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
			case EmoteConstants.EMOTE_SUICIDE_DEATH :
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
			
			case EmoteConstants.EMOTE_SUICIDE_BLEED :
				if (GetGame().IsServer())
					m_Manager.CreateBleedingEffect(m_callbackID);
			break;
			
			case EmoteConstants.EMOTE_SUICIDE_SIMULATION_END :
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
	PluginAdminLog 			m_AdminLog;
	ref Timer 				m_ReservationTimer;
	ref map<int, ref EmoteBase>		m_NameEmoteMap;
	
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
		
		EmoteConstructor ec = new EmoteConstructor;
		if ( !m_NameEmoteMap )
		{
			if ( !ec.ConstructEmotes(m_Player,m_NameEmoteMap) )
			{
				Error("EmoteManager | EmoteConstructor initialization failed!");
			}
		}
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
	
	//! Also includes a stance check for FB callbacks
	bool DetermineEmoteData(EmoteBase emote, out int callback_ID, out int stancemask, out bool is_fullbody)
	{
		if ( emote.DetermineOverride(callback_ID, stancemask, is_fullbody) && emote.EmoteFBStanceCheck(stancemask) )
		{
			return true;
		}
		else if ( emote.m_AdditiveCallbackUID != 0 && m_Player.IsPlayerInStance(emote.m_StanceMaskAdditive) )
		{
			callback_ID = emote.m_AdditiveCallbackUID;
			stancemask = emote.m_StanceMaskAdditive;
			is_fullbody = false;
			return true;
		}
		else if ( emote.m_FullbodyCallbackUID != 0 && emote.EmoteFBStanceCheck(emote.m_StanceMaskFullbody) )
		{
			callback_ID = emote.m_FullbodyCallbackUID;
			stancemask = emote.m_StanceMaskFullbody;
			is_fullbody = true;
			return true;
		}
		
		return false;
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
					SendEmoteRequestSync(CALLBACK_CMD_END);
				}
			}
			
			if( (gestureSlot > 0 && gestureSlot != 12 ) || m_GestureInterruptInput || (m_HIC.IsSingleUse() && !uiGesture) || (m_HIC.IsContinuousUseStart() && !uiGesture) || (m_Callback.m_IsFullbody && !uiGesture && m_HIC.IsWeaponRaised()) ) 
			{
				if (m_CurrentGestureID == EmoteConstants.ID_EMOTE_SUICIDE  && m_HIC.IsSingleUse())
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
				else if ( (m_CurrentGestureID == EmoteConstants.ID_EMOTE_THUMB || m_CurrentGestureID == EmoteConstants.ID_EMOTE_THUMBDOWN) && m_HIC.IsSingleUse() )
				{
					m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_ACTION);
				}
				else if ( m_CurrentGestureID == EmoteConstants.ID_EMOTE_RPS || m_CurrentGestureID == EmoteConstants.ID_EMOTE_RPS_R || m_CurrentGestureID == EmoteConstants.ID_EMOTE_RPS_P || m_CurrentGestureID == EmoteConstants.ID_EMOTE_RPS_S )
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
				else if (m_CurrentGestureID != EmoteConstants.ID_EMOTE_SUICIDE || (m_CurrentGestureID == EmoteConstants.ID_EMOTE_SUICIDE && m_Callback.GetState() < 3))
				{
					SendEmoteRequestSync(CALLBACK_CMD_END);
				}
				else if (m_CurrentGestureID == EmoteConstants.ID_EMOTE_SUICIDE)
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
			// getting out of surrender state - hard cancel
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
		if ( m_CurrentGestureID == EmoteConstants.ID_EMOTE_SURRENDER )
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
		if( id > 0 )
		{
			//-----------------------------------------------
			EmoteBase emote;// = new EmoteBase;
			if (m_NameEmoteMap.Find(id,emote))
			{
				int callback_ID;
				int stancemask;
				bool is_fullbody;
				if ( DetermineEmoteData(emote,callback_ID,stancemask,is_fullbody) )
				{
					emote.OnBeforeStandardCallbackCreated(callback_ID,stancemask,is_fullbody);
					CreateEmoteCallback(EmoteCB,callback_ID,stancemask,is_fullbody);
					
					if (emote.m_HideItemInHands)
					{
						HideItemInHands();
					}
				}
				else
				{
					Error("EmoteManager | DetermineEmoteData failed!");
				}
			}
			else //direcly handled exceptions
			{
				switch ( id )
				{
					case EmoteConstants.ID_EMOTE_SURRENDER :
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
					
					case EmoteConstants.ID_EMOTE_VOMIT :
						if ( m_Player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || !GetGame().IsMultiplayer() )
						{
							ref SymptomBase symptom = m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
		        			
				            if ( symptom )
				            { 
				                symptom.SetDuration(Math.RandomIntInclusive(4,8));
				            }
						}
						m_Player.SetInventorySoftLock(false);
						SetEmoteLockState(false);
					break;
					
					default :
						Print("EmoteManager.c | PlayEmote | WRONG ID");
						m_bEmoteIsPlaying = false;
						return false;
					break;
				}
			}
			//-----------------------------------------------
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
			m_Player.TryHideItemInHands(true);
			m_ItemToHands = true;
		}
	}
	
	protected void ShowItemInHands()
	{
		if (m_item)
		{
			m_Player.TryHideItemInHands(false);
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
				m_Callback.RegisterAnimationEvent("Simulation_End",EmoteConstants.EMOTE_SUICIDE_SIMULATION_END);
				m_Player.SetSuicide(true);
				weapon.ProcessWeaponEvent(weapon_event);
				m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_FINISH);
				if (m_Player.IsAlive()) 
				{
					EntityAI helm = m_Player.FindAttachmentBySlotName("Headgear");
					if (helm && GetGame().IsServer())
					{
						float damage = helm.GetMaxHealth("","");
						helm.AddHealth( "","", -damage/2);
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
			m_Callback.RegisterAnimationEvent("Death",EmoteConstants.EMOTE_SUICIDE_DEATH);
			m_Callback.RegisterAnimationEvent("Bleed",EmoteConstants.EMOTE_SUICIDE_BLEED);
			m_Callback.RegisterAnimationEvent("Simulation_End",EmoteConstants.EMOTE_SUICIDE_SIMULATION_END);
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
		m_MenuEmote = new EmoteLauncher(id,interrupts_same);
	}
	
	void InterruptCallbackCommand()
	{
		m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_INTERRUPT);
		
		if (m_MenuEmote)
			m_MenuEmote = null;
		m_DeferredEmoteExecution = CALLBACK_CMD_INVALID;
	}
	
	void EndCallbackCommand()
	{
		if (m_CurrentGestureID == EmoteConstants.ID_EMOTE_DANCE)
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
					case EmoteConstants.ID_EMOTE_RPS :
						m_RPSOutcome = Math.RandomInt(0,3);
					break;
					
					case EmoteConstants.ID_EMOTE_RPS_R :
						m_RPSOutcome = 0;
					break;
					
					case EmoteConstants.ID_EMOTE_RPS_P :
						m_RPSOutcome = 1;
					break;
					
					case EmoteConstants.ID_EMOTE_RPS_S :
						m_RPSOutcome = 2;
					break;
				}
				if (m_RPSOutcome != -1) 	ctx.Write(m_RPSOutcome);
				ctx.Send();
				m_Player.SetInventorySoftLock(true);
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
		if ( item && item.IsHeavyBehaviour() &&  (id != EmoteConstants.ID_EMOTE_SURRENDER) )
		{
			return false;
		}
		
		if ( (m_Player.GetWeaponManager() && m_Player.GetWeaponManager().IsRunning()) || (m_Player.GetActionManager() && m_Player.GetActionManager().GetRunningAction()) )
		{
			return false;
		}
		
		if ( m_HIC.IsWeaponRaised() || m_Player.IsRolling() || m_Player.IsClimbing() || m_Player.IsRestrainStarted() || m_Player.IsFighting() || m_Player.IsSwimming() || m_Player.IsClimbingLadder() || m_Player.IsFalling() || m_Player.IsUnconscious() || m_Player.IsJumpInProgress() ) 	// rework conditions into something better?
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
		
		if ( m_Player.GetCommand_Move() && m_Player.GetCommand_Move().IsOnBack() && id != EmoteConstants.ID_EMOTE_SURRENDER)
		{
			return false;
		}
		
		//"locks" player in surrender state
		if ( m_IsSurrendered && (id != EmoteConstants.ID_EMOTE_SURRENDER) )
		{
			return false;
		}
		
		if ( m_Player.GetDayZPlayerInventory().IsProcessing() )
		{
			return false;
		}
		
		EmoteBase emote;
		if (m_NameEmoteMap.Find(id,emote))
		{
			int callback_ID;
			int stancemask;
			bool is_fullbody;
			if ( DetermineEmoteData(emote,callback_ID,stancemask,is_fullbody) && emote.EmoteCondition(stancemask) )
			{
				return true;
			}
		}
		else if ( id == EmoteConstants.ID_EMOTE_SURRENDER )//direcly handled exceptions
		{
			return true;
		}
		else if (id == EmoteConstants.ID_EMOTE_VOMIT && DayZPlayerUtils.PlayerCanChangeStance(m_Player,DayZPlayerConstants.STANCEIDX_CROUCH) )//direcly handled exceptions
		{
			return true;
		}
		
		return false;
	}
	
	void PlaySurrenderInOut(bool state)
	{
		m_PreviousGestureID = m_CurrentGestureID;
		m_CurrentGestureID = EmoteConstants.ID_EMOTE_SURRENDER;
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
/*
	//! Locks inputs during emote request processing
	void SetInputsLocked(bool state)
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if (state)
				GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
			else
				GetGame().GetMission().PlayerControlEnable(true);
		}
	}
*/
	
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
						return true;
					}
			}
		}
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