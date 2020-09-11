class VicinitySlotsContainer: Container
{
	protected ref Container			m_Container;
	protected int					m_ItemsCount;
	protected int					m_SlotsCount;
	protected ref array<EntityAI>	m_ShowedItems;
	
	void VicinitySlotsContainer( LayoutHolder parent )
	{
		m_Container = new Container( this );
		ref SlotsContainer con = new SlotsContainer( m_Container, null );
		m_Container.Insert( con );
		m_Body.Insert( m_Container );
		for( int j = 0; j < ITEMS_IN_ROW; j++ )
		{
			SlotsIcon icon = con.GetSlotIcon( j );
			WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetPanelWidget(),  m_Parent, "OnDropReceivedFromIcon" );
			WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetGhostSlot(),  m_Parent, "OnDropReceivedFromHeader" );
			WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetMainWidget(),  m_Parent, "OnDropReceivedFromHeader" );
			
			WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetPanelWidget(),  m_Parent, "DraggingOverIcon" );
			WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetGhostSlot(),  m_Parent, "DraggingOverHeader" );
			WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetMainWidget(),  m_Parent, "DraggingOverHeader" );
			
			WidgetEventHandler.GetInstance().RegisterOnDoubleClick( icon.GetPanelWidget(),  this, "DoubleClick" );
			WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( icon.GetPanelWidget(),  this, "MouseClick" );
			WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( icon.GetPanelWidget(),  this, "MouseButtonDown" );
		}
		
		SlotsContainer.Cast( m_Container.Get( 0 ) ).SetColumnCount( 0 );
		
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( m_Container.GetMainWidget(),  m_Parent, "OnDropReceivedFromHeader" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( m_Container.GetMainWidget(),  m_Parent, "DraggingOverHeader" );
		m_SlotsCount++;
		
		m_ShowedItems = new array<EntityAI>;
	}
	
	EntityAI GetActiveItem()
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Icon" + m_FocusedColumn ).FindAnyWidget( "Render" + m_FocusedColumn ) );
		ItemManager.GetInstance().SetSelectedVicinityItem( ipw );
		return ipw.GetItem();
	}
	
	override EntityAI GetFocusedEntity()
	{
		return GetActiveItem();
	}
	
	bool IsItemWithContainerActive()
	{
		EntityAI ent = GetActiveItem();
		return ent && ( ent.GetInventory().GetCargo() || ent.GetSlotsCountCorrect() > 0 );
	}
	
	override bool IsItemWithQuantityActive()
	{
		EntityAI ent = GetActiveItem();
		return ent && QuantityConversions.HasItemQuantity( ent );
	}
	
	override bool IsItemActive()
	{
		EntityAI ent = GetActiveItem();
		return ent && !IsItemWithQuantityActive() && !IsItemWithContainerActive();
	}
	
	bool IsEmptyItemActive()
	{
		EntityAI ent = GetActiveItem();
		return ent == null;
	}
	
	override void UnfocusAll()
	{
		for ( int i = 0; i < m_Container.m_Body.Count(); i++ )
		{
			for ( int j = 0; j < ITEMS_IN_ROW; j++ )
			{
				m_Container.Get( i ).GetMainWidget().FindAnyWidget( "Cursor" + j ).Show( false );
			}
		}
	}
	
	override void MoveGridCursor( int direction )
	{
		ItemManager.GetInstance().HideTooltip();
		UnfocusAll();
		
		if( direction == Direction.RIGHT )
		{
			m_FocusedColumn++;
			if( m_FocusedColumn >= GetRowSlotCount() )
				m_FocusedColumn = 0;
		}
		else if( direction == Direction.LEFT )
		{
			m_FocusedColumn--;
			if( m_FocusedColumn < 0 )
				m_FocusedColumn = GetRowSlotCount() - 1;
		}
		else if( direction == Direction.UP )
		{
			m_FocusedRow--;
			if( m_FocusedRow < 0 )
			{
				m_FocusedRow = 0 ;
				LeftArea left_area = LeftArea.Cast( GetParent().GetParent() );
				left_area.SetPreviousActive();
				return;
			}				
		}
		else if( direction == Direction.DOWN )
		{
			m_FocusedRow++;
			if( m_FocusedRow == m_Container.m_Body.Count() )
			{
				m_FocusedRow = 0 ;
				left_area = LeftArea.Cast( GetParent().GetParent() );
				left_area.SetNextActive();
				return;
			}				
		}
		
		if( m_FocusedColumn < 0 )
			m_FocusedColumn = 0;
		
		m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).Show( true );
		
		LayoutHolder cnt = LayoutHolder.Cast( m_Container.Get( m_FocusedRow ) );
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( cnt.GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
		EntityAI focused_item =  item_preview.GetItem();

		if( focused_item )
		{
			float x, y;
			cnt.GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).GetScreenPos( x, y );
			ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
		}
	}
	
	override bool CanCombine()
	{
		ItemBase ent = ItemBase.Cast(  GetActiveItem() );
		ItemBase item_in_hands = ItemBase.Cast(	GetGame().GetPlayer().GetHumanInventory().GetEntityInHands() );
		
		return ( ItemManager.GetCombinationFlags( ent, item_in_hands ) != 0 );
	}
	
	override bool CanCombineAmmo()
	{
		PlayerBase m_player = PlayerBase.Cast( GetGame().GetPlayer() );
		ItemBase ent = ItemBase.Cast(  GetActiveItem() );
		ItemBase item_in_hands = ItemBase.Cast(	GetGame().GetPlayer().GetHumanInventory().GetEntityInHands() );
		ActionManagerClient amc;
		Class.CastTo(amc, m_player.GetActionManager());

		return ( amc.CanPerformActionFromInventory( item_in_hands, ent ) || amc.CanSetActionFromInventory( item_in_hands, ent ) );
	}
	
	override bool CanEquip()
	{
		EntityAI ent = GetActiveItem();
		InventoryLocation il = new InventoryLocation;
		bool found = GetGame().GetPlayer().GetInventory().FindFreeLocationFor(ent,FindInventoryLocationType.ATTACHMENT,il);
		if (found)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	override bool EquipItem()
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Icon" + m_FocusedColumn ).FindAnyWidget( "Render" + m_FocusedColumn ) );
		ItemManager.GetInstance().SetSelectedVicinityItem( ipw );
		EntityAI ent = ipw.GetItem();
		
		if( ent && !ent.IsInherited( Magazine ))
		{
			GetGame().GetPlayer().PredictiveTakeOrSwapAttachment( ent );
			return true;
		}
		return false;
	}
	
	override bool InspectItem()
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Icon" + m_FocusedColumn ).FindAnyWidget( "Render" + m_FocusedColumn ) );
		ItemManager.GetInstance().SetSelectedVicinityItem( ipw );
		EntityAI ent = ipw.GetItem();
		
		if( ent )
		{
			InspectItem( ent );
			return true;
		}
		return false;
	}
		
	override bool TransferItem()
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Icon" + m_FocusedColumn ).FindAnyWidget( "Render" + m_FocusedColumn ) );
		ItemManager.GetInstance().SetSelectedVicinityItem( ipw );
		EntityAI ent = ipw.GetItem();
		if( ent )
		{
			InventoryLocation il = new InventoryLocation;
			GetGame().GetPlayer().GetInventory().FindFreeLocationFor( ent, FindInventoryLocationType.CARGO, il );
			if( il.IsValid() && GetGame().GetPlayer().GetInventory().LocationCanAddEntity( il ) )
			{
				SplitItemUtils.TakeOrSplitToInventoryLocation( PlayerBase.Cast( GetGame().GetPlayer() ), il );
				return true;
			}
		}
		return false;
	}
	
	override bool Combine( )
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Icon" + m_FocusedColumn ).FindAnyWidget( "Render" + m_FocusedColumn ) );
		ItemManager.GetInstance().SetSelectedVicinityItem( ipw );
		ItemBase ent = ItemBase.Cast( ipw.GetItem() );
		
		ItemBase item_in_hands = ItemBase.Cast(	GetGame().GetPlayer().GetHumanInventory().GetEntityInHands() );
		
		Icon hands_icon = ItemManager.GetInstance().GetHandsPreview().GetIcon();
		
		if( item_in_hands && ent && hands_icon )
		{
			return hands_icon.CombineItems( item_in_hands, ent );
		}
		return true;
	}
	
	override bool SelectItem()
	{
		EntityAI ent = GetActiveItem();
		if( ent )
		{
			ItemManager.GetInstance().SetSelectedItem( ent, null, m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ) );
			return true;
		}
		return false;
	}
	
	override bool Select()
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Icon" + m_FocusedColumn ).FindAnyWidget( "Render" + m_FocusedColumn ) );
		ItemManager.GetInstance().SetSelectedVicinityItem( ipw );
		EntityAI ent = ipw.GetItem();
		
		if( ItemManager.GetInstance().IsItemMoving() )
		{
			ItemBase selected_item = ItemBase.Cast(ItemManager.GetInstance().GetSelectedItem());
			
			if( selected_item && GetGame().GetPlayer().CanDropEntity( selected_item ) )
			{
				bool draggable = false;

				PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
				draggable = !player.GetInventory().HasInventoryReservation( selected_item, null ) && !player.IsItemsToDelete();
				draggable = draggable && selected_item.CanPutIntoHands( GetGame().GetPlayer() );
				draggable = draggable && selected_item.GetInventory().CanRemoveEntity();
				
				if( draggable && m_ShowedItems.Find( selected_item ) == -1 )
				{
					if( selected_item.GetTargetQuantityMax() < selected_item.GetQuantity() )
						selected_item.SplitIntoStackMaxClient( null, -1 );
					else
						player.PhysicalPredictiveDropItem( selected_item );
					ItemManager.GetInstance().SetSelectedItem( null, null, null );
					return true;
				}
			}
		}
		
		if( ent && ent.GetInventory().CanRemoveEntity())
		{
			EntityAI item_in_hands = GetGame().GetPlayer().GetHumanInventory().GetEntityInHands();
			if( item_in_hands )
			{
				if( GameInventory.CanSwapEntitiesEx( item_in_hands, ent ) )
				{
					GetGame().GetPlayer().PredictiveSwapEntities( item_in_hands, ent );
					return true;
				}
			}
			else
			{
				if( GetGame().GetPlayer().GetHumanInventory().CanAddEntityInHands( ent ) )
				{
					GetGame().GetPlayer().PredictiveTakeEntityToHands( ent );
					return true;
				}
			}
		}
		
		return false;
	}
	
	void ~VicinitySlotsContainer()
	{
		for ( int i = 0; i < m_Container.Count(); i++ )
		{
			Container c = ClosableContainer.Cast( m_Container.Get( i / ITEMS_IN_ROW ) );
			if( c && c.GetMainWidget() )
			{
				delete m_Container.Get( i / ITEMS_IN_ROW ).GetMainWidget();
			}
		}
	}

	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.Container;
	}

	override void OnShow()
	{
		super.OnShow();
	}
	
	int GetRowSlotCount()
	{
		return SlotsContainer.Cast( m_Container.Get( m_FocusedRow ) ).GetColumnCount();
	}
	
	bool ExcludeFromContainer (EntityAI item)
	{
		if ( item.IsInherited(DayZAnimal) && item.IsAlive() )
		{
			return true;
		}
		else if ( item.IsInherited( DayZInfected ) || item.IsInherited( SurvivorBase ) || item.IsInherited( Car ) || item.IsInherited( GardenBase ) || item.IsInherited(DayZAnimal) || item.IsInherited( BaseBuildingBase ) )
		{
			return true;
		}	
		return false;
	}
	
	void ShowItemsInContainers( array<EntityAI> items )
	{
		EntityAI item;
		SlotsIcon icon;
		int x;
		int visible_items_count = 0;
		int visible_rows = 0;
		ref array<EntityAI> visible_items = new array<EntityAI>;
		
		for( x = 0; x < items.Count(); x++ )
		{
			item = items.Get( x );
			
			if (item == null || ExcludeFromContainer(item))
				continue;

			visible_items.Insert( item );
			visible_items_count++;
		}
		
		RecomputeNumberOfContainers( visible_items );
		
		for( x = 0; x < visible_items_count; x++ )
		{
			item			= visible_items.Get( x );
			int row			= Math.Floor( x / ITEMS_IN_ROW );
			int column		= x % ITEMS_IN_ROW;
			icon			= SlotsContainer.Cast( m_Container.Get( row ) ).GetSlotIcon( column );
			string config	= "CfgVehicles " + item.GetType() + " GUIInventoryAttachmentsProps";
			
			icon.GetMainWidget().Show( true );
			icon.GetPanelWidget().SetUserID( item.GetID() );
			
			if( m_ShowedItems.Find( item ) != x )
				icon.Init( item );
			icon.UpdateInterval();
			
			if( !ItemManager.GetInstance().IsDragging() )
			{
				ItemManager.GetInstance().SetTemperature( item, icon.GetRender() );
			}
			
			bool draggable = false;
			if( ItemBase.Cast( item ) )
			{
				PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
				draggable = !player.GetInventory().HasInventoryReservation( item, null ) && !player.IsItemsToDelete();
				draggable = draggable && item.CanPutIntoHands( GetGame().GetPlayer() );
				draggable = draggable && item.GetInventory().CanRemoveEntity();
			}
			
			if( !draggable && GetDragWidget() == icon.GetPanelWidget() )
				CancelWidgetDragging();
			ItemManager.GetInstance().SetWidgetDraggable( icon.GetPanelWidget(), draggable );

			ref map<int, ref Container> showed_items = ( VicinityContainer.Cast( m_Parent ) ).m_ShowedItemsIDs;
			
			int showed = showed_items.Count();
			ClosableContainer conta = ClosableContainer.Cast( showed_items.Get( item.GetID() ) );
			CollapsibleContainer conta2 = CollapsibleContainer.Cast( showed_items.Get( item.GetID() ) );
			
			bool show_radial_icon;
			if( conta )
			{
				show_radial_icon = conta.IsOpened();
				show_radial_icon = show_radial_icon && ( item.GetInventory().GetCargo() || item.GetSlotsCountCorrect() > 0 );
				show_radial_icon = show_radial_icon && !GetGame().ConfigIsExisting( config );
				show_radial_icon = show_radial_icon && !item.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT );
				icon.GetRadialIconPanel().Show( true );
				icon.GetRadialIcon().Show( !show_radial_icon );
				icon.GetRadialIconClosed().Show( show_radial_icon );		
			}
			else if( conta2 )
			{
				show_radial_icon = !conta2.IsHidden();
				Widget rip = icon.GetRadialIconPanel();
				rip.Show( !item.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ) );
				icon.GetRadialIcon().Show( !show_radial_icon );
				icon.GetRadialIconClosed().Show( show_radial_icon );
			}
			else
			{
				icon.GetRadialIconPanel().Show( false );
			}
		}
		
		SlotsContainer slots_last = SlotsContainer.Cast( m_Container.Get( visible_items.Count() / ITEMS_IN_ROW ) );
		for(int c = visible_items_count % ITEMS_IN_ROW; c < ITEMS_IN_ROW; c++)
		{
			icon = slots_last.GetSlotIcon( c );
			icon.GetMainWidget().Show( false );
			icon.Clear();
		}
		
		#ifndef PLATFORM_CONSOLE
		if( visible_items_count % ITEMS_IN_ROW == 0 )
		{
			slots_last = SlotsContainer.Cast( m_Container.Get( m_Container.Count() - 1 ) );
			slots_last.GetSlotIcon( 0 ).GetMainWidget().Show( true );
			slots_last.GetSlotIcon( 0 ).GetGhostSlot().Show( false );
			slots_last.GetMainWidget().Update();
		}
		#endif
		
		m_ShowedItems = visible_items;
	}
	
	void DoubleClick(Widget w, int x, int y, int button)
	{
		if( button == MouseState.LEFT )
		{
			if( w == null )
			{
				return;
			}
			ItemPreviewWidget iw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
			if( !iw )
			{
			  string name = w.GetName();
			  name.Replace( "PanelWidget", "Render" );
			  iw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
			} 
			
			if( !iw )
			{
			  iw = ItemPreviewWidget.Cast( w );
			}
			
			ItemBase item = ItemBase.Cast( iw.GetItem() );
			if( !item )
			{
				return;
			}
			
			if( GetGame().GetPlayer().GetInventory().HasInventoryReservation( item, null ) )
			{
				return;
			}
			
			if( !item.GetInventory().CanRemoveEntity() )
				return;
			
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
					
			if ( player.GetInventory().HasEntityInInventory( item ) && GetGame().GetPlayer().GetHumanInventory().CanAddEntityInHands( item ) )
			{
				player.PredictiveTakeEntityToHands( item );
			}
			else
			{
				InventoryLocation dst = new InventoryLocation;
				player.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.ANY, dst );
				if( dst.IsValid() && player.GetInventory().LocationCanAddEntity( dst ) )
				{
					SplitItemUtils.TakeOrSplitToInventoryLocation( player, dst );
				}
			}
			
			ItemManager.GetInstance().HideTooltip();
			InventoryMenu menu = InventoryMenu.Cast( GetGame().GetUIManager().FindMenu( MENU_INVENTORY ) );
			if( menu )
			{
				menu.RefreshQuickbar();
			}
		}
	}
	
	string GetItemQuantityText( EntityAI item )
	{
		string quantity_text = "";
		if ( item.IsInherited( InventoryItem ) )
		{
			ItemBase item_base = ItemBase.Cast( item );
			float quantity = item_base.GetQuantity();
			int ammo;
			if ( item.IsInherited( Magazine ) )
			{
				Magazine magazine_item = Magazine.Cast( item );
				ammo = magazine_item.GetAmmoCount();
				quantity_text = ammo.ToString();
				return quantity_text;
			}
			else if ( item.IsInherited( ItemBook ) )
			{
				return "";
			}
			int max = item.GetQuantityMax();
			string unit = item.ConfigGetString( "stackedUnit" );

			if ( max > 0 )
			{
				if ( max == 1 )
				{
					float tmp = Math.Round( ( quantity / max ) * 100 );
					quantity_text = tmp.ToString() + "%";
				}
				else
				{
					quantity_text = quantity.ToString();
				}
			}
		}
		return quantity_text;
	}
	
	int HasItemQuantity( EntityAI item )
	{
		if ( item.IsInherited( InventoryItem ) )
		{
			ItemBase item_base = ItemBase.Cast( item );
			if ( item.IsInherited( Magazine ) )
			{
				return QUANTITY_COUNT;
			}
			else if ( item.IsInherited( ItemBook ) )
			{
				return QUANTITY_HIDDEN;
			}
			int max = item.GetQuantityMax();
			bool bar = item.ConfigGetBool( "quantityBar" );
			if ( max > 0 )
			{
				if ( max == 1 || bar )
				{
					return QUANTITY_PROGRESS;
				}
				else
				{
					return QUANTITY_COUNT;
				}
			}
		}
		return QUANTITY_HIDDEN;
	}
	
	float GetItemQuantity( InventoryItem item )
	{
		float quantity = 0;
		if ( item.IsInherited( InventoryItem ) )
		{
			ItemBase item_base = ItemBase.Cast( item );
			if ( item.IsInherited( Magazine ) )
			{
				Magazine magazine_item = Magazine.Cast( item );
				quantity = magazine_item.GetAmmoCount();
			}
			else
			{
				quantity = item_base.GetQuantity();
			}
		}
		return quantity;
	}
	
	void MouseButtonDown( Widget w, int x, int y, int button)
	{
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		ItemBase item = ItemBase.Cast( item_preview.GetItem() );
		bool draggable = false;
		if( item )
		{
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
			draggable = !player.GetInventory().HasInventoryReservation( item, null ) && !player.IsItemsToDelete();
			draggable = draggable && item.CanPutIntoHands( GetGame().GetPlayer() );
			draggable = draggable && item.GetInventory().CanRemoveEntity();
		}
		
		ItemManager.GetInstance().SetWidgetDraggable( w, draggable );
	}
	
	void MouseClick( Widget w, int x, int y, int button)
	{
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		EntityAI item = item_preview.GetItem();
		InventoryItem itemAtPos = InventoryItem.Cast( item );
		Container conta;
		
		if( m_Parent )
		{
			ref map<int, ref Container> showed_items = ( VicinityContainer.Cast( m_Parent ) ).m_ShowedItemsIDs;
			
			if( item && showed_items )
			{
				conta = showed_items.Get( item.GetID() );
				( VicinityContainer.Cast( m_Parent ) ).ToggleContainer( conta );
				int showed = showed_items.Count();
				string config = "CfgVehicles " + item.GetType() + " GUIInventoryAttachmentsProps";
				
				if ( button == MouseState.RIGHT )
				{
					if ( itemAtPos )
					{
						itemAtPos.OnRightClick();
					}
				}
				else if ( button == MouseState.MIDDLE )
				{
					InspectItem( itemAtPos );
					return;
				}
			}
		}
	}
	
	override void OnDropReceivedFromHeader( Widget w, int x, int y, Widget receiver )
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget("Render") );
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
		
		if( !ipw.IsInherited( ItemPreviewWidget ) )
		{
			return;	
		}
		
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		ItemBase item = ItemBase.Cast(ipw.GetItem());
		
		if( item )
		{
			if( !item.GetInventory().CanRemoveEntity() )
				return;
			
			if( player.CanDropEntity( item ) )
			{
				if( item.GetTargetQuantityMax() < item.GetQuantity() )
					item.SplitIntoStackMaxClient( null, -1 );
				else
					player.PhysicalPredictiveDropItem( item );
			}
		}
	}
	
	void RecomputeNumberOfContainers( array<EntityAI> items )
	{
		int number_of_containers = m_Container.m_Body.Count();
		int number_of_containers_needed = ( items.Count() / ITEMS_IN_ROW ) + 1;
		int difference = number_of_containers_needed - number_of_containers;

		if( difference != 0 )
		{	
			if( difference > 0 )
			{
				for( int g = 0; g < difference; g++ )
				{
					SlotsContainer con = new SlotsContainer( m_Container, null );
					m_Container.Insert( con );
					for( int j = 0; j < ITEMS_IN_ROW; j++ )
					{
						SlotsIcon icon = con.GetSlotIcon( j );
						WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetPanelWidget(),  m_Parent, "OnDropReceivedFromIcon" );
						WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetGhostSlot(),  m_Parent, "OnDropReceivedFromHeader" );
						WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetMainWidget(),  m_Parent, "OnDropReceivedFromHeader" );
						
						WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetPanelWidget(),  m_Parent, "DraggingOverIcon" );
						WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetGhostSlot(),  m_Parent, "DraggingOverHeader" );
						WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetMainWidget(),  m_Parent, "DraggingOverHeader" );
						
						WidgetEventHandler.GetInstance().RegisterOnDoubleClick( icon.GetPanelWidget(),  this, "DoubleClick" );
						WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( icon.GetPanelWidget(),  this, "MouseClick" );
						WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( icon.GetPanelWidget(),  this, "MouseButtonDown" );
					}
					
					con.SetColumnCount( items.Count() % ITEMS_IN_ROW );
					m_SlotsCount++;
				}
			}
			else
			{
				for( int gx = 0; gx < ( difference * -1 ); gx++ )
				{
					Widget w = m_Container.m_Body.Get( m_SlotsCount - 1 ).GetMainWidget();
					delete w;
					m_Container.m_Body.Remove( m_SlotsCount - 1 );
					m_SlotsCount--;
				}
			}
			if( m_Parent )
			{
				m_Parent.Refresh();
				if( m_Parent.m_Parent )
				{
					m_Parent.m_Parent.Refresh();
				}
			}
		}
		
		if( (items.Count() % ITEMS_IN_ROW) == 0 )
		{
			SlotsContainer.Cast( m_Container.Get( number_of_containers_needed - 1 ) ).SetColumnCount( ITEMS_IN_ROW );
		}
		else
		{
			SlotsContainer.Cast( m_Container.Get( number_of_containers_needed - 1 ) ).SetColumnCount( items.Count() % ITEMS_IN_ROW );
		}
		
		for( int i = 0; i < number_of_containers_needed - 1; i++ )
		{
			SlotsContainer.Cast( m_Container.Get( i ) ).SetColumnCount( ITEMS_IN_ROW );
		}
	}
}
