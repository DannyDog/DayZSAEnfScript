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
	class DZ_Gear_Navigation
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgLocationTypes
{
	class Name
	{
		name = "keypoint";
		drawStyle = "name";
		texture = "#(argb,1,1,1)color(1,1,1,1)";
		color[] = {0,0,0,1};
		size = 0;
		font = "gui/fonts/sdf_MetronBook24";
		textSize = 0.03;
		shadow = 0;
		importance = 1;
	};
	class NameIcon
	{
		name = "keypoint";
		drawStyle = "icon";
		texture = "#(argb,1,1,1)color(1,1,1,1)";
		color[] = {0,0,0,1};
		size = 0;
		font = "gui/fonts/sdf_MetronBook24";
		textSize = 0.03;
		shadow = 0;
		importance = 1;
	};
	class Capital: Name
	{
		textSize = 0.06;
		importance = 7;
	};
	class City: Name
	{
		textSize = 0.05;
		importance = 6;
	};
	class Village: Name
	{
		textSize = 0.04;
		importance = 5;
	};
	class Local: Name
	{
		color[] = {0.44,0.38,0.3,1};
		textSize = 0.03;
		importance = 2;
	};
	class Marine: Name
	{
		color[] = {0.05,0.4,0.8,0.8};
		textSize = 0.03;
		importance = 2;
	};
	class Ruin: NameIcon
	{
		texture = "\DZ\gear\navigation\data\map_ruin_ca.paa";
		textSize = 0.03;
		importance = 2;
		size = 7;
	};
	class Camp: NameIcon
	{
		color[] = {0.44,0.38,0.3,1};
		texture = "\DZ\gear\navigation\data\map_camp_ca.paa";
		textSize = 0.04;
		size = 9;
	};
	class Hill: NameIcon
	{
		color[] = {0.0,0.0,0.0,1.0};
		texture = "\DZ\gear\navigation\data\map_hill_ca.paa";
		size = 9;
	};
	class ViewPoint: NameIcon
	{
		color[] = {0.78,0.0,0.05,1.0};
		texture = "\DZ\gear\navigation\data\map_viewpoint_ca.paa";
		size = 9;
	};
	class RockArea: NameIcon
	{
		color[] = {0.0,0.0,0.0,1.0};
		texture = "\DZ\gear\navigation\data\map_rock_ca.paa";
		size = 9;
	};
	class RailroadStation: NameIcon
	{
		color[] = {0.0,0.0,0.0,1.0};
		texture = "\DZ\gear\navigation\data\map_station_ca.paa";
		size = 9;
	};
	class IndustrialSite: NameIcon
	{
		color[] = {0.0,0.0,0.0,1.0};
		texture = "\DZ\gear\navigation\data\map_factory_ca.paa";
		size = 9;
	};
	class LocalOffice: NameIcon
	{
		color[] = {0.22,0.21,0.51,1};
		texture = "\DZ\gear\navigation\data\map_govoffice_ca.paa";
		size = 10;
	};
	class BorderCrossing: NameIcon
	{
		color[] = {0.78,0.0,0.05,1.0};
		texture = "\DZ\gear\navigation\data\map_border_cross_ca.paa";
		size = 9;
	};
	class VegetationBroadleaf: NameIcon
	{
		color[] = {0.25,0.4,0.2,1.0};
		texture = "\DZ\gear\navigation\data\map_broadleaf_ca.paa";
		size = 9;
	};
	class VegetationFir: NameIcon
	{
		color[] = {0.25,0.4,0.2,1.0};
		texture = "\DZ\gear\navigation\data\map_fir_ca.paa";
		size = 9;
	};
	class VegetationPalm: NameIcon
	{
		color[] = {0.25,0.4,0.2,1.0};
		texture = "\DZ\gear\navigation\data\map_palm_ca.paa";
		size = 9;
	};
	class VegetationVineyard: NameIcon
	{
		color[] = {0.25,0.4,0.2,1.0};
		texture = "\DZ\gear\navigation\data\map_vineyard_ca.paa";
		size = 9;
	};
};
class MapDefaults;
class CfgVehicles
{
	class Inventory_Base;
	class ItemMap: Inventory_Base{};
	class ItemCompass: Inventory_Base{};
	class ChernarusMap: ItemMap
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_ChernarusMap0";
		descriptionShort = "$STR_CfgVehicles_ChernarusMap1";
		model = "\dz\gear\navigation\Map_chernarus_animated.p3d";
		rotationFlags = 17;
		itemSize[] = {1,2};
		weight = 40;
		selectionPaper = "paper";
		simulation = "ItemMap";
		hiddenSelections[] = {"texture_map_closed","texture_map_opened","texture_legend"};
		absorbency = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\navigation\data\Map_chernarus.rvmat"}},{0.7,{"DZ\gear\navigation\data\Map_chernarus.rvmat"}},{0.5,{"DZ\gear\navigation\data\Map_chernarus_damage.rvmat"}},{0.3,{"DZ\gear\navigation\data\Map_chernarus_damage.rvmat"}},{0.0,{"DZ\gear\navigation\data\Map_chernarus_destruct.rvmat"}}};
				};
			};
		};
		class MapProperties: MapDefaults
		{
			scaleMin = 0.12;
			scaleMax = 0.6;
		};
		class AnimationSources
		{
			class map_closed
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class map_opened
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 1;
			};
		};
	};
	class ChernarusMap_Open: ChernarusMap{};
	class Compass: ItemCompass
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Compass0";
		descriptionShort = "$STR_CfgVehicles_Compass1";
		model = "\dz\gear\navigation\compass.p3d";
		animClass = "Compass";
		itemSize[] = {1,2};
		weight = 190;
		simulation = "ItemCompass";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\navigation\data\compass.rvmat"}},{0.7,{"DZ\gear\navigation\data\compass.rvmat"}},{0.5,{"DZ\gear\navigation\data\compass_damage.rvmat"}},{0.3,{"DZ\gear\navigation\data\compass_damage.rvmat"}},{0.0,{"DZ\gear\navigation\data\compass_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class cover
			{
				source = "user";
				animPeriod = 0.5;
				initPhase = 0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class compass_open
				{
					soundSet = "compass_open_SoundSet";
					id = 204;
				};
				class compass_close
				{
					soundSet = "compass_close_SoundSet";
					id = 205;
				};
			};
		};
	};
	class OrienteeringCompass: ItemCompass
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_OrienteeringCompass0";
		descriptionShort = "$STR_CfgVehicles_OrienteeringCompass1";
		model = "\dz\gear\navigation\compass_modern.p3d";
		animClass = "Compass";
		itemSize[] = {1,2};
		weight = 130;
		simulation = "ItemCompass";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\navigation\data\compass_modern.rvmat"}},{0.7,{"DZ\gear\navigation\data\compass_modern.rvmat"}},{0.5,{"DZ\gear\navigation\data\compass_modern_damage.rvmat"}},{0.3,{"DZ\gear\navigation\data\compass_modern_damage.rvmat"}},{0.0,{"DZ\gear\navigation\data\compass_modern_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class wheel
			{
				source = "user";
				animPeriod = 0;
				initPhase = 0;
			};
		};
	};
};
