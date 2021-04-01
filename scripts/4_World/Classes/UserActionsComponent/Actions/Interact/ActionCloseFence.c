class ActionCloseFence: ActionInteractBase
{
	ref NoiseParams m_NoisePar;
	
	void ActionCloseFence()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.CloseDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText()
	{
		return "#close";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			Fence fence = Fence.Cast( targetObject );
			
			if ( fence && fence.CanCloseFence() )
			{
				return true;
			}
		}
		
		return false;
	}

	override void OnStartServer( ActionData action_data )
	{
		Fence fence = Fence.Cast( action_data.m_Target.GetObject() );
		fence.CloseFence();
	}
	
	override void OnEndServer( ActionData action_data )
	{
		m_NoisePar = new NoiseParams();
		m_NoisePar.LoadFromPath("CfgVehicles SurvivorBase NoiseActionDefault");
		NoiseSystem noise = GetGame().GetNoiseSystem();
		if ( noise )
		{
			if ( action_data.m_Player )
				noise.AddNoisePos(action_data.m_Player, action_data.m_Target.GetObject().GetPosition(), m_NoisePar);
		}
	}
}