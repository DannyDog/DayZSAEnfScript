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
	class DZ_Vehicles_Parts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Bottle_Base;
	class Inventory_Base;
	class Box_Base;
	class TruckBattery: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TruckBattery0";
		descriptionShort = "$STR_CfgVehicles_TruckBattery1";
		model = "\dz\vehicles\parts\battery_truck.p3d";
		attachments[] = {"MetalWire"};
		stackedUnit = "w";
		quantityBar = 1;
		varQuantityInit = 50;
		varQuantityMin = 0.0;
		varQuantityMax = 50;
		varQuantityDestroyOnMin = 0;
		weight = 18000;
		itemSize[] = {5,3};
		absorbency = 0;
		inventorySlot[] = {"TruckBattery","LargeBattery"};
		rotationFlags = 2;
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			convertEnergyToQuantity = 1;
			energyStorageMax = 1500;
			energyAtSpawn = 1500;
			reduceMaxEnergyByDamageCoef = 0.5;
			powerSocketsCount = 1;
			plugType = 4;
			compatiblePlugTypes[] = {8};
			attachmentAction = 2;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 240;
					healthLevels[] = {{1.0,{"DZ\vehicles\parts\data\truck_bat.rvmat"}},{0.7,{"DZ\vehicles\parts\data\truck_bat.rvmat"}},{0.5,{"DZ\vehicles\parts\data\truck_bat_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\truck_bat_damage.rvmat"}},{0.0,{"DZ\vehicles\parts\data\truck_bat_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class drop
				{
					soundset = "carbattery_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CarBattery: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CarBattery0";
		descriptionShort = "$STR_CfgVehicles_CarBattery1";
		model = "\dz\vehicles\parts\battery_car.p3d";
		attachments[] = {"MetalWire"};
		weight = 10000;
		itemSize[] = {3,3};
		absorbency = 0.1;
		inventorySlot[] = {"CarBattery","LargeBattery"};
		rotationFlags = 2;
		stackedUnit = "w";
		quantityBar = 1;
		varQuantityInit = 50;
		varQuantityMin = 0.0;
		varQuantityMax = 50;
		varQuantityDestroyOnMin = 0;
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			convertEnergyToQuantity = 1;
			energyStorageMax = 500;
			energyAtSpawn = 500;
			reduceMaxEnergyByDamageCoef = 0.5;
			powerSocketsCount = 1;
			plugType = 4;
			compatiblePlugTypes[] = {5,8,6};
			attachmentAction = 2;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\vehicles\parts\data\battery_smallcar.rvmat"}},{0.7,{"DZ\vehicles\parts\data\battery_smallcar.rvmat"}},{0.5,{"DZ\vehicles\parts\data\battery_smallcar_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\battery_smallcar_damage.rvmat"}},{0.0,{"DZ\vehicles\parts\data\battery_smallcar_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class drop
				{
					soundset = "carbattery_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BrakeFluid: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BrakeFluid0";
		descriptionShort = "$STR_CfgVehicles_BrakeFluid1";
		model = "\dz\vehicles\parts\Brake_Fluid.p3d";
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		varQuantityDestroyOnMin = 1;
		destroyOnEmpty = 1;
		quantityBar = 1;
		weight = 500;
		itemSize[] = {2,3};
		absorbency = 0;
		rotationFlags = 64;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\vehicles\parts\data\Brake_Fluid.rvmat"}},{0.7,{"DZ\vehicles\parts\data\Brake_Fluid.rvmat"}},{0.5,{"DZ\vehicles\parts\data\Brake_Fluid_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\Brake_Fluid_damage.rvmat"}},{0.0,{"DZ\vehicles\parts\data\Brake_Fluid_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUp
				{
					soundSet = "engineoil_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "engineoil_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class EngineOil: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_EngineOil0";
		descriptionShort = "$STR_CfgVehicles_EngineOil1";
		model = "\dz\vehicles\parts\oil_bottle.p3d";
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		varQuantityDestroyOnMin = 1;
		destroyOnEmpty = 1;
		quantityBar = 1;
		weight = 500;
		itemSize[] = {3,4};
		absorbency = 0;
		rotationFlags = 64;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\vehicles\parts\data\oil_bottle.rvmat"}},{0.7,{"DZ\vehicles\parts\data\oil_bottle.rvmat"}},{0.5,{"DZ\vehicles\parts\data\oil_bottle_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\oil_bottle_damage.rvmat"}},{0.0,{"DZ\vehicles\parts\data\oil_bottle_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUp
				{
					soundSet = "engineoil_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "engineoil_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CarRadiator: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CarRadiator0";
		descriptionShort = "$STR_CfgVehicles_CarRadiator1";
		model = "\dz\vehicles\parts\radiator_car.p3d";
		weight = 2000;
		itemSize[] = {5,4};
		absorbency = 0;
		inventorySlot[] = {"CarRadiator"};
		rotationFlags = 32;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\vehicles\parts\data\radiator_smallcar.rvmat"}},{0.7,{"DZ\vehicles\parts\data\radiator_smallcar.rvmat"}},{0.5,{"DZ\vehicles\parts\data\radiator_smallcar_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\radiator_smallcar_damage.rvmat"}},{0.0,{"DZ\vehicles\parts\data\radiator_smallcar_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUp_Light
				{
					soundSet = "pickUpCanisterGasolineLight_SoundSet";
					id = 796;
				};
				class pickUp
				{
					soundSet = "pickUpCanisterGasoline_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "carradiator_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class HeadlightH7: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HeadlightH70";
		descriptionShort = "$STR_CfgVehicles_HeadlightH71";
		model = "\dz\vehicles\parts\Replacement_Headlight.p3d";
		weight = 150;
		itemSize[] = {1,1};
		absorbency = 0;
		inventorySlot[] = {"Reflector_1_1","Reflector_2_1"};
		rotationFlags = 12;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{"DZ\vehicles\parts\data\ReplacementHeadlight.rvmat"}},{0.7,{"DZ\vehicles\parts\data\ReplacementHeadlight.rvmat"}},{0.5,{"DZ\vehicles\parts\data\ReplacementHeadlight_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\ReplacementHeadlight_damage.rvmat"}},{0.0,{"DZ\vehicles\parts\data\ReplacementHeadlight_destruct.rvmat"}}};
				};
			};
		};
	};
	class HeadlightH7_Box: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HeadlightH7_Box0";
		descriptionShort = "$STR_CfgVehicles_HeadlightH7_Box1";
		model = "\dz\vehicles\parts\Replacement_Headlight_Box.p3d";
		weight = 200;
		itemSize[] = {1,1};
		absorbency = 0;
		rotationFlags = 63;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\vehicles\parts\data\ReplacementHeadlight_Box.rvmat"}},{0.7,{"DZ\vehicles\parts\data\ReplacementHeadlight_Box.rvmat"}},{0.5,{"DZ\vehicles\parts\data\ReplacementHeadlight_Box_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\ReplacementHeadlight_Box_damage.rvmat"}},{0.0,{"DZ\vehicles\parts\data\ReplacementHeadlight_Box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class HeadlightH7
			{
				value = 1;
				variable = "quantity";
			};
		};
	};
	class SparkPlug: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SparkPlug0";
		descriptionShort = "$STR_CfgVehicles_SparkPlug1";
		model = "\dz\vehicles\parts\sparkplug.p3d";
		weight = 180;
		itemSize[] = {1,1};
		absorbency = 0;
		inventorySlot[] = {"SparkPlug"};
		rotationFlags = 12;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\vehicles\parts\data\sparkplug.rvmat"}},{0.7,{"DZ\vehicles\parts\data\sparkplug.rvmat"}},{0.5,{"DZ\vehicles\parts\data\sparkplug_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\sparkplug_damage.rvmat"}},{0.0,{"DZ\vehicles\parts\data\sparkplug_destruct.rvmat"}}};
				};
			};
		};
	};
	class TireRepairKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TireRepairKit0";
		descriptionShort = "$STR_CfgVehicles_TireRepairKit1";
		model = "\dz\vehicles\parts\Tire_Repair_Kit.p3d";
		weight = 1000;
		itemSize[] = {2,3};
		absorbency = 0;
		rotationFlags = 16;
		stackedUnit = "percentage";
		quantityBar = 1;
		varQuantityInit = 100.0;
		varQuantityMin = 0.0;
		varQuantityMax = 100.0;
		repairKitType = 6;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\vehicles\parts\data\Tire_Repair_Kit.rvmat"}},{0.7,{"DZ\vehicles\parts\data\Tire_Repair_Kit.rvmat"}},{0.5,{"DZ\vehicles\parts\data\Tire_Repair_Kit_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\Tire_Repair_Kit_damage.rvmat"}},{0.0,{"DZ\vehicles\parts\data\Tire_Repair_Kit_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "smallprotectorcase_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "smallprotectorcase_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CanisterGasoline: Bottle_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CanisterGasoline0";
		descriptionShort = "$STR_CfgVehicles_CanisterGasoline1";
		model = "\dz\vehicles\parts\JerryCan.p3d";
		weight = 4000;
		itemSize[] = {5,6};
		absorbency = 0;
		canBeSplit = 0;
		stackedRandom = 1;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		varLiquidTypeInit = 8192;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit = 20000.0;
		varQuantityMin = 0.0;
		varQuantityMax = 20000.0;
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpCanisterGasoline_Light
				{
					soundSet = "pickUpCanisterGasolineLight_SoundSet";
					id = 796;
				};
				class pickUpCanisterGasoline
				{
					soundSet = "pickUpCanisterGasoline_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "canistergasoline_drop_SoundSet";
					id = 898;
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\vehicles\parts\data\jerrycan.rvmat"}},{0.7,{"DZ\vehicles\parts\data\jerrycan.rvmat"}},{0.5,{"DZ\vehicles\parts\data\jerrycan_damage.rvmat"}},{0.3,{"DZ\vehicles\parts\data\jerrycan_damage.rvmat"}},{0.0,{"DZ\vehicles\parts\data\jerrycan_destruct.rvmat"}}};
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyPart
	{
		scope = 2;
		simulation = "ProxyInventory";
		model = "";
		inventorySlot = "";
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 1;
	};
	class ProxyBattery_truck: ProxyPart
	{
		model = "DZ\vehicles\parts\battery_truck.p3d";
		inventorySlot[] = {"TruckBattery","LargeBattery"};
	};
	class ProxyBattery_Car: ProxyPart
	{
		model = "DZ\vehicles\parts\battery_car.p3d";
		inventorySlot[] = {"CarBattery","LargeBattery"};
	};
	class Proxysparkplug: ProxyPart
	{
		model = "DZ\vehicles\parts\sparkplug.p3d";
		inventorySlot = "SparkPlug";
	};
	class ProxyReplacement_Headlight: ProxyPart
	{
		model = "DZ\vehicles\parts\Replacement_Headlight.p3d";
		inventorySlot[] = {"Reflector_1_1","Reflector_2_1"};
	};
	class ProxyRadiator_car: ProxyPart
	{
		model = "DZ\vehicles\parts\Radiator_car.p3d";
		inventorySlot = "CarRadiator";
	};
};
