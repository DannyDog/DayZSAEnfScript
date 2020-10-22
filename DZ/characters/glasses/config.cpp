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
	class DZ_Characters_Glasses
	{
		units[] = {"SunGlasses"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Gear_Optics"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class ItemOptics;
	class Clothing: Clothing_Base{};
	class SportGlasses_ColorBase: Clothing
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_SportGlasses0";
		descriptionShort = "$STR_CfgVehicles_SportGlasses1";
		model = "\DZ\characters\glasses\sport_glasses_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot[] = {"Eyewear"};
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 17;
		itemSize[] = {3,1};
		weight = 20;
		lootCategory = "Eyewear";
		lootTag[] = {"Civilian"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\joeyx.rvmat"}},{0.7,{"DZ\characters\glasses\data\joeyx.rvmat"}},{0.5,{"DZ\characters\glasses\data\joeyx_damage.rvmat"}},{0.3,{"DZ\characters\glasses\data\joeyx_damage.rvmat"}},{0.0,{"DZ\characters\glasses\data\joeyx_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\sport_glasses.p3d";
			female = "\DZ\characters\glasses\sport_glasses.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SportGlasses_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SportGlasses_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SportGlasses_Black: SportGlasses_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\glasses\data\joeyx_black_ca.paa","\dz\characters\glasses\data\joeyx_black_ca.paa","\dz\characters\glasses\data\joeyx_black_ca.paa"};
	};
	class SportGlasses_Blue: SportGlasses_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\glasses\data\joeyx_blue_ca.paa","\dz\characters\glasses\data\joeyx_blue_ca.paa","\dz\characters\glasses\data\joeyx_blue_ca.paa"};
	};
	class SportGlasses_Green: SportGlasses_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\glasses\data\joeyx_green_ca.paa","\dz\characters\glasses\data\joeyx_green_ca.paa","\dz\characters\glasses\data\joeyx_green_ca.paa"};
	};
	class SportGlasses_Orange: SportGlasses_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\glasses\data\joeyx_yellowred_ca.paa","\dz\characters\glasses\data\joeyx_yellowred_ca.paa","\dz\characters\glasses\data\joeyx_yellowred_ca.paa"};
	};
	class AviatorGlasses: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AviatorGlasses0";
		descriptionShort = "$STR_CfgVehicles_AviatorGlasses1";
		model = "\DZ\characters\glasses\aviator_glasses_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot[] = {"Eyewear"};
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 17;
		weight = 36;
		itemSize[] = {2,1};
		lootTag[] = {"Military_west","Military_east","Civilian"};
		lootCategory = "Eyewear";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\goggles2_metal.rvmat"}},{0.7,{"DZ\characters\glasses\data\goggles2_metal.rvmat"}},{0.5,{"DZ\characters\glasses\data\goggles2_metal_damage.rvmat"}},{0.3,{"DZ\characters\glasses\data\goggles2_metal_damage.rvmat"}},{0.0,{"DZ\characters\glasses\data\goggles2_metal_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\aviator_glasses.p3d";
			female = "\DZ\characters\glasses\aviator_glasses.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SportGlasses_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SportGlasses_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class DesignerGlasses: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_DesignerGlasses0";
		descriptionShort = "$STR_CfgVehicles_DesignerGlasses1";
		model = "\DZ\characters\glasses\sunglasses_designer_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot[] = {"Eyewear"};
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 17;
		weight = 40;
		itemSize[] = {2,1};
		lootTag[] = {"Civilian"};
		lootCategory = "Eyewear";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\sunglass_designer.rvmat"}},{0.7,{"DZ\characters\glasses\data\sunglass_designer.rvmat"}},{0.5,{"DZ\characters\glasses\data\sunglass_designer_damage.rvmat"}},{0.3,{"DZ\characters\glasses\data\sunglass_designer_damage.rvmat"}},{0.0,{"DZ\characters\glasses\data\sunglass_designer_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\sunglasses_designer.p3d";
			female = "\DZ\characters\glasses\sunglasses_designer.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SportGlasses_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SportGlasses_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class ThickFramesGlasses: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ThickFramesGlasses0";
		descriptionShort = "$STR_CfgVehicles_ThickFramesGlasses1";
		model = "\DZ\characters\glasses\glasses_thick_frame_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot[] = {"Eyewear"};
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 17;
		weight = 50;
		itemSize[] = {2,1};
		lootTag[] = {"Civilian"};
		lootCategory = "Eyewear";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\ThickFrameGlasses.rvmat"}},{0.7,{"DZ\characters\glasses\data\ThickFrameGlasses.rvmat"}},{0.5,{"DZ\characters\glasses\data\ThickFrameGlasses_damage.rvmat"}},{0.3,{"DZ\characters\glasses\data\ThickFrameGlasses_damage.rvmat"}},{0.0,{"DZ\characters\glasses\data\ThickFrameGlasses_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\glasses_thick_frame.p3d";
			female = "\DZ\characters\glasses\glasses_thick_frame.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SportGlasses_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SportGlasses_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class ThinFramesGlasses: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ThinFramesGlasses0";
		descriptionShort = "$STR_CfgVehicles_ThinFramesGlasses1";
		model = "\DZ\characters\glasses\glasses_thin_frame_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot[] = {"Eyewear"};
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 17;
		weight = 30;
		itemSize[] = {2,1};
		lootTag[] = {"Civilian"};
		lootCategory = "Eyewear";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\ThinFrameGlasses.rvmat"}},{0.7,{"DZ\characters\glasses\data\ThinFrameGlasses.rvmat"}},{0.5,{"DZ\characters\glasses\data\ThinFrameGlasses_damage.rvmat"}},{0.3,{"DZ\characters\glasses\data\ThinFrameGlasses_damage.rvmat"}},{0.0,{"DZ\characters\glasses\data\ThinFrameGlasses_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\glasses_thin_frame.p3d";
			female = "\DZ\characters\glasses\glasses_thin_frame.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SportGlasses_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SportGlasses_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class TacticalGoggles: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TacticalGoggles0";
		descriptionShort = "$STR_CfgVehicles_TacticalGoggles1";
		model = "\DZ\characters\glasses\TacGoggles_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		inventorySlot[] = {"Eyewear"};
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 1;
		itemSize[] = {2,1};
		weight = 100;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\TacGoggles.rvmat"}},{0.7,{"DZ\characters\glasses\data\TacGoggles.rvmat"}},{0.5,{"DZ\characters\glasses\data\TacGoggles_damage.rvmat"}},{0.3,{"DZ\characters\glasses\data\TacGoggles_damage.rvmat"}},{0.0,{"DZ\characters\glasses\data\TacGoggles_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\TacGoggles.p3d";
			female = "\DZ\characters\glasses\TacGoggles.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SportGlasses_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SportGlasses_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class NVGHeadstrap: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_NVGHeadstrap0";
		descriptionShort = "$STR_CfgVehicles_NVGHeadstrap1";
		model = "\DZ\characters\glasses\NVG_Headstrap_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		attachments[] = {"NVG"};
		inventorySlot[] = {"Eyewear"};
		itemInfo[] = {"Clothing","Eyewear"};
		rotationFlags = 2;
		itemSize[] = {3,3};
		weight = 150;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\NVG_Headstrap.rvmat"}},{0.7,{"DZ\characters\glasses\data\NVG_Headstrap.rvmat"}},{0.5,{"DZ\characters\glasses\data\NVG_Headstrap_damage.rvmat"}},{0.3,{"DZ\characters\glasses\data\NVG_Headstrap_damage.rvmat"}},{0.0,{"DZ\characters\glasses\data\NVG_Headstrap_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\glasses\NVG_Headstrap.p3d";
			female = "\DZ\characters\glasses\NVG_Headstrap.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SportGlasses_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SportGlasses_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class NVGoggles: ItemOptics
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_NVGoggles0";
		descriptionShort = "$STR_CfgVehicles_NVGoggles1";
		model = "\DZ\characters\glasses\NVG.p3d";
		simulation = "itemoptics";
		animClass = "Binoculars";
		inventorySlot[] = {"NVG"};
		itemSize[] = {2,2};
		weight = 300;
		rotationFlags = 1;
		class OpticsInfo
		{
			memoryPointCamera = "eyeScope";
			cameraDir = "cameraDir";
			modelOptics = "-";
			distanceZoomMin = 500;
			distanceZoomMax = 500;
			opticsZoomMin = 0.5236;
			opticsZoomMax = 0.5236;
			opticsZoomInit = 0.5236;
		};
		attachments[] = {"BatteryD"};
		NVOptic = 1;
		simpleHiddenSelections[] = {"hide"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\glasses\data\NVG_Headstrap.rvmat"}},{0.7,{"DZ\characters\glasses\data\NVG_Headstrap.rvmat"}},{0.5,{"DZ\characters\glasses\data\NVG_Headstrap_damage.rvmat"}},{0.3,{"DZ\characters\glasses\data\NVG_Headstrap_damage.rvmat"}},{0.0,{"DZ\characters\glasses\data\NVG_Headstrap_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
		};
		class AnimationSources
		{
			class hide
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class rotate
			{
				source = "user";
				animPeriod = 0.3;
				initPhase = 0;
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyNVG: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"NVG"};
		model = "\DZ\characters\glasses\NVG.p3d";
	};
};
