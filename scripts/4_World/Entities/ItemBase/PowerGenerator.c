class PowerGenerator extends ItemBase
{
	float						m_Fuel;
	private static float		m_FuelTankCapacity; // Capacity in ml.
	private static float		m_FuelToEnergyRatio; // Conversion ratio of 1 ml of fuel to X Energy
	private int					m_FuelPercentage;
	
	static const string			START_SOUND = "powerGeneratorTurnOn_SoundSet";
	static const string			LOOP_SOUND = "powerGeneratorLoop_SoundSet";
	static const string			STOP_SOUND = "powerGeneratorTurnOff_SoundSet";
	static const string 		SPARKPLUG_ATTACH_SOUND = "sparkplug_attach_SoundSet";
	static const string 		SPARKPLUG_DETACH_SOUND = "sparkplug_detach_SoundSet";
	
	protected EffectSound 		m_EngineLoop;
	protected EffectSound 		m_EngineStart;
	protected EffectSound 		m_EngineStop;
	ref Timer 					m_SoundLoopStartTimer;
	ref protected Effect 		m_Smoke;
	
	ItemBase	m_SparkPlug; // Attached spark plug item
	
	// Constructor
	void PowerGenerator()
	{
		SetEventMask(EntityEvent.INIT); // Enable EOnInit event
		
		m_FuelPercentage = 50;
		RegisterNetSyncVariableInt("m_FuelPercentage");
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsPlaceSound");
	}

	override void EOnInit( IEntity other, int extra)
	{
		if ( GetGame().IsServer() )
		{
			m_FuelPercentage = GetCompEM().GetEnergy0To100();
			SetSynchDirty();
		}
		
		
		UpdateFuelMeter();
	}
	
	// Play the loop sound
	void StartLoopSound()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			if ( GetCompEM().IsWorking() )
			{
				PlaySoundSetLoop( m_EngineLoop, LOOP_SOUND, 0, 0 );
				
				// Particle
				vector local_pos = "0.3 0.21 0.4";
				vector local_ori = "270 0 0";
				m_Smoke = new EffGeneratorSmoke();
				SEffectManager.PlayOnObject(m_Smoke, this, local_pos, local_ori);
			}
		}
	}
	
	// Taking item into inventory
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}
		return CanManipulate();
	}

	// Taking item into inventory
	override bool CanPutIntoHands ( EntityAI player ) 
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		return CanManipulate();
	}

	// Returns true/false if this item can be moved into inventory/hands
	bool CanManipulate()
	{
		if ( GetCompEM().GetPluggedDevicesCount() == 0  &&  !GetCompEM().IsWorking() )
		{
			return true;
		}
		
		return false;
	}
	
	/*===================================
					EVENTS
	===================================*/
	
	// Init
	override void OnInitEnergy()
	{
		m_FuelTankCapacity = GetGame().ConfigGetFloat ("CfgVehicles " + GetType() + " fuelTankCapacity");
		m_FuelToEnergyRatio = GetCompEM().GetEnergyMax() / m_FuelTankCapacity; // Conversion ratio of 1 ml of fuel to X Energy
		m_SparkPlug = NULL;
		
		UpdateFuelMeter();
	}
	
	// Generator is working
	override void OnWorkStart()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			PlaySoundSet( m_EngineStart, START_SOUND, 0, 0 );
			
			if (!m_SoundLoopStartTimer)
				m_SoundLoopStartTimer = new Timer( CALL_CATEGORY_SYSTEM );
			
			if ( !m_SoundLoopStartTimer.IsRunning() ) // Makes sure the timer is NOT running already
			{
				m_SoundLoopStartTimer.Run(1.5, this, "StartLoopSound", NULL, false);
			}
		}
	}

	// Do work
	override void OnWork( float consumed_energy )
	{
		if ( GetGame().IsServer() )
		{
			m_FuelPercentage = GetCompEM().GetEnergy0To100();
			SetSynchDirty();
		}
		
		UpdateFuelMeter();
	}

	// Turn off when this runs out of fuel
	override void OnWorkStop()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			// Sound
			PlaySoundSet( m_EngineStop, STOP_SOUND, 0, 0 );
			StopSoundSet(m_EngineLoop);
			
			// particle
			if (m_Smoke)
				delete m_Smoke;
			
			// Fuel meter
			UpdateFuelMeter();
		}
	}
	
	// Called when this generator is picked up
	override void OnItemLocationChanged  ( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged(old_owner, new_owner);
		UpdateFuelMeter();
	}
	
	override void EEItemAttached ( EntityAI item, string slot_name )
	{
		super.EEItemAttached ( item, slot_name );
		
		ItemBase item_IB = ItemBase.Cast( item );
		
		if ( item_IB.IsKindOf("Sparkplug") )
		{
			ShowSelection("sparkplug_installed");
			m_SparkPlug = item_IB;
			
			if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
			{
				SEffectManager.PlaySound(SPARKPLUG_ATTACH_SOUND, GetPosition() );
			}
		}
	}
	
	override void EEItemDetached ( EntityAI item, string slot_name )
	{
		super.EEItemDetached ( item, slot_name );
		
		ItemBase item_IB = ItemBase.Cast( item );
		
		if ( item_IB.IsKindOf("Sparkplug") )
		{
			HideSelection("sparkplug_installed");
			m_SparkPlug = NULL;
			GetCompEM().SwitchOff();
			
			if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
			{
				SEffectManager.PlaySound(SPARKPLUG_DETACH_SOUND, GetPosition() );
			}
		}
	}
	
	/*================================
				FUNCTIONS
	================================*/
	
	void UpdateFuelMeter()
	{
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{
			SetAnimationPhase("dial_fuel", m_FuelPercentage * 0.01);
		}
		}
	
	// Adds energy to the generator
	void SetFuel(float fuel_amount)
	{
		if (m_FuelTankCapacity > 0)
		{
			m_FuelToEnergyRatio = GetCompEM().GetEnergyMax() / m_FuelTankCapacity;
			GetCompEM().SetEnergy(fuel_amount * m_FuelToEnergyRatio);
			m_FuelPercentage = GetCompEM().GetEnergy0To100();
			SetSynchDirty();
			UpdateFuelMeter();
		}
		else
		{
			string error = "ERROR! Item " + this.GetType() + " has fuel tank with 0 capacity! Add parameter 'fuelTankCapacity' to its config and set it to more than 0!";
			DPrint(error);
		}
	}

	// Adds fuel (energy) to the generator
	// Returns how much fuel was accepted
	float AddFuel(float available_fuel)
	{
		if ( available_fuel == 0 )
		{
			return 0;
		}
		
		float needed_fuel = GetMaxFuel() - GetFuel();
		
		if ( needed_fuel > available_fuel )
		{
			SetFuel(GetFuel() + available_fuel);
			return available_fuel; // Return used fuel amount
		}
		else
		{
			SetFuel(GetMaxFuel());
			return needed_fuel;
		}
	}

	// Check the bottle if it can be used to fill the tank
	bool CanAddFuel( ItemBase container )
	{
		if (container)
		{
			// Get the liquid
			int liquid_type	= container.GetLiquidType();
			
			// Do all checks
			if ( container.GetQuantity() > 0  &&  GetCompEM().GetEnergy() < GetCompEM().GetEnergyMax()  &&  (liquid_type & LIQUID_GASOLINE) )
			{
				return true;
			}
		}
		
		return false;
	}

	// Returns fuel amount
	float GetFuel()
	{
		return GetCompEM().GetEnergy() / m_FuelToEnergyRatio;
	}

	// Returns max fuel amount
	float GetMaxFuel()
	{
		return m_FuelTankCapacity;
	}

	// Checks sparkplug
	bool HasSparkplug()
	{
		if ( m_SparkPlug )
		{
			if ( !m_SparkPlug.IsRuined() )
			{
				return true;
			}
		}
		
		return false;
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
				
		UpdateFuelMeter();
		
		if ( IsPlaceSound() )
		{
			PlayPlaceSound();
		}
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
			
		SetIsPlaceSound( true );
	}
	
	override string GetPlaceSoundset()
	{
		return "placePowerGenerator_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPullOutPlug);
		AddAction(ActionTurnOnPowerGenerator);
		AddAction(ActionTurnOffPowerGenerator);
		AddAction(ActionPlaceObject);
	}
}
