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
	class DZ_Characters_Vests
	{
		units[] = {"TacticalVest","UKAssVest"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class PlateCarrierVest: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PlateCarrierBlank0";
		descriptionShort = "$STR_CfgVehicles_PlateCarrierBlank1";
		model = "\DZ\characters\vests\plate_carrier_g.p3d";
		inventorySlot[] = {"Vest"};
		itemInfo[] = {"Clothing","Vest"};
		attachments[] = {"VestHolster","VestPouch","VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD"};
		weight = 12000;
		itemSize[] = {4,4};
		varWetMax = 0.49;
		heatIsolation = 0.8;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\plate_carrier_m.p3d";
			female = "\DZ\characters\vests\plate_carrier_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\BallisticVest.rvmat"}},{0.7,{"DZ\characters\vests\Data\BallisticVest.rvmat"}},{0.5,{"DZ\characters\vests\Data\BallisticVest_damage.rvmat"}},{0.3,{"DZ\characters\vests\Data\BallisticVest_damage.rvmat"}},{0.0,{"DZ\characters\vests\Data\BallisticVest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.2;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.45;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.26;
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SmershVest_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SmershVest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SmershVest: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SmershVest0";
		descriptionShort = "$STR_CfgVehicles_SmershVest1";
		model = "\DZ\characters\vests\smersh_g.p3d";
		attachments[] = {"VestBackpack","VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD"};
		inventorySlot[] = {"Vest"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 220;
		itemSize[] = {3,3};
		itemsCargoSize[] = {6,5};
		quickBarBonus = 3;
		varWetMax = 0.49;
		heatIsolation = 0.1;
		visibilityModifier = 0.7;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\smersh_g_co.paa","\dz\characters\vests\data\smersh_co.paa","\dz\characters\vests\data\smersh_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 110;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\Smersh.rvmat"}},{0.7,{"DZ\characters\vests\Data\Smersh.rvmat"}},{0.5,{"DZ\characters\vests\Data\Smersh_damage.rvmat"}},{0.3,{"DZ\characters\vests\Data\Smersh_damage.rvmat"}},{0.0,{"DZ\characters\vests\Data\Smersh_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class Buttpack
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\smersh_m.p3d";
			female = "\DZ\characters\vests\smersh_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SmershVest_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SmershVest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class PressVest_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_PressVest_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_PressVest_ColorBase1";
		model = "\DZ\characters\vests\pressVest_g.p3d";
		inventorySlot[] = {"Vest"};
		attachments[] = {"VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 7000;
		itemSize[] = {3,2};
		itemsCargoSize[] = {6,4};
		quickBarBonus = 2;
		varWetMax = 0.49;
		heatIsolation = 0.7;
		visibilityModifier = 0.95;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\pressVest_m.p3d";
			female = "\DZ\characters\vests\pressVest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 170;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\PressVest.rvmat"}},{0.7,{"DZ\characters\vests\Data\PressVest.rvmat"}},{0.5,{"DZ\characters\vests\Data\PressVest_damage.rvmat"}},{0.3,{"DZ\characters\vests\Data\PressVest_damage.rvmat"}},{0.0,{"DZ\characters\vests\Data\PressVest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.75;
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
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
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
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
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
	class PressVest_Blue: PressVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\PressVest_Blue_co.paa","\dz\characters\vests\data\PressVest_Blue_co.paa","\dz\characters\vests\data\PressVest_Blue_co.paa"};
	};
	class PressVest_LightBlue: PressVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\PressVest_LightBlue_co.paa","\dz\characters\vests\data\PressVest_LightBlue_co.paa","\dz\characters\vests\data\PressVest_LightBlue_co.paa"};
	};
	class UKAssVest_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_UKAssVest_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_UKAssVest_ColorBase1";
		model = "\DZ\characters\vests\UKAssVest_g.p3d";
		inventorySlot[] = {"Vest"};
		attachments[] = {"VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 1900;
		itemSize[] = {3,3};
		itemsCargoSize[] = {6,5};
		quickBarBonus = 3;
		varWetMax = 0.79;
		heatIsolation = 0.5;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\UKAssVest_m.p3d";
			female = "\DZ\characters\vests\UKAssVest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 120;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\UKAssVest.rvmat","DZ\characters\vests\Data\UKAssVest_ground.rvmat"}},{0.7,{"DZ\characters\vests\Data\UKAssVest.rvmat","DZ\characters\vests\Data\UKAssVest_ground.rvmat"}},{0.5,{"DZ\characters\vests\Data\UKAssVest_damage.rvmat","DZ\characters\vests\Data\UKAssVest_ground_damage.rvmat"}},{0.3,{"DZ\characters\vests\Data\UKAssVest_damage.rvmat","DZ\characters\vests\Data\UKAssVest_ground_damage.rvmat"}},{0.0,{"DZ\characters\vests\Data\UKAssVest_destruct.rvmat","DZ\characters\vests\Data\UKAssVest_ground_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SmershVest_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SmershVest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class UKAssVest_Black: UKAssVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\UKAssVest_ground_black_co.paa","\dz\characters\vests\data\UKAssVest_black_co.paa","\dz\characters\vests\data\UKAssVest_black_co.paa"};
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
	class UKAssVest_Camo: UKAssVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.5;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\UKAssVest_ground_camo_co.paa","\dz\characters\vests\data\UKAssVest_camo_co.paa","\dz\characters\vests\data\UKAssVest_camo_co.paa"};
	};
	class UKAssVest_Khaki: UKAssVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.5;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\UKAssVest_ground_Khaki_co.paa","\dz\characters\vests\data\UKAssVest_Khaki_co.paa","\dz\characters\vests\data\UKAssVest_Khaki_co.paa"};
	};
	class UKAssVest_Olive: UKAssVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\UKAssVest_ground_Olive_co.paa","\dz\characters\vests\data\UKAssVest_Olive_co.paa","\dz\characters\vests\data\UKAssVest_Olive_co.paa"};
	};
	class PoliceVest: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PoliceVest0";
		descriptionShort = "$STR_CfgVehicles_PoliceVest1";
		model = "\DZ\characters\vests\policeVest_g.p3d";
		inventorySlot[] = {"Vest"};
		attachments[] = {"VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 3500;
		itemSize[] = {3,2};
		varWetMax = 0.79;
		heatIsolation = 0.6;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\policevest_co.paa","\dz\characters\vests\data\policevest_co.paa","\dz\characters\vests\data\policevest_co.paa"};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\policeVest_m.p3d";
			female = "\DZ\characters\vests\policeVest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 110;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\PoliceVest.rvmat"}},{0.7,{"DZ\characters\vests\Data\PoliceVest.rvmat"}},{0.5,{"DZ\characters\vests\Data\PoliceVest_damage.rvmat"}},{0.3,{"DZ\characters\vests\Data\PoliceVest_damage.rvmat"}},{0.0,{"DZ\characters\vests\Data\PoliceVest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
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
	class PlateCarrierHolster: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CarrierHolsterSolo0";
		descriptionShort = "$STR_CfgVehicles_CarrierHolsterSolo1";
		model = "\DZ\characters\vests\plate_carrier_holster_g.p3d";
		inventorySlot[] = {"VestHolster","Belt_Right"};
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 110;
		itemSize[] = {2,3};
		attachments[] = {"Pistol"};
		varWetMax = 0.79;
		heatIsolation = 0;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\ballisticvest.rvmat"}},{0.7,{"DZ\characters\vests\data\ballisticvest.rvmat"}},{0.5,{"DZ\characters\vests\data\ballisticvest_damage.rvmat"}},{0.3,{"DZ\characters\vests\data\ballisticvest_damage.rvmat"}},{0.0,{"DZ\characters\vests\data\ballisticvest_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\chest_holster_m.p3d";
			female = "\DZ\characters\vests\chest_holster_f.p3d";
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
	class ChestHolster: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ChestHolster0";
		descriptionShort = "$STR_CfgVehicles_ChestHolster1";
		model = "\DZ\characters\vests\chest_holster_g.p3d";
		inventorySlot[] = {"Vest"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		attachments[] = {"Pistol"};
		weight = 310;
		itemSize[] = {3,2};
		varWetMax = 0.249;
		heatIsolation = 0;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\chest_holster_m.p3d";
			female = "\DZ\characters\vests\chest_holster_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\chest_holster.rvmat"}},{0.7,{"DZ\characters\vests\data\chest_holster.rvmat"}},{0.5,{"DZ\characters\vests\data\chest_holster_damage.rvmat"}},{0.3,{"DZ\characters\vests\data\chest_holster_damage.rvmat"}},{0.0,{"DZ\characters\vests\data\chest_holster_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "SmershVest_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "SmershVest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class HighCapacityVest_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_HighCapacityVest_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_HighCapacityVest_ColorBase1";
		model = "\DZ\characters\vests\tacticalvest2_g.p3d";
		inventorySlot[] = {"Vest"};
		attachments[] = {"VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 2400;
		itemSize[] = {4,3};
		itemsCargoSize[] = {7,5};
		quickBarBonus = 3;
		varWetMax = 0.79;
		heatIsolation = 0.75;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\tacticalvest2_m.p3d";
			female = "\DZ\characters\vests\tacticalvest2_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 120;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\TacticalVest2.rvmat"}},{0.7,{"DZ\characters\vests\Data\TacticalVest2.rvmat"}},{0.5,{"DZ\characters\vests\Data\TacticalVest2_damage.rvmat"}},{0.3,{"DZ\characters\vests\Data\TacticalVest2_damage.rvmat"}},{0.0,{"DZ\characters\vests\Data\TacticalVest2_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.75;
					};
					class Blood
					{
						damage = 0.0;
					};
					class Shock
					{
						damage = 0.75;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
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
	class HighCapacityVest_Black: HighCapacityVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\tacticalvest2_black_co.paa","\dz\characters\vests\data\tacticalvest2_black_co.paa","\dz\characters\vests\data\tacticalvest2_black_co.paa"};
	};
	class HighCapacityVest_Olive: HighCapacityVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = {"\dz\characters\vests\data\tacticalvest2_olive_co.paa","\dz\characters\vests\data\tacticalvest2_olive_co.paa","\dz\characters\vests\data\tacticalvest2_olive_co.paa"};
	};
	class LeatherStorageVest_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_LeatherStorageVest_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_LeatherStorageVest_ColorBase1";
		model = "\DZ\characters\vests\Vest_LeatherStorage_g.p3d";
		inventorySlot[] = {"Vest"};
		attachments[] = {"VestGrenadeA","VestGrenadeC"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 2800;
		itemSize[] = {4,3};
		itemsCargoSize[] = {7,5};
		quickBarBonus = 3;
		varWetMax = 0.49;
		heatIsolation = 1;
		lootCategory = "Crafted";
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.7;
					};
					class Blood
					{
						damage = 0.6;
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
						damage = 0.7;
					};
					class Blood
					{
						damage = 0.6;
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
			male = "\DZ\characters\vests\Vest_LeatherStorage_m.p3d";
			female = "\DZ\characters\vests\Vest_LeatherStorage_f.p3d";
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
	class LeatherStorageVest_Natural: LeatherStorageVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsMaterials[] = {"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\Vest_LeatherStorage_natural_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\Vest_LeatherStorage_natural_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class LeatherStorageVest_Beige: LeatherStorageVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsMaterials[] = {"DZ\characters\vests\data\Vest_LeatherStorage_beige.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_beige.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_beige.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\Vest_LeatherStorage_beige_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\Vest_LeatherStorage_beige_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class LeatherStorageVest_Brown: LeatherStorageVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsMaterials[] = {"DZ\characters\vests\data\Vest_LeatherStorage_brown.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_brown.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_brown.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\Vest_LeatherStorage_brown_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\Vest_LeatherStorage_brown_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class LeatherStorageVest_Black: LeatherStorageVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsMaterials[] = {"DZ\characters\vests\data\Vest_LeatherStorage_black.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_black.rvmat","DZ\characters\vests\data\Vest_LeatherStorage_black.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\characters\vests\data\Vest_LeatherStorage_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\vests\Data\Vest_LeatherStorage_black_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\vests\Data\Vest_LeatherStorage_black_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class HuntingVest: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HuntingVest0";
		descriptionShort = "$STR_CfgVehicles_HuntingVest1";
		model = "\DZ\characters\vests\hunter_vest_g.p3d";
		inventorySlot[] = {"Vest"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 350;
		itemSize[] = {3,2};
		itemsCargoSize[] = {6,4};
		varWetMax = 0.79;
		heatIsolation = 0.35;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\hunter_vest_m.p3d";
			female = "\DZ\characters\vests\hunter_vest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 130;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\Hunting_vest.rvmat"}},{0.7,{"DZ\characters\vests\Data\Hunting_vest.rvmat"}},{0.5,{"DZ\characters\vests\Data\Hunting_vest_damage.rvmat"}},{0.3,{"DZ\characters\vests\Data\Hunting_vest_damage.rvmat"}},{0.0,{"DZ\characters\vests\Data\Hunting_vest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.9;
					};
					class Blood
					{
						damage = 0.9;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.9;
					};
					class Blood
					{
						damage = 0.9;
					};
					class Shock
					{
						damage = 0.9;
					};
				};
			};
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
	class ReflexVest: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ReflexVest0";
		descriptionShort = "$STR_CfgVehicles_ReflexVest1";
		model = "\DZ\characters\vests\orange_vest_g.p3d";
		inventorySlot[] = {"Vest"};
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Vest"};
		weight = 200;
		itemSize[] = {3,2};
		varWetMax = 0.249;
		heatIsolation = 0.2;
		repairableWithKits[] = {5};
		repairCosts[] = {25.0};
		class ClothingTypes
		{
			male = "\DZ\characters\vests\orange_vest_m.p3d";
			female = "\DZ\characters\vests\orange_vest_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\vests\Data\orange_vest.rvmat"}},{0.7,{"DZ\characters\vests\Data\orange_vest.rvmat"}},{0.5,{"DZ\characters\vests\Data\orange_vest_damage.rvmat"}},{0.3,{"DZ\characters\vests\Data\orange_vest_damage.rvmat"}},{0.0,{"DZ\characters\vests\Data\orange_vest_destruct.rvmat"}}};
				};
			};
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
	class Proxyberetta: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"Pistol"};
		model = "DZ\characters\proxies\beretta.p3d";
	};
	class Proxyplate_carrier_pouches_g: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"VestPouch"};
		model = "DZ\characters\vests\plate_carrier_pouches_g.p3d";
	};
	class Proxyplate_carrier_holster_g: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"VestHolster"};
		model = "DZ\characters\vests\plate_carrier_holster_g.p3d";
	};
	class Proxysmersh_buttpack: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"VestBackpack"};
		model = "\DZ\characters\vests\proxy\smersh_buttpack.p3d";
	};
	class Proxyproxy_grenade_a: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"VestGrenadeA"};
		model = "\DZ\characters\vests\proxy\proxy_grenade_a.p3d";
	};
	class Proxyproxy_grenade_b: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"VestGrenadeB"};
		model = "\DZ\characters\vests\proxy\proxy_grenade_b.p3d";
	};
	class Proxyproxy_grenade_c: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"VestGrenadeC"};
		model = "\DZ\characters\vests\proxy\proxy_grenade_c.p3d";
	};
	class Proxyproxy_grenade_d: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"VestGrenadeD"};
		model = "\DZ\characters\vests\proxy\proxy_grenade_d.p3d";
	};
};
