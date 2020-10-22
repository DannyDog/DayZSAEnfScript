//Post event containers
class DeferredEvent
{
	InventoryMode m_mode;
}


class DeferredTakeToDst : DeferredEvent
{
	ref InventoryLocation m_src;
	ref InventoryLocation m_dst;
	
	void DeferredTakeToDst(InventoryMode mode, notnull InventoryLocation src, notnull InventoryLocation dst)
	{
		m_mode = mode;
		m_src = src;
		m_dst = dst;
	}
}

class DeferredSwapEntities : DeferredEvent
{
	EntityAI m_item1;
	EntityAI m_item2;
	ref InventoryLocation m_dst1;
	ref InventoryLocation m_dst2;
	
	void DeferredSwapEntities(InventoryMode mode, notnull EntityAI item1, notnull EntityAI item2, notnull InventoryLocation dst1, notnull InventoryLocation dst2)
	{
		m_mode = mode;
		m_item1 = item1;
		m_item2 = item2;
		m_dst1 = dst1;
		m_dst2 = dst2;
	}
}

class DeferredForceSwapEntities : DeferredEvent
{
	EntityAI m_item1;
	EntityAI m_item2;
	ref InventoryLocation m_dst1;
	ref InventoryLocation m_dst2;
	
	void DeferredForceSwapEntities(InventoryMode mode, notnull EntityAI item1, notnull EntityAI item2, notnull InventoryLocation dst1, notnull InventoryLocation dst2)
	{
		m_mode = mode;
		m_item1 = item1;
		m_item2 = item2;
		m_dst1 = dst1;
		m_dst2 = dst2;
	}
}

class DeferredHandEvent: DeferredEvent
{
	ref HandEventBase m_event;
	void DeferredHandEvent(InventoryMode mode, HandEventBase e)
	{
		m_mode = mode;
		m_event = e;		
	}	
}


/**
 * @class		DayZPlayerInventory
 **/
class DayZPlayerInventory : HumanInventoryWithFSM
{
	ref DeferredEvent m_DeferredEvent = NULL;
	ref Timer m_DeferredWeaponTimer = new Timer;
	//protected ref HandEventBase m_PostedHandEvent = NULL; /// deferred hand event
	
	
	protected ref HandEventBase m_DeferredPostedHandEvent = NULL; /// deferred hand event
	ref WeaponEventBase m_DeferredWeaponEvent = NULL; /// deferred weapon event
	// states with animations
	protected ref HandAnimatedTakingFromAtt m_Taking;
	protected ref HandAnimatedMovingToAtt m_MovingTo;
	protected ref HandAnimatedSwapping m_Swapping;
	protected ref HandAnimatedForceSwapping m_FSwapping;

	void DayZPlayerInventory () 
	{
	}

	DayZPlayer GetDayZPlayerOwner () { return DayZPlayer.Cast(GetInventoryOwner()); }

	override void Init ()
	{
		hndDebugPrint("[hndfsm] Creating DayZPlayer Inventory FSM");
		
		CreateStableStates(); // stable states needs to be created first

		m_Taking = new HandAnimatedTakingFromAtt(GetManOwner(), null);
		m_MovingTo = new HandAnimatedMovingToAtt(GetManOwner(), null);
		m_Swapping = new HandAnimatedSwapping(GetManOwner(), null);
		m_FSwapping = new HandAnimatedForceSwapping(GetManOwner(), null);

		// events
		HandEventBase _fin_ = new HandEventHumanCommandActionFinished;
		HandEventBase _abt_ = new HandEventHumanCommandActionAborted;
		HandEventBase __T__ = new HandEventTake;
		HandEventBase __M__ = new HandEventMoveTo;
		HandEventBase __W__ = new HandEventSwap;
		//HandEventBase __D__ = new HandEventDropping;
		HandEventBase __Xd_ = new HandEventDestroyed;
		HandEventBase __F__ = new HandEventForceSwap;

		// setup transitions
		m_FSM.AddTransition(new HandTransition( m_Empty   , __T__,    m_Taking, NULL, new HandSelectAnimationOfTakeToHandsEvent(GetManOwner())));
		m_FSM.AddTransition(new HandTransition( m_Taking  , _fin_,  m_Equipped, null, null));
		m_FSM.AddTransition(new HandTransition( m_Taking  , __Xd_,  m_Empty, new HandActionDestroyed, new HandGuardHasDestroyedItemInHands(GetManOwner())));
			m_Taking.AddTransition(new HandTransition(  m_Taking.m_Hide, _abt_,   m_Empty));
			m_Taking.AddTransition(new HandTransition(  m_Taking.m_Show, _abt_,   m_Equipped));

		m_FSM.AddTransition(new HandTransition( m_Equipped, __M__,  m_MovingTo, NULL, new HandSelectAnimationOfMoveFromHandsEvent(GetManOwner())));
		m_FSM.AddTransition(new HandTransition( m_MovingTo, __Xd_,  m_Empty, new HandActionDestroyed, new HandGuardHasDestroyedItemInHands(GetManOwner())));
		m_FSM.AddTransition(new HandTransition( m_MovingTo, _fin_,  m_Empty   , null, null));
			m_MovingTo.AddTransition(new HandTransition(  m_MovingTo.m_Hide, _abt_,   m_Equipped));
			m_MovingTo.AddTransition(new HandTransition(  m_MovingTo.m_Show, _abt_,   m_Empty));

		m_FSM.AddTransition(new HandTransition( m_Equipped, __W__,  m_Swapping, NULL, new HandSelectAnimationOfSwapInHandsEvent(GetManOwner())));
		m_FSM.AddTransition(new HandTransition( m_Swapping, __Xd_,  m_Empty, new HandActionDestroyed, new HandGuardHasDestroyedItemInHands(GetManOwner())));
		m_FSM.AddTransition(new HandTransition( m_Swapping, _fin_,  m_Equipped, null, null));
		m_FSM.AddTransition(new HandTransition( m_Swapping, _abt_,  m_Equipped, null, null));

		m_FSM.AddTransition(new HandTransition( m_Equipped, __F__, m_FSwapping, NULL, new HandSelectAnimationOfForceSwapInHandsEvent(GetManOwner())));
		m_FSM.AddTransition(new HandTransition(m_FSwapping, _fin_,  m_Equipped, null, null));
		m_FSM.AddTransition(new HandTransition(m_FSwapping, _abt_,  m_Equipped, null, null));
		m_FSM.AddTransition(new HandTransition(m_FSwapping, __Xd_,  m_Empty, new HandActionDestroyed, new HandGuardHasDestroyedItemInHands(GetManOwner())));

		super.Init(); // initialize ordinary human fsm (no anims)
	}

	/**@fn	PostHandEvent
	 * @brief	deferred hands's fsm handling of events
	 * @NOTE: "post" stores the event for later use when ::CommandHandler is being run
	 **/
	override void PostHandEvent (HandEventBase e)
	{
		// @NOTE: synchronous event from server. this happens only on client(s) and is caused by CreateVehicle and DeleteObject network messages.
		bool synchronous = e.GetEventID() == HandEventID.DESTROYED || e.GetEventID() == HandEventID.CREATED;
		// @NOTE: there is no HandleInventory(dt) called on Remote(s). Immeadiate processing as workaroud.
		DayZPlayerInstanceType inst_type = GetDayZPlayerOwner().GetInstanceType();
		bool remote =  inst_type == DayZPlayerInstanceType.INSTANCETYPE_REMOTE || inst_type == DayZPlayerInstanceType.INSTANCETYPE_AI_REMOTE;
		if (synchronous || GetInventoryOwner().IsDamageDestroyed() || remote)
		{
 			hndDebugPrint("[hndfsm] SYNCHRONOUS hand event e=" + e.ToString());
			ProcessHandEvent(e);
		}
		else
		{
			if (m_DeferredPostedHandEvent == NULL)
			{
				m_DeferredPostedHandEvent = e;
				hndDebugPrint("[hndfsm] STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " Posted event m_DeferredPostedHandEvent=" + m_DeferredPostedHandEvent.ToString());
			}
			else
				Error("[hndfsm] warning - pending hand event already posted, curr_event=" + m_DeferredPostedHandEvent.ToString() + " new_event=" + e.ToString());
		}
	}
	
	/**@fn	CancelHandEvent
	 * @brief	cancels any handevents that will be executed this frame
	 * @NOTE: this is used in situations where the player performs an action that renders the event invalid exactly on the frame it will be executed
	 **/
	void CancelHandEvent ()
	{
		m_DeferredPostedHandEvent = null;
		//m_postedHandEvent = null;
	}
	
	void CancelWeaponEvent ()
	{
		m_DeferredWeaponEvent = null;
		m_DeferredWeaponTimer.Stop();
	}

	void AbortWeaponEvent ()
	{
		HumanCommandWeapons hcw = GetDayZPlayerOwner().GetCommandModifier_Weapons();
			
		Weapon_Base weapon;
		Class.CastTo(weapon, GetEntityInHands());
			
		if (hcw && weapon && weapon.CanProcessWeaponEvents() && !weapon.IsIdle())
		{
			wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(weapon) + " Weapon event: ABORT! notifying running state=" + weapon.GetCurrentState());
			weapon.ProcessWeaponAbortEvent(new WeaponEventHumanCommandActionAborted(GetDayZPlayerOwner()));
		}
	}
	
	/**@fn	PostWeaponEvent
	 * @brief	deferred weapon's fsm handling of events
	 * @NOTE: "post" stores the event for later use when ::CommandHandler is being run
	 **/
	void PostWeaponEvent (WeaponEventBase e)
	{
		if (m_DeferredWeaponEvent == NULL)
		{
			m_DeferredWeaponEvent = e;
			wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(GetInventoryOwner()) + " Posted event m_DeferredWeaponEvent=" + m_DeferredWeaponEvent.DumpToString());
		}
		else
			Error("[wpnfsm] " + Object.GetDebugName(GetInventoryOwner()) + " warning - pending event already posted, curr_event=" + m_DeferredWeaponEvent.DumpToString() + " new_event=" + e.DumpToString());
	}
	
	void DeferredWeaponFailed()
	{
		Weapon_Base weapon;
		Class.CastTo(weapon, GetEntityInHands());
		
		string secondPart = " - ENTITY IN HANDS IS NOT A WEAPON: " + Object.GetDebugName(GetEntityInHands());
		
		string firstPart = "[wpnfsm] " + Object.GetDebugName(GetInventoryOwner()) + " failed to perform weaponevent " + m_DeferredWeaponEvent.DumpToString();
		if (weapon)
		{
			secondPart = " on " + Object.GetDebugName(GetEntityInHands()) + " which is in state " + weapon.GetCurrentState();
			secondPart += " with physical state: J: " + weapon.IsJammed() + " | ";
			for (int i = 0; i < weapon.GetMuzzleCount(); ++i)
			{
				secondPart += "Chamber_" + i + ": B(" + weapon.IsChamberFull(i) + ") F(" + weapon.IsChamberFiredOut(i) + ") E(" + weapon.IsChamberEmpty(i) + ") | ";
				secondPart += "Magazine_" + i + ": " + weapon.GetMagazine(i);
				if (i < weapon.GetMuzzleCount() - 1)
					secondPart += " | ";
			}
		}
		
		Error(firstPart + secondPart);
		CancelWeaponEvent();
	}

	void HandleWeaponEvents (float dt, out bool exitIronSights)
	{
		HumanCommandWeapons hcw = GetDayZPlayerOwner().GetCommandModifier_Weapons();

		Weapon_Base weapon;
		Class.CastTo(weapon, GetEntityInHands());
		
		if (hcw && weapon && weapon.CanProcessWeaponEvents())
		{
			weapon.GetCurrentState().OnUpdate(dt);

			wpnDebugSpamALot("[wpnfsm] " + Object.GetDebugName(weapon) + " HCW: playing A=" + typename.EnumToString(WeaponActions, hcw.GetRunningAction()) + " AT=" + WeaponActionTypeToString(hcw.GetRunningAction(), hcw.GetRunningActionType()) + " fini=" + hcw.IsActionFinished());

			if (!weapon.IsIdle())
			{
				while (true)
				{
					int weaponEventId = hcw.IsEvent();
					if (weaponEventId == -1)
					{
						break;
					}

					if (weaponEventId == WeaponEvents.CHANGE_HIDE)
					{
						break;
					}

					WeaponEventBase anim_event = WeaponAnimEventFactory(weaponEventId, GetDayZPlayerOwner(), NULL);
					wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(weapon) + " HandleWeapons: event arrived " + typename.EnumToString(WeaponEvents, weaponEventId) + "(" + weaponEventId + ")  fsm_ev=" + anim_event.ToString());
					if (anim_event != NULL)
					{
						weapon.ProcessWeaponEvent(anim_event);
					}
				}

				if (hcw.IsActionFinished())
				{
					if (weapon.IsWaitingForActionFinish())
					{
						wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(weapon) + " Weapon event: finished! notifying waiting state=" + weapon.GetCurrentState());
						weapon.ProcessWeaponEvent(new WeaponEventHumanCommandActionFinished(GetDayZPlayerOwner()));
					}
					else
					{
						wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(weapon) + " Weapon event: ABORT! notifying running state=" + weapon.GetCurrentState());
						weapon.ProcessWeaponAbortEvent(new WeaponEventHumanCommandActionAborted(GetDayZPlayerOwner()));
					}
				}
			}

			if (m_DeferredWeaponEvent)
			{
				wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(weapon) + " Weapon event: deferred " + m_DeferredWeaponEvent.DumpToString());
				if (weapon.ProcessWeaponEvent(m_DeferredWeaponEvent))
				{
					exitIronSights = true;
					fsmDebugSpam("[wpnfsm] " + Object.GetDebugName(weapon) + " Weapon event: resetting deferred event" + m_DeferredWeaponEvent.DumpToString());
					m_DeferredWeaponEvent = NULL;
					m_DeferredWeaponTimer.Stop();
				}
				else if (!m_DeferredWeaponTimer.IsRunning())
				{
					m_DeferredWeaponTimer.Run(3, this, "DeferredWeaponFailed");
				}
			}
		}
	}
	
	void HandleInventory (float dt)
	{
		HumanCommandWeapons hcw = GetDayZPlayerOwner().GetCommandModifier_Weapons();

		EntityAI ih = GetEntityInHands();
		Weapon_Base weapon;
		Class.CastTo(weapon, ih);
		
		if (hcw)
		{
			m_FSM.GetCurrentState().OnUpdate(dt);

			hndDebugSpamALot("[hndfsm] HCW: playing A=" + typename.EnumToString(WeaponActions, hcw.GetRunningAction()) + " AT=" + WeaponActionTypeToString(hcw.GetRunningAction(), hcw.GetRunningActionType()) + " fini=" + hcw.IsActionFinished());
			
			if ( !m_FSM.GetCurrentState().IsIdle() || !m_FSM.IsRunning() )
			{
				while (true)
				{
					int weaponEventId = hcw.IsEvent();
					if (weaponEventId == -1)
					{
						break;
					}

					HandEventBase anim_event = HandAnimEventFactory(weaponEventId, GetManOwner(), NULL);
					hndDebugPrint("[hndfsm] HandleInventory: event arrived " + typename.EnumToString(WeaponEvents, weaponEventId) + "(" + weaponEventId + ")  fsm_ev=" + anim_event.ToString());
					if (anim_event != NULL)
					{
						SyncHandEventToRemote(anim_event);
						ProcessHandEvent(anim_event);
					}
				}

				if (hcw.IsActionFinished())
				{
					if (m_FSM.GetCurrentState().IsWaitingForActionFinish())
					{
						hndDebugPrint("[hndfsm] Hand-Weapon event: finished! notifying waiting state=" + m_FSM.GetCurrentState());
						HandEventBase fin_event = new HandEventHumanCommandActionFinished(GetManOwner());
						SyncHandEventToRemote(fin_event);
						ProcessHandEvent(fin_event);
					}
					else
					{
						hndDebugPrint("[hndfsm] Hand-Weapon event: ABORT! notifying running state=" + m_FSM.GetCurrentState());
						HandEventBase abt_event = new HandEventHumanCommandActionAborted(GetManOwner());
						SyncHandEventToRemote(abt_event);						
						ProcessHandAbortEvent(abt_event);
						//m_FSM.ProcessHandAbortEvent(new WeaponEventHumanCommandActionAborted(GetManOwner()));
					}
				}
			}
		}
		
		if (m_DeferredPostedHandEvent)
		{
			hndDebugSpam("[hndfsm] STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " Hand event: deferred " + m_DeferredPostedHandEvent);

			HandEventBase hndEvent = m_DeferredPostedHandEvent; // make a copy for processing and release post
			hndDebugSpam("[hndfsm] STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " Hand event: deferred event reset to null.");
			m_DeferredPostedHandEvent = NULL;

			ProcessHandEvent(hndEvent); // process copy
		}
	}


	///@{ juncture
	/**@fn			OnInventoryJunctureFromServer
	 * @brief		reaction to engine callback
	 *	originates in:
	 *				engine - DayZPlayer::OnSyncJuncture
	 *				script - PlayerBase.OnSyncJuncture
	 **/
	override bool OnInventoryJunctureFromServer (ParamsReadContext ctx)
	{
		int tmp = -1;
		ctx.Read(tmp);
		syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " store Juncture packet STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp());
			StoreJunctureData(ctx);
		return true;
	}
	
	///@{ juncture
	/**@fn			OnInventoryJunctureFromServer
	 * @brief		reaction to engine callback
	 *	originates in:
	 *				engine - DayZPlayer::OnSyncJuncture
	 *				script - PlayerBase.OnSyncJuncture
	 **/
	override bool OnInventoryJunctureRepairFromServer (ParamsReadContext ctx)
	{
/*		InventoryLocation il = new InventoryLocation;
		if (!il.ReadFromContext(ctx) )
			return false;
		
		InventoryLocation il_current = new InventoryLocation;
		
		EntityAI item = il.GetItem();
		item.GetInventory().GetCurrentInventoryLocation(il_current);
		
		if( !il_current.CompareLocationOnly(il))
		{
			LocationMoveEntity(il_current,il);
		}*/
		return true;
	}
	
	/**@fn			OnHandleStoredJunctureData
	 * @brief		reaction to engine callback
	 *	originates in engine - DayZPlayerInventory::HandleStoredJunctureData
	 **/
	protected void OnHandleStoredJunctureData (ParamsReadContext ctx)
	{
		int tmp = -1;
		ctx.Read(tmp);
		syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " handle JunctureData packet STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp());
		HandleInputData(true, false, ctx);
	}

	/**@fn			StoreJunctureData
	 * @brief		stores received input user data for later handling
	/aaa
	 **/
	proto native void StoreJunctureData (ParamsReadContext ctx);
	///@} juncture


	///@{ input user data
	/**@fn			OnInputUserDataProcess
	 * @brief		reaction to engine callback
	 *	originates in:
	 *				engine - DayZPlayer::OnInputUserDataReceived
	 *				script - DayZPlayerImplement.OnInputUserDataReceived
	 **/
	override bool OnInputUserDataProcess (ParamsReadContext ctx)
	{
		syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " store InputUserData packet STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp());
			StoreInputUserData(ctx);
		return true;
	}

	/**@fn			OnHandleStoredInputUserData
	 * @brief		reaction to engine callback
	 *	originates in engine - DayZPlayerInventory::HandleStoredInputUserData
	 **/
	protected void OnHandleStoredInputUserData (ParamsReadContext ctx)
	{
		int tmp = -1;
		ctx.Read(tmp);
		syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " handle InputUserData packet STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp());
		HandleInputData(false, false, ctx);
	}

	/**@fn			StoreInputUserData
	 * @brief		stores received input user data for later handling
	 **/
	proto native void StoreInputUserData (ParamsReadContext ctx);
	///@} input user data
	
	bool OnInputUserDataForRemote (ParamsReadContext ctx)
	{
		syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " remote handling InputUserData packet from server");
		return HandleInputData(false, true, ctx);
	}

	override void OnServerInventoryCommand (ParamsReadContext ctx)
	{
		syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " DZPInventory command from server");
		HandleInputData(true, true, ctx);
	}
	
	override bool ProccessInputData(int type, bool handling_juncture, bool remote, ParamsReadContext ctx)
	{
		if(super.ProccessInputData(type, handling_juncture, remote, ctx))
			return true;
		
		InventoryLocation correct_il;
		ScriptJunctureData ctx_repair;
		ScriptInputUserData n_ctx = new ScriptInputUserData;

		switch (type)
		{
			case InventoryCommandType.SYNC_MOVE:
			{
				InventoryLocation src = new InventoryLocation;
				InventoryLocation dst = new InventoryLocation;
				src.ReadFromContext(ctx);
				dst.ReadFromContext(ctx);
				
				if (remote && (!src.GetItem() || !dst.GetItem()))
				{
					syncDebugPrint("[syncinv] HandleInputData remote input (cmd=SYNC_MOVE) dropped, item not in bubble! src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
					break; // not in bubble
				}

				EnableMovableOverride(src.GetItem());
				if (!GameInventory.CheckRequestSrc(GetManOwner(), src, GameInventory.c_MaxItemDistanceRadius))
				{
					if( GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER )
					{
						correct_il = new InventoryLocation;
						src.GetItem().GetInventory().GetCurrentInventoryLocation(correct_il);
						
						
						if( !correct_il.CompareLocationOnly(src) )
						{
							ctx_repair = new ScriptJunctureData;
							correct_il.WriteToContext(ctx_repair);
							
							GetDayZPlayerOwner().SendSyncJuncture(DayZPlayerSyncJunctures.SJ_INVENTORY_REPAIR, ctx_repair);
						}
					}
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " failed src check with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src=" + InventoryLocation.DumpToStringNullSafe(src));
					RemoveMovableOverride(src.GetItem());
					return false; // stale packet
				}
				
				//Players should not try to determine whether some other player is cheater or not, this is up to that player and the server
				if ( IsServerOrLocalPlayer() &&  !GameInventory.CheckMoveToDstRequest(GetManOwner(), src, dst, GameInventory.c_MaxItemDistanceRadius) )
				{
					/*if( GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER )
					{
						correct_il = new InventoryLocation;
						src.GetItem().GetInventory().GetCurrentInventoryLocation(correct_il);
						
						
						if( !correct_il.CompareLocationOnly(src) )
						{
							ctx_repair = new ScriptJunctureData;
							correct_il.WriteToContext(ctx_repair);
							
							//GetDayZPlayerOwner().SendSyncJuncture(DayZPlayerSyncJunctures.SJ_INVENTORY_REPAIR, ctx_repair);
						}
					}*/
					
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " is cheating with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
					RemoveMovableOverride(src.GetItem());
					return false; // cheater
				}
				RemoveMovableOverride(src.GetItem());
				
				if( GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER )
				{
					if (!GameInventory.LocationCanMoveEntity(src, dst))
					{
						#ifdef DEVELOPER
							DumpInventoryDebug();
						#endif
						Error("[desync] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " CANNOT move cmd=" + typename.EnumToString(InventoryCommandType, type) + " src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
						return false;
					}
				}
				
				syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " HandleInputData t=" + GetGame().GetTime() + "ms received cmd=" + typename.EnumToString(InventoryCommandType, type) + " src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));

				if (!handling_juncture && GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
				{
					JunctureRequestResult result_mv = TryAcquireInventoryJunctureFromServer(GetDayZPlayerOwner(), src, dst);
					if (result_mv == JunctureRequestResult.JUNCTURE_NOT_REQUIRED)
					{
						// ok, perform sync move
					}
					else if (result_mv == JunctureRequestResult.JUNCTURE_ACQUIRED)
					{
						GetDayZPlayerOwner().SendSyncJuncture(DayZPlayerSyncJunctures.SJ_INVENTORY, ctx); // ok, send juncture
						EnableMovableOverride(src.GetItem());
						break; // and do NOT perform sync move
					}
					else if (result_mv == JunctureRequestResult.JUNCTURE_DENIED)
					{
						return true; // abort, do not send anything to remotes
					}
					else
					{
						Error("[syncinv] HandleInputData: unexpected return code from AcquireInventoryJunctureFromServer"); return true;
						return true; // abort, do not send anything to remotes
					}
				}

				if( GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
				{
					ClearInventoryReservation(dst.GetItem(),dst);
				}
				
				if (GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
					CheckForRope(src, dst);

				LocationSyncMoveEntity(src, dst);				
				break;
			}

			case InventoryCommandType.HAND_EVENT:
			{
				HandEventBase e = HandEventBase.CreateHandEventFromContext(ctx);
				EntityAI itemSrc = e.GetSrcEntity();
				EntityAI itemDst = e.GetSecondSrcEntity();

				syncDebugPrint("[syncinv] HandleInputData remote input (cmd=HAND_EVENT) e=" + e.DumpToString());

				if (remote && !e.GetSrcEntity())
				{
					Error("[syncinv] HandleInputData remote input (cmd=HAND_EVENT) dropped, item not in bubble");
					break; // not in bubble
				}
				
				if (itemSrc)
					RemoveMovableOverride(itemSrc);
				if (itemDst)
					RemoveMovableOverride(itemDst);

				if (!e.CheckRequestSrc())
				{
					if( GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER && itemSrc )
					{
						correct_il = new InventoryLocation;
						itemSrc.GetInventory().GetCurrentInventoryLocation(correct_il);
						
						if( !correct_il.CompareLocationOnly(e.GetSrc()) )
						{
							ctx_repair = new ScriptJunctureData;
							correct_il.WriteToContext(ctx_repair);
							
							GetDayZPlayerOwner().SendSyncJuncture(DayZPlayerSyncJunctures.SJ_INVENTORY_REPAIR, ctx_repair);
						}
					}
					if (itemSrc)
						RemoveMovableOverride(itemSrc);
					if (itemDst)
						RemoveMovableOverride(itemDst);
					return false; // stale packet
				}

				//Players should not try to determine whether some other player is cheater or not, this is up to that player and the server
				if ( IsServerOrLocalPlayer() && !e.CheckRequest() )
				{
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " is cheating with cmd=" + typename.EnumToString(InventoryCommandType, type) + " event=" + e.DumpToString());
					if (itemSrc)
						RemoveMovableOverride(itemSrc);
					if (itemDst)
						RemoveMovableOverride(itemDst);
					return false; // cheater
				}
				
				if ( GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER )
				{
					if (!e.CanPerformEvent())
					{
						syncDebugPrint("[desync] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " CANNOT do cmd=HAND_EVENT e=" + e.DumpToString());
						if (itemSrc)
							RemoveMovableOverride(itemSrc);
						if (itemDst)
							RemoveMovableOverride(itemDst);
						return false;
					}
				}
				if (itemSrc)
					RemoveMovableOverride(itemSrc);
				if (itemDst)
					RemoveMovableOverride(itemDst);

				syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " HandleInputData t=" + GetGame().GetTime() + "ms received cmd=" + typename.EnumToString(InventoryCommandType, type) + " event=" + e.DumpToString());

				if (!handling_juncture && GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
				{
					JunctureRequestResult result_ev = e.AcquireInventoryJunctureFromServer(GetDayZPlayerOwner());
					if (result_ev == JunctureRequestResult.JUNCTURE_NOT_REQUIRED)
					{
						// ok, post event
					}
					else if (result_ev == JunctureRequestResult.JUNCTURE_ACQUIRED)
					{
						GetDayZPlayerOwner().SendSyncJuncture(DayZPlayerSyncJunctures.SJ_INVENTORY, ctx); // ok, send juncture
						if (itemSrc)
							EnableMovableOverride(itemSrc);
						if (itemDst)
							EnableMovableOverride(itemDst);
						break; // and do NOT perform post event
					}
					else if (result_ev == JunctureRequestResult.JUNCTURE_DENIED)
					{
						return true; // abort, do not send anything to remotes
					}
					else
					{
						Error("[syncinv] HandleInputData: unexpected return code from AcquireInventoryJunctureFromServer"); return true;
						return true; // abort, do not send anything to remotes
					}
				}
				
				if (GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
					CheckForRope(e.GetSrc(), e.GetDst());
				
				if (handling_juncture)
				{
					// juncture is already handled inside DayZPlayer::Simulate so it can be handled synchronously right now without delaying via m_PostedEvent
					e.m_Player.GetHumanInventory().ProcessHandEvent(e);
				}
				else
					e.m_Player.GetHumanInventory().PostHandEvent(e);
				break;
			}

			case InventoryCommandType.SWAP:
			{
				InventoryLocation src1 = new InventoryLocation;
				InventoryLocation src2 = new InventoryLocation;
				InventoryLocation dst1 = new InventoryLocation;
				InventoryLocation dst2 = new InventoryLocation;
				bool skippedSwap = false;
				
				src1.ReadFromContext(ctx);
				src2.ReadFromContext(ctx);
				dst1.ReadFromContext(ctx);
				dst2.ReadFromContext(ctx);
				ctx.Read(skippedSwap);
				
				if (remote && (!src1.GetItem() || !src2.GetItem()))
				{
					if (skippedSwap)
						syncDebugPrint("[syncinv] HandleInputData remote input (cmd=SWAP) dropped, swap is skipped");
					else
						Error("[syncinv] HandleInputData remote input (cmd=SWAP) dropped, item not in bubble");
					break; // not in bubble
				}
				
				EnableMovableOverride(src1.GetItem());
				EnableMovableOverride(src2.GetItem());
				
				if (false == GameInventory.CheckRequestSrc(GetManOwner(), src1, GameInventory.c_MaxItemDistanceRadius))
				{
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " failed src1 check with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src1=" + InventoryLocation.DumpToStringNullSafe(src1));
					RemoveMovableOverride(src1.GetItem());
					RemoveMovableOverride(src2.GetItem());
					return false; // stale packet
				}
				if (false == GameInventory.CheckRequestSrc(GetManOwner(), src2, GameInventory.c_MaxItemDistanceRadius))
				{
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " failed src2 check with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2));
					RemoveMovableOverride(src1.GetItem());
					RemoveMovableOverride(src2.GetItem());
					return false; // stale packet
				}

				//Players should not try to determine whether some other player is cheater or not, this is up to that player and the server
				if ( IsServerOrLocalPlayer() && !GameInventory.CheckSwapItemsRequest(GetManOwner(), src1, src2, dst1, dst2, GameInventory.c_MaxItemDistanceRadius))
				{
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " is cheating with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2) +  " dst1=" + InventoryLocation.DumpToStringNullSafe(dst1) + " dst2=" + InventoryLocation.DumpToStringNullSafe(dst2));
					RemoveMovableOverride(src1.GetItem());
					RemoveMovableOverride(src2.GetItem());
					return false; // cheater
				}
				
				RemoveMovableOverride(src1.GetItem());
				RemoveMovableOverride(src2.GetItem());
				
				if( GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER )
				{
					if (false == GameInventory.CanForceSwapEntitiesEx(src1.GetItem(), dst1, src2.GetItem(), dst2))
					{
						#ifdef DEVELOPER
							DumpInventoryDebug();
						#endif
						Error("[desync] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " CANNOT swap cmd=" + typename.EnumToString(InventoryCommandType, type) + " src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " dst1=" + InventoryLocation.DumpToStringNullSafe(dst1) +" | src2=" + InventoryLocation.DumpToStringNullSafe(src2) + " dst2=" + InventoryLocation.DumpToStringNullSafe(dst2));
						return false;
					}
				}

				if (src1.IsValid() && src2.IsValid() && dst1.IsValid() && dst2.IsValid())
				{
					if (!handling_juncture && GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
					{
						JunctureRequestResult result_sw = TryAcquireTwoInventoryJuncturesFromServer(GetDayZPlayerOwner(), src1, src2, dst1, dst2);
						if (result_sw == JunctureRequestResult.JUNCTURE_NOT_REQUIRED)
						{
							// ok, perform swap
						}
						else if (result_sw == JunctureRequestResult.JUNCTURE_ACQUIRED)
						{
							GetDayZPlayerOwner().SendSyncJuncture(DayZPlayerSyncJunctures.SJ_INVENTORY, ctx); // ok, send juncture
							EnableMovableOverride(src1.GetItem());
							EnableMovableOverride(src2.GetItem());
							break; // and do NOT perform swap
						}
						else if (result_sw == JunctureRequestResult.JUNCTURE_DENIED)
						{
							return true; // abort, do not send anything to remotes
						}
						else
						{
							Error("[syncinv] HandleInputData: unexpected return code from TryAcquireTwoInventoryJuncturesFromServer"); return true;
							return true; // abort, do not send anything to remotes
						}
					}
					
					if (GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
					{
						ClearInventoryReservation(dst1.GetItem(),dst1);
						ClearInventoryReservation(dst2.GetItem(),dst2);
					}

					bool isNotSkipped = LocationSwap(src1, src2, dst1, dst2);
					
					InventoryInputUserData.SerializeSwap(n_ctx, src1, src2, dst1, dst2, !isNotSkipped);
					ctx = n_ctx;
				}
				else
				{
					Error("HandleInputData: cmd=" + typename.EnumToString(InventoryCommandType, type) + " invalid input(s): src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2) +  " dst1=" + InventoryLocation.DumpToStringNullSafe(dst1) + " dst2=" + InventoryLocation.DumpToStringNullSafe(dst2));
					return true; // abort, do not send anything to remotes
				}

				break;
			}

			case InventoryCommandType.FORCESWAP:
			{
				Error("[syncinv] DZPI.ForceSwap TODO");
				break;
			}

			case InventoryCommandType.DESTROY:
			{
				src.ReadFromContext(ctx);
				syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " HandleInputData t=" + GetGame().GetTime() + "ms received cmd=" + typename.EnumToString(InventoryCommandType, type) + " src=" + InventoryLocation.DumpToStringNullSafe(src));

				if (remote && !src.GetItem())
				{
					Error("[syncinv] HandleInputData remote input (cmd=DESTROY) dropped, item not in bubble");
					break; // not in bubble
				}
				
				if (false == GameInventory.CheckRequestSrc(GetManOwner(), src, GameInventory.c_MaxItemDistanceRadius))
				{
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " failed src check with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src=" + InventoryLocation.DumpToStringNullSafe(src));
					return false; // stale packet
				}

				//Players should not try to determine whether some other player is cheater or not, this is up to that player and the server
				if ( IsServerOrLocalPlayer() && !GameInventory.CheckDropRequest(GetManOwner(), src, GameInventory.c_MaxItemDistanceRadius))
				{
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " is cheating with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src=" + InventoryLocation.DumpToStringNullSafe(src));
					return false; // cheater
				}

				GetGame().ObjectDelete(src.GetItem());
				break;
			}
		}

		StoreInputForRemotes(handling_juncture, remote, ctx);

		return true;
	}

	/**@fn			HandleInputData
	 * @brief		real processing of the input data
	 **/
	bool HandleInputData (bool handling_juncture, bool remote, ParamsReadContext ctx)
	{
		syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " HANDLE rmt=" + remote + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " HandleInputData t=" + GetGame().GetTime() + " pos=" + GetDayZPlayerOwner().GetPosition());

		int type = -1;
		if (!ctx.Read(type))
			return false;
		
		return ProccessInputData(type,handling_juncture, remote, ctx);
	}
	
	void RemoveMovableOverride(EntityAI item)
	{
		ItemBase itemIB = ItemBase.Cast(item);
		if (itemIB)
			itemIB.SetCanBeMovedOverride(false);
	}
	
	void EnableMovableOverride(EntityAI item)
	{
		ItemBase itemIB = ItemBase.Cast(item);
		if (itemIB)
			itemIB.SetCanBeMovedOverride(true);
	}
	
	// Hacky solution for dealing with fencekit rope related issues, could be fixed by introducing some indicator that this item behaves differently or sth..
	void CheckForRope(InventoryLocation src, InventoryLocation dst)
	{
		Rope rope = Rope.Cast(src.GetItem());
		if (rope)
			rope.SetTargetLocation(dst);
	}
	
	bool IsServerOrLocalPlayer()
	{
		return GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER || GetDayZPlayerOwner() == GetGame().GetPlayer());
	}
	
	bool StoreInputForRemotes (bool handling_juncture, bool remote, ParamsReadContext ctx)
	{
		if (!handling_juncture && !remote && GetDayZPlayerOwner().GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
		{
			syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " StoreInputForRemotes forwarding to remotes");
			GetDayZPlayerOwner().StoreInputForRemotes(ctx); // @NOTE: needs to be called _after_ the operation
			return true;
		}
		return false;
	}
	
	override bool TakeToDst (InventoryMode mode, notnull InventoryLocation src, notnull InventoryLocation dst)
	{
		if (!GetManOwner().IsAlive())
			return super.TakeToDst(mode,src,dst);
		
		switch ( mode )
		{
			case InventoryMode.SERVER:
				if (RedirectToHandEvent(mode, src, dst))
					return true;

				if (GetDayZPlayerOwner().NeedInventoryJunctureFromServer(src.GetItem(), src.GetParent(), dst.GetParent()))
				{
					syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " DZPI::Take2Dst(" + typename.EnumToString(InventoryMode, mode) + ") need juncture src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
					
					if (GetGame().AddInventoryJuncture(GetDayZPlayerOwner(), src.GetItem(), dst, true, GameInventory.c_InventoryReservationTimeoutMS))
						syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " DZPI::Take2Dst(" + typename.EnumToString(InventoryMode, mode) + ") got juncture");
					else
						syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " DZPI::Take2Dst(" + typename.EnumToString(InventoryMode, mode) + ") got juncture");
				}

				syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " DZPI::Take2Dst(" + typename.EnumToString(InventoryMode, mode) + " server sync move src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
				ScriptInputUserData ctx = new ScriptInputUserData;
				InventoryInputUserData.SerializeMove(ctx, InventoryCommandType.SYNC_MOVE, src, dst);
	
				GetDayZPlayerOwner().SendSyncJuncture(DayZPlayerSyncJunctures.SJ_INVENTORY, ctx);
				syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " store input for remote - DZPI::Take2Dst(" + typename.EnumToString(InventoryMode, mode) + " server sync move src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
				GetDayZPlayerOwner().StoreInputForRemotes(ctx); // @TODO: is this right place? maybe in HandleInputData(server=true, ...)
				return true;
			
			case InventoryMode.LOCAL:
				LocationSyncMoveEntity(src, dst);
				return true;
		}
		if(!super.TakeToDst(mode,src,dst))
		{
			if (!m_DeferredEvent)
				m_DeferredEvent = new DeferredTakeToDst(mode,src,dst);
			else
				return false;
		}
		return true;
	}
	
	void HandleTakeToDst( DeferredEvent deferred_event )
	{
		DeferredTakeToDst deferred_take_to_dst = DeferredTakeToDst.Cast(deferred_event);
		if( deferred_take_to_dst )
		{
			inventoryDebugPrint("[inv] I::Take2Dst(" + typename.EnumToString(InventoryMode, deferred_take_to_dst.m_mode) + ") src=" + InventoryLocation.DumpToStringNullSafe(deferred_take_to_dst.m_src) + " dst=" + InventoryLocation.DumpToStringNullSafe(deferred_take_to_dst.m_dst));

			switch (deferred_take_to_dst.m_mode)
			{
				case InventoryMode.PREDICTIVE:
					InventoryInputUserData.SendInputUserDataMove(InventoryCommandType.SYNC_MOVE, deferred_take_to_dst.m_src, deferred_take_to_dst.m_dst);
					ClearInventoryReservation(deferred_take_to_dst.m_dst.GetItem(),deferred_take_to_dst.m_dst);
					LocationSyncMoveEntity(deferred_take_to_dst.m_src, deferred_take_to_dst.m_dst);
					break;
				case InventoryMode.JUNCTURE:
					DayZPlayer player = GetGame().GetPlayer();
					player.GetHumanInventory().AddInventoryReservation(deferred_take_to_dst.m_dst.GetItem(), deferred_take_to_dst.m_dst, GameInventory.c_InventoryReservationTimeoutShortMS);
					EnableMovableOverride(deferred_take_to_dst.m_dst.GetItem());	
					InventoryInputUserData.SendInputUserDataMove(InventoryCommandType.SYNC_MOVE, deferred_take_to_dst.m_src, deferred_take_to_dst.m_dst);
					break;
				case InventoryMode.LOCAL:
					break;
				case InventoryMode.SERVER:
					break;

					break;
				default:
					Error("HandEvent - Invalid mode");
			}
		}
	}
	
	override bool SwapEntities (InventoryMode mode, notnull EntityAI item1, notnull EntityAI item2)
	{
		InventoryLocation src1, src2, dst1, dst2;
		if( mode == InventoryMode.LOCAL )
		{
			if (GameInventory.MakeSrcAndDstForSwap(item1, item2, src1, src2, dst1, dst2))
			{
				LocationSwap(src1, src2, dst1, dst2);
				return true;
			}
		}
		
		if(!super.SwapEntities(mode,item1,item2))
		{
			GameInventory.MakeSrcAndDstForSwap(item1, item2, src1, src2, dst1, dst2);
			m_DeferredEvent = new DeferredSwapEntities(mode, item1, item2, dst1, dst2);
		}
		return true;
	}
	
	void HandleSwapEntities( DeferredEvent deferred_event )
	{
		DeferredSwapEntities deferred_swap_entities = DeferredSwapEntities.Cast(deferred_event);
		if( deferred_swap_entities )
		{
			InventoryLocation src1, src2, dst1, dst2;
			if (GameInventory.MakeSrcAndDstForSwap(deferred_swap_entities.m_item1, deferred_swap_entities.m_item2, src1, src2, dst1, dst2))
			{
				inventoryDebugPrint("[inv] I::Swap(" + typename.EnumToString(InventoryMode, deferred_swap_entities.m_mode) + ") src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2) +  " dst1=" + InventoryLocation.DumpToStringNullSafe(deferred_swap_entities.m_dst1) + " dst2=" + InventoryLocation.DumpToStringNullSafe(deferred_swap_entities.m_dst2));

				switch (deferred_swap_entities.m_mode)
				{
					case InventoryMode.PREDICTIVE:
						InventoryInputUserData.SendInputUserDataSwap(src1, src2, deferred_swap_entities.m_dst1, deferred_swap_entities.m_dst2);
						LocationSwap(src1, src2, deferred_swap_entities.m_dst1, deferred_swap_entities.m_dst2);
						break;
			
					case InventoryMode.JUNCTURE:
						DayZPlayer player = GetGame().GetPlayer();
						player.GetHumanInventory().AddInventoryReservation(deferred_swap_entities.m_dst1.GetItem(), deferred_swap_entities.m_dst1, GameInventory.c_InventoryReservationTimeoutShortMS);
						player.GetHumanInventory().AddInventoryReservation(deferred_swap_entities.m_dst2.GetItem(), deferred_swap_entities.m_dst2, GameInventory.c_InventoryReservationTimeoutShortMS);
						EnableMovableOverride(deferred_swap_entities.m_dst1.GetItem());
						EnableMovableOverride(deferred_swap_entities.m_dst2.GetItem());
						InventoryInputUserData.SendInputUserDataSwap(src1, src2, deferred_swap_entities.m_dst1, deferred_swap_entities.m_dst2);
						break;

					case InventoryMode.LOCAL:
						break;

					default:
						Error("SwapEntities - HandEvent - Invalid mode");
				}
			}
			else
				Error("SwapEntities - MakeSrcAndDstForSwap - no inv loc");
		}
	}
	
	override bool ForceSwapEntities (InventoryMode mode, notnull EntityAI item1, notnull EntityAI item2, notnull InventoryLocation item2_dst)
	{
		if( mode == InventoryMode.LOCAL )
		{
			InventoryLocation src1, src2, dst1;
			if (GameInventory.MakeSrcAndDstForForceSwap(item1, item2, src1, src2, dst1, item2_dst))
			{
				LocationSwap(src1, src2, dst1, item2_dst);
				return true;
			}
			
		}
		
		if(!super.ForceSwapEntities(mode,item1,item2,item2_dst))
		{
			if(!m_DeferredEvent)
			{
				if (GameInventory.MakeSrcAndDstForForceSwap(item1, item2, src1, src2, dst1, item2_dst))
				{
					m_DeferredEvent = new DeferredForceSwapEntities(mode,item1,item2, dst1, item2_dst);
				}
			}
		}
		
		return true;
	}

	void HandleForceSwapEntities( DeferredEvent deferred_event )
	{
		DeferredForceSwapEntities deferred_force_swap_entities = DeferredForceSwapEntities.Cast(deferred_event);
		if( deferred_force_swap_entities )
		{
			InventoryLocation src1, src2, dst1;
			if (GameInventory.MakeSrcAndDstForForceSwap(deferred_force_swap_entities.m_item1, deferred_force_swap_entities.m_item2, src1, src2, dst1, deferred_force_swap_entities.m_dst2))
			{
				inventoryDebugPrint("[inv] I::FSwap(" + typename.EnumToString(InventoryMode, deferred_force_swap_entities.m_mode) + ") src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2) +  " dst1=" + InventoryLocation.DumpToStringNullSafe(deferred_force_swap_entities.m_dst1) + " dst2=" + InventoryLocation.DumpToStringNullSafe(deferred_force_swap_entities.m_dst2));

				switch (deferred_force_swap_entities.m_mode)
				{
					case InventoryMode.PREDICTIVE:
						InventoryInputUserData.SendInputUserDataSwap(src1, src2, deferred_force_swap_entities.m_dst1, deferred_force_swap_entities.m_dst2);
						LocationSwap(src1, src2, deferred_force_swap_entities.m_dst1, deferred_force_swap_entities.m_dst2);
						break;

					case InventoryMode.JUNCTURE:
						DayZPlayer player = GetGame().GetPlayer();
						player.GetHumanInventory().AddInventoryReservation(deferred_force_swap_entities.m_dst1.GetItem(), deferred_force_swap_entities.m_dst1, GameInventory.c_InventoryReservationTimeoutShortMS);
						player.GetHumanInventory().AddInventoryReservation(deferred_force_swap_entities.m_dst2.GetItem(), deferred_force_swap_entities.m_dst2, GameInventory.c_InventoryReservationTimeoutShortMS);
				
						InventoryInputUserData.SendInputUserDataSwap(src1, src2, deferred_force_swap_entities.m_dst1, deferred_force_swap_entities.m_dst2);
						break;

					case InventoryMode.LOCAL:
						break;

					default:
						Error("ForceSwapEntities - HandEvent - Invalid mode");
				}
			}
			else
				Error("ForceSwapEntities - MakeSrcAndDstForForceSwap - no inv loc");
		}
	}
	
	static void SendServerHandEventViaJuncture (notnull DayZPlayer player, HandEventBase e)
	{
		if (GetGame().IsServer())
		{
			if (e.IsServerSideOnly())
				Error("[syncinv] " + Object.GetDebugName(player) + " SendServerHandEventViaJuncture - called on server side event only, e=" + e.DumpToString());
			
			if (player.IsAlive())
			{
				InventoryLocation dst = e.GetDst();
				InventoryLocation src = e.GetSrc();
				if (src.IsValid() && dst.IsValid())
				{
					if (player.NeedInventoryJunctureFromServer(src.GetItem(), src.GetParent(), dst.GetParent()))
					{
						syncDebugPrint("[syncinv] " + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " SendServerHandEventViaJuncture(" + typename.EnumToString(InventoryMode, InventoryMode.SERVER) + ") need juncture src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
						
						if (GetGame().AddInventoryJuncture(player, src.GetItem(), dst, true, GameInventory.c_InventoryReservationTimeoutMS))
							syncDebugPrint("[syncinv] " + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " SendServerHandEventViaJuncture(" + typename.EnumToString(InventoryMode, InventoryMode.SERVER) + ") got juncture");
						else
							syncDebugPrint("[syncinv] " + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " SendServerHandEventViaJuncture(" + typename.EnumToString(InventoryMode, InventoryMode.SERVER) + ") !got juncture");
					}
	
					syncDebugPrint("[syncinv] " + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " SendServerHandEventViaJuncture(" + typename.EnumToString(InventoryMode, InventoryMode.SERVER) + " server hand event src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
					
					ScriptInputUserData ctx = new ScriptInputUserData;
					InventoryInputUserData.SerializeHandEvent(ctx, e);
					player.SendSyncJuncture(DayZPlayerSyncJunctures.SJ_INVENTORY, ctx);
					syncDebugPrint("[syncinv] " + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " store input for remote - SendServerHandEventViaJuncture(" + typename.EnumToString(InventoryMode, InventoryMode.SERVER) + " server hand event src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
					player.StoreInputForRemotes(ctx); // @TODO: is this right place? maybe in HandleInputData(server=true, ...)
				}
			}
			else
			{
				Error("[syncinv] SendServerHandEventViaJuncture - called on dead player, juncture is for living only");
			}
		}
	}

	/**@fn			NetSyncCurrentStateID
	 * @brief		Engine callback - network synchronization of FSM's state. not intended to direct use.
	 **/
	override void NetSyncCurrentStateID (int id)
	{
		super.NetSyncCurrentStateID(id);

		GetDayZPlayerOwner().GetItemAccessor().OnItemInHandsChanged();
	}

	/**@fn			OnAfterStoreLoad
	 * @brief		engine reaction to load from database
	 *	originates in:
	 *				engine - Person::BinLoad
	 *				script - PlayerBase.OnAfterStoreLoad
	 **/
	override void OnAfterStoreLoad ()
	{
		GetDayZPlayerOwner().GetItemAccessor().OnItemInHandsChanged(true);
	}

	/**@fn			OnEventForRemoteWeapon
	 * @brief		reaction of remote weapon to (common user/anim/...) event sent from server
	 **/
	bool OnEventForRemoteWeapon (ParamsReadContext ctx)
	{
		if (GetEntityInHands())
		{
			Weapon_Base wpn = Weapon_Base.Cast(GetEntityInHands());
			if (wpn)
			{
				PlayerBase pb = PlayerBase.Cast(GetDayZPlayerOwner());

				WeaponEventBase e = CreateWeaponEventFromContext(ctx);
				if (pb && e)
				{
					pb.GetWeaponManager().SetRunning(true);
		
					fsmDebugSpam("[wpnfsm] " + Object.GetDebugName(wpn) + " recv event from remote: created event=" + e);
					if (e.GetEventID() == WeaponEventID.HUMANCOMMAND_ACTION_ABORTED)
					{
						wpn.ProcessWeaponAbortEvent(e);
					}
					else
					{
						wpn.ProcessWeaponEvent(e);
					}
					pb.GetWeaponManager().SetRunning(false);
				}
			}
			else
				Error("OnEventForRemoteWeapon - entity in hands, but not weapon. item=" + GetEntityInHands());
		}
		else
			Error("OnEventForRemoteWeapon - no entity in hands");
		return true;
	}


	/**@fn			OnHandEventForRemote
	 * @brief		reaction of remote weapon to (common user/anim/...) event sent from server
	 **/
	bool OnHandEventForRemote (ParamsReadContext ctx)
	{
		HandEventBase e = HandEventBase.CreateHandEventFromContext(ctx);
		if (e)
		{
			hndDebugSpam("[hndfsm] recv event from remote: created event=" + e);
			//m_FSM.ProcessEvent(e);
			if (e.GetEventID() == HandEventID.HUMANCOMMAND_ACTION_ABORTED)
			{
				ProcessEventResult aa;
				m_FSM.ProcessAbortEvent(e, aa);
			}
			else
			{
				m_FSM.ProcessEvent(e);
			}

			return true;
		}
		return false;
	}

	void SyncHandEventToRemote (HandEventBase e)
	{
		DayZPlayer p = GetDayZPlayerOwner();
		if (p && p.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)
		{
			ScriptRemoteInputUserData ctx = new ScriptRemoteInputUserData;

			ctx.Write(INPUT_UDT_HAND_REMOTE_EVENT);
			e.WriteToContext(ctx);

			hndDebugPrint("[hndfsm] send 2 remote: sending e=" + e + " id=" + e.GetEventID() + " p=" + p + "  e=" + e.DumpToString());
			p.StoreInputForRemotes(ctx);
		}
	}
	
	override void OnHandsExitedStableState (HandStateBase src, HandStateBase dst)
	{
		super.OnHandsExitedStableState(src, dst);

		hndDebugPrint("[hndfsm] hand fsm exit stable src=" + src.Type().ToString());
	}
	
	override void OnHandsEnteredStableState (HandStateBase src, HandStateBase dst)
	{
		super.OnHandsEnteredStableState(src, dst);

		hndDebugPrint("[hndfsm] hand fsm entered stable dst=" + dst.Type().ToString());
	}
	
	override void OnHandsStateChanged (HandStateBase src, HandStateBase dst)
	{
		super.OnHandsStateChanged(src, dst);

		hndDebugPrint("[hndfsm] hand fsm changed state src=" + src.Type().ToString() + " ---> dst=" + dst.Type().ToString());

		if (src.IsIdle())
			OnHandsExitedStableState(src, dst);
		
		if (dst.IsIdle())
			OnHandsEnteredStableState(src, dst);

#ifdef BOT
		PlayerBase p = PlayerBase.Cast(GetDayZPlayerOwner());
		if (p && p.m_Bot)
		{
			p.m_Bot.ProcessEvent(new BotEventOnItemInHandsChanged(p));
		}
#endif
	}
	
	override bool HandEvent(InventoryMode mode, HandEventBase e)
	{
		if (!m_DeferredEvent)
		{
			EntityAI itemInHands = GetEntityInHands();
			InventoryLocation handInventoryLocation = new InventoryLocation;
			handInventoryLocation.SetHands(GetInventoryOwner(), itemInHands);
			
			bool hadHandReservation = false;
			
			if (HasInventoryReservation(itemInHands, handInventoryLocation))
			{
				ClearInventoryReservation(itemInHands, handInventoryLocation);
				hadHandReservation = true;	
			}
			
			if (e.CanPerformEvent())
			{
				m_DeferredEvent = new DeferredHandEvent(mode,e);
				return true;
			}
			
			if (hadHandReservation)
				AddInventoryReservation(itemInHands, handInventoryLocation, GameInventory.c_InventoryReservationTimeoutMS);
		}
		return false;
	}
	
	
	void HandleHandEvent( DeferredEvent deferred_event)
	{
		DeferredHandEvent deferred_hand_event = DeferredHandEvent.Cast(deferred_event);
		if(deferred_hand_event)
		{
			hndDebugPrint("[inv] HumanInventory::HandEvent(" + typename.EnumToString(InventoryMode, deferred_hand_event.m_mode) + ") ev=" + deferred_hand_event.m_event.DumpToString());

			switch (deferred_hand_event.m_mode)
			{
				case InventoryMode.PREDICTIVE:
					InventoryInputUserData.SendInputUserDataHandEvent(deferred_hand_event.m_event);
					PostHandEvent(deferred_hand_event.m_event);
					break;

				case InventoryMode.JUNCTURE:
					InventoryInputUserData.SendInputUserDataHandEvent(deferred_hand_event.m_event);
					//Functionality to prevent desync when two players perform interfering action at the same time
					EntityAI itemSrc = deferred_hand_event.m_event.GetSrcEntity();
					EntityAI itemDst = null;
					if (deferred_hand_event.m_event.GetDst())
						itemDst = deferred_hand_event.m_event.GetDst().GetItem();
					if (itemSrc)
						EnableMovableOverride(itemSrc);
					if (itemDst)
						EnableMovableOverride(itemDst);
					break;

				case InventoryMode.LOCAL:
					PostHandEvent(deferred_hand_event.m_event);
					break;
			
				case InventoryMode.SERVER:
					hndDebugPrint("[inv] DZPI::HandEvent(" + typename.EnumToString(InventoryMode, deferred_hand_event.m_mode) + ")");
					if (!deferred_hand_event.m_event.IsServerSideOnly())
					{
						if (GetDayZPlayerOwner().IsAlive())
						{
							SendServerHandEventViaJuncture(GetDayZPlayerOwner(), deferred_hand_event.m_event);
						}
						else
						{
							InventoryInputUserData.SendServerHandEventViaInventoryCommand(GetDayZPlayerOwner(), deferred_hand_event.m_event);
						}
					}
               		PostHandEvent(deferred_hand_event.m_event);
               	 break;

				default:
					Error("HumanInventory::HandEvent - Invalid mode");
			}
		}
	}
	
	override void HandleInventoryManipulation()
	{
		super.HandleInventoryManipulation();
		if(m_DeferredEvent && ScriptInputUserData.CanStoreInputUserData() )
		{
			HandleHandEvent(m_DeferredEvent);
			HandleTakeToDst(m_DeferredEvent);
			HandleSwapEntities(m_DeferredEvent);
			HandleForceSwapEntities(m_DeferredEvent);
		
			m_DeferredEvent = null;
		}
	}
	
	
	
	bool IsProcessing()
	{
		return !m_FSM.GetCurrentState().IsIdle() || m_DeferredEvent || m_DeferredPostedHandEvent;
	}
};

