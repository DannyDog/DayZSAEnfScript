class ActionBuryAshesCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.BURY_ASHES );
	}
}

class ActionBuryAshes: ActionContinuousBase
{
	void ActionBuryAshes()
	{
		m_CallbackClass = ActionBuryAshesCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}

	override string GetText()
	{
		return "#bury";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Fireplace fireplace_target = Fireplace.Cast( target.GetObject() );
		
		if ( fireplace_target )
		{
			if ( fireplace_target.HasAshes() && !fireplace_target.IsBurning() && fireplace_target.IsEmpty() )
			{
				string surface_type;
				vector position = fireplace_target.GetPosition();
				GetGame().SurfaceGetType ( position[0], position[2], surface_type );
				if ( GetGame().IsSurfaceDigable( surface_type ) )
				{
					return true;
				}
			}
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		//destroy fireplace with ashes
		GetGame().ObjectDelete( action_data.m_Target.GetObject() );

		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 4);
		
		//add soft skill specialty
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( UASoftSkillsWeight.ROUGH_LOW );	
	}
}