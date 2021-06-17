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
	class DZ_Gear_Food
	{
		units[] = {"Food_CanBakedBeans","Food_CanFrankBeans","Food_CanPasta","Food_CanSardines","Food_BoxCerealCrunchin"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class BaseFoodStageTransitions
{
	class Raw
	{
		class ToBaked
		{
			transition_to = 2;
			cooking_method = 1;
		};
		class ToBoiled
		{
			transition_to = 3;
			cooking_method = 2;
		};
		class ToBurned
		{
			transition_to = 5;
			cooking_method = 3;
		};
	};
	class Rotten
	{
		class ToBurned
		{
			transition_to = 5;
			cooking_method = 1;
		};
	};
	class Baked
	{
		class ToBurned
		{
			transition_to = 5;
			cooking_method = 1;
		};
	};
	class Boiled
	{
		class ToBaked
		{
			transition_to = 2;
			cooking_method = 1;
		};
	};
	class Dried
	{
		class ToBaked
		{
			transition_to = 5;
			cooking_method = 1;
		};
		class ToBoiled
		{
			transition_to = 5;
			cooking_method = 2;
		};
	};
	class Burned{};
};
class NotCookable
{
	class Raw
	{
		class ToRotten
		{
			transition_to = 6;
			cooking_method = 4;
		};
	};
};
class MeatStageTransitions: BaseFoodStageTransitions{};
class FruitStageTransitions: BaseFoodStageTransitions{};
class AnimalCorpsesStageTransitions: BaseFoodStageTransitions{};
class MushroomsStageTransitions: BaseFoodStageTransitions{};
class FoodAnimationSources
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
class NutritionModifiers
{
	class General
	{
		base_stage = "Raw";
		class Raw
		{
			nutrition_properties[] = {1.0,1.0,1.0,1.0,1.0};
		};
		class Rotten
		{
			nutrition_properties[] = {0.5,0.75,1.0,0.25,1.0};
		};
		class Baked
		{
			nutrition_properties[] = {2.0,0.5,0.75,0.75,1.0};
		};
		class Boiled
		{
			nutrition_properties[] = {1.0,1.0,0.8,0.8,1.0};
		};
		class Dried
		{
			nutrition_properties[] = {4.0,0.1,0.5,0.8,1.0};
		};
		class Burned
		{
			nutrition_properties[] = {1.0,0.25,0.75,0.1,1.0};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Edible_Base: Inventory_Base
	{
		varTemperatureMax = 100;
	};
	class BoxCerealCrunchin: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BoxCerealCrunchin0";
		descriptionShort = "$STR_CfgVehicles_BoxCerealCrunchin1";
		model = "\dz\gear\food\BoxCereal.p3d";
		rotationFlags = 17;
		weight = 0;
		itemSize[] = {3,3};
		varQuantityInit = 250;
		varQuantityMin = 0;
		varQuantityMax = 250;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\CerealBox_01_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\Cereal_box.rvmat"}},{0.7,{"DZ\gear\food\data\Cereal_box.rvmat"}},{0.5,{"DZ\gear\food\data\Cereal_box_damage.rvmat"}},{0.3,{"DZ\gear\food\data\Cereal_box_damage.rvmat"}},{0.0,{"DZ\gear\food\data\Cereal_box_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 400;
			water = 0;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickup
				{
					soundSet = "BoxCerealCrunchin_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
				class drop
				{
					soundset = "BoxCerealCrunchin_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class PowderedMilk: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PowderedMilk0";
		descriptionShort = "$STR_CfgVehicles_PowderedMilk1";
		model = "\dz\gear\food\PowderedMilk.p3d";
		rotationFlags = 17;
		weight = 0;
		itemSize[] = {1,2};
		varQuantityInit = 200;
		varQuantityMin = 0;
		varQuantityMax = 200;
		absorbency = 0.9;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\powdered_milk.rvmat"}},{0.7,{"DZ\gear\food\data\powdered_milk.rvmat"}},{0.5,{"DZ\gear\food\data\powdered_milk_damage.rvmat"}},{0.3,{"DZ\gear\food\data\powdered_milk_damage.rvmat"}},{0.0,{"DZ\gear\food\data\powdered_milk_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 400;
			water = 0;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
				class drop
				{
					soundset = "bloodbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SmallGuts: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SmallGuts0";
		descriptionShort = "$STR_CfgVehicles_SmallGuts1";
		model = "\dz\gear\food\animal_smallguts.p3d";
		rotationFlags = 1;
		weight = 0;
		itemSize[] = {2,1};
		varQuantityInit = 200;
		varQuantityMin = 0;
		varQuantityMax = 200;
		absorbency = 0;
		inventorySlot[] = {"Guts"};
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\powdered_milk.rvmat"}},{0.7,{"DZ\gear\food\data\powdered_milk.rvmat"}},{0.5,{"DZ\gear\food\data\powdered_milk_damage.rvmat"}},{0.3,{"DZ\gear\food\data\powdered_milk_damage.rvmat"}},{0.0,{"DZ\gear\food\data\powdered_milk_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeSoft";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeSoft_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeSoft_Heavy";
				range = 2.8;
			};
		};
		class Nutrition
		{
			fullnessIndex = 2.5;
			energy = 150;
			water = 70;
			nutritionalIndex = 1;
			toxicity = 0;
			agents = 4;
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Guts: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Guts0";
		descriptionShort = "$STR_CfgVehicles_Guts1";
		model = "\dz\gear\food\animal_guts.p3d";
		weight = 0;
		itemSize[] = {3,2};
		varQuantityInit = 500;
		varQuantityMin = 0;
		varQuantityMax = 500;
		inventorySlot[] = {"Guts"};
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\powdered_milk.rvmat"}},{0.7,{"DZ\gear\food\data\powdered_milk.rvmat"}},{0.5,{"DZ\gear\food\data\powdered_milk_damage.rvmat"}},{0.3,{"DZ\gear\food\data\powdered_milk_damage.rvmat"}},{0.0,{"DZ\gear\food\data\powdered_milk_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeSoft";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeSoft_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeSoft_Heavy";
				range = 2.8;
			};
		};
		class Nutrition
		{
			fullnessIndex = 5;
			energy = 50;
			water = 50;
			nutritionalIndex = 1;
			toxicity = 0;
			agents = 4;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Rice: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Rice0";
		descriptionShort = "$STR_CfgVehicles_Rice1";
		model = "\dz\gear\food\Rice.p3d";
		weight = 0;
		itemSize[] = {2,3};
		varQuantityInit = 500;
		varQuantityMin = 0;
		varQuantityMax = 500;
		absorbency = 0.9;
		rotationFlags = 63;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\rice.rvmat"}},{0.7,{"DZ\gear\food\data\rice.rvmat"}},{0.5,{"DZ\gear\food\data\rice_damage.rvmat"}},{0.3,{"DZ\gear\food\data\rice_damage.rvmat"}},{0.0,{"DZ\gear\food\data\rice_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 3;
			energy = 100;
			water = 0;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Marmalade: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Marmalade0";
		descriptionShort = "$STR_CfgVehicles_Marmalade1";
		model = "\dz\gear\food\Marmalade.p3d";
		weight = 0;
		itemSize[] = {2,2};
		varQuantityInit = 400;
		varQuantityMin = 0;
		varQuantityMax = 400;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\marmalade_jar.rvmat"}},{0.7,{"DZ\gear\food\data\marmalade_jar.rvmat"}},{0.5,{"DZ\gear\food\data\marmalade_jar_damage.rvmat"}},{0.3,{"DZ\gear\food\data\marmalade_jar_damage.rvmat"}},{0.0,{"DZ\gear\food\data\marmalade_jar_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 4;
			energy = 150;
			water = 50;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Marmalade_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class Honey: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Honey0";
		descriptionShort = "$STR_Honey1";
		model = "\dz\gear\food\Honey.p3d";
		weight = 0;
		itemSize[] = {2,2};
		varQuantityInit = 400;
		varQuantityMin = 0;
		varQuantityMax = 400;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\honey_jar.rvmat"}},{0.7,{"DZ\gear\food\data\honey_jar.rvmat"}},{0.5,{"DZ\gear\food\data\honey_jar_damage.rvmat"}},{0.3,{"DZ\gear\food\data\honey_jar_damage.rvmat"}},{0.0,{"DZ\gear\food\data\honey_jar_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 5;
			energy = 250;
			water = 0;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Marmalade_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};
	class Zagorky_ColorBase: Edible_Base
	{
		model = "\dz\gear\food\Zagorky.p3d";
		rotationFlags = 1;
		weight = 0;
		itemSize[] = {1,2};
		varQuantityInit = 100;
		varQuantityMin = 0;
		varQuantityMax = 100;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\zagorky.rvmat","DZ\gear\food\data\zagorky_wrapping.rvmat"}},{0.7,{"DZ\gear\food\data\zagorky.rvmat","DZ\gear\food\data\zagorky_wrapping.rvmat"}},{0.5,{"DZ\gear\food\data\zagorky_damage.rvmat","DZ\gear\food\data\zagorky_wrapping_damage.rvmat"}},{0.3,{"DZ\gear\food\data\zagorky_damage.rvmat","DZ\gear\food\data\zagorky_wrapping_damage.rvmat"}},{0.0,{"DZ\gear\food\data\zagorky_destruct.rvmat","DZ\gear\food\data\zagorky_wrapping_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickup
				{
					soundSet = "BoxCerealCrunchin_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
				class drop
				{
					soundset = "BoxCerealCrunchin_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Zagorky: Zagorky_ColorBase
	{
		scope = 2;
		displayName = "$STR_Zagorky0";
		descriptionShort = "$STR_Zagorky1";
		hiddenSelections[] = {"camoground"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\zagorky_milk_ca.paa"};
		class Nutrition
		{
			fullnessIndex = 0;
			energy = 100;
			water = 0;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class ZagorkyChocolate: Zagorky_ColorBase
	{
		scope = 2;
		displayName = "$STR_ZagorkyChocolate0";
		descriptionShort = "$STR_ZagorkyChocolate1";
		hiddenSelections[] = {"camoground"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\zagorky_choco_ca.paa"};
		class Nutrition
		{
			fullnessIndex = 0;
			energy = 200;
			water = 0;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class ZagorkyPeanuts: Zagorky_ColorBase
	{
		scope = 2;
		displayName = "$STR_ZagorkyPeanuts0";
		descriptionShort = "$STR_ZagorkyPeanuts1";
		hiddenSelections[] = {"camoground"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\zagorky_nuts_ca.paa"};
		class Nutrition
		{
			fullnessIndex = 0;
			energy = 150;
			water = 0;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class Snack_ColorBase: Edible_Base
	{
		model = "\DZ\gear\food\salty_crackers.p3d";
		rotationFlags = 1;
		weight = 0;
		itemSize[] = {2,2};
		varQuantityInit = 50;
		varQuantityMin = 0;
		varQuantityMax = 50;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\tycinky.rvmat","DZ\gear\food\data\tycinky_wrapping.rvmat"}},{0.7,{"DZ\gear\food\data\tycinky.rvmat","DZ\gear\food\data\tycinky_wrapping.rvmat"}},{0.5,{"DZ\gear\food\data\tycinky_damage.rvmat","DZ\gear\food\data\tycinky_wrapping_damage.rvmat"}},{0.3,{"DZ\gear\food\data\tycinky_damage.rvmat","DZ\gear\food\data\tycinky_wrapping_damage.rvmat"}},{0.0,{"DZ\gear\food\data\tycinky_destruct.rvmat","DZ\gear\food\data\tycinky_wrapping_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
				class drop
				{
					soundset = "bloodbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SaltySticks: Snack_ColorBase
	{
		scope = 2;
		displayName = "$STR_SaltySticks0";
		descriptionShort = "$STR_SaltySticks1";
		class Nutrition
		{
			fullnessIndex = 3;
			energy = 100;
			water = 0;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class Crackers: Snack_ColorBase
	{
		model = "\DZ\gear\food\salty_chips.p3d";
		scope = 2;
		displayName = "$STR_Crackers0";
		descriptionShort = "$STR_Crackers1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\salted_crackers_co.paa"};
		class Nutrition
		{
			fullnessIndex = 3;
			energy = 150;
			water = 0;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class Chips: Snack_ColorBase
	{
		model = "\DZ\gear\food\salty_chips.p3d";
		scope = 2;
		displayName = "$STR_Chips0";
		descriptionShort = "$STR_Chips1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\salted_chips_co.paa"};
		class Nutrition
		{
			fullnessIndex = 3;
			energy = 200;
			water = 0;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class BakedBeansCan: Edible_Base
	{
		scope = 2;
		displayName = "$STR_BakedBeansCan0";
		descriptionShort = "$STR_BakedBeansCan1";
		model = "\dz\gear\food\food_can.p3d";
		rotationFlags = 63;
		itemSize[] = {2,2};
		weight = 440;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\deez_beans_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\food_can.rvmat"}},{0.7,{"DZ\gear\food\data\food_can.rvmat"}},{0.5,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.3,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.0,{"DZ\gear\food\data\food_can_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "BakedBeansCan_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
				class drop
				{
					soundset = "BakedBeansCan_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BakedBeansCan_Opened: Edible_Base
	{
		scope = 2;
		displayName = "$STR_BakedBeansCan0";
		descriptionShort = "$STR_BakedBeansCan1";
		model = "\dz\gear\food\food_can_open.p3d";
		itemSize[] = {2,2};
		weight = 40;
		varQuantityInit = 400;
		varQuantityMin = 0;
		varQuantityMax = 400;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\deez_beans_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\food_can.rvmat"}},{0.7,{"DZ\gear\food\data\food_can.rvmat"}},{0.5,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.3,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.0,{"DZ\gear\food\data\food_can_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 200;
			water = 50;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class PeachesCan: Edible_Base
	{
		scope = 2;
		displayName = "$STR_PeachesCan0";
		descriptionShort = "$STR_PeachesCan1";
		model = "\dz\gear\food\food_can.p3d";
		rotationFlags = 63;
		itemSize[] = {2,2};
		weight = 440;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\canned_peaches_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\food_can.rvmat"}},{0.7,{"DZ\gear\food\data\food_can.rvmat"}},{0.5,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.3,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.0,{"DZ\gear\food\data\food_can_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class PeachesCan_Opened: Edible_Base
	{
		scope = 2;
		displayName = "$STR_PeachesCan0";
		descriptionShort = "$STR_PeachesCan1";
		model = "\dz\gear\food\food_can_open.p3d";
		itemSize[] = {2,2};
		weight = 40;
		varQuantityInit = 400;
		varQuantityMin = 0;
		varQuantityMax = 400;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\canned_peaches_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\food_can.rvmat"}},{0.7,{"DZ\gear\food\data\food_can.rvmat"}},{0.5,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.3,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.0,{"DZ\gear\food\data\food_can_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 150;
			water = 100;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class TacticalBaconCan: Edible_Base
	{
		scope = 2;
		displayName = "$STR_TacticalBaconCan0";
		descriptionShort = "$STR_TacticalBaconCan1";
		model = "\dz\gear\food\food_can.p3d";
		rotationFlags = 63;
		itemSize[] = {2,2};
		weight = 440;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\tactical_bacon_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\food_can.rvmat"}},{0.7,{"DZ\gear\food\data\food_can.rvmat"}},{0.5,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.3,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.0,{"DZ\gear\food\data\food_can_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class TacticalBaconCan_Opened: Edible_Base
	{
		scope = 2;
		displayName = "$STR_TacticalBaconCan0";
		descriptionShort = "$STR_TacticalBaconCan1";
		model = "\dz\gear\food\food_can_open.p3d";
		itemSize[] = {2,2};
		weight = 40;
		varQuantityInit = 400;
		varQuantityMin = 0;
		varQuantityMax = 400;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\tactical_bacon_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\food_can.rvmat"}},{0.7,{"DZ\gear\food\data\food_can.rvmat"}},{0.5,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.3,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.0,{"DZ\gear\food\data\food_can_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 300;
			water = 50;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class SpaghettiCan: Edible_Base
	{
		scope = 2;
		displayName = "$STR_SpaghettiCan0";
		descriptionShort = "$STR_SpaghettiCan1";
		model = "\dz\gear\food\food_can.p3d";
		rotationFlags = 63;
		itemSize[] = {2,2};
		weight = 440;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\canned_spaghetti_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\food_can.rvmat"}},{0.7,{"DZ\gear\food\data\food_can.rvmat"}},{0.5,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.3,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.0,{"DZ\gear\food\data\food_can_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class SpaghettiCan_Opened: Edible_Base
	{
		scope = 2;
		displayName = "$STR_SpaghettiCan0";
		descriptionShort = "$STR_SpaghettiCan1";
		model = "\dz\gear\food\food_can_open.p3d";
		itemSize[] = {2,2};
		weight = 40;
		varQuantityInit = 400;
		varQuantityMin = 0;
		varQuantityMax = 400;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\canned_spaghetti_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\food_can.rvmat"}},{0.7,{"DZ\gear\food\data\food_can.rvmat"}},{0.5,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.3,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.0,{"DZ\gear\food\data\food_can_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 175;
			water = 75;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class SardinesCan: Edible_Base
	{
		scope = 2;
		displayName = "$STR_SardinesCan0";
		descriptionShort = "$STR_SardinesCan1";
		model = "\dz\gear\food\can_sardines.p3d";
		rotationFlags = 34;
		itemSize[] = {2,1};
		weight = 125;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\sardines_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\Sardines.rvmat"}},{0.7,{"DZ\gear\food\data\Sardines.rvmat"}},{0.5,{"DZ\gear\food\data\Sardines_damage.rvmat"}},{0.3,{"DZ\gear\food\data\Sardines_damage.rvmat"}},{0.0,{"DZ\gear\food\data\Sardines_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class SardinesCan_Opened: Edible_Base
	{
		scope = 2;
		displayName = "$STR_SardinesCan0";
		descriptionShort = "$STR_SardinesCan1";
		model = "\dz\gear\food\can_sardines_open.p3d";
		itemSize[] = {2,1};
		weight = 25;
		varQuantityInit = 100;
		varQuantityMin = 0;
		varQuantityMax = 100;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\sardines_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\Sardines.rvmat"}},{0.7,{"DZ\gear\food\data\Sardines.rvmat"}},{0.5,{"DZ\gear\food\data\Sardines_damage.rvmat"}},{0.3,{"DZ\gear\food\data\Sardines_damage.rvmat"}},{0.0,{"DZ\gear\food\data\Sardines_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 250;
			water = 200;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class TunaCan: Edible_Base
	{
		scope = 2;
		displayName = "$STR_TunaCan0";
		descriptionShort = "$STR_TunaCan1";
		model = "\dz\gear\food\Tuna.p3d";
		rotationFlags = 32;
		itemSize[] = {2,1};
		weight = 265;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\tuna_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\tuna.rvmat"}},{0.7,{"DZ\gear\food\data\tuna.rvmat"}},{0.5,{"DZ\gear\food\data\tuna_damage.rvmat"}},{0.3,{"DZ\gear\food\data\tuna_damage.rvmat"}},{0.0,{"DZ\gear\food\data\tuna_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class TunaCan_Opened: Edible_Base
	{
		scope = 2;
		displayName = "$STR_TunaCan0";
		descriptionShort = "$STR_TunaCan1";
		model = "\dz\gear\food\tuna_open.p3d";
		itemSize[] = {2,1};
		weight = 15;
		varQuantityInit = 250;
		varQuantityMin = 0;
		varQuantityMax = 250;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\tuna_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\tuna.rvmat"}},{0.7,{"DZ\gear\food\data\tuna.rvmat"}},{0.5,{"DZ\gear\food\data\tuna_damage.rvmat"}},{0.3,{"DZ\gear\food\data\tuna_damage.rvmat"}},{0.0,{"DZ\gear\food\data\tuna_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 150;
			water = 100;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class FoodCan_250g_ColorBase: Edible_Base
	{
		model = "\dz\gear\food\FoodCan_250g.p3d";
		rotationFlags = 2;
		itemSize[] = {2,1};
		weight = 265;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\FoodCan_250g.rvmat"}},{0.7,{"DZ\gear\food\data\FoodCan_250g.rvmat"}},{0.5,{"DZ\gear\food\data\FoodCan_250g_damage.rvmat"}},{0.3,{"DZ\gear\food\data\FoodCan_250g_damage.rvmat"}},{0.0,{"DZ\gear\food\data\FoodCan_250g_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class FoodCan_250g_Opened_ColorBase: Edible_Base
	{
		model = "\dz\gear\food\FoodCan_250g_open.p3d";
		itemSize[] = {2,1};
		weight = 15;
		varQuantityInit = 250;
		varQuantityMin = 0;
		varQuantityMax = 250;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\FoodCan_250g.rvmat"}},{0.7,{"DZ\gear\food\data\FoodCan_250g.rvmat"}},{0.5,{"DZ\gear\food\data\FoodCan_250g_damage.rvmat"}},{0.3,{"DZ\gear\food\data\FoodCan_250g_damage.rvmat"}},{0.0,{"DZ\gear\food\data\FoodCan_250g_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class DogFoodCan: FoodCan_250g_ColorBase
	{
		scope = 2;
		displayName = "$STR_DogFoodCan0";
		descriptionShort = "$STR_DogFoodCan1";
	};
	class DogFoodCan_Opened: FoodCan_250g_Opened_ColorBase
	{
		scope = 2;
		displayName = "$STR_DogFoodCan0";
		descriptionShort = "$STR_DogFoodCan1";
		class Nutrition
		{
			fullnessIndex = 10;
			energy = 150;
			water = 100;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class CatFoodCan: FoodCan_250g_ColorBase
	{
		scope = 2;
		displayName = "$STR_CatFoodCan0";
		descriptionShort = "$STR_CatFoodCan1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\FoodCan_250g_Cat_CO.paa"};
	};
	class CatFoodCan_Opened: FoodCan_250g_Opened_ColorBase
	{
		scope = 2;
		displayName = "$STR_CatFoodCan0";
		descriptionShort = "$STR_CatFoodCan1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\FoodCan_250g_Cat_CO.paa"};
		class Nutrition
		{
			fullnessIndex = 10;
			energy = 125;
			water = 125;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class PorkCan: FoodCan_250g_ColorBase
	{
		scope = 2;
		displayName = "$STR_PorkCan0";
		descriptionShort = "$STR_PorkCan1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\FoodCan_250g_Pork_CO.paa"};
	};
	class PorkCan_Opened: FoodCan_250g_Opened_ColorBase
	{
		scope = 2;
		displayName = "$STR_PorkCan0";
		descriptionShort = "$STR_PorkCan1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\FoodCan_250g_Pork_CO.paa"};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 225;
			water = 25;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class Lunchmeat: FoodCan_250g_ColorBase
	{
		scope = 2;
		displayName = "$STR_Lunchmeat0";
		descriptionShort = "$STR_Lunchmeat1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\foodcan_250g_lunch_co.paa"};
	};
	class Lunchmeat_Opened: FoodCan_250g_Opened_ColorBase
	{
		scope = 2;
		displayName = "$STR_Lunchmeat0";
		descriptionShort = "$STR_Lunchmeat1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\foodcan_250g_lunch_co.paa"};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 200;
			water = 50;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class UnknownFoodCan: Edible_Base
	{
		scope = 2;
		displayName = "$STR_UnknownFoodCan0";
		descriptionShort = "$STR_UnknownFoodCan1";
		model = "\dz\gear\food\food_can.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\UnknownFoodCan_co.paa"};
		rotationFlags = 63;
		itemSize[] = {2,2};
		weight = 440;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\food_can.rvmat"}},{0.7,{"DZ\gear\food\data\food_can.rvmat"}},{0.5,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.3,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.0,{"DZ\gear\food\data\food_can_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class UnknownFoodCan_Opened: Edible_Base
	{
		scope = 2;
		displayName = "$STR_UnknownFoodCan0";
		descriptionShort = "$STR_UnknownFoodCan1";
		model = "\dz\gear\food\food_can_open.p3d";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\UnknownFoodCan_co.paa"};
		itemSize[] = {2,2};
		weight = 40;
		varQuantityInit = 400;
		varQuantityMin = 0;
		varQuantityMax = 400;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\food_can.rvmat"}},{0.7,{"DZ\gear\food\data\food_can.rvmat"}},{0.5,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.3,{"DZ\gear\food\data\food_can_damage.rvmat"}},{0.0,{"DZ\gear\food\data\food_can_destruct.rvmat"}}};
				};
			};
		};
		class Nutrition
		{
			fullnessIndex = 10;
			energy = 200;
			water = 100;
			nutritionalIndex = 1;
			toxicity = 0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class FoodCan_100g_ColorBase: Edible_Base
	{
		model = "\dz\gear\food\FoodCan_100g.p3d";
		rotationFlags = 2;
		itemSize[] = {1,1};
		weight = 115;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\FoodCan_100g.rvmat","DZ\gear\food\data\FoodCan_100g_silver.rvmat","DZ\gear\food\data\FoodCan_100g_content.rvmat"}},{0.7,{"DZ\gear\food\data\FoodCan_100g.rvmat","DZ\gear\food\data\FoodCan_100g_silver.rvmat","DZ\gear\food\data\FoodCan_100g_content.rvmat"}},{0.5,{"DZ\gear\food\data\FoodCan_100g_damage.rvmat","DZ\gear\food\data\FoodCan_100g_silver_damage.rvmat","DZ\gear\food\data\FoodCan_100g_content_damage.rvmat"}},{0.3,{"DZ\gear\food\data\FoodCan_100g_damage.rvmat","DZ\gear\food\data\FoodCan_100g_silver_damage.rvmat","DZ\gear\food\data\FoodCan_100g_content_damage.rvmat"}},{0.0,{"DZ\gear\food\data\FoodCan_100g_destruct.rvmat","DZ\gear\food\data\FoodCan_100g_silver_destruct.rvmat","DZ\gear\food\data\FoodCan_100g_content_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class FoodCan_100g_Opened_ColorBase: Edible_Base
	{
		model = "\dz\gear\food\FoodCan_100g_open.p3d";
		itemSize[] = {1,1};
		weight = 15;
		varQuantityInit = 100;
		varQuantityMin = 0;
		varQuantityMax = 100;
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\FoodCan_100g.rvmat","DZ\gear\food\data\FoodCan_100g_white.rvmat","DZ\gear\food\data\FoodCan_100g_content.rvmat"}},{0.7,{"DZ\gear\food\data\FoodCan_100g.rvmat","DZ\gear\food\data\FoodCan_100g_white.rvmat","DZ\gear\food\data\FoodCan_100g_content.rvmat"}},{0.5,{"DZ\gear\food\data\FoodCan_100g_damage.rvmat","DZ\gear\food\data\FoodCan_100g_white_damage.rvmat","DZ\gear\food\data\FoodCan_100g_content_damage.rvmat"}},{0.3,{"DZ\gear\food\data\FoodCan_100g_damage.rvmat","DZ\gear\food\data\FoodCan_100g_white_damage.rvmat","DZ\gear\food\data\FoodCan_100g_content_damage.rvmat"}},{0.0,{"DZ\gear\food\data\FoodCan_100g_destruct.rvmat","DZ\gear\food\data\FoodCan_100g_white_destruct.rvmat","DZ\gear\food\data\FoodCan_100g_content_destruct.rvmat"}}};
				};
			};
		};
	};
	class Pajka: FoodCan_100g_ColorBase
	{
		scope = 2;
		displayName = "$STR_Pajka0";
		descriptionShort = "$STR_Pajka1";
	};
	class Pajka_Opened: FoodCan_100g_Opened_ColorBase
	{
		scope = 2;
		displayName = "$STR_Pajka0";
		descriptionShort = "$STR_Pajka1";
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 150;
			water = 25;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class Pate: FoodCan_100g_ColorBase
	{
		scope = 2;
		displayName = "$STR_Pate0";
		descriptionShort = "$STR_Pate1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\FoodCan_100g_Liver_CO.paa"};
	};
	class Pate_Opened: FoodCan_100g_Opened_ColorBase
	{
		scope = 2;
		displayName = "$STR_Pate0";
		descriptionShort = "$STR_Pate1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\FoodCan_100g_Liver_CO.paa"};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 250;
			water = 25;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class BrisketSpread: FoodCan_100g_ColorBase
	{
		scope = 2;
		displayName = "$STR_BrisketSpread0";
		descriptionShort = "$STR_BrisketSpread1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\FoodCan_100g_Brisket_CO.paa"};
	};
	class BrisketSpread_Opened: FoodCan_100g_Opened_ColorBase
	{
		scope = 2;
		displayName = "$STR_BrisketSpread0";
		descriptionShort = "$STR_BrisketSpread1";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\food\Data\FoodCan_100g_Brisket_CO.paa"};
		class Nutrition
		{
			fullnessIndex = 2;
			energy = 200;
			water = 25;
			nutritionalIndex = 1;
			toxicity = 0;
		};
	};
	class Apple: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Apple0";
		descriptionShort = "$STR_Apple1";
		model = "\dz\gear\food\apple.p3d";
		weight = 0;
		itemSize[] = {1,1};
		stackedUnit = "g";
		absorbency = 0.2;
		varQuantityInit = 125;
		varQuantityMin = 0;
		varQuantityMax = 125;
		quantityBar = 1;
		ammoType = "G_GrenadeHand";
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		containsSeedsType = "";
		containsSeedsQuantity = "0";
		hiddenSelections[] = {"cs_raw","cs_boiled","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\apple_raw_CO.paa","dz\gear\food\data\apple_baked_CO.paa","dz\gear\food\data\apple_baked_CO.paa","dz\gear\food\data\apple_dried_CO.paa","dz\gear\food\data\apple_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\apple_raw.rvmat","dz\gear\food\data\apple_baked.rvmat","dz\gear\food\data\apple_boiled.rvmat","dz\gear\food\data\apple_dried.rvmat","dz\gear\food\data\apple_burnt.rvmat","dz\gear\food\data\apple_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,100,75,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,75,50,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {1,1,1};
					nutrition_properties[] = {1,250,75,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {1,2,2};
					nutrition_properties[] = {1,200,100,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {2,3,3};
					nutrition_properties[] = {1,200,0,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {1,4,4};
					nutrition_properties[] = {5,100,0,1,0,16};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Apple_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Plum: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Plum0";
		descriptionShort = "$STR_Plum1";
		model = "\dz\gear\food\plum.p3d";
		rotationFlags = 12;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		absorbency = 0.4;
		weight = 0;
		itemSize[] = {1,1};
		stackedUnit = "g";
		varQuantityInit = 75;
		varQuantityMin = 0;
		varQuantityMax = 75;
		quantityBar = 1;
		hiddenSelections[] = {"cs_raw","cs_baked","cs_boiled","cs_dried","cs_burned"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\plum_raw_CO.paa","dz\gear\food\data\plum_baked_CO.paa","dz\gear\food\data\plum_boiled_CO.paa","dz\gear\food\data\plum_dried_CO.paa","dz\gear\food\data\plum_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\plum_raw.rvmat","dz\gear\food\data\plum_boiled.rvmat","dz\gear\food\data\plum_baked.rvmat","dz\gear\food\data\plum_dried.rvmat","dz\gear\food\data\plum_burnt.rvmat","dz\gear\food\data\plum_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,100,75,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,75,50,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {1,1,1};
					nutrition_properties[] = {1,300,125,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {2,2,2};
					nutrition_properties[] = {1,250,175,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {3,3,3};
					nutrition_properties[] = {1,250,0,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {4,4,4};
					nutrition_properties[] = {5,125,0,1,0,16};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Pear: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Pear0";
		descriptionShort = "$STR_Pear1";
		model = "\dz\gear\food\pear.p3d";
		rotationFlags = 12;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		absorbency = 0.2;
		weight = 0;
		itemSize[] = {1,2};
		stackedUnit = "g";
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		quantityBar = 1;
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\pear_raw_CO.paa","dz\gear\food\data\pear_baked_CO.paa","dz\gear\food\data\pear_baked_CO.paa","dz\gear\food\data\pear_dried_CO.paa","dz\gear\food\data\pear_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\pear_raw.rvmat","dz\gear\food\data\pear_boiled.rvmat","dz\gear\food\data\pear_baked.rvmat","dz\gear\food\data\pear_dried.rvmat","dz\gear\food\data\pear_burnt.rvmat","dz\gear\food\data\pear_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,75,50,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,50,25,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,300,50,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,250,150,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {1,250,0,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,75,0,1,0,16};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Banana: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Banana0";
		descriptionShort = "$STR_Banana1";
		model = "\dz\gear\food\banana_fresh.p3d";
		rotationFlags = 34;
		weight = 0;
		itemSize[] = {1,2};
		stackedUnit = "g";
		varQuantityInit = 100;
		varQuantityMin = 0;
		varQuantityMax = 100;
		quantityBar = 1;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC"};
		containsSeedsType = "";
		containsSeedsQuantity = "0";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		hiddenSelections[] = {"cs_raw","cs_rotten"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\banana_frash_CO.paa","dz\gear\food\data\ban_rotten_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\banana_frash.rvmat","dz\gear\food\data\banana_rotten.rvmat"};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,200,100,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {1,1,1};
					nutrition_properties[] = {10,100,50,1,0,16};
					cooking_properties[] = {0,0};
				};
			};
			class FoodStageTransitions: NotCookable{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Orange: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Orange0";
		descriptionShort = "$STR_Orange1";
		model = "\dz\gear\food\orange_fresh.p3d";
		weight = 0;
		itemSize[] = {1,1};
		stackedUnit = "g";
		varQuantityInit = 110;
		varQuantityMin = 0;
		varQuantityMax = 110;
		quantityBar = 1;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC"};
		containsSeedsType = "";
		containsSeedsQuantity = "0";
		hiddenSelections[] = {"cs_raw","cs_rotten"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\orange_frash_CO.paa","dz\gear\food\data\orange_rotten_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\orange_frash.rvmat","dz\gear\food\data\orange_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,75,150,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {1,1,1};
					nutrition_properties[] = {10,50,100,1,0,16};
					cooking_properties[] = {0,0};
				};
			};
			class FoodStageTransitions: NotCookable{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Tomato: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Tomato0";
		descriptionShort = "$STR_Tomato1";
		model = "\dz\gear\food\tomato.p3d";
		weight = 0;
		itemSize[] = {1,1};
		stackedUnit = "g";
		varQuantityInit = 100;
		varQuantityMin = 0;
		varQuantityMax = 100;
		quantityBar = 1;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		containsSeedsType = "Cultivation_TomatoSeeds";
		containsSeedsQuantity = "10";
		hiddenSelections[] = {"cs_raw","cs_burned"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\tomato_raw_CO.paa","dz\gear\food\data\tomato_baked_CO.paa","dz\gear\food\data\tomato_baked_CO.paa","dz\gear\food\data\tomato_dried_CO.paa","dz\gear\food\data\tomato_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\tomato_raw.rvmat","dz\gear\food\data\tomato_baked.rvmat","dz\gear\food\data\tomato_boiled.rvmat","dz\gear\food\data\tomato_dried.rvmat","dz\gear\food\data\tomato_burnt.rvmat","dz\gear\food\data\tomato_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,50,100,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,150,75,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,125,100,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {1,125,0,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {1,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class GreenBellPepper: Edible_Base
	{
		scope = 2;
		displayName = "$STR_GreenBellPepper0";
		descriptionShort = "$STR_GreenBellPepper1";
		model = "\dz\gear\food\pepper_green.p3d";
		rotationFlags = 12;
		weight = 0;
		itemSize[] = {1,2};
		stackedUnit = "g";
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		quantityBar = 1;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		containsSeedsType = "Cultivation_PepperSeeds";
		containsSeedsQuantity = "10";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\pepper_green_raw_CO.paa","dz\gear\food\data\pepper_green_baked_CO.paa","dz\gear\food\data\pepper_green_baked_CO.paa","dz\gear\food\data\pepper_green_dried_CO.paa","dz\gear\food\data\pepper_green_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\pepper_green_raw.rvmat","dz\gear\food\data\pepper_green_boiled.rvmat","dz\gear\food\data\pepper_green_baked.rvmat","dz\gear\food\data\pepper_green_dried.rvmat","dz\gear\food\data\pepper_green_burnt.rvmat","dz\gear\food\data\pepper_green_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,100,50,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,50,25,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,250,50,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,200,125,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {1,200,0,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {1,4,4};
					nutrition_properties[] = {5,100,0,1,0,16};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Zucchini: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Zucchini0";
		descriptionShort = "$STR_Zucchini1";
		model = "\dz\gear\food\zucchini.p3d";
		rotationFlags = 12;
		weight = 0;
		stackedUnit = "g";
		varQuantityInit = 200;
		varQuantityMin = 0;
		varQuantityMax = 200;
		quantityBar = 1;
		itemSize[] = {1,3};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		containsSeedsType = "Cultivation_ZucchiniSeeds";
		containsSeedsQuantity = "15";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\zucchini_raw_CO.paa","dz\gear\food\data\zucchini_baked_CO.paa","dz\gear\food\data\zucchini_baked_CO.paa","dz\gear\food\data\zucchini_dried_CO.paa","dz\gear\food\data\zucchini_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\zucchini_raw.rvmat","dz\gear\food\data\zucchini_boiled.rvmat","dz\gear\food\data\zucchini_baked.rvmat","dz\gear\food\data\zucchini_dried.rvmat","dz\gear\food\data\zucchini_burnt.rvmat","dz\gear\food\data\zucchini_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,125,75,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,250,75,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,200,150,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {1,200,0,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,125,0,1,0,16};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Pumpkin: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Pumpkin0";
		descriptionShort = "$STR_Pumpkin1";
		model = "\dz\gear\food\Pumpkin_fresh.p3d";
		weight = 0;
		itemSize[] = {3,3};
		stackedUnit = "g";
		varQuantityInit = 2300;
		varQuantityMin = 0;
		varQuantityMax = 2300;
		quantityBar = 1;
		absorbency = 0.2;
		inventorySlot[] = {"Ingredient"};
		containsSeedsType = "Cultivation_PumpkinSeeds";
		containsSeedsQuantity = "20";
		hiddenSelections[] = {"cs_raw","cs_rotten"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\pumpkin_fresh_CO.paa","dz\gear\food\data\pumpkin_rotten_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\pumpkin_fresh.rvmat","dz\gear\food\data\pumpkin_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,20,95,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {1,1,1};
					nutrition_properties[] = {2,15,47.5,1,0,16};
					cooking_properties[] = {0,0};
				};
			};
			class FoodStageTransitions: NotCookable{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class SlicedPumpkin: Edible_Base
	{
		scope = 2;
		displayName = "$STR_SlicedPumpkin0";
		descriptionShort = "$STR_SlicedPumpkin1";
		model = "\dz\gear\food\pumpkin_sliced.p3d";
		rotationFlags = 2;
		weight = 0;
		itemSize[] = {3,2};
		stackedUnit = "g";
		varQuantityInit = 250;
		varQuantityMin = 0;
		varQuantityMax = 250;
		quantityBar = 1;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		containsSeedsType = "";
		containsSeedsQuantity = "0";
		hiddenSelections[] = {"cs_raw","cs_baked","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\pumpkin_sliced_raw_CO.paa","dz\gear\food\data\pumpkin_sliced_baked_CO.paa","dz\gear\food\data\pumpkin_sliced_baked_CO.paa","dz\gear\food\data\pumpkin_sliced_dried_CO.paa","dz\gear\food\data\pumpkin_sliced_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\pumpkin_sliced_raw.rvmat","dz\gear\food\data\pumpkin_sliced_boiled.rvmat","dz\gear\food\data\pumpkin_sliced_baked.rvmat","dz\gear\food\data\pumpkin_sliced_dried.rvmat","dz\gear\food\data\pumpkin_sliced_burnt.rvmat","dz\gear\food\data\pumpkin_sliced_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,75,50,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,50,25,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {1,1,1};
					nutrition_properties[] = {1,150,50,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {1,2,2};
					nutrition_properties[] = {1,125,100,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {2,3,3};
					nutrition_properties[] = {1,125,0,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {2,4,4};
					nutrition_properties[] = {5,75,0,1,0,16};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Potato: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Potato0";
		descriptionShort = "$STR_Potato1";
		model = "\dz\gear\food\potato_prepared.p3d";
		rotationFlags = 12;
		weight = 0;
		itemSize[] = {2,1};
		stackedUnit = "g";
		varQuantityInit = 200;
		varQuantityMin = 0;
		varQuantityMax = 200;
		quantityBar = 1;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		containsSeedsType = "";
		containsSeedsQuantity = "0";
		class Horticulture
		{
			PlantType = "Plant_Potato";
		};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\potato_prepared_CO.paa","dz\gear\food\Data\potato_baked_CO.paa","#(argb,8,8,3)color(1,0.988235,0.835294,1.0,CO)","dz\gear\food\Data\potato_prepared_CO.paa","dz\gear\food\Data\potato_baked_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\potato_prepared.rvmat","dz\gear\food\Data\potato_baked.rvmat","dz\gear\food\data\potato_boiled.rvmat","dz\gear\food\data\potato_dried.rvmat","dz\gear\food\data\potato_burnt.rvmat","dz\gear\food\data\potato_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,75,25,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,50,25,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,250,25,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,200,1,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {1,200,0,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,75,0,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Kiwi: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Kiwi0";
		descriptionShort = "$STR_Kiwi1";
		model = "\dz\gear\food\kiwi_fresh.p3d";
		rotationFlags = 12;
		itemSize[] = {1,1};
		weight = 0;
		VarQuantityInit = 75;
		varQuantityMin = 0;
		varQuantityMax = 75;
		quantityBar = 1;
		stackedUnit = "g";
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC"};
		containsSeedsType = "";
		containsSeedsQuantity = "0";
		hiddenSelections[] = {"cs_raw","cs_rotten"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\kiwi_frash_CO.paa","dz\gear\food\data\kiwi_rotten_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\kiwi_frash.rvmat","dz\gear\food\data\kiwi_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,150,150,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {1,1,1};
					nutrition_properties[] = {10,75,75,1,0,16};
					cooking_properties[] = {0,0};
				};
			};
			class FoodStageTransitions: NotCookable{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class SambucusBerry: Edible_Base
	{
		scope = 2;
		displayName = "$STR_SambucusBerry0";
		descriptionShort = "$STR_SambucusBerry1";
		model = "\dz\gear\food\Sambucus_nigra.p3d";
		weight = 0;
		itemSize[] = {1,1};
		stackedUnit = "g";
		absorbency = 0.4;
		varQuantityInit = 50;
		varQuantityMin = 0;
		varQuantityMax = 50;
		quantityBar = 1;
		inventorySlot[] = {"Ingredient","BerryB"};
		containsSeedsType = "";
		containsSeedsQuantity = "0";
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\sambucus_nigra_CO.paa","dz\gear\food\data\sambucus_nigra_dried_CO.paa","dz\gear\food\data\sambucus_nigra_dried_CO.paa","dz\gear\food\data\sambucus_nigra_dried_CO.paa","dz\gear\food\data\sambucus_nigra_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\sambucus_nigra_raw.rvmat","dz\gear\food\data\sambucus_nigra_boiled.rvmat","dz\gear\food\data\sambucus_nigra_baked.rvmat","dz\gear\food\data\sambucus_nigra_dried.rvmat","dz\gear\food\data\sambucus_nigra_burnt.rvmat","dz\gear\food\data\sambucus_nigra_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,50,80,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {2,37.5,40,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1.75,90,40,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1.5,90,80,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {0.75,90,8,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {2,37.5,20,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class CaninaBerry: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CaninaBerry0";
		descriptionShort = "$STR_CaninaBerry1";
		model = "\dz\gear\food\canina_raw.p3d";
		itemSize[] = {1,1};
		weight = 0;
		stackedUnit = "g";
		absorbency = 0.4;
		varQuantityInit = 50;
		varQuantityMin = 0;
		varQuantityMax = 50;
		quantityBar = 1;
		inventorySlot[] = {"Ingredient","BerryR"};
		ontainsSeedsType = "";
		containsSeedsQuantity = "0";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\canina_raw_CO.paa","dz\gear\food\data\canina_baked_CO.paa","dz\gear\food\data\canina_raw_CO.paa","dz\gear\food\data\canina_dried_CO.paa","dz\gear\food\data\canina_baked_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\canina_raw.rvmat","dz\gear\food\data\canina_baked.rvmat","dz\gear\food\data\canina_boiled.rvmat","dz\gear\food\data\canina_dried.rvmat","dz\gear\food\data\canina_burnt.rvmat","dz\gear\food\data\canina_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,50,80,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {2,37.5,40,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1.75,90,40,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1.5,90,80,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {0.75,90,8,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {2,37.5,20,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Cannabis: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Cannabis0";
		descriptionShort = "$STR_Cannabis1";
		model = "\dz\gear\food\cannabis_seedman.p3d";
		rotationFlags = 34;
		weight = 0;
		itemSize[] = {1,1};
		stackedUnit = "g";
		absorbency = 0.2;
		varQuantityInit = 10;
		varQuantityMin = 0;
		varQuantityMax = 10;
		quantityBar = 1;
		inventorySlot[] = {"Ingredient"};
		containsSeedsType = "";
		containsSeedsQuantity = "0";
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\cannabis_seedman_raw_CO.paa","dz\gear\food\data\cannabis_seedman_baked_CO.paa","dz\gear\food\data\cannabis_seedman_raw_CO.paa","dz\gear\food\data\cannabis_seedman_raw_CO.paa","dz\gear\food\data\cannabis_seedman_baked_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\cannabis_seedman_raw.rvmat","dz\gear\food\data\cannabis_seedman_baked.rvmat","dz\gear\food\data\cannabis_seedman_raw.rvmat","dz\gear\food\data\cannabis_seedman_dried.rvmat","dz\gear\food\data\cannabis_seedman_burnt.rvmat","dz\gear\food\data\cannabis_seedman_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,284,293,30,1};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {1,100,293,10,1,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,69,172,70,1};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,69,172,70,1};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {1,69,172,70,1};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {1,20,40,10,1};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class pickUpItem
				{
					soundSet = "Zucchini_pickup_SoundSet";
					id = 797;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class HumanSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_HumanSteakMeat0";
		descriptionShort = "$STR_HumanSteakMeat1";
		model = "\dz\gear\food\human_meat.p3d";
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		itemSize[] = {1,3};
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {7,50,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {4,200,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {4,150,150,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {5,150,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {7,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class GoatSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_GoatSteakMeat0";
		descriptionShort = "$STR_GoatSteakMeat1";
		model = "\dz\gear\food\meat_steak.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		itemSize[] = {1,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {2,250,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {2,200,150,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {3,200,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class MouflonSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_MouflonSteakMeat0";
		descriptionShort = "$STR_MouflonSteakMeat1";
		model = "\dz\gear\food\meat_steak.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 230;
		varQuantityMin = 0;
		varQuantityMax = 230;
		itemSize[] = {1,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {4.5,544,334,236,1,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {4,250,222,35,1,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {3.5,537,222,129,1};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {3,537,222,129,1};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {1.5,390,130,180,1};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {4,250,90,50,1,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class BoarSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_BoarSteakMeat0";
		descriptionShort = "$STR_BoarSteakMeat1";
		model = "\dz\gear\food\meat_steak.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 250;
		varQuantityMin = 0;
		varQuantityMax = 250;
		itemSize[] = {1,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {2,325,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,275,150,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {3,275,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class PigSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_PigSteakMeat0";
		descriptionShort = "$STR_PigSteakMeat1";
		model = "\dz\gear\food\meat_steak.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 250;
		varQuantityMin = 0;
		varQuantityMax = 250;
		itemSize[] = {1,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,300,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,250,150,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {2,250,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,50,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class DeerSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_DeerSteakMeat0";
		descriptionShort = "$STR_DeerSteakMeat1";
		model = "\dz\gear\food\meat_steak.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 250;
		varQuantityMin = 0;
		varQuantityMax = 250;
		itemSize[] = {1,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {2,350,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,300,100,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {3,300,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class WolfSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_WolfSteakMeat0";
		descriptionShort = "$STR_WolfSteakMeat1";
		model = "\dz\gear\food\meat_steak.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		itemSize[] = {1,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {2,200,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {2,150,150,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {3,150,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class BearSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_BearSteakMeat0";
		descriptionShort = "$STR_BearSteakMeat1";
		model = "\dz\gear\food\meat_steak.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 500;
		varQuantityMin = 0;
		varQuantityMax = 500;
		itemSize[] = {2,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {2,400,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {2,350,150,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {3,350,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class CowSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CowSteakMeat0";
		descriptionShort = "$STR_CowSteakMeat1";
		model = "\dz\gear\food\meat_steak.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 500;
		varQuantityMin = 0;
		varQuantityMax = 500;
		itemSize[] = {2,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,300,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,250,100,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {1,250,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class SheepSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_SheepSteakMeat0";
		descriptionShort = "$STR_SheepSteakMeat1";
		model = "\dz\gear\food\meat_steak.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		itemSize[] = {1,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {2,250,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {2,200,100,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {3,200,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class FoxSteakMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_FoxSteakMeat0";
		descriptionShort = "$STR_FoxSteakMeat1";
		model = "\dz\gear\food\meat_steak.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 130;
		varQuantityMin = 0;
		varQuantityMax = 130;
		itemSize[] = {1,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_steak_raw_CO.paa","dz\gear\food\data\meat_steak_baked_CO.paa","dz\gear\food\data\meat_steak_boiled_co.paa","dz\gear\food\data\meat_steak_dried_CO.paa","dz\gear\food\data\meat_steak_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_steak_raw.rvmat","dz\gear\food\data\meat_steak_baked.rvmat","dz\gear\food\data\meat_steak_boiled.rvmat","dz\gear\food\data\meat_steak_dried.rvmat","dz\gear\food\data\meat_steak_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {4.5,544,334,236,1,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {4,250,222,35,1,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {3.5,537,222,129,1};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {3,537,222,129,1};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {1.5,390,130,180,1};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {4,250,90,50,1,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class ChickenBreastMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_ChickenBreastMeat0";
		descriptionShort = "$STR_ChickenBreastMeat1";
		model = "\dz\gear\food\meat_breast.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 125;
		varQuantityMin = 0;
		varQuantityMax = 125;
		itemSize[] = {1,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_breast_raw_CO.paa","dz\gear\food\data\meat_breast_baked_CO.paa","dz\gear\food\data\meat_breast_baked_CO.paa","dz\gear\food\data\meat_breast_dried_CO.paa","dz\gear\food\data\meat_breast_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_breast_raw.rvmat","dz\gear\food\data\meat_breast_baked.rvmat","dz\gear\food\data\meat_breast_boiled.rvmat","dz\gear\food\data\meat_breast_dried.rvmat","dz\gear\food\data\meat_breast_burnt.rvmat","dz\gear\food\data\meat_breast_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,200,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,150,100,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {2,150,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class RabbitLegMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_RabbitLegMeat0";
		descriptionShort = "$STR_RabbitLegMeat1";
		model = "\dz\gear\food\meat_leg.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 110;
		varQuantityMin = 0;
		varQuantityMax = 110;
		itemSize[] = {1,2};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\meat_leg_raw_CO.paa","dz\gear\food\data\meat_leg_baked_CO.paa","dz\gear\food\data\meat_leg_baked_CO.paa","dz\gear\food\data\meat_leg_dried_CO.paa","dz\gear\food\data\meat_leg_burned_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\meat_leg_raw.rvmat","dz\gear\food\data\meat_leg_baked.rvmat","dz\gear\food\data\meat_leg_boiled.rvmat","dz\gear\food\data\meat_leg_dried.rvmat","dz\gear\food\data\meat_leg_burnt.rvmat","dz\gear\food\data\meat_leg_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {4.5,517,338,218,1,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {4,150,338,30,1,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {3.5,480,184,155,1};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {3,480,184,155,1};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {1.5,380,120,150,1};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {4,100,50,40,1,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class CarpFilletMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_CarpFilletMeat0";
		descriptionShort = "$STR_CarpFilletMeat1";
		model = "\dz\gear\food\carp_fillet.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		varQuantityInit = 300;
		varQuantityMin = 0;
		varQuantityMax = 300;
		itemSize[] = {2,3};
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\carp_fillet_raw_CO.paa","dz\gear\food\data\carp_fillet_baked_CO.paa","dz\gear\food\data\carp_fillet_boiled_CO.paa","dz\gear\food\data\carp_fillet_dried_CO.paa","dz\gear\food\data\carp_fillet_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\carp_fillet_raw.rvmat","dz\gear\food\data\carp_fillet_baked.rvmat","dz\gear\food\data\carp_fillet_boiled.rvmat","dz\gear\food\data\carp_fillet_dried.rvmat","dz\gear\food\data\carp_fillet_burnt.rvmat","dz\gear\food\data\carp_fillet_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,100,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,50,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {2,300,100,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {2,250,250,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {3,200,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class MackerelFilletMeat: Edible_Base
	{
		scope = 2;
		displayName = "$STR_MackerelFilletMeat0";
		descriptionShort = "$STR_MackerelFilletMeat1";
		model = "\dz\gear\food\mackerel_fillet.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		quantityBar = 1;
		itemSize[] = {3,1};
		varQuantityInit = 200;
		varQuantityMin = 0;
		varQuantityMax = 200;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mackerel_fillet_raw_CO.paa","dz\gear\food\data\mackerel_fillet_baked_CO.paa","dz\gear\food\data\mackerel_fillet_boiled_CO.paa","dz\gear\food\data\mackerel_fillet_dried_CO.paa","dz\gear\food\data\mackerel_fillet_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mackerel_fillet_raw.rvmat","dz\gear\food\data\mackerel_fillet_baked.rvmat","dz\gear\food\data\mackerel_fillet_boiled.rvmat","dz\gear\food\data\mackerel_fillet_dried.rvmat","dz\gear\food\data\mackerel_fillet_burnt.rvmat","dz\gear\food\data\mackerel_fillet_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {5,50,100,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,25,50,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,600,100,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,400,400,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {2,400,130,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {5,50,0,1,0,16};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: MeatStageTransitions{};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Lard: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Lard0";
		descriptionShort = "$STR_Lard1";
		model = "\dz\gear\food\lard.p3d";
		rotationFlags = 34;
		weight = 0;
		interactionWeight = 1;
		itemSize[] = {2,2};
		varQuantityInit = 200;
		varQuantityMin = 0;
		varQuantityMax = 200;
		quantityBar = 1;
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\lard_raw_CO.paa","dz\gear\food\data\lard_baked_CO.paa","dz\gear\food\data\lard_boiled_CO.paa","dz\gear\food\data\lard_dried_CO.paa","dz\gear\food\data\lard_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\lard_raw.rvmat","dz\gear\food\data\lard_baked.rvmat","dz\gear\food\data\lard_boiled.rvmat","dz\gear\food\data\lard_dried.rvmat","dz\gear\food\data\lard_burnt.rvmat","dz\gear\food\data\meat_steak_rotten.rvmat"};
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
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {7,100,50,1,0,4};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {10,50,25,1,0,"4 + 		  16"};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {4,300,50,1,0};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {4,250,100,1,0};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {5,250,0,1,0};
					cooking_properties[] = {70,120,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {7,100,0,1,0,16};
					cooking_properties[] = {100,150};
				};
			};
			class FoodStageTransitions: MeatStageTransitions
			{
				class Baked
				{
					class ToRotten
					{
						transition_to = 6;
						cooking_method = 4;
					};
				};
				class Dried
				{
					class ToBaked
					{
						transition_to = 2;
						cooking_method = 1;
					};
					class ToBoiled
					{
						transition_to = 3;
						cooking_method = 2;
					};
				};
			};
		};
		class NoiseImpact
		{
			strength = 600.0;
			type = "sound";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Carp: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Carp0";
		descriptionShort = "$STR_Carp1";
		model = "\dz\gear\food\carp_live.p3d";
		rotationFlags = 17;
		weight = 800;
		itemSize[] = {2,3};
		stackedUnit = "g";
		quantityBar = 1;
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\carp_live_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\carp_live.rvmat"};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,20,60,70,1};
					cooking_properties[] = {0,0};
				};
			};
			class FoodStageTransitions: NotCookable{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Sardines: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Sardines0";
		descriptionShort = "$STR_Sardines1";
		model = "\dz\gear\food\sardines_live.p3d";
		itemSize[] = {2,1};
		weight = 110;
		stackedUnit = "g";
		quantityBar = 1;
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\sardines_raw_CO.paa","dz\gear\food\data\sardines_baked_CO.paa","dz\gear\food\data\sardines_raw_CO.paa","dz\gear\food\data\sardines_baked_CO.paa","dz\gear\food\data\sardines_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\sardines_raw.rvmat","dz\gear\food\data\sardines_baked.rvmat","dz\gear\food\data\sardines_boiled.rvmat","dz\gear\food\data\sardines_dried.rvmat","dz\gear\food\data\sardines_burnt.rvmat","dz\gear\food\data\sardines_rotten.rvmat"};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,69,172,70,1};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {1,40,160,25,1};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1,60,140,60,1};
					cooking_properties[] = {70,45};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1,60,160,60,1};
					cooking_properties[] = {70,55};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {1,50,70,50,1};
					cooking_properties[] = {70,45,80};
				};
				class Burned
				{
					visual_properties[] = {1,4,4};
					nutrition_properties[] = {1,20,60,20,1};
					cooking_properties[] = {100,30};
				};
			};
			class FoodStageTransitions: AnimalCorpsesStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Mackerel: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Mackerel0";
		descriptionShort = "$STR_Mackerel1";
		model = "\dz\gear\food\mackerel_live.p3d";
		rotationFlags = 17;
		weight = 180;
		itemSize[] = {4,2};
		stackedUnit = "g";
		quantityBar = 1;
		varQuantityInit = 400;
		varQuantityMin = 0;
		varQuantityMax = 400;
		isMeleeWeapon = 1;
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mackerel_live_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mackerel_live.rvmat"};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,69,172,70,1};
					cooking_properties[] = {0,0};
				};
			};
			class FoodStageTransitions: NotCookable{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class Worm: Edible_Base
	{
		scope = 2;
		displayName = "$STR_Worm0";
		descriptionShort = "$STR_Worm1";
		model = "\dz\gear\food\bait_worm.p3d";
		rotationFlags = 17;
		weight = 21;
		stackedUnit = "";
		canBeSplit = 0;
		quantityBar = 0;
		varQuantityInit = 0.0;
		varQuantityMin = 0.0;
		varQuantityMax = 0.0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{"DZ\gear\food\data\"""".rvmat"}},{0.7,{"DZ\gear\food\data\"""".rvmat"}},{0.5,{"DZ\gear\food\data\""""_damage.rvmat"}},{0.3,{"DZ\gear\food\data\""""_damage.rvmat"}},{0.0,{"DZ\gear\food\data\""""_destruct.rvmat"}}};
				};
			};
		};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\bait_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\bait.rvmat"};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {1,80,8,42,1};
					cooking_properties[] = {0,0};
				};
			};
			class FoodStageTransitions: NotCookable{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class MushroomBase: Edible_Base
	{
		varQuantityInit = 130;
		varQuantityMin = 0;
		varQuantityMax = 130;
	};
	class AgaricusMushroom: MushroomBase
	{
		scope = 2;
		displayName = "$STR_AgaricusMushroom0";
		descriptionShort = "$STR_AgaricusMushroom1";
		model = "\dz\gear\food\mushroom_agaricus.p3d";
		weight = 0;
		itemSize[] = {1,2};
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		stackedUnit = "";
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_agaricus_raw_CO.paa","dz\gear\food\data\mushroom_agaricus_baked_CO.paa","dz\gear\food\data\mushroom_agaricus_baked_CO.paa","dz\gear\food\data\mushroom_agaricus_dried_CO.paa","dz\gear\food\data\mushroom_agaricus_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_agaricus_raw.rvmat","dz\gear\food\data\mushroom_agaricus_baked.rvmat","dz\gear\food\data\mushroom_agaricus_boiled.rvmat","dz\gear\food\data\mushroom_agaricus_dried.rvmat","dz\gear\food\data\mushroom_agaricus_burnt.rvmat","dz\gear\food\data\mushroom_agaricus_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,20,95,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {2,15,47.5,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1.75,80,71.25,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1.5,60,120,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {0.75,30,9.5,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {2,15,23.75,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: MushroomsStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class AmanitaMushroom: MushroomBase
	{
		scope = 2;
		displayName = "$STR_AmanitaMushroom0";
		descriptionShort = "$STR_AmanitaMushroom1";
		model = "\dz\gear\food\mushroom_amanita.p3d";
		weight = 0;
		itemSize[] = {1,2};
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		stackedUnit = "";
		inventorySlot[] = {"Ingredient"};
		hiddenSelections[] = {"cs_raw","cs_boiled"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_amanita_raw_CO.paa","dz\gear\food\data\mushroom_amanita_boiled_CO.paa","dz\gear\food\data\mushroom_amanita_baked_CO.paa","dz\gear\food\data\mushroom_amanita_dried_CO.paa","dz\gear\food\data\mushroom_amanita_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_amanita_raw.rvmat","dz\gear\food\data\mushroom_amanita_baked.rvmat","dz\gear\food\data\mushroom_amanita_boiled.rvmat","dz\gear\food\data\mushroom_amanita_dried.rvmat","dz\gear\food\data\mushroom_amanita_burnt.rvmat","dz\gear\food\data\mushroom_amanita_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,20,95,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {2,15,47.5,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {1,1,1};
					nutrition_properties[] = {1.75,35,71.25,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {1,2,2};
					nutrition_properties[] = {1.5,25,95,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {0.75,20,9.5,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {1,4,4};
					nutrition_properties[] = {2,15,23.75,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: MushroomsStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class MacrolepiotaMushroom: MushroomBase
	{
		scope = 2;
		displayName = "$STR_MacrolepiotaMushroom0";
		descriptionShort = "$STR_MacrolepiotaMushroom1";
		model = "\dz\gear\food\mushroom_macrolepiota.p3d";
		weight = 0;
		itemSize[] = {1,2};
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		stackedUnit = "";
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw","cs_baked","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_macrolepiota_raw_CO.paa","dz\gear\food\data\mushroom_macrolepiota_baked_CO.paa","dz\gear\food\data\mushroom_macrolepiota_baked_CO.paa","dz\gear\food\data\mushroom_macrolepiota_dried_CO.paa","dz\gear\food\data\mushroom_macrolepiota_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_macrolepiota_raw.rvmat","dz\gear\food\data\mushroom_macrolepiota_baked.rvmat","dz\gear\food\data\mushroom_macrolepiota_boiled.rvmat","dz\gear\food\data\mushroom_macrolepiota_dried.rvmat","dz\gear\food\data\mushroom_macrolepiota_burnt.rvmat","dz\gear\food\data\mushroom_macrolepiota_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,20,95,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {2,15,47.5,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {1,1,1};
					nutrition_properties[] = {1.75,80,71.25,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {1,2,2};
					nutrition_properties[] = {1.5,60,120,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {2,3,3};
					nutrition_properties[] = {0.75,30,9.5,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {2,4,4};
					nutrition_properties[] = {2,15,23.75,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: MushroomsStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class LactariusMushroom: MushroomBase
	{
		scope = 2;
		displayName = "$STR_LactariusMushroom0";
		descriptionShort = "$STR_LactariusMushroom1";
		model = "\dz\gear\food\mushroom_lactarius.p3d";
		weight = 0;
		itemSize[] = {1,2};
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		stackedUnit = "";
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_lactarius_raw_CO.paa","dz\gear\food\data\mushroom_lactarius_baked_CO.paa","dz\gear\food\data\mushroom_lactarius_baked_CO.paa","dz\gear\food\data\mushroom_lactarius_dried_CO.paa","dz\gear\food\data\mushroom_lactarius_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_lactarius_raw.rvmat","dz\gear\food\data\mushroom_lactarius_baked.rvmat","dz\gear\food\data\mushroom_lactarius_boiled.rvmat","dz\gear\food\data\mushroom_lactarius_dried.rvmat","dz\gear\food\data\mushroom_lactarius_burnt.rvmat","dz\gear\food\data\mushroom_lactarius_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,20,95,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {2,15,47.5,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1.75,80,71.25,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1.5,60,120,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {0.75,30,9.5,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {2,15,23.75,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: MushroomsStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class PsilocybeMushroom: MushroomBase
	{
		scope = 2;
		displayName = "$STR_PsilocybeMushroom0";
		descriptionShort = "$STR_PsilocybeMushroom1";
		model = "\dz\gear\food\Psilocybe_semilanceata.p3d";
		weight = 0;
		itemSize[] = {1,1};
		varQuantityInit = 50;
		varQuantityMin = 0;
		varQuantityMax = 50;
		stackedUnit = "";
		inventorySlot[] = {"Ingredient"};
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\Psilocybe_semilanceata_CO.paa","dz\gear\food\data\Psilocybe_semilanceata_dried_CO.paa","dz\gear\food\data\Psilocybe_semilanceata_dried_CO.paa","dz\gear\food\data\Psilocybe_semilanceata_dried_CO.paa","dz\gear\food\data\Psilocybe_semilanceata_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\Psilocybe_semilanceata_raw.rvmat","dz\gear\food\data\Psilocybe_semilanceata_baked.rvmat","dz\gear\food\data\Psilocybe_semilanceata_boiled.rvmat","dz\gear\food\data\Psilocybe_semilanceata_dried.rvmat","dz\gear\food\data\Psilocybe_semilanceata_burnt.rvmat","dz\gear\food\data\Psilocybe_semilanceata_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,20,95,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {2,15,47.5,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1.75,35,71.25,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1.5,25,95,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {0.75,20,9.5,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {2,15,23.75,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: MushroomsStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class AuriculariaMushroom: MushroomBase
	{
		scope = 2;
		displayName = "$STR_AuriculariaMushroom0";
		descriptionShort = "$STR_AuriculariaMushroom1";
		model = "\dz\gear\food\mushroom_auricularia.p3d";
		weight = 0;
		itemSize[] = {1,2};
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		rotationFlags = 1;
		stackedUnit = "";
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_auricularia_raw_CO.paa","dz\gear\food\data\mushroom_auricularia_baked_CO.paa","dz\gear\food\data\mushroom_auricularia_boiled_CO.paa","dz\gear\food\data\mushroom_auricularia_dried_CO.paa","dz\gear\food\data\mushroom_auricularia_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_auricularia_raw.rvmat","dz\gear\food\data\mushroom_auricularia_baked.rvmat","dz\gear\food\data\mushroom_auricularia_boiled.rvmat","dz\gear\food\data\mushroom_auricularia_dried.rvmat","dz\gear\food\data\mushroom_auricularia_burnt.rvmat","dz\gear\food\data\mushroom_auricularia_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,20,95,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {2,15,47.5,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1.75,80,71.25,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1.5,60,120,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {0,3,3};
					nutrition_properties[] = {0.75,30,9.5,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {0,4,4};
					nutrition_properties[] = {2,15,23.75,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: MushroomsStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class BoletusMushroom: MushroomBase
	{
		scope = 2;
		displayName = "$STR_BoletusMushroom0";
		descriptionShort = "$STR_BoletusMushroom1";
		model = "\dz\gear\food\Mushroom_boletus.p3d";
		weight = 0;
		itemSize[] = {1,2};
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		stackedUnit = "";
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_boletus_raw_CO.paa","dz\gear\food\data\mushroom_boletus_baked_CO.paa","dz\gear\food\data\mushroom_boletus_boiled_CO.paa","dz\gear\food\data\mushroom_boletus_boiled_CO.paa","dz\gear\food\data\mushroom_boletus_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_boletus_raw.rvmat","dz\gear\food\data\mushroom_boletus_baked.rvmat","dz\gear\food\data\mushroom_boletus_boiled.rvmat","dz\gear\food\data\mushroom_boletus_dried.rvmat","dz\gear\food\data\mushroom_boletus_burnt.rvmat","dz\gear\food\data\mushroom_boletus_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,20,95,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {2,15,47.5,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {0,1,1};
					nutrition_properties[] = {1.75,80,71.25,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {0,2,2};
					nutrition_properties[] = {1.5,60,120,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {1,3,3};
					nutrition_properties[] = {0.75,30,9.5,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {1,4,4};
					nutrition_properties[] = {2,15,23.75,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: MushroomsStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
	class PleurotusMushroom: MushroomBase
	{
		scope = 2;
		displayName = "$STR_PleurotusMushroom0";
		descriptionShort = "$STR_PleurotusMushroom1";
		model = "\dz\gear\food\mushroom_pleurotus.p3d";
		weight = 0;
		itemSize[] = {1,2};
		varQuantityInit = 150;
		varQuantityMin = 0;
		varQuantityMax = 150;
		rotationFlags = 1;
		stackedUnit = "";
		inventorySlot[] = {"Ingredient","DirectCookingA","DirectCookingB","DirectCookingC","SmokingA","SmokingB","SmokingC","SmokingD"};
		hiddenSelections[] = {"cs_raw","cs_boiled","cs_dried"};
		hiddenSelectionsTextures[] = {"dz\gear\food\data\mushroom_pleurotus_raw_CO.paa","dz\gear\food\data\mushroom_pleurotus_baked_CO.paa","dz\gear\food\data\mushroom_pleurotus_baked_CO.paa","dz\gear\food\data\mushroom_pleurotus_dried_CO.paa","dz\gear\food\data\mushroom_pleurotus_burnt_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\food\data\mushroom_pleurotus_raw.rvmat","dz\gear\food\data\mushroom_pleurotus_baked.rvmat","dz\gear\food\data\mushroom_pleurotus_boiled.rvmat","dz\gear\food\data\mushroom_pleurotus_dried.rvmat","dz\gear\food\data\mushroom_pleurotus_burnt.rvmat","dz\gear\food\data\mushroom_pleurotus_rotten.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 10;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class AnimationSources: FoodAnimationSources{};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[] = {0,0,0};
					nutrition_properties[] = {2.5,20,95,1,0};
					cooking_properties[] = {0,0};
				};
				class Rotten
				{
					visual_properties[] = {-1,-1,5};
					nutrition_properties[] = {2,15,47.5,1,0,16};
					cooking_properties[] = {0,0};
				};
				class Baked
				{
					visual_properties[] = {1,1,1};
					nutrition_properties[] = {1.75,80,71.25,1,0};
					cooking_properties[] = {70,35};
				};
				class Boiled
				{
					visual_properties[] = {1,2,2};
					nutrition_properties[] = {1.5,60,120,1,0};
					cooking_properties[] = {70,45};
				};
				class Dried
				{
					visual_properties[] = {2,3,3};
					nutrition_properties[] = {0.75,30,9.5,1,0};
					cooking_properties[] = {70,30,80};
				};
				class Burned
				{
					visual_properties[] = {1,4,4};
					nutrition_properties[] = {2,15,23.75,1,0};
					cooking_properties[] = {100,20};
				};
			};
			class FoodStageTransitions: MushroomsStageTransitions{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet = "openTunaCan_SoundSet";
					id = 204;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Eating_BoxOpen
				{
					soundSet = "Eating_BoxOpen_Soundset";
					id = 893;
				};
				class Eating_BoxShake
				{
					soundSet = "Eating_BoxShake_Soundset";
					id = 894;
				};
				class Eating_BoxEnd
				{
					soundSet = "Eating_BoxEnd_Soundset";
					id = 895;
				};
			};
		};
	};
};
