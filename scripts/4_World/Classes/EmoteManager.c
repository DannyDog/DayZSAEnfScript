class EmoteCB : HumanCommandActionCallback
{
	//const int 		CB_SURRENDER_STATE = 100;
	bool 			m_IsFullbody;
	int 			m_callbackID;
	PlayerBase 		m_player;
	EmoteManager 	m_Manager;
	
	bool CancelCondition()
	{
		return false;
	}
	
	bool IsEmoteCallback()
	{
		return IsGestureCallback();
	}
	
	override void OnAnimationEvent(int pEventID)
	{
		switch (pEventID)
		{
			case EMOTE_SUICIDE_DEATH :
				if (GetGame().IsServer())
					m_Manager.KillPlayer();
			break;
			
			case UA_ANIM_EVENT :
				if (GetGame().IsServer())
				{
					if ( m_player.GetItemInHands() && SurrenderDummyItem.Cast(m_player.GetItemInHands()) )
						m_player.GetItemInHands().Delete();
					
					if ( m_player.GetItemInHands() )
					{
						m_player.PhysicalPredictiveDropItem(m_player.GetItemInHands());
					}
				}
				m_Manager.m_ItemToBeCreated = true;
			break;
			
			case EMOTE_SUICIDE_BLEED :
				if (GetGame().IsServer())
					m_Manager.CreateBleedingEffect(m_callbackID);
			break;
			
			case EMOTE_SUICIDE_SIMULATION_END :
				if (GetGame().IsServer())
				{
					EntityAI itemInHands = m_player.GetHumanInventory().GetEntityInHands();
					if (itemInHands)
					{
						vector m4[4];
						itemInHands.GetTransform(m4);
						m_player.GetInventory().DropEntityWithTransform(InventoryMode.SERVER, m_player, itemInHands, m4);
					}
				}			
			break;
		}
	}
	
	override bool IsGestureCallback()
	{
		return true;
	}
};

class EmoteLauncher
{
	bool m_InterruptsSameIDEmote;
	int m_ID;
	
	void EmoteLauncher(int emoteID, bool interrupts_same)
	{
		m_ID = emoteID;
		m_InterruptsSameIDEmote = interrupts_same;
	}
}

class EmoteManager
{
	PlayerBase 				m_Player;
	ItemBase				m_item;
	EmoteCB					m_Callback;
	HumanInputController 	m_HIC;
	ref array<string> 		m_InterruptInputs;
	ref InventoryLocation 	m_HandInventoryLocation;
	ref EmoteLauncher 		m_MenuEmote;
	bool					m_bEmoteIsPlaying;
	bool 					m_IsSurrendered;
	bool 					m_ItemToBeCreated;
	bool 					m_CancelEmote;
	bool 					m_GestureInterruptInput;
	protected bool			m_ItemToHands;
	protected bool			m_ItemIsOn;
	protected bool			m_MouseButtonPressed;
	protected bool 			m_PlayerDies;
	protected bool 			m_controllsLocked;
	protected bool 			m_EmoteLockState;
	protected int 			m_DeferredEmoteExecution;
	protected int  			m_GestureID;
	protected int			m_PreviousGestureID;
	protected int			m_CurrentGestureID;
	protected int 			m_LastMask;
	protected int 			m_RPSOutcome;
	protected const int 	CALLBACK_CMD_INVALID = -1;
	protected const int 	CALLBACK_CMD_END = -2;
	protected const int 	CALLBACK_CMD_GESTURE_INTERRUPT = -3;
	//protected const int 	CALLBACK_CMD_SERVER = 0;
	//protected const int 	CALLBACK_CMD_CLIENT = 1;
	protected const float 	WATER_DEPTH = 0.15;
	PluginAdminLog 			m_AdminLog;
	ref Timer 				m_ReservationTimer;
	
	void EmoteManager( PlayerBase player ) 
	{
		m_Player = player;
		m_HIC = m_Player.GetInputController();
		m_ItemIsOn = false;
		m_RPSOutcome = -1;
		m_DeferredEmoteExecution = CALLBACK_CMD_INVALID;
		
		// new input-based interrupt actions
		m_InterruptInputs = new array<string>;
		m_InterruptInputs.Insert("UAMoveForward");
		m_InterruptInputs.Insert("UAMoveBack");
		m_InterruptInputs.Insert("UATurnLeft");
		m_InterruptInputs.Insert("UATurnRight");
		m_InterruptInputs.Insert("UAMoveLeft");
		m_InterruptInputs.Insert("UAMoveRight");
		m_InterruptInputs.Insert("UAStand");
		m_InterruptInputs.Insert("UACrouch");
		m_InterruptInputs.Insert("UAProne");
		m_InterruptInputs.Insert("UAGetOver");
		// end of new input-based interrupt actions
		
		m_HandInventoryLocation = new InventoryLocation;
		m_HandInventoryLocation.SetHands(m_Player,null);
		
		if( GetGame().IsServer() )
		{
			m_AdminLog = PluginAdminLog.Cast( GetPlugin(PluginAdminLog) );
		}
		
		m_ReservationTimer = new Timer();
		m_ReservationTimer.Run(8,this,"CheckEmoteLockedState",NULL,true);
	}
	
	void ~EmoteManager() 
	{
		if (m_ReservationTimer && m_ReservationTimer.IsRunning())
			m_ReservationTimer.Stop();
	}
	
	void SetGesture(int id)
	{
		m_GestureID = id;
	}
	
	int GetGesture()
	{
		return m_GestureID;
	}
	
	int DetermineGestureIndex()
	{
		// while player controls something else (car) - do not use gestures
		if( m_HIC.IsOtherController() )
			return 0;
	
		int gesture = m_HIC.IsGestureSlot();
		return gesture;
	}
	
	//Called from players commandhandler each frame, checks input
	void Update( float deltaT )
	{
		// no updates on restrained characters
		if (m_Player.IsRestrained())
			return;
		
		if (m_ItemToBeCreated)
		{
			if ( !m_Player.GetItemInHands() && GetGame().IsServer() )
			{
				m_Player.GetHumanInventory().CreateInHands("SurrenderDummyItem");
			}
			m_ItemToBeCreated = false;
		}
		
		int gestureSlot = DetermineGestureIndex();
		
		if ( m_DeferredEmoteExecution == CALLBACK_CMD_GESTURE_INTERRUPT )
		{
			//m_GestureInterruptInput = true;
		}
		
		if ( m_Callback )
		{
			bool uiGesture = false;
			if( !GetGame().IsMultiplayer() || GetGame().IsClient() )
			{
				uiGesture = GetGame().GetUIManager().IsMenuOpen(MENU_GESTURES);
				
				if (InterruptGestureCheck())
				{
					SendEmoteRequestSync(CALLBACK_CMD_END); //TODO CALLBACK_CMD_END CALLBACK_CMD_GESTURE_INTERRUPT
				}
			}
			
			if( (gestureSlot > 0 && gestureSlot != 12 ) || m_GestureInterruptInput || (m_HIC.IsSingleUse() && !uiGesture) || (m_HIC.IsContinuousUseStart() && !uiGesture) || (m_Callback.m_IsFullbody && !uiGesture && m_HIC.IsWeaponRaised()) ) 
			{
				/*if (m_GestureInterruptInput)
				{
					SendEmoteRequestSync(CALLBACK_CMD_END);
				}
				else */if (m_CurrentGestureID == ID_EMOTE_SUICIDE  && m_HIC.IsSingleUse())
				{
					if (m_Callback.GetState() == m_Callback.STATE_LOOP_LOOP)
					{
						CommitSuicide();
					}
					else
					{
						return;
					}
				}
				else if ( (m_CurrentGestureID == ID_EMOTE_THUMB || m_CurrentGestureID == ID_EMOTE_THUMBDOWN) && m_HIC.IsSingleUse() )
				{
					m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_ACTION);
				}
				else if ( m_CurrentGestureID == ID_EMOTE_RPS || m_CurrentGestureID == ID_EMOTE_RPS_R || m_CurrentGestureID == ID_EMOTE_RPS_P || m_CurrentGestureID == ID_EMOTE_RPS_S )
				{
					if ( m_RPSOutcome != -1 )
					{
						if (m_RPSOutcome == 0) 			m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_RPS_ROCK);
						else if (m_RPSOutcome == 1) 	m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_RPS_PAPER);
						else if (m_RPSOutcome == 2) 	m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_RPS_SCISSORS);
						m_RPSOutcome = -1;
					}
					else
					{
						m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
					}
				}
				else if (m_CurrentGestureID != ID_EMOTE_SUICIDE || (m_CurrentGestureID == ID_EMOTE_SUICIDE && m_Callback.GetState() < 3))
				{
					SendEmoteRequestSync(CALLBACK_CMD_END);
				}
				else if (m_CurrentGestureID == ID_EMOTE_SUICIDE)
				{
					SendEmoteRequestSync(CALLBACK_CMD_END);
				}
			}
			
			//HOTFIX for stance changing in additive emotes
			if ( m_LastMask != -1 && m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE) )
			{
				m_Callback.Cancel();
			}
			
			if ( m_MenuEmote && m_bEmoteIsPlaying )
			{
				SendEmoteRequestSync(CALLBACK_CMD_END);
			}
			
			if ( m_DeferredEmoteExecution == CALLBACK_CMD_END )
			{
				EndCallbackCommand();
			}
			
			if ( m_DeferredEmoteExecution == CALLBACK_CMD_GESTURE_INTERRUPT )
			{
				InterruptCallbackCommand();
			}
		}
		//no m_Callback exists //TODO please future me, refactor into some sort of switch
		else
		{
			if (m_bEmoteIsPlaying)
			{
				m_bEmoteIsPlaying = false;
				OnEmoteEnd();
			}
			else if (!m_Player.GetItemInHands() && m_IsSurrendered && !m_ItemToBeCreated)
			{
				PlaySurrenderInOut(false);
				return;
			}
			// getting out of surrender state - hard cancel (TODO: refactor)
			else if (m_IsSurrendered && (m_HIC.IsSingleUse() || m_HIC.IsContinuousUseStart() || m_HIC.IsWeaponRaised()))
			{
				if ( m_Player.GetItemInHands() )
					m_Player.GetItemInHands().Delete();
				return;
			}
			
			// fallback in case lock does not end properly
			else if (m_IsSurrendered && !m_Player.GetItemInHands() || (m_Player.GetItemInHands() && m_Player.GetItemInHands().GetType() != "SurrenderDummyItem" && m_EmoteLockState))
			{
				m_IsSurrendered = false;
				SetEmoteLockState(false);
				return;
			}
			//actual emote launch
			else if (m_DeferredEmoteExecution > CALLBACK_CMD_INVALID)
			{
				PlayEmote(m_DeferredEmoteExecution);
				m_DeferredEmoteExecution = CALLBACK_CMD_INVALID;
			}
			//client-side emote launcher
			else if (!m_bEmoteIsPlaying && m_MenuEmote && (GetGame().IsClient() || !GetGame().IsMultiplayer()))
			{
				SendEmoteRequestSync(m_MenuEmote.m_ID);
			}
			else if (!m_MenuEmote && gestureSlot > 0)
			{
				PickEmote(gestureSlot);
			}
		}
	}
	
	void OnEmoteEnd()
	{
		if ( m_ItemToHands )
		{
			ShowItemInHands();
		}
		
		if ( m_PlayerDies )
		{
			m_Player.SetHealth(0.0);
			return;
		}
		
		//surrender "state" switch
		if ( m_CurrentGestureID == ID_EMOTE_SURRENDER )
		{
			m_IsSurrendered = !m_IsSurrendered;
			SetEmoteLockState(m_IsSurrendered);
		}
		
		m_CurrentGestureID = 0;
		
		if ( m_IsSurrendered )
		{
			return;
		}
		m_GestureInterruptInput = false;
		SetEmoteLockState(false);

		//! back to the default - shoot from camera - if not set already
		if (!m_Player.IsShootingFromCamera()) m_Player.OverrideShootFromCamera(true);
	}
	
	//server-side
	bool OnInputUserDataProcess(int userDataType, ParamsReadContext ctx)
	{
		if ( userDataType == INPUT_UDT_GESTURE)
		{
			int gestureID = -1;
			int random = -1;

			if (ctx.Read(gestureID))
			{
				if (ctx.Read(random))
				{
					m_RPSOutcome = random;
				}
				
				//server-side check
				if (CanPlayEmote(gestureID))
				{
					ScriptJunctureData pCtx = new ScriptJunctureData;
					pCtx.Write(gestureID);
					
					m_Player.SendSyncJuncture(DayZPlayerSyncJunctures.SJ_GESTURE_REQUEST, pCtx);
				}
			}
			return true;
		}
		return false;
	}
	
	//server and client
	void OnSyncJuncture(int pJunctureID, ParamsReadContext pCtx)
	{
		int gesture_id;
		int juncture_type = -1;
		if (!m_CancelEmote)
		{
			pCtx.Read(gesture_id);
			
			/*if (!pCtx.Read(juncture_type))
			{
				m_DeferredEmoteExecution = gesture_id;
			}
			else if (juncture_type == CALLBACK_CMD_SERVER)
			{
				ScriptJunctureData pCtx2 = new ScriptJunctureData;
				pCtx2.Write(gesture_id);
				
				m_Player.SendSyncJuncture(DayZPlayerSyncJunctures.SJ_GESTURE_REQUEST, pCtx2);
			}*/
			m_DeferredEmoteExecution = gesture_id;
		}
		else
			m_CancelEmote = false;
		//Print(m_DeferredEmoteExecution);
	}
	
	void AfterStoreLoad()
	{
		//failsafe, deletes helper item after fully loading character
		if ( m_Player.GetItemInHands() && SurrenderDummyItem.Cast(m_Player.GetItemInHands()) )
			m_Player.GetItemInHands().Delete();
	}
	
	//Configure Emote parameters for callback here
	bool PlayEmote( int id )
	{
		if (!CanPlayEmote(id))
		{
			m_Player.SetInventorySoftLock(false);
			return false;
		}
		
		actionDebugPrint("[emote] " + Object.GetDebugName(m_Player) + " play emote id=" + id + " IH=" + Object.GetDebugName(m_Player.GetItemInHands()));
		
		m_PreviousGestureID = m_CurrentGestureID;
		m_CurrentGestureID = id;
		if( id > 0)
		{
			switch ( id )
			{
				case ID_EMOTE_GREETING :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_GREETING,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_GREETING,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
			
				case ID_EMOTE_SOS :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE)) 	CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SOS,DayZPlayerConstants.STANCEMASK_ERECT,true);
					HideItemInHands();
				break;
			
				case ID_EMOTE_HEART :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_HEART,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_HEART,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
					HideItemInHands();
				break;
			
				case ID_EMOTE_TAUNT :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_TAUNT,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_TAUNT,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
			
				case ID_EMOTE_LYINGDOWN :
					vector water_info = HumanCommandSwim.WaterLevelCheck( m_Player, m_Player.GetPosition() - (m_Player.GetDirection() * 0.9) );
					if ( water_info[0] < WATER_DEPTH ) //is player able to lay down without "drowning"?
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_LYINGDOWN,DayZPlayerConstants.STANCEMASK_CROUCH,true);
						HideItemInHands();
					}
				break;
			
				case ID_EMOTE_TAUNTKISS :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_TAUNTKISS,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_TAUNTKISS,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
			
				case ID_EMOTE_POINT :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_POINT,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_POINT,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_TAUNTELBOW :
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_TAUNTELBOW,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					HideItemInHands();
				break;
				
				case ID_EMOTE_THUMB :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_THUMB,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_THUMB,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_THUMBDOWN :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_THUMBDOWN,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_THUMBDOWN,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_THROAT :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_THROAT,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_THROAT,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
			
				case ID_EMOTE_SUICIDE :
					int suicideID = DayZPlayerConstants.CMD_SUICIDEFB_UNARMED;
					int m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
					string suicideStr;
					ItemBase weapon;
					weapon = m_Player.GetItemInHands();
					//suicideID = DayZPlayerConstants.CMD_SUICIDEFB_UNARMED; //unarmed suicide...optional?
					if (weapon)
					{
						if (weapon.ConfigIsExisting("suicideAnim"))
						{
							suicideStr = weapon.ConfigGetString("suicideAnim");
						}
						
						if (weapon.IsKindOf("Pistol_Base"))
						{
							suicideID = DayZPlayerConstants.CMD_SUICIDEFB_PISTOL;
							m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
							m_Player.OverrideShootFromCamera(false);
						}

						else if (weapon.IsKindOf("Rifle_Base"))
						{
							suicideID = DayZPlayerConstants.CMD_SUICIDEFB_RIFLE;
							m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
							m_Player.OverrideShootFromCamera(false);
						}
						
						else if (suicideStr == "onehanded"){
							suicideID = DayZPlayerConstants.CMD_SUICIDEFB_1HD;
							m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
						}
						
						else if (suicideStr == "fireaxe"){
							suicideID = DayZPlayerConstants.CMD_SUICIDEFB_FIREAXE;
							m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
						}
						
						else if (suicideStr == "pitchfork"){
							suicideID = DayZPlayerConstants.CMD_SUICIDEFB_PITCHFORK;
							m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
						}
						
						else if (suicideStr == "sword"){
							suicideID = DayZPlayerConstants.CMD_SUICIDEFB_SWORD;
							m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
						}
						
						else if (suicideStr == "spear"){
							suicideID = DayZPlayerConstants.CMD_SUICIDEFB_SPEAR;
							m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
						}
						
						else if (suicideStr == "woodaxe"){
							suicideID = DayZPlayerConstants.CMD_SUICIDEFB_WOODAXE;
							m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
						}
					
						else
							suicideID = -1;
					}
			
					if (suicideID > -1)
					{
						CreateEmoteCallback(EmoteCB, suicideID, m_StanceMask, true);
					}
					else
						m_Player.SetInventorySoftLock(false);
				break;
			
				case ID_EMOTE_DANCE:
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE)) 	CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_DANCE,DayZPlayerConstants.STANCEMASK_ERECT,true);
					HideItemInHands();
				break;
				
				case ID_EMOTE_SALUTE:
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE)) 	CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SALUTE,DayZPlayerConstants.STANCEMASK_ERECT,true);
					HideItemInHands();
				break;
				
				case ID_EMOTE_TIMEOUT:
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_TIMEOUT,DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH,false);
						HideItemInHands();
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_TIMEOUT,DayZPlayerConstants.STANCEMASK_PRONE,true);
						HideItemInHands();
					}
					
				break;
				
				case ID_EMOTE_DABBING:
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_DABBING,DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH,false);
					HideItemInHands();
				break;
				
				case ID_EMOTE_FACEPALM:
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_FACEPALM,DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH,false);
					//HideItemInHands();
				break;
				
				case ID_EMOTE_CLAP:
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_CLAP,DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH,false);
					HideItemInHands();
				break;
				
				case ID_EMOTE_SILENT:
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_SILENCE,DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH,false);
						//HideItemInHands();
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SILENCE,DayZPlayerConstants.STANCEMASK_PRONE,true);
						//HideItemInHands();
					}
				break;
				
				case ID_EMOTE_WATCHING:
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_WATCHING,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_WATCHING,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_HOLD:
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_HOLD,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_HOLD,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_LISTENING:
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_LISTENING,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_LISTENING,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_POINTSELF:
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_POINTSELF,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_POINTSELF,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_LOOKATME:
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_LOOKATME,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_LOOKATME,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_TAUNTTHINK :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_TAUNTTHINK,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_TAUNTTHINK,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_MOVE :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_MOVE,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_MOVE,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_DOWN :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_DOWN,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_DOWN,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_COME :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_COME,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_COME,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_SURRENDER :
					if ( !m_IsSurrendered )
					{
						PlaySurrenderInOut(true);
					}
					else if ( m_IsSurrendered )
					{
						if ( m_Player.GetItemInHands() )
							m_Player.GetItemInHands().Delete();
					}
				break;
				
				case ID_EMOTE_CAMPFIRE :
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_CAMPFIRE,DayZPlayerConstants.STANCEMASK_CROUCH,true);
					HideItemInHands();
				break;
				
				case ID_EMOTE_SITA :
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SITA,DayZPlayerConstants.STANCEMASK_CROUCH,true);
				break;
				
				case ID_EMOTE_SITB :
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SITB,DayZPlayerConstants.STANCEMASK_CROUCH,true);
				break;
				
				case ID_EMOTE_RPS :
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_RPS,DayZPlayerConstants.STANCEMASK_ERECT,false);
				break;
				
				case ID_EMOTE_RPS_R :
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_RPS,DayZPlayerConstants.STANCEMASK_ERECT,false);
				break;
				
				case ID_EMOTE_RPS_P :
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_RPS,DayZPlayerConstants.STANCEMASK_ERECT,false);
				break;
				
				case ID_EMOTE_RPS_S :
					CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_RPS,DayZPlayerConstants.STANCEMASK_ERECT,false);
				break;
				
				case ID_EMOTE_NOD :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_NODHEAD,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_NODHEAD,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_SHAKE :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_SHAKEHEAD,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SHAKEHEAD,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_SHRUG :
					if (!m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE))
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREMOD_SHRUG,DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT,false);
					}
					else
					{
						CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SHRUG,DayZPlayerConstants.STANCEMASK_PRONE,true);
					}
				break;
				
				case ID_EMOTE_VOMIT :
					if ( m_Player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer() )
					{
						ref SymptomBase symptom = m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
	        			
			            if ( symptom )
			            { 
			                symptom.SetDuration(Math.RandomIntInclusive(4,8));
			            }
					}
				break;
				
				/*case ID_EMOTE_DEBUG :
				break;*/
				
				default :
					Print("EmoteManager.c | PlayEmote | WRONG ID");
					m_bEmoteIsPlaying = false;
					return false;
				break;
			}
		}
		if ( m_bEmoteIsPlaying )
		{
			m_Player.SetInventorySoftLock(true);
			if(m_Callback.m_IsFullbody)
			{
				SetEmoteLockState(true);
			}
		}
		
		return true;
	}
	
	protected void PickEmote(int gestureslot)
	{
		if ( m_Player && (GetGame().IsClient() || !GetGame().IsMultiplayer()))
		{
			m_PreviousGestureID = gestureslot;
			//HACK - to be removed with new input controller
			if ( gestureslot == 12)
			{
				return;
			}
			
			int emote_id_from_slot = m_Player.m_ConfigEmotesProfile.GetEmoteFromSlot(gestureslot.ToString());
			CreateEmoteCBFromMenu(emote_id_from_slot,true);
		}
	}
	
	//creates Emote callback
	protected void CreateEmoteCallback(typename callbacktype, int id, int mask, bool fullbody )
	{
		if ( m_Player )
		{
			m_LastMask = -1;
			if ( fullbody )
			{
				Class.CastTo(m_Callback, m_Player.StartCommand_Action(id,callbacktype,mask));
				m_Callback.m_IsFullbody = true;
				m_Callback.EnableCancelCondition(true);
			}
			else if (m_Player.IsPlayerInStance(mask))
			{
				m_LastMask = mask;  //character is probably not prone now
				Class.CastTo(m_Callback, m_Player.AddCommandModifier_Action(id,callbacktype));
			}
			
			if (m_Callback)
			{
				m_bEmoteIsPlaying = true;
				m_Callback.m_callbackID = id;
				m_Callback.m_player = m_Player;
				m_Callback.m_Manager = this;
			}
		}
	}
	
	protected void HideItemInHands()
	{
		m_item = m_Player.GetItemInHands();
		if(m_Callback && m_item)
		{
			m_Player.GetItemAccessor().HideItemInHands(true);
			m_ItemToHands = true;
		}
	}
	
	protected void ShowItemInHands()
	{
		if (m_item)
		{
			m_Player.GetItemAccessor().HideItemInHands(false);
		}
		m_ItemToHands = false;
	}
	
	protected void CommitSuicide()
	{
		Weapon_Base weapon;
		WeaponEventBase weapon_event = new WeaponEventTrigger;
		
		if ( Weapon_Base.CastTo(weapon,m_Player.GetItemInHands()) )
		{
			//TODO : check multiple muzzles for shotguns, eventually
			if (weapon.CanFire())
			{
				m_Callback.RegisterAnimationEvent("Simulation_End",EMOTE_SUICIDE_SIMULATION_END);
				m_Player.SetSuicide(true);
				weapon.ProcessWeaponEvent(weapon_event);
				m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_FINISH);
				if (m_Player.IsAlive()) 
				{
					EntityAI helm = m_Player.FindAttachmentBySlotName("Headgear");
					if (helm && GetGame().IsServer())
					{
						float damage = helm.GetMaxHealth("","");
						helm.AddHealth( "","", -damage/2); //TODO damages by 50% now. Use some proper, projectile-related value here
					}
					GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(this.KillPlayer);
					//LogSuicide(); 	// older logging
					if ( m_AdminLog )
					{
						m_AdminLog.Suicide( m_Player );
					}
				}
			}
			else
			{
				weapon.ProcessWeaponEvent(weapon_event);
				m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
			}
		}
		else if ( m_Player.GetItemInHands() && m_Player.GetItemInHands().ConfigIsExisting("suicideAnim") )
		{
			m_Callback.RegisterAnimationEvent("Death",EMOTE_SUICIDE_DEATH);
			m_Callback.RegisterAnimationEvent("Bleed",EMOTE_SUICIDE_BLEED);
			m_Callback.RegisterAnimationEvent("Simulation_End",EMOTE_SUICIDE_SIMULATION_END);
			m_Player.SetSuicide(true);
			m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_FINISH);
			
			LogSuicide();
		}
		else
		{
			m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_FINISH);
		}
	}

	void KillPlayer()
	{
		if (GetGame().IsServer())
		{		
			m_Player.SetHealth(0);
			
			/*EntityAI itemInHands = m_Player.GetHumanInventory().GetEntityInHands();
			bool can_drop = itemInHands && m_Player.CanDropEntity(itemInHands);
			if (!m_Player.IsAlive() && can_drop)
			{
				syncDebugPrint("EmoteManager::KillPlayer - char already dead, using alternative drop method");
				string item_name = itemInHands.GetType();
				
				m_Player.ServerReplaceItemInHandsWithNewElsewhere(new DestroyItemInCorpsesHandsAndCreateNewOnGndLambda(itemInHands, item_name, m_Player, false));
			}
			else
			{
				if( can_drop )
				{
					syncDebugPrint("EmoteManager::KillPlayer - trying to drop item");
					ChainedDropAndKillPlayerLambda lambda = new ChainedDropAndKillPlayerLambda(itemInHands, "", m_Player);
					m_Player.GetDayZPlayerInventory().ReplaceItemInHandsWithNew(InventoryMode.SERVER, lambda);
				}
				else
				{
					m_Player.SetHealth(0);
				}
			}*/
		}
	}
	
	void LogSuicide()
	{
		if (GetGame().IsServer())
		{
			PlayerIdentity identity = m_Player.GetIdentity();
			if (identity)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(GetGame().AdminLog, "Player '" + identity.GetName() + "' (id=" + identity.GetId() + ") committed suicide.");
			}
		}
	}
	
	void CreateEmoteCBFromMenu(int id, bool interrupts_same = false)
	{
		//if (CanPlayEmote(id))
			m_MenuEmote = new EmoteLauncher(id,interrupts_same);
	}
	
	void InterruptCallbackCommand()
	{
		//Print("ending ECB - interrupt");
		m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_INTERRUPT);
		
		if (m_MenuEmote)
			m_MenuEmote = null;
		m_DeferredEmoteExecution = CALLBACK_CMD_INVALID;
	}
	
	void EndCallbackCommand()
	{
		//Print("ending ECB - proper");
		if (m_CurrentGestureID == ID_EMOTE_DANCE)
		{
			m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_INTERRUPT);
		}
		else
		{
			m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
		}
		
		if (m_MenuEmote)
			m_MenuEmote = null;
		m_DeferredEmoteExecution = CALLBACK_CMD_INVALID;
	}
	
	//sends request
	void SendEmoteRequestSync(int id)
	{
		ScriptInputUserData ctx = new ScriptInputUserData;
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() )
		{
			if ( ctx.CanStoreInputUserData() && CanPlayEmote(id) )
			{
				ctx.Write(INPUT_UDT_GESTURE);
				ctx.Write(id);
				m_RPSOutcome = -1;
				switch (id)
				{
					case ID_EMOTE_RPS :
						m_RPSOutcome = Math.RandomInt(0,3);
					break;
					
					case ID_EMOTE_RPS_R :
						m_RPSOutcome = 0;
					break;
					
					case ID_EMOTE_RPS_P :
						m_RPSOutcome = 1;
					break;
					
					case ID_EMOTE_RPS_S :
						m_RPSOutcome = 2;
					break;
				}
				if (m_RPSOutcome != -1) 	ctx.Write(m_RPSOutcome);
				ctx.Send();
				m_Player.SetInventorySoftLock(true);
				//m_DeferredEmoteExecution = m_MenuEmote.m_ID;
				//PlayEmote(m_MenuEmote.m_ID);
			}
			m_MenuEmote = NULL;
		}
		else if (!GetGame().IsMultiplayer())
		{
			if (id == CALLBACK_CMD_END )
			{
				EndCallbackCommand();
			}
			else if (id == CALLBACK_CMD_GESTURE_INTERRUPT)
			{
				m_DeferredEmoteExecution = CALLBACK_CMD_GESTURE_INTERRUPT;
			}
			else
			{
				PlayEmote(id);
			}
			m_MenuEmote = NULL;
		}
		/*else
		{
			EndCallbackCommand();
			m_MenuEmote = NULL;
		}*/
	}
	
	bool IsControllsLocked()
	{
		return m_controllsLocked;
	}
	
	bool CanPlayEmote(int id)
	{
		//special cases
		if ( id == CALLBACK_CMD_END || id == CALLBACK_CMD_GESTURE_INTERRUPT)
		{
			return true;
		}
		
		if ( !m_Player || (!IsEmotePlaying() && m_Player.GetCommand_Action() || m_Player.GetCommandModifier_Action()) || m_Player.GetThrowing().IsThrowingModeEnabled() || m_Player.IsItemsToDelete())
		{	
			return false;
		}
		
		ItemBase item = m_Player.GetItemInHands();
		if ( item && item.IsHeavyBehaviour() &&  (id != ID_EMOTE_SURRENDER) )
		{
			return false;
		}
		
		if ( (m_Player.GetWeaponManager() && m_Player.GetWeaponManager().IsRunning()) || (m_Player.GetActionManager() && m_Player.GetActionManager().GetRunningAction()) )
		{
			return false;
		}
		
		if ( m_HIC.IsWeaponRaised() || m_Player.IsClimbing() || m_Player.IsRestrainStarted() || m_Player.IsFighting() || m_Player.IsSwimming() || m_Player.IsClimbingLadder() || m_Player.IsFalling() || m_Player.IsUnconscious() || m_Player.IsJumpInProgress() ) 	// rework conditions into something better?
		{
			return false;
		}
		if ( m_Player.GetCommand_Vehicle() )
		{
			if ( m_Player.GetCommand_Vehicle().GetTransport() )
			{
				return false;
			}
		}
		
		if ( m_Player.GetCommand_Move() && m_Player.GetCommand_Move().IsOnBack() && id != ID_EMOTE_SURRENDER)
		{
			return false;
		}
		
		//"locks" player in surrender state
		if ( m_IsSurrendered && (id != ID_EMOTE_SURRENDER) )
		{
			return false;
		}
		
		if ( m_Player.GetDayZPlayerInventory().IsProcessing() )
		{
			return false;
		}
		return true;
	}
	
	void PlaySurrenderInOut(bool state)
	{
		m_PreviousGestureID = m_CurrentGestureID;
		m_CurrentGestureID = ID_EMOTE_SURRENDER;
		if (state)
		{
			if (m_Player.GetItemInHands() && !m_Player.CanDropEntity(m_Player.GetItemInHands()))
				return;
			if (m_Player.GetItemInHands() && GetGame().IsClient())
			{
				m_Player.PhysicalPredictiveDropItem(m_Player.GetItemInHands());
			}
			CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SURRENDERIN,DayZPlayerConstants.STANCEMASK_ALL,true);
			if (m_Callback)
				m_Callback.RegisterAnimationEvent("ActionExec", UA_ANIM_EVENT);
		}
		else
		{
			CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SURRENDEROUT,DayZPlayerConstants.STANCEMASK_ALL,true);
		}
	}
	
	//!
	void SetEmoteLockState(bool state)
	{
		DayZPlayerCameraBase camera = DayZPlayerCameraBase.Cast(m_Player.GetCurrentCamera());
		if (!m_HandInventoryLocation)
		{
			m_HandInventoryLocation = new InventoryLocation;
			m_HandInventoryLocation.SetHands(m_Player,null);
		}
		
		if (!state)
		{
			if (m_Player.GetInventory().HasInventoryReservation(null, m_HandInventoryLocation))
			{
				m_Player.GetInventory().ClearInventoryReservation( null, m_HandInventoryLocation);
			}
			
			if ( m_Player.GetActionManager() )
				m_Player.GetActionManager().EnableActions(true);
			
			m_Player.SetInventorySoftLock(false);
						
			if ( m_controllsLocked )
			{
				m_controllsLocked = false;
				//camera.ForceFreelook(false);
				//m_Player.GetInputController().OverrideAimChangeX(false,0);
				//m_Player.GetInputController().OverrideMovementSpeed(false,0);
			}
		}
		else
		{
			//m_HandInventoryLocation.SetHands(m_Player,m_Player.GetItemInHands());
			if (!m_Player.GetInventory().HasInventoryReservation(null, m_HandInventoryLocation))
			{
				m_Player.GetInventory().AddInventoryReservation( null, m_HandInventoryLocation, GameInventory.c_InventoryReservationTimeoutMS);
			}
				
			if ( m_Player.GetActionManager() )
				m_Player.GetActionManager().EnableActions(false);
			
			//Movement lock in fullbody anims
			if (m_Callback && m_Callback.m_IsFullbody && !m_controllsLocked )
			{
				m_controllsLocked = true;
				//m_Player.GetInputController().OverrideAimChangeX(true,0);
				//m_Player.GetInputController().OverrideMovementSpeed(true,0);
				
				//camera.ForceFreelook(true);
			}
		}
		m_EmoteLockState = state;
	}
	
	void CheckEmoteLockedState()
	{
		if ( !m_Player.GetItemInHands() || (m_Player.GetItemInHands() && !SurrenderDummyItem.Cast(m_Player.GetItemInHands())) )
			return;
		
		//refreshes reservation in case of unwanted timeout
		if ( m_EmoteLockState && m_HandInventoryLocation )
		{
			m_Player.GetInventory().ExtendInventoryReservation( null, m_HandInventoryLocation, 10000);
		}
	}
	
	//! force-ends surrender state from outside of normal flow
	void EndSurrenderRequest(SurrenderData data = null)
	{
		if (m_IsSurrendered && data)
		{
			SetEmoteLockState(false);
			if (m_Player.GetItemInHands())
				m_Player.GetItemInHands().Delete();
			
			m_IsSurrendered = false;
			
			data.End();
		}
	}
	
	//sent from server to cancel general emote callback
	void ServerRequestEmoteCancel()
	{
		ScriptJunctureData pCtx = new ScriptJunctureData;
		pCtx.Write(CALLBACK_CMD_GESTURE_INTERRUPT);
		//pCtx.Write(CALLBACK_CMD_SERVER);
		
		m_Player.SendSyncJuncture(DayZPlayerSyncJunctures.SJ_GESTURE_REQUEST, pCtx);
	}
	
	bool InterruptGestureCheck()
	{
		//interrupts any callback if restrain action is in progress, takes priority
		/*if (m_Player.IsRestrainStarted())
			return true;*/
		
		if (!m_Callback.m_IsFullbody)
			return false;
		
		if ( GetUApi() )
		{
			for( int idx = 0; idx < m_InterruptInputs.Count(); idx++ )
			{
				string inputName = m_InterruptInputs[idx];
				
					UAInput inp = GetUApi().GetInputByName(inputName);
					
					if( inp && inp.LocalPress() )
					{
						return true; //TODO
					}
			}
		}
		/*UAInterface input_interface = m_Player.GetInputInterface();
		if ( input_interface )
		{
			for( int idx = 0; idx < m_InterruptInputs.Count(); idx++ )
			{
				string inputName = m_InterruptInputs[idx];
				
				if( input_interface.SyncedPress(inputName) )
				{
					return true;
				}
			}
		}*/
		return false;
	}
	
	bool IsEmotePlaying()
	{
		return m_bEmoteIsPlaying || m_IsSurrendered;
	}
	
	void CreateBleedingEffect(int Callback_ID)
	{
		if (GetGame().IsServer() && m_Player.IsAlive())
		{
			switch (Callback_ID)
			{
				case DayZPlayerConstants.CMD_SUICIDEFB_1HD :
					m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Neck");
				break;
				
				case DayZPlayerConstants.CMD_SUICIDEFB_FIREAXE :
					m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftForeArmRoll");
				break;
				
				case DayZPlayerConstants.CMD_SUICIDEFB_PITCHFORK :
					m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine2");
				break;
				
				case DayZPlayerConstants.CMD_SUICIDEFB_SWORD :
					m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine2");
				break;
				
				case DayZPlayerConstants.CMD_SUICIDEFB_SPEAR :
					m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Head");
				break;
				
				case DayZPlayerConstants.CMD_SUICIDEFB_WOODAXE :
					m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftForeArmRoll");
				break;
				
				default :
					Print("EmoteManager.c | CreateBleedingEffect | WRONG ID");
				break;
			}
		}
	}
	
	void CancelEmote()
	{
		if (m_Callback || m_MenuEmote || m_DeferredEmoteExecution != CALLBACK_CMD_INVALID)
			m_CancelEmote = true;
		if (m_Callback)
			m_Callback.Cancel();
		if (m_MenuEmote)
			m_MenuEmote = null;
		m_DeferredEmoteExecution = CALLBACK_CMD_END;
	}
	
	void OnJumpStart()
	{
		//CancelEmote();
	}
	
	void OnCommandClimbStart()
	{
		//CancelEmote();
	}
};

class SurrenderData
{
	//!called on surrender end request end
	void End();
}

/**@class		ChainedDropAndKillPlayerLambda
 * @brief		drops weapon in hands to ground and then calls kill
 **/
class ChainedDropAndKillPlayerLambda : ReplaceItemWithNewLambdaBase
{
	PlayerBase m_Player;

	void ChainedDropAndKillPlayerLambda (EntityAI old_item, string new_item_type, PlayerBase player)
	{
		m_Player = player;
		InventoryLocation gnd = new InventoryLocation;
		vector mtx[4];
		old_item.GetTransform(mtx);
		gnd.SetGround( old_item, mtx );
		
		OverrideNewLocation( gnd );
	}
		
	override void Execute (HumanInventoryWithFSM fsm_to_notify = null)
	{
		if (PrepareLocations())
		{
			vector transform[4];
		
			m_Player.GetInventory().TakeToDst(InventoryMode.SERVER, m_OldLocation, m_NewLocation);
			m_Player.OnItemInHandsChanged();			
		}
		
		m_Player.SetHealth(0);
		
		hndDebugPrint("[syncinv] player=" + Object.GetDebugName(m_Player) + " STS=" + m_Player.GetSimulationTimeStamp() + " ChainedDropAndKillPlayerLambda");
	}
}