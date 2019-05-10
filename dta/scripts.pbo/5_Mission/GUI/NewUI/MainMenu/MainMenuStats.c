class MainMenuStats extends ScriptedWidgetEventHandler
{
	protected Widget m_Root;
	protected RichTextWidget m_TemRTextContent;
	
	void MainMenuStats( Widget root )
	{
		m_Root = root;
		m_TemRTextContent = RichTextWidget.Cast( m_Root.FindAnyWidget( "temp_text_content" ) );
	}
		
	void ShowStats()
	{
		m_Root.Show( true );
		UpdateStats();
	}
	
	void HideStats()
	{
		m_Root.Show( false );
	}
	
	void UpdateStats()
	{
		PlayerBase player;
		MissionMainMenu mission_main_menu = MissionMainMenu.Cast( GetGame().GetMission() );
		
		#ifdef PLATFORM_WINDOWS
			player = mission_main_menu.GetIntroScenePC().GetIntroCharacter().GetCharacterObj();
		#endif
		#ifdef PLATFORM_CONSOLE
			player = mission_main_menu.GetIntroSceneXbox().GetIntroSceneCharacter();
		#endif
		
		if ( player )
		{
			float stat_value;
			string stat_text;
			
			stat_value = player.StatGet( AnalyticsManagerServer.STAT_PLAYTIME );
			stat_text += AnalyticsManagerServer.STAT_PLAYTIME + " = " + GetTimeString( stat_value );
			
			stat_value = player.StatGet( AnalyticsManagerServer.STAT_PLAYERS_KILLED );
			stat_text += "<br></br>" + AnalyticsManagerServer.STAT_PLAYERS_KILLED + " = " + GetValueString( stat_value );
			
			stat_value = player.StatGet( AnalyticsManagerServer.STAT_INFECTED_KILLED );
			stat_text += "<br></br>" + AnalyticsManagerServer.STAT_INFECTED_KILLED + " = " + GetValueString( stat_value );
			
			stat_value = player.StatGet( AnalyticsManagerServer.STAT_DISTANCE );
			stat_text += "<br></br>" + AnalyticsManagerServer.STAT_DISTANCE + " = " + GetDistanceString( stat_value );
			
			stat_value = player.StatGet( AnalyticsManagerServer.STAT_LONGEST_SURVIVOR_HIT );
			stat_text += "<br></br>" + AnalyticsManagerServer.STAT_LONGEST_SURVIVOR_HIT + " = " + GetDistanceString( stat_value, true );
			
			m_TemRTextContent.SetText( stat_text );
		}
	}
	
	protected string GetTimeString( float total_time )
	{
		if( total_time < 0 )
			return "not set yet";
	
		int time_seconds = total_time; 								//convert total time to int
		string time_string;
		
		int hours = time_seconds / 3600;
		if ( hours > 0 )
		{
			time_string += GetValueString( hours ) + "h";			//hours
		}
		
		time_string += " ";											//separator
		
		int minutes = ( time_seconds % 3600 ) / 60;
		time_string += GetValueString( minutes ) + "m";			//minutes
		
		return time_string;
	}
	
	protected string GetDistanceString( float total_distance, bool meters_only = false )
	{
		if( total_distance < 0 )
			return "not set yet";
	
		int distance_meters = total_distance;
		string distance_string;
		
		int kilometers = distance_meters / 1000;
		if ( kilometers > 0 && !meters_only )
		{
			distance_string += GetValueString( kilometers ) + " km";			//kilometers
			distance_string += " ";												//separator
		}
		else
		{
			distance_string += GetValueString( distance_meters ) + " m";		//meters
		}
		
		return distance_string;
	}
	
	protected string GetValueString( float total_value )
	{
		if( total_value < 0 )
			return "not set yet";
	
		int value = total_value;
		string out_string;
		
		if ( value >= 1000 )
		{
			string value_string = value.ToString();
			
			int count;		
			int first_length = value_string.Length() % 3;		//calculate position of the first separator
			if ( first_length > 0 )
			{
				count = 3 - first_length;
			}
			
			for ( int i = 0; i < value_string.Length(); ++i )
			{
				out_string += value_string.Get( i );
				count ++;
				
				if ( count >= 3 )
				{
					out_string += " ";			//separator
					count = 0;
				}
			}
		}
		else
		{
			out_string = value.ToString();
		}
		
		return out_string;
	}
}