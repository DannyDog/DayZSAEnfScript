class ModsMenuDetailedEntry extends ScriptedWidgetEventHandler
{
	protected Widget			m_Root;
	protected ImageWidget		m_Icon;
	protected RichTextWidget	m_Name;
	protected RichTextWidget	m_Description;
	protected Widget			m_Spacer;

	protected ref ModInfo		m_Data;

	void ModsMenuDetailedEntry(ModInfo data, Widget parent)
	{
		m_Root = GetGame().GetWorkspace().CreateWidgets("gui/layouts/new_ui/mods_menu/mods_menu_detailed_entry.layout", parent);
		m_Icon = ImageWidget.Cast(m_Root.FindAnyWidget("Icon"));
		m_Name = RichTextWidget.Cast(m_Root.FindAnyWidget("Name"));
		m_Description = RichTextWidget.Cast(m_Root.FindAnyWidget("Description"));
		m_Spacer = m_Root.FindAnyWidget("Spacer");

		m_Data = data;

		m_Root.SetHandler(this);

		LoadData();
	}

	void LoadData()
	{
		string logo = m_Data.GetLogo();
		string name = m_Data.GetName();
		string description = m_Data.GetName();

		if (logo != "")
		{
			m_Icon.LoadImageFile(0, logo);
		}

		if (name != "")
		{
			m_Name.SetText(name);
		}

		if (description != "")
		{
			m_Spacer.Show(true);
			m_Description.Show(true);
			m_Description.SetText(description);
		}
	}
}