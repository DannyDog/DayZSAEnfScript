class HandsPreview: LayoutHolder
{
	protected ref Icon	m_Icon;
	protected EntityAI	m_AttachmentsInitialized;
	
	protected float		m_IconSize;

	protected EntityAI	m_Item

	void HandsPreview( LayoutHolder parent )
	{
	}

	void RefreshQuantity( EntityAI m_Item_to_refresh )
	{
		if( m_Icon )
		{
			m_Icon.RefreshQuantity();
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

		PlayerBase p = PlayerBase.Cast( GetGame().GetPlayer() );
		if( !p )
			return;
		m_Item = p.GetHumanInventory().GetEntityInHands();
		if ( ( !m_Item && m_Icon ) || ( m_Icon && m_Item != m_Icon.GetObject() ) )
		{
			RemoveItem();
			( HandsContainer.Cast( m_Parent ) ).RemoveItem();
			( HandsContainer.Cast( m_Parent ) ).DestroyAtt();
			( HandsContainer.Cast( m_Parent ) ).DestroyCargo();
			m_AttachmentsInitialized = null;
			m_RootWidget.SetColor( ARGB( 166, 80, 80, 80 ) );
			m_Parent.GetParent().Refresh();
		}
		else if( m_Item && !m_Icon )
		{
			CreateNewIcon();
			m_RootWidget.SetColor( ARGB( 180, 0, 0, 0 ) );
			m_Parent.GetParent().Refresh();
		}
		else if ( m_Icon )
		{
			m_Icon.UpdateInterval();
		}

		HandsContainer parent = HandsContainer.Cast( m_Parent );
		Header header = parent.GetHeader();

		if( m_Item )
		{
			string display_name = m_Item.GetDisplayName();
			display_name.ToUpper();
			header.SetName( display_name );
		}
		else
		{
			header.SetName( "#str_widget_textwidget00" );
		}
	}

	protected void CreateNewIcon()
	{
		float y;
		GetMainWidget().GetScreenSize( m_IconSize, y );
		m_IconSize = m_IconSize / 10;
		
		m_Icon = new Icon( this, true );
		m_Icon.Refresh();
		if( m_Icon )
		{
			Weapon_Base wpn;
			if ( Class.CastTo(wpn,  m_Item ) )
			{
				int mi = wpn.GetCurrentMuzzle();
				m_Icon.GetMainWidget().FindAnyWidget( "AmmoIcon" ).Show(  wpn.IsChamberFull( mi )  );
			}

			m_Icon.Init( m_Item );
			if( m_Item != m_AttachmentsInitialized )
			{
				( HandsContainer.Cast( m_Parent ) ).RemoveItem();
				( HandsContainer.Cast( m_Parent ) ).DestroyAtt();
				( HandsContainer.Cast( m_Parent ) ).DestroyCargo();
				( HandsContainer.Cast( m_Parent ) ).ShowAtt( m_Item );
				m_AttachmentsInitialized = m_Item;
			}
			
			m_Icon.FullScreen();
			m_Icon.Refresh();
		}
	}
}
