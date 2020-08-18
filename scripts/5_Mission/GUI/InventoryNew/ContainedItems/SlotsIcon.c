class SlotsIcon: LayoutHolder
{
	protected bool					m_IsWeapon			= false;
	protected bool					m_IsMagazine		= false;
	protected bool					m_HasTemperature	= false;
	protected bool					m_HasQuantity		= false;
	protected bool					m_HasItemSize		= false;
	protected float					m_CurrQuantity		= -1;
	
	protected EntityAI				m_Obj;
	protected ItemBase				m_Item;
	protected EntityAI				m_SlotParent;
	protected int					m_SlotID;
	protected bool					m_IsDragged;
	
	protected Widget				m_PanelWidget;
	
	protected Widget				m_CursorWidget;
	protected Widget				m_ColWidget;
	protected Widget				m_MountedWidget;
	protected Widget				m_OutOfReachWidget;
	protected Widget				m_ReservedWidget;
	
	protected ItemPreviewWidget		m_ItemPreview;
	protected ImageWidget			m_GhostSlot;
	
	protected Widget				m_ColorWidget;
	protected Widget				m_SelectedPanel;
	
	protected Widget				m_QuantityPanel;
	protected TextWidget			m_QuantityItem;
	protected ProgressBarWidget		m_QuantityProgress;
	protected Widget				m_QuantityStack;
	
	protected Widget				m_ItemSizePanel;
	protected TextWidget			m_ItemSizeWidget;
	
	protected Widget				m_AmmoIcon;
	
	protected Widget				m_RadialIconPanel;
	protected Widget				m_RadialIconClosed;
	protected Widget				m_RadialIcon;
	
	protected bool					m_Reserved;

	void SlotsIcon( LayoutHolder parent, Widget root, int index, EntityAI slot_parent )
	{
		m_MainWidget			= root;
		
		m_PanelWidget			= m_MainWidget.FindAnyWidget( "PanelWidget" + index );
		
		m_CursorWidget			= m_MainWidget.FindAnyWidget( "Cursor" + index );
		m_ColWidget				= m_MainWidget.FindAnyWidget( "Col" + index );
		m_MountedWidget			= m_MainWidget.FindAnyWidget( "Mounted" + index );
		m_OutOfReachWidget		= m_MainWidget.FindAnyWidget( "OutOfReach" + index );

		m_ItemPreview			= ItemPreviewWidget.Cast( m_MainWidget.FindAnyWidget( "Render" + index ) );
		m_ItemPreview.SetForceFlipEnable(true);
		m_ItemPreview.SetForceFlip(false);
		
		m_GhostSlot				= ImageWidget.Cast( m_MainWidget.FindAnyWidget( "GhostSlot" + index ) );
		
		m_ColorWidget			= m_MainWidget.FindAnyWidget( "Color" + index );
		m_SelectedPanel			= m_MainWidget.FindAnyWidget( "Selected" + index );
		
		m_QuantityPanel			= m_MainWidget.FindAnyWidget( "QuantityPanel" + index );
		m_QuantityItem			= TextWidget.Cast( m_MainWidget.FindAnyWidget( "Quantity" + index ) );
		m_QuantityProgress		= ProgressBarWidget.Cast( m_MainWidget.FindAnyWidget( "QuantityBar" + index ) );
		m_QuantityStack			= m_MainWidget.FindAnyWidget( "QuantityStackPanel" + index );
		
		m_ItemSizePanel			= m_MainWidget.FindAnyWidget( "ItemSizePanel" + index );
		m_ItemSizeWidget		= TextWidget.Cast( m_MainWidget.FindAnyWidget( "ItemSize" + index ) );
		
		m_AmmoIcon				= m_MainWidget.FindAnyWidget( "AmmoIcon" + index );
		
		m_RadialIconPanel		= m_MainWidget.FindAnyWidget( "RadialIconPanel" + index );
		m_RadialIconClosed		= m_MainWidget.FindAnyWidget( "RadialIconClosed" + index );
		m_RadialIcon			= m_MainWidget.FindAnyWidget( "RadialIcon" + index );
		
		m_ReservedWidget = Widget.Cast( GetGame().GetWorkspace().CreateWidgets( "gui/layouts/inventory_new/reserved_icon.layout", m_MainWidget ) );
		m_ReservedWidget.Show(false);
		
		WidgetEventHandler.GetInstance().RegisterOnMouseEnter( m_PanelWidget,  this, "MouseEnter" );
		WidgetEventHandler.GetInstance().RegisterOnMouseLeave( m_PanelWidget,  this, "MouseLeave" );
		
		WidgetEventHandler.GetInstance().RegisterOnDrag( m_PanelWidget, this, "OnIconDrag" );
		WidgetEventHandler.GetInstance().RegisterOnDrop( m_PanelWidget, this, "OnIconDrop" );
		
		//WidgetEventHandler.GetInstance().RegisterOnMouseEnter( m_ReservedWidget,  this, "MouseEnter" );
		//WidgetEventHandler.GetInstance().RegisterOnMouseLeave( m_ReservedWidget,  this, "MouseLeave" );
		
		m_Reserved 				= false;
		m_SlotID 				= -1;
		
		m_SlotParent			= slot_parent;
		
		m_PanelWidget.SetUserData(this);
		m_ItemPreview.SetUserData(this);
		m_GhostSlot.SetUserData(this);
		m_MainWidget.SetUserData(this);
		
		SetActive( false );
	}
	
	void ~SlotsIcon()
	{
		if( m_Obj )
		{
			m_Obj.GetOnItemFlipped().Remove( UpdateFlip );
			m_Obj.GetOnViewIndexChanged().Remove( SetItemPreview );
		}
	}
	
	EntityAI GetSlotParent()
	{
		return m_SlotParent;
	}
	
	int GetSlotID()
	{
		return m_SlotID;
	}
	
	void SetSlotID(int slot_ID)
	{
		m_SlotID = slot_ID;
	}
	
	bool IsReserved()
	{
		return m_Reserved;
	}
	
	Widget GetPanelWidget()
	{
		return m_PanelWidget;
	}
	
	Widget GetCursorWidget()
	{
		return m_CursorWidget;
	}
	
	Widget GetColWidget()
	{
		return m_ColWidget;
	}
	
	Widget GetReservedWidget()
	{
		return m_ReservedWidget;
	}
	
	Widget GetMountedWidget()
	{
		return m_MountedWidget;
	}
	
	ItemPreviewWidget GetRender()
	{
		return m_ItemPreview;
	}

	ImageWidget GetGhostSlot()
	{
		return m_GhostSlot;
	}

	Widget GetColorWidget()
	{
		return m_ColorWidget;
	}

	Widget GetSelectedPanel()
	{
		return m_SelectedPanel;
	}

	Widget GetQuantityPanel()
	{
		return m_QuantityPanel;
	}
	
	Widget GetOutOfReachWidget()
	{
		return m_OutOfReachWidget;
	}

	TextWidget GetQuantityItem()
	{
		return m_QuantityItem;
	}
	
	ProgressBarWidget GetQuantityProgress()
	{
		return m_QuantityProgress;
	}
	
	Widget GetQuantityStack()
	{
		return m_QuantityStack;
	}

	Widget GetItemSizePanel()
	{
		return m_ItemSizePanel;
	}
	
	TextWidget GetItemSizeWidget()
	{
		return m_ItemSizeWidget;
	}

	Widget GetAmmoIcon()
	{
		return m_AmmoIcon;
	}

	Widget GetRadialIconPanel()
	{
		return m_RadialIconPanel;
	}

	Widget GetRadialIconClosed()
	{
		return m_RadialIconClosed;
	}

	Widget GetRadialIcon()
	{
		return m_RadialIcon;
	}

	override void SetActive( bool active )
	{
		if( active && GetObject() )
		{
			float x, y;
			GetMainWidget().GetScreenPos( x, y );
			ItemManager.GetInstance().PrepareTooltip( EntityAI.Cast( GetObject() ), x, y );
		}
		
		m_SelectedPanel.Show( active );
	}
	
	override void SetLayoutName()
	{
		m_LayoutName = "";
	}

	override void Refresh()
	{
		if( m_HasTemperature )
			SetTemperature();
		if( m_IsWeapon )
			RefreshMuzzleIcon();
		if( m_HasQuantity )
			SetQuantity();
	}

	void SetTemperature()
	{
		ItemManager.GetInstance().SetIconTemperature( EntityAI.Cast( m_Obj ), m_MainWidget );
	}

	Object GetObject()
	{
		return m_Obj;
	}
	
	EntityAI GetEntity()
	{
		return EntityAI.Cast( m_Obj );
	}
	
	ItemBase GetItem()
	{
		return m_Item;
	}
	
	void RefreshMuzzleIcon()
	{
		Weapon_Base wpn = Weapon_Base.Cast( GetObject() );
		if( wpn )
		{
			if( wpn.IsShowingChamberedBullet() )
			{
				int mi = wpn.GetCurrentMuzzle();
				m_AmmoIcon.Show( wpn.IsChamberFull( mi ) );
				
			}
			else
			{
				m_AmmoIcon.Show( false );
			}
		}
	}
	
	float GetQuantity()
	{
		if( m_Item )
		{
			if( m_IsMagazine )
			{
				return Magazine.Cast( m_Item ).GetAmmoCount();
			}
			else
			{
				return m_Item.GetQuantity();
			}
		}
		return -1;
	}

	void SetQuantity()
	{
		if( m_Item && m_CurrQuantity != GetQuantity() )
		{
			m_CurrQuantity = GetQuantity();
			int has_quantity = QuantityConversions.HasItemQuantity( m_Item );
			
			if( has_quantity == QUANTITY_COUNT )
			{
				string q_text = QuantityConversions.GetItemQuantityText( m_Item , true);
				if( q_text == "" )
				{
					m_QuantityStack.Show( false );
					m_QuantityProgress.Show( false );
				}
				else
				{
					m_QuantityItem.SetText( q_text );
					m_QuantityStack.Show( true );
					m_QuantityProgress.Show( false );
				}

			}
			else if( has_quantity == QUANTITY_PROGRESS )
			{

				float progress_max = m_QuantityProgress.GetMax();
				int max = m_Item.ConfigGetInt( "varQuantityMax" );
				int count = m_Item.ConfigGetInt( "count" );
				float quantity = QuantityConversions.GetItemQuantity( m_Item );

				if( count > 0 )
				{
					max = count;
				}
				if( max > 0 )
				{

					float value = Math.Round( ( quantity / max ) * 100 );
					m_QuantityProgress.SetCurrent( value );
				}
				m_QuantityStack.Show( false );
				m_QuantityProgress.Show( true );
			}
		}
	}
	
	void SetItemPreview()
	{
		m_ItemPreview.Show( true );
		m_ItemPreview.SetItem( EntityAI.Cast( m_Obj ) );
		m_ItemPreview.SetModelOrientation( "0 0 0" );
		m_ItemPreview.SetView( m_Obj.GetViewIndex() );
	}
	
	void SetItemSize()
	{
		if( m_HasItemSize )
		{
			int size_x, size_y;
			GetGame().GetInventoryItemSize( InventoryItem.Cast( m_Obj ), size_x, size_y );
			
			m_ItemSizePanel.Show( true );
			m_ItemSizeWidget.SetText( ( size_x * size_y ).ToString() );
		}
	}
	
	void UpdateFlip( bool flipped )
	{
		if( !m_Reserved )
		{
			float x_content, y_content;
			GetPanelWidget().GetScreenSize( x_content, y_content );
			GetPanelWidget().SetSize( y_content, x_content );
		}
	}

	void Init( EntityAI obj, bool reservation = false )
	{
		if( m_Obj != obj )
		{
			Clear();
			m_Obj	= obj;
			m_Item	= ItemBase.Cast( m_Obj );
			m_Obj.GetOnItemFlipped().Insert( UpdateFlip );
			m_Obj.GetOnViewIndexChanged().Insert( SetItemPreview );
			m_Reserved = reservation;
			
			if(reservation)
			{
				ItemManager.GetInstance().SetWidgetDraggable( m_PanelWidget, false );
				
				m_IsWeapon = false;
				m_IsMagazine = false;
				m_HasTemperature = false;
				m_HasQuantity = false;
				m_HasItemSize = false;
			}
			else
			{
				CheckIsWeapon();
				CheckIsMagazine();
				CheckHasTemperature();
				CheckHasQuantity();
				CheckHasItemSize();
			}

			m_ReservedWidget.Show(reservation);

			SetItemPreview();
			
			m_GhostSlot.Show( false );
			m_PanelWidget.Show( true );
			
			Refresh();
		}
	}
	
	void Clear()
	{
		if (m_IsDragged)
		{
			m_IsDragged = false;
			ItemManager.GetInstance().HideDropzones();
			ItemManager.GetInstance().SetIsDragging( false );
			m_PanelWidget.ClearFlags( WidgetFlags.EXACTSIZE );
			m_PanelWidget.SetSize( 1, 1 );
			m_ColWidget.Show( false );
			m_SelectedPanel.Show( false );
			m_SelectedPanel.SetColor( ARGBF( 1, 1, 1, 1 ) );
			m_ItemPreview.SetForceFlipEnable(true);
			Widget a = CancelWidgetDragging();
			ItemManager.GetInstance().SetWidgetDraggable( a, false );
		}
		if( m_Obj )
		{
			m_Obj.GetOnItemFlipped().Remove( UpdateFlip );
			m_Obj.GetOnViewIndexChanged().Remove( SetItemPreview );
		}
			
		m_Obj = null;
		m_Item = null;
		
		m_ItemPreview.Show( false );
		m_ItemPreview.SetItem( null );
		
		m_CurrQuantity = -1;
		m_IsWeapon = false;
		m_IsMagazine = false;
		m_HasTemperature = false;
		m_HasQuantity = false;
		m_HasItemSize = false;
		
		m_GhostSlot.Show( true );
		m_AmmoIcon.Show( false );
		m_PanelWidget.Show( false );
		m_RadialIconPanel.Show( false );
		
		m_QuantityPanel.Show( false );
		if(GetSlotID() != -1)
		{
			int stack_max = InventorySlots.GetStackMaxForSlotId( GetSlotID() );
			if(stack_max > 1)
			{
				m_QuantityPanel.Show( true );
				m_QuantityItem.SetText( string.Format("0/%1", stack_max.ToString()) );
				m_QuantityStack.Show( true );
				m_QuantityProgress.Show( false );
				m_PanelWidget.Show( true );
				m_ItemPreview.Show( true );
			}
		}
		
		m_ColWidget.Show( false );
		m_SelectedPanel.Show( false );
		m_MountedWidget.Show( false );
		m_OutOfReachWidget.Show( false );
		m_ReservedWidget.Show( false );
		
		if( m_ItemSizePanel )
			m_ItemSizePanel.Show( false );
		
		if( m_ColorWidget )
			m_ColorWidget.Show( false );
		
		Refresh();
	}
	
	void CheckIsWeapon()
	{
		m_IsWeapon = ( Weapon_Base.Cast( m_Obj ) != null );
	}
	
	void CheckIsMagazine()
	{
		m_IsMagazine = ( Magazine.Cast( m_Obj ) != null );
	}
	
	void CheckHasTemperature()
	{
		if( m_Item )
		{
			m_HasTemperature = ( m_Item.GetTemperatureMax() != 0 && m_Item.GetTemperatureMin() != 0 );
		}
	}
	
	void CheckHasQuantity()
	{
		if( m_Item )
		{
			m_HasQuantity = ( QuantityConversions.HasItemQuantity( m_Item ) != QUANTITY_HIDDEN );
			if( m_HasQuantity )
			{
				m_QuantityPanel.Show( true );
			}
		}
	}
	
	void CheckHasItemSize()
	{
		#ifdef PLATFORM_CONSOLE
		string config = "CfgVehicles " + m_Obj.GetType() + " GUIInventoryAttachmentsProps";
		m_HasItemSize = ( InventoryItem.Cast( m_Obj ) && !GetGame().ConfigIsExisting( config ) );
		#else
		m_HasItemSize = false;
		#endif
	}
	
	bool IsOutOfReach()
	{
		bool oot = ( m_OutOfReachWidget.IsVisible() || m_MountedWidget.IsVisible() );
		//Print( "WAT " + oot );
		return oot;
	}
	
	bool MouseEnter(Widget w, int x, int y)
	{
		if( m_Reserved )
			return true;
		
		ItemManager.GetInstance().PrepareTooltip( m_Item, x, y );
		if( GetDragWidget() != m_PanelWidget && !IsOutOfReach() )
		{
			m_SelectedPanel.Show( true );
		}
		return true;
	}

	bool MouseLeave( Widget w, Widget s, int x, int y	)
	{
		if( m_Reserved )
			return true;
		
		ItemManager.GetInstance().HideTooltip();
		if( GetDragWidget() != m_PanelWidget )
		{
			m_SelectedPanel.Show( false );
		}
		return true;
	}
	
	override void UpdateInterval()
	{
		if( m_Item )
		{
			if( m_HasTemperature )
				SetTemperature();
			if( m_IsWeapon )
				RefreshMuzzleIcon();
			if( m_HasQuantity )
				SetQuantity();
			if( m_HasItemSize )
				SetItemSize();
		}
	}
	
	void OnIconDrag( Widget w )
	{
		if(!m_Obj || !w)
		{
			return;
		}
		ItemManager.GetInstance().HideDropzones();
		if( m_Obj.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
		{
			ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
		}
		else
		{
			ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
		}

		ItemManager.GetInstance().SetIsDragging( true );
		int icon_x, icon_y;
		float icon_size, y;
		int m_sizeX, m_sizeY;

		if( m_Item )
		{
			GetGame().GetInventoryItemSize( m_Item, icon_x, icon_y );
			
			CargoContainer c_parent = CargoContainer.Cast( m_Parent );
			HandsPreview h_parent = HandsPreview.Cast( m_Parent );

			if( GetRoot().m_MainWidget.FindAnyWidget( "HandsPanel" ) )
			{
				GetRoot().m_MainWidget.FindAnyWidget( "HandsPanel" ).GetScreenSize( icon_size, y );
			}
			
			icon_size = icon_size / 10;
			
			w.SetFlags( WidgetFlags.EXACTSIZE );
			m_ItemPreview.SetForceFlipEnable(false);
			
			if( !m_Item.GetInventory().GetFlipCargo() )
			{
				w.SetSize( icon_x * icon_size , icon_y * icon_size );
			}
			else
			{
				w.SetSize( icon_y * icon_size , icon_x * icon_size );
			}
		
			m_ColWidget.Show( true );
			m_SelectedPanel.Show( true );
			
			m_RadialIcon.Show( false );
			
			ItemManager.GetInstance().SetDraggedItem( m_Item );
		}
		m_IsDragged = true;
	}
	
	void OnIconDrop( Widget w )
	{
		m_IsDragged = false;
		ItemManager.GetInstance().HideDropzones();
		ItemManager.GetInstance().SetIsDragging( false );
		w.ClearFlags( WidgetFlags.EXACTSIZE );
		w.SetSize( 1, 1 );
		m_ColWidget.Show( false );
		m_SelectedPanel.Show( false );
		m_SelectedPanel.SetColor( ARGBF( 1, 1, 1, 1 ) );
		m_ItemPreview.SetForceFlipEnable(true);
	}
	
}