// #include "Scripts/GUI/IngameHud.c"

class MissionGameplay extends MissionBase
{
	int								m_LifeState;
	bool							m_Initialized;
	
	protected UIManager				m_UIManager;
	
	Widget							m_HudRootWidget;
	ImageWidget 					m_MicrophoneIcon;
	
	ref InventoryMenu				m_InventoryMenu;
	ref Chat 						m_Chat;
	ref ActionMenu					m_ActionMenu;
	ref IngameHud					m_Hud;
	ref HudDebug					m_HudDebug;
	ref LogoutMenu					m_Logout;
	ref DebugMonitor				m_DebugMonitor;
	
	ref Timer						m_ChatChannelHideTimer;
	ref WidgetFadeTimer				m_ChatChannelFadeTimer;
	ref WidgetFadeTimer				m_MicFadeTimer;
	
	Widget							m_ChatChannelArea;
	TextWidget						m_ChatChannelText;
	NoteMenu 						m_Note;
	
	protected ref Timer				m_ToggleHudTimer;
	protected const int 			HOLD_LIMIT_TIME	= 300; //ms
	protected int					m_ActionDownTime;
	protected int					m_ActionUpTime;
	protected bool 					m_InitOnce;
	protected bool 					m_ControlDisabled;
	protected bool 					m_QuickbarHold;
	protected bool 					m_PlayerRespawning;
	protected int 					m_RespawnModeClient; //for client-side usage
	
	// von control info
	protected bool					m_VoNActive;
	protected Widget				m_VoiceLevels;
	protected ref map<int,ImageWidget> m_VoiceLevelsWidgets;
	protected ref map<int,ref WidgetFadeTimer> m_VoiceLevelTimers;
	
	void MissionGameplay()
	{
		DestroyAllMenus();
		m_Initialized				= false;
		m_HudRootWidget				= null;
		m_Chat						= new Chat;
		m_ActionMenu				= new ActionMenu;
		m_LifeState					= -1;
		m_Hud						= new IngameHud;
		m_VoNActive					= false;
		m_ChatChannelFadeTimer		= new WidgetFadeTimer;
		m_MicFadeTimer				= new WidgetFadeTimer;
		m_ChatChannelHideTimer		= new Timer(CALL_CATEGORY_GUI);
		m_ToggleHudTimer			= new Timer(CALL_CATEGORY_GUI);
		
		m_ActiveRefresherLocations 	= new array<vector>;
		SyncEvents.RegisterEvents();
	}
	
	void ~MissionGameplay()
	{
		DestroyInventory();
		PPEffects.ResetAll();
		//GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.UpdateDebugMonitor);
	#ifndef NO_GUI
		if (g_Game.GetUIManager() && g_Game.GetUIManager().ScreenFadeVisible())
		{
			g_Game.SetEVValue(0);
			g_Game.GetUIManager().ScreenFadeOut(0);
		}
	#endif
	}
	
	InventoryMenu GetInventory()
	{
		return m_InventoryMenu;
	}
	
	override void OnInit()
	{
		super.OnInit();

		if ( m_Initialized )
		{
			return;
		}
			
		PPEffects.Init();
		MapMarkerTypes.Init();
		
		m_UIManager = GetGame().GetUIManager();
			
		m_Initialized				= true;

		// init hud ui
		if ( !m_HudRootWidget )
		{
			m_HudRootWidget			= GetGame().GetWorkspace().CreateWidgets("gui/layouts/day_z_hud.layout");
			
			m_HudRootWidget.Show(false);
			
			m_Chat.Init(m_HudRootWidget.FindAnyWidget("ChatFrameWidget"));
			
			m_ActionMenu.Init( m_HudRootWidget.FindAnyWidget("ActionsPanel"), TextWidget.Cast( m_HudRootWidget.FindAnyWidget("DefaultActionWidget") ) );
			
			m_Hud.Init( m_HudRootWidget.FindAnyWidget("HudPanel") );
			
			// von enabled icon
			m_MicrophoneIcon = ImageWidget.Cast( m_HudRootWidget.FindAnyWidget("mic") );
			m_MicrophoneIcon.Show(false);
			
			// von voice level
			m_VoiceLevels = m_HudRootWidget.FindAnyWidget("VoiceLevelsPanel");
			m_VoiceLevelsWidgets = new map<int, ImageWidget>; // [key] voice level
			m_VoiceLevelTimers = new map<int,ref WidgetFadeTimer>; // [key] voice level
		
			if( m_VoiceLevels )
			{
				m_VoiceLevelsWidgets.Set(VoiceLevelWhisper, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Whisper") ));
				m_VoiceLevelsWidgets.Set(VoiceLevelTalk, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Talk") ));
				m_VoiceLevelsWidgets.Set(VoiceLevelShout, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Shout") ));
				
				m_VoiceLevelTimers.Set(VoiceLevelWhisper, new WidgetFadeTimer);
				m_VoiceLevelTimers.Set(VoiceLevelTalk, new WidgetFadeTimer);
				m_VoiceLevelTimers.Set(VoiceLevelShout, new WidgetFadeTimer);
			}
			
			HideVoiceLevelWidgets();
			
			// chat channel
			m_ChatChannelArea		= m_HudRootWidget.FindAnyWidget("ChatChannelPanel");
			m_ChatChannelText		= TextWidget.Cast( m_HudRootWidget.FindAnyWidget("ChatChannelText") );
		}
		
		// init hud ui
		if ( GetGame().IsDebug() )
		{
			m_HudDebug				= new HudDebug;
			
			if ( !m_HudDebug.IsInitialized() )
			{
				m_HudDebug.Init( GetGame().GetWorkspace().CreateWidgets("gui/layouts/debug/day_z_hud_debug.layout") );
				
				Debug.SetEnabledLogs(PluginConfigDebugProfile.GetInstance().GetLogsEnabled());
			}
		}

		//AIBehaviourHL.RegAIBehaviour("zombie2",AIBehaviourHLZombie2,AIBehaviourHLDataZombie2);
		//RegBehaviour("zombie2",AIBehaviourHLZombie2,AIBehaviourHLDataZombie2);
		
		if( GetGame().IsMultiplayer() )
		{
			OnlineServices.m_MuteUpdateAsyncInvoker.Insert( SendMuteListToServer );
		}
	}
	
	UIManager GetUIManager()
	{
		return m_UIManager;
	}

	override void OnMissionStart()
	{
		g_Game.SetConnecting(false);
		//does not display HUD until player is fully loaded
		//m_HudRootWidget.Show(true);
		GetUIManager().ShowUICursor(false);
		g_Game.SetMissionState( DayZGame.MISSION_STATE_GAME );
	}
	
	void InitInventory()
	{
		if ( !m_InventoryMenu )
		{
			m_InventoryMenu = InventoryMenu.Cast( GetUIManager().EnterScriptedMenu(MENU_INVENTORY, NULL) );
			GetUIManager().HideScriptedMenu( m_InventoryMenu );
		}
	}
	
	void TickScheduler(float timeslice)
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
				
		if( player )
			player.OnScheduledTick(timeslice);
	}
	
	void SendMuteListToServer( map<string, bool> mute_list )
	{
		if( mute_list && mute_list.Count() > 0 )
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write(mute_list);
			rpc.Send(null, ERPCs.RPC_USER_SYNC_PERMISSIONS, true, null);
		}
	}
	
	override void OnMissionFinish()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		Print("OnMissionFinish");
		GetUIManager().HideDialog();
		DestroyAllMenus();
		
		m_Chat.Destroy();
		delete m_HudRootWidget;
		
		#ifdef PLATFORM_CONSOLE
			OnlineServices.m_MuteUpdateAsyncInvoker.Remove( SendMuteListToServer );
		#endif

		if (m_DebugMonitor)
			m_DebugMonitor.Hide();
		g_Game.GetUIManager().ShowUICursor(false);
		g_Game.SetMissionState( DayZGame.MISSION_STATE_FINNISH );
	}
	
	override void OnUpdate(float timeslice)
	{
		Man player = GetGame().GetPlayer();
		PlayerBase playerPB = PlayerBase.Cast(player);
		TickScheduler(timeslice);
		UpdateDummyScheduler();//for external entities
		UIScriptedMenu menu = m_UIManager.GetMenu();
		InventoryMenu inventory = InventoryMenu.Cast( m_UIManager.FindMenu(MENU_INVENTORY) );
		MapMenu map_menu = MapMenu.Cast( m_UIManager.FindMenu(MENU_MAP) );
		NoteMenu note_menu = NoteMenu.Cast( m_UIManager.FindMenu(MENU_NOTE) );
		GesturesMenu gestures_menu = GesturesMenu.Cast(m_UIManager.FindMenu(MENU_GESTURES));
		RadialQuickbarMenu quickbar_menu = RadialQuickbarMenu.Cast(m_UIManager.FindMenu(MENU_RADIAL_QUICKBAR));
		//m_InventoryMenu = inventory;
		InspectMenuNew inspect = InspectMenuNew.Cast( m_UIManager.FindMenu(MENU_INSPECT) );
		Input input = GetGame().GetInput();
		//UAInput input = GetUApi().GetInputByID(GetUApi().DeterminePressedButton());
		
		//TODO should be switchable
		if ( playerPB )
		{
			#ifdef DEVELOPER
			if ( DiagMenu.GetBool(DiagMenuIDs.DM_HOLOGRAM) )
			{
				DbgUI.BeginCleanupScope();
				DbgUI.Begin("Hologram Debug", 5, 5);
			}
			#endif
			
			if ( playerPB.GetHologramLocal() )
			{
				playerPB.GetHologramLocal().UpdateHologram( timeslice );
			}
			#ifdef DEVELOPER
			else if ( DiagMenu.GetBool(DiagMenuIDs.DM_HOLOGRAM) )
			{	
				DbgUI.Text("No active Hologram");
			}
			
			if ( DiagMenu.GetBool(DiagMenuIDs.DM_HOLOGRAM) )
			{		
				DbgUI.End();
				DbgUI.EndCleanupScope();
			}
			#endif
			
			/*if( !menu && m_ControlDisabled && !playerPB.GetCommand_Melee2() )
			{
				PlayerControlEnable(true);
			}*/
		}

#ifdef PLATFORM_CONSOLE
		//Radial quickbar
		if( input.LocalPress("UAUIQuickbarRadialOpen",false) )
		{
			//open quickbar menu
			if ( playerPB.IsAlive() && !playerPB.IsRaised() && !playerPB.GetCommand_Vehicle() )	//player hands not raised, player is not in prone and player is not interacting with vehicle
			{
				if ( !GetUIManager().IsMenuOpen( MENU_RADIAL_QUICKBAR ) )
				{
					RadialQuickbarMenu.OpenMenu();
					m_Hud.ShowHudUI( false );
					/*if (!m_ControlDisabled)
					{
						PlayerControlDisable(INPUT_EXCLUDE_MOUSE_RADIAL);
						GetUApi().GetInputByName("UAUIQuickbarRadialOpen").Unlock();
					}*/
				}	
			}
		}
		
		if( input.LocalRelease("UAUIQuickbarRadialOpen",false) )
		{
			//close quickbar menu
			if ( GetUIManager().IsMenuOpen( MENU_RADIAL_QUICKBAR ) )
			{
				RadialQuickbarMenu.CloseMenu();
				quickbar_menu.SetMenuClosing(true);
				PlayerControlEnable(false);
				m_Hud.ShowHudUI( true );
			}
		}
		
		//Radial Quickbar from inventory
		if( GetGame().GetInput().LocalRelease("UAUIQuickbarRadialInventoryOpen",false) )
		{
			//close radial quickbar menu
			if ( GetGame().GetUIManager().IsMenuOpen( MENU_RADIAL_QUICKBAR ) )
			{
				PlayerControlDisable( INPUT_EXCLUDE_ALL );
				RadialQuickbarMenu.CloseMenu();
				//PlayerControlEnable(false);
				RadialQuickbarMenu.SetItemToAssign( NULL );
			}
		}
		
		//Special behaviour for leaning [CONSOLE ONLY]
		if ( playerPB && !GetGame().IsInventoryOpen() )
		{
			if ( playerPB.IsRaised() || playerPB.IsInRasedProne() )
			{
				GetUApi().GetInputByName( "UALeanLeft" 	).Unlock();
				GetUApi().GetInputByName( "UALeanRight" ).Unlock();
			}
			else
			{
				GetUApi().GetInputByName( "UALeanLeft" 	).Lock();
				GetUApi().GetInputByName( "UALeanRight" ).Lock();	
			}
		}
		
		//Special behaviour for freelook & zeroing [CONSOLE ONLY]
		if ( playerPB )
		{
			if ( playerPB.IsRaised() )
			{
				GetUApi().GetInputByName( "UALookAround" 	).Lock();		//disable freelook
				
				GetUApi().GetInputByName( "UAZeroingUp" 	).Unlock();		//enable zeroing
				GetUApi().GetInputByName( "UAZeroingDown" 	).Unlock();
			}
			else
			{
				GetUApi().GetInputByName( "UALookAround" 	).Unlock();	//enable freelook
				
				GetUApi().GetInputByName( "UAZeroingUp" 	).Lock();		//disable zeroing
				GetUApi().GetInputByName( "UAZeroingDown" 	).Lock();
			}		
		}	
#endif
		//Gestures
		if( input.LocalPress("UAUIGesturesOpen",false) )
		{
			//open gestures menu
			if ( !playerPB.IsRaised() && (playerPB.GetActionManager().ActionPossibilityCheck(playerPB.m_MovementState.m_CommandTypeId) || playerPB.IsEmotePlaying()) && !playerPB.GetCommand_Vehicle() )
			{
				if ( !GetUIManager().IsMenuOpen( MENU_GESTURES ) )
				{
					GesturesMenu.OpenMenu();
					m_Hud.ShowHudUI( false );
					/*if (!m_ControlDisabled)
					{
						PlayerControlDisable(INPUT_EXCLUDE_MOUSE_RADIAL);
						GetUApi().GetInputByName("UAUIGesturesOpen").Unlock();
					}*/
				}
			}
		}
		
		if( input.LocalRelease("UAUIGesturesOpen",false) )
		{
			//close gestures menu
			if ( GetUIManager().IsMenuOpen( MENU_GESTURES ) )
			{
				GesturesMenu.CloseMenu();
				gestures_menu.SetMenuClosing(true);
				PlayerControlEnable(false);
				m_Hud.ShowHudUI( true );
			}
		}
		
		//if(GetUApi().GetInputByName("UADropitem").LocalPress())
		/*if( input.LocalPress("UADropitem",false) )
		{
			//drops item
			if (playerPB && playerPB.GetItemInHands() && !GetUIManager().GetMenu())
			{
				ActionManagerClient manager = ActionManagerClient.Cast(playerPB.GetActionManager());
				manager.ActionDropItemStart(playerPB.GetItemInHands(),null);
			}
		}*/

		if (player && m_LifeState == EPlayerStates.ALIVE && !player.IsUnconscious() )
		{
			// enables HUD on spawn
			if (m_HudRootWidget)
			{
				m_HudRootWidget.Show(true);
			}
			
		#ifndef NO_GUI
			// fade out black screen
			
			if ( GetUIManager().ScreenFadeVisible() )
			{
				 GetUIManager().ScreenFadeOut(0.5);
			}
			
		#endif
		
			if( input.LocalPress("UAGear",false) )
			{
				if( !inventory && playerPB.CanManipulateInventory() )
				{
					ShowInventory();
					menu = m_InventoryMenu;
				}
				else if( menu == inventory )
				{
					HideInventory();
				}
			}
			#ifndef PLATFORM_CONSOLE
			if( input.LocalPress("UAChat",false) )
			{
				ChatInputMenu chat = ChatInputMenu.Cast( m_UIManager.FindMenu(MENU_CHAT) );		
				if( menu == NULL )
				{
					ShowChat();
				}
			}
			#endif
			if( input.LocalPress("UAVoiceLevel",false) )
			{
				int oldLevel = GetGame().GetVoiceLevel();
				int newLevel = ( oldLevel + 1 ) % ( VoiceLevelShout + 1 );
				
				// update general voice icon
				UpdateVoiceLevelWidgets(newLevel);
				GetGame().SetVoiceLevel(newLevel);	
			}
			
			if( input.LocalHold("UAUIQuickbarToggle",false) )
			{
				if( !m_QuickbarHold )
				{
					m_QuickbarHold = true;
					SetActionDownTime( GetGame().GetTime() );
					//m_Hud.ShowHudPlayer( m_Hud.IsHideHudPlayer() );
					m_Hud.ShowHud( !m_Hud.GetHudState() );
				}
			}
			
			if( input.LocalRelease("UAUIQuickbarToggle",false) )
			{
				if( !m_QuickbarHold )
					m_Hud.ShowQuickbarPlayer( m_Hud.IsHideQuickbarPlayer() );
				m_QuickbarHold = false;
			}
			
			if ( g_Game.GetInput().LocalPress("UAZeroingUp",false) || g_Game.GetInput().LocalPress("UAZeroingDown",false) || g_Game.GetInput().LocalPress("UAToggleWeapons",false) )
			{

				m_Hud.ZeroingKeyPress();
			}
			
			if ( menu == NULL )
			{
				m_ActionMenu.Refresh();
				
				if (input.LocalPress("UANextAction",false))
				{
					m_ActionMenu.NextAction();
				}
				
				if (input.LocalPress("UAPrevAction",false))
				{
					m_ActionMenu.PrevAction();
				}
			}
			else
			{
				m_ActionMenu.Hide();
			}
			
			//hologram rotation
			if (menu == NULL && playerPB.IsPlacingLocal() && playerPB.GetHologramLocal().GetParentEntity().PlacementCanBeRotated())
			{
				if( input.LocalRelease("UANextAction",false) )
				{
					playerPB.GetHologramLocal().SubtractProjectionRotation(15);
				}
				
				if( input.LocalRelease("UAPrevAction",false) )
				{
					playerPB.GetHologramLocal().AddProjectionRotation(15);
				}
			}
		}
		
		// life state check
		if (player)
		{
			int life_state = player.GetPlayerState();
			
			// life state changed
			if (m_LifeState != life_state)
			{
				m_LifeState = life_state;
				
				if (m_LifeState != EPlayerStates.ALIVE)
				{
					CloseAllMenus();
				}
			}
		}
		
		if (menu && !menu.UseKeyboard() && menu.UseMouse())
		{
			int i;
			for (i = 0; i < 5; i++)
			{
				input.DisableKey(i | INPUT_DEVICE_MOUSE);
				input.DisableKey(i | INPUT_ACTION_TYPE_DOWN_EVENT | INPUT_DEVICE_MOUSE);
				input.DisableKey(i | INPUT_ACTION_TYPE_DOUBLETAP | INPUT_DEVICE_MOUSE);
			}
			
			for (i = 0; i < 6; i++)
			{
				input.DisableKey(i | INPUT_DEVICE_MOUSE_AXIS);
			}
		}
		
		if (!m_UIManager.IsDialogVisible())
		{
			if ( menu )
			{
				if( menu == inspect )
				{
					if(input.LocalPress("UAGear",false))
					{
						if( ItemManager.GetInstance().GetSelectedItem() == NULL )
						{
							HideInventory();
						}
					}
					else if(input.LocalPress("UAUIBack",false))
					{
						if( ItemManager.GetInstance().GetSelectedItem() == NULL )
						{
							HideInventory();
						}
					}
				}
				else if(menu == map_menu && !m_ControlDisabled)
				{
					PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
				}
				else if(menu == note_menu && !m_ControlDisabled)
				{
					PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
				}
				else if(menu == gestures_menu && !m_ControlDisabled && !gestures_menu.IsMenuClosing())
				{
					PlayerControlDisable(INPUT_EXCLUDE_MOUSE_RADIAL);
					GetUApi().GetInputByName("UAUIGesturesOpen").Unlock();
				}
				else if(menu == quickbar_menu && !m_ControlDisabled && !quickbar_menu.IsMenuClosing())
				{
					PlayerControlDisable(INPUT_EXCLUDE_MOUSE_RADIAL);
					GetUApi().GetInputByName("UAUIQuickbarRadialOpen").Unlock();
				}
				else if( IsPaused() )
				{
					InGameMenuXbox menu_xb = InGameMenuXbox.Cast( GetGame().GetUIManager().GetMenu() );
					if( !g_Game.GetUIManager().ScreenFadeVisible() && ( !menu_xb || !menu_xb.IsOnlineOpen() ) )
					{
						if( input.LocalPress("UAUIMenu",false) )
						{
							Continue();
						}
						else if( input.LocalPress( "UAUIBack", false ) )
						{
							Continue();
						}
					}
					else if( input.LocalPress( "UAUIBack", false ) )
					{
						if( menu_xb && menu_xb.IsOnlineOpen() )
						{
							menu_xb.CloseOnline();
						}
					}
				}
			}
			else if (input.LocalPress("UAUIMenu",false))
			{
				Pause();
			}
			
			//final controls check that suppresses inputs to avoid input collision. If anything needed to be handled without forced input suppression, it had been at this point.
			if( playerPB )
			{
				if( !menu && m_ControlDisabled && !playerPB.GetCommand_Melee2() )
				{
					PlayerControlEnable(true);
				}
			}
		}
		
		UpdateDebugMonitor();
		
		SEffectManager.Event_OnFrameUpdate(timeslice);
		
		if (!GetGame().IsMultiplayer())
			m_WorldData.UpdateBaseEnvTemperature( timeslice );

#ifdef DEVELOPER
		DisplayHairDebug();
#endif
	}
	
	override void OnKeyPress(int key)
	{
		super.OnKeyPress(key);
		m_Hud.KeyPress(key);
		
#ifdef DEVELOPER
		if ( key == KeyCode.KC_Q )
		{
			
			
		}
#endif
	}
	
	override void OnKeyRelease(int key)
	{
		super.OnKeyRelease(key);
	}
	
	override void OnEvent(EventType eventTypeId, Param params)
	{
		super.OnEvent(eventTypeId, params);
		InventoryMenu menu;
		Man player = GetGame().GetPlayer();
		
		switch(eventTypeId)
		{
		case ChatMessageEventTypeID:
			ChatMessageEventParams chat_params = ChatMessageEventParams.Cast( params );			
			if (m_LifeState == EPlayerStates.ALIVE)
			{
				m_Chat.Add(chat_params);
			}
			break;
			
		case ChatChannelEventTypeID:
			ChatChannelEventParams cc_params = ChatChannelEventParams.Cast( params );
			ChatInputMenu chatMenu = ChatInputMenu.Cast( GetUIManager().FindMenu(MENU_CHAT_INPUT) );
			if (chatMenu)
			{
				chatMenu.UpdateChannel();
			}
			else
			{
				m_ChatChannelText.SetText(ChatInputMenu.GetChannelName(cc_params.param1));
				m_ChatChannelFadeTimer.FadeIn(m_ChatChannelArea, 0.5, true);
				m_ChatChannelHideTimer.Run(2, m_ChatChannelFadeTimer, "FadeOut", new Param3<Widget, float, bool>(m_ChatChannelArea, 0.5, true));
			}
			break;
			
		case WindowsResizeEventTypeID:
			DestroyAllMenus();
			m_Hud.OnResizeScreen();
			
			break;
			
		case VONStateEventTypeID:
			VONStateEventParams vonStateParams = VONStateEventParams.Cast( params );
			if (vonStateParams.param1)
			{
				m_MicrophoneIcon.SetAlpha(1.0);
				m_MicrophoneIcon.Show(true);
				
				m_VoNActive = true;
				
				int level = GetGame().GetVoiceLevel();
				UpdateVoiceLevelWidgets(level);	
			}
			else
			{
				m_MicrophoneIcon.Show(false);
				m_VoNActive = false;
				
				if( !GetUIManager().FindMenu(MENU_CHAT_INPUT) )
					HideVoiceLevelWidgets();
			}
			break;
		
		case SetFreeCameraEventTypeID:
			SetFreeCameraEventParams set_free_camera_event_params = SetFreeCameraEventParams.Cast( params );
			PluginDeveloper plugin_developer = PluginDeveloper.Cast( GetPlugin(PluginDeveloper) );
			plugin_developer.OnSetFreeCameraEvent( PlayerBase.Cast( player ), set_free_camera_event_params.param1 );
			break;
		}
	}
	
	override void OnItemUsed(InventoryItem item, Man owner)
	{
		if (item && GetUIManager().GetMenu() == NULL)
		{
			if (item.IsInherited(ItemBook))
			{
				BookMenu bookMenu = BookMenu.Cast( GetUIManager().EnterScriptedMenu(MENU_BOOK, NULL) );
				if (bookMenu)
				{
					bookMenu.ReadBook(item);
				}
			}
		}
	}
	
	override void PlayerControlEnable( bool bForceSupress )
	{
		super.PlayerControlEnable(bForceSupress);

		//Print("Enabling Controls");
		GetUApi().GetInputByName("UAWalkRunTemp").ForceEnable(false); // force walk off!
		GetUApi().UpdateControls();
		
		// supress control for next frame
		GetUApi().SupressNextFrame(bForceSupress);
		
		m_ControlDisabled = false;
		
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if (!player)
			return;
			
		HumanInputController hic = player.GetInputController();
		hic.LimitsDisableSprint(false);
	}

	//!movement restrictions
	override void PlayerControlDisable(int mode)
	{
		super.PlayerControlDisable(mode);

		//Print("Disabling Controls");
		switch (mode)
		{
			case INPUT_EXCLUDE_ALL:
			{
				GetUApi().ActivateExclude("menu");
				break;
			}
			case INPUT_EXCLUDE_INVENTORY:
			{
				GetUApi().ActivateExclude("inventory");
				GetUApi().GetInputByName("UAWalkRunTemp").ForceEnable(true); // force walk on!
				break;
			}
			case INPUT_EXCLUDE_MOUSE_ALL:
			{
				GetUApi().ActivateExclude("radialmenu");
				break;
			}
			case INPUT_EXCLUDE_MOUSE_RADIAL:
			{
				GetUApi().ActivateExclude("radialmenu");
				break;
			}
		}
		
		GetUApi().UpdateControls();
		m_ControlDisabled = true;
		
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if( player )
		{
			HumanInputController hic = player.GetInputController();
			//hic.ResetADS();
			player.RequestResetADSSync();
		}
	}
	
	override bool IsControlDisabled()
	{
		return m_ControlDisabled;
	}
	
	void CloseAllMenus()
	{
		GetUIManager().CloseAll();
	}
	
	
	void DestroyAllMenus()
	{
		if( GetUIManager() )
		{
			GetUIManager().HideDialog();
			GetUIManager().CloseAll();
		}
		
		DestroyInventory();
		
		if( m_Chat )
			m_Chat.Clear();
	}
	
	void MoveHudForInventory( bool inv_open )
	{
		#ifdef PLATFORM_CONSOLE
		IngameHud hud = IngameHud.Cast( GetHud() );
		if( hud )
		{
			if( inv_open )
			{
				hud.GetHudPanelWidget().SetPos( 0, -0.055 );
			}
			else
			{
				hud.GetHudPanelWidget().SetPos( 0, 0 );
			}
		}
		#endif
	}
	
	override void ShowInventory()
	{
		UIScriptedMenu menu = GetUIManager().GetMenu();
		
		if ( !menu && GetGame().GetPlayer().GetHumanInventory().CanOpenInventory() && !GetGame().GetPlayer().IsInventorySoftLocked() && GetGame().GetPlayer().GetHumanInventory().IsInventoryUnlocked() )
		{
			if( !m_InventoryMenu )
			{
				InitInventory();
			}
			
			if( !GetUIManager().FindMenu( MENU_INVENTORY ) )
			{
				GetUIManager().ShowScriptedMenu(m_InventoryMenu, null);
				PlayerBase.Cast(GetGame().GetPlayer()).OnInventoryMenuOpen();
			}
			MoveHudForInventory( true );
			PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
		}
	}
	
	override void HideInventory()
	{
		if( m_InventoryMenu )
		{
			GetUIManager().HideScriptedMenu(m_InventoryMenu);
			MoveHudForInventory( false );
			PlayerControlEnable(false);
			PlayerBase.Cast(GetGame().GetPlayer()).OnInventoryMenuClose();
			VicinityItemManager.GetInstance().ResetRefreshCounter();
		}	
	}
	
	void DestroyInventory()
	{
		if( m_InventoryMenu )
		{
			m_InventoryMenu.Close();
			m_InventoryMenu = NULL;
		}
	}
	
	override void ResetGUI()
	{
		DestroyInventory();
		InitInventory();
	}
	
	override void ShowChat()
	{
		m_ChatChannelHideTimer.Stop();
		m_ChatChannelFadeTimer.Stop();
		m_ChatChannelArea.Show(false);
		m_UIManager.EnterScriptedMenu(MENU_CHAT_INPUT, NULL);
		
		int level = GetGame().GetVoiceLevel();
		UpdateVoiceLevelWidgets(level);
		
		PlayerControlDisable(INPUT_EXCLUDE_ALL);		
	}

	override void HideChat()
	{
		PlayerControlEnable(true);
	}
	
	void ShowVehicleInfo()
	{
		if( GetHud() )
			GetHud().ShowVehicleInfo();
	}
	
	void HideVehicleInfo()
	{
		if( GetHud() )
			GetHud().HideVehicleInfo();
	}
	
	override Hud GetHud()
	{
		return m_Hud;
	}
	
	HudDebug GetHudDebug()
	{
		return m_HudDebug;
	}
	
	override void RefreshCrosshairVisibility()
	{
		GetHudDebug().RefreshCrosshairVisibility();
	}
	
	override void HideCrosshairVisibility()
	{
		GetHudDebug().HideCrosshairVisibility();
	}
	
	override bool IsPaused()
	{
		return GetGame().GetUIManager().IsMenuOpen(MENU_INGAME);
	}
	
	override void Pause()
	{
		if ( IsPaused() || ( GetGame().GetUIManager().GetMenu() && GetGame().GetUIManager().GetMenu().GetID() == MENU_INGAME ) )
			return;

		if ( g_Game.IsClient() && g_Game.GetGameState() != DayZGameState.IN_GAME )
			return;
		
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if ( player && !player.IsPlayerLoaded() || IsPlayerRespawning() )
			return;
		
		CloseAllMenus();
		
		// open ingame menu
		GetUIManager().EnterScriptedMenu( MENU_INGAME, GetGame().GetUIManager().GetMenu() );
		PlayerControlDisable(INPUT_EXCLUDE_ALL);
	}
	
	override void Continue()
	{
		int menu_id = GetGame().GetUIManager().GetMenu().GetID();
		if ( !IsPaused() || ( menu_id != MENU_INGAME && menu_id != MENU_LOGOUT && menu_id != MENU_RESPAWN_DIALOGUE ) || ( m_Logout && m_Logout.layoutRoot.IsVisible() ) )
		{
			return;
		}
		
		PlayerControlEnable(true);
		GetUIManager().CloseMenu(MENU_INGAME);
		//GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(CloseInGameMenu,1,true);
	}
	
	/*void CloseInGameMenu()
	{
		if (GetUIManager().IsMenuOpen(MENU_INGAME))
		{
			GetUIManager().CloseMenu(MENU_INGAME);
		}
		else
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(CloseInGameMenu);
		}
	}*/
	
	override bool IsMissionGameplay()
	{
		return true;
	}
	
	override void AbortMission()
	{
		#ifdef BULDOZER
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(g_Game.RequestExit, IDC_MAIN_QUIT);
		#else
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(GetGame().AbortMission);
		#endif
	}
	
	override void CreateLogoutMenu(UIMenuPanel parent)
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		// do not show logout screen if player's dead
		if (!player || player.IsDamageDestroyed())
		{
			// exit the game immediately
			AbortMission();
			return;
		}
		
		if (parent)
		{
			m_Logout = LogoutMenu.Cast(parent.EnterScriptedMenu(MENU_LOGOUT));
			
			if (m_Logout)
			{
				m_Logout.SetLogoutTime();
			}
		}		
	}
	
	override void StartLogoutMenu(int time)
	{
		if (m_Logout)
		{
			if (time > 0)
			{
				// character will be deleted from server int "time" seconds
				m_Logout.SetTime(time);
				m_Logout.Show();
				
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_Logout.UpdateTime, 1000, true);
			}
			else
			{
				// no waiting time -> player is most likely dead
				m_Logout.Exit();
			}
		}
	}
	
	override void CreateDebugMonitor()
	{
		if (!m_DebugMonitor)
		{
			m_DebugMonitor = new DebugMonitor();
			m_DebugMonitor.Init();
		}
	}
	
	void UpdateDebugMonitor()
	{
		if (!m_DebugMonitor) return;
		
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if (player)
		{
			DebugMonitorValues values = player.GetDebugMonitorValues();
			if (values)
			{
				m_DebugMonitor.SetHealth(values.GetHealth());
				m_DebugMonitor.SetBlood(values.GetBlood());
				m_DebugMonitor.SetLastDamage(values.GetLastDamage());
				m_DebugMonitor.SetPosition(player.GetPosition());
			}
		}
	}
	
	void SetActionDownTime( int time_down )
	{
		m_ActionDownTime = time_down;
	}
	
	void SetActionUpTime( int time_up )
	{
		m_ActionUpTime = time_up;
	}
	
	int LocalPressTime()
	{
		return m_ActionDownTime;
	}
	
	int LocalReleaseTime()
	{
		return m_ActionUpTime;
	}
	
	float GetHoldActionTime()
	{
		float hold_action_time = LocalReleaseTime() - LocalPressTime();
		return hold_action_time;
	}
	
	void DisplayHairDebug()
	{
		if ( DiagMenu.GetBool(DiagMenuIDs.DM_HAIR_DISPLAY_DEBUG) )
		{
			if(GetGame().IsClient() || !GetGame().IsMultiplayer())
				ShowHairDebugValues(true);
		}
		else
		{
			if(GetGame().IsClient() || !GetGame().IsMultiplayer())
				ShowHairDebugValues(false);
		}
	}
	
	void ShowHairDebugValues(bool state)
	{
#ifdef DEVELOPER
		if( state )
		{
			PluginDiagMenu diagmenu = PluginDiagMenu.Cast(GetPlugin(PluginDiagMenu));
			
			int i 					= DiagMenu.GetValue(DiagMenuIDs.DM_HAIR_LEVEL);
			bool bState 			= diagmenu.m_HairHidingStateMap.Get(i);
			string selectionState;
			if (!bState)
				selectionState 		= "Hidden";
			else
				selectionState 		= "Shown";
			string selectionName 	= diagmenu.m_HairSelectionArray.Get(i);
			
			DbgUI.BeginCleanupScope();
	        DbgUI.Begin("Hair Debug", 50, 150);
	        DbgUI.Text("Current Hair Selection:" + selectionName);
			DbgUI.Text("State: " + selectionState);
			
	        DbgUI.End();
	        DbgUI.EndCleanupScope();
		}
		else
		{
			DbgUI.BeginCleanupScope();
			DbgUI.Begin("Hair Debug", 50, 50);
			DbgUI.End();
	        DbgUI.EndCleanupScope();
		}
#endif
	}
	
	override void UpdateVoiceLevelWidgets(int level)
	{
		for( int n = 0; n < m_VoiceLevelsWidgets.Count(); n++ )
		{
			int voiceKey = m_VoiceLevelsWidgets.GetKey(n);
			ImageWidget voiceWidget = m_VoiceLevelsWidgets.Get(n);
			
			// stop fade timer since it will be refreshed
			ref WidgetFadeTimer timer = m_VoiceLevelTimers.Get(n);		
			timer.Stop();
		
			// show widgets according to the level
			if( voiceKey <= level )
			{
				voiceWidget.SetAlpha(1.0); // reset from possible previous fade out 
				voiceWidget.Show(true);
				
				if( !m_VoNActive && !GetUIManager().FindMenu(MENU_CHAT_INPUT) ) 	
					timer.FadeOut(voiceWidget, 3.0);	
			}
			else
				voiceWidget.Show(false);
		}
		
		// fade out microphone icon when switching levels without von on
		if( !m_VoNActive )
		{
		  	if( !GetUIManager().FindMenu(MENU_CHAT_INPUT) )
			{
				m_MicrophoneIcon.SetAlpha(1.0); 
				m_MicrophoneIcon.Show(true);
				
				m_MicFadeTimer.FadeOut(m_MicrophoneIcon, 3.0);
			}
		}
		else
		{
			// stop mic icon fade timer when von is activated
			m_MicFadeTimer.Stop();
		}
	}
	override bool IsVoNActive()
	{
		return m_VoNActive;
	}
	
	override void HideVoiceLevelWidgets()
	{
		for ( int n = 0; n < m_VoiceLevelsWidgets.Count(); n++ )
		{
			ImageWidget voiceWidget = m_VoiceLevelsWidgets.Get( n );
			voiceWidget.Show(false);
		}
	}
	
	override UIScriptedMenu GetNoteMenu()
	{
		return m_Note;
	};
	
	override void SetNoteMenu(UIScriptedMenu menu)
	{
		m_Note = NoteMenu.Cast(menu);
	};
	
	override void SetPlayerRespawning(bool state)
	{
		m_PlayerRespawning = state;
	}
	
	override bool IsPlayerRespawning()
	{
		return m_PlayerRespawning;
	}
	
	override array<vector> GetActiveRefresherLocations()
	{
		return m_ActiveRefresherLocations;
	}
	
	override void SetRespawnModeClient(int mode)
	{
		m_RespawnModeClient = mode;
	}
	
	override int GetRespawnModeClient()
	{
		return m_RespawnModeClient;
	}
}
