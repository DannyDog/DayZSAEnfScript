class ContainerWithCargoAndAttachments extends ClosableContainer
{
	protected ref Attachments								m_Atts;
	protected ref CargoContainer							m_CargoGrid;
	
	protected ref map<EntityAI, ref CargoContainer>			m_AttachmentCargos;
	protected ref map<EntityAI, ref AttachmentsWrapper>		m_AttachmentAttachmentsContainers;
	protected ref map<EntityAI, ref Attachments>			m_AttachmentAttachments;
	protected ref array<int>								m_AttachmentSlotsSorted;
	
	void ContainerWithCargoAndAttachments( LayoutHolder parent, int sort = -1 )
	{
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( m_MainWidget,  this, "DraggingOverHeader2" );
	}

	void ~ContainerWithCargoAndAttachments()
	{
		if( m_Entity )
		{
			m_Entity.GetOnItemAttached().Remove( AttachmentAdded );
			m_Entity.GetOnItemDetached().Remove( AttachmentRemoved );
		}
		
		if( m_Atts )
			delete m_Atts;
		
		foreach( EntityAI e, Attachments att : m_AttachmentAttachments )
		{
			delete att;
		}
		
		if( m_AttachmentAttachments )
			m_AttachmentAttachments.Clear();
		if( m_AttachmentAttachmentsContainers )
			m_AttachmentAttachmentsContainers.Clear();
		if( m_AttachmentCargos )
			m_AttachmentCargos.Clear();
	}
	
	void AttachmentAdded(EntityAI item, string slot, EntityAI parent)
	{
		int slot_id = InventorySlots.GetSlotIdFromString( slot );
		int att_mod = 1;
		if( item.GetInventory().GetCargo() )
		{
			ref CargoContainer cont = new CargoContainer( this, true );
			cont.GetRootWidget().SetSort( m_AttachmentSlotsSorted.Find( slot_id ) + m_AttachmentCargos.Count() + 1 );
			cont.SetEntity( item );
			Insert( cont, m_Atts.GetAttachmentHeight() + m_AttachmentCargos.Count() + 1 );
			
			m_AttachmentCargos.Insert( item, cont );
			att_mod += m_AttachmentSlotsSorted.Find( slot_id ) + m_AttachmentCargos.Count() + 1;
			RecomputeOpenedContainers();
			if( m_Parent )
				m_Parent.Refresh();
			Inventory.GetInstance().UpdateConsoleToolbar();
		}
		
		if( item.GetInventory().GetAttachmentSlotsCount() > 0  )
		{
			ref Attachments att_cont = new Attachments( this, item );
			att_cont.InitAttachmentGrid( m_AttachmentSlotsSorted.Find( slot_id ) + m_Atts.GetAttachmentHeight() + att_mod );
			
			m_AttachmentAttachments.Insert( item, att_cont );
			m_AttachmentAttachmentsContainers.Insert( item, att_cont.GetWrapper() );
			
			att_cont.UpdateInterval();
			RecomputeOpenedContainers();
			if( m_Parent )
				m_Parent.Refresh();
			Inventory.GetInstance().UpdateConsoleToolbar();
		}
	}
	
	void AttachmentRemoved(EntityAI item, string slot, EntityAI parent)
	{
		int slot_id = InventorySlots.GetSlotIdFromString( slot );
		
		CargoContainer old_cont = m_AttachmentCargos.Get( item );
		if( old_cont )
		{
			m_Body.RemoveItem( old_cont );
			m_AttachmentCargos.Remove( item );
			RecomputeOpenedContainers();
			if( m_Parent )
				m_Parent.Refresh();
			Inventory.GetInstance().UpdateConsoleToolbar();
		}
				
		
		AttachmentsWrapper old_att_cont = m_AttachmentAttachmentsContainers.Get( item );
		if( old_att_cont )
		{
			m_Body.RemoveItem( old_att_cont );
			m_AttachmentAttachmentsContainers.Remove( item );
			m_AttachmentAttachments.Remove( item );
			delete old_att_cont;
			RecomputeOpenedContainers();
			if( m_Parent )
				m_Parent.Refresh();
			Inventory.GetInstance().UpdateConsoleToolbar();
		}
	}
	
	override void UpdateInterval()
	{
		int i;
		if( m_Entity )
		{
			for( i = 0; i < m_AttachmentCargos.Count(); i++ )
			{
				m_AttachmentCargos.GetElement( i ).UpdateInterval();
			}
			
			if( m_Entity.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ) || m_Closed )
			{
				HideContent();
			}
			else
			{
				ShowContent();
			}
			
			if( m_Atts )
			{
				m_Atts.UpdateInterval();
			}
			
			if( m_CargoGrid )
			{
				m_CargoGrid.UpdateInterval();
			}
		}
	}
	
	override EntityAI GetFocusedContainerEntity()
	{
		return m_Entity;
	}
	
	override Container GetFocusedContainer()
	{
		int index = m_ActiveIndex - 1;
		int attachment_start_index = -1;
		int cargo_start_index = -1;
		int attachment_end_index = -1;
		int cargo_end_index = -1;
		
		if( m_Atts || m_AttachmentAttachments.Count() > 0 )
		{
			attachment_start_index = 0;
			if( m_Atts )
				attachment_end_index++;
			attachment_end_index += m_AttachmentAttachments.Count();
		}
		
		if( m_CargoGrid || m_AttachmentCargos.Count() > 0 )
		{
			cargo_start_index = attachment_end_index + 1;
			if( m_CargoGrid )
				cargo_end_index++;
			cargo_end_index += cargo_start_index + m_AttachmentCargos.Count();
		}
		
		if( index.InRange( 0, attachment_end_index ) )
		{
			if( m_Atts )
			{
				if( index == 0 )
				{
					return m_Atts.GetWrapper();
				}
				else
				{
					return m_AttachmentAttachments.GetElement( index - 1 ).GetWrapper();
				}
			}
			else
			{
				return m_AttachmentAttachments.GetElement( index ).GetWrapper();
			}
		}
		else if( index.InRange( cargo_start_index, cargo_end_index ) )
		{
			if( m_CargoGrid )
			{
				if( index == cargo_start_index )
				{
					return m_CargoGrid;
				}
				else
				{
					return m_AttachmentCargos.GetElement( index - 1 - cargo_start_index );
				}
			}
			else
			{
				return m_AttachmentCargos.GetElement( index - cargo_start_index );
			}
		}
		
		return null;
	}
	
	override void SetActive( bool active )
	{
		super.SetActive( active );
		UnfocusAll();
		
		if( GetFocusedContainer() )
			GetFocusedContainer().SetActive( active );
		if( active )
			SetFocusToIndex( true );
		Inventory.GetInstance().UpdateConsoleToolbar();
	}
	
	override void SetLastActive()
	{
		if( GetFocusedContainer() )
		{
			GetFocusedContainer().UnfocusAll();
		}
		
		Container old = GetFocusedContainer();
		m_ActiveIndex = m_Body.Count() - 1;
		if( old != GetFocusedContainer() )
			old.SetActive( false );
		
		SetFocusToIndex( true, true );
		Inventory.GetInstance().UpdateConsoleToolbar();
	}
	
	void EquipmentMoveUp()
	{
		PlayerContainer pc = PlayerContainer.Cast( m_Parent );
		if( pc )
		{
			pc.MoveContainerUp( this );
		}
	}
	
	void EquipmentMoveDown()
	{
		PlayerContainer pc = PlayerContainer.Cast( m_Parent );
		if( pc )
		{
			pc.MoveContainerDown( this );
		}
	}

	void SetDefaultFocus()
	{
		UnfocusAll();
		if( m_Atts )
		{
			m_Atts.SetDefaultFocus();
		}
		else if( m_CargoGrid )
		{
			m_CargoGrid.SetDefaultFocus();
		}
		else if( m_AttachmentAttachments.Count() > 0 )
		{
			m_AttachmentAttachments.GetElement( 0 ).SetDefaultFocus();
		}
		else if( m_AttachmentCargos.Count() > 0 )
		{
			m_AttachmentCargos.GetElement( 0 ).SetDefaultFocus();
		}
	}

	override void UnfocusAll()
	{
		if( m_Atts )
		{
			m_Atts.UnfocusAll();
		}
			
		if( m_CargoGrid )
		{
			m_CargoGrid.UnfocusAll();
		}
		
		foreach( EntityAI e1, CargoContainer cargo : m_AttachmentCargos )
		{
			cargo.UnfocusAll();
				
		}
		
		foreach( EntityAI e2, Attachments att : m_AttachmentAttachments )
		{
			att.UnfocusAll();
		}
	}
	
	override bool IsLastIndex()
	{
		return m_ActiveIndex == ( m_Body.Count() - 1 );
	}
	
	override bool IsFirstContainerFocused()
	{
		return IsFirstIndex();
	}
	
	override bool IsLastContainerFocused()
	{
		return IsLastIndex();
	}

	override void MoveGridCursor( int direction )
	{
		int index = m_ActiveIndex - 1;
		int attachment_start_index = -1;
		int cargo_start_index = -1;
		int attachment_end_index = -1;
		int cargo_end_index = -1;
		
		if( m_Atts || m_AttachmentAttachments.Count() > 0 )
		{
			attachment_start_index = 0;
			if( m_Atts )
				attachment_end_index++;
			attachment_end_index += m_AttachmentAttachments.Count();
		}
		
		if( m_CargoGrid || m_AttachmentCargos.Count() > 0 )
		{
			cargo_start_index = attachment_end_index + 1;
			if( m_CargoGrid )
				cargo_end_index++;
			cargo_end_index += cargo_start_index + m_AttachmentCargos.Count();
		}
		
		if( index.InRange( 0, attachment_end_index ) )
		{
			if( m_Atts )
			{
				if( index == 0 )
				{
					m_Atts.MoveGridCursor( direction );
				}
				else
				{
					m_AttachmentAttachments.GetElement( index - 1 ).MoveGridCursor( direction );
				}
			}
			else
			{
				m_AttachmentAttachments.GetElement( index ).MoveGridCursor( direction );
			}
		}
		else if( index.InRange( cargo_start_index, cargo_end_index ) )
		{
			if( m_CargoGrid )
			{
				if( index == cargo_start_index )
				{
					m_CargoGrid.MoveGridCursor( direction );
				}
				else
				{
					m_AttachmentCargos.GetElement( index - 1 - cargo_start_index ).MoveGridCursor( direction );
				}
			}
			else
			{
				m_AttachmentCargos.GetElement( index - cargo_start_index ).MoveGridCursor( direction );
			}
		}
		Inventory.GetInstance().UpdateConsoleToolbar();
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
			if( GetFocusedContainer() )
				GetFocusedContainer().SetActive( false );
			SetFocusToIndex( false );
			m_ActiveIndex++;
			if( GetFocusedContainer() )
				GetFocusedContainer().SetActive( true );
			SetFocusToIndex( true );
		}
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
			if( GetFocusedContainer() )
				GetFocusedContainer().SetActive( false );
			SetFocusToIndex( false );
			m_ActiveIndex--;
			if( GetFocusedContainer() )
				GetFocusedContainer().SetActive( true );
			SetFocusToIndex( true );
		}
	}
	
	void SetFocusToIndex( bool focus, bool last = false )
	{
		int index = m_ActiveIndex - 1;
		int attachment_start_index = -1;
		int cargo_start_index = -1;
		int attachment_end_index = -1;
		int cargo_end_index = -1;
		
		if( m_Atts || m_AttachmentAttachments.Count() > 0 )
		{
			attachment_start_index = 0;
			if( m_Atts )
				attachment_end_index++;
			attachment_end_index += m_AttachmentAttachments.Count();
		}
		
		if( m_CargoGrid || m_AttachmentCargos.Count() > 0 )
		{
			cargo_start_index = attachment_end_index + 1;
			if( m_CargoGrid )
				cargo_end_index++;
			cargo_end_index += cargo_start_index + m_AttachmentCargos.Count();
		}
		
		if( index.InRange( 0, attachment_end_index ) )
		{
			if( m_Atts )
			{
				if( index == 0 )
				{
					if( focus )
					{
						m_Atts.SetActive(true);
						if( last )
							m_Atts.SetLastActive();
						else
							m_Atts.SetDefaultFocus();
					}
					else
					{
						m_Atts.UnfocusAll();
						m_Atts.SetActive(false);
					}
				}
				else
				{
					if( focus )
					{
						m_AttachmentAttachments.GetElement( index - 1 ).SetActive(true);
						if( last )
							m_AttachmentAttachments.GetElement( index - 1 ).SetLastActive();
						else
							m_AttachmentAttachments.GetElement( index - 1 ).SetDefaultFocus();
					}
					else
					{
						m_AttachmentAttachments.GetElement( index - 1 ).UnfocusAll();
						m_AttachmentAttachments.GetElement( index - 1 ).SetActive(false);
					}
					
				}
			}
			else
			{
				if( focus )
				{
					m_AttachmentAttachments.GetElement( index ).SetActive(true);
					if( last )
						m_AttachmentAttachments.GetElement( index ).SetLastActive();
					else
						m_AttachmentAttachments.GetElement( index ).SetDefaultFocus();
				}
				else
				{
					m_AttachmentAttachments.GetElement( index ).UnfocusAll();
					m_AttachmentAttachments.GetElement( index ).SetActive(false);
				}
			}
		}
		else if( index.InRange( cargo_start_index, cargo_end_index ) )
		{
			if( m_CargoGrid )
			{
				if( index == cargo_start_index )
				{
					if( focus )
					{
						m_CargoGrid.SetActive(true);
						if( last )
							m_CargoGrid.SetLastActive();
						else
							m_CargoGrid.SetDefaultFocus();
					}
					else
					{
						m_CargoGrid.UnfocusAll();
						m_CargoGrid.SetActive(false);
					}	
				}
				else
				{
					if( focus )
					{
						m_AttachmentCargos.GetElement( index - 1 - cargo_start_index ).SetActive(true);
						if( last )
							m_AttachmentCargos.GetElement( index - 1 - cargo_start_index ).SetLastActive();
						else
							m_AttachmentCargos.GetElement( index - 1 - cargo_start_index ).SetDefaultFocus();
					}
					else
					{
						m_AttachmentCargos.GetElement( index - 1 - cargo_start_index ).UnfocusAll();
						m_AttachmentCargos.GetElement( index - 1 - cargo_start_index ).SetActive(false);
					}
				}
			}
			else
			{
				if( focus )
				{
					m_AttachmentCargos.GetElement( index - cargo_start_index ).SetActive(true);
					if( last )
						m_AttachmentCargos.GetElement( index - cargo_start_index ).SetLastActive();
					else
						m_AttachmentCargos.GetElement( index - cargo_start_index ).SetDefaultFocus();
				}
				else
				{
					m_AttachmentCargos.GetElement( index - cargo_start_index ).UnfocusAll();
					m_AttachmentCargos.GetElement( index - cargo_start_index ).SetActive(false);
				}
			}
		}
		Inventory.GetInstance().UpdateConsoleToolbar();
	}

	void SetEntity( EntityAI entity )
	{
		m_Entity = entity;
		
		m_Atts = new Attachments( this, entity );
		m_Atts.InitAttachmentGrid( 1 );
		m_AttachmentSlotsSorted = m_Atts.GetSlotsSorted();
		
		m_Entity.GetOnItemAttached().Insert( AttachmentAdded );
		m_Entity.GetOnItemDetached().Insert( AttachmentRemoved );
		
		m_ClosableHeader.SetItemPreview( entity );
		
		if( entity.GetInventory().GetCargo() )
		{
			m_CargoGrid = new CargoContainer( this );
			m_CargoGrid.GetRootWidget().SetSort( 2 );
			m_CargoGrid.SetEntity( entity );
			m_CargoGrid.UpdateHeaderText();
			this.Insert( m_CargoGrid );
		}
		else
		{
			string name = m_Entity.GetDisplayName();
			name.ToUpper();
			m_ClosableHeader.SetName( name );
		}

		m_AttachmentCargos					= new map<EntityAI, ref CargoContainer>;
		m_AttachmentAttachmentsContainers	= new map<EntityAI, ref AttachmentsWrapper>;
		m_AttachmentAttachments				= new map<EntityAI, ref Attachments>;
		
		( Container.Cast( m_Parent ) ).Insert( this );
		
		foreach( int slot_id : m_AttachmentSlotsSorted )
		{
			EntityAI item = m_Entity.GetInventory().FindAttachment( slot_id );
			if( item )
				AttachmentAdded( item, InventorySlots.GetSlotName( slot_id ), m_Entity );
		}
		
		if( m_Entity.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ) || m_Closed )
		{
			HideContent();
		}
		else
		{
			ShowContent();
		}
		SetOpenState( ItemManager.GetInstance().GetDefaultOpenState( m_Entity.GetType() ) );
		m_Parent.m_Parent.Refresh();
		
		RecomputeOpenedContainers();
	}

	EntityAI GetEntity()
	{
		return m_Entity;
	}

	ItemPreviewWidget GetItemPreviewWidgetDragOrDrop( Widget w )
	{
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		return ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
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
			return NULL;
		}
		return ipw.GetItem();
	}

	Widget GetItemPreviewWidget( Widget w )
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
		return ipw;
	}

	void MouseClick2( Widget w, int x, int y, int button )
	{
		SlotsIcon slots_icon;
		w.GetUserData(slots_icon);
		
		EntityAI item = null;
		if(slots_icon)
			item = slots_icon.GetEntity();
		
		ItemBase itemAtPos = ItemBase.Cast( item );
		
		if( item )
		{
			bool reserved = false;
		
			reserved = slots_icon.IsReserved();
		
			if ( button == MouseState.RIGHT )
			{
				if( reserved )
				{
					EntityAI att_parent = slots_icon.GetSlotParent();
					GetGame().GetPlayer().GetHumanInventory().ClearUserReservedLocation( item );
					att_parent.GetOnAttachmentReleaseLock().Invoke(item, slots_icon.GetSlotID());
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
					PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
					if ( g_Game.IsLeftCtrlDown() )
					{
						if( itemAtPos && itemAtPos.GetInventory().CanRemoveEntity() )
						{
							if( itemAtPos.GetTargetQuantityMax() < itemAtPos.GetQuantity() )
								itemAtPos.SplitIntoStackMaxClient( player, -1 );
							else
								player.PredictiveTakeEntityToInventory( FindInventoryLocationType.ANY, itemAtPos );
						}
					}
					else
					{
						bool draggable = !player.GetInventory().HasInventoryReservation( item, null ) && !player.GetInventory().IsInventoryLocked() && item.GetInventory().CanRemoveEntity() && !player.IsItemsToDelete();
						ItemManager.GetInstance().SetWidgetDraggable( w, draggable );
					}
				}
			}
		}
	}
	
	/*void DraggingOverHeader2(Widget w, int x, int y, Widget receiver )
	{
		DraggingOverHeader(w, x, y, receiver );
	}*/

	void DropReceived( Widget w, int x, int y, CargoContainer cargo )
	{
		EntityAI item = GetItemPreviewItem( w );
		if( !item )
		{
			return;
		}

		int idx = 0;
		int c_x, c_y;
		
		EntityAI target_entity;
		CargoBase target_cargo;
		
		if( cargo == m_CargoGrid )
		{
			target_entity	= m_Entity;
			target_cargo 	= m_Entity.GetInventory().GetCargo();
			#ifdef PLATFORM_CONSOLE
			if( m_CargoGrid.HasItem( item ) )
			{
				return;
			}
			#endif
		}
		else
		{
			target_entity	= m_AttachmentCargos.GetKeyByValue( cargo );
			if( target_entity )
			{
				target_cargo 	= target_entity.GetInventory().GetCargo();
				#ifdef PLATFORM_CONSOLE
				if( cargo.HasItem( item ) )
				{
					return;
				}
				#endif
			}
			else
				return;
		}
		
		if( target_cargo && target_entity )
		{
			c_x = target_cargo.GetHeight();
			c_y = target_cargo.GetWidth();
		}
		else
			return;
		
		InventoryLocation dst = new InventoryLocation;
		#ifdef PLATFORM_CONSOLE
		x = 0;
		y = target_cargo.GetItemCount();
		target_entity.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.CARGO, dst );
		#else
		dst.SetCargoAuto(target_cargo, item, x, y, item.GetInventory().GetFlipCargo());
		#endif
		
		InventoryLocation src = new InventoryLocation;
		item.GetInventory().GetCurrentInventoryLocation(src);
		if(src.CompareLocationOnly(dst))
			return;
		
		#ifdef PLATFORM_CONSOLE
		if(dst.IsValid() && target_entity.GetInventory().LocationCanAddEntity(dst))
		#else
		if( c_x > x && c_y > y && target_entity.GetInventory().LocationCanAddEntity(dst))
		#endif
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );

			SplitItemUtils.TakeOrSplitToInventoryLocation( player, dst );
			
			Icon icon = cargo.GetIcon( item );
			
			if( icon )
			{
				if( w && w.FindAnyWidget("Selected") )
					w.FindAnyWidget("Selected").SetColor( ColorManager.BASE_COLOR );
				icon.Refresh();
				Refresh();
			}
		}
		
		ItemManager.GetInstance().HideDropzones();
		ItemManager.GetInstance().SetIsDragging( false );
	}
	
	void TakeAsAttachment( Widget w, Widget receiver )
	{
		ItemManager.GetInstance().HideDropzones();
		ItemManager.GetInstance().SetIsDragging( false );
		SlotsIcon slots_icon;
		EntityAI receiver_item;
		int slot_id = -1;
		bool is_reserved = false;
		EntityAI attached_entity;
		receiver.GetUserData(slots_icon);
		//string name = receiver.GetName();
		//name.Replace("PanelWidget", "Render");
		
		//ItemPreviewWidget receiver_iw = ItemPreviewWidget.Cast( receiver.FindAnyWidget(name) );
		if( slots_icon )
		{
			receiver_item	= slots_icon.GetEntity();
			slot_id			= slots_icon.GetSlotID();
			attached_entity = slots_icon.GetSlotParent();
			is_reserved		= slots_icon.IsReserved();
		}
		
		EntityAI item = GetItemPreviewItem( w );
		if( !item )
		{
			return;
		}
		ItemBase item_base	= ItemBase.Cast( item );
		InventoryLocation il = new InventoryLocation;
		float stackable;
		
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if( !item.GetInventory().CanRemoveEntity() || !player.CanManipulateInventory() )
			return;
		
		EntityAI target_att_entity = m_Entity;
		Weapon_Base wpn;
		Magazine mag;
		if( Class.CastTo(wpn,  m_Entity ) && Class.CastTo(mag,  item ) )
		{
			if( player.GetWeaponManager().CanAttachMagazine( wpn, mag ) )
			{
				player.GetWeaponManager().AttachMagazine( mag );
			}
		}
		else if( receiver_item && !is_reserved )
		{
			if( ( ItemBase.Cast( receiver_item ) ).CanBeCombined( ItemBase.Cast( item ) ) )
			{
				( ItemBase.Cast( receiver_item ) ).CombineItemsClient( ItemBase.Cast( item ) );
			}
			else if( GameInventory.CanSwapEntitiesEx( receiver_item, item ) )
			{
				if( !receiver_item.GetInventory().CanRemoveEntity() )
					return;
				GetGame().GetPlayer().PredictiveSwapEntities( receiver_item, item );
			}
			else if( receiver_item.GetInventory().CanAddAttachment( item ) )
			{
				player.PredictiveTakeEntityToTargetAttachment(receiver_item, item);
			}
		}
		else if( attached_entity && attached_entity.GetInventory().CanAddAttachmentEx( item, slot_id ) )
		{
			stackable = item_base.GetTargetQuantityMax(slot_id);
			if( stackable == 0 || stackable >= item_base.GetQuantity() )
			{
				player.PredictiveTakeEntityToTargetAttachmentEx(attached_entity, item, slot_id);
			}
			else if( stackable != 0 && stackable < item_base.GetQuantity() )
			{
				item_base.SplitIntoStackMaxClient( attached_entity, slot_id );
			}
		}
		else if(attached_entity && attached_entity.GetInventory().FindFreeLocationFor(item,FindInventoryLocationType.ATTACHMENT,il))
		{
			stackable = item_base.GetTargetQuantityMax(il.GetSlot());
			if( stackable == 0 || stackable >= item_base.GetQuantity() )
			{
				player.PredictiveTakeEntityToTargetAttachmentEx(attached_entity, item, il.GetSlot());
			}
			else if( stackable != 0 && stackable < item_base.GetQuantity() )
			{
				item_base.SplitIntoStackMaxClient( attached_entity, il.GetSlot() );
			}
		}
		else if( m_Entity.GetInventory().FindFreeLocationFor(item,FindInventoryLocationType.ATTACHMENT,il) )
		{
			stackable = item_base.GetTargetQuantityMax(il.GetSlot());
			if( stackable == 0 || stackable >= item_base.GetQuantity() )
			{
				player.PredictiveTakeEntityToTargetAttachmentEx(m_Entity, item, il.GetSlot());
			}
			else if( stackable != 0 && stackable < item_base.GetQuantity() )
			{
				item_base.SplitIntoStackMaxClient( m_Entity, il.GetSlot() );
			}
		}
		else if( ( m_Entity.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() ) && ( !player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item )) ) || player.GetHumanInventory().HasEntityInHands( item ) )
		{
			SplitItemUtils.TakeOrSplitToInventory( PlayerBase.Cast( GetGame().GetPlayer() ), m_Entity, item );
		}
		/*else if( !player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item ) )
		{
			SplitItemUtils.TakeOrSplitToInventory( PlayerBase.Cast( GetGame().GetPlayer() ), m_Entity, item );
		}*/
	}

	override void OnDropReceivedFromHeader( Widget w, int x, int y, Widget receiver )
	{
		TakeAsAttachment( w, receiver );
	}

	void OnDropReceivedFromHeader2( Widget w, int x, int y, Widget receiver )
	{
		TakeAsAttachment( w, receiver );
	}

	void DoubleClick(Widget w, int x, int y, int button)
	{
		if( button == MouseState.LEFT )
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			if( w == NULL || player.GetInventory().IsInventoryLocked() )
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
			
			EntityAI item = iw.GetItem();
			
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
			
			if( !item.GetInventory().CanRemoveEntity() || !player.CanManipulateInventory() )
				return;
			
			if( player.GetInventory().HasEntityInInventory( item ) && player.GetHumanInventory().CanAddEntityInHands( item ) )
			{
				player.PredictiveTakeEntityToHands( item );
			}
			else
			{
				if(player.GetInventory().CanAddEntityToInventory( item ) && item.GetInventory().CanRemoveEntity())
				{
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
	
			ItemManager.GetInstance().HideTooltip();
	
			name = w.GetName();
			name.Replace( "PanelWidget", "Temperature" );
			w.FindAnyWidget( name ).Show( false );
		}
	}

	bool DraggingOverGrid( Widget w,  int x, int y, Widget reciever, CargoContainer cargo )
	{
		if( w == NULL )
		{
			return false;
		}
		
		EntityAI item = GetItemPreviewItem( w );
		
		if( !item )
		{
			return false;
		}

		int color;
		int idx = 0;
		int c_x, c_y;
		
		EntityAI target_entity;
		CargoBase target_cargo;
		
		if( cargo == m_CargoGrid )
		{
			target_entity	= m_Entity;
			target_cargo 	= m_Entity.GetInventory().GetCargo();
		}
		else
		{
			target_entity	= m_AttachmentCargos.GetKeyByValue( cargo );
			if( target_entity )
			{
				target_cargo 	= target_entity.GetInventory().GetCargo();
			}
			else
				return false;
		}
		
		if( target_cargo && target_entity )
		{
			c_x = target_cargo.GetHeight();
			c_y = target_cargo.GetWidth();
		}
		else
			return false;
		
		if( c_x > x && c_y > y && target_entity.GetInventory().CanAddEntityInCargoEx( item, idx, x, y, item.GetInventory().GetFlipCargo() ) )
		{
			color = ColorManager.GREEN_COLOR;
			if( target_entity.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
			{
				ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
			}
			else
			{
				ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
			}
		}
		else
		{
			color = ColorManager.RED_COLOR;
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

	override void DraggingOver( Widget w, int x, int y, Widget receiver )
	{
		DraggingOverHeader( w, x, y, receiver );
	}

	override void DraggingOverHeader( Widget w, int x, int y, Widget receiver )
	{
		if( w == NULL )
		{
			return;
		}
		EntityAI item = GetItemPreviewItem( w );
		if( !item )
		{
			return;
		}
		
		SlotsIcon slots_icon;
		receiver.GetUserData(slots_icon);
	
		EntityAI attached_entity;
		EntityAI receiver_item;
		bool is_reserved = false;
		int slot_id = -1;
			
		if(slots_icon)
		{
			attached_entity	= slots_icon.GetSlotParent();
			slot_id			= slots_icon.GetSlotID();
			receiver_item 	= slots_icon.GetEntity();
			is_reserved 	= slots_icon.IsReserved();
		}


		Weapon_Base wpn;
		Magazine mag;
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if( m_Entity )
		{
			if( Class.CastTo(wpn,  m_Entity ) && Class.CastTo(mag,  item ) )
			{
				if( player.GetWeaponManager().CanAttachMagazine( wpn, mag ) )
				{
					ItemManager.GetInstance().HideDropzones();
					if( m_Entity.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
					{
						ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
					}
					else
					{
						ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
					}
					ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
				}
			}
			else if( receiver_item && !is_reserved )
			{
				ItemBase receiver_itemIB	= ItemBase.Cast( receiver_item );
				ItemBase itemIB				= ItemBase.Cast( item );
				if( receiver_itemIB && itemIB && receiver_itemIB.CanBeCombined( itemIB ) )
				{
					ItemManager.GetInstance().HideDropzones();
					if( m_Entity.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
					{
						ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
					}
					else
					{
						ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
					}
					ColorManager.GetInstance().SetColor( w, ColorManager.COMBINE_COLOR );
				}
				else if( GameInventory.CanSwapEntitiesEx( receiver_item, item ) )
				{
					ItemManager.GetInstance().HideDropzones();
					if( m_Entity.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
					{
						ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
					}
					else
					{
						ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
					}
					ColorManager.GetInstance().SetColor( w, ColorManager.SWAP_COLOR );
				}
				else if( receiver_itemIB.GetInventory().CanAddAttachment( item ) )
				{
					ItemManager.GetInstance().HideDropzones();
					if( receiver_itemIB.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
					{
						ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
					}
					else
					{
						ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
					}
					ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
				}
			}
			else if( attached_entity && attached_entity.GetInventory().CanAddAttachmentEx( item, slot_id ) )
			{
				ItemManager.GetInstance().HideDropzones();
				if( attached_entity.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
				{
					ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
				}
				else
				{
					ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
				}
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
			}
			else if( m_Entity.GetInventory().CanAddAttachment( item ) )
			{
				ItemManager.GetInstance().HideDropzones();
				if( m_Entity.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
				{
					ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
				}
				else
				{
					ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
				}
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
			}
			else if( ( m_Entity.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() ) && (!player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item )) ) /*|| player.GetHumanInventory().HasEntityInHands( item )*/ )
			{
				ItemManager.GetInstance().HideDropzones();
				if( m_Entity.GetHierarchyRootPlayer() == GetGame().GetPlayer() )
				{
					ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
				}
				else
				{
					ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
				}
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
			}
			else
			{
				ItemManager.GetInstance().ShowSourceDropzone( item );
				ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
			}
		}
	}
}
