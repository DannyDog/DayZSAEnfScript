enum FireplaceFireState
{
	NO_FIRE				= 1,
	START_FIRE			= 2,
	SMALL_FIRE			= 3,	
	NORMAL_FIRE			= 4,
	END_FIRE			= 5,
	EXTINGUISHING_FIRE	= 6,
	EXTINGUISHED_FIRE	= 7,
	REIGNITED_FIRE		= 8,
	
	COUNT				= 9			//for net sync purposes
}

class FireplaceBase extends ItemBase
{
	//State params
	protected bool m_IsBurning 	= false;   
	protected bool m_HasAshes	= false;
	protected bool m_IsOven		= false;
	protected FireplaceFireState m_FireState	 = FireplaceFireState.NO_FIRE;
	protected FireplaceFireState m_LastFireState = FireplaceFireState.NO_FIRE;		//for synchronization purposes
	
	//Fireplace params
	protected float m_TemperatureLossMP		= 1.0;		//! determines how fast will the fireplace loose its temperature when cooling (lower is better)
	protected float m_FuelBurnRateMP		= 1.0;		//! determines how fast will the fuel item burn before spending (lower is better)
	
	//cooking
	protected ref Cooking m_CookingProcess;
	
	//
	const float PARAM_SMALL_FIRE_TEMPERATURE 		= 150;		//! maximum fireplace temperature of a small fire (degree Celsius)
	const float PARAM_NORMAL_FIRE_TEMPERATURE 		= 1000;		//! maximum fireplace temperature of a normal fire (degree Celsius)
	const float PARAM_MIN_FIRE_TEMPERATURE 			= 40;		//! minimum fireplace temperature under which the fireplace is inactive (degree Celsius)
	const float	PARAM_TEMPERATURE_INCREASE 			= 30;		//! how much will temperature increase when fireplace is burning (degree Celsius)
	const float	PARAM_TEMPERATURE_DECREASE 			= 10;		//! how much will temperature decrease when fireplace is cooling (degree Celsius)
	const float	PARAM_MAX_WET_TO_IGNITE 			= 0.2;		//! maximum wetness value when the fireplace can be ignited
	const float PARAM_MIN_TEMP_TO_REIGNITE 			= 100;		//! minimum fireplace temperature under which the fireplace can be reignited using air only (degree Celsius)
	const float	PARAM_IGNITE_RAIN_THRESHOLD 		= 0.05;		//! maximum rain value when the fireplace can be ignited
	const float	PARAM_BURN_WET_THRESHOLD 			= 0.40;		//! maximum wetness value when the fireplace is able to burn
	const float	PARAM_WET_INCREASE_COEF 			= 0.02;		//! value for calculating of  wetness that fireplace gain when raining
	const float	PARAM_WET_HEATING_DECREASE_COEF 	= 0.01;		//! value for calculating wetness loss during heating process
	const float	PARAM_WET_COOLING_DECREASE_COEF 	= 0.002;	//! value for calculating wetness loss during cooling process
	const float	PARAM_FIRE_CONSUM_RATE_AMOUNT		= 1.0;		//! base value of fire consumption rate (how many base energy will be spent on each update)
	const float	PARAM_BURN_DAMAGE_COEF				= 0.05;		//! value for calculating damage on items located in fireplace cargo
	const float	PARAM_ITEM_HEAT_TEMP_INCREASE_COEF	= 10;		//! value for calculating temperature increase on each heat update interval (degree Celsius)
	const float	PARAM_ITEM_HEAT_MIN_TEMP			= 40;		//! minimum temperature for items that can be heated in fireplace cargo or as attachments (degree Celsius)
	const float PARAM_MAX_ITEM_HEAT_TEMP_INCREASE	= 200;		//! maximum value of temperature of items in fireplace when heating (degree Celsius)
	const float PARAM_HEAT_RADIUS 					= 3.0;		//! radius in which objects are heated by fire
	const float PARAM_HEAT_THROUGH_AIR_COEF			= 0.035;	//! value for calculation of heat transfered from fireplace through air to player (environment)
	//! 
	const int 	MIN_STONES_TO_BUILD_OVEN			= 8;		//! minimum amount of stones for oven
	const int 	MAX_TEMPERATURE_TO_DISMANTLE_OVEN	= 40;		//! maximum temperature for dismantling oven
	//
	const float TEMPERATURE_LOSS_MP_DEFAULT			= 1.0;
	const float FUEL_BURN_RATE_DEFAULT				= 1.0;
	const float TEMPERATURE_LOSS_MP_STONES			= 0.83;		//20% boost
	const float FUEL_BURN_RATE_STONES				= 0.83;
	const float TEMPERATURE_LOSS_MP_OVEN			= 0.67;		//50% boost
	const float FUEL_BURN_RATE_OVEN					= 0.67;
	
	//! cooking
	const float PARAM_COOKING_TEMP_THRESHOLD		= 100;		//! temperature threshold for starting coooking process (degree Celsius)
	const float PARAM_COOKING_EQUIP_MAX_TEMP		= 250;		//! maximum temperature of attached cooking equipment (degree Celsius)
	const float PARAM_COOKING_EQUIP_TEMP_INCREASE	= 10;		//! how much will temperature increase when attached on burning fireplace (degree Celsius)
	//! 
	const int 	TIMER_HEATING_UPDATE_INTERVAL 		= 2;		//! update interval duration of heating process (seconds)
	const int 	TIMER_COOLING_UPDATE_INTERVAL 		= 2;		//! update interval duration of cooling process (seconds)
	
	//Timers
	protected ref Timer m_HeatingTimer;
	protected ref Timer m_CoolingTimer;
	
	protected FireplaceLight m_Light; // Light entity
	
	//Attachments
	protected ItemBase m_CookingEquipment;
	protected ref FireConsumable m_ItemToConsume;
	
	//Particles - default for FireplaceBase
	protected int PARTICLE_FIRE_START 			= ParticleList.CAMP_FIRE_START;
	protected int PARTICLE_OVEN_FIRE_START 		= ParticleList.CAMP_STOVE_FIRE_START;
	protected int PARTICLE_SMALL_FIRE 			= ParticleList.CAMP_SMALL_FIRE;
	protected int PARTICLE_NORMAL_FIRE			= ParticleList.CAMP_NORMAL_FIRE;
	protected int PARTICLE_OVEN_FIRE 			= ParticleList.CAMP_STOVE_FIRE;
	protected int PARTICLE_SMALL_SMOKE 			= ParticleList.CAMP_SMALL_SMOKE;
	protected int PARTICLE_NORMAL_SMOKE			= ParticleList.CAMP_NORMAL_SMOKE;
	protected int PARTICLE_FIRE_END 			= ParticleList.CAMP_FIRE_END;
	protected int PARTICLE_OVEN_FIRE_END 		= ParticleList.CAMP_STOVE_FIRE_END;
	protected int PARTICLE_STEAM_END			= ParticleList.CAMP_STEAM_2END;
	protected int PARTICLE_STEAM_EXTINGUISHING	= ParticleList.CAMP_STEAM_EXTINGUISH_START;
	//
	protected Particle m_ParticleFireStart;
	protected Particle m_ParticleSmallFire;
	protected Particle m_ParticleNormalFire;
	protected Particle m_ParticleSmallSmoke;
	protected Particle m_ParticleNormalSmoke;
	protected Particle m_ParticleFireEnd;
	protected Particle m_ParticleSteamEnd;
	protected Particle m_ParticleSteamExtinguishing;
	
	//Sounds
	const string SOUND_FIRE_HEAVY 				= "HeavyFire_SoundSet";
	const string SOUND_FIRE_LIGHT				= "LightFire_SoundSet";
	const string SOUND_FIRE_NO_FIRE				= "NoFuelFire_SoundSet";
	const string SOUND_FIRE_EXTINGUISHING		= "ExtinguishByWater_SoundSet";
	const string SOUND_FIRE_EXTINGUISHED		= "ExtinguishByWaterEnd_SoundSet";
	
	//
	protected EffectSound m_SoundFireLoop;
	protected EffectSound m_SoundFire;
	//
	
	//Fuel
	//Kindling / Fuel item types
	protected static ref map<typename, ref FireConsumableType> 	m_FireConsumableTypes;
	protected ref map<ItemBase, ref FireConsumable> 			m_FireConsumables;
	
	//Player action / status messages
	const string MESSAGE_IGNITE_IGNIT_ITEM_DAMAGED 		= "You cannot start fire. Fireplace is ruined.";
	const string MESSAGE_IGNITE_NO_KINDLING 			= "There needs to be some kindling to start a fire.";
	const string MESSAGE_IGNITE_TOO_WET 				= "The fireplace is too wet to be ignited.";
	const string MESSAGE_IGNITE_RAIN	 				= "The fire went out because of the rain.";
	const string MESSAGE_IGNITE_WIND	 				= "The fire went out because of the wind.";
	const string MESSAGE_IGNITE_IN_WATER 				= "I cannot ignite the fireplace in the water.";
	const string MESSAGE_IGNITE_UNDER_LOW_ROOF 			= "I cannot ignite the fireplace here, the is not enough room.";
	const string MESSAGE_REIGNITE_NO_KINDLING 			= "There needs to be some kindling to start a fire.";
	const string MESSAGE_REIGNITE_RAIN	 				= "Cannot reignite fireplace in rain.";
	const string MESSAGE_REIGNITE_TOO_WET 				= "The fireplace is too wet to be reignited.";
	const string MESSAGE_BURY_ASHES_FAILED_NOT_EMPTY	= "Cannot bury ashes. There are sill items in it.";
	const string MESSAGE_BURY_ASHES_FAILED_SURFACE		= "Cannot bury ashes on hard surface.";
	const string MESSAGE_BURY_ASHES_FAILED_BURNING		= "Cannot bury ashes, the fireplace is still burning.";
	const string MESSAGE_BURY_ASHES_FAILED_TOO_HOT		= "Cannot bury ashes, the fireplace is too hot.";
	const string MESSAGE_CANNOT_BUILD_OVEN				= "Cannot build oven.";
	const string MESSAGE_CANNOT_DISMANTLE_OVEN			= "Cannot dismantle oven.";
	
	//Visual animations
	const string ANIMATION_ASHES 			= "Ashes";
	const string ANIMATION_KINDLING			= "Kindling";
	const string ANIMATION_STICKS			= "Sticks";
	const string ANIMATION_WOOD 			= "Wood";
	const string ANIMATION_BURNT_WOOD 		= "BurntWood";
	const string ANIMATION_STONES 			= "Stones";
	const string ANIMATION_TRIPOD 			= "Tripod";
	const string ANIMATION_OVEN 			= "Oven";
	const string ANIMATION_INVENTORY	 	= "Inventory";
	const string ANIMATION_COOKWARE_HANDLE 	= "handleRotate";

	
	//Visual textures and materials
	const string MATERIAL_FIREPLACE_GLOW 		= "dz\\gear\\cooking\\data\\stoneground.rvmat";
	const string MATERIAL_FIREPLACE_NOGLOW 		= "dz\\gear\\cooking\\data\\stonegroundnoemit.rvmat";
	
	//Attachment types
	//Fuel
	typename ATTACHMENT_STICKS			= WoodenStick;
	typename ATTACHMENT_FIREWOOD		= Firewood;
	//Kindling
	typename ATTACHMENT_RAGS 			= Rag;
	typename ATTACHMENT_BANDAGE 		= BandageDressing;
	typename ATTACHMENT_BOOK 			= ItemBook;
	typename ATTACHMENT_BARK_OAK 		= Bark_Oak;
	typename ATTACHMENT_BARK_BIRCH 		= Bark_Birch;
	typename ATTACHMENT_PAPER 			= Paper;
	//Other
	typename ATTACHMENT_TRIPOD 			= Tripod;
	typename ATTACHMENT_STONES 			= Stone;
	typename ATTACHMENT_COOKING_POT 	= Pot;
	typename ATTACHMENT_FRYING_PAN 		= FryingPan;
	//
	const string OBJECT_CLUTTER_CUTTER 	= "ClutterCutterFireplace";
	
	//area damage
	protected ref AreaDamageBase 		m_AreaDamage;
	
	//quantity
	protected float m_TotalEnergy;
	
	//================================================================
	// INIT / STORE LOAD-SAVE
	//================================================================
	//Constructor
	protected void FireplaceBase()
	{
		//STATIC: define kindling types
		if ( !m_FireConsumableTypes )
		{
			m_FireConsumableTypes = new ref map<typename, ref FireConsumableType>;
			m_FireConsumableTypes.Insert( ATTACHMENT_RAGS, 			new FireConsumableType( ATTACHMENT_RAGS, 		14, 	true,	"Rags" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_BANDAGE, 		new FireConsumableType( ATTACHMENT_BANDAGE, 	14, 	true,	"MedicalBandage" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_BOOK, 			new FireConsumableType( ATTACHMENT_BOOK, 		36, 	true,	"Book" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_BARK_OAK, 		new FireConsumableType( ATTACHMENT_BARK_OAK, 	20, 	true,	"OakBark" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_BARK_BIRCH, 	new FireConsumableType( ATTACHMENT_BARK_BIRCH, 	14, 	true,	"BirchBark" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_PAPER, 		new FireConsumableType( ATTACHMENT_PAPER, 		10, 	true,	"Paper" ) );
			
			//define fuel types
			m_FireConsumableTypes.Insert( ATTACHMENT_STICKS, 		new FireConsumableType( ATTACHMENT_STICKS, 		40, 	false,	"WoodenStick" ) );
			m_FireConsumableTypes.Insert( ATTACHMENT_FIREWOOD, 		new FireConsumableType( ATTACHMENT_FIREWOOD, 	100, 	false,	"Firewood" ) );
		}

		//calculate total energy
		CalcAndSetTotalEnergy();
		
		//define fuel / kindling items (fire consumables)
		m_FireConsumables = new ref map<ItemBase, ref FireConsumable>;
		
		//default burning parameters
		SetTemperatureLossMP( TEMPERATURE_LOSS_MP_DEFAULT );
		SetFuelBurnRateMP( FUEL_BURN_RATE_DEFAULT );
		
		//synchronized variables
		RegisterNetSyncVariableBool( "m_IsBurning" );
		RegisterNetSyncVariableBool( "m_HasAshes" );
		RegisterNetSyncVariableBool( "m_IsOven" );
		RegisterNetSyncVariableInt( "m_FireState", FireplaceFireState.NO_FIRE, FireplaceFireState.COUNT );
		RegisterNetSyncVariableBool( "m_IsSoundSynchRemote" );
		RegisterNetSyncVariableBool( "m_IsPlaceSound" );
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		//refresh visual on init
		RefreshFireplaceVisuals();
	}	
	
	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged( old_owner, new_owner );
		
		//refresh physics after location change (with delay)
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( RefreshFireplacePhysics );
	}	
	
	override void EEDelete( EntityAI parent )
	{
		super.EEDelete( parent );
		
		SetFireState( FireplaceFireState.NO_FIRE );
	}	
		
	//on store save/load
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave(ctx);

		//Save ashes state
		ctx.Write( m_HasAshes );
		
		//Save temperature loss MP
		ctx.Write( m_TemperatureLossMP );

		//Save fuel burn rate MP
		ctx.Write( m_FuelBurnRateMP );
		
		//Save burning state
		ctx.Write( m_IsBurning );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad(ctx, version) )
			return false;

		//--- Fireplace data ---
		//Load ashes state
		if ( !ctx.Read( m_HasAshes ) )
		{
			m_HasAshes = false;			//set default
			return false;
		}
		
		//Load temperature loss MP
		if ( !ctx.Read( m_TemperatureLossMP ) )
		{
			m_TemperatureLossMP = 1.0;	//set default
			return false;
		}
		
		//Load fuel burn rate MP
		if ( !ctx.Read( m_FuelBurnRateMP ) )
		{
			m_FuelBurnRateMP = 1.0;		//set default
			return false;
		}
		
		//Load burning state, if true start fire
		if ( !ctx.Read( m_IsBurning ) )
		{
			m_IsBurning = false;		//set default
			return false;
		}
		//---
		
		return true;
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
				
		//synchronize
		Synchronize();
		
		//start fire
		if ( IsBurning() )
		{
			if ( GetGame() && GetGame().IsServer() ) 
			{
				StartFire( true );			//will be auto-synchronized when starting fire
			}
		}		
	}		
	
	//================================================================
	// SYNCHRONIZATION
	//================================================================	
	void Synchronize()
	{
		if ( GetGame() && GetGame().IsServer() )
		{
			SetSynchDirty();
			
			if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
			{
				//Refresh visuals (on server)
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( RefreshFireplaceVisuals );
			}
		}
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		//Refresh client particles and audio
		if ( HasAshes() )
		{
			SetBurntFirewood();		//set burnt wood visual
		}
		
		RefreshFireplaceVisuals();
		RefreshFireParticlesAndSounds( false );
		
		if ( IsPlaceSound() )
		{
			PlayPlaceSound();
		}
	}
	
	//================================================================
	// BASE
	//================================================================
	
	//States
	//check fireplace types
	override bool IsFireplace()
	{
		return true;
	}
	
	bool IsBaseFireplace()
	{
		return false;
	}
	
	bool IsBarrelWithHoles()
	{
		return false;
	}
	
	bool IsFireplaceIndoor()
	{
		return false;
	}
	
	//cooking equipment
	ItemBase GetCookingEquipment()
	{
		return m_CookingEquipment;
	}
	
	void SetCookingEquipment( ItemBase equipment )
	{
		m_CookingEquipment = equipment;
	}
	
	void ClearCookingEquipment()
	{
		SetCookingEquipment( NULL );
	}

	//Destroy
	void DestroyFireplace()
	{
		//delete object
		GetGame().ObjectDelete( this );
	}
	
	//================================================================
	// VISUAL
	//================================================================
	//Fireplace visual
	void RefreshFireplaceVisuals()
	{		
		if ( IsHologram() )
		{
			return;
		}
		
		// Light
		if ( IsBurning() ) 
		{
			//turn light on
			if ( !GetLightEntity()  &&  ( GetGame().IsClient() || !GetGame().IsMultiplayer() ) )
			{
				SetLightEntity( FireplaceLight.Cast( ScriptedLightBase.CreateLight(FireplaceLight, GetPosition(), 20) ) );
				GetLightEntity().AttachOnMemoryPoint(this, "light");
			}
		}
		else
		{
			//turn light off
			if (GetLightEntity())
			{
				GetLightEntity().FadeOut();
			}
		}
		
		//set default burn parameters based on fireplace type
		if ( IsBarrelWithHoles() || IsFireplaceIndoor() )
		{
			SetFuelBurnRateMP( FUEL_BURN_RATE_OVEN );
			SetTemperatureLossMP( TEMPERATURE_LOSS_MP_OVEN );
		}
		else
		{
			SetFuelBurnRateMP( FUEL_BURN_RATE_DEFAULT );
			SetTemperatureLossMP( TEMPERATURE_LOSS_MP_DEFAULT );			
		}
		
		//VISUAL STATES
		//Fuel state
		if ( IsItemTypeAttached( ATTACHMENT_STICKS ) )
		{
			SetAnimationPhase( ANIMATION_STICKS, 0 );
		}
		else
		{
			SetAnimationPhase( ANIMATION_STICKS, 1 );
		}
		
		//Firewood state
		if ( IsItemTypeAttached( ATTACHMENT_FIREWOOD ) )
		{
			if ( IsInAnimPhase( ANIMATION_BURNT_WOOD ) )
			{
				SetAnimationPhase( ANIMATION_WOOD, 1 );
			}
			else
			{
				SetAnimationPhase( ANIMATION_WOOD, 0 );
			}
		}
		else
		{
			SetAnimationPhase( ANIMATION_WOOD, 1 );
			SetAnimationPhase( ANIMATION_BURNT_WOOD, 1 );		
		}	
			
		//Kindling state
		if ( GetKindlingCount() == 0 )
		{
			SetAnimationPhase( ANIMATION_KINDLING, 1 );
		}
		else
		{
			SetAnimationPhase( ANIMATION_KINDLING, 0 );
		}

		//Ashes state
		if ( HasAshes() )
		{
			SetAnimationPhase( ANIMATION_ASHES, 0 );
		}
		else
		{
			SetAnimationPhase( ANIMATION_ASHES, 1 );
		}
		
		//Oven state (+set burn parameters)
		if ( IsOven() )
		{
			SetAnimationPhase( ANIMATION_OVEN, 0 );
			
			//set burn parameters
			SetFuelBurnRateMP( FUEL_BURN_RATE_OVEN );
			SetTemperatureLossMP( TEMPERATURE_LOSS_MP_OVEN );
		}
		else
		{
			SetAnimationPhase( ANIMATION_OVEN, 1 );
		}
		
		//Stones state (+set burn parameters)
		if ( IsItemTypeAttached ( ATTACHMENT_STONES ) )
		{
			ItemBase attached_item = ItemBase.Cast( GetAttachmentByType( ATTACHMENT_STONES ) );
			float item_quantity = attached_item.GetQuantity();
		
			//show stones
			if ( item_quantity >= 8 && !IsOven() )
			{
				SetAnimationPhase( ANIMATION_STONES, 0 );
				
				//set burn parameters
				SetFuelBurnRateMP( FUEL_BURN_RATE_STONES );
				SetTemperatureLossMP( TEMPERATURE_LOSS_MP_STONES );				
			}
			else
			{
				SetAnimationPhase( ANIMATION_STONES, 1 );
			}
		}
		else
		{
			SetAnimationPhase( ANIMATION_STONES, 1 );
		}
		
		//Tripod state
		if ( IsItemTypeAttached( ATTACHMENT_TRIPOD ) )
		{
			SetAnimationPhase( ANIMATION_TRIPOD, 0 );
		}
		else
		{
			SetAnimationPhase( ANIMATION_TRIPOD, 1 );
		}
		
		//refresh physics (with delay)
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( RefreshFireplacePhysics );
	}
	
	protected void SetBurntFirewood()
	{
		if ( IsInAnimPhase( ANIMATION_WOOD ) )
		{
			SetAnimationPhase( ANIMATION_WOOD, 1 );
			SetAnimationPhase( ANIMATION_BURNT_WOOD, 0 );				
		}	
	}

	//Refresh fireplace object physics
	void RefreshFireplacePhysics()
	{
		//Oven
		if ( IsOven() )
		{
			AddProxyPhysics( ANIMATION_OVEN );
		}
		else
		{
			RemoveProxyPhysics( ANIMATION_OVEN );
		}
		
		//Tripod
		if ( IsItemTypeAttached( ATTACHMENT_TRIPOD ) )
		{
			AddProxyPhysics( ANIMATION_TRIPOD );
		}
		else
		{
			RemoveProxyPhysics( ANIMATION_TRIPOD );
		}		
	}
	
	protected void RefreshFireParticlesAndSounds( bool force_refresh )
	{
		FireplaceFireState fire_state = GetFireState();
		
		if ( m_LastFireState != fire_state || force_refresh )
		{
			if ( fire_state == FireplaceFireState.START_FIRE )
			{
				//particles
				ParticleFireStartStart();
	
				//sounds
				SoundFireStop();
				SoundFireLightStart();			
			}
			else if ( fire_state == FireplaceFireState.SMALL_FIRE )
			{
				//particles
				ParticleFireStartStop();
				
				ParticleSmallFireStart();
				if ( CanShowSmoke() ) 
				{
					ParticleSmallSmokeStart();
				}
				else
				{
					ParticleSmallSmokeStop();
				}
				
				ParticleNormalFireStop();
				ParticleNormalSmokeStop();
				
				ParticleSteamExtinguishingStop();
				
				//sounds
				SoundFireStop();
				SoundFireLightStart();
			}
			else if ( fire_state == FireplaceFireState.NORMAL_FIRE )
			{
				//particles
				ParticleFireStartStop();
				
				ParticleSmallFireStop();
				ParticleSmallSmokeStop();
				
				ParticleNormalFireStart();
				if ( CanShowSmoke() ) 
				{
					ParticleNormalSmokeStart();
				}
				else
				{
					ParticleNormalSmokeStop();
				}
				
				ParticleSteamExtinguishingStop();
	
				//sounds
				SoundFireStop();
				SoundFireHeavyStart();
			}
			else if ( fire_state == FireplaceFireState.END_FIRE )
			{
				//particles
				ParticleFireStartStop();
				
				ParticleSmallFireStop();
				ParticleSmallSmokeStop();
	
				ParticleNormalFireStop();
				ParticleNormalSmokeStop();
	
				ParticleFireEndStart();
				
				//sounds
				SoundFireStop();
				SoundFireNoFireStart();
			}
			else if ( fire_state == FireplaceFireState.EXTINGUISHING_FIRE )		//TODO add steam particles when extinguishing
			{
				//particles
				ParticleFireStartStop();
				
				ParticleSmallFireStop();
				ParticleSmallSmokeStop();
	
				ParticleNormalFireStop();
				ParticleNormalSmokeStop();	
	
				ParticleFireEndStop();
				
				ParticleSteamExtinguishingStart();
				
				//sounds
				SoundFireStop();
				SoundFireExtinguishingStart();			
			}
			else if ( fire_state == FireplaceFireState.EXTINGUISHED_FIRE )		//TODO add steam particles when fireplace is extinguished
			{
				//particles
				ParticleFireStartStop();
				
				ParticleSmallFireStop();
				ParticleSmallSmokeStop();
	
				ParticleNormalFireStop();
				ParticleNormalSmokeStop();	
	
				ParticleFireEndStop();
				
				ParticleSteamExtinguishingStop();
				if ( CanShowSmoke() ) 
				{
					ParticleSteamEndStart();
				}
				else
				{
					ParticleSteamEndStop();
				}
				
				//sounds
				SoundFireStop();
				SoundFireExtinguishedStart();
				SoundFireNoFireStart();
			}
			else if ( fire_state == FireplaceFireState.REIGNITED_FIRE )
			{
				//particles
				ParticleFireStartStart();
				
				ParticleSmallFireStop();
				ParticleSmallSmokeStop();
	
				ParticleNormalFireStop();
				ParticleNormalSmokeStop();	
	
				ParticleFireEndStop();
				
				ParticleSteamEndStop();
				
				//sounds
				SoundFireStop();
			}
			else if ( fire_state == FireplaceFireState.NO_FIRE )
			{
				//particles
				ParticleFireStartStop();
				
				ParticleSmallFireStop();
				ParticleSmallSmokeStop();
	
				ParticleNormalFireStop();
				ParticleNormalSmokeStop();	
	
				ParticleFireEndStop();
				
				ParticleSteamEndStop();
				ParticleSteamExtinguishingStop();
				
				//sounds
				SoundFireStop();
			}
			
			m_LastFireState = fire_state;
		}
	}
	
	bool CanShowSmoke()
	{
		return true;
	}
	
	//Fireplace fire intensity
	void RefreshFireState()
	{
		float temperature = GetTemperature();
		FireplaceFireState fire_state = GetFireState();
		
		//if it's burning
		if ( IsBurning() )
		{
			//Start fire
			if ( temperature < PARAM_SMALL_FIRE_TEMPERATURE )
			{
				if ( GetFireState() != FireplaceFireState.START_FIRE )
				{
					SetFireState( FireplaceFireState.START_FIRE );
				}
			}
			//Small fire
			else if ( temperature >= PARAM_SMALL_FIRE_TEMPERATURE && temperature < PARAM_NORMAL_FIRE_TEMPERATURE )
			{
				if ( GetFireState() != FireplaceFireState.SMALL_FIRE )
				{
					SetFireState( FireplaceFireState.SMALL_FIRE );
				}
			}
			//Normal fire
			else if ( temperature > PARAM_SMALL_FIRE_TEMPERATURE )
			{
				if ( GetFireState() != FireplaceFireState.NORMAL_FIRE )
				{
					SetFireState( FireplaceFireState.NORMAL_FIRE );
				}
			}			
		}
	}

	//================================================================
	// PARTICLES & SOUNDS
	//================================================================
	//returns true if particle started, false if not
	protected bool PlayParticle( out Particle particle, int particle_type, vector local_pos )
	{
		if ( !particle && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			particle = Particle.PlayOnObject( particle_type, this, local_pos );
			
			return true;
		}
		
		return false;
	}
	
	//returns true if particle stopped, false if not
	protected bool StopParticle( out Particle particle )
	{
		if ( particle && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			particle.Stop();
			particle = NULL;
			
			return true;
		}
		
		return false;
	}
	
	//start fire
	protected void ParticleFireStartStart()
	{
		if ( IsOven() )
		{
			PlayParticle( m_ParticleFireStart, PARTICLE_OVEN_FIRE_START, GetFireEffectPosition() );
		}
		else
		{
			PlayParticle( m_ParticleFireStart, PARTICLE_FIRE_START, GetFireEffectPosition() );
		}
	}
	
	protected void ParticleFireStartStop()
	{
		StopParticle( m_ParticleFireStart );
	}
	
	//small fire
	protected void ParticleSmallFireStart()
	{
		if ( IsOven() )
		{
			PlayParticle( m_ParticleSmallFire, PARTICLE_OVEN_FIRE, GetFireEffectPosition() );
		}
		else
		{
			PlayParticle( m_ParticleSmallFire, PARTICLE_SMALL_FIRE, GetFireEffectPosition() );	
		}
	}
	
	protected void ParticleSmallFireStop()
	{
		StopParticle( m_ParticleSmallFire );
	}	
	
	//normal fire
	protected void ParticleNormalFireStart()
	{
		if ( IsOven() )
		{
			PlayParticle( m_ParticleNormalFire, PARTICLE_OVEN_FIRE, GetFireEffectPosition() );
		}
		else
		{
			PlayParticle( m_ParticleNormalFire, PARTICLE_NORMAL_FIRE, GetFireEffectPosition() );
		}
	}
	
	protected void ParticleNormalFireStop()
	{
		StopParticle( m_ParticleNormalFire );
	}
	
	//small smoke
	protected void ParticleSmallSmokeStart()
	{
		PlayParticle( m_ParticleSmallSmoke, PARTICLE_SMALL_SMOKE, GetSmokeEffectPosition() );
		
		//calculate air resistance
		float actual_height;
		if ( !HasEnoughRoomForSmokeAbove( actual_height ) )
		{
			float air_resistance = GetAirResistanceForSmokeParticles( actual_height );
			
			//alter smoke height
			m_ParticleSmallSmoke.SetParameter( -1, EmitorParam.AIR_RESISTANCE, air_resistance );
			
			if ( IsRoofAbove() )
			{
				m_ParticleSmallSmoke.SetParameter( -1, EmitorParam.WIND, false );
			}
		}
	}
	
	protected void ParticleSmallSmokeStop()
	{
		StopParticle( m_ParticleSmallSmoke );
	}
	
	//normal smoke
	protected void ParticleNormalSmokeStart()
	{
		PlayParticle( m_ParticleNormalSmoke, PARTICLE_NORMAL_SMOKE, GetSmokeEffectPosition() );
		
		//calculate air resistance
		float actual_height;
		if ( !HasEnoughRoomForSmokeAbove( actual_height ) )
		{		
			float air_resistance = GetAirResistanceForSmokeParticles( actual_height );
			
			//alter smoke height
			m_ParticleNormalSmoke.SetParameter( -1, EmitorParam.AIR_RESISTANCE, air_resistance );
			
			if ( IsRoofAbove() )
			{			
				m_ParticleNormalSmoke.SetParameter( -1, EmitorParam.WIND, false );
			}
		}
	}
	
	protected void ParticleNormalSmokeStop()
	{
		StopParticle( m_ParticleNormalSmoke );
	}
	
	//fire end
	protected void ParticleFireEndStart()
	{
		if ( IsOven() )
		{
			PlayParticle( m_ParticleFireEnd, PARTICLE_OVEN_FIRE_END, GetFireEffectPosition() );
		}
		else
		{
			PlayParticle( m_ParticleFireEnd, PARTICLE_FIRE_END, GetFireEffectPosition() );
		}
	}
	
	protected void ParticleFireEndStop()
	{
		StopParticle( m_ParticleFireEnd );
	}
	
	//steam extinguishing
	protected void ParticleSteamExtinguishingStart()
	{
		PlayParticle( m_ParticleSteamExtinguishing, PARTICLE_STEAM_EXTINGUISHING, GetFireEffectPosition() );
	}
	
	protected void ParticleSteamExtinguishingStop()
	{
		StopParticle(m_ParticleSteamExtinguishing);
	}	

	//steam end
	protected void ParticleSteamEndStart()
	{
		PlayParticle( m_ParticleSteamEnd, PARTICLE_STEAM_END, GetFireEffectPosition() );
	}
	
	protected void ParticleSteamEndStop()
	{
		StopParticle( m_ParticleSteamEnd );
	}

	//Particle Positions
	//Get local fire and smoke effect position
	protected vector GetFireEffectPosition()
	{
		return Vector( 0, 0.05, 0 );
	}
	
	protected vector GetSmokeEffectPosition()
	{
		return Vector( 0, 0.05, 0 );
	}

	//================================================================
	// SOUNDS
	//================================================================
	//Burning
	//Start
	protected void SoundFireLightStart()
	{
		PlaySoundSetLoop( m_SoundFireLoop, SOUND_FIRE_LIGHT, 1.0, 1.0 );
	}
	
	protected void SoundFireHeavyStart()
	{
		PlaySoundSetLoop( m_SoundFireLoop, SOUND_FIRE_HEAVY, 1.0, 2.0 );
	}

	protected void SoundFireNoFireStart()
	{
		PlaySoundSetLoop( m_SoundFireLoop, SOUND_FIRE_NO_FIRE, 2.0, 2.0 );
	}
	
	protected void SoundFireExtinguishedStart()
	{
		PlaySoundSet( m_SoundFire, SOUND_FIRE_EXTINGUISHED, 0.1, 0.1 );
	}		

	protected void SoundFireExtinguishingStart()
	{
		PlaySoundSetLoop( m_SoundFireLoop, SOUND_FIRE_EXTINGUISHING, 1.0, 0.5 );
	}
	
	//Stop
	protected void SoundFireStop()
	{
		StopSoundSet( m_SoundFireLoop );
	}
	
	//================================================================
	// FUEL / KINDLING
	//================================================================
	//Add to fire consumables
	protected void AddToFireConsumables( ItemBase item )
	{
		float energy = GetFireConsumableTypeEnergy ( item );
		m_FireConsumables.Insert( item, new FireConsumable ( item, energy ) );
		
		CalcAndSetQuantity();
	}

	protected float GetFireConsumableTypeEnergy( ItemBase item )
	{
		//Kindling
		ref FireConsumableType fire_consumable_type = m_FireConsumableTypes.Get( item.Type() );
		if ( fire_consumable_type )
		{
			return fire_consumable_type.GetEnergy();
		}
		
		return 0;
	}

	//Remove from fire consumables
	protected void RemoveFromFireConsumables( FireConsumable fire_consumable )
	{
		if ( fire_consumable )
		{
			m_FireConsumables.Remove( fire_consumable.GetItem() );
			delete fire_consumable;
		}
		
		CalcAndSetQuantity();
	}
	
	protected FireConsumable GetFireConsumableByItem( ItemBase item )
	{
		return m_FireConsumables.Get( item );
	}

	//Set fuel / kindling to consume
	//Sets the item with the lowest energy value as item that will be consumed next
	//Returns reference to set fire consumable
	protected FireConsumable SetItemToConsume()
	{
		if ( m_FireConsumables.Count() == 0 )
		{
			m_ItemToConsume = NULL;
		}
		else
		{
			float energy = 0;
			
			for ( int i = 0; i < m_FireConsumables.Count(); ++i )
			{
				ItemBase key = m_FireConsumables.GetKey( i );
				ref FireConsumable fire_consumable = m_FireConsumables.Get( key );
				energy = fire_consumable.GetEnergy();
				
				if ( i == 0 )
				{
					m_ItemToConsume = fire_consumable;
				}
				else
				{
					if ( fire_consumable.GetEnergy() < m_ItemToConsume.GetEnergy() )
					{
						m_ItemToConsume = fire_consumable;
					}	
				}
			}
		}
		
		//refresh visual
		RefreshFireplaceVisuals();

		return m_ItemToConsume;
	}

	protected FireConsumable GetItemToConsume()
	{
		return m_ItemToConsume;
	}

	//Spend item that is used as consumable for fire (fuel, kindling)
	//if 'amount == 0', the whole quantity will be consumed (quantity -= 1 )
	//debug
	//int m_debug_fire_consume_time = 0;
	protected void SpendFireConsumable ( float amount )
	{
		//spend item
		ref FireConsumable fire_consumable = GetItemToConsume();
		
		if ( !fire_consumable )
		{
			//Set new item to consume
			fire_consumable = SetItemToConsume();
		}
		
		if ( fire_consumable )
		{
			ItemBase item = fire_consumable.GetItem();
			
			//set remaining energy
			fire_consumable.SetRemainingEnergy( fire_consumable.GetRemainingEnergy() - amount );
			
			//Debug
			/*
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			string message = "item type = " + item.GetType() + " m_RemainingEnergy = " + fire_consumable.GetRemainingEnergy().ToString() + " quantity = " + item.GetQuantity().ToString() + " amount = " + amount.ToString();
			player.MessageAction ( message );
			*/
			
			if ( fire_consumable.GetRemainingEnergy() <= 0 || amount == 0 )
			{
				//set ashes
				if ( !HasAshes() )
				{
					SetAshesState( true );
				}	
				
				if ( item.IsInherited( ItemBook ) || item.IsInherited( Paper ) )
				{
					//Debug
					//Print( "Item consumed = " + item.GetType() + " time = " + m_debug_fire_consume_time.ToString() );
					//m_debug_fire_consume_time = 0;
					//
					
					RemoveFromFireConsumables( fire_consumable );
					GetGame().ObjectDelete( item );
				}
				else
				{
					//if there is nothing left, delete and remove old consumable, set new fire consumable
					if ( item.GetQuantity() <= 1 )
					{
						//remove item from fuel items
						RemoveFromFireConsumables( fire_consumable );
					}
					else
					{
						fire_consumable.SetRemainingEnergy( fire_consumable.GetEnergy() );
					}

					//Debug
					//Print( "Item consumed = " + item.GetType() + " time = " + m_debug_fire_consume_time.ToString() );
					//m_debug_fire_consume_time = 0;
					//
					
					item.AddQuantity( -1 );
					SetItemToConsume();			//set item after each quantity decrease
				}
			}
		}
		
		//debug
		//m_debug_fire_consume_time += TIMER_HEATING_UPDATE_INTERVAL;
		//
		
		CalcAndSetQuantity();
	}

	//GetKindlingCount
	//Returns count of all kindling type items (define in 'm_KindlingTypes') attached to fireplace
	protected int GetKindlingCount()
	{
		int attachments_count = GetInventory().AttachmentCount();
		int fire_consumables_count = m_FireConsumables.Count();
		int kindling_count = 0;
		
		for ( int i = 0; i < attachments_count; i++ )
		{
			ItemBase item = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( i ) );
			
			for ( int j = 0; j < fire_consumables_count; j++ )
			{
				ref FireConsumableType fire_consumable_type = m_FireConsumableTypes.Get( item.Type() );

				if ( fire_consumable_type && fire_consumable_type.IsKindling() )
				{
					kindling_count++;
					break;
				}
			}
		}
		
		return kindling_count;
	}

	//GetFuelCount
	//Returns count of all fuel type items (define in 'm_FuelTypes') attached to fireplace
	protected int GetFuelCount()
	{
		int attachments_count = GetInventory().AttachmentCount();
		int fire_consumables_count = m_FireConsumables.Count();
		int fuel_count = 0;
		
		for ( int i = 0; i < attachments_count; i++ )
		{
			ItemBase item = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( i ) );
			
			for ( int j = 0; j < fire_consumables_count; j++ )
			{
				ref FireConsumableType fire_consumable_type = m_FireConsumableTypes.Get( item.Type() );

				if ( fire_consumable_type && !fire_consumable_type.IsKindling() )
				{
					fuel_count++;
					break;
				}
			}
		}
		
		return fuel_count;
	}

	//returns if item attached to fireplace is kindling
	protected bool IsKindling( ItemBase item )
	{
		ref FireConsumableType fire_consumable_type = m_FireConsumableTypes.Get( item.Type() );
		if ( fire_consumable_type )
		{
			return fire_consumable_type.IsKindling();
		}
		
		return false;
	}

	//returns if item attached to fireplace is fuel
	protected bool IsFuel( ItemBase item )
	{
		ref FireConsumableType fire_consumable_type = m_FireConsumableTypes.Get( item.Type() );
		if ( fire_consumable_type )
		{
			return !fire_consumable_type.IsKindling();
		}
		
		return false;
	}

	//Has attachments of given type
	bool IsItemTypeAttached( typename item_type )
	{
		if ( GetAttachmentByType( item_type ) )
		{
			return true;
		}
		
		return false;
	}

	//Has attachments of required quantity
	bool IsItemAttachedQuantity( typename item_type, float quantity )
	{
		ItemBase item = ItemBase.Cast( GetAttachmentByType( item_type ) );
		
		if ( item.GetQuantity() >= quantity )
		{
			return true;
		}
		
		return false;
	}

	//Has last attached item
	bool HasLastAttachment()
	{
		if ( GetInventory().AttachmentCount() == 1 )
		{
			return true;
		}
		
		return false;
	}

	//Has last fuel/kindling attached
	bool HasLastFuelKindlingAttached()
	{
		int fuel_kindling_count = GetFuelCount() + GetKindlingCount();

		if ( fuel_kindling_count == 1 )
		{
			return true;
		}
		
		return false;
	}

	
	//================================================================
	// FIRE STATE
	//================================================================
	//Is fireplace burning?
	bool IsBurning()
	{
		return m_IsBurning;
	}
	
	//Set burning state
	protected void SetBurningState( bool is_burning )
	{
 		if ( m_IsBurning != is_burning )
		{
			m_IsBurning = is_burning;
			
			//synchronize
			Synchronize();
		}
	}

	//Are ashes present in fireplace?
	bool HasAshes()
	{
		return m_HasAshes;
	}

	//Set ashes state
	protected void SetAshesState( bool has_ashes )
	{
		if ( m_HasAshes != has_ashes )
		{
			m_HasAshes = has_ashes;
			
			if ( m_HasAshes )
			{
				SetBurntFirewood();		//set burnt wood visual
			}
			
			//synchronize
			Synchronize();
		}
	}

	//Is in oven state
	bool IsOven()
	{
		return m_IsOven;
	}		
	
	void SetOvenState( bool is_oven )
	{
		if ( m_IsOven != is_oven )
		{
			m_IsOven = is_oven;
			
			//synchronize
			Synchronize();
		}
	}
	
	//Temperature loss MP
	protected float GetTemperatureLossMP()
	{
		return m_TemperatureLossMP;
	}	
	
	protected void SetTemperatureLossMP( float value )
	{
		m_TemperatureLossMP = value;
	}
	
	//Fuel burn rate MP
	protected float GetFuelBurnRateMP()
	{
		return m_FuelBurnRateMP;
	}	
	
	protected void SetFuelBurnRateMP( float value )
	{
		m_FuelBurnRateMP = value;
	}
	
	//Get fire state 
	protected int GetFireState()
	{
		return m_FireState;
	}

	//Sets fire state
	protected void SetFireState( FireplaceFireState state )
	{
		if ( m_FireState != state )
		{
			m_FireState = state;
			
			//synchronize
			Synchronize();
		}
	}
		
	void SetExtinguishingState()
	{
		SetFireState( FireplaceFireState.EXTINGUISHING_FIRE );
	}

	//================================================================
	// FIRE PROCESS
	//================================================================
	
	//Start the fire process
	// 1. start heating
	// 2. heating
	// 3. stop heating
	void StartFire( bool force_start = false )
	{
		//Print("Starting fire...");
		
		//stop cooling process if active
		if ( m_CoolingTimer )
		{
			m_CoolingTimer.Stop();
			m_CoolingTimer = NULL;
		}
		
		//start fire
		if ( !IsBurning() || force_start )	
		{
			//set fuel to consume
			SetItemToConsume();
			
			//set fire state
			SetBurningState( true );
			
			//start heating
			StartHeating();
		}
	}

	//Start heating
	protected void StartHeating()
	{
		//Print("Starting heat...");
		
		//visual
		SetObjectMaterial ( 0, MATERIAL_FIREPLACE_GLOW );
		
		//create area damage
		if ( IsBaseFireplace() && !IsOven() )
		{
			CreateAreaDamage();
		}
		
		m_HeatingTimer = new Timer ( CALL_CATEGORY_GAMEPLAY );
		m_HeatingTimer.Run ( TIMER_HEATING_UPDATE_INTERVAL, this, "Heating", NULL, true );	
	}

	//Do heating
	protected void Heating()
	{
		//Debug
		/*
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		player.MessageAction ( "Heating..." );
		*/
		
		float wetness = GetWet();
		float temperature = GetTemperature();
		float temperature_modifier = 0;
		
		//check burning conditions
		if ( wetness > PARAM_BURN_WET_THRESHOLD )		//wetness condition
		{
			StopFire( FireplaceFireState.EXTINGUISHED_FIRE );
			return; 
		}
		else
		{
			if ( m_FireConsumables.Count() == 0 )		//fire consumable condition
			{
				StopFire();
				return; 				
			}
		}

		//DEBUG
		/*
		string s_message = "-> fire amount = " + PARAM_FIRE_CONSUM_RATE_AMOUNT.ToString() + " burn rate = " + GetFuelBurnRateMP().ToString() + " temp loss = " + GetTemperatureLossMP().ToString();
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		player.MessageAction (s_message);
		Print ( s_message );
		*/
		
		//spend actual fire consumable
		float amount = ( PARAM_FIRE_CONSUM_RATE_AMOUNT * GetFuelBurnRateMP() ) * TIMER_HEATING_UPDATE_INTERVAL;
		SpendFireConsumable ( amount );
		
		//set wetness if raining and alter temperature modifier (which will lower temperature increase because of rain)
		float rain = GetGame().GetWeather().GetRain().GetActual();
		if ( rain >= PARAM_BURN_WET_THRESHOLD && IsRainingAbove() )
		{
			//set wet to fireplace
			AddWetnessToFireplace( PARAM_WET_INCREASE_COEF * rain );
			
			//set temperature modifier
			temperature_modifier = PARAM_TEMPERATURE_INCREASE * rain;
		}
		//subtract wetness when heating and not raining above
		else
		{
			AddWetnessToFireplace( -PARAM_WET_HEATING_DECREASE_COEF );
		}
		
		//calculate and set temperature
		AddTemperatureToFireplace( PARAM_TEMPERATURE_INCREASE - temperature_modifier );
		
		//check fire state
		if ( GetFireState() != FireplaceFireState.EXTINGUISHING_FIRE )
		{
			RefreshFireState();
		}
		
		//damage cargo items
		BurnItemsInFireplace();
		
		//transfer heat to near players
		TransferHeatToNearPlayers();
		
		//manage cooking equipment
		if ( m_CookingEquipment )
		{
			float cook_equip_temp = m_CookingEquipment.GetTemperature();
			
			if ( cook_equip_temp >= PARAM_COOKING_TEMP_THRESHOLD )
			{
				//start cooking
				CookWithEquipment();
			}
			
			//DEBUG
			/*
			PlayerBase player = ( PlayerBase ) GetGame().GetPlayer();
			string s_message = "cooking equipment temp = " + ftoa(cook_equip_temp) + " | PARAM_COOKING_TEMP_THRESHOLD = " + ftoa(PARAM_COOKING_TEMP_THRESHOLD);
			if (player != NULL) {player.MessageAction (s_message);}
			Print ( s_message );
			*/
			//set temperature to cooking equipment
			cook_equip_temp = cook_equip_temp + PARAM_COOKING_EQUIP_TEMP_INCREASE;
			if ( temperature <= PARAM_SMALL_FIRE_TEMPERATURE )
			{
				cook_equip_temp = Math.Clamp ( cook_equip_temp, PARAM_ITEM_HEAT_MIN_TEMP, PARAM_SMALL_FIRE_TEMPERATURE );
			}
			else
			{
				cook_equip_temp = Math.Clamp ( cook_equip_temp, PARAM_ITEM_HEAT_MIN_TEMP, PARAM_COOKING_EQUIP_MAX_TEMP );
			}
			m_CookingEquipment.SetTemperature( cook_equip_temp );
		}
	}
	
	//Stop the fire process
	// 1. start cooling
	// 2. cooling
	// 3. stop cooling
	void StopFire( FireplaceFireState fire_state = FireplaceFireState.END_FIRE )
	{
		//Debug
		//PlayerBase player = ( PlayerBase ) GetGame().GetPlayer();
		//if (player != NULL) {player.MessageAction ( "Stop fire..." );}
		//Print("Stop fire...");
		
		//Stop heating
		StopHeating();
		
		//spend item
		SpendFireConsumable( 0 );
		
		//turn fire off
		SetBurningState( false );
		
		//start cooling
		StartCooling();
		
		//Refresh fire visual
		SetFireState( fire_state );
		
		//remove audio visuals
		if ( GetCookingEquipment() )
		{
			Bottle_Base cooking_pot = Bottle_Base.Cast( GetCookingEquipment() );
			cooking_pot.RemoveAudioVisualsOnClient();
		}
	}
	
	//Stop heating
	protected void StopHeating()
	{
		//Debug
		//PlayerBase player = ( PlayerBase ) GetGame().GetPlayer();
		//if (player != NULL) {player.MessageAction ( "Stop heating..." );}
		//Print("Stop heating...");
		
		//Stop heating
		m_HeatingTimer.Stop();
		m_HeatingTimer = NULL;
	}	

	//Start cooling
	protected void StartCooling()
	{
		//Debug
		//PlayerBase player = ( PlayerBase ) GetGame().GetPlayer();
		//if (player != NULL) {player.MessageAction ( "Start cooling..." );}
		//Print("Start cooling...");
		
		//stop heating timer if active
		if ( m_HeatingTimer )
		{
			m_HeatingTimer.Stop();
			m_HeatingTimer = NULL;
		}
		
		//Start cooling
		m_CoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_CoolingTimer.Run( TIMER_COOLING_UPDATE_INTERVAL, this, "Cooling", NULL, true );		
	}

	//Start cooling       
	protected void Cooling()
	{
		//Debug
		/*
		PlayerBase player = ( PlayerBase ) GetGame().GetPlayer();
		player.MessageAction ( "Cooling..." );
		Print("Cooling...");
		*/
		
		float wetness = GetWet();
		float temperature = GetTemperature();
		float temperature_modifier = 0;
		
		if ( this && !IsBurning() && temperature >= PARAM_MIN_FIRE_TEMPERATURE )
		{
			//check wetness
			//set wetness if raining and alter temperature modifier (which will lower temperature increase because of rain)
			float rain = GetGame().GetWeather().GetRain().GetActual();
			if ( IsRainingAbove() )
			{
				//set wet to fireplace
				AddWetnessToFireplace( PARAM_WET_INCREASE_COEF * rain );
				
				//set temperature modifier
				temperature_modifier = temperature_modifier + ( PARAM_TEMPERATURE_DECREASE * rain );
			}
			else		//subtrackt wetness
			{
				AddWetnessToFireplace( -PARAM_WET_COOLING_DECREASE_COEF );
			}
			
			//calculate already obtained wetness (e.g. extinguished by water)
			temperature_modifier = temperature_modifier + ( PARAM_TEMPERATURE_DECREASE * wetness );
			
			//calculate and set temperature (decrease)
			AddTemperatureToFireplace( -PARAM_TEMPERATURE_DECREASE - ( temperature_modifier * GetTemperatureLossMP() ) );
			
			//damage cargo items
			BurnItemsInFireplace();
			
			//transfer heat to near players
			TransferHeatToNearPlayers();			
			
			//cook with equipment if temperature of equipment is still high
			if ( m_CookingEquipment )
			{
				float cook_equip_temp = m_CookingEquipment.GetTemperature();
				
				if ( cook_equip_temp >= PARAM_COOKING_TEMP_THRESHOLD )
				{
					//cook
					CookWithEquipment();
				}
			}
			
			//Debug
			//PlayerBase player = ( PlayerBase ) GetGame().GetPlayer();
			//if (player != NULL) {player.MessageAction ( temperature.ToString() );}
		
			//turn off glow effect and other fire effects
			if ( temperature <= PARAM_MIN_TEMP_TO_REIGNITE )
			{
				//visual
				SetObjectMaterial( 0, MATERIAL_FIREPLACE_NOGLOW );
				
				//stop all fire visuals
				SetFireState( FireplaceFireState.NO_FIRE );	
			}
		}
		else
		{
			//stop cooling
			StopCooling();
		}
	}

	protected void StopCooling()
	{
		//Debug
		//PlayerBase player = ( PlayerBase ) GetGame().GetPlayer();
		//if (player != NULL) {player.MessageAction ( "Stop cooling..." );}
		//Print("Stop cooling...");
		
		//stop all fire visuals
		SetFireState( FireplaceFireState.NO_FIRE );	
		
		//Stop cooling
		m_CoolingTimer.Stop();
		m_CoolingTimer = NULL;
		
		//destroy area damage
		DestroyAreaDamage();
	}
	
	//================================================================
	// COOKING
	//================================================================
	protected void CookWithEquipment()
	{
		if ( m_CookingProcess == NULL )
		{
			m_CookingProcess = new Cooking();
		}
		
		m_CookingProcess.CookWithEquipment ( m_CookingEquipment );
	}
	
	Cooking GetCookingProcess()
	{
		if ( m_CookingProcess == NULL )
		{
			m_CookingProcess = new Cooking();
		}
		
		return m_CookingProcess;
	}
	
	//================================================================
	// FIRE VICINITY
	//================================================================
	//apply damage to all items, raise temperature to only specific items
	protected void BurnItemsInFireplace()
	{
		//Cargo
		CargoBase cargo = GetInventory().GetCargo();
		for ( int i = 0; i < cargo.GetItemCount(); i++ )
		{
			ItemBase item = ItemBase.Cast( cargo.GetItem ( i ) );
			
			//set damage
			AddDamageToItemByFire( item, true );
			
			//add temperature
			AddTemperatureToItemByFire( item );
			
			//remove wetness
			AddWetnessToItem( item, -PARAM_WET_HEATING_DECREASE_COEF );
		}
		
		//Fuel (only) attachments
		for ( int j = 0; j < GetInventory().AttachmentCount(); ++j )
		{
			ItemBase attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( j ) );
			
			//set damage (fuel items only)
			if ( IsKindling( attachment ) || IsFuel( attachment ) )
			{
				//set damage
				AddDamageToItemByFire( attachment, false );
			}
			
			//add temperature
			AddTemperatureToItemByFire( attachment );
		
			//remove wetness
			AddWetnessToItem( attachment, -PARAM_WET_HEATING_DECREASE_COEF );		
		}
	}
	
	//add temperature to item by fire
	protected void AddTemperatureToItemByFire( ItemBase item )
	{
		if ( item.GetTemperatureMax() >= PARAM_ITEM_HEAT_MIN_TEMP )
		{
			float temperature = item.GetTemperature() + PARAM_ITEM_HEAT_TEMP_INCREASE_COEF;
			temperature = Math.Clamp ( temperature, PARAM_ITEM_HEAT_MIN_TEMP, PARAM_MAX_ITEM_HEAT_TEMP_INCREASE );
			item.SetTemperature( temperature );
		}
	}

	protected void AddTemperatureToFireplace( float amount )
	{
		float temperature = GetTemperature();
		temperature = temperature + amount;
		
		if ( GetFuelCount() == 0 && temperature <= ( PARAM_SMALL_FIRE_TEMPERATURE + PARAM_TEMPERATURE_INCREASE ) )	//no fuel present, temperature should be low but there can be high temperature from previous fuel burning
		{
			temperature = Math.Clamp ( temperature, 0, PARAM_SMALL_FIRE_TEMPERATURE );		//small fire
		}
		else
		{
			temperature = Math.Clamp ( temperature, 0, PARAM_NORMAL_FIRE_TEMPERATURE );		//normal fire
		}
		SetTemperature( temperature );
	}	
	
	//add damage to item by fire
	protected void AddDamageToItemByFire( ItemBase item, bool can_be_ruined )
	{
		//if item can be cooked, burn it
		if ( item.CanBeCooked() )
		{
			Edible_Base edible_item = Edible_Base.Cast( item );
			edible_item.ChangeFoodStage( FoodStageType.BURNED );
		}
		//else add damage (max to BADLY_DAMAGED state)
		else
		{
			float damage_amount = PARAM_BURN_DAMAGE_COEF * 100;
			float min_health;
			
			if ( !can_be_ruined )
			{
				min_health = InjuryHandlerThresholds.RUINED * 100;
			}
				
			if ( item.GetHealth() >= min_health + damage_amount )
			{
				item.DecreaseHealth( damage_amount, false );
			}	
		}
	}
	
	//add wetness on item
	protected void AddWetnessToItem( ItemBase item, float amount )
	{
		float wetness = item.GetWet();
		wetness = wetness + amount;
		wetness = Math.Clamp ( wetness, 0, 1 );		//wetness <0-1>
		item.SetWet( wetness );
	}
	
	//add wetness on fireplace
	void AddWetnessToFireplace( float amount )
	{
		//add wetness
		float wetness = GetWet();
		wetness = wetness + amount;
		wetness = Math.Clamp ( wetness, 0, 1 );		//wetness <0-1>
		SetWet( wetness );
		
		//decrease temperature
		if ( amount > 0 )
		{
			float temperature = GetTemperature();
			temperature = temperature * ( 1 - ( wetness * 0.5 ) );
			temperature = Math.Clamp( temperature, PARAM_MIN_FIRE_TEMPERATURE, PARAM_NORMAL_FIRE_TEMPERATURE );
			SetTemperature( temperature );
		}
	}	
	
	//transfer heat to all nearby players
	protected void TransferHeatToNearPlayers()
	{
		float distance;

		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;

		GetGame().GetObjectsAtPosition ( GetPosition(), PARAM_HEAT_RADIUS, nearest_objects, proxy_cargos ); 

		for ( int i = 0; i < nearest_objects.Count(); i++ )
		{
			Object nearest_object = nearest_objects.Get(i);
			
			//! heat transfer to player
			if ( nearest_object.IsInherited( PlayerBase ) )
			{
				PlayerBase player = PlayerBase.Cast( nearest_object );
				distance = vector.Distance( player.GetPosition(), GetPosition() );
				distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
				
				//! heat transfer through air to player ( anv temperature )
				float temperature = GetTemperature() * ( PARAM_HEAT_THROUGH_AIR_COEF / distance );
				player.AddToEnvironmentTemperature( temperature );
			}
			//! heat transfer to items (no in player possession)
			else if ( nearest_object != this && nearest_object.IsInherited( ItemBase ) && nearest_object.GetParent() == null )
			{
				ItemBase item = ItemBase.Cast( nearest_object );
				float wetness = item.GetWet();

				//! drying of items around the fireplace (based on distance)
				if ( wetness > 0 )
				{
					distance = vector.Distance( item.GetPosition(), GetPosition() );
					distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
					
					wetness = wetness * ( PARAM_HEAT_THROUGH_AIR_COEF / distance );
					wetness = Math.Clamp( wetness, item.GetWetMin(), item.GetWetMax() );
					item.AddWet( -wetness );
				}
			}
		}
	}
	
	//Create and Destroy damage radius around the fireplace when starting/stopping burning process
	void CreateAreaDamage()
	{
		//destroy area damage if some already exists
		DestroyAreaDamage();
		
		//create new area damage
		m_AreaDamage = new AreaDamageRegularDeferred( this );
		m_AreaDamage.SetExtents("-0.25 0 -0.25", "0.25 1.8 0.25");
		m_AreaDamage.SetLoopInterval( 0.5 );
		m_AreaDamage.SetDeferInterval( 0.5 );
		m_AreaDamage.SetHitZones( { "Head","Torso","LeftHand","LeftLeg","LeftFoot","RightHand","RightLeg","RightFoot" } );
		m_AreaDamage.SetAmmoName( "FireDamage" );
		m_AreaDamage.Spawn();
	}
	
	void DestroyAreaDamage()
	{
		if ( m_AreaDamage ) 
		{
			m_AreaDamage.DestroyDamageTrigger();
		}
	}

	//================================================================
	// SUPPORT
	//================================================================
	//Check if object is under a roof (height check)
	static void LineHit( EntityAI entity, float height, out bool hit, out float actual_height )
	{
		float start_pos_offset = 1.8;
		vector from = entity.GetPosition();
		vector to = entity.GetPosition();
		from[1] = from[1] + start_pos_offset;		//add fireplace height into calculation
		to[1] = to[1] + height;
		vector contactPos;
		vector contactDir;
		int contactComponent;
		
		hit = DayZPhysics.RaycastRV( from, to, contactPos, contactDir, contactComponent, NULL, NULL, entity );
		actual_height = vector.Distance( from, contactPos ) + start_pos_offset;
		
		//debug
		//Print( "actual_height = " + actual_height.ToString() );
	}

	//Is player facing fireplace
	bool IsFacingFireplace( PlayerBase player )
	{
		vector fireplace_pos = GetPosition();
		vector player_pos = player.GetPosition();
		vector dir_vec = vector.Direction( fireplace_pos, player_pos );	//calculate direction vector
		dir_vec.Normalize();										//normalize direction vector
		
		//check zero vector
		if ( dir_vec.Length() == 0 )
		{
			return false;
		}
		
		float dot = vector.Dot ( player.GetOrientation(), dir_vec );
		if ( Math.Acos ( dot ) < 0.436332313 ) 		//0.436332313 => 25 degrees 
		{
			return true;
		}
		
		return false;
	}
	
	//================================================================
	// ACTIONS
	//================================================================
	// --- Actions / Action conditions
	//Check if there is some kindling attached
	bool HasAnyKindling()
	{
		if ( GetKindlingCount() > 0 )
		{
			return true;
		}
		
		return false;
	}

	//Check if the weather is too windy
	static bool IsWindy()
	{
		//check wind
		float wind_speed = GetGame().GetWeather().GetWindSpeed();
		float wind_speed_threshold = GetGame().GetWeather().GetWindMaximumSpeed() * 0.8;
		
		if ( wind_speed >= wind_speed_threshold )
		{
			return true;
		}
		
		return false;
	}

	//Check if the fireplace is too wet to be ignited
	static bool IsEntityWet( notnull EntityAI entity_ai )
	{
		if ( entity_ai.GetWet() >= FireplaceBase.PARAM_MAX_WET_TO_IGNITE )
		{
			return true;
		}
		
		return false;
	}
	
	bool IsWet()
	{
		return FireplaceBase.IsEntityWet( this );
	}

	//Check if there is any roof above fireplace
	bool IsRoofAbove()
	{
		//check rain
		float actual_height;
		bool hit;
		FireplaceBase.LineHit( this, 20, hit, actual_height );
		
		return hit;
	}

	//Check if there is enough room for smoke above fireplace
	bool HasEnoughRoomForSmokeAbove( out float actual_height )
	{
		//check rain
		bool hit;
		FireplaceBase.LineHit( this, 6, hit, actual_height );
		
		return !hit;
	}	
	
	//Check if there is enough room for fire above fireplace
	static bool HasEntityEnoughRoomForFireAbove( notnull EntityAI entity_ai )
	{
		//check rain
		float actual_height;
		bool hit;
		FireplaceBase.LineHit( entity_ai, 1.8, hit, actual_height );
		
		return !hit;
	}
	
	bool HasEnoughRoomForFireAbove()
	{
		return FireplaceBase.HasEntityEnoughRoomForFireAbove( this );
	}
	
	float GetAirResistanceForSmokeParticles( float actual_height )
	{
		float air_res;
		actual_height = Math.Clamp( actual_height, 0, 6 );
		
		air_res = ( 6 - actual_height ) * 0.33; //6 is the max height of smoke particles
		air_res = Math.Clamp( air_res, 0, 2 );
		
		return air_res;
	}

	//Check if it's raining and there is only sky above fireplace
	static bool IsRainingAboveEntity( notnull EntityAI entity_ai )
	{
		//check rain
		bool hit;
		float actual_height;
		FireplaceBase.LineHit( entity_ai, 100, hit, actual_height );
		
		if ( GetGame() && GetGame().GetWeather().GetRain().GetActual() >= FireplaceBase.PARAM_IGNITE_RAIN_THRESHOLD && !hit )
		{
			return true;
		}
		
		return false;
	}
	
	bool IsRainingAbove()
	{
		return FireplaceBase.IsRainingAboveEntity( this );
	}

	//Check there is water surface bellow fireplace
	static bool IsEntityOnWaterSurface( notnull EntityAI entity_ai )
	{
		//check surface
		string surface_type;
		vector fireplace_pos = entity_ai.GetPosition();
		
		GetGame().SurfaceGetType ( fireplace_pos[0], fireplace_pos[2], surface_type ); 
		if ( surface_type == "FreshWater" || surface_type == "sea" || GetGame().SurfaceIsSea( fireplace_pos[0], fireplace_pos[2] ) )
		{
			return true;
		}
		
		return false;
	}
	
	bool IsOnWaterSurface()
	{
		return FireplaceBase.IsEntityOnWaterSurface( this );
	}

	//Checks if has not additional items in it
	override bool IsEmpty()
	{
		//check cargo and attachments
		CargoBase cargo = GetInventory().GetCargo();
		if ( cargo.GetItemCount() == 0 && GetInventory().AttachmentCount() == 0 )
		{
			return true;			
		}
		
		return false;
	}
	
	//Checks if it has no items in cargo
	bool IsCargoEmpty()
	{
		//check cargo
		CargoBase cargo = GetInventory().GetCargo();
		if ( cargo.GetItemCount() == 0 )
		{
			return true;			
		}
		
		return false;
	}
	
	//Check if object is in animation phase
	bool IsInAnimPhase( string anim_phase )
	{
		if ( GetAnimationPhase ( anim_phase ) == 0 )
		{
			return true;
		}
		
		return false;
	}
	
	//Action condition for building oven
	bool CanBuildOven()
	{
		ItemBase attached_item = ItemBase.Cast( GetAttachmentByType( ATTACHMENT_STONES ) );
		if ( attached_item )
		{
			float item_quantity = attached_item.GetQuantity();
			
			if ( !IsOven() && !IsBurning() && item_quantity >= MIN_STONES_TO_BUILD_OVEN && !IsItemTypeAttached( ATTACHMENT_TRIPOD ) )
			{
				return true;
			}
		}
	
		return false;
	}
	
	//Action condition for dismantling oven
	bool CanDismantleOven()
	{
		if ( IsOven() && !IsBurning() && !GetCookingEquipment() && GetTemperature() <= MAX_TEMPERATURE_TO_DISMANTLE_OVEN )
		{
			return true;
		}
		
		return false;
	}
	
	bool CanCookOnStick()
	{
		if ( GetTemperature() >= PARAM_COOKING_TEMP_THRESHOLD )
		{
			return true;
		}
		
		return false;
	}
	
	//Can extinguish fire
	bool CanExtinguishFire()
	{
		return IsBurning();
	}
	
	FireplaceLight GetLightEntity()
	{
		return m_Light;
	}
	
	void SetLightEntity( FireplaceLight light )
	{
		m_Light = light;
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementComplete( Man player )
	{		
		super.OnPlacementComplete( player );
			
		PlayerBase player_base = PlayerBase.Cast( player );
		vector position = player_base.GetLocalProjectionPosition();
		vector orientation = player_base.GetLocalProjectionOrientation();
		
		if ( GetGame().IsMultiplayer()  &&  GetGame().IsServer() || !GetGame().IsMultiplayer() )
		{
			//remove grass
			Object cc_object = GetGame().CreateObject ( OBJECT_CLUTTER_CUTTER , position );
			cc_object.SetOrientation ( orientation );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( GetGame().ObjectDelete, 1000, false, cc_object );
			
			SetIsPlaceSound( true );
		}
	}
	
	override string GetPlaceSoundset()
	{
		return "placeFireplace_SoundSet";
	}
	
	//================================================================
	// QUANITTY
	//================================================================
	// calculates and sets total energy based on possible (fuel/kinidling) item attachments
	protected void CalcAndSetTotalEnergy()
	{
		if ( GetGame() && GetGame().IsServer() )
		{
			m_TotalEnergy = 0;
			
			for ( int i = 0; i < m_FireConsumableTypes.Count(); ++i )
			{
				typename key = m_FireConsumableTypes.GetKey( i );
				FireConsumableType fire_consumable_type = m_FireConsumableTypes.Get( key );
				string qt_config_path = "CfgVehicles" + " " + fire_consumable_type.GetItemType().ToString() + " " + "varQuantityMax";
				string sm_config_path = "CfgSlots" + " " + "Slot_" + fire_consumable_type.GetAttSlot() + " " + "stackMax";
				if ( GetGame().ConfigIsExisting( qt_config_path ) )
				{
					float quantity_max = GetGame().ConfigGetFloat( qt_config_path );
				}
				
				if ( GetGame().ConfigIsExisting( sm_config_path ) )
				{
					float stack_max = GetGame().ConfigGetFloat( sm_config_path );
				}			
				
				//debug
				//Print( fire_consumable_type.GetItemType().ToString() + " quantity_max = " + quantity_max.ToString() + " [" + (quantity_max*fire_consumable_type.GetEnergy()).ToString()  + "] | stack_max = " + stack_max.ToString() + " [" + (stack_max*fire_consumable_type.GetEnergy()).ToString() + "]" );
				
				if ( stack_max > 0 )
				{
					m_TotalEnergy += stack_max * fire_consumable_type.GetEnergy();
				}
				else
				{
					m_TotalEnergy += quantity_max * fire_consumable_type.GetEnergy();
				}
			}
			
			//debug
			//Print( "Total energy = " + m_TotalEnergy.ToString() );
		}
	}
	
	// calculates and sets current quantity based on actual (fuel/kinidling) item attachments
	protected void CalcAndSetQuantity()
	{
		if ( GetGame() && GetGame().IsServer() )
		{
			float remaining_energy;
			
			for ( int i = 0; i < m_FireConsumables.Count(); ++i )
			{
				ItemBase key = m_FireConsumables.GetKey( i );
				FireConsumable fire_consumable = m_FireConsumables.Get( key );
				
				float quantity = fire_consumable.GetItem().GetQuantity();
				
				if ( quantity > 0 )
				{
					remaining_energy += ( ( quantity - 1 ) * fire_consumable.GetEnergy() ) + fire_consumable.GetRemainingEnergy();
					//Print( fire_consumable.GetItem().GetType() + " remaining energy = " + ( ( ( quantity - 1 ) * fire_consumable.GetEnergy() ) + fire_consumable.GetRemainingEnergy() ).ToString() );
				}
				else
				{
					remaining_energy += fire_consumable.GetRemainingEnergy();
					//Print( fire_consumable.GetItem().GetType() + " remaining energy = " + ( fire_consumable.GetRemainingEnergy().ToString() ) );
				}
			}
			
			SetQuantity( remaining_energy / m_TotalEnergy * GetQuantityMax() );
		}
	}
	
	override void OnAttachmentQuantityChanged( ItemBase item )
	{
		super.OnAttachmentQuantityChanged( item );
		
		CalcAndSetQuantity();
	}	
}
