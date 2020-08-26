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
	class DZ_Structures_Bliss_Ruins
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
	class Land_Ruin_BusStop_Village2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_BusStop_Village2.p3d";
	};
	class Land_Ruin_Camp_House: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Camp_House.p3d";
	};
	class Land_Ruin_Slum_House2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Slum_House2.p3d";
	};
	class Land_Ruin_Slum_House3: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Slum_House3.p3d";
	};
	class Land_Ruin_Slum_House4: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Slum_House4.p3d";
	};
	class Land_Ruin_Highway_Pillar1: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Highway_Pillar1.p3d";
	};
	class Land_Ruin_Highway_Pillar1_Garage: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Highway_Pillar1_Garage.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodChurchLargeOpen";
				soundClose = "doorWoodChurchLargeClose";
				soundLocked = "doorWoodChurchLargeRattle";
				soundOpenABit = "doorWoodChurchLargeOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodChurchLargeOpen";
				soundClose = "doorWoodChurchLargeClose";
				soundLocked = "doorWoodChurchLargeRattle";
				soundOpenABit = "doorWoodChurchLargeOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class twin1
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorstwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
				class twin2
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorstwin2"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 3;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
			};
		};
	};
	class Land_Ruin_Chapel2_White: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Chapel2_White.p3d";
	};
	class Land_Ruin_Chapel2_Yellow: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Chapel2_Yellow.p3d";
	};
	class Land_Ruin_Church2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Church2.p3d";
	};
	class Land_Ruin_Church2_NoIvy: Land_Ruin_Church2
	{
		model = "\DZ\structures_bliss\Ruins\Ruin_Church2_NoIvy.p3d";
	};
	class Land_Ruin_House_1B01: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1B01.p3d";
	};
	class Land_Ruin_House_1W01: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W01.p3d";
	};
	class Land_Ruin_House_1W02: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W02.p3d";
	};
	class Land_Ruin_House_1W03: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W03.p3d";
	};
	class Land_Ruin_House_1W04: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W04.p3d";
	};
	class Land_Ruin_House_1W05: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W05.p3d";
	};
	class Land_Ruin_House_1W06: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W06.p3d";
	};
	class Land_Ruin_House_1W07: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W07.p3d";
	};
	class Land_Ruin_House_1W08: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W08.p3d";
	};
	class Land_Ruin_House_1W09: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W09.p3d";
	};
	class Land_Ruin_House_1W10: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W10.p3d";
	};
	class Land_Ruin_House_1W11: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W11.p3d";
	};
	class Land_Ruin_House_1W12: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W12.p3d";
	};
	class Land_Ruin_House_1W13: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_1W13.p3d";
	};
	class Land_Ruin_House_2B01: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_2B01.p3d";
	};
	class Land_Ruin_House_2B02: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_2B02.p3d";
	};
	class Land_Ruin_House_2B03: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_2B03.p3d";
	};
	class Land_Ruin_House_2B04: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_2B04.p3d";
	};
	class Land_Ruin_House_2W01: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_2W01.p3d";
	};
	class Land_Ruin_House_2W02: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_2W02.p3d";
	};
	class Land_Ruin_House_2W03: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_2W03.p3d";
	};
	class Land_Ruin_House_2W04: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_2W04.p3d";
	};
	class Land_Ruin_House_2W05: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_House_2W05.p3d";
	};
	class Land_Ruin_HouseBig1: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig1.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class twin1
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
			};
		};
	};
	class Land_Ruin_HouseBig1_NoIvy: Land_Ruin_HouseBig1
	{
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig1_NoIvy.p3d";
	};
	class Land_Ruin_HouseBig1_Half: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig1_Half.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class twin1
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
			};
		};
	};
	class Land_Ruin_HouseBig1_NoIvy_Half: Land_Ruin_HouseBig1_Half
	{
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig1_NoIvy_Half.p3d";
	};
	class Land_Ruin_HouseBig2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig2.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class twin1
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
				class twin2
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
			};
		};
	};
	class Land_Ruin_HouseBig2_NoIvy: Land_Ruin_HouseBig2
	{
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig2_NoIvy.p3d";
	};
	class Land_Ruin_HouseBig2_Half: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig2_Half.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class twin1
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
				class twin2
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
			};
		};
	};
	class Land_Ruin_HouseBig2_NoIvy_Half: Land_Ruin_HouseBig2_Half
	{
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig2_NoIvy_Half.p3d";
	};
	class Land_Ruin_HouseBig3: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig3.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class twin1
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
			};
		};
	};
	class Land_Ruin_HouseBig3_NoIvy: Land_Ruin_HouseBig3
	{
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig3_NoIvy.p3d";
	};
	class Land_Ruin_HouseBig3_Half: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig3_Half.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class twin1
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
			};
		};
	};
	class Land_Ruin_HouseBig3_NoIvy_Half: Land_Ruin_HouseBig3_Half
	{
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseBig3_NoIvy_Half.p3d";
	};
	class Land_Ruin_HouseSmall1: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseSmall1.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class twin1
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
			};
		};
	};
	class Land_Ruin_HouseSmall1_NoIvy: Land_Ruin_HouseSmall1
	{
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseSmall1_NoIvy.p3d";
	};
	class Land_Ruin_HouseSmall1_Half: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseSmall1_Half.p3d";
	};
	class Land_Ruin_HouseSmall1_NoIvy_Half: Land_Ruin_HouseSmall1_Half
	{
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseSmall1_NoIvy_Half.p3d";
	};
	class Land_Ruin_HouseSmall2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseSmall2.p3d";
		class Doors
		{
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
			class DamageZones
			{
				class twin1
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin1"};
					fatalInjuryCoef = -1;
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 2.5;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 2;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
				};
			};
		};
	};
	class Land_Ruin_HouseSmall2_NoIvy: Land_Ruin_HouseSmall2
	{
		model = "\DZ\structures_bliss\Ruins\Ruin_HouseSmall2_NoIvy.p3d";
	};
	class Land_Ruin_Mil_ControlTower: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Mil_ControlTower.p3d";
	};
	class Land_Ruin_Mil_GuardBox_Brown: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Mil_GuardBox_Brown.p3d";
	};
	class Land_Ruin_Mil_GuardBox_Green: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Mil_GuardBox_Green.p3d";
	};
	class Land_Ruin_Mil_GuardBox_Smooth: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Mil_GuardBox_Smooth.p3d";
	};
	class Land_Ruin_Shed_Closed: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Shed_Closed.p3d";
	};
	class Land_Ruin_Shed_Closed2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Shed_Closed2.p3d";
	};
	class Land_Ruin_Smokestack_Metal: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Ruins\Ruin_Smokestack_Metal.p3d";
	};
};
