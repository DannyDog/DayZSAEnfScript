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
	class DZ_Structures_Specific
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
	class House;
	class Land_Radio_PanelBig: HouseNoDestruct
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Land_Radio_PanelBig0";
		descriptionShort = "$STR_CfgVehicles_Land_Radio_PanelBig1";
		model = "\dz\structures\Specific\Radio\Radio_PanelBig.p3d";
		oldpower = 0;
		simulation = "statictransmitter";
		inputRange = 8;
		range = 20000;
		useEntityHierarchy = "true";
		attachments[] = {"LargeBattery"};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.2;
			attachmentAction = 1;
		};
	};
	class Land_Radio_PanelPAS: HouseNoDestruct
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Land_Radio_PanelPAS0";
		descriptionShort = "$STR_CfgVehicles_Land_Radio_PanelPAS1";
		model = "\dz\structures\Specific\Radio\Radio_PanelPAS.p3d";
		oldpower = 0;
		simulation = "pasbroadcaster";
		inputRange = 8;
		useEntityHierarchy = "true";
		attachments[] = {"LargeBattery"};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.15;
			attachmentAction = 1;
		};
	};
	class Land_Tower_TC3_Red: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\towers\Tower_TC3_Red.p3d";
		featureSize = 150;
	};
	class Land_Tower_TC3_Grey: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\towers\Tower_TC3_Grey.p3d";
	};
	class Land_Church1_Yellow: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\churches\Church1_Yellow.p3d";
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
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class Doors3
			{
				displayName = "door 3";
				component = "Doors3";
				soundPos = "doors3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class Doors4
			{
				displayName = "door 4";
				component = "Doors4";
				soundPos = "doors4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
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
						hitpoints = 1500;
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
				class door3
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors3"};
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
				class door4
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors4"};
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
	class Land_Airfield_Small_Control: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\airfields\Airfield_Small_Control.p3d";
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
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors2
			{
				displayName = "door 2";
				component = "Doors2";
				soundPos = "doors2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors3
			{
				displayName = "door 3";
				component = "Doors3";
				soundPos = "doors3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors5
			{
				displayName = "door 5";
				component = "Doors5";
				soundPos = "doors5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors6
			{
				displayName = "door 6";
				component = "Doors6";
				soundPos = "doors6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors7
			{
				displayName = "door 7";
				component = "Doors7";
				soundPos = "doors7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors8
			{
				displayName = "door 8";
				component = "Doors8";
				soundPos = "doors8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors9
			{
				displayName = "door 9";
				component = "Doors9";
				soundPos = "doors9_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors10
			{
				displayName = "door 10";
				component = "Doors10";
				soundPos = "doors10_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors11
			{
				displayName = "door 11";
				component = "Doors11";
				soundPos = "doors11_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
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
						hitpoints = 1500;
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
				class door2
				{
					class Health
					{
						hitpoints = 1500;
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
				class door3
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors3"};
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
				class door5
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors5"};
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
				class door6
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors6"};
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
				class door7
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors7"};
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
				class door8
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors8"};
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
				class door9
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors9"};
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
				class door10
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors10"};
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
				class door11
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors11"};
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
	class Land_Airfield_Small_Hangar: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\airfields\Airfield_Small_Hangar.p3d";
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
	class Land_Cableway_Base: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\cableway\Cableway_Base.p3d";
	};
	class Land_Cableway_Tower: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\cableway\Cableway_Tower.p3d";
	};
	class Land_Cableway_Tower_Slope: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\cableway\Cableway_Tower_Slope.p3d";
	};
	class Land_Camp_House_white: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\camps\Camp_House_white.p3d";
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
	class Land_Camp_House_brown: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\camps\Camp_House_brown.p3d";
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
	class Land_Camp_House_red: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\camps\Camp_House_red.p3d";
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
	class Land_Castle_Bastion: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Bastion";
		featureSize = 12;
	};
	class Land_Castle_Bastion_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Bastion_nolc";
		featureSize = 12;
	};
	class Land_Castle_Gate: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Gate";
		featureSize = 12;
	};
	class Land_Castle_Wall1_20: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_20";
		featureSize = 12;
	};
	class Land_Castle_Wall1_20_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_20_nolc";
		featureSize = 12;
	};
	class Land_Castle_Wall1_20_Turn: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_20_Turn";
		featureSize = 12;
	};
	class Land_Castle_Wall1_20_Turn_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_20_Turn_nolc";
		featureSize = 12;
	};
	class Land_Castle_Wall1_Corner1: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_Corner1";
		featureSize = 12;
	};
	class Land_Castle_Wall1_Corner1_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_Corner1_nolc";
		featureSize = 12;
	};
	class Land_Castle_Wall1_End1: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_End1";
		featureSize = 12;
	};
	class Land_Castle_Wall1_End1_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_End1_nolc";
		featureSize = 12;
	};
	class Land_Castle_Wall1_End2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_End2";
		featureSize = 12;
	};
	class Land_Castle_Wall1_End2_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_End2_nolc";
		featureSize = 12;
	};
	class Land_Castle_Wall2_30: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall2_30";
		featureSize = 12;
	};
	class Land_Castle_Wall2_30_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall2_30_nolc";
		featureSize = 12;
	};
	class Land_Castle_Wall2_Corner1: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall2_Corner1";
		featureSize = 12;
	};
	class Land_Castle_Wall2_Corner1_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall2_Corner1_nolc";
		featureSize = 12;
	};
	class Land_Castle_Wall2_End1: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall2_End1";
		featureSize = 12;
	};
	class Land_Castle_Wall2_End1_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall2_End1_nolc";
		featureSize = 12;
	};
	class Land_Castle_Wall2_End2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall2_End2";
		featureSize = 12;
	};
	class Land_Castle_Wall2_End2_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall2_End2_nolc";
		featureSize = 12;
	};
	class Land_Castle_WallS_10: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_WallS_10";
		featureSize = 12;
	};
	class Land_Castle_WallS_10_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_WallS_10_nolc";
		featureSize = 12;
	};
	class Land_Castle_WallS_5_D: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_WallS_5_D";
		featureSize = 12;
	};
	class Land_Castle_WallS_5_D_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_WallS_5_D_nolc";
		featureSize = 12;
	};
	class Land_Castle_WallS_End: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_WallS_End";
		featureSize = 12;
	};
	class Land_Castle_WallS_End_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_WallS_End_nolc";
		featureSize = 12;
	};
	class Land_Castle_Stairs: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Stairs";
		featureSize = 12;
	};
	class Land_Castle_Stairs_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Stairs_nolc";
		featureSize = 12;
	};
	class Land_Castle_Wall1_Corner2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_Corner2";
		featureSize = 12;
	};
	class Land_Castle_Wall1_Corner2_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall1_Corner2_nolc";
		featureSize = 12;
	};
	class Land_Castle_Wall2_Corner2: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall2_Corner2";
		featureSize = 12;
	};
	class Land_Castle_Wall2_Corner2_nolc: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\structures\Specific\Castles\Castle_Wall2_Corner2_nolc";
		featureSize = 12;
	};
	class Land_Castle_Bergfrit: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\castles\Castle_Bergfrit.p3d";
		featureSize = 30;
	};
	class Land_Castle_Donjon: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\castles\Castle_Donjon.p3d";
		featureSize = 20;
	};
	class Land_Dead_MassGrave: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\deadbodies\Dead_Massgrave.p3d";
	};
	class Land_FuelStation_Build: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\fuelstation\Fuelstation_Build.p3d";
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
				initOpened = 0.3;
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
	class Land_FuelStation_Feed: House
	{
		scope = 1;
		model = "\dz\structures\specific\fuelstation\Fuelstation_Feed.p3d";
		displayName = "$STR_GasStation_Pump0";
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
	class Land_Hotel_Damaged: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\hotel\Hotel_Damaged.p3d";
		featureSize = 50;
	};
	class Land_Hotel: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\hotel\Hotel.p3d";
		featureSize = 50;
	};
	class Land_Chapel: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\churches\Chapel.p3d";
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
				soundOpen = "doorWoodNolatchOpen";
				soundClose = "doorWoodNolatchClose";
				soundLocked = "doorWoodNolatchRattle";
				soundOpenABit = "doorWoodNolatchOpenABit";
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
	class Land_Church2_1: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\churches\Church2_1.p3d";
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
				soundOpen = "doorWoodChurchOpen";
				soundClose = "doorWoodChurchClose";
				soundLocked = "doorWoodChurchRattle";
				soundOpenABit = "doorWoodChurchOpenABit";
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
	class Land_Church2_2: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\churches\Church2_2.p3d";
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
				soundOpen = "doorWoodChurchOpen";
				soundClose = "doorWoodChurchClose";
				soundLocked = "doorWoodChurchRattle";
				soundOpenABit = "doorWoodChurchOpenABit";
			};
			class Doors3
			{
				displayName = "door 3";
				component = "Doors3";
				soundPos = "doors3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorWoodChurchOpen";
				soundClose = "doorWoodChurchClose";
				soundLocked = "doorWoodChurchRattle";
				soundOpenABit = "doorWoodChurchOpenABit";
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
				class door3
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors3"};
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
	class Land_Church3: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\churches\Church3.p3d";
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
			};
		};
	};
	class Land_Lunapark_Autodrome: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\lunapark\Lunapark_Autodrome.p3d";
	};
	class Land_Lunapark_Carousel_Swan: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\lunapark\Lunapark_Carousel_Swan.p3d";
	};
	class Land_Lunapark_Carousel_Small: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\lunapark\Lunapark_Carousel_Small.p3d";
	};
	class Land_Lunapark_Ferris_wheel: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\lunapark\Lunapark_Ferris_wheel.p3d";
	};
	class Land_Lunapark_Bumper_Car: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\lunapark\Lunapark_Bumper_Car.p3d";
	};
	class Land_Lunapark_Shooting_Gallery: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\lunapark\Lunapark_Shooting_Gallery.p3d";
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
	class Land_Prison_Main: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\prison\Prison_Main.p3d";
		featureSize = 50;
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
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors2
			{
				displayName = "door 2";
				component = "Doors2";
				soundPos = "doors2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors3
			{
				displayName = "door 3";
				component = "Doors3";
				soundPos = "doors3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors5
			{
				displayName = "door 5";
				component = "Doors5";
				soundPos = "doors5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors6
			{
				displayName = "door 6";
				component = "Doors6";
				soundPos = "doors6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors7
			{
				displayName = "door 7";
				component = "Doors7";
				soundPos = "doors7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors8
			{
				displayName = "door 8";
				component = "Doors8";
				soundPos = "doors8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors9
			{
				displayName = "door 9";
				component = "Doors9";
				soundPos = "doors9_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors10
			{
				displayName = "door 10";
				component = "Doors10";
				soundPos = "doors10_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors11
			{
				displayName = "door 11";
				component = "Doors11";
				soundPos = "doors11_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors13
			{
				displayName = "door 13";
				component = "Doors13";
				soundPos = "doors13_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors14
			{
				displayName = "door 14";
				component = "Doors14";
				soundPos = "doors14_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors15
			{
				displayName = "door 15";
				component = "Doors15";
				soundPos = "doors15_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors16
			{
				displayName = "door 16";
				component = "Doors16";
				soundPos = "doors16_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors17
			{
				displayName = "door 17";
				component = "Doors17";
				soundPos = "doors17_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class Doors18
			{
				displayName = "door 18";
				component = "Doors18";
				soundPos = "doors18_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors19
			{
				displayName = "door 19";
				component = "Doors19";
				soundPos = "doors19_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors20
			{
				displayName = "door 20";
				component = "Doors20";
				soundPos = "doors20_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors21
			{
				displayName = "door 21";
				component = "Doors21";
				soundPos = "doors21_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors22
			{
				displayName = "door 22";
				component = "Doors22";
				soundPos = "doors22_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors23
			{
				displayName = "door 23";
				component = "Doors23";
				soundPos = "doors23_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors24
			{
				displayName = "door 24";
				component = "Doors24";
				soundPos = "doors24_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors25
			{
				displayName = "door 25";
				component = "Doors25";
				soundPos = "doors25_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors26
			{
				displayName = "door 26";
				component = "Doors26";
				soundPos = "doors26_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors27
			{
				displayName = "door 27";
				component = "Doors27";
				soundPos = "doors27_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors28
			{
				displayName = "door 28";
				component = "Doors28";
				soundPos = "doors28_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors29
			{
				displayName = "door 29";
				component = "Doors29";
				soundPos = "doors29_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors30
			{
				displayName = "door 30";
				component = "Doors30";
				soundPos = "doors30_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors31
			{
				displayName = "door 31";
				component = "Doors31";
				soundPos = "doors31_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors32
			{
				displayName = "door 32";
				component = "Doors32";
				soundPos = "doors32_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors33
			{
				displayName = "door 33";
				component = "Doors33";
				soundPos = "doors33_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors34
			{
				displayName = "door 34";
				component = "Doors34";
				soundPos = "doors34_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors35
			{
				displayName = "door 35";
				component = "Doors35";
				soundPos = "doors35_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors36
			{
				displayName = "door 36";
				component = "Doors36";
				soundPos = "doors36_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors37
			{
				displayName = "door 37";
				component = "Doors37";
				soundPos = "doors37_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors38
			{
				displayName = "door 38";
				component = "Doors38";
				soundPos = "doors38_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors39
			{
				displayName = "door 39";
				component = "Doors39";
				soundPos = "doors39_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors40
			{
				displayName = "door 40";
				component = "Doors40";
				soundPos = "doors40_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors41
			{
				displayName = "door 41";
				component = "Doors41";
				soundPos = "doors41_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors42
			{
				displayName = "door 42";
				component = "Doors42";
				soundPos = "doors42_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors43
			{
				displayName = "door 43";
				component = "Doors43";
				soundPos = "doors43_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors44
			{
				displayName = "door 44";
				component = "Doors44";
				soundPos = "doors44_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors45
			{
				displayName = "door 45";
				component = "Doors45";
				soundPos = "doors45_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors46
			{
				displayName = "door 46";
				component = "Doors46";
				soundPos = "doors46_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors47
			{
				displayName = "door 47";
				component = "Doors47";
				soundPos = "doors47_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors48
			{
				displayName = "door 48";
				component = "Doors48";
				soundPos = "doors48_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors49
			{
				displayName = "door 49";
				component = "Doors49";
				soundPos = "doors49_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors50
			{
				displayName = "door 50";
				component = "Doors50";
				soundPos = "doors50_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors51
			{
				displayName = "door 51";
				component = "Doors51";
				soundPos = "doors51_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors52
			{
				displayName = "door 52";
				component = "Doors52";
				soundPos = "doors52_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors53
			{
				displayName = "door 53";
				component = "Doors53";
				soundPos = "doors53_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors54
			{
				displayName = "door 54";
				component = "Doors54";
				soundPos = "doors54_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors55
			{
				displayName = "door 55";
				component = "Doors55";
				soundPos = "doors55_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors56
			{
				displayName = "door 56";
				component = "Doors56";
				soundPos = "doors56_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailHeavyOpen";
				soundClose = "doorMetalJailHeavyClose";
				soundLocked = "doorMetalJailHeavyRattle";
				soundOpenABit = "doorMetalJailHeavyOpenABit";
			};
			class Doors57
			{
				displayName = "door 57";
				component = "Doors57";
				soundPos = "doors57_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors58
			{
				displayName = "door 58";
				component = "Doors58";
				soundPos = "doors58_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors59
			{
				displayName = "door 59";
				component = "Doors59";
				soundPos = "doors59_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors60
			{
				displayName = "door 60";
				component = "Doors60";
				soundPos = "doors60_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors61
			{
				displayName = "door 61";
				component = "Doors61";
				soundPos = "doors61_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors62
			{
				displayName = "door 62";
				component = "Doors62";
				soundPos = "doors62_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors63
			{
				displayName = "door 63";
				component = "Doors63";
				soundPos = "doors63_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors64
			{
				displayName = "door 64";
				component = "Doors64";
				soundPos = "doors64_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors65
			{
				displayName = "door 65";
				component = "Doors65";
				soundPos = "doors65_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors66
			{
				displayName = "door 66";
				component = "Doors66";
				soundPos = "doors66_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin3
			{
				displayName = "door Twin3";
				component = "DoorsTwin3";
				soundPos = "doorsTwin3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin4
			{
				displayName = "door Twin4";
				component = "DoorsTwin4";
				soundPos = "doorsTwin4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin5
			{
				displayName = "door Twin5";
				component = "DoorsTwin5";
				soundPos = "doorsTwin5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin6
			{
				displayName = "door Twin6";
				component = "DoorsTwin6";
				soundPos = "doorsTwin6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin7
			{
				displayName = "door Twin7";
				component = "DoorsTwin7";
				soundPos = "doorsTwin7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin8
			{
				displayName = "door Twin8";
				component = "DoorsTwin8";
				soundPos = "doorsTwin8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
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
				class door3
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors3"};
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
				class door5
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors5"};
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
				class door6
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors6"};
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
				class door7
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors7"};
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
				class door8
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors8"};
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
				class door9
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors9"};
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
				class door10
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors10"};
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
				class door11
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors11"};
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
				class door13
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors13"};
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
				class door14
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors14"};
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
				class door15
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors15"};
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
				class door16
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors16"};
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
				class door17
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors17"};
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
				class door18
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors18"};
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
				class door19
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors19"};
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
				class door20
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors20"};
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
				class door21
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors21"};
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
				class door22
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors22"};
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
				class door23
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors23"};
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
				class door24
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors24"};
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
				class door25
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors25"};
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
				class door26
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors26"};
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
				class door27
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors27"};
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
				class door28
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors28"};
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
				class door29
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors29"};
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
				class door30
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors30"};
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
				class door31
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors31"};
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
				class door32
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors32"};
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
				class door33
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors33"};
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
				class door34
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors34"};
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
				class door35
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors35"};
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
				class door36
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors36"};
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
				class door37
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors37"};
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
				class door38
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors38"};
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
				class door39
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors39"};
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
				class door40
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors40"};
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
				class door41
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors41"};
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
				class door42
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors42"};
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
				class door43
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors43"};
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
				class door44
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors44"};
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
				class door45
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors45"};
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
				class door46
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors46"};
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
				class door47
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors47"};
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
				class door48
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors48"};
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
				class door49
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors49"};
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
				class door50
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors50"};
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
				class door51
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors51"};
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
				class door52
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors52"};
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
				class door53
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors53"};
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
				class door54
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors54"};
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
				class door55
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors55"};
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
				class door56
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors56"};
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
				class door57
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors57"};
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
				class door58
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors58"};
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
				class door59
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors59"};
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
				class door60
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors60"};
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
				class door61
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors61"};
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
				class door62
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors62"};
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
				class door63
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors63"};
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
				class door64
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors64"};
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
				class door65
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors65"};
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
				class door66
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors66"};
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
				class twin1
				{
					class Health
					{
						hitpoints = 1500;
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
						hitpoints = 1500;
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
						hitpoints = 1500;
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
						hitpoints = 1500;
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
						hitpoints = 1500;
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
						hitpoints = 1500;
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
						hitpoints = 1500;
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
						hitpoints = 1500;
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
			};
		};
	};
	class Land_Prison_Side: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\prison\Prison_Side.p3d";
		featureSize = 50;
		class Doors
		{
			class Doors3
			{
				displayName = "door 3";
				component = "Doors3";
				soundPos = "doors3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors4
			{
				displayName = "door 4";
				component = "Doors4";
				soundPos = "doors4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors11
			{
				displayName = "door 11";
				component = "Doors11";
				soundPos = "doors11_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors12
			{
				displayName = "door 12";
				component = "Doors12";
				soundPos = "doors12_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors19
			{
				displayName = "door 19";
				component = "Doors19";
				soundPos = "doors19_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors20
			{
				displayName = "door 20";
				component = "Doors20";
				soundPos = "doors20_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors21
			{
				displayName = "door 21";
				component = "Doors21";
				soundPos = "doors21_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors22
			{
				displayName = "door 22";
				component = "Doors22";
				soundPos = "doors22_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors23
			{
				displayName = "door 23";
				component = "Doors23";
				soundPos = "doors23_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors24
			{
				displayName = "door 24";
				component = "Doors24";
				soundPos = "doors24_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors25
			{
				displayName = "door 25";
				component = "Doors25";
				soundPos = "doors25_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors26
			{
				displayName = "door 26";
				component = "Doors26";
				soundPos = "doors26_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors29
			{
				displayName = "door 29";
				component = "Doors29";
				soundPos = "doors29_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalJailSlideOpen";
				soundClose = "doorMetalJailSlideClose";
				soundLocked = "doorMetalJailSlideRattle";
				soundOpenABit = "doorMetalJailSlideOpenABit";
			};
			class Doors30
			{
				displayName = "door 30";
				component = "Doors30";
				soundPos = "doors30_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalJailSlideOpen";
				soundClose = "doorMetalJailSlideClose";
				soundLocked = "doorMetalJailSlideRattle";
				soundOpenABit = "doorMetalJailSlideOpenABit";
			};
			class DoorsTwin1
			{
				displayName = "door Twin1";
				component = "DoorsTwin1";
				soundPos = "doorsTwin1_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class DoorsTwin2
			{
				displayName = "door Twin2";
				component = "DoorsTwin2";
				soundPos = "doorsTwin2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorMetalJailOpen";
				soundClose = "doorMetalJailClose";
				soundLocked = "doorMetalJailRattle";
				soundOpenABit = "doorMetalJailOpenABit";
			};
			class DoorsTwin3
			{
				displayName = "door Twin3";
				component = "DoorsTwin3";
				soundPos = "doorsTwin3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin4
			{
				displayName = "door Twin4";
				component = "DoorsTwin4";
				soundPos = "doorsTwin4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin5
			{
				displayName = "door Twin5";
				component = "DoorsTwin5";
				soundPos = "doorsTwin5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin6
			{
				displayName = "door Twin6";
				component = "DoorsTwin6";
				soundPos = "doorsTwin6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin7
			{
				displayName = "door Twin7";
				component = "DoorsTwin7";
				soundPos = "doorsTwin7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class DoorsTwin8
			{
				displayName = "door Twin8";
				component = "DoorsTwin8";
				soundPos = "doorsTwin8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
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
				class door3
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors3"};
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
				class door4
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors4"};
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
				class door11
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors11"};
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
				class door12
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors12"};
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
				class door19
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors19"};
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
				class door20
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors20"};
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
				class door21
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors21"};
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
				class door22
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors22"};
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
				class door23
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors23"};
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
				class door24
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors24"};
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
				class door25
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors25"};
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
				class door26
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors26"};
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
				class door27
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors27"};
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
				class door28
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors28"};
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
				class door29
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors29"};
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
				class door30
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors30"};
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
				class twin1
				{
					class Health
					{
						hitpoints = 1500;
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
						hitpoints = 1500;
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
				class twin3
				{
					class Health
					{
						hitpoints = 1500;
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
						hitpoints = 1500;
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
						hitpoints = 1500;
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
						hitpoints = 1500;
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
						hitpoints = 1500;
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
						hitpoints = 1500;
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
			};
		};
	};
	class Land_Prison_Wall_Large: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\prison\Prison_Wall_Large.p3d";
	};
	class Land_Radio_building: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\radio\Radio_building.p3d";
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
				soundOpen = "doorWoodTwinOpen";
				soundClose = "doorWoodTwinClose";
				soundLocked = "doorWoodTwinRattle";
				soundOpenABit = "doorWoodTwinOpenABit";
			};
			class Doors3
			{
				displayName = "door 3";
				component = "Doors3";
				soundPos = "doors3_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
			class Doors4
			{
				displayName = "door 4";
				component = "Doors4";
				soundPos = "doors4_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.3;
				soundOpen = "doorMetalSmallOpen";
				soundClose = "doorMetalSmallClose";
				soundLocked = "doorMetalSmallRattle";
				soundOpenABit = "doorMetalSmallOpenABit";
			};
			class Doors5
			{
				displayName = "door 5";
				component = "Doors5";
				soundPos = "doors5_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors6
			{
				displayName = "door 6";
				component = "Doors6";
				soundPos = "doors6_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors7
			{
				displayName = "door 7";
				component = "Doors7";
				soundPos = "doors7_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors8
			{
				displayName = "door 8";
				component = "Doors8";
				soundPos = "doors8_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
				soundOpen = "doorWoodSmallOpen";
				soundClose = "doorWoodSmallClose";
				soundLocked = "doorWoodSmallRattle";
				soundOpenABit = "doorWoodSmallOpenABit";
			};
			class Doors9
			{
				displayName = "door 9";
				component = "Doors9";
				soundPos = "doors9_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
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
						hitpoints = 1500;
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
				class door3
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors3"};
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
				class door4
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors4"};
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
				class door5
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors5"};
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
				class door6
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors6"};
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
				class door7
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors7"};
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
				class door8
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors8"};
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
				class door9
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors9"};
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
	class Land_Monument_T34: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\statues\Monument_T34.p3d";
	};
	class Land_Tower_TC1: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\towers\Tower_TC1.p3d";
	};
	class Land_Tower_TC2_Base: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\towers\Tower_TC2_Base.p3d";
		featureSize = 150;
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
				soundOpen = "doorWoodFrontOpen";
				soundClose = "doorWoodFrontClose";
				soundLocked = "doorWoodFrontRattle";
				soundOpenABit = "doorWoodFrontOpenABit";
			};
			class Doors2
			{
				displayName = "door 2";
				component = "Doors2";
				soundPos = "doors2_action";
				animPeriod = 1;
				initPhase = 0;
				initOpened = 0.7;
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
					componentNames[] = {"doors5"};
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
				class door2
				{
					class Health
					{
						hitpoints = 1000;
						transferToGlobalCoef = 0;
					};
					componentNames[] = {"doors6"};
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
	class Land_Tower_TC2_Mid: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\towers\Tower_TC2_Mid.p3d";
		featureSize = 150;
	};
	class Land_Tower_TC2_Top: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\towers\Tower_TC2_Top.p3d";
		featureSize = 150;
	};
	class Land_Tower_TC4_Base: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\towers\Tower_TC4_Base.p3d";
	};
	class Land_Tower_TC4_Mid: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\towers\Tower_TC4_Mid.p3d";
	};
	class Land_Tower_TC4_Top: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\specific\towers\Tower_TC4_Top.p3d";
	};
	class Land_Cableway_Cart: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\Specific\Cableway\Cableway_Cart.p3d";
	};
	class Land_Cableway_Cart2: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\Specific\Cableway\Cableway_Cart2.p3d";
	};
	class Land_Cableway_Cart3: HouseNoDestruct
	{
		scope = 1;
		model = "\dz\structures\Specific\Cableway\Cableway_Cart3.p3d";
	};
};
