class UniversalLight extends Switchable_Base
{
	UniversallightLight 	m_Light;
	
	static int			REFLECTOR_ID = 1;
	static int			GLASS_ID = 2;
	
	static string 		LIGHT_OFF_GLASS 	= "dz\\gear\\tools\\data\\flashlight_glass.rvmat";
	static string 		LIGHT_OFF_REFLECTOR = "dz\\weapons\\attachments\\data\\m4_flashlight.rvmat";
	static string 		LIGHT_ON_GLASS 		= "dz\\gear\\tools\\data\\flashlight_glass_on.rvmat";
	static string 		LIGHT_ON_REFLECTOR 	= "dz\\weapons\\attachments\\data\\m4_flashlight_on.rvmat";
	
	
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}
		bool m4_rishndgrd   = false;
		bool ak_railhndgrd  = false;
		bool mp5_railhndgrd = false;

		if ( parent.FindAttachmentBySlotName("weaponHandguardM4") != NULL )
		{
			m4_rishndgrd = parent.FindAttachmentBySlotName("weaponHandguardM4").IsKindOf("M4_RISHndgrd");
		}
		
		if ( parent.FindAttachmentBySlotName("weaponHandguardAK") != NULL )
		{
			ak_railhndgrd = parent.FindAttachmentBySlotName("weaponHandguardAK").IsKindOf("AK_RailHndgrd");
		}

		if ( parent.FindAttachmentBySlotName("weaponHandguardMP5") != NULL )
		{
			mp5_railhndgrd = parent.FindAttachmentBySlotName("weaponHandguardMP5").IsKindOf("MP5_RailHndgrd");
		}

		if ( Mich2001Helmet.Cast(parent) ) //attachment on helmet
			return true;
		
		if ( m4_rishndgrd || ak_railhndgrd || mp5_railhndgrd || parent.IsKindOf("UMP45_Base") )
		{
			return true;
		}
		
		return false;
	}
	
	override void OnWorkStart()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			m_Light = UniversallightLight.Cast(  ScriptedLightBase.CreateLight(UniversallightLight, "0 0 0", 0.08)  ); // Position is zero because light is attached on parent immediately.
			m_Light.AttachOnMemoryPoint(this, "beamStart", "beamEnd");
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
	
	override void OnWorkStop()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // Client side
		{
			if (m_Light)
				m_Light.FadeOut();
			
			m_Light = NULL;
			
			SetObjectMaterial(GLASS_ID, LIGHT_OFF_GLASS);
			SetObjectMaterial(REFLECTOR_ID, LIGHT_OFF_REFLECTOR);
		}
	}
	
	// Inventory manipulation
	override void OnInventoryExit(Man player)
	{
		super.OnInventoryExit(player);
		
		if ( GetGame().IsServer()  &&  GetCompEM().IsWorking() )
		{
			if (player)
			{
				vector ori_rotate = player.GetOrientation();
				ori_rotate = ori_rotate + Vector(270,0,0);
				SetOrientation(ori_rotate);
			}
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}
}