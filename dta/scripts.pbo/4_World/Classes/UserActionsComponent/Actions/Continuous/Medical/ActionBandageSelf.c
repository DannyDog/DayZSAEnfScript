class ActionBandageSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.BANDAGE);
	}
};

class ActionBandageSelf: ActionContinuousBase
{	
	void ActionBandageSelf()
	{
		m_CallbackClass = ActionBandageSelfCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGE;
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
		return AT_BANDAGE_S;
	}

	override bool HasTarget()
	{
		return false;
	}
		
	override string GetText()
	{
		return "#treat_wound";
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
		
		if (action_data.m_MainItem.HasQuantity())
		{
			action_data.m_MainItem.AddQuantity(-1,true);
		}
		else
		{
			action_data.m_MainItem.Delete();
		}

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};
