#define _ARMA_

class CfgPatches
{
	class DZ_UI
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVideoOptions
{
	class Visibility
	{
		minValue = 750;
		maxValue = 5000;
	};
	class ObjectsVisibility
	{
		minValue = 500;
		maxValue = 5000;
	};
	class ShadowsVisibility
	{
		minValue = 50;
		maxValue = 500;
	};
	class HDR
	{
		class Low
		{
			text = "$STR_TERRAIN_50";
			value = 8;
		};
		class Normal
		{
			text = "$STR_TERRAIN_25";
			value = 16;
		};
	};
	class PPAA
	{
		class Disabled
		{
			textMethod = "";
			textQuality = "$STR_DISABLED";
			ppaaType = 0;
			ppaaLevel = 0;
		};
		class FXAALow
		{
			textMethod = "FXAA";
			textQuality = "$STR_TERRAIN_25";
			ppaaType = 1;
			ppaaLevel = 0;
		};
		class FXAANormal
		{
			textMethod = "FXAA";
			textQuality = "$STR_TERRAIN_12_5";
			ppaaType = 1;
			ppaaLevel = 1;
		};
		class FXAAHigh
		{
			textMethod = "FXAA";
			textQuality = "$STR_TERRAIN_6_25";
			ppaaType = 1;
			ppaaLevel = 2;
		};
		class FXAAVeryHigh
		{
			textMethod = "FXAA";
			textQuality = "$STR_TERRAIN_3_125";
			ppaaType = 1;
			ppaaLevel = 3;
		};
		class SMAALow
		{
			textMethod = "SMAA";
			textQuality = "$STR_TERRAIN_25";
			ppaaType = 2;
			ppaaLevel = 0;
		};
		class SMAANormal
		{
			textMethod = "SMAA";
			textQuality = "$STR_TERRAIN_12_5";
			ppaaType = 2;
			ppaaLevel = 1;
		};
		class SMAAHigh
		{
			textMethod = "SMAA";
			textQuality = "$STR_TERRAIN_6_25";
			ppaaType = 2;
			ppaaLevel = 2;
		};
		class SMAAVeryHigh
		{
			textMethod = "SMAA";
			textQuality = "$STR_TERRAIN_3_125";
			ppaaType = 2;
			ppaaLevel = 3;
		};
	};
	class AnisotropicFiltering
	{
		class Disabled
		{
			text = "$STR_DISABLED";
			value = 0;
		};
		class VeryLow
		{
			text = "$STR_TERRAIN_50";
			value = 2;
		};
		class Low
		{
			text = "$STR_TERRAIN_25";
			value = 4;
		};
		class Normal
		{
			text = "$STR_TERRAIN_12_5";
			value = 8;
		};
		class High
		{
			text = "$STR_TERRAIN_6_25";
			value = 12;
		};
		class VeryHigh
		{
			text = "$STR_TERRAIN_3_125";
			value = 16;
		};
	};
	class PiP
	{
		class Disabled
		{
			text = "$STR_DISABLED";
			value = 0;
		};
		class VeryLow
		{
			text = "$STR_TERRAIN_50";
			value = 500;
		};
		class Low
		{
			text = "$STR_TERRAIN_25";
			value = 800;
		};
		class Normal
		{
			text = "$STR_TERRAIN_12_5";
			value = 1000;
		};
		class High
		{
			text = "$STR_TERRAIN_6_25";
			value = 1500;
		};
		class VeryHigh
		{
			text = "$STR_TERRAIN_3_125";
			value = 2000;
		};
	};
	class TextureQuality
	{
		class VeryLow
		{
			text = "$STR_TERRAIN_50";
			mipBias = 3.0;
		};
		class Low
		{
			text = "$STR_TERRAIN_25";
			mipBias = 2.5;
		};
		class Normal
		{
			text = "$STR_TERRAIN_12_5";
			mipBias = 2.0;
		};
		class High
		{
			text = "$STR_TERRAIN_6_25";
			mipBias = 1.5;
		};
		class VeryHigh
		{
			text = "$STR_TERRAIN_3_125";
			mipBias = 1.0;
		};
	};
	class ObjectsQuality
	{
		class VeryLow
		{
			text = "$STR_TERRAIN_50";
			value = 200000;
		};
		class Low
		{
			text = "$STR_TERRAIN_25";
			value = 300000;
		};
		class Normal
		{
			text = "$STR_TERRAIN_12_5";
			value = 500000;
		};
		class High
		{
			text = "$STR_TERRAIN_6_25";
			value = 750000;
		};
		class VeryHigh
		{
			text = "$STR_TERRAIN_3_125";
			value = 1000000;
		};
	};
	class TerrainQuality
	{
		class VeryLow
		{
			text = "$STR_TERRAIN_50";
			terrainGrid = 50.0;
		};
		class Low
		{
			text = "$STR_TERRAIN_25";
			terrainGrid = 25.0;
		};
		class Normal
		{
			text = "$STR_TERRAIN_12_5";
			terrainGrid = "12.5f";
		};
		class High
		{
			text = "$STR_TERRAIN_6_25";
			terrainGrid = "6.25f";
		};
		class VeryHigh
		{
			text = "$STR_TERRAIN_3_125";
			terrainGrid = "3.125f";
		};
	};
	class CloudQuality
	{
		class Disabled
		{
			text = "$STR_DISABLED";
			value = 0;
		};
		class VeryLow
		{
			text = "$STR_TERRAIN_50";
			value = 32;
		};
		class Low
		{
			text = "$STR_TERRAIN_25";
			value = 48;
		};
		class Normal
		{
			text = "$STR_TERRAIN_12_5";
			value = 64;
		};
		class High
		{
			text = "$STR_TERRAIN_6_25";
			value = 96;
		};
		class VeryHigh
		{
			text = "$STR_TERRAIN_3_125";
			value = 128;
		};
	};
	class ShadowQuality
	{
		class Disabled
		{
			text = "$STR_DISABLED";
			shadowType = 0;
			textureSize = 0;
			shaderQuality = 0;
		};
		class VeryLow
		{
			text = "$STR_TERRAIN_50";
			shadowType = 1;
			textureSize = 0;
			shaderQuality = 0;
		};
		class Low
		{
			text = "$STR_TERRAIN_25";
			shadowType = 2;
			textureSize = 1024;
			shaderQuality = 1;
		};
		class Normal
		{
			text = "$STR_TERRAIN_12_5";
			shadowType = 2;
			textureSize = 1024;
			shaderQuality = 2;
		};
		class High
		{
			text = "$STR_TERRAIN_6_25";
			shadowType = 2;
			textureSize = 2048;
			shaderQuality = 2;
		};
		class VeryHigh
		{
			text = "$STR_TERRAIN_3_125";
			shadowType = 2;
			textureSize = 2048;
			shaderQuality = 3;
		};
	};
	class ATOCQuality
	{
		class Disabled
		{
			text = "$STR_DISABLED";
			grass = "false";
			oldTrees = "false";
			newTrees = "false";
			other = "false";
		};
		class Grass: Disabled
		{
			text = "$STR_ATOC_GRASS";
			grass = "true";
			other = "true";
		};
		class NewTree: Disabled
		{
			text = "$STR_ATOC_TREEOA";
			newTrees = "true";
			other = "true";
		};
		class NewTreeGrass: Disabled
		{
			text = "$STR_ATOC_TREEOA_GRASS";
			grass = "true";
			newTrees = "true";
			other = "true";
		};
		class All: Disabled
		{
			text = "$STR_ATOC_TREEOA_TREEA2_GRASS";
			grass = "true";
			oldTrees = "true";
			newTrees = "true";
			other = "true";
		};
	};
	class FSAA
	{
		class Disabled
		{
			text = "$STR_DISABLED";
			value = 0;
		};
		class Low
		{
			text = "$STR_TERRAIN_25";
			value = 1;
		};
		class Normal
		{
			text = "$STR_TERRAIN_12_5";
			value = 2;
		};
		class High
		{
			text = "$STR_TERRAIN_6_25";
			value = 3;
		};
		class VeryHigh
		{
			text = "$STR_TERRAIN_3_125";
			value = 4;
		};
	};
	class PPBloom
	{
		minValue = 0;
		maxValue = 2;
	};
	class PPDOF
	{
		minValue = 0;
		maxValue = 3;
	};
	class PPRotBlur
	{
		minValue = 0;
		maxValue = 2;
	};
	class PPRadialBlur
	{
		minValue = 0;
		maxValue = 2;
	};
	class DefaultSettings
	{
		text = "Default";
		visibility = 1600;
		objectVisibility = 1200;
		shadowVisibility = 100;
		hdr = "Normal";
		ppaa = "Disabled";
		fsaa = "Disabled";
		particles = "Normal";
		dynamicLights = "Normal";
		anisotropicFiltering = "Normal";
		pip = "Normal";
		textureQuality = "Normal";
		objectsQuality = "Normal";
		terrainQuality = "Normal";
		cloudQuality = "Normal";
		shadowQuality = "Normal";
		atocQuality = "All";
		ppBloom = 1;
		ppDOF = 1;
		ppRotBlur = 1;
		ppRadialBlur = 1;
		postProcessQuality = 3;
	};
	class OverallSettings
	{
		class VeryLow: DefaultSettings
		{
			text = "$STR_TERRAIN_50";
			visibility = 1000;
			objectVisibility = 800;
			shadowVisibility = 100;
			hdr = "Normal";
			ppaa = "Disabled";
			fsaa = "Disabled";
			particles = "Low";
			dynamicLights = "VeryLow";
			anisotropicFiltering = "Disabled";
			pip = "VeryLow";
			textureQuality = "VeryLow";
			objectsQuality = "VeryLow";
			terrainQuality = "Low";
			cloudQuality = "VeryLow";
			shadowQuality = "Low";
			atocQuality = "Disabled";
			ppBloom = 0;
			ppDOF = 0;
			ppRotBlur = 0;
			ppRadialBlur = 0;
			postProcessQuality = 0;
		};
		class Low: DefaultSettings
		{
			text = "$STR_TERRAIN_25";
			visibility = 1600;
			objectVisibility = 1300;
			shadowVisibility = 100;
			hdr = "Normal";
			ppaa = "Disabled";
			fsaa = "Disabled";
			particles = "Low";
			dynamicLights = "Low";
			anisotropicFiltering = "Low";
			pip = "Low";
			textureQuality = "Low";
			objectsQuality = "Low";
			terrainQuality = "Low";
			cloudQuality = "Low";
			shadowQuality = "Normal";
			atocQuality = "Disabled";
			ppBloom = 1;
			ppDOF = 1;
			ppRotBlur = 1;
			ppRadialBlur = 1;
			postProcessQuality = 2;
		};
		class Normal: DefaultSettings
		{
			text = "$STR_TERRAIN_12_5";
			visibility = 2200;
			objectVisibility = 1800;
			shadowVisibility = 100;
			hdr = "Normal";
			ppaa = "FXAALow";
			fsaa = "Low";
			particles = "Normal";
			dynamicLights = "Normal";
			anisotropicFiltering = "Normal";
			pip = "Normal";
			textureQuality = "Normal";
			objectsQuality = "Normal";
			terrainQuality = "Normal";
			cloudQuality = "Normal";
			shadowQuality = "Normal";
			atocQuality = "All";
			ppBloom = 1;
			ppDOF = 1;
			ppRotBlur = 1;
			ppRadialBlur = 1;
			postProcessQuality = 3;
		};
		class High: DefaultSettings
		{
			text = "$STR_TERRAIN_6_25";
			visibility = 3000;
			objectVisibility = 2600;
			shadowVisibility = 100;
			hdr = "Normal";
			ppaa = "FXAANormal";
			fsaa = "Normal";
			particles = "High";
			dynamicLights = "High";
			anisotropicFiltering = "High";
			pip = "Normal";
			textureQuality = "High";
			objectsQuality = "Normal";
			terrainQuality = "Normal";
			cloudQuality = "High";
			shadowQuality = "High";
			atocQuality = "All";
			ppBloom = 1;
			ppDOF = 1;
			ppRotBlur = 1;
			ppRadialBlur = 1;
			postProcessQuality = 4;
		};
		class VeryHigh: DefaultSettings
		{
			text = "$STR_TERRAIN_3_125";
			visibility = 3800;
			objectVisibility = 3200;
			shadowVisibility = 100;
			hdr = "Normal";
			ppaa = "FXAAVeryHigh";
			fsaa = "VeryHigh";
			particles = "High";
			dynamicLights = "VeryHigh";
			anisotropicFiltering = "VeryHigh";
			pip = "Normal";
			textureQuality = "VeryHigh";
			objectsQuality = "High";
			terrainQuality = "VeryHigh";
			cloudQuality = "VeryHigh";
			shadowQuality = "VeryHigh";
			atocQuality = "All";
			ppBloom = 1;
			ppDOF = 1;
			ppRotBlur = 1;
			ppRadialBlur = 1;
			postProcessQuality = 5;
		};
	};
};
class CfgLanguages
{
	class Original
	{
		name = "Original";
	};
	class English
	{
		name = "#options_language_EN";
	};
	class French
	{
		name = "#options_language_FR";
	};
	class Spanish
	{
		name = "#options_language_ES";
	};
	class Italian
	{
		name = "#options_language_IT";
	};
	class German
	{
		name = "#options_language_DE";
	};
	class Czech
	{
		name = "#options_language_CZ";
	};
	class Russian
	{
		name = "#options_language_RU";
	};
	class Chinese
	{
		name = "#options_language_CHT";
	};
	class Chinesesimp
	{
		name = "#options_language_CHS";
	};
	class Polish
	{
		name = "#options_language_PL";
	};
	class Japanese
	{
		name = "#options_language_JA";
	};
	class Portuguese
	{
		name = "#options_language_PTBR";
	};
};
