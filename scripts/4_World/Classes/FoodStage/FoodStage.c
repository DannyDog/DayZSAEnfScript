enum FoodStageType
{
	NONE		= 0,			//food stage not define
	RAW			= 1,			//default
	BAKED		= 2,
	BOILED		= 3,
	DRIED		= 4,
	BURNED		= 5,
	ROTTEN		= 6,
	
	COUNT						//for net sync purposes
}

class FoodStage
{
	protected FoodStageType m_FoodStageTypeClientLast;
	protected FoodStageType m_FoodStageType;
	protected Edible_Base m_FoodItem;
	
	protected int m_SelectionIndex;				//visual properties
	protected int m_TextureIndex;
	protected int m_MaterialIndex;
	
	protected float m_CookingTime;
	
	//constructor
	void FoodStage( Edible_Base food_item )
	{
		//default
		m_FoodStageType = FoodStageType.RAW;
		m_FoodItem = food_item;
		
		//reset cooking time
		m_CookingTime = 0;
		
		//get config data
		string config_path = "CfgVehicles" + " " + GetFoodItem().GetType() + " " + "Food" + " " + "FoodStages" + " " + GetFoodStageName( m_FoodStageType );
		
		//if not exists in config
		if ( !GetGame().ConfigIsExisting( config_path ) )
		{
			return;
		}
		
		//set params
		//visual properties
		array<int> visual_properties = new array<int>;
		GetGame().ConfigGetIntArray( config_path + " " + "visual_properties", visual_properties );
		if ( visual_properties.Count() > 0 )
		{
			SetSelectionIndex( visual_properties.Get( 0 ) );
			SetTextureIndex( visual_properties.Get( 1 ) );
			SetMaterialIndex( visual_properties.Get( 2 ) );
		}
		
		m_FoodStageTypeClientLast = m_FoodStageType;
	}
	
	//Food Stage Type
	FoodStageType GetFoodStageType()
	{
		return m_FoodStageType;
	}
	void SetFoodStageType( FoodStageType food_stage_type )
	{
		m_FoodStageType = food_stage_type;
	}
	
	//Selection index
	int GetSelectionIndex()
	{
		return m_SelectionIndex;
	}
	void SetSelectionIndex( int index )
	{
		m_SelectionIndex = index;
	}
	
	//Texture index
	int GetTextureIndex()
	{
		return m_TextureIndex;
	}
	void SetTextureIndex( int index )
	{
		m_TextureIndex = index;
	}
	
	//Material index
	int GetMaterialIndex()
	{
		return m_MaterialIndex;
	}
	void SetMaterialIndex( int index )
	{
		m_MaterialIndex = index;
	}
		
	//Food properties
	protected static float GetNutritionPropertyFromIndex( int index, FoodStageType stage_type, FoodStage stage, string classname )
	{
		if(stage)
		{
			stage_type = stage.m_FoodStageType;
			classname = stage.GetFoodItem().GetType();
		}
		
		string config_path;
		string food_stage_name = GetFoodStageName( stage_type );

		config_path = "CfgVehicles" + " " + classname + " " + "Food" + " " + "FoodStages" + " " + food_stage_name + " " + "nutrition_properties";
		array<float> nutrition_properties = new array<float>;
		GetGame().ConfigGetFloatArray( config_path, nutrition_properties );
		
		if ( nutrition_properties.Count() > 0 )
		{
			if( index > (nutrition_properties.Count() - 1))
			{
				return 0;
			}
			else
			{
				return nutrition_properties.Get( index );
			}
		}
		//calculate nutrition properties from base stage and nutrition modifiers
		else
		{
			//get modifiers class for nutrition values
			config_path = "CfgVehicles" + " " + classname + " " + "Food" + " " + "nutrition_modifiers_class";
			
			if ( GetGame().ConfigIsExisting( config_path ) )
			{
				string nutr_mod_class;
				GetGame().ConfigGetText( config_path, nutr_mod_class );
				
				config_path = "CfgVehicles" + " " + "NutritionModifiers" + " " + nutr_mod_class + " " + "base_stage";
				string nutr_base_stage;
				GetGame().ConfigGetText( config_path, nutr_base_stage );
				
				//get nutrition values for food stage and modifiers 
				config_path = "CfgVehicles" + " " + classname + " " + "Food" + " " + "FoodStages" + " " + nutr_base_stage + " " + "nutrition_properties";
				array<float> base_nutr_properties = new array<float>;
				GetGame().ConfigGetFloatArray( config_path, base_nutr_properties );
				
				config_path = "CfgVehicles" + " " + "NutritionModifiers" + " " + nutr_mod_class + " " + food_stage_name + " " + "nutrition_properties";
				array<float> nutr_mod_properties = new array<float>;
				GetGame().ConfigGetFloatArray( config_path, nutr_mod_properties );
				
				//base nutrition * food stage nutrition modifier
				if ( base_nutr_properties.Count() > 0 && nutr_mod_properties.Count() > 0 )
				{
					return ( base_nutr_properties.Get( index ) * nutr_mod_properties.Get( index ) );
				}
			}
		}
		
		return 0;
	}
	
	static float GetFullnessIndex(FoodStage stage, int stage_type = -1, string classname = "")
	{
		return GetNutritionPropertyFromIndex( 0 , stage_type, stage, classname );
	}
	
	static float GetEnergy(FoodStage stage, int stage_type = -1, string classname = "")
	{

		return GetNutritionPropertyFromIndex( 1 , stage_type, stage, classname );
	}
	
	static float GetWater(FoodStage stage, int stage_type = -1, string classname = "")
	{
		return GetNutritionPropertyFromIndex( 2 , stage_type, stage, classname );
	}
	
	static float GetNutritionalIndex(FoodStage stage, int stage_type = -1, string classname = "")
	{
		return GetNutritionPropertyFromIndex( 3 , stage_type , stage, classname);
	}
	
	static float GetToxicity(FoodStage stage, int stage_type = -1, string classname = "")
	{
		return GetNutritionPropertyFromIndex( 4 , stage_type, stage, classname );
	}
	
	static int GetAgents(FoodStage stage, int stage_type = -1, string classname = "")
	{
		return GetNutritionPropertyFromIndex( 5 , stage_type, stage, classname );
	}
	
	static float GetDigestibility(FoodStage stage, int stage_type = -1, string classname = "")
	{
		return GetNutritionPropertyFromIndex( 6 , stage_type, stage, classname );
	}
	
	//Food item
	protected Edible_Base GetFoodItem()
	{
		return m_FoodItem;
	}
	
	//Cooking time
	float GetCookingTime()
	{
		return m_CookingTime;
	}
	void SetCookingTime( float time )
	{
		m_CookingTime = time;
	}
	
	//********************************************/
	//	FOOD STAGE CHANGE
	//********************************************/
	//Checks if food stage can be changed to another stage
	bool CanChangeToNewStage( CookingMethodType cooking_method )
	{
		if ( GetNextFoodStageType( cooking_method ) == FoodStageType.NONE )
		{
			return false;
		}
		
		return true;
	}
	
	//returns possible food stage type according to given cooking method
	FoodStageType GetNextFoodStageType( CookingMethodType cooking_method )
	{
		ref array<string> string_output = new array<string>;
		ref array<string> stage_transitions = new array<string>;
		
		//get stage transitions from config
		string config_path = "CfgVehicles" + " " + GetFoodItem().GetType() + " " + "Food" + " " + "FoodStageTransitions" + " " + GetFoodStageName( GetFoodStageType() );;
		
		if ( GetGame().ConfigIsExisting( config_path ) )
		{
			int	child_count = GetGame().ConfigGetChildrenCount( config_path );
			
			for ( int i = 0; i < child_count; i++ )
			{
				string child_name;
				GetGame().ConfigGetChildName( config_path, i, child_name );
				string transition_config_path = config_path + " " + child_name + " " + "cooking_method";
				
				if ( GetGame().ConfigIsExisting( transition_config_path ) )
				{
					if ( GetGame().ConfigGetInt( transition_config_path ) == cooking_method )
					{
						string cooking_method_config_path = config_path + " " + child_name + " " + "transition_to";
						return GetGame().ConfigGetInt( cooking_method_config_path );
					}
				}
			}			
		}
		
		return FoodStageType.BURNED; //If the item cannot transition out of current state, burn it
	}
	
	void ChangeFoodStage( FoodStageType new_stage_type )
	{
		string config_path = "CfgVehicles" + " " + GetFoodItem().GetType() + " " + "Food" + " " + "FoodStages" + " " + GetFoodStageName( new_stage_type );
		
		//merge stages
		//food stage type
		SetFoodStageType( new_stage_type );
		
		array<int> visual_properties = new array<int>;
		GetGame().ConfigGetIntArray( config_path + " " + "visual_properties", visual_properties );
		if ( visual_properties.Count() > 0 )
		{
			//selection index
			int index = visual_properties.Get( 0 );
			if ( index >= 0 )
			{
				SetSelectionIndex( index );
			}
			//texture index
			index = visual_properties.Get( 1 );
			if ( index >= 0 )
			{
				SetTextureIndex( index );
			}
			//material index
			index = visual_properties.Get( 2 );
			if ( index >= 0 )
			{
				SetMaterialIndex( index );
			}	
		}
		
		//refresh visual
		GetFoodItem().Synchronize();
	}	

	void UpdateVisuals()
	{
		//if item has food stages
		if ( GetFoodItem().HasFoodStage() ) 
		{
			Edible_Base food_item = GetFoodItem();
			
			//Selections
			string config_path;
			ref array<string> config_selections	= new array<string>;
			ref array<string> config_textures	= new array<string>;
			ref array<string> config_materials	= new array<string>;
				
			//selections
			config_path = "CfgVehicles" + " " + food_item.GetType() + " " + "hiddenSelections";
			GetGame().ConfigGetTextArray( config_path, config_selections );
			//textures
			config_path = "CfgVehicles" + " " + food_item.GetType() + " " + "hiddenSelectionsTextures";
			GetGame().ConfigGetTextArray( config_path, config_textures );
			//materials
			config_path = "CfgVehicles" + " " + food_item.GetType() + " " + "hiddenSelectionsMaterials";
			GetGame().ConfigGetTextArray( config_path, config_materials );
			
			//selection index
			int selection_index;
			if ( GetSelectionIndex() >= 0 && config_selections.Count() > GetSelectionIndex() )
			{
				selection_index = GetSelectionIndex();
			}
			
			//texture index
			int texture_index;
			if ( GetTextureIndex() >= 0 && config_textures.Count() > GetTextureIndex() )
			{
				texture_index = GetTextureIndex();
			}
	
			//material index
			int material_index;
			if ( GetMaterialIndex() >= 0 && config_materials.Count() > GetMaterialIndex() )
			{
				material_index = GetMaterialIndex();
			}
				
			//hide all selection except the configured one
			for ( int i = 0; i < config_selections.Count(); i++ )
			{
				if ( config_selections.Get( i ) != config_selections.Get( selection_index ) )
				{
					food_item.SetAnimationPhase( config_selections.Get( i ), 1 );
				}
			}
	
			//Debug	
			//Print( "item = " + food_item.GetType() + " selection index = " + GetSelectionIndex().ToString() + " texture index = " + GetTextureIndex().ToString() );
		
			//show selection
			food_item.SetAnimationPhase( config_selections.Get( selection_index ), 0 );
			//set texture
			food_item.SetObjectTexture( selection_index, config_textures.Get( texture_index ) );
			//set materials
			food_item.SetObjectMaterial( selection_index, config_materials.Get( material_index ) );
		}
				
		m_FoodStageTypeClientLast = m_FoodStageType;
	}

	//Food States
	//check food stages
	bool IsFoodInStage( FoodStageType food_stage_type )
	{
		if ( GetFoodStageType() == food_stage_type )
		{
			return true;
		}
		
		return false;
	}
	
	bool IsFoodRaw()
	{
		return IsFoodInStage( FoodStageType.RAW );
	}
	
	bool IsFoodBaked()
	{
		return IsFoodInStage( FoodStageType.BAKED );
	}
	
	bool IsFoodBoiled()
	{
		return IsFoodInStage( FoodStageType.BOILED );
	}
	
	bool IsFoodDried()
	{
		return IsFoodInStage( FoodStageType.DRIED );
	}
	
	bool IsFoodBurned()
	{
		return IsFoodInStage( FoodStageType.BURNED );
	}

	bool IsFoodRotten()
	{
		return IsFoodInStage( FoodStageType.ROTTEN );
	}
			
	//get name of food stage type
	static string GetFoodStageName( FoodStageType food_stage_type )
	{
		switch( food_stage_type )
		{
			case FoodStageType.RAW: 	return "Raw";
			case FoodStageType.BAKED: 	return "Baked";
			case FoodStageType.BOILED: 	return "Boiled";
			case FoodStageType.DRIED: 	return "Dried";
			case FoodStageType.BURNED: 	return "Burned";
			case FoodStageType.ROTTEN: 	return "Rotten";
		}
		
		return "Raw";
	}
	
	//================================================================
	// SERIALIZATION
	//================================================================	
	void OnStoreSave( ParamsWriteContext ctx )
	{   
		//Food stage type 
		ctx.Write( m_FoodStageType );
		
		//Selection index
		ctx.Write( m_SelectionIndex );

		//Texture index
		ctx.Write( m_TextureIndex );

		//Material index
		ctx.Write( m_MaterialIndex );
	}
	
	bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		//Food stage type 
		if ( !ctx.Read( m_FoodStageType ) )
		{
			m_FoodStageType = FoodStageType.RAW;	//set default
			return false;
		}
		
		//Selection index
		if ( !ctx.Read( m_SelectionIndex ) )
		{
			m_SelectionIndex = 0;			//set default
			return false;
		}
		
		//Texture index
		if ( !ctx.Read( m_TextureIndex ) )
		{
			m_TextureIndex = 0;				//set default
			return false;
		}
		
		//Material index
		if ( !ctx.Read( m_MaterialIndex ) )
		{
			m_MaterialIndex = 0;			//set default			
			return false;
		}
		
		return true;
	}
}
