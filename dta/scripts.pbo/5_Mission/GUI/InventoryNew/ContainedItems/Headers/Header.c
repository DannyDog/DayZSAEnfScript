class Header: LayoutHolder
{
	protected float			m_DefaultColor;
	protected int			m_DefaultFontSize;
	
	protected EntityAI		m_Entity;
	
	protected TextWidget	m_HeaderText;
	
	void Header( LayoutHolder parent, string function_name )
	{
		#ifndef PLATFORM_CONSOLE
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( GetMainWidget().FindAnyWidget( "collapse_button" ),  m_Parent, function_name );
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget().FindAnyWidget( "collapse_button" ),  m_Parent, "OnDropReceivedFromHeader" );
		#endif
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget(),  m_Parent, "OnDropReceivedFromHeader" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget(),  this, "DraggingOverHeader" );
		
		m_HeaderText		= TextWidget.Cast( GetMainWidget().FindAnyWidget( "TextWidget0" ) );
		
		m_DefaultColor		= GetRootWidget().GetAlpha();
	}
	
	void SetName( string name )
	{
		TextWidget text_widget = TextWidget.Cast( GetRootWidget().FindAnyWidget( "TextWidget0" ) );
		name.ToUpper();
		text_widget.SetText( name );
	}
	
	void SetItemPreview( EntityAI entity_ai )
	{
		m_Entity = entity_ai;
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( GetMainWidget().FindAnyWidget( "Render" ) );
		item_preview.SetItem(entity_ai);
		item_preview.SetView( entity_ai.GetViewIndex() );
	}
	
	void DraggingOverHeader( Widget w, int x, int y, Widget receiver )
	{
		if( w == NULL )
		{
			return;
		}
		Container parent_container = Container.Cast( m_Parent );
		parent_container.DraggingOverHeader( w, x, y, receiver );
	}

	void OnDropReceivedFromHeader( Widget w, int x, int y, Widget receiver )
	{
		Container parent_container = Container.Cast( m_Parent );
		parent_container.OnDropReceivedFromHeader( w, x, y, receiver );
	}
	
	override void SetActive( bool active )
	{
		super.SetActive( active );
		if( active )
		{
			GetMainWidget().SetAlpha( m_DefaultColor + 0.1 );
			m_HeaderText.SetTextExactSize( m_DefaultFontSize * 1.1 );
		}
		else
		{
			GetMainWidget().SetAlpha( m_DefaultColor );
			m_HeaderText.SetTextExactSize( m_DefaultFontSize );
		}
	}
}
