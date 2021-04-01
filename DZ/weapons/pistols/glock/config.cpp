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
	class DZ_Pistols_Glock
	{
		units[] = {"Glock19"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class Pistol_Base;
	class Glock19_Base: Pistol_Base
	{
		scope = 0;
		weight = 1000;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		PPDOFProperties[] = {1,0.5,10,250,4,10};
		WeaponLength = 0.63;
		barrelArmor = 1.5;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"Mag_Glock_15Rnd"};
		chamberableFrom[] = {"Ammo_9x19"};
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {1.1,1.1,0.8};
		drySound[] = {"DZ\sounds\weapons\firearms\glock19\Glock19_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\FNX45\FNX45_reload",0.8,1,20};
		reloadAction = "ReloadGlock";
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Glock19_Shot_SoundSet","Glock19_Tail_SoundSet","Glock19_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Glock19_silencerPro_SoundSet","Glock19_silencerTail_SoundSet","Glock19_silencerInteriorTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\CZ75\CZ75_single_0",1,1,600};
			begin2[] = {"dz\sounds\weapons\firearms\CZ75\CZ75_single_1",1,1,600};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin1",0.33333,"begin2",0.33333};
			beginSilenced_Pro1[] = {"dz\sounds\weapons\firearms\CZ75\cz75Silenced",1,1,60};
			beginSilenced_Pro2[] = {"dz\sounds\weapons\firearms\CZ75\cz75Silenced2",1,1,60};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\CZ75\cz75Silenced",1,1,100};
			soundBeginExt[] = {{"beginSilenced_Pro1",0.5,"beginSilenced_Pro2",0.5},{"beginSilenced_HomeMade",1}};
			reloadTime = 0.13;
			recoil = "recoil_Glock";
			recoilProne = "recoil_Glock_prone";
			dispersion = 0.003;
			magazineSlot = "magazine";
		};
		class NoiseShoot
		{
			strength = 50;
			type = "shot";
		};
		class OpticsInfo: OpticsInfoPistol
		{
			memoryPointCamera = "eye";
			discreteDistance[] = {25};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 100;
		};
	};
	class Glock19: Glock19_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Glock190";
		descriptionShort = "$STR_cfgWeapons_Glock191";
		model = "\dz\weapons\pistols\glock\Glock19.p3d";
		attachments[] = {"pistolOptics","pistolFlashlight","pistolMuzzle"};
		itemSize[] = {3,2};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\glock\data\glock19.rvmat"}},{0.7,{"DZ\weapons\pistols\glock\data\glock19.rvmat"}},{0.5,{"DZ\weapons\pistols\glock\data\glock19_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\glock\data\glock19_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\glock\data\glock19_destruct.rvmat"}}};
				};
			};
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlashForward
				{
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					overrideParticle = "weapon_shot_fnx_01";
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
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyGlock: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "pistol";
		model = "\dz\weapons\pistols\glock\Glock19.p3d";
	};
};
