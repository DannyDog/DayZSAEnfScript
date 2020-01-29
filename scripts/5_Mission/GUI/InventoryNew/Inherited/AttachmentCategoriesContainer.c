class AttachmentCategoriesContainer: CollapsibleContainer
{
	protected EntityAI								m_Entity;
	protected ref map<string, int>					m_CategorySlotIndex;
	protected int									m_SlotsCount;

	void AttachmentCategoriesContainer( LayoutHolder parent, int sort = -1 )
	{
		m_CategorySlotIndex = new map<string, int>
	}
	
	void SetEntity( EntityAI entity )
	{
		m_Entity = entity;
		InitIconsContainers( entity );
		
		m_MainWidget = m_RootWidget.FindAnyWidget( "body" );
		WidgetEventHandler.GetInstance().RegisterOnChildAdd( m_MainWidget, this, "OnChildAdd" );
		WidgetEventHandler.GetInstance().RegisterOnChildRemove( m_MainWidget, this, "OnChildRemove" );
		
		InitGhostSlots( entity );
		
		( Container.Cast( m_Parent ) ).m_Body.Insert( this );
		m_Parent.Refresh();
		SetHeaderName( entity );
		RecomputeOpenedContainers();
	}

	void SetHeaderName( EntityAI entity )
	{
		Header h = Header.Cast( m_Body.Get(0) );
		h.SetName( entity.GetDisplayName() );
	}

	override void UpdateInterval()
	{
		if( m_Entity )
		{
			if( m_Entity.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ) || m_Hidden )
			{
				if( m_Body.Count() > 0 && !m_Hidden )
					m_Body.Get( 0 ).OnHide();
				HideContent();
				GetMainWidget().Show( false );
			}
			else
			{
				if( m_Body.Count() > 0 && !m_Hidden )
				{
					if( m_Body.Count() > 0 && !m_Hidden )
						m_Body.Get( 0 ).OnShow();
					for( int i = 1; i < m_Body.Count(); ++i )
					{
						LayoutHolder child = m_Body[i];
						AttachmentCategoriesRow row = AttachmentCategoriesRow.Cast( child );
						AttachmentCategoriesSlotsContainer slots = AttachmentCategoriesSlotsContainer.Cast( child );
						if( slots || ( row && m_Entity.CanDisplayAttachmentCategory( row.GetCategoryIdentifier() ) ) )
						{
							child.OnShow();
							if( row )
								ShowInSlots( row.GetCategoryIdentifier(), true );
						}
						else if( slots || row )
						{
							child.OnHide();
							if( row )
								ShowInSlots( row.GetCategoryIdentifier(), false );
						}
					}
				}
				GetMainWidget().Show( true );
			}
	
			InitGhostSlots( m_Entity );
		}
	}
	
	override void RecomputeOpenedContainers()
	{
		m_OpenedContainers.Clear();
		m_OpenedContainers.Insert( m_Body[0] );
		for ( int i = 0; i < m_Body.Count(); i++ )
		{
			ClosableContainer cnt = ClosableContainer.Cast( m_Body.Get( i ) );
			if( cnt && cnt.IsOpened() )
			{
				m_OpenedContainers.Insert( cnt );
			}
			AttachmentCategoriesSlotsContainer att_cnt = AttachmentCategoriesSlotsContainer.Cast( m_Body.Get( i ) );
			if( att_cnt )
			{
				m_OpenedContainers.Insert( att_cnt );
			}
		}
	}
	
	override void MoveGridCursor( int direction )
	{
		Container active_container = Container.Cast( m_Body.Get( m_ActiveIndex ) );
		active_container.MoveGridCursor( direction );
	}
	
	override void SetNextActive()
	{
		super.SetNextActive();
		if( m_ActiveIndex == 1 )
			m_CollapsibleHeader.SetActive( true );
		else
			m_CollapsibleHeader.SetActive( false );
	}
	
	override void SetPreviousActive( bool force = false )
	{
		super.SetPreviousActive( force );
		if( m_ActiveIndex == 1 )
			m_CollapsibleHeader.SetActive( true );
		else
			m_CollapsibleHeader.SetActive( false );
	}
	
	void LoadAttachmentCategoriesIcon( SlotsContainer items_cont, string icon_name, int slot_number )
	{
		SlotsIcon icon				= items_cont.GetSlotIcon( slot_number );
		ImageWidget image_widget	= icon.GetGhostSlot();
		image_widget.Show( true );
		image_widget.LoadImageFile( 0, "set:dayz_inventory image:" + icon_name );
		
		if( m_Body.Count() > ( slot_number + 2 ) )
		{
			ClosableContainer c = ClosableContainer.Cast( m_Body.Get( slot_number + 2 ) );
			icon.GetRadialIconPanel().Show( true );
			if( c && c.IsOpened() )
			{
				icon.GetRadialIconClosed().Show( false );
				icon.GetRadialIcon().Show( true );
			}
			else
			{
				icon.GetRadialIcon().Show( false );
				icon.GetRadialIconClosed().Show( true );
			}
		}
	}

	int GetAttachmentCategoriesCount( string config_path )
	{
		return GetGame().ConfigGetChildrenCount( config_path );
	}

	SlotsContainer GetSlotsContainer( int icons_row )
	{
		AttachmentCategoriesSlotsContainer items_cont = AttachmentCategoriesSlotsContainer.Cast( m_Body.Get( icons_row + 1 ) );
		return items_cont.GetSlotsContainer();
	}
	
	void ShowInSlots( string category, bool show )
	{
		int index						= m_CategorySlotIndex.Get( category );
		int slot_number					= index % ITEMS_IN_ROW;
		
		SlotsContainer items_cont		= GetSlotsContainer( index / ITEMS_IN_ROW );
		if( items_cont )
		{
			Widget icon_widget			= items_cont.GetSlotIcon( slot_number ).GetMainWidget();
			if( icon_widget )
				icon_widget.Show( show );
			icon_widget.GetParent().Update();
			icon_widget.GetParent().GetParent().Update();
			icon_widget.GetParent().GetParent().GetParent().Update();
		}
	}
	
	string GetAttachmentCategory( string config_path_attachment_categories, int i )
	{
		string attachment_category;
		GetGame().ConfigGetChildName(config_path_attachment_categories, i, attachment_category);
		return attachment_category;
	}

	string GetIconName( string config_path_attachment_categories, string attachment_category )
	{
		string icon_path = config_path_attachment_categories+ " " + attachment_category + " icon";
		string icon_name;
		GetGame().ConfigGetText(icon_path, icon_name);
		return icon_name;
	}
	
	int GetViewIndex( string config_path_attachment_categories, string attachment_category )
	{
		string preview_path = config_path_attachment_categories+ " " + attachment_category + " view_index";
		return GetGame().ConfigGetInt( preview_path );;
	}

	void MouseClick( Widget w )
	{
		int index = w.GetParent().GetUserID() * ITEMS_IN_ROW + w.GetUserID() + m_SlotsCount + 1;
		if( m_Body.Count() > index )
		{
			ClosableContainer c = ClosableContainer.Cast( m_Body.Get( index ) );
			if( c )
			{
				string icon_name = "RadialIcon" + ( w.GetUserID() );
				if( c.IsOpened() )
				{
					c.Close();
					w.GetParent().FindAnyWidget( icon_name ).Show( true );
				}
				else
				{
					c.Open();
					w.GetParent().FindAnyWidget( icon_name ).Show( false );
				}
			}
		}
	}
	
	void ExpandCollapseContainer()
	{
		if( m_Body.Count() > m_ActiveIndex )
		{
			AttachmentCategoriesSlotsContainer acsc = AttachmentCategoriesSlotsContainer.Cast( m_Body.Get( m_ActiveIndex ) );
			if( acsc )
			{
				int index = acsc.GetParentID() * ITEMS_IN_ROW + acsc.GetFocusedID() + m_SlotsCount + 1;
				
				ClosableContainer c = ClosableContainer.Cast( m_Body.Get( index ) );
				
				if( c )
				{
					string icon_name_open = "RadialIcon" + ( acsc.GetFocusedID() );
					string icon_name_closed = "RadialIconClosed" + ( acsc.GetFocusedID() );
					if( c.IsOpened() )
					{
						c.Close();
						acsc.GetRootWidget().FindAnyWidget( icon_name_open ).Show( true );
						acsc.GetRootWidget().FindAnyWidget( icon_name_closed ).Show( false );
					}
					else
					{
						c.Open();
						acsc.GetRootWidget().FindAnyWidget( icon_name_closed ).Show( true );
						acsc.GetRootWidget().FindAnyWidget( icon_name_open ).Show( false );
					}
					RecomputeOpenedContainers();
				}
			}
		}
	}
	
	bool IsHeaderActive()
	{
		return ( AttachmentCategoriesSlotsContainer.Cast( m_Body.Get( m_ActiveIndex ) ) != null );
	}
	
	void InitIconsContainers( EntityAI entity )
	{
		m_SlotsCount = 0;
		
		string type = entity.GetType();
		string config_path_attachment_categories = "CfgVehicles " + type + " GUIInventoryAttachmentsProps";
		int attachments_categories_count = GetAttachmentCategoriesCount( config_path_attachment_categories );
		for ( int i = 0; i < (attachments_categories_count / ITEMS_IN_ROW) + 1; i++ )
		{
			ref AttachmentCategoriesSlotsContainer items_cont = new AttachmentCategoriesSlotsContainer( this, i );
			m_Body.Insert( items_cont );
			m_OpenedContainers.Insert( items_cont );
			if( i < ( attachments_categories_count / ITEMS_IN_ROW ) )
				items_cont.GetSlotsContainer().SetColumnCount( ITEMS_IN_ROW );
			else
				items_cont.GetSlotsContainer().SetColumnCount( attachments_categories_count % ITEMS_IN_ROW );
			m_SlotsCount++;
		}
	}
	
	void InitGhostSlots( EntityAI entity )
	{
		string type = entity.GetType();
		string config_path_attachment_categories = "CfgVehicles " + type + " GUIInventoryAttachmentsProps";

		int attachments_categories_count = GetAttachmentCategoriesCount( config_path_attachment_categories );

		SlotsContainer items_cont;
		SlotsIcon icon;
		string attachment_category;
		string icon_name;
		for (int i = 0; i < attachments_categories_count; i++)
		{
			items_cont = GetSlotsContainer( i / ITEMS_IN_ROW );
			attachment_category = GetAttachmentCategory( config_path_attachment_categories, i );
			icon_name = GetIconName( config_path_attachment_categories, attachment_category );

			if( items_cont )
			{
				int slot_number = i % ITEMS_IN_ROW;
				m_CategorySlotIndex.Insert( attachment_category, i );
				icon = items_cont.GetSlotIcon( slot_number );
				icon.GetGhostSlot().SetFlags( WidgetFlags.IGNOREPOINTER );
				
				LoadAttachmentCategoriesIcon( items_cont, icon_name, slot_number );
				
				int num = i + 2 + attachments_categories_count / ITEMS_IN_ROW;
				if( m_Body.Count() > num )
				{
					ClosableContainer c = ClosableContainer.Cast( m_Body.Get( num ) );
					icon.GetRadialIconPanel().Show( true );
					Widget rad_ic = icon.GetRadialIcon();
					rad_ic.Show( !c.IsOpened() );
					icon.GetRadialIconClosed().Show( c.IsOpened() );
				}
				
				AttachmentCategoriesRow ar;
				int count = attachments_categories_count + 2 + attachments_categories_count / ITEMS_IN_ROW;
				if( m_Body.Count() < count )
				{
					ar = new AttachmentCategoriesRow( this, -1 );
				}
				else
				{
					ar = AttachmentCategoriesRow.Cast( m_Body.Get( i + 2 + attachments_categories_count / ITEMS_IN_ROW ) );
				}
				
				ar.Init(attachments_categories_count, i, attachment_category, config_path_attachment_categories, entity,m_Body.Count() );
				
				if( m_Body.Count() < count )
				{
					this.Insert(ar);
				}
			}
		}
		
		if( m_Body.Count() < attachments_categories_count + 3 + attachments_categories_count / ITEMS_IN_ROW )
		{
			if( entity.GetInventory().GetCargo() )
			{
				items_cont = GetSlotsContainer( attachments_categories_count / ITEMS_IN_ROW );
				if( items_cont )
				{
					icon = items_cont.GetSlotIcon( attachments_categories_count );
					icon.GetGhostSlot().Show( true );
					icon.GetGhostSlot().LoadImageFile( 0, "set:dayz_inventory image:cat_common_cargo" );
					icon.GetGhostSlot().SetFlags( WidgetFlags.IGNOREPOINTER );
					
					icon.GetRadialIconPanel().Show( true );
					icon.GetMainWidget().Show( true );
				}
				
				ContainerWithCargo iwc = new ContainerWithCargo( this, -1 );
				iwc.Get( 0 ).GetRootWidget().ClearFlags( WidgetFlags.DRAGGABLE );
				iwc.SetEntity( entity );
				Insert( iwc );
			}
		}
		else
		{
			ContainerWithCargo iwc2 = ContainerWithCargo.Cast( m_Body.Get(attachments_categories_count + 2 + attachments_categories_count / ITEMS_IN_ROW ) );
			iwc2.UpdateInterval();
			
			icon = items_cont.GetSlotIcon( attachments_categories_count );
			icon.GetMainWidget().Show( true );
			icon.GetRadialIconPanel().Show( true );
			if( iwc2.IsOpened() )
			{
				icon.GetRadialIcon().Show( false );
				icon.GetRadialIconClosed().Show( true );
			}
			else
			{
				icon.GetRadialIcon().Show( true );
				icon.GetRadialIconClosed().Show( false );
			}
		}
	}

	override void OnDropReceivedFromHeader( Widget w, int x, int y, Widget receiver )
	{
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
		if( !iw.GetItem() )
			return;
		if( m_Entity.GetInventory().CanAddAttachment( iw.GetItem() ) && iw.GetItem().GetInventory().CanRemoveEntity() )
		{
			GetGame().GetPlayer().PredictiveTakeEntityToTargetAttachment( m_Entity, iw.GetItem() );
		}
		else if( m_Entity.GetInventory().CanAddEntityToInventory( iw.GetItem() ) && iw.GetItem().GetInventory().CanRemoveEntity() )
		{
			GetGame().GetPlayer().PredictiveTakeEntityToTargetInventory( m_Entity, FindInventoryLocationType.ANY, iw.GetItem() );
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
		
		ItemManager.GetInstance().ShowSourceDropzone( iw.GetItem() );
		ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
	}
	
	override void CollapseButtonOnMouseButtonDown(Widget w)
	{
		super.CollapseButtonOnMouseButtonDown(w);
		RecomputeOpenedContainers();
	}
}
