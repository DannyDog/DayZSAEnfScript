class ActionHandsPartSwitch: ActionSingleUseBase
{
	void ActionHandsPartSwitch()
	{
	}
	
	override void CreateConditionComponents()  
	{		
		m_ConditionItem = new CCINone; //'CCINotPresent' to perfom with empty hands only
		m_ConditionTarget = new CCTCursor;
	}
		
	override bool IsInstant()
	{
		return true;
	}
	
	override typename GetInputType()
	{
		return InteractActionInput;
	}
	
	override bool RemoveForceTargetAfterUse()
	{
		return false;
	}
	
	override bool UseAcknowledgment()
	{
		return true;
	}		
	
	override string GetText()
	{
		return "#switch_to_the_next_part";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( player && !player.IsLeaning() )
		{
			Object target_object = target.GetObject();
			if ( target_object && target_object.CanUseHandConstruction() )
			{
				BaseBuildingBase base_building = BaseBuildingBase.Cast( target_object );
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				construction_action_data.SetTarget( target_object );
				
				string main_part_name = target_object.GetActionComponentName( target.GetComponentIndex() );
				construction_action_data.RefreshPartsToBuild( main_part_name, null, false );
				
				if ( construction_action_data.GetConstructionPartsCount() > 1 )
				{
					//Check validity of recipes
					int valid_recipes;
					for (int i = 0; i < construction_action_data.GetConstructionPartsCount(); i++)
					{
						string name = construction_action_data.GetBuildPartAtIndex(i).GetPartName();
						if (MiscGameplayFunctions.ComplexBuildCollideCheckClient(player, target, item, name))
							valid_recipes++;
					}
					if (valid_recipes > 1)
						return true;
				}
			}
		}
		
		return false;
	}
	
	//-------------------------------------------------
	override void OnStartClient(ActionData action_data)
	{
		super.OnStartClient( action_data );
		
		SetNextIndex(action_data);
	}
	
	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer( action_data );
		
		if (!GetGame().IsMultiplayer())
			SetNextIndex(action_data);
	}
	
	void SetNextIndex(ActionData action_data)
	{
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		construction_action_data.SetNextIndex();
	}
}