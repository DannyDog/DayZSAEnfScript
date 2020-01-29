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
	class DZ_Gear_Medical
	{
		units[] = {"Medical_DisinfectantSpray","Medical_Antibiotics","Medical_Bandage","Medical_Bloodbag","Medical_Defibrillator","Medical_Epinephrine","Medical_Morphine","Medical_Painkiller"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Switchable_Base;
	class Edible_Base;
	class Bottle_Base;
	class BandageDressing: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BandageDressing0";
		descriptionShort = "$STR_CfgVehicles_BandageDressing1";
		model = "\dz\gear\medical\Bandage_dressing.p3d";
		inventorySlot[] = {"MedicalBandage"};
		isMeleeWeapon = 1;
		varQuantityInit = 4;
		varQuantityMin = 0;
		varQuantityMax = 4;
		quantityBar = 1;
		varQuantityDestroyOnMin = 1;
		rotationFlags = 17;
		weight = 115;
		absorbency = 0.8;
		itemSize[] = {1,2};
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\bandage.rvmat"}},{0.7,{"DZ\gear\medical\data\bandage.rvmat"}},{0.5,{"DZ\gear\medical\data\bandage_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\bandage_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\bandage_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Bandage_loop1
				{
					soundSet = "Bandage_loop_SoundSet";
					id = 201;
				};
				class Bandage_loop2
				{
					soundSet = "Bandage_loop_SoundSet";
					id = 202;
				};
				class Bandage_loop3
				{
					soundSet = "Bandage_loop_SoundSet";
					id = 203;
				};
				class Bandage_start
				{
					soundSet = "Bandage_start_SoundSet";
					id = 204;
				};
				class Bandage_end
				{
					soundSet = "Bandage_end_SoundSet";
					id = 205;
				};
			};
		};
	};
	class DisinfectantSpray: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_DisinfectantSpray0";
		descriptionShort = "$STR_CfgVehicles_DisinfectantSpray1";
		model = "\dz\gear\medical\DisinfectantSpray.p3d";
		inventorySlot[] = {"Disinfectant"};
		quantityBar = 1;
		weight = 50;
		stackedUnit = "ml";
		itemSize[] = {1,3};
		varLiquidTypeInit = 32768;
		varQuantityInit = 500;
		varQuantityMin = 0;
		varQuantityMax = 500;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = -10;
			water = 1;
			nutritionalIndex = 55;
			toxicity = 0.3;
			digestibility = 2;
			agents = 16;
		};
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
		class AnimEvents
		{
			class SoundWeapon
			{
				class WaterBottle_in_B
				{
					soundSet = "WaterBottle_in_B_SoundSet";
					id = 202;
				};
				class WaterBottle_in_C
				{
					soundSet = "WaterBottle_in_C_SoundSet";
					id = 203;
				};
				class WaterBottle_in_C1
				{
					soundSet = "WaterBottle_in_C1_SoundSet";
					id = 204;
				};
				class WaterBottle_out_A
				{
					soundSet = "WaterBottle_out_A_SoundSet";
					id = 205;
				};
				class WaterBottle_out_B
				{
					soundSet = "WaterBottle_out_B_SoundSet";
					id = 206;
				};
				class disinfectant_loop
				{
					soundSet = "disinfectant_loop_SoundSet";
					id = 212;
				};
				class disinfectant_loop2
				{
					soundSet = "disinfectant_loop_SoundSet";
					id = 213;
				};
				class pickUpItem
				{
					soundSet = "pickUpWatterBottle_SoundSet";
					id = 797;
				};
			};
		};
	};
	class DisinfectantAlcohol: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_DisinfectantAlcohol0";
		descriptionShort = "$STR_CfgVehicles_DisinfectantAlcohol1";
		model = "\dz\gear\medical\alfa.p3d";
		isMeleeWeapon = 1;
		weight = 50;
		itemSize[] = {1,2};
		varQuantityInit = 200;
		varQuantityMin = 0;
		varQuantityMax = 200;
		varQuantityDestroyOnMin = 1;
		varLiquidTypeInit = 32768;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = -10;
			water = 1;
			nutritionalIndex = 55;
			toxicity = 0.3;
			digestibility = 2;
			agents = 16;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\alfa.rvmat"}},{0.7,{"DZ\gear\medical\data\alfa.rvmat"}},{0.5,{"DZ\gear\medical\data\alfa_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\alfa_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\alfa_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class CleanWound_start
				{
					soundSet = "CleanWound_start_SoundSet";
					id = 201;
				};
				class CleanWound_loop
				{
					soundSet = "CleanWound_loop_SoundSet";
					id = 202;
				};
				class CleanWound_loop2
				{
					soundSet = "CleanWound_loop_SoundSet";
					id = 203;
				};
				class CleanWound_loop3
				{
					soundSet = "CleanWound_loop_SoundSet";
					id = 204;
				};
				class CleanWound_loop4
				{
					soundSet = "CleanWound_loop_SoundSet";
					id = 205;
				};
			};
		};
	};
	class PurificationTablets: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PurificationTablets0";
		descriptionShort = "$STR_CfgVehicles_PurificationTablets1";
		model = "\dz\gear\medical\Water_purification_tablets.p3d";
		rotationFlags = 17;
		varQuantityInit = 10;
		varQuantityMin = 0;
		varQuantityMax = 10;
		itemSize[] = {1,2};
		weight = 20;
		stackedUnit = "pills";
		quantityBar = 0;
		absorbency = 0.7;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\water_purification_tablets.rvmat"}},{0.7,{"DZ\gear\medical\data\water_purification_tablets.rvmat"}},{0.5,{"DZ\gear\medical\data\water_purification_tablets_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\water_purification_tablets_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\water_purification_tablets_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Tablets_open
				{
					soundSet = "Tablets_open_SoundSet";
					id = 201;
				};
				class Tablets_catch
				{
					soundSet = "Tablets_catch_SoundSet";
					id = 202;
				};
				class Tablets_close
				{
					soundSet = "Tablets_close_SoundSet";
					id = 203;
				};
				class pickup
				{
					soundSet = "purificationtablets_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "purificationtablets_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CharcoalTablets: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CharcoalTablets0";
		descriptionShort = "$STR_CfgVehicles_CharcoalTablets1";
		model = "\dz\gear\medical\charcoal_tablets.p3d";
		rotationFlags = 17;
		varQuantityInit = 12;
		varQuantityMin = 0;
		varQuantityMax = 12;
		varQuantityDestroyOnMin = 1;
		itemSize[] = {1,2};
		weight = 20;
		stackedUnit = "pills";
		quantityBar = 0;
		absorbency = 0.9;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\charcoal_tablets.rvmat"}},{0.7,{"DZ\gear\medical\data\charcoal_tablets.rvmat"}},{0.5,{"DZ\gear\medical\data\charcoal_tablets_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\charcoal_tablets_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\charcoal_tablets_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Tablets_open
				{
					soundSet = "Tablets_open_SoundSet";
					id = 201;
				};
				class Tablets_catch
				{
					soundSet = "Tablets_catch_SoundSet";
					id = 202;
				};
				class Tablets_close
				{
					soundSet = "Tablets_close_SoundSet";
					id = 203;
				};
				class pickup
				{
					soundSet = "purificationtablets_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "purificationtablets_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class PainkillerTablets: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PainkillerTablets0";
		descriptionShort = "$STR_CfgVehicles_PainkillerTablets1";
		model = "\dz\gear\medical\painkillers2.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		varQuantityInit = 12;
		varQuantityMin = 0;
		varQuantityMax = 12;
		varQuantityDestroyOnMin = 1;
		weight = 20;
		stackedUnit = "pills";
		quantityBar = 0;
		absorbency = 0.7;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\painkiller2.rvmat"}},{0.7,{"DZ\gear\medical\data\painkiller2.rvmat"}},{0.5,{"DZ\gear\medical\data\painkiller2_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\painkiller2_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\painkiller2_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Tablets_open
				{
					soundSet = "Tablets_open_SoundSet";
					id = 201;
				};
				class Tablets_catch
				{
					soundSet = "Tablets_catch_SoundSet";
					id = 202;
				};
				class Tablets_close
				{
					soundSet = "Tablets_close_SoundSet";
					id = 203;
				};
				class pickup
				{
					soundSet = "purificationtablets_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "purificationtablets_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class VitaminBottle: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_VitaminBottle0";
		descriptionShort = "$STR_CfgVehicles_VitaminBottle1";
		model = "\dz\gear\medical\VitaminBottle.p3d";
		varQuantityInit = 50;
		varQuantityMin = 0;
		varQuantityMax = 50;
		varQuantityDestroyOnMin = 1;
		itemSize[] = {1,2};
		weight = 20;
		stackedUnit = "pills";
		quantityBar = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\vitamin_bottle.rvmat"}},{0.7,{"DZ\gear\medical\data\vitamin_bottle.rvmat"}},{0.5,{"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\vitamin_bottle_destruct.rvmat"}}};
				};
			};
		};
		class Medicine
		{
			prevention = 0.75;
			treatment = 0.5;
			diseaseExit = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class VitaminBottle_open
				{
					soundSet = "VitaminBottle_open_SoundSet";
					id = 201;
				};
				class VitaminBottle_shake
				{
					soundSet = "VitaminBottle_shake_SoundSet";
					id = 202;
				};
				class VitaminBottle_close
				{
					soundSet = "VitaminBottle_close_SoundSet";
					id = 203;
				};
				class pickUpItem
				{
					soundSet = "vitaminbottle_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class TetracyclineAntibiotics: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TetracyclineAntibiotics0";
		descriptionShort = "$STR_CfgVehicles_TetracyclineAntibiotics1";
		model = "\dz\gear\medical\tetracycline.p3d";
		rotationFlags = 17;
		varQuantityInit = 12;
		varQuantityMin = 0;
		varQuantityMax = 12;
		varQuantityDestroyOnMin = 1;
		itemSize[] = {1,2};
		weight = 20;
		stackedUnit = "pills";
		quantityBar = 0;
		absorbency = 0.7;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\tetracycline.rvmat"}},{0.7,{"DZ\gear\medical\data\tetracycline.rvmat"}},{0.5,{"DZ\gear\medical\data\tetracycline_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\tetracycline_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\tetracycline_destruct.rvmat"}}};
				};
			};
		};
		class Medicine
		{
			prevention = 0;
			treatment = 0.9;
			diseaseExit = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Tablets_open
				{
					soundSet = "Tablets_open_SoundSet";
					id = 201;
				};
				class Tablets_catch
				{
					soundSet = "Tablets_catch_SoundSet";
					id = 202;
				};
				class Tablets_close
				{
					soundSet = "Tablets_close_SoundSet";
					id = 203;
				};
				class pickup
				{
					soundSet = "purificationtablets_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "purificationtablets_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Epinephrine: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Epinephrine0";
		descriptionShort = "$STR_CfgVehicles_Epinephrine1";
		model = "\dz\gear\medical\Epinephrine.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\epipen.rvmat"}},{0.7,{"DZ\gear\medical\data\epipen.rvmat"}},{0.5,{"DZ\gear\medical\data\epipen_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\epipen_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\epipen_destruct.rvmat"}}};
				};
			};
		};
	};
	class Morphine: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Morphine0";
		descriptionShort = "$STR_CfgVehicles_Morphine1";
		model = "\dz\gear\medical\Morphine.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 60;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\Morphine.rvmat"}},{0.7,{"DZ\gear\medical\data\Morphine.rvmat"}},{0.5,{"DZ\gear\medical\data\Morphine_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\Morphine_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\Morphine_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Morphine_spear
				{
					soundSet = "Morphine_spear_SoundSet";
					id = 201;
				};
				class Morphine_out
				{
					soundSet = "Morphine_out_SoundSet";
					id = 202;
				};
			};
		};
	};
	class Syringe: Epinephrine
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Syringe0";
		descriptionShort = "$STR_CfgVehicles_Syringe1";
		model = "\dz\gear\medical\syringe_empty.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 130;
		stackedUnit = "ml";
		quantityBar = 1;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		varQuantityInit = 0.0;
		varQuantityMin = 0.0;
		varQuantityMax = 0.0;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\Syringe.rvmat"}},{0.7,{"DZ\gear\medical\data\Syringe.rvmat"}},{0.5,{"DZ\gear\medical\data\Syringe_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\Syringe_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\Syringe_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Syringe_out
				{
					soundSet = "Syringe_out_SoundSet";
					id = 201;
				};
				class Syringe_spear
				{
					soundSet = "Syringe_spear_SoundSet";
					id = 202;
				};
				class Syringe_splash
				{
					soundSet = "Syringe_splash_SoundSet";
					id = 203;
				};
			};
		};
	};
	class ClearSyringe: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Syringe0";
		descriptionShort = "$STR_CfgVehicles_Syringe1";
		model = "\dz\gear\medical\syringe_Full.p3d";
		rotationFlags = 17;
		weight = 110;
		itemSize[] = {1,2};
		stackedUnit = "ml";
		quantityBar = 1;
		varQuantityInit = 20;
		varQuantityMin = 0.0;
		varQuantityMax = 20;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dz\gear\medical\data\SyringeFluid_Grey_CA.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\Syringe.rvmat"}},{0.7,{"DZ\gear\medical\data\Syringe.rvmat"}},{0.5,{"DZ\gear\medical\data\Syringe_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\Syringe_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\Syringe_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Syringe_out
				{
					soundSet = "Syringe_out_SoundSet";
					id = 201;
				};
				class Syringe_spear
				{
					soundSet = "Syringe_spear_SoundSet";
					id = 202;
				};
				class Syringe_splash
				{
					soundSet = "Syringe_splash_SoundSet";
					id = 203;
				};
			};
		};
	};
	class BloodSyringe: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Syringe0";
		descriptionShort = "$STR_CfgVehicles_Syringe1";
		model = "\dz\gear\medical\syringe_Full.p3d";
		rotationFlags = 17;
		weight = 110;
		itemSize[] = {1,2};
		stackedUnit = "ml";
		quantityBar = 1;
		varQuantityInit = 20;
		varQuantityMin = 0.0;
		varQuantityMax = 20;
		varLiquidTypeInit = 4;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dz\gear\medical\data\SyringeFluid_Blood_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\Syringe.rvmat"}},{0.7,{"DZ\gear\medical\data\Syringe.rvmat"}},{0.5,{"DZ\gear\medical\data\Syringe_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\Syringe_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\Syringe_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Syringe_out
				{
					soundSet = "Syringe_out_SoundSet";
					id = 201;
				};
				class Syringe_spear
				{
					soundSet = "Syringe_spear_SoundSet";
					id = 202;
				};
				class Syringe_splash
				{
					soundSet = "Syringe_splash_SoundSet";
					id = 203;
				};
			};
		};
	};
	class InjectionVial: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_InjectionVial0";
		descriptionShort = "$STR_CfgVehicles_InjectionVial1";
		model = "\dz\gear\medical\InjectionVial.p3d";
		itemSize[] = {1,1};
		weight = 50;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\InjectionVial.rvmat"}},{0.7,{"DZ\gear\medical\data\InjectionVial.rvmat"}},{0.5,{"DZ\gear\medical\data\InjectionVial_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\InjectionVial_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\InjectionVial_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "injectionvial_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class SalineBag: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SalineBag0";
		descriptionShort = "$STR_CfgVehicles_SalineBag1";
		model = "\dz\gear\medical\SalineBag.p3d";
		rotationFlags = 17;
		itemSize[] = {2,2};
		weight = 100;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\Saline_Bag.rvmat"}},{0.7,{"DZ\gear\medical\data\Saline_Bag.rvmat"}},{0.5,{"DZ\gear\medical\data\Saline_Bag_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\Saline_Bag_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\Saline_Bag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class BloodBag_start
				{
					soundSet = "BloodBag_start_SoundSet";
					id = 201;
				};
				class BloodBag_spear
				{
					soundSet = "BloodBag_spear_SoundSet";
					id = 202;
				};
				class BloodBag_loop
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 203;
				};
				class BloodBag_loop2
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 204;
				};
				class BloodBag_end
				{
					soundSet = "BloodBag_end_SoundSet";
					id = 205;
				};
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "bloodbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class StartKitIV: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_StartKitIV0";
		descriptionShort = "$STR_CfgVehicles_StartKitIV1";
		model = "\dz\gear\medical\StartKit.p3d";
		itemSize[] = {1,2};
		rotationFlags = 17;
		weight = 100;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\start_kit.rvmat"}},{0.7,{"DZ\gear\medical\data\start_kit.rvmat"}},{0.5,{"DZ\gear\medical\data\start_kit_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\start_kit_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\start_kit_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class BloodBag_start
				{
					soundSet = "BloodBag_start_SoundSet";
					id = 201;
				};
				class BloodBag_spear
				{
					soundSet = "BloodBag_spear_SoundSet";
					id = 202;
				};
				class BloodBag_loop
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 203;
				};
				class BloodBag_loop2
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 204;
				};
				class BloodBag_end
				{
					soundSet = "BloodBag_end_SoundSet";
					id = 205;
				};
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "bloodbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SalineBagIV: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SalineBagIV0";
		descriptionShort = "$STR_CfgVehicles_SalineBagIV1";
		model = "\dz\gear\medical\TransfusionKit.p3d";
		rotationFlags = 17;
		itemSize[] = {2,2};
		weight = 200;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\transfusion_kit.rvmat"}},{0.7,{"DZ\gear\medical\data\transfusion_kit.rvmat"}},{0.5,{"DZ\gear\medical\data\transfusion_kit_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\transfusion_kit_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\transfusion_kit_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class BloodBag_start
				{
					soundSet = "BloodBag_start_SoundSet";
					id = 201;
				};
				class BloodBag_spear
				{
					soundSet = "BloodBag_spear_SoundSet";
					id = 202;
				};
				class BloodBag_loop
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 203;
				};
				class BloodBag_loop2
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 204;
				};
				class BloodBag_end
				{
					soundSet = "BloodBag_end_SoundSet";
					id = 205;
				};
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "bloodbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BloodBagEmpty: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BloodBagEmpty0";
		descriptionShort = "$STR_CfgVehicles_BloodBagEmpty1";
		model = "\dz\gear\medical\BloodBag_Sealed.p3d";
		itemSize[] = {1,2};
		weight = 100;
		rotationFlags = 17;
		stackedUnit = "ml";
		quantityBar = 1;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		varQuantityInit = 0.0;
		varQuantityMin = 0.0;
		varQuantityMax = 0.0;
		varLiquidTypeInit = 4;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\BloodBag_Sealed.rvmat"}},{0.7,{"DZ\gear\medical\data\BloodBag_Sealed.rvmat"}},{0.5,{"DZ\gear\medical\data\BloodBag_Sealed_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\BloodBag_Sealed_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\BloodBag_Sealed_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class BloodBag_start
				{
					soundSet = "BloodBag_start_SoundSet";
					id = 201;
				};
				class BloodBag_spear
				{
					soundSet = "BloodBag_spear_SoundSet";
					id = 202;
				};
				class BloodBag_loop
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 203;
				};
				class BloodBag_loop2
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 204;
				};
				class BloodBag_end
				{
					soundSet = "BloodBag_end_SoundSet";
					id = 205;
				};
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "bloodbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BloodBagFull: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BloodBagFull0";
		descriptionShort = "$STR_CfgVehicles_BloodBagFull1";
		model = "\dz\gear\medical\BloodBag_Full.p3d";
		rotationFlags = 17;
		itemSize[] = {2,2};
		weight = 100;
		stackedUnit = "ml";
		quantityBar = 1;
		varQuantityInit = 500.0;
		varQuantityMin = 0.0;
		varQuantityMax = 500.0;
		varLiquidTypeInit = 4;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\BloodBag_Full.rvmat"}},{0.7,{"DZ\gear\medical\data\BloodBag_Full.rvmat"}},{0.5,{"DZ\gear\medical\data\BloodBag_Full_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\BloodBag_Full_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\BloodBag_Full_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class BloodBag_start
				{
					soundSet = "BloodBag_start_SoundSet";
					id = 201;
				};
				class BloodBag_spear
				{
					soundSet = "BloodBag_spear_SoundSet";
					id = 202;
				};
				class BloodBag_loop
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 203;
				};
				class BloodBag_loop2
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 204;
				};
				class BloodBag_end
				{
					soundSet = "BloodBag_end_SoundSet";
					id = 205;
				};
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "bloodbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BloodBagIV: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BloodBagIV0";
		descriptionShort = "$STR_CfgVehicles_BloodBagIV1";
		model = "\dz\gear\medical\BloodBag_Full_IV.p3d";
		rotationFlags = 17;
		itemSize[] = {2,2};
		weight = 110;
		quantityBar = 1;
		stackedUnit = "ml";
		varQuantityInit = 500.0;
		varQuantityMin = 0.0;
		varQuantityMax = 500.0;
		varQuantityDestroyOnMin = 1;
		varLiquidTypeInit = 4;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\BloodBag_Full.rvmat"}},{0.7,{"DZ\gear\medical\data\BloodBag_Full.rvmat"}},{0.5,{"DZ\gear\medical\data\BloodBag_Full_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\BloodBag_Full_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\BloodBag_Full_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class BloodBag_start
				{
					soundSet = "BloodBag_start_SoundSet";
					id = 201;
				};
				class BloodBag_spear
				{
					soundSet = "BloodBag_spear_SoundSet";
					id = 202;
				};
				class BloodBag_loop
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 203;
				};
				class BloodBag_loop2
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 204;
				};
				class BloodBag_end
				{
					soundSet = "BloodBag_end_SoundSet";
					id = 205;
				};
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "bloodbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BloodTestKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BloodTestKit0";
		descriptionShort = "$STR_CfgVehicles_BloodTestKit1";
		model = "\dz\gear\medical\BloodTest_Kit.p3d";
		itemSize[] = {1,1};
		rotationFlags = 17;
		weight = 130;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\BloodTest.rvmat"}},{0.7,{"DZ\gear\medical\data\BloodTest.rvmat"}},{0.5,{"DZ\gear\medical\data\BloodTest_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\BloodTest_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\BloodTest_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class BloodBag_start
				{
					soundSet = "BloodBag_start_SoundSet";
					id = 201;
				};
				class BloodBag_spear
				{
					soundSet = "BloodBag_spear_SoundSet";
					id = 202;
				};
				class BloodBag_loop
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 203;
				};
				class BloodBag_loop2
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 204;
				};
				class BloodBag_end
				{
					soundSet = "BloodBag_end_SoundSet";
					id = 205;
				};
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "bloodbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Splint: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Splint0";
		descriptionShort = "$STR_CfgVehicles_Splint1";
		model = "\dz\gear\medical\improvised_fixture.p3d";
		rotationFlags = 17;
		itemSize[] = {2,4};
		weight = 540;
		absorbency = 0.3;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\improvised_fixture.rvmat"}},{0.7,{"DZ\gear\medical\data\improvised_fixture.rvmat"}},{0.5,{"DZ\gear\medical\data\improvised_fixture_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\improvised_fixture_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\improvised_fixture_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class cover
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 3.3;
			};
		};
	};
	class Thermometer: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Thermometer0";
		descriptionShort = "$STR_CfgVehicles_Thermometer1";
		model = "\dz\gear\medical\med_tmeter.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 15;
		fragility = 0.5;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\med_tmeter.rvmat"}},{0.7,{"DZ\gear\medical\data\med_tmeter.rvmat"}},{0.5,{"DZ\gear\medical\data\med_tmeter_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\med_tmeter_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\med_tmeter_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class cover
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 1;
			};
		};
	};
	class Defibrillator: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Defibrillator0";
		descriptionShort = "$STR_CfgVehicles_Defibrillator1";
		model = "\dz\gear\medical\Defibrillator.p3d";
		animClass = "NoFireClass";
		weight = 1200;
		itemSize[] = {4,4};
		defibChargeTime = 8.35;
		defibEnergyNeededPerCharge = 9;
		absorbency = 0.3;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\defibrillator.rvmat"}},{0.7,{"DZ\gear\medical\data\defibrillator.rvmat"}},{0.5,{"DZ\gear\medical\data\defibrillator_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\defibrillator_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\defibrillator_destruct.rvmat"}}};
				};
			};
		};
		attachments[] = {"BatteryD"};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.02;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.5;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "sewingkit_pickup_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "sewingkit_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "ammobox_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CigarettePack_ColorBase: Inventory_Base
	{
		displayName = "$STR_CfgVehicles_CigarettePack_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_CigarettePack_ColorBase1";
		model = "\dz\gear\medical\cigarette_pack.p3d";
		itemSize[] = {1,1};
		weight = 50;
		varQuantityInit = 20.0;
		varQuantityMin = 0.0;
		varQuantityMax = 20.0;
		absorbency = 0.7;
		hiddenSelections[] = {"camoGround","zbytek"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 25;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\Pack_of_cigs.rvmat"}},{0.7,{"DZ\gear\medical\data\Pack_of_cigs.rvmat"}},{0.5,{"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\Pack_of_cigs_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\Pack_of_cigs_destruct.rvmat"}}};
				};
			};
		};
		class Medicine
		{
			prevention = 0;
			treatment = 0.9;
			diseaseExit = 1;
		};
	};
	class CigarettePack_Chernamorka: CigarettePack_ColorBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CigarettePack_Chernamorka0";
		hiddenSelectionsTextures[] = {"DZ\gear\medical\Data\pack_of_cigs_cherno_co.paa","DZ\gear\medical\Data\pack_of_cigs_cherno_co.paa"};
	};
	class CigarettePack_Merkur: CigarettePack_ColorBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CigarettePack_Merkur0";
		hiddenSelectionsTextures[] = {"DZ\gear\medical\Data\pack_of_cigs_merkur_co.paa","DZ\gear\medical\Data\pack_of_cigs_merkur_co.paa"};
	};
	class CigarettePack_Partyzanka: CigarettePack_ColorBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CigarettePack_Partyzanka0";
		hiddenSelectionsTextures[] = {"DZ\gear\medical\Data\pack_of_cigs_partyzanka_co.paa","DZ\gear\medical\Data\pack_of_cigs_partyzanka_co.paa"};
	};
};
