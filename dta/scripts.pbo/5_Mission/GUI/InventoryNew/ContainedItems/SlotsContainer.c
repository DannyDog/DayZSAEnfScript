class SlotsContainer: LayoutHolder
{
	protected int						m_ColumnCount;
	protected ref array<ref SlotsIcon>	m_Icons;
	
	void SlotsContainer( LayoutHolder parent ) 
	{
		m_Icons = new array<ref SlotsIcon>;
		for( int i = 0; i < ITEMS_IN_ROW; i++ )
		{
			if( GetRootWidget().FindAnyWidget( "Icon" + i ) )
				m_Icons.Insert( new SlotsIcon( this, GetRootWidget().FindAnyWidget( "Icon" + i ), i ) );
			else
			{
				Widget child = GetRootWidget().GetChildren();
				while( child )
				{
					Print( child.GetName() );
					child = child.GetSibling();
				}
			}
		}
	}

	void SetColumnCount( int column_count )
	{
		m_ColumnCount = column_count;
	}

	int GetColumnCount()
	{
		return m_ColumnCount;
	}
	
	SlotsIcon GetSlotIcon( int index )
	{
		if( m_Icons.IsValidIndex( index ) )
		{
			return m_Icons.Get( index );
		}
		
		return null;
	}

	override void SetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
			m_LayoutName = WidgetLayoutName.InventorySlotsContainerXbox;
		#else
			switch( InventoryMenu.GetWidthType() )
			{
				case ScreenWidthType.NARROW:
				{
					m_LayoutName = WidgetLayoutName.InventorySlotsContainerNarrow;
					break;
				}
				case ScreenWidthType.MEDIUM:
				{
					m_LayoutName = WidgetLayoutName.InventorySlotsContainerMedium;
					break;
				}
				case ScreenWidthType.WIDE:
				{
					m_LayoutName = WidgetLayoutName.InventorySlotsContainerWide;
					break;
				}
			}
		#endif
			
	}
}