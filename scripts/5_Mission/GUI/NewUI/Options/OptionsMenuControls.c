class OptionsMenuControls extends ScriptedWidgetEventHandler
{
	protected Widget						m_Root;
	
	protected Widget						m_SettingsRoot;
	protected Widget						m_DetailsRoot;
	protected TextWidget					m_DetailsLabel;
	protected RichTextWidget				m_DetailsText;
	protected GridSpacerWidget				m_Keybindings;
	
	protected GameOptions					m_Options;
	protected OptionsMenu					m_Menu;
	
	protected ref SwitchOptionsAccess		m_KeyboardOption;
	protected ref SwitchOptionsAccess		m_AimHelperOption;
	protected ref NumericOptionsAccess		m_VSensitivityOption;
	protected ref NumericOptionsAccess		m_HSensitivityOption;
	protected ref SwitchOptionsAccess		m_InvertOption;
	protected ref NumericOptionsAccess		m_ControllerVSensitivityOption;
	protected ref NumericOptionsAccess		m_ControllerHSensitivityOption;
	protected ref SwitchOptionsAccess		m_ControllerInvertOption;
	
	protected ref OptionSelectorMultistate	m_KeyboardSelector;
	protected ref OptionSelectorMultistate	m_AimHelperSelector;
	protected ref OptionSelectorSlider		m_VSensitivitySelector;
	protected ref OptionSelectorSlider		m_HSensitivitySelector;
	protected ref OptionSelectorMultistate	m_InvertSelector;
	protected ref OptionSelectorSlider		m_ControllerVSensitivitySelector;
	protected ref OptionSelectorSlider		m_ControllerHSensitivitySelector;
	protected ref OptionSelectorMultistate	m_ControllerInvertSelector;
	
	protected ref map<int, ref Param2<string, string>> m_TextMap;
	
	void OptionsMenuControls( Widget parent, Widget details_root, GameOptions options, OptionsMenu menu )
	{
		m_Root										= GetGame().GetWorkspace().CreateWidgets( GetLayoutName(), parent );
		
		m_DetailsRoot								= details_root;
		m_DetailsLabel								= TextWidget.Cast( m_DetailsRoot.FindAnyWidget( "details_label" ) );
		m_DetailsText								= RichTextWidget.Cast( m_DetailsRoot.FindAnyWidget( "details_content" ) );
		m_Keybindings								= GridSpacerWidget.Cast( m_Root.FindAnyWidget( "keyboard_settings_content" ) );
		
		m_Options 									= options;
		m_Menu										= menu;
		
		#ifdef PLATFORM_PS4
		TextWidget text_controller = TextWidget.Cast(m_Root.FindAnyWidget( "controller_text" ));
		text_controller.SetText( "#layout_PS4_controls_controller" );
		#endif
		
		SetOptions( options );
		
		#ifdef PLATFORM_CONSOLE
		m_Root.FindAnyWidget( "keyboard_setting_option" ).SetUserID( AT_OPTIONS_MOUSE_AND_KEYBOARD );
		m_Root.FindAnyWidget( "aimhelper_setting_option" ).SetUserID( AT_OPTIONS_AIM_HELPER );
		#endif
		
		#ifdef PLATFORM_WINDOWS
		#ifndef PLATFORM_CONSOLE
		m_Root.FindAnyWidget( "vsensitivity_setting_option" ).SetUserID( AT_CONFIG_YAXIS );
		m_Root.FindAnyWidget( "hsensitivity_setting_option" ).SetUserID( AT_CONFIG_XAXIS );
		m_Root.FindAnyWidget( "invert_setting_option" ).SetUserID( AT_CONFIG_YREVERSED );
		m_Keybindings.SetUserID( 777 );
		#endif
		#endif
		
		m_Root.FindAnyWidget( "controller_vsensitivity_setting_option" ).SetUserID( AT_CONFIG_CONTROLLER_YAXIS );
		m_Root.FindAnyWidget( "controller_hsensitivity_setting_option" ).SetUserID( AT_CONFIG_CONTROLLER_XAXIS );
		m_Root.FindAnyWidget( "controller_invert_setting_option" ).SetUserID( AT_CONFIG_CONTROLLER_REVERSED_LOOK );

		ref array<string> opt						= { "#options_controls_disabled", "#options_controls_enabled" };
		
		#ifdef PLATFORM_CONSOLE
		m_KeyboardSelector							= new OptionSelectorMultistate( m_Root.FindAnyWidget( "keyboard_setting_option" ), m_KeyboardOption.GetIndex(), this, false, opt );
		m_AimHelperSelector							= new OptionSelectorMultistate( m_Root.FindAnyWidget( "aimhelper_setting_option" ), m_AimHelperOption.GetIndex(), this, false, opt );
		m_KeyboardSelector.m_OptionChanged.Insert( UpdateKeyboard );
		m_AimHelperSelector.m_OptionChanged.Insert( UpdateAimHelper );
		#endif
		
		m_ControllerVSensitivitySelector			= new OptionSelectorSlider( m_Root.FindAnyWidget( "controller_vsensitivity_setting_option" ), m_ControllerVSensitivityOption.ReadValue(), this, false, m_ControllerVSensitivityOption.GetMin(), m_ControllerVSensitivityOption.GetMax() );
		m_ControllerHSensitivitySelector			= new OptionSelectorSlider( m_Root.FindAnyWidget( "controller_hsensitivity_setting_option" ), m_ControllerHSensitivityOption.ReadValue(), this, false, m_ControllerHSensitivityOption.GetMin(), m_ControllerHSensitivityOption.GetMax() );
		m_ControllerInvertSelector					= new OptionSelectorMultistate( m_Root.FindAnyWidget( "controller_invert_setting_option" ), m_ControllerInvertOption.GetIndex(), this, false, opt );
		
		#ifdef PLATFORM_WINDOWS
		#ifndef PLATFORM_CONSOLE
		m_VSensitivitySelector						= new OptionSelectorSlider( m_Root.FindAnyWidget( "vsensitivity_setting_option" ), m_VSensitivityOption.ReadValue(), this, false, m_VSensitivityOption.GetMin(), m_VSensitivityOption.GetMax() );
		m_HSensitivitySelector						= new OptionSelectorSlider( m_Root.FindAnyWidget( "hsensitivity_setting_option" ), m_HSensitivityOption.ReadValue(), this, false, m_HSensitivityOption.GetMin(), m_HSensitivityOption.GetMax() );
		m_InvertSelector							= new OptionSelectorMultistate( m_Root.FindAnyWidget( "invert_setting_option" ), m_InvertOption.GetIndex(), this, false, opt );
		
		m_VSensitivitySelector.m_OptionChanged.Insert( UpdateVerticalSensitivity );
		m_HSensitivitySelector.m_OptionChanged.Insert( UpdateHorizontalSensitivity );
		m_InvertSelector.m_OptionChanged.Insert( UpdateInvertView );
		#endif
		#endif
		
		m_ControllerVSensitivitySelector.m_OptionChanged.Insert( UpdateControllerVerticalSensitivity );
		m_ControllerHSensitivitySelector.m_OptionChanged.Insert( UpdateControllerHorizontalSensitivity );
		m_ControllerInvertSelector.m_OptionChanged.Insert( UpdateControllerInvertView );
		
		FillTextMap();
		
		float x, y, y2;
		m_Root.FindAnyWidget( "controls_settings_scroll" ).GetScreenSize( x, y );
		m_Root.FindAnyWidget( "controls_settings_root" ).GetScreenSize( x, y2 );
		int f = ( y2 > y );
		m_Root.FindAnyWidget( "controls_settings_scroll" ).SetAlpha( f );
		
		m_Root.SetHandler( this );
	}
	
	string GetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
			return "gui/layouts/new_ui/options/xbox/controls_tab.layout";
		#else
		#ifdef PLATFORM_WINDOWS
			return "gui/layouts/new_ui/options/pc/controls_tab.layout";
		#endif
		#endif
	}
	
	void EnterKeybindingMenu()
	{
		m_Menu.EnterScriptedMenu( MENU_KEYBINDINGS );
	}
	
	void Focus()
	{
		#ifdef PLATFORM_CONSOLE
			m_KeyboardSelector.Focus();
		#endif
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if ( w && w.IsInherited( ScrollWidget ) )
		{
			return false;
		}
		
		m_Menu.ColorHighlight( w );
		
		return true;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if ( w && w.IsInherited( ScrollWidget ) )
		{
			return false;
		}
		
		m_Menu.ColorNormal( w );
		return true;
	}
	
	override bool OnMouseButtonUp( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			#ifdef PLATFORM_WINDOWS
			#ifndef PLATFORM_CONSOLE
			if( w == m_Keybindings )
			{
				EnterKeybindingMenu();
				return true;
			}
			#endif
			#endif
		}
		return false;
	}
	
	override bool OnFocus( Widget w, int x, int y )
	{
		OptionsMenu menu = OptionsMenu.Cast( GetGame().GetUIManager().GetMenu() );
		if( menu )
		{
			menu.OnFocus( w, x, y );
		}
		
		if( w )
		{
			Param2<string, string> p = m_TextMap.Get( w.GetUserID() );
			
			if( p )
			{
				m_DetailsRoot.Show( true );
				m_DetailsLabel.SetText( p.param1 );
				m_DetailsText.SetText( p.param2 );
				
				//float lines = m_DetailsText.GetContentHeight();
				//m_DetailsText.SetSize( 1, lines );
				
				m_DetailsText.Update();
				m_DetailsLabel.Update();
				m_DetailsRoot.Update();
				return true;
			}
			
			if( w.IsInherited( SliderWidget ) )
			{
				ColorRed( w );
				return true;
			}
			
			if( IsFocusable( w ) )
			{
				ColorRed( w );
				return true;
			}
		}
		else
		{
			m_DetailsRoot.Show( false );
		}
		return ( w != null );
	}
	
	override bool OnFocusLost( Widget w, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorWhite( w, null );
			return true;
		}
		return false;
	}
	/*
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorRed( w );
			return true;
		}
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorWhite( w, enterW );
			return true;
		}
		return false;
	}
	*/
	bool IsFocusable( Widget w )
	{
		if( w )
		{
			return ( w == m_Keybindings );
		}
		return false;
	}
	
	bool IsChanged()
	{
		#ifdef PLATFORM_CONSOLE
		return ( ( m_KeyboardSelector.IsEnabled() && m_KeyboardOption.GetIndex() == 0 ) || ( !m_KeyboardSelector.IsEnabled() && m_KeyboardOption.GetIndex() == 1 ) );
		#else
		return false;
		#endif
	}
	
	void Apply()
	{
		#ifdef PLATFORM_CONSOLE
		if( m_KeyboardSelector.IsEnabled() && m_KeyboardOption.GetIndex() == 0 )
		{
			m_KeyboardOption.Switch();
			g_Game.DeleteGamepadDisconnectMenu();
		}
		else if( !m_KeyboardSelector.IsEnabled() && m_KeyboardOption.GetIndex() == 1 )
		{
			m_KeyboardOption.Switch();
			m_KeyboardSelector.Focus();
			if( g_Game.ShouldShowControllerDisconnect() || ( GetGame().IsClient() && !GetGame().GetWorld().IsMouseAndKeyboardEnabledOnServer() ) )
			{
				g_Game.CreateGamepadDisconnectMenu();
			}
		}
		
		GetGame().GetInput().EnableMouseAndKeyboard( m_KeyboardSelector.IsEnabled() );
		GetGame().GetUIManager().ShowUICursor( m_KeyboardSelector.IsEnabled() );
		m_Menu.Refresh();
		#endif
	}
	
	void Revert()
	{
		#ifdef PLATFORM_CONSOLE
		if( m_KeyboardSelector )
			m_KeyboardSelector.SetValue( m_KeyboardOption.GetIndex(), false );
		if( m_AimHelperSelector )
			m_AimHelperSelector.SetValue( m_AimHelperOption.GetIndex(), false );
		#endif
		
		if( m_ControllerVSensitivitySelector )
			m_ControllerVSensitivitySelector.SetValue( m_ControllerVSensitivityOption.ReadValue(), false );
		if( m_ControllerHSensitivitySelector )
			m_ControllerHSensitivitySelector.SetValue( m_ControllerHSensitivityOption.ReadValue(), false );
		if( m_ControllerInvertSelector )
			m_ControllerInvertSelector.SetValue( m_ControllerInvertOption.GetIndex(), false );
		
		#ifdef PLATFORM_WINDOWS
		#ifndef PLATFORM_CONSOLE
		if( m_VSensitivitySelector )
			m_VSensitivitySelector.SetValue( m_VSensitivityOption.ReadValue(), false );
		if( m_HSensitivitySelector )
			m_HSensitivitySelector.SetValue( m_HSensitivityOption.ReadValue(), false );
		if( m_InvertSelector )
			m_InvertSelector.SetValue( m_InvertOption.GetIndex(), false );
		#endif
		#endif
	}
	
#ifdef PLATFORM_CONSOLE
	void UpdateKeyboard( int index )
	{
		m_Menu.OnChanged();
	}
#endif
	
#ifdef PLATFORM_CONSOLE
	void UpdateAimHelper( int index )
	{
		m_AimHelperOption.Switch();
		m_Menu.OnChanged();
	}
#endif
	
#ifdef PLATFORM_WINDOWS
#ifndef PLATFORM_CONSOLE
	void UpdateVerticalSensitivity( float value )
	{
		m_VSensitivityOption.WriteValue( value );
		m_Menu.OnChanged();
	}
	
	void UpdateHorizontalSensitivity( float value )
	{
		m_HSensitivityOption.WriteValue( value );
		m_Menu.OnChanged();
	}
	
	void UpdateInvertView( int index )
	{
		m_InvertOption.Switch();
		m_Menu.OnChanged();
	}
#endif
#endif
	
	void UpdateControllerVerticalSensitivity( float value )
	{
		m_ControllerVSensitivityOption.WriteValue( value );
		m_Menu.OnChanged();
	}
	
	void UpdateControllerHorizontalSensitivity( float value )
	{
		m_ControllerHSensitivityOption.WriteValue( value );
		m_Menu.OnChanged();
	}
	
	void UpdateControllerInvertView( int index )
	{
		m_ControllerInvertOption.Switch();
		m_Menu.OnChanged();
	}
	
	void ReloadOptions()
	{
		m_Menu.ReloadOptions();
	}
	
	void SetOptions( GameOptions options )
	{
		m_Options = options;
		#ifdef PLATFORM_CONSOLE
		m_KeyboardOption							= SwitchOptionsAccess.Cast( m_Options.GetOptionByType( AT_OPTIONS_MOUSE_AND_KEYBOARD ) );
		m_AimHelperOption							= SwitchOptionsAccess.Cast( m_Options.GetOptionByType( AT_OPTIONS_AIM_HELPER ) );
		#endif
		
		#ifdef PLATFORM_WINDOWS
		#ifndef PLATFORM_CONSOLE
		m_VSensitivityOption						= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_CONFIG_YAXIS ) );
		m_HSensitivityOption						= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_CONFIG_XAXIS ) );
		m_InvertOption								= SwitchOptionsAccess.Cast( m_Options.GetOptionByType( AT_CONFIG_YREVERSED ) );
		
		#endif
		#endif
		
		m_ControllerVSensitivityOption				= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_CONFIG_CONTROLLER_YAXIS ) );
		m_ControllerHSensitivityOption				= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_CONFIG_CONTROLLER_XAXIS ) );
		m_ControllerInvertOption					= SwitchOptionsAccess.Cast( m_Options.GetOptionByType( AT_CONFIG_CONTROLLER_REVERSED_LOOK ) );
		
		Revert();
	}
	
	void FillTextMap()
	{
		m_TextMap = new map<int, ref Param2<string, string>>;
		m_TextMap.Insert( AT_CONFIG_YAXIS, new Param2<string, string>( "#options_controls_vertical_sens", "#options_controls_vertical_sensitivity_desc" ) );
		m_TextMap.Insert( AT_CONFIG_XAXIS, new Param2<string, string>( "#options_controls_horizontal_sens", "#options_controls_horizontal_sensitivity_desc" ) );
		m_TextMap.Insert( AT_CONFIG_YREVERSED, new Param2<string, string>( "#options_controls_invert_vertical_view", "#options_controls_invert_vertical_view_desc" ) );
		
		#ifdef PLATFORM_PS4
		m_TextMap.Insert( AT_OPTIONS_MOUSE_AND_KEYBOARD, new Param2<string, string>( "#xbox_options_controls_mandk_contr", "#xbox_options_controls_mandk_contr_desc" ) );
		m_TextMap.Insert( AT_OPTIONS_AIM_HELPER, new Param2<string, string>( "#ps4_options_controls_aim_helper_contr", "#ps4_options_controls_aim_helper_contr_desc" ) );
		m_TextMap.Insert( AT_CONFIG_CONTROLLER_YAXIS, new Param2<string, string>( "#ps4_options_controls_vertical_sens_contr", "#ps4_options_controls_vertical_sens_contr_desc" ) );
		m_TextMap.Insert( AT_CONFIG_CONTROLLER_XAXIS, new Param2<string, string>( "#ps4_options_controls_horizontal_sens_contr", "#ps4_options_controls_horizontal_sens_contr_desc" ) );
		m_TextMap.Insert( AT_CONFIG_CONTROLLER_REVERSED_LOOK, new Param2<string, string>( "#ps4_options_controls_invert_vert_view_contr", "#ps4_options_controls_invert_vert_view_contr_desc" ) );
		#else 
		m_TextMap.Insert( AT_OPTIONS_MOUSE_AND_KEYBOARD, new Param2<string, string>( "#xbox_options_controls_mandk_contr", "#xbox_options_controls_mandk_contr_desc" ) );
		m_TextMap.Insert( AT_OPTIONS_AIM_HELPER, new Param2<string, string>( "#xbox_options_controls_aim_helper_contr", "#xbox_options_controls_aim_helper_contr_desc" ) );
		m_TextMap.Insert( AT_CONFIG_CONTROLLER_YAXIS, new Param2<string, string>( "#options_controls_vertical_sens_contr", "#options_controls_vertical_sens_contr_desc" ) );
		m_TextMap.Insert( AT_CONFIG_CONTROLLER_XAXIS, new Param2<string, string>( "#options_controls_horizontal_sens_contr", "#options_controls_horizontal_sens_contr_desc" ) );
		m_TextMap.Insert( AT_CONFIG_CONTROLLER_REVERSED_LOOK, new Param2<string, string>( "#options_controls_invert_vert_view_contr", "#options_controls_invert_vert_view_contr_desc" ) );
		#endif
	}
	
	//Coloring functions (Until WidgetStyles are useful)
	void ColorRed( Widget w )
	{
		SetFocus( w );
		if( w.IsInherited( ButtonWidget ) )
		{
			ButtonWidget button = ButtonWidget.Cast( w );
			button.SetTextColor( ARGB( 255, 255, 0, 0 ) );
			button.SetAlpha( 0.9 );
		}
	}
	
	void ColorWhite( Widget w, Widget enterW )
	{
		if( w.IsInherited( ButtonWidget ) )
		{
			ButtonWidget button = ButtonWidget.Cast( w );
			button.SetTextColor( ARGB( 255, 255, 255, 255 ) );
			button.SetAlpha( 0.75 );
		}
	}
}