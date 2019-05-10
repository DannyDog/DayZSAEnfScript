/*! Xbox menu */
class TitleScreenMenu extends UIScriptedMenu
{
	RichTextWidget m_TextPress;
	
	void TitleScreenMenu()
	{
		g_Game.SetGameState( DayZGameState.MAIN_MENU );
		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_START );
	}
	
	void ~TitleScreenMenu()
	{
	}
	
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("gui/layouts/xbox/day_z_title_screen.layout");
		
		MissionMainMenu mission = MissionMainMenu.Cast( g_Game.GetMission() );
		
		m_TextPress = RichTextWidget.Cast( layoutRoot.FindAnyWidget("InputPromptText") );
		if (m_TextPress)
		{
			string gamertag;
			GetGame().GetPlayerName(gamertag);
			
			#ifdef PLATFORM_XBOX
				m_TextPress.SetText("#dayz_game_press" + " " + "<image set=\"xbox_buttons\" name=\"A\" />" + "" + "#dayz_game_to_start");
			#endif
					
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
				m_TextPress.SetText("#ps4_dayz_game_press" + "" + "<image set=\"playstation_buttons\" name=\"" + confirm + "\" />" + "" + "#ps4_dayz_game_to_start");
			#endif
		}
		return layoutRoot;
	}
	
	override void OnShow()
	{
		if( g_Game.GetGameState() != DayZGameState.CONNECTING )
		{
			#ifdef PLATFORM_CONSOLE
				g_Game.GamepadCheck();
			#endif
		}
		
		SetWidgetAnimAlpha( m_TextPress );
	}
	
	override void OnHide()
	{
	}
	
	override void Update(float timeslice)
	{
		super.Update( timeslice );
		
		if( GetGame().GetInput().LocalPress("UAUISelect",false) )
		{
			#ifdef PLATFORM_WINDOWS
				EnterScriptedMenu(MENU_MAIN);
			#endif
			#ifdef PLATFORM_XBOX
				g_Game.GamepadCheck();
			#endif
		}
	}
}