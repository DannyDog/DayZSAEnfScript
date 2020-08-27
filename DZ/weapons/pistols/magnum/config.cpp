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
	class DZ_Pistols_Magnum
	{
		units[] = {"magnum"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class Muzzle_Base;
class OpticsInfoPistol;
class cfgWeapons
{
	class Pistol_Base;
	class Magnum_Base: Pistol_Base
	{
		scope = 0;
		weight = 1400;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {30.0,25.0};
		PPDOFProperties[] = {1,0.9,10,250,4,10};
		WeaponLength = 0.63;
		barrelArmor = 1.758;
		initSpeedMultiplier = 1.17;
		DisplayMagazine = 0;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {};
		chamberableFrom[] = {"Ammo_357","Mag_357Speedloader_6Rnd"};
		ejectType = 8;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {1.15,1.15,0.8};
		drySound[] = {"DZ\sounds\weapons\firearms\magnum\Magnum_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\magnum\magnum_reload2",0.8,1,20};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Magnum_Shot_SoundSet","Magnum_Tail_SoundSet","Magnum_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\firearms\magnum\magnum_single_2",1,1,700};
			begin2[] = {"dz\sounds\weapons\firearms\magnum\magnum_single_1",1,1,700};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 0.25;
			dispersion = 0.009;
			magazineSlot = "magazine";
		};
		class OpticsInfoMagnumBase: OpticsInfoPistol
		{
			memoryPointCamera = "eye";
			discreteDistance[] = {25};
			discreteDistanceInitIndex = 0;
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 100;
		};
		class OpticsInfo: OpticsInfoMagnumBase{};
		muzzles[] = {"this","SecondMuzzle","ThirdMuzzle","FourthMuzzle","FifthMuzzle","SixthMuzzle"};
		class SecondMuzzle: Muzzle_Base
		{
			chamberSize = 1;
			muzzlePos = "usti hlavne";
			muzzleEnd = "konec hlavne";
			cartridgePos = "nabojnicestart_2";
			cartridgeVel = "nabojniceend_2";
			modes[] = {"Single"};
			magazines[] = {};
			chamberableFrom[] = {"Ammo_357"};
			barrelArmor = 1.758;
			drySound[] = {"DZ\sounds\weapons\firearms\magnum\Magnum_dry",0.5,1,20};
			soundBullet[] = {};
			class Single: Mode_SemiAuto
			{
				soundSetShot[] = {"Magnum_Shot_SoundSet","Magnum_Tail_SoundSet","Magnum_InteriorTail_SoundSet"};
				begin1[] = {"dz\sounds\weapons\firearms\magnum\magnum_single_2",1,1,700};
				begin2[] = {"dz\sounds\weapons\firearms\magnum\magnum_single_1",1,1,700};
				soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
				reloadTime = 0.25;
				dispersion = 0.009;
				magazineSlot = "magazine";
			};
			class OpticsInfo: OpticsInfoMagnumBase{};
		};
		class ThirdMuzzle: SecondMuzzle
		{
			cartridgePos = "nabojnicestart_3";
			cartridgeVel = "nabojniceend_3";
		};
		class FourthMuzzle: SecondMuzzle
		{
			cartridgePos = "nabojnicestart_4";
			cartridgeVel = "nabojniceend_4";
		};
		class FifthMuzzle: SecondMuzzle
		{
			cartridgePos = "nabojnicestart_5";
			cartridgeVel = "nabojniceend_5";
		};
		class SixthMuzzle: SecondMuzzle
		{
			cartridgePos = "nabojnicestart_6";
			cartridgeVel = "nabojniceend_6";
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
	class Magnum: Magnum_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Magnum0";
		descriptionShort = "$STR_cfgWeapons_Magnum1";
		model = "\dz\weapons\pistols\magnum\magnum.p3d";
		itemSize[] = {4,2};
		attachments[] = {"RevolverCylinder","RevolverEjector"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.7,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.5,{"DZ\weapons\pistols\magnum\data\magnum_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\magnum\data\magnum_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\magnum\data\magnum_destruct.rvmat"}}};
				};
			};
		};
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class Magnum_Cylinder: Inventory_Base
	{
		scope = 2;
		model = "\dz\weapons\pistols\magnum\proxy\magnum_cylinder.p3d";
		weight = 1;
		inventorySlot[] = {"RevolverCylinder"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.7,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.5,{"DZ\weapons\pistols\magnum\data\magnum_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\magnum\data\magnum_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\magnum\data\magnum_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class Rotate_Cylinder
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class Rotate_Cylinder_Back
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 0;
			};
			class bullet
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_2
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_3
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_4
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_5
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_6
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_nose
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_nose_2
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_nose_3
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_nose_4
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_nose_5
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class bullet_nose_6
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
	};
	class Magnum_Ejector: Inventory_Base
	{
		scope = 2;
		model = "\dz\weapons\pistols\magnum\proxy\magnum_ejector.p3d";
		weight = 1;
		inventorySlot[] = {"RevolverEjector"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.7,{"DZ\weapons\pistols\magnum\data\magnum.rvmat"}},{0.5,{"DZ\weapons\pistols\magnum\data\magnum_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\magnum\data\magnum_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\magnum\data\magnum_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class Rotate_Ejector
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxymagnum: ProxyAttachment
	{
		scope = 2;
	};
	class Proxymagnum_cylinder: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "RevolverCylinder";
		model = "\dz\weapons\pistols\magnum\proxy\magnum_cylinder.p3d";
	};
	class Proxymagnum_ejector: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "RevolverEjector";
		model = "\dz\weapons\pistols\magnum\proxy\magnum_ejector.p3d";
	};
};
