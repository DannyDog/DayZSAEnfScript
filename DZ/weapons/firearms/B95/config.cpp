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
	class DZ_Weapons_Firearms_B95
	{
		units[] = {"b95","b95_Black","b95_Green"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Weapons_Firearms"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class Muzzle_Base;
class OpticsInfoRifle;
class cfgWeapons
{
	class Rifle_Base;
	class B95_Base: Rifle_Base
	{
		scope = 0;
		weight = 2820;
		itemSize[] = {9,3};
		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_308Win","Ammo_308WinTracer","Mag_308WinSnaploader_2Rnd"};
		magazines[] = {};
		DisplayMagazine = 0;
		PPDOFProperties[] = {1,0.5,50,160,4,10};
		WeaponLength = 0.85;
		muzzles[] = {"this","SecondMuzzle"};
		ejectType = 3;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {2.2,2.2,1.2};
		drySound[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_dry",0.5,1,20};
		reloadAction = "ReloadB95";
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\B95\b95_reload2",0.8,1,20};
		reloadSound[] = {"",0.05623413,1,20};
		hiddenSelections[] = {"camoGround"};
		simpleHiddenSelections[] = {"bullet","bullet2","hide_barrel"};
		modes[] = {"Single","Burst"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"B95_Shot_SoundSet","B95_Tail_SoundSet","B95_InteriorTail_SoundSet"};
			reloadTime = 0.1;
			dispersion = 0.001;
			magazineSlot = "magazine";
		};
		class Burst: Mode_Burst
		{
			soundSetShot[] = {"B95_Shot_SoundSet","B95_Tail_SoundSet","B95_InteriorTail_SoundSet"};
			reloadTime = 0.1;
			dispersion = 0.001;
			magazineSlot = "magazine";
		};
		class SecondMuzzle: Muzzle_Base
		{
			chamberSize = 1;
			muzzlePos = "usti hlavne_2";
			muzzleEnd = "konec hlavne_2";
			cartridgePos = "nabojnicestart_2";
			cartridgeVel = "nabojniceend_2";
			modes[] = {"Single","Burst"};
			magazines[] = {};
			chamberableFrom[] = {"Ammo_308Win","Ammo_308WinTracer","Mag_308WinSnaploader_2Rnd"};
			barrelArmor = 1000.0;
			initSpeedMultiplier = 1.0;
			irDistance = 0.0;
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			drySound[] = {"dz\sounds\weapons\shotguns\Izh43\izh43_dry",0.005623413,1};
			soundBullet[] = {};
			class Single: Mode_SemiAuto
			{
				soundSetShot[] = {"B95_Shot_SoundSet","B95_Tail_SoundSet","B95_InteriorTail_SoundSet"};
				reloadTime = 0.1;
				dispersion = 0.001;
				magazineSlot = "magazine";
			};
			class Burst: Mode_Burst
			{
				soundSetShot[] = {"B95_Shot_SoundSet","B95_Tail_SoundSet","B95_InteriorTail_SoundSet"};
				reloadTime = 0.1;
				dispersion = 0.001;
				magazineSlot = "magazine";
			};
			class OpticsInfo: OpticsInfoRifle
			{
				memoryPointCamera = "eye";
				modelOptics = "-";
				distanceZoomMin = 50;
				distanceZoomMax = 200;
				discreteDistance[] = {50,100,200};
				discreteDistanceInitIndex = 0;
			};
		};
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera = "eye";
			modelOptics = "-";
			distanceZoomMin = 50;
			distanceZoomMax = 200;
			discreteDistance[] = {50,100,200};
			discreteDistanceInitIndex = 0;
		};
	};
	class B95: B95_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_B950";
		descriptionShort = "$STR_cfgWeapons_B951";
		model = "\dz\weapons\firearms\B95\b95.p3d";
		attachments[] = {"weaponWrap","weaponOpticsHunting"};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\B95\data\b95_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\B95\data\b95.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\B95\Data\b95.rvmat"}},{0.7,{"DZ\weapons\firearms\B95\Data\b95.rvmat"}},{0.5,{"DZ\weapons\firearms\B95\Data\b95_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\B95\Data\b95_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\B95\Data\b95_destruct.rvmat"}}};
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
					muzzleIndex = 0;
				};
				class SmokeCloud_2
				{
					overrideParticle = "weapon_shot_winded_smoke";
					overridePoint = "Usti hlavne_2";
					muzzleIndex = 1;
				};
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_winch70_01";
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
				};
				class MuzzleFlash_2
				{
					overrideParticle = "weapon_shot_winch70_01";
					overridePoint = "Usti hlavne_2";
					illuminateWorld = 1;
					muzzleIndex = 1;
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
	class B95_Black: B95
	{
		scope = 2;
		color = "Black";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\B95\data\b95_painted.rvmat"};
	};
	class B95_Green: B95
	{
		scope = 2;
		color = "Green";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\B95\data\b95_painted.rvmat"};
	};
};
