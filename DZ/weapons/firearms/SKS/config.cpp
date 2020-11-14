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
	class DZ_Weapons_Firearms_SKS
	{
		units[] = {"SKS","SKS_Black","SKS_Green"};
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
	class SKS_Base: Rifle_Base
	{
		scope = 0;
		weight = 3850;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		PPDOFProperties[] = {1,0.6,50,160,4,10};
		DisplayMagazine = 0;
		WeaponLength = 1.11042;
		barrelArmor = 1.667;
		chamberSize = 10;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_762x39","Mag_CLIP762x39_10Rnd","Ammo_762x39Tracer"};
		magazines[] = {};
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {2.4,2.4,1.3};
		simpleHiddenSelections[] = {"hide_barrel"};
		cursor = "aimBowGhost";
		drySound[] = {"dz\sounds\weapons\firearms\SKS\SKS_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\SKS\SKS_reloading",0.8,1,20};
		reloadAction = "ReloadSks";
		hiddenSelections[] = {"camoGround","Clip_rounds","clip"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"SKS_Shot_SoundSet","SKS_Tail_SoundSet","SKS_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"SKS_silencerHomeMade_SoundSet","SKS_silencerHomeMadeTail_SoundSet","SKS_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\SKS\SKS_close_0",1,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\SKS\SKS_close_1",1,1,1000};
			begin3[] = {"dz\sounds\weapons\firearms\SKS\SKS_close_2",1,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,150};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
			reloadTime = 0.125;
			recoil = "recoil_sks";
			recoilProne = "recoil_sks_prone";
			dispersion = 0.0015;
			magazineSlot = "magazine";
		};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle = "weapon_shot_winded_smoke";
				};
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_sks_01";
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					positionOffset[] = {-0.05,0,0};
				};
				class ChamberSmoke
				{
					overrideParticle = "weapon_shot_chamber_smoke";
					overridePoint = "Nabojnicestart";
					overrideDirectionPoint = "Nabojniceend";
				};
			};
			class OnOverheating
			{
				maxOverheatingValue = 20;
				shotsToStartOverheating = 1;
				overheatingDecayInterval = 1;
				class SmokingBarrel1
				{
					overrideParticle = "smoking_barrel_small";
					onlyWithinOverheatLimits[] = {0.0,0.5};
					positionOffset[] = {0.1,0,0};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHot1
				{
					overrideParticle = "smoking_barrel";
					onlyWithinOverheatLimits[] = {0.5,0.8};
					positionOffset[] = {0.1,0,0};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHot3
				{
					overrideParticle = "smoking_barrel_heavy";
					onlyWithinOverheatLimits[] = {0.8,1};
					positionOffset[] = {0.1,0,0};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHotSteamSmall
				{
					overrideParticle = "smoking_barrel_steam_small";
					positionOffset[] = {0.3,0,0};
					onlyWithinRainLimits[] = {0.2,0.5};
				};
				class SmokingBarrelHotSteam
				{
					overrideParticle = "smoking_barrel_steam";
					positionOffset[] = {0.3,0,0};
					onlyWithinRainLimits[] = {0.5,1};
				};
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen = 1;
					overrideParticle = "smoking_barrel_small";
					overridePoint = "Nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle = "weapon_shot_chamber_smoke_raise";
					overridePoint = "Nabojnicestart";
				};
			};
		};
		class OpticsInfo: OpticsInfoRifle
		{
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 100;
		};
		class AnimationSources
		{
			class Clip_rounds
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Clip
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class SKS: SKS_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_SKS0";
		descriptionShort = "$STR_cfgWeapons_SKS1";
		model = "\dz\weapons\firearms\SKS\SKS.p3d";
		attachments[] = {"weaponWrap","weaponOpticsMosin","suppressorImpro","weaponBayonetSKS"};
		itemSize[] = {9,3};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\SKS\data\sks_co.paa","",""};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\SKS\data\sks.rvmat","",""};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\SKS\data\sks.rvmat"}},{0.7,{"DZ\weapons\firearms\SKS\data\sks.rvmat"}},{0.5,{"DZ\weapons\firearms\SKS\data\sks_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\SKS\data\sks_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\SKS\data\sks_destruct.rvmat"}}};
				};
			};
		};
	};
	class SKS_Black: SKS
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_SKS_Black0";
		color = "Black";
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\SKS\data\sks_black_co.paa","",""};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\SKS\data\sks_painted.rvmat","",""};
	};
	class SKS_Green: SKS
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_SKS_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\SKS\data\sks_green_co.paa","",""};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\SKS\data\sks_painted.rvmat","",""};
	};
};
