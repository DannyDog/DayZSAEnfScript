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
	class DZ_Characters_Masks
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class GasMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_GasMask0";
		descriptionShort = "$STR_CfgVehicles_GasMask1";
		model = "\DZ\characters\masks\GasMask_g.p3d";
		inventorySlot[] = {"Mask"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 2;
		weight = 730;
		itemSize[] = {3,4};
		varWetMax = 0.49;
		heatIsolation = 0.6;
		visibilityModifier = 0.9;
		noHelmet = 0;
		noEyewear = 1;
		headSelectionsToHide[] = {"Clipping_Gasmask"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\dz\characters\masks\data\GasMask_co.paa","\dz\characters\masks\data\GasMask_co.paa","\dz\characters\masks\data\GasMask_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 120;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\GasMask.rvmat"}},{0.7,{"DZ\characters\masks\data\GasMask.rvmat"}},{0.5,{"DZ\characters\masks\data\GasMask_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\GasMask_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\GasMask_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\GasMask_m.p3d";
			female = "\DZ\characters\masks\GasMask_f.p3d";
		};
		class Protection
		{
			biological = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class BandanaMask_ColorBase: Clothing
	{
		displayName = "$STR_cfgvehicles_bandana_colorbase0";
		descriptionShort = "$STR_cfgvehicles_bandana_colorbase1";
		model = "\DZ\characters\masks\BandanaFace_g.p3d";
		inventorySlot[] = {"Mask"};
		ChangeInventorySlot[] = {"Mask"};
		itemInfo[] = {"Clothing","Mask"};
		weight = 510;
		itemSize[] = {2,1};
		ragQuantity = 1;
		varWetMax = 1.0;
		heatIsolation = 0.4;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_BandanaFace"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\headgear\data\BandanaF.rvmat"}},{0.7,{"DZ\characters\headgear\data\BandanaF.rvmat"}},{0.5,{"DZ\characters\headgear\data\BandanaF_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\BandanaF_damage.rvmat"}},{0.0,{"DZ\characters\headgear\data\BandanaF_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\BandanaFace_m.p3d";
			female = "\DZ\characters\masks\BandanaFace_f.p3d";
		};
		class Protection
		{
			biological = 0.25;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "none";
		soundVoicePriority = 5;
	};
	class BandanaMask_RedPattern: BandanaMask_ColorBase
	{
		scope = 2;
		color = "redpattern";
		ChangeIntoOnAttach[] = {"BandanaHead_RedPattern",""};
		ChangeIntoOnDetach = "Bandana_Redpattern";
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaF_redpattern_co.paa","DZ\characters\headgear\data\BandanaF_redpattern_co.paa","DZ\characters\headgear\data\BandanaF_redpattern_co.paa"};
	};
	class BandanaMask_BlackPattern: BandanaMask_ColorBase
	{
		scope = 2;
		color = "blackpattern";
		ChangeIntoOnAttach[] = {"BandanaHead_BlackPattern",""};
		ChangeIntoOnDetach = "Bandana_Blackpattern";
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaF_blackpattern_co.paa","DZ\characters\headgear\data\BandanaF_blackpattern_co.paa","DZ\characters\headgear\data\BandanaF_blackpattern_co.paa"};
	};
	class BandanaMask_PolkaPattern: BandanaMask_ColorBase
	{
		scope = 2;
		color = "polkapattern";
		ChangeIntoOnAttach[] = {"BandanaHead_PolkaPattern",""};
		ChangeIntoOnDetach = "Bandana_Polkapattern";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaF_karkulka_co.paa","DZ\characters\headgear\data\BandanaF_karkulka_co.paa","DZ\characters\headgear\data\BandanaF_karkulka_co.paa"};
	};
	class BandanaMask_GreenPattern: BandanaMask_ColorBase
	{
		scope = 2;
		color = "greenpattern";
		ChangeIntoOnAttach[] = {"BandanaHead_Greenpattern",""};
		ChangeIntoOnDetach = "Bandana_Greenpattern";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaFHG_olive_co.paa","DZ\characters\headgear\data\BandanaFHG_olive_co.paa","DZ\characters\headgear\data\BandanaFHG_olive_co.paa"};
	};
	class BandanaMask_CamoPattern: BandanaMask_ColorBase
	{
		scope = 2;
		color = "camopattern";
		ChangeIntoOnAttach[] = {"BandanaHead_CamoPattern",""};
		ChangeIntoOnDetach = "Bandana_Camopattern";
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"DZ\characters\headgear\data\BandanaFHG_TTsKO_co.paa","DZ\characters\headgear\data\BandanaFHG_TTsKO_co.paa","DZ\characters\headgear\data\BandanaFHG_TTsKO_co.paa"};
	};
	class NioshFaceMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_NioshFaceMask0";
		descriptionShort = "$STR_CfgVehicles_NioshFaceMask1";
		model = "\DZ\characters\masks\NioshFaceMask_g.p3d";
		inventorySlot[] = {"Mask"};
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 16;
		weight = 340;
		itemSize[] = {2,2};
		varWetMax = 1.0;
		heatIsolation = 0.2;
		headSelectionsToHide[] = {"Clipping_NioshFaceMask"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\NioshFaceMask_co.paa","\DZ\characters\masks\data\NioshFaceMask_co.paa","\DZ\characters\masks\data\NioshFaceMask_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\NioshFaceMask.rvmat"}},{0.7,{"DZ\characters\masks\data\NioshFaceMask.rvmat"}},{0.5,{"DZ\characters\masks\data\NioshFaceMask_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\NioshFaceMask_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\NioshFaceMask_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\NioshFaceMask_m.p3d";
			female = "\DZ\characters\masks\NioshFaceMask_f.p3d";
		};
		class Protection
		{
			biological = 0.75;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "none";
		soundVoicePriority = 5;
	};
	class BalaclavaMask_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_BalaclavaMask_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_BalaclavaMask_ColorBase1";
		model = "\DZ\characters\masks\Balaclava_g.p3d";
		inventorySlot[] = {"Mask"};
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 1;
		weight = 130;
		itemSize[] = {3,2};
		ragQuantity = 1;
		varWetMax = 1.0;
		heatIsolation = 1;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_Balaclava"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\Balaclava.rvmat"}},{0.7,{"DZ\characters\masks\data\Balaclava.rvmat"}},{0.5,{"DZ\characters\masks\data\Balaclava_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\Balaclava_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\Balaclava_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\Balaclava_m.p3d";
			female = "\DZ\characters\masks\Balaclava_f.p3d";
		};
		class Protection
		{
			biological = 0.25;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BalaclavaMask_Black: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "black";
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_black_co.paa","\DZ\characters\masks\data\Balaclava_black_co.paa","\DZ\characters\masks\data\Balaclava_black_co.paa"};
	};
	class BalaclavaMask_Blackskull: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "blackskull";
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_blackskull_co.paa","\DZ\characters\masks\data\Balaclava_blackskull_co.paa","\DZ\characters\masks\data\Balaclava_blackskull_co.paa"};
	};
	class BalaclavaMask_Beige: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "beige";
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_beige_co.paa","\DZ\characters\masks\data\Balaclava_beige_co.paa","\DZ\characters\masks\data\Balaclava_beige_co.paa"};
	};
	class BalaclavaMask_Blue: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "blue";
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_blue_co.paa","\DZ\characters\masks\data\Balaclava_blue_co.paa","\DZ\characters\masks\data\Balaclava_blue_co.paa"};
	};
	class BalaclavaMask_Green: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "green";
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_green_co.paa","\DZ\characters\masks\data\Balaclava_green_co.paa","\DZ\characters\masks\data\Balaclava_green_co.paa"};
	};
	class BalaclavaMask_Pink: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "pink";
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_pink_co.paa","\DZ\characters\masks\data\Balaclava_pink_co.paa","\DZ\characters\masks\data\Balaclava_pink_co.paa"};
	};
	class BalaclavaMask_White: BalaclavaMask_ColorBase
	{
		scope = 2;
		color = "white";
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Balaclava_white_co.paa","\DZ\characters\masks\data\Balaclava_white_co.paa","\DZ\characters\masks\data\Balaclava_white_co.paa"};
	};
	class GP5GasMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_GP5GasMask0";
		descriptionShort = "$STR_CfgVehicles_GP5GasMask1";
		model = "\DZ\characters\masks\GP5GasMask_g.p3d";
		inventorySlot[] = {"Mask"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 1;
		weight = 1090;
		itemSize[] = {3,3};
		varWetMax = 0.249;
		heatIsolation = 0.7;
		visibilityModifier = 0.95;
		noHelmet = 0;
		noEyewear = 1;
		headSelectionsToHide[] = {"Clipping_GP5GasMask"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\dz\characters\masks\data\GP5GasMask_white_co.paa","\dz\characters\masks\data\GP5GasMask_white_co.paa","\dz\characters\masks\data\GP5GasMask_white_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\GP5GasMask.rvmat"}},{0.7,{"DZ\characters\masks\data\GP5GasMask.rvmat"}},{0.5,{"DZ\characters\masks\data\GP5GasMask_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\GP5GasMask_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\GP5GasMask_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\GP5GasMask_m.p3d";
			female = "\DZ\characters\masks\GP5GasMask_f.p3d";
		};
		class Protection
		{
			biological = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class AirborneMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_AirborneMask0";
		descriptionShort = "$STR_CfgVehicles_AirborneMask1";
		model = "\DZ\characters\masks\airborne_mask_g.p3d";
		inventorySlot[] = {"Mask"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 2;
		weight = 700;
		itemSize[] = {3,4};
		varWetMax = 0.249;
		heatIsolation = 0.8;
		visibilityModifier = 0.9;
		noHelmet = 0;
		noEyewear = 1;
		headSelectionsToHide[] = {"Clipping_GP5GasMask"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","camoFilter","camoGlass"};
		hiddenSelectionsTextures[] = {"\dz\characters\masks\data\airborne_mask_co.paa","\dz\characters\masks\data\airborne_mask_co.paa","\dz\characters\masks\data\airborne_mask_co.paa","\dz\characters\masks\data\gp5gasmask_white_co.paa","\dz\characters\masks\data\airborne_mask_glass_ca.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"dz\characters\masks\data\airborne_mask.rvmat","dz\characters\masks\data\airborne_mask_glass.rvmat","dz\characters\masks\data\gp5gasmask.rvmat"}},{0.7,{}},{0.5,{"dz\characters\masks\data\airborne_mask_damage.rvmat","dz\characters\masks\data\airborne_mask_glass.rvmat","dz\characters\masks\data\gp5gasmask_damage.rvmat"}},{0.3,{}},{0.0,{"dz\characters\masks\data\airborne_mask_destruct.rvmat","dz\characters\masks\data\airborne_mask_glass.rvmat","dz\characters\masks\data\gp5gasmask_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\airborne_mask_m.p3d";
			female = "\DZ\characters\masks\airborne_mask_f.p3d";
		};
		class Protection
		{
			biological = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "gasmask";
		soundVoicePriority = 5;
	};
	class GP5GasMask_Filter: Inventory_Base
	{
		scope = 2;
		displayName = "mask filter - PLACEHOLDER";
		descriptionShort = "placeholder description";
		model = "\DZ\characters\masks\GP5GasMask_filter.p3d";
		inventorySlot[] = {"GasMaskFilter"};
		rotationFlags = 2;
		weight = 200;
		itemSize[] = {2,2};
		varWetMax = 0.249;
		heatIsolation = 0;
		visibilityModifier = 0.95;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\characters\masks\data\GP5GasMask_white_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\GP5GasMask.rvmat"}},{0.7,{"DZ\characters\masks\data\GP5GasMask.rvmat"}},{0.5,{"DZ\characters\masks\data\GP5GasMask_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\GP5GasMask_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\GP5GasMask_destruct.rvmat"}}};
				};
			};
		};
	};
	class Balaclava3Holes_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_Balaclava3Holes_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_Balaclava3Holes_ColorBase1";
		model = "\DZ\characters\masks\Balaclava_3holes_g.p3d";
		inventorySlot[] = {"Mask"};
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 17;
		weight = 300;
		itemSize[] = {3,2};
		ragQuantity = 2;
		varWetMax = 1.0;
		heatIsolation = 0.9;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_Balaclava_3holes"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\Balaclava_3holes.rvmat"}},{0.7,{"DZ\characters\masks\data\Balaclava_3holes.rvmat"}},{0.5,{"DZ\characters\masks\data\Balaclava_3holes_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\Balaclava_3holes_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\Balaclava_3holes_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\Balaclava_3holes_m.p3d";
			female = "\DZ\characters\masks\Balaclava_3holes_f.p3d";
		};
		class Protection
		{
			biological = 0.25;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Balaclava3Holes_Beige: Balaclava3Holes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\masks\data\Balaklava_3holes_beige_co.paa","DZ\characters\masks\data\Balaklava_3holes_beige_co.paa","DZ\characters\masks\data\Balaklava_3holes_beige_co.paa"};
	};
	class Balaclava3Holes_Blue: Balaclava3Holes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\masks\data\Balaklava_3holes_blue_co.paa","DZ\characters\masks\data\Balaklava_3holes_blue_co.paa","DZ\characters\masks\data\Balaklava_3holes_blue_co.paa"};
	};
	class Balaclava3Holes_Black: Balaclava3Holes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\masks\data\Balaklava_3holes_co.paa","DZ\characters\masks\data\Balaklava_3holes_co.paa","DZ\characters\masks\data\Balaklava_3holes_co.paa"};
	};
	class Balaclava3Holes_Green: Balaclava3Holes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\masks\data\Balaklava_3holes_green_co.paa","DZ\characters\masks\data\Balaklava_3holes_green_co.paa","DZ\characters\masks\data\Balaklava_3holes_green_co.paa"};
	};
	class SantasBeard: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SantasBeard0";
		descriptionShort = "$STR_CfgVehicles_SantasBeard1";
		model = "\DZ\characters\masks\SantasBeard_g.p3d";
		inventorySlot[] = {"Mask"};
		itemInfo[] = {"Clothing","Mask"};
		weight = 220;
		itemSize[] = {3,1};
		ragQuantity = 1;
		varWetMax = 0.049;
		heatIsolation = 1;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_SantasBeard"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"dz\characters\masks\data\santasbeard_co.paa","dz\characters\masks\data\santasbeard_co.paa","dz\characters\masks\data\santasbeard_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\SantasBeard.rvmat"}},{0.7,{"DZ\characters\masks\data\SantasBeard.rvmat"}},{0.5,{"DZ\characters\masks\data\SantasBeard_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\SantasBeard_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\SantasBeard_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\SantasBeard_m.p3d";
			female = "\DZ\characters\masks\SantasBeard_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "none";
		soundVoicePriority = 5;
	};
	class MouthRag: Clothing
	{
		scope = 2;
		displayName = "$STR_cfgvehicles_rag0";
		descriptionShort = "$STR_cfgvehicles_rag1";
		model = "\DZ\gear\consumables\Rags.p3d";
		inventorySlot[] = {"Mask"};
		ChangeInventorySlot[] = {"Mask"};
		ChangeIntoOnDetach = "Rag";
		itemInfo[] = {"Clothing","Mask"};
		weight = 150;
		itemSize[] = {1,3};
		ragQuantity = 1;
		varWetMax = 1.0;
		heatIsolation = 0;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		headSelectionsToHide[] = {"Clipping_mouth_rags"};
		hiddenSelections[] = {"camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"DZ\characters\masks\data\mouth_rags_CO.paa","DZ\characters\masks\data\mouth_rags_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\mouth_rags.rvmat"}},{0.7,{"DZ\characters\masks\data\mouth_rags.rvmat"}},{0.5,{"DZ\characters\masks\data\mouth_rags_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\mouth_rags_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\mouth_rags_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\mouth_rags.p3d";
			female = "\DZ\characters\masks\mouth_rags.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "gag";
		soundVoicePriority = 15;
	};
	class SurgicalMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SurgicalMask0";
		descriptionShort = "$STR_CfgVehicles_SurgicalMask1";
		model = "\DZ\characters\masks\Surgical_mask_g.p3d";
		inventorySlot[] = {"Mask"};
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 2;
		weight = 340;
		itemSize[] = {3,1};
		varWetMax = 1.0;
		heatIsolation = 0.1;
		headSelectionsToHide[] = {"Clipping_Surgical_mask"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\surgical_mask_ground_co.paa","\DZ\characters\masks\data\surgical_mask_co.paa","\DZ\characters\masks\data\surgical_mask_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\Surgical_mask.rvmat","DZ\characters\masks\data\Surgical_mask_ground.rvmat"}},{0.7,{"DZ\characters\masks\data\Surgical_mask.rvmat","DZ\characters\masks\data\Surgical_mask_ground.rvmat"}},{0.5,{"DZ\characters\masks\data\Surgical_mask_damage.rvmat","DZ\characters\masks\data\Surgical_mask_ground_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\Surgical_mask_damage.rvmat","DZ\characters\masks\data\Surgical_mask_ground_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\Surgical_mask_destruct.rvmat","DZ\characters\masks\data\Surgical_mask_ground_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\Surgical_mask_m.p3d";
			female = "\DZ\characters\masks\Surgical_mask_f.p3d";
		};
		class Protection
		{
			biological = 0.5;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "none";
		soundVoicePriority = 5;
	};
	class HockeyMask: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HockeyMask0";
		descriptionShort = "$STR_CfgVehicles_HockeyMask1";
		model = "\DZ\characters\masks\VintageHockeyMask_g.p3d";
		inventorySlot[] = {"Mask"};
		itemInfo[] = {"Clothing","Mask"};
		weight = 555;
		itemSize[] = {3,2};
		varWetMax = 0.249;
		heatIsolation = 0.05;
		headSelectionsToHide[] = {"Clipping_VintageHockeyMask"};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\Vinitagehockeym_CO.paa","\DZ\characters\masks\data\Vinitagehockeym_CO.paa","\DZ\characters\masks\data\Vinitagehockeym_CO.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 90;
					healthLevels[] = {{1.0,{"DZ\characters\masks\Data\Vintagehockeym.rvmat"}},{0.7,{"DZ\characters\masks\Data\Vintagehockeym.rvmat"}},{0.5,{"DZ\characters\masks\Data\Vintagehockeym_damage.rvmat"}},{0.3,{"DZ\characters\masks\Data\Vintagehockeym_damage.rvmat"}},{0.0,{"DZ\characters\masks\Data\Vintagehockeym_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.85;
					};
					class Blood
					{
						damage = 0.8;
					};
					class Shock
					{
						damage = 0.8;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.85;
					};
					class Blood
					{
						damage = 0.8;
					};
					class Shock
					{
						damage = 0.8;
					};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\VintageHockeyMask_m.p3d";
			female = "\DZ\characters\masks\VintageHockeyMask_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "DarkMotoHelmet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "DarkMotoHelmet_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CrookedNose: Clothing
	{
		scope = 2;
		displayName = "$STR_CrookedNose0";
		descriptionShort = "$STR_CrookedNose1";
		model = "\DZ\characters\masks\CrookedNose_g.p3d";
		inventorySlot[] = {"Mask"};
		itemInfo[] = {"Clothing","Mask"};
		rotationFlags = 16;
		weight = 220;
		itemSize[] = {3,1};
		varWetMax = 0.049;
		heatIsolation = 0.4;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\masks\data\CrookedNose_co.paa","\DZ\characters\masks\data\CrookedNose_co.paa","\DZ\characters\masks\data\CrookedNose_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\characters\masks\data\CrookedNose.rvmat"}},{0.7,{"DZ\characters\masks\data\CrookedNose.rvmat"}},{0.5,{"DZ\characters\masks\data\CrookedNose_damage.rvmat"}},{0.3,{"DZ\characters\masks\data\CrookedNose_damage.rvmat"}},{0.0,{"DZ\characters\masks\data\CrookedNose_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\masks\CrookedNose_m.p3d";
			female = "\DZ\characters\masks\CrookedNose_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxymask_filter: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"GasMaskFilter"};
		model = "DZ\characters\masks\proxy\mask_filter.p3d";
	};
};
