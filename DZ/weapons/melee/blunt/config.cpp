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
	class DZ_Weapons_Melee_Blunt
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Melee"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BaseballBat: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BaseballBat0";
		descriptionShort = "$STR_CfgVehicles_BaseballBat1";
		model = "\dz\weapons\melee\blunt\baseballbat.p3d";
		rotationFlags = 17;
		inventorySlot[] = {"Shoulder","Melee"};
		weight = 566;
		itemSize[] = {1,7};
		itemBehaviour = 2;
		fragility = 0.02;
		openItemSpillRange[] = {40,80};
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeBat";
				range = 1.5;
			};
			class Heavy
			{
				ammo = "MeleeBat_Heavy";
				range = 1.5;
			};
			class Sprint
			{
				ammo = "MeleeBat_Heavy";
				range = 4.1;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blunt\Data\BaseballBat.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View.rvmat"}},{0.7,{"DZ\weapons\melee\blunt\Data\BaseballBat.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View.rvmat"}},{0.5,{"DZ\weapons\melee\blunt\Data\BaseballBat_damage.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blunt\Data\BaseballBat_damage.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blunt\Data\BaseballBat_destruct.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUp_Light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "baseballbat_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class NailedBaseballBat: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_NailedBaseballBat0";
		descriptionShort = "$STR_CfgVehicles_NailedBaseballBat1";
		model = "\dz\weapons\melee\blunt\Baseballbat_nailed.p3d";
		rotationFlags = 17;
		inventorySlot[] = {"Shoulder","Melee"};
		weight = 600;
		itemSize[] = {1,7};
		itemBehaviour = 2;
		fragility = 0.02;
		openItemSpillRange[] = {40,70};
		isMeleeWeapon = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blunt\Data\BaseballBat.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View.rvmat"}},{0.7,{"DZ\weapons\melee\blunt\Data\BaseballBat.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View.rvmat"}},{0.5,{"DZ\weapons\melee\blunt\Data\BaseballBat_damage.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blunt\Data\BaseballBat_damage.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blunt\Data\BaseballBat_destruct.rvmat","DZ\weapons\melee\blunt\Data\BaseballBat_View_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeBatNails";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeBatNails_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeBatNails_Heavy";
				range = 2.8;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUp_Light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "baseballbat_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class PipeWrench: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PipeWrench0";
		descriptionShort = "$STR_CfgVehicles_PipeWrench1";
		model = "\dz\weapons\melee\blunt\pipewrench.p3d";
		rotationFlags = 12;
		inventorySlot[] = {"Shoulder","Melee"};
		weight = 4400;
		itemSize[] = {2,5};
		itemBehaviour = 1;
		fragility = 0.002;
		openItemSpillRange[] = {30,60};
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleePipeWrench";
				range = 1.5;
			};
			class Heavy
			{
				ammo = "MeleePipeWrench_Heavy";
				range = 1.5;
			};
			class Sprint
			{
				ammo = "MeleePipeWrench_Heavy";
				range = 4.1;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blunt\Data\pipewrench.rvmat","DZ\weapons\melee\blunt\Data\pipewrench_view.rvmat"}},{0.7,{"DZ\weapons\melee\blunt\Data\pipewrench.rvmat","DZ\weapons\melee\blunt\Data\pipewrench_view.rvmat"}},{0.5,{"DZ\weapons\melee\blunt\Data\pipewrench_damage.rvmat","DZ\weapons\melee\blunt\Data\pipewrench_view_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blunt\Data\pipewrench_damage.rvmat","DZ\weapons\melee\blunt\Data\pipewrench_view_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blunt\Data\pipewrench_destruct.rvmat","DZ\weapons\melee\blunt\Data\pipewrench_view_destruct.rvmat"}}};
				};
			};
		};
	};
	class BrassKnuckles_ColorBase: Inventory_Base
	{
		displayName = "$STR_CfgVehicles_BrassKnuckles_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_BrassKnuckles_ColorBase1";
		model = "\dz\weapons\melee\blunt\Brassknuckles.p3d";
		rotationFlags = 17;
		inventorySlot[] = {""};
		weight = 142;
		itemSize[] = {1,2};
		fragility = 0.002;
		hiddenSelections[] = {"camo"};
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeBrassKnuckles";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeBrassKnuckles_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeBrassKnuckles_Heavy";
				range = 2.8;
			};
		};
	};
	class BrassKnuckles_Dull: BrassKnuckles_ColorBase
	{
		scope = 2;
		hiddenSelectionsMaterials[] = {"dz\weapons\melee\blunt\data\Brassknuckles_dull.rvmat"};
		hiddenSelectionsTextures[] = {"dz\weapons\melee\blunt\data\BrassKnuckles_dull_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blunt\Data\brassknuckles_dull.rvmat"}},{0.7,{"DZ\weapons\melee\blunt\Data\brassknuckles_dull.rvmat"}},{0.5,{"DZ\weapons\melee\blunt\Data\brassknuckles_dull_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blunt\Data\brassknuckles_dull_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blunt\Data\brassknuckles_dull_destruct.rvmat"}}};
				};
			};
		};
	};
	class BrassKnuckles_Shiny: BrassKnuckles_ColorBase
	{
		scope = 2;
		weight = 162;
		hiddenSelectionsMaterials[] = {"dz\weapons\melee\blunt\Data\Brassknuckles_shiny.rvmat"};
		hiddenSelectionsTextures[] = {"dz\weapons\melee\blunt\data\BrassKnuckles_shiny_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blunt\Data\Brassknuckles_shiny.rvmat"}},{0.7,{"DZ\weapons\melee\blunt\Data\Brassknuckles_shiny.rvmat"}},{0.5,{"DZ\weapons\melee\blunt\Data\Brassknuckles_shiny_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blunt\Data\Brassknuckles_shiny_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blunt\Data\Brassknuckles_shiny_destruct.rvmat"}}};
				};
			};
		};
	};
	class TelescopicBaton: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TelescopicBaton0";
		descriptionShort = "$STR_CfgVehicles_TelescopicBaton1";
		model = "\dz\weapons\melee\blunt\TelescopingBaton.p3d";
		rotationFlags = 17;
		inventorySlot[] = {"Shoulder","Melee"};
		weight = 252;
		itemSize[] = {2,5};
		itemBehaviour = 1;
		fragility = 0.002;
		openItemSpillRange[] = {35,55};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blunt\Data\TelescopingBaton.rvmat"}},{0.7,{"DZ\weapons\melee\blunt\Data\TelescopingBaton.rvmat"}},{0.5,{"DZ\weapons\melee\blunt\Data\TelescopingBaton_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blunt\Data\TelescopingBaton_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blunt\Data\TelescopingBaton_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
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
			class Default_Opened
			{
				ammo = "MeleeBlunt";
				range = 1.6;
			};
			class Heavy_Opened
			{
				ammo = "MeleeBlunt_Heavy";
				range = 1.6;
			};
			class Sprint_Opened
			{
				ammo = "MeleeBlunt_Heavy";
				range = 4.1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class Baton_deploy
				{
					soundSet = "Baton_deploy_SoundSet";
					id = 201;
				};
				class Baton_retract
				{
					soundSet = "Baton_retract_SoundSet";
					id = 202;
				};
			};
		};
		class AnimationSources
		{
			class Doors1
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.001;
			};
		};
	};
	class HockeyStick: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HockeyStick0";
		descriptionShort = "$STR_CfgVehicles_HockeyStick1";
		model = "\dz\weapons\melee\blunt\hockey_stick_peters.p3d";
		rotationFlags = 12;
		inventorySlot[] = {"Shoulder","Melee"};
		weight = 650;
		itemSize[] = {2,10};
		itemBehaviour = 2;
		fragility = 0.02;
		openItemSpillRange[] = {40,80};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blunt\Data\Hockey_Stick.rvmat"}},{0.7,{"DZ\weapons\melee\blunt\Data\Hockey_Stick.rvmat"}},{0.5,{"DZ\weapons\melee\blunt\Data\Hockey_Stick_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blunt\Data\Hockey_Stick_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blunt\Data\Hockey_Stick_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeWoodBlunt";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeWoodBlunt_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeWoodBlunt_Heavy";
				range = 3.7;
			};
		};
	};
	class NewHockeyStick: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_NewHockeyStick0";
		descriptionShort = "$STR_CfgVehicles_NewHockeyStick1";
		model = "\dz\weapons\melee\blunt\hockey_stick_peters.p3d";
		rotationFlags = 12;
		inventorySlot[] = {"Shoulder","Melee"};
		weight = 650;
		itemSize[] = {2,10};
		itemBehaviour = 2;
		fragility = 0.02;
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeBat";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeBat_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeBat_Heavy";
				range = 3.7;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blunt\Data\Hockey_Stick.rvmat"}},{0.7,{"DZ\weapons\melee\blunt\Data\Hockey_Stick.rvmat"}},{0.5,{"DZ\weapons\melee\blunt\Data\Hockey_Stick_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blunt\Data\Hockey_Stick_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blunt\Data\Hockey_Stick_destruct.rvmat"}}};
				};
			};
		};
	};
	class PoliceBaton: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PoliceBaton0";
		descriptionShort = "$STR_CfgVehicles_PoliceBaton1";
		model = "\dz\weapons\melee\blunt\Police_baton.p3d";
		rotationFlags = 16;
		inventorySlot[] = {"Shoulder","Melee"};
		weight = 540;
		itemSize[] = {2,5};
		itemBehaviour = 1;
		fragility = 0.002;
		openItemSpillRange[] = {35,55};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blunt\Data\baton.rvmat"}},{0.7,{"DZ\weapons\melee\blunt\Data\baton.rvmat"}},{0.5,{"DZ\weapons\melee\blunt\Data\baton_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blunt\Data\baton_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blunt\Data\baton_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeBlunt";
				range = 1.6;
			};
			class Heavy
			{
				ammo = "MeleeBlunt_Heavy";
				range = 1.6;
			};
			class Sprint
			{
				ammo = "MeleeBlunt_Heavy";
				range = 4.1;
			};
		};
	};
};
