class HandsArea: LayoutHolder
{
	protected ScrollWidget			m_Scroller;
	protected ref HandsContainer	m_HandsContainer;
	protected ref SizeToChild		m_HandsResizer;
	
	protected bool					m_ShouldChangeSize = true;

	void HandsArea( LayoutHolder parent )
	{
		m_HandsContainer	= new HandsContainer( this );
		
		m_MainWidget.Update();
		
		m_ParentWidget.GetScript( m_HandsResizer );
		m_Scroller = ScrollWidget.Cast( m_ParentWidget );
	}

	override void SetActive( bool active )
	{
		m_HandsContainer.SetActive( active );
	}

	override bool IsActive()
	{
		return m_HandsContainer.IsActive();
	}
	
	bool CanEquip()
	{
		return m_HandsContainer.CanEquip();
	}
	
	void UnfocusGrid()
	{
		m_HandsContainer.UnfocusGrid();
	}
	
	void SetNextActive()
	{
		m_HandsContainer.SetNextActive();
	}
	
	void SetPreviousActive()
	{
		m_HandsContainer.SetPreviousActive();
	}

	bool IsSwapActive()
	{
		Widget swap_cursor = m_MainWidget.FindAnyWidget("SwapCursor");
		if( swap_cursor )
		{
			return swap_cursor.IsVisible();
		}
		else
		{
			return false;
		}
	}

	bool IsCombineActive()
	{
		Widget combine_cursor = m_MainWidget.FindAnyWidget("CombineCursor");

		if( combine_cursor )
		{
			return combine_cursor.IsVisible();
		}
		else
		{
			return false;
		}
	}
	
	void MoveGridCursor( int direction )
	{
		if( IsActive() )
		{
			m_HandsContainer.MoveGridCursor( direction );
		}
	}
	
	bool EquipItem()
	{
		return m_HandsContainer.EquipItem();
	}
	
	bool SelectItem()
	{
		return m_HandsContainer.SelectItem();
	}

	bool Select()
	{
		return m_HandsContainer.Select();
	}
	
	bool TransferItem()
	{
		return m_HandsContainer.TransferItem();
	}
	
	bool TransferItemToVicinity()
	{
		return m_HandsContainer.TransferItemToVicinity();
	}
	
	bool IsItemActive()
	{
		return m_HandsContainer.IsItemActive();
	}
	
	bool IsItemWithQuantityActive()
	{
		return m_HandsContainer.IsItemWithQuantityActive();
	}
	
	bool IsEmpty()
	{
		return m_HandsContainer.IsEmpty();
	}

	override void UpdateInterval()
	{
		m_Scroller.VScrollToPos01( m_Scroller.GetVScrollPos01() );
		m_HandsContainer.UpdateInterval();
		
		bool changed_size;
		if( m_ShouldChangeSize && m_HandsResizer.ResizeParentToChild( changed_size, InventoryMenu.GetHeight() * 0.5 ) )
			m_Scroller.SetAlpha( 0.3921 );
		else
			m_Scroller.SetAlpha( 0 );
		
		if( changed_size )
			m_ShouldChangeSize = false;
	}

	void RefreshQuantity( EntityAI item_to_refresh )
	{
		m_HandsContainer.RefreshQuantity( item_to_refresh );
	}

	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.HandsArea;
	}

	override void SetParentWidget()
	{
		m_ParentWidget = m_Parent.GetMainWidget().FindAnyWidget( "HandsPanel" );
	}

	override void OnShow()
	{
		super.OnShow();
		m_HandsContainer.OnShow();
	}

	override void Refresh()
	{
		m_HandsContainer.Refresh();
		m_ShouldChangeSize = true;
	}
	
	void DraggingOverHandsPanel( Widget w, int x, int y, Widget receiver )
	{
		if( w == NULL )
		{
			return;
		}
		
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
		
		if( !ipw )
		{
		  string name = w.GetName();
		  name.Replace( "PanelWidget", "Render" );
		  ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		}
		
		if( !ipw )
		{
		  ipw = ItemPreviewWidget.Cast( w );
		}
		
		if( !ipw || !ipw.IsInherited( ItemPreviewWidget ) )
		{
			return;
		}

		ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
		ItemManager.GetInstance().HideDropzones();
		ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "HandsPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
	}
	
	void OnHandsPanelDropReceived( Widget w, int x, int y, Widget receiver )
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
		if( !ipw )
		{
		  string name = w.GetName();
		  name.Replace( "PanelWidget", "Render" );
		  ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		}
		
		if( !ipw )
		{
			ipw = ItemPreviewWidget.Cast( w );
		}
		
		if( !ipw || !ipw.GetItem() || !ipw.IsInherited( ItemPreviewWidget ) )
		{
			return;
		}
		
		if( !ipw.GetItem().GetInventory().CanRemoveEntity() )
			return;
		
		if( GetGame().GetPlayer().GetHumanInventory().CanAddEntityInHands( ipw.GetItem() ) )
		{
			ItemBase item_base = ItemBase.Cast( ipw.GetItem() );
			float stackable = item_base.ConfigGetFloat("varStackMax");
			if( stackable == 0 || item_base.GetQuantity() <= stackable )
			{
				GetGame().GetPlayer().PredictiveTakeEntityToHands( item_base );		
			}
			else if( stackable != 0 && stackable <= item_base.GetQuantity() )
			{
				item_base.SplitIntoStackMaxHandsClient( PlayerBase.Cast( GetGame().GetPlayer() ) );
			}
		}
	}
}