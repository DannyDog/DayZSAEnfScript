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
	class DZ_Weapons_Firearms_aug
	{
		units[] = {"AugSteyr"};
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
	class AugSteyr_Base: Rifle_Base
	{
		scope = 0;
		weight = 3600;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black"};
		magazineSwitchTime = 0.38;
		ejectType = 1;
		drySound[] = {"dz\sounds\weapons\firearms\m4a1\m4_dry",0.5,1,20};
		discreteDistance[] = {300};
		discreteDistanceInitIndex = 1;
		reloadAction = "ReloadAug";
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\steyraug\steyraug_reload",0.8,1,20};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4"};
		modes[] = {"FullAuto","SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"AUG_Shot_SoundSet","AUG_Tail_SoundSet","AUG_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"AUG_silencer_SoundSet","AUG_silencerTail_SoundSet","AUG_silencerInteriorTail_SoundSet"},{"AUG_silencerHomeMade_SoundSet","AUG_silencerHomeMadeTail_SoundSet","AUG_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\steyraug\steyraug_shot_0",1,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\steyraug\steyraug_shot_1",1,1,1000};
			begin3[] = {"dz\sounds\weapons\firearms\steyraug\steyraug_shot_2",1,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
			reloadTime = 0.085;
			recoil = "recoil_single_primary_5outof10";
			recoilProne = "recoil_single_primary_prone_5outof10";
			dispersion = 0.0015;
			magazineSlot = "magazine";
			beginSilenced_Pro[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,75};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,100};
			soundBeginExt[] = {{"beginSilenced_Pro",1},{"beginSilenced_HomeMade",1}};
		};
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[] = {"AUG_Shot_SoundSet","AUG_Tail_SoundSet","AUG_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"AUG_silencer_SoundSet","AUG_silencerTail_SoundSet","AUG_silencerInteriorTail_SoundSet"},{"AUG_silencerHomeMade_SoundSet","AUG_silencerHomeMadeTail_SoundSet","AUG_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\steyraug\steyraug_shot_0",1,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\steyraug\steyraug_shot_1",1,1,1000};
			begin3[] = {"dz\sounds\weapons\firearms\steyraug\steyraug_shot_2",1,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
			beginSilenced_Pro[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,75};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,100};
			soundBeginExt[] = {{"beginSilenced_Pro",1},{"beginSilenced_HomeMade",1}};
			reloadTime = 0.09;
			recoil = "recoil_auto_primary_5outof10";
			recoilProne = "recoil_auto_primary_prone_5outof10";
			dispersion = 0.0015;
			magazineSlot = "magazine";
		};
		class NoiseShoot
		{
			strength = 82;
			type = "shot";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			modelOptics = "-";
			opticsZoomMin = 0.28;
			opticsZoomMax = 0.28;
			opticsZoomInit = 0.28;
			distanceZoomMin = 300;
			distanceZoomMax = 300;
		};
	};
	class AugSteyr: AugSteyr_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_AugSteyr0";
		descriptionShort = "$STR_cfgWeapons_AugSteyr1";
		model = "\dz\weapons\firearms\aug\aug.p3d";
		attachments[] = {"weaponMuzzleM4","weaponBarrelAug"};
		itemSize[] = {8,3};
		spawnDamageRange[] = {0.0,0.6};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\firearms\aug\data\aug_barrel_base.rvmat","DZ\weapons\firearms\aug\data\aug_barrel_base_damage.rvmat","DZ\weapons\firearms\aug\data\aug_barrel_base_destruct.rvmat","DZ\weapons\firearms\aug\data\aug_barrel_short.rvmat","DZ\weapons\firearms\aug\data\aug_barrel_short_damage.rvmat","DZ\weapons\firearms\aug\data\aug_barrel_short_destruct.rvmat","DZ\weapons\firearms\aug\data\aug_stock.rvmat","DZ\weapons\firearms\aug\data\aug_stock_damage.rvmat","DZ\weapons\firearms\aug\data\aug_stock_destruct.rvmat","DZ\weapons\firearms\aug\data\scope.rvmat","DZ\weapons\firearms\aug\data\scope_damage.rvmat","DZ\weapons\firearms\aug\data\scope_destruct.rvmat"};
		};
	};
};
