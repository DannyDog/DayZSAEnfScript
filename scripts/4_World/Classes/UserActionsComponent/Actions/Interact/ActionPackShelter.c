class ActionDeconstructShelter : ActionContinuousBase
{
	void ActionDeconstructShelter()
	{
		m_CallbackClass		= ActionPackTentCB;
		m_SpecialtyWeight 	= UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
		m_FullBody			= true;
		m_StanceMask		= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINone;
/*
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTParent(3);
*/
	}
	
	override string GetText()
	{
		return "#pack_tent"; //todo
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
/*
	override bool IsUsingProxies()
	{
		return true;
	}
*/
	override bool HasProgress()
	{
		return true;
	}
	
	override bool HasAlternativeInterrupt()
	{
		return true;
	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{
		return true;
	}
	
	override ActionData CreateActionData()
	{
		PlaceObjectActionData action_data = new PlaceObjectActionData;
		return action_data;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		//Object targetParent = target.GetParent();
		
		if ( player && targetObject )
		{
			ShelterBase shelter = ShelterBase.Cast( targetObject );
			if ( shelter.CanBePacked() )
			{
				return true;
			}
		}
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		//Object targetParent = action_data.m_Target.GetParent();
		ShelterBase shelter = ShelterBase.Cast( targetObject );
		shelter.Deconstruct();
	}
};