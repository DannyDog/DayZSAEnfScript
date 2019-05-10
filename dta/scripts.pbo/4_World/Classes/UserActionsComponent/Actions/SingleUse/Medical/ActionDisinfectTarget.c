class ActionDisinfectTargetCB : ActionSingleUseBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CASingleUseQuantity(UAQuantityConsumed.DISINFECT);
	}

	/*bool CancelCondition()
	{
		if ( !m_Interrupted && (GetState() == STATE_LOOP_LOOP || GetState() == STATE_LOOP_LOOP2) )
		{	
			AnimatedActionBase action = AnimatedActionBase.Cast(m_ActionData.m_Action);
			action.Do(m_ActionData,m_ActionData.m_State);
		}
		return DefaultCancelCondition(); 
	}*/
	/*override void InitActionComponent()
	{
		super.InitActionComponent();
		EnableCancelCondition(true);
	}*/
};


class ActionDisinfectTarget: ActionSingleUseBase
{	
	void ActionDisinfectTarget()
	{
		m_CallbackClass = ActionDisinfectTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CLEANWOUNDSTARGET;
		m_StanceMask = DayZPlayerConstants.STANCEIDX_ERECT | DayZPlayerConstants.STANCEIDX_CROUCH;
		m_FullBody = true;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}

	override int GetType()
	{
		return AT_DISINFECT_T;
	}
		
	override string GetText()
	{
		return "#disinfect_person";
	}

	override void OnEndServer( ActionData action_data )
	{
		//Print(action_data.m_Player.GetSoftSkillManager());
		//RemoveModifiers(target, item); ?

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		if ( action_data.m_MainItem && action_data.m_MainItem.GetQuantity() <= 0 ) 
		{
			action_data.m_MainItem.SetQuantity(0);
		}
	}
};