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
	class DZ_Data
	{
		units[] = {"FxWindGrass1","FxWindGrass2","FxWindRock1","FxWindLeaf1","FxWindLeaf2","FxWindLeaf3","FxWindPollen1","FXUSWindLeaf1","FXUSWindLeaf2","FXUSWindLeaf3"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};
class CfgAddons
{
	class PreloadBanks{};
	class PreloadAddons
	{
		class DayZ
		{
			list[] = {"DZ_A_Airport","DZ_Animals","DZ_Animals_AnimConfig","DZ_Animals_Birds","DZ_Animals_Birds_Chicken","DZ_Animals_Birds_Cock","DZ_Animals_Birds_Crow","DZ_Animals_Birds_hawk","DZ_Animals_Birds_Seagull","DZ_Animals_Cow","DZ_Animals_Deer","DZ_Animals_Dogs_Fin","DZ_Animals_Dogs_Pastor","DZ_Animals_Goat","DZ_Animals_Insect","DZ_Animals_Rabbit","DZ_Animals_Rat","DZ_Animals_Sheep","DZ_Animals_WildBoar","DZ_Anims","DZ_Anims_Config_Sdr","DZ_Anims_Config_Wmn","DZ_Anims_Config_Zmb","DZ_Buildings","DZ_Buildings2","DZ_Buildings2_A_Crane_02","DZ_Buildings2_A_GENERALSTORE_01","DZ_Buildings2_A_Pub","DZ_Buildings2_A_Statue","DZ_Buildings2_Barn_Metal","DZ_Buildings2_BuildingParts","DZ_Buildings2_BuildingParts_Signs","DZ_Buildings2_BuildingParts_Signs_TEC","DZ_Buildings2_Church_01","DZ_Buildings2_Farm_Cowshed","DZ_Buildings2_Farm_WTower","DZ_Buildings2_HouseBlocks_HouseBlock_A","DZ_Buildings2_HouseBlocks_HouseBlock_B","DZ_Buildings2_HouseBlocks_HouseBlock_C","DZ_Buildings2_HouseBlocks_HouseBlock_D","DZ_Buildings2_Ind_CementWorks_Ind_Dopravnik","DZ_Buildings2_Ind_CementWorks_Ind_Expedice","DZ_Buildings2_Ind_CementWorks_Ind_MalyKomin","DZ_Buildings2_Ind_CementWorks_Ind_Mlyn","DZ_Buildings2_Ind_CementWorks_Ind_Pec","DZ_Buildings2_Ind_CementWorks_Ind_SiloMale","DZ_Buildings2_Ind_CementWorks_Ind_SiloVelke","DZ_Buildings2_Ind_CementWorks_Ind_Vysypka","DZ_Buildings2_Ind_Garage01","DZ_Buildings2_Ind_Pipeline_IndPipe2","DZ_Buildings2_Ind_Shed_01","DZ_Buildings2_Ind_Shed_02","DZ_Buildings2_Ind_Tank","DZ_Buildings2_Ind_Workshop01","DZ_Buildings2_Misc_Cargo","DZ_Buildings2_Misc_PowerStation","DZ_Buildings2_Misc_WaterStation","DZ_Buildings2_Rail_House_01","DZ_Buildings2_Shed_small","DZ_Buildings2_Shed_wooden","DZ_Characters","DZ_Characters_Backpacks","DZ_Characters_Glasses","DZ_Characters_Gloves","DZ_Characters_Headgear","DZ_Characters_Heads","DZ_Characters_Pants","DZ_Characters_Masks","DZ_Characters_Shoes","DZ_Characters_Tops","DZ_Characters_Vests","DZ_Code","DZ_Data","DZ_Data_Data_ParticleEffects","DZ_Functions","DZ_Gear_Crafting","DZ_Gear_Cooking","DZ_Gear_Consumables","DZ_Gear_Containers","DZ_Gear_Drinks","DZ_Gead_Food","DZ_Gear_Medical","DZ_Gear_Navigation","DZ_Gear_Optics","DZ_Gear_Tools","DZ_Gear_Traps","DZ_Items","DZ_Items_Drinks","DZ_Items_Food","DZ_Items_Medical","DZ_Items_Misc","DZ_Items_Trash","DZ_Items_Weapons","DZ_Misc","DZ_Misc2","DZ_Misc2_Samsite","DZ_Misc3","DZ_Modules","DZ_Roads2","DZ_Roads2_Bridge","DZ_Roads2_Dam","DZ_Rocks2","DZ_Rocks3","DZ_Signs2","DZ_Server_Data","DZ_Spawn_Proxies","DZ_Sounds_Arma2","DZ_Sounds_Mod","DZ_Sounds_Effects","DZ_Structures","DZ_Structures_A_BuildingWIP","DZ_Structures_A_CraneCon","DZ_Structures_A_MunicipalOffice","DZ_Structures_A_TVTower","DZ_Structures_Barn_W","DZ_Structures_Castle","DZ_Structures_Furniture","DZ_Structures_Houses","DZ_Structures_House_A_FuelStation","DZ_Structures_House_A_Hospital","DZ_Structures_House_A_Office01","DZ_Structures_House_A_Office02","DZ_Structures_House_A_StationHouse","DZ_Structures_House_Church_02","DZ_Structures_House_Church_03","DZ_Structures_House_Church_05R","DZ_Structures_House_HouseBT","DZ_Structures_House_HouseV","DZ_Structures_House_HouseV2","DZ_Structures_House_Street_Booth","DZ_Structures_Ind","DZ_Structures_Ind_Pipeline_IndPipe1","DZ_Structures_Ind_Quarry","DZ_Structures_Ind_SawMill","DZ_Structures_Mil","DZ_Structures_Misc","DZ_Structures_Misc_Powerlines","DZ_Structures_NAV","DZ_Structures_Nav_Boathouse","DZ_Structures_Nav_Pier","DZ_Structures_Pond","DZ_Structures_Rail","DZ_Structures_Rail_Rail_Station_big","DZ_Structures_Rail_Railway","DZ_Structures_Ruins","DZ_Structures_Shed_Ind","DZ_Structures_Shed_Shed_Small","DZ_Structures_Tenement","DZ_Structures_Wall","DZ_Structures_Ship_Wreck","DZ_UI","DZ_UIFonts","DZ_UIFonts_CoreConfigOverwrite","DZ_Vehicles_Tracked","DZ_Vehicles_Wheeled","DZ_Vehicles_Wheeled_Datsun_Armed","DZ_Vehicles_Wheeled_Hilux_Armed","DZ_Vehicles_Wrecks","DZ_Weapons_Attachments_Data","DZ_Weapons_Magazines","DZ_Weapons_Lights","DZ_Weapons_Muzzles","DZ_Weapons_Optics","DZ_Weapons_Supports","DZ_Weapons_Animations","DZ_Weapons_Ammunition","DZ_Weapons_Firearms","DZ_Weapons_Firearms_Winchester70","DZ_Weapons_Firearms_SVD","DZ_Weapons_Melee","DZ_Weapons_Melee_Blunt","DZ_Weapons_Melee_Blade","DZ_Weapons_Melee_Powered","DZ_Weapons_Misc","DZ_Weapons_Explosives","DZ_Weapons_Firearms_aug","DZ_Weapons_Firearms_M4","DZ_Weapons_Firearms_MosinNagant","DZ_Weapons_Firearms_SKS","DZ_Weapons_Firearms_Ruger1022","DZ_Weapons_Pistols_1911","DZ_Weapons_Pistols_Cz75","DZ_Weapons_Pistols_Fnx45","DZ_Weapons_Pistols_Magnum","DZ_Weapons_Pistols_Mkii","DZ_Weapons_Projectiles","DZ_Weapons_Shotguns","DZ_Worlds_Chernarusplus_World","DZ_Worlds_Test_Terrain"};
		};
	};
};
class CfgWorlds
{
	initWorld = "ChernarusPlus";
	class DefaultLighting
	{
		access = 0;
		groundReflection[] = {0.085,0.068,0.034};
		moonObjectColorFull[] = {0.9,0.9,1.0,0.2};
		moonHaloObjectColorFull[] = {0.9,0.9,1.0,0.01};
		moonsetObjectColor[] = {0.9,0.75,0.4};
		moonsetHaloObjectColor[] = {0.9,0.5,0.2};
		nightAngle = 5;
		sunSunset = 20;
		endSunset = 10;
	};
	class DefaultWorld
	{
		class Weather
		{
			class Overcast
			{
				class Weather1;
				class Weather2;
				class Weather3;
				class Weather4;
				class Weather5;
			};
		};
	};
	class CAWorld: DefaultWorld
	{
		class Weather: Weather
		{
			class LightingNew
			{
				class C_Night
				{
					height = 0;
					overcast = 0.35;
					sunAngle = -18;
					sunOrMoon = 0.0;
					diffuse[] = {0.1,0.15,0.3};
					diffuseCloud[] = {0.1,0.15,0.3};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.032,0.06,0.096};
					ambientCloud[] = {0.032,0.06,0.096};
					groundReflection[] = {0.004,0.0072,0.012};
					groundReflectionCloud[] = {0.004,0.0072,0.012};
					sky[] = {0.018,0.028,0.043};
					skyAroundSun[] = {0.018,0.028,0.043};
					desiredLuminanceCoef = 0.12;
					desiredLuminanceCoefCloud = 0.12;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Astro1
				{
					height = 0;
					overcast = 0.35;
					sunAngle = -17;
					sunOrMoon = 0.5;
					diffuse[] = {0.0,0.0,0.0};
					diffuseCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.008,0.0158,0.024};
					ambientCloud[] = {0.008,0.0158,0.024};
					groundReflection[] = {0.004,0.0072,0.012};
					groundReflectionCloud[] = {0.004,0.0072,0.012};
					sky[] = {0.036,0.056,0.087};
					skyAroundSun[] = {0.036,0.056,0.087};
					desiredLuminanceCoef = 0.12;
					desiredLuminanceCoefCloud = 0.12;
					EVMin = -2.0;
					EVMax = 0.5;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Astro2
				{
					height = 0;
					overcast = 0.35;
					sunAngle = -16;
					sunOrMoon = 1.0;
					diffuse[] = {0.0,0.0,0.0};
					diffuseCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.032,0.0632,0.096};
					ambientCloud[] = {0.032,0.0632,0.096};
					groundReflection[] = {0.008,0.0144,0.024};
					groundReflectionCloud[] = {0.008,0.0144,0.024};
					sky[] = {0.036,0.056,0.087};
					skyAroundSun[] = {0.1011,0.1063,0.0926};
					desiredLuminanceCoef = 0.12;
					desiredLuminanceCoefCloud = 0.12;
					EVMin = -2.0;
					EVMax = 0.5;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Astro3
				{
					height = 0;
					overcast = 0.35;
					sunAngle = -14;
					sunOrMoon = 1.0;
					diffuse[] = {0.0,0.0,0.0};
					diffuseCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.032,0.0632,0.096};
					ambientCloud[] = {0.032,0.0632,0.096};
					groundReflection[] = {0.008,0.0144,0.024};
					groundReflectionCloud[] = {0.008,0.0144,0.024};
					sky[] = {0.1,0.14,0.22};
					skyAroundSun[] = {0.3035,0.319,0.278};
					desiredLuminanceCoef = 0.12;
					desiredLuminanceCoefCloud = 0.12;
					EVMin = -2.0;
					EVMax = 0.5;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Nautical1
				{
					height = 0;
					overcast = 0.35;
					sunAngle = -12;
					sunOrMoon = 1.0;
					diffuse[] = {0.0,0.0,0.0};
					diffuseCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.064,0.1264,0.192};
					ambientCloud[] = {0.064,0.1264,0.192};
					groundReflection[] = {0.016,0.0288,0.048};
					groundReflectionCloud[] = {0.016,0.0288,0.048};
					sky[] = {0.15,0.21,0.34};
					skyAroundSun[] = {0.6039,0.5411,0.4509};
					desiredLuminanceCoef = 0.16;
					desiredLuminanceCoefCloud = 0.16;
					EVMin = -2.0;
					EVMax = 0.5;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Nautical2
				{
					height = 0;
					overcast = 0.35;
					sunAngle = -10;
					sunOrMoon = 1.0;
					diffuse[] = {0.1011,0.1063,0.0926};
					diffuseCloud[] = {0.1011,0.1063,0.0926};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.128,0.2528,0.384};
					ambientCloud[] = {0.128,0.2528,0.384};
					groundReflection[] = {0.016,0.0288,0.048};
					groundReflectionCloud[] = {0.016,0.0288,0.048};
					sky[] = {0.15,0.21,0.34};
					skyAroundSun[] = {0.8039,0.5411,0.4509};
					desiredLuminanceCoef = 0.16;
					desiredLuminanceCoefCloud = 0.16;
					EVMin = -2.0;
					EVMax = 0.5;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Nautical3
				{
					height = 0;
					overcast = 0.35;
					sunAngle = -8;
					sunOrMoon = 1.0;
					diffuse[] = {0.2311,0.2112,0.184};
					diffuseCloud[] = {0.2311,0.2112,0.184};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.128,0.2528,0.384};
					ambientCloud[] = {0.128,0.2528,0.384};
					groundReflection[] = {0.032,0.0572,0.096};
					groundReflectionCloud[] = {0.032,0.0572,0.096};
					sky[] = {0.15,0.21,0.34};
					skyAroundSun[] = {0.8039,0.5411,0.4509};
					desiredLuminanceCoef = 0.22;
					desiredLuminanceCoefCloud = 0.22;
					EVMin = -2.0;
					EVMax = 0.5;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Civil1
				{
					height = 0;
					overcast = 0.35;
					sunAngle = -6;
					sunOrMoon = 1.0;
					diffuse[] = {0.346,0.1803,0.0836};
					diffuseCloud[] = {0.346,0.1803,0.0836};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.128,0.2528,0.384};
					ambientCloud[] = {0.128,0.2528,0.384};
					groundReflection[] = {0.032,0.0572,0.096};
					groundReflectionCloud[] = {0.032,0.0572,0.096};
					sky[] = {0.3,0.225,0.327};
					skyAroundSun[] = {0.939,0.5411,0.2509};
					desiredLuminanceCoef = 0.28;
					desiredLuminanceCoefCloud = 0.28;
					EVMin = -2.0;
					EVMax = 0.5;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Civil2
				{
					height = 0;
					overcast = 0.35;
					sunAngle = -4;
					sunOrMoon = 1.0;
					diffuse[] = {{0.446,0.1803,0.0836},0.2};
					diffuseCloud[] = {{0.446,0.1803,0.0836},0.2};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {{0.128,0.2528,0.384},0.1};
					ambientCloud[] = {{0.128,0.2528,0.384},0.1};
					groundReflection[] = {0.064,0.1144,0.192};
					groundReflectionCloud[] = {0.064,0.1144,0.192};
					sky[] = {{0.6,0.549,0.745},0.5};
					skyAroundSun[] = {{0.939,0.5411,0.2509},1.5};
					desiredLuminanceCoef = 0.35;
					desiredLuminanceCoefCloud = 0.35;
					EVMin = -2.0;
					EVMax = 0.2;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Civil3
				{
					height = 0;
					overcast = 0.35;
					sunAngle = -2;
					sunOrMoon = 1.0;
					diffuse[] = {1.3,0.404,0.294};
					diffuseCloud[] = {1.3,0.404,0.294};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.2,0.23,0.45};
					ambientCloud[] = {0.2,0.23,0.45};
					groundReflection[] = {0.032,0.0572,0.096};
					groundReflectionCloud[] = {0.032,0.0572,0.096};
					sky[] = {0.8,0.64,1};
					skyAroundSun[] = {1.239,0.4411,0.2509};
					desiredLuminanceCoef = 0.37;
					desiredLuminanceCoefCloud = 0.37;
					EVMin = -2.0;
					EVMax = 0.2;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Day0
				{
					height = 0;
					overcast = 0.35;
					sunAngle = 0;
					sunOrMoon = 1.0;
					diffuse[] = {1.3,0.404,0.294};
					diffuseCloud[] = {1.3,0.404,0.294};
					bidirect[] = {0.03,0.03,0.03};
					bidirectCloud[] = {0.03,0.03,0.03};
					ambient[] = {0.2,0.23,0.45};
					ambientCloud[] = {0.2,0.23,0.45};
					groundReflection[] = {0.032,0.0572,0.096};
					groundReflectionCloud[] = {0.032,0.0572,0.096};
					sky[] = {1.2,0.64,1};
					skyAroundSun[] = {3.5,1.64,1};
					desiredLuminanceCoef = 0.4;
					desiredLuminanceCoefCloud = 0.4;
					EVMin = -2.0;
					EVMax = 0.1;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Day4
				{
					height = 0;
					overcast = 0.35;
					sunAngle = 4;
					sunOrMoon = 1;
					diffuse[] = {{1.2,0.404,0.294},7.4};
					diffuseCloud[] = {{1.2,0.404,0.294},7.4};
					bidirect[] = {0.03,0.03,0.03};
					bidirectCloud[] = {0.03,0.03,0.03};
					ambient[] = {{0.2,0.23,0.45},7.2};
					ambientCloud[] = {{0.2,0.23,0.45},7.2};
					groundReflection[] = {{0.2,0.23,0.45},3.4};
					groundReflectionCloud[] = {{0.2,0.23,0.45},3.4};
					sky[] = {{1.2,0.64,1},7.0};
					skyAroundSun[] = {{2.2,1.24,1},8.2};
					desiredLuminanceCoef = 0.45;
					desiredLuminanceCoefCloud = 0.45;
					EVMin = -2.0;
					EVMax = 0.1;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Day8
				{
					height = 0;
					overcast = 0.35;
					sunAngle = 8;
					sunOrMoon = 1;
					diffuse[] = {{1.0,0.604,0.294},10.4};
					diffuseCloud[] = {{1.0,0.604,0.294},10.4};
					bidirect[] = {0.03,0.03,0.03};
					bidirectCloud[] = {0.03,0.03,0.03};
					ambient[] = {{0.12,0.18,0.28},10.2};
					ambientCloud[] = {{0.12,0.18,0.28},10.2};
					groundReflection[] = {{0.12,0.18,0.28},7.4};
					groundReflectionCloud[] = {{0.12,0.18,0.28},7.4};
					sky[] = {{0.5,0.64,1},10.4};
					skyAroundSun[] = {{1.2,0.674,0.294},11};
					desiredLuminanceCoef = 0.5;
					desiredLuminanceCoefCloud = 0.5;
					EVMin = -2.0;
					EVMax = 0.1;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Day12
				{
					height = 0;
					overcast = 0.35;
					sunAngle = 12;
					sunOrMoon = 1;
					diffuse[] = {{1.0,0.64,0.31},11.4};
					diffuseCloud[] = {{1.0,0.64,0.31},11.4};
					bidirect[] = {0.03,0.03,0.03};
					bidirectCloud[] = {0.03,0.03,0.03};
					ambient[] = {{0.12,0.18,0.28},10.6};
					ambientCloud[] = {{0.12,0.18,0.28},10.6};
					groundReflection[] = {{0.12,0.18,0.28},8.1};
					groundReflectionCloud[] = {{0.12,0.18,0.28},8.1};
					sky[] = {{0.5,0.64,1},10.8};
					skyAroundSun[] = {{1.0,0.874,0.494},11.4};
					desiredLuminanceCoef = 0.53;
					desiredLuminanceCoefCloud = 0.53;
					EVMin = -2.0;
					EVMax = 0.1;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Day16
				{
					height = 0;
					overcast = 0.35;
					sunAngle = 16;
					sunOrMoon = 1;
					diffuse[] = {{1,0.87,0.85},11.8};
					diffuseCloud[] = {{1,0.87,0.85},11.8};
					bidirect[] = {0.08,0.08,0.07};
					bidirectCloud[] = {0.08,0.08,0.07};
					ambient[] = {{0.12,0.18,0.24},10.4};
					ambientCloud[] = {{0.12,0.18,0.24},10.4};
					groundReflection[] = {{0.12,0.18,0.24},8.1};
					groundReflectionCloud[] = {{0.12,0.18,0.24},8.1};
					sky[] = {{0.5,0.64,1},11.0};
					skyAroundSun[] = {{1.0,1.0,1.0},11.2};
					desiredLuminanceCoef = 0.56;
					desiredLuminanceCoefCloud = 0.56;
					EVMin = -2.0;
					EVMax = 0.1;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Day35
				{
					height = 0;
					overcast = 0.35;
					sunAngle = 35;
					sunOrMoon = 1;
					diffuse[] = {{1,0.87,0.85},12.8};
					diffuseCloud[] = {{1,0.87,0.85},12.8};
					bidirect[] = {0.08,0.08,0.07};
					bidirectCloud[] = {0.08,0.08,0.07};
					ambient[] = {{0.12,0.18,0.24},11.0};
					ambientCloud[] = {{0.12,0.18,0.24},11.0};
					groundReflection[] = {{0.12,0.18,0.24},8.0};
					groundReflectionCloud[] = {{0.12,0.18,0.24},8.0};
					sky[] = {{0.7,0.84,1},11.7};
					skyAroundSun[] = {{1.0,1.0,1.0},12.5};
					desiredLuminanceCoef = 0.62;
					desiredLuminanceCoefCloud = 0.62;
					EVMin = -2.0;
					EVMax = 0.2;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class C_Day60
				{
					height = 0;
					overcast = 0.35;
					sunAngle = 60;
					sunOrMoon = 1;
					diffuse[] = {{1,0.87,0.85},13.8};
					diffuseCloud[] = {{1,0.87,0.85},13.8};
					bidirect[] = {0.08,0.08,0.07};
					bidirectCloud[] = {0.08,0.08,0.07};
					ambient[] = {{0.12,0.18,0.24},11.8};
					ambientCloud[] = {{0.12,0.18,0.24},11.8};
					groundReflection[] = {{0.12,0.18,0.24},7.8};
					groundReflectionCloud[] = {{0.12,0.18,0.24},7.8};
					sky[] = {{0.7,0.84,1},12.6};
					skyAroundSun[] = {{1.0,1.0,1.0},13.0};
					desiredLuminanceCoef = 0.66;
					desiredLuminanceCoefCloud = 0.66;
					EVMin = -2.0;
					EVMax = 0.2;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Night
				{
					height = 0;
					overcast = 0.65;
					sunAngle = -18;
					sunOrMoon = 0.0;
					diffuse[] = {0.0,0.0,0.0};
					diffuseCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.036,0.057,0.085};
					ambientCloud[] = {0.036,0.057,0.085};
					groundReflection[] = {0.005,0.005,0.0075};
					groundReflectionCloud[] = {0.005,0.005,0.0075};
					sky[] = {0.01,0.01,0.01};
					skyAroundSun[] = {0.01,0.01,0.01};
					desiredLuminanceCoef = 0.08;
					desiredLuminanceCoefCloud = 0.08;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Astro1
				{
					height = 0;
					overcast = 0.65;
					sunAngle = -17;
					sunOrMoon = 0.5;
					diffuse[] = {0.0,0.0,0.0};
					diffuseCloud[] = {0.0,0.0,0.0};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.036,0.057,0.085};
					ambientCloud[] = {0.036,0.057,0.085};
					groundReflection[] = {0.01,0.01,0.015};
					groundReflectionCloud[] = {0.01,0.01,0.015};
					sky[] = {0.01,0.01,0.01};
					skyAroundSun[] = {0.01,0.01,0.01};
					desiredLuminanceCoef = 0.08;
					desiredLuminanceCoefCloud = 0.08;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Nautical1
				{
					height = 0;
					overcast = 0.65;
					sunAngle = -12;
					sunOrMoon = 1.0;
					diffuse[] = {0.036,0.057,0.085};
					diffuseCloud[] = {0.036,0.057,0.085};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.036,0.057,0.085};
					ambientCloud[] = {0.036,0.057,0.085};
					groundReflection[] = {0.01,0.01,0.015};
					groundReflectionCloud[] = {0.01,0.01,0.015};
					sky[] = {0.036,0.056,0.087};
					skyAroundSun[] = {0.1011,0.1063,0.0926};
					desiredLuminanceCoef = 0.15;
					desiredLuminanceCoefCloud = 0.15;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Civil1
				{
					height = 0;
					overcast = 0.65;
					sunAngle = -6;
					sunOrMoon = 1;
					diffuse[] = {0.018,0.018,0.018};
					diffuseCloud[] = {0.018,0.018,0.018};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.1,0.18,0.29};
					ambientCloud[] = {0.1,0.18,0.29};
					groundReflection[] = {0.01,0.01,0.015};
					groundReflectionCloud[] = {0.01,0.01,0.015};
					sky[] = {0.1,0.14,0.22};
					skyAroundSun[] = {0.1,0.14,0.22};
					desiredLuminanceCoef = 0.25;
					desiredLuminanceCoefCloud = 0.25;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Civil2
				{
					height = 0;
					overcast = 0.65;
					sunAngle = -2;
					sunOrMoon = 1;
					diffuse[] = {0.018,0.018,0.018};
					diffuseCloud[] = {0.018,0.018,0.018};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.145,0.227,0.349};
					ambientCloud[] = {0.145,0.227,0.349};
					groundReflection[] = {0.01,0.01,0.015};
					groundReflectionCloud[] = {0.01,0.01,0.015};
					sky[] = {0.1,0.14,0.22};
					skyAroundSun[] = {0.1,0.14,0.22};
					desiredLuminanceCoef = 0.3;
					desiredLuminanceCoefCloud = 0.3;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Day0
				{
					height = 0;
					overcast = 0.65;
					sunAngle = 0;
					sunOrMoon = 1;
					diffuse[] = {0.27,0.27,0.27};
					diffuseCloud[] = {0.27,0.27,0.27};
					bidirect[] = {0.0,0.0,0.0};
					bidirectCloud[] = {0.0,0.0,0.0};
					ambient[] = {0.145,0.227,0.349};
					ambientCloud[] = {0.145,0.227,0.349};
					groundReflection[] = {0.02,0.02,0.03};
					groundReflectionCloud[] = {0.02,0.02,0.03};
					sky[] = {0.1,0.14,0.16};
					skyAroundSun[] = {0.1,0.14,0.16};
					desiredLuminanceCoef = 0.3;
					desiredLuminanceCoefCloud = 0.3;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Day4
				{
					height = 0;
					overcast = 0.65;
					sunAngle = 4;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.29},4.4};
					diffuseCloud[] = {{0.27,0.27,0.29},4.4};
					bidirect[] = {0.13,0.13,0.13};
					bidirectCloud[] = {0.13,0.13,0.13};
					ambient[] = {{0.145,0.227,0.349},5.4};
					ambientCloud[] = {{0.145,0.227,0.349},5.4};
					groundReflection[] = {{0.145,0.227,0.349},2.4};
					groundReflectionCloud[] = {{0.145,0.227,0.349},2.4};
					sky[] = {{1.0,1.0,1.0},4.415};
					skyAroundSun[] = {{1.0,1.0,1.0},4.799};
					desiredLuminanceCoef = 0.32;
					desiredLuminanceCoefCloud = 0.32;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Day8
				{
					height = 0;
					overcast = 0.65;
					sunAngle = 8;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.3},7.4};
					diffuseCloud[] = {{0.27,0.27,0.3},7.4};
					bidirect[] = {0.13,0.13,0.13};
					bidirectCloud[] = {0.13,0.13,0.13};
					ambient[] = {{0.145,0.227,0.349},8.1};
					ambientCloud[] = {{0.145,0.227,0.349},8.1};
					groundReflection[] = {{0.145,0.227,0.349},6.1};
					groundReflectionCloud[] = {{0.145,0.227,0.349},6.1};
					sky[] = {{1.0,1.0,1.0},8.0};
					skyAroundSun[] = {{1.0,1.0,1.0},8.8};
					desiredLuminanceCoef = 0.35;
					desiredLuminanceCoefCloud = 0.35;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Day12
				{
					height = 0;
					overcast = 0.65;
					sunAngle = 12;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.3},8.2};
					diffuseCloud[] = {{0.27,0.27,0.3},8.2};
					bidirect[] = {0.13,0.13,0.13};
					bidirectCloud[] = {0.13,0.13,0.13};
					ambient[] = {{0.145,0.227,0.349},10.1};
					ambientCloud[] = {{0.145,0.227,0.349},10.1};
					groundReflection[] = {{0.145,0.227,0.349},7.1};
					groundReflectionCloud[] = {{0.145,0.227,0.349},7.1};
					sky[] = {{1.0,1.0,1.0},9.0};
					skyAroundSun[] = {{1.0,1.0,1.0},9.8};
					desiredLuminanceCoef = 0.37;
					desiredLuminanceCoefCloud = 0.37;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Day35
				{
					height = 0;
					overcast = 0.65;
					sunAngle = 35;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.3},9.4};
					diffuseCloud[] = {{0.27,0.27,0.3},9.4};
					bidirect[] = {0.23,0.23,0.23};
					bidirectCloud[] = {0.23,0.23,0.23};
					ambient[] = {{0.15,0.2,0.25},11.1};
					ambientCloud[] = {{0.15,0.2,0.25},11.1};
					groundReflection[] = {{0.15,0.2,0.25},8.1};
					groundReflectionCloud[] = {{0.15,0.2,0.25},8.1};
					sky[] = {{1,1,1},11};
					skyAroundSun[] = {{1,1,1},11.8};
					desiredLuminanceCoef = 0.4;
					desiredLuminanceCoefCloud = 0.4;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
				class O_Day60
				{
					height = 0;
					overcast = 0.65;
					sunAngle = 60;
					sunOrMoon = 1;
					diffuse[] = {{0.27,0.27,0.3},10.4};
					diffuseCloud[] = {{0.27,0.27,0.3},10.4};
					bidirect[] = {0.33,0.33,0.33};
					bidirectCloud[] = {0.33,0.33,0.33};
					ambient[] = {{0.2,0.24,0.29},12.4};
					ambientCloud[] = {{0.2,0.24,0.29},12.4};
					groundReflection[] = {{0.2,0.24,0.29},8.4};
					groundReflectionCloud[] = {{0.2,0.24,0.29},8.4};
					sky[] = {{1,1,1},12};
					skyAroundSun[] = {{1,1,1},12.8};
					desiredLuminanceCoef = 0.45;
					desiredLuminanceCoefCloud = 0.45;
					EVMin = -2.0;
					EVMax = 0.0;
					filmGrainIntensity = 0.0;
					luminanceRectCoef = 0.0;
					luminanceRectCoefCloud = 0.0;
					rayleigh[] = {0.0,0.0,0.0};
					mie[] = {0.0,0.0,0.0};
					cloudsColor[] = {0.0,0.0,0.0};
					swBrightness = 0;
				};
			};
			class VolFog
			{
				CameraFog = 0.0;
				Item1[] = {800.0,0.06,0.93,0.13,1.0};
				Item2[] = {1300.0,0.02,0.9,0.05,1.0};
			};
			class Overcast: Overcast
			{
				class Weather1: Weather1
				{
					overcast = 0.0;
					lightingOvercast = 0.0;
					sky = "DZ\data\data\sky_clear_sky.paa";
					skyR = "DZ\data\data\sky_clear_lco.paa";
					horizon = "DZ\data\data\sky_clear_horizont_sky.paa";
					alpha = 0.0;
					bright = 0.0;
					speed = 0.1;
					size = 0.5;
					height = 1.0;
					through = 0.45;
					diffuse = 1.0;
					cloudDiffuse = 1.0;
					waves = 0.0;
				};
				class Weather2: Weather2
				{
					overcast = 0.3;
					lightingOvercast = 0.3;
					sky = "DZ\data\data\sky_almostclear_sky.paa";
					skyR = "DZ\data\data\sky_almostclear_lco.paa";
					horizon = "DZ\data\data\sky_almostclear_horizont_sky.paa";
					alpha = 0.1;
					bright = 0.6;
					speed = 0.3;
					size = 0.55;
					height = 0.9;
					through = 0.2;
					diffuse = 1.0;
					cloudDiffuse = 1.0;
					waves = 0.0;
				};
				class Weather3: Weather3
				{
					overcast = 0.5;
					lightingOvercast = 0.5;
					sky = "DZ\data\data\sky_semicloudy_sky.paa";
					skyR = "DZ\data\data\sky_semicloudy_lco.paa";
					horizon = "DZ\data\data\sky_semicloudy_horizont_sky.paa";
					alpha = 0.25;
					bright = 0.6;
					speed = 0.5;
					size = 0.65;
					height = 0.85;
					through = 0.1;
					diffuse = 1.0;
					cloudDiffuse = 1.0;
					waves = 0.0;
				};
				class Weather4: Weather4
				{
					overcast = 0.7;
					lightingOvercast = 0.7;
					sky = "DZ\data\data\sky_cloudy_sky.paa";
					skyR = "DZ\data\data\sky_cloudy_lco.paa";
					horizon = "DZ\data\data\sky_cloudy_horizont_sky.paa";
					alpha = 0.35;
					bright = 0.4;
					speed = 0.75;
					size = 0.85;
					height = 0.8;
					through = 0.1;
					diffuse = 1.0;
					cloudDiffuse = 1.0;
					waves = 0.0;
				};
				class Weather5: Weather5
				{
					overcast = 1.01;
					lightingOvercast = 1.0;
					sky = "DZ\data\data\sky_mostlycloudy_sky.paa";
					skyR = "DZ\data\data\sky_mostlycloudy_lco.paa";
					horizon = "DZ\data\data\sky_mostlycloudy_horizont_sky.paa";
					alpha = 0.35;
					bright = 0.2;
					speed = 0.8;
					size = 1.0;
					height = 0.75;
					through = 0.0;
					diffuse = 1.0;
					cloudDiffuse = 1.0;
					waves = 0.0;
				};
			};
		};
		envTexture = "DZ\Data\data\env_co.paa";
		clouds[] = {"DZ\Data\data\mrak1.p3d","DZ\Data\data\mrak2.p3d","DZ\Data\data\mrak3.p3d","DZ\Data\data\mrak4.p3d"};
		skyObject = "DZ\Data\data\obloha.p3d";
		starsObject = "DZ\Data\data\stars.p3d";
		pointObject = "DZ\Data\data\point.p3d";
		horizontObject = "DZ\Data\data\horizont.p3d";
		haloObject = "DZ\Data\data\sunHalo.p3d";
		sunObject = "DZ\Data\data\sun.p3d";
		rainbowObject = "DZ\Data\data\rainbow.p3d";
		moonObject = "DZ\Data\data\moon.p3d";
		mapDisplayNameKey = "#STR_CfgVehicles_ChernarusMap0";
		mapDescriptionKey = "#STR_CfgVehicles_ChernarusMap1";
		mapTextureClosed = "dz\gear\navigation\data\map_chernarus_co.paa";
		mapTextureOpened = "dz\structures\signs\tourist\data\karta_co.paa";
		mapTextureLegend = "dz\structures\signs\tourist\data\karta_side_co.paa";
		starsIntensity = 0.181;
		hazeDistCoef = 0.0;
		hazeFogCoef = 1.0;
		volFogOffset = 0;
		rainMaterial = "{AD76A616D0EF1ABC}Graphics/Materials/postprocess/rain.emat";
		satelliteNormalBlendStart = 100;
		satelliteNormalBlendEnd = 500;
		flareMinDistance = 2.0;
		flareMinDistanceLerp = 1.0;
		farLightSpotMul = 2.0;
		farLightPointMul = 2.0;
		minTreesInForestSquare = 10;
		minRocksInRockSquare = 5;
		soundMapAttenCoef = 0.01;
		class SoundMapValues
		{
			treehard = 0.03;
			treesoft = 0.03;
			bushhard = 0.0;
			bushsoft = 0.0;
			forest = 1.0;
			house = 0.3;
			church = 0.5;
		};
		class Sounds
		{
			sounds[] = {};
		};
		class Subdivision
		{
			class Fractal
			{
				rougness = 5;
				maxRoad = 0.02;
				maxTrack = 0.5;
				maxSlopeFactor = 0.05;
			};
			class WhiteNoise
			{
				rougness = 2;
				maxRoad = 0.01;
				maxTrack = 0.05;
				maxSlopeFactor = 0.0025;
			};
			minY = -0.0;
			minSlope = 0.02;
		};
	};
};
class CfgMaterials
{
	class Water
	{
		PixelShaderID = "Water";
		VertexShaderID = "Water";
		ambient[] = {0.07058824,0.17254902,0.14509805,0.4};
		diffuse[] = {0.07058824,0.17254902,0.14509805,1};
		forcedDiffuse[] = {0.0264,0.03,0.013,0};
		specular[] = {1.5,1.5,1.5,0};
		specularPower = 4;
		emmisive[] = {0,0,0,0};
		class Stage1
		{
			texture = "DZ\Data\data\water_nofhq.paa";
			uvSource = "texWaterAnim";
			class uvTransform
			{
				aside[] = {0,1,0};
				up[] = {1,0,0};
				dir[] = {0,0,1};
				pos[] = {0.3,0.4,0};
			};
		};
		class Stage2
		{
			texture = "DZ\Data\data\sea_foam_lco.paa";
			uvSource = "none";
		};
		class Stage3
		{
			texture = "DZ\Data\data\water2_nohq.paa";
			uvSource = "none";
		};
	};
	class Shore
	{
		PixelShaderID = "Shore";
		VertexShaderID = "Shore";
		ambient[] = {0.07058824,0.17254902,0.14509805,0.4};
		diffuse[] = {0.07058824,0.17254902,0.14509805,1};
		forcedDiffuse[] = {0.0264,0.03,0.013,0};
		specular[] = {1.5,1.5,1.5,0};
		specularPower = 4;
		emmisive[] = {0,0,0,0};
		class Stage1
		{
			texture = "DZ\Data\data\water_nofhq.paa";
			uvSource = "texWaterAnim";
			class uvTransform
			{
				aside[] = {0,1,0};
				up[] = {0.1,0,0};
				dir[] = {0,0,1};
				pos[] = {0.3,0.4,0};
			};
		};
		class Stage2
		{
			texture = "DZ\Data\data\sea_foam_lco.paa";
			uvSource = "none";
		};
		class Stage3
		{
			texture = "DZ\Data\data\water2_nohq.paa";
			uvSource = "none";
		};
	};
	class ShoreWet
	{
		PixelShaderID = "ShoreWet";
		VertexShaderID = "Shore";
	};
};
class CfgDifficulties
{
	class Recruit
	{
		displayName = "Recruit";
		scoreImage = "#(argb,8,8,3)color(1,1,1,1)";
		badScoreImage = "#(argb,8,8,3)color(1,1,1,1)";
		skillFriendly = 1;
		precisionFriendly = 1;
		skillEnemy = 0.55;
		precisionEnemy = 0.3;
		myArmorCoef = 4.0;
		peripheralVisionAid = 0.85;
		visionAid = 0.85;
		class Flags
		{
			friendlyTag[] = {0,1};
			tracers[] = {1,1};
			unlimitedSaves[] = {1,1};
			roughLanding[] = {1,1};
			windEnabled[] = {0,1};
			autoTrimEnabled[] = {1,1};
			stressDamageEnabled[] = {0,1};
		};
		overviewText = "";
		overviewPicture = "";
	};
	class Regular
	{
		displayName = "Regular";
		scoreImage = "#(argb,8,8,3)color(1,1,1,1)";
		badScoreImage = "#(argb,8,8,3)color(1,1,1,1)";
		skillFriendly = 1;
		precisionFriendly = 1;
		skillEnemy = 0.7;
		precisionEnemy = 0.5;
		peripheralVisionAid = 0.75;
		visionAid = 0;
		class Flags
		{
			friendlyTag[] = {0,1};
			tracers[] = {1,1};
			roughLanding[] = {0,1};
			windEnabled[] = {1,1};
			autoTrimEnabled[] = {1,1};
			stressDamageEnabled[] = {1,1};
		};
		overviewText = "";
		overviewPicture = "";
	};
	class Veteran
	{
		displayName = "Veteran";
		scoreImage = "#(argb,8,8,3)color(1,1,1,1)";
		badScoreImage = "#(argb,8,8,3)color(1,1,1,1)";
		skillFriendly = 1.0;
		precisionFriendly = 1.0;
		skillEnemy = 0.9;
		precisionEnemy = 0.75;
		myArmorCoef = 1.0;
		groupArmorCoef = 1.0;
		autoAimSizeFactor = 0.3;
		autoAimDistance = 0.6;
		autoAimAngle = 2.5;
		peripheralVisionAid = 0.65;
		class Flags
		{
			hudWpPerm[] = {0,0};
			map[] = {0,1};
			clockIndicator[] = {0,1};
			tracers[] = {0,0};
			unlimitedSaves[] = {0,1};
			deathMessages[] = {1,1};
			hudGroupInfo[] = {0,1};
			roughLanding[] = {0,0};
			windEnabled[] = {1,0};
			autoTrimEnabled[] = {0,0};
			stressDamageEnabled[] = {1,0};
		};
		overviewText = "";
		overviewPicture = "";
	};
};
class cfgCharacterCreation
{
	format = "Survivor%1_%2";
	gender[] = {"Female","Male"};
	personalityMale[] = {"Mirek","Boris","Cyril","Denis","Elias","Francis","Guo","Hassan","Indar","Jose","Kaito","Lewis","Manua","Niki","Oliver","Peter","Quinn","Rolf","Seth","Taiki"};
	personalityFemale[] = {"Eva","Frida","Gabi","Helga","Irena","Judy","Keiko","Linda","Maria","Naomi"};
	top[] = {"TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_OrangeWhiteStripes","TShirt_Red","TShirt_RedBlackStripes","TShirt_White","TShirt_Grey"};
	bottom[] = {"CanvasPantsMidi_Beige","CanvasPantsMidi_Blue","CanvasPantsMidi_Grey","CanvasPantsMidi_Red","CanvasPantsMidi_Violet"};
	shoe[] = {"AthleticShoes_Black","AthleticShoes_Blue","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey"};
	maleCustom[] = {};
	femaleCustom[] = {};
};
class cfgCharacterScenes
{
	class ChernarusPlus
	{
		class loc1
		{
			target[] = {7134.12,2673.46,6.97};
			position[] = {7132.96,2665.93,0.84};
			fov = 0.5236;
			date[] = {1984,10,28,14,27};
			overcast = 0.25;
			rain = 0;
			fog = 0.15;
		};
		class loc2
		{
			target[] = {7096.13,14656.38,357.13};
			position[] = {7099.73,14654.77,0.92};
			fov = 0.5236;
			date[] = {1984,10,28,8,27};
			overcast = 0.25;
			rain = 0;
			fog = 0.15;
		};
		class loc3
		{
			target[] = {1522.94,13624.13,441.36};
			position[] = {1527.19,13623.92,0.92};
			fov = 0.5236;
			date[] = {1984,10,28,9,7};
			overcast = 0.25;
			rain = 0;
			fog = 0.15;
		};
		class loc4
		{
			target[] = {6974.89,3521.69,39.97};
			position[] = {6976.64,3523.85,0.93};
			fov = 0.5236;
			date[] = {1984,7,28,8,7};
			overcast = 0.25;
			rain = 0;
			fog = 0.15;
		};
		class loc5
		{
			target[] = {11487.63,10652.17,163.68};
			position[] = {11493.24,10652.59,0.93};
			fov = 0.5236;
			date[] = {1984,7,28,8,47};
			overcast = 0.25;
			rain = 0;
			fog = 0.15;
		};
	};
	class sampleMap
	{
		class default
		{
			target[] = {60497.79,-79032.57,-39.78};
			position[] = {2887.08,2704.82,1.23};
			fov = 0.491;
			date[] = {3000,6,1,12,11};
			aperture = 18;
		};
	};
	class sampleMap3: sampleMap{};
	class sampleMap4: sampleMap{};
};
class cfgLiquidDefinitions
{
	class Water
	{
		type = 512;
		displayName = "$STR_cfgLiquidDefinitions_Water0";
		flammability = -10;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 0;
			water = 100;
			nutritionalIndex = 75;
			toxicity = -0.01;
			digestibility = 2;
		};
	};
	class RiverWater
	{
		type = 1024;
		displayName = "$STR_cfgLiquidDefinitions_RiverWater0";
		flammability = -10;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 0;
			water = 100;
			nutritionalIndex = 75;
			toxicity = -0.01;
			digestibility = 2;
		};
	};
	class Disinfectant
	{
		type = 32768;
		displayName = "$STR_cfgLiquidDefinitions_Disinfectant0";
		flammability = 10;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = -10;
			water = 1;
			nutritionalIndex = 55;
			toxicity = 0.3;
			digestibility = 2;
			agents = 16;
		};
	};
	class Vodka
	{
		type = 2048;
		displayName = "$STR_cfgLiquidDefinitions_Vodka0";
		flammability = 10;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 231;
			water = 15;
			nutritionalIndex = 75;
			toxicity = 0.05;
			digestibility = 2;
		};
	};
	class Beer
	{
		type = 4096;
		displayName = "$STR_cfgLiquidDefinitions_Beer0";
		flammability = 0;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 43;
			water = 100;
			nutritionalIndex = 75;
			toxicity = 0.01;
			digestibility = 2;
		};
	};
	class Gasoline
	{
		type = 8192;
		displayName = "$STR_cfgLiquidDefinitions_Gasoline0";
		flammability = 50;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 5;
			water = 0;
			nutritionalIndex = 75;
			toxicity = 1;
			digestibility = 2;
			agents = 16;
		};
	};
	class Diesel
	{
		type = 16384;
		displayName = "$STR_cfgLiquidDefinitions_Diesel0";
		flammability = 50;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = -10;
			water = 0;
			nutritionalIndex = 75;
			toxicity = 1;
			digestibility = 2;
			agents = 16;
		};
	};
	class Saline
	{
		type = 256;
		displayName = "$STR_cfgLiquidDefinitions_Saline0";
		flammability = -10;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 0;
			water = 0;
			nutritionalIndex = 75;
			toxicity = 0.1;
			digestibility = 2;
		};
	};
	class Blood_0Positive
	{
		type = 1;
		displayName = "$STR_cfgLiquidDefinitions_Blood_0Positive0";
		flammability = 50;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 5;
			water = 30;
			nutritionalIndex = 55;
			toxicity = 0.1;
			digestibility = 2;
		};
	};
	class Blood_0Negative
	{
		type = 2;
		displayName = "$STR_cfgLiquidDefinitions_Blood_0Negative0";
		flammability = 50;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 5;
			water = 30;
			nutritionalIndex = 55;
			toxicity = 0.1;
			digestibility = 2;
		};
	};
	class Blood_APositive
	{
		type = 4;
		displayName = "$STR_cfgLiquidDefinitions_Blood_APositive0";
		flammability = 50;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 5;
			water = 30;
			nutritionalIndex = 55;
			toxicity = 0.1;
			digestibility = 2;
		};
	};
	class Blood_ANegative
	{
		type = 8;
		displayName = "$STR_cfgLiquidDefinitions_Blood_ANegative0";
		flammability = 50;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 5;
			water = 30;
			nutritionalIndex = 55;
			toxicity = 0.1;
			digestibility = 2;
		};
	};
	class Blood_BPositive
	{
		type = 16;
		displayName = "$STR_cfgLiquidDefinitions_Blood_BPositive0";
		flammability = 50;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 5;
			water = 30;
			nutritionalIndex = 55;
			toxicity = 0.1;
			digestibility = 2;
		};
	};
	class Blood_BNegative
	{
		type = 32;
		displayName = "$STR_cfgLiquidDefinitions_Blood_BNegative0";
		flammability = 50;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 5;
			water = 30;
			nutritionalIndex = 55;
			toxicity = 0.1;
			digestibility = 2;
		};
	};
	class Blood_ABPositive
	{
		type = 64;
		displayName = "$STR_cfgLiquidDefinitions_Blood_ABPositive0";
		flammability = 50;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 5;
			water = 30;
			nutritionalIndex = 55;
			toxicity = 0.1;
			digestibility = 2;
		};
	};
	class Blood_ABNegative
	{
		type = 128;
		displayName = "$STR_cfgLiquidDefinitions_Blood_ABNegative0";
		flammability = 50;
		class Nutrition
		{
			fullnessIndex = 1;
			energy = 5;
			water = 30;
			nutritionalIndex = 55;
			toxicity = 0.1;
			digestibility = 2;
		};
	};
};
class CfgMods
{
	class DayZ
	{
		dir = "DZ";
		picture = "DZ\ui\data\logos\dayz_ca";
		action = "http://www.dayzgame.com";
		hideName = 1;
		hidePicture = 1;
		name = "DayZ";
		credits = "BIS_fnc_credits_H";
		author = "Bohemia Interactive";
	};
};
class DefaultEventhandlers
{
	init = "_scr = _this execVM ""\dz\Data\data\ParticleEffects\SCRIPTS\init.sqf"";";
	fired = "_this call BIS_Effects_EH_Fired;";
	killed = "_this call BIS_Effects_EH_Killed;";
};
class CfgVehicleClasses
{
	class People
	{
		displayName = "People";
	};
	class Zombie
	{
		displayName = "Zombies";
	};
	class Vehicles_Car
	{
		displayName = "Cars";
	};
	class Vehicles_Truck
	{
		displayName = "Trucks";
	};
	class Vehicles_Bicycle
	{
		displayName = "Bicycle";
	};
	class Vehicles_Motorbike
	{
		displayName = "Motorbikes";
	};
	class Vehicles_Boat
	{
		displayName = "Boats";
	};
	class Vehicles_Ship
	{
		displayName = "Ships";
	};
	class Vehicles_Helicopter
	{
		displayName = "Helicopters";
	};
	class Vehicles_Plane
	{
		displayName = "Planes";
	};
	class Clothing
	{
		displayName = "Clothing";
	};
	class Backpacks
	{
		displayName = "Backpacks";
	};
	class Ammoboxes
	{
		displayName = "Ammoboxes";
	};
	class Test
	{
		displayName = "Test";
	};
	class Buildings
	{
		displayName = "Buildings";
	};
	class Ruins
	{
		displayName = "Ruins";
	};
	class Fortifications
	{
		displayName = "$STR_DN_OBJECTS_FORTIFICATIONS";
	};
	class Furniture
	{
		displayName = "$STR_DN_FURNITURE";
	};
	class Military
	{
		displayName = "$STR_DN_MILITARY";
	};
	class Misc
	{
		displayName = "$STR_DN_MISC";
	};
	class Signs
	{
		displayName = "$STR_DN_SIGNS";
	};
	class Targets
	{
		displayName = "$STR_DN_TARGETS";
	};
	class Training
	{
		displayName = "$STR_DN_TRAINING";
	};
	class Wrecks
	{
		displayName = "$STR_DN_WRECKS";
	};
	class Dead_bodies
	{
		displayName = "Dead bodies";
	};
	class Small_items
	{
		displayName = "Small items";
	};
};
class CfgCoreData
{
	textureDefault = "dz\Data\data\default_co.paa";
	textureTrack = "dz\Data\data\texturetrack_ca.paa";
	textureTrackFour = "dz\Data\data\texturetrackfour_ca.paa";
	maskTextureFlare = "dz\Data\data\masktextureflare%02d_co.paa";
	eyeFlare = "dz\Data\data\eyeflare_ca.paa";
	heatHazeNoise = "dz\Data\data\heathaze_ca.paa";
	cloudletBasic = "dz\Data\data\cl_basic.p3d";
	cloudletFire = "dz\Data\data\cl_fire.p3d";
	cloudletFireD = "dz\Data\data\cl_fireD.p3d";
	cloudletFireNew = "dz\Data\data\Fire_4x4.p3d";
	cloudletWater = "dz\Data\data\cl_water.p3d";
	paperCarModel = "dz\Data\data\papauto.p3d";
	collisionShape = "dz\Data\data\colision.p3d";
	sphereModel = "dz\Data\data\koule.p3d";
	rectangleModel = "dz\Data\data\rect.p3d";
	craterShell = "dz\Data\data\krater.p3d";
	craterBullet = "dz\Data\data\krater_po_kulce.p3d";
	sphereLight = "dz\Data\data\kouleSvetlo.p3d";
	cloudletMissile = "dz\Data\data\missileSmoke.p3d";
	horizontObject = "dz\Data\data\horizont.p3d";
	skysphere = "dz\Data\data\obloha.p3d";
	halflight = "dz\Data\data\halfLight.p3d";
	footStepL = "dz\Data\data\stopa_L.p3d";
	footStepR = "dz\Data\data\stopa_P.p3d";
	slopBlood = "dz\Data\data\krvava_skvrna.p3d";
	textureBlack = "dz\Data\data\black_co.paa";
	textureLine = "dz\Data\data\tracer_co.paa";
	textureLine3D = "dz\Data\data\textureline3d_ca.paa";
	cobraLight = "dz\Data\data\cobraSvetlo.p3d";
	gunLightModel = "dz\Data\data\gunLight.p3d";
	marker = "dz\Data\data\obrysove svetlo.p3d";
	rayModel = "dz\Data\data\laserBeam.p3d";
};
class CfgCloudletShapes
{
	cloudletBlood = "\dz\Data\data\cl_water.p3d";
	cloudletClouds = "\dz\Data\data\cl_basic.p3d";
	cloudletDust = "\dz\Data\data\cl_basic.p3d";
	cloudletExplosion = "\dz\Data\data\cl_basic.p3d";
	cloudletFire = "\dz\Data\data\cl_fireD.p3d";
	cloudletMissile = "\dz\Data\data\cl_basic.p3d";
	cloudletSmoke = "\dz\Data\data\cl_basic.p3d";
	cloudletUniversal = "\dz\Data\data\ParticleEffects\Universal\Universal.p3d";
	cloudletWater = "\dz\Data\data\cl_water.p3d";
	cloudletUniversal_02 = "\dz\data\data\ParticleEffects\Universal\Universal_02";
};
class CfgOpticsEffect
{
	class TankGunnerOptics1
	{
		type = "ColorCorrections";
		priority = 1550;
		params[] = {1,1,0,0,0,0,0,1,1.0,0.2,0.6,0.199,0.587,0.114,0};
	};
	class TankGunnerOptics2
	{
		type = "ColorCorrections";
		priority = 1550;
		params[] = {1,1,0,0,0,0,0,1,1.0,0.2,0.8,0.199,0.25,0.114,0};
	};
	class TankCommanderOptics1
	{
		type = "FilmGrain";
		priority = 2050;
		params[] = {0.05,1,1,0.35,1,0};
	};
	class OpticsInverted
	{
		type = "colorInversion";
		priority = 2550;
		params[] = {1,1,1};
	};
	class BWTV
	{
		type = "ColorCorrections";
		priority = 1550;
		params[] = {1,2,-0.03,0.0,0.0,0.0,0.0,1.0,1.0,1.0,0.0,0.199,0.587,0.114,0.0};
	};
	class WeaponsOptics
	{
		type = "dynamicblur";
		priority = 450;
		params[] = {0.05};
	};
	class OpticsBlur1
	{
		type = "dynamicblur";
		priority = 450;
		params[] = {0.0025};
	};
	class OpticsBlur2
	{
		type = "dynamicblur";
		priority = 450;
		params[] = {0.005};
	};
	class OpticsBlur3
	{
		type = "dynamicblur";
		priority = 450;
		params[] = {0.01};
	};
	class OpticsCHAbera1
	{
		type = "chromaberration";
		priority = 250;
		params[] = {0.004,0.004,1};
	};
	class OpticsCHAbera2
	{
		type = "chromaberration";
		priority = 250;
		params[] = {0.006,0.006,1};
	};
	class OpticsCHAbera3
	{
		type = "chromaberration";
		priority = 250;
		params[] = {0.008,0.008,1};
	};
};
class CfgNoMipmapTextures
{
	NoMipmapTextures = "\dz\data\data\NoMipmapTextures.p3d";
};
class PreloadTextures
{
	class CfgCloudletShapes
	{
		cloudletSmoke = "@*";
		cloudletWater = "@*";
		cloudletFire = "@*";
		cloudletUniversal = "@*";
	};
	class CfgNoMipmapTextures
	{
		NoMipmapTextures = "@*";
	};
};
class PreloadVehicles
{
	class MediumTent
	{
		loadStyle = 2;
	};
	class MediumTent_Green
	{
		loadStyle = 2;
	};
	class MediumTent_Orange
	{
		loadStyle = 2;
	};
	class LargeTent
	{
		loadStyle = 2;
	};
	class CarTent
	{
		loadStyle = 2;
	};
	class PartyTent
	{
		loadStyle = 2;
	};
	class PartyTent_Blue
	{
		loadStyle = 2;
	};
	class PartyTent_Brown
	{
		loadStyle = 2;
	};
	class PartyTent_Lunapark
	{
		loadStyle = 2;
	};
	class Watchtower
	{
		loadStyle = 2;
	};
	class Fence
	{
		loadStyle = 2;
	};
	class Sedan_02
	{
		loadStyle = 2;
	};
	class Sedan_02_Red
	{
		loadStyle = 2;
	};
	class Sedan_02_Grey
	{
		loadStyle = 2;
	};
	class OffroadHatchback
	{
		loadStyle = 2;
	};
	class OffroadHatchback_Blue
	{
		loadStyle = 2;
	};
	class OffroadHatchback_White
	{
		loadStyle = 2;
	};
	class Hatchback_02
	{
		loadStyle = 2;
	};
	class Hatchback_02_Black
	{
		loadStyle = 2;
	};
	class Hatchback_02_Blue
	{
		loadStyle = 2;
	};
	class CivilianSedan
	{
		loadStyle = 2;
	};
	class CivilianSedan_Wine
	{
		loadStyle = 2;
	};
	class CivilianSedan_Black
	{
		loadStyle = 2;
	};
};
class CfgVehicles
{
	class All
	{
		clothingType = "";
		itemsCargoSize[] = {};
		HeadAimDown = 0;
		author = "dayz";
		maxCargo = 0;
	};
	class AllVehicles: All
	{
		htMin = 60;
		htMax = 1800;
		afMax = 200;
		mfMax = 100;
		mFact = 0;
		tBody = 0;
		driverFreelook = 1;
	};
	class Man: AllVehicles
	{
		minFireTime = 5;
		extCameraPosition[] = {0.15,0,-2.0};
	};
	class Man_Base: Man{};
	class DZ_LightAI_old: Man
	{
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
	};
	class DZ_LightAI: Man_Base
	{
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
	};
	class Air: AllVehicles
	{
		class AnimationSources;
		accuracy = 0;
		irScanRangeMin = 500;
		class MarkerLights
		{
			class WhiteStill
			{
				name = "bily pozicni";
				color[] = {0.0388,0.0388,0.0388,1.0};
				ambient[] = {0.03,0.023,0.0056,1.0};
				radius = 0.001;
				blinking = 0;
			};
			class RedStill
			{
				name = "cerveny pozicni";
				color[] = {0.12,0.006,0.006,1.0};
				ambient[] = {0.1,0.01,0.01,1.0};
				radius = 0.001;
				blinking = 0;
			};
			class GreenStill
			{
				name = "zeleny pozicni";
				color[] = {0.006,0.12,0.006,1.0};
				ambient[] = {0.01,0.1,0.01,1.0};
				radius = 0.001;
				blinking = 0;
			};
			class WhiteBlinking
			{
				name = "bily pozicni blik";
				color[] = {0.0388,0.0388,0.0388,1.0};
				ambient[] = {0.03,0.023,0.0056,1.0};
				radius = 0.001;
				blinking = 1;
			};
			class RedBlinking
			{
				name = "cerveny pozicni blik";
				color[] = {0.12,0.006,0.006,1.0};
				ambient[] = {0.1,0.01,0.01,1.0};
				radius = 0.001;
				blinking = 1;
			};
		};
	};
	class Static: All{};
	class Building: Static{};
	class Strategic: Building{};
	class FlagCarrierCore: Strategic{};
	class NonStrategic: Building{};
	class NonStrategic_Base: NonStrategic
	{
		animated = 0;
	};
	class House: Static
	{
		scope = 1;
		ladders[] = {};
		simulation = "house";
		nameSound = "obj_building";
		displayName = "House";
		irTarget = 0;
		accuracy = 0.1;
		destrType = "DestructBuilding";
	};
	class HouseNoDestruct: House
	{
		displayName = "";
		animated = 0;
		destrType = "DestructNo";
		storageCategory = 7;
	};
	class HouseHighCost: House
	{
		displayName = "STRUCTUR HIGH COST";
	};
	class Ruins: House
	{
		vehicleClass = "Ruins";
		destrType = "DestructNo";
	};
	class Inventory_Base: Static
	{
		scope = 0;
		displayName = "";
		model = "";
		descriptionShort = "...";
		simulation = "inventoryItem";
		physLayer = "item_small";
		storageCategory = 1;
		weight = 1000;
		heavyItem = 0;
		itemSize[] = {1,1};
		attachments[] = {};
		repairableWithKits[] = {0};
		repairCosts[] = {0.0};
		ragQuantity = 0;
		fragility = 0.1;
		inventoryCondition = "true";
		inventorySlot[] = {""};
		cargoClass = "";
		targetCategory = "";
		itemInfo[] = {};
		absorbency = 0;
		heatIsolation = 0;
		heatReduction = 0;
		coldReduction = 0;
		slopeTolerance = 0.05;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = {10,10,10};
		spawnDamageRange[] = {0.0,0.6};
		canBeSplit = 0;
		stackedUnit = "pc.";
		quantity = "";
		quantityShow = 1;
		quantityBar = 0;
		animated = 0;
		reversed = 1;
		vehicleClass = "Inventory";
		mapSize = 1;
		supplyRadius = 1.4;
		hiddenSelections[] = {};
		hiddenSelectionsTextures[] = {};
		recoilModifier[] = {1,1,1};
		isMeleeWeapon = 1;
		soundImpactType = "default";
		destroyOnEmpty = 1;
		varQuantityDestroyOnMin = 1;
		varWetInit = 0;
		varWetMin = 0;
		varWetMax = 1;
		varTemperatureInit = 0;
		varTemperatureMin = 0;
		varTemperatureMax = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
		};
		class Protection
		{
			biological = 0;
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeFist";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeFist_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeFist_Heavy";
				range = 2.8;
			};
		};
	};
	class ExplosionTest: HouseNoDestruct
	{
		scope = 2;
		model = "\DZ\data\lightpoint.p3d";
		ammoType = "Explosion_NonLethal";
	};
	class Container_Base: Inventory_Base
	{
		storageCategory = 1;
		openable = 0;
		armAction = "Disarm";
	};
	class WorldContainer_Base: Inventory_Base
	{
		storageCategory = 1;
		inventoryCondition = "false";
		openable = 0;
		itemsCargoSize[] = {5,8};
	};
	class Powered_Base: Inventory_Base
	{
		displayName = "Powered Item Base";
		descriptionShort = "Should not be in inventory.";
		attachments[] = {"BatteryD"};
		energyResources[] = {{"power",8.0}};
	};
	class Edible_Base: Inventory_Base
	{
		armAction = "Disarm";
		spawnOffset = 0;
		trashItem = "";
		varQuantityInit = 1000;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		stackedUnit = "g";
		quantityBar = 1;
	};
	class Trap_Base: Inventory_Base
	{
		itemSize[] = {2,2};
		isMeleeWeapon = 0;
	};
	class Grenade_Base: Inventory_Base
	{
		absorbency = 0.5;
		itemSize[] = {1,2};
		inventorySlot[] = {"VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD","tripWireAttachment"};
	};
	class Book_Base: Inventory_Base
	{
		simulation = "ItemBook";
		model = "\DZ\gear\books\Book_kniga.p3d";
		inventorySlot[] = {"Book"};
		itemSize[] = {2,2};
		absorbency = 0.9;
		hiddenSelections[] = {"camoGround"};
		hiddenSelectionsTextures[] = {"dz\gear\books\data\book_kniga_co.paa"};
	};
	class FishingRod_Base: Inventory_Base
	{
		scope = 0;
	};
	class Clothing_Base: Inventory_Base
	{
		scope = 0;
		simulation = "clothing";
		itemInfo[] = {"Clothing"};
		visibilityModifier = 1.0;
		allowOwnedCargoManipulation = 1;
		soundVoiceType = "none";
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
				class Melee
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
				class FragGrenade
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
		};
	};
	class Switchable_Base: Powered_Base{};
	class Box_Base: Inventory_Base
	{
		iconType = 0;
		isMeleeWeapon = 1;
	};
	class Bottle_Base: Edible_Base
	{
		storageCategory = 1;
		canBeSplit = 0;
		quantityBar = 1;
		stackedRandom = 1;
		stackedUnit = "ml";
		itemSize[] = {1,2};
		varLiquidTypeInit = 512;
	};
	class ItemOptics: Inventory_Base
	{
		scope = 1;
		simulation = "itemoptics";
		selectionFireAnim = "zasleh";
		class AnimationSources
		{
			class hide
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
	};
	class SurrenderDummyItem: Inventory_Base
	{
		scope = 1;
		model = "\DZ\data\lightpoint.p3d";
		weight = 1;
	};
	class Thing;
	class ThingEffectLight;
	class ThingEffectFeather;
	class FxWindGrass1: ThingEffectLight
	{
		scope = 1;
		model = "\dz\data\data\cl_grass1.p3d";
		displayName = "Internal: FxWindGrass1";
		airRotation = 0.45;
	};
	class FxWindGrass2: ThingEffectLight
	{
		scope = 1;
		model = "\dz\data\data\cl_grass2.p3d";
		displayName = "Internal: FxWindGrass2";
		airRotation = 0.3;
	};
	class FxWindRock1: ThingEffectLight
	{
		scope = 1;
		model = "\dz\data\data\cl_rock1.p3d";
		displayName = "Internal: FxWindRock1";
		airFriction2[] = {1,1,1};
		airFriction1[] = {0.5,0.5,0.5};
		airFriction0[] = {0.05,0.05,0.05};
		airRotation = 0.7;
		minHeight = 0.05;
		avgHeight = 0.1;
		maxHeight = 0.15;
	};
	class FxWindLeaf1: ThingEffectLight
	{
		scope = 1;
		model = "\dz\data\data\cl_leaf.p3d";
		displayName = "Internal: FxWindLeaf1";
		airFriction2[] = {2,2,8};
		airFriction1[] = {1,1,4};
		airFriction0[] = {0.3,0.3,0.1};
		airRotation = 0.35;
		minHeight = 0.3;
		avgHeight = 1.5;
		maxHeight = 3.0;
	};
	class FxWindLeaf2: FxWindLeaf1
	{
		model = "\dz\data\data\cl_leaf2.p3d";
		displayName = "Internal: FxWindLeaf2";
	};
	class FxWindLeaf3: FxWindLeaf1
	{
		model = "\dz\data\data\cl_leaf3.p3d";
		displayName = "Internal: FxWindLeaf3";
	};
	class FXCrWindLeaf1: ThingEffectLight
	{
		scope = 1;
		model = "\dz\data\data\cr_leaf.p3d";
		displayName = "Internal: FxCrWindLeaf1";
		airFriction2[] = {2,2,8};
		airFriction1[] = {1,1,4};
		airFriction0[] = {0.3,0.3,0.1};
		airRotation = 0.35;
		minHeight = 0.3;
		avgHeight = 5.5;
		maxHeight = 10.0;
	};
	class FXCrWindLeaf2: FXCrWindLeaf1
	{
		model = "\dz\data\data\cr_leaf2.p3d";
		displayName = "Internal: FxCrWindLeaf2";
	};
	class FXCrWindLeaf3: FXCrWindLeaf1
	{
		model = "\dz\data\data\cr_leaf3.p3d";
		displayName = "Internal: FxCrWindLeaf3";
	};
	class FxWindPollen1: ThingEffectFeather
	{
		scope = 1;
		model = "\dz\data\data\cl_feathers2.p3d";
		displayName = "Internal: FxWindPollen1";
	};
	class FXUSWindLeaf1: ThingEffectLight
	{
		scope = 1;
		model = "\dz\data\cr_leaf.p3d";
		displayName = "Internal: FxUSWindLeaf1";
		airFriction2[] = {2,2,8};
		airFriction1[] = {1,1,4};
		airFriction0[] = {0.3,0.3,0.1};
		airRotation = 0.35;
		minHeight = 0.3;
		avgHeight = 5.5;
		maxHeight = 10.0;
	};
	class FXUSWindLeaf2: FXUSWindLeaf1
	{
		model = "\dz\data\cr_leaf2.p3d";
		displayName = "Internal: FxUSWindLeaf2";
	};
	class FXUSWindLeaf3: FXUSWindLeaf1
	{
		model = "\dz\data\cr_leaf3.p3d";
		displayName = "Internal: FxUSWindLeaf3";
	};
	class TestObject: Inventory_Base
	{
		scope = 2;
		model = "\DZ\gear\drinks\SodaCan.p3d";
	};
};
class CfgNonAIVehicles
{
	class StaticObject;
	class Plant: StaticObject
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
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
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class Mode_Safe: Mode_SemiAuto
{
	magazines[] = {};
};
class cfgAmmoTypes
{
	class AType_Arrow_Composite
	{
		name = "Arrow_Composite";
	};
	class AType_Arrow_Crude
	{
		name = "Arrow_Crude";
	};
	class AType_Arrow_Primitive
	{
		name = "Arrow_Primitive";
	};
	class AType_Bullet_12GaugePellets
	{
		name = "Bullet_12GaugePellets";
	};
	class AType_Bullet_12GaugeSlug
	{
		name = "Bullet_12GaugeSlug";
	};
	class AType_Bullet_12GaugeRubberSlug
	{
		name = "Bullet_12GaugeRubberSlug";
	};
	class AType_Bullet_12GaugeBeanbag
	{
		name = "Bullet_12GaugeBeanbag";
	};
	class AType_Bullet_22
	{
		name = "Bullet_22";
	};
	class AType_Bullet_357
	{
		name = "Bullet_357";
	};
	class AType_Bullet_308Win
	{
		name = "Bullet_308Win";
	};
	class AType_Bullet_308WinTracer
	{
		name = "Bullet_308WinTracer";
	};
	class AType_Bullet_380
	{
		name = "Bullet_380";
	};
	class AType_Bullet_45ACP
	{
		name = "Bullet_45ACP";
	};
	class AType_Bullet_9x19
	{
		name = "Bullet_9x19";
	};
	class AType_Bullet_9x39
	{
		name = "Bullet_9x39";
	};
	class AType_Bullet_9x39AP
	{
		name = "Bullet_9x39AP";
	};
	class AType_Bullet_545x39
	{
		name = "Bullet_545x39";
	};
	class AType_Bullet_545x39Tracer
	{
		name = "Bullet_545x39Tracer";
	};
	class AType_Bullet_556x45
	{
		name = "Bullet_556x45";
	};
	class AType_Bullet_556x45Tracer
	{
		name = "Bullet_556x45Tracer";
	};
	class AType_Bullet_762x39
	{
		name = "Bullet_762x39";
	};
	class AType_Bullet_762x39Tracer
	{
		name = "Bullet_762x39Tracer";
	};
	class AType_Bullet_762x54
	{
		name = "Bullet_762x54";
	};
	class AType_Bullet_762x54Tracer
	{
		name = "Bullet_762x54Tracer";
	};
};
class OpticsInfoDefault;
class OpticsInfoRifle: OpticsInfoDefault
{
	memoryPointCamera = "eye";
	opticsZoomMin = 0.414215;
	opticsZoomInit = 0.57737;
	opticsZoomMax = 0.70022;
	distanceZoomMin = 25;
	distanceZoomMax = 25;
	discreteDistance[] = {50,100,200,300};
	discreteDistanceInitIndex = 1;
};
class OpticsInfoShotgun: OpticsInfoRifle
{
	memoryPointCamera = "eye";
	modelOptics = "-";
	distanceZoomMin = 25;
	distanceZoomMax = 25;
	discreteDistance[] = {25};
	discreteDistanceInitIndex = 0;
};
class OpticsInfoPistol: OpticsInfoDefault
{
	memoryPointCamera = "eye";
	opticsZoomMin = 0.414215;
	opticsZoomInit = 0.57737;
	opticsZoomMax = 0.70022;
	distanceZoomMin = 25;
	distanceZoomMax = 25;
	discreteDistance[] = {25};
	discreteDistanceInitIndex = 0;
};
class OpticsInfoArchery: OpticsInfoDefault
{
	memoryPointCamera = "eye";
	opticsZoomMin = 0.414215;
	opticsZoomInit = 0.57737;
	opticsZoomMax = 0.70022;
	modelOptics = "-";
	distanceZoomMin = 10;
	distanceZoomMax = 10;
	discreteDistance[] = {10};
	discreteDistanceInitIndex = 0;
};
class OpticsInfoLauncher: OpticsInfoDefault
{
	memoryPointCamera = "eye";
	opticsZoomMin = 0.25;
	opticsZoomMax = 1.1;
	opticsZoomInit = 0.5;
	distanceZoomMin = 100;
	distanceZoomMax = 100;
	discreteDistance[] = {100};
	discreteDistanceInitIndex = 0;
};
class cfgAmmo
{
	class DefaultAmmo;
	class Explosion_NonLethal: DefaultAmmo
	{
		hit = 1;
		indirectHit = 1;
		indirectHitRange = 1;
		effect = "LandmineExplosion";
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		fuseDistance = 1;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {"Grenade_explosion_SoundSet","Grenade_Tail_SoundSet"};
		soundHit[] = {"DZ\sounds\weapons\grenades\hand_grenade_1",10.0,1};
		soundFly[] = {"dz\sounds\Weapons\explosions\noise",3.162277e-05,1};
		soundEngine[] = {"",9.999998e-05,4};
		visibleFire = 2;
		audibleFire = 0.25;
		whistleDist = 4;
		visibleFireTime = 0;
		class DamageApplied
		{
			type = "Projectile";
			class Health
			{
				damage = 5;
			};
			class Blood
			{
				damage = 10;
			};
			class Shock
			{
				damage = 10;
			};
		};
	};
};
class cfgWeapons
{
	class DefaultWeapon;
	class LauncherCore;
	class RifleCore;
	class PistolCore;
	class Rifle_Base: RifleCore
	{
		scope = 0;
		lootCategory = "Rifles";
		storageCategory = 1;
		targetCategory = "loot";
		weaponInfoType = "RscWeaponZeroing";
		inventorySlot[] = {"Shoulder","Melee"};
		sightMisalignmentModifier[] = {1,1,0};
		rotationFlags = 17;
		soundAttType = "Rifle";
		cursor = "aimGunGhost";
		cursorAim = "aimPistol";
		itemSize[] = {6,3};
		spawnDamageRange[] = {0.0,0.6};
		damagePerShot = 0.05;
		barrelArmor = 400;
		unjamTime[] = {6.0,10.0};
		autoReload = 0;
		discreteDistance[] = {50,100,200,300};
		discreteDistanceInitIndex = 1;
		opticsZoomMin = 0.414215;
		opticsZoomInit = 0.57737;
		opticsZoomMax = 0.70022;
		magazineSlot = "magazine";
		chamberedRound = "";
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		bullet1[] = {"dz\sounds\weapons\shells\5_56\asphlat_556_01",0.17782794,1,15};
		bullet2[] = {"dz\sounds\weapons\shells\5_56\asphlat_556_02",0.17782794,1,15};
		bullet3[] = {"dz\sounds\weapons\shells\5_56\asphlat_556_03",0.17782794,1,15};
		bullet4[] = {"dz\sounds\weapons\shells\5_56\asphlat_556_04",0.17782794,1,15};
		bullet5[] = {"dz\sounds\weapons\shells\5_56\asphlat_556_05",0.31622776,1,15};
		bullet6[] = {"dz\sounds\weapons\shells\5_56\asphlat_556_06",0.31622776,1,15};
		bullet7[] = {"dz\sounds\weapons\shells\5_56\dirt_556_01",0.31622776,1,15};
		bullet8[] = {"dz\sounds\weapons\shells\5_56\dirt_556_02",0.31622776,1,15};
		bullet9[] = {"dz\sounds\weapons\shells\5_56\dirt_556_03",0.17782794,1,15};
		bullet10[] = {"dz\sounds\weapons\shells\5_56\dirt_556_04",0.17782794,1,15};
		bullet11[] = {"dz\sounds\weapons\shells\5_56\dirt_556_05",0.17782794,1,15};
		bullet12[] = {"dz\sounds\weapons\shells\5_56\dirt_556_06",0.17782794,1,15};
		soundBullet[] = {"bullet1",0.083,"bullet2",0.083,"bullet3",0.083,"bullet4",0.083,"bullet5",0.083,"bullet6",0.083,"bullet7",0.083,"bullet8",0.083,"bullet9",0.083,"bullet10",0.083,"bullet11",0.083,"bullet12",0.083};
		class Single: Mode_SemiAuto{};
		class NoiseShoot
		{
			strength = 100.0;
			type = "shot";
		};
		class OpticsInfo: OpticsInfoRifle{};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
		class Reliability
		{
			ChanceToJam[] = {0,0.001,0.005,0.05,1};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "FirearmHit_Rifle";
				range = 1.2;
			};
			class Buttstock
			{
				ammo = "FirearmHit_Rifle_Buttstock";
				range = 1.2;
			};
			class Bayonet
			{
				ammo = "FirearmHit_Rifle_Bayonet";
				range = 1.8;
			};
		};
	};
	class BoltActionRifle_Base: Rifle_Base{};
	class BoltActionRifle_InnerMagazine_Base: BoltActionRifle_Base{};
	class Shotgun_Base: Rifle_Base
	{
		scope = 0;
		rotationFlags = 17;
		soundAttType = "Shotgun";
		animClass = "Shotgun";
		modelOptics = "-";
		distanceZoomMin = 50;
		distanceZoomMax = 50;
		discreteDistance[] = {50};
		opticsFlare = 0;
		class OpticsInfo: OpticsInfoShotgun{};
	};
	class Pistol_Base: PistolCore
	{
		scope = 0;
		lootCategory = "Pistols";
		storageCategory = 1;
		targetCategory = "loot";
		inventorySlot[] = {"Pistol"};
		sightMisalignmentModifier[] = {0.4,1.5,0};
		rotationFlags = 17;
		soundAttType = "None";
		cursor = "aimGunGhost";
		cursorAim = "aimPistol";
		type = 1;
		itemSize[] = {4,2};
		damagePerShot = 0.1;
		barrelArmor = 400;
		unjamTime[] = {6.0,10.0};
		autoReload = 0;
		opticsZoomMin = 0.414215;
		opticsZoomInit = 0.57737;
		opticsZoomMax = 0.70022;
		magazineSlot = "magazine";
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		bullet1[] = {"dz\sounds\weapons\shells\45\asphlat_45_01",0.17782794,1,15};
		bullet2[] = {"dz\sounds\weapons\shells\45\asphlat_45_02",0.17782794,1,15};
		bullet3[] = {"dz\sounds\weapons\shells\45\asphlat_45_03",0.17782794,1,15};
		bullet4[] = {"dz\sounds\weapons\shells\45\asphlat_45_04",0.17782794,1,15};
		bullet5[] = {"dz\sounds\weapons\shells\45\asphlat_45_05",0.31622776,1,15};
		bullet6[] = {"dz\sounds\weapons\shells\45\asphlat_45_06",0.31622776,1,15};
		bullet7[] = {"dz\sounds\weapons\shells\45\dirt_45_01",0.31622776,1,15};
		bullet8[] = {"dz\sounds\weapons\shells\45\dirt_45_02",0.31622776,1,15};
		bullet9[] = {"dz\sounds\weapons\shells\45\dirt_45_03",0.17782794,1,15};
		bullet10[] = {"dz\sounds\weapons\shells\45\dirt_45_04",0.17782794,1,15};
		bullet11[] = {"dz\sounds\weapons\shells\45\dirt_45_05",0.17782794,1,15};
		bullet12[] = {"dz\sounds\weapons\shells\45\dirt_45_06",0.17782794,1,15};
		soundBullet[] = {"bullet1",0.083,"bullet2",0.083,"bullet3",0.083,"bullet4",0.083,"bullet5",0.083,"bullet6",0.083,"bullet7",0.083,"bullet8",0.083,"bullet9",0.083,"bullet10",0.083,"bullet11",0.083,"bullet12",0.083};
		class Single: Mode_SemiAuto{};
		class NoiseShoot
		{
			strength = 100.0;
			type = "shot";
		};
		class OpticsInfo: OpticsInfoPistol{};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
		class Reliability
		{
			ChanceToJam[] = {0,0.0025,0.01,0.05,1};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "FirearmHit_Pistol";
				range = 1.2;
			};
		};
	};
	class Archery_Base: RifleCore
	{
		scope = 0;
		storageCategory = 1;
		armAction = "Bow";
		animClass = "Bow";
		animName = "Bow";
		targetCategory = "loot";
		autoReload = 0;
		cursor = "aimBowGhost";
		cursorAim = "aimBow";
		arrow1[] = {};
		absorbency = 0.1;
		itemSize[] = {7,3};
		modelOptics = "-";
		distanceZoomMin = 10;
		distanceZoomMax = 10;
		discreteDistance[] = {10};
		discreteDistanceInitIndex = 1;
		soundBullet[] = {"arrow1",1};
		drySound[] = {"dz\sounds\weapons\bows\dry_bow_0",0.9,1,30};
		reloadMagazineSound[] = {};
		reloadSound[] = {"dz\sounds\weapons\bows\Bow_reload",0.9,1,30};
		prepSoundDry1[] = {"dz\sounds\weapons\bows\Bow_wood_bend_empty_01",0.9,1,30};
		prepSoundDry2[] = {"dz\sounds\weapons\bows\Bow_wood_bend_empty_02",0.9,1,30};
		prepSoundDry[] = {"prepSoundDry1",0.5,"prepSoundDry2",0.5};
		prepSoundLoaded1[] = {"dz\sounds\weapons\bows\Bow_wood_bend_loaded_01",0.9,1,30};
		prepSoundLoaded2[] = {"dz\sounds\weapons\bows\Bow_wood_bend_loaded_02",0.9,1,30};
		prepSoundLoaded[] = {"prepSoundLoaded1",0.5,"prepSoundLoaded2",0.5};
		attachments[] = {};
		ejectType = 1;
		reloadAction = "ReloadBow";
		shotAction = "ReloadBow";
		magazineSlot = "magazine";
		canChamberByDestroyed = 0;
		hiddenSelections[] = {"camo"};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			reloadTime = 0.7;
			recoil = "recoil_bow";
			recoilProne = "recoil_bow";
			dispersion = 0.003;
			magazineSlot = "magazine";
		};
		class NoiseShoot
		{
			strength = 5.0;
			type = "shot";
		};
		class OpticsInfo: OpticsInfoArchery{};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};
	class Launcher_Base: LauncherCore
	{
		scope = 0;
		cursorAim = "";
		cursor = "";
		cursorSize = 1;
		autoAimEnabled = 0;
		opticsDisablePeripherialVision = 1;
		magazines[] = {};
		magazineReloadTime = 12;
		reloadTime = 0;
		initSpeed = 30;
		canLock = 0;
		rotationFlags = 17;
		reloadAction = "ManActReloadAT";
		autoReload = 0;
		ffMagnitude = 0.1;
		ffFrequency = 1;
		ffCount = 1;
		recoil = "";
		aiRateOfFire = 10.0;
		aiRateOfFireDistance = 500;
		primary = 0;
		spawnDamageRange[] = {0.0,0.6};
		opticsZoomMin = 0.25;
		opticsZoomMax = 1.1;
		opticsZoomInit = 0.5;
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		minRange = 20;
		minRangeProbab = 0.3;
		midRange = 150;
		midRangeProbab = 0.58;
		maxRange = 500;
		maxRangeProbab = 0.04;
		class OpticsInfo: OpticsInfoLauncher{};
	};
};
