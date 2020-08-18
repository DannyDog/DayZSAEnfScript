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
	class Rifle_Base;
	class ScoutBase: Rifle_Base
	{
		scope = 0;
		animName = "cz527";
		weight = 2720;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {30.0,25.0};
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_308Win","Ammo_308WinTracer"};
		magazines[] = {"Mag_Scout_5Rnd"};
		magazineSwitchTime = 0.38;
		ejectType = 0;
		drySound[] = {"dz\sounds\weapons\firearms\mosin9130\mosin_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\cz527\cz527_reload_0",0.8,1,20};
		reloadSound[] = {"dz\sounds\weapons\firearms\cz527\cz527_cycling_0",0.8,1,20};
		reloadAction = "Reloadcz527";
		shotAction = "Reloadcz527Shot";
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		dispersionModifier = -0.00025;
		dexterityModifier = -0.2;
		recoilModifier[] = {1,1,1};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"CR527_Shot_SoundSet","CR527_Tail_SoundSet","CR527_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"CR527_silencerPro_SoundSet","CR527_silencerTail_SoundSet","CR527_silencerInteriorTail_SoundSet"},{"CR527_silencerHomeMade_SoundSet","CR527_silencerHomeMadeTail_SoundSet","CR527_silencerInteriorTail_SoundSet"}};
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
		class OpticsInfo: OpticsInfoRifle
		{
			modelOptics = "-";
			distanceZoomMin = 100;
			distanceZoomMax = 100;
		};
	};
	class Scout: ScoutBase
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_Scout0";
		descriptionShort = "$STR_cfgWeapons_Scout1";
		model = "\dz\weapons\firearms\scout\scout.p3d";
		attachments[] = {"weaponWrap","weaponOpticsHunting","weaponOptics","suppressorImpro"};
		itemSize[] = {9,3};
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\scout\data\scout_blk_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\firearms\scout\data\scout.rvmat"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\scout\data\scout.rvmat"}},{0.7,{"DZ\weapons\firearms\scout\data\scout.rvmat"}},{0.5,{"DZ\weapons\firearms\scout\data\scout_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\scout\data\scout_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\scout\data\scout_destruct.rvmat"}}};
				};
			};
		};
	};
	class Scout_Black: Scout
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_Scout_Black0";
		color = "Black";
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\scout\data\scout_co.paa"};
	};
	class Scout_Green: Scout
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_Scout_Green0";
		color = "Green";
		hiddenSelectionsTextures[] = {"dz\weapons\firearms\scout\data\scout_grn_co.paa"};
	};
};
