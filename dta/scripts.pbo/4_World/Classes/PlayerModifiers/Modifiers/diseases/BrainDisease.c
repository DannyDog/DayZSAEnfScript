class BrainDiseaseMdfr: ModifierBase
{
	static const int BRAIN_AGENT_THRESHOLD_ACTIVATE = 2000;
	static const int BRAIN_AGENT_THRESHOLD_DEACTIVATE = 0;
	const int SHAKE_INTERVAL_MIN = 1;
	const int SHAKE_INTERVAL_MAX = 4;
	//const float SHAKE_INTERVAL_DEVIATION = 1;
	
	float m_Time;
	float m_ShakeTime;
	
	override void Init()
	{
		m_TrackActivatedTime	= false;
		m_ID 					= eModifiers.MDF_BRAIN;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}
	
	override protected bool ActivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(eAgents.BRAIN) > BRAIN_AGENT_THRESHOLD_ACTIVATE) 
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
		player.IncreaseDiseaseCount();
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(eAgents.BRAIN) < BRAIN_AGENT_THRESHOLD_DEACTIVATE) 
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
		m_Time += deltaT;
		float brain_agents = player.GetSingleAgentCountNormalized(eAgents.BRAIN);
		float chance_of_laughter = brain_agents / Math.RandomInt(1,10);
		
		if( Math.RandomFloat01() < chance_of_laughter )
		{
			player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_LAUGHTER);
		}
		
		if( m_Time >= m_ShakeTime )
		{
			DayZPlayerSyncJunctures.SendKuruRequest(player, brain_agents);
			m_ShakeTime = m_Time + Math.RandomFloat(SHAKE_INTERVAL_MIN, SHAKE_INTERVAL_MAX);
		}
		
	}
};