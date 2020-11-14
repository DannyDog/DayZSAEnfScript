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
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		PPDOFProperties[] = {1,0.5,50,160,4,10};
		WeaponLength = 1.18986;
		barrelArmor = 2.019;
		initSpeedMultiplier = 1.15;
		winchesterTypeOpticsMount = 1;
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_22"};
		magazines[] = {"Mag_Ruger1022_30Rnd","Mag_Ruger1022_15Rnd"};
		magazineSwitchTime = 0.4;
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {2,2,1.1};
		simpleHiddenSelections[] = {"hide_barrel"};
		drySound[] = {"dz\sounds\weapons\firearms\SKS\SKS_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\Ruger1022\Ruger1022_reload",0.8,1,20};
		reloadAction = "ReloadRuger1022";
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Ruger1022_Shot_SoundSet","Ruger1022_Tail_SoundSet","Ruger1022_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Ruger1022_silencerHomeMade_SoundSet","Ruger1022_silencerHomeMadeTail_SoundSet","Ruger1022_silencerInteriorHomeMadeTail_SoundSet"}};
			reloadTime = 0.08;
			dispersion = 0.0025;
			magazineSlot = "magazine";
		};
		class NoiseShoot
		{
			strength = 5.0;
			type = "shot";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			modelOptics = "-";
			distanceZoomMin = 50;
			distanceZoomMax = 50;
			discreteDistance[] = {100};
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
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\Ruger1022\data\ruger1022.rvmat"}},{0.7,{"DZ\weapons\firearms\Ruger1022\data\ruger1022.rvmat"}},{0.5,{"DZ\weapons\firearms\Ruger1022\data\ruger1022_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\Ruger1022\data\ruger1022_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\Ruger1022\data\ruger1022_destruct.rvmat"}}};
				};
			};
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_fnx_02";
				};
				class SmokeCloud
				{
					overrideParticle = "weapon_shot_winded_smoke_small";
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating = 1;
				maxOverheatingValue = 7;
				overheatingDecayInterval = 1;
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen = 1;
					overrideParticle = "smoking_barrel_small";
					overridePoint = "Nabojnicestart";
				};
			};
		};
	};
};
