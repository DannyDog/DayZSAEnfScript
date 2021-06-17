class ActionDisinfectSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT);
	}
};

class ActionDisinfectBase: ActionContinuousBase
{
	void Apply( ActionData action_data )
	{
		ItemBase item = action_data.m_MainItem;
		item.AddQuantity(-item.GetDisinfectQuantity());
		
	}
}


class ActionDisinfectSelf: ActionDisinfectBase
{
	float m_GramsConsumedPerUse;//left for legacy reasons
	
	void ActionDisinfectSelf()
	{
		m_CallbackClass = ActionDisinfectSelfCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_STITCHUPSELF;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override bool HasTarget()
	{
		return false;
	}
		
	override string GetText()
	{
		return "#disinfect_self";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		return (player.IsBleeding() || (player.m_Agents & eAgents.WOUND_AGENT));
	}
	

	override void OnFinishProgressServer( ActionData action_data )
	{
		
		if( action_data.m_Player.GetModifiersManager().IsModifierActive(eModifiers.MDF_DISINFECTION))//effectively resets the timer
		{
			action_data.m_Player.GetModifiersManager().DeactivateModifier( eModifiers.MDF_DISINFECTION );
		}
		action_data.m_Player.GetModifiersManager().ActivateModifier( eModifiers.MDF_DISINFECTION );

		Apply(action_data);
	}

	
};