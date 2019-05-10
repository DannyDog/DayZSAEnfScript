class ActionSewSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SEW_CUTS);
	}
};

class ActionSewSelf: ActionContinuousBase
{
	void ActionSewSelf()
	{
		m_CallbackClass = ActionSewSelfCB;
		m_MessageStartFail = "There's no sewing left.";
		m_MessageStart = "I have started sewing myself";
		m_MessageSuccess = "I have sewed myself.";
		m_MessageFail = "I have moved and sewing was canceled.";
		m_MessageCancel = "I stopped sewing.";
		//m_Animation = "bandage";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_STITCHUPSELF;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override int GetType()
	{
		return AT_SEW_S;
	}

	override bool HasTarget()
	{
		return false;
	}
			
	override string GetText()
	{
		return "#sew_cuts";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		return player.IsBleeding();
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		if (action_data.m_Player.GetBleedingManagerServer() )
		{
			action_data.m_Player.GetBleedingManagerServer().RemoveMostSignificantBleedingSource();	
		}
		
		if (action_data.m_MainItem.GetQuantity() > 0)
		{
			action_data.m_MainItem.AddQuantity(-1,true);
		}

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};