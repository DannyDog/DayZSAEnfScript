	//------------
	//Will be used later down the line
	enum eBrokenLegs
	{
		NO_BROKEN_LEGS = 0,
		BROKEN_LEGS = 1,
		BROKEN_LEGS_SPLINT = 2,
	}
	//-----------

class PlayerBase extends ManBase
{
	const int 						SIMPLIFIED_SHOCK_CAP = 63;
	const int 						SHAKE_LEVEL_MAX = 7;					
	private int						m_LifeSpanState;
	private int						m_LastShavedSeconds;
	private int						m_BloodType;
	private bool					m_HasBloodTypeVisible;
	private bool					m_LiquidTendencyDrain; //client-side only
	private bool 					m_FlagRaisingTendency;
	private bool					m_HasBloodyHandsVisible;
	protected bool					m_HasHeatBuffer;
	protected bool 					m_PlayerLoaded;
	protected bool 					m_PlayerDisconnectProcessed;
	protected bool 					m_ProcessUIWarning;
	protected int 					m_LocalRefreshAnimStateIdx;
	protected int 					m_RefreshAnimStateIdx;
	private int 					m_StoreLoadVersion;
	const int 						ACT_STORE_SAVE_VERSION = 4;
	protected int 					m_LifespanLevelLocal; //control variable for change calls
	protected int 					m_AnimCommandStarting; //signals the command that is about to start the next frame (e.g. Swim, Fall...)

	private PluginPlayerStatus		m_ModulePlayerStatus;
	PluginConfigEmotesProfile 		m_ConfigEmotesProfile;
	private PluginLifespan 			m_ModuleLifespan;
	protected PluginPresenceNotifier  m_PresenceNotifier;
	
	ref PlayerStats 				m_PlayerStats;
	PluginRecipesManager 			m_ModuleRecipesManager;
	ref BleedingSourcesManagerServer 	m_BleedingManagerServer;
	ref BleedingSourcesManagerRemote 	m_BleedingManagerRemote;
	ref ModifiersManager			m_ModifiersManager;
	ref NotifiersManager 			m_NotifiersManager;
	ref protected ActionManagerBase	m_ActionManager;
	//ref PlayerLightManager 			m_PlayerLightManager;
	ref PlayerAgentPool				m_AgentPool;
	ref Environment					m_Environment;
	ref EmoteManager 				m_EmoteManager;
//	ref VehicleManager 				m_VehicleManager;
	ref SymptomManager				m_SymptomManager;
	ref VirtualHud 					m_VirtualHud;
	ref StaminaHandler				m_StaminaHandler;
	ref InjuryAnimationHandler		m_InjuryHandler;
	ref ShockHandler				m_ShockHandler; //New shock handler
	ref SoftSkillsManager			m_SoftSkillsManager;
	ref StanceIndicator				m_StanceIndicator;
	ref TransferValues				m_TrasferValues;
	ref DebugMonitorValues			m_DebugMonitorValues;
	const int 						OVERLOAD_LIMIT = 30000;
	float 							m_CargoLoad;
	float							m_VisibilityCoef;
	float 							m_OriginalSlidePoseAngle;
	int								m_SoundEvent;
	int 							m_FliesIndex;
	bool							m_SoundEventSent;	
	ref Param2<float,float>			m_UAProgressParam;
	ref Param2<int,int> 			m_UAParam;
	ref Param3<float,float,bool>	m_StaminaParam;
	ref Param1<string> 				m_UAParamMessage;
	ref DamageDealtEffect			m_DamageDealtEffect;
	ref FlashbangEffect				m_FlashbangEffect;
	ref ShockDealtEffect 			m_ShockDealtEffect;
	ref EffectParticle 				m_FliesEff;
	ref TInputActionMap				m_InputActionMap; // Backwards compatibility
	ref TInputActionMap				m_InputActionMapControled;
	ref TInputActionMap				m_InputActionMapAsTarget;
	bool							m_ActionsInitialize;
	//ref CraftingMeta 				m_CraftingMeta;
	ref WeaponManager				m_WeaponManager;
	ref CraftingManager 			m_CraftingManager;
	ref InventoryActionHandler 		m_InventoryActionHandler;
	ref protected QuickBarBase		m_QuickBarBase;
	ref PlayerSoundManagerServer	m_PlayerSoundManagerServer;
	ref PlayerSoundManagerClient	m_PlayerSoundManagerClient;
	ref HeatComfortAnimHandler		m_HCAnimHandler;
	ref EffectSound					m_SoundFliesEffect;
	bool 							m_QuickBarHold;
	bool							m_QuickBarFT = false;
	Hud 							m_Hud;
	protected float 				m_dT;
	protected int 					m_RecipePick;
	protected bool					m_IsHoldingBreath;
	protected bool					m_IsInWater;
	float							m_LastPostFrameTickTime;
	//AbstractWave 					m_SaySoundWave;
	ref Timer						m_DeathCheckTimer;
	bool 							m_CorpseProcessing;
	int 							m_CorpseState;
	protected int 					m_CorpseStateLocal;
	
	int								m_StaminaState;
	float							m_UnconsciousTime;
	int 							m_ShockSimplified;
	float							m_CurrentShock; //Used to synchronize shock between server and client
	bool							m_IsRestrained;
	bool 							m_IsRestrainStarted;
	bool 							m_IsRestrainPrelocked;
	bool							m_ImmunityBoosted;
	bool							m_AreHandsLocked; //Currently only used to block quickbar usage after canceling placement
	float							m_UnconsciousVignetteTarget = 2;
	float							m_CameraSwayModifier = 0.2;
	float 							m_LastShockHitTime;
	DayZPlayerCameraBase 			m_CurrentCamera;
	int								m_BleedingBits;
	vector 							m_DirectionToCursor;
	vector 							m_DefaultHitPosition;
	int								m_DiseaseCount;
	protected bool					m_AllowQuickRestrain;
	protected bool					m_AllowQuickFishing;
	protected int					m_Shakes;
	int								m_BreathVapour;
	int 							m_HealthLevel;
	int 							m_MixedSoundStates;
	bool							m_IsVehicleSeatDriver;
	float							m_UnconsciousEndTime = 0;
	int								m_BleedingSourceCount;
	Head_Default 					m_CharactersHead;
	EPulseType						m_PulseType;
	PlayerBase						m_CheckPulseLastTarget;
	int 							m_ForceInjuryAnimMask;
	//string 						m_sOpticsType;
	bool 							m_HideHairAnimated;
	string 							m_DecayedTexture;
	protected ref array<EntityAI>	m_ItemsToDelete;
	int								m_BrokenLegState = eBrokenLegs.NO_BROKEN_LEGS; //Describe the current leg state
	int								m_LocalBrokenState = eBrokenLegs.NO_BROKEN_LEGS; //Used to check differences between server and client before sync (MUST BE SYNCHED)
	//HumanCommandMove 				cm;	//Get the command modifier in order to force stance when legs are broken
	ref EffectSound 				m_BrokenLegSound;
	const string 					SOUND_BREAK_LEG = "broken_leg_SoundSet";
	bool							m_CanPlayBrokenLegSound = false; //Used to check if sound has already been played
	
	static ref array<string>		m_BleedingSourcesLow; //Stores all LOWER body part bleeding sources
	static ref array<string>		m_BleedingSourcesUp; //Stores all UPPER body part bleeding sources EXCLUDING HEAD
	
	ref protected RandomGeneratorSyncManager m_RGSManager;
	
	#ifdef BOT
	ref Bot							m_Bot;
	#endif
	
	float GetDeltaT()
	{
		return m_dT;
	}
	//Temp QuickBar load	
	ref array<ref Param2<EntityAI,int> >	m_aQuickBarLoad;
	
	//hologram
	ref Hologram m_HologramServer;
	ref Hologram m_HologramLocal;
	vector m_LocalProjectionPosition = "0 0 0 ";
	vector m_LocalProjectionOrientation = "0 0 0 "; 

	//Sheduler
	float m_LastTick = -1;
	int m_AddModifier = -1;
	//crafting start
	int m_RecipeID = -1;
	EntityAI m_Item1;
	EntityAI m_Item2;
	bool m_IsCraftingReady;
	float m_RecipeAnimLength;
	vector m_CraftingInitialPos;
	ref array<int> m_Recipes;
	//crafting end
	ref SoundParams m_SaySoundParams;
	ref SoundObjectBuilder m_SaySoundBuilder;
	ref SoundObject m_SaySoundObject;
	string m_SaySoundLastSetName;
	//input control
	bool m_ActionQBControl;
	
	//Action data for base building actions
	ref ConstructionActionData m_ConstructionActionData;
	//Action data for fireplace (indoor)
	vector m_LastFirePoint;
	float m_LastFirePointRot;
	int m_LastFirePointIndex;
	
	bool ItemToInventory;
	bool m_IsFighting = false;

	// debug monitor
	int m_DebugMonitorEnabled;
	
	//map
	ActionUnfoldMapCB m_hac;
	bool m_MapOpen;
	bool m_MapCloseRequestProcessed;
	protected float m_LastMapScale = -1.0;
	protected vector m_LastMapPos;
	
	//inventory soft locking
	protected bool 					m_InventorySoftLocked;
	static ref TStringArray			m_QBarItems;
	
	//Analytics
	string							m_DatabaseID;
	ref Timer						m_AnalyticsTimer;
	
	//! melee stats
	protected bool 					m_MeleeDebug;
	//protected bool 					m_CheckMeleeItem;
	protected ItemBase 				m_CheckMeleeItem;
	
	//! user actions last message
	protected string 				m_UALastMessage;
	protected ref Timer 			m_UALastMessageTimer;
	
	bool 							m_WorkingNVGHeadset;
	bool 							m_LoweredNVGHeadset;
	//bool 							m_PreviousNVGState;
	
	PluginAdminLog 					m_AdminLog; 
	ref PlayerStomach m_PlayerStomach;
	void PlayerBase()
	{	
		Init();		
	}

	void Init()
	{
		//Print("PSOVIS: new player");
		//PrintString( "isServer " + GetGame().IsServer().ToString() );
		//PrintString( "isClient " + GetGame().IsClient().ToString() );
		//PrintString( "isMultiplayer " + GetGame().IsMultiplayer().ToString() );
		SetEventMask(EntityEvent.INIT|EntityEvent.POSTFRAME|EntityEvent.FRAME);
		//m_Agents = new array<int>; //transmission agents
		m_StoreLoadVersion = 0;
		m_IsCraftingReady = false;
		m_Recipes = new array<int>;
		m_LastShavedSeconds = 0;
		m_BloodType = 0;
		m_HasBloodTypeVisible = false;
		m_LifeSpanState = 0;
		m_LifespanLevelLocal = -1;
		m_CorpseStateLocal = -1;
		m_HasBloodyHandsVisible = false;
		m_PlayerLoaded = false;
		m_PlayerSelected = false;
		m_ProcessUIWarning = false;
		m_FlagRaisingTendency = true;
		m_LiquidTendencyDrain = false;
		m_UAParamMessage = new Param1<string>("");
		m_UAParam = new Param2<int,int>(0,0);
		m_UAProgressParam = new Param2<float,float>(0,0);
		m_QuickBarBase = new QuickBarBase(this);
		m_CargoLoad = 0;
		m_VisibilityCoef = 1.0;
		m_Hud = GetGame().GetMission().GetHud();
		m_RecipePick = 0;
		m_ActionQBControl = false;
		m_QuickBarHold = false;
		m_HideHairAnimated = true;
		m_WorkingNVGHeadset = false;
		m_LoweredNVGHeadset = false;
		m_AreHandsLocked = false;
		m_ItemsToDelete = new array<EntityAI>;
		m_AnimCommandStarting = HumanMoveCommandID.None;
		
		m_AnalyticsTimer = new Timer( CALL_CATEGORY_SYSTEM );

		m_StaminaHandler = new StaminaHandler(this);//current stamina calculation
		m_InjuryHandler = new InjuryAnimationHandler(this);
		m_ShockHandler = new ShockHandler(this); //New shock handler
		m_HCAnimHandler = new HeatComfortAnimHandler(this);
		if( GetGame().IsServer() )
		{
			m_PlayerStomach = new PlayerStomach(this);
			m_PlayerStats = new PlayerStats(this);//player stats
			m_NotifiersManager = new NotifiersManager(this); // player notifiers 
			m_AgentPool = new PlayerAgentPool(this); // agent pool manager
			m_BleedingManagerServer = new BleedingSourcesManagerServer(this);
			m_Environment = new Environment(this);//environment effects on player
			m_ModifiersManager = new ModifiersManager(this); // player modifiers 
			m_PlayerSoundManagerServer = new PlayerSoundManagerServer(this);
			m_VirtualHud = new VirtualHud(this);
			
			m_AdminLog 				= PluginAdminLog.Cast( GetPlugin(PluginAdminLog) );
		}
		
		m_SymptomManager = new SymptomManager(this); // state manager
		m_ModuleRecipesManager = PluginRecipesManager.Cast(GetPlugin(PluginRecipesManager));
		
		m_TrasferValues = new TransferValues(this);
		m_EmoteManager = new EmoteManager(this);
		m_SoftSkillsManager = new SoftSkillsManager(this);//Soft Skills calculation
		
		m_WeaponManager = new WeaponManager(this);
		m_DebugMonitorValues = new DebugMonitorValues(this);
		m_RGSManager = new RandomGeneratorSyncManager(this);
		
		if( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			m_VirtualHud = new VirtualHud(this);
			m_MeleeDebug = false;
			m_UALastMessage = "";
			m_UALastMessageTimer = new Timer;
			m_CraftingManager = new CraftingManager(this,m_ModuleRecipesManager);
			m_InventoryActionHandler = new InventoryActionHandler(this);
			m_PlayerSoundEventHandler = new PlayerSoundEventHandler(this);
			m_BleedingManagerRemote = new BleedingSourcesManagerRemote(this);
			m_PlayerSoundManagerClient = new PlayerSoundManagerClient(this);
			m_StanceIndicator = new StanceIndicator(this);
			m_ActionsInitialize = false;
			ClientData.AddPlayerBase( this );
			//PPEffects.SetDeathDarkening(1);
		}

		m_ActionManager = NULL;
		//m_PlayerLightManager = NULL;
		//m_VehicleManager = new VehicleManager(this,m_ActionManager);	
		
		m_ConfigEmotesProfile = PluginConfigEmotesProfile.Cast( GetPlugin(PluginConfigEmotesProfile) );
		
		if ( GetDayZGame().IsDebug() )
		{
			PluginConfigDebugProfileFixed m_ConfigDebugProfileFixed = PluginConfigDebugProfileFixed.Cast( GetPlugin(PluginConfigDebugProfileFixed) );
			PluginConfigDebugProfile m_ConfigDebugProfile = PluginConfigDebugProfile.Cast( GetPlugin(PluginConfigDebugProfile) );
			PluginDeveloper m_Developer = PluginDeveloper.Cast( GetPlugin(PluginDeveloper) );
			
			PlayerBase player = this;
			
			if( m_ConfigDebugProfile )
			{
				string default_preset = m_ConfigDebugProfile.GetDefaultPreset();
				if ( player && default_preset != "" )
				{
					TStringArray preset_array = new TStringArray;
					m_ConfigDebugProfileFixed.GetPresetItems( default_preset, preset_array );
					
					bool is_preset_fixed = true;
					if ( preset_array.Count() == 0 )
					{
						m_ConfigDebugProfile.GetPresetItems( default_preset, preset_array );
						is_preset_fixed = false;
					}
					
					if ( preset_array.Count() > 0 )
					{
						m_Developer.ClearInventory(player);
						
						for (int i = 0; i < preset_array.Count(); i++)
						{
							float health = -1;
							int quantity = -1;
							if ( is_preset_fixed )
							{
								health = m_ConfigDebugProfileFixed.GetItemHealth( default_preset, i );
								quantity = m_ConfigDebugProfileFixed.GetItemQuantity( default_preset, i );
							}
							else
							{
								health = m_ConfigDebugProfile.GetItemHealth( default_preset, i );
								quantity = m_ConfigDebugProfile.GetItemQuantity( default_preset, i );
							}
							m_Developer.SpawnEntityInInventory(player, preset_array.Get(i), health, quantity );
						}
					}
				}
			}
		}
		
		m_ModulePlayerStatus	= PluginPlayerStatus.Cast( GetPlugin(PluginPlayerStatus) );
		m_ModuleLifespan		= PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
		
		m_BleedingSourcesLow = new array<string>;
		m_BleedingSourcesLow.Insert("RightToeBase");
		m_BleedingSourcesLow.Insert("RightFoot");
		m_BleedingSourcesLow.Insert("LeftToeBase");
		m_BleedingSourcesLow.Insert("LeftFoot");
		m_BleedingSourcesLow.Insert("RightUpLegRoll");
		m_BleedingSourcesLow.Insert("RightUpLeg");
		m_BleedingSourcesLow.Insert("RightLegRoll");
		m_BleedingSourcesLow.Insert("RightLeg");
		m_BleedingSourcesLow.Insert("LeftUpLegRoll");
		m_BleedingSourcesLow.Insert("LeftUpLeg");
		m_BleedingSourcesLow.Insert("LeftLegRoll");
		m_BleedingSourcesLow.Insert("LeftLeg");
		
		m_BleedingSourcesUp = new array<string>;
		m_BleedingSourcesUp.Insert("RightForeArmRoll");
		m_BleedingSourcesUp.Insert("LeftForeArmRoll");
		m_BleedingSourcesUp.Insert("RightForeArm");
		m_BleedingSourcesUp.Insert("RightArmRoll");
		m_BleedingSourcesUp.Insert("RightArm");
		m_BleedingSourcesUp.Insert("RightShoulder");
		m_BleedingSourcesUp.Insert("LeftForeArm");
		m_BleedingSourcesUp.Insert("LeftArmRoll");
		m_BleedingSourcesUp.Insert("LeftArm");
		m_BleedingSourcesUp.Insert("LeftShoulder");
		m_BleedingSourcesUp.Insert("Spine3");
		m_BleedingSourcesUp.Insert("Spine2");
		m_BleedingSourcesUp.Insert("Spine1");
		m_BleedingSourcesUp.Insert("Spine");
		m_BleedingSourcesUp.Insert("Pelvis");
		m_BleedingSourcesUp.Insert("Neck");
		
		RegisterNetSyncVariableInt("m_LifeSpanState", LifeSpanState.BEARD_NONE, LifeSpanState.COUNT);
		RegisterNetSyncVariableInt("m_BloodType", 0, 127);
		RegisterNetSyncVariableInt("m_ShockSimplified",0, SIMPLIFIED_SHOCK_CAP);
		RegisterNetSyncVariableInt("m_SoundEvent",0, EPlayerSoundEventID.ENUM_COUNT - 1);
		RegisterNetSyncVariableInt("m_StaminaState",0, eStaminaState.COUNT - 1);
		RegisterNetSyncVariableInt("m_BleedingBits");
		RegisterNetSyncVariableInt("m_Shakes", 0, SHAKE_LEVEL_MAX);
		RegisterNetSyncVariableInt("m_BreathVapour", 0, BREATH_VAPOUR_LEVEL_MAX);
		RegisterNetSyncVariableInt("m_HealthLevel", eInjuryHandlerLevels.PRISTINE, eInjuryHandlerLevels.RUINED);
		RegisterNetSyncVariableInt("m_MixedSoundStates", 0, eMixedSoundStates.COUNT - 1);
		RegisterNetSyncVariableInt("m_CorpseState",PlayerConstants.CORPSE_STATE_FRESH,PlayerConstants.CORPSE_STATE_DECAYED);
		RegisterNetSyncVariableInt("m_RefreshAnimStateIdx",0,3);
		RegisterNetSyncVariableInt("m_BrokenLegState", eBrokenLegs.NO_BROKEN_LEGS, eBrokenLegs.BROKEN_LEGS_SPLINT);
		RegisterNetSyncVariableInt("m_LocalBrokenState", eBrokenLegs.NO_BROKEN_LEGS, eBrokenLegs.BROKEN_LEGS_SPLINT);
		
		RegisterNetSyncVariableBool("m_IsUnconscious");
		RegisterNetSyncVariableBool("m_IsRestrained");
		RegisterNetSyncVariableBool("m_IsInWater");
		RegisterNetSyncVariableBool("m_HasBloodyHandsVisible");
		RegisterNetSyncVariableBool("m_HasBloodTypeVisible");
		//RegisterNetSyncVariableBool("m_LiquidTendencyDrain");
		RegisterNetSyncVariableBool("m_IsRestrainStarted");
		RegisterNetSyncVariableBool("m_IsRestrainPrelocked");
		RegisterNetSyncVariableBool("m_CanPlayBrokenLegSound"); //Temporary
		RegisterNetSyncVariableBool("m_HasHeatBuffer");
		
		RegisterNetSyncVariableFloat("m_CurrentShock"); //Register shock synchronized variable
		
		m_OriginalSlidePoseAngle = GetSlidePoseAngle();
		
		//! sets default hit position and cache it here (mainly for impact particles)
		m_DefaultHitPosition = SetDefaultHitPosition(GetDayZPlayerType().GetDefaultHitPositionComponent());
		
		/*if (g_Game && g_Game.m_tilePublic && g_Game.m_isTileSet == true)
		{
			g_Game.m_isTileSet = false;
			g_Game.m_tilePublic.Show(false);		
		}*/
		m_DecayedTexture = ConfigGetString("decayedTexture");
		m_FliesIndex = -1;
		
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(this.OnPlayerLoaded);
	}
	
	//! Returns item that's on this player's attachment slot. Parameter slot_type should be a string from config parameter 'itemInfo[]' like "Legs", "Headgear" and so on.
	ItemBase GetItemOnSlot(string slot_type)
	{
		int slot_id = InventorySlots.GetSlotIdFromString( slot_type );
		EntityAI item_EAI = this.GetInventory().FindAttachment( slot_id );
		ItemBase item_IB = ItemBase.Cast(item_EAI);
		
		if (item_EAI  &&  !item_IB)
		{
			string str = "Warning! GetItemOnSlot() >> found item on slot " + slot_type + " can't be cast to ItemBase! Found item is " + item_EAI.GetType() + " and the player is " + GetType() + "!";
			Error(str);
			return null;
		}
		
		return item_IB;
	}
	
	//! Returns item on player's head. For an example, a headtorch.
	ItemBase GetItemOnHead()
	{
		return GetItemOnSlot("Headgear");
	}
	
	//--------------------------------------------------------------------------
	// Inventory overrides
	//--------------------------------------------------------------------------
	override bool CanDropEntity (notnull EntityAI item)
	{ 
		if( IsRestrained() )
		{
			if( GetHumanInventory().GetEntityInHands() == item )
				return false;
		}
		
		return true; 
	}

	//--------------------------------------------------------------------------
	// PLAYER DAMAGE EVENT HANDLING
	//--------------------------------------------------------------------------
	
	int GetBreathVapourLevel()
	{
		return m_BreathVapour;
	}
	
	// adds state to and syncs sound states variable which is used to generate sound client-side
	void UnsetMixedSoundState(eMixedSoundStates state)
	{
		int bit_mask_remove = ~state;
		
		eMixedSoundStates new_states = m_MixedSoundStates & bit_mask_remove;

		if(new_states != m_MixedSoundStates)
		{
			m_MixedSoundStates = new_states;
			SetSynchDirty();
		}
	}
	
	// adds state to and syncs sound states variable which is used to generate sound client-side
	void SetMixedSoundState(eMixedSoundStates state)
	{
		eMixedSoundStates new_states = m_MixedSoundStates | state;
		
		if(new_states != m_MixedSoundStates)
		{
			m_MixedSoundStates = new_states;
			SetSynchDirty();
		}
	}
	
	override bool IsPlayer()
	{
		return true;
	}
	
	bool IsBleeding()
	{
		return (m_BleedingBits != 0 );
	}
	
	void SetBleedingBits(int bits)
	{
		if( m_BleedingBits != bits )
		{
			if( m_BleedingBits == 0 )
			{
				OnBleedingBegin();
			}
			else if( bits == 0 )
			{
				OnBleedingEnd();
			}
		}
		m_BleedingBits = bits;
		SetSynchDirty();
	}
	
	int GetBleedingBits()
	{
		return m_BleedingBits;
	}
	
	void IncreaseDiseaseCount()
	{
		m_DiseaseCount++;
	}
	
	void DecreaseDiseaseCount()
	{
		m_DiseaseCount--;
	}
	
	bool HasDisease()
	{
		return m_DiseaseCount;//0 for no disease, 1+ for disease, gets truncated to 1
	}
	
	
	EPulseType GetPulseType()
	{
		return m_PulseType;
	}
	
	void SetPulseType(EPulseType pulse_type)
	{
		m_PulseType = pulse_type;
	}
	
	
	DamageDealtEffect GetDamageDealtEffect()
	{
		return m_DamageDealtEffect;
	}
	
	override void SpawnDamageDealtEffect()
	{
		m_DamageDealtEffect = new DamageDealtEffect();
	}
	
	FlashbangEffect GetFlashbangEffect()
	{
		return m_FlashbangEffect;
	}
	
	void SpawnFlashbangEffect(PlayerBase player, bool visual)
	{
		if (m_FlashbangEffect)
		{
			delete m_FlashbangEffect;
		}
		
		m_FlashbangEffect = new FlashbangEffect(player, visual);
	}
	
	ShockDealtEffect GetShockEffect()
	{
		return m_ShockDealtEffect;
	}
	
	void SpawnShockEffect(float intensity_max)
	{
		m_ShockDealtEffect = new ShockDealtEffect(intensity_max);
	}
	
	override void EEKilled( Object killer )
	{
		Print(Object.GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " event EEKilled, player has died at STS=" + GetSimulationTimeStamp());
		
		if ( m_AdminLog )
		{
			m_AdminLog.PlayerKilled( this, killer );
		}
		
		if( GetBleedingManagerServer() ) delete GetBleedingManagerServer();

		// kill character in database
		if (GetHive())
		{
			GetHive().CharacterKill(this);
		}
	
		// disable voice communication
		GetGame().EnableVoN(this, false); 
		if( !GetGame().IsMultiplayer() || GetGame().IsClient() )
			ClientData.RemovePlayerBase( this );
		GetSymptomManager().OnPlayerKilled();
		
		if ( GetEconomyProfile() && !m_CorpseProcessing && GetGame().GetMission().InsertCorpse(this) )
		{
			m_CorpseProcessing = true;
			Print("EEKilled - processing corpse");
		}
		
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
		{
			if (GetGame().GetMission())
			{
				GetGame().GetMission().SyncRespawnModeInfo(GetIdentity());
			}
		}
		
		super.EEKilled( killer );
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		dmgDebugPrint(damageResult,damageType,source,component,dmgZone,ammo,modelPos,speedCoef);	
		
		if( m_AdminLog )
		{
			m_AdminLog.PlayerHitBy( damageResult, damageType, this, source, component, dmgZone, ammo );
		}
				
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		
		if( damageResult != null && damageResult.GetDamage(dmgZone, "Shock") > 0)
		{
			m_LastShockHitTime = GetGame().GetTime();
		}
		
		 //! DT_EXPLOSION & FlashGrenade
		if( damageType == DT_EXPLOSION && ammo == "FlashGrenade_Ammo" )
		{
			GetStaminaHandler().DepleteStamina(EStaminaModifiers.OVERALL_DRAIN);
		}
		
		//new bleeding computation
		//---------------------------------------
		if( damageResult != null && GetBleedingManagerServer() )
		{
			float dmg = damageResult.GetDamage(dmgZone, "Blood");
			GetBleedingManagerServer().ProcessHit(dmg, source, component, dmgZone, ammo, modelPos);
		}
		//---------------------------------------
		
		#ifdef DEVELOPER
		if(DiagMenu.GetBool(DiagMenuIDs.DM_MELEE_DEBUG_ENABLE))
		{
			Print("EEHitBy() | Charater " + GetDisplayName() + " hit by " + source.GetDisplayName() + " to " + dmgZone);
		}
		
		PluginRemotePlayerDebugServer plugin_remote_server = PluginRemotePlayerDebugServer.Cast( GetPlugin(PluginRemotePlayerDebugServer) );
		if(plugin_remote_server)
		{
			plugin_remote_server.OnDamageEvent(this, damageResult);
		}
		#endif
		if( GetGame().IsDebugMonitor() )
			m_DebugMonitorValues.SetLastDamage(source.GetDisplayName());
		
		if( m_ActionManager )
			m_ActionManager.Interrupt();
		
		if ( ammo.ToType().IsInherited(Nonlethal_Base) )
		{
			//Print("PlayerBase | EEHitBy | nonlethal hit");
			AddHealth("","Health",-ConvertNonlethalDamage(damageResult.GetDamage(dmgZone,"Shock")));
			if (dmgZone != "Head")
				AddHealth(dmgZone,"Health",-damageResult.GetDamage(dmgZone,"Shock")); //Also deal damage to zone health, no dmg reduction
		}
		
		if (GetGame().IsServer())
		{
			if ( GetHealth("RightLeg", "Health") <= 1 || GetHealth("LeftLeg", "Health") <= 1 || GetHealth("RightFoot", "Health") <= 1 || GetHealth("LeftFoot", "Health") <= 1 )
			{
				if ( GetModifiersManager().IsModifierActive( eModifiers.MDF_BROKEN_LEGS ) )//effectively resets the modifier
				{
					GetModifiersManager().DeactivateModifier( eModifiers.MDF_BROKEN_LEGS );
				}
				GetModifiersManager().ActivateModifier( eModifiers.MDF_BROKEN_LEGS );
			}
		}
		
		//m_ShockHandler.SetShock(damageResult.GetDamage("", "Shock")); //TESTING
		m_ShockHandler.CheckValue(true);
		
		//analytics
		GetGame().GetAnalyticsServer().OnEntityHit( source, this );
	}
	
	override void EEDelete(EntityAI parent)
	{
		if( m_FliesEff )
			m_FliesEff.Stop();
		if( m_SoundFliesEffect )
		{
			StopSoundSet(m_SoundFliesEffect);
			//SEffectManager.DestroySound(m_SoundFliesEffect);
			//m_SoundFliesEffect = null;
		}
	}
	
	float ConvertNonlethalDamage(float damage)
	{
		float converted_dmg = damage * GameConstants.PROJECTILE_CONVERSION_PLAYERS;
		return converted_dmg;
	} 
	
	/** Call only on client or single player PlayerBase
 	 *  (as GetGame().GetPlayer())
	 */
	override void OnPlayerRecievedHit()
	{
		SpawnDamageDealtEffect();
	}
	
	void OnPlayerReceiveFlashbangHitStart(bool visual)
	{
		SpawnFlashbangEffect(this, visual);
	}

	void OnPlayerReceiveFlashbangHitEnd() {}
	
	override void EEHitByRemote(int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos)
	{
		super.EEHitByRemote(damageType, source, component, dmgZone, ammo, modelPos);
		
		Print("DayZPlayerImplement : EEHitByRemote");
	}

	//--------------------------------------------------------------------------	
	//! Melee helpers
	//--------------------------------------------------------------------------

	//! select & return hit component for attacking AI
	override string GetHitComponentForAI()
	{
		return GetDayZPlayerType().GetHitComponentForAI();
	}

	//! returns default hit component (fallback)
	override string GetDefaultHitComponent()
	{
		return GetDayZPlayerType().GetDefaultHitComponent();
	}
	
	override vector GetDefaultHitPosition()
	{
		return m_DefaultHitPosition;
	}
	
	//! returns list of suitable finisher hit components (defined on base entity/entity type)
	override array<string> GetSuitableFinisherHitComponents()
	{
		return GetDayZPlayerType().GetSuitableFinisherHitComponents();
	}
	
	protected vector SetDefaultHitPosition(string pSelection)
	{
		return GetSelectionPositionMS(pSelection);
	}

	//--------------------------------------------------------------------------
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		SwitchItemSelectionTexture(item, slot_name);
		//SwitchItemTypeAttach(item, slot_name);
		m_QuickBarBase.updateSlotsCount();
		CalculateVisibilityForAI();
		UpdateShoulderProxyVisibility(item, slot_name);
		
		HideHairSelections(ItemBase.Cast(item),true);
		
		GetGame().GetAnalyticsClient().OnItemAttachedAtPlayer(item, slot_name);	
		if ( Clothing.Cast(item) )
		{
			Clothing.Cast(item).UpdateNVGStatus(this,true);
		}
		
		AdjustBandana(item,slot_name);
		
		//Print("item " + item.GetType() + " in slot" + slot_name);
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		SwitchItemSelectionTexture(item, slot_name);
		//SwitchItemTypeDetach(item, slot_name); //can't call this one, *OnWasDetached* has to be called on item itself
		m_QuickBarBase.updateSlotsCount();
		CalculateVisibilityForAI();
		//UpdateShoulderProxyVisibility(item, slot_name);
		
		HideHairSelections(ItemBase.Cast(item),false);
		
		if ( Clothing.Cast(item) )
		{
			Clothing.Cast(item).UpdateNVGStatus(this);
		}
	}
	
	void SwitchItemTypeAttach(EntityAI item, string slot)
	{
		//Print("SwitchItemTypeAttach: " + item.GetType());
		if( !GetGame().IsServer() )
			return;
		
		/*InventoryLocation invloc = new InventoryLocation;
		
		item.GetInventory().GetCurrentInventoryLocation(invloc);
		//Print(invloc.DumpToString());
		if (item.ConfigIsExisting("ChangeIntoOnAttach") && invloc.GetType() != InventoryLocationType.UNKNOWN)
		{
			string str = item.ChangeIntoOnAttach(slot);
			if (str != "")
			{
				string typestr = item.GetType();
				MiscGameplayFunctions.TurnItemIntoItem(ItemBase.Cast( item ), str, this);
			}
		}*/
	}
	
	void SwitchItemTypeDetach(EntityAI item, string slot)
	{
		//Print("SwitchItemTypeDetach: " + item.GetType());
	}
	
	void UpdateShoulderProxyVisibility(EntityAI item, string slot_name)
	{
		string slot = slot_name;
		bool boo;
		boo = item.IsWeapon();
		
		if ( slot == "Melee" )
		{
			SetSimpleHiddenSelectionState(SIMPLE_SELECTION_MELEE_RIFLE,boo);
			SetSimpleHiddenSelectionState(SIMPLE_SELECTION_MELEE_MELEE,!boo);
		}
		else if ( slot == "Shoulder" )
		{
			SetSimpleHiddenSelectionState(SIMPLE_SELECTION_SHOULDER_RIFLE,boo);
			SetSimpleHiddenSelectionState(SIMPLE_SELECTION_SHOULDER_MELEE,!boo);
		}
	}
	
	//temporary workaround, STAGING would make this obsolete
	override void SwitchItemSelectionTexture(EntityAI item, string slot_name)
	{
		if((slot_name == "Armband" && FindAttachmentBySlotName("Armband")) || ((slot_name == "Body" && FindAttachmentBySlotName("Armband"))))
		{
			array<string> texture_array = new array<string>;
			GetGame().ConfigGetTextArray ("cfgVehicles " + FindAttachmentBySlotName("Armband").GetType() + " hiddenSelectionsTextures", texture_array);
			int selection = 0;
			int selection_hide = 0;
			string texture = "";
			string show_this = "";
			string hide_this = "";
			
			//has top
			if(FindAttachmentBySlotName("Body"))
			{
				if (ConfigGetBool("woman") != 1)
				{
					show_this = "camoMaleBig";
					hide_this = "camoMale";
				}
				else
				{
					show_this = "camoFemaleBig";
					hide_this = "camoFemale";
				}
			}
			//has no top
			else
			{
				if (ConfigGetBool("woman") != 1)
				{
					show_this = "camoMale";
					hide_this = "camoMaleBig";
				}
				else
				{
					show_this = "camoFemale";
					hide_this = "camoFemaleBig";
				}
			}
			
			selection = FindAttachmentBySlotName("Armband").GetHiddenSelectionIndex(show_this);
			selection_hide = FindAttachmentBySlotName("Armband").GetHiddenSelectionIndex(hide_this);
			
			ItemBase itemIB = ItemBase.Cast(FindAttachmentBySlotName("armband"));
			if(itemIB.ConfigGetString("color") == "Dyed")
			{
				texture = itemIB.GetColorString();
			}
			else
			{
				texture = texture_array.Get(selection);
			}
			
			FindAttachmentBySlotName("Armband").SetObjectTexture ( selection, texture );
			FindAttachmentBySlotName("Armband").SetObjectTexture ( selection_hide, "" );
		}
		
		// matches skin colour shown on item to player's
		if((FindAttachmentBySlotName(slot_name) && FindAttachmentBySlotName(slot_name).GetHiddenSelectionIndex("personality") >= 0))
		{
			string tmp = ConfigGetString("emptyGloves"); //textures are in most body parts, emptyGloves is sufficient
				
			array<string> tone_mat_array = new array<string>;
			array<string> tone_texture_array = new array<string>;
			int personality = FindAttachmentBySlotName(slot_name).GetHiddenSelectionIndex("personality");
			GetGame().ConfigGetTextArray ("cfgVehicles " + tmp + " hiddenSelectionsMaterials", tone_mat_array);
			GetGame().ConfigGetTextArray ("cfgVehicles " + tmp + " hiddenSelectionsTextures", tone_texture_array);
			string tone_mat = tone_mat_array.Get(0);
			string tone_texture;
			if (m_CorpseState > PlayerConstants.CORPSE_STATE_FRESH)
			{
				tone_texture = m_DecayedTexture;
			}
			else
			{
				tone_texture = tone_texture_array.Get(0);
			}
			FindAttachmentBySlotName(slot_name).SetObjectMaterial( personality, tone_mat );
			FindAttachmentBySlotName(slot_name).SetObjectTexture( personality, tone_texture );
		}
	}
	
	void RemoveAllItems()
	{
		array<EntityAI> itemsArray = new array<EntityAI>;
		ItemBase item;
		GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		
		for (int i = 0; i < itemsArray.Count(); i++)
		{
			Class.CastTo(item, itemsArray.Get(i));
			if (item && !item.IsInherited(SurvivorBase))	GetInventory().LocalDestroyEntity(item);
		}
	}
	
	bool IsMale()
	{
		if (ConfigGetBool("woman") != 1)
		{
			return true;
		}
		return false;
	}
	
	int GetVoiceType()
	{
		int voice_type = ConfigGetInt("voiceType");
		
		if (voice_type == 0)
		{
			voice_type = 1;
		}
		
		return voice_type;
	}
	
	PlayerSoundManagerServer GetPlayerSoundManagerServer()
	{
		return m_PlayerSoundManagerServer;
	}
		
	// --------------------------------------------------
	// User Actions
	//---------------------------------------------------
	void SetActions(out TInputActionMap InputActionMap)
	{
		AddAction(ActionOpenDoors, InputActionMap);
		AddAction(ActionCloseDoors, InputActionMap);
		AddAction(ActionEnterLadder, InputActionMap);
		AddAction(ActionExitLadder, InputActionMap);
		//AddAction(ActionWorldCraft);//??
		//AddAction(ActionWorldCraftSwitch);//??
		
		//-----------CheckIfCanMOveToTarget----------
		AddAction(ActionStartEngine, InputActionMap);
		AddAction(ActionStopEngine, InputActionMap);
		AddAction(ActionSwitchSeats, InputActionMap);
		AddAction(ActionOpenCarDoors,InputActionMap);
		AddAction(ActionCloseCarDoors,InputActionMap);
		//AddAction(ActionTakeMaterialToHandsSwitch);
		AddAction(ActionUncoverHeadSelf, InputActionMap);
		//AddAction(ActionAttach);
		AddAction(ActionDrinkPondContinuous, InputActionMap);
		AddAction(ActionIgniteFireplaceByAir, InputActionMap);
		AddAction(ActionMineBushByHand, InputActionMap);
		
		AddAction(ActionUngagSelf, InputActionMap);
		AddAction(ActionLockedDoors, InputActionMap);
		AddAction(ActionWashHandsWaterOne, InputActionMap);
		AddAction(ActionGetOutTransport, InputActionMap);
		//AddAction(ActionSwitchLights);
		//AddAction(ActionTakeMaterialToHands);
		
		/*
		AddAction(AT_VEH_ENGINE_START);// TODO -> target
		AddAction(AT_FOLD_BASEBUILDING_OBJECT);// TODO -> target
		AddAction(AT_DIAL_COMBINATION_LOCK_ON_TARGET);// TODO -> target
		AddAction(AT_UNGAG_SELF);
		AddAction(AT_PICK_BERRY);// TODO -> target
		//actions.Insert(AT_SWAP_ITEM_TO_HANDS);
		AddAction(AT_LOCKED_DOORS);// TODO -> target
		AddAction(AT_GETOUT_TRANSPORT);
		AddAction(AT_VEH_SWITCH_LIGHTS);// TODO -> target??
		AddAction(AT_FENCE_OPEN);// TODO -> target
		AddAction(AT_FENCE_CLOSE);// TODO -> target
		AddAction(AT_TAKE_MATERIAL_TO_HANDS);// TODO -> target*/
		
	}
	
	void SetActions() // Backwards compatibility, not recommended to use
	{
	}
	
	void SetActionsRemoteTarget( out TInputActionMap InputActionMap)
	{
		AddAction(ActionCPR, InputActionMap);
		AddAction(ActionUncoverHeadTarget, InputActionMap);
		AddAction(ActionUngagTarget, InputActionMap);
		AddAction(ActionCheckPulse, InputActionMap);
		AddAction(ActionPullBodyFromTransport, InputActionMap);
		//AddAction(AT_GIVE_ITEM);
	}
	
	void SetActionsRemoteTarget() // Backwards compatibility, not recommended to use
	{
	}
	
	void InitializeActions()
	{
		// Backwards compatibility
		if (IsControlledPlayer())
		{
			m_InputActionMap = new TInputActionMap;
			SetActions();
		}
		else
		{
			m_InputActionMap = new TInputActionMap;
			SetActionsRemoteTarget();
		}
		//////////////////////////
		
		m_InputActionMapControled = new TInputActionMap;
		SetActions(m_InputActionMapControled);

		m_InputActionMapAsTarget = new TInputActionMap;
		SetActionsRemoteTarget(m_InputActionMapAsTarget);
	}
	
	override void GetActions(typename action_input_type, out array<ActionBase_Basic> actions)
	{
		if (!m_ActionsInitialize)
		{
			m_ActionsInitialize = true;
			InitializeActions();
		}

		// Backwards compatibility
		array<ActionBase_Basic> bcActions = m_InputActionMap.Get(action_input_type);
		if (!bcActions)
		{
			if (IsControlledPlayer())
				actions = m_InputActionMapControled.Get(action_input_type);
			else
				actions = m_InputActionMapAsTarget.Get(action_input_type);
		}
		else
		{
			if (!actions)
				actions = new array<ActionBase_Basic>();
			
			if (IsControlledPlayer())
				actions.InsertAll(m_InputActionMapControled.Get(action_input_type));
			else
				actions.InsertAll(m_InputActionMapAsTarget.Get(action_input_type));
			
			actions.InsertAll(bcActions);
		}
	}
	
	void AddAction(typename actionName, out TInputActionMap InputActionMap )
	{
		ActionBase action = GetActionManager().GetAction(actionName);

		typename ai = action.GetInputType();
		if (!ai)
		{
			m_ActionsInitialize = false;
			return;
		}
		
		ref array<ActionBase_Basic> action_array = InputActionMap.Get( ai );
		
		if (!action_array)
		{
			action_array = new array<ActionBase_Basic>;
			InputActionMap.Insert(ai, action_array);
		}
		action_array.Insert(action);
	}
	
	void AddAction(typename actionName) // Backwards compatibility, not recommended to use
	{
		AddAction(actionName, m_InputActionMap);
	}
	
	void RemoveAction(typename actionName, out TInputActionMap InputActionMap)
	{
		ActionBase action = GetActionManager().GetAction(actionName);
		typename ai = action.GetInputType();
		ref array<ActionBase_Basic> action_array = InputActionMap.Get( ai );
		
		if (action_array)
		{
			for (int i = 0; i < action_array.Count(); i++)
			{
				if (action == action_array.Get(i))
				{
					action_array.Remove(i);
				}
			}
			action_array = new array<ActionBase_Basic>;
			InputActionMap.Insert(ai, action_array);
		}
		action_array.Insert(action); 
	}
	
	void RemoveAction(typename actionName) // Backwards compatibility, not recommended to use
	{
		RemoveAction(actionName, m_InputActionMap);
	}
	
	int GetCurrentRecipe()
	{
		return m_RecipePick;
	}
	
	void SetNextRecipe()
	{
		m_RecipePick++;
	}
	
	void SetFirstRecipe()
	{
		m_RecipePick = 0;
	}
	
	//---------------------------------------------------
	
	
	ActionManagerBase GetActionManager()
	{
		return m_ActionManager;
	}
	
	EmoteManager GetEmoteManager()
	{
		return m_EmoteManager;
	}
	
	RandomGeneratorSyncManager GetRandomGeneratorSyncManager()
	{
		return m_RGSManager;
	}
/*	VehicleManager GetVehicleManager()
	{
		return m_VehicleManager;
	}*/
	
	//!called every command handler tick when player is on ladder
	override void OnLadder(float delta_time, HumanMovementState pState)
	{
		ProcessHandDamage(delta_time, pState);
	}
	
	void ProcessHandDamage(float delta_time, HumanMovementState pState)
	{
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer() )
		{
			if(pState.m_iMovement == DayZPlayerConstants.MOVEMENTIDX_SLIDE)
			{
				//Print("sliding down");
				EntityAI gloves = GetInventory().FindAttachment(InventorySlots.GLOVES);
			
				if( gloves && gloves.GetHealthLevel() < 4 )
				{
					gloves.AddHealth("","", PlayerConstants.GLOVES_DAMAGE_SLIDING_LADDER_PER_SEC * delta_time);
					return;
				}
				
				if(	Math.RandomFloat01() < PlayerConstants.CHANCE_TO_BLEED_SLIDING_LADDER_PER_SEC * delta_time)
				{
					if(Math.RandomFloat01() < 0.5)
					{
						if(GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftForeArmRoll"))
						{
							SendSoundEvent(EPlayerSoundEventID.INJURED_LIGHT);
						}
					}
					else
					{
						if(GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("RightForeArmRoll"))
						{
							SendSoundEvent(EPlayerSoundEventID.INJURED_LIGHT);
						}
					}
				}
				
			}
		}
	}
	
	override void ProcessFeetDamageServer(int pUserInt)
	{
		//InventorySlots.HEADGEAR
		EntityAI shoes = GetInventory().FindAttachment(InventorySlots.FEET);
		
		string surface;	int liquid;
		GetGame().SurfaceUnderObject(this, surface, liquid);
		float modifier_surface = Surface.GetParamFloat(surface, "footDamage");
		
		if( shoes && shoes.GetHealthLevel() < 4 )
		{
			shoes.AddHealth("","", - 1 * modifier_surface * PlayerConstants.SHOES_MOVEMENT_DAMAGE_PER_STEP * (float)PlayerConstants.CHECK_EVERY_N_STEP);
			
			/*
			Print("modifier_surface:"+modifier_surface);
			Print(shoes.GetHealth("",""));
			*/
			return;
		}

		float rnd = Math.RandomFloat01();
		
		float modifier_movement = GetFeetDamageMoveModifier();
		
		
		
		/*
		Print(surface);
		Print(Surface.GetParamFloat(surface, "footDamage"));
		*/
		
		float chance = modifier_movement * modifier_surface * PlayerConstants.BAREFOOT_MOVEMENT_BLEED_MODIFIER * (float)PlayerConstants.CHECK_EVERY_N_STEP;
		//Print(chance);
		//Print("chance:" +chance);
		if( rnd < chance )
		{
			if(pUserInt % 2 == 0)//!right foot
			{
				if(GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("RightFoot"))
				{
					//added
					//Print("right foot bleeding");
					SendSoundEvent(EPlayerSoundEventID.INJURED_LIGHT);
					
				}
				
			}
			else//!left foot
			{
				if(GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftFoot"))
				{
					//added
					//Print("left foot bleeding");
					SendSoundEvent(EPlayerSoundEventID.INJURED_LIGHT);
					
				}
			}
		}
	}
	
	float GetFeetDamageMoveModifier()
	{
		float modifier;
		switch(m_MovementState.m_iMovement)
		{
			case DayZPlayerConstants.MOVEMENTIDX_SPRINT:
				modifier = 1;
				break
			case DayZPlayerConstants.MOVEMENTIDX_RUN:
				modifier = 0.5;
				break 
			case DayZPlayerConstants.MOVEMENTIDX_WALK:
				modifier = 0;
				break
		}
		return modifier;
	}
	
	void SetStamina( int value, int range )
	{
		if( m_ModulePlayerStatus )
			m_ModulePlayerStatus.SetStamina( value, range );
	}
	
	void SetQuickRestrain(bool enable)
	{
		m_AllowQuickRestrain = enable;
	}
	
	void SetQuickFishing(bool enable)
	{
		m_AllowQuickFishing = enable;
	}
	
	bool IsQuickRestrain()
	{
		return m_AllowQuickRestrain;
	}
	
	bool IsQuickFishing()
	{
		return m_AllowQuickFishing;
	}
	
	PlayerStats GetPlayerStats()
	{
		return m_PlayerStats;	
	}

	CraftingManager GetCraftingManager()
	{
		return m_CraftingManager;		
	}
	
	StaminaHandler GetStaminaHandler()
	{
		return m_StaminaHandler;		
	}
	
	override WeaponManager GetWeaponManager()
	{
		return m_WeaponManager;		
	}
	
	bool CanBeRestrained()
	{
		if( IsInVehicle() || IsRaised() || IsSwimming() || IsClimbing() || IsClimbingLadder() || IsRestrained() || !GetWeaponManager() || GetWeaponManager().IsRunning() || !GetActionManager() || GetActionManager().GetRunningAction() != null || IsMapOpen() )
		{
			return false;
		}
		if( GetThrowing() && GetThrowing().IsThrowingModeEnabled() )
		{
			return false;
		}
		return true;
	}
	
	void SetRestrainStarted(bool restrain_started)
	{
		m_IsRestrainStarted = restrain_started;
		SetSynchDirty();
	}
	
	bool IsRestrainStarted()
	{
		return m_IsRestrainStarted;
	}
	
	void SetRestrainPrelocked(bool restrain_prelock)
	{
		m_IsRestrainPrelocked = restrain_prelock;
		SetSynchDirty();
	}
	
	bool IsRestrainPrelocked()
	{
		return m_IsRestrainPrelocked;
	}
	
	void SetRestrained(bool	is_restrained)
	{
		m_IsRestrained = is_restrained;
		SetSynchDirty();
	}
	
	override bool IsRestrained()
	{
		return m_IsRestrained;
	}
	
	override bool IsInventoryVisible()
	{
		return true;
	}
	
	bool CanManipulateInventory()
	{
		if( IsControlledPlayer() )
		{
			return !IsRestrained() && !IsRestrainPrelocked();
		}
		return true;
	}
	
	override bool CanReleaseAttachment (EntityAI attachment)
	{
		return super.CanReleaseAttachment(attachment);
	}
	
	override bool CanReleaseCargo (EntityAI cargo)
	{
		return super.CanReleaseCargo(cargo);
	}
	
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return super.CanReceiveItemIntoCargo(item);
	}
	
	override bool CanSwapItemInCargo (EntityAI child_entity, EntityAI new_entity)
	{
		return super.CanSwapItemInCargo(child_entity, new_entity);
	}
	
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		ClothingBase headgear = ClothingBase.Cast(GetInventory().FindAttachment(InventorySlots.HEADGEAR));
		ClothingBase mask = ClothingBase.Cast(GetInventory().FindAttachment(InventorySlots.MASK));
		ClothingBase eyewear = ClothingBase.Cast(GetInventory().FindAttachment(InventorySlots.EYEWEAR));
		
		if( headgear && ((headgear.ConfigGetBool("noMask") && slotId == InventorySlots.MASK) || (headgear.ConfigGetBool("noEyewear") && slotId == InventorySlots.EYEWEAR)) )
		{
			return false;
		}
		if( ClothingBase.Cast(attachment) && ((attachment.ConfigGetBool("noMask") && mask) || (attachment.ConfigGetBool("noEyewear") && eyewear && !eyewear.ConfigGetBool("isStrap"))) )
		{
			return false;
		}
		
		return super.CanReceiveAttachment(attachment, slotId);
	}
	
	override bool CanReceiveItemIntoHands(EntityAI item_to_hands)
	{
		if ( IsInVehicle() )
			return false;
		
		if ( !CanPickupHeavyItem(item_to_hands) )
			return false;
		
		return super.CanReceiveItemIntoHands(item_to_hands);
	}
	
	override bool CanSaveItemInHands(EntityAI item_in_hands)
	{
		return super.CanSaveItemInHands(item_in_hands);
	}
	
	override bool CanReleaseFromHands(EntityAI handheld)
	{
		return super.CanReleaseFromHands(handheld);
	}
	
	int GetCraftingRecipeID()
	{
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			return GetCraftingManager().GetRecipeID();
		}
		else
		{
			return m_RecipeID;
		}		
	}
	
	void SetCraftingRecipeID(int recipeID)
	{
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			GetCraftingManager().SetRecipeID(recipeID);
		}
		else
		{
			m_RecipeID = recipeID;			
		}		
	}
	
	// --------------------------------------------------
	// Action data for base building actions
	//---------------------------------------------------	
	ConstructionActionData GetConstructionActionData()
	{
		if ( !m_ConstructionActionData )
		{
			m_ConstructionActionData  = new ref ConstructionActionData();
		}
		
		return m_ConstructionActionData;
	}
	
	void ResetConstructionActionData()
	{
		if ( m_ConstructionActionData )
		{
			m_ConstructionActionData.ResetActionIndexes();
		}
	}
	
	// --------------------------------------------------
	// Action data for fireplace (indoor)
	//---------------------------------------------------	
	vector GetLastFirePoint()
	{
		return m_LastFirePoint;
	}	
	float GetLastFirePointRot()
	{
		return m_LastFirePointRot;
	}	
	int GetLastFirePointIndex()
	{
		return m_LastFirePointIndex;
	}

	void SetLastFirePoint( vector last_fire_point )
	{
		m_LastFirePoint = last_fire_point;
	}
	void SetLastFirePointRot( float last_fire_point_rot )
	{
		m_LastFirePointRot = last_fire_point_rot;
	}
	void SetLastFirePointIndex( int last_fire_point_index )
	{
		m_LastFirePointIndex = last_fire_point_index;
	}

	// --------------------------------------------------
	// QuickBar
	//---------------------------------------------------
	
	void RemoveQuickBarEntityShortcut(EntityAI entity)
	{
		int index = m_QuickBarBase.FindEntityIndex(entity);
		if(index != -1)
			m_QuickBarBase.SetEntityShortcut(entity,-1);
	}
	//---------------------------------------------------
	void SetEnableQuickBarEntityShortcut(EntityAI entity, bool value)
	{
		int index = m_QuickBarBase.FindEntityIndex(entity);
		if(index != -1)
			m_QuickBarBase.SetShotcutEnable(index,value);

	}
	//---------------------------------------------------
	int FindQuickBarEntityIndex(EntityAI entity)
	{
		int index;
		index = m_QuickBarBase.FindEntityIndex(entity);

		if(m_QuickBarBase.GetEntity(index) == NULL )
			return -1;

		return index;
	}
	//---------------------------------------------------
	
	int GetQuickBarSize()
	{
		return m_QuickBarBase.GetSize();
	}
	//---------------------------------------------------	
	EntityAI GetQuickBarEntity(int index)
	{
		return m_QuickBarBase.GetEntity(index);
	}
	//---------------------------------------------------
	void UpdateQuickBarEntityVisibility(EntityAI entity)
	{
		int i = FindQuickBarEntityIndex(entity);
		if( i >= 0 )
			m_QuickBarBase.UpdateShotcutVisibility(i);
	}
	//---------------------------------------------------
	void SetQuickBarEntityShortcut(EntityAI entity, int index, bool force = false )
	{
		m_QuickBarBase.SetEntityShortcut(entity, index, force);
	}
	//---------------------------------------------------
	void OnQuickbarSetEntityRequest(ParamsReadContext ctx)
	{
		m_QuickBarBase.OnSetEntityRequest(ctx);
	}
	//---------------------------------------------------	

	// Applies splint on all limbs.
	void ApplySplint()
	{
		float add_health_coef = 0.33;
		// The idea is to slightly increase health of broken limb so the player is still limping. Using more splints will help but each time less. 100% recovery can be achieved only through long term healing.
		if (m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
		{
			AddHealth("LeftLeg", 	"Health",	( GetMaxHealth("LeftLeg", "Health")  - GetHealth("LeftLeg", "Health")  ) * add_health_coef 	);
			AddHealth("RightLeg",	"Health",	( GetMaxHealth("RightLeg", "Health") - GetHealth("RightLeg", "Health") ) * add_health_coef 	);
			AddHealth("RightFoot",	"Health",	( GetMaxHealth("RightFoot", "Health") - GetHealth("RightFoot", "Health") ) * add_health_coef 	);
			AddHealth("LeftFoot",	"Health",	( GetMaxHealth("LeftFoot", "Health") - GetHealth("LeftFoot", "Health") ) * add_health_coef 	);
		}
	}
	
	void ProcessHoldBreath(float dT)
	{
		if( IsTryingHoldBreath() && CanStartConsumingStamina(EStaminaConsumers.HOLD_BREATH) )
		{
			DepleteStamina(EStaminaModifiers.HOLD_BREATH,dT);
			if( !m_IsHoldingBreath )
			{
				OnHoldBreathStart();
				m_IsHoldingBreath = true;
			}
		}
		else if( IsTryingHoldBreath() && m_IsHoldingBreath && CanConsumeStamina(EStaminaConsumers.HOLD_BREATH) )
		{
			DepleteStamina(EStaminaModifiers.HOLD_BREATH,dT);
		}
		else
		{
			if( m_IsHoldingBreath ) OnHoldBreathEnd();
			m_IsHoldingBreath = false;
		}
	}
	
	void OnHoldBreathStart()
	{
		//SendSoundEvent(SoundSetMap.GetSoundSetID("holdBreath_male_Char_SoundSet"));
		RequestSoundEvent(EPlayerSoundEventID.HOLD_BREATH, true);
	}
	
	void OnHoldBreathExhausted()
	{
		RequestSoundEvent(EPlayerSoundEventID.EXHAUSTED_BREATH, true);
	}
	
	void OnHoldBreathEnd()
	{
		//SendSoundEvent(SoundSetMap.GetSoundSetID("releaseBreath_male_Char_SoundSet"));
		RequestSoundEvent(EPlayerSoundEventID.RELEASE_BREATH, true);
	}
	
	override bool IsHoldingBreath()
	{
		return m_IsHoldingBreath;
	}
	
	override bool IsRefresherSignalingViable()
	{
		return false;
	}
	
	eMixedSoundStates GetMixedSoundStates()
	{
		return m_MixedSoundStates;
	}
	
	AbstractWave SaySoundSet(string name)
	{
		if( m_SaySoundLastSetName != name )
		{
			m_SaySoundParams = new SoundParams(name);
			m_SaySoundBuilder = new SoundObjectBuilder(m_SaySoundParams);

			m_SaySoundLastSetName = name;
		}
		
		m_SaySoundObject = m_SaySoundBuilder.BuildSoundObject();
		m_SaySoundObject.SetPosition(GetPosition());
		return GetGame().GetSoundScene().Play3D(m_SaySoundObject, m_SaySoundBuilder);
	}

	EntityAI FindCargoByBaseType(string searched_item)
	{
		EntityAI attachment;
		string item_name;
		int attcount = this.GetInventory().AttachmentCount();
		
		for (int att = 0; att < attcount; att++)
		{	
			attachment = GetInventory().GetAttachmentFromIndex(att);
			if ( attachment.IsItemBase() )
			{
				item_name = attachment.GetType();
				if ( GetGame().IsKindOf(item_name, searched_item) )
				{
					return attachment;
				}
			}
		}
		return NULL;
	}

	void InitEditor()
	{
		if ( GetGame().IsDebug() )
		{
			if ( !GetGame().IsMultiplayer()  &&  GetGame().GetPlayer()  &&  GetGame().GetPlayer().GetID() == this.GetID() )
			{
				PluginSceneManager scene_editor = PluginSceneManager.Cast( GetPlugin(PluginSceneManager) );
				scene_editor.InitLoad();
			}
		}
	}
	
	//---------------------------------------------------------------------------------------------------------------------------
	void OnPlayerLoaded()
	{
		//Print("PlayerBase | OnPlayerLoaded()");
		InitEditor();
		
		if ( GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			m_ModuleLifespan.SynchLifespanVisual( this, m_LifeSpanState, m_HasBloodyHandsVisible, m_HasBloodTypeVisible, m_BloodType );
		}	
	
		if ( m_Hud && IsControlledPlayer() /*&& ((GetGame().IsMultiplayer() && GetGame().IsClient()) || !GetGame().IsMultiplayer())*/)
		{
			m_Hud.UpdateBloodName();
			PPEffects.SetDeathDarkening(0);
			PPEffects.SetShockEffectColor(0);
			GetGame().GetUIManager().CloseAll();
			GetGame().GetMission().SetPlayerRespawning(false);
			//GetGame().GetUIManager().FindMenu(MENU_INGAME);
		}
		
		int slot_id = InventorySlots.GetSlotIdFromString("Head");
		m_CharactersHead = Head_Default.Cast(GetInventory().FindPlaceholderForSlot( slot_id ));
		CheckHairClippingOnCharacterLoad();
		UpdateHairSelectionVisibility();
		PreloadDecayTexture();
		
		Weapon_Base wpn = Weapon_Base.Cast(GetItemInHands());
		if (wpn)
			wpn.ValidateAndRepair();
		
		m_PlayerLoaded = true;
	}
	
	void SetPlayerDisconnected(bool state)
	{
		m_PlayerDisconnectProcessed = state;
	}
	
	bool IsPlayerDisconnected()
	{
		return m_PlayerDisconnectProcessed;
	}

	// --------------------------------------------------
	// Advanced placement
	//---------------------------------------------------
	
	//get hologram
	Hologram GetHologramServer()
	{
		return m_HologramServer;
	}
	
	Hologram GetHologramLocal()
	{
		return m_HologramLocal;
	}
	
	void PlacingStartServer( ItemBase item )
	{
		m_HologramServer = new Hologram( this, GetLocalProjectionPosition(), item );
		GetHologramServer().SetProjectionPosition( GetLocalProjectionPosition() );
		GetHologramServer().SetProjectionOrientation( GetLocalProjectionOrientation() );
		GetHologramServer().GetProjectionEntity().OnPlacementStarted( this );
		GetHologramServer().CheckPowerSource();
		GetHologramServer().RefreshVisual();
	}
	
	void PlacingStartLocal(ItemBase item)
	{
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			return;
		
		m_HologramLocal = new Hologram( this, GetLocalProjectionPosition(), item );
		GetHologramLocal().GetProjectionEntity().OnPlacementStarted( this );
	}
	
	void PlacingCancelServer()
	{
		EntityAI entity_in_hands = GetHumanInventory().GetEntityInHands();
		
		if ( IsPlacingServer() )
		{
			GetHologramServer().GetParentEntity().OnPlacementCancelled( this );
			
			delete m_HologramServer;
			return;
		}
		else if ( entity_in_hands && entity_in_hands.HasEnergyManager() )
		{
			if ( entity_in_hands.GetCompEM().IsPlugged() )
			{
				entity_in_hands.OnPlacementCancelled( this );
			}	
		}
	}
	
	//Called when item placement is canceled, will prevent quickbar usage until the item the player was placing is back in hands
	void LockHandsUntilItemHeld()
	{
		m_AreHandsLocked = true;
	}
	
	void PlacingCancelLocal()
	{
		EntityAI entity_in_hands = GetHumanInventory().GetEntityInHands();
		if ( entity_in_hands && entity_in_hands.HasEnergyManager() )
		{
			if ( entity_in_hands.GetCompEM().IsPlugged() )
			{
				entity_in_hands.OnPlacementCancelled( this );
			}	
		}
		delete m_HologramLocal;
	}
	
	void PlacingCompleteServer()
	{
		delete m_HologramServer;	
	}
	
	void PlacingCompleteLocal()
	{
		delete m_HologramLocal;
	}
	
	bool IsPlacingServer()
	{
		if ( m_HologramServer )
		{
			return true;
		}
		else
		{
			return false;			
		}
	}
	
	bool IsPlacingLocal()
	{
		if ( m_HologramLocal )
		{
			return true;
		}
		
		return false;			
	}
	
	bool TogglePlacingServer( int userDataType, ParamsReadContext ctx )
	{	
		if ( userDataType == INPUT_UDT_ADVANCED_PLACEMENT )
		{
			PlacingCancelServer();
			return true;
		}
		
		return false;
	}
	
	void RequestResetADSSync() //temporary solution, to be solved by special input
	{
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT && GetGame().IsMultiplayer() )
		{
			if (ScriptInputUserData.CanStoreInputUserData())
			{
				ScriptInputUserData ctx = new ScriptInputUserData;
				ctx.Write(INPUT_UDT_RESET_ADS);
				ctx.Send();
				m_ResetADS = true;
			}
		}
		else
			m_ResetADS = true;
	}
	
	bool ResetADSPlayerSync( int userDataType, ParamsReadContext ctx )
	{
		if ( userDataType == INPUT_UDT_RESET_ADS )
		{
			m_ResetADS = true;
			return true;
		}
		
		return false;	
	}
	
	void TogglePlacingLocal(ItemBase item = null)
	{	
		if ( IsPlacingLocal() )
		{
			if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT && GetGame().IsMultiplayer() )
			{
				if (ScriptInputUserData.CanStoreInputUserData())
				{
					ScriptInputUserData ctx = new ScriptInputUserData;
					ctx.Write(INPUT_UDT_ADVANCED_PLACEMENT);
					ctx.Send();
				}
			}
			PlacingCancelLocal();
		}
		else if (!item)
		{
			PlacingStartLocal( GetItemInHands() );
		}
		else
		{
			PlacingStartLocal(item);
		}
	}

	void SetLocalProjectionPosition( vector local_position )
	{
		m_LocalProjectionPosition = local_position;
	}
	
	void SetLocalProjectionOrientation( vector local_orientation )
	{
		m_LocalProjectionOrientation = local_orientation;
	}
	
	vector GetLocalProjectionPosition()
	{
		return m_LocalProjectionPosition;
	}
	
	vector GetLocalProjectionOrientation()
	{
		return m_LocalProjectionOrientation;
	}
	
	void AddToEnvironmentTemperature(float pTemperature)
	{
		if (m_Environment)
		{
			m_Environment.AddToEnvironmentTemperature(pTemperature);
		}
	}

	// ------------------------------------------------------------------------

	//! water contact (driven by Environment)
	void SetInWater(bool pState)
	{
		m_IsInWater = pState;
		SetSynchDirty();
	}

	bool IsInWater()
	{
		return m_IsInWater;
	}

	// -------------------------------------------------------------------------
	void ~PlayerBase()
	{
		if( GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
			ClientData.RemovePlayerBase( this );
		
		if( m_FliesEff )
			m_FliesEff.Stop();
		if( m_SoundFliesEffect )
		{
			StopSoundSet(m_SoundFliesEffect);
			//SEffectManager.DestroySound(m_SoundFliesEffect);
			//m_SoundFliesEffect = null;
		}
	}

	void OnCameraChanged(DayZPlayerCameraBase new_camera)
	{
		m_CameraSwayModifier = new_camera.GetWeaponSwayModifier();
		m_CurrentCamera = new_camera;
	}
	
	DayZPlayerCamera GetCurrentPlayerCamera()
	{
		return m_CurrentCamera;
	}
	
	bool IsCurrentCameraAimedAtGround()
	{
		if (!m_CurrentCamera)
			return false;
		
		return m_CurrentCamera.GetCurrentPitch() < PlayerConstants.CAMERA_THRESHOLD_PITCH;
	} 
	
	BleedingSourcesManagerServer GetBleedingManagerServer()
	{
		return m_BleedingManagerServer;
	}
	
	BleedingSourcesManagerRemote GetBleedingManagerRemote()
	{
		return m_BleedingManagerRemote;
	}

	SymptomManager GetSymptomManager()
	{
		return m_SymptomManager;
	}
	VirtualHud GetVirtualHud()
	{
		return m_VirtualHud;
	}

	TransferValues GetTransferValues()
	{
		return m_TrasferValues;
	}

	DebugMonitorValues GetDebugMonitorValues()
	{
		return m_DebugMonitorValues;
	}
	
	// -------------------------------------------------------------------------
	/*bool  IsCraftingSetUp()
	{
		return m_IsCraftingReady;
	}*/
	// -------------------------------------------------------------------------
	/*void  PerformRecipe()
	{*/
		/*
		Debug.Log("Ingredient1: "+ToString(m_Item1.Ptr().GetType()),"recipes");
		Debug.Log("Ingredient2: "+ToString(m_Item2.Ptr().GetType()),"recipes");
		*/
		/*int id = GetCraftingMeta().GetRecipeID();
		ItemBase item1 = GetCraftingMeta().GetIngredient1();
		ItemBase item2 = GetCraftingMeta().GetIngredient2();
		
		Debug.Log("PerformRecipe called on player: "+ string.ToString(this),"recipes");
		
		if ( m_ModuleRecipesManager )
		{
			if( !item1 || !item2 )
			{
				Debug.Log("PerformRecipe: At least one of the object links is now null, not performing the recipe","recipes");
			}
			else
			{

				m_ModuleRecipesManager.PerformRecipeServer(id, item1,item2,this);
			}
			RequestCraftingDisable();
		}
	}*/
	// -------------------------------------------------------------------------
	/*float GetCraftingSetUpDistance()
	{
		return Math.AbsFloat( vector.Distance( GetCraftingMeta().GetInitPos(), GetPosition() ) );
	}*/
	// -------------------------------------------------------------------------

	/*void RequestCraftingSetup(int id, EntityAI item1, EntityAI item2, int craft_type)
	{
		if( !GetGame().IsMultiplayer() || GetGame().IsClient() ) 
		{
			SetUpCraftingClient(id,item1,item2,craft_type);
			SendCraftingMeta();
		}

	}*/

	/*void RequestCraftingDisable()
	{
		if( GetGame().IsServer() ) 
		{
			SendDisableRequestToClient();
			DisableCrafting();
		}

	}*/
	
	/*private void SendDisableRequestToClient()
	{
		GetGame().RPCSingleParam(this, ERPCs.RPC_CRAFTING_DISABLE, NULL,this);
	}*/

	/*private void OnReceiveDisableRequest()
	{
		DisableCrafting();
	}*/
	
	/*private void SendCraftingMeta()
	{
		array<ref Param> params = new array<ref Param>;
		CraftingMeta cm = GetCraftingMeta();
		cm.SerializeValues(params);
		GetGame().RPC(this, ERPCs.RPC_CRAFTING_SETUP, params,this);
	}*/

	/*private void OnReceiveCraftingMeta(ParamsReadContext ctx)
	{
		CreateCraftingMeta(0,NULL,NULL,"0 0 0", 0,0);
		GetCraftingMeta().DeserializeValuesCtx(ctx);
		SetUpCraftingServer();
		
	}*/
	// -------------------------------------------------------------------------
	/*private void SetUpCraftingServer()
	{
		if( GetGame().IsMultiplayer() && GetGame().IsServer() ) 
		{
			m_IsCraftingReady = true;
			m_ModuleRecipesManager.OnCraftingSetUpServer( GetCraftingMeta(), this );
		}
	}*/
	
	/*private void SetUpCraftingClient( int id, EntityAI item1, EntityAI item2, int craft_type)
	{
		if( !GetGame().IsMultiplayer() || GetGame().IsClient() ) 
		{
			m_IsCraftingReady = true;
			
			float specialty_weight = m_ModuleRecipesManager.GetRecipeSpecialty(id);
			float length = m_ModuleRecipesManager.GetRecipeLengthInSecs(id);
			CreateCraftingMeta(id, item1, item2, GetPosition(), length, specialty_weight);
			m_ModuleRecipesManager.OnCraftingSetUpClient( GetCraftingMeta(), this );
			Debug.Log("SetUpCrafting2 called for id: "+ id.ToString()+ " on player: "+ this.ToString(),"recipes");
			if ( craft_type != AT_WORLD_CRAFT )
			{
				ActionManagerClient mngr = GetActionManager();
				mngr.DisableActions();
				ActionTarget actionTarget;		
				if ( item2 == GetItemInHands() ) 
				{
					actionTarget = new ActionTarget(item1, -1, vector.Zero, -1);
					mngr.InjectContinuousAction(craft_type,actionTarget,item2);
				}
				else
				{
					actionTarget = new ActionTarget(item2, -1, vector.Zero, -1);
					mngr.InjectContinuousAction(craft_type,actionTarget,item1);
				}
			}			
		}

	}*/

	// -------------------------------------------------------------------------
	/*void DisableCrafting()
	{
		m_IsCraftingReady = false;
		if( !GetGame().IsMultiplayer() || GetGame().IsClient() ) 
		{	
			ActionManagerClient mngr = GetActionManager();
			if ( mngr) 
			{
				mngr.EnableActions();
				GetCraftingMeta() = NULL;
			}
		}
	}*/
	
	//--------------------------------------------------------------------------
	void OnScheduledTick(float deltaTime)
	{
		if( !IsPlayerSelected() || !IsAlive() ) return;
		if( m_ModifiersManager ) m_ModifiersManager.OnScheduledTick(deltaTime);
		if( m_NotifiersManager ) m_NotifiersManager.OnScheduledTick();
		if( m_TrasferValues ) m_TrasferValues.OnScheduledTick(deltaTime);
		if( m_VirtualHud ) m_VirtualHud.OnScheduledTick();
		if( GetBleedingManagerServer() ) GetBleedingManagerServer().OnTick(deltaTime);
		
		// Check if electric device needs to be unplugged
		ItemBase heldItem = GetItemInHands();
		if ( heldItem && heldItem.HasEnergyManager() && heldItem.GetCompEM().IsPlugged() )
		{
			// Now we know we are working with an electric device which is plugged into a power source.
			EntityAI placed_entity = heldItem;
					
			// Unplug the device when the player is too far from the power source.
			placed_entity.GetCompEM().UpdatePlugState();
		}
	}
	
	void OnCommandHandlerTick(float delta_time, int pCurrentCommandID)
	{
		if( !IsAlive() )
		{
			if ( !m_DeathSyncSent && m_KillerData )
			{
				SyncEvents.SendEntityKilled(this, m_KillerData.m_Killer, m_KillerData.m_MurderWeapon, m_KillerData.m_KillerHiTheBrain);
				//Print("Sending Death Sync, yay! Headshot by killer = " + m_KillerData.m_KillerHiTheBrain);
				//Print("And was he killed by headshot in general? = " + m_KilledByHeadshot);
				m_DeathSyncSent = true;
			}
			return;
		}
		if( m_DebugMonitorValues )
			m_DebugMonitorValues.OnScheduledTick(delta_time);
		if( GetSymptomManager() )
			GetSymptomManager().OnTick(delta_time, pCurrentCommandID, m_MovementState);//needs to stay in command handler tick as it's playing animations
		//if( GetBleedingManagerServer() ) GetBleedingManagerServer().OnTick(delta_time);
		
		DayZPlayerInstanceType instType = GetInstanceType();		
		if( instType == DayZPlayerInstanceType.INSTANCETYPE_CLIENT || instType == DayZPlayerInstanceType.INSTANCETYPE_REMOTE )
		{ 
			if( GetPlayerSoundEventHandler() )
				GetPlayerSoundEventHandler().OnTick(delta_time);

			//! is not equal to
			if( instType != DayZPlayerInstanceType.INSTANCETYPE_REMOTE ) 
			{
				#ifdef DEVELOPER
				if( m_WeaponDebug )
				{
					m_WeaponDebug.OnCommandHandlerUpdate();
				}
				#endif
			}

		}
		m_AnimCommandStarting = HumanMoveCommandID.None;
	}
	
	bool m_ShowDbgUI = true;
	int m_DbgListSelection = 0;
	float m_DbgSliderValue = 0.0;
	ref array<string> m_DbgOptions = {"jedna", "dva", "tri"};
	
	NotifiersManager GetNotifiersManager()
	{
		return m_NotifiersManager;
	}
	//--------------------------------------------------------------------------
	void OnTick()
	{
		float deltaT = (GetGame().GetTime() - m_LastTick) / 1000;
		if ( m_LastTick < 0 )  deltaT = 0;//first tick protection
		m_LastTick = GetGame().GetTime();
		
		//PrintString("deltaT: " + deltaT);
		//PrintString("at time: " + m_LastTick);
		OnScheduledTick(deltaT);		
		
		
	}
	// -------------------------------------------------------------------------
	override void EEItemIntoHands(EntityAI item)
	{
		super.EEItemIntoHands( item );

		Weapon_Base w;
		if (item && Class.CastTo(w, item))
		{
			w.ResetWeaponAnimState();
			
			HumanCommandMove cm = GetCommand_Move();
			if ( cm )
			{
				cm.SetMeleeBlock( false );
				GetMeleeFightLogic().SetBlock( false );
			}
		}
		
		//SetOpticsPreload(true,item);
	}
	
	override void EEItemOutOfHands(EntityAI item)
	{
		super.EEItemOutOfHands( item );
		if ( IsPlacingLocal() )
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(TogglePlacingLocal);
		}
		
		if ( !IsAlive() )
			OnItemInHandsChanged();
		
		//SetOpticsPreload(false,item);
	}
	
	override void CommandHandler(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)	
	{
		// lower implement 
		super.CommandHandler(pDt,pCurrentCommandID,pCurrentCommandFinished);
		//PrintString("pCurrentCommandID="+pCurrentCommandID.ToString());
		//PrintString(GetActionManager().GetRunningAction().ToString());
		m_dT = pDt;
		
		CheckZeroSoundEvent();
		CheckSendSoundEvent();
		
		ProcessADDModifier();
		/*
		m_IsSwimming = pCurrentCommandID == DayZPlayerConstants.COMMANDID_SWIM;
		m_IsClimbingLadder pCurrentCommandID != DayZPlayerConstants.COMMANDID_LADDER
		*/
				
		GetDayZPlayerInventory().HandleInventory(pDt);
		ProcessHoldBreath(pDt);
		ActionManagerBase		mngr = GetActionManager();
		HumanInputController hic = GetInputController();
		
		if (m_AreHandsLocked && GetHumanInventory().GetEntityInHands())
		{
			m_AreHandsLocked = false;
		}
		
		// freelook camera memory for weapon raycast
		if (hic.CameraIsFreeLook() && m_DirectionToCursor == vector.Zero)
		{
			m_DirectionToCursor = GetGame().GetCurrentCameraDirection();
		}
		else if (!hic.CameraIsFreeLook() && m_DirectionToCursor != vector.Zero)
		{
			m_DirectionToCursor = vector.Zero;
		}
		
		if( m_WeaponManager )
		{
			m_WeaponManager.Update(pDt);
		}
		if( m_EmoteManager && IsPlayerSelected() ) 
		{
			m_EmoteManager.Update(pDt);	
			//Print("selected! " + IsPlayerSelected());
		}
		if( m_RGSManager )
		{
			 m_RGSManager.Update();
		}
/*		if( m_VehicleManager ) 
		{
			m_VehicleManager.Update(pDt);	
		}*/
		if( m_StanceIndicator ) 
		{
			m_StanceIndicator.Update();
		}
		if( m_StaminaHandler ) 
		{
			m_StaminaHandler.Update(pDt, pCurrentCommandID);
		}
		if( m_InjuryHandler )
		{
			m_InjuryHandler.Update(pDt);
		}
		if( m_HCAnimHandler )
		{
			m_HCAnimHandler.Update(pDt, m_MovementState);
		}
		if ( m_ShockHandler )
		{
			m_ShockHandler.Update(pDt);
		}
			
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer() )
		{
			GetPlayerSoundManagerServer().Update();
			ShockRefill(pDt);
			FreezeCheck();
			if ( m_Environment )
			{
				m_Environment.Update(pDt);
			}
		}
		
		GetHumanInventory().Update(pDt);
		
		UpdateDelete();
		//PrintString(pCurrentCommandID.ToString());
		//PrintString(m_IsUnconscious.ToString());
		//PrintString("currentCommand:" +pCurrentCommandID.ToString());
		
		if (mngr && hic)
		{
			mngr.Update(pCurrentCommandID);
			
			//PrintString(m_ShouldBeUnconscious.ToString());
			if(pCurrentCommandID == DayZPlayerConstants.COMMANDID_UNCONSCIOUS)
			{
				if( !m_UnconsciousDebug )
				{
					OnUnconsciousUpdate(pDt, m_LastCommandBeforeUnconscious );
					if( !m_IsUnconscious ) 
					{
						m_IsUnconscious = true;
						OnUnconsciousStart();
					}
					if( !m_ShouldBeUnconscious )
					{
						
						HumanCommandUnconscious	hcu = GetCommand_Unconscious();
						if(hcu) 
						{
							hcu.WakeUp();
						}
					}
				}
			}
			else
			{
				if(m_ShouldBeUnconscious && pCurrentCommandID != DayZPlayerConstants.COMMANDID_UNCONSCIOUS && pCurrentCommandID != DayZPlayerConstants.COMMANDID_DEATH && pCurrentCommandID != DayZPlayerConstants.COMMANDID_FALL && pCurrentCommandID != DayZPlayerConstants.COMMANDID_MOD_DAMAGE && pCurrentCommandID != DayZPlayerConstants.COMMANDID_DAMAGE)
				{			
					m_LastCommandBeforeUnconscious = pCurrentCommandID;
					HumanCommandVehicle vehicleCommand = GetCommand_Vehicle();
					if( vehicleCommand ) 
					{
						if (vehicleCommand.ShouldBeKnockedOut())
						{
							m_TransportCache = null;
							vehicleCommand.KnockedOutVehicle();
							int damageHitAnim = 1;
							float damageHitDir = 0;
							StartCommand_Damage(damageHitAnim, m_DamageHitDir);
							TryHideItemInHands(false,true);
						}
						else
						{
							m_TransportCache = vehicleCommand.GetTransport();	
						}
					}
					StartCommand_Unconscious(0);	
				}
				if( m_IsUnconscious /*&& pCurrentCommandID != DayZPlayerConstants.COMMANDID_DEATH*/)
				{
					m_IsUnconscious = false;
					OnUnconsciousStop(pCurrentCommandID);
				}
			}
			
			// quickbar use
			int quickBarSlot = hic.IsQuickBarSlot();
			if( quickBarSlot && IsAlive())
			{
				if (hic.IsQuickBarSingleUse())
				{
					OnQuickBarSingleUse(quickBarSlot);
					//Print("PlayerBase.c IsQuickBarSingleUse - slot: " + quickBarSlot.ToString());
				}
				if (hic.IsQuickBarContinuousUseStart() && ((!GetGame().IsMultiplayer() || GetGame().IsClient()) && !GetGame().GetUIManager().GetMenu()))
				{
					OnQuickBarContinuousUseStart(quickBarSlot);
					Print("PlayerBase.c IsQuickBarContinuousUseStart - slot: " + quickBarSlot.ToString());
				}
				if (hic.IsQuickBarContinuousUseEnd() && ((!GetGame().IsMultiplayer() || GetGame().IsClient())))
				{
					OnQuickBarContinuousUseEnd(quickBarSlot);
					Print("PlayerBase.c IsQuickBarContinuousUseEnd - slot: " + quickBarSlot.ToString());
				}
			}
			
			// handheld optics zooming
			ItemOptics optic = ItemOptics.Cast(GetItemInHands());
			Input input = GetGame().GetInput();
			if (hic.IsContinuousUse() && input.LocalPress("UAZoomInOptics") && optic && optic.IsInOptics())
			{
				optic.StepFOVUp();
			}
			if (hic.IsContinuousUse() && input.LocalPress("UAZoomOutOptics") && optic && optic.IsInOptics())
			{
				optic.StepFOVDown();
			}
			
			/*if ((pCurrentCommandID == DayZPlayerConstants.COMMANDID_ACTION || pCurrentCommandID == DayZPlayerConstants.COMMANDID_MOVE || pCurrentCommandID == DayZPlayerConstants.COMMANDID_LADDER || pCurrentCommandID == DayZPlayerConstants.COMMANDID_SWIM ) ) 
			{
				mngr.Update(); // checks for suitable action and sets it
			}*/
		}
		if (m_StaminaHandler && hic)
		{
			//! SPRINT: enable/disable - based on stamina; disable also when raised
			if ( !CanConsumeStamina(EStaminaConsumers.SPRINT) || !CanSprint() )
			{
				hic.LimitsDisableSprint(true);
			}
			else
			{
				hic.LimitsDisableSprint(false);
			}
		}

		//map closing - feel free to move to different "update" if it does not belong here
		if ( (!GetGame().IsMultiplayer() || GetGame().IsClient()) && IsMapOpen() && !m_MapCloseRequestProcessed)
		{
			if ( m_hac && !GetGame().GetUIManager().IsMenuOpen(MENU_MAP) )
			{
				CloseMap();
				m_MapCloseRequestProcessed = true;
			}
		}
		
#ifdef BOT
		if (m_Bot)
			m_Bot.OnUpdate(pDt);
#endif
		if (m_CheckMeleeItem && (!GetGame().IsMultiplayer() || GetGame().IsClient()) && ScriptInputUserData.CanStoreInputUserData() )
		{
			bool result = CheckMeleeItemDamage(m_CheckMeleeItem);
			//if (result)
				SetCheckMeleeItem();
		}
		OnCommandHandlerTick(pDt, pCurrentCommandID);
	}
	
	//! terminates map animation callback and re-enables controls
	void CloseMap()
	{
		if (m_hac)
		{
			ScriptInputUserData ctx = new ScriptInputUserData;
			if ( ctx.CanStoreInputUserData() )
			{
				if ( GetGame().IsMultiplayer() && GetGame().IsClient() )
				{
					m_hac.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
					ctx.Write(INPUT_UDT_STANDARD_ACTION_END_REQUEST);
					ctx.Write(DayZPlayerConstants.CMD_ACTIONINT_END);
					ctx.Send();
				}
				else if ( !GetGame().IsMultiplayer() )
				{
					m_hac.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
				}
			}
		}
		
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( !GetGame().GetUIManager().GetMenu() )
				GetGame().GetMission().PlayerControlEnable(false);
			if (GetGame().GetUIManager().IsMenuOpen(MENU_MAP))
				GetGame().GetUIManager().FindMenu(MENU_MAP).Close();
		}
	}
	
	void SetMapOpen(bool state)
	{
		m_MapOpen = state;
		m_MapCloseRequestProcessed = !state;
	}
	
	bool IsMapOpen()
	{
		return m_MapOpen;
	}
	
	void SetCheckMeleeItem(ItemBase item = null)
	{
		m_CheckMeleeItem = item;
	}
	
	/*
	void AirTemperatureCheck()
	{
		if( !m_Environment.IsTemperatureSet() )
			return;
		float air_temperature = m_Environment.GetTemperature();
		int level = 0;//default
		if( MiscGameplayFunctions.IsValueInRange( air_temperature, PlayerConstants.BREATH_VAPOUR_THRESHOLD_HIGH, PlayerConstants.BREATH_VAPOUR_THRESHOLD_LOW) )
		{
			float value = Math.InverseLerp( PlayerConstants.BREATH_VAPOUR_THRESHOLD_LOW, PlayerConstants.BREATH_VAPOUR_THRESHOLD_HIGH,air_temperature);
			value = Math.Clamp(value,0,1);
			level = Math.Round(Math.Lerp(1,BREATH_VAPOUR_LEVEL_MAX,value));
		}
		else if(air_temperature < PlayerConstants.BREATH_VAPOUR_THRESHOLD_HIGH)
		{
			level = BREATH_VAPOUR_LEVEL_MAX;
		}
		if( level != m_BreathVapour )
		{
			m_BreathVapour = level;
			SetSynchDirty();
		}
	}
	*/
	void FreezeCheck()
	{
		float heat_comfort = GetStatHeatComfort().Get();
		int level;
		if( heat_comfort <= PlayerConstants.THRESHOLD_HEAT_COMFORT_MINUS_WARNING )
		{
			float value = Math.InverseLerp( PlayerConstants.THRESHOLD_HEAT_COMFORT_MINUS_WARNING, PlayerConstants.THRESHOLD_HEAT_COMFORT_MINUS_CRITICAL,heat_comfort);
			level = Math.Lerp(1,7,value);
			level = Math.Clamp(value,1,7);
			/*
			value = Math.Clamp(value,0,1);
			level = Math.Round(value * SHAKE_LEVEL_MAX);//translate from normalized value to levels
			*/
		}
		if( level != m_Shakes )
		{
			m_Shakes = level;
			SetSynchDirty();
		}
	}
	
	void OnUnconsciousStart()
	{
		CloseInventoryMenu();
		//if( GetInventory() ) GetInventory().LockInventory(LOCK_FROM_SCRIPT);
		
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)//server
		{
			
		}
		
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			SetInventorySoftLock(true);
			EntityAI entity_in_hands = GetHumanInventory().GetEntityInHands();
			if( entity_in_hands && CanDropEntity(entity_in_hands) && !IsRestrained() )
			{
				//PredictiveDropEntity(entity_in_hands);
				DropItem(ItemBase.Cast(entity_in_hands));
				//GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerDropEntity,1000,false,( GetHumanInventory().GetEntityInHands() ));
			}
		}
		
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer() )
		{
			SetSynchDirty();
			 
			// disable voice communication
			GetGame().EnableVoN(this, false);
			
			if ( m_AdminLog )
			{
				m_AdminLog.UnconStart( this );
			}
		}
		
		SetMasterAttenuation("UnconsciousAttenuation");
		
		PrintString("OnUnconsciousStart");
	}
	
	void OnUnconsciousStop(int pCurrentCommandID)
	{		
		SetSynchDirty();
		//if( GetInventory() ) GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);
		m_UnconsciousTime = 0;
		m_UnconsciousVignetteTarget = 2;
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ) 
		{
			if ( pCurrentCommandID != DayZPlayerConstants.COMMANDID_DEATH )
			{
				PPEffects.SetUnconsciousnessVignette(0);
				if ( GetGame().GetUIManager().IsDialogVisible() )
				{
					GetGame().GetUIManager().CloseDialog();
				}
				if ( GetGame().GetUIManager().IsMenuOpen(MENU_RESPAWN_DIALOGUE) )
				{
					GetGame().GetUIManager().FindMenu(MENU_RESPAWN_DIALOGUE).Close();
				}
			}
			SetInventorySoftLock(false);
		}
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
		{
			// enable voice communication
			GetGame().EnableVoN(this, true);
			
			if ( m_AdminLog )
			{
				m_AdminLog.UnconStop( this );
			}
		}
		
		SetMasterAttenuation("");
		
		PrintString("OnUnconsciousStop");
	}

	void OnUnconsciousUpdate(float pDt, int last_command)
	{
		m_UnconsciousTime += pDt;
		if( GetGame().IsServer() )
		{
			int shock_simplified = SimplifyShock();
			
			if( m_ShockSimplified != shock_simplified )
			{
				m_ShockSimplified = shock_simplified;
				SetSynchDirty();
			}
			
			//PrintString(last_command.ToString());
			//PrintString(DayZPlayerConstants.COMMANDID_SWIM.ToString());
			
			if( m_UnconsciousTime > PlayerConstants.UNCONSCIOUS_IN_WATER_TIME_LIMIT_TO_DEATH && last_command == DayZPlayerConstants.COMMANDID_SWIM )
			{
				SetHealth("","",-100);
			}
		}
		if( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			if(GetPulseType() == EPulseType.REGULAR)
			{
				float shock_simple_normalized = GetSimplifiedShockNormalized();
	
				float sin = Math.Sin(m_UnconsciousTime * 0.3);
				float sin_normalized = (sin + 1) / 2;
				if(sin_normalized < 0.05)
				{
					m_UnconsciousVignetteTarget = (1 - shock_simple_normalized / 3) * 2/*vignette max*/;
				}
				float vignette = Math.Lerp(2,m_UnconsciousVignetteTarget, sin_normalized);
				//PrintString(m_UnconsciousVignetteTarget.ToString());
				PPEffects.SetUnconsciousnessVignette(vignette);
			}
		}
	}
	
	int SimplifyShock()
	{
		int shock = Math.Lerp( 0, SIMPLIFIED_SHOCK_CAP, GetHealth("","Shock") / GetMaxHealth("","Shock") );
		shock = Math.Clamp(shock, 0, SIMPLIFIED_SHOCK_CAP);
		return shock;
	}
	
	float GetSimplifiedShockNormalized()
	{
		return (m_ShockSimplified / SIMPLIFIED_SHOCK_CAP);
	}
	
	override bool IsUnconscious()
	{
		return m_IsUnconscious;
	}
	
	override bool CanBeTargetedByAI(EntityAI ai)
	{
		return super.CanBeTargetedByAI( ai ) && !IsUnconscious();
	}
	
	void GiveShock(float shock)
	{
		AddHealth("","Shock",shock);
	}
	
	
	void OnRestrainStart()
	{
		CloseInventoryMenu();
		GetGame().GetMission().PlayerControlEnable(true);
	}
	
	void ShockRefill(float pDt)
	{
		if( !IsAlive() ) return;
		if( GetGame().GetTime() >  m_LastShockHitTime + PlayerConstants.SHOCK_REFILL_COOLDOWN_AFTER_HIT && GetPulseType() == EPulseType.REGULAR)
		{
			float refill_speed;
			if( IsUnconscious() )
			{
				refill_speed =  PlayerConstants.SHOCK_REFILl_UNCONSCIOUS_SPEED;
			}
			else if (m_BrokenLegState != eBrokenLegs.BROKEN_LEGS || (m_MovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_PRONE || m_MovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDPRONE))
			{
				refill_speed =  PlayerConstants.SHOCK_REFILL_CONSCIOUS_SPEED;
			}
			else  if ( m_BrokenLegState == eBrokenLegs.BROKEN_LEGS && (IsSwimming() || IsClimbingLadder()) )
			{
				refill_speed =  PlayerConstants.SHOCK_REFILl_UNCONSCIOUS_SPEED;
			}
			else
				refill_speed = 0; //Block shock regen when standing with broken legs
			
			AddHealth("","Shock", pDt * refill_speed );
		}
		
	}
	
	//BrokenLegs
	// -----------------------
	
	//First time activation
	void SetBrokenLegs(int stateId)
	{
		//Raise broken legs flag and force to prone
		if (stateId != eBrokenLegs.NO_BROKEN_LEGS)
		{
			if ( stateId == eBrokenLegs.BROKEN_LEGS )
			{
				//Activate the BrokenLegs Notifier
				m_NotifiersManager.ActivateByType(eNotifiers.NTF_FRACTURE);
				m_BrokenLegState = eBrokenLegs.BROKEN_LEGS;
				BrokenLegForceProne(true);
				//SetSynchDirty();
				m_InjuryHandler.CheckValue(true);
				
				DayZPlayerSyncJunctures.SendBrokenLegs(this, m_CanPlayBrokenLegSound, m_BrokenLegState, m_LocalBrokenState);
			}
		}
		else
		{
			m_BrokenLegState = eBrokenLegs.NO_BROKEN_LEGS; //Safeguard used to ensure proper state setup
			m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.BROKEN_LEGS;
			m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.BROKEN_LEGS_SPLINT;
			DayZPlayerSyncJunctures.SendBrokenLegs(this, m_CanPlayBrokenLegSound, m_BrokenLegState, m_LocalBrokenState); //Synchronize one last time before deactivation of state
		}
	}
	
	//Update of state
	void UpdateBrokenLegs(int stateId)
	{
		//Raise broken legs flag and force to prone
		if (stateId != eBrokenLegs.NO_BROKEN_LEGS)
		{
			if ( stateId == eBrokenLegs.BROKEN_LEGS_SPLINT )
			{
				//Activate the BrokenLegs Notifier
				m_NotifiersManager.ActivateByType(eNotifiers.NTF_FRACTURE);
				m_BrokenLegState = eBrokenLegs.BROKEN_LEGS_SPLINT;
				if ( m_MovementState.m_iStanceIdx != DayZPlayerConstants.STANCEIDX_PRONE )
				{
					m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.PRONE_ANIM_OVERRIDE;
					m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.BROKEN_LEGS;
					m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask | eInjuryOverrides.BROKEN_LEGS_SPLINT;
				}
				//SetSynchDirty();
				m_InjuryHandler.CheckValue(false);
				
				m_LocalBrokenState = m_BrokenLegState;
				
				//Extra safeguard to break out of state if synch failed
				if (!IsWearingSplint())
				{
					Debug.LogError("Player is in state " + m_BrokenLegState + " and is wearing splint : " + IsWearingSplint() + " and modifier is : " + m_ModifiersManager.IsModifierActive(eModifiers.MDF_BROKEN_LEGS));
					//m_BrokenLegState = eBrokenLegs.NO_BROKEN_LEGS;
					//m_LocalBrokenState = m_BrokenLegState;
				}
				
				DayZPlayerSyncJunctures.SendBrokenLegs(this, false, m_BrokenLegState, m_LocalBrokenState);
			}
			else if ( stateId == eBrokenLegs.BROKEN_LEGS )
			{
				//Activate the BrokenLegs Notifier
				m_NotifiersManager.ActivateByType(eNotifiers.NTF_FRACTURE);
				m_BrokenLegState = eBrokenLegs.BROKEN_LEGS;
				
				//Apply movement anim depending on stance
				if ( m_MovementState.m_iStanceIdx != DayZPlayerConstants.STANCEIDX_PRONE )
				{
					m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.PRONE_ANIM_OVERRIDE;
					m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.BROKEN_LEGS_SPLINT;
					m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask | eInjuryOverrides.BROKEN_LEGS;
				}
				
				BrokenLegForceProne();
				BrokenLegWalkShock();
				//SetSynchDirty();
				m_InjuryHandler.CheckValue(false);
				
				DayZPlayerSyncJunctures.SendBrokenLegs(this, false, m_BrokenLegState, m_LocalBrokenState);
			}
		}
		else if (stateId == eBrokenLegs.NO_BROKEN_LEGS)
		{
			//Deactivate the modifier
			m_BrokenLegState = eBrokenLegs.NO_BROKEN_LEGS;
			m_NotifiersManager.DeactivateByType(eNotifiers.NTF_FRACTURE);
			m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.BROKEN_LEGS;
			m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.BROKEN_LEGS_SPLINT;
			DayZPlayerSyncJunctures.SendBrokenLegs(this, false, m_BrokenLegState, m_LocalBrokenState);
			//SetSynchDirty();
		}
	}
	
	void BreakLegSound()
	{
		if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT)
		{
			if ( m_BrokenLegState == eBrokenLegs.BROKEN_LEGS && m_CanPlayBrokenLegSound )
			{
				PlaySoundSet(m_BrokenLegSound, SOUND_BREAK_LEG, 0.1, 0.1);
				m_CanPlayBrokenLegSound = false;
				SetSynchDirty();
			}
		}
	}

	//Execute all relevant tests before forcing character to prone
	void BrokenLegForceProne(bool forceOverride = false)
	{
		if (!IsInWater() && !IsSwimming() && !IsClimbingLadder() && !IsInVehicle() && !IsClimbing() && DayZPlayerUtils.PlayerCanChangeStance(this, DayZPlayerConstants.STANCEIDX_PRONE) )
		{
			//Force to prone if player tries moving while not prone OR if it is first time legs break
			if ( (forceOverride == true || m_BrokenLegState != m_LocalBrokenState) && (m_MovementState.m_iStanceIdx != DayZPlayerConstants.STANCEIDX_PRONE && m_MovementState.m_iStanceIdx != DayZPlayerConstants.STANCEIDX_RAISEDPRONE))
			{
				EntityAI attachment;
				Class.CastTo(attachment, GetItemOnSlot("Splint_Right"));
				if ( attachment && attachment.GetType() == "Splint_Applied" )
				{
					attachment.Delete();
				}
				
				m_CanPlayBrokenLegSound = true;
				m_ShockHandler.SetShock(PlayerConstants.BROKEN_LEGS_INITIAL_SHOCK);
				m_ShockHandler.CheckValue(true);
				
				if ( m_ShockHandler.GetCurrentShock() >= 25 ) //Prevent conflict with unconsciousness by not forcing prone when going uncon (25 shock or less left)
				{
					//Get command move and verify not null
					HumanCommandMove hcm = StartCommand_Move();  
					hcm = GetCommand_Move(); 
					if (hcm)
					{
						hcm.ForceStance(DayZPlayerConstants.STANCEIDX_PRONE);
					}
				}
				SetLegHealth();
				m_LocalBrokenState = m_BrokenLegState;
			}
			else
				m_CanPlayBrokenLegSound = false;
		}
	}
	
	//Used to inflict shock when player is walking (only inflicted on Update timer)
	void BrokenLegWalkShock()
	{
		//No need to pursue here if player is prone as the following logic is not applied
		if ( m_MovementState.m_iStanceIdx != DayZPlayerConstants.STANCEIDX_PRONE && m_MovementState.m_iStanceIdx != DayZPlayerConstants.STANCEIDX_RAISEDPRONE )
		{
			float avgLegHealth = GetHealth("RightLeg","") + GetHealth("LeftLeg","") + GetHealth("RightFoot","") + GetHealth("LeftFoot","");
			avgLegHealth *= 0.25; //divide by 4 to make the average leg health;
			
			if (IsSwimming() && m_MovementState.m_iMovement != 0)
			{
				m_ShockHandler.SetShock(PlayerConstants.BROKEN_LEGS_SHOCK_SWIM);
			}
			else if (IsClimbingLadder() && m_MovementState.m_iMovement != 0)
			{
				MovingShock(avgLegHealth, PlayerConstants.BROKEN_LEGS_HIGH_SHOCK_WALK, PlayerConstants.BROKEN_LEGS_MID_SHOCK_WALK, PlayerConstants.BROKEN_LEGS_LOW_SHOCK_WALK);
			}
			else if ( (m_MovementState.m_iMovement != 0 && m_MovementState.m_iMovement != 1) )
			{
				MovingShock(avgLegHealth, PlayerConstants.BROKEN_LEGS_HIGH_SHOCK_WALK, PlayerConstants.BROKEN_LEGS_MID_SHOCK_WALK, PlayerConstants.BROKEN_LEGS_LOW_SHOCK_WALK);
			}
			else 
			{
				//Here apply shock if player is standing or crouched and STANDING STILL
				m_ShockHandler.SetShock(PlayerConstants.BROKEN_LEGS_STAND_SHOCK);
			}
			
			m_ShockHandler.CheckValue(true);
		}
	}
	
	//Always use the same thresholds but allow passing of different shock values
	void MovingShock(float legHealth, float highShock, float midShock, float lowShock)
	{
		if (legHealth <= PlayerConstants.BROKEN_LEGS_LOW_HEALTH_THRESHOLD)
		{
			//Inflict "high shock"
			m_ShockHandler.SetShock(highShock);
		}
		else if (legHealth >= PlayerConstants.BROKEN_LEGS_HIGH_HEALTH_THRESHOLD)
		{
			//Inflict "low shock"
			m_ShockHandler.SetShock(lowShock);
		}
		else
		{
			//If neither high nore low, inflict "mid shock"
			m_ShockHandler.SetShock(midShock);
		}
	}
	
	void DealShock(float dmg)
	{
		Param1<float> damage = new Param1<float>(0);
		damage.param1 = dmg;
		GetGame().RPCSingleParam(this, ERPCs.RPC_SHOCK, damage, true, GetIdentity());
	}
	
	//Prevent player from picking up heavy items when legs are broken
	override bool CanPickupHeavyItem(notnull EntityAI item)
	{
		if (item.IsHeavyBehaviour() && (m_BrokenLegState == eBrokenLegs.BROKEN_LEGS || m_BrokenLegState == eBrokenLegs.BROKEN_LEGS_SPLINT))
			return false;

		return super.CanPickupHeavyItem(item);
	}
	
	//Set all leg zones' health to 0 in order to limit emergent behaviour and prevent confusion as to how broken legs really work
	void SetLegHealth()
	{
		SetHealth("RightLeg", "", 0);
		SetHealth("RightFoot", "", 0);
		SetHealth("LeftLeg", "", 0);
		SetHealth("LeftFoot", "", 0);
	}
	
	void DropHeavyItem()
	{
		ItemBase itemInHands = GetItemInHands();
		if ( itemInHands && itemInHands.IsHeavyBehaviour() )
			DropItem(itemInHands);
	}
	
	bool IsWearingSplint()
	{
		EntityAI attachment;
		Class.CastTo(attachment, GetItemOnSlot("Splint_Right"));
		if ( attachment && attachment.GetType() == "Splint_Applied" )
		{
			return true;
		}
		return false;		
	}
	
	// -----------------------
	
		
	override void OnCommandSwimStart()
	{
		if ( GetItemInHands() && GetItemInHands().IsHeavyBehaviour() )
		{
			TryHideItemInHands(false);
			DropHeavyItem();
		}
		else
		{
			TryHideItemInHands(true);
		}
		
		m_AnimCommandStarting = HumanMoveCommandID.CommandSwim;
		
		if ( GetInventory() )
			GetInventory().LockInventory(LOCK_FROM_SCRIPT);
		
		CloseInventoryMenu();
		GetGame().GetMission().PlayerControlEnable(false);
		GetDayZGame().GetBacklit().OnSwimmingStart();
		
		AbortWeaponEvent();
		GetWeaponManager().DelayedRefreshAnimationState(10);
		RequestHandAnimationStateRefresh();
	}
	
	override void OnCommandSwimFinish()
	{
		TryHideItemInHands(false, true);
		
		if ( GetInventory() )
			GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);
		
		GetDayZGame().GetBacklit().OnSwimmingStop();
		
		GetWeaponManager().RefreshAnimationState();
	}
	
	override void OnCommandLadderStart()
	{
		m_AnimCommandStarting = HumanMoveCommandID.CommandLadder;
		TryHideItemInHands(true);
		
		if ( GetInventory() )
			GetInventory().LockInventory(LOCK_FROM_SCRIPT);
		
		CloseInventoryMenu();
	}
	
	override void OnCommandLadderFinish()
	{
		TryHideItemInHands(false, true);
		
		if ( GetInventory() )
			GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);
	}
	
	override void OnCommandFallStart()
	{
		m_AnimCommandStarting = HumanMoveCommandID.CommandFall;
		
		if ( GetInventory() )
			GetInventory().LockInventory(LOCK_FROM_SCRIPT);
		
		CloseInventoryMenu();
		
		AbortWeaponEvent();		
		GetWeaponManager().DelayedRefreshAnimationState(10);
		RequestHandAnimationStateRefresh();
	}
	
	override void OnCommandFallFinish()
	{
		if ( GetInventory() )
			GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);
		
		GetWeaponManager().RefreshAnimationState();
	}
	
	override void OnCommandClimbStart()
	{
		m_AnimCommandStarting = HumanMoveCommandID.CommandClimb;
		
		if ( GetInventory() )
			GetInventory().LockInventory(LOCK_FROM_SCRIPT);
		
		CloseInventoryMenu();
		
		AbortWeaponEvent();
		GetWeaponManager().DelayedRefreshAnimationState(10);
		RequestHandAnimationStateRefresh();
	}
	
	override void OnCommandClimbFinish()
	{
		if ( GetInventory() )
			GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);
		
		GetWeaponManager().RefreshAnimationState();
	}
	
	override void OnCommandVehicleStart()
	{
		m_AnimCommandStarting = HumanMoveCommandID.CommandVehicle;
		
		if ( GetInventory() )
			GetInventory().LockInventory(LOCK_FROM_SCRIPT);
		
		ItemBase itemInHand = GetItemInHands();
		EntityAI itemOnHead = FindAttachmentBySlotName("Headgear");

		if ( itemInHand && itemInHand.GetCompEM() )
			itemInHand.GetCompEM().SwitchOff();

		TryHideItemInHands(true);

		if ( itemOnHead && itemOnHead.GetCompEM() )
			itemOnHead.GetCompEM().SwitchOff();
		
		HumanCommandVehicle hcv = GetCommand_Vehicle();
		if ( hcv && hcv.GetVehicleSeat() == DayZPlayerConstants.VEHICLESEAT_DRIVER )
			OnVehicleSeatDriverEnter();
	}
	
	override void OnCommandVehicleFinish()
	{
		if ( GetInventory() )
			GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);
		
		TryHideItemInHands(false, true);
		
		if ( m_IsVehicleSeatDriver )
			OnVehicleSeatDriverLeft();
	}	
	
	override void OnCommandMelee2Start()
	{
		m_AnimCommandStarting = HumanMoveCommandID.CommandMelee2;
		m_IsFighting = true;
		
		AbortWeaponEvent();	
		GetWeaponManager().DelayedRefreshAnimationState(10);
		RequestHandAnimationStateRefresh();
	}
	
	override void OnCommandMelee2Finish()
	{
		RunFightBlendTimer();
		
		GetWeaponManager().RefreshAnimationState();
		
	}
	
	override void OnCommandDeathStart()
	{	
		m_AnimCommandStarting = HumanMoveCommandID.CommandDeath;
		AbortWeaponEvent();	
		GetWeaponManager().DelayedRefreshAnimationState(10);
		RequestHandAnimationStateRefresh();
	}
	
	override void OnJumpStart()
	{
		m_ActionManager.OnJumpStart();
		
		AbortWeaponEvent();
		GetWeaponManager().DelayedRefreshAnimationState(10);
		RequestHandAnimationStateRefresh();
	}
	
	override void OnJumpEnd(int pLandType = 0)
	{
		if(m_PresenceNotifier)
		{
			switch(pLandType)
			{
			case HumanCommandFall.LANDTYPE_NONE:
			case HumanCommandFall.LANDTYPE_LIGHT:
				m_PresenceNotifier.ProcessEvent(EPresenceNotifierNoiseEventType.LAND_LIGHT);
				break;
			case HumanCommandFall.LANDTYPE_MEDIUM:
			case HumanCommandFall.LANDTYPE_HEAVY:
				m_PresenceNotifier.ProcessEvent(EPresenceNotifierNoiseEventType.LAND_HEAVY);
				break;
			}
		}
		
		GetWeaponManager().RefreshAnimationState();
	}
	
	bool IsStance(int stance, int stanceMask)
	{
		return ((1 << stance) & stanceMask) != 0;
	}
	
	override void OnStanceChange(int previousStance, int newStance)
	{
		int prone = DayZPlayerConstants.STANCEMASK_PRONE | DayZPlayerConstants.STANCEMASK_RAISEDPRONE;
		int notProne = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_RAISEDERECT | DayZPlayerConstants.STANCEMASK_RAISEDCROUCH;
		
		if ( ( IsStance(previousStance, prone) && IsStance(newStance, notProne) ) || ( IsStance(previousStance, notProne) && IsStance(newStance, prone) ) )
		{
			AbortWeaponEvent();
			GetWeaponManager().RefreshAnimationState();
		}
		
		if ( GetGame().IsServer() )
		{
			if (newStance == DayZPlayerConstants.STANCEIDX_PRONE)
			{
				//Print("Update anim");
				if (m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
					m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.BROKEN_LEGS;
				else if (m_BrokenLegState == eBrokenLegs.BROKEN_LEGS_SPLINT)
					m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.BROKEN_LEGS_SPLINT;
				
				m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask | eInjuryOverrides.PRONE_ANIM_OVERRIDE;
				ForceUpdateInjuredState();
			}
			else if (previousStance == DayZPlayerConstants.STANCEIDX_PRONE || previousStance == DayZPlayerConstants.STANCEIDX_RAISEDPRONE)
			{
				m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.PRONE_ANIM_OVERRIDE;
				//Print("Update anim 2");
				if (m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
					m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask | eInjuryOverrides.BROKEN_LEGS;
				else if (m_BrokenLegState == eBrokenLegs.BROKEN_LEGS_SPLINT)
					m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask | eInjuryOverrides.BROKEN_LEGS_SPLINT;
				
				ForceUpdateInjuredState();
			}
		}
	}
	
	override void OnCommandMoveStart()
	{
		if ( GetGame().IsServer() )
		{
			//In case player changes stance through a different command, we refresh the anim overrides
			int prone = DayZPlayerConstants.STANCEMASK_PRONE | DayZPlayerConstants.STANCEMASK_RAISEDPRONE;
			if ( !IsPlayerInStance( prone ) )
			{
				m_InjuryHandler.m_ForceInjuryAnimMask = m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.PRONE_ANIM_OVERRIDE;
				ForceUpdateInjuredState();
			}
		}
	}
	
	override bool CanRoll()
	{
		if (!CanConsumeStamina(EStaminaConsumers.ROLL)) 
			return false;
		
		if (IsInFBEmoteState() || m_EmoteManager.m_MenuEmote)
		{
			return false;
		}
		
		return IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE | DayZPlayerConstants.STANCEMASK_RAISEDPRONE);
	}
	
	override void OnRollStart(bool isToTheRight)
	{
		DepleteStamina(EStaminaModifiers.ROLL);
		
		if (m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
			m_ShockHandler.SetShock(PlayerConstants.BROKEN_LEGS_ROLL_SHOCK);
	}
	
	override void OnRollFinish()
	{
	}
	
	void OnJumpOutVehicleFinish(float carSpeed)
	{ 
		string surfaceType;
		int liquidType;
		GetGame().SurfaceUnderObject(this, surfaceType, liquidType);
	}
		
	void OnVehicleSwitchSeat( int seatIndex )
	{
		if ( seatIndex == DayZPlayerConstants.VEHICLESEAT_DRIVER )
		{
			OnVehicleSeatDriverEnter();
		}
		else
		{
			OnVehicleSeatDriverLeft();
		}
	}
	
	void OnVehicleSeatDriverEnter()
	{
		Print("OnVehicleSeatDriverEnter");
		
		m_IsVehicleSeatDriver = true;
		ControlSchemeManager.SetControlScheme( EControlSchemeState.VehicleDriver );
		if( m_Hud )
			m_Hud.ShowVehicleInfo();
	}
	
	void OnVehicleSeatDriverLeft()
	{
		Print("OnVehicleSeatDriverLeft");
		
		m_IsVehicleSeatDriver = false;
		ControlSchemeManager.SetControlScheme( EControlSchemeState.None );
		if( m_Hud )
			m_Hud.HideVehicleInfo();
	}
	
	override void OnThrowingModeChange(bool change_to_enabled)
	{
		if (change_to_enabled)
		{
			PlacingCancelLocal();
			PlacingCancelServer();
		}
	}
	
	override void EOnFrame(IEntity other, float timeSlice)
	{
		//super.EOnFrame(other, timeSlice);
		
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			m_Hud.Update( timeSlice );
			m_Hud.ToggleHeatBufferPlusSign( m_HasHeatBuffer );
		}
	}

	override void EOnPostFrame(IEntity other, int extra)
	{
		//super.EOnPostFrame(other, extra);
		
		float delta_time = (GetGame().GetTime() - m_LastPostFrameTickTime) / 1000;
		m_LastPostFrameTickTime = GetGame().GetTime();
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			if( GetDamageDealtEffect() ) 
			{
				if (IsAlive())
					GetDamageDealtEffect().Update(delta_time);
				else
					delete GetDamageDealtEffect();
			}
			
			if( GetFlashbangEffect() )
			{	if (IsAlive())
					GetFlashbangEffect().Update(delta_time);
				else
					delete GetFlashbangEffect();
			}
			
			if( GetShockEffect() )
			{
				if (IsAlive())
					GetShockEffect().Update(delta_time);
				else
					delete GetShockEffect();
			}

			m_InventoryActionHandler.OnUpdate();
#ifdef DEVELOPER
			if(m_WeaponDebug)
			{
				m_WeaponDebug.OnPostFrameUpdate();
			}

			if( GetBleedingManagerRemote() )
			{
				GetBleedingManagerRemote().OnUpdate();
			}
			
			if(m_MeleeCombat)
			{
				if(DiagMenu.GetBool(DiagMenuIDs.DM_MELEE_DEBUG_ENABLE))
				{
					m_MeleeDebug = true;
					m_MeleeCombat.Debug(GetItemInHands(), m_MeleeCombat.GetHitType());
				}
				else if (!DiagMenu.GetBool(DiagMenuIDs.DM_MELEE_DEBUG_ENABLE) && m_MeleeDebug)
				{
					m_MeleeDebug = false;
					m_MeleeCombat.Debug(GetItemInHands(), m_MeleeCombat.GetHitType());
				}
			}
			
			if(m_Environment)
			{
				if(DiagMenu.GetBool(DiagMenuIDs.DM_ENVIRONMENT_DEBUG_ENABLE))
				{
					m_Environment.ShowEnvDebugPlayerInfo(DiagMenu.GetBool(DiagMenuIDs.DM_ENVIRONMENT_DEBUG_ENABLE));
				}
			}
			
			if(GetPluginManager())
			{
				PluginDrawCheckerboard drawCheckerboard = PluginDrawCheckerboard.Cast(GetPluginManager().GetPluginByType(PluginDrawCheckerboard));
				if(drawCheckerboard && !drawCheckerboard.IsActive())
				{
					drawCheckerboard.ShowWidgets(DiagMenu.GetBool(DiagMenuIDs.DM_DRAW_CHECKERBOARD));
				}
			}

			if(m_PresenceNotifier)
			{
				m_PresenceNotifier.EnableDebug(DiagMenu.GetBool(DiagMenuIDs.DM_PRESENCE_NOTIFIER_DBG));
			}
#endif
		}
	}

	void StaminaHUDNotifier( bool show )
	{
		if (m_Hud)
			m_Hud.SetStaminaBarVisibility( show );
	}
	
	override void DepleteStamina(EStaminaModifiers modifier, float dT = -1)
	{
		if( GetStaminaHandler() )
			GetStaminaHandler().DepleteStamina(modifier,dT);		
	}

	override bool CanConsumeStamina(EStaminaConsumers consumer)
	{
		if(!GetStaminaHandler()) return false;
		
		bool val = (GetStaminaHandler().HasEnoughStaminaFor(consumer) /*&& !IsOverloaded()*/ && !IsRestrained() && !IsInFBEmoteState());
		
		if (!val)
			StaminaHUDNotifier( false );

		return val;
	}
	
	override bool CanStartConsumingStamina(EStaminaConsumers consumer)
	{
		if(!GetStaminaHandler()) return false;
		
		bool val = (GetStaminaHandler().HasEnoughStaminaToStart(consumer) && !IsRestrained() && !IsInFBEmoteState());
		
		if (!val)
			StaminaHUDNotifier( false );

		return val;
	}
	
	bool HasStaminaRemaining()
	{
		if(!GetStaminaHandler()) return false;
		
		return GetStaminaHandler().GetStamina() > 0;
	}
	
	override bool CanClimb( int climbType, SHumanCommandClimbResult climbRes )
	{
		if (m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
		{
			return false;
		}
			
		if ( climbType == 1 && !CanConsumeStamina(EStaminaConsumers.VAULT) )
			return false;
		
		if ( climbType == 2 && ( !CanConsumeStamina(EStaminaConsumers.CLIMB) || m_BrokenLegState != eBrokenLegs.NO_BROKEN_LEGS ) )
			return false;

		if ( climbType > 0 && m_InjuryHandler && m_InjuryHandler.GetInjuryAnimValue() >= InjuryAnimValues.LVL3)
			return false;

		return super.CanClimb( climbType,climbRes );
	}

	override bool CanJump()
	{
		if (m_BrokenLegState != eBrokenLegs.NO_BROKEN_LEGS)
		{	
			return false;
		}
		
		if (!CanConsumeStamina(EStaminaConsumers.JUMP))
			return false;

		//! disables jump when player is significantly injured
		if ( m_InjuryHandler && m_InjuryHandler.GetInjuryAnimValue() >= InjuryAnimValues.LVL3 )
			return false;
		
		if (IsInFBEmoteState() || m_EmoteManager.m_MenuEmote)
		{
			return false;
		}
		
		//! disables jump when player is under object
		/*if (IsUnderRoofJumpCheck())
		{
			return false;
		}*/
		

		return super.CanJump();
	}
	
	bool IsJumpInProgress()
	{
		return m_JumpClimb.m_bIsJumpInProgress;
	}
	
	/*bool IsUnderRoofJumpCheck() 
	{
		vector start = GetPosition();
		float size;
		vector to;
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		if (IsPlayerInStance(DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_RAISEDERECT))
		{
			start[1] = start[1] + 1.7;
		}
		else
		{
			start[1] = start[1] + 1.7;
		}
		
		size = 0.5;
		to = start;
		to[1] = to[1] + size;
	
		return DayZPhysics.RaycastRV( start, to, contact_pos, contact_dir, contact_component, NULL, NULL, this );
	}*/
	
	bool IsTargetInActiveRefresherRange(EntityAI target)
	{
		array<vector> temp = new array<vector>;
		temp = GetGame().GetMission().GetActiveRefresherLocations();
		int count = temp.Count();
		if (count > 0)
		{
			vector pos = target.GetPosition();
			for (int i = 0; i < count; i++)
			{
				if ( vector.Distance(pos,temp.Get(i)) < GameConstants.REFRESHER_RADIUS )
					return true;
			}
			
			return false;
		}
		else
		{
			return false;
		}
	}
	
	void RequestHandAnimationStateRefresh()
	{
		if ( (GetGame().IsMultiplayer() && GetGame().IsServer()) )
		{
			m_RefreshAnimStateIdx++;
			if (m_RefreshAnimStateIdx > 3)
				m_RefreshAnimStateIdx = 0;
			SetSynchDirty();
		}
	}
	
	void RefreshHandAnimationState(int delay = 0)
	{
		if (delay == 0)
		{
			//Print("---Refreshing Hand Anim State---");
			GetItemAccessor().OnItemInHandsChanged(true);
			GetItemAccessor().ResetWeaponInHands();
		}
		else
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(RefreshHandAnimationState,delay,false,0);
		}
	}
	
	// -------------------------------------------------------------------------
	// 		USER ACTIONS
	// -------------------------------------------------------------------------

	bool IsFacingTarget( Object target )
	{
		vector pdir = GetDirection();
		vector ptv = target.GetPosition() - GetPosition();
		pdir.Normalize();
		ptv.Normalize();
		//MessageAction(ToString(pdir)+"  "+ToString(ptv)+"  ");
		if (Math.AbsFloat(pdir[0]-ptv[0]) < 0.5 && Math.AbsFloat(pdir[2]-ptv[2]) < 0.5 )
		{
			return true;
		}
		return false;
	}

	//---------------------------------------------------------
	void OnQuickBarSingleUse(int slotClicked)
	{
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER )
			return;
		
		if ( m_AreHandsLocked )
			return; //Player is in the short window of time after interrupting placement of an item and before getting it back in hands

		if ( GetInventory().IsInventoryLocked() || IsEmotePlaying() )
			return;
		
		if ( GetThrowing().IsThrowingModeEnabled() || GetThrowing().IsThrowingAnimationPlaying() )
			return;
		
		if ( IsRaised() || GetCommand_Melee() || IsSwimming() || IsClimbingLadder() || IsClimbing() || IsRestrained() || IsRestrainPrelocked() )
			return;
		
		if ( GetDayZPlayerInventory().IsProcessing() || IsItemsToDelete() )
			return;
		
		if ( GetActionManager().GetRunningAction() != null )
			return;
		
		if ( GetWeaponManager() && GetWeaponManager().IsRunning() )
			return;
		
		if ( !ScriptInputUserData.CanStoreInputUserData() )
			return;
		
		//TODO MW change locking method
		//if( GetDayZPlayerInventory().HasLockedHands() )
		//	return;
			
		EntityAI quickBarEntity = GetQuickBarEntity(slotClicked - 1);//GetEntityInQuickBar(slotClicked - 1);
		
		if ( !quickBarEntity )
			return;
		
		Magazine mag;
		Weapon_Base wpn;
		
		if ( Class.CastTo(mag, quickBarEntity) && Class.CastTo(wpn, mag.GetHierarchyParent()) )
			return;

		EntityAI inHandEntity = GetHumanInventory().GetEntityInHands();
				
		if ( !GetDayZPlayerInventory().IsIdle() )
			return; // player is already performing some animation

		InventoryLocation handInventoryLocation = new InventoryLocation;
		handInventoryLocation.SetHands(this,quickBarEntity);
		if ( this.GetInventory().HasInventoryReservation(quickBarEntity, handInventoryLocation ) )
			return;
		
		if ( inHandEntity == quickBarEntity )
		{
			if ( GetHumanInventory().CanRemoveEntityInHands() )
			{
				syncDebugPrint("[QB] Stash - PredictiveMoveItemFromHandsToInventory HND=" + Object.GetDebugName(inHandEntity));
				PredictiveMoveItemFromHandsToInventory();
			}
		}
		else
		{
			InventoryLocation invLocQBItem = new InventoryLocation;
			quickBarEntity.GetInventory().GetCurrentInventoryLocation(invLocQBItem);
			if ( GetInventory().HasInventoryReservation(quickBarEntity,invLocQBItem) )
				return;
				
			if ( inHandEntity )
			{
				InventoryLocation Reserved_Item_il = new InventoryLocation;
				
				InventoryLocation inHandEntityFSwapDst = new InventoryLocation;
				inHandEntity.GetInventory().GetCurrentInventoryLocation(inHandEntityFSwapDst);

				int index = GetHumanInventory().FindUserReservedLocationIndex(inHandEntity);
				if ( index >= 0 )
					GetHumanInventory().GetUserReservedLocation( index, Reserved_Item_il);
				
				if ( Reserved_Item_il )
					inHandEntityFSwapDst.CopyLocationFrom(Reserved_Item_il, true);
				
				if ( index < 0 && GameInventory.CanSwapEntitiesEx( quickBarEntity, inHandEntity ) )
				{
					syncDebugPrint("[QB] PredictiveSwapEntities QB=" + Object.GetDebugName(quickBarEntity) + " HND=" + Object.GetDebugName(inHandEntity));
					PredictiveSwapEntities( quickBarEntity, inHandEntity );
				}
				else if ( GameInventory.CanForceSwapEntitiesEx( quickBarEntity, null, inHandEntity, inHandEntityFSwapDst ) )
				{
					syncDebugPrint("[QB] Swap - PredictiveForceSwapEntities HND=" + Object.GetDebugName(inHandEntity) +  " QB=" + Object.GetDebugName(quickBarEntity) + " fswap_dst=" + InventoryLocation.DumpToStringNullSafe(inHandEntityFSwapDst));
					PredictiveForceSwapEntities( quickBarEntity, inHandEntity, inHandEntityFSwapDst );
				}
			}
			else
			{
				if ( GetInventory().HasInventoryReservation(quickBarEntity,handInventoryLocation) )
					return;
				
				if ( GetInventory().CanAddEntityIntoHands(quickBarEntity) )
				{
					syncDebugPrint("[QB] Stash - PredictiveTakeEntityToHands QB=" + Object.GetDebugName(quickBarEntity));
					PredictiveTakeEntityToHands( quickBarEntity );
				}
			}
		}	
	}
	//---------------------------------------------------------
	void OnQuickBarContinuousUseStart(int slotClicked)
	{
		if ( GetInventory().IsInventoryLocked() )
			return;
		
		if ( IsSwimming() || IsClimbingLadder() || GetCommand_Melee() || IsClimbing() || IsRestrained() || IsRestrainPrelocked() )
			return;
		
		ItemBase quickBarItem = ItemBase.Cast(GetQuickBarEntity(slotClicked - 1));

		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT)
		{
			ItemBase itemInHands = ItemBase.Cast(GetHumanInventory().GetEntityInHands());

			if ( itemInHands != quickBarItem )
			{
				ActionManagerClient amc = ActionManagerClient.Cast(GetActionManager());

				if ( amc.CanPerformActionFromQuickbar(itemInHands, quickBarItem) )
				{
					amc.PerformActionFromQuickbar(itemInHands, quickBarItem);
				}
				else
				{
					if ( IsRaised() || GetCommand_Melee() )
						return;

					amc.ForceTarget(quickBarItem);
					m_QuickBarFT = true;
				}
			}
		}
		m_QuickBarHold = true;
	}
	//---------------------------------------------------------
	void OnQuickBarContinuousUseEnd(int slotClicked)
	{
		if ( m_QuickBarHold )
		{
			if (  GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
			{
				ActionManagerClient am = ActionManagerClient.Cast(GetActionManager());
				
				if (m_ActionQBControl)
				{
					ActionBase action = am.GetRunningAction(); 
					if (action)
					{
						if (!action.GetInput().IsActive())
						{
							am.EndActionInput();
						}
					
					}
				}
				
				if (m_QuickBarFT)
				{
					am.ClearForceTarget();
					m_QuickBarFT = false;
				}
			}
		}
		m_QuickBarHold = false;
	}
	void SetActionEndInput(ActionBase action)
	{
		m_ActionQBControl = !action.GetInput().IsActive();
	}
	
	bool IsQBControl()
	{
		return m_ActionQBControl;
	}
	void ResetActionEndInput()
	{
		m_ActionQBControl = false;
	}
	
	//---------------------------------------------------------
	//	RADIAL QUICKBAR AND RELOAD ACTIONS
	//---------------------------------------------------------
	//the same functionality as normal quick bar slot key press
	void RadialQuickBarSingleUse( int slotClicked )
	{
		OnQuickBarSingleUse( slotClicked );				
	}
	
	//removed the need for holding down quick bar slot key
	void RadialQuickBarCombine( int slotClicked )
	{
		EntityAI quickBarEntity = GetQuickBarEntity( slotClicked - 1 );
		EntityAI entity_in_hands = GetHumanInventory().GetEntityInHands();
		
		ReloadWeapon( entity_in_hands, quickBarEntity );	
	}

	//removed the need for holding down quick bar slot key
	void QuickReloadWeapon( EntityAI weapon )
	{
		EntityAI magazine = GetMagazineToReload( weapon );
		ReloadWeapon( weapon, magazine );
	}
	
	//Reload weapon with given magazine
	void ReloadWeapon( EntityAI weapon, EntityAI magazine )
	{
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			ActionManagerClient mngr_client;
			CastTo(mngr_client, GetActionManager());
			
			if (mngr_client && FirearmActionLoadMultiBulletRadial.Cast(mngr_client.GetRunningAction()))
			{
				mngr_client.Interrupt();
			}
			else if ( GetHumanInventory().GetEntityInHands()!= magazine )
			{
				Weapon_Base wpn;
				Magazine mag;
				Class.CastTo( wpn,  weapon );
				Class.CastTo( mag,  magazine );
				if ( GetWeaponManager().CanUnjam(wpn) )
				{
					GetWeaponManager().Unjam();
				}
				else if ( GetWeaponManager().CanAttachMagazine( wpn, mag ) )
				{
					GetWeaponManager().AttachMagazine( mag );
				}
				else if ( GetWeaponManager().CanSwapMagazine( wpn, mag ) )
				{
					GetWeaponManager().SwapMagazine( mag );
				}
				else if ( GetWeaponManager().CanLoadBullet( wpn, mag ) )
				{
					//GetWeaponManager().LoadMultiBullet( mag );

					ActionTarget atrg = new ActionTarget(mag, this, -1, vector.Zero, -1.0);
					if ( mngr_client && !mngr_client.GetRunningAction() && mngr_client.GetAction(FirearmActionLoadMultiBulletRadial).Can(this, atrg, wpn) )
						mngr_client.PerformActionStart(mngr_client.GetAction(FirearmActionLoadMultiBulletRadial), atrg, wpn);
				}
			}
		}		
	}

	//returns compatible magazine from player inventory with highest ammo count
	EntityAI GetMagazineToReload( EntityAI weapon )
	{
		Weapon_Base weapon_base = Weapon_Base.Cast( weapon );
		WeaponManager weapon_manager = GetWeaponManager();
		EntityAI magazine_to_reload;
		
		EntityAI ammo_magazine;				//magazine
		int last_ammo_magazine_count;
		int ammo_magazine_count;
		
		EntityAI ammo_pile;					//ammo pile
		int last_ammo_pile_count;
		int ammo_pile_count;
		
		//Get all magazines in (player) inventory
		for ( int att_i = 0; att_i < GetInventory().AttachmentCount(); ++att_i )
		{
			EntityAI attachment = GetInventory().GetAttachmentFromIndex( att_i );
			ref CargoBase attachment_cargo = attachment.GetInventory().GetCargo();
			
			if ( attachment_cargo )
			{
				for ( int cgo_i = 0; cgo_i < attachment_cargo.GetItemCount(); ++cgo_i )
				{
					EntityAI cargo_item = attachment_cargo.GetItem( cgo_i );
					
					//check for proper magazine
					if ( cargo_item.IsMagazine() )
					{
						Magazine magazine = Magazine.Cast( cargo_item );
						ammo_pile_count = magazine.GetAmmoCount();
						
						//magazines (get magazine with max ammo count)
						if ( weapon_manager.CanAttachMagazine( weapon_base, magazine ) || weapon_manager.CanSwapMagazine( weapon_base, magazine ) )
						{
							if ( ammo_pile_count > 0 )
							{
								if ( last_ammo_magazine_count == 0 )
								{
									ammo_magazine = magazine;
									last_ammo_magazine_count = ammo_pile_count;
								}
								else
								{
									if ( last_ammo_magazine_count < ammo_pile_count )
									{
										ammo_magazine = magazine;
										last_ammo_magazine_count = ammo_pile_count;
									}
								}
							}
						}	
						//bullets (get ammo pile with min ammo count)
						else if ( weapon_manager.CanLoadBullet( weapon_base, magazine ) )
						{
							if ( ammo_pile_count > 0 )
							{
								if ( last_ammo_pile_count == 0 )
								{
									ammo_pile = magazine;
									last_ammo_pile_count = ammo_pile_count;
								}
								else
								{
									if ( last_ammo_pile_count > ammo_pile_count )
									{
										ammo_pile = magazine;
										last_ammo_pile_count = ammo_pile_count;
									}
								}
							}
						}							
					}
				}
			}
		}

		//prioritize magazine
		if ( ammo_magazine )
		{
			return ammo_magazine;		
		}
		
		return ammo_pile;
	}
	//---------------------------------------------------------
	
	
	//---------------------------------------------------------
	void OnSpawnedFromConsole()
	{
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer() )
		{
			GetGame().GetMission().AddDummyPlayerToScheduler( this );
		}
	}
	
	//---------------------------------------------------------
	bool GetLiquidTendencyDrain()
	{
		return m_LiquidTendencyDrain;
	}
	//---------------------------------------------------------
	void SetLiquidTendencyDrain(bool state)
	{
		m_LiquidTendencyDrain = state;
	}
	
	//---------------------------------------------------------
	bool GetFlagTendencyRaise()
	{
		return m_FlagRaisingTendency;
	}
	//---------------------------------------------------------
	void SetFlagTendencyRaise(bool state)
	{
		m_FlagRaisingTendency = state;
	}
	
	override SoundOnVehicle PlaySound(string sound_name, float range, bool create_local = false)
	{
		return BetaSound.SaySound(this, sound_name, range, false);
	}
	
	float GetPlayerLoad()
	{
		return m_CargoLoad;
	}
	
	bool IsOverloaded()
	{
		if ( GetPlayerLoad() >= OVERLOAD_LIMIT ) return true;
		return false;
	}

	void SetPlayerLoad(float load)
	{
		m_CargoLoad = load;
		//Print("m_CargoLoad: " + m_CargoLoad);
		//Log(ToString(this) + "'s load weight is " + ftoa(m_CargoLoad) + " g.", LogTemplates.TEMPLATE_PLAYER_WEIGHT);
	}

	void AddPlayerLoad(float addedload)
	{
		float newload = GetPlayerLoad() + addedload;
		SetPlayerLoad(newload);
		
		// Do not need -> Log is in SetPlayerLoad
		//PrintString(ToString(this) + "'s load weight is " + ToString(m_CargoLoad) + " g.");
	}

	bool IsItemInInventory(EntityAI entity)
	{
		return GetInventory().HasEntityInInventory(entity);
	}

	override bool NeedInventoryJunctureFromServer(notnull EntityAI item, EntityAI currParent, EntityAI newParent)
	{
		if (GetGame().IsMultiplayer())
		{
			DayZPlayerInstanceType t = GetInstanceType();
			switch (t)
			{
				case DayZPlayerInstanceType.INSTANCETYPE_AI_SINGLEPLAYER:
					return false;
				case DayZPlayerInstanceType.INSTANCETYPE_CLIENT:
				case DayZPlayerInstanceType.INSTANCETYPE_SERVER:
				case DayZPlayerInstanceType.INSTANCETYPE_AI_SERVER:
				case DayZPlayerInstanceType.INSTANCETYPE_AI_REMOTE:
				case DayZPlayerInstanceType.INSTANCETYPE_REMOTE:
					return true; // Might help mitigate "megabugged" (desync)
				
					syncDebugPrint("[syncinv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " NeedInventoryJunctureFromServer item=" + Object.GetDebugName(item) + " currPar=" + currParent + " newPar=" + newParent);
					
					bool i_owned = GetHumanInventory().HasEntityInInventory(item);
					
					bool cp_owned = false;
					if (currParent)
						cp_owned = GetHumanInventory().HasEntityInInventory(currParent);
					
					bool np_owned = false;
					if (newParent)
						np_owned = GetHumanInventory().HasEntityInInventory(newParent);

					bool all_owned = i_owned && cp_owned && (np_owned || (newParent == null));
					syncDebugPrint("[syncinv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " NeedInventoryJunctureFromServer=" + !all_owned + " i_pwn=" + i_owned + " cp_pwn=" + cp_owned + " np_pwn=" + np_owned);
					
					return !all_owned;
				default:
					Error("[syncinv] unsupported instance type t=" + t);
					break;
			}
		}
		return false;
	}
	
	override void UpdateWeight(WeightUpdateType updateType = WeightUpdateType.FULL, float weightAdjustment = 0)
	{
		//Print("CalculatePlayerLoad | timestamp: " + GetSimulationTimeStamp());
		EntityAI attachment;
		ItemBase itemHands;
		
		itemHands = GetItemInHands();
		int attcount = this.GetInventory().AttachmentCount();
		int total_load = 0;
		
		for (int att = 0; att < attcount; att++)
		{	
			attachment = GetInventory().GetAttachmentFromIndex(att);
			if( attachment )
			{
				total_load += attachment.GetWeight();
			}
		}

		if ( itemHands ) // adds weight of item carried in hands
		{
			total_load += itemHands.GetWeight();
			//Print("itemHands.GetWeight(): " + itemHands.GetWeight());
		}
		m_Weight = total_load;
		//Print("total_load: " + total_load);
	}

	void CalculateVisibilityForAI()
	{
		const int VISIBILITY_SLOTS_COUNT = 10;

		int attcount = this.GetInventory().AttachmentCount();
		float sumVisibility = 0;
		float countVisibility = 0;
		float visibilityMean = 0;

		if (attcount > 0)
		{
			for (int att = 0; att < attcount; att++)
			{
				EntityAI attachment = GetInventory().GetAttachmentFromIndex(att);
				if ( attachment.IsClothing() )
				{
					ClothingBase clothing;
					Class.CastTo(clothing, attachment);
					sumVisibility += clothing.GetItemVisibility();
					countVisibility++;
				}
			}

			visibilityMean = (sumVisibility + (VISIBILITY_SLOTS_COUNT - countVisibility)) / VISIBILITY_SLOTS_COUNT;
			SetVisibilityCoef(visibilityMean);
		}
		else
		{
			visibilityMean = 1;
			SetVisibilityCoef(visibilityMean);
		}
	}
	
	void SetVisibilityCoef(float pVisibility)
	{
		m_VisibilityCoef = pVisibility;
	}
	
	float GetVisibilityCoef()
	{
		return m_VisibilityCoef;
	}

	
	int GetShakeLevel()
	{
		return m_Shakes;
	}
	
	
	EStatLevels GetStatLevelHealth()
	{
		float health = GetHealth("","");
		return GetStatLevel(health, PlayerConstants.SL_HEALTH_CRITICAL, PlayerConstants.SL_HEALTH_LOW, PlayerConstants.SL_HEALTH_NORMAL, PlayerConstants.SL_HEALTH_HIGH);
	}
	
	EStatLevels GetStatLevelToxicity()
	{
		float toxicity = GetStatToxicity().Get();
		return GetStatLevel(toxicity, PlayerConstants.SL_HEALTH_CRITICAL, PlayerConstants.SL_HEALTH_LOW, PlayerConstants.SL_HEALTH_NORMAL, PlayerConstants.SL_HEALTH_HIGH);
	}
	
	EStatLevels GetStatLevelBlood()
	{
		float blood = GetHealth("","Blood");
		return GetStatLevel(blood, PlayerConstants.SL_BLOOD_CRITICAL, PlayerConstants.SL_BLOOD_LOW, PlayerConstants.SL_BLOOD_NORMAL, PlayerConstants.SL_BLOOD_HIGH);
	}
	
	EStatLevels GetStatLevelEnergy()
	{
		float energy = GetStatEnergy().Get();
		return GetStatLevel(energy, PlayerConstants.SL_ENERGY_CRITICAL, PlayerConstants.SL_ENERGY_LOW, PlayerConstants.SL_ENERGY_NORMAL, PlayerConstants.SL_ENERGY_HIGH);
	}
	
	EStatLevels GetStatLevelWater()
	{
		float water = GetStatWater().Get();
		return GetStatLevel(water, PlayerConstants.SL_WATER_CRITICAL, PlayerConstants.SL_WATER_LOW, PlayerConstants.SL_WATER_NORMAL, PlayerConstants.SL_WATER_HIGH);
	}
	
	//!returns player's immunity level
	/*
	EStatLevels GetImmunityLevel()
	{
		float immunity = GetImmunity();
		
		EStatLevels level; 
		if( immunity > PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_HIGH )
		{
			level = EStatLevels.GREAT;
		}
		else if( immunity > PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_NORMAL )
		{
			level = EStatLevels.HIGH;
		}
		else if( immunity > PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_LOW )
		{
			level = EStatLevels.MEDIUM;
		}
		else if( immunity > PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_CRITICAL )
		{
			level = EStatLevels.LOW;
		}
		else
		{
			level = EStatLevels.CRITICAL;
		}
		
		if( m_ImmunityBoosted && level != EStatLevels.GREAT )
		{
			level--;
		}
		return level;
	}
	*/
	
	EStatLevels GetImmunityLevel()
	{
		float immunity = GetImmunity();
		if(m_ImmunityBoosted)
			return EStatLevels.GREAT;
		return GetStatLevel(immunity, PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_CRITICAL, PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_LOW, PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_NORMAL, PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_HIGH);
	}
	
	//-------------------------------------
	float GetBordersImmunity()
	{
		float immunity = GetImmunity();
		float immmunity_max = 1;
		return GetStatLevelBorders(immunity, PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_CRITICAL, PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_LOW, PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_NORMAL, PlayerConstants.IMMUNITY_THRESHOLD_LEVEL_HIGH, immmunity_max);
	}
	
	
	float GetStatBordersHealth()
	{
		float health = GetHealth("","");
		float health_max = GetMaxHealth("","");
		return GetStatLevelBorders(health, PlayerConstants.SL_HEALTH_CRITICAL, PlayerConstants.SL_HEALTH_LOW, PlayerConstants.SL_HEALTH_NORMAL, PlayerConstants.SL_HEALTH_HIGH, health_max);
	}
	
	float GetStatBordersToxicity()
	{
		float toxicity = GetStatToxicity().Get();
		float toxicity_max = GetStatToxicity().GetMax();
		return GetStatLevelBorders(toxicity, PlayerConstants.SL_HEALTH_CRITICAL, PlayerConstants.SL_HEALTH_LOW, PlayerConstants.SL_HEALTH_NORMAL, PlayerConstants.SL_HEALTH_HIGH, toxicity_max);
	}
	
	float GetStatBordersBlood()
	{
		float blood = GetHealth("","Blood");
		float blood_max = GetMaxHealth("","Blood");
		return GetStatLevelBorders(blood, PlayerConstants.SL_BLOOD_CRITICAL, PlayerConstants.SL_BLOOD_LOW, PlayerConstants.SL_BLOOD_NORMAL, PlayerConstants.SL_BLOOD_HIGH, blood_max);
	}
	
	float GetStatBordersEnergy()
	{
		float energy = GetStatEnergy().Get();
		float energy_max = GetStatEnergy().GetMax();
		return GetStatLevelBorders(energy, PlayerConstants.SL_ENERGY_CRITICAL, PlayerConstants.SL_ENERGY_LOW, PlayerConstants.SL_ENERGY_NORMAL, PlayerConstants.SL_ENERGY_HIGH, energy_max);
	}
	
	float GetStatBordersWater()
	{
		float water = GetStatWater().Get();
		float water_max = GetStatWater().GetMax();
		return GetStatLevelBorders(water, PlayerConstants.SL_WATER_CRITICAL, PlayerConstants.SL_WATER_LOW, PlayerConstants.SL_WATER_NORMAL, PlayerConstants.SL_WATER_HIGH, water_max);
	}
	
	//------------------------------------
	
	float GetStatLevelBorders(float stat_value, float critical, float low, float normal, float high, float max)
	{
		if(stat_value <= critical)
		{	
			return Math.InverseLerp(0, critical, stat_value);
		}
		if(stat_value <= low)
		{
			return Math.InverseLerp(critical, low, stat_value);
		}
		if(stat_value <= normal)
		{
			return Math.InverseLerp(low, normal, stat_value);
		}
		if(stat_value <= high)
		{
			return Math.InverseLerp(normal, high, stat_value);
		}
		return Math.InverseLerp(high, max, stat_value);
	}
	
	EStatLevels GetStatLevel(float stat_value, float critical, float low, float normal, float high)
	{
		if(stat_value <= critical)
		{
			return EStatLevels.CRITICAL;
		}
		if(stat_value <= low)
		{
			return EStatLevels.LOW;
		}
		if(stat_value <= normal)
		{
			return EStatLevels.MEDIUM;
		}
		if(stat_value <= high)
		{
			return EStatLevels.HIGH;
		}
		return EStatLevels.GREAT;
	}
	
	void SetImmunityBoosted(bool boosted)
	{
		m_ImmunityBoosted = boosted;
	}
	
	
	
	//!returns player's immunity strength between 0..1
	float GetImmunity()
	{
		float immunity;
		if(	GetPlayerStats() ) 
		{
			float max_health = GetMaxHealth("GlobalHealth", "Health") + 0.01;//addition to prevent divisioin by zero in case of some messup
			float max_blood = GetMaxHealth("GlobalHealth", "Blood") + 0.01;//addition to prevent divisioin by zero in case of some messup
			float energy_normalized = GetStatEnergy().Get() / PlayerConstants.SL_ENERGY_HIGH;
			float water_normalized = GetStatWater().Get() / PlayerConstants.SL_WATER_HIGH;
			float health_normalized = GetHealth("GlobalHealth", "Health") / max_health;
			float blood_normalized = GetHealth("GlobalHealth", "Blood") / max_blood;
			immunity = energy_normalized + water_normalized + health_normalized + blood_normalized;
			immunity = immunity / 4;//avg
			immunity =  Math.Clamp(immunity,0,1);
		}
		return immunity;
	}
	
	bool IsSprinting()
	{
		return m_MovementState.m_iMovement == DayZPlayerConstants.MOVEMENT_SPRINT);
	}

	bool CanSprint()
	{
		ItemBase item = GetItemInHands();
		if ( IsRaised() || (item && item.IsHeavyBehaviour()) )
		{
			return false;
		}
		
		if (m_BrokenLegState != eBrokenLegs.NO_BROKEN_LEGS)
		{
			return false;
		}
		
		return true;
	}
	
	bool IsInProne()
	{
		return m_MovementState.IsInProne();
	}
	
	bool IsInRasedProne()
	{
		return m_MovementState.IsInRaisedProne();
	}	
	
	bool IsLeaning()
	{
		return m_MovementState.IsLeaning();
	}	
	
	bool IsRolling()
	{
		if (GetCommand_Move() && GetCommand_Move().IsInRoll())
			return true;
		return false;
	}
	
	override bool IsRaised()
	{
		//GetMovementState(m_MovementState);
		return m_MovementState.IsRaised();
	}
	
	bool IsSwimming()
	{
		return m_MovementState.m_CommandTypeId == DayZPlayerConstants.COMMANDID_SWIM;
	}
	
	bool IsClimbingLadder()
	{
		return m_MovementState.m_CommandTypeId == DayZPlayerConstants.COMMANDID_LADDER;
	}
	
	bool IsClimbing()
	{
		return m_MovementState.m_CommandTypeId == DayZPlayerConstants.COMMANDID_CLIMB;
	}
	
	bool IsFalling()
	{
		return m_MovementState.m_CommandTypeId == DayZPlayerConstants.COMMANDID_FALL;
	}
	
	bool IsInVehicle()
	{
		return m_MovementState.m_CommandTypeId == DayZPlayerConstants.COMMANDID_VEHICLE;
	}

	override bool IsFighting()
	{
		return m_IsFighting;
	}
	
	bool IsEmotePlaying()
	{
		if (m_EmoteManager)
		{
			return m_EmoteManager.IsEmotePlaying();
		}
		else
		{
			return false;
		}
	}
	
	/*!
	Returns whether the specified movement command(s) are starting the next frame.
	Use caution when using this for anything player animation-related, some commands may require the movement state to be truly active (wait until next update)
	*/
	bool AnimCommandCheck(HumanMoveCommandID mask)
	{
		return m_AnimCommandStarting & mask;
	}
	
	void RunFightBlendTimer()
	{
		if (!m_FightEndBlendTimer)
			m_FightEndBlendTimer = new Timer();
		if (!m_FightEndBlendTimer.IsRunning())
		{
			m_FightEndBlendTimer.Run(PlayerConstants.MELEE2_MOVEMENT_BLEND_DELAY,this,"EndFighting");
		}
	}
	
	void EndFighting()
	{
		m_IsFighting = false;
	}
	
	bool CheckMeleeItemDamage(ItemBase item)
	{
		//on-hit drop of melee weapons
		//bayonets & buttstocks
		if (item && item.GetHierarchyParent() && item.GetHierarchyParent().IsWeapon() && item.IsRuined()/*&& item.FindAttachmentBySlotName()*/)
		{
			PlayAttachmentDropSound();
			return DropItem(item);
		}
		//handheld items themselves
		if (item && item == GetItemInHands() && item.IsRuined())
		{
			return PredictiveDropEntity(item);
		}
		return false;
	}
	
	void PlayAttachmentDropSound()
	{
		//TODO
	}
	
	// -------------------------------------------------------------------------
	override void RPC(int rpc_type, array<ref Param> params, bool guaranteed, PlayerIdentity recipient = NULL)
	{
		super.RPC(rpc_type, params, guaranteed, recipient);
	}

	// -------------------------------------------------------------------------
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		
		switch (rpc_type)
		{
			case ERPCs.RPC_SYNC_DISPLAY_STATUS:
				if ( GetVirtualHud() ) 
				{
					GetVirtualHud().OnRPC(ctx);
				}
			break;
	  
			case ERPCs.RPC_PLAYER_SYMPTOM_ON:
				if ( GetSymptomManager() ) 
				{
					GetSymptomManager().OnRPC(ERPCs.RPC_PLAYER_SYMPTOM_ON, ctx);
				}
			break;
			 
			case ERPCs.RPC_PLAYER_SYMPTOM_OFF:
				if ( GetSymptomManager() ) 
				{
					GetSymptomManager().OnRPC(ERPCs.RPC_PLAYER_SYMPTOM_OFF, ctx);
				}
			break;
			
			case ERPCs.RPC_CHECK_PULSE:
				ctx.Read(CachedObjectsParams.PARAM1_INT);
				EPulseType pulse;
				if ( (CachedObjectsParams.PARAM1_INT.param1 & ActionCheckPulse.TARGET_IRREGULAR_PULSE_BIT) == 0 )
				{
					pulse = EPulseType.REGULAR;
				}
				else
				{
					pulse = EPulseType.IRREGULAR;
				}
			/*
				Print("-----------------");
				Print(ActionCheckPulse.TARGET_IRREGULAR_PULSE_BIT);
				Print(CachedObjectsParams.PARAM1_INT.param1);
				Print(pulse);
				Print("-----------------");
			*/
				int blood_level = ~ActionCheckPulse.TARGET_IRREGULAR_PULSE_BIT & CachedObjectsParams.PARAM1_INT.param1;
				if (m_CheckPulseLastTarget)
				{
					m_CheckPulseLastTarget.SetLastUAMessage(ActionCheckPulse.GetPulseMessage(pulse, blood_level));
				}
			break;

			case ERPCs.RPC_PLAYER_SYMPTOMS_DEBUG_ON:
				if ( GetSymptomManager() ) 
				{
					GetSymptomManager().OnRPCDebug(ERPCs.RPC_PLAYER_SYMPTOMS_DEBUG_ON, ctx);
				}
			break;

			case ERPCs.RPC_PLAYER_SYMPTOMS_DEBUG:
				if ( GetSymptomManager() ) 
				{
					GetSymptomManager().OnRPCDebug(ERPCs.RPC_PLAYER_SYMPTOMS_DEBUG, ctx);
				}
			break;
			
			case ERPCs.RPC_PLAYER_SYMPTOMS_EXIT:
				if ( GetSymptomManager() ) 
				{
					GetSymptomManager().OnRPCDebug(ERPCs.RPC_PLAYER_SYMPTOMS_EXIT, ctx);
				}
			break;		
			
			case ERPCs.RPC_USER_ACTION_MESSAGE:
				if ( !GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT ) 
				{
					break;
				}
				if ( ctx.Read(m_UAParamMessage) )
				{
					string actiontext = m_UAParamMessage.param1;
					MessageAction(actiontext);
				}
			break;
			
/*			case ERPCs.RPC_USER_ACTION_MESSAGES:
				if( !GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
				{
					break;
				}
				if ( ctx.Read(m_UAParam) && GetActionManager() )
				{
					string actiontext2 = GetActionManager().GetAction(m_UAParam.param1).GetMessageText(m_UAParam.param2);
					MessageAction(actiontext2);
				}
			break;
*/			
			case ERPCs.RPC_STAMINA:
				if ( ctx.Read(m_StaminaParam) && m_StaminaHandler )
				{
					m_StaminaHandler.OnRPC(m_StaminaParam.param1, m_StaminaParam.param2, m_StaminaParam.param3);
				}
			break;
			
			//TESTING
			case ERPCs.RPC_SHOCK:
				if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
				{
					break;
				}
				
				Param1<float> damage = new Param1<float>(0);
				//damage.param1 = dmg;
				if ( ctx.Read(damage) /*&& m_ShockHandler*/ )
				{
					GiveShock(-damage.param1);
				}
			break;
			
			case ERPCs.RPC_CRAFTING_INVENTORY_INSTANT:
				ref Param3<int, ItemBase, ItemBase> craftParam = new Param3<int, ItemBase, ItemBase>(-1, NULL, NULL);
				if (ctx.Read( craftParam ) )
				{
					m_ModuleRecipesManager.PerformRecipeServer(craftParam.param1, craftParam.param2, craftParam.param3, this);				
				}
			break;
				
		
			/*
			case ERPCs.RPC_RECIPE_SEND:
				if ( m_ModuleRecipesManager )
				{
					//m_ModuleRecipesManager.OnRPC(ctx,this);
				}
			break; 
			*/
			case ERPCs.RPC_ON_SET_CAPTIVE:
				CallMethod( CALL_ID_HIDE_INVENTORY, NULL );
			break;
			
			case ERPCs.RPC_DAMAGE_VALUE_SYNC:
				if ( m_TrasferValues ) 
					m_TrasferValues.OnRPC(ctx);
			break; 
			
			case ERPCs.RPC_DEBUG_MONITOR_FLT:
				if ( m_DebugMonitorValues ) 
					m_DebugMonitorValues.OnRPCFloat(ctx);
			break;
			
			case ERPCs.RPC_DEBUG_MONITOR_STR:
				if ( m_DebugMonitorValues ) 
					m_DebugMonitorValues.OnRPCString(ctx);
			break;
			
			case ERPCs.RPC_SOFT_SKILLS_SPECIALTY_SYNC:
				ref Param1<float> p_synch = new Param1<float>(0);
				ctx.Read( p_synch );
				float specialty_level = p_synch.param1;
				GetSoftSkillsManager().SetSpecialtyLevel( specialty_level );
			break;

			case ERPCs.RPC_SOFT_SKILLS_STATS_SYNC:
				ref Param5<float, float, float, float, bool> p_debug_synch = new Param5<float, float ,float, float, bool>(0, 0, 0, 0, false);
				ctx.Read( p_debug_synch );
				float general_bonus_before = p_debug_synch.param1;
				float general_bonus_after = p_debug_synch.param2;
				float last_UA_value = p_debug_synch.param3;
				float cooldown_value = p_debug_synch.param4;
				float cooldown_active = p_debug_synch.param5;
				GetSoftSkillsManager().SetGeneralBonusBefore( general_bonus_before );
				GetSoftSkillsManager().SetGeneralBonusAfter( general_bonus_after );
				GetSoftSkillsManager().SetLastUAValue( last_UA_value );
				GetSoftSkillsManager().SetCoolDownValue( cooldown_value );
				GetSoftSkillsManager().SetCoolDown( cooldown_active );
			break;
			
			case ERPCs.RPC_INIT_SET_QUICKBAR:
				ref Param1<int> count = new Param1<int>(0); 
				if ( ctx.Read( count ) );
				{
					for ( int i = 0; i < count.param1 ; i++ )
					{
						m_QuickBarBase.OnSetEntityRPC(ctx);	
					}
				}
			break;
			
			case ERPCs.DEV_REQUEST_PLAYER_DEBUG:
				PluginRemotePlayerDebugServer plugin_remote_server = PluginRemotePlayerDebugServer.Cast( GetPlugin(PluginRemotePlayerDebugServer) );
				plugin_remote_server.OnRPC(ctx, this);
			break;
			
			case ERPCs.DEV_PLAYER_DEBUG_DATA:
				PluginRemotePlayerDebugClient plugin_remote_client = PluginRemotePlayerDebugClient.Cast( GetPlugin(PluginRemotePlayerDebugClient) );
				plugin_remote_client.OnRPC(ctx);
			break;
			
			case ERPCs.DEV_AGENT_GROW:
			{
				m_AgentPool.RemoteGrowRequestDebug(ctx);
				break;
			}
			
			case ERPCs.RPC_SYNC_THERMOMETER:
			{
				float value;
				if ( ctx.Read( value ) )
					m_Hud.SetTemperature( value.ToString() + "#degrees_celsius" );
				break;
			}
			
			/*
			case ERPCs.RPC_ITEM_SPLIT:
				Param1<ItemBase> param = new Param1<ItemBase>(null);
				if( ctx.Read( param ) );
				{
					param.param1.SplitItem(this);
				}
			break;
			*/
			
			case ERPCs.RPC_SEND_LIGHTING_SETUP:
			{
				ref Param1<int> lightingID = new Param1<int>( 0 ); 
				if ( ctx.Read( lightingID ) )
				{
					Mission mission = GetGame().GetMission();
					if ( mission )
					{
						WorldLighting wLighting = mission.GetWorldLighting();
						if ( wLighting )
							wLighting.SetGlobalLighting( lightingID.param1 );
					}
				}
				break;
			}
			
			case ERPCs.RPC_WARNING_ITEMDROP:
			{
				if ( GetGame().IsClient() && GetGame().GetUIManager() && !GetGame().GetUIManager().FindMenu(MENU_WARNING_ITEMDROP) )
				{
					//GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().GetUIManager().EnterScriptedMenu,1000,false,MENU_WARNING_ITEMDROP,null);
					GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(GetGame().GetUIManager().EnterScriptedMenu,MENU_WARNING_ITEMDROP,null);
					GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
				}
				break;
			}
		}
		
		//woodcutting
		switch (rpc_type)
		{
			case PlantType.TREE_HARD:
				SoundHardTreeFallingPlay();
			break;
			
			case PlantType.TREE_SOFT:
				SoundSoftTreeFallingPlay();
			break;
			
			case PlantType.BUSH_HARD:
				SoundHardBushFallingPlay();
			break;
			
			case PlantType.BUSH_SOFT:
				SoundSoftBushFallingPlay();
			break;
		}
#ifdef DEVELOPER
			PluginDeveloper module_rc = PluginDeveloper.Cast( GetPlugin(PluginDeveloper) );
			if ( module_rc ) 
				module_rc.OnRPC(this, rpc_type, ctx);
			
			PluginDeveloperSync module_rcs = PluginDeveloperSync.Cast( GetPlugin(PluginDeveloperSync) );
			if ( module_rcs ) 
				module_rcs.OnRPC(this, rpc_type, ctx);
			
			PluginDiagMenu plugin_diag_menu = PluginDiagMenu.Cast( GetPlugin(PluginDiagMenu) );
			if ( plugin_diag_menu ) 
				plugin_diag_menu.OnRPC(this, rpc_type, ctx);
#endif
	}
	
	// -------------------------------------------------------------------------
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( m_ModuleLifespan )
		{
			m_ModuleLifespan.SynchLifespanVisual( this, m_LifeSpanState, m_HasBloodyHandsVisible, m_HasBloodTypeVisible, m_BloodType );
			
			if (m_LifespanLevelLocal != m_LifeSpanState) //client solution, lifespan level changed
			{
				m_LifespanLevelLocal = m_LifeSpanState;
				UpdateHairSelectionVisibility();
			}	
		}
		
		CheckSoundEvent();
		if ( GetBleedingManagerRemote() )
		{
			GetBleedingManagerRemote().OnVariablesSynchronized(GetBleedingBits());
		}
		
		if( m_CorpseStateLocal != m_CorpseState )
		{
			UpdateCorpseStateVisual();
			m_CorpseStateLocal = m_CorpseState;
			
			//perpetual client-side update of decay state, potential fix for texture loading issue?
			/*if (m_CorpseState == PlayerConstants.CORPSE_STATE_DECAYED)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.UpdateCorpseStateVisual, 30000, true);
			}*/
		}
		
		if(m_RefreshAnimStateIdx != m_LocalRefreshAnimStateIdx)
		{
			RefreshHandAnimationState(396); //mean animation blend time
			m_LocalRefreshAnimStateIdx = m_RefreshAnimStateIdx;
		}
	}
	
	void OnInventoryMenuOpen()
	{
	
	}
	
	void OnInventoryMenuClose()
	{
	
	}
	
	//--------------------------------------------------------------------------
	void OnSelectPlayer()
	{
		//Print("PlayerBase | OnSelectPlayer()");
		m_QuickBarBase.updateSlotsCount();
		
		m_PlayerSelected = true;

		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer() )
		{
			//! add callbacks for ai target system
			SetAITargetCallbacks(new AITargetCallbacksPlayer(this));

			array<ref Param> params = new array<ref Param>;	
			if( m_aQuickBarLoad )
			{
				int count = m_aQuickBarLoad.Count();
				ref Param1<int> paramCount = new Param1<int>(count);
				params.Insert(paramCount);
				for(int i = 0; i < count; i++)
				{
					m_QuickBarBase.OnSetEntityNoSync(m_aQuickBarLoad.Get(i).param1,m_aQuickBarLoad.Get(i).param2);
					params.Insert(m_aQuickBarLoad.Get(i));
				}					
							
				if(count > 0 && GetGame().IsMultiplayer() )
				{
					GetGame().RPC(this, ERPCs.RPC_INIT_SET_QUICKBAR, params, true, GetIdentity());
				}
				m_aQuickBarLoad = NULL;
			}		
			
			GetSoftSkillsManager().InitSpecialty( GetStatSpecialty().Get() );
			GetModifiersManager().SetModifiers(true);
			
			SetSynchDirty();
			
			if ( GetGame().IsMultiplayer() )
			{
				//Drop item warning
				if ( m_ProcessUIWarning )
				{
					GetGame().RPCSingleParam(this, ERPCs.RPC_WARNING_ITEMDROP, null, true, GetIdentity());
					m_ProcessUIWarning = false;
				}
				
				GetGame().GetMission().SyncRespawnModeInfo(GetIdentity());
			}
		}
		
		CheckForGag();
		
		if(GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
		{
			m_ActionManager = new ActionManagerServer(this);

		}
		else
		{
			m_ActionManager = new ActionManagerClient(this);
		}
		
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			//m_PlayerLightManager = new PlayerLightManager(this);
			if( GetGame().GetMission() )
			{
				GetGame().GetMission().ResetGUI();
				// force update player
				GetDayZGame().GetBacklit().UpdatePlayer(true);
			}
					
			m_DeathCheckTimer = new Timer();
			m_DeathCheckTimer.Run(0.1, this, "CheckDeath", NULL, true);
			PPEffects.ResetAll();
			CheckForBurlap();
			
			int char_count = GetGame().GetMenuData().GetCharactersCount() - 1;
			int idx = GetGame().GetMenuData().GetLastPlayedCharacter();
			if ( idx == GameConstants.DEFAULT_CHARACTER_MENU_ID || idx > char_count )
			{
				GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(SetNewCharName);
			}
			if ( IsAlive() )
			{
				SimulateDeath(false);		
				if( GetGame().GetUserManager() && GetGame().GetUserManager().GetSelectedUser() )
				{
					ref StatsEventDeathData data = new StatsEventDeathData();
					data.m_CharacterId = g_Game.GetDatabaseID();
					data.m_CharacterLifetime = StatGet( "lifetime" );
					data.m_Cause = "Death";
					data.m_WeaponName = "Unknown";
					data.m_Distance = 0;
					data.m_Position = vector.Zero;
					Analytics.PlayerDeath(data);
				}
			}
			
			if( !GetGame().GetUIManager().GetMenu() )
				GetGame().GetMission().PlayerControlEnable(true);
			
			m_PresenceNotifier = PluginPresenceNotifier.Cast( GetPlugin( PluginPresenceNotifier ) );
			m_PresenceNotifier.Init(this);
		}
#ifdef BOT
		m_Bot = new Bot(this);
		m_Bot.Start(true, new MyBotTrigger(this));
#endif
	}
	
	void SetNewCharName()
	{
		//Print("SetNewCharName");
		g_Game.GetMenuData().SaveCharacter(false,true);
		g_Game.GetMenuData().SetCharacterName(g_Game.GetMenuData().GetLastPlayedCharacter(), g_Game.GetMenuDefaultCharacterData(false).GetCharacterName() );
		//g_Game.GetMenuData().SaveCharacter(false,true);
		g_Game.GetMenuData().SaveCharactersLocal();
	}

	void CheckForBurlap()
	{
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			BurlapSackCover attachment;
			Class.CastTo(attachment, GetInventory().FindAttachment(InventorySlots.HEADGEAR));
			if ( attachment )
			{
				PPEffects.EnableBurlapSackBlindness();
			}
			else
			{
				PPEffects.DisableBurlapSackBlindness();
			}
		}
	}
	
	void CheckForGag()
	{
		Clothing item;
		Class.CastTo(item, GetInventory().FindAttachment(InventorySlots.MASK));
		if ( !item )
		{
			Class.CastTo(item, GetInventory().FindAttachment(InventorySlots.HEADGEAR));
		}
		
		if ( item && item.IsObstructingVoice() )
		{
			item.MutePlayer(this,true);
		}
		else 
		{
			if (( GetGame().IsServer() && GetGame().IsMultiplayer() ) || ( GetGame().GetPlayer() == this ))
			{
				GetGame().SetVoiceEffect(this, VoiceEffectMumbling, false);
				GetGame().SetVoiceEffect(this, VoiceEffectObstruction, false);
			}
		}
	}
	
	// -------------------------------------------------------------------------
	override bool OnInputUserDataProcess(int userDataType, ParamsReadContext ctx)
	{
		if( super.OnInputUserDataProcess(userDataType, ctx) )
			return true;
		
		if( m_QuickBarBase.OnInputUserDataProcess(userDataType, ctx) )
			return true;
		
		if( m_WeaponManager.OnInputUserDataProcess(userDataType, ctx) )
			return true;

		if( HandleRemoteItemManipulation(userDataType, ctx) )
			return true;
		
		if ( userDataType == INPUT_UDT_INVENTORY && GetHumanInventory().OnInputUserDataProcess(ctx) )
			return true;
		
		if ( TogglePlacingServer( userDataType, ctx ) )
			return true;
		
		if ( ResetADSPlayerSync( userDataType, ctx ) )
			return true;
		
		string uid;
		bool mute;
		if( userDataType == INPUT_UDT_USER_MUTE_XBOX )
		{
			if( ctx.Read( uid ) && ctx.Read( mute ) )
			{
				GetGame().MutePlayer( uid, GetIdentity().GetPlainId(), mute );
				// commented because plainID should not be present in logs
				//Print( "Player: " + GetIdentity().GetId() + " set mute for " + uid + " to " + mute );
			}
		}
		
		if( m_EmoteManager && userDataType == INPUT_UDT_GESTURE )	 return m_EmoteManager.OnInputUserDataProcess(userDataType, ctx);
		
		//if( m_hac ) 	return EndMapAnim(userDataType, ctx);
		
		if( userDataType == INPUT_UDT_WEAPON_LIFT_EVENT )
			return ReadLiftWeaponRequest(userDataType, ctx);
		
		if( m_ActionManager )
			return m_ActionManager.OnInputUserDataProcess(userDataType, ctx);
		return false;
	}

	bool HandleRemoteItemManipulation(int userDataType, ParamsReadContext ctx)
	{
		if( userDataType == INPUT_UDT_ITEM_MANIPULATION )
		{
			int type = -1;
			ItemBase item1 = null;
			ItemBase item2 = null;
			bool use_stack_max = false;
			int slot_id = -1;

			if (!ctx.Read(type))
				return false;
			
			if (type == 4)
			{
				if (!ctx.Read(item1))
					return false;
				InventoryLocation dst = new InventoryLocation;
				if (dst.ReadFromContext(ctx))
				{
					Print(InventoryLocation.DumpToStringNullSafe(dst));
					bool dummy;
					if (ctx.Read(dummy))
						item1.SplitItemToInventoryLocation(dst);
					else
						item1.SplitIntoStackMaxToInventoryLocation(dst);
					return true;
				}
				return false;
			}
			
			if (!ctx.Read(item1))
				return false;
			if (!ctx.Read(item2))
				return false;
			if (!ctx.Read(use_stack_max))
				return false;
			if (!ctx.Read(slot_id))
				return false;
			
			if ( type == -1 && item1 && item2 )//combine
			{
				item1.CombineItems( item2, use_stack_max );
			}
			else if ( type == 1 && item1 )
			{
				if ( use_stack_max )
					item1.SplitIntoStackMax(item2, slot_id, this);
				else
					item1.SplitItem(this);
			}
			else if ( type == 2 && item1 )
			{
				int row, col;
				if ( !ctx.Read( row ) )
					return false;
				if ( !ctx.Read( col ) )
					return false;
				item1.SplitIntoStackMaxCargo( item2, slot_id, row, col );
			}
			else if ( type == 3 && item1 )
			{
				item1.SplitIntoStackMaxHands( this );
			}
			return true;
		}
		return false;
	}
	
	// -------------------------------------------------------------------------
	ItemBase GetItemInHands()
	{
		return ItemBase.Cast( GetHumanInventory().GetEntityInHands() );
		
	}

	//--------------------------------------------------------------------------


	override EntityAI SpawnEntityOnGroundPos (string object_name, vector pos)
	{
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer() )
		{
			bool is_AI = GetGame().IsKindOf( object_name, "DZ_LightAI");
			if (is_AI)
			{
				return SpawnAI(object_name, pos);
			}
			else
			{
				InventoryLocation inv_loc = new InventoryLocation;
				vector mtx[4];
				Math3D.MatrixIdentity4(mtx);
				mtx[3] = pos;
				inv_loc.SetGround(NULL, mtx);
				//return GetGame().SpawnEntity(object_name, inv_loc, ECE_PLACE_ON_SURFACE, RF_DEFAULT);
				return EntityAI.Cast(GetGame().CreateObjectEx(object_name, inv_loc.GetPos(), ECE_PLACE_ON_SURFACE));
			}
		}
		return null;
	}

	EntityAI SpawnEntityOnGroundOnCursorDir (string object_name, float distance)
	{
		vector position = GetPosition() + ( GetDirection() * distance );
		return SpawnEntityOnGroundPos(object_name, position);
	}

	EntityAI SpawnAI (string object_name, vector pos)
	{
		bool is_ai = GetGame().IsKindOf( object_name, "DZ_LightAI");
		if (is_ai)
		{
			return EntityAI.Cast( GetGame().CreateObject(object_name, pos, false, is_ai) );
		}
		return NULL;
	}


	/*EntityAI SpawnAttachmentOnPointerPos (string object_name, bool full_quantity, EntityAI attachmentObject = NULL)
	{
		Object cursor_obj = GetCursorObject();
		if ( cursor_obj != NULL && cursor_obj.IsInherited(EntityAI) )
		{
			EntityAI eai = (EntityAI)cursor_obj;
			eai.TakeEntityAsAttachment(item);
		}
		else if ( attachmentObject != NULL)
		{
			attachmentObject.TakeEntityAsAttachment(item);
		}
	}*/

	/**
	\brief Spawn item on server side
		\param object_name \p string Name of item class
		\param spawn_type \int(const) Type of spawning const: SPAWNTYPE_GROUND, SPAWNTYPE_HANDS, SPAWNTYPE_INVENTORY
		\param full_quantity \bool Spawn with full quantity of item
		\param distance \float Distance of spawn position from player (Only if spawn_type = SPAWNTYPE_GROUND)
		\returns \p ItemBase Spawned item
		@code
			PlayerBase player = GetGame().GetPlayer();
			
			player.SpawnItem("Fruit_Apple", SPAWNTYPE_GROUND, true, 5);
		@endcode
	*/
	/*EntityAI SpawnItem (string object_name, bool full_quantity, float distance = 0, bool usePosition = false, vector pos = "0 0 0", EntityAI attachmentObject = NULL)
	{
		EntityAI entity = NULL;

		// Creat Object
		bool is_ai = GetGame().IsKindOf( object_name, "DZ_LightAI");
		vector item_position;
		if( usePosition )
		{
			item_position = pos;
		}
		else
		{
			item_position = GetPosition() + ( GetDirection() * distance );
		}
		entity = GetGame().CreateObject(object_name, item_position, false, is_ai);

		if ( !entity )
		{
			string s = "Cannot spawn entity: "+object_name;
			Print(s);
			//g_Game.GetUIManager().ShowDialog("Spawn error", "Cannot spawn item: "+object_name, 0, DBT_OK, DBB_YES, DMT_EXCLAMATION, this);
			return NULL;
		}

		if ( entity.IsInherited( ItemBase ) )
		{
			ItemBase item = entity;

			// Set full quantity
			if ( full_quantity )
			{
				item.SetQuantity(item.GetQuantityMax());
			}

			// Spawn In Inventory
			if ( spawn_type == SPAWNTYPE_INVENTORY )
			{
				TakeItemToInventory(item);
			}
			// Spawn In Hands
			if ( spawn_type == SPAWNTYPE_HANDS )
			{
				TakeItemToHands(item);
			}
			// Spawn As Attachment
			if ( spawn_type == SPAWNTYPE_ATTACHMENT )
			{
				Object cursor_obj = GetCursorObject();
				if ( cursor_obj != NULL && cursor_obj.IsInherited(EntityAI) )
				{
					EntityAI eai = (EntityAI)cursor_obj;
					eai.TakeEntityAsAttachment(item);
				}
				else if ( attachmentObject != NULL)
				{
					attachmentObject.TakeEntityAsAttachment(item);
				}
			}
		}

		return entity;
	}*/

	//--------------------------------------------------------------------------
	bool DropItem(ItemBase item)
	{
		bool can_be_dropped = CanDropEntity( item );
		if( can_be_dropped )
		{
			can_be_dropped = PredictiveDropEntity( item );
		}

		vector 	pos_spawn	= GetPosition() + GetDirection();
		pos_spawn[0]		= pos_spawn[0] + Math.RandomFloat(-0.2, 0.2);
		pos_spawn[2]		= pos_spawn[2] + Math.RandomFloat(-0.2, 0.2);

		item.SetPosition(pos_spawn);
		item.PlaceOnSurface();
		return can_be_dropped;
	}

	/*bool TakeItemToInventory (bool synchronize, ItemBase item)
	{
		ItemBase itemInHands;
		itemInHands = GetItemInHands();

		if ( itemInHands == item )
		{
			SynchronizedMoveItemFromHandsToInventory(synchronize);
			return true;
		}

		// in case the player have a cargo item in hands we put item from vicinity into it
		if ( itemInHands && itemInHands.GetInventory().GetCargo() )
		{
			if( itemInHands.GetInventory().CanAddEntityIntoInventory(item) )
			{
				EntityAI entity;
				Class.CastTo(entity, item);
				itemInHands.SynchronizedTakeEntityToCargo(do_synchronize, entity);
				return true;
			}
		}

		if ( GetInventory().CanAddEntityToInventory(item) )
		{
			SynchronizedTakeEntityToInventory(synchronize, item);
			return true;
		}

		//g_Game.GetUIManager().ShowDialog("Spawn error", "Cannot take item into inventory! ("+object_name+")", 0, DBT_OK, DBB_YES, DMT_EXCLAMATION, this);
		return false;
	}

	void TakeItemToHands(ItemBase item)
	{
		TakeEntityToHands(item);
	}*/

	// -------------------------------------------------------------------------
	/**
	/brief Creates \p ItemBase in players inventory. If player dont have enough slots for new item, item will be created on the ground under player.
		\param item_name \p string Class name of ItemBase in configs
		\returns \p ItemBase Created item
		@code
			ItemBase item = g_Game.GetPlayer().CreateInInventory("Consumable_GardenLime", "cargo_weapon");
		@endcode
	*/
	
	
	EntityAI CreateInInventory( string item_name, string cargo_type = "", bool full_quantity = false ) // TODO: Create item in cargo
	{
		InventoryLocation inv_loc = new InventoryLocation;
		if (GetInventory().FindFirstFreeLocationForNewEntity(item_name, FindInventoryLocationType.ANY, inv_loc))
		{
			return SpawnItemOnLocation(item_name, inv_loc, full_quantity);
		}
		return NULL;
	}


	// -------------------------------------------------------------------------
	/**
	/brief Creates copy of \p ItemBase in players inventory. If player dont have enough slots for new item, item will be created on the ground under player.
		\param item_name \p string Class name of ItemBase in configs
		\returns \p ItemBase Created item
		@code
			ItemBase item = g_Game.GetPlayer().CreateInInventory("Consumable_GardenLime", "cargo_weapon");
		@endcode
	*/
	/*ItemBase CopyInventoryItem( ItemBase orig_item )
	{
		ItemBase item = ItemBase.Cast( GetInventory().CreateInInventory( orig_item.GetType() ) );
		if ( item == NULL )
		{
			return NULL;
		}

		// Copy of quantity
		item.SetQuantity( orig_item.GetQuantity() );

		// Copy of damage
		item.SetHealth( "", "", orig_item.GetHealth("", "") );

		return item;
	}*/
	
	ItemBase CreateCopyOfItemInInventory ( ItemBase src )
	{
		InventoryLocation loc = new InventoryLocation;
		string t = src.GetType();
		if (GetInventory().FindFirstFreeLocationForNewEntity(t, FindInventoryLocationType.CARGO, loc))
		{
			bool locked = GetGame().HasInventoryJunctureDestination(this, loc);
			if (locked)
			{
				Print("Warning: Split: CreateCopyOfItemInInventory - Cannot create entity at locked inventory at loc=" + InventoryLocation.DumpToStringNullSafe(loc));
				return null;
			}
			ItemBase dst = ItemBase.Cast( GetInventory().LocationCreateLocalEntity(loc, t, ECE_IN_INVENTORY, RF_DEFAULT) );
			if (dst)
			{
				MiscGameplayFunctions.TransferItemProperties(src, dst);

				GetGame().RemoteObjectTreeCreate(dst);
				
				Print("CreateCopyOfItemInInventory - created " + dst.GetName() + " at loc=" + InventoryLocation.DumpToStringNullSafe(loc));
			}
			return dst;
		}
		return NULL;
	}
	
	ItemBase CreateCopyOfItemInInventoryOrGround ( ItemBase src )
	{
		ItemBase dst = CreateCopyOfItemInInventory(src);
		if (!dst)
		{
			Print("CreateCopyOfItemInInventoryOrGround - cannot create in inv, creating on gnd");
			//new_item = GetGame().CreateObject(this.GetType(), this.GetPosition() + "1 0 0" );
			dst = ItemBase.Cast(SpawnEntityOnGroundPos(src.GetType(), this.GetPosition()));
			dst.PlaceOnSurface();
			MiscGameplayFunctions.TransferItemProperties(src, dst);
		}
		return dst;
	}



	// -------------------------------------------------------------------------
	/**
	colorStatusChannel
	colorAction
	colorFriendly
	colorImportant
	*/
	void Message( string text, string style )
	{
		if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
		{
			GetGame().ChatMP(this, text, style );
		}
		else
		{
			GetGame().Chat( text, style );
		}
	}

	// -------------------------------------------------------------------------
	void MessageStatus( string text )
	{
		Message( text, "colorStatusChannel" );
	}

	// -------------------------------------------------------------------------
	void MessageAction( string text )
	{
		Message( text, "colorAction" );
	}

	// -------------------------------------------------------------------------
	void MessageFriendly( string text )
	{
		Message( text, "colorFriendly" );
	}

	// -------------------------------------------------------------------------
	void MessageImportant( string text )
	{
		Message( text, "colorImportant" );
	}

	void CloseInventoryMenu()
	{
		if( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			UIScriptedMenu menu = GetGame().GetUIManager().GetMenu();
			if( menu && ( menu.GetID() == MENU_INVENTORY || menu.GetID() == MENU_INSPECT ) )
			{
				GetGame().GetUIManager().CloseAll();
				GetGame().GetMission().PlayerControlEnable(true);
			}
		}
	}
	
	// -------------------------------------------------------------------------
	/**
	/brief Delete all items in inventory
		\returns \p void
		@code
			PlayerBase player = GetGame().GetPlayer();
			player.ClearInventory();
		@endcode
	*/
	void ClearInventory( )
	{
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer() )
		{
			ItemBase item;
			for ( int i = 0; i < GetInventory().GetAttachmentSlotsCount(); ++i )
			{
				item = ItemBase.Cast( GetInventory().FindAttachment(i) );
				if ( item )
				{
					GetGame().ObjectDelete(item);
				}
			}

			ItemBase item_in_hands = ItemBase.Cast( GetHumanInventory().GetEntityInHands() );

			if ( item_in_hands )
			{
				LocalDestroyEntityInHands();
			}
		}
	}
	
	//! Drops all clothes/wearables this character is carrying on themselves.
	void DropAllItems()
	{
		array<EntityAI> itemsArray = new array<EntityAI>;
		ItemBase item;
		GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, itemsArray);
		int count = itemsArray.Count();
		
		for (int i = 0; i < itemsArray.Count(); i++)
		{
			Class.CastTo(item, itemsArray.Get(i));
			
			if (item  &&  !item.IsInherited(SurvivorBase))	
			{
				ServerDropEntity(item);
			}
		}
	}

	string GetPlayerClass()
	{
		string type;
		GetGame().ObjectGetType( this, type );
		return type;
	}

	// --------------------------------------------------
	// Lifespan
	//---------------------------------------------------
	
	void ShavePlayer()
	{
		SetLastShavedSeconds( StatGet("playtime") );

		m_ModuleLifespan.UpdateLifespan( this, true );
	}

	bool CanShave()
	{
		if ( GetLifeSpanState() )
		{
			return true;		
		}
		else
		{
			return false;			
		}
	}
	
	bool CanSpawnBreathVaporEffect()
	{
		if( !ToDelete() && IsAlive() && !IsSwimming() )
		{
			return true;
		}
		return false;
	}
	

	void ProcessADDModifier()
	{
		if( m_AddModifier != -1 )
		{
			HumanCommandAdditives ad = GetCommandModifier_Additives();
			if(ad)
				ad.StartModifier(m_AddModifier);
			
			m_AddModifier = -1;
		}
	}
	
	void SpawnBreathVaporEffect()
	{
		//Print("SpawnBreathVaporEffect:"+GetGame().GetTime());
		int boneIdx = GetBoneIndexByName("Head");
		if ( boneIdx != -1 )
		{
			Particle p;
			switch (m_BreathVapour)
			{
				case 1:
					p = Particle.PlayInWorld(ParticleList.BREATH_VAPOUR_LIGHT, "-0.03 0.15 0");
					break;
				case 2:
					p = Particle.PlayInWorld(ParticleList.BREATH_VAPOUR_MEDIUM, "-0.03 0.15 0");
					break;
				case 3:
					p = Particle.PlayInWorld(ParticleList.BREATH_VAPOUR_HEAVY, "-0.03 0.15 0");
					break;
				default:
					break;
			}
			
			if ( p )
				AddChild(p, boneIdx);
		}
	}

	void SetLifeSpanStateVisible( int show_state )
	{
		bool state_changed;
		if (show_state != m_LifeSpanState)
			state_changed = true;
		m_LifeSpanState = show_state;
		SetSynchDirty();
		
		if (state_changed) //server only, client solution in OnVariablesSynchronized()
		{
			//SendLifespanSyncEvent(m_LifeSpanState);
			
			UpdateHairSelectionVisibility();
		}
	}
	
	int GetLifeSpanState()
	{
		return m_LifeSpanState;
	}
	
	int GetLastShavedSeconds()
	{
		return m_LastShavedSeconds;
	}

	void SetLastShavedSeconds( int last_shaved_seconds )
	{
		m_LastShavedSeconds = last_shaved_seconds;
	}
	
	bool HasBloodyHands()
	{
		return m_HasBloodyHandsVisible;
	}

	void SetBloodyHands( bool show )
	{
		m_HasBloodyHandsVisible = show;
		SetSynchDirty();
	}
	
	void SetBloodyHandsPenalty()
	{
		InsertAgent( eAgents.SALMONELLA, 1 );
	}
	
	bool HasBloodTypeVisible()
	{
		return m_HasBloodTypeVisible;
	}
	
	void SetBloodTypeVisible( bool show )
	{
		m_HasBloodTypeVisible = show;
		SetSynchDirty();
	}
			
	int GetBloodType()
	{
		return m_BloodType;
	}
	
	void SetBloodType( int blood_type )
	{
		m_BloodType = blood_type;
		SetSynchDirty();
	}

	// --------------------------------------------------
	// Soft Skills
	//---------------------------------------------------
	
	SoftSkillsManager GetSoftSkillsManager()
	{
		return m_SoftSkillsManager;
	}
	
	void CheckDeath()
	{
		if( IsPlayerSelected() && !IsAlive() )
		{
			SimulateDeath(true);
			m_DeathCheckTimer.Stop();
		}
	}
	
	// -------------------------------------------------------------------------
	
	// --------------------------------------------------
	// AI Presence
	//---------------------------------------------------
	
	//! Return actual noise presence of player
	int GetNoisePresenceInAI()
	{
		if (m_PresenceNotifier)
		{
			return m_PresenceNotifier.GetNoisePresence();
		}

		return 0;
	}

	// -------------------------------------------------------------------------

	int GetStoreLoadVersion()
	{
		return m_StoreLoadVersion;
	}

	override void OnStoreSave( ParamsWriteContext ctx )
	{
		if( GetGame().SaveVersion() < 102 )
		{
			ctx.Write( ACT_STORE_SAVE_VERSION );//to be removed after we push 102+
		}

		super.OnStoreSave( ctx );

		GetHumanInventory().OnStoreSave(ctx); // FSM of hands
		OnStoreSaveLifespan( ctx );

		if ( GetDayZGame().IsServer() && GetDayZGame().IsMultiplayer() )
		{
			GetPlayerStats().SaveStats(ctx);// save stats
			m_ModifiersManager.OnStoreSave(ctx);// save modifiers
			m_AgentPool.OnStoreSave(ctx);//save agents
			GetSymptomManager().OnStoreSave(ctx);//save states
			GetBleedingManagerServer().OnStoreSave(ctx);//save bleeding sources
			m_PlayerStomach.OnStoreSave(ctx);
			ctx.Write( m_BrokenLegState );
			ctx.Write( m_LocalBrokenState );
		}
	}

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		//Print("---- PlayerBase OnStoreLoad START ----, version: "+version);
		m_aQuickBarLoad = new array<ref Param2<EntityAI,int>>;
		
		// todo :: this should be after base call !!!!
		if( version < 102 )//write removed in v. 102
		{
			if(!ctx.Read( m_StoreLoadVersion ))
				return false;
		}

		if ( !super.OnStoreLoad( ctx, version ) )
			return false;

		// FSM of hands
		if ( !GetHumanInventory().OnStoreLoad(ctx, version) )
			return false;

		if ( !OnStoreLoadLifespan( ctx, version ) )
			return false;

		if ( GetDayZGame().IsServer() && GetDayZGame().IsMultiplayer() )
		{
			if(!GetPlayerStats().LoadStats(ctx, version)) // load stats
			{
				Print("---- failed to load PlayerStats  ----");
				return false;
			}
			
			if( version < m_ModifiersManager.GetStorageVersion() )//load modifiers !! WILL CANCEL REST OF STREAM IF UNSUPPORTED VERSION !!
			{
				Print("---- failed to load ModifiersManager, unsupported version   ----");
				return false;
			}
			else
			{
				if(!m_ModifiersManager.OnStoreLoad(ctx, version))
				{
					Print("---- failed to load ModifiersManager, read fail  ----");
					return false;
				}
			}
			
			if( version < m_AgentPool.GetStorageVersion() )//load agents !! WILL CANCEL REST OF STREAM IF UNSUPPORTED VERSION !!
			{
				Print("---- failed to load AgentPool, unsupported version   ----");
				return false;
			}
			else
			{
				if(!m_AgentPool.OnStoreLoad(ctx, version))
				{
					Print("---- failed to load AgentPool, read fail  ----");
					return false;
				}
			}
			
			
			if( version < GetSymptomManager().GetStorageVersion() )//load symptoms !! WILL CANCEL REST OF STREAM IF UNSUPPORTED VERSION !!
			{
				Print("---- failed to load SymptomManager, unsupported version   ----");
				return false;
			}
			else
			{
				if(!GetSymptomManager().OnStoreLoad(ctx, version))
				{
					Print("---- failed to load SymptomManager, read fail  ----");
					return false;
				}
			}
			
			if( version < GetBleedingManagerServer().GetStorageVersion() )//load bleeding manager !! WILL CANCEL REST OF STREAM IF UNSUPPORTED VERSION !!
			{
				Print("---- failed to load BleedingManagerServer, unsupported version  ----");
				return false;
			}
			else
			{
				if(!GetBleedingManagerServer().OnStoreLoad(ctx, version))
				{
					Print("---- failed to load BleedingManagerServer, read fail  ----");
					return false;
				}
			}
			
			if( version < m_PlayerStomach.GetStorageVersion() )//load PlayerStomach !! WILL CANCEL REST OF STREAM IF UNSUPPORTED VERSION !!
			{
				Print("---- failed to load PlayerStomach, unsupported version  ----");
				return false;
			}
			else
			{
				if(!m_PlayerStomach.OnStoreLoad(ctx, version))
				{
					Print("---- failed to load PlayerStomach, read fail  ----");
					return false;
				}
			}
			
			//Check for broken leg value
			if ( version >= 116 && (!ctx.Read( m_BrokenLegState ) || !ctx.Read( m_LocalBrokenState )) )
			{
				m_BrokenLegState = eBrokenLegs.NO_BROKEN_LEGS;
				m_LocalBrokenState = eBrokenLegs.NO_BROKEN_LEGS;
				return false;
			}
		}
		
		Print("---- PlayerBase OnStoreLoad SUCCESS ----");
		return true;
	}

	override void AfterStoreLoad()
	{
		GetHumanInventory().OnAfterStoreLoad();
		if (m_EmoteManager)
		{
			m_EmoteManager.AfterStoreLoad();
		}
		UpdateWeight();
		SetPlayerLoad( GetWeight() );
		//SetSynchDirty();		
	}

	void OnStoreSaveLifespan( ParamsWriteContext ctx )
	{		
		ctx.Write( m_LifeSpanState );	
		ctx.Write( m_LastShavedSeconds );	
		ctx.Write( m_HasBloodyHandsVisible );
		ctx.Write( m_HasBloodTypeVisible );
		ctx.Write( m_BloodType );
	}

	bool OnStoreLoadLifespan( ParamsReadContext ctx, int version )
	{	
		int lifespan_state = 0;
		if(!ctx.Read( lifespan_state ))
			return false;
		m_LifeSpanState = lifespan_state;
		
		int last_shaved = 0;
		if(!ctx.Read( last_shaved ))
			return false;
		m_LastShavedSeconds = last_shaved;
		
		bool bloody_hands = false;
		if(!ctx.Read( bloody_hands ))
			return false;
		m_HasBloodyHandsVisible = bloody_hands;
		
		bool blood_visible = false;
		if(!ctx.Read( blood_visible ))
			return false;
		m_HasBloodTypeVisible = blood_visible;
		
		int blood_type = 0;
		if(!ctx.Read( blood_type ))
			return false;
		m_BloodType = blood_type;

		return true;
	}
	
	vector m_PlayerOldPos;
	void UpdatePlayerMeasures()
	{
		int hour, minute, second;
		GetHourMinuteSecond( hour, minute, second );
		float distance;
		distance = StatGet("playtime");
		if( m_AnalyticsTimer )
		{
			ref StatsEventMeasuresData data = new StatsEventMeasuresData();
			data.m_CharacterId = g_Game.GetDatabaseID();
			data.m_TimeInterval = m_AnalyticsTimer.GetRemaining();
			data.m_DaytimeHour = hour;
			data.m_PositionStart = m_PlayerOldPos;
			data.m_PositionEnd = GetPosition();
			data.m_DistanceOnFoot = distance;
			Analytics.PlayerMeasures(data);
		}

		m_PlayerOldPos = GetPosition();
	}

	void OnConnect()
	{
		Debug.Log("Player connected:"+this.ToString(),"Connect");

		// analytics
		GetGame().GetAnalyticsServer().OnPlayerConnect( this );
		
		m_PlayerOldPos = GetPosition();
		if( m_AnalyticsTimer )
			m_AnalyticsTimer.Run( 60, this, "UpdatePlayerMeasures", null, true );
		
		//construction action data
		ResetConstructionActionData();
	}
	
	void OnReconnect()
	{
		Debug.Log("Player reconnected:"+this.ToString(),"Reconnect");
		
		//construction action data
		ResetConstructionActionData();	
	}
	
	void OnDisconnect()
	{
		Debug.Log("Player disconnected:"+this.ToString(),"Connect");
		
		// analytics
		// force update of the stats
		// if player disconnect too soon, UpdatePlayersStats() is not called
		GetGame().GetAnalyticsServer().OnPlayerDisconnect( this );
		
		ref StatsEventDisconnectedData data = new StatsEventDisconnectedData();
		data.m_CharacterId = g_Game.GetDatabaseID();
		data.m_Reason = "Disconnected";
		Analytics.PlayerDisconnected(data);
		
		if( m_AnalyticsTimer )
			m_AnalyticsTimer.Stop();
		UpdatePlayerMeasures();
		
		SetPlayerDisconnected(true);
	}

	void SetModifiers(bool enable)
	{
		GetModifiersManager().SetModifiers(enable);
	}

	bool Consume(ItemBase source, float amount, EConsumeType consume_type )
	{
		PluginTransmissionAgents plugin = PluginTransmissionAgents.Cast( GetPlugin(PluginTransmissionAgents) );
		int agents;
		if( consume_type == EConsumeType.ENVIRO_POND || consume_type == EConsumeType.ENVIRO_WELL )
		{
			if ( consume_type == EConsumeType.ENVIRO_POND )
			{
				agents = agents | eAgents.CHOLERA;
				//plugin.TransmitAgents(NULL, this, AGT_WATER_POND, amount);
			}
			m_PlayerStomach.AddToStomach(Liquid.GetLiquidClassname(LIQUID_WATER), amount, 0 , agents );
			
			
			return true;
		}
		
		Edible_Base edible_item = Edible_Base.Cast(source);
		if(!edible_item)
		{
			return false;
		}
		agents = edible_item.GetAgents();
		if( consume_type == EConsumeType.ITEM_SINGLE_TIME || consume_type == EConsumeType.ITEM_CONTINUOUS )
		{
			if(consume_type == EConsumeType.ITEM_SINGLE_TIME)
			{
				plugin.TransmitAgents(edible_item, this, AGT_UACTION_CONSUME, amount);
			}
			/*
			else
			{
				plugin.TransmitAgents(edible_item, this, AGT_UACTION_TO_PLAYER, amount);
			}
			*/
			if(edible_item.IsLiquidContainer())
			{
				int liquid_type = edible_item.GetLiquidType();
				string liquidClassName = Liquid.GetLiquidClassname(liquid_type);
				if (liquidClassName.Length() == 0)
					Error("Error! Trying to add unknown liquid to stomach with item=" + Object.GetDebugName(edible_item) + " consume_type=" + consume_type + " liquid_type=" + liquid_type);
				m_PlayerStomach.AddToStomach(liquidClassName, amount, 0, agents);
			}
			else 
			{
				int food_stage_type;
				if( edible_item.GetFoodStage() )
				{
					food_stage_type = edible_item.GetFoodStage().GetFoodStageType();
				}
				m_PlayerStomach.AddToStomach(source.GetType(), amount, food_stage_type, agents);
			}
			edible_item.Consume(amount, this);
			return true;

		}
		/*
		if( consume_type == EConsumeType.ITEM_CONTINUOUS )
		{
			if(edible_item)
			{
				plugin.TransmitAgents(edible_item, this, AGT_UACTION_TO_PLAYER, amount);
				edible_item.Consume(amount, this);
				//ProcessNutritions(edible_item.GetNutritionalProfile(),amount);
				m_PlayerStomach.AddToStomach(source.GetType(), amount, edible_item.GetNutritionalProfile());
				return true;
			}
		}
		*/
		return false;
	}
	
	/*
	void ProcessNutritions( NutritionalProfile profile, float consumedquantity )
	{	
		float energy_per_unit = profile.GetEnergy() / 100;
		float water_per_unit = profile.GetWaterContent() / 100;
		float nutritions = profile.GetNutritionalIndex();
		float fullness_index = profile.GetFullnessIndex();
		float toxicity = profile.GetToxicity();
		bool is_liquid = profile.IsLiquid();
		
		if ( consumedquantity > 0 )
		{
			float water_consumed = consumedquantity * water_per_unit;
			GetStatStomachVolume().Add(consumedquantity * fullness_index );
			GetStatStomachEnergy().Add( consumedquantity * energy_per_unit );
			GetStatStomachWater().Add( water_consumed );
			GetStatToxicity().Add( consumedquantity * toxicity );
		}
		else
		{
			Print("ProcessNutritions - ZERO VOLUME! Fix config");
		}
	}
	*/
	
	void ShowUnconsciousScreen(bool show)
	{
	#ifndef NO_GUI
		if (show)
		{
			GetGame().GetUIManager().ScreenFadeIn(0, "You are Unconscious", FadeColors.BLACK, FadeColors.WHITE);
			PrintString("Fade in");
		}
		else
		{
			GetGame().GetUIManager().ScreenFadeOut(0);
			PrintString("Fade out");
		}
	#endif
	}
	
	override void RequestSoundEvent(EPlayerSoundEventID id, bool from_server_and_client = false)
	{
		if(from_server_and_client && GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT)
		{
			PlaySoundEvent(id);
			return;
		}
		SendSoundEvent(id);
	}

	override protected void SendSoundEvent(EPlayerSoundEventID id)
	{
		if( !GetGame().IsServer() ) return;
		m_SoundEvent = id;
		SetSynchDirty();
		
		if( !GetGame().IsMultiplayer() ) 
		{
			CheckSoundEvent();
		}
		
		//PrintString(GetGame().GetTime().ToString() + " Set SoundEvent, id:" + id.ToString());
	}
	
	void CheckZeroSoundEvent()
	{
		if( m_SoundEvent != 0 && m_SoundEventSent )
		{
			m_SoundEvent = 0;
			m_SoundEventSent = false;
			//PrintString(GetGame().GetTime().ToString() + " Zero SoundEvent");
			SetSynchDirty();
		}
	}
	
	void CheckSendSoundEvent()
	{
		if( m_SoundEvent!= 0 && !m_SoundEventSent )
		{
			m_SoundEventSent = true;
			//PrintString(GetGame().GetTime().ToString() + " Send SoundEvent");
		}
	}
	
	override bool PlaySoundEvent(EPlayerSoundEventID id, bool from_anim_system = false, bool is_from_server = false)
	{
		//PrintString("Sound request for: " + this + ", controlling:" + GetGame().GetPlayer());
		return GetPlayerSoundEventHandler().PlayRequest(id, is_from_server);
	}
	
	PlayerSoundEventHandler GetPlayerSoundEventHandler()
	{
		return m_PlayerSoundEventHandler;
	}
	
	
	void OnBleedingBegin()
	{
		/*
		DisplayElementBadge dis_elm = DisplayElementBadge.Cast(GetVirtualHud().GetElement(eDisplayElements.DELM_BADGE_BLEEDING));
		
		if( dis_elm )
		{
			dis_elm.SetLevel(eBadgeLevel.FIRST);
		}
		*/
	}
	
	void OnBleedingEnd()
	{
		/*
		DisplayElementBadge dis_elm = DisplayElementBadge.Cast(GetVirtualHud().GetElement(eDisplayElements.DELM_BADGE_BLEEDING));
		
		if( dis_elm )
		{
			dis_elm.SetLevel(eBadgeLevel.NONE);
		}
		*/
	}
	
	void OnBleedingSourceAdded()
	{
		m_BleedingSourceCount++;
		if( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			DisplayElementBadge dis_elm = DisplayElementBadge.Cast(GetVirtualHud().GetElement(eDisplayElements.DELM_BADGE_BLEEDING));
			if( dis_elm )
			{
				dis_elm.SetValue(GetBleedingSourceCount());
			}
			
			
			//Print("----------bleeding_SoundSet----------");
			//SEffectManager.PlaySoundOnObject("bleeding_SoundSet", this); Removed due as it caused a freeze on the Console Submission builds.
		}
	}
	
	void OnBleedingSourceRemoved()
	{
		m_BleedingSourceCount--;
		if( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			//Print("GetBleedingSourceCount() "+GetBleedingSourceCount());
			DisplayElementBadge dis_elm = DisplayElementBadge.Cast(GetVirtualHud().GetElement(eDisplayElements.DELM_BADGE_BLEEDING));
			if( dis_elm )
			{
				dis_elm.SetValue(GetBleedingSourceCount());
			}
		}
	}
	
	int GetBleedingSourceCount()
	{
		if( !GetGame().IsMultiplayer() )
			return m_BleedingSourceCount / 2;
		return m_BleedingSourceCount;
	}
	
	/*
	bool IsSayingSound()
	{
		if(m_SaySoundWave) return true;
		else return false;
	}
	*/
	
	void CheckSoundEvent()
	{
		if(m_SoundEvent != 0)
		{
			PlaySoundEvent(m_SoundEvent, false, true);
			m_SoundEvent = 0;
		}
	}
	
	void TestSend()
	{
		if( GetGame().IsClient() ) return;
		RequestSoundEvent(1234);
		//Math.RandomInt(1,4096)
	}
	
	void SetStaminaState(eStaminaState state)
	{
		if( state != m_StaminaState )
		{
			m_StaminaState = state;
			//PrintString("m_StaminaState:"+m_StaminaState.ToString());
			SetSynchDirty();
		}
	}
	
	int GetStaminaState()
	{
		return m_StaminaState;
	}
	
	void UpdateQuickBarExtraSlots()
	{
		m_QuickBarBase.updateSlotsCount();
	}

	bool Save()
	{
		// saved player must be alive and not captive
		if (GetPlayerState() == EPlayerStates.ALIVE && !IsRestrained())
		{
			GetHive().CharacterSave(this);
			Debug.Log("Player "+this.ToString()+ " saved as alive");
			
			return true;
		}
		return false;		
	}

	// agent transfer
	void SpreadAgents()
	{
		array<Object> objects = new array<Object>;
		array<CargoBase> proxy_cargos = new array<CargoBase>;
		
		GetGame().GetObjectsAtPosition(this.GetPosition(), 3, objects, proxy_cargos);
		
		PluginTransmissionAgents plugin = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));

		for(int i = 0; i < objects.Count(); i++)
		{
			PlayerBase other_player = PlayerBase.Cast(objects.Get(i));
			if(other_player && other_player != this)
			{
				plugin.TransmitAgents(this, other_player, AGT_AIRBOURNE_BIOLOGICAL, 1);
			}
			
		}
	}
	
	/*
	bool IsInfected()
	{
		if( m_AgentPool && m_AgentPool.GetAgents().Count() != 0) 
		{
			return true;			
		}
		else
		{
			return false;
		}
	}
	*/
	//--------------------------------------------------------------------------------------------
	override int GetAgents()
	{
		return m_AgentPool.GetAgents();
	}

	//--------------------------------------------------------------------------------------------
	override void RemoveAgent(int agent_id) //removes a single agent type from the player agent pool
	{
		m_AgentPool.RemoveAgent(agent_id);
	}

	//--------------------------------------------------------------------------------------------
	override void RemoveAllAgents()
	{
		m_AgentPool.RemoveAllAgents();
	}


	//--------------------------------------------------------------------------------------------
	override void InsertAgent(int agent, float count = 1) //adds a single agent type to the player agent pool
	{
		m_AgentPool.AddAgent(agent,count);
	}

	//--------------------------------------------------------------------------------------------
	int GetSingleAgentCount(int agent_id)
	{
		return m_AgentPool.GetSingleAgentCount(agent_id);
	}

	//--------------------------------------------------------------------------------------------
	float GetSingleAgentCountNormalized(int agent_id)
	{
		int max_count = PluginTransmissionAgents.GetAgentMaxCount(agent_id);
		return m_AgentPool.GetSingleAgentCount(agent_id) / max_count;
	}

	float GetTotalAgentCount()
	{
		return m_AgentPool.GetTotalAgentCount();
	}

	void PrintAgents()
	{
		m_AgentPool.PrintAgents();
	}

	void ImmuneSystemTick(float value, float deltaT)
	{
		m_AgentPool.ImmuneSystemTick(value, deltaT);
	}
	
	void AntibioticsAttack(float value)
	{
		m_AgentPool.AntibioticsAttack(value);
	}

	//Get aim (player crosshair) position
	vector GetAimPosition()
	{
		float min_distance = 0.5;		//min distance, default = 5m
		
		vector from = GetGame().GetCurrentCameraPosition();
		vector to = from + (GetGame().GetCurrentCameraDirection() * min_distance);
		vector contactPos;
		vector contactDir;
		int contactComponent;
		
		DayZPhysics.RaycastRV( from, to, contactPos, contactDir, contactComponent, NULL, NULL, NULL, false, true );
		
		return contactPos;
	}

	//get modifier manager
	ModifiersManager GetModifiersManager()
	{
		return m_ModifiersManager;
	}

	/*
	PlayerStat<float> GetStatStomachVolume()
	{
		if( GetPlayerStats() ) 
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.STOMACH_SOLID));
			return stat;
		}
		return null;
	}
*/
	PlayerStat<float> GetStatWater()
	{
		if( GetPlayerStats() )
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.WATER));
			return stat;
		}
		return null;
	}
	
	
	PlayerStat<float> GetStatToxicity()
	{
		if( GetPlayerStats() )
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.TOXICITY));
			return stat;
		}
		return null;
	}

	/*
	PlayerStat<float> GetStatStomachWater()
	{
		if( GetPlayerStats() )
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.STOMACH_WATER));
			return stat;
		}
		return null;
	}*/

	PlayerStat<float> GetStatEnergy()
	{
		if( GetPlayerStats() ) 
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.ENERGY));
			return stat;
		}
		return null;
	}
	
	/*PlayerStat<float> GetStatShock()
	{
		if( GetPlayerStats() ) 
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.SHOCK));
			return stat;
		}
		return null;
	}*/
	
	/*
	PlayerStat<float> GetStatTemperature()
	{
		if( GetPlayerStats() ) 
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.TEMPERATURE));
			return stat;
		}
		return null;
	}
	*/
	
	PlayerStat<float> GetStatHeatComfort()
	{
		if( GetPlayerStats() ) 
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.HEATCOMFORT));
			return stat;
		}
		return null;
	}
	
	/*
	PlayerStat<float> GetStatHeatIsolation()
	{
		if( GetPlayerStats() ) 
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.HEATISOLATION));
			return stat;
		}
		return null;
	}
	*/
	
	PlayerStat<float> GetStatTremor()
	{
		if( GetPlayerStats() ) 
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.TREMOR));
			return stat;
		}
		return null;
	}
	
	PlayerStat<int> GetStatWet()
	{
		if( GetPlayerStats() ) 
		{
			PlayerStat<int> stat = PlayerStat<int>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.WET));
			return stat;
		}
		return null;
	}
	
	/*
	PlayerStat<float> GetStatStomachEnergy()
	{
		if( GetPlayerStats() )
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.STOMACH_ENERGY));
			return stat;
		}
		return null;
	}*/
	
	PlayerStat<float> GetStatDiet()
	{
		if( GetPlayerStats() )
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.DIET));
			return stat;
		}
		return null;
	}
	
	PlayerStat<float> GetStatStamina()
	{
		if( GetPlayerStats() )
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.STAMINA));
			return stat;
		}
		return null;
	}

	PlayerStat<float> GetStatSpecialty()
	{
		if( GetPlayerStats() )
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.SPECIALTY));
			return stat;
		}
		return null;
	}
	
	PlayerStat<int> GetStatBloodType()
	{
		if( GetPlayerStats() )
		{
			PlayerStat<int> stat = PlayerStat<int>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.BLOODTYPE));
			return stat;
		}
		return null;
	}
	
	PlayerStat<float> GetStatHeatBuffer()
	{
		if( GetPlayerStats() )
		{
			PlayerStat<float> stat = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStats_current.HEATBUFFER));
			return stat;
		}
		return null;
	}
	
	void ToggleHeatBufferVisibility( bool show )
	{
		m_HasHeatBuffer = show;
		SetSynchDirty();
	}
	
	//! UA Last Message
	string GetLastUAMessage()
	{
		return m_UALastMessage;
	}

	void SetLastUAMessage(string pMsg)
	{
		m_UALastMessage = pMsg;

		if( m_UALastMessageTimer.IsRunning() )
		{
			m_UALastMessageTimer.Stop();
		}
		
		m_UALastMessageTimer.Run(PlayerConstants.LAST_UA_MSG_LIFETIME, this, "ClearLastUAMessage", null);
	}

	protected void ClearLastUAMessage()
	{
		if( m_UALastMessageTimer.IsRunning() )
		{
			m_UALastMessageTimer.Stop();
		}
		
		m_UALastMessage = "";
	}

	//! -------------------------------------------------------------------------
	//! Injured stat
	
	//! update injured state immediately
	void ForceUpdateInjuredState()
	{
		m_InjuryHandler.CheckValue(true);
	}
	
	// -------------------------------------------------------------------------
	void GetDebugActions(out TSelectableActionInfoArray outputList)
	{
		PluginTransmissionAgents plugin_trans_agents = PluginTransmissionAgents.Cast( GetPlugin(PluginTransmissionAgents) );
		
		string name;
		int id;
		map<int,string> agent_list = plugin_trans_agents.GetSimpleAgentList();
		
		for(int i = 0; i < agent_list.Count(); i++)
		{
			name = agent_list.GetElement(i);
			id = agent_list.GetKey(i);
			
			outputList.Insert(new TSelectableActionInfo(SAT_DEBUG_ACTION,EActions.DEBUG_AGENTS_RANGE_INJECT_START + id, "Inject " + name));
			outputList.Insert(new TSelectableActionInfo(SAT_DEBUG_ACTION,EActions.DEBUG_AGENTS_RANGE_REMOVE_START + id, "Remove " + name));
		}
	}		

	//-------------------------------------------------------------
	//!
	//! SyncJunctures
	//! 

	override void OnSyncJuncture(int pJunctureID, ParamsReadContext pCtx)
	{
		super.OnSyncJuncture(pJunctureID, pCtx);
			
		switch( pJunctureID )
		{
			case DayZPlayerSyncJunctures.SJ_INJURY:
				eInjuryHandlerLevels level;
				bool enable;
				DayZPlayerSyncJunctures.ReadInjuryParams(pCtx, enable, level);
				m_InjuryHandler.SetInjuryCommandParams(enable, level);
				break;
			case DayZPlayerSyncJunctures.SJ_PLAYER_STATES:
				GetSymptomManager().SetAnimation(pCtx);
				break;
			case DayZPlayerSyncJunctures.SJ_QUICKBAR_SET_SHORTCUT:		
				OnQuickbarSetEntityRequest(pCtx);
				break;
			case DayZPlayerSyncJunctures.SJ_INVENTORY:
				GetInventory().OnInventoryJunctureFromServer(pCtx);
				break;
			case DayZPlayerSyncJunctures.SJ_INVENTORY_REPAIR:
				GetInventory().OnInventoryJunctureRepairFromServer(pCtx);
				break;
			case DayZPlayerSyncJunctures.SJ_ACTION_INTERRUPT:
			case DayZPlayerSyncJunctures.SJ_ACTION_ACK_ACCEPT:
			case DayZPlayerSyncJunctures.SJ_ACTION_ACK_REJECT:
				m_ActionManager.OnSyncJuncture(pJunctureID,pCtx);
				break;
			case DayZPlayerSyncJunctures.SJ_WEAPON_ACTION_ACK_ACCEPT:
			case DayZPlayerSyncJunctures.SJ_WEAPON_ACTION_ACK_REJECT:
			case DayZPlayerSyncJunctures.SJ_WEAPON_SET_JAMMING_CHANCE:
				m_WeaponManager.OnSyncJuncture(pJunctureID,pCtx);
				break;
			case DayZPlayerSyncJunctures.SJ_UNCONSCIOUSNESS:
				DayZPlayerSyncJunctures.ReadPlayerUnconsciousnessParams(pCtx, m_ShouldBeUnconscious);
				break;
			case DayZPlayerSyncJunctures.SJ_PLAYER_ADD_MODIFIER:
				GetSymptomManager().SetAnimation(pCtx);
				break;
			case DayZPlayerSyncJunctures.SJ_KURU_REQUEST:
				float amount;
				if(DayZPlayerSyncJunctures.ReadKuruRequest(pCtx, amount))
				{
					if(GetAimingModel() && IsFireWeaponRaised()) 
					{
						GetAimingModel().RequestKuruShake(amount);
					}
				}
				break;
/*			case DayZPlayerSyncJunctures.SJ_ACTION_TARGET_START:
			case DayZPlayerSyncJunctures.SJ_ACTION_TARGET_END:
				OnBeActionTargetJuncture(pJunctureID,pCtx);
				break;*/
			case DayZPlayerSyncJunctures.SJ_GESTURE_REQUEST :
				m_EmoteManager.OnSyncJuncture(pJunctureID, pCtx);
				break;
			case DayZPlayerSyncJunctures.SJ_WEAPON_LIFT :
				SetLiftWeapon(pJunctureID, pCtx);
				break;
			
			case DayZPlayerSyncJunctures.SJ_DELETE_ITEM :

				SetToDelete(pCtx);
				break;	
			case DayZPlayerSyncJunctures.SJ_BROKEN_LEGS :
				DayZPlayerSyncJunctures.ReadBrokenLegsParams(pCtx, m_CanPlayBrokenLegSound, m_BrokenLegState, m_LocalBrokenState);
				BreakLegSound();
				DropHeavyItem();
			break;
			case DayZPlayerSyncJunctures.SJ_SHOCK :
				DayZPlayerSyncJunctures.ReadShockParams(pCtx, m_CurrentShock);
			break;
			case DayZPlayerSyncJunctures.SJ_STAMINA:
				m_StaminaHandler.OnSyncJuncture(pJunctureID, pCtx);
			break;
			case DayZPlayerSyncJunctures.SJ_STAMINA_MISC:
				m_StaminaHandler.OnSyncJuncture(pJunctureID, pCtx);
			break;
		}
	}
	
	bool IsItemsToDelete()
	{
		return m_ItemsToDelete.Count()>0;
	}
	
	void SetToDelete(ParamsReadContext pCtx)
	{
		EntityAI item; 
		pCtx.Read(item);
		AddItemToDelete(item);
	}
	
	override void AddItemToDelete( EntityAI item )
	{
		item.SetPrepareToDelete();
		m_ItemsToDelete.Insert(item);
	}
	
	bool CanDeleteItems()
	{
		if( IsEmotePlaying() || GetThrowing().IsThrowingAnimationPlaying() || GetDayZPlayerInventory().IsProcessing() || GetActionManager().GetRunningAction() )
			return false;
		
		return true;
	}
	
	override void JunctureDeleteItem(EntityAI item)
	{
		DayZPlayerSyncJunctures.SendDeleteItem( this, item );
	} 
	
	void UpdateDelete()
	{
		if (m_ItemsToDelete.Count() > 0)
		{
			if(CanDeleteItems())
			{
				if(GetGame().IsClient() && GetGame().IsMultiplayer())
				{
					for(int i = m_ItemsToDelete.Count() - 1; i >= 0 ; i--)
					{
						if(m_ItemsToDelete.Get(i) == NULL)
						{
							
							m_ItemsToDelete.Remove(i);
						}
					}
				}
				else
				{
					for(int j = m_ItemsToDelete.Count() - 1; j >= 0 ; j--)
					{
						EntityAI item_to_delete = m_ItemsToDelete.Get(j);
						if( item_to_delete == NULL)
						{
							m_ItemsToDelete.Remove(j);
						}
						else
						{
							item_to_delete.Delete();
							m_ItemsToDelete.Remove(j);
						}
					}
				}
			
			
			}
		}
	}
	
	
/*	void OnBeActionTargetJuncture(int pJunctureID, ParamsReadContext pCtx)
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			int action;
			PlayerBase player;
			
			switch ( pJunctureID )
			{
				case DayZPlayerSyncJunctures.SJ_ACTION_TARGET_START:
					pCtx.Read(action);
					pCtx.Read(player);
					break;
				case DayZPlayerSyncJunctures.SJ_ACTION_TARGET_END:
					pCtx.Read(action);
					pCtx.Read(player);
					break;
			}
		}
	
	}
	*/
	override bool	HeadingModel(float pDt, SDayZPlayerHeadingModel pModel)
	{
		//! during fullbody gestures - disables character turning
		if ( GetEmoteManager().IsControllsLocked() || (GetActionManager() && GetActionManager().GetRunningAction() && GetActionManager().GetRunningAction().IsFullBody(this)) )
		{
			m_fLastHeadingDiff = 0;
			//return DayZPlayerImplementHeading.RotateOrient(pDt, pModel, m_fLastHeadingDiff);
			return DayZPlayerImplementHeading.ClampHeading(pDt, pModel, m_fLastHeadingDiff);
			//return DayZPlayerImplementHeading.NoHeading(pDt, pModel, m_fLastHeadingDiff);
			//return false;
		}
		
		return super.HeadingModel(pDt, pModel);
	}
	
	override bool IsInventorySoftLocked()
	{
		return m_InventorySoftLocked;
	}
	
	override void SetInventorySoftLock(bool status)
	{
		 m_InventorySoftLocked = status;
	}
	
	void SetLoadedQuickBarItemBind(EntityAI entity, int index)
	{
		if( m_aQuickBarLoad )
			m_aQuickBarLoad.Insert(new Param2<EntityAI, int>(entity,index));
	}
	
	override bool IsLiftWeapon()
	{
		return m_LiftWeapon_player;
	}
	
	//Server
	bool ReadLiftWeaponRequest(int userDataType, ParamsReadContext ctx)
	{
		bool state;
		ctx.Read(state);
		
		ScriptJunctureData pCtx = new ScriptJunctureData;
		pCtx.Write(state);
		
		SendSyncJuncture(DayZPlayerSyncJunctures.SJ_WEAPON_LIFT, pCtx);
		
		return true;
	}
	
	void SetLiftWeapon(int pJunctureID, ParamsReadContext ctx)
	{
		bool state;
		ctx.Read(state);
		
		m_ProcessLiftWeaponState = state;
		m_ProcessLiftWeapon = true;
		
		//Print("SetLiftWeapon | STS: " + GetSimulationTimeStamp());
	}
	
	//! Client-side only
	void SendLiftWeaponSync(bool state)
	{
		HumanCommandWeapons	hcw;
		//SP version
		if (!GetGame().IsMultiplayer())
		{
			m_LiftWeapon_player = state;
		
			hcw = GetCommandModifier_Weapons();
			if( hcw )
				hcw.LiftWeapon(state);
			
			return;
		}
		
		ScriptInputUserData ctx = new ScriptInputUserData;
		
		if (GetGame().IsMultiplayer() && GetGame().IsClient() && !ctx.CanStoreInputUserData())
		{
			//Print("ctx unavailable");
			return;
		}
		else if (GetGame().IsMultiplayer() && GetGame().IsClient() && ctx.CanStoreInputUserData())
		{
			//Print("sending ECB cancel request");
			ctx.Write(INPUT_UDT_WEAPON_LIFT_EVENT);
			ctx.Write(state);
			ctx.Send();
		}
	}
	
	override void CheckLiftWeapon()
	{
		// lift weapon check
		if ( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT /*GetGame().IsClient()*/)
		{
			Weapon_Base weap;
			if ( Weapon_Base.CastTo(weap, GetItemInHands()) )
			{
				bool limited = weap.LiftWeaponCheck(this);
				if (limited && !m_LiftWeapon_player)
					SendLiftWeaponSync(true);
				else if (!limited && m_LiftWeapon_player)
					SendLiftWeaponSync(false);
			}
			else if (m_LiftWeapon_player)
			{
				SendLiftWeaponSync(false);
			}
		}
	}
	
	override void ProcessLiftWeapon()
	{
		if (m_ProcessLiftWeapon)
		{
			HumanCommandWeapons	hcw = GetCommandModifier_Weapons();
			if( hcw )
				hcw.LiftWeapon(m_ProcessLiftWeaponState);
			m_LiftWeapon_player = m_ProcessLiftWeaponState;
			m_ProcessLiftWeapon = false;
			
			//Debug.Log("SimulationStamp_server: " + this.GetSimulationTimeStamp());
		}
	}
	
	override void HideClothing(ItemOptics optic, bool state)
	{
		super.HideClothing(optic, state);
		array<int> clothingArray = new array<int>;
		Clothing clothes;
		
		if (state && DayZPlayerCameraOptics.Cast(m_CurrentCamera))
		{
			if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT)
			{
				clothingArray.Insert(InventorySlots.BACK);
				clothingArray.Insert(InventorySlots.SHOULDER);
				clothingArray.Insert(InventorySlots.MELEE);
				if(optic.GetCurrentStepFOV() < GameConstants.DZPLAYER_CAMERA_FOV_IRONSIGHTS/*0.5*/ )
				{
					clothingArray.Insert(InventorySlots.BODY);
					clothingArray.Insert(InventorySlots.VEST);
				}
				
				SetInvisibleRecursive(true,this,clothingArray);
			}
		}
		//showing should be instant (called directly, not via CallLater)
		else
		{
			if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT)
			{
				/*for(int i = 0; i < GetInventory().AttachmentCount(); i++)
				{
					Print("attachment slot ID: " + GetInventory().GetAttachmentSlotId(i));
					clothingArray.Insert(GetInventory().GetAttachmentSlotId(i));
				}*/
				clothingArray = {InventorySlots.BACK,InventorySlots.BODY,InventorySlots.VEST,InventorySlots.SHOULDER,InventorySlots.MELEE};
				
				SetInvisibleRecursive(false,this,clothingArray);
			}
		}
	}
	
	void RequestUnconsciousness(bool enable)
	{
		DayZPlayerSyncJunctures.SendPlayerUnconsciousness(this, enable);
	}
	
	override void SetDeathDarknessLevel(float duration, float tick_time)
	{
		//super.SetDeathDarknessLevel(duration, tick_time);
		
		float actual_tick = tick_time;
		if (GetDamageDealtEffect())
			m_DamageDealtEffect = null;

		if (GetFlashbangEffect())
			m_FlashbangEffect = null;
		
		float percentage;
		if ( duration > 0 )
			percentage = 1 - ( (duration - m_DeathDarkeningCurrentTime) / duration );
		
		m_DeathDarkeningCurrentTime += actual_tick;
		
		if (!GetDamageDealtEffect() && !IsAlive())
			PPEffects.SetDeathDarkening(percentage);
		
		if ( m_DeathDarkeningCurrentTime >= duration && m_DeathEffectTimer )
			m_DeathEffectTimer.Stop();
	}
	
	override bool IsInFBEmoteState()
	{
		if (!IsEmotePlaying())
			return false;
		if ( (m_EmoteManager.m_Callback && m_EmoteManager.m_Callback.m_IsFullbody) || m_EmoteManager.m_IsSurrendered )
		{
			return true;
		}
		return false;
	}
	
	//! ends surrender, originally intended for surrender->restrained transitioning
	void EndSurrenderRequest(SurrenderData data = null)
	{
		if (m_EmoteManager)
			m_EmoteManager.EndSurrenderRequest(data);
	}
	
	bool IsSurrendered()
	{
		if (m_EmoteManager)
			return m_EmoteManager.m_IsSurrendered;
		
		return false;
	}
	
	bool IsPlayerLoaded()
	{
		return m_PlayerLoaded;
	}
	
	//disconnected, caused problems. Awaiting refactor
	override void CheckAnimationOverrides()
	{
		//FB gesture slideposeangle override
		if (IsInFBEmoteState() && IsControlledPlayer() && IsPlayerSelected())
		{
			OverrideSlidePoseAngle(Math.PI2);
		}
		else if (!IsInFBEmoteState() && IsControlledPlayer() && IsPlayerSelected())
		{
			OverrideSlidePoseAngle(m_OriginalSlidePoseAngle);
		}
		
		//+add more, if needed
	}
	
	/*void OnSurrenderEnd()
	{
	}*/
	
	bool CanRedirectToWeaponManager (notnull EntityAI item, out bool isActionPossible)
	{
		isActionPossible = false;
		Magazine mag = Magazine.Cast(item);
		Weapon_Base wpn = Weapon_Base.Cast(item.GetHierarchyParent());
		if (mag && wpn)
		{
			if (GetWeaponManager().CanDetachMagazine(wpn, mag))
			{
				Print("[inv] PlayerBase.CanRedirectToWeaponManager OK, can detach mag=" + mag + " from wpn=" + wpn);
				isActionPossible = true;
			}
			else
			{
				Print("[inv] PlayerBase.CanRedirectToWeaponManager cannot detach mag=" + mag + " from wpn=" + wpn);
			}
			return true;
		}
		return false;
	}
	
	// Inventory actions with redirection to weapon manager
	override bool PredictiveTakeEntityToTargetInventory (notnull EntityAI target, FindInventoryLocationType flags, notnull EntityAI item)
	{
		bool can_detach;
		if (CanRedirectToWeaponManager(item,can_detach))
		{
			InventoryLocation il = new InventoryLocation();
			if (can_detach && target.GetInventory().FindFreeLocationFor(item, flags, il))
			{
				return GetWeaponManager().DetachMagazine(il);
			}
			return false;
		}
		return super.PredictiveTakeEntityToTargetInventory(target, flags, item);
	}

	override bool PredictiveTakeEntityToInventory (FindInventoryLocationType flags, notnull EntityAI item)
	{
		bool can_detach;
		if (CanRedirectToWeaponManager(item,can_detach))
		{
			InventoryLocation il = new InventoryLocation();
			if (can_detach && GetInventory().FindFreeLocationFor(item, flags, il))
			{
				return GetWeaponManager().DetachMagazine(il);
			}
			return false;
		}
		return super.PredictiveTakeEntityToInventory(flags, item);
	}
	
	override bool PredictiveTakeEntityToTargetAttachment (notnull EntityAI target, notnull EntityAI item)
	{
		Weapon_Base parentWpn = Weapon_Base.Cast(target);
		Magazine mag = Magazine.Cast(item);
		if (parentWpn && mag)
		{
			if( GetWeaponManager().CanAttachMagazine(parentWpn, mag) )
				return GetWeaponManager().AttachMagazine(mag);

			return false;
		}
		return super.PredictiveTakeEntityToTargetAttachment(target, item);
	}
	
	override bool PredictiveTakeEntityToTargetAttachmentEx (notnull EntityAI target, notnull EntityAI item, int slot)
	{
		Weapon_Base parentWpn = Weapon_Base.Cast(target);
		Magazine mag = Magazine.Cast(item);
		if (parentWpn && mag)
		{
			if( target.CanReceiveAttachment(item,slot) && GetWeaponManager().CanAttachMagazine(parentWpn, mag) )
				return GetWeaponManager().AttachMagazine(mag);

			return false;
		}
		return super.PredictiveTakeEntityToTargetAttachmentEx(target, item,slot);
	}
	
	override bool PredictiveTakeEntityToTargetCargo (notnull EntityAI target, notnull EntityAI item)
	{
		bool can_detach;
		if (CanRedirectToWeaponManager(item,can_detach))
		{
			InventoryLocation il = new InventoryLocation();
			if (can_detach && target.GetInventory().FindFreeLocationFor(item, FindInventoryLocationType.CARGO, il))
			{
				return GetWeaponManager().DetachMagazine(il);	
			}
			return false;	
		}
		return super.PredictiveTakeEntityToTargetCargo(target,item);
	}
	
	override bool PredictiveTakeEntityToTargetCargoEx (notnull CargoBase cargo, notnull EntityAI item, int row, int col)
	{
		bool can_detach;
		if (CanRedirectToWeaponManager(item, can_detach))
		{
			if (can_detach)
			{
				InventoryLocation dst = new InventoryLocation;
				dst.SetCargoAuto(cargo, item, row, col, item.GetInventory().GetFlipCargo());

				return GetWeaponManager().DetachMagazine(dst);
			}
			return false;
		}		
		return super.PredictiveTakeEntityToTargetCargoEx (cargo, item, row, col);
	}
	
	override bool PredictiveDropEntity (notnull EntityAI item)
	{
		bool can_detach;
		if (CanRedirectToWeaponManager(item,can_detach))
		{
			if (can_detach)
			{
				vector m4[4];
				Math3D.MatrixIdentity4(m4);
				GameInventory.PrepareDropEntityPos(this, item, m4);
				InventoryLocation il = new InventoryLocation;
				il.SetGround(item, m4);
				return GetWeaponManager().DetachMagazine(il);
			}
			return false;
		}
		return super.PredictiveDropEntity(item);
	}
	
	override bool PredictiveSwapEntities (notnull EntityAI item1, notnull EntityAI item2)
	{
		ForceStandUpForHeavyItemsSwap(item1, item2);
		//Print("PlayerBase | PredictiveSwapEntities");
		Magazine swapmag1 = Magazine.Cast(item1);
		Magazine swapmag2 = Magazine.Cast(item2);

		if (swapmag1 && swapmag2)
		{
			Weapon_Base parentWpn;

			if (Class.CastTo(parentWpn, swapmag1.GetHierarchyParent()))
			{
				if (GetWeaponManager().CanSwapMagazine(parentWpn, swapmag2) )
				{
					Print("[inv] PlayerBase.PredictiveSwapEntities: swapping mag1=" + swapmag1 + " to parent wpn=" + parentWpn + " of mag1=" + swapmag1);
					return GetWeaponManager().SwapMagazine(swapmag2);
				}
				else
				{
					Print("[inv] PlayerBase.PredictiveSwapEntities: can not swap magazines");
					return false;
				}
			}

			if (Class.CastTo(parentWpn, swapmag2.GetHierarchyParent()))
			{
				if (GetWeaponManager().CanSwapMagazine(parentWpn, swapmag1) )
				{
					Print("[inv] PlayerBase.PredictiveSwapEntities: swapping mag1=" + swapmag1 + " to parent wpn=" + parentWpn + " of mag2=" + swapmag2);
					return GetWeaponManager().SwapMagazine(swapmag1);
				}
				else
				{
					Print("[inv] PlayerBase.PredictiveSwapEntities: can not swap magazines");
					return false;
				}
			}
		}
		
		EntityAI item_hands;
		EntityAI item_ground;
		if ( IsSwapBetweenHandsAndGroundLargeItem(item1,item2,item_hands,item_ground) && !m_ActionManager.GetRunningAction() )
		{
			ActionManagerClient mngr_client;
			CastTo(mngr_client,m_ActionManager);
			
			ActionTarget atrg = new ActionTarget(item_ground,null,-1,vector.Zero,-1.0);
			if ( mngr_client.GetAction(ActionSwapItemToHands).Can(this,atrg,ItemBase.Cast(item_hands)) )
			{
				mngr_client.PerformActionStart(mngr_client.GetAction(ActionSwapItemToHands),atrg,ItemBase.Cast(item_hands));
				return true;
			}
			return super.PredictiveSwapEntities( item1, item2);
		}
		else
			return super.PredictiveSwapEntities( item1, item2);
	}
	
	override bool PredictiveForceSwapEntities (notnull EntityAI item1, notnull EntityAI item2, notnull InventoryLocation item2_dst)
	{
		ForceStandUpForHeavyItemsSwap(item1, item2);

		InventoryLocation il = new InventoryLocation;	
		if ( item1.IsHeavyBehaviour() && item1.GetInventory().GetCurrentInventoryLocation(il) && il.GetType() == InventoryLocationType.GROUND && !m_ActionManager.GetRunningAction() )
		{		
			//Print("override bool PredictiveForceSwapEntities (notnull EntityAI item1, notnull EntityAI item2, notnull InventoryLocation item2_dst)");
			ActionManagerClient mngr_client;
			CastTo(mngr_client,m_ActionManager);
			
			ActionTarget atrg = new ActionTarget(item1,null,-1,vector.Zero,-1.0);
			if ( mngr_client.GetAction(ActionSwapItemToHands).Can(this,atrg,ItemBase.Cast(item2)) )
			{
				mngr_client.PerformActionStart(mngr_client.GetAction(ActionSwapItemToHands),atrg,ItemBase.Cast(item2));
			}
			return true;
		}
		else
			return super.PredictiveForceSwapEntities( item1, item2, item2_dst );
	}
	
	override void PredictiveTakeEntityToHands(EntityAI item)
	{
		if ( item.IsHeavyBehaviour() && !m_ActionManager.GetRunningAction() && !item.GetHierarchyParent() )
		{
			ActionManagerClient mngr_client;
			if (CastTo(mngr_client,m_ActionManager))
			{
				ActionTarget atrg = new ActionTarget(item,null,-1,vector.Zero,-1.0);
				
				if ( mngr_client.GetAction(ActionTakeItemToHands).Can(this,atrg,null) )
				{
					mngr_client.PerformActionStart(mngr_client.GetAction(ActionTakeItemToHands),atrg,null);
				}
				/*).Can(this,
				mngr_client.ActionStart(mngr_client.GetAction(ActionTakeItemToHands),mngr_client.FindActionTarget(),null);
				return;*/
			}
		}
		else
			super.PredictiveTakeEntityToHands(item);
	}

	override bool PredictiveTakeToDst (notnull InventoryLocation src, notnull InventoryLocation dst)
	{
		EntityAI item = src.GetItem();
		if(item)
		{
			bool can_detach;
		
			if (CanRedirectToWeaponManager(item,can_detach))
			{
				if (can_detach)
				{
					return GetWeaponManager().DetachMagazine(dst);	
				}
				return false;	
			}
			return super.PredictiveTakeToDst(src,dst);
		}
		return false;
	}
	
	bool IsSwapBetweenHandsAndGroundLargeItem(notnull EntityAI item1, notnull EntityAI item2, out EntityAI item_hands, out EntityAI item_ground)
	{
		InventoryLocation il = new InventoryLocation;
		if (item1.GetInventory().GetCurrentInventoryLocation(il) && il.GetType() == InventoryLocationType.HANDS)
			item_hands = item1;
		if (item2.GetInventory().GetCurrentInventoryLocation(il) && il.GetType() == InventoryLocationType.HANDS)
			item_hands = item2;
		if (item1.GetInventory().GetCurrentInventoryLocation(il) && il.GetType() == InventoryLocationType.GROUND)
			item_ground = item1;
		if (item2.GetInventory().GetCurrentInventoryLocation(il) && il.GetType() == InventoryLocationType.GROUND)
			item_ground = item2;
		
		return item_hands && item_ground && item_ground.IsHeavyBehaviour();
	}
	
	//! Dynamic hair hiding
	void SetHairLevelToHide(int level, bool state, bool was_debug = false)
	{
		if (was_debug && GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_CLIENT)
			return;
		
		if (!m_CharactersHead)
		{
			Print("No valid head detected on character!");
			return;
		}

#ifdef DEVELOPER
		PluginDiagMenu diagmenu = PluginDiagMenu.Cast(GetPlugin(PluginDiagMenu));
#endif
		if (level == -1) //hide/show ALL
		{
			m_HideHairAnimated = !m_HideHairAnimated;
			for (int i = 0; i < m_CharactersHead.m_HeadHairSelectionArray.Count(); i++)
			{
				//m_CharactersHead.SetSimpleHiddenSelectionState(i,m_HideHairAnimated);
				SelectionTranslation stt = SelectionTranslation.Cast(m_CharactersHead.m_HeadHairHidingStateMap.Get(i));
				stt.SetSelectionState(m_HideHairAnimated);
				m_CharactersHead.m_HeadHairHidingStateMap.Set(i,stt);
#ifdef DEVELOPER
				diagmenu.m_HairHidingStateMap.Set(i,m_HideHairAnimated);
#endif
			}
			return;
		}
		else //hide/show selected level only
		{
			bool switchState;
			if (was_debug)
			{
#ifdef DEVELOPER
				switchState = !diagmenu.m_HairHidingStateMap.Get(level);
				diagmenu.m_HairHidingStateMap.Set(level,switchState);
#endif
			}
			else
			{
				switchState = !state;
			}
			//m_CharactersHead.SetSimpleHiddenSelectionState(level,switchState);
			stt = SelectionTranslation.Cast(m_CharactersHead.m_HeadHairHidingStateMap.Get(level));
			stt.SetSelectionState(switchState);
			m_CharactersHead.m_HeadHairHidingStateMap.Set(level,stt); //nescessary?
		}
	}
	
	void HideHairSelections(ItemBase item, bool state)
	{
		if ( !item || !item.GetHeadHidingSelection() || !m_CharactersHead)
			return;
		
		string str
		int idx;
		
		for (int i = 0; i < item.GetHeadHidingSelection().Count(); i++)
		{
			str = item.GetHeadHidingSelection().Get(i);
			idx = m_CharactersHead.m_HeadHairSelectionArray.Find(str);//selection_array.Find(str);
			SetHairLevelToHide(idx,state);
		}
		UpdateHairSelectionVisibility();
	}
	
	void UpdateHairSelectionVisibility(bool was_debug = false)
	{
		if (!m_CharactersHead)
			return;
		bool shown;
		bool exception_hidden = false;
		int i;
		SelectionTranslation stt;
		
		//hide/show beard
		if ( IsMale() && m_CharactersHead.GetBeardIndex() > -1 && !was_debug )
		{
			SetHairLevelToHide(m_CharactersHead.GetBeardIndex(),GetLifeSpanState() != LifeSpanState.BEARD_EXTRA);
		}
		
		//show all first
		for (i = 0; i < m_CharactersHead.m_HeadHairHidingStateMap.Count(); i++)
		{
			m_CharactersHead.SetSimpleHiddenSelectionState(i,true);
		}
		//then carve it up
		for (i = 0; i < m_CharactersHead.m_HeadHairHidingStateMap.Count(); i++)
		{
			stt = m_CharactersHead.m_HeadHairHidingStateMap.Get(i);
			shown = stt.GetSelectionState();
			if (!shown)
			{
				if ( /*IsMale() && */!m_CharactersHead.IsHandlingException() )
				{
					m_CharactersHead.SetSimpleHiddenSelectionState(i,shown);
					UpdateTranslatedSelections(stt);
					//Print("hidden idx: " + i);
				}
				else
				{
					exception_hidden = true;
				}
			}
		}
		
		//exceptions handled differently; hides hair
		if ( exception_hidden )
		{
			m_CharactersHead.SetSimpleHiddenSelectionState(m_CharactersHead.GetHairIndex(),false);
			if ( IsMale() )
				m_CharactersHead.SetSimpleHiddenSelectionState(m_CharactersHead.GetBeardIndex(),false);
		}
	}
	
	void UpdateTranslatedSelections(SelectionTranslation stt)
	{
		int index;
		array<int> translatedSelectinosArray = stt.GetTranslatedSelections();
		for (int i = 0; i < translatedSelectinosArray.Count(); i++)
		{
			index = translatedSelectinosArray.Get(i);
			//if (index > -1)
				m_CharactersHead.SetSimpleHiddenSelectionState(index,false); //safe this way, only hiding/carving from shown parts
		}
	}
	
	//! helper method for re-checking hairhiding on character load
	void CheckHairClippingOnCharacterLoad()
	{
		ItemBase headgear = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.HEADGEAR));
		ItemBase mask = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.MASK));
		
		HideHairSelections(headgear,true);
		HideHairSelections(mask,true);
	}
	
	bool IsNVGWorking()
	{
		return m_WorkingNVGHeadset;
	}
	
	bool IsNVGLowered()
	{
		return m_LoweredNVGHeadset;
	}
	
	void SetNVGWorking(bool state)
	{
		m_WorkingNVGHeadset = state;
		if (state)
		{
			//Print("NVG working by player: " + state);
		}
	}
	
	void SetNVGLowered(bool state)
	{
		m_LoweredNVGHeadset = state;
	}
#ifdef DEVELOPER
	void DEBUGRotateNVG()
	{
		NVGoggles nvg;
		
		if ( FindAttachmentBySlotName("Eyewear") )
		{
			nvg = NVGoggles.Cast(FindAttachmentBySlotName("Eyewear").FindAttachmentBySlotName("NVG"));
		}
		else if ( FindAttachmentBySlotName("Headgear") )
		{
			nvg = NVGoggles.Cast(FindAttachmentBySlotName("Headgear").FindAttachmentBySlotName("NVG"));
		}
		
		if ( nvg )
		{
			nvg.RotateGoggles(nvg.m_IsLowered);
		}
	}
#endif
	
	void AdjustBandana(EntityAI item, string slot_name)
	{
		if (Bandana_ColorBase.Cast(item))
		{
			if (slot_name == "Headgear")
			{
				item.SetSimpleHiddenSelectionState(0,1);
				item.SetSimpleHiddenSelectionState(1,0);
			}
			else if (slot_name == "Mask")
			{
				item.SetSimpleHiddenSelectionState(0,0);
				item.SetSimpleHiddenSelectionState(1,1);
			}
		}
	}
	
	//client-side
	void UpdateCorpseStateVisual()
	{
		//Print("---Prettying up corpses... | " + GetGame().GetTime() + " | " + this + " | " + GetType() + "---");
		//Print("m_DecayedTexture = " + m_DecayedTexture);
		
		if( m_CorpseState == PlayerConstants.CORPSE_STATE_DECAYED )
		{
			EntityAI bodypart;
			ItemBase item;
			
			string path;
			int idx;
			int slot_id;
			array<string> bodyparts = {"Gloves","Body","Legs","Feet"};
			
			for (int i = 0; i < bodyparts.Count(); i++)
			{
				slot_id = InventorySlots.GetSlotIdFromString(bodyparts.Get(i));
				bodypart = GetInventory().FindPlaceholderForSlot( slot_id );
				item = ItemBase.Cast(GetInventory().FindAttachment( slot_id ));
				
				if( bodypart )
				{
					path = "cfgVehicles " + bodypart.GetType();
					idx = bodypart.GetHiddenSelectionIndex("personality");
					if( idx > -1 )
					{
						bodypart.SetObjectTexture(idx,m_DecayedTexture);
					}
				}
				if( item )
				{
					path = "cfgVehicles " + item.GetType();
					idx = item.GetHiddenSelectionIndex("personality");
					if( idx > -1 )
					{
						item.SetObjectTexture(idx,m_DecayedTexture);
					}
				}
			}
			
			SetFaceTexture(m_DecayedTexture);
		}

		SetDecayEffects(m_CorpseState);
	}
	
	void SetDecayEffects(int effect = -1)
	{
		int boneIdx = GetBoneIndexByName("Spine2");
		Particle p;
		
		switch (effect)
		{
			case PlayerConstants.CORPSE_STATE_MEDIUM :
				//play medium sound/flies particle
				if (!m_FliesEff)
					m_FliesEff = new EffSwarmingFlies();
				
				if ( m_FliesEff && !SEffectManager.IsEffectExist(m_FliesIndex) )
				{
					m_FliesEff.SetDecalOwner( this );
					m_FliesIndex = SEffectManager.PlayOnObject(m_FliesEff, this, "0 0.25 0");
					p = m_FliesEff.GetParticle();
					AddChild(p, boneIdx);
					if ( !m_SoundFliesEffect )
					{
						//m_SoundFliesEffect = SEffectManager.PlaySoundOnObject("Flies_SoundSet",this,0,0,true);
						PlaySoundSetLoop(m_SoundFliesEffect, "Flies_SoundSet", 1.0, 1.0);
					}
				}
			break;
			case PlayerConstants.CORPSE_STATE_DECAYED :
				//play serious sound/flies particle
				if ( !m_FliesEff )
					m_FliesEff = new EffSwarmingFlies();
				
				if ( m_FliesEff && !SEffectManager.IsEffectExist(m_FliesIndex) )
				{
					m_FliesEff.SetDecalOwner( this );
					m_FliesIndex = SEffectManager.PlayOnObject(m_FliesEff, this, "0 0.25 0");
					p = m_FliesEff.GetParticle();
					AddChild(p, boneIdx);
					if ( !m_SoundFliesEffect )
					{
						//m_SoundFliesEffect = SEffectManager.PlaySoundOnObject("Flies_SoundSet",this,0,0,true);
						PlaySoundSetLoop(m_SoundFliesEffect, "Flies_SoundSet", 1.0, 1.0);
					}
				}
			break;
			
			default:
				if ( m_FliesEff )
				{
					m_FliesEff.Stop();
					if (SEffectManager.IsEffectExist(m_FliesIndex))
					{
						SEffectManager.Stop(m_FliesIndex);
					}
				}
				if ( m_SoundFliesEffect )
				{
					StopSoundSet(m_SoundFliesEffect);
					//SEffectManager.DestroySound(m_SoundFliesEffect);
					//m_SoundFliesEffect = null;
				}
		}
	}
	
	void PreloadDecayTexture()
	{
		int idx;
		int slot_id;
		
		idx = this.GetHiddenSelectionIndex("decay_preload");
		if (idx > -1)
		{
			this.SetObjectTexture(idx,m_DecayedTexture);
			//Print("'decay_preload' loaded on " + this);
		}
		else
		{
			//Print("No 'decay_preload' selection found on " + this);
		}
	}
	
	void SetLastMapInfo(float scale, vector pos)
	{
		m_LastMapScale = scale;
		m_LastMapPos = pos;
	}
	
	bool GetLastMapInfo(out float scale, out vector pos)
	{
		scale = m_LastMapScale;
		pos = m_LastMapPos;
		
		return m_LastMapScale != -1.0;
	}
	
	override bool PhysicalPredictiveDropItem(EntityAI entity, bool heavy_item_only = true)
	{
		vector dir;
		ItemBase item = ItemBase.Cast(entity);
		
		if (GetItemInHands() == item) //from hands
		{
			//HOTFIX
			return PredictiveDropEntity(item);
			
			if (entity.ConfigGetString("physLayer") != "item_large" && heavy_item_only)
			{
				return PredictiveDropEntity(item);
			}
			else
			{
				dir = GetOrientation();
				//item.m_ItemBeingDropped = true;
				return GetHumanInventory().ThrowEntity(item,dir,0);
			}
		}
		else //from anywhere else
		{
			ActionManagerClient mngr_client;
			if (CastTo(mngr_client,m_ActionManager))
			{
				ActionTarget atrg = new ActionTarget(null, null, -1, vector.Zero, -1);
				if ( mngr_client.GetAction(ActionDropItemSimple).Can(this,atrg,item) )
				{
					//Param1<bool> p1 = new Param1<bool>(false);
					//p1.param1 = heavy_item_only;
					mngr_client.PerformActionStart(mngr_client.GetAction(ActionDropItemSimple),atrg,item/*,p1*/);
					return true;
				}
				return false;
			}
			else
				return true;
		}
	}
	
	override void SetProcessUIWarning(bool state)
	{
		m_ProcessUIWarning = state;
	}
	
	void dmgDebugPrint(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		/*Print("ProjectileDebugging | Damage Health: " + damageResult.GetDamage(dmgZone,"Health") + " | Component: " + component + " | Zone: " + dmgZone + "| Timestamp: " + GetSimulationTimeStamp());
		Print("ProjectileDebugging | speedCoef: " + speedCoef);
		Print("ProjectileDebugging | GetWorldTime(): " + GetWorldTime());
		Print("-----------------------------------------------");*/
	}
	
	//Use this method to process additionnal dmg to legs specifically (must use the dmg system to fire relevant events)
	//Legzone is a dummy to inflict damage once and NOT transfer damage to other zones. All leg zones will drop to 0 anyway
	void DamageAllLegs(float inputDmg)
	{
		array<string> legZones = new array<string>;
		legZones.Insert("LeftLeg");
		legZones.Insert("RightLeg");
		legZones.Insert("RightFoot");
		legZones.Insert("LeftFoot");
		
		for (int i = 0; i < legZones.Count(); i++)
		{
			this.DecreaseHealth(legZones[i],"",inputDmg);
		}
	}
	
	
	//! tries to hide item in player's hands, some exceptions for various movement states
	void TryHideItemInHands(bool hide, bool force = false)
	{
		if ( !hide && ((!IsSwimming() && !IsClimbingLadder() && !IsInVehicle() && !AnimCommandCheck(HumanMoveCommandID.CommandSwim | HumanMoveCommandID.CommandLadder | HumanMoveCommandID.CommandVehicle)) || force) )
		{
			GetItemAccessor().HideItemInHands(false);
		}
		else
		{
			GetItemAccessor().HideItemInHands(true);
		}
	}
	
	//!
	bool CheckAndExecuteStackSplit(FindInventoryLocationType flags, notnull EntityAI item, notnull EntityAI target)
	{
		float stackable = item.GetTargetQuantityMax();
		if ( !(stackable == 0 || stackable >= item.GetQuantity()) )
		{
			InventoryLocation il = new InventoryLocation;
			if ( target && target.GetInventory().FindFreeLocationFor( item, flags, il ) )
			{
				ItemBase itemB;
				if ( CastTo(itemB, item) )
				{
					itemB.SplitIntoStackMaxToInventoryLocationClient( il );
					return true;
				}
			}
		}
		return false;
	}
	
	bool CheckAndExecuteStackSplitToInventoryLocation(InventoryLocation il, notnull EntityAI item)
	{
		float stackable = item.GetTargetQuantityMax();
		if ( !(stackable == 0 || stackable >= item.GetQuantity()) )
		{
			ItemBase itemB;
			if ( CastTo(itemB, item) )
			{
				itemB.SplitIntoStackMaxToInventoryLocationClient( il );
				return true;
			}
		}
		return false;
	}
	
	override protected bool TakeEntityToInventoryImpl(InventoryMode mode, FindInventoryLocationType flags, notnull EntityAI item)
	{
		if ( CheckAndExecuteStackSplit(flags, item, this) )
		{
			syncDebugPrint("[inv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " Take2Inv(SPLIT) item=" + GetDebugName(item));
			return true;
		}
		
		return super.TakeEntityToInventoryImpl(mode, flags, item);
	}
	
	override protected bool TakeEntityToCargoImpl(InventoryMode mode, notnull EntityAI item)
	{
		if ( CheckAndExecuteStackSplit(FindInventoryLocationType.CARGO, item, this) )
		{
			syncDebugPrint("[inv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " Take2Cgo(SPLIT) item=" +GetDebugName(item));
			return true;
		}
		
		return super.TakeEntityToCargoImpl(mode, item);
	}
	
	override protected bool TakeEntityAsAttachmentImpl(InventoryMode mode, notnull EntityAI item)
	{
		if ( CheckAndExecuteStackSplit(FindInventoryLocationType.ATTACHMENT, item, this) )
		{
			syncDebugPrint("[inv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " Take2Att(SPLIT) item=" + GetDebugName(item));
			return true;
		}
		
		return super.TakeEntityAsAttachmentImpl(mode, item);
	}
	
	override void TakeEntityToHandsImpl(InventoryMode mode, EntityAI item)
	{
		if ( CheckAndExecuteStackSplit(FindInventoryLocationType.HANDS, item, this) )
		{
			syncDebugPrint("[inv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " Take2Hands(SPLIT) item=" + GetDebugName(item));
			return;
		}
		
		super.TakeEntityToHandsImpl(mode, item);
	}
	
	override protected bool TakeEntityToTargetInventoryImpl(InventoryMode mode, notnull EntityAI target, FindInventoryLocationType flags, notnull EntityAI item)
	{
		if ( CheckAndExecuteStackSplit(flags, item, target) )
		{
			syncDebugPrint("[inv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " Take2TargetInv(SPLIT) item=" + GetDebugName(item));
			return true;
		}
		
		return super.TakeEntityToTargetInventoryImpl(mode, target, flags, item);
	}
	
	override protected bool TakeEntityToTargetCargoImpl(InventoryMode mode, notnull EntityAI target, notnull EntityAI item)
	{
		if ( CheckAndExecuteStackSplit(FindInventoryLocationType.CARGO, item, target) )
		{
			syncDebugPrint("[inv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " Take2TargetCgo(SPLIT) item=" + GetDebugName(item));
			return true;
		}
		
		return super.TakeEntityToTargetCargoImpl(mode, target, item);
	}
	
	override protected bool TakeEntityToTargetAttachmentImpl(InventoryMode mode, notnull EntityAI target, notnull EntityAI item)
	{
		if ( CheckAndExecuteStackSplit(FindInventoryLocationType.ATTACHMENT, item, target) )
		{
			syncDebugPrint("[inv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " Take2TargetAtt(SPLIT) item=" + GetDebugName(item));
			return true;
		}
		
		return super.TakeEntityToTargetAttachmentImpl(mode, target, item);
	}
	
	override protected bool TakeToDstImpl(InventoryMode mode, notnull InventoryLocation src, notnull InventoryLocation dst)
	{
		if ( CheckAndExecuteStackSplitToInventoryLocation(dst, dst.GetItem()) )
		{
			syncDebugPrint("[inv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " Take2Dst(SPLIT) item=" + GetDebugName(dst.GetItem()));
			return true;
		}
		
		return super.TakeToDstImpl(mode, src, dst);
	}
	
	override vector GetCenter()
	{
		return GetBonePositionWS( GetBoneIndexByName( "spine3" ) );
	}
}