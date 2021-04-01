#define _ARMA_

class CfgPatches
{
	class DZ_Scripts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgSlots
{
	class Slot_Head
	{
		name = "Head";
		displayName = "";
		ghostIcon = "";
		show = "false";
	};
	class Slot_Shoulder
	{
		name = "Shoulder";
		displayName = "$STR_CfgShoulder0";
		ghostIcon = "set:dayz_inventory image:shoulderleft";
	};
	class Slot_Melee
	{
		name = "Melee";
		displayName = "$STR_CfgShoulder0";
		ghostIcon = "set:dayz_inventory image:shoulderright";
	};
	class Slot_Bow
	{
		name = "Bow";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:bow";
	};
	class Slot_Headgear
	{
		name = "Headgear";
		displayName = "$STR_CfgHeadgear0";
		ghostIcon = "set:dayz_inventory image:headgear";
		boneName = "Head";
	};
	class Slot_Mask
	{
		name = "Mask";
		displayName = "$STR_CfgMask0";
		ghostIcon = "set:dayz_inventory image:mask";
	};
	class Slot_Eyewear
	{
		name = "Eyewear";
		displayName = "$STR_CfgEyewear0";
		ghostIcon = "set:dayz_inventory image:eyewear";
	};
	class Slot_Hands
	{
		name = "Hands";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:hands";
		boneName = "RightHand";
	};
	class Slot_LeftHand
	{
		name = "LeftHand";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:hands";
		boneName = "LeftHand";
		show = "false";
	};
	class Slot_Gloves
	{
		name = "Gloves";
		displayName = "$STR_CfgGloves0";
		ghostIcon = "set:dayz_inventory image:gloves";
	};
	class Slot_Armband
	{
		name = "Armband";
		displayName = "$STR_CfgArmband0";
		ghostIcon = "set:dayz_inventory image:armband";
	};
	class Slot_Vest
	{
		name = "Vest";
		displayName = "$STR_CfgVest0";
		ghostIcon = "set:dayz_inventory image:vest";
	};
	class Slot_Body
	{
		name = "Body";
		displayName = "$STR_CfgBody0";
		ghostIcon = "set:dayz_inventory image:body";
	};
	class Slot_Back
	{
		name = "Back";
		displayName = "$STR_CfgBack0";
		ghostIcon = "set:dayz_inventory image:back";
	};
	class Slot_Hips
	{
		name = "Hips";
		displayName = "$STR_CfgHips0";
		ghostIcon = "set:dayz_inventory image:hips";
	};
	class Slot_Legs
	{
		name = "Legs";
		displayName = "$STR_CfgLegs0";
		ghostIcon = "set:dayz_inventory image:legs";
	};
	class Slot_Feet
	{
		name = "Feet";
		displayName = "$STR_CfgFeet0";
		ghostIcon = "set:dayz_inventory image:feet";
	};
	class Slot_Pistol
	{
		name = "Pistol";
		displayName = "$STR_CfgPistol0";
		ghostIcon = "set:dayz_inventory image:pistol";
	};
	class Slot_Knife
	{
		name = "Knife";
		displayName = "$STR_CfgKnife0";
		ghostIcon = "set:dayz_inventory image:knife";
	};
	class Slot_magazine
	{
		name = "magazine";
		displayName = "$STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine";
		autoAttach = "false";
	};
	class Slot_magazine2
	{
		name = "magazine2";
		displayName = "$STR_CfgMagazine0";
		ghostIcon = "set:dayz_inventory image:magazine2";
		autoAttach = "false";
	};
	class Slot_magazine3
	{
		name = "magazine3";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:magazine3";
		autoAttach = "false";
	};
	class Slot_Driver
	{
		name = "Driver";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:doors";
	};
	class Slot_Cargo
	{
		name = "Cargo";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:missing";
	};
	class Slot_Muzzle1
	{
		name = "Muzzle1";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:muzzle";
	};
	class Slot_Muzzle2
	{
		name = "Muzzle2";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:muzzle";
	};
	class Slot_Muzzle3
	{
		name = "Muzzle3";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:muzzle";
	};
	class Slot_VestHolster
	{
		name = "VestHolster";
		displayName = "$STR_CfgBelt_Right0";
		ghostIcon = "set:dayz_inventory image:vestholster";
	};
	class Slot_VestPouch
	{
		name = "VestPouch";
		displayName = "$STR_CfgVestPouch0";
		ghostIcon = "set:dayz_inventory image:vestpouches";
	};
	class Slot_VestBackpack
	{
		name = "VestBackpack";
		displayName = "$STR_CfgVestBackpack0";
		ghostIcon = "set:dayz_inventory image:back";
	};
	class Slot_pistolFlashlight
	{
		name = "pistolFlashlight";
		displayName = "$STR_CfgFlashlight0";
		ghostIcon = "set:dayz_inventory image:weaponflashlight";
	};
	class Slot_pistolMuzzle
	{
		name = "pistolMuzzle";
		displayName = "$STR_CfgSuppressor0";
		ghostIcon = "set:dayz_inventory image:supressor";
	};
	class Slot_pistolOptics
	{
		name = "pistolOptics";
		displayName = "$STR_CfgPistolOptics0";
		ghostIcon = "set:dayz_inventory image:weaponopticssmall";
	};
	class Slot_weaponBayonet
	{
		name = "weaponBayonet";
		displayName = "$STR_CfgBayonet0";
		ghostIcon = "set:dayz_inventory image:bayonet";
	};
	class Slot_weaponBayonetAK
	{
		name = "weaponBayonetAK";
		displayName = "$STR_CfgBayonet0";
		ghostIcon = "set:dayz_inventory image:bayonet";
	};
	class Slot_weaponBayonetMosin
	{
		name = "weaponBayonetMosin";
		displayName = "$STR_CfgBayonet0";
		ghostIcon = "set:dayz_inventory image:bayonet";
	};
	class Slot_weaponBayonetSKS
	{
		name = "weaponBayonetSKS";
		displayName = "$STR_CfgBayonet0";
		ghostIcon = "set:dayz_inventory image:bayonet";
	};
	class Slot_weaponButtstockAK
	{
		name = "weaponButtstockAK";
		displayName = "$STR_CfgButtstock0";
		ghostIcon = "set:dayz_inventory image:buttstock";
	};
	class Slot_weaponButtstockFal
	{
		name = "weaponButtstockFal";
		displayName = "$STR_CfgButtstock0";
		ghostIcon = "set:dayz_inventory image:buttstock";
	};
	class Slot_weaponButtstockM4
	{
		name = "weaponButtstockM4";
		displayName = "$STR_CfgButtstock0";
		ghostIcon = "set:dayz_inventory image:buttstock";
	};
	class Slot_weaponButtstockMP5
	{
		name = "weaponButtstockMP5";
		displayName = "$STR_CfgButtstock0";
		ghostIcon = "set:dayz_inventory image:buttstock";
	};
	class Slot_weaponButtstockRed9
	{
		name = "weaponButtstockRed9";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:buttstock";
	};
	class Slot_weaponButtstockSaiga
	{
		name = "weaponButtstockSaiga";
		displayName = "$STR_CfgButtstock0";
		ghostIcon = "set:dayz_inventory image:buttstock";
	};
	class Slot_weaponHandguardAK
	{
		name = "weaponHandguardAK";
		displayName = "$STR_CfgHandguard0";
		ghostIcon = "set:dayz_inventory image:handguard";
	};
	class Slot_weaponHandguardM4
	{
		name = "weaponHandguardM4";
		displayName = "$STR_CfgHandguard0";
		ghostIcon = "set:dayz_inventory image:handguard";
	};
	class Slot_weaponHandguardMP5
	{
		name = "weaponHandguardMP5";
		displayName = "$STR_CfgHandguard0";
		ghostIcon = "set:dayz_inventory image:handguard";
	};
	class Slot_weaponHandguardM249
	{
		name = "weaponHandguardM249";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:handguard";
	};
	class Slot_weaponMuzzle
	{
		name = "weaponMuzzle";
		displayName = "$STR_CfgMuzzle0";
		ghostIcon = "set:dayz_inventory image:weaponmuzzle";
	};
	class Slot_weaponMuzzleAK
	{
		name = "weaponMuzzleAK";
		displayName = "$STR_CfgSuppressor0";
		ghostIcon = "set:dayz_inventory image:supressor";
	};
	class Slot_weaponMuzzleM4
	{
		name = "weaponMuzzleM4";
		displayName = "$STR_CfgSuppressor0";
		ghostIcon = "set:dayz_inventory image:supressor";
	};
	class Slot_weaponMuzzleMP5
	{
		name = "weaponMuzzleMP5";
		displayName = "$STR_CfgMuzzle0";
		ghostIcon = "set:dayz_inventory image:weaponmuzzle";
	};
	class Slot_weaponMuzzleMosin
	{
		name = "weaponMuzzleMosin";
		displayName = "$STR_CfgMuzzle0";
		ghostIcon = "set:dayz_inventory image:weaponmuzzle";
	};
	class Slot_weaponUnderSlugM4
	{
		name = "weaponUnderSlugM4";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:weaponunderslungm4";
	};
	class Slot_weaponUnderSlugAK
	{
		name = "weaponUnderSlugAK";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:weaponunderslungak";
	};
	class Slot_weaponBarrelAug
	{
		name = "weaponBarrelAug";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:weaponmuzzle";
	};
	class Slot_weaponOptics
	{
		name = "weaponOptics";
		displayName = "$STR_CfgWeaponOptics0";
		ghostIcon = "set:dayz_inventory image:weaponoptics";
	};
	class Slot_weaponOpticsAcog
	{
		name = "weaponOpticsAcog";
		displayName = "$STR_CfgWeaponOptics0";
		ghostIcon = "set:dayz_inventory image:weaponoptics";
	};
	class Slot_weaponOpticsAK
	{
		name = "weaponOpticsAK";
		displayName = "$STR_CfgWeaponOptics0";
		ghostIcon = "set:dayz_inventory image:weaponoptics";
	};
	class Slot_weaponOpticsCrossbow
	{
		name = "weaponOpticsCrossbow";
		displayName = "$STR_CfgPistolOptics0";
		ghostIcon = "set:dayz_inventory image:weaponopticssmall";
	};
	class Slot_weaponOpticsHunting
	{
		name = "weaponOpticsHunting";
		displayName = "$STR_CfgWeaponOptics0";
		ghostIcon = "set:dayz_inventory image:weaponoptics";
	};
	class Slot_weaponOpticsLRS
	{
		name = "weaponOpticsLRS";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:weaponoptics";
	};
	class Slot_weaponOpticsMosin
	{
		name = "weaponOpticsMosin";
		displayName = "$STR_CfgWeaponOptics0";
		ghostIcon = "set:dayz_inventory image:weaponoptics";
	};
	class Slot_weaponBipod
	{
		name = "weaponBipod";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:bipod";
	};
	class Slot_weaponBipodM249
	{
		name = "Slot_weaponBipodM249";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:bipod";
	};
	class Slot_weaponFlashlight
	{
		name = "weaponFlashlight";
		displayName = "$STR_CfgFlashlight0";
		ghostIcon = "set:dayz_inventory image:weaponflashlight";
	};
	class Slot_suppressorImpro
	{
		name = "suppressorImpro";
		displayName = "$STR_CfgSuppressor0";
		ghostIcon = "set:dayz_inventory image:supressor";
	};
	class Slot_weaponWrap
	{
		name = "weaponWrap";
		displayName = "$STR_CfgWeaponWrap0";
		ghostIcon = "set:dayz_inventory image:weaponwrap";
	};
	class Slot_magazineFakeWeapon
	{
		name = "magazineFakeWeapon";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:magazinefakeweapon";
		autoAttach = "false";
	};
	class Slot_tripWireAttachment
	{
		name = "tripWireAttachment";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:tripwireattachment";
	};
	class Slot_BatteryD
	{
		name = "BatteryD";
		displayName = "$STR_CfgBatteryD0";
		ghostIcon = "set:dayz_inventory image:batteryd";
	};
	class Slot_MetalWire
	{
		name = "MetalWire";
		displayName = "$STR_CfgMetalWire0";
		ghostIcon = "set:dayz_inventory image:metalwire";
	};
	class Slot_Book
	{
		name = "Book";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:book";
		stackMax = 1;
	};
	class Slot_ButaneTorchCanister
	{
		name = "ButaneTorchCanister";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:gascanister";
	};
	class Slot_CableReel
	{
		name = "CableReel";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:cablereel";
	};
	class Slot_CamoNet
	{
		name = "CamoNet";
		displayName = "$STR_CfgCamoNet0";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_CookingBase
	{
		name = "CookingBase";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:cookingbase";
	};
	class Slot_CookingEquipment
	{
		name = "CookingEquipment";
		displayName = "$STR_CfgCookingEquipment0";
		ghostIcon = "set:dayz_inventory image:cookingequipment";
	};
	class Slot_CookingTripod
	{
		name = "CookingTripod";
		displayName = "$STR_CfgCookingTripod0";
		ghostIcon = "set:dayz_inventory image:cookingtripod";
	};
	class Slot_DBHelmetMouth
	{
		name = "DBHelmetMouth";
		displayName = "$STR_CfgDBHelmetMouth0";
		ghostIcon = "set:dayz_inventory image:dbhelmetmouth";
	};
	class Slot_DBHelmetVisor
	{
		name = "DBHelmetVisor";
		displayName = "$STR_CfgDBHelmetVisor0";
		ghostIcon = "set:dayz_inventory image:dbhelmetvisor";
	};
	class Slot_Firewood
	{
		name = "Firewood";
		displayName = "$STR_CfgFirewood0";
		ghostIcon = "set:dayz_inventory image:firewood";
		stackMax = 6;
	};
	class Slot_GasCanister
	{
		name = "GasCanister";
		displayName = "$STR_CfgGasCanister0";
		ghostIcon = "set:dayz_inventory image:gascanister";
	};
	class Slot_Glass
	{
		name = "Glass";
		displayName = "$STR_CfgGlass0";
		ghostIcon = "set:dayz_inventory image:gorkavisor";
	};
	class Slot_Hook
	{
		name = "Hook";
		displayName = "$STR_CfgHook0";
		ghostIcon = "set:dayz_inventory image:hook";
	};
	class Slot_Ingredient
	{
		name = "Ingredient";
		displayName = "$STR_CfgFood0";
		ghostIcon = "set:dayz_inventory image:food";
	};
	class Slot_Lights
	{
		name = "Lights";
		displayName = "$STR_CfgXmasLights0";
		ghostIcon = "set:dayz_inventory image:cat_christmaslights";
	};
	class Slot_MedicalBandage
	{
		name = "MedicalBandage";
		displayName = "$STR_CfgMedicalBandage0";
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
	class Slot_Paper
	{
		name = "Paper";
		displayName = "$STR_CfgPaper0";
		ghostIcon = "set:dayz_inventory image:paper";
	};
	class Slot_Rags
	{
		name = "Rags";
		displayName = "$STR_CfgRags0";
		ghostIcon = "set:dayz_inventory image:rags";
		stackMax = 6;
	};
	class Slot_Stones
	{
		name = "Stones";
		displayName = "$STR_CfgStones0";
		ghostIcon = "set:dayz_inventory image:stones";
		stackMax = 16;
	};
	class Slot_WoodenStick
	{
		name = "WoodenStick";
		displayName = "$STR_CfgWoodenStick0";
		ghostIcon = "set:dayz_inventory image:woodenstick";
		stackMax = 10;
	};
	class Slot_bait
	{
		name = "Bait";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:hook";
	};
	class Slot_matchinside
	{
		name = "matchinside";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:matchinside";
	};
	class Slot_BerryB
	{
		name = "BerryB";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:berry";
	};
	class Slot_BerryR
	{
		name = "BerryR";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:berry";
	};
	class Slot_BirchBark
	{
		name = "BirchBark";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:bark";
		stackMax = 8;
	};
	class Slot_OakBark
	{
		name = "OakBark";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:bark";
		stackMax = 8;
	};
	class Slot_Plant
	{
		name = "Plant";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:plant";
	};
	class Slot_Disinfectant
	{
		name = "Disinfectant";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:disinfectant";
	};
	class Slot_Guts
	{
		name = "Guts";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:guts";
	};
	class Slot_Lime
	{
		name = "Lime";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:lime";
	};
	class Slot_Bark
	{
		name = "Bark";
		displayName = "$STR_CfgBark0";
		ghostIcon = "set:dayz_inventory image:bark";
		stackMax = 8;
	};
	class Slot_DirectCookingA
	{
		name = "DirectCookingA";
		displayName = "$STR_CfgDirectCooking0";
		ghostIcon = "set:dayz_inventory image:directcooking";
	};
	class Slot_DirectCookingB
	{
		name = "DirectCookingB";
		displayName = "$STR_CfgDirectCooking0";
		ghostIcon = "set:dayz_inventory image:directcooking";
	};
	class Slot_DirectCookingC
	{
		name = "DirectCookingC";
		displayName = "$STR_CfgDirectCooking0";
		ghostIcon = "set:dayz_inventory image:directcooking";
	};
	class Slot_SmokingA
	{
		name = "SmokingA";
		displayName = "$STR_CfgSmoking0";
		ghostIcon = "set:dayz_inventory image:smoking";
	};
	class Slot_SmokingB
	{
		name = "SmokingB";
		displayName = "$STR_CfgSmoking0";
		ghostIcon = "set:dayz_inventory image:smoking";
	};
	class Slot_SmokingC
	{
		name = "SmokingC";
		displayName = "$STR_CfgSmoking0";
		ghostIcon = "set:dayz_inventory image:smoking";
	};
	class Slot_SmokingD
	{
		name = "SmokingD";
		displayName = "$STR_CfgSmoking0";
		ghostIcon = "set:dayz_inventory image:smoking";
	};
	class Slot_SeedBase_1
	{
		name = "SeedBase_1";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_1";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_2
	{
		name = "SeedBase_2";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_2";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_3
	{
		name = "SeedBase_3";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_3";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_4
	{
		name = "SeedBase_4";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_4";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_5
	{
		name = "SeedBase_5";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_5";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_6
	{
		name = "SeedBase_6";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_6";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_7
	{
		name = "SeedBase_7";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_7";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_8
	{
		name = "SeedBase_8";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_8";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_9
	{
		name = "SeedBase_9";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_9";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_10
	{
		name = "SeedBase_10";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_10";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_11
	{
		name = "SeedBase_11";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_11";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_12
	{
		name = "SeedBase_12";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_12";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_SeedBase_13
	{
		name = "SeedBase_13";
		displayName = "$STR_CfgSeedBase0";
		selection = "SeedBase_13";
		ghostIcon = "set:dayz_inventory image:seedbase";
		stackMax = 1;
	};
	class Slot_GlowPlug
	{
		name = "GlowPlug";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:glowplug";
	};
	class Slot_SparkPlug
	{
		name = "SparkPlug";
		displayName = "$STR_CfgSparkPlug0";
		ghostIcon = "set:dayz_inventory image:sparkplug";
	};
	class Slot_EngineBelt
	{
		name = "EngineBelt";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:enginebelt";
	};
	class Slot_CarBattery
	{
		name = "CarBattery";
		displayName = "$STR_CfgVehicleBattery0";
		selection = "battery";
		ghostIcon = "set:dayz_inventory image:carbattery";
	};
	class Slot_TruckBattery
	{
		name = "TruckBattery";
		displayName = "$STR_CfgVehicleBattery0";
		selection = "battery";
		ghostIcon = "set:dayz_inventory image:carbattery";
	};
	class Slot_LightBulb
	{
		name = "LightBulb";
		displayName = "$STR_CfgLightBulb0";
		ghostIcon = "set:dayz_inventory image:lightbulb";
	};
	class Slot_Reflector_1_1
	{
		name = "Reflector_1_1";
		displayName = "$STR_CfgLightBulb0";
		selection = "Reflector_1_1";
		ghostIcon = "set:dayz_inventory image:lightbulb";
	};
	class Slot_Reflector_2_1
	{
		name = "Reflector_2_1";
		displayName = "$STR_CfgLightBulb0";
		selection = "Reflector_2_1";
		ghostIcon = "set:dayz_inventory image:lightbulb";
	};
	class Slot_TruckRadiator
	{
		name = "TruckRadiator";
		displayName = "$STR_CfgVehicleRadiator0";
		ghostIcon = "set:dayz_inventory image:radiator";
	};
	class Slot_CarRadiator
	{
		name = "CarRadiator";
		displayName = "$STR_CfgVehicleRadiator0";
		ghostIcon = "set:dayz_inventory image:radiator";
	};
	class Slot_V3SWheel_1_1
	{
		name = "V3SWheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_V3SWheel_1_2
	{
		name = "V3SWheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_V3SWheel_1_3
	{
		name = "V3SWheel_1_3";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_3";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_V3SWheel_2_1
	{
		name = "V3SWheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_V3SWheel_2_2
	{
		name = "V3SWheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_V3SWheel_2_3
	{
		name = "V3SWheel_2_3";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_3";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_V3SWheel_Spare_1
	{
		name = "V3SWheel_Spare_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_spare_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_V3SWheel_Spare_2
	{
		name = "V3SWheel_Spare_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_spare_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_V3SHood
	{
		name = "V3SHood";
		displayName = "$STR_CfgHood0";
		ghostIcon = "set:dayz_inventory image:hood";
	};
	class Slot_V3SDriverDoors
	{
		name = "V3SDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_V3SCoDriverDoors
	{
		name = "V3SCoDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_UtilityVehicleWheel_1_1
	{
		name = "UtilityVehicleWheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_UtilityVehicleWheel_1_2
	{
		name = "UtilityVehicleWheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_UtilityVehicleWheel_2_1
	{
		name = "UtilityVehicleWheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_UtilityVehicleWheel_2_2
	{
		name = "UtilityVehicleWheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_UtilityVehicleDriverDoors
	{
		name = "UtilityVehicleDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_UtilityVehicleCoDriverDoors
	{
		name = "UtilityVehicleCoDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_NivaWheel_1_1
	{
		name = "NivaWheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_NivaWheel_1_2
	{
		name = "NivaWheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_NivaWheel_2_1
	{
		name = "NivaWheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_NivaWheel_2_2
	{
		name = "NivaWheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_NivaWheel_Spare_1
	{
		name = "NivaWheel_Spare_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_spare_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_NivaHood
	{
		name = "NivaHood";
		displayName = "$STR_CfgHood0";
		ghostIcon = "set:dayz_inventory image:hood";
	};
	class Slot_NivaTrunk
	{
		name = "NivaTrunk";
		displayName = "$STR_CfgTrunk0";
		ghostIcon = "set:dayz_inventory image:trunk";
	};
	class Slot_NivaDriverDoors
	{
		name = "NivaDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_NivaCoDriverDoors
	{
		name = "NivaCoDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_CivSedanWheel_1_1
	{
		name = "CivSedanWheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivSedanWheel_1_2
	{
		name = "CivSedanWheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivSedanWheel_2_1
	{
		name = "CivSedanWheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivSedanWheel_2_2
	{
		name = "CivSedanWheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivSedanHood
	{
		name = "CivSedanHood";
		displayName = "$STR_CfgHood0";
		ghostIcon = "set:dayz_inventory image:hood";
	};
	class Slot_CivSedanTrunk
	{
		name = "CivSedanTrunk";
		displayName = "$STR_CfgTrunk0";
		ghostIcon = "set:dayz_inventory image:trunk";
	};
	class Slot_CivSedanDriverDoors
	{
		name = "CivSedanDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_CivSedanCoDriverDoors
	{
		name = "CivSedanCoDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_CivSedanCargo1Doors
	{
		name = "CivSedanCargo1Doors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_CivSedanCargo2Doors
	{
		name = "CivSedanCargo2Doors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_CivVanWheel_1_1
	{
		name = "CivVanWheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivVanWheel_1_2
	{
		name = "CivVanWheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivVanWheel_2_1
	{
		name = "CivVanWheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivVanWheel_2_2
	{
		name = "CivVanWheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivVanDriverDoors
	{
		name = "CivVanDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_CivVanCoDriverDoors
	{
		name = "CivVanCoDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_CivVanCargo1Doors
	{
		name = "CivVanCargo1Doors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_CivVanTrunkUp
	{
		name = "CivVanTrunkUp";
		displayName = "$STR_CfgTrunk0";
		ghostIcon = "set:dayz_inventory image:trunk";
	};
	class Slot_CivVanCargoDown
	{
		name = "CivVanTrunkDown";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_Van_01_Wheel_1_1
	{
		name = "Van_01_Wheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Van_01_Wheel_1_2
	{
		name = "Van_01_Wheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Van_01_Wheel_2_1
	{
		name = "Van_01_Wheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Van_01_Wheel_2_2
	{
		name = "Van_01_Wheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Van_01_Door_1_1
	{
		name = "Van_01_Door_1_1";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_Van_01_Door_2_1
	{
		name = "Van_01_Door_2_1";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_Van_01_Door_2_2
	{
		name = "Van_01_Door_2_2";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_Van_01_Trunk_1
	{
		name = "Van_01_Trunk_1";
		displayName = "$STR_CfgTrunk0";
		ghostIcon = "set:dayz_inventory image:trunk";
	};
	class Slot_Van_01_Trunk_2
	{
		name = "Van_01_Trunk_2";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_BusWheel_1_1
	{
		name = "BusWheel_1_1";
		displayName = "";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_BusWheel_1_2
	{
		name = "BusWheel_1_2";
		displayName = "";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_BusWheel_2_1
	{
		name = "BusWheel_2_1";
		displayName = "";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_BusWheel_2_2
	{
		name = "BusWheel_2_2";
		displayName = "";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_BusHood
	{
		name = "BusHood";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:hood";
	};
	class Slot_BusLeftDoors_1
	{
		name = "BusLeftDoors_1";
		displayName = "";
		selection = "BusLeftDoors_1";
		ghostIcon = "set:dayz_inventory image:busdoor";
	};
	class Slot_BusLeftDoors_2
	{
		name = "BusLeftDoors_2";
		displayName = "";
		selection = "BusLeftDoors_2";
		ghostIcon = "set:dayz_inventory image:busdoor";
	};
	class Slot_BusLeftDoors_3
	{
		name = "BusLeftDoors_3";
		displayName = "";
		selection = "BusLeftDoors_3";
		ghostIcon = "set:dayz_inventory image:busdoor";
	};
	class Slot_BusRightDoors_1
	{
		name = "BusRightDoors_1";
		displayName = "";
		selection = "BusRightDoors_1";
		ghostIcon = "set:dayz_inventory image:busdoor";
	};
	class Slot_BusRightDoors_2
	{
		name = "BusRightDoors_2";
		displayName = "";
		selection = "BusRightDoors_2";
		ghostIcon = "set:dayz_inventory image:busdoor";
	};
	class Slot_BusRightDoors_3
	{
		name = "BusRightDoors_3";
		displayName = "";
		selection = "BusRightDoors_3";
		ghostIcon = "set:dayz_inventory image:busdoor";
	};
	class Slot_CivHatchbackWheel_1_1
	{
		name = "CivHatchbackWheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivHatchbackWheel_1_2
	{
		name = "CivHatchbackWheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivHatchbackWheel_2_1
	{
		name = "CivHatchbackWheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivHatchbackWheel_2_2
	{
		name = "CivHatchbackWheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_CivHatchbackHood
	{
		name = "CivHatchbackHood";
		displayName = "$STR_CfgHood0";
		ghostIcon = "set:dayz_inventory image:hood";
	};
	class Slot_CivHatchbackTrunk
	{
		name = "CivHatchbackTrunk";
		displayName = "$STR_CfgTrunk0";
		ghostIcon = "set:dayz_inventory image:trunk";
	};
	class Slot_CivHatchbackDriverDoors
	{
		name = "CivHatchbackDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_CivHatchbackCoDriverDoors
	{
		name = "CivHatchbackCoDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_CivHatchbackCargo1Doors
	{
		name = "CivHatchbackCargo1Doors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_CivHatchbackCargo2Doors
	{
		name = "CivHatchbackCargo2Doors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_S120Wheel_1_1
	{
		name = "S120Wheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_S120Wheel_1_2
	{
		name = "S120Wheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_S120Wheel_2_1
	{
		name = "S120Wheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_S120Wheel_2_2
	{
		name = "S120Wheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_S120Hood
	{
		name = "S120Hood";
		displayName = "$STR_CfgHood0";
		ghostIcon = "set:dayz_inventory image:hood";
	};
	class Slot_S120Trunk
	{
		name = "S120Trunk";
		displayName = "$STR_CfgTrunk0";
		ghostIcon = "set:dayz_inventory image:trunk";
	};
	class Slot_S120DriverDoors
	{
		name = "S120DriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_S120CoDriverDoors
	{
		name = "S120CoDriverDoors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_S120Cargo1Doors
	{
		name = "S120Cargo1Doors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_S120Cargo2Doors
	{
		name = "S120Cargo2Doors";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_Truck_01_Wheel_1_1
	{
		name = "Truck_01_Wheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Truck_01_Wheel_1_2
	{
		name = "Truck_01_Wheel_1_2";
		displayName = "$STR_CfgDoubleWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:doublewheel";
	};
	class Slot_Truck_01_Wheel_1_3
	{
		name = "Truck_01_Wheel_1_3";
		displayName = "$STR_CfgDoubleWheel0";
		selection = "wheel_1_3";
		ghostIcon = "set:dayz_inventory image:doublewheel";
	};
	class Slot_Truck_01_Wheel_2_1
	{
		name = "Truck_01_Wheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Truck_01_Wheel_2_2
	{
		name = "Truck_01_Wheel_2_2";
		displayName = "$STR_CfgDoubleWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:doublewheel";
	};
	class Slot_Truck_01_Wheel_2_3
	{
		name = "Truck_01_Wheel_2_3";
		displayName = "$STR_CfgDoubleWheel0";
		selection = "wheel_2_3";
		ghostIcon = "set:dayz_inventory image:doublewheel";
	};
	class Slot_Truck_01_Wheel_Spare_1
	{
		name = "Truck_01_Wheel_Spare_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_spare_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Truck_01_Wheel_Spare_2
	{
		name = "Truck_01_Wheel_Spare_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_spare_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Truck_01_Hood
	{
		name = "Truck_01_Hood";
		displayName = "$STR_CfgHood0";
		ghostIcon = "set:dayz_inventory image:hood";
	};
	class Slot_Truck_01_Door_1_1
	{
		name = "Truck_01_Door_1_1";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_Truck_01_Doors_2_1
	{
		name = "Truck_01_Door_2_1";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_Truck_01_WoodenLogs
	{
		name = "Truck_01_WoodenLogs";
		displayName = "$STR_CfgWoodenLogs0";
		ghostIcon = "set:dayz_inventory image:woodenlog";
		stackMax = 50;
	};
	class Slot_Truck_01_WoodenPlanks
	{
		name = "Truck_01_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 100;
	};
	class Slot_Truck_01_MetalSheets
	{
		name = "Truck_01_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 40;
	};
	class Slot_Truck_01_Barrel1
	{
		name = "Truck_01_Barrel1";
		displayName = "$STR_CfgBarrel0";
		ghostIcon = "set:dayz_inventory image:barrel";
	};
	class Slot_Truck_01_Barrel2
	{
		name = "Truck_01_Barrel2";
		displayName = "$STR_CfgBarrel0";
		ghostIcon = "set:dayz_inventory image:barrel";
	};
	class Slot_Truck_01_Barrel3
	{
		name = "Truck_01_Barrel3";
		displayName = "$STR_CfgBarrel0";
		ghostIcon = "set:dayz_inventory image:barrel";
	};
	class Slot_Truck_01_Barrel4
	{
		name = "Truck_01_Barrel4";
		displayName = "$STR_CfgBarrel0";
		ghostIcon = "set:dayz_inventory image:barrel";
	};
	class Slot_Truck_01_WoodenCrate1
	{
		name = "Truck_01_WoodenCrate1";
		displayName = "$STR_CfgCrate0";
		ghostIcon = "set:dayz_inventory image:woodcrate";
	};
	class Slot_Truck_01_WoodenCrate2
	{
		name = "Truck_01_WoodenCrate2";
		displayName = "$STR_CfgCrate0";
		ghostIcon = "set:dayz_inventory image:woodcrate";
	};
	class Slot_Truck_01_WoodenCrate3
	{
		name = "Truck_01_WoodenCrate3";
		displayName = "$STR_CfgCrate0";
		ghostIcon = "set:dayz_inventory image:woodcrate";
	};
	class Slot_Truck_01_WoodenCrate4
	{
		name = "Truck_01_WoodenCrate4";
		displayName = "$STR_CfgCrate0";
		ghostIcon = "set:dayz_inventory image:woodcrate";
	};
	class Slot_Truck_02_Wheel_1_1
	{
		name = "Truck_02_Wheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Truck_02_Wheel_1_2
	{
		name = "Truck_02_Wheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Truck_02_Wheel_2_1
	{
		name = "Truck_02_Wheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Truck_02_Wheel_2_2
	{
		name = "Truck_02_Wheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Truck_02_Door_1_1
	{
		name = "Truck_02_Door_1_1";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_Truck_02_Door_2_1
	{
		name = "Truck_02_Door_2_1";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_Hatchback_02_Wheel_1_1
	{
		name = "Hatchback_02_Wheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Hatchback_02_Wheel_1_2
	{
		name = "Hatchback_02_Wheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Hatchback_02_Wheel_2_1
	{
		name = "Hatchback_02_Wheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Hatchback_02_Wheel_2_2
	{
		name = "Hatchback_02_Wheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Hatchback_02_Door_1_1
	{
		name = "Hatchback_02_Door_1_1";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_Hatchback_02_Door_1_2
	{
		name = "Hatchback_02_Door_1_2";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_Hatchback_02_Door_2_1
	{
		name = "Hatchback_02_Door_2_1";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_Hatchback_02_Door_2_2
	{
		name = "Hatchback_02_Door_2_2";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_Hatchback_02_Hood
	{
		name = "Hatchback_02_Hood";
		displayName = "$STR_CfgHood0";
		ghostIcon = "set:dayz_inventory image:hood";
	};
	class Slot_Hatchback_02_Trunk
	{
		name = "Hatchback_02_Trunk";
		displayName = "$STR_CfgTrunk0";
		ghostIcon = "set:dayz_inventory image:trunk";
	};
	class Slot_Sedan_02_Wheel_1_1
	{
		name = "Sedan_02_Wheel_1_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Sedan_02_Wheel_1_2
	{
		name = "Sedan_02_Wheel_1_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_1_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Sedan_02_Wheel_2_1
	{
		name = "Sedan_02_Wheel_2_1";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_1";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Sedan_02_Wheel_2_2
	{
		name = "Sedan_02_Wheel_2_2";
		displayName = "$STR_CfgWheel0";
		selection = "wheel_2_2";
		ghostIcon = "set:dayz_inventory image:wheel";
	};
	class Slot_Sedan_02_Hood
	{
		name = "Sedan_02_Hood";
		displayName = "$STR_CfgHood0";
		ghostIcon = "set:dayz_inventory image:hood";
	};
	class Slot_Sedan_02_Trunk
	{
		name = "Sedan_02_Trunk";
		displayName = "$STR_CfgTrunk0";
		ghostIcon = "set:dayz_inventory image:trunk";
	};
	class Slot_Sedan_02_Door_1_1
	{
		name = "Sedan_02_Door_1_1";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_Sedan_02_Door_2_1
	{
		name = "Sedan_02_Door_2_1";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorfront";
	};
	class Slot_Sedan_02_Door_1_2
	{
		name = "Sedan_02_Door_1_2";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_Sedan_02_Door_2_2
	{
		name = "Sedan_02_Door_2_2";
		displayName = "$STR_CfgDoor0";
		ghostIcon = "set:dayz_inventory image:doorrear";
	};
	class Slot_Level_1_Wall_1_Barbedwire_1
	{
		name = "Level_1_Wall_1_Barbedwire_1";
		displayName = "$STR_CfgBarbedWire0";
		selection = "level_1_wall_1_barbedwire_1";
		ghostIcon = "set:dayz_inventory image:barbedwiredown";
	};
	class Slot_Level_1_Wall_1_Barbedwire_2
	{
		name = "Level_1_Wall_1_Barbedwire_2";
		displayName = "$STR_CfgBarbedWire0";
		selection = "level_1_wall_1_barbedwire_2";
		ghostIcon = "set:dayz_inventory image:barbedwireup";
	};
	class Slot_Level_1_Wall_2_Barbedwire_1
	{
		name = "Level_1_Wall_2_Barbedwire_1";
		displayName = "$STR_CfgBarbedWire0";
		selection = "level_1_wall_2_barbedwire_1";
		ghostIcon = "set:dayz_inventory image:barbedwiredown";
	};
	class Slot_Level_1_Wall_2_Barbedwire_2
	{
		name = "Level_1_Wall_2_Barbedwire_2";
		displayName = "$STR_CfgBarbedWire0";
		selection = "level_1_wall_2_barbedwire_2";
		ghostIcon = "set:dayz_inventory image:barbedwireup";
	};
	class Slot_Level_1_Wall_3_Barbedwire_1
	{
		name = "Level_1_Wall_3_Barbedwire_1";
		displayName = "$STR_CfgBarbedWire0";
		selection = "level_1_wall_3_barbedwire_1";
		ghostIcon = "set:dayz_inventory image:barbedwiredown";
	};
	class Slot_Level_1_Wall_3_Barbedwire_2
	{
		name = "Level_1_Wall_3_Barbedwire_2";
		displayName = "$STR_CfgBarbedWire0";
		selection = "level_1_wall_3_barbedwire_2";
		ghostIcon = "set:dayz_inventory image:barbedwireup";
	};
	class Slot_Level_1_Wall_1_Camonet
	{
		name = "Level_1_Wall_1_Camonet";
		displayName = "$STR_CfgCamoNet0";
		selection = "level_1_wall_1_camonet";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_Level_1_Wall_2_Camonet
	{
		name = "Level_1_Wall_2_Camonet";
		displayName = "$STR_CfgCamoNet0";
		selection = "level_1_wall_2_camonet";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_Level_1_Wall_3_Camonet
	{
		name = "Level_1_Wall_3_Camonet";
		displayName = "$STR_CfgCamoNet0";
		selection = "level_1_wall_3_camonet";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_Level_2_Wall_1_Camonet
	{
		name = "Level_2_Wall_1_Camonet";
		displayName = "$STR_CfgCamoNet0";
		selection = "level_2_wall_1_camonet";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_Level_2_Wall_2_Camonet
	{
		name = "Level_2_Wall_2_Camonet";
		displayName = "$STR_CfgCamoNet0";
		selection = "level_2_wall_2_camonet";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_Level_2_Wall_3_Camonet
	{
		name = "Level_2_Wall_3_Camonet";
		displayName = "$STR_CfgCamoNet0";
		selection = "level_2_wall_3_camonet";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_Level_3_Wall_1_Camonet
	{
		name = "Level_3_Wall_1_Camonet";
		displayName = "$STR_CfgCamoNet0";
		selection = "level_3_wall_1_camonet";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_Level_3_Wall_2_Camonet
	{
		name = "Level_3_Wall_2_Camonet";
		displayName = "$STR_CfgCamoNet0";
		selection = "level_3_wall_2_camonet";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_Level_3_Wall_3_Camonet
	{
		name = "Level_3_Wall_3_Camonet";
		displayName = "$STR_CfgCamoNet0";
		selection = "level_3_wall_3_camonet";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_Material_L1_WoodenLogs
	{
		name = "Material_L1_WoodenLogs";
		displayName = "$STR_CfgWoodenLogs0";
		selection = "Material_L1_WoodenLogs";
		ghostIcon = "set:dayz_inventory image:woodenlog";
		stackMax = 4;
	};
	class Slot_Material_L1_Nails
	{
		name = "Material_L1_Nails";
		displayName = "$STR_CfgNails0";
		selection = "material_l1_nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L1W1_Nails
	{
		name = "Material_L1W1_Nails";
		displayName = "$STR_CfgNails0";
		selection = "material_l1w1_nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L1W2_Nails
	{
		name = "Material_L1W2_Nails";
		displayName = "$STR_CfgNails0";
		selection = "material_l1w2_nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L1W3_Nails
	{
		name = "Material_L1W3_Nails";
		displayName = "$STR_CfgNails0";
		selection = "material_l1w3_nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L1_WoodenPlanks
	{
		name = "Material_L1_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "material_l1_woodenplanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L1W1_WoodenPlanks
	{
		name = "Material_L1W1_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "material_l1w1_woodenplanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L1W2_WoodenPlanks
	{
		name = "Material_L1W2_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "material_l1w2_woodenplanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L1W3_WoodenPlanks
	{
		name = "Material_L1W3_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "material_l1w3_woodenplanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L1W1_MetalSheets
	{
		name = "Material_L1W1_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "material_l1w1_metalsheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_L1W2_MetalSheets
	{
		name = "Material_L1W2_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "material_l1w2_metalsheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_L1W3_MetalSheets
	{
		name = "Material_L1W3_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "material_l1w3_metalsheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_L2_WoodenLogs
	{
		name = "Material_L2_WoodenLogs";
		displayName = "$STR_CfgWoodenLogs0";
		selection = "Material_L2_WoodenLogs";
		ghostIcon = "set:dayz_inventory image:woodenlog";
		stackMax = 4;
	};
	class Slot_Material_L2_Nails
	{
		name = "Material_L2_Nails";
		displayName = "$STR_CfgNails0";
		selection = "material_l2_nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L2W1_Nails
	{
		name = "Material_L2W1_Nails";
		displayName = "$STR_CfgNails0";
		selection = "material_l2w1_nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L2W2_Nails
	{
		name = "Material_L2W2_Nails";
		displayName = "$STR_CfgNails0";
		selection = "material_l2w2_nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L2W3_Nails
	{
		name = "Material_L2W3_Nails";
		displayName = "$STR_CfgNails0";
		selection = "material_l2w3_nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L2_WoodenPlanks
	{
		name = "Material_L2_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "material_l2_woodenplanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L2W1_WoodenPlanks
	{
		name = "Material_L2W1_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "material_l2w1_woodenplanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L2W2_WoodenPlanks
	{
		name = "Material_L2W2_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "material_l2w2_woodenplanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L2W3_WoodenPlanks
	{
		name = "Material_L2W3_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "material_l2w3_woodenplanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L2W1_MetalSheets
	{
		name = "Material_L2W1_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "material_l2w1_metalsheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_L2W2_MetalSheets
	{
		name = "Material_L2W2_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "material_l2w2_metalsheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_L2W3_MetalSheets
	{
		name = "Material_L2W3_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "material_l2w3_metalsheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_L3_WoodenLogs
	{
		name = "Material_L3_WoodenLogs";
		displayName = "$STR_CfgWoodenLogs0";
		selection = "Material_L3_WoodenLogs";
		ghostIcon = "set:dayz_inventory image:woodenlog";
		stackMax = 4;
	};
	class Slot_Material_L3_Nails
	{
		name = "Material_L3_Nails";
		displayName = "$STR_CfgNails0";
		selection = "Material_L3_Nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L3_MetalSheets
	{
		name = "Material_L3_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "Material_L3_MetalSheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_L3W1_Nails
	{
		name = "Material_L3W1_Nails";
		displayName = "$STR_CfgNails0";
		selection = "Material_L3W1_Nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L3W2_Nails
	{
		name = "Material_L3W2_Nails";
		displayName = "$STR_CfgNails0";
		selection = "Material_L3W2_Nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L3W3_Nails
	{
		name = "Material_L3W3_Nails";
		displayName = "$STR_CfgNails0";
		selection = "Material_L3W3_Nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_L3_WoodenPlanks
	{
		name = "Material_L3_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "Material_L3_WoodenPlanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L3W1_WoodenPlanks
	{
		name = "Material_L3W1_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "Material_L3W1_WoodenPlanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L3W2_WoodenPlanks
	{
		name = "Material_L3W2_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "Material_L3W2_WoodenPlanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L3W3_WoodenPlanks
	{
		name = "Material_L3W3_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "Material_L3W3_WoodenPlanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_L3W1_MetalSheets
	{
		name = "Material_L3W1_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "Material_L3W1_MetalSheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_L3W2_MetalSheets
	{
		name = "Material_L3W2_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "Material_L3W2_MetalSheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_L3W3_MetalSheets
	{
		name = "Material_L3W3_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "Material_L3W3_MetalSheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_Nails
	{
		name = "Material_Nails";
		displayName = "$STR_CfgNails0";
		selection = "Material_Nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 99;
	};
	class Slot_Material_WoodenPlanks
	{
		name = "Material_WoodenPlanks";
		displayName = "$STR_CfgPlanks0";
		selection = "Material_WoodenPlanks";
		ghostIcon = "set:dayz_inventory image:planks";
		stackMax = 20;
	};
	class Slot_Material_MetalSheets
	{
		name = "Material_MetalSheets";
		displayName = "$STR_CfgMetalPlate0";
		selection = "Material_MetalSheets";
		ghostIcon = "set:dayz_inventory image:plates";
		stackMax = 20;
	};
	class Slot_Material_WoodenLogs
	{
		name = "Material_WoodenLogs";
		displayName = "$STR_CfgWoodenLogs0";
		selection = "Material_WoodenLogs";
		ghostIcon = "set:dayz_inventory image:woodenlog";
		stackMax = 2;
	};
	class Slot_Material_MetalWire
	{
		name = "Material_MetalWire";
		displayName = "$STR_CfgMetalWire0";
		selection = "Material_MetalWire";
		ghostIcon = "set:dayz_inventory image:metalwire";
	};
	class Slot_Att_CombinationLock
	{
		name = "Att_CombinationLock";
		displayName = "$STR_CombinationLock0";
		selection = "att_combinationlock";
		ghostIcon = "set:dayz_inventory image:combolock";
	};
	class Slot_Wall_Barbedwire_1
	{
		name = "Wall_Barbedwire_1";
		displayName = "$STR_CfgBarbedWire0";
		selection = "wall_barbedwire_1";
		ghostIcon = "set:dayz_inventory image:barbedwiredown";
	};
	class Slot_Wall_Barbedwire_2
	{
		name = "Wall_Barbedwire_2";
		displayName = "$STR_CfgBarbedWire0";
		selection = "wall_barbedwire_2";
		ghostIcon = "set:dayz_inventory image:barbedwireup";
	};
	class Slot_Wall_Camonet
	{
		name = "Wall_Camonet";
		displayName = "$STR_CfgCamoNet0";
		selection = "wall_camonet";
		ghostIcon = "set:dayz_inventory image:camonet";
	};
	class Slot_Material_FPole_WoodenLog
	{
		name = "Material_FPole_WoodenLog";
		displayName = "$STR_CfgWoodenLogs0";
		selection = "Material_FPole_WoodenLog";
		ghostIcon = "set:dayz_inventory image:woodenlog";
		stackMax = 1;
	};
	class Slot_Material_FPole_Stones
	{
		name = "Material_FPole_Stones";
		displayName = "$STR_CfgStones0";
		selection = "Material_FPole_Stones";
		ghostIcon = "set:dayz_inventory image:stones";
		stackMax = 32;
	};
	class Slot_Material_FPole_WoodenLog2
	{
		name = "Material_FPole_WoodenLog2";
		displayName = "$STR_CfgWoodenLogs0";
		selection = "Material_FPole_WoodenLog2";
		ghostIcon = "set:dayz_inventory image:woodenlog";
		stackMax = 6;
	};
	class Slot_Material_FPole_MetalWire
	{
		name = "Material_FPole_MetalWire";
		displayName = "$STR_CfgMetalWire0";
		selection = "Material_FPole_MetalWire";
		ghostIcon = "set:dayz_inventory image:metalwire";
	};
	class Slot_Material_FPole_Rope
	{
		name = "Material_FPole_Rope";
		displayName = "$STR_CfgRope0";
		selection = "Material_FPole_Rope";
		ghostIcon = "set:dayz_inventory image:rope";
	};
	class Slot_Material_FPole_Nails
	{
		name = "Material_FPole_Nails";
		displayName = "$STR_CfgNails0";
		selection = "Material_FPole_Nails";
		ghostIcon = "set:dayz_inventory image:nails";
		stackMax = 60;
	};
	class Slot_Material_FPole_MagicStick
	{
		name = "Material_FPole_MagicStick";
		displayName = "$STR_CfgWoodenLogs0";
		selection = "Material_FPole_MagicStick";
		ghostIcon = "set:dayz_inventory image:woodenlog";
		stackMax = 3;
	};
	class Slot_Material_FPole_Flag
	{
		name = "Material_FPole_Flag";
		displayName = "$STR_Flag0";
		selection = "Material_FPole_Flag";
		ghostIcon = "set:dayz_inventory image:tf_flag";
	};
	class Slot_Material_Shelter_FrameSticks
	{
		name = "Material_Shelter_FrameSticks";
		displayName = "$STR_CfgWoodenStick0";
		selection = "Material_Shelter_FrameSticks";
		ghostIcon = "set:dayz_inventory image:woodenstick";
		stackMax = 4;
	};
	class Slot_Material_Shelter_Rope
	{
		name = "Material_Shelter_Rope";
		displayName = "$STR_CfgRope0";
		selection = "Material_Shelter_Rope";
		ghostIcon = "set:dayz_inventory image:rope";
	};
	class Slot_Material_Shelter_Leather
	{
		name = "Material_Shelter_Leather";
		displayName = "$STR_Leather0";
		selection = "Material_Shelter_Leather";
		ghostIcon = "set:dayz_inventory image:animal_pelt";
		stackMax = 8;
	};
	class Slot_Material_Shelter_Fabric
	{
		name = "Material_Shelter_Fabric";
		displayName = "$STR_Fabric0";
		selection = "Material_Shelter_Fabric";
		ghostIcon = "set:dayz_inventory image:tarp";
		stackMax = 4;
	};
	class Slot_Material_Shelter_Sticks
	{
		name = "Material_Shelter_Sticks";
		displayName = "$STR_CfgWoodenStick0";
		selection = "Material_Shelter_Sticks";
		ghostIcon = "set:dayz_inventory image:wooden_sticks";
		stackMax = 50;
	};
	class Slot_LargeBattery
	{
		name = "LargeBattery";
		displayName = "$STR_CfgVehicleBattery0";
		selection = "battery";
		ghostIcon = "set:dayz_inventory image:carbattery";
	};
	class Slot_Knife_Holster
	{
		name = "KnifeHolster";
		displayName = "";
		ghostIcon = "set:dayz_inventory image:knifeholster";
	};
	class Slot_Chemlight
	{
		name = "Chemlight";
		displayName = "$STR_CfgChemlight0";
		ghostIcon = "set:dayz_inventory image:chemlight";
	};
	class Slot_WalkieTalkie
	{
		name = "WalkieTalkie";
		displayName = "$STR_CfgWalkieTalkie0";
		ghostIcon = "set:dayz_inventory image:walkietalkie";
	};
	class Slot_NVG
	{
		name = "NVG";
		displayName = "$STR_CfgNVG0";
		ghostIcon = "set:dayz_inventory image:nvggoggles";
	};
	class Slot_helmetFlashlight
	{
		name = "helmetFlashlight";
		displayName = "$STR_CfgFlashlight0";
		ghostIcon = "set:dayz_inventory image:weaponflashlight";
	};
	class Slot_Belt_Left
	{
		name = "Belt_Left";
		displayName = "$STR_CfgBelt_Left0";
		ghostIcon = "set:dayz_inventory image:canteen";
	};
	class Slot_Belt_Right
	{
		name = "Belt_Right";
		displayName = "$STR_CfgBelt_Right0";
		ghostIcon = "set:dayz_inventory image:vestholster";
	};
	class Slot_Belt_Back
	{
		name = "Belt_Back";
		displayName = "$STR_CfgBelt_Back0";
		ghostIcon = "set:dayz_inventory image:knifeholster";
	};
	class Slot_VestGrenadeA
	{
		name = "VestGrenadeA";
		displayName = "$STR_CfgVestGrenade0";
		ghostIcon = "set:dayz_inventory image:grenade";
	};
	class Slot_VestGrenadeB
	{
		name = "VestGrenadeB";
		displayName = "$STR_CfgVestGrenade0";
		ghostIcon = "set:dayz_inventory image:grenade";
	};
	class Slot_VestGrenadeC
	{
		name = "VestGrenadeC";
		displayName = "$STR_CfgVestGrenade0";
		ghostIcon = "set:dayz_inventory image:grenade";
	};
	class Slot_VestGrenadeD
	{
		name = "VestGrenadeD";
		displayName = "$STR_CfgVestGrenade0";
		ghostIcon = "set:dayz_inventory image:grenade";
	};
	class Slot_GasMaskFilter
	{
		name = "GasMaskFilter";
		displayName = "";
		ghostIcon = "";
	};
	class Slot_Rope
	{
		name = "Rope";
		displayName = "$STR_CfgRope0";
		ghostIcon = "set:dayz_inventory image:rope";
	};
	class Slot_RevolverCylinder
	{
		name = "RevolverCylinder";
		displayName = "";
		ghostIcon = "";
		show = "false";
	};
	class Slot_RevolverEjector
	{
		name = "RevolverEjector";
		displayName = "";
		ghostIcon = "";
		show = "false";
	};
	class Slot_Splint_Right
	{
		name = "Splint_Right";
		displayName = "";
		ghosticon = "";
		show = "false";
	};
	class Slot_Splint_Left
	{
		name = "Splint_Left";
		displayName = "";
		ghosticon = "";
		show = "false";
	};
};
