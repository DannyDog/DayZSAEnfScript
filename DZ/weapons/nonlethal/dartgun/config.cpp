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
	class DZ_weapons_nonlethal_DartGun
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgWeapons
{
	class NonlethalPistol;
	class DartGun: NonlethalPistol
	{
		scope = 2;
		displayName = "$STR_cfgWeapons_DartGun0";
		descriptionShort = "$STR_cfgWeapons_DartGun1";
		model = "\dz\weapons\nonlethal\dartgun\dartgun.p3d";
		weight = 950;
		itemSize[] = {6,3};
		absorbency = 0.0;
		attachments[] = {"weaponOptics"};
		chamberedRound = "D_Syringe";
		magazines[] = {"D_Syringe_Single","Mag_Dartgun_CO2"};
		drySound[] = {"DZ\sounds\weapons\nonlethal\dartgun\Dartgun_dry",0.5,1,20};
		reloadMagazineSound[] = {"dz\sounds\weapons\bows\crossbow_reload",0.05623413,1,30};
		reloadSound[] = {"dz\sounds\weapons\bows\crossbow_magazine_reload",0.05623413,1,30};
		repairableWithKits[] = {1};
		repairCosts[] = {30.0,25.0};
		modes[] = {"Single"};
		recoilModifier[] = {1,1,1};
		modelOptics = "-";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		value = 0;
		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"Dartgun_Shot_SoundSet","Dartgun_Tail_SoundSet","Dartgun_InteriorTail_SoundSet"};
			begin1[] = {"dz\sounds\weapons\x2_dart_gun\x2dart_gun_single_1",0.8,1,20};
			begin2[] = {"dz\sounds\weapons\x2_dart_gun\x2dart_gun_single_2",0.8,1,20};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
			reloadTime = 0.7;
			recoil = "recoil_bow";
			recoilProne = "recoil_bow";
			dispersion = 0.003;
			magazineSlot = "magazine";
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"DZ\weapons\nonlethal\dartgun\data\dartgun.rvmat","DZ\weapons\nonlethal\dartgun\data\dartgun_damage.rvmat","DZ\weapons\nonlethal\dartgun\data\dartgun_destruct.rvmat"};
		};
		class NoiseShoot
		{
			strength = 10.0;
			type = "shot";
		};
	};
};
