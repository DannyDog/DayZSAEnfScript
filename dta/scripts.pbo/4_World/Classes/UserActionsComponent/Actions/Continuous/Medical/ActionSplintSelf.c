class ActionSplintSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.APPLY_SPLINT);
	}
};

class ActionSplintSelf: ActionContinuousBase	
{
	void ActionSplintSelf()
	{
		m_CallbackClass = ActionSplintSelfCB;
		m_MessageStartFail = "There's no splint left";
		m_MessageStart = "I have started fixing myself";
		m_MessageSuccess = "I have fixed myself.";
		m_MessageFail = "I have moved and fixing was canceled.";
		m_MessageCancel = "I stopped fixing.";
		//m_Animation = "bandage";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override int GetType()
	{
		return AT_SPLINT_S;
	}

	override bool HasTarget()
	{
		return false;
	}
		
	override string GetText()
	{
		return "#apply_splint";
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		action_data.m_MainItem.TransferModifiers(action_data.m_Player);
		action_data.m_Player.ApplySplint();
		//action_data.m_Player.m_NotifiersManager.DeactivateByType(eNotifiers.NTF_FRACTURE);
		action_data.m_MainItem.Delete();

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};