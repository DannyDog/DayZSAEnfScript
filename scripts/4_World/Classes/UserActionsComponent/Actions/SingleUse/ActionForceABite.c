class ActionForceABiteCB : ActionSingleUseBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CASingleUseQuantityEdible(UAQuantityConsumed.EAT_NORMAL);
	}
};

class ActionForceABite: ActionForceConsumeSingle
{
	void ActionForceABite()
	{		
		m_CallbackClass = ActionForceABiteCB;
	}
	
	override void CreateConditionComponents()  
	{		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}

	override string GetText()
	{
		return "#feed_a_bite";
	}
	
	override void OnEndServer( ActionData action_data )
	{	
		if ( action_data.m_MainItem.GetQuantity() <= 0 )
		{
			action_data.m_MainItem.SetQuantity(0);
		}
	}
};