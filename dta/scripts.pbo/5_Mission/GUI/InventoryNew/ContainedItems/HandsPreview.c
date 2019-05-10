class HandsPreview: LayoutHolder
{
	protected ref Icon	m_Icon;
	protected EntityAI	m_AttachmentsInitialized;
	
	protected float		m_IconSize;

	protected ItemBase	m_Item

	void HandsPreview( LayoutHolder parent )
	{
		GetGame().GetPlayer().GetOnItemAddedToHands().Insert( CreateNewIcon );
		GetGame().GetPlayer().GetOnItemRemovedFromHands().Insert( DeleteIcon );
		
		m_Item = ItemBase.Cast( GetGame().GetPlayer().GetHumanInventory().GetEntityInHands() );
		if( m_Item )
			CreateNewIcon( ItemBase.Cast( m_Item ) );
	}
	
	void ~HandsPreview()
	{
		GetGame().GetPlayer().GetOnItemAddedToHands().Remove( CreateNewIcon );
		GetGame().GetPlayer().GetOnItemRemovedFromHands().Remove( DeleteIcon );
	}

	void RefreshQuantity( EntityAI m_Item_to_refresh )
	{
		if( m_Icon )
		{
			m_Icon.SetQuantity();
		}
	}

	Icon GetIcon()
	{
		return m_Icon;
	}
	
	float GetIconSize()
	{
		return m_IconSize;
	}

	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.HandsPreview;
	}

	void RemoveItem()
	{
		delete m_Icon;
	}

	override void UpdateInterval()
	{
		bool show_combine_swap = ItemManager.GetInstance().IsDragging();

		#ifndef PLATFORM_CONSOLE
		if( m_Icon && !m_Icon.IsDragged() )
		{
			m_Icon.GetMainWidget().FindAnyWidget( "Combine" ).Show(  show_combine_swap );
			m_Icon.GetMainWidget().FindAnyWidget( "Swap" ).Show( show_combine_swap );
		}
		#endif
		
		if ( m_Icon )
		{
			m_Icon.UpdateInterval();
		}
	}

	void CreateNewIcon( ItemBase item )
	{
		float y;
		GetRootWidget().GetParent().GetParent().GetParent().GetParent().GetScreenSize( m_IconSize, y );
		m_IconSize = m_IconSize / 10;
		
		m_Icon = new Icon( this, true );
		m_Icon.Refresh();
		if( m_Icon )
		{
			m_Item = item;
			m_Icon.Init( m_Item );
			m_Icon.FullScreen();
			( HandsContainer.Cast( m_Parent ) ).ShowAtt( m_Item );
			m_Icon.Refresh();
		}
		
		m_RootWidget.SetColor( ARGB( 180, 0, 0, 0 ) );
		m_Parent.GetParent().Refresh();
		Inventory.GetInstance().UpdateConsoleToolbar();
		
		HandsContainer parent = HandsContainer.Cast( m_Parent );
		HandsHeader header = HandsHeader.Cast( parent.GetHeader() );

		if( m_Item && !m_Item.GetInventory().GetCargo() )
		{
			string display_name = m_Item.GetDisplayName();
			display_name.ToUpper();
			header.SetName( display_name );
		}
	}
	
	void DeleteIcon()
	{
		RemoveItem();
		( HandsContainer.Cast( m_Parent ) ).RemoveItem();
		( HandsContainer.Cast( m_Parent ) ).DestroyAtt();
		( HandsContainer.Cast( m_Parent ) ).DestroyCargo();
		m_AttachmentsInitialized = null;
		m_RootWidget.SetColor( ARGB( 166, 80, 80, 80 ) );
		m_Parent.GetParent().Refresh();
		Inventory.GetInstance().UpdateConsoleToolbar();
	}
}
