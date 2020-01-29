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
	class DZ_Weapons_Firearms_Ruger1022
	{
		units[] = {"Ruger1022","Ruger1022_Black","Ruger1022_Green"};
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
class cfgWeapons
{
	class Rifle_Base;
	class Ruger1022_Base: Rifle_Base
	{
		scope = 0;
		weight = 2300;
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_22"};
		magazines[] = {"Mag_Ruger1022_30Rnd","Mag_Ruger1022_10Rnd"};
		magazineSwitchTime = 0.4;
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\firearms\SKS\SKS_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\Ruger1022\Ruger1022_reload",0.8,1,20};
		reloadAction = "ReloadRuger1022";
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Ruger1022_Shot_SoundSet","Ruger1022_Tail_SoundSet","Ruger1022_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Ruger1022_silencerHomeMade_SoundSet","Ruger1022_silencerHomeMadeTail_SoundSet","Ruger1022_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\Ruger1022\Ruger1022_close_0auth",1,1,300};
			begin2[] = {"dz\sounds\weapons\firearms\Ruger1022\Ruger1022_close_1auth",1,1,300};
			begin3[] = {"dz\sounds\weapons\firearms\Ruger1022\Ruger1022_close_2",1,1,300};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\Ruger1022\Ruger1022_close_0auth",0.1,1,50};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
			reloadTime = 0.1;
			recoil = "recoil_single_primary_1outof10";
			recoilProne = "recoil_single_primary_1outof10";
			dispersion = 0.0025;
			magazineSlot = "magazine";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			modelOptics = "-";
			distanceZoomMin = 50;
			distanceZoomMax = 50;
			discreteDistance[] = {50};
			discreteDistanceInitIndex = 0;
		};
	};
	class Ruger1022: Ruger1022_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Ruger10220";
		descriptionShort = "$STR_cfgWeapons_Ruger10221";
		model = "\dz\weapons\firearms\Ruger1022\Ruger1022.p3d";
		itemSize[] = {9,3};
		attachments[] = {"weaponWrap","weaponOpticsHunting","suppressorImpro"};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\Ruger1022\data\ruger1022_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\Ruger1022\data\ruger1022.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\Ruger1022\data\ruger1022.rvmat"}},{0.7,{"DZ\weapons\firearms\Ruger1022\data\ruger1022.rvmat"}},{0.5,{"DZ\weapons\firearms\Ruger1022\data\ruger1022_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\Ruger1022\data\ruger1022_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\Ruger1022\data\ruger1022_destruct.rvmat"}}};
				};
			};
		};
	};
	class Ruger1022_Black: Ruger1022
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_Ruger1022_Black0";
		color = "Black";
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\Ruger1022\data\ruger1022_black_co.paa"};
	};
	class Ruger1022_Green: Ruger1022
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_Ruger1022_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\Ruger1022\data\ruger1022_green_co.paa"};
	};
};
