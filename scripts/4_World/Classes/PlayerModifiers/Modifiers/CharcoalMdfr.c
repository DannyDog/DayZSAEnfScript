class CharcoalMdfr: ModifierBase
{
	float m_Killrate;
	const int CHARCOAL_LIFETIME = 300;
	const int CHARCOAL_EFFECT_TIME = 100;
	
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= eModifiers.MDF_CHARCOAL;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 3;
		m_Killrate = 2.85;	// # of killed agents * m_TickIntervalActive
	}

	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}
	
	override void OnReconnect(PlayerBase player)
	{
		OnActivate( player );
	}
	
	override string GetDebugText()
	{
		return ( CHARCOAL_LIFETIME - GetAttachedTime() ).ToString();
	}

	
	override void OnActivate(PlayerBase player)
	{
		if ( player.GetNotifiersManager() )
			player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		if ( player.GetNotifiersManager() )
			player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
	}
	
	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();
		
		if ( attached_time >= CHARCOAL_LIFETIME )
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
		if ( GetAttachedTime() > ( CHARCOAL_LIFETIME - CHARCOAL_EFFECT_TIME ) )
		{		
			player.m_AgentPool.AddAgent(eAgents.SALMONELLA, -m_Killrate * deltaT);
		}
	}
};