enum CookingMethodType
{
	NONE		= 0,		//no cooking method available
	BAKING		= 1,
	BOILING		= 2,
	DRYING		= 3,
	TIME		= 4,
	
	COUNT
}

class Cooking
{
	static const float COOKING_FOOD_TIME_INC_VALUE 		= 2;		//time increase when cooking a food
	static const float COOKING_LARD_DECREASE_COEF 		= 25;		//lard quantity decrease when cooking a food (Baking)
	//
	static const float DEFAULT_COOKING_TEMPERATURE 		= 150;		//default temperature for cooking (e.g. cooking on stick)
	static const float FOOD_MAX_COOKING_TEMPERATURE		= 150;		//
	static const float PARAM_BURN_DAMAGE_COEF			= 0.05;		//value for calculating damage on items located in fireplace cargo
	//
	typename COOKING_EQUIPMENT_POT	 					= Pot;
	typename COOKING_EQUIPMENT_FRYINGPAN				= FryingPan;
	typename COOKING_INGREDIENT_LARD 					= Lard;
	//
	static const float LIQUID_BOILING_POINT 			= 150;	//boiling point for liquids
	static const float LIQUID_VAPOR_QUANTITY 			= 2;	//vapor quantity
	
	//COOKING PROCESS
	//--- Cooking with equipment (pot)
	//Returns 1 if the item changed its cooking stage, 0 if not
	int CookWithEquipment( ItemBase cooking_equipment, float cooking_time_coef = 1 )
	{
		int cooking_state_update = 0;
		bool is_done;
		bool is_empty;
		bool is_burned;
		
		//check cooking conditions
		if ( cooking_equipment == NULL )
		{
			return cooking_state_update;
		}
		
		//manage items in cooking equipment
		CookingMethodType cooking_method = GetCookingMethod( cooking_equipment );
		CargoBase cargo = cooking_equipment.GetInventory().GetCargo();
		if ( cargo.GetItemCount() == 0 )
		{
			is_empty = true;
		}
		//process items
		for ( int i = 0; i < cargo.GetItemCount(); i++ )
		{
			ItemBase item = ItemBase.Cast( cargo.GetItem( i ) );
			Edible_Base item_to_cook = Edible_Base.Cast( item );
			
			if ( item_to_cook && item_to_cook.CanBeCooked() )
			{
				//update food
				cooking_state_update = UpdateCookingState( item_to_cook, cooking_method, cooking_equipment, cooking_time_coef );
				
				//check for done state for boiling and drying
				if ( item_to_cook.IsFoodBoiled() || item_to_cook.IsFoodDried() )
				{
					is_done = true;
				}
				//check for done state fro baking (exclude Lard from baked items)
				else if ( item_to_cook.IsFoodBaked() && item_to_cook.Type() != Lard )		
				{
					is_done = true;
				}
				//check for burned state
				else if ( item_to_cook.IsFoodBurned() )
				{
					is_burned = true;
				}
			}
			else   
			{
				//damage item
				item.DecreaseHealth( "", "", PARAM_BURN_DAMAGE_COEF * 100 );
				
				//add temperature to item
				AddTemperatureToItem( item, NULL, 0 );
			}
		}
		
		//manage cooking equipment
		Bottle_Base bottle_base = Bottle_Base.Cast( cooking_equipment );
		if ( bottle_base )
		{
			float cooking_equipment_temp = cooking_equipment.GetTemperature();
			bool is_water_boiling;
			
			//handle water boiling
			if ( cooking_equipment_temp >= LIQUID_BOILING_POINT )
			{
				//remove agents
				cooking_equipment.RemoveAllAgents();
				
				if ( cooking_equipment.GetQuantity() > 0 )
				{
					is_water_boiling = true;
					
					//vaporize liquid
					cooking_equipment.AddQuantity( -LIQUID_VAPOR_QUANTITY );
				};
			}
			
			//handle audio visuals
			bottle_base.RefreshAudioVisualsOnClient( cooking_method, is_done, is_empty, is_burned );
		}

		FryingPan frying_pan = FryingPan.Cast( cooking_equipment );
		if ( frying_pan && !bottle_base )
		{
			//handle audio visuals
			frying_pan.RefreshAudioVisualsOnClient( cooking_method, is_done, is_empty, is_burned );
		}
		
		return cooking_state_update;
	}
	
	//Returns 1 if the item changed its cooking stage, 0 if not
	int CookOnStick( Edible_Base item_to_cook, float cook_time_inc )
	{
		if ( item_to_cook && item_to_cook.CanBeCookedOnStick() )
		{
			//update food
			return UpdateCookingStateOnStick( item_to_cook, cook_time_inc );
		}
		
		return 0;
	}
	
	//Returns 1 if the item changed its cooking stage, 0 if not
	protected int UpdateCookingState( Edible_Base item_to_cook, CookingMethodType cooking_method, ItemBase cooking_equipment, float cooking_time_coef )
	{
		//food properties
		float food_temperature = item_to_cook.GetTemperature();
		
		//{min_temperature, time_to_cook, max_temperature (optional)}
		//get next stage name - if next stage is not defined, next stage name will be empty "" and no cooking properties (food_min_temp, food_time_to_cook, food_max_temp) will be set
		FoodStageType new_stage_type = item_to_cook.GetNextFoodStageType( cooking_method );
		float food_min_temp = 0;
		float food_time_to_cook = 0;
		float food_max_temp = -1;
		
		//Set next stage cooking properties if next stage possible
		if ( item_to_cook.CanChangeToNewStage( cooking_method ) )
		{
			ref array<float> next_stage_cooking_properties = new array<float>;
			
			string config_path = "CfgVehicles" + " " + item_to_cook.GetType() + " " + "Food" + " " + "FoodStages";
			GetGame().ConfigGetFloatArray( config_path + " " + item_to_cook.GetFoodStageName( new_stage_type ) + " " + "cooking_properties", next_stage_cooking_properties );
			
			food_min_temp = next_stage_cooking_properties.Get( 0 );
			food_time_to_cook = next_stage_cooking_properties.Get( 1 );
			
			if ( next_stage_cooking_properties.Count() > 2)
			{
				food_max_temp = next_stage_cooking_properties.Get ( 2 );
			}
		}
		
		//add temperature
		AddTemperatureToItem( item_to_cook, cooking_equipment, food_min_temp );
		
		//add cooking time if the food can be cooked by this method
		if ( food_min_temp > 0 && food_temperature >= food_min_temp )
		{
			float new_cooking_time = item_to_cook.GetCookingTime() + COOKING_FOOD_TIME_INC_VALUE * cooking_time_coef;
			item_to_cook.SetCookingTime( new_cooking_time );
			
			//progress to next stage
			if ( item_to_cook.GetCookingTime() >= food_time_to_cook )
			{
				//if max temp is defined check next food stage
				if ( food_max_temp >= 0 )
				{
					if ( food_temperature > food_max_temp && item_to_cook.GetFoodStageType() != FoodStageType.BURNED )
					{
						new_stage_type = FoodStageType.BURNED;
					}
				}
				
				//change food stage
				item_to_cook.ChangeFoodStage( new_stage_type );
				//Temp
				//Remove all modifiers
				item_to_cook.RemoveAllAgentsExcept(eAgents.BRAIN);
				
				//remove lard when baking with cooking equipment
				if ( cooking_equipment && cooking_method == CookingMethodType.BAKING )
				{
					if ( item_to_cook.Type() != COOKING_INGREDIENT_LARD )
					{
						//get lard item
						ItemBase item_lard = GetItemTypeFromCargo( COOKING_INGREDIENT_LARD, cooking_equipment );
						
						//decrease lard quantity
						float lard_quantity = item_lard.GetQuantity() - COOKING_LARD_DECREASE_COEF;
						lard_quantity = Math.Clamp( lard_quantity, 0, item_lard.GetQuantityMax() );
						item_lard.SetQuantity( lard_quantity );
					}
				}
				
				//reset cooking time
				item_to_cook.SetCookingTime( 0 );
				return 1;
			}
		}
		
		return 0;
	}
	
	//Returns 1 if the item changed its cooking stage, 0 if not
	protected int UpdateCookingStateOnStick( Edible_Base item_to_cook, float cook_time_inc )
	{
		//food properties
		float food_temperature = item_to_cook.GetTemperature();
		
		//{min_temperature, time_to_cook, max_temperature (optional)}
		//get next stage name - if next stage is not defined, next stage name will be empty "" and no cooking properties (food_min_temp, food_time_to_cook, food_max_temp) will be set
		FoodStageType new_stage_type = item_to_cook.GetNextFoodStageType( CookingMethodType.BAKING );
		float food_min_temp = 0;
		float food_time_to_cook = 0;
		float food_max_temp = -1;
		bool is_done = false;	// baked
		bool is_burned = false;	// burned

		//Set next stage cooking properties if next stage possible
		if ( item_to_cook.CanChangeToNewStage ( CookingMethodType.BAKING ) )
		{
			ref array<float> next_stage_cooking_properties = new array<float>;

			string config_path = "CfgVehicles" + " " + item_to_cook.GetType() + " " + "Food" + " " + "FoodStages";
			GetGame().ConfigGetFloatArray ( config_path + " " + item_to_cook.GetFoodStageName( new_stage_type ) + " " + "cooking_properties", next_stage_cooking_properties );

			food_min_temp = next_stage_cooking_properties.Get( 0 );
			food_time_to_cook = next_stage_cooking_properties.Get( 1 );

			if ( next_stage_cooking_properties.Count() > 2)
			{
				food_max_temp = next_stage_cooking_properties.Get( 2 );
			}
		}
		
		//add temperature
		AddTemperatureToItem( item_to_cook, NULL, food_min_temp );
		
		// refresh audio
		if ( item_to_cook.GetInventory().IsAttachment() )
		{
			InventoryLocation invloc = new InventoryLocation;
			item_to_cook.GetInventory().GetCurrentInventoryLocation( invloc );
			if ( invloc )
			{
				if ( InventorySlots.GetSlotName( invloc.GetSlot() ) != "Ingredient" )
				{
					item_to_cook.MakeSoundsOnClient( true );
				}
			}
		}
		
		//add cooking time if the food can be cooked by this method
		if ( food_min_temp > 0 && food_temperature >= food_min_temp )
		{
			float new_cooking_time = item_to_cook.GetCookingTime() + cook_time_inc;
			item_to_cook.SetCookingTime( new_cooking_time );
			
			//progress to next stage
			if ( item_to_cook.GetCookingTime() >= food_time_to_cook )
			{
				//if max temp is defined check next food stage
				if ( food_max_temp >= 0 )
				{
					if ( food_temperature > food_max_temp && item_to_cook.GetFoodStageType() != FoodStageType.BURNED )
					{
						new_stage_type = FoodStageType.BURNED;
					}
				}
				
				//change food stage
				item_to_cook.ChangeFoodStage( new_stage_type );
				//Temp
				//Remove all modifiers
				item_to_cook.RemoveAllAgentsExcept(eAgents.BRAIN);

				//reset cooking time
				item_to_cook.SetCookingTime( 0 );
				return 1;
			}
		}
		
		return 0;
	}
	
	void SmokeItem( Edible_Base item_to_cook, float cook_time_inc )
	{
		if ( item_to_cook )
		{
			if ( ( item_to_cook.GetFoodStageType() == FoodStageType.RAW ) || ( item_to_cook.GetFoodStageType() == FoodStageType.BAKED ) || ( item_to_cook.GetFoodStageType() == FoodStageType.BOILED ) )
			{
				ref array<float> next_stage_cooking_properties = new array<float>;
				string config_path = "CfgVehicles" + " " + item_to_cook.GetType() + " " + "Food" + " " + "FoodStages";
				GetGame().ConfigGetFloatArray ( config_path + " " + item_to_cook.GetFoodStageName( FoodStageType.DRIED ) + " " + "cooking_properties", next_stage_cooking_properties );
				if ( next_stage_cooking_properties.Count() == 0 )
					return;
				
				float new_cooking_time = item_to_cook.GetCookingTime() + ( cook_time_inc );
				item_to_cook.SetCookingTime( new_cooking_time );

				if ( item_to_cook.GetCookingTime() >= next_stage_cooking_properties.Get( 1 ) )
				{
					item_to_cook.ChangeFoodStage( FoodStageType.DRIED );
					item_to_cook.RemoveAllAgentsExcept(eAgents.BRAIN);
				}
			}
			else
			{
				item_to_cook.SetCookingTime( 0 );
			}
		}
	}
	
	//COOKING DATA
	//
	protected ItemBase GetItemTypeFromCargo( typename item_type, ItemBase cooking_equipment )
	{
		CargoBase cargo = cooking_equipment.GetInventory().GetCargo();
		
		for ( int i = 0; i < cargo.GetItemCount(); i++ )
		{
			EntityAI entity = cargo.GetItem( i );
			if ( entity.Type() == item_type )
			{
				ItemBase item = ItemBase.Cast( entity );

				return item;
			}
		}
		
		return NULL;
	}

	protected CookingMethodType GetCookingMethod( ItemBase cooking_equipment )
	{
		if ( cooking_equipment.Type() == COOKING_EQUIPMENT_POT )
		{
			//has water
			if ( cooking_equipment.GetQuantity() > 0 )
			{
				return CookingMethodType.BOILING;
			}
			
			//has lard in cargo
			if ( GetItemTypeFromCargo( COOKING_INGREDIENT_LARD, cooking_equipment ) )
			{
				return CookingMethodType.BAKING;
			}
			return CookingMethodType.DRYING;
		}
		
		if (cooking_equipment.Type() == COOKING_EQUIPMENT_FRYINGPAN )
		{
			if ( GetItemTypeFromCargo( COOKING_INGREDIENT_LARD, cooking_equipment ) )
			{
				return CookingMethodType.BAKING;
			}
			return CookingMethodType.DRYING;
		}

		return CookingMethodType.NONE;
	}
	
	Edible_Base GetFoodOnStick( ItemBase stick_item )
	{
		Edible_Base food_on_stick = Edible_Base.Cast( stick_item.GetAttachmentByType( Edible_Base ) );

		return food_on_stick;
	}
	
	float GetTimeToCook( Edible_Base item_to_cook, CookingMethodType cooking_method )
	{
		ref array<float> next_stage_cooking_properties = new array<float>;
		string config_path = "CfgVehicles" + " " + item_to_cook.GetType() + " " + "Food" + " " + "FoodStages";
		FoodStageType food_stage_type = item_to_cook.GetNextFoodStageType( cooking_method );
		GetGame().ConfigGetFloatArray( config_path + " " + item_to_cook.GetFoodStageName( food_stage_type ) + " " + "cooking_properties", next_stage_cooking_properties );
		
		return next_stage_cooking_properties.Get( 1 );
	}

	float GetMinTempToCook( Edible_Base item_to_cook, CookingMethodType cooking_method )
	{
		ref array<float> next_stage_cooking_properties = new array<float>;
		string config_path = "CfgVehicles" + " " + item_to_cook.GetType() + " " + "Food" + " " + "FoodStages";
		FoodStageType food_stage_type = item_to_cook.GetNextFoodStageType( cooking_method );
		GetGame().ConfigGetFloatArray( config_path + " " + item_to_cook.GetFoodStageName( food_stage_type ) + " " + "cooking_properties", next_stage_cooking_properties );
		
		return next_stage_cooking_properties.Get( 0 );
	}
	
	//add temperature to item
	protected void AddTemperatureToItem( ItemBase cooked_item, ItemBase cooking_equipment, float min_temperature )
	{
		if ( cooked_item.GetTemperatureMax() >= FireplaceBase.PARAM_ITEM_HEAT_MIN_TEMP )
		{
			float item_temperature = cooked_item.GetTemperature();
			
			//set actual cooking temperature
			float actual_cooking_temp = DEFAULT_COOKING_TEMPERATURE;	//default
			if ( cooking_equipment )
			{
				actual_cooking_temp = cooking_equipment.GetTemperature();
			}
			
			//add temperature
			if ( actual_cooking_temp > item_temperature )
			{
				
				item_temperature = actual_cooking_temp * 0.5;
				item_temperature = Math.Clamp( item_temperature, min_temperature, FOOD_MAX_COOKING_TEMPERATURE );
				
				//set new temperature
				if ( GetGame() && GetGame().IsServer() )
				{
					cooked_item.SetTemperature( item_temperature );
				}
			}
		}
	}
	
}
