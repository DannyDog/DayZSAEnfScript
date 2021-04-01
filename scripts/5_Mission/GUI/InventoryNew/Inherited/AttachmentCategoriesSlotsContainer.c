class AttachmentCategoriesSlotsContainer: Container
{
	ref SlotsContainer m_ItemsCont;
	
	void AttachmentCategoriesSlotsContainer( LayoutHolder parent, int index )
	{
		m_ItemsCont = new SlotsContainer(this, null);
		m_Body.Insert( m_ItemsCont );
		m_ItemsCont.GetMainWidget().SetUserID( index );
		
		for( int k = 0; k < ITEMS_IN_ROW; k++ )
		{
			//WidgetEventHandler.GetInstance().RegisterOnDropReceived( m_ItemsCont.GetSlotIcon( k ).GetMainWidget(),  m_Parent, "OnDropReceivedFromHeader" );
			//WidgetEventHandler.GetInstance().RegisterOnDropReceived(  m_ItemsCont.GetSlotIcon( k ).GetPanelWidget(),  m_Parent, "OnDropReceivedFromHeader" );
			      
			WidgetEventHandler.GetInstance().RegisterOnDraggingOver( m_ItemsCont.GetSlotIcon( k ).GetMainWidget(),  m_Parent, "DraggingOverHeader" );
			WidgetEventHandler.GetInstance().RegisterOnDraggingOver( m_ItemsCont.GetSlotIcon( k ).GetPanelWidget(),  m_Parent, "DraggingOverHeader" );
			
			WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( m_ItemsCont.GetSlotIcon( k ).GetMainWidget(),  m_Parent, "MouseClick" );
			WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( m_ItemsCont.GetSlotIcon( k ).GetPanelWidget(),  m_Parent, "MouseClick" );
			
			WidgetEventHandler.GetInstance().RegisterOnMouseEnter( m_ItemsCont.GetSlotIcon( k ).GetMainWidget(), m_ItemsCont.GetSlotIcon( k ), "MouseEnterGhostSlot" );
			WidgetEventHandler.GetInstance().RegisterOnMouseLeave( m_ItemsCont.GetSlotIcon( k ).GetMainWidget(), m_ItemsCont.GetSlotIcon( k ), "MouseLeaveGhostSlot" );
			
			m_ItemsCont.GetSlotIcon( k ).GetMainWidget().SetUserID( k );
			m_ItemsCont.GetSlotIcon( k ).GetPanelWidget().SetUserID( k );
		}
	}
  
	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.Container;
	}
  
	SlotsContainer GetSlotsContainer()
	{
		return m_ItemsCont;
	}
	
	override bool IsFirstContainerFocused()
	{
		
		Container first;
		if( m_Body.Count() > 0 )
			first = Container.Cast( m_Body[1] );
		return GetFocusedContainer() == first;
	}
	
	override bool IsLastContainerFocused()
	{
		Container last;
		if( m_Body.Count() > 0 )
			last = Container.Cast( m_Body[ m_Body.Count() - 1 ] );
		return GetFocusedContainer() == last;
	}
	
	override EntityAI GetFocusedItem()
	{
		return m_ItemsCont.GetSlotIcon( m_FocusedColumn ).GetRender().GetItem();
	}
	
	int GetParentID()
	{
		return m_ItemsCont.GetMainWidget().GetUserID();
	}
	
	int GetFocusedID()
	{
		return m_ItemsCont.GetSlotIcon( m_FocusedColumn ).GetMainWidget().GetUserID();
	}
	
	void ExpandCollapseContainer( bool expand )
	{
		m_ItemsCont.GetSlotIcon( m_FocusedColumn ).GetRadialIcon().Show( expand );
		m_ItemsCont.GetSlotIcon( m_FocusedColumn ).GetRadialIconClosed().Show( !expand );
	}
	
	override void MoveGridCursor( int direction )
	{
		ItemManager.GetInstance().HideTooltip();
		UnfocusAll();
		if( direction == Direction.UP )
		{
			Container cnt = Container.Cast( m_Parent.GetParent() );
			if( cnt )
			{
				cnt.SetPreviousActive();
			}
			else
			{
				cnt = Container.Cast( m_Parent );
				cnt.SetPreviousActive();
			}
			return;
		}
	
		if( direction == Direction.DOWN )
		{
			cnt = Container.Cast( m_Parent.GetParent() );
			if( cnt )
			{
				cnt.SetNextActive();
			}
			else
			{
				cnt = Container.Cast( m_Parent );
				cnt.SetNextActive();
			}
			return;
		}
	
		if( direction == Direction.RIGHT )
		{
			m_FocusedColumn++;
			if( m_FocusedColumn > m_ItemsCont.GetColumnCount() )
			{
				m_FocusedColumn = 0;
			}
		}
	
		if( direction == Direction.LEFT )
		{
			m_FocusedColumn--;
			if( m_FocusedColumn < 0 )
			{
				m_FocusedColumn = m_ItemsCont.GetColumnCount() - 1;
			}
		}

		m_ItemsCont.SetFocus( m_FocusedColumn );
		
		EntityAI focused_item = GetFocusedItem();
		if( focused_item )
		{
			float x, y;
			m_ItemsCont.GetSlotIcon( m_FocusedColumn ).GetCursorWidget().GetScreenPos( x, y );
			ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
		}
	}
	
	override bool SelectItem()
	{
		return false;
	}
	
	override bool Select()
	{
		return false;
	}
	
	override bool Combine()
	{
		return false;
	}
	
	override bool TransferItemToVicinity()
	{
		return false;
	}
	
	override bool TransferItem()
	{
		return false;
	}
	
	override bool EquipItem()
	{
		return false;
	}
	
	override bool CanEquip()
	{
		return false;
	}
	
	override bool CanCombine()
	{
		return false;
	}
	
	override bool CanCombineAmmo()
	{
		return false;
	}
	
	override bool IsEmpty()
	{
		return false;
	}
	
	override bool IsItemActive()
	{
		return false;
	}

	override bool IsItemWithQuantityActive()
	{
		return false;
	}
}
