class AnalyticsManagerClient
{
	static const int GEAR_COUNT = 3; 
	static string m_FullGear[GEAR_COUNT] = {"Shoulder","Melee","Back"};
	
	void RegisterEvents()
	{
		ClientData.SyncEvent_OnEntityKilled.Insert(Event_OnEntityKilled);
		ClientData.SyncEvent_OnPlayerIgnitedFireplace.Insert(Event_OnPlayerIgnitedFireplace);
	}
	
	void UnregisterEvents()
	{
		ClientData.SyncEvent_OnEntityKilled.Remove(Event_OnEntityKilled);
		ClientData.SyncEvent_OnPlayerIgnitedFireplace.Remove(Event_OnPlayerIgnitedFireplace);
	}
	
	//===================================
	// OnActionEat
	//===================================
	void OnActionEat()
	{
		#ifdef PLATFORM_CONSOLE
			AchievementsXbox.OnActionEat();
		#endif
	}
	
	//===================================
	// OnActionDrink
	//===================================
	void OnActionDrink()
	{
		#ifdef PLATFORM_CONSOLE
			AchievementsXbox.OnActionDrink();
		#endif
	}
	
	//===================================
	// OnActionCookedSteak - not implemented
	//===================================
	void OnActionCookedSteak()
	{
		#ifdef PLATFORM_CONSOLE
			AchievementsXbox.OnCookedSteak();
		#endif
	}
	
	//===================================
	// OnActionFinishedShaveSelf
	//===================================
	void OnActionFinishedShaveSelf()
	{
		#ifdef PLATFORM_CONSOLE
			AchievementsXbox.OnActionShave();
		#endif
	}
	
	//===================================
	// OnActionFinishedGutDeer
	//===================================
	void OnActionFinishedGutDeer()
	{
		#ifdef PLATFORM_CONSOLE
			AchievementsXbox.OnActionGutDeer();
		#endif
	}
	
	//===================================
	// OnActionRestrain
	//===================================
	void OnActionRestrain()
	{		
		#ifdef PLATFORM_CONSOLE
			AchievementsXbox.OnActionHandcuff();
		#endif
	}
	
	//===================================
	// OnActionBandageTarget
	//===================================
	void OnActionBandageTarget()
	{		
		#ifdef PLATFORM_CONSOLE
			AchievementsXbox.OnActionMedsSurvivor();
		#endif
	}
	
	//===================================
	// OnItemAttachedAtPlayer
	//===================================
	void OnItemAttachedAtPlayer(EntityAI item, string slot_name)
	{
		bool weapon_present;
		bool melee_present;
		bool backpack_present;
		HumanInventory inventory;
		//#ifdef PLATFORM_XBOX
			if ( GetDayZGame().GetGameState() != DayZGameState.IN_GAME )
			{
				return;
			}
		
			Man player = GetGame().GetPlayer();
			if (!player)
			return;
		
			inventory = player.GetHumanInventory();
			
			if ( player && inventory )
			{
				for ( int i = 0; i < GEAR_COUNT; ++i )
				{
					int slot_id = InventorySlots.GetSlotIdFromString(m_FullGear[i]);
					EntityAI att_item = inventory.FindAttachment( slot_id ); // Boris V [27.2.2019]: Consider using player.GetItemOnSlot(m_FullGear[i]) instead.
					
					if ( !att_item )
					{
						//Print("index: "+ i +" slot_id: "+ slot_id +" = "+ att_item + " EMPTY");
						continue;
					}
				
					//checks for firearm
					if (att_item.IsWeapon())
						weapon_present = true;
					//checks for melee weapon
					else if (!att_item.IsWeapon() && att_item.GetInventory().HasInventorySlot(InventorySlots.GetSlotIdFromString("Melee")))
						melee_present = true;
					//checks for backpack
					else if (!att_item.IsWeapon() && att_item.GetInventory().HasInventorySlot(InventorySlots.GetSlotIdFromString("Back")))
						backpack_present = true;
					//Print("index: "+ i +" slot_id: "+ slot_id +" = "+ att_item + " ATTACHED");
				}
				
				//separate check for hand slot; TODO remove duplicates
				att_item = inventory.GetEntityInHands();
				if ( att_item )
				{
					//checks for firearm
					if (att_item.IsWeapon())
						weapon_present = true;
					//checks for melee weapon
					else if (!att_item.IsWeapon() && att_item.GetInventory().HasInventorySlot(InventorySlots.GetSlotIdFromString("Melee")) )
						melee_present = true;
					//checks for backpack
					else if (!att_item.IsWeapon() && att_item.GetInventory().HasInventorySlot(InventorySlots.GetSlotIdFromString("Back")))
						backpack_present = true;
				}
				
				if (weapon_present && melee_present && backpack_present)
				{
					//Print("---EAchievementActionId.ACTION_EQUIP_GEAR");
					AchievementsXbox.OnEquippedFullGear();
				}
			}
		//#endif
	}
	
	//===================================
	// Event_OnPlayerIgnitedFireplace
	//===================================
	void Event_OnPlayerIgnitedFireplace( EFireIgniteType ignite_type )
	{
		switch ( ignite_type )
		{
			case EFireIgniteType.Matchbox:
			{
				AchievementsXbox.OnActionIgniteMatchbox();
				break;
			}
			case EFireIgniteType.Roadflare:
			{
				AchievementsXbox.OnActionIgniteRoadflare();
				break;
			}
			case EFireIgniteType.HandDrill:
			{
				AchievementsXbox.OnActionIgniteDrill();
				break;
			}
		}
	}
	
	//===================================
	// Event_OnEntityKilled
	//===================================
	void Event_OnEntityKilled(EntityAI victim, EntityAI killer, EntityAI source, bool is_headshot)
	{
		#ifdef PLATFORM_CONSOLE
		// Xbox Achievement
		if ( killer != null && killer.IsPlayer() && killer.GetID() == GetGame().GetPlayer().GetID() )
		{
			AchievementsXbox.OnPlayerKilled(victim, killer, source, is_headshot);
		}
		#endif
	}
}