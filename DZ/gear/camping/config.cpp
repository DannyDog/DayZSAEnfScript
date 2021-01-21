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
	class DZ_Gear_Camping
	{
		units[] = {"TentMedium_Packed","TentMedium_Pitched"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class WorldContainer_Base;
	class HouseNoDestruct;
	class Static;
	class BaseBuildingBase: Inventory_Base{};
	class TentBase: Container_Base
	{
		destrType = "DestructTent";
	};
	class MediumTent: TentBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_MediumTent0";
		descriptionShort = "$STR_CfgVehicles_MediumTent1";
		model = "\DZ\gear\camping\MediumTent.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		slopeTolerance = 0.2;
		yawPitchRollLimit[] = {12,12,12};
		hiddenSelections[] = {"bags","camo","xlights_glass_r","xlights_glass_g","xlights_glass_b","xlights_glass_y"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.470588,0.470588,0.470588,1.0,co)","dz\gear\camping\data\tent_pristine_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\tent_medium_packed.rvmat","dz\gear\camping\data\tent_medium_pitched.rvmat"};
		openable = 0;
		carveNavmesh = 1;
		weight = 10000;
		itemSize[] = {8,4};
		itemsCargoSize[] = {10,20};
		itemBehaviour = 2;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		attachments[] = {"CamoNet","Lights"};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = {{1.0,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0.0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.05;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.3;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
				};
			};
			class DamageZones
			{
				class Body
				{
					class Health
					{
						hitpoints = 600;
						transferToGlobalCoef = 0.5;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_medium_packed.rvmat","DZ\gear\camping\data\tent_pristine_co.paa"}},{0.7,{"DZ\gear\camping\data\tent_medium_packed.rvmat","DZ\gear\camping\data\tent_worn_co.paa"}},{0.5,{"DZ\gear\camping\data\tent_medium_packed_damage.rvmat","DZ\gear\camping\data\tent_damage_co.paa"}},{0.3,{"DZ\gear\camping\data\tent_medium_packed_damage.rvmat","DZ\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"DZ\gear\camping\data\tent_medium_packed_destruct.rvmat","DZ\gear\camping\data\tent_destruct_co.paa"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.05;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] = {"body"};
					transferToZonesNames[] = {"Inventory"};
					transferToZonesCoefs[] = {1.0};
					fatalInjuryCoef = -1;
				};
				class Inventory
				{
					class Health
					{
						hitpoints = 600;
						transferToGlobalCoef = 0.5;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_medium_packed.rvmat"}},{0.7,{"DZ\gear\camping\data\tent_medium_packed.rvmat"}},{0.5,{"DZ\gear\camping\data\tent_medium_packed_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\tent_medium_packed_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\tent_medium_packed_destruct.rvmat"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.05;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] = {"inventory"};
					transferToZonesNames[] = {"Body","Entrance"};
					transferToZonesCoefs[] = {1.0,1.0};
					fatalInjuryCoef = -1;
				};
				class Entrance
				{
					class Health
					{
						hitpoints = 600;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_pristine_co.paa"}},{0.7,{"DZ\gear\camping\data\tent_worn_co.paa"}},{0.5,{"DZ\gear\camping\data\tent_damage_co.paa"}},{0.3,{"DZ\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"DZ\gear\camping\data\tent_ruined_ca.paa"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.1;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 1.0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 10;
							};
						};
					};
					componentNames[] = {"entranceo","entrancec"};
					fatalInjuryCoef = -1;
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = {"CamoNet","Lights"};
				icon = "cat_fp_tents";
				view_index = 1;
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CamoNet
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceO
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceC
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Pack
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement_walk
				{
					soundSet = "mediumtent_movement_walk_SoundSet";
					id = 1;
				};
				class movement_run
				{
					soundSet = "mediumtent_movement_run_SoundSet";
					id = 3;
				};
				class movement_sprint
				{
					soundSet = "mediumtent_movement_sprint_SoundSet";
					id = 5;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpTentLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpTent_SoundSet";
					id = 797;
				};
				class mediumtent_drop
				{
					soundset = "mediumtent_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class MediumTent_Green: MediumTent
	{
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.152941,0.176471,0.101961,1.0,co)","dz\gear\camping\data\tent_pristine_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\tent_medium_packed.rvmat","dz\gear\camping\data\tent_medium_pitched_g.rvmat"};
	};
	class MediumTent_Orange: MediumTent
	{
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.152941,0.145098,0.203922,1.0,co)","dz\gear\camping\data\tent_pristine_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\tent_medium_packed.rvmat","dz\gear\camping\data\tent_medium_pitched_o.rvmat"};
	};
	class MediumTentPlacing: MediumTent
	{
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		model = "\DZ\gear\camping\MediumTentPlacing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\tent_medium_pitched_b_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\tent_medium_pitched.rvmat"};
		hologramMaterial = "tent_medium";
		hologramMaterialPath = "dz\gear\camping\data";
	};
	class MediumTent_GreenPlacing: MediumTentPlacing{};
	class MediumTent_OrangePlacing: MediumTentPlacing{};
	class MediumTentClutterCutter: Static
	{
		scope = 1;
		model = "\DZ\gear\camping\MediumTentClutterCutter.p3d";
		displayName = "$STR_CfgVehicles_ClutterCutter6x60";
		icon = "";
		simulation = "thing";
		nameSound = "";
		vehicleClass = "Misc";
		mapSize = 0.7;
		accuracy = 0.2;
		destrType = "DestructNo";
	};
	class LargeTent: TentBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_LargeTent0";
		descriptionShort = "$STR_CfgVehicles_LargeTent1";
		model = "\DZ\gear\camping\LargeTent.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		slopeTolerance = 0.3;
		yawPitchRollLimit[] = {12,12,12};
		hiddenSelections[] = {"entrancec","camo","bags","xlights_glass_r","xlights_glass_g","xlights_glass_b","xlights_glass_y"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\tent_door_co.paa","","dz\gear\camping\data\bagpack_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\tent_door.rvmat","dz\gear\camping\data\large_tent.rvmat","dz\gear\camping\data\bagpack.rvmat"};
		openable = 0;
		carveNavmesh = 1;
		weight = 20000;
		itemSize[] = {10,4};
		itemsCargoSize[] = {10,40};
		itemBehaviour = 0;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		attachments[] = {"CamoNet","Lights"};
		minPlacingDist = 10;
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
					healthLevels[] = {{1.0,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0.0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.05;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.3;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
				};
			};
			class DamageZones
			{
				class Body
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0.5;
						healthLevels[] = {{1.0,{"dz\gear\camping\Data\tent_pristine_co.paa","DZ\gear\camping\data\bagpack.rvmat"}},{0.7,{"dz\gear\camping\data\tent_worn_co.paa","DZ\gear\camping\data\bagpack.rvmat"}},{0.5,{"dz\gear\camping\data\tent_damage_co.paa","DZ\gear\camping\data\bagpack_damage.rvmat"}},{0.3,{"dz\gear\camping\data\tent_destruct_co.paa","DZ\gear\camping\data\bagpack_damage.rvmat"}},{0.0,{"dz\gear\camping\data\tent_destruct_co.paa","DZ\gear\camping\data\bagpack_destruct.rvmat"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.05;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] = {"body"};
					transferToZonesNames[] = {"Inventory"};
					transferToZonesCoefs[] = {1.0};
					fatalInjuryCoef = -1;
				};
				class Inventory
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0.5;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\bagpack.rvmat"}},{0.7,{"DZ\gear\camping\data\bagpack.rvmat"}},{0.5,{"DZ\gear\camping\data\bagpack_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\bagpack_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\bagpack_destruct.rvmat"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.05;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] = {"inventory"};
					transferToZonesNames[] = {"Body","Entrance","Window1","Window2","Window3","Window4","Window5","Window6","Window7"};
					transferToZonesCoefs[] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
					fatalInjuryCoef = -1;
				};
				class Entrance
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_door.rvmat","DZ\gear\camping\data\tent_pristine_co.paa"}},{0.7,{"DZ\gear\camping\data\tent_door.rvmat","DZ\gear\camping\data\tent_worn_co.paa"}},{0.5,{"DZ\gear\camping\data\tent_door_damage.rvmat","DZ\gear\camping\data\tent_damage_co.paa"}},{0.3,{"DZ\gear\camping\data\tent_door_damage.rvmat","DZ\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"DZ\gear\camping\data\tent_door.rvmat","DZ\gear\camping\data\tent_ruined_ca.paa"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1.0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 5.0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 40;
							};
						};
					};
					componentNames[] = {"entranceo","entrancec"};
					fatalInjuryCoef = -1;
				};
				class Window_Base
				{
					class Health
					{
						hitpoints = 2000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_pristine_co.paa"}},{0.7,{"DZ\gear\camping\data\tent_worn_co.paa"}},{0.5,{"DZ\gear\camping\data\tent_damage_co.paa"}},{0.3,{"DZ\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"DZ\gear\camping\data\tent_ruined_ca.paa"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1.0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 5.0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 40;
							};
						};
					};
					componentNames[] = {""};
					fatalInjuryCoef = -1;
				};
				class Window1: Window_Base
				{
					componentNames[] = {"window1o","window1c"};
				};
				class Window2: Window_Base
				{
					componentNames[] = {"window2o","window2c"};
				};
				class Window3: Window_Base
				{
					componentNames[] = {"window3o","window3c"};
				};
				class Window4: Window_Base
				{
					componentNames[] = {"window4o","window4c"};
				};
				class Window5: Window_Base
				{
					componentNames[] = {"window5o","window5c"};
				};
				class Window6: Window_Base
				{
					componentNames[] = {"window6o","window6c"};
				};
				class Window7: Window_Base
				{
					componentNames[] = {"window7o","window7c"};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = {"CamoNet","Lights"};
				icon = "cat_fp_tents";
				view_index = 1;
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CamoNet
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceO
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceC
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window1O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window2O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window3O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window4O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window5O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window6O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window7O
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window1C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window2C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window3C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window4C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window5C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window6C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Window7C
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Pack
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement_walk
				{
					soundSet = "mediumtent_movement_walk_SoundSet";
					id = 1;
				};
				class movement_run
				{
					soundSet = "mediumtent_movement_run_SoundSet";
					id = 3;
				};
				class movement_sprint
				{
					soundSet = "mediumtent_movement_sprint_SoundSet";
					id = 5;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpTentLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpTent_SoundSet";
					id = 797;
				};
				class mediumtent_drop
				{
					soundset = "mediumtent_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class LargeTentPlacing: LargeTent
	{
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		model = "\DZ\gear\camping\LargeTentPlacing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\large_tent_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\large_tent.rvmat"};
		hologramMaterial = "large_tent";
		hologramMaterialPath = "dz\gear\camping\data";
	};
	class LargeTentClutterCutter: Static
	{
		scope = 1;
		model = "\DZ\gear\camping\LargeTentClutterCutter.p3d";
		displayName = "$STR_CfgVehicles_ClutterCutter6x60";
		icon = "";
		simulation = "thing";
		nameSound = "";
		vehicleClass = "Misc";
		mapSize = 0.7;
		accuracy = 0.2;
		destrType = "DestructNo";
	};
	class CarTent: TentBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CarTent0";
		descriptionShort = "$STR_CfgVehicles_CarTent1";
		model = "\DZ\gear\camping\CarTent.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		slopeTolerance = 0.3;
		yawPitchRollLimit[] = {15,15,15};
		hiddenSelections[] = {"bags","camo","xlights_glass_r","xlights_glass_g","xlights_glass_b","xlights_glass_y"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\car_tent_packed_co.paa","dz\gear\camping\data\tent_pristine_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\car_tent_packed.rvmat","dz\gear\camping\data\car_tent.rvmat"};
		openable = 0;
		carveNavmesh = 1;
		weight = 20000;
		itemSize[] = {10,5};
		itemsCargoSize[] = {10,50};
		itemBehaviour = 0;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		attachments[] = {"CamoNet","Lights"};
		minPlacingDist = 10;
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1700;
					healthLevels[] = {{1.0,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0.0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.05;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.3;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
				};
			};
			class DamageZones
			{
				class Body
				{
					class Health
					{
						hitpoints = 1700;
						transferToGlobalCoef = 0.5;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\car_tent_packed.rvmat","DZ\gear\camping\data\tent_pristine_co.paa"}},{0.7,{"DZ\gear\camping\data\car_tent_packed.rvmat","DZ\gear\camping\data\tent_worn_co.paa"}},{0.5,{"DZ\gear\camping\data\car_tent_packed_damage.rvmat","DZ\gear\camping\data\tent_damage_co.paa"}},{0.3,{"DZ\gear\camping\data\car_tent_packed_damage.rvmat","DZ\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"DZ\gear\camping\data\car_tent_packed_destruct.rvmat","DZ\gear\camping\data\tent_destruct_co.paa"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.05;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] = {"body"};
					transferToZonesNames[] = {"Inventory"};
					transferToZonesCoefs[] = {1.0};
					fatalInjuryCoef = -1;
				};
				class Inventory
				{
					class Health
					{
						hitpoints = 1700;
						transferToGlobalCoef = 0.5;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\car_tent_packed.rvmat"}},{0.7,{"DZ\gear\camping\data\car_tent_packed.rvmat"}},{0.5,{"DZ\gear\camping\data\car_tent_packed_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\car_tent_packed_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\car_tent_packed_destruct.rvmat"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.05;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] = {"inventory"};
					transferToZonesNames[] = {"Body","Entrance"};
					transferToZonesCoefs[] = {1.0,1.0};
					fatalInjuryCoef = -1;
				};
				class Entrance
				{
					class Health
					{
						hitpoints = 1700;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_pristine_co.paa"}},{0.7,{"DZ\gear\camping\data\tent_worn_co.paa"}},{0.5,{"DZ\gear\camping\data\tent_damage_co.paa"}},{0.3,{"DZ\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"DZ\gear\camping\data\tent_ruined_ca.paa"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.1;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.5;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 10;
							};
						};
					};
					componentNames[] = {"entranceo","entrancec"};
					fatalInjuryCoef = -1;
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = {"CamoNet","Lights"};
				icon = "cat_fp_tents";
				view_index = 1;
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CamoNet
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceO
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class EntranceC
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Pack
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "cartent_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpTentLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpTent_SoundSet";
					id = 797;
				};
				class mediumtent_drop
				{
					soundset = "mediumtent_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CarTentPlacing: CarTent
	{
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		model = "\DZ\gear\camping\CarTentPlacing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\car_tent_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\car_tent.rvmat"};
		hologramMaterial = "car_tent";
		hologramMaterialPath = "dz\gear\camping\data";
	};
	class PartyTent: TentBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PartyTent0";
		descriptionShort = "$STR_CfgVehicles_PartyTent1";
		model = "\DZ\gear\camping\party_tent.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		slopeTolerance = 0.3;
		yawPitchRollLimit[] = {15,15,15};
		weight = 10000;
		itemSize[] = {9,4};
		itemsCargoSize[] = {10,15};
		minPlacingDist = 10;
		openable = 0;
		carveNavmesh = 1;
		itemBehaviour = 0;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"bags","camo","party_tent_pieces","party_tent_tubes_cables","xlights_glass_r","xlights_glass_g","xlights_glass_b","xlights_glass_y"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.619608,0.603922,0.505882,1.0,co)","dz\gear\camping\data\tent_pristine_co.paa","dz\gear\camping\data\party_tent_pieces_co.paa","dz\gear\camping\data\party_tent_tubes_cables_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\party_tent_bag.rvmat","dz\gear\camping\data\party_tent_cloth.rvmat","dz\gear\camping\data\party_tent_pieces.rvmat","dz\gear\camping\data\party_tent_tubes_cables.rvmat"};
		attachments[] = {"CamoNet","Lights"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1400;
					healthLevels[] = {{1.0,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0.0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.05;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.3;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
				};
			};
			class DamageZones
			{
				class Body
				{
					class Health
					{
						hitpoints = 1400;
						transferToGlobalCoef = 0.5;
						healthLevels[] = {{1.0,{"dz\gear\camping\Data\party_tent_bag.rvmat","dz\gear\camping\Data\tent_pristine_co.paa"}},{0.7,{"dz\gear\camping\Data\party_tent_bag.rvmat","dz\gear\camping\data\tent_worn_co.paa"}},{0.5,{"dz\gear\camping\Data\party_tent_bag_damage.rvmat","dz\gear\camping\data\tent_damage_co.paa"}},{0.3,{"dz\gear\camping\Data\party_tent_bag_damage.rvmat","dz\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"dz\gear\camping\Data\party_tent_bag_destruct.rvmat","dz\gear\camping\data\tent_destruct_co.paa"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.05;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] = {"body"};
					transferToZonesNames[] = {"Inventory"};
					transferToZonesCoefs[] = {1.0};
					fatalInjuryCoef = -1;
				};
				class Inventory
				{
					class Health
					{
						hitpoints = 1400;
						transferToGlobalCoef = 0.5;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\party_tent_bag.rvmat"}},{0.7,{"DZ\gear\camping\data\party_tent_bag.rvmat"}},{0.5,{"DZ\gear\camping\data\party_tent_bag_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\party_tent_bag_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\party_tent_bag_destruct.rvmat"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.05;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] = {"inventory"};
					transferToZonesNames[] = {"Body","Door1","Door2","Door3","Door4","Door5","Door6"};
					transferToZonesCoefs[] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0};
					fatalInjuryCoef = -1;
				};
				class Door_Base
				{
					class Health
					{
						hitpoints = 1400;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_pristine_co.paa"}},{0.7,{"DZ\gear\camping\data\tent_worn_co.paa"}},{0.5,{"DZ\gear\camping\data\tent_damage_co.paa"}},{0.3,{"DZ\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"DZ\gear\camping\data\tent_ruined_ca.paa"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 1.0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.3;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage = 8;
							};
						};
					};
					componentNames[] = {""};
					fatalInjuryCoef = -1;
				};
				class Door1: Door_Base
				{
					componentNames[] = {"door1c","door1o"};
				};
				class Door2: Door_Base
				{
					componentNames[] = {"door2c","door2o"};
				};
				class Door3: Door_Base
				{
					componentNames[] = {"door3c","door3o"};
				};
				class Door4: Door_Base
				{
					componentNames[] = {"door4c","door4o"};
				};
				class Door5: Door_Base
				{
					componentNames[] = {"door5c","door5o"};
				};
				class Door6: Door_Base
				{
					componentNames[] = {"door6c","door6o"};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Attachments
			{
				name = "$STR_attachment_accessories";
				description = "";
				attachmentSlots[] = {"CamoNet","Lights"};
				icon = "cat_fp_tents";
				view_index = 1;
			};
		};
		class AnimationSources
		{
			class Body
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class CamoNet
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door1c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door1o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door2c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door2o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door3c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door3o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door4c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door4o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door5c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door5o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door6c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Door6o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo1c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo1o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo2c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo2o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo3c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo3o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo4c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo4o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo5c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo5o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo6c
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo6o
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Camo_Roof
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Pack
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement_walk
				{
					soundSet = "mediumtent_movement_walk_SoundSet";
					id = 1;
				};
				class movement_run
				{
					soundSet = "mediumtent_movement_run_SoundSet";
					id = 3;
				};
				class movement_sprint
				{
					soundSet = "mediumtent_movement_sprint_SoundSet";
					id = 5;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpTentLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpTent_SoundSet";
					id = 797;
				};
				class mediumtent_drop
				{
					soundset = "mediumtent_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class PartyTent_Blue: PartyTent
	{
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.0862745,0.180392,0.537255,1.0,co)","dz\gear\camping\data\tent_pristine_co.paa","dz\gear\camping\data\party_tent_pieces_co.paa","dz\gear\camping\data\party_tent_tubes_cables_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\party_tent_bag.rvmat","dz\gear\camping\data\party_tent_cloth_blue.rvmat","dz\gear\camping\data\party_tent_pieces.rvmat","dz\gear\camping\data\party_tent_tubes_cables.rvmat"};
	};
	class PartyTent_Brown: PartyTent
	{
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.196078,0,0.0980392,1.0,co)","dz\gear\camping\data\tent_pristine_co.paa","dz\gear\camping\data\party_tent_pieces_co.paa","dz\gear\camping\data\party_tent_tubes_cables_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\party_tent_bag.rvmat","dz\gear\camping\data\party_tent_cloth_brown.rvmat","dz\gear\camping\data\party_tent_pieces.rvmat","dz\gear\camping\data\party_tent_tubes_cables.rvmat"};
	};
	class PartyTent_Lunapark: PartyTent
	{
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.611765,0.584314,0.054902,1.0,co)","dz\gear\camping\data\tent_pristine_co.paa","dz\gear\camping\data\party_tent_pieces_co.paa","dz\gear\camping\data\party_tent_tubes_cables_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\party_tent_bag.rvmat","dz\gear\camping\data\party_tent_cloth_lunapark.rvmat","dz\gear\camping\data\party_tent_pieces.rvmat","dz\gear\camping\data\party_tent_tubes_cables.rvmat"};
	};
	class PartyTentPlacing: PartyTent
	{
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		model = "\DZ\gear\camping\party_tentPlacing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\tent_pristine_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\party_tent_cloth.rvmat"};
		hologramMaterial = "party_tent";
		hologramMaterialPath = "dz\gear\camping\data";
	};
	class PartyTent_BluePlacing: PartyTentPlacing{};
	class PartyTent_BrownPlacing: PartyTentPlacing{};
	class PartyTent_LunaparkPlacing: PartyTentPlacing{};
	class CamoNetShelter: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CamoNetShelter0";
		descriptionShort = "$STR_CfgVehicles_CamoNetShelter1";
		model = "\DZ\gear\camping\camo_net_shelter.p3d";
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		lootCategory = "Crafted";
		weight = 10000;
		itemSize[] = {5,2};
		minPlacingDist = 12;
		carveNavmesh = 1;
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\car_tent.rvmat"}},{0.7,{"DZ\gear\camping\data\car_tent.rvmat"}},{0.5,{"DZ\gear\camping\data\car_tent_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\car_tent_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\car_tent_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
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
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class FenceKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FenceKit0";
		descriptionShort = "$STR_CfgVehicles_FenceKit1";
		model = "\DZ\gear\camping\fence_kit.p3d";
		rotationFlags = 17;
		itemSize[] = {1,5};
		weight = 280;
		itemBehaviour = 1;
		attachments[] = {"Rope"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
				class GlobalArmor
				{
					class Projectile
					{
						class Health
						{
							damage = 0;
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
							damage = 0;
						};
						class Shock
						{
							damage = 0;
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory: AnimSourceHidden{};
			class Placing: AnimSourceHidden{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class crafting_1
				{
					soundSet = "FenceKit_crafting_1_SoundSet";
					id = 1111;
				};
				class crafting_2
				{
					soundSet = "FenceKit_crafting_2_SoundSet";
					id = 1112;
				};
				class crafting_3
				{
					soundSet = "FenceKit_crafting_3_SoundSet";
					id = 1113;
				};
				class crafting_4
				{
					soundSet = "FenceKit_crafting_4_SoundSet";
					id = 1114;
				};
				class crafting_5
				{
					soundSet = "FenceKit_crafting_5_SoundSet";
					id = 1115;
				};
			};
		};
	};
	class FenceKitPlacing: FenceKit
	{
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		scope = 2;
		model = "\DZ\gear\camping\fence_kit_placing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\consumables\data\pile_of_planks_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\fence_pile_of_planks.rvmat"};
		hologramMaterial = "tent_medium";
		hologramMaterialPath = "dz\gear\camping\data";
		alignHologramToTerain = 0;
		slopeTolerance = 0.3;
	};
	class WatchtowerKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_WatchtowerKit0";
		descriptionShort = "$STR_CfgVehicles_WatchtowerKit1";
		model = "\DZ\gear\camping\watchtower_kit.p3d";
		rotationFlags = 17;
		itemSize[] = {1,5};
		weight = 280;
		itemBehaviour = 1;
		attachments[] = {"Rope"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
				class GlobalArmor
				{
					class Projectile
					{
						class Health
						{
							damage = 0;
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
							damage = 0;
						};
						class Shock
						{
							damage = 0;
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory: AnimSourceHidden{};
			class Placing: AnimSourceHidden{};
		};
	};
	class WatchtowerKitPlacing: WatchtowerKit
	{
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		scope = 2;
		model = "\DZ\gear\camping\watchtower_kit_placing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\consumables\data\pile_of_planks_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\fence_pile_of_planks.rvmat"};
		hologramMaterial = "tent_medium";
		hologramMaterialPath = "dz\gear\camping\data";
		alignHologramToTerain = 0;
		slopeTolerance = 0.3;
	};
	class Fence: BaseBuildingBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Fence0";
		descriptionShort = "$STR_CfgVehicles_Fence1";
		model = "\DZ\gear\camping\fence.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		handheld = "false";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 10000;
		itemSize[] = {2,3};
		physLayer = "item_large";
		createProxyPhysicsOnInit = "false";
		createdProxiesOnInit[] = {"Deployed"};
		hybridAttachments[] = {"Material_WoodenLogs","Material_MetalWire","Wall_Barbedwire_1","Wall_Barbedwire_2"};
		mountables[] = {"Wall_Barbedwire_1","Wall_Barbedwire_2"};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0.0,{""}}};
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage = 0;
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
			class DamageZones
			{
				class Body
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_pile_of_planks_destruct.rvmat"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0;
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
						class Melee
						{
							class Health
							{
								damage = 0;
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"body"};
					fatalInjuryCoef = -1;
				};
				class Wall_Base_Down
				{
					class Health
					{
						hitpoints = 12000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_pile_of_planks_worn.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 50;
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
					componentNames[] = {"wall_base_down"};
					fatalInjuryCoef = -1;
				};
				class Wall_Base_Up: Wall_Base_Down
				{
					componentNames[] = {"wall_base_up"};
				};
				class Wall_Wood_Down
				{
					class Health
					{
						hitpoints = 16000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_pile_of_planks_worn.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 50;
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
					componentNames[] = {"wall_wood_down"};
					fatalInjuryCoef = -1;
				};
				class Wall_Wood_Up: Wall_Wood_Down
				{
					componentNames[] = {"wall_wood_up"};
				};
				class Wall_Metal_Down
				{
					class Health
					{
						hitpoints = 21000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_metalsheets.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_metalsheets_worn.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_metalsheets_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_metalsheets_bdamage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_metalsheets_bdamage.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 40;
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
					componentNames[] = {"wall_metal_down"};
					fatalInjuryCoef = -1;
				};
				class Wall_Metal_Up: Wall_Metal_Down
				{
					componentNames[] = {"wall_metal_up"};
				};
				class Wall_Platform
				{
					class Health
					{
						hitpoints = 18000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_pile_of_planks_worn.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 50;
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
					componentNames[] = {"wall_platform"};
					fatalInjuryCoef = -1;
				};
				class Wall_Platform_Stairs_Left: Wall_Platform
				{
					componentNames[] = {"wall_platform_stairs_left"};
				};
				class Wall_Platform_Stairs_Right: Wall_Platform
				{
					componentNames[] = {"wall_platform_stairs_right"};
				};
				class Wall_Barbedwire_1
				{
					class Health
					{
						hitpoints = 300;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\barbed_wire.rvmat"}},{0.7,{"DZ\gear\camping\data\barbed_wire.rvmat"}},{0.5,{"DZ\gear\camping\data\barbed_wire.rvmat"}},{0.3,{"DZ\gear\camping\data\barbed_wire.rvmat"}},{0.0,{"DZ\gear\camping\data\barbed_wire.rvmat"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.01;
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
						class Melee
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
								damage = 40;
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
					componentNames[] = {"wall_barbedwire_1","wall_barbedwire_1_mounted"};
					inventorySlots[] = {"Wall_Barbedwire_1"};
					fatalInjuryCoef = -1;
				};
				class Wall_Barbedwire_2: Wall_Barbedwire_1
				{
					componentNames[] = {"wall_barbedwire_2","wall_barbedwire_2_mounted"};
					inventorySlots[] = {"Wall_Barbedwire_2"};
				};
				class Wall_Gate
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_metalwire.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_metalwire.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_metalwire.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_metalwire.rvmat"}},{0.0,"hidden"}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0;
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
						class Melee
						{
							class Health
							{
								damage = 0;
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"wall_gate"};
					fatalInjuryCoef = -1;
				};
				class Material_WoodenLogs
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 50;
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
					componentNames[] = {"Material_WoodenLogs"};
					inventorySlots[] = {"Material_WoodenLogs"};
					fatalInjuryCoef = -1;
				};
				class Material_MetalWire
				{
					class Health
					{
						hitpoints = 200;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\crafting\data\string_metalwire.rvmat"}},{0.7,{"DZ\gear\crafting\data\string_metalwire.rvmat"}},{0.5,{"DZ\gear\crafting\data\string_metalwire_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\string_metalwire_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\string_metalwire_destruct.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 40;
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
					componentNames[] = {"Material_MetalWire"};
					inventorySlots[] = {"Material_MetalWire"};
					fatalInjuryCoef = -1;
				};
			};
		};
		attachments[] = {"Wall_Barbedwire_1","Wall_Barbedwire_2","Wall_Camonet","Att_CombinationLock","Material_Nails","Material_WoodenPlanks","Material_MetalSheets","Material_WoodenLogs","Material_MetalWire"};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] = {"Material_WoodenLogs"};
				icon = "cat_bb_base";
				selection = "wall";
			};
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] = {"Wall_Camonet","Wall_Barbedwire_1","Wall_Barbedwire_2","Att_CombinationLock"};
				icon = "cat_bb_attachments";
				selection = "wall";
			};
			class Material
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Materials";
				description = "";
				attachmentSlots[] = {"Material_Nails","Material_WoodenPlanks","Material_MetalSheets","Material_MetalWire"};
				icon = "cat_bb_material";
				selection = "wall";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.018;
				initPhase = 0;
			};
			class Wall_Interact_Rotate: AnimRotate{};
			class Wall_Barbedwire_1_Mounted_Rotate: AnimRotate{};
			class Wall_Barbedwire_2_Mounted_Rotate: AnimRotate{};
			class Wall_Camonet_Rotate: AnimRotate{};
			class Wall_Gate_Rotate: AnimRotate{};
			class Wall_Base_Down_Rotate: AnimRotate{};
			class Wall_Base_Up_Rotate: AnimRotate{};
			class Wall_Wood_Down_Rotate: AnimRotate{};
			class Wall_Wood_Up_Rotate: AnimRotate{};
			class Wall_Metal_Down_Rotate: AnimRotate{};
			class Wall_Metal_Up_Rotate: AnimRotate{};
			class Material_WoodenLogs: AnimSourceHidden{};
			class Material_MetalWire: AnimSourceHidden{};
			class Wall_Barbedwire_1: AnimSourceHidden{};
			class Wall_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Wall_Barbedwire_2: AnimSourceHidden{};
			class Wall_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Wall_Camonet: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Base: AnimSourceHidden{};
			class Wall_Platform: AnimSourceHidden{};
			class Wall_Platform_Stairs_Left: AnimSourceHidden{};
			class Wall_Platform_Stairs_Right: AnimSourceHidden{};
			class Wall_Gate: AnimSourceHidden{};
			class Wall_Base_Down: AnimSourceHidden{};
			class Wall_Base_Up: AnimSourceHidden{};
			class Wall_Metal_Down: AnimSourceHidden{};
			class Wall_Metal_Up: AnimSourceHidden{};
			class Wall_Wood_Down: AnimSourceHidden{};
			class Wall_Wood_Up: AnimSourceHidden{};
		};
		class Construction
		{
			class wall
			{
				class base
				{
					name = "$STR_CfgVehicles_Construction_Part_Base";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 4;
					dismantle_action_type = 4;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_WoodenLogs";
							quantity = 2;
							lockable = 1;
						};
					};
				};
				class wall_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					id = 6;
					required_parts[] = {"base"};
					conflicted_parts[] = {};
					collision_data[] = {"wall_down_min","wall_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class wall_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					id = 7;
					required_parts[] = {"wall_base_down"};
					conflicted_parts[] = {"wall_metal_down"};
					collision_data[] = {"wall_down_min","wall_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 10;
						};
					};
				};
				class wall_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					id = 8;
					required_parts[] = {"wall_base_down"};
					conflicted_parts[] = {"wall_wood_down"};
					collision_data[] = {"wall_down_min","wall_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 12;
						};
					};
				};
				class wall_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					id = 9;
					required_parts[] = {"base"};
					conflicted_parts[] = {};
					collision_data[] = {"wall_up_min","wall_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class wall_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					id = 10;
					required_parts[] = {"wall_base_up"};
					conflicted_parts[] = {"wall_metal_up"};
					collision_data[] = {"wall_up_min","wall_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 10;
						};
					};
				};
				class wall_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					id = 11;
					required_parts[] = {"wall_base_up"};
					conflicted_parts[] = {"wall_wood_up"};
					collision_data[] = {"wall_up_min","wall_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 12;
						};
					};
				};
				class wall_platform
				{
					name = "$STR_CfgVehicles_Construction_Part_Platform";
					id = 2;
					required_parts[] = {"base"};
					conflicted_parts[] = {"wall_gate"};
					collision_data[] = {"wall_platform_min","wall_platform_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 3;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 15;
						};
					};
				};
				class wall_platform_stairs_left
				{
					name = "$STR_CfgVehicles_Construction_Part_Platform_Stairs_Right";
					id = 3;
					required_parts[] = {"wall_platform"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 3;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class wall_platform_stairs_right
				{
					name = "$STR_CfgVehicles_Construction_Part_Platform_Stairs_Left";
					id = 4;
					required_parts[] = {"wall_platform"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 3;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_Nails";
							quantity = 8;
						};
					};
				};
				class wall_gate
				{
					name = "$STR_CfgVehicles_Construction_Part_Gate";
					is_gate = 1;
					id = 5;
					required_parts[] = {"base","wall_base_down","wall_base_up"};
					conflicted_parts[] = {"wall_platform"};
					collision_data[] = {};
					build_action_type = 1;
					dismantle_action_type = 1;
					material_type = 5;
					class Materials
					{
						class Material1
						{
							type = "MetalWire";
							slot_name = "Material_MetalWire";
							quantity = -1;
							lockable = 1;
						};
					};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
	};
	class Watchtower: BaseBuildingBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Watchtower0";
		descriptionShort = "$STR_CfgVehicles_Watchtower1";
		model = "\DZ\gear\camping\watchtower.p3d";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 60000;
		itemSize[] = {6,6};
		physLayer = "item_large";
		createProxyPhysicsOnInit = "false";
		createdProxiesOnInit[] = {"Deployed"};
		mountables[] = {"Level_1_Wall_1_Barbedwire_1","Level_1_Wall_1_Barbedwire_2","Level_1_Wall_2_Barbedwire_1","Level_1_Wall_2_Barbedwire_2","Level_1_Wall_3_Barbedwire_1","Level_1_Wall_3_Barbedwire_2"};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0.0,{""}}};
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage = 0;
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
			class DamageZones
			{
				class Body
				{
					class Health
					{
						hitpoints = 100;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_pile_of_planks_destruct.rvmat"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0;
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
						class Melee
						{
							class Health
							{
								damage = 0;
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
					};
					componentNames[] = {"body"};
					fatalInjuryCoef = -1;
				};
				class Material_L1_WoodenLogs
				{
					class Health
					{
						hitpoints = 500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 50;
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
					componentNames[] = {"Material_L1_WoodenLogs"};
					inventorySlots[] = {"Material_L1_WoodenLogs"};
					fatalInjuryCoef = -1;
				};
				class Level_1_Stairs
				{
					class Health
					{
						hitpoints = 7500;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_pile_of_planks_worn.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 50;
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
					componentNames[] = {"level_1_stairs"};
					fatalInjuryCoef = -1;
				};
				class Level_1_Wall_1_Base_Down
				{
					class Health
					{
						hitpoints = 12000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_pile_of_planks_worn.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 50;
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
					componentNames[] = {"level_1_wall_1_base_down"};
					fatalInjuryCoef = -1;
				};
				class Level_1_Wall_1_Base_Up: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_1_wall_1_base_up"};
				};
				class Level_1_Wall_1_Wood_Down
				{
					class Health
					{
						hitpoints = 16000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_pile_of_planks_worn.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 50;
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
					componentNames[] = {"level_1_wall_1_wood_down"};
					fatalInjuryCoef = -1;
				};
				class Level_1_Wall_1_Wood_Up: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_1_wall_1_wood_up"};
				};
				class Level_1_Wall_1_Metal_Down
				{
					class Health
					{
						hitpoints = 21000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_metalsheets.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_metalsheets_worn.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_metalsheets_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_metalsheets_bdamage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_metalsheets_bdamage.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 40;
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
					componentNames[] = {"level_1_wall_1_metal_down"};
					fatalInjuryCoef = -1;
				};
				class Level_1_Wall_1_Metal_Up: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_1_wall_1_metal_up"};
				};
				class Level_1_Wall_1_Barbedwire_1
				{
					class Health
					{
						hitpoints = 300;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\barbed_wire.rvmat","DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\barbed_wire.rvmat","DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.5,{"DZ\gear\camping\data\barbed_wire_damage.rvmat","DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\barbed_wire_damage.rvmat","DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\barbed_wire_destruct.rvmat","DZ\gear\camping\data\fence_pile_of_planks_destruct.rvmat"}}};
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage = 0.01;
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
						class Melee
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
								damage = 40;
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
					componentNames[] = {"level_1_wall_1_barbedwire_1","level_1_wall_1_barbedwire_1_mounted"};
					inventorySlots[] = {"Level_1_Wall_1_Barbedwire_1"};
					fatalInjuryCoef = -1;
				};
				class Level_1_Wall_1_Barbedwire_2: Level_1_Wall_1_Barbedwire_1
				{
					componentNames[] = {"level_1_wall_1_barbedwire_2","level_1_wall_1_barbedwire_2_mounted"};
					inventorySlots[] = {"Level_1_Wall_1_Barbedwire_2"};
				};
				class Level_1_Wall_2_Base_Down: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_1_wall_2_base_down"};
				};
				class Level_1_Wall_2_Base_Up: Level_1_Wall_1_Base_Up
				{
					componentNames[] = {"level_1_wall_2_base_up"};
				};
				class Level_1_Wall_2_Wood_Down: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_1_wall_2_wood_down"};
				};
				class Level_1_Wall_2_Wood_Up: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_1_wall_2_wood_up"};
				};
				class Level_1_Wall_2_Metal_Down: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_1_wall_2_metal_down"};
				};
				class Level_1_Wall_2_Metal_Up: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_1_wall_2_metal_up"};
				};
				class Level_1_Wall_2_Barbedwire_1: Level_1_Wall_1_Barbedwire_1
				{
					componentNames[] = {"level_1_wall_2_barbedwire_1","level_1_wall_2_barbedwire_1_mounted"};
					inventorySlots[] = {"Level_1_Wall_2_Barbedwire_1"};
				};
				class Level_1_Wall_2_Barbedwire_2: Level_1_Wall_1_Barbedwire_1
				{
					componentNames[] = {"level_1_wall_2_barbedwire_2","level_1_wall_2_barbedwire_2_mounted"};
					inventorySlots[] = {"Level_1_Wall_2_Barbedwire_2"};
				};
				class Level_1_Wall_3_Base_Down: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_1_wall_3_base_down"};
				};
				class Level_1_Wall_3_Base_Up: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_1_wall_3_base_up"};
				};
				class Level_1_Wall_3_Wood_Down: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_1_wall_3_wood_down"};
				};
				class Level_1_Wall_3_Wood_Up: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_1_wall_3_wood_up"};
				};
				class Level_1_Wall_3_Metal_Down: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_1_wall_3_metal_down"};
				};
				class Level_1_Wall_3_Metal_Up: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_1_wall_3_metal_up"};
				};
				class Level_1_Wall_3_Barbedwire_1: Level_1_Wall_1_Barbedwire_1
				{
					componentNames[] = {"level_1_wall_3_barbedwire_1","level_1_wall_3_barbedwire_1_mounted"};
					inventorySlots[] = {"Level_1_Wall_3_Barbedwire_1"};
				};
				class Level_1_Wall_3_Barbedwire_2: Level_1_Wall_1_Barbedwire_1
				{
					componentNames[] = {"level_1_wall_3_barbedwire_2","level_1_wall_3_barbedwire_2_mounted"};
					inventorySlots[] = {"Level_1_Wall_3_Barbedwire_2"};
				};
				class Material_L2_WoodenLogs: Material_L1_WoodenLogs
				{
					componentNames[] = {"Material_L2_WoodenLogs"};
					inventorySlots[] = {"Material_L2_WoodenLogs"};
				};
				class Level_2_Stairs: Level_1_Stairs
				{
					componentNames[] = {"level_2_stairs"};
				};
				class Level_2_Wall_1_Base_Down: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_2_wall_1_base_down"};
				};
				class Level_2_Wall_1_Base_Up: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_2_wall_1_base_up"};
				};
				class Level_2_Wall_1_Wood_Down: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_2_wall_1_wood_down"};
				};
				class Level_2_Wall_1_Wood_Up: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_2_wall_1_wood_up"};
				};
				class Level_2_Wall_1_Metal_Down: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_2_wall_1_metal_down"};
				};
				class Level_2_Wall_1_Metal_Up: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_2_wall_1_metal_up"};
				};
				class Level_2_Wall_2_Base_Down: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_2_wall_2_base_down"};
				};
				class Level_2_Wall_2_Base_Up: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_2_wall_2_base_up"};
				};
				class Level_2_Wall_2_Wood_Down: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_2_wall_2_wood_down"};
				};
				class Level_2_Wall_2_Wood_Up: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_2_wall_2_wood_up"};
				};
				class Level_2_Wall_2_Metal_Down: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_2_wall_2_metal_down"};
				};
				class Level_2_Wall_2_Metal_Up: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_2_wall_2_metal_up"};
				};
				class Level_2_Wall_3_Base_Down: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_2_wall_3_base_down"};
				};
				class Level_2_Wall_3_Base_Up: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_2_wall_3_base_up"};
				};
				class Level_2_Wall_3_Wood_Down: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_2_wall_3_wood_down"};
				};
				class Level_2_Wall_3_Wood_Up: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_2_wall_3_wood_up"};
				};
				class Level_2_Wall_3_Metal_Down: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_2_wall_3_metal_down"};
				};
				class Level_2_Wall_3_Metal_Up: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_2_wall_3_metal_up"};
				};
				class Material_L3_WoodenLogs: Material_L1_WoodenLogs
				{
					componentNames[] = {"Material_L3_WoodenLogs"};
					inventorySlots[] = {"Material_L3_WoodenLogs"};
				};
				class Level_3_Wall_1_Base_Down: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_3_wall_1_base_down"};
				};
				class Level_3_Wall_1_Base_Up: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_3_wall_1_base_up"};
				};
				class Level_3_Wall_1_Wood_Down: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_3_wall_1_wood_down"};
				};
				class Level_3_Wall_1_Wood_Up: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_3_wall_1_wood_up"};
				};
				class Level_3_Wall_1_Metal_Down: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_3_wall_1_metal_down"};
				};
				class Level_3_Wall_1_Metal_Up: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_3_wall_1_metal_up"};
				};
				class Level_3_Wall_2_Base_Down: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_3_wall_2_base_down"};
				};
				class Level_3_Wall_2_Base_Up: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_3_wall_2_base_up"};
				};
				class Level_3_Wall_2_Wood_Down: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_3_wall_2_wood_down"};
				};
				class Level_3_Wall_2_Wood_Up: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_3_wall_2_wood_up"};
				};
				class Level_3_Wall_2_Metal_Down: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_3_wall_2_metal_down"};
				};
				class Level_3_Wall_2_Metal_Up: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_3_wall_2_metal_up"};
				};
				class Level_3_Wall_3_Base_Down: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_3_wall_3_base_down"};
				};
				class Level_3_Wall_3_Base_Up: Level_1_Wall_1_Base_Down
				{
					componentNames[] = {"level_3_wall_3_base_up"};
				};
				class Level_3_Wall_3_Wood_Down: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_3_wall_3_wood_down"};
				};
				class Level_3_Wall_3_Wood_Up: Level_1_Wall_1_Wood_Down
				{
					componentNames[] = {"level_3_wall_3_wood_up"};
				};
				class Level_3_Wall_3_Metal_Down: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_3_wall_3_metal_down"};
				};
				class Level_3_Wall_3_Metal_Up: Level_1_Wall_1_Metal_Down
				{
					componentNames[] = {"level_3_wall_3_metal_up"};
				};
				class Level_3_Roof
				{
					class Health
					{
						hitpoints = 19000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1.0,{"DZ\gear\camping\data\fence_metalsheets.rvmat","DZ\gear\camping\data\fence_pile_of_planks.rvmat"}},{0.7,{"DZ\gear\camping\data\fence_metalsheets_worn.rvmat","DZ\gear\camping\data\fence_pile_of_planks_worn.rvmat"}},{0.5,{"DZ\gear\camping\data\fence_metalsheets_damage.rvmat","DZ\gear\camping\data\fence_pile_of_planks_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\fence_metalsheets_bdamage.rvmat","DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}},{0.0,{"DZ\gear\camping\data\fence_metalsheets_bdamage.rvmat","DZ\gear\camping\data\fence_pile_of_planks_bdamage.rvmat"}}};
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
								damage = 0;
							};
							class Shock
							{
								damage = 0;
							};
						};
						class Melee
						{
							class Health
							{
								damage = 0.65;
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
								damage = 40;
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
					componentNames[] = {"level_3_roof"};
					fatalInjuryCoef = -1;
				};
			};
		};
		attachments[] = {"Level_1_Wall_1_Barbedwire_1","Level_1_Wall_1_Barbedwire_2","Level_1_Wall_2_Barbedwire_1","Level_1_Wall_2_Barbedwire_2","Level_1_Wall_3_Barbedwire_1","Level_1_Wall_3_Barbedwire_2","Level_1_Wall_1_Camonet","Level_1_Wall_2_Camonet","Level_1_Wall_3_Camonet","Level_2_Wall_1_Camonet","Level_2_Wall_2_Camonet","Level_2_Wall_3_Camonet","Level_3_Wall_1_Camonet","Level_3_Wall_2_Camonet","Level_3_Wall_3_Camonet","Material_L1_WoodenLogs","Material_L2_WoodenLogs","Material_L3_WoodenLogs","Material_L1_Nails","Material_L1W1_Nails","Material_L1W2_Nails","Material_L1W3_Nails","Material_L2_Nails","Material_L2W1_Nails","Material_L2W2_Nails","Material_L2W3_Nails","Material_L3_Nails","Material_L3W1_Nails","Material_L3W2_Nails","Material_L3W3_Nails","Material_L1_WoodenPlanks","Material_L1W1_WoodenPlanks","Material_L1W2_WoodenPlanks","Material_L1W3_WoodenPlanks","Material_L2_WoodenPlanks","Material_L2W1_WoodenPlanks","Material_L2W2_WoodenPlanks","Material_L2W3_WoodenPlanks","Material_L3_WoodenPlanks","Material_L3W1_WoodenPlanks","Material_L3W2_WoodenPlanks","Material_L3W3_WoodenPlanks","Material_L3_MetalSheets","Material_L1W1_MetalSheets","Material_L1W2_MetalSheets","Material_L1W3_MetalSheets","Material_L2W1_MetalSheets","Material_L2W2_MetalSheets","Material_L2W3_MetalSheets","Material_L3W1_MetalSheets","Material_L3W2_MetalSheets","Material_L3W3_MetalSheets"};
		class GUIInventoryAttachmentsProps
		{
			class Level_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Base";
				description = "";
				attachmentSlots[] = {"Material_L1_WoodenLogs","Material_L1_Nails","Material_L1_WoodenPlanks"};
				icon = "cat_bb_watchtower";
				selection = "level_1";
			};
			class Level_1_Wall_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Wall_1";
				description = "";
				attachmentSlots[] = {"Material_L1W1_Nails","Material_L1W1_WoodenPlanks","Material_L1W1_MetalSheets","Level_1_Wall_1_Camonet","Level_1_Wall_1_Barbedwire_1","Level_1_Wall_1_Barbedwire_2"};
				icon = "cat_bb_watchtower_wall_1";
				selection = "level_1_wall_1";
			};
			class Level_1_Wall_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Wall_2";
				description = "";
				attachmentSlots[] = {"Material_L1W2_Nails","Material_L1W2_WoodenPlanks","Material_L1W2_MetalSheets","Level_1_Wall_2_Camonet","Level_1_Wall_2_Barbedwire_1","Level_1_Wall_2_Barbedwire_2"};
				icon = "cat_bb_watchtower_wall_2";
				selection = "level_1_wall_2";
			};
			class Level_1_Wall_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_1_Wall_3";
				description = "";
				attachmentSlots[] = {"Material_L1W3_Nails","Material_L1W3_WoodenPlanks","Material_L1W3_MetalSheets","Level_1_Wall_3_Camonet","Level_1_Wall_3_Barbedwire_1","Level_1_Wall_3_Barbedwire_2"};
				icon = "cat_bb_watchtower_wall_3";
				selection = "level_1_wall_3";
			};
			class Level_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Base";
				description = "";
				attachmentSlots[] = {"Material_L2_WoodenLogs","Material_L2_Nails","Material_L2_WoodenPlanks"};
				icon = "cat_bb_watchtower";
				selection = "level_2";
			};
			class Level_2_Wall_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Wall_1";
				description = "";
				attachmentSlots[] = {"Material_L2W1_Nails","Material_L2W1_WoodenPlanks","Material_L2W1_MetalSheets","Level_2_Wall_1_Camonet"};
				icon = "cat_bb_watchtower_wall_1";
				selection = "level_2_wall_1";
			};
			class Level_2_Wall_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Wall_2";
				description = "";
				attachmentSlots[] = {"Material_L2W2_Nails","Material_L2W2_WoodenPlanks","Material_L2W2_MetalSheets","Level_2_Wall_2_Camonet"};
				icon = "cat_bb_watchtower_wall_2";
				selection = "level_2_wall_2";
			};
			class Level_2_Wall_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_2_Wall_3";
				description = "";
				attachmentSlots[] = {"Material_L2W3_Nails","Material_L2W3_WoodenPlanks","Material_L2W3_MetalSheets","Level_2_Wall_3_Camonet"};
				icon = "cat_bb_watchtower_wall_3";
				selection = "level_2_wall_3";
			};
			class Level_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Base";
				description = "";
				attachmentSlots[] = {"Material_L3_WoodenLogs","Material_L3_Nails","Material_L3_WoodenPlanks","Material_L3_MetalSheets"};
				icon = "cat_bb_watchtower";
				selection = "level_3";
			};
			class Level_3_Wall_1
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Wall_1";
				description = "";
				attachmentSlots[] = {"Material_L3W1_Nails","Material_L3W1_WoodenPlanks","Material_L3W1_MetalSheets","Level_3_Wall_1_Camonet"};
				icon = "cat_bb_watchtower_wall_1";
				selection = "level_3_wall_1";
			};
			class Level_3_Wall_2
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Wall_2";
				description = "";
				attachmentSlots[] = {"Material_L3W2_Nails","Material_L3W2_WoodenPlanks","Material_L3W2_MetalSheets","Level_3_Wall_2_Camonet"};
				icon = "cat_bb_watchtower_wall_2";
				selection = "level_3_wall_2";
			};
			class Level_3_Wall_3
			{
				name = "$STR_CfgVehicles_Watchtower_Att_Category_Level_3_Wall_3";
				description = "";
				attachmentSlots[] = {"Material_L3W3_Nails","Material_L3W3_WoodenPlanks","Material_L3W3_MetalSheets","Level_3_Wall_3_Camonet"};
				icon = "cat_bb_watchtower_wall_3";
				selection = "level_3_wall_3";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Deployed: AnimSourceHidden{};
			class Level_1_Base: AnimSourceHidden{};
			class Level_1_Stairs: AnimSourceHidden{};
			class Level_1_Roof: AnimSourceHidden{};
			class Material_L1_WoodenLogs: AnimSourceHidden{};
			class Level_1_Wall_1_Barbedwire_1: AnimSourceHidden{};
			class Level_1_Wall_1_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Level_1_Wall_1_Barbedwire_2: AnimSourceHidden{};
			class Level_1_Wall_1_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Level_1_Wall_2_Barbedwire_1: AnimSourceHidden{};
			class Level_1_Wall_2_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Level_1_Wall_2_Barbedwire_2: AnimSourceHidden{};
			class Level_1_Wall_2_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Level_1_Wall_3_Barbedwire_1: AnimSourceHidden{};
			class Level_1_Wall_3_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Level_1_Wall_3_Barbedwire_2: AnimSourceHidden{};
			class Level_1_Wall_3_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Level_1_Wall_1_Camonet: AnimSourceHidden{};
			class Level_1_Wall_2_Camonet: AnimSourceHidden{};
			class Level_1_Wall_3_Camonet: AnimSourceHidden{};
			class Level_1_Wall_1_Base_Down: AnimSourceHidden{};
			class Level_1_Wall_1_Base_Up: AnimSourceHidden{};
			class Level_1_Wall_1_Wood_Down: AnimSourceHidden{};
			class Level_1_Wall_1_Wood_Up: AnimSourceHidden{};
			class Level_1_Wall_1_Metal_Down: AnimSourceHidden{};
			class Level_1_Wall_1_Metal_Up: AnimSourceHidden{};
			class Level_1_Wall_2_Base_Down: AnimSourceHidden{};
			class Level_1_Wall_2_Base_Up: AnimSourceHidden{};
			class Level_1_Wall_2_Wood_Down: AnimSourceHidden{};
			class Level_1_Wall_2_Wood_Up: AnimSourceHidden{};
			class Level_1_Wall_2_Metal_Down: AnimSourceHidden{};
			class Level_1_Wall_2_Metal_Up: AnimSourceHidden{};
			class Level_1_Wall_3_Base_Down: AnimSourceHidden{};
			class Level_1_Wall_3_Base_Up: AnimSourceHidden{};
			class Level_1_Wall_3_Wood_Down: AnimSourceHidden{};
			class Level_1_Wall_3_Wood_Up: AnimSourceHidden{};
			class Level_1_Wall_3_Metal_Down: AnimSourceHidden{};
			class Level_1_Wall_3_Metal_Up: AnimSourceHidden{};
			class Level_2_Base: AnimSourceHidden{};
			class Level_2_Stairs: AnimSourceHidden{};
			class Level_2_Roof: AnimSourceHidden{};
			class Material_L2_WoodenLogs: AnimSourceHidden{};
			class Level_2_Wall_1_Camonet: AnimSourceHidden{};
			class Level_2_Wall_2_Camonet: AnimSourceHidden{};
			class Level_2_Wall_3_Camonet: AnimSourceHidden{};
			class Level_2_Wall_1_Base_Down: AnimSourceHidden{};
			class Level_2_Wall_1_Base_Up: AnimSourceHidden{};
			class Level_2_Wall_1_Wood_Down: AnimSourceHidden{};
			class Level_2_Wall_1_Wood_Up: AnimSourceHidden{};
			class Level_2_Wall_1_Metal_Down: AnimSourceHidden{};
			class Level_2_Wall_1_Metal_Up: AnimSourceHidden{};
			class Level_2_Wall_2_Base_Down: AnimSourceHidden{};
			class Level_2_Wall_2_Base_Up: AnimSourceHidden{};
			class Level_2_Wall_2_Wood_Down: AnimSourceHidden{};
			class Level_2_Wall_2_Wood_Up: AnimSourceHidden{};
			class Level_2_Wall_2_Metal_Down: AnimSourceHidden{};
			class Level_2_Wall_2_Metal_Up: AnimSourceHidden{};
			class Level_2_Wall_3_Base_Down: AnimSourceHidden{};
			class Level_2_Wall_3_Base_Up: AnimSourceHidden{};
			class Level_2_Wall_3_Wood_Down: AnimSourceHidden{};
			class Level_2_Wall_3_Wood_Up: AnimSourceHidden{};
			class Level_2_Wall_3_Metal_Down: AnimSourceHidden{};
			class Level_2_Wall_3_Metal_Up: AnimSourceHidden{};
			class Level_3_Base: AnimSourceHidden{};
			class Level_3_Stairs: AnimSourceHidden{};
			class Level_3_Roof: AnimSourceHidden{};
			class Material_L3_WoodenLogs: AnimSourceHidden{};
			class Level_3_Wall_1_Camonet: AnimSourceHidden{};
			class Level_3_Wall_2_Camonet: AnimSourceHidden{};
			class Level_3_Wall_3_Camonet: AnimSourceHidden{};
			class Level_3_Wall_1_Base_Down: AnimSourceHidden{};
			class Level_3_Wall_1_Base_Up: AnimSourceHidden{};
			class Level_3_Wall_1_Wood_Down: AnimSourceHidden{};
			class Level_3_Wall_1_Wood_Up: AnimSourceHidden{};
			class Level_3_Wall_1_Metal_Down: AnimSourceHidden{};
			class Level_3_Wall_1_Metal_Up: AnimSourceHidden{};
			class Level_3_Wall_2_Base_Down: AnimSourceHidden{};
			class Level_3_Wall_2_Base_Up: AnimSourceHidden{};
			class Level_3_Wall_2_Wood_Down: AnimSourceHidden{};
			class Level_3_Wall_2_Wood_Up: AnimSourceHidden{};
			class Level_3_Wall_2_Metal_Down: AnimSourceHidden{};
			class Level_3_Wall_2_Metal_Up: AnimSourceHidden{};
			class Level_3_Wall_3_Base_Down: AnimSourceHidden{};
			class Level_3_Wall_3_Base_Up: AnimSourceHidden{};
			class Level_3_Wall_3_Wood_Down: AnimSourceHidden{};
			class Level_3_Wall_3_Wood_Up: AnimSourceHidden{};
			class Level_3_Wall_3_Metal_Down: AnimSourceHidden{};
			class Level_3_Wall_3_Metal_Up: AnimSourceHidden{};
		};
		class Construction
		{
			class level_1
			{
				class level_1_base
				{
					name = "$STR_CfgVehicles_Construction_Part_Base";
					is_base = 1;
					id = 1;
					platform_support = "level_1";
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_stairs_min","level_1_stairs_max"};
					build_action_type = 4;
					dismantle_action_type = 4;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L1_WoodenLogs";
							quantity = 4;
							lockable = 1;
						};
					};
				};
				class level_1_stairs
				{
					name = "$STR_CfgVehicles_Construction_Part_Stairs";
					id = 2;
					required_parts[] = {"level_1_base","level_1_roof"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_stairs_min","level_1_stairs_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 3;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1_WoodenPlanks";
							quantity = 6;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1_Nails";
							quantity = 18;
						};
					};
				};
				class level_1_roof
				{
					name = "$STR_CfgVehicles_Construction_Part_Roof";
					id = 3;
					platform_support = "level_2";
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_roof_min","level_1_roof_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1_Nails";
							quantity = 20;
						};
					};
				};
			};
			class level_1_wall_1
			{
				class level_1_wall_1_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					id = 4;
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_1_down_min","level_1_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_1_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					id = 6;
					required_parts[] = {"level_1_wall_1_base_down"};
					conflicted_parts[] = {"level_1_wall_1_metal_down"};
					collision_data[] = {"level_1_wall_1_down_min","level_1_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_1_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					id = 8;
					required_parts[] = {"level_1_wall_1_base_down"};
					conflicted_parts[] = {"level_1_wall_1_wood_down"};
					collision_data[] = {"level_1_wall_1_down_min","level_1_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 12;
						};
					};
				};
				class level_1_wall_1_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					id = 5;
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_1_up_min","level_1_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_1_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					id = 7;
					required_parts[] = {"level_1_wall_1_base_up"};
					conflicted_parts[] = {"level_1_wall_1_metal_up"};
					collision_data[] = {"level_1_wall_1_up_min","level_1_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_1_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					id = 9;
					required_parts[] = {"level_1_wall_1_base_up"};
					conflicted_parts[] = {"level_1_wall_1_wood_up"};
					collision_data[] = {"level_1_wall_1_up_min","level_1_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W1_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_1_wall_2
			{
				class level_1_wall_2_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					id = 10;
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_2_down_min","level_1_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_2_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					id = 12;
					required_parts[] = {"level_1_wall_2_base_down"};
					conflicted_parts[] = {"level_1_wall_2_metal_down"};
					collision_data[] = {"level_1_wall_2_down_min","level_1_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_2_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					id = 14;
					required_parts[] = {"level_1_wall_2_base_down"};
					conflicted_parts[] = {"level_1_wall_2_wood_down"};
					collision_data[] = {"level_1_wall_3_down_min","level_1_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 12;
						};
					};
				};
				class level_1_wall_2_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					id = 11;
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_2_up_min","level_1_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_2_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					id = 13;
					required_parts[] = {"level_1_wall_2_base_up"};
					conflicted_parts[] = {"level_1_wall_2_metal_up"};
					collision_data[] = {"level_1_wall_2_up_min","level_1_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_2_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					id = 15;
					required_parts[] = {"level_1_wall_2_base_up"};
					conflicted_parts[] = {"level_1_wall_2_wood_up"};
					collision_data[] = {"level_1_wall_2_up_min","level_1_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W2_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_1_wall_3
			{
				class level_1_wall_3_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					id = 16;
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_3_down_min","level_1_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_3_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					id = 18;
					required_parts[] = {"level_1_wall_3_base_down"};
					conflicted_parts[] = {"level_1_wall_3_metal_down"};
					collision_data[] = {"level_1_wall_3_down_min","level_1_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_3_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					id = 20;
					required_parts[] = {"level_1_wall_3_base_down"};
					conflicted_parts[] = {"level_1_wall_3_wood_down"};
					collision_data[] = {"level_1_wall_3_down_min","level_1_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 12;
						};
					};
				};
				class level_1_wall_3_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					id = 17;
					required_parts[] = {"level_1_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_1_wall_3_up_min","level_1_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_1_wall_3_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					id = 19;
					required_parts[] = {"level_1_wall_3_base_up"};
					conflicted_parts[] = {"level_1_wall_3_metal_up"};
					collision_data[] = {"level_1_wall_3_up_min","level_1_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L1W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_1_wall_3_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					id = 21;
					required_parts[] = {"level_1_wall_3_base_up"};
					conflicted_parts[] = {"level_1_wall_3_wood_up"};
					collision_data[] = {"level_1_wall_3_up_min","level_1_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L1W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L1W3_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_2
			{
				class level_2_base
				{
					name = "$STR_CfgVehicles_Construction_Part_Floor_Base";
					id = 22;
					platform_support = "level_2";
					required_parts[] = {"level_1_roof"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 8;
					dismantle_action_type = 8;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L2_WoodenLogs";
							quantity = 4;
							lockable = 1;
						};
					};
				};
				class level_2_stairs
				{
					name = "$STR_CfgVehicles_Construction_Part_Stairs";
					id = 23;
					required_parts[] = {"level_2_roof"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_stairs_min","level_2_stairs_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 3;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2_WoodenPlanks";
							quantity = 6;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2_Nails";
							quantity = 18;
						};
					};
				};
				class level_2_roof
				{
					name = "$STR_CfgVehicles_Construction_Part_Roof";
					id = 24;
					platform_support = "level_3";
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_roof_min","level_2_roof_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2_WoodenPlanks";
							quantity = 10;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2_Nails";
							quantity = 20;
						};
					};
				};
			};
			class level_2_wall_1
			{
				class level_2_wall_1_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					id = 25;
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_1_down_min","level_2_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_1_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					id = 27;
					required_parts[] = {"level_2_wall_1_base_down"};
					conflicted_parts[] = {"level_2_wall_1_metal_down"};
					collision_data[] = {"level_2_wall_1_down_min","level_2_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_1_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					id = 29;
					required_parts[] = {"level_2_wall_1_base_down"};
					conflicted_parts[] = {"level_2_wall_1_wood_down"};
					collision_data[] = {"level_2_wall_1_down_min","level_2_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 12;
						};
					};
				};
				class level_2_wall_1_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					id = 26;
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_1_up_min","level_2_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_1_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					id = 28;
					required_parts[] = {"level_2_wall_1_base_up"};
					conflicted_parts[] = {"level_2_wall_1_metal_up"};
					collision_data[] = {"level_2_wall_1_up_min","level_2_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_1_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					id = 30;
					required_parts[] = {"level_2_wall_1_base_up"};
					conflicted_parts[] = {"level_2_wall_1_wood_up"};
					collision_data[] = {"level_2_wall_1_up_min","level_2_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W1_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_2_wall_2
			{
				class level_2_wall_2_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					id = 31;
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_2_down_min","level_2_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_2_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					id = 33;
					required_parts[] = {"level_2_wall_2_base_down"};
					conflicted_parts[] = {"level_2_wall_2_metal_down"};
					collision_data[] = {"level_2_wall_2_down_min","level_2_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_2_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					id = 35;
					required_parts[] = {"level_2_wall_2_base_down"};
					conflicted_parts[] = {"level_2_wall_2_wood_down"};
					collision_data[] = {"level_2_wall_2_down_min","level_2_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 12;
						};
					};
				};
				class level_2_wall_2_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					id = 32;
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_2_up_min","level_2_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_2_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					id = 34;
					required_parts[] = {"level_2_wall_2_base_up"};
					conflicted_parts[] = {"level_2_wall_2_metal_up"};
					collision_data[] = {"level_2_wall_2_up_min","level_2_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_2_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					id = 36;
					required_parts[] = {"level_2_wall_2_base_up"};
					conflicted_parts[] = {"level_2_wall_2_wood_up"};
					collision_data[] = {"level_2_wall_2_up_min","level_2_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W2_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_2_wall_3
			{
				class level_2_wall_3_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					id = 37;
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_3_down_min","level_2_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_3_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					id = 39;
					required_parts[] = {"level_2_wall_3_base_down"};
					conflicted_parts[] = {"level_2_wall_3_metal_down"};
					collision_data[] = {"level_2_wall_3_down_min","level_2_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_3_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					id = 41;
					required_parts[] = {"level_2_wall_3_base_down"};
					conflicted_parts[] = {"level_2_wall_3_wood_down"};
					collision_data[] = {"level_2_wall_3_down_min","level_2_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 12;
						};
					};
				};
				class level_2_wall_3_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					id = 38;
					required_parts[] = {"level_2_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_2_wall_3_up_min","level_2_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_2_wall_3_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					id = 40;
					required_parts[] = {"level_2_wall_3_base_up"};
					conflicted_parts[] = {"level_2_wall_3_metal_up"};
					collision_data[] = {"level_2_wall_3_up_min","level_2_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L2W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_2_wall_3_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					id = 42;
					required_parts[] = {"level_2_wall_3_base_up"};
					conflicted_parts[] = {"level_2_wall_3_wood_up"};
					collision_data[] = {"level_2_wall_3_up_min","level_2_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L2W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L2W3_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_3
			{
				class level_3_base
				{
					name = "$STR_CfgVehicles_Construction_Part_Floor_Base";
					id = 43;
					platform_support = "level_3";
					required_parts[] = {"level_2_roof"};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 8;
					dismantle_action_type = 8;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_L3_WoodenLogs";
							quantity = 4;
							lockable = 1;
						};
					};
				};
				class level_3_roof
				{
					name = "$STR_CfgVehicles_Construction_Part_Roof";
					id = 44;
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_roof_min","level_3_roof_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3_Nails";
							quantity = 20;
						};
						class Material3
						{
							type = "MetalPlate";
							slot_name = "Material_L3_MetalSheets";
							quantity = 6;
						};
					};
				};
			};
			class level_3_wall_1
			{
				class level_3_wall_1_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					id = 45;
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_1_down_min","level_3_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_1_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					id = 47;
					required_parts[] = {"level_3_wall_1_base_down"};
					conflicted_parts[] = {"level_3_wall_1_metal_down"};
					collision_data[] = {"level_3_wall_1_down_min","level_3_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_1_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					id = 49;
					required_parts[] = {"level_3_wall_1_base_down"};
					conflicted_parts[] = {"level_3_wall_1_wood_down"};
					collision_data[] = {"level_3_wall_1_down_min","level_3_wall_1_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 12;
						};
					};
				};
				class level_3_wall_1_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					id = 46;
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_1_up_min","level_3_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W1_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_1_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					id = 48;
					required_parts[] = {"level_3_wall_1_base_up"};
					conflicted_parts[] = {"level_3_wall_1_metal_up"};
					collision_data[] = {"level_3_wall_1_up_min","level_3_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W1_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_1_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					id = 50;
					required_parts[] = {"level_3_wall_1_base_up"};
					conflicted_parts[] = {"level_3_wall_1_wood_up"};
					collision_data[] = {"level_3_wall_1_up_min","level_3_wall_1_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W1_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W1_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_3_wall_2
			{
				class level_3_wall_2_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					id = 51;
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_2_down_min","level_3_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_2_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					id = 53;
					required_parts[] = {"level_3_wall_2_base_down"};
					conflicted_parts[] = {"level_3_wall_2_metal_down"};
					collision_data[] = {"level_3_wall_2_down_min","level_3_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_2_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					id = 55;
					required_parts[] = {"level_3_wall_2_base_down"};
					conflicted_parts[] = {"level_3_wall_2_wood_down"};
					collision_data[] = {"level_3_wall_2_down_min","level_3_wall_2_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 12;
						};
					};
				};
				class level_3_wall_2_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					id = 52;
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_2_up_min","level_3_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W2_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_2_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					id = 54;
					required_parts[] = {"level_3_wall_2_base_up"};
					conflicted_parts[] = {"level_3_wall_2_metal_up"};
					collision_data[] = {"level_3_wall_2_up_min","level_3_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W2_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_2_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					id = 56;
					required_parts[] = {"level_3_wall_2_base_up"};
					conflicted_parts[] = {"level_3_wall_2_wood_up"};
					collision_data[] = {"level_3_wall_2_up_min","level_3_wall_2_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W2_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W2_Nails";
							quantity = 12;
						};
					};
				};
			};
			class level_3_wall_3
			{
				class level_3_wall_3_base_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Down";
					id = 57;
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_3_down_min","level_3_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_3_wood_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Down";
					id = 59;
					required_parts[] = {"level_3_wall_3_base_down"};
					conflicted_parts[] = {"level_3_wall_3_metal_down"};
					collision_data[] = {"level_3_wall_3_down_min","level_3_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_3_metal_down
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Down";
					id = 61;
					required_parts[] = {"level_3_wall_3_base_down"};
					conflicted_parts[] = {"level_3_wall_3_wood_down"};
					collision_data[] = {"level_3_wall_3_down_min","level_3_wall_3_down_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 12;
						};
					};
				};
				class level_3_wall_3_base_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Base_Up";
					id = 58;
					required_parts[] = {"level_3_base"};
					conflicted_parts[] = {};
					collision_data[] = {"level_3_wall_3_up_min","level_3_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W3_WoodenPlanks";
							quantity = 4;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 8;
						};
					};
				};
				class level_3_wall_3_wood_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Wood_Up";
					id = 60;
					required_parts[] = {"level_3_wall_3_base_up"};
					conflicted_parts[] = {"level_3_wall_3_metal_up"};
					collision_data[] = {"level_3_wall_3_up_min","level_3_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "WoodenPlank";
							slot_name = "Material_L3W3_WoodenPlanks";
							quantity = 5;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 10;
						};
					};
				};
				class level_3_wall_3_metal_up
				{
					name = "$STR_CfgVehicles_Construction_Part_Metal_Up";
					id = 62;
					required_parts[] = {"level_3_wall_3_base_up"};
					conflicted_parts[] = {"level_3_wall_3_wood_up"};
					collision_data[] = {"level_3_wall_3_up_min","level_3_wall_3_up_max"};
					build_action_type = 2;
					dismantle_action_type = 2;
					material_type = 4;
					class Materials
					{
						class Material1
						{
							type = "MetalPlate";
							slot_name = "Material_L3W3_MetalSheets";
							quantity = 3;
						};
						class Material2
						{
							type = "Nail";
							slot_name = "Material_L3W3_Nails";
							quantity = 12;
						};
					};
				};
			};
		};
	};
	class BarbedWire: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BarbedWire0";
		descriptionShort = "$STR_CfgVehicles_BarbedWire1";
		model = "\dz\gear\camping\Barbed_wire.p3d";
		OnRestrainChange = "BarbedWireLocked";
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\Barbed_wire_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\Barbed_wire.rvmat"};
		hologramMaterial = "Barbed_wire";
		hologramMaterialPath = "dz\gear\camping\data";
		barbedWireShockEnergyConsumption = 3;
		carveNavmesh = 1;
		itemSize[] = {2,4};
		weight = 400;
		inventorySlot[] = {"Wall_Barbedwire_1","Wall_Barbedwire_2","Level_1_Wall_1_Barbedwire_1","Level_1_Wall_1_Barbedwire_2","Level_1_Wall_2_Barbedwire_1","Level_1_Wall_2_Barbedwire_2","Level_1_Wall_3_Barbedwire_1","Level_1_Wall_3_Barbedwire_2"};
		physLayer = "item_large";
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\Barbed_wire.rvmat"}},{0.7,{"DZ\gear\camping\data\Barbed_wire.rvmat"}},{0.5,{"DZ\gear\camping\data\Barbed_wire_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\Barbed_wire_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\Barbed_wire_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			cordLength = 6;
			powerSocketsCount = 2;
			plugType = 6;
			compatiblePlugTypes[] = {6};
			cordTextureFile = "DZ\gear\camping\Data\plug_black_CO.paa";
			energyUsagePerSecond = 0.01;
		};
		class AnimationSources
		{
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class zbytek
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class rope_untie
				{
					soundSet = "rope_untie_SoundSet";
					id = 202;
				};
				class rope_struggle
				{
					soundSet = "rope_struggle_SoundSet";
					id = 203;
				};
				class pickUpItem
				{
					soundSet = "pickUpBarbedWire_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "barbedwire_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CombinationLock: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CombinationLock0";
		descriptionShort = "$STR_CfgVehicles_CombinationLock1";
		model = "\DZ\gear\camping\combination_lock3.p3d";
		inventorySlot[] = {"Att_CombinationLock"};
		rotationFlags = 34;
		itemSize[] = {3,3};
		weight = 350;
		class AnimationSources
		{
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Combination_Lock_Item: AnimSourceHidden{};
			class Lock_Item_1: AnimSourceHidden{};
			class Lock_Item_2: AnimSourceHidden{};
			class Combination_Lock_Attached: AnimSourceHidden{};
			class Lock_Attached_1: AnimSourceHidden{};
			class Lock_Attached_2: AnimSourceHidden{};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1500;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\combilock3_metal.rvmat","DZ\gear\camping\data\combination_lock_chain.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber1.rvmat"}},{0.7,{"DZ\gear\camping\data\combilock3_metal.rvmat","DZ\gear\camping\data\combination_lock_chain.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber1.rvmat"}},{0.5,{"DZ\gear\camping\data\combilock3_metal_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber1_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\combilock3_metal_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber1_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\combilock3_metal_destruct.rvmat","DZ\gear\camping\data\combination_lock_chain_destruct.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber_destruct.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber1_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
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
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class CombinationLock4: CombinationLock
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_4digitcombinationlock0";
		descriptionShort = "$STR_CfgVehicles_4digitcombinationlock1";
		model = "\DZ\gear\camping\combination_lock4.p3d";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1500;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\combilock4_metal.rvmat","DZ\gear\camping\data\combination_lock_chain.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber1.rvmat"}},{0.7,{"DZ\gear\camping\data\combilock4_metal.rvmat","DZ\gear\camping\data\combination_lock_chain.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber1.rvmat"}},{0.5,{"DZ\gear\camping\data\combilock4_metal_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber1_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\combilock4_metal_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber_damage.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber1_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\combilock4_metal_destruct.rvmat","DZ\gear\camping\data\combination_lock_chain_destruct.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber_destruct.rvmat","DZ\gear\camping\data\combination_lock_chain_rubber1_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
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
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};
	class BarbedWireLocked: Inventory_Base
	{
		scope = 1;
		displayName = "$STR_CfgVehicles_BarbedWireLocked0";
		model = "\dz\gear\camping\Barbed_wire_tied.p3d";
		OnRestrainChange = "BarbedWire";
		StruggleLength = 20;
		rotationFlags = 17;
		CanBeUnrestrainedBy[] = {"Hacksaw","15","Pliers","25","HandSaw","15"};
		CanBeUnrestrainedByDMG[] = {20,20,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\Barbed_wire.rvmat"}},{0.7,{"DZ\gear\camping\data\Barbed_wire.rvmat"}},{0.5,{"DZ\gear\camping\data\Barbed_wire_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\Barbed_wire_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\Barbed_wire_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class rope_untie
				{
					soundSet = "rope_untie_SoundSet";
					id = 202;
				};
				class rope_struggle
				{
					soundSet = "rope_struggle_SoundSet";
					id = 203;
				};
				class pickUpItem
				{
					soundSet = "pickUpBarbedWire_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "barbedwire_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CamoNet: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CamoNet0";
		descriptionShort = "$STR_CfgVehicles_CamoNet1";
		model = "\dz\gear\camping\camo_net_p.p3d";
		itemSize[] = {7,3};
		weight = 400;
		inventorySlot[] = {"CamoNet","Wall_Camonet","Level_1_Wall_1_Camonet","Level_1_Wall_2_Camonet","Level_1_Wall_3_Camonet","Level_2_Wall_1_Camonet","Level_2_Wall_2_Camonet","Level_2_Wall_3_Camonet","Level_3_Wall_1_Camonet","Level_3_Wall_2_Camonet","Level_3_Wall_3_Camonet"};
		physLayer = "item_large";
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 120;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\camo_net_p.rvmat"}},{0.7,{"DZ\gear\camping\data\camo_net_p.rvmat"}},{0.5,{"DZ\gear\camping\data\camo_net_p_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\camo_net_p_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\camo_net_p_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCourierBag_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCourierBag_SoundSet";
					id = 797;
				};
			};
		};
	};
	class SeaChest: Container_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SeaChest0";
		descriptionShort = "$STR_CfgVehicles_SeaChest1";
		model = "\DZ\gear\camping\sea_chest.p3d";
		hologramMaterial = "sea_chest";
		hologramMaterialPath = "dz\gear\camping\data";
		slopeTolerance = 0.4;
		yawPitchRollLimit[] = {45,45,45};
		weight = 10000;
		itemBehaviour = 0;
		itemSize[] = {10,10};
		carveNavmesh = 1;
		canBeDigged = 1;
		rotationFlags = 2;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\camping\data\sea_chest_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\sea_chest.rvmat"}},{0.7,{"DZ\gear\camping\data\sea_chest.rvmat"}},{0.5,{"DZ\gear\camping\data\sea_chest_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\sea_chest_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\sea_chest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage = 8.0;
					};
					class Blood
					{
						damage = 8.0;
					};
					class Shock
					{
						damage = 8.0;
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,10};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "seachest_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "seachest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class WoodenCrate: Container_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Wooden_Case0";
		descriptionShort = "$STR_CfgVehicles_Wooden_Case1";
		model = "\DZ\gear\camping\wooden_case.p3d";
		hologramMaterial = "wooden_case";
		hologramMaterialPath = "dz\gear\camping\data";
		slopeTolerance = 0.4;
		yawPitchRollLimit[] = {45,45,45};
		inventorySlot[] = {"Truck_01_WoodenCrate1","Truck_01_WoodenCrate2","Truck_01_WoodenCrate3","Truck_01_WoodenCrate4"};
		weight = 10000;
		itemSize[] = {10,5};
		itemBehaviour = 0;
		carveNavmesh = 1;
		canBeDigged = 1;
		rotationFlags = 2;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"\dz\gear\camping\data\wooden_case_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\wooden_case.rvmat"}},{0.7,{"DZ\gear\camping\data\wooden_case.rvmat"}},{0.5,{"DZ\gear\camping\data\wooden_case_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\wooden_case_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\wooden_case_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class FragGrenade
				{
					class Health
					{
						damage = 8.0;
					};
					class Blood
					{
						damage = 8.0;
					};
					class Shock
					{
						damage = 8.0;
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,5};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement
				{
					soundSet = "seachest_movement_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSeaChest_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "seachest_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class UndergroundStash: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_UndergroundStash0";
		model = "\DZ\gear\camping\underground_stash.p3d";
		canBeDigged = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
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
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {20,20};
			openable = 1;
			allowOwnedCargoManipulation = 1;
		};
	};
	class Spotlight: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Spotlight0";
		descriptionShort = "$STR_CfgVehicles_Spotlight1";
		model = "\dz\gear\camping\spotlight.p3d";
		slopeTolerance = 0.15;
		yawPitchRollLimit[] = {18,18,18};
		hiddenSelections[] = {"placing","cord_folded","cord_plugged","glass_unfolded","reflector_unfolded","glass_folded","reflector_folded"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\spotlight_co.paa","dz\gear\camping\data\plug_yellow_co.paa","dz\gear\camping\data\plug_yellow_co.paa","dz\gear\camping\data\spotlight_glass_ca.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\spotlight.rvmat","dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\spotlight_glass.rvmat"};
		hologramMaterial = "spotlight";
		hologramMaterialPath = "dz\gear\camping\data";
		weight = 1700;
		itemSize[] = {3,7};
		itemBehaviour = 2;
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\spotlight.rvmat"}},{0.7,{"DZ\gear\camping\data\spotlight.rvmat"}},{0.5,{"DZ\gear\camping\data\spotlight_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\spotlight_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\spotlight_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.14;
			cordTextureFile = "DZ\gear\camping\Data\plug_yellow_CO.paa";
			cordLength = 5;
			plugType = 2;
			updateInterval = 50;
		};
		class Reflectors
		{
			class Beam
			{
				color[] = {0.8,0.9,1.0,1.0};
				brightness = 20.0;
				radius = 60;
				angle = 140;
				angleInnerRatio = 0.25;
				dayLight = 1;
				position = "beamStart";
				direction = "beamTarget";
				hitpoint = "glass_unfolded";
				selection = "glass_unfolded";
			};
		};
		class AnimationSources
		{
			class cord_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class cord_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class reflector
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class reflector_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class reflector_unfolded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class glass_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class glass_unfolded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class spotlight_folded_cord_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class spotlight_folded_cord_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpSpotLightLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpSpotLight_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "spotlight_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class XmasLights: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_XmasLights0";
		descriptionShort = "$STR_CfgVehicles_XmasLights1";
		model = "\dz\gear\camping\christmas_lights.p3d";
		hiddenSelections[] = {"glass_r","glass_g","glass_b","glass_y"};
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		itemSize[] = {1,3};
		weight = 150;
		inventorySlot[] = {"Lights"};
		rotationFlags = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\christmass_ligths.rvmat"}},{0.7,{"DZ\gear\camping\data\christmass_ligths.rvmat"}},{0.5,{"DZ\gear\camping\data\christmass_ligths_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\christmass_ligths_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\christmass_ligths_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			switchOnAtSpawn = 1;
			energyUsagePerSecond = 0.05;
			cordTextureFile = "DZ\gear\camping\Data\plug_yellow_CO.paa";
			cordLength = 5;
			plugType = 2;
			updateInterval = 50;
		};
		class AnimationSources
		{
			class glass
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Xlights_glass_r
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Xlights_glass_g
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Xlights_glass_b
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Xlights_glass_y
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class christmas_lights
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
	};
	class Refridgerator: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Refridgerator0";
		descriptionShort = "$STR_CfgVehicles_Refridgerator1";
		model = "\DZ\gear\containers\fridge.p3d";
		canBeDigged = 1;
		weight = 1700;
		itemSize[] = {7,10};
		rotationFlags = 2;
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.1;
			cordTextureFile = "DZ\gear\camping\Data\plug_black_CO.paa";
			plugType = 2;
			cordLength = 5;
		};
		class Cargo
		{
			itemsCargoSize[] = {5,8};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
	};
	class PowerGenerator: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PowerGenerator0";
		descriptionShort = "$STR_CfgVehicles_PowerGenerator1";
		model = "\DZ\gear\camping\power_generator.p3d";
		rotationFlags = 2;
		slopeTolerance = 0.4;
		yawPitchRollLimit[] = {45,45,45};
		weight = 45000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		attachments[] = {"SparkPlug"};
		fuelTankCapacity = 7000;
		carveNavmesh = 1;
		heavyItem = 1;
		hiddenSelections[] = {"socket_1_plugged","socket_2_plugged","socket_3_plugged","socket_4_plugged","sparkplug_installed","placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\plug_black_CO.paa","dz\gear\camping\data\plug_yellow_CO.paa","dz\gear\camping\data\plug_white_CO.paa","dz\gear\camping\data\plug_orange_CO.paa","dz\gear\camping\data\power_generator_CO.paa","dz\gear\camping\data\power_generator_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\plug.rvmat","dz\gear\camping\data\power_generator.rvmat","dz\gear\camping\data\power_generator.rvmat"};
		hologramMaterial = "power_generator";
		hologramMaterialPath = "dz\gear\camping\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\power_generator.rvmat"}},{0.7,{"DZ\gear\camping\data\power_generator.rvmat"}},{0.5,{"DZ\gear\camping\data\power_generator_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\power_generator_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\power_generator_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyStorageMax = 10000;
			energyUsagePerSecond = 0.28;
			reduceMaxEnergyByDamageCoef = 0.5;
			energyAtSpawn = 5000;
			powerSocketsCount = 4;
			compatiblePlugTypes[] = {2,6};
		};
		class AnimationSources
		{
			class socket_1_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_2_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_3_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_4_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class sparkplug
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class fuel_tank
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class sparkplug_installed
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class dial_fuel
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class walk
				{
					soundSet = "powergenerator_movement_walk_SoundSet";
					id = 1;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpPowerGenerator_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpPowerGenerator_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "powergenerator_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CableReel: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CableReel0";
		descriptionShort = "$STR_CfgVehicles_CableReel1";
		model = "\dz\gear\camping\cable_reel.p3d";
		inventorySlot[] = {"CableReel"};
		slopeTolerance = 0.2;
		yawPitchRollLimit[] = {45,45,45};
		weight = 5000;
		itemSize[] = {3,4};
		itemBehaviour = 2;
		rotationFlags = 2;
		hiddenSelections[] = {"socket_1_plugged","cord_plugged","cord_folded","placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\cable_reel_co.paa","dz\gear\camping\data\cable_reel_co.paa","dz\gear\camping\data\cable_reel_co.paa","dz\gear\camping\data\cable_reel_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\cable_reel.rvmat","dz\gear\camping\data\cable_reel.rvmat","dz\gear\camping\data\cable_reel.rvmat","dz\gear\camping\data\cable_reel.rvmat"};
		hologramMaterial = "cable_reel";
		hologramMaterialPath = "dz\gear\camping\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 90;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\cable_reel.rvmat"}},{0.7,{"DZ\gear\camping\data\cable_reel.rvmat"}},{0.5,{"DZ\gear\camping\data\cable_reel_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\cable_reel_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\cable_reel_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			switchOnAtSpawn = 1;
			powerSocketsCount = 1;
			cordTextureFile = "DZ\gear\camping\Data\plug_orange_CO.paa";
			isPassiveDevice = 1;
			cordLength = 15;
			plugType = 2;
			compatiblePlugTypes[] = {2,6};
		};
		class AnimationSources
		{
			class cord_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class cord_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_1_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpCableReelLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpCableReel_SoundSet";
					id = 797;
				};
				class cablereel_drop
				{
					soundset = "cablereel_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class BatteryCharger: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BatteryCharger0";
		descriptionShort = "$STR_CfgVehicles_BatteryCharger1";
		model = "\dz\gear\camping\battery_charger.p3d";
		slopeTolerance = 0.15;
		yawPitchRollLimit[] = {45,45,45};
		attachments[] = {"CarBattery","TruckBattery"};
		weight = 5000;
		itemSize[] = {3,3};
		itemBehaviour = 1;
		rotationFlags = 2;
		hiddenSelections[] = {"light_stand_by","light_charging","light_charged","switch_on","clips_detached","clips_folded","cord_plugged","cord_folded","placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa","dz\gear\camping\data\battery_charger_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat","dz\gear\camping\data\battery_charger.rvmat"};
		hologramMaterial = "battery_charger";
		hologramMaterialPath = "dz\gear\camping\data";
		ChargeEnergyPerSecond = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 90;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\battery_charger.rvmat"}},{0.7,{"DZ\gear\camping\data\battery_charger.rvmat"}},{0.5,{"DZ\gear\camping\data\battery_charger_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\battery_charger_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\battery_charger_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.01;
			cordTextureFile = "DZ\gear\camping\Data\plug_black_CO.paa";
			cordLength = 5;
			plugType = 2;
			compatiblePlugTypes[] = {4};
			powerSocketsCount = 1;
			attachmentAction = 2;
			wetnessExposure = 0.1;
		};
		class AnimationSources
		{
			class cord_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class cord_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class clips_detached
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class clips_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class switch_on
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class switch_off
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class clips_car_battery
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class clips_truck_battery
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class light_stand_by
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class light_charging
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class light_charged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class drop
				{
					soundset = "batterycharger_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class HescoBox: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HescoBox0";
		descriptionShort = "$STR_CfgVehicles_HescoBox1";
		model = "\dz\gear\camping\hbox_base.p3d";
		forceFarBubble = "true";
		slopeTolerance = 0.15;
		yawPitchRollLimit[] = {45,45,45};
		weight = 5000;
		itemSize[] = {10,10};
		carveNavmesh = 1;
		itemBehaviour = 0;
		createProxyPhysicsOnInit = "false";
		createdProxiesOnInit[] = {"Deployed"};
		physLayer = "item_large";
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\hbox_filled_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\hbox_filled.rvmat"};
		hologramMaterial = "hbox_empty";
		hologramMaterialPath = "dz\gear\camping\data";
		rotationFlags = 4;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\hbox_empty.rvmat","DZ\gear\camping\data\hbox_filled.rvmat"}},{0.7,{"DZ\gear\camping\data\hbox_empty.rvmat","DZ\gear\camping\data\hbox_filled.rvmat"}},{0.5,{"DZ\gear\camping\data\hbox_empty_damage.rvmat","DZ\gear\camping\data\hbox_filled_damage.rvmat"}},{0.3,{"DZ\gear\camping\data\hbox_empty_damage.rvmat","DZ\gear\camping\data\hbox_filled_damage.rvmat"}},{0.0,{"DZ\gear\camping\data\hbox_empty_destruct.rvmat","DZ\gear\camping\data\hbox_filled_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
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
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
		class AnimationSources
		{
			class inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class filled
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class Fabric: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Folded_Fabric0";
		descriptionShort = "$STR_CfgVehicles_Folded_Fabric1";
		model = "\dz\gear\camping\fabric_ground.p3d";
		weight = 220;
		absorbency = 0.3;
		itemSize[] = {4,3};
		canBeSplit = 1;
		varQuantityInit = 1.0;
		varQuantityMin = 0.0;
		varQuantityMax = 4.0;
		inventorySlot[] = {"Material_Shelter_Fabric"};
		attachSoundSet[] = {"Shelter_Site_Attach_Fabric_SoundSet"};
		attachSoundSlot[] = {"Material_Shelter_Fabric"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_pristine_co.paa"}},{0.7,{"DZ\gear\camping\data\tent_worn_co.paa"}},{0.5,{"DZ\gear\camping\data\tent_damage_co.paa"}},{0.3,{"DZ\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"DZ\gear\camping\data\tent_destruct_co.paa"}}};
				};
			};
		};
	};
	class ShelterKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ShelterKit0";
		descriptionShort = "$STR_CfgVehicles_ShelterKit1";
		model = "\DZ\gear\camping\watchtower_kit.p3d";
		rotationFlags = 17;
		itemSize[] = {1,5};
		weight = 280;
		itemBehaviour = 1;
		attachments[] = {"Rope"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
				class GlobalArmor
				{
					class Projectile
					{
						class Health
						{
							damage = 0;
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
							damage = 0;
						};
						class Shock
						{
							damage = 0;
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory: AnimSourceHidden{};
			class Placing: AnimSourceHidden{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class crafting_1
				{
					soundSet = "FenceKit_crafting_1_SoundSet";
					id = 1111;
				};
				class crafting_2
				{
					soundSet = "FenceKit_crafting_2_SoundSet";
					id = 1112;
				};
				class crafting_3
				{
					soundSet = "FenceKit_crafting_3_SoundSet";
					id = 1113;
				};
				class crafting_4
				{
					soundSet = "FenceKit_crafting_4_SoundSet";
					id = 1114;
				};
				class crafting_5
				{
					soundSet = "FenceKit_crafting_5_SoundSet";
					id = 1115;
				};
			};
		};
	};
	class ShelterKitPlacing: ShelterKit
	{
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		scope = 2;
		model = "\DZ\gear\camping\shelter_kit_placing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\consumables\data\pile_of_planks_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\fence_pile_of_planks.rvmat"};
		hologramMaterial = "tent_medium";
		hologramMaterialPath = "dz\gear\camping\data";
		alignHologramToTerain = 1;
		slopeTolerance = 0.3;
		yawPitchRollLimit[] = {15,15,15};
	};
	class ShelterSite: BaseBuildingBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ShelterSite0";
		descriptionShort = "$STR_CfgVehicles_ShelterSite1";
		model = "\DZ\gear\camping\sheltersite.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		handheld = "false";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 10000;
		itemSize[] = {2,3};
		physLayer = "item_large";
		createProxyPhysicsOnInit = "false";
		rotationFlags = 2;
		attachments[] = {"Material_Shelter_FrameSticks","Material_Shelter_Leather","Material_Shelter_Fabric","Material_Shelter_Sticks"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0.0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
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
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] = {"Material_Shelter_FrameSticks"};
				icon = "cat_shelter_support";
				selection = "site";
			};
			class Material
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Materials";
				description = "";
				attachmentSlots[] = {"Material_Shelter_Leather","Material_Shelter_Fabric","Material_Shelter_Sticks"};
				icon = "cat_shelter_roof";
				selection = "site";
			};
		};
		class Construction
		{
			class site
			{
				class leather
				{
					name = "leather";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {"fabric","stick"};
					collision_data[] = {"leather_min","leather_max"};
					build_action_type = 16;
					dismantle_action_type = 16;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "LongWoodenStick";
							slot_name = "Material_Shelter_FrameSticks";
							quantity = 4;
							lockable = 0;
						};
						class Material2
						{
							type = "TannedLeather";
							slot_name = "Material_Shelter_Leather";
							quantity = 8;
							lockable = 0;
						};
					};
				};
				class fabric
				{
					name = "fabric";
					is_base = 1;
					id = 2;
					required_parts[] = {};
					conflicted_parts[] = {"leather","stick"};
					collision_data[] = {"fabric_min","fabric_max"};
					build_action_type = 16;
					dismantle_action_type = 16;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "LongWoodenStick";
							slot_name = "Material_Shelter_FrameSticks";
							quantity = 4;
							lockable = 0;
						};
						class Material2
						{
							type = "Fabric";
							slot_name = "Material_Shelter_Fabric";
							quantity = 4;
							lockable = 0;
						};
					};
				};
				class stick
				{
					name = "stick";
					is_base = 1;
					id = 3;
					required_parts[] = {};
					conflicted_parts[] = {"leather","fabric"};
					collision_data[] = {"stick_min","stick_max"};
					build_action_type = 16;
					dismantle_action_type = 16;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "LongWoodenStick";
							slot_name = "Material_Shelter_FrameSticks";
							quantity = 4;
							lockable = 0;
						};
						class Material2
						{
							type = "WoodenStick";
							slot_name = "Material_Shelter_Sticks";
							quantity = 50;
							lockable = 0;
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Material_Shelter_FrameSticks: AnimSourceHidden{};
			class Material_Shelter_Leather: AnimSourceHidden{};
			class Material_Shelter_Fabric: AnimSourceHidden{};
			class Material_Shelter_Sticks: AnimSourceHidden{};
		};
	};
	class ShelterBase: TentBase
	{
		scope = 0;
		model = "\DZ\gear\camping\shelter_fabric.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		slopeTolerance = 0.3;
		yawPitchRollLimit[] = {15,15,15};
		hiddenSelections[] = {"xlights_glass_r","xlights_glass_g","xlights_glass_b","xlights_glass_y"};
		openable = 0;
		carveNavmesh = 1;
		inherit_rotation = 1;
		weight = 10000;
		itemSize[] = {8,4};
		itemsCargoSize[] = {10,10};
		itemBehaviour = 2;
		lootCategory = "Tents";
		placement = "ForceSlopeOnTerrain";
		physLayer = "item_large";
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = {{1.0,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0.0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.05;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.3;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1.0,1.0,1.0,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0.0;
				heatHazePower = 0.0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
		class AnimationSources
		{
			class CamoNet
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Xlights
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_r
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_g
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_b
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Xlights_glass_y
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_folded
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
			class Cord_plugged
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement_walk
				{
					soundSet = "mediumtent_movement_walk_SoundSet";
					id = 1;
				};
				class movement_run
				{
					soundSet = "mediumtent_movement_run_SoundSet";
					id = 3;
				};
				class movement_sprint
				{
					soundSet = "mediumtent_movement_sprint_SoundSet";
					id = 5;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpTentLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpTent_SoundSet";
					id = 797;
				};
				class mediumtent_drop
				{
					soundset = "mediumtent_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class ShelterFabric: ShelterBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ShelterFabric0";
		descriptionShort = "$STR_CfgVehicles_ShelterFabric1";
		model = "\DZ\gear\camping\shelter_fabric.p3d";
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_pristine_co.paa"}},{0.7,{"DZ\gear\camping\data\tent_worn_co.paa"}},{0.5,{"DZ\gear\camping\data\tent_damage_co.paa"}},{0.3,{"DZ\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"DZ\gear\camping\data\tent_destruct_co.paa"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.05;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.3;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
				};
			};
		};
	};
	class ShelterLeather: ShelterBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ShelterLeather0";
		descriptionShort = "$STR_CfgVehicles_ShelterLeather1";
		model = "\DZ\gear\camping\shelter_leather.p3d";
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 600;
					healthLevels[] = {{1.0,{"DZ\gear\camping\data\tent_pristine_co.paa"}},{0.7,{"DZ\gear\camping\data\tent_worn_co.paa"}},{0.5,{"DZ\gear\camping\data\tent_damage_co.paa"}},{0.3,{"DZ\gear\camping\data\tent_destruct_co.paa"}},{0.0,{"DZ\gear\camping\data\tent_destruct_co.paa"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.05;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.3;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 8;
					};
				};
			};
		};
	};
	class ShelterStick: ShelterBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ShelterStick0";
		descriptionShort = "$STR_CfgVehicles_ShelterStick1";
		model = "\DZ\gear\camping\shelter_stick.p3d";
		repairableWithKits[] = {5};
		repairCosts[] = {25.0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 400;
					healthLevels[] = {{1.0,{"dz\characters\backpacks\data\ghillie_green_co.paa","dz\gear\camping\data\improvised_tent_construction_01.rvmat","dz\gear\crafting\data\bp_wooden_stick.rvmat","dz\plants\tree\data\t_piceaabies_leaves_ca.paa"}},{0.7,{"dz\characters\backpacks\data\ghillie_green_damage_co.paa","DZ\gear\camping\Data\wooden_log_damage.rvmat","dz\gear\crafting\data\bp_wooden_stick_damage.rvmat","dz\plants\tree\data\t_piceaabies_leaves_damage_ca.paa"}},{0.5,{"dz\characters\backpacks\data\ghillie_green_damage_co.paa","DZ\gear\camping\Data\wooden_log_damage.rvmat","dz\gear\crafting\data\bp_wooden_stick_damage.rvmat","dz\plants\tree\data\t_piceaabies_leaves_damage_ca.paa"}},{0.3,{"dz\characters\backpacks\data\ghillie_green_destruct_co.paa","DZ\gear\camping\Data\wooden_log_destruct.rvmat","dz\gear\crafting\data\bp_wooden_stick_destruct.rvmat","dz\plants\tree\data\t_piceaabies_leaves_destruct_ca.paa"}},{0.0,{"dz\characters\backpacks\data\ghillie_green_destruct_co.paa","DZ\gear\camping\Data\wooden_log_destruct.rvmat","dz\gear\crafting\data\bp_wooden_stick_destruct.rvmat","dz\plants\tree\data\t_piceaabies_leaves_destruct_ca.paa"}}};
				};
			};
			componentNames[] = {""};
		};
	};
	class TerritoryFlag: BaseBuildingBase
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TerritoryFlag0";
		descriptionShort = "$STR_CfgVehicles_TerritoryFlag1";
		model = "\DZ\gear\camping\territory_flag.p3d";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		handheld = "false";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 60000;
		itemSize[] = {6,6};
		physLayer = "item_large";
		createProxyPhysicsOnInit = "false";
		createdProxiesOnInit[] = {"Deployed"};
		rotationFlags = 2;
		attachments[] = {"Material_FPole_WoodenLog","Material_FPole_Stones","Material_FPole_WoodenLog2","Material_FPole_MetalWire","Material_FPole_Rope","Material_FPole_Nails","Material_FPole_MagicStick","Material_FPole_Flag"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
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
				class Melee
				{
					class Health
					{
						damage = 0;
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
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Construction_Part_Base";
				description = "";
				attachmentSlots[] = {"Material_FPole_WoodenLog"};
				icon = "cat_tf_log";
				selection = "totem";
			};
			class Support
			{
				name = "$STR_CfgVehicles_TerritoryFlag_Att_Category_Support";
				description = "";
				attachmentSlots[] = {"Material_FPole_Stones","Material_FPole_WoodenLog2"};
				icon = "tf_stones";
				selection = "totem";
			};
			class Pole
			{
				name = "$STR_CfgVehicles_TerritoryFlag_Att_Category_Pole";
				description = "";
				attachmentSlots[] = {"Material_FPole_MetalWire","Material_FPole_Rope","Material_FPole_Nails","Material_FPole_MagicStick"};
				icon = "cat_tf_pole";
				selection = "totem";
			};
			class Flag
			{
				name = "$STR_CfgVehicles_TerritoryFlag_Att_Category_Flag";
				description = "";
				attachmentSlots[] = {"Material_FPole_Flag"};
				icon = "tf_flag";
				selection = "totem";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class flag_mast
			{
				source = "user";
				initPhase = 1;
				animPeriod = 1;
			};
			class Deployed: AnimSourceHidden{};
			class Base: AnimSourceHidden{};
			class Support: AnimSourceHidden{};
			class Pole: AnimSourceHidden{};
			class Material_FPole_WoodenLog: AnimSourceHidden{};
			class Material_FPole_Stones: AnimSourceHidden{};
			class Material_FPole_WoodenLog2: AnimSourceHidden{};
			class Material_FPole_MetalWire: AnimSourceHidden{};
			class Material_FPole_Rope: AnimSourceHidden{};
			class Material_FPole_Nails: AnimSourceHidden{};
			class Material_FPole_MagicStick: AnimSourceHidden{};
		};
		class Construction
		{
			class totem
			{
				class base
				{
					name = "$STR_CfgVehicles_Construction_Part_Base";
					is_base = 1;
					id = 1;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {"base_min","base_max"};
					build_action_type = 16;
					dismantle_action_type = 16;
					material_type = 1;
					class Materials
					{
						class Material1
						{
							type = "WoodenLog";
							slot_name = "Material_FPole_WoodenLog";
							quantity = 1;
							lockable = 0;
						};
					};
				};
				class support
				{
					name = "$STR_CfgVehicles_TerritoryFlag_Att_Category_Support";
					id = 2;
					required_parts[] = {"base"};
					conflicted_parts[] = {};
					collision_data[] = {"support_min","support_max"};
					build_action_type = 36;
					dismantle_action_type = 36;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "Stone";
							slot_name = "Material_FPole_Stones";
							quantity = 32;
							lockable = 0;
						};
						class Material2
						{
							type = "WoodenLog";
							slot_name = "Material_FPole_WoodenLog2";
							quantity = 6;
							lockable = 0;
						};
					};
				};
				class pole
				{
					name = "$STR_CfgVehicles_TerritoryFlag_Att_Category_Pole";
					id = 3;
					required_parts[] = {"support"};
					conflicted_parts[] = {};
					collision_data[] = {"pole_min","pole_max"};
					build_action_type = 2;
					dismantle_action_type = 64;
					material_type = 2;
					class Materials
					{
						class Material1
						{
							type = "MetalWire";
							slot_name = "Material_FPole_MetalWire";
							quantity = 0;
							lockable = 1;
						};
						class Material2
						{
							type = "Rope";
							slot_name = "Material_FPole_Rope";
							quantity = 0;
							lockable = 1;
						};
						class Material3
						{
							type = "Nail";
							slot_name = "Material_FPole_Nails";
							quantity = 60;
							lockable = 0;
						};
						class Material4
						{
							type = "WoodenLog";
							slot_name = "Material_FPole_MagicStick";
							quantity = 3;
							lockable = 0;
						};
					};
				};
			};
		};
	};
	class TerritoryFlagKit: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TerritoryFlagKit0";
		descriptionShort = "$STR_CfgVehicles_TerritoryFlagKit1";
		model = "\DZ\gear\camping\territory_flag_kit.p3d";
		rotationFlags = 17;
		itemSize[] = {1,5};
		weight = 280;
		itemBehaviour = 1;
		attachments[] = {"Rope"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
				class GlobalArmor
				{
					class Projectile
					{
						class Health
						{
							damage = 0;
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
							damage = 0;
						};
						class Shock
						{
							damage = 0;
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Inventory: AnimSourceHidden{};
			class Placing: AnimSourceHidden{};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class crafting_1
				{
					soundSet = "FenceKit_crafting_1_SoundSet";
					id = 1111;
				};
				class crafting_2
				{
					soundSet = "FenceKit_crafting_2_SoundSet";
					id = 1112;
				};
				class crafting_3
				{
					soundSet = "FenceKit_crafting_3_SoundSet";
					id = 1113;
				};
				class crafting_4
				{
					soundSet = "FenceKit_crafting_4_SoundSet";
					id = 1114;
				};
				class crafting_5
				{
					soundSet = "FenceKit_crafting_5_SoundSet";
					id = 1115;
				};
			};
		};
	};
	class TerritoryFlagKitPlacing: TerritoryFlagKit
	{
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		scope = 2;
		model = "\DZ\gear\camping\territory_flag_kit_placing.p3d";
		storageCategory = 10;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\consumables\data\pile_of_planks_co.tga"};
		hiddenSelectionsMaterials[] = {"dz\gear\camping\data\fence_pile_of_planks.rvmat"};
		hologramMaterial = "tent_medium";
		hologramMaterialPath = "dz\gear\camping\data";
		alignHologramToTerain = 0;
		slopeTolerance = 0.3;
	};
	class Flag_Base: Inventory_Base
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_Flag_Base0";
		descriptionShort = "$STR_CfgVehicles_Flag_Base1";
		model = "\dz\gear\camping\DZ_Flag.p3d";
		itemSize[] = {2,2};
		absorbency = 0.9;
		inventorySlot[] = {"Material_FPole_Flag"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\gear\camping\data\flag_chern_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0.0,{""}}};
				};
				class GlobalArmor
				{
					class Projectile
					{
						class Health
						{
							damage = 0;
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
							damage = 0;
						};
						class Shock
						{
							damage = 0;
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class unfolded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class Flag_Chernarus: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_Chern_co.paa"};
	};
	class Flag_Chedaki: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_Ched_co.paa"};
	};
	class Flag_NAPA: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_NAPA_co.paa"};
	};
	class Flag_CDF: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_CDF_co.paa"};
	};
	class Flag_Livonia: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_Livo_co.paa"};
	};
	class Flag_Altis: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_Alti_co.paa"};
	};
	class Flag_SSahrani: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_KoS_co.paa"};
	};
	class Flag_NSahrani: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_DRoS_co.paa"};
	};
	class Flag_DayZ: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_DAYZ_co.paa"};
	};
	class Flag_LivoniaArmy: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_LDF_co.paa"};
	};
	class Flag_White: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_white_co.paa"};
	};
	class Flag_Bohemia: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_BI_co.paa"};
	};
	class Flag_APA: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_APA_co.paa"};
	};
	class Flag_UEC: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_UEC_co.paa"};
	};
	class Flag_Pirates: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_jolly_co.paa"};
	};
	class Flag_Cannibals: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_jolly_c_co.paa"};
	};
	class Flag_Bear: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_bear_co.paa"};
	};
	class Flag_Wolf: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_wolf_co.paa"};
	};
	class Flag_BabyDeer: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_Fawn_co.paa"};
	};
	class Flag_Rooster: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_cock_co.paa"};
	};
	class Flag_LivoniaPolice: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_police_co.paa"};
	};
	class Flag_CMC: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_CMC_co.paa"};
	};
	class Flag_TEC: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_TEC_co.paa"};
	};
	class Flag_CHEL: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_CHEL_co.paa"};
	};
	class Flag_Zenit: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_Zenit_co.paa"};
	};
	class Flag_HunterZ: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_zhunters_co.paa"};
	};
	class Flag_BrainZ: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_brain_co.paa"};
	};
	class Flag_Refuge: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_refuge_co.paa"};
	};
	class Flag_RSTA: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_rsta_co.paa"};
	};
	class Flag_Snake: Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\gear\camping\Data\Flag_snake_co.paa"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyPart
	{
		scope = 2;
		simulation = "ProxyInventory";
		model = "";
		inventorySlot[] = {""};
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 1;
	};
	class ProxyBaseBuilding: ProxyAttachment
	{
		scope = 2;
	};
	class Proxysingle_plank: ProxyBaseBuilding
	{
		model = "\DZ\gear\consumables\single_plank.p3d";
		inventorySlot[] = {"Material_WoodenPlanks","Material_L1_WoodenPlanks","Material_L1W1_WoodenPlanks","Material_L1W2_WoodenPlanks","Material_L1W3_WoodenPlanks","Material_L2_WoodenPlanks","Material_L2W1_WoodenPlanks","Material_L2W2_WoodenPlanks","Material_L2W3_WoodenPlanks","Material_L3_WoodenPlanks","Material_L3W1_WoodenPlanks","Material_L3W2_WoodenPlanks","Material_L3W3_WoodenPlanks"};
	};
	class ProxySingle_Metal_Sheet: ProxyBaseBuilding
	{
		model = "\DZ\gear\consumables\Single_Metal_Sheet.p3d";
		inventorySlot[] = {"Material_MetalSheets","Material_L3_MetalSheets","Material_L1W1_MetalSheets","Material_L1W2_MetalSheets","Material_L1W3_MetalSheets","Material_L2W1_MetalSheets","Material_L2W2_MetalSheets","Material_L2W3_MetalSheets","Material_L3W1_MetalSheets","Material_L3W2_MetalSheets","Material_L3W3_MetalSheets"};
	};
	class ProxyNails_loose_10: ProxyBaseBuilding
	{
		model = "\DZ\gear\consumables\Nails_loose_10.p3d";
		inventorySlot[] = {"Material_Nails","Material_L1_Nails","Material_L1W1_Nails","Material_L1W2_Nails","Material_L1W3_Nails","Material_L2_Nails","Material_L2W1_Nails","Material_L2W2_Nails","Material_L2W3_Nails","Material_L3_Nails","Material_L3W1_Nails","Material_L3W2_Nails","Material_L3W3_Nails","Material_FPole_Nails"};
	};
	class ProxyCombinationLock: ProxyBaseBuilding
	{
		model = "\DZ\gear\camping\combination_lock_proxied.p3d";
		inventorySlot[] = {"Att_CombinationLock"};
		class AnimationSources
		{
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class Combination_Lock_Item: AnimSourceHidden{};
			class Combination_Lock_Attached: AnimSourceHidden{};
		};
	};
	class Proxycombination_lock3: ProxyCombinationLock
	{
		model = "\DZ\gear\camping\combination_lock3.p3d";
	};
	class Proxycombination_lock4: ProxyCombinationLock
	{
		model = "\DZ\gear\camping\combination_lock4.p3d";
	};
	class Proxywooden_log: ProxyBaseBuilding
	{
		model = "\dz\gear\camping\wooden_log.p3d";
		inventorySlot[] = {"Material_FPole_WoodenLog","Material_FPole_WoodenLog2"};
	};
	class Proxycable_reel
	{
		model = "DZ\gear\camping\cable_reel.p3d";
		inventorySlot[] = {"CableReel"};
		scope = 2;
		simulation = "ProxyInventory";
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 1;
		class AnimationSources
		{
			class cord_folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class cord_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class socket_1_available
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class socket_1_plugged
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class dropped_plug_1
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class ProxyDZ_Flag: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"Material_FPole_Flag"};
		model = "\DZ\gear\camping\DZ_Flag.p3d";
		class AnimationSources
		{
			class folded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class unfolded
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class ProxyWooden_stick_blunt: ProxyBaseBuilding
	{
		model = "\dz\gear\crafting\Wooden_stick_blunt.p3d";
		inventorySlot[] = {"Material_Shelter_FrameSticks"};
	};
	class Proxytanned_leather: ProxyBaseBuilding
	{
		model = "\dz\gear\consumables\tanned_leather.p3d";
		inventorySlot[] = {"Material_Shelter_Leather"};
	};
	class Proxyfabric_ground: ProxyBaseBuilding
	{
		model = "\dz\gear\camping\fabric_ground.p3d";
		inventorySlot[] = {"Material_Shelter_Fabric"};
	};
	class Proxybp_wooden_stick: ProxyBaseBuilding
	{
		model = "\dz\gear\crafting\bp_wooden_stick.p3d";
		inventorySlot[] = {"Material_Shelter_Sticks"};
	};
};
