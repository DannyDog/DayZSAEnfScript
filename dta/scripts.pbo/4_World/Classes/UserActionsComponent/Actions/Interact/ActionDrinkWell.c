class ActionDrinkWell extends ActionInteractBase
{
	void ActionDrinkWell()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DRINKSIP;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override int GetType()
	{
		return AT_DRINK_WELL_ONE;
	}

	override bool IsDrink()
	{
		return true;
	}
	
	override string GetText()
	{
		return "#drink";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
			return true;
		
		vector pos_cursor = target.GetCursorHitPos();
		if ( target.GetObject() && target.GetObject().IsWell() )
		{
			if ( vector.Distance(player.GetPosition(), pos_cursor) < UAMaxDistances.DEFAULT )
			{
				return true;
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		action_data.m_Player.Consume(NULL, UAQuantityConsumed.DRINK, EConsumeType.ENVIRO_WELL);
		if(action_data.m_Player.HasBloodyHands())
		{
			action_data.m_Player.InsertAgent(eAgents.CHOLERA, 1);
		}
	}
}