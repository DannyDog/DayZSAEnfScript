class BleedingSourcesManagerBase
{
	ref map<int, ref BleedingSource> m_BleedingSources = new map<int, ref BleedingSource>;
	ref map<string, ref BleedingSourceZone> m_BleedingSourceZone = new map<string, ref BleedingSourceZone>;
	
	PlayerBase m_Player;
	//ref map<string, int> m_FireGeomToBit = new map<string, int>;
	ref map<int, string> m_BitToFireGeom = new map<int, string>;
	int m_BitOffset = 0;
	
	void BleedingSourcesManagerBase( PlayerBase player )
	{
		m_Player = player;
		Init();
	}
	
	protected void Init()
	{
		//dmgZone_head
		RegisterBleedingZone("Head",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "0 0 0");
		//dmgZone_torso
		RegisterBleedingZone("Neck", PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL,"", "-180 0 0" , "0.02 -0.05 0.05");
		RegisterBleedingZone("Pelvis",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 -135 0" , "0 0.12 0");
		RegisterBleedingZone("Spine",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 55 0" , "0 -0.1 0");
		RegisterBleedingZone("Spine1",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 155 0" , "0 -0.1 0");
		RegisterBleedingZone("Spine2",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 55 0" , "0 -0.07 0");
		RegisterBleedingZone("Spine3",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 155 0" , "0 -0.05 0");
		//dmgZone_leftArm
		RegisterBleedingZone("LeftShoulder",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 -90 0" , "0 0.07 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("LeftArm", PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "","0 90 90" , "0 -0.05 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("LeftArmRoll",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "0 -0.05 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("LeftForeArm",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "0 -0.05 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		//dmgZone_rightArm
		RegisterBleedingZone("RightShoulder",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "0 -0.07 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("RightArm", PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL,"", "0 -90 0" , "0 0.05 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("RightArmRoll",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 -90 0" , "0 0.05 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("RightForeArm",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 -90 0" , "0 0.05 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		//dmgZone_leftHand
		RegisterBleedingZone("LeftForeArmRoll",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "0.1 0 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_LOW, "BleedingSourceEffectLight");
		//dmgZone_rightHand
		RegisterBleedingZone("RightForeArmRoll",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "-0.1 0 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_LOW, "BleedingSourceEffectLight");
		//dmgZone_leftLeg
		RegisterBleedingZone("LeftLeg",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "0 -0.07 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("LeftLegRoll",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "0 -0.07 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("LeftUpLeg",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "0 -0.12 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("LeftUpLegRoll",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "0 -0.07 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		//dmgZone_rightLeg
		RegisterBleedingZone("RightLeg",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 -90 0" , "0 0.06 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("RightLegRoll",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 -90 0" , "0 0 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("RightUpLeg",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 -90 0" , "0 0.12 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		RegisterBleedingZone("RightUpLegRoll",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 -90 0" , "0 0.06 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM);
		//dmgZone_leftFoot
		RegisterBleedingZone("LeftFoot",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 180 0" , "0 0 0.035", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_LOW, "BleedingSourceEffectLight");
		RegisterBleedingZone("LeftToeBase",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 -90 0" , "0 0.07 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_LOW);
		//dmgZone_rightFoot
		RegisterBleedingZone("RightFoot",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 0 0" , "0 0 -0.035", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_LOW, "BleedingSourceEffectLight");
		RegisterBleedingZone("RightToeBase",PlayerConstants.BLEEDING_SOURCE_DURATION_NORMAL, "", "0 90 0" , "0 -0.07 0", PlayerConstants.BLEEDING_SOURCE_FLOW_MODIFIER_LOW);
	}
	
	protected int GetBitFromSelectionID(int id)
	{
		CachedObjectsArrays.ARRAY_STRING.Clear();
		m_Player.GetActionComponentNameList(id, CachedObjectsArrays.ARRAY_STRING, "fire");
		
		for(int i = 0; i < CachedObjectsArrays.ARRAY_STRING.Count(); i++)
		{
			/*
			string name = CachedObjectsArrays.ARRAY_STRING.Get(i);
			PrintString(name);
			*/
			int bit = GetBitFromSelectionName(CachedObjectsArrays.ARRAY_STRING.Get(i));
			if(  bit !=0 )
			{
				return bit;
			}
		}
		return 0;
	}
	
	protected BleedingSourceZone GetBleedingSourceMeta(int bit)
	{
		return m_BleedingSourceZone.Get(GetSelectionNameFromBit(bit));
	}
	
	protected void RegisterBleedingZone(string name, int max_time, string bone = "", vector orientation = "0 0 0", vector offset = "0 0 0", float flow_modifier = 1, string particle_name = "BleedingSourceEffect")
	{
		if( m_BitOffset == BIT_INT_SIZE)
		{
			Error("Too many bleeding sources, max is "+BIT_INT_SIZE.ToString());
		}
		else
		{
			name.ToLower();
			//PrintString(name);
			//int bit = Math.Pow(2, m_BitOffset);
			int bit = 1 << m_BitOffset;
			//PrintString(bit.ToString());
			string bone_name = bone;
			
			if(bone_name == "")
			{
				bone_name = name;
			}
			
			m_BleedingSourceZone.Insert(name, new BleedingSourceZone(name, bit, offset, orientation, bone_name, max_time, flow_modifier, particle_name));
			m_BitToFireGeom.Insert(bit, name);
			m_BitOffset++;
		}
	}
	
	void RemoveAllSources()
	{
		//int count = m_BleedingSources.Count();
		while (m_BleedingSources.Count() > 0 )
		{
			int bit = m_BleedingSources.GetKey(0);
			RemoveBleedingSource(bit);
		}
	}
	
	protected int GetBitFromSelectionName(string name)
	{
		if(!m_BleedingSourceZone.Get(name))
		{
			return 0;
		}
		return m_BleedingSourceZone.Get(name).GetBit();
	}	
	
	protected string GetSelectionNameFromBit(int bit)
	{
		return m_BitToFireGeom.Get(bit);
	}
	
	bool AttemptAddBleedingSource(int component)
	{
		int bit = GetBitFromSelectionID(component);
		
		if( bit == 0 )
		{
			return false;
		}
		
		if( CanAddBleedingSource(bit) )
		{
			AddBleedingSource(bit);
			return true;
		}
		
		return false;
	}
	
	bool AttemptAddBleedingSourceBySelection(string selection_name)
	{
		selection_name.ToLower();
		int bit = GetBitFromSelectionName(selection_name);
		
		if( bit == 0 )
		{
			return false;
		}
		
		if( CanAddBleedingSource(bit) )
		{
			AddBleedingSource(bit);
			return true;
		}
		return false;
	}
	
	protected bool CanAddBleedingSource(int bit)
	{
		if(!GetBleedingSourceMeta(bit)) return false;
		return ((m_Player.GetBleedingBits() & bit) == 0 );
	}
	
	protected void AddBleedingSource(int bit)
	{
		vector orientation = GetBleedingSourceMeta(bit).GetOrientation();
		vector offset = GetBleedingSourceMeta(bit).GetOffset();
		string bone_name =  GetBleedingSourceMeta(bit).GetBoneName();
		float flow_modifier = GetBleedingSourceMeta(bit).GetFlowModifier();
		int max_time = GetBleedingSourceMeta(bit).GetMaxTime();
		string particle_name = GetBleedingSourceMeta(bit).GetParticleName();
		m_BleedingSources.Insert(bit, new BleedingSource(m_Player, bit,bone_name, orientation, offset, max_time, flow_modifier, particle_name) );
		m_Player.OnBleedingSourceAdded();
	}
	
	int GetBleedingSourceActiveTime(int bit)
	{
		int time = -1;
		if(m_BleedingSources.Contains(bit))
		{
			time = m_BleedingSources.Get(bit).GetActiveTime();
		}
		return time;
	}
	
	void SetBleedingSourceActiveTime(int bit, int time)
	{
		if(m_BleedingSources.Contains(bit))
		{
			m_BleedingSources.Get(bit).SetActiveTime(time);
		}

	}

	protected bool RemoveBleedingSource(int bit)
	{
		if(m_BleedingSources.Contains(bit))
		{
			m_BleedingSources.Remove(bit);
			m_Player.OnBleedingSourceRemoved();
			return true;
		}
		return false;
	}

	int GetBleedingSourcesCount()
	{
		return m_BleedingSources.Count();
	}
}