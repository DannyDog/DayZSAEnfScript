//-------------------------------------
//Birch tree baseclasses (white bark)
class TreeHard_BetulaPendula: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		//m_CycleTimeOverride = 1.0;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "WoodenStick";
		m_BarkType = "Bark_Birch";
	}
};

class TreeSoft_BetulaPendula_Base: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		//m_CycleTimeOverride = 1.0;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "WoodenStick";
		m_BarkType = "Bark_Birch";
	}
};

//-----------------------------------------------
//TreeSoft
class TreeSoft_t_BetulaPendula_1f: TreeSoft_BetulaPendula_Base
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 6;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_BetulaPendula_1fb: TreeSoft_BetulaPendula_Base
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_BetulaPendula_1s: TreeSoft_BetulaPendula_Base
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_BetulaPendula_2f: TreeSoft_BetulaPendula_Base
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 6;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_BetulaPendula_2fb: TreeSoft_BetulaPendula_Base
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 6;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_BetulaPendula_2fc: TreeSoft_BetulaPendula_Base
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeSoft_t_BetulaPendula_2w: TreeSoft_BetulaPendula_Base
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_FagusSylvatica_1f: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "LongWoodenStick";
		m_SecondaryOutput = "WoodenStick";
	}
};
class TreeSoft_t_FagusSylvatica_1fc: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_FagusSylvatica_1fd: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_FagusSylvatica_1s: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_FagusSylvatica_2sb: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_FagusSylvatica_2sb_Trail_B: TreeSoft_t_FagusSylvatica_2sb{};
class TreeSoft_t_FagusSylvatica_2sb_Trail_G: TreeSoft_t_FagusSylvatica_2sb{};
class TreeSoft_t_FagusSylvatica_2sb_Trail_R: TreeSoft_t_FagusSylvatica_2sb{};
class TreeSoft_t_FagusSylvatica_2sb_Trail_Y: TreeSoft_t_FagusSylvatica_2sb{};

class TreeSoft_t_FraxinusExcelsior_2w: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_malusDomestica_1s: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_malusDomestica_2s: TreeSoft_t_malusDomestica_1s{};
class TreeSoft_t_malusDomestica_3s: TreeSoft_t_malusDomestica_1s{};
class TreeSoft_t_PiceaAbies_1f: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 4;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_PiceaAbies_2sb: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 4;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_populusAlba_1f: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
	}
};
class TreeSoft_t_pyrusCommunis_2s: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 4;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "WoodenStick";
	}
};
class TreeSoft_t_quercusRobur_1f: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_quercusRobur_1fc: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_quercusRobur_1fd: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_quercusRobur_1s: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_quercusRobur_2fb: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 4;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_quercusRobur_2fc: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 4;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_robiniaPseudoacacia_1f: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "WoodenStick";
	}
};
class TreeSoft_t_town_1s: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "WoodenStick";
	}
};
class TreeSoft_t_town_1sb: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "WoodenStick";
	}
};
class TreeSoft_t_LarixDecidua_1f: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeSoft_t_LarixDecidua_1s: TreeSoft
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
//-----------------------------------------------
//TreeHard
class TreeHard_t_BetulaPendula_2s: TreeHard_BetulaPendula
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 6;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeHard_t_BetulaPendula_3f: TreeHard_BetulaPendula
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_BetulaPendula_3fb: TreeHard_BetulaPendula
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_BetulaPendula_3fc: TreeHard_BetulaPendula
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_BetulaPendula_3s: TreeHard_BetulaPendula
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_carpinus_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 4;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
}
class TreeHard_t_FagusSylvatica_1fe: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_FagusSylvatica_2d: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_FagusSylvatica_2f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeHard_t_FagusSylvatica_2fb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeHard_t_FagusSylvatica_2fc: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_MEDIUM;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeHard_t_FagusSylvatica_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_FagusSylvatica_3d: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 4;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_FagusSylvatica_3f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_FagusSylvatica_3fb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_FagusSylvatica_3s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_FraxinusExcelsior_2f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_FraxinusExcelsior_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_FraxinusExcelsior_3s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_juglansRegia_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_juglansRegia_3s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_LarixDecidua_2f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 4;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_LarixDecidua_2fb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 4;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_LarixDecidua_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_LarixDecidua_3f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 4;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_LarixDecidua_3fb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_naked_1s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_naked_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 4;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_piceaabies_2d: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 6;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PiceaAbies_2f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PiceaAbies_2fb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PiceaAbies_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 4;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
//class TreeHard_t_PiceaAbies_2s_xmas: TreeHard{};
class TreeHard_t_piceaabies_3d: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 6;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PiceaAbies_3f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
	}
};
class TreeHard_t_PiceaAbies_3f_Trail_B: TreeHard_t_PiceaAbies_3f{};
class TreeHard_t_PiceaAbies_3f_Trail_G: TreeHard_t_PiceaAbies_3f{};
class TreeHard_t_PiceaAbies_3f_Trail_R: TreeHard_t_PiceaAbies_3f{};
class TreeHard_t_PiceaAbies_3f_Trail_Y: TreeHard_t_PiceaAbies_3f{};
class TreeHard_t_PiceaAbies_3s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 4;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeHard_t_PinusSylvestris_2f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PinusSylvestris_2fb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PinusSylvestris_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PinusSylvestris_2sb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PinusSylvestris_3d: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 6;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PinusSylvestris_3f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PinusSylvestris_3fb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PinusSylvestris_3fc: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_PinusSylvestris_3s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_populusAlba_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_populusAlba_3s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 5;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_populusNigra_3s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 4;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_prunusDomestica_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeHard_t_pyrusCommunis_3s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeHard_t_pyrusCommunis_3sb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 1;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeHard_t_quercusRobur_2d: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 6;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_quercusRobur_2f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_quercusRobur_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_quercusRobur_2sb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_quercusRobur_2sc: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_quercusRobur_3d: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 8;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_quercusRobur_3f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_quercusRobur_3fb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 4;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_quercusRobur_3s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 4;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_quercusRobur_3sb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 4;
		m_SecondaryDropsAmount = 6;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_robiniaPseudoacacia_2f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 4;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_robiniaPseudoacacia_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_robiniaPseudoacacia_3f: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_salixAlba_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 2;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};
class TreeHard_t_salixAlba_2sb: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 6;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeHard_t_salixAlba_2sb_swamp: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 6;
		m_SecondaryDropsAmount = 3;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "LongWoodenStick";
	}
};
class TreeHard_t_sorbus_2s: TreeHard
{
	override void InitMiningValues()
	{
		super.InitMiningValues();
		m_IsCuttable = true;
		
		m_PrimaryDropsAmount = 1;
		m_SecondaryDropsAmount = 4;
		m_ToolDamage = 4.0;
		m_CycleTimeOverride = GameConstants.MINING_WOOD_SLOW;
		m_PrimaryOutput = "WoodenLog";
		m_SecondaryOutput = "FireWood";
	}
};