class ActionTakeMaterialToHandsSwitch: ActionSingleUseBase
{
	void ActionTakeMaterialToHandsSwitch()
	{
	}
	
	override void CreateConditionComponents()  
	{		
		m_ConditionItem = new CCINotPresent;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}
	
	override int GetType()
	{
		return AT_TAKE_MATERIAL_TO_HANDS_SWITCH;
	}
	
	override string GetText()
	{
		return "#switch_to_next_material";
	}

#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return InteractActionInput;
	}
#endif
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		if ( target_entity && target_entity.CanUseConstruction() )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			
			string main_part_name = target_entity.GetActionComponentName( target.GetComponentIndex() );
			construction_action_data.RefreshAttachmentsToDetach( target_entity, main_part_name );
			
			if ( construction_action_data.GetAttachmentsToDetachCount() > 1 )
			{
				return true;
			}
		}
		
		return false;
	}
	
	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		
		//set next index
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		construction_action_data.SetNextAttachmentIndex();
	}	
		
	override bool IsInstant()
	{
		return true;
	}
	
	override bool RemoveForceTargetAfterUse()
	{
		return false;
	}
}