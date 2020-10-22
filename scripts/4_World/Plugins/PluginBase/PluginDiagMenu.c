enum DiagMenuIDs
{
	DM_SCRIPTS_MENU,
	DM_PLAYER_STATES_MENU,
	DM_PLAYER_SYMPTOMS_SHOW,
	DM_TRANSFER_VALUES_MENU,
	DM_TRANSFER_VALUES_SHOW,
	DM_PLAYER_CRAFTING_MENU,
	DM_PLAYER_CRAFTING_GENERATE,
	DM_PLAYER_CRAFTING_DEBUG_ACTIONS_ENABLE,
	DM_PLAYER_CRAFTING_DUMP,
	DM_CHEATS_MENU,
	DM_CHEATS_MODIFIERS_ENABLE,
	DM_CHEATS_PLAYER_INSTAKILL,
	DM_CHEATS_INVINCIBILITY,
	DM_CHEATS_STAMINA_DISABLE,
	DM_PLAYER_AGENTS_MENU,
	DM_PLAYER_AGENTS_INJECTS_SHOW,
	DM_SOFT_SKILLS_MENU,
	DM_GUN_PARTICLES,
	DM_DISABLE_PERSONAL_LIGHT,
	DM_SOFT_SKILLS_SHOW_DEBUG,
	DM_SOFT_SKILLS_TOGGLE_STATE,
	DM_SOFT_SKILLS_TOGGLE_MODEL,
	DM_SOFT_SKILLS_SPECIALTY_VALUE,
	DM_ITEM_DEBUG_ACTIONS_SHOW,
	DM_PLAYER_STATS_LOG_ENABLE,
	DM_ACTION_TARGETS_MENU,
	DM_ACTION_TARGETS_NEW,
	DM_ACTION_TARGETS_DEBUG,
	DM_ACTION_TARGETS_SELPOS_DEBUG,
	DM_LIFESPAN_MENU,
	DM_BLOODY_HANDS,
	DM_LIFESPAN_PLAYTIME_UPDATE,
	DM_PERMANENT_CROSSHAIR,
	DM_SHOW_VEHICLE_GETOUT_BOX,
	DM_TOGGLE_HUD,
	DM_MISC_MENU,
	DM_MISC_SIMULATE,
	DM_MELEE_MENU,
	DM_MELEE_DEBUG_ENABLE,
	DM_MELEE_SHOW_TARGETS,
	DM_MELEE_DRAW_TARGETS,
	DM_MELEE_DRAW_RANGE,
	DM_WEAPON_DEBUG_MENU,
	DM_WEAPON_DEBUG_ENABLE,
	DM_WEAPON_AIM_NOISE,
	DM_WEAPON_ALLOW_RECOIL,
	DM_WEAPON_UNLIMITED,
	DM_ENVIRONMENT_DEBUG_ENABLE,
	DM_DISPLAY_PLAYER_INFO,
	DM_DRAW_CHECKERBOARD,
	DM_BULLET_IMPACT,
	DM_PRESENCE_NOTIFIER_DBG,
	DM_XBOX_CURSOR,
	DM_GO_UNCONSCIOUS,
	DM_GO_UNCONSCIOUS_DELAYED,
	DM_SIMULATE_INFINITE_LOOP,
	DM_SIMULATE_NULL_POINTER,
	DM_SIMULATE_DIVISION_BY_ZERO,
	DM_SIMULATE_ERROR_FUNCTION,
	DM_SHOW_BLEEDING_SOURCES,
	DM_DISABLE_BLOOD_LOSS,
	DM_BLEEDING_MENU,
	DM_ACTIVATE_SOURCE,
	DM_ACTIVATE_ALL_BS,
	DM_BS_RELOAD,
	DM_QUICK_RESTRAIN,
	DM_HAIR_MENU,
	DM_HAIR_DISPLAY_DEBUG,
	DM_HAIR_LEVEL,
	DM_HAIR_LEVEL_HIDE,
	DM_HAIR_HIDE_ALL,
	DM_CAM_SHAKE,
	DM_QUICK_FISHING,
	DM_HOLOGRAM,
	DM_SHOCK_IMPACT,
};

enum DebugActionType
{
	GENERIC_ACTIONS = 1,
	PLAYER_AGENTS = 2,
	UNLIMITED_AMMO = 4,
};


class PluginDiagMenu extends PluginBase
{
#ifdef DEVELOPER
	ref Timer m_Timer;
	bool m_EnableModifiers 			= true;
	bool m_EnableUnlimitedAmmo;
	bool m_DisableBloodLoss			= false;
	bool m_IsInvincible 			= false;
	bool m_ShowCraftingDebugActions = false;
	bool m_LogPlayerStats 			= false;
	bool m_SoftSkillsState 			= false;
	bool m_SoftSkillsDebug 			= false;
	bool m_GunParticlesState		= false;
	bool m_SoftSkillsModel 			= false;
	bool m_BloodyHands	 			= false;
	bool m_PermanentCrossHair		= false;
	bool m_ToggleHud				= false;
	bool m_ShowingWeaponDebug		= false;
	bool m_AimNoiseEnabled			= true;
	int m_DisplayPlayerInfo			= false;
	bool m_ProceduralRecoilEnabled 	= true;
	bool m_EnableQuickRestrain 		= false;
	bool m_EnableQuickFishing		= false;
	bool m_StaminaDisabled			= false;
	bool m_EnvironmentStats			= false;
	bool m_DrawCheckerboard			= false;
	bool m_PresenceNotifierDebug	= false;
	bool m_ShowBleedingSources		= false;
	bool m_XboxCursor				= true;
	float m_SpecialtyLevel			= 0;
	float m_LifespanLevel			= 0;
	int  m_DayzPlayerDebugMenu		= -1;
	int m_BleedingSourceRequested;
	int m_HairLevelSelected 		= 0;
	int m_TotalHairLevelsAdjusted;
	
	//string m_HairSelections 		= "Clipping_GhillieHood, Clipping_grathelm, Clipping_ConstructionHelmet, Clipping_Hockey_hekmet, Clipping_Maska, Clipping_ProtecSkateHelmet2, Clipping_BandanaFace, Clipping_NioshFaceMask, Clipping_NBC_Hood, Clipping_MotoHelmet, Clipping_FireHelmet, Clipping_ushanka, Clipping_TankerHelmet, Clipping_SantasBeard, Clipping_Surgical_mask, Clipping_PumpkinHelmet, Clipping_Balaclava_3holes, Clipping_Balaclava, Clipping_GP5GasMask, Clipping_BoonieHat, Clipping_prison_cap, Clipping_MilitaryBeret_xx, Clipping_Policecap, Clipping_OfficerHat, Clipping_Hat_leather, Clipping_CowboyHat, Clipping_BandanaHead, Clipping_SantasHat, Clipping_FlatCap, Clipping_MxHelmet, Clipping_baseballcap, Clipping_BeanieHat, Clipping_MedicalScrubs_Hat, Clipping_RadarCap, Clipping_ZmijovkaCap, Clipping_HeadTorch, Clipping_pilotka, Clipping_MxHelmet, Clipping_HelmetMich, Clipping_Ssh68Helmet, Clipping_Mich2001, Clipping_Welding_Mask, Clipping_VintageHockeyMask, Clipping_mouth_rags, Clipping_Gasmask";
	ref map<int,bool> m_HairHidingStateMap;
	ref TStringArray m_HairSelectionArray;
	Shape m_VehicleFreeAreaBox;
	
	override void OnInit()
	{
		if( GetGame().IsMultiplayer() && GetGame().IsServer() ) return; //(only client/local)
		
		//----------------------
		m_HairHidingStateMap = new map<int,bool>;
		m_HairSelectionArray = new TStringArray;
		m_VehicleFreeAreaBox = Debug.DrawBox(Vector(0,0,0), Vector(0,0,0), 0xffffffff);
		
		g_Game.ConfigGetTextArray("cfgVehicles Head_Default simpleHiddenSelections",m_HairSelectionArray);
		m_TotalHairLevelsAdjusted = m_HairSelectionArray.Count() - 1;
		for (int i = 0; i < m_HairSelectionArray.Count(); i++)
		{
			m_HairHidingStateMap.Insert(i,1); //all considered "shown" on init
		}
		
		//----------------------
		m_Timer = new Timer();

		m_Timer.Run(0.5, this, "Update", NULL, true);
		
		//---------------------------------------------------------------
		// LEVEL 0
		//---------------------------------------------------------------
 		DiagMenu.RegisterMenu(DiagMenuIDs.DM_SCRIPTS_MENU,"Script", "");
			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_BLEEDING_MENU,"Bleeding", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool(DiagMenuIDs.DM_SHOW_BLEEDING_SOURCES, "", "Show Bleeding Sources", "Bleeding");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_DISABLE_BLOOD_LOSS, "", "Disable Blood Loss", "Bleeding");
				DiagMenu.RegisterRange(DiagMenuIDs.DM_ACTIVATE_SOURCE, "", "Activate Source #", "Bleeding", "1, 32, 0, 1");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_ACTIVATE_ALL_BS, "", "Activate All Sources", "Bleeding");
				
				DiagMenu.RegisterBool(DiagMenuIDs.DM_BS_RELOAD, "", "Client Reload", "Bleeding");
		
			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_CHEATS_MENU,"Cheats", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool(DiagMenuIDs.DM_CHEATS_MODIFIERS_ENABLE, "lalt+2", "Tick Modifiers", "Cheats");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_CHEATS_INVINCIBILITY, "lalt+1", "Invincibility(IDDQD)", "Cheats");
				DiagMenu.SetValue(DiagMenuIDs.DM_CHEATS_MODIFIERS_ENABLE, true);
				DiagMenu.RegisterBool(DiagMenuIDs.DM_CHEATS_PLAYER_INSTAKILL, "", "Kill Player", "Cheats");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_CHEATS_STAMINA_DISABLE, "", "Disable stamina", "Cheats");
			
			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_PLAYER_CRAFTING_MENU,"Crafting", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool(DiagMenuIDs.DM_PLAYER_CRAFTING_GENERATE, "", "Generate Cache", "Crafting");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_PLAYER_CRAFTING_DEBUG_ACTIONS_ENABLE, "", "Debug Insta Crafting", "Crafting");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_PLAYER_CRAFTING_DUMP, "", "Dump recipes to file", "Crafting");
			
			
			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_PLAYER_STATES_MENU,"Player States", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool(DiagMenuIDs.DM_PLAYER_SYMPTOMS_SHOW, "lalt+6", "Show States", "Player States");

			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_TRANSFER_VALUES_MENU, "TransferValues", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool(DiagMenuIDs.DM_TRANSFER_VALUES_SHOW, "", "ShowValues", "TransferValues");
			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_PLAYER_AGENTS_MENU, "Player Agents", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool(DiagMenuIDs.DM_PLAYER_AGENTS_INJECTS_SHOW, "lalt+5", "Allow Inject Actions", "Player Agents");
			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_SOFT_SKILLS_MENU, "Soft Skills", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool( DiagMenuIDs.DM_SOFT_SKILLS_SHOW_DEBUG, "", "Show Debug", "Soft Skills" );
				DiagMenu.RegisterBool( DiagMenuIDs.DM_SOFT_SKILLS_TOGGLE_STATE, "", "Enable SoftSkills", "Soft Skills" );
				DiagMenu.RegisterBool( DiagMenuIDs.DM_SOFT_SKILLS_TOGGLE_MODEL, "", "Enable linear model", "Soft Skills" );
				DiagMenu.RegisterRange( DiagMenuIDs.DM_SOFT_SKILLS_SPECIALTY_VALUE, "", "Set specialty value", "Soft Skills", "-1, 1, 0, 0.01" );
			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_LIFESPAN_MENU, "Lifespan", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool( DiagMenuIDs.DM_BLOODY_HANDS, "", "Bloody hands", "Lifespan" );
				DiagMenu.RegisterRange( DiagMenuIDs.DM_LIFESPAN_PLAYTIME_UPDATE, "", "Playtime in seconds", "Lifespan", "0, 3600, 0, 300" );
			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_MISC_SIMULATE, "Simulate script", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool(DiagMenuIDs.DM_SIMULATE_INFINITE_LOOP, "", "Simulate infinite loop", "Simulate script");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_SIMULATE_NULL_POINTER, "", "Simulate null pointer", "Simulate script");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_SIMULATE_DIVISION_BY_ZERO, "", "Simulate division by 0", "Simulate script");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_SIMULATE_ERROR_FUNCTION, "", "Simulate Error() function", "Simulate script");	
			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_MISC_MENU, "Misc", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool(DiagMenuIDs.DM_ITEM_DEBUG_ACTIONS_SHOW, "lalt+4", "Item Debug Actions", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_BULLET_IMPACT, "lalt+7", "BulletImpact", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_SHOCK_IMPACT, "lalt+8", "ShockHitEffect", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_PLAYER_STATS_LOG_ENABLE, "", "Log Player Stats", "Misc");
				DiagMenu.RegisterMenu(DiagMenuIDs.DM_ACTION_TARGETS_MENU, "Action Targets", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_XBOX_CURSOR, "", "XboxCursor", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_PERMANENT_CROSSHAIR, "", "Enable permanent crosshair", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_SHOW_VEHICLE_GETOUT_BOX, "", "Debug transport freespace", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_TOGGLE_HUD, "", "Toggle HUD on/off", "Misc", true);
				DiagMenu.RegisterRange(DiagMenuIDs.DM_DISPLAY_PLAYER_INFO, "", "Display Player Info", "Misc", "0,2,0,1");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_ENVIRONMENT_DEBUG_ENABLE, "", "Show Environment stats", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_DRAW_CHECKERBOARD, "", "Draw Checkerboard on screen", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_PRESENCE_NOTIFIER_DBG, "", "Show Presence to AI dbg", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_GO_UNCONSCIOUS, "", "Go Unconscious", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_GO_UNCONSCIOUS_DELAYED, "", "Uncons. in 10sec", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_QUICK_RESTRAIN, "ralt+0", "Quick Restrain", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_QUICK_FISHING, "", "Quick Fishing", "Misc");
				DiagMenu.RegisterMenu(DiagMenuIDs.DM_HAIR_MENU, "Hair Hiding", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_DISABLE_PERSONAL_LIGHT, "", "Disable Personal Light", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_CAM_SHAKE, "lalt+3", "Simulate Cam Shake", "Misc");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_HOLOGRAM, "lctrl+h", "Hologram placing debug", "Misc");
					//---------------------------------------------------------------
					// LEVEL 3
					//---------------------------------------------------------------
					DiagMenu.RegisterBool(DiagMenuIDs.DM_ACTION_TARGETS_NEW, "", "New AT Selection", "Action Targets", true);
					DiagMenu.RegisterBool(DiagMenuIDs.DM_ACTION_TARGETS_DEBUG, "", "Show Debug", "Action Targets");
					DiagMenu.RegisterBool(DiagMenuIDs.DM_ACTION_TARGETS_SELPOS_DEBUG, "", "Show selection pos debug", "Action Targets");
					DiagMenu.RegisterBool(DiagMenuIDs.DM_HAIR_DISPLAY_DEBUG, "", "Display Debug", "Hair Hiding");
					DiagMenu.RegisterRange(DiagMenuIDs.DM_HAIR_LEVEL, "", "Hair Level#", "Hair Hiding","0,"+m_TotalHairLevelsAdjusted+",0,1");
					DiagMenu.RegisterBool(DiagMenuIDs.DM_HAIR_LEVEL_HIDE, "", "Toggle Hair Level", "Hair Hiding");
					DiagMenu.RegisterBool(DiagMenuIDs.DM_HAIR_HIDE_ALL, "", "Hide/Show All", "Hair Hiding");

			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_MELEE_MENU, "Melee", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool(DiagMenuIDs.DM_MELEE_DEBUG_ENABLE, "", "Enable Melee Debug", "Melee");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_MELEE_SHOW_TARGETS, "", "Show targets", "Melee");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_MELEE_DRAW_TARGETS, "", "Draw targets", "Melee");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_MELEE_DRAW_RANGE, "", "Draw range", "Melee");
			//---------------------------------------------------------------
			// LEVEL 1
			//---------------------------------------------------------------
			DiagMenu.RegisterMenu(DiagMenuIDs.DM_WEAPON_DEBUG_MENU, "Weapon", "Script");
				//---------------------------------------------------------------
				// LEVEL 2
				//---------------------------------------------------------------
				DiagMenu.RegisterBool( DiagMenuIDs.DM_GUN_PARTICLES, "", "Enable gun particles", "Weapon", true );
				DiagMenu.RegisterBool(DiagMenuIDs.DM_WEAPON_DEBUG_ENABLE, "", "Show Debug", "Weapon");
				DiagMenu.RegisterBool(DiagMenuIDs.DM_WEAPON_AIM_NOISE, "", "Weapon Sway", "Weapon");
				DiagMenu.SetValue(DiagMenuIDs.DM_WEAPON_AIM_NOISE, true);
				DiagMenu.RegisterBool(DiagMenuIDs.DM_WEAPON_ALLOW_RECOIL, "", "Procedural Recoil", "Weapon");
				DiagMenu.SetValue(DiagMenuIDs.DM_WEAPON_ALLOW_RECOIL, true);
				DiagMenu.RegisterBool(DiagMenuIDs.DM_WEAPON_UNLIMITED, "lalt+9", "Unlimited Ammo", "Weapon");
	}
	
	void Update(float deltaT)
	{
		//---------------------------------------------
		// every system can handle their own actions locally(within the system itself),
		// this section is for systems which don't have client side representation,
		// or don't have their own tick, or for whatever other reason you prefer to put the logic here
		// PUT ONLY METHOD CALLS HERE, NO CODE !!
		// PUT ONLY METHOD CALLS HERE, NO CODE !!
		//---------------------------------------------
			
		CheckModifiers();//should modifiers be ticking
		CheckKillPlayer();//should i kill myself ?
		CheckCraftingDebugActions();
		CheckItemDebugActions();
		CheckAgentInjectActions();
		CheckGenerateRecipeCache();
		CheckDayzPlayerMenu();
		CheckSoftSkillsDebug();
		CheckSoftSkillsState();
		CheckSoftSkillsModel();
		CheckGunParticles();
		CheckSpecialtyLevel();
		CheckBloodyHands();
		CheckLifeSpanPlaytimeUpdate();
		CheckPermanentCrossHairUpdate();
		CheckToggleHud();
		CheckShowWeaponDebug();
		CheckInvincibility();
		CheckStamina();
		CheckAimNoise();
		CheckProceduralRecoil();
		CheckUnlimitedAmmo();
		CheckCraftingDump();
		CheckEnvironmentStats();
		CheckDisplayMenu();
		CheckDrawCheckerboard();
		CheckBulletImpact();
		CheckShockImpact();
		CheckPresenceNotifierDebug();
		CheckGoUnconscious();
		CheckGoUnconsciousDelayed();
		CheckSimulateNULLPointer();
		CheckSimulateDivisionByZero();
		CheckSimulateInfiniteLoop();
		CheckSimulateErrorFunction();
		CheckShowBleedingSources();
		CheckDisableBloodLoss();
		CheckActivateAllBS();
		CheckReloadBS();
		CheckActivateBleedingSource();
		CheckQuickRestrain();
		CheckQuickFishing();
		CheckHairLevel();
		CheckHairHide();
		CheckPersonalLight();
		CheckCamShake();
		CheckVehicleGetOutBox();

	}
	//---------------------------------------------
	void CheckModifiers()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_CHEATS_MODIFIERS_ENABLE) )
		{
			if(!m_EnableModifiers)
			{
				SendModifiersRPC(true);
				m_EnableModifiers = true;
			}
		}
		else
		{
			if(m_EnableModifiers)
			{
				SendModifiersRPC(false);
				m_EnableModifiers = false;
			}
		}
	}
	//---------------------------------------------
	void CheckUnlimitedAmmo()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_WEAPON_UNLIMITED) )
		{
			if(!m_EnableUnlimitedAmmo)
			{
				SendUnlimitedRPC(true);
				m_EnableUnlimitedAmmo = true;
				ItemBase.SetDebugActionsMask( ItemBase.GetDebugActionsMask() | DebugActionType.UNLIMITED_AMMO );
			}
		}
		else
		{
			if(m_EnableUnlimitedAmmo)
			{
				SendUnlimitedRPC(false);
				m_EnableUnlimitedAmmo = false;
				ItemBase.SetDebugActionsMask( ItemBase.GetDebugActionsMask() & (~DebugActionType.UNLIMITED_AMMO) );
			}
		}
	}	
	//---------------------------------------------
	void CheckDisableBloodLoss()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_DISABLE_BLOOD_LOSS) )
		{
			if(!m_DisableBloodLoss)
			{
				SendDisableBloodLossRPC(true);
				m_DisableBloodLoss = true;
			}
		}
		else
		{
			if(m_DisableBloodLoss)
			{
				SendDisableBloodLossRPC(false);
				m_DisableBloodLoss = false;
			}
		}
	}
	//---------------------------------------------
	void CheckActivateAllBS()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_ACTIVATE_ALL_BS) )
		{
			SendActivateAllBSRPC();
			DiagMenu.SetValue(DiagMenuIDs.DM_ACTIVATE_ALL_BS, false);//to prevent constant RPC calls, switch back to false
		}
	}	
	//---------------------------------------------
	void CheckReloadBS()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_BS_RELOAD) )
		{
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
			if(player && player.GetBleedingManagerRemote())
			{
				player.GetBleedingManagerRemote().Reload();
			}
			DiagMenu.SetValue(DiagMenuIDs.DM_BS_RELOAD, false);//to prevent constant RPC calls, switch back to false
		}
	}
	//---------------------------------------------
	void CheckGenerateRecipeCache()
	{
		if ( DiagMenu.GetBool(DiagMenuIDs.DM_PLAYER_CRAFTING_GENERATE) )
		{
			PluginRecipesManager plugin_recipes_manager;
			Class.CastTo(plugin_recipes_manager, GetPlugin(PluginRecipesManager));
			plugin_recipes_manager.CallbackGenerateCache();
			DiagMenu.SetValue(DiagMenuIDs.DM_PLAYER_CRAFTING_GENERATE, false);
		}
	}
	//---------------------------------------------
	void CheckShowBleedingSources()
	{
		PlayerBase player;
		if ( DiagMenu.GetBool(DiagMenuIDs.DM_SHOW_BLEEDING_SOURCES) )
		{
			if( !m_ShowBleedingSources )
			{
				player = PlayerBase.Cast(GetGame().GetPlayer());
				player.GetBleedingManagerRemote().SetDiag(true);
				m_ShowBleedingSources = true;
			}
		}
		else
		{
			if( m_ShowBleedingSources )
			{
				player = PlayerBase.Cast(GetGame().GetPlayer());
				player.GetBleedingManagerRemote().SetDiag(false);
				m_ShowBleedingSources = false;
			}
		}
	}
	//---------------------------------------------
	void CheckKillPlayer()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_CHEATS_PLAYER_INSTAKILL) )
		{
			SendKillPlayerRPC();
			DiagMenu.SetValue(DiagMenuIDs.DM_CHEATS_PLAYER_INSTAKILL, false);//to prevent constant RPC calls, switch back to false
		}
	}
	//---------------------------------------------
	void CheckGoUnconscious()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_GO_UNCONSCIOUS) )
		{
			SendGoUnconsciousRPC(false);
			DiagMenu.SetValue(DiagMenuIDs.DM_GO_UNCONSCIOUS, false);//to prevent constant RPC calls, switch back to false
		}
	}
	//---------------------------------------------
	void CheckGoUnconsciousDelayed()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_GO_UNCONSCIOUS_DELAYED) )
		{
			SendGoUnconsciousRPC(true);
			DiagMenu.SetValue(DiagMenuIDs.DM_GO_UNCONSCIOUS_DELAYED, false);//to prevent constant RPC calls, switch back to false
		}
	}
	
	void CheckHairLevel()
	{
		int value = DiagMenu.GetRangeValue(DiagMenuIDs.DM_HAIR_LEVEL);
		if (value != m_HairLevelSelected)
		{
			m_HairLevelSelected = value;
			//SendSetHairLevelRPC();
			DiagMenu.SetRangeValue(DiagMenuIDs.DM_HAIR_LEVEL, value);//to prevent constant RPC calls, switch back to false
		}
	}
	
	void CheckHairHide()
	{
		int value = DiagMenu.GetBool(DiagMenuIDs.DM_HAIR_LEVEL_HIDE);
		bool hide_all = DiagMenu.GetBool(DiagMenuIDs.DM_HAIR_HIDE_ALL);
		if (hide_all)
		{
			SendSetHairLevelHideRPC(-1,value);
			DiagMenu.SetValue(DiagMenuIDs.DM_HAIR_HIDE_ALL, false);//to prevent constant RPC calls, switch back to false
		}
		else if (value)
		{
			SendSetHairLevelHideRPC(m_HairLevelSelected,value);
			DiagMenu.SetValue(DiagMenuIDs.DM_HAIR_LEVEL_HIDE, false);//to prevent constant RPC calls, switch back to false
		}
	}
	
	void CheckPersonalLight()
	{
		int value = DiagMenu.GetBool(DiagMenuIDs.DM_DISABLE_PERSONAL_LIGHT);
		PlayerBaseClient.m_PersonalLightDisabledByDebug = value;
		PlayerBaseClient.UpdatePersonalLight();
	}
	
	//---------------------------------------------
	void CheckItemDebugActions()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_ITEM_DEBUG_ACTIONS_SHOW) )
		{
			if( (ItemBase.GetDebugActionsMask() & DebugActionType.GENERIC_ACTIONS) == 0 )
			{
				int test = ItemBase.GetDebugActionsMask();
				int mask = (ItemBase.GetDebugActionsMask() | DebugActionType.GENERIC_ACTIONS);
				ItemBase.SetDebugActionsMask(mask);
				SendDebugActionsRPC();
			}
		}
		else
		{
			if( (ItemBase.GetDebugActionsMask() & DebugActionType.GENERIC_ACTIONS) )
			{
				int mask2 = (ItemBase.GetDebugActionsMask() & (~DebugActionType.GENERIC_ACTIONS));
				ItemBase.SetDebugActionsMask(mask2);
				SendDebugActionsRPC();
			}
		}
	}

	void CheckBulletImpact()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_BULLET_IMPACT) )
		{
			PlayerBase pl_player = PlayerBase.Cast(GetGame().GetPlayer() );
			pl_player.SpawnDamageDealtEffect();
			DiagMenu.SetValue(DiagMenuIDs.DM_BULLET_IMPACT, false);
		}
		else
		{
			
		}
	}
	
	float tmp = 0.25;
	void CheckShockImpact()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_SHOCK_IMPACT) )
		{
			PlayerBase pl_player = PlayerBase.Cast(GetGame().GetPlayer() );
			if (tmp >= 1.0) 	tmp = 0.25;
			pl_player.SpawnShockEffect(tmp);
			tmp += 0.25;
			DiagMenu.SetValue(DiagMenuIDs.DM_SHOCK_IMPACT, false);
		}
	}
	
	bool GetXboxCursor()
	{
		return DiagMenu.GetBool(DiagMenuIDs.DM_XBOX_CURSOR);
	}
	
	//---------------------------------------------
	void CheckAgentInjectActions()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_PLAYER_AGENTS_INJECTS_SHOW) )
		{
			if( (ItemBase.GetDebugActionsMask() & DebugActionType.PLAYER_AGENTS) == 0 )
			{
				int mask = (ItemBase.GetDebugActionsMask() | DebugActionType.PLAYER_AGENTS);
				ItemBase.SetDebugActionsMask(mask);	
				SendDebugActionsRPC();
			}
		}
		else
		{
			if( ItemBase.GetDebugActionsMask() & DebugActionType.PLAYER_AGENTS )
			{
				int mask2 = (ItemBase.GetDebugActionsMask() & (~DebugActionType.PLAYER_AGENTS));
				ItemBase.SetDebugActionsMask(mask2);
				SendDebugActionsRPC();
			}
		}
	}
	//---------------------------------------------
	/*
	void CheckAgentInjectActions()
	{
		if( DiagMenu.GetBool(DM_PLAYER_AGENTS_INJECTS_SHOW) )
		{
			if( !ItemBase.IsShowInjectActions() )
			{
				ItemBase.SetShowInjectActions(true);		
			}
		}
		else
		{
			if( ItemBase.IsShowInjectActions() )
			{
				ItemBase.SetShowInjectActions(false);		
			}
		}
	}
	*/
	
	//---------------------------------------------
	void CheckCraftingDump()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_PLAYER_CRAFTING_DUMP) )
		{
			PluginRecipesManager plugin_recipes_manager;
			Class.CastTo(plugin_recipes_manager, GetPlugin(PluginRecipesManager));
			plugin_recipes_manager.GenerateHumanReadableRecipeList();
			DiagMenu.SetValue(DiagMenuIDs.DM_PLAYER_CRAFTING_DUMP, false);
		}
	}
	//---------------------------------------------
	
	
	//---------------------------------------------
	void CheckCraftingDebugActions()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_PLAYER_CRAFTING_DEBUG_ACTIONS_ENABLE) )
		{
			if(!m_ShowCraftingDebugActions)
			{
				SendDebugCraftingRPC(true);
				PluginRecipesManager plugin_recipes_manager;
				Class.CastTo(plugin_recipes_manager, GetPlugin(PluginRecipesManager));
				plugin_recipes_manager.SetEnableDebugCrafting(true);
				m_ShowCraftingDebugActions = true;
			}
		}
		else
		{
			if(m_ShowCraftingDebugActions)
			{
				SendDebugCraftingRPC(false);
				PluginRecipesManager plugin_recipes_manager2;
				Class.CastTo(plugin_recipes_manager2, GetPlugin(PluginRecipesManager));
				plugin_recipes_manager2.SetEnableDebugCrafting(false);
				m_ShowCraftingDebugActions = false;
			}
		}
	}
	//---------------------------------------------
	void CheckInvincibility()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_CHEATS_INVINCIBILITY) )
		{
			if(!m_IsInvincible)	
			{
				SendInvincibilityRPC(true);
				m_IsInvincible = true;
			}
		}
		else
		{
			if(m_IsInvincible)	
			{
				SendInvincibilityRPC(false);
				m_IsInvincible = false;
			}
		}
	}

	//---------------------------------------------
	void CheckStamina()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_CHEATS_STAMINA_DISABLE) )
		{
			if(!m_StaminaDisabled)	
			{
				m_StaminaDisabled = true;
			}
		}
		else
		{
			if(m_StaminaDisabled)	
			{
				m_StaminaDisabled = false;
			}
		}
	}

	//---------------------------------------------
	void CheckLogPlayerStats()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_PLAYER_STATS_LOG_ENABLE) )
		{
			if(!m_LogPlayerStats)	
			{
				SendLogPlayerStatsRPC(true);
				m_LogPlayerStats = true;
			}
		}
		else
		{
			if(m_LogPlayerStats)	
			{
				SendLogPlayerStatsRPC(false);
				m_LogPlayerStats = false;
			}
		}
	}

	//---------------------------------------------
	void CheckSoftSkillsDebug()
	{
		PlayerBase player;
		SoftSkillManagerDebug m_DebugWindow;

		if( DiagMenu.GetBool( DiagMenuIDs.DM_SOFT_SKILLS_SHOW_DEBUG ) )
		{
			if(!m_SoftSkillsDebug)	
			{
				Class.CastTo(player, GetGame().GetPlayer());
				player.GetSoftSkillsManager().CreateDebugWindow( true );
				SoftSkillsShowDebugRPC(true);
				m_SoftSkillsDebug = true;
			}
		}
		else
		{
			if(m_SoftSkillsDebug)	
			{
				Class.CastTo(player, GetGame().GetPlayer());
				player.GetSoftSkillsManager().CreateDebugWindow( false );
				SoftSkillsShowDebugRPC(false);
				m_SoftSkillsDebug = false;
			}
		}
	}

	//---------------------------------------------
	void CheckSoftSkillsState()
	{
		if( DiagMenu.GetBool( DiagMenuIDs.DM_SOFT_SKILLS_TOGGLE_STATE ) )
		{
			if(!m_SoftSkillsState)	
			{
				SoftSkillsToggleStateRPC(true);
				m_SoftSkillsState = true;
			}
		}
		else
		{
			if(m_SoftSkillsState)	
			{
				SoftSkillsToggleStateRPC(false);
				m_SoftSkillsState = false;
			}
		}
	}
		
	//---------------------------------------------
	void CheckGunParticles()
	{
		if( DiagMenu.GetBool( DiagMenuIDs.DM_GUN_PARTICLES ) )
		{
			if(!m_GunParticlesState)
			{
				GunParticlesToggleStateRPC(false);
				m_GunParticlesState = true;
			}
		}
		else
		{
			if(m_GunParticlesState)
			{
				GunParticlesToggleStateRPC(true);
				m_GunParticlesState = false;
			}
		}
	}

	//---------------------------------------------
	void CheckSoftSkillsModel()
	{
		if( DiagMenu.GetBool( DiagMenuIDs.DM_SOFT_SKILLS_TOGGLE_MODEL ) )
		{
			if(!m_SoftSkillsModel)	
			{
				SoftSkillsToggleModelRPC(true);
				m_SoftSkillsModel = true;
			}
		}
		else
		{
			if(m_SoftSkillsModel)	
			{
				SoftSkillsToggleModelRPC(false);
				m_SoftSkillsModel = false;
			}
		}
	}

	//---------------------------------------------
	void CheckSpecialtyLevel()
	{
		float specialty_value = DiagMenu.GetRangeValue( DiagMenuIDs.DM_SOFT_SKILLS_SPECIALTY_VALUE );

		if( m_SpecialtyLevel != specialty_value )
		{
			SoftSkillsSetSpecialtyRPC( specialty_value );
			m_SpecialtyLevel = specialty_value;
		}
	}
	
	//---------------------------------------------
	void CheckActivateBleedingSource()
	{
		int bleeding_source = DiagMenu.GetRangeValue( DiagMenuIDs.DM_ACTIVATE_SOURCE );
		
		if( bleeding_source != m_BleedingSourceRequested )
		{
			SendActivateBleedingSource(bleeding_source);
			m_BleedingSourceRequested = bleeding_source;
		}
		
	}

	//---------------------------------------------
	void CheckBloodyHands()
	{
		if( DiagMenu.GetBool( DiagMenuIDs.DM_BLOODY_HANDS ) )
		{
			if(!m_BloodyHands)	
			{
				LifespanBloodyHandsRPC(true);
				m_BloodyHands = true;
			}
		}
		else
		{
			if(m_BloodyHands)	
			{
				LifespanBloodyHandsRPC(false);
				m_BloodyHands = false;
			}
		}
	}

	//---------------------------------------------
	void CheckLifeSpanPlaytimeUpdate()
	{
		float lifespan_level = DiagMenu.GetRangeValue( DiagMenuIDs.DM_LIFESPAN_PLAYTIME_UPDATE );

		if( m_LifespanLevel != lifespan_level )
		{
			LifespanPlaytimeUpdateRPC( lifespan_level );
			m_LifespanLevel = lifespan_level;
		}
	}
	//---------------------------------------------	
	void CheckPermanentCrossHairUpdate()
	{
		PluginPermanentCrossHair crosshair;
		if( DiagMenu.GetBool( DiagMenuIDs.DM_PERMANENT_CROSSHAIR ) )
		{
			if(!m_PermanentCrossHair)	
			{
				Class.CastTo(crosshair, GetPlugin( PluginPermanentCrossHair ));
				crosshair.SwitchPermanentCrossHair(true);
				m_PermanentCrossHair = true;
			}
		}
		else
		{
			if(m_PermanentCrossHair)	
			{
				Class.CastTo(crosshair, GetPlugin( PluginPermanentCrossHair ));
				crosshair.SwitchPermanentCrossHair(false);
				m_PermanentCrossHair = false;
			}
		}
	}
	
	//---------------------------------------------		
	void CheckVehicleGetOutBox()
	{
		if ( DiagMenu.GetBool(DiagMenuIDs.DM_SHOW_VEHICLE_GETOUT_BOX ) )
		{
			if (m_VehicleFreeAreaBox)
			{
				m_VehicleFreeAreaBox.Destroy();
				m_VehicleFreeAreaBox = null;
			}
			
			HumanCommandVehicle hcv = GetGame().GetPlayer().GetCommand_Vehicle();
			if (!hcv)
				return;
			m_VehicleFreeAreaBox = hcv.GetTransport().DebugFreeAreaAtDoor( hcv.GetVehicleSeat() );
		}
		else if (m_VehicleFreeAreaBox)
		{
			m_VehicleFreeAreaBox.Destroy();
			m_VehicleFreeAreaBox = null;
		}
	}
	
	//---------------------------------------------	
	void CheckToggleHud()
	{
		Hud hud;
			
		if( DiagMenu.GetBool( DiagMenuIDs.DM_TOGGLE_HUD ) )
		{
			if(!m_ToggleHud)	
			{
				hud = GetGame().GetMission().GetHud();
				hud.Show( m_ToggleHud );
				GetGame().GetMission().HideCrosshairVisibility();
				m_ToggleHud = true;
			}
		}
		else
		{
			if(m_ToggleHud)	
			{
				hud = GetGame().GetMission().GetHud();
				hud.Show( m_ToggleHud );
				GetGame().GetMission().RefreshCrosshairVisibility();
				m_ToggleHud = false;
			}
		}
	}

	//---------------------------------------------	
	void CheckShowWeaponDebug()
	{
		PlayerBase player;
		if( DiagMenu.GetBool( DiagMenuIDs.DM_WEAPON_DEBUG_ENABLE ) )
		{
			if(!m_ShowingWeaponDebug)	
			{

				Class.CastTo(player, GetGame().GetPlayer());
				player.ShowWeaponDebug(true);
				m_ShowingWeaponDebug = true;
			}
		}
		else
		{
			if(m_ShowingWeaponDebug)	
			{
				Class.CastTo(player, GetGame().GetPlayer());
				player.ShowWeaponDebug(false);
				m_ShowingWeaponDebug = false;
			}
		}
	}
	//---------------------------------------------	
	void CheckProceduralRecoil()
	{
		DayZPlayerImplement player;
		if( DiagMenu.GetBool( DiagMenuIDs.DM_WEAPON_ALLOW_RECOIL ) )
		{
			if(!m_ProceduralRecoilEnabled)
			{
				//Class.CastTo(player, GetGame().GetPlayer());
				//player.GetAimingModel().SetProceduralRecoilEnabled(true);
				SendProceduralRecoilRPC(true);
				m_ProceduralRecoilEnabled = true;
			}
		}
		else
		{
			if(m_ProceduralRecoilEnabled)	
			{
				//Class.CastTo(player, GetGame().GetPlayer());
				//player.GetAimingModel().SetProceduralRecoilEnabled(false);
				SendProceduralRecoilRPC(false);
				m_ProceduralRecoilEnabled = false;
			}
		}
	}
	//---------------------------------------------	
	void CheckQuickRestrain()
	{
		
		if( DiagMenu.GetBool( DiagMenuIDs.DM_QUICK_RESTRAIN ) )
		{
			if(!m_EnableQuickRestrain)
			{
				SendEnableQuickRestrainRPC(true);
				m_EnableQuickRestrain = true;
			}
		}
		else
		{
			if(m_EnableQuickRestrain)	
			{
				SendEnableQuickRestrainRPC(false);
				m_EnableQuickRestrain = false;
			}
		}
	}
	
	//---------------------------------------------	
	void CheckQuickFishing()
	{
		
		if ( DiagMenu.GetBool( DiagMenuIDs.DM_QUICK_FISHING ) )
		{
			if (!m_EnableQuickFishing)
			{
				SendEnableQuickFishingRPC(true);
				m_EnableQuickFishing = true;
			}
		}
		else
		{
			if (m_EnableQuickFishing)	
			{
				SendEnableQuickFishingRPC(false);
				m_EnableQuickFishing = false;
			}
		}
	}
	
	//---------------------------------------------	
	
	void CheckCamShake()
	{
		if( DiagMenu.GetBool( DiagMenuIDs.DM_CAM_SHAKE ) )
		{
			GetGame().GetPlayer().GetCurrentCamera().SpawnCameraShake(1,1,15,4);
			DiagMenu.SetValue(DiagMenuIDs.DM_CAM_SHAKE, false);
		}
		

	}
	//---------------------------------------------	
	void CheckAimNoise()
	{
		DayZPlayerImplement player;
		if( DiagMenu.GetBool( DiagMenuIDs.DM_WEAPON_AIM_NOISE ) )
		{
			if(!m_AimNoiseEnabled)
			{

				Class.CastTo(player, GetGame().GetPlayer());
				player.GetAimingModel().SetAimNoiseAllowed(true);
				m_AimNoiseEnabled = true;
			}
		}
		else
		{
			if(m_AimNoiseEnabled)	
			{
				Class.CastTo(player, GetGame().GetPlayer());
				player.GetAimingModel().SetAimNoiseAllowed(false);
				m_AimNoiseEnabled = false;
			}
		}
	}

	//---------------------------------------------
	void CheckDayzPlayerMenu()
	{
		int	actMenuValue = DiagMenu.GetValue(DayZPlayerConstants.DEBUG_SHOWDEBUGPLUGIN);
		// Print("Debug Menu:" + actMenuValue.ToString());
		if (actMenuValue != m_DayzPlayerDebugMenu)
		{
			if (g_Plugins != NULL)
			{
				PluginDayzPlayerDebug pd;
				Class.CastTo(pd, g_Plugins.GetPluginByType(PluginDayzPlayerDebug));
				if (pd != NULL)
				{
					pd.ToggleDebugWindowSetMode(actMenuValue);
					//Print("DayzPlayerDebug - switched to:" + actMenuValue.ToString());
				}
			}
			m_DayzPlayerDebugMenu = actMenuValue;
		}

	}
	//---------------------------------------------
	
	void CheckDisplayMenu()
	{
		PluginRemotePlayerDebugClient plugin_remote_client;
		int value = DiagMenu.GetRangeValue( DiagMenuIDs.DM_DISPLAY_PLAYER_INFO );
		
		if( value != 0 )
		{
			if( m_DisplayPlayerInfo != value )
			{
				plugin_remote_client = PluginRemotePlayerDebugClient.Cast( GetPlugin(PluginRemotePlayerDebugClient) );
				plugin_remote_client.RequestPlayerInfo( PlayerBase.Cast(GetGame().GetPlayer()), value );
				
				m_DisplayPlayerInfo = value;
			}
		}
		else
		{
			if( m_DisplayPlayerInfo != 0 )	
			{
				plugin_remote_client = PluginRemotePlayerDebugClient.Cast( GetPlugin(PluginRemotePlayerDebugClient) );
				plugin_remote_client.RequestPlayerInfo( PlayerBase.Cast(GetGame().GetPlayer()), 0 );
				
				m_DisplayPlayerInfo = 0;
			}
		}
	}

	void CheckEnvironmentStats()
	{
		if(DiagMenu.GetBool(DiagMenuIDs.DM_ENVIRONMENT_DEBUG_ENABLE))
		{
			if(!m_EnvironmentStats)
				m_EnvironmentStats = true;
		}
		else
		{
			if(m_EnvironmentStats)
				m_EnvironmentStats = false;
		}
	}
	
	void CheckDrawCheckerboard()
	{
		if(DiagMenu.GetBool(DiagMenuIDs.DM_DRAW_CHECKERBOARD))
		{
			if(!m_DrawCheckerboard) m_DrawCheckerboard = true;
		}
		else
		{
			if(m_DrawCheckerboard) m_DrawCheckerboard = false;
		}
	}

	void CheckPresenceNotifierDebug()
	{
		if(DiagMenu.GetBool(DiagMenuIDs.DM_PRESENCE_NOTIFIER_DBG))
		{
			if(!m_PresenceNotifierDebug) m_PresenceNotifierDebug = true;
		}
		else
		{
			if(m_PresenceNotifierDebug) m_PresenceNotifierDebug = false;
		}
	}
	
	//---------------------------------------------
	void CheckSimulateNULLPointer()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_SIMULATE_NULL_POINTER) )
		{
			SendSimulateNULLPointer();
			DiagMenu.SetValue(DiagMenuIDs.DM_SIMULATE_NULL_POINTER, false);//to prevent constant RPC calls, switch back to false
		}
	}
	//---------------------------------------------
	void CheckSimulateDivisionByZero()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_SIMULATE_DIVISION_BY_ZERO) )
		{
			SendSimulateDivisionByZero();
			DiagMenu.SetValue(DiagMenuIDs.DM_SIMULATE_DIVISION_BY_ZERO, false);//to prevent constant RPC calls, switch back to false
		}
	}
	//---------------------------------------------
	void CheckSimulateInfiniteLoop()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_SIMULATE_INFINITE_LOOP) )
		{
			SendSimulateInfiniteLoop();
			DiagMenu.SetValue(DiagMenuIDs.DM_SIMULATE_INFINITE_LOOP, false);//to prevent constant RPC calls, switch back to false
		}
	}
	//---------------------------------------------
	void CheckSimulateErrorFunction()
	{
		if( DiagMenu.GetBool(DiagMenuIDs.DM_SIMULATE_ERROR_FUNCTION) )
		{
			SendSimulateErrorFunction();
			DiagMenu.SetValue(DiagMenuIDs.DM_SIMULATE_ERROR_FUNCTION, false);//to prevent constant RPC calls, switch back to false
		}
	}
	
	//---------------------------------------------
	void SendDebugActionsRPC()
	{
		CachedObjectsParams.PARAM1_INT.param1 = ItemBase.GetDebugActionsMask();
		if( GetGame() && GetGame().GetPlayer() ) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_ITEM_DEBUG_ACTIONS, CachedObjectsParams.PARAM1_INT, true, GetGame().GetPlayer().GetIdentity() );
 	}
	
	//---------------------------------------------
	void SendEnableQuickRestrainRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if(player) player.SetQuickRestrain(enable);
		if( GetGame() && GetGame().GetPlayer() ) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_ENABLE_QUICK_RESTRAIN, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	
	//---------------------------------------------
	void SendEnableQuickFishingRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player) player.SetQuickFishing(enable);
		if ( GetGame() && GetGame().GetPlayer() ) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_ENABLE_QUICK_FISHING, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	
	//---------------------------------------------
	void SendProceduralRecoilRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if(player) player.GetAimingModel().SetProceduralRecoilEnabled(enable);
		if( GetGame() && GetGame().GetPlayer() ) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_WEAPON_PROC_RECOIL, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	
	//---------------------------------------------
	void SendActivateAllBSRPC()
	{
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_ACTIVATE_ALL_BS, NULL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SendKillPlayerRPC()
	{
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_KILL_PLAYER, NULL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SendInvincibilityRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_ENABLE_INVINCIBILITY, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SendLogPlayerStatsRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_LOG_PLAYER_STATS, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SendModifiersRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_DISABLE_MODIFIERS, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SendUnlimitedRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_RPC_UNLIMITED_AMMO, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SendDisableBloodLossRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_RPC_DISABLE_BLOODLOOS, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SendDebugCraftingRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_CRAFTING_DEBUG, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SoftSkillsShowDebugRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_SOFT_SKILLS_DEBUG_WINDOW, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SoftSkillsToggleStateRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_SOFT_SKILLS_TOGGLE_STATE, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void GunParticlesToggleStateRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_GUN_PARTICLES_TOGGLE, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SoftSkillsToggleModelRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_SOFT_SKILLS_TOGGLE_MODEL, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SoftSkillsSetSpecialtyRPC( float specialty_value )
	{
		CachedObjectsParams.PARAM1_FLOAT.param1 = specialty_value;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_SOFT_SKILLS_SET_SPECIALTY, CachedObjectsParams.PARAM1_FLOAT, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void LifespanBloodyHandsRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_LIFESPAN_BLOODY_HANDS, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void LifespanPlaytimeUpdateRPC( float playtime )
	{
		CachedObjectsParams.PARAM1_FLOAT.param1 = playtime;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.RPC_LIFESPAN_PLAYTIME_UPDATE, CachedObjectsParams.PARAM1_FLOAT, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SendMeleeBlockStanceRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_RPC_MELEE_BLOCK_STANCE, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
	}
	//---------------------------------------------
	void SendMeleeFightRPC(bool enable)
	{
		CachedObjectsParams.PARAM1_BOOL.param1 = enable;
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_RPC_MELEE_FIGHT, CachedObjectsParams.PARAM1_BOOL, true, GetGame().GetPlayer().GetIdentity() );
	}
	//---------------------------------------------
	void SendGoUnconsciousRPC(bool is_delayed)
	{
		Param1<bool> p1 = new Param1<bool>(is_delayed);
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_GO_UNCONSCIOUS, p1, true, GetGame().GetPlayer().GetIdentity() );
 	}
	//---------------------------------------------
	void SendSimulateNULLPointer()
	{
		GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_SIMULATE_NULL_POINTER, NULL, true, GetGame().GetPlayer().GetIdentity() );
	}
	//---------------------------------------------
	void SendSimulateDivisionByZero()
	{
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_SIMULATE_DIVISION_BY_ZERO, NULL, true, GetGame().GetPlayer().GetIdentity() );
	}
	//---------------------------------------------
	void SendSimulateInfiniteLoop()
	{
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_SIMULATE_INFINITE_LOOP, NULL, true, GetGame().GetPlayer().GetIdentity() );
	}
	//---------------------------------------------
	void SendSimulateErrorFunction()
	{
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_SIMULATE_ERROR_FUNCTION, NULL, true, GetGame().GetPlayer().GetIdentity() );
	}
	
	void SendActivateBleedingSource(int bleeding_source)
	{
		Param1<int> p1 = new Param1<int>(bleeding_source);
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_ACTIVATE_BS, p1, true, GetGame().GetPlayer().GetIdentity() );
	}
	//---------------------------------------------
	void SendSetHairLevelRPC()
	{
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_HAIR_LEVEL, NULL, true, GetGame().GetPlayer().GetIdentity() );
 	}
	
	void SendSetHairLevelHideRPC(int level, bool value)
	{
		Param2<int,bool> p2 = new Param2<int,bool>(level,value);
		if(GetGame() && GetGame().GetPlayer()) 
			GetGame().RPCSingleParam( GetGame().GetPlayer(),ERPCs.DEV_HAIR_LEVEL_HIDE, p2, true, GetGame().GetPlayer().GetIdentity() );
 	}
	
	//---------------------------------------------
	void OnRPC(PlayerBase player, int rpc_type, ParamsReadContext ctx)
	{
		if( GetGame().IsMultiplayer()  &&  GetGame().IsServer() )
		{
			switch(rpc_type)
			{
				case ERPCs.DEV_SIMULATE_NULL_POINTER:
					PlayerBase NULL_player = NULL;
					NULL_player.SetHealth("","", -1);		
				break;
				
				case ERPCs.DEV_SIMULATE_DIVISION_BY_ZERO:
					int zero = 0;
					int division_by_zero = 1/zero;
				break;
				
				case ERPCs.DEV_SIMULATE_INFINITE_LOOP:
					while( true )
					{
						Print("simulated infinite loop");
					}
				break;
				
				case ERPCs.DEV_SIMULATE_ERROR_FUNCTION:
					Error("Simulated error");
				break;
			}
		}
		
		bool enable;
		
		switch(rpc_type)
		{
			case ERPCs.DEV_ACTIVATE_BS:
					ctx.Read(CachedObjectsParams.PARAM1_INT);
					player.GetBleedingManagerServer().DebugActivateBleedingSource(CachedObjectsParams.PARAM1_INT.param1);
			break;
			
			case ERPCs.DEV_RPC_UNLIMITED_AMMO:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				enable = CachedObjectsParams.PARAM1_BOOL.param1;
				if(enable)
				{			
					ItemBase.SetDebugActionsMask( ItemBase.GetDebugActionsMask() | DebugActionType.UNLIMITED_AMMO );
				}
				else
				{
					ItemBase.SetDebugActionsMask( ItemBase.GetDebugActionsMask() & (~DebugActionType.UNLIMITED_AMMO) );			
				}
			break;
			
			case ERPCs.RPC_DISABLE_MODIFIERS:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				enable = CachedObjectsParams.PARAM1_BOOL.param1;
				player.SetModifiers( enable );
			break;
			
			case ERPCs.DEV_RPC_DISABLE_BLOODLOOS:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				player.GetBleedingManagerServer().SetBloodLoss( CachedObjectsParams.PARAM1_BOOL.param1 );
			break;
			
			case ERPCs.RPC_KILL_PLAYER:
				player.SetHealth("","", -1);
			break;	
			
			case ERPCs.DEV_ACTIVATE_ALL_BS:
				player.GetBleedingManagerServer().ActivateAllBS();
			break;

			case ERPCs.RPC_ENABLE_INVINCIBILITY:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				enable = CachedObjectsParams.PARAM1_BOOL.param1;
				player.SetAllowDamage(!enable);
			break;

			case ERPCs.RPC_ITEM_DEBUG_ACTIONS:
				ctx.Read(CachedObjectsParams.PARAM1_INT);
				int mask = CachedObjectsParams.PARAM1_INT.param1;
				ItemBase.SetDebugActionsMask(mask);
			break;
			
			case  ERPCs.RPC_WEAPON_PROC_RECOIL:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				enable = CachedObjectsParams.PARAM1_BOOL.param1;
				player.GetAimingModel().SetProceduralRecoilEnabled(enable);
			break;
			
			case ERPCs.RPC_ENABLE_QUICK_RESTRAIN:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				enable = CachedObjectsParams.PARAM1_BOOL.param1;
				player.SetQuickRestrain(enable);
			break;
			
			case ERPCs.RPC_ENABLE_QUICK_FISHING:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				enable = CachedObjectsParams.PARAM1_BOOL.param1;
				player.SetQuickFishing(enable);
			break;

			case ERPCs.RPC_LOG_PLAYER_STATS:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				player.GetPlayerStats().SetAllowLogs(CachedObjectsParams.PARAM1_BOOL.param1);
			break;

			case ERPCs.RPC_SOFT_SKILLS_TOGGLE_STATE:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				player.GetSoftSkillsManager().SetSoftSkillsState(CachedObjectsParams.PARAM1_BOOL.param1);
			break;

			case ERPCs.RPC_SOFT_SKILLS_DEBUG_WINDOW:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				enable = CachedObjectsParams.PARAM1_BOOL.param1;
				
				if( enable )
				{
					player.GetSoftSkillsManager().StartSynchTimer();
				}
				else
				{
					player.GetSoftSkillsManager().StopSynchTimer();
					player.GetSoftSkillsManager().ResetDebugWindow();
				}
				
			break;
		
			case ERPCs.RPC_GUN_PARTICLES_TOGGLE:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				PrtTest.m_GunParticlesState = CachedObjectsParams.PARAM1_BOOL.param1;
			break;

			case ERPCs.RPC_CRAFTING_DEBUG:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				PluginRecipesManager plugin_recipes_manager;
				Class.CastTo(plugin_recipes_manager, GetPlugin(PluginRecipesManager));
				plugin_recipes_manager.SetEnableDebugCrafting(CachedObjectsParams.PARAM1_BOOL.param1);
			break;

			case ERPCs.RPC_SOFT_SKILLS_TOGGLE_MODEL:
				ctx.Read(CachedObjectsParams.PARAM1_BOOL);
				player.GetSoftSkillsManager().SetLinearState(CachedObjectsParams.PARAM1_BOOL.param1) ;
			break;

			case ERPCs.RPC_SOFT_SKILLS_SET_SPECIALTY:
				ctx.Read( CachedObjectsParams.PARAM1_FLOAT );
				float specialty = CachedObjectsParams.PARAM1_FLOAT.param1;
				SoftSkillsManager soft_skill_manager = player.GetSoftSkillsManager();
				soft_skill_manager.SetSpecialtyLevel( specialty );
				soft_skill_manager.SynchSpecialtyLevel();
				player.GetStatSpecialty().Set( specialty );
			break;

			case ERPCs.RPC_LIFESPAN_BLOODY_HANDS:
				ctx.Read( CachedObjectsParams.PARAM1_BOOL );
				enable = CachedObjectsParams.PARAM1_BOOL.param1;
				PluginLifespan lifespan_bloody_hands;
				Class.CastTo(lifespan_bloody_hands, GetPlugin( PluginLifespan ));
				lifespan_bloody_hands.UpdateBloodyHandsVisibility( player, enable );
			break;

			case ERPCs.RPC_LIFESPAN_PLAYTIME_UPDATE:
				ctx.Read( CachedObjectsParams.PARAM1_FLOAT );
				//reset players playtime
				float playtime = player.StatGet("playtime");
				float opposite_playtime = playtime * ( -1 );
				player.StatUpdate("playtime", opposite_playtime );
				//set new playtime
				float playtime_update = CachedObjectsParams.PARAM1_FLOAT.param1;
				player.StatUpdate("playtime", playtime_update );
				player.SetLastShavedSeconds( 0 );
				//update lifespan
				PluginLifespan module_lifespan_update;
				Class.CastTo(module_lifespan_update, GetPlugin( PluginLifespan ));
				module_lifespan_update.UpdateLifespan( player, true );
				module_lifespan_update.ChangeFakePlaytime( player, playtime_update );
				
			break;
			case ERPCs.DEV_GO_UNCONSCIOUS:
				ctx.Read( CachedObjectsParams.PARAM1_BOOL );
				if(!CachedObjectsParams.PARAM1_BOOL.param1)
				{
					if(player.IsUnconscious())
					{
						player.SetHealth("","Shock",100);
					}
					else
					{
						player.m_UnconsciousEndTime = -60;
						player.SetHealth("","Shock",0);
					}
				}
				else
				{
					GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GoUnconsciousDelayed, 10000, false, new Param1<PlayerBase>(player));
				}
			//DayZPlayerSyncJunctures.SendPlayerUnconsciousness(player, !player.IsUnconscious() );
			break;
			case ERPCs.DEV_HAIR_LEVEL_HIDE:
				ctx.Read( CachedObjectsParams.PARAM2_INT_INT ); //PARAM2_INT_INT.param2 is BOOL here
				player.SetHairLevelToHide(CachedObjectsParams.PARAM2_INT_INT.param1,CachedObjectsParams.PARAM2_INT_INT.param2,true);
				player.UpdateHairSelectionVisibility(true);
			break;
		}
	}
	// Helper diag functions
	void GoUnconsciousDelayed(Param1<PlayerBase> p1)
	{
		PlayerBase player = p1.param1;
		if(player.IsUnconscious())
		{
			player.SetHealth("","Shock",100);
		}
		else
		{
			player.m_UnconsciousEndTime = -60;
			player.SetHealth("","Shock",0);
		}
	}
	
#endif
}
