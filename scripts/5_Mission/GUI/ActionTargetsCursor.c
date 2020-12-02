class ATCCachedObject
{
	protected Object 	m_CachedObject;
	protected vector 	m_CursorWPos;
	protected vector	m_ScreenPos;
	protected int		m_CompIdx;
	
	void ATCCachedTarget()
	{
		m_CachedObject = null;
		m_ScreenPos = vector.Zero;
		m_CompIdx = -1;
	}

	//! cache object and its world pos
	void Store(Object obj, vector pos, int compIdx)
	{
		if(!m_CachedObject)
		{
			m_CachedObject = obj;
			m_CursorWPos = pos;
			m_CompIdx = compIdx;
		}
	}

	//! invalidate cached objec
	void Invalidate()
	{
		if ( m_CachedObject )
		{
			m_CachedObject = null;
			m_CursorWPos = vector.Zero;
			m_CompIdx = -1;
		}
	}

	Object Get()
	{
		return m_CachedObject; 	
	}
	
	vector GetCursorWorldPos()
	{
		return m_CursorWPos;
	}
	
	int GetCursorCompIdx()
	{
		return m_CompIdx;
	}
};

class ActionTargetsCursor extends ScriptedWidgetEventHandler
{
	protected PlayerBase 					m_Player;
	protected ActionTarget 					m_Target;
	protected ref ATCCachedObject			m_CachedObject;
	protected Object						m_DisplayInteractTarget;

	protected ActionBase					m_Interact;
	protected ActionBase					m_ContinuousInteract;
	protected ActionBase					m_Single;
	protected ActionBase					m_Continuous;
	protected ActionManagerClient 			m_AM;

	protected int							m_InteractActionsNum;
	protected int							m_ContinuousInteractActionsNum;
	protected bool 							m_HealthEnabled;
	protected bool							m_QuantityEnabled;	
	protected bool							m_FixedOnPosition;
	protected bool 							m_Hidden;

	protected Widget						m_Root;
	protected Widget						m_Container;
	protected Widget 						m_ItemLeft;

	//! widget width
	protected float m_MaxWidthChild;
	protected float m_RootWidth;
	protected float m_RootHeight;

	void ActionTargetsCursor()
	{
		m_Interact 				= null;
		m_ContinuousInteract	= null;
		m_Single				= null;
		m_Continuous			= null;
		m_AM					= null;
		
		m_HealthEnabled			= true;
		m_QuantityEnabled		= true;
		
		m_CachedObject 			= new ATCCachedObject;
		m_Hidden 				= false;
		m_DisplayInteractTarget	= null;
	}
	
	void ~ActionTargetsCursor() {}
	
	// Controls appearance of the builded cursor
	void SetHealthVisibility( bool state)
	{
		m_HealthEnabled = state;
	}

	void SetQuantityVisibility( bool state )
	{
		m_QuantityEnabled = state;
	}
		
	void SetInteractXboxIcon( string imageset_name, string image_name )
	{
		SetXboxIcon( "interact", imageset_name, image_name );
	}

	void SetContinuousInteractXboxIcon( string imageset_name, string image_name )
	{
		SetXboxIcon( "continuous_interact", imageset_name, image_name );
	}
	
	void SetSingleXboxIcon( string imageset_name, string image_name )
	{
		SetXboxIcon( "single", imageset_name, image_name );
	}
	
	void SetContinuousXboxIcon( string imageset_name, string image_name )
	{
		SetXboxIcon( "continuous", imageset_name, image_name );
	}
	
	protected void SetXboxIcon( string name, string imageset_name, string image_name )
	{
		ImageWidget w = ImageWidget.Cast( m_Root.FindAnyWidget( name + "_btn_icon_xbox" ) );
		w.LoadImageFile( 0, "set:"+ imageset_name + " image:" + image_name );
	}

	protected void OnWidgetScriptInit(Widget w)
	{
		m_Root = w;
		m_Root.Show(false);
		m_Root.SetHandler(this);

		m_Container = w.FindAnyWidget("container");
		m_ItemLeft = w.FindAnyWidget("item_left");
		m_Root.Update();

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

	protected void PrepareCursorContent()
	{
		int health = -1;
		int cargoCount = 0;
		int q_type = 0;
		int q_min, q_max = -1;
		float q_cur = -1.0;
		
		//! item health
		health = GetItemHealth();
		SetItemHealth(health, "item", "item_health_mark", m_HealthEnabled);	
		//! quantity
		GetItemQuantity(q_type, q_cur, q_min, q_max);
		//! cargo in item
		GetItemCargoCount(cargoCount);
		//! fill the widget with data
		SetItemQuantity(q_type, q_cur, q_min, q_max, "item", "item_quantity_pb", "item_quantity_text", m_QuantityEnabled);
		SetInteractActionIcon("interact", "interact_icon_frame", "interact_btn_inner_icon", "interact_btn_text");
		SetItemDesc(GetItemDesc(m_Interact), cargoCount, "item", "item_desc");
		SetActionWidget(m_Interact, GetActionDesc(m_Interact), "interact", "interact_action_name");

		SetInteractActionIcon("continuous_interact", "continuous_interact_icon_frame", "continuous_interact_btn_inner_icon", "continuous_interact_btn_text");
		SetActionWidget(m_ContinuousInteract, GetActionDesc(m_ContinuousInteract), "continuous_interact", "continuous_interact_action_name");

		SetActionWidget(m_Single, GetActionDesc(m_Single), "single", "single_action_name");
		SetActionWidget(m_Continuous, GetActionDesc(m_Continuous), "continuous", "continuous_action_name");
		SetMultipleInteractAction("interact_mlt_wrapper");
	}
	
	protected void BuildFixedCursor()
	{
		int w, h, x, y;

		PrepareCursorContent();
		GetScreenSize(w, h);
		x = w/2 + 32;
		y = h/2 + 32;

		m_Root.SetPos(x, y);
	}
	
	protected void BuildFloatingCursor(bool forceRebuild)
	{
		float pos_x, pos_y = 0.0;

		PrepareCursorContent();
		
		//! Get OnScreenPos when forced or targeted component differs
		if (forceRebuild || m_Target.GetComponentIndex() != m_CachedObject.GetCursorCompIdx())
		{
			GetOnScreenPosition(pos_x, pos_y);
		}
		//! in case of cached item, all above is reused except the position
		else
		{
			vector screen_pos = TransformToScreenPos(m_CachedObject.GetCursorWorldPos());
	
			pos_x = screen_pos[0];
			pos_y = screen_pos[1];
		}
		
		pos_x = Math.Ceil(pos_x);
		pos_y = Math.Ceil(pos_y);

		Widget parentWdg = m_Root.GetParent();
		
		float screen_w = 0;
		float screen_h = 0;
		
		float wdg_w = 0;
		float wdg_h = 0; 
		
		parentWdg.GetScreenSize( screen_w, screen_h );
		m_Root.GetSize( wdg_w, wdg_h );

		if ( pos_x + wdg_w > screen_w )
			pos_x = screen_w - wdg_w;

		if ( pos_y + wdg_h > screen_h )
			pos_y = screen_h - wdg_h;
				
		m_Root.SetPos(pos_x, pos_y);
	}
	
	override bool OnUpdate(Widget w)
	{
		if (m_Root == w)
		{
			Update();
			return true;
		}
		
		return false;
	}

	protected void HideWidget()
	{
		if (m_Root.IsVisible())
		{
			m_Root.Show(false);
			m_CachedObject.Invalidate();
		}
	}
	
	void Update()
	{
		//! don't show floating widget if it's disabled in profile
		if(GetGame().GetUIManager().GetMenu() != null || !g_Game.GetProfileOption(EDayZProfilesOptions.HUD))
		{
			HideWidget();
			return;
		}

		// TODO: if we choose to have it configurable throught options or from server settings
		// we need to change setting of these methods;
		//SetHealthVisibility(true);
		//SetQuantityVisibility(true);
		
		if(m_Player && !m_Player.IsAlive()) // handle respawn
		{
			m_Player = null;
			m_AM = null;
		}

		if(!m_Player) GetPlayer();
		if(!m_AM) GetActionManager();

		GetTarget();
		GetActions();

		if((m_Target && !m_Hidden) || (m_Interact || m_ContinuousInteract || m_Single || m_Continuous) && m_AM.GetRunningAction() == null)
		{
			//! cursor with fixed position (environment interaction mainly)
			if ( m_Target.GetObject() == null && (m_Interact || m_ContinuousInteract || m_Single || m_Continuous))
			{
				//Print(">> fixed widget");
				m_CachedObject.Invalidate();
				BuildFixedCursor();
				m_Root.Show(true);
				m_FixedOnPosition = false;
				return;
			}
			else if (m_Target.GetObject() != null)
			{
				CheckRefresherFlagVisibility(m_Target.GetObject());
				//! build cursor for new target
				if ( m_Target.GetObject() != m_CachedObject.Get() )
				{
					if (!m_FixedOnPosition)
					{
						//Print(">> non-cached widget");
						m_CachedObject.Invalidate();
						BuildFloatingCursor(true);
						m_Root.Show(true);
						return;
					}
					else
					{
						//Print(">> non-cached widget (fixed)");
						m_CachedObject.Invalidate();
						BuildFixedCursor();
						m_Root.Show(true);
						m_FixedOnPosition = false;
						return;
					}
				}
				//! use cached version for known target - recalculate onscreen pos only
				else if (m_Target.GetObject() == m_CachedObject.Get())
				{
					if (!m_FixedOnPosition)
					{
						//Print(">> cached widget");
						BuildFloatingCursor(false);
						m_Root.Show(true);
						return;
					}
					else
					{
						//Print(">> cached widget (fixed)");
						m_CachedObject.Invalidate();
						BuildFixedCursor();
						m_Root.Show(true);
						m_FixedOnPosition = false;
						return;
					}
				}
			}
			else
			{
				if (m_Root.IsVisible())
				{
					m_CachedObject.Invalidate();
					m_Root.Show(false);				

					// remove previous backlit
					GetDayZGame().GetBacklit().HintClear();
				}
			}
		}
		else
		{
			if (m_Root.IsVisible())
			{
				m_CachedObject.Invalidate();
				m_Root.Show(false);
				m_FixedOnPosition = false;

				// remove previous backlit
				GetDayZGame().GetBacklit().HintClear();
			}
		}
		
		m_MaxWidthChild = 350;
	}
	
	protected void ShowXboxHidePCIcons( string widget, bool show_xbox_icon )
	{
		m_Root.FindAnyWidget( widget + "_btn_icon_xbox" ).Show( show_xbox_icon );
		m_Root.FindAnyWidget( widget + "_btn_icon" ).Show( !show_xbox_icon );
	}


	//! transform world pos to screen pos (related to parent widget size)
	protected vector TransformToScreenPos(vector pWorldPos)
	{
		float parent_width, parent_height;
		vector transformed_pos, screen_pos;
		
		//! get relative pos for screen from world pos vector
		screen_pos = GetGame().GetScreenPosRelative( pWorldPos );
		//! get size of parent widget
		m_Root.GetParent().GetScreenSize(parent_width, parent_height);
		
		//! calculate corrent position from relative pos and parent widget size
		transformed_pos[0] = screen_pos[0] * parent_width;
		transformed_pos[1] = screen_pos[1] * parent_height;
		
		return transformed_pos;
	}

	protected void GetOnScreenPosition(out float x, out float y)
	{
		const float 	DEFAULT_HANDLE_OFFSET 	= 0.2;
		const string 	CE_CENTER_COMP_NAME 	= "ce_center";
		const string 	MEM_LOD_NAME 			= "memory";
		
		int compIdx;
		float pivotOffset = 0.0;
		float memOffset   = 0.0;
		string compName;

		bool isTargetForced = false;
		
		vector worldPos;
		vector modelPos;

		LOD lod;

		ref array<Selection> memSelections	= new array<Selection>();
		ref array<string> components = new array<string>; // for components with multiple selection
		
		Object object;

		if(m_Target)
		{
			object = m_Target.GetObject();
			compIdx  = m_Target.GetComponentIndex();

			if(m_Target.GetCursorHitPos() == vector.Zero)
				isTargetForced = true;
		}
		else
		{
			return;
		}

		if(object)
		{
			if(!isTargetForced)
			{
				compName = object.GetActionComponentName( compIdx );
				object.GetActionComponentNameList( compIdx, components );	
				pivotOffset	= object.ConfigGetFloat( "actionTargetPivotOffsetY" );
				memOffset	= object.ConfigGetFloat( "actionTargetMemOffsetY" );
	
				//! Get memory LOD from p3d
				lod = object.GetLODByName(MEM_LOD_NAME);
				if(lod != null)
				{
					//! save selection from memory lod
					lod.GetSelections(memSelections);

					// items with CE_Center mem point
					if( IsComponentInSelection( memSelections, CE_CENTER_COMP_NAME ) )
					{
						for( int i2 = 0; i2 < memSelections.Count(); ++i2 )
						{
							if( memSelections[i2].GetName() == CE_CENTER_COMP_NAME && memSelections[i2].GetVertexCount() == 1 )
							{
								m_FixedOnPosition = false;
								modelPos = object.GetSelectionPositionMS( CE_CENTER_COMP_NAME );
								worldPos = object.ModelToWorld( modelPos );
								if ( memOffset != 0.0 )
								{
									worldPos[1] = worldPos[1] + memOffset;
								}
								else
								{
									worldPos[1] = worldPos[1] + DEFAULT_HANDLE_OFFSET;
								}
							}
						}

						//! cache current object and the widget world pos
						m_CachedObject.Store(object, worldPos, compIdx);
					}
					//! doors/handles
					else if( !compName.Contains("ladder") && IsComponentInSelection( memSelections, compName ) )
					{
						for( int i1 = 0; i1 < memSelections.Count(); ++i1 )
						{
							//! single vertex in selection
							if( memSelections[i1].GetName() == compName && memSelections[i1].GetVertexCount() == 1 )
							{
								modelPos = object.GetSelectionPositionMS( compName );
								worldPos = object.ModelToWorld( modelPos );

								m_FixedOnPosition = false;
								if ( object.GetType() == "Fence" || object.GetType() == "Watchttower" )
									m_FixedOnPosition = true;
								
								if ( memOffset != 0.0 )
								{
									worldPos[1] = worldPos[1] + memOffset;
								}
								else
								{
									worldPos[1] = worldPos[1] + DEFAULT_HANDLE_OFFSET;
								}
							}

							//! multiple vertices in selection
							if ( memSelections[i1].GetName() == compName && memSelections[i1].GetVertexCount() > 1 )
							{
								for( int j = 0; j < components.Count(); ++j )
								{
									if( IsComponentInSelection(memSelections, components[j]) )
									{
										modelPos = object.GetSelectionPositionMS( components[j] );
										worldPos = object.ModelToWorld( modelPos );

										m_FixedOnPosition = false;
										if ( memOffset != 0.0 )
										{
											worldPos[1] = worldPos[1] + memOffset;
										}
										else
										{
											worldPos[1] = worldPos[1] + DEFAULT_HANDLE_OFFSET;
										}
									}
								}
							}
						}
						
						//! cache current object and the widget world pos
						m_CachedObject.Store(object, worldPos, -1); //! do not store component index for doors/handles
					}
					//! ladders handling
					else if( compName.Contains("ladder") && IsComponentInSelection( memSelections, compName))
					{
						vector ladderHandlePointLS, ladderHandlePointWS;
						vector closestHandlePos;
						float lastDistance = 0;
	
						for( int i3 = 0; i3 < memSelections.Count(); ++i3 )
						{
							if ( memSelections[i3].GetName() == compName && memSelections[i3].GetVertexCount() > 1 )
							{
								ladderHandlePointLS = memSelections[i3].GetVertexPosition(lod, 0);
								ladderHandlePointWS = object.ModelToWorld( ladderHandlePointLS );
								closestHandlePos = ladderHandlePointWS;
								lastDistance = Math.AbsFloat(vector.DistanceSq(ladderHandlePointWS, m_Player.GetPosition()));
	
								for( int k = 1; k < memSelections[i3].GetVertexCount(); ++k )
								{
									ladderHandlePointLS = memSelections[i3].GetVertexPosition(lod, k);
									ladderHandlePointWS = object.ModelToWorld( ladderHandlePointLS );
									
									if ( lastDistance > Math.AbsFloat(vector.DistanceSq(ladderHandlePointWS, m_Player.GetPosition())) )
									{
										lastDistance = Math.AbsFloat(vector.DistanceSq(ladderHandlePointWS, m_Player.GetPosition()));
										closestHandlePos = ladderHandlePointWS;
									}
								}

								m_FixedOnPosition = false;
								worldPos = closestHandlePos;						
								if ( memOffset != 0.0 )
								{
									worldPos[1] = worldPos[1] + memOffset;
								}
								else
								{
									worldPos[1] = worldPos[1] + DEFAULT_HANDLE_OFFSET;
								}
							}
						}

						//! cache current object and the widget world pos
						m_CachedObject.Store(object, worldPos, -1); //! do not store component index for ladders
					}
					else
					{
						m_FixedOnPosition = true;
					}
				}
				else
				{
					m_FixedOnPosition = true;
				}
			}
			else
			{
				m_FixedOnPosition = true;
			}

			vector pos = TransformToScreenPos(worldPos);

			x = pos[0];
			y = pos[1];
		}

		worldPos = vector.Zero;
		isTargetForced = false;
	}

	protected bool IsComponentInSelection( array<Selection> selection, string compName )
	{
		if (selection.Count() == 0 || compName.Length() == 0) return false;

		for ( int i = 0; i < selection.Count(); ++i )
		{
			compName.ToLower();
			if ( selection[i] && selection[i].GetName() == compName )
			{
				return true;
			}
		}
		return false;
	}

	// getters

 	protected void GetPlayer()
	{
		Class.CastTo(m_Player, GetGame().GetPlayer());
	}

	protected void GetActionManager()
	{
		if( m_Player && m_Player.IsPlayerSelected() )
		{
			Class.CastTo(m_AM, m_Player.GetActionManager());
		}
		else
		{
			m_AM = null;
		}
	}

	//! get actions from Action Manager
  	protected void GetActions()
	{
		m_Interact = null;
		m_ContinuousInteract = null;
		m_Single = null;
		m_Continuous = null;

		if(!m_AM) return;
		if(!m_Target) return;
		if(m_Player.IsSprinting()) return;
		if(m_Player.IsInVehicle()) return; // TODO: TMP: Car AM rework needed
			
		array<ActionBase> possible_interact_actions = m_AM.GetPossibleActions(InteractActionInput);
		array<ActionBase> possible_continuous_interact_actions = m_AM.GetPossibleActions(ContinuousInteractActionInput);
		int possible_interact_actions_index = m_AM.GetPossibleActionIndex(InteractActionInput);
		int possible_continuous_interact_actions_index = m_AM.GetPossibleActionIndex(ContinuousInteractActionInput);
		
		m_InteractActionsNum = possible_interact_actions.Count();
		if( m_InteractActionsNum > 0 )
		{
			m_Interact = possible_interact_actions[possible_interact_actions_index];
			m_DisplayInteractTarget = m_Interact.GetDisplayInteractObject(m_Player,m_Target);
		}
		else
		{
			m_DisplayInteractTarget	= null;
		}
		
		m_ContinuousInteractActionsNum = possible_continuous_interact_actions.Count();
		if( m_ContinuousInteractActionsNum > 0 )
		{
			m_ContinuousInteract = possible_continuous_interact_actions[possible_continuous_interact_actions_index];
		}
		
		
		m_Single = m_AM.GetPossibleAction(DefaultActionInput);
		m_Continuous = m_AM.GetPossibleAction(ContinuousDefaultActionInput);
	}

	protected void GetTarget()
	{
		if(!m_AM) return;

		m_Target = m_AM.FindActionTarget();
		m_Hidden = false;

		if (m_Target && m_Target.GetObject() && m_Target.GetObject().IsItemBase())
		{
			ItemBase item = ItemBase.Cast(m_Target.GetObject());
			if( !item.IsTakeable() || (m_Player && m_Player.IsInVehicle()) )
			{
				m_Hidden = true;
			}
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
	
	//getting name of the entity
	protected string GetItemDesc(ActionBase action)
	{
		string desc = "";
		Object tgObject = m_DisplayInteractTarget;
		if(!tgObject && m_Target)
		{
			tgObject = m_Target.GetObject();
		}
		
		if(tgObject)
		{
			if( tgObject.IsItemBase() || tgObject.IsTransport() )
			{
				desc = tgObject.GetDisplayName();
			}
			else if( !tgObject.IsAlive() )
			{
				desc = tgObject.GetDisplayName();
			}
		}
		return desc;
	}
	
	protected int GetItemHealth()
	{
		int health = -1;

		if ( m_Interact && !m_Interact.HasTarget() )
		{
			return health;
		}
		
		Object tgObject = m_DisplayInteractTarget;
		if(!tgObject && m_Target)
		{
			tgObject = m_Target.GetObject();
		}
		
		if ( tgObject )
		{
			if ( tgObject.IsHealthVisible() )
			{
				//bool showZoneHealth = true;
				if ( tgObject.ShowZonesHealth() && !tgObject.IsDamageDestroyed() )
				{
					//
					string zone = "";
					string compName;
					array<string> selections = new array<string>();

					//NOTE: relevant fire geometry and view geometry selection names MUST match in order to get a valid damage zone
					tgObject.GetActionComponentNameList( m_Target.GetComponentIndex(), selections, "view" );

					for ( int s = 0; s < selections.Count(); s++ )
					{
						compName = selections[s];
						EntityAI targetEntity = EntityAI.Cast( tgObject );

						if ( targetEntity && DamageSystem.GetDamageZoneFromComponentName( targetEntity , compName, zone))
						{
							health = m_Target.GetObject().GetHealthLevel(zone);
							//Print(zone);
							break;
						}
					}

					if ( zone == "" )
						health = m_Target.GetObject().GetHealthLevel();
				}
				else
				{
					health = m_Target.GetObject().GetHealthLevel();
				}

			}
			else if ( !m_Target.GetObject().IsAlive() )
			{
				health = m_Target.GetObject().GetHealthLevel();
			}
		}
		
		return health;
	}

	protected void GetItemQuantity(out int q_type, out float q_cur, out int q_min, out int q_max)
	{
		InventoryItem item = null;

		if(m_Interact && !m_Interact.HasTarget())
		{
			return;
		}
		
		Object tgObject = m_DisplayInteractTarget;
		if(!tgObject && m_Target)
		{
			tgObject = m_Target.GetObject();
		}
		
		if( Class.CastTo(item, tgObject) )
		{
			q_type = QuantityConversions.HasItemQuantity(item);
			if (q_type > 0)
				QuantityConversions.GetItemQuantity(item, q_cur, q_min, q_max);
		}
	}

	//! returns number of item in cargo for targeted entity
	protected void GetItemCargoCount(out int cargoCount)
	{
		CargoBase cargo = null;
		EntityAI entity = null;
		PlayerBase player;
		
		Object tgObject = m_DisplayInteractTarget;
		if(!tgObject && m_Target)
		{
			tgObject = m_Target.GetObject();
		}

		if( Class.CastTo(entity,tgObject) )
		{
			//! player specific way
			if (entity.IsInherited(PlayerBase))
			{					
				if (Class.CastTo(player, entity))
				{
					int attCount = player.GetHumanInventory().AttachmentCount();

					//! go thru the each attachment slot and check cargo count
					for(int attIdx = 0; attIdx < attCount; attIdx++)
					{
						EntityAI attachment = player.GetInventory().GetAttachmentFromIndex(attIdx);
						int attachmentSlot = attachment.GetInventory().GetSlotId(0);
						if( attachment.GetInventory() )
						{
							cargo = attachment.GetInventory().GetCargo();
							if( cargo )
							{
								cargoCount += cargo.GetItemCount();
							}
						}
						
					}
					
					return;
				}
			}
			else
			{
				if(entity.GetInventory())
				{
					cargo = entity.GetInventory().GetCargo();
	
					if (cargo)
					{
						cargoCount = cargo.GetItemCount();
						return;
					}
				}
			}

			//! default cargo count
			cargoCount = 0;
		}
	}

	// setters
	protected void SetItemDesc(string descText, int cargoCount, string itemWidget, string descWidget)
	{
		Widget widget;
		widget = m_Root.FindAnyWidget(itemWidget);
		
		//! Last message from finished User Action on target (Thermometer, Blood Test Kit, etc. )
		PlayerBase playerT = PlayerBase.Cast(m_Target.GetObject());
		if (playerT)
			string msg = playerT.GetLastUAMessage();
				
		if(descText.Length() == 0 && msg.Length() == 0)
		{
			widget.Show(false);
			return;
		}
		
		descText.ToUpper();
		TextWidget itemName;
		Class.CastTo(itemName, widget.FindAnyWidget(descWidget));
	
		//! when cargo in container
		if (cargoCount > 0)
		{
			descText = string.Format("[+] %1  %2", descText, msg);
			itemName.SetText(descText);		
		}
		else
			descText = string.Format("%1  %2", descText, msg);
			itemName.SetText(descText);

		widget.Show(true);
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
					}
					else
					{
						progressBar.Show(false);
						textWidget.Show(false);
						textWidget.GetParent().Show(false);
					}
					break;
				case QUANTITY_PROGRESS :
					float qty_num = Math.Round( ( current / max ) * 100 );
	
					textWidget.Show(false);
					progressBar.SetCurrent(qty_num);
					progressBar.Show(true);
					textWidget.GetParent().Show(true);
					break;
			}
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
		
		if(action)
		{
			if(action.HasTarget() && m_AM.GetActionState() < 1) // targeted & action not performing
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
				
				int x, y;
				actionName.GetTextSize(x, y);
				if (x > m_MaxWidthChild);
					m_MaxWidthChild = x;
			}
			else
			{
				widget.Show(false);			
			}
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
		GetDayZGame().GetBacklit().HintShow(i1);
		
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
	
	protected void CheckRefresherFlagVisibility(Object object)
	{
		EntityAI entity;
		Widget w = m_Root.FindAnyWidget("item_flag_icon");
		if ( Class.CastTo(entity,object) && w )
		{
			w.Show(entity.IsRefresherSignalingViable() && m_Player.IsTargetInActiveRefresherRange(entity));
		}
	}
}