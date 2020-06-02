class ServerBrowserTabConsolePages extends ServerBrowserTab
{
	private bool m_IsFilterChanged;
	private bool m_IsFilterFocused;
	
	private Widget m_WidgetNavFilters;
	private Widget m_WidgetNavServers;
	
	protected Widget								m_ButtonPageLeftImg;
	protected Widget								m_ButtonPageRightImg;
	
	protected int									m_PreviousPage;
	protected int									m_TotalServersCount;
	protected int									m_PageStartNum;
	protected int									m_PageEndNum;
	protected int									m_PagesCount;
	protected int									m_ServersEstimateCount;
	protected int									m_TimeLastServerRefresh;
	protected int									m_TimeLastServerRefreshHoldButton;
	
	protected Widget								m_PnlPagesPanel;
	protected TextWidget							m_PnlPagesLoadingText;
	protected ref array<ref ServerBrowserEntry>		m_ServerListEntiers;
	
	protected override void Construct( Widget parent, ServerBrowserMenuNew menu, TabType type )
	{
		m_Root = GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/server_browser/xbox/server_browser_tab_console_pages.layout", parent );
		
		m_ServerListScroller	= ScrollWidget.Cast( m_Root.FindAnyWidget( "server_list_scroller" ) );
		m_ServerList			= SpacerBaseWidget.Cast( m_ServerListScroller.FindAnyWidget( "server_list_content" ) );
		m_ServerListScroller.VScrollToPos01( 0 );
		
		m_ServerListEntiers		= new array<ref ServerBrowserEntry>;
		m_EntryWidgets			= new map<string, ref ServerBrowserEntry>;
		m_EntriesSorted			= new map<ESortType, ref array<ref GetServersResultRow>>;
		
		m_EntriesSorted[ESortType.HOST] = new array<ref GetServersResultRow>;
		m_EntriesSorted[ESortType.POPULATION] = new array<ref GetServersResultRow>;
		
		m_Menu					= menu;
		m_TabType				= type;
		
		m_ApplyFilter			= m_Root.FindAnyWidget( "apply_filter_button" );
		m_ResetFilters			= m_Root.FindAnyWidget( "reset_filter_button" );
		m_RefreshList			= m_Root.FindAnyWidget( "refresh_list_button" );
		m_FiltersChanged		= m_Root.FindAnyWidget( "unapplied_filters_notify" );
		m_HostSort				= m_Root.FindAnyWidget( "server_list_content_header_host" );
		m_TimeSort				= m_Root.FindAnyWidget( "server_list_content_header_time" );
		m_PopulationSort		= m_Root.FindAnyWidget( "server_list_content_header_population" );
		m_SlotsSort				= m_Root.FindAnyWidget( "server_list_content_header_slots" );
		m_PingSort				= m_Root.FindAnyWidget( "server_list_content_header_ping" );
		m_FilterSearchText		= m_Root.FindAnyWidget( "search_name_button" );
		m_FilterSearchTextBox	= m_Root.FindAnyWidget( "search_name_setting_option" );
		m_LoadingText			= TextWidget.Cast( m_Root.FindAnyWidget( "loading_servers_info" ) );
		m_WidgetNavFilters		= m_Root.FindAnyWidget( "filters_root_nav_wrapper" );
		m_WidgetNavServers		= m_Root.FindAnyWidget( "server_list_root_nav_wrapper" );
		
		m_BtnPagePrev			= ButtonWidget.Cast( m_Root.FindAnyWidget( "servers_navigation_prev" ) ) ;
		m_BtnPageNext			= ButtonWidget.Cast( m_Root.FindAnyWidget( "servers_navigation_next" ) ) ;
		
		#ifdef PLATFORM_PS4
			m_ButtonPageLeftImg = m_Root.FindAnyWidget( "servers_navigation_page_prev_icon_ps4" );
			m_ButtonPageRightImg = m_Root.FindAnyWidget( "servers_navigation_page_next_icon_ps4" );
			m_Root.FindAnyWidget( "servers_navigation_page_prev_icon_xbox" ).Show( false );
			m_Root.FindAnyWidget( "servers_navigation_page_next_icon_xbox" ).Show( false );
		#else
			m_ButtonPageLeftImg = m_Root.FindAnyWidget( "servers_navigation_page_prev_icon_xbox" );
			m_ButtonPageRightImg = m_Root.FindAnyWidget( "servers_navigation_page_next_icon_xbox" );
			m_Root.FindAnyWidget( "servers_navigation_page_prev_icon_ps4" ).Show( false );
			m_Root.FindAnyWidget( "servers_navigation_page_next_icon_ps4" ).Show( false );
		#endif
		
		ShowHideConsoleWidgets();		
		
		m_Filters				= new ServerBrowserFilterContainer( m_Root.FindAnyWidget( "filters_content" ), this );
		
		m_PnlPagesPanel			= m_Root.FindAnyWidget( "servers_navigation_spacer" );
		m_PreviousPage			= 1;
		SetCurrentPage( 1 );
		m_PnlPagesPanel.Show( true );
		m_LoadingFinished		= true;
		
		m_Filters.OnSortChanged( m_Filters.m_SortingFilter.GetValue() );
		SetFocusFilters();
		UpdatePageButtons();
		
		m_Root.SetHandler( this );
		m_FilterSearchTextBox.SetHandler( this );
	}
	
	void ShowHideConsoleWidgets()
	{
		bool is_xbox = true;
		
#ifdef PLATFORM_PS4
		is_xbox = false;
#endif
		
		m_Root.FindAnyWidget( "filters_button_wrapper" ).Show( GetGame().GetInput().IsEnabledMouseAndKeyboard() );
		
		m_Root.FindAnyWidget( "filters_root_nav_img_lb_xbox" ).Show( is_xbox );
		m_Root.FindAnyWidget( "filters_root_nav_img_rb_xbox" ).Show( is_xbox );
		m_Root.FindAnyWidget( "server_list_root_nav_img_lb_xbox" ).Show( is_xbox );
		m_Root.FindAnyWidget( "server_list_root_nav_img_rb_xbox" ).Show( is_xbox );
		
		m_Root.FindAnyWidget( "filters_root_nav_img_l1_ps4" ).Show( !is_xbox );
		m_Root.FindAnyWidget( "filters_root_nav_img_r1_ps4" ).Show( !is_xbox );
		m_Root.FindAnyWidget( "server_list_root_nav_img_l1_ps4" ).Show( !is_xbox );
		m_Root.FindAnyWidget( "server_list_root_nav_img_r1_ps4" ).Show( !is_xbox );
	}
	
	override void OnLoadServersAsyncConsole( GetServersResult result_list, EBiosError error, string response )
	{
		//Print("m_NumServers: "+ result_list.m_NumServers +" m_Pages: "+ result_list.m_Pages + " m_Page: "+ result_list.m_Page);
		//string smg = "m_NumServers: "+ result_list.m_NumServers +" m_Pages: "+ result_list.m_Pages + " m_Page: "+ result_list.m_Page +" response: "+ response +" error: "+ error;
		//m_LoadingText.SetText( smg );
		
		if ( error != EBiosError.OK )
		{
			m_LoadingText.SetText( "Error code: " + error );
			m_Menu.SetServersLoadingTab( TabType.NONE );
			m_LoadingFinished = true;
			SetFocusFilters();
			return;
		}
				
		m_PagesCount = result_list.m_Pages;
		//m_CurrentPageNum = result_list.m_Page;
		m_TotalServersCount = result_list.m_NumServers;
		
		if( m_PagesCount > 0 )
		{
			LoadEntries( result_list.m_Page, result_list.m_Results );
		}
		else
		{
			SetFocusFilters();
		}
		
		OnLoadServersAsyncFinished();
		UpdatePageButtons();
	}
	
	void OnLoadServersAsyncFinished()
	{
		string msg = "#servers_found: " + m_TotalServersCount;
		if ( m_TotalServersCount == 0 )
		{
			msg = "#server_browser_tab_unable_to_get_server";
		}
		m_LoadingText.SetText( msg );
		m_LoadingFinished = true;
		
		m_Menu.SetServersLoadingTab( TabType.NONE );
	}
	
	void LoadEntries( int cur_page_index , GetServersResultRowArray page_entries )
	{
		if( !m_Menu || m_Menu.GetServersLoadingTab() != m_TabType )
		{
			return;
		}
		if( page_entries )
		{
			int index = 0;
			
			foreach( GetServersResultRow result : page_entries )
			{
				m_TotalLoadedServers++;
								
				if( PassFilter( result ) )
				{
					ServerBrowserEntry entry = GetServerEntryByIndex( index );
					index++;
					string server_id = result.m_HostIp + ":" + result.m_HostPort;
					
					entry.FillInfo( result );
					
					entry.SetFavorite( m_Menu.IsFavorited( server_id ) );
										
					m_EntryWidgets.Insert( server_id, entry );				
					m_EntriesSorted[m_SortType].Insert( result );
				}
				
				if( !m_Menu || m_Menu.GetServersLoadingTab() != m_TabType )
					return;
			}
			
			m_ServerList.Update();
		}
		SetFocusServers();
	}
	
	protected ServerBrowserEntry GetServerEntryByIndex( int index )
	{
		ServerBrowserEntry entry;
		
		if ( index >= 0 )
		{
			if ( index < m_ServerListEntiers.Count() )
			{
				entry = m_ServerListEntiers[index];
			}
			else
			{
				entry = new ServerBrowserEntry( m_ServerList, index, this );				
				m_ServerListEntiers.Insert(entry);
			}
		}
		else
		{
			return null;
		}
		
		entry.Show( true );
		
		return entry;
	}
	
	override void OnFilterFocus( Widget w )
	{
		super.OnFilterFocus( w );
		
		//ColorHighlight( w );
	}
	
	override void OnFilterChanged()
	{
		m_IsFilterChanged = true;
	}
	
	bool CanRefreshServerList()
	{
		if ( m_LoadingFinished )
		{
			return true;
		}
				
		return false;
	}
	
	override void RefreshList()
	{
		if ( CanRefreshServerList() )
		{
			for ( int i = 0; i < m_ServerListEntiers.Count(); i++ )
			{
				m_ServerListEntiers[i].Show(false);
			}
			
			for ( int j = 0; j < m_EntriesSorted.Count(); j++ )
			{
				array<ref GetServersResultRow> result_rows = m_EntriesSorted.GetElement(j);
				
				if ( result_rows )
				{
					result_rows.Clear();
				}
			}
			
			m_IsFilterChanged = false;
			m_Filters.SaveFilters();
			
			super.RefreshList();
			
			m_ServerListScroller.VScrollToPos01( 0 );
			
			m_LoadingText.SetText( "#dayz_game_loading" );			
		}
	}
	
	override void ResetFilters()
	{
		super.ResetFilters();
		
		m_IsFilterChanged = false;
	}
	
	override void ApplyFilters()
	{
		if ( m_IsFilterChanged )
		{
			SetCurrentPage(1);
		}
		
		m_IsFilterChanged = false;
		m_CurrentFilterInput = m_Filters.GetFilterOptionsConsoles();
		RefreshList();
	}
	
	override void OnFilterFocusLost( Widget w )
	{
		super.OnFilterFocusLost( w );
	}
	
	override void PressA()
	{
		
	}
	
	override void PressX()
	{
		if ( (GetGame().GetTime() - m_TimeLastServerRefresh) > 1000 )
		{
			m_TimeLastServerRefresh = GetGame().GetTime();
			
			if ( m_IsFilterChanged )
			{
				SetCurrentPage(1);
			}
			
			RefreshList();
		}
		
	}
	
	override void PressY()
	{
		switch( m_SelectedPanel )
		{
			case SelectedPanel.BROWSER:
			{
				if( m_SelectedServer )
				{
					m_Menu.ServerListFocus( true, m_SelectedServer.ToggleFavorite() );
				}
				break;
			}
			case SelectedPanel.FILTERS:
			{
				if( m_Filters )
					m_Filters.ResetFilters();
				break;
			}
		}
	}
	
	override void Left()
	{
		if ( !m_IsFilterFocused )
		{
			int curr_page = GetCurrentPage();
			m_PreviousPage = curr_page;
			if ( curr_page > 1 )
			{
				SetCurrentPage( curr_page - 1 );
				UpdatePageButtons();
			}
		}
	}
	
	override void LeftHold()
	{
		if ( !m_IsFilterFocused )
		{
			if ( (GetGame().GetTime() - m_TimeLastServerRefreshHoldButton) > 100 )
			{
				m_TimeLastServerRefreshHoldButton = GetGame().GetTime();
				Left();
			}
		}		
	}
	
	override void LeftRelease()
	{
		if ( !m_IsFilterFocused && GetCurrentPage() != m_PreviousPage )
		{
			RefreshList();
		}
	}
	
	override void Right()
	{
		if ( !m_IsFilterFocused )
		{
			int curr_page = GetCurrentPage();
			m_PreviousPage = curr_page;
			if ( curr_page < m_PagesCount )
			{
				SetCurrentPage( curr_page + 1 );
				UpdatePageButtons();
			}
		}
	}
	
	override void RightHold()
	{
		if ( !m_IsFilterFocused )
		{
			if ( (GetGame().GetTime() - m_TimeLastServerRefreshHoldButton) > 100 )
			{				
				m_TimeLastServerRefreshHoldButton = GetGame().GetTime();
				Right();
			}
		}
	}
	
	override void RightRelease()
	{
		if ( !m_IsFilterFocused && GetCurrentPage() != m_PreviousPage )
		{
			RefreshList();
		}
	}
	
	override void PressSholderLeft()
	{
		if ( m_IsFilterFocused )
		{
			SetFocusServers();
		}
		else
		{
			SetFocusFilters();
		}
	}
	
	override void PressSholderRight()
	{
		if ( m_IsFilterFocused )
		{
			SetFocusServers();
		}
		else
		{
			SetFocusFilters();
		}
	}
	override void Focus()
	{
		if( m_EntryWidgets.Contains( m_CurrentSelectedServer ) )
		{
			m_EntryWidgets.Get( m_CurrentSelectedServer ).Focus();
			ScrollToEntry( m_EntryWidgets.Get( m_CurrentSelectedServer ) );
		}
		
		array<ref GetServersResultRow> entries = m_EntriesSorted[m_SortType];
		if( entries && entries.Count() > 0 )
			SetFocusServers();
		else
			SetFocusFilters();
	}
	
	
	void SetFocusFilters()
	{
		SetEnableFilters( true );
		SetEnableServers( false );
		
		// if loaded servers is 0, then hide Top navigation menu <Left / Right>
		m_WidgetNavFilters.Show( true );
		m_WidgetNavServers.Show( false );
		
		m_Filters.Focus();
		m_IsFilterFocused = true;
		
		UpdatePageButtons();
	}
	
	void SetFocusServers()
	{
		SetEnableServers( true );
		SetEnableFilters( false );
		
		m_WidgetNavFilters.Show( false );
		m_WidgetNavServers.Show( true );
				
		array<ref GetServersResultRow> entries = m_EntriesSorted[m_SortType];
		if( entries && entries.Count() > 0 )
		{
			string server_id = entries.Get( 0 ).m_HostIp + ":" + entries.Get( 0 ).m_HostPort;
			m_EntryWidgets.Get( server_id ).Focus();
		}
		else
		{
			SetFocus( null );
		}
		m_IsFilterFocused = false;
		
		UpdatePageButtons();
	}
	
	void SetEnableFilters(bool enable)
	{		
		Widget w_filters = m_Root.FindAnyWidget("filters_content");
		Widget w_content = m_Root.FindAnyWidget("server_list_scroller");
		w_content.Enable( !enable );
		
		if ( enable )
		{
			SetFocus( ButtonWidget.Cast(w_filters.FindWidget("sort_button")) );
		}
	}
	
	void SetEnableServers(bool enable)
	{		
		Widget w_filters = m_Root.FindAnyWidget("filters_content");
		Widget w_content = m_Root.FindAnyWidget("server_list_scroller");
		w_content.Enable( enable );
	}
	
	void UpdatePageButtons()
	{
		TextWidget wgt_page_stat = TextWidget.Cast( m_Root.FindAnyWidget( "servers_navigation_page_status" ) );		
		
		wgt_page_stat.SetText( GetCurrentPage().ToString() +" / "+ m_PagesCount.ToString() );
				
		if ( !m_IsFilterFocused && (m_PagesCount > 1) )
		{
			bool can_left = (GetCurrentPage() > 1);
			m_ButtonPageLeftImg.Show( can_left );
			m_BtnPagePrev.Show( can_left );
			
			bool can_right = (GetCurrentPage() < m_PagesCount);
			m_ButtonPageRightImg.Show( can_right );
			m_BtnPageNext.Show( can_right );
		}
		else
		{
			m_ButtonPageLeftImg.Show( false );
			m_BtnPagePrev.Show( false );
			m_ButtonPageRightImg.Show( false );
			m_BtnPageNext.Show( false );
		}
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		super.OnClick( w, x, y, button );
		
		if( button == MouseState.LEFT )
		{
			if ( w == m_ResetFilters )
			{
				ResetFilters();
			}
			else if( w == m_ApplyFilter )
			{
				ApplyFilters();
				return true;
			}
			else if ( w == m_RefreshList )
			{
				if ( m_Loading && !m_LoadingFinished )
				{
					PressX();
				}
				else
				{
					RefreshList();
				}
				
				return true;
			}
			else if ( w == m_BtnPagePrev )
			{
				Left();
				return true;
			}
			else if ( w == m_BtnPageNext )
			{
				Right();
				return true;
			}
		}
		return false;
	}
	
	//Coloring functions (Until WidgetStyles are useful)
	override void ColorHighlight( Widget w )
	{
		if ( !w )
		{
			return;
		}
		
		w.SetColor( ARGB( 255, 200, 0, 0) );
	}
	
	override void ColorNormal( Widget w )
	{
		if ( !w )
		{
			return
		}
		
		if ( (w.GetFlags() & WidgetFlags.IGNOREPOINTER) == WidgetFlags.IGNOREPOINTER )
		{
			return;
		}
		
		if( w.IsInherited( ButtonWidget ) )
		{
			ButtonWidget button = ButtonWidget.Cast( w );
			button.SetTextColor( ARGB( 255, 255, 255, 255 ) );
		}
		else if( !w.IsInherited( EditBoxWidget ) )
		{
			w.SetColor( ARGB( 0, 255, 255, 255 ) );
		}
		
		TextWidget text1	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
		TextWidget text3	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindAnyWidget( w.GetName() + "_image" ) );
		
		Widget option	= Widget.Cast( w.FindAnyWidget( w.GetName() + "_option_wrapper" ) );
		
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
	}
	
	override void ColorDisable( Widget w )
	{
		#ifdef PLATFORM_WINDOWS
		SetFocus( null );
		#endif
		
		ButtonWidget button = ButtonWidget.Cast( w );
		if( button )
		{
			button.SetTextColor( ColorManager.COLOR_DISABLED_TEXT );
		}
	}
}