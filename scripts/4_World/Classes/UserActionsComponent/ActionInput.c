enum ActionInputType
{
	AIT_CONTINUOUS,				//React to hold input and release after it
	AIT_SINGLE,					//React to click input - single use actions
	AIT_DOUBLECLICK,			//React to double click input - single use actions
	AIT_HOLDSINGLE,				//React to hold input - single use actions
	AIT_CLICKCONTINUOUS,		//React to click input for start and click for end
	AIT_NOINPUTCONTROL,
}

class ForcedActionData
{
	ActionBase m_Action;
	ref ActionTarget m_Target;
	ItemBase m_Item;
}

class ActionInput : ActionInput_Basic
{
	UAIDWrapper m_input;			//Input ID automaticly generated from name.
	int m_InputType;			//Use from action manager for handling input
	bool m_DetectFromTarget;	//Can be used action from target in vicinity?
	bool m_Enabled;
	bool m_JustActivate;
	
	PlayerBase m_Player;
	
	ref ActionTarget m_ForcedTarget;
	
	ref ForcedActionData m_ForcedActionData;
	
	ref ActionTarget m_Target;
	ItemBase m_MainItem;
	int m_ConditionMask;
	
	bool m_Active;
	
	void ActionInput()
	{
		Debug.Log("+ ActionInput() " + this);
		
		m_Active = false;
		m_Enabled = true;
		m_ForcedTarget = null;
		m_ForcedActionData = null;
		
		m_JustActivate = false;
		m_DetectFromTarget = false;
	}
	
	void Init(PlayerBase player, ActionManagerClient am)
	{
		m_Player = player;
	}
	
	void SetEnablity(bool value)
	{
		m_Enabled = value;
	}
	
	protected void SetInput(string input_name)
	{
		m_input = GetUApi().GetInputByName(input_name).GetPersistentWrapper();
		if(m_input && m_input.InputP())
			Debug.Log("+ input: " + input_name);
		else
			Debug.Log("- input: " + input_name);
	}
	
	int GetInputType()
	{
		return m_InputType;
	}
	
	UAInput GetUAInput()
	{
		return m_input.InputP();
	}
	
	bool JustActivate()
	{
		return m_JustActivate;
	}

	bool IsActive()
	{
		return m_Active;
	}
		
	bool WasEnded()
	{
		return !m_Active;
	}
	
	void Update()
	{
		if(	!m_Enabled )
		{
			m_Active = false;
			m_JustActivate = false;
			return;
		}
		
		switch ( m_InputType )
		{
			case ActionInputType.AIT_CONTINUOUS:
				m_JustActivate = false;
				if(m_Active)
				{
					m_Active = m_input.InputP().LocalHold();
				}
				else
				{
					m_Active = m_input.InputP().LocalHoldBegin();
					m_JustActivate = m_Active;
				}
				break;
			case ActionInputType.AIT_SINGLE:
				m_Active = m_input.InputP().LocalClick();
				m_JustActivate = m_Active;
				break;
			case ActionInputType.AIT_DOUBLECLICK:
				m_Active = m_input.InputP().LocalDoubleClick();
				m_JustActivate = m_Active;
				break;
			break;
			case ActionInputType.AIT_HOLDSINGLE:
				m_Active = m_input.InputP().LocalHoldBegin();
				m_JustActivate = m_Active;
				break;
			break;
			case ActionInputType.AIT_CLICKCONTINUOUS:
				m_JustActivate = false;
				if(m_Active)
				{
					if ( m_input.InputP().LocalClick() )
					{
						m_Active = false;
					}
				}
				else
				{
					m_Active = m_input.InputP().LocalClick();
					m_JustActivate = m_Active;
				}
				break;
			break;
			default:
				break;
		}
	}
	
	void Reset()
	{
		m_Active = false;
		ActionsSelectReset();
	}
	
	void UpdatePossibleActions(PlayerBase player, ActionTarget target, ItemBase item, int action_condition_mask)
	{	
	}
	
	ActionBase GetAction()
	{
		return NULL;
	}
	
	ActionTarget GetUsedActionTarget()
	{
		return m_Target;
	}
	
	ItemBase GetUsedMainItem()
	{
		return m_MainItem;
	}
	
	array<ActionBase> GetPossibleActions()
	{
		return NULL;
	}
	
	ActionBase GetPossibleAction()
	{
		return NULL;
	}
	
	int GetPossibleActionIndex()
	{
		return -1;
	}
	
	void OnActionStart()
	{
		ActionsSelectReset();
	}
	
	void OnActionEnd()
	{
		Reset();
	}
	
	void ActionsSelectReset()
	{}
	
	void ForceAction(ActionBase action, ActionTarget target, ItemBase item )
	{
		m_ForcedActionData = new ForcedActionData;
		m_ForcedActionData.m_Action = action;
		m_ForcedActionData.m_Target = target;
		m_ForcedActionData.m_Item = item;
	}
	
	void ForceActionTarget( ActionTarget target )
	{
		m_ForcedTarget = target;
	}
	
	void ClearForcedAction()
	{
		m_ForcedActionData = null;
	}
	
	void ClearForcedTarget()
	{
		m_ForcedTarget = NULL;
	}
	
	bool ForceActionCheck(PlayerBase player)
	{
		if (m_ForcedActionData)
		{
			if (m_ForcedActionData.m_Action.Can(player, m_ForcedActionData.m_Target, m_ForcedActionData.m_Item))
			{
				m_MainItem = m_ForcedActionData.m_Item;
				m_Target = m_ForcedActionData.m_Target;
				return true;
			}
		}
		return false;
	}
	
	void SelectNextAction()
	{
	}
	
	void SelectPrevAction()
	{}
	
	bool HasInput()
	{
		return m_input != NULL;
	}
}

class ContinuousInteractActionInput : ActionInput
{
	ref array<ActionBase>	m_SelectActions;
	int 					m_selectedActionIndex;
	
	void ContinuousInteractActionInput(PlayerBase player)
	{
		SetInput("UAAction");
		m_InputType = ActionInputType.AIT_CONTINUOUS;
		m_DetectFromTarget = true;
		m_selectedActionIndex = 0;
		m_SelectActions = new array<ActionBase>;
	}
	
	override void ForceAction(ActionBase action, ActionTarget target, ItemBase item )
	{
		super.ForceAction(action, target, item);

		m_selectedActionIndex = 0;
	}
	
	override void UpdatePossibleActions(PlayerBase player, ActionTarget target, ItemBase item, int action_condition_mask)
	{
		if ( ForceActionCheck(player))
		{
			m_SelectActions.Clear();
			m_SelectActions.Insert(m_ForcedActionData.m_Action);
			return;
		}
		
		if(m_ForcedTarget)
		{
			target = m_ForcedTarget;
		}
		array<ActionBase_Basic> possible_actions;
		ActionBase action;
		int i;
		int last_index = 0;
		
		m_MainItem = item;
		m_Target = target;
		m_ConditionMask = action_condition_mask;

		Object target_obj = target.GetObject();
		
		if(target_obj)
			target_obj.GetActions(this.Type(), possible_actions);
		
		if(possible_actions)
		{		
			for (i = 0; i < possible_actions.Count(); i++)
			{
				action = ActionBase.Cast(possible_actions.Get(i));
				if ( action.Can(player, target, item, action_condition_mask) )
				{
					if(m_SelectActions.Count() > last_index )
					{
						if(m_SelectActions[last_index] != action)
						{
							m_selectedActionIndex = 0;
							m_SelectActions[last_index] = action;
						}
					}
					else
					{
						m_selectedActionIndex = 0;
						m_SelectActions.Insert(action);
					}
				
					last_index++;
				}
			}
			possible_actions = null;
		}
		
		target_obj = target.GetParent();
		
		if(target_obj)
			target_obj.GetActions(this.Type(), possible_actions);
		
		if(possible_actions)
		{		
			for (i = 0; i < possible_actions.Count(); i++)
			{
				action = ActionBase.Cast(possible_actions.Get(i));
				if ( action.Can(player, target, item, action_condition_mask) )
				{
					if(m_SelectActions.Count() > last_index )
					{
						if(m_SelectActions[last_index] != action)
						{
							m_selectedActionIndex = 0;
							m_SelectActions[last_index] = action;
						}
					}
					else
					{
						m_selectedActionIndex = 0;
						m_SelectActions.Insert(action);
					}
					last_index++;
				}
			}
			possible_actions = null;
		}
		
		
		
		player.GetActions(this.Type(), possible_actions);
		if(possible_actions)
		{
			for (i = 0; i < possible_actions.Count(); i++)
			{
				action = ActionBase.Cast(possible_actions.Get(i));
				if ( action.Can(player, target, item, action_condition_mask) )
				{
					if(m_SelectActions.Count() > last_index )
					{
						if(m_SelectActions[last_index] != action)
						{
							m_selectedActionIndex = 0;
							m_SelectActions[last_index] = action;
						}
					}
					else
					{
						m_selectedActionIndex = 0;
						m_SelectActions.Insert(action);
					}
					last_index++;
				}
			}
		}
		
		
		if (m_SelectActions.Count() > last_index)
		{
			m_selectedActionIndex = 0;
			for (i = last_index; i < m_SelectActions.Count(); i++)
			{
				m_SelectActions.Remove(last_index);
			}
		}
	}
	
	override array<ActionBase> GetPossibleActions()
	{
		return m_SelectActions;
	}
	
	override int GetPossibleActionIndex()
	{
		return m_selectedActionIndex;
	}
	
	override ActionBase GetAction()
	{
		if (m_SelectActions.Count() > 0)
			return m_SelectActions[m_selectedActionIndex];
		return null;
	}
	
	override void ActionsSelectReset()
	{
		m_SelectActions.Clear();
		m_selectedActionIndex = 0;
	}
	
	override void SelectNextAction()
	{
		if(m_SelectActions.Count())
		{
			m_selectedActionIndex++;
			if(m_SelectActions.Count() <= m_selectedActionIndex )
			{
				m_selectedActionIndex = 0;
			}
		}
	}
	
	override void SelectPrevAction()
	{
		if(m_SelectActions.Count())
		{
			m_selectedActionIndex--;
			if(0 > m_selectedActionIndex )
			{
				m_selectedActionIndex = m_SelectActions.Count() - 1;
			}
		}
	}
};

class InteractActionInput : ContinuousInteractActionInput
{
	void InteractActionInput(PlayerBase player)
	{
		m_InputType = ActionInputType.AIT_SINGLE;
	}
	
	override void OnActionStart()
	{
		super.OnActionStart();
		m_Active = false;
	}
	
	override bool WasEnded()
	{
		return false;
	}
};

class NoIndicationActionInputBase : ActionInput
{
	void NoIndicationActionInputBase(PlayerBase player)
	{
		m_DetectFromTarget = false;
	}
	
	override void UpdatePossibleActions(PlayerBase player, ActionTarget target, ItemBase item, int action_condition_mask)
	{
		m_MainItem = item;
		m_Target = target;
		m_ConditionMask = action_condition_mask;
	}
	
	override ActionBase GetAction()
	{
		if ( ForceActionCheck(m_Player) )
			return m_ForcedActionData.m_Action;
		
		if(m_MainItem)
		{
			array<ActionBase_Basic> possible_actions;
			ActionBase action;
			
			m_MainItem.GetActions(this.Type(), possible_actions);
			if(possible_actions)
			{
				for (int i = 0; i < possible_actions.Count(); i++)
				{
					action = ActionBase.Cast(possible_actions.Get(i));
					if ( action.Can(m_Player, m_Target, m_MainItem, m_ConditionMask) )
					{
						return action;
					}
				}
			}
		
		}
		return NULL;
	}

	override ActionBase GetPossibleAction()
	{
		return GetAction();
	}
}

class ContinuousDefaultActionInput : ActionInput
{
	protected ActionBase m_SelectAction;
	void ContinuousDefaultActionInput(PlayerBase player)
	{
		SetInput("UADefaultAction");
		m_InputType = ActionInputType.AIT_CONTINUOUS;
		m_DetectFromTarget = false;
		m_SelectAction = null;
	}
	
	override void UpdatePossibleActions(PlayerBase player, ActionTarget target, ItemBase item, int action_condition_mask)
	{
		if ( ForceActionCheck(player))
		{
			m_SelectAction = m_ForcedActionData.m_Action;
			return;
		}
		
		if(m_ForcedTarget)
		{
			target = m_ForcedTarget;
		}
		m_SelectAction = NULL;
		array<ActionBase_Basic> possible_actions;
		ActionBase action;
		int i;
		
		m_MainItem = item;
		m_Target = target;
		m_ConditionMask = action_condition_mask;
		
		if(item)
		{
			item.GetActions(this.Type(), possible_actions);
			if(possible_actions)
			{
				for (i = 0; i < possible_actions.Count(); i++)
				{
					action = ActionBase.Cast(possible_actions.Get(i));
					if ( action.Can(player, target, item, action_condition_mask) )
					{
						m_SelectAction = action;
						return;
					}
				}
				possible_actions = null;
			}
		}
		
		player.GetActions(this.Type(), possible_actions);
		if(possible_actions)
		{
			for (i = 0; i < possible_actions.Count(); i++)
			{
				action = ActionBase.Cast(possible_actions.Get(i));
				if ( action.Can(player, target, item, action_condition_mask) )
				{
					m_SelectAction = action;
					return;
				}
			}
		}
	}
	
	override ActionBase GetPossibleAction()
	{
		return m_SelectAction;
	}
	
	override ActionBase GetAction()
	{
		return m_SelectAction;
	}
	
	override void ActionsSelectReset()
	{
		m_SelectAction = NULL;
	}
};

class DefaultActionInput : ContinuousDefaultActionInput
{
	void DefaultActionInput(PlayerBase player)
	{
		m_InputType = ActionInputType.AIT_SINGLE;	
	}
	
	override void OnActionStart()
	{
		super.OnActionStart();
		m_Active = false;
	}
	
	override bool WasEnded()
	{
		return false;
	}
};

class DropActionInput : NoIndicationActionInputBase
{
	void DropActionInput(PlayerBase player)
	{
		SetInput("UADropitem");
		m_InputType = ActionInputType.AIT_HOLDSINGLE;
	}
};

class ToggleLightsActionInput : DefaultActionInput
{
	ref ActionTarget target_new;
	
	void ToggleLightsActionInput(PlayerBase player)
	{
		SetInput("UAToggleHeadlight");
		m_InputType = ActionInputType.AIT_SINGLE;
	}
	
	override void UpdatePossibleActions(PlayerBase player, ActionTarget target, ItemBase item, int action_condition_mask)
	{
		if( ForceActionCheck(player) )
		{
			m_SelectAction = m_ForcedActionData.m_Action;
			return;
		}
		//ForceActionTarget(player.m_PlayerLightManager.
		
		m_SelectAction = NULL;
		array<ActionBase_Basic> possible_actions;
		ActionBase action;
		int i;

		m_MainItem = NULL;
		if ( player && !player.IsInVehicle() ) 
		{
			Clothing headgear = Clothing.Cast(player.FindAttachmentBySlotName("Headgear"));
			if ( headgear )
			{
				//m_MainItem = Headtorch_ColorBase.Cast(player.FindAttachmentBySlotName("Headgear"));
				target_new = new ActionTarget(headgear, null, -1, vector.Zero, -1);
				ForceActionTarget(target_new);
			}
			else
				ClearForcedTarget();
		}
		else if ( player && player.IsInVehicle() )
		{
			HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
			if( vehCommand )
			{
				Transport trans = vehCommand.GetTransport();
				if( trans )
				{
					target_new = new ActionTarget(trans, null, -1, vector.Zero, -1);
					ForceActionTarget(target_new);
				}
			}
			
			if ( !target_new )
				ClearForcedTarget();
		}
		
		target = m_ForcedTarget;
		m_Target = m_ForcedTarget;
		
		if(target && target.GetObject())
		{
			target.GetObject().GetActions(this.Type(), possible_actions);
			if(possible_actions)
			{
				for (i = 0; i < possible_actions.Count(); i++)
				{
					action = ActionBase.Cast(possible_actions.Get(i));
					if ( action.Can(player, target, m_MainItem, action_condition_mask) )
					{
						m_SelectAction = action;
						return;
					}
				}
			}
		}
	}
};

class ToggleNVGActionInput : DefaultActionInput
{
	ref ActionTarget target_new;
	
	void ToggleNVGActionInput(PlayerBase player)
	{
		SetInput("UAToggleNVG");
		m_InputType = ActionInputType.AIT_HOLDSINGLE;
	}
	
	override void UpdatePossibleActions(PlayerBase player, ActionTarget target, ItemBase item, int action_condition_mask)
	{
		if( ForceActionCheck(player) )
		{
			m_SelectAction = m_ForcedActionData.m_Action;
			return;
		}
		//ForceActionTarget(player.m_PlayerLightManager.
		
		m_SelectAction = NULL;
		array<ActionBase_Basic> possible_actions;
		ActionBase action;
		int i;

		m_MainItem = NULL;
		if ( player ) 
		{
			Mich2001Helmet helmet = Mich2001Helmet.Cast(player.FindAttachmentBySlotName("Headgear"));
			NVGHeadstrap headstrap = NVGHeadstrap.Cast(player.FindAttachmentBySlotName("Eyewear"));
			if ( helmet )
			{
				//m_MainItem = Headtorch_ColorBase.Cast(player.FindAttachmentBySlotName("Headgear"));
				target_new = new ActionTarget(helmet, null, -1, vector.Zero, -1);
				ForceActionTarget(target_new);
			}
			else if ( headstrap )
			{
				target_new = new ActionTarget(headstrap, null, -1, vector.Zero, -1);
				ForceActionTarget(target_new);
			}
			else
				ClearForcedTarget();
		}
		
		target = m_ForcedTarget;
		m_Target = m_ForcedTarget;
		
		if(target && target.GetObject())
		{
			target.GetObject().GetActions(this.Type(), possible_actions);
			if(possible_actions)
			{
				for (i = 0; i < possible_actions.Count(); i++)
				{
					action = ActionBase.Cast(possible_actions.Get(i));
					if ( action.Can(player, target, m_MainItem, action_condition_mask) )
					{
						m_SelectAction = action;
						return;
					}
				}
			}
		}
	}
};

class ContinuousWeaponManipulationActionInput : NoIndicationActionInputBase
{
	void ContinuousWeaponManipulationActionInput(PlayerBase player)
	{
		SetInput("UAReloadMagazine");
		m_InputType = ActionInputType.AIT_CONTINUOUS;
	}
};

class WeaponManipulationActionInput : NoIndicationActionInputBase
{	
	void WeaponManipulationActionInput(PlayerBase player)
	{
		SetInput("UAReloadMagazine");
		m_InputType = ActionInputType.AIT_SINGLE;
	}
};

class ExternalControlledActionInput : NoIndicationActionInputBase
{	
	void ExternalControlledActionInput(PlayerBase player)
	{
		//SetInput("UAReloadMagazine");
		m_InputType = ActionInputType.AIT_NOINPUTCONTROL;
	}
};

class QuickaBarActionInput : ExternalControlledActionInput
{	
};


