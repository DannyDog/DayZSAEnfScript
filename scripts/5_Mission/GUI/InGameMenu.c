class InGameMenu extends UIScriptedMenu
{
	protected Widget			m_ContinueButton;
	protected Widget			m_ExitButton;
	protected Widget			m_RestartButton;
	protected Widget			m_RestartDeadButton;
	protected Widget			m_OptionsButton;
	
	protected ref TextWidget	m_ModdedWarning;
	
	protected ref UiHintPanel m_HintPanel;
	
	void ~InGameMenu()
	{
		HudShow( true );
	}

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("gui/layouts/day_z_ingamemenu.layout");
				
		m_ContinueButton	= layoutRoot.FindAnyWidget( "continuebtn" );
		m_ExitButton		= layoutRoot.FindAnyWidget( "exitbtn" );
		m_RestartButton		= layoutRoot.FindAnyWidget( "restartbtn" );
		m_RestartDeadButton	= layoutRoot.FindAnyWidget( "restartdeadbtn" );
		m_OptionsButton		= layoutRoot.FindAnyWidget( "optionsbtn" );
		m_ModdedWarning		= TextWidget.Cast( layoutRoot.FindAnyWidget( "ModdedWarning" ) );
		m_HintPanel			= new UiHintPanel(layoutRoot.FindAnyWidget( "hint_frame" ));
		
		
		if (GetGame().IsMultiplayer())
		{
			ButtonSetText(m_RestartButton, "#main_menu_respawn");
		}
		else
		{
			ButtonSetText(m_RestartButton, "#main_menu_restart");
		}		
		
	#ifdef BULDOZER		
		delete m_RestartButton;
	#endif
		
		HudShow( false );
		
		SetGameVersion();
		
		m_ModdedWarning.Show( g_Game.ReportModded() );
		
		return layoutRoot;
	}
	
	protected void SetGameVersion()
	{
		TextWidget version_widget = TextWidget.Cast( layoutRoot.FindAnyWidget("version") );
		string version;
		GetGame().GetVersion( version );
		version_widget.SetText( "#main_menu_version" + " " + version );

		#ifdef PREVIEW_BUILD
			version_widget.SetText("THIS IS PREVIEW");
		#endif
	}
	
	protected void HudShow( bool show )
	{
		Mission mission = GetGame().GetMission();
		if ( mission )
		{
			IngameHud hud = IngameHud.Cast( mission.GetHud() );
			if ( hud )
			{
				hud.ShowHudUI(show);
				hud.ShowQuickbarUI(show);
			}
		}
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		ColorHighlight( w );
		return true;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		ColorNormal( w );
		return true;
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		
		if ( w == m_ContinueButton )
		{
			OnClick_Continue();
			return true;
		}
		else if ( w == m_RestartButton || w == m_RestartDeadButton )
		{
			OnClick_Restart();
			return true;
		}
		else if ( w == m_OptionsButton )
		{
			OnClick_Options();
			return true;
		}
		else if ( w == m_ExitButton )
		{
			OnClick_Exit();
			return true;
		}

		return false;
	}
	
	protected void OnClick_Continue()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(GetGame().GetMission().Continue);
	}
	
	protected void OnClick_Restart()
	{
		if ( !GetGame().IsMultiplayer() )
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(GetGame().RestartMission);
		}
		else
		{
			Man player = GetGame().GetPlayer();
			
			if ( player && player.IsUnconscious() )
			{
				GetGame().GetUIManager().ShowDialog("#main_menu_respawn", "#main_menu_respawn_question", IDC_INT_RETRY, DBT_YESNO, DBB_YES, DMT_QUESTION, this);
			}
			else
			{
				GameRespawn();
			}
		}
	}
	
	protected void OnClick_Options()
	{
		EnterScriptedMenu(MENU_OPTIONS);
	}
	
	protected void OnClick_Exit()
	{
		GetGame().LogoutRequestTime();
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(GetGame().GetMission().CreateLogoutMenu, this);
		
		//GetGame().GetUIManager().ShowDialog("EXIT", "Are you sure you want to exit?", IDC_INT_EXIT, DBT_YESNO, DBB_YES, DMT_QUESTION, NULL);
	}
	
	override bool OnModalResult(Widget w, int x, int y, int code, int result)
	{
		super.OnModalResult(w, x, y, code, result);
		if ( code == IDC_INT_EXIT && result == DBB_YES )
		{
			if (GetGame().IsMultiplayer())
			{
				GetGame().LogoutRequestTime();
				GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(GetGame().GetMission().CreateLogoutMenu, this);
			}
			else
			{
				// skip logout screen in singleplayer
				GetGame().GetMission().AbortMission();
			}	
			g_Game.CancelLoginTimeCountdown();
			return true;
		
		}
		else if ( code == IDC_INT_EXIT && result == DBB_NO )
		{
			g_Game.CancelLoginTimeCountdown();
		}
		else if ( code == IDC_INT_RETRY && result == DBB_YES && GetGame().IsMultiplayer() )
		{
			GameRespawn();
			return true;
		}
	
		return false;
	}
	
	override void Update( float timeslice )
	{
		super.Update( timeslice );
		
		UpdateGUI();
	}
	
	protected void UpdateGUI()
	{
		if ( GetGame().IsMultiplayer() )
		{
			Man player = GetGame().GetPlayer();
			bool player_is_alive = false;
	
			if (player)
			{
				int life_state = player.GetPlayerState();
	
				if (life_state == EPlayerStates.ALIVE)
				{
					player_is_alive = true;
				}
			}
			
			m_ContinueButton.Show( player_is_alive );
			m_RestartButton.Show( (player_is_alive && player.IsUnconscious()) );
			m_RestartDeadButton.Show( !player_is_alive );
		}
		else
		{
			m_ContinueButton.Show( player_is_alive );
			m_RestartButton.Show( (player_is_alive && player.IsUnconscious()) );
			m_RestartDeadButton.Show( !player_is_alive );
		}
	}
	
	protected void GameRespawn()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(GetGame().RespawnPlayer);
		//turns off dead screen, hides HUD for countdown
		//---------------------------------------------------
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if(player)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(player.ShowDeadScreen, DayZPlayerImplement.DEAD_SCREEN_DELAY, false, false, 0);
		}
		
		MissionGameplay missionGP = MissionGameplay.Cast(GetGame().GetMission());
		missionGP.DestroyAllMenus();
		missionGP.SetPlayerRespawning(true);
		//---------------------------------------------------
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(GetGame().GetMission().Continue);
		Close();
	}	
	
	protected void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, ARGB(255, 0, 0, 0));
		ButtonSetTextColor(w, ARGB(255, 255, 0, 0));
	}
	
	protected void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, ARGB(0, 0, 0, 0));
		ButtonSetTextColor(w, ARGB(255, 255, 255, 255));
	}
	
	protected void ButtonSetText( Widget w, string text )
	{
		if( !w )
			return;
				
		TextWidget label = TextWidget.Cast(w.FindWidget( w.GetName() + "_label" ) );
		
		if( label )
		{
			label.SetText( text );
		}
		
	}
	
	protected void ButtonSetColor( Widget w, int color )
	{
		if( !w )
			return;
		
		Widget panel = w.FindWidget( w.GetName() + "_panel" );
		
		if( panel )
		{
			panel.SetColor( color );
		}
	}
	
	protected void ButtonSetTextColor( Widget w, int color )
	{
		if( !w )
			return;

		TextWidget label	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
				
		if( label )
		{
			label.SetColor( color );
		}
	}
}
