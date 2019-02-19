class JsonControlMappingInfo
{
	int m_TabID;
	int m_TextWidgetID;
	string m_ButtonName;
	string m_InfoText;
}

class ControlsXbox extends UIScriptedMenu
{
	protected ImageWidget 	m_ControlsLayoutImage;
	protected const int 	TABS_COUNT = 4;
	protected ImageWidget 	m_tab_images[TABS_COUNT];
	protected TabberUI		m_TabScript;
	
	//============================================
	// ControlsXbox
	//============================================
	void ControlsXbox()
	{
		
	}
	
	void ~ControlsXbox()
	{
		PPEffects.SetBlurMenu( 0 );
	}
	
	void Back()
	{
		GetGame().GetUIManager().Back();
	}
	
	void DrawConnectingLines( int index )
	{
		ref array<ref JsonControlMappingInfo> control_mapping_info = new array<ref JsonControlMappingInfo>;
		ref array<ref array <ref JsonControlMappingInfo>> tab_array = new array<ref array <ref JsonControlMappingInfo>>;
		
		map<string, ref array<int>> button_marker_groups_unflitred = new map<string, ref array<int>>;
		map<string, ref array<int>> button_marker_groups = new map<string, ref array<int>>;
		
		float text_widget_pos_x, text_widget_pos_y;
		float text_widget_width, text_widget_height;
		float dot_pos_x, dot_pos_y;
		float dot_width, dot_height;
		float draw_pos_x, draw_pos_y;
		
		CanvasWidget canvas_widget = CanvasWidget.Cast( layoutRoot.FindAnyWidget("CanvasWidget_" + index) );
		control_mapping_info  = GetControlMappingInfo();
		
		for( int i = 0; i < m_TabScript.GetTabCount(); i++ )
		{
			tab_array.Insert( new array<ref JsonControlMappingInfo> );
			for( int j = 0; j < 20; j++ )
			{
				tab_array[i].Insert( NULL );
			}
		}
		
		// insert json info to array by index, so it is sorted
		for ( i = 0; i < control_mapping_info.Count(); i++ )
		{
			JsonControlMappingInfo info = control_mapping_info.Get( i );
			tab_array[info.m_TabID][info.m_TextWidgetID] = info;
		}
		
		// create group of buttons which are connected together with line
		for( int l = 0; l < control_mapping_info.Count(); l++ )
		{
			JsonControlMappingInfo info1 = control_mapping_info[l];
			string button_name = info1.m_ButtonName;
			int text_widget_id = info1.m_TextWidgetID;
			if( info1.m_TabID != index )
			{
				continue;
			}
			if( !button_marker_groups_unflitred.Contains( button_name) )
			{
				button_marker_groups_unflitred.Insert( button_name, new ref array<int> );
				button_marker_groups_unflitred.Get( button_name ).Insert( text_widget_id );
			}
			else
			{
				button_marker_groups_unflitred.Get( button_name ).Insert( text_widget_id );
			}
		}
		
		// we want groups which are bigger than 1
		for( l = 0; l < button_marker_groups_unflitred.Count(); l++ )
		{
			if( button_marker_groups_unflitred.GetElement( l ).Count() > 1 )
			{
				string key = button_marker_groups_unflitred.GetKey( l );
				button_marker_groups.Insert( button_marker_groups_unflitred.GetKey( l ), button_marker_groups_unflitred.Get( key ) );
			}
		}
		
		Widget controls_image;
		// hide all button markers
		#ifdef PLATFORM_XBOX
			controls_image = layoutRoot.FindAnyWidget( "XboxControlsImage" );
		#else
		#ifdef PLATFORM_PS4
			controls_image = layoutRoot.FindAnyWidget( "PSControlsImage" );
		#endif
		#endif
		
		Widget child = controls_image.GetChildren();
		child.Show(false);
		while( child.GetSibling() )
		{
			child = child.GetSibling();
			child.Show(false);
		}
		Widget panel_widget;
		Widget button_marker_widget;
		
		for( l = 0; l < tab_array[index].Count(); l++ )
		{
			panel_widget = layoutRoot.FindAnyWidget( "PanelWidget" + l );
			if( tab_array[index][l] != NULL )
			{
				TextWidget text_widget = TextWidget.Cast( panel_widget.FindAnyWidget( "TextWidget" + l ) );
				string key_prefix;
				#ifdef PLATFORM_XBOX
					key_prefix = "xb_button_marker_";
				#else
				#ifdef PLATFORM_PS4
					key_prefix = "ps_button_marker_";
				#endif
				#endif
				button_marker_widget = layoutRoot.FindAnyWidget( key_prefix + tab_array[index][l].m_ButtonName );
				text_widget.SetText( tab_array[index][l].m_InfoText );
				panel_widget.Show( true );
				button_marker_widget.Show( true );
				panel_widget.Update();
				if( !button_marker_groups.Contains(tab_array[index][l].m_ButtonName ))
				{
					panel_widget.GetScreenPos( text_widget_pos_x, text_widget_pos_y );
					panel_widget.GetScreenSize( text_widget_width,text_widget_height );
					
					button_marker_widget.GetScreenPos( dot_pos_x, dot_pos_y );
					button_marker_widget.GetScreenSize( dot_width, dot_height );
					
					draw_pos_y = text_widget_pos_y + text_widget_height / 2;
					if( l < 10 )
					{
						draw_pos_x = text_widget_pos_x + text_widget_width - 1;
					}
					else
					{
						draw_pos_x = text_widget_pos_x;
					}
					canvas_widget.DrawLine( draw_pos_x, draw_pos_y, dot_pos_x+dot_width/2, draw_pos_y, 2, ARGBF( 0.6, 1, 1, 1 ) );
					canvas_widget.DrawLine( dot_pos_x+dot_width/2, draw_pos_y, dot_pos_x+dot_width/2, dot_pos_y+dot_height/2, 2, ARGBF( 0.6, 1, 1, 1 ) );	
				}
				
			}
			else
			{
				panel_widget.Show( false );
			}
			panel_widget.Update();
		}
		
		// draw connecting lines 
		for( l = 0; l <  button_marker_groups.Count(); l++ )
		{
			text_widget_pos_x = 0;
			text_widget_pos_y = 0;
			text_widget_width = 0;
			text_widget_height = 0;
			float group_point_x = 0, group_point_y = 0;
			float first_x = 0, first_y = 0;
			
			ref array<int> element = button_marker_groups.GetElement( l );
			string key_name = button_marker_groups.GetKey( l );
			#ifdef PLATFORM_XBOX
				key_prefix = "xb_button_marker_";
			#else
			#ifdef PLATFORM_PS4
				key_prefix = "ps_button_marker_";
			#endif
			#endif
			button_marker_widget = layoutRoot.FindAnyWidget( key_prefix + key_name );
			
			for( int g = 0; g < element.Count(); g++ )
			{
				panel_widget = layoutRoot.FindAnyWidget( "PanelWidget" + element[g] );
				
				panel_widget.GetScreenPos( text_widget_pos_x, text_widget_pos_y );
				panel_widget.GetScreenSize( text_widget_width, text_widget_height );
				
				if( g == 0 )
				{
					if( element[0] < 10 )
					{
						first_x = text_widget_pos_x + text_widget_width +50;
					}
					else
					{
						first_x = text_widget_pos_x - 50;
					}
					first_y = text_widget_pos_y + text_widget_height/2;
					
				}
				group_point_x += text_widget_pos_x;
				group_point_y += text_widget_pos_y;
				if( element[0] < 10 )
				{
					canvas_widget.DrawLine( text_widget_pos_x + text_widget_width - 1, text_widget_pos_y + text_widget_height/2, text_widget_pos_x + text_widget_width +50, text_widget_pos_y + text_widget_height/2, 2, ARGBF( 0.6, 1, 1, 1 ) );
				}
				else
				{
					canvas_widget.DrawLine( text_widget_pos_x, text_widget_pos_y + text_widget_height/2, text_widget_pos_x - 50, text_widget_pos_y + text_widget_height/2, 2, ARGBF( 0.6, 1, 1, 1 ) );
				}
			}
			if( element[0] < 10 )
			{
				group_point_x = group_point_x/element.Count() + text_widget_width + 50;
			}
			else
			{
				group_point_x = group_point_x/element.Count() - 50;
			}
			group_point_y = group_point_y/element.Count() + text_widget_height/2;
			
			button_marker_widget.GetScreenPos( dot_pos_x, dot_pos_y );
			button_marker_widget.GetScreenSize( dot_width, dot_height );
			
			canvas_widget.DrawLine( group_point_x, group_point_y, dot_pos_x+dot_width/2, group_point_y, 2, ARGBF( 0.6, 1, 1, 1 ) );
			canvas_widget.DrawLine( dot_pos_x+dot_width/2, group_point_y, dot_pos_x+dot_width/2, dot_pos_y, 2, ARGBF( 0.6, 1, 1, 1 ) );
			
			if( element[0] < 10 )
			{
				canvas_widget.DrawLine( first_x, first_y, text_widget_pos_x + text_widget_width +50, text_widget_pos_y + text_widget_height/2, 2, ARGBF( 0.6, 1, 1, 1 ) );
			}
			else
			{
				canvas_widget.DrawLine( first_x, first_y, text_widget_pos_x - 50, text_widget_pos_y + text_widget_height/2, 2, ARGBF( 0.6, 1, 1, 1 ) );
			}
		}
	}
	
	protected array<ref JsonControlMappingInfo> GetControlMappingInfo()
	{
		array<ref JsonControlMappingInfo> control_mapping_info = new array<ref JsonControlMappingInfo>;
		
		string file_path =	"Xbox/PageDataControlIer.json";
		#ifdef PLATFORM_PS4
			file_path =	"Ps4/PageDataControlIer.json";
		#endif
		FileHandle file_handle = OpenFile(file_path, FileMode.READ);
		JsonSerializer js = new JsonSerializer();
		
		string js_error = "";
		string line_content = "";
		string content = "";
		if ( file_handle )
		{
			while ( FGets( file_handle,  line_content ) >= 0 )
			{
				content += line_content;
			}
			CloseFile( file_handle );
			
			if ( js.ReadFromString( control_mapping_info, content, js_error ) )
			{
				return control_mapping_info;
			}
			else
			{
				Print("JSON ERROR => [ControlMappingInfo.json]: "+ js_error);
				DumpStack();
			}
		}
		
		return control_mapping_info;
	}
	
	//============================================
	// Init
	//============================================
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "gui/layouts/xbox/control_mapping_info_screen.layout" );
		
		layoutRoot.FindAnyWidget("Tabber").GetScript( m_TabScript );
		
		#ifdef PLATFORM_XBOX
			layoutRoot.FindAnyWidget("XboxControlsImage").Show( true );
		#else
		#ifdef PLATFORM_PS4
			ImageWidget toolbar_b = layoutRoot.FindAnyWidget( "BackIcon" );
			toolbar_b.LoadImageFile( 0, "set:playstation_buttons image:circle" );
			layoutRoot.FindAnyWidget("PSControlsImage").Show( true );
		#endif
		#endif
		m_tab_images[0] = ImageWidget.Cast( layoutRoot.FindAnyWidget("MovementTabBackdropImageWidget") );
		m_tab_images[1] = ImageWidget.Cast( layoutRoot.FindAnyWidget("WeaponsAndActionsBackdropImageWidget") );
		m_tab_images[2] = ImageWidget.Cast( layoutRoot.FindAnyWidget("InventoryTabBackdropImageWidget") );
		m_tab_images[3] = ImageWidget.Cast( layoutRoot.FindAnyWidget("MenusTabBackdropImageWidget") );
		PPEffects.SetBlurMenu( 0.6 );
		DrawConnectingLines( 0 );
		return layoutRoot;
	}
	
	override void Update( float timeslice )
	{
		if( GetGame().GetInput().GetActionDown("UAUITabLeft",false) )
		{
			m_TabScript.PreviousTab();
			DrawConnectingLines( m_TabScript.GetSelectedIndex() );
		}
		
		//RIGHT BUMPER - TAB RIGHT
		if( GetGame().GetInput().GetActionDown("UAUITabRight",false) )
		{
			m_TabScript.NextTab();
			DrawConnectingLines( m_TabScript.GetSelectedIndex() );
		}
		
		if( GetGame().GetInput().GetActionDown("UAUIBack",false) )
		{
			Back();
		}
	}
}
