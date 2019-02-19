class RightArea: Container
{
	ref PlayerContainer m_PlayerContainer;
	
	void RightArea( LayoutHolder parent )
	{
		m_MainWidget.Show( true );
		m_MainWidget = m_MainWidget.FindAnyWidget( "Content" );
		
		m_PlayerContainer = new PlayerContainer( this );
		m_PlayerContainer.SetPlayer( PlayerBase.Cast( GetGame().GetPlayer() ) );
		m_Body.Insert( m_PlayerContainer );
		m_ActiveIndex = 0;
	}
	
	override Container GetFocusedContainer()
	{
		return m_FocusedContainer;
	}
	
	override void SetFocusedContainer( Container cont )
	{
		m_FocusedContainer = cont;
	}
	
	EntityAI GetFocusedItem()
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
	
	bool IsPlayerEquipmentActive()
	{
		return m_PlayerContainer.IsPlayerEquipmentActive();
	}
	
	void ExpandCollapseContainer()
	{
		m_PlayerContainer.ExpandCollapseContainer();
	}
	
	override void RefreshItemPosition( EntityAI item_to_refresh )
	{
		m_PlayerContainer.RefreshItemPosition( item_to_refresh );
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
	
	override void SetPreviousActive()
	{
		m_PlayerContainer.SetPreviousActive();
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
	
	override void RefreshQuantity( EntityAI item_to_refresh )
	{
		m_PlayerContainer.RefreshQuantity( item_to_refresh );
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
}
