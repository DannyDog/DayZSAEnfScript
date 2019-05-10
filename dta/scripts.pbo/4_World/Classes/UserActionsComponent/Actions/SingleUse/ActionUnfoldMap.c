class ActionUnfoldMapCB : HumanCommandActionCallback //ActionSingleUseBaseCB
{
	protected ref ActionData			m_ActionData; //needs to be reffed for the destructor use
	bool 								m_MapFolding;
	bool 								m_HasReceivedEvent;
	
	void ActionUnfoldMapCB()
	{
		RegisterAnimationEvent("ActionExec", UA_ANIM_EVENT);
		EnableStateChangeCallback();
	}
	
	void ~ActionUnfoldMapCB()
	{
		if (GetGame().IsClient() && !GetGame().GetUIManager().GetMenu())
		{
			GetGame().GetMission().PlayerControlEnable();
		}
		
		if (!m_ActionData || !m_ActionData.m_Player )
			return;
		
		ItemMap chernomap = ItemMap.Cast(m_ActionData.m_Player.GetItemInHands());
		if (/*m_ActionData.m_Player.IsAlive() && */chernomap && m_ActionData.m_Player.IsMapOpen())
		{
			chernomap.SetMapStateOpen(false, m_ActionData.m_Player);
		}
	}
	
	void SetActionData(ActionData action_data )
	{
		m_ActionData = action_data;
	}
	
	override void OnStateChange(int pOldState, int pCurrentState)
	{
		if (!m_ActionData || !m_ActionData.m_Player)
			return;
		
		if ( m_HasReceivedEvent )
			return;
		
		if ( pCurrentState == STATE_NONE ) //callback ended
		{
			m_ActionData.m_Player.CloseMap();
		}
		if ( pOldState == STATE_LOOP_IN && pCurrentState == STATE_LOOP_LOOP )
		{
			PerformMapChange();
		}
	}
	
	override void OnAnimationEvent(int pEventID)
	{
		if (!m_ActionData || !m_ActionData.m_Player)
			return;
		
		switch (pEventID)
		{
			case UA_ANIM_EVENT: 
				m_HasReceivedEvent = true;
				PerformMapChange();
			break;
		}
	}
	
	override void OnFinish(bool pCanceled)	
	{
		if ( m_ActionData && m_ActionData.m_Player )
		{
			//if ( pCanceled ) 
			//{
				if ( m_ActionData && m_ActionData.m_ActionComponent )
					m_ActionData.m_State = m_ActionData.m_ActionComponent.Interrupt(m_ActionData);
				if ( (!GetGame().IsMultiplayer() || GetGame().IsClient()) && GetGame().GetUIManager() && GetGame().GetUIManager().IsMenuOpen(MENU_MAP) )
				{
					GetGame().GetUIManager().FindMenu(MENU_MAP).Close();
				}
			//}
			
			ActionUnfoldMap action = ActionUnfoldMap.Cast(m_ActionData.m_Action);
			
			if(action)
				action.End(m_ActionData);
		}
	}
	
	void PerformMapChange()
	{
		if (m_ActionData.m_Player.IsSwimming() || m_ActionData.m_Player.IsFalling() || m_ActionData.m_Player.IsClimbingLadder() || m_ActionData.m_Player.IsUnconscious() || m_ActionData.m_Player.IsRestrained())
			return;
		
		ItemMap chernomap = ItemMap.Cast(m_ActionData.m_Player.GetItemInHands());
		if (chernomap && !m_ActionData.m_Player.IsMapOpen() && !m_MapFolding)
		{
			//MiscGameplayFunctions.TurnItemIntoItem(chernomap, opened_map, m_ActionData.m_Player);
			chernomap.SetMapStateOpen(true,m_ActionData.m_Player);
	
			if (!GetGame().IsMultiplayer() || GetGame().IsClient())
			{
				UIManager 	m_UIManager;
				m_UIManager = GetGame().GetUIManager();
				m_UIManager.CloseAll();
				m_UIManager.EnterScriptedMenu(MENU_MAP, NULL);
			}
		}
		else if (chernomap && m_ActionData.m_Player.IsMapOpen())
		{
			//MiscGameplayFunctions.TurnItemIntoItem(chernomap, closed_map, m_ActionData.m_Player);
			chernomap.SetMapStateOpen(false,m_ActionData.m_Player);
			m_MapFolding = true;
		}
	}
}

class ActionUnfoldMap: ActionBase
{
	void ActionUnfoldMap()
	{
	}
	
	override bool IsInstant()
	{
		return false;
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override int GetType()
	{
		return AT_UNFOLD_MAP;
	}

	override string GetText()
	{
		return "#unfold_map";
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (player.m_hac || player.IsMapOpen())
		{
			return false;
		}
		return true;
	}
	
	override int GetActionCategory()
	{
		return AC_SINGLE_USE;
	}
	
	override void OnStartClient( ActionData action_data )
	{
		OpenMap( action_data );
	}
	
	override void OnStartServer( ActionData action_data )
	{
		OpenMap( action_data );
	}
	
	void OpenMap( ActionData action_data )
	{
		if (!action_data.m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
		{
			action_data.m_Player.m_hac = ActionUnfoldMapCB.Cast(action_data.m_Player.AddCommandModifier_Action(DayZPlayerConstants.CMD_ACTIONMOD_VIEWMAP,ActionUnfoldMapCB));
		}
		else
		{
			action_data.m_Player.m_hac = ActionUnfoldMapCB.Cast(action_data.m_Player.StartCommand_Action(DayZPlayerConstants.CMD_ACTIONFB_VIEWMAP,ActionUnfoldMapCB,GetStanceMask(action_data.m_Player)));
		}
		
		// sets player for associated callback to use
		if (action_data.m_Player.m_hac)
		{
			action_data.m_Player.m_hac.SetActionData(action_data);
		}
	}
};