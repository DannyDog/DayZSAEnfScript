class SymptomSoundEventBase extends PlayerSoundEventBase
{
	void SymptomSoundEventBase()
	{
		m_Type = EPlayerSoundEventType.GENERAL;
		m_HasPriorityOverTypes = -1;
	}
	
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
}

class CoughSoundEvent extends SymptomSoundEventBase
{
	void CoughSoundEvent()
	{
		m_ID = EPlayerSoundEventID.SYMPTOM_COUGH;
		m_SoundVoiceAnimEventClassID = 8;
	}
}

class LaugherSoundEvent extends SymptomSoundEventBase
{
	void LaugherSoundEvent()
	{
		m_ID = EPlayerSoundEventID.SYMPTOM_LAUGHTER;
		m_SoundVoiceAnimEventClassID = 10;
	}
}

class SneezeSoundEvent extends SymptomSoundEventBase
{
	void SneezeSoundEvent()
	{
		m_ID = EPlayerSoundEventID.SYMPTOM_SNEEZE;
		m_SoundVoiceAnimEventClassID = 9;
	}
}