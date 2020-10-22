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
	class DZ_Nonlethal_Shockpistol
	{
		units[] = {"Shockpistol"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Nonlethal"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons
{
	class NonlethalPistol;
	class Shockpistol_Base: NonlethalPistol
	{
		scope = 0;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {30.0,25.0};
		value = 0;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"Mag_ShockCartridge"};
		chamberableFrom[] = {"Ammo_9x19"};
		ejectType = 1;
		drySound[] = {"DZ\sounds\weapons\nonlethal\shockpistol\Shockpistol_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\FNX45\FNX45_reload",0.8,1,20};
		recoilModifier[] = {1,1,1};
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Shockpistol_Shot_SoundSet","Shockpistol_Tail_SoundSet","Shockpistol_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\firearms\CZ75\CZ75_single_0",1,1,600};
			begin2[] = {"dz\sounds\weapons\firearms\CZ75\CZ75_single_1",1,1,600};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin1",0.33333,"begin2",0.33333};
			beginSilenced_Pro1[] = {"dz\sounds\weapons\firearms\CZ75\cz75Silenced",1,1,60};
			beginSilenced_Pro2[] = {"dz\sounds\weapons\firearms\CZ75\cz75Silenced2",1,1,60};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\CZ75\cz75Silenced",1,1,100};
			soundBeginExt[] = {{"beginSilenced_Pro1",0.5,"beginSilenced_Pro2",0.5},{"beginSilenced_HomeMade",1}};
			reloadTime = 0.13;
			recoil = "recoil_shockpistol";
			recoilProne = "recoil_shockpistol";
			dispersion = 0.006;
			magazineSlot = "magazine";
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\nonlethal\shockpistol\data\shockpistol_main.rvmat","DZ\weapons\nonlethal\shockpistol\data\shockpistol_main_damage.rvmat","DZ\weapons\nonlethal\shockpistol\data\shockpistol_main_destruct.rvmat"};
		};
	};
	class Shockpistol: Shockpistol_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Shockpistol0";
		descriptionShort = "$STR_cfgWeapons_Shockpistol1";
		model = "\dz\weapons\nonlethal\shockpistol\shockpistol.p3d";
		itemSize[] = {4,3};
		weight = 1000;
		modelOptics = "-";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dz\weapons\nonlethal\shockpistol\data\shockpistol_main_yel_co.paa"};
	};
	class Shockpistol_Black: Shockpistol
	{
		descriptionShort = "$STR_cfgWeapons_Shockpistol_Black0";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\dz\weapons\nonlethal\shockpistol\data\shockpistol_main_bk_co.paa"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyShockpistol: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "pistol";
		model = "\dz\weapons\nonlethal\shockpistol\shockpistol.p3d";
	};
};
