class ActionClapBearTrapWithThisItem: ActionSingleUseBase
{
	void ActionClapBearTrapWithThisItem()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_POKE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText()
	{
		return "#trigger_bear_trap";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target ) return false;
		if ( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;

		TrapBase target_TB;

		if ( Class.CastTo(target_TB,  target.GetObject() ) &&  item )
		{		
			if (target_TB.IsActive())
			{
				return true;
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		TrapBase target_TB;
		Class.CastTo(target_TB,  action_data.m_Target.GetObject() );
		
		target_TB.SnapOnObject(action_data.m_MainItem);
	}
};