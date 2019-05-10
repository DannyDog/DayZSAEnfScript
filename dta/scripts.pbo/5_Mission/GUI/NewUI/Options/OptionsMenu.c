class OptionsMenu extends UIScriptedMenu
{
	protected TabberUI					m_Tabber;
	protected ref OptionsMenuGame		m_GameTab;
	protected ref OptionsMenuSounds		m_SoundsTab;
	protected ref OptionsMenuVideo		m_VideoTab;
	protected ref OptionsMenuControls	m_ControlsTab;
	
	protected ref GameOptions			m_Options;
	
	protected ButtonWidget				m_Apply;
	protected ButtonWidget				m_Back;
	protected ButtonWidget				m_Reset;
	
	protected Widget					m_Details;
	protected TextWidget				m_Version;
	
	void OptionsMenu()
	{
		
	}
	
	override Widget Init()
	{
		m_Options			= new GameOptions();
		
		#ifdef PLATFORM_CONSOLE
			layoutRoot		= GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/options/xbox/options_menu.layout", null );
		#else
		#ifdef PLATFORM_WINDOWS
			layoutRoot		= GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/options/pc/options_menu.layout", null );
		#endif
		#endif
		
		layoutRoot.FindAnyWidget( "Tabber" ).GetScript( m_Tabber );
		
		m_Details			= layoutRoot.FindAnyWidget( "settings_details" );
		m_Version			= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		
		m_GameTab			= new OptionsMenuGame( layoutRoot.FindAnyWidget( "Tab_0" ), m_Details, m_Options, this );
		m_SoundsTab			= new OptionsMenuSounds( layoutRoot.FindAnyWidget( "Tab_1" ), m_Details, m_Options, this );
		
		#ifdef PLATFORM_CONSOLE
			m_ControlsTab	= new OptionsMenuControls( layoutRoot.FindAnyWidget( "Tab_2" ), m_Details, m_Options, this );
		#else
		#ifdef PLATFORM_WINDOWS
			m_VideoTab		= new OptionsMenuVideo( layoutRoot.FindAnyWidget( "Tab_2" ), m_Details, m_Options, this );
			m_ControlsTab	= new OptionsMenuControls( layoutRoot.FindAnyWidget( "Tab_3" ), m_Details, m_Options, this );
		#endif
		#endif
		
		m_Apply				= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "apply" ) );
		m_Back				= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "back" ) );
		m_Reset				= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "reset" ) );
		
		string version;
		GetGame().GetVersion( version );
		#ifdef PLATFORM_CONSOLE
			version = "#main_menu_version" + " " + version + " (" + g_Game.GetDatabaseID() + ")";
		#else
			version = "#main_menu_version" + " " + version;
		#endif
		m_Version.SetText( version );
		
		#ifdef PLATFORM_WINDOWS
			SetFocus( layoutRoot );
		#else
			SliderFocus();
		#endif
		
		m_Tabber.m_OnTabSwitch.Insert( OnTabSwitch );
		
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
			ImageWidget toolbar_a = layoutRoot.FindAnyWidget( "ToggleIcon" );
			ImageWidget toolbar_b = layoutRoot.FindAnyWidget( "BackIcon" );
			ImageWidget toolbar_x = layoutRoot.FindAnyWidget( "ApplyIcon" );
			ImageWidget toolbar_y = layoutRoot.FindAnyWidget( "ResetIcon" );
			toolbar_a.LoadImageFile( 0, "set:playstation_buttons image:" + confirm );
			toolbar_b.LoadImageFile( 0, "set:playstation_buttons image:" + back );
			toolbar_x.LoadImageFile( 0, "set:playstation_buttons image:square" );
			toolbar_y.LoadImageFile( 0, "set:playstation_buttons image:triangle" );
		#endif
		
		OnChanged();
		
		return layoutRoot;
	}
	
	void ~OptionsMenu()
	{
		Reset();
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			if( w == m_Apply )
			{
				Apply();
				return true;
			}
			else if( w == m_Back )
			{
				Back();
				return true;
			}
			else if( w == m_Reset )
			{
				Reset();
				return true;
			}
		}
		return false;
	}
	
	void OnTabSwitch( int tab )
	{
		switch( tab )
		{
			case 0:
			{
				m_GameTab.Focus();
				break;
			}
			case 1:
			{
				m_SoundsTab.Focus();
				break;
			}
			case 2:
			{
				#ifdef PLATFORM_CONSOLE
					m_ControlsTab.Focus();
				#else
				#ifdef PLATFORM_WINDOWS
					m_VideoTab.Focus();
				#endif
				#endif
				break;
			}
			case 3:
			{
				#ifdef PLATFORM_WINDOWS
					m_ControlsTab.Focus();
				#endif
				break;
			}
		}
	}
	
	void Apply()
	{
		if( m_Options.IsChanged() || m_GameTab.IsChanged() )
		{
			m_Options.Test();
			m_Options.Apply();
		}
		
		if( m_GameTab.IsChanged() )
		{
			m_GameTab.Apply();
		}
		
		// save input configuration
		GetUApi().Export();	
		
		#ifdef PLATFORM_CONSOLE
			layoutRoot.FindAnyWidget( "Reset" ).Show( false );
			layoutRoot.FindAnyWidget( "Apply" ).Show( false );
		#else
		#ifdef PLATFORM_WINDOWS
			//m_Apply.Enable( false );
			m_Apply.SetFlags( WidgetFlags.IGNOREPOINTER );
			ColorDisable(m_Apply);
			//m_Reset.Enable( false );
			//m_Reset.SetFlags( WidgetFlags.IGNOREPOINTER );
			//ColorDisable(m_Reset);
		#endif
		#endif
		
		if( m_Options.NeedRestart() )
			g_Game.GetUIManager().ShowDialog("#main_menu_configure", "#menu_restart_needed", 117, DBT_YESNO, DBB_YES, DMT_QUESTION, this);
	}
	
	void Back()
	{
		bool changed = false;
		
		if( m_Options.IsChanged() )
		{
			changed = true;
		}
		
		if( m_GameTab.IsChanged() )
		{
			changed = true;
		}
		
		if( m_SoundsTab.IsChanged() )
		{
			changed = true;
		}
		
		#ifdef PLATFORM_WINDOWS
		#ifndef PLATFORM_CONSOLE
		else if( m_VideoTab.IsChanged() )
		{
			changed = true;
		}
		#endif
		#endif
		
		if( changed )
			g_Game.GetUIManager().ShowDialog("#main_menu_configure", "#main_menu_configure_desc", 1337, DBT_YESNO, DBB_YES, DMT_QUESTION, this);
		else
		{
			m_Options.Revert();
			GetGame().EndOptionsVideo();
			GetGame().GetUIManager().Back();
		}
	}
	
	void OnChanged()
	{
		bool changed = false;
		if( m_Options.IsChanged() || m_GameTab.IsChanged() || m_SoundsTab.IsChanged() )
		{
			changed = true;
		}
		#ifdef PLATFORM_WINDOWS
		#ifndef PLATFORM_CONSOLE
		else if( m_VideoTab.IsChanged() )
		{
			changed = true;
		}
		#endif
		#endif
		
		#ifdef PLATFORM_CONSOLE
			layoutRoot.FindAnyWidget( "Apply" ).Show( changed );
			layoutRoot.FindAnyWidget( "Reset" ).Show( changed );
		#else
		#ifdef PLATFORM_WINDOWS
			//m_Apply.Enable( changed );
			//m_Reset.Enable( changed );
		
			if( changed )
			{
				//m_Reset.ClearFlags( WidgetFlags.IGNOREPOINTER );
				//ColorNormal( m_Reset );
				m_Apply.ClearFlags( WidgetFlags.IGNOREPOINTER );
				ColorNormal( m_Apply );
			}
			else
			{
				m_Apply.SetFlags( WidgetFlags.IGNOREPOINTER );
				ColorDisable( m_Apply );
				//m_Reset.SetFlags( WidgetFlags.IGNOREPOINTER );
				//ColorDisable( m_Reset );
				
			}
		#endif
		#endif
	}
	
	void Reset()
	{
		//if( m_Options.IsChanged() )
			m_Options.Revert();
		//if( m_GameTab.IsChanged() )
			m_GameTab.Revert();
		//if( m_SoundsTab.IsChanged() )
			m_SoundsTab.Revert();
		//if( m_ControlsTab.IsChanged() )
			m_ControlsTab.Revert();
		#ifdef PLATFORM_WINDOWS
		#ifndef PLATFORM_CONSOLE
		//if( m_VideoTab.IsChanged() )
			m_VideoTab.Revert();
		#endif
		#endif
		
		if( m_Options.IsChanged() )
			m_Options.Revert();
		
		#ifdef PLATFORM_CONSOLE
			layoutRoot.FindAnyWidget( "Apply" ).Show( false );
			layoutRoot.FindAnyWidget( "Reset" ).Show( false );
		#else
		#ifdef PLATFORM_WINDOWS
			//m_Apply.Enable( false );
			//m_Apply.SetFlags( WidgetFlags.IGNOREPOINTER );
		
			//m_Reset.Enable( false );
			//m_Reset.SetFlags( WidgetFlags.IGNOREPOINTER );
		#endif
		#endif
	}
	
	void SliderFocus()
	{
		#ifdef PLATFORM_CONSOLE
		layoutRoot.FindAnyWidget( "Toggle" ).Show( false );
		#endif
	}
	
	void ToggleFocus()
	{
		#ifdef PLATFORM_CONSOLE
		layoutRoot.FindAnyWidget( "Toggle" ).Show( true );
		#endif
	}
	
	void ReloadOptions()
	{
		m_Options = new GameOptions();
		if( m_GameTab )
			m_GameTab.SetOptions( m_Options );
		if( m_SoundsTab )
			m_SoundsTab.SetOptions( m_Options );
		if( m_ControlsTab )
			m_ControlsTab.SetOptions( m_Options );
		
		#ifdef PLATFORM_WINDOWS
		#ifndef PLATFORM_CONSOLE
			if( m_VideoTab )
				m_VideoTab.SetOptions( m_Options );
		#endif
		#endif
	}
	
	override bool OnModalResult( Widget w, int x, int y, int code, int result )
	{
		if( code == 1337 )
		{
			if( result == 2 )
			{
				m_Options.Revert();
				GetGame().EndOptionsVideo();
				GetGame().GetUIManager().Back();
			}
			return true;
		}
		else if( code == 117 )
		{
			g_Game.RequestRestart(IDC_MAIN_QUIT);
		}
		return false;
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( w && IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( w && IsFocusable( w ) )
		{
			ColorNormal( w );
			return true;
		}
		return false;
	}
	
	override bool OnFocus( Widget w, int x, int y )
	{
		if( w && IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}
		else if( y == 1 )
		{
			SliderFocus();
		}
		else
		{
			ToggleFocus();
		}
		
		return false;
	}
	
	override bool OnFocusLost( Widget w, int x, int y )
	{
		if( w && IsFocusable( w ) )
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
			return ( w == m_Apply || w == m_Back || w == m_Reset );
		}
		return false;
	}
	
	override void Refresh()
	{
		string version;
		GetGame().GetVersion( version );
		#ifdef PLATFORM_CONSOLE
			version = "#main_menu_version" + " " + version + " (" + g_Game.GetDatabaseID() + ")";
		#else
			version = "#main_menu_version" + " " + version;
		#endif
		m_Version.SetText( version );
	}
	
	override void OnShow()
	{
		super.OnShow();
		Refresh();
	}
	
	override void Update( float timeslice )
	{
		super.Update( timeslice );
		if( GetGame().GetInput().LocalPress("UAUITabLeft",false) )
		{
			m_Tabber.PreviousTab();
		}
		
		//RIGHT BUMPER - TAB RIGHT
		if( GetGame().GetInput().LocalPress("UAUITabRight",false) )
		{
			m_Tabber.NextTab();
		}
		
		if( GetGame().GetInput().LocalPress("UAUICtrlX",false) )
		{
			Apply();
		}
		
		if( GetGame().GetInput().LocalPress("UAUICtrlY",false) )
		{
			Reset();
		}
		
		if( GetGame().GetInput().LocalPress("UAUIBack",false) )
		{
			Back();
		}
	}
	
	//Coloring functions (Until WidgetStyles are useful)
	void ColorHighlight( Widget w )
	{
		if( w.IsInherited( ButtonWidget ) )
		{
			ButtonWidget button = ButtonWidget.Cast( w );
			button.SetTextColor( ARGB( 255, 200, 0, 0 ) );
		}
		
		w.SetColor( ARGB( 255, 0, 0, 0) );
		
		TextWidget text1	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		TextWidget text3	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindAnyWidget( w.GetName() + "_image" ) );
		Widget option		= Widget.Cast( w.FindAnyWidget( w.GetName() + "_option_wrapper" ) );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if( text1 )
		{
			text1.SetColor( ARGB( 255, 255, 0, 0 ) );
		}
		
		if( text2 )
		{
			text2.SetColor( ARGB( 255, 255, 0, 0 ) );
		}
		
		if( text3 )
		{
			text3.SetColor( ARGB( 255, 255, 0, 0 ) );
			w.SetAlpha(1);
		}
		
		if( image )
		{
			image.SetColor( ARGB( 255, 200, 0, 0 ) );
		}
		
		if ( option )
		{
			option.SetColor( ARGB( 255, 255, 0, 0 ) );
		}
		
		if ( option_label )
		{
			option_label.SetColor( ARGB( 255, 255, 0, 0 ) );
		}
	}
	
	void ColorNormal( Widget w )
	{
		//Print("ColorNormal -> "+ w.GetName());
		//DumpStack();
		
		if ( (w.GetFlags() & WidgetFlags.IGNOREPOINTER) == WidgetFlags.IGNOREPOINTER )
		{
			return;
		}
		
		if( w.IsInherited( ButtonWidget ) )
		{
			ButtonWidget button = ButtonWidget.Cast( w );
			button.SetTextColor( ARGB( 255, 255, 255, 255 ) );
		}
		
		TextWidget text1	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
		TextWidget text3	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindAnyWidget( w.GetName() + "_image" ) );
		Widget option		= w.FindAnyWidget( w.GetName() + "_option_wrapper" );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if( text1 )
		{
			text1.SetColor( ARGB( 255, 255, 255, 255 ) );
		}
		
		if( text2 )
		{
			text2.SetColor( ARGB( 255, 255, 255, 255 ) );
		}
		
		if( text3 )
		{
			text3.SetColor( ARGB( 255, 255, 255, 255 ) );
			w.SetAlpha(0);
		}
		
		if( image )
		{
			image.SetColor( ARGB( 255, 255, 255, 255 ) );
		}
		
		if ( option )
		{
			option.SetColor( ARGB( 150, 255, 255, 255 ) );
		}
		
		if ( option_label )
		{
			option_label.SetColor( ARGB( 255, 255, 255, 255 ) );
		}
	}
	
	void ColorDisable( Widget w )
	{
		#ifdef PLATFORM_WINDOWS
		SetFocus( null );
		#endif
		
		if ( w )
		{
			ButtonWidget button = ButtonWidget.Cast( w );
			if( button )
			{
				button.SetTextColor( ColorManager.COLOR_DISABLED_TEXT );
			}
		}
	}
}
