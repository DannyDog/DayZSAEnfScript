class ModsMenuSimple extends ScriptedWidgetEventHandler
{
	protected Widget								m_Root;
	protected Widget								m_Content;
	protected ref array<ref ModInfo>				m_Data;
	protected ref array<ref ModsMenuSimpleEntry>	m_Entries;

	void ModsMenuSimple(array<ref ModInfo> data, Widget parent)
	{
		m_Root = GetGame().GetWorkspace().CreateWidgets("gui/layouts/new_ui/mods_menu/mods_menu_simple.layout", parent);
		m_Data = data;

		m_Root.SetHandler(this);
		LoadEntries();
	}

	void LoadEntries()
	{
		int count = Math.Max(4, m_Data.Count() - 1);
		for (int i = 0; i < count - 1; i++)
		{
			ref ModsMenuSimpleEntry entry = new ModsMenuSimpleEntry(m_Data.Get(i), m_Content);
			m_Entries.Insert(entry);
		}

		if (m_Data.Count() > 4)
			m_Root.FindAnyWidget("ModMore").Show(true);
	}
}