class PlayerContainer: CollapsibleContainer
{
	protected ref Container						m_PlayerAttachmentsContainer;
	protected ref map<int, SlotsIcon>			m_InventorySlots;
	protected ref map<EntityAI, ref Container>	m_ShowedItems = new ref map<EntityAI, ref Container>;
	protected ref map<int, ref Container>		m_ShowedItemsIDs = new ref map<int, ref Container>;
	protected PlayerBase						m_Player;
	protected ScrollWidget						m_ScrollWidget;
	
	protected Widget							m_UpIcon;
	protected Widget							m_DownIcon;
	
	protected ref SizeToChild					m_ContentResize;
	protected bool								m_ShouldChangeSize = true;
	
	void MoveContainerUp( Container cont )
	{
		EntityAI entity = cont.GetFocusedContainerEntity();
		if( entity )
		{
			InventoryLocation loc = new InventoryLocation;
			entity.GetInventory().GetCurrentInventoryLocation( loc );
			if( loc.IsValid() )
			{
				int slot = loc.GetSlot();
				Inventory.MoveAttachmentUp( slot );
				UpdateSelectionIcons();
			}
		}
	}
	
	void MoveContainerDown( Container cont )
	{
		EntityAI entity = cont.GetFocusedContainerEntity();
		if( entity )
		{
			InventoryLocation loc = new InventoryLocation;
			entity.GetInventory().GetCurrentInventoryLocation( loc );
			if( loc.IsValid() )
			{
				int slot = loc.GetSlot();
				Inventory.MoveAttachmentDown( slot );
				UpdateSelectionIcons();
			}
		}
	}
	
	bool HasEntityContainerVisible( EntityAI entity )
	{
		ClosableContainer cont = ClosableContainer.Cast( m_ShowedItems.Get( entity ) );
		return ( cont && cont.IsOpened() );
	}
	
	SlotsIcon GetSlotsIcon( int row, int column )
	{
		return SlotsContainer.Cast( m_PlayerAttachmentsContainer.Get( row ) ).GetSlotIcon( column );
	}
	
	void PlayerContainer( LayoutHolder parent, int sort = -1 )
	{
		m_ScrollWidget	= ScrollWidget.Cast( parent.GetRootWidget().FindAnyWidget( "Scroller" ) );
		
		m_UpIcon		= parent.GetRootWidget().FindAnyWidget( "Up" );
		m_DownIcon		= parent.GetRootWidget().FindAnyWidget( "Down" );
		
		parent.GetRootWidget().FindAnyWidget( "ContentParent" ).GetScript( m_ContentResize );
		
		m_InventorySlots = new ref map<int, SlotsIcon>;
		m_PlayerAttachmentsContainer = new Container( this );
		m_Body.Insert( m_PlayerAttachmentsContainer );
		m_MainWidget = m_RootWidget.FindAnyWidget( "body" );
		WidgetEventHandler.GetInstance().RegisterOnChildAdd( m_MainWidget, this, "OnChildAdd" );
		WidgetEventHandler.GetInstance().RegisterOnChildRemove( m_MainWidget, this, "OnChildRemove" );
		
		//START - SetHeaderName
			m_CollapsibleHeader.SetName( "#container_inventory" );
		//END - SetHeaderName

		//START - InitGhostSlots
		string config_path_ghosts_slots = "CfgVehicles SurvivorBase InventoryEquipment playerSlots";
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
				int slot_number = i;
				int column = slot_number % ITEMS_IN_ROW;

				//START - GetWidgetSlot
				int row = slot_number / ITEMS_IN_ROW;
				if( row >= m_PlayerAttachmentsContainer.Count() )
				{
					if( row < ( player_ghosts_slots.Count() / ITEMS_IN_ROW ) )
						AddSlotsContainer( ITEMS_IN_ROW );
					else
						AddSlotsContainer( player_ghosts_slots.Count() % ITEMS_IN_ROW );
				}
		
				SlotsIcon icon = GetSlotsIcon( row, column );
				
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
				icon.SetSlotID(slot_id);
				m_InventorySlots.Set( slot_id, icon );
			}
		}
		m_PlayerAttachmentsContainer.GetMainWidget().Update();
		//END - InitGhostSlots
		RecomputeOpenedContainers();
	}
	
	void ~PlayerContainer()
	{
		if( m_Player )
		{
			m_Player.GetOnItemAttached().Remove(ItemAttached);
			m_Player.GetOnItemDetached().Remove(ItemDetached);
			m_Player.GetOnAttachmentSetLock().Remove(OnAttachmentReservationSet);
			m_Player.GetOnAttachmentReleaseLock().Remove(OnAttachmentReservationRelease);
		}
	}
	
	void ItemAttached(EntityAI item, string slot_name)
	{
		int slot = InventorySlots.GetSlotIdFromString( slot_name );
		SlotsIcon icon = m_InventorySlots.Get( slot );
		
		if( icon )
		{
			if( icon.IsReserved())
				m_Player.GetOnAttachmentReleaseLock().Invoke(item, slot);
			
			icon.Init( item );

			if( m_ShowedItems.Contains( item ) == false )
			{
				string name;
				int sort_index = Inventory.GetPlayerAttachmentIndex( slot );
				int current_sort = 9999;
				if( GetFocusedContainer() )
					current_sort = GetFocusedContainer().GetRootWidget().GetSort();
				
				if( item.GetSlotsCountCorrect() > 0 )
				{
					ContainerWithCargoAndAttachments iwca = new ContainerWithCargoAndAttachments( this, sort_index );
					iwca.SetEntity( item );
					WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( icon.GetPanelWidget(),  this, "ToggleWidget" );

					icon.GetRadialIconPanel().Show( true );
					if( sort_index <= current_sort )
						m_ActiveIndex++;
					m_ShowedItems.Insert( item, iwca );
					Refresh();
				}
				else if( item.GetInventory().GetCargo() )
				{
					ContainerWithCargo iwc = new ContainerWithCargo( this, sort_index );
					iwc.SetEntity( item );
					iwc.UpdateInterval();
					WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( icon.GetPanelWidget(),  this, "ToggleWidget" );
					m_ShowedItems.Insert( item, iwc );
					icon.GetRadialIconPanel().Show(true);
					if( sort_index <= current_sort )
						m_ActiveIndex++;
					
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
	
	void OnAttachmentReservationSet( EntityAI item, int slot_id )
	{
		SlotsIcon icon = m_InventorySlots.Get( slot_id );
		
		if( item )
		{
			icon.Init( item, true );
		}
	}
	
	void OnAttachmentReservationRelease( EntityAI item, int slot_id )
	{
		SlotsIcon icon = m_InventorySlots.Get( slot_id );
		icon.Clear();
	}
	
	void AddSlotsContainer( int row_count )
	{
		ref SlotsContainer s_cont = new SlotsContainer( m_PlayerAttachmentsContainer, m_Player );
		s_cont.SetColumnCount( row_count );
		m_PlayerAttachmentsContainer.Insert( s_cont );
	}
	
	override void SetActive( bool active )
	{
		super.SetActive( active );
		UpdateSelectionIcons();
	}
	
	void MouseClick( Widget w, int x, int y, int button )
	{
		
		SlotsIcon slots_icon;
		w.GetUserData(slots_icon);
		
		EntityAI item;
		bool reserved;
		
		
		if(slots_icon)
		{
			item = slots_icon.GetEntity();
			reserved = slots_icon.IsReserved();
		
		}

		ItemBase itemAtPos = ItemBase.Cast( item );
		
		if( item )
		{
			if ( button == MouseState.RIGHT )
			{
				if( reserved )
				{
					GetGame().GetPlayer().GetHumanInventory().ClearUserReservedLocation( item );
					m_Player.GetOnAttachmentReleaseLock().Invoke(item, slots_icon.GetSlotID());
				}
			}
			else if ( button == MouseState.MIDDLE )
			{
				if( !reserved )
				{
					InspectItem( itemAtPos );
				}
			} 
			else if ( button == MouseState.LEFT )
			{
				if( !reserved )
				{
					if ( g_Game.IsLeftCtrlDown() )
					{
						if( itemAtPos && itemAtPos.GetInventory().CanRemoveEntity() && m_Player.CanDropEntity(itemAtPos) )
						{
							if( itemAtPos.GetTargetQuantityMax() < itemAtPos.GetQuantity() )
								itemAtPos.SplitIntoStackMaxClient( null, -1 );
							else
								m_Player.PhysicalPredictiveDropItem( itemAtPos );
						}
					}
					else
					{
						bool draggable = !m_Player.GetInventory().HasInventoryReservation( item, null ) && !m_Player.GetInventory().IsInventoryLocked() && item.GetInventory().CanRemoveEntity() && !m_Player.IsItemsToDelete();
						ItemManager.GetInstance().SetWidgetDraggable( w, draggable );
					}
				}
			}
		}
	}
	
	override void SetFirstActive()
	{
		super.SetFirstActive();
		
		EntityAI focused_item = GetFocusedItem();
		if( focused_item )
		{
			float x, y;
			GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetCursorWidget().GetScreenPos( x, y );
			ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
		}
		m_ScrollWidget.VScrollToPos01( 0 );
	}
	
	override void SetLastActive()
	{
		super.SetLastActive();
		
		m_ScrollWidget.VScrollToPos01( 1 );
	}
	
	override void SetNextActive()
	{
		ItemManager.GetInstance().HideTooltip( );
		if( ItemManager.GetInstance().IsMicromanagmentMode() )
		{
			ItemManager.GetInstance().SetItemMoving( true );
		}
		Container active = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
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
			}
			if( next )
			{
				active.SetActive( false );
				next.SetActive( true );
				active = next;
				SetFocusedContainer( next );
				if( m_ActiveIndex == 1 )
					m_CollapsibleHeader.SetActive( true );
				else
					m_CollapsibleHeader.SetActive( false );
			}
			else
			{
				m_ActiveIndex = 1;
				Container first = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
				if( first )
				{
					active.SetActive( false );
					first.SetActive( true );
					active = first;
					SetFocusedContainer( first );
					m_CollapsibleHeader.SetActive( true );
					m_ScrollWidget.VScrollToPos01( 0 );
					if( m_ActiveIndex == 1 )
						m_CollapsibleHeader.SetActive( true );
					else
						m_CollapsibleHeader.SetActive( false );
				}
			}
		}
		
		ScrollToActiveContainer( active );
		UpdateSelectionIcons();
	}

	override void SetPreviousActive( bool force = false )
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
		}
		
		if( prev )
		{
			active.SetActive( false );
			prev.SetActive( true );
			active = prev;
			SetFocusedContainer( active );
			m_CollapsibleHeader.SetActive( false );
			active.SetLastActive();
			if( m_ActiveIndex == 1 )
			{
				UnfocusAll();
				m_CollapsibleHeader.SetActive( true );
				m_FocusedColumn = 0;
				m_FocusedRow = m_PlayerAttachmentsContainer.Count() - 1;
	   			GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetCursorWidget().Show( true );
				
				if( GetParent().IsInherited( RightArea ) )
				{
					m_ScrollWidget.VScrollToPos01( 0 );
				}
				
				EntityAI focused_item = GetFocusedItem();
				if( focused_item )
				{
					float x, y;
					GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetCursorWidget().GetScreenPos( x, y );
					ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
				}
			}
			else
				m_CollapsibleHeader.SetActive( false );
		}
		else
		{
			m_ActiveIndex = m_OpenedContainers.Count() - 1;
			Container first = Container.Cast( m_OpenedContainers[m_ActiveIndex] );
			if( first )
			{
				active.SetActive( false );
				first.SetActive( true );
				active = first;
				SetFocusedContainer( first );
				active.SetLastActive();
				m_ScrollWidget.VScrollToPos01( 1 );
			}
			if( m_ActiveIndex == 1 )
				m_CollapsibleHeader.SetActive( true );
			else
				m_CollapsibleHeader.SetActive( false );
		}
		
		ScrollToActiveContainer( active );
		UpdateSelectionIcons();
	}
	
	float GetMainContainerTopPos()
	{
		float x, y;
		GetRootWidget().GetScreenPos( x, y );
		return y;
	}
	
	float GetMainContainerBottomPos()
	{
		float x, y;
		float x2, y2;
		GetRootWidget().GetScreenPos( x, y );
		GetRootWidget().GetScreenSize( x2, y2 );
		y += y2;
		return y;
	}
	
	void UpdateSelectionIcons()
	{
		m_UpIcon.Show( m_IsActive );
		m_DownIcon.Show( m_IsActive );
		if( m_IsActive )
		{
			float x, y;
			m_UpIcon.GetScreenSize( x, y );
			
			float top_y		= GetCurrentContainerTopY();
			m_UpIcon.SetPos( 0, Math.Clamp( top_y, 0, 99999 ) );
			
			#ifndef PLATFORM_CONSOLE
			float x2, y2;
			m_DownIcon.GetScreenSize( x2, y2 );
			float bottom_y	= GetCurrentContainerBottomY() - y2;
			
			float diff		= bottom_y - ( top_y + y );
			if( diff < 0 )
			{
				top_y += diff / 2;
				bottom_y -= diff / 2;
			}
			m_DownIcon.SetPos( 0, bottom_y );
			#endif
		}
	}
	
	float GetCurrentContainerTopY()
	{
		float x, y;
		GetParent().GetMainWidget().Update();
		GetParent().GetMainWidget().GetScreenPos( x, y );
		float cont_screen_pos = GetFocusedContainerYScreenPos();
		
		return cont_screen_pos - y;
	}
	
	float GetCurrentContainerBottomY()
	{
		float x, y;
		GetParent().GetMainWidget().Update();
		GetParent().GetMainWidget().GetScreenPos( x, y );
		
		float cont_screen_pos		= GetFocusedContainerYScreenPos();
		float cont_screen_height	= GetFocusedContainerHeight();
		return cont_screen_pos - y + cont_screen_height;
	}
	
	override void Insert( LayoutHolder container, int pos = -1 )
	{
		ClosableContainer c_cont = ClosableContainer.Cast( container );
		if( c_cont && m_Body.Count() > 2 )
		{
			ClosableContainer prev	= ClosableContainer.Cast( m_Body.Get( 2 ) );
			int index				= 2;
			int curr_sort			= c_cont.GetRootWidget().GetSort();
			while( prev )
			{
				int prev_sort = prev.GetRootWidget().GetSort();
				if( prev_sort > curr_sort )
					break;
				if( ++index < m_Body.Count() )
					prev = ClosableContainer.Cast( m_Body.Get( index ) );
				else
					break;
			}
			
			m_Body.InsertAt( container, index );
		}
		else
		{
			m_Body.Insert( container );
		}
		
		RecomputeOpenedContainers();
	}
	
	bool IsItemWithContainerActive()
	{
		EntityAI ent = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
		return ent && ( ent.GetInventory().GetCargo() || ent.GetSlotsCountCorrect() > 0 );
	}
	
	override bool IsItemWithQuantityActive()
	{
		EntityAI ent = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
		return ent && QuantityConversions.HasItemQuantity( ent );
	}
	
	override bool IsItemActive()
	{
		EntityAI ent = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
		return ent && !IsItemWithQuantityActive() && !IsItemWithContainerActive();
	}
	
	bool IsEmptyItemActive()
	{
		EntityAI ent = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
		return ent == null;
	}
	
	void UnfocusPlayerAttachmentsContainer()
	{
		m_PlayerAttachmentsContainer.UnfocusAll();
	}
	
	void DoubleClick(Widget w, int x, int y, int button)
	{
		if( button == MouseState.LEFT )
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			
			if( w == null || m_Player.GetInventory().IsInventoryLocked() )
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
				
			SlotsIcon icon;
			iw.GetUserData(icon);
		
			if(icon && icon.IsReserved())
			{
				return;
			}
			
			if( !item.GetInventory().CanRemoveEntity() )
				return;
			
			if ( player.GetInventory().HasEntityInInventory( item ) && player.GetHumanInventory().CanAddEntityInHands( item ) )
			{
				player.PredictiveTakeEntityToHands( item );
			}
			else
			{
				if (player.GetInventory().CanAddEntityToInventory( item ) && item.GetInventory().CanRemoveEntity())
				{
					if( item.GetTargetQuantityMax() < item.GetQuantity() )
						item.SplitIntoStackMaxClient( player, -1 );
					else
						player.PredictiveTakeEntityToInventory( FindInventoryLocationType.ANY, item );
				}
				else
				{
					if( item.GetTargetQuantityMax() < item.GetQuantity() )
						item.SplitIntoStackMaxHandsClient( player );
					else
						player.PredictiveTakeEntityToHands( item );
				}
			}
			ToggleWidget( w );
			ItemManager.GetInstance().HideTooltip();
	
			InventoryMenu menu = InventoryMenu.Cast( GetGame().GetUIManager().FindMenu( MENU_INVENTORY ) );
			if ( menu )
			{
				menu.RefreshQuickbar();
			}
		}
	}
	
	void ExpandCollapseContainer()
	{
		if( m_PlayerAttachmentsContainer.IsActive() )
		{
			ToggleWidget( GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetPanelWidget() );
		}
	}
	
	bool IsContainerWithCargoActive()
	{
		return GetFocusedContainer().IsInherited( ContainerWithCargo );
	}
	
	bool IsItemWithAttachmentsActive()
	{
		return GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments );
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
			Man player = GetGame().GetPlayer();
			EntityAI item = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
			if( item )
			{
				InspectItem( item );
				return true;
			}
		}
		return false;
	}
	
	int GetRecipeCount( bool recipe_anywhere, EntityAI entity1, EntityAI entity2 )
	{
		PluginRecipesManager plugin_recipes_manager = PluginRecipesManager.Cast( GetPlugin( PluginRecipesManager ) );
		return plugin_recipes_manager.GetValidRecipes( ItemBase.Cast( entity1 ), ItemBase.Cast( entity2 ), null, PlayerBase.Cast( GetGame().GetPlayer() ) );
	}
	
	override bool CanCombine()
	{
		ItemBase ent =  ItemBase.Cast( GetFocusedItem() );
		ItemBase item_in_hands = ItemBase.Cast(	GetGame().GetPlayer().GetHumanInventory().GetEntityInHands() );
		
		return GetRecipeCount( false, ent, item_in_hands ) > 0;
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
	
	override bool Combine()
	{
		if( GetFocusedContainer() && ( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) ) )
		{
			return GetFocusedContainer().Combine();
		}
		else
		{
			EntityAI item = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
			ItemBase item_in_hands = ItemBase.Cast(	GetGame().GetPlayer().GetHumanInventory().GetEntityInHands() );
			
			Icon hands_icon = ItemManager.GetInstance().GetHandsPreview().GetIcon();
						
			if( item_in_hands && item )
			{
				return hands_icon.CombineItems( item_in_hands, item );
			}
		}
		return true;
	}
	
	override bool SelectItem()
	{
		if( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) )
		{
			return GetFocusedContainer().SelectItem();
		}
		else
		{
			EntityAI item = GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetEntity();
			if( item )
			{
				ItemManager.GetInstance().SetSelectedItem( item, null, null );
				return true;
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
					if( m_Player.GetInventory().CanRemoveAttachment( selected_item ) )
					{
						GetGame().GetPlayer().PredictiveTakeEntityToInventory( FindInventoryLocationType.ATTACHMENT, selected_item );
						ItemManager.GetInstance().SetSelectedItem( null, null, null );
						return true;
					}
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
								
								GetGame().GetPlayer().GetHumanInventory().ForceSwapEntities( invMode, item, item_in_hands, il_hands_dst );
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
			ScrollToActiveContainer( GetFocusedContainer() );
		}
		else
		{
			ItemManager.GetInstance().HideTooltip();
			GetFocusedContainer().UnfocusAll();
			
			if( direction == Direction.UP )
			{
				m_FocusedRow--;
				if( m_FocusedRow < 0 )
				{
					m_FocusedRow  = 1;
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
					return;
				}
				else
				{
					SlotsContainer cont3 = SlotsContainer.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ) );
					if( m_FocusedColumn >= cont3.GetColumnCount() )
					{
						m_FocusedColumn = cont3.GetColumnCount() - 1;
					}
					else if( m_FocusedColumn < 0 )
					{
						m_FocusedColumn = 0;
					}
				}
			}
			else if( direction == Direction.DOWN )
			{
				m_FocusedRow++;
				if( m_FocusedRow == 2 )
				{
					m_FocusedRow = 0;
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
					return;
				}
				else
				{
					SlotsContainer cont4 = SlotsContainer.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ) );
					if( m_FocusedColumn >= cont4.GetColumnCount() )
					{
						m_FocusedColumn = cont4.GetColumnCount() - 1;
					}
					else if( m_FocusedColumn < 0 )
					{
						m_FocusedColumn = 0;
					}
				}
			}
			else if( direction == Direction.RIGHT )
			{
				m_FocusedColumn++;
				SlotsContainer cont = SlotsContainer.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ) );
				if( m_FocusedColumn >= cont.GetColumnCount() )
				{
					m_FocusedColumn = 0;
				}
			}
			else if( direction == Direction.LEFT )
			{
				m_FocusedColumn--;
				SlotsContainer cont2 = SlotsContainer.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ) );
				if( m_FocusedColumn < 0 )
				{
					m_FocusedColumn = cont2.GetColumnCount() - 1;
				}
			}
			
			GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetCursorWidget().Show( true );
			
			EntityAI focused_item = GetFocusedItem();
			if( focused_item )
			{
				GetSlotsIcon( m_FocusedRow, m_FocusedColumn ).GetCursorWidget().GetScreenPos( x, y );
				ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
			}
			
			ScrollToActiveContainer( Container.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ) ) );
		}
		
		UpdateSelectionIcons();
	}
	
	void ScrollToActiveContainer( Container active_container )
	{
		if( !active_container )
			return;
		float x, y, y_s;
		m_ScrollWidget.GetScreenPos( x, y );
		m_ScrollWidget.GetScreenSize( x, y_s );
		float amount;
		float next_pos	= active_container.GetFocusedContainerYScreenPos( true ) + active_container.GetFocusedContainerHeight( true );
			
		if( next_pos > ( y + y_s ) )
		{
			amount	= y + active_container.GetFocusedContainerYScreenPos( true );
			m_ScrollWidget.VScrollToPos( m_ScrollWidget.GetVScrollPos() + active_container.GetFocusedContainerHeight( true ) + 2 );
		}
		else if( active_container.GetFocusedContainerYScreenPos( true ) < y )
		{
			amount = active_container.GetFocusedContainerYScreenPos( true ) - y;
			m_ScrollWidget.VScrollToPos( m_ScrollWidget.GetVScrollPos() + amount - 2 );
		}
	}

	void SetPlayer( PlayerBase player )
	{
		if( m_Player )
		{
			m_Player.GetOnItemAttached().Remove(ItemAttached);
			m_Player.GetOnItemDetached().Remove(ItemDetached);
			m_Player.GetOnAttachmentSetLock().Remove(OnAttachmentReservationSet);
			m_Player.GetOnAttachmentReleaseLock().Remove(OnAttachmentReservationRelease);
		}
		m_Player = player;
		if( m_Player )
		{
			m_Player.GetOnItemAttached().Insert(ItemAttached);
			m_Player.GetOnItemDetached().Insert(ItemDetached);
			m_Player.GetOnAttachmentSetLock().Insert(OnAttachmentReservationSet);
			m_Player.GetOnAttachmentReleaseLock().Insert(OnAttachmentReservationRelease);
		}
		
		//START - InitGhostSlots
		string config_path_ghosts_slots = "CfgVehicles SurvivorBase InventoryEquipment playerSlots";
		ref array<string> player_ghosts_slots = new array<string>;
		GetGame().ConfigGetTextArray( config_path_ghosts_slots, player_ghosts_slots );

		for ( int i = 0; i < player_ghosts_slots.Count(); i++ )
		{
			string slot_name = player_ghosts_slots.Get ( i );

			int column = i % ITEMS_IN_ROW;
			int row = i / ITEMS_IN_ROW;
	
			SlotsIcon icon = GetSlotsIcon( row, column );
			
			icon.GetMainWidget().Show( true );
			icon.Clear();
			
			GetGame().ConfigGetText( "CfgSlots" + " " + slot_name + " name", slot_name );
			EntityAI item = m_Player.GetInventory().FindAttachment( InventorySlots.GetSlotIdFromString( slot_name ) );
			if( item )
			{
				ItemAttached( item, slot_name );
			}
		}
	}

	override void OnDropReceivedFromHeader( Widget w, int x, int y, Widget receiver )
	{
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( GetItemPreviewWidget( w ) );

		if( !ipw.IsInherited( ItemPreviewWidget ) )
		{
			return;
		}

		EntityAI item = ipw.GetItem();
		if( !item )
		{
			return;
		}

		if( !item.GetInventory().CanRemoveEntity() )
			return;
		
		if( m_Player.GetInventory().CanAddEntityToInventory( item, FindInventoryLocationType.CARGO | FindInventoryLocationType.ATTACHMENT ) && ( !m_Player.GetInventory().HasEntityInInventory( item ) ) || m_Player.GetHumanInventory().HasEntityInHands( item ) )
		{
			Print("HELLO");
			m_Player.PredictiveTakeEntityToInventory( FindInventoryLocationType.CARGO | FindInventoryLocationType.ATTACHMENT, item );
		}
	}

	ItemPreviewWidget GetItemPreviewWidget( Widget w )
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

		return ipw;
	}

	override void DraggingOverHeader( Widget w, int x, int y, Widget receiver )
	{
		if( w == null )
		{
			return;
		}
		ItemPreviewWidget ipw = GetItemPreviewWidget( w );

		if( !ipw || !ipw.IsInherited( ItemPreviewWidget ) )
		{
			return;
		}

		EntityAI item = ipw.GetItem();
		if( !item )
		{
			return;
		}

		if( m_Player.GetInventory().CanAddEntityToInventory( item, FindInventoryLocationType.CARGO | FindInventoryLocationType.ATTACHMENT ) && ( !m_Player.GetInventory().HasEntityInInventory( item ) ) || m_Player.GetHumanInventory().HasEntityInHands( item ) )
		{
			ItemManager.GetInstance().HideDropzones();
			ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
			ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
		}
		else
		{
			ItemManager.GetInstance().HideDropzones();
			ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
			ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
			//ItemManager.GetInstance().ShowSourceDropzone( item );
		}
	}

	override void DraggingOver( Widget w, int x, int y, Widget receiver )
	{
		if( w == null )
		{
			return;
		}
		
		EntityAI receiver_item;
		bool is_reserved = false;
		
		SlotsIcon slots_icon;
		receiver.GetUserData(slots_icon);
		
		if(slots_icon)
		{
			receiver_item = slots_icon.GetEntity();
			is_reserved = slots_icon.IsReserved();
		}

		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( GetItemPreviewWidget( w ) );

		if( !ipw || !ipw.IsInherited( ItemPreviewWidget ) )
		{
			return;
		}

		EntityAI item = ipw.GetItem();
		if( !item )
		{
			return;
		}
		
		if( receiver_item && !is_reserved )
		{
			if( GameInventory.CanSwapEntitiesEx( receiver_item, item ) )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.SWAP_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
				return;
			}
			else if( receiver_item.GetInventory().CanAddAttachment(item) || receiver_item.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() ) && !receiver_item.GetInventory().HasEntityInCargo( item ))
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
				return;
			}
			else if( ( ItemBase.Cast( receiver_item ) ).CanBeCombined( ItemBase.Cast( item ) ) )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.COMBINE_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
				return;
			}

		}
		
		if( item.GetInventory().CanRemoveEntity() )
		{
			if( m_Player.GetInventory().CanAddAttachment( item) )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
			}
			else if( m_Player.GetInventory().CanAddEntityToInventory( item, FindInventoryLocationType.CARGO | FindInventoryLocationType.ATTACHMENT ) && ( !m_Player.GetInventory().HasEntityInInventory( item ) ) || m_Player.GetHumanInventory().HasEntityInHands( item ) )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
			}
			else if ( receiver_item && GameInventory.CanSwapEntitiesEx( receiver_item, item ) )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.SWAP_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
			}
			else
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
			}
		}
		else
		{
			ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
			ItemManager.GetInstance().HideDropzones();
			ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
			//ItemManager.GetInstance().ShowSourceDropzone( item );
		}
	}

	void OnDropReceivedFromGhostArea( Widget w, int x, int y, Widget receiver )
	{
		ItemManager.GetInstance().HideDropzones();
		ItemManager.GetInstance().SetIsDragging( false );
		
		EntityAI receiver_item;
		bool is_reserved = false;
		InventoryMenu menu = InventoryMenu.Cast( GetGame().GetUIManager().FindMenu( MENU_INVENTORY ) );
		float stack_max;

		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( GetItemPreviewWidget( w ) );
		SlotsIcon slots_icon;
		receiver.GetUserData(slots_icon);
		int slot_id = slots_icon.GetSlotID();
		
		receiver_item = slots_icon.GetEntity();
		is_reserved = slots_icon.IsReserved();

		if ( !ipw )
		{
			return;
		}

		ItemBase item = ItemBase.Cast(ipw.GetItem());
		PlayerBase real_player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( !item )
		{
			return;
		}
		if ( receiver_item && !is_reserved )
		{
			if ( GameInventory.CanSwapEntitiesEx( receiver_item, item ) )
			{
				GetGame().GetPlayer().PredictiveSwapEntities( item, receiver_item );

				if ( menu )
				{
					menu.RefreshQuickbar();
				}
				return;
			}
			else if ( receiver_item.GetInventory().CanAddAttachment( item ) )
			{
				GetGame().GetPlayer().PredictiveTakeEntityToTargetAttachment( receiver_item, item );

				if ( menu )
				{
					menu.RefreshQuickbar();
				}
				return;
			}
			else if ( receiver_item.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() ) && !receiver_item.GetInventory().HasEntityInCargo( item ) )
			{
				SplitItemUtils.TakeOrSplitToInventory(real_player, receiver_item,item);

				if ( menu )
				{
					menu.RefreshQuickbar();
				}
				return;
			}
			else if ( ( ItemBase.Cast( receiver_item ) ).CanBeCombined( ItemBase.Cast( item ) ) )
			{
				( ItemBase.Cast( receiver_item ) ).CombineItemsClient( ItemBase.Cast( item ) );
				return;
			}
		}
		
		if ( m_Player.GetInventory().CanAddAttachmentEx( item, slot_id ) )
		{			
			if (item.GetQuantity() > item.GetTargetQuantityMax(slot_id))
			{
				item.SplitIntoStackMaxClient( real_player, slot_id );
			}
			else
			{
				real_player.PredictiveTakeEntityToTargetAttachmentEx( m_Player, item, slots_icon.GetSlotID() );
			}
		}
		else if (  m_Player.GetInventory().CanAddAttachment( item ) )
		{
			float stackable = item.GetTargetQuantityMax(-1);
		
			if ( stackable == 0 || stackable >= item.GetQuantity() )
			{
				real_player.PredictiveTakeEntityToTargetAttachment( m_Player, item );
			}
			else
			{
				InventoryLocation il = new InventoryLocation;
				m_Player.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.ATTACHMENT, il );
				ItemBase.Cast(item).SplitIntoStackMaxToInventoryLocationClient( il );
			}
		}
		else if(  m_Player.GetInventory().CanAddEntityToInventory( item, FindInventoryLocationType.CARGO | FindInventoryLocationType.ATTACHMENT ) && ( !m_Player.GetInventory().HasEntityInInventory( item ) ) || m_Player.GetHumanInventory().HasEntityInHands( item ) )
		{
			SplitItemUtils.TakeOrSplitToInventory(m_Player, m_Player, item);
		}

		if ( menu )
		{
			menu.RefreshQuickbar();
		}
	}
	
	void SwapItemsInOrder( int slot1, int slot2 )
	{
		EntityAI item1	= m_Player.GetInventory().FindAttachment( slot1 );
		EntityAI item2	= m_Player.GetInventory().FindAttachment( slot2 );
		
		if( item1 && item2 )
		{
			Container cont1	= m_ShowedItems.Get( item1 );
			Container cont2	= m_ShowedItems.Get( item2 );
			if( cont1 && cont2 )
			{
				int sort1		= cont1.GetRootWidget().GetSort();
				int sort2		= cont2.GetRootWidget().GetSort();
				
				cont1.GetRootWidget().SetSort( sort2 );
				cont2.GetRootWidget().SetSort( sort1 );
				
				m_Body.SwapItems( m_Body.Find( cont1 ), m_Body.Find( cont2 ) );
				m_OpenedContainers.SwapItems( m_OpenedContainers.Find( cont1 ), m_OpenedContainers.Find( cont2 ) );
			}
		}
	}

	override void UpdateInterval()
	{
		int i;
		for( i = 0; i < m_InventorySlots.Count(); i++ )
		{
			SlotsIcon icon = m_InventorySlots.GetElement( i );
			if( icon )
			{
				icon.UpdateInterval();
			}
		}
		for( i = 0; i < m_ShowedItems.Count(); i++ )
		{
			Container cont = m_ShowedItems.GetElement( i );
			if( cont )
			{
				cont.UpdateInterval();
			}
		}
		
		bool changed_size;
		if( m_ShouldChangeSize )
			m_ContentResize.ResizeParentToChild( changed_size );
		if( changed_size )
		{
			CheckScrollbarVisibility();
			m_ShouldChangeSize = false;
		}
	}

	void ToggleContainer( Widget w, EntityAI item )
	{
		InventoryLocation il = new InventoryLocation;
		item.GetInventory().GetCurrentInventoryLocation( il );
		SlotsIcon icon = m_InventorySlots.Get( il.GetSlot() );
		ClosableContainer c = ClosableContainer.Cast( m_ShowedItems.Get( item ) );
		if( c == null )
		{
			return;
		}

		if( c.IsOpened() )
		{
			c.Close();
		}
		else
		{
			c.Open();
		}
		
		if( icon )
		{
			Widget ric = icon.GetRadialIcon();
			ric.Show( !c.IsOpened() );
			icon.GetRadialIconClosed().Show( c.IsOpened() );
		}
		
		Refresh();
	}

	void ToggleWidget( Widget w )
	{
		if( ItemManager.GetInstance().IsDragging() )
		{
			return;
		}
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		if( ipw.GetItem() )
		{
			ToggleContainer( w, ipw.GetItem() );
			RecomputeOpenedContainers();
		}
		
		Refresh();
	}

	override void CollapseButtonOnMouseButtonDown(Widget w)
	{
		super.CollapseButtonOnMouseButtonDown(w);
	}
	
	bool IsPlayerEquipmentActive()
	{
		if( GetFocusedContainer() && ( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) ) )
		{
			return false;
		}
		
		return true;
	}
	
	override void Refresh()
	{
		super.Refresh();
		m_MainWidget.Update();
		m_RootWidget.Update();
		m_ScrollWidget.Update();
		
		m_ShouldChangeSize = true;
	}
	
	void CheckScrollbarVisibility()
	{
		m_MainWidget.Update();
		m_RootWidget.Update();
		m_ScrollWidget.Update();
		float x, y;
		float x2, y2;
		
		m_RootWidget.GetScreenSize( x, y );
		m_ScrollWidget.GetScreenSize( x2, y2 );
		m_ScrollWidget.SetAlpha( ( y > y2 ) );
		
		UpdateSelectionIcons();
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
