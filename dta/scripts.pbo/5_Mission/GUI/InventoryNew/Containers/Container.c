class Container extends LayoutHolder
{
	protected ref array<ref LayoutHolder>	m_Body;
	protected ref array<ref LayoutHolder>	m_OpenedContainers;
	protected int							m_ActiveIndex = 1;
	protected bool							m_LastIndex;
	protected Container 					m_FocusedContainer;
	
	const int ITEMS_IN_ROW = 8;
	
	int										m_FocusedRow = 0;
	int										m_FocusedColumn = 0;
	bool									m_ForcedHide;

	void MoveGridCursor( int direction );
	void OnDropReceivedFromHeader( Widget w, int x, int y, Widget receiver );
	void DraggingOver( Widget w, int x, int y, Widget receiver );
	void DraggingOverHeader( Widget w, int x, int y, Widget receiver );
	void RefreshQuantity( EntityAI item_to_refresh );
	void RefreshItemPosition( EntityAI item_to_refresh );
	void UpdateSpacer();
	
	void Container( LayoutHolder parent )
	{
		m_Body = new array<ref LayoutHolder>;
		m_OpenedContainers = new array<ref LayoutHolder>;
	}
	
	Container GetFocusedContainer()
	{
		return m_FocusedContainer;
	}
	
	void SetFocusedContainer( Container cont )
	{
		m_FocusedContainer = cont;
	}
	
	float GetFocusedContainerHeight( bool contents = false )
	{
		float x, y;
		if( GetFocusedContainer() )
			y = GetFocusedContainer().GetFocusedContainerHeight( contents );
		else
			GetRootWidget().GetScreenSize( x, y );
		return y;
	}
	
	float GetFocusedContainerYPos( bool contents = false )
	{
		float x, y;
		if( GetFocusedContainer() )
			y = GetFocusedContainer().GetFocusedContainerYPos( contents );
		else
			GetRootWidget().GetPos( x, y );
		return y;
	}
	
	float GetFocusedContainerYScreenPos( bool contents = false )
	{
		float x, y;
		if( GetFocusedContainer() )
			y = GetFocusedContainer().GetFocusedContainerYScreenPos( contents );
		else
			GetRootWidget().GetScreenPos( x, y );
		return y;
	}

	int Count()
	{
		return m_Body.Count();
	}
	
	bool SelectItem()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().SelectItem();
		return false;
	}
	
	bool Select()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().Select();
		return false;
	}
	
	bool Combine()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().Combine();
		return false;
	}
	
	bool TransferItemToVicinity()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().TransferItemToVicinity();
		return false;
	}
	
	bool TransferItem()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().TransferItem();
		return false;
	}
	
	bool EquipItem()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().EquipItem();
		return false;
	}
	
	bool CanEquip()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().CanEquip();
		return false;
	}
	
	bool CanCombine()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().CanCombine();
		return false;
	}
	
	bool CanCombineAmmo()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().CanCombineAmmo();
		return false;
	}
	
	bool IsEmpty()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().IsEmpty();
		return true;
	}
	
	bool IsItemActive()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().IsItemActive();
		return false;
	}

	bool IsItemWithQuantityActive()
	{
		if( GetFocusedContainer() )
			return GetFocusedContainer().IsItemWithQuantityActive();
		return false;
	}
	
	EntityAI GetFocusedEntity()
	{
		EntityAI item = GetFocusedContainer().GetFocusedEntity();
		return item;
	}
	
	override void UpdateInterval()
	{
		for ( int i = 0; i < m_Body.Count(); i++ )
		{
			if( m_Body.Get( i ) )
				m_Body.Get( i ).UpdateInterval();
		}
	}

	float m_PrevAlpha;
	
	override void SetActive( bool active )
	{
		m_IsActive = active;
		AttachmentCategoriesRow att_row;
		if( m_MainWidget.FindAnyWidget("SelectedContainer") )
		{
			m_MainWidget.FindAnyWidget("SelectedContainer").Show(active);
		}
		else
		{
			m_PrevAlpha = m_MainWidget.GetAlpha();
			if( active )
			{
				m_MainWidget.SetAlpha( m_PrevAlpha + 0.2 );
			}
			else
			{
				m_MainWidget.SetAlpha( m_PrevAlpha - 0.2 );
			}
		}
		
		if( active )
		{
			if( this.IsInherited( ContainerWithCargo ) )
			{
				ContainerWithCargo iwc = ContainerWithCargo.Cast( this );
				if( iwc )
				{
					iwc.SetDefaultFocus();
				}
			}
			else if( this.IsInherited( ContainerWithCargoAndAttachments ) )
			{
				ContainerWithCargoAndAttachments iwca = ContainerWithCargoAndAttachments.Cast( this );
				if( iwca )
				{
					iwca.SetDefaultFocus();
				}
			}
			else if(this.IsInherited( ContainerWithElectricManager ))
			{
			}
			else if(this.IsInherited( AttachmentCategoriesRow ))
			{
				att_row = AttachmentCategoriesRow.Cast( this );
				if( att_row )
				{
					att_row.SetDefaultFocus();
				}
			}
			else
			{
				if( !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_FocusedColumn = 0;
					m_FocusedRow = 0;
					if( m_Body.Count() )
					{
						LayoutHolder cnt = LayoutHolder.Cast( m_Body.Get( 0 ) );
						cnt.GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).Show( true );
						ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( cnt.GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
					}
					if( item_preview == null )
					{
						return;
					}
					EntityAI focused_item =  item_preview.GetItem();
					
					if( focused_item )
					{
						float x, y;
						cnt.GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).GetScreenPos( x, y );
						ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
					}
				}
			}
		}
		else
		{
			if( this.IsInherited( AttachmentCategoriesRow ) )
			{
				att_row = AttachmentCategoriesRow.Cast( this );
				if( att_row )
				{
					att_row.UnfocusAll();
				}
			}
			else if( this.IsInherited( AttachmentCategoriesSlotsContainer ) )
			{
				AttachmentCategoriesSlotsContainer slot_row = AttachmentCategoriesSlotsContainer.Cast( this );
				if( slot_row )
				{
					slot_row.UnfocusAll();
				}
			}
			else if( this.IsInherited( VicinitySlotsContainer ) )
			{
				VicinitySlotsContainer vicinity_row = VicinitySlotsContainer.Cast( this );
				if( vicinity_row )
				{
					vicinity_row.UnfocusAll();
				}
			}
		}
	}

	void UnfocusAll()
	{
		for ( int i = 0; i < Count(); i++ )
		{
			for ( int j = 0; j < ITEMS_IN_ROW; j++ )
			{
				if( Get( i ) && Get( i ).GetMainWidget() && Get( i ).GetMainWidget().FindAnyWidget( "Cursor" + j ) )
					Get( i ).GetMainWidget().FindAnyWidget( "Cursor" + j ).Show( false );
			}
		}
	}

	void UnfocusGrid()
	{
		if( GetFocusedContainer() )
		{
			m_FocusedRow = 0;
			m_FocusedColumn = 0;
			GetFocusedContainer().UnfocusAll();
		}
		/*if( GetFocusedContainer() && !GetFocusedContainer().IsInherited( ContainerWithCargo ) && !GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) && !GetFocusedContainer().IsInherited( AttachmentCategoriesRow ) )
		{
			UnfocusAll();
			m_FocusedRow = 0;
			m_FocusedColumn = 0;
		}
		else
		{
			ContainerWithCargo iwc = ContainerWithCargo.Cast( GetFocusedContainer() );
			ContainerWithCargoAndAttachments iwca = ContainerWithCargoAndAttachments.Cast( GetFocusedContainer() );
			AttachmentCategoriesRow iwca2 = AttachmentCategoriesRow.Cast( GetFocusedContainer() );
			if( iwc )
			{
				iwc.UnfocusGrid();
			}
			else if( iwca )
			{
				iwca.UnfocusGrid();
			}
			else if( iwca2 )
			{
				iwca2.UnfocusAll();
			}
		}*/
	}

	bool IsLastIndex()
	{
		return m_LastIndex;
	}
	
	bool IsFirstIndex()
	{
		return m_ActiveIndex == 1; 
	}
	
	bool IsFirstContainerFocused()
	{
		Container first;
		if( m_OpenedContainers.Count() > 0 )
			first = Container.Cast( m_OpenedContainers[1] );
		return GetFocusedContainer() == first;
	}
	
	bool IsLastContainerFocused()
	{
		Container last;
		if( m_OpenedContainers.Count() > 0 )
			last = Container.Cast( m_OpenedContainers[ m_OpenedContainers.Count() - 1 ] );
		return GetFocusedContainer() == last;
	}
	
	void SetFocused()
	{
		SetFocusedContainer( this );
	}
	
	void ResetFocusedContainer()
	{
		SetFocusedContainer( null );
	}

	void SetNextActive()
	{
		ItemManager.GetInstance().HideTooltip( );
		if( ItemManager.GetInstance().IsMicromanagmentMode() )
		{
			ItemManager.GetInstance().SetItemMoving( true );
		}
		
		Container active = Container.Cast( m_Body[m_ActiveIndex] );
		if( !active.IsActive() )
		{
			return;
		}
		
		if( !active.IsLastContainerFocused() )
		{
			active.SetNextActive();
		}
		else
		{
			++m_ActiveIndex;
			Container next;
			if( m_ActiveIndex < m_OpenedContainers.Count() )
			{
				next = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
				if( m_ActiveIndex == m_OpenedContainers.Count() - 1 )
				{
					m_LastIndex = true;
				}
				else
				{
					m_LastIndex = false;
				}
			}
			
			while( next && !next.GetMainWidget().IsVisible() )
			{
				++m_ActiveIndex;
				if( m_ActiveIndex < m_OpenedContainers.Count() )
				{
					next = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
				}
				else
				{
					next = null;
				}
			}
			
			if( next )
			{
				active.SetActive( false );
				next.SetActive( true );
				SetFocusedContainer( next );
			}
			else
			{
				m_ActiveIndex = 1;
				Container first = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
				if( first )
				{
					active.SetActive( false );
					first.SetActive( true );
					SetFocusedContainer( first );
				}
			}
		}
	}

	void SetPreviousActive()
	{
		if( ItemManager.GetInstance().IsMicromanagmentMode() )
		{
			ItemManager.GetInstance().SetItemMoving( true );
		}
		
		Container active = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
		if( !active.IsActive() )
		{
			return;
		}
		
		Container prev;
		
		if( --m_ActiveIndex > 0 )
		{
			prev = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
			if( m_ActiveIndex == m_OpenedContainers.Count() - 1 )
			{
				m_LastIndex = true;
			}
			else
			{
				m_LastIndex = false;
			}
		}
		
		while( prev && !prev.GetMainWidget().IsVisible() )
		{
			if( --m_ActiveIndex > 0 )
			{
				prev = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
			}
			else
			{
				prev = null;
			}
		}
		
		if( prev )
		{
			active.SetActive( false );
			prev.SetActive( true );
			SetFocusedContainer( prev );
		}
		else
		{
			m_ActiveIndex = m_OpenedContainers.Count() - 1;
			Container first = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
			if( first )
			{
				active.SetActive( false );
				first.SetActive( true );
				SetFocusedContainer( first );
			}
		}
	}
	
	void RecomputeOpenedContainers()
	{
		m_OpenedContainers.Clear();
		m_OpenedContainers.Insert( m_Body[0] );
		m_OpenedContainers.Insert( m_Body[1] );
		for ( int i = 0; i < m_Body.Count(); i++ )
		{
			ClosableContainer cnt = ClosableContainer.Cast( m_Body.Get( i ) );
			if( cnt && cnt.IsOpened() )
			{
				m_OpenedContainers.Insert( cnt );
			}
		}
	}

	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.Container;
	}

	void Insert( LayoutHolder container, int pos = -1 )
	{
		if( pos > -1 && pos < m_Body.Count() )
			m_Body.InsertAt( container, pos );
		else
			m_Body.Insert( container );
		
		Refresh();
	}

	void Remove( LayoutHolder container )
	{
		if( m_Body )
		{
			m_Body.RemoveItem( container );
		}
		
		Refresh();
	}
	
	LayoutHolder Get( int x )
	{
		return m_Body.Get( x );
	}

	override void Refresh()
	{
		for ( int i = 0; i < m_Body.Count(); i++ )
		{
			if( m_Body.Get( i ) )
				m_Body.Get( i ).Refresh();
		}
	}

	void UpdateBodySpacers()
	{
		for ( int i = 0; i < m_Body.Count(); i++ )
		{
			Container c = Container.Cast( m_Body.Get( i ) );
			if( c && c.IsInherited( Container ) )
			{
				c.UpdateSpacer();
			}
		}
		
		UpdateSpacer();
	}

	void HideContent( bool force_hide = false )
	{
		if( !m_ForcedHide )
			m_ForcedHide = force_hide;
		for( int i = 1; i < m_Body.Count(); i++ )
		{
			if( m_Body.Get( i ) )
				m_Body.Get( i ).OnHide();
		}
	}
	
	void ShowContent( bool force_show = false )
	{
		if( force_show )
			m_ForcedHide = false;
		
		if( !m_ForcedHide )
		{
			for( int i = 1; i < m_Body.Count(); i++ )
			{
				if( m_Body.Get( i ) )
				m_Body.Get( i ).OnShow();
			}
		}
	}
}
