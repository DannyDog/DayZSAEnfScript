class ContainerWithCargo: ClosableContainer
{
	protected ref CargoContainer	m_CargoGrid;

	void ContainerWithCargo( Container parent, int sort = -1 )
	{
		m_Parent = parent;

		m_CargoGrid = new CargoContainer( this );
		this.Insert( m_CargoGrid );
		
		m_CargoGrid.GetRootWidget().SetSort( 1 );
		
		#ifdef PLATFORM_CONSOLE
		m_RootWidget.FindAnyWidget( "CargoCount" ).Show( true );
		#endif
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
	
	override void SetNextActive()
	{
		Container.Cast( GetParent() ).SetNextActive();
		m_ActiveIndex = 1;
		UnfocusAll();
	}

	override void SetPreviousActive()
	{
		Container.Cast( GetParent() ).SetPreviousActive();
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

	void SetEntity( EntityAI entity )
	{
		m_Entity = entity;
		SetOpenState( ItemManager.GetInstance().GetDefaultOpenState( m_Entity.GetType() ) );

		Header h = Header.Cast( m_Body.Get( 0 ) );
		h.SetName( m_Entity.GetDisplayName() );
		h.SetItemPreview( m_Entity );

		m_CargoGrid.SetEntity( entity );
		
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
		
		if( m_Entity.GetInventory().GetCargo() )
		{
			c_x = m_Entity.GetInventory().GetCargo().GetHeight();
			c_y = m_Entity.GetInventory().GetCargo().GetWidth();
		}
		
		#ifdef PLATFORM_CONSOLE
		if( m_Entity.GetInventory().CanAddEntityInCargo( item ) && item.GetInventory().CanRemoveEntity() )
		#else
		if( m_Entity && c_x > x && c_y > y && m_Entity.GetInventory().CanAddEntityInCargoEx( item, 0, x, y ) && item.GetInventory().CanRemoveEntity() )
		#endif
		{
			ItemManager.GetInstance().HideDropzones();
			if( m_Entity.GetHierarchyParent() == GetGame().GetPlayer() )
			{
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
			else
			{
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "LeftPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
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
		int idx = -1;
		#else
		int idx = 0;
		#endif
		int c_x, c_y;
		
		if( m_Entity.GetInventory().GetCargo() )
		{
			c_x = m_Entity.GetInventory().GetCargo().GetHeight();
			c_y = m_Entity.GetInventory().GetCargo().GetWidth();
		}
		
		#ifdef PLATFORM_CONSOLE
		if( m_Entity.GetInventory().CanAddEntityInCargo( item ) )
		#else
		if( c_x > x && c_y > y && m_Entity.GetInventory().CanAddEntityInCargoEx( item, idx, x, y ) )
		#endif
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			
			TakeIntoCargo( player, m_Entity, item, idx, x, y );
			
			Icon icon = m_CargoGrid.GetIcon( item );
			
			if( icon && w && w.FindAnyWidget("Selected") )
			{
				w.FindAnyWidget("Selected").SetColor( ColorManager.BASE_COLOR );
				icon.Refresh();
				Refresh();
			}
		}
		
		ItemManager.GetInstance().HideDropzones();
	}
	
	void TakeIntoHands( notnull PlayerBase player, notnull EntityAI item )
	{
		ItemBase item_base = ItemBase.Cast( item );
		
		if( !item.GetInventory().CanRemoveEntity() || !player.CanManipulateInventory() )
			return;
		
		float stackable = item_base.ConfigGetFloat("varStackMax");
		
		if( stackable == 0 || stackable >= item_base.GetQuantity() )
		{
			player.PredictiveTakeEntityToHands( item );
		}
		else if( stackable != 0 && stackable < item_base.GetQuantity() )
		{
			item_base.SplitIntoStackMaxHandsClient( player );
		}
	}
	
	void TakeIntoCargo( notnull PlayerBase player, notnull EntityAI entity, notnull EntityAI item, int idx = -1, int row = 0, int col = 0 )
	{
		ItemBase item_base = ItemBase.Cast( item );
		
		if( !item.GetInventory().CanRemoveEntity() || !player.CanManipulateInventory() )
			return;
		
		float stackable = item_base.ConfigGetFloat("varStackMax");
		
		if( stackable == 0 || stackable >= item_base.GetQuantity() )
		{
			if( idx != -1 )
				player.PredictiveTakeEntityToTargetCargoEx( m_Entity, item, idx, row, col );
			else
				player.PredictiveTakeEntityToTargetCargo(m_Entity, item);
		}
		else if( stackable != 0 && stackable < item_base.GetQuantity() )
		{
			item_base.SplitIntoStackMaxCargoClient( entity, idx, row, col );
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
		if( item.GetInventory().CanRemoveEntity() && player.CanManipulateInventory() && ( m_Entity.GetInventory().CanAddEntityInCargo( item ) && (!player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item )) ) || player.GetHumanInventory().HasEntityInHands( item ) )
		{
			ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
			ItemManager.GetInstance().HideDropzones();
			if( m_Entity.GetHierarchyParent() == GetGame().GetPlayer() )
			{
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
			else
			{
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "LeftPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
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
		if( GetEntity() )
		{
			bool can_add = m_Entity.GetInventory().CanAddEntityInCargo( item );
			bool in_cargo = !player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item );
			if( can_add && in_cargo )
			{
				TakeIntoCargo( player, m_Entity, item );
			}
		}
	}
}
