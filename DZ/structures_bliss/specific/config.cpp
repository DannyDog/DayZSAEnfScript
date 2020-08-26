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
	class DZ_Structures_Bliss_Specific
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
	class Land_Castle_Bastion2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Castles\Castle_Bastion2.p3d";
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
				soundOpen = "doorMetalTwinOpen";
				soundClose = "doorMetalTwinClose";
				soundLocked = "doorMetalTwinRattle";
				soundOpenABit = "doorMetalTwinOpenABit";
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
						hitpoints = 3000;
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
	class Land_Chapel2_White: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Chapel2_White.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
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
				class door1
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors1"};
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
	class Land_Chapel2_White_Dam: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Chapel2_White_Dam.p3d";
	};
	class Land_Chapel2_Yellow: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Chapel2_Yellow.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
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
				class door1
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors1"};
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
	class Land_Chapel2_Yellow_Dam: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Chapel2_Yellow_Dam.p3d";
	};
	class Land_Church4: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Church4.p3d";
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
				soundOpen = "doorWoodChurchOpen";
				soundClose = "doorWoodChurchClose";
				soundLocked = "doorWoodChurchRattle";
				soundOpenABit = "doorWoodChurchOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin3
			{
				displayName = "door Twin3";
				component = "DoorsTwin3";
				soundPos = "doorsTwin3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin4
			{
				displayName = "door Twin4";
				component = "DoorsTwin4";
				soundPos = "doorsTwin4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin5
			{
				displayName = "door Twin5";
				component = "DoorsTwin5";
				soundPos = "doorsTwin5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin6
			{
				displayName = "door Twin6";
				component = "DoorsTwin6";
				soundPos = "doorsTwin6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin7
			{
				displayName = "door Twin7";
				component = "DoorsTwin7";
				soundPos = "doorsTwin7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin8
			{
				displayName = "door Twin8";
				component = "DoorsTwin8";
				soundPos = "doorsTwin8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin9
			{
				displayName = "door Twin9";
				component = "DoorsTwin9";
				soundPos = "doorsTwin9_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
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
					componentNames[] = {"doorsTwin1"};
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
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin2"};
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
				class twin3
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin3"};
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
				class twin4
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin4"};
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
				class twin5
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin5"};
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
				class twin6
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin6"};
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
				class twin7
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin7"};
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
				class twin8
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin8"};
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
				class twin9
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin9"};
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
	class Land_Church4_Dam: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Church4_Dam.p3d";
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
				soundOpen = "doorWoodChurchOpen";
				soundClose = "doorWoodChurchClose";
				soundLocked = "doorWoodChurchRattle";
				soundOpenABit = "doorWoodChurchOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin3
			{
				displayName = "door Twin3";
				component = "DoorsTwin3";
				soundPos = "doorsTwin3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin4
			{
				displayName = "door Twin4";
				component = "DoorsTwin4";
				soundPos = "doorsTwin4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin5
			{
				displayName = "door Twin5";
				component = "DoorsTwin5";
				soundPos = "doorsTwin5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin6
			{
				displayName = "door Twin6";
				component = "DoorsTwin6";
				soundPos = "doorsTwin6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin7
			{
				displayName = "door Twin7";
				component = "DoorsTwin7";
				soundPos = "doorsTwin7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin8
			{
				displayName = "door Twin8";
				component = "DoorsTwin8";
				soundPos = "doorsTwin8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin9
			{
				displayName = "door Twin9";
				component = "DoorsTwin9";
				soundPos = "doorsTwin9_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
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
					componentNames[] = {"doorsTwin1"};
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
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin2"};
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
				class twin3
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin3"};
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
				class twin4
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin4"};
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
				class twin5
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin5"};
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
				class twin6
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin6"};
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
				class twin7
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin7"};
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
				class twin8
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin8"};
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
				class twin9
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin9"};
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
	class Land_Church4_Lightblue: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Church4_Lightblue.p3d";
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
				soundOpen = "doorWoodChurchOpen";
				soundClose = "doorWoodChurchClose";
				soundLocked = "doorWoodChurchRattle";
				soundOpenABit = "doorWoodChurchOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin3
			{
				displayName = "door Twin3";
				component = "DoorsTwin3";
				soundPos = "doorsTwin3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin4
			{
				displayName = "door Twin4";
				component = "DoorsTwin4";
				soundPos = "doorsTwin4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin5
			{
				displayName = "door Twin5";
				component = "DoorsTwin5";
				soundPos = "doorsTwin5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin6
			{
				displayName = "door Twin6";
				component = "DoorsTwin6";
				soundPos = "doorsTwin6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin7
			{
				displayName = "door Twin7";
				component = "DoorsTwin7";
				soundPos = "doorsTwin7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin8
			{
				displayName = "door Twin8";
				component = "DoorsTwin8";
				soundPos = "doorsTwin8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin9
			{
				displayName = "door Twin9";
				component = "DoorsTwin9";
				soundPos = "doorsTwin9_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
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
					componentNames[] = {"doorsTwin1"};
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
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin2"};
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
				class twin3
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin3"};
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
				class twin4
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin4"};
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
				class twin5
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin5"};
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
				class twin6
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin6"};
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
				class twin7
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin7"};
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
				class twin8
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin8"};
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
				class twin9
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin9"};
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
	class Land_Church4_Red: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Church4_Red.p3d";
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
				soundOpen = "doorWoodChurchOpen";
				soundClose = "doorWoodChurchClose";
				soundLocked = "doorWoodChurchRattle";
				soundOpenABit = "doorWoodChurchOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin3
			{
				displayName = "door Twin3";
				component = "DoorsTwin3";
				soundPos = "doorsTwin3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin4
			{
				displayName = "door Twin4";
				component = "DoorsTwin4";
				soundPos = "doorsTwin4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin5
			{
				displayName = "door Twin5";
				component = "DoorsTwin5";
				soundPos = "doorsTwin5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin6
			{
				displayName = "door Twin6";
				component = "DoorsTwin6";
				soundPos = "doorsTwin6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin7
			{
				displayName = "door Twin7";
				component = "DoorsTwin7";
				soundPos = "doorsTwin7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin8
			{
				displayName = "door Twin8";
				component = "DoorsTwin8";
				soundPos = "doorsTwin8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin9
			{
				displayName = "door Twin9";
				component = "DoorsTwin9";
				soundPos = "doorsTwin9_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
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
					componentNames[] = {"doorsTwin1"};
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
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin2"};
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
				class twin3
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin3"};
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
				class twin4
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin4"};
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
				class twin5
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin5"};
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
				class twin6
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin6"};
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
				class twin7
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin7"};
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
				class twin8
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin8"};
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
				class twin9
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin9"};
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
	class Land_Church4_White: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Church4_White.p3d";
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
				soundOpen = "doorWoodChurchOpen";
				soundClose = "doorWoodChurchClose";
				soundLocked = "doorWoodChurchRattle";
				soundOpenABit = "doorWoodChurchOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin3
			{
				displayName = "door Twin3";
				component = "DoorsTwin3";
				soundPos = "doorsTwin3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin4
			{
				displayName = "door Twin4";
				component = "DoorsTwin4";
				soundPos = "doorsTwin4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin5
			{
				displayName = "door Twin5";
				component = "DoorsTwin5";
				soundPos = "doorsTwin5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin6
			{
				displayName = "door Twin6";
				component = "DoorsTwin6";
				soundPos = "doorsTwin6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin7
			{
				displayName = "door Twin7";
				component = "DoorsTwin7";
				soundPos = "doorsTwin7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin8
			{
				displayName = "door Twin8";
				component = "DoorsTwin8";
				soundPos = "doorsTwin8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin9
			{
				displayName = "door Twin9";
				component = "DoorsTwin9";
				soundPos = "doorsTwin9_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
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
					componentNames[] = {"doorsTwin1"};
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
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin2"};
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
				class twin3
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin3"};
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
				class twin4
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin4"};
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
				class twin5
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin5"};
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
				class twin6
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin6"};
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
				class twin7
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin7"};
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
				class twin8
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin8"};
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
				class twin9
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin9"};
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
	class Land_Church4_Yellow_Dam: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Church4_Yellow_Dam.p3d";
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
				soundOpen = "doorWoodChurchOpen";
				soundClose = "doorWoodChurchClose";
				soundLocked = "doorWoodChurchRattle";
				soundOpenABit = "doorWoodChurchOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin3
			{
				displayName = "door Twin3";
				component = "DoorsTwin3";
				soundPos = "doorsTwin3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin4
			{
				displayName = "door Twin4";
				component = "DoorsTwin4";
				soundPos = "doorsTwin4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin5
			{
				displayName = "door Twin5";
				component = "DoorsTwin5";
				soundPos = "doorsTwin5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin6
			{
				displayName = "door Twin6";
				component = "DoorsTwin6";
				soundPos = "doorsTwin6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin7
			{
				displayName = "door Twin7";
				component = "DoorsTwin7";
				soundPos = "doorsTwin7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin8
			{
				displayName = "door Twin8";
				component = "DoorsTwin8";
				soundPos = "doorsTwin8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin9
			{
				displayName = "door Twin9";
				component = "DoorsTwin9";
				soundPos = "doorsTwin9_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
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
					componentNames[] = {"doorsTwin1"};
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
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin2"};
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
				class twin3
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin3"};
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
				class twin4
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin4"};
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
				class twin5
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin5"};
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
				class twin6
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin6"};
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
				class twin7
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin7"};
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
				class twin8
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin8"};
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
				class twin9
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doorsTwin9"};
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
	class Land_Misc_Calvary1: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Cultural\Misc_Calvary1.p3d";
		class AnimationSources
		{
			class Plate1
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Plate2: Plate1{};
			class Plate3: Plate1
			{
				initPhase = 0;
			};
			class Plate4: Plate1{};
			class Plate5: Plate1{};
		};
	};
	class Land_FuelStation_Build_Enoch: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\FuelStation\FuelStation_Build_Enoch.p3d";
		class Doors
		{
			class Doors1
			{
				displayName = "door 1";
				component = "Doors1";
				soundPos = "doors1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
			class Doors2
			{
				displayName = "door 2";
				component = "Doors2";
				soundPos = "doors2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.5;
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
				class door1
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors1"};
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
				class door2
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors2"};
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
	class House;
	class Land_FuelStation_Feed_Enoch: House
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\FuelStation\FuelStation_Feed_Enoch.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 1;
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
						damage = 1;
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
	class Land_Tower_TC5: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Towers\Tower_TC5.p3d";
	};
	class Land_Tower_TC6: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures_bliss\Specific\Towers\Tower_TC6.p3d";
	};
};
