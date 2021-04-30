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
	class DZ_Animals_gallus_gallus_domesticus
	{
		units[] = {"Animal_GallusGallusDomesticus"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Animals"};
	};
};
class CfgVehicles
{
	class AnimalBase;
	class Animal_GallusGallusDomesticus: AnimalBase
	{
		simulation = "dayzanimal";
		scope = 2;
		model = "\DZ\animals\gallus_gallus_domesticus\gallus_gallus_domesticus.p3d";
		displayName = "$STR_CfgVehicles_Animal_GallusGallusDomesticus0";
		descriptionShort = "$STR_CfgVehicles_Animal_GallusGallusDomesticus1";
		aiAgentTemplate = "AmbientLife";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15;
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
		};
		class Skinning
		{
			class ObtainedSteaks
			{
				item = "ChickenBreastMeat";
				count = 2;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class ObtainedFeathers
			{
				item = "ChickenFeather";
				count = 0;
				quantityMinMaxCoef[] = {0.5,1};
				transferToolDamageCoef = 1;
			};
			class ObtainedGuts
			{
				item = "SmallGuts";
				count = 0;
				quantityMinMaxCoef[] = {0.5,0.8};
			};
			class ObtainedBones
			{
				item = "Bone";
				count = 1;
				quantityMinMaxCoef[] = {0.2,0.3};
				transferToolDamageCoef = 1;
			};
		};
		class enfanimsys
		{
			meshObject = "dz\animals\gallus_gallus_domesticus\data\gallus_gallus_domesticus.xob";
			graphname = "dz\animals\animations\!graph_files\AmbientLife\AmbientLife_Graph.agr";
			defaultinstance = "dz\animals\animations\!graph_files\AmbientLife\GallusGallus_skeleton_AnimInstance.asi";
			startnode = "Master_SM";
			skeletonName = "gallus_gallus_domesticus.xob";
		};
		class AnimEvents
		{
			class Steps
			{
				class Walk1
				{
					soundLookupTable = "BirdWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 1;
				};
				class Walk2
				{
					soundLookupTable = "BirdWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 2;
				};
				class Walk3
				{
					soundLookupTable = "BirdWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 3;
				};
				class Walk4
				{
					soundLookupTable = "BirdWalk_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 4;
				};
				class Grazing1
				{
					soundLookupTable = "BirdGrazing_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 9;
				};
				class Grazing2
				{
					soundLookupTable = "BirdGrazing_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 10;
				};
				class Bodyfall
				{
					soundLookupTable = "BirdBodyfall_LookupTable";
					noise = "DeerStepNoise";
					effectSet[] = {"DeerStepEffect1","DeerStepEffect2"};
					id = 11;
				};
			};
			class Sounds
			{
				class HenChick
				{
					soundSet = "HenChick_SoundSet";
					noise = "DeerRoarNoise";
					id = 1;
				};
				class HenCluck_A
				{
					soundSet = "HenCluck_A_SoundSet";
					noise = "DeerRoarNoise";
					id = 2;
				};
				class HenCluck_A_High
				{
					soundSet = "HenCluck_A_High_SoundSet";
					noise = "DeerRoarNoise";
					id = 3;
				};
				class HenCluck_B
				{
					soundSet = "HenCluck_B_SoundSet";
					noise = "DeerRoarNoise";
					id = 4;
				};
				class HenCluck_B_High
				{
					soundSet = "HenCluck_B_High_SoundSet";
					noise = "DeerRoarNoise";
					id = 5;
				};
				class HenCluck_C
				{
					soundSet = "HenCluck_C_SoundSet";
					noise = "DeerRoarNoise";
					id = 6;
				};
				class HenCluck_C_High
				{
					soundSet = "HenCluck_C_High_SoundSet";
					noise = "DeerRoarNoise";
					id = 7;
				};
				class HenCluck_D
				{
					soundSet = "HenCluck_D_SoundSet";
					noise = "DeerRoarNoise";
					id = 8;
				};
				class HenCluck_D_High
				{
					soundSet = "HenCluck_D_High_SoundSet";
					noise = "DeerRoarNoise";
					id = 9;
				};
				class HenCluck_E
				{
					soundSet = "HenCluck_E_SoundSet";
					noise = "DeerRoarNoise";
					id = 10;
				};
				class HenCluck_E_High
				{
					soundSet = "HenCluck_E_High_SoundSet";
					noise = "DeerRoarNoise";
					id = 11;
				};
				class HenCluck_Silky
				{
					soundSet = "HenCluck_Silky_SoundSet";
					noise = "DeerRoarNoise";
					id = 12;
				};
				class HenCluck_Silky_High
				{
					soundSet = "HenCluck_Silky_High_SoundSet";
					noise = "DeerRoarNoise";
					id = 13;
				};
				class HenCrow_A
				{
					soundSet = "HenCrow_A_SoundSet";
					noise = "DeerRoarNoise";
					id = 14;
				};
				class HenCrow_B
				{
					soundSet = "HenCrow_B_SoundSet";
					noise = "DeerRoarNoise";
					id = 15;
				};
				class HenCrow_C
				{
					soundSet = "HenCrow_C_SoundSet";
					noise = "DeerRoarNoise";
					id = 16;
				};
				class HenCrow_D
				{
					soundSet = "HenCrow_D_SoundSet";
					noise = "DeerRoarNoise";
					id = 17;
				};
				class HenCrow_E
				{
					soundSet = "HenCrow_E_SoundSet";
					noise = "DeerRoarNoise";
					id = 18;
				};
				class HenCrow_F
				{
					soundSet = "HenCrow_F_SoundSet";
					noise = "DeerRoarNoise";
					id = 19;
				};
				class HenCrow_G
				{
					soundSet = "HenCrow_G_SoundSet";
					noise = "DeerRoarNoise";
					id = 20;
				};
				class HenScream
				{
					soundSet = "HenScream_SoundSet";
					noise = "DeerRoarNoise";
					id = 21;
				};
				class BirdFlapping
				{
					soundSet = "BirdFlapping_SoundSet";
					noise = "DeerRoarNoise";
					id = 22;
				};
				class BirdFlapping_short
				{
					soundSet = "BirdFlapping_short_SoundSet";
					noise = "DeerRoarNoise";
					id = 23;
				};
				class BirdFlapping_mid
				{
					soundSet = "BirdFlapping_mid_SoundSet";
					noise = "DeerRoarNoise";
					id = 24;
				};
				class BirdFlapping_long
				{
					soundSet = "BirdFlapping_long_SoundSet";
					noise = "DeerRoarNoise";
					id = 25;
				};
				class HenCrowX1
				{
					soundSet = "HenCrowX1_SoundSet";
					noise = "DeerRoarNoise";
					id = 26;
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
			movementSpeedMapping[] = {0.0,0.25,0.8,3.0};
		};
	};
};
