//! limit function
float 	Limit(float pV, float pMin, float pMax)
{
	if (pV >= pMin && pV <= pMax)
	{
		return pV;
	}
	else if (pV < pMin)
	{
		return pMin;
	}
	else
	{
		return pMax;
	}	
}


float fixAngle_PI_PI(float pAngle)
{
	while (pAngle > Math.PI)
	{

		pAngle -=  Math.PI2;
	}

	while (pAngle < -Math.PI)
	{

		pAngle +=  Math.PI2;
	}

	return pAngle;
}

float fixAngle_180_180(float pAngle)
{
	while (pAngle > 180)
	{

		pAngle -=  360;
	}

	while (pAngle < -180)
	{

		pAngle +=  360;
	}

	return pAngle;
}


enum NVTypes
{
	NONE,
	NV_GOGGLES,
	NV_OPTICS_ON,
	NV_OPTICS_OFF
	MAX
}

class DayZPlayerCameraBase extends DayZPlayerCamera
{
	protected 	Weapon_Base		m_weaponUsed;
	protected 	ItemOptics 		m_opticsUsed;
	
	//! constructor must be same 
	void 	DayZPlayerCameraBase(DayZPlayer pPlayer, HumanInputController pInput)
	{
		m_fLRAngleVel[0] = 0;
		m_fUDAngleVel[0] = 0;
		m_fFovAbsVel[0] = 0;
		m_WeaponSwayModifier = 1;
		
		if (m_pPlayer.IsEyeZoom())
		{
			m_fFovAbsolute		= DZPLAYER_CAMERA_FOV_EYEZOOM;
		}
		else
		{
			m_fFovAbsolute		= g_Game.GetUserFOV();
		}
		
		//!
		/*
		{
			int perItemCamUD = pPlayer.GetCurrentPerItemCameraUD();
			string 		a	= "Per Item Camera User Data: " + perItemCamUD.ToString();
			Print(a);
		}
		*/
		m_CameraPPDelay = 0;

		m_CommandWeapons = pPlayer.GetCommandModifier_Weapons();
	};

	float UpdateUDAngle(out float pAngle, out float pAngleAdd, float pMin, float pMax, float pDt)
	{
		if (Math.AbsFloat(pAngleAdd) > 0.001)
		{
			float aimingUDAngle = m_CommandWeapons.GetBaseAimingAngleUD();

			//!	pAngle + pAngleAdd == aimingUDAngle + aimingUDAdd
			//! now we set pAngleAdd to be the differenc from aimingAngle and we change camera angle to be the aiming angle

			// override actual angle
			pAngleAdd 	= pAngle + pAngleAdd - aimingUDAngle;
			pAngle 		= aimingUDAngle;

			// Print("Angle: " + pAngle.ToString() + " Aim: " + actualUDAngle.ToString() );
		}

		//! lr angle
		if( m_pInput.CameraIsFreeLook() )	
		{
			pAngleAdd 	+= m_pInput.GetAimChange()[1] * Math.RAD2DEG;
			pAngleAdd	= Limit(pAngleAdd, pMin, pMax);

			m_fUDAngleVel[0]	= 0;
		}
		else
		{
			if( m_pInput.CameraIsTracking() )
			{
				pAngleAdd 	= m_pInput.GetTracking()[1] * Math.RAD2DEG;
				pAngleAdd	= Limit(pAngleAdd, pMin, pMax);

				m_fUDAngleVel[0]	= 0;
			}
			else
			{	
				//! update it in degrees
				pAngle 	+= m_pInput.GetAimChange()[1] * Math.RAD2DEG;
				pAngle 	= Limit(pAngle, pMin, pMax);

				pAngleAdd	= Math.SmoothCD(pAngleAdd, 0, m_fUDAngleVel, 0.14, 1000, pDt);
			}
		}
		
		/*{
			float change = m_pInput.GetAimChange()[1] * Math.RAD2DEG;

			Print ("Script: Camera ud angle: " +  pAngle.ToString() + " change: " + change.ToString() );
		}*/		

		return Limit(pAngle + pAngleAdd, pMin, pMax);
	}


	float UpdateLRAngle(float pAngle, float pMin, float pMax, float pDt)
	{
		//! lr angle
		if (m_pInput.CameraIsFreeLook() || m_bForceFreeLook)	
		{
			//!
			pAngle	+= m_pInput.GetAimChange()[0] * Math.RAD2DEG;
			pAngle	= Limit(pAngle, pMin, pMax);

			m_fLRAngleVel[0]	= 0;	// reset filter

		}
		else
		{
			if( m_pInput.CameraIsTracking() )
			{
				pAngle = m_pInput.GetTracking()[0] * Math.RAD2DEG;
				pAngle	= Limit(-pAngle, pMin, pMax);
				
				m_fLRAngleVel[0]	= 0;	// reset filter
			}
			else
			{	
				// smooth value back to 0 
				pAngle		= Math.SmoothCD(pAngle, 0, m_fLRAngleVel, 0.14, 1000, pDt);
				// m_fLeftRightAngle	= 0.9 * (1.0 - pDt);			
			}
		}

		return pAngle;
	}

	

	void 	StdFovUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		//! change abs FOV for naked eye zoom
		if (m_pPlayer.IsEyeZoom())
		{
			m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, DZPLAYER_CAMERA_FOV_EYEZOOM, m_fFovAbsVel, 0.1, 1000, pDt);
		}
		else
		{
			m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, g_Game.GetUserFOV(), m_fFovAbsVel, 0.1, 1000, pDt);
		}

		pOutResult.m_fFovAbsolute = m_fFovAbsolute;

		//! switch shooting from camera to weapon (firearms)
		if (!m_pPlayer.IsShootingFromCamera())
		{
			pOutResult.m_fShootFromCamera = 0.0;
		}
	}


	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		super.OnUpdate(pDt, pOutResult);

		StdFovUpdate(pDt, pOutResult);
		UpdateCameraNV(PlayerBase.Cast(m_pPlayer));
	}

	override void OnActivate(DayZPlayerCamera pPrevCamera, DayZPlayerCameraResult pPrevCameraResult)
	{
		//PrintString("OnActivate DayZPlayerCameraBase");
		PlayerBase player = PlayerBase.Cast(m_pPlayer);
		player.OnCameraChanged(this);
		SetCameraPPDelay(pPrevCamera);
		
		if (DayZPlayerCameraBase.Cast(pPrevCamera) && DayZPlayerCameraBase.Cast(pPrevCamera).IsCameraNV())
		{
			PPEffects.SetEVValuePP(0); //sets EV value immediately to avoid bright flashes at night
		}
		
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(SetCameraPP,m_CameraPPDelay*1000,false,true,this); // this takes care of weapon/optics postprocessing
		DayZPlayerCameraOptics optic_camera;
		if (DayZPlayerCamera.CastTo(optic_camera,pPrevCamera))
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(PlayerBase.Cast(m_pPlayer).HideClothing,null,false);
		}
	}
	
	float GetWeaponSwayModifier()
	{
		return m_WeaponSwayModifier;
	}
	
	override string GetCameraName()
	{
		return "DayZPlayerCameraBase";
	}
	
	void SetCameraPPDelay(DayZPlayerCamera pPrevCamera)
	{
	}
	
	void SetCameraNV(bool nightvision)
	{
		m_IsNightvision = nightvision;
	}
	
	bool IsCameraNV()
	{
		return m_IsNightvision;
	}
	
	void UpdateCameraNV(PlayerBase player)
	{
		if ( !player )
			return;
		
		if ( player.IsNVGWorking() != IsCameraNV() )
		{
			SetCameraNV(player.IsNVGWorking());
			SetCameraPP(true, this);
		}
	}
	
	//! by default sets camera PP to zero, regardless of parameter. Override if needed.
	void SetCameraPP(bool state, DayZPlayerCamera launchedFrom)
	{
		PPEffects.ResetPPMask();
		PPEffects.SetLensEffect(0, 0, 0, 0);
		PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
		PPEffects.SetBlurOptics(0);
		
		if (IsCameraNV())
		{
			SetNVPostprocess(NVTypes.NV_GOGGLES);
		}
		else
		{
			SetNVPostprocess(NVTypes.NONE);
		}
		
		m_weaponUsed = Weapon_Base.Cast(m_pPlayer.GetHumanInventory().GetEntityInHands());
		if (m_weaponUsed)
		{
			m_weaponUsed.HideWeaponBarrel(false);
		}
	}
	
	override float GetCurrentPitch()
	{
		return m_CurrentCameraPitch;
	}
	
	void ForceFreelook(bool state)
	{
		m_bForceFreeLook = state;
	}
	
	void SetNVPostprocess(int NVtype)
	{
		switch (NVtype)
		{
			case NVTypes.NONE:
				PPEffects.SetEVValuePP(0);
				PPEffects.SetColorizationNV(0.0, 0.0, 0.0);
				PPEffects.SetNVParams(1, 0, 2.35, 2.75); //default values
			break;
			
			case NVTypes.NV_OPTICS_ON:
				PPEffects.SetEVValuePP(7);
				PPEffects.SetColorizationNV(0.0, 1.0, 0.0);
				PPEffects.SetNVParams(3, 2, 9, 1);
			break;
			
			case NVTypes.NV_OPTICS_OFF:
				PPEffects.SetEVValuePP(-7);
				PPEffects.SetColorizationNV(0.0, 0.0, 0.0);
				PPEffects.SetNVParams(1, 0, 2.35, 2.75); //default values
			break;
			
			case NVTypes.NV_GOGGLES:
				PPEffects.SetEVValuePP(7);
				PPEffects.SetColorizationNV(0.0, 1.0, 0.0);
				PPEffects.SetNVParams(2, 1, 10, 1);
			break;
		}
	}
	
	protected float 				m_fLRAngleVel[1];
	protected float 				m_fUDAngleVel[1];
	protected float					m_fFovAbsVel[1];
	protected float					m_fFovAbsolute;
	protected bool					m_bForceFreeLook;
	protected float					m_WeaponSwayModifier;
	protected float 				m_CameraPPDelay;
	protected float 				m_CurrentCameraPitch;
	protected HumanCommandWeapons	m_CommandWeapons;
	protected bool 					m_IsNightvision;
}
