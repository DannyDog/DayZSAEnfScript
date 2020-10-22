class WoodBase extends Plant
{
	bool 	m_IsCuttable;
	int 	m_PrimaryDropsAmount = -1;
	int 	m_SecondaryDropsAmount = -1;
	float 	m_ToolDamage = -1.0;
	float 	m_CycleTimeOverride = -1.0;
	string 	m_PrimaryOutput = ""; //some nonsensical item for debugging purposes
	string 	m_SecondaryOutput = ""; //some nonsensical item for debugging purposes
	string 	m_BarkType = "";
	
	void WoodBase()
	{
		InitMiningValues();
	}
	
	void InitMiningValues()
	{
		m_IsCuttable = false;
	/*
		m_PrimaryDropsAmount = 3;
		m_SecondaryDropsAmount = 2;
		m_ToolDamage = 3.0;
		m_CycleTimeOverride = 1.0;
		m_PrimaryOutput = "FireWood";
		m_SecondaryOutput = "WoodenStick";
		m_BarkType = "Bark_Birch";
	*/
	};
	
	override bool IsWoodBase()
	{
		return true;
	}

	int GetAmountOfDrops(ItemBase item)
	{
		if ( m_PrimaryDropsAmount > 0 )
		{
			if ( IsTree() && item && item.KindOf("Knife") )
			{
				return -1;
			}
			else
			{
				return m_PrimaryDropsAmount; 
			}
		}
		else
		{
			if ( item && item.KindOf("Knife") )
			{
				return -1;
			}
			else if ( item && item.KindOf("Axe") )
			{
				return 3;
			}
			else
			{
				return 100;
			}
		}
	}
	
	void GetMaterialAndQuantityMap(ItemBase item, out map<string,int> output_map)
	{
		if ( IsTree() && item && item.KindOf("Knife") && m_BarkType != "" )
		{
			output_map.Insert(m_BarkType,1);
		}
		else
		{
			output_map.Insert(m_PrimaryOutput,1);
		}
	}
	
	float GetDamageToMiningItemEachDrop(ItemBase item)
	{
		if (m_ToolDamage > -1)
			return m_ToolDamage;
		
		if ( IsTree() )
		{
			if ( item && item.KindOf("Knife") )
			{
				return 20;
			}
			else if ( item && item.KindOf("Axe") )
			{
				return 20;
			}
			else
			{
				return 0; 
			}
		}
		else
		{
			if ( item && item.KindOf("Knife") )
			{
				return 30;
			}
			else if ( item && item.KindOf("Axe") )
			{
				return 30;
			}
			else
			{
				return 0;
			}
		}
	}
	
	override bool IsCuttable()
	{
		return m_IsCuttable;
	}
};