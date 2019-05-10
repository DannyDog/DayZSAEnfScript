class MainMenu extends UIScriptedMenu
{
	protected ref MainMenuNewsfeed	m_Newsfeed;
	protected ref MainMenuStats		m_Stats;
	protected ref MainMenuVideo		m_Video;
	
	protected MissionMainMenu		m_Mission;
	protected DayZIntroScenePC 		m_ScenePC;
	
	protected TextWidget			m_PlayerName;
	protected TextWidget			m_Version;
	
	protected Widget				m_CharacterRotationFrame;
	
	protected Widget				m_Play;
	protected Widget		 		m_ChooseServer;
	protected Widget				m_CustomizeCharacter;
	protected Widget				m_PlayVideo;
	protected Widget				m_Tutorials;
	protected Widget				m_StatButton;
	protected Widget				m_MessageButton;
	protected Widget				m_SettingsButton;
	protected Widget				m_Exit;
	protected Widget				m_NewsFeedOpen;
	protected Widget				m_NewsFeedClose;
	protected Widget				m_CharacterStatsOpen;
	protected Widget				m_CharacterStatsClose;
	protected Widget				m_NewsMain;
	protected Widget				m_NewsSec1;
	protected Widget				m_NewsSec2;
	protected Widget				m_PrevCharacter;
	protected Widget				m_NextCharacter;
	
	protected Widget				m_LastPlayedTooltip;
	protected Widget				m_LastPlayedTooltipLabel;
	protected TextWidget			m_LastPlayedTooltipIP;
	protected TextWidget			m_LastPlayedTooltipPort;
	
	protected ref WidgetFadeTimer	m_LastPlayedTooltipTimer;
	protected ref Widget			m_LastFocusedButton;

	protected ref ModsMenuSimple	m_ModsSimple;
	protected ref ModsMenuDetailed	m_ModsDetailed;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/main_menu.layout" );
		
		m_Play						= layoutRoot.FindAnyWidget( "play" );
		m_ChooseServer				= layoutRoot.FindAnyWidget( "choose_server" );
		m_CustomizeCharacter		= layoutRoot.FindAnyWidget( "customize_character" );
		m_PlayVideo					= layoutRoot.FindAnyWidget( "play_video" );
		m_Tutorials					= layoutRoot.FindAnyWidget( "tutorials" );
		m_StatButton				= layoutRoot.FindAnyWidget( "stat_button" );
		m_MessageButton				= layoutRoot.FindAnyWidget( "message_button" );
		m_SettingsButton			= layoutRoot.FindAnyWidget( "settings_button" );
		m_Exit						= layoutRoot.FindAnyWidget( "exit_button" );
		m_NewsFeedOpen				= layoutRoot.FindAnyWidget( "news_feed_open" );
		m_NewsFeedClose				= layoutRoot.FindAnyWidget( "news_feed_close" );
		m_CharacterStatsOpen		= layoutRoot.FindAnyWidget( "character_stats_open" );
		m_CharacterStatsClose		= layoutRoot.FindAnyWidget( "character_stats_close" );
		m_PrevCharacter				= layoutRoot.FindAnyWidget( "prev_character" );
		m_NextCharacter				= layoutRoot.FindAnyWidget( "next_character" );

		m_Version					= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		m_CharacterRotationFrame	= layoutRoot.FindAnyWidget( "character_rotation_frame" );
		
		m_LastPlayedTooltip			= layoutRoot.FindAnyWidget( "last_server_info" );
		m_LastPlayedTooltip.Show(false);
		m_LastPlayedTooltipLabel	= m_LastPlayedTooltip.FindAnyWidget( "last_server_info_label" );
		m_LastPlayedTooltipIP		= TextWidget.Cast( m_LastPlayedTooltip.FindAnyWidget( "last_server_info_ip" ) );
		m_LastPlayedTooltipPort		= TextWidget.Cast( m_LastPlayedTooltip.FindAnyWidget( "last_server_info_port" ) );
		
		m_LastPlayedTooltipTimer	= new WidgetFadeTimer();
		
		m_Newsfeed					= new MainMenuNewsfeed( layoutRoot.FindAnyWidget( "news_feed_root" ) );
		m_Stats						= new MainMenuStats( layoutRoot.FindAnyWidget( "character_stats_root" ) );
		
		m_Mission					= MissionMainMenu.Cast( GetGame().GetMission() );
		
		m_LastFocusedButton = 		m_Play;

		m_ScenePC					= m_Mission.GetIntroScenePC();
		
		if( m_ScenePC )
		{
			m_ScenePC.ResetIntroCamera();
		}
		
		m_PlayVideo.Show( false );
		
		m_PlayerName				= TextWidget.Cast( layoutRoot.FindAnyWidget("character_name_text") );
		
		// Set Version
		string version;
		GetGame().GetVersion( version );
		m_Version.SetText( "#main_menu_version" + " " + version );
		
		GetGame().GetUIManager().ScreenFadeOut(0);

		SetFocus( null );
		
		Refresh();
		
		LoadMods();
		
		GetDayZGame().GetBacklit().MainMenu_OnShow();
	
		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );				
		
		return layoutRoot;
	}
	
	void ~MainMenu()
	{
		
	}
	
	void LoadMods()
	{
		ref array<ref ModInfo> modArray = new array<ref ModInfo>;
		
		GetGame().GetModInfos( modArray );
		
		//m_ModsSimple = new ModsMenuSimple(modArray, layoutRoot.FindAnyWidget("ModsSimple"));
		//m_ModsDetailed = new ModsMenuDetailed(modArray, layoutRoot.FindAnyWidget("ModsDetailed"));
	}
	
	override bool OnMouseButtonDown( Widget w, int x, int y, int button )
	{
		if ( w == m_CharacterRotationFrame )
		{
			if (m_ScenePC)
				m_ScenePC.CharacterRotationStart();
			return true;
		}
		else if ( w == m_Play )
		{
			m_LastFocusedButton = m_Play;
			Play();
			return true;
		}
		else if ( w == m_ChooseServer )
		{
			m_LastFocusedButton = m_ChooseServer;
			OpenMenuServerBrowser();
			return true;
		}
		
		return false;
	}
	
	override bool OnMouseButtonUp( Widget w, int x, int y, int button )
	{
		if (m_ScenePC)
			m_ScenePC.CharacterRotationStop();
		return false;
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			if( w == m_Play )
			{
				m_LastFocusedButton = m_Play;
				Play();
				return true;
			}
			else if ( w == m_ChooseServer )
			{
				m_LastFocusedButton = m_ChooseServer;
				OpenMenuServerBrowser();
				return true;
			}
			else if ( w == m_CustomizeCharacter )
			{
				OpenMenuCustomizeCharacter();
				return true;
			}
			else if ( w == m_StatButton )
			{
				OpenStats();
				return true;
			}
			else if ( w == m_MessageButton )
			{
				OpenCredits();
				return true;
			}
			else if ( w == m_SettingsButton )
			{
				OpenSettings();
				return true;
			}
			else if ( w == m_Exit )
			{
				Exit();
				return true;
			}
			else if ( w == m_PrevCharacter )
			{
				PreviousCharacter();
				return true;
			}
			else if ( w == m_NextCharacter )
			{
				NextCharacter();
				return true;
			}
			else if ( w == m_NewsFeedOpen )
			{
				ShowNewsfeed();
				return true;
			}
			else if ( w == m_NewsFeedClose )
			{
				HideNewsfeed();
				return true;
			}
			else if ( w == m_CharacterStatsOpen )
			{
				ShowStats();
				return true;
			}
			else if ( w == m_CharacterStatsClose )
			{
				HideStats();
				return true;
			}
			else if ( w == m_PlayVideo )
			{
				m_LastFocusedButton = m_PlayVideo;
				PlayVideo();
				return true;
			}
			else if ( w == m_Tutorials )
			{
				m_LastFocusedButton = m_Tutorials;
				OpenTutorials();
				return true;
			}
		}
		return false;
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( w == m_Play )
		{
			string ip = "";
			int port = 0;
			 
			if(m_ScenePC && !m_ScenePC.GetIntroCharacter().IsDefaultCharacter())
			{
				int charID = m_ScenePC.GetIntroCharacter().GetCharacterID();
				m_ScenePC.GetIntroCharacter().GetLastPlayedServer(charID, ip, port);
				
				m_LastPlayedTooltipIP.SetText( "#main_menu_IP " + ip );
				m_LastPlayedTooltipPort.SetText( "#main_menu_port " + port );
				
				m_LastPlayedTooltipTimer.FadeIn( m_LastPlayedTooltip, 0.3, true );
			}
		}
		
		if( IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( w == m_Play )
		{
			m_LastPlayedTooltipTimer.FadeOut( m_LastPlayedTooltip, 0.3, true );
		}
		
		if( IsFocusable( w ) )
		{
			ColorNormal( w );
			return true;
		}
		return false;
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
	
	bool IsFocusable( Widget w )
	{
		if( w )
		{
			if( w == m_Play || w == m_ChooseServer || w == m_CustomizeCharacter || w == m_StatButton || w == m_MessageButton || w == m_SettingsButton );
			{
				return true;
			}
			
			if( w == m_Exit || w == m_NewsFeedOpen || w == m_NewsFeedClose || w == m_PlayVideo );
			{
				return true;
			}
			
			if( w == m_CharacterStatsOpen || w == m_CharacterStatsClose || w == m_NewsMain || w == m_NewsSec1 || w == m_NewsSec2 || w == m_PrevCharacter || w == m_NextCharacter );
			{
				return true;
			}
		}
		return false;
	}
	
	override void Refresh()
	{
		string name;
		
		if( m_ScenePC )
		{
			OnChangeCharacter();
			//name = m_ScenePC.GetIntroCharacter().GetCharacterName();
		}		
		
		string version;
		GetGame().GetVersion( version );
		m_Version.SetText( "#main_menu_version" + " " + version );
	}	
	
	override void OnShow()
	{
		SetFocus( null );
		return;
		/*
		GetDayZGame().GetBacklit().MainMenu_OnShow();
	
		SetFocus( layoutRoot );
		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );
		
		Refresh();
		
		if( m_ScenePC && m_ScenePC.GetIntroCamera() )
		{
			m_ScenePC.GetIntroCamera().LookAt( m_ScenePC.GetIntroCharacter().GetPosition() + Vector( 0, 1, 0 ) );
		}
		
		LoadMods();
		*/
	}
	
	override void OnHide()
	{
		GetDayZGame().GetBacklit().MainMenu_OnHide();
		//super.OnHide();
	}
	
	override void Update(float timeslice)
	{
		super.Update( timeslice );
		
		if( GetGame() && GetGame().GetInput() && GetGame().GetInput().LocalPress("UAUIBack", false) )
		{
			Exit();
		}
	}
	
	void Play()
	{
		if (m_ScenePC && m_ScenePC.GetIntroCharacter())
		{
			//saves demounit for further use
			if (m_ScenePC.GetIntroCharacter().GetCharacterObj().GetInventory().FindAttachment(InventorySlots.BODY) && m_ScenePC.GetIntroCharacter().GetCharacterID() == -1)
			{
				m_ScenePC.GetIntroCharacter().SaveCharacterSetup();
			}
		}
	
		if( !g_Game.IsNewCharacter() )
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "ConnectLastSession");
		}
		else
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallByName(this, "ConnectBestServer");
		}
	}

	void OpenMenuServerBrowser()
	{
		EnterScriptedMenu(MENU_SERVER_BROWSER);
				
		//saves demounit for further use
		if (m_ScenePC && m_ScenePC.GetIntroCharacter() && m_ScenePC.GetIntroCharacter().GetCharacterObj().GetInventory().FindAttachment(InventorySlots.BODY) && m_ScenePC.GetIntroCharacter().GetCharacterID() == -1)
		{
			m_ScenePC.GetIntroCharacter().SaveCharacterSetup();
		}
	}
	
	void OpenMenuCustomizeCharacter()
	{
		EnterScriptedMenu(MENU_CHARACTER);
	}
	
	void NextCharacter()
	{
		if ( m_ScenePC && m_ScenePC.GetIntroCharacter() )
		{
			int charID = m_ScenePC.GetIntroCharacter().GetNextCharacterID();
			//m_ScenePC.GetIntroCharacter().SaveCharName();
			if( charID != m_ScenePC.GetIntroCharacter().GetCharacterID())
			{
				m_ScenePC.GetIntroCharacter().SetCharacterID(charID);
				OnChangeCharacter();
			}
		}
	}
	
	void PreviousCharacter()
	{
		if ( m_ScenePC && m_ScenePC.GetIntroCharacter() )
		{
			//m_ScenePC.GetIntroCharacter().SaveCharName();
			int charID = m_ScenePC.GetIntroCharacter().GetPrevCharacterID();
			if( charID != m_ScenePC.GetIntroCharacter().GetCharacterID())
			{
				m_ScenePC.GetIntroCharacter().SetCharacterID(charID);
				OnChangeCharacter();
			}
		}
	}
	
	void OnChangeCharacter()
	{
		if ( m_ScenePC && m_ScenePC.GetIntroCharacter() )
		{
			int charID = m_ScenePC.GetIntroCharacter().GetCharacterID();
			m_ScenePC.GetIntroCharacter().CreateNewCharacterById( charID );
			m_PlayerName.SetText( m_ScenePC.GetIntroCharacter().GetCharacterNameById( charID ) );
			
			Widget w = m_CustomizeCharacter.FindAnyWidget(m_CustomizeCharacter.GetName() + "_label");
			
			if ( w )
			{
				TextWidget text = TextWidget.Cast( w );
				
				if( m_ScenePC.GetIntroCharacter().IsDefaultCharacter() )
				{
					text.SetText("#layout_main_menu_customize_char");
				}
				else
				{
					text.SetText("#layout_main_menu_rename");
				}
			}
			if (m_ScenePC.GetIntroCharacter().GetCharacterObj() )
			{
				if ( m_ScenePC.GetIntroCharacter().GetCharacterObj().IsMale() )
					m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Male);
				else
					m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Female);
			}
			
			//update character stats
			m_Stats.UpdateStats();
		}
	}
	
	void OpenStats()
	{
		
	}
	
	void OpenMessages()
	{
		
	}
	
	void ShowStats()
	{
		m_Stats.ShowStats();
		m_CharacterStatsOpen.Show( false );
	}
	
	void HideStats()
	{
		m_CharacterStatsOpen.Show( true );
		m_Stats.HideStats();
	}
	
	void ShowNewsfeed()
	{
		m_Newsfeed.ShowNewsfeed();
		m_NewsFeedOpen.Show( false );
	}
	
	void HideNewsfeed()
	{
		m_Newsfeed.HideNewsfeed();
		m_NewsFeedOpen.Show( true );
	}
	
	void OpenSettings()
	{
		EnterScriptedMenu(MENU_OPTIONS);
	}
	
	void PlayVideo()
	{
		EnterScriptedMenu(MENU_VIDEO);
	}
	
	void OpenTutorials()
	{
		EnterScriptedMenu(MENU_TUTORIAL);
	}
	
	void OpenCredits()
	{
		EnterScriptedMenu(MENU_CREDITS);
	}
	
	void Exit()
	{
		GetGame().GetUIManager().ShowDialog("#main_menu_exit", "#main_menu_exit_desc", IDC_MAIN_QUIT, DBT_YESNO, DBB_YES, DMT_QUESTION, this);
	}
		
	bool TryConnectLastSession( out string ip, out int port )
	{
		if( g_Game.GetLastVisitedServer( ip, port ) )
		{
			return true;
		}
		return false;
	}
	
	void AutoConnect()
	{
		OnlineServices.AutoConnectToEmptyServer();
	}
	
	void ConnectLastSession()
	{
		string ip = "";
		int port = 0;
			 
		if(!m_ScenePC.GetIntroCharacter().IsDefaultCharacter())
		{
			int charID = m_ScenePC.GetIntroCharacter().GetCharacterID();
			m_ScenePC.GetIntroCharacter().GetLastPlayedServer(charID,ip,port);
		}
		
		if( ip.Length() > 0 )
		{
			g_Game.ConnectFromServerBrowser( ip, port, "" );
		}
		else
		{
			OpenMenuServerBrowser();
		}
	}
	
	void ConnectBestServer()
	{
		ConnectLastSession();
	}
	
	override bool OnModalResult( Widget w, int x, int y, int code, int result )
	{
		if( code == IDC_MAIN_QUIT )
		{
			if( result == 2 )
				GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(g_Game.RequestExit, IDC_MAIN_QUIT);
			#ifdef PLATFORM_WINDOWS
			if( result == 3 )
				ColorNormal( GetFocus() );
			#endif
			return true;
		}
		else if( code == 555 )
		{
			if( result == 2 )
				OpenTutorials();
		}
		return false;
	}
		
	//Coloring functions (Until WidgetStyles are useful)
	void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		//SetFocus( w );
		
		int color_pnl = ARGB(255, 0, 0, 0);
		int color_lbl = ARGB(255, 255, 0, 0);
		int color_img = ARGB(255, 200, 0, 0);
		
		#ifdef PLATFORM_CONSOLE
			color_pnl = ARGB(255, 200, 0, 0);
			color_lbl = ARGB(255, 255, 255, 255);
		#endif
		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
	}
	
	void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = ARGB(0, 0, 0, 0);
		int color_lbl = ARGB(255, 255, 255, 255);
		int color_img = ARGB(255, 255, 255, 255);
		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
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
	
	void ImagenSetColor( Widget w, int color )
	{
		if( !w )
			return;
		
		Widget panel = w.FindWidget( w.GetName() + "_image" );
		
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
