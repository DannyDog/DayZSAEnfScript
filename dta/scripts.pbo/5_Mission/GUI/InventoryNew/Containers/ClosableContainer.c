class ClosableContainer extends Container
{
	protected ref ClosableHeader	m_ClosableHeader;
	protected bool					m_Closed;
	protected EntityAI				m_Entity;

	void ClosableContainer( LayoutHolder parent, int sort = -1 )
	{
		m_Body				= new array<ref LayoutHolder>;
		m_ClosableHeader	= new ClosableHeader( this, "CloseButtonOnMouseButtonDown" );
		
		m_Body.Insert( m_ClosableHeader );
		
		if( sort > -1 )
			m_RootWidget.SetSort( sort + 2 );
		
		m_MainWidget = m_MainWidget.FindWidget( "body" );
	}

	void Open()
	{
		ItemManager.GetInstance().SetDefaultOpenState( m_Entity.GetType(), true );
		m_Closed = false;
		OnShow();
		m_Parent.m_Parent.Refresh();
	}
	
	void SetOpenState( bool state )
	{
		ItemManager.GetInstance().SetDefaultOpenState( m_Entity.GetType(), state );
		m_Closed = !state;
		if( !m_Closed )
		{
			OnShow();
		}
		else
		{
			OnHide();
		}
	}
	
	override Header GetHeader()
	{
		return m_ClosableHeader;
	}

	void Close()
	{
		ItemManager.GetInstance().SetDefaultOpenState( m_Entity.GetType(), false );
		m_Closed = true;
		this.OnHide();
	}

	bool IsOpened()
	{
		return !m_Closed;
	}

	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.ClosableContainer;
	}

	override void OnShow()
	{
		if( !m_Closed )
		{
			super.OnShow();
		}
	}

	override LayoutHolder Get( int x )
	{
		if( m_Body && x < m_Body.Count() && x >= 0 )
			return m_Body.Get( x );
		return null;
	}

	override void Refresh()
	{
		if( !m_Closed )
		{
			super.Refresh();
		}
	}

	void CloseButtonOnMouseButtonDown()
	{
		m_Closed = true;
		this.OnHide();
		m_Parent.m_Parent.Refresh();
	}
	
	override void SetActive( bool active )
	{
		super.SetActive( active );
		m_ClosableHeader.SetActive( active );
	}
	
	override float GetFocusedContainerHeight( bool contents = false )
	{
		float x, y;
		if( contents && GetFocusedContainer() )
			y = GetFocusedContainer().GetFocusedContainerHeight( contents );
		else if( GetRootWidget() )
			GetRootWidget().GetScreenSize( x, y );
		return y;
	}
	
	override float GetFocusedContainerYPos( bool contents = false )
	{
		float x, y;
		if( contents && GetFocusedContainer() )
			y = GetFocusedContainer().GetFocusedContainerYPos( contents );
		else if( GetRootWidget() )
			GetRootWidget().GetPos( x, y );
		return y;
	}
	
	override float GetFocusedContainerYScreenPos( bool contents = false )
	{
		float x, y;
		if( contents && GetFocusedContainer() )
			y = GetFocusedContainer().GetFocusedContainerYScreenPos( contents );
		else if( GetRootWidget() )
			GetRootWidget().GetScreenPos( x, y );
		return y;
	}
}
