class Edible_Base extends ItemBase
{
	ref FoodStage m_FoodStage;
	
	void Edible_Base()
	{
		if ( HasFoodStage() )
		{
			m_FoodStage = new FoodStage( this );
			
			//synchronized variables
			RegisterNetSyncVariableInt( "m_FoodStage.m_FoodStageType", 	FoodStageType.NONE, FoodStageType.COUNT );
			RegisterNetSyncVariableInt( "m_FoodStage.m_SelectionIndex", 0, 6 );
			RegisterNetSyncVariableInt( "m_FoodStage.m_TextureIndex", 	0, 6 );
			RegisterNetSyncVariableInt( "m_FoodStage.m_MaterialIndex", 	0, 6 );
			RegisterNetSyncVariableFloat( "m_FoodStage.m_CookingTime", 	0, 600, 0 );						//min = 0; max = 0; precision = 0;
		}
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		//update visual
		UpdateVisuals();
	}
	
	void UpdateVisuals()
	{
		if ( GetFoodStage() )
		{
			GetFoodStage().UpdateVisuals();
		}
	}
	
	bool Consume(float amount, PlayerBase consumer)
	{
		AddQuantity(-amount, false, false);
		OnConsume(amount, consumer);
		return true;
	}
	
	void OnConsume(float amount, PlayerBase consumer);	
	
	//food staging
	override bool CanBeCooked()
	{
		return false;
	}
	
	override bool CanBeCookedOnStick()
	{
		return false;
	}
	
	//================================================================
	// SYNCHRONIZATION
	//================================================================	
	void Synchronize()
	{
		if ( GetGame().IsServer() )
		{
			SetSynchDirty();
			
			if ( GetGame().IsMultiplayer() )
			{
				UpdateVisuals();
			}
		}
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		//update visuals
		UpdateVisuals();
	}	
	
	//================================================================
	// SERIALIZATION
	//================================================================	
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );

		if ( GetFoodStage() )
		{
			GetFoodStage().OnStoreSave( ctx );
		}
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;

		if ( GetFoodStage() )
		{
			if ( !GetFoodStage().OnStoreLoad( ctx, version ) )
			return false;
		}
		
		return true;
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
		
		//synchronize
		Synchronize();
	}	

	//get food stage
	FoodStage GetFoodStage()
	{
		return m_FoodStage;
	}
	
	//food types
	bool IsMeat()
	{
		return false;
	}
	
	bool IsFruit()
	{
		return false;
	}
	
	bool IsMushroom()
	{
		return false;
	}	
	
	//================================================================
	// NUTRITIONAL VALUES
	//================================================================	
	//food properties
	float GetFoodTotalVolume()
	{
		if ( !GetFoodStage() )
		{
			string class_path = "cfgVehicles " + GetType() + " Nutrition";
			return GetGame().ConfigGetFloat( class_path + " fullnessIndex" );			
		}
		
		return GetFoodStage().GetFullnessIndex();
	}
	
	float GetFoodEnergy()
	{
		if ( !GetFoodStage() )
		{
			string class_path = "cfgVehicles " + GetType() + " Nutrition";
			return GetGame().ConfigGetFloat( class_path + " energy" );			
		}

		return GetFoodStage().GetEnergy();
	}
	
	float GetFoodWater()
	{
		if ( !GetFoodStage() )
		{
			string class_path = "cfgVehicles " + GetType() + " Nutrition";
			return GetGame().ConfigGetFloat( class_path + " water" );			
		}

		return GetFoodStage().GetWater();
	}
	
	float GetFoodNutritionalIndex()
	{
		if ( !GetFoodStage() )
		{
			string class_path = "cfgVehicles " + GetType() + " Nutrition";
			return GetGame().ConfigGetFloat( class_path + " nutritionalIndex" );			
		}

		return GetFoodStage().GetNutritionalIndex();
	}
	
	float GetFoodToxicity()
	{
		if ( !GetFoodStage() )
		{
			string class_path = "cfgVehicles " + GetType() + " Nutrition";
			return GetGame().ConfigGetFloat( class_path + " toxicity" );			
		}

		return GetFoodStage().GetToxicity();
	}
	
	NutritionalProfile GetNutritionalProfile()
	{
		NutritionalProfile profile; 
		if( !IsLiquidPresent() )
		{
			profile = NutritionalProfile(GetFoodEnergy(),GetFoodWater(),GetFoodNutritionalIndex(),GetFoodTotalVolume(), GetFoodToxicity());
		}
		else
		{
			int liquid_type = GetLiquidType();
			profile = Liquid.GetNutritionalProfile(liquid_type);
		}
		return profile;
		
	}
	
	//================================================================
	// FOOD STAGING
	//================================================================
	FoodStageType GetFoodStageType()
	{
		return GetFoodStage().GetFoodStageType();
	}
	
	//food stage states
	bool IsFoodRaw()
	{
		if ( GetFoodStage() ) 
		{
			return GetFoodStage().IsFoodRaw();
		}
		
		return false;
	}

	bool IsFoodBaked()
	{
		if ( GetFoodStage() ) 
		{
			return GetFoodStage().IsFoodBaked();
		}
		
		return false;
	}
	
	bool IsFoodBoiled()
	{
		if ( GetFoodStage() ) 
		{
			return GetFoodStage().IsFoodBoiled();
		}
		
		return false;
	}
	
	bool IsFoodDried()
	{
		if ( GetFoodStage() ) 
		{
			return GetFoodStage().IsFoodDried();
		}
		
		return false;
	}
	
	bool IsFoodBurned()
	{
		if ( GetFoodStage() ) 
		{
			return GetFoodStage().IsFoodBurned();
		}
		
		return false;
	}
	
	bool IsFoodRotten()
	{
		if ( GetFoodStage() ) 
		{
			return GetFoodStage().IsFoodRotten();
		}
		
		return false;
	}				
	
	//food stage change
	void ChangeFoodStage( FoodStageType new_food_stage_type )
	{
		GetFoodStage().ChangeFoodStage( new_food_stage_type );
	}
	
	FoodStageType GetNextFoodStageType( CookingMethodType cooking_method )
	{
		return GetFoodStage().GetNextFoodStageType( cooking_method );
	}
	
	string GetFoodStageName( FoodStageType food_stage_type )
	{
		return GetFoodStage().GetFoodStageName( food_stage_type );
	}
	
	bool CanChangeToNewStage( CookingMethodType cooking_method )
	{
		return GetFoodStage().CanChangeToNewStage( cooking_method );
	}
	
	//================================================================
	// COOKING
	//================================================================
	//cooking time
	float GetCookingTime()
	{
		return GetFoodStage().GetCookingTime();
	}
	
	void SetCookingTime( float time )
	{
		GetFoodStage().SetCookingTime( time );
		
		//synchronize when calling on server
		Synchronize();
	}
	
	//replace edible with new item (opening cans)
	void ReplaceEdibleWithNew (string typeName)
	{
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (player)
		{
			ReplaceEdibleWithNewLambda lambda = new ReplaceEdibleWithNewLambda(this, typeName, player);
			player.ServerReplaceItemInHandsWithNew(lambda);
		}
		else
			Error("ReplaceEdibleWithNew - cannot use edible without player");
	}
}

class ReplaceEdibleWithNewLambda : TurnItemIntoItemLambda
{
	void ReplaceEdibleWithNewLambda (EntityAI old_item, string new_item_type, PlayerBase player) { }
};
