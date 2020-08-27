class EmoteBase
{
	//todo change to 'protected'
	PlayerBase m_Player;
	int m_ID = -1;
	int m_StanceMaskAdditive = 0;
	int m_StanceMaskFullbody = 0;
	int m_AdditiveCallbackUID = 0;
	int m_FullbodyCallbackUID = 0;
	bool m_HideItemInHands = false;
	
	bool EmoteCondition(int stancemask)
	{
		return true;
	}
	
	//! Checks for valid stance mask; redundant?
	bool EmoteFBStanceCheck(int stancemask)
	{
		int stanceIdx = DayZPlayerUtils.ConvertStanceMaskToStanceIdx(stancemask);
		
		if (!m_Player)
		{
			Print("EmoteFBStanceCheck | no player for 'PlayerCanChangeStance'");
			//DumpStack();
			return false;
		}
		
		if ( stanceIdx != -1 && !DayZPlayerUtils.PlayerCanChangeStance(m_Player, stanceIdx) )
			return false;
		
		return true;
	}
	
	bool DetermineOverride(out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		return false;
	}
	
	void OnBeforeStandardCallbackCreated(int callback_ID, int stancemask, bool is_fullbody)
	{
	}
}
