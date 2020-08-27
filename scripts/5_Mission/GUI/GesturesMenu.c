enum GestureCategories
{
	CATEGORIES,				//special category selection
	CATEGORY_1,
	CATEGORY_2,
	CATEGORY_3,
	CATEGORY_4,
	CATEGORY_5,
	CONSOLE_GESTURES
}

class GestureMenuItem
{
	protected int 					m_ID;
	protected string 				m_Name;
	protected GestureCategories 	m_Category;
	protected bool 					m_CanPerformEmote;
	//radial menu
	protected Widget 				m_RadialMenuSelector;
	protected Widget				m_RadialMenuItemCard;
	
	void GestureMenuItem( int id, string name, GestureCategories category )
	{
		m_ID				= id;
		m_Name 				= name;
		m_Category 			= category;
		m_CanPerformEmote 	= true;
	}
	
	string GetName()
	{
		return m_Name;
	}
	
	int GetID()
	{
		return m_ID;
	}
	
	GestureCategories GetCategory()
	{
		return m_Category;
	}
	
	Widget GetRadialItemCard()
	{
		return m_RadialMenuItemCard;
	}
	
	void SetRadialItemCard( Widget widget )
	{
		m_RadialMenuItemCard = widget;
	}
	
	void SetCanPerformEmote(bool state)
	{
		m_CanPerformEmote = state;
	}
	
	bool GetCanPerformEmote()
	{
		return m_CanPerformEmote;
	}
}

class GesturesMenu extends UIScriptedMenu
{
	protected Widget 							m_GestureItemCardPanel;
	protected ref array<ref GestureMenuItem> 	m_GestureItems;
	
	protected TextWidget						m_CategoryNameText;
	
	//
	const string 								RADIAL_TEXT		= "RadialText";
	const string 								CATEGORY_NAME	= "CategoryName";
	//selections
	protected Widget 							m_SelectedItem;
	protected bool 								m_IsCategorySelected;
	protected bool 								m_IsMenuClosing;
	protected int 								m_CurrentCategory;
	
	//instance
	static GesturesMenu							instance;
	
	//============================================
	// GesturesMenu
	//============================================
	void GesturesMenu()
	{
		m_GestureItems = new ref array<ref GestureMenuItem>;
		
		if ( !instance )
		{
			instance = this;
		}
	}
	
	void ~GesturesMenu()
	{
	}

	//============================================
	// Menu Controls
	//============================================	
	static void OpenMenu()
	{
		GetGame().GetUIManager().EnterScriptedMenu( MENU_GESTURES, NULL );
	}
	
	static void CloseMenu()
	{
		//execute on menu release
		instance.OnMenuRelease();
		
		GetGame().GetUIManager().Back();
	}
		
	//============================================
	// Init & Widget Events
	//============================================
	override Widget Init()
	{
		m_CurrentCategory = -1;
		
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "gui/layouts/radial_menu/radial_gestures/day_z_gestures.layout" );
		m_GestureItemCardPanel = layoutRoot.FindAnyWidget( RadialMenu.RADIAL_ITEM_CARD_CONTAINER );
		
		//register gestures menu
		RadialMenu.GetInstance().RegisterClass( this );
		
		//delay updates until fully initialized
		RadialMenu.GetInstance().SetWidgetInitialized(false);
		
		//set radial menu properties
		RadialMenu.GetInstance().SetWidgetProperties( "gui/layouts/radial_menu/radial_gestures/day_z_gesture_delimiter.layout" );
		
		//create content (widgets) for items
		RefreshGestures();
		
#ifdef PLATFORM_WINDOWS
		Widget toolbar_panel = layoutRoot.FindAnyWidget( "toolbar_bg" );
		toolbar_panel.Show( !RadialMenu.GetInstance().IsUsingMouse() );
#endif	
		
		//clear category name text
		UpdateCategoryName( "" );
		
		return layoutRoot;
	}
	
	override void OnShow()
	{
		super.OnShow();
		
		SetFocus( layoutRoot );
		m_IsMenuClosing = false;
	}
	
	override bool OnController( Widget w, int control, int value )
	{
		super.OnController( w, control, value );
		
		RadialMenu.GetInstance().SetControlType( RadialMenuControlType.CONTROLLER );

		return false;
	}	
		
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		super.OnMouseEnter( w, x, y );
		
		RadialMenu.GetInstance().SetControlType( RadialMenuControlType.MOUSE );

		return false;
	}
	
	override bool UseMouse()
	{
		return true;
	}
	
	override bool UseGamepad()
	{
		return true;
	}
	
	override void Update(float timeslice)
	{
		super.Update(timeslice);
		
		//RefreshGestures(m_CurrentCategory);
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if (m_CurrentCategory != GestureCategories.CATEGORIES && m_CurrentCategory != -1 && player)
		{
			for (int i = 0; i < m_GestureItems.Count(); i++)
			{
				UpdateQuickbarItemCard(m_GestureItems[i]);
			}
		}
	}
	
	void ProcessEmoteConditionRequest(GestureMenuItem gesture_item)
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if (player && m_CurrentCategory != -1)
		{
			bool can = player.GetEmoteManager().CanPlayEmote(gesture_item.GetID());
			gesture_item.SetCanPerformEmote(can);
		}
	}
	
	//============================================
	// Gestures
	//============================================
	protected void RefreshGestures( GestureCategories category_id = -1 )
	{
		//create gestures content (widgets) based on categories
		if ( category_id > -1 )
		{
			GetGestureItems( m_GestureItems, category_id);
			m_CurrentCategory = category_id;
		}
		else
		{
			GetGestureItems( m_GestureItems, GestureCategories.CATEGORIES );
			m_CurrentCategory = -1;
		}
		
		CreateGestureContent();
		
		UpdateToolbar();
	}
	
	protected void GetGestureItems( out ref array<ref GestureMenuItem> gesture_items, GestureCategories category )
	{
		gesture_items.Clear();
		
		//PC PLATFORM
		//All categories
		if ( category == GestureCategories.CATEGORIES )
		{
			gesture_items.Insert( new GestureMenuItem( GestureCategories.CATEGORY_1, "#STR_USRACT_EMOTE_CATEGORY_COMMS", 	GestureCategories.CATEGORIES ) );
			gesture_items.Insert( new GestureMenuItem( GestureCategories.CATEGORY_2, "#STR_USRACT_EMOTE_CATEGORY_TAUNTS", 	GestureCategories.CATEGORIES ) );
			gesture_items.Insert( new GestureMenuItem( GestureCategories.CATEGORY_3, "#STR_USRACT_EMOTE_CATEGORY_MISC", 	GestureCategories.CATEGORIES ) );
			gesture_items.Insert( new GestureMenuItem( GestureCategories.CATEGORY_4, "#STR_USRACT_EMOTE_CATEGORY_REGARDS", 	GestureCategories.CATEGORIES ) );
			//gesture_items.Insert( new GestureMenuItem( GestureCategories.CATEGORY_5, "Tactical?", 	GestureCategories.CATEGORIES ) );
		}
		//Category 1 - comms
		else if ( category == GestureCategories.CATEGORY_1 )
		{
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_TIMEOUT,	"#STR_USRACT_ID_EMOTE_TIMEOUT", 	GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_POINTSELF, 	"#STR_USRACT_ID_EMOTE_POINTSELF",	GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_WATCHING, 	"#STR_USRACT_ID_EMOTE_WATCHING", 	GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_HOLD, 		"#STR_USRACT_ID_EMOTE_HOLD", 		GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_LISTENING, 	"#STR_USRACT_ID_EMOTE_LISTENING", 	GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_SILENT, 	"#STR_USRACT_ID_EMOTE_SILENT", 		GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_POINT, 		"#STR_USRACT_ID_EMOTE_POINT", 		GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_MOVE, 		"#STR_USRACT_ID_EMOTE_MOVE", 		GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_DOWN, 		"#STR_USRACT_ID_EMOTE_DOWN", 		GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_COME, 		"#STR_USRACT_ID_EMOTE_COME", 		GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_NOD, 		"#STR_USRACT_ID_EMOTE_NOD", 		GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_SHAKE, 		"#STR_USRACT_ID_EMOTE_SHAKE", 		GestureCategories.CATEGORY_1 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_SHRUG, 		"#STR_USRACT_ID_EMOTE_SHRUG", 		GestureCategories.CATEGORY_1 ) );
		}
		//Category 2 - taunt
		else if ( category == GestureCategories.CATEGORY_2 )
		{
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_LOOKATME, 	"#STR_USRACT_ID_EMOTE_LOOKATME", 	GestureCategories.CATEGORY_2 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_TAUNT, 		"#STR_USRACT_ID_EMOTE_TAUNT", 		GestureCategories.CATEGORY_2 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_TAUNTELBOW, "#STR_USRACT_ID_EMOTE_TAUNTELBOW", 	GestureCategories.CATEGORY_2 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_THROAT, 	"#STR_USRACT_ID_EMOTE_THROAT", 		GestureCategories.CATEGORY_2 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_TAUNTTHINK, "#STR_USRACT_ID_EMOTE_TAUNTTHINK", 	GestureCategories.CATEGORY_2 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_FACEPALM, 	"#STR_USRACT_ID_EMOTE_FACEPALM", 	GestureCategories.CATEGORY_2 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_THUMBDOWN, 	"#STR_USRACT_ID_EMOTE_THUMBDOWN", 	GestureCategories.CATEGORY_2 ) );
		}
		//Category 3 - misc
		else if ( category == GestureCategories.CATEGORY_3 )
		{
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_DANCE, 		"#STR_USRACT_ID_EMOTE_DANCE", 		GestureCategories.CATEGORY_3 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_LYINGDOWN, 	"#STR_USRACT_ID_EMOTE_LYINGDOWN", 	GestureCategories.CATEGORY_3 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_SOS, 		"#STR_USRACT_ID_EMOTE_SOS", 		GestureCategories.CATEGORY_3 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_RPS, 		"#STR_USRACT_ID_EMOTE_RPS", 		GestureCategories.CATEGORY_3 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_SITA, 		"#STR_USRACT_ID_EMOTE_SITA", 		GestureCategories.CATEGORY_3 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_SITB, 		"#STR_USRACT_ID_EMOTE_SITB", 		GestureCategories.CATEGORY_3 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_SUICIDE, 	"#STR_USRACT_ID_EMOTE_SUICIDE", 	GestureCategories.CATEGORY_3 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_CAMPFIRE, 	"#STR_USRACT_ID_EMOTE_CAMPFIRE", 	GestureCategories.CATEGORY_3 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_SURRENDER, 	"#STR_USRACT_ID_EMOTE_SURRENDER", 	GestureCategories.CATEGORY_3 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_VOMIT, 		"#STR_USRACT_ID_EMOTE_VOMIT", 		GestureCategories.CATEGORY_3 ) );
			//gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_RPS_R, 	"#STR_USRACT_ID_EMOTE_RPS_R", 		GestureCategories.CATEGORY_3 ) );
			//gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_RPS_P, 	"#STR_USRACT_ID_EMOTE_RPS_P", 		GestureCategories.CATEGORY_3 ) );
			//gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_RPS_S, 	"#STR_USRACT_ID_EMOTE_RPS_S", 		GestureCategories.CATEGORY_3 ) );
		}
		//Category 4 - regards
		else if ( category == GestureCategories.CATEGORY_4 )
		{
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_GREETING, 	"#STR_USRACT_ID_EMOTE_GREETING", 	GestureCategories.CATEGORY_4 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_THUMB, 		"#STR_USRACT_ID_EMOTE_THUMB", 		GestureCategories.CATEGORY_4 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_HEART, 		"#STR_USRACT_ID_EMOTE_HEART", 		GestureCategories.CATEGORY_4 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_CLAP, 		"#STR_USRACT_ID_EMOTE_CLAP", 		GestureCategories.CATEGORY_4 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_TAUNTKISS, 	"#STR_USRACT_ID_EMOTE_TAUNTKISS", 	GestureCategories.CATEGORY_4 ) );
			gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_SALUTE, 	"#STR_USRACT_ID_EMOTE_SALUTE", 		GestureCategories.CATEGORY_4 ) );
			//gesture_items.Insert( new GestureMenuItem( EmoteConstants.ID_EMOTE_DEBUG, 		"ID_EMOTE_DEBUG", 					GestureCategories.CATEGORY_4 ) );
		}
	}
	
	protected void CreateGestureContent()
	{
		//delete existing gesture widgets
		DeleteGestureItems();
		
		for ( int i = 0; i < m_GestureItems.Count(); ++i )
		{
			GestureMenuItem gesture_item = m_GestureItems.Get( i );
			
			//create item card
			Widget gesture_item_card_widget = Widget.Cast( GetGame().GetWorkspace().CreateWidgets( "gui/layouts/radial_menu/radial_gestures/day_z_gesture_item_card.layout", m_GestureItemCardPanel ) );
			gesture_item.SetRadialItemCard( gesture_item_card_widget );
			
			//update item card widget
			UpdateQuickbarItemCard( gesture_item );
			
			//set data
			gesture_item_card_widget.SetUserData( gesture_item );
		}
		
		//set radial parameters for content
		if ( m_GestureItems.Count() > 0 ) 
		{
			RadialMenu radial_menu = RadialMenu.GetInstance();
			radial_menu.SetRadiusOffset( 0 );
			radial_menu.SetExecuteDistOffset( 0.5 );
			radial_menu.SetOffsetFromTop( 0 );
			radial_menu.SetItemCardRadiusOffset( 0.25 );
			radial_menu.ActivateControllerTimeout( false );
		}
		
		//refresh radial menu
		RadialMenu.GetInstance().Refresh();
	}
	
	protected void UpdateQuickbarItemCard( GestureMenuItem gesture_item )
	{
		Widget gesture_item_card_widget = gesture_item.GetRadialItemCard();
		
		//set text
		ButtonWidget name_widget = ButtonWidget.Cast( gesture_item_card_widget.FindAnyWidget( RADIAL_TEXT ) );
		name_widget.SetText( gesture_item.GetName() );
		ProcessEmoteConditionRequest(gesture_item);
		if (gesture_item.GetCanPerformEmote())
		{
			gesture_item_card_widget.SetFlags(WidgetFlags.DISABLED); //flag just seems to be...'there', useful for showing radial selector. Still...
			name_widget.SetTextColor(ARGB(255,255,255,255));
		}
		else
		{
			gesture_item_card_widget.ClearFlags(WidgetFlags.DISABLED);
			name_widget.SetTextColor(ARGB(255,150,150,150));
		}
	} 
	
	protected void DeleteGestureItems()
	{
		Widget child;
		Widget child_to_destroy;
		
		child = m_GestureItemCardPanel.GetChildren();
		while ( child )
		{
			child_to_destroy = child;
			child = child.GetSibling();
			
			delete child_to_destroy;
		}		
	}
	
	protected void UpdateToolbar()
	{
		#ifdef PLATFORM_CONSOLE
			//set controller toolbar icons
			string select_img;
			//string back_img;
	
			ImageWidget toolbar_select = ImageWidget.Cast( layoutRoot.FindAnyWidget( "SelectIcon" ) );
			//ImageWidget toolbar_back = ImageWidget.Cast( layoutRoot.FindAnyWidget( "BackIcon" ) );
							 
			if ( instance.m_IsCategorySelected )
			{
				#ifdef PLATFORM_XBOX
					select_img = "set:xbox_buttons image:A";
					//back_img = "set:xbox_buttons image:B";
				#endif		
				#ifdef PLATFORM_PS4
					string confirm = "cross";
					if( GetGame().GetInput().GetEnterButton() == GamepadButton.A )
					{
						confirm = "cross";
					}
					else
					{
						confirm = "circle";
					}
					select_img = "set:playstation_buttons image:" + confirm;
					//back_img = "set:playstation_buttons image:circle";
				#endif
			}
			else
			{
				#ifdef PLATFORM_XBOX
					select_img = "set:xbox_buttons image:R_up";
					//back_img = "set:xbox_buttons image:B";
				#endif		
				#ifdef PLATFORM_PS4
					select_img = "set:playstation_buttons image:R_up";
					//back_img = "set:playstation_buttons image:circle";
				#endif				
			}
			
			toolbar_select.LoadImageFile( 0, select_img );
			//toolbar_back.LoadImageFile( 0, back_img );
		#endif
	}
	
	protected void UpdateCategoryName( string name )
	{
		if ( !m_CategoryNameText )
		{
			m_CategoryNameText = TextWidget.Cast( layoutRoot.FindAnyWidget( CATEGORY_NAME ) );
		}
		
		m_CategoryNameText.SetText( name );
	}
	
	//============================================
	// Radial Menu Events
	//============================================
	//Common
	void OnControlsChanged( RadialMenuControlType type )
	{
		//show/hide controller toolbar
		Widget toolbar_panel = layoutRoot.FindAnyWidget( "toolbar_bg" );
		if ( type == RadialMenuControlType.CONTROLLER )
		{
#ifdef PLATFORM_CONSOLE
			toolbar_panel.Show( true );
#endif
		}
		else
		{
			toolbar_panel.Show( false );
		}
	}
	
	//Mouse
	void OnMouseSelect( Widget w )
	{
		MarkSelected( w );
	}

	void OnMouseDeselect( Widget w )
	{
		UnmarkSelected( w );
	}

	void OnMouseExecute( Widget w )
	{
		ExecuteSelectedCategory( w );
	}
			
	//Controller
	void OnControllerSelect( Widget w )
	{
		MarkSelected( w );
	}

	void OnControllerDeselect( Widget w )
	{
		UnmarkSelected( w );
	}

	void OnControllerExecute( Widget w )
	{
		ExecuteSelectedCategory( w );
	}
	
	void OnControllerPressSelect( Widget w )
	{
		ExecuteSelectedItem();
	}
	
	void OnControllerPressBack( Widget w )
	{
		//back to category or close menu?
		/*
		if ( instance.m_IsCategorySelected )
		{
			instance.m_IsCategorySelected = false; 		//reset category selection
			RefreshGestures();							//back to categories
		}
		else
		{
			//close menu
			CloseMenu();
		}
		*/
	}		
	
	//Gestures Menu
	protected void OnMenuRelease()
	{
		//execute on release (mouse only)
		if ( RadialMenu.GetInstance().IsUsingMouse() )
		{
			ExecuteSelectedItem();
		}
	}
	
	//Actions
	protected void MarkSelected( Widget w )
	{
		instance.m_SelectedItem = w;
		
		if ( w )
		{
			GestureMenuItem gesture_item;
			w.GetUserData( gesture_item );

			//is not category
			/*
			if ( gesture_item && gesture_item.GetCategory() != GestureCategories.CATEGORIES )
			{	
				//alter item visual
				//TextWidget text_widget = TextWidget.Cast( gesture_item.GetRadialItemCard().FindAnyWidget( RADIAL_TEXT ) );
				//text_widget.SetColor( ARGB( 255, 66, 175, 95 ) );
			}
			*/	
		}
	}
	
	protected void UnmarkSelected( Widget w )
	{
		instance.m_SelectedItem = NULL;
		
		if ( w )
		{
			GestureMenuItem gesture_item;
			w.GetUserData( gesture_item );

			//is not category
			/*
			if ( gesture_item && gesture_item.GetCategory() != GestureCategories.CATEGORIES )
			{			
				//alter item visual
				//TextWidget text_widget = TextWidget.Cast( gesture_item.GetRadialItemCard().FindAnyWidget( RADIAL_TEXT ) );
				//text_widget.SetColor( ARGB( 255, 255, 255, 255 ) );
			}
			*/
		}
	}	
	
	protected void ExecuteSelectedCategory( Widget w )
	{
		//only when category is not picked yet
		if ( w && !instance.m_IsCategorySelected )
		{
			GestureMenuItem gesture_item;
			w.GetUserData( gesture_item );
			
			//is category
			if ( gesture_item.GetCategory() == GestureCategories.CATEGORIES )
			{
				//set category selected
				instance.m_IsCategorySelected = true;
				
				//show selected category gestures
				GetGestureItems( m_GestureItems, gesture_item.GetID() );
				CreateGestureContent();
				RefreshGestures( gesture_item.GetID() );
				
				//update category name text
				UpdateCategoryName( gesture_item.GetName() );
			}
		}
	}
	
	protected void ExecuteSelectedItem()
	{
		if ( instance.m_IsCategorySelected && instance.m_SelectedItem )
		{
			if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
			{
				PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
				
				GestureMenuItem gesture_item;
				instance.m_SelectedItem.GetUserData( gesture_item );
			
				if ( gesture_item ) 
				{
					if( player.GetEmoteManager() ) 
					{
						player.GetEmoteManager().CreateEmoteCBFromMenu( gesture_item.GetID() );
					}
				}
			}
		}
	}
	
	bool IsMenuClosing()
	{
		return m_IsMenuClosing;
	}
	
	void SetMenuClosing(bool state)
	{
		m_IsMenuClosing = state;
	}
}	
