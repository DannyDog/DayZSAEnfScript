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
	class DZ_Weapons_Firearms_M249Para
	{
		units[] = {"M249Para"};
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
	class M249_Base: Rifle_Base
	{
		scope = 0;
		weight = 7500;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {30.0,25.0};
		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_556x45","Ammo_556x45Tracer"};
		magazines[] = {"Mag_M249_Box200Rnd"};
		magazineSwitchTime = 6.5;
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\firearms\m4a1\m4_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\m4a1\m4_reload_0",0.8,1,40};
		reloadAction = "ReloadAKM";
		modes[] = {"FullAuto"};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"dz\sounds\weapons\firearms\m4a1\m4_single_1",1.7782794,1,1000};
			begin2[] = {"dz\sounds\weapons\firearms\m4a1\m4_single_2",1.7782794,1,1000};
			begin3[] = {"dz\sounds\weapons\firearms\m4a1\m4_single_3",1.7782794,1,1000};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = "60/800";
			recoil = "recoil_m249";
			recoilProne = "recoil_m249_prone";
			dispersion = 0.002;
			magazineSlot = "magazine";
			beginSilenced_Pro1[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,75};
			beginSilenced_Pro2[] = {"dz\sounds\weapons\firearms\m4a1\m4Silenced2",1,1,75};
			beginSilenced_HomeMade[] = {"ddz\sounds\weapons\firearms\m4a1\m4Silenced",1,1,150};
			soundBeginExt[] = {{"beginSilenced_Pro1",0.5,"beginSilenced_Pro2",0.5},{"beginSilenced_HomeMade",1}};
		};
		class OpticsInfo: OpticsInfoRifle{};
	};
	class M249: M249_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_M2490";
		descriptionShort = "$STR_cfgWeapons_M2491";
		model = "\dz\weapons\firearms\m249\m249.p3d";
		attachments[] = {"weaponOptics","weaponMuzzleM4","weaponHandguardM249","Att_Handguard_M249_Ris"};
		itemSize[] = {9,3};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\firearms\m249\Data\m249.rvmat"}},{0.7,{"DZ\weapons\firearms\m249\Data\m249.rvmat"}},{0.5,{"DZ\weapons\firearms\m249\Data\m249_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\m249\Data\m249_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\m249\Data\m249_destruct.rvmat"}}};
				};
			};
		};
	};
};
