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
	class DZ_Characters_Heads
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgFaces
{
	class Default
	{
		class Custom;
	};
	class MaleAdamHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved_co.paa";
			head = "MaleAdamHead";
			material = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat";
		};
		class MaleAdamHead: Default{};
	};
	class MaleBorisHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved_co.paa";
			head = "MaleBorisHead";
			material = "dz\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved.rvmat";
		};
		class MaleBorisHead: Default{};
	};
	class MaleCyrilHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved_co.paa";
			head = "MaleCyrilHead";
			material = "dz\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved.rvmat";
		};
		class MaleCyrilHead: Default{};
	};
	class MaleDenisHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved_co.paa";
			head = "MaleDenisHead";
			material = "dz\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved.rvmat";
		};
		class MaleDenisHead: Default{};
	};
	class MaleEliasHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved_co.paa";
			head = "MaleEliasHead";
			material = "dz\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved.rvmat";
		};
		class MaleEliasHead: Default{};
	};
	class MaleFrancisHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved_co.paa";
			head = "MaleFrancisHead";
			material = "dz\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved.rvmat";
		};
		class MaleFrancisHead: Default{};
	};
	class MaleGuoHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved_co.paa";
			head = "MaleGuoHead";
			material = "dz\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved.rvmat";
		};
		class MaleGuoHead: Default{};
	};
	class MaleHassanHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved_co.paa";
			head = "MaleHassanHead";
			material = "dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved.rvmat";
		};
		class MaleHassanHead: Default{};
	};
	class MaleIndarHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved_co.paa";
			head = "MaleIndarHead";
			material = "dz\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved.rvmat";
		};
		class MaleIndarHead: Default{};
	};
	class MaleJoseHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved_co.paa";
			head = "MaleJoseHead";
			material = "dz\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved.rvmat";
		};
		class MaleJoseHead: Default{};
	};
	class MaleKaitoHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved_co.paa";
			head = "MaleKaitoHead";
			material = "dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved.rvmat";
		};
		class MaleKaitoHead: Default{};
	};
	class MaleLewisHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved_co.paa";
			head = "MaleLewisHead";
			material = "dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved.rvmat";
		};
		class MaleLewisHead: Default{};
	};
	class MaleManuaHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved_co.paa";
			head = "MaleManuaHead";
			material = "dz\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved.rvmat";
		};
		class MaleManuaHead: Default{};
	};
	class MaleNikiHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved_co.paa";
			head = "MaleNikiHead";
			material = "dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved.rvmat";
		};
		class MaleNikiHead: Default{};
	};
	class MaleOliverHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved_co.paa";
			head = "MaleOliverHead";
			material = "dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved.rvmat";
		};
		class MaleOliverHead: Default{};
	};
	class MalePeterHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved_co.paa";
			head = "MalePeterHead";
			material = "dz\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved.rvmat";
		};
		class MalePeterHead: Default{};
	};
	class MaleQuinnHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved_co.paa";
			head = "MaleQuinnHead";
			material = "dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved.rvmat";
		};
		class MaleQuinnHead: Default{};
	};
	class MaleRolfHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved_co.paa";
			head = "MaleRolfHead";
			material = "dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved.rvmat";
		};
		class MaleRolfHead: Default{};
	};
	class MaleSethHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved_co.paa";
			head = "MaleSethHead";
			material = "dz\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved.rvmat";
		};
		class MaleSethHead: Default{};
	};
	class MaleTaikiHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved_co.paa";
			head = "MaleTaikiHead";
			material = "dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved.rvmat";
		};
		class MaleTaikiHead: Default{};
	};
	class FemaleEvaHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body_co.paa";
			head = "FemaleEvaHead";
			material = "dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body.rvmat";
		};
		class FemaleEvaHead: Default{};
	};
	class FemaleFridaHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\f_Frida_2\hhl_f_Frida_body_co.paa";
			head = "FemaleFridaHead";
			material = "dz\characters\heads\data\f_Frida_2\hhl_f_Frida_body.rvmat";
		};
		class FemaleFridaHead: Default{};
	};
	class FemaleGabiHead: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body_co.paa";
			head = "FemaleGabiHead";
			material = "dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body.rvmat";
		};
		class FemaleGabiHead: Default{};
	};
	class FemaleHelgaHead: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleHelgaHead_Default0";
			texture = "dz\characters\heads\data\f_Helga\hhl_f_Helga_body_co.paa";
			head = "FemaleHelgaHead";
			material = "dz\characters\heads\data\f_Helga\hhl_f_Helga_body.rvmat";
		};
		class FemaleHelgaHead: Default{};
	};
	class FemaleIrenaHead: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleIrenaHead_Default0";
			texture = "dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body_co.paa";
			head = "FemaleIrenaHead";
			material = "dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body.rvmat";
		};
		class FemaleIrenaHead: Default{};
	};
	class FemaleJudyHead: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleJudyHead_Default0";
			texture = "dz\characters\heads\data\f_Judy\hhl_f_Judy_body_co.paa";
			head = "FemaleJudyHead";
			material = "dz\characters\heads\data\f_Judy\hhl_f_Judy_body.rvmat";
		};
		class FemaleJudyHead: Default{};
	};
	class FemaleKeikoHead: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleKeikoHead_Default0";
			texture = "dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body_co.paa";
			head = "FemaleKeikoHead";
			material = "dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body.rvmat";
		};
		class FemaleKeikoHead: Default{};
	};
	class FemaleLindaHead: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleLindaHead_Default0";
			texture = "dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body_co.paa";
			head = "FemaleLindaHead";
			material = "dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body.rvmat";
		};
		class FemaleLindaHead: Default{};
	};
	class FemaleMariaHead: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleMariaHead_Default0";
			texture = "dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body_co.paa";
			head = "FemaleMariaHead";
			material = "dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body.rvmat";
		};
		class FemaleMariaHead: Default{};
	};
	class FemaleNaomiHead: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleNaomiHead_Default0";
			texture = "dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body_co.paa";
			head = "FemaleNaomiHead";
			material = "dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body.rvmat";
		};
		class FemaleNaomiHead: Default{};
	};
	class AnimalHead
	{
		class Default
		{
			displayname = "$STR_FN_AnimalHead_Default";
			texture = "\DZ\Characters\Heads\Data\hhl_m_white_06_co.paa";
			head = "";
			material = "";
		};
		class Animal: Default{};
	};
	class MaleAdamHeadNoBeard: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved_co.paa";
			head = "MaleAdamHeadNoBeard";
			material = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat";
		};
		class MaleAdamHeadNoBeard: Default{};
	};
	class MaleAdamHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Adam\Adam_body_shaved_decayed.paa";
			head = "MaleAdamHeadDecayed";
			material = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat";
		};
		class MaleAdamHeadDecayed: Default{};
	};
	class MaleAdamHeadDecayedDark: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Adam\Adam_body_shaved_decayed_dark.paa";
			head = "MaleAdamHeadDecayedDark";
			material = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat";
		};
		class MaleAdamHeadDecayedDark: Default{};
	};
	class MaleAdamHeadDecayedLighterDark: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Adam\Adam_body_shaved_decayed_lighter_dark.paa";
			head = "MaleAdamHeadDecayedLighterDark";
			material = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat";
		};
		class MaleAdamHeadDecayedLighterDark: Default{};
	};
	class MaleBorisHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved_decayed_co.paa";
			head = "MaleBorisHead";
			material = "dz\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved.rvmat";
		};
		class MaleBorisHeadDecayed: Default{};
	};
	class MaleCyrilHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved_decayed_co.paa";
			head = "MaleCyrilHead";
			material = "dz\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved.rvmat";
		};
		class MaleCyrilHeadDecayed: Default{};
	};
	class MaleDenisHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved_decayed_co.paa";
			head = "MaleDenisHead";
			material = "dz\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved.rvmat";
		};
		class MaleDenisHeadDecayed: Default{};
	};
	class MaleEliasHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved_decayed_co.paa";
			head = "MaleEliasHead";
			material = "dz\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved.rvmat";
		};
		class MaleEliasHeadDecayed: Default{};
	};
	class MaleFrancisHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved_decayed_co.paa";
			head = "MaleFrancisHead";
			material = "dz\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved.rvmat";
		};
		class MaleFrancisHeadDecayed: Default{};
	};
	class MaleGuoHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved_decayed_co.paa";
			head = "MaleGuoHead";
			material = "dz\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved.rvmat";
		};
		class MaleGuoHeadDecayed: Default{};
	};
	class MaleHassanHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved_decayed_co.paa";
			head = "MaleHassanHead";
			material = "dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved.rvmat";
		};
		class MaleHassanHeadDecayed: Default{};
	};
	class MaleIndarHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved_decayed_co.paa";
			head = "MaleIndarHead";
			material = "dz\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved.rvmat";
		};
		class MaleIndarHeadDecayed: Default{};
	};
	class MaleJoseHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved_decayed_co.paa";
			head = "MaleJoseHead";
			material = "dz\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved.rvmat";
		};
		class MaleJoseHeadDecayed: Default{};
	};
	class MaleKaitoHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved_decayed_co.paa";
			head = "MaleKaitoHead";
			material = "dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved.rvmat";
		};
		class MaleKaitoHeadDecayed: Default{};
	};
	class MaleLewisHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved_decayed_co.paa";
			head = "MaleLewisHead";
			material = "dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved.rvmat";
		};
		class MaleLewisHeadDecayed: Default{};
	};
	class MaleManuaHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved_decayed_co.paa";
			head = "MaleManuaHead";
			material = "dz\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved.rvmat";
		};
		class MaleManuaHeadDecayed: Default{};
	};
	class MaleNikiHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved_decayed_co.paa";
			head = "MaleNikiHead";
			material = "dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved.rvmat";
		};
		class MaleNikiHeadDecayed: Default{};
	};
	class MaleOliverHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved_decayed_co.paa";
			head = "MaleOliverHead";
			material = "dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved.rvmat";
		};
		class MaleOliverHeadDecayed: Default{};
	};
	class MalePeterHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved_decayed_co.paa";
			head = "MalePeterHead";
			material = "dz\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved.rvmat";
		};
		class MalePeterHeadDecayed: Default{};
	};
	class MaleQuinnHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved_decayed_co.paa";
			head = "MaleQuinnHead";
			material = "dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved.rvmat";
		};
		class MaleQuinnHeadDecayed: Default{};
	};
	class MaleRolfHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved_decayed_co.paa";
			head = "MaleRolfHead";
			material = "dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved.rvmat";
		};
		class MaleRolfHeadDecayed: Default{};
	};
	class MaleSethHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved_decayed_co.paa";
			head = "MaleSethHead";
			material = "dz\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved.rvmat";
		};
		class MaleSethHeadDecayed: Default{};
	};
	class MaleTaikiHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved_decayed_co.paa";
			head = "MaleTaikiHead";
			material = "dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved.rvmat";
		};
		class MaleTaikiHeadDecayed: Default{};
	};
	class FemaleEvaHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body_decayed_co.paa";
			head = "FemaleEvaHead";
			material = "dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body.rvmat";
		};
		class FemaleEvaHeadDecayed: Default{};
	};
	class FemaleFridaHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\f_Frida_2\hhl_f_Frida_body_decayed_co.paa";
			head = "FemaleFridaHead";
			material = "dz\characters\heads\data\f_Frida_2\hhl_f_Frida_body.rvmat";
		};
		class FemaleFridaHeadDecayed: Default{};
	};
	class FemaleGabiHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body_decayed_co.paa";
			head = "FemaleGabiHead";
			material = "dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body.rvmat";
		};
		class FemaleGabiHeadDecayed: Default{};
	};
	class FemaleGabi2HeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body_decayed_co.paa";
			head = "FemaleGabi2Head";
			material = "dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body.rvmat";
		};
		class FemaleGabi2HeadDecayed: Default{};
	};
	class FemaleHelgaHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleHelgaHead_Default0";
			texture = "dz\characters\heads\data\f_Helga\hhl_f_Helga_body_decayed_co.paa";
			head = "FemaleHelgaHead";
			material = "dz\characters\heads\data\f_Helga\hhl_f_Helga_body.rvmat";
		};
		class FemaleHelgaHeadDecayed: Default{};
	};
	class FemaleIrenaHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleIrenaHead_Default0";
			texture = "dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body_decayed_co.paa";
			head = "FemaleIrenaHead";
			material = "dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body.rvmat";
		};
		class FemaleIrenaHeadDecayed: Default{};
	};
	class FemaleJudyHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleJudyHead_Default0";
			texture = "dz\characters\heads\data\f_Judy\hhl_f_Judy_body_decayed_co.paa";
			head = "FemaleJudyHead";
			material = "dz\characters\heads\data\f_Judy\hhl_f_Judy_body.rvmat";
		};
		class FemaleJudyHeadDecayed: Default{};
	};
	class FemaleKeikoHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleKeikoHead_Default0";
			texture = "dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body_decayed_co.paa";
			head = "FemaleKeikoHead";
			material = "dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body.rvmat";
		};
		class FemaleKeikoHeadDecayed: Default{};
	};
	class FemaleLindaHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleLindaHead_Default0";
			texture = "dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body_decayed_co.paa";
			head = "FemaleLindaHead";
			material = "dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body.rvmat";
		};
		class FemaleLindaHeadDecayed: Default{};
	};
	class FemaleMariaHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleMariaHead_Default0";
			texture = "dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body_decayed_co.paa";
			head = "FemaleMariaHead";
			material = "dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body.rvmat";
		};
		class FemaleMariaHeadDecayed: Default{};
	};
	class FemaleMaria2HeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleMaria2Head_Default0";
			texture = "dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body_decayed_co.paa";
			head = "FemaleMaria2Head";
			material = "dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body.rvmat";
		};
		class FemaleMaria2HeadDecayed: Default{};
	};
	class FemaleNaomiHeadDecayed: Default
	{
		class Default
		{
			displayname = "$STR_CfgFaces_FemaleNaomiHead_Default0";
			texture = "dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body_decayed_co.paa";
			head = "FemaleNaomiHead";
			material = "dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body.rvmat";
		};
		class FemaleNaomiHeadDecayed: Default{};
	};
	class MaleAdamHead_BeardStart: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved_co.paa";
			head = "MaleAdamHead_BeardStart";
			material = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat";
		};
		class MaleAdamHead_BeardStart: Default{};
	};
	class MaleAdamHead_BeardEnd: Default
	{
		class Default
		{
			displayname = "$STR_CFG_FACES_Default";
			texture = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved_co.paa";
			head = "MaleAdamHead_BeardEnd";
			material = "dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat";
		};
		class MaleAdamHead_BeardEnd: Default{};
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class Head: Inventory_Base
	{
		scope = 2;
		displayName = "head";
		descriptionShort = "engine head base";
		inventorySlot[] = {"Head"};
		simulation = "head";
	};
	class Head_Default: Head
	{
		scope = 2;
		displayName = "face";
		descriptionShort = "for testing purposes only";
		model = "\dz\characters\heads\m_adam.p3d";
		selectionHeadWound = "injury_head";
		selectionPersonality = "personality";
		hiddenSelections[] = {"beard","hair"};
		simpleHiddenSelections[] = {"beard","hair","Clipping_GhillieHood","Clipping_grathelm","Clipping_ConstructionHelmet","Clipping_Hockey_hekmet","Clipping_Maska","Clipping_ProtecSkateHelmet2","Clipping_BandanaFace","Clipping_NioshFaceMask","Clipping_NBC_Hood","Clipping_MotoHelmet","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet","Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_BoonieHat","Clipping_prison_cap","Clipping_MilitaryBeret_xx","Clipping_Policecap","Clipping_OfficerHat","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_SantasHat","Clipping_FlatCap","Clipping_MxHelmet","Clipping_baseballcap","Clipping_BeanieHat","Clipping_MedicalScrubs_Hat","Clipping_RadarCap","Clipping_ZmijovkaCap","Clipping_HeadTorch","Clipping_pilotka","Clipping_HeloHelmet","Clipping_HelmetMich","Clipping_Ssh68Helmet","Clipping_Mich2001","Clipping_Welding_Mask","Clipping_VintageHockeyMask","Clipping_mouth_rags","Clipping_Gasmask","Clipping_WitchHood","Clipping_WitchHat"};
	};
	class FemaleFridaHead: Head_Default
	{
		model = "\dz\characters\heads\f_Frida_2.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\f_Frida_2\hhl_f_Frida_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\f_Frida_2\hhl_f_Frida_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_NBC_Hood","Clipping_PumpkinHelmet","Clipping_MotoHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_RadarCap"};
				memberSelections[] = {"Clipping_RadarCap","Clipping_BeanieHat","Clipping_TankerHelmet"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_BandanaHead"};
				memberSelections[] = {"Clipping_BandanaHead","Clipping_SantasHat","Clipping_Maska","Clipping_MedicalScrubs_Hat","Clipping_OfficerHat","Clipping_Policecap","Clipping_prison_cap","Clipping_MilitaryBeret_xx","Clipping_CowboyHat","Clipping_FlatCap"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_HeloHelmet"};
				memberSelections[] = {"Clipping_HeloHelmet","Clipping_Hockey_hekmet"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_ProtecSkateHelmet2","Clipping_Ssh68Helmet"};
			};
			class Group_4
			{
				simpleSelectionName[] = {"Clipping_ushanka"};
				memberSelections[] = {"Clipping_ushanka","Clipping_ZmijovkaCap"};
			};
		};
	};
	class FemaleGabiHead: Head_Default
	{
		model = "\dz\characters\heads\f_Gabi_2.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_GhillieHood","Clipping_grathelm","Clipping_ConstructionHelmet","Clipping_Maska","Clipping_NioshFaceMask","Clipping_NBC_Hood","Clipping_MotoHelmet","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_BeanieHat","Clipping_RadarCap","Clipping_ZmijovkaCap","Clipping_HelmetMich","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_BoonieHat"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_Hockey_hekmet"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_prison_cap","Clipping_MilitaryBeret_xx","Clipping_Policecap","Clipping_OfficerHat","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_SantasHat","Clipping_MxHelmet","Clipping_MedicalScrubs_Hat"};
			};
		};
	};
	class FemaleHelgaHead: Head_Default
	{
		model = "\dz\characters\heads\f_Helga.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\f_Helga\hhl_f_Helga_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\f_Helga\hhl_f_Helga_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_NBC_Hood","Clipping_MotoHelmet","Clipping_TankerHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_MilitaryBeret_xx","Clipping_Policecap","Clipping_OfficerHat","Clipping_VintageHockeyMask","Clipping_WitchHood","Clipping_WitchHat","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_ConstructionHelmet"};
				memberSelections[] = {"Clipping_ConstructionHelmet","Clipping_Hockey_hekmet","Clipping_Maska","Clipping_ProtecSkateHelmet2"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_Hat_leather","Clipping_BandanaHead","Clipping_SantasHat","Clipping_BoonieHat","Clipping_prison_cap","Clipping_CowboyHat","Clipping_MxHelmet","Clipping_baseballcap","Clipping_BeanieHat","Clipping_Ssh68Helmet","Clipping_Mich2001"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_RadarCap"};
				memberSelections[] = {"Clipping_RadarCap","Clipping_ushanka","Clipping_ZmijovkaCap"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_HelmetMich"};
				memberSelections[] = {"Clipping_HelmetMich","Clipping_MedicalScrubs_Hat","Clipping_HeloHelmet"};
			};
		};
	};
	class FemaleIrenaHead: Head_Default
	{
		model = "\dz\characters\heads\f_Irena_2.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\f_Irena_2\hhl_f_Irena_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\f_Irena_2\hhl_f_Irena_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_NBC_Hood","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_BoonieHat"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_FlatCap","Clipping_CowboyHat","Clipping_Hat_leather"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_Maska"};
				memberSelections[] = {"Clipping_Maska","Clipping_ProtecSkateHelmet2","Clipping_MotoHelmet"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_HeloHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_HeloHelmet"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_pilotka"};
				memberSelections[] = {"Clipping_SantasHat","Clipping_pilotka"};
			};
			class Group_4
			{
				simpleSelectionName[] = {"Clipping_BeanieHat"};
				memberSelections[] = {"Clipping_BeanieHat","Clipping_RadarCap"};
			};
			class Group_5
			{
				simpleSelectionName[] = {"Clipping_Gasmask"};
				memberSelections[] = {"Clipping_Welding_Mask","Clipping_VintageHockeyMask","Clipping_Gasmask"};
			};
		};
	};
	class FemaleJudyHead: Head_Default
	{
		model = "\dz\characters\heads\f_Judy.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\f_Judy\hhl_f_Judy_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\f_Judy\hhl_f_Judy_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\f_Judy\hhl_f_Judy_body.rvmat","DZ\Characters\Heads\Data\f_Judy\hhl_f_Judy_body_injury.rvmat","DZ\Characters\Heads\Data\f_Judy\hhl_f_Judy_body_injury2.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_Hockey_hekmet","Clipping_Maska","Clipping_NBC_Hood","Clipping_MotoHelmet","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_BoonieHat","Clipping_MilitaryBeret_xx","Clipping_Policecap","Clipping_OfficerHat","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_SantasHat","Clipping_FlatCap","Clipping_MxHelmet","Clipping_BeanieHat","Clipping_MedicalScrubs_Hat","Clipping_RadarCap","Clipping_ZmijovkaCap","Clipping_pilotka","Clipping_HeloHelmet","Clipping_HelmetMich","Clipping_Ssh68Helmet","Clipping_Mich2001","Clipping_VintageHockeyMask","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_ConstructionHelmet"};
				memberSelections[] = {"Clipping_ConstructionHelmet","Clipping_ProtecSkateHelmet2","Clipping_prison_cap"};
			};
		};
	};
	class FemaleKeikoHead: Head_Default
	{
		model = "\dz\characters\heads\f_Keiko.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\f_Keiko\hhl_f_Keiko_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\f_Keiko\hhl_f_Keiko_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_Hockey_hekmet","Clipping_Maska","Clipping_NBC_Hood","Clipping_MotoHelmet","Clipping_TankerHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_HeadTorch","Clipping_Welding_Mask","Clipping_VintageHockeyMask","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_BoonieHat"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_SantasHat"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_MilitaryBeret_xx"};
				memberSelections[] = {"Clipping_MilitaryBeret_xx","Clipping_CowboyHat"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_BeanieHat"};
				memberSelections[] = {"Clipping_BeanieHat","Clipping_ZmijovkaCap"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_HelmetMich"};
				memberSelections[] = {"Clipping_HelmetMich","Clipping_Ssh68Helmet"};
			};
		};
	};
	class FemaleLindaHead: Head_Default
	{
		model = "\dz\characters\heads\f_Linda_2.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\f_Linda_2\hhl_f_Linda_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\f_Linda_2\hhl_f_Linda_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_NBC_Hood","Clipping_MotoHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_RadarCap","Clipping_VintageHockeyMask","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_BoonieHat","Clipping_prison_cap","Clipping_Policecap","Clipping_OfficerHat","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_SantasHat","Clipping_baseballcap","Clipping_Ssh68Helmet","Clipping_Welding_Mask"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_ConstructionHelmet"};
				memberSelections[] = {"Clipping_ConstructionHelmet","Clipping_Hockey_hekmet","Clipping_ushanka","Clipping_BandanaHead","Clipping_MxHelmet","Clipping_MilitaryBeret_xx","Clipping_MedicalScrubs_Hat"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_BeanieHat"};
				memberSelections[] = {"Clipping_BeanieHat","Clipping_ZmijovkaCap","Clipping_TankerHelmet","Clipping_Gasmask"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_ProtecSkateHelmet2"};
				memberSelections[] = {"Clipping_ProtecSkateHelmet2","Clipping_FireHelmet"};
			};
		};
	};
	class FemaleMariaHead: Head_Default
	{
		model = "\dz\characters\heads\f_Maria_2.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\f_Maria_2\hhl_f_Maria_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\f_Maria_2\hhl_f_Maria_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_Hockey_hekmet"};
				memberSelections[] = {"Clipping_Hockey_hekmet","Clipping_FireHelmet"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_BoonieHat"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_HelmetMich"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_MilitaryBeret_xx","Clipping_Policecap","Clipping_OfficerHat","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_baseballcap"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_SantasHat"};
				memberSelections[] = {"Clipping_SantasHat","Clipping_ushanka","Clipping_MxHelmet","Clipping_MedicalScrubs_Hat"};
			};
			class Group_4
			{
				simpleSelectionName[] = {"Clipping_BeanieHat"};
				memberSelections[] = {"Clipping_BeanieHat","Clipping_ZmijovkaCap"};
			};
			class Group_5
			{
				simpleSelectionName[] = {"Clipping_RadarCap"};
				memberSelections[] = {"Clipping_RadarCap","Clipping_MotoHelmet","Clipping_TankerHelmet","Clipping_Maska"};
			};
		};
	};
	class FemaleNaomiHead: Head_Default
	{
		model = "\dz\characters\heads\f_Naomi.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\f_Naomi\hhl_f_Naomi_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\f_Naomi\hhl_f_Naomi_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_Maska","Clipping_ProtecSkateHelmet2","Clipping_NBC_Hood","Clipping_MotoHelmet","Clipping_FireHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_TankerHelmet","Clipping_RadarCap","Clipping_HelmetMich","Clipping_Mich2001","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_ushanka"};
				memberSelections[] = {"Clipping_ushanka","Clipping_MxHelmet","Clipping_BandanaHead"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_BoonieHat"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_prison_cap"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_SantasHat","Clipping_CowboyHat","Clipping_Hat_leather","Clipping_OfficerHat","Clipping_Policecap","Clipping_MilitaryBeret_xx"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_baseballcap"};
				memberSelections[] = {"Clipping_baseballcap","Clipping_HeadTorch","Clipping_HeloHelmet"};
			};
			class Group_4
			{
				simpleSelectionName[] = {"Clipping_BeanieHat"};
				memberSelections[] = {"Clipping_BeanieHat","Clipping_MedicalScrubs_Hat","Clipping_ZmijovkaCap"};
			};
		};
	};
	class FemaleEvaHead: Head_Default
	{
		model = "\dz\characters\heads\f_Eva_2.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\f_Eva_2\hhl_f_Eva_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\f_Eva_2\hhl_f_Eva_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_PumpkinHelmet","Clipping_Maska","Clipping_NBC_Hood","Clipping_MotoHelmet","Clipping_FireHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_BeanieHat","Clipping_RadarCap","Clipping_HeloHelmet","Clipping_TankerHelmet","Clipping_Mich2001","Clipping_HelmetMich","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_Hockey_hekmet"};
				memberSelections[] = {"Clipping_Hockey_hekmet","Clipping_ProtecSkateHelmet2"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_ushanka"};
				memberSelections[] = {"Clipping_ushanka","Clipping_BandanaHead","Clipping_MxHelmet","Clipping_baseballcap","Clipping_MedicalScrubs_Hat","Clipping_ZmijovkaCap"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_BoonieHat"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_Ssh68Helmet"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_Gasmask"};
				memberSelections[] = {"Clipping_Gasmask","Clipping_Hat_leather","Clipping_CowboyHat"};
			};
			class Group_4
			{
				simpleSelectionName[] = {"Clipping_prison_cap"};
				memberSelections[] = {"Clipping_prison_cap","Clipping_baseballcap","Clipping_FlatCap"};
			};
			class Group_5
			{
				simpleSelectionName[] = {"Clipping_Policecap"};
				memberSelections[] = {"Clipping_Policecap","Clipping_OfficerHat"};
			};
		};
	};
	class MaleAdamHead: Head_Default
	{
		model = "\dz\characters\heads\m_adam.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_adam\hhl_m_adam_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_adam\hhl_m_adam_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_NBC_Hood","Clipping_MotoHelmet","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_SantasBeard","Clipping_Surgical_mask"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_prison_cap","Clipping_MilitaryBeret_xx","Clipping_Policecap","Clipping_OfficerHat","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_SantasHat","Clipping_FlatCap","Clipping_MxHelmet"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_baseballcap"};
				memberSelections[] = {"Clipping_baseballcap","Clipping_BeanieHat"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_MedicalScrubs_Hat"};
				memberSelections[] = {"Clipping_MedicalScrubs_Hat","Clipping_RadarCap","Clipping_ZmijovkaCap"};
			};
		};
	};
	class MaleBorisHead: Head_Default
	{
		model = "\dz\characters\heads\m_boris.p3d";
		hiddenSelectionsTextures[] = {"",""};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_grathelm","Clipping_ConstructionHelmet","Clipping_BandanaFace","Clipping_MotoHelmet","Clipping_NioshFaceMask","Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_Welding_Mask ","Clipping_Gasmask "};
			};
		};
	};
	class MaleCyrilHead: Head_Default
	{
		model = "\dz\characters\heads\m_cyril.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Cyril\hhl_m_Cyril_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Cyril\hhl_m_Cyril_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_NBC_Hood","Clipping_TankerHelmet","Clipping_RadarCap","Clipping_BeanieHat","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_NioshFaceMask"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_grathelm","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_MotoHelmet"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_ConstructionHelmet","Clipping_FireHelmet","Clipping_BoonieHat","Clipping_prison_cap","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_baseballcap","Clipping_MilitaryBeret","Clipping_Policecap","Clipping_OfficerHat"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_MedicalScrubs_Hat"};
				memberSelections[] = {"Clipping_MedicalScrubs_Hat","Clipping_Hockey_hekmet","Clipping_SantasHat"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_ProtecSkateHelmet2"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_HelmetMich"};
				memberSelections[] = {"Clipping_HelmetMich","Clipping_Maska"};
			};
		};
	};
	class MaleDenisHead: Head_Default
	{
		model = "\dz\characters\heads\m_Denis_2.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Denis_2\hhl_m_Denis_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Denis_2\hhl_m_Denis_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_NBC_Hood","Clipping_TankerHelmet","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_SantasBeard","Clipping_Surgical_mask"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_grathelm","Clipping_MotoHelmet","Clipping_Balaclava"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FireHelmet"};
				memberSelections[] = {"Clipping_FireHelmet","Clipping_HeloHelmet"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_BoonieHat"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_MxHelmet","Clipping_SantasHat","Clipping_Mich2001","Clipping_constructionHelmet","Clipping_Hockey_hekmet","Clipping_ProtecSkateHelmet2","Clipping_CowboyHat"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_OfficerHat"};
				memberSelections[] = {"Clipping_OfficerHat","Clipping_Policecap","Clipping_MilitaryBeret","Clipping_baseballcap","Clipping_MedicalScrubs_Hat","Clipping_BandanaHead","Clipping_Hat_Leather"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_BeanieHat"};
				memberSelections[] = {"Clipping_BeanieHat","Clipping_RadarCap","Clipping_Maska","Clipping_ZmijovkaCap"};
			};
			class Group_4
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_ushanka"};
			};
		};
	};
	class MaleEliasHead: Head_Default
	{
		model = "\dz\characters\heads\m_elias.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Elias\hhl_m_Elias_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Elias\hhl_m_Elias_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_ConstructionHelmet","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet","Clipping_BoonieHat","Clipping_prison_cap","Clipping_MilitaryBeret_xx","Clipping_Policecap","Clipping_OfficerHat","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_SantasHat","Clipping_FlatCap","Clipping_baseballcap","Clipping_BeanieHat","Clipping_MedicalScrubs_Hat","Clipping_RadarCap","Clipping_ZmijovkaCap","Clipping_HeloHelmet","Clipping_WitchHood","Clipping_WitchHat"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_BandanaFace","Clipping_SantasBeard","Clipping_Surgical_mask"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_MotoHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_Hockey_hekmet","Clipping_ProtecSkateHelmet2","Clipping_MxHelmet"};
			};
		};
	};
	class MaleFrancisHead: Head_Default
	{
		model = "\dz\characters\heads\m_francis.p3d";
		hiddenSelectionsTextures[] = {"",""};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Francis\hhl_m_Francis_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_BandanaFace","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_MotoHelmet","Clipping_Gasmask","Clipping_Welding_Mask"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_Hockey_hekmet"};
				memberSelections[] = {"Clipping_Hockey_hekmet","Clipping_ProtecSkateHelmet2"};
			};
		};
	};
	class MaleGuoHead: Head_Default
	{
		model = "\dz\characters\heads\m_guo.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Guo\hhl_m_Guo_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Guo\hhl_m_Guo_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_NBC_Hood","Clipping_Hockey_hekmet","Clipping_FireHelmet","Clipping_ConstructionHelmet","Clipping_ProtecSkateHelmet2","Clipping_ushanka","Clipping_HeloHelmet","Clipping_TankerHelmet","Clipping_BoonieHat","Clipping_BeanieHat","Clipping_RadarCap"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_NioshFaceMask","Clipping_Welding_Mask","Clipping_BandanaFace","Clipping_SantasBeard","Clipping_Surgical_mask"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_MotoHelmet","Clipping_grathelm","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_SantasHat","Clipping_BandanaHead","Clipping_CowboyHat","Clipping_Hat_Leather","Clipping_OfficerHat","Clipping_Policecap","Clipping_baseballcap"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_MedicalScrubs_Hat"};
				memberSelections[] = {"Clipping_MedicalScrubs_Hat","Clipping_ZmijovkaCap"};
			};
		};
	};
	class MaleHassanHead: Head_Default
	{
		model = "\dz\characters\heads\m_Hassan.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Hassan\hhl_m_Hassan_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Hassan\hhl_m_Hassan_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_ConstructionHelmet","Clipping_Hockey_hekmet","Clipping_Maska","Clipping_ProtecSkateHelmet2","Clipping_NBC_Hood","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet","Clipping_BoonieHat","Clipping_prison_cap","Clipping_MilitaryBeret","Clipping_Policecap","Clipping_OfficerHat","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_SantasHat","Clipping_FlatCap","Clipping_baseballcap","Clipping_BeanieHat","Clipping_MedicalScrubs_Hat","Clipping_RadarCap","Clipping_ZmijovkaCap","Clipping_HeloHelmet","Clipping_HelmetMich","Clipping_Ssh68Helmet"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_BandanaFace","Clipping_NioshFaceMask","Clipping_SantasBeard","Clipping_Surgical_mask"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_grathelm","Clipping_MotoHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_HelmetMich"};
				memberSelections[] = {"Clipping_HelmetMich","Clipping_Ssh68Helmet"};
			};
		};
	};
	class MaleIndarHead: Head_Default
	{
		model = "\dz\characters\heads\m_Indar.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Indar\hhl_m_Indar_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Indar\hhl_m_Indar_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_BandanaFace"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_MotoHelmet"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_prison_cap","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_SantasHat","Clipping_FlatCap","Clipping_baseballcap","Clipping_MilitaryBeret","Clipping_Policecap","Clipping_OfficerHat","Clipping_ConstructionHelmet","Clipping_Hockey_hekmet"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_MedicalScrubs_Hat"};
				memberSelections[] = {"Clipping_MedicalScrubs_Hat","Clipping_RadarCap","Clipping_ZmijovkaCap","Clipping_BeanieHat","Clipping_HeloHelmet"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_ProtecSkateHelmet2"};
			};
		};
	};
	class MaleJoseHead: Head_Default
	{
		model = "\dz\characters\heads\m_Jose.p3d";
		hiddenSelectionsTextures[] = {"",""};
		hiddenSelectionsMaterials[] = {"",""};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_BandanaFace","Clipping_NioshFaceMask","Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_Gasmask","Clipping_Welding_Mask"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_Ssh68Helmet"};
			};
		};
	};
	class MaleKaitoHead: Head_Default
	{
		model = "\dz\characters\heads\m_Kaito.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Kaito\hhl_m_Kaito_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Kaito\hhl_m_kaito_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_NBC_Hood","Clipping_MotoHelmet","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet","Clipping_RadarCap","Clipping_ZmijovkaCap","Clipping_BandanaHead","Clipping_Hockey_hekmet"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_NioshFaceMask","Clipping_BandanaFace"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_baseballcap","Clipping_CowboyHat","Clipping_Hat_leather","Clipping_OfficerHat","Clipping_Policecap","Clipping_MilitaryBeret","Clipping_prison_cap","Clipping_BoonieHat","Clipping_ConstructionHelmet"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_Ssh68Helmet"};
				memberSelections[] = {"Clipping_Ssh68Helmet","Clipping_ProtecSkateHelmet2"};
			};
		};
	};
	class MaleLewisHead: Head_Default
	{
		model = "\dz\characters\heads\m_Lewis.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Lewis\hhl_m_Lewis_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Lewis\hhl_m_Lewis_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_unshaved.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_bearded.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_bearded_injury2.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_ConstructionHelmet","Clipping_Hockey_hekmet","Clipping_HeloHelmet","Clipping_NBC_Hood","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet","Clipping_BeanieHat","Clipping_RadarCap"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_NioshFaceMask","Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_Welding_Mask","Clipping_BandanaFace"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_grathelm","Clipping_MotoHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_prison_cap","Clipping_FlatCap","Clipping_SantasHat","Clipping_BandanaHead","Clipping_CowboyHat","Clipping_Hat_leather","Clipping_OfficerHat","Clipping_Policecap","Clipping_MilitaryBeret","Clipping_baseballcap","Clipping_MedicalScrubs_Hat","Clipping_ZmijovkaCap","Clipping_HeadTorch"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_ProtecSkateHelmet2","Clipping_MxHelmet"};
			};
		};
	};
	class MaleManuaHead: Head_Default
	{
		model = "\dz\characters\heads\m_Manua.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Manua\hhl_m_Manua_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Manua\hhl_m_Manua_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_unshaved.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_bearded.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_bearded_injury2.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_BeanieHat","Clipping_FireHelmet","Clipping_RadarCap","Clipping_grathelm","Clipping_NBC_Hood","Clipping_TankerHelmet"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_SantasBeard"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_MotoHelmet"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_BandanaHead"};
				memberSelections[] = {"Clipping_BandanaHead","Clipping_SantasHat","Clipping_Maska"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_baseballcap","Clipping_OfficerHat","Clipping_Policecap","Clipping_prison_cap","Clipping_Hat_leather","Clipping_MilitaryBeret_xx","Clipping_ConstructionHelmet","Clipping_CowboyHat"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_HeloHelmet"};
				memberSelections[] = {"Clipping_HeloHelmet","Clipping_Hockey_hekmet"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_ProtecSkateHelmet2","Clipping_Ssh68Helmet"};
			};
			class Group_4
			{
				simpleSelectionName[] = {"Clipping_ushanka"};
				memberSelections[] = {"Clipping_ushanka","Clipping_ZmijovkaCap"};
			};
		};
	};
	class MaleNikiHead: Head_Default
	{
		model = "\dz\characters\heads\m_Niki_2.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Niki_2\hhl_m_Niki_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Niki_2\hhl_m_Niki_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_unshaved.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_bearded.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_bearded_injury2.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_NBC_Hood","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet","Clipping_RadarCap","Clipping_ZmijovkaCap","Clipping_BeanieHat","Clipping_grathelm"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_BandanaFace"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_MotoHelmet"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_baseballcap","Clipping_CowboyHat","Clipping_Hat_leather","Clipping_MilitaryBeret","Clipping_prison_cap","Clipping_BoonieHat","Clipping_HeloHelmet","Clipping_ConstructionHelmet"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_MedicalScrubs_Hat"};
				memberSelections[] = {"Clipping_MedicalScrubs_Hat","Clipping_ProtecSkateHelmet2"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_BandanaHead"};
				memberSelections[] = {"Clipping_BandanaHead","Clipping_Hockey_hekmet","Clipping_SantasHat"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_OfficerHat"};
				memberSelections[] = {"Clipping_OfficerHat","Clipping_Policecap"};
			};
		};
	};
	class MaleOliverHead: Head_Default
	{
		model = "\dz\characters\heads\m_Oliver.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Oliver\hhl_m_Oliver_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Oliver\hhl_m_Oliver_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_unshaved.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_bearded.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_bearded_injury2.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_NBC_Hood","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_BandanaFace","Clipping_NioshFaceMask"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_MotoHelmet"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_BoonieHat","Clipping_prison_cap","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_SantasHat","Clipping_FlatCap","Clipping_baseballcap","Clipping_MilitaryBeret","Clipping_Policecap","Clipping_OfficerHat"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_MedicalScrubs_Hat"};
				memberSelections[] = {"Clipping_MedicalScrubs_Hat","Clipping_RadarCap","Clipping_ZmijovkaCap","Clipping_BeanieHat","Clipping_HeadTorch"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_ProtecSkateHelmet2"};
			};
		};
	};
	class MalePeterHead: Head_Default
	{
		model = "\dz\characters\heads\m_Peter.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Peter\hhl_m_Peter_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Peter\hhl_m_Peter_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_BeanieHat","Clipping_RadarCap","Clipping_grathelm"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_BandanaFace","Clipping_NioshFaceMask","Clipping_SantasBeard","Clipping_Surgical_mask"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_MotoHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_ConstructionHelmet","Clipping_BoonieHat","Clipping_prison_cap"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_baseballcap"};
				memberSelections[] = {"Clipping_MedicalScrubs_Hat","Clipping_FireHelmet","Clipping_SantasHat","Clipping_BandanaHead","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_OfficerHat","Clipping_Policecap","Clipping_MilitaryBeret","Clipping_baseballcap"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_ushanka"};
				memberSelections[] = {"Clipping_ushanka","Clipping_ZmijovkaCap"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_ProtecSkateHelmet2"};
			};
		};
	};
	class MaleQuinnHead: Head_Default
	{
		model = "\dz\characters\heads\m_Quinn.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Quinn\hhl_m_Quinn_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Quinn\hhl_m_Quinn_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_unshaved.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_bearded.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_bearded_injury2.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_GhillieHood","Clipping_FireHelmet","Clipping_ushanka","Clipping_BeanieHat","Clipping_RadarCap","Clipping_HeloHelmet","Clipping_grathelm"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_BandanaFace","Clipping_SantasBeard","Clipping_Surgical_mask"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_MotoHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_ConstructionHelmet","Clipping_BoonieHat","Clipping_prison_cap","Clipping_FlatCap","Clipping_SantasHat","Clipping_BandanaHead","Clipping_CowboyHat","Clipping_Hat_leather","Clipping_OfficerHat","Clipping_Policecap","Clipping_MilitaryBeret","Clipping_baseballcap","Clipping_MedicalScrubs_Hat","Clipping_ZmijovkaCap","Clipping_HeadTorch"};
			};
		};
	};
	class MaleRolfHead: Head_Default
	{
		model = "\dz\characters\heads\m_Rolf.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Rolf\hhl_m_Rolf_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Rolf\hhl_m_Rolf_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_unshaved.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_bearded.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_bearded_injury2.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_pilotka","Clipping_ZmijovkaCap","Clipping_BeanieHat","Clipping_RadarCap","Clipping_MedicalScrubs_Hat","Clipping_BoonieHat","Clipping_prison_cap","Clipping_Hat_leather","Clipping_CowboyHat","Clipping_BandanaHead","Clipping_SantasHat","Clipping_FlatCap","Clipping_baseballcap","Clipping_MilitaryBeret","Clipping_Policecap","Clipping_OfficerHat","Clipping_FireHelmet","Clipping_ushanka"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_SantasBeard","Clipping_Surgical_mask","Clipping_BandanaFace"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_grathelm","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask","Clipping_MotoHelmet"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_ProtecSkateHelmet2"};
			};
		};
	};
	class MaleSethHead: Head_Default
	{
		model = "\dz\characters\heads\m_Seth.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Seth\hhl_m_Seth_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Seth\hhl_m_Seth_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_unshaved.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_bearded.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_bearded_injury2.rvmat"};
		};
		class HairHiding
		{
			class Group_Hair
			{
				simpleSelectionName[] = {"hair"};
				memberSelections[] = {"Clipping_grathelm","Clipping_MedicalScrubs_Hat","Clipping_Hockey_helmet","Clipping_Maska","Clipping_FireHelmet","Clipping_ushanka","Clipping_TankerHelmet","Clipping_BoonieHat","Clipping_prison_cap","Clipping_SantasHat","Clipping_BandanaHead","Clipping_CowboyHat","Clipping_Hat_leather","Clipping_baseballcap","Clipping_BeanieHat","Clipping_RadarCap","Clipping_ZmijovkaCap","Clipping_HeloHelmet"};
			};
			class Group_Beard
			{
				simpleSelectionName[] = {"beard"};
				memberSelections[] = {"Clipping_BandanaFace","Clipping_SantasBeard","Clipping_Surgical_mask"};
			};
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_MotoHelmet","Clipping_PumpkinHelmet","Clipping_Balaclava_3holes","Clipping_Balaclava","Clipping_GP5GasMask"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_Ssh68Helmet"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_FlatCap"};
				memberSelections[] = {"Clipping_FlatCap","Clipping_ConstructionHelmet","Clipping_MilitaryBeret_xx"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_OfficerHat"};
				memberSelections[] = {"Clipping_OfficerHat","Clipping_Policecap"};
			};
		};
	};
	class MaleTaikiHead: Head_Default
	{
		model = "\dz\characters\heads\m_Taiki.p3d";
		hiddenSelectionsTextures[] = {"","dz\characters\heads\data\m_Taiki\hhl_m_Taiki_hair_ca.paa"};
		hiddenSelectionsMaterials[] = {"","dz\characters\heads\data\m_Taiki\hhl_m_Taiki_hair.rvmat"};
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_unshaved.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_bearded.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_bearded_injury2.rvmat"};
		};
		class HairHiding
		{
			class Group_HairBeard
			{
				simpleSelectionName[] = {"hair","beard"};
				memberSelections[] = {"Clipping_Balaclava_3holes"};
			};
			class Group_0
			{
				simpleSelectionName[] = {"Clipping_baseballcap"};
				memberSelections[] = {"Clipping_baseballcap","Clipping_ConstructionHelmet","Clipping_ushanka","Clipping_TankerHelmet","Clipping_Balaclava","Clipping_BoonieHat","Clipping_SantasHat","Clipping_BandanaHead","Clipping_CowboyHat","Clipping_Hat_leather"};
			};
			class Group_1
			{
				simpleSelectionName[] = {"Clipping_MxHelmet"};
				memberSelections[] = {"Clipping_MxHelmet","Clipping_NBC_Hood"};
			};
			class Group_2
			{
				simpleSelectionName[] = {"Clipping_GP5GasMask"};
				memberSelections[] = {"Clipping_GP5GasMask","Clipping_MotoHelmet"};
			};
			class Group_3
			{
				simpleSelectionName[] = {"Clipping_OfficerHat"};
				memberSelections[] = {"Clipping_OfficerHat","Clipping_Policecap","Clipping_MilitaryBeret_xx"};
			};
			class Group_4
			{
				simpleSelectionName[] = {"Clipping_BeanieHat"};
				memberSelections[] = {"Clipping_BeanieHat","Clipping_RadarCap","Clipping_MedicalScrubs_Hat","Clipping_ZmijovkaCap"};
			};
		};
	};
	class MaleAdamHead_BeardStart: MaleAdamHead
	{
		simpleHiddenSelections[] = {"beard","hair","Clipping_Gasmask"};
	};
	class MaleAdamHead_BeardEnd: MaleAdamHead
	{
		simpleHiddenSelections[] = {"Clipping_Gasmask","beard","hair"};
	};
};
class CfgNonAIVehicles
{
	class ProxyBysta
	{
		autocenter = 0;
		scope = 2;
		reversed = 1;
		animated = 1;
		model = "";
		simulation = "ProxySubpart";
	};
};
class MaskFaceDZ
{
	mask[] = {"Face_BrowFrontLeft",1,"Face_BrowFrontRight",1,"Face_BrowMiddle",1,"Face_BrowSideLeft",1,"Face_BrowSideRight",1,"Face_CornerLeft",1,"Face_CornerRight",1,"Face_Eyelids",1,"Face_Forehead",1,"Face_CheekFrontLeft",1,"Face_CheekFrontRight",1,"Face_CheekSideLeft",1,"Face_CheekSideRight",1,"Face_CheekUpperLeft",1,"Face_CheekUpperRight",1,"Face_Chin",1,"Face_ChopLeft",1,"Face_ChopRight",1,"Face_Jawbone",1,"Face_Jowl",1,"Face_LipLowerLeft",1,"Face_LipLowerMiddle",1,"Face_LipLowerRight",1,"Face_LipUpperLeft",1,"Face_LipUpperMiddle",1,"Face_LipUpperRight",1,"Face_NostrilLeft",1,"Face_NostrilRight",1,"Face_Tongue",1};
};
class EyeMask
{
	mask[] = {"Face_EyelidUpperRight",1,"Face_EyelidLowerRight",1,"Face_EyelidUpperLeft",1,"Face_EyelidLowerLeft",1,"EyeLeft",0.4,"EyeRight",0.4};
};
class MaskLipDZ
{
	mask[] = {"Face_BrowFrontLeft",0.5,"Face_BrowFrontRight",0.5,"Face_BrowMiddle",0.5,"Face_BrowSideLeft",0.5,"Face_BrowSideRight",0.5,"Face_CornerLeft",0.5,"Face_CornerRight",0.5,"Face_Forehead",0.5,"Face_CheekFrontLeft",0.5,"Face_CheekFrontRight",0.5,"Face_CheekSideLeft",0.5,"Face_CheekSideRight",0.5,"Face_CheekUpperLeft",0.5,"Face_CheekUpperRight",0.5,"Face_Chin",0.5,"Face_ChopLeft",0.5,"Face_ChopRight",0.5,"Face_Jawbone",0.5,"Face_Jowl",0.5,"Face_LipLowerLeft",0.5,"Face_LipLowerMiddle",0.5,"Face_LipLowerRight",0.5,"Face_LipUpperLeft",0.5,"Face_LipUpperMiddle",0.5,"Face_LipUpperRight",0.5,"Face_NostrilLeft",0.5,"Face_NostrilRight",0.5,"Face_Tongue",0.5};
};
class CfgHeads
{
	class Default
	{
		model = "\DZ\Characters\Heads\m_white_01_above0.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
		selectionHeadWound = "injury_head";
		selectionPersonality = "personality";
		class Grimaces
		{
			class Eyes
			{
				type = "eyes";
				eyeMaxAngle = 0.15;
				eyelidUpStartAngle = 0.4;
				eyelidUpMaxAngle = 1.0;
				eyelidDownStartAngle = 0.09;
				eyelidDownMaxAngle = 0.3;
			};
			class Lipsync
			{
				type = "lipsync";
				vizem[] = {"dz\anims\data\anim\fce\Neutral.rtm","dz\anims\data\anim\fce\vizem\a.rtm","dz\anims\data\anim\fce\vizem\e2.rtm","dz\anims\data\anim\fce\vizem\f.rtm","dz\anims\data\anim\fce\vizem\m.rtm","dz\anims\data\anim\fce\vizem\y.rtm","dz\anims\data\anim\fce\vizem\v.rtm","dz\anims\data\anim\fce\vizem\i.rtm"};
			};
			class RTM_Face
			{
				type = "rtm";
				anim = "dz\anims\data\anim\fce\Neutral.rtm";
			};
			class NeutralFace: RTM_Face
			{
				anim = "dz\anims\data\anim\fce\Neutral.rtm";
			};
			class DeadFace: RTM_Face
			{
				anim = "dz\anims\data\anim\fce\Dead.rtm";
			};
			class DangerFace: RTM_Face
			{
				anim = "dz\anims\data\anim\fce\Danger.rtm";
			};
			class HurtFace: RTM_Face
			{
				anim = "dz\anims\data\anim\fce\Hurt.rtm";
			};
			class AwareFace: RTM_Face
			{
				anim = "dz\anims\data\anim\fce\Aware.rtm";
			};
			class SafeFace: RTM_Face
			{
				anim = "dz\anims\data\anim\fce\Safe.rtm";
			};
			class CombatFace: RTM_Face
			{
				anim = "dz\anims\data\anim\fce\Combat.rtm";
			};
			class Neutral
			{
				type = "compound";
				class Items
				{
					class NeutralFace: MaskFaceDZ{};
					class Lipsync: MaskLipDZ{};
					class Eyes: EyeMask{};
				};
			};
			class Dead
			{
				type = "compound";
				class Items
				{
					class DeadFace: MaskFaceDZ{};
					class Eyes: EyeMask{};
				};
			};
			class Unconscious
			{
				type = "compound";
				class Items
				{
					class UnconsciousFace: MaskFaceDZ{};
				};
			};
			class Danger
			{
				type = "compound";
				class Items
				{
					class DangerFace: MaskFaceDZ{};
					class Lipsync: MaskLipDZ{};
					class Eyes: EyeMask{};
				};
			};
			class Hurt
			{
				type = "compound";
				class Items
				{
					class HurtFace: MaskFaceDZ{};
					class Lipsync: MaskLipDZ{};
					class Eyes: EyeMask{};
				};
			};
			class Aware
			{
				type = "compound";
				class Items
				{
					class AwareFace: MaskFaceDZ{};
					class Lipsync: MaskLipDZ{};
					class Eyes: EyeMask{};
				};
			};
			class Safe
			{
				type = "compound";
				class Items
				{
					class SafeFace: MaskFaceDZ{};
					class Lipsync: MaskLipDZ{};
					class Eyes: EyeMask{};
				};
			};
			class Combat
			{
				type = "compound";
				class Items
				{
					class CombatFace: MaskFaceDZ{};
					class Lipsync: MaskLipDZ{};
					class Eyes: EyeMask{};
				};
			};
		};
	};
	class FemaleFridaHead: Default
	{
		model = "\dz\characters\heads\f_Frida_2.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class FemaleGabiHead: Default
	{
		model = "\dz\characters\heads\f_Gabi_2.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class FemaleHelgaHead: Default
	{
		model = "\dz\characters\heads\f_Helga.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class FemaleIrenaHead: Default
	{
		model = "\dz\characters\heads\f_Irena_2.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class FemaleJudyHead: Default
	{
		model = "\dz\characters\heads\f_Judy.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class FemaleKeikoHead: Default
	{
		model = "\dz\characters\heads\f_Keiko.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class FemaleLindaHead: Default
	{
		model = "\dz\characters\heads\f_Linda_2.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class FemaleMariaHead: Default
	{
		model = "\dz\characters\heads\f_Maria_2.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class FemaleNaomiHead: Default
	{
		model = "\dz\characters\heads\f_Naomi.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat","DZ\Characters\Heads\Data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class FemaleEvaHead: Default
	{
		model = "\dz\characters\heads\f_Eva_2.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleAdamHead: Default
	{
		model = "\dz\characters\heads\m_adam.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleBorisHead: Default
	{
		model = "\dz\characters\heads\m_boris.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleCyrilHead: Default
	{
		model = "\dz\characters\heads\m_cyril.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleDenisHead: Default
	{
		model = "\dz\characters\heads\m_Denis_2.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleEliasHead: Default
	{
		model = "\dz\characters\heads\m_elias.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleFrancisHead: Default
	{
		model = "\dz\characters\heads\m_francis.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleGuoHead: Default
	{
		model = "\dz\characters\heads\m_guo.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleHassanHead: Default
	{
		model = "\dz\characters\heads\m_Hassan.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleIndarHead: Default
	{
		model = "\dz\characters\heads\m_Indar.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleJoseHead: Default
	{
		model = "\dz\characters\heads\m_Jose.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleKaitoHead: Default
	{
		model = "\dz\characters\heads\m_Kaito.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleLewisHead: Default
	{
		model = "\dz\characters\heads\m_Lewis.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_unshaved.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_bearded.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_bearded_injury2.rvmat"};
		};
	};
	class MaleManuaHead: Default
	{
		model = "\dz\characters\heads\m_Manua.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_unshaved.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_bearded.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_bearded_injury2.rvmat"};
		};
	};
	class MaleNikiHead: Default
	{
		model = "\dz\characters\heads\m_Niki_2.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_unshaved.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_bearded.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_bearded_injury2.rvmat"};
		};
	};
	class MaleOliverHead: Default
	{
		model = "\dz\characters\heads\m_Oliver.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_unshaved.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_bearded.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_bearded_injury2.rvmat"};
		};
	};
	class MalePeterHead: Default
	{
		model = "\dz\characters\heads\m_Peter.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat","DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
		};
	};
	class MaleQuinnHead: Default
	{
		model = "\dz\characters\heads\m_Quinn.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_unshaved.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_bearded.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_bearded_injury2.rvmat"};
		};
	};
	class MaleRolfHead: Default
	{
		model = "\dz\characters\heads\m_Rolf.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_unshaved.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_bearded.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_bearded_injury2.rvmat"};
		};
	};
	class MaleSethHead: Default
	{
		model = "\dz\characters\heads\m_Seth.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_unshaved.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_bearded.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_bearded_injury2.rvmat"};
		};
	};
	class MaleTaikiHead: Default
	{
		model = "\dz\characters\heads\m_Taiki.p3d";
		class Wounds
		{
			tex[] = {};
			mat[] = {"DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved_injury.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved_injury2.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_unshaved.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_unshaved_injury.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_unshaved_injury2.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_bearded.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_bearded_injury.rvmat","DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_bearded_injury2.rvmat"};
		};
	};
};
