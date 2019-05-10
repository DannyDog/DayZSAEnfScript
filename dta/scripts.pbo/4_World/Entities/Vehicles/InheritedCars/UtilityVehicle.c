class UtilityVehicle extends CarScript
{
	void UtilityVehicle()
	{
		m_dmgContactCoef = 0.018;
		m_enginePtcPos = "0 1.346 2.205";
	}
	
	override int GetAnimInstance()
	{
		return VehicleAnimInstances.MULTICAR;
	}

	override int GetSeatAnimationType( int posIdx )
	{
		switch( posIdx )
		{
		case 0:
			return DayZPlayerConstants.VEHICLESEAT_DRIVER;
		case 1:
			return DayZPlayerConstants.VEHICLESEAT_CODRIVER;
		}

		return 0;
	}

	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		Print( zone );
	}

	override bool CrewCanGetThrough( int posIdx )
	{
		CarDoor carDoor;
		switch( posIdx )
		{
			case 0:
				if ( GetCarDoorsState( "UtilityVehicleDriverDoors" ) == CarDoorState.DOORS_CLOSED )
				{
					return false;
				}
			
				return true;
			break;
			
			case 1:
				if ( GetCarDoorsState( "UtilityVehicleCoDriverDoors" ) == CarDoorState.DOORS_CLOSED )
				{
					return false;
				}
			
				return true;
			break;
		}

		return false;
	}
	
	override float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		switch ( ctrl )
		{
			case CarSoundCtrl.DOORS:
				float newValue = 0;

				//-----
				if ( GetCarDoorsState( "UtilityVehicleDriverDoors" ) == CarDoorState.DOORS_CLOSED )
				{
					newValue += 0.4;
					m_enviroCoef += 0.5;
				}

				if ( GetCarDoorsState( "UtilityVehicleCoDriverDoors" ) == CarDoorState.DOORS_CLOSED )
				{
					newValue += 0.4;
					m_enviroCoef += 0.5;
				}

				if ( newValue > 1 )
					newValue = 1;

			return newValue;
			break;
		}

		m_enviroCoef = oldValue;
		return oldValue;
	}
	
	override int GetCarDoorsState( string slotType )
	{
		CarDoor carDoor;
		
		switch( slotType )
		{
			case "UtilityVehicleDriverDoors":
				Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
				if ( carDoor )
				{
					if ( GetAnimationPhase("DoorsDriver") > 0.5 )
					{
						return CarDoorState.DOORS_OPEN;
					}
					else
					{
						return CarDoorState.DOORS_CLOSED;
					}
				}

				return CarDoorState.DOORS_MISSING;
			break;
			
			case "UtilityVehicleCoDriverDoors":
				Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
				if ( carDoor )
				{
					if ( GetAnimationPhase("DoorsCoDriver") > 0.5 )
					{
						return CarDoorState.DOORS_OPEN;
					}
					else
					{
						return CarDoorState.DOORS_CLOSED;
					}
				}

				return CarDoorState.DOORS_MISSING;
			break;
		}
		
		return CarDoorState.DOORS_MISSING;
	}

	override string GetAnimSourceFromSelection( string selection )
	{
		switch( selection )
		{
		case "doors_driver":
			return "DoorsDriver";
		case "doors_codriver":
			return "DoorsCoDriver";
		case "doors_hood":
			return "DoorsHood";
		case "doors_trunk":
			return "DoorsTrunk";			
		case "wheelsideplate1":
			return "WheelSidePlate1";
		case "wheelsideplate2":
			return "WheelSidePlate2";
		}

		return "";
	}

	override bool CanReachDoorsFromSeat( string pDoorsSelection, int pCurrentSeat )
	{
		switch( pCurrentSeat )
		{
		case 0:
			if (pDoorsSelection == "DoorsDriver")
			{
				return true;
			}
		break;
		case 1:
			if (pDoorsSelection == "DoorsCoDriver")
			{
				return true;
			}
		break;
		}
		
		return false;		
	}

	override bool IsVitalCarBattery()
	{
		return false;
	}

	override bool IsVitalSparkPlug()
	{
		return false;
	}

	override bool IsVitalGlowPlug()
	{
		return false;
	}

	override bool IsVitalEngineBelt()
	{
		return false;
	}
	
	override bool IsVitalRadiator()
	{
		return false;
	}
	
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "V3SWheel" );
			entity.GetInventory().CreateInInventory( "V3SWheel" );
			entity.GetInventory().CreateInInventory( "V3SWheel" );
			entity.GetInventory().CreateInInventory( "V3SWheel" );
			
			entity.GetInventory().CreateInInventory( "V3SWheelDouble" );
			entity.GetInventory().CreateInInventory( "V3SWheelDouble" );
			entity.GetInventory().CreateInInventory( "V3SWheelDouble" );
			entity.GetInventory().CreateInInventory( "V3SWheelDouble" );

			entity.GetInventory().CreateInInventory( "TruckBattery" );

			entity.GetInventory().CreateInInventory( "V3SDoors_Driver" );
			entity.GetInventory().CreateInInventory( "V3SDoors_CoDriver" );
			entity.GetInventory().CreateInInventory( "V3SHood" );

			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		};

		Fill( CarFluid.FUEL, 120 );
		Fill( CarFluid.OIL, 4.0 );
	};
}