class PlayerConstants 
{
	static const float WEAPON_RAISE_BLEND_DELAY = 0.136;
	static const float MELEE2_MOVEMENT_BLEND_DELAY = 0.35;
	//----------------------------------------------------------
	//				SHOES DAMAGE/FEET BLEEDING
	//----------------------------------------------------------
	static const float BAREFOOT_MOVEMENT_BLEED_MODIFIER = 0.1;
	static const float SHOES_MOVEMENT_DAMAGE_PER_STEP = 0.035;
	static const int CHECK_EVERY_N_STEP = 10;//will process every n-th step(for performance reasons)
	//----------------------------------------------------------
	//					STAT LEVELS START
	//----------------------------------------------------------
	static const float SL_HEALTH_CRITICAL = 15;
	static const float SL_HEALTH_LOW = 30;
	static const float SL_HEALTH_NORMAL = 50;
	static const float SL_HEALTH_HIGH = 80;	
	
	static const float SL_TOXICITY_CRITICAL = 20;
	static const float SL_TOXICITY_LOW = 40;
	static const float SL_TOXICITY_NORMAL = 60;
	static const float SL_TOXICITY_HIGH = 80;

	static const float SL_BLOOD_CRITICAL = 3000;
	static const float SL_BLOOD_LOW = 3500;
	static const float SL_BLOOD_NORMAL = 4000;
	static const float SL_BLOOD_HIGH = 4500;
	
	static const float SL_ENERGY_CRITICAL = 0;
	static const float SL_ENERGY_LOW = 200;
	static const float SL_ENERGY_NORMAL = 400;
	static const float SL_ENERGY_HIGH = 4000;	// max is 20000 (playerstats)
	
	static const float SL_WATER_CRITICAL = 0;
	static const float SL_WATER_LOW = 300;
	static const float SL_WATER_NORMAL = 600;
	static const float SL_WATER_HIGH = 2400;	// max is 5000 (playerstats)
	//----------------------------------------------------------
	//						STAT LEVELS END
	//----------------------------------------------------------

	//-------------------------------------------------------
	static const float NORMAL_TEMPERATURE_L = 35.2;
	static const float NORMAL_TEMPERATURE_H = 36.8;
	static const float HIGH_TEMPERATURE_L 	= 38.5;
	static const float HIGH_TEMPERATURE_H	= 39.9;
	//-------------------------------------------------------
	static const float STOMACH_ENERGY_TRANSFERED_PER_SEC 		= 3;	//amount of kcal transfered to energy per second(this should ideally be higher than what player burns under high metabolic load[sprint])
	static const float STOMACH_WATER_TRANSFERED_PER_SEC 		= 6;	//amount of ml transfered to water per second(this should ideally be higher than what player burns under high metabolic load[sprint])
	static const float STOMACH_SOLID_EMPTIED_PER_SEC 			= 7;	//amount of g/ml emptied from stomach per second

	static const float LOW_WATER_THRESHOLD 						= PlayerConstants.SL_WATER_LOW;	//threshold from which water affects health

	static const float LOW_ENERGY_THRESHOLD 					= 200;	//threshold from which energy affects health

	//--------------------------------------------------------
	static const float METABOLIC_SPEED_ENERGY_BASAL		= 0.01;		//energy loss per second while idle
	
	static const float METABOLIC_SPEED_ENERGY_WALK		= 0.08;		//energy loss per second
	static const float METABOLIC_SPEED_ENERGY_JOG		= 0.3;		//energy loss per second
	static const float METABOLIC_SPEED_ENERGY_SPRINT	= 0.6;		//energy loss per second
	
	static const float METABOLIC_SPEED_WATER_BASAL		= 0.02;		//water loss per second while idle
	
	static const float METABOLIC_SPEED_WATER_WALK		= 0.08;		//water loss per second
	static const float METABOLIC_SPEED_WATER_JOG		= 0.3;		//water loss per second
	static const float METABOLIC_SPEED_WATER_SPRINT		= 0.5;		//water loss per second
	//--------------------------------------------------------
	
	static const float	THRESHOLD_HEAT_COMFORT_PLUS_WARNING		= 0.2;	//missing comment
	static const float	THRESHOLD_HEAT_COMFORT_PLUS_CRITICAL 	= 0.5;	//missing comment
	static const float	THRESHOLD_HEAT_COMFORT_PLUS_EMPTY		= 0.9;	//missing comment

	static const float	THRESHOLD_HEAT_COMFORT_MINUS_WARNING	= -0.3;	//missing comment
	static const float	THRESHOLD_HEAT_COMFORT_MINUS_CRITICAL	= -0.5;	//missing comment
	static const float	THRESHOLD_HEAT_COMFORT_MINUS_EMPTY		= -0.9;	//missing comment

	//--------------------------------------------------------
	static const int BLOOD_THRESHOLD_FATAL 					= 2500;	//fatal blood level
	
	static const float BLOOD_REGEN_RATE_PER_SEC				= 0.3; 	//base amount of blood regenerated per second
	static const float DAMAGE_ZONE_BLOOD_REGEN_MODIFIER 	= 0.7;
	
	static const float BLOOD_REGEN_MODIFIER_ENERGY_LOW		= 0; 	//multiplier for blood regen rate 
	static const float BLOOD_REGEN_MODIFIER_ENERGY_MID		= 0.5;
	static const float BLOOD_REGEN_MODIFIER_ENERGY_HIGH		= 1;
	
	static const float BLOOD_REGEN_MODIFIER_WATER_LOW		= 0; 	//multiplier for blood regen rate (BLOOD_REGEN_MULTIPLIER_WATER_LOW ?)
	static const float BLOOD_REGEN_MODIFIER_WATER_MID		= 0.5;
	static const float BLOOD_REGEN_MODIFIER_WATER_HIGH		= 1;
	
	static const float SALINE_BLOOD_REGEN_PER_SEC			= 3;	//boost for blood regen per second, independent on BLOOD_REGEN_SPEED
	static const float SALINE_LIQUID_AMOUNT					= 500;
	static const float SALINE_WATER_REGEN_PER_SEC 			= 2.1;
	
	static const float HEMOLYTIC_BLOOD_DRAIN_PER_SEC		= 7;	//hemolytic reaction blood drain per second
	static const float HEMOLYTIC_BLOODLOSS_AMOUNT			= 500;
	static const float HEMOLYTIC_RISK_SHOCK_THRESHOLD		= 75;	// amount of blood from transfusion causing player character going into shock
	static const float HEMOLYTIC_REACTION_THRESHOLD			= 175;	// amount of blood from transfusion triggering hemolytic reaction
	
	static const float WATER_LOSS_THRESHOLD_HC_PLUS_LOW		= THRESHOLD_HEAT_COMFORT_PLUS_WARNING;
	static const float WATER_LOSS_THRESHOLD_HC_PLUS_HIGH	= THRESHOLD_HEAT_COMFORT_PLUS_CRITICAL;
	
	static const float ENERGY_LOSS_THRESHOLD_HC_MINUS_LOW	= THRESHOLD_HEAT_COMFORT_MINUS_WARNING;
	static const float ENERGY_LOSS_THRESHOLD_HC_MINUS_HIGH	= THRESHOLD_HEAT_COMFORT_MINUS_CRITICAL;
	
	static const float WATER_LOSS_HC_PLUS_LOW				= 0;
	static const float WATER_LOSS_HC_PLUS_HIGH				= 0.4;

	static const float ENERGY_LOSS_HC_MINUS_LOW				= 0.2;
	static const float ENERGY_LOSS_HC_MINUS_HIGH			= 0.45;
	
	static const float HEALTH_LOSS_HC_PLUS_LOW				= 0.05;
	static const float HEALTH_LOSS_HC_PLUS_HIGH				= 0.15;		
	
	static const float HEALTH_LOSS_HC_MINUS_LOW				= 0.05;
	static const float HEALTH_LOSS_HC_MINUS_HIGH 			= 0.15;	
	
	static const float WATER_LOSS_FEVER						= 0.2;
	
	//--------------------------------------------------------
	static const float LOW_ENERGY_DAMAGE_PER_SEC			= 0.125;	//health loss per second while low on energy
	static const float LOW_WATER_DAMAGE_PER_SEC				= 0.2;		//health loss per second while low on water
	
	static const float HEALTH_REGEN_MIN						= 0.005;	//health regen rate at BLOOD_THRESHOLD_FATAL blood level
	static const float HEALTH_REGEN_MAX						= 0.03;		//health regen rate at MAXIMUM blood level
	
	static const float LEG_HEALTH_REGEN						= 1;		//Leg health regen when leg is NOT BROKEN
	static const float LEG_HEALTH_REGEN_BROKEN				= 0.18;		//Leg health regen when BROKEN OR SPLINTED
	
	static const float UNCONSCIOUS_THRESHOLD				= 25.0;		//player goes unconscious when we get under this threshold
	static const float CONSCIOUS_THRESHOLD					= 50.0;		//player regains consciousness when he gets above this threshold
	
	static const float SHOCK_REFILL_CONSCIOUS_SPEED			= 5;		//shock refill speed when the player is conscious
	static const float SHOCK_REFILl_UNCONSCIOUS_SPEED		= 1;		//shock refill speed when the player is unconscious
	
	static const float SHOCK_DAMAGE_BLOOD_THRESHOLD_HIGH	= 3000;		// we start dealing shock damage over time when we get at this value or lower
	static const float SHOCK_DAMAGE_BLOOD_THRESHOLD_LOW		= 2500; 	// the closer we get to this value, the higher the over time shock damage we deal
	
	static const float SHOCK_DAMAGE_HIGH					= 5.5; 		// shock damage per second when the blood is near the upper blood threshold
	static const float SHOCK_DAMAGE_LOW						= 6.25; 		// shock damage per second when the blood is near the lower blood threshold
	
	static const float SHOCK_REFILL_COOLDOWN_AFTER_HIT 		= 15; 		// duration of cooldown during which shock regeneration is paused
	
	static const float UNCONSCIOUS_IN_WATER_TIME_LIMIT_TO_DEATH	= 20;	// how long can player survive while unconscious when in water in secs 
	//----------------------------------------------------------
	static const float BLEEDING_SOURCE_BLOODLOSS_PER_SEC 	= -24; 		// amount of blood loss per second from one bleeding source 
	static const float BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM = 0.6; 		// modifier of the bloodloss given by BLEEDING_SOURCE_BLOODLOSS_PER_SEC, multiplying these two will give the resulting bloodloss
	static const float BLEEDING_SOURCE_FLOW_MODIFIER_LOW	= 0.1; 		// modifier of the bloodloss given by BLEEDING_SOURCE_BLOODLOSS_PER_SEC, multiplying these two will give the resulting bloodloss
	static const int BLEEDING_SOURCE_DURATION_NORMAL = 300; 			// in seconds, how long will bleeding source exist until disapearing
	static const float BLEEDING_LOW_PRESSURE_BLOOD = 4000.0;			// from which blood level we start lowering BLEEDING_SOURCE_BLOODLOSS_PER_SEC
	static const float BLEEDING_LOW_PRESSURE_MIN_MOD = 0.3;				// minimal value for low pressure bleeding (lowest possible multiplier of BLEEDING_SOURCE_BLOODLOSS_PER_SEC)
	
	 
	//----------------------------------------------------------
	static const float BREATH_VAPOUR_THRESHOLD_HIGH 		= -5.0; 	//missing comment
	static const float BREATH_VAPOUR_THRESHOLD_LOW 			= 7.0; 		//missing comment
	//----------------------------------------------------------
	static const float IMMUNITY_THRESHOLD_LEVEL_HIGH = 0.95;
	static const float IMMUNITY_THRESHOLD_LEVEL_NORMAL = 0.65;
	static const float IMMUNITY_THRESHOLD_LEVEL_LOW = 0.35;
	static const float IMMUNITY_THRESHOLD_LEVEL_CRITICAL = 0.15;
	//----------------------------------------------------------
	static const float VITAMINS_LIFETIME_SECS				= 300;

	static const float CHANCE_TO_BLEED_SLIDING_LADDER_PER_SEC = 0.3; // probability of bleeding source occuring while sliding down ladder without gloves given as percentage per second(0.5 means 50% chance bleeding source will happen every second while sliding down) 
	static const float GLOVES_DAMAGE_SLIDING_LADDER_PER_SEC = -3;// how much damage the gloves receive while sliding down the ladder (per sec)
	
	//----------------------------------------------------------
	//						BADGE THRESHOLDS
	//----------------------------------------------------------
	static const int BT_STOMACH_VOLUME_LVL3 = 1500;
	static const int BT_STOMACH_VOLUME_LVL2 = 750;
	static const int BT_STOMACH_VOLUME_LVL1 = 1;

	//!
	static const int LAST_UA_MSG_LIFETIME = 30;						//! last User Action message lifetime [s] (default: 30s)
	
	//!
	const int	 	VOMIT_THRESHOLD 			= 2000;
	
	static const float 	CORPSE_THRESHOLD_MEDIUM = 0.7; //0.7
	static const float 	CORPSE_THRESHOLD_DECAYED = 0.3; //0.3
	
	static const int 	CORPSE_STATE_FRESH = 0;
	static const int 	CORPSE_STATE_MEDIUM = 1;
	static const int 	CORPSE_STATE_DECAYED = 2;
	//----------------------------------------------------------
	static const float 	CAMERA_THRESHOLD_PITCH = -70.0;
	
	//----------------------------------------------------------
	//						BROKEN LEGS SHOCK
	//----------------------------------------------------------
	static const float 	BROKEN_LEGS_INITIAL_SHOCK = 20;				//Inflicted shock on modifier start
	static const float 	BROKEN_LEGS_LOW_SHOCK_WALK = 4;				//Inflicted shock on modifier update with almost healthy legs 
	static const float 	BROKEN_LEGS_MID_SHOCK_WALK = 6;				//Inflicted shock on modifier update with mid health legs
	static const float 	BROKEN_LEGS_HIGH_SHOCK_WALK = 8;			//Inflicted shock on modifier update with low health legs
	static const float 	BROKEN_LEGS_SHOCK_SWIM = 2;					//Inflicted shock on modifier update when swimming
	static const float 	BROKEN_LEGS_LIGHT_MELEE_SHOCK = 20; 		//Inflicted shock per light weapon swing
	static const float 	BROKEN_LEGS_HEAVY_MELEE_SHOCK = 35; 		//Inflicted shock per heavy weapon swing
	static const float	BROKEN_LEGS_LOW_HEALTH_THRESHOLD = 25;		//Amount of health BELOW which legs have "low health"
	static const float	BROKEN_LEGS_HIGH_HEALTH_THRESHOLD = 75;		//Amount of health OVER which legs have "low health"
	//static const int	BROKEN_LEGS_FALL_STEP_COUNT = 10;			//Number of steps before falling over
	static const float	BROKEN_LEGS_STAND_SHOCK = 0;				//Shock dealt when standing with broken legs
	static const float	BROKEN_LEGS_ROLL_SHOCK = 10;				//Shock dealt when rolling with broken legs
}