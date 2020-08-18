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
	class DZ_Pistols_Flaregun
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons
{
	class Pistol_Base;
	class Flaregun_Base: Pistol_Base
	{
		scope = 0;
		weight = 400;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {30.0,25.0};
		modelOptics = "-";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		value = 0;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {};
		chamberableFrom[] = {"Ammo_Flare"};
		ejectType = 2;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\firearms\FNX45\FNX_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\magnum\magnum_reload2",0.8,1,20};
		reloadAction = "reloadFlaregun";
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
	class Flaregun: Flaregun_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Flaregun0";
		descriptionShort = "$STR_cfgWeapons_Flaregun1";
		model = "\dz\weapons\pistols\flaregun\flaregun.p3d";
		attachments[] = {};
		itemSize[] = {2,2};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\pistols\flaregun\data\flaregun.rvmat","DZ\weapons\pistols\flaregun\data\flaregun_damage.rvmat","DZ\weapons\pistols\flaregun\data\flaregun_destruct.rvmat"};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyFlaregun: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "pistol";
		model = "\dz\weapons\pistols\flaregun\flaregun.p3d";
	};
};
