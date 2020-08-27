typedef map<typename,ref array<ActionBase_Basic>>		TInputActionMap;
typedef map<typename,ref ActionInput>					TTypeNameActionInputMap;

class ActionManagerClient: ActionManagerBase 
{
	
	//Last send AcknowledgmentID (client can send more requests before recive ackfor first action)
	protected int 								m_LastAcknowledgmentID;
	protected bool								m_ActionPossible;
	protected ref array<ref InventoryLocation>	m_ReservedInventoryLocations;
	protected ref InventoryActionHandler		m_InventoryActionHandler;
	protected ref InventoryLocation				m_HandInventoryLocationTest;
	protected ref TTypeNameActionInputMap		m_RegistredInputsMap;
	
	protected ref ActionData 					m_PendingActionData;

	//protected bool								m_ActionWantEnd;		//If set action try end // send request to server to end
	protected bool 								m_ActionWantEndRequest_Send;		//Request to server was sended
	protected bool								m_ActionInputWantEnd_Send;	

	void ActionManagerClient(PlayerBase player) 
	{
		//ActionManagerBase(player);
		m_HandInventoryLocationTest = new InventoryLocation;
		m_HandInventoryLocationTest.SetHands(player,null);
		m_LastAcknowledgmentID = 1;
		m_Targets	= new ActionTargets(player);
		m_ReservedInventoryLocations = new array<ref InventoryLocation>;
		m_InventoryActionHandler = new InventoryActionHandler(player);

		m_ActionWantEndRequest_Send = false;
		m_ActionInputWantEnd_Send = false;
		RegisterInputs(player);

	}
	
	override void Update(int pCurrentCommandID)
	{
		m_InventoryActionHandler.OnUpdate();
		super.Update(pCurrentCommandID);
		m_ActionPossible = ActionPossibilityCheck(pCurrentCommandID);
		
		if (m_PendingActionData) //SP only
		{
			m_CurrentActionData = m_PendingActionData;
			
			m_CurrentActionData.m_Action.Start(m_CurrentActionData);
			
			if ( m_CurrentActionData.m_Action.IsInstant() )
				OnActionEnd();
			
			m_PendingActionData = null;
		}
		
		if (m_CurrentActionData)
		{
			if (m_CurrentActionData.m_State != UA_AM_PENDING && m_CurrentActionData.m_State != UA_AM_REJECTED && m_CurrentActionData.m_State != UA_AM_ACCEPTED)
				m_CurrentActionData.m_Action.OnUpdateClient(m_CurrentActionData);
			
			switch (m_CurrentActionData.m_State)
			{
				case UA_AM_PENDING:
					break;
			
				case UA_AM_ACCEPTED:
					// check pCurrentCommandID before start or reject 
					if ( m_ActionPossible && pCurrentCommandID != DayZPlayerConstants.COMMANDID_SWIM && pCurrentCommandID != DayZPlayerConstants.COMMANDID_LADDER && ( !m_Player.IsRestrained() || m_CurrentActionData.m_Action.CanBeUsedInRestrain() ) )
					{
						m_CurrentActionData.m_State = UA_START;
						m_CurrentActionData.m_Action.Start(m_CurrentActionData);
						
						if ( m_CurrentActionData.m_Action.IsInstant() )
							OnActionEnd();
					}
					else
					{
						OnActionEnd();
					}
					m_PendingActionAcknowledgmentID = -1;
					break;
				
				case UA_AM_REJECTED:
					OnActionEnd();
					m_PendingActionAcknowledgmentID = -1;
			
					//m_Player.GetDayZPlayerInventory().UnlockHands();
					break;
			
				default:
					if ( m_ActionWantEndRequest )
					{
						if ( GetGame().IsMultiplayer() && !m_CurrentActionData.m_Action.IsLocal() )
						{
							if ( !m_ActionWantEndRequest_Send && ScriptInputUserData.CanStoreInputUserData() )
							{
								Debug.Log("Action=" + m_CurrentActionData.m_Action.Type() + " ended, STS=" + m_Player.GetSimulationTimeStamp());
								ScriptInputUserData ctx = new ScriptInputUserData;
								ctx.Write(INPUT_UDT_STANDARD_ACTION_END_REQUEST);
								ctx.Send();
								
								m_ActionWantEndRequest_Send = true;
									
								m_ActionWantEndRequest = false;
								m_CurrentActionData.m_Action.EndRequest(m_CurrentActionData);
							}
						}
						else
						{
							m_ActionWantEndRequest = false;
							m_CurrentActionData.m_Action.EndRequest(m_CurrentActionData);
						}
					}
					
					if ( m_ActionInputWantEnd )
					{
						if ( GetGame().IsMultiplayer() && !m_CurrentActionData.m_Action.IsLocal() )
						{
							if ( !m_ActionInputWantEnd_Send && ScriptInputUserData.CanStoreInputUserData() )
							{
								Debug.Log("Action=" + m_CurrentActionData.m_Action.Type() + " input ended, STS=" + m_Player.GetSimulationTimeStamp());
								ScriptInputUserData ctxi = new ScriptInputUserData;
								ctxi.Write(INPUT_UDT_STANDARD_ACTION_INPUT_END);
								ctxi.Send();
								
								m_ActionInputWantEnd_Send = true;
									
								m_ActionInputWantEnd = false;
								m_CurrentActionData.m_Action.EndInput(m_CurrentActionData);
							}
						}
						else
						{
							if (!m_ActionInputWantEnd_Send)
							{
								m_ActionInputWantEnd_Send = true;
								m_ActionInputWantEnd = false;
								m_CurrentActionData.m_Action.EndInput(m_CurrentActionData);
							}
						}
					}
				break;
			}
		}
		
#ifdef DEVELOPER
		if ( DeveloperFreeCamera.IsFreeCameraEnabled() )
		{
			m_ActionPossible = false;
			ResetInputsActions();
		}
		else
		{
#endif
			if (!m_CurrentActionData)
			{
				if ( m_Player.IsRaised() )
				{
					m_Targets.Clear();
				}
				else
				{
					m_Targets.Update();
				}
				FindContextualUserActions( pCurrentCommandID );	
			}
		
			InputsUpdate();
#ifdef DEVELOPER
		}
#endif		

	}
	
	void RegisterInputs(PlayerBase player)
	{
		if (!m_RegistredInputsMap)
		{
			m_RegistredInputsMap = new TTypeNameActionInputMap;

			for (int i = 0; i < m_ActionsArray.Count(); i++)
			{	
				ActionBase action = m_ActionsArray.Get(i);
				typename input_type_name = action.GetInputType();
				ref ActionInput ai;
			
				ai = ActionInput.Cast(m_RegistredInputsMap.Get(input_type_name));
				if(!ai)
				{
					ai = ActionInput.Cast(input_type_name.Spawn());
					m_RegistredInputsMap.Insert(input_type_name, ai);
				}
				action.SetInput(ai);
			}
		
			for (int j = 0; j < m_RegistredInputsMap.Count(); j++ )
			{
				m_RegistredInputsMap.GetElement(j).Init(player, this);
			}
		}
	}
	
	void RequestEndAction()
	{
		if ( !m_ActionWantEndRequest_Send )
		{
			m_ActionWantEndRequest = true;
		}
	}
	
	void EndActionInput()
	{
		if (!m_ActionInputWantEnd_Send)
		{
			m_ActionInputWantEnd = true;
		}
	}
	
	void InputsUpdate()
	{
		if (m_CurrentActionData)
		{
			if (!m_ActionInputWantEnd)
			{
				ActionInput ai = m_CurrentActionData.m_Action.GetInput();
				ai.Update();
				if (m_Player.IsQBControl())
				{
					if ( ai.JustActivate() )
						m_Player.SetActionEndInput(m_CurrentActionData.m_Action);
				}
				else
				{
					if ( ai.WasEnded() && ( ai.GetInputType() == ActionInputType.AIT_CONTINUOUS || ai.GetInputType() == ActionInputType.AIT_CLICKCONTINUOUS ) )
					{
						EndActionInput();
					}
				}
			}
		}
		else
		{
			if ( m_ActionsAvaibale )
			{
				for (int i = 0; i < m_RegistredInputsMap.Count();i++)
				{
					ActionInput ain = m_RegistredInputsMap.GetElement(i);
					ain.Update();
				
					if ( ain.JustActivate() )
					{
						ActionBase action = ain.GetAction();
						if ( action )
						{
							ActionStart(action, ain.GetUsedActionTarget(), ain.GetUsedMainItem());
							break;
						}
					}
				}
			}
		}
	}
	
	ActionBase GetPossibleAction(typename inputType)
	{
		ActionInput action_input = m_RegistredInputsMap.Get(inputType);
		if(action_input)
		{
			return action_input.GetPossibleAction();
		}
		return NULL;
	}
	
	array<ActionBase> GetPossibleActions(typename inputType)
	{
		ActionInput action_input = m_RegistredInputsMap.Get(inputType);
		if(action_input)
		{
			return action_input.GetPossibleActions();
		}
		return NULL;
	}
	
	int GetPossibleActionIndex(typename inputType)
	{
		ActionInput action_input = m_RegistredInputsMap.Get(inputType);
		if(action_input)
		{
			return action_input.GetPossibleActionIndex();
		}
		return -1;
	}

	//--------------------------------------------------------
	// Alows to set different action to current contextual one //jtomasik - pri injectu budu muset serveru poslat ID injectnute akce
	//--------------------------------------------------------	
	void InjectAction( ActionBase action, ActionTarget target, ItemBase item)
	{
		ActionInput ai = action.GetInput();
		ai.ForceAction(action, target, item );
	}
	
	void InjectAction( typename actionType, ActionTarget target, ItemBase item)
	{
		ActionBase action = GetAction(actionType);
		InjectAction(action, target, item);
	}
	
	void EjectAction( ActionBase action )
	{
		ActionInput ai = action.GetInput();
		ai.ClearForcedAction();
	}
	
	void EjectAction( typename actionType )
	{
		ActionBase action = GetAction(actionType);
		EjectAction(action);
	}
		
	void ForceTarget(Object targetObject)
	{
		Object parent = null;
		EntityAI targetEntity = EntityAI.Cast(targetObject);
		if (targetEntity)
			parent = targetEntity.GetHierarchyParent();
		m_ForceTarget = new ActionTarget(targetObject, parent, -1, vector.Zero, -1);
	}
	
	void ClearForceTarget()
	{
		m_ForceTarget = NULL;
	}
	
			
	//-------------------------------------------------------------------------
	override ActionTarget FindActionTarget()
	{
		if(m_ForceTarget)
			return m_ForceTarget;
		
		ActionTarget action_target;
		action_target = NULL;
		int targetsCount = m_Targets.GetTargetsCount();
		if( targetsCount )
		{
			for( int i = 0; i < targetsCount; ++i )
			{
				action_target = m_Targets.GetTarget(i);
				Object targetObject = action_target.GetObject();
				Object targetParent = action_target.GetParent();

				if( targetParent && targetParent.IsEntityAI() )
				{
					break;
				}

				if( targetObject && (targetObject.IsEntityAI() || targetObject.IsWoodBase() || targetObject.IsRock()) )
				{
					break;
				}
			}
		}
		else
		{
			action_target = new ActionTarget(null, null, -1, vector.Zero, -1 );
		}
		return action_target;
	}
	
	ItemBase FindActionItem()
	{
		ItemBase item;
		if ( m_Player && m_Player.GetItemInHands() && m_Player.GetItemInHands().IsItemBase() ) 
		{
			item = m_Player.GetItemInHands();
		}
		return item;
	}
	
	protected bool HasHandInventoryReservation()
	{
		m_HandInventoryLocationTest.SetHands(m_Player,m_Player.GetItemInHands());
		if (m_Player.GetHumanInventory().HasInventoryReservation(m_Player.GetItemInHands(),m_HandInventoryLocationTest))
			return true;
		return false;
	}
	
	protected void FindContextualUserActions( int pCurrentCommandID )
	{
		m_ActionsAvaibale = false;
		if ( !m_ActionPossible || HasHandInventoryReservation() || GetGame().IsInventoryOpen())
		{
			ResetInputsActions();
			return;
		}
		
		if ( !GetRunningAction() )
		{	
			ActionBase action;
			ActionTarget 	target;
			ItemBase 		item;

			// Gathering current inputs
			m_ActionsAvaibale = true;
			
			item = FindActionItem();
			target = FindActionTarget();
			
			ItemBase target_item;
			Class.CastTo(target_item,  target.GetObject() );
			
			m_Player.GetCraftingManager().OnUpdate(item,target_item);
			
			int actionConditionMask = ActionBase.ComputeConditionMask(m_Player,target,item);
			for (int i = 0; i < m_RegistredInputsMap.Count();i++)
			{
				ActionInput ain = m_RegistredInputsMap.GetElement(i);
				ain.UpdatePossibleActions(m_Player,target,item, actionConditionMask);
			}
			SetActionContext( target,item );
		}
	}
	
	//TOOD MW In progress
	protected bool LockInventory(ActionData action_data)
	{
		if ( action_data.m_Action.IsInstant() )
		{
			Print("[AM][INVL](-) Inventory lock - Not Used");
				return true;
		}
		else
		{
			Print("[AM][INVL](X) Inventory lock");
			if (action_data.m_Action)
				return action_data.m_Action.InventoryReservation(action_data);
		}
		return false;
	}
	void UnlockInventory(ActionData action_data)
	{
		//if ( action_data.m_Action.IsInstant() )
		//{
		//	Print("[AM][INVL](-) Inventory unlock - Not Used");
		//}
		//else
		//{
			Print("[AM][INVL](O) Inventory unlock");
			if (action_data.m_Action)
				action_data.m_Action.ClearInventoryReservation(action_data);
		//}
	}
	
	protected void ActionStart(ActionBase action, ActionTarget target, ItemBase item, Param extra_data = NULL )
	{
		if ( !m_CurrentActionData && action ) 
		{
			m_ActionWantEndRequest_Send = false;
			m_ActionInputWantEnd_Send = false;
			m_ActionWantEndRequest = false;
			m_ActionInputWantEnd = false;
			
			if ( action.CanBePerformedFromQuickbar() )
				m_Player.SetActionEndInput(action);
			
			HandleInputsOnActionStart(action);

			Debug.Log("Action=" + action.Type() + " started, STS=" + m_Player.GetSimulationTimeStamp());
			m_Interrupted = false;
			if ( GetGame().IsMultiplayer() && !action.IsLocal() )
			{
				if (!ScriptInputUserData.CanStoreInputUserData())
				{
					DPrint("ScriptInputUserData already posted - ActionManagerClient");
					return;
				}
			}
			
			Debug.Log("[Action DEBUG] Start time stamp ++: " + m_Player.GetSimulationTimeStamp());
			
			if( !action.SetupAction(m_Player, target, item, m_CurrentActionData, extra_data ))
			{
				Print("Can not inicialize action - ActionManagerClient");
				m_CurrentActionData = NULL;
				return;
			}
			Debug.Log("[AM] Action data created (" + m_Player + ")");
			
			if ( GetGame().IsMultiplayer() && !action.IsLocal() )
			{
				ScriptInputUserData ctx = new ScriptInputUserData;
				ctx.Write(INPUT_UDT_STANDARD_ACTION_START);
				ctx.Write(action.GetID());

				action.WriteToContext(ctx, m_CurrentActionData);
					
				if (action.UseAcknowledgment())
				{
					m_CurrentActionData.m_State = UA_AM_PENDING;
					m_PendingActionAcknowledgmentID = ++m_LastAcknowledgmentID;
						
					ctx.Write(m_PendingActionAcknowledgmentID);
				}
					
				ctx.Send();
					
				if (!action.UseAcknowledgment())
				{
					action.Start(m_CurrentActionData);
					if( action.IsInstant() )
						OnActionEnd();
				}
			}
			else
			{
				action.Start(m_CurrentActionData);
				if( action.IsInstant() )
					OnActionEnd();
			}
		}
	}

	void HandleInputsOnActionStart(ActionBase action)
	{
		for (int i = 0; i < m_RegistredInputsMap.Count();i++)
		{
			ActionInput ain = m_RegistredInputsMap.GetElement(i);
			if(action.GetInput() == ain)
			{
				ain.OnActionStart();
			}
			else
			{
				ain.Reset();
			}
		}
	}
	
	void HandleInputsOnActionEnd()
	{
		ResetInputsState();
	}
	
	void ResetInputsState()
	{
		for (int i = 0; i < m_RegistredInputsMap.Count();i++)
		{
			ActionInput ain = m_RegistredInputsMap.GetElement(i);
			ain.Reset();
		}
	}
	
	void ResetInputsActions()
	{
		for (int i = 0; i < m_RegistredInputsMap.Count();i++)
		{
			ActionInput ain = m_RegistredInputsMap.GetElement(i);
			ain.ActionsSelectReset();
		}
	}

	override void OnJumpStart()
	{
		if(m_CurrentActionData)
		{
			if( m_CurrentActionData.m_State == UA_AM_PENDING || m_CurrentActionData.m_State == UA_AM_REJECTED || m_CurrentActionData.m_State == UA_AM_ACCEPTED)
			{
				OnActionEnd();
				m_PendingActionAcknowledgmentID = -1;
			}
			else
			{
				m_CurrentActionData.m_Action.Interrupt(m_CurrentActionData);
			}
		}
	}
	
	//Instant Action (Debug Actions) ---------------------------------
	override void OnInstantAction(typename user_action_type, Param data = NULL)
	{
		ActionBase action = GetAction(user_action_type);
		if(action)
		{
			ActionStart(action,NULL,NULL, data);
		}
	}
	
#ifdef BOT
	/// used for bots
	void PerformAction(int user_action_id, ActionTarget target, ItemBase item, Param extraData = NULL)
	{
		ActionStart(GetAction(user_action_id), target, item, extraData);
	}
#endif
	
	void PerformActionStart(ActionBase action, ActionTarget target, ItemBase item, Param extra_data = NULL )
	{
		if (!GetGame().IsMultiplayer())
		{
			m_PendingActionData = new ActionData;
	
			if (!action.SetupAction(m_Player,target,item,m_PendingActionData,extra_data))
				m_PendingActionData = null;
		}
		else
			ActionStart(action, target, item, extra_data);
	}
	
	override void OnActionEnd()
	{
		if(m_CurrentActionData)
		{
			UnlockInventory(m_CurrentActionData);
			if( m_CurrentActionData.m_Action.RemoveForceTargetAfterUse() )
				m_InventoryActionHandler.DeactiveAction();
			
			super.OnActionEnd();
			HandleInputsOnActionEnd();
		}
	}

	void SetInventoryAction(ActionBase action_name, ItemBase target_item, ItemBase main_item)
	{
		m_InventoryActionHandler.SetAction(action_name, target_item, main_item);
	}

	void SetInventoryAction(ActionBase action_name, ActionTarget target, ItemBase main_item)
	{
		m_InventoryActionHandler.SetAction(action_name, target, main_item);
	}
	
	void UnsetInventoryAction()
	{
		m_InventoryActionHandler.DeactiveAction();
	}

	override void SelectNextAction()
	{
		ActionInput ai = m_RegistredInputsMap.Get(InteractActionInput);
		if(ai)
		{
			ai.SelectNextAction();
		}
	}
	
	override void SelectPrevAction()
	{
		ActionInput ai = m_RegistredInputsMap.Get(InteractActionInput);
		if(ai)
		{
			ai.SelectPrevAction();
		}
	}

	bool CanPerformActionFromQuickbar(ItemBase mainItem, ItemBase targetItem)
	{	
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			array<ActionBase_Basic> actions;
			ActionBase picked_action;
			int i;
			
			mainItem.GetActions(QuickaBarActionInput, actions);
			if (actions)
			{
				for ( i = 0; i < actions.Count(); i++ )
				{			
					picked_action = ActionBase.Cast(actions[i]);
					if ( picked_action && picked_action.Can(m_Player,target, itemInHand) )
					{
						if( hasTarget == picked_action.HasTarget())
							return true;
					}
				}
			}			
			//First check continuous actions
			mainItem.GetActions(ContinuousDefaultActionInput, actions);
			if (actions)
			{
				for ( i = 0; i < actions.Count(); i++ )
				{			
					picked_action = ActionBase.Cast(actions[i]);
					if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
					{
						if( hasTarget == picked_action.HasTarget())
							return true;
					}
				}
			}
			//second single use actions
			mainItem.GetActions(DefaultActionInput, actions);
			if (actions)
			{
				for ( i = 0; i < actions.Count(); i++ )
				{
					picked_action = ActionBase.Cast(actions[i]);
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
					{
						if( hasTarget == picked_action.HasTarget())
							return true;
					}
				}
			}
		}
		return false;
	}
	
	void PerformActionFromQuickbar(ItemBase mainItem, ItemBase targetItem)
	{
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		ItemBase parent = null;
		if (targetItem)
			parent = ItemBase.Cast(targetItem.GetHierarchyParent());
		target = new ActionTarget(targetItem, parent, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			ActionBase picked_action;
			array<ActionBase_Basic> actions;
			int i;
					
			mainItem.GetActions(QuickaBarActionInput, actions);
			if (actions)
			{
				for ( i = 0; i < actions.Count(); i++ )
				{
					picked_action = ActionBase.Cast(actions[i]);
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) )
					{
						if( hasTarget == picked_action.HasTarget())
						{
							ActionStart(picked_action, target, mainItem);
							return;
						}
					}
				}
			}
			
			//First continuous actions
			mainItem.GetActions(ContinuousDefaultActionInput, actions);
			if (actions)
			{
				for ( i = 0; i < actions.Count(); i++ )
				{
					picked_action = ActionBase.Cast(actions[i]);
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
					{
						if( hasTarget == picked_action.HasTarget())
						{
							ActionStart(picked_action, target, mainItem);
							return;
						}
					}
				}
			}
			//Second check single use actions
			mainItem.GetActions(DefaultActionInput, actions);
			if (actions)
			{
				for ( i = 0; i < actions.Count(); i++ )
				{
					picked_action = ActionBase.Cast(actions[i]);
					if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
					{
						if( hasTarget == picked_action.HasTarget())
						{
							ActionStart(picked_action, target, mainItem);
							return;
						}
					}
				}
			}

		}
	}
	
	bool CanPerformActionFromInventory(ItemBase mainItem, ItemBase targetItem)
	{	
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			array<ActionBase_Basic> actions;
			ActionBase picked_action;
			
			//First check single use actions
			mainItem.GetActions(DefaultActionInput, actions);
			if (actions)
			{
				for ( int i = 0; i < actions.Count(); i++ )
				{			
					picked_action = ActionBase.Cast(actions[i]);
					if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromInventory() )
					{
						if( hasTarget == picked_action.HasTarget())
							return true;
					}
				}
			}
		}
		return false;
	}
	
	void PerformActionFromInventory(ItemBase mainItem, ItemBase targetItem)
	{
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			ActionBase picked_action;
			array<ActionBase_Basic> actions;
			
			//First check single use actions
			mainItem.GetActions(DefaultActionInput, actions);
			if (actions)
			{
				for ( int j = 0; j < actions.Count(); j++ )
				{
					picked_action = ActionBase.Cast(actions[j]);
					if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromInventory() )
					{
						if( hasTarget == picked_action.HasTarget())
						{
							ActionStart(picked_action, target, mainItem);
							return;
						}
					}
				}
			}
		}
	}
	
	bool CanSetActionFromInventory(ItemBase mainItem, ItemBase targetItem)
	{
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			array<ActionBase_Basic> actions;
			ActionBase picked_action;
			
			//First check single use actions
			mainItem.GetActions(DefaultActionInput, actions);
			if (actions)
			{
				for ( int i = 0; i < actions.Count(); i++ )
				{			
					picked_action = ActionBase.Cast(actions[i]);
					if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBeSetFromInventory() )
					{
						if( hasTarget == picked_action.HasTarget())
							return true;
					}
				}
			}
			//second continuous actions
			mainItem.GetActions(ContinuousDefaultActionInput, actions);
			if (actions)
			{
				for ( int j = 0; j < actions.Count(); j++ )
				{
					picked_action = ActionBase.Cast(actions[j]);
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBeSetFromInventory() )
					{
						if( hasTarget == picked_action.HasTarget())
							return true;
					}
				}
			}
		}
		return false;
	}
	
	void SetActionFromInventory(ItemBase mainItem, ItemBase targetItem)
	{
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			array<ActionBase_Basic> actions;
			ActionBase picked_action;
			
			//First check single use actions
			mainItem.GetActions(DefaultActionInput, actions);
			if (actions)
			{
				for ( int i = 0; i < actions.Count(); i++ )
				{			
					picked_action = ActionBase.Cast(actions[i]);
					if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBeSetFromInventory() )
					{
						if( hasTarget == picked_action.HasTarget())
						{
							SetInventoryAction( picked_action, target, itemInHand);
							return;
						}
					}
				}
			}
			//second continuous actions
			mainItem.GetActions(ContinuousDefaultActionInput, actions);
			if (actions)
			{
				for ( int j = 0; j < actions.Count(); j++ )
				{
					picked_action = ActionBase.Cast(actions[j]);
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBeSetFromInventory() )
					{
						if( hasTarget == picked_action.HasTarget())
						{
							SetInventoryAction( picked_action, target, itemInHand);
							return;
						}
					}
				}
			}
		}	
	}
	
	override void Interrupt()
	{
		if(m_CurrentActionData)
			m_Interrupted = true;
	}
	
	private ref ActionTarget m_ForceTarget;
	private ref ActionTargets m_Targets;
};
