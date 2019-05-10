class OptionSelectorSlider extends OptionSelectorBase
{
	protected SliderWidget			m_Slider;
	protected float					m_MinValue;
	protected float					m_MaxValue;
	
	void OptionSelectorSlider( Widget parent, float value, ScriptedWidgetEventHandler parent_menu, bool disabled, float min, float max )
	{
		m_Root					= GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/option_slider.layout", parent );
		#ifdef PLATFORM_CONSOLE
			m_Parent				= parent.GetParent().GetParent();
		#else
		#ifdef PLATFORM_WINDOWS
			m_Parent				= parent.GetParent();
		#endif
		#endif
		
		m_SelectorType				= 1;
		m_ParentClass				= parent_menu;
		m_Slider					= SliderWidget.Cast( m_Root.FindAnyWidget( "option_value" ) );
		m_Slider.SetCurrent( value );
		
		//m_DisablePanel				= m_Parent.GetParent().FindAnyWidget( m_Parent.GetName() + "_disable" );
		
		/*
		if ( !m_DisablePanel )
		{
			Print("Cant found disable panel: "+ m_Parent.GetName() );
		}
		*/
		m_MinValue					= min;
		m_MaxValue					= max;
		
		SetValue( value );
		Enable();
		/*
		m_Enabled = !disabled;
		if( m_Enabled )
		{
			Enable();
		}
		else
		{
			Disable();
		}
		*/
		
		//#ifdef PLATFORM_CONSOLE
		m_Parent.SetHandler( this );
		//#endif
	}
	
	void ~OptionSelectorSlider()
	{
		delete m_Root;
	}
	
	override void Enable()
	{
		super.Enable();
		
		m_Slider.ClearFlags( WidgetFlags.IGNOREPOINTER );
	}
	
	override void Disable()
	{
		super.Disable();
		
		m_Slider.SetFlags( WidgetFlags.IGNOREPOINTER );
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( m_ParentClass )
		{
			m_ParentClass.OnMouseEnter( m_Root.GetParent().GetParent(), x, y );
			ColorHighlight(w);
		}
		
		return true;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( m_ParentClass )
		{
			m_ParentClass.OnMouseLeave( m_Root.GetParent().GetParent(), enterW, x, y );
			ColorNormal( w );
		}
			
		return true;
	}
	
	override bool OnMouseButtonUp( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT && w == m_Slider )
		{
			Print( m_Slider.GetCurrent() );
		}
		return false;
	}
	
	override bool OnChange( Widget w, int x, int y, bool finished )
	{
		if( w == m_Slider )
		{
			m_OptionChanged.Invoke( GetValue() );
			return true;
		}
		return false;
	}
	
	override bool IsFocusable( Widget w )
	{
		if( w )
		{
			return ( w == m_Parent || w == m_Slider );
		}
		return false;
	}
	
	override bool OnFocus( Widget w, int x, int y )
	{
		#ifdef PLATFORM_CONSOLE
		Print("Slider Option OnFocus: "+ w.GetName());
		if( GetFocus() != m_Slider )
		{
			SetFocus( m_Slider );
			m_Parent.Enable( false );
		}
		
		return super.OnFocus( m_Parent, x, y );
		
		#else
		return false;
		#endif
	}
	
	override bool OnFocusLost( Widget w, int x, int y )
	{
		if( w == m_Slider )
		{
			m_Parent.Enable( true );
			return super.OnFocusLost( m_Parent, x, y );
		}
		return false;
	}
	
	float NormalizeInput( float value )
	{
		float ret = ( value - m_MinValue) / ( m_MaxValue - m_MinValue );
		return ret;
	}
	
	void SetValue( float value, bool update = true )
	{
		m_Slider.SetCurrent( NormalizeInput( value ) );
		if( update )
			m_OptionChanged.Invoke( GetValue() );
	}
	
	float GetValue()
	{
		float ret = ( m_Slider.GetCurrent() * ( m_MaxValue - m_MinValue ) ) + m_MinValue;
		return ret;
	}
	
	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		//SliderWidget slider = SliderWidget.Cast( w.FindAnyWidget("option_value") );
		
		if ( m_Slider )
		{
			SetFocus( m_Slider );
			m_Slider.SetColor( ARGB(255, 200, 0, 0) );
		}
		
		super.ColorHighlight( w );
	}
	
	override void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		//SliderWidget slider = SliderWidget.Cast( w.FindAnyWidget("option_value") );
		
		if ( m_Slider )
		{
			m_Slider.SetColor( ARGB(140, 255, 255, 255) );
		}
		
		super.ColorNormal( w );
	}
}