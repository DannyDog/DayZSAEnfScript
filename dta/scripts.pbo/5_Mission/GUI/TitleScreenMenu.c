/*! Xbox menu */
class TitleScreenMenu extends UIScriptedMenu
{
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
		
		RichTextWidget text_widget = RichTextWidget.Cast( layoutRoot.FindAnyWidget("InputPromptText") );
		if (text_widget)
		{
			string gamertag;
			GetGame().GetPlayerName(gamertag);
			
			#ifdef PLATFORM_XBOX
					text_widget.SetText("#dayz_game_press" + " " + "<image set=\"xbox_buttons\" name=\"A\" />" + "" + "#dayz_game_to_start");
			#endif
					
			#ifdef PLATFORM_PS4
					text_widget.SetText("#dayz_game_press" + " " + "<image set=\"playstation_buttons\" name=\"cross\" />" + "" + "#dayz_game_to_start");
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
	}
	
	override void OnHide()
	{
	}
	
	override void Update(float timeslice)
	{
		if( GetGame().GetInput().GetActionDown("UAUISelect",false) )
		{
			#ifdef PLATFORM_WINDOWS
				EnterScriptedMenu(MENU_MAIN);
			#endif
			#ifdef PLATFORM_CONSOLE
				g_Game.GamepadCheck();
			#endif
		}
	}
}