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
	class DZ_Weapons_Ammunition
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Magazines"};
	};
};
class CfgMagazines
{
	class Magazine_Base;
	class Ammunition_Base: Magazine_Base
	{
		rotationFlags = 2;
		itemSize[] = {1,1};
		iconCartridge = 0;
		iconType = 0;
		ammo = "";
		spawnDamageRange[] = {0.0,0.6};
		destroyOnEmpty = 1;
		varQuantityDestroyOnMin = 1;
		canBeSplit = 1;
		simpleHeap = 1;
		soundUse = "craft_rounds";
		emptySound = "craft_rounds";
	};
	class Ammo_45ACP: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_45ACP0";
		descriptionShort = "$STR_CfgMagazines_Ammo_45ACP1";
		model = "\dz\weapons\ammunition\45acp_LooseRounds.p3d";
		iconCartridge = 1;
		weight = 12;
		count = 25;
		ammo = "Bullet_45ACP";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\45cal_loose.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\45cal_loose.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\45cal_loose_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\45cal_loose_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\45cal_loose_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_308Win: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_308Win0";
		descriptionShort = "$STR_CfgMagazines_Ammo_308Win1";
		model = "\dz\weapons\ammunition\308Win_LooseRounds.p3d";
		iconCartridge = 3;
		weight = 10;
		count = 20;
		ammo = "Bullet_308Win";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\308_loose.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\308_loose.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\308_loose_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\308_loose_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\308_loose_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_308WinTracer: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_308WinTracer0";
		descriptionShort = "$STR_CfgMagazines_Ammo_308WinTracer1";
		model = "\dz\weapons\ammunition\308Win_LooseRounds.p3d";
		iconCartridge = 3;
		iconType = 1;
		weight = 10;
		count = 20;
		ammo = "Bullet_308WinTracer";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\Data\308_loose_tracer_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\308_loose.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\308_loose.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\308_loose_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\308_loose_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\308_loose_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_9x19: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_9x190";
		descriptionShort = "$STR_CfgMagazines_Ammo_9x191";
		model = "\dz\weapons\ammunition\9mm_LooseRounds.p3d";
		iconCartridge = 1;
		weight = 6;
		count = 25;
		ammo = "Bullet_9x19";
		muzzleFlashParticle = "weapon_shot_mp5k_01";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\9mm.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\9mm.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\9mm_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\9mm_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\9mm_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_380: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_3800";
		descriptionShort = "$STR_CfgMagazines_Ammo_3801";
		model = "\dz\weapons\ammunition\380auto_LooseRounds.p3d";
		iconCartridge = 1;
		weight = 6;
		count = 35;
		ammo = "Bullet_380";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\9mm.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\9mm.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\9mm_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\9mm_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\9mm_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_556x45: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_556x450";
		descriptionShort = "$STR_CfgMagazines_Ammo_556x451";
		model = "\dz\weapons\ammunition\556_LooseRounds.p3d";
		iconCartridge = 2;
		weight = 4;
		count = 20;
		ammo = "Bullet_556x45";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\556_LooseRounds5.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\556_LooseRounds5.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\556_LooseRounds5_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\556_LooseRounds5_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\556_LooseRounds5_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_556x45Tracer: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_556x45Tracer0";
		descriptionShort = "$STR_CfgMagazines_Ammo_556x45Tracer1";
		model = "\dz\weapons\ammunition\556_LooseRounds.p3d";
		iconCartridge = 2;
		iconType = 1;
		weight = 4;
		count = 20;
		ammo = "Bullet_556x45Tracer";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\Data\556_loose_tracer_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\556_LooseRounds5.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\556_LooseRounds5.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\556_LooseRounds5_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\556_LooseRounds5_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\556_LooseRounds5_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_762x54: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_762x540";
		descriptionShort = "$STR_CfgMagazines_Ammo_762x541";
		model = "\dz\weapons\ammunition\762_LooseRounds.p3d";
		iconCartridge = 3;
		weight = 9;
		count = 20;
		ammo = "Bullet_762x54";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\mosinclip.rvmat"}},{0.7,{"DZ\weapons\attachments\data\mosinclip.rvmat"}},{0.5,{"DZ\weapons\attachments\data\mosinclip_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\mosinclip_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\mosinclip_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_762x54Tracer: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_762x54Tracer0";
		descriptionShort = "$STR_CfgMagazines_Ammo_762x54Tracer1";
		model = "\dz\weapons\ammunition\762_LooseRounds.p3d";
		iconCartridge = 3;
		iconType = 1;
		weight = 9;
		count = 20;
		ammo = "Bullet_762x54Tracer";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\mosinclip_tracer_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\mosinclip.rvmat"}},{0.7,{"DZ\weapons\attachments\data\mosinclip.rvmat"}},{0.5,{"DZ\weapons\attachments\data\mosinclip_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\mosinclip_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\mosinclip_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_762x39: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_762x390";
		descriptionShort = "$STR_CfgMagazines_Ammo_762x391";
		model = "\dz\weapons\ammunition\762x39_LooseRounds.p3d";
		iconCartridge = 2;
		weight = 8;
		count = 20;
		ammo = "Bullet_762x39";
		muzzleFlashParticle = "weapon_shot_izh18_01";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762x39.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762x39.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762x39_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762x39_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762x39_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_762x39Tracer: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_762x39Tracer0";
		descriptionShort = "$STR_CfgMagazines_Ammo_762x39Tracer1";
		model = "\dz\weapons\ammunition\762x39_LooseRounds.p3d";
		iconCartridge = 2;
		iconType = 1;
		weight = 8;
		count = 20;
		ammo = "Bullet_762x39Tracer";
		muzzleFlashParticle = "weapon_shot_izh18_01";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\data\762x39_tracer_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762x39.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762x39.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762x39_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762x39_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762x39_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_9x39AP: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_cfgmagazines_ammo_9x39AP0";
		descriptionShort = "$STR_cfgmagazines_ammo_9x39AP1";
		model = "\dz\weapons\ammunition\9x39_LooseRounds.p3d";
		iconCartridge = 2;
		iconType = 2;
		weight = 10;
		count = 20;
		ammo = "Bullet_9x39AP";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\vss_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\vss_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\vss_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\vss_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\vss_mag_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_9x39: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_9x390";
		descriptionShort = "$STR_CfgMagazines_Ammo_9x391";
		model = "\dz\weapons\ammunition\9x39_LooseRounds.p3d";
		iconCartridge = 2;
		weight = 10;
		count = 20;
		ammo = "Bullet_9x39";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\magazine\data\vss_mag_variant_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\attachments\magazine\data\vss_mag_variant.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"dz\weapons\attachments\magazine\data\vss_mag.rvmat"}},{0.7,{"dz\weapons\attachments\magazine\data\vss_mag_variant.rvmat"}},{0.5,{"dz\weapons\attachments\magazine\data\vss_mag_variant_damage.rvmat"}},{0.3,{"dz\weapons\attachments\magazine\data\vss_mag_variant_damage.rvmat"}},{0.0,{"dz\weapons\attachments\magazine\data\vss_mag_variant_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_22: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_220";
		descriptionShort = "$STR_CfgMagazines_Ammo_221";
		model = "\dz\weapons\ammunition\22_LooseRounds.p3d";
		iconCartridge = 1;
		weight = 2;
		count = 50;
		ammo = "Bullet_22";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\22lr.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\22lr.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\22lr_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\22lr_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\22lr_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_12gaPellets: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_12gaPellets0";
		descriptionShort = "$STR_CfgMagazines_Ammo_12gaPellets1";
		model = "\dz\weapons\ammunition\12ga_00buck.p3d";
		iconCartridge = 4;
		weight = 28;
		count = 10;
		ammo = "Bullet_12GaugePellets";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\rem870_ammo.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\rem870_ammo.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\rem870_ammo_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\rem870_ammo_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\rem870_ammo_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_12gaSlug: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_12gaSlug0";
		descriptionShort = "$STR_CfgMagazines_Ammo_12gaSlug1";
		model = "\dz\weapons\ammunition\12ga_rifled_slug.p3d";
		iconCartridge = 4;
		weight = 28;
		count = 10;
		ammo = "Bullet_12GaugeSlug";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\rem870_ammo.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\rem870_ammo.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\rem870_ammo_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\rem870_ammo_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\rem870_ammo_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_12gaRubberSlug: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_12gaRubberSlug0";
		descriptionShort = "$STR_CfgMagazines_Ammo_12gaRubberSlug1";
		model = "\dz\weapons\ammunition\12ga_RubberRifled_slug.p3d";
		iconCartridge = 4;
		weight = 6;
		count = 10;
		ammo = "Bullet_12GaugeRubberSlug";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\rem870_ammo.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\rem870_ammo.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\rem870_ammo_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\rem870_ammo_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\rem870_ammo_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_12gaBeanbag: Ammunition_Base
	{
		scope = 2;
		displayName = "TODO";
		descriptionShort = "TODO";
		model = "\dz\weapons\ammunition\12ga_beanbag.p3d";
		iconCartridge = 4;
		weight = 6;
		count = 10;
		ammo = "Bullet_12GaugeBeanbag";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\rem870_ammo.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\rem870_ammo.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\rem870_ammo_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\rem870_ammo_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\rem870_ammo_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_357: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_3570";
		descriptionShort = "$STR_CfgMagazines_Ammo_3571";
		model = "\dz\weapons\ammunition\357_looseRounds.p3d";
		iconCartridge = 1;
		weight = 8;
		count = 20;
		ammo = "Bullet_357";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\357mag_loose.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\357mag_loose.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\357mag_loose_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\357mag_loose_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\357mag_loose_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_545x39: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_545x390";
		descriptionShort = "$STR_CfgMagazines_Ammo_545x391";
		model = "\dz\weapons\ammunition\545x39_LooseRounds.p3d";
		iconCartridge = 2;
		weight = 4;
		count = 20;
		ammo = "Bullet_545x39";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\545x39.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\545x39.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\545x39_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\545x39_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\545x39_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_545x39Tracer: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_545x39Tracer0";
		descriptionShort = "$STR_CfgMagazines_Ammo_545x39Tracer1";
		model = "\dz\weapons\ammunition\545x39_LooseRounds.p3d";
		iconCartridge = 2;
		iconType = 1;
		weight = 4;
		count = 20;
		ammo = "Bullet_545x39Tracer";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\data\545x39_tracer_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\545x39.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\545x39.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\545x39_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\545x39_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\545x39_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_ArrowComposite: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_ArrowComposite0";
		descriptionShort = "$STR_CfgMagazines_Ammo_ArrowComposite1";
		model = "\dz\weapons\projectiles\arrow_composite.p3d";
		rotationFlags = 34;
		weight = 24;
		itemSize[] = {2,1};
		count = 5;
		ammo = "Arrow_Composite";
		emptySound = "empty_arrows";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\projectiles\data\arrow_composite.rvmat"}},{0.7,{"DZ\weapons\projectiles\data\arrow_composite.rvmat"}},{0.5,{"DZ\weapons\projectiles\data\arrow_composite_damage.rvmat"}},{0.3,{"DZ\weapons\projectiles\data\arrow_composite_damage.rvmat"}},{0.0,{"DZ\weapons\projectiles\data\arrow_composite_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_SharpStick: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_SharpStick0";
		descriptionShort = "$STR_CfgMagazines_Ammo_SharpStick1";
		model = "\dz\weapons\projectiles\arrow_crude_simple.p3d";
		rotationFlags = 34;
		inventorySlot[] = {"Firewood"};
		weight = 40;
		itemSize[] = {2,1};
		count = 5;
		ammo = "Arrow_Crude";
		emptySound = "empty_arrows";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\projectiles\data\arrow_composite.rvmat"}},{0.7,{"DZ\weapons\projectiles\data\arrow_composite.rvmat"}},{0.5,{"DZ\weapons\projectiles\data\arrow_composite_damage.rvmat"}},{0.3,{"DZ\weapons\projectiles\data\arrow_composite_damage.rvmat"}},{0.0,{"DZ\weapons\projectiles\data\arrow_composite_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeStab";
				range = 1.3;
			};
			class Heavy
			{
				ammo = "MeleeStab_Heavy";
				range = 1.3;
			};
			class Sprint
			{
				ammo = "MeleeStab_Heavy";
				range = 3.3;
			};
		};
	};
	class Ammo_ArrowPrimitive: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_ArrowPrimitive0";
		descriptionShort = "$STR_CfgMagazines_Ammo_ArrowPrimitive1";
		model = "\dz\weapons\projectiles\arrow_crafted_simple.p3d";
		rotationFlags = 34;
		weight = 50;
		itemSize[] = {2,1};
		count = 5;
		ammo = "Arrow_Primitive";
		emptySound = "empty_arrows";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\projectiles\data\arrow_composite.rvmat"}},{0.7,{"DZ\weapons\projectiles\data\arrow_composite.rvmat"}},{0.5,{"DZ\weapons\projectiles\data\arrow_composite_damage.rvmat"}},{0.3,{"DZ\weapons\projectiles\data\arrow_composite_damage.rvmat"}},{0.0,{"DZ\weapons\projectiles\data\arrow_composite_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_ArrowBoned: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_ArrowBoned0";
		descriptionShort = "$STR_CfgMagazines_Ammo_ArrowBoned1";
		model = "\dz\weapons\projectiles\arrow_crafted_advanced.p3d";
		rotationFlags = 34;
		weight = 40;
		itemSize[] = {2,1};
		count = 5;
		ammo = "Arrow_Boned";
		emptySound = "empty_arrows";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\projectiles\data\advanced_arrow.rvmat"}},{0.7,{"DZ\weapons\projectiles\data\advanced_arrow.rvmat"}},{0.5,{"DZ\weapons\projectiles\data\advanced_arrow_damage.rvmat"}},{0.3,{"DZ\weapons\projectiles\data\advanced_arrow_damage.rvmat"}},{0.0,{"DZ\weapons\projectiles\data\advanced_arrow_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_ArrowBolt: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_ArrowBolt0";
		descriptionShort = "$STR_CfgMagazines_Ammo_ArrowBolt1";
		model = "\dz\weapons\projectiles\arrow_hunting.p3d";
		rotationFlags = 34;
		weight = 22;
		count = 5;
		ammo = "Arrow_Bolt";
		emptySound = "empty_arrows";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\projectiles\data\arrows.rvmat"}},{0.7,{"DZ\weapons\projectiles\data\arrows.rvmat"}},{0.5,{"DZ\weapons\projectiles\data\arrows_damage.rvmat"}},{0.3,{"DZ\weapons\projectiles\data\arrows_damage.rvmat"}},{0.0,{"DZ\weapons\projectiles\data\arrows_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_DartSyringe: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_DartSyringe0";
		descriptionShort = "$STR_CfgMagazines_Ammo_DartSyringe1";
		model = "\dz\weapons\projectiles\dart_syringe.p3d";
		rotationFlags = 34;
		weight = 24;
		count = 5;
		ammo = "Dart_Syringe";
		emptySound = "empty_arrows";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\projectiles\data\arrows.rvmat"}},{0.7,{"DZ\weapons\projectiles\data\arrows.rvmat"}},{0.5,{"DZ\weapons\projectiles\data\arrows_damage.rvmat"}},{0.3,{"DZ\weapons\projectiles\data\arrows_damage.rvmat"}},{0.0,{"DZ\weapons\projectiles\data\arrows_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_Flare: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Ammo_Flare0";
		descriptionShort = "$STR_CfgMagazines_Ammo_Flare1";
		model = "\dz\weapons\ammunition\Flare_SingleRound.p3d";
		rotationFlags = 34;
		weight = 80;
		count = 5;
		ammo = "Bullet_Flare";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\flaregun\data\flaregun.rvmat"}},{0.7,{"DZ\weapons\pistols\flaregun\data\flaregun.rvmat"}},{0.5,{"DZ\weapons\pistols\flaregun\data\flaregun_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\flaregun\data\flaregun_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\flaregun\data\flaregun_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_RPG7_HE: Ammunition_Base
	{
		scope = 2;
		itemSize[] = {2,1};
		displayName = "$STR_CfgMagazines_Ammo_RPG7_HE0";
		descriptionShort = "$STR_CfgMagazines_Ammo_RPG7_HE1";
		model = "\dz\weapons\ammunition\rocket_rpg7.p3d";
		rotationFlags = 34;
		weight = 2200;
		count = 1;
		ammo = "Rocket_RPG7_HE";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\rocket_rpg7.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\rocket_rpg7.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\rocket_rpg7_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\rocket_rpg7_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\rocket_rpg7_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_RPG7_AP: Ammunition_Base
	{
		scope = 2;
		itemSize[] = {2,1};
		displayName = "$STR_CfgMagazines_Ammo_RPG7_AP0";
		descriptionShort = "$STR_CfgMagazines_Ammo_RPG7_AP1";
		model = "\dz\weapons\ammunition\rocket_rpg7.p3d";
		rotationFlags = 34;
		weight = 2200;
		count = 1;
		ammo = "Rocket_RPG7_AP";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\rocket_rpg7.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\rocket_rpg7.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\rocket_rpg7_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\rocket_rpg7_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\rocket_rpg7_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_LAW_HE: Ammunition_Base
	{
		scope = 2;
		itemSize[] = {2,1};
		displayName = "$STR_CfgMagazines_Ammo_LAW_HE0";
		descriptionShort = "$STR_CfgMagazines_Ammo_LAW_HE1";
		model = "\dz\weapons\launchers\law\law_rocket.p3d";
		rotationFlags = 34;
		weight = 1800;
		count = 1;
		ammo = "Rocket_LAW_HE";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\launchers\law\data\law_rocket.rvmat"}},{0.7,{"DZ\weapons\launchers\law\data\law_rocket.rvmat"}},{0.5,{"DZ\weapons\launchers\law\data\law_rocket_damage.rvmat"}},{0.3,{"DZ\weapons\launchers\law\data\law_rocket_damage.rvmat"}},{0.0,{"DZ\weapons\launchers\law\data\law_rocket_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ammo_GrenadeM4: Ammunition_Base
	{
		scope = 2;
		itemSize[] = {2,1};
		displayName = "$STR_CfgMagazines_Ammo_GrenadeM40";
		descriptionShort = "$STR_CfgMagazines_Ammo_GrenadeM41";
		model = "\dz\weapons\explosives\grenade.p3d";
		weight = 397;
		count = 1;
		ammo = "GrenadeM4";
		fuseDelay = 5;
		timeToLive = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\explosives\data\grenade_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\explosives\data\grenade.rvmat"};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\explosives\data\grenade.rvmat","DZ\weapons\explosives\data\grenade_damage.rvmat","DZ\weapons\explosives\data\grenade_destruct.rvmat"};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\explosives\data\grenade.rvmat"}},{0.7,{"DZ\weapons\explosives\data\grenade.rvmat"}},{0.5,{"DZ\weapons\explosives\data\grenade_damage.rvmat"}},{0.3,{"DZ\weapons\explosives\data\grenade_damage.rvmat"}},{0.0,{"DZ\weapons\explosives\data\grenade_destruct.rvmat"}}};
				};
			};
		};
	};
};
class CfgVehicles
{
	class Box_Base;
	class AmmoBox_556x45_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_556x45_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_556x45_20Rnd1";
		model = "\dz\weapons\ammunition\556_20RoundBox.p3d";
		rotationFlags = 17;
		weight = 85;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\556_20RoundBox.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\556_20RoundBox.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\556_20RoundBox_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\556_20RoundBox_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\556_20RoundBox_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_556x45
			{
				value = 20;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_556x45Tracer_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_556x45Tracer_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_556x45Tracer_20Rnd1";
		model = "\dz\weapons\ammunition\556_20RoundBox.p3d";
		iconType = 1;
		rotationFlags = 17;
		weight = 85;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\556_20RoundBox.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\556_20RoundBox.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\556_20RoundBox_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\556_20RoundBox_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\556_20RoundBox_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_556x45Tracer
			{
				value = 20;
				variable = "quantity";
			};
		};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\data\556_20RoundBox_tracer_CO.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_308Win_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_308Win_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_308Win_20Rnd1";
		model = "\dz\weapons\ammunition\308Win_20RoundBox.p3d";
		rotationFlags = 17;
		weight = 195;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_308Win
			{
				value = 20;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_308WinTracer_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_308WinTracer_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_308WinTracer_20Rnd1";
		model = "\dz\weapons\ammunition\308Win_20RoundBox.p3d";
		iconType = 1;
		rotationFlags = 17;
		weight = 195;
		class Resources
		{
			class Ammo_308WinTracer
			{
				value = 20;
				variable = "quantity";
			};
		};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\data\308Win_box_tracer_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762_box_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_762x54_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_762x54_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_762x54_20Rnd1";
		model = "\dz\weapons\ammunition\762_20RoundBox.p3d";
		rotationFlags = 17;
		weight = 185;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_762x54
			{
				value = 20;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_762x54Tracer_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_762x54Tracer_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_762x54Tracer_20Rnd1";
		model = "\dz\weapons\ammunition\762_20RoundBox.p3d";
		iconType = 1;
		rotationFlags = 17;
		weight = 185;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_762x54Tracer
			{
				value = 20;
				variable = "quantity";
			};
		};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\data\762_box_tracer_co.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_762x39_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_762x39_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_762x39_20Rnd1";
		model = "\dz\weapons\ammunition\762x39_20RoundBox.p3d";
		rotationFlags = 17;
		weight = 165;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762x39_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762x39_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762x39_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762x39_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762x39_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_762x39
			{
				value = 20;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_762x39Tracer_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_762x39Tracer_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_762x39Tracer_20Rnd1";
		model = "\dz\weapons\ammunition\762x39_20RoundBox.p3d";
		iconType = 1;
		rotationFlags = 17;
		weight = 165;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762x39_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762x39_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762x39_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762x39_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762x39_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_762x39Tracer
			{
				value = 20;
				variable = "quantity";
			};
		};
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\data\762x39_box_tracer_co.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_22_50Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_22_50Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_22_50Rnd1";
		model = "\dz\weapons\ammunition\22_50RoundBox.p3d";
		rotationFlags = 12;
		weight = 45;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\22LR_50RoundBox.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\22LR_50RoundBox.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\22LR_50RoundBox_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\22LR_50RoundBox_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\22LR_50RoundBox_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_22
			{
				value = 50;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_357_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_357_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_357_20Rnd1";
		model = "\dz\weapons\ammunition\357_20RoundBox.p3d";
		rotationFlags = 17;
		weight = 165;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\357box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\357box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\357box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\357box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\357box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_357
			{
				value = 20;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_45ACP_25rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_45ACP_25rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_45ACP_25rnd1";
		model = "\dz\weapons\ammunition\45acp_25rnd_box.p3d";
		rotationFlags = 17;
		weight = 305;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\45cal_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\45cal_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\45cal_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\45cal_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\45cal_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_45ACP
			{
				value = 25;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_9x19_25rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_9x19_25rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_9x19_25rnd1";
		model = "\dz\weapons\ammunition\9mm_25rnd_box.p3d";
		rotationFlags = 17;
		weight = 155;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\9mm_25roundbox.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\9mm_25roundbox.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\9mm_25roundbox_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\9mm_25roundbox_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\9mm_25roundbox_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_9x19
			{
				value = 25;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_380_35rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_380_35rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_380_35rnd1";
		model = "\dz\weapons\ammunition\380auto_35RoundBox.p3d";
		rotationFlags = 17;
		weight = 155;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\45cal_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\45cal_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\45cal_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\45cal_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\45cal_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_380
			{
				value = 35;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_00buck_10rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_00buck_10rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_00buck_10rnd1";
		model = "\dz\weapons\ammunition\00Buck_10RoundBox.p3d";
		rotationFlags = 17;
		weight = 285;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\00buck_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\00buck_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\00buck_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\00buck_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\00buck_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_12gaPellets
			{
				value = 10;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_12gaSlug_10Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_12gaSlug_10Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_12gaSlug_10Rnd1";
		model = "\dz\weapons\ammunition\00Buck_10RoundBox.p3d";
		rotationFlags = 17;
		weight = 285;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\data\12ga_rifledSlug_10RoundBox_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\00buck_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\00buck_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\00buck_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\00buck_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\00buck_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_12gaSlug
			{
				value = 10;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_12gaRubberSlug_10Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_12gaRubberSlug_10Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_12gaRubberSlug_10Rnd1";
		model = "\dz\weapons\ammunition\00Buck_10RoundBox.p3d";
		rotationFlags = 17;
		weight = 285;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\data\12ga_rubberbaton_box.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\00buck_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\00buck_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\00buck_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\00buck_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\00buck_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_12gaRubberSlug
			{
				value = 10;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_12gaBeanbag_10Rnd: Box_Base
	{
		scope = 2;
		displayName = "TODO";
		descriptionShort = "TODO";
		model = "\dz\weapons\ammunition\00Buck_10RoundBox.p3d";
		rotationFlags = 17;
		weight = 285;
		Selections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,CO)"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\00buck_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\00buck_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\00buck_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\00buck_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\00buck_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_12gaBeanbag
			{
				value = 10;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_545x39_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_545x39_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_545x39_20Rnd1";
		model = "\dz\weapons\ammunition\545x39_20RoundBox.p3d";
		rotationFlags = 17;
		weight = 85;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\545x39box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\545x39box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\545x39box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\545x39box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\545x39box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_545x39
			{
				value = 20;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_545x39Tracer_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_545x39Tracer_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_545x39Tracer_20Rnd1";
		model = "\dz\weapons\ammunition\545x39_20RoundBox.p3d";
		iconType = 1;
		rotationFlags = 17;
		weight = 85;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\data\545x39box_tracer_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\545x39box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\545x39box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\545x39box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\545x39box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\545x39box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_545x39Tracer
			{
				value = 20;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_9x39AP_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_9x39AP_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_9x39AP_20Rnd1";
		model = "\dz\weapons\ammunition\9x39_20RoundBox.p3d";
		iconType = 2;
		rotationFlags = 17;
		weight = 200;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762x39_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762x39_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762x39_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762x39_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762x39_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_9x39AP
			{
				value = 10;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
	class AmmoBox_9x39_20Rnd: Box_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AmmoBox_9x39_20Rnd0";
		descriptionShort = "$STR_CfgVehicles_AmmoBox_9x39_20Rnd1";
		model = "\dz\weapons\ammunition\9x39_20RoundBox.p3d";
		rotationFlags = 17;
		weight = 200;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"dz\weapons\ammunition\data\9x39_box_variant_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\762x39_box.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\762x39_box.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\762x39_box_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\762x39_box_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\762x39_box_destruct.rvmat"}}};
				};
			};
		};
		class Resources
		{
			class Ammo_9x39
			{
				value = 10;
				variable = "quantity";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset = "ammoboxUnpack_SoundSet";
					id = 70;
				};
			};
		};
	};
};
