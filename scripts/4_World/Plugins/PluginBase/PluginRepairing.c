class PluginRepairing extends PluginBase
{
	bool Repair(PlayerBase player, ItemBase repair_kit, ItemBase item, float specialty_weight, string damage_zone = "")
	{	
		switch ( item.GetHealthLevel(damage_zone) ) 
		{
			case GameConstants.STATE_PRISTINE:
				break;
				
			case GameConstants.STATE_WORN:
				if( CanRepairToPristine( player ) || CanBeRepairedToPristine( item ) )
				{
					CalculateHealth( player, repair_kit, item, specialty_weight, damage_zone );
				}
				break;
				
			case GameConstants.STATE_DAMAGED:
				CalculateHealth( player, repair_kit, item, specialty_weight, damage_zone );
				break;
				
			case GameConstants.STATE_BADLY_DAMAGED:
				CalculateHealth( player, repair_kit, item, specialty_weight, damage_zone );
				break;
			
			case GameConstants.STATE_RUINED:
				break;
		}

		return true;
	}

	void CalculateHealth( PlayerBase player, ItemBase kit, ItemBase item, float specialty_weight, string damage_zone = "" )
	{
		bool kit_has_quantity = kit.HasQuantity();
		float cur_kit_quantity = kit.GetQuantity();
		float kit_repair_cost = GetKitRepairCost( kit, item );
		float kit_repair_cost_adjusted;
		float new_quantity;
		float item_max_health = item.GetMaxHealth( damage_zone, "" );
		float health_up_one_level;
		
		health_up_one_level = item_max_health / 4;
		
		if ( cur_kit_quantity > health_up_one_level )
		{
			kit_repair_cost_adjusted = player.GetSoftSkillsManager().SubtractSpecialtyBonus( kit_repair_cost, specialty_weight );
			kit_repair_cost_adjusted = Math.Clamp( kit_repair_cost_adjusted, 0, 100 );
			new_quantity = kit.GetQuantity() - kit_repair_cost_adjusted;
			kit.SetQuantity( new_quantity );
			
			item.AddHealth( damage_zone, "", health_up_one_level );
		}
		else if (!kit_has_quantity) //"kit" without quantity (hammers and such) for your every day repairing needs
		{
			item.AddHealth( damage_zone, "", health_up_one_level );
		}
		else
		{
			new_quantity = kit.GetQuantity() - cur_kit_quantity;
			kit.SetQuantity( new_quantity );
			
			item.AddHealth( damage_zone, "", cur_kit_quantity );
		}
		
		if ( !CanRepairToPristine( player ) && !CanBeRepairedToPristine( item ) )
		{
			float item_health = item.GetHealth( damage_zone, "" );
			float clamp_health = Math.Clamp( item_health, 0, ( item_max_health * 0.7 ) );
			item.SetHealth( damage_zone, "", clamp_health );
		}		
	}

	bool CanRepair( ItemBase repair_kit, ItemBase item, string damage_zone = "" )
	{
		int state = item.GetHealthLevel(damage_zone);
		
		if ( (item.CanBeRepairedToPristine() && state >= GameConstants.STATE_WORN) || (!item.CanBeRepairedToPristine() && state >= GameConstants.STATE_DAMAGED ) )
		{
			int repair_kit_type = repair_kit.ConfigGetInt( "repairKitType" );
			
			ref array<int> repairable_with_types = new array<int>;
			item.ConfigGetIntArray( "repairableWithKits", repairable_with_types );	
						
			for ( int i = 0; i < repairable_with_types.Count(); i++ )
			{
				int repairable_with_type = repairable_with_types.Get(i);
				
				if ( IsRepairValid( repair_kit_type, repairable_with_type ) )
				{
					return true;
				}
			}
		}
		return false;
		
	}
	
	private bool IsRepairValid(int repair_kit_type, int repairable_with_type)
	{
		if ( repair_kit_type > 0 && repairable_with_type > 0 )
		{
			if ( repair_kit_type == repairable_with_type )
			{
				return true;
			}
		}
		
		return false;
	}

	//! Player can repair items to 100%; currently unused
	private bool CanRepairToPristine( PlayerBase player )
	{
// temporary disabled
/*
		float specialty = player.GetStatSpecialty().Get();
		
		if ( specialty <= -0.5 || specialty >= 0.5 )
		{
			return true;
		}
		else
		{
			return false; 
		}
*/
		return false; 
	}
	
	//! Item can be repaired to 100%
	private bool CanBeRepairedToPristine( ItemBase item )
	{
		return item.CanBeRepairedToPristine();
	}
	
	private float GetKitRepairCost( ItemBase repair_kit, ItemBase item )
	{
		ref array<int> repair_kit_types = new array<int>;	
		ref array<float> repair_kit_costs = new array<float>;	
		
		item.ConfigGetIntArray( "repairableWithKits", repair_kit_types );
		item.ConfigGetFloatArray( "repairCosts", repair_kit_costs );
		
		int eligible_kit;
		int kit_in_hands = repair_kit.ConfigGetInt( "repairKitType" );
		
		for ( int i = 0; i < repair_kit_types.Count(); i++ )
		{
			eligible_kit = repair_kit_types.Get(i);
			
			if ( eligible_kit == kit_in_hands )
			{
				float repair_cost = repair_kit_costs.Get(i);
			}
		} 
					
		return repair_cost;
	}
}
