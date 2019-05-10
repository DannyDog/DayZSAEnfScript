class ActionBuildPartSwitch: ActionSingleUseBase
{
	void ActionBuildPartSwitch()
	{
	}
	
	override void CreateConditionComponents()  
	{		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.BASEBUILDING);
	}
	
	override int GetType()
	{
		return AT_BUILD_PART_SWITCH;
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
			if ( target_object && target_object.CanUseConstruction() )
			{
				BaseBuildingBase base_building = BaseBuildingBase.Cast( target_object );
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				construction_action_data.SetTarget( target_object );
				
				string main_part_name = target_object.GetActionComponentName( target.GetComponentIndex() );
				construction_action_data.RefreshPartsToBuild( main_part_name, item );
				
				if ( construction_action_data.GetConstructionPartsCount() > 1 )
				{
					//camera and position checks
					if ( !base_building.IsFacingPlayer( player, main_part_name ) && !player.GetInputController().CameraIsFreeLook() )
					{
						//Camera check (client-only)
						if ( GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
						{
							return !base_building.IsFacingCamera( main_part_name );
						}
						
						return true;
					}
				}
			}
		}
		
		return false;
	}
	
	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		
		//set next index
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		construction_action_data.SetNextIndex();
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