class ActionHarvestCrops: ActionInteractBase
{
	void ActionHarvestCrops()
	{

		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		
		/*m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_FullBody = true;*/
	}

	override string GetText()
	{
		return "#harvest";
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.SMALL);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object targetObject = target.GetObject();
		if ( targetObject.IsInherited(PlantBase) )
		{
			PlantBase plant = PlantBase.Cast( targetObject );
			bool is_mature = plant.IsMature();
			bool is_spoiled = plant.IsSpoiled();
			bool has_crops = plant.HasCrops();
			int plant_state = plant.GetPlantState();
			
			
			if (  ( is_mature  ||  is_spoiled )  &&  has_crops  )
			{
				return true;
			}
		}
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		PlantBase plant = PlantBase.Cast( targetObject );
		plant.Harvest( action_data.m_Player );

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};