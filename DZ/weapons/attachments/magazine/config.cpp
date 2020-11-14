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
	class DZ_Weapons_Magazines
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMagazines
{
	class DefaultMagazine;
	class Magazine_Base: DefaultMagazine
	{
		scope = 0;
		storageCategory = 1;
		inventorySlot[] = {"magazine","magazine2","magazine3"};
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		handheld = "true";
		armAction = "Disarm";
		isMeleeWeapon = 1;
		rotationFlags = 17;
		quantityBar = 0;
		itemSize[] = {1,2};
		absorbency = 0.0;
		recoilModifier[] = {0.95,0.95,0.95};
		value = 1;
		modelSpecial = "";
		spawnDamageRange[] = {0.0,0.6};
		enlargeInventoryView = 0;
		useAction = 0;
		useActionTitle = "";
		reloadAction = "";
		manipulationDamage = 0.05;
		count = 30;
		ammo = "";
		ammoItems[] = {};
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 1;
		selectionFireAnim = "zasleh";
		nameSound = "magazine";
		soundUse = "craft_rounds";
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
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeFist";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeFist_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeFist_Heavy";
				range = 2.8;
			};
		};
		class Reliability
		{
			ChanceToJam[] = {0,0.0025,0.015,0.1,1};
		};
	};
	class Mag_FNX45_15Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_FNX45_15Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_FNX45_15Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_fnp45.p3d";
		weight = 113;
		itemSize[] = {1,2};
		count = 15;
		ammo = "Bullet_45ACP";
		ammoItems[] = {"Ammo_45ACP"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\fnx45\data\herstal45.rvmat"}},{0.7,{"DZ\weapons\pistols\fnx45\data\herstal45.rvmat"}},{0.5,{"DZ\weapons\pistols\fnx45\data\herstal45_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\fnx45\data\herstal45_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\fnx45\data\herstal45_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_357Speedloader_6Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_357Speedloader_6Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_357Speedloader_6Rnd1";
		model = "\dz\weapons\attachments\magazine\357_SpeedLoader.p3d";
		weight = 25;
		itemSize[] = {1,1};
		count = 6;
		ammo = "Bullet_357";
		ammoItems[] = {"Ammo_357"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\ammunition\data\speedloader.rvmat"}},{0.7,{"DZ\weapons\ammunition\data\speedloader.rvmat"}},{0.5,{"DZ\weapons\ammunition\data\speedloader_damage.rvmat"}},{0.3,{"DZ\weapons\ammunition\data\speedloader_damage.rvmat"}},{0.0,{"DZ\weapons\ammunition\data\speedloader_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Deagle_9rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Deagle_9rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_Deagle_9rnd1";
		model = "\dz\weapons\attachments\magazine\magazine_DE.p3d";
		weight = 70;
		itemSize[] = {1,2};
		ammo = "Bullet_357";
		ammoItems[] = {"Ammo_357"};
		count = 9;
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"dz\weapons\attachments\magazine\data\deagle_mag.rvmat"}},{0.7,{"dz\weapons\attachments\magazine\data\deagle_mag.rvmat"}},{0.5,{"dz\weapons\attachments\magazine\data\deagle_mag_damage.rvmat"}},{0.3,{"dz\weapons\attachments\magazine\data\deagle_mag_damage.rvmat"}},{0.0,{"dz\weapons\attachments\magazine\data\deagle_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_1911_7Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_1911_7Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_1911_7Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_1911.p3d";
		weight = 68;
		itemSize[] = {1,2};
		count = 7;
		ammo = "Bullet_45ACP";
		ammoItems[] = {"Ammo_45ACP"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\1911.rvmat"}},{0.7,{"DZ\weapons\attachments\data\1911.rvmat"}},{0.5,{"DZ\weapons\attachments\data\1911_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\1911_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\1911_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_CZ75_15Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_CZ75_15Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_CZ75_15Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_CZ75.p3d";
		weight = 131;
		itemSize[] = {1,2};
		count = 15;
		ammo = "Bullet_9x19";
		ammoItems[] = {"Ammo_9x19"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\cz75_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\data\cz75_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\data\cz75_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\cz75_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\cz75_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Glock_15Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Glock_15Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_Glock_15Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_glock19.p3d";
		weight = 131;
		itemSize[] = {1,2};
		count = 15;
		ammo = "Bullet_9x19";
		ammoItems[] = {"Ammo_9x19"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\glock19_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\glock19_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\glock19_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\glock19_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\glock19_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_P1_8Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_P1_8Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_P1_8Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_p1.p3d";
		weight = 227;
		itemSize[] = {1,2};
		count = 8;
		ammo = "Bullet_9x19";
		ammoItems[] = {"Ammo_9x19"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\p38_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\data\p38_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\data\p38_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\p38_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\p38_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_IJ70_8Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_IJ70_12Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_IJ70_12Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_ij70.p3d";
		weight = 131;
		itemSize[] = {1,2};
		count = 12;
		ammo = "Bullet_380";
		ammoItems[] = {"Ammo_380"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\pmm\data\pmm.rvmat"}},{0.7,{"DZ\weapons\pistols\pmm\data\pmm.rvmat"}},{0.5,{"DZ\weapons\pistols\pmm\data\pmm_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\pmm\data\pmm_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\pmm\data\pmm_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_MP5_15Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_MP5_15Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_MP5_15Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_mp5_15rnd.p3d";
		weight = 120;
		itemSize[] = {1,2};
		count = 15;
		ammo = "Bullet_9x19";
		ammoItems[] = {"Ammo_9x19"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\MP5k_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\data\MP5k_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\data\MP5k_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\MP5k_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\MP5k_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_MP5_30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_MP5_30Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_MP5_30Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_mp5_30rnd.p3d";
		weight = 170;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_9x19";
		ammoItems[] = {"Ammo_9x19"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\mp5k_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\data\mp5k_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\data\mp5k_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\mp5k_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\mp5k_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_PM73_15Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_PM73_15Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_PM73_15Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_pm73_15rnd.p3d";
		weight = 150;
		itemSize[] = {1,2};
		count = 15;
		ammo = "Bullet_380";
		ammoItems[] = {"Ammo_380"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\magazine_pm73.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\magazine_pm73.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\magazine_pm73_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\magazine_pm73_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\magazine_pm73_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_PM73_25Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_PM73_25Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_PM73_25Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_pm73_25rnd.p3d";
		weight = 170;
		itemSize[] = {1,3};
		count = 25;
		ammo = "Bullet_380";
		ammoItems[] = {"Ammo_380"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\magazine_pm73.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\magazine_pm73.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\magazine_pm73_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\magazine_pm73_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\magazine_pm73_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_CZ61_20Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_CZ61_20Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_CZ61_20Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_cz61.p3d";
		weight = 150;
		itemSize[] = {1,2};
		count = 20;
		ammo = "Bullet_380";
		ammoItems[] = {"Ammo_380"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\magazine_cz61.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\magazine_cz61.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\magazine_cz61_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\magazine_cz61_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\magazine_cz61_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_MKII_10Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_MKII_10Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_MKII_10Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_mk2.p3d";
		weight = 55;
		itemSize[] = {1,2};
		count = 10;
		ammo = "Bullet_22";
		ammoItems[] = {"Ammo_22"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\mk2_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\data\mk2_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\data\mk2_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\mk2_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\mk2_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_ShockCartridge: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_ShockCartridge0";
		descriptionShort = "$STR_CfgMagazines_Mag_ShockCartridge1";
		model = "\DZ\weapons\attachments\magazine\shockpistol_cartridge.p3d";
		weight = 131;
		itemSize[] = {2,2};
		count = 1;
		ammo = "Dart_Syringe";
		ammoItems[] = {"Ammo_DartSyringe"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\shockpistol_cartridge.rvmat"}},{0.7,{"DZ\weapons\attachments\data\shockpistol_cartridge.rvmat"}},{0.5,{"DZ\weapons\attachments\data\shockpistol_cartridge_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\shockpistol_cartridge_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\shockpistol_cartridge_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Ruger1022_10Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_cfgmagazines_mag_ruger1022_10rnd0";
		descriptionShort = "$STR_cfgmagazines_mag_ruger1022_10rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_ruger1022_10.p3d";
		weight = 50;
		itemSize[] = {1,1};
		count = 10;
		ammo = "Bullet_22";
		ammoItems[] = {"Ammo_22"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\ruger_mag2.rvmat"}},{0.7,{"DZ\weapons\attachments\data\ruger_mag2.rvmat"}},{0.5,{"DZ\weapons\attachments\data\ruger_mag2_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\ruger_mag2_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\ruger_mag2_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Ruger1022_15Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Ruger1022_15Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_Ruger1022_15Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_ruger1022_15.p3d";
		weight = 80;
		itemSize[] = {1,2};
		count = 15;
		ammo = "Bullet_22";
		ammoItems[] = {"Ammo_22"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\ruger_mag2.rvmat"}},{0.7,{"DZ\weapons\attachments\data\ruger_mag2.rvmat"}},{0.5,{"DZ\weapons\attachments\data\ruger_mag2_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\ruger_mag2_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\ruger_mag2_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Ruger1022_30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Ruger1022_30Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_Ruger1022_30Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_ruger1022_30.p3d";
		weight = 110;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_22";
		ammoItems[] = {"Ammo_22"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\ruger_mag2.rvmat"}},{0.7,{"DZ\weapons\attachments\data\ruger_mag2.rvmat"}},{0.5,{"DZ\weapons\attachments\data\ruger_mag2_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\ruger_mag2_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\ruger_mag2_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_CLIP762x54_5Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_CLIP762x54_5Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_CLIP762x54_5Rnd1";
		model = "\DZ\weapons\attachments\magazine\clip_762_5rnd.p3d";
		weight = 20;
		itemSize[] = {1,2};
		count = 5;
		ammo = "Bullet_762x54";
		ammoItems[] = {"Ammo_762x54","Ammo_762x54Tracer"};
		tracersEvery = 0;
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
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_762x54Snaploader_2Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_762x54Snaploader_2Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_762x54Snaploader_2Rnd1";
		model = "\dz\weapons\attachments\magazine\snaploader_762.p3d";
		weight = 20;
		itemSize[] = {1,1};
		count = 2;
		ammo = "Bullet_762x54";
		ammoItems[] = {"Ammo_762x54","Ammo_762x54Tracer"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\snaploader762.rvmat"}},{0.7,{"DZ\weapons\attachments\data\snaploader762.rvmat"}},{0.5,{"DZ\weapons\attachments\data\snaploader762_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\snaploader762_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\snaploader762_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_308WinSnaploader_2Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_308WinSnaploader_2Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_308WinSnaploader_2Rnd1";
		model = "\dz\weapons\attachments\magazine\snaploader_762.p3d";
		weight = 30;
		itemSize[] = {1,1};
		count = 2;
		ammo = "Bullet_308Win";
		ammoItems[] = {"Ammo_308Win","Ammo_308WinTracer"};
		tracersEvery = 0;
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
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_CLIP762x39_10Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_CLIP762x39_10Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_CLIP762x39_10Rnd1";
		model = "\DZ\weapons\attachments\magazine\clip_762x39_10rnd.p3d";
		weight = 20;
		itemSize[] = {2,2};
		count = 10;
		ammo = "Bullet_762x39";
		ammoItems[] = {"Ammo_762x39","Ammo_762x39Tracer"};
		tracersEvery = 0;
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
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_CLIP9x19_10Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_CLIP9x19_10Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_CLIP9x19_10Rnd1";
		model = "\DZ\weapons\attachments\magazine\clip_9mm_10rnd.p3d";
		weight = 18;
		itemSize[] = {2,2};
		count = 10;
		ammo = "Bullet_9x19";
		ammoItems[] = {"Ammo_9x19"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\clip_9mm_10rnd.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\clip_9mm_10rnd.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\clip_9mm_10rnd_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\clip_9mm_10rnd_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\clip_9mm_10rnd_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_AKM_30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_AKM_30Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_AKM_30Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_akm_30rnd.p3d";
		weight = 430;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_762x39";
		ammoItems[] = {"Ammo_762x39","Ammo_762x39Tracer"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\akm_steel_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\data\akm_steel_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\data\akm_steel_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\akm_steel_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\akm_steel_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_AKM_Drum75Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_AKM_Drum75Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_AKM_Drum75Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_akm_drum.p3d";
		rotationFlags = 12;
		weight = 14;
		itemSize[] = {3,3};
		count = 75;
		ammo = "Bullet_762x39";
		ammoItems[] = {"Ammo_762x39","Ammo_762x39Tracer"};
		tracersEvery = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"DZ\weapons\attachments\data\magazine_drum_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\attachments\data\magazine_drum.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\magazine_drum.rvmat"}},{0.7,{"DZ\weapons\attachments\data\magazine_drum.rvmat"}},{0.5,{"DZ\weapons\attachments\data\magazine_drum_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\magazine_drum_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\magazine_drum_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_AKM_Drum75Rnd_Black: Mag_AKM_Drum75Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_AKM_Drum75Rnd_Black0";
		color = "Black";
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_AKM_Drum75Rnd_Green: Mag_AKM_Drum75Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_AKM_Drum75Rnd_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"DZ\weapons\attachments\data\magazine_drum_green_co.paa"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_AKM_Palm30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_AKM_Palm30Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_AKM_Palm30Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_akm_palm30.p3d";
		weight = 430;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_762x39";
		ammoItems[] = {"Ammo_762x39","Ammo_762x39Tracer"};
		tracersEvery = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\akm_accessories_black_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\akm_accessories.rvmat"}},{0.7,{"DZ\weapons\attachments\data\akm_accessories.rvmat"}},{0.5,{"DZ\weapons\attachments\data\akm_accessories_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\akm_accessories_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\akm_accessories_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_AKM_Palm30Rnd_Black: Mag_AKM_Palm30Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_AKM_Palm30Rnd_Black0";
		color = "Black";
	};
	class Mag_AKM_Palm30Rnd_Green: Mag_AKM_Palm30Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_AKM_Palm30Rnd_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\akm_accessories_green_co.paa"};
	};
	class Mag_CZ527_5rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_CZ527_5rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_CZ527_5rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_CZ527.p3d";
		weight = 91;
		itemSize[] = {1,1};
		count = 5;
		ammo = "Bullet_762x39";
		ammoItems[] = {"Ammo_762x39","Ammo_762x39Tracer"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\cz527_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\data\cz527_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\data\cz527_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\cz527_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\cz527_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_STANAG_30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_STANAG_30Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_STANAG_30Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_stanag30.p3d";
		weight = 90;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_556x45";
		ammoItems[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\m4_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\data\m4_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\data\m4_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\m4_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\m4_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_STANAGCoupled_30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_STANAGCoupled_30Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_STANAGCoupled_30Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_stanag30_coupled.p3d";
		weight = 180;
		itemSize[] = {2,3};
		count = 60;
		ammo = "Bullet_556x45";
		ammoItems[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\m4_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\data\m4_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\data\m4_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\m4_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\m4_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_CMAG_10Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_CMAG_10Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_10Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_pmag_10.p3d";
		weight = 30;
		itemSize[] = {1,2};
		count = 10;
		ammo = "Bullet_556x45";
		ammoItems[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		tracersEvery = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\pmag_black_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\pmag_black.rvmat"}},{0.7,{"DZ\weapons\attachments\data\pmag_black.rvmat"}},{0.5,{"DZ\weapons\attachments\data\pmag_black_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\pmag_black_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\pmag_black_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_CMAG_10Rnd_Black: Mag_CMAG_10Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_10Rnd_Black0";
		color = "Black";
	};
	class Mag_CMAG_10Rnd_Green: Mag_CMAG_10Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_10Rnd_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\pmag_co.paa"};
	};
	class Mag_CMAG_20Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_CMAG_20Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_20Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_pmag_20.p3d";
		weight = 60;
		itemSize[] = {1,2};
		count = 20;
		ammo = "Bullet_556x45";
		ammoItems[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		tracersEvery = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\pmag_black_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\pmag_black.rvmat"}},{0.7,{"DZ\weapons\attachments\data\pmag_black.rvmat"}},{0.5,{"DZ\weapons\attachments\data\pmag_black_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\pmag_black_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\pmag_black_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_CMAG_20Rnd_Black: Mag_CMAG_20Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_20Rnd_Black0";
		color = "Black";
	};
	class Mag_CMAG_20Rnd_Green: Mag_CMAG_20Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_20Rnd_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\pmag_co.paa"};
	};
	class Mag_CMAG_30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_CMAG_30Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_30Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_pmag_30.p3d";
		weight = 90;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_556x45";
		ammoItems[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		tracersEvery = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\pmag_black_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\pmag_black.rvmat"}},{0.7,{"DZ\weapons\attachments\data\pmag_black.rvmat"}},{0.5,{"DZ\weapons\attachments\data\pmag_black_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\pmag_black_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\pmag_black_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_CMAG_30Rnd_Black: Mag_CMAG_30Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_30Rnd_Black0";
		color = "Black";
	};
	class Mag_CMAG_30Rnd_Green: Mag_CMAG_30Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_30Rnd_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\pmag_co.paa"};
	};
	class Mag_CMAG_40Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_CMAG_40Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_40Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_pmag_40.p3d";
		weight = 100;
		itemSize[] = {1,4};
		count = 40;
		ammo = "Bullet_556x45";
		ammoItems[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		tracersEvery = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\pmag_black_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\pmag_black.rvmat"}},{0.7,{"DZ\weapons\attachments\data\pmag_black.rvmat"}},{0.5,{"DZ\weapons\attachments\data\pmag_black_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\pmag_black_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\pmag_black_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_CMAG_40Rnd_Black: Mag_CMAG_40Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_40Rnd_Black0";
		color = "Black";
	};
	class Mag_CMAG_40Rnd_Green: Mag_CMAG_40Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_CMAG_40Rnd_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\pmag_co.paa"};
	};
	class Mag_AK101_30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_AK101_30Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_AK101_30Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_ak101_30rnd.p3d";
		weight = 400;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_556x45";
		ammoItems[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		tracersEvery = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"DZ\weapons\firearms\AK101\data\ak101_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\weapons\firearms\AK101\data\ak101.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.7,{"DZ\weapons\firearms\AK101\data\ak101.rvmat"}},{0.5,{"DZ\weapons\firearms\AK101\data\ak101_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\AK101\data\ak101_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\AK101\data\ak101_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_AK101_30Rnd_Black: Mag_AK101_30Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_AK101_30Rnd_Black0";
		color = "Black";
	};
	class Mag_AK101_30Rnd_Green: Mag_AK101_30Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_AK101_30Rnd_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,CO)"};
	};
	class Mag_AK74_30Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_AK74_30Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_AK74_30Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_ak74_30rnd.p3d";
		weight = 230;
		itemSize[] = {1,3};
		count = 30;
		ammo = "Bullet_545x39";
		ammoItems[] = {"Ammo_545x39","Ammo_545x39Tracer"};
		tracersEvery = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"DZ\weapons\attachments\magazine\data\magazine_ak74_tan_co.paa"};
		hiddenSelectionsMaterials[] = {"DZ\weapons\attachments\magazine\data\magazine_ak74_tan.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\magazine_ak74.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\magazine_ak74.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\magazine_ak74_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\magazine_ak74_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\magazine_ak74_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_AK74_30Rnd_Black: Mag_AK74_30Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_AK74_30Rnd_Black0";
		color = "Black";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"DZ\weapons\attachments\magazine\data\magazine_ak74.rvmat"};
	};
	class Mag_AK74_30Rnd_Green: Mag_AK74_30Rnd
	{
		scope = 2;
		descriptionShort = "$STR_CfgMagazines_Mag_AK74_30Rnd_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"DZ\weapons\attachments\magazine\data\magazine_ak74.rvmat"};
	};
	class Mag_SVD_10Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_SVD_10Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_SVD_10Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_svd.p3d";
		weight = 120;
		itemSize[] = {1,2};
		count = 10;
		ammo = "Bullet_762x54";
		ammoItems[] = {"Ammo_762x54","Ammo_762x54Tracer"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"dz\weapons\attachments\data\svd_mag.rvmat"}},{0.7,{"dz\weapons\attachments\data\svd_mag.rvmat"}},{0.5,{"dz\weapons\attachments\data\svd_mag_damage.rvmat"}},{0.3,{"dz\weapons\attachments\data\svd_mag_damage.rvmat"}},{0.0,{"dz\weapons\attachments\data\svd_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_FAL_20Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_FAL_20Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_FAL_20Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_fal.p3d";
		weight = 120;
		itemSize[] = {1,2};
		count = 20;
		ammo = "Bullet_308Win";
		ammoItems[] = {"Ammo_308Win","Ammo_308WinTracer"};
		tracersEvery = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"DZ\weapons\attachments\magazine\data\fal_mag_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\fal_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\fal_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\fal_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\fal_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\fal_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Scout_5Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Scout_5Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_Scout_5Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_scout.p3d";
		weight = 40;
		itemSize[] = {1,1};
		count = 5;
		ammo = "Bullet_308Win";
		ammoItems[] = {"Ammo_308Win","Ammo_308WinTracer"};
		tracersEvery = 0;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\magazine\data\scout_mag_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\scout_mag.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\scout_mag.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\scout_mag_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\scout_mag_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\scout_mag_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_UMP_25Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_UMP_25Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_UMP_25Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_ump45_25rnd.p3d";
		weight = 350;
		itemSize[] = {1,3};
		count = 25;
		ammo = "Bullet_45ACP";
		ammoItems[] = {"Ammo_45ACP"};
		tracersEvery = 0;
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_VSS_10Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_VSS_10Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_VSS_10Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_vss.p3d";
		weight = 350;
		itemSize[] = {1,2};
		count = 10;
		ammo = "Bullet_9x39";
		ammoItems[] = {"Ammo_9x39","Ammo_9x39AP"};
		tracersEvery = 0;
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
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_M249_Box200Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_M249_Box200Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_M249_Box200Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_m249_ammobox.p3d";
		rotationFlags = 12;
		weight = 2000;
		itemSize[] = {5,4};
		count = 200;
		ammo = "Bullet_556x45";
		ammoItems[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		tracersEvery = 0;
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_12gaSnaploader_2Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_12gaSnaploader_2Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_12gaSnaploader_2Rnd1";
		model = "\dz\weapons\attachments\magazine\snaploader.p3d";
		weight = 10;
		itemSize[] = {1,1};
		count = 2;
		ammo = "Bullet_12GaugePellets";
		ammoItems[] = {"Ammo_12gaPellets","Ammo_12gaSlug","Ammo_12gaRubberSlug"};
		tracersEvery = 0;
		mass = 10;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\snaploader_red_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\snaploader.rvmat"}},{0.7,{"DZ\weapons\attachments\data\snaploader.rvmat"}},{0.5,{"DZ\weapons\attachments\data\snaploader_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\snaploader_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\snaploader_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Saiga_5Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Saiga_5Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_Saiga_5Rnd1";
		model = "\dz\weapons\attachments\magazine\magazine_saiga_mag5.p3d";
		weight = 200;
		itemSize[] = {1,1};
		count = 5;
		ammo = "Bullet_12GaugePellets";
		ammoItems[] = {"Ammo_12gaPellets","Ammo_12gaSlug","Ammo_12gaRubberSlug","Ammo_12gaBeanbag"};
		tracersEvery = 0;
		mass = 10;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\magazine\data\saiga_mag5_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\saiga_mag5.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\saiga_mag5.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\saiga_mag5_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\saiga_mag5_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\saiga_mag5_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Saiga_8Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Saiga_8Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_Saiga_8Rnd1";
		model = "\dz\weapons\attachments\magazine\magazine_saiga_mag8.p3d";
		weight = 220;
		itemSize[] = {1,2};
		count = 8;
		ammo = "Bullet_12GaugePellets";
		ammoItems[] = {"Ammo_12gaPellets","Ammo_12gaSlug","Ammo_12gaRubberSlug","Ammo_12gaBeanbag"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\magazine\data\saiga_mag8_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\saiga_mag8.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\saiga_mag8.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\saiga_mag8_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\saiga_mag8_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\saiga_mag8_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Saiga_Drum20Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Saiga_Drum20Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_Saiga_Drum20Rnd1";
		model = "\dz\weapons\attachments\magazine\magazine_saiga_drum.p3d";
		rotationFlags = 12;
		weight = 260;
		itemSize[] = {2,2};
		count = 20;
		ammo = "Bullet_12GaugePellets";
		ammoItems[] = {"Ammo_12gaPellets","Ammo_12gaSlug","Ammo_12gaRubberSlug","Ammo_12gaBeanbag"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\magazine\data\saiga_drum_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\saiga_drum.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\saiga_drum.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\saiga_drum_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\saiga_drum_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\saiga_drum_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Arrows_Quiver: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Arrows_Quiver0";
		descriptionShort = "$STR_CfgMagazines_Mag_Arrows_Quiver1";
		model = "\dz\weapons\attachments\magazine\magazine_quiver.p3d";
		rotationFlags = 1;
		weight = 150;
		itemSize[] = {2,3};
		count = 5;
		ammo = "Arrow_Composite";
		ammoItems[] = {"Ammo_ArrowComposite"};
		tracersEvery = 1;
		mass = 10;
		class Damage
		{
			tex[] = {};
			mat[] = {"dz\characters\vests\data\chest_holster.rvmat","dz\characters\vests\data\chest_holster_damage.rvmat","dz\characters\vests\data\chest_holster_destruct.rvmat"};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Bolts_Quiver: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Bolts_Quiver0";
		descriptionShort = "$STR_CfgMagazines_Mag_Bolts_Quiver1";
		model = "\dz\weapons\attachments\magazine\magazine_quiver.p3d";
		rotationFlags = 1;
		weight = 150;
		itemSize[] = {2,3};
		count = 5;
		ammo = "Arrow_Bolt";
		ammoItems[] = {"Ammo_ArrowBolt"};
		tracersEvery = 1;
		mass = 10;
		class Damage
		{
			tex[] = {};
			mat[] = {"dz\characters\vests\data\chest_holster.rvmat","dz\characters\vests\data\chest_holster_damage.rvmat","dz\characters\vests\data\chest_holster_destruct.rvmat"};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Dartgun_CO2: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Dartgun_CO20";
		descriptionShort = "$STR_CfgMagazines_Mag_Dartgun_CO21";
		model = "\dz\weapons\attachments\magazine\magazine_dartgun_CO2.p3d";
		weight = 12;
		itemSize[] = {2,2};
		count = 0;
		tracersEvery = 1;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\magazine_dartgun_CO2.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\magazine_dartgun_CO2.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\magazine_dartgun_CO2_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\magazine_dartgun_CO2_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\magazine_dartgun_CO2_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_Groza_20Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_Groza_20Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_Groza_20Rnd1";
		model = "\dz\weapons\attachments\magazine\magazine_ots14.p3d";
		weight = 410;
		itemSize[] = {1,2};
		count = 20;
		ammo = "Bullet_9x39AP";
		ammoItems[] = {"Ammo_9x39","Ammo_9x39AP"};
		tracersEvery = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\ots14_magazine.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\ots14_magazine.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\ots14_magazine_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\ots14_magazine_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\ots14_magazine_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_MakarovPB_8Rnd: Magazine_Base
	{
		scope = 2;
		displayName = "$STR_CfgMagazines_Mag_MakarovPB_8Rnd0";
		descriptionShort = "$STR_CfgMagazines_Mag_MakarovPB_8Rnd1";
		model = "\DZ\weapons\attachments\magazine\magazine_pb6p9.p3d";
		weight = 131;
		itemSize[] = {1,2};
		count = 8;
		ammo = "Bullet_380";
		ammoItems[] = {"Ammo_380"};
		tracersEvery = 0;
		mass = 10;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\magazine\data\magazine_pb6p9.rvmat"}},{0.7,{"DZ\weapons\attachments\magazine\data\magazine_pb6p9.rvmat"}},{0.5,{"DZ\weapons\attachments\magazine\data\magazine_pb6p9_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\magazine\data\magazine_pb6p9_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\magazine\data\magazine_pb6p9_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class MagRifle_fill_in
				{
					soundSet = "MagRifle_fill_in_SoundSet";
					id = 1;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 2;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 3;
				};
				class MagRifle_empty_in
				{
					soundSet = "MagRifle_empty_in_SoundSet";
					id = 4;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 5;
				};
				class MagRifle_empty_out
				{
					soundSet = "MagRifle_empty_out_SoundSet";
					id = 6;
				};
				class MagPistol_fill_in
				{
					soundSet = "MagPistol_fill_in_SoundSet";
					id = 7;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 8;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 9;
				};
				class MagPistol_empty_in
				{
					soundSet = "MagPistol_empty_in_SoundSet";
					id = 10;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 11;
				};
				class MagPistol_empty_out
				{
					soundSet = "MagPistol_empty_out_SoundSet";
					id = 12;
				};
			};
		};
	};
	class Mag_AKM_Drum_TEST: Mag_AKM_Drum75Rnd
	{
		scope = 2;
		displayName = "Tracer testing mag";
		descriptionShort = "Hope it won't cause lag";
		count = 300;
		ammo = "Bullet_762x39Tracer";
		ammoItems[] = {"Ammo_762x39Tracer"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyMagazine_STANAG30: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_STANAG30.p3d";
	};
	class ProxyMagazine_PMAG_10: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_pmag_10.p3d";
	};
	class ProxyMagazine_PMAG_20: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_pmag_20.p3d";
	};
	class ProxyMagazine_PMAG_30: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_pmag_30.p3d";
	};
	class ProxyMagazine_PMAG_40: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_pmag_40.p3d";
	};
	class ProxyMagazine_FNP45: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_fnp45.p3d";
	};
	class ProxyMagazine_ruger1022_10: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_ruger1022_10.p3d";
	};
	class Proxymagazine_ruger1022_15: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_ruger1022_15.p3d";
	};
	class ProxyMagazine_ruger1022_30: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_ruger1022_30.p3d";
	};
	class ProxyMagazine_mk2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_mk2.p3d";
	};
	class ProxyMagazine_1911: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_1911.p3d";
	};
	class ProxyMagazine_CZ75: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_CZ75.p3d";
	};
	class ProxyMagazine_akm_30rnd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_akm_30rnd.p3d";
	};
	class ProxyMagazine_akm_drum: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_akm_drum.p3d";
	};
	class ProxyMagazine_akm_palm30: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_akm_palm30.p3d";
	};
	class ProxyArrow_Composite
	{
		scope = 2;
		model = "\dz\weapons\projectiles\arrow_composite.p3d";
		inventorySlot = "arrows";
		autocenter = 1;
		shadow = 1;
		simulation = "proxyprojectile";
	};
	class ProxyMagazine_mp5_15rnd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_mp5_15rnd.p3d";
	};
	class ProxyMagazine_mp5_30rnd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_mp5_30rnd.p3d";
	};
	class ProxyMagazine_pm73_15rnd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_pm73_15rnd.p3d";
	};
	class ProxyMagazine_pm73_25rnd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_pm73_25rnd.p3d";
	};
	class Proxymagazine_cz527: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_cz527.p3d";
	};
	class Proxymagazine_ij70: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_ij70.p3d";
	};
	class ProxyMagazine_ak101_30rnd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_ak101_30rnd.p3d";
	};
	class Proxymagazine_p1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine3";
		model = "\DZ\weapons\attachments\magazine\magazine_p1.p3d";
	};
	class Proxymagazine_ak74_30rnd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_ak74_30rnd.p3d";
	};
	class Proxymagazine_aug30: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_aug30.p3d";
	};
	class Proxymagazine_svd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_svd.p3d";
	};
	class Proxymagazine_Vss: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_vss.p3d";
	};
	class ProxyMagazine_DE: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_DE.p3d";
	};
	class ProxyMagazine_ump45_25rnd: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_ump45_25rnd.p3d";
	};
	class Proxymagazine_glock19: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_glock19.p3d";
	};
	class Proxymagazine_fal: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_fal.p3d";
	};
	class Proxyshockpistol_cartridge: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\shockpistol_cartridge.p3d";
	};
	class ProxyShotgunShell_pellets
	{
		scope = 2;
		model = "\dz\weapons\projectiles\shotgunshell_pellets.p3d";
		autocenter = 1;
		shadow = 1;
		simulation = "proxyprojectile";
	};
	class ProxyShotgunShell_slug
	{
		scope = 2;
		model = "\dz\weapons\projectiles\shotgunshell_slug.p3d";
		autocenter = 1;
		shadow = 1;
		simulation = "proxyprojectile";
	};
	class ProxyMagazine_saiga_mag5: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_saiga_mag5.p3d";
	};
	class ProxyMagazine_saiga_mag8: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_saiga_mag8.p3d";
	};
	class ProxyMagazine_saiga_drum: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_saiga_drum.p3d";
	};
	class ProxyMagazine_m249_ammobox: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_m249_ammobox.p3d";
	};
	class ProxyMagazine_scout: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_scout.p3d";
	};
	class ProxyMagazine_ots14: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\dz\weapons\attachments\magazine\magazine_ots14.p3d";
	};
	class ProxyMagazine_cz61: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "magazine";
		model = "\DZ\weapons\attachments\magazine\magazine_cz61.p3d";
	};
};
