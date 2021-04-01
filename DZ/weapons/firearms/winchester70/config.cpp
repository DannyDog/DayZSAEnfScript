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
	class DZ_Weapons_Firearms_Winchester70
	{
		units[] = {"Winchester70","Winchester70_Black","Winchester70_Green"};
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
	class BoltActionRifle_InnerMagazine_Base;
	class Winchester70_Base: BoltActionRifle_InnerMagazine_Base
	{
		scope = 0;
		animName = "Winchester70";
		weight = 2721;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		PPDOFProperties[] = {1,0.5,20,170,4,10};
		WeaponLength = 0.931718;
		barrelArmor = 3.125;
		winchesterTypeOpticsMount = 1;
		chamberSize = 5;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_308Win","Ammo_308WinTracer"};
		magazines[] = {};
		DisplayMagazine = 0;
		ejectType = 0;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {2.2,2.2,1.2};
		simpleHiddenSelections[] = {"hide_barrel"};
		drySound[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\winchester70\winchester70_reload",0.8,1,20};
		reloadSound[] = {"dz\sounds\weapons\firearms\winchester70\winchester70_cycle",0.8,1,20};
		reloadAction = "ReloadWinchester70";
		shotAction = "ReloadWinchester70_shot";
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Win_Shot_SoundSet","Win_Tail_SoundSet","Win_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Win_silencerHomeMade_SoundSet","Win_silencerHomeMadeTail_SoundSet","Win_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\winchester70\winchester70_0",1,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\winchester70\winchester70_1",1,1,1000};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,150};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
			reloadTime = 1;
			recoil = "recoil_Winchester";
			recoilProne = "recoil_Winchester_prone";
			dispersion = 0.0005;
			magazineSlot = "magazine";
		};
		class NoiseShoot
		{
			strength = 100;
			type = "shot";
		};
		class OpticsInfo: OpticsInfoRifle
		{
			discreteDistance[] = {200};
			discreteDistanceInitIndex = 0;
			distanceZoomMin = 200;
			distanceZoomMax = 200;
		};
	};
	class Winchester70: Winchester70_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Winchester700";
		descriptionShort = "$STR_cfgWeapons_Winchester701";
		model = "\dz\weapons\firearms\winchester70\winchester70.p3d";
		attachments[] = {"weaponWrap","weaponOpticsHunting","suppressorImpro"};
		itemSize[] = {10,3};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\winchester70\data\winchester70_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\winchester70\data\winchester70.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\winchester70\data\winchester70.rvmat"}},{0.7,{"DZ\weapons\firearms\winchester70\data\winchester70.rvmat"}},{0.5,{"DZ\weapons\firearms\winchester70\data\winchester70_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\winchester70\data\winchester70_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\winchester70\data\winchester70_destruct.rvmat"}}};
				};
			};
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
					overrideParticle = "weapon_shot_winch70_01";
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					positionOffset[] = {0.1,0,0};
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating = 1;
				maxOverheatingValue = 3;
				overheatingDecayInterval = 4;
				class BarrelSmoke
				{
					overrideParticle = "smoking_barrel_small";
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
	class Winchester70_Black: Winchester70
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_Winchester70_Black0";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)"};
	};
	class Winchester70_Green: Winchester70
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_Winchester70_Green0";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,CO)"};
	};
};
