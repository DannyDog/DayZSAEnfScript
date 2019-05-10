class ActionHarvestCrops: ActionInteractBase
{
	void ActionHarvestCrops()
	{
		m_MessageSuccess = "";
		m_MessageStartFail = "";
		m_MessageStart = "";
		m_MessageSuccess = "";
		m_MessageFail = "";
		m_MessageCancel = "";

		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		
		/*m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_FullBody = true;*/
	}

	override int GetType()
	{
		return AT_HARVEST_CROPS;
	}

	override string GetText()
	{
		return "#harvest";
	}

#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
#endif

	override void CreateConditionComponents()  
	{	
		
		m_ConditionTarget = new CCTNone;
		m_ConditionItem = new CCINone;
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