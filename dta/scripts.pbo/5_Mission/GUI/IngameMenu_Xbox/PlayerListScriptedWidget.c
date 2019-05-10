class PlayerListScriptedWidget extends ScriptedWidgetEventHandler
{
	protected Widget												m_Root;
	//protected TextWidget											m_Header;
	protected ScrollWidget											m_ScrollContainer;
	protected Widget												m_Content;
	protected ref map<string, ref PlayerListEntryScriptedWidget>	m_Entries;
	
	protected int													m_TotalEntries;
	protected PlayerListEntryScriptedWidget							m_SelectedEntry;
	
	void PlayerListScriptedWidget( Widget parent, string header_text )
	{
		m_Root				= GetGame().GetWorkspace().CreateWidgets( "gui/layouts/xbox/ingamemenu_xbox/players_info_panel.layout", parent );
		//m_Header			= TextWidget.Cast( m_Root.FindAnyWidget( "header_text" ) );
		m_ScrollContainer	= ScrollWidget.Cast( m_Root.FindAnyWidget( "ScrollFrame" ) );
		m_Content			= m_Root.FindAnyWidget( "Content" );
		
		m_Entries			= new map<string, ref PlayerListEntryScriptedWidget>;
		
		//m_Header.SetText( header_text );
		OnlineServices.m_ServersAsyncInvoker.Insert( OnLoadServersAsync );
		m_ScrollContainer.VScrollToPos01( 0 );
	}
	
	void ~PlayerListScriptedWidget()
	{
		OnlineServices.m_ServersAsyncInvoker.Remove( OnLoadServersAsync );
		delete m_Root;
	}
	
	void FocusFirst()
	{
		if( m_Content && m_Content.GetChildren() )
			SetFocus( m_Content.GetChildren().FindAnyWidget( "Button" ) );
		m_ScrollContainer.VScrollToPos01( 0 );
	}
	
	void Reload( SyncPlayerList player_list )
	{
		if( player_list && player_list.m_PlayerList && m_Entries )
		{
			foreach( string UID, ref PlayerListEntryScriptedWidget widget : m_Entries )
			{
				SyncPlayer player_found;
				foreach( SyncPlayer player : player_list.m_PlayerList )
				{
					if( player && player.m_UID == UID )
					{
						player_found = player;
						break;
					}
				}
				if( !player_found )
				{
					RemovePlayer( UID );
				}
			}
			
			for( int i = 0; i < player_list.m_PlayerList.Count(); i++ )
			{
				SyncPlayer player2 = player_list.m_PlayerList.Get( i );
				PlayerListEntryScriptedWidget player_widget;
				m_Entries.Find( player2.m_UID, player_widget );
				if( !player_widget )
				{
					AddPlayer( player2.m_PlayerName, player2.m_UID, true );
				}
			}
		}
	}
	
	bool IsEmpty()
	{
		return ( m_Entries.Count() == 0 );
	}
	
	void OnLoadServersAsync( ref GetServersResult result_list, EBiosError error, string response )
	{
		string header_text = "Server";
		GetServersResultRow info = OnlineServices.GetCurrentServerInfo();
		if( info )
		{
			header_text = info.m_Name + " - " + info.m_HostIp + ":" + info.m_HostPort;
		}
		//m_Header.SetText( header_text );
	}
	
	void Reload( BiosFriendInfoArray player_list )
	{
		if( player_list && m_Entries )
		{
			foreach( string UID, ref PlayerListEntryScriptedWidget widget : m_Entries )
			{
				BiosFriendInfo player_found;
				foreach( BiosFriendInfo player : player_list )
				{
					if( player && player.m_Uid == UID )
					{
						player_found = player;
						break;
					}
				}
				if( !player_found )
				{
					RemovePlayer( UID );
				}
			}
			
			for( int i = 0; i < player_list.Count(); i++ )
			{
				BiosFriendInfo player2 = player_list.Get( i );
				PlayerListEntryScriptedWidget player_widget;
				m_Entries.Find( player2.m_Uid, player_widget );
				if( !player_widget )
				{
					AddPlayer( player2.m_DisplayName, player2.m_Uid, false );
				}
			}
		}
	}
	
	void Reload( BiosPrivacyUidResultArray player_list )
	{
		foreach( BiosPrivacyUidResult result : player_list )
		{
			PlayerListEntryScriptedWidget player_widget;
			m_Entries.Find( result.m_Uid, player_widget );
			if( player_widget )
			{
				player_widget.LoadPermissions( result.m_Results );
			}
		}
	}
	
	void ReloadLocal( map<string, bool> player_list )
	{
		if( player_list )
		{
			for( int i = 0; i < player_list.Count(); i++ )
			{
				string uid = player_list.GetKey( i );
				bool muted = OnlineServices.IsPlayerMuted( uid );
				PlayerListEntryScriptedWidget player_widget;
				m_Entries.Find( uid, player_widget );
				if( player_widget )
				{
					player_widget.MutePlayer( muted );
				}
			}
		}
	}
	
	PlayerListEntryScriptedWidget FindEntryByWidget( Widget button )
	{
		if( button && m_Entries )
		{
			foreach( string UID, ref PlayerListEntryScriptedWidget widget : m_Entries )
			{
				if( widget && widget.GetButtonWidget() == button )
				{
					return widget;
				}
			}
		}
		
		return null;
	}
	
	string FindPlayerByWidget( Widget button )
	{
		if( button && m_Entries )
		{
			foreach( string UID, ref PlayerListEntryScriptedWidget widget : m_Entries )
			{
				if( widget && widget.GetButtonWidget() == button )
				{
					return UID;
				}
			}
		}
		
		return "";
	}
	
	void AddPlayer( string name, string UID, bool show_permissions )
	{
		if( m_Entries )
		{
			m_Entries.Insert( UID, new PlayerListEntryScriptedWidget( m_Content, name, UID, show_permissions, this ) );
			m_TotalEntries++;
		}
	}
	
	void RemovePlayer( string UID )
	{
		if( m_Entries )
		{
			PlayerListEntryScriptedWidget next_entry;
			
			if( m_Entries.Get( UID ) == m_SelectedEntry )
			{
				for( int i = 0; i < m_Entries.Count() - 1; i++ )
				{
					if( m_Entries.GetElement( i ) == m_Entries.Get( UID ) )
					{
						next_entry = m_Entries.GetElement( i + 1 );
					}
				}
			}
			
			m_Entries.Remove( UID );
			m_TotalEntries--;
			SelectPlayer( next_entry );
			m_Content.Update();
		}
	}
	
	bool IsGloballyMuted( string UID )
	{
		if( m_Entries && m_Entries.Get( UID ) )
		{
			return m_Entries.Get( UID ).IsGloballyMuted();
		}
		return false;
	}
	
	void MutePlayer( string UID, bool mute )
	{
		if( m_Entries )
		{
			m_Entries.Get( UID ).MutePlayer( mute );
		}
	}
	
	void SelectPlayer( PlayerListEntryScriptedWidget entry )
	{
		m_SelectedEntry = entry;
		ScrollToEntry( entry );
	}
	
	void ScrollToEntry( PlayerListEntryScriptedWidget entry )
	{
		if( entry )
		{
			float x, y;
			float x_s, y_s;
			float x_l, y_l;
			
			Widget root			= entry.GetButtonWidget().GetParent();
			Widget first_child	= root.GetParent().GetChildren();
			Widget last_child	= first_child;
			while( last_child )
			{
				if( last_child.GetSibling() )
					last_child = last_child.GetSibling();
				else
					break;
			}
			
			root.GetParent().Update();
			root.Update();
			
			m_ScrollContainer.GetScreenPos( x, y );
			m_ScrollContainer.GetScreenSize( x_s, y_s );
			
			float bottom_pos = y + y_s;
			
			root.GetScreenPos( x_l, y_l );
			root.GetScreenSize( x_s, y_s );
			
			if( root == first_child )
			{
				m_ScrollContainer.VScrollToPos01( 0 );
			}
			else if( root == last_child )
			{
				m_ScrollContainer.VScrollToPos01( 1 );
			}
			else if( y_l + y_s >= bottom_pos )
			{
				m_ScrollContainer.VScrollToPos( m_ScrollContainer.GetVScrollPos() + y_s );
			}
			else if( y_l <= y )
			{
				m_ScrollContainer.VScrollToPos( m_ScrollContainer.GetVScrollPos() - y_s );
			}
		}
	}
}