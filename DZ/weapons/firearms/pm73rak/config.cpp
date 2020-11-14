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
	class DZ_Weapons_Firearms_pm73rak
	{
		units[] = {"PM73Rak"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoRifle;
class CfgWeapons
{
	class Rifle_Base;
	class PM73Rak_Base: Rifle_Base
	{
		scope = 0;
		weight = 1600;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_380"};
		magazines[] = {"Mag_PM73_25Rnd","Mag_PM73_15Rnd"};
		magazineSwitchTime = 0.35;
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\firearms\m4a1\m4_dry",0.5,1,20};
		reloadAction = "ReloadPM63";
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\pm63rak\pm63rak_reload_0mod",0.8,1,20};
		hiddenSelections[] = {"camo"};
		modes[] = {"FullAuto"};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[] = {"PM73_Shot_SoundSet","PM73_Tail_SoundSet","PM73_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\firearms\pm63rak\pm63rak_single_0",0.7,1,900};
			begin2[] = {"dz\sounds\weapons\firearms\pm63rak\pm63rak_single_1",0.7,1,900};
			begin3[] = {"dz\sounds\weapons\firearms\pm63rak\pm63rak_single_1",0.7,1,900};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
			reloadTime = 0.092;
			recoil = "recoil_rak";
			recoilProne = "recoil_rak_prone";
			dispersion = 0.003;
			magazineSlot = "magazine";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 100;
		};
	};
	class PM73Rak: PM73Rak_Base
	{
		scope = 2;
		displayName = "$STR_CfgWeapons_PM73Rak0";
		descriptionShort = "$STR_CfgWeapons_PM73Rak1";
		model = "\dz\weapons\firearms\pm73rak\pm73rak.p3d";
		attachments[] = {};
		itemSize[] = {6,3};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\pm73rak\data\pm73_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\pm73rak\data\pm73.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\pm73rak\Data\pm73.rvmat"}},{0.7,{"DZ\weapons\firearms\pm73rak\Data\pm73.rvmat"}},{0.5,{"DZ\weapons\firearms\pm73rak\Data\pm73_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\pm73rak\Data\pm73_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\pm73rak\Data\pm73_destruct.rvmat"}}};
				};
			};
		};
	};
};
