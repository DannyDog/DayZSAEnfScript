class ActionDrinkPondContinuousCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(UATimeSpent.DRINK_POND);
	}
};

class ActionDrinkPondContinuous: ActionContinuousBase
{
	private const float WATER_DRANK_PER_SEC = 35;
	
	void ActionDrinkPondContinuous()
	{
		m_CallbackClass = ActionDrinkPondContinuousCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DRINKPOND;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override int GetType()
	{
		return AT_DRINK_POND;
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
		m_ConditionTarget = new CCTNone;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
			return true;
		
		vector pos_cursor = target.GetCursorHitPos();
		string surfType;
		int liquidType;

		g_Game.SurfaceUnderObject(player, surfType, liquidType);

		if ( liquidType == LIQUID_WATER )
		{
			pos_cursor[1] = g_Game.SurfaceY(pos_cursor[0],pos_cursor[2]);
			// TODO: use some automatic way for setting of surface description (when it's possible)
			//GetGame().SurfaceGetType(pos_cursor[0], pos_cursor[2], m_TargetDescription);
			if ( vector.Distance(player.GetPosition(), pos_cursor) < UAMaxDistances.DEFAULT )
			{
				return true;
			}
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
		action_data.m_Player.Consume(NULL,amount, EConsumeType.ENVIRO_POND);
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