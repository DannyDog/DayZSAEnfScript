class TurnItemIntoItemLambda extends ReplaceItemWithNewLambda
{
	bool m_TransferAgents;
	bool m_TransferVariables;
	bool m_TransferHealth;
	bool m_ExcludeQuantity;
	float m_quantity_override;
	
	void TurnItemIntoItemLambda (EntityAI old_item, string new_item_type, PlayerBase player)
	{
		SetTransferParams();
	}
	
	void SetTransferParams (bool transfer_agents = true, bool transfer_variables = true, bool transfer_health = true, bool exclude_quantity = false, float quantity_override = -1)
	{
		m_TransferAgents = transfer_agents;
		m_TransferVariables = transfer_variables; 
		m_TransferHealth = transfer_health;
		m_ExcludeQuantity = exclude_quantity;
		m_quantity_override = quantity_override;
	}

	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		if (new_item) 
		{
			MiscGameplayFunctions.TransferItemProperties(old_item, new_item, m_TransferAgents, m_TransferVariables, m_TransferHealth, m_ExcludeQuantity);
			MiscGameplayFunctions.TransferInventory(old_item, new_item, m_Player);
			
			//quantity override
			if (ItemBase.Cast(new_item) && m_quantity_override != -1)
			{
				m_quantity_override = Math.Max(m_quantity_override,0);
				ItemBase.Cast(new_item).SetQuantity(m_quantity_override);
			}
		}
		else
		{
			Debug.LogError("TurnItemIntoItemLambda: failed to create new item","static");
		}
	}
	
	//! if attaching from att.slot to att.slot, skips the change to "ground" version. Allows for correct property transfers.
	override void VerifyItemTypeBySlotType ()
	{
		if (m_NewLocation.GetType() == InventoryLocationType.ATTACHMENT && m_OldItem.ConfigIsExisting("ChangeIntoOnAttach"))
		{
			string str;
			int idx = -1;
			TStringArray inventory_slots = new TStringArray;
			TIntArray inventory_slots_idx = new TIntArray;
			TStringArray attach_types = new TStringArray;
			
			m_OldItem.ConfigGetTextArray("ChangeInventorySlot",inventory_slots);
			if (inventory_slots.Count() < 1) //is string
			{
				inventory_slots_idx.Insert(InventorySlots.GetSlotIdFromString(m_OldItem.ConfigGetString("ChangeInventorySlot")));
				attach_types.Insert(m_OldItem.ConfigGetString("ChangeIntoOnAttach"));
			}
			else //is array
			{
				inventory_slots_idx.Clear();
				for (int i = 0; i < inventory_slots.Count(); i++)
				{
					inventory_slots_idx.Insert(InventorySlots.GetSlotIdFromString(inventory_slots.Get(i)));
				}
				m_OldItem.ConfigGetTextArray("ChangeIntoOnAttach",attach_types);
			}
		
			idx = m_NewLocation.GetSlot();
			str = attach_types.Get(inventory_slots_idx.Find(idx));
			if (str != "")
			{
				m_NewItemType = str;
			}
		}
	}
	
	override void OnSuccess (EntityAI new_item)
	{
		super.OnSuccess(new_item);
		if( m_Player )
		{
			m_Player.GetItemAccessor().OnItemInHandsChanged();
		}
	}
};

class TurnItemIntoItemLambdaAnimSysNotifyLambda extends TurnItemIntoItemLambda
{
	override void OnSuccess (EntityAI new_item)
	{
		super.OnSuccess(new_item);
		if( m_Player )
		{
			m_Player.GetItemAccessor().OnItemInHandsChanged();
		}
	}
}

class TurnItemIntoItemLambdaRestrainLambda extends TurnItemIntoItemLambdaAnimSysNotifyLambda
{
	override void OnSuccess (EntityAI new_item)
	{
		super.OnSuccess(new_item);
		m_Player.SetRestrained(true);
	}
}

/**@class		DropEquipAndDestroyRootLambda
 * @brief		this one is a bit special: it drops all items and destroys the ex-root of the hierarchy
 **/
class DropEquipAndDestroyRootLambda : ReplaceItemWithNewLambdaBase
{
	PlayerBase m_Player;

	void DropEquipAndDestroyRootLambda (EntityAI old_item, string new_item_type, PlayerBase player)
	{
		m_Player = player;
	}
	
	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);
		
		InventoryLocation understash_src = m_NewLocation; // m_NewLocation is a backup of original old_item's src before the operation started
		
		array<EntityAI> children = new array<EntityAI>;
		old_item.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, children);
		int count = children.Count();
		for (int i = 0; i < count; i++)
		{
			EntityAI child = children.Get(i);
			if (child)
			{
				InventoryLocation child_src = new InventoryLocation;
				child.GetInventory().GetCurrentInventoryLocation(child_src);
				
				InventoryLocation child_dst = new InventoryLocation;
				child_dst.Copy(child_src);
				child_dst.CopyLocationFrom(understash_src, true);
				//@TODO: modify _dst with place on gnd?
				
				m_Player.LocalTakeToDst(child_src, child_dst);
												
				GetGame().RemoteObjectTreeCreate(child); // this forces server to send CreateVehicle Message to client. This is needed for preserving the appearance of network operations on client (so that DeleteObject(old) arrives before CreateVehicle(new)). @NOTE: this does not delete the object on server, only it's network representation.
			}
		}
	}
}

/**@class		MoveEquipToExistingItemAndDestroyOldRootLambda
 * @brief		this one is a also bit special: it moves all items to already existing item and destroys the ex-root of the hierarchy
 **/
class MoveEquipToExistingItemAndDestroyOldRootLambda : ReplaceItemWithNewLambdaBase
{
	PlayerBase m_Player;
	EntityAI m_NewItem;

	void MoveEquipToExistingItemAndDestroyOldRootLambda (EntityAI old_item, string new_item_type, PlayerBase player, EntityAI new_item)
	{
		m_Player = player;
		m_NewItem = new_item;
		if (new_item_type != string.Empty)
			Error("MoveEquipAndDestroyRootLambda expects new_item_type to be empty");
	}
	
	override protected void RemoveNetworkObjectInfo ()
	{
		super.RemoveNetworkObjectInfo();
		GetGame().RemoteObjectTreeDelete(m_NewItem);
	}
	override protected void UndoRemoveNetworkObjectInfo ()
	{
		super.UndoRemoveNetworkObjectInfo();
		GetGame().RemoteObjectTreeCreate(m_NewItem);
	}
	
	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		// @NOTE: new_item is NULL, this lambda does not create new entity
		super.CopyOldPropertiesToNew(old_item, new_item);
		
		MiscGameplayFunctions.TransferInventory(old_item, m_NewItem, m_Player);		
	}
	
	override protected void CreateNetworkObjectInfo (EntityAI new_item)
	{
		super.CreateNetworkObjectInfo(new_item);
		GetGame().RemoteObjectTreeCreate(m_NewItem);
	}
};

enum TransferInventoryResult
{
	Ok, DroppedSome
};

class MiscGameplayFunctions
{	
	//! Produces ACII "progress bar" based on an 0..1 'value' input
	static string ValueToBar(float value, string bar = "[----------]", string mark = "x")
	{
		int length = bar.Length() - 2;
		float index = Math.Lerp(0,length, value);
		index = Math.Round(index);
		index = Math.Clamp(index,0,length);
		
		return InsertAtPos(bar,mark,index);
	}
	
	//! Insert 'insert' behind index 'pos' of the 'base' string
	static string InsertAtPos(string base, string insert, int pos)
	{
		int length_first = pos+1;
		int length_base = base.Length();
		int length_second = length_base - length_first;
		string first = base.Substring(0,length_first);
		string second = base.Substring(pos+1,length_second);
		return first + insert + second;
	}
	
	//! will transform item' variables, agents and other local scripted properties as well as any relevant non-scripted properties like health
	static void TransferItemProperties(EntityAI source, notnull EntityAI target, bool transfer_agents = true, bool transfer_variables = true, bool transfer_health = true, bool exclude_quantity = false)
	{
		ItemBase target_ib = ItemBase.Cast(target);
		ItemBase source_ib = ItemBase.Cast(source);
		
		if( transfer_agents ) target_ib.TransferAgents( source.GetAgents() );
		
		if( transfer_variables )
		{
			MiscGameplayFunctions.TransferItemVariables(source_ib, target_ib, exclude_quantity);
		}

		if( !GetGame().IsClient())
		{
			//if( transfer_health ) target_ib.SetHealth("", "", source.GetHealth("",""));
			target_ib.SetHealth("", "", source.GetHealth01("","") * target_ib.GetMaxHealth("",""));
		}
	}

	static void TransferItemVariables(ItemBase source, ItemBase target, bool exclude_quantity = false)
	{
		target.TransferVariablesFloat( source.GetVariablesFloat() );
		//target.TransferVariablesString( source.GetVariablesString() );
		if ( exclude_quantity )
		{
			target.RemoveItemVariable(VARIABLE_QUANTITY);
		}
		else if ( source.IsMagazine() && target.IsMagazine() )
		{
			Magazine source_mag = Magazine.Cast(source);
			Magazine target_mag = Magazine.Cast(target);
			
			target_mag.ServerSetAmmoCount( source_mag.GetAmmoCount() );
		}
		else if ( source.IsWeapon() && target.IsWeapon() )
		{
			Weapon_Base source_wpn = Weapon_Base.Cast(source);
			Weapon_Base target_wpn = Weapon_Base.Cast(target);
			
			target_wpn.CopyWeaponStateFrom(source_wpn);
		}
		else if ( source.HasEnergyManager() && target.HasEnergyManager() )
		{
			target.GetCompEM().SetEnergy(source.GetCompEM().GetEnergy());

			if (source.GetCompEM().IsSwitchedOn())
				target.GetCompEM().SwitchOn();
		}
	}

	static TransferInventoryResult TransferInventory( EntityAI sourceItem, EntityAI targetItem, PlayerBase player)
	{
		TransferInventoryResult result = TransferInventoryResult.Ok;

		array<EntityAI> children = new array<EntityAI>;
		sourceItem.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, children);
		int count = children.Count();
		for (int i = 0; i < count; i++)
		{
			EntityAI child = children.Get(i);
			if (child)
			{
				InventoryLocation child_src = new InventoryLocation;
				child.GetInventory().GetCurrentInventoryLocation( child_src );
				
				InventoryLocation child_dst = new InventoryLocation;
				child_dst.Copy( child_src );
				child_dst.SetParent( targetItem );

				bool drop = false;

				if (GameInventory.LocationCanAddEntity(child_dst))
				{
					// try to move it to the same exact place in dst
					targetItem.GetInventory().TakeToDst(InventoryMode.LOCAL, child_src, child_dst);
				}
				else
				{
					drop = true; // or drop otherwise
				}

				if (drop)
				{
					player.LocalDropEntity(child);
					GetGame().RemoteObjectTreeCreate(child);
					result = TransferInventoryResult.DroppedSome;
				}
			}
		}
		return result;
	}
	
	static void UnlimitedAmmoDebugCheck(Weapon_Base weapon)
	{
		if ( ItemBase.GetDebugActionsMask() & DebugActionType.UNLIMITED_AMMO )
		{
			Magazine magazine;
			if ( GetGame().IsServer() )
			{
				magazine = weapon.GetMagazine(weapon.GetCurrentMuzzle());
			
				if(magazine)
				{
					if (magazine.GetAmmoCount() <= 5)
					{
						magazine.ServerSetAmmoMax();
					}
				}
			}
			else
			{
				magazine = weapon.GetMagazine(weapon.GetCurrentMuzzle());
			
				if(magazine)
				{
					if (magazine.GetAmmoCount() <= 5)
					{
						magazine.LocalSetAmmoMax();
					}
				}
			
			}
		}
	}
	

		
	static void TurnItemIntoItem (notnull ItemBase old_item, string new_item_type, notnull PlayerBase player)
	{
		TurnItemIntoItemEx(player, new TurnItemIntoItemLambda(old_item, new_item_type, player));
	}
		
	static void TurnItemIntoItemEx (notnull PlayerBase player, ReplaceItemWithNewLambdaBase lambda)
	{
		player.ServerReplaceItemWithNew(lambda);
	}

	static void TurnItemInHandsIntoItem (notnull ItemBase old_item, string new_item_type, notnull PlayerBase player)
	{
		TurnItemInHandsIntoItemEx(player, new TurnItemIntoItemLambda(old_item, new_item_type, player));
	}
	
	static void TurnItemInHandsIntoItemEx (notnull PlayerBase player, ReplaceItemWithNewLambdaBase lambda)
	{
		player.ServerReplaceItemInHandsWithNew(lambda);
	}

	//!Spawns multiple piles of stackable ItemBase objects on ground (intended for generic use)
	static array<ItemBase> CreateItemBasePiles(string item_name, vector ground_position, float quantity, float health, bool floaty_spawn = false)
	{
		ref array<ItemBase>	item_piles;
		float max_stack_size;
		ItemBase pile;
		
		item_piles = new array<ItemBase>;
		max_stack_size = g_Game.ConfigGetInt("cfgVehicles " + item_name + " varStackMax");
		if( max_stack_size < 1)
			max_stack_size = g_Game.ConfigGetInt("cfgVehicles " + item_name + " varQuantityMax");
		if( max_stack_size < 1)
			max_stack_size = 1;
		
		int full_piles_count = Math.Floor(quantity/max_stack_size);
		int rest = quantity - (full_piles_count*max_stack_size);
		
		for ( int i = 0; i < full_piles_count; i++ )
		{
			if (floaty_spawn)
				pile = ItemBase.Cast(GetGame().CreateObjectEx(item_name, ground_position, ECE_CREATEPHYSICS|ECE_UPDATEPATHGRAPH));
			else
				pile = ItemBase.Cast(GetGame().CreateObjectEx(item_name, ground_position, ECE_PLACE_ON_SURFACE));
			pile.SetQuantity(max_stack_size);
			pile.SetHealth(health);
			item_piles.Insert(pile);
		}
		if ( rest > 0 )
		{
			if (floaty_spawn)
				pile = ItemBase.Cast(GetGame().CreateObjectEx(item_name, ground_position, ECE_CREATEPHYSICS|ECE_UPDATEPATHGRAPH));
			else
				pile = ItemBase.Cast(GetGame().CreateObjectEx(item_name, ground_position, ECE_PLACE_ON_SURFACE));
			pile.SetQuantity(rest);
			pile.SetHealth(health);
			item_piles.Insert(pile);
		}
		return item_piles;
	}
	
	static array<Magazine> CreateMagazinePiles(string item_name, vector ground_position, float quantity,  float health )
	{
		ref array<Magazine>	items;
		float stack_size;
		Magazine pile;
		
		items = new array<Magazine>;
		stack_size = g_Game.ConfigGetInt("cfgMagazines " + item_name + " count");
		
		int piles_count = Math.Floor(quantity/stack_size);
		int rest = quantity - (piles_count*stack_size);
		
		for ( int i = 0; i < piles_count; i++ )
		{
			pile = Magazine.Cast(GetGame().CreateObjectEx(item_name, ground_position, ECE_PLACE_ON_SURFACE));
			pile.ServerSetAmmoCount(stack_size);
			items.Insert(pile);
		}
		if ( rest > 0)
		{
			pile = Magazine.Cast(GetGame().CreateObjectEx(item_name, ground_position, ECE_PLACE_ON_SURFACE));
			pile.ServerSetAmmoCount(rest);
			items.Insert(pile);
		}
		return items;
	}
	
	static array<Magazine> CreateMagazinePilesFromBullet(string bullet_type, vector ground_position, float quantity,  float health )
	{
		ref array<Magazine>	items;
		items = new array<Magazine>;
		float stack_size;
		Magazine pile;
		string item_name;
		if( !g_Game.ConfigGetText("cfgAmmo " + bullet_type + " spawnPileType", item_name) )
			return items;
		
		stack_size = g_Game.ConfigGetInt("cfgMagazines " + item_name + " count");
		
		if(stack_size > 0)
		{
			int piles_count = Math.Floor(quantity/stack_size);
			int rest = quantity - (piles_count*stack_size);
		
			for ( int i = 0; i < piles_count; i++ )
			{
				pile = Magazine.Cast(GetGame().CreateObjectEx(item_name, ground_position, ECE_PLACE_ON_SURFACE));
				pile.ServerSetAmmoCount(stack_size);
				items.Insert(pile);
			}
			if ( rest > 0)
			{
				pile = Magazine.Cast(GetGame().CreateObjectEx(item_name, ground_position, ECE_PLACE_ON_SURFACE));
				pile.ServerSetAmmoCount(rest);
				items.Insert(pile);
			}
		}
		return items;
	}
	
	static int GetHealthLevelForAmmo(string class_name, float health)
	{
		float health_normalized = health / 100;
		string config_path = CFG_WEAPONSPATH + " " + class_name + " DamageSystem" + " GlobalHealth" + " healthLabels";
		CachedObjectsArrays.ARRAY_FLOAT.Clear();
		GetGame().ConfigGetFloatArray(config_path, CachedObjectsArrays.ARRAY_FLOAT);
		for(int i = 0; i < CachedObjectsArrays.ARRAY_FLOAT.Count(); i++)
		{
			if( health_normalized >= CachedObjectsArrays.ARRAY_FLOAT.Get(i) )
			{
				return i;
			}
		}
		return -1;
	}
	
	static float GetTypeMaxGlobalHealth(string class_name, string health_type = "Health")
	{
		float max_health;
		string cfg_path;
		
		if ( GetGame().ConfigIsExisting(CFG_VEHICLESPATH+" "+class_name) )
		{
			cfg_path = CFG_VEHICLESPATH;
		}
		else if ( GetGame().ConfigIsExisting(CFG_WEAPONSPATH+" "+class_name) )
		{
			cfg_path = CFG_WEAPONSPATH;
		}
		else if ( GetGame().ConfigIsExisting(CFG_MAGAZINESPATH+" "+class_name) )
		{
			cfg_path = CFG_MAGAZINESPATH;
		}
		cfg_path = cfg_path + " "+class_name+" DamageSystem GlobalHealth " + health_type + " hitpoints";
		max_health = GetGame().ConfigGetFloat(cfg_path);
		
		return max_health;
	}
	
	static bool GetProjectedCursorPos3d (out vector position, Weapon_Base weapon)
	{
		vector usti_hlavne_position = weapon.GetSelectionPositionMS( "usti hlavne" );
		vector konec_hlavne_position = weapon.GetSelectionPositionMS( "konec hlavne" );
		vector end_point = weapon.ModelToWorld(usti_hlavne_position);
		vector begin_point = weapon.ModelToWorld(konec_hlavne_position);
		vector contact_dir;
		int contact_component;
		
		vector aim_point = end_point - begin_point;
		aim_point = aim_point.Normalized() * PROJECTED_CURSOR_DISTANCE;
		aim_point = aim_point + end_point;
		
		if (DayZPhysics.RaycastRV(begin_point, aim_point, position, contact_dir, contact_component, null, null, null, false, false, ObjIntersectFire))
			return true;
		return false;
	}
	
	static void GetHeadBonePos(notnull PlayerBase player, out vector pos)
	{
		// Get position of head for starting trace pos, otherwise use sane default
		int headBoneIdx = player.GetBoneIndexByName("Head");
		if ( headBoneIdx == -1 )
			{ pos = player.GetPosition()[1] + 1.6; }
		else
			{ pos = player.GetBonePositionWS(headBoneIdx); }	
	}

	static vector GetHeadingVector(notnull PlayerBase player)
	{
		vector dir = vector.Zero;
		float headingAngle = GetHeadingAngle(player);
		dir[0] = Math.Cos(headingAngle + Math.PI_HALF);
		dir[2] = Math.Sin(headingAngle + Math.PI_HALF);
		
		return dir.Normalized();
	}

	static float GetHeadingAngle(notnull DayZPlayerImplement player)
	{
		HumanInputController hic = player.GetInputController();
		float headingAngle = hic.GetHeadingAngle();
		
		return headingAngle;
	}
	
	static float GetEnergyMetabolicSpeed(int movement_speed)
	{
		float speed;
		//PrintString(movement_speed.ToString());
		switch (movement_speed)
		{
			case 1:
			{
				speed = PlayerConstants.METABOLIC_SPEED_ENERGY_WALK;
				break;
			}
			case 2:
			{
				speed = PlayerConstants.METABOLIC_SPEED_ENERGY_JOG;
				break;
			}
			case 3:
			{
				speed = PlayerConstants.METABOLIC_SPEED_ENERGY_SPRINT;
				break;
			}
			default:
			{
				speed = 0;
				break;
			}
		}
		speed += PlayerConstants.METABOLIC_SPEED_ENERGY_BASAL;
		return speed;
	}
	
	static float GetWaterMetabolicSpeed(int movement_speed)
	{
		float speed;
		switch (movement_speed)
		{
			case 1:
			{
				speed = PlayerConstants.METABOLIC_SPEED_WATER_WALK;
				break;
			}
			case 2:
			{
				speed = PlayerConstants.METABOLIC_SPEED_WATER_JOG;
				break;
			}
			case 3:
			{
				speed = PlayerConstants.METABOLIC_SPEED_WATER_SPRINT;
				break;
			}
			default:
			{
				speed = 0;
				break;
			}
		}
		speed += PlayerConstants.METABOLIC_SPEED_WATER_BASAL;
		return speed;
	}
	
	static string ObtainRestrainItemTargetClassname(notnull EntityAI entity)
	{
		return entity.ConfigGetString( "OnRestrainChange");
	}
	
	static void TransformRestrainItem(EntityAI current_item, EntityAI tool, PlayerBase player_source, PlayerBase player_target, bool destroy = false)
	{
		bool type;
		
		if( tool )
		{
			//is unrestrain and not struggle
			type = tool.ConfigGetBool("RestrainUnlockType");
		}
		string new_item_name = current_item.ConfigGetString( "OnRestrainChange");
		
		if( new_item_name != "" )
		{
			if( player_target )
			{
				if (player_target.IsAlive())
					MiscGameplayFunctions.TurnItemIntoItemEx(player_target, new ReplaceAndDestroyLambda(current_item, new_item_name, player_target, type));
				else
					MiscGameplayFunctions.TurnItemIntoItemEx(player_source, new DestroyItemInCorpsesHandsAndCreateNewOnGndLambda(current_item, new_item_name, player_target, type));
			}
			else
			{
				MiscGameplayFunctions.TurnItemIntoItemEx(player_target, new ReplaceAndDestroyLambda(current_item, new_item_name, player_target, type));
			}
		}
		else
		{
			Error("current_item:" +current_item+ ", tool:" +tool +". No value for 'OnRestrainChange' config parameter");
		}
	}
	
	static bool IsValueInRange(float value, float from, float to)
	{
		return (value >= from) && (value <= to);
	}

	//! Check if player direction(based on cone of defined angle) is oriented to target position
	static bool IsPlayerOrientedTowardPos(notnull DayZPlayerImplement player, vector target_pos, float cone_angle)
	{
		if(player)
		{
			vector player_dir = player.GetDirection();
			vector to_target_dir = target_pos - player.GetPosition();
	
			player_dir[1] = 0;
			to_target_dir[1] = 0;
		
			player_dir.Normalize();
			to_target_dir.Normalize();
		
			float cos_fi = vector.Dot(player_dir, to_target_dir);
			vector cross = player_dir * to_target_dir;
		
			int dir = Math.Acos(cos_fi) * Math.RAD2DEG;
				
			if( cross[1] < 0 )
				dir = -dir;

			//! dir in cone or in a tip of cone 
			if( (dir <= cone_angle && dir >= -cone_angle) || Math.AbsFloat(dir) == 90 )
			{
				return true;
			}
		}
		
		return false;
	}
	
	//TODO
	static string SanitizeString(string input)
	{
		int max_length = 512;
		string output = input;
		
		output = output.Substring(0,Math.Clamp(max_length,0,output.Length()));
		return output;
	}
	
	static bool ComplexBuildCollideCheckClient( PlayerBase player, ActionTarget target, ItemBase item, string partName = "" )
	{
		BaseBuildingBase base_building = BaseBuildingBase.Cast( target.GetObject() );
		if (base_building)
		{
			Construction construction = base_building.GetConstruction();
			if (construction && BuildCondition( player, target, item, false ))
			{
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				if (partName == "")
					partName = construction_action_data.GetCurrentBuildPart().GetPartName();
				return !construction.IsColliding( partName );
			}
		}
		return false;
	}
	
	static bool BuildCondition( PlayerBase player, ActionTarget target, ItemBase item, bool camera_check )
	{	
		if ( player && !player.IsLeaning() )
		{
			Object targetObject = target.GetObject();
			if ( targetObject && targetObject.CanUseConstruction() )
			{
				BaseBuildingBase base_building = BaseBuildingBase.Cast( targetObject );
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				construction_action_data.SetTarget( targetObject );
				
				string main_part_name = targetObject.GetActionComponentName( target.GetComponentIndex() );
				
				if ( GetGame().IsMultiplayer() || GetGame().IsServer() )
				{
					construction_action_data.RefreshPartsToBuild( main_part_name, item, !targetObject.CanUseHandConstruction() );
				}
				ConstructionPart constrution_part = construction_action_data.GetCurrentBuildPart();
	
				//Debug
				/*
				if ( constrution_part )
				{
					Construction construction = base_building.GetConstruction();	
					construction.IsColliding( constrution_part.GetPartName() );
				}
				*/

				if ( constrution_part )
				{
					//camera and position checks
					bool position_check = ( base_building.MustBeBuiltFromOutside() && !base_building.IsPlayerInside(player, constrution_part.GetMainPartName()) ) || ( !base_building.MustBeBuiltFromOutside() && base_building.IsPlayerInside(player, constrution_part.GetMainPartName()) );
					if ( position_check && !player.GetInputController().CameraIsFreeLook() )
					{
						//Camera check (client-only)
						if ( camera_check )
						{
							if ( GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
							{
								return !base_building.IsFacingCamera( constrution_part.GetMainPartName() );
							}
						}
						
						return true;
					}
				}
			}
		}
		
		return false;
	}
	
	static void IsUnderRoofFromToCalculation(EntityAI entity, out vector from, out vector to, float height = GameConstants.ROOF_CHECK_RAYCAST_DIST)
	{
		vector minMax[2];
		entity.GetCollisionBox(minMax);
		/*if (!entity.GetCollisionBox(minMax))
		{
			Print("IsUnderRoof | GetCollisionBox");
		}*/

		vector size = Vector(0,0,0);
		size[1] = minMax[1][1] - minMax[0][1];

		from = entity.GetPosition() + size;  
		vector ceiling = "0 0 0";
		ceiling[1] = height;
		if ( entity.HeightCheckOverride() > 0 )
		{
			to = entity.GetPosition() + Vector(0, entity.HeightCheckOverride(), 0);
		}
		else
		{
			to = from + ceiling;
		}
	}
	
	static bool IsUnderRoof(EntityAI entity, float height = GameConstants.ROOF_CHECK_RAYCAST_DIST) 
	{
		return IsUnderRoofEx(entity, height, ObjIntersectView);
	}
	
	static bool IsUnderRoofEx(EntityAI entity, float height = GameConstants.ROOF_CHECK_RAYCAST_DIST, int geometry = ObjIntersectView) 
	{
		vector from;  
		vector to;
		
		IsUnderRoofFromToCalculation(entity, from, to, height);

		vector contact_pos;
		vector contact_dir;

		int contact_component;
		//set<Object> hit_object = new set<Object>;
		bool boo = DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, /*hit_object*/NULL, NULL, entity, false, false, geometry,0.25 );
		
		/*if (boo)
		{
			Debug.DrawSphere(from , 0.8,Colors.YELLOW, ShapeFlags.ONCE);
			Debug.DrawSphere(to , 0.8,Colors.RED, ShapeFlags.ONCE);
		}
		else
		{
			Debug.DrawSphere(from , 0.8,Colors.GREEN, ShapeFlags.ONCE);
			Debug.DrawSphere(to , 0.8,Colors.RED, ShapeFlags.ONCE);
		}*/
		
		return boo;
	}

	// cooking equipment effects (get position for steam particle)
	static vector GetSteamPosition( EntityAI parent )
	{
		vector particle_pos;
		float steam_offset = 0;
		
		if ( parent )
		{
			particle_pos = parent.GetPosition();
			
			if ( parent.IsInherited( PortableGasStove ) )
			{
				steam_offset = 0.2;
			}
			else if ( parent.IsInherited( FireplaceBase ) )
			{
				FireplaceBase fireplace = FireplaceBase.Cast( parent );
				
				if ( fireplace.IsBaseFireplace() )
				{
					steam_offset = 0.8;
				}
				else if ( fireplace.IsBarrelWithHoles() )
				{
					steam_offset = 1.1;
				}
				else if ( fireplace.IsFireplaceIndoor() )
				{
					steam_offset = 0.45;
				}
				else if ( fireplace.IsIndoorOven() )
				{
					steam_offset = 0.9;
				}
			}
		}
		
		particle_pos[1] = particle_pos[1] + steam_offset;
		
		return particle_pos;
	}
	
	static void DropAllItemsInInventoryInBounds(ItemBase ib, vector halfExtents)
	{
		array<EntityAI> items = new array<EntityAI>;
		ib.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, items);
		
		vector direction = ib.GetDirection();
		float dot = vector.Dot(direction, vector.Forward);
		
		float angle = Math.Acos(dot);	
		if (direction[0] < 0)
			angle = -angle;	

		float cos = Math.Cos(angle);
		float sin = Math.Sin(angle);
		
		EntityAI item;
		int count = items.Count();
		for ( int i = 0; i < count; ++i )
		{
			item = items.Get(i);
			if ( item )
				ib.GetInventory().DropEntityInBounds(InventoryMode.SERVER, ib, item, halfExtents, angle, cos, sin);					
		}
	}

	static float GetCurrentItemHeatIsolation( ItemBase pItem )
	{
		float wetFactor;
		float healthFactor;

		float heatIsolation = pItem.GetHeatIsolation(); 	//! item heat isolation (from cfg)
		float itemHealthLabel = pItem.GetHealthLevel();		//! item health (state)
		float itemWetness = pItem.GetWet();					//! item wetness
		
		//! wet factor selection
		if ( itemWetness >= GameConstants.STATE_DRY && itemWetness < GameConstants.STATE_DAMP )
		{
			wetFactor = GameConstants.ENVIRO_ISOLATION_WETFACTOR_DRY;
		}
		else if ( itemWetness >= GameConstants.STATE_DAMP && itemWetness < GameConstants.STATE_WET )
		{
			wetFactor = GameConstants.ENVIRO_ISOLATION_WETFACTOR_DAMP;
		}
		else if ( itemWetness >= GameConstants.STATE_WET && itemWetness < GameConstants.STATE_SOAKING_WET )
		{
			wetFactor = GameConstants.ENVIRO_ISOLATION_WETFACTOR_WET;
		}
		else if ( itemWetness >= GameConstants.STATE_SOAKING_WET && itemWetness < GameConstants.STATE_DRENCHED )
		{
			wetFactor = GameConstants.ENVIRO_ISOLATION_WETFACTOR_SOAKED;
		}
		else if ( itemWetness >= GameConstants.STATE_DRENCHED )
		{
			wetFactor = GameConstants.ENVIRO_ISOLATION_WETFACTOR_DRENCHED;
		}
		
		//! health factor selection
		switch (itemHealthLabel)
		{
			case GameConstants.STATE_PRISTINE:
				healthFactor = GameConstants.ENVIRO_ISOLATION_HEALTHFACTOR_PRISTINE;
			break;
			
			case GameConstants.STATE_WORN:
				healthFactor = GameConstants.ENVIRO_ISOLATION_HEALTHFACTOR_WORN;
			break;
			
			case GameConstants.STATE_DAMAGED:
				healthFactor = GameConstants.ENVIRO_ISOLATION_HEALTHFACTOR_DAMAGED;
			break;
			
			case GameConstants.STATE_BADLY_DAMAGED:
				healthFactor = GameConstants.ENVIRO_ISOLATION_HEALTHFACTOR_B_DAMAGED;
			break;
			
			case GameConstants.STATE_RUINED:
				healthFactor = GameConstants.ENVIRO_ISOLATION_HEALTHFACTOR_RUINED;
			break;
		}
		
		//! apply fatctors
		heatIsolation *= healthFactor;
		heatIsolation *= wetFactor;

		return heatIsolation;
	}
	static bool IsObjectObstructed(Object object, bool doDistanceCheck = false, vector distanceCheckPos = "0 0 0", float maxDist = 0)
	{
		if (!object)
			return true;
		
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (doDistanceCheck && vector.DistanceSq(player.GetPosition(), distanceCheckPos) > maxDist * maxDist)
			return true;
		
		bool is_obstructed = false;
		vector object_center_pos;
		vector object_contact_pos;
		vector object_contact_dir;
		vector raycast_start;
		int contact_component;
		array<ref RaycastRVResult> hit_proxy_objects = new array<ref RaycastRVResult>;	
		set<Object> hit_objects = new set<Object>;
		EntityAI entity_ai;
		
		Class.CastTo( entity_ai, object );
				
		if ( object.MemoryPointExists("ce_center") )
		{
			//Print("CE_CENTER found");
			vector modelPos = object.GetMemoryPointPos("ce_center");
			object_center_pos = object.ModelToWorld(modelPos);
		}
		else if ( entity_ai && entity_ai.IsMan() )
		{
			//Print("NA HRACovi getujem pelvis");
			PlayerBase vicinity_player = PlayerBase.Cast( entity_ai );
			if ( vicinity_player )
			{
				int bone_index_player = vicinity_player.GetBoneIndexByName( "spine3" );
				object_center_pos = vicinity_player.GetBonePositionWS( bone_index_player );
			}
		}
		else if ( entity_ai && (entity_ai.IsZombie() || entity_ai.IsZombieMilitary()) )
		{
			//Print("NA INFECTEDovi getujem pelvis");
			ZombieBase vicinity_zombie = ZombieBase.Cast( entity_ai );
			if ( vicinity_zombie )
			{
				int bone_index_zombie = vicinity_zombie.GetBoneIndexByName( "spine3" );
				object_center_pos = vicinity_zombie.GetBonePositionWS( bone_index_zombie );
			}
		}
		else
		{
			//Print("CE_CENTER DOING A BAMBOOZLE => not found");
			object_center_pos = object.GetPosition();
			object_center_pos[1] = object_center_pos[1] + 0.2;
		}
			
		//Print("-->raycast from player to: " + object);
		MiscGameplayFunctions.GetHeadBonePos( PlayerBase.Cast( GetGame().GetPlayer() ), raycast_start);
		//DebugRaycastDraw( raycast_start, object_center_pos );
			
		if ( object.HasProxyParts() || object.CanUseConstruction() )
		{
			//Print(" :) (: pouzij proxy raycast koli proxy itemom :) (: ");
			RaycastRVParams ray_input = new RaycastRVParams( raycast_start, object_center_pos, player );
			DayZPhysics.RaycastRVProxy( ray_input, hit_proxy_objects );
				
			if ( hit_proxy_objects )
			{
				//Print(" - hit_proxy_objects - ");
				if ( hit_proxy_objects.Count() > 0 )
				{
					if ( hit_proxy_objects[0].hierLevel > 0 )
					{
						// ignores attachments on player
						if ( !hit_proxy_objects[0].parent.IsMan() )
						{
							//Print( "hit_proxy_objects[0].obj " + hit_proxy_objects[0].obj );
							//Print( "hit_proxy_objects[0].parent" + hit_proxy_objects[0].parent );
								
							if ( hit_proxy_objects[0].parent )
							{
								EntityAI proxy_parent = EntityAI.Cast( hit_proxy_objects[0].parent );
								if ( proxy_parent.GetInventory() && proxy_parent.GetInventory().GetCargo() )
								{	
									is_obstructed = true;
								}
								else
								{
									is_obstructed = false;
								}
							}
						}	
					}
				}
			}
		}
		if ( hit_objects ) 
			hit_objects.Clear();
				
		//Print(" ===>>> pouzij standardny raycast s fire geometriou koli domom a basebuildingu <<<=== ");
		DayZPhysics.RaycastRV( raycast_start, object_center_pos, object_contact_pos, object_contact_dir, contact_component, hit_objects, null, GetGame().GetPlayer(), false, false, ObjIntersectFire, 0.0, CollisionFlags.ALLOBJECTS );
				
		//4.2. ignore items if they are obstructed
		for ( int m = 0; m < hit_objects.Count(); m++ )
		{
			Object hit_object = hit_objects.Get(m);
				
			//Print("-->>pocas raycastu hitujem: " + hit_object);
				
			if ( hit_object.IsBuilding() )
			{
				//Print("!!!!!obstacle building: " + hit_object);
				is_obstructed = true;
			}
	
			if ( hit_object.IsPlainObject()/* && !ItemBase.Cast(hit_object)*/ )
			{
				//Print("!!!!!obstacle plain object: " + hit_object);
				is_obstructed = true;
			}
				
			if ( hit_object.IsInherited(BaseBuildingBase) )
			{
				if (object != hit_object)
					is_obstructed = true;
			} 
				
			//4.3. ignore item if items are big and heavy >= OBJECT_OBSTRUCTION_WEIGHT 
			/*EntityAI eai;
			if ( Class.CastTo( eai, hit_object ) )
			{
					
				if ( eai.GetWeight() >= OBJECT_OBSTRUCTION_WEIGHT )
				{
					if ( eai != filtered_object && eai.GetHierarchyRoot() != filtered_object )
					{
						//Print("!!!!!obstacle vaha: " + hit_object);
						is_obstructed = true;
					}
				}
			}*/
		}
			
		return is_obstructed;
	}
	
	//Inflict absolute damage to item (used on tools when completing actions)
	static void DealAbsoluteDmg(ItemBase item, float dmg)
	{
		float totalDmg = dmg;
		//Print("The damage dealt is : " + totalDmg);
		item.DecreaseHealth(totalDmg, false);
		//Print("Current health of item is : " + item.GetHealth());
	}
	
	//Function used to normailze values, enter the used value and the max value (max will become 1)
	static float Normalize(int val, int maxVal)
	{
		float normVal;
		if (maxVal == 0)
		{
			Debug.LogError("Division by 0 is not allowed");
			return 0;
		}
		
		normVal = val / maxVal;
		return normVal;
	}
	
	static float Bobbing(float period, float amplitude, float elapsedTime)
	{
		//Prevent division by 0
		if ( period == 0 )
			period = 1;
		
		elapsedTime /= period;
		
		float cycle;
		cycle += elapsedTime;
		cycle = FModulus(cycle, 360);
		cycle = Math.Sin(cycle) * amplitude;
		
		return cycle;
	}
	
	static float FModulus(float x, float y)
	{
		float res;
		//Prevent division by 0
		if (y == 0)
			y = 1;
		
		int n = Math.Floor(x/y);
		res = x - n * y;
		return res;
	}
	
	static void RemoveSplint( PlayerBase player )
	{
		EntityAI entity = player.GetInventory().CreateInInventory("Splint");
		EntityAI attachment;
		ItemBase new_item = ItemBase.Cast(entity);
		Class.CastTo(attachment, player.GetItemOnSlot("Splint_Right"));
		if ( attachment && attachment.GetType() == "Splint_Applied" )
		{
			if (new_item)
			{
				MiscGameplayFunctions.TransferItemProperties(attachment,new_item);
				
				if (GetGame().IsServer())
				{
					//Lower health level of splint after use
					if (new_item.GetHealthLevel() < 4)
					{
						int newDmgLevel = new_item.GetHealthLevel() + 1;
						
						float max = new_item.GetMaxHealth("","");
						
						switch ( newDmgLevel )
						{
							case GameConstants.STATE_BADLY_DAMAGED:
								new_item.SetHealth( "", "", max * GameConstants.DAMAGE_BADLY_DAMAGED_VALUE );
								break;
		
							case GameConstants.STATE_DAMAGED:
								new_item.SetHealth( "", "", max * GameConstants.DAMAGE_DAMAGED_VALUE );
								break;
		
							case GameConstants.STATE_WORN:
								new_item.SetHealth( "", "", max * GameConstants.DAMAGE_WORN_VALUE );
								break;
							
							case GameConstants.STATE_RUINED:
								new_item.SetHealth( "", "", max * GameConstants.DAMAGE_RUINED_VALUE );
								break;
							
							default:
								break;
						}
					}
				}
			}
			
			attachment.Delete();
		}
	}
};

class DestroyItemInCorpsesHandsAndCreateNewOnGndLambda : ReplaceAndDestroyLambda
{
	// @NOTE m_Player == target player - i.e. restrained one
	void DestroyItemInCorpsesHandsAndCreateNewOnGndLambda (EntityAI old_item, string new_item_type, PlayerBase player, bool destroy = false)
	{
		InventoryLocation gnd = new InventoryLocation;
		vector mtx[4];
		if (old_item)
			old_item.GetTransform(mtx);
		else
			player.GetTransform(mtx);
		gnd.SetGround(NULL, mtx);
		OverrideNewLocation(gnd);
	}
	
	protected override void RemoveOldItemFromLocation ()
	{
		super.RemoveOldItemFromLocation();
		m_Player.GetHumanInventory().OnEntityInHandsDestroyed(m_OldLocation);
	}
}