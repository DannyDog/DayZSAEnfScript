class ActionSidePlateInteract: ActionAnimateCarSelection
{
	void ActionSidePlateInteract()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		//m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseDoors;
	}
	
	override void OnStartClient( ActionData action_data )
	{
		super.OnStartClient( action_data );
		//Make work in SP  + try after packing sounds
		ref EffectSound m_InteractSound;
		string openSidePlateSound = "Truck_01_Gear_Open_Side_Plate_SoundSet";
		string closeSidePlateSound = "Truck_01_Gear_Close_Side_Plate_SoundSet";
		
		Entity targetEnt;
		if ( Class.CastTo(targetEnt, action_data.m_Target.GetObject()) )
		{
			if ( targetEnt.GetAnimationPhase(m_AnimSource) > 0.5 )
			{
				SEffectManager.PlaySound(closeSidePlateSound, targetEnt.GetPosition(), 0.1, 0.1);
			}
			if ( targetEnt.GetAnimationPhase(m_AnimSource) <= 0.5 )
			{
				SEffectManager.PlaySound(openSidePlateSound, targetEnt.GetPosition(), 0.1, 0.1);
			}
		}
	}
};