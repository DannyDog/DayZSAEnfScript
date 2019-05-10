class RecoilBase
{
	bool m_DebugMode;
	
	Weapon_Base m_Weapon;
	PlayerBase m_Player;
	protected bool m_DeleteRequested;
	protected float m_Time;//how much time has elapsed since first update
	protected float m_ReloadTime;//reload time config parameter of the weapon
	protected vector m_RecoilModifier;
	protected bool m_IsClient;
	// for mouse offset
	float m_MouseOffsetRangeMin;//in degrees min
	float m_MouseOffsetRangeMax;//in degrees max
	float m_MouseOffsetRelativeTime = 1;//[0..1] a time it takes to move the mouse the required distance relative to the reload time of the weapon(firing mode)
	float m_HandsOffsetRelativeTime = 1;//[0..1] a time it takes to move the hands the required distance given by the curve relative to the reload time of the weapon(firing mode)
	float m_CamOffsetRelativeTime = 1;//[0..1] a time it takes to move the camera the required distance relative to the reload time of the weapon(firing mode)
	float m_CamOffsetDistance = 0.05;//how far the camera will travel along the z-axis in cm
	float m_MouseOffsetDistance;//how far should the mouse travel
	float m_TimeNormalized;
	//protected float m_MouseOffsetResult;//in degrees max
	protected vector m_MouseOffsetTarget;//move the mouse towards this point
	protected vector m_MouseOffsetTargetAccum;//the overall mouse offset so far(all deltas accumulated)
	protected float m_Angle;//result between the min and max
	// mouse end
	
	//hands
	vector m_LastPosOnCurve;
	//ends end
	
	
	protected ref array<vector> m_HandsCurvePoints;
	
	void RecoilBase(Weapon_Base weapon)
	{
		m_Weapon = weapon;
		m_DebugMode = false;
		m_Player = PlayerBase.Cast(weapon.GetHierarchyRootPlayer());
		m_HandsCurvePoints = new array<vector>;
		Init();
		PostInit(weapon);
	}
	
	void Init()
	{
	
	}
	
	Weapon_Base GetWeapon()
	{
		return m_Weapon;
	}
	
	void PostInit(Weapon_Base weapon)
	{
		int muzzleIndex = weapon.GetCurrentMuzzle();
		Magazine magazine = weapon.GetMagazine(muzzleIndex);

		m_Angle = m_Player.GetRandomGeneratorSyncManager().GetRandomInRange(RandomGeneratorSyncUsage.RGSRecoil, m_MouseOffsetRangeMin, m_MouseOffsetRangeMax);
		m_RecoilModifier = GetRecoilModifier( GetWeapon() );
		if(m_DebugMode) Print(m_Angle);
		
		m_ReloadTime = weapon.GetReloadTime(muzzleIndex);
		m_MouseOffsetTarget = vector.YawToVector(m_Angle);
		m_MouseOffsetTarget = m_MouseOffsetTarget * m_MouseOffsetDistance;
		m_IsClient = GetGame().IsClient() || !GetGame().IsMultiplayer();
		m_CamOffsetDistance *= m_RecoilModifier[2];
	}
	
	//! Destroys this object next update tick
	void Destroy()
	{
		m_DeleteRequested = true;
	}
	
	// called externally per update, not to be overriden in children
	void Update( SDayZPlayerAimingModel pModel, out float axis_mouse_x, out float axis_mouse_y, out float axis_hands_x, out float axis_hands_y, float pDt )
	{
		if( m_DeleteRequested )
		{
			delete this;
		}
		
		m_TimeNormalized = Math.InverseLerp(0, m_ReloadTime, m_Time);
		m_TimeNormalized = Math.Clamp(m_TimeNormalized, 0,0.99);
		
		ApplyMouseOffset(pDt, axis_mouse_x, axis_mouse_y);
		ApplyHandsOffset(pDt, axis_hands_x, axis_hands_y);
		if(m_IsClient)
			ApplyCamOffset(pModel);
		
		axis_mouse_x = axis_mouse_x * m_RecoilModifier[0];
		axis_mouse_y = axis_mouse_y * m_RecoilModifier[1];
		
		axis_hands_x = axis_hands_x * m_RecoilModifier[0];
		axis_hands_y = axis_hands_y * m_RecoilModifier[1];
	
		
		if( m_Time >= m_ReloadTime )
		{
			Destroy();
		}
		
		m_Time += pDt;
		
		
	}
	
	void ApplyCamOffset(SDayZPlayerAimingModel pModel)
    {
        float time_rel = Math.Clamp(Math.InverseLerp(0, m_CamOffsetRelativeTime, m_TimeNormalized), 0, 1);
        float offset = 0;
        float time = Easing.EaseOutBack(time_rel);
        if(time == 1)
        {
            offset = 0;
        }
        else
        {
            offset = Math.Lerp(0,m_CamOffsetDistance,time);
        }
        
        pModel.m_fCamPosOffsetZ = offset;
    }
	
	void ApplyHandsOffset(float pDt, out float pRecResultX, out float pRecResultY)
	{
		float relative_time = m_TimeNormalized / Math.Clamp(m_HandsOffsetRelativeTime, 0.001,1);
		vector pos_on_curve = GetPositionOnCurve(m_HandsCurvePoints, relative_time);
		/*
		float offset_x = pos_on_curve[0] - m_LastPosOnCurve[0];
		float offset_y = pos_on_curve[1] - m_LastPosOnCurve[1];
		
		m_LastPosOnCurve = pos_on_curve;
		*/
		if(m_DebugMode)
		{
			PrintString("normalized time: " + m_TimeNormalized.ToString());
			PrintString("elapsed time: " + m_Time.ToString());
			PrintString("curve pos x: " + pos_on_curve[0].ToString());
			PrintString("curve pos y: " + pos_on_curve[1].ToString());
			PrintString("relative_time: " + relative_time.ToString());
			
			//PrintString("hands offset_x: " + offset_x.ToString());
			//PrintString("hands offset_y: " + offset_y.ToString());
		}
		
		pRecResultX = pos_on_curve[0];
		pRecResultY = pos_on_curve[1];
	}
	
	void ApplyMouseOffset(float pDt, out float pRecResultX, out float pRecResultY)
	{
		
		if( m_MouseOffsetTargetAccum[1] < m_MouseOffsetTarget[1] )
		{
			float relative_delta = pDt / m_ReloadTime / Math.Clamp(m_MouseOffsetRelativeTime, 0.001,1);
			
			float delta_mouse_offset_x = m_MouseOffsetTarget[0] * relative_delta;
			float delta_mouse_offset_y = m_MouseOffsetTarget[1] * relative_delta;
			
			if( ( m_MouseOffsetTargetAccum[1] + delta_mouse_offset_y) > m_MouseOffsetTarget[1] )
			{
				delta_mouse_offset_x = m_MouseOffsetTarget[0] - m_MouseOffsetTargetAccum[0];
				delta_mouse_offset_y = m_MouseOffsetTarget[1] - m_MouseOffsetTargetAccum[1];
			}
			
			m_MouseOffsetTargetAccum[0] = m_MouseOffsetTargetAccum[0] + delta_mouse_offset_x;
			m_MouseOffsetTargetAccum[1] = m_MouseOffsetTargetAccum[1] + delta_mouse_offset_y;
			
			pRecResultX = delta_mouse_offset_x;
			pRecResultY = delta_mouse_offset_y;
			
			if(m_DebugMode)
			{
				PrintString( "delta x: "+ delta_mouse_offset_x );
				PrintString( "delta y: "+ delta_mouse_offset_y );
				PrintString( "target x: "+ m_MouseOffsetTarget[0] );
				PrintString( "target y: "+ m_MouseOffsetTarget[1] );
				PrintString( "accum x: "+ m_MouseOffsetTargetAccum[0] );
				PrintString( "accum y: "+ m_MouseOffsetTargetAccum[1] );
			}
		}
	
	}
	
	vector GetRecoilModifier(Weapon_Base weapon)
	{
		vector recoil_modifier;
		if( weapon && weapon.GetPropertyModifierObject() )
		{
			recoil_modifier = weapon.GetPropertyModifierObject().m_RecoilModifiers;
		}
		return recoil_modifier;
	}
	
	vector GetPositionOnCurve(array<vector> points, float time)
	{
		return Math3D.Curve(ECurveType.CatmullRom, time, points);
	}
}