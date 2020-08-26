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
	class DZ_Surfaces_Bliss
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Surfaces"};
	};
};
class CfgWorlds
{
	class DefaultWorld;
	class CAWorld: DefaultWorld
	{
		class DefaultClutter;
		class Clutter
		{
			class Wheat_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_wheat1_summer.p3d";
				scaleMin = 0.5;
				scaleMax = 1.0;
				noSatColor = 1;
			};
			class WheatTall_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_wheat1_summer.p3d";
				scaleMin = 1.0;
				scaleMax = 2.0;
				noSatColor = 1;
			};
			class Stubble_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_stubble_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.2;
				noSatColor = 1;
			};
			class Vaccinium_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_vaccinium_summer.p3d";
				scaleMin = 0.6;
				scaleMax = 1.0;
				noSatColor = 0;
			};
			class Fern_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_fern_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.2;
				noSatColor = 0;
			};
			class FernTall_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_fernTall_summer.p3d";
				scaleMin = 0.7;
				scaleMax = 1.0;
				noSatColor = 0;
			};
			class branches_picea_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_branches_picea_summer.p3d";
				scaleMin = 0.6;
				scaleMax = 0.9;
				noSatColor = 0;
			};
			class branchesBig_picea_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_branchesBig_picea_summer.p3d";
				scaleMin = 0.6;
				scaleMax = 0.8;
				noSatColor = 0;
			};
			class branches_deciduous_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_branches_deciduous_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.25;
				noSatColor = 0;
			};
			class Pines_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_Pines_summer.p3d";
				scaleMin = 0.5;
				scaleMax = 1.1;
				noSatColor = 1;
			};
			class Cones_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_cones_summer.p3d";
				scaleMin = 1.0;
				scaleMax = 1.0;
				noSatColor = 0;
			};
			class leaves_dead_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_leaves_dead_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.1;
				noSatColor = 0;
			};
			class leaves_dead_half_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_leaves_dead_half_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.1;
				noSatColor = 0;
			};
			class plantsSmall1_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_plantsSmall1_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.1;
				noSatColor = 0;
			};
			class plantsSmall2_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_plantsSmall2_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.1;
				noSatColor = 0;
			};
			class GrassSmall_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassSmall_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.0;
				noSatColor = 0;
			};
			class GrassTiny_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassTiny_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.0;
				noSatColor = 0;
			};
			class beech_big_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_beech_big_summer.p3d";
				scaleMin = 0.4;
				scaleMax = 0.9;
				noSatColor = 0;
			};
			class beech_mid_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_beech_mid_summer.p3d";
				scaleMin = 0.7;
				scaleMax = 1.0;
				noSatColor = 0;
			};
			class beech_small_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_beech_small_summer.p3d";
				scaleMin = 0.7;
				scaleMax = 1.0;
				noSatColor = 0;
			};
			class GrassPlant1_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassPlant1_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.1;
				noSatColor = 0;
			};
			class GrassPlant2_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassPlant2_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.1;
				noSatColor = 0;
			};
			class Grass_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_Grass_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.1;
				noSatColor = 0;
			};
			class GrassLow_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassLow_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.1;
				noSatColor = 0;
			};
			class GrassAnthoxanthum_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassAnthoxanthum_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.1;
				noSatColor = 0;
			};
			class GrassAnthoxanthum_bended_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassAnthoxanthum_bended_summer.p3d";
				scaleMin = 0.9;
				scaleMax = 1.1;
				noSatColor = 0;
			};
			class GrassTall2_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassTall2_summer.p3d";
				scaleMin = 1.0;
				scaleMax = 1.5;
				noSatColor = 0;
			};
			class GrassTall3_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassTall3_summer.p3d";
				scaleMin = 1.0;
				scaleMax = 1.5;
				noSatColor = 0;
			};
			class Grass_flower1_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_Grass_flower1_summer.p3d";
				scaleMin = 1.0;
				scaleMax = 1.3;
				noSatColor = 0;
			};
			class GrassDry_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassDry_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.6;
				noSatColor = 1;
			};
			class GrassDry2_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassDry2_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.6;
				noSatColor = 1;
			};
			class GrassDry3_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassDry3_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.6;
				noSatColor = 1;
			};
			class GrassDryPlant1_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassDryPlant1_summer.p3d";
				scaleMin = 1.0;
				scaleMax = 1.3;
				noSatColor = 0;
			};
			class GrassDryTall_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassDryTall_summer.p3d";
				affectedByWind = 0.3;
				swLighting = 0;
				scaleMin = 1.0;
				scaleMax = 1.5;
			};
			class GrassDryTall2_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassDryTall2_summer.p3d";
				scaleMin = 1.0;
				scaleMax = 1.5;
				noSatColor = 0;
			};
			class GrassBaseHypericum_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassBaseHypericum_summer.p3d";
				affectedByWind = 0.3;
				swLighting = 0;
				scaleMin = 0.8;
				scaleMax = 1.4;
				noSatColor = 0;
			};
			class GrassBaseCarduus_f_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassBaseCarduus_f_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.4;
				noSatColor = 0;
			};
			class GrassDryHypericum_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassDryHypericum_summer.p3d";
				affectedByWind = 0.3;
				swLighting = 0;
				scaleMin = 0.8;
				scaleMax = 1.4;
				noSatColor = 0;
			};
			class GrassDryCarduus_f_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassDryCarduus_f_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.4;
				noSatColor = 0;
			};
			class GrassCropHypericum_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassCropHypericum_summer.p3d";
				affectedByWind = 0.3;
				swLighting = 0;
				scaleMin = 0.8;
				scaleMax = 1.4;
				noSatColor = 0;
			};
			class GrassCropCarduus_f_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassCropCarduus_f_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.4;
				noSatColor = 0;
			};
			class GrassDryTall3_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassDryTall3_summer.p3d";
				scaleMin = 1.0;
				scaleMax = 1.5;
				noSatColor = 0;
			};
			class GrassSmallConc_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassSmallConc_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.0;
				noSatColor = 0;
			};
			class GrassTinyConc_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassTinyConc_summer.p3d";
				scaleMin = 1.0;
				scaleMax = 1.0;
				noSatColor = 0;
			};
			class Elytrigia_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_Elytrigia_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.6;
				scaleMax = 1.3;
				noSatColor = 0;
			};
			class ElytrigiaGreen_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_Elytrigia_green_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.6;
				scaleMax = 1.3;
				noSatColor = 0;
			};
			class ElytrigiaTall_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_ElytrigiaTall_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.8;
				scaleMax = 1.6;
				noSatColor = 0;
			};
			class ElytrigiaTall2_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_ElytrigiaTall2_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.8;
				scaleMax = 1.6;
				noSatColor = 0;
			};
			class GrassFlowersWhite_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassFlowersWhite_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.6;
				scaleMax = 1.2;
				noSatColor = 0;
			};
			class GrassFlowersWhiteShort_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassFlowersWhiteShort_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.6;
				scaleMax = 1.2;
				noSatColor = 0;
			};
			class GrassFlowersWhiteTall_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassFlowersWhiteTall_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.6;
				scaleMax = 1.4;
				noSatColor = 0;
			};
			class GrassFlowersYellow_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassFlowersYellow_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.4;
				scaleMax = 1.4;
				noSatColor = 0;
			};
			class GrassFlowersYellowShort_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassFlowersYellowShort_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.4;
				scaleMax = 1.4;
				noSatColor = 0;
			};
			class GrassFlowersYellowTall_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassFlowersYellowTall_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.4;
				scaleMax = 1.0;
				noSatColor = 0;
			};
			class GrassFlowersPurple_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassFlowersPurple_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.6;
				scaleMax = 0.8;
				noSatColor = 0;
			};
			class GrassFlowersPurpleShort_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassFlowersPurpleShort_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.6;
				scaleMax = 0.8;
				noSatColor = 0;
			};
			class GrassFlowersPurpleTall_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_GrassFlowersPurpleTall_summer.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.6;
				scaleMax = 0.8;
				noSatColor = 0;
			};
			class Wheat2_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_wheat2.p3d";
				affectedByWind = 0.2;
				scaleMin = 0.4;
				scaleMax = 1.8;
				noSatColor = 1;
			};
			class ConcreteGrass_summer: DefaultClutter
			{
				model = "DZ\plants_bliss\clutter\c_ConcreteGrass_bunch_summer.p3d";
				scaleMin = 0.4;
				scaleMax = 1.2;
				noSatColor = 1;
			};
			class DirtGrass_summer: DefaultClutter
			{
				model = "DZ\plants_bliss\clutter\c_DirtGrass_bunch_summer.p3d";
				scaleMin = 0.4;
				scaleMax = 1.2;
				noSatColor = 0;
			};
			class ElytrigiaDirt_summer: DefaultClutter
			{
				model = "dz\plants_bliss\clutter\c_ElytrigiaDirt_summer.p3d";
				scaleMin = 0.8;
				scaleMax = 1.3;
				noSatColor = 0;
			};
		};
	};
};
class CfgSurfaceCharacters
{
	class en_dirt
	{
		probability[] = {};
		names[] = {};
	};
	class en_grass1
	{
		probability[] = {0.425,0.4,0.05,0.04,0.04,0.02,0.02,0.005};
		names[] = {"Elytrigia_summer","ElytrigiaGreen_summer","ElytrigiaTall2_summer","GrassBaseHypericum_summer","GrassBaseCarduus_f_summer","GrassFlowersWhiteShort_summer","GrassFlowersYellowShort_summer","GrassFlowersPurpleShort_summer"};
	};
	class en_grass2
	{
		probability[] = {0.375,0.075,0.3,0.15,0.03,0.02,0.01,0.02,0.01,0.005,0.005};
		names[] = {"GrassDry2_summer","GrassDry3_summer","ElytrigiaGreen_summer","GrassDryHypericum_summer","GrassDryCarduus_f_summer","GrassFlowersWhiteShort_summer","GrassFlowersWhite_summer","GrassFlowersYellowShort_summer","GrassFlowersYellow_summer","GrassFlowersPurpleShort_summer","GrassFlowersPurple_summer"};
	};
	class en_flowers1
	{
		probability[] = {0.1,0.05,0.05,0.025,0.0,0.0,0.2,0.275,0.2,0.03,0.04,0.04,0.002,0.03,0.0125};
		names[] = {"Elytrigia_summer","ElytrigiaGreen_summer","ElytrigiaTall_summer","ElytrigiaTall3_summer","GrassBaseHypericum_summer","GrassBaseCarduus_f_summer","GrassFlowersWhiteShort_summer","GrassFlowersWhite_summer","GrassFlowersWhiteTall_summer","GrassFlowersYellowShort_summer","GrassFlowersYellow_summer","GrassFlowersYellowTall_summer","GrassFlowersPurpleShort_summer","GrassFlowersPurple_summer","GrassFlowersPurpleTall_summer"};
	};
	class en_flowers2
	{
		probability[] = {0.1,0.05,0.05,0.025,0.0,0.0,0.03,0.04,0.04,0.2,0.275,0.2,0.002,0.03,0.0125};
		names[] = {"Elytrigia_summer","ElytrigiaGreen_summer","ElytrigiaTall_summer","ElytrigiaTall3_summer","GrassBaseHypericum_summer","GrassBaseCarduus_f_summer","GrassFlowersWhiteShort_summer","GrassFlowersWhite_summer","GrassFlowersWhiteTall_summer","GrassFlowersYellowShort_summer","GrassFlowersYellow_summer","GrassFlowersYellowTall_summer","GrassFlowersPurpleShort_summer","GrassFlowersPurple_summer","GrassFlowersPurpleTall_summer"};
	};
	class en_flowers3
	{
		probability[] = {0.1,0.05,0.05,0.025,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.25,0.325,0.25};
		names[] = {"Elytrigia_summer","ElytrigiaGreen_summer","ElytrigiaTall_summer","ElytrigiaTall3_summer","GrassBaseHypericum_summer","GrassBaseCarduus_f_summer","GrassFlowersWhiteShort_summer","GrassFlowersWhite_summer","GrassFlowersWhiteTall_summer","GrassFlowersYellowShort_summer","GrassFlowersYellow_summer","GrassFlowersYellowTall_summer","GrassFlowersPurpleShort_summer","GrassFlowersPurple_summer","GrassFlowersPurpleTall_summer"};
	};
	class en_forestCon
	{
		probability[] = {0.325,0.1025,0.1725,0.12,0.03,0.0,0.05,0.2};
		names[] = {"Vaccinium_summer","Fern_summer","FernTall_summer","Twigs","branchesBig_picea_summer","GrassDry_summer","Pines_summer","Cones"};
	};
	class en_forestDec
	{
		probability[] = {0.14,0.14,0.175,0.175,0.0,0.025,0.08,0.025,0.1};
		names[] = {"leaves_dead_summer","leaves_dead_half_summer","plantsSmall1_summer","plantsSmall2_summer","ElytrigiaTall_summer","beech_big_summer","beech_small_summer","beech_mid_summer","branches_deciduous_summer"};
	};
	class en_mud
	{
		probability[] = {};
		names[] = {};
	};
	class en_soil
	{
		probability[] = {0.02,0.175};
		names[] = {"ElytrigiaDirt_summer","DirtGrass_summer"};
	};
	class en_tarmac
	{
		probability[] = {0.05,0.1};
		names[] = {"ElytrigiaDirt_summer","ConcreteGrass_summer"};
	};
	class en_tarmacold
	{
		probability[] = {0.025,0.1};
		names[] = {"ElytrigiaDirt_summer","ConcreteGrass_summer"};
	};
	class en_stubble
	{
		probability[] = {0.05,0.05,0.65,0.1,0.1,0.05};
		names[] = {"GrassCropHypericum_summer","GrassCropCarduus_f_summer","Stubble_summer","Wheat2_summer","WheatTall_summer","ElytrigiaTall_summer"};
	};
	class en_stubbleLow
	{
		probability[] = {0.95,0.025,0.025};
		names[] = {"Stubble_summer","GrassSmallConc_summer","GrassTinyConc_summer"};
	};
	class en_stones
	{
		probability[] = {};
		names[] = {};
	};
};
class CfgSurfaces
{
	class DZ_SurfacesInt;
	class DZ_SurfacesExt;
	class en_grass1: DZ_SurfacesExt
	{
		files = "en_grass1*";
		deflection = 0.1;
		friction = 0.85;
		restitution = 0.4;
		soundEnviron = "grass";
		soundHit = "soft_ground";
		character = "en_Grass1";
		audibility = 0.4;
		footDamage = 0.023;
		class Visible
		{
			prone = 0.2;
			kneel = 0.6;
			stand = 0.8;
		};
		impact = "Hit_Grass";
		isDigable = 1;
		isFertile = 1;
		vpSurface = "Grass";
	};
	class en_grass2: DZ_SurfacesExt
	{
		files = "en_grass2*";
		deflection = 0.1;
		friction = 0.8;
		restitution = 0.38;
		soundEnviron = "grass";
		soundHit = "soft_ground";
		character = "en_Grass2";
		audibility = 0.4;
		footDamage = 0.023;
		class Visible
		{
			prone = 0.1;
			kneel = 0.4;
			stand = 0.75;
		};
		impact = "Hit_Grass";
		isDigable = 1;
		isFertile = 1;
		vpSurface = "Grass";
	};
	class en_flowers1: en_grass2
	{
		files = "en_flowers1*";
		character = "en_flowers1";
	};
	class en_flowers2: en_grass2
	{
		files = "en_flowers2*";
		character = "en_flowers2";
	};
	class en_flowers3: en_grass2
	{
		files = "en_flowers3*";
		character = "en_flowers3";
	};
	class en_forestcon: DZ_SurfacesExt
	{
		files = "en_forest_con*";
		deflection = 0.1;
		friction = 0.75;
		restitution = 0.26;
		soundEnviron = "forest";
		soundHit = "soft_ground";
		character = "en_ForestCon";
		footDamage = 0.058;
		audibility = 0.6;
		class Visible
		{
			prone = 0.1;
			kneel = 0.3;
			stand = 0.5;
		};
		impact = "Hit_Foliage";
		isDigable = 1;
		isFertile = 1;
		vpSurface = "Forest";
	};
	class en_forestdec: DZ_SurfacesExt
	{
		files = "en_forest_dec*";
		deflection = 0.1;
		friction = 0.7;
		restitution = 0.34;
		soundEnviron = "forest";
		soundHit = "soft_ground";
		character = "en_ForestDec";
		footDamage = 0.058;
		audibility = 0.6;
		class Visible
		{
			prone = 0.3;
			kneel = 0.5;
			stand = 0.6;
		};
		impact = "Hit_Foliage";
		isDigable = 1;
		isFertile = 1;
		vpSurface = "Forest";
	};
	class en_soil: DZ_SurfacesExt
	{
		files = "en_soil*";
		deflection = 0.1;
		friction = 0.75;
		restitution = 0.34;
		soundEnviron = "gravel";
		soundHit = "soft_ground";
		character = "en_Soil";
		footDamage = 0.058;
		audibility = 0.8;
		impact = "Hit_Dirt";
		isDigable = 1;
		isFertile = 1;
		vpSurface = "Dirt";
	};
	class en_tarmac: DZ_SurfacesExt
	{
		files = "en_tarmac_ca*";
		deflection = 0.1;
		friction = 0.98;
		restitution = 0.55;
		soundEnviron = "road";
		soundHit = "hard_ground";
		character = "en_Tarmac";
		footDamage = 0.117;
		audibility = 0.9;
		impact = "Hit_Concrete";
		isDigable = 0;
		isFertile = 0;
		vpSurface = "Asphalt";
	};
	class en_tarmacold: DZ_SurfacesExt
	{
		files = "en_tarmac_old*";
		deflection = 0.1;
		friction = 0.98;
		restitution = 0.55;
		soundEnviron = "road";
		soundHit = "hard_ground";
		character = "en_TarmacOld";
		footDamage = 0.117;
		audibility = 0.9;
		impact = "Hit_Concrete";
		isDigable = 0;
		isFertile = 0;
		vpSurface = "Asphalt";
	};
	class en_stubble: DZ_SurfacesExt
	{
		files = "en_stubble*";
		deflection = 0.1;
		friction = 0.75;
		restitution = 0.34;
		soundEnviron = "gravel";
		soundHit = "soft_ground";
		character = "en_Stubble";
		footDamage = 0.058;
		audibility = 0.8;
		impact = "Hit_Dirt";
		isDigable = 1;
		isFertile = 1;
		vpSurface = "Dirt";
	};
	class en_stones: DZ_SurfacesExt
	{
		files = "en_stones*";
		deflection = 0.9;
		friction = 0.86;
		restitution = 0.6;
		soundEnviron = "rock";
		soundHit = "hard_ground";
		character = "en_Stones";
		audibility = 0.9;
		footDamage = 0.234;
		impact = "Hit_Gravel";
		isDigable = 0;
		isFertile = 0;
	};
};
