class LeftArea: Container
{
	protected Widget					m_UpIcon;
	protected Widget					m_DownIcon;
	protected ref VicinityContainer		m_VicinityContainer;
	protected ScrollWidget				m_ScrollWidget;
	protected ref SizeToChild			m_ContentResize;
	protected bool						m_ShouldChangeSize = true;
	
	void LeftArea( LayoutHolder parent )
	{
		m_MainWidget.Show( true );
		m_MainWidget.FindAnyWidget( "ContentParent" ).GetScript( m_ContentResize );
		
		m_ScrollWidget	= ScrollWidget.Cast( m_MainWidget.FindAnyWidget( "Scroller" ) );
		m_MainWidget	= m_MainWidget.FindAnyWidget( "Content" );
		
		m_UpIcon		= m_RootWidget.FindAnyWidget( "Up" );
		m_DownIcon		= m_RootWidget.FindAnyWidget( "Down" );
		
		m_VicinityContainer = new VicinityContainer( this );
		m_Body.Insert( m_VicinityContainer );
		m_ActiveIndex = 0;
		
		WidgetEventHandler.GetInstance().RegisterOnChildAdd( m_MainWidget, this, "OnChildAdd" );
		WidgetEventHandler.GetInstance().RegisterOnChildRemove( m_MainWidget, this, "OnChildRemove" );
	}
	
	override void RefreshItemPosition( EntityAI item_to_refresh )
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		active_container.RefreshItemPosition( item_to_refresh );
	}
	
	override void RefreshQuantity( EntityAI item_to_refresh )
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		active_container.RefreshQuantity( item_to_refresh );
	}
	
	override void MoveGridCursor( int direction )
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		active_container.MoveGridCursor( direction );
		
		float x, y, y_s, amount;
		m_ScrollWidget.GetScreenPos( x, y );
		m_ScrollWidget.GetScreenSize( x, y_s );
		
		float next_pos	= active_container.GetFocusedContainerYScreenPos() + active_container.GetFocusedContainerHeight();
		
		if( next_pos > ( y + y_s ) )
		{
			amount	= y + active_container.GetFocusedContainerYScreenPos();
			m_ScrollWidget.VScrollToPos( m_ScrollWidget.GetVScrollPos() + active_container.GetFocusedContainerHeight() + 2 );
		}
		else if( active_container.GetFocusedContainerYScreenPos() < y )
		{
			amount = active_container.GetFocusedContainerYScreenPos() - y;
			m_ScrollWidget.VScrollToPos( m_ScrollWidget.GetVScrollPos() + amount - 2 );
		}
	}
	
	override bool TransferItemToVicinity()
	{
		return m_VicinityContainer.TransferItemToVicinity();
	}
	
	override bool SelectItem()
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		return active_container.SelectItem();
	}
		
	override bool Select()
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		return active_container.Select();
	}
	
	override bool Combine()
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		return active_container.Combine();
	}
	
	override bool TransferItem()
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		return active_container.TransferItem();
	}
	
	override bool EquipItem()
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		return active_container.EquipItem();
	}
	
	override void UnfocusGrid()
	{
		Container active_container;
		for ( int i = 0; i < m_Body.Count(); i++ )
		{
			active_container = Container.Cast( m_Body.Get( i ) );
			active_container.UnfocusGrid();
		}
	}
	
	override void ResetFocusedContainer()
	{
		m_ActiveIndex = 0;
		Container active_container;
		for ( int i = 0; i < m_Body.Count(); i++ )
		{
			active_container = Container.Cast( m_Body.Get( i ) );
			active_container.ResetFocusedContainer();
		}
	}
	
	override bool IsActive()
	{
		if( m_Body.Count() <= m_ActiveIndex )
		{
			m_ActiveIndex = 0;
		}
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		return active_container.IsActive( );
	}
	
	override void SetActive( bool active )
	{
		m_IsActive = active;
		if( m_Body.Count() <= m_ActiveIndex )
		{
			m_ActiveIndex = 0;
		}
		
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		active_container.SetActive( active );
		if( active )
		{
			if( active_container.IsInherited( CollapsibleContainer ) )
			{
				CollapsibleContainer.Cast( active_container ).SetFirstActive();
			}
			SetFocusedContainer( active_container );
		}
		UpdateSelectionIcons();
	}
	
	override void SetNextActive()
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		if( !active_container.IsActive() )
		{
			return;
		}

		if( active_container.IsLastContainerFocused() )
		{
			++m_ActiveIndex;
			if( m_ActiveIndex >= m_Body.Count() )
			{
				m_ActiveIndex = 0;
				m_ScrollWidget.VScrollToPos01( 0 );
			}

			active_container.SetActive( false );
			active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
			active_container.SetActive( true );
			SetFocusedContainer( active_container );
			if( active_container.IsInherited( CollapsibleContainer ) )
			{
				CollapsibleContainer.Cast( active_container ).SetFirstActive();
			}
		}
		else
		{
			active_container.SetNextActive();
		}
		
		float x, y, y_s;
		m_ScrollWidget.GetScreenPos( x, y );
		m_ScrollWidget.GetScreenSize( x, y_s );
		float amount	= y + active_container.GetFocusedContainerYScreenPos( true );
		float next_pos	= active_container.GetFocusedContainerYScreenPos( true ) + active_container.GetFocusedContainerHeight( true );
		if( next_pos > ( y + y_s ) )
		{
			m_ScrollWidget.VScrollToPos( m_ScrollWidget.GetVScrollPos() + active_container.GetFocusedContainerHeight( true ) + 2 );
		}
		
		UpdateSelectionIcons();
	}
	
	override void SetPreviousActive()
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		if( !active_container.IsActive() )
		{
			return;
		}
		
		if( active_container.IsFirstIndex() )
		{
			--m_ActiveIndex;
			if ( m_ActiveIndex < 0 )
			{
				m_ActiveIndex = m_Body.Count() - 1;
				m_ScrollWidget.VScrollToPos01( 1 );
			}
			
			active_container.SetActive( false );
			active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
			active_container.SetActive( true );
			SetFocusedContainer( active_container );
			if( active_container.IsInherited( CollapsibleContainer ) )
			{
				CollapsibleContainer.Cast( active_container ).SetLastActive();
			}
		}
		else
		{
			active_container.SetPreviousActive();
		}
		
		float x, y;
		m_ScrollWidget.GetScreenPos( x, y );
		if( active_container.GetFocusedContainerYScreenPos( true ) < y )
		{
			float amount = active_container.GetFocusedContainerYScreenPos( true ) - y;
			m_ScrollWidget.VScrollToPos( m_ScrollWidget.GetVScrollPos() + amount - 2 );
		}
		
		UpdateSelectionIcons();
	}
	
	void UpdateSelectionIcons()
	{
		m_UpIcon.Show( m_IsActive );
		m_DownIcon.Show( m_IsActive );
		if( m_IsActive )
		{
			float x, y;
			float x2, y2;
			m_UpIcon.GetScreenSize( x, y );
			m_DownIcon.GetScreenSize( x2, y2 );
			
			float top_y		= GetCurrentContainerTopY();
			float bottom_y	= GetCurrentContainerBottomY() - y2;
			
			float diff		= bottom_y - ( top_y + y );
			if( diff < 0 )
			{
				top_y += diff / 2;
				bottom_y -= diff / 2;
			}
			
			m_UpIcon.SetPos( 0, top_y );
			m_DownIcon.SetPos( 0, bottom_y );
		}
	}
	
	float GetCurrentContainerTopY()
	{
		float x, y;
		m_MainWidget.GetScreenPos( x, y );
		float cont_screen_pos = Container.Cast( m_Body.Get( m_ActiveIndex ) ).GetFocusedContainerYScreenPos();
		
		return cont_screen_pos - y;
	}
	
	float GetCurrentContainerBottomY()
	{
		float x, y;
		m_MainWidget.GetScreenPos( x, y );
		
		float cont_screen_pos = Container.Cast( m_Body.Get( m_ActiveIndex ) ).GetFocusedContainerYScreenPos();
		float cont_screen_height = Container.Cast( m_Body.Get( m_ActiveIndex ) ).GetFocusedContainerHeight();
		return cont_screen_pos - y + cont_screen_height;
	}
	
	void ExpandCollapseContainer()
	{
		m_VicinityContainer.ExpandCollapseContainer();
		
		Refresh();
	}
	
	void OnLeftPanelDropReceived( Widget w, int x, int y, Widget receiver )
	{
		m_VicinityContainer.OnLeftPanelDropReceived( w, x, y, receiver );
	}
	
	override void DraggingOverHeader( Widget w, int x, int y, Widget receiver )
	{
		m_VicinityContainer.DraggingOverHeader( w, x, y, receiver );
	}
	
	override void SetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
			m_LayoutName = WidgetLayoutName.LeftAreaXbox;
		#else
			switch( InventoryMenu.GetWidthType() )
			{
				case ScreenWidthType.NARROW:
				{
					m_LayoutName = WidgetLayoutName.LeftAreaNarrow;
					break;
				}
				case ScreenWidthType.MEDIUM:
				{
					m_LayoutName = WidgetLayoutName.LeftAreaMedium;
					break;
				}
				case ScreenWidthType.WIDE:
				{
					m_LayoutName = WidgetLayoutName.LeftAreaWide;
					break;
				}
			}
		#endif
			
	}
	
	VicinityContainer GetVicinityContainer()
	{
		return m_VicinityContainer;
	}
	
	override void SetParentWidget()
	{
		m_ParentWidget = m_Parent.GetMainWidget().FindAnyWidget( "LeftPanel" );
	}
	
	override void OnShow()
	{
		super.OnShow();
		Refresh();
	}
	
	override void Refresh()
	{
		super.Refresh();
		
		m_MainWidget.Update();
		m_RootWidget.Update();
		m_ScrollWidget.Update();
		
		UpdateSelectionIcons();
		CheckScrollbarVisibility();
		m_ShouldChangeSize = true;
	}
	
	override void UpdateInterval()
	{
		super.UpdateInterval();
		bool changed_size;
		if( m_ShouldChangeSize )
			m_ContentResize.ResizeParentToChild( changed_size );
		if( changed_size )
		{
			CheckScrollbarVisibility();
			m_ShouldChangeSize = false;
		}
	}
	
	void CheckScrollbarVisibility()
	{
		float x, y;
		float x2, y2;
		
		m_MainWidget.Update();
		m_RootWidget.Update();
		m_ScrollWidget.Update();
		
		m_MainWidget.GetScreenSize( x, y );
		m_ScrollWidget.GetScreenSize( x2, y2 );
		m_ScrollWidget.SetAlpha( ( y > y2 ) );
		
		m_ScrollWidget.VScrollToPos01( m_ScrollWidget.GetVScrollPos01() );
	}
	
	override bool OnChildRemove( Widget w, Widget child )
	{
		Refresh();
		return true;
	}
	
	override bool OnChildAdd( Widget w, Widget child )
	{
		Refresh();
		return true;
	}
}
