class ZombieContainer: CollapsibleContainer
{
	protected ref Container						m_Container;
	protected ref CargoContainer				m_CargoGrid;
	protected ref map<int, ref Widget>			m_InventorySlots;
	protected ref map<EntityAI, ref Container>	m_ShowedItems = new ref map<EntityAI, ref Container>;
	protected EntityAI							m_ZombieEntity;
	
	void ZombieContainer( LayoutHolder parent, int sort = -1 )
	{
		m_InventorySlots = new ref map<int, ref Widget>;
		m_Container = new Container( this );
		m_Body.Insert( m_Container );
		
		m_MainWidget = m_RootWidget.FindAnyWidget( "body" );
		
		WidgetEventHandler.GetInstance().RegisterOnChildAdd( m_MainWidget, this, "OnChildAdd" );
		WidgetEventHandler.GetInstance().RegisterOnChildRemove( m_MainWidget, this, "OnChildRemove" );
		
		SetHeaderName();
	}
	
	void SetEntity( EntityAI zombie_entity )
	{
		m_ZombieEntity = zombie_entity;
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
	
	void OnIconDrag( Widget w )
	{
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
		w.GetParent().FindAnyWidget( name ).Show( false );
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
		
		if (m_ZombieEntity.GetInventory().CanAddEntityInCargo( item ))
			GetGame().GetPlayer().PredictiveTakeEntityToTargetCargo( m_ZombieEntity, item );
		else if( m_ZombieEntity.GetInventory().CanAddEntityToInventory( item ) )
		{
			GetGame().GetPlayer().PredictiveTakeEntityToTargetInventory( m_ZombieEntity, FindInventoryLocationType.ANY, item );
		}
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
			else if( receiver_item.GetInventory().CanAddEntityInCargo( item ) && !receiver_item.GetInventory().HasEntityInCargo( item ) )
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
				player.PredictiveTakeEntityToTargetInventory( m_ZombieEntity, FindInventoryLocationType.ANY, ipw.GetItem() );
			}
		}
	}

	void SetHeaderName()
	{
		Header h = Header.Cast( m_Body.Get( 0 ) );
		h.SetName( "#container_inventory"/*"ZOMBIE CONTAINER"*/ );
	}

	override void UpdateInterval()
	{
		if( m_ZombieEntity == null )
		{
			return;
		}
		int attachments_count = m_ZombieEntity.GetInventory().AttachmentCount();
		ref map<EntityAI, ref Container> new_showed_items = new ref map<EntityAI, ref Container>;
		ref array<EntityAI> showed_player_ghost_entities = new ref array<EntityAI>;
		for ( int i = 0; i < attachments_count; i++ )
		{
			EntityAI entity = m_ZombieEntity.GetInventory().GetAttachmentFromIndex( i );
			if ( entity )
			{
				int slot_id = entity.GetInventory().GetSlotId(0);
				ItemPreviewWidget ipw = ItemPreviewWidget.Cast( m_InventorySlots.Get( slot_id ) );
				if( ipw == null )
				{
					return;
				}
				string name2 = ipw.GetParent().GetName();
				
				ipw.Show( true );
				ipw.GetParent().Show( true );
				name2.Replace( "PanelWidget", "GhostSlot" );
				ipw.GetParent().GetParent().FindAnyWidget( name2 ).Show( false );
				ipw.SetItem( entity );
				showed_player_ghost_entities.Insert( entity );

				string config = "CfgVehicles " + entity.GetType() + " GUIInventoryAttachmentsProps";

					if( m_ShowedItems.Contains( entity ) == false )
					{
						string name;
						if( entity.GetInventory().GetCargo() )
						{
							ContainerWithCargo iwc = new ContainerWithCargo( this, -1 );
							iwc.Get( 0 ).GetRootWidget().ClearFlags( WidgetFlags.DRAGGABLE );
							iwc.SetEntity( entity );
							new_showed_items.Insert( entity, iwc );
							ipw.GetParent().SetUserID( ( new_showed_items.Count() - 1) );
							WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( ipw.GetParent(),  this, "ToggleWidget" );

							name = ipw.GetName();
							name.Replace( "Icon", "RadialIcon" );
							ipw.GetParent().GetParent().FindAnyWidget( name ).Show(true);
						}
						else if( entity.GetSlotsCountCorrect() > 0 )
						{
							ContainerWithCargoAndAttachments iwca = new ContainerWithCargoAndAttachments( this, -1 );
							iwca.Get( 0 ).GetRootWidget().ClearFlags( WidgetFlags.DRAGGABLE );
							iwca.SetEntity( entity );
							new_showed_items.Insert( entity, iwca );
							ipw.GetParent().SetUserID( ( new_showed_items.Count() - 1 ) );
							WidgetEventHandler.GetInstance().RegisterOnMouseButtonUp( ipw.GetParent(),  this, "ToggleWidget" );

							name = ipw.GetName();
							name.Replace( "Icon", "RadialIcon" );
							ipw.GetParent().GetParent().FindAnyWidget( name ).Show( true );
						}
					}
					else
					{
						new_showed_items.Insert( entity, m_ShowedItems.Get( entity ) );
					}
			}
		}
		
		if( m_ShowedItems.Contains( m_ZombieEntity ) == false )
		{
			if( m_ZombieEntity.GetInventory().GetCargo() )
			{
				ContainerWithCargo iwcc = new ContainerWithCargo( this, -1 );
				iwcc.Get( 0 ).GetRootWidget().ClearFlags( WidgetFlags.DRAGGABLE );
				iwcc.SetEntity( m_ZombieEntity );
				new_showed_items.Insert( m_ZombieEntity, iwcc );
			}
		}
		else
		{
			new_showed_items.Insert( m_ZombieEntity, m_ShowedItems.Get( m_ZombieEntity ) );
		}

		for ( i = 0; i < m_ShowedItems.Count(); i++ )
		{
			EntityAI ent = m_ShowedItems.GetKey( i );
			m_ShowedItems.GetElement( i ).UpdateInterval();
			if( new_showed_items.Contains( ent ) == false )
			{
				Container con = m_ShowedItems.GetElement( i );
				( Container.Cast( con.m_Parent ) ).Remove( con );
			}
		}
		
		for ( i = 0; i < m_InventorySlots.Count(); i++)
		{
			ipw = ItemPreviewWidget.Cast( m_InventorySlots.GetElement(i) );
			if( ipw.GetItem() != null && showed_player_ghost_entities.Find( ipw.GetItem() ) == INDEX_NOT_FOUND )
			{
				name2 = ipw.GetParent().GetName();
				ipw.Show( false );
				name2.Replace( "PanelWidget", "GhostSlot" );
				ipw.GetParent().GetParent().FindAnyWidget( name2 ).Show( true );
				ipw.SetItem( null );
			}
			
		}

		m_ShowedItems = new_showed_items;
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
	}

	override void SetPreviousActive()
	{
		if( ItemManager.GetInstance().IsMicromanagmentMode() )
		{
			ItemManager.GetInstance().SetItemMoving( true );
		}
		
		if( IsFirstIndex() )
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
		}
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
					return;
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
					return;
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
			
			Container cnt = Container.Cast( m_Body.Get( 1 ) );
   			cnt.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).Show( true );
			
			//ScrollToActiveContainer( Container.Cast( cnt.Get( m_FocusedRow ) ) );
		}
	}

	void ToggleContainer( Widget w , int number )
	{
		ClosableContainer c = ClosableContainer.Cast( m_ShowedItems.GetElement( number ) );
		if( c.IsOpened() )
		{
			c.Close();
		}
		else
		{
			c.Open();
		}

		string name = w.GetName();
		name.Replace( "PanelWidget", "RadialIcon" );
		w.GetParent().GetParent().FindAnyWidget( name ).Show( !w.FindAnyWidget( name ).IsVisible() );
	}

	void ToggleWidget( Widget w )
	{
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		if( ipw.GetItem() )
		{
			ToggleContainer( w, w.GetUserID() );
		}
	}

	void InitGhostSlots()
	{
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

				int row = i / ITEMS_IN_ROW;
				if( row >= m_Container.Count() )
				{
					if( row < ( player_ghosts_slots.Count() / ITEMS_IN_ROW ) )
						AddSlotsContainer( ITEMS_IN_ROW );
					else
						AddSlotsContainer( player_ghosts_slots.Count() % ITEMS_IN_ROW );
				}
				Widget item_preview = GetWidgetSlot( i );
				LoadIconIntoWidgetSlot( icon_name, i );

				GetGame().ConfigGetText( path + " name", slot_name );
				int slot_id = InventorySlots.GetSlotIdFromString( slot_name );
				m_InventorySlots.Set( slot_id, item_preview );
			}
		}
	}
	
	void AddSlotsContainer( int row_count )
	{
		ref SlotsContainer s_cont = new SlotsContainer( m_Container );
		s_cont.SetColumnCount( row_count );
		m_Container.Insert( s_cont );
	}

	Widget GetWidgetSlot( int slot_number )
	{
		int row = slot_number / ITEMS_IN_ROW;
		int column = slot_number % ITEMS_IN_ROW;

		Widget item_preview = m_Container.Get( row ).GetMainWidget().FindAnyWidget( "Render" + column );
		if( !item_preview )
		{
			item_preview = m_Container.Get( row ).GetMainWidget().FindAnyWidget( "Icon" + column );
		}
		WidgetEventHandler.GetInstance().RegisterOnDrag( item_preview.GetParent(),  this, "OnIconDrag" );
		WidgetEventHandler.GetInstance().RegisterOnDrop( item_preview.GetParent(),  this, "OnIconDrop" );
		WidgetEventHandler.GetInstance().RegisterOnDoubleClick( item_preview.GetParent(),  this, "DoubleClick" );
		return item_preview;
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
			if( !iw.GetItem() )
			{
				return;
			}
			
			ItemBase item = ItemBase.Cast( iw.GetItem() );
			
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			
			if( !item.GetInventory().CanRemoveEntity() )
				return;
			
			if (player.GetInventory().HasEntityInInventory( item ) && GetGame().GetPlayer().GetHumanInventory().CanAddEntityInHands( item ) )
			{
				player.PredictiveTakeEntityToHands( item );
			}
			else
			{
				if( item.GetInventory().CanRemoveEntity() )
				{
					InventoryLocation il = new InventoryLocation;
					if ( player.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.ANY, il) )
					{
						if( item.ConfigGetFloat("varStackMax") )
							item.SplitIntoStackMaxClient( player, -1, );
						else
							player.PredictiveTakeEntityToInventory( FindInventoryLocationType.ANY, InventoryItem.Cast( item ) );
					}
					else if( GetGame().GetPlayer().GetHumanInventory().CanAddEntityInHands( item ) )
					{
						player.PredictiveTakeEntityToHands( item );
					}
				}
			}
			iw.SetItem( null );
			name.Replace( "Render", "GhostSlot" );
			w.GetParent().FindAnyWidget( name ).Show( true );
			
			ItemManager.GetInstance().HideTooltip();
		}
	}
	
	void LoadIconIntoWidgetSlot( string icon_name, int slot_number )
	{
		int column = slot_number % ITEMS_IN_ROW;
		Widget item_preview = GetWidgetSlot( slot_number );
		ImageWidget image_widget = ImageWidget.Cast( item_preview.FindAnyWidget( "GhostSlot" + column ) );
		if( !image_widget )
		{
			image_widget = ImageWidget.Cast( item_preview.GetParent().GetParent().FindAnyWidget( "GhostSlot" + column ) );
		}
		item_preview.GetParent().GetParent().Show( true );
		image_widget.Show( true );
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( item_preview.GetParent().GetParent().FindAnyWidget( "PanelWidget" + column ),  this, "OnDropReceivedFromGhostArea" );
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( item_preview.GetParent().GetParent().FindAnyWidget( "GhostSlot" + column ),  this, "OnDropReceivedFromGhostArea" );
		image_widget.LoadImageFile( 0, "set:dayz_inventory image:" + icon_name );
	}

	override void CollapseButtonOnMouseButtonDown(Widget w)
	{
		super.CollapseButtonOnMouseButtonDown(w);
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
}
