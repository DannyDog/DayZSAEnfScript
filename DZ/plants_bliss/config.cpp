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
	class DZ_Plants_Bliss
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgNonAIVehicles
{
	class BushHard;
	class BushSoft;
	class TreeSoft;
	class TreeHard;
	class BushSoft_b_betulaNana_1s_summer: BushSoft{};
	class BushSoft_b_corylusHeterophylla_1s_summer: BushSoft{};
	class BushSoft_b_FagusSylvatica_1f_summer: BushSoft{};
	class BushSoft_b_rosaCanina_1s_summer: BushSoft{};
	class BushSoft_b_rosaCanina_2s_summer: BushSoft{};
	class BushSoft_b_sambucusNigra_1s_summer: BushSoft{};
	class BushSoft_b_PiceaAbies_1f_summer: BushSoft{};
	class BushSoft_t_PinusSylvestris_1s_summer: BushSoft{};
	class BushHard_b_caraganaArborescens_2s_summer: BushHard{};
	class BushHard_b_corylusHeterophylla_2s_summer: BushHard{};
	class BushHard_b_prunusSpinosa_1s_summer: BushHard{};
	class BushHard_b_prunusSpinosa_2s_summer: BushHard{};
	class BushHard_b_sambucusNigra_2s_summer: BushHard{};
	class BushHard_b_PiceaAbies_1fb_summer: BushHard{};
	class BushHard_t_FagusSylvatica_1fb_summer: BushHard{};
	class BushHard_t_PiceaAbies_1sb_summer: BushHard{};
	class BushHard_t_PiceaAbies_1s_summer: BushHard{};
	class BushHard_t_PinusSylvestris_1f_summer: BushHard{};
	class TreeSoft_t_BetulaPendulaE_1s_summer: TreeSoft{};
	class TreeSoft_t_BetulaPendulaE_2f_summer: TreeSoft{};
	class TreeSoft_t_BetulaPendulaE_2w_summer: TreeSoft{};
	class TreeSoft_t_FagusSylvatica_1fc_summer: TreeSoft{};
	class TreeSoft_t_FagusSylvatica_1fd_summer: TreeSoft{};
	class TreeSoft_t_FagusSylvatica_1f_summer: TreeSoft{};
	class TreeSoft_t_FagusSylvatica_1s_summer: TreeSoft{};
	class TreeSoft_t_FagusSylvatica_2sb_summer: TreeSoft{};
	class TreeSoft_t_FagusSylvatica_2sb_Trail_B_summer: TreeSoft{};
	class TreeSoft_t_FagusSylvatica_2sb_Trail_G_summer: TreeSoft{};
	class TreeSoft_t_FagusSylvatica_2sb_Trail_R_summer: TreeSoft{};
	class TreeSoft_t_FagusSylvatica_2sb_Trail_Y_summer: TreeSoft{};
	class TreeSoft_t_malusDomestica_2s_summer: TreeSoft{};
	class TreeSoft_t_malusDomestica_3s_summer: TreeSoft{};
	class TreeSoft_t_PiceaAbies_1f_summer: TreeSoft{};
	class TreeSoft_t_LarixDecidua_1f_summer: TreeSoft{};
	class TreeSoft_t_LarixDecidua_1s_summer: TreeSoft{};
	class TreeSoft_t_PiceaAbies_2sb_summer: TreeSoft{};
	class TreeSoft_t_pyrusCommunis_2s_summer: TreeSoft{};
	class TreeHard_t_acer_2s_summer: TreeHard{};
	class TreeHard_t_BetulaPendulaE_2s_summer: TreeHard{};
	class TreeHard_t_BetulaPendulaE_3f_summer: TreeHard{};
	class TreeHard_t_BetulaPendulaE_3s_summer: TreeHard{};
	class TreeHard_t_FagusSylvaticaE_2s_summer: TreeHard{};
	class TreeHard_t_FagusSylvaticaE_3f_summer: TreeHard{};
	class TreeHard_t_FagusSylvatica_1fe_summer: TreeHard{};
	class TreeHard_t_FagusSylvatica_2d_summer: TreeHard{};
	class TreeHard_t_FagusSylvatica_2fb_summer: TreeHard{};
	class TreeHard_t_FagusSylvatica_2fc_summer: TreeHard{};
	class TreeHard_t_FagusSylvatica_2f_summer: TreeHard{};
	class TreeHard_t_FagusSylvatica_2s_summer: TreeHard{};
	class TreeHard_t_FagusSylvatica_3d_summer: TreeHard{};
	class TreeHard_t_FagusSylvatica_3fb_summer: TreeHard{};
	class TreeHard_t_FagusSylvatica_3f_summer: TreeHard{};
	class TreeHard_t_FagusSylvatica_3s_summer: TreeHard{};
	class TreeHard_t_juglansRegia_2s_summer: TreeHard{};
	class TreeHard_t_juglansRegia_3s_summer: TreeHard{};
	class TreeHard_t_LarixDecidua_2f_summer: TreeHard{};
	class TreeHard_t_LarixDecidua_2fb_summer: TreeHard{};
	class TreeHard_t_LarixDecidua_2s_summer: TreeHard{};
	class TreeHard_t_LarixDecidua_3f_summer: TreeHard{};
	class TreeHard_t_LarixDecidua_3fb_summer: TreeHard{};
	class TreeHard_t_PiceaAbies_2fb_summer: TreeHard{};
	class TreeHard_t_PiceaAbies_2f_summer: TreeHard{};
	class TreeHard_t_PiceaAbies_2s_summer: TreeHard{};
	class TreeHard_t_PiceaAbies_3f_summer: TreeHard{};
	class TreeHard_t_PiceaAbies_3f_Trail_B_summer: TreeHard{};
	class TreeHard_t_PiceaAbies_3f_Trail_G_summer: TreeHard{};
	class TreeHard_t_PiceaAbies_3f_Trail_R_summer: TreeHard{};
	class TreeHard_t_PiceaAbies_3f_Trail_Y_summer: TreeHard{};
	class TreeHard_t_PiceaAbies_3s_summer: TreeHard{};
	class TreeHard_t_PinusSylvestris_2fb_summer: TreeHard{};
	class TreeHard_t_PinusSylvestris_2f_summer: TreeHard{};
	class TreeHard_t_PinusSylvestris_2sb_summer: TreeHard{};
	class TreeHard_t_PinusSylvestris_2s_summer: TreeHard{};
	class TreeHard_t_PinusSylvestris_3d_summer: TreeHard{};
	class TreeHard_t_PinusSylvestris_3fb_summer: TreeHard{};
	class TreeHard_t_PinusSylvestris_3fc_summer: TreeHard{};
	class TreeHard_t_PinusSylvestris_3f_summer: TreeHard{};
	class TreeHard_t_PinusSylvestris_3s_summer: TreeHard{};
	class TreeHard_t_populusNigra_3sb_summer: TreeHard{};
	class TreeHard_t_pyrusCommunis_3s_summer: TreeHard{};
	class TreeHard_t_salixAlba_2sb_summer: TreeHard{};
	class TreeHard_t_sorbus_2s_summer: TreeHard{};
};
