class JumpEventsBase extends PlayerSoundEventBase
{
	override bool HasPriorityOverCurrent(PlayerBase player, EPlayerSoundEventID other_state_id, EPlayerSoundEventType type_other)
	{
		return true;
	}
	
	override bool CanPlay(PlayerBase player)
	{
		if( !super.CanPlay(player) )
		{
			return false;
		}
		return true;
	}
	
	override void OnPlay(PlayerBase player)
	{
		if( player.CanSpawnBreathVaporEffect() )
			player.SpawnBreathVaporEffect();
	}
	
	override void OnEnd()
	{
		//m_Player.GetStaminaSoundHandlerClient().PostponeStamina(1000);
		StaminaSoundHandlerClient.Cast(m_Player.m_PlayerSoundManagerClient.GetHandler(eSoundHandlers.STAMINA)).PostponeStamina(1300);
	}
}

class JumpSoundEvent extends JumpEventsBase
{
	void JumpSoundEvent()
	{
		m_HasPriorityOverTypes = -1;//-1 for all
		m_Type = EPlayerSoundEventType.GENERAL;
		m_ID = EPlayerSoundEventID.JUMP;
		m_SoundVoiceAnimEventClassID = 18;
	}
}