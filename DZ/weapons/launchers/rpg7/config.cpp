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
	class DZ_Weapons_Launchers_RPG7
	{
		units[] = {"RPG7"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Launchers"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons
{
	class Rifle_Base;
	class Launcher_Base;
	class RPG7Base: Launcher_Base
	{
		cursorAim = "";
		cursor = "";
		cursorSize = 1;
		autoAimEnabled = 0;
		opticsDisablePeripherialVision = 1;
		magazineReloadTime = 12;
		reloadTime = 0;
		initSpeed = 30;
		canLock = 0;
		reloadAction = "ManActReloadAT";
		aiRateOfFire = 10.0;
		aiRateOfFireDistance = 500;
		opticsZoomMin = 0.25;
		opticsZoomMax = 1.1;
		opticsZoomInit = 0.5;
		minRange = 20;
		minRangeProbab = 0.3;
		midRange = 150;
		midRangeProbab = 0.58;
		maxRange = 500;
		maxRangeProbab = 0.04;
		scope = 1;
		weight = 7000;
		itemSize[] = {4,1};
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		modelOptics = "-";
		cameraDir = "look";
		memoryPointCamera = "eye";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		primary = 1;
		value = 0;
		model = "\DZ\weapons\launchers\rpg7\rpg7.p3d";
		autoReload = 0;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {};
		chamberableFrom[] = {"Ammo_RPG7_HE","Ammo_RPG7_AP"};
		barrelArmor = 2000;
		ejectType = 2;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\firearms\FNX45\FNX_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\magnum\magnum_reload2",0.8,1,20};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"dz\sounds\weapons\firearms\CZ75\CZ75_single_0",3.1622777,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\CZ75\CZ75_single_1",3.1622777,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin1",0.33333,"begin2",0.33333};
			reloadTime = 0.13;
			recoil = "recoil_flaregun";
			recoilProne = "recoil_flaregun_prone";
			dispersion = 0.03;
			magazineSlot = "magazine";
		};
	};
	class RPG7: RPG7Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_RPG70";
		descriptionShort = "$STR_cfgWeapons_RPG71";
		model = "\DZ\weapons\launchers\rpg7\rpg7.p3d";
		attachments[] = {};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\launchers\rpg7\data\rpg7.rvmat","DZ\weapons\launchers\rpg7\data\rpg7_damage.rvmat","DZ\weapons\launchers\rpg7\data\rpg7_destruct.rvmat"};
		};
		class AnimationSources
		{
			class rearsight
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
		};
	};
};
