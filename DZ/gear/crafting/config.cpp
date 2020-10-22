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
	class DZ_Gear_Crafting
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
	class BurlapSack: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BurlapSack0";
		descriptionShort = "$STR_CfgVehicles_BurlapSack1";
		model = "\dz\gear\crafting\bp_burlap_sack.p3d";
		rotationFlags = 17;
		weight = 510;
		itemSize[] = {3,2};
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\bp_sack_burlap.rvmat"}},{0.7,{"DZ\gear\crafting\data\bp_sack_burlap.rvmat"}},{0.5,{"DZ\gear\crafting\data\bp_sack_burlap_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\bp_sack_burlap_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\bp_sack_burlap_destruct.rvmat"}}};
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
	class Rope: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Rope0";
		descriptionShort = "$STR_CfgVehicles_Rope1";
		model = "\dz\gear\crafting\bp_rope.p3d";
		OnRestrainChange = "RopeLocked";
		RestrainTime = 10;
		rotationFlags = 17;
		itemSize[] = {1,3};
		weight = 280;
		inventorySlot[] = {"Rope","Material_FPole_Rope","Material_Shelter_Rope"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\bp_rope.rvmat"}},{0.7,{"DZ\gear\crafting\data\bp_rope.rvmat"}},{0.5,{"DZ\gear\crafting\data\bp_rope_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\bp_rope_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\bp_rope_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class rope_untie
				{
					soundSet = "rope_untie_SoundSet";
					id = 202;
				};
				class rope_struggle
				{
					soundSet = "rope_struggle_SoundSet";
					id = 203;
				};
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
				class rope_tieup
				{
					soundSet = "rope_tieup_SoundSet";
					id = 13338;
				};
				class rope_tieup_end
				{
					soundSet = "rope_tieup_end_SoundSet";
					id = 13339;
				};
				class rope_tieup_back
				{
					soundSet = "rope_tieup_back_SoundSet";
					id = 13340;
				};
			};
		};
	};
	class RopeLocked: Inventory_Base
	{
		scope = 1;
		displayName = "$STR_CfgVehicles_RopeLocked0";
		model = "\dz\gear\crafting\bp_rope_tied.p3d";
		OnRestrainChange = "Rope";
		StruggleLength = 10;
		rotationFlags = 17;
		CanBeUnrestrainedBy[] = {"Sickle",3,"Hacksaw",3,"KitchenKnife",3,"SteakKnife",3,"HayHook",3,"StoneKnife",3,"Cleaver",3,"CombatKnife",3,"HuntingKnife",3,"Machete",3,"Screwdriver",3,"Crowbar",3,"Pickaxe",3,"WoodAxe",3,"Hatchet",3,"FirefighterAxe",3,"Sword",3,"AK_Bayonet",3,"M9A1_Bayonet",3,"Mosin_Bayonet",3,"SKS_Bayonet",3,"HandSaw",3};
		CanBeUnrestrainedByDMG[] = {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\bp_rope.rvmat"}},{0.7,{"DZ\gear\crafting\data\bp_rope.rvmat"}},{0.5,{"DZ\gear\crafting\data\bp_rope_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\bp_rope_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\bp_rope_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class rope_untie
				{
					soundSet = "rope_untie_SoundSet";
					id = 202;
				};
				class rope_struggle
				{
					soundSet = "rope_struggle_SoundSet";
					id = 203;
				};
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
	class MetalWire: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_MetalWire0";
		descriptionShort = "$STR_CfgVehicles_MetalWire1";
		model = "\dz\gear\crafting\String_MetalWire.p3d";
		OnRestrainChange = "MetalWireLocked";
		rotationFlags = 17;
		itemSize[] = {2,3};
		weight = 170;
		inventorySlot[] = {"MetalWire","Material_MetalWire","Material_FPole_MetalWire"};
		hiddenSelections[] = {"att_battery_car","att_battery_car_plugged","att_battery_truck","att_battery_truck_plugged","att_battery_car_plug","att_battery_truck_plug","rolled"};
		hiddenSelectionsTextures[] = {"dz\gear\crafting\data\string_metalwire_co.paa","dz\gear\crafting\data\string_metalwire_co.paa","dz\gear\crafting\data\string_metalwire_co.paa","dz\gear\crafting\data\string_metalwire_co.paa","","","dz\gear\crafting\data\string_metalwire_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\crafting\data\String_MetalWire.rvmat","dz\gear\crafting\data\String_MetalWire.rvmat","dz\gear\crafting\data\String_MetalWire.rvmat","dz\gear\crafting\data\String_MetalWire.rvmat","","","dz\gear\crafting\data\String_MetalWire.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\String_MetalWire.rvmat"}},{0.7,{"DZ\gear\crafting\data\String_MetalWire.rvmat"}},{0.5,{"DZ\gear\crafting\data\String_MetalWire_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\String_MetalWire_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\String_MetalWire_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			switchOnAtSpawn = 1;
			isPassiveDevice = 1;
			powerSocketsCount = 1;
			plugType = 8;
			compatiblePlugTypes[] = {2};
		};
		class AnimationSources
		{
			class Att_battery_car
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Att_battery_car_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Att_battery_truck
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Att_battery_truck_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Att_battery_car_plug
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Att_battery_truck_plug
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Rolled
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class rope_untie
				{
					soundSet = "rope_untie_SoundSet";
					id = 202;
				};
				class rope_struggle
				{
					soundSet = "rope_struggle_SoundSet";
					id = 203;
				};
				class pickUpItem
				{
					soundSet = "pickUpBarbedWire_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "barbedwire_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class MetalWireLocked: Inventory_Base
	{
		scope = 1;
		displayName = "$STR_CfgVehicles_MetalWireLocked0";
		model = "\dz\gear\crafting\String_MetalWire_tied.p3d";
		OnRestrainChange = "MetalWire";
		StruggleLength = 15;
		rotationFlags = 17;
		CanBeUnrestrainedBy[] = {"Hacksaw","15","Pliers","25","HandSaw","15"};
		CanBeUnrestrainedByDMG[] = {20,20,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\String_MetalWire.rvmat"}},{0.7,{"DZ\gear\crafting\data\String_MetalWire.rvmat"}},{0.5,{"DZ\gear\crafting\data\String_MetalWire_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\String_MetalWire_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\String_MetalWire_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class rope_untie
				{
					soundSet = "rope_untie_SoundSet";
					id = 202;
				};
				class rope_struggle
				{
					soundSet = "rope_struggle_SoundSet";
					id = 203;
				};
				class pickUpItem
				{
					soundSet = "pickUpBarbedWire_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "barbedwire_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class WoodenStick: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_WoodenStick0";
		descriptionShort = "$STR_CfgVehicles_WoodenStick1";
		model = "\dz\gear\crafting\bp_wooden_stick.p3d";
		inventorySlot[] = {"WoodenStick","Material_Shelter_Sticks"};
		weight = 220;
		itemSize[] = {5,1};
		canBeSplit = 1;
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varQuantityMax = 50.0;
		varQuantityDestroyOnMin = 1;
		varStackMax = 5.0;
		absorbency = 0.9;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\bp_wooden_stick.rvmat"}},{0.7,{"DZ\gear\crafting\data\bp_wooden_stick.rvmat"}},{0.5,{"DZ\gear\crafting\data\bp_wooden_stick_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\bp_wooden_stick_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\bp_wooden_stick_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.2;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.2;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class TorchKindle
				{
					soundSet = "Torch_kindle_SoundSet";
					id = 201;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class woodenlog_drop
				{
					soundset = "baseballbat_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Torch: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Torch0";
		descriptionShort = "$STR_CfgVehicles_Torch1";
		model = "\dz\gear\crafting\Torch.p3d";
		overrideDrawArea = "8.0";
		rotationFlags = 17;
		absorbency = 0.5;
		isMeleeWeapon = 1;
		burnTimePerRag = 120;
		burnTimePerFullLardDose = 900;
		burnTimePerFullFuelDose = 600;
		maxConsumableLardDose = 200;
		maxConsumableFuelDose = 200;
		canBeSplit = 0;
		stackedUnit = "w";
		quantityBar = 1;
		varQuantityInit = 0.0;
		varQuantityMin = 0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 0;
		weight = 240;
		itemSize[] = {1,5};
		attachments[] = {"Rags"};
		hiddenSelections[] = {"flame","zbytek"};
		hiddenSelectionsTextures[] = {"","dz\gear\crafting\data\Torch_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\torch.rvmat"}},{0.7,{"DZ\gear\crafting\data\torch.rvmat"}},{0.5,{"DZ\gear\crafting\data\torch_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\torch_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\torch_destruct.rvmat"}}};
				};
			};
		};
		class EnergyManager
		{
			autoSwitchOff = 1;
			energyAtSpawn = 2;
			energyStorageMax = 1800;
			energyUsagePerSecond = 1;
			wetnessExposure = 0.5;
			updateInterval = 4;
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.6;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.6;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.2;
			};
			class Default_SwitchedOn
			{
				ammo = "MeleeLightBluntShock";
				range = 1.6;
			};
			class Heavy_SwitchedOn
			{
				ammo = "MeleeLightBluntShock_Heavy";
				range = 1.6;
			};
			class Sprint_SwitchedOn
			{
				ammo = "MeleeLightBluntShock_Heavy";
				range = 2.2;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class TorchKindle
				{
					soundSet = "Torch_kindle_SoundSet";
					id = 201;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class woodenlog_drop
				{
					soundset = "baseballbat_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class LongTorch: Torch
	{
		displayName = "$STR_cfgvehicles_long_torch";
		descriptionShort = "$STR_cfgvehicles_long_torch_desc";
		model = "\dz\gear\crafting\LongTorch.p3d";
		weight = 500;
		itemSize[] = {1,8};
	};
	class ChickenFeather: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ChickenFeather0";
		descriptionShort = "$STR_CfgVehicles_ChickenFeather1";
		model = "\dz\gear\consumables\arrow_feather.p3d";
		itemSize[] = {1,1};
		weight = 1;
		canBeSplit = 1;
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varQuantityMax = 20.0;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 5;
					healthLevels[] = {{1.0,{"DZ\weapons\projectiles\data\arrow_crafted_simple.rvmat"}},{0.7,{"DZ\weapons\projectiles\data\arrow_crafted_simple.rvmat"}},{0.5,{"DZ\weapons\projectiles\data\arrow_crafted_simple_damage.rvmat"}},{0.3,{"DZ\weapons\projectiles\data\arrow_crafted_simple_damage.rvmat"}},{0.0,{"DZ\weapons\projectiles\data\arrow_crafted_simple_destruct.rvmat"}}};
				};
			};
		};
	};
	class LongWoodenStick: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_LongWoodenStick0";
		descriptionShort = "$STR_CfgVehicles_LongWoodenStick1";
		model = "\dz\gear\crafting\Wooden_stick_blunt.p3d";
		rotationFlags = 17;
		weight = 670;
		itemSize[] = {1,8};
		canBeSplit = 1;
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varQuantityMax = 10.0;
		varQuantityDestroyOnMin = 1;
		varStackMax = 1.0;
		inventorySlot[] = {"Shoulder","Melee","Material_FPole_MagicStick","Material_Shelter_FrameSticks"};
		itemBehaviour = 1;
		absorbency = 0.9;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\Wooden_stick.rvmat"}},{0.7,{"DZ\gear\crafting\data\Wooden_stick.rvmat"}},{0.5,{"DZ\gear\crafting\data\Wooden_stick_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\Wooden_stick_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\Wooden_stick_destruct.rvmat"}}};
				};
			};
		};
	};
	class SharpWoodenStick: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SharpLongWoodenStick0";
		descriptionShort = "$STR_CfgVehicles_SharpLongWoodenStick1";
		model = "\dz\gear\crafting\Wooden_stick.p3d";
		rotationFlags = 17;
		weight = 670;
		itemSize[] = {1,8};
		canBeSplit = 1;
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varQuantityMax = 1.0;
		varQuantityDestroyOnMin = 1;
		inventorySlot[] = {"Shoulder","Melee"};
		suicideAnim = "spear";
		itemBehaviour = 1;
		attachments[] = {"Ingredient"};
		absorbency = 0.9;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\Wooden_stick.rvmat"}},{0.7,{"DZ\gear\crafting\data\Wooden_stick.rvmat"}},{0.5,{"DZ\gear\crafting\data\Wooden_stick_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\Wooden_stick_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\Wooden_stick_destruct.rvmat"}}};
				};
			};
		};
	};
	class GorkaHelmetVisor: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_GorkaHelmetVisor0";
		descriptionShort = "$STR_CfgVehicles_GorkaHelmetVisor1";
		model = "\dz\characters\headgear\Maska_glass_g.p3d";
		rotationFlags = 16;
		weight = 350;
		itemSize[] = {3,2};
		inventorySlot[] = {"Glass"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"dz\characters\headgear\data\maska.rvmat"}},{0.7,{"dz\characters\headgear\data\maska.rvmat"}},{0.5,{"dz\characters\headgear\data\maska_damage.rvmat"}},{0.3,{"dz\characters\headgear\data\maska_damage.rvmat"}},{0.0,{"dz\characters\headgear\data\maska_destruct.rvmat"}}};
				};
			};
		};
	};
	class HandDrillKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HandDrillKit0";
		descriptionShort = "$STR_CfgVehicles_HandDrillKit1";
		model = "\dz\gear\crafting\hand_drill_kit.p3d";
		weight = 210;
		itemSize[] = {1,4};
		rotationFlags = 8;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\hand_drill_kit.rvmat"}},{0.7,{"DZ\gear\crafting\data\hand_drill_kit.rvmat"}},{0.5,{"DZ\gear\crafting\data\hand_drill_kit_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\hand_drill_kit_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\hand_drill_kit_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MatchStrike
				{
					soundSet = "HandDrillIgnite_SoundSet";
					id = 201;
				};
				class pickup
				{
					soundSet = "bark_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "bark_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Spear: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Spear0";
		descriptionShort = "$STR_CfgVehicles_Spear1";
		model = "\dz\gear\crafting\advanced_spear.p3d";
		rotationFlags = 17;
		weight = 700;
		itemSize[] = {1,9};
		inventorySlot[] = {"Shoulder","Melee"};
		suicideAnim = "spear";
		itemBehaviour = 2;
		openItemSpillRange[] = {20,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\advanced_spear.rvmat"}},{0.7,{"DZ\gear\crafting\data\advanced_spear.rvmat"}},{0.5,{"DZ\gear\crafting\data\advanced_spear_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\advanced_spear_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\advanced_spear_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeSpear";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeSpear_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeSpear_Heavy";
				range = 3.7;
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyMaska_glass_g: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"Glass"};
		model = "\dz\characters\headgear\Maska_glass_g.p3d";
	};
	class ProxyMeat_steak: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"Ingredient"};
		model = "\dz\gear\food\meat_steak.p3d";
		class AnimationSources
		{
			class CS_Raw
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CS_Rotten
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CS_Baked
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CS_Boiled
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CS_Dried
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CS_Burned
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class ProxyString_MetalWire: ProxyAttachment
	{
		scope = 2;
		model = "\dz\gear\crafting\String_MetalWire.p3d";
		inventorySlot[] = {"MetalWire","Material_FPole_MetalWire"};
		class AnimationSources
		{
			class Att_battery_car
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Att_battery_car_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Att_battery_truck
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Att_battery_truck_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Att_battery_car_plug
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Att_battery_truck_plug
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Rolled
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
	};
	class ProxyBp_rope: ProxyAttachment
	{
		scope = 2;
		model = "\dz\gear\crafting\bp_rope.p3d";
		inventorySlot[] = {"Rope","Material_FPole_Rope"};
	};
	class ProxyWooden_stick: ProxyAttachment
	{
		scope = 2;
		model = "\dz\gear\crafting\Wooden_stick.p3d";
		inventorySlot[] = {"Material_FPole_MagicStick"};
	};
};
