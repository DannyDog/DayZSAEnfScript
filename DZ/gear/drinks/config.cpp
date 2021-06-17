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
	class DZ_Gear_Drinks
	{
		units[] = {"Drink_Canteen","Drink_SodaZlutaKlasik","Drink_SodaZlutaKolaloka","Drink_SodaZlutaMalinovka","Drink_WaterBottle"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Edible_Base;
	class Bottle_Base;
	class Canteen: Bottle_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Canteen0";
		descriptionShort = "$STR_CfgVehicles_Canteen1";
		model = "\dz\gear\drinks\Canteen.p3d";
		inventorySlot[] = {"Belt_Left"};
		weight = 250;
		itemSize[] = {2,2};
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		varLiquidTypeInit = 512;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256) -32768";
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\drinks\data\Canteen.rvmat"}},{0.7,{"DZ\gear\drinks\data\Canteen.rvmat"}},{0.5,{"DZ\gear\drinks\data\Canteen_damage.rvmat"}},{0.3,{"DZ\gear\drinks\data\Canteen_damage.rvmat"}},{0.0,{"DZ\gear\drinks\data\Canteen_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Canteen_in_B
				{
					soundSet = "Canteen_in_B_SoundSet";
					id = 202;
				};
				class Canteen_in_C
				{
					soundSet = "Canteen_in_C_SoundSet";
					id = 203;
				};
				class WaterBottle_in_C1
				{
					soundSet = "WaterBottle_in_C1_SoundSet";
					id = 204;
				};
				class Canteen_out_A
				{
					soundSet = "Canteen_out_A_SoundSet";
					id = 205;
				};
				class Canteen_out_B
				{
					soundSet = "Canteen_out_B_SoundSet";
					id = 206;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
			};
		};
	};
	class WaterBottle: Bottle_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_WaterBottle0";
		descriptionShort = "$STR_CfgVehicles_WaterBottle1";
		model = "\dz\gear\drinks\WaterBottle.p3d";
		weight = 25;
		itemSize[] = {1,3};
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		varLiquidTypeInit = 512;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256) -32768";
		varQuantityInit = 1000.0;
		varQuantityMin = 0.0;
		varQuantityMax = 1000.0;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"}},{0.7,{"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"}},{0.5,{"DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"}},{0.3,{"DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"}},{0.0,{"DZ\gear\drinks\data\Loot_WaterBottle_destruct.rvmat"}}};
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
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "WaterBottle_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class Vodka: Bottle_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Vodka0";
		descriptionShort = "$STR_CfgVehicles_Vodka1";
		model = "\dz\gear\drinks\VodkaBottles.p3d";
		weight = 450;
		itemSize[] = {1,3};
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		varLiquidTypeInit = 2048;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256) -32768";
		varQuantityInit = 500.0;
		varQuantityMin = 0.0;
		varQuantityMax = 500.0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\drinks\data\VodkaBottles.rvmat"}},{0.7,{"DZ\gear\drinks\data\VodkaBottles.rvmat"}},{0.5,{"DZ\gear\drinks\data\VodkaBottles_damage.rvmat"}},{0.3,{"DZ\gear\drinks\data\VodkaBottles_damage.rvmat"}},{0.0,{"DZ\gear\drinks\data\VodkaBottles_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class GlassBottle_in_B
				{
					soundSet = "GlassBottle_in_B_SoundSet";
					id = 202;
				};
				class GlassBottle_in_C
				{
					soundSet = "GlassBottle_in_C_SoundSet";
					id = 203;
				};
				class WaterBottle_in_C1
				{
					soundSet = "WaterBottle_in_C1_SoundSet";
					id = 204;
				};
				class GlassBottle_out_A
				{
					soundSet = "GlassBottle_out_A_SoundSet";
					id = 205;
				};
				class GlassBottle_out_B
				{
					soundSet = "GlassBottle_out_B_SoundSet";
					id = 206;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
			};
		};
	};
	class WaterPouch_ColorBase: Bottle_Base
	{
		displayName = "$STR_CfgVehicles_WaterPouch_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_WaterPouch_ColorBase1";
		model = "\dz\gear\drinks\waterpouch.p3d";
		lootCategory = "Crafted";
		weight = 250;
		itemSize[] = {2,4};
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256) -32768";
		varQuantityInit = 0.0;
		varQuantityMin = 0.0;
		varQuantityMax = 1250.0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\drinks\data\Drink_WaterPouch_Natural.rvmat"}},{0.7,{"DZ\gear\drinks\data\Drink_WaterPouch_Natural.rvmat"}},{0.5,{"DZ\gear\drinks\data\Drink_WaterPouch_Natural_damage.rvmat"}},{0.3,{"DZ\gear\drinks\data\Drink_WaterPouch_Natural_damage.rvmat"}},{0.0,{"DZ\gear\drinks\data\Drink_WaterPouch_Natural_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class WaterPouch_in_B
				{
					soundSet = "WaterPouch_in_B_SoundSet";
					id = 202;
				};
				class WaterPouch_in_C
				{
					soundSet = "WaterPouch_in_C_SoundSet";
					id = 203;
				};
				class WaterBottle_in_C1
				{
					soundSet = "WaterBottle_in_C1_SoundSet";
					id = 204;
				};
				class WaterPouch_out_A
				{
					soundSet = "WaterPouch_out_A_SoundSet";
					id = 205;
				};
				class WaterPouch_out_B
				{
					soundSet = "WaterPouch_out_B_SoundSet";
					id = 206;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
			};
		};
	};
	class WaterPouch_Natural: WaterPouch_ColorBase
	{
		scope = 2;
		rotationFlags = 17;
		hiddenSelectionsMaterials[] = {"DZ\gear\drinks\data\","Drink_WaterPouch_Natural.rvmat","DZ\gear\drinks\data\","Drink_WaterPouch_Natural.rvmat","DZ\gear\drinks\data\","Drink_WaterPouch_Natural.rvmat"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class WaterPouch_in_B
				{
					soundSet = "WaterPouch_in_B_SoundSet";
					id = 202;
				};
				class WaterPouch_in_C
				{
					soundSet = "WaterPouch_in_C_SoundSet";
					id = 203;
				};
				class WaterBottle_in_C1
				{
					soundSet = "WaterBottle_in_C1_SoundSet";
					id = 204;
				};
				class WaterPouch_out_A
				{
					soundSet = "WaterPouch_out_A_SoundSet";
					id = 205;
				};
				class WaterPouch_out_B
				{
					soundSet = "WaterPouch_out_B_SoundSet";
					id = 206;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
			};
		};
	};
	class SodaCan_ColorBase: Edible_Base
	{
		model = "\dz\gear\drinks\SodaCan.p3d";
		stackedRandom = 0;
		itemSize[] = {1,2};
		weight = 15;
		stackedUnit = "";
		varQuantityInit = 300;
		varQuantityMin = 0;
		varQuantityMax = 300;
		hiddenSelections[] = {"camoGround"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\drinks\data\sodacan.rvmat"}},{0.7,{"DZ\gear\drinks\data\sodacan.rvmat"}},{0.5,{"DZ\gear\drinks\data\sodacan_damage.rvmat"}},{0.3,{"DZ\gear\drinks\data\sodacan_damage.rvmat"}},{0.0,{"DZ\gear\drinks\data\sodacan_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			totalVolume = 1;
			energy = 50;
			water = 150;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class SodaCan_Pipsi: SodaCan_ColorBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SodaCan_Pipsi0";
		descriptionShort = "$STR_CfgVehicles_SodaCan_Pipsi1";
		hiddenSelectionsTextures[] = {"\dz\gear\drinks\Data\SodaCan_pipsi_co.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet = "SodaCan_in_B_SoundSet";
					id = 202;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "SodaCan_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SodaCan_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SodaCan_Cola: SodaCan_ColorBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SodaCan_Cola0";
		descriptionShort = "$STR_CfgVehicles_SodaCan_Cola1";
		hiddenSelectionsTextures[] = {"\dz\gear\drinks\Data\SodaCan_cola_co.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet = "SodaCan_in_B_SoundSet";
					id = 202;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "SodaCan_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SodaCan_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SodaCan_Spite: SodaCan_ColorBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SodaCan_Spite0";
		descriptionShort = "$STR_CfgVehicles_SodaCan_Spite1";
		hiddenSelectionsTextures[] = {"\dz\gear\drinks\Data\SodaCan_spite_co.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet = "SodaCan_in_B_SoundSet";
					id = 202;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "SodaCan_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SodaCan_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SodaCan_Kvass: SodaCan_ColorBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SodaCan_Kvass0";
		descriptionShort = "$STR_CfgVehicles_SodaCan_Kvass1";
		hiddenSelectionsTextures[] = {"\dz\gear\drinks\Data\SodaCan_rasputin_kvass_co.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet = "SodaCan_in_B_SoundSet";
					id = 202;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "SodaCan_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SodaCan_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SodaCan_Empty: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SodaCan_Empty0";
		descriptionShort = "$STR_CfgVehicles_SodaCan_Empty1";
		model = "\dz\gear\drinks\SodaCan_Used.p3d";
		inventorySlot[] = {"tripWireAttachment"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet = "SodaCan_in_B_SoundSet";
					id = 202;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "SodaCan_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SodaCan_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SodaCan_Fronta: SodaCan_ColorBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SodaCan_Fronta0";
		descriptionShort = "$STR_CfgVehicles_SodaCan_Fronta1";
		hiddenSelectionsTextures[] = {"\dz\gear\drinks\Data\SodaCan_Fanda_co.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet = "SodaCan_in_B_SoundSet";
					id = 202;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
				class pickup
				{
					soundSet = "SodaCan_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SodaCan_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxySodaCan_Used: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"tripWireAttachment"};
		model = "\dz\gear\drinks\SodaCan_Used.p3d";
	};
};
