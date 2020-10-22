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
	class DZ_Structures_Walls
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
	class Land_Wall_Gate_Camp: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_camp.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalGateOpen";
				soundClose = "doorMetalGateClose";
				soundLocked = "doorMetalGateRattle";
				soundOpenABit = "doorMetalGateOpenABit";
			};
			class Doors4
			{
				displayName = "door 4";
				component = "Doors4";
				soundPos = "doors4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalGateOpen";
				soundClose = "doorMetalGateClose";
				soundLocked = "doorMetalGateRattle";
				soundOpenABit = "doorMetalGateOpenABit";
			};
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Fen2_L: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_fen2_l.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateMeshOpen";
				soundClose = "doorMetalGateMeshClose";
				soundLocked = "doorMetalGateMeshRattle";
				soundOpenABit = "doorMetalGateMeshOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Fen2_R: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_fen2_r.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateMeshOpen";
				soundClose = "doorMetalGateMeshClose";
				soundLocked = "doorMetalGateMeshRattle";
				soundOpenABit = "doorMetalGateMeshOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenG: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_feng.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateOpen";
				soundClose = "doorMetalGateClose";
				soundLocked = "doorMetalGateRattle";
				soundOpenABit = "doorMetalGateOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenG_Big: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_feng_big.p3d";
		bounding = "BSphere";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenG_Big_L: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_feng_big_l.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateOpen";
				soundClose = "doorMetalGateClose";
				soundLocked = "doorMetalGateRattle";
				soundOpenABit = "doorMetalGateOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenG_Big_Open: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_feng_big_open.p3d";
		bounding = "BSphere";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenG_Big_R: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_feng_big_r.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenG_Open: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_feng_open.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateOpen";
				soundClose = "doorMetalGateClose";
				soundLocked = "doorMetalGateRattle";
				soundOpenABit = "doorMetalGateOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenR: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_fenr.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateOpen";
				soundClose = "doorMetalGateClose";
				soundLocked = "doorMetalGateRattle";
				soundOpenABit = "doorMetalGateOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenR_Big: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_fenr_big.p3d";
		bounding = "BSphere";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenR_Big_L: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_fenr_big_l.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenR_Big_Open: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_fenr_big_open.p3d";
		bounding = "BSphere";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenR_Big_R: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_fenr_big_r.p3d";
		bounding = "BSphere";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 1;
				initOpened = 0.3;
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_FenR_Open: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_fenr_open.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateOpen";
				soundClose = "doorMetalGateClose";
				soundLocked = "doorMetalGateRattle";
				soundOpenABit = "doorMetalGateOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Ind1_L: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_ind1_l.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Ind1_R: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_ind1_r.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Ind2A_L: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_ind2a_l.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Ind2A_R: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_ind2a_r.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Ind2B_L: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_ind2b_l.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Ind2B_R: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_ind2b_r.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Ind2Rail_L: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_ind2rail_l.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Ind2Rail_R: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_ind2rail_r.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateBigOpen";
				soundClose = "doorMetalGateBigClose";
				soundLocked = "doorMetalGateBigRattle";
				soundOpenABit = "doorMetalGateBigOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Village: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_village.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorMetalGateOpen";
				soundClose = "doorMetalGateClose";
				soundLocked = "doorMetalGateRattle";
				soundOpenABit = "doorMetalGateOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Wood1: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_wood1.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorWoodGateSmallOpen";
				soundClose = "doorWoodGateSmallClose";
				soundLocked = "doorWoodGateSmallRattle";
				soundOpenABit = "doorWoodGateSmallOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Wood2: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_wood2.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorWoodGateSmallOpen";
				soundClose = "doorWoodGateSmallClose";
				soundLocked = "doorWoodGateSmallRattle";
				soundOpenABit = "doorWoodGateSmallOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Wood3: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_wood3.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorWoodGateSmallOpen";
				soundClose = "doorWoodGateSmallClose";
				soundLocked = "doorWoodGateSmallRattle";
				soundOpenABit = "doorWoodGateSmallOpenABit";
			};
		};
	};
	class Land_Wall_Gate_Wood4: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\walls\wall_gate_wood4.p3d";
		bounding = "BSphere";
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
				soundOpen = "doorWoodGateOpen";
				soundClose = "doorWoodGateClose";
				soundLocked = "doorWoodGateRattle";
				soundOpenABit = "doorWoodGateOpenABit";
			};
		};
	};
};
