////////////////////////////////////////////////////////////////////
//DeRap: characters_data\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Aug 01 14:25:56 2019 : 'file' last modified on Wed Jun 19 12:52:11 2019
////////////////////////////////////////////////////////////////////

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
	class DZ_Characters
	{
		units[] = {"SurvivorMale","SurvivorFemale","SurvivorParts","SurvivorPartsFemale","SurvivorPartsMale","zombieCoverallsBeige","zombieCoverallsBlue","zombieCoverallsGreen","zombieCoverallsGrey","zombieCoverallsWhite","zombieJacketBeige","zombieJacketBlack","zombieJacketBlue","zombieJacketBluechecks","zombieJacketBrown","zombieJacketGreenchecks","zombieJacketGrey","zombieJacketKhaki","zombieJacketMagenta","zombieJacketStripes","zombieShortskirtBeige","zombieShortskirtBlack","zombieShortskirtBrown","zombieShortskirtChecks","zombieShortskirtGreen","zombieShortskirtGrey","zombieShortskirtRed","zombieShortskirtStripes","zombieShortskirtWhite","zombieShortskirtYellow","zombieJacketBeigeNew","zombieJacketBlackNew","zombieJacketBlueNew"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVoice
{
	class NoVoice
	{
		protocol = "RadioProtocolBase";
		variants[] = {1};
		directories[] = {"",""};
	};
};
class CfgIdentities
{
	class Zombie1
	{
		name = "Zombie";
		face = "Zombie1";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
	class Zombie2
	{
		name = "Zombie";
		face = "Zombie2";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
	class PlayerMimics
	{
		name = "PlayerMimics";
		face = "MaleWhiteHeadMimics";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
	class Player_H
	{
		name = "Player_H";
		face = "PlayerFace_H";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
	class MaleAsian
	{
		name = "MaleAsian";
		face = "MaleAsianHead_01_New";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
	class MaleAsian2
	{
		name = "MaleAsian2";
		face = "MaleAsianHead_01_Medium_New";
		glasses = "None";
		speaker = "NoVoice";
		pitch = 1;
	};
};
class CfgFSMs{};
class CfgVehicles
{
	class AllVehicles;
	class Man: AllVehicles{};
	class SurvivorBase: Man
	{
		accuracy = 1000;
		handGunBone = "RightHand";
		weaponBone = "RightHand_Dummy";
		inventorySlot = "Driver";
		attachments[] = {"Head","Shoulder","Melee","Headgear","Mask","Eyewear","Hands","LeftHand","Gloves","Armband","Vest","Body","Back","Hips","Legs","Feet"};
		simulation = "dayzplayer";
		class enfAnimSys
		{
			meshObject = "dz\characters\bodies\player_testing.xob";
			graphName = "dz\anims\workspaces\player\player_main\player_main.agr";
			defaultInstance = "dz\anims\workspaces\player\player_main\player_main.asi";
			skeletonName = "player_testing.xob";
			startNode = "MasterControl";
		};
		class AnimSystem
		{
			meshObject = "INVALID MESH OBJET NAME";
			animGraph = "INVALID ANIMGRAPH NAME";
		};
		class Skinning
		{
			class Steaks
			{
				item = "HumanSteakMeat";
				count = 10;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class Guts
			{
				item = "Guts";
				count = 1;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class Lard
			{
				item = "Lard";
				count = 1;
				quantityMinMaxCoef[] = {0.5,1};
			};
			class Bones
			{
				item = "Bone";
				count = 2;
				quantityMinMaxCoef[] = {0.75,1};
			};
		};
		class DayZPlayer
		{
			class P3DAttachments
			{
				P3DProxies[] = {"spine1","righthand_dummy","spine2","head","rightlegroll","spine3","lefthand","pelvis","leftshoulder","rightshoulder"};
				BoneNames[] = {"Spine1","RightHand_Dummy","Spine2","Head","RightLegRoll","Spine3","LeftHand","Pelvis","LeftShoulder","RightShoulder"};
			};
			class CommandMoveDir
			{
				RunSpringTimeout = 0.1;
				RunSpringMaxChange = 4.0;
				DirFilterTimeout = 0.1;
				DirFilterSpeed = 6.2831855;
				MaxSprintAngle = 45.01;
				ikSetup = "LR";
			};
			class CommandLookAt
			{
				HeadDirFilterTimeout = 0.2;
				HeadDirFilterSpeed = 3.14;
			};
		};
		class MeleeModes
		{
			class Fist
			{
				ammo = "MeleeFist";
				range = 1.2;
			};
			class Fist_Heavy
			{
				ammo = "MeleeFist_Heavy";
				range = 1.2;
			};
			class Fist_Sprint
			{
				ammo = "MeleeFist_Heavy";
				range = 2.8;
			};
		};
		storageCategory = 9;
		class InventoryEquipment
		{
			playerSlots[] = {"Slot_Shoulder","Slot_Melee","Slot_Vest","Slot_Body","Slot_Hips","Slot_Legs","Slot_Back","Slot_Headgear","Slot_Mask","Slot_Eyewear","Slot_Gloves","Slot_Feet","Slot_Armband"};
		};
		class AIPlayerParams
		{
			teamName = "Player";
		};
		displayName = "$STR_cfgvehicles_survivor0";
		descriptionShort = "$STR_cfgvehicles_survivor1";
		directSpeakRange = 30;
		faction = "dz_Civ_US";
		rarityUrban = -1;
		Icon = "\dz\Characters\data\UI\icons\soldier_CA.paa";
		canCarryBackPack = 1;
		supplyRadius = 1.5;
		quickBarBonus = 2;
		customHeads[] = {};
		selectionPersonality = "personality";
		vehicleClass = "People";
		faceType = "MaleWhiteHeadNew";
		languages[] = {};
		threat[] = {1,0.05,0.05};
		extCameraPosition[] = {0.25,-0.25,-2.35};
		extCameraPositionMoving[] = {0.1,-0.25,-2.89};
		extCameraPositionRaisedWeapon[] = {0.55,-0.33,-1.51,-0.45,-0.33,-1.51};
		extCameraPositionRaisedWeaponMoving[] = {0.1,-0.32,-2.54};
		extCameraPositionRaised[] = {0.25,-0.16,-1.39,-0.15,-0.16,-1.39};
		extCameraPositionRaisedMoving[] = {0.25,-0.24,-2.53,-0.15,-0.24,-2.53};
		extCameraSpeedBound[] = {4.2,6.9};
		extCamTopZoomCoef = 0.725;
		htMin = 60;
		htMax = 1800;
		afMax = 30;
		mfMax = 0;
		mFact = 1;
		tBody = 37;
		launcherBone = "launcher";
		selectionHeadWound = "injury_head";
		selectionBodyWound = "injury_body";
		selectionLArmWound = "injury_hands";
		selectionRArmWound = "injury_hands";
		selectionLLegWound = "injury_legs";
		selectionRLegWound = "injury_legs";
		selectionHeadHide = "";
		selectionNeckHide = "";
		memoryPointLStep = "footstepL";
		memoryPointRStep = "footstepR";
		memoryPointAim = "aimPoint";
		memoryPointCameraTarget = "camera";
		memoryPointCommonDamage = "l_femur_hit";
		memoryPointLeaningAxis = "leaning_axis";
		memoryPointAimingAxis = "aiming_axis";
		memoryPointHeadAxis = "head_axis";
		selectionLBrow = "lBrow";
		selectionMBrow = "mBrow";
		selectionRBrow = "rBrow";
		selectionLMouth = "lMouth";
		selectionMMouth = "mMouth";
		selectionRMouth = "rMouth";
		selectionEyelid = "Eyelids";
		selectionLip = "LLip";
		class VegetationSounds
		{
			class bush_walkErc
			{
				soundSet = "bush_walkErc_SoundSet";
				animEventIds[] = {1,2,23,24,51,52};
			};
			class bush_walkCro
			{
				soundSet = "bush_walkCro_SoundSet";
				animEventIds[] = {21,22,31,32,33,34,131};
			};
			class bush_runErc
			{
				soundSet = "bush_runErc_SoundSet";
				animEventIds[] = {3,4,17,101,53,54};
			};
			class bush_sprintErc
			{
				soundSet = "bush_sprintErc_SoundSet";
				animEventIds[] = {5,6,35,36,37,38,100,110,111};
			};
			class bush_scuffErc
			{
				soundSet = "bush_scuffErc_SoundSet";
				animEventIds[] = {7,8};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
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
				class Head
				{
					class Health
					{
						hitpoints = 33;
						transferToGlobalCoef = 2;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 3;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
						class Infected
						{
							class Health
							{
								damage = 0.5;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
					};
					componentNames[] = {"dmgZone_head"};
					fatalInjuryCoef = 0.1;
					inventorySlots[] = {"Headgear","Mask"};
				};
				class Brain
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 1;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
					};
					componentNames[] = {"dmgZone_brain"};
					fatalInjuryCoef = 1;
				};
				class Lungs
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
					};
					componentNames[] = {"dmgZone_lungs"};
					fatalInjuryCoef = -1;
				};
				class Spine
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"dmgZone_spine"};
					fatalInjuryCoef = -1;
				};
				class Liver
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"dmgZone_liver"};
					fatalInjuryCoef = -1;
				};
				class Heart
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 0;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
					};
					componentNames[] = {"dmgZone_heart"};
					fatalInjuryCoef = -1;
				};
				class Torso
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 1.0;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 1;
							};
						};
					};
					componentNames[] = {"dmgZone_torso"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Vest","Body","Back"};
				};
				class LeftArm
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0.33;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0.33;
							};
						};
					};
					componentNames[] = {"dmgZone_leftArm"};
					fatalInjuryCoef = -1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0.33;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0.33;
							};
						};
					};
					componentNames[] = {"dmgZone_rightArm"};
					fatalInjuryCoef = -1;
				};
				class LeftHand
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0.1;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0.1;
							};
						};
					};
					transferToZonesNames[] = {"LeftArm"};
					transferToZonesCoefs[] = {0.1};
					componentNames[] = {"dmgZone_leftHand"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Gloves"};
				};
				class RightHand
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0.1;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0.1;
							};
						};
					};
					transferToZonesNames[] = {"RightArm"};
					transferToZonesCoefs[] = {0.1};
					componentNames[] = {"dmgZone_rightHand"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Gloves"};
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0.33;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0.33;
							};
						};
					};
					componentNames[] = {"dmgZone_leftLeg"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Legs"};
				};
				class RightLeg
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0.33;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0.33;
							};
						};
					};
					componentNames[] = {"dmgZone_rightLeg"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Legs"};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0.1;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0.1;
							};
						};
					};
					transferToZonesNames[] = {"LeftLeg"};
					transferToZonesCoefs[] = {0.2};
					componentNames[] = {"dmgZone_leftFoot"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Feet"};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0.1;
					};
					class Blood
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
					};
					class Shock
					{
						hitpoints = 0;
						transferToGlobalCoef = 1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1;
							};
							class Blood
							{
								damage = 1;
							};
							class Shock
							{
								damage = 0.1;
							};
						};
					};
					transferToZonesNames[] = {"RightLeg"};
					transferToZonesCoefs[] = {0.2};
					componentNames[] = {"dmgZone_rightFoot"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Feet"};
				};
			};
		};
		class NoiseStepStand
		{
			strength = 16.0;
			type = "sound";
		};
		class NoiseStepCrouch
		{
			strength = 6.0;
			type = "sound";
		};
		class NoiseStepProne
		{
			strength = 3.0;
			type = "sound";
		};
		class NoiseLandLight
		{
			strength = 8;
			type = "sound";
		};
		class NoiseLandHeavy
		{
			strength = 16;
			type = "sound";
		};
		class AnimEvents
		{
			class Sounds
			{
				class Dig_Hoe_SoundSet
				{
					soundset = "Dig_Hoe_Soundset";
					id = 1;
				};
				class Hack_Bush_Leaf
				{
					soundSet = "Hack_Bush_Leaf_SoundSet";
					id = 3;
				};
				class putItemInventory
				{
					soundSet = "putItemInventory_SoundSet";
					id = 5;
				};
				class tuneRadio
				{
					soundSet = "tuneRadio_SoundSet";
					id = 8;
				};
				class mapIn
				{
					soundSet = "mapIn_SoundSet";
					id = 9;
				};
				class mapOut
				{
					soundSet = "mapOut_SoundSet";
					id = 10;
				};
				class noteIn
				{
					soundSet = "noteIn_SoundSet";
					id = 11;
				};
				class noteOut
				{
					soundSet = "noteOut_SoundSet";
					id = 12;
				};
				class minePickAxe
				{
					soundSet = "minePickAxe_SoundSet";
					id = 13;
				};
				class Dig_PickAxe_End
				{
					soundSet = "Dig_PickAxe_End_SoundSet";
					id = 14;
				};
				class Dig_PickAxe
				{
					soundSet = "Dig_PickAxe_SoundSet";
					id = 15;
				};
				class cutBarkLoop
				{
					soundSet = "cutBarkLoop_SoundSet";
					id = 16;
				};
				class cutBarkEnd
				{
					soundSet = "cutBarkEnd_SoundSet";
					id = 17;
				};
				class RiverWater_in_A
				{
					soundSet = "RiverWater_in_A_SoundSet";
					id = 21;
				};
				class pickUpCanisterGasolineLight
				{
					soundSet = "pickUpCanisterGasolineLight_SoundSet";
					id = 22;
				};
				class pickUpCanisterGasoline
				{
					soundSet = "pickUpCanisterGasoline_SoundSet";
					id = 23;
				};
				class flip_GasolineCanister
				{
					soundSet = "flip_GasolineCanister_SoundSet";
					id = 24;
				};
				class Pot_Shake
				{
					soundSet = "Pot_Shake_SoundSet";
					id = 25;
				};
				class step_ladder
				{
					soundSet = "step_ladder_Char_Soundset";
					id = 26;
				};
				class step_ladder_run
				{
					soundSet = "step_ladder_run_Char_Soundset";
					id = 27;
				};
				class Flashlight_TurnOn
				{
					soundSet = "Flashlight_TurnOn_SoundSet";
					id = 28;
				};
				class Flashlight_TurnOff
				{
					soundSet = "Flashlight_TurnOff_SoundSet";
					id = 29;
				};
				class turnOnMegaphone
				{
					soundSet = "turnOnMegaphone_SoundSet";
					id = 30;
				};
				class turnOffMegaphone
				{
					soundSet = "turnOffMegaphone_SoundSet";
					id = 31;
				};
				class seedpack_open
				{
					soundSet = "seedpack_open_SoundSet";
					id = 32;
				};
				class seedpack_empty
				{
					soundSet = "seedpack_empty_SoundSet";
					id = 33;
				};
				class Morphine_spear
				{
					soundSet = "Morphine_spear_SoundSet";
					id = 34;
				};
				class Morphine_out
				{
					soundSet = "Morphine_out_Soundset";
					id = 35;
				};
				class Hanckuff_Close_1
				{
					soundSet = "handcuff_close_1_SoundSet";
					id = 36;
				};
				class Hanckuff_Close_2
				{
					soundSet = "handcuff_close_2_SoundSet";
					id = 37;
				};
				class rope_tieup
				{
					soundSet = "rope_tieup_SoundSet";
					id = 38;
				};
				class rope_tieup_end
				{
					soundSet = "rope_tieup_end_SoundSet";
					id = 39;
				};
				class rope_tieup_back
				{
					soundSet = "rope_tieup_back_SoundSet";
					id = 40;
				};
				class CZ75_charge_open
				{
					soundSet = "CZ75_charge_open_SoundSet";
					id = 101;
				};
				class CZ75_charge_open_release
				{
					soundSet = "CZ75_charge_open_release_SoundSet";
					id = 102;
				};
				class CZ75_charge_close
				{
					soundSet = "CZ75_charge_close_SoundSet";
					id = 103;
				};
				class CZ75_charge_close_release
				{
					soundSet = "CZ75_charge_close_release_SoundSet";
					id = 104;
				};
				class CZ75_chamber_load
				{
					soundSet = "CZ75_chamber_load_SoundSet";
					id = 105;
				};
				class CZ75_mag_in
				{
					soundSet = "CZ75_mag_in_SoundSet";
					id = 106;
				};
				class CZ75_mag_load
				{
					soundSet = "CZ75_mag_load_SoundSet";
					id = 107;
				};
				class CZ75_mag_remove
				{
					soundSet = "CZ75_mag_remove_SoundSet";
					id = 108;
				};
				class CZ75_dry
				{
					soundSet = "CZ75_dry_SoundSet";
					id = 110;
				};
				class CZ75_pullout
				{
					soundSet = "CZ75_pullout_SoundSet";
					id = 111;
				};
				class CZ75_dry_uncock
				{
					soundSet = "CZ75_dry_uncock_SoundSet";
					id = 113;
				};
				class CZ75_jamming1
				{
					soundSet = "CZ75_jamming1_SoundSet";
					id = 1001;
				};
				class CZ75_jamming2
				{
					soundSet = "CZ75_jamming2_SoundSet";
					id = 1002;
				};
				class CZ75_jamming3
				{
					soundSet = "CZ75_jamming3_SoundSet";
					id = 1003;
				};
				class CZ75_jamming4
				{
					soundSet = "CZ75_jamming4_SoundSet";
					id = 1004;
				};
				class CZ75_jamming5
				{
					soundSet = "CZ75_jamming5_SoundSet";
					id = 1005;
				};
				class CZ75_jamming6
				{
					soundSet = "CZ75_jamming6_SoundSet";
					id = 1006;
				};
				class CZ75_jamming7
				{
					soundSet = "CZ75_jamming7_SoundSet";
					id = 1007;
				};
				class CZ75_jamming8
				{
					soundSet = "CZ75_jamming8_SoundSet";
					id = 1008;
				};
				class CZ75_jamming9
				{
					soundSet = "CZ75_jamming9_SoundSet";
					id = 1009;
				};
				class CZ75_jamming10
				{
					soundSet = "CZ75_jamming10_SoundSet";
					id = 1010;
				};
				class CZ75_jamming11
				{
					soundSet = "CZ75_jamming11_SoundSet";
					id = 1011;
				};
				class CZ75_jamming12
				{
					soundSet = "CZ75_jamming12_SoundSet";
					id = 1012;
				};
				class CZ75_jamming13
				{
					soundSet = "CZ75_jamming13_SoundSet";
					id = 1013;
				};
				class CZ75_jam
				{
					soundSet = "CZ75_jam_SoundSet";
					id = 115;
				};
				class FNX45_charge_open
				{
					soundSet = "FNX45_charge_open_SoundSet";
					id = 121;
				};
				class FNX45_charge_open_release
				{
					soundSet = "FNX45_charge_open_release_SoundSet";
					id = 122;
				};
				class FNX45_charge_close
				{
					soundSet = "FNX45_charge_close_SoundSet";
					id = 123;
				};
				class FNX45_charge_close_release
				{
					soundSet = "FNX45_charge_close_release_SoundSet";
					id = 124;
				};
				class FNX45_chamber_load
				{
					soundSet = "FNX45_chamber_load_SoundSet";
					id = 125;
				};
				class FNX45_mag_in
				{
					soundSet = "FNX45_mag_in_SoundSet";
					id = 126;
				};
				class FNX45_mag_load
				{
					soundSet = "FNX45_mag_load_SoundSet";
					id = 127;
				};
				class FNX45_mag_remove
				{
					soundSet = "FNX45_mag_remove_SoundSet";
					id = 128;
				};
				class FNX45_dry
				{
					soundSet = "FNX45_dry_SoundSet";
					id = 130;
				};
				class FNX45_pullout
				{
					soundSet = "FNX45_pullout_SoundSet";
					id = 131;
				};
				class FNX45_dry_uncock
				{
					soundSet = "FNX45_dry_uncock_SoundSet";
					id = 132;
				};
				class FNX45_jamming1
				{
					soundSet = "FNX45_jamming1_SoundSet";
					id = 133;
				};
				class FNX45_jamming2
				{
					soundSet = "FNX45_jamming2_SoundSet";
					id = 134;
				};
				class FNX45_jamming3
				{
					soundSet = "FNX45_jamming3_SoundSet";
					id = 135;
				};
				class FNX45_jamming4
				{
					soundSet = "FNX45_jamming4_SoundSet";
					id = 136;
				};
				class FNX45_jamming5
				{
					soundSet = "FNX45_jamming5_SoundSet";
					id = 137;
				};
				class FNX45_jamming6
				{
					soundSet = "FNX45_jamming6_SoundSet";
					id = 138;
				};
				class FNX45_jamming7
				{
					soundSet = "FNX45_jamming7_SoundSet";
					id = 139;
				};
				class FNX45_jamming8
				{
					soundSet = "FNX45_jamming8_SoundSet";
					id = 140;
				};
				class FNX45_jamming9
				{
					soundSet = "FNX45_jamming9_SoundSet";
					id = 141;
				};
				class FNX45_jamming10
				{
					soundSet = "FNX45_jamming10_SoundSet";
					id = 142;
				};
				class FNX45_jamming11
				{
					soundSet = "FNX45_jamming11_SoundSet";
					id = 143;
				};
				class FNX45_jamming12
				{
					soundSet = "FNX45_jamming12_SoundSet";
					id = 144;
				};
				class FNX45_jamming13
				{
					soundSet = "FNX45_jamming13_SoundSet";
					id = 145;
				};
				class FNX45_jam
				{
					soundSet = "FNX45_jam_SoundSet";
					id = 146;
				};
				class IJ70_charge_open
				{
					soundSet = "IJ70_charge_open_SoundSet";
					id = 151;
				};
				class IJ70_charge_open_release
				{
					soundSet = "IJ70_charge_open_release_SoundSet";
					id = 152;
				};
				class IJ70_charge_close
				{
					soundSet = "IJ70_charge_close_SoundSet";
					id = 153;
				};
				class IJ70_charge_close_release
				{
					soundSet = "IJ70_charge_close_release_SoundSet";
					id = 154;
				};
				class IJ70_chamber_load
				{
					soundSet = "IJ70_chamber_load_SoundSet";
					id = 155;
				};
				class IJ70_mag_in
				{
					soundSet = "IJ70_mag_in_SoundSet";
					id = 156;
				};
				class IJ70_mag_load
				{
					soundSet = "IJ70_mag_load_SoundSet";
					id = 157;
				};
				class IJ70_mag_remove
				{
					soundSet = "IJ70_mag_remove_SoundSet";
					id = 158;
				};
				class IJ70_dry
				{
					soundSet = "IJ70_dry_SoundSet";
					id = 160;
				};
				class IJ70_pullout
				{
					soundSet = "IJ70_pullout_SoundSet";
					id = 161;
				};
				class IJ70_mag_push
				{
					soundSet = "IJ70_mag_push_SoundSet";
					id = 162;
				};
				class IJ70_dry_uncock
				{
					soundSet = "IJ70_dry_uncock_SoundSet";
					id = 163;
				};
				class IJ70_jamming1
				{
					soundSet = "IJ70_jamming1_SoundSet";
					id = 1014;
				};
				class IJ70_jamming2
				{
					soundSet = "IJ70_jamming2_SoundSet";
					id = 1015;
				};
				class IJ70_jamming3
				{
					soundSet = "IJ70_jamming3_SoundSet";
					id = 1016;
				};
				class IJ70_jamming4
				{
					soundSet = "IJ70_jamming4_SoundSet";
					id = 1017;
				};
				class IJ70_jamming5
				{
					soundSet = "IJ70_jamming5_SoundSet";
					id = 1018;
				};
				class IJ70_jamming6
				{
					soundSet = "IJ70_jamming6_SoundSet";
					id = 1019;
				};
				class IJ70_jamming7
				{
					soundSet = "IJ70_jamming7_SoundSet";
					id = 1020;
				};
				class IJ70_jamming8
				{
					soundSet = "IJ70_jamming8_SoundSet";
					id = 1021;
				};
				class IJ70_jamming9
				{
					soundSet = "IJ70_jamming9_SoundSet";
					id = 1022;
				};
				class IJ70_jamming10
				{
					soundSet = "IJ70_jamming10_SoundSet";
					id = 1023;
				};
				class IJ70_jamming11
				{
					soundSet = "IJ70_jamming11_SoundSet";
					id = 1024;
				};
				class IJ70_jamming12
				{
					soundSet = "IJ70_jamming12_SoundSet";
					id = 1025;
				};
				class IJ70_jamming13
				{
					soundSet = "IJ70_jamming13_SoundSet";
					id = 1026;
				};
				class IJ70_jam
				{
					soundSet = "IJ70_jam_SoundSet";
					id = 114;
				};
				class CZ61_charge_open
				{
					soundSet = "CZ61_charge_open_SoundSet";
					id = 171;
				};
				class CZ61_charge_open_release
				{
					soundSet = "CZ61_charge_open_release_SoundSet";
					id = 172;
				};
				class CZ61_charge_close
				{
					soundSet = "CZ61_charge_close_SoundSet";
					id = 173;
				};
				class CZ61_charge_close_release
				{
					soundSet = "CZ61_charge_close_release_SoundSet";
					id = 174;
				};
				class CZ61_chamber_load
				{
					soundSet = "CZ61_chamber_load_SoundSet";
					id = 175;
				};
				class CZ61_mag_in
				{
					soundSet = "CZ61_mag_in_SoundSet";
					id = 176;
				};
				class CZ61_mag_load
				{
					soundSet = "CZ61_mag_load_SoundSet";
					id = 177;
				};
				class CZ61_mag_remove
				{
					soundSet = "CZ61_mag_remove_SoundSet";
					id = 178;
				};
				class CZ61_dry
				{
					soundSet = "CZ61_dry_SoundSet";
					id = 180;
				};
				class CZ61_pullout
				{
					soundSet = "CZ61_pullout_SoundSet";
					id = 181;
				};
				class CZ61_mag_out
				{
					soundSet = "CZ61_mag_out_SoundSet";
					id = 182;
				};
				class CZ61_hand
				{
					soundSet = "CZ61_hand_SoundSet";
					id = 183;
				};
				class CZ61_jamming1
				{
					soundSet = "CZ61_jamming1_SoundSet";
					id = 1027;
				};
				class CZ61_jamming2
				{
					soundSet = "CZ61_jamming2_SoundSet";
					id = 1028;
				};
				class CZ61_jamming3
				{
					soundSet = "CZ61_jamming3_SoundSet";
					id = 1029;
				};
				class CZ61_jamming4
				{
					soundSet = "CZ61_jamming4_SoundSet";
					id = 1030;
				};
				class CZ61_jamming5
				{
					soundSet = "CZ61_jamming5_SoundSet";
					id = 1031;
				};
				class CZ61_jamming6
				{
					soundSet = "CZ61_jamming6_SoundSet";
					id = 1032;
				};
				class CZ61_jamming7
				{
					soundSet = "CZ61_jamming7_SoundSet";
					id = 1033;
				};
				class CZ61_jamming8
				{
					soundSet = "CZ61_jamming8_SoundSet";
					id = 1034;
				};
				class CZ61_jamming9
				{
					soundSet = "CZ61_jamming9_SoundSet";
					id = 1035;
				};
				class CZ61_jamming10
				{
					soundSet = "CZ61_jamming10_SoundSet";
					id = 1036;
				};
				class CZ61_jamming11
				{
					soundSet = "CZ61_jamming11_SoundSet";
					id = 1037;
				};
				class CZ61_jamming12
				{
					soundSet = "CZ61_jamming12_SoundSet";
					id = 1038;
				};
				class CZ61_jamming13
				{
					soundSet = "CZ61_jamming13_SoundSet";
					id = 1039;
				};
				class CZ61_jam
				{
					soundSet = "CZ61_jam_SoundSet";
					id = 116;
				};
				class ump45_charge_open
				{
					soundSet = "ump45_charge_open_SoundSet";
					id = 191;
				};
				class ump45_charge_open_release
				{
					soundSet = "ump45_charge_open_release_SoundSet";
					id = 192;
				};
				class ump45_charge_close
				{
					soundSet = "ump45_charge_close_SoundSet";
					id = 193;
				};
				class ump45_charge_close_release
				{
					soundSet = "ump45_charge_close_release_SoundSet";
					id = 194;
				};
				class ump45_chamber_load
				{
					soundSet = "ump45_chamber_load_SoundSet";
					id = 195;
				};
				class ump45_mag_in
				{
					soundSet = "ump45_mag_in_SoundSet";
					id = 196;
				};
				class ump45_mag_load
				{
					soundSet = "ump45_mag_load_SoundSet";
					id = 197;
				};
				class ump45_mag_remove
				{
					soundSet = "ump45_mag_remove_SoundSet";
					id = 198;
				};
				class ump45_dry
				{
					soundSet = "ump45_dry_SoundSet";
					id = 200;
				};
				class ump45_pullout
				{
					soundSet = "ump45_pullout_SoundSet";
					id = 201;
				};
				class ump45_mag_out
				{
					soundSet = "ump45_mag_out_SoundSet";
					id = 202;
				};
				class ump45_jamming1
				{
					soundSet = "ump45_jamming1_SoundSet";
					id = 1051;
				};
				class ump45_jamming2
				{
					soundSet = "ump45_jamming2_SoundSet";
					id = 1052;
				};
				class ump45_jamming3
				{
					soundSet = "ump45_jamming3_SoundSet";
					id = 1053;
				};
				class ump45_jamming4
				{
					soundSet = "ump45_jamming4_SoundSet";
					id = 1054;
				};
				class ump45_jamming5
				{
					soundSet = "ump45_jamming5_SoundSet";
					id = 1055;
				};
				class ump45_jamming6
				{
					soundSet = "ump45_jamming6_SoundSet";
					id = 1056;
				};
				class ump45_jamming7
				{
					soundSet = "ump45_jamming7_SoundSet";
					id = 1057;
				};
				class ump45_jamming8
				{
					soundSet = "ump45_jamming8_SoundSet";
					id = 1058;
				};
				class ump45_jamming9
				{
					soundSet = "ump45_jamming9_SoundSet";
					id = 1059;
				};
				class ump45_jamming10
				{
					soundSet = "ump45_jamming10_SoundSet";
					id = 1060;
				};
				class ump45_jamming11
				{
					soundSet = "ump45_jamming11_SoundSet";
					id = 1061;
				};
				class ump45_jamming12
				{
					soundSet = "ump45_jamming12_SoundSet";
					id = 1062;
				};
				class ump45_jam
				{
					soundSet = "ump45_jam_SoundSet";
					id = 117;
				};
				class MP5K_hand
				{
					soundSet = "MP5K_hand_SoundSet";
					id = 210;
				};
				class MP5K_charge_open
				{
					soundSet = "MP5K_charge_open_SoundSet";
					id = 211;
				};
				class MP5K_charge_open_release
				{
					soundSet = "MP5K_charge_open_release_SoundSet";
					id = 212;
				};
				class MP5K_charge_close
				{
					soundSet = "MP5K_charge_close_SoundSet";
					id = 213;
				};
				class MP5K_charge_close_release
				{
					soundSet = "MP5K_charge_close_release_SoundSet";
					id = 214;
				};
				class MP5K_chamber_load
				{
					soundSet = "MP5K_chamber_load_SoundSet";
					id = 215;
				};
				class MP5K_mag_in
				{
					soundSet = "MP5K_mag_in_SoundSet";
					id = 216;
				};
				class MP5K_mag_load
				{
					soundSet = "MP5K_mag_load_SoundSet";
					id = 217;
				};
				class MP5K_mag_out
				{
					soundSet = "MP5K_mag_out_SoundSet";
					id = 222;
				};
				class MP5K_mag_remove
				{
					soundSet = "MP5K_mag_remove_SoundSet";
					id = 218;
				};
				class MP5K_dry
				{
					soundSet = "MP5K_dry_SoundSet";
					id = 220;
				};
				class MP5K_pullout
				{
					soundSet = "MP5K_pullout_SoundSet";
					id = 221;
				};
				class MP5_jamming1
				{
					soundSet = "MP5_jamming1_SoundSet";
					id = 223;
				};
				class MP5_jamming2
				{
					soundSet = "MP5_jamming2_SoundSet";
					id = 1040;
				};
				class MP5_jamming3
				{
					soundSet = "MP5_jamming3_SoundSet";
					id = 1041;
				};
				class MP5_jamming4
				{
					soundSet = "MP5_jamming4_SoundSet";
					id = 1042;
				};
				class MP5_jamming5
				{
					soundSet = "MP5_jamming5_SoundSet";
					id = 1043;
				};
				class MP5_jamming6
				{
					soundSet = "MP5_jamming6_SoundSet";
					id = 1044;
				};
				class MP5_jamming7
				{
					soundSet = "MP5_jamming7_SoundSet";
					id = 1045;
				};
				class MP5_jamming8
				{
					soundSet = "MP5_jamming8_SoundSet";
					id = 1046;
				};
				class MP5_jamming9
				{
					soundSet = "MP5_jamming9_SoundSet";
					id = 1047;
				};
				class MP5_jamming10
				{
					soundSet = "MP5_jamming10_SoundSet";
					id = 1048;
				};
				class MP5_jamming11
				{
					soundSet = "MP5_jamming11_SoundSet";
					id = 1049;
				};
				class MP5_jamming12
				{
					soundSet = "MP5_jamming12_SoundSet";
					id = 1050;
				};
				class MP5_jamming13
				{
					soundSet = "MP5_jamming13_SoundSet";
					id = 204;
				};
				class MP5_jam
				{
					soundSet = "MP5_jam_SoundSet";
					id = 203;
				};
				class IZH18_charge_open
				{
					soundSet = "IZH18_charge_open_SoundSet";
					id = 231;
				};
				class IZH18_charge_close
				{
					soundSet = "IZH18_charge_close_SoundSet";
					id = 233;
				};
				class IZH18_charge_close_release
				{
					soundSet = "IZH18_charge_close_release_SoundSet";
					id = 234;
				};
				class IZH18_chamber_load
				{
					soundSet = "IZH18_chamber_load_SoundSet";
					id = 235;
				};
				class IZH18_dry
				{
					soundSet = "IZH18_dry_SoundSet";
					id = 240;
				};
				class IZH18_pullout
				{
					soundSet = "IZH18_pullout_SoundSet";
					id = 241;
				};
				class IZH18_jamming1
				{
					soundSet = "IZH18_jamming1_SoundSet";
					id = 242;
				};
				class IZH18_jamming2
				{
					soundSet = "IZH18_jamming2_SoundSet";
					id = 243;
				};
				class IZH18_jamming3
				{
					soundSet = "IZH18_jamming3_SoundSet";
					id = 244;
				};
				class IZH18_jamming4
				{
					soundSet = "IZH18_jamming4_SoundSet";
					id = 245;
				};
				class IZH18_jamming5
				{
					soundSet = "IZH18_jamming5_SoundSet";
					id = 246;
				};
				class IZH18_jamming6
				{
					soundSet = "IZH18_jamming6_SoundSet";
					id = 247;
				};
				class IZH18_jamming7
				{
					soundSet = "IZH18_jamming7_SoundSet";
					id = 248;
				};
				class IZH18_jamming8
				{
					soundSet = "IZH18_jamming8_SoundSet";
					id = 249;
				};
				class IZH18_jam
				{
					soundSet = "IZH18_jam_SoundSet";
					id = 250;
				};
				class AK_charge_open
				{
					soundSet = "AK_charge_open_SoundSet";
					id = 251;
				};
				class AK_charge_open_release
				{
					soundSet = "AK_charge_open_release_SoundSet";
					id = 252;
				};
				class AK_charge_close
				{
					soundSet = "AK_charge_close_SoundSet";
					id = 253;
				};
				class AK_charge_close_release
				{
					soundSet = "AK_charge_close_release_SoundSet";
					id = 254;
				};
				class AK_chamber_load2
				{
					soundSet = "AK_chamber_load2_SoundSet";
					id = 255;
				};
				class AK_mag_in
				{
					soundSet = "AK_mag_in_SoundSet";
					id = 256;
				};
				class AK_mag_load
				{
					soundSet = "AK_mag_load_SoundSet";
					id = 257;
				};
				class AK_mag_remove
				{
					soundSet = "AK_mag_remove_SoundSet";
					id = 258;
				};
				class AK_jamming
				{
					soundSet = "AK_jamming_SoundSet";
					id = 259;
				};
				class AK_dry
				{
					soundSet = "AK_dry_SoundSet";
					id = 260;
				};
				class AK_pullout
				{
					soundSet = "AK_pullout_SoundSet";
					id = 261;
				};
				class AK_dry_uncock
				{
					soundSet = "AK_dry_uncock_SoundSet";
					id = 262;
				};
				class AK_hand
				{
					soundSet = "AK_hand_SoundSet";
					id = 264;
				};
				class AK_hand3
				{
					soundSet = "AK_hand3_SoundSet";
					id = 266;
				};
				class AK_weapon_down
				{
					soundSet = "AK_weapon_down_SoundSet";
					id = 265;
				};
				class AK_jamming1
				{
					soundSet = "AK_jamming1_SoundSet";
					id = 1063;
				};
				class AK_jamming2
				{
					soundSet = "AK_jamming2_SoundSet";
					id = 1064;
				};
				class AK_jamming3
				{
					soundSet = "AK_jamming3_SoundSet";
					id = 1065;
				};
				class AK_jamming4
				{
					soundSet = "AK_jamming4_SoundSet";
					id = 1066;
				};
				class AK_jamming5
				{
					soundSet = "AK_jamming5_SoundSet";
					id = 1067;
				};
				class AK_jamming6
				{
					soundSet = "AK_jamming6_SoundSet";
					id = 1068;
				};
				class AK_jamming7
				{
					soundSet = "AK_jamming7_SoundSet";
					id = 1069;
				};
				class AK_jamming8
				{
					soundSet = "AK_jamming8_SoundSet";
					id = 1070;
				};
				class AK_jamming9
				{
					soundSet = "AK_jamming9_SoundSet";
					id = 1071;
				};
				class AK_jam
				{
					soundSet = "AK_jam_SoundSet";
					id = 1072;
				};
				class SVD_charge_open
				{
					soundSet = "SVD_charge_open_SoundSet";
					id = 271;
				};
				class SVD_charge_open_release
				{
					soundSet = "SVD_charge_open_release_SoundSet";
					id = 272;
				};
				class SVD_charge_close
				{
					soundSet = "SVD_charge_close_SoundSet";
					id = 273;
				};
				class SVD_charge_close_release
				{
					soundSet = "SVD_charge_close_release_SoundSet";
					id = 274;
				};
				class SVD_chamber_load
				{
					soundSet = "SVD_chamber_load_SoundSet";
					id = 275;
				};
				class SVD_mag_in
				{
					soundSet = "SVD_mag_in_SoundSet";
					id = 276;
				};
				class SVD_mag_load
				{
					soundSet = "SVD_mag_load_SoundSet";
					id = 277;
				};
				class SVD_mag_out
				{
					soundSet = "SVD_mag_out_SoundSet";
					id = 282;
				};
				class SVD_mag_remove
				{
					soundSet = "SVD_mag_remove_SoundSet";
					id = 278;
				};
				class SVD_dry
				{
					soundSet = "SVD_dry_SoundSet";
					id = 280;
				};
				class SVD_pullout
				{
					soundSet = "SVD_pullout_SoundSet";
					id = 281;
				};
				class SVD_chamber_load2
				{
					soundSet = "SVD_chamber_load2_SoundSet";
					id = 283;
				};
				class SVD_hand
				{
					soundSet = "SVD_hand_SoundSet";
					id = 284;
				};
				class SVD_weapon_down
				{
					soundSet = "SVD_weapon_down_SoundSet";
					id = 285;
				};
				class SVD_jamming1
				{
					soundSet = "SVD_jamming1_SoundSet";
					id = 290;
				};
				class SVD_jamming2
				{
					soundSet = "SVD_jamming2_SoundSet";
					id = 291;
				};
				class SVD_jamming3
				{
					soundSet = "SVD_jamming3_SoundSet";
					id = 292;
				};
				class SVD_jamming4
				{
					soundSet = "SVD_jamming4_SoundSet";
					id = 293;
				};
				class SVD_jamming5
				{
					soundSet = "SVD_jamming5_SoundSet";
					id = 294;
				};
				class SVD_jamming6
				{
					soundSet = "SVD_jamming6_SoundSet";
					id = 295;
				};
				class SVD_jamming7
				{
					soundSet = "SVD_jamming7_SoundSet";
					id = 296;
				};
				class SVD_jamming8
				{
					soundSet = "SVD_jamming8_SoundSet";
					id = 297;
				};
				class SVD_jamming9
				{
					soundSet = "SVD_jamming8_SoundSet";
					id = 298;
				};
				class SVD_jam
				{
					soundSet = "SVD_jam_SoundSet";
					id = 299;
				};
				class Mosin_charge_open
				{
					soundSet = "Mosin_charge_open_SoundSet";
					id = 301;
				};
				class Mosin_chamber_load
				{
					soundSet = "Mosin_chamber_load_SoundSet";
					id = 302;
				};
				class Mosin_charge_close
				{
					soundSet = "Mosin_charge_close_SoundSet";
					id = 303;
				};
				class Mosin_dry
				{
					soundSet = "Mosin_dry_SoundSet";
					id = 307;
				};
				class Mosin_pullout
				{
					soundSet = "mosin_pullout_SoundSet";
					id = 308;
				};
				class Mosin_jamming1
				{
					soundSet = "Mosin_jamming1_SoundSet";
					id = 309;
				};
				class Mosin_jamming2
				{
					soundSet = "Mosin_jamming2_SoundSet";
					id = 310;
				};
				class Mosin_jamming3
				{
					soundSet = "Mosin_jamming3_SoundSet";
					id = 311;
				};
				class Mosin_jamming4
				{
					soundSet = "Mosin_jamming4_SoundSet";
					id = 312;
				};
				class Mosin_jamming5
				{
					soundSet = "Mosin_jamming5_SoundSet";
					id = 313;
				};
				class Mosin_jamming6
				{
					soundSet = "Mosin_jamming6_SoundSet";
					id = 314;
				};
				class Mosin_jamming7
				{
					soundSet = "Mosin_jamming7_SoundSet";
					id = 315;
				};
				class Mosin_jamming8
				{
					soundSet = "Mosin_jamming8_SoundSet";
					id = 316;
				};
				class Mosin_jamming9
				{
					soundSet = "Mosin_jamming9_SoundSet";
					id = 317;
				};
				class Mosin_jamming10
				{
					soundSet = "Mosin_jamming10_SoundSet";
					id = 318;
				};
				class Mosin_jamming11
				{
					soundSet = "Mosin_jamming11_SoundSet";
					id = 319;
				};
				class Mosin_jam
				{
					soundSet = "Mosin_jam_SoundSet";
					id = 320;
				};
				class M4_charge_open
				{
					soundSet = "M4_charge_open_SoundSet";
					id = 321;
				};
				class M4_charge_open_release
				{
					soundSet = "M4_charge_open_release_SoundSet";
					id = 322;
				};
				class M4_charge_close
				{
					soundSet = "M4_charge_close_SoundSet";
					id = 323;
				};
				class M4_charge_close_release
				{
					soundSet = "M4_charge_close_release_SoundSet";
					id = 324;
				};
				class M4_charge_close_release2
				{
					soundSet = "M4_charge_close_release2_SoundSet";
					id = 382;
				};
				class M4_chamber_load
				{
					soundSet = "M4_chamber_load_SoundSet";
					id = 325;
				};
				class M4_mag_in
				{
					soundSet = "M4_mag_in_SoundSet";
					id = 326;
				};
				class M4_mag_load
				{
					soundSet = "M4_mag_load_SoundSet";
					id = 327;
				};
				class M4_mag_out
				{
					soundSet = "M4_mag_out_SoundSet";
					id = 328;
				};
				class M4_mag_remove
				{
					soundSet = "M4_mag_remove_SoundSet";
					id = 329;
				};
				class M4_dry
				{
					soundSet = "M4_dry_SoundSet";
					id = 331;
				};
				class M4_pullout
				{
					soundSet = "M4_pullout_SoundSet";
					id = 332;
				};
				class M4_hand
				{
					soundSet = "M4_hand_SoundSet";
					id = 333;
				};
				class M4_weapon_down
				{
					soundSet = "M4_weapon_down_SoundSet";
					id = 334;
				};
				class M4_jamming1
				{
					soundSet = "M4_jamming1_SoundSet";
					id = 335;
				};
				class M4_jamming2
				{
					soundSet = "M4_jamming2_SoundSet";
					id = 336;
				};
				class M4_jamming3
				{
					soundSet = "M4_jamming3_SoundSet";
					id = 337;
				};
				class M4_jamming4
				{
					soundSet = "M4_jamming4_SoundSet";
					id = 338;
				};
				class M4_jamming5
				{
					soundSet = "M4_jamming5_SoundSet";
					id = 339;
				};
				class M4_jamming6
				{
					soundSet = "M4_jamming6_SoundSet";
					id = 340;
				};
				class M4_jamming7
				{
					soundSet = "M4_jamming7_SoundSet";
					id = 341;
				};
				class M4_jamming8
				{
					soundSet = "M4_jamming8_SoundSet";
					id = 383;
				};
				class M4_jamming9
				{
					soundSet = "M4_jamming9_SoundSet";
					id = 384;
				};
				class M4_jamming10
				{
					soundSet = "M4_jamming10_SoundSet";
					id = 385;
				};
				class M4_jamming11
				{
					soundSet = "M4_jamming11_SoundSet";
					id = 386;
				};
				class M4_jamming12
				{
					soundSet = "M4_jamming12_SoundSet";
					id = 387;
				};
				class M4_jamming13
				{
					soundSet = "M4_jamming13_SoundSet";
					id = 388;
				};
				class M4_jam
				{
					soundSet = "M4_jam_SoundSet";
					id = 300;
				};
				class MP133_charge_open
				{
					soundSet = "MP133_charge_open_SoundSet";
					id = 342;
				};
				class MP133_charge_close
				{
					soundSet = "MP133_charge_close_SoundSet";
					id = 343;
				};
				class MP133_chamber_load1
				{
					soundSet = "MP133_chamber_load1_SoundSet";
					id = 345;
				};
				class MP133_chamber_load2
				{
					soundSet = "MP133_chamber_load2_SoundSet";
					id = 346;
				};
				class MP133_weapon_down
				{
					soundSet = "MP133_weapon_down_SoundSet";
					id = 347;
				};
				class MP133_hand
				{
					soundSet = "MP133_hand_SoundSet";
					id = 348;
				};
				class MP133_dry
				{
					soundSet = "MP133_dry_SoundSet";
					id = 349;
				};
				class MP133_pullout
				{
					soundSet = "MP133_pullout_SoundSet";
					id = 350;
				};
				class MP133_jamming1
				{
					soundSet = "MP133_jamming1_SoundSet";
					id = 351;
				};
				class MP133_jamming2
				{
					soundSet = "MP133_jamming2_SoundSet";
					id = 352;
				};
				class MP133_jamming3
				{
					soundSet = "MP133_jamming3_SoundSet";
					id = 353;
				};
				class MP133_jamming4
				{
					soundSet = "MP133_jamming4_SoundSet";
					id = 354;
				};
				class MP133_jamming5
				{
					soundSet = "MP133_jamming5_SoundSet";
					id = 355;
				};
				class MP133_jamming6
				{
					soundSet = "MP133_jamming6_SoundSet";
					id = 356;
				};
				class MP133_jamming7
				{
					soundSet = "MP133_jamming7_SoundSet";
					id = 357;
				};
				class MP133_jamming8
				{
					soundSet = "MP133_jamming8_SoundSet";
					id = 358;
				};
				class MP133_jamming9
				{
					soundSet = "MP133_jamming9_SoundSet";
					id = 359;
				};
				class MP133_jamming10
				{
					soundSet = "MP133_jamming10_SoundSet";
					id = 360;
				};
				class MP133_jam
				{
					soundSet = "MP133_jam_SoundSet";
					id = 380;
				};
				class IZH43_charge_open
				{
					soundSet = "IZH43_charge_open_SoundSet";
					id = 361;
				};
				class IZH43_charge_open_release
				{
					soundSet = "IZH43_charge_open_release_SoundSet";
					id = 362;
				};
				class IZH43_charge_close
				{
					soundSet = "IZH43_charge_close_SoundSet";
					id = 363;
				};
				class IZH43_chamber_load
				{
					soundSet = "IZH43_chamber_load_SoundSet";
					id = 364;
				};
				class IZH43_chamber_fast_load
				{
					soundSet = "IZH43_chamber_fast_load_SoundSet";
					id = 365;
				};
				class IZH43_chamber_fast_in
				{
					soundSet = "IZH43_chamber_fast_in_SoundSet";
					id = 366;
				};
				class IZH43_chamber_fast_out
				{
					soundSet = "IZH43_chamber_fast_out_SoundSet";
					id = 367;
				};
				class IZH43_weapon_down
				{
					soundSet = "IZH43_weapon_down_SoundSet";
					id = 368;
				};
				class IZH43_hand
				{
					soundSet = "IZH43_hand_SoundSet";
					id = 369;
				};
				class IZH43_dry
				{
					soundSet = "IZH43_dry_SoundSet";
					id = 370;
				};
				class IZH43_pullout
				{
					soundSet = "IZH43_pullout_SoundSet";
					id = 371;
				};
				class IZH43_jamming1
				{
					soundSet = "IZH43_jamming1_SoundSet";
					id = 372;
				};
				class IZH43_jamming2
				{
					soundSet = "IZH43_jamming2_SoundSet";
					id = 373;
				};
				class IZH43_jamming3
				{
					soundSet = "IZH43_jamming3_SoundSet";
					id = 374;
				};
				class IZH43_jamming4
				{
					soundSet = "IZH43_jamming4_SoundSet";
					id = 375;
				};
				class IZH43_jamming5
				{
					soundSet = "IZH43_jamming5_SoundSet";
					id = 376;
				};
				class IZH43_jamming6
				{
					soundSet = "IZH43_jamming6_SoundSet";
					id = 377;
				};
				class IZH43_jamming7
				{
					soundSet = "IZH43_jamming7_SoundSet";
					id = 378;
				};
				class IZH43_jamming8
				{
					soundSet = "IZH43_jamming8_SoundSet";
					id = 379;
				};
				class IZH43_jam
				{
					soundSet = "IZH43_jam_SoundSet";
					id = 381;
				};
				class CR527_charge_open
				{
					soundSet = "CR527_charge_open_SoundSet";
					id = 501;
				};
				class CR527_charge_open_release
				{
					soundSet = "CR527_charge_open_release_SoundSet";
					id = 502;
				};
				class CR527_charge_close
				{
					soundSet = "CR527_charge_close_SoundSet";
					id = 503;
				};
				class CR527_charge_close_release
				{
					soundSet = "CR527_charge_close_release_SoundSet";
					id = 504;
				};
				class CR527_chamber_load
				{
					soundSet = "CR527_chamber_load_SoundSet";
					id = 505;
				};
				class CR527_mag_in
				{
					soundSet = "CR527_mag_in_SoundSet";
					id = 506;
				};
				class CR527_mag_load
				{
					soundSet = "CR527_mag_load_SoundSet";
					id = 507;
				};
				class CR527_mag_out
				{
					soundSet = "CR527_mag_out_SoundSet";
					id = 509;
				};
				class CR527_mag_remove
				{
					soundSet = "CR527_mag_remove_SoundSet";
					id = 508;
				};
				class CR527_dry
				{
					soundSet = "CR527_dry_SoundSet";
					id = 510;
				};
				class CR527_pullout
				{
					soundSet = "CR527_pullout_SoundSet";
					id = 511;
				};
				class CR527_hand1
				{
					soundSet = "CR527_hand1_SoundSet";
					id = 512;
				};
				class CR527_hand2
				{
					soundSet = "CR527_hand2_SoundSet";
					id = 513;
				};
				class CR527_hand3
				{
					soundSet = "CR527_hand3_SoundSet";
					id = 514;
				};
				class CR527_hand4
				{
					soundSet = "CR527_hand4_SoundSet";
					id = 527;
				};
				class CR527_jamming1
				{
					soundSet = "CR527_jamming1_SoundSet";
					id = 515;
				};
				class CR527_jamming2
				{
					soundSet = "CR527_jamming2_SoundSet";
					id = 516;
				};
				class CR527_jamming3
				{
					soundSet = "CR527_jamming3_SoundSet";
					id = 517;
				};
				class CR527_jamming4
				{
					soundSet = "CR527_jamming4_SoundSet";
					id = 518;
				};
				class CR527_jamming5
				{
					soundSet = "CR527_jamming5_SoundSet";
					id = 519;
				};
				class CR527_jamming6
				{
					soundSet = "CR527_jamming6_SoundSet";
					id = 520;
				};
				class CR527_jamming7
				{
					soundSet = "CR527_jamming7_SoundSet";
					id = 521;
				};
				class CR527_jamming8
				{
					soundSet = "CR527_jamming8_SoundSet";
					id = 522;
				};
				class CR527_jamming9
				{
					soundSet = "CR527_jamming9_SoundSet";
					id = 523;
				};
				class CR527_jamming10
				{
					soundSet = "CR527_jamming10_SoundSet";
					id = 524;
				};
				class CR527_jamming11
				{
					soundSet = "CR527_jamming11_SoundSet";
					id = 525;
				};
				class CR527_jam
				{
					soundSet = "CR527_jam_SoundSet";
					id = 526;
				};
				class SKS_charge_open
				{
					soundSet = "SKS_charge_open_SoundSet";
					id = 541;
				};
				class SKS_charge_open_release
				{
					soundSet = "SKS_charge_open_release_SoundSet";
					id = 542;
				};
				class SKS_chamber_load
				{
					soundSet = "SKS_chamber_load_SoundSet";
					id = 543;
				};
				class SKS_charge_close
				{
					soundSet = "SKS_charge_close_SoundSet";
					id = 544;
				};
				class SKS_charge_close_release
				{
					soundSet = "SKS_charge_close_release_SoundSet";
					id = 545;
				};
				class SKS_dry
				{
					soundSet = "SKS_dry_SoundSet";
					id = 546;
				};
				class SKS_pullout
				{
					soundSet = "SKS_pullout_SoundSet";
					id = 547;
				};
				class SKS_jamming1
				{
					soundSet = "SKS_jamming1_SoundSet";
					id = 548;
				};
				class SKS_jamming2
				{
					soundSet = "SKS_jamming2_SoundSet";
					id = 549;
				};
				class SKS_jamming3
				{
					soundSet = "SKS_jamming3_SoundSet";
					id = 550;
				};
				class SKS_jamming4
				{
					soundSet = "SKS_jamming4_SoundSet";
					id = 551;
				};
				class SKS_jamming5
				{
					soundSet = "SKS_jamming5_SoundSet";
					id = 552;
				};
				class SKS_jamming6
				{
					soundSet = "SKS_jamming6_SoundSet";
					id = 553;
				};
				class SKS_jamming7
				{
					soundSet = "SKS_jamming7_SoundSet";
					id = 554;
				};
				class SKS_jam
				{
					soundSet = "SKS_jam_SoundSet";
					id = 559;
				};
				class SKS_hand2
				{
					soundSet = "SKS_hand2_SoundSet";
					id = 560;
				};
				class SKS_hand3
				{
					soundSet = "SKS_hand3_SoundSet";
					id = 561;
				};
				class SKS_hand4
				{
					soundSet = "SKS_hand4_SoundSet";
					id = 562;
				};
				class SKS_last
				{
					soundSet = "SKS_last_SoundSet";
					id = 563;
				};
				class SKS_clip_in
				{
					soundSet = "SKS_clip_in_SoundSet";
					id = 564;
				};
				class SKS_clip_out
				{
					soundSet = "SKS_clip_out_SoundSet";
					id = 565;
				};
				class SKS_clip_shell
				{
					soundSet = "SKS_clip_shell_SoundSet";
					id = 566;
				};
				class SKS_clip_shell2
				{
					soundSet = "SKS_clip_shell_SoundSet";
					id = 567;
				};
				class SKS_clip_shell3
				{
					soundSet = "SKS_clip_shell_SoundSet";
					id = 568;
				};
				class SKS_clip_shell4
				{
					soundSet = "SKS_clip_shell_SoundSet";
					id = 569;
				};
				class Win_charge_open
				{
					soundSet = "Win_charge_open_SoundSet";
					id = 570;
				};
				class Win_charge_open_release
				{
					soundSet = "Win_charge_open_release_SoundSet";
					id = 571;
				};
				class Win_charge_close
				{
					soundSet = "Win_charge_close_SoundSet";
					id = 572;
				};
				class Win_charge_close_release
				{
					soundSet = "Win_charge_close_release_SoundSet";
					id = 573;
				};
				class Win_chamber_load
				{
					soundSet = "Win_chamber_load_SoundSet";
					id = 574;
				};
				class Win_dry
				{
					soundSet = "Win_dry_SoundSet";
					id = 575;
				};
				class Win_pullout
				{
					soundSet = "Win_pullout_SoundSet";
					id = 576;
				};
				class Win_hand
				{
					soundSet = "Win_hand_SoundSet";
					id = 577;
				};
				class Win_jam
				{
					soundSet = "Win_jam_SoundSet";
					id = 578;
				};
				class Win_jamming1
				{
					soundSet = "Win_jamming1_SoundSet";
					id = 579;
				};
				class Win_jamming2
				{
					soundSet = "Win_jamming2_SoundSet";
					id = 580;
				};
				class Win_jamming3
				{
					soundSet = "Win_jamming3_SoundSet";
					id = 581;
				};
				class Win_jamming4
				{
					soundSet = "Win_jamming4_SoundSet";
					id = 582;
				};
				class Win_jamming5
				{
					soundSet = "Win_jamming5_SoundSet";
					id = 583;
				};
				class Win_jamming6
				{
					soundSet = "Win_jamming6_SoundSet";
					id = 584;
				};
				class Win_jamming7
				{
					soundSet = "Win_jamming7_SoundSet";
					id = 585;
				};
				class Win_jamming8
				{
					soundSet = "Win_jamming8_SoundSet";
					id = 586;
				};
				class Win_jamming9
				{
					soundSet = "Win_jamming9_SoundSet";
					id = 587;
				};
				class Win_jamming10
				{
					soundSet = "Win_jamming10_SoundSet";
					id = 588;
				};
				class FNFAL_charge_open
				{
					soundSet = "FNFAL_charge_open_SoundSet";
					id = 601;
				};
				class FNFAL_charge_open_release
				{
					soundSet = "FNFAL_charge_open_release_SoundSet";
					id = 602;
				};
				class FNFAL_charge_close
				{
					soundSet = "FNFAL_charge_close_SoundSet";
					id = 603;
				};
				class FNFAL_charge_close_release
				{
					soundSet = "FNFAL_charge_close_release_SoundSet";
					id = 604;
				};
				class FNFAL_chamber_load
				{
					soundSet = "FNFAL_chamber_load_SoundSet";
					id = 605;
				};
				class FNFAL_mag_in
				{
					soundSet = "FNFAL_mag_in_SoundSet";
					id = 606;
				};
				class FNFAL_mag_load
				{
					soundSet = "FNFAL_mag_load_SoundSet";
					id = 607;
				};
				class FNFAL_mag_out
				{
					soundSet = "FNFAL_mag_out_SoundSet";
					id = 608;
				};
				class FNFAL_mag_remove
				{
					soundSet = "FNFAL_mag_remove_SoundSet";
					id = 609;
				};
				class FNFAL_dry
				{
					soundSet = "FNFAL_dry_SoundSet";
					id = 610;
				};
				class FNFAL_pullout
				{
					soundSet = "FNFAL_pullout_SoundSet";
					id = 611;
				};
				class FNFAL_hand
				{
					soundSet = "FNFAL_hand_SoundSet";
					id = 612;
				};
				class FNFAL_weapon_down
				{
					soundSet = "FNFAL_weapon_down_SoundSet";
					id = 613;
				};
				class FNFAL_jam
				{
					soundSet = "FNFAL_jam_SoundSet";
					id = 614;
				};
				class FNFAL_jamming1
				{
					soundSet = "FNFAL_jamming1_SoundSet";
					id = 615;
				};
				class FNFAL_jamming2
				{
					soundSet = "FNFAL_jamming2_SoundSet";
					id = 616;
				};
				class FNFAL_jamming3
				{
					soundSet = "FNFAL_jamming3_SoundSet";
					id = 617;
				};
				class FNFAL_jamming4
				{
					soundSet = "FNFAL_jamming4_SoundSet";
					id = 618;
				};
				class FNFAL_jamming5
				{
					soundSet = "FNFAL_jamming5_SoundSet";
					id = 619;
				};
				class FNFAL_jamming6
				{
					soundSet = "FNFAL_jamming6_SoundSet";
					id = 620;
				};
				class FNFAL_jamming7
				{
					soundSet = "FNFAL_jamming7_SoundSet";
					id = 621;
				};
				class FNFAL_jamming8
				{
					soundSet = "FNFAL_jamming8_SoundSet";
					id = 622;
				};
				class FNFAL_jamming9
				{
					soundSet = "FNFAL_jamming9_SoundSet";
					id = 623;
				};
				class FNFAL_jamming10
				{
					soundSet = "FNFAL_jamming10_SoundSet";
					id = 624;
				};
				class FNFAL_jamming11
				{
					soundSet = "FNFAL_jamming11_SoundSet";
					id = 625;
				};
				class FNFAL_jamming12
				{
					soundSet = "FNFAL_jamming12_SoundSet";
					id = 626;
				};
				class FNFAL_jamming13
				{
					soundSet = "FNFAL_jamming13_SoundSet";
					id = 627;
				};
				class VSS_charge_open
				{
					soundSet = "VSS_charge_open_SoundSet";
					id = 630;
				};
				class VSS_charge_open_release
				{
					soundSet = "VSS_charge_open_release_SoundSet";
					id = 631;
				};
				class VSS_charge_close
				{
					soundSet = "VSS_charge_close_SoundSet";
					id = 632;
				};
				class VSS_charge_close_release
				{
					soundSet = "VSS_charge_close_release_SoundSet";
					id = 633;
				};
				class VSS_chamber_load2
				{
					soundSet = "VSS_chamber_load2_SoundSet";
					id = 634;
				};
				class VSS_mag_in
				{
					soundSet = "VSS_mag_in_SoundSet";
					id = 635;
				};
				class VSS_mag_load
				{
					soundSet = "VSS_mag_load_SoundSet";
					id = 636;
				};
				class VSS_mag_remove
				{
					soundSet = "VSS_mag_remove_SoundSet";
					id = 637;
				};
				class VSS_jamming
				{
					soundSet = "VSS_jamming_SoundSet";
					id = 638;
				};
				class VSS_dry
				{
					soundSet = "VSS_dry_SoundSet";
					id = 639;
				};
				class VSS_pullout
				{
					soundSet = "VSS_pullout_SoundSet";
					id = 640;
				};
				class VSS_dry_uncock
				{
					soundSet = "VSS_dry_uncock_SoundSet";
					id = 641;
				};
				class VSS_hand
				{
					soundSet = "VSS_hand_SoundSet";
					id = 642;
				};
				class VSS_hand2
				{
					soundSet = "VSS_hand2_SoundSet";
					id = 643;
				};
				class VSS_hand3
				{
					soundSet = "VSS_hand3_SoundSet";
					id = 644;
				};
				class VSS_hand4
				{
					soundSet = "VSS_hand4_SoundSet";
					id = 655;
				};
				class VSS_hand5
				{
					soundSet = "VSS_hand5_SoundSet";
					id = 656;
				};
				class VSS_hand6
				{
					soundSet = "VSS_hand6_SoundSet";
					id = 657;
				};
				class VSS_hand7
				{
					soundSet = "VSS_hand7_SoundSet";
					id = 658;
				};
				class VSS_hand8
				{
					soundSet = "VSS_hand8_SoundSet";
					id = 659;
				};
				class VSS_jamming1
				{
					soundSet = "VSS_jamming1_SoundSet";
					id = 645;
				};
				class VSS_jamming2
				{
					soundSet = "VSS_jamming2_SoundSet";
					id = 646;
				};
				class VSS_jamming3
				{
					soundSet = "VSS_jamming3_SoundSet";
					id = 647;
				};
				class VSS_jamming4
				{
					soundSet = "VSS_jamming4_SoundSet";
					id = 648;
				};
				class VSS_jamming5
				{
					soundSet = "VSS_jamming5_SoundSet";
					id = 649;
				};
				class VSS_jamming6
				{
					soundSet = "VSS_jamming6_SoundSet";
					id = 650;
				};
				class VSS_jamming7
				{
					soundSet = "VSS_jamming7_SoundSet";
					id = 651;
				};
				class VSS_jamming8
				{
					soundSet = "VSS_jamming8_SoundSet";
					id = 652;
				};
				class VSS_jamming9
				{
					soundSet = "VSS_jamming9_SoundSet";
					id = 653;
				};
				class VSS_jam
				{
					soundSet = "VSS_jam_SoundSet";
					id = 654;
				};
				class MagRifle_fill_loop
				{
					soundSet = "MagRifle_fill_loop_SoundSet";
					id = 402;
				};
				class MagRifle_fill_out
				{
					soundSet = "MagRifle_fill_out_SoundSet";
					id = 403;
				};
				class MagRifle_empty_loop
				{
					soundSet = "MagRifle_empty_loop_SoundSet";
					id = 405;
				};
				class MagPistol_fill_loop
				{
					soundSet = "MagPistol_fill_loop_SoundSet";
					id = 408;
				};
				class MagPistol_fill_out
				{
					soundSet = "MagPistol_fill_out_SoundSet";
					id = 409;
				};
				class MagPistol_empty_loop
				{
					soundSet = "MagPistol_empty_loop_SoundSet";
					id = 411;
				};
				class ChoppingTree
				{
					soundSet = "ChoppingTree_SoundSet";
					id = 415;
				};
				class pickUpRifleLight
				{
					soundSet = "pickUpRifleLight_SoundSet";
					id = 798;
				};
				class Char_HiddenStash_Dig_Shovel_Shot
				{
					soundset = "Char_HiddenStash_Dig_Shovel_Shot_SoundSet";
					id = 886;
				};
				class Char_HiddenStash_Dig_Dirt
				{
					soundset = "Char_HiddenStash_Dig_Dirt_SoundSet";
					id = 887;
				};
				class Char_HiddenStash_Dig_Shovel_In
				{
					soundset = "Char_HiddenStash_Dig_Shovel_In_SoundSet";
					id = 888;
				};
				class Char_HiddenStash_Dig_Find
				{
					soundset = "Char_HiddenStash_Dig_Find_SoundSet";
					id = 889;
				};
				class Char_Unconscious_Hand_Move_Water
				{
					soundset = "Char_Unconscious_Hand_Move_Water_SoundSet";
					id = 890;
				};
				class Char_Gestures_Hand_Clap_Head
				{
					soundset = "Char_Gestures_Hand_Clap_Head_SoundSet";
					id = 891;
				};
				class Char_Gestures_Hand_Grab_Fabric
				{
					soundset = "Char_Gestures_Hand_Grab_Fabric_SoundSet";
					id = 892;
				};
				class pickUpRifle
				{
					soundset = "pickUpRifle_SoundSet";
					id = 893;
				};
				class hand_ladder
				{
					soundset = "hand_ladder_Char_Soundset";
					id = 898;
				};
				class slide_ladder
				{
					soundset = "slide_ladder_Char_Soundset";
					id = 899;
				};
				class ShoulderL_Hide_Rifle
				{
					soundset = "ShoulderL_Hide_Rifle_SoundSet";
					id = 1200;
				};
				class ShoulderL_Show_Rifle
				{
					soundset = "ShoulderL_Show_Rifle_SoundSet";
					id = 1201;
				};
				class ShoulderR_Hide
				{
					soundset = "ShoulderR_Hide_SoundSet";
					id = 1210;
				};
				class ShoulderR_Show
				{
					soundset = "ShoulderR_Show_SoundSet";
					id = 1211;
				};
				class Inventory_Hide
				{
					soundset = "Inventory_Hide_SoundSet";
					id = 1220;
				};
				class Inventory_Show
				{
					soundset = "Inventory_Show_SoundSet";
					id = 1221;
				};
				class Chest_Pistol_Hide
				{
					soundset = "Chest_Pistol_Hide_SoundSet";
					id = 1222;
				};
				class Chest_Pistol_Show
				{
					soundset = "Chest_Pistol_Show_SoundSet";
					id = 1223;
				};
				class Back_Knife_Hide
				{
					soundset = "Back_Knife_Hide_SoundSet";
					id = 1224;
				};
				class Back_Knife_Show
				{
					soundset = "Back_Knife_Show_SoundSet";
					id = 1225;
				};
				class offroad_Gear
				{
					soundset = "offroad_Gear_SoundSet";
					id = 2000;
				};
				class Offroad_Key_On
				{
					soundset = "Offroad_Key_On_SoundSet";
					id = 2001;
				};
				class Offroad_Key_Off
				{
					soundset = "Offroad_Key_Off_SoundSet";
					id = 2002;
				};
				class Offroad_lights
				{
					soundset = "Offroad_lights_SoundSet";
					id = 2003;
				};
				class Offroad_DriverGetIn
				{
					soundset = "Offroad_DriverGetIn_SoundSet";
					id = 2004;
				};
				class Offroad_DriverGetOut
				{
					soundset = "Offroad_DriverGetOut_SoundSet";
					id = 2005;
				};
				class Offroad_DriverJumpOut
				{
					soundset = "Offroad_DriverJumpOut_SoundSet";
					id = 2006;
				};
				class Offroad_CoDriverGetIn
				{
					soundset = "Offroad_CoDriverGetIn_SoundSet";
					id = 2007;
				};
				class Offroad_CoDriverGetOut
				{
					soundset = "Offroad_CoDriverGetOut_SoundSet";
					id = 2008;
				};
				class Offroad_CoDriverJumpOut
				{
					soundset = "Offroad_CoDriverJumpOut_SoundSet";
					id = 2009;
				};
				class Offroad_PassengerGetIn
				{
					soundset = "Offroad_PassengerGetIn_SoundSet";
					id = 2010;
				};
				class Offroad_PassengerGetOut
				{
					soundset = "Offroad_PassengerGetOut_SoundSet";
					id = 2011;
				};
				class Offroad_driver_switchSeat
				{
					soundset = "Offroad_driver_switchSeat_SoundSet";
					id = 2020;
				};
				class Offroad_passanger_switchSeat
				{
					soundset = "Offroad_passanger_switchSeat_SoundSet";
					id = 2021;
				};
				class Offroad_switchSeat_hand
				{
					soundset = "Offroad_switchSeat_hand_SoundSet";
					id = 2022;
				};
				class Offroad_hit_character
				{
					soundset = "offroad_hit_character_SoundSet";
					id = 2040;
				};
				class V3S_Gear
				{
					soundset = "V3S_Gear_SoundSet";
					id = 2100;
				};
				class V3S_Key_On
				{
					soundset = "V3S_Key_On_SoundSet";
					id = 2101;
				};
				class V3S_Key_Off
				{
					soundset = "V3S_Key_Off_SoundSet";
					id = 2102;
				};
				class V3S_lights
				{
					soundset = "V3S_lights_SoundSet";
					id = 2103;
				};
				class V3S_DriverGetIn
				{
					soundset = "V3S_DriverGetIn_SoundSet";
					id = 2104;
				};
				class V3S_DriverGetOut
				{
					soundset = "V3S_DriverGetOut_SoundSet";
					id = 2105;
				};
				class V3S_CoDriverGetIn
				{
					soundset = "V3S_CoDriverGetIn_SoundSet";
					id = 2106;
				};
				class V3S_CoDriverGetOut
				{
					soundset = "V3S_CoDriverGetOut_SoundSet";
					id = 2107;
				};
				class V3S_PassengerGetIn
				{
					soundset = "V3S_PassengerGetIn_SoundSet";
					id = 2108;
				};
				class V3S_PassengerGetOut
				{
					soundset = "V3S_PassengerGetOut_SoundSet";
					id = 2109;
				};
				class V3S_PassengerJumpOut
				{
					soundset = "V3S_PassengerJumpOut_SoundSet";
					id = 2110;
				};
				class CivilianSedan_Gear
				{
					soundset = "CivilianSedan_Gear_SoundSet";
					id = 2200;
				};
				class CivilianSedan_Key_On
				{
					soundset = "CivilianSedan_Key_On_SoundSet";
					id = 2201;
				};
				class CivilianSedan_Key_Off
				{
					soundset = "CivilianSedan_Key_Off_SoundSet";
					id = 2202;
				};
				class CivilianSedan_lights
				{
					soundset = "CivilianSedan_lights_SoundSet";
					id = 2203;
				};
				class CivilianSedan_DriverGetIn
				{
					soundset = "CivilianSedan_DriverGetIn_SoundSet";
					id = 2204;
				};
				class CivilianSedan_DriverGetOut
				{
					soundset = "CivilianSedan_DriverGetOut_SoundSet";
					id = 2205;
				};
				class CivilianSedan_DriverJumpOut
				{
					soundset = "CivilianSedan_DriverJumpOut_SoundSet";
					id = 2206;
				};
				class CivilianSedan_CoDriverGetIn
				{
					soundset = "CivilianSedan_CoDriverGetIn_SoundSet";
					id = 2207;
				};
				class CivilianSedan_CoDriverGetOut
				{
					soundset = "CivilianSedan_CoDriverGetOut_SoundSet";
					id = 2208;
				};
				class CivilianSedan_CoDriverJumpOut
				{
					soundset = "CivilianSedan_CoDriverJumpOut_SoundSet";
					id = 2209;
				};
				class CivilianSedan_PassengerGetIn
				{
					soundset = "CivilianSedan_PassengerGetIn_SoundSet";
					id = 2210;
				};
				class CivilianSedan_PassengerGetOut
				{
					soundset = "CivilianSedan_PassengerGetOut_SoundSet";
					id = 2211;
				};
				class CivilianSedan_driver_switchSeat
				{
					soundset = "CivilianSedan_driver_switchSeat_SoundSet";
					id = 2220;
				};
				class CivilianSedan_passanger_switchSeat
				{
					soundset = "CivilianSedan_passanger_switchSeat_SoundSet";
					id = 2221;
				};
				class CivilianSedan_switchSeat_hand
				{
					soundset = "CivilianSedan_switchSeat_hand_SoundSet";
					id = 2222;
				};
				class Hatchback_02_Gear
				{
					soundset = "Hatchback_02_Gear_SoundSet";
					id = 2300;
				};
				class Hatchback_02_Key_On
				{
					soundset = "Hatchback_02_Key_On_SoundSet";
					id = 2301;
				};
				class Hatchback_02_Key_Off
				{
					soundset = "Hatchback_02_Key_Off_SoundSet";
					id = 2302;
				};
				class Hatchback_02_lights
				{
					soundset = "Hatchback_02_lights_SoundSet";
					id = 2303;
				};
				class Hatchback_02_DriverGetIn
				{
					soundset = "Hatchback_02_DriverGetIn_SoundSet";
					id = 2304;
				};
				class Hatchback_02_DriverGetOut
				{
					soundset = "Hatchback_02_DriverGetOut_SoundSet";
					id = 2305;
				};
				class Hatchback_02_DriverJumpOut
				{
					soundset = "Hatchback_02_DriverJumpOut_SoundSet";
					id = 2306;
				};
				class Hatchback_02_CoDriverGetIn
				{
					soundset = "Hatchback_02_CoDriverGetIn_SoundSet";
					id = 2307;
				};
				class Hatchback_02_CoDriverGetOut
				{
					soundset = "Hatchback_02_CoDriverGetOut_SoundSet";
					id = 2308;
				};
				class Hatchback_02_CoDriverJumpOut
				{
					soundset = "Hatchback_02_CoDriverJumpOut_SoundSet";
					id = 2309;
				};
				class Hatchback_02_PassengerGetIn
				{
					soundset = "Hatchback_02_PassengerGetIn_SoundSet";
					id = 2310;
				};
				class Hatchback_02_PassengerGetOut
				{
					soundset = "Hatchback_02_PassengerGetOut_SoundSet";
					id = 2311;
				};
				class Hatchback_02_driver_switchSeat
				{
					soundset = "Hatchback_02_driver_switchSeat_SoundSet";
					id = 2320;
				};
				class Hatchback_02_passanger_switchSeat
				{
					soundset = "Hatchback_02_passanger_switchSeat_SoundSet";
					id = 2321;
				};
				class Hatchback_02_switchSeat_hand
				{
					soundset = "Hatchback_02_switchSeat_hand_SoundSet";
					id = 2322;
				};
				class p_1hd_cro_suicide_out
				{
					soundset = "p_1hd_cro_suicide_out_SoundSet";
					id = 3001;
				};
				class p_2hd_erc_fireaxe_suicide_in
				{
					soundset = "p_2hd_erc_fireaxe_suicide_in_SoundSet";
					id = 3003;
				};
				class p_2hd_erc_fireaxe_suicide_out_A
				{
					soundset = "p_2hd_erc_fireaxe_suicide_out_A_SoundSet";
					id = 3002;
				};
				class p_2hd_erc_fireaxe_suicide_out_B
				{
					soundset = "p_2hd_erc_fireaxe_suicide_out_B_SoundSet";
					id = 3004;
				};
				class p_2hd_erc_fireaxe_suicide_out_C
				{
					soundset = "p_2hd_erc_fireaxe_suicide_out_C_SoundSet";
					id = 3008;
				};
				class p_2hd_erc_fireaxe_suicide_out_D
				{
					soundset = "p_2hd_erc_fireaxe_suicide_out_D_SoundSet";
					id = 3009;
				};
				class p_2hd_erc_medievalsword_suicide_cancelled_A
				{
					soundset = "p_2hd_erc_medievalsword_suicide_cancelled_A_SoundSet";
					id = 3005;
				};
				class p_2hd_erc_medievalsword_suicide_cancelled_B
				{
					soundset = "p_2hd_erc_medievalsword_suicide_cancelled_B_SoundSet";
					id = 3011;
				};
				class p_2hd_erc_medievalsword_suicide_cancelled_C
				{
					soundset = "p_2hd_erc_medievalsword_suicide_cancelled_C_SoundSet";
					id = 3014;
				};
				class p_2hd_erc_medievalsword_suicide_in_A
				{
					soundset = "p_2hd_erc_medievalsword_suicide_in_A_SoundSet";
					id = 3006;
				};
				class p_2hd_erc_medievalsword_suicide_in_B
				{
					soundset = "p_2hd_erc_medievalsword_suicide_in_B_SoundSet";
					id = 3021;
				};
				class p_2hd_erc_medievalsword_suicide_in_C
				{
					soundset = "p_2hd_erc_medievalsword_suicide_in_C_SoundSet";
					id = 3022;
				};
				class p_2hd_erc_medievalsword_suicide_out
				{
					soundset = "p_2hd_erc_medievalsword_suicide_out_SoundSet";
					id = 3007;
				};
				class p_2hd_erc_pitchfork_suicide_out
				{
					soundset = "p_2hd_erc_pitchfork_suicide_out_SoundSet";
					id = 3010;
				};
				class p_2hd_erc_spear_suicide_in
				{
					soundset = "p_2hd_erc_spear_suicide_in_SoundSet";
					id = 3012;
				};
				class p_2hd_erc_spear_suicide_out
				{
					soundset = "p_2hd_erc_spear_suicide_out_SoundSet";
					id = 3013;
				};
				class p_2hd_erc_woodaxe_suicide_in
				{
					soundset = "p_2hd_erc_woodaxe_suicide_in_SoundSet";
					id = 3015;
				};
				class p_2hd_erc_woodaxe_suicide_out_A
				{
					soundset = "p_2hd_erc_woodaxe_suicide_out_A_SoundSet";
					id = 3016;
				};
				class p_2hd_erc_woodaxe_suicide_out_B
				{
					soundset = "p_2hd_erc_woodaxe_suicide_out_B_SoundSet";
					id = 3023;
				};
				class p_2hd_erc_woodaxe_suicide_out_C
				{
					soundset = "p_2hd_erc_woodaxe_suicide_out_C_SoundSet";
					id = 3024;
				};
				class p_2hd_erc_woodaxe_suicide_out_D
				{
					soundset = "p_2hd_erc_woodaxe_suicide_out_D_SoundSet";
					id = 3025;
				};
				class p_pst_cro_suicide_out
				{
					soundset = "p_pst_cro_suicide_out_SoundSet";
					id = 3017;
				};
				class p_rfl_cro_suicide_cancelled_A
				{
					soundset = "p_rfl_cro_suicide_cancelled_A_SoundSet";
					id = 3018;
				};
				class p_rfl_cro_suicide_cancelled_B
				{
					soundset = "p_rfl_cro_suicide_cancelled_B_SoundSet";
					id = 3026;
				};
				class p_rfl_cro_suicide_cancelled_C
				{
					soundset = "p_rfl_cro_suicide_cancelled_C_SoundSet";
					id = 3027;
				};
				class p_rfl_cro_suicide_in_A
				{
					soundset = "p_rfl_cro_suicide_in_A_SoundSet";
					id = 3019;
				};
				class p_rfl_cro_suicide_in_B
				{
					soundset = "p_rfl_cro_suicide_in_B_SoundSet";
					id = 3028;
				};
				class p_rfl_cro_suicide_in_C
				{
					soundset = "p_rfl_cro_suicide_in_C_SoundSet";
					id = 3029;
				};
				class p_rfl_cro_suicide_in_D
				{
					soundset = "p_rfl_cro_suicide_in_D_SoundSet";
					id = 3030;
				};
				class p_rfl_cro_suicide_out
				{
					soundset = "p_rfl_cro_suicide_out_SoundSet";
					id = 3020;
				};
			};
			class Attachments
			{
				class SoundShoulderWalk_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_walkErc_L_LookupTable";
					id = 1;
				};
				class SoundShoulderWalk_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_walkErc_R_LookupTable";
					id = 2;
				};
				class SoundShoulderRun_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_runErc_L_LookupTable";
					id = 3;
				};
				class SoundShoulderRun_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_runErc_R_LookupTable";
					id = 4;
				};
				class SoundShoulderSprint_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_sprintErc_L_LookupTable";
					id = 5;
				};
				class SoundShoulderSprint_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_sprintErc_R_LookupTable";
					id = 6;
				};
				class SoundShoulderWalk_Cro_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_walkCro_L_LookupTable";
					id = 21;
				};
				class SoundShoulderWalk_Cro_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_walkCro_R_LookupTable";
					id = 22;
				};
				class SoundShoulderRun_Cro_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_runCro_L_LookupTable";
					id = 23;
				};
				class SoundShoulderRun_Cro_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_runCro_R_LookupTable";
					id = 24;
				};
				class SoundShoulderProne_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_walkProne_L_LookupTable";
					id = 31;
				};
				class SoundShoulderProne_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_walkProne_R_LookupTable";
					id = 32;
				};
				class SoundShoulderProne_Run_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_walkProne_L_LookupTable";
					id = 33;
				};
				class SoundShoulderProne_Run_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_walkProne_R_LookupTable";
					id = 34;
				};
				class SoundShoulderRunJump_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_runErc_L_LookupTable";
					id = 35;
				};
				class SoundShoulderRunJump_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_runErc_R_LookupTable";
					id = 36;
				};
				class shoulder_landFootErc_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_sprintErc_R_LookupTable";
					id = 37;
				};
				class shoulder_landFootErc_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_sprintErc_R_LookupTable";
					id = 38;
				};
				class SoundShoulderWalkErcRas_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_walkErc_L_LookupTable";
					id = 51;
				};
				class SoundShoulderWalkErcRas_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_walkErc_R_LookupTable";
					id = 52;
				};
				class SoundShoulderRunErcRas_L
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_runErc_L_LookupTable";
					id = 53;
				};
				class SoundShoulderRunErcRas_R
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_runErc_R_LookupTable";
					id = 54;
				};
				class shoulder_landFeetErc
				{
					slot = "shoulder";
					soundLookupTable = "shoulder_sprintErc_R_LookupTable";
					id = 100;
				};
				class SoundBodyWalk_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_walkErc_LookupTable";
					id = 1;
				};
				class SoundBodyWalk_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_walkErc_LookupTable";
					id = 2;
				};
				class SoundBodyRun_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_runErc_LookupTable";
					id = 3;
				};
				class SoundBodyRun_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_runErc_LookupTable";
					id = 4;
				};
				class SoundBodySprint_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_sprintErc_LookupTable";
					id = 5;
				};
				class SoundBodySprint_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_sprintErc_LookupTable";
					id = 6;
				};
				class SoundBodyShortmove_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_Shortmove_LookupTable";
					id = 7;
				};
				class SoundBodyShortmove_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_Shortmove_LookupTable";
					id = 8;
				};
				class SoundBodyLongmove_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_Longmove_LookupTable";
					id = 9;
				};
				class SoundBodyLongmove_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_Longmove_LookupTable";
					id = 10;
				};
				class SoundBodyWalk_Cro_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_walkCro_LookupTable";
					id = 21;
				};
				class SoundBodyWalk_Cro_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_walkCro_LookupTable";
					id = 22;
				};
				class SoundBodyRun_Cro_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_runCro_LookupTable";
					id = 23;
				};
				class SoundBodyRun_Cro_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_runCro_LookupTable";
					id = 24;
				};
				class SoundBodyProne_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_walkProne_LookupTable";
					id = 31;
				};
				class SoundBodyProne_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_walkProne_LookupTable";
					id = 32;
				};
				class SoundBodyProne_Run_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_runProne_LookupTable";
					id = 33;
				};
				class SoundBodyProne_Run_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_runProne_LookupTable";
					id = 34;
				};
				class SoundBodyRunJump_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_jumpErc_LookupTable";
					id = 35;
				};
				class SoundBodyRunJump_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_jumpErc_LookupTable";
					id = 36;
				};
				class body_landFootErc_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_landFootErc_LookupTable";
					id = 37;
				};
				class body_landFootErc_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_landFootErc_LookupTable";
					id = 38;
				};
				class SoundBodyAttackLight
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_attack_light_LookupTable";
					id = 41;
				};
				class SoundBodyAttackHeavy
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_attack_heavy_LookupTable";
					id = 42;
				};
				class SoundBodyWalkErcWalk_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_walkRasErc_LookupTable";
					id = 51;
				};
				class SoundBodyWalkErcWalk_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_walkRasErc_LookupTable";
					id = 52;
				};
				class SoundBodyRunErcWalk_L
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_runRasErc_LookupTable";
					id = 53;
				};
				class SoundBodyRunErcWalk_R
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_runRasErc_LookupTable";
					id = 54;
				};
				class body_landFeetErc
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_landFeetErc_LookupTable";
					id = 100;
				};
				class SoundBodyShortmove_L_NoFilter
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_Shortmove_LookupTable";
					id = 10007;
				};
				class SoundBodyShortmove_R_NoFilter
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_Shortmove_LookupTable";
					id = 10008;
				};
				class SoundBodyLongmove_L_NoFilter
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_Longmove_LookupTable";
					id = 10009;
				};
				class SoundBodyLongmove_R_NoFilter
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_Longmove_LookupTable";
					id = 10010;
				};
				class Cloth_Body_Freezing
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_Freezing_LookupTable";
					id = 10200;
				};
				class Cloth_Body_Freezing_2hd_Erc
				{
					slot = "body";
					soundLookupTable = "Cloth_Body_Freezing_2hd_Erc_LookupTable";
					id = 10201;
				};
				class SoundbackWalk_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_walkErc_LookupTable";
					id = 1;
				};
				class SoundbackWalk_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_walkErc_LookupTable";
					id = 2;
				};
				class SoundbackRun_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_runErc_LookupTable";
					id = 3;
				};
				class SoundbackRun_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_runErc_LookupTable";
					id = 4;
				};
				class SoundbackSprint_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_sprintErc_LookupTable";
					id = 5;
				};
				class SoundbackSprint_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_sprintErc_LookupTable";
					id = 6;
				};
				class SoundbackShorrtmove_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_Shortmove_LookupTable";
					id = 7;
				};
				class SoundbackShortmove_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_Shortmove_LookupTable";
					id = 8;
				};
				class SoundbackLongmove_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_Longmove_LookupTable";
					id = 9;
				};
				class SoundbackLongmove_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_Longmove_LookupTable";
					id = 10;
				};
				class SoundbackWalk_Cro_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_walkCro_LookupTable";
					id = 21;
				};
				class SoundbackWalk_Cro_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_walkCro_LookupTable";
					id = 22;
				};
				class SoundbackRun_Cro_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_runCro_LookupTable";
					id = 23;
				};
				class SoundbackRun_Cro_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_runCro_LookupTable";
					id = 24;
				};
				class SoundbackProne_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_walkProne_LookupTable";
					id = 31;
				};
				class SoundbackProne_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_walkProne_LookupTable";
					id = 32;
				};
				class SoundbackProne_Run_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_runProne_LookupTable";
					id = 33;
				};
				class SoundbackProne_Run_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_runProne_LookupTable";
					id = 34;
				};
				class SoundbackRunJump_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_jumpErc_LookupTable";
					id = 35;
				};
				class SoundbackRunJump_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_jumpErc_LookupTable";
					id = 36;
				};
				class back_landFootErc_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_landFootErc_LookupTable";
					id = 37;
				};
				class back_landFootErc_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_landFootErc_LookupTable";
					id = 38;
				};
				class SoundbackAttackLight
				{
					slot = "back";
					soundLookupTable = "Cloth_back_attack_light_LookupTable";
					id = 41;
				};
				class SoundbackAttackHeavy
				{
					slot = "back";
					soundLookupTable = "Cloth_back_attack_heavy_LookupTable";
					id = 42;
				};
				class SoundbackWalkErcWalk_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_walkRasErc_LookupTable";
					id = 51;
				};
				class SoundbackWalkErcWalk_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_walkRasErc_LookupTable";
					id = 52;
				};
				class SoundbackRunErcWalk_L
				{
					slot = "back";
					soundLookupTable = "Cloth_back_runRasErc_LookupTable";
					id = 53;
				};
				class SoundbackRunErcWalk_R
				{
					slot = "back";
					soundLookupTable = "Cloth_back_runRasErc_LookupTable";
					id = 54;
				};
				class back_landFeetErc
				{
					slot = "back";
					soundLookupTable = "Cloth_back_landFeetErc_LookupTable";
					id = 100;
				};
			};
			class SoundVoiceEvent
			{
				noise = "NoiseStepStand";
			};
			class SoundVoice
			{
				class staminaDownLight: SoundVoiceEvent
				{
					soundLookupTable = "staminaDownLight_SoundVoice_Char_LookupTable";
					id = 1;
				};
				class staminaDownHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "staminaDownHeavy_SoundVoice_Char_LookupTable";
					id = 2;
				};
				class staminaUpHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "staminaUpHeavy_SoundVoice_Char_LookupTable";
					id = 3;
				};
				class staminaUpLight_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "staminaUpLight_SoundVoice_Char_LookupTable";
					id = 4;
				};
				class cough_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "cough_SoundVoice_Char_LookupTable";
					id = 8;
				};
				class sneez_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "sneez_SoundVoice_Char_LookupTable";
					id = 9;
				};
				class laugh_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "laugh_SoundVoice_Char_LookupTable";
					id = 10;
				};
				class freezing_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "freezing_SoundVoice_Char_LookupTable";
					id = 11;
				};
				class takingDamageLight_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "takingDamageLight_SoundVoice_Char_LookupTable";
					id = 12;
				};
				class takingDamageHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "takingDamageHeavy_SoundVoice_Char_LookupTable";
					id = 13;
				};
				class meleeAttackLight_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "meleeAttack_SoundVoice_Char_LookupTable";
					id = 16;
				};
				class meleeAttackHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "meleeAttackHeavy_SoundVoice_Char_LookupTable";
					id = 17;
				};
				class jump_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "jump_SoundVoice_Char_LookupTable";
					id = 18;
				};
				class pickUpHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "pickUpHeavy_SoundVoice_Char_LookupTable";
					id = 19;
				};
				class holdBreath_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "holdBreath_SoundVoice_Char_LookupTable";
					id = 20;
				};
				class releaseBreath_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "releaseBreath_SoundVoice_Char_LookupTable";
					id = 21;
				};
				class vomit_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "vomit_SoundVoice_Char_LookupTable";
					id = 23;
				};
				class vomitShort_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "vomitShort_SoundVoice_Char_LookupTable";
					id = 23333;
				};
				class blow_fireplace_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "blow_fireplace_SoundVoice_Char_LookupTable";
					id = 24;
				};
				class inhale_fireplace_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "inhale_fireplace_SoundVoice_Char_LookupTable";
					id = 25;
				};
				class staminaUpEnd_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "staminaUpEnd_SoundVoice_Char_LookupTable";
					id = 26;
				};
				class generalgrunt_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "generalgrunt_SoundVoice_Char_LookupTable";
					id = 27;
				};
				class pain_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "pain_SoundVoice_Char_LookupTable";
					id = 28;
				};
				class hot_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable = "hot_SoundVoice_Char_LookupTable";
					id = 30;
				};
				class drinking: SoundVoiceEvent
				{
					soundLookupTable = "drinking_SoundVoice_Char_LookupTable";
					id = 200;
				};
				class takeASip_sip: SoundVoiceEvent
				{
					soundLookupTable = "takeASip_sip_SoundVoice_Char_LookupTable";
					id = 201;
				};
				class takeASip_swallow: SoundVoiceEvent
				{
					soundLookupTable = "takeASip_swallow_SoundVoice_Char_LookupTable";
					id = 202;
				};
				class welldrinking: SoundVoiceEvent
				{
					soundLookupTable = "welldrinking_SoundVoice_Char_LookupTable";
					id = 203;
				};
				class riverdrinking: SoundVoiceEvent
				{
					soundLookupTable = "riverdrinking_SoundVoice_Char_LookupTable";
					id = 204;
				};
				class eating: SoundVoiceEvent
				{
					soundLookupTable = "eating_SoundVoice_Char_LookupTable";
					id = 888;
				};
				class eating_fruit: SoundVoiceEvent
				{
					soundLookupTable = "eating_fruit_SoundVoice_Char_LookupTable";
					id = 889;
				};
				class eating_boxfood: SoundVoiceEvent
				{
					soundLookupTable = "eating_boxfood_SoundVoice_Char_LookupTable";
					id = 890;
				};
				class eating_tablets: SoundVoiceEvent
				{
					soundLookupTable = "eating_tablets_SoundVoice_Char_LookupTable";
					id = 891;
				};
			};
			class SoundWeapon
			{
				class swim_run
				{
					soundset = "swim_run_Char_Soundset";
					id = 71;
				};
				class swim_sprint
				{
					soundset = "swim_sprint_Char_Soundset";
					id = 72;
				};
				class CPR
				{
					soundset = "CPR_Soundset";
					id = 73;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpItem_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpItem_SoundSet";
					id = 797;
				};
				class pickUpRifleLight
				{
					soundSet = "pickUpRifleLight_SoundSet";
					id = 798;
				};
				class Attack_1hdDefault_Light1
				{
					soundSet = "Char_Attack_unarmed_light1_SoundSet";
					id = 801;
				};
				class Attack_1hdDefault_Light2
				{
					soundSet = "Char_Attack_unarmed_light2_SoundSet";
					id = 802;
				};
				class Attack_1hdDefault_Heavy1
				{
					soundSet = "Char_Attack_unarmed_heavy1_SoundSet";
					id = 803;
				};
				class Attack_1hdDefault_Heavy2
				{
					soundSet = "Char_Attack_unarmed_heavy2_SoundSet";
					id = 804;
				};
				class Attack_knife_Light1
				{
					soundSet = "Char_Attack_knife_light1_SoundSet";
					id = 806;
				};
				class Attack_knife_Light2
				{
					soundSet = "Char_Attack_knife_light2_SoundSet";
					id = 807;
				};
				class Attack_knife_Heavy1
				{
					soundSet = "Char_Attack_knife_heavy1_SoundSet";
					id = 808;
				};
				class Attack_knife_Heavy2
				{
					soundSet = "Char_Attack_knife_heavy2_SoundSet";
					id = 809;
				};
				class Attack_pipemetal_Light1
				{
					soundSet = "Char_Attack_pipemetal_light1_SoundSet";
					id = 811;
				};
				class Attack_pipemetal_Light2
				{
					soundSet = "Char_Attack_pipemetal_light2_SoundSet";
					id = 812;
				};
				class Attack_pipemetal_Heavy1
				{
					soundSet = "Char_Attack_pipemetal_heavy1_SoundSet";
					id = 813;
				};
				class Attack_pipemetal_Heavy2
				{
					soundSet = "Char_Attack_pipemetal_heavy2_SoundSet";
					id = 814;
				};
				class Attack_2hddefault_Light1
				{
					soundSet = "Char_Attack_pipemetal_light1_SoundSet";
					id = 16;
				};
				class Attack_2hddefault_Light2
				{
					soundSet = "Char_Attack_pipemetal_light2_SoundSet";
					id = 17;
				};
				class Attack_2hddefault_Heavy1
				{
					soundSet = "Char_Attack_pipemetal_heavy1_SoundSet";
					id = 18;
				};
				class Attack_2hddefault_Heavy2
				{
					soundSet = "Char_Attack_pipemetal_heavy2_SoundSet";
					id = 19;
				};
				class Attack_2hdlight_Light1
				{
					soundSet = "Char_Attack_pipemetal_light1_SoundSet";
					id = 21;
				};
				class Attack_2hdlight_Light2
				{
					soundSet = "Char_Attack_pipemetal_light2_SoundSet";
					id = 22;
				};
				class Attack_2hdlight_Heavy1
				{
					soundSet = "Char_Attack_pipemetal_heavy1_SoundSet";
					id = 23;
				};
				class Attack_2hdlight_Heavy2
				{
					soundSet = "Char_Attack_pipemetal_heavy2_SoundSet";
					id = 24;
				};
				class Attack_bat_Light1
				{
					soundSet = "Char_Attack_fireaxe_light1_SoundSet";
					id = 826;
				};
				class Attack_bat_Light2
				{
					soundSet = "Char_Attack_fireaxe_light2_SoundSet";
					id = 827;
				};
				class Attack_bat_Heavy1
				{
					soundSet = "Char_Attack_fireaxe_heavy1_SoundSet";
					id = 828;
				};
				class Attack_bat_Heavy2
				{
					soundSet = "Char_Attack_fireaxe_heavy2_SoundSet";
					id = 829;
				};
				class Attack_fireaxe_Light1
				{
					soundSet = "Char_Attack_fireaxe_light1_SoundSet";
					id = 831;
				};
				class Attack_fireaxe_Light2
				{
					soundSet = "Char_Attack_fireaxe_light2_SoundSet";
					id = 832;
				};
				class Attack_fireaxe_Heavy1
				{
					soundSet = "Char_Attack_fireaxe_heavy1_SoundSet";
					id = 833;
				};
				class Attack_fireaxe_Heavy2
				{
					soundSet = "Char_Attack_fireaxe_heavy2_SoundSet";
					id = 834;
				};
				class Attack_extinguisher_Light1
				{
					soundSet = "Char_Attack_pipemetal_light1_SoundSet";
					id = 836;
				};
				class Attack_extinguisher_Light2
				{
					soundSet = "Char_Attack_pipemetal_light2_SoundSet";
					id = 837;
				};
				class Attack_extinguisher_Heavy1
				{
					soundSet = "Char_Attack_pipemetal_heavy1_SoundSet";
					id = 838;
				};
				class Attack_extinguisher_Heavy2
				{
					soundSet = "Char_Attack_pipemetal_heavy2_SoundSet";
					id = 839;
				};
				class Attack_pistol_Light1
				{
					soundSet = "Char_Attack_pipemetal_light1_SoundSet";
					id = 841;
				};
				class Attack_pistol_Light2
				{
					soundSet = "Char_Attack_pipemetal_light2_SoundSet";
					id = 842;
				};
				class Attack_pistol_Heavy1
				{
					soundSet = "Char_Attack_pipemetal_heavy1_SoundSet";
					id = 843;
				};
				class Attack_pistol_Heavy2
				{
					soundSet = "Char_Attack_pipemetal_heavy2_SoundSet";
					id = 844;
				};
				class Attack_rifle_Light1
				{
					soundSet = "Char_Attack_pipemetal_light1_SoundSet";
					id = 846;
				};
				class Attack_rifle_Light2
				{
					soundSet = "Char_Attack_pipemetal_light2_SoundSet";
					id = 847;
				};
				class Attack_rifle_Heavy1
				{
					soundSet = "Char_Attack_pipemetal_heavy1_SoundSet";
					id = 848;
				};
				class Attack_rifle_Heavy2
				{
					soundSet = "Char_Attack_pipemetal_heavy2_SoundSet";
					id = 849;
				};
				class Attack_unarmed_Light1
				{
					soundSet = "Char_Attack_unarmed_light1_SoundSet";
					id = 851;
				};
				class Attack_unarmed_Light2
				{
					soundSet = "Char_Attack_unarmed_light2_SoundSet";
					id = 852;
				};
				class Attack_unarmed_Heavy1
				{
					soundSet = "Char_Attack_unarmed_heavy1_SoundSet";
					id = 853;
				};
				class Attack_unarmed_Heavy2
				{
					soundSet = "Char_Attack_unarmed_heavy2_SoundSet";
					id = 854;
				};
				class Eating_TakeFood
				{
					soundSet = "Eating_TakeFood_Soundset";
					id = 889;
				};
				class Char_Gestures_Hand_Clap_Head
				{
					soundset = "Char_Gestures_Hand_Clap_Head_SoundSet";
					id = 891;
				};
				class Char_Gestures_Hand_Grab_Fabric
				{
					soundset = "Char_Gestures_Hand_Grab_Fabric_SoundSet";
					id = 892;
				};
				class pickUpRifle
				{
					soundset = "pickUpRifle_SoundSet";
					id = 893;
				};
				class HandClap
				{
					soundset = "Char_Gestures_HandClap_SoundSet";
					id = 894;
				};
				class vomit_Char
				{
					soundset = "vomit_Char_SoundSet";
					id = 897;
				};
				class turnOnRadio
				{
					soundSet = "turnOnRadio_SoundSet";
					id = 1006;
				};
				class turnOffRadio
				{
					soundSet = "turnOffRadio_SoundSet";
					id = 1007;
				};
				class ShoulderL_Hide_Rifle
				{
					soundset = "ShoulderL_Hide_Rifle_SoundSet";
					id = 1200;
				};
				class ShoulderL_Show_Rifle
				{
					soundset = "ShoulderL_Show_Rifle_SoundSet";
					id = 1201;
				};
				class ShoulderR_Hide
				{
					soundset = "ShoulderR_Hide_SoundSet";
					id = 1210;
				};
				class ShoulderR_Show
				{
					soundset = "ShoulderR_Show_SoundSet";
					id = 1211;
				};
				class Inventory_Hide
				{
					soundset = "Inventory_Hide_SoundSet";
					id = 1220;
				};
				class Inventory_Show
				{
					soundset = "Inventory_Show_SoundSet";
					id = 1221;
				};
				class Chest_Pistol_Hide
				{
					soundset = "Chest_Pistol_Hide_SoundSet";
					id = 1222;
				};
				class Chest_Pistol_Show
				{
					soundset = "Chest_Pistol_Show_SoundSet";
					id = 1223;
				};
				class Back_Knife_Hide
				{
					soundset = "Back_Knife_Hide_SoundSet";
					id = 1224;
				};
				class Back_Knife_Show
				{
					soundset = "Back_Knife_Show_SoundSet";
					id = 1225;
				};
				class rope_tieup
				{
					soundSet = "rope_tieup_SoundSet";
					id = 13338;
				};
				class rope_tieup_end
				{
					soundSet = "rope_tieup_end_SoundSet";
					id = 13339;
				};
				class rope_tieup_back
				{
					soundSet = "rope_tieup_back_SoundSet";
					id = 13340;
				};
			};
			class Steps
			{
				class walkErc_L
				{
					soundLookupTable = "walkErc_Char_LookupTable";
					id = 1;
				};
				class walkErc_R
				{
					soundLookupTable = "walkErc_Char_LookupTable";
					id = 2;
				};
				class runErc_L
				{
					soundLookupTable = "runErc_Char_LookupTable";
					id = 3;
				};
				class runErc_R
				{
					soundLookupTable = "runErc_Char_LookupTable";
					id = 4;
				};
				class sprintErc_L
				{
					soundLookupTable = "sprintErc_Char_LookupTable";
					id = 5;
				};
				class sprintErc_R
				{
					soundLookupTable = "sprintErc_Char_LookupTable";
					id = 6;
				};
				class scuffErc_L
				{
					soundLookupTable = "scuffErc_Char_LookupTable";
					id = 7;
				};
				class scuffErc_R
				{
					soundLookupTable = "scuffErc_Char_LookupTable";
					id = 8;
				};
				class HandStep
				{
					soundLookupTable = "handstepSound_Char_LookupTable";
					id = 11;
				};
				class stepfall_DeleteLater
				{
					soundLookupTable = "bodyfallSound_Char_LookupTable";
					id = 14;
				};
				class Bodyfall_hand_DeleteLater
				{
					soundLookupTable = "bodyfall_handSound_Char_LookupTable";
					id = 15;
				};
				class Bodyfall_slide_DeleteLater
				{
					soundLookupTable = "bodyfall_slideSound_Char_LookupTable";
					id = 16;
				};
				class Bodyfall_rollHard
				{
					soundLookupTable = "bodyfall_rollHardSound_Char_LookupTable";
					id = 101;
				};
				class Bodyfall_roll
				{
					soundLookupTable = "bodyfall_rollSound_Char_LookupTable";
					id = 17;
				};
				class walkCro_L
				{
					soundLookupTable = "walkCro_Char_LookupTable";
					id = 21;
				};
				class walkCro_R
				{
					soundLookupTable = "walkCro_Char_LookupTable";
					id = 22;
				};
				class runCro_L
				{
					soundLookupTable = "runCro_Char_LookupTable";
					id = 23;
				};
				class runCro_R
				{
					soundLookupTable = "runCro_Char_LookupTable";
					id = 24;
				};
				class walkProne_L
				{
					soundLookupTable = "walkProne_Char_LookupTable";
					id = 31;
				};
				class walkProne_R
				{
					soundLookupTable = "walkProne_Char_LookupTable";
					id = 32;
				};
				class runProne_L
				{
					soundLookupTable = "runProne_Char_LookupTable";
					id = 33;
				};
				class runProne_R
				{
					soundLookupTable = "runProne_Char_LookupTable";
					id = 34;
				};
				class walkProneElbow_L
				{
					soundLookupTable = "walkProneElbow_Char_LookupTable";
					id = 41;
				};
				class walkProneElbow_R
				{
					soundLookupTable = "walkProneElbow_Char_LookupTable";
					id = 42;
				};
				class runProneElbow_L
				{
					soundLookupTable = "runProneElbow_Char_LookupTable";
					id = 43;
				};
				class runProneElbow_R
				{
					soundLookupTable = "runProneElbow_Char_LookupTable";
					id = 44;
				};
				class jumpErc_L
				{
					soundLookupTable = "jumpErc_Char_LookupTable";
					id = 35;
				};
				class jumpErc_R
				{
					soundLookupTable = "jumpErc_Char_LookupTable";
					id = 36;
				};
				class landFootErc_L
				{
					soundLookupTable = "landFootErc_Char_LookupTable";
					id = 37;
				};
				class landFootErc_R
				{
					soundLookupTable = "landFootErc_Char_LookupTable";
					id = 38;
				};
				class walkRasErc_L
				{
					soundLookupTable = "walkRasErc_Char_LookupTable";
					id = 51;
				};
				class walkRasErc_R
				{
					soundLookupTable = "walkRasErc_Char_LookupTable";
					id = 52;
				};
				class runRasErc_L
				{
					soundLookupTable = "runRasErc_Char_LookupTable";
					id = 53;
				};
				class runRasErc_R
				{
					soundLookupTable = "runRasErc_Char_LookupTable";
					id = 54;
				};
				class HandStep_L
				{
					soundLookupTable = "handstepSound_Char_LookupTable";
					id = 61;
				};
				class HandStep_R
				{
					soundLookupTable = "handstepSound_Char_LookupTable";
					id = 62;
				};
				class HandStep_Hard_L
				{
					soundLookupTable = "handstepSound_Hard_Char_LookupTable";
					id = 63;
				};
				class HandStep_Hard_R
				{
					soundLookupTable = "handstepSound_Hard_Char_LookupTable";
					id = 64;
				};
				class landFeetErc
				{
					soundLookupTable = "landFeetErc_Char_LookupTable";
					id = 100;
				};
				class Bodyfall
				{
					soundLookupTable = "bodyfallSound_Char_LookupTable";
					id = 110;
				};
				class Bodyfall_hand
				{
					soundLookupTable = "bodyfall_handSound_Char_LookupTable";
					id = 111;
				};
				class Bodyfall_slide
				{
					soundLookupTable = "bodyfall_slideSound_Char_LookupTable";
					id = 112;
				};
				class Bodyfall_slide_light
				{
					soundLookupTable = "bodyfall_slide_lightSound_Char_LookupTable";
					id = 113;
				};
				class Bodyfall_hand_light
				{
					soundLookupTable = "bodyfall_hand_lightSound_Char_LookupTable";
					id = 114;
				};
				class walkProne_noHS
				{
					soundLookupTable = "walkProne_noHS_Char_LookupTable";
					id = 131;
				};
				class walkProneLong_noHS
				{
					soundLookupTable = "walkProneLong_noHS_Char_LookupTable";
					id = 132;
				};
				class HandsStep
				{
					soundLookupTable = "handsstepSound_Char_LookupTable";
					id = 161;
				};
				class Dropitem
				{
					soundLookupTable = "drop_item_LookupTable";
					id = 201;
				};
				class step_ladder
				{
					soundLookupTable = "step_ladder_Char_LookupTable";
					id = 1026;
				};
				class step_ladder_run
				{
					soundLookupTable = "step_ladder_run_Char_LookupTable";
					id = 1027;
				};
			};
		};
		class Melee
		{
			action = "MeleeAttack%d";
			ammo = "MeleeFist";
			useCursor = 1;
			range = 0.85;
			actionSounds = "action_punch";
		};
		class States
		{
			class Energy
			{
				min = -500;
				max = 20000;
				events[] = {"Hunger","HighEnergy"};
				change = "-(DZ_METABOLISM_SEC + (((_person call fnc_speedVector) min 7) * 0.125))";
			};
			class Water
			{
				min = -1000;
				max = 4000;
				events[] = {"Thirst","HighWater"};
				change = "-(DZ_THIRST_SEC + (((_person call fnc_speedVector) min 7) * 0.2))";
			};
			class Bodytemperature
			{
				min = 30;
				max = 43;
				events[] = {"Temperature"};
				change = "0";
			};
			class Heatcomfort
			{
				min = -100;
				max = 100;
				events[] = {"FeelingCold"};
				change = "0";
			};
			class Stomach
			{
				min = 0;
				max = 4000;
				events[] = {"Packed"};
				change = "-DZ_DIGESTION_RATE";
			};
			class Blood
			{
				min = 0;
				max = 5000;
				events[] = {"Bleeding"};
				change = "0";
			};
			class Health
			{
				min = 0;
				max = 5000;
				events[] = {"Healing","FootInjury"};
				change = "0.02 call player_fnc_tickHealth";
			};
			class Exposure
			{
				min = -1;
				max = 1;
				events[] = {};
				change = "call player_fnc_tickExposure";
			};
			class Shock
			{
				min = 0;
				max = 5000;
				events[] = {"Unconscious"};
				change = "-30";
			};
			class Wet
			{
				min = 0;
				max = 1;
				events[] = {};
				change = "";
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\bodies\data\underwear.rvmat","dz\characters\bodies\data\underwear_injury.rvmat","dz\characters\bodies\data\underwear_injury.rvmat","dz\characters\heads\data\hhl_m_white01_medium_002.rvmat","dz\characters\heads\data\hhl_m_white01_medium_002_injury1.rvmat","dz\characters\heads\data\hhl_m_white01_medium_002_injury2.rvmat","dz\characters\heads\data\hhl_m_asian01_001_light.rvmat","dz\characters\heads\data\hhl_m_asian01_001_light_injury1.rvmat","dz\characters\heads\data\hhl_m_asian01_001_light_injury2.rvmat","dz\characters\heads\data\hhl_m_african01_001_light.rvmat","dz\characters\heads\data\hhl_m_african01_001_light_injury1.rvmat","dz\characters\heads\data\hhl_m_african01_001_light_injury2.rvmat","dz\characters\heads\data\hhl_m_latino01_001_medium.rvmat","dz\characters\heads\data\hhl_m_latino01_001_medium_injury1.rvmat","dz\characters\heads\data\hhl_m_latino01_001_medium_injury2.rvmat","DZ\Characters\Heads\Data\hhl_f_white_01.rvmat","DZ\Characters\Heads\Data\hhl_f_white_01_injury1.rvmat","DZ\Characters\Heads\Data\hhl_f_white_01_injury2.rvmat","DZ\Characters\Heads\Data\hhl_f_asian_01.rvmat","DZ\Characters\Heads\Data\hhl_f_asian_01_injury1.rvmat","DZ\Characters\Heads\Data\hhl_f_asian_01_injury2.rvmat","DZ\Characters\Heads\Data\hhl_f_african_01.rvmat","DZ\Characters\Heads\Data\hhl_f_african_01_injury1.rvmat","DZ\Characters\Heads\Data\hhl_f_african_01_injury2.rvmat","DZ\Characters\Heads\Data\hhl_f_latino_01.rvmat","DZ\Characters\Heads\Data\hhl_f_latino_01_injury1.rvmat","DZ\Characters\Heads\Data\hhl_f_latino_01_injury2.rvmat","DZ\characters\heads\data\hhl_m_raghu.rvmat","DZ\characters\heads\data\hhl_m_raghu_injury1.rvmat","DZ\characters\heads\data\hhl_m_raghu_injury2.rvmat","DZ\characters\heads\data\hhl_m_dean.rvmat","DZ\characters\heads\data\hhl_m_dean_injury.rvmat","DZ\characters\heads\data\hhl_m_dean_injury2.rvmat","DZ\characters\heads\data\hhl_m_matt.rvmat","DZ\characters\heads\data\hhl_m_matt_injury.rvmat","DZ\characters\heads\data\hhl_m_matt_injury2.rvmat","DZ\characters\heads\data\hhl_f_kamila.rvmat","DZ\characters\heads\data\hhl_f_kamila_injury.rvmat","DZ\characters\heads\data\hhl_f_kamila_injury2.rvmat","DZ\characters\heads\data\hhl_f_henriet.rvmat","DZ\characters\heads\data\hhl_f_henriet_injury.rvmat","DZ\characters\heads\data\hhl_f_henriet_injury2.rvmat","DZ\characters\heads\data\hhl_f_janaz.rvmat","DZ\characters\heads\data\hhl_f_janaz_injury.rvmat","DZ\characters\heads\data\hhl_f_janaz_injury2.rvmat","dz\characters\heads\data\hhl_f_sita.rvmat","dz\characters\heads\data\hhl_f_sita_injury1.rvmat","dz\characters\heads\data\hhl_f_sita_injury2.rvmat"};
		};
	};
	class SurvivorMale_Base: SurvivorBase
	{
		scope = 0;
		model = "\dz\characters\bodies\bodyparts_above0.p3d";
		simpleHiddenSelections[] = {"slot_melee_rifle","slot_melee_melee","slot_shoulder_rifle","slot_shoulder_melee"};
		woman = 0;
		voiceType = 1;
		clothingType = "male";
		emptyBody = "MaleTorso_Base";
		emptyLegs = "MaleLegs_Base";
		emptyFeet = "MaleFeet_Base";
		emptyGloves = "MaleHands_Base";
		faceType = "MaleWhiteHead";
		customHeads[] = {"Dean","Matt"};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)","dz\characters\heads\data\hhl_dummy_skin_material.rvmat","#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)","dz\characters\heads\data\hhl_dummy_skin_material.rvmat","#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)","dz\characters\heads\data\hhl_dummy_skin_material.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class SurvivorFemale_Base: SurvivorBase
	{
		scope = 0;
		model = "\dz\characters\bodies\bodyparts_above0.p3d";
		simpleHiddenSelections[] = {"slot_melee_rifle","slot_melee_melee","slot_shoulder_rifle","slot_shoulder_melee"};
		woman = 1;
		voiceType = 1;
		clothingType = "female";
		emptyBody = "FemaleTorso_Base";
		emptyLegs = "FemaleLegs_Base";
		emptyFeet = "FemaleFeet_Base";
		emptyGloves = "FemaleHands_Base";
		faceType = "FemaleWhiteHead";
		customHeads[] = {};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class SurvivorM_Mirek: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleAdamHead";
		emptyBody = "MaleAdamTorso";
		emptyLegs = "MaleAdamLegs";
		emptyFeet = "MaleAdamFeet";
		emptyGloves = "MaleAdamHands";
		faceType = "MaleAdamHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_adam\hhl_m_adam_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_adam\hhl_m_adam_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_adam\hhl_m_adam_body_shaved_co.paa","dz\characters\heads\data\m_adam\hhl_m_adam_body_shaved.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_body_unshaved_co.paa","dz\characters\heads\data\m_adam\hhl_m_adam_body_unshaved.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_body_bearded_co.paa","dz\characters\heads\data\m_adam\hhl_m_adam_body_bearded.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_beard_ca.paa","dz\characters\heads\data\m_adam\hhl_m_adam_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_adam\hhl_m_adam_body_shaved.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_body_shaved_injury.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_body_shaved_injury2.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_body_unshaved.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_body_unshaved_injury.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_body_bearded.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_body_bearded_injury.rvmat","dz\characters\heads\data\m_adam\hhl_m_adam_body_bearded_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorM_Boris: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleBorisHead";
		emptyBody = "MaleBorisTorso";
		emptyLegs = "MaleBorisLegs";
		emptyFeet = "MaleBorisFeet";
		emptyGloves = "MaleBorisHands";
		faceType = "MaleBorisHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_boris\hhl_m_boris_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_boris\hhl_m_boris_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_boris\hhl_m_boris_body_shaved_co.paa","dz\characters\heads\data\m_boris\hhl_m_boris_body_shaved.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_body_unshaved_co.paa","dz\characters\heads\data\m_boris\hhl_m_boris_body_unshaved.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_body_bearded_co.paa","dz\characters\heads\data\m_boris\hhl_m_boris_body_bearded.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_beard_ca.paa","dz\characters\heads\data\m_boris\hhl_m_boris_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_boris\hhl_m_boris_body_shaved.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_body_shaved_injury.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_body_shaved_injury2.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_body_unshaved.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_body_unshaved_injury.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_body_bearded.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_body_bearded_injury.rvmat","dz\characters\heads\data\m_boris\hhl_m_boris_body_bearded_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorM_Cyril: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleCyrilHead";
		emptyBody = "MaleCyrilTorso";
		emptyLegs = "MaleCyrilLegs";
		emptyFeet = "MaleCyrilFeet";
		emptyGloves = "MaleCyrilHands";
		faceType = "MaleCyrilHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_cyril\hhl_m_cyril_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_cyril\hhl_m_cyril_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_cyril\hhl_m_cyril_body_shaved_co.paa","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_shaved.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_unshaved_co.paa","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_unshaved.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_bearded_co.paa","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_bearded.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_beard_ca.paa","dz\characters\heads\data\m_cyril\hhl_m_cyril_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_cyril\hhl_m_cyril_body_shaved.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_shaved_injury.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_shaved_injury2.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_unshaved.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_unshaved_injury.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_bearded.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_bearded_injury.rvmat","dz\characters\heads\data\m_cyril\hhl_m_cyril_body_bearded_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorM_Denis: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleDenisHead";
		emptyBody = "MaleDenisTorso";
		emptyLegs = "MaleDenisLegs";
		emptyFeet = "MaleDenisFeet";
		emptyGloves = "MaleDenisHands";
		faceType = "MaleDenisHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_denis_2\hhl_m_denis_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_denis_2\hhl_m_denis_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_denis_2\hhl_m_denis_body_shaved_co.paa","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_shaved.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_unshaved_co.paa","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_unshaved.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_bearded_co.paa","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_bearded.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_beard_ca.paa","dz\characters\heads\data\m_denis_2\hhl_m_denis_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_denis_2\hhl_m_denis_body_shaved.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_shaved_injury.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_shaved_injury2.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_unshaved.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_unshaved_injury.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_bearded.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_bearded_injury.rvmat","dz\characters\heads\data\m_denis_2\hhl_m_denis_body_bearded_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorM_Elias: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleEliasHead";
		emptyBody = "MaleEliasTorso";
		emptyLegs = "MaleEliasLegs";
		emptyFeet = "MaleEliasFeet";
		emptyGloves = "MaleEliasHands";
		faceType = "MaleEliasHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_elias\hhl_m_elias_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_elias\hhl_m_elias_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_elias\hhl_m_elias_body_shaved_co.paa","dz\characters\heads\data\m_elias\hhl_m_elias_body_shaved.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_body_unshaved_co.paa","dz\characters\heads\data\m_elias\hhl_m_elias_body_unshaved.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_body_bearded_co.paa","dz\characters\heads\data\m_elias\hhl_m_elias_body_bearded.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_beard_ca.paa","dz\characters\heads\data\m_elias\hhl_m_elias_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_elias\hhl_m_elias_body_shaved.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_body_shaved_injury.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_body_shaved_injury2.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_body_unshaved.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_body_unshaved_injury.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_body_bearded.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_body_bearded_injury.rvmat","dz\characters\heads\data\m_elias\hhl_m_elias_body_bearded_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorM_Francis: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleFrancisHead";
		emptyBody = "MaleFrancisTorso";
		emptyLegs = "MaleFrancisLegs";
		emptyFeet = "MaleFrancisFeet";
		emptyGloves = "MaleFrancisHands";
		faceType = "MaleFrancisHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_francis\hhl_m_francis_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_francis\hhl_m_francis_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_francis\hhl_m_francis_body_shaved_co.paa","dz\characters\heads\data\m_francis\hhl_m_francis_body_shaved.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_body_unshaved_co.paa","dz\characters\heads\data\m_francis\hhl_m_francis_body_unshaved.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_body_bearded_co.paa","dz\characters\heads\data\m_francis\hhl_m_francis_body_bearded.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_beard_ca.paa","dz\characters\heads\data\m_francis\hhl_m_francis_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_francis\hhl_m_francis_body_shaved.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_body_shaved_injury.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_body_shaved_injury2.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_body_unshaved.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_body_unshaved_injury.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_body_bearded.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_body_bearded_injury.rvmat","dz\characters\heads\data\m_francis\hhl_m_francis_body_bearded_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorM_Guo: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleGuoHead";
		emptyBody = "MaleGuoTorso";
		emptyLegs = "MaleGuoLegs";
		emptyFeet = "MaleGuoFeet";
		emptyGloves = "MaleGuoHands";
		faceType = "MaleGuoHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_guo\hhl_m_guo_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_guo\hhl_m_guo_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_guo\hhl_m_guo_body_shaved_co.paa","dz\characters\heads\data\m_guo\hhl_m_guo_body_shaved.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_body_unshaved_co.paa","dz\characters\heads\data\m_guo\hhl_m_guo_body_unshaved.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_body_bearded_co.paa","dz\characters\heads\data\m_guo\hhl_m_guo_body_bearded.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_beard_ca.paa","dz\characters\heads\data\m_guo\hhl_m_guo_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_guo\hhl_m_guo_body_shaved.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_body_shaved_injury.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_body_shaved_injury2.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_body_unshaved.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_body_unshaved_injury.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_body_bearded.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_body_bearded_injury.rvmat","dz\characters\heads\data\m_guo\hhl_m_guo_body_bearded_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorM_Hassan: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleHassanHead";
		emptyBody = "MaleHassanTorso";
		emptyLegs = "MaleHassanLegs";
		emptyFeet = "MaleHassanFeet";
		emptyGloves = "MaleHassanHands";
		faceType = "MaleHassanHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_hassan\hhl_m_hassan_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_hassan\hhl_m_hassan_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_hassan\hhl_m_hassan_body_shaved_co.paa","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_shaved.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_unshaved_co.paa","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_unshaved.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_bearded_co.paa","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_bearded.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_beard_ca.paa","dz\characters\heads\data\m_hassan\hhl_m_hassan_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_hassan\hhl_m_hassan_body_shaved.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_shaved_injury.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_shaved_injury2.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_unshaved.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_unshaved_injury.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_bearded.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_bearded_injury.rvmat","dz\characters\heads\data\m_hassan\hhl_m_hassan_body_bearded_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorM_Indar: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleIndarHead";
		emptyBody = "MaleIndarTorso";
		emptyLegs = "MaleIndarLegs";
		emptyFeet = "MaleIndarFeet";
		emptyGloves = "MaleIndarHands";
		faceType = "MaleIndarHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_indar\hhl_m_indar_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_indar\hhl_m_indar_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_indar\hhl_m_indar_body_shaved_co.paa","dz\characters\heads\data\m_indar\hhl_m_indar_body_shaved.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_body_unshaved_co.paa","dz\characters\heads\data\m_indar\hhl_m_indar_body_unshaved.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_body_bearded_co.paa","dz\characters\heads\data\m_indar\hhl_m_indar_body_bearded.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_beard_ca.paa","dz\characters\heads\data\m_indar\hhl_m_indar_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_indar\hhl_m_indar_body_shaved.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_body_shaved_injury.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_body_shaved_injury2.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_body_unshaved.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_body_unshaved_injury.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_body_bearded.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_body_bearded_injury.rvmat","dz\characters\heads\data\m_indar\hhl_m_indar_body_bearded_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorM_Jose: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleJoseHead";
		emptyBody = "MaleJoseTorso";
		emptyLegs = "MaleJoseLegs";
		emptyFeet = "MaleJoseFeet";
		emptyGloves = "MaleJoseHands";
		faceType = "MaleJoseHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_jose\hhl_m_jose_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_jose\hhl_m_jose_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_jose\hhl_m_jose_body_shaved_co.paa","dz\characters\heads\data\m_jose\hhl_m_jose_body_shaved.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_body_unshaved_co.paa","dz\characters\heads\data\m_jose\hhl_m_jose_body_unshaved.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_body_bearded_co.paa","dz\characters\heads\data\m_jose\hhl_m_jose_body_bearded.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_beard_ca.paa","dz\characters\heads\data\m_jose\hhl_m_jose_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_jose\hhl_m_jose_body_shaved.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_body_shaved_injury.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_body_shaved_injury2.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_body_unshaved.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_body_unshaved_injury.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_body_bearded.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_body_bearded_injury.rvmat","dz\characters\heads\data\m_jose\hhl_m_jose_body_bearded_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorM_Kaito: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleKaitoHead";
		emptyBody = "MaleKaitoTorso";
		emptyLegs = "MaleKaitoLegs";
		emptyFeet = "MaleKaitoFeet";
		emptyGloves = "MaleKaitoHands";
		faceType = "MaleKaitoHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_kaito\hhl_m_kaito_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_kaito\hhl_m_kaito_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_kaito\hhl_m_kaito_body_shaved_co.paa","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_shaved.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_unshaved_co.paa","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_unshaved.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_bearded_co.paa","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_bearded.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_beard_ca.paa","dz\characters\heads\data\m_kaito\hhl_m_kaito_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_kaito\hhl_m_kaito_body_shaved.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_shaved_injury.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_shaved_injury2.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_unshaved.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_unshaved_injury.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_bearded.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_bearded_injury.rvmat","dz\characters\heads\data\m_kaito\hhl_m_kaito_body_bearded_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorM_Lewis: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleLewisHead";
		emptyBody = "MaleLewisTorso";
		emptyLegs = "MaleLewisLegs";
		emptyFeet = "MaleLewisFeet";
		emptyGloves = "MaleLewisHands";
		faceType = "MaleLewisHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_lewis\hhl_m_lewis_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_lewis\hhl_m_lewis_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_lewis\hhl_m_lewis_body_shaved_co.paa","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_shaved.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_unshaved_co.paa","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_unshaved.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_bearded_co.paa","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_bearded.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_beard_ca.paa","dz\characters\heads\data\m_lewis\hhl_m_lewis_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_lewis\hhl_m_lewis_body_shaved.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_shaved_injury.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_shaved_injury2.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_unshaved.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_unshaved_injury.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_bearded.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_bearded_injury.rvmat","dz\characters\heads\data\m_lewis\hhl_m_lewis_body_bearded_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorM_Manua: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleManuaHead";
		emptyBody = "MaleManuaTorso";
		emptyLegs = "MaleManuaLegs";
		emptyFeet = "MaleManuaFeet";
		emptyGloves = "MaleManuaHands";
		faceType = "MaleManuaHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_manua\hhl_m_manua_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_manua\hhl_m_manua_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_manua\hhl_m_manua_body_shaved_co.paa","dz\characters\heads\data\m_manua\hhl_m_manua_body_shaved.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_body_unshaved_co.paa","dz\characters\heads\data\m_manua\hhl_m_manua_body_unshaved.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_body_bearded_co.paa","dz\characters\heads\data\m_manua\hhl_m_manua_body_bearded.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_beard_ca.paa","dz\characters\heads\data\m_manua\hhl_m_manua_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_manua\hhl_m_manua_body_shaved.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_body_shaved_injury.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_body_shaved_injury2.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_body_unshaved.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_body_unshaved_injury.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_body_bearded.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_body_bearded_injury.rvmat","dz\characters\heads\data\m_manua\hhl_m_manua_body_bearded_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorM_Niki: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleNikiHead";
		emptyBody = "MaleNikiTorso";
		emptyLegs = "MaleNikiLegs";
		emptyFeet = "MaleNikiFeet";
		emptyGloves = "MaleNikiHands";
		faceType = "MaleNikiHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_niki_2\hhl_m_niki_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_niki_2\hhl_m_niki_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_niki_2\hhl_m_niki_body_shaved_co.paa","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_shaved.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_unshaved_co.paa","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_unshaved.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_bearded_co.paa","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_bearded.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_beard_ca.paa","dz\characters\heads\data\m_niki_2\hhl_m_niki_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_niki_2\hhl_m_niki_body_shaved.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_shaved_injury.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_shaved_injury2.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_unshaved.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_unshaved_injury.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_bearded.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_bearded_injury.rvmat","dz\characters\heads\data\m_niki_2\hhl_m_niki_body_bearded_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorM_Oliver: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleOliverHead";
		emptyBody = "MaleOliverTorso";
		emptyLegs = "MaleOliverLegs";
		emptyFeet = "MaleOliverFeet";
		emptyGloves = "MaleOliverHands";
		faceType = "MaleOliverHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_oliver\hhl_m_oliver_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_oliver\hhl_m_oliver_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_oliver\hhl_m_oliver_body_shaved_co.paa","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_shaved.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_unshaved_co.paa","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_unshaved.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_bearded_co.paa","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_bearded.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_beard_ca.paa","dz\characters\heads\data\m_oliver\hhl_m_oliver_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_oliver\hhl_m_oliver_body_shaved.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_shaved_injury.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_shaved_injury2.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_unshaved.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_unshaved_injury.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_bearded.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_bearded_injury.rvmat","dz\characters\heads\data\m_oliver\hhl_m_oliver_body_bearded_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorM_Peter: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MalePeterHead";
		emptyBody = "MalePeterTorso";
		emptyLegs = "MalePeterLegs";
		emptyFeet = "MalePeterFeet";
		emptyGloves = "MalePeterHands";
		faceType = "MalePeterHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_peter\hhl_m_peter_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_peter\hhl_m_peter_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_peter\hhl_m_peter_body_shaved_co.paa","dz\characters\heads\data\m_peter\hhl_m_peter_body_shaved.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_body_unshaved_co.paa","dz\characters\heads\data\m_peter\hhl_m_peter_body_unshaved.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_body_bearded_co.paa","dz\characters\heads\data\m_peter\hhl_m_peter_body_bearded.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_beard_ca.paa","dz\characters\heads\data\m_peter\hhl_m_peter_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_peter\hhl_m_peter_body_shaved.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_body_shaved_injury.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_body_shaved_injury2.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_body_unshaved.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_body_unshaved_injury.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_body_bearded.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_body_bearded_injury.rvmat","dz\characters\heads\data\m_peter\hhl_m_peter_body_bearded_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorM_Quinn: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleQuinnHead";
		emptyBody = "MaleQuinnTorso";
		emptyLegs = "MaleQuinnLegs";
		emptyFeet = "MaleQuinnFeet";
		emptyGloves = "MaleQuinnHands";
		faceType = "MaleQuinnHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_quinn\hhl_m_quinn_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_quinn\hhl_m_quinn_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_quinn\hhl_m_quinn_body_shaved_co.paa","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_shaved.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_unshaved_co.paa","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_unshaved.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_bearded_co.paa","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_bearded.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_beard_ca.paa","dz\characters\heads\data\m_quinn\hhl_m_quinn_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_quinn\hhl_m_quinn_body_shaved.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_shaved_injury.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_shaved_injury2.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_unshaved.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_unshaved_injury.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_bearded.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_bearded_injury.rvmat","dz\characters\heads\data\m_quinn\hhl_m_quinn_body_bearded_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorM_Rolf: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleRolfHead";
		emptyBody = "MaleRolfTorso";
		emptyLegs = "MaleRolfLegs";
		emptyFeet = "MaleRolfFeet";
		emptyGloves = "MaleRolfHands";
		faceType = "MaleRolfHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_rolf\hhl_m_rolf_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_rolf\hhl_m_rolf_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_rolf\hhl_m_rolf_body_shaved_co.paa","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_shaved.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_unshaved_co.paa","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_unshaved.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_bearded_co.paa","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_bearded.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_beard_ca.paa","dz\characters\heads\data\m_rolf\hhl_m_rolf_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_rolf\hhl_m_rolf_body_shaved.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_shaved_injury.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_shaved_injury2.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_unshaved.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_unshaved_injury.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_bearded.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_bearded_injury.rvmat","dz\characters\heads\data\m_rolf\hhl_m_rolf_body_bearded_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorM_Seth: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleSethHead";
		emptyBody = "MaleSethTorso";
		emptyLegs = "MaleSethLegs";
		emptyFeet = "MaleSethFeet";
		emptyGloves = "MaleSethHands";
		faceType = "MaleSethHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_seth\hhl_m_seth_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_seth\hhl_m_seth_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_seth\hhl_m_seth_body_shaved_co.paa","dz\characters\heads\data\m_seth\hhl_m_seth_body_shaved.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_body_unshaved_co.paa","dz\characters\heads\data\m_seth\hhl_m_seth_body_unshaved.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_body_bearded_co.paa","dz\characters\heads\data\m_seth\hhl_m_seth_body_bearded.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_beard_ca.paa","dz\characters\heads\data\m_seth\hhl_m_seth_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_seth\hhl_m_seth_body_shaved.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_body_shaved_injury.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_body_shaved_injury2.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_body_unshaved.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_body_unshaved_injury.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_body_bearded.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_body_bearded_injury.rvmat","dz\characters\heads\data\m_seth\hhl_m_seth_body_bearded_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorM_Taiki: SurvivorMale_Base
	{
		scope = 2;
		emptyHead = "MaleTaikiHead";
		emptyBody = "MaleTaikiTorso";
		emptyLegs = "MaleTaikiLegs";
		emptyFeet = "MaleTaikiFeet";
		emptyGloves = "MaleTaikiHands";
		faceType = "MaleTaikiHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\m_taiki\hhl_m_taiki_body_shaved.rvmat";
			mat_blood = "dz\characters\heads\data\m_taiki\hhl_m_taiki_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {"dz\characters\heads\data\m_taiki\hhl_m_taiki_body_shaved_co.paa","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_shaved.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_unshaved_co.paa","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_unshaved.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_bearded_co.paa","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_bearded.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_beard_ca.paa","dz\characters\heads\data\m_taiki\hhl_m_taiki_beard.rvmat"};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\m_taiki\hhl_m_taiki_body_shaved.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_shaved_injury.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_shaved_injury2.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_unshaved.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_unshaved_injury.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_unshaved_injury2.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_bearded.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_bearded_injury.rvmat","dz\characters\heads\data\m_taiki\hhl_m_taiki_body_bearded_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorF_Eva: SurvivorFemale_Base
	{
		scope = 2;
		emptyHead = "FemaleEvaHead";
		emptyBody = "FemaleEvaTorso";
		emptyLegs = "FemaleEvaLegs";
		emptyFeet = "FemaleEvaFeet";
		emptyGloves = "FemaleEvaHands";
		faceType = "FemaleEvaHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_eva_2\hhl_f_eva_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_eva_2\hhl_f_eva_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\f_eva_2\hhl_f_eva_body.rvmat","dz\characters\heads\data\f_eva_2\hhl_f_eva_body_injury.rvmat","dz\characters\heads\data\f_eva_2\hhl_f_eva_body_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorF_Frida: SurvivorFemale_Base
	{
		scope = 2;
		emptyHead = "FemaleFridaHead";
		emptyBody = "FemaleFridaTorso";
		emptyLegs = "FemaleFridaLegs";
		emptyFeet = "FemaleFridaFeet";
		emptyGloves = "FemaleFridaHands";
		faceType = "FemaleFridaHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_frida_2\hhl_f_frida_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_frida_2\hhl_f_frida_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\f_frida_2\hhl_f_frida_body.rvmat","dz\characters\heads\data\f_frida_2\hhl_f_frida_body_injury.rvmat","dz\characters\heads\data\f_frida_2\hhl_f_frida_body_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorF_Gabi: SurvivorFemale_Base
	{
		scope = 2;
		emptyHead = "FemaleGabiHead";
		emptyBody = "FemaleGabiTorso";
		emptyLegs = "FemaleGabiLegs";
		emptyFeet = "FemaleGabiFeet";
		emptyGloves = "FemaleGabiHands";
		faceType = "FemaleGabiHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_gabi_2\hhl_f_gabi_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_gabi_2\hhl_f_gabi_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\f_gabi_2\hhl_f_gabi_body.rvmat","dz\characters\heads\data\f_gabi_2\hhl_f_gabi_body_injury.rvmat","dz\characters\heads\data\f_gabi_2\hhl_f_gabi_body_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorF_Helga: SurvivorFemale_Base
	{
		scope = 2;
		emptyHead = "FemaleHelgaHead";
		emptyBody = "FemaleHelgaTorso";
		emptyLegs = "FemaleHelgaLegs";
		emptyFeet = "FemaleHelgaFeet";
		emptyGloves = "FemaleHelgaHands";
		faceType = "FemaleHelgaHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_helga\hhl_f_helga_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_helga\hhl_f_helga_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\f_helga\hhl_f_helga_body.rvmat","dz\characters\heads\data\f_helga\hhl_f_helga_body_injury.rvmat","dz\characters\heads\data\f_helga\hhl_f_helga_body_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorF_Irena: SurvivorFemale_Base
	{
		scope = 2;
		emptyHead = "FemaleIrenaHead";
		emptyBody = "FemaleIrenaTorso";
		emptyLegs = "FemaleIrenaLegs";
		emptyFeet = "FemaleIrenaFeet";
		emptyGloves = "FemaleIrenaHands";
		faceType = "FemaleIrenaHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_irena_2\hhl_f_irena_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_irena_2\hhl_f_irena_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\f_irena_2\hhl_f_irena_body.rvmat","dz\characters\heads\data\f_irena_2\hhl_f_irena_body_injury.rvmat","dz\characters\heads\data\f_irena_2\hhl_f_irena_body_injury2.rvmat"};
		};
		voiceType = 1;
	};
	class SurvivorF_Judy: SurvivorFemale_Base
	{
		scope = 2;
		emptyHead = "FemaleJudyHead";
		emptyBody = "FemaleJudyTorso";
		emptyLegs = "FemaleJudyLegs";
		emptyFeet = "FemaleJudyFeet";
		emptyGloves = "FemaleJudyHands";
		faceType = "FemaleJudyHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_judy\hhl_f_judy_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_judy\hhl_f_judy_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\f_judy\hhl_f_judy_body.rvmat","dz\characters\heads\data\f_judy\hhl_f_judy_body_injury.rvmat","dz\characters\heads\data\f_judy\hhl_f_judy_body_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorF_Keiko: SurvivorFemale_Base
	{
		scope = 2;
		emptyHead = "FemaleKeikoHead";
		emptyBody = "FemaleKeikoTorso";
		emptyLegs = "FemaleKeikoLegs";
		emptyFeet = "FemaleKeikoFeet";
		emptyGloves = "FemaleKeikoHands";
		faceType = "FemaleKeikoHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_keiko\hhl_f_keiko_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_keiko\hhl_f_keiko_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\f_keiko\hhl_f_keiko_body.rvmat","dz\characters\heads\data\f_keiko\hhl_f_keiko_body_injury.rvmat","dz\characters\heads\data\f_keiko\hhl_f_keiko_body_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorF_Linda: SurvivorFemale_Base
	{
		scope = 2;
		emptyHead = "FemaleLindaHead";
		emptyBody = "FemaleLindaTorso";
		emptyLegs = "FemaleLindaLegs";
		emptyFeet = "FemaleLindaFeet";
		emptyGloves = "FemaleLindaHands";
		faceType = "FemaleLindaHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_linda_2\hhl_f_linda_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_linda_2\hhl_f_linda_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\f_linda_2\hhl_f_linda_body.rvmat","dz\characters\heads\data\f_linda_2\hhl_f_linda_body_injury.rvmat","dz\characters\heads\data\f_linda_2\hhl_f_linda_body_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorF_Maria: SurvivorFemale_Base
	{
		scope = 2;
		emptyHead = "FemaleMariaHead";
		emptyBody = "FemaleMariaTorso";
		emptyLegs = "FemaleMariaLegs";
		emptyFeet = "FemaleMariaFeet";
		emptyGloves = "FemaleMariaHands";
		faceType = "FemaleMariaHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_maria_2\hhl_f_maria_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_maria_2\hhl_f_maria_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\f_maria_2\hhl_f_maria_body.rvmat","dz\characters\heads\data\f_maria_2\hhl_f_maria_body_injury.rvmat","dz\characters\heads\data\f_maria_2\hhl_f_maria_body_injury2.rvmat"};
		};
		voiceType = 2;
	};
	class SurvivorF_Naomi: SurvivorFemale_Base
	{
		scope = 2;
		emptyHead = "FemaleNaomiHead";
		emptyBody = "FemaleNaomiTorso";
		emptyLegs = "FemaleNaomiLegs";
		emptyFeet = "FemaleNaomiFeet";
		emptyGloves = "FemaleNaomiHands";
		faceType = "FemaleNaomiHead";
		class BloodyHands
		{
			mat_normal = "dz\characters\heads\data\f_naomi\hhl_f_naomi_body.rvmat";
			mat_blood = "dz\characters\heads\data\f_naomi\hhl_f_naomi_body_bloodyhands.rvmat";
		};
		class Lifespan
		{
			class Beard
			{
				mat[] = {};
			};
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"dz\characters\heads\data\f_naomi\hhl_f_naomi_body.rvmat","dz\characters\heads\data\f_naomi\hhl_f_naomi_body_injury.rvmat","dz\characters\heads\data\f_naomi\hhl_f_naomi_body_injury2.rvmat"};
		};
		voiceType = 2;
	};
};
class CfgAimHelperParameters
{
	debugDraw = 0;
	allowOnInfected = 1;
	allowOnAnimal = 1;
	allowOnPlayer = 0;
	class TargetSnapping
	{
		enabled = 0;
		enabledXbox = 1;
		enabledPS4 = 1;
		onlyInIronsight = 0;
		crosshairWidth = 0.5;
		aimMinDistance = 3.0;
		aimMaxDistance = 50.0;
		aimSpeed = 0.25;
		animalBonePairs[] = {"pelvis","head","lfleg1","rfleg1","frontlleg1","frontrleg1","lleg1","rleg1"};
		humanBonePairs[] = {"pelvis","neck","leftarm","rightarm"};
	};
	class ScopeSlowing
	{
		enabled = 0;
		enabledXbox = 0;
		enabledPS4 = 0;
		onlyInIronsight = 0;
		speedMultiplier = "0.2f";
		aimMinDistance = 0.5;
		aimMaxDistance = 300.0;
		crosshairWidth = "5.0f";
		minScopeZoom = "80.0f";
	};
};
class CfgNonAIVehicles
{
	class ProxyHands;
	class ProxyAK_47_v58_Proxy: ProxyHands
	{
		model = "\dz\Characters\Proxies\ak_47_v58_proxy.p3d";
	};
	class ProxyShoulder;
	class ProxyRPG7_Proxy: ProxyShoulder
	{
		model = "\dz\Characters\Proxies\RPG7_proxy.p3d";
	};
	class ProxyArmband;
	class ProxyArmband_DZ: ProxyArmband
	{
		model = "\dz\Characters\Proxies\Armband_DZ.p3d";
	};
	class ProxyBack;
	class ProxyBackpack_DZ: ProxyBack
	{
		model = "\dz\Characters\Proxies\Backpack_DZ.p3d";
	};
	class ProxyEyewear;
	class ProxyEyewear_DZ: ProxyEyewear
	{
		model = "\dz\Characters\Proxies\Eyewear_DZ.p3d";
	};
	class ProxyHeadgear;
	class ProxyHeadgear_DZ: ProxyHeadgear
	{
		model = "\dz\Characters\Proxies\Headgear_DZ.p3d";
	};
	class ProxyMask;
	class ProxyMask_DZ: ProxyMask
	{
		model = "\dz\Characters\Proxies\Mask_DZ.p3d";
	};
	class ProxyBody;
	class ProxyBody_DZ: ProxyBody
	{
		model = "\dz\Characters\Proxies\Body_DZ.p3d";
	};
	class ProxyLegs;
	class ProxyLegs_DZ: ProxyLegs
	{
		model = "\dz\Characters\Proxies\Legs_DZ.p3d";
	};
	class ProxyFeet;
	class ProxyFeet_DZ: ProxyFeet
	{
		model = "\dz\Characters\Proxies\Feet_DZ.p3d";
	};
	class ProxyGloves;
	class ProxyGloves_DZ: ProxyGloves
	{
		model = "\dz\Characters\Proxies\Gloves_DZ.p3d";
	};
	class ProxyVest;
	class ProxyVest_DZ: ProxyVest
	{
		model = "\dz\Characters\Proxies\Vest_DZ.p3d";
	};
	class ProxyMelee;
	class ProxyMelee_DZ: ProxyMelee
	{
		model = "\dz\Characters\Proxies\Melee_DZ.p3d";
	};
	class ProxyBow;
	class ProxyBow_DZ: ProxyBow
	{
		model = "\dz\Characters\Proxies\bow_DZ.p3d";
	};
	class ProxyHips;
	class ProxyHips_DZ: ProxyHips
	{
		model = "\dz\Characters\Proxies\hips_DZ.p3d";
	};
	class ProxyAttachment;
	class ProxyLHand_DZ: ProxyAttachment
	{
		inventorySlot = "LeftHand";
		model = "\dz\Characters\Proxies\LHand_DZ.p3d";
	};
};