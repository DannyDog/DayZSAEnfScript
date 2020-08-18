#define _ARMA_

//(8 Enums)
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	destructno = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgPatches
{
	class DZ_Structures_Wrecks
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class Land_Wreck_Uaz: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Uaz.p3d";
	};
	class Land_Boat_Small1: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Ships\Boat_Small1.p3d";
	};
	class Land_Boat_Small2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Ships\Boat_Small2.p3d";
	};
	class Land_Boat_Small3: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Ships\Boat_Small3.p3d";
	};
	class Land_Ship_Big_FrontA: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Ships\Ship_Big_FrontA.p3d";
		featureSize = 50;
	};
	class Land_Ship_Big_FrontB: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Ships\Ship_Big_FrontB.p3d";
	};
	class Land_Ship_Big_BackA: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Ships\Ship_Big_BackA.p3d";
		featureSize = 50;
	};
	class Land_Ship_Big_BackB: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Ships\Ship_Big_BackB.p3d";
		featureSize = 50;
	};
	class Land_Ship_Big_Castle: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Ships\Ship_Big_Castle.p3d";
		featureSize = 50;
	};
	class Land_Train_742_Blue: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Trains\Train_742_Blue.p3d";
	};
	class Land_Train_742_Red: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Trains\Train_742_Red.p3d";
	};
	class Land_Train_Wagon_Box: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Trains\Train_Wagon_Box.p3d";
		class Doors
		{
			class Door1
			{
				displayName = "$STR_CfgVehicles_Land_Train_Wagon_Box_Doors_Door10";
				component = "Door1";
				soundPos = "door1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSlideOpen";
				soundClose = "doorWoodSlideClose";
				soundLocked = "doorWoodRattle";
			};
			class Door2
			{
				displayName = "$STR_CfgVehicles_Land_Train_Wagon_Box_Doors_Door20";
				component = "Door2";
				soundPos = "door2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSlideOpen";
				soundClose = "doorWoodSlideClose";
				soundLocked = "doorWoodRattle";
			};
		};
	};
	class Land_Wreck_Caravan_MGreen: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Caravan_MGreen.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
		};
	};
	class Land_Wreck_Caravan_MRust: Land_Wreck_Caravan_MGreen
	{
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Caravan_MRust.p3d";
	};
	class Land_Wreck_Caravan_WBrown: Land_Wreck_Caravan_MGreen
	{
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Caravan_WBrown.p3d";
	};
	class Land_Wreck_Caravan_WGreen: Land_Wreck_Caravan_MGreen
	{
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Caravan_WGreen.p3d";
	};
	class Land_Wreck_Ikarus: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Ikarus.p3d";
	};
	class Land_Wreck_Lada_Green: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Lada_Green.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.2;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class Doors2
			{
				displayName = "door 2";
				component = "Doors2";
				soundPos = "doors2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class Doors3
			{
				displayName = "door 3";
				component = "Doors3";
				soundPos = "doors3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.2;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class Doors4
			{
				displayName = "door 4";
				component = "Doors4";
				soundPos = "doors4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class Doors5
			{
				displayName = "door 5";
				component = "Doors5";
				soundPos = "doors5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.1;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
		};
	};
	class Land_Wreck_Lada_Red: Land_Wreck_Lada_Green
	{
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Lada_Red.p3d";
	};
	class Land_Wreck_S1023_Blue: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_S1023_Blue.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.1;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
		};
	};
	class Land_Wreck_S1023_Beige: Land_Wreck_S1023_Blue
	{
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_S1023_Beige.p3d";
	};
	class Land_Wreck_V3S: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_V3S.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class Doors2
			{
				displayName = "door 2";
				component = "Doors2";
				soundPos = "doors2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class Doors5
			{
				displayName = "door 5";
				component = "Doors5";
				soundPos = "doors5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
		};
	};
	class Land_Wreck_Volha_Blue: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Volha_Blue.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class Doors2
			{
				displayName = "door 2";
				component = "Doors2";
				soundPos = "doors2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.2;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class Doors3
			{
				displayName = "door 3";
				component = "Doors3";
				soundPos = "doors3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class Doors4
			{
				displayName = "door 4";
				component = "Doors4";
				soundPos = "doors4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.2;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
			class Doors5
			{
				displayName = "door 5";
				component = "Doors5";
				soundPos = "doors5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.1;
				soundOpen = "doorCarSmallOpen";
				soundClose = "doorCarSmallClose";
				soundLocked = "doorCarSmallRattle";
				soundOpenABit = "doorCarSmallOpenABit";
			};
		};
	};
	class Land_Wreck_Volha_Grey: Land_Wreck_Volha_Blue
	{
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Volha_Grey.p3d";
	};
	class Land_Wreck_Trailer_Closed: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Trailer_Closed.p3d";
	};
	class Land_Wreck_Harverster: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Harverster.p3d";
	};
	class Land_Wreck_Harvester_head_trailer: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Harvester_head_trailer.p3d";
	};
	class Land_Wreck_C130J: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Aircraft\Wreck_C130J.p3d";
	};
	class Wreck_UH1Y: HouseNoDestruct
	{
		scope = 2;
		storageCategory = 4;
		model = "\DZ\structures\Wrecks\Aircraft\Wreck_UH1Y.p3d";
	};
	class Wreck_Mi8: HouseNoDestruct
	{
		scope = 2;
		storageCategory = 4;
		model = "\DZ\structures\Wrecks\Aircraft\Wreck_Mi8.p3d";
	};
	class Land_Wreck_Volha_Police: Land_Wreck_Volha_Blue
	{
		scope = 2;
		storageCategory = 4;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_Volha_Police.p3d";
	};
	class Land_Wreck_hb01_aban1_blue: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Wrecks\Vehicles\Wreck_hb01_aban1_blue.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1.5;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorCarWreckOpen";
				soundClose = "doorCarWreckClose";
				soundLocked = "doorCarWreckRattle";
				soundOpenABit = "doorCarWreckOpenABit";
			};
			class Doors2
			{
				displayName = "door 2";
				component = "Doors2";
				soundPos = "doors2_action";
				animPeriod = 1.5;
				initPhase = 0;
				initOpened = 0.2;
				soundOpen = "doorCarWreckOpen";
				soundClose = "doorCarWreckClose";
				soundLocked = "doorCarWreckRattle";
				soundOpenABit = "doorCarWreckOpenABit";
			};
			class Doors3
			{
				displayName = "door 3";
				component = "Doors3";
				soundPos = "doors3_action";
				animPeriod = 1.5;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorCarWreckOpen";
				soundClose = "doorCarWreckClose";
				soundLocked = "doorCarWreckRattle";
				soundOpenABit = "doorCarWreckOpenABit";
			};
		};
	};
	class Land_Wreck_hb01_aban1_green: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb01_aban1_green";
	};
	class Land_Wreck_hb01_aban1_white: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb01_aban1_white";
	};
	class Land_Wreck_hb01_aban1_police: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb01_aban1_police";
	};
	class Land_Wreck_hb01_aban2_blue: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb01_aban2_blue";
	};
	class Land_Wreck_hb01_aban2_green: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb01_aban2_green";
	};
	class Land_Wreck_hb01_aban2_white: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb01_aban2_white";
	};
	class Land_Wreck_hb01_aban2_police: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb01_aban2_police";
	};
	class Land_Wreck_hb02_aban1_black: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb02_aban1_black";
	};
	class Land_Wreck_hb02_aban1_blue: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb02_aban1_blue";
	};
	class Land_Wreck_hb02_aban1_red: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb02_aban1_red";
	};
	class Land_Wreck_hb02_aban2_black: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb02_aban2_black";
	};
	class Land_Wreck_hb02_aban2_blue: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb02_aban2_blue";
	};
	class Land_Wreck_hb02_aban2_red: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_hb02_aban2_red";
	};
	class Land_Wreck_sed01_aban1_black: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban1_black";
	};
	class Land_Wreck_sed01_aban1_white: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban1_white";
	};
	class Land_Wreck_sed01_aban1_police: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban1_police";
	};
	class Land_Wreck_sed01_aban1_wine: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban1_wine";
	};
	class Land_Wreck_sed01_aban2_black: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban2_black";
	};
	class Land_Wreck_sed01_aban2_white: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban2_white";
	};
	class Land_Wreck_sed01_aban2_police: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban2_police";
	};
	class Land_Wreck_sed01_aban2_wine: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban2_wine";
	};
	class Land_Wreck_sed02_aban1_grey: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed02_aban1_grey";
	};
	class Land_Wreck_sed02_aban1_red: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed02_aban1_red";
	};
	class Land_Wreck_sed02_aban1_yellow: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed02_aban1_yellow";
	};
	class Land_Wreck_sed02_aban2_grey: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed02_aban2_grey";
	};
	class Land_Wreck_sed02_aban2_red: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed02_aban2_red";
	};
	class Land_Wreck_sed02_aban2_yellow: Land_Wreck_hb01_aban1_blue
	{
		model = "DZ\structures\Wrecks\Vehicles\Wreck_sed02_aban2_yellow";
	};
};
