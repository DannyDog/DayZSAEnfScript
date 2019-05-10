enum EInfectedSoundEventType
{
	GENERAL,
}

class InfectedSoundEventBase extends SoundEventBase
{
	ZombieBase m_Infected;

	void InfectedSoundEventBase()
	{
		m_Type = EInfectedSoundEventType.GENERAL;
	}
	
	void ~InfectedSoundEventBase()
	{
		if(m_SoundSetCallback) m_SoundSetCallback.Stop();
	}

	void Init(ZombieBase pInfected)
	{
		m_Infected = pInfected;
	}
	
	void SoftStop()
	{
		if (m_SoundSetCallback)
		{
			m_SoundSetCallback.Loop(false);
			m_SoundSetCallback = null;
		}
	}

	override void Stop()
	{
		if (m_SoundSetCallback)
		{
			m_SoundSetCallback.Stop();
			m_SoundSetCallback = null;
		}

		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).RemoveByName(this, "PosUpdate");
	}
	
	void PosUpdate()
	{
		if (m_SoundSetCallback)
		{
			m_SoundSetCallback.SetPosition(m_Infected.GetPosition());
		}
	}
	
	override bool Play()
	{
		string soundset_name;
			
		soundset_name = m_Infected.ClassName() + "_" + m_SoundSetNameRoot + "_SoundSet";
		m_SoundSetCallback = m_Infected.ProcessVoiceFX(soundset_name);
		if ( m_SoundSetCallback )
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLaterByName(this, "PosUpdate", 0, true);
			return true;
		}
		return false;
	}
}