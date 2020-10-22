enum Direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
}

enum ConsoleToolbarType
{
	//Local Player
	PLAYER_EQUIPMENT_SLOTS_ITEM,
	PLAYER_EQUIPMENT_SLOTS_ITEM_WITH_CARGO,
	PLAYER_EQUIPMENT_SLOTS_ITEM_WITH_ATTACHMENTS,
	PLAYER_EQUIPMENT_SLOTS_ITEM_FREE,
	
	PLAYER_CARGO_CONTAINER_EMPTY_CONTAINER,
	PLAYER_CARGO_CONTAINER_ITEM,
	PLAYER_CARGO_CONTAINER_ITEM_NO_EQUIP,
	PLAYER_CARGO_CONTAINER_ITEM_WITH_QUANTITY,
	PLAYER_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS,
	PLAYER_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS_NO_EQUIP,
	
	PLAYER_ITEM_WITH_ATTACHMENTS_CONTAINER_ITEM,
	
	//Vicinity Player
	VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM,
	VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM_WITH_CARGO,
	VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM_WITH_ATTACHMENTS,
	VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM_FREE,
	
	VICNITY_PLAYER_CARGO_CONTAINER_EMPTY_CONTAINER,
	VICNITY_PLAYER_CARGO_CONTAINER_ITEM,
	VICNITY_PLAYER_CARGO_CONTAINER_ITEM_NO_EQUIP,
	VICNITY_PLAYER_CARGO_CONTAINER_ITEM_WITH_QUANTITY,
	VICNITY_PLAYER_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS,
	VICNITY_PLAYER_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS_NO_EQUIP,
	
	VICNITY_PLAYER_ITEM_WITH_ATTACHMENTS_CONTAINER_ITEM,
	
	//Vicinity Zombie
	VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM,
	VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM_WITH_CARGO,
	VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM_WITH_ATTACHMENTS,
	VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM_FREE,
	
	VICNITY_ZOMBIE_CARGO_CONTAINER_EMPTY_CONTAINER,
	VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM,
	VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_NO_EQUIP,
	VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_WITH_QUANTITY,
	VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS,
	VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS_NO_EQUIP,
	
	VICNITY_ZOMBIE_ITEM_WITH_ATTACHMENTS_CONTAINER_ITEM,
	
	//Local Player Hands
	HANDS_ITEM,
	HANDS_ITEM_NO_EQUIP,
	HANDS_ITEM_WITH_QUANTITY,
	HANDS_ITEM_EMPTY,
	
	//Vicinity Container
	VICINITY_CONTAINER_LIST_ITEM_WITH_CONTAINER,
	VICINITY_CONTAINER_LIST_ITEM_WITH_CONTAINER_NO_EQUIP,
	VICINITY_CONTAINER_LIST_ITEM,
	VICINITY_CONTAINER_LIST_ITEM_NO_EQUIP,
	VICINITY_CONTAINER_LIST_ITEM_WITH_QUANTITY,
	VICINITY_CONTAINER_LIST_HEADER,
	VICINITY_CONTAINER_LIST_EMPTY_ITEM,
	
	VICINITY_CONTAINER_DETAILS_EMPTY,
	VICINITY_CONTAINER_DETAILS_ITEM,
	VICINITY_CONTAINER_DETAILS_ITEM_NO_EQUIP,
	VICINITY_CONTAINER_DETAILS_ITEM_WITH_QUANTITY
}

class Inventory: LayoutHolder
{
	protected ref LeftArea					m_LeftArea;
	protected ref RightArea					m_RightArea;
	protected ref HandsArea					m_HandsArea;
	protected ref PlayerPreview				m_PlayerPreview;
	protected ref InventoryQuickbar			m_Quickbar;
	
	protected Widget						m_QuickbarWidget;
	protected Widget						m_SpecializationPanel;
	protected Widget						m_SpecializationIcon;
	protected Widget						m_TopConsoleToolbarVicinity;
	protected Widget						m_TopConsoleToolbarHands;
	protected Widget						m_TopConsoleToolbarEquipment;
	protected RichTextWidget				m_BottomConsoleToolbar;

	protected ref ContextMenu				m_ContextMenu;
	protected static ref map<string, int>	m_PlayerAttachmentsIndexes;
	
	protected bool							m_HadFastTransferred;
	protected bool							m_HadInspected;
	
	protected static Inventory				m_Instance;
	
	protected int							m_ControllerAngle;
	protected int							m_ControllerTilt;
	protected bool							m_ControllerRightStickTimerEnd = true;
	protected ref Timer						m_ControllerRightStickTimer;
	
	protected bool							m_HoldingQB;
	protected InventoryItem					m_QBHoveredItems;
	
	void Inventory( LayoutHolder parent )
	{
		m_Instance = this;
		LoadPlayerAttachmentIndexes();
		
		m_ControllerRightStickTimer = new Timer();
		new ItemManager( GetMainWidget() );
		new ColorManager();
		
		m_LeftArea = new LeftArea( this );
		m_RightArea = new RightArea( this );
		m_HandsArea = new HandsArea( this );
		m_PlayerPreview = new PlayerPreview( this );
		

		m_QuickbarWidget = GetMainWidget().FindAnyWidget( "QuickbarGrid" );
		m_Quickbar = new InventoryQuickbar( m_QuickbarWidget );
		m_Quickbar.UpdateItems( m_QuickbarWidget );
		
		m_SpecializationPanel = GetMainWidget().FindAnyWidget("SpecializationPanelPanel");
		m_SpecializationIcon = GetMainWidget().FindAnyWidget("SpecializationIcon");
		
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget().FindAnyWidget( "LeftBackground" ),  this, "OnLeftPanelDropReceived" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget().FindAnyWidget( "LeftBackground" ),  this, "DraggingOverLeftPanel" );
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget().FindAnyWidget( "LeftPanel" ).FindAnyWidget( "Scroller" ),  this, "OnLeftPanelDropReceived" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget().FindAnyWidget( "LeftPanel" ).FindAnyWidget( "Scroller" ),  this, "DraggingOverLeftPanel" );
		
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget().FindAnyWidget( "RightBackground" ),  this, "OnRightPanelDropReceived" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget().FindAnyWidget( "RightBackground" ),  this, "DraggingOverRightPanel" );
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "Scroller" ),  this, "OnRightPanelDropReceived" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "Scroller" ),  this, "DraggingOverRightPanel" );
		
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget().FindAnyWidget( "CharacterPanel" ),  this, "OnCenterPanelDropReceived" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget().FindAnyWidget( "CharacterPanel" ),  this, "DraggingOverCenterPanel" );
		
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget().FindAnyWidget( "HandsPanel" ),  this, "OnHandsPanelDropReceived" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget().FindAnyWidget( "HandsPanel" ),  this, "DraggingOverHandsPanel" );
		
		#ifdef PLATFORM_CONSOLE
			PluginDiagMenu plugin_diag_menu = PluginDiagMenu.Cast( GetPlugin(PluginDiagMenu) );
			GetGame().GetUIManager().ShowUICursor( false );
			ResetFocusedContainers();
			GetMainWidget().FindAnyWidget( "CursorCharacter" ).Show( false );
	
			//console inventory toolbar
			m_TopConsoleToolbarVicinity		= GetRootWidget().FindAnyWidget( "LBRB_Vicinity" );
			m_TopConsoleToolbarHands		= GetRootWidget().FindAnyWidget( "LBRB_Hands" );
			m_TopConsoleToolbarEquipment	= GetRootWidget().FindAnyWidget( "LBRB_Equipment" );
			#ifdef PLATFORM_PS4
			ImageWidget.Cast( m_TopConsoleToolbarVicinity.FindAnyWidget( "LBRB_Vicinity_LBIcon" ) ).LoadImageFile( 0, "set:playstation_buttons image:L1" );
			ImageWidget.Cast( m_TopConsoleToolbarVicinity.FindAnyWidget( "LBRB_Vicinity_RBIcon" ) ).LoadImageFile( 0, "set:playstation_buttons image:R1" );
			ImageWidget.Cast( m_TopConsoleToolbarHands.FindAnyWidget( "LBRB_Hands_LBIcon" ) ).LoadImageFile( 0, "set:playstation_buttons image:L1" );
			ImageWidget.Cast( m_TopConsoleToolbarHands.FindAnyWidget( "LBRB_Hands_RBIcon" ) ).LoadImageFile( 0, "set:playstation_buttons image:R1" );
			ImageWidget.Cast( m_TopConsoleToolbarEquipment.FindAnyWidget( "LBRB_Equipment_LBIcon" ) ).LoadImageFile( 0, "set:playstation_buttons image:L1" );
			ImageWidget.Cast( m_TopConsoleToolbarEquipment.FindAnyWidget( "LBRB_Equipment_RBIcon" ) ).LoadImageFile( 0, "set:playstation_buttons image:R1" );
			#endif
			m_BottomConsoleToolbar			= RichTextWidget.Cast( GetRootWidget().FindAnyWidget( "ContextToolbarText" ) );
			UpdateConsoleToolbar();
		#endif
	}
	
	static Inventory GetInstance()
	{
		return m_Instance;
	}
	
	void Serialize()
	{
		ItemManager.GetInstance().SerializeDefaultOpenStates();
		ItemManager.GetInstance().SerializeDefaultHeaderOpenStates();
	}

	void Deserialize()
	{
		ItemManager.GetInstance().DeserializeDefaultOpenStates();
		ItemManager.GetInstance().DeserializeDefaultHeaderOpenStates();
	}

	static int GetPlayerAttachmentIndex( string slot_name )
	{
		return m_PlayerAttachmentsIndexes[slot_name];
	}
	
	static int GetPlayerAttachmentIndex( int slot_id )
	{
		return GetPlayerAttachmentIndex( InventorySlots.GetSlotName( slot_id ) );
	}
	
	protected void LoadPlayerAttachmentIndexes()
	{
		m_PlayerAttachmentsIndexes	= new map<string, int>;
		
		string data;
		string slot_name;
		int i;
		
		if( GetGame().GetProfileString( "INV_AttIndexes", data ) )
		{
			JsonFileLoader<map<string, int>>.JsonLoadData( data, m_PlayerAttachmentsIndexes );
		}
		
		string config_path_ghosts_slots = "CfgVehicles SurvivorBase InventoryEquipment playerSlots";
		ref array<string> player_ghosts_slots = new array<string>;
		GetGame().ConfigGetTextArray( config_path_ghosts_slots, player_ghosts_slots );
		
		for( i = 0; i < player_ghosts_slots.Count(); i++ )
		{
			slot_name = player_ghosts_slots.Get( i );
			slot_name.Replace( "Slot_", "" );
			if( !m_PlayerAttachmentsIndexes.Contains( slot_name ) && InventorySlots.GetSlotIdFromString( slot_name ) != -1 )
			{
				m_PlayerAttachmentsIndexes.Insert( slot_name, m_PlayerAttachmentsIndexes.Count() );
			}
		}
		
		data = JsonFileLoader<map<string, int>>.JsonMakeData( m_PlayerAttachmentsIndexes );
		GetGame().SetProfileString( "INV_AttIndexes", data );
	}
	
	static void MoveAttachmentUp( int slot_id )
	{
		int curr			= GetPlayerAttachmentIndex( slot_id );
		
		int next_offset		= 0;
		string next_item	= "init";
		int next_id;
		EntityAI next_ent;
		
		while( !next_ent && next_item != "" )
		{
			next_item		= m_PlayerAttachmentsIndexes.GetKeyByValue( curr + --next_offset );
		 	next_id			= InventorySlots.GetSlotIdFromString( next_item );
			next_ent		= GetGame().GetPlayer().GetInventory().FindAttachment( next_id );
			if( next_ent && !m_Instance.m_RightArea.HasEntityContainerVisible( next_ent ) )
				next_ent	= null;
		}
		
		if( next_item != "" && next_ent )
		{
			int next = GetPlayerAttachmentIndex( next_item );
			m_PlayerAttachmentsIndexes.Set( InventorySlots.GetSlotName( slot_id ), next );
			m_PlayerAttachmentsIndexes.Set( next_item, curr );
			if( m_Instance )
				m_Instance.m_RightArea.SwapItemsInOrder( next_id, slot_id );
		}
	}
	
	static void MoveAttachmentDown( int slot_id )
	{
		int curr			= GetPlayerAttachmentIndex( slot_id );
		
		int next_offset		= 0;
		string next_item	= "init";
		int next_id;
		EntityAI next_ent;
		
		while( !next_ent && next_item != "" )
		{
			next_item		= m_PlayerAttachmentsIndexes.GetKeyByValue( curr + ++next_offset );
		 	next_id			= InventorySlots.GetSlotIdFromString( next_item );
			next_ent		= GetGame().GetPlayer().GetInventory().FindAttachment( next_id );
			if( next_ent && !m_Instance.m_RightArea.HasEntityContainerVisible( next_ent ) )
				next_ent	= null;
		}
		
		if( next_item != "" && next_ent )
		{
			int next = GetPlayerAttachmentIndex( next_item );
			m_PlayerAttachmentsIndexes.Set( InventorySlots.GetSlotName( slot_id ), next );
			m_PlayerAttachmentsIndexes.Set( next_item, curr );
			if( m_Instance )
				m_Instance.m_RightArea.SwapItemsInOrder( next_id, slot_id );
		}
	}

	protected int GetProperControllerStickAngle( int angle )
	{
		int proper_angle = ( 360 - angle ) % 360;
		return proper_angle;
	}

	protected int AngleToDirection( int angle )
	{
		if( angle < 45 || angle > 315)
		{
			return Direction.RIGHT;
		}
		else if ( angle < 135 && angle > 45 )
		{
			return Direction.DOWN;
		}
		else if ( angle < 225 && angle > 135 )
		{
			return Direction.LEFT;
		}
		else if ( angle < 315 && angle > 225 )
		{
			return Direction.UP;
		}
		return -1;
	}

	void TimerEnd()
	{
		m_ControllerRightStickTimerEnd = true;
		m_ControllerRightStickTimer.Stop();
	}

	bool Controller( Widget w, int control, int value )
	{
		#ifdef PLATFORM_CONSOLE
		//Right stick
		if ( control == ControlID.CID_RADIALMENU )
		{
			m_ControllerAngle 	= value >> 4; 	// <0,360>
			m_ControllerTilt	= value & 0xF; 	// <0,10>

			m_ControllerAngle = GetProperControllerStickAngle(m_ControllerAngle);

			m_ControllerAngle = AngleToDirection(m_ControllerAngle);


			if(m_ControllerTilt>5)
			{
				if( m_ControllerRightStickTimerEnd )
				{
					m_ControllerRightStickTimerEnd = false;
					m_ControllerRightStickTimer.Run( 0.1, this, "TimerEnd" );
				}
			}
			return true;
		}
		
		if ( control == 4 && value == 1 )
		{
			if( GetGame().GetInput().LocalValue( "UAUISelect", false ) )
			{
				EnableMicromanagement();
			}
			
			if( m_RightArea.IsActive() )
				m_RightArea.MoveGridCursor(Direction.RIGHT);
			if( m_LeftArea.IsActive() )
				m_LeftArea.MoveGridCursor(Direction.RIGHT);
			if( m_HandsArea.IsActive() )
				m_HandsArea.MoveGridCursor(Direction.RIGHT);
		}
		else if ( control == 3 && value == 1 )
		{
			if( GetGame().GetInput().LocalValue( "UAUISelect", false ) )
			{
				EnableMicromanagement();
			}
			
			if( m_RightArea.IsActive() )
				m_RightArea.MoveGridCursor(Direction.LEFT);
			if( m_LeftArea.IsActive() )
				m_LeftArea.MoveGridCursor(Direction.LEFT);
			if( m_HandsArea.IsActive() )
				m_HandsArea.MoveGridCursor(Direction.LEFT);
		}
		else if ( control == 5 && value == 1 )
		{
			if( GetGame().GetInput().LocalValue( "UAUISelect", false ) )
			{
				EnableMicromanagement();
			}
			
			if( m_RightArea.IsActive() )
				m_RightArea.MoveGridCursor(Direction.UP);
			if( m_LeftArea.IsActive() )
				m_LeftArea.MoveGridCursor(Direction.UP);
			if( m_HandsArea.IsActive() )
				m_HandsArea.MoveGridCursor(Direction.UP);
		}
		else if ( control == 6 && value == 1 )
		{
			if( GetGame().GetInput().LocalValue( "UAUISelect", false ) )
			{
				EnableMicromanagement();
			}
			
			if( m_RightArea.IsActive() )
				m_RightArea.MoveGridCursor(Direction.DOWN);
			if( m_LeftArea.IsActive() )
				m_LeftArea.MoveGridCursor(Direction.DOWN);
			if( m_HandsArea.IsActive() )
				m_HandsArea.MoveGridCursor(Direction.DOWN);
		}
		
		UpdateConsoleToolbar();
		#endif
		return false;
	}

	void DraggingOverHandsPanel( Widget w, int x, int y, Widget receiver )
	{
		ItemManager.GetInstance().HideDropzones();
		m_HandsArea.DraggingOverHandsPanel( w, x, y, receiver );
	}
	
	void OnHandsPanelDropReceived( Widget w, int x, int y, Widget receiver )
	{
		m_HandsArea.OnHandsPanelDropReceived( w, x, y, receiver );
	}

	void OnLeftPanelDropReceived( Widget w, int x, int y, Widget receiver )
	{
		m_LeftArea.OnLeftPanelDropReceived( w, x, y, receiver );
	}

	void OnRightPanelDropReceived( Widget w, int x, int y, Widget receiver )
	{
		if( w )
		{
			ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
			if( !ipw )
			{
				string name = w.GetName();
				name.Replace( "PanelWidget", "Render" );
				ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
				if( !ipw )
				{
					ipw = ItemPreviewWidget.Cast( w );
					if( !ipw )
					{
						return;
					}
				}
			}
	
			EntityAI item = ipw.GetItem();
			if( item )
			{
				PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
				InventoryLocation il = new InventoryLocation;
				if( player && player.GetInventory().FindFreeLocationFor(item, FindInventoryLocationType.CARGO | FindInventoryLocationType.ATTACHMENT, il) )
				{
					SplitItemUtils.TakeOrSplitToInventory(player, player, item);
				}
			}
		}
	}
	
	void OnCenterPanelDropReceived( Widget w, int x, int y, Widget receiver )
	{
		if( w )
		{
			ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
			if( !ipw )
			{
				string name = w.GetName();
				name.Replace( "PanelWidget", "Render" );
				ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
				if( !ipw )
				{
					ipw = ItemPreviewWidget.Cast( w );
					if( !ipw )
					{
						return;
					}
				}
			}
	
			EntityAI item = ipw.GetItem();
			if ( item )
			{
				if ( !item.GetInventory().CanRemoveEntity() )
					return;
				PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
				if ( player && ( player.GetInventory().CanAddAttachment( item ) ) )
				{
					float stackable = item.GetTargetQuantityMax(-1);
		
					if ( stackable == 0 || stackable >= item.GetQuantity() )
					{
						player.PredictiveTakeEntityAsAttachment( item );
					}
					else
					{
						InventoryLocation il = new InventoryLocation;
						player.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.ATTACHMENT, il );
						ItemBase.Cast(item).SplitIntoStackMaxToInventoryLocationClient( il );
					}
				}
				else
				{
					int slot_id = item.GetInventory().GetSlotId(0);
					EntityAI slot_item = player.GetInventory().FindAttachment( slot_id );
					if( slot_item && player.GetInventory().CanSwapEntitiesEx( item, slot_item ) )
					{
						player.PredictiveSwapEntities(item, slot_item);
					}
					else if ( player.CanReceiveItemIntoCargo( item ) )
					{
						InventoryLocation dst = new InventoryLocation;
						player.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.ANY, dst );
						if ( dst.IsValid() )
						{						
							if ( dst.GetType() == InventoryLocationType.HANDS && item.IsHeavyBehaviour() )
							{											
								ActionManagerClient mngr_client;
								CastTo(mngr_client, player.GetActionManager());
			
								ActionTarget atrg = new ActionTarget(item, null, -1, vector.Zero, -1.0);
								if ( mngr_client.GetAction(ActionTakeItemToHands).Can(player, atrg, null) )
									mngr_client.PerformActionStart(mngr_client.GetAction(ActionTakeItemToHands), atrg, null);
								
								return;
							}
							
							SplitItemUtils.TakeOrSplitToInventoryLocation( player, dst );
						}
					}
				}
			}
		}
	}

	void DraggingOverLeftPanel( Widget w, int x, int y, Widget receiver )
	{
		m_LeftArea.DraggingOverHeader( w, x, y, receiver );
	}

	void DraggingOverRightPanel( Widget w, int x, int y, Widget receiver )
	{
		m_RightArea.DraggingOverHeader( w, x, y, receiver );
	}
	
	void DraggingOverCenterPanel( Widget w, int x, int y, Widget receiver )
	{
		if( w )
		{
			ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
			if( !ipw )
			{
				string name = w.GetName();
				name.Replace( "PanelWidget", "Render" );
				ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
				if( !ipw )
				{
					ipw = ItemPreviewWidget.Cast( w );
					if( !ipw )
					{
						return;
					}
				}
			}
			
			EntityAI item = ipw.GetItem();
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			
			if( player && item )
			{
				int slot_id = item.GetInventory().GetSlotId(0);
				EntityAI slot_item = player.GetInventory().FindAttachment( slot_id );
				
				InventoryLocation inv_loc = new InventoryLocation;
				player.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.ANY, inv_loc );
				if( inv_loc.IsValid() )
				{
					ItemManager.GetInstance().HideDropzones();
					GetMainWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
					if( inv_loc.GetType() == 4 )
					{
						ItemManager.GetInstance().HideDropzones();
						GetMainWidget().FindAnyWidget( "HandsPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
					}
		
					ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
				}
				else
				{
					ItemManager.GetInstance().ShowSourceDropzone( item );
					ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
				}
			}
			else
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
			}
		}
	}

	override void UpdateInterval()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		InventoryItem item;
		if( GetGame().GetInput().LocalPress( "UAUIRotateInventory", false ) )
		{
			item = InventoryItem.Cast( ItemManager.GetInstance().GetDraggedItem() );
			if( item )
			{
				int size_x, size_y;
				GetGame().GetInventoryItemSize( item, size_x, size_y );
				if( size_x != size_y )
				{
					item.GetInventory().FlipCargo();
					item.GetOnItemFlipped().Invoke(item.GetInventory().GetFlipCargo());
				}
			}
		}
		
		#ifdef PLATFORM_CONSOLE
		DayZPlayerInventory dpi;
		if ( player )
			dpi = player.GetDayZPlayerInventory();
		
		// There's a second one a bit below
		if ( dpi && !dpi.IsProcessing() )
		{
			if ( GetGame().GetInput().LocalPress( "UAUIExpandCollapseContainer", false ) )
			{
				if ( m_RightArea.IsActive() )
				{
					m_RightArea.ExpandCollapseContainer();
				}
				else if ( m_LeftArea.IsActive() )
				{
					m_LeftArea.ExpandCollapseContainer();
				}
			}
			
			if ( GetGame().GetInput().LocalPress( "UAUIFastEquipOrSplit", false ) )
			{
				if ( m_HandsArea.IsActive() )
				{
					if ( m_HandsArea.EquipItem() )
					{
						m_HandsArea.SetActive( false );
						m_HandsArea.UnfocusGrid();
						m_RightArea.SetActive( true );
					}
				}
				else if ( m_RightArea.IsActive() )
				{
					m_RightArea.EquipItem();
				}
				else if ( m_LeftArea.IsActive() )
				{
					m_LeftArea.EquipItem();
				}
				
				UpdateConsoleToolbar();
				ItemManager.GetInstance().HideTooltip();
			}
			
			if ( GetGame().GetInput().LocalRelease( "UAUISelect", false ) )
			{
				if ( m_RightArea.IsActive() )
				{
					if ( m_RightArea.Select() && !ItemManager.GetInstance().IsMicromanagmentMode() )
					{
						m_RightArea.SetActive( false );
						m_RightArea.UnfocusGrid();
						m_HandsArea.SetActive( true );
					}
				}
				else if ( m_LeftArea.IsActive() )
				{
					if ( m_LeftArea.Select() && !ItemManager.GetInstance().IsMicromanagmentMode() )
					{
						//m_LeftArea.SetActive( false );
						//m_LeftArea.UnfocusGrid();
						//m_RightArea.SetActive( true );
					}
				}
				else if ( m_HandsArea.IsActive() )
				{
					if ( m_HandsArea.Select() && !ItemManager.GetInstance().IsMicromanagmentMode() )
					{
						m_HandsArea.SetActive( false );
						m_HandsArea.UnfocusGrid();
						m_RightArea.SetActive( true );
					}
				}
				
				DisableMicromanagement();
				UpdateConsoleToolbar();
			}
			
			if ( GetGame().GetInput().LocalPress( "UAUIFastTransferToVicinity", false ) )
			{
				if ( m_HandsArea.IsActive() )
				{
					item = InventoryItem.Cast( m_HandsArea.GetFocusedItem() );
					if ( item && item.GetInventory().CanRemoveEntity() )
					{
						if ( m_HandsArea.TransferItemToVicinity() )
						{
							m_HandsArea.SetActive( false );
							m_HandsArea.UnfocusGrid();
							m_LeftArea.SetActive( true );
							m_HadFastTransferred = true;
						}
					}
				}
				else if ( m_RightArea.IsActive() )
				{
					item = InventoryItem.Cast( m_RightArea.GetFocusedItem() );
					if ( item && item.GetInventory().CanRemoveEntity() )
					{
						if ( m_RightArea.TransferItemToVicinity() )
						{
							//m_RightArea.SetActive( false );
							//m_RightArea.UnfocusGrid();
							//m_LeftArea.SetActive( true );
							m_HadFastTransferred = true;
						}
					}
				}
				else if ( m_LeftArea.IsActive() )
				{
					item = InventoryItem.Cast( m_LeftArea.GetFocusedItem() );
					if ( item && item.GetInventory().CanRemoveEntity() )
					{
						m_LeftArea.TransferItemToVicinity();
						m_HadFastTransferred = true;
					}
				}
				
				UpdateConsoleToolbar();
				ItemManager.GetInstance().HideTooltip();
			}
		}
		
		if ( GetGame().GetInput().LocalPress( "UAUIInspectItem", false ) )
		{
			if ( m_HandsArea.IsActive() )
			{
				if ( m_HandsArea.InspectItem() )
				{
					m_HadInspected = true;
				}
			}
			else if ( m_RightArea.IsActive() )
			{
				if ( m_RightArea.InspectItem() )
				{
					m_HadInspected = true;
				}
			}
			else if ( m_LeftArea.IsActive() )
			{
				if( m_LeftArea.InspectItem() )
				{
					m_HadInspected = true;
				}
			}
			
			UpdateConsoleToolbar();
		}
		
		if ( GetGame().GetInput().LocalPress( "UAUIFastTransferItem", false ) )
			m_HadFastTransferred = false;
		
		if ( GetGame().GetInput().LocalPress( "UAUIInspectItem", false ) )
			m_HadInspected = false;
		
		if ( dpi && !dpi.IsProcessing() )
		{
			if ( !m_HadFastTransferred && GetGame().GetInput().LocalRelease( "UAUIFastTransferItem", false ) )
			{
				if ( ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					return;
				}
				
				if ( m_RightArea.IsActive() )
				{
					item = InventoryItem.Cast( m_RightArea.GetFocusedItem() );
					if ( item && item.GetInventory().CanRemoveEntity() )
					{
						m_RightArea.TransferItem();
					}
				}
				else if ( m_LeftArea.IsActive() )
				{
					item = InventoryItem.Cast( m_LeftArea.GetFocusedItem() );
					if ( item && item.GetInventory().CanRemoveEntity() )
					{
						if ( m_LeftArea.TransferItem() )
						{
							//m_LeftArea.SetActive( false );
							//m_LeftArea.UnfocusGrid();
							//m_RightArea.SetActive( true );
						}
					}
				}
				else if ( m_HandsArea.IsActive() )
				{
					item = InventoryItem.Cast( m_HandsArea.GetFocusedItem() );
					if ( item && item.GetInventory().CanRemoveEntity() )
					{
						if ( m_HandsArea.TransferItem() )
						{
							m_HandsArea.SetActive( false );
							m_HandsArea.UnfocusGrid();
							m_RightArea.SetActive( true );
						}
					}
				}
				
				UpdateConsoleToolbar();
				ItemManager.GetInstance().HideTooltip();
			}
		}
		
		if ( GetGame().GetInput().LocalPress( "UAUINextUp", false ) )
		{
			ItemManager.GetInstance().HideTooltip();
			
			if ( GetGame().GetInput().LocalValue( "UAUISelect", false ) )
			{
				EnableMicromanagement();
			}
			
			if ( !ItemManager.GetInstance().IsMicromanagmentMode() )
			{
				m_RightArea.UnfocusGrid();
				m_LeftArea.UnfocusGrid();
				m_HandsArea.UnfocusGrid();
			}
			if ( m_LeftArea.IsActive() )
			{
				m_LeftArea.SetPreviousActive();
			}
			else if ( m_RightArea.IsActive() )
			{
				m_RightArea.SetPreviousActive();
			}
			else if ( m_HandsArea.IsActive() )
			{
				m_HandsArea.SetPreviousActive();
			}
			
			UpdateConsoleToolbar();
		}

		if ( GetGame().GetInput().LocalPress( "UAUINextDown", false ) )
		{
			ItemManager.GetInstance().HideTooltip();
			
			if ( GetGame().GetInput().LocalValue( "UAUISelect", false ) )
			{
				EnableMicromanagement();
			}
			
			if ( !ItemManager.GetInstance().IsMicromanagmentMode() )
			{
				m_RightArea.UnfocusGrid();
				m_LeftArea.UnfocusGrid();
				m_HandsArea.UnfocusGrid();
			}
			
			if ( m_LeftArea.IsActive() )
			{
				m_LeftArea.SetNextActive();
			}
			else if ( m_RightArea.IsActive() )
			{
				m_RightArea.SetNextActive();
			}
			else if ( m_HandsArea.IsActive() )
			{
				m_HandsArea.SetNextActive();
			}
			
			UpdateConsoleToolbar();
		}

		if ( GetGame().GetInput().LocalPress( "UAUITabLeft", false ) )
		{
			ItemManager.GetInstance().HideTooltip();
			
			if ( GetGame().GetInput().LocalValue( "UAUISelect", false ) )
			{
				EnableMicromanagement();
			}
			
			if ( ItemManager.GetInstance().IsMicromanagmentMode() )
			{
				ItemManager.GetInstance().SetItemMoving( true );
			}
			
			if ( m_LeftArea.IsActive() )
			{
				if ( !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_LeftArea.UnfocusGrid();
				}
				m_LeftArea.SetActive( false );
				m_RightArea.SetActive( true );
				
				UpdateConsoleToolbar();
			}
			else if ( m_RightArea.IsActive() )
			{
				if ( !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_RightArea.UnfocusGrid();
				}
				m_RightArea.SetActive( false );
				player = PlayerBase.Cast( GetGame().GetPlayer() );
				EntityAI item_in_hands = player.GetItemInHands();
				m_HandsArea.SetActive( true );

				UpdateConsoleToolbar();
			}
			else if ( m_HandsArea.IsActive() )
			{
				m_HandsArea.UnfocusGrid();
				m_HandsArea.SetActive( false );
				m_LeftArea.SetActive( true );
				
				UpdateConsoleToolbar();
			}
		}

		if ( GetGame().GetInput().LocalPress( "UAUITabRight", false ) )
		{
			if ( GetGame().GetInput().LocalValue( "UAUISelect", false ) )
			{
				EnableMicromanagement();
			}
			
			if ( ItemManager.GetInstance().IsMicromanagmentMode() )
			{
				ItemManager.GetInstance().SetItemMoving( true );
			}
			
			ItemManager.GetInstance().HideTooltip();
			
			if ( m_LeftArea.IsActive() )
			{
				if ( !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_LeftArea.UnfocusGrid();
				}
				m_LeftArea.SetActive( false );
				player = PlayerBase.Cast( GetGame().GetPlayer() );
				item_in_hands = player.GetItemInHands();
				m_HandsArea.SetActive( true );
				
				UpdateConsoleToolbar();
			}
			else if ( m_RightArea.IsActive() )
			{
				if ( !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_RightArea.UnfocusGrid();
				}
				m_RightArea.SetActive( false );
				m_LeftArea.SetActive( true );
				
				UpdateConsoleToolbar();
			}
			else if ( m_HandsArea.IsActive() )
			{
				m_HandsArea.UnfocusGrid();
				m_HandsArea.SetActive( false );
				m_RightArea.SetActive( true );
				
				UpdateConsoleToolbar();
	
			}
		}
		
		//Open Quickbar radial menu
		if ( GetGame().GetInput().LocalPress( "UAUIQuickbarRadialInventoryOpen", false ) )
		{
			//assign item
			EntityAI item_to_assign;
						
			if ( m_HandsArea.IsActive() )
			{
				player = PlayerBase.Cast( GetGame().GetPlayer() );
				item_to_assign = player.GetItemInHands();
			}
			else if ( m_RightArea.IsActive() )
			{
				item_to_assign = m_RightArea.GetFocusedItem();
			}
			
			if ( item_to_assign && dpi && !dpi.IsProcessing() )
			{
				RadialQuickbarMenu.SetItemToAssign( item_to_assign );
				
				//open radial quickbar menu
				if ( !GetGame().GetUIManager().IsMenuOpen( MENU_RADIAL_QUICKBAR ) )
				{
					RadialQuickbarMenu.OpenMenu( GetGame().GetUIManager().FindMenu( MENU_INVENTORY ) );
				}				
			}
		}
		#endif
		
		MissionGameplay mission = MissionGameplay.Cast( GetGame().GetMission() );
		if ( !m_HadInspected && GetGame().GetInput().LocalRelease( "UAUIBack", false ) )
		{
			if ( GetMainWidget().IsVisible() )
			{
			#ifdef PLATFORM_CONSOLE
				DisableMicromanagement();
				if ( m_RightArea.IsActive() )
				{
					if ( m_RightArea.Combine() )
						mission.HideInventory();
				}
				else if ( m_LeftArea.IsActive() )
				{
					if ( m_LeftArea.Combine() )
						mission.HideInventory();
				}
				else
				{
					mission.HideInventory();
				}
			#endif
			#ifdef PLATFORM_WINDOWS
				mission.HideInventory();
			#endif
			}
		}
		
		for ( int i = 0; i < 10; i++ )
		{
			if ( !m_HoldingQB && GetGame().GetInput().LocalPress( "UAItem" + i, false ) )
			{
				m_QBHoveredItems = InventoryItem.Cast( ItemManager.GetInstance().GetHoveredItem() );
				m_HoldingQB = true;
			}
			
			if ( m_HoldingQB && GetGame().GetInput().LocalHold( "UAItem" + i, false ) )
			{
				
				AddQuickbarItem( m_QBHoveredItems, i );
				m_QBHoveredItems = null;
				m_HoldingQB = false;
			}
		}

		m_LeftArea.UpdateInterval();
		m_RightArea.UpdateInterval();
		m_HandsArea.UpdateInterval();
		m_PlayerPreview.UpdateInterval();
	}
	
	void AddQuickbarItem( InventoryItem item, int index )
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			
		if( item && item.GetInventory().CanRemoveEntity() )
		{
			player.SetQuickBarEntityShortcut( item, index ) ;
		}
		
		InventoryMenu menu = InventoryMenu.Cast( GetGame().GetUIManager().FindMenu(MENU_INVENTORY) );
		if( menu )
		{
			menu.RefreshQuickbar();
		}
	}
	
	void EnableMicromanagement()
	{
		if( !ItemManager.GetInstance().IsMicromanagmentMode() )
		{
			ItemManager.GetInstance().SetItemMicromanagmentMode( true );
			if( m_RightArea.IsActive() )
			{
				m_RightArea.SelectItem();
			}
			else if( m_LeftArea.IsActive() )
			{
				m_LeftArea.SelectItem();
			}
			else if( m_HandsArea.IsActive() )
			{
				m_HandsArea.SelectItem();
			}
			
			UpdateConsoleToolbar();
			ItemManager.GetInstance().HideTooltip();
		}
	}
	
	void DisableMicromanagement()
	{
		if( ItemManager.GetInstance().IsMicromanagmentMode() )
		{
			ItemManager.GetInstance().SetItemMicromanagmentMode( false );
			ItemManager.GetInstance().SetItemMoving( false );
			ItemManager.GetInstance().SetSelectedItem( null, null, null );
			UpdateConsoleToolbar();
			ItemManager.GetInstance().HideTooltip();
		}
	}

	override void SetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
			m_LayoutName = WidgetLayoutName.InventoryXbox;
		#else
			switch( InventoryMenu.GetWidthType() )
			{
				case ScreenWidthType.NARROW:
				{
					m_LayoutName = WidgetLayoutName.InventoryNarrow;
					break;
				}
				case ScreenWidthType.MEDIUM:
				{
					m_LayoutName = WidgetLayoutName.InventoryMedium;
					break;
				}
				case ScreenWidthType.WIDE:
				{
					m_LayoutName = WidgetLayoutName.InventoryWide;
					break;
				}
			}
		#endif
	}

	void Init() {}

	void Reset()
	{
		m_LeftArea.Refresh();
		m_RightArea.Refresh();
		m_HandsArea.Refresh();
	}
	
	void ResetFocusedContainers()
	{
		#ifdef PLATFORM_CONSOLE
		m_RightArea.UnfocusGrid();
		m_LeftArea.UnfocusGrid();
		m_HandsArea.UnfocusGrid();
		
		m_LeftArea.SetActive( false );
		m_HandsArea.SetActive( false );
		m_RightArea.SetActive( false );
		
		m_RightArea.ResetFocusedContainer();
		m_LeftArea.ResetFocusedContainer();
		
		m_RightArea.SetActive( true );
		#endif
	}

	override void OnShow()
	{
		SetFocus( GetMainWidget() );
		Deserialize();
		
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player && player.IsPlacingLocal() )
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(player.TogglePlacingLocal);
		}

		Mission mission = GetGame().GetMission();
		if ( mission )
		{
			IngameHud hud = IngameHud.Cast( mission.GetHud() );
			if ( hud )
			{
				hud.ShowQuickbarUI( false );
				hud.ShowHudInventory( true );
			}
		}
		
		UpdateSpecialtyMeter();
		
		#ifdef PLATFORM_CONSOLE
			ResetFocusedContainers();
		#endif	
		
		RefreshQuickbar();
		UpdateInterval();
		UpdateConsoleToolbar();
		
		m_HadFastTransferred = false;
		m_HadInspected = false;
	}

	override void OnHide()
	{
		Serialize();
		ItemManager.GetInstance().HideTooltip();
		Mission mission = GetGame().GetMission();
		if ( mission )
		{
			IngameHud hud = IngameHud.Cast( mission.GetHud() );
			if ( hud )
			{
				hud.ShowQuickbarUI( true );
				hud.ShowHudInventory( false );
			}
		}
		ItemManager.GetInstance().SetSelectedItem( null, null, null );
	}
	
	void UpdateSpecialtyMeter()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player && player.GetSoftSkillsManager() )
		{
			float x = player.GetSoftSkillsManager().GetSpecialtyLevel() / 2;
			float y = -0.75;
			m_SpecializationIcon.SetPos( x, y, true );	
		}
	}
	
	override void Refresh()
	{
		m_LeftArea.Refresh();
		m_HandsArea.Refresh();
		m_RightArea.Refresh();
		
		RefreshQuickbar();
		UpdateConsoleToolbar();
	}
	
	void RefreshQuickbar()
	{
		m_QuickbarWidget.Show( GetGame().GetInput().IsEnabledMouseAndKeyboardEvenOnServer() );
#ifdef PLATFORM_WINDOWS
		if ( m_Quickbar )
#else
		if ( m_Quickbar && GetGame().GetInput().IsEnabledMouseAndKeyboardEvenOnServer() )
#endif
		{
			m_Quickbar.UpdateItems( m_QuickbarWidget );
		}
	}
	
	#ifdef PLATFORM_XBOX
	static const string to_hands_swap = "<image set=\"xbox_buttons\" name=\"A\" /> " + "#dayz_context_menu_to_hands_swap" + "    ";
	static const string drop = "<image set=\"xbox_buttons\" name=\"X\" /> " + "#dayz_context_menu_drop" + "    ";
	static const string equip = "<image set=\"xbox_buttons\" name=\"Y\" /> " + "#dayz_context_menu_equip" + "    ";
	static const string split = "<image set=\"xbox_buttons\" name=\"Y\" /> " + "#dayz_context_menu_split" + "    ";
	static const string to_inventory = "<image set=\"xbox_buttons\" name=\"X\" /> " + "#dayz_context_menu_to_inventory" + "    ";
	static const string open_close_container = "<image set=\"xbox_buttons\" name=\"RS\" /> " + "#dayz_context_menu_open_close" + "    ";
	static const string combine = "<image set=\"xbox_buttons\" name=\"B\" /> " + "#dayz_context_menu_combine";
	static const string micromanagment = "<image set=\"xbox_buttons\" name=\"A\" /> " + "#dayz_context_menu_micro" + "    ";
	static const string quickslot = "<image set=\"xbox_buttons\" name=\"LS\" /> " + "#dayz_context_menu_quickslot" + "    ";
	#else
	#ifdef PLATFORM_PS4
	static const string drop = "<image set=\"playstation_buttons\" name=\"square\" /> " + "#ps4_dayz_context_menu_drop" + "    ";
	static const string equip = "<image set=\"playstation_buttons\" name=\"triangle\" /> " + "#ps4_dayz_context_menu_equip" + "    ";
	static const string split = "<image set=\"playstation_buttons\" name=\"triangle\" /> " + "#ps4_dayz_context_menu_split" + "    ";
	static const string to_inventory = "<image set=\"playstation_buttons\" name=\"square\" /> " + "#ps4_dayz_context_menu_to_inventory" + "    ";
	static const string open_close_container = "<image set=\"playstation_buttons\" name=\"R3\" /> " + "#ps4_dayz_context_menu_open_close" + "    ";
	static const string quickslot = "<image set=\"playstation_buttons\" name=\"L3\" /> " + "#ps4_dayz_context_menu_quickslot" + "    ";
	#endif
	#endif
	
	#ifdef PLATFORM_CONSOLE
	string ConsoleToolbarTypeToString( int console_toolbar_type )
	{
		#ifdef PLATFORM_PS4
		string confirm = "cross";
		string back = "circle";
		if( GetGame().GetInput().GetEnterButton() == GamepadButton.A )
		{
			confirm = "cross";
			back = "circle";
		}
		else
		{
			confirm = "circle";
			back = "cross";
		}
		
		string to_hands_swap = "<image set=\"playstation_buttons\" name=\"" + confirm + "\" /> " + "#ps4_dayz_context_menu_to_hands_swap" + "    ";
		string combine = "<image set=\"playstation_buttons\" name=\"" + back + "\" /> " + "#ps4_dayz_context_menu_combine";
		string micromanagment = "<image set=\"playstation_buttons\" name=\"" + confirm + "\" /> " + "#ps4_dayz_context_menu_micro" + "    ";
		#endif
		switch ( console_toolbar_type )
		{
			case ConsoleToolbarType.PLAYER_EQUIPMENT_SLOTS_ITEM:
				return to_hands_swap + to_inventory + drop + micromanagment + quickslot;
			case ConsoleToolbarType.PLAYER_EQUIPMENT_SLOTS_ITEM_WITH_CARGO:
				return open_close_container + to_hands_swap + drop + micromanagment + quickslot;
			case ConsoleToolbarType.PLAYER_EQUIPMENT_SLOTS_ITEM_WITH_ATTACHMENTS:
				return open_close_container + to_hands_swap + drop + micromanagment + quickslot;
			case ConsoleToolbarType.PLAYER_EQUIPMENT_SLOTS_ITEM_FREE:
				return "";
			
			case ConsoleToolbarType.PLAYER_CARGO_CONTAINER_EMPTY_CONTAINER:
				return "";
			case ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM:
				return to_hands_swap + drop + equip + micromanagment + quickslot;
			case ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM_NO_EQUIP:
				return to_hands_swap + drop + micromanagment + quickslot;
			case ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM_WITH_QUANTITY:
				return to_hands_swap + drop + split + micromanagment + quickslot;
			case ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS:
				return to_hands_swap + drop + equip + micromanagment + quickslot;
			case ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS_NO_EQUIP:
				return to_hands_swap + drop + micromanagment + quickslot;
			
			case ConsoleToolbarType.VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM:
				return to_hands_swap + drop + micromanagment;
			case ConsoleToolbarType.VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM_WITH_CARGO:
				return open_close_container + to_hands_swap + drop + micromanagment;
			case ConsoleToolbarType.VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM_WITH_ATTACHMENTS:
				return open_close_container + to_hands_swap + drop + micromanagment;
			case ConsoleToolbarType.VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM_FREE:
				return "";
			
			case ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_EMPTY_CONTAINER:
				return "";
			case ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM:
				return to_hands_swap + to_inventory + drop + equip + micromanagment;
			case ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM_NO_EQUIP:
				return to_hands_swap + to_inventory + drop + micromanagment;
			case ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM_WITH_QUANTITY:
				return to_hands_swap + to_inventory + drop + split + micromanagment;
			case ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS:
				return to_hands_swap + to_inventory + drop + equip + micromanagment;
			case ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS_NO_EQUIP:
				return to_hands_swap + to_inventory + drop + micromanagment;
			
			case ConsoleToolbarType.VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM:
				return to_hands_swap + drop + micromanagment;
			case ConsoleToolbarType.VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM_WITH_CARGO:
				return open_close_container + to_hands_swap + drop + micromanagment;
			case ConsoleToolbarType.VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM_WITH_ATTACHMENTS:
				return open_close_container + to_hands_swap + drop + micromanagment;
			case ConsoleToolbarType.VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM_FREE:
				return "";
			
			case ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_EMPTY_CONTAINER:
				return "";
			case ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM:
				return to_hands_swap + to_inventory + drop + equip + micromanagment;
			case ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_NO_EQUIP:
				return to_hands_swap + to_inventory + drop + micromanagment;
			case ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_WITH_QUANTITY:
				return to_hands_swap + to_inventory + drop + split + micromanagment;
			case ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS:
				return to_hands_swap + to_inventory + drop + equip + micromanagment;
			case ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_WITH_ATTACHMENTS_NO_EQUIP:
				return to_hands_swap + to_inventory + drop + micromanagment;
			
			case ConsoleToolbarType.HANDS_ITEM:
				return to_inventory + drop + equip  + micromanagment + quickslot;
			case ConsoleToolbarType.HANDS_ITEM_NO_EQUIP:
				return to_inventory + drop  + micromanagment + quickslot;
			case ConsoleToolbarType.HANDS_ITEM_WITH_QUANTITY:
				return to_inventory + drop + split  + micromanagment + quickslot;
			case ConsoleToolbarType.HANDS_ITEM_EMPTY:
				return "";
			
			case ConsoleToolbarType.VICINITY_CONTAINER_LIST_ITEM_WITH_CONTAINER:
				return open_close_container + to_hands_swap + to_inventory + equip  + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_LIST_ITEM_WITH_CONTAINER_NO_EQUIP:
				return open_close_container + to_hands_swap + to_inventory  + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_LIST_ITEM:
				return to_hands_swap + to_inventory + equip  + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_LIST_ITEM_NO_EQUIP:
				return to_hands_swap + to_inventory + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_LIST_ITEM_WITH_QUANTITY:
				return to_hands_swap + to_inventory + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_LIST_HEADER:
				return open_close_container ;
			case ConsoleToolbarType.VICINITY_CONTAINER_LIST_EMPTY_ITEM:
				return "";
			
			case ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_EMPTY:
				return "";
			case ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM:
				return to_hands_swap + drop + to_inventory + equip + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_NO_EQUIP:
				return to_hands_swap + drop + to_inventory + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_WITH_QUANTITY:
				return to_hands_swap + drop + to_inventory + split + micromanagment;
		}
		return "";
	}
	#endif
	
	//Console toolbar
	void UpdateConsoleToolbar()
	{
		#ifdef PLATFORM_CONSOLE
		string context_text;
		#ifdef PLATFORM_PS4
		string back = "circle";
		if( GetGame().GetInput().GetEnterButton() == GamepadButton.A )
		{
			back = "circle";
		}
		else
		{
			back = "cross";
		}
		string combine = "<image set=\"playstation_buttons\" name=\"" + back + "\" /> " + "#ps4_dayz_context_menu_combine";
		#endif
		
		if ( m_LeftArea && m_LeftArea.IsActive() )
		{
			VicinityContainer vicinity_container = m_LeftArea.GetVicinityContainer();
			if( vicinity_container.IsVicinityContainerIconsActive() )
			{
				VicinitySlotsContainer vicinity_icons_container = vicinity_container.GetVicinityIconsContainer();
				if( vicinity_icons_container.IsItemWithContainerActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_LIST_ITEM_WITH_CONTAINER );
				}
				else if( vicinity_icons_container.IsItemWithQuantityActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_LIST_ITEM_WITH_QUANTITY );
				}
				else if( vicinity_icons_container.IsItemActive() )
				{
					if( vicinity_icons_container.CanEquip() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_LIST_ITEM );
					}
					else
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_LIST_ITEM_NO_EQUIP );
					}
				}
				else if( vicinity_icons_container.IsEmptyItemActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_LIST_EMPTY_ITEM );
				}
				
				if( vicinity_icons_container.CanCombine() || vicinity_icons_container.CanCombineAmmo() )
				{
					context_text += combine;
				}
			}
			else if( vicinity_container.IsContainerWithCargoActive() )
			{
				ContainerWithCargo iwc = ContainerWithCargo.Cast( vicinity_container.GetFocusedContainer() );
				if( iwc.IsEmpty() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_EMPTY );
				}
				else if( iwc.IsItemWithQuantityActive() )
				{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_WITH_QUANTITY );
				}
				else if( iwc.IsItemActive() )
				{
					if( iwc.CanEquip() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM );
					}
					else
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_NO_EQUIP );
					}
				}
				
				if( iwc.CanCombine() || iwc.CanCombineAmmo() )
				{
					context_text += combine;
				}
			}
			else if( vicinity_container.IsItemWithAttachmentsActive() )
			{
				ContainerWithCargoAndAttachments iwca = ContainerWithCargoAndAttachments.Cast( vicinity_container.GetFocusedContainer() );
				if( iwca.IsEmpty() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_EMPTY );
				}
				else if( iwca.IsItemWithQuantityActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_WITH_QUANTITY );
				}
				else if( iwca.IsItemActive() )
				{
					if( iwca.CanEquip() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM );
					}
					else
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_NO_EQUIP );
					}
				}
				
				if( iwca.CanCombine() || iwca.CanCombineAmmo() )
				{
					context_text += combine;
				}
			}
			else if( AttachmentCategoriesContainer.Cast( m_LeftArea.GetFocusedContainer() ) )
			{
				AttachmentCategoriesContainer acc = AttachmentCategoriesContainer.Cast( m_LeftArea.GetFocusedContainer() );
				if( acc.IsEmpty() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_EMPTY );
				}
				else if( acc.IsItemWithQuantityActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_WITH_QUANTITY );
				}
				else if( acc.IsItemActive() )
				{
					if( acc.CanEquip() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM );
					}
					else
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_NO_EQUIP );
					}
				}
				else if( acc.IsHeaderActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_LIST_HEADER );
				}
				
				if( acc.CanCombine() || acc.CanCombineAmmo() )
				{
					context_text += combine;
				}
			}
			else if( PlayerContainer.Cast( m_LeftArea.GetFocusedContainer() ) )
			{
				PlayerContainer pcc = PlayerContainer.Cast( m_LeftArea.GetFocusedContainer() );
				if ( pcc.IsPlayerEquipmentActive() )
				{
					if( pcc.IsItemActive() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM );
					}
					else if( pcc.IsItemWithContainerActive() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM_WITH_CARGO );
					}
					else if( pcc.IsEmptyItemActive() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_EQUIPMENT_SLOTS_ITEM_FREE );
					}
					
					if( pcc.CanCombine() || pcc.CanCombineAmmo() )
					{
						context_text += combine;
					}
				}
				else if( pcc.IsContainerWithCargoActive() )
				{
					ContainerWithCargo iwc1a = ContainerWithCargo.Cast( pcc.GetFocusedContainer() );
					if( iwc1a.IsEmpty() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_EMPTY_CONTAINER );
					}
					else if( iwc1a.IsItemWithQuantityActive() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM_WITH_QUANTITY );
					}
					else if( iwc1a.IsItemActive() )
					{
						if( iwc1a.CanEquip() )
						{
							context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM );
						}
						else
						{
							context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM_NO_EQUIP );
						}
					}
					
					if( iwc1a.CanCombine() || iwc1a.CanCombineAmmo() )
					{
						context_text += combine;
					}
				}
				else if( pcc.IsItemWithAttachmentsActive() )
				{
					ContainerWithCargoAndAttachments iwca1a = ContainerWithCargoAndAttachments.Cast( pcc.GetFocusedContainer() );
					if( iwca1a.IsEmpty() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_EMPTY_CONTAINER );
					}
					else if( iwca1a.IsItemWithQuantityActive() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM_WITH_QUANTITY );
					}
					else if( iwca1a.IsItemActive() )
					{
						if( iwca1a.CanEquip() )
						{
							context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM );
						}
						else
						{
							context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_PLAYER_CARGO_CONTAINER_ITEM_NO_EQUIP );
						}
					}
					
					if( iwca1a.CanCombine() || iwca1a.CanCombineAmmo() )
					{
						context_text += combine;
					}
				}
			}
			else if( ZombieContainer.Cast( m_LeftArea.GetFocusedContainer() ) )
			{
				ZombieContainer zcc = ZombieContainer.Cast( m_LeftArea.GetFocusedContainer() );
				if ( zcc.IsZombieEquipmentActive() )
				{
					if( zcc.IsItemActive() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM );
					}
					else if( zcc.IsItemWithContainerActive() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM_WITH_CARGO );
					}
					else if( zcc.IsEmptyItemActive() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_EQUIPMENT_SLOTS_ITEM_FREE );
					}
					
					if( zcc.CanCombine() || zcc.CanCombineAmmo() )
					{
						context_text += combine;
					}
				}
				else if( zcc.IsContainerWithCargoActive() )
				{
					ContainerWithCargo iwc1b = ContainerWithCargo.Cast( zcc.GetFocusedContainer() );
					if( iwc1b.IsEmpty() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_EMPTY_CONTAINER );
					}
					else if( iwc1b.IsItemWithQuantityActive() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_WITH_QUANTITY );
					}
					else if( iwc1b.IsItemActive() )
					{
						if( iwc1b.CanEquip() )
						{
							context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM );
						}
						else
						{
							context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_NO_EQUIP );
						}
					}
					
					if( iwc1b.CanCombine() || iwc1b.CanCombineAmmo() )
					{
						context_text += combine;
					}
				}
				else if( zcc.IsItemWithAttachmentsActive() )
				{
					ContainerWithCargoAndAttachments iwca1b = ContainerWithCargoAndAttachments.Cast( zcc.GetFocusedContainer() );
					if( iwca1b.IsEmpty() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_EMPTY_CONTAINER );
					}
					else if( iwca1b.IsItemWithQuantityActive() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_WITH_QUANTITY );
					}
					else if( iwca1b.IsItemActive() )
					{
						if( iwca1b.CanEquip() )
						{
							context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM );
						}
						else
						{
							context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICNITY_ZOMBIE_CARGO_CONTAINER_ITEM_NO_EQUIP );
						}
					}
					
					if( iwca1b.CanCombine() || iwca1b.CanCombineAmmo() )
					{
						context_text += combine;
					}
				}
			}
		}
		else if ( m_RightArea && m_RightArea.IsActive() )
		{
			PlayerContainer player_container = m_RightArea.GetPlayerContainer();
			if ( m_RightArea.IsPlayerEquipmentActive() )
			{
				if( player_container.IsItemActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_EQUIPMENT_SLOTS_ITEM );
				}
				else if( player_container.IsItemWithContainerActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_EQUIPMENT_SLOTS_ITEM_WITH_CARGO );
				}
				else if( player_container.IsEmptyItemActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_EQUIPMENT_SLOTS_ITEM_FREE );
				}
				
				if( player_container.CanCombine() || player_container.CanCombineAmmo() )
				{
					context_text += combine;
				}
			}
			else if( player_container.IsContainerWithCargoActive() )
			{
				ContainerWithCargo iwc1 = ContainerWithCargo.Cast( player_container.GetFocusedContainer() );
				if( iwc1.IsEmpty() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_CARGO_CONTAINER_EMPTY_CONTAINER );
				}
				else if( iwc1.IsItemWithQuantityActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM_WITH_QUANTITY );
				}
				else if( iwc1.IsItemActive() )
				{
					if( iwc1.CanEquip() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM );
					}
					else
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM_NO_EQUIP );
					}
				}
				
				if( iwc1.CanCombine() || iwc1.CanCombineAmmo() )
				{
					context_text += combine;
				}
			}
			else if( player_container.IsItemWithAttachmentsActive() )
			{
				ContainerWithCargoAndAttachments iwca1 = ContainerWithCargoAndAttachments.Cast( player_container.GetFocusedContainer() );
				if( iwca1.IsEmpty() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_CARGO_CONTAINER_EMPTY_CONTAINER );
				}
				else if( iwca1.IsItemWithQuantityActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM_WITH_QUANTITY );
				}
				else if( iwca1.IsItemActive() )
				{
					if( iwca1.CanEquip() )
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM );
					}
					else
					{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM_NO_EQUIP );
					}
				}
				
				if( iwca1.CanCombine() || iwca1.CanCombineAmmo() )
				{
					context_text += combine;
				}
			}
		}
		else if ( m_HandsArea && m_HandsArea.IsActive() )
		{
			if( m_HandsArea.IsItemWithQuantityActive() )
			{
				context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.HANDS_ITEM_WITH_QUANTITY );
			}
			else if( m_HandsArea.IsItemActive() )
			{
				if( m_HandsArea.CanEquip() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.HANDS_ITEM );
				}
				else
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.HANDS_ITEM_NO_EQUIP );
				}
			}
			else  if( m_HandsArea.IsEmpty() )
			{
				context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.HANDS_ITEM_EMPTY );
			}
		}
		
		string general_text_left;
		string general_text_right;
		
		if( m_TopConsoleToolbarVicinity )
			m_TopConsoleToolbarVicinity.Show( m_LeftArea.IsActive() );
		if( m_TopConsoleToolbarHands )
			m_TopConsoleToolbarHands.Show( m_HandsArea.IsActive() );
		if( m_TopConsoleToolbarEquipment )
			m_TopConsoleToolbarEquipment.Show( m_RightArea.IsActive() );
		if( m_BottomConsoleToolbar )
			m_BottomConsoleToolbar.SetText( context_text + " " );
		
		#endif
	}
}
