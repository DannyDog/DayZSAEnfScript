#ifndef OLD_ACTIONS
typedef map<typename,ref array<ActionBase_Basic>>		TInputActionMap;
typedef map<typename,ref ActionInput>					TTypeNameActionInputMap;
#endif
class ActionManagerClient: ActionManagerBase 
{
	
	//Last send AcknowledgmentID (client can send more requests before recive ackfor first action)
	protected int 								m_LastAcknowledgmentID;
	protected bool								m_ActionPossible;
	protected ref array<ref InventoryLocation>	m_ReservedInventoryLocations;
	protected ref InventoryActionHandler		m_InventoryActionHandler;
	protected ref InventoryLocation				m_HandInventoryLocationTest;
#ifndef OLD_ACTIONS	
	protected static ref TTypeNameActionInputMap		m_RegistredInputsMap;

	//protected bool								m_ActionWantEnd;		//If set action try end // send request to server to end
	protected bool 								m_ActionWantEndRequest_Send;		//Request to server was sended
	protected bool								m_ActionInputWantEnd_Send;	
#endif
	void ActionManagerClient(PlayerBase player) 
	{
		//ActionManagerBase(player);
		m_HandInventoryLocationTest = new InventoryLocation;
		m_HandInventoryLocationTest.SetHands(player,null);
		m_LastAcknowledgmentID = 1;
		m_Targets	= new ActionTargets(player);
		m_ReservedInventoryLocations = new array<ref InventoryLocation>;
		m_InventoryActionHandler = new InventoryActionHandler(player);
		EnableActions();
#ifndef OLD_ACTIONS	
		m_ActionWantEndRequest_Send = false;
		m_ActionInputWantEnd_Send = false;
		RegisterInputs();
#endif
	}
	
	override void Update(int pCurrentCommandID)
	{
		m_InventoryActionHandler.OnUpdate();
		super.Update(pCurrentCommandID);
		m_ActionPossible = ActionPossibilityCheck(pCurrentCommandID);
		if (m_CurrentActionData)
		{
			switch (m_CurrentActionData.m_State)
			{
				case UA_AM_PENDING:
					break;
			
				case UA_AM_ACCEPTED:
					// check pCurrentCommandID before start or reject 
					if( m_ActionPossible && pCurrentCommandID != DayZPlayerConstants.COMMANDID_SWIM && pCurrentCommandID != DayZPlayerConstants.COMMANDID_LADDER )
					{
						if(!m_Player.IsRestrained() || m_CurrentActionData.m_Action.CanBeUsedInRestrain() )
						{
							m_CurrentActionData.m_State = UA_START;
							m_CurrentActionData.m_Action.Start(m_CurrentActionData);
							if( m_CurrentActionData.m_Action.IsInstant() )
								OnActionEnd();
						}
						else
						{
							OnActionEnd();
						}
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
#ifndef OLD_ACTIONS
					if ( m_ActionWantEndRequest )
					{
						if ( GetGame().IsMultiplayer() && !m_CurrentActionData.m_Action.IsLocal() )
						{
							if ( !m_ActionWantEndRequest_Send )
							{
								if (ScriptInputUserData.CanStoreInputUserData())
								{
									Debug.Log("Action=" + m_CurrentActionData.m_Action.Type() + " ended, STS=" + m_Player.GetSimulationTimeStamp());
									ScriptInputUserData ctx = new ScriptInputUserData;
									ctx.Write(INPUT_UDT_STANDARD_ACTION_END_REQUEST);
									ctx.Send();
									m_ActionWantEndRequest_Send = true;
									
									m_ActionWantEndRequest = false;
									m_CurrentActionData.m_Action.OnEndRequest(m_CurrentActionData);
								}
							}
						}
						else
						{
							m_ActionWantEndRequest = false;
							m_CurrentActionData.m_Action.OnEndRequest(m_CurrentActionData);
						}
					}
					
					if ( m_ActionInputWantEnd )
					{
						if ( GetGame().IsMultiplayer() && !m_CurrentActionData.m_Action.IsLocal() )
						{
							if ( !m_ActionInputWantEnd_Send )
							{
								if (ScriptInputUserData.CanStoreInputUserData())
								{
									Debug.Log("Action=" + m_CurrentActionData.m_Action.Type() + " input ended, STS=" + m_Player.GetSimulationTimeStamp());
									ScriptInputUserData ctxi = new ScriptInputUserData;
									ctxi.Write(INPUT_UDT_STANDARD_ACTION_INPUT_END);
									ctxi.Send();
								
									m_ActionInputWantEnd_Send = true;
									
									m_ActionInputWantEnd = false;
									m_CurrentActionData.m_Action.OnEndInput(m_CurrentActionData);
								}
							}
						}
						else
						{
							m_ActionInputWantEnd = false;
							m_CurrentActionData.m_Action.OnEndInput(m_CurrentActionData);
						}
					}
#endif
				break;
			}
		}
#ifdef DEVELOPER
			if( DeveloperFreeCamera.IsFreeCameraEnabled() )
			{
				m_ActionPossible = false;
				RemoveSingleUseAction();
				RemoveContinuousAction();
				m_SelectableActions.Clear();
				m_SelectedActionIndex = 0;
			}
			else
			{
#endif
		if(!m_CurrentActionData)
		{
			m_Targets.Update();
			FindContextualUserActions( pCurrentCommandID );	
		}
#ifndef OLD_ACTIONS
		InputsUpdate();
#endif
#ifdef DEVELOPER
			}
#endif

	}
#ifndef OLD_ACTIONS	
	void RegisterInputs()
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
				m_RegistredInputsMap.GetElement(j).Init(this);
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
		if(m_CurrentActionData)
		{
			if(!m_ActionInputWantEnd)
			{
				ActionInput ai = m_CurrentActionData.m_Action.GetInput();
				ai.Update();
				if(m_Player.IsQBControl())
				{
					if( ai.JustActivate() )
						m_Player.SetActionEndInput(m_CurrentActionData.m_Action);
				}
				else
				{
					if( ai.WasEnded() )
					{
						if( ai.GetInputType() == ActionInputType.AIT_CONTINUOUS || ai.GetInputType() == ActionInputType.AIT_CLICKCONTINUOUS )
						{
							EndActionInput();
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < m_RegistredInputsMap.Count();i++)
			{
				ActionInput ain = m_RegistredInputsMap.GetElement(i);
				ain.Update();
				
				if( ain.JustActivate() && ain.HasAction() )
				{
					ActionStart(ain.GetAction(), ain.GetUsedActionTarget(), ain.GetUsedMainItem());
					break;
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
#endif	
	//--------------------------------------------------------
	// Controls avaliability of contextual actions
	//--------------------------------------------------------
/*	void EnableContinuousAction()
	{
		m_PrimaryActionEnabled = true;	
	}
*/	
	override void DisableContinuousAction()
	{
		RemoveContinuousAction();
		m_PrimaryActionEnabled = false;
	}
	
/*	void EnableSingleUseAction()
	{
		m_SecondaryActionEnabled = true;
	}
*/	
	override void DisableSingleUseAction()
	{
		RemoveSingleUseAction();
		m_SecondaryActionEnabled = false;
	}
/*	
	void EnableInteractAction()
	{
		m_TertiaryActionEnabled = true;
	}
*/
	/*override void DisableInteractAction()
	{
		m_TertiaryActionEnabled = false;
	}*/
	
/*	void EnableActions()
	{
		EnableContinuousAction();
		EnableSingleUseAction();
		EnableInteractAction();
	}
	
	void DisableActions()
	{
		DisableContinuousAction();
		DisableSingleUsesAction();
		DisableInteractAction();
	}
*/	
	
/*	override bool ActionPossibilityCheck(int pCurrentCommandID)
	{
		if ( super.ActionPossibilityCheck(pCurrentCommandID) )
		{
			m_HandInventoryLocationTest.SetHands(m_Player,m_Player.GetItemInHands());
			if (!m_Player.GetHumanInventory().HasInventoryReservation(m_Player.GetItemInHands(),m_HandInventoryLocationTest))
				return true;
		}
		
		return false;
	}*/
	//--------------------------------------------------------
	// Alows to set different action to current contextual one //jtomasik - pri injectu budu muset serveru poslat ID injectnute akce
	//--------------------------------------------------------
#ifdef OLD_ACTIONS
	void InjectContinuousAction( int actionid, ActionTarget target, ItemBase item )
	{
		//DisableContinuousAction();
		
		//ActionBase action = GetAction(actionid);
		SetContinuousAction(GetAction(actionid),target,item);
		//DeliverInjectedAction(1,action_id,action_target,action_item);
	}
	
	void EjectContinuousAction()
	{
		RemoveContinuousAction();
		EnableContinuousAction();
		//DeliverEjectAction(1);
	}
	
	void InjectSingleUseAction( int actionid, ActionTarget target, ItemBase item )
	{
		//DisableSingleUseAction();
		SetSingleUseAction(GetAction(actionid),target,item);
		
		
		//DeliverInjectedAction(2,action_id,action_target,action_item);
	}
	
	void EjectSingleUseAction()
	{
		RemoveSingleUseAction();
		EnableSingleUseAction();
		//DeliverEjectAction(2);
	}
			
	void EjectActions()
	{
		EjectContinuousAction();
		EjectSingleUseAction();
		//DeliverEjectAction(4);
	}
#else	
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
	
#endif	
	void ForceTarget(Object targetObject)
	{
		m_ForceTarget = new ActionTarget(targetObject, null, -1, vector.Zero, -1);
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
		RemoveActions();
#ifdef OLD_ACTIONS
		if (m_Player.IsRaised() || !ActionPossibilityCheck(pCurrentCommandID) || HasHandInventoryReservation() || GetGame().IsInventoryOpen() )
		{
			m_SelectableActions.Clear();
			return;
		}
#else
		if (!ActionPossibilityCheck(pCurrentCommandID) || HasHandInventoryReservation() || GetGame().IsInventoryOpen())
		{
			//add clearing for actions maybe
			return;
		}
#endif	
		
		if ( (m_PrimaryActionEnabled || m_SecondaryActionEnabled || m_TertiaryActionEnabled ) && !GetRunningAction() )
		{	
			ActionBase action;
			ActionTarget 	target;
			ItemBase 		item;

			// Gathering current inputs
			
			item = FindActionItem();
			target = FindActionTarget();
			
#ifndef OLD_ACTIONS	
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
#else		
			//When player swim there is only enter ladder action
			if ( pCurrentCommandID == DayZPlayerConstants.COMMANDID_SWIM )
			{
				m_SelectableActions.Clear();
				m_SelectedActionIndex = 0;

				action = GetAction(AT_ENTER_LADDER);

				if ( action && action.Can(m_Player, target, NULL) )
				{
					m_SelectableActions.Insert(new TSelectableActionInfo(SAT_INTERACT_ACTION, action.GetType(), action.GetText()));
				}
				return;
			}
			
			if ( pCurrentCommandID == DayZPlayerConstants.COMMANDID_LADDER )
			{
				m_SelectableActions.Clear();
				m_SelectedActionIndex = 0;
				action = GetAction(AT_EXIT_LADDER);

				if ( action && action.Can(m_Player, target, NULL) )
				{
					m_SelectableActions.Insert(new TSelectableActionInfo(SAT_INTERACT_ACTION, action.GetType(), action.GetText()));
				}
				return;
			}
			
			ItemBase target_item;
			Class.CastTo(target_item,  target.GetObject() );
			
			m_Player.GetCraftingManager().OnUpdate(item,target_item);

			//Looking for suitable user actions with given inputs
			if ( m_PrimaryActionEnabled ) 
			{
				SetContinuousAction(FindContextualContinuousAction(target,item),target,item);
			}
			if ( m_SecondaryActionEnabled ) 
			{
				SetSingleUseAction(FindContextualSingleUseAction(target,item),target,item);
			}
			if ( m_TertiaryActionEnabled ) 
			{
				FindSelectableActions(target);
			}

		}
		else
		{
			m_SelectableActions.Clear();
		}
#endif
	}
	
#ifdef OLD_ACTIONS	
	protected ActionBase FindContextualContinuousAction(ActionTarget target, ItemBase item)
	{
		ref TIntArray primary_action_ids = new TIntArray;
		ActionBase picked_action;
		
		primary_action_ids.Insert(AT_WORLD_CRAFT);
		if ( item )
		{
			item.GetContinuousActions(primary_action_ids);
		}
		
		// Adding default continuous actions of player
		if ( m_Player ) 
		{
			m_Player.GetContinuousActions(primary_action_ids);
		}

		// Adding actions of item

		// Looking for first possible continuous action 
		if ( primary_action_ids && primary_action_ids.Count() > 0  )
		{
			for ( int i = 0; i < primary_action_ids.Count(); i++ )
			{
				picked_action = GetAction(primary_action_ids.Get(i));
				if ( picked_action && picked_action.Can(m_Player,target, item) )
				{
					return picked_action;
				}
			}
		}
		return NULL;
	}
		
	protected ActionBase FindContextualSingleUseAction(ActionTarget target, ItemBase item)
	{
		ref TIntArray secondary_action_ids = new TIntArray;
		ActionBase picked_action;
		secondary_action_ids.Insert(AT_WORLD_CRAFT_SWITCH);
		// Adding actions of item
		if ( item )
		{
			item.GetSingleUseActions(secondary_action_ids);
		}
		// Adding default single use actions of player
		if ( m_Player ) 
		{
			m_Player.GetSingleUseActions(secondary_action_ids);
		}
		
		// Looking for first possible single use action 
		if ( secondary_action_ids  && secondary_action_ids.Count() > 0 )
		{
			for ( int i = 0; i < secondary_action_ids.Count(); i++ )
			{
				picked_action = GetAction(secondary_action_ids.Get(i));
				if ( picked_action && picked_action.Can(m_Player, target, item) ) 
				{
					return picked_action;
				}
			}
		}
		return NULL;
	}
	
	protected void GetContextualInteractActions(out TSelectableActionInfoArray outarray, ActionTarget target)
	{
		Object targetObject;
		Object targetParent;

		if( target )
		{
			targetObject = target.GetObject();
			targetParent = target.GetParent();
		}
		ref TIntArray tertiary_action_ids = new TIntArray;
		ActionBase picked_action; 
		
		if (targetParent)
		{
			targetParent.GetInteractActions(tertiary_action_ids);
		}

		// Adding interact actions of items in the world
		if ( targetObject )
		{
			targetObject.GetInteractActions(tertiary_action_ids);
		}
		
		// Adding default interact actions of player
		if ( m_Player ) 
		{
			m_Player.GetInteractActions(tertiary_action_ids);	
		}

		// Looking for first possible interact action 
		if ( tertiary_action_ids && tertiary_action_ids.Count() > 0 )
		{
			for ( int i = 0; i < tertiary_action_ids.Count(); i++ )
			{
				picked_action = GetAction(tertiary_action_ids.Get(i));
				if ( picked_action && picked_action.Can(m_Player, target, NULL) )
				{
					outarray.Insert(new TSelectableActionInfo(SAT_INTERACT_ACTION, tertiary_action_ids.Get(i), picked_action.GetText()));
				}
			}
		}
	}
	
	void FindSelectableActions(ActionTarget target)
	{
		ref TSelectableActionInfoArray newSelectableActions = new TSelectableActionInfoArray;

			// add contextual user actions
			GetContextualInteractActions(newSelectableActions, target);
			// add rest
			ItemBase targetItem;
			if( Class.CastTo(targetItem, target.GetObject()) )
			{
				//targetItem.GetRecipesActions(m_Player, newSelectableActions); //jtomasik - now are those actions peformed through user action actionworldcraft.c
				if ( ItemBase.GetDebugActionsMask() & DebugActionType.GENERIC_ACTIONS )
				{	
					targetItem.GetDebugActions(newSelectableActions);
				}		
				if( ItemBase.GetDebugActionsMask() & DebugActionType.PLAYER_AGENTS )
				{
					m_Player.GetDebugActions(newSelectableActions);
				}
			}
		// was there any change?
		m_SelectableActionsHasChanged = !newSelectableActions.IsSameAs(m_SelectableActions);
		if( m_SelectableActionsHasChanged )
		{
			m_SelectableActions = newSelectableActions;
			m_SelectedActionIndex = 0;
		}
	}
	
	int GetContinuousActionForTargetItem(ItemBase item)
	{
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(item, null, -1, vector.Zero, -1);
		
		if( itemInHand )
		{
			ref TIntArray primary_action_ids = new TIntArray;
			ActionBase picked_action;
			itemInHand.GetContinuousActions(primary_action_ids);			
			
			if ( primary_action_ids && primary_action_ids.Count() > 0  )
			{
				for ( int i = 0; i < primary_action_ids.Count(); i++ )
				{
					picked_action = GetAction(primary_action_ids.Get(i));
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) )
					{
						return picked_action.GetType();
					}
				}
			}
		}		
		
		return -1;
	}
#endif
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
#ifndef OLD_ACTIONS
			m_ActionWantEndRequest_Send = false;
			m_ActionInputWantEnd_Send = false;
			m_ActionWantEndRequest = false;
			m_ActionInputWantEnd = false;
			
			if ( action.CanBePerformedFromQuickbar() )
				m_Player.SetActionEndInput(action);
			
			HandleInputsOnActionStart(action);
#endif
			Debug.Log("Action=" + action.Type() + " started, STS=" + m_Player.GetSimulationTimeStamp());
			m_Interrupted = false;
			if ( GetGame().IsMultiplayer() && !action.IsLocal() )
			{
				if (!ScriptInputUserData.CanStoreInputUserData())
				{
					Error("ScriptInputUserData already posted - ActionManagerClient");
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
#ifdef OLD_ACTIONS
			if ( action.CanBePerformedFromQuickbar() )
				m_Player.SetActionEndInput();
#endif
			
			if ( GetGame().IsMultiplayer() && !action.IsLocal() )
			{
				ScriptInputUserData ctx = new ScriptInputUserData;
				ctx.Write(INPUT_UDT_STANDARD_ACTION_START);
#ifdef OLD_ACTIONS
				ctx.Write(action.GetType());
#else
				ctx.Write(action.GetID());
#endif
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
#ifndef OLD_ACTIONS
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
		for (int i = 0; i < m_RegistredInputsMap.Count();i++)
		{
			ActionInput ain = m_RegistredInputsMap.GetElement(i);
			ain.Reset();
		}
	}
#endif	
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
	
	//---------------------------------
	// EVENTS
	//---------------------------------
	override void OnContinuousStart()
	{
#ifdef OLD_ACTIONS
		if (!m_PrimaryActionEnabled || !m_ActionPossible || m_CurrentActionData )
			return;
								
		ActionStart(m_PrimaryAction, m_PrimaryActionTarget, m_PrimaryActionItem);
#endif
	}
	
	override void OnContinuousCancel()
	{
#ifdef OLD_ACTIONS
		if (!m_CurrentActionData || m_CurrentActionData.m_Action.GetActionCategory()!= AC_CONTINUOUS )
			return;
		
		if( m_CurrentActionData.m_State == UA_AM_PENDING || m_CurrentActionData.m_State == UA_AM_REJECTED || m_CurrentActionData.m_State == UA_AM_ACCEPTED )
		{
			OnActionEnd();
			m_PendingActionAcknowledgmentID = -1;
		}
		else
		{
			m_CurrentActionData.m_Action.OnContinuousCancel(m_CurrentActionData);
		}
#endif
	}
		
	// Single----------------------------------------------------
	override void OnSingleUse()
	{
#ifdef OLD_ACTIONS
		if (!m_SecondaryActionEnabled || !m_ActionPossible || m_CurrentActionData)
			return;
		
		ActionStart(m_SecondaryAction, m_SecondaryActionTarget, m_SecondaryActionItem);
#endif
	}
	
	// Interact----------------------------------------------------
	override void OnInteractAction() //Interact
	{
#ifdef OLD_ACTIONS
		if(!m_TertiaryActionEnabled || !m_ActionPossible || m_CurrentActionData)
			return;
		
		if ( m_SelectableActions.Count() > 0 )
		{
			int action_type = m_SelectableActions.Get(m_SelectedActionIndex).param1;
			switch ( action_type )
			{
				case SAT_INTERACT_ACTION :
					ActionBase action = GetAction(m_SelectableActions.Get(m_SelectedActionIndex).param2);
					ActionTarget target = NULL;
					if (action.HasTarget())
						target = FindActionTarget();
				
					ActionStart(action, target, NULL);
					break;
					
				case SAT_DEBUG_ACTION :
					int action_id = m_SelectableActions.Get(m_SelectedActionIndex).param2;
					Object item = FindActionTarget().GetObject();
					if ( item.IsItemBase() )
					{
						ItemBase action_item;
						Class.CastTo(action_item, item);
						OnInstantAction(AT_DEBUG,new Param2<ItemBase,int>(action_item,action_id)); 
					}
					break;
				default :
					Print("WRONG SELECTABLE ACTION TYPE!");
					break;
			}
		}
#endif
	}
	
	
	//Instant Action (Debug Actions) ---------------------------------
	override void OnInstantAction(int user_action_id, Param data = NULL)
	{
		ActionStart(GetAction(user_action_id),NULL,NULL, data);
	}
#ifdef BOT
	/// used for bots
	void PerformAction(int user_action_id, ActionTarget target, ItemBase item, Param extraData = NULL)
	{
		ActionStart(GetAction(user_action_id), target, item, extraData);
	}
#endif
	
	override void OnActionEnd()
	{
		if(m_CurrentActionData)
		{
			UnlockInventory(m_CurrentActionData);
			if( m_CurrentActionData.m_Action.RemoveForceTargetAfterUse() )
				m_InventoryActionHandler.DeactiveAction();
			
			super.OnActionEnd();
#ifndef OLD_ACTIONS
			HandleInputsOnActionEnd();
#endif
		}
	}
#ifdef OLD_ACTIONS
	void SetInventoryAction(int type, int ActionID, ItemBase action_target_item)
	{
		m_InventoryActionHandler.SetAction(type, ActionID, action_target_item);
	}
	
	void UnsetInventoryAction()
	{
		m_InventoryActionHandler.DeactiveAction();
	}
#else
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
#endif


#ifndef OLD_ACTIONS
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
#endif

	bool CanPerformActionFromQuickbar(ItemBase mainItem, ItemBase targetItem)
	{	
#ifdef OLD_ACTIONS	
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			ref TIntArray action_ids = new TIntArray;
			ActionBase picked_action;
			
			//First check continuous actions
			mainItem.GetContinuousActions(action_ids);
			for ( int i = 0; i < action_ids.Count(); i++ )
			{
				picked_action = GetAction(action_ids.Get(i));
				if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
				{
					if( hasTarget == picked_action.HasTarget())
						return true;
				}
			}
			//second single use actions
			mainItem.GetSingleUseActions(action_ids);
			for ( int j = 0; j < action_ids.Count(); j++ )
			{
				picked_action = GetAction(action_ids.Get(j));
				if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
				{
					if( hasTarget == picked_action.HasTarget())
						return true;
				}
			}
		}
#else
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			array<ActionBase_Basic> actions;
			ActionBase picked_action;
			
			//First check continuous actions
			mainItem.GetActions(ContinuousDefaultActionInput, actions);
			if (actions)
			{
				for ( int i = 0; i < actions.Count(); i++ )
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
				for ( int j = 0; j < actions.Count(); j++ )
				{
					picked_action = ActionBase.Cast(actions[j]);
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
					{
						if( hasTarget == picked_action.HasTarget())
							return true;
					}
				}
			}
		}
#endif	
		return false;
	}
	
	void PerformActionFromQuickbar(ItemBase mainItem, ItemBase targetItem)
	{
#ifdef OLD_ACTIONS
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			ref TIntArray action_ids = new TIntArray;
			ActionBase picked_action;
			
			//First continuous actions
			mainItem.GetContinuousActions(action_ids);
			for ( int i = 0; i < action_ids.Count(); i++ )
			{
				picked_action = GetAction(action_ids.Get(i));
				if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
				{
					if( hasTarget == picked_action.HasTarget())
					{
						ActionStart(picked_action, target, mainItem);
						return;
					}
				}
			}
			//Second check single use actions
			mainItem.GetSingleUseActions(action_ids);
			for ( int j = 0; j < action_ids.Count(); j++ )
			{
				picked_action = GetAction(action_ids.Get(j));
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
#else
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			ActionBase picked_action;
			array<ActionBase_Basic> actions;
			
			//First continuous actions
			mainItem.GetActions(ContinuousDefaultActionInput, actions);
			if (actions)
			{
				for ( int i = 0; i < actions.Count(); i++ )
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
				for ( int j = 0; j < actions.Count(); j++ )
				{
					picked_action = ActionBase.Cast(actions[j]);
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
#endif
	}
	
	bool CanPerformActionFromInventory(ItemBase mainItem, ItemBase targetItem)
	{	
#ifdef OLD_ACTIONS
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			ref TIntArray action_ids = new TIntArray;
			ActionBase picked_action;
			
			//First check single use actions
			mainItem.GetSingleUseActions(action_ids);
			for ( int i = 0; i < action_ids.Count(); i++ )
			{
				picked_action = GetAction(action_ids.Get(i));
				if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromInventory() )
				{
					if( hasTarget == picked_action.HasTarget())
					return true;
				}
			}
				//second continuous actions - performing continuous action from inventory not supported yet
				/*mainItem.GetContinuousActions(action_ids);
				for ( int i = 0; i < action_ids.Count(); i++ )
				{
					picked_action = GetAction(action_ids.Get(i));
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromInventory() )
					{
						return true;
					}
				}*/
		}
#else
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
					if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
					{
						if( hasTarget == picked_action.HasTarget())
							return true;
					}
				}
			}
			//second continuous actions
			/*mainItem.GetActions(ContinuousDefaultActionInput, actions);
			if (actions)
			{
				for ( int j = 0; j < actions.Count(); j++ )
				{
					picked_action = ActionBase.Cast(actions[j]);
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
					{
						if( hasTarget == picked_action.HasTarget())
							return true;
					}
				}
			}*/
		}
#endif	
		return false;
	}
	
	void PerformActionFromInventory(ItemBase mainItem, ItemBase targetItem)
	{
#ifdef OLD_ACTIONS
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			ref TIntArray action_ids = new TIntArray;
			ActionBase picked_action;
			
			//First check single use actions
			mainItem.GetSingleUseActions(action_ids);
			for ( int i = 0; i < action_ids.Count(); i++ )
			{
				picked_action = GetAction(action_ids.Get(i));
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
#else
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
#endif
	}
	
	bool CanSetActionFromInventory(ItemBase mainItem, ItemBase targetItem)
	{
#ifdef OLD_ACTIONS
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			ref TIntArray action_ids = new TIntArray;
			ActionBase picked_action;
			
			//First check single use actions
			mainItem.GetSingleUseActions(action_ids);
			for ( int i = 0; i < action_ids.Count(); i++ )
			{
				picked_action = GetAction(action_ids.Get(i));
				if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBeSetFromInventory() )
				{
					if( hasTarget == picked_action.HasTarget())
						return true;
				}
			}
			//second continuous actions
			mainItem.GetContinuousActions(action_ids);
			for ( int j = 0; j < action_ids.Count(); j++ )
			{
				picked_action = GetAction(action_ids.Get(j));
				if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBeSetFromInventory() )
				{
					if( hasTarget == picked_action.HasTarget())
						return true;
				}
			}
		}
#else
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
					if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
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
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
					{
						if( hasTarget == picked_action.HasTarget())
							return true;
					}
				}
			}
		}
#endif	
		return false;
	}
	
	void SetActionFromInventory(ItemBase mainItem, ItemBase targetItem)
	{
#ifdef OLD_ACTIONS
		ItemBase itemInHand = m_Player.GetItemInHands();
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		if( mainItem )
		{
			ref TIntArray action_ids = new TIntArray;
			ActionBase picked_action;
			
			//First continuous actions
			mainItem.GetContinuousActions(action_ids);
			for ( int i = 0; i < action_ids.Count(); i++ )
			{
				picked_action = GetAction(action_ids.Get(i));
				if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBeSetFromInventory() )
				{
					if( hasTarget == picked_action.HasTarget())
					{
						SetInventoryAction(InventoryActionHandler.IAH_CONTINUOUS, action_ids.Get(i), targetItem);
						return;
					}
				}
			}
			//Second check single use actions
			mainItem.GetSingleUseActions(action_ids);
			for ( int j = 0; j < action_ids.Count(); j++ )
			{
				picked_action = GetAction(action_ids.Get(j));
				if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBeSetFromInventory() )
				{
					if( hasTarget == picked_action.HasTarget())
					{
						SetInventoryAction(InventoryActionHandler.IAH_SINGLE_USE, action_ids.Get(j), targetItem);
						return;
					}
				}
			}

		}
#else
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
					if ( picked_action && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
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
					if ( picked_action && picked_action.HasTarget() && picked_action.Can(m_Player,target, itemInHand) && picked_action.CanBePerformedFromQuickbar() )
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
	
	
	
#endif	
	}
	
	void ActionDropItemStart(ItemBase itemInHand, ItemBase targetItem)
	{
#ifdef OLD_ACTIONS
		ActionTarget target;
		target = new ActionTarget(targetItem, null, -1, vector.Zero, -1);
		bool hasTarget = targetItem != NULL;
		
		ActionBase picked_action;
		
		picked_action = GetAction(AT_DROP_ITEM);
		if ( picked_action && picked_action.Can(m_Player,target,itemInHand) )
		{
			if( hasTarget == picked_action.HasTarget())
			{
				ActionStart(picked_action, target, itemInHand);
				return;
			}
		}
#endif
	}
	
	override void Interrupt()
	{
		if(m_CurrentActionData)
			m_Interrupted = true;
	}
	
	private ref ActionTarget m_ForceTarget;
	private ref ActionTargets m_Targets;
};
