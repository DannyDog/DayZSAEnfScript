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
	class DZ_Animals_ursus_arctos
	{
		units[] = {"Animal_UrsusArctos"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Animals","DZ_Data_Bliss","DZ_AI_Bliss","DZ_Weapons_Melee"};
	};
};
class CfgAmmo
{
	class Bullet_Base;
	class MeleeDamage;
	class MeleeBear: MeleeDamage
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.85;
			class Health
			{
				damage = 25;
			};
			class Blood
			{
				damage = 110;
			};
			class Shock
			{
				damage = 35;
			};
			additionAnimalMeleeMultiplier = 5;
		};
		soundGroundSoft1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_01",0.5,1,60};
		soundGroundSoft2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_02",0.5,1,60};
		soundGroundSoft3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_03",0.5,1,60};
		soundGroundSoft4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_04",0.5,1,60};
		soundGroundSoft5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_05",0.5,1,60};
		soundGroundSoft6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_06",0.5,1,60};
		soundGroundSoft7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_07",0.5,1,60};
		soundGroundSoft8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_08",0.5,1,60};
		soundGroundHard1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_01",0.5,1,80};
		soundGroundHard2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_02",0.5,1,80};
		soundGroundHard3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_03",0.5,1,80};
		soundGroundHard4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_04",0.5,1,80};
		soundGroundHard5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_05",0.5,1,80};
		soundGroundHard6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_06",0.5,1,80};
		soundGroundHard7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_07",0.5,1,80};
		soundGroundHard8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_08",0.5,1,80};
		soundMetal1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",0.5,1,80};
		soundMetal2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",0.5,1,80};
		soundMetal3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",0.5,1,80};
		soundMetal4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",0.5,1,80};
		soundMetal5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",0.5,1,80};
		soundMetal6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",0.5,1,80};
		soundMetal7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",0.5,1,80};
		soundMetal8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",0.5,1,80};
		soundHitGlass1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_01",0.5,1,100};
		soundHitGlass2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_02",0.5,1,100};
		soundHitGlass3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_03",0.5,1,100};
		soundHitGlass4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_04",0.5,1,100};
		soundHitGlass5[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_05",0.5,1,100};
		soundHitGlass6[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_06",0.5,1,100};
		soundGlassArmored1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_01",0.5,1,60};
		soundGlassArmored2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_02",0.5,1,60};
		soundGlassArmored3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_03",0.5,1,60};
		soundGlassArmored4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_04",0.5,1,60};
		soundGlassArmored5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_05",0.5,1,60};
		soundGlassArmored6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_06",0.5,1,60};
		soundVehiclePlate1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",0.5,1,80};
		soundVehiclePlate2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",0.5,1,80};
		soundVehiclePlate3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",0.5,1,80};
		soundVehiclePlate4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",0.5,1,80};
		soundVehiclePlate5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",0.5,1,80};
		soundVehiclePlate6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",0.5,1,80};
		soundVehiclePlate7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",0.5,1,80};
		soundVehiclePlate8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",0.5,1,80};
		soundWood1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_01",0.5,1,80};
		soundWood2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_02",0.5,1,80};
		soundWood3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_03",0.5,1,80};
		soundWood4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_04",0.5,1,80};
		soundWood5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_05",0.5,1,80};
		soundWood6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_06",0.5,1,80};
		soundWood7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_07",0.5,1,80};
		soundWood8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_08",0.5,1,80};
		soundHitBody1[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_1",0.56234133,1,60};
		soundHitBody2[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_2",0.56234133,1,60};
		soundHitBody3[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_3",0.56234133,1,60};
		soundHitBody4[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_4",0.56234133,1,60};
		soundHitBody5[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_5",0.56234133,1,60};
		soundHitBody6[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_6",0.56234133,1,60};
		soundHitBuilding1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",0.5,1,60};
		soundHitBuilding2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",0.5,1,60};
		soundHitBuilding3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",0.5,1,60};
		soundHitBuilding4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",0.5,1,60};
		soundHitBuilding5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",0.5,1,60};
		soundHitBuilding6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",0.5,1,60};
		soundHitBuilding7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",0.5,1,60};
		soundHitBuilding8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",0.5,1,60};
		soundHitFoliage1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_01",0.5,1,20};
		soundHitFoliage2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_02",0.5,1,20};
		soundHitFoliage3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_03",0.5,1,20};
		soundHitFoliage4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_04",0.5,1,20};
		soundPlastic1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_01",0.35,1,70};
		soundPlastic2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_02",0.35,1,70};
		soundPlastic3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_03",0.35,1,70};
		soundPlastic4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_04",0.35,1,70};
		soundConcrete1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",0.5,1,70};
		soundConcrete2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",0.5,1,70};
		soundConcrete3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",0.5,1,70};
		soundConcrete4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",0.5,1,70};
		soundConcrete5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",0.5,1,70};
		soundConcrete6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",0.5,1,70};
		soundConcrete7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",0.5,1,70};
		soundConcrete8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",0.5,1,70};
		soundRubber1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_01",0.5,1,50};
		soundRubber2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_02",0.5,1,50};
		soundRubber3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_03",0.5,1,50};
		soundRubber4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_04",0.5,1,50};
		soundWater1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_01",0.5,1,40};
		soundWater2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_02",0.5,1,40};
		soundWater3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_03",0.5,1,40};
		hitGroundSoft[] = {"soundGroundSoft1",0.2,"soundGroundSoft2",0.2,"soundGroundSoft3",0.1,"soundGroundSoft4",0.1,"soundGroundSoft5",0.1,"soundGroundSoft6",0.1,"soundGroundSoft7",0.1,"soundGroundSoft8",0.1};
		hitGroundHard[] = {"soundGroundHard1",0.2,"soundGroundHard2",0.2,"soundGroundHard3",0.1,"soundGroundHard4",0.1,"soundGroundHard5",0.1,"soundGroundHard6",0.1,"soundGroundHard7",0.1,"soundGroundHard8",0.1};
		hitMan[] = {"soundHitBody1",0.166,"soundHitBody2",0.166,"soundHitBody3",0.166,"soundHitBody4",0.166,"soundHitBody5",0.166,"soundHitBody6",0.17};
		hitArmor[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitBuilding[] = {"soundHitBuilding1",0.2,"soundHitBuilding2",0.2,"soundHitBuilding3",0.1,"soundHitBuilding4",0.1,"soundHitBuilding5",0.1,"soundHitBuilding6",0.1,"soundHitBuilding7",0.1,"soundHitBuilding8",0.1};
		hitFoliage[] = {"soundHitFoliage1",0.25,"soundHitFoliage2",0.25,"soundHitFoliage3",0.25,"soundHitFoliage4",0.25};
		hitWood[] = {"soundWood1",0.125,"soundWood2",0.125,"soundWood3",0.125,"soundWood4",0.125,"soundWood5",0.125,"soundWood6",0.125,"soundWood7",0.125,"soundWood8",0.125};
		hitGlass[] = {"soundHitGlass1",0.166,"soundHitGlass2",0.166,"soundHitGlass3",0.167,"soundHitGlass4",0.167,"soundHitGlass5",0.167,"soundHitGlass6",0.167};
		hitGlassArmored[] = {"soundGlassArmored1",0.166,"soundGlassArmored2",0.166,"soundGlassArmored3",0.167,"soundGlassArmored4",0.167,"soundGlassArmored5",0.167,"soundGlassArmored6",0.167};
		hitConcrete[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitRubber[] = {"soundRubber1",0.25,"soundRubber2",0.25,"soundRubber3",0.25,"soundRubber4",0.25};
		hitPlastic[] = {"soundPlastic1",0.25,"soundPlastic2",0.25,"soundPlastic3",0.25,"soundPlastic4",0.25};
		hitDefault[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitMetal[] = {"soundMetal1",0.125,"soundMetal2",0.125,"soundMetal3",0.125,"soundMetal4",0.125,"soundMetal5",0.125,"soundMetal6",0.125,"soundMetal7",0.125,"soundMetal8",0.125};
		hitMetalplate[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitWater[] = {"soundWater1",0.333,"soundWater2",0.333,"soundWater3",0.333};
	};
	class MeleeBear_Heavy: MeleeBear
	{
		hitAnimation = 1;
		soundGroundSoft1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_01",1,1,60};
		soundGroundSoft2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_02",1,1,60};
		soundGroundSoft3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_03",1,1,60};
		soundGroundSoft4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_04",1,1,60};
		soundGroundSoft5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_05",1,1,60};
		soundGroundSoft6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_06",1,1,60};
		soundGroundSoft7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_07",1,1,60};
		soundGroundSoft8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_08",1,1,60};
		soundGroundHard1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_01",1,1,80};
		soundGroundHard2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_02",1,1,80};
		soundGroundHard3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_03",1,1,80};
		soundGroundHard4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_04",1,1,80};
		soundGroundHard5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_05",1,1,80};
		soundGroundHard6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_06",1,1,80};
		soundGroundHard7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_07",1,1,80};
		soundGroundHard8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_08",1,1,80};
		soundMetal1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",1,1,80};
		soundMetal2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",1,1,80};
		soundMetal3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",1,1,80};
		soundMetal4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",1,1,80};
		soundMetal5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",1,1,80};
		soundMetal6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",1,1,80};
		soundMetal7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",1,1,80};
		soundMetal8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",1,1,80};
		soundHitGlass1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_01",1,1,100};
		soundHitGlass2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_02",1,1,100};
		soundHitGlass3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_03",1,1,100};
		soundHitGlass4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_04",1,1,100};
		soundHitGlass5[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_05",1,1,100};
		soundHitGlass6[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_06",1,1,100};
		soundGlassArmored1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_01",1,1,60};
		soundGlassArmored2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_02",1,1,60};
		soundGlassArmored3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_03",1,1,60};
		soundGlassArmored4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_04",1,1,60};
		soundGlassArmored5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_05",1,1,60};
		soundGlassArmored6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_06",1,1,60};
		soundVehiclePlate1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",1,1,80};
		soundVehiclePlate2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",1,1,80};
		soundVehiclePlate3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",1,1,80};
		soundVehiclePlate4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",1,1,80};
		soundVehiclePlate5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",1,1,80};
		soundVehiclePlate6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",1,1,80};
		soundVehiclePlate7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",1,1,80};
		soundVehiclePlate8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",1,1,80};
		soundWood1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_01",1,1,80};
		soundWood2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_02",1,1,80};
		soundWood3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_03",1,1,80};
		soundWood4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_04",1,1,80};
		soundWood5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_05",1,1,80};
		soundWood6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_06",1,1,80};
		soundWood7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_07",1,1,80};
		soundWood8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_08",1,1,80};
		soundHitBody1[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_1",0.56234133,1,60};
		soundHitBody2[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_2",0.56234133,1,60};
		soundHitBody3[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_3",0.56234133,1,60};
		soundHitBody4[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_4",0.56234133,1,60};
		soundHitBody5[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_5",0.56234133,1,60};
		soundHitBody6[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_6",0.56234133,1,60};
		soundHitBuilding1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",1,1,60};
		soundHitBuilding2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",1,1,60};
		soundHitBuilding3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",1,1,60};
		soundHitBuilding4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",1,1,60};
		soundHitBuilding5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",1,1,60};
		soundHitBuilding6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",1,1,60};
		soundHitBuilding7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",1,1,60};
		soundHitBuilding8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",1,1,60};
		soundHitFoliage1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_01",1,1,20};
		soundHitFoliage2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_02",1,1,20};
		soundHitFoliage3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_03",1,1,20};
		soundHitFoliage4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_04",1,1,20};
		soundPlastic1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_01",0.70794576,1,70};
		soundPlastic2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_02",0.70794576,1,70};
		soundPlastic3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_03",0.70794576,1,70};
		soundPlastic4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_04",0.70794576,1,70};
		soundConcrete1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",1,1,70};
		soundConcrete2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",1,1,70};
		soundConcrete3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",1,1,70};
		soundConcrete4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",1,1,70};
		soundConcrete5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",1,1,70};
		soundConcrete6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",1,1,70};
		soundConcrete7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",1,1,70};
		soundConcrete8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",1,1,70};
		soundRubber1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_01",1,1,50};
		soundRubber2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_02",1,1,50};
		soundRubber3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_03",1,1,50};
		soundRubber4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_04",1,1,50};
		soundWater1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_01",1,1,40};
		soundWater2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_02",1,1,40};
		soundWater3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_03",1,1,40};
		hitGroundSoft[] = {"soundGroundSoft1",0.2,"soundGroundSoft2",0.2,"soundGroundSoft3",0.1,"soundGroundSoft4",0.1,"soundGroundSoft5",0.1,"soundGroundSoft6",0.1,"soundGroundSoft7",0.1,"soundGroundSoft8",0.1};
		hitGroundHard[] = {"soundGroundHard1",0.2,"soundGroundHard2",0.2,"soundGroundHard3",0.1,"soundGroundHard4",0.1,"soundGroundHard5",0.1,"soundGroundHard6",0.1,"soundGroundHard7",0.1,"soundGroundHard8",0.1};
		hitMan[] = {"soundHitBody1",0.166,"soundHitBody2",0.166,"soundHitBody3",0.166,"soundHitBody4",0.166,"soundHitBody5",0.166,"soundHitBody6",0.17};
		hitArmor[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitBuilding[] = {"soundHitBuilding1",0.2,"soundHitBuilding2",0.2,"soundHitBuilding3",0.1,"soundHitBuilding4",0.1,"soundHitBuilding5",0.1,"soundHitBuilding6",0.1,"soundHitBuilding7",0.1,"soundHitBuilding8",0.1};
		hitFoliage[] = {"soundHitFoliage1",0.25,"soundHitFoliage2",0.25,"soundHitFoliage3",0.25,"soundHitFoliage4",0.25};
		hitWood[] = {"soundWood1",0.125,"soundWood2",0.125,"soundWood3",0.125,"soundWood4",0.125,"soundWood5",0.125,"soundWood6",0.125,"soundWood7",0.125,"soundWood8",0.125};
		hitGlass[] = {"soundHitGlass1",0.166,"soundHitGlass2",0.166,"soundHitGlass3",0.167,"soundHitGlass4",0.167,"soundHitGlass5",0.167,"soundHitGlass6",0.167};
		hitGlassArmored[] = {"soundGlassArmored1",0.166,"soundGlassArmored2",0.166,"soundGlassArmored3",0.167,"soundGlassArmored4",0.167,"soundGlassArmored5",0.167,"soundGlassArmored6",0.167};
		hitConcrete[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitRubber[] = {"soundRubber1",0.25,"soundRubber2",0.25,"soundRubber3",0.25,"soundRubber4",0.25};
		hitPlastic[] = {"soundPlastic1",0.25,"soundPlastic2",0.25,"soundPlastic3",0.25,"soundPlastic4",0.25};
		hitDefault[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitMetal[] = {"soundMetal1",0.125,"soundMetal2",0.125,"soundMetal3",0.125,"soundMetal4",0.125,"soundMetal5",0.125,"soundMetal6",0.125,"soundMetal7",0.125,"soundMetal8",0.125};
		hitMetalplate[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitWater[] = {"soundWater1",0.333,"soundWater2",0.333,"soundWater3",0.333};
	};
	class MeleeBearShock: MeleeDamage
	{
		class DamageApplied
		{
			type = "Melee";
			bleedThreshold = 0.85;
			class Health
			{
				damage = 25;
			};
			class Blood
			{
				damage = 350;
			};
			class Shock
			{
				damage = 110;
			};
			additionAnimalMeleeMultiplier = 5;
		};
		soundGroundSoft1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_01",0.5,1,60};
		soundGroundSoft2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_02",0.5,1,60};
		soundGroundSoft3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_03",0.5,1,60};
		soundGroundSoft4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_04",0.5,1,60};
		soundGroundSoft5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_05",0.5,1,60};
		soundGroundSoft6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_06",0.5,1,60};
		soundGroundSoft7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_07",0.5,1,60};
		soundGroundSoft8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_08",0.5,1,60};
		soundGroundHard1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_01",0.5,1,80};
		soundGroundHard2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_02",0.5,1,80};
		soundGroundHard3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_03",0.5,1,80};
		soundGroundHard4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_04",0.5,1,80};
		soundGroundHard5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_05",0.5,1,80};
		soundGroundHard6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_06",0.5,1,80};
		soundGroundHard7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_07",0.5,1,80};
		soundGroundHard8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_08",0.5,1,80};
		soundMetal1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",0.5,1,80};
		soundMetal2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",0.5,1,80};
		soundMetal3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",0.5,1,80};
		soundMetal4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",0.5,1,80};
		soundMetal5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",0.5,1,80};
		soundMetal6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",0.5,1,80};
		soundMetal7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",0.5,1,80};
		soundMetal8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",0.5,1,80};
		soundHitGlass1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_01",0.5,1,100};
		soundHitGlass2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_02",0.5,1,100};
		soundHitGlass3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_03",0.5,1,100};
		soundHitGlass4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_04",0.5,1,100};
		soundHitGlass5[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_05",0.5,1,100};
		soundHitGlass6[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_06",0.5,1,100};
		soundGlassArmored1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_01",0.5,1,60};
		soundGlassArmored2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_02",0.5,1,60};
		soundGlassArmored3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_03",0.5,1,60};
		soundGlassArmored4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_04",0.5,1,60};
		soundGlassArmored5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_05",0.5,1,60};
		soundGlassArmored6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_06",0.5,1,60};
		soundVehiclePlate1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",0.5,1,80};
		soundVehiclePlate2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",0.5,1,80};
		soundVehiclePlate3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",0.5,1,80};
		soundVehiclePlate4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",0.5,1,80};
		soundVehiclePlate5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",0.5,1,80};
		soundVehiclePlate6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",0.5,1,80};
		soundVehiclePlate7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",0.5,1,80};
		soundVehiclePlate8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",0.5,1,80};
		soundWood1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_01",0.5,1,80};
		soundWood2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_02",0.5,1,80};
		soundWood3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_03",0.5,1,80};
		soundWood4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_04",0.5,1,80};
		soundWood5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_05",0.5,1,80};
		soundWood6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_06",0.5,1,80};
		soundWood7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_07",0.5,1,80};
		soundWood8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_08",0.5,1,80};
		soundHitBody1[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_1",0.56234133,1,60};
		soundHitBody2[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_2",0.56234133,1,60};
		soundHitBody3[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_3",0.56234133,1,60};
		soundHitBody4[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_4",0.56234133,1,60};
		soundHitBody5[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_5",0.56234133,1,60};
		soundHitBody6[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_light_6",0.56234133,1,60};
		soundHitBuilding1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",0.5,1,60};
		soundHitBuilding2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",0.5,1,60};
		soundHitBuilding3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",0.5,1,60};
		soundHitBuilding4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",0.5,1,60};
		soundHitBuilding5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",0.5,1,60};
		soundHitBuilding6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",0.5,1,60};
		soundHitBuilding7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",0.5,1,60};
		soundHitBuilding8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",0.5,1,60};
		soundHitFoliage1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_01",0.5,1,20};
		soundHitFoliage2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_02",0.5,1,20};
		soundHitFoliage3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_03",0.5,1,20};
		soundHitFoliage4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_04",0.5,1,20};
		soundPlastic1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_01",0.35,1,70};
		soundPlastic2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_02",0.35,1,70};
		soundPlastic3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_03",0.35,1,70};
		soundPlastic4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_04",0.35,1,70};
		soundConcrete1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",0.5,1,70};
		soundConcrete2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",0.5,1,70};
		soundConcrete3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",0.5,1,70};
		soundConcrete4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",0.5,1,70};
		soundConcrete5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",0.5,1,70};
		soundConcrete6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",0.5,1,70};
		soundConcrete7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",0.5,1,70};
		soundConcrete8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",0.5,1,70};
		soundRubber1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_01",0.5,1,50};
		soundRubber2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_02",0.5,1,50};
		soundRubber3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_03",0.5,1,50};
		soundRubber4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_04",0.5,1,50};
		soundWater1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_01",0.5,1,40};
		soundWater2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_02",0.5,1,40};
		soundWater3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_03",0.5,1,40};
		hitGroundSoft[] = {"soundGroundSoft1",0.2,"soundGroundSoft2",0.2,"soundGroundSoft3",0.1,"soundGroundSoft4",0.1,"soundGroundSoft5",0.1,"soundGroundSoft6",0.1,"soundGroundSoft7",0.1,"soundGroundSoft8",0.1};
		hitGroundHard[] = {"soundGroundHard1",0.2,"soundGroundHard2",0.2,"soundGroundHard3",0.1,"soundGroundHard4",0.1,"soundGroundHard5",0.1,"soundGroundHard6",0.1,"soundGroundHard7",0.1,"soundGroundHard8",0.1};
		hitMan[] = {"soundHitBody1",0.166,"soundHitBody2",0.166,"soundHitBody3",0.166,"soundHitBody4",0.166,"soundHitBody5",0.166,"soundHitBody6",0.17};
		hitArmor[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitBuilding[] = {"soundHitBuilding1",0.2,"soundHitBuilding2",0.2,"soundHitBuilding3",0.1,"soundHitBuilding4",0.1,"soundHitBuilding5",0.1,"soundHitBuilding6",0.1,"soundHitBuilding7",0.1,"soundHitBuilding8",0.1};
		hitFoliage[] = {"soundHitFoliage1",0.25,"soundHitFoliage2",0.25,"soundHitFoliage3",0.25,"soundHitFoliage4",0.25};
		hitWood[] = {"soundWood1",0.125,"soundWood2",0.125,"soundWood3",0.125,"soundWood4",0.125,"soundWood5",0.125,"soundWood6",0.125,"soundWood7",0.125,"soundWood8",0.125};
		hitGlass[] = {"soundHitGlass1",0.166,"soundHitGlass2",0.166,"soundHitGlass3",0.167,"soundHitGlass4",0.167,"soundHitGlass5",0.167,"soundHitGlass6",0.167};
		hitGlassArmored[] = {"soundGlassArmored1",0.166,"soundGlassArmored2",0.166,"soundGlassArmored3",0.167,"soundGlassArmored4",0.167,"soundGlassArmored5",0.167,"soundGlassArmored6",0.167};
		hitConcrete[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitRubber[] = {"soundRubber1",0.25,"soundRubber2",0.25,"soundRubber3",0.25,"soundRubber4",0.25};
		hitPlastic[] = {"soundPlastic1",0.25,"soundPlastic2",0.25,"soundPlastic3",0.25,"soundPlastic4",0.25};
		hitDefault[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitMetal[] = {"soundMetal1",0.125,"soundMetal2",0.125,"soundMetal3",0.125,"soundMetal4",0.125,"soundMetal5",0.125,"soundMetal6",0.125,"soundMetal7",0.125,"soundMetal8",0.125};
		hitMetalplate[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitWater[] = {"soundWater1",0.333,"soundWater2",0.333,"soundWater3",0.333};
	};
	class MeleeBearShock_Heavy: MeleeBearShock
	{
		hitAnimation = 1;
		soundGroundSoft1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_01",1,1,60};
		soundGroundSoft2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_02",1,1,60};
		soundGroundSoft3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_03",1,1,60};
		soundGroundSoft4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_04",1,1,60};
		soundGroundSoft5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_05",1,1,60};
		soundGroundSoft6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_06",1,1,60};
		soundGroundSoft7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_07",1,1,60};
		soundGroundSoft8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_dirt_hit_08",1,1,60};
		soundGroundHard1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_01",1,1,80};
		soundGroundHard2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_02",1,1,80};
		soundGroundHard3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_03",1,1,80};
		soundGroundHard4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_04",1,1,80};
		soundGroundHard5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_05",1,1,80};
		soundGroundHard6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_06",1,1,80};
		soundGroundHard7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_07",1,1,80};
		soundGroundHard8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_default_hit_08",1,1,80};
		soundMetal1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",1,1,80};
		soundMetal2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",1,1,80};
		soundMetal3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",1,1,80};
		soundMetal4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",1,1,80};
		soundMetal5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",1,1,80};
		soundMetal6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",1,1,80};
		soundMetal7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",1,1,80};
		soundMetal8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",1,1,80};
		soundHitGlass1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_01",1,1,100};
		soundHitGlass2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_02",1,1,100};
		soundHitGlass3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_03",1,1,100};
		soundHitGlass4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_04",1,1,100};
		soundHitGlass5[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_05",1,1,100};
		soundHitGlass6[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_glass_hit_06",1,1,100};
		soundGlassArmored1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_01",1,1,60};
		soundGlassArmored2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_02",1,1,60};
		soundGlassArmored3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_03",1,1,60};
		soundGlassArmored4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_04",1,1,60};
		soundGlassArmored5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_05",1,1,60};
		soundGlassArmored6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_armor_glass_hit_06",1,1,60};
		soundVehiclePlate1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_01",1,1,80};
		soundVehiclePlate2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_02",1,1,80};
		soundVehiclePlate3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_03",1,1,80};
		soundVehiclePlate4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_04",1,1,80};
		soundVehiclePlate5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_05",1,1,80};
		soundVehiclePlate6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_06",1,1,80};
		soundVehiclePlate7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_07",1,1,80};
		soundVehiclePlate8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_metal_hit_08",1,1,80};
		soundWood1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_01",1,1,80};
		soundWood2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_02",1,1,80};
		soundWood3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_03",1,1,80};
		soundWood4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_04",1,1,80};
		soundWood5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_05",1,1,80};
		soundWood6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_06",1,1,80};
		soundWood7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_07",1,1,80};
		soundWood8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_wood_hit_08",1,1,80};
		soundHitBody1[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_1",0.56234133,1,60};
		soundHitBody2[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_2",0.56234133,1,60};
		soundHitBody3[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_3",0.56234133,1,60};
		soundHitBody4[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_4",0.56234133,1,60};
		soundHitBody5[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_5",0.56234133,1,60};
		soundHitBody6[] = {"dz\sounds\weapons\hits\melee\shortblade\hit_shortblade_body_heavy_6",0.56234133,1,60};
		soundHitBuilding1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",1,1,60};
		soundHitBuilding2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",1,1,60};
		soundHitBuilding3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",1,1,60};
		soundHitBuilding4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",1,1,60};
		soundHitBuilding5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",1,1,60};
		soundHitBuilding6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",1,1,60};
		soundHitBuilding7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",1,1,60};
		soundHitBuilding8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",1,1,60};
		soundHitFoliage1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_01",1,1,20};
		soundHitFoliage2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_02",1,1,20};
		soundHitFoliage3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_03",1,1,20};
		soundHitFoliage4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_leaves_hit_04",1,1,20};
		soundPlastic1[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_01",0.70794576,1,70};
		soundPlastic2[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_02",0.70794576,1,70};
		soundPlastic3[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_03",0.70794576,1,70};
		soundPlastic4[] = {"dz\sounds\weapons\meleehits\fist_hits\fist_hard_plastic_hit_04",0.70794576,1,70};
		soundConcrete1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_01",1,1,70};
		soundConcrete2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_02",1,1,70};
		soundConcrete3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_03",1,1,70};
		soundConcrete4[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_04",1,1,70};
		soundConcrete5[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_05",1,1,70};
		soundConcrete6[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_06",1,1,70};
		soundConcrete7[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_07",1,1,70};
		soundConcrete8[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_concrete_hit_08",1,1,70};
		soundRubber1[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_01",1,1,50};
		soundRubber2[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_02",1,1,50};
		soundRubber3[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_03",1,1,50};
		soundRubber4[] = {"dz\sounds\weapons\meleehits\blunt_metal_weapon_hits\blunt_metal_weapon_rubber_hit_04",1,1,50};
		soundWater1[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_01",1,1,40};
		soundWater2[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_02",1,1,40};
		soundWater3[] = {"dz\sounds\weapons\meleehits\short_blade_weapon_hits\short_blade_weapon_water_hit_03",1,1,40};
		hitGroundSoft[] = {"soundGroundSoft1",0.2,"soundGroundSoft2",0.2,"soundGroundSoft3",0.1,"soundGroundSoft4",0.1,"soundGroundSoft5",0.1,"soundGroundSoft6",0.1,"soundGroundSoft7",0.1,"soundGroundSoft8",0.1};
		hitGroundHard[] = {"soundGroundHard1",0.2,"soundGroundHard2",0.2,"soundGroundHard3",0.1,"soundGroundHard4",0.1,"soundGroundHard5",0.1,"soundGroundHard6",0.1,"soundGroundHard7",0.1,"soundGroundHard8",0.1};
		hitMan[] = {"soundHitBody1",0.166,"soundHitBody2",0.166,"soundHitBody3",0.166,"soundHitBody4",0.166,"soundHitBody5",0.166,"soundHitBody6",0.17};
		hitArmor[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitBuilding[] = {"soundHitBuilding1",0.2,"soundHitBuilding2",0.2,"soundHitBuilding3",0.1,"soundHitBuilding4",0.1,"soundHitBuilding5",0.1,"soundHitBuilding6",0.1,"soundHitBuilding7",0.1,"soundHitBuilding8",0.1};
		hitFoliage[] = {"soundHitFoliage1",0.25,"soundHitFoliage2",0.25,"soundHitFoliage3",0.25,"soundHitFoliage4",0.25};
		hitWood[] = {"soundWood1",0.125,"soundWood2",0.125,"soundWood3",0.125,"soundWood4",0.125,"soundWood5",0.125,"soundWood6",0.125,"soundWood7",0.125,"soundWood8",0.125};
		hitGlass[] = {"soundHitGlass1",0.166,"soundHitGlass2",0.166,"soundHitGlass3",0.167,"soundHitGlass4",0.167,"soundHitGlass5",0.167,"soundHitGlass6",0.167};
		hitGlassArmored[] = {"soundGlassArmored1",0.166,"soundGlassArmored2",0.166,"soundGlassArmored3",0.167,"soundGlassArmored4",0.167,"soundGlassArmored5",0.167,"soundGlassArmored6",0.167};
		hitConcrete[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitRubber[] = {"soundRubber1",0.25,"soundRubber2",0.25,"soundRubber3",0.25,"soundRubber4",0.25};
		hitPlastic[] = {"soundPlastic1",0.25,"soundPlastic2",0.25,"soundPlastic3",0.25,"soundPlastic4",0.25};
		hitDefault[] = {"soundConcrete1",0.125,"soundConcrete2",0.125,"soundConcrete3",0.125,"soundConcrete4",0.125,"soundConcrete5",0.125,"soundConcrete6",0.125,"soundConcrete7",0.125,"soundConcrete8",0.125};
		hitMetal[] = {"soundMetal1",0.125,"soundMetal2",0.125,"soundMetal3",0.125,"soundMetal4",0.125,"soundMetal5",0.125,"soundMetal6",0.125,"soundMetal7",0.125,"soundMetal8",0.125};
		hitMetalplate[] = {"soundVehiclePlate1",0.125,"soundVehiclePlate2",0.125,"soundVehiclePlate3",0.125,"soundVehiclePlate4",0.125,"soundVehiclePlate5",0.125,"soundVehiclePlate6",0.125,"soundVehiclePlate7",0.125,"soundVehiclePlate8",0.125};
		hitWater[] = {"soundWater1",0.333,"soundWater2",0.333,"soundWater3",0.333};
	};
};
class CfgVehicles
{
	class AnimalBase;
	class Animal_UrsusArctos: AnimalBase
	{
		simulation = "dayzanimal";
		scope = 2;
		model = "\DZ\animals_bliss\ursus_arctos\ursus_arctos.p3d";
		armor = 1.2;
		displayName = "$STR_CfgVehicles_Animal_UrsusArctos0";
		descriptionShort = "$STR_CfgVehicles_Animal_UrsusArctos1";
		aiAgentTemplate = "Predator_UrsusArctos";
		injuryLevels[] = {1.0,0.5,0.2,0.0};
		DamageSphereAmmos[] = {"MeleeBear","MeleeBearShock","MeleeWolf"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 800;
					healthLabels[] = {1.0,0.7,0.5,0.3,0.0};
				};
				class Blood
				{
					hitpoints = 5000;
				};
				class Shock
				{
					hitpoints = 5000;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[] = {"Zone_Head"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.1;
					canBleed = 0;
					class Health
					{
						hitpoints = 250;
						transferToGlobalCoef = 1;
					};
					class Blood: Health
					{
						hitpoints = 5000;
					};
					class Shock: Health
					{
						hitpoints = 5000;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0.51;
							};
						};
						class Projectile: Melee
						{
							class Health: Health
							{
								damage = 0.56;
							};
						};
						class FragGrenade: Melee{};
					};
				};
				class Zone_Neck: Zone_Head
				{
					componentNames[] = {"Zone_Neck"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.1;
					class Health
					{
						hitpoints = 300;
						transferToGlobalCoef = 1;
					};
					class ArmorType: ArmorType
					{
						class Melee: Melee
						{
							class Health: Health
							{
								damage = 0.15;
							};
						};
						class Projectile: Projectile
						{
							class Health: Health
							{
								damage = 0.78;
							};
						};
					};
				};
				class Zone_Belly: Zone_Head
				{
					componentNames[] = {"Zone_Belly"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health: Health
					{
						hitpoints = 400;
					};
					class ArmorType: ArmorType
					{
						class Melee: Melee
						{
							class Health: Health
							{
								damage = 0.3;
							};
						};
					};
				};
				class Zone_Pelvis: Zone_Head
				{
					componentNames[] = {"Zone_Pelvis"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health: Health
					{
						hitpoints = 500;
					};
					class ArmorType: ArmorType
					{
						class Melee: Melee
						{
							class Health: Health
							{
								damage = 0.3;
							};
						};
					};
				};
				class Zone_Legs: Zone_Head
				{
					componentNames[] = {"Zone_Legs"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.01;
					class Health: Health
					{
						hitpoints = 200;
						transferToGlobalCoef = 0.0;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedPelt
			{
				item = "BearPelt";
				count = 2;
				transferToolDamageCoef = 1;
			};
			class ObtainedSteaks
			{
				item = "BearSteakMeat";
				count = 20;
				itemZones[] = {"Zone_Belly","Zone_Pelvis"};
				countByZone[] = {8.0,8.0};
				quantityMinMaxCoef[] = {0.7,1};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 2;
				quantityMinMaxCoef[] = {0.2,1};
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 4;
				quantityMinMaxCoef[] = {0.4,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 5;
				quantityMinMaxCoef[] = {0.3,1};
				transferToolDamageCoef = 1;
			};
		};
		class enfanimsys
		{
			meshObject = "DZ\animals_bliss\ursus_arctos\data\ursus_arctos_skeleton.xob";
			graphname = "DZ\animals_bliss\animations\!graph_files\bear\Bear_Graph.agr";
			defaultinstance = "DZ\animals_bliss\animations\!graph_files\bear\BearSkeleton_AnimInstance.asi";
			startnode = "MasterBear_SM";
			skeletonName = "ursus_arctos_skeleton.xob";
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "PawBigWalk_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "PawBigRun_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 8;
				};
				class Bodyfall
				{
					soundLookupTable = "PawBigBodyfall_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 11;
				};
				class Settle
				{
					soundLookupTable = "PawBigSettle_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 12;
				};
				class Rest2standA
				{
					soundLookupTable = "PawBigRest2standA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 13;
				};
				class Rest2standB
				{
					soundLookupTable = "PawBigRest2standB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 14;
				};
				class Stand2restA
				{
					soundLookupTable = "PawBigStand2restA_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 15;
				};
				class Stand2restB
				{
					soundLookupTable = "PawBigStand2restB_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 16;
				};
				class Stand2restC
				{
					soundLookupTable = "PawBigStand2restC_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 17;
				};
				class Jump
				{
					soundLookupTable = "PawBigJump_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 18;
				};
				class Impact
				{
					soundLookupTable = "PawBigImpact_LookupTable";
					noise = "WolfStepNoise";
					effectSet[] = {"WolfStepEffect1","WolfStepEffect2"};
					id = 19;
				};
			};
			class Sounds
			{
				class BearAttack
				{
					soundSet = "BearAttack_SoundSet";
					noise = "WolfRoarNoise";
					id = 21;
				};
				class BearBreath
				{
					soundSet = "BearBreath_SoundSet";
					noise = "WolfRoarNoise";
					id = 1;
				};
				class BearGrowl
				{
					soundSet = "BearGrowl_SoundSet";
					noise = "WolfRoarNoise";
					id = 2;
				};
				class BearMumble
				{
					soundSet = "BearMumble_SoundSet";
					noise = "WolfRoarNoise";
					id = 3;
				};
				class BearRoar
				{
					soundSet = "BearRoar_SoundSet";
					noise = "WolfRoarNoise";
					id = 4;
				};
				class BearRoarShort
				{
					soundSet = "BearRoarShort_SoundSet";
					noise = "WolfRoarNoise";
					id = 12;
				};
				class BearSigh
				{
					soundSet = "BearSigh_SoundSet";
					noise = "WolfRoarNoise";
					id = 5;
				};
				class BearSighLong
				{
					soundSet = "BearSighLong_SoundSet";
					noise = "WolfRoarNoise";
					id = 6;
				};
				class BearSighShort
				{
					soundSet = "BearSighShort_SoundSet";
					noise = "WolfRoarNoise";
					id = 7;
				};
				class BearSnarl
				{
					soundSet = "BearSnarl_SoundSet";
					noise = "WolfRoarNoise";
					id = 8;
				};
				class BearSnarlLong
				{
					soundSet = "BearSnarlLong_SoundSet";
					noise = "WolfRoarNoise";
					id = 9;
				};
				class BearSnort
				{
					soundSet = "BearSnort_SoundSet";
					noise = "WolfRoarNoise";
					id = 10;
				};
				class BearGrowl_1
				{
					soundSet = "BearGrowl_1_SoundSet";
					noise = "WolfRoarNoise";
					id = 11;
				};
				class BearGrowl_3
				{
					soundSet = "BearGrowl_3_SoundSet";
					noise = "WolfRoarNoise";
					id = 13;
				};
				class BearGrowl_4
				{
					soundSet = "BearGrowl_4_SoundSet";
					noise = "WolfRoarNoise";
					id = 14;
				};
				class BearGrowl_5
				{
					soundSet = "BearGrowl_5_SoundSet";
					noise = "WolfRoarNoise";
					id = 15;
				};
				class BearGrowl_6
				{
					soundSet = "BearGrowl_6_SoundSet";
					noise = "WolfRoarNoise";
					id = 16;
				};
				class BearGrowl_7
				{
					soundSet = "BearGrowl_7_SoundSet";
					noise = "WolfRoarNoise";
					id = 17;
				};
				class BearGrowl_8
				{
					soundSet = "BearGrowl_8_SoundSet";
					noise = "WolfRoarNoise";
					id = 18;
				};
				class BearGrowl_9
				{
					soundSet = "BearGrowl_9_SoundSet";
					noise = "WolfRoarNoise";
					id = 19;
				};
				class BearGrowl_10
				{
					soundSet = "BearGrowl_10_SoundSet";
					noise = "WolfRoarNoise";
					id = 20;
				};
				class BearGrowl_12
				{
					soundSet = "BearGrowl_12_SoundSet";
					noise = "WolfRoarNoise";
					id = 22;
				};
				class BearGrowl_13
				{
					soundSet = "BearGrowl_13_SoundSet";
					noise = "WolfRoarNoise";
					id = 23;
				};
				class BearRoar_1
				{
					soundSet = "BearRoar_1_SoundSet";
					noise = "WolfRoarNoise";
					id = 24;
				};
				class BearRoar_2
				{
					soundSet = "BearRoar_2_SoundSet";
					noise = "WolfRoarNoise";
					id = 25;
				};
				class BearRoar_3
				{
					soundSet = "BearRoar_3_SoundSet";
					noise = "WolfRoarNoise";
					id = 26;
				};
				class BearRoar_5
				{
					soundSet = "BearRoar_5_SoundSet";
					noise = "WolfRoarNoise";
					id = 27;
				};
				class BearRoar_6
				{
					soundSet = "BearRoar_6_SoundSet";
					noise = "WolfRoarNoise";
					id = 28;
				};
				class BearRoar_7
				{
					soundSet = "BearRoar_7_SoundSet";
					noise = "WolfRoarNoise";
					id = 29;
				};
				class BearSighLong_0
				{
					soundSet = "BearSighLong_0_SoundSet";
					noise = "WolfRoarNoise";
					id = 30;
				};
				class BearSighLong_1
				{
					soundSet = "BearSighLong_1_SoundSet";
					noise = "WolfRoarNoise";
					id = 31;
				};
				class BearSighLong_2
				{
					soundSet = "BearSighLong_2_SoundSet";
					noise = "WolfRoarNoise";
					id = 32;
				};
				class BearSnarlLong_0
				{
					soundSet = "BearSnarlLong_0_SoundSet";
					noise = "WolfRoarNoise";
					id = 33;
				};
				class BearSnarlLong_1
				{
					soundSet = "BearSnarlLong_1_SoundSet";
					noise = "WolfRoarNoise";
					id = 34;
				};
				class BearSnarlLong_2
				{
					soundSet = "BearSnarlLong_2_SoundSet";
					noise = "WolfRoarNoise";
					id = 35;
				};
			};
			class Damages
			{
				class BearBiteDamage
				{
					damage = "BearBiteDamage";
					id = 1;
				};
				class BearLeftPawDamage
				{
					damage = "BearLeftPawDamage";
					id = 2;
				};
				class BearRightPawDamage
				{
					damage = "BearRightPawDamage";
					id = 3;
				};
				class BearBiteDamageIntimidate
				{
					damage = "BearBiteDamageIntimidate";
					id = 11;
				};
				class BearLeftPawDamageIntimidate
				{
					damage = "BearLeftPawDamageIntimidate";
					id = 12;
				};
				class BearRightPawDamageIntimidate
				{
					damage = "BearRightPawDamageIntimidate";
					id = 13;
				};
			};
		};
		class CommandMoveSettings
		{
			useSpeedMapping = 1;
			movementSpeedMapping[] = {0.0,0.24,0.55,1.72,3.5,8.0};
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
	};
};
