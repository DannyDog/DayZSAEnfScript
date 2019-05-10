class CholeraMdfr: ModifierBase
{
	static const int CHOLERA_AGENT_THRESHOLD_ACTIVATE = 100;
	static const int CHOLERA_AGENT_THRESHOLD_DEACTIVATE = 20;
	
	float m_Time = 0;
	bool m_IsVomiting;
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 					= eModifiers.MDF_CHOLERA;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}
	
	override protected bool ActivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(eAgents.CHOLERA) > CHOLERA_AGENT_THRESHOLD_ACTIVATE) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	override protected void OnActivate(PlayerBase player)
	{
		m_IsVomiting = false;
		//if( player.m_NotifiersManager ) player.m_NotifiersManager.ActivateByType(eNotifiers.NTF_SICK);
		player.IncreaseDiseaseCount();
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(eAgents.CHOLERA) < CHOLERA_AGENT_THRESHOLD_DEACTIVATE) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	override protected void OnTick(PlayerBase player, float deltaT)
	{
		float chance_of_vomit = player.GetStatStomachVolume().GetNormalized() / 10;
		
		if( Math.RandomFloat01() < chance_of_vomit && !m_IsVomiting )
		{
			SymptomBase symptom = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
			
			if( symptom )
			{ 
				symptom.SetDuration(Math.RandomIntInclusive(4,8));
			}
			
			m_IsVomiting = true;
		}
	}
};