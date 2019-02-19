class PluginAdminLog extends PluginBase			// Class for admin log messages handled by script
{
	string 						m_PlayerName;
	string						m_Pid;
	vector 						m_Position; 
	string						m_PlayerPrefix;
	string 						m_PlayerPrefix2;
	string						m_DisplayName;
	float						m_Distance;
	PlayerBase					m_Source;
	PlayerIdentity				m_Identity;
	string 						m_PosArray[3];
	int 						m_DotIndex;
	PlayerStat<float>			m_StatWater;
	PlayerStat<float>			m_StatEnergy;
	BleedingSourcesManagerServer	m_BleedMgr;
	
	/* EXE side ADM log messages (not removable)
		Connect / Disconnect
		Chat
		Player->Admin report (ingame chat: #toadmin <text> )	
	*/

	void PluginAdminLog()
	{
		//filtering prep
		/*FileHandle file;
		if ( FileExist( "$profile:AdminLog.cfg" ) )
		{		
			file = OpenFile("$profile:AdminLog.cfg", FileMode.READ);
			if (file != 0)
			{
				CloseFile(file);
			}
			else
			{
				LogPrint("Can't open AdminLog.cfg");
			}
		}
		else
		{
			file = OpenFile("$profile:AdminLog.cfg", FileMode.WRITE);
			if (file != 0)
			{
				LogPrint("Configuration not found - creating new AdminLog.cfg");
				//FPrintln(file, "LogHits=1");
				//FPrintln(file, "LogPlacement=1");
				CloseFile(file);
			}
			else
			{
				LogPrint("Can't create AdminLog.cfg");
			}
		}*/
	}
	
	void LogPrint( string message )
	{
		GetGame().AdminLog( message );
	}
	
	string GetPlayerPrefix( PlayerBase player, PlayerIdentity identity )  // player name + id + position prefix for log prints
	{	
		
		m_Position = player.GetPosition();
		m_PosArray[3] = { m_Position[0].ToString(), m_Position[2].ToString(), m_Position[1].ToString() };
		
		for ( int i = 0; i < 3; i++ )	// trim position precision
		{
			m_DotIndex = m_PosArray[i].IndexOf(".");
			if ( m_DotIndex != -1 )
			{
			m_PosArray[i] = m_PosArray[i].Substring( 0, m_DotIndex + 2 );
			}
		}
		
		if ( !identity ) 	// return partial message even if it fails to fetch identity 
		{
			return "Player \""  + "Unknown Entity" + "\" (id=" + "Unknown" + " pos=<" +  m_PosArray[0] + ", " + m_PosArray[1] + ", " + m_PosArray[2] + ">)";
		}
		
		m_PlayerName = identity.GetName();
		m_Pid = identity.GetId();
		
		return "Player \""  + m_PlayerName + "\" (id=" + m_Pid + " pos=<" +  m_PosArray[0] + ", " + m_PosArray[1] + ", " + m_PosArray[2] + ">)";
	}
		
	void PlayerKilled( PlayerBase player, Object source )  // PlayerBase.c   
	{
		
		if ( player && source )
		{
			m_PlayerPrefix = this.GetPlayerPrefix( player , player.GetIdentity() );
			
			if( player == source )	// deaths not caused by another object (starvation, dehydration)
			{
				m_StatWater = player.GetStatWater();
				m_StatEnergy = player.GetStatEnergy();
				m_BleedMgr = player.GetBleedingManagerServer();
				
				if ( m_StatWater && m_StatEnergy && m_BleedMgr )
				{
					LogPrint( m_PlayerPrefix + " died. Stats> Water: " + m_StatWater.Get().ToString() + " Energy: " + m_StatEnergy.Get().ToString() + " Bleed sources: " + m_BleedMgr.GetBleedingSourcesCount().ToString() );
				}
				else if ( m_StatWater && m_StatEnergy && !m_BleedMgr )
				{
					LogPrint( m_PlayerPrefix + " died. Stats> Water: " + m_StatWater.Get().ToString() + " Energy: " + m_StatEnergy.Get().ToString() );
				}
				else
				{
					LogPrint( m_PlayerPrefix + " died. Stats> could not fetch");
				}
			}
			else if ( source.IsWeapon() )  // player
			{				
				m_Source = PlayerBase.Cast( EntityAI.Cast( source ).GetHierarchyParent() );
				m_PlayerPrefix2 = this.GetPlayerPrefix( m_Source ,  m_Source.GetIdentity() );
				
				LogPrint( m_PlayerPrefix + " killed by " + m_PlayerPrefix2 + " with " + source.GetDisplayName() );	
			}
			else					// others
			{
				LogPrint( m_PlayerPrefix + " killed by " + source.GetDisplayName() );
			}
		}
		else 
		{
			LogPrint("DEBUG: PlayerKilled() player/object does not exist");
		}	
	}
	
	void PlayerHitBy( PlayerBase player, EntityAI source, string dmgZone, string ammo ) // PlayerBase.c 
	{
		if ( !player.IsAlive() )
		{
			return;
		}
		
		m_Identity = player.GetIdentity();
		
		if ( !source.IsZombie() && !source.IsAnimal() && m_Identity )		// don't log infected/animal hits or if it fails to fetch the identity
		{
			m_PlayerPrefix = this.GetPlayerPrefix( player ,  m_Identity );
			
			if ( source.IsPlayer() ) 		// player 
			{
				if ( ammo == "FallDamage" ) // fall damage
				{
					LogPrint( m_PlayerPrefix + " suffered " + ammo );	
					return;
				}
				
				m_Source = PlayerBase.Cast( source );
				m_PlayerPrefix2 = this.GetPlayerPrefix( m_Source ,  m_Source.GetIdentity() );

				LogPrint( m_PlayerPrefix + " hit by " + m_PlayerPrefix2 + " into " + dmgZone + " with " + ammo );	
				
			}
			else if ( Object.Cast(source).IsWeapon() || Object.Cast(source).IsMeleeWeapon() )  // weapon
			{
							
				m_Source = PlayerBase.Cast( source.GetHierarchyParent() );
				m_PlayerPrefix2 = this.GetPlayerPrefix( m_Source ,  m_Source.GetIdentity() );	
				
				if ( source.IsMeleeWeapon() )		// melee
				{
					LogPrint( m_PlayerPrefix + " hit by " + m_PlayerPrefix2 + " into " + dmgZone + " with " + ammo );	
				}
				else								// ranged
				{
					m_Distance = vector.Distance( player.GetPosition(), m_Source.GetPosition() );	
					
					LogPrint( m_PlayerPrefix + " hit by " + m_PlayerPrefix2 + " into " + dmgZone + " with " + ammo + " from " + m_Distance + " meters ");	
				}
			}
			else  // others
			{
				m_DisplayName = Object.Cast(source).GetDisplayName();
				
				if ( dmgZone == "" )
				{
					dmgZone = "body";
				}
				
				LogPrint( m_PlayerPrefix + " hit by " + m_DisplayName + " into " + dmgZone );	
			}			
		}
	}
	
	void UnconStart( PlayerBase player )	//  PlayerBase.c  
	{
		m_PlayerPrefix = this.GetPlayerPrefix( player ,  player.GetIdentity() );
		
		LogPrint( m_PlayerPrefix + " is unconscious" );
	}
	
	void UnconStop( PlayerBase player ) //  PlayerBase.c 
	{	
		if ( player.IsAlive() ) 	// Do not log uncon stop for dead players
		{
			m_PlayerPrefix = this.GetPlayerPrefix( player ,  player.GetIdentity() );
			
			LogPrint( m_PlayerPrefix + " regained consciousness" );		
		}
	}
	
	void OnPlacementComplete( Man player, TrapBase item ) // TrapBase.c 
	{
		m_Source = PlayerBase.Cast( player ); 
		m_PlayerPrefix = this.GetPlayerPrefix( m_Source ,  m_Source.GetIdentity() );
		m_DisplayName = item.GetDisplayName();		
		
		if ( m_DisplayName != "")
		{
			LogPrint( m_PlayerPrefix + " placed " + m_DisplayName );
		}
		else
		{
			LogPrint( m_PlayerPrefix + " placed " + "unknown trap" );
		}
	}
	
	void Suicide( PlayerBase player )  // EmoteManager.c 
	{
		m_PlayerPrefix = this.GetPlayerPrefix( player ,  player.GetIdentity() );
		
		LogPrint( m_PlayerPrefix + " committed suicide" );
	}
	
	void BleedingOut( PlayerBase player )  // Bleeding.c
	{
		m_PlayerPrefix = this.GetPlayerPrefix( player ,  player.GetIdentity() );
		
		LogPrint( m_PlayerPrefix + " bled out" );
	}
}