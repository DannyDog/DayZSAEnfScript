class RightArea: Container
{
	ref PlayerContainer	m_PlayerContainer;
	protected Widget	m_ContentParent;
	
	void RightArea( LayoutHolder parent )
	{
		m_MainWidget.Show( true );
		m_MainWidget		= m_MainWidget.FindAnyWidget( "Content" );
		m_ContentParent		= m_RootWidget.FindAnyWidget( "ContentParent" );
		m_PlayerContainer	= new PlayerContainer( this );
		m_PlayerContainer.SetPlayer( PlayerBase.Cast( GetGame().GetPlayer() ) );
		m_Body.Insert( m_PlayerContainer );
		m_ActiveIndex = 0;
		
		#ifdef PLATFORM_PS4
		ImageWidget lt = ImageWidget.Cast( m_RootWidget.FindAnyWidget( "LTIcon" ) );
		ImageWidget rt = ImageWidget.Cast( m_RootWidget.FindAnyWidget( "RTIcon" ) );
		
		lt.LoadImageFile( 0, "set:playstation_buttons image:L2" );
		rt.LoadImageFile( 0, "set:playstation_buttons image:R2" );
		#endif
	}
	
	override Container GetFocusedContainer()
	{
		return m_FocusedContainer;
	}
	
	override void SetFocusedContainer( Container cont )
	{
		m_FocusedContainer = cont;
	}
	
	override EntityAI GetFocusedItem()
	{
		EntityAI item = m_PlayerContainer.GetFocusedItem();
		return item;
	}
	
	PlayerContainer GetPlayerContainer()
	{
		return m_PlayerContainer;
	}
	
	override void DraggingOverHeader( Widget w, int x, int y, Widget receiver )
	{
		m_PlayerContainer.DraggingOverHeader( w, x, y, receiver );
	}
	
	override void MoveGridCursor( int direction )
	{
		m_PlayerContainer.MoveGridCursor( direction );
	}
	
	override bool Select()
	{
		return m_PlayerContainer.Select();
	}
	
	override bool SelectItem()
	{
		return m_PlayerContainer.SelectItem();
	}
	
	override bool Combine()
	{
		return m_PlayerContainer.Combine();
	}
	
	override bool EquipItem()
	{
		return m_PlayerContainer.EquipItem();
	}
	
	override bool TransferItem()
	{
		return m_PlayerContainer.TransferItem();
	}
	
	override bool InspectItem()
	{
		return m_PlayerContainer.InspectItem();
	}
	
	override bool TransferItemToVicinity()
	{
		return m_PlayerContainer.TransferItemToVicinity();
	}
	
	override void UnfocusGrid()
	{
		m_PlayerContainer.UnfocusGrid();
	}
	
	override void ResetFocusedContainer()
	{
		m_PlayerContainer.ResetFocusedContainer();
	}
	
	bool HasEntityContainerVisible( EntityAI entity )
	{
		return m_PlayerContainer.HasEntityContainerVisible( entity );
	}
	
	void SwapItemsInOrder( int slot1, int slot2 )
	{
		m_PlayerContainer.SwapItemsInOrder( slot1, slot2 );
	}
	
	bool IsPlayerEquipmentActive()
	{
		return m_PlayerContainer.IsPlayerEquipmentActive();
	}
	
	void ExpandCollapseContainer()
	{
		m_PlayerContainer.ExpandCollapseContainer();
	}
	
	override void SetActive( bool active )
	{
		m_PlayerContainer.SetActive( active );
		if( active )
		{
			m_PlayerContainer.SetFirstActive();
		}
	}
	
	override void SetNextActive()
	{
		m_PlayerContainer.SetNextActive();
	}
	
	override void SetPreviousActive( bool force = false )
	{
		m_PlayerContainer.SetPreviousActive( force );
	}
	
	override bool IsActive()
	{
		return m_PlayerContainer.IsActive( );
	}
	
	override void Refresh()
	{
		m_PlayerContainer.Refresh();
	}

	override void SetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
			m_LayoutName = WidgetLayoutName.RightAreaXbox;
		#else
			switch( InventoryMenu.GetWidthType() )
			{
				case ScreenWidthType.NARROW:
				{
					m_LayoutName = WidgetLayoutName.RightAreaNarrow;
					break;
				}
				case ScreenWidthType.MEDIUM:
				{
					m_LayoutName = WidgetLayoutName.RightAreaMedium;
					break;
				}
				case ScreenWidthType.WIDE:
				{
					m_LayoutName = WidgetLayoutName.RightAreaWide;
					break;
				}
			}
		#endif
			
	}

	override void SetParentWidget()
	{
		m_ParentWidget = m_Parent.GetMainWidget().FindAnyWidget( "RightPanel" );
	}

	override void OnShow()
	{
		super.OnShow();
		Refresh();
	}
	
	override void UpdateInterval()
	{
		super.UpdateInterval();
		m_PlayerContainer.UpdateInterval();
	}
}