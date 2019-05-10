class UnconsciousnessMdfr: ModifierBase
{
	const int UNCONSIOUSS_COOLDOWN_TIME = 60;//in s
	
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 					= eModifiers.MDF_UNCONSCIOUSNESS;
		m_TickIntervalInactive 	= 0.5;
		m_TickIntervalActive 	= 0.5;
	}		

	override bool ActivateCondition(PlayerBase player)
	{
		if( player.GetHealth("","Shock") <=  PlayerConstants.UNCONSCIOUS_THRESHOLD && GetGame().GetTime() > player.m_UnconsciousEndTime + (UNCONSIOUSS_COOLDOWN_TIME * 1000))
		{
			return true;
		}
		return false;
	}
	
	override void OnActivate(PlayerBase player)
	{
		DayZPlayerSyncJunctures.SendPlayerUnconsciousness(player, true);
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		player.m_UnconsciousEndTime = GetGame().GetTime();
		DayZPlayerSyncJunctures.SendPlayerUnconsciousness(player, false);
	}
	
	override string GetDebugText()
	{
		return (PlayerConstants.CONSCIOUS_THRESHOLD - m_Player.GetHealth("","Shock")).ToString();
	}
	
	override void OnReconnect(PlayerBase player)
	{
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		if( player.GetHealth("","Shock") >=  PlayerConstants.CONSCIOUS_THRESHOLD )
		{
			return true;
		}
		return false;
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		player.AddHealth("","Shock", PlayerConstants.SHOCK_REFILl_UNCONSCIOUS_SPEED * deltaT);
	}
};