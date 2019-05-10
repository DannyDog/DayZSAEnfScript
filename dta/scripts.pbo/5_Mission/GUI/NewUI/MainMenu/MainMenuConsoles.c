class MainMenuConsole extends UIScriptedMenu
{
	protected ref MainMenuVideo		m_Video;
	
	protected MissionMainMenu		m_Mission;
	protected DayZIntroScenePC 		m_ScenePC;
	
	protected TextWidget			m_PlayerName;
	protected TextWidget			m_Version;
	
	protected Widget				m_PlayVideo;
	protected Widget				m_Tutorials;
	protected Widget				m_Options;
	protected Widget				m_Controls;
	protected Widget				m_Play;	
	
	protected ref Widget			m_LastFocusedButton;
	protected bool					m_IsShown;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/main_menu_console.layout" );
		
		m_PlayerName			= TextWidget.Cast( layoutRoot.FindAnyWidget("character_name_xbox") );
		
		m_PlayVideo					= layoutRoot.FindAnyWidget( "play_video" );
		m_Tutorials					= layoutRoot.FindAnyWidget( "tutorials" );
		m_Options					= layoutRoot.FindAnyWidget( "options" );
		m_Controls					= layoutRoot.FindAnyWidget( "controls" );
		m_Play						= layoutRoot.FindAnyWidget( "play" );
		
		m_Version					= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		m_Mission					= MissionMainMenu.Cast( GetGame().GetMission() );
		m_LastFocusedButton = 		m_Play;
				
		GetGame().GetUIManager().ScreenFadeOut(1);

		string launch_done;
		if( !GetGame().GetProfileString( "FirstLaunchDone", launch_done ) || launch_done != "true" )
		{
			GetGame().SetProfileString( "FirstLaunchDone", "true" );
			GetGame().GetUIManager().ShowDialog( "#main_menu_tutorial", "#main_menu_tutorial_desc", 555, DBT_YESNO, DBB_YES, DMT_QUESTION, this );
			GetGame().SaveProfile();
		}
		
		#ifdef PLATFORM_PS4
			string confirm = "cross";
			if( GetGame().GetInput().GetEnterButton() == GamepadButton.A )
			{
				confirm = "cross";
			}
			else
			{
				confirm = "circle";
			}
			ImageWidget toolbar_a = layoutRoot.FindAnyWidget( "SelectIcon" );
			ImageWidget toolbar_y = layoutRoot.FindAnyWidget( "ChooseAccount" );
			toolbar_a.LoadImageFile( 0, "set:playstation_buttons image:" + confirm );
			toolbar_y.Show( false );
		#endif
		
		Refresh();
		return layoutRoot;
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( m_IsShown )
		{
			if( w == m_Play )
			{
				m_LastFocusedButton = m_Play;
				OpenMenuServerBrowser();
				return true;
			}
			else if ( w == m_Options )
			{
				m_LastFocusedButton = m_Options;
				OpenMenuOptions();					
				return true;
			}
			else if ( w == m_PlayVideo )
			{
				m_LastFocusedButton = m_PlayVideo;
				OpenMenuPlayVideo();
				return true;
			}
			else if ( w == m_Tutorials )
			{
				m_LastFocusedButton = m_Tutorials;
				OpenMenuTutorials();
				return true;
			}
			else if ( w == m_Controls )
			{
				m_LastFocusedButton = m_Controls;
				OpenMenuControls();
				return true;
			}
		}
		return false;
	}
	
	override bool OnFocus( Widget w, int x, int y )
	{
		ColorHighlight( w );
		return true;
	}
	
	override bool OnFocusLost( Widget w, int x, int y )
	{
		ColorNormal( w );
		return true;
	}
	
	override void Refresh()
	{
		string name;
		
		if( GetGame().GetUserManager() && GetGame().GetUserManager().GetSelectedUser() )
		{
			name = GetGame().GetUserManager().GetSelectedUser().GetName();
			if( name.LengthUtf8() > 18 )
			{
				name = name.SubstringUtf8(0, 18);
				name += "...";
			}
		}
		m_PlayerName.SetText( name );		
		
		string version;
		GetGame().GetVersion( version );
		m_Version.SetText( "#main_menu_version" + " " + version + " (" + g_Game.GetDatabaseID() + ")" );
	}	
	
	override void OnShow()
	{
		GetDayZGame().GetBacklit().MainMenu_OnShow();
	
		SetFocus( m_LastFocusedButton );
		
		Refresh();
		
		if( m_ScenePC && m_ScenePC.GetIntroCamera() )
		{
			m_ScenePC.GetIntroCamera().LookAt( m_ScenePC.GetIntroCharacter().GetPosition() + Vector( 0, 1, 0 ) );
		}
		m_IsShown = true;
	}
	
	override void OnHide()
	{
		m_IsShown = false;
		GetDayZGame().GetBacklit().MainMenu_OnHide();
	}

	override void Update(float timeslice)
	{
		super.Update( timeslice );
		if( m_IsShown )
		{
			
			#ifndef PLATFORM_CONSOLE
			if ( GetGame().GetInput().LocalPress("UAUIBack", false) && g_Game.GetLoadState() != DayZGameState.CONNECTING && !GetGame().GetUIManager().IsDialogVisible() )
			{
				Exit();
			}
			#endif
			#ifdef PLATFORM_XBOX
			if ( GetGame().GetInput().LocalPress("UAUICtrlY",false) )
			{
				BiosUserManager user_manager = GetGame().GetUserManager();
				if( user_manager )
				{
					g_Game.SetLoadState( DayZLoadState.MAIN_MENU_START );
					#ifndef PLATFORM_WINDOWS
					user_manager.SelectUser( null );
					#endif
					GetGame().GetUIManager().Back();
				}
			}
			#endif
		}
	}
	
	void OpenMenuServerBrowser()
	{
		EnterScriptedMenu(MENU_SERVER_BROWSER);
	}

	void OpenMenuControls()
	{
		EnterScriptedMenu( MENU_XBOX_CONTROLS );
	}
	
	void OpenMenuOptions()
	{
		EnterScriptedMenu(MENU_OPTIONS);
	}
	
	void OpenMenuPlayVideo()
	{
		EnterScriptedMenu(MENU_VIDEO);
	}
	
	void OpenMenuTutorials()
	{
		EnterScriptedMenu(MENU_TUTORIAL);
	}
	
	void Exit()
	{
		GetGame().GetUIManager().ShowDialog("#main_menu_exit", "#main_menu_exit_desc", IDC_MAIN_QUIT, DBT_YESNO, DBB_YES, DMT_QUESTION, this);
	}
		
	//Coloring functions (Until WidgetStyles are useful)
	void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = ARGB(255, 200, 0, 0);
		int color_lbl = ARGB(255, 255, 255, 255);
		
		ButtonSetColor(w, color_pnl);
		ButtonSetAlphaAnim( w );
		ButtonSetTextColor(w, color_lbl);
	}
	
	void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = ARGB(0, 0, 0, 0);
		int color_lbl = ARGB(255, 255, 255, 255);
		
		ButtonSetColor(w, color_pnl);
		ButtonSetAlphaAnim( null );
		ButtonSetTextColor(w, color_lbl);
	}
	
	override bool OnModalResult( Widget w, int x, int y, int code, int result )
	{
		if( code == IDC_MAIN_QUIT )
		{
			if( result == 2 )
			{
				GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(g_Game.RequestExit, IDC_MAIN_QUIT);
			}
			
			return true;
		}
		else if( code == 555 )
		{
			if( result == 2 )
			{
				OpenMenuTutorials();
			}
		}
		return false;
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
	
	void ButtonSetAlphaAnim( Widget w )
	{
		if( !w )
			return;
		
		Widget panel = w.FindWidget( w.GetName() + "_panel" );
		
		if( panel )
		{
			SetWidgetAnimAlpha( panel );
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
