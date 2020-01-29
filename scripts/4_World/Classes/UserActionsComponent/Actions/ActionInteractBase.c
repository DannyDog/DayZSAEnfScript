class ActionInteractBaseCB : ActionBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAInteract;
	}

	override void OnAnimationEvent(int pEventID)	
	{	
#ifdef DEVELOPER
		Print("ActionInteractBase.c | OnAnimationEvent | OnAnimationEvent called");
#endif
		if ( !m_Interrupted && pEventID == UA_ANIM_EVENT ) 
		{
			AnimatedActionBase action = AnimatedActionBase.Cast(m_ActionData.m_Action);
			action.OnAnimationEvent(m_ActionData);
		}	
	}
	
	override void InitActionComponent()
	{
#ifdef DEVELOPER
		Print("ActionInteractBase.c | InitActionComponent | inited");
#endif
		m_Interrupted = false;
		m_Canceled = false;

		CreateActionComponent();
		if ( m_ActionData.m_ActionComponent ) 
		{
			m_ActionData.m_ActionComponent.Init(m_ActionData);
		}
		m_ActionData.m_State = UA_PROCESSING;
		RegisterAnimationEvent("ActionExec", UA_ANIM_EVENT);
		m_SoundObject = m_ActionData.m_Action.PlayActionSound(m_ActionData.m_Player);
	}	
	
	override void EndActionComponent()
	{
		SetCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
		m_ActionData.m_State = UA_FINISHED;
	}	
};



class ActionInteractBase : AnimatedActionBase
{
	string m_HUDCursorIcon;
	
	void ActionInteractBase() 
	{
		m_CallbackClass = ActionInteractBaseCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_HUDCursorIcon = CursorIcons.Cursor;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}
	
	string GetHUDCursorIcon()
	{
		return m_HUDCursorIcon;
	}
	
	override typename GetInputType()
	{
		return InteractActionInput;
	}

	override int GetActionCategory()
	{
		return AC_INTERACT;
	}
	
	override bool UseMainItem()
	{
		return false;
	}
	
	override bool MainItemAlwaysInHands()
	{
		return false;
	}	
};