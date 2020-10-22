class ActionForceConsumeCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityEdible(UAQuantityConsumed.DEFAULT,UATimeSpent.DEFAULT);
	}
};

class ActionForceConsume: ActionContinuousBase
{
	void ActionForceConsume()
	{
		m_CallbackClass = ActionForceConsumeCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_FORCEFEED;
		m_StanceMask = DayZPlayerConstants.STANCEIDX_ERECT | DayZPlayerConstants.STANCEIDX_CROUCH;
		m_FullBody = true;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}

	override string GetText()
	{
		return "#feed";
	}
	
	override void OnEndServer( ActionData action_data )
	{	
		if ( action_data.m_MainItem && ( action_data.m_MainItem.GetQuantity() <= 0.01 ) )
		{
			action_data.m_MainItem.SetQuantity( 0 );
		}
		
		if ( action_data.m_Player.HasBloodyHands() && !action_data.m_Player.GetInventory().FindAttachment( InventorySlots.GLOVES ) )
		{
			Object targetPlayer = action_data.m_Target.GetObject();
			PlayerBase target = PlayerBase.Cast( targetPlayer );
			if ( target )
			{
				target.SetBloodyHandsPenalty();
			}
		}
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		if( item.GetQuantity() > item.GetQuantityMin() )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};