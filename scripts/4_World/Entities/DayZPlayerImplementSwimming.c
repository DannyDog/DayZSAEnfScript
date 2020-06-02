
class DayZPlayerImplementSwimming
{

	DayZPlayer 					m_pPlayer;
	SHumanCommandSwimSettings	m_pSettings;
	bool						m_bWasSwimming = false; // important for shallow water, so we know if we should get back into swimming when other fullbody command (like damage) finished

	void DayZPlayerImplementSwimming(DayZPlayer pPlayer)
	{
		m_pPlayer 	= pPlayer;
		m_pSettings	= pPlayer.GetDayZPlayerType().CommandSwimSettingsW();
	}

	float  GetWaterDepth()
	{
		vector 	pp = m_pPlayer.GetPosition();
		vector  wl = HumanCommandSwim.WaterLevelCheck(m_pPlayer, pp);

		return wl[0];
	}

	float  GetCharacterDepth()
	{
		vector 	pp = m_pPlayer.GetPosition();
		vector  wl = HumanCommandSwim.WaterLevelCheck(m_pPlayer, pp);

		return wl[1];
	}

	bool CheckSwimmingStart(out vector waterLevel)
	{
		vector 	pp = m_pPlayer.GetPosition();
		waterLevel = HumanCommandSwim.WaterLevelCheck(m_pPlayer, pp);
			
		//! if total water depth >= 1.5m && character is 1.5m in water 
		return (waterLevel[0] >= m_pSettings.m_fWaterLevelIn && waterLevel[1] >= m_pSettings.m_fWaterLevelIn);
	}

	//! ha
	bool HandleSwimming(int pCurrentCommandID, HumanCommandMove pCMove, HumanMovementState pState)
	{
		
		if( pCurrentCommandID == DayZPlayerConstants.COMMANDID_UNCONSCIOUS || pCurrentCommandID == DayZPlayerConstants.COMMANDID_DAMAGE )
			return false;
		
		m_bWasSwimming = false;

		//! get water level 
		if (pCurrentCommandID != DayZPlayerConstants.COMMANDID_SWIM)
		{
			vector wl;
			if( CheckSwimmingStart(wl) )
			{
				m_pPlayer.StartCommand_Swim();
				m_bWasSwimming = true;
				return true;
			}
			
			//! now movement
			if (pCurrentCommandID == DayZPlayerConstants.COMMANDID_MOVE)
			{
				if (wl[1] > m_pSettings.m_fToErectLevel)
				{
					pCMove.ForceStanceUp(DayZPlayerConstants.STANCEIDX_ERECT);
				}
				else if (wl[1] > m_pSettings.m_fToCrouchLevel)
				{
					pCMove.ForceStanceUp(DayZPlayerConstants.STANCEIDX_CROUCH);
				}
			}

			// not handled 
			return false;
		}
		else // if (pCurrentCommandID == DayZPlayerConstants.COMMANDID_SWIM)
		{
			if (GetWaterDepth() < m_pSettings.m_fWaterLevelOut)
			{
				HumanCommandSwim hcs = m_pPlayer.GetCommand_Swim();
				hcs.StopSwimming();
				m_bWasSwimming = false;
				return true;
			}
		
			//! handled !
			m_bWasSwimming = true;
			return true;
		}
	}
}