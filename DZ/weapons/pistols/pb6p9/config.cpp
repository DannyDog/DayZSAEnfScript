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
	class DZ_Pistols_pb6p9
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Sounds_Weapons"};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class Mode_Safe: Mode_SemiAuto
{
	magazines[] = {};
};
class cfgWeapons
{
	class DefaultWeapon;
	class PistolCore;
	class Pistol_Base;
	class MakarovPB_Base: Pistol_Base
	{
		scope = 0;
		weight = 760;
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		modelOptics = "-";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		value = 0;
		chamberSize = 1;
		chamberedRound = "";
		magazines[] = {"Mag_MakarovPB_8Rnd"};
		chamberableFrom[] = {"Ammo_380"};
		ejectType = 1;
		recoilModifier[] = {1,1,1};
		drySound[] = {"DZ\sounds\weapons\firearms\PB6P9\PB6P9_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\ij70\Makarov_reload",0.8,1,20};
		reloadAction = "ReloadIJ70";
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Makarov_Shot_SoundSet","Makarov_Tail_SoundSet","Makarov_InteriorTail_SoundSet"};
			soundSetShotExt[] = {{"PB6P9_silencerPro_SoundSet","PB6P9_silencerTail_SoundSet","PB6P9_silencerInteriorTail_SoundSet"}};
			begin1[] = {"dz\sounds\weapons\firearms\ij70\ij70_close_0",1,1,600};
			begin2[] = {"dz\sounds\weapons\firearms\ij70\ij70_close_1",1,1,600};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
			reloadTime = 0.13;
			recoil = "recoil_ij70";
			recoilProne = "recoil_if70_prone";
			dispersion = 0.012;
			magazineSlot = "magazine";
			beginSilenced_Pro[] = {"dz\sounds\weapons\firearms\ij70\MakarovSilenced",1,1,60};
			beginSilenced_HomeMade[] = {"dz\sounds\weapons\firearms\ij70\MakarovSilenced",1,1,100};
			soundBeginExt[] = {{"beginSilenced_Pro",1},{"beginSilenced_HomeMade",1}};
		};
	};
	class MakarovPB: MakarovPB_Base
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_MakarovPB0";
		descriptionShort = "$STR_cfgWeapons_MakarovPB1";
		model = "\DZ\weapons\pistols\pb6p9\pb6p9.p3d";
		attachments[] = {"pistolMuzzle"};
		itemSize[] = {2,2};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\pistols\pb6p9\data\pb6p9.rvmat"}},{0.7,{"DZ\weapons\pistols\pb6p9\data\pb6p9.rvmat"}},{0.5,{"DZ\weapons\pistols\pb6p9\data\pb6p9_damage.rvmat"}},{0.3,{"DZ\weapons\pistols\pb6p9\data\pb6p9_damage.rvmat"}},{0.0,{"DZ\weapons\pistols\pb6p9\data\pb6p9_destruct.rvmat"}}};
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyPB6P9: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "pistol";
		model = "\dz\weapons\pistols\pb6p9\pb6p9.p3d";
	};
};
