class ActionFoldBaseBuildingObjectCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.DEFAULT_DECONSTRUCT );
	}
}

class ActionFoldBaseBuildingObject: ActionContinuousBase
{
	void ActionFoldBaseBuildingObject()
	{
		m_CallbackClass = ActionFoldBaseBuildingObjectCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINotPresent;
	}

	override int GetType()
	{
		return AT_FOLD_BASEBUILDING_OBJECT;
	}
		
	override string GetText()
	{
		return "#fold";
	}

#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
#endif

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		
		if ( targetObject.CanUseConstruction() )
		{
			BaseBuildingBase base_building = BaseBuildingBase.Cast( targetObject );
			
			if ( base_building.CanFoldBaseBuildingObject() )
			{
				return true;
			}
		}
		
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		base_building.FoldBaseBuildingObject();
	}
}