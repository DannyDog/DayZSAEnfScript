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
	class DZ_Weapons_Firearms_IZH18
	{
		units[] = {"ShotgunIzh43","ShotgunIzh43_Sawedoff"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Single;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoRifle;
class cfgWeapons
{
	class Rifle_Base;
	class Izh18_Base: Rifle_Base
	{
		scope = 0;
		weight = 3200;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		PPDOFProperties[] = {1,0.5,10,170,4,10};
		ironsightsExcludingOptics[] = {"HuntingOptic"};
		DisplayMagazine = 0;
		WeaponLength = 0.981055;
		barrelArmor = 1.875;
		initSpeedMultiplier = 1.05;
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_762x39","Ammo_762x39Tracer"};
		magazines[] = {};
		ejectType = 3;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {2.25,2.25,1.2};
		drySound[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\izh18\izh18_reload",0.8,1,20};
		reloadSound[] = {"",0.05623413,1,20};
		reloadAction = "ReloadIZH18";
		shotAction = "";
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Single: Mode_Single
		{
			soundSetShot[] = {"IZH18_Shot_SoundSet","IZH18_Tail_SoundSet","IZH18_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"IZH18_silencerHomeMade_SoundSet","IZH18_silencerHomeMadeTail_SoundSet","IZH18_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\izh18\izh18_shot_0",1,1,800};
			begin2[] = {"dz\sounds\weapons\firearms\izh18\izh18_shot_1",1,1,800};
			soundBegin[] = {"begin1",0.56,"begin2",0.5};
			reloadTime = 1;
			recoil = "recoil_izh18";
			recoilProne = "recoil_izh18_prone";
			dispersion = 0.002;
			magazineSlot = "magazine";
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\AK101\akSilenced",1,1,300};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					overridePoint = "Usti hlavne";
				};
				class ChamberFlash
				{
					overridePoint = "dust_point";
					overrideParticle = "weapon_dust_izh18_01";
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
			memoryPointCamera = "eye";
			discreteDistance[] = {200};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 200;
			distanceZoomMax = 200;
		};
	};
	class Izh18: Izh18_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Izh180";
		descriptionShort = "$STR_cfgWeapons_Izh181";
		model = "\dz\weapons\firearms\Izh18\Izh18.p3d";
		attachments[] = {"weaponWrap","suppressorImpro"};
		itemSize[] = {9,3};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\Izh18\data\Izh18_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\Izh18\data\Izh18.rvmat"};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_izh18_01";
					ignoreIfSuppressed = 1;
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\Izh18\data\Izh18.rvmat"}},{0.7,{"DZ\weapons\firearms\Izh18\data\Izh18.rvmat"}},{0.5,{"DZ\weapons\firearms\Izh18\data\Izh18_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\Izh18\data\Izh18_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\Izh18\data\Izh18_destruct.rvmat"}}};
				};
			};
		};
	};
	class SawedoffIzh18: Izh18
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_SawedoffIzh180";
		descriptionShort = "$STR_cfgWeapons_SawedoffIzh181";
		model = "\dz\weapons\firearms\Izh18\Izh18_sawedoff.p3d";
		itemSize[] = {5,2};
		weight = 2800;
		attachments[] = {};
		recoilModifier[] = {1,1,1};
		swayModifier[] = {1.5,1.5,1};
		firespreadangle = 3;
		WeaponLength = 0.41;
		initSpeedMultiplier = 0.75;
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"IZH18_Shot_SoundSet","IZH18_Tail_SoundSet","IZH18_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"IZH18_silencerHomeMade_SoundSet","IZH18_silencerHomeMadeTail_SoundSet","IZH18_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_0",1.7782794,1,1000};
			begin2[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_1",1.7782794,1,1000};
			begin3[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_close_2",1.7782794,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 1;
			dispersion = 0.045;
			recoil = "recoil_izh18sawedoff";
			recoilProne = "recoil_izh18sawedoff";
		};
	};
};
