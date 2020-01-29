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
	class DZ_Characters_Shoes
	{
		units[] = {"athleticShoes","HikingBoots","MaleFeet","FemaleFeet"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class MaleFeet_Base: Inventory_Base
	{
		scope = 1;
		displayName = "$STR_MaleFeet_Base0";
		model = "\DZ\characters\shoes\feet3_m.p3d";
		inventorySlot[] = {"Feet"};
		hiddenSelections[] = {"personality"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.843137,0.768627,0.658824,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"};
	};
	class MaleAdamFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat"};
	};
	class MaleBorisFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved.rvmat"};
	};
	class MaleCyrilFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved.rvmat"};
	};
	class MaleDenisFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved.rvmat"};
	};
	class MaleEliasFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved.rvmat"};
	};
	class MaleFrancisFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved.rvmat"};
	};
	class MaleGuoFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved.rvmat"};
	};
	class MaleHassanFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved.rvmat"};
	};
	class MaleIndarFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved.rvmat"};
	};
	class MaleJoseFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved.rvmat"};
	};
	class MaleKaitoFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved.rvmat"};
	};
	class MaleLewisFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved.rvmat"};
	};
	class MaleManuaFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved.rvmat"};
	};
	class MaleNikiFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved.rvmat"};
	};
	class MaleOliverFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved.rvmat"};
	};
	class MalePeterFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved.rvmat"};
	};
	class MaleQuinnFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved.rvmat"};
	};
	class MaleRolfFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved.rvmat"};
	};
	class MaleSethFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved.rvmat"};
	};
	class MaleTaikiFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved.rvmat"};
	};
	class FemaleFeet_Base: Inventory_Base
	{
		scope = 1;
		displayName = "$STR_FemaleFeet_Base0";
		model = "\DZ\characters\shoes\feet3_f.p3d";
		inventorySlot[] = {"Feet"};
		hiddenSelections[] = {"personality"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.843137,0.768627,0.658824,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\hhl_dummy_skin_material.rvmat"};
	};
	class FemaleEvaFeet: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Eva_2\hhl_f_Eva_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body.rvmat"};
	};
	class FemaleFridaFeet: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Frida_2\hhl_f_frida_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Frida_2\hhl_f_frida_body.rvmat"};
	};
	class FemaleGabiFeet: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body.rvmat"};
	};
	class FemaleHelgaFeet: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Helga\hhl_f_Helga_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Helga\hhl_f_Helga_body.rvmat"};
	};
	class FemaleIrenaFeet: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body.rvmat"};
	};
	class FemaleJudyFeet: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Judy\hhl_f_Judy_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Judy\hhl_f_Judy_body.rvmat"};
	};
	class FemaleKeikoFeet: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body.rvmat"};
	};
	class FemaleLindaFeet: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body.rvmat"};
	};
	class FemaleMariaFeet: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body.rvmat"};
	};
	class FemaleNaomiFeet: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body.rvmat"};
	};
	class MaleAdamDecayedFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\m_Adam\Adam_body_shaved_decayed.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat"};
	};
	class MaleAdamDecayedDarkFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\m_Adam\Adam_body_shaved_decayed_dark.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat"};
	};
	class MaleAdamDecayedLighterDarkFeet: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\m_Adam\Adam_body_shaved_decayed_lighter_dark.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat"};
	};
	class MaleAdamFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat"};
	};
	class MaleBorisFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved.rvmat"};
	};
	class MaleCyrilFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved.rvmat"};
	};
	class MaleDenisFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved.rvmat"};
	};
	class MaleEliasFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved.rvmat"};
	};
	class MaleFrancisFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved.rvmat"};
	};
	class MaleGuoFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved.rvmat"};
	};
	class MaleHassanFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved.rvmat"};
	};
	class MaleIndarFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved.rvmat"};
	};
	class MaleJoseFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved.rvmat"};
	};
	class MaleKaitoFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved.rvmat"};
	};
	class MaleLewisFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved.rvmat"};
	};
	class MaleManuaFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved.rvmat"};
	};
	class MaleNikiFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved.rvmat"};
	};
	class MaleOliverFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved.rvmat"};
	};
	class MalePeterFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved.rvmat"};
	};
	class MaleQuinnFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved.rvmat"};
	};
	class MaleRolfFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved.rvmat"};
	};
	class MaleSethFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved.rvmat"};
	};
	class MaleTaikiFeetDecayed: MaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved.rvmat"};
	};
	class FemaleEvaFeetDecayed: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Eva_2\hhl_f_Eva_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body.rvmat"};
	};
	class FemaleFridaFeetDecayed: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Frida_2\hhl_f_frida_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Frida_2\hhl_f_frida_body.rvmat"};
	};
	class FemaleGabiFeetDecayed: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body.rvmat"};
	};
	class FemaleHelgaFeetDecayed: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Helga\hhl_f_Helga_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Helga\hhl_f_Helga_body.rvmat"};
	};
	class FemaleIrenaFeetDecayed: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body.rvmat"};
	};
	class FemaleJudyFeetDecayed: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Judy\hhl_f_Judy_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Judy\hhl_f_Judy_body.rvmat"};
	};
	class FemaleKeikoFeetDecayed: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body.rvmat"};
	};
	class FemaleLindaFeetDecayed: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body.rvmat"};
	};
	class FemaleMariaFeetDecayed: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body.rvmat"};
	};
	class FemaleNaomiFeetDecayed: FemaleFeet_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body.rvmat"};
	};
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class AthleticShoes_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_AthleticShoes_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_AthleticShoes_ColorBase1";
		model = "\DZ\characters\shoes\athleticShoes_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,2};
		weight = 330;
		durability = 0.2;
		absorbency = 0.5;
		heatIsolation = 0.4;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		soundAttType = "Sneakers";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\athleticShoes_m.p3d";
			female = "\DZ\characters\shoes\athleticShoes_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\data\athleticShoes.rvmat"}},{0.7,{"DZ\characters\shoes\data\athleticShoes.rvmat"}},{0.5,{"DZ\characters\shoes\data\athleticShoes_damage.rvmat"}},{0.3,{"DZ\characters\shoes\data\athleticShoes_damage.rvmat"}},{0.0,{"DZ\characters\shoes\data\athleticShoes_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class AthleticShoes_Blue: AthleticShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\athleticShoes_blue_co.paa","\dz\characters\shoes\data\athleticShoes_blue_co.paa","\dz\characters\shoes\data\athleticShoes_blue_co.paa"};
	};
	class AthleticShoes_Black: AthleticShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\athleticShoes_black_co.paa","\dz\characters\shoes\data\athleticShoes_black_co.paa","\dz\characters\shoes\data\athleticShoes_black_co.paa"};
	};
	class AthleticShoes_Brown: AthleticShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\athleticShoes_brown_co.paa","\dz\characters\shoes\data\athleticShoes_brown_co.paa","\dz\characters\shoes\data\athleticShoes_brown_co.paa"};
	};
	class AthleticShoes_Green: AthleticShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\athleticShoes_green_co.paa","\dz\characters\shoes\data\athleticShoes_green_co.paa","\dz\characters\shoes\data\athleticShoes_green_co.paa"};
	};
	class AthleticShoes_Grey: AthleticShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\athleticShoes_grey_co.paa","\dz\characters\shoes\data\athleticShoes_grey_co.paa","\dz\characters\shoes\data\athleticShoes_grey_co.paa"};
	};
	class HikingBoots_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_HikingBoots_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_HikingBoots_ColorBase1";
		model = "\DZ\characters\shoes\hikingBoots_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,4};
		weight = 400;
		durability = 0.5;
		absorbency = 0.1;
		heatIsolation = 0.5;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		soundAttType = "Sneakers";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\hikingBoots_m.p3d";
			female = "\DZ\characters\shoes\hikingBoots_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\Data\hikingBoots.rvmat"}},{0.7,{"DZ\characters\shoes\Data\hikingBoots.rvmat"}},{0.5,{"DZ\characters\shoes\Data\hikingBoots_damage.rvmat"}},{0.3,{"DZ\characters\shoes\Data\hikingBoots_damage.rvmat"}},{0.0,{"DZ\characters\shoes\Data\hikingBoots_destruct.rvmat"}}};
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
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class HikingBoots_Brown: HikingBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\hikingBoots_brown_co.paa","\dz\characters\shoes\data\hikingBoots_brown_co.paa","\dz\characters\shoes\data\hikingBoots_brown_co.paa"};
	};
	class HikingBoots_Black: HikingBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\hikingBoots_black_co.paa","\dz\characters\shoes\data\hikingBoots_black_co.paa","\dz\characters\shoes\data\hikingBoots_black_co.paa"};
	};
	class HikingBootsLow_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_HikingBootsLow_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_HikingBootsLow_ColorBase1";
		model = "\DZ\characters\shoes\hikingBoots_low_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,3};
		weight = 270;
		durability = 0.5;
		absorbency = 0.25;
		heatIsolation = 0.35;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		soundAttType = "Sneakers";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\hikingBoots_low_m.p3d";
			female = "\DZ\characters\shoes\hikingBoots_low_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\Data\hikingBoots_low.rvmat"}},{0.7,{"DZ\characters\shoes\Data\hikingBoots_low.rvmat"}},{0.5,{"DZ\characters\shoes\Data\hikingBoots_low_damage.rvmat"}},{0.3,{"DZ\characters\shoes\Data\hikingBoots_low_damage.rvmat"}},{0.0,{"DZ\characters\shoes\Data\hikingBoots_low_destruct.rvmat"}}};
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
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class HikingBootsLow_Black: HikingBootsLow_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\HikingBoots_Low_black_co.paa","\DZ\characters\shoes\data\HikingBoots_Low_black_co.paa","\DZ\characters\shoes\data\HikingBoots_Low_black_co.paa"};
	};
	class HikingBootsLow_Blue: HikingBootsLow_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\HikingBoots_Low_blue_co.paa","\dz\characters\shoes\data\HikingBoots_Low_blue_co.paa","\dz\characters\shoes\data\HikingBoots_Low_blue_co.paa"};
	};
	class HikingBootsLow_Beige: HikingBootsLow_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\HikingBoots_Low_beige_co.paa","\dz\characters\shoes\data\HikingBoots_Low_beige_co.paa","\dz\characters\shoes\data\HikingBoots_Low_beige_co.paa"};
	};
	class HikingBootsLow_Grey: HikingBootsLow_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\HikingBoots_Low_grey_co.paa","\dz\characters\shoes\data\HikingBoots_Low_grey_co.paa","\dz\characters\shoes\data\HikingBoots_Low_grey_co.paa"};
	};
	class Wellies_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_Wellies_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_Wellies_ColorBase1";
		model = "\DZ\characters\shoes\wellies_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,4};
		weight = 700;
		durability = 0.5;
		repairableWithKits[] = {5};
		repairCosts[] = {30.0};
		absorbency = 0;
		heatIsolation = 0.4;
		soundAttType = "Boots";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\wellies_m.p3d";
			female = "\DZ\characters\shoes\wellies_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\Data\wellies.rvmat"}},{0.7,{"DZ\characters\shoes\Data\wellies.rvmat"}},{0.5,{"DZ\characters\shoes\Data\wellies_damage.rvmat"}},{0.3,{"DZ\characters\shoes\Data\wellies_damage.rvmat"}},{0.0,{"DZ\characters\shoes\Data\wellies_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 1;
					};
					class Blood
					{
						damage = 0.9;
					};
					class Shock
					{
						damage = 1;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 1;
					};
					class Blood
					{
						damage = 0.9;
					};
					class Shock
					{
						damage = 1;
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
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Wellies_Black: Wellies_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\wellies_black_co.paa","\DZ\characters\shoes\data\wellies_black_co.paa","\DZ\characters\shoes\data\wellies_black_co.paa"};
	};
	class Wellies_Brown: Wellies_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\wellies_brown_co.paa","\DZ\characters\shoes\data\wellies_brown_co.paa","\DZ\characters\shoes\data\wellies_brown_co.paa"};
	};
	class Wellies_Green: Wellies_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\wellies_green_co.paa","\DZ\characters\shoes\data\wellies_green_co.paa","\DZ\characters\shoes\data\wellies_green_co.paa"};
	};
	class Wellies_Grey: Wellies_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\wellies_grey_co.paa","\DZ\characters\shoes\data\wellies_grey_co.paa","\DZ\characters\shoes\data\wellies_grey_co.paa"};
	};
	class WorkingBoots_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_WorkingBoots_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_WorkingBoots_ColorBase1";
		model = "\DZ\characters\shoes\WorkingBoots_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,3};
		weight = 1100;
		durability = 0.5;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		absorbency = 0.3;
		heatIsolation = 0.35;
		soundAttType = "Boots";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\WorkingBoots_m.p3d";
			female = "\DZ\characters\shoes\WorkingBoots_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\Data\WorkingBoots.rvmat"}},{0.7,{"DZ\characters\shoes\Data\WorkingBoots.rvmat"}},{0.5,{"DZ\characters\shoes\Data\WorkingBoots_damage.rvmat"}},{0.3,{"DZ\characters\shoes\Data\WorkingBoots_damage.rvmat"}},{0.0,{"DZ\characters\shoes\Data\WorkingBoots_destruct.rvmat"}}};
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
						damage = 0.85;
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
						damage = 0.85;
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
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class WorkingBoots_Grey: WorkingBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\WorkingBoots_grey_co.paa","\DZ\characters\shoes\data\WorkingBoots_grey_co.paa","\DZ\characters\shoes\data\WorkingBoots_grey_co.paa"};
	};
	class WorkingBoots_Brown: WorkingBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\WorkingBoots_brown_co.paa","\DZ\characters\shoes\data\WorkingBoots_brown_co.paa","\DZ\characters\shoes\data\WorkingBoots_brown_co.paa"};
	};
	class WorkingBoots_Green: WorkingBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\WorkingBoots_green_co.paa","\DZ\characters\shoes\data\WorkingBoots_green_co.paa","\DZ\characters\shoes\data\WorkingBoots_green_co.paa"};
	};
	class WorkingBoots_Yellow: WorkingBoots_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\WorkingBoots_yellow_co.paa","\DZ\characters\shoes\data\WorkingBoots_yellow_co.paa","\DZ\characters\shoes\data\WorkingBoots_yellow_co.paa"};
	};
	class WorkingBoots_Beige: WorkingBoots_ColorBase
	{
		scope = 2;
		descriptionShort = "$STR_CfgVehicles_WorkingBoots_Beige0";
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\WorkingBoots_beige_co.paa","\DZ\characters\shoes\data\WorkingBoots_beige_co.paa","\DZ\characters\shoes\data\WorkingBoots_beige_co.paa"};
	};
	class JungleBoots_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_JungleBoots_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_JungleBoots_ColorBase1";
		model = "\DZ\characters\shoes\JungleBoots_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,4};
		weight = 1230;
		durability = 0.5;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		absorbency = 0.1;
		heatIsolation = 0.5;
		soundAttType = "Boots";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\JungleBoots_m.p3d";
			female = "\DZ\characters\shoes\JungleBoots_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 90;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\Data\JungleBoots.rvmat"}},{0.7,{"DZ\characters\shoes\Data\JungleBoots.rvmat"}},{0.5,{"DZ\characters\shoes\Data\JungleBoots_damage.rvmat"}},{0.3,{"DZ\characters\shoes\Data\JungleBoots_damage.rvmat"}},{0.0,{"DZ\characters\shoes\Data\JungleBoots_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.8;
					};
					class Blood
					{
						damage = 0.7;
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
						damage = 0.8;
					};
					class Blood
					{
						damage = 0.7;
					};
					class Shock
					{
						damage = 0.8;
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
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class JungleBoots_Beige: JungleBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\JungleBoots_beige_co.paa","\DZ\characters\shoes\data\JungleBoots_beige_co.paa","\DZ\characters\shoes\data\JungleBoots_beige_co.paa"};
	};
	class JungleBoots_Black: JungleBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\JungleBoots_black_co.paa","\DZ\characters\shoes\data\JungleBoots_black_co.paa","\DZ\characters\shoes\data\JungleBoots_black_co.paa"};
	};
	class JungleBoots_Brown: JungleBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\JungleBoots_brown_co.paa","\DZ\characters\shoes\data\JungleBoots_brown_co.paa","\DZ\characters\shoes\data\JungleBoots_brown_co.paa"};
	};
	class JungleBoots_Green: JungleBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.5;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\JungleBoots_green_co.paa","\DZ\characters\shoes\data\JungleBoots_green_co.paa","\DZ\characters\shoes\data\JungleBoots_green_co.paa"};
	};
	class JungleBoots_Olive: JungleBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\JungleBoots_olive_co.paa","\DZ\characters\shoes\data\JungleBoots_olive_co.paa","\DZ\characters\shoes\data\JungleBoots_olive_co.paa"};
	};
	class DressShoes_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_DressShoes_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_DressShoes_ColorBase1";
		model = "\DZ\characters\shoes\LeatherShoes_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,2};
		weight = 780;
		durability = 0.5;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		absorbency = 0.4;
		heatIsolation = 0.25;
		soundAttType = "Boots";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\LeatherShoes_m.p3d";
			female = "\DZ\characters\shoes\LeatherShoes_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\Data\LeatherShoes.rvmat"}},{0.7,{"DZ\characters\shoes\Data\LeatherShoes.rvmat"}},{0.5,{"DZ\characters\shoes\Data\LeatherShoes_damage.rvmat"}},{0.3,{"DZ\characters\shoes\Data\LeatherShoes_damage.rvmat"}},{0.0,{"DZ\characters\shoes\Data\LeatherShoes_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.95;
					};
					class Blood
					{
						damage = 0.9;
					};
					class Shock
					{
						damage = 1;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.95;
					};
					class Blood
					{
						damage = 0.9;
					};
					class Shock
					{
						damage = 1;
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
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class DressShoes_Beige: DressShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.95;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\LeatherShoes_beige_co.paa","\DZ\characters\shoes\data\LeatherShoes_beige_co.paa","\DZ\characters\shoes\data\LeatherShoes_beige_co.paa"};
	};
	class DressShoes_Black: DressShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\LeatherShoes_black_co.paa","\DZ\characters\shoes\data\LeatherShoes_black_co.paa","\DZ\characters\shoes\data\LeatherShoes_black_co.paa"};
	};
	class DressShoes_Brown: DressShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\LeatherShoes_brown_co.paa","\DZ\characters\shoes\data\LeatherShoes_brown_co.paa","\DZ\characters\shoes\data\LeatherShoes_brown_co.paa"};
	};
	class DressShoes_Sunburst: DressShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\LeatherShoes_sunburst_co.paa","\DZ\characters\shoes\data\LeatherShoes_sunburst_co.paa","\DZ\characters\shoes\data\LeatherShoes_sunburst_co.paa"};
	};
	class DressShoes_White: DressShoes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\LeatherShoes_white_co.paa","\DZ\characters\shoes\data\LeatherShoes_white_co.paa","\DZ\characters\shoes\data\LeatherShoes_white_co.paa"};
	};
	class MilitaryBoots_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_MilitaryBoots_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_MilitaryBoots_ColorBase1";
		model = "\DZ\characters\shoes\MilitaryBoots_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,4};
		weight = 1100;
		durability = 0.5;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		attachments[] = {"Knife"};
		absorbency = 0.1;
		heatIsolation = 0.7;
		soundAttType = "Boots";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\MilitaryBoots_m.p3d";
			female = "\DZ\characters\shoes\MilitaryBoots_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\Data\MilitaryBoots.rvmat"}},{0.7,{"DZ\characters\shoes\Data\MilitaryBoots.rvmat"}},{0.5,{"DZ\characters\shoes\Data\MilitaryBoots_damage.rvmat"}},{0.3,{"DZ\characters\shoes\Data\MilitaryBoots_damage.rvmat"}},{0.0,{"DZ\characters\shoes\Data\MilitaryBoots_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.8;
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
						damage = 0.8;
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
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class MilitaryBoots_Beige: MilitaryBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\MilitaryBoots_beige_co.paa","\DZ\characters\shoes\data\MilitaryBoots_beige_co.paa","\DZ\characters\shoes\data\MilitaryBoots_beige_co.paa"};
	};
	class MilitaryBoots_Black: MilitaryBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\MilitaryBoots_black_co.paa","\DZ\characters\shoes\data\MilitaryBoots_black_co.paa","\DZ\characters\shoes\data\MilitaryBoots_black_co.paa"};
	};
	class MilitaryBoots_Bluerock: MilitaryBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\MilitaryBoots_bluerock_co.paa","\DZ\characters\shoes\data\MilitaryBoots_bluerock_co.paa","\DZ\characters\shoes\data\MilitaryBoots_bluerock_co.paa"};
	};
	class MilitaryBoots_Brown: MilitaryBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\MilitaryBoots_brown_co.paa","\DZ\characters\shoes\data\MilitaryBoots_brown_co.paa","\DZ\characters\shoes\data\MilitaryBoots_brown_co.paa"};
	};
	class MilitaryBoots_Redpunk: MilitaryBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\MilitaryBoots_redpunk_co.paa","\DZ\characters\shoes\data\MilitaryBoots_redpunk_co.paa","\DZ\characters\shoes\data\MilitaryBoots_redpunk_co.paa"};
	};
	class CombatBoots_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_CombatBoots_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_CombatBoots_ColorBase1";
		model = "\DZ\characters\shoes\CombatBoots_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,4};
		weight = 1350;
		durability = 0.5;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		absorbency = 0.1;
		heatIsolation = 0.7;
		soundAttType = "Boots";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\CombatBoots_m.p3d";
			female = "\DZ\characters\shoes\CombatBoots_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 120;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\Data\CombatBoots.rvmat"}},{0.7,{"DZ\characters\shoes\Data\CombatBoots.rvmat"}},{0.5,{"DZ\characters\shoes\Data\CombatBoots_damage.rvmat"}},{0.3,{"DZ\characters\shoes\Data\CombatBoots_damage.rvmat"}},{0.0,{"DZ\characters\shoes\Data\CombatBoots_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.8;
					};
					class Blood
					{
						damage = 0.7;
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
						damage = 0.8;
					};
					class Blood
					{
						damage = 0.7;
					};
					class Shock
					{
						damage = 0.8;
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
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CombatBoots_Beige: CombatBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\CombatBoots_beige_co.paa","\DZ\characters\shoes\data\CombatBoots_beige_co.paa","\DZ\characters\shoes\data\CombatBoots_beige_co.paa"};
	};
	class CombatBoots_Black: CombatBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\CombatBoots_black_co.paa","\DZ\characters\shoes\data\CombatBoots_black_co.paa","\DZ\characters\shoes\data\CombatBoots_black_co.paa"};
	};
	class CombatBoots_Brown: CombatBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\CombatBoots_brown_co.paa","\DZ\characters\shoes\data\CombatBoots_brown_co.paa","\DZ\characters\shoes\data\CombatBoots_brown_co.paa"};
	};
	class CombatBoots_Green: CombatBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\CombatBoots_green_co.paa","\DZ\characters\shoes\data\CombatBoots_green_co.paa","\DZ\characters\shoes\data\CombatBoots_green_co.paa"};
	};
	class CombatBoots_Grey: CombatBoots_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\CombatBoots_grey_co.paa","\DZ\characters\shoes\data\CombatBoots_grey_co.paa","\DZ\characters\shoes\data\CombatBoots_grey_co.paa"};
	};
	class JoggingShoes_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_JoggingShoes_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_JoggingShoes_ColorBase1";
		model = "\DZ\characters\shoes\JoggingShoes_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,2};
		weight = 300;
		durability = 0.5;
		absorbency = 0.45;
		heatIsolation = 0.35;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		soundAttType = "Sneakers";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\JoggingShoes_m.p3d";
			female = "\DZ\characters\shoes\JoggingShoes_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\data\JoggingShoes.rvmat"}},{0.7,{"DZ\characters\shoes\data\JoggingShoes.rvmat"}},{0.5,{"DZ\characters\shoes\data\JoggingShoes_damage.rvmat"}},{0.3,{"DZ\characters\shoes\data\JoggingShoes_damage.rvmat"}},{0.0,{"DZ\characters\shoes\data\JoggingShoes_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class JoggingShoes_Black: JoggingShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\JoggingShoes_black_co.paa","\DZ\characters\shoes\data\JoggingShoes_black_co.paa","\DZ\characters\shoes\data\JoggingShoes_black_co.paa"};
	};
	class JoggingShoes_Blue: JoggingShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\JoggingShoes_blue_co.paa","\DZ\characters\shoes\data\JoggingShoes_blue_co.paa","\DZ\characters\shoes\data\JoggingShoes_blue_co.paa"};
	};
	class JoggingShoes_Red: JoggingShoes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\JoggingShoes_red_co.paa","\DZ\characters\shoes\data\JoggingShoes_red_co.paa","\DZ\characters\shoes\data\JoggingShoes_red_co.paa"};
	};
	class JoggingShoes_Violet: JoggingShoes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\JoggingShoes_violet_co.paa","\DZ\characters\shoes\data\JoggingShoes_violet_co.paa","\DZ\characters\shoes\data\JoggingShoes_violet_co.paa"};
	};
	class JoggingShoes_White: JoggingShoes_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\JoggingShoes_white_co.paa","\DZ\characters\shoes\data\JoggingShoes_white_co.paa","\DZ\characters\shoes\data\JoggingShoes_white_co.paa"};
	};
	class LeatherShoes_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_LeatherShoes_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_LeatherShoes_ColorBase1";
		model = "\DZ\characters\shoes\Shoes_LeatherMoccasins_g.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,2};
		weight = 380;
		durability = 0.5;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		absorbency = 0.45;
		heatIsolation = 0.6;
		soundAttType = "Boots";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\Shoes_LeatherMoccasins_CO.paa","\DZ\characters\shoes\data\Shoes_LeatherMoccasins_CO.paa","\DZ\characters\shoes\data\Shoes_LeatherMoccasins_CO.paa"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\Shoes_LeatherMoccasins_m.p3d";
			female = "\DZ\characters\shoes\Shoes_LeatherMoccasins_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class GlobalArmor
			{
				class Melee
				{
					class Health
					{
						damage = 0.8;
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
						damage = 0.8;
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
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class LeatherShoes_Black: LeatherShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsMaterials[] = {"DZ\characters\shoes\data\Shoes_LeatherMoccasins_black.rvmat","DZ\characters\shoes\data\Shoes_LeatherMoccasins_black.rvmat","DZ\characters\shoes\data\Shoes_LeatherMoccasins_black.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\shoes\Data\Shoes_LeatherMoccasins_black_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\shoes\Data\Shoes_LeatherMoccasins_black_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class LeatherShoes_Natural: LeatherShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsMaterials[] = {"DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat","DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat","DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\shoes\Data\Shoes_LeatherMoccasins_natural_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\shoes\Data\Shoes_LeatherMoccasins_natural_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class LeatherShoes_Brown: LeatherShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsMaterials[] = {"DZ\characters\shoes\data\Shoes_LeatherMoccasins_brown.rvmat","DZ\characters\shoes\data\Shoes_LeatherMoccasins_brown.rvmat","DZ\characters\shoes\data\Shoes_LeatherMoccasins_brown.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\shoes\Data\Shoes_LeatherMoccasins_brown_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\shoes\Data\Shoes_LeatherMoccasins_brown_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class LeatherShoes_Beige: LeatherShoes_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsMaterials[] = {"DZ\characters\shoes\data\Shoes_LeatherMoccasins_beige.rvmat","DZ\characters\shoes\data\Shoes_LeatherMoccasins_beige.rvmat","DZ\characters\shoes\data\Shoes_LeatherMoccasins_beige.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\data\Shoes_LeatherMoccasins_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\shoes\Data\Shoes_LeatherMoccasins_beige_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\shoes\Data\Shoes_LeatherMoccasins_beige_destruct.rvmat"}}};
				};
			};
			class GlobalArmor: GlobalArmor{};
		};
	};
	class Sneakers_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_Sneakers_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_Sneakers_ColorBase1";
		model = "\DZ\characters\shoes\Sneakers_g.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,2};
		weight = 780;
		durability = 0.35;
		absorbency = 0.5;
		heatIsolation = 0.25;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		soundAttType = "Sneakers";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\Sneakers_m.p3d";
			female = "\DZ\characters\shoes\Sneakers_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 30;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\data\Sneakers.rvmat"}},{0.7,{"DZ\characters\shoes\data\Sneakers.rvmat"}},{0.5,{"DZ\characters\shoes\data\Sneakers_damage.rvmat"}},{0.3,{"DZ\characters\shoes\data\Sneakers_damage.rvmat"}},{0.0,{"DZ\characters\shoes\data\Sneakers_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Sneakers_Black: Sneakers_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\Sneakers_Black_co.paa","\dz\characters\shoes\data\Sneakers_Black_co.paa","\dz\characters\shoes\data\Sneakers_Black_co.paa"};
	};
	class Sneakers_Gray: Sneakers_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\Sneakers_Gray_co.paa","\dz\characters\shoes\data\Sneakers_Gray_co.paa","\dz\characters\shoes\data\Sneakers_Gray_co.paa"};
	};
	class Sneakers_Green: Sneakers_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\Sneakers_Green_co.paa","\dz\characters\shoes\data\Sneakers_Green_co.paa","\dz\characters\shoes\data\Sneakers_Green_co.paa"};
	};
	class Sneakers_Red: Sneakers_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\Sneakers_Red_co.paa","\dz\characters\shoes\data\Sneakers_Red_co.paa","\dz\characters\shoes\data\Sneakers_Red_co.paa"};
	};
	class Sneakers_White: Sneakers_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\Sneakers_White_co.paa","\dz\characters\shoes\data\Sneakers_White_co.paa","\dz\characters\shoes\data\Sneakers_White_co.paa"};
	};
	class NBCBootsBase: Clothing
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_NBCBootsBase0";
		descriptionShort = "$STR_CfgVehicles_NBCBootsBase1";
		model = "\DZ\characters\shoes\NBC_Boots_g.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {3,2};
		weight = 300;
		durability = 0.5;
		repairableWithKits[] = {5};
		repairCosts[] = {30.0};
		absorbency = 0.0;
		heatIsolation = 0.7;
		soundAttType = "Boots";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\NBC_Boots_m.p3d";
			female = "\DZ\characters\shoes\NBC_Boots_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\Data\NBC_Boots.rvmat"}},{0.7,{"DZ\characters\shoes\Data\NBC_Boots.rvmat"}},{0.5,{"DZ\characters\shoes\Data\NBC_Boots_damage.rvmat"}},{0.3,{"DZ\characters\shoes\Data\NBC_Boots_damage.rvmat"}},{0.0,{"DZ\characters\shoes\Data\NBC_Boots_destruct.rvmat"}}};
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
	};
	class NBCBootsGray: NBCBootsBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"\dz\characters\shoes\data\NBC_Boots_grey_co.paa","\dz\characters\shoes\data\NBC_Boots_grey_co.paa","\dz\characters\shoes\data\NBC_Boots_grey_co.paa"};
	};
	class Ballerinas_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_Ballerinas_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_Ballerinas_ColorBase1";
		model = "\DZ\characters\shoes\Ballerinas_ground.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,2};
		weight = 520;
		durability = 0.5;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		absorbency = 0.4;
		heatIsolation = 0.1;
		soundAttType = "Sneakers";
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","personality"};
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\Ballerinas_m.p3d";
			female = "\DZ\characters\shoes\Ballerinas_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\data\Ballerinas.rvmat"}},{0.7,{"DZ\characters\shoes\data\Ballerinas.rvmat"}},{0.5,{"DZ\characters\shoes\data\Ballerinas_damage.rvmat"}},{0.3,{"DZ\characters\shoes\data\Ballerinas_damage.rvmat"}},{0.0,{"DZ\characters\shoes\data\Ballerinas_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "AthleticShoes_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "AthleticShoes_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Ballerinas_Blue: Ballerinas_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\Ballerinas_blue_co.paa","\DZ\characters\shoes\data\Ballerinas_blue_co.paa","\DZ\characters\shoes\data\Ballerinas_blue_co.paa"};
	};
	class Ballerinas_Red: Ballerinas_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\Ballerinas_red_co.paa","\DZ\characters\shoes\data\Ballerinas_red_co.paa","\DZ\characters\shoes\data\Ballerinas_red_co.paa"};
	};
	class Ballerinas_White: Ballerinas_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\Ballerinas_white_co.paa","\DZ\characters\shoes\data\Ballerinas_white_co.paa","\DZ\characters\shoes\data\Ballerinas_white_co.paa"};
	};
	class Ballerinas_Yellow: Ballerinas_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\DZ\characters\shoes\data\Ballerinas_yellow_co.paa","\DZ\characters\shoes\data\Ballerinas_yellow_co.paa","\DZ\characters\shoes\data\Ballerinas_yellow_co.paa"};
	};
	class TTSKOBoots: Clothing
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TTSKOBoots0";
		descriptionShort = "$STR_CfgVehicles_TTSKOBoots1";
		model = "\DZ\characters\shoes\TTsKO_Boots_g.p3d";
		inventorySlot[] = {"Feet"};
		itemInfo[] = {"Clothing","Feet"};
		itemSize[] = {4,4};
		weight = 1200;
		absorbency = 0.25;
		heatIsolation = 0.7;
		repairableWithKits[] = {5,3};
		repairCosts[] = {30.0,25.0};
		soundAttType = "Boots";
		class ClothingTypes
		{
			male = "\DZ\characters\shoes\TTsKO_Boots_m.p3d";
			female = "\DZ\characters\shoes\TTsKO_Boots_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 110;
					healthLevels[] = {{1.0,{"DZ\characters\shoes\data\TTsKO_boots.rvmat"}},{0.7,{"DZ\characters\shoes\data\TTsKO_boots.rvmat"}},{0.5,{"DZ\characters\shoes\data\TTsKO_boots_damage.rvmat"}},{0.3,{"DZ\characters\shoes\data\TTsKO_boots_damage.rvmat"}},{0.0,{"DZ\characters\shoes\data\TTsKO_boots_destruct.rvmat"}}};
				};
			};
		};
	};
};
