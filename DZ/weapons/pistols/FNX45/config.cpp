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
	class DZ_Pistols_FNX45
	{
		units[] = {"FNX45"};
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
	class FNX45_Base: Pistol_Base
	{
		scope = 0;
		weight = 950;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		PPDOFProperties[] = {1,0.5,10,250,4,10};
		ironsightsExcludingOptics[] = {"FNP45_MRDSOptic"};
		WeaponLength = 0.634148;
		barrelArmor = 1.7;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"Mag_FNX45_15Rnd"};
		chamberableFrom[] = {"Ammo_45ACP"};
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {1.3,1.3,0.8};
		drySound[] = {"dz\sounds\weapons\firearms\FNX45\FNX45_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\FNX45\FNX45_reload",0.8,1,20};
		modes[] = {"SemiAuto"};
		class SemiAuto: Mode_SemiAuto
		{
			soundSetShot[] = {"FNX45_Shot_SoundSet","FNX45_Tail_SoundSet","FNX45_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"FNX45_silencerPro_SoundSet","FNX45_silencerTail_SoundSet","FNX45_silencerInteriorTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\FNX45\FNX45_single_1",1,1,600};
			begin2[] = {"dz\sounds\weapons\firearms\FNX45\FNX45_single_2",1,1,600};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 0.125;
			recoil = "recoil_fnx";
			recoilProne = "recoil_fnx_prone";
			dispersion = 0.003;
			magazineSlot = "magazine";
			beginSilenced_Pro[] = {"dz\sounds\weapons\firearms\colt1911\1911Silenced",1,1,60};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\colt1911\1911Silenced",1,1,100};
			soundBeginExt[] = {{"beginSilenced_Pro",1},{"beginSilenced_HomeMade",1}};
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
	class FNX45: FNX45_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_FNX450";
		descriptionShort = "$STR_cfgWeapons_FNX451";
		model = "\dz\weapons\pistols\fnx45\fnp45.p3d";
		attachments[] = {"pistolOptics","pistolFlashlight","pistolMuzzle"};
		itemSize[] = {3,2};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\fnx45\data\herstal45.rvmat"}},{0.7,{"DZ\weapons\pistols\fnx45\data\herstal45.rvmat"}},{0.5,{"DZ\weapons\pistols\fnx45\data\herstal45_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\fnx45\data\herstal45_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\fnx45\data\herstal45_destruct.rvmat"}}};
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
	class FNX45_arrow: FNX45
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_FNX450";
		descriptionShort = "$STR_cfgWeapons_FNX451";
		model = "\dz\weapons\pistols\fnx45\fnp45.p3d";
		attachments[] = {"pistolMuzzle","pistolOptics","pistolFlashlight"};
		itemSize[] = {3,2};
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"Mag_FNX45_15Rnd"};
		chamberableFrom[] = {"Ammo_ArrowComposite"};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlashForward
				{
					ignoreIfSuppressed = 1;
					overrideParticle = "weapon_shot_fnx_01";
				};
				class ChamberSmoke
				{
					overrideParticle = "weapon_shot_chamber_smoke";
					overridePoint = "Nabojnicestart";
					overrideDirectionPoint = "Nabojniceend";
				};
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
	class ProxyFNP45: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "pistol";
		model = "\dz\weapons\pistols\fnx45\fnp45.p3d";
	};
};
