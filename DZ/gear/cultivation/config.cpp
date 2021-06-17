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
	class DZ_Gear_Cultivation
	{
		units[] = {"Cultivation_TomatoSeedsPack"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgHorticulture
{
	class Plants
	{
		class Plant_Pepper
		{
			infestedTex = "dz\gear\cultivation\data\pepper_plant_insect_co.paa";
			infestedMat = "";
			healthyTex = "dz\gear\cultivation\data\pepper_plant_co.paa";
			healthyMat = "dz\gear\cultivation\data\pepper_plant.rvmat";
		};
		class Plant_Tomato
		{
			infestedTex = "dz\gear\cultivation\data\tomato_plant_insect_co.paa";
			infestedMat = "";
			healthyTex = "dz\gear\cultivation\data\tomato_plant_co.paa";
			healthyMat = "dz\gear\cultivation\data\tomato_plant.rvmat";
		};
		class Plant_Zucchini
		{
			infestedTex = "dz\gear\cultivation\data\zucchini_plant_insect_co.paa";
			infestedMat = "";
			healthyTex = "dz\gear\cultivation\data\zucchini_plant_co.paa";
			healthyMat = "dz\gear\cultivation\data\zucchini_plant.rvmat";
		};
		class Plant_Potato
		{
			infestedTex = "dz\gear\cultivation\data\potato_plant_insect_co.paa";
			infestedMat = "dz\gear\cultivation\data\potato_plant_insect.rvmat";
			healthyTex = "dz\gear\cultivation\data\potato_plant_co.paa";
			healthyMat = "dz\gear\cultivation\data\potato_plant.rvmat";
		};
		class Plant_Pumpkin
		{
			infestedTex = "dz\gear\cultivation\data\pumpkin_plant_insect_co.paa";
			infestedMat = "";
			healthyTex = "dz\gear\cultivation\data\pumpkin_plant_co.paa";
			healthyMat = "dz\gear\cultivation\data\pumpkin_plant.rvmat";
		};
		class Plant_Cannabis
		{
			infestedTex = "dz\gear\cultivation\data\cannabis_plant_insect_co.paa";
			infestedMat = "dz\gear\cultivation\data\cannabis_plant_insect.rvmat";
			healthyTex = "dz\gear\cultivation\data\cannabis_plant_co.paa";
			healthyMat = "dz\gear\cultivation\data\cannabis_plant.rvmat";
		};
	};
};
class CfgVehicles
{
	class Static;
	class Inventory_Base;
	class HouseNoDestruct;
	class ClutterCutter6x6: Static
	{
		scope = 1;
		model = "\DZ\gear\cultivation\clutter_cutter_6m_x_6m.p3d";
		displayName = "$STR_CfgVehicles_ClutterCutter6x60";
		icon = "";
		simulation = "thing";
		nameSound = "";
		vehicleClass = "Misc";
		mapSize = 0.7;
		accuracy = 0.2;
		destrType = "DestructNo";
	};
	class ClutterCutter2x2: Static
	{
		scope = 1;
		model = "\DZ\gear\cultivation\clutter_cutter_2m_x_2m.p3d";
		displayName = "$STR_CfgVehicles_ClutterCutter2x20";
		icon = "";
		simulation = "thing";
		nameSound = "";
		vehicleClass = "Misc";
		mapSize = 0.7;
		accuracy = 0.2;
		destrType = "DestructNo";
	};
	class SeedBase: Inventory_Base
	{
		scope = 0;
		weight = 10;
		itemSize[] = {1,1};
		spawnOffset = 0;
		lootCategory = "Crafted";
		inventorySlot[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","SeedBase_10","SeedBase_11","SeedBase_12","SeedBase_13"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5;
					healthLevels[] = {{1.0,{"DZ\gear\cultivation\data\seeds.rvmat"}},{0.7,{"DZ\gear\cultivation\data\seeds.rvmat"}},{0.5,{"DZ\gear\cultivation\data\seeds_damage.rvmat"}},{0.3,{"DZ\gear\cultivation\data\seeds_damage.rvmat"}},{0.0,{"DZ\gear\cultivation\data\seeds_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet = "seeds_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class TomatoSeeds: SeedBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TomatoSeeds0";
		descriptionShort = "$STR_CfgVehicles_TomatoSeeds1";
		model = "\dz\gear\cultivation\tomato_seeds.p3d";
		canBeSplit = 1;
		varQuantityInit = 20;
		varQuantityMin = 0;
		varQuantityMax = 20;
		class Horticulture
		{
			PlantType = "Plant_Tomato";
		};
	};
	class PepperSeeds: SeedBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PepperSeeds0";
		descriptionShort = "$STR_CfgVehicles_PepperSeeds1";
		model = "\dz\gear\cultivation\pepper_seeds.p3d";
		canBeSplit = 1;
		varQuantityInit = 20;
		varQuantityMin = 0;
		varQuantityMax = 20;
		class Horticulture
		{
			PlantType = "Plant_Pepper";
		};
	};
	class PumpkinSeeds: SeedBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PumpkinSeeds0";
		descriptionShort = "$STR_CfgVehicles_PumpkinSeeds1";
		model = "\dz\gear\cultivation\pumpkin_seeds.p3d";
		canBeSplit = 1;
		varQuantityInit = 20;
		varQuantityMin = 0;
		varQuantityMax = 20;
		class Horticulture
		{
			PlantType = "Plant_Pumpkin";
		};
	};
	class ZucchiniSeeds: SeedBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ZucchiniSeeds0";
		descriptionShort = "$STR_CfgVehicles_ZucchiniSeeds1";
		model = "\dz\gear\cultivation\Zucchini_seeds.p3d";
		canBeSplit = 1;
		varQuantityInit = 20;
		varQuantityMin = 0;
		varQuantityMax = 20;
		class Horticulture
		{
			PlantType = "Plant_Zucchini";
		};
	};
	class PotatoSeed: SeedBase
	{
		scope = 2;
		displayName = "$STR_PotatoSeed0";
		descriptionShort = "$STR_PotatoSeed1";
		model = "\dz\gear\food\potato.p3d";
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 1;
		rotationFlags = 12;
		weight = 0;
		itemSize[] = {2,1};
		stackedUnit = "g";
		absorbency = 0.2;
		class Horticulture
		{
			PlantType = "Plant_Potato";
		};
	};
	class CannabisSeeds: SeedBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CannabisSeeds0";
		descriptionShort = "$STR_CfgVehicles_CannabisSeeds1";
		model = "\dz\gear\cultivation\cannabis_seeds.p3d";
		canBeSplit = 1;
		varQuantityInit = 20;
		varQuantityMin = 0;
		varQuantityMax = 20;
		class Horticulture
		{
			PlantType = "Plant_Cannabis";
		};
	};
	class TomatoSeedsPack: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TomatoSeedsPack0";
		descriptionShort = "$STR_CfgVehicles_TomatoSeedsPack1";
		model = "\dz\gear\cultivation\tomato_seeds_pack.p3d";
		rotationFlags = 17;
		quantityBar = 1;
		itemSize[] = {1,1};
		weight = 10;
		spawnOffset = 0;
		lootCategory = "Materials";
		lootTag[] = {"Farm","Kitchen","Forester"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5;
					healthLevels[] = {{1.0,{"DZ\gear\cultivation\data\tomato_seeds.rvmat"}},{0.7,{"DZ\gear\cultivation\data\tomato_seeds.rvmat"}},{0.5,{"DZ\gear\cultivation\data\tomato_seeds_damage.rvmat"}},{0.3,{"DZ\gear\cultivation\data\tomato_seeds_damage.rvmat"}},{0.0,{"DZ\gear\cultivation\data\tomato_seeds_destruct.rvmat"}}};
				};
			};
		};
		class Horticulture
		{
			ContainsSeedsType = "TomatoSeeds";
			ContainsSeedsQuantity = 10;
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault = "$STR_CfgVehicles_TomatoSeedsPack_UserActions_EmptyPack0";
				displayName = "$STR_CfgVehicles_TomatoSeedsPack_UserActions_EmptyPack1";
				position = "action";
				onlyForPlayer = 1;
				radius = 2;
				condition = "true";
				statement = "this callMethod ['EmptySeedPack', _person];";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet = "seedpack_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class PepperSeedsPack: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PepperSeedsPack0";
		descriptionShort = "$STR_CfgVehicles_PepperSeedsPack1";
		model = "\dz\gear\cultivation\pepper_seeds_pack.p3d";
		rotationFlags = 17;
		quantityBar = 1;
		itemSize[] = {1,1};
		weight = 10;
		spawnOffset = 0;
		lootCategory = "Materials";
		lootTag[] = {"Farm","Kitchen","Forester"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5;
					healthLevels[] = {{1.0,{"DZ\gear\cultivation\data\pepper_seeds.rvmat"}},{0.7,{"DZ\gear\cultivation\data\pepper_seeds.rvmat"}},{0.5,{"DZ\gear\cultivation\data\pepper_seeds_damage.rvmat"}},{0.3,{"DZ\gear\cultivation\data\pepper_seeds_damage.rvmat"}},{0.0,{"DZ\gear\cultivation\data\pepper_seeds_destruct.rvmat"}}};
				};
			};
		};
		class Horticulture
		{
			ContainsSeedsType = "PepperSeeds";
			ContainsSeedsQuantity = 10;
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault = "$STR_CfgVehicles_PepperSeedsPack_UserActions_EmptyPack0";
				displayName = "$STR_CfgVehicles_PepperSeedsPack_UserActions_EmptyPack1";
				position = "action";
				onlyForPlayer = 1;
				radius = 2;
				condition = "true";
				statement = "this callMethod ['EmptySeedPack', _person];";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet = "seedpack_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class PumpkinSeedsPack: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PumpkinSeedsPack0";
		descriptionShort = "$STR_CfgVehicles_PumpkinSeedsPack1";
		model = "\dz\gear\cultivation\Pumpkin_seeds_pack.p3d";
		itemSize[] = {1,1};
		rotationFlags = 17;
		quantityBar = 1;
		weight = 10;
		spawnOffset = 0;
		lootCategory = "Materials";
		lootTag[] = {"Farm","Kitchen","Forester"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5;
					healthLevels[] = {{1.0,{"DZ\gear\cultivation\data\pumpkin_seeds.rvmat"}},{0.7,{"DZ\gear\cultivation\data\pumpkin_seeds.rvmat"}},{0.5,{"DZ\gear\cultivation\data\pumpkin_seeds_damage.rvmat"}},{0.3,{"DZ\gear\cultivation\data\pumpkin_seeds_damage.rvmat"}},{0.0,{"DZ\gear\cultivation\data\pumpkin_seeds_destruct.rvmat"}}};
				};
			};
		};
		class Horticulture
		{
			ContainsSeedsType = "PumpkinSeeds";
			ContainsSeedsQuantity = 10;
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault = "$STR_CfgVehicles_PumpkinSeedsPack_UserActions_EmptyPack0";
				displayName = "$STR_CfgVehicles_PumpkinSeedsPack_UserActions_EmptyPack1";
				position = "action";
				onlyForPlayer = 1;
				radius = 2;
				condition = "true";
				statement = "this callMethod ['EmptySeedPack', _person];";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet = "seedpack_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class ZucchiniSeedsPack: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ZucchiniSeedsPack0";
		descriptionShort = "$STR_CfgVehicles_ZucchiniSeedsPack1";
		model = "\dz\gear\cultivation\Zucchini_seeds_pack.p3d";
		rotationFlags = 17;
		quantityBar = 1;
		itemSize[] = {1,1};
		weight = 10;
		spawnOffset = 0;
		lootCategory = "Materials";
		lootTag[] = {"Farm","Kitchen","Forester"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5;
					healthLevels[] = {{1.0,{"DZ\gear\cultivation\data\zucchini_seeds.rvmat"}},{0.7,{"DZ\gear\cultivation\data\zucchini_seeds.rvmat"}},{0.5,{"DZ\gear\cultivation\data\zucchini_seeds_damage.rvmat"}},{0.3,{"DZ\gear\cultivation\data\zucchini_seeds_damage.rvmat"}},{0.0,{"DZ\gear\cultivation\data\zucchini_seeds_destruct.rvmat"}}};
				};
			};
		};
		class Horticulture
		{
			ContainsSeedsType = "ZucchiniSeeds";
			ContainsSeedsQuantity = 10;
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault = "$STR_CfgVehicles_ZucchiniSeedsPack_UserActions_EmptyPack0";
				displayName = "$STR_CfgVehicles_ZucchiniSeedsPack_UserActions_EmptyPack1";
				position = "action";
				onlyForPlayer = 1;
				radius = 2;
				condition = "true";
				statement = "this callMethod ['EmptySeedPack', _person];";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet = "seedpack_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class CannabisSeedsPack: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CannabisSeedsPack0";
		descriptionShort = "$STR_CfgVehicles_CannabisSeedsPack1";
		model = "\dz\gear\cultivation\cannabis_seeds_pack.p3d";
		rotationFlags = 17;
		quantityBar = 1;
		itemSize[] = {1,1};
		weight = 10;
		spawnOffset = 0;
		lootCategory = "Materials";
		lootTag[] = {"Farm","Kitchen","Forester"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5;
					healthLevels[] = {{1.0,{"DZ\gear\cultivation\data\cannabis_seeds.rvmat"}},{0.7,{"DZ\gear\cultivation\data\cannabis_seeds.rvmat"}},{0.5,{"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"}},{0.3,{"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"}},{0.0,{"DZ\gear\cultivation\data\cannabis_seeds_destruct.rvmat"}}};
				};
			};
		};
		class Horticulture
		{
			ContainsSeedsType = "CannabisSeeds";
			ContainsSeedsQuantity = 10;
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault = "$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack0";
				displayName = "$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack1";
				position = "action";
				onlyForPlayer = 1;
				radius = 2;
				condition = "true";
				statement = "this callMethod ['EmptySeedPack', _person];";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet = "seedpack_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class PlantMaterial: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PlantMaterial0";
		descriptionShort = "$STR_CfgVehicles_PlantMaterial1";
		model = "\dz\gear\cultivation\plant_material.p3d";
		inventorySlot[] = {"Plant"};
		lootCategory = "Crafted";
		itemSize[] = {3,2};
		rotationFlags = 34;
		weight = 10;
		spawnOffset = 0;
		canBeSplit = 1;
		varQuantityInit = 350;
		varQuantityMin = 0.0;
		varQuantityMax = 350;
		quantityBar = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\gear\cultivation\data\plant_material.rvmat"}},{0.7,{"DZ\gear\cultivation\data\plant_material.rvmat"}},{0.5,{"DZ\gear\cultivation\data\plant_material_damage.rvmat"}},{0.3,{"DZ\gear\cultivation\data\plant_material_damage.rvmat"}},{0.0,{"DZ\gear\cultivation\data\plant_material_destruct.rvmat"}}};
				};
			};
		};
		class Horticulture
		{
			TexId = 2;
			AddEnergyToSlot = 0.5;
			ConsumedQuantity = 100.0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpPlantMaterialLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpPlantMaterial_SoundSet";
					id = 797;
				};
			};
		};
	};
	class AntiPestsSpray: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AntiPestsSpray0";
		descriptionShort = "$STR_CfgVehicles_AntiPestsSpray1";
		model = "\dz\gear\medical\DisinfectantSpray.p3d";
		lootTag[] = {"Farm"};
		lootCategory = "Crafted";
		weight = 40;
		itemSize[] = {1,3};
		varQuantityInit = 120;
		varQuantityMin = 0.0;
		varQuantityMax = 120;
		varQuantityDestroyOnMin = 1;
		quantityBar = 1;
		varLiquidTypeInit = 32768;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\Loot_DisinfectantSpray.rvmat"}},{0.7,{"DZ\gear\medical\data\Loot_DisinfectantSpray.rvmat"}},{0.5,{"DZ\gear\medical\data\Loot_DisinfectantSpray_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\Loot_DisinfectantSpray_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\Loot_DisinfectantSpray_destruct.rvmat"}}};
				};
			};
		};
	};
	class PlantBase: Inventory_Base
	{
		storageCategory = 1;
		lootCategory = "Crafted";
		hiddenSelections[] = {"infestedParts"};
		hiddenSelectionsTextures[] = {""};
		hiddenSelectionsMaterials[] = {""};
		inventorySlot[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","SeedBase_10","SeedBase_11","SeedBase_12","SeedBase_13"};
		class AnimationSources
		{
			class pile_01
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class pile_02
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_01
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_01_crops
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_02
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_02_crops
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_03
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_03_crops
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_04
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_04_crops
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_05
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_05_crops
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_06
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class plantStage_06_crops
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class stake
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class Plant_Tomato: PlantBase
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_land_horticulture_plant_tomato0";
		descriptionShort = "$STR_cfgvehicles_land_horticulture_plant_tomato1";
		model = "DZ\gear\cultivation\tomato_plant.p3d";
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\tomato_plant_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\cultivation\data\tomato_plant.rvmat"};
		class Horticulture
		{
			GrowthStagesCount = 6;
			CropsCount = 7;
			CropsType = "Tomato";
		};
	};
	class Plant_Pepper: PlantBase
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_land_horticulture_plant_pepper0";
		descriptionShort = "$STR_cfgvehicles_land_horticulture_plant_pepper1";
		model = "DZ\gear\cultivation\pepper_plant.p3d";
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\pepper_plant_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\cultivation\data\pepper_plant.rvmat"};
		class Horticulture
		{
			GrowthStagesCount = 6;
			CropsCount = 3;
			CropsType = "GreenBellPepper";
		};
	};
	class Plant_Potato: PlantBase
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_land_horticulture_plant_potato0";
		descriptionShort = "$STR_cfgvehicles_land_horticulture_plant_potato1";
		model = "DZ\gear\cultivation\potato_plant.p3d";
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\potato_plant_co.paa","dz\gear\cultivation\data\potato_plant_nohq.paa","dz\gear\cultivation\data\potato_plant_smdi.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\cultivation\data\potato_plant.rvmat"};
		class Horticulture
		{
			GrowthStagesCount = 6;
			CropsCount = 3;
			CropsType = "PotatoSeed";
		};
	};
	class Plant_Pumpkin: PlantBase
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_land_horticulture_plant_pumpkin0";
		descriptionShort = "$STR_cfgvehicles_land_horticulture_plant_pumpkin1";
		model = "DZ\gear\cultivation\pumpkin_plant.p3d";
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\pumpkin_plant_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\cultivation\data\pumpkin_plant.rvmat"};
		class Horticulture
		{
			GrowthStagesCount = 7;
			CropsCount = 2;
			CropsType = "Pumpkin";
		};
	};
	class Plant_Zucchini: PlantBase
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_land_horticulture_plant_zucchini0";
		descriptionShort = "$STR_cfgvehicles_land_horticulture_plant_zucchini1";
		model = "DZ\gear\cultivation\zucchini_plant.p3d";
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\zucchini_plant_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\cultivation\data\zucchini_plant.rvmat"};
		class Horticulture
		{
			GrowthStagesCount = 7;
			CropsCount = 2;
			CropsType = "Zucchini";
		};
	};
	class Plant_Cannabis: PlantBase
	{
		scope = 2;
		model = "DZ\gear\cultivation\Cannabis_plant.p3d";
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\Cannabis_plant_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\cultivation\data\Cannabis_plant.rvmat"};
		class Horticulture
		{
			GrowthStagesCount = 6;
			CropsCount = 7;
			CropsType = "Cannabis";
		};
	};
	class GardenPlotGreenhouse: Inventory_Base
	{
		scope = 2;
		model = "DZ\gear\cultivation\garden_plot_greenhouse.p3d";
		storageCategory = 1;
		useEntityHierarchy = "true";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = {10,10,10};
		physLayer = "item_large";
		attachments[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9"};
		hiddenSelections[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","slotCovered_01","slotCovered_02","slotCovered_03","slotCovered_04","slotCovered_05","slotCovered_06","slotCovered_07","slotCovered_08","slotCovered_09"};
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\soil_cultivated_co.paa","dz\gear\cultivation\data\soil_cultivated_limed_CO.paa","dz\gear\cultivation\data\soil_cultivated_compost_CO.paa","","","","","","","","","","","","","","",""};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","","","","","","","","",""};
		class AnimationSources
		{
			class slotVisible
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class slotHidden: slotVisible
			{
				initPhase = 1;
			};
			class SeedBase_1: slotVisible{};
			class SeedBase_2: slotVisible{};
			class SeedBase_3: slotVisible{};
			class SeedBase_4: slotVisible{};
			class SeedBase_5: slotVisible{};
			class SeedBase_6: slotVisible{};
			class SeedBase_7: slotVisible{};
			class SeedBase_8: slotVisible{};
			class SeedBase_9: slotVisible{};
			class slotCovered_01: slotHidden{};
			class slotCovered_02: slotHidden{};
			class slotCovered_03: slotHidden{};
			class slotCovered_04: slotHidden{};
			class slotCovered_05: slotHidden{};
			class slotCovered_06: slotHidden{};
			class slotCovered_07: slotHidden{};
			class slotCovered_08: slotHidden{};
			class slotCovered_09: slotHidden{};
		};
		class DamageSystem
		{
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
		};
		class GUIInventoryAttachmentsProps
		{
			class Filling
			{
				name = "$STR_attachment_Filling0";
				description = "";
				icon = "set:dayz_inventory image:cat_gp_filling";
				attachmentSlots[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9"};
			};
		};
	};
	class GardenPlotPolytunnel: Inventory_Base
	{
		scope = 2;
		model = "DZ\gear\cultivation\garden_plot_polytunnel.p3d";
		storageCategory = 1;
		useEntityHierarchy = "true";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = {10,10,10};
		physLayer = "item_large";
		attachments[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","SeedBase_10","SeedBase_11","SeedBase_12","SeedBase_13"};
		hiddenSelections[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","SeedBase_10","SeedBase_11","SeedBase_12","SeedBase_13","slotCovered_01","slotCovered_02","slotCovered_03","slotCovered_04","slotCovered_05","slotCovered_06","slotCovered_07","slotCovered_08","slotCovered_09","slotCovered_10","slotCovered_11","slotCovered_12","slotCovered_13"};
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\soil_cultivated_co.paa","dz\gear\cultivation\data\soil_cultivated_limed_CO.paa","dz\gear\cultivation\data\soil_cultivated_compost_CO.paa","","","","","","","","","","","","","","","","","","","","","","",""};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","","","","","","","","","","","","","","","","",""};
		class AnimationSources
		{
			class slotVisible
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class slotHidden: slotVisible
			{
				initPhase = 1;
			};
			class SeedBase_1: slotVisible{};
			class SeedBase_2: slotVisible{};
			class SeedBase_3: slotVisible{};
			class SeedBase_4: slotVisible{};
			class SeedBase_5: slotVisible{};
			class SeedBase_6: slotVisible{};
			class SeedBase_7: slotVisible{};
			class SeedBase_8: slotVisible{};
			class SeedBase_9: slotVisible{};
			class SeedBase_10: slotVisible{};
			class SeedBase_11: slotVisible{};
			class SeedBase_12: slotVisible{};
			class SeedBase_13: slotVisible{};
			class slotCovered_01: slotHidden{};
			class slotCovered_02: slotHidden{};
			class slotCovered_03: slotHidden{};
			class slotCovered_04: slotHidden{};
			class slotCovered_05: slotHidden{};
			class slotCovered_06: slotHidden{};
			class slotCovered_07: slotHidden{};
			class slotCovered_08: slotHidden{};
			class slotCovered_09: slotHidden{};
			class slotCovered_10: slotHidden{};
			class slotCovered_11: slotHidden{};
			class slotCovered_12: slotHidden{};
			class slotCovered_13: slotHidden{};
		};
		class DamageSystem
		{
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
		};
		class GUIInventoryAttachmentsProps
		{
			class Filling
			{
				name = "$STR_attachment_Filling0";
				description = "";
				icon = "set:dayz_inventory image:cat_gp_filling";
				attachmentSlots[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","SeedBase_10","SeedBase_11","SeedBase_12","SeedBase_13"};
			};
		};
	};
	class GardenPlot: Inventory_Base
	{
		scope = 2;
		model = "DZ\gear\cultivation\garden_plot_outside.p3d";
		storageCategory = 1;
		lootCategory = "Crafted";
		useEntityHierarchy = "true";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = {10,10,10};
		attachments[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9"};
		physLayer = "item_large";
		class GUIInventoryAttachmentsProps
		{
			class Filling
			{
				name = "$STR_attachment_Filling0";
				description = "";
				attachmentSlots[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9"};
				icon = "set:dayz_inventory image:cat_gp_filling";
			};
		};
		hiddenSelections[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","slotCovered_01","slotCovered_02","slotCovered_03","slotCovered_04","slotCovered_05","slotCovered_06","slotCovered_07","slotCovered_08","slotCovered_09","placing"};
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\soil_cultivated_co.paa","dz\gear\cultivation\data\soil_cultivated_limed_CO.paa","dz\gear\cultivation\data\soil_cultivated_compost_CO.paa","","","","","","","","","","","","","","","","dz\gear\cultivation\data\tile_co.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","","","","","","","","","","dz\gear\cultivation\data\tile.rvmat"};
		hologramMaterial = "tile";
		hologramMaterialPath = "dz\gear\cultivation\data";
		class AnimationSources
		{
			class slotVisible
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class slotHidden: slotVisible
			{
				initPhase = 1;
			};
			class SeedBase_1: slotVisible{};
			class SeedBase_2: slotVisible{};
			class SeedBase_3: slotVisible{};
			class SeedBase_4: slotVisible{};
			class SeedBase_5: slotVisible{};
			class SeedBase_6: slotVisible{};
			class SeedBase_7: slotVisible{};
			class SeedBase_8: slotVisible{};
			class SeedBase_9: slotVisible{};
			class slotCovered_01: slotHidden{};
			class slotCovered_02: slotHidden{};
			class slotCovered_03: slotHidden{};
			class slotCovered_04: slotHidden{};
			class slotCovered_05: slotHidden{};
			class slotCovered_06: slotHidden{};
			class slotCovered_07: slotHidden{};
			class slotCovered_08: slotHidden{};
			class slotCovered_09: slotHidden{};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class DamageSystem
		{
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
		};
	};
	class GardenPlotPlacing: GardenPlot
	{
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		model = "DZ\gear\cultivation\garden_plot_outside_placing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\cultivation\data\tile_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\cultivation\data\tile.rvmat"};
		hologramMaterial = "tile";
		hologramMaterialPath = "dz\gear\cultivation\data";
		class DamageSystem
		{
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
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class HorticultureBaseProxies: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","SeedBase_10","SeedBase_11","SeedBase_12","SeedBase_13"};
	};
	class ProxyTomato_Seeds: ProxyAttachment
	{
		model = "DZ\gear\cultivation\tomato_seeds.p3d";
		scope = 2;
		inventorySlot[] = {"SeedBase_1","SeedBase_2","SeedBase_3","SeedBase_4","SeedBase_5","SeedBase_6","SeedBase_7","SeedBase_8","SeedBase_9","SeedBase_10","SeedBase_11","SeedBase_12","SeedBase_13"};
	};
};
