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
	class DZ_Nonlethal
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Sounds_Weapons"};
	};
};
class Mode_SemiAuto;
class Mode_Safe: Mode_SemiAuto
{
	magazines[] = {};
};
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons
{
	class DefaultWeapon;
	class NonlethalCore: DefaultWeapon
	{
		scope = 0;
		targetCategory = "loot";
		type = 1;
		autoReload = 0;
		rotationFlags = 17;
		storageCategory = 1;
		class Single: Mode_SemiAuto{};
		class NoiseShoot
		{
			strength = 10.0;
			type = "shot";
		};
		opticsZoomMin = 0.414215;
		opticsZoomInit = 0.57737;
		opticsZoomMax = 0.70022;
		tooltip = "_text = _this call fnc_generateTooltip;_text";
		barrelArmor = 400;
		bullet1[] = {"dz\sounds\weapons\shells\45\asphlat_45_01",0.17782794,1,15};
		bullet2[] = {"dz\sounds\weapons\shells\45\asphlat_45_02",0.17782794,1,15};
		bullet3[] = {"dz\sounds\weapons\shells\45\asphlat_45_03",0.17782794,1,15};
		bullet4[] = {"dz\sounds\weapons\shells\45\asphlat_45_04",0.17782794,1,15};
		bullet5[] = {"dz\sounds\weapons\shells\45\asphlat_45_05",0.31622776,1,15};
		bullet6[] = {"dz\sounds\weapons\shells\45\asphlat_45_06",0.31622776,1,15};
		bullet7[] = {"dz\sounds\weapons\shells\45\dirt_45_01",0.31622776,1,15};
		bullet8[] = {"dz\sounds\weapons\shells\45\dirt_45_02",0.31622776,1,15};
		bullet9[] = {"dz\sounds\weapons\shells\45\dirt_45_03",0.17782794,1,15};
		bullet10[] = {"dz\sounds\weapons\shells\45\dirt_45_04",0.17782794,1,15};
		bullet11[] = {"dz\sounds\weapons\shells\45\dirt_45_05",0.17782794,1,15};
		bullet12[] = {"dz\sounds\weapons\shells\45\dirt_45_06",0.17782794,1,15};
		soundBullet[] = {"bullet1",0.083,"bullet2",0.083,"bullet3",0.083,"bullet4",0.083,"bullet5",0.083,"bullet6",0.083,"bullet7",0.083,"bullet8",0.083,"bullet9",0.083,"bullet10",0.083,"bullet11",0.083,"bullet12",0.083};
		magazineSlot = "magazine";
	};
	class NonlethalPistol: NonlethalCore
	{
		itemSize[] = {4,2};
		disarmAction = "disarmHandgun";
		reloadAction = "GestureReloadPistolFNP45";
		cursor = "aimGunGhost";
		cursorAim = "aimPistol";
		inventorySlot[] = {"Pistol"};
		animClass = "Pistol";
		armAction = "HandGun";
	};
	class NonlethalRifle: NonlethalCore
	{
		itemSize[] = {8,2};
		disarmAction = "disarmRifle";
		cursor = "aimGunGhost";
		cursorAim = "aimRifle";
		inventorySlot[] = {"Shoulder"};
		animClass = "Rifle";
	};
};
