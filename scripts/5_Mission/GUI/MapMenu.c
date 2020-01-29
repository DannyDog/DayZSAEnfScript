class MapMenu extends UIScriptedMenu
{
	
	protected bool 							m_WasChanged;
	protected ref MapHandler 				m_MapMenuHandler;
	protected ref MapWidget 				m_MapWidgetInstance;
	 ItemMap 						m_Map;
	//int 									m_MarkerCount;
	
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("gui/layouts/day_z_map.layout");
		
		/*MapWidget m = MapWidget.Cast(layoutRoot.FindAnyWidget("Map"));
		if (m)
		{
			m.AddUserMark("2681 4.7 1751", "Lalal", ARGB(255,255,0,0), "\\dz\\gear\\navigation\\data\\map_tree_ca.paa");
			m.AddUserMark("2683 4.7 1851", "Lala2", ARGB(255,0,255,0), "\\dz\\gear\\navigation\\data\\map_bunker_ca.paa");
			m.AddUserMark("2670 4.7 1651", "Lala3", ARGB(255,0,0,255), "\\dz\\gear\\navigation\\data\\map_busstop_ca.paa");
		}*/
		m_MapWidgetInstance = MapWidget.Cast(layoutRoot.FindAnyWidget("Map"));
		if (m_MapWidgetInstance)
		{
			float scale;
			vector map_pos;
			PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
			if( player && !player.GetLastMapInfo(scale,map_pos) )
			{
				string path = "CfgWorlds " + GetGame().GetWorldName();
				vector temp = GetGame().ConfigGetVector(path + " centerPosition");
				scale = 0.33;
				map_pos = Vector(temp[0],temp[2],temp[1]);
			}
			m_MapWidgetInstance.SetScale(scale);
			m_MapWidgetInstance.SetMapPos(map_pos);
			
			
			m_MapMenuHandler = new MapHandler(m_MapWidgetInstance);
		}
		
		return layoutRoot;
	}
	
	override void InitMapItem(EntityAI item)
	{
		super.InitMapItem(item);
		
		m_Map = ItemMap.Cast(item);
		//m_Map.SyncMapMarkers();
		//m_MarkerCount = m_Map.GetMarkerArray().Count();
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		
		switch (w.GetUserID())
		{
			case IDC_CANCEL:
				CloseMapMenu();
				return true;
		}
		
		return false;
	}

	//TODO if it does not work well enough, attach some ScriptedWidgetEventHandler to the MapWidget
	/*override bool OnDoubleClick(Widget w, int x, int y, int button)
	{
		super.OnDoubleClick(w, x, y, button);
		
		MapWidget m = MapWidget.Cast(layoutRoot.FindAnyWidget("Map"));
		if ( w == m )
		{
			vector screen_to_map = m.ScreenToMap(Vector(x,y,0));
			
			AddMarker(w,screen_to_map,
			
			//m.AddUserMark(screen_to_map, "marker", ARGB(255,0,0,255), "\\dz\\gear\\navigation\\data\\map_tree_ca.paa");
						
			return true;
		}
		
		return false;
	}*/

	override void Update( float timeslice )
	{
		super.Update( timeslice );
		
		if( GetGame() && GetGame().GetInput() && GetGame().GetInput().LocalPress("UAUIBack", false) )
		{
			MapWidget m = MapWidget.Cast(layoutRoot.FindAnyWidget("Map"));
			PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
			if( player && m )
			{
				player.SetLastMapInfo(m.GetScale(),m.GetMapPos());
			}
			
			CloseMapMenu();
		}
	}
	
	void AddMarker(vector pos, int color, int icon = 0)
	{
		m_Map.InsertMarker(pos,"",color,icon);
		m_MapWidgetInstance.AddUserMark(pos, "", color, MapMarkerTypes.GetMarkerTypeFromID(icon));
		m_WasChanged = true;
	}
	
	void RemoveMarker()
	{
		m_WasChanged = true;
	}
	
	override void LoadMapMarkers()
	{
		MapMarker marker;
		for ( int i = 0; i < m_Map.GetMarkerArray().Count(); i++ )
		{
			marker = m_Map.GetMarkerArray().Get(i);
			m_MapWidgetInstance.AddUserMark(marker.GetMarkerPos(),marker.GetMarkerText(),marker.GetMarkerColor(),MapMarkerTypes.GetMarkerTypeFromID(marker.GetMarkerIcon())/*"\\dz\\gear\\navigation\\data\\map_tree_ca.paa"*/);
		}
	}
	
	/*void SetChanged(bool state)
	{
		m_WasChanged = state;
	}
	
	bool WasChanged()
	{
		return m_WasChanged;
	}*/
	
	void CloseMapMenu()
	{
		if (m_WasChanged)
		{
			m_Map.SyncMapMarkers();
			m_WasChanged = false;
		}
		Close();
	}
}
