class AttachmentCategoriesRow: ClosableContainer
{
	protected string									m_CategoryIdentifier;
	protected string									m_RowConfigPath;
	
	protected ref array<ref SlotsContainer>				m_Ics;
	protected ref map<EntityAI, ref CargoContainer>		m_AttachmentCargos;
	
	void AttachmentCategoriesRow( LayoutHolder parent, int sort = -1 )
	{
		ClosableHeader header	= ClosableHeader.Cast( m_Body.Get( 0 ) );
		m_Ics					= new array<ref SlotsContainer>;
		m_AttachmentCargos		= new map<EntityAI, ref CargoContainer>;
		
		header.GetMainWidget().ClearFlags( WidgetFlags.DRAGGABLE );
	}
	
	string GetCategoryIdentifier()
	{
		return m_CategoryIdentifier;
	}
	
	override EntityAI GetFocusedEntity()
	{
		SlotsIcon icon = GetFocusedIcon();
		if( icon )
		{
			return icon.GetEntity();
		}
		return null;
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
	
	int GetFocusedSlot()
	{
		if( m_FocusedRow < m_Ics.Count() )
		{
			return m_Ics.Get( m_FocusedRow ).GetSlotIcon( m_FocusedColumn ).GetSlotID();
		}
		return -1;
	}
	
	override bool SelectItem()
	{
		if( m_FocusedRow < m_Ics.Count() )
		{
			ItemBase item = ItemBase.Cast( GetFocusedEntity() );
			if ( !item.IsLockedInSlot() )
			{
				ItemManager.GetInstance().SetSelectedItem( item, null, m_Ics.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ) );
				return true;
			}
		}
		return false;
	}
	
	override bool Select()
	{
		ItemBase prev_item = ItemBase.Cast( GetFocusedEntity() );
		Man player = GetGame().GetPlayer();
		SlotsIcon selected_icon = GetFocusedIcon();
		
		if( ItemManager.GetInstance().IsItemMoving() )
		{
			ItemBase selected_item = ItemBase.Cast( ItemManager.GetInstance().GetSelectedItem() );
			int selected_slot = GetFocusedSlot();
			int stack_max;
			if( selected_item && selected_item.GetInventory().CanRemoveEntity() && !selected_icon.IsOutOfReach() )
			{
				if( m_Entity.GetInventory().CanAddAttachmentEx( selected_item, selected_slot ) )
				{
					stack_max = InventorySlots.GetStackMaxForSlotId( selected_slot );
					float quantity = selected_item.GetQuantity();
					if( stack_max == 0 || stack_max >= quantity || !selected_item.CanBeSplit() )
					{
						player.PredictiveTakeEntityToTargetAttachmentEx( m_Entity, selected_item, selected_slot );
						return true;
					}
					else
					{
						selected_item.SplitIntoStackMaxClient( m_Entity, selected_slot );
						return true;
					}
				}
				else if( selected_slot != -1 )
				{
					if( prev_item && prev_item.GetInventory().CanRemoveEntity() )
					{
						InventoryLocation inv_loc = new InventoryLocation;
						prev_item.GetInventory().GetCurrentInventoryLocation( inv_loc );
						stack_max = InventorySlots.GetStackMaxForSlotId( inv_loc.GetSlot() );
						quantity = prev_item.GetQuantity();
						if( prev_item.CanBeCombined( ItemBase.Cast( selected_item ) ) )
						{
							prev_item.CombineItemsClient( selected_item, true );
							return true;
						}
						else if( stack_max == 0 && GameInventory.CanSwapEntitiesEx( prev_item, selected_item ) )
						{
							player.PredictiveSwapEntities( selected_item, prev_item );
							return true;
						}
						else if( m_AttachmentCargos.Contains( prev_item ) )
						{
							if( prev_item.GetInventory().CanAddEntityInCargo( selected_item, selected_item.GetInventory().GetFlipCargo() ) )
							{
								SplitItemUtils.TakeOrSplitToInventory( PlayerBase.Cast( player ), prev_item, selected_item );
								return true;
							}
						}
					}
					else
					{
						InventoryLocation inv_loc_src = new InventoryLocation;
						InventoryLocation inv_loc_dst = new InventoryLocation;
						selected_item.GetInventory().GetCurrentInventoryLocation( inv_loc_src );
						m_Entity.GetInventory().FindFreeLocationFor( selected_item, FindInventoryLocationType.ATTACHMENT, inv_loc_dst );
						int dst_slot = inv_loc_dst.GetSlot();

						if(dst_slot == selected_slot && selected_item.GetInventory().CanRemoveEntity() && inv_loc_dst.IsValid() && inv_loc_dst.GetType() == InventoryLocationType.ATTACHMENT )
						{
							stack_max = InventorySlots.GetStackMaxForSlotId( inv_loc_dst.GetSlot() );
							quantity = selected_item.GetQuantity();
							if( stack_max == 0 || stack_max >= quantity || !selected_item.CanBeSplit() )
							{
								GetGame().GetPlayer().PredictiveTakeEntityToTargetAttachmentEx( m_Entity, selected_item, inv_loc_dst.GetSlot() );
								return true;
							}
							else if( stack_max >= 0 || !selected_item.CanBeSplit() )
							{
								selected_item.SplitIntoStackMaxClient( m_Entity, inv_loc_dst.GetSlot() );
								return true;
							}
						}
					}
				}
			}
		}
		else
		{
			if( prev_item && prev_item.GetInventory().CanRemoveEntity() && !selected_icon.IsOutOfReach() )
			{
				EntityAI item_in_hands = GetGame().GetPlayer().GetHumanInventory().GetEntityInHands();
				if( item_in_hands && item_in_hands.GetInventory().CanRemoveEntity() )
				{
					if( GameInventory.CanSwapEntitiesEx( item_in_hands, prev_item ) )
					{
						player.PredictiveSwapEntities( item_in_hands, prev_item );
						return true;
					}
				}
				else
				{
					if( player.GetHumanInventory().CanAddEntityInHands( prev_item ) )
					{
						player.PredictiveTakeEntityToHands( prev_item );
						return true;
					}
				}
			}		
		}
		return false;
	}
	
	override bool TransferItem()
	{
		EntityAI entity = GetFocusedEntity();
		if( entity && !entity.IsLockedInSlot() && !GetFocusedIcon().IsOutOfReach() )
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			GetGame().GetPlayer().PredictiveTakeEntityToInventory( FindInventoryLocationType.CARGO, entity );
			return true;
		}
		return false;
	}
	
	override bool TransferItemToVicinity()
	{
		ItemBase item = ItemBase.Cast(GetFocusedEntity());
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if( item && !item.IsLockedInSlot() && !GetFocusedIcon().IsOutOfReach() )
		{
			if( item.GetTargetQuantityMax() < item.GetQuantity() )
				item.SplitIntoStackMaxClient( null, -1 );
			else
				player.PhysicalPredictiveDropItem( item );
			return true;
		}
		return false;
	}
	
	override bool Combine()
	{
		Man player = GetGame().GetPlayer();
		ItemBase prev_item = ItemBase.Cast( GetFocusedEntity() );
		ItemBase selected_item = ItemBase.Cast( player.GetHumanInventory().GetEntityInHands() );
		
		if( selected_item )
		{
			int selected_slot = GetFocusedSlot();
			int stack_max;
			if( selected_item && selected_item.GetInventory().CanRemoveEntity() && !GetFocusedIcon().IsOutOfReach() )
			{
				if( m_Entity.GetInventory().CanAddAttachmentEx( selected_item, selected_slot ) )
				{
					stack_max = InventorySlots.GetStackMaxForSlotId( selected_slot );
					float quantity = selected_item.GetQuantity();
					if( stack_max == 0 || stack_max >= quantity || !selected_item.CanBeSplit() )
					{
						player.PredictiveTakeEntityToTargetAttachmentEx( m_Entity, selected_item, selected_slot );
						return false;
					}
					else
					{
						selected_item.SplitIntoStackMaxClient( m_Entity, selected_slot );
						return false;
					}
				}
				else if( selected_slot != -1 )
				{
					if( prev_item )
					{
						InventoryLocation inv_loc = new InventoryLocation;
						prev_item.GetInventory().GetCurrentInventoryLocation( inv_loc );
						stack_max = InventorySlots.GetStackMaxForSlotId( inv_loc.GetSlot() );
						quantity = prev_item.GetQuantity();
						if( prev_item.CanBeCombined( ItemBase.Cast( selected_item ) ) )
						{
							prev_item.CombineItemsClient( selected_item, true );
							return false;
						}
						else if( stack_max == 0 && GameInventory.CanSwapEntitiesEx( prev_item, selected_item ) )
						{
							player.PredictiveSwapEntities( selected_item, prev_item );
							return false;
						}
						else if( m_AttachmentCargos.Contains( prev_item ) )
						{
							if( prev_item.GetInventory().CanAddEntityInCargo( selected_item, selected_item.GetInventory().GetFlipCargo() ) )
							{
								SplitItemUtils.TakeOrSplitToInventory( PlayerBase.Cast( player ), prev_item, selected_item );
								return false;
							}
						}
					}
					else
					{
						InventoryLocation inv_loc_src = new InventoryLocation;
						InventoryLocation inv_loc_dst = new InventoryLocation;
						selected_item.GetInventory().GetCurrentInventoryLocation( inv_loc_src );
						m_Entity.GetInventory().FindFreeLocationFor( selected_item, FindInventoryLocationType.ATTACHMENT, inv_loc_dst );
						
						if( inv_loc_dst.IsValid() && inv_loc_dst.GetType() == InventoryLocationType.ATTACHMENT )
						{
							stack_max = InventorySlots.GetStackMaxForSlotId( inv_loc_dst.GetSlot() );
							quantity = selected_item.GetQuantity();
							if( stack_max == 0 || stack_max >= quantity || !selected_item.CanBeSplit() )
							{
								GetGame().GetPlayer().PredictiveTakeEntityToTargetAttachmentEx( m_Entity, selected_item, inv_loc_dst.GetSlot() );
								return false;
							}
							else if( stack_max >= 0 || !selected_item.CanBeSplit() )
							{
								selected_item.SplitIntoStackMaxClient( m_Entity, inv_loc_dst.GetSlot() );
								return false;
							}
						}
					}
				}
			}
		}
		return true;
	}
	
	override bool EquipItem()
	{
		return false;
	}
	
	override bool CanEquip()
	{
		return false;
	}
	
	override bool CanCombine()
	{
		Man player = GetGame().GetPlayer();
		ItemBase prev_item = ItemBase.Cast( GetFocusedEntity() );
		ItemBase selected_item = ItemBase.Cast( player.GetHumanInventory().GetEntityInHands() );
		
		if( selected_item )
		{
			int selected_slot = GetFocusedSlot();
			int stack_max;
			if( selected_item && selected_item.GetInventory().CanRemoveEntity() && !GetFocusedIcon().IsOutOfReach() )
			{
				if( m_Entity.GetInventory().CanAddAttachmentEx( selected_item, selected_slot ) )
				{
					stack_max = InventorySlots.GetStackMaxForSlotId( selected_slot );
					float quantity = selected_item.GetQuantity();
					if( stack_max == 0 || stack_max >= quantity || !selected_item.CanBeSplit() )
					{
						return true;
					}
					else
					{
						return true;
					}
				}
				else if( selected_slot != -1 )
				{
					if( prev_item )
					{
						InventoryLocation inv_loc = new InventoryLocation;
						prev_item.GetInventory().GetCurrentInventoryLocation( inv_loc );
						stack_max = InventorySlots.GetStackMaxForSlotId( inv_loc.GetSlot() );
						quantity = prev_item.GetQuantity();
						if( prev_item.CanBeCombined( ItemBase.Cast( selected_item ) ) )
						{
							return true;
						}
					}
					else
					{
						InventoryLocation inv_loc_src = new InventoryLocation;
						InventoryLocation inv_loc_dst = new InventoryLocation;
						selected_item.GetInventory().GetCurrentInventoryLocation( inv_loc_src );
						m_Entity.GetInventory().FindFreeLocationFor( selected_item, FindInventoryLocationType.ATTACHMENT, inv_loc_dst );
						
						if( inv_loc_dst.IsValid() && inv_loc_dst.GetType() == InventoryLocationType.ATTACHMENT )
						{
							stack_max = InventorySlots.GetStackMaxForSlotId( inv_loc_dst.GetSlot() );
							quantity = selected_item.GetQuantity();
							if( stack_max == 0 || stack_max >= quantity || !selected_item.CanBeSplit() )
							{
								return true;
							}
							else if( stack_max >= 0 || !selected_item.CanBeSplit() )
							{
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}
	
	override bool CanCombineAmmo()
	{
		return false;
	}
	
	override bool IsEmpty()
	{
		return GetFocusedIcon().GetEntity() == null && !GetFocusedIcon().IsOutOfReach();
	}
	
	override bool IsItemActive()
	{
		return GetFocusedIcon().GetEntity() != null && !GetFocusedIcon().IsOutOfReach();
	}

	override bool IsItemWithQuantityActive()
	{
		ItemBase item = GetFocusedIcon().GetItem();
		return item && !GetFocusedIcon().IsOutOfReach() && item.CanBeSplit();
	}
	
	void SetDefaultFocus()
	{
		m_FocusedRow = 0;
		m_FocusedColumn = 0;
		if( m_FocusedRow < m_Ics.Count() )
		{
			m_Ics.Get( 0 ).GetMainWidget().FindAnyWidget( "Cursor" + 0 ).Show( true );
			EntityAI focused_item = GetFocusedEntity();
			if( focused_item )
			{
				float x, y;
				m_Ics.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).GetScreenPos( x, y );
				ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
			}
		}
	}
	
	override bool IsLastContainerFocused()
	{
		return true;
	}
	
	override void MoveGridCursor( int direction )
	{
		ItemManager.GetInstance().HideTooltip();
		UnfocusAll();
		int max_row;
		Container cnt;
		CargoContainer grid;
		if( direction == Direction.UP )
		{
			m_FocusedRow--;
			if( m_FocusedRow < 0 )
			{
				m_FocusedRow  = m_Ics.Count() - 1;
				cnt = Container.Cast( m_Parent.GetParent().GetParent() );
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
			
			if( m_FocusedRow < m_Ics.Count() )
			{
				max_row = m_Ics.Get( m_FocusedRow ).GetColumnCount() - 1;
				if( max_row < m_FocusedColumn )
				{
					m_FocusedColumn = max_row;
				}
			}
			else if( m_FocusedRow < m_Ics.Count() + m_AttachmentCargos.Count() )
			{
				m_AttachmentCargos.GetElement( m_FocusedRow - m_Ics.Count() ).MoveGridCursor( direction );
			}
		}
	
		if( direction == Direction.DOWN )
		{
			m_FocusedRow++;
			if( m_FocusedRow == m_Ics.Count() + m_AttachmentCargos.Count() )
			{
				m_FocusedRow = 0;
				cnt = Container.Cast( m_Parent.GetParent().GetParent().GetParent() );
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
			
			if( m_FocusedRow < m_Ics.Count() )
			{
				max_row = m_Ics.Get( m_FocusedRow ).GetColumnCount() - 1;
				if( max_row < m_FocusedColumn )
				{
					m_FocusedColumn = max_row;
				}
			}
			else if( m_FocusedRow < m_Ics.Count() + m_AttachmentCargos.Count() )
			{
				grid = m_AttachmentCargos.GetElement( m_FocusedRow - m_Ics.Count() );
				if( grid.IsActive() )
					grid.MoveGridCursor( direction );
				else
				{
					if( m_FocusedRow - 1 < m_Ics.Count() )
					{
						m_Ics.Get( m_FocusedRow - 1 ).SetActive( false );
					}
					SetFocusedContainer( m_AttachmentCargos.GetElement( m_FocusedRow - m_Ics.Count() ) );
					grid.SetActive( true );
				}
			}
		}
	
		if( direction == Direction.RIGHT )
		{
			if( m_FocusedRow < m_Ics.Count() )
			{
				m_FocusedColumn++;
				if( m_FocusedColumn == m_Ics.Get( m_FocusedRow ).GetColumnCount() )
				{
					m_FocusedColumn = 0;
				}
			}
			else if( m_FocusedRow < m_Ics.Count() + m_AttachmentCargos.Count() )
			{
				m_AttachmentCargos.GetElement( m_FocusedRow - m_Ics.Count() ).MoveGridCursor( direction );
			}
		}
	
		if( direction == Direction.LEFT )
		{
			if( m_FocusedRow < m_Ics.Count() )
			{
				m_FocusedColumn--;
				if( m_FocusedColumn < 0 )
				{
					m_FocusedColumn = m_Ics.Get( m_FocusedRow ).GetColumnCount() - 1;
				}
			}
			else if( m_FocusedRow < m_Ics.Count() + m_AttachmentCargos.Count() )
			{
				m_AttachmentCargos.GetElement( m_FocusedRow - m_Ics.Count() ).MoveGridCursor( direction );
			}
		}
	
		if( m_FocusedRow < m_Ics.Count() )
		{
			m_Ics.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).Show( true );
			EntityAI focused_item = GetFocusedEntity();
			if( focused_item )
			{
				float x, y;
				m_Ics.Get( m_FocusedRow ).GetMainWidget().FindAnyWidget( "Cursor" + m_FocusedColumn ).GetScreenPos( x, y );
				ItemManager.GetInstance().PrepareTooltip( focused_item, x, y );
			}
		}
	}
	
	override void OnDropReceivedFromHeader( Widget w, int x, int y, Widget receiver )
	{
		ItemManager.GetInstance().HideDropzones();
		ItemManager.GetInstance().SetIsDragging( false );
		SlotsIcon slots_icon;
		EntityAI receiver_item;
		int slot_id = -1;
		bool is_reserved = false;
		EntityAI attached_entity;
		receiver.GetUserData(slots_icon);
		float stackable = 0.0;
		InventoryLocation il = new InventoryLocation;
		
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
		else if( attached_entity && slot_id != -1 &&  attached_entity.GetInventory().CanAddAttachmentEx( item, slot_id ) )
		{
			item_base	= ItemBase.Cast( item );
			stackable	= item_base.GetTargetQuantityMax( slot_id );
			
			if( stackable == 0 || stackable >= item_base.GetQuantity() )
			{
				player.PredictiveTakeEntityToTargetAttachmentEx(attached_entity, item, slot_id);
			}
			else if( stackable != 0 && stackable < item_base.GetQuantity() )
			{
				item_base.SplitIntoStackMaxClient( m_Entity, slot_id );
			}
		}
		else if(attached_entity && slot_id == -1 && attached_entity.GetInventory().FindFreeLocationFor(item,FindInventoryLocationType.ATTACHMENT,il))
		{
			item_base	= ItemBase.Cast( item );
			stackable	= item_base.GetTargetQuantityMax( il.GetSlot() );
			
			if( stackable == 0 || stackable >= item_base.GetQuantity() )
			{
				player.PredictiveTakeEntityToTargetAttachmentEx(attached_entity, item, il.GetSlot());
			}
			else if( stackable != 0 && stackable < item_base.GetQuantity() )
			{
				item_base.SplitIntoStackMaxClient( m_Entity, il.GetSlot() );
			}
		}
		else if( ( m_Entity.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() ) && ( !player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item )) ) /*|| player.GetHumanInventory().HasEntityInHands( item )*/ )
		{
			SplitItemUtils.TakeOrSplitToInventory( PlayerBase.Cast( GetGame().GetPlayer() ), m_Entity, item );
		}
	}

	override void UnfocusAll()
	{
		int i;
		for ( i = 1; i < Count(); i++ )
		{
			for ( int j = 0; j < ITEMS_IN_ROW; j++ )
			{
				Widget w = Get( i ).GetMainWidget().FindAnyWidget( "Cursor" + j );
				if( w )
					w.Show( false );
			}
		}
		for ( i = 0; i < m_AttachmentCargos.Count(); i++ )
		{
			m_AttachmentCargos.GetElement( i ).Unfocus();
			m_AttachmentCargos.GetElement( i ).SetActive( false );
		}
	}

	override void DraggingOverHeader( Widget w, int x, int y, Widget receiver )
	{
		if( w == null )
		{
			return;
		}
		ItemPreviewWidget iw = ItemPreviewWidget.Cast( w.FindAnyWidget("Render") );
		if(!iw)
		{
		  string name = w.GetName();
		  name.Replace("PanelWidget", "Render");
		  iw = ItemPreviewWidget.Cast( w.FindAnyWidget(name) );
		}
		if(!iw)
		{
		  iw = ItemPreviewWidget.Cast( w );
		}
		
		if( !iw || !iw.GetItem() )
		{
			return;
		}
		
		ItemBase item;
		ItemBase receiver_item;
		name = receiver.GetName();
		name.Replace("PanelWidget", "Render");
		ItemPreviewWidget receiver_iw = ItemPreviewWidget.Cast( receiver.FindAnyWidget(name) );
		if(receiver_iw)
			receiver_item = ItemBase.Cast( receiver_iw.GetItem() );
		
		SlotsIcon slots_icon;
		receiver.GetUserData(slots_icon);
		
		if( receiver_item )
		{
			int stack_max = InventorySlots.GetStackMaxForSlotId( receiver_item.GetInventory().GetSlotId(0) );
			//int quantity = receiver_item.GetQuantity();
			//bool combinable = ( quantity < stack_max ) && ( ItemBase.Cast( receiver_item ).CanBeCombined( ItemBase.Cast( iw.GetItem() ) ) );
			if( receiver_item.CanBeCombined( ItemBase.Cast( iw.GetItem() ) ) )
			{
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
				ColorManager.GetInstance().SetColor( w, ColorManager.COMBINE_COLOR );
			}
			else if( stack_max == 0 && GameInventory.CanSwapEntitiesEx( receiver_item, iw.GetItem() ) )
			{
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
				ColorManager.GetInstance().SetColor( w, ColorManager.SWAP_COLOR );
			}
			else
			{
				ItemManager.GetInstance().ShowSourceDropzone( iw.GetItem() );
				ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
			}
		}
		else if( slots_icon && slots_icon.GetSlotID() != -1 )
		{
			item = ItemBase.Cast( iw.GetItem() );
			
			if( m_Entity.GetInventory().CanAddAttachmentEx( item, slots_icon.GetSlotID() ) )
			{
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
			}
			else
			{
				ItemManager.GetInstance().ShowSourceDropzone( iw.GetItem() );
				ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
			}
		}
		else
		{
			ItemManager.GetInstance().ShowSourceDropzone( iw.GetItem() );
			ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
		}
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
			
			SlotsIcon slots_icon;
			w.GetUserData(slots_icon);
			
			if( slots_icon && m_Entity.GetInventory().GetSlotLock( iw.GetUserID() ) )
			{
				return;
			}
			
			ItemBase item = ItemBase.Cast( iw.GetItem() );
			
			if( !item.GetInventory().CanRemoveEntity() )
				return;
			
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			
			if( player.GetInventory().HasEntityInInventory( item ) && player.GetHumanInventory().CanAddEntityInHands( item ) )
			{
				player.PredictiveTakeEntityToHands( item );
			}
			else
			{
				if(player.GetInventory().CanAddEntityToInventory( item ) && item.GetInventory().CanRemoveEntity())
				{
					if( item.GetTargetQuantityMax() < item.GetQuantity() )
					{
						item.SplitIntoStackMaxClient( player, -1 );
					}
					else
					{
						player.PredictiveTakeEntityToInventory( FindInventoryLocationType.ANY, item );
					}
				}
				else
				{
					if( player.GetHumanInventory().CanAddEntityInHands( item ) )
					{
						if( item.GetTargetQuantityMax() < item.GetQuantity() )
						{
							item.SplitIntoStackMaxHandsClient( player );
						}
						else
						{
							player.PredictiveTakeEntityToHands( item );
						}
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
		if( w == null )
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
		
		target_entity		= m_AttachmentCargos.GetKeyByValue( cargo );
		if( target_entity )
		{
			target_cargo 	= target_entity.GetInventory().GetCargo();
		}
		else
			return false;
		
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
		
		target_entity	= m_AttachmentCargos.GetKeyByValue( cargo );
		if( target_entity )
		{
			target_cargo 	= target_entity.GetInventory().GetCargo();
		}
		else
			return;
		
		if( target_cargo && target_entity )
		{
			c_x = target_cargo.GetHeight();
			c_y = target_cargo.GetWidth();
		}
		else
			return;
		
		InventoryLocation dst = new InventoryLocation;		
		dst.SetCargoAuto(target_cargo, item, x, y, item.GetInventory().GetFlipCargo());
			
		if( c_x > x && c_y > y && target_entity.GetInventory().LocationCanAddEntity(dst))
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );

			SplitItemUtils.TakeOrSplitToInventoryLocation( player, dst);

			Icon icon = cargo.GetIcon( item );
			
			if( icon )
			{
				icon.GetRootWidget().FindAnyWidget("Selected").SetColor( ColorManager.BASE_COLOR );
				icon.RefreshPos( x, y );
				icon.Refresh();
				Refresh();
			}
		}
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
			return null;
		}
		return ipw.GetItem();
	}
	
	override void Refresh()
	{
		if( !m_Closed )
		{
			super.Refresh();
			
		}
	}
	
	void RefreshSlot( int j, int id, int slot_id, string slot_name )
	{
		EntityAI item = m_Entity.GetInventory().FindAttachment( slot_id );
		
		SlotsContainer row				= SlotsContainer.Cast( Get( ( j / ITEMS_IN_ROW + 1 ) ) );
		SlotsIcon icon					= row.GetSlotIcon( id );
		
		icon.SetSlotID(slot_id);
		
		if( !m_Entity.CanDisplayAttachmentSlot( slot_name ) )
		{
			icon.Clear();
			icon.GetMainWidget().Show( false );
		}
		else if( !item )
		{
			icon.Clear();
			icon.GetMainWidget().Show( true );
		}
		else
		{
			icon.GetMainWidget().Show( true );
			icon.Init( item );
			icon.Refresh();
			
			if( item.GetInventory().GetCargo() && m_AttachmentCargos )
			{
				if( !m_AttachmentCargos.Contains( item ) )
				{
					ref CargoContainer cont = new CargoContainer( this, true );
					cont.GetRootWidget().SetSort( m_AttachmentCargos.Count() + 10 );
					cont.SetEntity( item );
					this.Insert( cont );
					
					m_AttachmentCargos.Insert( item, cont );
				}
			}
			
			bool draggable				= true;
			bool in_hands_condition		= m_Entity.GetHierarchyRoot() == GetGame().GetPlayer() && item.GetInventory().CanRemoveEntity();
			bool in_vicinity_condition	= AttachmentsOutOfReach.IsAttachmentReachable( m_Entity, slot_name );
			if( m_Entity.GetInventory().GetSlotLock( slot_id ) && ItemManager.GetInstance().GetDraggedItem() != item )
			{
				icon.GetMountedWidget().Show( true );
				draggable = false;
			}
			else
			{
				icon.GetMountedWidget().Show( false );
			}
			
			if( !m_Entity.CanReleaseAttachment( item ) )
			{
				draggable = false;
			}
			
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
				icon.GetRender().GetParent().SetFlags( WidgetFlags.DRAGGABLE );
			}
			else
			{
				icon.GetRender().GetParent().ClearFlags( WidgetFlags.DRAGGABLE );
			}
		}
	}
	
	void Init(int attachments_categories_count, int i, string attachment_category, string config_path_attachment_categories, EntityAI entity, int parent_m_Body_count )
	{
		m_Entity = entity;
		Header he = Header.Cast( this.Get(0) );
		
		m_CategoryIdentifier = attachment_category;
		
		ref array<string> player_ghosts_slots2 = new array<string>;
		string category_name;
		
		m_RowConfigPath = config_path_attachment_categories + " " + attachment_category + " attachmentSlots";
		string config_path_category_name = config_path_attachment_categories + " " + attachment_category + " name";
		GetGame().ConfigGetTextArray( m_RowConfigPath, player_ghosts_slots2 );
		GetGame().ConfigGetText( config_path_category_name, category_name );
		he.SetName( category_name );
		
		int count = player_ghosts_slots2.Count();
		int number_of_rows = ( count / ITEMS_IN_ROW );
		if( count % ITEMS_IN_ROW == 0 )
		{
			number_of_rows--;
		}
		
		if( parent_m_Body_count < attachments_categories_count + 2 + attachments_categories_count / ITEMS_IN_ROW )
		{
			for ( int j = 0; j < (count / ITEMS_IN_ROW) + 1; j++ )
			{
				SlotsContainer ic = new SlotsContainer(this, m_Entity);
				ic.GetRootWidget().SetAlpha(0.7);
				if( j == number_of_rows && count % ITEMS_IN_ROW != 0 )
				{
					ic.SetColumnCount( count % ITEMS_IN_ROW );
				}
				else
				{
					ic.SetColumnCount( ITEMS_IN_ROW );
				}
				
				this.Insert(ic);
				m_Ics.Insert( ic );
				
				ic.GetRootWidget().SetSort( m_Ics.Count() );
				
				for(int k = 0; k < ITEMS_IN_ROW; k++)
				{
					SlotsIcon icon = ic.GetSlotIcon( k );
					WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetMainWidget(),  this, "OnDropReceivedFromHeader" );
					WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetGhostSlot(),  this, "OnDropReceivedFromHeader" );
					WidgetEventHandler.GetInstance().RegisterOnDropReceived( icon.GetPanelWidget(),  this, "OnDropReceivedFromHeader" );
					
					WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetMainWidget(),  this, "DraggingOverHeader" );
					WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetGhostSlot(),  this, "DraggingOverHeader" );
					WidgetEventHandler.GetInstance().RegisterOnDraggingOver( icon.GetPanelWidget(),  this, "DraggingOverHeader" );
					
					WidgetEventHandler.GetInstance().RegisterOnDrop( icon.GetMainWidget(),  this, "OnIconDrop" );
					WidgetEventHandler.GetInstance().RegisterOnDrop( icon.GetPanelWidget(),  this, "OnIconDrop" );
				}
			}
		}
		
		for ( j = 0; j < count; j++ )
		{
			string slot_name = player_ghosts_slots2.Get ( j );
			string icon_name2;
			string path = "CfgSlots" + " Slot_" + slot_name;
			GetGame().ConfigGetText( path + " ghostIcon", icon_name2 );
			GetGame().ConfigGetText( path + " name", slot_name );
			
			int slot_id						= InventorySlots.GetSlotIdFromString( slot_name );
			int id							= j % ITEMS_IN_ROW;
			
			SlotsContainer ic2				= SlotsContainer.Cast( Get( ( j / ITEMS_IN_ROW + 1 ) ) );
			SlotsIcon icon2					= ic2.GetSlotIcon( id );
			
			EntityAI ent = entity.GetInventory().FindAttachment( slot_id );
			
			//icon2.Clear();
			RefreshSlot( j, id, slot_id, slot_name );
			
			icon2.GetGhostSlot().LoadImageFile( 0,"set:dayz_inventory image:" + icon_name2 );
		}
		
		array<EntityAI> cargo_attachments = entity.GetAttachmentsWithCargo();
		for( i = 0; i < m_AttachmentCargos.Count(); i++ )
		{
			EntityAI e			= m_AttachmentCargos.GetKey( i );
			if( e )
			{
				if( cargo_attachments.Find( e ) == -1 )
				{
					CargoContainer old_cont = m_AttachmentCargos.GetElement( i );
					m_Body.RemoveItem( old_cont );
					m_AttachmentCargos.Remove( e );
				}
				else if( m_AttachmentCargos.Get( e ) )
				{
					m_AttachmentCargos.Get( e ).UpdateInterval();
				}
			}
		}
	}
}
