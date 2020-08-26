#define _ARMA_

class CfgPatches
{
	class DZ_Data_Bliss
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class bliss
	{
		type = "mod";
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"DZ/data_bliss/scripts/4_World"};
			};
		};
		dir = "Bliss";
		appId = 1151700;
		name = "$STR_dlc_livonia_name";
		picture = "DZ\data_bliss\gui\textures\picture_bliss_ca.paa";
		logo = "DZ\data_bliss\gui\textures\logo_bliss_ca.paa";
		logoOver = "DZ\data_bliss\gui\textures\logoOver_bliss_ca.paa";
		logoSmall = "DZ\data_bliss\gui\textures\logoSmall_bliss_ca.paa";
		tooltip = "";
		tooltipOwned = "";
		overview = "$STR_dlc_livonia_overview";
		action = "https://dayz.com/";
		author = "$STR_bohemia_interactive";
		version = "";
	};
};
