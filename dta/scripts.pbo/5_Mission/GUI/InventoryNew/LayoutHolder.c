class LayoutHolder extends ScriptedWidgetEventHandler
{
	protected Widget				m_MainWidget;
	protected Widget				m_RootWidget;
	protected Widget				m_ParentWidget;
	protected LayoutHolder			m_Parent;
	protected string				m_LayoutName;
	
	protected bool					m_IsActive;

	void UpdateInterval();
	void SetLayoutName();
	
	void LayoutHolder( LayoutHolder parent )
	{		
		m_Parent = parent;
		
		this.SetLayoutName();
		this.SetParentWidget();
		
		if( m_LayoutName != "" )
		{
			m_MainWidget = GetGame().GetWorkspace().CreateWidgets( m_LayoutName );
			m_MainWidget.Show( true );
		}
		
		m_RootWidget = m_MainWidget;
		
		if( m_ParentWidget )
		{
			m_ParentWidget.Show( true );
			if( m_MainWidget )
			{
				m_ParentWidget.AddChild( m_MainWidget );
				m_MainWidget.Update();
			}
		}
	}
	
	void ~LayoutHolder()
	{
		delete m_RootWidget;
	}
	
		
	LayoutHolder GetRoot()
	{
		if( m_Parent )
		{
			ref LayoutHolder container = m_Parent.GetRoot();
			return container;
		}
		else
		{
			return this;
		}
	}
	
	void SetParentWidget()
	{
		if( m_Parent != NULL )
		{
			m_ParentWidget = m_Parent.GetMainWidget();
		}
	}
	
	LayoutHolder GetParent()
	{
		return m_Parent;
	}

	void SetActive( bool active )
	{
		m_IsActive = active;
	}

	bool IsActive()
	{
		return m_IsActive;
	}

	Widget GetMainWidget()
	{
		return m_MainWidget;
	}
	
	Widget GetRootWidget()
	{
		return m_RootWidget;
	}

	void OnShow()
	{
		m_RootWidget.Show( true );
		if( m_ParentWidget )
		{
			m_ParentWidget.Show( true );
		}
	}

	void OnHide()
	{
		m_RootWidget.Show( false );
	}

	void Refresh()
	{
		m_RootWidget.Update();
	}
	
	void InspectItem(InventoryItem item)
	{
		InventoryMenu menu = InventoryMenu.Cast( GetGame().GetUIManager().FindMenu(MENU_INVENTORY) );
		InspectMenuNew inspect_menu = InspectMenuNew.Cast( menu.EnterScriptedMenu(MENU_INSPECT) );
		if ( inspect_menu )
		{
			inspect_menu.SetItem(item);
		}
	}
}
