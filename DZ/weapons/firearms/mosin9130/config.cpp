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
	class DZ_Weapons_Firearms_MosinNagant
	{
		units[] = {"Mosin9130","Mosin9130_Black","Mosin9130_Green","Mosin9130_Green_Black","Mosin9130_Black_Green"};
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
	class Mosin9130_Base: BoltActionRifle_InnerMagazine_Base
	{
		scope = 0;
		displayName = "$STR_cfgWeapons_Mosin91300";
		descriptionShort = "$STR_cfgWeapons_Mosin91301";
		animName = "Mosin9130";
		weight = 4000;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		PPDOFProperties[] = {1,0.5,20,170,4,10};
		DisplayMagazine = 0;
		WeaponLength = 1.22271;
		barrelArmor = 2.0;
		chamberSize = 5;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_762x54","Ammo_762x54Tracer","Mag_CLIP762x54_5Rnd"};
		magazines[] = {};
		ejectType = 0;
		recoilModifier[] = {1,1,1};
		swayModifier[] = {2.5,2.5,1.3};
		simpleHiddenSelections[] = {"hide_barrel"};
		drySound[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_dry",0.5,1,20};
		reloadSkips[] = {0.32,0.41,0.5,0.59,0.69,0.77};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_reloading",0.8,1,20};
		reloadSound[] = {"DZ\sounds\weapons\firearms\mosin9130\mosin_cycling",0.8,1,20};
		reloadAction = "ReloadMosinFull";
		shotAction = "ReloadMosinShort";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\mosin9130\data\mosin_9130.rvmat"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Mosin_Shot_SoundSet","Mosin_Tail_SoundSet","Mosin_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Mosin_silencerHomeMade_SoundSet","Mosin_silencerHomeMadeTail_SoundSet","Mosin_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_close_0",1,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_close_1",1,1,1000};
			begin3[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_close_2",1,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,150};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
			reloadTime = 1;
			recoil = "recoil_mosin";
			recoilProne = "recoil_mosin_prone";
			dispersion = 0.001;
			magazineSlot = "magazine";
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_mosin9130_01";
					ignoreIfSuppressed = 1;
					illuminateWorld = 1;
					positionOffset[] = {-0.03,0,0};
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
		class OpticsInfo: OpticsInfoRifle
		{
			memoryPointCamera = "eye";
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 100;
			discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
			discreteDistanceInitIndex = 0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130.rvmat"}},{0.7,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130.rvmat"}},{0.5,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130_destruct.rvmat"}}};
				};
			};
		};
	};
	class SawedoffMosin9130_Base: Mosin9130_Base
	{
		scope = 0;
		displayName = "$STR_cfgWeapons_SawedoffMosin91300";
		descriptionShort = "$STR_cfgWeapons_SawedoffMosin91301";
		animName = "Mosin9130";
		weight = 3000;
		absorbency = 0.1;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		WeaponLength = 0.52;
		chamberSize = 5;
		chamberedRound = "";
		magazines[] = {};
		chamberableFrom[] = {"Ammo_762x54","Ammo_762x54Tracer","Mag_CLIP762x54_5Rnd"};
		ejectType = 0;
		recoilModifier[] = {2,2,1};
		swayModifier[] = {1.5,1.5,1};
		DisplayMagazine = 0;
		simpleHiddenSelections[] = {"hide_barrel"};
		drySound[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_dry",0.5,1};
		reloadSkips[] = {0.32,0.41,0.5,0.59,0.69,0.77};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_reloading",0.8,1,20};
		reloadSound[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_cycling",0.8,1,20};
		reloadAction = "ReloadMosinFull";
		shotAction = "ReloadMosinShort";
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Mosin_Shot_SoundSet","Mosin_Tail_SoundSet","Mosin_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"Mosin_silencerHomeMade_SoundSet","Mosin_silencerHomeMadeTail_SoundSet","Mosin_silencerInteriorHomeMadeTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_close_0",1,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_close_1",1,1,1000};
			begin3[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_close_2",1,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,150};
			soundBeginExt[] = {{"beginSilenced_HomeMade",1}};
			reloadTime = 1;
			recoil = "recoil_mosin";
			recoilProne = "recoil_mosin_prone";
			dispersion = 0.003;
		};
		class OpticsInfo: OpticsInfo
		{
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 100;
			discreteDistance[] = {50};
			discreteDistanceInitIndex = 0;
		};
	};
	class Mosin9130: Mosin9130_Base
	{
		scope = 2;
		model = "\dz\weapons\firearms\mosin9130\mosin9130.p3d";
		itemSize[] = {10,3};
		attachments[] = {"weaponWrap","weaponOpticsMosin","suppressorImpro","weaponMuzzleMosin","weaponBayonetMosin"};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\mosin9130\data\mosin_9130_co.paa"};
	};
	class Mosin9130_Black: Mosin9130
	{
		scope = 2;
		color = "Black";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\mosin9130\data\mosin_9130_bk.rvmat"};
	};
	class Mosin9130_Green: Mosin9130
	{
		scope = 2;
		color = "Green";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,CO)"};
	};
	class Mosin9130_Camo: Mosin9130
	{
		scope = 2;
		color = "Camo";
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\mosin9130\data\mosin_nagant_camo_co.paa"};
	};
	class SawedoffMosin9130: SawedoffMosin9130_Base
	{
		scope = 2;
		model = "\dz\weapons\firearms\mosin9130\mosin_sawn.p3d";
		attachments[] = {"weaponOpticsMosin"};
		itemSize[] = {5,2};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\mosin9130\data\mosin_sawn_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\mosin9130\data\mosin_sawn.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\mosin9130\Data\mosin_sawn.rvmat"}},{0.7,{"DZ\weapons\firearms\mosin9130\Data\mosin_sawn.rvmat"}},{0.5,{"DZ\weapons\firearms\mosin9130\Data\mosin_sawn_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\mosin9130\Data\mosin_sawn_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\mosin9130\Data\mosin_sawn_destruct.rvmat"}}};
				};
			};
		};
	};
	class SawedoffMosin9130_Black: SawedoffMosin9130
	{
		scope = 2;
		color = "Black";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\mosin9130\data\mosin_sawn_bk.rvmat"};
	};
	class SawedoffMosin9130_Green: SawedoffMosin9130
	{
		scope = 2;
		color = "Green";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.35,0.36,0.28,1.0,CO)"};
	};
	class SawedoffMosin9130_Camo: SawedoffMosin9130
	{
		scope = 2;
		color = "Camo";
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\mosin9130\data\mosin_nagant_camo_co.paa"};
	};
};
