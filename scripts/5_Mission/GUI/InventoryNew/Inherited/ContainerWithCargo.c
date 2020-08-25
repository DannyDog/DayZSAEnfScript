class ContainerWithCargo: ClosableContainer
{
	protected ref CargoContainer	m_CargoGrid;
	protected int m_CargoIndex = -1;

	void ContainerWithCargo( Container parent, int sort = -1 )
	{
		m_Parent = parent;

		m_CargoGrid = new CargoContainer( this );
		this.Insert( m_CargoGrid );
		
		m_CargoGrid.GetRootWidget().SetSort( 1 );
		
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( m_MainWidget,  this, "DraggingOverGrid" );
	}
	
	override bool IsEmpty()
	{
		return m_CargoGrid.IsEmpty();
	}
	
	override bool IsItemActive()
	{
		return m_CargoGrid.IsItemActive();
	}
	
	override bool CanEquip()
	{
		return m_CargoGrid.CanEquip();
	}
	
	override bool CanCombine()
	{
		return m_CargoGrid.CanCombine();
	}
	
	override bool CanCombineAmmo()
	{
		return m_CargoGrid.CanCombineAmmo();
	}
	
	override bool IsItemWithQuantityActive()
	{
		return m_CargoGrid.IsItemWithQuantityActive();
	}
	
	override void UpdateInterval()
	{
		if( m_Entity )
		{
			if( m_Entity.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ) || m_Closed )
			{
				HideContent();
			}
			else
			{
				ShowContent();
			}
		
			m_CargoGrid.UpdateInterval();
		}
	}

	override void MoveGridCursor( int direction )
	{
		m_CargoGrid.MoveGridCursor( direction );
	}
	
	override void SetActive( bool active )
	{
		super.SetActive( active );
		m_CargoGrid.SetActive( active );
		SetFocusedContainer( m_CargoGrid );
	}
	
	override void SetLastActive()
	{
		m_CargoGrid.SetLastActive();
	}
	
	override void SetNextActive()
	{
		Container.Cast( GetParent() ).SetNextActive();
		m_ActiveIndex = 1;
		UnfocusAll();
	}

	override void SetPreviousActive( bool force = false )
	{
		Container.Cast( GetParent() ).SetPreviousActive( force );
		m_ActiveIndex = 1;
		UnfocusAll();
	}
	
	override bool IsFirstContainerFocused()
	{
		return m_CargoGrid.IsFirstContainerFocused();
	}
	
	override bool IsLastContainerFocused()
	{
		return m_CargoGrid.IsLastContainerFocused();
	}

	void SetDefaultFocus( bool while_micromanagment_mode = false )
	{
		m_CargoGrid.SetDefaultFocus( while_micromanagment_mode );
	}
	
	override void UnfocusAll()
	{
		m_CargoGrid.Unfocus();
	}
	
	override bool EquipItem()
	{
		return m_CargoGrid.EquipItem();
	}
	
	override bool TransferItem()
	{
		return m_CargoGrid.TransferItem();
	}
	
	override bool TransferItemToVicinity()
	{
		return m_CargoGrid.TransferItemToVicinity();
	}
	
	override bool InspectItem()
	{
		return m_CargoGrid.InspectItem();
	}

	void SetEntity( EntityAI entity, int cargo_index = 0 )
	{
		m_Entity = entity;
		m_CargoIndex = cargo_index;

		SetOpenState( ItemManager.GetInstance().GetDefaultOpenState( m_Entity.GetType() ) );

		m_CargoGrid.SetEntity( entity );
		m_CargoGrid.UpdateHeaderText();
		m_ClosableHeader.SetItemPreview( entity );
		
		( Container.Cast( m_Parent ) ).Insert( this );
		
		if( m_Entity.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ) || m_Closed )
		{
			HideContent();
		}
		else
		{
			ShowContent();
		}
		
		Refresh();
		GetMainWidget().Update();
	}

	EntityAI GetEntity()
	{
		return m_Entity;
	}
	
	override EntityAI GetFocusedContainerEntity()
	{
		return m_Entity;
	}
	
	void EquipmentMoveUp()
	{
		PlayerContainer pc = PlayerContainer.Cast( m_Parent );
		if( pc )
		{
			pc.MoveContainerUp( this );
		}
	}
	
	void EquipmentMoveDown()
	{
		PlayerContainer pc = PlayerContainer.Cast( m_Parent );
		if( pc )
		{
			pc.MoveContainerDown( this );
		}
	}

	EntityAI GetItemPreviewItem( Widget w )
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
		if( !ipw || !ipw.IsInherited( ItemPreviewWidget ) )
		{
			return null;
		}
		return ipw.GetItem();
	}

	bool DraggingOverGrid( Widget w, int x, int y, Widget reciever )
	{
		if( w == null )
		{
			return false;
		}
		
		EntityAI item = GetItemPreviewItem( w );
		
		if( !item )
		{
			return false;
		}

		int color, c_x, c_y;
		
		#ifdef PLATFORM_CONSOLE
		int idx = -1;
		#else
		int idx = 0;
		#endif
		
		CargoBase cargo = m_Entity.GetInventory().GetCargoFromIndex(m_CargoIndex);
		if( cargo )
		{
			c_x = cargo.GetHeight();
			c_y = cargo.GetWidth();
		}
		
		InventoryLocation dst = new InventoryLocation;
		#ifdef PLATFORM_CONSOLE
		x = 0;
		y = cargo.GetItemCount();
		m_Entity.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.CARGO, dst );
		#else
		dst.SetCargoAuto(cargo, item, x, y, item.GetInventory().GetFlipCargo());
		#endif
		
		#ifdef PLATFORM_CONSOLE
		if( dst.IsValid() && m_Entity.GetInventory().LocationCanAddEntity(dst))
		#else
		if( m_Entity && c_x > x && c_y > y && m_Entity.GetInventory().LocationCanAddEntity(dst))
		#endif
		{
			ItemManager.GetInstance().HideDropzones();
			if( m_Entity.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
			{
				ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
			}
			else
			{
				ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
			}
			color = ColorManager.GREEN_COLOR;
		}
		else
		{
			color = ColorManager.RED_COLOR;
			ItemManager.GetInstance().ShowSourceDropzone( item );
		}

		if( w.FindAnyWidget("Selected") )
		{
			w.FindAnyWidget("Selected").SetColor( color );
		}
		else
		{
			string name = w.GetName();
			name.Replace( "PanelWidget", "Selected" );
			if( w.FindAnyWidget( name ) )
			{
				w.FindAnyWidget( name ).SetColor( color );
			}
		}

		return true;
	}

	void DropReceived( Widget w, int x, int y )
	{
		float xx, yy;
		GetMainWidget().Update();
		GetMainWidget().GetScreenSize( xx, yy );
		if( GetMainWidget().FindAnyWidget("Background") )
		{
			GetMainWidget().FindAnyWidget("Background").Show( true );
			GetMainWidget().FindAnyWidget("Background").SetSize( xx, yy );
		}
		EntityAI item = GetItemPreviewItem( w );
		if( !item )
		{
			return;
		}
		
		#ifdef PLATFORM_CONSOLE
		if( m_CargoGrid.HasItem( item ) )
		{
			return;
		}
		#endif
		
		#ifdef PLATFORM_CONSOLE
		int idx = -1;
		#else
		int idx = 0;
		#endif
		int c_x, c_y;
		
		CargoBase cargo = m_Entity.GetInventory().GetCargoFromIndex(m_CargoIndex);
		
		if( cargo )
		{
			c_x = cargo.GetHeight();
			c_y = cargo.GetWidth();
		}
		
		InventoryLocation dst = new InventoryLocation;
		#ifdef PLATFORM_CONSOLE
		x = 0;
		y = cargo.GetItemCount();
		m_Entity.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.CARGO, dst );
		#else
		dst.SetCargoAuto(cargo, item, x, y, item.GetInventory().GetFlipCargo());
		#endif
		
		InventoryLocation src = new InventoryLocation;
		item.GetInventory().GetCurrentInventoryLocation(src);
		if(src.CompareLocationOnly(dst))
			return;
		
		#ifdef PLATFORM_CONSOLE
		if(dst.IsValid() && m_Entity.GetInventory().LocationCanAddEntity(dst))
		#else
		if( c_x > x && c_y > y && m_Entity.GetInventory().LocationCanAddEntity(dst))
		#endif
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			
			SplitItemUtils.TakeOrSplitToInventoryLocation( player, dst );
			
			Icon icon = m_CargoGrid.GetIcon( item );
			
			if( icon && w && w.FindAnyWidget("Selected") )
			{
				w.FindAnyWidget("Selected").SetColor( ColorManager.BASE_COLOR );
				icon.Refresh();
				Refresh();
			}
		}
		
		ItemManager.GetInstance().HideDropzones();
		ItemManager.GetInstance().SetIsDragging( false );
	}
	
	void TakeIntoHands( notnull PlayerBase player, notnull EntityAI item )
	{
		ItemBase item_base = ItemBase.Cast( item );
		
		if( !item.GetInventory().CanRemoveEntity() || !player.CanManipulateInventory() )
			return;
		
		float stackable = item_base.GetTargetQuantityMax();
		
		if( stackable == 0 || stackable >= item_base.GetQuantity() )
		{
			player.PredictiveTakeEntityToHands( item );
		}
		else if( stackable != 0 && stackable < item_base.GetQuantity() )
		{
			item_base.SplitIntoStackMaxHandsClient( player );
		}
	}

	override void DraggingOverHeader( Widget w, int x, int y, Widget receiver )
	{
		DraggingOver( w, x, y, receiver );
	}

	override void DraggingOver( Widget w, int x, int y, Widget receiver )
	{
		if( !w )
			return;
		EntityAI item = GetItemPreviewItem( w );
		if( !item )
			return;
		
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if( item.GetInventory().CanRemoveEntity() && player.CanManipulateInventory() && ( m_Entity.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() ) && (!player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item )) ) || player.GetHumanInventory().HasEntityInHands( item ) )
		{
			ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
			ItemManager.GetInstance().HideDropzones();
			if( m_Entity.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
			{
				ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
			}
			else
			{
				ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
			}
		}
		else
		{
			ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
			ItemManager.GetInstance().ShowSourceDropzone( item );
		}
	}

	override void OnDropReceivedFromHeader( Widget w, int x, int y, Widget receiver )
	{
		EntityAI item = GetItemPreviewItem( w );
		if( !item )
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		InventoryLocation src = new InventoryLocation();
		if( GetEntity() && item.GetInventory().GetCurrentInventoryLocation(src))
		{
			InventoryLocation dst = new InventoryLocation();
			if (m_Entity.GetInventory().FindFreeLocationFor(item, FindInventoryLocationType.ATTACHMENT, dst))
			{
				player.PredictiveTakeToDst(src, dst);
			}

			bool can_add = m_Entity.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() );
			bool in_cargo = !player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item );
			if( can_add && in_cargo )
			{
				SplitItemUtils.TakeOrSplitToInventory( player, m_Entity, item );
			}
		}
	}
}
