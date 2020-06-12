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
	class DZ_Gear_Containers
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class WorldContainer_Base;
	class Barrel_ColorBase: Container_Base
	{
		displayName = "$STR_CfgVehicles_Barrel_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_Barrel_ColorBase1";
		model = "\dz\gear\containers\55galDrum.p3d";
		overrideDrawArea = "8.0";
		forceFarBubble = "true";
		slopeTolerance = 0.3;
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		quantityBar = 1;
		carveNavmesh = 1;
		canBeDigged = 0;
		heavyItem = 1;
		weight = 10000;
		itemSize[] = {10,15};
		itemBehaviour = 0;
		stackedUnit = "ml";
		randomQuantity = 2;
		varLiquidTypeInit = 512;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit = 0.0;
		varQuantityMin = 0.0;
		varQuantityMax = 200000.0;
		absorbency = 0.1;
		physLayer = "item_large";
		allowOwnedCargoManipulation = 1;
		hiddenSelections[] = {"camoGround"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1300;
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage = 8.0;
					};
					class Blood
					{
						damage = 8.0;
					};
					class Shock
					{
						damage = 8.0;
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,15};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class AnimationSources
		{
			class Lid
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
			};
			class Lid2
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "barrel_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpBarrelLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpBarrel_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "barrel_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Barrel_Green: Barrel_ColorBase
	{
		scope = 2;
		color = "Green";
		hiddenSelectionsTextures[] = {"\dz\gear\containers\data\barrel_green_co.paa"};
		hologramMaterial = "barrel";
		hologramMaterialPath = "dz\gear\containers\data";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\gear\containers\data\barrel_green.rvmat"};
					healthLevels[] = {{1.0,{"dz\gear\containers\data\barrel_green.rvmat"}},{0.7,{"dz\gear\containers\data\barrel_green.rvmat"}},{0.5,{"dz\gear\containers\data\barrel_green_damage.rvmat"}},{0.3,{"dz\gear\containers\data\barrel_green_damage.rvmat"}},{0.0,{"dz\gear\containers\data\barrel_green_destruct.rvmat"}}};
				};
			};
		};
	};
	class Barrel_Blue: Barrel_ColorBase
	{
		scope = 2;
		color = "Blue";
		hiddenSelectionsTextures[] = {"\dz\gear\containers\data\barrel_blue_co.paa"};
		hologramMaterial = "barrel";
		hologramMaterialPath = "dz\gear\containers\data";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\gear\containers\data\barrel_green.rvmat"};
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\barrel_blue.rvmat"}},{0.7,{"DZ\gear\containers\data\barrel_blue.rvmat"}},{0.5,{"DZ\gear\containers\data\barrel_blue_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\barrel_blue_damage.rvmat"}},{0.0,{"DZ\gear\containers\data\barrel_blue_destruct.rvmat"}}};
				};
			};
		};
	};
	class Barrel_Red: Barrel_ColorBase
	{
		scope = 2;
		color = "Red";
		hiddenSelectionsTextures[] = {"\dz\gear\containers\data\barrel_red_co.paa"};
		hologramMaterial = "barrel";
		hologramMaterialPath = "dz\gear\containers\data";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\gear\containers\data\barrel_green.rvmat"};
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\barrel_red.rvmat"}},{0.7,{"DZ\gear\containers\data\barrel_red.rvmat"}},{0.5,{"DZ\gear\containers\data\barrel_red_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\barrel_red_damage.rvmat"}},{0.0,{"DZ\gear\containers\data\barrel_red_destruct.rvmat"}}};
				};
			};
		};
	};
	class Barrel_Yellow: Barrel_ColorBase
	{
		scope = 2;
		color = "Yellow";
		hiddenSelectionsTextures[] = {"\dz\gear\containers\data\barrel_yellow_co.paa"};
		hologramMaterial = "barrel";
		hologramMaterialPath = "dz\gear\containers\data";
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health: Health
				{
					RefTexsMats[] = {"dz\gear\containers\data\barrel_green.rvmat"};
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\barrel_yellow.rvmat"}},{0.7,{"DZ\gear\containers\data\barrel_yellow.rvmat"}},{0.5,{"DZ\gear\containers\data\barrel_yellow_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\barrel_yellow_damage.rvmat"}},{0.0,{"DZ\gear\containers\data\barrel_yellow_destruct.rvmat"}}};
				};
			};
		};
	};
	class Refrigerator: WorldContainer_Base
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_Refrigerator0";
		descriptionShort = "$STR_CfgVehicles_Refrigerator1";
		model = "\DZ\gear\containers\fridge.p3d";
	};
	class RefrigeratorMinsk: WorldContainer_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_RefrigeratorMinsk0";
		descriptionShort = "$STR_CfgVehicles_RefrigeratorMinsk1";
		model = "\DZ\gear\containers\fridge.p3d";
		weight = 50000;
		itemSize[] = {5,10};
		class Cargo
		{
			itemsCargoSize[] = {2,5};
			openable = 0;
			allowOwnedCargoManipulation = 1;
			cargoReceivesDamage = 0;
			cargoSingleItemMode = 0;
			cargoReceivedDamageCoeff = 0.0;
		};
	};
	class TrashCan: WorldContainer_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TrashCan0";
		descriptionShort = "$STR_CfgVehicles_TrashCan1";
		model = "\DZ\gear\containers\trashcan.p3d";
		weight = 13500;
		itemSize[] = {10,15};
		canBeDigged = 1;
		class Cargo
		{
			itemsCargoSize[] = {5,10};
			openable = 0;
			allowOwnedCargoManipulation = 1;
			cargoReceivesDamage = 0;
			cargoSingleItemMode = 0;
			cargoReceivedDamageCoeff = 0.0;
		};
	};
	class FirstAidKit: Container_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FirstAidKit0";
		descriptionShort = "$STR_CfgVehicles_FirstAidKit1";
		model = "\dz\gear\containers\FirstAidKit.p3d";
		rotationFlags = 17;
		weight = 140;
		itemSize[] = {3,3};
		itemsCargoSize[] = {3,3};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		canBeDigged = 1;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},{0.7,{"DZ\gear\containers\data\FirsAidKit.rvmat"}},{0.5,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\FirsAidKit_damage.rvmat"}},{0.0,{"DZ\gear\containers\data\FirsAidKit_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class SmallProtectorCase: Container_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SmallProtectorCase0";
		descriptionShort = "$STR_CfgVehicles_SmallProtectorCase1";
		model = "\dz\gear\containers\Protector_Case.p3d";
		rotationFlags = 17;
		weight = 980;
		itemSize[] = {3,4};
		itemsCargoSize[] = {3,4};
		canBeDigged = 1;
		isMeleeWeapon = 1;
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 750;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\Protector_Case.rvmat"}},{0.7,{"DZ\gear\containers\data\Protector_Case.rvmat"}},{0.5,{"DZ\gear\containers\data\Protector_Case_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\Protector_Case_damage.rvmat"}},{0.0,{"DZ\gear\containers\data\Protector_Case_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage = 8.0;
					};
					class Blood
					{
						damage = 8.0;
					};
					class Shock
					{
						damage = 8.0;
					};
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
	class PlateCarrierPouches: Container_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CarrierPouches0";
		descriptionShort = "$STR_CfgVehicles_CarrierPouches1";
		model = "\dz\characters\vests\plate_carrier_pouches_g.p3d";
		inventorySlot[] = {"VestPouch"};
		weight = 250;
		itemSize[] = {6,4};
		itemsCargoSize[] = {6,4};
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\BallisticVest.rvmat"}},{0.7,{"DZ\characters\vests\Data\BallisticVest.rvmat"}},{0.5,{"DZ\characters\vests\Data\BallisticVest_damage.rvmat"}},{0.3,{"DZ\characters\vests\Data\BallisticVest_damage.rvmat"}},{0.0,{"DZ\characters\vests\Data\BallisticVest_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class AmmoBox: Container_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox1";
		model = "\dz\gear\containers\300RoundBox.p3d";
		weight = 2250;
		itemSize[] = {5,4};
		itemsCargoSize[] = {5,4};
		allowOwnedCargoManipulation = 1;
		randomQuantity = 4;
		canBeDigged = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\300RoundBox.rvmat"}},{0.7,{"DZ\gear\containers\data\300RoundBox.rvmat"}},{0.5,{"DZ\gear\containers\data\300RoundBox_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\300RoundBox_damage.rvmat"}},{0.0,{"DZ\gear\containers\data\300RoundBox_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
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
	class Bear_ColorBase: Container_Base
	{
		displayName = "$STR_CfgVehicles_Bear_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_Bear_ColorBase1";
		model = "\dz\gear\containers\teddybear.p3d";
		weight = 130;
		itemSize[] = {2,3};
		itemsCargoSize[] = {2,3};
		canBeDigged = 1;
		allowOwnedCargoManipulation = 1;
		hiddenSelections[] = {"camoGround"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\teddybear.rvmat"}},{0.7,{"DZ\gear\containers\data\teddybear.rvmat"}},{0.5,{"DZ\gear\containers\data\teddybear_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\teddybear_damage.rvmat"}},{0.0,{"DZ\gear\containers\data\teddybear_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class Bear_Beige: Bear_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\containers\Data\teddybear_brown_co.paa"};
	};
	class Bear_Dark: Bear_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\containers\Data\teddybear_dark_co.paa"};
	};
	class Bear_Pink: Bear_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\containers\Data\teddybear_pink_co.paa"};
	};
	class Bear_White: Bear_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\containers\Data\teddybear_white_co.paa"};
	};
	class WaterproofBag_ColorBase: Container_Base
	{
		displayName = "$STR_CfgVehicles_WaterproofBag_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_WaterproofBag_ColorBase1";
		model = "\dz\gear\containers\WaterproofBag.p3d";
		rotationFlags = 17;
		weight = 350;
		itemSize[] = {4,5};
		itemsCargoSize[] = {4,5};
		allowOwnedCargoManipulation = 1;
		canBeDigged = 1;
		absorbency = 0;
		heatIsolation = 1;
		repairableWithKits[] = {5,6};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\WaterproofBag.rvmat"}},{0.7,{"DZ\gear\containers\data\WaterproofBag.rvmat"}},{0.5,{"DZ\gear\containers\data\WaterproofBag_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\WaterproofBag_damage.rvmat"}},{0.0,{"DZ\gear\containers\data\WaterproofBag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItemLight
				{
					soundSet = "pickUpGardenLimeLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpGardenLime_SoundSet";
					id = 797;
				};
			};
		};
	};
	class WaterproofBag_Yellow: WaterproofBag_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\containers\Data\WaterproofBag_yellow_co.paa"};
	};
	class WaterproofBag_Green: WaterproofBag_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\containers\Data\WaterproofBag_green_co.paa"};
	};
	class WaterproofBag_Orange: WaterproofBag_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\containers\Data\WaterproofBag_orange_co.paa"};
	};
	class GiftBox_Base: Container_Base
	{
		scope = 0;
		displayName = "$STR_cfgvehicles_xmasboxsmall0";
		descriptionShort = "$STR_cfgvehicles_xmasbox_common1";
		model = "\DZ\gear\containers\ChristmasBox1.p3d";
		weight = 100;
		itemSize[] = {2,2};
		itemsCargoSize[] = {2,2};
		allowOwnedCargoManipulation = 1;
		absorbency = 0;
		reversed = 1;
		hiddenSelections[] = {"ChristmasBox1","ChristmasBox1_ribbon"};
		hiddenSelectionsTextures[] = {"\dz\gear\containers\data\christmas_paper1_CO.paa","\dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN_damage.rvmat"}},{0.3,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN_damage.rvmat"}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Small: GiftBox_Base
	{
		displayName = "$STR_cfgvehicles_xmasboxsmall0";
	};
	class GiftBox_Medium: GiftBox_Base
	{
		displayName = "$STR_cfgvehicles_xmasboxmedium0";
		model = "\DZ\gear\containers\ChristmasBox2.p3d";
		weight = 300;
		itemSize[] = {4,4};
		itemsCargoSize[] = {4,4};
		hiddenSelections[] = {"ChristmasBox2","ChristmasBox2_ribbon"};
	};
	class GiftBox_Large: GiftBox_Base
	{
		displayName = "$STR_cfgvehicles_xmasboxlarge0";
		model = "\DZ\gear\containers\ChristmasBox3.p3d";
		weight = 500;
		itemSize[] = {5,5};
		itemsCargoSize[] = {5,5};
		hiddenSelections[] = {"ChristmasBox3","ChristmasBox3_ribbon"};
	};
	class GiftBox_Small_1: GiftBox_Small
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper1_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Small_2: GiftBox_Small
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper2_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Small_3: GiftBox_Small
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper3_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_RED.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_RED.rvmat"}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_RED_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_RED_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Small_4: GiftBox_Small
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper4_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat"}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Medium_1: GiftBox_Medium
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper1_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 35;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Medium_2: GiftBox_Medium
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper2_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_RED.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 35;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_RED.rvmat"}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_RED_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_RED_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Medium_3: GiftBox_Medium
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper3_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 35;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat"}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Medium_4: GiftBox_Medium
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper4_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 35;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Large_1: GiftBox_Large
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper1_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_RED.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_RED.rvmat"}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_RED_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_RED_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Large_2: GiftBox_Large
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper2_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER.rvmat"}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_SILVER_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Large_3: GiftBox_Large
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper3_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD.rvmat"}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_GOLD_destruct.rvmat"}}};
				};
			};
		};
	};
	class GiftBox_Large_4: GiftBox_Large
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\gear\containers\data\christmas_paper4_CO.paa","dz\gear\containers\data\christmas_paper_ribbon_CO.paa"};
		hiddenSelectionsMaterials[] = {"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\gear\containers\data\christmas_paper1.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN.rvmat"}},{0.7,{}},{0.5,{"DZ\gear\containers\data\christmas_paper1_damage.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\gear\containers\data\christmas_paper1_destruct.rvmat","DZ\gear\containers\data\christmas_ribbon_GREEN_destruct.rvmat"}}};
				};
			};
		};
	};
};
