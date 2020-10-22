class PluginDeveloperSync extends PluginBase
{
	int m_DetailedInfoRequested = 0;
	ref Timer m_UpdateTimer;
	ref array<PlayerBase> m_RegisteredPlayers;
	
	ref array<ref SyncedValue> m_PlayerStatsSynced;
	ref array<ref Param> m_PlayerStomachSynced;
	ref array<ref SyncedValueLevel> m_PlayerLevelsSynced;
	ref array<ref SyncedValueModifier> m_PlayerModsSynced;
	string 	m_PlayerModsDetailedSynced;
	ref array<ref SyncedValueAgent> m_PlayerAgentsSynced;
	
	bool m_StatsUpdateStatus;
	bool m_LevelsUpdateStatus;
	bool m_ModsUpdateStatus;
	bool m_AgentsUpdateStatus;
	bool m_StomachUpdateStatus;
	
	void PluginDeveloperSync()
	{
		m_RegisteredPlayers 	= new array<PlayerBase>;
		m_PlayerStatsSynced 	= new array<ref SyncedValue>;
		m_PlayerLevelsSynced 	= new array<ref SyncedValueLevel>;
		m_PlayerModsSynced 		= new array<ref SyncedValueModifier>;
		m_PlayerAgentsSynced 	= new array<ref SyncedValueAgent>;
		m_PlayerStomachSynced 	= new array<ref Param>;
		
		m_StatsUpdateStatus 	= false;
		m_LevelsUpdateStatus 	= false;
		m_ModsUpdateStatus 		= false;
		m_AgentsUpdateStatus 	= false;
		m_StomachUpdateStatus 	= false;
	}
	
	//================================================================
	// Init / Update
	//================================================================
	override void OnInit()
	{
		super.OnInit();
		
		if ( GetGame().IsServer() )
		{
			//create timer
			m_UpdateTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		}
	}

	void EnableUpdate( bool state, int type, PlayerBase player )
	{
		//set update by type
		RegisterPlayer( player );
		switch ( type )
		{
			case ERPCs.DEV_STATS_UPDATE: 
			{
				m_StatsUpdateStatus = state; 
				break;	
			}
			
			case ERPCs.DEV_LEVELS_UPDATE: 
			{
				m_LevelsUpdateStatus = state; 
				break;	
			}
			
			case ERPCs.DEV_MODS_UPDATE: 
			{
				m_ModsUpdateStatus = state; 
				break;	
			}
			
			case ERPCs.DEV_AGENTS_UPDATE: 
			{
				m_AgentsUpdateStatus = state; 
				break;	
			}	
			
			case ERPCs.DEV_STOMACH_UPDATE: 
			{
				m_StomachUpdateStatus = state; 
				break;	
			}
		}	
		if ( m_UpdateTimer )
		{
			if ( state && !m_UpdateTimer.IsRunning() )
			{
				//Print("ToggleUpdate() - RUN");
				
				if ( m_StatsUpdateStatus || m_ModsUpdateStatus || m_AgentsUpdateStatus || m_LevelsUpdateStatus || m_StomachUpdateStatus )
				{
					m_UpdateTimer.Run( 1, this, "Update", NULL, true );
					
				}
			}
			else
			{
				//Print("ToggleUpdate() - STOP");
				
				if ( !m_StatsUpdateStatus && !m_ModsUpdateStatus && !m_AgentsUpdateStatus && !m_LevelsUpdateStatus && !m_StomachUpdateStatus)
				{
					m_UpdateTimer.Stop();
				
					//unregister player
					UnregisterPlayer( player );
				}
			}
		}
	}
	
	void Update()
	{
		//Stats
		if ( m_LevelsUpdateStatus )
		{
			//Multiplayer server
			if ( !GetDayZGame().IsMultiplayer() || GetDayZGame().IsServer() )
			{
				for ( int i = 0; i < m_RegisteredPlayers.Count(); i++ )
				{
					if ( m_RegisteredPlayers.Get( i ) )
					{
						SendRPCLevels( m_RegisteredPlayers.Get( i ) );		
					}
				}
			}	
			//Local server
			/*
			else
			{
				if ( GetDayZGame().IsServer() )
				{
					//update local
					UpdateLevelsLocal();	
				}
			}*/
		}
		
		
		//Stats
		if ( m_StatsUpdateStatus )
		{
			//Multiplayer server
			if ( GetDayZGame().IsMultiplayer() && GetDayZGame().IsServer() )
			{
				for ( int z = 0; z < m_RegisteredPlayers.Count(); z++ )
				{
					if ( m_RegisteredPlayers.Get( z ) )
					{
						SendRPCStats( m_RegisteredPlayers.Get( z ) );		
					}
				}
			}	
			//Local server
			else
			{
				if ( GetDayZGame().IsServer() )
				{
					//update local
					UpdateStatsLocal();	
				}
			}
		}
		
		//Mods
		if ( m_ModsUpdateStatus )
		{
			//Multiplayer server
			if ( !GetDayZGame().IsMultiplayer() || GetDayZGame().IsServer() )
			{
				for ( int j = 0; j < m_RegisteredPlayers.Count(); j++ )
				{
					if ( m_RegisteredPlayers.Get( j ) )
					{
						SendRPCMods( m_RegisteredPlayers.Get( j ) );
						if( m_DetailedInfoRequested !=0 )
							SendRPCModsDetail(	m_RegisteredPlayers.Get( j ));
					}
				}
			}	
		}
		
		//Agents
		if ( m_AgentsUpdateStatus )
		{
			//Multiplayer server
			if ( !GetDayZGame().IsMultiplayer() || GetDayZGame().IsServer() )
			{
				for ( int k = 0; k < m_RegisteredPlayers.Count(); k++ )
				{
					if ( m_RegisteredPlayers.Get( k ) )
					{
						SendRPCAgents( m_RegisteredPlayers.Get( k ) );		
					}
				}
			}
		}		
		
		//Agents
		if ( m_StomachUpdateStatus )
		{
			//Multiplayer server
			if ( !GetDayZGame().IsMultiplayer() || GetDayZGame().IsServer() )
			{
				for ( int l = 0; l < m_RegisteredPlayers.Count(); l++ )
				{
					if ( m_RegisteredPlayers.Get( l ) )
					{
						SendRPCStomach( m_RegisteredPlayers.Get( l ) );		
					}
				}
			}
		}
	}
	
	//--- Register / Unregister player
	void RegisterPlayer( PlayerBase player )
	{
		if ( !IsPlayerRegistered( player ) ) 
		{
			m_RegisteredPlayers.Insert( player );
		}
	}

	void UnregisterPlayer( PlayerBase player )
	{
		if ( IsPlayerRegistered( player ) ) 
		{
			m_RegisteredPlayers.RemoveItem( player );
		}
	}

	bool IsPlayerRegistered( PlayerBase player )
	{
		if ( m_RegisteredPlayers.Find( player ) > 0 )
		{
			return true;
		}
		
		return false;
	}
	
	//================================================================
	// RPC
	//================================================================ 
	void OnRPC( PlayerBase player, int rpc_type, ParamsReadContext ctx )
	{
		if ( !GetGame().IsDebug() )
		{
			return;
		}
		
		switch( rpc_type )
		{
			case ERPCs.DEV_STATS_UPDATE:
			{
				EnableUpdate( GetRPCUpdateState( ctx ), ERPCs.DEV_STATS_UPDATE, player ); break;
			}
			
			case ERPCs.DEV_LEVELS_UPDATE:
			{
				EnableUpdate( GetRPCUpdateState( ctx ), ERPCs.DEV_LEVELS_UPDATE, player ); break;
			}
			
			case ERPCs.DEV_MODS_UPDATE:
			{
				EnableUpdate( GetRPCUpdateState( ctx ), ERPCs.DEV_MODS_UPDATE, player ); break;
			}
			
			case ERPCs.DEV_AGENTS_UPDATE:
			{
				EnableUpdate( GetRPCUpdateState( ctx ), ERPCs.DEV_AGENTS_UPDATE, player ); break;
			}
			
			case ERPCs.DEV_STOMACH_UPDATE:
			{
				EnableUpdate( GetRPCUpdateState( ctx ), ERPCs.DEV_STOMACH_UPDATE, player ); break;
			}
			
			case ERPCs.DEV_RPC_STATS_DATA:
			{
				OnRPCStats( ctx ); break;
			}
			
			case ERPCs.DEV_RPC_LEVELS_DATA:
			{
				OnRPCLevels( ctx ); break;
			}

			case ERPCs.DEV_RPC_MODS_DATA:
			{
				OnRPCMods( ctx ); break;
			}
			
			case ERPCs.DEV_RPC_MODS_DATA_DETAILED:
			{
				OnRPCModsDetailed( ctx ); break;
			}
			
			case ERPCs.DEV_RPC_AGENTS_DATA:
			{
				OnRPCAgents( ctx ); break;
			}		
			case ERPCs.DEV_RPC_STOMACH_DATA:
			{
				OnRPCStomach( ctx ); break;
			}
			
			case ERPCs.DEV_RPC_MODS_ACTIVATE:
			{
				ActivateModifier( GetRPCModifierID( ctx ), player ); break;
			}
			case ERPCs.DEV_RPC_MODS_DETAILED:
			{
				RequestDetailedInfo( GetRPCModifierID( ctx ), player ); break;
			}
			
			case ERPCs.DEV_RPC_MODS_DEACTIVATE:
			{
				DeactivateModifier( GetRPCModifierID( ctx ), player ); break;
			}
			
			case ERPCs.DEV_RPC_MODS_LOCK:
			{
				int id;
				bool lock;
				GetRPCModifierLock( ctx, id, lock );
				LockModifier( id, lock, player ); break;
			}
		}
	}
	
	//get update status from ctx data
	bool GetRPCUpdateState( ParamsReadContext ctx )
	{
		ref Param1<bool> p = new Param1<bool>( 0 );
		if ( ctx.Read( p ) )
		{
			return p.param1;
		}
		
		return false;
	}
	
	//get modifier id from ctx data
	int GetRPCModifierID( ParamsReadContext ctx )
	{
		ref Param1<int> p = new Param1<int>( 0 );
		if ( ctx.Read( p ) )
		{
			return p.param1;
		}
		
		return 0;
	}
	
	//get modifier lock state from lock ctx data
	void GetRPCModifierLock( ParamsReadContext ctx, out int id, out bool lock )
	{
		ref Param2<int, bool> p = new Param2<int, bool>( 0, false );
		if ( ctx.Read( p ) )
		{
			id = p.param1;
			lock = p.param2;
		}
	}

	//============================================
	// STATS
	//============================================	
	//send player stats through RPC
	void SendRPCStats( PlayerBase player )
	{
		//write and send values
		if ( player )
		{
			array<ref Param> rpc_params = new array<ref Param>;
			
			//param count
			for ( int i = 0; i < player.m_PlayerStats.GetPCO().Get().Count(); i++ ) 
			{
				string label = player.m_PlayerStats.GetPCO().Get().Get( i ).GetLabel();
				float value = (float) player.m_PlayerStats.GetPCO().Get().Get( i ).Get();
				rpc_params.Insert( new Param2<string, float>( label, value ) );
			}
			rpc_params.Insert(new Param2<string, float>( "(NaS)Immunity", player.GetImmunity() ));
			rpc_params.Insert(new Param2<string, float>( "(NaS)BrokenLegs", player.m_BrokenLegState ));
		
			float param_count = (float) rpc_params.Count();
			rpc_params.InsertAt( new Param2<string, float>( "PARAM_COUNT", param_count ), 0);
			//send params
			GetDayZGame().RPC( player, ERPCs.DEV_RPC_STATS_DATA, rpc_params, true, player.GetIdentity() );
		}
	}

	//Display player stats
	void OnRPCStats( ParamsReadContext ctx )
	{
		//clear values
		m_PlayerStatsSynced.Clear();
		
		ref Param2<string, float> p = new Param2<string, float>( "", 0 );
		
		//get param count
		int param_count = 0;
		if ( ctx.Read(p) )
		{
			param_count = (int) p.param2;
		}
		
		//read values and set 
		for ( int i = 0; i < param_count; i++ )
		{
			ctx.Read(p);
			m_PlayerStatsSynced.Insert( new SyncedValue( p.param1, p.param2, false ) );
		}
	}

	//Update data on local
	void UpdateStatsLocal()
	{
		PlayerBase player = PlayerBase.Cast( GetDayZGame().GetPlayer() );
		
		//clear values
		m_PlayerStatsSynced.Clear();
		
		//set values
		for ( int i = 0; i < player.m_PlayerStats.GetPCO().Get().Count(); i++ ) 
		{
			string label = player.m_PlayerStats.GetPCO().Get().Get( i ).GetLabel();
			float value = player.m_PlayerStats.GetPCO().Get().Get( i ).Get();
			m_PlayerStatsSynced.Insert( new SyncedValue( label, value, false ) );
		}
			m_PlayerStatsSynced.Insert(new SyncedValue(  "(NaS)Immunity", player.GetImmunity() , false));
			m_PlayerStatsSynced.Insert(new SyncedValue(  "(NaS) BrokenLegs", player.m_BrokenLegState, false));
	}

	//============================================
	// LEVELS
	//============================================	
	//send player stats through RPC
	void SendRPCLevels( PlayerBase player )
	{
		//write and send values
		if ( player )
		{
			array<ref Param> rpc_params = new array<ref Param>;

			rpc_params.Insert(new Param3<string, float, float>( "Immunity: "+ typename.EnumToString(EStatLevels, player.GetImmunityLevel() ),player.GetImmunityLevel(), player.GetBordersImmunity()));
			rpc_params.Insert(new Param3<string, float, float>( "Blood: "+ typename.EnumToString(EStatLevels, player.GetStatLevelBlood()),player.GetStatLevelBlood(), player.GetStatBordersBlood()));
			rpc_params.Insert(new Param3<string, float, float>( "Health: "+ typename.EnumToString(EStatLevels, player.GetStatLevelHealth() ),player.GetStatLevelHealth(), player.GetStatBordersHealth()));
			rpc_params.Insert(new Param3<string, float, float>( "Energy: "+ typename.EnumToString(EStatLevels, player.GetStatLevelEnergy() ),player.GetStatLevelEnergy(), player.GetStatBordersEnergy()));
			rpc_params.Insert(new Param3<string, float, float>( "Water: "+ typename.EnumToString(EStatLevels, player.GetStatLevelWater() ),player.GetStatLevelWater(), player.GetStatBordersWater()));
			
			int param_count = rpc_params.Count();
			rpc_params.InsertAt( new Param3<string, float, float>( "PARAM_COUNT", param_count,0 ), 0);
			//send params
			GetDayZGame().RPC( player, ERPCs.DEV_RPC_LEVELS_DATA, rpc_params, true, player.GetIdentity() );
		}
	}

	//Display player stats
	void OnRPCLevels( ParamsReadContext ctx )
	{
		//clear values
		m_PlayerLevelsSynced.Clear();
		
		ref Param3<string, float, float> p3 = new Param3<string, float, float>( "", 0,0 );
		
		//get param count
		int param_count = 0;
		if ( ctx.Read(p3) )
		{
			param_count = p3.param2;
		}
		
		//read values and set 
		for ( int i = 0; i < param_count; i++ )
		{
			if( ctx.Read(p3) )
				m_PlayerLevelsSynced.Insert( new SyncedValueLevel( p3.param1, p3.param2, p3.param3 ) );
		}
	}
	
	//Update data on local
	/*
	void UpdateLevelsLocal()
	{
		PlayerBase player = PlayerBase.Cast( GetDayZGame().GetPlayer() );
		
		//clear values
		m_PlayerLevelsSynced.Clear();
		m_PlayerLevelsSynced.Insert(new SyncedValueLevel( "Immunity: "+ typename.EnumToString(EStatLevels, player.GetImmunityLevel() ),player.GetImmunityLevel(),0));
		m_PlayerLevelsSynced.Insert(new SyncedValueLevel( "Blood: "+ typename.EnumToString(EStatLevels, player.GetStatLevelBlood()),player.GetStatLevelBlood(), player.GetStatBordersBlood()));
		m_PlayerLevelsSynced.Insert(new SyncedValueLevel( "Health: "+ typename.EnumToString(EStatLevels, player.GetStatLevelHealth() ),player.GetStatLevelHealth(), player.GetStatBordersHealth()));
		m_PlayerLevelsSynced.Insert(new SyncedValueLevel( "Energy: "+ typename.EnumToString(EStatLevels, player.GetStatLevelEnergy() ),player.GetStatLevelEnergy(), player.GetStatBordersEnergy()));
		m_PlayerLevelsSynced.Insert(new SyncedValueLevel( "Water: "+ typename.EnumToString(EStatLevels, player.GetStatLevelWater() ),player.GetStatLevelWater(), player.GetStatBordersWater()));
	}
	*/
	
	
	
	//============================================
	// MODS
	//============================================	
	//send player mods through RPC
	/*
	void SendRPCMods( PlayerBase player )
	{
		//write and send values
		if ( player )
		{
			array<ref Param> rpc_params = new array<ref Param>;
			
			//get modifiers
			ModifiersManager mods_manager = player.GetModifiersManager();
			
			//param count
			map<int, string> modifiers = new map<int, string>;
			mods_manager.DbgGetModifiers( modifiers );
			
			float param_count = ( float ) modifiers.Count();
			rpc_params.Insert( new Param3<string, float, bool>( "PARAM_COUNT", param_count, false ) );
			
			//set modifiers
			for ( int i = 0; i < modifiers.Count(); ++i ) 
			{
				int key = modifiers.GetKey( i );
				string value = modifiers.Get( key );
				bool state = IsModifierLocked( key, player );
				rpc_params.Insert( new Param3<string, float, bool>( value, key, state ) );
			}
			
			//send params
			GetDayZGame().RPC( player, ERPCs.DEV_RPC_MODS_DATA, rpc_params, true, player.GetIdentity() );
		}
	}
	*/
	void SendRPCMods( PlayerBase player )
	{
		//write and send values
		if ( player )
		{
			array<ref Param> rpc_params = new array<ref Param>;
			
			//get modifiers
			ModifiersManager mods_manager = player.GetModifiersManager();
			
			//param count
			array<ref ModifierDebugObj> modifiers = new array<ref ModifierDebugObj>;
			mods_manager.DbgGetModifiers( modifiers );
			
			float param_count = ( float ) modifiers.Count();
			rpc_params.Insert( new Param1<int>( param_count ));
			
			//set modifiers
			for ( int i = 0; i < modifiers.Count(); ++i ) 
			{
				int id = modifiers.Get(i).GetID();
				string name = modifiers.Get(i).GetName();
				bool active =  modifiers.Get(i).IsActive();
				bool locked =  modifiers.Get(i).IsLocked();
				
				rpc_params.Insert( new Param4<int, string, bool, bool>( id, name, active, locked ) );
			}
			
			//send params
			GetDayZGame().RPC( player, ERPCs.DEV_RPC_MODS_DATA, rpc_params, true, player.GetIdentity() );
		}
	}
	
	//============================================
	// MODS
	//============================================	
	//send player mods through RPC
	void SendRPCModsDetail( PlayerBase player )
	{
		//write and send values
		if ( player )
		{
			
			Param1<string> p1 = new Param1<string>("");
			ModifiersManager mods_manager = player.GetModifiersManager();
			
			if(m_DetailedInfoRequested != 0)
			{
				p1.param1 = mods_manager.GetModifier(m_DetailedInfoRequested).GetDebugText();
				//send params
				if(p1.param1 != "")
					GetDayZGame().RPCSingleParam( player, ERPCs.DEV_RPC_MODS_DATA_DETAILED, p1, true, player.GetIdentity() );
			}
		}
	}

	//Display player modifiers
	void OnRPCMods( ParamsReadContext ctx )
	{
		//clear values
		m_PlayerModsSynced.Clear();
		
		//ref Param3<string, float, bool> p = new Param3<string, float, bool>( "", 0, false );
		Param1<int> p1 = new Param1<int>(0);
		Param4<int, string, bool, bool> p4 = new Param4<int, string, bool, bool>( 0,"", false, false );
		//get param count
		int param_count = 0;
		if ( ctx.Read(p1) )
		{
			param_count = (int) p1.param1;
		}
		
		//read values and set 
		for ( int i = 0; i < param_count; i++ )
		{
			if(ctx.Read(p4))
			{
				m_PlayerModsSynced.Insert( new SyncedValueModifier( p4.param1, p4.param2, p4.param3, p4.param4 ) );
			}
		}
	}
	
	void OnRPCModsDetailed( ParamsReadContext ctx )
	{
		Param1<string> p1 = new Param1<string>("");
		
		//get param count
		if ( ctx.Read(p1) )
		{
			m_PlayerModsDetailedSynced = p1.param1;
		}
	}

	
	
	//Activates modifier with given ID
	void RequestDetailedInfo( int id, PlayerBase player = NULL )
	{
		int modifier_id = Math.AbsInt( id );
		if(id == m_DetailedInfoRequested)
		{
			m_DetailedInfoRequested = 0;//repeated request --> disable
		}
		else
		{
			m_DetailedInfoRequested = modifier_id;
		}
	}
	
	
	//Activates modifier with given ID
	void ActivateModifier( int id, PlayerBase player = NULL )
	{
		if ( !player )
		{
			player = PlayerBase.Cast( GetDayZGame().GetPlayer() );
		}
		ModifiersManager mods_manager = player.GetModifiersManager();
		mods_manager.ActivateModifier( Math.AbsInt( id ) );
	}

	//Activates modifier with given ID
	void DeactivateModifier( int id, PlayerBase player = NULL )
	{
		if ( !player )
		{
			player = PlayerBase.Cast( GetDayZGame().GetPlayer() );
		}
		ModifiersManager mods_manager = player.GetModifiersManager();
		mods_manager.DeactivateModifier( Math.AbsInt( id ) );
	}

	//Activates modifier with given ID
	void LockModifier( int id, bool lock, PlayerBase player = NULL )
	{
		if ( !player )
		{
			player = PlayerBase.Cast( GetDayZGame().GetPlayer() );
		}
		ModifiersManager mods_manager = player.GetModifiersManager();
		mods_manager.SetModifierLock( Math.AbsInt( id ), lock );
	}
	
	bool IsModifierLocked( int id, PlayerBase player = NULL )
	{
		if ( !player )
		{
			player = PlayerBase.Cast( GetDayZGame().GetPlayer() );
		}
		ModifiersManager mods_manager = player.GetModifiersManager();	
		
		return mods_manager.GetModifierLock( Math.AbsInt( id ) );
	}
	
	//============================================
	// AGENTS
	//============================================	
	//send player mods through RPC
	void SendRPCAgents( PlayerBase player )
	{
		//write and send values
		if ( ( player && player.GetIdentity() ) || ( player && !GetGame().IsMultiplayer() ) )
		{
			
			//get agent pool data
			array<ref Param> agent_pool = new array<ref Param>;
			player.m_AgentPool.GetDebugObject( agent_pool );
		
			GetDayZGame().RPC( player, ERPCs.DEV_RPC_AGENTS_DATA, agent_pool, true, player.GetIdentity() );
		}
	}

	//Display player modifiers
	void OnRPCAgents( ParamsReadContext ctx )
	{
		//clear values
		m_PlayerAgentsSynced.Clear();
		
		ref Param3<string, string, int> p3 = new Param3<string, string, int>( "", "" ,0 );
		Param1<int> p1 = new Param1<int>(0);
		
		//get param count
		int param_count = 0;
		if ( ctx.Read(p1) )
		{
			param_count = p1.param1;
		}
		
		//read values and set 
		for ( int i = 0; i < param_count; i++ )
		{
			ctx.Read(p3);
			m_PlayerAgentsSynced.Insert( new SyncedValueAgent( p3.param1, p3.param2, p3.param3 ) );
		}
	}
	
	//============================================
	// STOMACH
	//============================================	

	void SendRPCStomach( PlayerBase player )
	{
		//write and send values
		if ( player )
		{
			
			array<ref Param> stomach = new array<ref Param>;
			int count = player.m_PlayerStomach.GetDebugObject( stomach );
			stomach.InsertAt(new Param1<int>(count), 0);
		
			GetDayZGame().RPC( player, ERPCs.DEV_RPC_STOMACH_DATA, stomach, true, player.GetIdentity() );
		}
	}


	void OnRPCStomach( ParamsReadContext ctx )
	{
		//clear values
		m_PlayerStomachSynced.Clear();
		
		Param1<int> p1 = new Param1<int>(0);
		int param_count = 0;
		if ( ctx.Read(p1) )
		{
			param_count = p1.param1;
		}
		
		if(param_count)
		{
			//invidividual stomach items
			for ( int i = 0; i < param_count; i++ )
			{
				Param4<int,int,int,float> p4 = new Param4<int,int,int,float>(0,0,0,0);
				ctx.Read(p4);
				m_PlayerStomachSynced.Insert(p4);
			}
			//volume
			Param1<float> p1b = new Param1<float>(0);
			ctx.Read(p1b);
			m_PlayerStomachSynced.Insert(p1b);
		}
	}

	//Update data on local
	/*
	void UpdateAgentsLocal()
	{
		PlayerBase player = PlayerBase.Cast( GetDayZGame().GetPlayer() );
		
		if ( player )
		{
			//clear values
			m_PlayerAgentsSynced.Clear();
			
			//get agent pool data
			array<ref Param> agent_pool = new array<ref Param>;
			player.m_AgentPool.GetDebugObject( agent_pool );
			
			//get agents count 
			Param1<int> p1 = Param1<int>.Cast( agent_pool.Get( 0 ) );
			int agents_count = p1.param1;
			
			//set synced data
			for ( int i = 0; i < agents_count; i++ ) 
			{
				string name = Param2<string,string>.Cast(agent_pool.Get(i+1)).param1;
				string count = Param2<string,string>.Cast(agent_pool.Get(i+1)).param2;
				m_PlayerAgentsSynced.Insert( new SyncedValueAgent( name, count, false ) );
			}
		}
	}
	*/
	//================================================================
	// FOCUS
	//================================================================ 
	void CaptureFocus()
	{
		GetGame().GetInput().ChangeGameFocus( 1 );
		GetGame().GetUIManager().ShowUICursor( true );
	}
	
	void ReleaseFocus()
	{
		GetGame().GetInput().ChangeGameFocus( -1 );
		GetGame().GetUIManager().ShowUICursor( false );
	}
	
	void ToggleFocus()
	{
		if ( GetGame().GetInput().HasGameFocus() )
		{
			GetGame().GetInput().ChangeGameFocus( 1 );
			GetGame().GetUIManager().ShowUICursor( true );
		}
		else
		{
			GetGame().GetInput().ResetGameFocus();
			GetGame().GetUIManager().ShowUICursor( false );
		}
	}
}
