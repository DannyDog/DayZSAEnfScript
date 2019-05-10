class SalmonellaMdfr: ModifierBase
{
	static const int SALMONELLA_AGENT_THRESHOLD_ACTIVATE = 100;
	static const int SALMONELLA_AGENT_THRESHOLD_DEACTIVATE = 20;
	override void Init()
	{
		m_TrackActivatedTime			= false;
		m_ID 					= eModifiers.MDF_SALMONELLA;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}
	
	override protected bool ActivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(eAgents.SALMONELLA) > SALMONELLA_AGENT_THRESHOLD_ACTIVATE) 
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
		//if( player.m_NotifiersManager ) player.m_NotifiersManager.ActivateByType(eNotifiers.NTF_SICK);
		player.IncreaseDiseaseCount();
		
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(eAgents.SALMONELLA) < SALMONELLA_AGENT_THRESHOLD_DEACTIVATE) 
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
		//Log("Ticking OnTick influenza modifier "+ToString(player.GetSingleAgentCount(eAgents.INFLUENZA)));
		float chance_of_vomit = player.GetStatStomachVolume().GetNormalized() / 10;
		if( Math.RandomFloat01() < chance_of_vomit )
		{
			SymptomBase symptom = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
			
			if( symptom )
			{
				symptom.SetDuration(5);
			}
		}
	}
};