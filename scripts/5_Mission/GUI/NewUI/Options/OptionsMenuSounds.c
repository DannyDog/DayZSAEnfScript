class OptionsMenuSounds extends ScriptedWidgetEventHandler
{
	protected Widget					m_Root;
	
	protected Widget					m_SettingsRoot;
	protected Widget					m_DetailsRoot;
	protected TextWidget				m_DetailsLabel;
	protected RichTextWidget			m_DetailsText;
	
	protected ref NumericOptionsAccess	m_MasterOption;
	protected ref NumericOptionsAccess	m_EffectsOption;
	protected ref NumericOptionsAccess	m_VOIPOption;
	protected ref NumericOptionsAccess	m_MusicOption;
	
	protected ref OptionSelectorSlider	m_MasterSelector;
	protected ref OptionSelectorSlider	m_EffectsSelector;
	protected ref OptionSelectorSlider	m_VOIPSelector;
	protected ref OptionSelectorSlider	m_MusicSelector;
	
	protected GameOptions				m_Options;
	protected OptionsMenu			m_Menu;
	
	protected ref map<int, ref Param2<string, string>> m_TextMap;
	
	void OptionsMenuSounds( Widget parent, Widget details_root, GameOptions options, OptionsMenu menu )
	{
		m_Root					= GetGame().GetWorkspace().CreateWidgets( GetLayoutName(), parent );
		
		m_DetailsRoot			= details_root;
		m_DetailsLabel			= TextWidget.Cast( m_DetailsRoot.FindAnyWidget( "details_label" ) );
		m_DetailsText			= RichTextWidget.Cast( m_DetailsRoot.FindAnyWidget( "details_content" ) );
		
		m_Options				= options;
		m_Menu					= menu;
		
		m_MasterOption			= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_OPTIONS_MASTER_VOLUME ) );
		m_EffectsOption			= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_OPTIONS_EFFECTS_SLIDER ) );
		m_VOIPOption			= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_OPTIONS_VON_SLIDER ) );
		m_MusicOption			= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_OPTIONS_MUSIC_SLIDER ) );
		
		m_Root.FindAnyWidget( "master_setting_option" ).SetUserID( AT_OPTIONS_MASTER_VOLUME );
		m_Root.FindAnyWidget( "effects_setting_option" ).SetUserID( AT_OPTIONS_EFFECTS_SLIDER );
		m_Root.FindAnyWidget( "voip_setting_option" ).SetUserID( AT_OPTIONS_VON_SLIDER );
		m_Root.FindAnyWidget( "music_setting_option" ).SetUserID( AT_OPTIONS_MUSIC_SLIDER );
		
		FillTextMap();
		
		m_MasterSelector		= new OptionSelectorSlider( m_Root.FindAnyWidget( "master_setting_option" ), m_MasterOption.ReadValue(), this, false, m_MasterOption.GetMin(), m_MasterOption.GetMax() );
		m_EffectsSelector		= new OptionSelectorSlider( m_Root.FindAnyWidget( "effects_setting_option" ), m_EffectsOption.ReadValue(), this, false, m_EffectsOption.GetMin(), m_EffectsOption.GetMax() );
		m_VOIPSelector			= new OptionSelectorSlider( m_Root.FindAnyWidget( "voip_setting_option" ), m_VOIPOption.ReadValue(), this, false, m_VOIPOption.GetMin(), m_VOIPOption.GetMax() );
		m_MusicSelector			= new OptionSelectorSlider( m_Root.FindAnyWidget( "music_setting_option" ), m_MusicOption.ReadValue(), this, false, m_MusicOption.GetMin(), m_MusicOption.GetMax() );
		
		m_MasterSelector.m_OptionChanged.Insert( UpdateMaster );
		m_EffectsSelector.m_OptionChanged.Insert( UpdateEffects );
		m_VOIPSelector.m_OptionChanged.Insert( UpdateVOIP );
		m_MusicSelector.m_OptionChanged.Insert( UpdateMusic );
		
		float x, y, y2;
		m_Root.FindAnyWidget( "sound_settings_scroll" ).GetScreenSize( x, y );
		m_Root.FindAnyWidget( "sound_settings_root" ).GetScreenSize( x, y2 );
		int f = ( y2 > y );
		m_Root.FindAnyWidget( "sound_settings_scroll" ).SetAlpha( f );
		
		m_Root.SetHandler( this );
	}
	
	string GetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
			return "gui/layouts/new_ui/options/xbox/sound_tab.layout";
		#else
		#ifdef PLATFORM_WINDOWS
			return "gui/layouts/new_ui/options/pc/sound_tab.layout";
		#endif
		#endif
	}
	
	void Focus()
	{
		#ifdef PLATFORM_CONSOLE
			SetFocus( m_MasterSelector.GetParent() );
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
	
	override bool OnFocus( Widget w, int x, int y )
	{
		OptionsMenu menu = OptionsMenu.Cast( GetGame().GetUIManager().GetMenu() );
		if( menu )
			menu.OnFocus( w, x, y );
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
				return true;
			}
		}
		m_DetailsRoot.Show( false );
		return ( w != null );
	}
	
	bool IsChanged()
	{
		return false;
	}
	
	void Apply()
	{
		
	}
	
	void Revert()
	{
		if( m_MasterOption )
			m_MasterSelector.SetValue( m_MasterOption.ReadValue() );
		if( m_EffectsOption )
			m_EffectsSelector.SetValue( m_EffectsOption.ReadValue() );
		if( m_VOIPOption )
			m_VOIPSelector.SetValue( m_VOIPOption.ReadValue() );
		if( m_MusicOption )
			m_MusicSelector.SetValue( m_MusicOption.ReadValue() );
	}
	
	void ReloadOptions()
	{
		m_Menu.ReloadOptions();
	}
	
	void SetOptions( GameOptions options )
	{
		m_Options = options;
		
		m_MasterOption			= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_OPTIONS_MASTER_VOLUME ) );
		m_EffectsOption			= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_OPTIONS_EFFECTS_SLIDER ) );
		m_VOIPOption			= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_OPTIONS_VON_SLIDER ) );
		m_MusicOption			= NumericOptionsAccess.Cast( m_Options.GetOptionByType( AT_OPTIONS_MUSIC_SLIDER ) );
		
		Revert();
	}
	
	void UpdateMaster( float value )
	{
		m_MasterOption.WriteValue( value );
		m_Menu.OnChanged();
	}
	
	void UpdateEffects( float value )
	{
		m_EffectsOption.WriteValue( value );
		m_Menu.OnChanged();
	}
	
	void UpdateVOIP( float value )
	{
		m_VOIPOption.WriteValue( value );
		m_Menu.OnChanged();
	}
	
	void UpdateMusic( float value )
	{
		m_MusicOption.WriteValue( value );
		m_Menu.OnChanged();
	}
	
	void FillTextMap()
	{
		m_TextMap = new map<int, ref Param2<string, string>>;
		#ifdef PLATFORM_PS4
		m_TextMap.Insert( AT_OPTIONS_MASTER_VOLUME, new Param2<string, string>( "#ps4_options_sound_master_volume", "#ps4_options_sound_master_volume_desc" ) );
		m_TextMap.Insert( AT_OPTIONS_EFFECTS_SLIDER, new Param2<string, string>( "#ps4_options_sound_effects_volume", "#ps4_options_sound_effects_volume_desc" ) );
		m_TextMap.Insert( AT_OPTIONS_VON_SLIDER, new Param2<string, string>( "#ps4_options_sound_VOIP_volume", "#ps4_options_sound_VOIP_volume_desc" ) );
		m_TextMap.Insert( AT_OPTIONS_MUSIC_SLIDER, new Param2<string, string>( "#ps4_options_sound_music_volume", "#ps4_options_sound_music_volume_desc" ) );
		#else
		m_TextMap.Insert( AT_OPTIONS_MASTER_VOLUME, new Param2<string, string>( "#options_sound_master_volume", "#options_sound_master_volume_desc" ) );
		m_TextMap.Insert( AT_OPTIONS_EFFECTS_SLIDER, new Param2<string, string>( "#options_sound_effects_volume", "#options_sound_effects_volume_desc" ) );
		m_TextMap.Insert( AT_OPTIONS_VON_SLIDER, new Param2<string, string>( "#options_sound_VOIP_volume", "#options_sound_VOIP_volume_desc" ) );
		m_TextMap.Insert( AT_OPTIONS_MUSIC_SLIDER, new Param2<string, string>( "#options_sound_music_volume", "#options_sound_music_volume_desc" ) ); 
		#endif
	}
}