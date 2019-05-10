class ModsMenuDetailed extends ScriptedWidgetEventHandler
{
	protected Widget								m_Root;
	protected Widget								m_Content;
	protected ref array<ref ModInfo>				m_Data;
	protected ref array<ref ModsMenuDetailedEntry>	m_Entries;

	void ModsMenuDetailed(array<ref ModInfo> data, Widget parent)
	{
		m_Root = GetGame().GetWorkspace().CreateWidgets("gui/layouts/new_ui/mods_menu/mods_menu_detailed.layout", parent);
		m_Content = m_Root.FindAnyWidget("Content");
		m_Data = data;

		m_Root.SetHandler(this);

		LoadEntries();
	}

	void LoadEntries()
	{
		foreach(ModInfo var : m_Data)
		{
			ref ModsMenuDetailedEntry entry = new ModsMenuDetailedEntry(var, m_Content);
			m_Entries.Insert(entry);
		}
	}
}