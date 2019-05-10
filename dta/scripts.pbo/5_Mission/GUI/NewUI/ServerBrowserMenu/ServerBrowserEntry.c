class ServerBrowserEntry extends ScriptedWidgetEventHandler
{
	protected Widget					m_Root;
	protected Widget					m_Favorite;
	protected Widget					m_Expand;
	
	//Basic info
	protected TextWidget				m_ServerName;
	protected TextWidget				m_ServerPopulation;
	protected TextWidget				m_ServerSlots;
	protected TextWidget				m_ServerPing;
	protected ImageWidget				m_ServerTime;
	protected ImageWidget				m_ServerLock;
	
	//Detailed info
	protected TextWidget				m_ServerShard;
	protected TextWidget				m_ServerCharacterAlive;
	protected TextWidget				m_ServerFriends;
	protected TextWidget				m_ServerMode;
	protected TextWidget				m_ServerBattleye;
	protected TextWidget				m_ServerIP;
	protected TextWidget				m_ServerAcceleration;
	
	protected bool						m_IsExpanded;
	protected bool						m_IsFavorited;
	
	protected ref GetServersResultRow	m_ServerData;
	protected int						m_Index;
	protected ServerBrowserTab			m_Tab;
	protected bool						m_Selected;
	
	void ServerBrowserEntry( Widget parent, int index, ServerBrowserTab tab )
	{
		m_Index++;
		
		#ifdef PLATFORM_CONSOLE
			m_Root				= GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/server_browser/xbox/server_browser_list_entry.layout", parent );
		#else
			m_Root				= GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/server_browser/pc/server_browser_list_entry_pages.layout", parent );
		#endif
		//m_Root.SetSort( index );
		m_Root.Enable( true );
		m_Favorite				= m_Root.FindAnyWidget( "favorite_button" );
		m_Expand				= m_Root.FindAnyWidget( "expand_button" );
		m_ServerName			= TextWidget.Cast( m_Root.FindAnyWidget( "server_name" ) );
		m_ServerPopulation		= TextWidget.Cast( m_Root.FindAnyWidget( "server_population" ) );
		m_ServerSlots			= TextWidget.Cast( m_Root.FindAnyWidget( "server_slots" ) );
		m_ServerPing			= TextWidget.Cast( m_Root.FindAnyWidget( "server_ping" ) );
		m_ServerTime			= ImageWidget.Cast( m_Root.FindAnyWidget( "server_time" ) );
		m_ServerLock			= ImageWidget.Cast( m_Root.FindAnyWidget( "lock_icon" ) );
		
		m_ServerShard			= TextWidget.Cast( m_Root.FindAnyWidget( "shard_text" ) );
		m_ServerCharacterAlive	= TextWidget.Cast( m_Root.FindAnyWidget( "character_alive_text" ) );
		m_ServerFriends			= TextWidget.Cast( m_Root.FindAnyWidget( "steam_friends_text" ) );
		m_ServerMode			= TextWidget.Cast( m_Root.FindAnyWidget( "mode_text" ) );
		m_ServerBattleye		= TextWidget.Cast( m_Root.FindAnyWidget( "battlleye_text" ) );
		m_ServerIP				= TextWidget.Cast( m_Root.FindAnyWidget( "ip_text" ) );
		m_ServerAcceleration	= TextWidget.Cast( m_Root.FindAnyWidget( "server_acceleration_text" ) );
		
		m_Root.FindAnyWidget( "basic_info" ).Show( true );
		
		m_Root.FindAnyWidget( "favorite_image" ).Update();
		m_Root.FindAnyWidget( "unfavorite_image" ).Update();
		
		m_Index					= index;
		m_Tab					= tab;
		
		m_ServerTime.LoadImageFile( 0, "set:dayz_gui image:icon_sun" );
		m_ServerTime.LoadImageFile( 1, "set:dayz_gui image:icon_sun_accel" );
		m_ServerTime.LoadImageFile( 2, "set:dayz_gui image:icon_moon" );
		m_ServerTime.LoadImageFile( 3, "set:dayz_gui image:icon_moon_accel" );
		
		UpdateColors();
		m_Root.SetHandler( this );
	}
	
	void ~ServerBrowserEntry()
	{
		delete m_Root;
	}
	
	Widget GetRoot()
	{
		return m_Root;
	}
	
	void Show(bool show)
	{
		m_Root.Show( show );
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		#ifdef PLATFORM_CONSOLE
		if( w == m_Root	)
		{
			m_Tab.Connect( this );
			return true;
		}
		#endif
		return false;
	}
	
	override bool OnDoubleClick( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			if( w == m_Root )
			{
				m_Tab.Connect( this );
				return true;
			}
		}
		return false;
	}
	
	override bool OnMouseButtonUp( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			if( w == m_Favorite )
			{
				ToggleFavorite();
				return true;
			}
			else if ( w == m_Expand )
			{
				ToggleExpand();
				return true;
			}
			else if( w == m_Root )
			{
				Darken(w, x, y);
				Select();
				SetFocus( m_Root );
				return true;
			}
		}
		return false;
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			Preview( w, x, y );
			
			return true;
		}
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			Lighten( w, enterW, x, y );
			return true;
		}
		return false;
	}
	
	void Focus()
	{
		SetFocus( m_Root );
	}
	
	void ServerListFocus( bool focus )
	{
		m_Tab.ServerListFocus( focus, m_IsFavorited );
	}
	
	override bool OnFocus( Widget w, int x, int y )
	{
		if( !m_Selected )
		{
			if( IsFocusable( w ) )
			{
				Darken( w, x, y );
			}
			#ifdef PLATFORM_CONSOLE
			if( w == m_Root )
			{
				Select();
				ServerListFocus( true );
			}
			#endif
			return true;
		}
		return false;
	}
	
	override bool OnFocusLost( Widget w, int x, int y )
	{
		#ifdef PLATFORM_CONSOLE
		if( w == m_Root )
		{
			Deselect();
			ServerListFocus( false );
		}
		#endif
		
		if( IsFocusable( w ) )
		{
			Lighten( w, null, x, y );
		}
		
		return true;
		return false;
	}
	
	bool IsFocusable( Widget w )
	{
		if( w )
		{
			return ( w == m_Root || w == m_Favorite || w == m_Expand );
		}
		return false;
	}
	
	void FillInfo( GetServersResultRow server_info )
	{
		m_ServerData = server_info;
		
		//Print( server_info.m_Priority );
		
#ifndef PLATFORM_CONSOLE
		m_Root.FindAnyWidget( "detailed_info" ).Show( server_info.m_IsExpanded );
#endif
		
		SetName( server_info.m_Name );
		SetPasswordLocked( server_info.m_IsPasswordProtected );
		SetPopulation( server_info.m_CurrentNumberPlayers, server_info.m_MaxPlayers );
		SetSlots( server_info.m_MaxPlayers );
		SetPing( server_info.m_Ping );
		SetTime( server_info.m_TimeOfDay, server_info.m_EnvironmentTimeMul );
		SetFavorite( server_info.m_Favorite );
		
#ifdef PLATFORM_WINDOWS
#ifndef PLATFORM_CONSOLE
		SetExpand( server_info.m_IsExpanded );
		SetShard( server_info.m_ShardId.ToInt() );
		SetCharacterAlive( server_info.m_CharactersAlive );
		SetFriends( server_info.m_SteamFriends );
		SetMode( server_info.m_Disable3rdPerson );
		SetBattleye( server_info.m_AntiCheat );
		SetIP( server_info.m_Id );
		SetAcceleration( server_info.m_EnvironmentTimeMul );
#endif
#endif
	}
	
	void SetName( string name )
	{
		m_ServerName.SetText( name );
	}
	
	void SetPasswordLocked( bool locked )
	{
		m_ServerLock.Show( locked );
	}
	
	void SetPopulation( int population, int slots )
	{
		string pop_text	= "#server_browser_entry_empty";
		
		if ( slots > 0 )
		{
			float pop_percentage = population / slots;
			if( population == 0 )
				pop_text	= "#server_browser_entry_empty";
			else if( pop_percentage < 0.33 )
				pop_text	= "#server_browser_entry_low";
			else if( pop_percentage < 0.66 )
				pop_text	= "#server_browser_entry_medium";
			else if( pop_percentage != 1 )
				pop_text	= "#server_browser_entry_high";
			else
				pop_text	= "#server_browser_entry_full";
		}

		m_ServerPopulation.SetText( pop_text );
	}
	
	void SetSlots( int slots )
	{
		m_ServerSlots.SetText( slots.ToString() );
	}
	
	void SetPing( int ping )
	{
		int color;
		if( ping < 50 )
			color	= ARGBF( 1, 0, 1, 0 );
		else if( ping < 100 )
			color	= ARGBF( 1, 0.8, 0.8, 0 );
		else if( ping < 200 )
			color	= ARGBF( 1, 1, 0.5, 0 );
		else
			color	= ARGBF( 1, 1, 0, 0 );
		
		m_ServerPing.SetColor( color );
		m_ServerPing.SetText( ping.ToString() );
	}
	
	void SetTime( string time, float multiplier )
	{
		if( time != "" )
		{
			TStringArray arr	= new TStringArray;
			
			time.Split( ":", arr );
			
			if( arr.Count() == 2 )
			{
				int hour		= arr.Get( 0 ).ToInt();
				int minute		= arr.Get( 1 ).ToInt();
				
				if( hour >= 19 || hour <= 5 )	//Night
				{
					if( multiplier > 1 )
						m_ServerTime.SetImage( 3 );
					else
						m_ServerTime.SetImage( 2 );
				}
				else							//Day
				{
					if( multiplier > 1 )
						m_ServerTime.SetImage( 1 );
					else
						m_ServerTime.SetImage( 0 );
				}
			}
		}
	}
	
	void SetShard( int shard )
	{
		string text;
		switch( shard )
		{
			case 0:
			{
				text = "#server_browser_entry_private";
				break;
			}
			case 1:
			{
				text = "#server_browser_entry_official";
				break;
			}
		}
		m_ServerShard.SetText( text );
	}
	
	void SetCharacterAlive( string char_alive )
	{
		m_ServerCharacterAlive.SetText( char_alive );
	}
	
	void SetFriends( string friends_text )
	{
		m_ServerFriends.SetText( friends_text );
	}
	
	void SetMode( int mode )
	{
		string text;
		switch( mode )
		{
			case 0:
			{
				text = "#server_browser_entry_person_both";
				break;
			}
			case 1:
			{
				text = "#server_browser_entry_person_first";
				break;
			}
		}
		m_ServerMode.SetText( text );
	}
	
	void SetBattleye( bool battleye )
	{
		if( battleye )
		{
			m_ServerBattleye.SetText( "#server_browser_entry_enabled" );
			m_ServerBattleye.SetColor( ARGBF( 1, 0, 1, 0 ) );
		}
		else
		{
			m_ServerBattleye.SetText( "#server_browser_entry_disabled" );
			m_ServerBattleye.SetColor( ARGBF( 1, 1, 0, 0 ) );
		}
	}
	
	void SetIP( string ip )
	{
		m_ServerIP.SetText( ip );
	}
	
	string GetIP()
	{
		return m_ServerData.m_HostIp;
	}
	
	int GetPort()
	{
		return m_ServerData.m_HostPort;
	}
	
	string GetServerID()
	{
		return m_ServerData.m_Id;
	}
	
	void SetFavorite( bool favorite )
	{
		m_IsFavorited = favorite;
		m_Root.FindAnyWidget( "favorite_image" ).Show( favorite );
		m_Root.FindAnyWidget( "unfavorite_image" ).Show( !favorite );		
	}
	
	void SetAcceleration( float mult )
	{
		if( mult > 1 )
		{
			m_ServerAcceleration.Show( true );
			m_ServerAcceleration.SetText( mult.ToString() + "x" );
		}
		else
		{
			m_ServerAcceleration.Show( false );
		}
	}
	
	bool ToggleFavorite()
	{
		m_IsFavorited = !m_IsFavorited;
		
#ifdef PLATFORM_CONSOLE
		//Save Data Console
		m_Tab.GetRootMenu().SetFavoriteConsoles(m_ServerData.m_Id, m_IsFavorited);
#else
		//Save Data PC
		GetServersResultRow data = m_ServerData;
		TStringArray server_id = new TStringArray;
		data.m_Id.Split(":", server_id);
		OnlineServices.SetServerFavorited(server_id[0], data.m_HostPort, data.m_SteamQueryPort, m_IsFavorited);
#endif	
		
		m_Root.FindAnyWidget( "unfavorite_image" ).Show( !m_IsFavorited );
		m_Root.FindAnyWidget( "favorite_image" ).Show( m_IsFavorited );
		
		return m_IsFavorited;
	}
	
	bool ToggleExpand()
	{
		return SetExpand(!m_IsExpanded);
	}
	
	bool SetExpand(bool expand)
	{
		m_IsExpanded = expand;
		m_Root.FindAnyWidget( "collapse_image" ).Show( m_IsExpanded );
		m_Root.FindAnyWidget( "expand_image" ).Show( !m_IsExpanded );
		m_Root.FindAnyWidget( "detailed_info" ).Show( m_IsExpanded );
		
		if ( m_ServerData )
		{
			m_ServerData.m_IsExpanded = m_IsExpanded;
		}
		
		return m_IsExpanded;
	}
	
	void Select( bool notify = true )
	{
		if( !m_Selected )
		{
			if( notify )
			{
				m_Tab.SelectServer( this );
			}
			
			m_ServerData.m_IsSelected = true;
			
			m_Selected = true;
			#ifdef PLATFROM_XBOX
				m_Root.SetColor( ARGB( 1, 50, 50, 50 ) );
			#endif
		}
	}
	
	void Deselect()
	{
		if( m_Selected )
		{
			m_ServerData.m_IsSelected = false;
			
			m_Selected = false;
			float alpha = 0.1;
			if( m_Index % 2 )
			{
				alpha = 0.3;
			}
			m_Root.SetColor( ARGB( alpha, 50, 50, 50 ) );
			
			Lighten( m_Root, null, 0, 0 );
		}
	}
	
	void UpdateColors()
	{
		float alpha = 0.15;
		if( m_Index % 2 )
		{
			alpha = 0;
		}
		
		m_Root.SetAlpha( alpha );
	}
	
	//Coloring functions (Until WidgetStyles are useful)
	void Darken( Widget w, int x, int y )
	{
		if( m_Selected )
			return;
		
		Print("w: "+ w.GetName());
		
		if( w == m_Root || w == m_Favorite || w == m_Expand )
		{
			m_Root.SetColor( ARGB( 255, 200, 0, 0) );
			m_Root.SetAlpha( 1 );
			m_ServerName.SetColor( ARGB( 255, 255, 255, 255 ) );
		}
	}
	
	//Coloring functions (Until WidgetStyles are useful)
	void Preview( Widget w, int x, int y )
	{		
		if( m_Selected )
			return;
		
		if( w == m_Root || w == m_Favorite || w == m_Expand )
		{
			m_Root.SetColor( ARGB( 255, 0, 0, 0) );
			m_Root.SetAlpha( 1 );
			m_ServerName.SetColor( ARGB( 255, 255, 0, 0 ) );
		}
	}
	
	void Lighten( Widget w, Widget enterW, int x, int y )
	{
		if( GetFocus() == w || m_Selected )
		{
			return;
		}
		
		if( w == m_Root && ( ( m_Favorite && enterW == m_Favorite ) || ( m_Expand && enterW == m_Expand ) ) )
		{
			return;
		}
		
		m_Root.SetColor( ARGB( 255, 0, 0, 0) );
		m_ServerName.SetColor( ARGB( 255, 255, 255, 255 ) );
		UpdateColors();
	}
}
