typedef Param3<int, int, string> TSelectableActionInfo;

class TSelectableActionInfoArray extends array<ref TSelectableActionInfo>
{
	bool IsSameAs(TSelectableActionInfoArray other)
	{
		if( this.Count() != other.Count() )
		{
			return false;
		}
		
		for( int i = 0; i < Count(); ++i )
		{
			TSelectableActionInfo ai1 = this.Get(i);
			TSelectableActionInfo ai2 = other.Get(i);
			
			if( ai1.param2 != ai2.param2 )
			{
				return false;
			}
			
			if( ai1.param3 != ai2.param3 )
			{
				return false;
			}
		}
		return true;
	}
};

class ActionManagerBase
{


	//ref ActionConstructor						m_ActionConstructor;
	PlayerBase									m_Player;
	ref HumanCommandActionCallback				m_Command;
	
	protected ActionTarget						m_TestedActionTarget;
	protected ItemBase							m_TestedActionItem;
		
	protected ActionBase						m_PrimaryAction;
	protected ActionTarget						m_PrimaryActionTarget;
	protected ItemBase							m_PrimaryActionItem;
	protected ActionBase						m_SecondaryAction;
	protected ActionTarget						m_SecondaryActionTarget;
	protected ItemBase							m_SecondaryActionItem;
	bool										m_PrimaryActionEnabled;
	bool										m_SecondaryActionEnabled;
	bool										m_TertiaryActionEnabled;
	ref TSelectableActionInfoArray				m_SelectableActions;
	int                             			m_SelectedActionIndex;
	bool                            			m_SelectableActionsHasChanged;
	bool										m_Interrupted;
#ifndef OLD_ACTIONS	
	static ref array<ref ActionBase>			m_ActionsArray;
	static ref map<typename, ActionBase>		m_ActionNameActionMap;
	protected bool								m_ActionWantEndRequest;
	protected bool								m_ActionInputWantEnd;
#else
	ref map<int, ActionBase>					m_ActionsMap;
	ref array<ref ActionBase>		m_Actions;

#endif
		
//Pending actions waiting for acknowledgment
	protected int 					m_PendingActionAcknowledgmentID;
	
	protected ref ActionData		m_CurrentActionData;
	
	void ActionManagerBase(PlayerBase player)
	{
		m_Player = player;
		if ( m_Player )
		{
			m_SelectableActions = new TSelectableActionInfoArray;
			m_SelectedActionIndex = 0;
			m_SelectableActionsHasChanged = false;
			
			m_PendingActionAcknowledgmentID = -1;
			
			m_CurrentActionData = NULL;
			m_Interrupted = false;
			
			
			
#ifdef OLD_ACTIONS
			m_ActionsMap = new map<int, ActionBase>;
			m_Actions = new array<ref ActionBase>;

			ActionConstructor ac = new ActionConstructor;
			ac.ConstructActions(m_Actions);

			for (int i = 0; i < m_Actions.Count(); i++)
			{	
				m_Actions.Get(i).CreateConditionComponents();
				m_ActionsMap.Set(m_Actions.Get(i).GetType(), m_Actions.Get(i));
			}
#else
			ActionConstructor ac = new ActionConstructor;
			if ( !m_ActionsArray )
			{
				ac.ConstructActions( m_ActionsArray, m_ActionNameActionMap );
			}
			m_ActionWantEndRequest = false;
			m_ActionInputWantEnd = false;
#endif
		}
	}
	
	ActionBase GetRunningAction()
	{
		if ( m_CurrentActionData )
		{
			return m_CurrentActionData.m_Action;
		}
		return NULL;
	}
	
	void Update(int pCurrentCommandID)
	{
		if(m_CurrentActionData)
		{
			if(m_Interrupted)
			{
				LocalInterrupt();
				m_Interrupted = false;
			}
		}
		if(m_CurrentActionData)
		{
			if(m_CurrentActionData.m_State != UA_AM_PENDING && m_CurrentActionData.m_State != UA_AM_REJECTED && m_CurrentActionData.m_State != UA_AM_ACCEPTED)
			{
				m_CurrentActionData.m_Action.OnUpdate(m_CurrentActionData);
			}
		}
	}
	
	void OnSyncJuncture(int pJunctureID, ParamsReadContext pCtx)
	{
		int AcknowledgmentID;
		switch (pJunctureID)
		{
			case DayZPlayerSyncJunctures.SJ_ACTION_ACK_ACCEPT:
				pCtx.Read(AcknowledgmentID);
				if (m_CurrentActionData && AcknowledgmentID == m_PendingActionAcknowledgmentID)
					m_CurrentActionData.m_State = UA_AM_ACCEPTED;
				break;
			case DayZPlayerSyncJunctures.SJ_ACTION_ACK_REJECT:
				pCtx.Read(AcknowledgmentID);
				if (m_CurrentActionData && AcknowledgmentID == m_PendingActionAcknowledgmentID)
					m_CurrentActionData.m_State = UA_AM_REJECTED;
				break;
			case DayZPlayerSyncJunctures.SJ_ACTION_INTERRUPT:
				m_Interrupted = true;
				break;
		}
	}
		
	ActionTarget FindActionTarget()
	{
	}
	
	void StartDeliveredAction()
	{
	}
	
	#ifndef OLD_ACTIONS
	static ActionBase GetAction(typename actionName)
	{
		if (m_ActionNameActionMap)
			return m_ActionNameActionMap.Get(actionName);
		return null;
	}
	
	static ActionBase GetAction(int actionID)
	{
		return m_ActionsArray.Get(actionID);
	}
	#else
	
	ActionBase GetAction(int actionID)
	{
		return m_ActionsMap.Get(actionID);
	}
	
	#endif
	
	ActionBase GetContinuousAction()
	{
		if ( m_PrimaryAction )
		{
			return m_PrimaryAction;
		}
		return NULL;
	}
	
	ActionBase GetSingleUseAction()
	{
		if ( m_SecondaryAction )
		{ 
			return m_SecondaryAction;
		}
		return NULL;
	}
			
	TSelectableActionInfoArray GetSelectableActions()
	{
		return m_SelectableActions;
	}

	int GetSelectedActionIndex()
	{
		return m_SelectedActionIndex;
	}
	
	void SelectNextAction()
	{
#ifdef OLD_ACTIONS
		if( m_SelectableActions.Count() == 0 )
		{
			return;
		}
		
		m_SelectedActionIndex++;
		if( m_SelectedActionIndex >= m_SelectableActions.Count() )
		{
			m_SelectedActionIndex = 0;
		}
#endif
	}
	
	void SelectPrevAction()
	{
#ifdef OLD_ACTIONS
		if( m_SelectableActions.Count() == 0 )
		{
			return;
		}
		
		m_SelectedActionIndex--;
		if( m_SelectedActionIndex < 0 )
		{
			m_SelectedActionIndex = m_SelectableActions.Count() - 1;
		}
#endif
	}
	
	bool IsSelectableActionsChanged()
	{
		return m_SelectableActionsHasChanged;
	}
	//------------------------------------------------------
	bool ActionPossibilityCheck(int pCurrentCommandID)
	{
		if ( m_Player.IsSprinting() || m_Player.IsUnconscious() || m_Player.GetCommandModifier_Action() || m_Player.GetCommand_Action() || m_Player.IsPlayingEmote() )
			return false;
		
		if (pCurrentCommandID == DayZPlayerConstants.COMMANDID_ACTION || pCurrentCommandID == DayZPlayerConstants.COMMANDID_MOVE || pCurrentCommandID == DayZPlayerConstants.COMMANDID_SWIM || pCurrentCommandID == DayZPlayerConstants.COMMANDID_LADDER || pCurrentCommandID == DayZPlayerConstants.COMMANDID_VEHICLE)
			return true;
		
		return false;
	}	
	//------------------------------------------------------
	protected void SetActionContext( ActionTarget target, ItemBase item )
	{
		m_TestedActionTarget = target;
		m_TestedActionItem = item;
	}
	
	//------------------------------------------------------	
	protected void SetContinuousAction( ActionBase action, ActionTarget target, ItemBase item )
	{
		m_PrimaryAction = action;
		m_PrimaryActionTarget = target;
		m_PrimaryActionItem = item;
	}
	
	protected void SetSingleUseAction( ActionBase action, ActionTarget target, ItemBase item )
	{
		m_SecondaryAction = action;
		m_SecondaryActionTarget = target;
		m_SecondaryActionItem = item;
	}
	
	protected void RemoveContinuousAction()
	{
		m_PrimaryAction = NULL;
		m_PrimaryActionTarget = NULL;
		m_PrimaryActionItem = NULL;
	}
	
	protected void RemoveSingleUseAction()
	{
		m_SecondaryAction = NULL;
		m_SecondaryActionTarget = NULL;
		m_SecondaryActionItem = NULL;
	}
		
	protected void RemoveActions()
	{
		RemoveContinuousAction();
		RemoveSingleUseAction();
	}
	
	void DisableContinuousAction()
	{
		m_PrimaryActionEnabled = false;
	}
	
	void EnableContinuousAction()
	{
		m_PrimaryActionEnabled = true;		
	}
	
	void DisableSingleUseAction()
	{
		m_SecondaryActionEnabled = false;
	}
	
	void EnableSingleUseAction()
	{
		m_SecondaryActionEnabled = true;		
	}
	
	void DisableInteractAction()
	{
		m_TertiaryActionEnabled = false;
	}
	
	void EnableInteractAction()
	{
		m_TertiaryActionEnabled = true;		
	}
	
	void EnableActions()
	{
		//Print("ActionManager - Enable actions");
		EnableContinuousAction();
		EnableSingleUseAction();
		EnableInteractAction();
	}
	
	void DisableActions()
	{
		//Print("ActionManager - Disable actions");
		DisableContinuousAction();
		DisableSingleUseAction();
		DisableInteractAction();
	}
	//---------------------------------------------------------------------
		
	int GetActionState(ActionBase action)
	{
		if( m_CurrentActionData )
		{
			return m_CurrentActionData.m_State;
		}
		return UA_NONE; // TODO check if it is correct constant
	}
	
	//---------------------------------
	// EVENTS
	//---------------------------------
	void OnContinuousStart()
	{
	}
	
	void OnContinuousCancel()
	{	
	}
		
	void OnSingleUse()
	{
	}
	
	void Interrupt()
	{
	}
	protected void LocalInterrupt()
	{
		if (m_CurrentActionData && m_CurrentActionData.m_Action)
			m_CurrentActionData.m_Action.Interrupt(m_CurrentActionData);
	} 
	
	void OnInteractAction() //Interact
	{
	}

	void OnInstantAction(int user_action_id, Param data = NULL)
	{
	}
	
	void OnActionEnd( )
	{
		Debug.Log("[AM] Action data cleared (" + m_Player + ")");
		m_CurrentActionData = NULL;
		
		m_Player.ResetActionEndInput();
	}
	
	void OnJumpStart()
	{
	}

	bool OnInputUserDataProcess(int userDataType, ParamsReadContext ctx)
	{
		return false;
	}
	
	float GetActionComponentProgress()
	{
		if(m_CurrentActionData)
			return m_CurrentActionData.m_Action.GetProgress(m_CurrentActionData);
		return 0.0;
	}
	
	int GetActionState()
	{
		if(m_CurrentActionData)
			return m_CurrentActionData.m_Action.GetState(m_CurrentActionData);
		return UA_NONE;
	}
	
	ActionReciveData GetReciveData()
	{
		return NULL;
	}
};