enum Direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
}

enum ConsoleToolbarType
{
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
	
	HANDS_ITEM,
	HANDS_ITEM_NO_EQUIP,
	HANDS_ITEM_WITH_QUANTITY,
	HANDS_ITEM_EMPTY,
	
	VICINITY_CONTAINER_LIST_ITEM_WITH_CONTAINER,
	VICINITY_CONTAINER_LIST_ITEM_WITH_CONTAINER_NO_EQUIP,
	VICINITY_CONTAINER_LIST_ITEM,
	VICINITY_CONTAINER_LIST_ITEM_NO_EQUIP,
	VICINITY_CONTAINER_LIST_ITEM_WITH_QUANTITY,
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
	protected RichTextWidget				m_TopConsoleToolbarLeft;
	protected RichTextWidget				m_TopConsoleToolbarRight;
	protected RichTextWidget				m_BottomConsoleToolbar;

	protected ref ContextMenu				m_ContextMenu;
	protected static ref map<string, int>	m_PlayerAttachmentsIndexes;
	protected static ref map<int, string>	m_SlotIDs;
	
	protected bool							m_HadFastTransferred;
	
	void Inventory( LayoutHolder parent )
	{
		LoadPlayerAttachmentIndexes();
		
		m_ControllerRightStickTimer = new Timer();
		new ItemManager( GetMainWidget() );
		new ColorManager();
		//Deserialize();
		m_LeftArea = new LeftArea( this );
		m_RightArea = new RightArea( this );
		m_HandsArea = new HandsArea( this );
		m_PlayerPreview = new PlayerPreview( this );
		
#ifdef PLATFORM_CONSOLE
#else
		m_QuickbarWidget = GetMainWidget().FindAnyWidget( "QuickbarGrid" );
		m_Quickbar = new InventoryQuickbar( m_QuickbarWidget );
		m_Quickbar.UpdateItems( m_QuickbarWidget );
#endif			
		
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
		
		//WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget().FindAnyWidget( "InventoryWindow" ),  this, "OnLeftPanelDropReceived" );
		//WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget().FindAnyWidget( "InventoryWindow" ),  this, "DraggingOverLeftPanel" );
		
		#ifdef PLATFORM_CONSOLE
		
				PluginDiagMenu plugin_diag_menu = PluginDiagMenu.Cast( GetPlugin(PluginDiagMenu) );
				GetGame().GetUIManager().ShowUICursor( false );
				ResetFocusedContainers();
				GetMainWidget().FindAnyWidget( "CursorCharacter" ).Show( false );
		
				//console inventory toolbar
				m_TopConsoleToolbarLeft		= RichTextWidget.Cast( GetRootWidget().FindAnyWidget( "GeneralToolbarTextLeft" ) );
				m_TopConsoleToolbarRight	= RichTextWidget.Cast( GetRootWidget().FindAnyWidget( "GeneralToolbarTextRight" ) );
				m_BottomConsoleToolbar		= RichTextWidget.Cast( GetRootWidget().FindAnyWidget( "ContextToolbarText" ) );
				UpdateConsoleToolbar();
		#endif
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

	void ~Inventory()
	{
		
	}
	
	Man GetPreviewPlayer()
	{
		return m_PlayerPreview.GetPlayerInstance();
	}
	
	static int GetPlayerAttachmentIndex( string slot_name )
	{
		return m_PlayerAttachmentsIndexes[slot_name];
	}
	
	static int GetPlayerAttachmentIndex( int slot_id )
	{
		return GetPlayerAttachmentIndex( m_SlotIDs[slot_id] );
	}
	
	protected void LoadPlayerAttachmentIndexes()
	{
		m_PlayerAttachmentsIndexes	= new map<string, int>;
		m_SlotIDs					= new map<int, string>;
		
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
		
		for( i = 0; i < m_PlayerAttachmentsIndexes.Count(); i++ )
		{
			slot_name = m_PlayerAttachmentsIndexes.GetKey( i );
			m_SlotIDs.Insert( InventorySlots.GetSlotIdFromString( slot_name ), slot_name );
		}
		
		data = JsonFileLoader<map<string, int>>.JsonMakeData( m_PlayerAttachmentsIndexes );
		GetGame().SetProfileString( "INV_AttIndexes", data );
	}
	
	static void MoveAttachmentUp( int slot_id )
	{
		int curr = GetPlayerAttachmentIndex( m_SlotIDs[slot_id] );
		string prev_item = m_PlayerAttachmentsIndexes.GetKeyByValue( curr - 1 );
		if( prev_item != "" )
		{
			int prev = GetPlayerAttachmentIndex( prev_item );
			m_PlayerAttachmentsIndexes.Set( m_SlotIDs[slot_id], prev );
			m_PlayerAttachmentsIndexes.Set( prev_item, curr );
		}
	}
	
	static void MoveAttachmentDown( int slot_id )
	{
		int curr = GetPlayerAttachmentIndex( m_SlotIDs[slot_id] );
		string next_item = m_PlayerAttachmentsIndexes.GetKeyByValue( curr + 1 );
		if( next_item != "" )
		{
			int prev = GetPlayerAttachmentIndex( next_item );
			m_PlayerAttachmentsIndexes.Set( m_SlotIDs[slot_id], prev );
			m_PlayerAttachmentsIndexes.Set( next_item, curr );
		}
	}

	protected int GetProperControllerStickAngle( int angle )
	{
		int proper_angle = ( 360 - angle ) % 360;	//rotation correction

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
	
	protected int		m_ControllerAngle;
	protected int		m_ControllerTilt;
	protected bool		m_ControllerRightStickTimerEnd = true;
	protected ref Timer	m_ControllerRightStickTimer;

	bool Controller( Widget w, int control, int value )
	{
		//Print( "control: " + control + " value: " + value );
		
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
					m_RightArea.MoveGridCursor(m_ControllerAngle);
					m_LeftArea.MoveGridCursor(m_ControllerAngle);
					m_ControllerRightStickTimerEnd = false;
					m_ControllerRightStickTimer.Run( 0.1, this, "TimerEnd" );
				}
			}
			return true;
		}
		
		if ( control == ControlID.CID_RIGHT && value == 1 )
		{
			if( GetGame().GetInput().GetAction( "UAUISelectItem", false ) )
			{
				EnableMicromanagement();
			}
			
			m_RightArea.MoveGridCursor(Direction.RIGHT);
			m_LeftArea.MoveGridCursor(Direction.RIGHT);
			m_HandsArea.MoveGridCursor(Direction.RIGHT);
		}
		else if ( control == ControlID.CID_LEFT && value == 1 )
		{
			if( GetGame().GetInput().GetAction( "UAUISelectItem", false ) )
			{
				EnableMicromanagement();
			}
			
			m_RightArea.MoveGridCursor(Direction.LEFT);
			m_LeftArea.MoveGridCursor(Direction.LEFT);
			m_HandsArea.MoveGridCursor(Direction.LEFT);
		}
		else if ( control == ControlID.CID_UP && value == 1 )
		{
			if( GetGame().GetInput().GetAction( "UAUISelectItem", false ) )
			{
				EnableMicromanagement();
			}
			
			m_RightArea.MoveGridCursor(Direction.UP);
			m_LeftArea.MoveGridCursor(Direction.UP);
			m_HandsArea.MoveGridCursor(Direction.UP);
		}
		else if ( control == ControlID.CID_DOWN && value == 1 )
		{
			if( GetGame().GetInput().GetAction( "UAUISelectItem", false ) )
			{
				EnableMicromanagement();
			}
			
			m_RightArea.MoveGridCursor(Direction.DOWN);
			m_LeftArea.MoveGridCursor(Direction.DOWN);
			m_HandsArea.MoveGridCursor(Direction.DOWN);
		}
		
		UpdateConsoleToolbar();
		return false;
	}
	
	void RefreshQuantity( EntityAI item_to_refresh )
	{
		m_RightArea.RefreshQuantity( item_to_refresh );
		m_HandsArea.RefreshQuantity( item_to_refresh );
		m_LeftArea.RefreshQuantity( item_to_refresh );
	}
	
	void RefreshItemPosition( EntityAI item_to_refresh )
	{
		m_LeftArea.RefreshItemPosition( item_to_refresh );
		m_RightArea.RefreshItemPosition( item_to_refresh );
	}

	void DraggingOverHandsPanel( Widget w, int x, int y, Widget receiver )
	{
		ItemManager.GetInstance().HideDropzones();
		//GetMainWidget().FindAnyWidget( "HandsPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
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
				if( player && ( player.GetInventory().CanAddEntityToInventory( item ) ) || player.GetHumanInventory().HasEntityInHands( item ) )
				{
					player.PredictiveTakeEntityToInventory( FindInventoryLocationType.CARGO | FindInventoryLocationType.ATTACHMENT, item );
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
			if( item )
			{
				if( !item.GetInventory().CanRemoveEntity() )
					return;
				PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
				if( player && ( player.GetInventory().CanAddAttachment( item ) ) )
				{
					player.PredictiveTakeEntityAsAttachment( item );
				}
				else
				{
					int slot_id = item.GetInventory().GetSlotId(0);
					EntityAI slot_item = player.GetInventory().FindAttachment( slot_id );
					if( slot_item && player.GetInventory().CanSwapEntities( item, slot_item ) )
					{
						player.PredictiveSwapEntities(item, slot_item);
					}
					else if( player.CanReceiveItemIntoCargo( item ) )
					{
						player.PredictiveTakeEntityToCargo( item );
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
				player.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.ATTACHMENT | FindInventoryLocationType.CARGO, inv_loc );
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
		PlayerBase player;
		
		if( GetGame().GetInput().GetActionDown( "UAUIExpandCollapseContainer", false ) )
		{
			if( m_RightArea.IsActive() )
			{
				m_RightArea.ExpandCollapseContainer();
			}
			if( m_LeftArea.IsActive() )
			{
				m_LeftArea.ExpandCollapseContainer();
			}
		}
		
		if( GetGame().GetInput().GetActionDown( "UAUIFastEquipOrSplit", false ) )
		{
			if( m_HandsArea.IsActive() )
			{
				if( m_HandsArea.EquipItem() )
				{
					m_HandsArea.SetActive( false );
					m_HandsArea.UnfocusGrid();
					m_RightArea.SetActive( true );
				}
			}
			if( m_RightArea.IsActive() )
			{
				m_RightArea.EquipItem();
			}
			if( m_LeftArea.IsActive() )
			{
				if( m_LeftArea.EquipItem() )
				{
					//m_LeftArea.SetActive( false );
					//m_LeftArea.UnfocusAll();
					//m_RightArea.SetActive( true );
				}
			}
			UpdateConsoleToolbar();
			ItemManager.GetInstance().HideTooltip();
		}
		
		if( GetGame().GetInput().GetActionUp( "UAUISelectItem", false ) )
		{
			if( m_RightArea.IsActive() )
			{
				if( m_RightArea.Select() && !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_RightArea.SetActive( false );
					m_RightArea.UnfocusAll();
					m_HandsArea.SetActive( true );
				}
			}
			if( m_LeftArea.IsActive() )
			{
				if( m_LeftArea.Select() && !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					//m_LeftArea.SetActive( false );
					//m_LeftArea.UnfocusAll();
					//m_RightArea.SetActive( true );
				}
			}
			if( m_HandsArea.IsActive() )
			{
				if( m_HandsArea.Select() && !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_HandsArea.SetActive( false );
					m_HandsArea.UnfocusGrid();
					m_RightArea.SetActive( true );
				}
			}
			DisableMicromanagement();
			UpdateConsoleToolbar();
		}
		
		if( GetGame().GetInput().GetActionDown( "UAUIFastTransferToVicinity", false ) )
		{
			if( m_HandsArea.IsActive() )
			{
				if( m_HandsArea.TransferItemToVicinity() )
				{
					m_HandsArea.SetActive( false );
					m_HandsArea.UnfocusGrid();
					m_LeftArea.SetActive( true );
					m_HadFastTransferred = true;
				}
			}
			if( m_RightArea.IsActive() )
			{
				if( m_RightArea.TransferItemToVicinity() )
				{
					//m_RightArea.SetActive( false );
					//m_RightArea.UnfocusAll();
					//m_LeftArea.SetActive( true );
					m_HadFastTransferred = true;
				}
			}
			if( m_LeftArea.IsActive() )
			{
				m_LeftArea.TransferItemToVicinity();
				m_HadFastTransferred = true;
			}
			UpdateConsoleToolbar();
			ItemManager.GetInstance().HideTooltip();
		}
		
		if( GetGame().GetInput().GetActionDown( "UAUIFastTransferItem", false ) )
			m_HadFastTransferred = false;
		
		if( !m_HadFastTransferred && GetGame().GetInput().GetActionUp( "UAUIFastTransferItem", false ) )
		{
			if( ItemManager.GetInstance().IsMicromanagmentMode() )
			{
				return;
			}
			if( m_RightArea.IsActive() )
			{
				m_RightArea.TransferItem();
			}
			if( m_LeftArea.IsActive() )
			{
				if( m_LeftArea.TransferItem() )
				{
					//m_LeftArea.SetActive( false );
					//m_LeftArea.UnfocusAll();
					//m_RightArea.SetActive( true );
				}
			}
			if( m_HandsArea.IsActive() )
			{
				if( m_HandsArea.TransferItem() )
				{
					m_HandsArea.SetActive( false );
					m_HandsArea.UnfocusGrid();
					m_RightArea.SetActive( true );
				}
			}
			UpdateConsoleToolbar();
			ItemManager.GetInstance().HideTooltip();
		}
		
		if( GetGame().GetInput().GetActionDown( "UAUINextUp", false ) )
		{
			ItemManager.GetInstance().HideTooltip();
			
			if( GetGame().GetInput().GetActionDown( "UAUISelectItem", false ) )
			{
				EnableMicromanagement();
			}
			
			if( !ItemManager.GetInstance().IsMicromanagmentMode() )
			{
				m_RightArea.UnfocusGrid();
				m_LeftArea.UnfocusGrid();
				m_HandsArea.UnfocusGrid();
			}
			if( m_LeftArea.IsActive() )
			{
				m_LeftArea.SetPreviousActive();
			}
			if( m_RightArea.IsActive() )
			{
				m_RightArea.SetPreviousActive();
			}
			if( m_HandsArea.IsActive() )
			{
				m_HandsArea.SetPreviousActive();
			}
			
#ifdef PLATFORM_CONSOLE
				UpdateConsoleToolbar();
#endif		
		}

		if( GetGame().GetInput().GetActionDown( "UAUINextDown", false ) )
		{
			ItemManager.GetInstance().HideTooltip();
			
			if( GetGame().GetInput().GetAction( "UAUISelectItem", false ) )
			{
				EnableMicromanagement();
			}
			
			if( !ItemManager.GetInstance().IsMicromanagmentMode() )
			{
				m_RightArea.UnfocusGrid();
				m_LeftArea.UnfocusGrid();
				m_HandsArea.UnfocusGrid();
			}
			if( m_LeftArea.IsActive() )
			{
				m_LeftArea.SetNextActive();
			}
			if( m_RightArea.IsActive() )
			{
				m_RightArea.SetNextActive();
			}
			if( m_HandsArea.IsActive() )
			{
				m_HandsArea.SetNextActive();
			}
#ifdef PLATFORM_CONSOLE
				UpdateConsoleToolbar();
#endif
		}

		if( GetGame().GetInput().GetActionDown( "UAUITabLeft", false ) )
		{
			ItemManager.GetInstance().HideTooltip();
			
			if( GetGame().GetInput().GetAction( "UAUISelectItem", false ) )
			{
				EnableMicromanagement();
			}
			
			if( ItemManager.GetInstance().IsMicromanagmentMode() )
			{
				ItemManager.GetInstance().SetItemMoving( true );
			}
			if( m_LeftArea.IsActive() )
			{
				if( !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_LeftArea.UnfocusGrid();
				}
				m_LeftArea.SetActive( false );
				m_RightArea.SetActive( true );
				
#ifdef PLATFORM_CONSOLE
			UpdateConsoleToolbar();
#endif
			}
			else if( m_RightArea.IsActive() )
			{
				if( !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_RightArea.UnfocusGrid();
				}
				m_RightArea.SetActive( false );
				player = PlayerBase.Cast( GetGame().GetPlayer() );
				EntityAI item_in_hands = player.GetItemInHands();
				m_HandsArea.SetActive( true );

#ifdef PLATFORM_CONSOLE
			UpdateConsoleToolbar();
#endif	
			}
			else if( m_HandsArea.IsActive() )
			{
				m_HandsArea.UnfocusGrid();
				m_HandsArea.SetActive( false );
				m_LeftArea.SetActive( true );
				
#ifdef PLATFORM_CONSOLE
				UpdateConsoleToolbar();
#endif		
			}
		}

		if( GetGame().GetInput().GetActionDown( "UAUITabRight", false ) )
		{
			if( GetGame().GetInput().GetAction( "UAUISelectItem", false ) )
			{
				EnableMicromanagement();
			}
			
			if( ItemManager.GetInstance().IsMicromanagmentMode() )
			{
				ItemManager.GetInstance().SetItemMoving( true );
			}
			ItemManager.GetInstance().HideTooltip();
			if( m_LeftArea.IsActive() )
			{
				if( !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_LeftArea.UnfocusGrid();
				}
				m_LeftArea.SetActive( false );
				player = PlayerBase.Cast( GetGame().GetPlayer() );
				item_in_hands = player.GetItemInHands();
				m_HandsArea.SetActive( true );
				
#ifdef PLATFORM_CONSOLE
				UpdateConsoleToolbar();
#endif			
			}
			else if( m_RightArea.IsActive() )
			{
				if( !ItemManager.GetInstance().IsMicromanagmentMode() )
				{
					m_RightArea.UnfocusGrid();
				}
				m_RightArea.SetActive( false );
				m_LeftArea.SetActive( true );
				
#ifdef PLATFORM_CONSOLE
				UpdateConsoleToolbar();
#endif	
			}
			else if( m_HandsArea.IsActive() )
			{
				m_HandsArea.UnfocusGrid();
				m_HandsArea.SetActive( false );
				m_RightArea.SetActive( true );
				
#ifdef PLATFORM_CONSOLE
				UpdateConsoleToolbar();
#endif
	
			}
		}

		MissionGameplay mission = MissionGameplay.Cast( GetGame().GetMission() );
#ifdef PLATFORM_CONSOLE
		//Open Quickbar radial menu
		if( GetGame().GetInput().GetActionDown( "UAUIQuickbarRadialInventoryOpen", false ) )
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
			
			if ( item_to_assign )
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
		if( GetGame().GetInput().GetActionDown( "UAUIBack", false ) )
		{
			if( GetMainWidget().IsVisible() )
			{
			#ifdef PLATFORM_CONSOLE
				DisableMicromanagement();
				if( m_RightArea.IsActive() )
				{
					m_RightArea.Combine();
					m_RightArea.UnfocusGrid();

				}
				if( m_LeftArea.IsActive() )
				{
					m_LeftArea.Combine();
					m_LeftArea.UnfocusGrid();
				}
			#endif
				mission.HideInventory();
			}
		}

		m_LeftArea.UpdateInterval();
		m_RightArea.UpdateInterval();
		m_HandsArea.UpdateInterval();
		m_PlayerPreview.UpdateInterval();
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
			if( m_LeftArea.IsActive() )
			{
				m_LeftArea.SelectItem();
			}
			if( m_HandsArea.IsActive() )
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
		m_RightArea.UnfocusGrid();
		m_LeftArea.UnfocusGrid();
		m_HandsArea.UnfocusGrid();
		m_LeftArea.SetActive( false );
		m_HandsArea.SetActive( false );
		m_RightArea.SetActive( false );
		m_RightArea.ResetFocusedContainer();
		m_LeftArea.ResetFocusedContainer();
		m_RightArea.SetActive( true );
	}

	override void OnShow()
	{
		//start update
		SetFocus( GetMainWidget() );
		Deserialize();
		//m_MainWidget.Update(); 
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
				hud.SetSpecialtyMeterVisibility( true );
				hud.HideQuickbar( true, true );
				hud.ToggleHud( true, true );
			}
		}
		#ifdef PLATFORM_CONSOLE
				ResetFocusedContainers();
		#endif	
		RefreshQuickbar();
		UpdateInterval();
		UpdateConsoleToolbar();
		m_HadFastTransferred = false;
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
				hud.SetSpecialtyMeterVisibility( false );
				if( hud.GetQuickBarState() )
				{
					hud.ShowQuickbar();
				}
				
				hud.ToggleHud( hud.GetHudState(), true );
			}
		}
		ItemManager.GetInstance().SetSelectedItem( null, null, null );
	}
	
	override void Refresh()
	{
		m_LeftArea.Refresh();
		m_HandsArea.Refresh();
		m_RightArea.Refresh();
	}
	
	void RefreshQuickbar()
	{
#ifdef PLATFORM_CONSOLE
#else
		if ( m_Quickbar )
		{
			m_Quickbar.UpdateItems( m_QuickbarWidget );
		}
#endif	
	}


	void ShowQuickbar()
	{
#ifdef PLATFORM_CONSOLE
#else
		if ( m_QuickbarWidget )
		{
			m_QuickbarWidget.Show( true );
		}
#endif
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
	static const string to_hands_swap = "<image set=\"playstation_buttons\" name=\"cross\" /> To hands/swap    ";
	static const string drop = "<image set=\"playstation_buttons\" name=\"square\" />(hold) Drop    ";
	static const string equip = "<image set=\"playstation_buttons\" name=\"triangle\" /> Equip    ";
	static const string split = "<image set=\"playstation_buttons\" name=\"triangle\" /> Split    ";
	static const string to_inventory = "<image set=\"playstation_buttons\" name=\"square\" /> To inventory    ";
	static const string open_close_container = "<image set=\"playstation_buttons\" name=\"R3\" /> Open/Close container    ";
	static const string combine = "<image set=\"playstation_buttons\" name=\"circle\" /> Combine";
	static const string micromanagment = "<image set=\"playstation_buttons\" name=\"cross\" /> (hold) Micromanagment    ";
	static const string quickslot = "<image set=\"playstation_buttons\" name=\"L3\" /> (hold) Quickslot    ";
	#endif
	
	string ConsoleToolbarTypeToString( int console_toolbar_type )
	{
		switch ( console_toolbar_type )
		{
			case ConsoleToolbarType.PLAYER_EQUIPMENT_SLOTS_ITEM:
			return to_hands_swap + drop + micromanagment + quickslot;
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
			return to_hands_swap + to_inventory  + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_LIST_ITEM_WITH_QUANTITY:
			return to_hands_swap + to_inventory  + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_LIST_EMPTY_ITEM:
			return "";
			
			case ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_EMPTY:
			return "";
			case ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM:
			return to_hands_swap + to_inventory + equip + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_NO_EQUIP:
			return to_hands_swap + to_inventory + micromanagment;
			case ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_WITH_QUANTITY:
			return to_hands_swap + to_inventory + split + micromanagment;
		}
		return "";
	}
	
	//Console toolbar
	void UpdateConsoleToolbar()
	{
#ifdef PLATFORM_CONSOLE		
		string context_text;
		
		//context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_EQUIPMENT_SLOTS_ITEM );
		if ( m_LeftArea.IsActive() )
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
				
				if( vicinity_icons_container.CanCombine() )
				{
						context_text += combine;
				}
				
				if( vicinity_icons_container.CanCombineAmmo() )
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
				else if( iwc.IsItemWithQuantityActive() )
				{
						context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_WITH_QUANTITY );
				}
				
				if( iwc.CanCombine() )
				{
					context_text += combine;
				}
				
				if( iwc.CanCombineAmmo() )
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
				else if( iwca.IsItemWithQuantityActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_WITH_QUANTITY );
				}
				
				if( iwca.CanCombine() )
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
				else if( acc.IsItemWithQuantityActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.VICINITY_CONTAINER_DETAILS_ITEM_WITH_QUANTITY );
				}
				
				if( acc.CanCombine() )
				{
					context_text += combine;
				}
			}
		}
		else if ( m_RightArea.IsActive() )
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
				
				if( player_container.CanCombine() )
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
				else if( iwc1.IsItemWithQuantityActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM_WITH_QUANTITY );
				}
				
				if( iwc1.CanCombine() )
				{
					context_text += combine;
				}
				
				if( iwc1.CanCombineAmmo() )
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
				else if( iwca1.IsItemWithQuantityActive() )
				{
					context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.PLAYER_CARGO_CONTAINER_ITEM_WITH_QUANTITY );
				}
				
				if( iwca1.CanCombine() )
				{
					context_text += combine;
				}
			}
		}
		else if ( m_HandsArea.IsActive() )
		{
			if( m_HandsArea.IsItemActive() )
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
			else if( m_HandsArea.IsItemWithQuantityActive() )
			{
				context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.HANDS_ITEM_WITH_QUANTITY );
			}
			else if( m_HandsArea.IsEmpty() )
			{
				context_text = ConsoleToolbarTypeToString( ConsoleToolbarType.HANDS_ITEM_EMPTY );
			}
		}
		string general_text_left;
		string general_text_right;
		
		#ifdef PLATFORM_XBOX
			if ( m_LeftArea.IsActive() )
			{
				general_text_left	= "<image set=\"xbox_buttons\" name=\"LB\"/> " + "#switch_to_equipment";
				general_text_right	= "#switch_to_hands" + " <image set=\"xbox_buttons\" name=\"RB\"/>";
			}
			else if ( m_RightArea.IsActive() )
			{
				general_text_left	= "<image set=\"xbox_buttons\" name=\"LB\"/> " + "#switch_to_hands";
				general_text_right	= "#switch_to_vicinity" + " <image set=\"xbox_buttons\" name=\"RB\"/>";
			}
			else if ( m_HandsArea.IsActive() )
			{
				general_text_left	= "<image set=\"xbox_buttons\" name=\"LB\"/> " + "#switch_to_vicinity";
				general_text_right	= "#switch_to_equipment" + " <image set=\"xbox_buttons\" name=\"RB\"/>";
			}
		#else
			if ( m_LeftArea.IsActive() )
			{
				general_text_left	= "<image set=\"playstation_buttons\" name=\"L2\"/> " + "#switch_to_equipment";
				general_text_right	= "#switch_to_hands" + " <image set=\"playstation_buttons\" name=\"R2\"/>";
			}
			else if ( m_RightArea.IsActive() )
			{
				general_text_left	= "<image set=\"playstation_buttons\" name=\"L2\"/> " + "#switch_to_hands";
				general_text_right	= "#switch_to_vicinity" + " <image set=\"playstation_buttons\" name=\"R2\"/>";
			}
			else if ( m_HandsArea.IsActive() )
			{
				general_text_left	= "<image set=\"playstation_buttons\" name=\"L2\"/> " + "#switch_to_vicinity";
				general_text_right	= "#switch_to_equipment" + " <image set=\"playstation_buttons\" name=\"R2\"/>";
			}
		#endif
		
		//set toolbar text
		m_TopConsoleToolbarLeft.SetText( general_text_left + " " );
		m_TopConsoleToolbarRight.SetText( general_text_right + " " );
		m_BottomConsoleToolbar.SetText( context_text + " " );
		#endif
	}
}
