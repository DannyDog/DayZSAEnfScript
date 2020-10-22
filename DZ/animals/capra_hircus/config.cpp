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
	class DZ_Animals_capra_hircus
	{
		units[] = {"Animal_CapraHircus"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Animals"};
	};
};
class CfgVehicles
{
	class AnimalBase;
	class Animal_CapraHircus: AnimalBase
	{
		simulation = "dayzanimal";
		scope = 0;
		model = "\dz\animals\capra_hircus\capra_hircus.p3d";
		displayName = "$STR_CfgVehicles_Animal_CapraHircus0";
		descriptionShort = "$STR_CfgVehicles_Animal_CapraHircus1";
		hiddenSelections[] = {"Camo","CamoHair"};
		aiAgentTemplate = "Herbivores_CapraHircus";
		injuryLevels[] = {1.0,0.5,0.2,0.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 120;
					healthLabels[] = {1.0,0.7,0.5,0.3,0.0};
				};
				class Blood
				{
					hitpoints = 5000;
				};
				class Shock
				{
					hitpoints = 100;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[] = {"Zone_Head"};
					transferToZonesNames[] = {};
					transferToZonesCoefs[] = {};
					fatalInjuryCoef = 0.15;
					canBleed = 0;
					class Health
					{
						hitpoints = 80;
						transferToGlobalCoef = 1;
					};
					class Blood: Health
					{
						hitpoints = 0;
					};
					class Shock: Health
					{
						hitpoints = 0;
					};
				};
				class Zone_Neck: Zone_Head
				{
					componentNames[] = {"Zone_Neck"};
					transferToZonesNames[] = {"Zone_Chest"};
					transferToZonesCoefs[] = {0.2};
					fatalInjuryCoef = 0.05;
					class Health: Health
					{
						hitpoints = 150;
					};
				};
				class Zone_Chest: Zone_Head
				{
					componentNames[] = {"Zone_Chest"};
					transferToZonesNames[] = {"Zone_Neck","Zone_Belly"};
					transferToZonesCoefs[] = {0.15,0.15};
					fatalInjuryCoef = 0.05;
					class Health: Health
					{
						hitpoints = 120;
					};
				};
				class Zone_Belly: Zone_Head
				{
					componentNames[] = {"Zone_Belly"};
					transferToZonesNames[] = {"Zone_Pelvis","Zone_Chest"};
					transferToZonesCoefs[] = {0.15,0.15};
					fatalInjuryCoef = 0.05;
					class Health: Health
					{
						hitpoints = 100;
					};
				};
				class Zone_Spine: Zone_Head
				{
					componentNames[] = {"Zone_Spine"};
					transferToZonesNames[] = {"Zone_Pelvis","Zone_Belly","Zone_Chest"};
					transferToZonesCoefs[] = {0.1,0.1,0.1};
					fatalInjuryCoef = 0.05;
					class Health: Health
					{
						hitpoints = 120;
					};
				};
				class Zone_Pelvis: Zone_Head
				{
					componentNames[] = {"Zone_Pelvis"};
					transferToZonesNames[] = {"Zone_Spine","Zone_Belly"};
					transferToZonesCoefs[] = {0.15,0.15};
					fatalInjuryCoef = 0.05;
					class Health: Health
					{
						hitpoints = 120;
					};
				};
				class Zone_Legs: Zone_Head
				{
					componentNames[] = {"Zone_Legs"};
					transferToZonesNames[] = {"Zone_Pelvis","Zone_Belly","Zone_Chest"};
					transferToZonesCoefs[] = {0.1,0.1,0.1};
					fatalInjuryCoef = 0.0;
					class Health: Health
					{
						hitpoints = 50;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "GoatSteakMeat";
				count = 10;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {3.0,2.0,4.0};
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedPelt
			{
				item = "GoatPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 2;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.3,6};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
		};
		class enfanimsys
		{
			meshObject = "dz\animals\capra_hircus\Data\capra_hircus_skeleton.xob";
			graphname = "dz\animals\animations\!graph_files\Herbivores\Herbivores_Graph.agr";
			defaultinstance = "dz\animals\animations\!graph_files\Herbivores\GoatSkeleton_AnimInstance.asi";
			startnode = "Master_GoatAndSheep_SM";
			skeletonName = "capra_hircus_skeleton.xob";
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "HoofSmallWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "HoofSmallWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "HoofSmallWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "HoofSmallWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "HoofSmallRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "HoofSmallRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "HoofSmallRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "HoofSmallRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 8;
				};
				class Grazing1
				{
					soundLookupTable = "HoofSmallGrazing_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 9;
				};
				class Grazing2
				{
					soundLookupTable = "HoofSmallGrazing_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 10;
				};
				class Bodyfall
				{
					soundLookupTable = "HoofSmallBodyfall_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 11;
				};
				class Settle
				{
					soundLookupTable = "HoofSmallSettle_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 12;
				};
				class Rest2standA
				{
					soundLookupTable = "HoofSmallRest2standA_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 13;
				};
				class Rest2standB
				{
					soundLookupTable = "HoofSmallRest2standB_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 14;
				};
				class Stand2restA
				{
					soundLookupTable = "HoofSmallStand2restA_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 15;
				};
				class Stand2restB
				{
					soundLookupTable = "HoofSmallStand2restB_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 16;
				};
				class Stand2restC
				{
					soundLookupTable = "HoofSmallStand2restC_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 17;
				};
				class Rub1
				{
					soundLookupTable = "HoofSmallRub1_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 18;
				};
				class Rub2
				{
					soundLookupTable = "HoofSmallRub2_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 19;
				};
			};
			class Sounds
			{
				class GoatBleat_A
				{
					soundSet = "GoatBleat_A_SoundSet";
					noise = "DeerRoarNoise";
					id = 1;
				};
				class GoatBleat_B
				{
					soundSet = "GoatBleat_B_SoundSet";
					noise = "DeerRoarNoise";
					id = 2;
				};
				class GoatBleat_C
				{
					soundSet = "GoatBleat_C_SoundSet";
					noise = "DeerRoarNoise";
					id = 3;
				};
				class GoatBleat_D
				{
					soundSet = "GoatBleat_D_SoundSet";
					noise = "DeerRoarNoise";
					id = 4;
				};
				class GoatBleat_E
				{
					soundSet = "GoatBleat_E_SoundSet";
					noise = "DeerRoarNoise";
					id = 5;
				};
				class GoatBleat_F
				{
					soundSet = "GoatBleat_F_SoundSet";
					noise = "DeerRoarNoise";
					id = 6;
				};
				class GoatBleatX1
				{
					soundSet = "GoatBleatX1_SoundSet";
					noise = "DeerRoarNoise";
					id = 14;
				};
				class GoatBleatX2
				{
					soundSet = "GoatBleatX2_SoundSet";
					noise = "DeerRoarNoise";
					id = 16;
				};
				class GoatBleatX3
				{
					soundSet = "GoatBleatX3_SoundSet";
					noise = "DeerRoarNoise";
					id = 18;
				};
				class GoatBleatX4
				{
					soundSet = "GoatBleatX4_SoundSet";
					noise = "DeerRoarNoise";
					id = 20;
				};
				class GoatBleatX5
				{
					soundSet = "GoatBleatX5_SoundSet";
					noise = "DeerRoarNoise";
					id = 22;
				};
			};
			class Damages
			{
				class Bite
				{
					damage = "DeerBiteDamage";
					id = 1;
				};
			};
		};
		class CommandMoveSettings
		{
			useSpeedMapping = 1;
			movementSpeedMapping[] = {0.0,0.11,0.41,2.1,4.56,10.44};
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
	};
	class Animal_CapraHircus_Brown: Animal_CapraHircus
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\animals\capra_hircus\data\Brown_Goat_CO.paa","dz\animals\capra_hircus\data\Brown_Goat_fur_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\animals\capra_hircus\data\Brown_Goat.rvmat","dz\animals\capra_hircus\data\Brown_Goat_Fur.rvmat"};
	};
	class Animal_CapraHircus_Black: Animal_CapraHircus
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\animals\capra_hircus\data\Black_Goat_CO.paa","dz\animals\capra_hircus\data\black_goat_fur_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\animals\capra_hircus\data\Black_Goat.rvmat","dz\animals\capra_hircus\data\black_goat_fur.rvmat"};
	};
	class Animal_CapraHircus_White: Animal_CapraHircus
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\animals\capra_hircus\data\White_Goat_CO.paa","dz\animals\capra_hircus\data\White_Goat_fur_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\animals\capra_hircus\data\White_Goat.rvmat","dz\animals\capra_hircus\data\White_Goat_Fur.rvmat"};
	};
};
