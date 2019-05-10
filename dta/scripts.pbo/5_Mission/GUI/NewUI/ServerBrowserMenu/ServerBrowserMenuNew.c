const int MAX_FAVORITES = 50;

#ifdef PLATFORM_CONSOLE
const int SERVER_BROWSER_PAGE_SIZE = 50;
#else
const int SERVER_BROWSER_PAGE_SIZE = 5;
#endif

class DebugClass1
{
	string m_DebugString;
	
	
}

class DebugClass2 : Managed
{
	ref DebugClass1 m_Class1;
}

class ServerBrowserMenuNew extends UIScriptedMenu
{
	protected Widget				m_Play;
	protected Widget				m_Back;
	protected Widget				m_CustomizeCharacter;
	protected TextWidget			m_PlayerName;
	protected TextWidget			m_Version;
	
	protected TabberUI				m_Tabber;
	protected ref ServerBrowserTab	m_OfficialTab;
	protected ref ServerBrowserTab	m_CommunityTab;
	protected ref ServerBrowserTab	m_LANTab;
	
	protected TabType				m_IsRefreshing = TabType.NONE;
	protected ref TStringArray		m_Favorites;
	protected ServerBrowserEntry	m_SelectedServer;
	
	override Widget Init()
	{
#ifdef PLATFORM_CONSOLE
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/server_browser/xbox/server_browser.layout" );
		m_OfficialTab	= new ServerBrowserTabConsole( layoutRoot.FindAnyWidget( "Tab_0" ), this, TabType.OFFICIAL );
#else
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/server_browser/pc/server_browser.layout" );
		m_OfficialTab	= new ServerBrowserTabPc( layoutRoot.FindAnyWidget( "Tab_0" ), this, TabType.OFFICIAL );
		m_CommunityTab	= new ServerBrowserTabPc( layoutRoot.FindAnyWidget( "Tab_1" ), this, TabType.COMMUNITY );
		m_LANTab		= new ServerBrowserTabPc( layoutRoot.FindAnyWidget( "Tab_2" ), this, TabType.LAN );
#endif
			
		layoutRoot.FindAnyWidget( "Tabber" ).GetScript( m_Tabber );
		
		m_Play					= layoutRoot.FindAnyWidget( "play" );
		m_Back					= layoutRoot.FindAnyWidget( "back_button" );
		m_CustomizeCharacter	= layoutRoot.FindAnyWidget( "customize_character" );
		m_PlayerName			= TextWidget.Cast( layoutRoot.FindAnyWidget( "character_name_text" ) );
		m_Version				= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		
#ifndef PLATFORM_CONSOLE
		// TODO: Temporary Hide for 1.0
		layoutRoot.FindAnyWidget( "customize_character" ).Show( false );
		layoutRoot.FindAnyWidget( "character" ).Show( false );
#endif
		
		Refresh();
		
		string version;
		GetGame().GetVersion( version );
		
#ifdef PLATFORM_CONSOLE
		version = "#main_menu_version" + " " + version + " (" + g_Game.GetDatabaseID() + ")";
#else
		version = "#main_menu_version" + " " + version;
#endif
		m_Version.SetText( version );
		
		OnlineServices.m_ServersAsyncInvoker.Insert( OnLoadServersAsync );
		m_Tabber.m_OnTabSwitch.Insert( OnTabSwitch );
				
		m_OfficialTab.RefreshList();
		//m_OfficialTab.LoadFakeData( 100 );
		
#ifdef PLATFORM_PS4
		string confirm = "cross";
		string back = "circle";
		if( GetGame().GetInput().GetEnterButton() == GamepadButton.A )
		{
			confirm = "cross";
			back = "circle";
		}
		else
		{
			confirm = "circle";
			back = "cross";
		}
		ImageWidget toolbar_a = layoutRoot.FindAnyWidget( "ConnectIcon" );
		ImageWidget toolbar_b = layoutRoot.FindAnyWidget( "BackIcon" );
		ImageWidget toolbar_x = layoutRoot.FindAnyWidget( "RefreshIcon" );
		ImageWidget toolbar_y = layoutRoot.FindAnyWidget( "ResetIcon" );
		toolbar_a.LoadImageFile( 0, "set:playstation_buttons image:" + confirm );
		toolbar_b.LoadImageFile( 0, "set:playstation_buttons image:" + back );
		toolbar_x.LoadImageFile( 0, "set:playstation_buttons image:square" );
		toolbar_y.LoadImageFile( 0, "set:playstation_buttons image:triangle" );
#endif
		
#ifdef PLATFORM_CONSOLE
		//Sort init
		TextWidget sort_text = TextWidget.Cast( layoutRoot.FindAnyWidget( "SortText" ) );
		sort_text.SetText( "#str_serverbrowserroot_toolbar_bg_consoletoolbar_sort_sorttext0" );
		LoadFavoriteServers();
#endif
		
		PPEffects.SetBlurMenu( 0.5 );
		return layoutRoot;
	}
	
	void ~ServerBrowserMenuNew()
	{
#ifdef PLATFORM_CONSOLE
		SaveFavoriteServersConsoles();
#endif
		OnlineServices.m_ServersAsyncInvoker.Remove( OnLoadServersAsync );
		m_Tabber.m_OnTabSwitch.Remove( OnTabSwitch );
		PPEffects.SetBlurMenu( 0.0 );
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			if( w == m_Play )
			{
				Play();
				return true;
			}
			else if ( w == m_Back )
			{
				Back();
				return true;
			}
			else if ( w == m_CustomizeCharacter )
			{
				CustomizeCharacter();
				return true;
			}
		}
		return false;
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorNormal( w );
			return true;
		}
		return false;
	}
	
	void SetServersLoadingTab( TabType refreshing )
	{
		m_IsRefreshing = refreshing;
		
		OnlineServices.m_ServersAsyncInvoker.Remove( OnLoadServersAsync );
		OnlineServices.m_ServersAsyncInvoker.Insert( OnLoadServersAsync );
	}

	TabType GetServersLoadingTab()
	{
		return m_IsRefreshing;
	}

	bool IsFavorited( string server_id )
	{
		int index = m_Favorites.Find( server_id );		
		return ( index >= 0 );
	}
	
	void SetFavoriteConsoles( string server_id, bool favorite )
	{
		if( m_Favorites )
		{
			if( favorite && m_Favorites.Find( server_id ) < 0 )
			{
				if( m_Favorites.Count() < MAX_FAVORITES )
				{
					m_Favorites.Insert( server_id );
				}
				else
				{
					m_OfficialTab.Unfavorite( m_Favorites.Get( 0 ) );
					m_Favorites.Remove( 0 );
					m_Favorites.Insert( server_id );
				}
			}
			else if ( m_Favorites.Find( server_id ) >= 0 )
			{
				m_Favorites.RemoveItem( server_id );
				m_OfficialTab.Unfavorite( server_id );
			}
			
			SaveFavoriteServersConsoles();
		}
	}
	
	void Back()
	{
		GetGame().GetUIManager().Back();
	}
	
	void FilterFocus( bool focus )
	{
		#ifdef PLATFORM_CONSOLE
		TextWidget con_text = TextWidget.Cast( layoutRoot.FindAnyWidget( "ConnectText" ) );
		TextWidget ref_text = TextWidget.Cast( layoutRoot.FindAnyWidget( "RefreshText" ) );
		TextWidget res_text = TextWidget.Cast( layoutRoot.FindAnyWidget( "ResetText" ) );
		Widget reset_frame	= layoutRoot.FindAnyWidget( "Reset" );
		
		if( focus )
		{			
			//con_text.SetText( "#str_settings_menu_root_toolbar_bg_consoletoolbar_toggle_toggletext0" );
			con_text.SetText( "#dialog_change" );
			ref_text.SetText( "#server_browser_menu_refresh" );
			res_text.SetText( "#server_browser_menu_reset_filters" );
		
			con_text.Update();
			ref_text.Update();
			res_text.Update();
		}		
		
		#endif
	}
	
	void ServerListFocus( bool focus, bool favorite )
	{
		#ifdef PLATFORM_CONSOLE
		TextWidget con_text = TextWidget.Cast( layoutRoot.FindAnyWidget( "ConnectText" ) );
		TextWidget ref_text = TextWidget.Cast( layoutRoot.FindAnyWidget( "RefreshText" ) );
		TextWidget res_text = TextWidget.Cast( layoutRoot.FindAnyWidget( "ResetText" ) );
		Widget reset_frame	= layoutRoot.FindAnyWidget( "Reset" );
		
		if( focus )
		{			
			con_text.SetText( "#server_browser_menu_connect" );
			
			float x, y;
			res_text.GetSize( x, y );
			if( favorite )
			{
				res_text.SetText( "#server_browser_menu_unfavorite" );
			}
			else
			{
				res_text.SetText( "#server_browser_menu_favorite" );
			}
			con_text.Update();
			res_text.Update();
		}
		#endif
	}
	
	override bool OnFocus( Widget w, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}
		return false;
	}
	
	override bool OnFocusLost( Widget w, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorNormal( w );
			return true;
		}
		return false;
	}
	
	override void Refresh()
	{
		string name;
		
		#ifdef PLATFORM_CONSOLE
			if( GetGame().GetUserManager() && GetGame().GetUserManager().GetSelectedUser() )
			{
				name = GetGame().GetUserManager().GetSelectedUser().GetName();
				if( name.LengthUtf8() > 18 )
				{
					name = name.SubstringUtf8(0, 18);
					name += "...";
				}
			}
		#else
			g_Game.GetPlayerNameShort( 14, name );
		#endif
		
		if( m_PlayerName )
			m_PlayerName.SetText( name );
		
		string version;
		GetGame().GetVersion( version );
		#ifdef PLATFORM_CONSOLE
			version = "#main_menu_version" + " " + version + " (" + g_Game.GetDatabaseID() + ")";
		#else
			version = "#main_menu_version" + " " + version;
		#endif
		m_Version.SetText( version );
	}
	
	override void Update( float timeslice )
	{
		if( !GetGame().GetUIManager().IsDialogVisible() && !GetDayZGame().IsConnecting() )
		{
			if( GetGame().GetInput().LocalPress("UAUITabLeft",false) )
			{
				//m_Tabber.PreviousTab();
				GetSelectedTab().PressSholderLeft();
			}
			
			if( GetGame().GetInput().LocalPress("UAUITabRight",false) )
			{
				//m_Tabber.NextTab();
				GetSelectedTab().PressSholderRight();
			}
			
			if( GetGame().GetInput().LocalPress("UAUISelect",false) )
			{
				GetSelectedTab().PressA();
			}
			
			if( GetGame().GetInput().LocalPress("UAUICtrlX",false) )
			{
				GetSelectedTab().PressX();
			}
			
			if( GetGame().GetInput().LocalPress("UAUICtrlY",false) )
			{
				GetSelectedTab().PressY();
			}
			
			if( GetGame().GetInput().LocalPress("UAUILeft",false) )
			{
				GetSelectedTab().Left();
			}
			
			if( GetGame().GetInput().LocalPress("UAUIRight",false) )
			{
				GetSelectedTab().Right();
			}
			
			if( GetGame().GetInput().LocalPress("UAUIUp",false) )
			{
				GetSelectedTab().Up();
			}
			
			if( GetGame().GetInput().LocalPress("UAUIDown",false) )
			{
				GetSelectedTab().Down();
			}
	
			if( GetGame().GetInput().LocalPress("UAUIBack",false) )
			{
				Back();
			}
		}
		
		super.Update( timeslice );
	}
	
	bool IsFocusable( Widget w )
	{
		if( w )
		{
			return ( w == m_Play || w == m_CustomizeCharacter || w == m_Back );
		}
		return false;
	}
	
	void LoadFavoriteServers()
	{
		m_Favorites = new TStringArray;
		GetGame().GetProfileStringList( "SB_Favorites", m_Favorites );
	}
	
	void SaveFavoriteServersConsoles()
	{
		if ( m_Favorites )
		{
			GetGame().SetProfileStringList( "SB_Favorites", m_Favorites );
			GetGame().SaveProfile();
		}
	}
	
	void SelectServer( ServerBrowserEntry server )
	{
		if( m_SelectedServer )
		{
			m_SelectedServer.Deselect();
		}
		
		m_SelectedServer = server;
	}
	
	void Connect( ServerBrowserEntry server )
	{
		SelectServer( server );
#ifdef PLATFORM_CONSOLE
		SaveFavoriteServersConsoles();
#endif
		Play();
		
		//server.
	}
	
	void Play()
	{
		if( m_SelectedServer )
		{
			string ip = m_SelectedServer.GetIP();
			int port = m_SelectedServer.GetPort();
			
			#ifdef PLATFORM_WINDOWS			
				// Hack - In new Serverborwser on PC has bad IP adress but ID is OK
				array<string> ip_port = new array<string>();
				m_SelectedServer.GetServerID().Split( ":", ip_port);
				ip = ip_port[0];
				port = ip_port[1].ToInt();
			#endif
			
			//g_Game.ConnectFromServerBrowser( m_SelectedServer.GetIP(), m_SelectedServer.GetPort(), "" );
			g_Game.ConnectFromServerBrowser( ip, port, "" );
		}
	}
	
	void CustomizeCharacter()
	{
		PPEffects.SetBlurMenu( 0.0 );
		EnterScriptedMenu(MENU_CHARACTER);
	}
	
	void NextCharacter()
	{
		
	}
	
	void PreviousCharacter()
	{
		
	}
	
	ServerBrowserTab GetSelectedTab()
	{
		switch( m_Tabber.GetSelectedIndex() )
		{
			case 0:
			{
				return m_OfficialTab;
			}
			case 1:
			{
				return m_CommunityTab;
			}
			case 2:
			{
				return m_LANTab;
			}
		}
		return null;
	}
	
	void OnTabSwitch()
	{
		SetServersLoadingTab( TabType.NONE );
		
		if( GetSelectedTab().IsNotInitialized() )
		{
			GetSelectedTab().RefreshList();
		}
		
		GetSelectedTab().Focus();
	}
	
	void OnLoadServersAsync( ref GetServersResult result_list, EBiosError error, string response )
	{
		#ifdef PLATFORM_WINDOWS
			#ifdef PLATFORM_CONSOLE
				GetSelectedTab().OnLoadServersAsyncConsole( result_list, error, response );
			#else
				GetSelectedTab().OnLoadServersAsyncPC( result_list, error, response );
			#endif
		#else
			GetSelectedTab().OnLoadServersAsyncConsole( result_list, error, response );
		#endif
	}
	
	/*
	//Coloring functions (Until WidgetStyles are useful)
	void ColorHighlight( Widget w, int x, int y )
	{
		SetFocus( w );
		
		ButtonWidget button = ButtonWidget.Cast( w );
		if( button )
		{
			button.SetTextColor( ColorManager.COLOR_HIGHLIGHT_TEXT );
		}
		
		TextWidget text		= TextWidget.Cast(w.FindWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindWidget( w.GetName() + "_text_1" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindWidget( w.GetName() + "_image" ) );
		
		if( text )
		{
			text.SetColor( ColorManager.COLOR_HIGHLIGHT_TEXT );
		}
		
		if( text2 )
		{
			text2.SetColor( ColorManager.COLOR_HIGHLIGHT_TEXT );
		}
		
		if( image )
		{
			image.SetColor( ColorManager.COLOR_HIGHLIGHT_TEXT );
		}
	}
	
	void ColorNormal( Widget w, Widget enterW, int x, int y )
	{
		#ifdef PLATFORM_WINDOWS
		SetFocus( null );
		#endif
		
		ButtonWidget button = ButtonWidget.Cast( w );
		if( button )
		{
			button.SetTextColor( ColorManager.COLOR_NORMAL_TEXT );
		}
		
		TextWidget text		= TextWidget.Cast(w.FindWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindWidget( w.GetName() + "_text_1" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindWidget( w.GetName() + "_image" ) );
		
		if( text )
		{
			text.SetColor( ColorManager.COLOR_NORMAL_TEXT );
		}
		
		if( text2 )
		{
			text2.SetColor( ColorManager.COLOR_NORMAL_TEXT );
		}
		
		if( image )
		{
			image.SetColor( ColorManager.COLOR_NORMAL_TEXT );
		}
	}
	*/
	
	//Coloring functions (Until WidgetStyles are useful)
	void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		//SetFocus( w );
		
		int color_pnl = ARGB(255, 0, 0, 0);
		int color_lbl = ARGB(255, 255, 0, 0);
		
		#ifdef PLATFORM_CONSOLE
			color_pnl = ARGB(255, 200, 0, 0);
			color_lbl = ARGB(255, 255, 255, 255);
		#endif
		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}
	
	void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = ARGB(0, 0, 0, 0);
		int color_lbl = ARGB(255, 255, 255, 255);
		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}
	
	void ButtonSetText( Widget w, string text )
	{
		if( !w )
			return;
				
		TextWidget label = TextWidget.Cast(w.FindWidget( w.GetName() + "_label" ) );
		
		if( label )
		{
			label.SetText( text );
		}
		
	}
	
	void ButtonSetColor( Widget w, int color )
	{
		if( !w )
			return;
		
		Widget panel = w.FindWidget( w.GetName() + "_panel" );
		
		if( panel )
		{
			panel.SetColor( color );
		}
	}
	
	void ButtonSetTextColor( Widget w, int color )
	{
		if( !w )
			return;

		TextWidget label	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		TextWidget text		= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
				
		if( label )
		{
			label.SetColor( color );
		}
		
		if( text )
		{
			text.SetColor( color );
		}
		
		if( text2 )
		{
			text2.SetColor( color );
		}
	}
}