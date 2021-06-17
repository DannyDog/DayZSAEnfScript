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
	class DZ_Characters_Headgear
	{
		units[] = {"BaseballCap_Blue","BaseballCap_Beige","BaseballCap_Black","BaseballCap_Olive","BaseballCap_Pink","BaseballCap_Red","BaseballCap_Camo","BaseballCap_CMMG_Black","BaseballCap_CMMG_Pink","MotoHelmet_Black","MotoHelmet_Blue","MotoHelmet_Green","MotoHelmet_Red","MotoHelmet_White","Headtorch_Grey","CowboyHat_Brown","CowboyHat_black","CowboyHat_darkBrown","CowboyHat_green","BoonieHat_black","BoonieHat_Blue","BoonieHat_DPM","BoonieHat_dubok","BoonieHat_flecktran","BoonieHat_NavyBlue","BoonieHat_olive","BoonieHat_orange","BoonieHat_red","BoonieHat_Tan","FlatCap_Black","FlatCap_Grey","FlatCap_Brown","FlatCap_Blue","FlatCap_Red","FlatCap_Check_Black","FlatCap_Check_Brown","FlatCap_Check_Grey","GhillieHoodWoodland"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class Switchable_Base;
	class BallisticHelmet_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_BallisticHelmet_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_BallisticHelmet_ColorBase1";
		model = "\DZ\characters\headgear\HelmetMich_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 1000;
		itemSize[] = {4,3};
		varWetMax = 0.249;
		heatIsolation = 0.3;
		noMask = 0;
		headSelectionsToHide[] = {"Clipping_HelmetMich"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 75;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\HelmetMich.rvmat"}},{0.7,{"DZ\characters\headgear\data\HelmetMich.rvmat"}},{0.5,{"DZ\characters\headgear\data\HelmetMich_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\HelmetMich_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\HelmetMich_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.26;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\HelmetMich_m.p3d";
			female = "\DZ\characters\headgear\HelmetMich_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpPot_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "BallisticHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BallisticHelmet_Green: BallisticHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		color = "Green";
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\helmetmich_co.paa","dz\characters\headgear\data\helmetmich_co.paa","dz\characters\headgear\data\helmetmich_co.paa"};
	};
	class BallisticHelmet_Black: BallisticHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		color = "Black";
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\helmetmich_bk_co.paa","dz\characters\headgear\data\helmetmich_bk_co.paa","dz\characters\headgear\data\helmetmich_bk_co.paa"};
	};
	class BallisticHelmet_UN: BallisticHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		weight = 980;
		lootTag[] = {"Military_west"};
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\helmetmich_un_co.paa","dz\characters\headgear\data\helmetmich_un_co.paa","dz\characters\headgear\data\helmetmich_un_co.paa"};
	};
	class BaseballCap_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_BaseballCap_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_BaseballCap_ColorBase1";
		model = "\DZ\characters\headgear\BaseballCap_ground.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 110;
		itemSize[] = {3,2};
		varWetMax = 1.0;
		heatIsolation = 0.2;
		repairableWithKits[] = {5,2};
		repairCosts[] = {25.0};
		headSelectionsToHide[] = {"Clipping_baseballcap"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 25;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\BaseballCapII.rvmat"}},{0.7,{"DZ\characters\headgear\data\BaseballCapII.rvmat"}},{0.5,{"DZ\characters\headgear\data\BaseballCapII_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\BaseballCapII_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\BaseballCapII_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\BaseballCap_m.p3d";
			female = "\DZ\characters\headgear\BaseballCap_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BaseballCap_Blue: BaseballCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\dz\characters\headgear\data\baseballcapii_blue_co.paa","\dz\characters\headgear\data\baseballcapii_blue_co.paa","\dz\characters\headgear\data\baseballcapii_blue_co.paa"};
	};
	class BaseballCap_Beige: BaseballCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\dz\characters\headgear\data\baseballcapii_beige_co.paa","\dz\characters\headgear\data\baseballcapii_beige_co.paa","\dz\characters\headgear\data\baseballcapii_beige_co.paa"};
	};
	class BaseballCap_Black: BaseballCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\dz\characters\headgear\data\baseballcapii_black_co.paa","\dz\characters\headgear\data\baseballcapii_black_co.paa","\dz\characters\headgear\data\baseballcapii_black_co.paa"};
	};
	class BaseballCap_Olive: BaseballCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\dz\characters\headgear\data\baseballcapii_olive_co.paa","\dz\characters\headgear\data\baseballcapii_olive_co.paa","\dz\characters\headgear\data\baseballcapii_olive_co.paa"};
	};
	class BaseballCap_Pink: BaseballCap_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\headgear\data\baseballcapii_pink_co.paa","\dz\characters\headgear\data\baseballcapii_pink_co.paa","\dz\characters\headgear\data\baseballcapii_pink_co.paa"};
	};
	class BaseballCap_Red: BaseballCap_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\headgear\data\baseballcapii_red_co.paa","\dz\characters\headgear\data\baseballcapii_red_co.paa","\dz\characters\headgear\data\baseballcapii_red_co.paa"};
	};
	class BaseballCap_Camo: BaseballCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.75;
		hiddenSelectionsTextures[] = {"\dz\characters\headgear\data\baseballcapii_camo_co.paa","\dz\characters\headgear\data\baseballcapii_camo_co.paa","\dz\characters\headgear\data\baseballcapii_camo_co.paa"};
	};
	class BaseballCap_CMMG_Black: BaseballCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\dz\characters\headgear\data\baseballcapii_cmmg_black_co.paa","\dz\characters\headgear\data\baseballcapii_cmmg_black_co.paa","\dz\characters\headgear\data\baseballcapii_cmmg_black_co.paa"};
	};
	class BaseballCap_CMMG_Pink: BaseballCap_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\headgear\data\baseballcapii_cmmg_pink_co.paa","\dz\characters\headgear\data\baseballcapii_cmmg_pink_co.paa","\dz\characters\headgear\data\baseballcapii_cmmg_pink_co.paa"};
	};
	class ZSh3PilotHelmet: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ZSh3PilotHelmet0";
		descriptionShort = "$STR_CfgVehicles_ZSh3PilotHelmet1";
		model = "\DZ\characters\headgear\HeloHelmet_ground.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 1450;
		itemSize[] = {4,4};
		varWetMax = 0.49;
		heatIsolation = 0.3;
		noMask = 0;
		headSelectionsToHide[] = {"Clipping_HeloHelmet"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\HeloHelmet_co.paa","\DZ\characters\headgear\data\HeloHelmet_co.paa","\DZ\characters\headgear\data\HeloHelmet_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 75;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\HeloHelmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\HeloHelmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\HeloHelmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\HeloHelmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\HeloHelmet_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\HeloHelmet.p3d";
			female = "\DZ\characters\headgear\HeloHelmet.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class ZSh3PilotHelmet_Green: ZSh3PilotHelmet
	{
		scope = 2;
		visibilityModifier = 0.9;
		color = "Green";
		lootCategory = "Crafted";
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\HeloHelmet_green_co.paa","\DZ\characters\headgear\data\HeloHelmet_green_co.paa","\DZ\characters\headgear\data\HeloHelmet_green_co.paa"};
	};
	class ZSh3PilotHelmet_Black: ZSh3PilotHelmet
	{
		scope = 2;
		visibilityModifier = 0.85;
		color = "Black";
		lootCategory = "Crafted";
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\HeloHelmet_black_co.paa","\DZ\characters\headgear\data\HeloHelmet_black_co.paa","\DZ\characters\headgear\data\HeloHelmet_black_co.paa"};
	};
	class ConstructionHelmet_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_ConstructionHelmet_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_ConstructionHelmet_ColorBase1";
		model = "\DZ\characters\headgear\ConstructionHelmet_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 470;
		itemSize[] = {4,3};
		varWetMax = 0.249;
		heatIsolation = 0.1;
		noMask = 0;
		noEyewear = 0;
		headSelectionsToHide[] = {"Clipping_ConstructionHelmet"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\ConstructionHelmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\ConstructionHelmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\ConstructionHelmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\ConstructionHelmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\ConstructionHelmet_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.9;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\ConstructionHelmet_m.p3d";
			female = "\DZ\characters\headgear\ConstructionHelmet_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class ConstructionHelmet_Blue: ConstructionHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ConstructionHelmet_blue_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_blue_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_blue_co.paa"};
	};
	class ConstructionHelmet_Lime: ConstructionHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ConstructionHelmet_lime_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_lime_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_lime_co.paa"};
	};
	class ConstructionHelmet_Orange: ConstructionHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ConstructionHelmet_orange_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_orange_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_orange_co.paa"};
	};
	class ConstructionHelmet_Red: ConstructionHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ConstructionHelmet_red_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_red_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_red_co.paa"};
	};
	class ConstructionHelmet_White: ConstructionHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ConstructionHelmet_white_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_white_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_white_co.paa"};
	};
	class ConstructionHelmet_Yellow: ConstructionHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ConstructionHelmet_yellow_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_yellow_co.paa","\DZ\characters\headgear\data\ConstructionHelmet_yellow_co.paa"};
	};
	class BurlapSackCover: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BurlapSack0";
		descriptionShort = "$STR_CfgVehicles_BurlapSack1";
		model = "\dz\characters\headgear\Head_sack_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 1;
		weight = 510;
		itemSize[] = {2,2};
		varWetMax = 1.0;
		heatIsolation = 0.3;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\head_sack_co.paa","dz\characters\headgear\data\head_sack_co.paa","dz\characters\headgear\data\head_sack_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\Head_Sack.rvmat"}},{0.7,{"DZ\characters\headgear\data\Head_Sack.rvmat"}},{0.5,{"DZ\characters\headgear\data\Head_Sack_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\Head_Sack_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\Head_Sack_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\Head_sack.p3d";
			female = "\DZ\characters\headgear\Head_sack.p3d";
		};
		class Protection
		{
			biological = 0.25;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "none";
		soundVoicePriority = 10;
	};
	class BeanieHat_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_BeanieHat_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_BeanieHat_ColorBase1";
		model = "\DZ\characters\headgear\BeanieHat_ground.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 90;
		itemSize[] = {3,2};
		varWetMax = 1.0;
		heatIsolation = 0.7;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_BeanieHat"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\BeanieHat.rvmat"}},{0.7,{"DZ\characters\headgear\data\BeanieHat.rvmat"}},{0.5,{"DZ\characters\headgear\data\BeanieHat_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\BeanieHat_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\BeanieHat_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\BeanieHat_m.p3d";
			female = "\DZ\characters\headgear\BeanieHat_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BeanieHat_Beige: BeanieHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\BeanieHat_beige_co.paa","\DZ\characters\headgear\data\BeanieHat_beige_co.paa","\DZ\characters\headgear\data\BeanieHat_beige_co.paa"};
	};
	class BeanieHat_Black: BeanieHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\BeanieHat_black_co.paa","\DZ\characters\headgear\data\BeanieHat_black_co.paa","\DZ\characters\headgear\data\BeanieHat_black_co.paa"};
	};
	class BeanieHat_Blue: BeanieHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\BeanieHat_blue_co.paa","\DZ\characters\headgear\data\BeanieHat_blue_co.paa","\DZ\characters\headgear\data\BeanieHat_blue_co.paa"};
	};
	class BeanieHat_Brown: BeanieHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\BeanieHat_brown_co.paa","\DZ\characters\headgear\data\BeanieHat_brown_co.paa","\DZ\characters\headgear\data\BeanieHat_brown_co.paa"};
	};
	class BeanieHat_Green: BeanieHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\BeanieHat_green_co.paa","\DZ\characters\headgear\data\BeanieHat_green_co.paa","\DZ\characters\headgear\data\BeanieHat_green_co.paa"};
	};
	class BeanieHat_Grey: BeanieHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\BeanieHat_grey_co.paa","\DZ\characters\headgear\data\BeanieHat_grey_co.paa","\DZ\characters\headgear\data\BeanieHat_grey_co.paa"};
	};
	class BeanieHat_Pink: BeanieHat_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\BeanieHat_pink_co.paa","\DZ\characters\headgear\data\BeanieHat_pink_co.paa","\DZ\characters\headgear\data\BeanieHat_pink_co.paa"};
	};
	class BeanieHat_Red: BeanieHat_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\BeanieHat_red_co.paa","\DZ\characters\headgear\data\BeanieHat_red_co.paa","\DZ\characters\headgear\data\BeanieHat_red_co.paa"};
	};
	class Ushanka_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_Ushanka_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_Ushanka_ColorBase1";
		model = "\DZ\characters\headgear\ushanka_ground.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 320;
		itemSize[] = {3,2};
		varWetMax = 1.0;
		heatIsolation = 1;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_ushanka"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\Ushanka.rvmat"}},{0.7,{"DZ\characters\headgear\data\Ushanka.rvmat"}},{0.5,{"DZ\characters\headgear\data\Ushanka_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\Ushanka_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\Ushanka_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\ushanka_m.p3d";
			female = "\DZ\characters\headgear\ushanka_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Ushanka_Black: Ushanka_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\Ushanka_black_co.paa","\DZ\characters\headgear\data\Ushanka_black_co.paa","\DZ\characters\headgear\data\Ushanka_black_co.paa"};
	};
	class Ushanka_Blue: Ushanka_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\Ushanka_blue_co.paa","\DZ\characters\headgear\data\Ushanka_blue_co.paa","\DZ\characters\headgear\data\Ushanka_blue_co.paa"};
	};
	class Ushanka_Green: Ushanka_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\Ushanka_green_co.paa","\DZ\characters\headgear\data\Ushanka_green_co.paa","\DZ\characters\headgear\data\Ushanka_green_co.paa"};
	};
	class PumpkinHelmet: Clothing
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_pumpkinhelmet0";
		descriptionShort = "$STR_cfgvehicles_pumpkinhelmet1";
		model = "\DZ\characters\headgear\PumpkinHelmet_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 500;
		itemSize[] = {2,2};
		varWetMax = 0.049;
		heatIsolation = 1;
		noMask = 1;
		noEyewear = 1;
		headSelectionsToHide[] = {"Clipping_PumpkinHelmet"};
		class Reflectors
		{
			class Beam
			{
				color[] = {1.0,0.55,0.0,1.0};
				brightness = 1.0;
				radius = 20;
				angle = 70;
				angleInnerRatio = 0.25;
				dayLight = 1;
				flareAngleBias = 40.0;
				position = "beamStart";
				direction = "beamEnd";
				hitpoint = "bulb";
				selection = "bulb";
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\PumpkinHelmet.p3d";
			female = "\DZ\characters\headgear\PumpkinHelmet.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLabels[] = {1.0,0.7,0.5,0.3,0.0};
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\MotoHelmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\MotoHelmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\MotoHelmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\MotoHelmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\MotoHelmet_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "none";
		soundVoicePriority = 10;
	};
	class MotoHelmet_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_MotoHelmet_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_MotoHelmet_ColorBase1";
		model = "\DZ\characters\headgear\MotoHelmet_ground.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {30.0,25.0};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 1210;
		itemSize[] = {4,4};
		varWetMax = 0.49;
		heatIsolation = 0.7;
		noMask = 1;
		noEyewear = 1;
		headSelectionsToHide[] = {"Clipping_MotoHelmet"};
		hiddenSelections[] = {"camoGround"};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\MotoHelmet.p3d";
			female = "\DZ\characters\headgear\MotoHelmet.p3d";
		};
		class Protection
		{
			biological = 0.25;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\MotoHelmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\MotoHelmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\MotoHelmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\MotoHelmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\MotoHelmet_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
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
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "motohelmet";
		soundVoicePriority = 10;
	};
	class MotoHelmet_Black: MotoHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		color = "Black";
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_black_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_ca.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor.rvmat"};
	};
	class MotoHelmet_Grey: MotoHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_grey_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_ca.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor.rvmat"};
	};
	class MotoHelmet_Green: MotoHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		color = "Green";
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_green_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_ca.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor.rvmat"};
	};
	class MotoHelmet_Lime: MotoHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_lime_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_ca.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor.rvmat"};
	};
	class MotoHelmet_Blue: MotoHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_blue_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_ca.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor.rvmat"};
	};
	class MotoHelmet_Red: MotoHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_red_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_ca.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor.rvmat"};
	};
	class MotoHelmet_White: MotoHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_white_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_ca.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor.rvmat"};
	};
	class DarkMotoHelmet_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_MotoHelmet_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_MotoHelmet_ColorBase1";
		model = "\DZ\characters\headgear\MotoHelmet_ground.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 1210;
		itemSize[] = {4,4};
		varWetMax = 0.49;
		heatIsolation = 0.7;
		noMask = 1;
		noEyewear = 1;
		headSelectionsToHide[] = {"Clipping_MotoHelmet"};
		hiddenSelections[] = {"camoGround","Camo1"};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\MotoHelmet.p3d";
			female = "\DZ\characters\headgear\MotoHelmet.p3d";
		};
		class Protection
		{
			biological = 0.25;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\MotoHelmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\MotoHelmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\MotoHelmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\MotoHelmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\MotoHelmet_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
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
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "motohelmet";
		soundVoicePriority = 10;
	};
	class DarkMotoHelmet_Black: DarkMotoHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		color = "Black";
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_black_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_dark_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor_nontrans.rvmat"};
	};
	class DarkMotoHelmet_Grey: DarkMotoHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_grey_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_dark_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor_nontrans.rvmat"};
	};
	class DarkMotoHelmet_Green: DarkMotoHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		color = "Green";
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_green_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_dark_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor_nontrans.rvmat"};
	};
	class DarkMotoHelmet_Lime: DarkMotoHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_lime_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_dark_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor_nontrans.rvmat"};
	};
	class DarkMotoHelmet_Blue: DarkMotoHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_blue_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_dark_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor_nontrans.rvmat"};
	};
	class DarkMotoHelmet_Red: DarkMotoHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_red_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_dark_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor_nontrans.rvmat"};
	};
	class DarkMotoHelmet_White: DarkMotoHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\MotoHelmet_white_co.paa","DZ\characters\headgear\data\MotoHelmetVisor_dark_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\characters\headgear\data\MotoHelmet.rvmat","DZ\characters\headgear\data\MotoHelmetVisor_nontrans.rvmat"};
	};
	class Headtorch_ColorBase: Switchable_Base
	{
		displayName = "$STR_CfgVehicles_Headtorch_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_Headtorch_ColorBase1";
		model = "\DZ\characters\headgear\HeadTorch_ground.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 1;
		weight = 200;
		itemSize[] = {2,2};
		varWetMax = 0.249;
		heatIsolation = 0;
		headSelectionsToHide[] = {"Clipping_HeadTorch"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","bulb","reflector","glass","reflector_far"};
		hiddenSelectionsTextures[] = {"dz\gear\tools\data\flashlight_old_co.paa","dz\gear\tools\data\flashlight_old_co.paa","dz\gear\tools\data\flashlight_glass.paa","dz\gear\tools\data\flashlight_old_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\tools\data\flashlight_old.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 25;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\HeadTorch.rvmat"}},{0.7,{"DZ\characters\headgear\data\HeadTorch.rvmat"}},{0.5,{"DZ\characters\headgear\data\HeadTorch_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\HeadTorch_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\HeadTorch_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\HeadTorch_m.p3d";
			female = "\DZ\characters\headgear\HeadTorch_f.p3d";
		};
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOffWhenInCargo = 1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 40;
		};
	};
	class Headtorch_Grey: Headtorch_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\headtorch_Grey_co.paa","dz\characters\headgear\data\headtorch_Grey_co.paa","dz\characters\headgear\data\headtorch_Grey_co.paa","dz\data\data\light_flare2_ca.paa","dz\characters\headgear\data\headtorch_Grey_co.paa","#(argb,8,8,3)color(0.0745098,0.141176,0.184314,0.3,ca)","dz\characters\headgear\data\headtorch_Grey_co.paa"};
	};
	class Headtorch_Black: Headtorch_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\headtorch_Black_co.paa","dz\characters\headgear\data\headtorch_Black_co.paa","dz\characters\headgear\data\headtorch_Black_co.paa","dz\data\data\light_flare2_ca.paa","dz\characters\headgear\data\headtorch_Black_co.paa","#(argb,8,8,3)color(0.0745098,0.141176,0.184314,0.3,ca)","dz\characters\headgear\data\headtorch_Black_co.paa"};
		class Reflectors
		{
			class Beam
			{
				color[] = {0.8,0.1,0.1,1.0};
				brightness = 8.0;
				radius = 25;
				angle = 130;
				angleInnerRatio = 0.25;
				dayLight = 1;
				flareAngleBias = 40.0;
				position = "beamStart";
				direction = "beamEnd";
				hitpoint = "bulb";
				selection = "bulb";
			};
		};
	};
	class Bandana_ColorBase: Clothing
	{
		scope = 0;
		displayName = "$STR_cfgvehicles_bandana_colorbase0";
		descriptionShort = "$STR_cfgvehicles_bandana_colorbase1";
		model = "\DZ\characters\headgear\BandanaHybrid_g.p3d";
		inventorySlot[] = {"Headgear","Mask"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		rotationFlags = 16;
		weight = 120;
		itemSize[] = {3,1};
		ragQuantity = 1;
		varWetMax = 1.0;
		heatIsolation = 0.4;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_BandanaHead","Clipping_BandanaFace"};
		hideSelectionsByinventorySlot[] = {1};
		hiddenSelections[] = {"camoGround","camoMale_H","camoMale_M","camoFemale_H","camoFemale_M"};
		simpleHiddenSelections[] = {"hide_headgear","hide_mask"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 25;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\BandanaH.rvmat"}},{0.7,{"DZ\characters\headgear\data\BandanaH.rvmat"}},{0.5,{"DZ\characters\headgear\data\BandanaH_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\BandanaH_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\BandanaH_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\BandanaHybrid_m.p3d";
			female = "\DZ\characters\headgear\BandanaHybrid_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Bandana_RedPattern: Bandana_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\BandanaFH_ground_redpattern_co.paa","DZ\characters\headgear\data\BandanaH_redpattern_co.paa","DZ\characters\headgear\data\BandanaF_redpattern_co.paa","DZ\characters\headgear\data\BandanaH_redpattern_co.paa","DZ\characters\headgear\data\BandanaF_redpattern_co.paa"};
	};
	class Bandana_BlackPattern: Bandana_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaFH_ground_blackpattern_co.paa","DZ\characters\headgear\data\BandanaH_blackpattern_co.paa","DZ\characters\headgear\data\BandanaF_blackpattern_co.paa","DZ\characters\headgear\data\BandanaH_blackpattern_co.paa","DZ\characters\headgear\data\BandanaF_blackpattern_co.paa"};
	};
	class Bandana_PolkaPattern: Bandana_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\BandanaFH_g_karkulka_co.paa","DZ\characters\headgear\data\BandanaH_karkulka_co.paa","DZ\characters\headgear\data\BandanaF_karkulka_co.paa","DZ\characters\headgear\data\BandanaH_karkulka_co.paa","DZ\characters\headgear\data\BandanaF_karkulka_co.paa"};
	};
	class Bandana_Greenpattern: Bandana_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\BandanaFHG_olive_co.paa","DZ\characters\headgear\data\BandanaFHG_olive_co.paa","DZ\characters\headgear\data\BandanaFHG_olive_co.paa","DZ\characters\headgear\data\BandanaFHG_olive_co.paa","DZ\characters\headgear\data\BandanaFHG_olive_co.paa"};
	};
	class Bandana_CamoPattern: Bandana_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\BandanaFHG_TTsKO_co.paa","DZ\characters\headgear\data\BandanaFHG_TTsKO_co.paa","DZ\characters\headgear\data\BandanaFHG_TTsKO_co.paa","DZ\characters\headgear\data\BandanaFHG_TTsKO_co.paa","DZ\characters\headgear\data\BandanaFHG_TTsKO_co.paa"};
	};
	class Bandana_Blue: Bandana_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\BandanaFH_g_blue_co.paa","DZ\characters\headgear\data\BandanaH_blue_co.paa","DZ\characters\headgear\data\BandanaF_blue_co.paa","DZ\characters\headgear\data\BandanaH_blue_co.paa","DZ\characters\headgear\data\BandanaF_blue_co.paa"};
	};
	class Bandana_Pink: Bandana_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\BandanaFH_g_pink_co.paa","DZ\characters\headgear\data\BandanaH_pink_co.paa","DZ\characters\headgear\data\BandanaF_pink_co.paa","DZ\characters\headgear\data\BandanaH_pink_co.paa","DZ\characters\headgear\data\BandanaF_pink_co.paa"};
	};
	class Bandana_Yellow: Bandana_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\BandanaFH_g_yellow_co.paa","DZ\characters\headgear\data\BandanaH_yellow_co.paa","DZ\characters\headgear\data\BandanaF_yellow_co.paa","DZ\characters\headgear\data\BandanaH_yellow_co.paa","DZ\characters\headgear\data\BandanaF_yellow_co.paa"};
	};
	class RadarCap_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_RadarCap_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_RadarCap_ColorBase1";
		model = "\DZ\characters\headgear\RadarCap_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 160;
		itemSize[] = {3,2};
		varWetMax = 1.0;
		heatIsolation = 0.8;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_RadarCap"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\RadarCap.rvmat"}},{0.7,{"DZ\characters\headgear\data\RadarCap.rvmat"}},{0.5,{"DZ\characters\headgear\data\RadarCap_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\RadarCap_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\RadarCap_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\RadarCap_m.p3d";
			female = "\DZ\characters\headgear\RadarCap_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class RadarCap_Black: RadarCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\RadarCap_black_co.paa","DZ\characters\headgear\data\RadarCap_black_co.paa","DZ\characters\headgear\data\RadarCap_black_co.paa"};
	};
	class RadarCap_Blue: RadarCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\RadarCap_blue_co.paa","DZ\characters\headgear\data\RadarCap_blue_co.paa","DZ\characters\headgear\data\RadarCap_blue_co.paa"};
	};
	class RadarCap_Brown: RadarCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\RadarCap_brown_co.paa","DZ\characters\headgear\data\RadarCap_brown_co.paa","DZ\characters\headgear\data\RadarCap_brown_co.paa"};
	};
	class RadarCap_Green: RadarCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\RadarCap_green_co.paa","DZ\characters\headgear\data\RadarCap_green_co.paa","DZ\characters\headgear\data\RadarCap_green_co.paa"};
	};
	class RadarCap_Red: RadarCap_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\RadarCap_red_co.paa","DZ\characters\headgear\data\RadarCap_red_co.paa","DZ\characters\headgear\data\RadarCap_red_co.paa"};
	};
	class MilitaryBeret_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_MilitaryBeret_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_MilitaryBeret_ColorBase1";
		model = "\DZ\characters\headgear\RadarCap_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 230;
		itemSize[] = {3,1};
		varWetMax = 1.0;
		heatIsolation = 0.2;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_MilitaryBeret_xx"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 35;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\MilitaryBeret.rvmat"}},{0.7,{"DZ\characters\headgear\data\MilitaryBeret.rvmat"}},{0.5,{"DZ\characters\headgear\data\MilitaryBeret_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\MilitaryBeret_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\MilitaryBeret_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class MilitaryBeret_Red: MilitaryBeret_ColorBase
	{
		scope = 2;
		model = "\DZ\characters\headgear\MilitaryBeret_g.p3d";
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\MilitaryBeret_m.p3d";
			female = "\DZ\characters\headgear\MilitaryBeret_f.p3d";
		};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MilitaryBeret_red_co.paa","\DZ\characters\headgear\data\MilitaryBeret_red_co.paa","\DZ\characters\headgear\data\MilitaryBeret_red_co.paa"};
	};
	class MilitaryBeret_UN: MilitaryBeret_ColorBase
	{
		scope = 2;
		model = "\DZ\characters\headgear\MilitaryBeret_UN_g.p3d";
		lootTag[] = {"Military_west"};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\MilitaryBeret_UN_m.p3d";
			female = "\DZ\characters\headgear\MilitaryBeret_UN_f.p3d";
		};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MilitaryBeret_blue_co.paa","\DZ\characters\headgear\data\MilitaryBeret_blue_co.paa","\DZ\characters\headgear\data\MilitaryBeret_blue_co.paa"};
	};
	class MilitaryBeret_NZ: MilitaryBeret_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		model = "\DZ\characters\headgear\MilitaryBeret_NZ_g.p3d";
		lootTag[] = {"Military_west"};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\MilitaryBeret_NZ_m.p3d";
			female = "\DZ\characters\headgear\MilitaryBeret_NZ_f.p3d";
		};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MilitaryBeret_green_co.paa","\DZ\characters\headgear\data\MilitaryBeret_green_co.paa","\DZ\characters\headgear\data\MilitaryBeret_green_co.paa"};
	};
	class MilitaryBeret_ChDKZ: MilitaryBeret_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		model = "\DZ\characters\headgear\MilitaryBeret_ChDKZ_g.p3d";
		lootTag[] = {"Military_east"};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\MilitaryBeret_ChDKZ_m.p3d";
			female = "\DZ\characters\headgear\MilitaryBeret_ChDKZ_f.p3d";
		};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MilitaryBeret_black_co.paa","\DZ\characters\headgear\data\MilitaryBeret_black_co.paa","\DZ\characters\headgear\data\MilitaryBeret_black_co.paa"};
	};
	class MilitaryBeret_CDF: MilitaryBeret_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		model = "\DZ\characters\headgear\MilitaryBeret_CDF_g.p3d";
		lootTag[] = {"Military_east"};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\MilitaryBeret_CDF_m.p3d";
			female = "\DZ\characters\headgear\MilitaryBeret_CDF_f.p3d";
		};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MilitaryBeret_green_co.paa","\DZ\characters\headgear\data\MilitaryBeret_green_co.paa","\DZ\characters\headgear\data\MilitaryBeret_green_co.paa"};
	};
	class FlatCap_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_FlatCap_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_FlatCap_ColorBase1";
		model = "\DZ\characters\headgear\FlatCap_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 240;
		itemSize[] = {3,2};
		varWetMax = 1.0;
		heatIsolation = 0.4;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_FlatCap"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 45;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\FlatCap.rvmat"}},{0.7,{"DZ\characters\headgear\data\FlatCap.rvmat"}},{0.5,{"DZ\characters\headgear\data\FlatCap_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\FlatCap_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\FlatCap_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\FlatCap.p3d";
			female = "\DZ\characters\headgear\FlatCap.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class FlatCap_Black: FlatCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FlatCap_black_co.paa","\DZ\characters\headgear\data\FlatCap_black_co.paa","\DZ\characters\headgear\data\FlatCap_black_co.paa"};
	};
	class FlatCap_Blue: FlatCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FlatCap_blue_co.paa","\DZ\characters\headgear\data\FlatCap_blue_co.paa","\DZ\characters\headgear\data\FlatCap_blue_co.paa"};
	};
	class FlatCap_Red: FlatCap_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FlatCap_red_co.paa","\DZ\characters\headgear\data\FlatCap_red_co.paa","\DZ\characters\headgear\data\FlatCap_red_co.paa"};
	};
	class FlatCap_Brown: FlatCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FlatCap_brown_co.paa","\DZ\characters\headgear\data\FlatCap_brown_co.paa","\DZ\characters\headgear\data\FlatCap_brown_co.paa"};
	};
	class FlatCap_Grey: FlatCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FlatCap_grey_co.paa","\DZ\characters\headgear\data\FlatCap_grey_co.paa","\DZ\characters\headgear\data\FlatCap_grey_co.paa"};
	};
	class FlatCap_BrownCheck: FlatCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FlatCap_brown_check_co.paa","\DZ\characters\headgear\data\FlatCap_brown_check_co.paa","\DZ\characters\headgear\data\FlatCap_brown_check_co.paa"};
	};
	class FlatCap_GreyCheck: FlatCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FlatCap_grey_check_co.paa","\DZ\characters\headgear\data\FlatCap_grey_check_co.paa","\DZ\characters\headgear\data\FlatCap_grey_check_co.paa"};
	};
	class FlatCap_BlackCheck: FlatCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FlatCap_black_check_co.paa","\DZ\characters\headgear\data\FlatCap_black_check_co.paa","\DZ\characters\headgear\data\FlatCap_black_check_co.paa"};
	};
	class ZmijovkaCap_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_ZmijovkaCap_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_ZmijovkaCap_ColorBase1";
		model = "\DZ\characters\headgear\ZmijovkaCap_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 17;
		weight = 110;
		itemSize[] = {3,2};
		varWetMax = 1.0;
		heatIsolation = 0.9;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_ZmijovkaCap"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\ZmijovkaCap_m.p3d";
			female = "\DZ\characters\headgear\ZmijovkaCap_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class ZmijovkaCap_Black: ZmijovkaCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ZmijovkaCap_black_co.paa","\DZ\characters\headgear\data\ZmijovkaCap_black_co.paa","\DZ\characters\headgear\data\ZmijovkaCap_black_co.paa"};
	};
	class ZmijovkaCap_Blue: ZmijovkaCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ZmijovkaCap_blue_co.paa","\DZ\characters\headgear\data\ZmijovkaCap_blue_co.paa","\DZ\characters\headgear\data\ZmijovkaCap_blue_co.paa"};
	};
	class ZmijovkaCap_Brown: ZmijovkaCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ZmijovkaCap_brown_co.paa","\DZ\characters\headgear\data\ZmijovkaCap_brown_co.paa","\DZ\characters\headgear\data\ZmijovkaCap_brown_co.paa"};
	};
	class ZmijovkaCap_Green: ZmijovkaCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ZmijovkaCap_green_co.paa","\DZ\characters\headgear\data\ZmijovkaCap_green_co.paa","\DZ\characters\headgear\data\ZmijovkaCap_green_co.paa"};
	};
	class ZmijovkaCap_Red: ZmijovkaCap_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ZmijovkaCap_red_co.paa","\DZ\characters\headgear\data\ZmijovkaCap_red_co.paa","\DZ\characters\headgear\data\ZmijovkaCap_red_co.paa"};
	};
	class CowboyHat_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_CowboyHat_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_CowboyHat_ColorBase1";
		model = "\DZ\characters\headgear\CowboyHat_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 370;
		itemSize[] = {3,2};
		varWetMax = 0.49;
		heatIsolation = 0.4;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_CowboyHat"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\CowboyHat.rvmat"}},{0.7,{"DZ\characters\headgear\data\CowboyHat.rvmat"}},{0.5,{"DZ\characters\headgear\data\CowboyHat_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\CowboyHat_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\CowboyHat_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\CowboyHat.p3d";
			female = "\DZ\characters\headgear\CowboyHat.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CowboyHat_Brown: CowboyHat_ColorBase
	{
		scope = 2;
		color = "Brown";
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\CowboyHat_Brown_co.paa","DZ\characters\headgear\data\CowboyHat_Brown_co.paa","DZ\characters\headgear\data\CowboyHat_Brown_co.paa"};
	};
	class CowboyHat_black: CowboyHat_ColorBase
	{
		scope = 2;
		color = "black";
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\CowboyHat_black_co.paa","DZ\characters\headgear\data\CowboyHat_black_co.paa","DZ\characters\headgear\data\CowboyHat_black_co.paa"};
	};
	class CowboyHat_darkBrown: CowboyHat_ColorBase
	{
		scope = 2;
		color = "darkBrown";
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\CowboyHat_darkBrown_co.paa","DZ\characters\headgear\data\CowboyHat_darkBrown_co.paa","DZ\characters\headgear\data\CowboyHat_darkBrown_co.paa"};
	};
	class CowboyHat_green: CowboyHat_ColorBase
	{
		scope = 2;
		color = "green";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\CowboyHat_green_co.paa","DZ\characters\headgear\data\CowboyHat_green_co.paa","DZ\characters\headgear\data\CowboyHat_green_co.paa"};
	};
	class BoonieHat_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_BoonieHat_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_BoonieHat_ColorBase1";
		model = "\DZ\characters\headgear\BoonieHat_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 170;
		itemSize[] = {3,2};
		attachments[] = {"Hook"};
		varWetMax = 1.0;
		heatIsolation = 0.3;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_BoonieHat"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\BoonieHat.rvmat"}},{0.7,{"DZ\characters\headgear\data\BoonieHat.rvmat"}},{0.5,{"DZ\characters\headgear\data\BoonieHat_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\BoonieHat_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\BoonieHat_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\BoonieHat.p3d";
			female = "\DZ\characters\headgear\BoonieHat.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BoonieHat_Black: BoonieHat_ColorBase
	{
		scope = 2;
		color = "black";
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BoonieHat_black_co.paa","DZ\characters\headgear\data\BoonieHat_black_co.paa","DZ\characters\headgear\data\BoonieHat_black_co.paa"};
	};
	class BoonieHat_Blue: BoonieHat_ColorBase
	{
		scope = 2;
		color = "Blue";
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BoonieHat_Blue_co.paa","DZ\characters\headgear\data\BoonieHat_Blue_co.paa","DZ\characters\headgear\data\BoonieHat_Blue_co.paa"};
	};
	class BoonieHat_DPM: BoonieHat_ColorBase
	{
		scope = 2;
		color = "DPM";
		visibilityModifier = 0.5;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BoonieHat_DPM_co.paa","DZ\characters\headgear\data\BoonieHat_DPM_co.paa","DZ\characters\headgear\data\BoonieHat_DPM_co.paa"};
	};
	class BoonieHat_Dubok: BoonieHat_ColorBase
	{
		scope = 2;
		color = "dubok";
		visibilityModifier = 0.5;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BoonieHat_dubok_co.paa","DZ\characters\headgear\data\BoonieHat_dubok_co.paa","DZ\characters\headgear\data\BoonieHat_dubok_co.paa"};
	};
	class BoonieHat_Flecktran: BoonieHat_ColorBase
	{
		scope = 2;
		color = "flecktran";
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BoonieHat_flecktran_co.paa","DZ\characters\headgear\data\BoonieHat_flecktran_co.paa","DZ\characters\headgear\data\BoonieHat_flecktran_co.paa"};
	};
	class BoonieHat_NavyBlue: BoonieHat_ColorBase
	{
		scope = 2;
		color = "NavyBlue";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BoonieHat_NavyBlue_co.paa","DZ\characters\headgear\data\BoonieHat_NavyBlue_co.paa","DZ\characters\headgear\data\BoonieHat_NavyBlue_co.paa"};
	};
	class BoonieHat_Olive: BoonieHat_ColorBase
	{
		scope = 2;
		color = "olive";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BoonieHat_olive_co.paa","DZ\characters\headgear\data\BoonieHat_olive_co.paa","DZ\characters\headgear\data\BoonieHat_olive_co.paa"};
	};
	class BoonieHat_Orange: BoonieHat_ColorBase
	{
		scope = 2;
		color = "orange";
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BoonieHat_orange_co.paa","DZ\characters\headgear\data\BoonieHat_orange_co.paa","DZ\characters\headgear\data\BoonieHat_orange_co.paa"};
	};
	class BoonieHat_Red: BoonieHat_ColorBase
	{
		scope = 2;
		color = "red";
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BoonieHat_red_co.paa","DZ\characters\headgear\data\BoonieHat_red_co.paa","DZ\characters\headgear\data\BoonieHat_red_co.paa"};
	};
	class BoonieHat_Tan: BoonieHat_ColorBase
	{
		scope = 2;
		color = "Tan";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BoonieHat_Tan_co.paa","DZ\characters\headgear\data\BoonieHat_Tan_co.paa","DZ\characters\headgear\data\BoonieHat_Tan_co.paa"};
	};
	class OfficerHat: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_OfficerHat0";
		descriptionShort = "$STR_CfgVehicles_OfficerHat1";
		model = "\DZ\characters\headgear\Officerhat_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 340;
		itemSize[] = {3,2};
		varWetMax = 0.79;
		heatIsolation = 0.2;
		visibilityModifier = 0.98;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_OfficerHat"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\Officerhat_co.paa","dz\characters\headgear\data\Officerhat_co.paa","dz\characters\headgear\data\Officerhat_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 35;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\Officerhat.rvmat"}},{0.7,{"DZ\characters\headgear\data\Officerhat.rvmat"}},{0.5,{"DZ\characters\headgear\data\Officerhat_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\Officerhat_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\Officerhat_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\Officerhat_m.p3d";
			female = "\DZ\characters\headgear\Officerhat_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class PoliceCap: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PoliceCap0";
		descriptionShort = "$STR_CfgVehicles_PoliceCap1";
		model = "\DZ\characters\headgear\PoliceCap_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 320;
		itemSize[] = {3,2};
		varWetMax = 0.79;
		heatIsolation = 0.2;
		visibilityModifier = 0.98;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_Policecap"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\PoliceCap_co.paa","dz\characters\headgear\data\PoliceCap_co.paa","dz\characters\headgear\data\PoliceCap_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\PoliceCap.rvmat"}},{0.7,{"DZ\characters\headgear\data\PoliceCap.rvmat"}},{0.5,{"DZ\characters\headgear\data\PoliceCap_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\PoliceCap_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\PoliceCap_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\PoliceCap_m.p3d";
			female = "\DZ\characters\headgear\PoliceCap_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class PilotkaCap: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PilotkaCap0";
		descriptionShort = "$STR_CfgVehicles_PilotkaCap1";
		model = "\DZ\characters\headgear\pilotka_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 140;
		itemSize[] = {3,1};
		varWetMax = 1.0;
		heatIsolation = 0.2;
		visibilityModifier = 0.98;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_pilotka"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\Pilotka_co.paa","dz\characters\headgear\data\Pilotka_co.paa","dz\characters\headgear\data\Pilotka_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\pilotka.rvmat"}},{0.7,{"DZ\characters\headgear\data\pilotka.rvmat"}},{0.5,{"DZ\characters\headgear\data\pilotka_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\pilotka_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\pilotka_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\pilotka_m.p3d";
			female = "\DZ\characters\headgear\pilotka_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class TankerHelmet: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TankerHelmet0";
		descriptionShort = "$STR_CfgVehicles_TankerHelmet1";
		model = "\DZ\characters\headgear\TankerHelmet_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 17;
		weight = 980;
		itemSize[] = {4,3};
		noMask = 0;
		noEyewear = 0;
		varWetMax = 1.0;
		heatIsolation = 0.9;
		visibilityModifier = 0.9;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_TankerHelmet"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\TankerHelmet_black_co.paa","\DZ\characters\headgear\data\TankerHelmet_black_co.paa","\DZ\characters\headgear\data\TankerHelmet_black_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\TankerHelmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\TankerHelmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\TankerHelmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\TankerHelmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\TankerHelmet_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.9;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\TankerHelmet.p3d";
			female = "\DZ\characters\headgear\TankerHelmet.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class GorkaHelmet: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_GorkaHelmet0";
		descriptionShort = "$STR_CfgVehicles_GorkaHelmet1";
		model = "\DZ\characters\headgear\Maska_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		attachments[] = {"Glass"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 1100;
		itemSize[] = {4,4};
		color = "Green";
		varWetMax = 0.49;
		heatIsolation = 0.8;
		noMask = 0;
		headSelectionsToHide[] = {"Clipping_Maska"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\maska_co.paa","\DZ\characters\headgear\data\maska_co.paa","\DZ\characters\headgear\data\maska_co.paa"};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\Maska.p3d";
			female = "\DZ\characters\headgear\Maska.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\HelmetMich.rvmat"}},{0.7,{"DZ\characters\headgear\data\HelmetMich.rvmat"}},{0.5,{"DZ\characters\headgear\data\HelmetMich_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\HelmetMich_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\HelmetMich_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.26;
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
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class GorkaHelmet_Green: GorkaHelmet
	{
		scope = 2;
		visibilityModifier = 0.7;
		color = "Green";
		lootCategory = "Crafted";
	};
	class GorkaHelmet_Black: GorkaHelmet
	{
		scope = 2;
		visibilityModifier = 0.7;
		color = "Black";
		lootCategory = "Crafted";
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\maska_black_co.paa","\DZ\characters\headgear\data\maska_black_co.paa","\DZ\characters\headgear\data\maska_black_co.paa"};
	};
	class FirefightersHelmet_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_FirefightersHelmet_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_FirefightersHelmet_ColorBase1";
		model = "\DZ\characters\headgear\FireHelmet_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 870;
		itemSize[] = {4,3};
		varWetMax = 0.249;
		heatIsolation = 0.5;
		headSelectionsToHide[] = {"Clipping_FireHelmet"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\FireHelmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\FireHelmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\FireHelmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\FireHelmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\FireHelmet_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\FireHelmet.p3d";
			female = "\DZ\characters\headgear\FireHelmet.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class FirefightersHelmet_Red: FirefightersHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FireHelmet_red_co.paa","\DZ\characters\headgear\data\FireHelmet_red_co.paa","\DZ\characters\headgear\data\FireHelmet_red_co.paa"};
	};
	class FirefightersHelmet_White: FirefightersHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FireHelmet_white_co.paa","\DZ\characters\headgear\data\FireHelmet_white_co.paa","\DZ\characters\headgear\data\FireHelmet_white_co.paa"};
	};
	class FirefightersHelmet_Yellow: FirefightersHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\FireHelmet_yellow_co.paa","\DZ\characters\headgear\data\FireHelmet_yellow_co.paa","\DZ\characters\headgear\data\FireHelmet_yellow_co.paa"};
	};
	class SkateHelmet_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_SkateHelmet_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_SkateHelmet_ColorBase1";
		model = "\DZ\characters\headgear\ProtecSkateHelmet2_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 460;
		itemSize[] = {4,3};
		varWetMax = 0.249;
		heatIsolation = 0.1;
		noMask = 0;
		noEyewear = 0;
		headSelectionsToHide[] = {"Clipping_ProtecSkateHelmet2"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\ProtecSkateHelmet2.rvmat"}},{0.7,{"DZ\characters\headgear\data\ProtecSkateHelmet2.rvmat"}},{0.5,{"DZ\characters\headgear\data\ProtecSkateHelmet2_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\ProtecSkateHelmet2_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\ProtecSkateHelmet2_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.9;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\ProtecSkateHelmet2_m.p3d";
			female = "\DZ\characters\headgear\ProtecSkateHelmet2_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SkateHelmet_Black: SkateHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ProtecSkateHelmet2_black_CO.paa","\DZ\characters\headgear\data\ProtecSkateHelmet2_black_CO.paa","\DZ\characters\headgear\data\ProtecSkateHelmet2_black_CO.paa"};
	};
	class SkateHelmet_Blue: SkateHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ProtecSkateHelmet2_blue_CO.paa","\DZ\characters\headgear\data\ProtecSkateHelmet2_blue_CO.paa","\DZ\characters\headgear\data\ProtecSkateHelmet2_blue_CO.paa"};
	};
	class SkateHelmet_Gray: SkateHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ProtecSkateHelmet2_gray_CO.paa","\DZ\characters\headgear\data\ProtecSkateHelmet2_gray_CO.paa","\DZ\characters\headgear\data\ProtecSkateHelmet2_gray_CO.paa"};
	};
	class SkateHelmet_Green: SkateHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ProtecSkateHelmet2_green_CO.paa","\DZ\characters\headgear\data\ProtecSkateHelmet2_green_CO.paa","\DZ\characters\headgear\data\ProtecSkateHelmet2_green_CO.paa"};
	};
	class SkateHelmet_Red: SkateHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\ProtecSkateHelmet2_red_CO.paa","\DZ\characters\headgear\data\ProtecSkateHelmet2_red_CO.paa","\DZ\characters\headgear\data\ProtecSkateHelmet2_red_CO.paa"};
	};
	class WeldingMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_WeldingMask0";
		descriptionShort = "$STR_CfgVehicles_WeldingMask1";
		model = "\DZ\characters\masks\Welding_Mask_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 2200;
		itemSize[] = {3,4};
		varWetMax = 0.249;
		heatIsolation = 0.1;
		visibilityModifier = 0.85;
		noMask = 1;
		noEyewear = 1;
		headSelectionsToHide[] = {"Clipping_Welding_Mask"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Welding_Mask_CO.paa","\DZ\characters\masks\data\Welding_Mask_CO.paa","\DZ\characters\masks\data\Welding_Mask_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\Welding_Mask.rvmat"}},{0.7,{"DZ\characters\masks\data\Welding_Mask.rvmat"}},{0.5,{"DZ\characters\masks\data\Welding_Mask_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\Welding_Mask_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\Welding_Mask_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\Welding_Mask_m.p3d";
			female = "\DZ\characters\masks\Welding_Mask_f.p3d";
		};
		class Protection
		{
			biological = 0.25;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "none";
		soundVoicePriority = 10;
	};
	class PrisonerCap: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PrisonerCap0";
		descriptionShort = "$STR_CfgVehicles_PrisonerCap1";
		model = "\DZ\characters\headgear\prison_cap_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 17;
		weight = 80;
		itemSize[] = {3,2};
		varWetMax = 1.0;
		heatIsolation = 0.1;
		headSelectionsToHide[] = {"Clipping_prison_cap"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\prison_cap_co.paa","\DZ\characters\headgear\data\prison_cap_co.paa","\DZ\characters\headgear\data\prison_cap_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 25;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\prison_cap.rvmat"}},{0.7,{"DZ\characters\headgear\data\prison_cap.rvmat"}},{0.5,{"DZ\characters\headgear\data\prison_cap_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\prison_cap_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\prison_cap_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\prison_cap_m.p3d";
			female = "\DZ\characters\headgear\prison_cap_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class GhillieHood_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_GhillieHood_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_GhillieHood_ColorBase1";
		model = "\DZ\characters\headgear\GhillieHood_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 2;
		weight = 410;
		itemSize[] = {4,3};
		varWetMax = 1.0;
		heatIsolation = 1;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_GhillieHood"};
		hiddenSelections[] = {"camoGround","camo","camo1"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\GhillieHood.p3d";
			female = "\DZ\characters\headgear\GhillieHood.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class GhillieHood_Tan: GhillieHood_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\dz\characters\backpacks\data\ghillie_tan_co.paa","\dz\characters\backpacks\data\ghillie_tan_co.paa","\dz\characters\backpacks\data\ghillie_tan_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\backpacks\data\ghillie_green_co.paa"}},{0.7,{"DZ\characters\backpacks\data\ghillie_tan_co.paa"}},{0.5,{"DZ\characters\backpacks\data\ghillie_tan_damage_co.paa"}},{0.3,{"DZ\characters\backpacks\data\ghillie_tan_damage_co.paa"}},{0.0,{"DZ\characters\backpacks\data\ghillie_tan_destruct_co.paa"}}};
				};
			};
		};
	};
	class GhillieHood_Woodland: GhillieHood_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.5;
		hiddenSelectionsTextures[] = {"\dz\characters\backpacks\data\ghillie_green_co.paa","\dz\characters\backpacks\data\ghillie_green_co.paa","\dz\characters\backpacks\data\ghillie_green_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\backpacks\data\ghillie_green_co.paa"}},{0.7,{"DZ\characters\backpacks\data\ghillie_green_co.paa"}},{0.5,{"DZ\characters\backpacks\data\ghillie_green_damage_co.paa"}},{0.3,{"DZ\characters\backpacks\data\ghillie_green_damage_co.paa"}},{0.0,{"DZ\characters\backpacks\data\ghillie_green_destruct_co.paa"}}};
				};
			};
			componentNames[] = {"dmg_all"};
		};
	};
	class GhillieHood_Mossy: GhillieHood_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.5;
		hiddenSelectionsTextures[] = {"\dz\characters\backpacks\data\ghillie_mossy_co.paa","\dz\characters\backpacks\data\ghillie_mossy_co.paa","\dz\characters\backpacks\data\ghillie_mossy_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\backpacks\data\ghillie_green_co.paa"}},{0.7,{"DZ\characters\backpacks\data\ghillie_mossy_co.paa"}},{0.5,{"DZ\characters\backpacks\data\ghillie_mossy_damage_co.paa"}},{0.3,{"DZ\characters\backpacks\data\ghillie_mossy_damage_co.paa"}},{0.0,{"DZ\characters\backpacks\data\ghillie_mossy_destruct_co.paa"}}};
				};
				componentNames[] = {"dmg_all"};
			};
		};
	};
	class LeatherHat_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_LeatherHat_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_LeatherHat_ColorBase1";
		model = "\DZ\characters\headgear\Hat_Leather_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 320;
		itemSize[] = {4,3};
		varWetMax = 0.249;
		heatIsolation = 0.4;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		noMask = 0;
		noEyewear = 0;
		headSelectionsToHide[] = {"Clipping_Hat_leather"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"dz\characters\headgear\data\Hat_Leather_CO.paa","dz\characters\headgear\data\Hat_Leather_CO.paa","dz\characters\headgear\data\Hat_Leather_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\Hat_Leather_m.p3d";
			female = "\DZ\characters\headgear\Hat_Leather_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class LeatherHat_Natural: LeatherHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsMaterials[] = {"dz\characters\headgear\data\Hat_Leather_natural.rvmat","dz\characters\headgear\data\Hat_Leather_natural.rvmat","dz\characters\headgear\data\Hat_Leather_natural.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\Hat_Leather_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\headgear\Data\Hat_Leather_natural_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\headgear\Data\Hat_Leather_natural_destruct.rvmat"}}};
				};
			};
		};
	};
	class LeatherHat_Beige: LeatherHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsMaterials[] = {"dz\characters\headgear\data\Hat_Leather_beige.rvmat","dz\characters\headgear\data\Hat_Leather_beige.rvmat","dz\characters\headgear\data\Hat_Leather_beige.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\Hat_Leather_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\headgear\Data\Hat_Leather_beige_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\headgear\Data\Hat_Leather_beige_destruct.rvmat"}}};
				};
			};
		};
	};
	class LeatherHat_Brown: LeatherHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsMaterials[] = {"dz\characters\headgear\data\Hat_Leather_brown.rvmat","dz\characters\headgear\data\Hat_Leather_brown.rvmat","dz\characters\headgear\data\Hat_Leather_brown.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\Hat_Leather_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\headgear\Data\Hat_Leather_brown_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\headgear\Data\Hat_Leather_brown_destruct.rvmat"}}};
				};
			};
		};
	};
	class LeatherHat_Black: LeatherHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsMaterials[] = {"dz\characters\headgear\data\Hat_Leather_black.rvmat","dz\characters\headgear\data\Hat_Leather_black.rvmat","dz\characters\headgear\data\Hat_Leather_black.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\Hat_Leather_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\headgear\Data\Hat_Leather_black_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\headgear\Data\Hat_Leather_black_destruct.rvmat"}}};
				};
			};
		};
	};
	class MedicalScrubsHat_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_MedicalScrubsHat_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_MedicalScrubsHat_ColorBase1";
		model = "\DZ\characters\headgear\MedicalScrubs_Hat_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 460;
		itemSize[] = {3,1};
		varWetMax = 1.0;
		heatIsolation = 0.1;
		headSelectionsToHide[] = {"Clipping_MedicalScrubs_Hat"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 25;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\MedicalScrubs_Hat.rvmat"}},{0.7,{"DZ\characters\headgear\data\MedicalScrubs_Hat.rvmat"}},{0.5,{"DZ\characters\headgear\data\MedicalScrubs_Hat_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\MedicalScrubs_Hat_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\MedicalScrubs_Hat_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\MedicalScrubs_Hat_f.p3d";
			female = "\DZ\characters\headgear\MedicalScrubs_Hat_m.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class MedicalScrubsHat_Blue: MedicalScrubsHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MedicalScrubs_Hat_blue_co.paa","\DZ\characters\headgear\data\MedicalScrubs_Hat_blue_co.paa","\DZ\characters\headgear\data\MedicalScrubs_Hat_blue_co.paa"};
	};
	class MedicalScrubsHat_White: MedicalScrubsHat_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MedicalScrubs_Hat_white_co.paa","\DZ\characters\headgear\data\MedicalScrubs_Hat_white_co.paa","\DZ\characters\headgear\data\MedicalScrubs_Hat_white_co.paa"};
	};
	class MedicalScrubsHat_Green: MedicalScrubsHat_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MedicalScrubs_Hat_green_co.paa","\DZ\characters\headgear\data\MedicalScrubs_Hat_green_co.paa","\DZ\characters\headgear\data\MedicalScrubs_Hat_green_co.paa"};
	};
	class GreatHelm: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_GreatHelm0";
		descriptionShort = "$STR_CfgVehicles_GreatHelm1";
		model = "\DZ\characters\headgear\greathelm_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		vehicleClass = "Clothing";
		simulation = "clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 2000;
		itemSize[] = {4,4};
		varWetMax = 0.249;
		heatIsolation = 0.3;
		noMask = 1;
		noEyewear = 1;
		headSelectionsToHide[] = {"Clipping_grathelm"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\greathelm_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 125;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\greathelm.rvmat"}},{0.7,{"DZ\characters\headgear\data\greathelm.rvmat"}},{0.5,{"DZ\characters\headgear\data\greathelm_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\greathelm_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\greathelm_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 1;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\greathelm.p3d";
			female = "\DZ\characters\headgear\greathelm.p3d";
		};
		class Protection
		{
			biological = 0.25;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpPot_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "GreatHelm_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "metalhelmet";
		soundVoicePriority = 10;
	};
	class Ssh68Helmet: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Ssh68Helmet0";
		descriptionShort = "$STR_CfgVehicles_Ssh68Helmet1";
		model = "\DZ\characters\headgear\Ssh68Helmet_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		vehicleClass = "Clothing";
		simulation = "clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		weight = 1500;
		itemSize[] = {4,3};
		varWetMax = 0.249;
		heatIsolation = 0.2;
		visibilityModifier = 0.7;
		noMask = 0;
		headSelectionsToHide[] = {"Clipping_Ssh68Helmet"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\SSH68Helmet_olive_co.paa","\DZ\characters\headgear\data\SSH68Helmet_olive_co.paa","\DZ\characters\headgear\data\SSH68Helmet_olive_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 85;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\SSH68Helmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\SSH68Helmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\SSH68Helmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\SSH68Helmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\SSH68Helmet_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\Ssh68Helmet.p3d";
			female = "\DZ\characters\headgear\Ssh68Helmet.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpPot_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "BallisticHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class DirtBikeHelmet_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_DirtBikeHelmet_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_DirtBikeHelmet_ColorBase1";
		model = "\DZ\characters\headgear\MxHelmet_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		vehicleClass = "Clothing";
		simulation = "clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 1600;
		itemSize[] = {4,3};
		varWetMax = 0.249;
		heatIsolation = 0.5;
		noMask = 0;
		noEyewear = 0;
		attachments[] = {"DBHelmetVisor","DBHelmetMouth"};
		headSelectionsToHide[] = {"Clipping_MxHelmet"};
		hiddenSelections[] = {"camoGround","camo"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 75;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\MxHelmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\MxHelmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\MxHelmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\MxHelmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\MxHelmet_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\MxHelmet.p3d";
			female = "\DZ\characters\headgear\MxHelmet.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class DirtBikeHelmet_Green: DirtBikeHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MxHelmet_green_co.paa","\DZ\characters\headgear\data\MxHelmet_green_co.paa"};
	};
	class DirtBikeHelmet_Chernarus: DirtBikeHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MxHelmet_chernarus_co.paa","\DZ\characters\headgear\data\MxHelmet_chernarus_co.paa"};
	};
	class DirtBikeHelmet_Khaki: DirtBikeHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MxHelmet_khaki_co.paa","\DZ\characters\headgear\data\MxHelmet_khaki_co.paa"};
	};
	class DirtBikeHelmet_Police: DirtBikeHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MxHelmet_police_co.paa","\DZ\characters\headgear\data\MxHelmet_police_co.paa"};
	};
	class DirtBikeHelmet_Red: DirtBikeHelmet_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MxHelmet_red_co.paa","\DZ\characters\headgear\data\MxHelmet_red_co.paa"};
	};
	class DirtBikeHelmet_Black: DirtBikeHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MxHelmet_black_co.paa","\DZ\characters\headgear\data\MxHelmet_black_co.paa"};
	};
	class DirtBikeHelmet_Blue: DirtBikeHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\MxHelmet_blue_co.paa","\DZ\characters\headgear\data\MxHelmet_blue_co.paa"};
	};
	class DirtBikeHelmet_Visor: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_DirtBikeHelmet_Visor0";
		descriptionShort = "$STR_CfgVehicles_DirtBikeHelmet_Visor1";
		model = "\dz\characters\headgear\MxHelmet_visor.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		rotationFlags = 34;
		itemSize[] = {3,1};
		inventorySlot[] = {"DBHelmetVisor"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\MxHelmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\MxHelmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\MxHelmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\MxHelmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\MxHelmet_destruct.rvmat"}}};
				};
			};
		};
	};
	class DirtBikeHelmet_Mouthguard: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_DirtBikeHelmet_Mouthguard0";
		descriptionShort = "$STR_CfgVehicles_DirtBikeHelmet_Mouthguard1";
		model = "\dz\characters\headgear\MxHelmet_mouthguard.p3d";
		rotationFlags = 34;
		itemSize[] = {3,1};
		inventorySlot[] = {"DBHelmetMouth"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\MxHelmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\MxHelmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\MxHelmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\MxHelmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\MxHelmet_destruct.rvmat"}}};
				};
			};
		};
	};
	class NBCHoodBase: Clothing
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_NBCHoodBase0";
		descriptionShort = "$STR_CfgVehicles_NBCHoodBase1";
		model = "\DZ\characters\headgear\NBC_Hood_g.p3d";
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 460;
		itemSize[] = {3,2};
		repairableWithKits[] = {5};
		repairCosts[] = {30.0};
		varWetMax = 0.249;
		heatIsolation = 0.4;
		headSelectionsToHide[] = {"Clipping_NBC_Hood"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 25;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\NBC_Hood.rvmat"}},{0.7,{"DZ\characters\headgear\data\NBC_Hood.rvmat"}},{0.5,{"DZ\characters\headgear\data\NBC_Hood_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\NBC_Hood_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\NBC_Hood_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\NBC_Hood_m.p3d";
			female = "\DZ\characters\headgear\NBC_Hood_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class NBCHoodGray: NBCHoodBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\headgear\data\NBC_Hood_grey_co.paa","\dz\characters\headgear\data\NBC_Hood_grey_co.paa","\dz\characters\headgear\data\NBC_Hood_grey_co.paa"};
	};
	class HockeyHelmet_ColorBase: Clothing
	{
		displayName = "$STR_cfgvehicles_hockeyhelmet0";
		descriptionShort = "$STR_cfgvehicles_hockeyhelmet1";
		model = "\DZ\characters\headgear\Hockey_helmet_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		weight = 610;
		itemSize[] = {4,3};
		varWetMax = 0.249;
		heatIsolation = 0.1;
		noMask = 0;
		noEyewear = 0;
		headSelectionsToHide[] = {"Clipping_Hockey_hekmet"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 55;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\Hockey_helmet.rvmat"}},{0.7,{"DZ\characters\headgear\data\Hockey_helmet.rvmat"}},{0.5,{"DZ\characters\headgear\data\Hockey_helmet_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\Hockey_helmet_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\Hockey_helmet_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.9;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\Hockey_helmet.p3d";
			female = "\DZ\characters\headgear\Hockey_helmet.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class HockeyHelmet_Black: HockeyHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\Hockey_helmet_black_CO.paa","\DZ\characters\headgear\data\Hockey_helmet_black_CO.paa","\DZ\characters\headgear\data\Hockey_helmet_black_CO.paa"};
	};
	class HockeyHelmet_Blue: HockeyHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\Hockey_helmet_blue_CO.paa","\DZ\characters\headgear\data\Hockey_helmet_blue_CO.paa","\DZ\characters\headgear\data\Hockey_helmet_blue_CO.paa"};
	};
	class HockeyHelmet_Red: HockeyHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\Hockey_helmet_red_CO.paa","\DZ\characters\headgear\data\Hockey_helmet_red_CO.paa","\DZ\characters\headgear\data\Hockey_helmet_red_CO.paa"};
	};
	class HockeyHelmet_White: HockeyHelmet_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\Hockey_helmet_white_CO.paa","\DZ\characters\headgear\data\Hockey_helmet_white_CO.paa","\DZ\characters\headgear\data\Hockey_helmet_white_CO.paa"};
	};
	class SantasHat: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SantasHat0";
		descriptionShort = "$STR_CfgVehicles_SantasHat1";
		model = "\DZ\characters\headgear\SantasHat_g.p3d";
		inventorySlot[] = {"Headgear"};
		vehicleClass = "Clothing";
		simulation = "clothing";
		itemInfo[] = {"Clothing","Headgear"};
		repairableWithKits[] = {2};
		repairCosts[] = {25.0};
		weight = 450;
		itemSize[] = {3,2};
		varWetMax = 0.049;
		heatIsolation = 1;
		visibilityModifier = 1;
		noMask = 0;
		headSelectionsToHide[] = {"Clipping_SantasHat"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\SantasHat_CO.paa","\DZ\characters\headgear\data\SantasHat_CO.paa","\DZ\characters\headgear\data\SantasHat_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\SantasHat.rvmat"}},{0.7,{"DZ\characters\headgear\data\SantasHat.rvmat"}},{0.5,{"DZ\characters\headgear\data\SantasHat_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\SantasHat_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\SantasHat_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\SantasHat_m.p3d";
			female = "\DZ\characters\headgear\SantasHat_f.p3d";
		};
	};
	class WitchHood_ColorBase: Clothing
	{
		displayName = "$STR_WitchHood0";
		descriptionShort = "$STR_WitchHood1";
		model = "\DZ\characters\headgear\WitchHood_g.p3d";
		inventorySlot[] = {"Headgear"};
		vehicleClass = "Clothing";
		simulation = "clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		repairableWithKits[] = {2};
		repairCosts[] = {25.0};
		weight = 250;
		itemSize[] = {2,2};
		varWetMax = 0.049;
		heatIsolation = 1;
		visibilityModifier = 1;
		noMask = 0;
		headSelectionsToHide[] = {"Clipping_WitchHood"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\WitchHood.rvmat"}},{0.7,{"DZ\characters\headgear\data\WitchHood.rvmat"}},{0.5,{"DZ\characters\headgear\data\WitchHood_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\WitchHood_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\WitchHood_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\WitchHood_m.p3d";
			female = "\DZ\characters\headgear\WitchHood_f.p3d";
		};
	};
	class WitchHood_Black: WitchHood_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\WitchHood_black_co.paa","\DZ\characters\headgear\data\WitchHood_black_co.paa","\DZ\characters\headgear\data\WitchHood_black_co.paa"};
	};
	class WitchHood_Brown: WitchHood_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\WitchHood_brown_co.paa","\DZ\characters\headgear\data\WitchHood_brown_co.paa","\DZ\characters\headgear\data\WitchHood_brown_co.paa"};
	};
	class WitchHood_Red: WitchHood_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\WitchHood_red_co.paa","\DZ\characters\headgear\data\WitchHood_red_co.paa","\DZ\characters\headgear\data\WitchHood_red_co.paa"};
	};
	class WitchHat: Clothing
	{
		scope = 2;
		displayName = "$STR_WitchHat0";
		descriptionShort = "$STR_WitchHat1";
		model = "\DZ\characters\headgear\WitchHat_g.p3d";
		inventorySlot[] = {"Headgear"};
		vehicleClass = "Clothing";
		simulation = "clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 16;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		weight = 450;
		itemSize[] = {3,2};
		varWetMax = 0.049;
		heatIsolation = 1;
		visibilityModifier = 1;
		noMask = 0;
		headSelectionsToHide[] = {"Clipping_WitchHat"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\WitchHat_co.paa","\DZ\characters\headgear\data\WitchHat_co.paa","\DZ\characters\headgear\data\WitchHat_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\WitchHat.rvmat"}},{0.7,{"DZ\characters\headgear\data\WitchHat.rvmat"}},{0.5,{"DZ\characters\headgear\data\WitchHat_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\WitchHat_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\WitchHat_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\WitchHat_m.p3d";
			female = "\DZ\characters\headgear\WitchHat_f.p3d";
		};
	};
	class Mich2001Helmet: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Mich2001Helmet0";
		descriptionShort = "$STR_CfgVehicles_Mich2001Helmet1";
		model = "\DZ\characters\headgear\Mich2001_g.p3d";
		repairableWithKits[] = {8};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Headgear"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		attachments[] = {"NVG","helmetFlashlight"};
		rotationFlags = 2;
		weight = 1200;
		itemSize[] = {4,3};
		noMask = 0;
		varWetMax = 0.249;
		heatIsolation = 0.25;
		visibilityModifier = 0.95;
		headSelectionsToHide[] = {"Clipping_Mich2001"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\headgear\data\mich2001_CO.paa","\DZ\characters\headgear\data\mich2001_CO.paa","\DZ\characters\headgear\data\mich2001_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\mich2001.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.7,{"DZ\characters\headgear\data\mich2001.rvmat","DZ\characters\headgear\data\mich2001_rail.rvmat"}},{0.5,{"DZ\characters\headgear\data\mich2001_damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\mich2001_damage.rvmat","DZ\characters\headgear\data\mich2001_rail_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\mich2001_destruct.rvmat","DZ\characters\headgear\data\mich2001_rail_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.26;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\Mich2001.p3d";
			female = "\DZ\characters\headgear\Mich2001.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpPot_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "BallisticHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyMxHelmet_visor: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"DBHelmetVisor"};
		model = "\dz\characters\headgear\MxHelmet_visor.p3d";
	};
	class ProxyMxHelmet_mouthguard: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"DBHelmetMouth"};
		model = "\dz\characters\headgear\MxHelmet_mouthguard.p3d";
	};
	class Proxyhelmet_flashlight: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"helmetFlashlight"};
		model = "\dz\characters\headgear\proxies\helmet_flashlight.p3d";
	};
};
