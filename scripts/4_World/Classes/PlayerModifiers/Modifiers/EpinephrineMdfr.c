class EpinephrineMdfr: ModifierBase
{
	const int LIFETIME = 60;
	
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= eModifiers.MDF_EPINEPHRINE;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}

	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}
	
	override void OnReconnect(PlayerBase player)
	{
		OnActivate(player);
	}
	
	override string GetDebugText()
	{
		return (LIFETIME - GetAttachedTime()).ToString();
	}
	
	override void OnActivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() ) player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);
		player.GiveShock(100);
		player.GetStaminaHandler().SetStamina(100);
		player.GetStaminaHandler().SetDepletionMultiplier(0);
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() ) player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
		player.GetStaminaHandler().SetDepletionMultiplier(1);
	}
	
	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();
		
		if( attached_time >= LIFETIME )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		//player.GetStaminaHandler().SetStamina(100);
	}

	
};