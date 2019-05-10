class ActionSewTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SEW_CUTS);
	}
};

class ActionSewTarget: ActionContinuousBase
{
	void ActionSewTarget()
	{
		m_CallbackClass = ActionSewTargetCB;
		//m_Animation = "sew";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}

	override int GetType()
	{
		return AT_SEW_T;
	}
		
	override string GetText()
	{
		return "#sew_targets_cuts";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		PlayerBase other_player = PlayerBase.Cast(target.GetObject());
		return other_player.IsBleeding();
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase ntarget = PlayerBase.Cast(action_data.m_Target.GetObject());
		if (ntarget.GetBleedingManagerServer() )
		{
			ntarget.GetBleedingManagerServer().RemoveMostSignificantBleedingSource();
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