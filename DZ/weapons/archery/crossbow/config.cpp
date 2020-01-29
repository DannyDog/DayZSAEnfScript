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
	class DZ_Weapons_Archery_Crossbow
	{
		units[] = {"Crossbow"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Archery"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons
{
	class Archery_Base;
	class Crossbow: Archery_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Crossbow0";
		descriptionShort = "$STR_cfgWeapons_Crossbow1";
		model = "\dz\weapons\archery\crossbow\crossbow.p3d";
		animName = "Crossbow";
		animClass = "";
		rotationFlags = 34;
		weight = 2700;
		itemSize[] = {10,5};
		chamberSize = 5;
		chamberedRound = "";
		magazines[] = {};
		chamberableFrom[] = {"Ammo_ArrowBolt","Mag_Bolts_Quiver"};
		reloadMagazineSound[] = {"dz\sounds\weapons\bows\crossbow_reload",0.05623413,1,30};
		reloadSound[] = {"dz\sounds\weapons\bows\crossbow_magazine_reload",0.05623413,1,30};
		reloadAction = "ReloadCrossbowFull";
		shotAction = "ReloadCrossbow";
		attachments[] = {"weaponOpticsCrossbow"};
		distanceZoomMin = 30;
		distanceZoomMax = 30;
		discreteDistance[] = {30};
		discreteDistanceInitIndex = 1;
		ejectType = 4;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\archery\crossbow\data\crossbow_leaves_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\archery\crossbow\data\crossbow.rvmat"};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\archery\crossbow\data\crossbow.rvmat","DZ\weapons\archery\crossbow\data\crossbow_damage.rvmat","DZ\weapons\archery\crossbow\data\crossbow_destruct.rvmat"};
		};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"dz\sounds\weapons\bows\Crossbow_shot_loaded_01",0.099999994,1,30};
			begin2[] = {"dz\sounds\weapons\bows\Crossbow_shot_loaded_02",0.099999994,1,30};
			begin3[] = {"dz\sounds\weapons\bows\Crossbow_shot_loaded_03",0.099999994,1,30};
			begin4[] = {"dz\sounds\weapons\bows\Crossbow_shot_loaded_04",0.099999994,1,30};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333,"begin4",0.33333};
			reloadTime = 5.3333;
			recoil = "recoil_crossbow";
			recoilProne = "recoil_crossbow";
			dispersion = 0.00075;
			magazineSlot = "magazine";
		};
		class NoiseShoot
		{
			strength = 10.0;
			type = "shot";
		};
	};
};
