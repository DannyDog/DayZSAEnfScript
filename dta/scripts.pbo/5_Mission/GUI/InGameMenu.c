class InGameMenu extends UIScriptedMenu
{
	protected Widget m_ContinueButton;
	protected Widget m_ExitButton;
	protected Widget m_RestartButton;
	protected Widget m_RestartDeadButton;
	protected Widget m_OptionsButton;
	protected Widget m_Root;
	
	void ~InGameMenu()
	{
		HudSow( true );
	}

	override Widget Init()
	{
		m_Root = GetGame().GetWorkspace().CreateWidgets("gui/layouts/day_z_ingamemenu.layout");
				
		m_ContinueButton	= m_Root.FindAnyWidget( "continuebtn" );
		m_ExitButton		= m_Root.FindAnyWidget( "exitbtn" );
		m_RestartButton		= m_Root.FindAnyWidget( "restartbtn" );
		m_RestartDeadButton	= m_Root.FindAnyWidget( "restartdeadbtn" );
		m_OptionsButton		= m_Root.FindAnyWidget( "optionsbtn" );
		
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
		
		HudSow( false );
		
		SetGameVersion();
		
		//m_Root.SetHandler( this );
		
		return m_Root;
	}
	
	protected void SetGameVersion()
	{
		TextWidget version_widget = TextWidget.Cast( m_Root.FindAnyWidget("version") );
		string version;
		GetGame().GetVersion( version );
		version_widget.SetText( "#main_menu_version" + " " + version );

		#ifdef PREVIEW_BUILD
			version_widget.SetText("THIS IS PREVIEW");
		#endif
	}
	
	protected void HudSow( bool show )
	{
		Mission mission = GetGame().GetMission();
		if ( mission )
		{
			IngameHud hud = IngameHud.Cast( mission.GetHud() );
			if ( hud )
			{
				if ( show )
				{
					hud.ToggleHud( hud.GetHudState(), true );
					hud.ToggleQuickBar( hud.GetQuickBarState(), true );
				}
				else
				{
					hud.ToggleHud( false, true );
					hud.ToggleQuickBar( false, true );
				}
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
			GetGame().GetMission().PlayerControlEnable();
		}
		else
		{
			Man player = GetGame().GetPlayer();
			
			if ( player && player.IsUnconscious() )
			{
				GetGame().GetUIManager().ShowDialog("#main_menu_respawn", "#main_menu_respawn_question", IDC_INT_RETRY, DBT_YESNO, DBB_YES, DMT_QUESTION, this);
				GetGame().GetMission().PlayerControlEnable();
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
			g_Game.CancelQueueTime();
			return true;
		
		}
		else if ( code == IDC_INT_EXIT && result == DBB_NO )
		{
			g_Game.CancelQueueTime();
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
		//---------------------------------------------------
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(GetGame().GetMission().Continue);
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
