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
	class DZ_Pistols_Derringer
	{
		units[] = {"Derringer_Black","Derringer_Grey","Derringer_Pink"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Pistols"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons
{
	class Pistol_Base;
	class Derringer_Base: Pistol_Base
	{
		scope = 0;
		displayName = "$STR_cfgWeapons_Derringer_Base0";
		descriptionShort = "$STR_cfgWeapons_Derringer_Base1";
		model = "\dz\weapons\pistols\derringer\derringer.p3d";
		animName = "Derringer";
		weight = 800;
		itemSize[] = {2,1};
		absorbency = 0.0;
		repairableWithKits[] = {1};
		repairCosts[] = {25.0};
		attachments[] = {};
		modelOptics = "-";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		value = 0;
		chamberSize = 2;
		chamberedRound = "";
		magazines[] = {};
		chamberableFrom[] = {"Ammo_45ACP"};
		ejectType = 3;
		recoilModifier[] = {1,1,1};
		drySound[] = {"dz\sounds\weapons\firearms\FNX45\FNX_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\firearms\derringer\deringer_reload_full",0.8,1,20};
		reloadSound[] = {"dz\sounds\weapons\firearms\derringer\deringer_reload_short",0.8,1,20};
		shotAction = "reloadDerringer";
		reloadAction = "reloadDerringerFull";
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsMaterials[] = {"dz\weapons\pistols\derringer\data\derringer.rvmat"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Derringer_Shot_SoundSet","Derringer_Tail_SoundSet","Derringer_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\firearms\derringer\deringer_single_0",1,1,600};
			begin2[] = {"dz\sounds\weapons\firearms\derringer\deringer_single_1",1,1,600};
			soundBegin[] = {"begin1",0.33333,"begin2",0.33333,"begin2",0.33333};
			reloadTime = 0.5;
			recoil = "recoil_derringer";
			recoilProne = "recoil_derringer_prone";
			dispersion = 0.01;
			magazineSlot = "magazine";
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\pistols\derringer\data\derringer.rvmat","DZ\weapons\pistols\derringer\data\derringer_damage.rvmat","DZ\weapons\pistols\derringer\data\derringer_destruct.rvmat"};
		};
	};
	class Derringer_Black: Derringer_Base
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_Derringer_Black0";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)"};
	};
	class Derringer_Pink: Derringer_Base
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_Derringer_Pink0";
		hiddenSelectionsTextures[] = {"dz\weapons\pistols\derringer\data\derringer_pink_co.paa"};
	};
	class Derringer_Grey: Derringer_Base
	{
		scope = 2;
		descriptionShort = "$STR_cfgWeapons_Derringer_Grey0";
		hiddenSelectionsTextures[] = {"dz\weapons\pistols\derringer\data\derringer_grey_co.paa"};
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
