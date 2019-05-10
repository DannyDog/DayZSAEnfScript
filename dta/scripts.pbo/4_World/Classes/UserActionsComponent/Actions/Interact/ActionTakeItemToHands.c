class ActionTakeItemToHands: ActionInteractBase
{
	void ActionTakeItemToHands()
	{
		m_MessageSuccess    = "";
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_CommandUIDProne	= DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HANDS;
		m_HUDCursorIcon     = CursorIcons.LootCorpse;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}	
	
	override bool HasProneException()
	{
		return true;
	}
	
#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
#endif
	
	override bool HasProgress()
	{
		return false;
	}
	
	override int GetType()
	{
		return AT_TAKE_ITEM_TO_HANDS;
	}

	override string GetText()
	{
		return "#take_to_hands";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemBase tgt_item = ItemBase.Cast( target.GetObject() );
		if ( !tgt_item || !tgt_item.IsTakeable() ) return false;
		if ( tgt_item.IsBeingPlaced() ) return false;
		if ( target.GetParent() ) return false;
		
#ifdef OLD_ACTIONS
		if ( !player.GetInventory().CanAddEntityIntoInventory(tgt_item) && player.GetInventory().CanAddEntityIntoHands(tgt_item) )
		{
			return true;
		}
#else
		if ( player.GetInventory().CanAddEntityIntoHands(tgt_item) )
		{
			return true;
		}
#endif
		return false;
	}
	
	override bool CanContinue( ActionData action_data )
	{
		return true;
	}
	
	override void OnStartServer( ActionData action_data )
	{
		//NOTE: removed until better solution is found
		/*vector rotation = vector.Zero;
		vector target_dir = action_data.m_Target.GetObject().GetPosition() - action_data.m_Player.GetPosition();
		
		rotation[0] = Math.Atan2(target_dir[0], target_dir[2]) * Math.RAD2DEG;
		action_data.m_Player.SetOrientation(rotation);*/
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		EntityAI ntarget = EntityAI.Cast(action_data.m_Target.GetObject());
		action_data.m_Player.PredictiveTakeEntityToHands(ntarget);
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		EntityAI ntarget = EntityAI.Cast(action_data.m_Target.GetObject());
		action_data.m_Player.PredictiveTakeEntityToHands(ntarget);
	}
	
	override void CreateAndSetupActionCallback( ActionData action_data )
	{
		EntityAI target = EntityAI.Cast(action_data.m_Target.GetObject());
		ActionBaseCB callback;
		if (!target)
			return;
		
		if (target.IsHeavyBehaviour())
		{
			Class.CastTo(callback, action_data.m_Player.StartCommand_Action(DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HEAVY,GetCallbackClassTypename(),DayZPlayerConstants.STANCEMASK_ERECT));
		}
		else
		{
			if( action_data.m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT) )
			{
				Class.CastTo(callback, action_data.m_Player.AddCommandModifier_Action(DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS,GetCallbackClassTypename()));
			}
			else
			{
				Class.CastTo(callback, action_data.m_Player.StartCommand_Action(DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HANDS,GetCallbackClassTypename(),DayZPlayerConstants.STANCEMASK_PRONE));
			}
		}
		callback.SetActionData(action_data); 
		callback.InitActionComponent();
		action_data.m_Callback = callback;
	}
};