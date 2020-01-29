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

	override string GetText()
	{
		return "#drink";
	}
	
	override bool IsDrink()
	{
		return true;
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTSurface(1.5);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		vector pos_cursor = target.GetCursorHitPos();
		string surfType;
		int liquidType;

		g_Game.SurfaceUnderObject(player, surfType, liquidType);

		if ( g_Game.SurfaceIsPond(pos_cursor[0],pos_cursor[2]) || liquidType == LIQUID_WATER )
		{
			/*pos_cursor[1] = g_Game.SurfaceY(pos_cursor[0],pos_cursor[2]);
			if ( vector.Distance(player.GetPosition(), pos_cursor) < UAMaxDistances.DEFAULT )
			{*/
				return true;
			//}
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
	
	override void OnEndServer(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(false);
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		//Print("OnFinishProgressServer");
		Param1<float> nacdata = Param1<float>.Cast( action_data.m_ActionComponent.GetACData() );
		float amount = UAQuantityConsumed.DRINK;
		action_data.m_Player.Consume(NULL,amount, EConsumeType.ENVIRO_POND);
	}

	override void OnEndAnimationLoopServer( ActionData action_data )
	{
		//Print("OnEndAnimationLoopServer");
		if(action_data.m_Player.HasBloodyHands())
		{
			action_data.m_Player.InsertAgent(eAgents.CHOLERA, 1);
		}
	}
	
	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		
		if( HasTarget() )
		{
			ctx.Write(action_data.m_Target.GetCursorHitPos());
		}
	}
	
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{		
		super.ReadFromContext(ctx, action_recive_data);
		
		if( HasTarget() )
		{
			vector cursor_position;
			if ( !ctx.Read(cursor_position) )
				return false;
			action_recive_data.m_Target.SetCursorHitPos(cursor_position);
		}
		return true;
	}
};