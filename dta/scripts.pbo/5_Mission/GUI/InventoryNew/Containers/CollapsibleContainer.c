class CollapsibleContainer: Container
{
	protected ref CollapsibleHeader		m_CollapsibleHeader;
	protected bool						m_Hidden;
	
	void CollapsibleContainer( LayoutHolder parent, int sort = -1 )
	{
		m_MainWidget.Show( true );

		if( sort > -1 )
			m_MainWidget.SetSort( sort + 2 );
		
		m_MainWidget = m_MainWidget.FindAnyWidget( "header" );
		
		m_Body = new array<ref LayoutHolder>;
		m_CollapsibleHeader = new CollapsibleHeader( this, "CollapseButtonOnMouseButtonDown" );
		m_Body.Insert( m_CollapsibleHeader );
		m_OpenedContainers.Insert( m_CollapsibleHeader );
	}
	
	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.CollapsibleContainer;
	}

	override void OnDropReceivedFromHeader( Widget w, int x, int y, Widget receiver ) { }

	override void Refresh()
	{
		super.Refresh();
	}

	override void OnShow()
	{
		super.OnShow();
		m_Hidden = false;
		for ( int i = 1; i < m_Body.Count(); i++ )
		{
			if( !m_Hidden )
			{
				m_Body.Get( i ).OnShow();
			}
		}
	}
	
	override void Insert( LayoutHolder container, int pos = -1 )
	{
		super.Insert( container );
		RecomputeOpenedContainers();
		UpdateCollapseButtons();
	}
	
	override void Remove( LayoutHolder container )
	{
		super.Remove( container );
		RecomputeOpenedContainers();
		UpdateCollapseButtons();
	}
	
	override void MoveGridCursor( int direction )
	{
		GetFocusedContainer().MoveGridCursor( direction );
	}

	void UpdateCollapseButtons()
	{
		#ifndef PLATFORM_CONSOLE
		if( m_Body.Count() < 3 )
		{
			m_CollapsibleHeader.GetMainWidget().FindAnyWidget("collapse_button").Show(false);
		}
		else
		{
			m_CollapsibleHeader.GetMainWidget().FindAnyWidget("collapse_button").Show(true);
		}
		#endif
	}
	
	void LoadDefaultState()
	{
		m_Hidden = !ItemManager.GetInstance().GetDefaultHeaderOpenState( "VICINITY" );
		
		if( m_Hidden )
		{
			OnHide();
		}
		else
		{
			OnShow();
		}
	}
	
	override bool IsActive()
	{
		for ( int i = 1; i < m_Body.Count(); i++ )
		{
			ref Container cont = Container.Cast( m_Body[i] );
			if( cont.IsActive() )
			{
				return true;
			}
		}
		return false;
	}
	
	void SetFirstActive()
	{
		UnfocusAll();
		Container cont = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
		if( m_ActiveIndex != 1 && cont )
			cont.SetActive( false );
		if( m_FocusedContainer )
			m_FocusedContainer.SetActive( false );
		
		cont = Container.Cast( m_Body[1] );
		cont.SetActive( true );
		SetFocusedContainer( cont );
		m_ActiveIndex = 1;
		m_CollapsibleHeader.SetActive( true );
	}
	
	override void SetLastActive()
	{
		UnfocusAll();
		Container cont = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
		if( cont )
			cont.SetActive( false );
		if( m_FocusedContainer )
			m_FocusedContainer.SetActive( false );
		
		cont = Container.Cast( m_OpenedContainers[m_OpenedContainers.Count() - 1] );
		cont.SetActive( true );
		cont.SetLastActive();
		SetFocusedContainer( cont );
		m_ActiveIndex = m_OpenedContainers.Count() - 1;
		if( m_ActiveIndex == 1 )
			m_CollapsibleHeader.SetActive( true );
		else
			m_CollapsibleHeader.SetActive( false );
	}
	
	override void SetActive( bool active )
	{
		Container cont;
		m_IsActive = active;
		if( active )
		{
			cont = Container.Cast( m_OpenedContainers[1] );
			cont.SetActive( true );
			SetFocusedContainer( cont );
			m_ActiveIndex = 1;
			m_LastIndex = ( Count() == 2 );
		}
		else
		{
			for ( int i = 1; i < m_OpenedContainers.Count(); i++ )
			{
				cont = Container.Cast( m_OpenedContainers[i] );
				if( cont.IsActive() )
				{
					cont.SetActive( false );
					m_ActiveIndex = 1;
				}
			}
		}
		m_CollapsibleHeader.SetActive( active );
	}
	
	bool IsHidden()
	{
		return m_Hidden;
	}
	
	void CollapseButtonOnMouseButtonDown( Widget w )
	{
		if( !m_Hidden )
		{
			for (int i = 2; i < m_Body.Count(); i++)
			{
				m_Body.Get( i ).OnHide();
			}

			m_Hidden = true;
		}
		else
		{
			m_Hidden = false;
			OnShow();
		}
		
		m_CollapsibleHeader.GetRootWidget().FindAnyWidget("opened").Show(!m_Hidden);
		m_CollapsibleHeader.GetRootWidget().FindAnyWidget("closed").Show(m_Hidden);

		UpdateCollapseButtons();
	}
	
	override bool OnChildRemove( Widget w, Widget child )
	{
		if( w == GetMainWidget() )
			GetMainWidget().Update();
		return true;
	}
	
	override bool OnChildAdd( Widget w, Widget child )
	{
		if( w == GetMainWidget() )
			GetMainWidget().Update();
		return true;
	}
}
