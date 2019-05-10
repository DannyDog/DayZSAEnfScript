class CivilianSedan extends CarScript
{
	void CivilianSedan()
	{
		m_dmgContactCoef = 0.065;
	}
	
	override int GetAnimInstance()
	{
		return VehicleAnimInstances.SEDAN;
	}

	override int GetSeatAnimationType( int posIdx )
	{
		switch( posIdx )
		{
		case 0:
			return DayZPlayerConstants.VEHICLESEAT_DRIVER;
		case 1:
			return DayZPlayerConstants.VEHICLESEAT_CODRIVER;
		case 2:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 3:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		}

		return 0;
	}
	
	override bool CanReleaseAttachment( EntityAI attachment )
	{
		super.CanReleaseAttachment( attachment );
		
		string attType = attachment.GetType();
		
		if ( EngineIsOn() || GetCarDoorsState("CivSedanHood") == CarDoorState.DOORS_CLOSED )
		{
			if ( attType == "CarRadiator" || attType == "CarBattery" || attType == "SparkPlug" )
				return false;
		}

		return true;
	}
	
	override int GetCarDoorsState( string slotType )
	{
		CarDoor carDoor;

		Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
		if ( !carDoor )
			return CarDoorState.DOORS_MISSING;
	
		switch( slotType )
		{
			case "CivSedanDriverDoors":
				if ( GetAnimationPhase("DoorsDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "CivSedanCoDriverDoors":
				if ( GetAnimationPhase("DoorsCoDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "CivSedanCargo1Doors":
				if ( GetAnimationPhase("DoorsCargo1") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "CivSedanCargo2Doors":
				if ( GetAnimationPhase("DoorsCargo2") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
			
			case "CivSedanTrunk":
				if ( GetAnimationPhase("DoorsTrunk") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "CivSedanHood":
				if ( GetAnimationPhase("DoorsHood") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
		}

		return CarDoorState.DOORS_MISSING;
	}
	

	override bool CrewCanGetThrough( int posIdx )
	{
		switch( posIdx )
		{
			case 0:
				if ( GetCarDoorsState( "CivSedanDriverDoors" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			case 1:
				if ( GetCarDoorsState( "CivSedanCoDriverDoors" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;

			case 2:
				if ( GetCarDoorsState( "CivSedanCargo1Doors" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;

			case 3:
				if ( GetCarDoorsState( "CivSedanCargo2Doors" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
		}

		return false;
	}

	// 0 full ambient and engine sound
	// 1 zero ambient and engine sound
	override float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		switch ( ctrl )
		{
			case CarSoundCtrl.DOORS:
				float newValue = 0;
				
				//-----
				if ( GetCarDoorsState( "CivSedanDriverDoors" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				//-----
				if ( GetCarDoorsState( "CivSedanCoDriverDoors" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
			
				//-----
				if ( GetCarDoorsState( "CivSedanCargo1Doors" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				//-----
				if ( GetCarDoorsState( "CivSedanCargo2Doors" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
			
				//-----
				if ( GetHealthLevel( "WindowFront") == STATE_RUINED )
					newValue -= 0.6;

				//-----
				if ( GetHealthLevel( "WindowBack") == STATE_RUINED )
					newValue -= 0.6;
			
				if ( newValue > 1 )
					newValue = 1;
			
				if ( newValue < 0 )
					newValue = 0;
			
				m_enviroCoef = newValue;
				return newValue;
			break;
		}

		m_enviroCoef = oldValue;
		return oldValue;
	}

	override string GetAnimSourceFromSelection( string selection )
	{
		switch( selection )
		{
		case "doors_driver":
			return "DoorsDriver";
		case "doors_codriver":
			return "DoorsCoDriver";
		case "doors_cargo1":
			return "DoorsCargo1";
		case "doors_cargo2":
			return "DoorsCargo2";
		case "doors_hood":
			return "DoorsHood";
		case "doors_trunk":
			return "DoorsTrunk";
		}

		return "";
	}

	override bool IsVitalTruckBattery()
	{
		return false;
	}

	override bool IsVitalGlowPlug()
	{
		return false;
	}
	
	override bool CanReachSeatFromSeat( int currentSeat, int nextSeat )
	{
		switch( currentSeat )
		{
		case 0:
			if ( nextSeat == 1 )
				return true;
			break;
		case 1:
			if ( nextSeat == 0 )
				return true;
			break;
		case 2:
			if ( nextSeat == 3 )
				return true;
			break;
		case 3:
			if ( nextSeat == 2 )
				return true;
			break;
		}
		
		return false;
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
		case 2:
			if (pDoorsSelection == "DoorsCargo1")
			{
				return true;
			}
		break;
		case 3:
			if (pDoorsSelection == "DoorsCargo2")
			{
				return true;
			}
		break;
		}
		
		return false;		
	}

	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CivSedanWheel" );
			entity.GetInventory().CreateInInventory( "CivSedanWheel" );
			entity.GetInventory().CreateInInventory( "CivSedanWheel" );
			entity.GetInventory().CreateInInventory( "CivSedanWheel" );

			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );

			entity.GetInventory().CreateInInventory( "CivSedanDoors_Driver" );
			entity.GetInventory().CreateInInventory( "CivSedanDoors_CoDriver" );
			entity.GetInventory().CreateInInventory( "CivSedanDoors_BackLeft" );
			entity.GetInventory().CreateInInventory( "CivSedanDoors_BackRight" );
			entity.GetInventory().CreateInInventory( "CivSedanHood" );
			entity.GetInventory().CreateInInventory( "CivSedanTrunk" );

			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		};

		Fill( CarFluid.FUEL, 50 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
		
		//hotfix 
		GetController().ShiftUp();
		GetController().ShiftDown();
	};
}