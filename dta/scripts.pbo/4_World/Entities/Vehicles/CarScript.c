enum CarDoorState
{
	DOORS_MISSING,
	DOORS_OPEN,
	DOORS_CLOSED
}

/*!
	Base script class for all motorized wheeled vehicles.
*/
class CarScript extends Car
{
#ifndef OLD_ACTIONS
	static ref map<typename, ref TInputActionMap> m_CarTypeActionsMap = new map<typename, ref TInputActionMap>;
	TInputActionMap m_InputActionMap;
	bool	m_ActionsInitialize;
#endif
	protected float m_Time;

	//! keeps ammount of each fluid
	protected float m_FuelAmmount;
	protected float m_CoolantAmmount;
	protected float m_OilAmmount;
	protected float m_BrakeAmmount;

	//!
	protected float m_dmgContactCoef;
	protected float m_enviroCoef;

	//!
	protected float m_EngineHealth;
	protected float m_RadiatorHealth;
	protected float m_FuelTankHealth;
	protected float m_BatteryHealth;
	protected float m_PlugHealth;

	//! Particles
	protected ref EffVehicleSmoke m_coolantFx;
	protected ref EffVehicleSmoke m_engineFx;
	protected ref EffVehicleSmoke m_exhaustFx;
		
	protected int m_enginePtcFx;
	protected int m_coolantPtcFx;
	protected int m_exhaustPtcFx;
	
	protected vector m_exhaustPtcPos;
	protected vector m_exhaustPtcDir;
	protected vector m_enginePtcPos;
	protected vector m_coolantPtcPos;
	
	protected vector m_fuelPos;
	
	//!Sounds
	protected bool m_PlayCrashSoundLight;
	protected bool m_PlayCrashSoundHeavy;
	
	void CarScript()
	{
		SetEventMask(/*EntityEvent.CONTACT |*/ EntityEvent.POSTSIMULATE);

		m_Time = 0;

		// sets max health for all components at init
		m_EngineHealth = 1;
		m_FuelTankHealth = 1;
		m_RadiatorHealth = -1;
		m_BatteryHealth = -1;
		m_PlugHealth = -1;

		m_enginePtcFx = -1;
		m_coolantPtcFx = -1;
		m_exhaustPtcFx = -1;

		m_dmgContactCoef = 0;
		m_enviroCoef = 0;

		m_PlayCrashSoundLight = false;
		m_PlayCrashSoundHeavy = false;
		
		RegisterNetSyncVariableBool("m_PlayCrashSoundLight");
		RegisterNetSyncVariableBool("m_PlayCrashSoundHeavy");
		
		if 	( MemoryPointExists("ptcExhaust_end") )
		{
			//Print( "CarScript Init " + GetType() );
			m_exhaustPtcPos = GetMemoryPointPos("ptcExhaust_end");
			if ( MemoryPointExists("ptcExhaust_start") )
			{
				vector exhaustStart = GetMemoryPointPos("ptcExhaust_start");
				vector tempOri = vector.Direction( exhaustStart, m_exhaustPtcPos);//.Normalized();//.VectorToAngles();
				
				//m_exhaustPtcDir = tempOri;

				m_exhaustPtcDir[0] = -tempOri[2];
				m_exhaustPtcDir[1] = tempOri[1];
				m_exhaustPtcDir[2] = tempOri[0];
				
				m_exhaustPtcDir = m_exhaustPtcDir.Normalized().VectorToAngles();

			}
		}
		else
		{
			m_exhaustPtcPos = "0 0 0";
			m_exhaustPtcDir = "1 1 1";
		}
	
		if 	( MemoryPointExists("ptcEnginePos") )
			m_enginePtcPos = GetMemoryPointPos("ptcEnginePos");
		else
			m_enginePtcPos = "0 0 0";		

		
		if 	( MemoryPointExists("ptcCoolantPos") )
			m_coolantPtcPos = GetMemoryPointPos("ptcCoolantPos");
		else
			m_coolantPtcPos = "0 0 0";

		if 	( MemoryPointExists("refill") )
			m_fuelPos = GetMemoryPointPos("refill");
		else
			m_fuelPos = "0 0 0";
		
#ifndef OLD_ACTIONS
		m_ActionsInitialize = false;
#endif
	}

	vector GetCoolantPtcPosWS()
	{
		return ModelToWorld( m_coolantPtcPos );
	}

	vector GetRefillPointPosWS()
	{	
		return ModelToWorld( m_fuelPos );
	}
	
/*
	//here we should handle the damage dealt in OnContact event, but maybe we will react even in that event 
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos)
	{
		Print("CarScript>>> EEHitBy");
		Print( dmgZone );
		Print( damageResult );
		Print( source );
		Print( component );
		Print( damageResult.GetDamage(dmgZone, "Health") );

		//if ( dmgZone == "Engine" && GetHealth("Engine","") < 0.1 )
		//{
		//	if ( GetHealth01("engine", "") <= 0.1 )
		//	{
		//		if ( !m_EngineSmoke )
		//		{
		//			Print("Smoke");
		//			EffVehicleSmoke engSmk = new EffEngineSmoke();
		//			SEffectManager.PlayOnObject(engSmk, this, "0 0.95 1.25" );
		//			// Particle is now playing on oject 'this'
		//		}
		//	}
		//}

	}
*/	

	override void EEDelete(EntityAI parent)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( SEffectManager.IsEffectExist( m_coolantPtcFx ) )
				SEffectManager.Stop(m_coolantPtcFx);

			if ( SEffectManager.IsEffectExist( m_exhaustPtcFx ) )
				SEffectManager.Stop( m_exhaustPtcFx );

			if ( SEffectManager.IsEffectExist( m_enginePtcFx ) )
				SEffectManager.Stop( m_enginePtcFx );
		}
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
				
		if ( GetCrashHeavySound() )
			PlayCrashHeavySound();
		else if ( GetCrashLightSound() )
			PlayCrashLightSound();
	}
	
	override void EEItemAttached ( EntityAI item, string slot_name ) 
	{
		super.EEItemAttached( item, slot_name );
		if ( GetGame().IsServer() )
		{
			if ( slot_name == "Reflector_1_1" )
				SetHealth( "Reflector_1_1", "Health", item.GetHealth() );

			if ( slot_name == "Reflector_2_1" )
				SetHealth( "Reflector_2_1", "Health", item.GetHealth() );

			if ( slot_name == "CarBattery" )
				m_BatteryHealth = item.GetHealth01();
					
			if ( slot_name == "TruckBattery" )
				m_BatteryHealth = item.GetHealth01();

			if ( slot_name == "SparkPlug" )
				m_PlugHealth = item.GetHealth01();
			
			if ( slot_name == "GlowPlug" )
				m_PlugHealth = item.GetHealth01();
			
			Synchronize();
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		if ( GetGame().IsServer() )
		{
			//int slot_id = InventorySlots.GetSlotIdFromString(slot_name);
			if ( IsLightsOn() )
			{
				if ( slot_name == "CarBattery" || slot_name == "TruckBattery" )
					SwitchLights();

				if ( slot_name == "Reflector_1_1" )
				{
					SetHealth( "Reflector_1_1", "Health", 0 );
				
					item = FindAttachmentBySlotName( "Reflector_2_1" );
					if ( !item || GetHealth01("Reflector_2_1", "") <= 0 )
						SwitchLights();
				}

				if ( slot_name == "Reflector_2_1" )
				{
					SetHealth( "Reflector_2_1", "Health", 0 );

					item = FindAttachmentBySlotName( "Reflector_1_1" );
					if ( !item || GetHealth01("Reflector_1_1", "") <= 0 )
						SwitchLights();
				}
			}

			if ( EngineIsOn() )
			{
				//EngineBelt
				if ( slot_name == "GlowPlug" || slot_name == "SparkPlug" || slot_name == "CarBattery" || slot_name == "TruckBattery" )
					EngineStop();
			}
			
			if ( slot_name == "CarBattery" )
				m_BatteryHealth = -1;
					
			if ( slot_name == "TruckBattery" )
				m_BatteryHealth = -1;

			if ( slot_name == "SparkPlug" )
				m_PlugHealth = -1;
			
			if ( slot_name == "GlowPlug" )
				m_PlugHealth = -1;

			if ( slot_name == "CarRadiator" )
			{
				LeakAll( CarFluid.COOLANT );
				SetHealth( "Radiator", "Health", 0);
			}

			Synchronize();
		}
	}
	
	override bool CanReleaseAttachment( EntityAI attachment )
	{

		if ( GetSpeedometer() > 0.5 )
			return false;

		//GetInventoryOwner()
				
		//if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() )
		//{
			for( int i =0; i < CrewSize(); i++ )
			{
				Human crew = CrewMember( i );
				if ( !crew )
					continue;

				PlayerBase player;
				if ( Class.CastTo(player, crew ) )
					return false;
			}
		//}
		
		return true;
	}

	override void EOnPostSimulate(IEntity other, float timeSlice)
	{
		m_Time += timeSlice;

		//! move it to constants.c const float CAR_UPDATE_INTERVAL = 1.0
		if ( m_Time >= CARS_FLUIDS_TICK )
		{
			m_Time = 0;

			CarPartsHealthCheck();

			//First of all check if the car should stop the engine
			if ( GetGame().IsServer() && EngineIsOn() )
			{
				if ( GetFluidFraction(CarFluid.FUEL) <= 0 || m_EngineHealth <= 0 )
					EngineStop();

				CheckVitalItem( IsVitalCarBattery(), "CarBattery" );
				CheckVitalItem( IsVitalTruckBattery(), "TruckBattery" );
				CheckVitalItem( IsVitalSparkPlug(), "SparkPlug" );
				CheckVitalItem( IsVitalGlowPlug(), "GlowPlug" );
				// engine belt is not needed right now
				//CheckVitalItem( IsVitalEngineBelt(), "EngineBelt" );
			}

			//! actions runned when the engine on
			if ( EngineIsOn() )
			{
				if ( GetGame().IsServer() )
				{
					float dmg;

					float test1 = EngineGetRPM();
					float test2 = EngineGetRPMRedline();
					
					if ( EngineGetRPM() >= EngineGetRPMRedline() )
					{
						if ( EngineGetRPM() > EngineGetRPMMax() )
							AddHealth( "Engine", "Health", -GetMaxHealth("Engine", "")); //CAR_RPM_DMG
							
						dmg = EngineGetRPM() * 0.001 * Math.RandomFloat( 0.02, 1.0 );  //CARS_TICK_DMG_MIN; //CARS_TICK_DMG_MAX
						//AddHealth( "Engine", "Health", -dmg); //CAR_RPM_DMG
						ProcessDirectDamage( 3, null, "Engine", "EnviroDmg", "0 0 0", dmg );
					}

					//! leaking of coolant from radiator when damaged
					if ( IsVitalRadiator() )
					{
						if ( GetFluidFraction(CarFluid.COOLANT) > 0 && m_RadiatorHealth < 0.5 ) //CARS_LEAK_THRESHOLD
							LeakFluid( CarFluid.COOLANT );
					}

					if ( GetFluidFraction(CarFluid.FUEL) > 0 && m_FuelTankHealth < 0.5 )
						LeakFluid( CarFluid.FUEL );

					if ( GetFluidFraction(CarFluid.BRAKE) > 0 && m_EngineHealth < 0.5 )
						LeakFluid( CarFluid.BRAKE );

					if ( GetFluidFraction(CarFluid.OIL) > 0 && m_EngineHealth < 0.5 )
						LeakFluid( CarFluid.OIL );

					if ( m_EngineHealth < 0.25 )
						LeakFluid( CarFluid.OIL );
/*Commented out till indicator of Oil in HUD will be ready
					if ( GetFluidFraction( CarFluid.OIL ) < 1 )
					{
						dmg = Math.Lerp( 0.02, 10, 1 - GetFluidFraction( CarFluid.OIL ) );  //CARS_TICK_DMG_MIN; //CARS_TICK_DMG_MAX
						AddHealth( "Engine", "Health", -dmg);
					}
*/
					if ( IsVitalRadiator() )
					{
						if ( GetFluidFraction( CarFluid.COOLANT ) < 0.5 && GetFluidFraction( CarFluid.COOLANT ) >= 0 )
						{
							dmg = ( 1 - GetFluidFraction(CarFluid.COOLANT) ) * Math.RandomFloat( 0.02, 10.00 );  //CARS_DMG_TICK_MIN_COOLANT; //CARS_DMG_TICK_MAX_COOLANT
							AddHealth( "Engine", "Health", -dmg );
						}
					}
				}
				
				//FX only on Client and in Single
				if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
				{
					if ( !SEffectManager.IsEffectExist( m_exhaustPtcFx ) )
					{
						m_exhaustFx = new EffExhaustSmoke();
						m_exhaustPtcFx = SEffectManager.PlayOnObject( m_exhaustFx, this, m_exhaustPtcPos, m_exhaustPtcDir );
					}

					m_exhaustFx.SetParticleStateLight();
				
					if ( IsVitalRadiator() && SEffectManager.IsEffectExist( m_coolantPtcFx ) )
						SEffectManager.Stop(m_coolantPtcFx);
					
					if ( IsVitalRadiator() && GetFluidFraction( CarFluid.COOLANT ) < 0.5 )
					{
						if ( !SEffectManager.IsEffectExist( m_coolantPtcFx ) )
						{
							m_coolantFx = new EffCoolantSteam();
							m_coolantPtcFx = SEffectManager.PlayOnObject( m_coolantFx, this, m_coolantPtcPos, Vector(0,0,0), true );
						}

						if ( GetFluidFraction( CarFluid.COOLANT ) > 0 )
							m_coolantFx.SetParticleStateLight();
						else
							m_coolantFx.SetParticleStateHeavy();
/*
						Particle ptc;
						if ( GetCarDoorsState("NivaHood") == CarDoorState.DOORS_CLOSED )
						{
							if ( Class.CastTo(ptc, m_coolantFx.GetParticle() ) )
							{
								ptc.SetParameter( -1, EmitorParam.AIR_RESISTANCE, 55 );
								ptc.SetParameter( -1, EmitorParam.SIZE, 0.05 );
							}
						}
						else
						{
							if ( Class.CastTo(ptc, m_coolantFx.GetParticle() ) )
							{
								ptc.SetParameter( -1, EmitorParam.AIR_RESISTANCE, 2 );
								ptc.SetParameter( -1, EmitorParam.SIZE, 0.5 );
							}
						}
*/
					}
					else
					{
						if ( SEffectManager.IsEffectExist( m_coolantPtcFx ) )
							SEffectManager.Stop(m_coolantPtcFx);
					}
				}
			}
			else
			{
				//FX only on Client and in Single
				if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
				{
					if ( SEffectManager.IsEffectExist( m_exhaustPtcFx ) )
						SEffectManager.Stop(m_exhaustPtcFx);
					
					if ( SEffectManager.IsEffectExist( m_coolantPtcFx ) )
						SEffectManager.Stop(m_coolantPtcFx);
				}
			}
		}

		//FX only on Client and in Single
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( IsDamageDestroyed() )
			{
				if ( !SEffectManager.IsEffectExist( m_enginePtcFx ) )
				{
					m_engineFx = new EffEngineSmoke();
					m_enginePtcFx = SEffectManager.PlayOnObject( m_engineFx, this, m_enginePtcPos, Vector(0,0,0), true );
					//m_engineFx.SetParticleStateLight();
					m_engineFx.SetParticleStateHeavy();
				}
			}
		}
	}

	override void OnContact( string zoneName, vector localPos, IEntity other, Contact data )
	{

		if ( zoneName == "" )
		{
			Print("CarScript >> ERROR >> OnContact dmg zone not defined!");
			return;
		}
		
		switch( zoneName )
		{
/*
			case "dmgZone_lightsLF":
				//Print("dmgZone_lightsLF");
			break;
			
			case "dmgZone_lightsRF":
				//Print("dmgZone_lightsRF");
			break;
*/
			default:
				if ( GetGame().IsServer() && zoneName != "")
				{
					float dmgMin = 150.0;	
					float dmgThreshold = 750.0;
					float dmgKillCrew = 3000.0;
					float dmg = data.Impulse * m_dmgContactCoef;

					if ( dmg < dmgThreshold )
					{					
						if ( dmg > dmgMin )
						{
							//Print( GetType() + " >>> " + " smlHit >>> " + "zoneName: "  + zoneName + " >>> - " + dmg.ToString() + " HP >>> in " + GetSpeedometer() + " km/h");
							AddHealth( zoneName, "Health", -dmg);
							//m_PlayCrashSoundLight = true;
							SynchCrashLightSound( true );
						}
					}
					else
					{
						//Print( GetType() + " >>> " + " BIGHit >>> " + "zoneName: " + zoneName + " >>> - " + dmg.ToString() + " HP >>> in " + GetSpeedometer() + " km/h" );
						for( int i =0; i < CrewSize(); i++ )
						{
							Human crew = CrewMember( i );
							if ( !crew )
								continue;

							PlayerBase player;
							if ( Class.CastTo(player, crew ) )
							{
								if ( dmg > dmgKillCrew )
								{		
									player.SetHealth(0.0);
								}
								else
								{
									//deal shock to player
									float shockTemp = Math.InverseLerp(dmgThreshold, dmgKillCrew, dmg);
									float shock = Math.Lerp( 50, 100, shockTemp );

									player.AddHealth("", "Shock", -shock );
									//Print( "SHOCK..........." + shock );
								}
							}
						}

						//m_PlayCrashSoundHeavy = true;
						SynchCrashHeavySound( true );
						ProcessDirectDamage( 3, null, zoneName, "EnviroDmg", "0 0 0", dmg );
					}
				}
			break;
		}
	}

	/*!
		Gets called every sound simulation step.
		In this callback, user can modify behaviour of sound controllers
	*/
	override float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		if ( GetGame().IsServer() )
		{
			if ( GetCrashLightSound() )
				m_PlayCrashSoundLight = false;
		
			if ( GetCrashHeavySound() )
				m_PlayCrashSoundHeavy = false;
		}
		
		switch ( ctrl )
		{
			// in this controller the higher returned value the more muted sounds inside the car
			case CarSoundCtrl.DOORS:
				break;
		}

		// if you don't wanna change the behaviour, just return the old value.
		return oldValue;
	}
	
	float enviroCoef()
	{
		//range <-1;1> higher number, higher heatcomfort
		return m_enviroCoef;
	}

	/*!
		Gets called everytime when the specified vehicle's fluid
		changes its current value eg. when car is consuming fuel.

		This callback is called on both server and client.
	*/
	override void OnFluidChanged( CarFluid fluid, float newValue, float oldValue )
	{
		switch ( fluid )
		{
			case CarFluid.FUEL:
				m_FuelAmmount = newValue;
				break;

			case CarFluid.OIL:
				m_OilAmmount = newValue;
				break;

			case CarFluid.BRAKE:
				m_BrakeAmmount = newValue;
				break;

			case CarFluid.COOLANT:
				m_CoolantAmmount = newValue;
				break;
		}
	}

	/*!
		Gets called everytime the game wants to start the engine.
		This callback is called on server only.

		\return true if the engine can start, false otherwise.
	*/
	override bool OnBeforeEngineStart()
	{
		// todo :: check if the battery is plugged-in
		//         check if we have enough power to start the engine
/*
		if (  GetFluidFraction( CarFluid.FUEL ) <= 0 )
		{
			if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
				SEffectManager.PlaySound("offroad_engine_failed_start_fuel_SoundSet", GetPosition() );

			return false;
		}
		
		EntityAI item = null;
		//---------------
		if ( IsVitalCarBattery() )
		{
			item = FindAttachmentBySlotName("CarBattery");

			if ( !item || (item && item.IsRuined() ) )
			{
				if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
					SEffectManager.PlaySound("offroad_engine_failed_start_battery_SoundSet", GetPosition() );
				return false;
			}
		}

		//---------------
		item = null;
		if ( IsVitalTruckBattery() )
		{
			item = FindAttachmentBySlotName("TruckBattery");

			if ( !item || ( item && item.IsRuined() ) )
			{
				if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
					SEffectManager.PlaySound("offroad_engine_failed_start_battery_SoundSet", GetPosition() );
				return false;
			}
		}

		//---------------
		item = null;
		if ( IsVitalSparkPlug() )
		{
			item = FindAttachmentBySlotName("SparkPlug");

			if ( !item || ( item && item.IsRuined() ) )
			{
				if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
					SEffectManager.PlaySound("offroad_engine_failed_start_sparkplugs_SoundSet", GetPosition() );
				return false;
			}
		}
	
		//---------------
		item = null;
		if ( IsVitalGlowPlug() )
		{
			item = FindAttachmentBySlotName("GlowPlug");

			if ( !item || ( item && item.IsRuined() ) )
			{
				if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
					SEffectManager.PlaySound("offroad_engine_failed_start_sparkplugs_SoundSet", GetPosition() );
				return false;
			}
		}
		

		//TODO:: make it proper when the belt will be ready
		//item = null;
		//m_BeltCon = true;
		
		//if ( IsVitalEngineBelt() )
		//{
			//item = FindAttachmentBySlotName("EngineBelt");

			//if ( !item || (item && item.IsRuined() ) )
			//{
				//if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
					//SEffectManager.PlaySound("", GetPosition() );
				//return false;
			//}
		//}

*/
		return true;
	}

	//! Gets called everytime the engine starts.
	override void OnEngineStart()
	{
	}

	//! Gets called everytime the engine stops.
	override void OnEngineStop()
	{
/*
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{		
			EffectSound sound =	SEffectManager.PlaySound("offroad_engine_stop_fuel_SoundSet", GetPosition() );
			sound.SetSoundAutodestroy( true );
		}
*/
	}

	/*!
		Gets called everytime the game wants to switch the lights.
		\return true when lights can be switched, false otherwise.
	*/
	override bool OnBeforeSwitchLights( bool toOn )
	{
		if ( toOn )
		{
			// todo :: check if the battery is plugged-in
			//         check if we have enough power to turn on the lights

			// this is the case from off -> on
			
			EntityAI battery = null;
			
			EntityAI item1 = null;
			EntityAI item2 = null;
			
			
			if ( IsVitalCarBattery() ) battery = FindAttachmentBySlotName("CarBattery");
			if ( IsVitalTruckBattery() ) battery = FindAttachmentBySlotName("TruckBattery");
				
			if ( !battery || battery.IsRuined() )
				return false;
			
			item1 = FindAttachmentBySlotName("Reflector_1_1");
			item2 = FindAttachmentBySlotName("Reflector_2_1");
			
			if ( !item1 && !item2 )
				return false;
			else if ( item1 && item1.IsRuined() && item2 && item2.IsRuined() )
				return false;

/* 
			//Should be redundand with the check above (for the headlights)
			if ( GetHealthLevel( "Reflector_1_1" ) >= STATE_RUINED && GetHealthLevel( "Reflector_2_1" ) >= STATE_RUINED )
				return false;
*/
		}

		// this is the case on -> off
		return true;
	}

	protected void CheckVitalItem( bool isVital, string itemName )
	{
		if ( !isVital )
			return;

		EntityAI item = FindAttachmentBySlotName(itemName);

		if ( !item )
			EngineStop();
		else if ( item.IsRuined() )
			EngineStop();
	}

	protected void LeakFluid(CarFluid fluid)
	{
		float ammount = 0;
		
		switch (fluid)
		{
			case CarFluid.COOLANT:
				ammount = (1- m_RadiatorHealth) * Math.RandomFloat(0.02, 0.05);//CARS_LEAK_TICK_MIN; CARS_LEAK_TICK_MAX
				Leak(fluid, ammount);
			break;
			
			case CarFluid.OIL:
				ammount =  ( 1 - m_EngineHealth ) * Math.RandomFloat(0.02, 1.0);//CARS_LEAK_OIL_MIN; CARS_LEAK_OIL_MAX
				Leak(fluid, ammount);
			break;
			
			case CarFluid.FUEL:
				ammount = ( 1 - m_FuelTankHealth ) * Math.RandomFloat(0.02, 0.05);//CARS_LEAK_TICK_MIN; CARS_LEAK_TICK_MAX
				Leak(fluid, ammount);
			break;
		}
	}

	protected void CarPartsHealthCheck()
	{
		if ( GetGame().IsServer() )
		{
			ItemBase radiator;
			Class.CastTo( radiator, FindAttachmentBySlotName("CarRadiator"));
			if ( radiator )
			{
				m_RadiatorHealth = radiator.GetHealth01("", "");
			}
			else
			{
				m_RadiatorHealth = 0;
			}
			
			m_EngineHealth = GetHealth01("Engine", "");

			m_FuelTankHealth = GetHealth01("FuelTank", "");
		}
	}
	
	bool GetCrashLightSound()
	{
		return m_PlayCrashSoundLight;
	}
	
	void SynchCrashLightSound( bool play )
	{
		m_PlayCrashSoundLight = play;
		SetSynchDirty();
	}

	void PlayCrashLightSound()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{		
			EffectSound sound =	SEffectManager.PlaySound("offroad_hit_light_SoundSet", GetPosition() );
			sound.SetSoundAutodestroy( true );
		}
	}

	bool GetCrashHeavySound()
	{
		return m_PlayCrashSoundHeavy;
	}

	void SynchCrashHeavySound( bool play )
	{
		m_PlayCrashSoundHeavy = play;
		SetSynchDirty();
	}
	
	void PlayCrashHeavySound()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{		
			EffectSound sound =	SEffectManager.PlaySound("offroad_hit_heavy_SoundSet", GetPosition() );
			sound.SetSoundAutodestroy( true );
		}
	}
	
	string GetAnimSourceFromSelection( string selection )
	{
		return "";
	}

	string GetDoorConditionPointFromSelection( string selection )
	{
		switch( selection )
		{
			case "seat_driver":
				return "seat_con_1_1";
			break;
			case "seat_codriver":
				return "seat_con_2_1";
			break;
			case "seat_cargo1":
				return "seat_con_1_2";
			break;
			case "seat_cargo2":
				return "seat_con_2_2";
			break;
		}
		
		return "";
	}
	
	int GetCrewIndex( string selection )
	{
		return -1;
	}

	override bool CanReachSeatFromDoors( string pSeatSelection, vector pFromPos, float pDistance = 1.0 )
	{
		string conPointName = GetDoorConditionPointFromSelection(pSeatSelection);
		if (conPointName.Length() > 0)
		{
			if( MemoryPointExists(conPointName) )
			{
				vector conPointMS = GetMemoryPointPos(conPointName);
				vector conPointWS = ModelToWorld(conPointMS);
				
				//! skip the height for now
				conPointWS[1] = 0;
				pFromPos[1] = 0;
				
				if (vector.Distance(pFromPos, conPointWS) <= pDistance)
				{
					return true;
				}
			}
		}

		return false;		
	}

	bool IsVitalCarBattery()
	{
		return true;
	}
	
	bool IsVitalTruckBattery()
	{
		return true;
	}
	
	bool IsVitalSparkPlug()
	{
		return true;
	}
	
	bool IsVitalGlowPlug()
	{
		return true;
	}
	
	bool IsVitalEngineBelt()
	{
		return true;
	}
	
	bool IsVitalRadiator()
	{
		return true;
	}

	//! camera type
	override int Get3rdPersonCameraType()
	{
		return DayZPlayerCameras.DAYZCAMERA_3RD_VEHICLE;

	}

	int GetCarDoorsState( string slotType )
	{
		return -1;
	}

	string GetActionCompNameCoolant()
	{
		return "radiator";
	}

	float GetActionDistanceCoolant()
	{
		return 2.0;
	}

	string GetActionCompNameFuel()
	{
		return "refill";
	}

	float GetActionDistanceFuel()
	{
		return 1.5;
	}
	
	string GetActionCompNameOil()
	{
		return "carradiator";
	}

	float GetActionDistanceOil()
	{
		return 2.0;
	}
	
	string GetActionCompNameBrakes()
	{
		return "carradiator";
	}

	float GetActionDistanceBrakes()
	{
		return 2.0;
	}
	
#ifndef OLD_ACTIONS	
	void InitializeActions()
	{
		m_InputActionMap = m_CarTypeActionsMap.Get( this.Type() );
		if(!m_InputActionMap)
		{
			TInputActionMap iam = new TInputActionMap;
			m_InputActionMap = iam;
			SetActions();
			m_CarTypeActionsMap.Insert(this.Type(), m_InputActionMap);
		}
	}
	
	override void GetActions(typename action_input_type, out array<ActionBase_Basic> actions)
	{
		if(!m_ActionsInitialize)
		{
			m_ActionsInitialize = true;
			InitializeActions();
		}
		
		actions = m_InputActionMap.Get(action_input_type);
	}
	
	void SetActions()
	{
		AddAction(ActionAnimateCarSelection);
		AddAction(ActionGetInTransport);
		AddAction(ActionGetOutTransport);
		AddAction(ActionSwitchLights);
	}
	
	void AddAction(typename actionName)
	{
		ActionBase action = ActionManagerBase.GetAction(actionName);

		if(!action)
		{
			Debug.LogError("Action " + actionName + " dosn't exist!");
			return;
		}		
		
		typename ai = action.GetInputType();
		if(!ai)
		{
			m_ActionsInitialize = false;
			return;
		}
		ref array<ActionBase_Basic> action_array = m_InputActionMap.Get( ai );
		
		if(!action_array)
		{
			action_array = new array<ActionBase_Basic>;
			m_InputActionMap.Insert(ai, action_array);
		}
		
		Print("+ " + this + " add action: " + action + " input " + ai);

		action_array.Insert(action);
	}
	
	void RemoveAction(typename actionName)
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ActionBase action = player.GetActionManager().GetAction(actionName);
		typename ai = action.GetInputType();
		ref array<ActionBase_Basic> action_array = m_InputActionMap.Get( ai );
		
		if(action_array)
		{
			action_array.RemoveItem(action);
		}
	}
#else
	void SetActions() {}	
	void AddAction(typename actionName) {}
	void RemoveAction(typename actionName) {}
	
#endif	
};
