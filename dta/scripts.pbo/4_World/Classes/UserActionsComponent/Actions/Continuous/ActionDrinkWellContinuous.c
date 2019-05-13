class ActionDrinkWellContinuousCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(UATimeSpent.DRINK_WELL);
	}
};

class ActionDrinkWellContinuous: ActionContinuousBase
{	
	void ActionDrinkWellContinuous()
	{
		m_CallbackClass = ActionDrinkWellContinuousCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DRINKWELL;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override int GetType()
	{
		return AT_DRINK_WELL;
	}

	override string GetText()
	{
		return "#drink";
	}

#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
#endif
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		if( target.GetObject() && target.GetObject().IsWell() )
		{
			return true;
		}	
			
		return false;
	}

	override void OnStartClient(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(true);
	}
	
	override void OnStartServer(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(true);
	}

	override void OnEndClient(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(false);
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Param1<float> nacdata = Param1<float>.Cast( action_data.m_ActionComponent.GetACData() );
		float amount = nacdata.param1 * UAQuantityConsumed.DRINK;
		action_data.m_Player.Consume(NULL,amount, EConsumeType.ENVIRO_WELL);
		action_data.m_Player.GetItemAccessor().HideItemInHands(false);
	}

	override void OnEndAnimationLoopServer( ActionData action_data )
	{
		if(action_data.m_Player.HasBloodyHands())
		{
			action_data.m_Player.InsertAgent(eAgents.CHOLERA, 1);
		}
	}

	override void OnEndServer( ActionData action_data )
	{
		OnFinishProgressServer(action_data);
		action_data.m_Player.GetItemAccessor().HideItemInHands(false);
	}
};