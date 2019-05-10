class StuffedStomachMdfr: ModifierBase
{
	protected const int	 	STUFFED_TRESHOLD 			= 1500;
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 					= eModifiers.MDF_STUFFED;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}
	
	override void OnTick(PlayerBase player, float deltaT)
	{

	}
	
	override bool ActivateCondition(PlayerBase player)
	{
		float stomach = player.GetStatStomachVolume().Get();
		if ( stomach >= STUFFED_TRESHOLD )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void OnActivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() )
		{
			player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_STUFFED);
		}
	}

	override void OnDeactivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() )
		{
			player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_STUFFED);
		}
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		return !ActivateCondition(player);
	}

};