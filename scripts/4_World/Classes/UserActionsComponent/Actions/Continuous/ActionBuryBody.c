class ActionBuryBodyCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.BURY_BODY);
	}
};

class ActionBuryBody: ActionContinuousBase
{	
	void ActionBuryBody()
	{
		m_CallbackClass = ActionBuryBodyCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		
		m_ConditionTarget = new CCTDummy;
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		return "#bury";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI body_EAI;
		Class.CastTo(body_EAI, target.GetObject());
		
		if ( body_EAI  &&  !body_EAI.IsAlive()  &&  (body_EAI.IsInherited(DayZCreature )  ||  body_EAI.IsInherited(Man)) && !body_EAI.GetParent() )
		{
			string surface_type;
			vector position = body_EAI.GetPosition();
			GetGame().SurfaceGetType ( position[0], position[2], surface_type );
			
			if ( GetGame().IsSurfaceDigable(surface_type) )
				return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		Object targetObject = action_data.m_Target.GetObject();
		g_Game.ObjectDelete(targetObject);

		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 4);
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight ); 
	}
};
