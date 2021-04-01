const int ITEMS_IN_ROW = 8;

class Attachments
{
	protected Container							m_Parent;
	protected EntityAI							m_Entity;
	protected ref AttachmentsWrapper			m_AttachmentsContainer;
	protected ref array<ref SlotsContainer>		m_Ics;
	protected ref array<string>					m_AttachmentSlotNames;
	protected ref map<int, SlotsIcon>			m_AttachmentSlots;
	
	protected int m_FocusedRow, m_FocusedColumn, m_RowIndex;

	void Attachments( Container parent, EntityAI entity )
	{
		m_Parent				= parent;
		m_Entity				= entity;
		m_Ics					= new array<ref SlotsContainer>;
		m_AttachmentSlots		= new map<int, SlotsIcon>;
		m_AttachmentSlotNames	= GetItemSlots( entity );
		m_Entity.GetOnItemAttached().Insert( AttachmentAdded );
		m_Entity.GetOnItemDetached().Insert( AttachmentRemoved );
		m_Entity.GetOnAttachmentSetLock().Insert( OnAttachmentReservationSet );
		m_Entity.GetOnAttachmentReleaseLock().Insert( OnAttachmentReservationRelease );
		
	}
	
	void ~Attachments()
	{
		if( m_Entity )
		{
			m_Entity.GetOnItemAttached().Remove( AttachmentAdded );
			m_Entity.GetOnItemDetached().Remove( AttachmentRemoved );
			m_Entity.GetOnAttachmentSetLock().Remove( OnAttachmentReservationSet );
			m_Entity.GetOnAttachmentReleaseLock().Remove( OnAttachmentReservationRelease );
		}
		
		delete m_AttachmentsContainer;
	}
	
	AttachmentsWrapper GetWrapper()
	{
		return m_AttachmentsContainer;
	}
	
	bool IsEmpty()
	{
		return m_AttachmentSlotNames.Count() == 0;
	}
	
	bool IsItemActive()
	{
		ItemBase item = ItemBase.Cast( GetFocusedItem() );
		if( !item )
		{
			return false;
		}
		return !IsEmpty() && ( !QuantityConversions.HasItemQuantity( item )  || ( QuantityConversions.HasItemQuantity( item ) && !item.CanBeSplit() ) );
	}
	
	bool IsItemWithQuantityActive()
	{
		ItemBase item = ItemBase.Cast( GetFocusedItem() );
		if( !item )
		{
			return false;
		}
		return !IsEmpty() && QuantityConversions.HasItemQuantity( item ) && item.CanBeSplit();
	}

	void UnfocusAll()
	{
		for ( int i = 0; i < m_Ics.Count(); i++ )
		{
			m_Ics.Get( i ).UnfocusAll();
		}
	}

	void SetDefaultFocus()
	{
		m_FocusedRow = 0;
		m_FocusedColumn = 0;
		if( m_Ics.Count() > 0 )
			m_Ics.Get( 0 ).SetFocus( 0 );
		
		SlotsIcon icon = GetFocusedIcon();
		EntityAI focused_item = icon.GetItem();
		float x, y;
		icon.GetCursorWidget().GetScreenPos( x, y );
		
		if( focused_item )
		{
			ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
		}
		else
		{
			ItemManager.GetInstance().PrepareSlotsTooltip( icon.GetSlotDisplayName(), icon.GetSlotDesc(), x, y );
		}
		Inventory.GetInstance().UpdateConsoleToolbar();
	}
	
	void SetLastActive()
	{
		m_FocusedRow = m_Ics.Count() - 1;
		m_FocusedColumn = 0;
		if( m_Ics.Count() > 0 )
		{
			UnfocusAll();
			m_Ics.Get( m_FocusedRow ).SetFocus( 0 );
		}
		
		SlotsIcon icon = GetFocusedIcon();
		EntityAI focused_item = icon.GetItem();
		float x, y;
		icon.GetCursorWidget().GetScreenPos( x, y );
		
		if( focused_item )
		{
			ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
		}
		else
		{
			ItemManager.GetInstance().PrepareSlotsTooltip( icon.GetSlotDisplayName(), icon.GetSlotDesc() , x, y );
		}
		Inventory.GetInstance().UpdateConsoleToolbar();
	}
	
	void SetActive( bool active )
	{
		if( active )
		{
			SetDefaultFocus();
		}
		m_AttachmentsContainer.SetActive( active );
		m_Parent.GetMainWidget().FindAnyWidget("AttachmentsWrapper").Update();
	}
	
	SlotsIcon GetFocusedIcon()
	{
		if( m_FocusedRow < m_Ics.Count() )
		{
			SlotsContainer cont = SlotsContainer.Cast( m_Ics.Get( m_FocusedRow ) );
			return cont.GetSlotIcon( m_FocusedColumn );
		}
		return null;
	}
	
	EntityAI GetFocusedItem()
	{
		SlotsIcon icon = GetFocusedIcon();
		if( icon )
		{
			return icon.GetEntity();
		}
		return null;
	}
	
	int GetFocusedSlot()
	{
		if( m_FocusedRow < m_Ics.Count() )
		{
			return m_Ics.Get( m_FocusedRow ).GetSlotIcon( m_FocusedColumn ).GetSlotID();
		}
		return -1;
	}
	
	bool SelectItem()
	{
		if( m_FocusedRow < m_Ics.Count() && !GetFocusedIcon().IsOutOfReach() )
		{
			ItemBase item = ItemBase.Cast( GetFocusedItem() );
			SlotsIcon icon = GetFocusedIcon();
			ItemManager.GetInstance().SetSelectedItem( item, null, icon.GetCursorWidget(), icon );
			return true;
		}
		return false;
	}
	
	bool Select()
	{
		SlotsIcon selected_slot = ItemManager.GetInstance().GetSelectedIcon();
		EntityAI selected_item = ItemManager.GetInstance().GetSelectedItem();
		SlotsIcon focused_slot = GetFocusedIcon();
		EntityAI focused_item = GetFocusedItem();
		Man player = GetGame().GetPlayer();
		
		if( focused_slot.IsReserved() || focused_item != selected_item && !(selected_slot && selected_slot.IsOutOfReach() ) )
		{
			if( selected_item )
			{
				if( selected_item.GetInventory().CanRemoveEntity() )
				{
					if( m_Entity.GetInventory().CanAddAttachmentEx( selected_item, focused_slot.GetSlotID() ) )
					{
						player.PredictiveTakeEntityToTargetAttachmentEx( m_Entity, selected_item, focused_slot.GetSlotID() );
						ItemManager.GetInstance().SetSelectedItem( null, null, null, null );
						return true;
					
					}
					else if( m_Entity.GetInventory().CanAddAttachment( selected_item ) )
					{
						player.PredictiveTakeEntityToTargetAttachment(m_Entity, selected_item);
						ItemManager.GetInstance().SetSelectedItem( null, null, null, null );
						return true;
					}
				}
			}
			else
			{
				if ( focused_item && !focused_slot.IsOutOfReach() )
				{
					EntityAI item_in_hands = GetGame().GetPlayer().GetHumanInventory().GetEntityInHands();
					InventoryLocation il = new InventoryLocation;
					focused_item.GetInventory().GetCurrentInventoryLocation( il );
					bool reachable = AttachmentsOutOfReach.IsAttachmentReachable( m_Entity, "", il.GetSlot() );
					if( reachable && focused_item.GetInventory().CanRemoveEntity() )
					{
						if( item_in_hands && item_in_hands.GetInventory().CanRemoveEntity() )
						{
							if( GameInventory.CanSwapEntitiesEx( item_in_hands, focused_item ) )
							{
								player.PredictiveSwapEntities( item_in_hands, focused_item );
								return true;
							}
						}
						else
						{
							if( player.GetHumanInventory().CanAddEntityInHands( focused_item ) )
							{
								player.PredictiveTakeEntityToHands( focused_item );
								return true;
							}
						}
					}
				}
			}	
		}
		return false;
	}
	
	int GetRecipeCount( bool recipe_anywhere, EntityAI entity1, EntityAI entity2 )
	{
		PluginRecipesManager plugin_recipes_manager = PluginRecipesManager.Cast( GetPlugin( PluginRecipesManager ) );
		return plugin_recipes_manager.GetValidRecipes( ItemBase.Cast( entity1 ), ItemBase.Cast( entity2 ), null, PlayerBase.Cast( GetGame().GetPlayer() ) );
	}
	
	bool CanCombine()
	{
		ItemBase ent = ItemBase.Cast( GetFocusedItem() );
		ItemBase item_in_hands = ItemBase.Cast(	GetGame().GetPlayer().GetHumanInventory().GetEntityInHands() );
		
		return GetRecipeCount( false, ent, item_in_hands ) > 0;
	}
	
	bool CanEquip()
	{
		EntityAI entity = ItemBase.Cast( GetFocusedItem() );
		InventoryLocation il = new InventoryLocation;
		if( !entity || entity.IsInherited( Magazine ) )
		{
			return false;
		}
		return GetGame().GetPlayer().GetInventory().FindFreeLocationFor( entity, FindInventoryLocationType.ATTACHMENT, il );
	}
	
	bool Combine()
	{
		ItemBase ent = ItemBase.Cast( GetFocusedItem() );
		ItemBase item_in_hands = ItemBase.Cast(	GetGame().GetPlayer().GetHumanInventory().GetEntityInHands() );
		
		if( !ent || !item_in_hands )
		{
			return false;
		}
		if ( item_in_hands.CanBeCombined( ent ) )
		{
			item_in_hands.CombineItemsClient( ent );
			return false;
		}
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		PluginRecipesManager plugin_recipes_manager = PluginRecipesManager.Cast( GetPlugin( PluginRecipesManager ) );
		ref array<int> recipes = new array<int>;
		if ( plugin_recipes_manager.GetValidRecipes( ent, item_in_hands, recipes, player ) > 0 )
			player.GetCraftingManager().SetInventoryCraft( recipes[0], ent, item_in_hands );
		
		return true;
	}
	
	bool EquipItem()
	{
		ItemBase entity = ItemBase.Cast( GetFocusedItem() );
		if( entity && !entity.IsInherited( Magazine ) && !GetFocusedIcon().IsOutOfReach() )
		{
			if( entity.HasQuantity() )
			{
				entity.OnRightClick();
				return true;
			}
			else
			{
				GetGame().GetPlayer().PredictiveTakeEntityToInventory( FindInventoryLocationType.ATTACHMENT, entity );
				return true;
			}
		}
		return false;
	}
	
	bool TransferItem()
	{
		EntityAI entity = GetFocusedItem();
		if( entity && !GetFocusedIcon().IsOutOfReach() )
		{
			GetGame().GetPlayer().PredictiveTakeEntityToInventory( FindInventoryLocationType.CARGO, entity );
			return true;
		}
		return false;
	}
	
	bool InspectItem()
	{
		EntityAI entity = GetFocusedItem();
		if( entity )
		{
			m_Parent.InspectItem( entity );
			return true;
		}
		return false;
	}
	
	bool TransferItemToVicinity()
	{
		ItemBase item = ItemBase.Cast(GetFocusedItem());
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if( item && !GetFocusedIcon().IsOutOfReach() )
		{
			if( item.GetTargetQuantityMax() < item.GetQuantity() )
				item.SplitIntoStackMaxClient( null, -1 );
			else
				player.PhysicalPredictiveDropItem( item );
			return true;
		}
		return false;
	}
	
	bool IsActive()
	{
		return m_Parent.GetMainWidget().FindAnyWidget("AttachmentsWrapper").GetAlpha() > 0;
	}

	void MoveGridCursor( int direction )
	{
		ItemManager.GetInstance().HideTooltip();
		UnfocusAll();
		if( direction == Direction.UP )
		{
			m_FocusedRow--;
			if( m_FocusedRow < 0 )
			{
				m_FocusedRow  = m_Ics.Count() - 1;
				Container cnt = Container.Cast( m_Parent );
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

			int max_row = m_Ics.Get( m_FocusedRow ).GetColumnCount() - 1;
			if( max_row < m_FocusedColumn )
			{
				m_FocusedColumn = max_row;
			}
		}

		if( direction == Direction.DOWN )
		{
			m_FocusedRow++;
			if( m_FocusedRow >= m_Ics.Count() )
			{
				m_FocusedRow = 0;
				cnt = Container.Cast( m_Parent );
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

			max_row = m_Ics.Get( m_FocusedRow ).GetColumnCount() - 1;
			if( max_row < m_FocusedColumn )
			{
				m_FocusedColumn = max_row;
			}
		}

		if( direction == Direction.RIGHT )
		{
			if( m_Ics.Count() > 0 )
			{
				m_FocusedColumn++;
				if( m_FocusedColumn == m_Ics.Get( m_FocusedRow ).GetColumnCount() )
				{
					m_FocusedColumn = 0;
				}
			}
			else
				return;
		}

		if( direction == Direction.LEFT )
		{
			if( m_Ics.Count() > 0 )
			{
				m_FocusedColumn--;
				if( m_FocusedColumn < 0 )
				{
					m_FocusedColumn = m_Ics.Get( m_FocusedRow ).GetColumnCount() - 1;
				}
			}
			else
				return;
		}

		m_Ics.Get( m_FocusedRow ).SetFocus( m_FocusedColumn );
		
		SlotsIcon icon = GetFocusedIcon();
		EntityAI focused_item = icon.GetItem();
		float x, y;
		icon.GetCursorWidget().GetScreenPos( x, y );
		if( focused_item )
		{
			ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
		}
		else
		{
			ItemManager.GetInstance().PrepareSlotsTooltip( icon.GetSlotDisplayName(), icon.GetSlotDesc(), x, y );
		}
		Inventory.GetInstance().UpdateConsoleToolbar();
	}

	void Remove()
	{
		for( int i = 0; i < m_Ics.Count(); i++ )
		{
			m_AttachmentsContainer.Remove( m_Ics.Get( i ) );
		}
		
		m_Ics.Clear();
		m_Parent.Refresh();
	}
	
	int GetAttachmentHeight()
	{
		return m_AttachmentsContainer.Count();
	}
	
	void UpdateInterval()
	{
		for( int i = 0; i < m_AttachmentSlotNames.Count(); i++ )
		{
			int slot_id = InventorySlots.GetSlotIdFromString( m_AttachmentSlotNames[i] );
			SlotsIcon icon = m_AttachmentSlots.Get( slot_id );
			EntityAI item = icon.GetEntity();
			if( m_Entity.CanDisplayAttachmentSlot( m_AttachmentSlotNames[i] ) )
			{
				icon.GetMainWidget().Show( true );
				icon.UpdateInterval();
				if( item )
				{
					bool draggable = true;
					if(icon.IsReserved())
					{
						draggable = false;
					}
					
					if( m_Entity.GetInventory().GetSlotLock( slot_id ) && ItemManager.GetInstance().GetDraggedItem() != item )
					{
						icon.GetMountedWidget().Show( true );
						draggable = false;
					}
					else
					{
						icon.GetMountedWidget().Show( false );
					}
					
					PlayerBase p = PlayerBase.Cast( GetGame().GetPlayer() );
					bool in_hands_condition		= m_Entity.GetHierarchyRoot() && item.GetInventory().CanRemoveEntity();
					bool in_vicinity_condition	= !m_Entity.GetHierarchyRoot() && AttachmentsOutOfReach.IsAttachmentReachable( m_Entity, m_AttachmentSlotNames[i] );
					if( in_hands_condition || in_vicinity_condition )
					{
						icon.GetOutOfReachWidget().Show( false );
					}
					else
					{
						icon.GetOutOfReachWidget().Show( true );
						draggable = false;
					}
					
					if( draggable )
					{
						icon.GetPanelWidget().SetFlags( WidgetFlags.DRAGGABLE );
					}
					else
					{
						icon.GetPanelWidget().ClearFlags( WidgetFlags.DRAGGABLE );
					}
				}
			}
			else
			{
				icon.GetMainWidget().Show( false );
			}
		}
	}
	
	array<int> GetSlotsSorted()
	{
		return m_AttachmentSlots.GetKeyArray();
	}
	
	void AttachmentAdded(EntityAI item, string slot, EntityAI parent)
	{
		int slot_id = InventorySlots.GetSlotIdFromString( slot );
		SlotsIcon icon = m_AttachmentSlots.Get( slot_id );
		
		icon.SetSlotID( slot_id );
		icon.SetSlotDisplayName(InventorySlots.GetSlotDisplayName(slot_id));
		if( item )
		{
			icon.Init( item );
		}
	}
	
	void AttachmentRemoved(EntityAI item, string slot, EntityAI parent)
	{
		int slot_id = InventorySlots.GetSlotIdFromString( slot );
		SlotsIcon icon = m_AttachmentSlots.Get( slot_id );
		icon.Clear();
	}
	
	void OnAttachmentReservationSet( EntityAI item, int slot_id )
	{
		SlotsIcon icon = m_AttachmentSlots.Get( slot_id );
		
		if( item )
		{
			icon.Init( item, true );
		}
	}
	
	void OnAttachmentReservationRelease( EntityAI item, int slot_id )
	{
		SlotsIcon icon = m_AttachmentSlots.Get( slot_id );
		icon.Clear();
	}
	

	void InitAttachmentGrid( int att_row_index )
	{
		m_RowIndex = att_row_index;

		int number_of_rows = Math.Ceil( m_AttachmentSlotNames.Count() / ITEMS_IN_ROW );
		
		m_AttachmentsContainer = new AttachmentsWrapper( m_Parent );
		m_AttachmentsContainer.SetParent( this );
		m_AttachmentsContainer.GetRootWidget().SetSort( att_row_index );
		m_Parent.Insert( m_AttachmentsContainer, att_row_index );
		
		for ( int i = 0; i < number_of_rows; i++ )
		{
			SlotsContainer ic = new SlotsContainer( m_AttachmentsContainer, m_Entity );
			m_AttachmentsContainer.Insert( ic );

			if( i == ( number_of_rows - 1 ) && m_AttachmentSlotNames.Count() % ITEMS_IN_ROW != 0 )
			{
				ic.SetColumnCount( m_AttachmentSlotNames.Count() % ITEMS_IN_ROW );
			}
			else
			{
				ic.SetColumnCount( ITEMS_IN_ROW );
			}

			m_Ics.Insert( ic );
			for( int j = 0; j < ITEMS_IN_ROW; j++ )
			{
				SlotsIcon icon = ic.GetSlotIcon( j );
				WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetMainWidget(), m_Parent, "OnDropReceivedFromHeader2" );
				WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetGhostSlot(), m_Parent, "OnDropReceivedFromHeader2" );
				WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetPanelWidget(), m_Parent, "OnDropReceivedFromHeader2" );

				WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetMainWidget(),  m_Parent, "DraggingOverHeader" );
				WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetGhostSlot(), m_Parent, "DraggingOverHeader" );
				WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetPanelWidget(), m_Parent, "DraggingOverHeader" );
				
				WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( icon.GetMainWidget(), m_Parent, "MouseClick2" );
				WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( icon.GetGhostSlot(), m_Parent, "MouseClick2" );
				WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( icon.GetPanelWidget(), m_Parent, "MouseClick2" );
			}
		}

		for ( i = 0; i < m_AttachmentSlotNames.Count(); i++ )
		{
			SlotsIcon icon2 = SlotsContainer.Cast( m_AttachmentsContainer.Get( ( i / ITEMS_IN_ROW ) ) ).GetSlotIcon( i % ITEMS_IN_ROW );
			WidgetEventHandler.GetInstance().RegisterOnDoubleClick( icon2.GetPanelWidget(), m_Parent, "DoubleClick" );
			
			string path = "CfgSlots" + " Slot_" + m_AttachmentSlotNames[i];

			//Show different magazine icon for firearms and pistols
			if ( m_AttachmentSlotNames[i] == "magazine" )
			{
				if ( !m_Entity.IsInherited( Pistol_Base ) )
					path = "CfgSlots" + " Slot_" + "magazine2";
			}
			
			string icon_name = ""; //icon_name must be in format "set:<setname> image:<imagename>"
			if( GetGame().ConfigGetText( path + " ghostIcon", icon_name ) && icon_name != "" )
				icon2.GetGhostSlot().LoadImageFile( 0, StaticGUIUtils.VerifyIconImageString(StaticGUIUtils.IMAGESETGROUP_INVENTORY,icon_name) );
			int slot_id = InventorySlots.GetSlotIdFromString( m_AttachmentSlotNames[i] );
			m_AttachmentSlots.Insert( slot_id, icon2 );
			
			icon2.SetSlotID(slot_id);
			icon2.SetSlotDisplayName(InventorySlots.GetSlotDisplayName(slot_id));
			
			EntityAI item = m_Entity.GetInventory().FindAttachment( slot_id );
			if( item )
				AttachmentAdded( item, m_AttachmentSlotNames[i], m_Entity );
			else
				icon2.Clear();
		}
		
		if( m_AttachmentSlotNames.Count() > 0 )
		{
			int row_index = number_of_rows - 1;
			SlotsContainer row_last = SlotsContainer.Cast( m_AttachmentsContainer.Get( row_index ) );
			if( row_last )
			{
				for( int k = m_AttachmentSlotNames.Count() % ITEMS_IN_ROW; k < ITEMS_IN_ROW; k++ )
				{
					row_last.GetSlotIcon( k ).GetMainWidget().Show( false );
				}
				row_last.GetRootWidget().Update();
				row_last.GetRootWidget().GetParent().Update();
			}
		}
	}

	array<string> GetItemSlots( EntityAI e )
	{
		TStringArray searching_in = new TStringArray;
		searching_in.Insert( CFG_VEHICLESPATH );
		searching_in.Insert( CFG_WEAPONSPATH );
		searching_in.Insert( CFG_MAGAZINESPATH );

		array<string> attachments_slots	= new array<string>;

		for ( int s = 0; s < searching_in.Count(); ++s )
		{
			string cfg_name = searching_in.Get( s );
			string path = cfg_name + " " + e.GetType();

			if ( GetGame().ConfigIsExisting( path ) )
			{
				g_Game.ConfigGetTextArray( path + " attachments", attachments_slots );
				if ( e.IsWeapon() && (!e.ConfigIsExisting("DisplayMagazine") || e.ConfigGetBool("DisplayMagazine")) )
				{
					attachments_slots.Insert( "magazine" );
				}
				return attachments_slots;
			}
		}
		if ( e.IsWeapon() && (!e.ConfigIsExisting("DisplayMagazine") || e.ConfigGetBool("DisplayMagazine")) )
		{
			attachments_slots.Insert( "magazine" );
		}
		return attachments_slots;
	}
}
