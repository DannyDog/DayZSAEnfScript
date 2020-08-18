class ItemActionsWidget extends ScriptedWidgetEventHandler
{
	protected PlayerBase 				m_Player;
	protected EntityAI 					m_EntityInHands;
	protected ActionBase				m_Interact;
	protected ActionBase				m_ContinuousInteract;
	protected ActionBase				m_Single;
	protected ActionBase				m_Continuous;
	protected ActionManagerClient	 	m_AM;

	protected int						m_InteractActionsNum;
	protected int						m_ContinuousInteractActionsNum;
	protected bool 						m_HealthEnabled;
	protected bool						m_QuantityEnabled;
	
	protected ref WidgetFadeTimer		m_FadeTimer;
	protected bool						m_Faded;

	protected Widget					m_Root;
	protected Widget 					m_ItemLeft;

	//! widget width
	protected float m_MaxWidthChild;
	protected float m_RootWidth;
	protected float m_RootHeight;
	
	void ItemActionsWidget()
	{
		m_Interact				= null;
		m_ContinuousInteract 	= null;
		m_Single 				= null;
		m_Continuous 			= null;
		m_AM 					= null;

		m_FadeTimer 			= new WidgetFadeTimer;
		m_Faded 				= true;
		
		m_HealthEnabled 		= true;
		m_QuantityEnabled 		= true;
		
		//KeysToUIElements.Init(); // Initialiaze of KeysToUIElements

		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Insert(Update);
	}
	
	void ~ItemActionsWidget()
	{
		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Remove(Update);
	}

	void SetInteractXboxIcon( string imageset_name, string image_name )
	{
		SetXboxIcon( "ia_interact", imageset_name, image_name );
	}

	void SetContinuousInteractXboxIcon( string imageset_name, string image_name )
	{
		SetXboxIcon( "ia_continuous_interact", imageset_name, image_name );
	}

	void SetSingleXboxIcon( string imageset_name, string image_name )
	{
		SetXboxIcon( "ia_single", imageset_name, image_name );
	}
	
	void SetContinuousXboxIcon( string imageset_name, string image_name )
	{
		SetXboxIcon( "ia_continuous", imageset_name, image_name );
	}
	
	protected void SetXboxIcon( string name, string imageset_name, string image_name )
	{
		ImageWidget w = ImageWidget.Cast( m_Root.FindAnyWidget( name + "_btn_icon_xbox" ) );
		w.LoadImageFile( 0, "set:"+ imageset_name + " image:" + image_name );
	}

	protected void ShowXboxHidePCIcons( string widget, bool show_xbox_icon )
	{
		m_Root.FindAnyWidget( widget + "_btn_icon_xbox" ).Show( show_xbox_icon );
		m_Root.FindAnyWidget( widget + "_btn_icon" ).Show( !show_xbox_icon );
	}

	protected void OnWidgetScriptInit(Widget w)
	{
		m_Root = w;
		m_Root.SetHandler(this);
		m_Root.Show(false);

		m_ItemLeft = w.FindAnyWidget("ia_item_left");
		
#ifdef PLATFORM_XBOX
		SetSingleXboxIcon("xbox_buttons", "RT");
		SetContinuousXboxIcon("xbox_buttons", "RT");
		SetInteractXboxIcon("xbox_buttons", "X");
		SetContinuousInteractXboxIcon("xbox_buttons", "X");
#endif
#ifdef PLATFORM_PS4
		SetSingleXboxIcon("playstation_buttons", "R2");
		SetContinuousXboxIcon("playstation_buttons", "R2");
		SetInteractXboxIcon("playstation_buttons", "square");
		SetContinuousInteractXboxIcon("playstation_buttons", "square");
#endif
	}

	protected void BuildCursor()
	{
		int health = -1;
		int q_type = 0;
		int q_min, q_max = -1;
		int q_chamber, q_mag = 0;
		float q_cur = -1.0;

		// item health
		health = GetItemHealth();
		SetItemHealth(health, "ia_item", "ia_item_health_mark", m_HealthEnabled);
		
		// quantity
		//! weapon specific
		if( m_EntityInHands && m_EntityInHands.IsWeapon() )
		{
			//GetWeaponQuantity(q_chamber, q_mag);
			SetWeaponQuantity(q_chamber, q_mag, "ia_item", "ia_item_quantity_pb", "ia_item_quantity_text", m_QuantityEnabled);
			SetWeaponModeAndZeroing("ia_item_subdesc", "ia_item_subdesc_up", "ia_item_subdesc_down", true);
		}
		//! transmitter/PAS specific
		else if( m_EntityInHands && m_EntityInHands.IsTransmitter() )
		{
			SetRadioFrequency(GetRadioFrequency(), "ia_item_subdesc", "ia_item_subdesc_up", "ia_item_subdesc_down", m_QuantityEnabled);
			GetItemQuantity(q_type, q_cur, q_min, q_max);
			SetItemQuantity(q_type, q_cur, q_min, q_max, "ia_item", "ia_item_quantity_pb", "ia_item_quantity_text", true);
		}
		else
		{
			GetItemQuantity(q_type, q_cur, q_min, q_max);
			SetItemQuantity(q_type, q_cur, q_min, q_max, "ia_item", "ia_item_quantity_pb", "ia_item_quantity_text", m_QuantityEnabled);
			SetWeaponModeAndZeroing("ia_item_subdesc", "", "", false);
		}
	
		SetItemDesc(m_EntityInHands, GetItemDesc(m_EntityInHands), "ia_item", "ia_item_desc");
		SetInteractActionIcon("ia_interact", "ia_interact_icon_frame", "ia_interact_btn_inner_icon", "ia_interact_btn_text");
		SetActionWidget(m_Interact, GetActionDesc(m_Interact), "ia_interact", "ia_interact_action_name");

		SetInteractActionIcon("ia_continuous_interact", "ia_continuous_interact_icon_frame", "ia_continuous_interact_btn_inner_icon", "ia_continuous_interact_btn_text");
		SetActionWidget(m_ContinuousInteract, GetActionDesc(m_ContinuousInteract), "ia_continuous_interact", "ia_continuous_interact_action_name");

		SetActionWidget(m_Single, GetActionDesc(m_Single), "ia_single", "ia_single_action_name");
		SetActionWidget(m_Continuous, GetActionDesc(m_Continuous), "ia_continuous", "ia_continuous_action_name");
		SetMultipleInteractAction("ia_interact_mlt_wrapper");
	}
		
	protected void Update()
	{
		//! don't show crosshair if it's disabled in profile
		if(!g_Game.GetProfileOption(EDayZProfilesOptions.HUD))
		{
			m_Root.Show(false);
			return;
		};

		if(m_Player && !m_Player.IsAlive()) // handle respawn
		{
			m_Player = null;
			m_AM = null;
		}
		if(!m_Player) GetPlayer();
		if(!m_AM) GetActionManager();

		GetEntityInHands();
		GetActions();

		if((m_EntityInHands || m_Interact || m_ContinuousInteract || m_Single || m_Continuous) && GetGame().GetUIManager().GetMenu() == null)
		{
			BuildCursor();
			CheckRefresherFlagVisibility();
			m_Root.Show(true);
		}
		else
		{
			if (m_Root.IsVisible())
			{
				m_Root.Show(false);
			}
		}

		m_MaxWidthChild = 200;
	}

	// getters
    protected void GetPlayer()
	{
		Class.CastTo( m_Player, GetGame().GetPlayer() );
	}

	protected void GetActionManager()
	{
		if( m_Player && m_Player.IsPlayerSelected() )
			ActionManagerClient.CastTo( m_AM, m_Player.GetActionManager() );
		else
			m_AM = null;
	}

    protected void GetActions()
	{
		m_Interact = null;
		m_ContinuousInteract = null;
		m_Single = null;
		m_Continuous = null;

		if(!m_AM) return;
		//if(!m_EntityInHands) return false;
		if(m_Player.IsSprinting()) return;
		
		array<ActionBase> possible_interact_actions = m_AM.GetPossibleActions(InteractActionInput);
		int possible_interact_actions_index = m_AM.GetPossibleActionIndex(InteractActionInput);
		array<ActionBase> possible_continuous_interact_actions = m_AM.GetPossibleActions(ContinuousInteractActionInput);
		int possible_continuous_interact_actions_index = m_AM.GetPossibleActionIndex(ContinuousInteractActionInput);
		
		m_InteractActionsNum = possible_interact_actions.Count();
		if ( m_InteractActionsNum > 0 )
		{
			m_Interact = possible_interact_actions[possible_interact_actions_index];
		}
		
		m_ContinuousInteractActionsNum = possible_continuous_interact_actions.Count();
		if ( m_ContinuousInteractActionsNum > 0 )
		{
			m_ContinuousInteract = possible_continuous_interact_actions[possible_continuous_interact_actions_index];
		}
		
		
		m_Single = m_AM.GetPossibleAction(DefaultActionInput);
		m_Continuous = m_AM.GetPossibleAction(ContinuousDefaultActionInput);
	}

	protected void GetEntityInHands()
	{
		if(!m_Player) return;
		
		EntityAI eai = m_Player.GetHumanInventory().GetEntityInHands();
		
		if (eai && !eai.IsInherited(DummyItem))
		{
			m_EntityInHands = eai;
		}
		else
		{
			m_EntityInHands = null;
		}
	}
	
	protected string GetActionDesc(ActionBase action)
	{
		string desc = "";
		if (action && action.GetText())
		{
			desc = action.GetText();
			return desc;
		}
		return desc;
	}
	
	protected string GetItemDesc(EntityAI entity)
	{
		string desc = "";

		if(m_EntityInHands)
		{
			desc = m_EntityInHands.GetDisplayName();
			return desc;
		}
		return desc;
	}
	
	protected int GetItemHealth()
	{
		int health = -1;

		if(m_EntityInHands)
		{
			health = m_EntityInHands.GetHealthLevel();
			return health;
		}
		
		return health;
	}

	protected void GetItemQuantity(out int q_type, out float q_cur, out int q_min, out int q_max)
	{
		InventoryItem item = null;

		if( m_EntityInHands )
		{
			Class.CastTo(item, m_EntityInHands);
			q_type = QuantityConversions.HasItemQuantity(m_EntityInHands);
			if(q_type > 0)
			{
				if(q_type == QUANTITY_PROGRESS)
				{
					QuantityConversions.GetItemQuantity(item, q_cur, q_min, q_max);

					q_cur = (q_cur / q_max);
					// to percents
					q_min = 0;
					q_cur = q_cur * 100;
					q_max = 100;
				}
				else
				{
					QuantityConversions.GetItemQuantity(item, q_cur, q_min, q_max);
				}
			}
		}
	}
	
/*	protected void GetWeaponQuantity(out int q_chamber, out int q_mag)
	{
		q_chamber = 0;
		q_mag = 0;

		Weapon_Base wpn;
		Magazine mag

		if ( Class.CastTo(wpn, m_EntityInHands ) )
		{
			int mi = wpn.GetCurrentMuzzle();
			mag = wpn.GetMagazine(mi);
			if (!wpn.IsChamberFiredOut(mi) && !wpn.IsChamberEmpty(mi))
			{
				q_chamber = 1;
			}
			if (wpn.IsJammed())
			{
				q_chamber = -1;
			}
			
			if (mag)
			{
				q_mag = mag.GetAmmoCount();
			}
			else if (wpn.GetInternalMagazineCartridgeCount(mi) > 0)
			{
				q_mag = wpn.GetInternalMagazineCartridgeCount(mi);
			}
		}
	}*/
	
	protected string GetRadioFrequency()
	{
		TransmitterBase trans;

		if ( Class.CastTo(trans, m_EntityInHands ) )
		{
			return trans.GetTunedFrequency().ToString();
		}

		return string.Empty;
	}
	
	// setters
	protected void SetItemDesc(EntityAI entity, string descText, string itemWidget, string descWidget)
	{
		Widget widget;
		
		widget = m_Root.FindAnyWidget(itemWidget);
		
		if(entity)
		{
			descText.ToUpper();
			TextWidget itemName;
			Class.CastTo(itemName, widget.FindAnyWidget(descWidget));
			itemName.SetText(descText);
			widget.Show(true);

			/*
			int x, y;
			itemName.GetTextSize(x, y);
			if (descText.Length() > 0 && x > m_MaxWidthChild);
				m_MaxWidthChild = x;
			*/

		}
		else
			widget.Show(false);
	}
	
	protected void SetItemHealth(int health, string itemWidget, string healthWidget, bool enabled)
	{
		Widget widget;
		
		widget = m_Root.FindAnyWidget(itemWidget);
		
		if(enabled)
		{
			ImageWidget healthMark;
			Class.CastTo(healthMark, widget.FindAnyWidget(healthWidget));

			switch (health)
			{
				case -1 :
					healthMark.GetParent().Show(false);
					break;
				case GameConstants.STATE_PRISTINE :
					healthMark.SetColor(Colors.COLOR_PRISTINE);
					healthMark.SetAlpha(0.5);
					healthMark.GetParent().Show(true);
					break;
				case GameConstants.STATE_WORN :
					healthMark.SetColor(Colors.COLOR_WORN);
					healthMark.SetAlpha(0.5);
					healthMark.GetParent().Show(true);
					break;
				case GameConstants.STATE_DAMAGED :
					healthMark.SetColor(Colors.COLOR_DAMAGED);
					healthMark.SetAlpha(0.5);
					healthMark.GetParent().Show(true);
					break;
				case GameConstants.STATE_BADLY_DAMAGED:
					healthMark.SetColor(Colors.COLOR_BADLY_DAMAGED);
					healthMark.SetAlpha(0.5);
					healthMark.GetParent().Show(true);
					break;
				case GameConstants.STATE_RUINED :
					healthMark.SetColor(Colors.COLOR_RUINED);
					healthMark.SetAlpha(0.5);
					healthMark.GetParent().Show(true);
					break;
				default :
					healthMark.SetColor(0x00FFFFFF);
					healthMark.SetAlpha(0.5);
					healthMark.GetParent().Show(true);
					break;			
			}
			
			widget.Show(true);
		}
		else
			widget.Show(false);
	}
	
	protected void SetItemQuantity(int type, float current, int min, int max, string itemWidget, string quantityPBWidget, string quantityTextWidget, bool enabled )
	{
		Widget widget;
		
		widget = m_Root.FindAnyWidget(itemWidget);
		
		if(enabled)
		{
			ProgressBarWidget progressBar;
			TextWidget textWidget;
			Class.CastTo(progressBar, widget.FindAnyWidget(quantityPBWidget));
			Class.CastTo(textWidget, widget.FindAnyWidget(quantityTextWidget));

			//check for volume vs. count and display progressbar or "bubble" with exact count/max text
			switch (type)
			{
				case QUANTITY_HIDDEN :
					progressBar.Show(false);
					textWidget.Show(false);
					textWidget.GetParent().Show(false);
					break;
				case QUANTITY_COUNT :
					if(max > 1 || current > 1)
					{
						string qty_text = string.Format("%1/%2", Math.Round(current).ToString(), max.ToString());
						progressBar.Show(false);
						textWidget.SetText(qty_text);
						textWidget.Show(true);
						textWidget.GetParent().Show(true);
						break;
					}
					else
					{
						progressBar.Show(false);
						textWidget.Show(false);
						textWidget.GetParent().Show(false);
						break;
					}
				case QUANTITY_PROGRESS :	
					textWidget.Show(false);
					progressBar.SetCurrent(current);
					progressBar.Show(true);
					textWidget.GetParent().Show(true);
					break;
			}
			widget.Show(true);
		}
		else
			widget.Show(false);	
	}
	
	protected void SetWeaponQuantity(int chamber, int mag, string itemWidget, string quantityPBWidget, string quantityTextWidget, bool enabled)
	{
		Widget widget;
		
		widget = m_Root.FindAnyWidget(itemWidget);
		
		if (enabled)
		{
			string wpn_qty = "";

			ProgressBarWidget progressBar;
			TextWidget textWidget;
			Class.CastTo(progressBar, widget.FindAnyWidget(quantityPBWidget));
			Class.CastTo(textWidget, widget.FindAnyWidget(quantityTextWidget));
			
			Weapon_Base wpn;
			Magazine maga;
			int mag_quantity = -1;

			if ( Class.CastTo(wpn, m_EntityInHands ) )
			{
				if(Magnum.Cast(wpn))
				{
					mag_quantity = 0;
					for (int j = 0; j < wpn.GetMuzzleCount(); j++)
					{
						if(wpn.IsChamberFull(j)&& !wpn.IsChamberFiredOut(j))
							mag_quantity++; 
					}
					wpn_qty = mag_quantity.ToString();
				}
				else
				{
					for (int i = 0; i < wpn.GetMuzzleCount(); i++)
					{
						if ( i > 0 && (wpn.GetMuzzleCount() < 3 ||  i%2 == 0 ) )
						{
							wpn_qty = wpn_qty + " ";
						}
						if (wpn.IsChamberEmpty(i))
						{
							wpn_qty = wpn_qty + "0";
						}
						else if (wpn.IsChamberFiredOut(i))
						{
							wpn_qty = wpn_qty + "F";
						}
						else
						{
							wpn_qty = wpn_qty + "1";
						}
						
						maga = wpn.GetMagazine(i);
						if (maga)
						{
							mag_quantity = maga.GetAmmoCount();
						}
						else if (wpn.GetInternalMagazineMaxCartridgeCount(i) > 0)
						{
							mag_quantity = wpn.GetInternalMagazineCartridgeCount(i);
						}
					
					}
				
					if (wpn.IsJammed())
					{
						if (mag_quantity != -1 )
							wpn_qty = string.Format("X (+%1)", mag_quantity);
						else
							wpn_qty = "X";
					}
					else
					{
						if(mag_quantity != -1 )
						{
							wpn_qty = wpn_qty + " (" + mag_quantity.ToString() + ")";
						}
					}
				}
			}
	
			progressBar.Show(false);
			textWidget.SetText(wpn_qty);
			textWidget.Show(true);
			textWidget.GetParent().Show(true);
		}
		else
			widget.Show(false);
	}
	
	protected void SetWeaponModeAndZeroing(string itemWidget, string upWidget, string downWidget, bool enabled)
	{
		Widget widget;
		
		widget = m_Root.FindAnyWidget(itemWidget);

		if(enabled)
		{
			TextWidget txtModeWidget;
			TextWidget txtZeroingWidget;

			Class.CastTo(txtModeWidget, widget.FindAnyWidget(upWidget));
			Class.CastTo(txtZeroingWidget, widget.FindAnyWidget(downWidget));
			
			Weapon w = Weapon.Cast(m_Player.GetHumanInventory().GetEntityInHands());
			string zeroing	= string.Empty;
			if (w)
				zeroing	= string.Format("%1 m", w.GetCurrentZeroing(w.GetCurrentMuzzle()));

			txtModeWidget.SetText(WeaponModeTextTemp());
			txtZeroingWidget.SetText(zeroing);
			widget.Show(true);
		}
		else
			widget.Show(false);
	}
	
	//temporary solution, to be solved via config parameter
	protected string WeaponModeTextTemp()
	{
		string mode = m_Player.GetCurrentWeaponMode();
		switch (mode)
		{
			case "Single" :
				return "#STR_Single";
			
			case "SemiAuto" :
				return "#STR_SemiAuto";
			
			case "FullAuto" :
				return "#STR_FullAuto";
			
			//currently only doubleshot shotguns
			case "Burst" :
				return "#STR_Double";//"#STR_Burst";
		}
		return mode;
	}
	
	protected void SetRadioFrequency(string freq, string itemWidget, string upWidget, string downWidget, bool enabled)
	{
		Widget widget;
		
		widget = m_Root.FindAnyWidget(itemWidget);
		
		if(enabled)
		{
			TextWidget txtUpWidget;
			TextWidget txtDownWidget;
			Class.CastTo(txtUpWidget, widget.FindAnyWidget(upWidget));
			Class.CastTo(txtDownWidget, widget.FindAnyWidget(downWidget));

			txtUpWidget.SetText(freq);
			txtDownWidget.SetText("MHz");
			widget.Show(true);
		}
		else
			widget.Show(false);	
	}
	
	protected void SetActionWidget(ActionBase action, string descText, string actionWidget, string descWidget)
	{
		Widget widget;
		
		widget = m_Root.FindAnyWidget(actionWidget);
		
#ifdef PLATFORM_XBOX
		ShowXboxHidePCIcons( actionWidget, !GetGame().GetInput().IsEnabledMouseAndKeyboardEvenOnServer() );
#else
#ifdef PLATFORM_PS4
		ShowXboxHidePCIcons( actionWidget, !GetGame().GetInput().IsEnabledMouseAndKeyboardEvenOnServer() );
#else
		ShowXboxHidePCIcons( actionWidget, false );
#endif
#endif
		// TODO: TMP: Car AM rework needed (checking of player's command)
		if(action && (!action.HasTarget() || m_Player.GetCommand_Vehicle()))
		{
			TextWidget actionName;
			Class.CastTo(actionName, widget.FindAnyWidget(descWidget));
			

			if(action.GetInput().GetInputType() == ActionInputType.AIT_CONTINUOUS)
			{
				descText = descText + " " + "#action_target_cursor_hold";
				actionName.SetText(descText);
			}
			else
			{
				actionName.SetText(descText);
			}

			widget.Show(true);
		}
		else
		{
			widget.Show(false);
		}
	}

	//! shows arrows near the interact action if there are more than one available
	protected void SetMultipleInteractAction(string multiActionsWidget)
	{
		Widget widget;

		widget = m_Root.FindAnyWidget(multiActionsWidget);

		if(m_InteractActionsNum > 1)
			widget.Show(true);
		else
			widget.Show(false);
	}
	
	protected void SetInteractActionIcon(string actionWidget, string actionIconFrameWidget, string actionIconWidget, string actionIconTextWidget)
	{
		string keyName = string.Empty;
		Widget widget, frameWidget;
		ImageWidget iconWidget;
		TextWidget textWidget;
		
		widget = m_Root.FindAnyWidget(actionWidget);
		Class.CastTo(frameWidget, widget.FindAnyWidget(actionIconFrameWidget));
		Class.CastTo(iconWidget, widget.FindAnyWidget(actionIconWidget));
		Class.CastTo(textWidget, widget.FindAnyWidget(actionIconTextWidget));

		//! get name of key which is used for UAAction input 
		UAInput i1 = GetUApi().GetInputByName("UAAction"); 
		
		i1.SelectAlternative(0); //! select first alternative (which is the primary bind)
		for( int c = 0; c < i1.BindKeyCount(); c++ )
		{
		  	int _hc = i1.GetBindKey(0);
		  	keyName = GetUApi().GetButtonName(_hc);
		}

		// uses text in floating widget
		iconWidget.Show(false);
		textWidget.SetText(keyName);
		//frameWidget.Show(true);
		textWidget.Show(true);	
	}
	
	protected void CheckRefresherFlagVisibility()
	{
		Widget w = m_Root.FindAnyWidget("ia_item_flag_icon");
		if ( m_Player.GetHologramLocal() )
		{
			EntityAI entity = m_Player.GetHologramLocal().GetProjectionEntity();
			w.Show(entity.IsRefresherSignalingViable() && m_Player.IsTargetInActiveRefresherRange(entity));
		}
		else if ( w.IsVisible() )
		{
			w.Show(false);
		}
	}
}