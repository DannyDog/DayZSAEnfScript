class ActionSplintTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.APPLY_SPLINT);
	}
};

class ActionSplintTarget: ActionContinuousBase
{
	void ActionSplintTarget()
	{
		m_CallbackClass = ActionSplintTargetCB;
		m_MessageStartFail = "There's no splint left.";
		m_MessageStart = "Player started fixing you.";
		m_MessageSuccess = "Player finished fixing you.";
		m_MessageFail = "Player moved and fixing was canceled.";
		m_MessageCancel = "You stopped fixing.";
		//m_Animation = "splint";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGETARGET;
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
		return AT_SPLINT_T;
	}
		
	override string GetText()
	{
		return "#fix_persons_fracture";
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		action_data.m_MainItem.TransferModifiers(ntarget);
		ntarget.ApplySplint();
		//ntarget.m_NotifiersManager.DeactivateByType(eNotifiers.NTF_FRACTURE);
		action_data.m_MainItem.Delete();

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};