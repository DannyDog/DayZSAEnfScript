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
	class DZ_Animals_bos_taurus_fem
	{
		units[] = {"Animal_BosTaurusF"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Animals"};
	};
};
class CfgVehicles
{
	class AnimalBase;
	class Animal_BosTaurusF: AnimalBase
	{
		simulation = "dayzanimal";
		scope = 0;
		model = "\dz\animals\bos_taurus_fem\bos_taurus_fem.p3d";
		displayName = "$STR_CfgVehicles_Animal_BosTaurusF0";
		descriptionShort = "$STR_CfgVehicles_Animal_BosTaurusF1";
		hiddenSelections[] = {"Camo"};
		aiAgentTemplate = "Herbivores_BosTaurus";
		injuryLevels[] = {1.0,0.5,0.2,0.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
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
						hitpoints = 250;
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
					transferToZonesCoefs[] = {0.5};
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
					transferToZonesCoefs[] = {0.5,0.5};
					fatalInjuryCoef = 0.05;
					class Health: Health
					{
						hitpoints = 200;
					};
				};
				class Zone_Belly: Zone_Head
				{
					componentNames[] = {"Zone_Belly"};
					transferToZonesNames[] = {"Zone_Pelvis","Zone_Chest"};
					transferToZonesCoefs[] = {0.5,0.5};
					class Health: Health
					{
						hitpoints = 200;
					};
				};
				class Zone_Spine: Zone_Head
				{
					componentNames[] = {"Zone_Spine"};
					transferToZonesNames[] = {"Zone_Pelvis","Zone_Belly","Zone_Chest"};
					transferToZonesCoefs[] = {0.5,0.5,0.5};
					fatalInjuryCoef = 0.05;
					class Health: Health
					{
						hitpoints = 200;
					};
				};
				class Zone_Pelvis: Zone_Head
				{
					componentNames[] = {"Zone_Pelvis"};
					transferToZonesNames[] = {"Zone_Spine","Zone_Belly"};
					transferToZonesCoefs[] = {0.5,0.5};
					fatalInjuryCoef = 0.05;
					class Health: Health
					{
						hitpoints = 250;
					};
				};
				class Zone_Legs: Zone_Head
				{
					componentNames[] = {"Zone_Legs"};
					transferToZonesNames[] = {"Zone_Pelvis","Zone_Belly","Zone_Chest"};
					transferToZonesCoefs[] = {0.5,0.5,0.5};
					fatalInjuryCoef = 0.05;
					class Health: Health
					{
						hitpoints = 100;
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "CowSteakMeat";
				count = 20;
				itemZones[] = {"Zone_Chest","Zone_Belly","Zone_Pelvis"};
				countByZone[] = {6.0,6.0,6.0};
				quantityMinMaxCoef[] = {0.75,1};
			};
			class ObtainedPelt
			{
				item = "CowPelt";
				count = 1;
				itemZones[] = {"Zone_Chest","Zone_Belly"};
				quantityCoef = 1;
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "Guts";
				count = 5;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedLard
			{
				item = "Lard";
				count = 3;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 4;
				quantityMinMaxCoef[] = {0.8,1};
				transferToolDamageCoef = 1;
			};
		};
		class enfanimsys
		{
			meshObject = "dz\animals\bos_taurus_fem\data\CowAndBull_skeleton.xob";
			graphname = "dz\animals\animations\!graph_files\Herbivores\Herbivores_Graph.agr";
			defaultinstance = "dz\animals\animations\!graph_files\Herbivores\CowAndBull_AnimInstance.asi";
			startnode = "Master_CowAndBull_SM";
			skeletonName = "CowAndBull_skeleton.xob";
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "HoofMediumWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "HoofMediumWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "HoofMediumWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "HoofMediumWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 4;
				};
				class Run1
				{
					soundLookupTable = "HoofMediumRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 5;
				};
				class Run2
				{
					soundLookupTable = "HoofMediumRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 6;
				};
				class Run3
				{
					soundLookupTable = "HoofMediumRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 7;
				};
				class Run4
				{
					soundLookupTable = "HoofMediumRun_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 8;
				};
				class Grazing1
				{
					soundLookupTable = "HoofMediumGrazing_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 9;
				};
				class Grazing2
				{
					soundLookupTable = "HoofMediumGrazing_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 10;
				};
				class Bodyfall
				{
					soundLookupTable = "HoofMediumBodyfall_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 11;
				};
				class Settle
				{
					soundLookupTable = "HoofMediumSettle_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 12;
				};
				class Rest2standA
				{
					soundLookupTable = "HoofMediumRest2standA_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 13;
				};
				class Rest2standB
				{
					soundLookupTable = "HoofMediumRest2standB_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 14;
				};
				class Stand2restA
				{
					soundLookupTable = "HoofMediumStand2restA_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 15;
				};
				class Stand2restB
				{
					soundLookupTable = "HoofMediumStand2restB_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 16;
				};
				class Stand2restC
				{
					soundLookupTable = "HoofMediumStand2restC_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 17;
				};
				class Rub1
				{
					soundLookupTable = "HoofMediumRub1_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 18;
				};
				class Rub2
				{
					soundLookupTable = "HoofMediumRub2_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 19;
				};
			};
			class Sounds
			{
				class CattleBawl
				{
					soundSet = "CattleBawl_SoundSet";
					noise = "DeerRoarNoise";
					id = 1;
				};
				class CattleBellow
				{
					soundSet = "CattleBellow_SoundSet";
					noise = "DeerRoarNoise";
					id = 2;
				};
				class CattleBreath
				{
					soundSet = "CattleBreath_SoundSet";
					noise = "DeerRoarNoise";
					id = 3;
				};
				class CattleGroan
				{
					soundSet = "CattleGroan_SoundSet";
					noise = "DeerRoarNoise";
					id = 4;
				};
				class CattleHoarse
				{
					soundSet = "CattleHoarse_SoundSet";
					noise = "DeerRoarNoise";
					id = 5;
				};
				class CattleHonk
				{
					soundSet = "CattleHonk_SoundSet";
					noise = "DeerRoarNoise";
					id = 6;
				};
				class CattleMooA
				{
					soundSet = "CattleMooA_SoundSet";
					noise = "DeerRoarNoise";
					id = 7;
				};
				class CattleMooALong
				{
					soundSet = "CattleMooALong_SoundSet";
					noise = "DeerRoarNoise";
					id = 8;
				};
				class CattleMooB
				{
					soundSet = "CattleMooB_SoundSet";
					noise = "DeerRoarNoise";
					id = 9;
				};
				class CattleMooC
				{
					soundSet = "CattleMooC_SoundSet";
					noise = "DeerRoarNoise";
					id = 10;
				};
				class CattleRoar
				{
					soundSet = "CattleRoar_SoundSet";
					noise = "DeerRoarNoise";
					id = 11;
				};
				class CattleSigh
				{
					soundSet = "CattleSigh_SoundSet";
					noise = "DeerRoarNoise";
					id = 12;
				};
				class CattleSighLong
				{
					soundSet = "CattleSighLong_SoundSet";
					noise = "DeerRoarNoise";
					id = 13;
				};
				class CattleMooX1
				{
					soundSet = "CattleMooX1_SoundSet";
					noise = "DeerRoarNoise";
					id = 14;
				};
				class CattleMooX1_Tail
				{
					soundSet = "CattleMooX1_Tail_SoundSet";
					noise = "DeerRoarNoise";
					id = 15;
				};
				class CattleMooX2
				{
					soundSet = "CattleMooX2_SoundSet";
					noise = "DeerRoarNoise";
					id = 16;
				};
				class CattleMooX2_Tail
				{
					soundSet = "CattleMooX2_Tail_SoundSet";
					noise = "DeerRoarNoise";
					id = 17;
				};
				class CattleMooX3
				{
					soundSet = "CattleMooX3_SoundSet";
					noise = "DeerRoarNoise";
					id = 18;
				};
				class CattleMooX3_Tail
				{
					soundSet = "CattleMooX3_Tail_SoundSet";
					noise = "DeerRoarNoise";
					id = 19;
				};
				class CattleMooX4
				{
					soundSet = "CattleMooX4_SoundSet";
					noise = "DeerRoarNoise";
					id = 20;
				};
				class CattleMooX4_Tail
				{
					soundSet = "CattleMooX4_Tail_SoundSet";
					noise = "DeerRoarNoise";
					id = 21;
				};
				class CattleMooX5
				{
					soundSet = "CattleMooX5_SoundSet";
					noise = "DeerRoarNoise";
					id = 22;
				};
				class CattleMooX5_Tail
				{
					soundSet = "CattleMooX5_Tail_SoundSet";
					noise = "DeerRoarNoise";
					id = 23;
				};
				class CattleSnort
				{
					soundSet = "CattleSnort_SoundSet";
					noise = "DeerRoarNoise";
					id = 24;
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
			movementSpeedMapping[] = {0.0,0.25,0.6,2.2,5.0,11.0};
		};
		class CommandLookAtSettings
		{
			lookAtFilterTimeout = 0.5;
			lookAtFilterSpeed = 1.57;
		};
	};
	class Animal_BosTaurusF_Brown: Animal_BosTaurusF
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\animals\bos_taurus_fem\data\cow_brown_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\animals\bos_taurus_fem\data\cow_brown.rvmat"};
	};
	class Animal_BosTaurusF_White: Animal_BosTaurusF
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\animals\bos_taurus_fem\data\cow_white_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\animals\bos_taurus_fem\data\cow_white.rvmat"};
	};
	class Animal_BosTaurusF_Spotted: Animal_BosTaurusF
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"dz\animals\bos_taurus_fem\data\cow_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\animals\bos_taurus_fem\data\cow.rvmat"};
	};
};
