class ActionDropItemCB : ActionSingleUseBaseCB
{
	override void EndActionComponent()
	{
		SetCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
		m_ActionData.m_State = UA_FINISHED;
	}
	
	override void OnAnimationEvent(int pEventID)
	{
		switch (pEventID)
		{
			case UA_ANIM_EVENT: 
				if (( ( !GetGame().IsServer() && GetGame().IsMultiplayer() ) || (!GetGame().IsMultiplayer()) ) && m_ActionData && m_ActionData.m_Player)
				{
					m_ActionData.m_Player.PredictiveDropEntity(m_ActionData.m_Player.GetItemInHands());
				
					if ( m_ActionData.m_Player.IsPlacingLocal() )
					{
						m_ActionData.m_Player.TogglePlacingLocal();
					}
				}
			break;
		}
	}
};

class ActionDropItem: ActionSingleUseBase
{
	string m_ItemName = "";

	void ActionDropItem()
	{
		m_MessageSuccess    = "";
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_DROPITEM_HANDS;
		m_CommandUIDProne	= DayZPlayerConstants.CMD_ACTIONFB_DROPITEM_HANDS;
		m_CallbackClass 	= ActionDropItemCB;
		//m_HUDCursorIcon     = CursorIcons.LootCorpse;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}	
	
	override int GetType()
	{
		return AT_DROP_ITEM;
	}

	override string GetText()
	{
		return "#drop_item";
	}
	
#ifndef OLD_ACTIONS
	override typename GetInputType()
	{
		return DropActionInput;
	}
#endif
	
	override bool HasProneException()
	{
		return true;
	}
	
	override bool HasTarget()
	{
		return false;
	}

	override bool ActionConditionContinue( ActionData action_data )
	{
		return true;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( player.GetCommand_Vehicle() )
			return false;
		
		if ( player && item )
		{
			return true;
		}
		return false;
	}
	
	/*override void OnExecuteServer( ActionData action_data )
	{
	}*/
	
	//would not work? Action probably already gone by then
	override void OnExecuteClient( ActionData action_data )
	{
		//action_data.m_Player.PredictiveDropEntity(action_data.m_Player.GetItemInHands());
	}
};