class FeverMdfr: ModifierBase
{
	private const float	 	TEMPERATURE_INCREMENT_PER_SEC = 0.1;
		
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 					= eModifiers.MDF_FEVER;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}
	override bool ActivateCondition(PlayerBase player)
	{
		//Print(GetGame().GetTime());
		return player.GetModifiersManager().IsModifierActive(eModifiers.MDF_INFLUENZA);
	}

	override void OnActivate(PlayerBase player)
	{
		//Print(GetGame().GetTime());
		if( player.m_NotifiersManager ) player.m_NotifiersManager.ActivateByType(eNotifiers.NTF_FEVERISH);
		
		player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
		
	}

	override void OnReconnect(PlayerBase player)
	{
		this.OnActivate(player);
	}


	override void OnDeactivate(PlayerBase player)
	{
		if( player.m_NotifiersManager ) player.m_NotifiersManager.DeactivateByType(eNotifiers.NTF_FEVERISH);
		player.GetSymptomManager().RemoveSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
	}


	override bool DeactivateCondition(PlayerBase player)
	{
		return !player.GetModifiersManager().IsModifierActive(eModifiers.MDF_INFLUENZA);
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		//player.GetStatTemperature().Add( (TEMPERATURE_INCREMENT_PER_SEC*deltaT) );
	}
};