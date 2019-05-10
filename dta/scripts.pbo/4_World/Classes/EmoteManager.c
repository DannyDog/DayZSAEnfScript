class EmoteCB : HumanCommandActionCallback
{
	//const int 		CB_SURRENDER_STATE = 100;
	bool 			m_IsFullbody;
	int 			m_callbackID;
	PlayerBase 		m_player;
	
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
		if (pEventID == 1)
		{
			m_player.GetEmoteManager().KillPlayer();
		}
		else if (GetGame().IsServer() && pEventID == UA_ANIM_EVENT)
		{
			if ( m_player.GetItemInHands() && SurrenderDummyItem.Cast(m_player.GetItemInHands()) )
				m_player.GetItemInHands().Delete();
			if ( m_player.GetItemInHands() )
				m_player.DropItem(m_player.GetItemInHands());
			else
				m_player.GetHumanInventory().CreateInHands("SurrenderDummyItem");
		}
	}
	
	override bool IsGestureCallback()
	{
		return true;
	}
};

/*
class EmoteSittingAndDoingSmthingCB : HumanCommandActionCallback //jtomasik - sem se daj asi dopsat nejaky dalsi callback extra burty pro sezeni se zbrani atp
{	
	bool IsEmoteCallback()
	{
		return true;
	}
};
*/

class EmoteFromMenu
{
	int m_ID;
	
	void EmoteFromMenu(int emoteID)
	{
		m_ID = emoteID;
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
	ref EmoteFromMenu 		m_MenuEmote;
	bool					m_bEmoteIsPlaying;
	bool 					m_IsSurrendered;
	protected bool 			m_ItemToBeCreated;
	protected bool			m_BelayedEmote;
	protected bool			m_ItemToHands;
	protected bool			m_ItemIsOn;
	protected bool			m_MouseButtonPressed;
	protected bool 			m_PlayerDies;
	protected bool 			m_controllsLocked;
	protected bool 			m_EmoteLockState;
	protected int 			m_DeferredMenuEmoteLaunch;
	protected int  			m_GestureID;
	protected int			m_BelayedEmoteSlot;
	protected int			m_PreviousGestureID;
	protected int			m_CurrentGestureID;
	protected int 			m_LastMask;
	protected int 			m_RPSOutcome;
	protected const float 	WATER_DEPTH = 0.15;
	PluginAdminLog 			m_AdminLog;
	ref Timer 				m_ReservationTimer;
	
	void EmoteManager( PlayerBase player ) 
	{
		m_Player = player;
		m_HIC = m_Player.GetInputController();
		m_ItemIsOn = false;
		m_RPSOutcome = -1;
		m_DeferredMenuEmoteLaunch = -1;
		
		// new input-based interrupt actions
		m_InterruptInputs = new array<string>;
		m_InterruptInputs.Insert("UAMoveForward");
		m_InterruptInputs.Insert("UAMoveBack");
		m_InterruptInputs.Insert("UATurnLeft");
		m_InterruptInputs.Insert("UATurnRight");
		m_InterruptInputs.Insert("UAMoveLeft");
		m_InterruptInputs.Insert("UAMoveRight");
		/*m_InterruptInputs.Insert("UAEvasiveForward");
		m_InterruptInputs.Insert("UAEvasiveLeft");
		m_InterruptInputs.Insert("UAEvasiveRight");
		m_InterruptInputs.Insert("UAEvasiveBack");*/
		m_InterruptInputs.Insert("UAStand");
		m_InterruptInputs.Insert("UACrouch");
		m_InterruptInputs.Insert("UAProne");
		/*m_InterruptInputs.Insert("UALeanLeft");
		m_InterruptInputs.Insert("UALeanRight");
		m_InterruptInputs.Insert("UALeanIronsightLeft");
		m_InterruptInputs.Insert("UALeanIronsightRight");
		m_InterruptInputs.Insert("UALeanLeftToggle");
		m_InterruptInputs.Insert("UALeanRightToggle");
		m_InterruptInputs.Insert("UAPersonCamSwitchSide");
		m_InterruptInputs.Insert("UAWalkRunToggle");
		m_InterruptInputs.Insert("UAWalkRunTemp");*/
		// end of new input-based interrupt actions
		
		//leave this here?
		m_HandInventoryLocation = new InventoryLocation;
		m_HandInventoryLocation.SetHands(m_Player,null);
		
		if( GetGame().IsServer() )
		{
			m_AdminLog = PluginAdminLog.Cast( GetPlugin(PluginAdminLog) );
		}
		
		m_ReservationTimer = new Timer();
		m_ReservationTimer.Run(8,this,"CheckEmoteLockedState",NULL,true);
		//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( CheckEmoteLockedState, 10000, true );
	}
	
	void ~EmoteManager() 
	{
		if (m_ReservationTimer && m_ReservationTimer.IsRunning())
			m_ReservationTimer.Stop();
		/*if (GetGame() && GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM )) //yes, we really need to ask for 'GetGame()' here, because of introscene character
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove( CheckEmoteLockedState );*/
		
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
		/*if (GetGame().GetInput())
		{
			//Print("---input is there --- ");
			//Print("---action count? ---" + GetGame().GetInput().GetActionsCount());
			
			GetActionsCount() -- was removed !!!
			
			for (int i = 1; i < 350; i++)
			{
				if (GetGame().GetInput().LocalPress(i, false))
					Print("---LocalPress--- " + i);
			}
		}*/
		// no updates on restrained characters
		if (m_Player.IsRestrained())
			return;
		
		//CheckEmoteLockedState();
		
		// dummy item has been created, cancels the "soft reservation" bool
		if (m_Player.GetItemInHands() && m_Player.GetItemInHands().GetType() == "SurrenderDummyItem" && m_ItemToBeCreated)
		{
			m_ItemToBeCreated = false;
		}
		
		int gestureSlot = DetermineGestureIndex();

		if ( m_Callback ) 
		{
			bool uiGesture = false;
			if( !GetGame().IsMultiplayer() || GetGame().IsClient() )
			{
				uiGesture = GetGame().GetUIManager().IsMenuOpen(MENU_GESTURES);
			}
			
			//jtomasik - asi bych nemel checkovat jestli hrac klika v menu nebo ve scene tady, ale mel by to vedet input manager?
			//HACK - handle differently with new input controller
			if( (gestureSlot > 0 && gestureSlot != 12 ) || (InterruptGesture() && m_Callback.m_IsFullbody) || (m_HIC.IsSingleUse() && !uiGesture) || (m_HIC.IsContinuousUseStart() && !uiGesture) || (m_Callback.m_IsFullbody && !uiGesture && m_HIC.IsWeaponRaised()) ) 
			{
				//Print("gestureslot pressed: " + gestureSlot);
				if (m_CurrentGestureID == ID_EMOTE_SUICIDE  && m_HIC.IsSingleUse() /*m_MouseButtonPressed*/)
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
				//HACK find a better solution
				else if (m_CurrentGestureID != ID_EMOTE_SUICIDE || (m_CurrentGestureID == ID_EMOTE_SUICIDE && m_Callback.GetState() < 3))
				{
					EndCallback();
				}

				if ( gestureSlot && m_PreviousGestureID != gestureSlot )
				{
					m_BelayedEmote = true;
					m_BelayedEmoteSlot = gestureSlot;
				}
			}
			
			//HOTFIX for stance changing in additive emotes
			if ( m_LastMask != -1 && m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_PRONE) )
			{
				m_Callback.Cancel();
			}
			
			if ( m_MenuEmote && m_bEmoteIsPlaying )
			{
				//PlayEmoteFromMenu();
				EndCallback();
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
				//PlaySurrenderInOut(false);
				if ( m_Player.GetItemInHands() )
					m_Player.GetItemInHands().Delete();
				return;
			}
			
			// fallback in case lock does not end properly
			else if (m_IsSurrendered && !m_Player.GetItemInHands() || (m_Player.GetItemInHands() && m_Player.GetItemInHands().GetType() != "SurrenderDummyItem" && m_EmoteLockState))
			{
				m_IsSurrendered = false;
				SetEmoteLockState(false);
				//m_Player.OnSurrenderEnd();
				return;
			}
			//server-side deferred launch
			else if (m_DeferredMenuEmoteLaunch != -1)
			{
				PlayEmote(m_DeferredMenuEmoteLaunch);
				m_MenuEmote = NULL;
				m_DeferredMenuEmoteLaunch = -1;
			}
			else if (!m_bEmoteIsPlaying && m_MenuEmote && (GetGame().IsClient() || !GetGame().IsMultiplayer()))
			{
				PlayEmoteFromMenu();
			}
			else if (gestureSlot > 0)
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
		
		//if suicide has been completed, kill player
		if ( m_PlayerDies )
		{
			m_Player.SetHealth(0.0);
			return;
		}
		
		//surrender "state" switch
		if ( m_CurrentGestureID == ID_EMOTE_SURRENDER )
		{
			m_IsSurrendered = !m_IsSurrendered;
			if ( !m_IsSurrendered )
			{
				SetEmoteLockState(false);
			}
			else
			{
				SetEmoteLockState(true);
				/*if ( m_Player.GetCommand_Move() && m_Player.GetCommand_Move().IsOnBack() )
				{
					m_IsSurrendered = !m_IsSurrendered; //invalid position, surrender state cannot proceed
				}*/
			}
		}
		
		if ( m_IsSurrendered )
		{
			if (m_BelayedEmote)
			{
				m_BelayedEmoteSlot = -1;
				m_BelayedEmote = false;
			}
			return;
		}
		
		SetEmoteLockState(false);
		
		if ( m_BelayedEmote )
		{
			if ( /*m_PreviousGestureID != m_BelayedEmoteSlot &&*/ !m_IsSurrendered)
			{
				PickEmote(m_BelayedEmoteSlot);
				//PlayEmote(m_BelayedEmoteSlot);
			}
			m_BelayedEmoteSlot = -1;
			m_BelayedEmote = false;
		}

		//! back to the default - shoot from camera - if not set already
		if (!m_Player.IsShootingFromCamera()) m_Player.OverrideShootFromCamera(true);
	}
	
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
				
				if ( gestureID >= 0 )
				{
					//PlayEmote(gestureID);
					m_DeferredMenuEmoteLaunch = gestureID;
					
				}
				else
				{
					EndCallback();
				}
			}
			return true;
		}
		return false;
	}
	
	//Configure Emote parameters for callback here
	bool PlayEmote( int id )
	{
		if (!CanPlayEmote(id))
		{
			return false;
		}
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
					vector water_info = HumanCommandSwim.WaterLevelCheck( m_Player, m_Player.GetPosition() - (m_Player.GetDirection() * 0.9) ); //checks behind player, where the head ends up being
					//Print("depth: " + water_info[0]);
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
					//m_bEmoteIsPlaying = false;
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
							//! switch to shoot from weapons instead of camera
							m_Player.OverrideShootFromCamera(false);
						}

						else if (weapon.IsKindOf("Rifle_Base"))
						{
							suicideID = DayZPlayerConstants.CMD_SUICIDEFB_RIFLE;
							m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
							//! switch to shoot from weapons instead of camera
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
					
						else //item in hands is not eligible for suicide
							suicideID = -1;
					}
			
					if (suicideID > -1)
					{
						CreateEmoteCallback(EmoteCB, suicideID, m_StanceMask, true);
						//m_Callback.RegisterAnimationEvent("Death",1);
					}
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
							//m_Player.GetHumanInventory().LocalDestroyEntity(m_Player.GetItemInHands());		
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
		if ( m_Player )
		{
			//m_PreviousGestureID = gestureslot;
			//HACK - to be removed with new input controller
			if ( gestureslot == 12)
			{
				return;
			}
			
			switch ( gestureslot )
			{
				case 1 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot1() );
				break;
				
				case 2 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot2() );
				break;
				
				case 3 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot3() );
				break;
				
				case 4 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot4() );
				break;
				
				case 5 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot5() );
				break;
				
				case 6 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot6() );
				break;
				
				case 7 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot7() );
				break;
				
				case 8 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot8() );
				break;
				
				case 9 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot9() );
				break;
				
				case 10 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot10() );
				break;
				
				case 11 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot11() );
				break;
				
				/*case 12 :
					PlayEmote( m_Player.m_ConfigEmotesProfile.GetEmoteSlot12() );
				break;*/
			}
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
			}
		}
	}
	
	protected void HideItemInHands()
	{
		/*if (GetGame().IsMultiplayer() && !GetGame().IsClient())
			return;*/
		m_item = m_Player.GetItemInHands();
		if(m_Callback && m_item)
		{
			m_Player.GetItemAccessor().HideItemInHands(true);
			m_ItemToHands = true;
		}
	}
	
	protected void ShowItemInHands()
	{
		/*if (GetGame().IsMultiplayer() && !GetGame().IsClient())
			return;*/
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
		
		//firearm suicide
		if ( Weapon_Base.CastTo(weapon,m_Player.GetItemInHands()) )
		{
			//TODO : check multiple muzzles for shotguns, eventually
			if (weapon.CanFire())
			{
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
		//melee weapon suicide
		else if ( m_Player.GetItemInHands() && m_Player.GetItemInHands().ConfigIsExisting("suicideAnim") )
		{
			m_Callback.RegisterAnimationEvent("Death",1);
			m_Player.SetSuicide(true);
			m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_FINISH);
			
			LogSuicide();
			//GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.KillPlayer, 4000, false);
		}
		//unarmed "suicide" :)
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
		
		EntityAI itemInHands = m_Player.GetHumanInventory().GetEntityInHands();
		if( itemInHands )
		{
			if( m_Player.CanDropEntity(itemInHands) )
			{
				vector transform[4];
				itemInHands.GetTransform(transform);
				m_Player.PredictiveDropEntity(itemInHands);
				itemInHands.SetTransform(transform);
			}
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
	
	void CreateEmoteCBFromMenu(int id)
	{
		m_MenuEmote = new EmoteFromMenu(id);
	}
	
	void EndCallback()
	{
		if (!m_Callback)
		{
			//Print("no callback!");
			return;
		}
		
		ScriptInputUserData ctx = new ScriptInputUserData;
		if (GetGame().IsMultiplayer() && GetGame().IsClient() && !ctx.CanStoreInputUserData())
		{
			//Print("ctx unavailable");
			return;
		}
		else if (GetGame().IsMultiplayer() && GetGame().IsClient() && ctx.CanStoreInputUserData())
		{
			//Print("sending ECB cancel request");
			ctx.Write(INPUT_UDT_GESTURE);
			ctx.Write(-1);
			ctx.Send();
		}
		
		//Print("ending ECB - proper");
		if (m_CurrentGestureID == ID_EMOTE_DANCE)
		{
			m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_INTERRUPT);
		}
		else
		{
			m_Callback.InternalCommand(DayZPlayerConstants.CMD_ACTIONINT_END);
		}
	}
	
	void PlayEmoteFromMenu()
	{
		ScriptInputUserData ctx = new ScriptInputUserData;
		if (GetGame().IsMultiplayer() && GetGame().IsClient() && ctx.CanStoreInputUserData())
		{
			ctx.Write(INPUT_UDT_GESTURE);
			ctx.Write(m_MenuEmote.m_ID);
			m_RPSOutcome = -1;
			switch (m_MenuEmote.m_ID)
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
			m_DeferredMenuEmoteLaunch = m_MenuEmote.m_ID;
			//PlayEmote(m_MenuEmote.m_ID);
			m_MenuEmote = NULL;
		}
		else if (!GetGame().IsMultiplayer())
		{
			PlayEmote(m_MenuEmote.m_ID);
			m_MenuEmote = NULL;
		}
	}
	
	bool IsControllsLocked()
	{
		return m_controllsLocked;
	}
	
	bool CanPlayEmote(int id)
	{
		if (m_BelayedEmote && id == m_CurrentGestureID)
		{
			return false;
		}
		
		if ( !m_Player || m_Player.GetCommand_Action() || m_Player.GetCommandModifier_Action() )
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
		
		if ( m_HIC.IsWeaponRaised() || m_Player.IsFighting() || m_Player.IsSwimming() || m_Player.IsClimbingLadder() || m_Player.IsFalling() || m_Player.IsUnconscious() ) 	// rework conditions into something better?
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
		
		if ( m_HandInventoryLocation && m_Player.GetInventory().HasInventoryReservation(null, m_HandInventoryLocation) )
		{
			if ( m_IsSurrendered && (id == ID_EMOTE_SURRENDER) )
			{
				return true;
			}
			if ( m_Callback && m_Callback.m_IsFullbody )
			{
				return true;
			}
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
			m_ItemToBeCreated = true;
			/*if ((GetGame().IsMultiplayer() && !GetGame().IsServer()) || !GetGame().IsMultiplayer())
			{*/
			if (m_Player.GetItemInHands() && !m_Player.CanDropEntity(m_Player.GetItemInHands()))
				return;
			if (m_Player.GetItemInHands() && GetGame().IsClient())
			{
				m_Player.DropItem(m_Player.GetItemInHands());
				//m_Player.LocalDropEntity(m_Player.GetItemInHands());
			}
			//}
			CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SURRENDERIN,DayZPlayerConstants.STANCEMASK_ALL,true);
			if (m_Callback)
				m_Callback.RegisterAnimationEvent("ActionExec", UA_ANIM_EVENT);
		}
		else
		{
			CreateEmoteCallback(EmoteCB,DayZPlayerConstants.CMD_GESTUREFB_SURRENDEROUT,DayZPlayerConstants.STANCEMASK_ALL,true);
			/*if (m_Callback)
				m_Callback.RegisterAnimationEvent("ActionExec", UA_ANIM_EVENT);*/
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
				m_Player.GetActionManager().EnableActions();
			
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
				m_Player.GetInventory().AddInventoryReservation( null, m_HandInventoryLocation, 10000);
			}
				
			if ( m_Player.GetActionManager() )
				m_Player.GetActionManager().DisableActions();
			
			//m_Player.SetInventorySoftLock(true);
			
			//Movement lock in fullbody anims
			if (m_Callback && m_Callback.m_IsFullbody && !m_controllsLocked /*&& m_CurrentGestureID == ID_EMOTE_SURRENDER*/)
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
		//Print("LockCheckCalled");
		if ( !m_Player.GetItemInHands() || (m_Player.GetItemInHands() && !SurrenderDummyItem.Cast(m_Player.GetItemInHands())) )
			return;
		
		/*if ( !m_EmoteLockState && SurrenderDummyItem.Cast(m_Player.GetItemInHands()) )
		{
			m_IsSurrendered = true;
			SetEmoteLockState(true);
			return;
		}*/
		
		//refreshes reservation in case of unwanted timeout
		if ( m_EmoteLockState && m_HandInventoryLocation/* && !m_Player.GetInventory().HasInventoryReservation(null, m_HandInventoryLocation)*/ )
		{
			m_Player.GetInventory().ExtendInventoryReservation( null, m_HandInventoryLocation, 10000);
		}
	}
	
	//! force-ends surrender state from outside of normal flow
	void EndSurrenderRequest(SurrenderData data)
	{
		if (m_IsSurrendered)
		{
			SetEmoteLockState(false);
			if (m_Player.GetItemInHands())
				m_Player.GetItemInHands().Delete();
			
			m_IsSurrendered = false;
			
			data.End();
		}
	}
	
	bool InterruptGesture()
	{
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
};

class SurrenderData
{
	//!called on surrender end request end
	void End();
}