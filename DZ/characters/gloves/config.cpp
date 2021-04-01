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
	class DZ_Characters_Gloves
	{
		units[] = {"MaleHands","FemaleHands"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class MaleHands_Base: Inventory_Base
	{
		scope = 1;
		displayName = "Bare hands";
		model = "\DZ\characters\gloves\hands3_m.p3d";
		inventorySlot[] = {"Gloves"};
		hiddenSelections[] = {"personality"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.843137,0.768627,0.658824,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\hhl_dummy_skin_material.rvmat"};
	};
	class MaleAdamHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat"};
	};
	class MaleBorisHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved.rvmat"};
	};
	class MaleCyrilHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved.rvmat"};
	};
	class MaleDenisHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved.rvmat"};
	};
	class MaleEliasHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved.rvmat"};
	};
	class MaleFrancisHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved.rvmat"};
	};
	class MaleGuoHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved.rvmat"};
	};
	class MaleHassanHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved.rvmat"};
	};
	class MaleIndarHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved.rvmat"};
	};
	class MaleJoseHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved.rvmat"};
	};
	class MaleKaitoHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved.rvmat"};
	};
	class MaleLewisHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved.rvmat"};
	};
	class MaleManuaHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved.rvmat"};
	};
	class MaleNikiHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved.rvmat"};
	};
	class MaleOliverHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved.rvmat"};
	};
	class MalePeterHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved.rvmat"};
	};
	class MaleQuinnHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved.rvmat"};
	};
	class MaleRolfHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved.rvmat"};
	};
	class MaleSethHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved.rvmat"};
	};
	class MaleTaikiHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved.rvmat"};
	};
	class FemaleHands_Base: Inventory_Base
	{
		scope = 1;
		displayName = "Bare hands";
		model = "\DZ\characters\gloves\hands3_f.p3d";
		inventorySlot[] = {"Gloves"};
		hiddenSelections[] = {"personality"};
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.843137,0.768627,0.658824,1.0,CO)"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\hhl_dummy_skin_material.rvmat"};
	};
	class FemaleEvaHands: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Eva_2\hhl_f_Eva_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body.rvmat"};
	};
	class FemaleFridaHands: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Frida_2\hhl_f_frida_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Frida_2\hhl_f_frida_body.rvmat"};
	};
	class FemaleGabiHands: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body.rvmat"};
	};
	class FemaleHelgaHands: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Helga\hhl_f_Helga_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Helga\hhl_f_Helga_body.rvmat"};
	};
	class FemaleIrenaHands: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body.rvmat"};
	};
	class FemaleJudyHands: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Judy\hhl_f_Judy_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Judy\hhl_f_Judy_body.rvmat"};
	};
	class FemaleKeikoHands: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body.rvmat"};
	};
	class FemaleLindaHands: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body.rvmat"};
	};
	class FemaleMariaHands: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body.rvmat"};
	};
	class FemaleNaomiHands: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body.rvmat"};
	};
	class MaleAdamDecayedHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\m_Adam\Adam_body_shaved_decayed.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat"};
	};
	class MaleAdamDecayedDarkHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\m_Adam\Adam_body_shaved_decayed_dark.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat"};
	};
	class MaleAdamDecayedLighterDarkHands: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\m_Adam\Adam_body_shaved_decayed_lighter_dark.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Adam\hhl_m_Adam_body_shaved.rvmat"};
	};
	class MaleBorisHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Boris\hhl_m_Boris_body_shaved.rvmat"};
	};
	class MaleCyrilHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Cyril\hhl_m_Cyril_body_shaved.rvmat"};
	};
	class MaleDenisHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Denis_2\hhl_m_Denis_body_shaved.rvmat"};
	};
	class MaleEliasHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Elias\hhl_m_Elias_body_shaved.rvmat"};
	};
	class MaleFrancisHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Francis\hhl_m_Francis_body_shaved.rvmat"};
	};
	class MaleGuoHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Guo\hhl_m_Guo_body_shaved.rvmat"};
	};
	class MaleHassanHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_shaved.rvmat"};
	};
	class MaleIndarHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Indar\hhl_m_Indar_body_shaved.rvmat"};
	};
	class MaleJoseHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Jose\hhl_m_Jose_body_shaved.rvmat"};
	};
	class MaleKaitoHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_shaved.rvmat"};
	};
	class MaleLewisHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_shaved.rvmat"};
	};
	class MaleManuaHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Manua\hhl_m_Manua_body_shaved.rvmat"};
	};
	class MaleNikiHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_shaved.rvmat"};
	};
	class MaleOliverHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_shaved.rvmat"};
	};
	class MalePeterHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Peter\hhl_m_Peter_body_shaved.rvmat"};
	};
	class MaleQuinnHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_shaved.rvmat"};
	};
	class MaleRolfHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_shaved.rvmat"};
	};
	class MaleSethHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Seth\hhl_m_Seth_body_shaved.rvmat"};
	};
	class MaleTaikiHandsDecayed: MaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_shaved.rvmat"};
	};
	class FemaleEvaHandsDecayed: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Eva_2\hhl_f_Eva_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body.rvmat"};
	};
	class FemaleFridaHandsDecayed: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Frida_2\hhl_f_frida_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Frida_2\hhl_f_frida_body.rvmat"};
	};
	class FemaleGabiHandsDecayed: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"\DZ\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body.rvmat"};
	};
	class FemaleHelgaHandsDecayed: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Helga\hhl_f_Helga_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Helga\hhl_f_Helga_body.rvmat"};
	};
	class FemaleIrenaHandsDecayed: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body.rvmat"};
	};
	class FemaleJudyHandsDecayed: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Judy\hhl_f_Judy_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Judy\hhl_f_Judy_body.rvmat"};
	};
	class FemaleKeikoHandsDecayed: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body.rvmat"};
	};
	class FemaleLindaHandsDecayed: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body.rvmat"};
	};
	class FemaleMariaHandsDecayed: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body.rvmat"};
	};
	class FemaleNaomiHandsDecayed: FemaleHands_Base
	{
		hiddenSelectionsTextures[] = {"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body_decayed_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body.rvmat"};
	};
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class WorkingGloves_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_WorkingGloves_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_WorkingGloves_ColorBase1";
		model = "\DZ\characters\gloves\working_gloves_g.p3d";
		inventorySlot[] = {"Gloves"};
		simulation = "clothing";
		itemInfo[] = {"Clothing","Gloves"};
		rotationFlags = 34;
		weight = 130;
		itemSize[] = {2,2};
		varWetMax = 0.49;
		heatIsolation = 0.5;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","personality"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\Characters\gloves\data\WorkingGloves.rvmat"}},{0.7,{"DZ\Characters\gloves\data\WorkingGloves.rvmat"}},{0.5,{"DZ\Characters\gloves\data\WorkingGloves_damage.rvmat"}},{0.3,{"DZ\Characters\gloves\data\WorkingGloves_damage.rvmat"}},{0.0,{"DZ\Characters\gloves\data\WorkingGloves_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\gloves\working_gloves_m.p3d";
			female = "\DZ\characters\gloves\working_gloves_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class WorkingGloves_Black: WorkingGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"DZ\characters\gloves\data\WorkingGloves_black_co.paa","DZ\characters\gloves\data\WorkingGloves_black_co.paa","DZ\characters\gloves\data\WorkingGloves_black_co.paa"};
	};
	class WorkingGloves_Beige: WorkingGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsTextures[] = {"DZ\characters\gloves\data\WorkingGloves_beige_co.paa","DZ\characters\gloves\data\WorkingGloves_beige_co.paa","DZ\characters\gloves\data\WorkingGloves_beige_co.paa"};
	};
	class WorkingGloves_Brown: WorkingGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"DZ\characters\gloves\data\WorkingGloves_brown_co.paa","DZ\characters\gloves\data\WorkingGloves_brown_co.paa","DZ\characters\gloves\data\WorkingGloves_brown_co.paa"};
	};
	class WorkingGloves_Yellow: WorkingGloves_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"DZ\characters\gloves\data\WorkingGloves_yellow_co.paa","DZ\characters\gloves\data\WorkingGloves_yellow_co.paa","DZ\characters\gloves\data\WorkingGloves_yellow_co.paa"};
	};
	class TacticalGloves_ColorBase: Clothing
	{
		displayName = "$STR_CfgVehicles_TacticalGloves_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_TacticalGloves_ColorBase1";
		model = "\DZ\characters\gloves\tactical_gloves_g.p3d";
		inventorySlot[] = {"Gloves"};
		simulation = "clothing";
		itemInfo[] = {"Clothing","Gloves"};
		rotationFlags = 34;
		weight = 454;
		itemSize[] = {2,2};
		varWetMax = 0.79;
		heatIsolation = 0.6;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","personality"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 165;
					healthLevels[] = {{1.0,{"DZ\Characters\gloves\data\TacticalGloves.rvmat"}},{0.7,{"DZ\Characters\gloves\data\TacticalGloves.rvmat"}},{0.5,{"DZ\Characters\gloves\data\TacticalGloves_damage.rvmat"}},{0.3,{"DZ\Characters\gloves\data\TacticalGloves_damage.rvmat"}},{0.0,{"DZ\Characters\gloves\data\TacticalGloves_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\gloves\tactical_gloves_m.p3d";
			female = "\DZ\characters\gloves\tactical_gloves_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class TacticalGloves_Black: TacticalGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"DZ\characters\gloves\data\TacticalGloves_black_co.paa","DZ\characters\gloves\data\TacticalGloves_black_co.paa","DZ\characters\gloves\data\TacticalGloves_black_co.paa"};
	};
	class TacticalGloves_Beige: TacticalGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"DZ\characters\gloves\data\TacticalGloves_beige_co.paa","DZ\characters\gloves\data\TacticalGloves_beige_co.paa","DZ\characters\gloves\data\TacticalGloves_beige_co.paa"};
	};
	class TacticalGloves_Green: TacticalGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"DZ\characters\gloves\data\TacticalGloves_green_co.paa","DZ\characters\gloves\data\TacticalGloves_green_co.paa","DZ\characters\gloves\data\TacticalGloves_green_co.paa"};
	};
	class NBCGloves_ColorBase: Clothing
	{
		scope = 0;
		displayName = "$STR_cfgvehicles_nbcglovesbase0";
		descriptionShort = "$STR_cfgvehicles_nbcglovesbase1";
		model = "\DZ\characters\gloves\NBC_Gloves_g.p3d";
		inventorySlot[] = {"Gloves"};
		simulation = "clothing";
		itemInfo[] = {"Clothing","Gloves"};
		rotationFlags = 34;
		weight = 454;
		itemSize[] = {2,3};
		varWetMax = 0.249;
		heatIsolation = 0.35;
		repairableWithKits[] = {5};
		repairCosts[] = {30.0};
		class ClothingTypes
		{
			male = "\DZ\characters\gloves\NBC_Gloves_m.p3d";
			female = "\DZ\characters\gloves\NBC_Gloves_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80;
					healthLevels[] = {{1.0,{"DZ\Characters\gloves\data\NBC_Gloves.rvmat"}},{0.7,{"DZ\Characters\gloves\data\NBC_Gloves.rvmat"}},{0.5,{"DZ\Characters\gloves\data\NBC_Gloves_damage.rvmat"}},{0.3,{"DZ\Characters\gloves\data\NBC_Gloves_damage.rvmat"}},{0.0,{"DZ\Characters\gloves\data\NBC_Gloves_destruct.rvmat"}}};
				};
			};
		};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","personality"};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class NBCGlovesGray: NBCGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\dz\characters\gloves\Data\NBC_Gloves_grey_co.paa","\dz\characters\gloves\Data\NBC_Gloves_grey_co.paa","\dz\characters\gloves\Data\NBC_Gloves_grey_co.paa"};
	};
	class SurgicalGloves_ColorBase: Clothing
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_SurgicalGloves_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_SurgicalGloves_ColorBase1";
		model = "\DZ\characters\gloves\Surgical_gloves_g.p3d";
		inventorySlot[] = {"Gloves"};
		simulation = "clothing";
		itemInfo[] = {"Clothing","Gloves"};
		rotationFlags = 34;
		weight = 100;
		itemSize[] = {1,1};
		varWetMax = 0.249;
		heatIsolation = 0.05;
		repairableWithKits[] = {5};
		repairCosts[] = {30.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","personality"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\Characters\gloves\data\Surgical_Gloves.rvmat","DZ\Characters\gloves\data\Surgical_Gloves_g.rvmat"}},{0.7,{"DZ\Characters\gloves\data\Surgical_Gloves.rvmat","DZ\Characters\gloves\data\Surgical_Gloves_g.rvmat"}},{0.5,{"DZ\Characters\gloves\data\Surgical_Gloves_damage.rvmat","DZ\Characters\gloves\data\Surgical_Gloves_g_damage.rvmat"}},{0.3,{"DZ\Characters\gloves\data\Surgical_Gloves_damage.rvmat","DZ\Characters\gloves\data\Surgical_Gloves_g_damage.rvmat"}},{0.0,{"DZ\Characters\gloves\data\Surgical_Gloves_destruct.rvmat","DZ\Characters\gloves\data\Surgical_Gloves_g_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\gloves\Surgical_gloves_m.p3d";
			female = "\DZ\characters\gloves\Surgical_gloves_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class SurgicalGloves_Blue: SurgicalGloves_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\gloves\Data\Surgical_Gloves_blue_co.paa","\dz\characters\gloves\Data\Surgical_Gloves_blue_co.paa","\dz\characters\gloves\Data\Surgical_Gloves_blue_co.paa"};
	};
	class SurgicalGloves_LightBlue: SurgicalGloves_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\gloves\Data\Surgical_Gloves_light_blue_co.paa","\dz\characters\gloves\Data\Surgical_Gloves_light_blue_co.paa","\dz\characters\gloves\Data\Surgical_Gloves_light_blue_co.paa"};
	};
	class SurgicalGloves_Green: SurgicalGloves_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\gloves\Data\Surgical_Gloves_green_co.paa","\dz\characters\gloves\Data\Surgical_Gloves_green_co.paa","\dz\characters\gloves\Data\Surgical_Gloves_green_co.paa"};
	};
	class SurgicalGloves_White: SurgicalGloves_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] = {"\dz\characters\gloves\Data\Surgical_Gloves_white_co.paa","\dz\characters\gloves\Data\Surgical_Gloves_white_co.paa","\dz\characters\gloves\Data\Surgical_Gloves_white_co.paa"};
	};
	class LeatherGloves_ColorBase: Clothing
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_LeatherGloves_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_LeatherGloves_ColorBase1";
		model = "\DZ\characters\gloves\leather_gloves_g.p3d";
		inventorySlot[] = {"Gloves"};
		simulation = "clothing";
		itemInfo[] = {"Clothing","Gloves"};
		rotationFlags = 34;
		weight = 200;
		itemSize[] = {2,2};
		varWetMax = 0.249;
		heatIsolation = 1;
		repairableWithKits[] = {3};
		repairCosts[] = {25.0};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","personality"};
		class ClothingTypes
		{
			male = "\DZ\characters\gloves\leather_gloves_m.p3d";
			female = "\DZ\characters\gloves\leather_gloves_f.p3d";
		};
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
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class LeatherGloves_Natural: LeatherGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsMaterials[] = {"DZ\Characters\gloves\data\leather_gloves_Natural.rvmat","DZ\Characters\gloves\data\leather_gloves_Natural.rvmat","DZ\Characters\gloves\data\leather_gloves_Natural.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\characters\gloves\data\leather_gloves_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\gloves\Data\leather_gloves_Natural_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\gloves\Data\leather_gloves_Natural_destruct.rvmat"}}};
				};
			};
		};
	};
	class LeatherGloves_Beige: LeatherGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.9;
		hiddenSelectionsMaterials[] = {"DZ\Characters\gloves\data\leather_gloves_Beige.rvmat","DZ\Characters\gloves\data\leather_gloves_Beige.rvmat","DZ\Characters\gloves\data\leather_gloves_Beige.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\characters\gloves\data\leather_gloves_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\gloves\Data\leather_gloves_Beige_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\gloves\Data\leather_gloves_Beige_destruct.rvmat"}}};
				};
			};
		};
	};
	class LeatherGloves_Black: LeatherGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsMaterials[] = {"DZ\Characters\gloves\data\leather_gloves_Black.rvmat","DZ\Characters\gloves\data\leather_gloves_Black.rvmat","DZ\Characters\gloves\data\leather_gloves_Black.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\characters\gloves\data\leather_gloves_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\gloves\Data\leather_gloves_Black_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\gloves\Data\leather_gloves_Black_destruct.rvmat"}}};
				};
			};
		};
	};
	class LeatherGloves_Brown: LeatherGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.85;
		hiddenSelectionsMaterials[] = {"DZ\Characters\gloves\data\leather_gloves_brown.rvmat","DZ\Characters\gloves\data\leather_gloves_brown.rvmat","DZ\Characters\gloves\data\leather_gloves_brown.rvmat"};
		class DamageSystem: DamageSystem
		{
			class GlobalHealth: GlobalHealth
			{
				class Health
				{
					hitpoints = 40;
					healthLevels[] = {{1.0,{"DZ\characters\gloves\data\leather_gloves_natural.rvmat"}},{0.7,{}},{0.5,{"DZ\characters\gloves\Data\leather_gloves_brown_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\characters\gloves\Data\leather_gloves_brown_destruct.rvmat"}}};
				};
			};
		};
	};
	class OMNOGloves_ColorBase: Clothing
	{
		scope = 0;
		displayName = "$STR_CfgVehicles_OMNOGloves_ColorBase0";
		descriptionShort = "$STR_CfgVehicles_OMNOGloves_ColorBase1";
		model = "\DZ\characters\gloves\OMNO_gloves_g.p3d";
		inventorySlot[] = {"Gloves"};
		simulation = "clothing";
		itemInfo[] = {"Clothing","Gloves"};
		rotationFlags = 34;
		weight = 450;
		itemSize[] = {2,2};
		varWetMax = 0.79;
		heatIsolation = 0.8;
		repairableWithKits[] = {5,2};
		repairCosts[] = {30.0,25.0};
		class ClothingTypes
		{
			male = "\DZ\characters\gloves\OMNO_gloves_m.p3d";
			female = "\DZ\characters\gloves\OMNO_gloves_f.p3d";
		};
		hiddenSelections[] = {"camoGround","camoMale","camoFemale","personality"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 180;
					healthLevels[] = {{1.0,{"DZ\Characters\gloves\data\OMNOGloves.rvmat"}},{0.7,{"DZ\Characters\gloves\data\OMNOGloves.rvmat"}},{0.5,{"DZ\Characters\gloves\data\OMNOGloves_damage.rvmat"}},{0.3,{"DZ\Characters\gloves\data\OMNOGloves_damage.rvmat"}},{0.0,{"DZ\Characters\gloves\data\OMNOGloves_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "WorkingGloves_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "WorkingGloves_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class OMNOGloves_Gray: OMNOGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\dz\characters\gloves\Data\OMNO_co.paa","\dz\characters\gloves\Data\OMNO_co.paa","\dz\characters\gloves\Data\OMNO_co.paa"};
	};
	class OMNOGloves_Brown: OMNOGloves_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.8;
		hiddenSelectionsTextures[] = {"\dz\characters\gloves\Data\OMNO_brown_co.paa","\dz\characters\gloves\Data\OMNO_brown_co.paa","\dz\characters\gloves\Data\OMNO_brown_co.paa"};
	};
};
