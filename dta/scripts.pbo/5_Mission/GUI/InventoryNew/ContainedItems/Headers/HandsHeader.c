class HandsHeader: Header
{
	bool	m_ForceHideCollapseButtons;
	Widget	m_ItemHeader;
	Widget	m_CollapseButton;
	
	void HandsHeader( LayoutHolder parent, string function_name )
	{
		m_DefaultFontSize	= 24;
		m_ItemHeader		= m_MainWidget.FindAnyWidget( "hands_item_header" );
		m_CollapseButton	= m_MainWidget.FindAnyWidget( "collapse_button" );
		m_HeaderText		= TextWidget.Cast( GetMainWidget().FindAnyWidget( "hands_title" ) );
		
		m_MainWidget		= GetMainWidget().FindAnyWidget( "height_wrapper" );
		m_DefaultColor		= GetMainWidget().GetAlpha();
	}
	
	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.HandsHeader;
	}
	
	override void UpdateInterval()
	{
		PlayerBase p = PlayerBase.Cast( GetGame().GetPlayer() );
		if(!p)
			return;
		EntityAI item = p.GetHumanInventory().GetEntityInHands();
		if( !m_ForceHideCollapseButtons )
		{
			if( item && !item.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ) )
			{
				ShowCollapseButtons( true );
			}
			else
			{
				ShowCollapseButtons( false );
			}
		}
		m_ItemHeader.Show( item != null );
	}
	
	void ShowCollapseButtons( bool show, bool force = false )
	{
		m_ForceHideCollapseButtons = force;
		m_CollapseButton.Show( show );
	}
}
