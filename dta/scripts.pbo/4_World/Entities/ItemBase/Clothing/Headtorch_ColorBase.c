class Headtorch_ColorBase extends Clothing
{
	HeadtorchLight m_Light;
	
	static int		REFLECTOR_ID = 4;
	static int		GLASS_ID = 5;
	
	static string 	LIGHT_OFF_GLASS 		= "dz\\characters\\headgear\\data\\HeadTorchGlass.rvmat";
	static string 	LIGHT_OFF_REFLECTOR 	= "dz\\characters\\headgear\\data\\HeadTorch.rvmat";
	static string 	LIGHT_ON_GLASS 			= "dz\\characters\\headgear\\data\\HeadTorchGlass_on.rvmat";
	static string 	LIGHT_ON_GLASS_RED		= "dz\\characters\\headgear\\data\\HeadTorchGlass_on_red.rvmat";
	static string 	LIGHT_ON_REFLECTOR 		= "dz\\characters\\headgear\\data\\HeadTorch_ON.rvmat";
	static string 	LIGHT_ON_REFLECTOR_RED	= "dz\\characters\\headgear\\data\\HeadTorch_ON_red.rvmat";
	
	static vector m_OnHeadLocalPos = Vector(0.12,0.15,0);
	static vector m_OnHeadLocalOri = Vector(0,90,0);
	static string m_OffHeadLightPoint = "beamStart";
	static string m_OffHeadLightTarget = "beamEnd";
	
	override void OnWorkStart()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			CreateHeadtorchLight();
		}
		
		if ( IsInherited( Headtorch_Black ) )
		{
			SetObjectMaterial(GLASS_ID, LIGHT_ON_GLASS_RED);
			SetObjectMaterial(REFLECTOR_ID, LIGHT_ON_REFLECTOR_RED);
		}
		else
		{
			SetObjectMaterial(GLASS_ID, LIGHT_ON_GLASS);
			SetObjectMaterial(REFLECTOR_ID, LIGHT_ON_REFLECTOR);
		}
	}

	override void OnWork( float consumed_energy )
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			Battery9V battery = Battery9V.Cast( GetCompEM().GetEnergySource() );
			
			if (battery  &&  m_Light)
			{
				float efficiency = battery.GetEfficiency0To1();
				
				if ( efficiency < 1 )
				{
					m_Light.SetIntensity( efficiency, GetCompEM().GetUpdateInterval() );
				}
				else
				{
					m_Light.SetIntensity( 1, 0 );
				}
			}
		}
	}
	
	void OnLightCreated()
	{
		m_Light.SetColorToWhite();
	}
	
	void CreateHeadtorchLight()
	{
		if (!m_Light)
			m_Light = HeadtorchLight.Cast(  ScriptedLightBase.CreateLight( HeadtorchLight, "0 0 0")  );
		
		OnLightCreated();
		
		bool is_on_head = false;
		PlayerBase player = PlayerBase.Cast( GetHierarchyParent() );
		
		if (player)
		{
			ItemBase att_item = player.GetItemOnHead();
			
			if (att_item == this)
			{
				is_on_head = true;
			}
		}
		
		
		if (is_on_head)
		{
			AttachLightOnHead(player);
		}
		else
		{
			m_Light.AttachOnMemoryPoint(this, m_OffHeadLightPoint, m_OffHeadLightTarget);
		}
	}
	
	void AttachLightOnHead(PlayerBase player)
	{
		int boneIdx = player.GetBoneIndexByName("Head");
		
		if( boneIdx != -1 )
		{
			if ( m_Light.GetParent() )
				m_Light.DetachFromParent();
			
			m_Light.SetPosition( m_OnHeadLocalPos );
			m_Light.SetOrientation( m_OnHeadLocalOri );
			
			player.AddChild(m_Light, boneIdx);
		}
	}
	
	override void OnWasAttached( EntityAI parent, int slot_id )
	{
		PlayerBase player = PlayerBase.Cast(parent);

		if ( player )
		{
			if ( m_Light )
			{
				AttachLightOnHead( player );
			}
			//player.m_PlayerLightManager.AddLightSource(this);
		}
	}
	
	override void OnWasDetached( EntityAI parent, int slot_id )
	{
		PlayerBase player = PlayerBase.Cast(parent);
		if ( player )
		{
			if ( m_Light )
			{
				m_Light.DetachFromParent();
				m_Light.AttachOnMemoryPoint(this, m_OffHeadLightPoint, m_OffHeadLightTarget);
			}
			//player.m_PlayerLightManager.RemoveLightSource(this);
		}
	}
	
	override void OnWorkStop()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			if (m_Light)
				m_Light.FadeOut();
			
			m_Light = NULL;
		}
		
		SetObjectMaterial(GLASS_ID, LIGHT_OFF_GLASS);
		SetObjectMaterial(REFLECTOR_ID, LIGHT_OFF_REFLECTOR);
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
		AddAction(ActionTurnOnHeadtorch);
		AddAction(ActionTurnOffHeadtorch);
	}
};