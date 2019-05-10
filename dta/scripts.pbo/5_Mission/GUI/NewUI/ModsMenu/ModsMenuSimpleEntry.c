class ModsMenuSimpleEntry extends ScriptedWidgetEventHandler
{
	protected Widget		m_Root;
	protected ImageWidget	m_Icon;

	protected ref ModInfo	m_Data;

	void ModsMenuSimpleEntry(ModInfo data, Widget parent)
	{
		m_Root = GetGame().GetWorkspace().CreateWidgets("gui/layouts/new_ui/mods_menu/mods_menu_simple_entry.layout", parent);
		m_Icon = ImageWidget.Cast(m_Root.FindAnyWidget("Icon"));

		m_Data = data;

		m_Root.SetHandler(this);

		LoadData();
	}

	void LoadData()
	{
		string logo = m_Data.GetLogo();
		if (logo != "")
		{
			m_Icon.LoadImageFile(0, logo);
		}
	}
}