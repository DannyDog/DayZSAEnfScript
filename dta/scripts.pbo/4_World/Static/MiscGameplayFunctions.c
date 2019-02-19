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
			
			m_OldItem.ConfigGetTextArray("inventorySlot",inventory_slots);
			if (inventory_slots.Count() < 1) //is string
			{
				inventory_slots_idx.Insert(InventorySlots.GetSlotIdFromString(m_OldItem.ConfigGetString("inventorySlot")));
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
};

class TurnItemIntoItemLambdaAnimSysNotifyLambda extends TurnItemIntoItemLambda
{
	override void OnSuccess (EntityAI new_item)
	{
		super.OnSuccess(new_item);
		Human player = Human.Cast(m_Player);
		player.GetItemAccessor().OnItemInHandsChanged();
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
				child_dst.CopyLocationFrom(understash_src);
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

		if( transfer_health ) target_ib.SetHealth("", "", source.GetHealth("",""));
	}

	static void TransferItemVariables(ItemBase source, ItemBase target, bool exclude_quantity = false)
	{
		target.TransferVariablesFloat( source.GetVariablesFloat() );
		//target.TransferVariablesString( source.GetVariablesString() );
		if( exclude_quantity )
		{
			target.RemoveItemVariable(VARIABLE_QUANTITY);
		}
		else if( source.IsMagazine() && target.IsMagazine() )
		{
			Magazine source_mag = Magazine.Cast(source);
			Magazine target_mag = Magazine.Cast(target);
			
			target_mag.ServerSetAmmoCount( source_mag.GetAmmoCount() );
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

				if (GameInventory.LocationCanMoveEntity(child_src, child_dst))
				{
					// try to move it to the same exact place in dst
					player.LocalTakeToDst(child_src, child_dst);
					/*if (!GameInventory.LocationMoveEntity(child_src, child_dst))
					{
						Error("[inv] TransferInventory: Cannot move src to dst even if GameInventory.LocationCanMoveEntity allowed it");
						drop = true; // failed, drop
					}*/
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

	static array<ItemBase> CreateItemBasePiles(string item_name, vector ground_position, float quantity,  float health )
	{
		ref array<ItemBase>	items;
		float stack_size;
		ItemBase pile;
		
		items = new array<ItemBase>;
		stack_size = g_Game.ConfigGetInt("cfgVehicles " + item_name + " varQuantityMax");
		
		int piles_count = Math.Floor(quantity/stack_size);
		int rest = quantity - (piles_count*stack_size);
		
		for ( int i = 0; i < piles_count; i++ )
		{
			pile = ItemBase.Cast(GetGame().CreateObject(item_name, ground_position, false));
			pile.SetQuantity(stack_size);
			items.Insert(pile);
		}
		if ( rest > 0)
		{
			pile = ItemBase.Cast(GetGame().CreateObject(item_name, ground_position, false));
			pile.SetQuantity(rest);
			items.Insert(pile);
		}
		return items;
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
			pile = Magazine.Cast(GetGame().CreateObject(item_name, ground_position, false));
			pile.ServerSetAmmoCount(stack_size);
			items.Insert(pile);
		}
		if ( rest > 0)
		{
			pile = Magazine.Cast(GetGame().CreateObject(item_name, ground_position, false));
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
				pile = Magazine.Cast(GetGame().CreateObject(item_name, ground_position, false));
				pile.ServerSetAmmoCount(stack_size);
				items.Insert(pile);
			}
			if ( rest > 0)
			{
				pile = Magazine.Cast(GetGame().CreateObject(item_name, ground_position, false));
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

	static float GetHeadingAngle(notnull PlayerBase player)
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
	
};

class DestroyItemInCorpsesHandsAndCreateNewOnGndLambda : ReplaceAndDestroyLambda
{
	// @NOTE m_Player == target player - i.e. restrained one
	void DestroyItemInCorpsesHandsAndCreateNewOnGndLambda (EntityAI old_item, string new_item_type, PlayerBase player, bool destroy = false)
	{
		InventoryLocation gnd = new InventoryLocation;
		vector mtx[4];
		Math3D.MatrixIdentity4(mtx);
		mtx[3] = player.GetPosition();
		gnd.SetGround(NULL, mtx);
		OverrideNewLocation(gnd);
	}
	
	protected override void RemoveOldItemFromLocation ()
	{
		super.RemoveOldItemFromLocation();
		m_Player.GetHumanInventory().OnEntityInHandsDestroyed(m_OldItem);
	}
}
