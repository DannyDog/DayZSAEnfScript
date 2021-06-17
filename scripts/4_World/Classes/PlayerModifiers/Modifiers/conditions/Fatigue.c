class FatigueMdfr: ModifierBase
{	
	private float m_Time;
	private float m_NextEvent;
	
	static const float FATIGUE_EVENT_INTERVAL_MIN = 5;
	static const float FATIGUE_EVENT_INTERVAL_MAX = 12;
	static const float STAMINA_RECOVERY_MULTIPLIER = 0.33;
	static const float STAMINA_DEPLETION_MULTIPLIER = 1.33;
	
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 					= eModifiers.MDF_FATIGUE;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE_LONG;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}
	override bool ActivateCondition(PlayerBase player)
	{
		return (player.GetModifiersManager().IsModifierActive(eModifiers.MDF_WOUND_INFECTION1) || player.GetModifiersManager().IsModifierActive(eModifiers.MDF_WOUND_INFECTION2));
	}

	override void OnActivate(PlayerBase player)
	{
		if( player.m_NotifiersManager ) 
			player.m_NotifiersManager.ActivateByType(eNotifiers.NTF_FEVERISH);
		
		//player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
		
		player.GetStaminaHandler().SetRecoveryMultiplier(STAMINA_RECOVERY_MULTIPLIER);
		player.GetStaminaHandler().SetDepletionMultiplier(STAMINA_DEPLETION_MULTIPLIER);
	}

	override void OnReconnect(PlayerBase player)
	{
		this.OnActivate(player);
	}


	override void OnDeactivate(PlayerBase player)
	{
		//player.GetSymptomManager().RemoveSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
		player.GetStaminaHandler().SetRecoveryMultiplier(1);
		player.GetStaminaHandler().SetDepletionMultiplier(1);
	}


	override bool DeactivateCondition(PlayerBase player)
	{
		return  !ActivateCondition(player);
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		/*
		m_Time += deltaT;
	
		if ( m_Time >= m_NextEvent )
		{
			player.RequestSoundEvent(EPlayerSoundEventID.SYMPTOM_FATIGUE, false);
			m_Time = 0;
			m_NextEvent = Math.RandomFloatInclusive( FATIGUE_EVENT_INTERVAL_MIN, FATIGUE_EVENT_INTERVAL_MAX );
		}
		*/
	}
};