class ItemDropWarningMenu extends UIScriptedMenu
{
	void ItemDropWarningMenu()
	{
		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
	}

	void ~ItemDropWarningMenu()
	{
		if ( GetGame() && GetGame().GetMission() )
			GetGame().GetMission().PlayerControlEnable(true);
	}
	
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("gui/layouts/day_z_dropped_items.layout");
		
		return layoutRoot;
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		
		if (w.GetUserID() == IDC_OK)
		{
			Close();
			return true;
		}

		return false;
	}
}
