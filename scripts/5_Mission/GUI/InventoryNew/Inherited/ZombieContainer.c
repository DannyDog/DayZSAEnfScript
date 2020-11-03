class ZombieContainer: CollapsibleContainer
{
	protected ref Container						m_Container;
	protected ref ContainerWithCargo			m_CargoGrid;
	protected ref map<int, SlotsIcon>			m_InventorySlots;
	protected ref map<EntityAI, ref Container>	m_ShowedItems = new ref map<EntityAI, ref Container>;
	protected EntityAI							m_ZombieEntity;
	
	void ZombieContainer( LayoutHolder parent, int sort = -1 )
	{
		m_InventorySlots = new ref map<int, SlotsIcon>;
		m_Container = new Container( this );
		m_Body.Insert( m_Container );
		
		m_MainWidget = m_RootWidget.FindAnyWidget( "body" );
		
		WidgetEventHandler.GetInstance().RegisterOnChildAdd( m_MainWidget, this, "OnChildAdd" );
		WidgetEventHandler.GetInstance().RegisterOnChildRemove( m_MainWidget, this, "OnChildRemove" );
		
		SetHeaderName();
	}
	
	void ~ZombieContainer()
	{
		if( m_ZombieEntity )
		{
			m_ZombieEntity.GetOnItemAttached().Remove(ItemAttached);
			m_ZombieEntity.GetOnItemDetached().Remove(ItemDetached);
		}
	}
	
	void SetEntity( EntityAI zombie_entity )
	{
		m_ZombieEntity = zombie_entity;
		m_ZombieEntity.GetOnItemAttached().Insert(ItemAttached);
		m_ZombieEntity.GetOnItemDetached().Insert(ItemDetached);
		InitGhostSlots();
		m_Parent.Refresh();
	}
	
	override bool IsLastIndex()
	{
		return m_ActiveIndex == m_Body.Count() - 1;
	}
	
	override bool IsFirstIndex()
	{
		return m_ActiveIndex == 1; 
	}
	
	override bool IsFirstContainerFocused()
	{
		return IsFirstIndex();
	}
	
	override bool IsLastContainerFocused()
	{
		return IsLastIndex();
	}
	
	override bool IsItemWithQuantityActive()
	{
		EntityAI ent = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
		return ent && QuantityConversions.HasItemQuantity( ent );
	}
	
	bool IsContainerWithCargoActive()
	{
		return GetFocusedContainer().IsInherited( ContainerWithCargo );
	}
	
	bool IsItemWithAttachmentsActive()
	{
		return GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments );
	}
	
	bool IsZombieEquipmentActive()
	{
		return GetFocusedContainer() == m_Container;
	}
	
	override bool IsItemActive()
	{
		return GetFocusedItem() != null;
	}
	
	bool IsItemWithContainerActive()
	{
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
		EntityAI ent = item_preview.GetItem();
		return ent && ( ent.GetInventory().GetCargo() || ent.GetSlotsCountCorrect() > 0 );
	}
	
	bool IsEmptyItemActive()
	{
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
		EntityAI ent = item_preview.GetItem();
		return ent == null;
	}
	
	void ExpandCollapseContainer()
	{
		if( IsZombieEquipmentActive() )
		{
			ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
			ToggleWidget( item_preview.GetParent() );
		}
	}
	
	override void OnDropReceivedFromHeader( Widget w, int x, int y, Widget receiver )
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
		
		if( !ipw.IsInherited( ItemPreviewWidget ) )
		{
			return;	
		}
		
		EntityAI item = ipw.GetItem();
		
		if( !item.GetInventory().CanRemoveEntity() )
			return;
		
		if (m_ZombieEntity.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() ))
			GetGame().GetPlayer().PredictiveTakeEntityToTargetCargo( m_ZombieEntity, item );
		else if( m_ZombieEntity.GetInventory().CanAddEntityToInventory( item ) )
		{
			GetGame().GetPlayer().PredictiveTakeEntityToTargetInventory( m_ZombieEntity, FindInventoryLocationType.CARGO, item );
		}
	}
	
	override void DraggingOverHeader( Widget w, int x, int y, Widget receiver )
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
		string name = receiver.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget receiver_iw = ItemPreviewWidget.Cast( receiver.FindAnyWidget( name ) );
		EntityAI receiver_item;
		if( receiver_iw )
		{
			receiver_item = receiver_iw.GetItem();
		}
		
		if( !ipw )
		{
			name = w.GetName();
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
		
		EntityAI item = ipw.GetItem();
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if( !item.GetInventory().CanRemoveEntity() )
			return;
	}
	
	void OnDropReceivedFromGhostArea( Widget w, int x, int y, Widget receiver )
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
		string name = receiver.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget receiver_iw = ItemPreviewWidget.Cast( receiver.FindAnyWidget( name ) );
		EntityAI receiver_item;
		if( receiver_iw )
		{
			receiver_item = receiver_iw.GetItem();
		}
		
		if( !ipw )
		{
			name = w.GetName();
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
		
		EntityAI item = ipw.GetItem();
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if( !item.GetInventory().CanRemoveEntity() )
			return;
		
		if( receiver_item )
		{
			if( receiver_item.GetInventory().CanAddAttachment( item ) )
			{
				player.PredictiveTakeEntityToTargetAttachment( receiver_item, item );
				return;
			}
			else if( receiver_item.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() ) && !receiver_item.GetInventory().HasEntityInCargo( item ) )
			{
				player.PredictiveTakeEntityToTargetInventory( receiver_item, FindInventoryLocationType.ANY, item );
				return;
			}
		}
		
		if( item )
		{
			if( m_ZombieEntity.GetInventory().CanAddAttachment( item ) )
			{
				player.PredictiveTakeEntityToTargetAttachment( m_ZombieEntity, item );
			}
			else if( m_ZombieEntity.GetInventory().CanAddEntityToInventory( item ) )
			{
				player.PredictiveTakeEntityToTargetInventory( m_ZombieEntity, FindInventoryLocationType.ANY, item );
			}
		}
		
		if( item )
		{
			if( m_ZombieEntity.GetInventory().CanAddEntityInto( item, FindInventoryLocationType.CARGO ) )
			{
				player.PredictiveTakeEntityToTargetInventory( m_ZombieEntity, FindInventoryLocationType.CARGO, item );
			}
		}
	}

	void SetHeaderName()
	{
		Header h = Header.Cast( m_Body.Get( 0 ) );
		h.SetName( "#container_inventory" );
	}
	
	void ItemAttached(EntityAI item, string slot_name)
	{
		int slot = InventorySlots.GetSlotIdFromString( slot_name );
		SlotsIcon icon = m_InventorySlots.Get( slot );
		if( icon )
		{
			icon.Init( item );

			if( m_ShowedItems.Contains( item ) == false )
			{
				string name;
				
				if( item.GetSlotsCountCorrect() > 0 )
				{
					ContainerWithCargoAndAttachments iwca = new ContainerWithCargoAndAttachments( this );
					iwca.SetEntity( item );
					WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( icon.GetPanelWidget(),  this, "ToggleWidget" );

					icon.GetRadialIconPanel().Show( true );
					m_ShowedItems.Insert( item, iwca );
					
					Refresh();
				}
				else if( item.GetInventory().GetCargo() )
				{
					ContainerWithCargo iwc = new ContainerWithCargo( this );
					iwc.SetEntity( item );
					iwc.UpdateInterval();
					WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( icon.GetPanelWidget(),  this, "ToggleWidget" );
					m_ShowedItems.Insert( item, iwc );
					icon.GetRadialIconPanel().Show(true);
					
					Refresh();
				}
			}
			
			ClosableContainer conta = ClosableContainer.Cast( m_ShowedItems.Get( item ) );
			string config = "CfgVehicles " + item.GetType() + " GUIInventoryAttachmentsProps";
			if( conta && conta.IsInherited( ClosableContainer ) )
			{
				bool show_radial_icon = ( item.GetInventory().GetCargo() || item.GetSlotsCountCorrect() > 0 ) && !GetGame().ConfigIsExisting( config );
				icon.GetRadialIconPanel().Show( show_radial_icon );
				Widget ric = icon.GetRadialIcon();
				ric.Show( !conta.IsOpened() );
				icon.GetRadialIconClosed().Show( conta.IsOpened() );
			}
		}
	}
	
	void ItemDetached(EntityAI item, string slot_name)
	{
		int slot = InventorySlots.GetSlotIdFromString( slot_name );
		SlotsIcon icon = m_InventorySlots.Get( slot );
		
		if( icon )
		{
			Container con = m_ShowedItems.Get( item );
			if( con )
			{
				( Container.Cast( con.m_Parent ) ).Remove( con );
				RecomputeOpenedContainers();
				GetMainWidget().Update();
				Refresh();
				m_ShowedItems.Remove( item );
			}
			
			icon.Clear();
			Inventory in = Inventory.Cast( GetRoot() );
			if( in )
				in.UpdateConsoleToolbar();
		}
	}
	
	override void RecomputeOpenedContainers()
	{
		m_OpenedContainers.Clear();
		m_OpenedContainers.Insert( m_Body[0] );
		m_OpenedContainers.Insert( m_Body[1] );
		for ( int i = 2; i < m_Body.Count(); i++ )
		{
			ClosableContainer cnt = ClosableContainer.Cast( m_Body.Get( i ) );
			if( cnt && cnt.IsOpened() )
			{
				m_OpenedContainers.Insert( cnt );
			}
		}
	}
	
	override void SetNextActive()
	{
		ItemManager.GetInstance().HideTooltip( );
		if( ItemManager.GetInstance().IsMicromanagmentMode() )
		{
			ItemManager.GetInstance().SetItemMoving( true );
		}
		
		if( IsLastIndex() )
		{
			Container.Cast( GetParent() ).SetNextActive();
			m_ActiveIndex = 1;
			UnfocusAll();
		}
		else
		{
			m_ActiveIndex++;
			GetFocusedContainer().SetActive( false );
			SetFocusedContainer( Container.Cast( m_Body.Get( m_ActiveIndex ) ) );
			GetFocusedContainer().SetActive( true );
		}
		
		if( m_IsActive && m_ActiveIndex == 1 )
			m_CollapsibleHeader.SetActive( true );
		else
			m_CollapsibleHeader.SetActive( false );
	}

	override void SetPreviousActive( bool force = false )
	{
		if( ItemManager.GetInstance().IsMicromanagmentMode() )
		{
			ItemManager.GetInstance().SetItemMoving( true );
		}
		
		if( IsFirstIndex() || force )
		{
			Container.Cast( GetParent() ).SetPreviousActive();
			m_ActiveIndex = 1;
			UnfocusAll();
		}
		else
		{
			m_ActiveIndex--;
			GetFocusedContainer().SetActive( false );
			SetFocusedContainer( Container.Cast( m_Body.Get( m_ActiveIndex ) ) );
			GetFocusedContainer().SetActive( true );
			GetFocusedContainer().SetLastActive();
		}
		
		if( m_IsActive && m_ActiveIndex == 1 )
			m_CollapsibleHeader.SetActive( true );
		else
			m_CollapsibleHeader.SetActive( false );
	}
	
	override void MoveGridCursor( int direction )
	{
		if( !GetFocusedContainer() || !GetFocusedContainer().IsActive() )
		{
			return;
		}

		float x, y;
		if( GetFocusedContainer() && ( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) ) )
		{
			ContainerWithCargo iwc = ContainerWithCargo.Cast( GetFocusedContainer() );
			ContainerWithCargoAndAttachments iwca = ContainerWithCargoAndAttachments.Cast( GetFocusedContainer() );
			if( iwc )
			{
				iwc.MoveGridCursor(direction);
			}
			else if( iwca )
			{
				iwca.MoveGridCursor(direction);
			}
		}
		else
		{
			ItemManager.GetInstance().HideTooltip();
			GetFocusedContainer().UnfocusAll();
			
			if( direction == Direction.UP )
			{
				m_FocusedRow--;
				if( m_FocusedRow <= 0 )
				{
					m_FocusedRow  = 0;
					RightArea right_area = RightArea.Cast( GetParent() );
					LeftArea left_area = LeftArea.Cast( GetParent() );
					if( right_area )
					{
						right_area.SetPreviousActive();
					}
					else
					{
						left_area.SetPreviousActive();
					}
				}				
			}
			else if( direction == Direction.DOWN )
			{
				m_FocusedRow++;
				if( m_FocusedRow >= m_InventorySlots.Count() / ITEMS_IN_ROW + 1 )
				{
					m_FocusedRow = m_Container.Count() - 1;
					m_Body.Get( m_ActiveIndex ).SetActive( false );
					m_ActiveIndex++;
					if( m_ActiveIndex > m_Body.Count() )
					{
						right_area = RightArea.Cast( GetParent() );
						left_area = LeftArea.Cast( GetParent() );
						if( right_area )
						{
							right_area.SetNextActive();
						}
						else
						{
							left_area.SetNextActive();
						}
					}
					else
					{
						SetFocusedContainer( Container.Cast( m_Body.Get( m_ActiveIndex ) ) );
						m_Body.Get( m_ActiveIndex ).SetActive( true );
					}
				}				
			}
			else if( direction == Direction.RIGHT )
			{
				m_FocusedColumn++;
				SlotsContainer cont = SlotsContainer.Cast( m_Container.Get( m_FocusedRow ) );
				if( m_FocusedColumn >= cont.GetColumnCount() )
				{
					m_FocusedColumn = 0;
				}
			}
			else if( direction == Direction.LEFT )
			{
				m_FocusedColumn--;
				SlotsContainer cont2 = SlotsContainer.Cast( m_Container.Get( m_FocusedRow ) );
				if( m_FocusedColumn < 0 )
				{
					m_FocusedColumn = cont2.GetColumnCount() - 1;
				}				
			}
			
			if( m_IsActive && m_ActiveIndex == 1 )
			{
				m_CollapsibleHeader.SetActive( true );
				Container cnt = Container.Cast( m_Body.Get( 1 ) );
	   			cnt.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).Show( true );
			}
			else
				m_CollapsibleHeader.SetActive( false );
		}
	}

	void ToggleContainer( Widget w )
	{
		EntityAI item;
		SlotsIcon slots_icon; 
		w.GetUserData(slots_icon);
		if(slots_icon)
			item = slots_icon.GetEntity();
		if( item )
		{
			ClosableContainer c = ClosableContainer.Cast( m_ShowedItems.Get( item ) );
			if( c.IsOpened() )
			{
				c.Close();
			}
			else
			{
				c.Open();
			}
		
			if( slots_icon )
			{
				Widget icon_open = slots_icon.GetRadialIcon();
				Widget icon_closed = slots_icon.GetRadialIconClosed();
				icon_open.Show( !c.IsOpened() );
				icon_closed.Show( c.IsOpened() );
			}
		}
	}

	void ToggleWidget( Widget w )
	{
		string name = w.GetName();
		if( !GetDragWidget() )
		{
			if( name.Contains( "GhostSlot" ) )
			{
				ClosableContainer cargo_cont = ClosableContainer.Cast( m_ShowedItems.Get( m_ZombieEntity ) );
				if( cargo_cont.IsOpened() )
				{
					cargo_cont.Close();
				}
				else
				{
					cargo_cont.Open();
				}
				name.Replace( "GhostSlot", "RadialIcon" );
				w.GetParent().FindAnyWidget( name ).Show( !cargo_cont.IsOpened() );
				name.Replace( "RadialIcon", "RadialIconClosed" );
				w.GetParent().FindAnyWidget( name ).Show( cargo_cont.IsOpened() );
			}
			else
			{
				//name.Replace( "PanelWidget", "Render" );
				//ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
				//SlotsIcon slot_icon; 
				//w.GetUserData(slot_icon);
				//if( slot_icon && slot_icon.GetEntity() )
				//{
					ToggleContainer( w );
				//}
			}
		}
	}
	
	SlotsIcon GetSlotsIcon( int row, int column )
	{
		return SlotsContainer.Cast( m_Container.Get( row ) ).GetSlotIcon( column );
	}

	void InitGhostSlots()
	{
		int row, column;
		SlotsIcon icon;
		
		string config_path_ghosts_slots = "CfgVehicles ZombieBase InventoryEquipment playerSlots";
		ref array<string> player_ghosts_slots = new array<string>;
		GetGame().ConfigGetTextArray( config_path_ghosts_slots, player_ghosts_slots );
		
		for ( int i = 0; i < player_ghosts_slots.Count(); i++ )
		{
			string slot_name = player_ghosts_slots.Get ( i );
			string path = "CfgSlots" + " " + slot_name;

			if ( GetGame().ConfigIsExisting( path ) )
			{
				string icon_name;
				GetGame().ConfigGetText( path + " ghostIcon", icon_name );
				column = i % ITEMS_IN_ROW;

				//START - GetWidgetSlot
				row = i / ITEMS_IN_ROW;
				if( row >= m_Container.Count() )
				{
					if( row < ( player_ghosts_slots.Count() / ITEMS_IN_ROW ) )
						AddSlotsContainer( ITEMS_IN_ROW );
					else
						AddSlotsContainer( player_ghosts_slots.Count() % ITEMS_IN_ROW );
				}
		
				icon = GetSlotsIcon( row, column );
				
				icon.GetMainWidget().Show( true );
				icon.Clear();
				
				WidgetEventHandler.GetInstance().RegisterOnDoubleClick( icon.GetPanelWidget(),  this, "DoubleClick" );
				
				//END - GetWidgetSlot
				WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetPanelWidget(),  this, "OnDropReceivedFromGhostArea" );
				WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetGhostSlot(),  this, "OnDropReceivedFromGhostArea" );
				WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetPanelWidget(),  this, "DraggingOver" );
				WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetGhostSlot(),  this, "DraggingOver" );
				WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetPanelWidget(),  this, "DraggingOver" );
				WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( icon.GetPanelWidget(),  this, "MouseClick" );
				
				icon.GetGhostSlot().LoadImageFile( 0, "set:dayz_inventory image:" + icon_name );
				//END - LoadIconIntoWidgetSlot

				GetGame().ConfigGetText( path + " name", slot_name );
				int slot_id = InventorySlots.GetSlotIdFromString( slot_name );
				//icon.GetGhostSlot().SetUserID( slot_id );
				//icon.GetPanelWidget().SetUserID( slot_id );
				icon.SetSlotID( slot_id );
				m_InventorySlots.Set( slot_id, icon );
				
				int slot = InventorySlots.GetSlotIdFromString( slot_name );
				ItemBase item = ItemBase.Cast( m_ZombieEntity.GetInventory().FindAttachment( slot ) );
				
				if( item )
					ItemAttached( item, slot_name );
			}
		}
		
		if( m_ZombieEntity.GetInventory().GetCargo() )
		{
			row = player_ghosts_slots.Count() / ITEMS_IN_ROW;
			column = player_ghosts_slots.Count() % ITEMS_IN_ROW;
			if( row >= m_Container.Count() )
			{
				if( row < ( player_ghosts_slots.Count() + 1 / ITEMS_IN_ROW ) )
					AddSlotsContainer( ITEMS_IN_ROW );
				else
					AddSlotsContainer( ( player_ghosts_slots.Count() + 1 ) % ITEMS_IN_ROW );
			}
			
			icon = GetSlotsIcon( row, column );
			icon.GetMainWidget().Show( true );
			icon.Clear();
			icon.GetGhostSlot().LoadImageFile( 0, "set:dayz_inventory image:cat_common_cargo" );
			icon.GetRadialIconPanel().Show( true );
			icon.GetRadialIcon().Show( true );
			
			WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( icon.GetGhostSlot(), this, "ToggleWidget" );
			m_CargoGrid = new ContainerWithCargo( this );
			m_CargoGrid.SetEntity( m_ZombieEntity );
			m_CargoGrid.GetHeader().GetMainWidget().ClearFlags( WidgetFlags.DRAGGABLE );
			m_ShowedItems.Insert( m_ZombieEntity, m_CargoGrid );
		}
	}
	
	void AddSlotsContainer( int row_count )
	{
		ref SlotsContainer s_cont = new SlotsContainer( m_Container, m_ZombieEntity );
		s_cont.SetColumnCount( row_count );
		m_Container.Insert( s_cont );
	}

	Widget GetWidgetSlot( int slot_number )
	{
		int row = slot_number / ITEMS_IN_ROW;
		int column = slot_number % ITEMS_IN_ROW;

		return m_Container.Get( row ).GetMainWidget().FindAnyWidget( "Render" + column );
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
			
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			
			if( player.GetInventory().HasInventoryReservation( item, null ) || player.IsItemsToDelete() )
			{
				return;
			}
			
			if( !item.GetInventory().CanRemoveEntity() )
				return;
					
			if ( player.GetInventory().HasEntityInInventory( item ) && GetGame().GetPlayer().GetHumanInventory().CanAddEntityInHands( item ) )
			{
				player.PredictiveTakeEntityToHands( item );
			}
			else
			{
				InventoryLocation il = new InventoryLocation;
				if( player.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.ANY, il) )
				{
					if( item.GetTargetQuantityMax(il.GetSlot()) < item.GetQuantity() )
						item.SplitIntoStackMaxToInventoryLocationClient( il );
					else
						player.PredictiveTakeEntityToInventory( FindInventoryLocationType.ANY, item );
				}
				else if( GetGame().GetPlayer().GetHumanInventory().CanAddEntityInHands( item ) )
				{
					if( item.GetTargetQuantityMax() < item.GetQuantity() )
						item.SplitIntoStackMaxHandsClient( player );
					else
						player.PredictiveTakeEntityToHands( item );
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

	override void CollapseButtonOnMouseButtonDown(Widget w)
	{
		super.CollapseButtonOnMouseButtonDown(w);
	}
	
	EntityAI GetFocusedItem()
	{
		EntityAI item;
		if( GetFocusedContainer() && ( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) ) )
		{
			return GetFocusedContainer().GetFocusedEntity();
		}
		else
		{
			item = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
		}
		return item;
	}
	
	override bool EquipItem()
	{
		if( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) )
		{
			return GetFocusedContainer().EquipItem();
		}
		else
		{
			EntityAI item = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
			if( item )
			{
				GetGame().GetPlayer().PredictiveTakeEntityToInventory( FindInventoryLocationType.ATTACHMENT, item );
				return true;
			}
		}
		return false;
	}
	
	override bool TransferItem()
	{
		LeftArea left_area = LeftArea.Cast( GetParent() );
		EntityAI item;
		if( left_area )
		{
			if( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) )
			{
				return GetFocusedContainer().TransferItem();
			}
			else
			{
				item = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
				if( item )
				{
					GetGame().GetPlayer().PredictiveTakeEntityToInventory( FindInventoryLocationType.CARGO, item );
					return true;
				}
			}
		}
		else
		{
			if( !GetFocusedContainer().IsInherited( ContainerWithCargo ) && !GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) )
			{
				item = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
				if( item )
				{
					GetGame().GetPlayer().PredictiveTakeEntityToInventory( FindInventoryLocationType.CARGO, item );
					return true;
				}
			}
		}
		return false;
	}
	
	override bool Select()
	{
		if( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) )
		{
			return GetFocusedContainer().Select();
		}
		else
		{
			if( ItemManager.GetInstance().IsItemMoving() )
			{
				EntityAI selected_item = ItemManager.GetInstance().GetSelectedItem();
				if( selected_item && selected_item.GetInventory().CanRemoveEntity() )
				{
					GetGame().GetPlayer().PredictiveTakeEntityToTargetInventory( m_ZombieEntity, FindInventoryLocationType.ANY, selected_item );
					ItemManager.GetInstance().SetSelectedItem( null, null, null );
					return true;
				}
			}
			else
			{
				EntityAI item = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
				if( item && item.GetInventory().CanRemoveEntity() )
				{
					EntityAI item_in_hands = GetGame().GetPlayer().GetHumanInventory().GetEntityInHands();
					if( item_in_hands && item_in_hands.GetInventory().CanRemoveEntity() )
					{
						if( GameInventory.CanSwapEntitiesEx( item_in_hands, item ) )
						{
							GetGame().GetPlayer().PredictiveSwapEntities( item_in_hands, item );
							return true;
						}
						else
						{
							InventoryLocation il_hands_dst = new InventoryLocation;
							if( GetGame().GetPlayer().GetHumanInventory().FindFreeLocationFor( item_in_hands, FindInventoryLocationType.ANY, il_hands_dst ) )
							{
								InventoryMode invMode = InventoryMode.PREDICTIVE;
					
								if ( GetGame().GetPlayer().NeedInventoryJunctureFromServer(item_in_hands, item_in_hands.GetHierarchyParent(), il_hands_dst.GetParent()) || GetGame().GetPlayer().NeedInventoryJunctureFromServer(item, item.GetHierarchyParent(), GetGame().GetPlayer()) )
									invMode = InventoryMode.JUNCTURE;
								
								GetGame().GetPlayer().GetHumanInventory().ForceSwapEntities( InventoryMode.JUNCTURE, item, item_in_hands, il_hands_dst );
								return true;
							}
						}
					}
					else
					{
						if( GetGame().GetPlayer().GetHumanInventory().CanAddEntityInHands( item ) )
						{
							GetGame().GetPlayer().PredictiveTakeEntityToHands( item );
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	
	override bool SelectItem()
	{
		if( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) )
		{
			return GetFocusedContainer().SelectItem();
		}
		else
		{
			ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
			ItemBase item = ItemBase.Cast( item_preview.GetItem() );
			ItemManager.GetInstance().SetSelectedItem( item, null, null );
			return true;
		}
		return false;
	}
	
	override bool TransferItemToVicinity()
	{
		if( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) )
		{
			return GetFocusedContainer().TransferItemToVicinity();
		}
		else
		{
			Man player = GetGame().GetPlayer();
			ItemBase item = ItemBase.Cast(GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity());
			if( item && player.CanDropEntity( item ) )
			{
				if( item.GetTargetQuantityMax() < item.GetQuantity() )
					item.SplitIntoStackMaxClient( null, -1 );
				else
					player.PhysicalPredictiveDropItem( item );
				return true;
			}
		}
		return false;
	}
	
	override bool InspectItem()
	{
		if( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) )
		{
			return GetFocusedContainer().InspectItem();
		}
		else
		{
			ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_Container.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
			ItemBase item = ItemBase.Cast( item_preview.GetItem() );
			if( item )
			{
				InspectItem( item );
				return true;
			}
		}
		return false;
	}
}
