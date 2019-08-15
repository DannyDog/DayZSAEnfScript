class CorpseData
{
	bool 		m_bUpdate;
	int 		m_iLastUpdateTime;
	int 		m_iTimeOfDeath;
	int 		m_iMaxLifetime;
	int 		m_iCorpseState;
	int temp;
	PlayerBase 	m_Player;
	
	void CorpseData(notnull PlayerBase player,int time_of_death)
	{
		m_bUpdate = true;
		m_iLastUpdateTime = time_of_death;
		m_iTimeOfDeath = time_of_death;
		m_iMaxLifetime = -1;
		//m_iMaxLifetime = player.GetLifetime(); //player.GetEconomyProfile().GetLifetime();
		m_iCorpseState = PlayerConstants.CORPSE_STATE_FRESH;
		m_Player = player;
	}
	
	void UpdateCorpseState(bool force_check = false)
	{
		if (m_iMaxLifetime <= 0 )
		{
			if ( m_iCorpseState == PlayerConstants.CORPSE_STATE_DECAYED && !force_check )
			{
				m_bUpdate = false;
				return;
			}
			else
			{
				//initializes lifetime values to be used in calculations
				m_iMaxLifetime = m_Player.GetLifetime(); //TODO: adjusts init value by update time?
				m_Player.SetLifetime(m_iMaxLifetime);
			}
		}
		
		int ioriginal_state = m_iCorpseState;
		float fremaining_lifetime = m_Player.GetLifetime();
		float fdecay_percentage = fremaining_lifetime/m_iMaxLifetime;
/*
		Print("fremaining_lifetime - " + fremaining_lifetime);
		Print("m_iMaxLifetime - " + m_iMaxLifetime);
		Print("fdecay_percentage - " + fdecay_percentage);
*/
		
		//int current_time = GetGame().GetTime();
		//float fdecay_percentage_by_game_time = 1 - ((current_time - m_iTimeOfDeath) / 1000 )/m_iMaxLifetime;
		//Print("fdecay_percentage_by_game_time - " + fdecay_percentage_by_game_time);
		
		if (fdecay_percentage > PlayerConstants.CORPSE_THRESHOLD_MEDIUM)
		{
			m_iCorpseState = PlayerConstants.CORPSE_STATE_FRESH;
		}
		else if (fdecay_percentage <= PlayerConstants.CORPSE_THRESHOLD_MEDIUM && fdecay_percentage > PlayerConstants.CORPSE_THRESHOLD_DECAYED)
		{
			m_iCorpseState = PlayerConstants.CORPSE_STATE_MEDIUM;
		}
		else
		{
			m_iCorpseState = PlayerConstants.CORPSE_STATE_DECAYED;
			m_bUpdate = false;
		}
		
		if (ioriginal_state != m_iCorpseState)
		{
			m_Player.m_CorpseState = m_iCorpseState;
			m_Player.SetSynchDirty();
/*
			Print("Corpse Syncing | player - " + m_Player);
			Print("Corpse Syncing | state - " + m_iCorpseState);
*/
		}
	}
}
