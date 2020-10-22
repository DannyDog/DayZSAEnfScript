class GardenBase extends BuildingSuper
{
	// Paths to slot textures. Slots can have multiple states, so multiple textures must be generated
	static const string SLOT_TEXTURE_DIGGED_WET_LIME		= "dz\\gear\\cultivation\\data\\soil_digged_wet_lime_CO.paa";
	static const string SLOT_TEXTURE_DIGGED_WET_PLANT		= "dz\\gear\\cultivation\\data\\soil_digged_wet_plant_CO.paa";
	
	// Wet/dry material
	static const string SLOT_MATERIAL_WET					= "dz\\gear\\cultivation\\data\\soil_cultivated_wet.rvmat";
	static const string SLOT_MATERIAL_DRY					= "dz\\gear\\cultivation\\data\\soil_cultivated.rvmat";
	
	static const string SLOT_MATERIAL_LIMED_WET				= "dz\\gear\\cultivation\\data\\soil_cultivated_limed_wet.rvmat";
	static const string SLOT_MATERIAL_LIMED_DRY				= "dz\\gear\\cultivation\\data\\soil_cultivated_limed.rvmat";
	static const string SLOT_MATERIAL_COMPOST_WET			= "dz\\gear\\cultivation\\data\\soil_cultivated_compost_wet.rvmat";
	static const string SLOT_MATERIAL_COMPOST_DRY			= "dz\\gear\\cultivation\\data\\soil_cultivated_compost.rvmat";
	
	// slot names
	private static const string SLOT_SELECTION_DIGGED_PREFIX 	= "seedbase_";
	private static const string SLOT_SELECTION_COVERED_PREFIX 	= "slotCovered_";
	private static const string SLOT_MEMORY_POINT_PREFIX 		= "slot_";
	private static const string SLOT_SEEDBASE_PREFIX 			= "seedbase_";
	
	
	private static const int 	CHECK_RAIN_INTERVAL 			= 15;
	
	protected ref array<ref Slot> m_Slots;
	protected float m_DefaultFertility = 1;
	ref Timer 		m_CheckRainTimer;
	
	private static ref map<string,string> m_map_slots; // For the 'attachment slot -> plant slot' conversion. It is possible that this will be removed later.
	
	void GardenBase()
	{		
		m_map_slots = new map<string,string>;
		
		SetEventMask(EntityEvent.INIT); // Enable EOnInit event
		
		// Prepare m_map_slots
		for (int i = 1;  i <= GetGardenSlotsCount() ;  ++i)
		{
			// m_map_slots is supposed to be: <input, output>
			string input = SLOT_SEEDBASE_PREFIX + i.ToString();
			string output = SLOT_MEMORY_POINT_PREFIX;
			
			if (i < 10)
				output = output + "0"; // Example: '1' changes to '01'
			
			output = output + i.ToString();
			
			m_map_slots.Set(input, output);
		}
		
		if (GetGame().IsServer())
		{
			if ( !m_CheckRainTimer )
				m_CheckRainTimer = new Timer( CALL_CATEGORY_SYSTEM );
			
			m_CheckRainTimer.Run( Math.RandomFloat(0,CHECK_RAIN_INTERVAL), this, "CheckRainStart", NULL, false ); // Temporarily removed by disabling the loop parameter. It might have been causing server-side stuttering. Good solution could be provided by upcoming (?) staging system.
		}
		
		InitializeSlots();
	}
	
	override bool HasProxyParts()
	{
		return true;
	}
	
	void SetBaseFertility(float value)
	{
		m_DefaultFertility = value;
	}
	
	float GetBaseFertility()
	{
		return m_DefaultFertility;
	}
	
	override void EOnInit(IEntity other, int extra)
	{
		CheckRainTick();
		UpdateTexturesOnAllSlots();
	}

	void InitializeSlots()
	{
		m_Slots = new array<ref Slot>;
		int slots_count = GetGardenSlotsCount();
		
		for ( int i = 0; i < slots_count; i++ )
		{
			Slot slot = new Slot(GetBaseFertility());
			slot.SetSlotIndex(i);
			int i1 = i + 1;
			string name = "SeedBase_" + i1;
			int slot_id = InventorySlots.GetSlotIdFromString(name);
			slot.SetSlotId(slot_id);
			slot.SetGarden(this);
			slot.m_State = Slot.STATE_DIGGED;
			m_Slots.Insert( slot );
		}
	}
	
	void UpdateTexturesOnAllSlots()
	{
		int slots_count = GetGardenSlotsCount();
		
		for ( int i = 0; i < slots_count; i++ )
		{
			UpdateSlotTexture(i);
		}
	}

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		if ( version < 102 )
		{
			float some_value;
			ctx.Read( some_value ); // compatibility check
		}
		
		int slots_count = GetGardenSlotsCount();
		
		for ( int i = 0; i < slots_count; i++ )
		{
			Slot slot = m_Slots.Get( i );

			if ( !slot.OnStoreLoadCustom( ctx, version ) )
				return false;

			UpdateSlotTexture( i );
		}

		return true;
	}

	override void OnStoreSave( ParamsWriteContext ctx )
	{
		super.OnStoreSave( ctx );
		
		// ctx.Write( m_BaseFertility ); // Not needed since storage version 102
		
		int slots_count = GetGardenSlotsCount();
		
		for ( int i = 0; i < slots_count; i++ )
		{
			Slot slot = m_Slots.Get( i );
			
			slot.OnStoreSaveCustom( ctx );
		}
	}
	
	void PrintSlots()
	{
		Print("PRINT ALL SLOTS FROM...");
		Print(this);
		int slots = GetInventory().GetAttachmentSlotsCount();
		Print(slots);
		
		for ( int i = 0; i < slots ; i++ )
		{
			Slot slot = m_Slots.Get(i);
			Print(i);
			Print(slot);

			float slot_fertility = slot.GetFertility();
			float slot_fertility_usage = slot.GetFertilityMax();
			string slot_fertility_type = slot.GetFertilityType();
			float slot_water = slot.GetWater();
			float slot_water_usage = slot.GetWaterUsage();
			ItemBase slot_seed = slot.GetSeed();
			ItemBase slot_plant = slot.GetPlant();
			float slot_state= slot.GetState();
			float slot_slot_Index = slot.GetSlotIndex();
			float slot_slot_ID = slot.GetSlotId();
			
			Print(slot_fertility);
			Print(slot_fertility_usage);
			Print(slot_fertility_type);
			Print(slot_water);
			Print(slot_water_usage);
			Print(slot_seed);
			Print(slot_plant);
			Print(slot_state);
			Print(slot_slot_Index);
			Print(slot_slot_ID);
			Print("///////////////////////////");
		}
		
		Print("END OF ALL SLOTS FOR...");
		Print(this);
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}
		return false;
	}

	override bool CanPutIntoHands( EntityAI player )
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		return false;
	}

	override bool CanRemoveFromHands( EntityAI player )
	{
		return false;
	}

	int GetGardenSlotsCount()
	{
		return 0;
	}

	bool CanPlantSeed( string selection_component )
	{
		Slot slot = GetSlotBySelection( selection_component );
		
		if ( slot != NULL && slot.m_State == Slot.STATE_DIGGED )
		{
			return  true;
		}
		else
		{
			return false;
		}
	}
	
	// Converts attachment slot name into plant slot name. Example: 'seedbase_1' -> 'component02'
	string ConvertAttSlotToPlantSlot(string attach_slot)
	{
		// Give result
		if ( m_map_slots.Contains(attach_slot) )
		{
			string return_value = m_map_slots.Get(attach_slot);
			return return_value;
		}
		
		return "";
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		
		string path = "CfgVehicles " + item.GetType() + " Horticulture" + " PlantType";
		bool IsItemSeed = GetGame().ConfigIsExisting(path); // Is this item a seed?
		int slot_id = InventorySlots.GetSlotIdFromString(slot_name);
		
		if ( IsItemSeed ) 
		{
			string converted_slot_name;
			
			vector pos = GetPosition();
			int index = GetSlotIndexByAttachmentSlot( slot_name );
			
			if (index < 10)
			{
				converted_slot_name = SLOT_MEMORY_POINT_PREFIX + "0" + index.ToString();
			}
			else
			{
				converted_slot_name = SLOT_MEMORY_POINT_PREFIX + index.ToString();
			}
			
			PlantSeed( ItemBase.Cast( item ), converted_slot_name);
		}
		else if (g_Game.IsClient())
		{
			Slot slot = GetSlotByIndex(GetSlotIndexByAttachmentSlot( slot_name) - 1);
			if (slot)
			{
				slot.SetPlant(PlantBase.Cast( item ));
				slot.m_State = Slot.STATE_PLANTED;
			}
		}
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		slot_name.ToLower();

		string path = "CfgVehicles " + item.GetType() + " Horticulture " + "PlantType";
		bool IsItemSeed = GetGame().ConfigIsExisting(path); // Is this item a seed?
		string converted_slot_name = ConvertAttSlotToPlantSlot(slot_name);
		Slot slot = GetSlotBySelection(converted_slot_name);
		
		if (slot)
		{
			if (IsItemSeed)
			{
				slot.SetSeed(NULL);				
			}
			else if (g_Game.IsClient())
			{
				slot.Init( GetBaseFertility() );
			}	
			
			slot.SetState(Slot.STATE_DIGGED);		
		}		
	}
	
	// Plants the seed into slot (selection_component)
	void PlantSeed( ItemBase seed, string selection_component )
	{
		int slot_index = GetSlotIndexBySelection( selection_component );
		
		if ( slot_index != -1 )
		{
			PluginHorticulture module_horticulture = PluginHorticulture.Cast( GetPlugin( PluginHorticulture ) );
			string plant_type = module_horticulture.GetPlantType( seed );
			
			Slot slot = m_Slots.Get( slot_index );
			slot.SetState(Slot.STATE_PLANTED);
			slot.m_PlantType = plant_type;
			slot.SetSeed(seed);
			slot.SetSlotComponent(selection_component);
			
			if ( !slot.NeedsWater() )
			{
				CreatePlant(slot);
			}
		}
	}
	
	// Creates a plant
	void CreatePlant(Slot slot )
	{
		if (g_Game.IsServer())
		{
			ItemBase seed = slot.GetSeed();
			GetGame().ObjectDelete(seed);

			PlantBase plant = PlantBase.Cast( GetInventory().CreateAttachmentEx( slot.m_PlantType, slot.GetSlotId()) );
		
			int slot_index = slot.GetSlotIndex();
			slot.SetPlant(plant);						
			plant.Init( this, slot.GetFertility(), slot.m_HarvestingEfficiency, slot.GetWater() );
			ShowSelection(SLOT_SELECTION_COVERED_PREFIX + (slot_index + 1).ToStringLen(2));
				
			plant.LockToParent();
		}
	}
		
	void Fertilize( PlayerBase player, ItemBase item, float consumed_quantity, string selection_component )
	{
		Slot slot = GetSlotBySelection( selection_component );
		
		if ( slot != NULL )
		{
			string item_type = item.GetType();
			
			if ( slot.m_FertilizerType == ""  ||  slot.m_FertilizerType == item_type )
			{
				slot.m_FertilizerType = item_type;
				
				float add_energy_to_slot = GetGame().ConfigGetFloat( "cfgVehicles " + item_type + " Horticulture AddEnergyToSlot" );
				slot.m_FertilizerUsage = GetGame().ConfigGetFloat( "cfgVehicles " + item_type + " Horticulture ConsumedQuantity" );
				
				float coef = Math.Clamp( consumed_quantity / slot.m_FertilizerUsage, 0.0, 1.0 );
				add_energy_to_slot = coef * add_energy_to_slot;
				
				slot.m_FertilizerQuantity += consumed_quantity;
				slot.m_Fertility += add_energy_to_slot;
				
				if ( NeedsFertilization(selection_component) == false )
				{
					int slot_index = slot.GetSlotIndex();
					
					if (slot_index > -1)
					{
						UpdateSlotTexture( slot_index );
					
						//TODO Boris: Add soft skill 2.0
						//PluginExperience module_exp = GetPlugin(PluginExperience);
						//slot.m_HarvestingEfficiency = module_exp.GetExpParamNumber(player, PluginExperience.EXP_FARMER_FERTILIZATION, "efficiency");
					}
				}
			}
			else
			{
				slot.SetFertilizerQuantity(0);
				slot.SetFertilityType("");
			}
		}
	}

	bool IsCorrectFertilizer( ItemBase item, string selection_component )
	{
		Slot slot = GetSlotBySelection( selection_component );
		
		if ( slot != NULL )
		{
			string item_type = item.GetType();
			
			if ( slot.m_FertilizerType == "" || slot.m_FertilizerType == item_type )
			{
				return true;
			}
		}
		
		return false;
	}

	bool NeedsFertilization( string selection_component )
	{
		Slot slot = GetSlotBySelection( selection_component );
		
		if ( slot )
		{
			if ( slot.m_FertilizerType == ""  ||  slot.m_FertilizerQuantity < slot.m_FertilizerUsage )
			{
				return true;
			}
		}
		
		return false;
	}

	void UpdateSlotTexture( int slot_index )
	{
		// TO DO: Fix DAYZ-30633 here!
		Slot slot = m_Slots.Get( slot_index );
		
		// Show / Hide selections according to DIGGED or COVERED states.
		
		if ( slot.IsDigged()  ||  slot.IsPlanted() )
		{
			string str_hide = SLOT_SELECTION_COVERED_PREFIX + (slot_index + 1).ToStringLen(2);
			string str_show = SLOT_SELECTION_DIGGED_PREFIX + (slot_index + 1).ToStringLen(1);
			
			HideSelection( str_hide );
			ShowSelection( str_show );
		}		
		
		if ( slot.m_FertilizerType != "" )
		{
			SetSlotTextureFertilized( slot_index, slot.m_FertilizerType );
		}
		else 
		{
			SetSlotTextureDigged( slot_index );
		}
	}

	void SetSlotTextureDigged( int slot_index )
	{
		TStringArray textures = GetHiddenSelectionsTextures();
		
		string str_digged = SLOT_SELECTION_DIGGED_PREFIX + (slot_index + 1).ToStringLen(1);
		
		ShowSelection( str_digged );
		string texture = textures.Get(0);
		SetObjectTexture( slot_index, texture );
		
		Slot slot = m_Slots.Get( slot_index );
		
		if ( slot.NeedsWater() )
		{
			// Set dry material
			SetObjectMaterial ( slot_index, SLOT_MATERIAL_DRY );
		}
		else
		{
			// Set wet material
			SetObjectMaterial ( slot_index, SLOT_MATERIAL_WET );
		}
	}

	void SetSlotTextureFertilized( int slot_index, string item_type )
	{
		TStringArray textures = GetHiddenSelectionsTextures();
		
		int tex_id = GetGame().ConfigGetInt( "cfgVehicles " + item_type + " Horticulture TexId" );
		
		string str_show = SLOT_SELECTION_DIGGED_PREFIX + (slot_index + 1).ToStringLen(2);
		
		ShowSelection( str_show );
		SetObjectTexture( slot_index, textures.Get(tex_id) );
		
		Slot slot = m_Slots.Get( slot_index );
		
		int slot_index_offset = 0;
		
		// Set material according to dry / wet states
		if ( slot.NeedsWater() )
		{
			// Set dry material for garden lime
			if ( slot.m_FertilizerType == "GardenLime" )
			{
				SetObjectMaterial ( slot_index + slot_index_offset, SLOT_MATERIAL_LIMED_DRY ); 
			}
			else if ( slot.m_FertilizerType == "PlantMaterial" )
			{
				SetObjectMaterial ( slot_index + slot_index_offset, SLOT_MATERIAL_COMPOST_DRY ); 
			}
		}
		else
		{
			// Set dry material for compost
			if ( slot.m_FertilizerType == "GardenLime" )
			{
				SetObjectMaterial ( slot_index + slot_index_offset, SLOT_MATERIAL_LIMED_WET ); 
			}
			else if ( slot.m_FertilizerType == "PlantMaterial" )
			{
				SetObjectMaterial ( slot_index + slot_index_offset, SLOT_MATERIAL_COMPOST_WET );
			}
		}
	}
	
	void RemoveSlot( int index )
	{
		if ( m_Slots != NULL )
		{	
			Slot slot = m_Slots.Get( index );
			PlantBase plant = slot.GetPlant();
			
			if ( plant )
			{
				plant.m_MarkForDeletion = true;
				GetGame().ObjectDelete( plant );
			}
			
			slot.Init( GetBaseFertility() );
			
			HideSelection( SLOT_SELECTION_COVERED_PREFIX + (index + 1).ToStringLen(2) );
			UpdateSlotTexture( index );
		}
	}

	void RemoveSlotPlant( Object plant )
	{
		int index = GetSlotIndexByPlant( plant );
		if ( index >= 0 )
		{
			RemoveSlot( index );
		}
	}

	Slot GetSlotBySelection( string selection_component )
	{
		int slot_index = GetSlotIndexBySelection( selection_component );
		
		if ( slot_index > -1 )
		{
			return m_Slots.Get( slot_index );
		}
		else
		{
			return NULL;
		}
	}

	// Returns slot array index by selection, starting from 0 as the first one.
	int GetSlotIndexBySelection( string selection_component )
	{
		int slot_index = -1;
		
		if ( m_Slots != NULL )
		{
			string selection_component_lower = selection_component; 
			selection_component_lower.ToLower();
			
			string slot_component_prefix_lower = SLOT_MEMORY_POINT_PREFIX;
			slot_component_prefix_lower.ToLower();
			
			int start = selection_component_lower.IndexOf( slot_component_prefix_lower );
			
			if ( start > -1 )
			{
				start += SLOT_MEMORY_POINT_PREFIX.Length();
				int end = start + 2;
				int length = selection_component.Length();
				
				if ( length >= end )
				{
					int length_add = length - end; // Hack-fix for inconsistent component names in p3d
					int length_from_end = 2 + length_add;
					string num_str = selection_component.Substring( start, length_from_end );
					slot_index = num_str.ToInt();
					
					slot_index = slot_index - 1;
				}
			}
		}
		
		return slot_index;
	}
	
	int GetSlotIndexByAttachmentSlot( string att_slot )
	{
		int slot_index = -1;
		
		int start = "SeedBase_".Length();
		int end = start + 2;
		
		string num_str = att_slot.Substring( start, 1 );
		slot_index = num_str.ToInt();
		
		return slot_index;
	}

	int GetSlotIndexByPlant( Object plant )
	{
		if ( m_Slots != NULL )
		{
			for ( int i = 0; i < m_Slots.Count(); i++ )
			{
				PlantBase found_plant = m_Slots.Get(i).GetPlant();
				
				if ( found_plant == plant )
				{
					return i;
				}
			}
		}
		
		return -1;
	}
	
	int GetNearestSlotIDByState( vector position, int slot_state)
	{
		float nearest_distance = 1000.0;
		int nearest_slot_index = -1;
		//Print(slot_state);
		int slots_count = GetGardenSlotsCount();
		for ( int i = 0; i < slots_count; i++ )
		{
			//Print(i);
			Slot slot = m_Slots.Get(i); // Move this line by a scope higher in this function after debugging
			
			if (slot)
			{
				//Print(slot.m_State);
			}
			
			vector slot_pos = GetSlotPosition( i );
			float current_distance = vector.Distance( position, slot_pos );
			
			if ( current_distance < nearest_distance )
			{
				
				if ( slot != NULL && slot.m_State == slot_state )
				{
					nearest_distance = current_distance;
					nearest_slot_index = i;
				}
			}
		}
		
		return nearest_slot_index;
	}

	vector GetSlotPosition( int index )
	{
		string memory_point = SLOT_MEMORY_POINT_PREFIX + (index + 1).ToStringLen(2);
		vector pos = this.GetSelectionPositionMS( memory_point );
		
		return this.ModelToWorld( pos );
	}
	
	void CheckRainStart()
	{
		if ( !m_CheckRainTimer )
			m_CheckRainTimer = new Timer( CALL_CATEGORY_SYSTEM );
		
		m_CheckRainTimer.Run( CHECK_RAIN_INTERVAL, this, "CheckRainTick", NULL, true );
	}
	
	void CheckRainTick()
	{
		if (this)
		{
			float rain_intensity = GetGame().GetWeather().GetRain().GetActual();
			
			float wetness = rain_intensity * 20 * CHECK_RAIN_INTERVAL;
			
			if (rain_intensity > 1  ||  rain_intensity < 0)
				wetness = 0; // hackfix for weird values returned by weather system
			
			if (wetness == 0)
				wetness = -0.1 * CHECK_RAIN_INTERVAL;
			
			int slots_count = GetGardenSlotsCount();
			
			for ( int i = 0; i < slots_count; i++ )
			{
				if (m_Slots)
				{
					Slot slot = m_Slots.Get( i );
					
					if (slot)
					{
						PlantBase plant = slot.GetPlant();
						
						if (plant)
						{
							if (wetness>0)
								slot.GiveWater( wetness * Math.RandomFloat01() );
							
							plant.UpdatePlant();
						}
						else
						{
							slot.GiveWater( wetness * Math.RandomFloat01() );
						}
					}
				}
			}
		
		}
	}
	
	array<ref Slot> GetSlots()
	{
		return m_Slots;
	}
	
	Slot GetSlotByIndex( int index )
	{
		return m_Slots.Get(index);
	}
}