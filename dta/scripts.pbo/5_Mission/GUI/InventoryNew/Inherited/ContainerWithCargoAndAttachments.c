class ContainerWithCargoAndAttachments extends ClosableContainer
{
	protected ref Attachments								m_Atts;
	protected ref CargoContainer							m_CargoGrid;
	
	protected ref map<EntityAI, ref CargoContainer>			m_AttachmentCargos;
	protected ref map<EntityAI, ref AttachmentsWrapper>		m_AttachmentAttachmentsContainers;
	protected ref map<EntityAI, ref Attachments>			m_AttachmentAttachments;

	void ~ContainerWithCargoAndAttachments()
	{
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
	
	override void UpdateInterval()
	{
		int i;
		if( m_Entity )
		{
			EntityAI e;
			array<EntityAI> cargo_attachments = m_Entity.GetAttachmentsWithCargo();
			if( cargo_attachments && m_AttachmentCargos )
			{
				for( i = 0; i < m_AttachmentCargos.Count(); i++ )
				{
					e			= m_AttachmentCargos.GetKey( i );
					if( e )
					{
						if( cargo_attachments.Find( e ) == -1 )
						{
							CargoContainer old_cont = m_AttachmentCargos.GetElement( i );
							m_Body.RemoveItem( old_cont );
							m_AttachmentCargos.Remove( e );
							RecomputeOpenedContainers();
						}
						else
						{
							m_AttachmentCargos.Get( e ).UpdateInterval();
						}
					}
				}
				
				for( i = 0; i < cargo_attachments.Count(); i++ )
				{
					if( !m_AttachmentCargos.Contains( cargo_attachments.Get( i ) ) )
					{
						ref CargoContainer cont = new CargoContainer( this, true );
						cont.GetRootWidget().SetSort( i + 50 );
						cont.SetEntity( cargo_attachments.Get( i ) );
						Insert( cont, m_Atts.GetAttachmentHeight() + 1 + m_AttachmentCargos.Count() );
						
						m_AttachmentCargos.Insert( cargo_attachments.Get( i ), cont );
						RecomputeOpenedContainers();
					}
				}
			}
			
			array<EntityAI> attachment_attachments = m_Entity.GetAttachmentsWithAttachments();
			if( attachment_attachments && m_AttachmentAttachments )
			{
				for( i = 0; i < m_AttachmentAttachmentsContainers.Count(); i++ )
				{
					e			= m_AttachmentAttachmentsContainers.GetKey( i );
					if( e )
					{
						if( attachment_attachments.Find( e ) == -1 )
						{
							AttachmentsWrapper old_att_cont = m_AttachmentAttachmentsContainers.GetElement( i );
							m_Body.RemoveItem( old_att_cont );
							m_AttachmentAttachmentsContainers.Remove( e );
							m_AttachmentAttachments.Remove( e );
							delete old_att_cont;
							m_Body.RemoveItem( old_att_cont );
							m_AttachmentAttachments.Remove( e );
							RecomputeOpenedContainers();
						}
						else
						{
							m_AttachmentAttachments.Get( e ).RefreshAtt();
						}
					}
				}
				
				for( i = 0; i < attachment_attachments.Count(); i++ )
				{
					if( !m_AttachmentAttachments.Contains( attachment_attachments.Get( i ) ) )
					{
						ref Attachments att_cont = new Attachments( this, attachment_attachments.Get( i ) );
						att_cont.InitAttachmentGrid( i + m_Atts.GetAttachmentHeight() + 1 );
						
						m_AttachmentAttachments.Insert( attachment_attachments.Get( i ), att_cont );
						m_AttachmentAttachmentsContainers.Insert( attachment_attachments.Get( i ), att_cont.GetWrapper() );
						
						att_cont.RefreshAtt();
						RecomputeOpenedContainers();
					}
				}
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
				m_Atts.RefreshAtt();
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
	}

	void SetEntity( EntityAI entity )
	{
		m_Entity = entity;
		
		m_Atts = new Attachments( this, entity );
		m_Atts.InitAttachmentGrid( 1 );
		
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
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		
		if( !item_preview )
		{
			return;
		}
		
		bool inventory_locked = GetGame().GetPlayer().GetInventory().IsInventoryLocked();
		ItemManager.GetInstance().SetWidgetDraggable( w, !inventory_locked );
		EntityAI item = item_preview.GetItem();
		InventoryItem itemAtPos = InventoryItem.Cast( item );
		
		if( item )
		{
			if( button == MouseState.MIDDLE )
			{
				InspectItem( itemAtPos );
			}
			else if ( button == MouseState.LEFT && g_Game.IsLeftCtrlDown() )
			{
				if( itemAtPos.GetInventory().CanRemoveEntity() )
				{
					GetGame().GetPlayer().PredictiveDropEntity( itemAtPos );
				}
			}
		}
	}
	
	void DraggingOverHeader2(Widget w, int x, int y, Widget receiver )
	{
		DraggingOverHeader(w, x, y, receiver );
	}

	void OnIconDrag( Widget w )
	{
		ItemManager.GetInstance().HideDropzones();
		if( m_Entity.GetHierarchyParent() == GetGame().GetPlayer() )
		{
			ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
		}
		else
		{
			ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
		}
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		ItemPreviewWidget ipw = ItemPreviewWidget.Cast( w.FindAnyWidget(name) );
		float icon_x, icon_y, x_content, y_content;
		int m_sizeX, m_sizeY;

		InventoryItem i_item = InventoryItem.Cast( ipw.GetItem() );
		if( i_item ) 
		{
			GetGame().GetInventoryItemSize( i_item, m_sizeX, m_sizeY );
	
			m_Parent.m_Parent.GetMainWidget().FindAnyWidget( "body" ).GetScreenSize( x_content, y_content );
			icon_x = x_content / 10;
			icon_y = x_content / 10;
			w.SetFlags( WidgetFlags.EXACTSIZE );
			if( i_item.GetInventory().GetFlipCargo() )
			{
				w.SetSize( icon_x * m_sizeY - 1 , icon_y * m_sizeX + m_sizeX - 1 );
			}
			else
			{
				w.SetSize( icon_x * m_sizeX - 1 , icon_y * m_sizeY + m_sizeY - 1 );
			}

			name.Replace( "Render", "Col" );
			w.FindAnyWidget( name ).Show( true );
			name.Replace( "Col", "RadialIcon" );
			w.GetParent().FindAnyWidget( name ).Show( false );
			name.Replace( "RadialIcon", "Temperature" );
			w.FindAnyWidget( name ).Show( false );
			name.Replace( "Temperature", "Selected" );
			w.FindAnyWidget( name ).Show( true );
			ItemManager.GetInstance().SetDraggedItem( i_item );
			ItemManager.GetInstance().SetIsDragging( true );
		}
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
		name.Replace( "Col", "Temperature" );
		w.FindAnyWidget( name ).Show( false );
		name.Replace( "Temperature", "Selected" );
		w.FindAnyWidget( name ).Show( false );
		w.FindAnyWidget( name ).SetColor( ARGBF( 1, 1, 1, 1 ) );
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
				return;
		}
		
		if( target_cargo && target_entity )
		{
			c_x = target_cargo.GetHeight();
			c_y = target_cargo.GetWidth();
		}
		else
			return;
		
		if( c_x > x && c_y > y && target_entity.GetInventory().CanAddEntityInCargoEx( item, idx, x, y, item.GetInventory().GetFlipCargo() ) )
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );

			TakeIntoCargo( player, target_entity, item, idx, x, y );

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
	
	void TakeIntoCargo( notnull PlayerBase player, notnull EntityAI entity, notnull EntityAI item, int idx = -1, int row = 0, int col = 0 )
	{
		ItemBase item_base = ItemBase.Cast( item );
		if( item_base )
		{
			float stackable = item_base.ConfigGetFloat("varStackMax");
			
			if( !item.GetInventory().CanRemoveEntity() || !player.CanManipulateInventory() )
				return;
			
			if( stackable == 0 || stackable >= item_base.GetQuantity() )
			{
				if( idx != -1 )
					player.PredictiveTakeEntityToTargetCargoEx( entity, item, idx, row, col );
				else
					player.PredictiveTakeEntityToTargetAttachment(entity, item);
			}
			else if( stackable != 0 && stackable < item_base.GetQuantity() )
			{
				item_base.SplitIntoStackMaxCargoClient( entity, idx, row, col );
			}
		}
		
	}

	void TakeAsAttachment( Widget w, Widget receiver )
	{
		ItemManager.GetInstance().HideDropzones();
		ItemManager.GetInstance().SetIsDragging( false );
		
		EntityAI receiver_item;
		int slot_id = -1;
		string name = receiver.GetName();
		name.Replace("PanelWidget", "Render");
		
		ItemPreviewWidget receiver_iw = ItemPreviewWidget.Cast( receiver.FindAnyWidget(name) );
		if( receiver_iw )
		{
			receiver_item	= receiver_iw.GetItem();
			slot_id			= receiver_iw.GetUserID();
		}
		
		EntityAI item = GetItemPreviewItem( w );
		if( !item )
		{
			return;
		}
		
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
		else if( receiver_item )
		{
			if( ( ItemBase.Cast( receiver_item ) ).CanBeCombined( ItemBase.Cast( item ) ) )
			{
				( ItemBase.Cast( receiver_item ) ).CombineItemsClient( ItemBase.Cast( item ) );
			}
			else if( GameInventory.CanSwapEntities( receiver_item, item ) )
			{
				if( !receiver_item.GetInventory().CanRemoveEntity() )
					return;
				GetGame().GetPlayer().PredictiveSwapEntities( item, receiver_item );
			}
		}
		else if( m_Entity.GetInventory().CanAddAttachment( item ) )
		{
			ItemBase item_base	= ItemBase.Cast( item );
			float stackable		= item_base.ConfigGetFloat("varStackMax");
			
			if( stackable == 0 || stackable >= item_base.GetQuantity() )
			{
				if( slot_id != -1 )
					player.PredictiveTakeEntityToTargetAttachmentEx(m_Entity, item, slot_id);
				else
					player.PredictiveTakeEntityToTargetAttachment(m_Entity, item);
			}
			else if( stackable != 0 && stackable < item_base.GetQuantity() )
			{
				item_base.SplitIntoStackMaxClient( m_Entity, slot_id );
			}
		}
		else if( ( m_Entity.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() ) && ( !player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item )) ) || player.GetHumanInventory().HasEntityInHands( item ) )
		{
			TakeIntoCargo( PlayerBase.Cast( GetGame().GetPlayer() ), m_Entity, item );
		}
		else if( !player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item ) )
		{
			TakeIntoCargo( PlayerBase.Cast( GetGame().GetPlayer() ), m_Entity, item );
		}
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
			if( !iw.GetItem() )
			{
				return;
			}
	
			EntityAI item = iw.GetItem();
			
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
					if( item.ConfigGetFloat("varStackMax") )
						player.PredictiveTakeEntityToInventory( FindInventoryLocationType.ANY, InventoryItem.Cast( item ) );
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

		EntityAI receiver_item;
		string name = receiver.GetName();
		name.Replace("PanelWidget", "Render");
		ItemPreviewWidget receiver_iw = ItemPreviewWidget.Cast( receiver.FindAnyWidget(name) );
		if( receiver_iw )
			receiver_item = receiver_iw.GetItem();

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
					if( m_Entity.GetHierarchyParent() == GetGame().GetPlayer() )
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
			else if( receiver_item )
			{
				ItemBase receiver_itemIB	= ItemBase.Cast( receiver_item );
				ItemBase itemIB				= ItemBase.Cast( receiver_item );
				if( receiver_itemIB && itemIB && receiver_itemIB.CanBeCombined( itemIB ) )
				{
					ItemManager.GetInstance().HideDropzones();
					if( m_Entity.GetHierarchyParent() == GetGame().GetPlayer() )
					{
						ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
					}
					else
					{
						ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
					}
					ColorManager.GetInstance().SetColor( w, ColorManager.COMBINE_COLOR );
				}
				else if( GameInventory.CanSwapEntities( receiver_item, item ) )
				{
					ItemManager.GetInstance().HideDropzones();
					if( m_Entity.GetHierarchyParent() == GetGame().GetPlayer() )
					{
						ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
					}
					else
					{
						ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
					}
					ColorManager.GetInstance().SetColor( w, ColorManager.SWAP_COLOR );
				}
			}
			else if( m_Entity.GetInventory().CanAddAttachment( item ) )
			{
				ItemManager.GetInstance().HideDropzones();
				if( m_Entity.GetHierarchyParent() == GetGame().GetPlayer() )
				{
					ItemManager.GetInstance().GetRightDropzone().SetAlpha( 1 );
				}
				else
				{
					ItemManager.GetInstance().GetLeftDropzone().SetAlpha( 1 );
				}
				ColorManager.GetInstance().SetColor( w, ColorManager.GREEN_COLOR );
			}
			else if( ( m_Entity.GetInventory().CanAddEntityInCargo( item, item.GetInventory().GetFlipCargo() ) && (!player.GetInventory().HasEntityInInventory( item ) || !m_Entity.GetInventory().HasEntityInCargo( item )) ) || player.GetHumanInventory().HasEntityInHands( item ) )
			{
				ItemManager.GetInstance().HideDropzones();
				if( m_Entity.GetHierarchyParent() == GetGame().GetPlayer() )
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
