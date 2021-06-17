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
	class DZ_Weapons_Firearms_M16A2
	{
		units[] = {"M16A2"};
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
	class Launcher_Base;
	class M4A1_Base;
	class M4A1;
	class M16A2_Base: Rifle_Base
	{
		scope = 0;
		model = "\dz\weapons\firearms\m16a2\m16a2.p3d";
		weight = 2900;
		itemSize[] = {9,3};
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		PPDOFProperties[] = {1,0.6,50,180,4,10};
		WeaponLength = 1.03;
		barrelArmor = 2.5;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\M16a2\Data\m16a2_a.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b.rvmat"}},{0.7,{"DZ\weapons\firearms\M16a2\Data\m16a2_a.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b.rvmat"}},{0.5,{"DZ\weapons\firearms\M16a2\Data\m16a2_a_damage.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\M16a2\Data\m16a2_a_damage.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\M16a2\Data\m16a2_a_destruct.rvmat","DZ\weapons\firearms\M16a2\Data\m16a2_b_destruct.rvmat"}}};
				};
			};
		};
		initSpeedMultiplier = 1.0;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {2.5,2.5,1.1};
		attachments[] = {"weaponWrap","weaponMuzzleM4","weaponBayonet"};
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		magazines[] = {"Mag_STANAG_30Rnd","Mag_STANAGCoupled_30Rnd","Mag_STANAG_60Rnd","Mag_CMAG_10Rnd","Mag_CMAG_20Rnd","Mag_CMAG_30Rnd","Mag_CMAG_40Rnd","Mag_CMAG_10Rnd_Green","Mag_CMAG_20Rnd_Green","Mag_CMAG_30Rnd_Green","Mag_CMAG_40Rnd_Green","Mag_CMAG_10Rnd_Black","Mag_CMAG_20Rnd_Black","Mag_CMAG_30Rnd_Black","Mag_CMAG_40Rnd_Black"};
		magazineSwitchTime = 0.5;
		ejectType = 1;
		reloadAction = "ReloadM4";
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\m4a1\m4_reload_0",0.8,1,20};
		modes[] = {"SemiAuto","Burst"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"M16_Shot_SoundSet","M16_Tail_SoundSet","M16_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"M16_silencer_SoundSet","M16_silencerTail_SoundSet","M16_silencerInteriorTail_SoundSet"},{"M16_silencerHomeMade_SoundSet","M16_silencerHomeMadeTail_SoundSet","M16_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\m4a1\m4_single_1",1,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\m4a1\m4_single_2",1,1,1000};
			begin3[] = {"dz\sounds\weapons\firearms\m4a1\m4_single_3",1,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
			reloadTime = 0.125;
			dispersion = 0.002;
			magazineSlot = "magazine";
			beginSilenced_Pro1[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,75};
			beginSilenced_Pro2[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced2",1,1,75};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,150};
			soundBeginExt[] = {{"beginSilenced_Pro1",0.5,"beginSilenced_Pro2",0.5},{"beginSilenced_HomeMade",1}};
		};
		class Burst: Mode_Burst
		{
			soundSetShot[] = {"M16_Shot_SoundSet","M16_Tail_SoundSet","M16_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"M16_silencer_SoundSet","M16_silencerTail_SoundSet","M16_silencerInteriorTail_SoundSet"},{"M16_silencerHomeMade_SoundSet","M16_silencerHomeMadeTail_SoundSet","M16_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\m4a1\m4_single_1",1,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\m4a1\m4_single_2",1,1,1000};
			begin3[] = {"dz\sounds\weapons\firearms\m4a1\m4_single_3",1,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin3",0.33333};
			burst = 3;
			reloadTime = 0.075;
			dispersion = 0.002;
			magazineSlot = "magazine";
			beginSilenced_Pro1[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,75};
			beginSilenced_Pro2[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced2",1,1,75};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,150};
			soundBeginExt[] = {{"beginSilenced_Pro1",0.5,"beginSilenced_Pro2",0.5},{"beginSilenced_HomeMade",1}};
		};
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera = "eye";
			discreteDistance[] = {25,50,100,200};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 25;
			distanceZoomMax = 200;
			PPMaskProperties[] = {0.5,0.5,0.4,0.05};
			PPLensProperties[] = {1,0.15,0,0};
			PPBlurProperties = 0.2;
		};
		class NoiseShoot
		{
			strength = 82;
			type = "shot";
		};
		simpleHiddenSelections[] = {"hide_barrel"};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\m16a2\data\m16a2_a_co.paa","dz\weapons\firearms\m16a2\data\m16a2_b_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\m16a2\data\m16a2_a.rvmat","dz\weapons\firearms\m16a2\data\m16a2_b.rvmat"};
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
					overrideParticle = "weapon_shot_ump45_01";
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
				};
				class ChamberSmokeBurst
				{
					overrideParticle = "weapon_shot_chamber_smoke";
					overridePoint = "Nabojnicestart";
					overrideDirectionPoint = "Nabojniceend";
				};
			};
			class OnOverheating
			{
				maxOverheatingValue = 60;
				shotsToStartOverheating = 7;
				overheatingDecayInterval = 1;
				class SmokingBarrel1
				{
					positionOffset[] = {0.2,0,0};
					overrideParticle = "smoking_barrel_small";
					onlyWithinOverheatLimits[] = {0.0,0.2};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHot1
				{
					positionOffset[] = {0.2,0,0};
					overrideParticle = "smoking_barrel";
					onlyWithinOverheatLimits[] = {0.2,0.6};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHot3
				{
					positionOffset[] = {0.2,0,0};
					overrideParticle = "smoking_barrel_heavy";
					onlyWithinOverheatLimits[] = {0.6,1};
					onlyWithinRainLimits[] = {0,0.2};
				};
				class SmokingBarrelHotSteam
				{
					overrideParticle = "smoking_barrel_steam";
					positionOffset[] = {0.35,0,0};
					onlyWithinOverheatLimits[] = {0,1};
					onlyWithinRainLimits[] = {0.2,1};
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
	};
	class M16A2: M16A2_Base
	{
		scope = 2;
		displayName = "$STR_M16A2_0";
		descriptionShort = "$STR_M16A2_1";
	};
};
