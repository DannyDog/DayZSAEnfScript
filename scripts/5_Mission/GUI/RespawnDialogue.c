class RespawnDialogue extends UIScriptedMenu//ItemDropWarningMenu
{
	const int 					ID_RESPAWN_CUSTOM = 101;
	const int 					ID_RESPAWN_RANDOM = 102;
	
	//tooltips
	protected Widget			m_DetailsRoot;
	protected TextWidget		m_DetailsLabel;
	protected RichTextWidget	m_DetailsText;
	
	void RespawnDialogue()
	{
		//GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
	}

	void ~RespawnDialogue()
	{
		/*if ( GetGame() && GetGame().GetMission() && !GetGame().GetUIManager().IsMenuOpen(MENU_INGAME) )
			GetGame().GetMission().PlayerControlEnable(true);*/
	}
	
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("gui/layouts/day_z_respawn_dialogue.layout");
		m_DetailsRoot 				= layoutRoot.FindAnyWidget( "menu_details_tooltip" );
		m_DetailsLabel				= TextWidget.Cast( m_DetailsRoot.FindAnyWidget( "menu_details_label" ) );
		m_DetailsText				= RichTextWidget.Cast( m_DetailsRoot.FindAnyWidget( "menu_details_tooltip_content" ) );
		
		return layoutRoot;
	}
	
	override void Update(float timeslice)
	{
		super.Update( timeslice );
		Input input = GetGame().GetInput();
		if ( input.LocalPress( "UAUIBack", false ) || input.LocalPress( "UAUIMenu", false ))
		{
			Close();
		}
		//UAUIBack
		//UAUIMenu
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		
		if (w.GetUserID() == IDC_CANCEL)
		{
			Close();
			return true;
		}
		if (w.GetUserID() == ID_RESPAWN_CUSTOM)
		{
			return RequestRespawn(false);
		}
		if (w.GetUserID() == ID_RESPAWN_RANDOM)
		{
			return RequestRespawn(true);
		}

		return false;
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		string tooltip_header = "";
		string tooltip_text = "";
		ColorHighlight( w );
		switch (w.GetUserID())//hack-ish solution, implement generic tooltip handler!
		{
			case ID_RESPAWN_RANDOM:
				tooltip_header = "#main_menu_respawn_random";
				tooltip_text = "#main_menu_respawn_random_tooltip";
			break;
			
			case ID_RESPAWN_CUSTOM:
				tooltip_header = "#main_menu_respawn_custom";
				tooltip_text = "#main_menu_respawn_custom_tooltip";
			break;
			
			/*default:
				tooltip_header = "boop";
				tooltip_text = "the snoot";
			break;*/
		}
		SetTooltipTexts(w, tooltip_header, tooltip_text);
		return true;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		ColorNormal( w );
		return true;
	}
	
	override bool OnFocus( Widget w, int x, int y )
	{
		string tooltip_header = "";
		string tooltip_text = "";
		if( IsFocusable( w ) )
		{
			ColorHighlight( w );
			switch (w.GetUserID())//hack-ish solution, implement generic tooltip handler!
			{
				case ID_RESPAWN_RANDOM:
					tooltip_header = "#main_menu_respawn_random";
					tooltip_text = "#main_menu_respawn_random_tooltip";
				break;
				
				case ID_RESPAWN_CUSTOM:
					tooltip_header = "#main_menu_respawn_custom";
					tooltip_text = "#main_menu_respawn_custom_tooltip";
				break;
				
				/*default:
					tooltip_header = "boop";
					tooltip_text = "the snoot";
				break;*/
			}
			SetTooltipTexts(w, tooltip_header, tooltip_text);
			return true;
		}
		SetTooltipTexts(w, tooltip_header, tooltip_text);
		return false;
	}
	
	override bool OnFocusLost( Widget w, int x, int y )
	{
		if( IsFocusable( w ) )
		{
			ColorNormal( w );
			return true;
		}
		return false;
	}
	
	bool IsFocusable( Widget w )
	{
		if( w )
		{
			if( w.GetUserID() == IDC_CANCEL || w.GetUserID() == ID_RESPAWN_CUSTOM || w.GetUserID() == ID_RESPAWN_RANDOM );
				return true;
		}
		return false;
	}
	
	protected void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, ARGB(255, 0, 0, 0));
		ButtonSetTextColor(w, ARGB(255, 255, 0, 0));
	}
	
	protected void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, ARGB(0, 0, 0, 0));
		ButtonSetTextColor(w, ARGB(255, 255, 255, 255));
	}
	
	protected void ButtonSetColor( Widget w, int color )
	{
		if( !w )
			return;
		
		Widget panel = w.FindWidget( w.GetName() + "_panel" );
		
		if( panel )
		{
			panel.SetColor( color );
		}
	}
	
	protected void ButtonSetTextColor( Widget w, int color )
	{
		if( !w )
			return;

		TextWidget label	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
				
		if( label )
		{
			label.SetColor( color );
		}
	}
	
	void SetTooltipTexts(Widget w, string header = "", string desc = "")
	{
		bool show = header != "" && desc != "";
		m_DetailsRoot.Show( show );
		m_DetailsLabel.SetText( header );
		m_DetailsText.SetText( desc );
		
		//moves the widget to parent, setting is relative to widget alignment, case-specific implementation (getter missing!!!)
		/*if (show)
		{
			float parent_pos_x, parent_pos_y;
			float parent_size_x, parent_size_y;
			float layout_size_x, layout_size_y;
			
			float root_pos_x, root_pos_y;
			m_DetailsRoot.GetScreenPos(root_pos_x,root_pos_y);
			
			w.GetPos(parent_pos_x,parent_pos_y);
			w.GetScreenSize(parent_size_x,parent_size_y);
			layoutRoot.GetScreenSize(layout_size_x,layout_size_y);
			
			//Print("w.GetPos: " + parent_pos_x + " | " + parent_pos_y);
			//Print("w.GetScreenSize: " + parent_size_x + " | " + parent_size_y);
			//Print("layoutRoot.GetScreenSize: " + layout_size_x + " | " + layout_size_y);
			//Print("---------------");
			float set_x = parent_size_x; //constant pos
			float set_y = 0;
			//Print("result: " + set_x + " : " + set_y);
			m_DetailsRoot.SetPos(set_x,set_y,true);
		}*/
		
		m_DetailsText.Update();
		m_DetailsLabel.Update();
		m_DetailsRoot.Update();
	}
	
	bool RequestRespawn(bool random)
	{
		Man player = GetGame().GetPlayer();

		if ( !player || (player.GetPlayerState() == EPlayerStates.ALIVE && !player.IsUnconscious()) )
			return false;
		
		#ifdef PLATFORM_CONSOLE
			InGameMenuXbox menu_ingame = InGameMenuXbox.Cast(GetGame().GetUIManager().FindMenu(MENU_INGAME));
		#else
			InGameMenu menu_ingame = InGameMenu.Cast(GetGame().GetUIManager().FindMenu(MENU_INGAME));
		#endif
		
		if (!menu_ingame)
			return false;
		
		menu_ingame.MenuRequestRespawn(this,random);
		return true;
	}
}
