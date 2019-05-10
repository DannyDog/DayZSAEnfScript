class MapMenu extends UIScriptedMenu
{
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
		return layoutRoot;
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		
		switch (w.GetUserID())
		{
			case IDC_CANCEL:
				Close();
				return true;
		}

		return false;
	}
	
	override void Update( float timeslice )
	{
		super.Update( timeslice );
		
		if( GetGame() && GetGame().GetInput() && GetGame().GetInput().LocalPress("UAUIBack", false) )
		{
			/*PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
			if( player )
				player.CloseMap();*/
			Close();
		}
	}
}
