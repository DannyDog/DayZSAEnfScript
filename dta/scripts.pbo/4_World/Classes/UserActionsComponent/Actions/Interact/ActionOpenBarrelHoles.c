class ActionOpenBarrelHoles: ActionInteractBase
{
	void ActionOpenBarrelHoles()
	{
		m_MessageSuccess = "I have opened it.";
		//m_Animation = "open";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.OpenHood;
	}

	override int GetType()
	{
		return AT_OPEN_BARREL_HOLES;
	}

	override string GetText()
	{
		return "#open";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			BarrelHoles_ColorBase ntarget = BarrelHoles_ColorBase.Cast( target_object );
			if( ntarget )
			{
				if ( !ntarget.IsOpen() && !ntarget.IsItemTypeAttached( ntarget.ATTACHMENT_COOKING_POT ) )
				{
					return true;
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		BarrelHoles_ColorBase ntarget = BarrelHoles_ColorBase.Cast( target_object );
		if( ntarget )
		{
			ntarget.Open();
		}
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		BarrelHoles_ColorBase ntarget = BarrelHoles_ColorBase.Cast( target_object );
		if( ntarget )
		{
			ntarget.SoundSynchRemoteReset();
		}
	}
}