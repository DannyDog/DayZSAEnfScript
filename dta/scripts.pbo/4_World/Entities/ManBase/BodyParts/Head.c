class Head_Default extends Head
{
	int beard_idx;
	ref map<int,bool> m_HeadHairHidingStateMap;
	//ref array<string> m_CurrentlyHiddenSelections;
	ref array<string> m_HeadHairSelectionArray;
	
	void Head_Default()
	{
		Init();
	}
	
	void Init()
	{
		m_HeadHairSelectionArray = new array<string>;
		//m_CurrentlyHiddenSelections = new array<string>;
		m_HeadHairHidingStateMap = new map<int,bool>;
		
		ConfigGetTextArray("simpleHiddenSelections",m_HeadHairSelectionArray);
		
		for (int i = 0; i < m_HeadHairSelectionArray.Count(); i++)
		{
			m_HeadHairHidingStateMap.Insert(i,1); //all considered "shown" on init
		}
		beard_idx = m_HeadHairSelectionArray.Find("beard");
	}
	
	bool GetHeadHideableSelections(out array<string> selections)
	{
		selections = m_HeadHairSelectionArray;
		return true;
	}
	
	/*void HandleCurrentlyHiddenSelections(int level)
	{
		string name = m_HeadHairSelectionArray.Get(level);
		int idx = m_CurrentlyHiddenSelections.Find(name);
		if ( idx > -1)
		{
			m_CurrentlyHiddenSelections.Remove(idx);
		}
		else
		{
			m_CurrentlyHiddenSelections.Insert(name);
		}
	}
	
	array<string> GetCurrentlyHiddenSelections()
	{
		return m_CurrentlyHiddenSelections;
	}*/
	
	int GetBeardIndex()
	{
		return beard_idx;
	}
};