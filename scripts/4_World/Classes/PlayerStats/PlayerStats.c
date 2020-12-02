enum EPSstatsFlags
{
	EMPTY,
};

class PlayerStats
{
	ref array<ref PlayerStatBase> m_PlayerStats;
	ref array<ref StatDebugObject> m_PlayerStatsDebug;
	
	//ref PlayerStatsPCO_current m_PCO = new PlayerStatsPCO_current();
	ref PCOHandlerStats m_PCOhandler = new PCOHandlerStats();
	
	ref Timer m_SyncTimer;
	Man m_Player;
	bool m_AllowLogs;
	string m_System = "Stats"; //debuging tag
	
	//int m_SystemVersion = 101;
	
	void PlayerStats(Man player)
	{
		Init(player);
	}

	void Init(Man player)
	{
		m_Player 		= player;
	}

	PlayerStatsPCO_Base GetPCO(int version = -1 )
	{
		return m_PCOhandler.GetPCO(version);
	}
	
	void ~PlayerStats()
	{
		//if( GetGame() && GetGame().IsDebugActions() ) GatherAllRecords();
	}
	
	
	PlayerStatBase GetStatObject(int id)
	{
		if( GetPCO() )
		{
			return GetPCO().GetStatObject(id);
		}
		else
		{
			return null;
		}
	}
	
/*
	array<ref PlayerStatBase> Get()
	{
		return m_PlayerStats;
	}
*/
	void SetAllowLogs(bool enable)
	{
		m_AllowLogs = enable;
	}

	bool GetAllowLogs()
	{
		return 	m_AllowLogs;	
	}
	
	void GetDebugInfo( array<ref StatDebugObject> objects, int flags )
	{
		/*
		for(int i = 0; i < m_PlayerStats.Count(); i++)
		{
			m_PlayerStats.Get(i).SerializeValue(objects, flags);
		}
		*/
	}
	
	void GatherAllRecords()
	{
		/*
		FileHandle file = OpenFile("$profile:StatRecords.log", FileMode.WRITE);
		
		FPrintln(file, "================================================================");
		FPrintln(file," ================== " + m_Player.ToString() +" ================== ");
		FPrintln(file, "================================================================");
		
		for(int i = 0; i < m_PlayerStats.Count(); i++)
		{
			array<PlayerStatRecord> records =  m_PlayerStats.Get(i).GetRecords();
			
			FPrintln(file, m_PlayerStats.Get(i).GetLabel() );
			
			for(int z = 0; z < records.Count(); z++)
			{
				PlayerStatRecord record = records.Get(z);
				string output = record.GetStringOutput();
				FPrintln(file, output);
			}
		}
		*/
	}
	
	void SaveStats ( ParamsWriteContext ctx )
	{
		int current_version = GetGame().SaveVersion();
		
		if( GetPCO(current_version ) )
		{
			GetPCO(current_version).OnStoreSave(ctx);
			//Print("Saving stats in version: "+ GetPCO(current_version ).GetVersion());
		}
		else
		{
			return;
		}
	}

	bool LoadStats ( ParamsReadContext ctx, int version )
	{
		if(GetPCO(version) && GetPCO(version).OnStoreLoad(ctx))
		{
			Print("********* LoadStats loading version: " + GetPCO(version).GetVersion());
			return true;
		}
		else
		{
			return false;
		}
		
	}

}