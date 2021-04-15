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
	class DZ_Weapons_Firearms_Scout
	{
		units[] = {"Scout"};
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
	class BoltActionRifle_Base;
	class Scout_Base: BoltActionRifle_Base
	{
		scope = 0;
		weight = 3000;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		modelOptics = "-";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		PPDOFProperties[] = {1,0.5,50,160,4,10};
		opticsFlare = 0;
		winchesterTypeOpticsMount = 1;
		ironsightsExcludingOptics[] = {"HuntingOptic"};
		WeaponLength = 0.934214;
		barrelArmor = 1.111;
		initSpeedMultiplier = 1.15;
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		magazines[] = {"Mag_Scout_5Rnd"};
		magazineSwitchTime = 0.38;
		ejectType = 0;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {0.85,0.85,0.85};
		drySound[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\cz527\cz527_reload_0",0.8,1,20};
		reloadSound[] = {"dz\sounds\weapons\firearms\cz527\cz527_cycling_0",0.8,1,20};
		reloadAction = "Reloadcz527";
		shotAction = "Reloadcz527Shot";
		hiddenSelections[] = {"camo","badge_cherno"};
		modes[] = {"Single"};
		dispersionModifier = -0.00025;
		dexterityModifier = -0.2;
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"SCOUT_Shot_SoundSet","SCOUT_Tail_SoundSet","SCOUT_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"SCOUT_silencer_SoundSet","SCOUT_silencerTail_SoundSet","SCOUT_silencerInteriorTail_SoundSet"},{"SCOUT_silencerHomeMade_SoundSet","SCOUT_silencerHomeMadeTail_SoundSet","SCOUT_silencerInteriorTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\cz527\cz527_single_0",1,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\cz527\cz527_single_1",1,1,1000};
			begin3[] = {"dz\sounds\weapons\firearms\cz527\cz527_single_2",1,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,150};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
			reloadTime = 2;
			recoil = "recoil_scout";
			recoilProne = "recoil_scout_prone";
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
					overrideParticle = "weapon_shot_cz527_01";
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					positionOffset[] = {-0.05,0,0};
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating = 1;
				maxOverheatingValue = 4;
				overheatingDecayInterval = 3;
				class BarrelSmoke
				{
					overrideParticle = "smoking_barrel_small";
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
		class NoiseShoot
		{
			strength = 100;
			type = "shot";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 100;
		};
	};
	class Scout: Scout_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Scout0";
		descriptionShort = "$STR_cfgWeapons_Scout1";
		model = "\dz\weapons\firearms\scout\scout.p3d";
		attachments[] = {"weaponWrap","weaponOptics","weaponMuzzleM4"};
		itemSize[] = {9,3};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\scout\data\scout_co.paa",""};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\scout\data\scout.rvmat",""};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\scout\data\scout.rvmat"}},{0.7,{"DZ\weapons\firearms\scout\data\scout.rvmat"}},{0.5,{"DZ\weapons\firearms\scout\data\scout_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\scout\data\scout_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\scout\data\scout_destruct.rvmat"}}};
				};
			};
		};
	};
	class Scout_Chernarus: Scout
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\scout\data\scout_co.paa","#(argb,8,8,3)color(0.2,0.2,0.2,1.0,co)"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\scout\data\scout.rvmat","dz\weapons\firearms\scout\data\badge_cherno.rvmat"};
	};
	class Scout_Livonia: Scout
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\scout\data\scout_co.paa","#(argb,8,8,3)color(0.2,0.2,0.2,1.0,co)"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\scout\data\scout.rvmat","dz\weapons\firearms\scout\data\badge_livonia.rvmat"};
	};
};
