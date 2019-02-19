class PlayerContainer: CollapsibleContainer
{
	protected ref Container						m_PlayerAttachmentsContainer;
	protected ref map<int, ref Widget>			m_InventorySlots;
	protected ref map<EntityAI, ref Container>	m_ShowedItems = new ref map<EntityAI, ref Container>;
	protected ref map<int, ref Container>		m_ShowedItemsIDs = new ref map<int, ref Container>;
	protected PlayerBase						m_Player;
	protected ScrollWidget						m_ScrollWidget;
	protected Widget							m_UpIcon;
	protected Widget							m_DownIcon;
	protected ref SizeToChild					m_ContentResize;
	protected bool								m_ShouldChangeSize = true;
	
	void PlayerContainer( LayoutHolder parent, int sort = -1 )
	{
		m_ScrollWidget	= ScrollWidget.Cast( parent.GetRootWidget().FindAnyWidget( "Scroller" ) );
		m_UpIcon		= parent.GetRootWidget().FindAnyWidget( "Up" );
		m_DownIcon		= parent.GetRootWidget().FindAnyWidget( "Down" );
		
		parent.GetRootWidget().FindAnyWidget( "ContentParent" ).GetScript( m_ContentResize );
		
		m_InventorySlots = new ref map<int, ref Widget>;
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
		
				Widget icon = m_PlayerAttachmentsContainer.Get( row ).GetMainWidget().FindAnyWidget( "Icon" + column );
				Widget item_preview = icon.FindAnyWidget( "Render" + column );
				if( !item_preview )
				{
					item_preview = icon;
				}
				icon.Show( true );
				WidgetEventHandler.GetInstance().RegisterOnDrag( item_preview.GetParent(),  this, "OnIconDrag" );
				WidgetEventHandler.GetInstance().RegisterOnDrop( item_preview.GetParent(),  this, "OnIconDrop" );
				WidgetEventHandler.GetInstance().RegisterOnDoubleClick( item_preview.GetParent(),  this, "DoubleClick" );

				WidgetEventHandler.GetInstance().RegisterOnMouseEnter( item_preview.GetParent(),  this, "MouseEnter" );
				WidgetEventHandler.GetInstance().RegisterOnMouseLeave( item_preview.GetParent(),  this, "MouseLeave" );
				//END - GetWidgetSlot

				//START - LoadIconIntoWidgetSlot
				ImageWidget image_widget = ImageWidget.Cast( item_preview.FindAnyWidget( "GhostSlot" + column ) );
				if( !image_widget )
				{
					image_widget = ImageWidget.Cast( item_preview.GetParent().GetParent().FindAnyWidget( "GhostSlot" + column ) );
				}
				image_widget.Show( true );
				WidgetEventHandler.GetInstance().RegisterOnDropReceived( item_preview.GetParent().GetParent().FindAnyWidget( "PanelWidget" + column ),  this, "OnDropReceivedFromGhostArea" );
				WidgetEventHandler.GetInstance().RegisterOnDropReceived( item_preview.GetParent().GetParent().FindAnyWidget( "GhostSlot" + column ),  this, "OnDropReceivedFromGhostArea" );
				WidgetEventHandler.GetInstance().RegisterOnDraggingOver( item_preview.GetParent().GetParent().FindAnyWidget( "PanelWidget" + column ),  this, "DraggingOver" );
				WidgetEventHandler.GetInstance().RegisterOnDraggingOver( item_preview.GetParent().GetParent().FindAnyWidget( "GhostSlot" + column ),  this, "DraggingOver" );
				WidgetEventHandler.GetInstance().RegisterOnDraggingOver( item_preview.GetParent().GetParent().GetParent().FindAnyWidget( "Icon" + column ),  this, "DraggingOver" );
				WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( item_preview.GetParent(),  this, "MouseClick" );
				image_widget.LoadImageFile( 0, "set:dayz_inventory image:" + icon_name );
				//END - LoadIconIntoWidgetSlot

				GetGame().ConfigGetText( path + " name", slot_name );
				int slot_id = InventorySlots.GetSlotIdFromString( slot_name );
				image_widget.SetUserID( slot_id );
				m_InventorySlots.Set( slot_id, item_preview );
			
				m_PlayerAttachmentsContainer.Get( row ).GetMainWidget().Update();
			}
		}
		m_PlayerAttachmentsContainer.GetMainWidget().Update();
			//LoadDefaultState();
		//END - InitGhostSlots
		RecomputeOpenedContainers();
	}
	
	void AddSlotsContainer( int row_count )
	{
		ref SlotsContainer s_cont = new SlotsContainer( m_PlayerAttachmentsContainer );
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
		bool inventory_locked = GetGame().GetPlayer().GetInventory().IsInventoryLocked();
		ItemManager.GetInstance().SetWidgetDraggable( w, !inventory_locked );
		
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		EntityAI item = item_preview.GetItem();
		InventoryItem itemAtPos = InventoryItem.Cast( item );
		
		if( item )
		{
			if ( button == MouseState.MIDDLE )
			{
				InspectItem( itemAtPos );
				return;
			}
			else if ( button == MouseState.LEFT && g_Game.IsLeftCtrlDown() )
			{
				if( item.GetInventory().CanRemoveEntity() )
				{
					GetGame().GetPlayer().PredictiveDropEntity( item );
				}
			}
		}
	}
	
	override void SetFirstActive()
	{
		super.SetFirstActive();
		
		EntityAI focused_item = GetFocusedItem();
		Container cnt = Container.Cast( m_Body.Get( 1 ) );
		if( focused_item )
		{
			float x, y;
			cnt.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).GetScreenPos( x, y );
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
			}
			if( next )
			{
				active.SetActive( false );
				next.SetActive( true );
				active = next;
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
					active = first;
					SetFocusedContainer( first );
					m_ScrollWidget.VScrollToPos01( 0 );
				}
			}
		}
		
		ScrollToActiveContainer( active );
		UpdateSelectionIcons();
	}

	override void SetPreviousActive()
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
		
		if(prev)
		{
			active.SetActive( false );
			prev.SetActive( true );
			active = prev;
			SetFocusedContainer( prev );
			
			if( active.IsInherited( CollapsibleContainer ) )
			{
				CollapsibleContainer.Cast( active ).SetLastActive();
			}
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
				m_ScrollWidget.VScrollToPos01( 1 );
			}
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
			float x2, y2;
			m_UpIcon.GetScreenSize( x, y );
			m_DownIcon.GetScreenSize( x2, y2 );
			
			float top_y		= GetCurrentContainerTopY();
			float bottom_y	= GetCurrentContainerBottomY() - y2;
			
			float diff		= bottom_y - ( top_y + y );
			if( diff < 0 )
			{
				top_y += diff / 2;
				bottom_y -= diff / 2;
			}
			
			m_UpIcon.SetPos( 0, top_y );
			m_DownIcon.SetPos( 0, bottom_y );
		}
	}
	
	float GetCurrentContainerTopY()
	{
		float x, y;
		GetParent().GetMainWidget().GetScreenPos( x, y );
		float cont_screen_pos = GetFocusedContainerYScreenPos();
		
		return cont_screen_pos - y;
	}
	
	float GetCurrentContainerBottomY()
	{
		float x, y;
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
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
		EntityAI ent = item_preview.GetItem();
		return ent && ( ent.GetInventory().GetCargo() || ent.GetSlotsCountCorrect() > 0 );
	}
	
	override bool IsItemWithQuantityActive()
	{
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
		EntityAI ent = item_preview.GetItem();
		return ent && QuantityConversions.HasItemQuantity( ent );
	}
	
	override bool IsItemActive()
	{
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
		EntityAI ent = item_preview.GetItem();
		return ent && !IsItemWithQuantityActive() && !IsItemWithContainerActive();
	}
	
	bool IsEmptyItemActive()
	{
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
		EntityAI ent = item_preview.GetItem();
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
			
			if( w == null || player.GetInventory().IsInventoryLocked() )
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
			if( !iw.GetItem() )
			{
				return;
			}
	
			ItemBase item = ItemBase.Cast( iw.GetItem() );
			
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
					if( item.ConfigGetFloat("varStackMax") )
						item.SplitIntoStackMaxClient( player, -1, );
					else
						player.PredictiveTakeEntityToInventory( FindInventoryLocationType.ANY, InventoryItem.Cast( item ) );
				}
				else
				{
					if( player.GetHumanInventory().CanAddEntityInHands( item ) )
					{
						player.PredictiveTakeEntityToHands( item );
					}
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
	
	override void RefreshItemPosition( EntityAI item_to_refresh )
	{
		for ( int i = 0; i < m_ShowedItems.Count(); i++ )
		{
			Container container = m_ShowedItems.GetElement( i );
			container.RefreshItemPosition( item_to_refresh );
		}
	}
	
	void ExpandCollapseContainer()
	{
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
		ToggleWidget( item_preview.GetParent() );
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
			ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
			EntityAI item = item_preview.GetItem();
			if( item && player.CanDropEntity( item ) )
			{
				player.PredictiveDropEntity( item );
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
			ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
			EntityAI item = item_preview.GetItem();
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
		if( left_area )
		{
			if( GetFocusedContainer().IsInherited( ContainerWithCargo ) || GetFocusedContainer().IsInherited( ContainerWithCargoAndAttachments ) )
			{
				return GetFocusedContainer().TransferItem();
			}
			else
			{
				ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
				EntityAI item = item_preview.GetItem();
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
				item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
				item = item_preview.GetItem();
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
			ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
			item = item_preview.GetItem();
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
			ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
			ItemBase item = ItemBase.Cast( item_preview.GetItem() );
			ItemBase item_in_hands = ItemBase.Cast(	GetGame().GetPlayer().GetHumanInventory().GetEntityInHands() );
			
			Icon hands_icon = ItemManager.GetInstance().GetHandsPreview().GetIcon();
						
			if( item_in_hands && item )
			{
				hands_icon.CombineItems( item_in_hands, item );
				return true;
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
			ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
			ItemBase item = ItemBase.Cast( item_preview.GetItem() );
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
					if( GetGame().GetPlayer().GetInventory().CanRemoveAttachment( selected_item ) )
					{
						GetGame().GetPlayer().PredictiveTakeEntityToInventory( FindInventoryLocationType.ATTACHMENT, selected_item );
						ItemManager.GetInstance().SetSelectedItem( null, null, null );
						return true;
					}
				}
			}
			else
			{
				ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( m_PlayerAttachmentsContainer.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Render" + m_FocusedColumn ) );
				EntityAI item = item_preview.GetItem();
				if( item && item.GetInventory().CanRemoveEntity() )
				{
					EntityAI item_in_hands = GetGame().GetPlayer().GetHumanInventory().GetEntityInHands();
					if( item_in_hands && item_in_hands.GetInventory().CanRemoveEntity() )
					{
						if( GameInventory.CanSwapEntities( item_in_hands, item ) )
						{
							GetGame().GetPlayer().PredictiveSwapEntities( item_in_hands, item );
							return true;
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
			
			Container cnt = Container.Cast( m_Body.Get( 1 ) );
   			cnt.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).Show( true );
			
			EntityAI focused_item = GetFocusedItem();
			if( focused_item )
			{
				cnt.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).GetScreenPos( x, y );
				ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
			}
			
			ScrollToActiveContainer( Container.Cast( cnt.Get( m_FocusedRow ) ) );
		}
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

	bool MouseEnter( Widget w, int x, int y )
	{
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		if( ipw.GetItem() )
		ItemManager.GetInstance().PrepareTooltip( ipw.GetItem() );
		return true;
	}

	bool MouseLeave( Widget w, Widget s, int x, int y	)
	{
		ItemManager.GetInstance().HideTooltip();
		return true;
	}

	void SetPlayer( PlayerBase player )
	{
		m_Player = player;
	}

	void OnIconDrag( Widget w )
	{
		ItemManager.GetInstance().HideDropzones();
		ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );

		ItemManager.GetInstance().SetIsDragging( true );
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget(name) );
		float icon_x, icon_y, x_content, y_content;
		int m_sizeX, m_sizeY;

		InventoryItem i_item = InventoryItem.Cast( ipw.GetItem() );
		GetGame().GetInventoryItemSize( i_item, m_sizeX, m_sizeY );

		m_Parent.m_Parent.GetMainWidget().FindAnyWidget( "body" ).GetScreenSize( x_content, y_content );
		icon_x = x_content / 10;
		icon_y = x_content / 10;
		w.SetFlags( WidgetFlags.EXACTSIZE );
		w.SetSize( icon_x, icon_y );
		w.SetSize( icon_x * m_sizeX - 1 , icon_y * m_sizeY + m_sizeY - 1 );

		if( !ipw.GetItem() )
		{
			return;
		}
		name.Replace( "Render", "Col" );
		w.FindAnyWidget( name ).Show( true );
		name.Replace( "Col", "RadialIcon" );
		w.GetParent().GetParent().FindAnyWidget( name ).Show( false );
		name.Replace( "RadialIcon", "AmmoIcon" );
		w.GetParent().FindAnyWidget( name ).Show( false );
		name.Replace( "AmmoIcon", "Selected" );
		w.GetParent().FindAnyWidget( name ).Show( true );
	}

	void OnIconDrop( Widget w )
	{
		ItemManager.GetInstance().HideDropzones();

		ItemManager.GetInstance().SetIsDragging( false );
		w.ClearFlags( WidgetFlags.EXACTSIZE );
		w.SetSize( 1, 1 );
		string name = w.GetName();
		name.Replace( "PanelWidget", "Col" );
		w.FindAnyWidget( name ).Show( false );
		name.Replace( "Col", "Render" );
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		ipw.Show( false );
		name.Replace( "Render", "GhostSlot" );
		w.GetParent().FindAnyWidget( name ).Show( true );
		name.Replace( "GhostSlot", "AmmoIcon" );
		w.GetParent().FindAnyWidget( name ).Show( false );
		name.Replace( "AmmoIcon", "Selected" );
		w.GetParent().FindAnyWidget( name ).Show( false );
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
		
		if( ( m_Player.GetInventory().CanAddEntityToInventory( item ) && !m_Player.GetInventory().HasEntityInInventory( item ) ) || m_Player.GetHumanInventory().HasEntityInHands( item ) )
		{
			m_Player.PredictiveTakeEntityToInventory( FindInventoryLocationType.ANY, item );
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

		if( ( m_Player.GetInventory().CanAddEntityToInventory( item ) && !m_Player.GetInventory().HasEntityInInventory( item ) ) || m_Player.GetHumanInventory().HasEntityInHands( item ) )
		{
			ItemManager.GetInstance().HideDropzones();
			ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
		}
		else
		{
			ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
			ItemManager.GetInstance().ShowSourceDropzone( item );
		}
	}

	override void DraggingOver( Widget w, int x, int y, Widget receiver )
	{
		if( w == null )
		{
			return;
		}
		string name = receiver.GetName();
		name.Replace("PanelWidget", "Render");
		ItemPreviewWidget receiver_iw = ItemPreviewWidget.Cast( receiver.FindAnyWidget(name) );
		EntityAI receiver_item;
		if( receiver_iw )
		{
			receiver_item = receiver_iw.GetItem();
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
		
		if( receiver_item )
		{
			if( GameInventory.CanSwapEntities( receiver_item, item ) )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.SWAP_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
				return;
			}
			else if( receiver_item.GetInventory().CanAddAttachment(item) || receiver_item.GetInventory().CanAddEntityInCargo( item ) && !receiver_item.GetInventory().HasEntityInCargo( item ))
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
				return;
			}
			else if( ( ItemBase.Cast( receiver_item ) ).CanBeCombined( ItemBase.Cast( item ) ) )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.COMBINE_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
				return;
			}

		}
		
		if( item.GetInventory().CanRemoveEntity() )
		{
			if( m_Player.GetInventory().CanAddAttachment( item) )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
			else if( ( m_Player.GetInventory().CanAddEntityToInventory( item ) && !m_Player.GetInventory().HasEntityInInventory( item ) ) || m_Player.GetHumanInventory().HasEntityInHands( item ) )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
			else if ( receiver_item && GameInventory.CanSwapEntities( receiver_item, item ) )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.SWAP_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
		}
		else
		{
			ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
			ItemManager.GetInstance().ShowSourceDropzone( item );
		}
	}

	void OnDropReceivedFromGhostArea( Widget w, int x, int y, Widget receiver )
	{
		string name = receiver.GetName();
		name.Replace("PanelWidget", "Render");
		ItemPreviewWidget receiver_iw = ItemPreviewWidget.Cast( receiver.FindAnyWidget(name) );
		EntityAI receiver_item;
		InventoryMenu menu = InventoryMenu.Cast( GetGame().GetUIManager().FindMenu( MENU_INVENTORY ) );
		if( receiver_iw )
		{
			receiver_item = receiver_iw.GetItem();
		}


		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( GetItemPreviewWidget( w ) );

		if( !ipw )
		{
			return;
		}

		EntityAI item = ipw.GetItem();
		PlayerBase real_player = PlayerBase.Cast( GetGame().GetPlayer() );
		if( !item )
		{
			return;
		}
		if( receiver_item )
		{
			if( GameInventory.CanSwapEntities( receiver_item, item ) )
			{
				GetGame().GetPlayer().PredictiveSwapEntities( item, receiver_item );

				if ( menu )
				{
					menu.RefreshQuickbar();
				}
				return;
			}
			else if( receiver_item.GetInventory().CanAddAttachment( item ) )
			{
				GetGame().GetPlayer().PredictiveTakeEntityToTargetAttachment( receiver_item, item );

				if ( menu )
				{
					menu.RefreshQuickbar();
				}
				return;
			}
			else if( receiver_item.GetInventory().CanAddEntityInCargo( item ) && !receiver_item.GetInventory().HasEntityInCargo( item ) )
			{
				GetGame().GetPlayer().PredictiveTakeEntityToTargetInventory( receiver_item, FindInventoryLocationType.ANY_CARGO, item );

				if ( menu )
				{
					menu.RefreshQuickbar();
				}
				return;
			}
			else if( ( ItemBase.Cast( receiver_item ) ).CanBeCombined( ItemBase.Cast( item ) ) )
			{
				( ItemBase.Cast( receiver_item ) ).CombineItemsClient( ItemBase.Cast( item ) );
				return;
			}
		}
		
		if( m_Player.GetInventory().CanAddAttachmentEx( item, receiver.GetUserID() ) )
		{
			real_player.PredictiveTakeEntityToTargetAttachmentEx( m_Player, item, receiver.GetUserID() );
		}
		else if(  m_Player.GetInventory().CanAddAttachment( item ) )
		{
			real_player.PredictiveTakeEntityToTargetAttachment( m_Player, item );
		}
		else if( ( m_Player.GetInventory().CanAddEntityToInventory( item ) && !m_Player.GetInventory().HasEntityInInventory( item ) ) || m_Player.GetHumanInventory().HasEntityInHands( item ) )
		{
			real_player.PredictiveTakeEntityToTargetInventory( m_Player, FindInventoryLocationType.ANY, item );
		}

		if ( menu )
		{
			menu.RefreshQuickbar();
		}
	}
	
	void EnterContainer( Container cont )
	{
		m_IsActive = true;
		SetFocusedContainer( cont );
		UpdateSelectionIcons();
	}
	
	void LeaveContainer( Container cont )
	{
		m_IsActive = false;
		SetFocusedContainer( null );
		UpdateSelectionIcons();
	}

	override void UpdateInterval()
	{
		if( !m_Player || !m_Parent.m_Parent.GetMainWidget().IsVisible() )
		{
			return;
		}
		
		int attachments_count = m_Player.GetInventory().AttachmentCount();
		ref map<EntityAI, ref Container> new_showed_items = new ref map<EntityAI, ref Container>;
		ref array<EntityAI> showed_player_ghost_entities = new ref array<EntityAI>;
		ref map<int, ref Container> showed_items_IDs = new ref map<int, ref Container>;
		for ( int i = 0; i < attachments_count; i++ )
		{
			EntityAI entity = m_Player.GetInventory().GetAttachmentFromIndex( i );
			if ( entity )
			{
				InventoryLocation loc = new InventoryLocation;
				entity.GetInventory().GetCurrentInventoryLocation( loc );
				int slot_id = loc.GetSlot();
				
				ItemPreviewWidget ipw = ItemPreviewWidget.Cast( m_InventorySlots.Get( slot_id ) );
				if( ipw && ipw.GetParent() )
				{
					string name2 = ipw.GetParent().GetName();
					ipw.Show( true );
					ipw.GetParent().Show( true );
					name2.Replace( "PanelWidget", "GhostSlot" );
					ipw.GetParent().GetParent().FindAnyWidget( name2 ).Show( false );
					ipw.SetItem( entity );
					showed_player_ghost_entities.Insert( entity );
					
					name2.Replace( "GhostSlot", "AmmoIcon" );
					
					#ifdef PLATFORM_CONSOLE
					int size_x, size_y;
					GetGame().GetInventoryItemSize( InventoryItem.Cast(entity), size_x, size_y );
					int capacity = size_x * size_y;
					name2.Replace( "AmmoIcon", "ItemSize" );
					TextWidget tw = TextWidget.Cast( ipw.GetParent().GetParent().FindAnyWidget( name2 ) );
					tw.SetText( capacity.ToString() );
					name2.Replace( "ItemSize", "AmmoIcon" );
					#endif
					
					Weapon_Base wpn;
					if ( Class.CastTo(wpn,  ipw.GetItem() ) )
					{
						int mi = wpn.GetCurrentMuzzle();
						ipw.GetParent().GetParent().FindAnyWidget( name2 ).Show( wpn.IsChamberFull( mi )  );
					}
	
					ClosableContainer conta = ClosableContainer.Cast( m_ShowedItemsIDs.Get( ipw.GetParent().GetUserID() ) );
					string config = "CfgVehicles " + entity.GetType() + " GUIInventoryAttachmentsProps";
					if( conta && conta.IsInherited( ClosableContainer ) )
					{
						bool show_radial_icon = conta.IsOpened() && ( entity.GetInventory().GetCargo() || entity.GetSlotsCountCorrect() > 0 ) && !GetGame().ConfigIsExisting( config );
						name2.Replace( "AmmoIcon", "RadialIcon" );
						ipw.GetParent().GetParent().FindAnyWidget( name2 ).Show( !show_radial_icon );
						name2.Replace( "RadialIcon", "RadialIconClosed" );
						ipw.GetParent().GetParent().FindAnyWidget( name2 ).Show( show_radial_icon );
					}
	
					if( m_ShowedItems.Contains( entity ) == false )
					{
						string name;
						int sort_index = Inventory.GetPlayerAttachmentIndex( slot_id );
						if( entity.GetSlotsCountCorrect() > 0 )
						{
							ContainerWithCargoAndAttachments iwca = new ContainerWithCargoAndAttachments( this, sort_index );
							iwca.SetEntity( entity );
							new_showed_items.Insert( entity, iwca );
							showed_items_IDs.Insert( entity.GetID(), iwca );
							ipw.GetParent().SetUserID( entity.GetID() );
							WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( ipw.GetParent(),  this, "ToggleWidget" );
	
							name = ipw.GetName();
							name.Replace( "Render", "RadialIconPanel" );
							ipw.GetParent().GetParent().FindAnyWidget( name ).Show( true );
							
							Refresh();
						}
						else if( entity.GetInventory().GetCargo() )
						{
							ContainerWithCargo iwc = new ContainerWithCargo( this, sort_index );
							iwc.SetEntity( entity );
							new_showed_items.Insert( entity, iwc );
							showed_items_IDs.Insert( entity.GetID(), iwc );
							iwc.UpdateInterval();
							ipw.GetParent().SetUserID( entity.GetID() );
							WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( ipw.GetParent(),  this, "ToggleWidget" );
	
							name = ipw.GetName();
							name.Replace( "Render", "RadialIconPanel" );
							ipw.GetParent().GetParent().FindAnyWidget( name ).Show(true);
							
							Refresh();
						}
					}
					else
					{
						new_showed_items.Insert( entity, m_ShowedItems.Get( entity ) );
						showed_items_IDs.Insert( entity.GetID(), m_ShowedItemsIDs.Get( entity.GetID() ) );
					}
				}
			}
		}

		for( i = 0; i < m_ShowedItems.Count(); i++ )
		{
			EntityAI ent = m_ShowedItems.GetKey( i );
			m_ShowedItems.GetElement( i ).UpdateInterval();
			if( new_showed_items.Contains( ent ) == false )
			{
				Container con = m_ShowedItems.GetElement( i );
				( Container.Cast( con.m_Parent ) ).Remove( con );
				RecomputeOpenedContainers();
				GetMainWidget().Update();
				Refresh();
			}
		}

		for( i = 0; i < m_InventorySlots.Count(); i++ )
		{
			ipw = ItemPreviewWidget.Cast( m_InventorySlots.GetElement(i) );
			if( ipw.GetItem() != null && showed_player_ghost_entities.Find( ipw.GetItem() ) == INDEX_NOT_FOUND )
			{
				name2 = ipw.GetParent().GetName();
				ipw.Show( false );
				name2.Replace( "PanelWidget", "GhostSlot" );
				ipw.GetParent().GetParent().FindAnyWidget( name2 ).Show( true );
				name2.Replace( "GhostSlot", "RadialIconPanel" );
				ipw.GetParent().GetParent().FindAnyWidget( name2 ).Show( false );
				ipw.SetItem( null );
				Inventory in = Inventory.Cast( GetRoot() );
				if( in )
					in.UpdateConsoleToolbar();
				
				#ifdef PLATFORM_CONSOLE
				name2.Replace( "RadialIconPanel", "ItemSizePanel" );
				ipw.GetParent().GetParent().FindAnyWidget( name2 ).Show( false );
				name2.Replace( "ItemSizePanel", "ItemSize" );
				TextWidget tw1 = TextWidget.Cast( ipw.GetParent().GetParent().FindAnyWidget( name2 ) );
				tw1.SetText( "" );
				#endif
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
		
		m_ShowedItems = new_showed_items;
		m_ShowedItemsIDs = showed_items_IDs;
	}

	void ToggleContainer( Widget w , int number )
	{
		ClosableContainer c = ClosableContainer.Cast( m_ShowedItemsIDs.Get( number ) );
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
			ToggleContainer( w, w.GetUserID() );
			RecomputeOpenedContainers();
		}
	}

	override void RefreshQuantity( EntityAI item_to_refresh )
	{
		for ( int i = 0; i < m_ShowedItems.Count(); i++)
		{
			m_ShowedItems.GetElement( i ).RefreshQuantity( item_to_refresh );
		}
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
