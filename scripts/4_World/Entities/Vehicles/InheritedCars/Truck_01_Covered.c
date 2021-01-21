class Truck_01_Covered extends Truck_01_Base {};

class Truck_01_Covered_Orange extends Truck_01_Covered
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "Truck_01_Wheel" );
			entity.GetInventory().CreateInInventory( "Truck_01_Wheel" );
			entity.GetInventory().CreateInInventory( "Truck_01_Wheel" );
			entity.GetInventory().CreateInInventory( "Truck_01_Wheel" );
			
			entity.GetInventory().CreateInInventory( "Truck_01_WheelDouble" );
			entity.GetInventory().CreateInInventory( "Truck_01_WheelDouble" );
			entity.GetInventory().CreateInInventory( "Truck_01_WheelDouble" );
			entity.GetInventory().CreateInInventory( "Truck_01_WheelDouble" );

			entity.GetInventory().CreateInInventory( "TruckBattery" );

			entity.GetInventory().CreateInInventory( "Truck_01_Door_1_1_Orange" );
			entity.GetInventory().CreateInInventory( "Truck_01_Door_2_1_Orange" );
			entity.GetInventory().CreateInInventory( "Truck_01_Hood_Orange" );

			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		};

		Fill( CarFluid.FUEL, 120 );
		Fill( CarFluid.OIL, 4.0 );
	};
};

class Truck_01_Covered_Blue extends Truck_01_Covered
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "Truck_01_Wheel" );
			entity.GetInventory().CreateInInventory( "Truck_01_Wheel" );
			entity.GetInventory().CreateInInventory( "Truck_01_Wheel" );
			entity.GetInventory().CreateInInventory( "Truck_01_Wheel" );
			
			entity.GetInventory().CreateInInventory( "Truck_01_WheelDouble" );
			entity.GetInventory().CreateInInventory( "Truck_01_WheelDouble" );
			entity.GetInventory().CreateInInventory( "Truck_01_WheelDouble" );
			entity.GetInventory().CreateInInventory( "Truck_01_WheelDouble" );

			entity.GetInventory().CreateInInventory( "TruckBattery" );

			entity.GetInventory().CreateInInventory( "Truck_01_Door_1_1_Blue" );
			entity.GetInventory().CreateInInventory( "Truck_01_Door_2_1_Blue" );
			entity.GetInventory().CreateInInventory( "Truck_01_Hood_Blue" );

			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		};

		Fill( CarFluid.FUEL, 120 );
		Fill( CarFluid.OIL, 4.0 );
	};
};