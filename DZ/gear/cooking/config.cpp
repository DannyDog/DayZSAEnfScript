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
	class DZ_Gear_Cooking
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Melee"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class Inventory_Base;
	class Bottle_Base;
	class ClutterCutterFireplace: HouseNoDestruct
	{
		scope = 1;
		model = "\DZ\gear\cooking\fireplace_cluttercutter.p3d";
		displayName = "$STR_CfgVehicles_ClutterCutterFireplace0";
		mapSize = 0.7;
		accuracy = 0.2;
		destrType = "DestructNo";
	};
	class FireplaceBase: Inventory_Base
	{
		stackedUnit = "NA";
		canBeSplit = 0;
		quantityBar = 1;
		varQuantityInit = 0.0;
		varQuantityMin = 0.0;
		varQuantityMax = 100.0;
		varQuantityDestroyOnMin = 0;
		varTemperatureMax = 1000;
		absorbency = 0.3;
		forceFarBubble = "true";
		itemBehaviour = 2;
		class AnimationSources
		{
			class Ashes
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Kindling
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Sticks
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Wood
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class BurntWood
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Stones
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Tripod
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Oven
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class LidOn
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class LidOff
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpFireplaceLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpFireplace_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "fireplace_drop_SoundSet";
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
					hitpoints = 100;
					healthLabels[] = {1.0,0.7,0.5,0.3,0.0};
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\FireplaceKit.rvmat","DZ\gear\cooking\data\FireplaceKit.rvmat"}},{0.7,{"DZ\gear\cooking\data\FireplaceKit.rvmat","DZ\gear\cooking\data\FireplaceKit.rvmat"}},{0.5,{"DZ\gear\cooking\data\FireplaceKit.rvmat","DZ\gear\cooking\data\FireplaceKit.rvmat"}},{0.3,{"DZ\gear\cooking\data\FireplaceKit.rvmat","DZ\gear\cooking\data\FireplaceKit.rvmat"}},{0.0,{"DZ\gear\cooking\data\FireplaceKit.rvmat","DZ\gear\cooking\data\FireplaceKit.rvmat"}}};
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
		};
	};
	class Fireplace: FireplaceBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Fireplace0";
		descriptionShort = "$STR_CfgVehicles_Fireplace1";
		model = "\dz\gear\cooking\Fireplace.p3d";
		overrideDrawArea = "8.0";
		slopeTolerance = 0.3;
		physLayer = "item_large";
		openable = 0;
		lootCategory = "Crafted";
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,4};
		useEntityHierarchy = "true";
		attachments[] = {"Firewood","WoodenStick","CookingEquipment","Rags","MedicalBandage","Paper","Bark","CookingTripod","Stones","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		class GUIInventoryAttachmentsProps
		{
			class CookingEquipment
			{
				name = "$STR_attachment_CookingEquipment0";
				description = "";
				attachmentSlots[] = {"CookingTripod","CookingEquipment"};
				icon = "cat_fp_cooking";
				view_index = 1;
			};
			class Smoking
			{
				name = "$STR_attachment_Smoking";
				description = "";
				attachmentSlots[] = {"SmokingA","SmokingB","SmokingC","SmokingD"};
				icon = "cookingequipment";
				view_index = 2;
			};
			class DirectCooking
			{
				name = "$STR_attachment_CookingEquipment0";
				description = "";
				attachmentSlots[] = {"DirectCookingA","DirectCookingB","DirectCookingC"};
				icon = "cookingequipment";
				view_index = 3;
			};
			class Upgrade
			{
				name = "$STR_attachment_Upgrade0";
				description = "";
				attachmentSlots[] = {"Stones"};
				icon = "cat_fp_upgrade";
				view_index = 4;
			};
			class Fuel
			{
				name = "$STR_attachment_Fuel0";
				description = "";
				attachmentSlots[] = {"Firewood","WoodenStick"};
				icon = "cat_fp_fuel";
				view_index = 5;
			};
			class Kindling
			{
				name = "$STR_attachment_Kindling0";
				description = "";
				attachmentSlots[] = {"Rags","MedicalBandage","Paper","Bark"};
				icon = "cat_fp_kindling";
				view_index = 6;
			};
		};
		hiddenSelections[] = {"ashes","inventory"};
		hiddenSelectionsTextures[] = {"\dz\gear\cooking\data\stoneground_co.paa","\dz\gear\cooking\data\fireplacekit_co.paa"};
		hiddenSelectionsMaterials[] = {"\dz\gear\cooking\data\stonegroundnoemit.rvmat","\dz\gear\cooking\data\fireplacekit.rvmat"};
		hologramMaterial = "FireplaceKit";
		hologramMaterialPath = "dz\gear\cooking\data";
	};
	class FireplaceIndoor: FireplaceBase
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_fireplace0";
		descriptionShort = "$STR_cfgvehicles_fireplace1";
		model = "\dz\gear\cooking\FireplaceIndoor.p3d";
		overrideDrawArea = "8.0";
		rotationFlags = 64;
		openable = 0;
		lootCategory = "Crafted";
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,4};
		attachments[] = {"Firewood","WoodenStick","Rags","MedicalBandage","Paper","Bark","DirectCookingA","DirectCookingB","SmokingA","SmokingB","SmokingC","SmokingD"};
		class GUIInventoryAttachmentsProps
		{
			class Smoking
			{
				name = "$STR_attachment_Smoking";
				description = "";
				attachmentSlots[] = {"SmokingA","SmokingB","SmokingC","SmokingD"};
				icon = "cookingequipment";
			};
			class CookingEquipment
			{
				name = "$STR_attachment_CookingEquipment0";
				description = "";
				attachmentSlots[] = {"DirectCookingA","DirectCookingB"};
				icon = "cookingequipment";
			};
			class Fuel
			{
				name = "$STR_attachment_Fuel0";
				description = "";
				attachmentSlots[] = {"Firewood","WoodenStick"};
				icon = "cat_fp_fuel";
			};
			class Kindling
			{
				name = "$STR_attachment_Kindling0";
				description = "";
				attachmentSlots[] = {"Rags","MedicalBandage","Paper","Bark"};
				icon = "cat_fp_kindling";
			};
		};
		hiddenSelections[] = {"ashes"};
	};
	class OvenIndoor: FireplaceBase
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_fireplace0";
		descriptionShort = "$STR_cfgvehicles_fireplace1";
		model = "\dz\gear\cooking\OvenIndoor.p3d";
		overrideDrawArea = "8.0";
		rotationFlags = 64;
		openable = 0;
		lootCategory = "Crafted";
		itemSize[] = {4,4};
		itemsCargoSize[] = {10,4};
		attachments[] = {"Firewood","WoodenStick","Rags","MedicalBandage","Paper","Bark","DirectCookingA","SmokingA","SmokingB"};
		class GUIInventoryAttachmentsProps
		{
			class Smoking
			{
				name = "$STR_attachment_Smoking";
				description = "";
				attachmentSlots[] = {"SmokingA","SmokingB"};
				icon = "cookingequipment";
			};
			class CookingEquipment
			{
				name = "$STR_attachment_CookingEquipment0";
				description = "";
				attachmentSlots[] = {"DirectCookingA"};
				icon = "cookingequipment";
			};
			class Fuel
			{
				name = "$STR_attachment_Fuel0";
				description = "";
				attachmentSlots[] = {"Firewood","WoodenStick"};
				icon = "cat_fp_fuel";
			};
			class Kindling
			{
				name = "$STR_attachment_Kindling0";
				description = "";
				attachmentSlots[] = {"Rags","MedicalBandage","Paper","Bark"};
				icon = "cat_fp_kindling";
			};
		};
		hiddenSelections[] = {"ashes"};
	};
	class BarrelHoles_ColorBase: FireplaceBase
	{
		displayName = "$STR_CfgVehicles_BarrelHoles_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_BarrelHoles_ColorBase1";
		model = "\dz\gear\cooking\barrel_holes.p3d";
		overrideDrawArea = "3.0";
		slopeTolerance = 0.3;
		lootCategory = "Crafted";
		itemSize[] = {10,15};
		weight = 10000;
		itemBehaviour = 0;
		quantityBar = 0;
		varQuantityInit = 0.0;
		varQuantityMin = 0.0;
		varQuantityMax = 0.0;
		stackedUnit = "";
		attachments[] = {"Firewood","WoodenStick","Rags","MedicalBandage","Paper","Bark","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		canBeDigged = 0;
		physLayer = "item_large";
		class GUIInventoryAttachmentsProps
		{
			class Smoking
			{
				name = "$STR_attachment_Smoking";
				description = "";
				attachmentSlots[] = {"SmokingA","SmokingB","SmokingC","SmokingD"};
				icon = "cookingequipment";
			};
			class CookingEquipment
			{
				name = "$STR_attachment_CookingEquipment0";
				description = "";
				attachmentSlots[] = {"DirectCookingA","DirectCookingB","DirectCookingC"};
				icon = "cookingequipment";
			};
			class Fuel
			{
				name = "$STR_attachment_Fuel0";
				description = "";
				attachmentSlots[] = {"Firewood","WoodenStick"};
				icon = "cat_fp_fuel";
			};
			class Kindling
			{
				name = "$STR_attachment_Kindling0";
				description = "";
				attachmentSlots[] = {"Rags","MedicalBandage","Paper","Bark"};
				icon = "cat_fp_kindling";
			};
		};
		hiddenSelections[] = {"ashes","camoGround","inventory"};
		class Cargo
		{
			itemsCargoSize[] = {10,15};
			openable = 0;
			allowOwnedCargoManipulation = 1;
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
	class BarrelHoles_Green: BarrelHoles_ColorBase
	{
		scope = 2;
		color = "Green";
		hiddenSelectionsTextures[] = {"\dz\gear\cooking\data\stoneground_co.paa","\dz\gear\cooking\data\barrel_green_holes_co.paa","\dz\gear\cooking\data\barrel_green_holes_co.paa"};
		hologramMaterial = "Barrel";
		hologramMaterialPath = "dz\gear\containers\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 900;
					RefTexsMats[] = {"dz\gear\cooking\data\barrel_green_holes.rvmat"};
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\barrel_green_holes.rvmat"}},{0.7,{"DZ\gear\cooking\data\barrel_green_holes.rvmat"}},{0.5,{"DZ\gear\cooking\data\barrel_green_holes_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\barrel_green_holes_damage.rvmat"}},{0.0,{"DZ\gear\cooking\data\barrel_green_holes_destruct.rvmat"}}};
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
	};
	class BarrelHoles_Blue: BarrelHoles_ColorBase
	{
		scope = 2;
		color = "Blue";
		hiddenSelectionsTextures[] = {"\dz\gear\cooking\data\stoneground_co.paa","\dz\gear\cooking\data\barrel_blue_holes_co.paa","\dz\gear\cooking\data\barrel_blue_holes_co.paa"};
		hologramMaterial = "Barrel";
		hologramMaterialPath = "dz\gear\containers\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 900;
					RefTexsMats[] = {"dz\gear\cooking\data\barrel_green_holes.rvmat"};
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\barrel_blue_holes.rvmat"}},{0.7,{"DZ\gear\cooking\data\barrel_blue_holes.rvmat"}},{0.5,{"DZ\gear\cooking\data\barrel_blue_holes_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\barrel_blue_holes_damage.rvmat"}},{0.0,{"DZ\gear\cooking\data\barrel_blue_holes_destruct.rvmat"}}};
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
	};
	class BarrelHoles_Red: BarrelHoles_ColorBase
	{
		scope = 2;
		color = "Red";
		hiddenSelectionsTextures[] = {"\dz\gear\cooking\data\stoneground_co.paa","\dz\gear\cooking\data\barrel_red_holes_co.paa","\dz\gear\cooking\data\barrel_red_holes_co.paa"};
		hologramMaterial = "Barrel";
		hologramMaterialPath = "dz\gear\containers\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 900;
					RefTexsMats[] = {"dz\gear\cooking\data\barrel_green_holes.rvmat"};
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\barrel_red_holes.rvmat"}},{0.7,{"DZ\gear\cooking\data\barrel_red_holes.rvmat"}},{0.5,{"DZ\gear\cooking\data\barrel_red_holes_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\barrel_red_holes_damage.rvmat"}},{0.0,{"DZ\gear\cooking\data\barrel_red_holes_destruct.rvmat"}}};
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
	};
	class BarrelHoles_Yellow: BarrelHoles_ColorBase
	{
		scope = 2;
		color = "Yellow";
		hiddenSelectionsTextures[] = {"\dz\gear\cooking\data\stoneground_co.paa","\dz\gear\cooking\data\barrel_yellow_holes_co.paa","\dz\gear\cooking\data\barrel_yellow_holes_co.paa"};
		hologramMaterial = "Barrel";
		hologramMaterialPath = "dz\gear\containers\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 900;
					RefTexsMats[] = {"dz\gear\cooking\data\barrel_green_holes.rvmat"};
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\barrel_yellow_holes.rvmat"}},{0.7,{"DZ\gear\cooking\data\barrel_yellow_holes.rvmat"}},{0.5,{"DZ\gear\cooking\data\barrel_yellow_holes_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\barrel_yellow_holes_damage.rvmat"}},{0.0,{"DZ\gear\cooking\data\barrel_yellow_holes_destruct.rvmat"}}};
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
	};
	class Pot: Bottle_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Pot0";
		descriptionShort = "$STR_CfgVehicles_Pot1";
		model = "\dz\gear\cooking\CookingPot.p3d";
		weight = 440;
		itemSize[] = {4,3};
		itemsCargoSize[] = {4,3};
		inventorySlot[] = {"CookingEquipment","DirectCookingA","DirectCookingB","DirectCookingC"};
		stackedRandom = 0;
		canBeDigged = 1;
		allowOwnedCargoManipulation = 1;
		varLiquidTypeInit = 512;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 2000;
		varTemperatureMax = 200;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\cooking_pot.rvmat"}},{0.7,{"DZ\gear\cooking\data\cooking_pot.rvmat"}},{0.5,{"DZ\gear\cooking\data\cooking_pot_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\cooking_pot_damage.rvmat"}},{0.0,{"DZ\gear\cooking\data\cooking_pot_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class handleRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpPotLight
				{
					soundSet = "pickUpPotLight_SoundSet";
					id = 796;
				};
				class pickUpPot
				{
					soundSet = "pickUpPot_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "pot_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class FryingPan: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FryingPan0";
		descriptionShort = "$STR_CfgVehicles_FryingPan1";
		model = "\dz\gear\cooking\FryingPan.p3d";
		rotationFlags = 2;
		openable = 0;
		weight = 750;
		itemSize[] = {4,3};
		itemsCargoSize[] = {4,3};
		fragility = 0.01;
		allowOwnedCargoManipulation = 1;
		volume = 1000;
		varTemperatureMax = 200;
		inventorySlot[] = {"CookingEquipment","DirectCookingA","DirectCookingB","DirectCookingC"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\frying_pan.rvmat"}},{0.7,{"DZ\gear\cooking\data\frying_pan.rvmat"}},{0.5,{"DZ\gear\cooking\data\frying_pan_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\frying_pan_damage.rvmat"}},{0.0,{"DZ\gear\cooking\data\frying_pan_destruct.rvmat"}}};
				};
			};
		};
	};
	class PortableGasStove: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PortableGasStove0";
		descriptionShort = "$STR_CfgVehicles_PortableGasStove1";
		model = "\dz\gear\cooking\GasCooker.p3d";
		overrideDrawArea = "3.0";
		openable = 0;
		lootTag[] = {"Camping"};
		lootCategory = "Tools";
		weight = 170;
		itemSize[] = {4,3};
		attachments[] = {"GasCanister","CookingEquipment"};
		containerSlot = "GasCanister";
		hiddenSelections[] = {"flame"};
		hiddenSelectionsTextures[] = {""};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\GasCooker.rvmat"}},{0.7,{"DZ\gear\cooking\data\GasCooker.rvmat"}},{0.5,{"DZ\gear\cooking\data\GasCooker_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\GasCooker_damage.rvmat"}},{0.0,{"DZ\gear\cooking\data\GasCooker_destruct.rvmat"}}};
				};
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn = 0;
			autoSwitchOff = 1;
			autoSwitchOffWhenInCargo = 1;
			energyStorageMax = 0;
			energyUsagePerSecond = 1;
			energyAtSpawn = 0;
			powerSocketsCount = 0;
			plugType = 7;
			attachmentAction = 1;
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,0.6,0.5,1.0};
				brightness = 1.0;
				radius = 5;
				dayLight = 0;
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
			};
		};
	};
	class PortableGasLamp: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PortableGasLamp0";
		descriptionShort = "$STR_CfgVehicles_PortableGasLamp1";
		model = "\dz\gear\cooking\GasLight.p3d";
		overrideDrawArea = "8.0";
		weight = 330;
		itemSize[] = {4,3};
		attachments[] = {"GasCanister"};
		containerSlot = "GasCanister";
		hiddenSelections[] = {"glow","zbytek","glow_on","glow_off"};
		hiddenSelectionsMaterials[] = {"dz\gear\cooking\data\gaslight.rvmat","dz\gear\cooking\data\gaslight.rvmat","","dz\gear\cooking\data\gaslight.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\GasLight.rvmat"}},{0.7,{"DZ\gear\cooking\data\GasLight.rvmat"}},{0.5,{"DZ\gear\cooking\data\GasLight_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\GasLight_damage.rvmat"}},{0.0,{"DZ\gear\cooking\data\GasLight_destruct.rvmat"}}};
				};
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn = 0;
			autoSwitchOff = 1;
			autoSwitchOffWhenInCargo = 1;
			energyStorageMax = 0;
			energyUsagePerSecond = 0.1;
			energyAtSpawn = 0;
			powerSocketsCount = 0;
			plugType = 7;
			attachmentAction = 1;
			updateInterval = 50;
		};
	};
	class Candle: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Candle0";
		descriptionShort = "$STR_CfgVehicles_Candle1";
		model = "\dz\gear\tools\candle.p3d";
		rotationFlags = 12;
		weight = 60;
		itemSize[] = {1,2};
		attachments[] = {"GasCanister"};
		hiddenSelections[] = {"flame"};
		containerSlot = "GasCanister";
		class flame
		{
			sound = "";
			texture = "dz\gear\tools\data\candle_flame_ca.paa";
			material = "dz\gear\tools\data\candle_flame.rvmat";
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,0.5,0.2,1.0};
				brightness = 1.0;
				radius = 2;
				dayLight = 0;
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
			};
		};
	};
	class PetrolLighter: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PetrolLighter0";
		descriptionShort = "$STR_CfgVehicles_PetrolLighter1";
		model = "\dz\gear\cooking\petrol_lighter.p3d";
		rotationFlags = 12;
		absorbency = 0;
		weight = 50;
		itemSize[] = {1,1};
		stackedUnit = "ml";
		quantityBar = 1;
		varQuantityInit = 20.0;
		varQuantityMin = 0.0;
		varQuantityMax = 20.0;
		varQuantityDestroyOnMin = 0;
		destroyOnEmpty = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\petrol_lighter.rvmat"}},{0.7,{"DZ\gear\cooking\data\petrol_lighter.rvmat"}},{0.5,{"DZ\gear\cooking\data\petrol_lighter_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\petrol_lighter_damage.rvmat"}},{0.0,{"DZ\gear\cooking\data\petrol_lighter_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class LighterZippo
				{
					soundSet = "Lighter_Soundset";
					id = 201;
				};
			};
		};
	};
	class Tripod: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Tripod0";
		descriptionShort = "$STR_CfgVehicles_Tripod1";
		model = "\dz\gear\cooking\tripod.p3d";
		rotationFlags = 17;
		physLayer = "item_large";
		weight = 660;
		itemSize[] = {1,6};
		suicideAnim = "pitchfork";
		inventorySlot[] = {"CookingTripod"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\cooking\data\tripod.rvmat"}},{0.7,{"DZ\gear\cooking\data\tripod.rvmat"}},{0.5,{"DZ\gear\cooking\data\tripod_damage.rvmat"}},{0.3,{"DZ\gear\cooking\data\tripod_damage.rvmat"}},{0.0,{"DZ\gear\cooking\data\tripod_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class drop
				{
					soundset = "crowbar_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyCookingPot: ProxyAttachment
	{
		scope = 2;
		model = "\dz\gear\cooking\CookingPot.p3d";
		inventorySlot[] = {"CookingEquipment"};
		class AnimationSources
		{
			class handleRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class Proxydirect_cooking_a: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"DirectCookingA"};
		model = "\dz\gear\cooking\proxy\direct_cooking_a.p3d";
	};
	class Proxydirect_cooking_b: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"DirectCookingB"};
		model = "\dz\gear\cooking\proxy\direct_cooking_b.p3d";
	};
	class Proxydirect_cooking_c: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"DirectCookingC"};
		model = "\dz\gear\cooking\proxy\direct_cooking_c.p3d";
	};
	class ProxyBook_kniga: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"Book"};
		model = "\dz\gear\books\Book_kniga.p3d";
	};
};
