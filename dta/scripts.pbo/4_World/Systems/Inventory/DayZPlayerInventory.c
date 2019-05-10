/**
 * @class		DayZPlayerInventory
 **/
class DayZPlayerInventory : HumanInventoryWithFSM
{
	protected ref HandEventBase m_PostedHandEvent = NULL; /// deferred hand event
	ref WeaponEventBase m_PostedEvent = NULL; /// deferred weapon event
	// states with animations
	protected ref HandAnimatedTakingFromAtt m_Taking;
	protected ref HandAnimatedMovingToAtt m_MovingTo;
	protected ref HandAnimatedSwapping m_Swapping;
	protected ref HandAnimatedForceSwapping m_FSwapping;

	void DayZPlayerInventory () { }

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
		HandEventBase __F__ = new HandEventForceSwap;

		// setup transitions
		m_FSM.AddTransition(new HandTransition( m_Empty   , __T__,    m_Taking, NULL, new HandSelectAnimationOfTakeToHandsEvent(GetManOwner())));
		m_FSM.AddTransition(new HandTransition( m_Taking  , _fin_,  m_Equipped, null, null));
			m_Taking.AddTransition(new HandTransition(  m_Taking.m_Hide, _abt_,   m_Empty));
			m_Taking.AddTransition(new HandTransition(  m_Taking.m_Show, _abt_,   m_Equipped));

		m_FSM.AddTransition(new HandTransition( m_Equipped, __M__,  m_MovingTo, NULL, new HandSelectAnimationOfMoveFromHandsEvent(GetManOwner())));
		m_FSM.AddTransition(new HandTransition( m_MovingTo, _fin_,  m_Empty   , null, null));
			m_MovingTo.AddTransition(new HandTransition(  m_MovingTo.m_Hide, _abt_,   m_Equipped));
			m_MovingTo.AddTransition(new HandTransition(  m_MovingTo.m_Show, _abt_,   m_Empty));

		m_FSM.AddTransition(new HandTransition( m_Equipped, __W__,  m_Swapping, NULL, new HandSelectAnimationOfSwapInHandsEvent(GetManOwner())));
		m_FSM.AddTransition(new HandTransition( m_Swapping, _fin_,  m_Equipped, null, null));
		m_FSM.AddTransition(new HandTransition( m_Swapping, _abt_,  m_Equipped, null, null));

		m_FSM.AddTransition(new HandTransition( m_Equipped, __F__, m_FSwapping, NULL, new HandSelectAnimationOfForceSwapInHandsEvent(GetManOwner())));
		m_FSM.AddTransition(new HandTransition(m_FSwapping, _fin_,  m_Equipped, null, null));
		m_FSM.AddTransition(new HandTransition(m_FSwapping, _abt_,  m_Equipped, null, null));

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
			if (m_PostedHandEvent == NULL)
			{
				m_PostedHandEvent = e;
				hndDebugPrint("[hndfsm] Posted event m_PostedHandEvent=" + m_PostedHandEvent.ToString());
			}
			else
				Error("[hndfsm] warning - pending hand event already posted, curr_event=" + m_PostedHandEvent.ToString() + " new_event=" + e.ToString());
		}
	}
	
	/**@fn	PostWeaponEvent
	 * @brief	deferred weapon's fsm handling of events
	 * @NOTE: "post" stores the event for later use when ::CommandHandler is being run
	 **/
	void PostWeaponEvent (WeaponEventBase e)
	{
		if (m_PostedEvent == NULL)
		{
			m_PostedEvent = e;
			wpnDebugPrint("[wpnfsm] Posted event m_PostedEvent=" + m_PostedEvent.ToString());
		}
		else
			Error("[wpnfsm] warning - pending event already posted, curr_event=" + m_PostedEvent.ToString() + " new_event=" + e.ToString());
	}

	void HandleWeaponEvents (float dt, out bool exitIronSights)
	{
		HumanCommandWeapons hcw = GetDayZPlayerOwner().GetCommandModifier_Weapons();

		Weapon_Base weapon;
		Class.CastTo(weapon, GetEntityInHands());

		if (hcw && weapon && weapon.CanProcessWeaponEvents())
		{
			weapon.GetCurrentState().OnUpdate(dt);

			//wpnDebugPrint("[wpnfsm] HCW: playing A=" + typename.EnumToString(WeaponActions, hcw.GetRunningAction()) + " AT=" + WeaponActionTypeToString(hcw.GetRunningAction(), hcw.GetRunningActionType()) + " fini=" + hcw.IsActionFinished());

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
					wpnDebugPrint("[wpnfsm] HandleWeapons: event arrived " + typename.EnumToString(WeaponEvents, weaponEventId) + "(" + weaponEventId + ")  fsm_ev=" + anim_event.ToString());
					if (anim_event != NULL)
					{
						weapon.ProcessWeaponEvent(anim_event);
					}
				}

				if (hcw.IsActionFinished())
				{
					if (weapon.IsWaitingForActionFinish())
					{
						wpnDebugPrint("[wpnfsm] Weapon event: finished! notifying waiting state=" + weapon.GetCurrentState());
						weapon.ProcessWeaponEvent(new WeaponEventHumanCommandActionFinished(GetDayZPlayerOwner()));
					}
					else
					{
						wpnDebugPrint("[wpnfsm] Weapon event: ABORT! notifying running state=" + weapon.GetCurrentState());
						weapon.ProcessWeaponAbortEvent(new WeaponEventHumanCommandActionAborted(GetDayZPlayerOwner()));
					}
				}
			}

			if (m_PostedEvent)
			{
				wpnDebugPrint("[wpnfsm] Weapon event: deferred " + m_PostedEvent);
				weapon.ProcessWeaponEvent(m_PostedEvent);
				exitIronSights = true;
				fsmDebugSpam("[wpnfsm] Weapon event: resetting deferred event" + m_PostedEvent);
				m_PostedEvent = NULL;
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

			//hndDebugSpam("[hndfsm] HCW: playing A=" + typename.EnumToString(WeaponActions, hcw.GetRunningAction()) + " AT=" + WeaponActionTypeToString(hcw.GetRunningAction(), hcw.GetRunningActionType()) + " fini=" + hcw.IsActionFinished());

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
		
		if (m_PostedHandEvent)
		{
			hndDebugSpam("[hndfsm] Hand event: deferred " + m_PostedHandEvent);

			HandEventBase hndEvent = m_PostedHandEvent; // make a copy for processing and release post
			hndDebugSpam("[hndfsm] Hand event: deferred event reset to null.");
			m_PostedHandEvent = NULL;

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
	
	bool OnInputUserDataFromRemote (ParamsReadContext ctx)
	{
		syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " remote handling InputUserData packet from server");
		return HandleInputData(false, true, ctx);
	}

	override void OnServerInventoryCommand (ParamsReadContext ctx)
	{
		syncDebugPrint("[syncinv] " + Object.GetDebugName(GetDayZPlayerOwner()) + " DZPInventory command from server");
		HandleInputData(true, true, ctx);
	}

	/**@fn			HandleInputData
	 * @brief		real processing of the input data
	 **/
	bool HandleInputData (bool handling_juncture, bool remote, ParamsReadContext ctx)
	{
		int type = -1;
		if (!ctx.Read(type))
			return false;

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
					Error("[syncinv] HandleInputData remote input (cmd=SYNC_MOVE) dropped, item not in bubble! src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
					break; // not in bubble
				}

				if (false == GameInventory.CheckRequestSrc(GetManOwner(), src, GameInventory.c_MaxItemDistanceRadius))
				{
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " failed src check with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src=" + InventoryLocation.DumpToStringNullSafe(src));
					return false; // stale packet
				}
				
				if (false == GameInventory.CheckMoveToDstRequest(GetManOwner(), src, dst, GameInventory.c_MaxItemDistanceRadius))
				{
					Error("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " is cheating with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
					return false; // cheater
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

				LocationSyncMoveEntity(src, dst);
				break;
			}

			case InventoryCommandType.HAND_EVENT:
			{
				HandEventBase e = HandEventBase.CreateHandEventFromContext(ctx);

				if (remote && !e.GetSrcEntity())
				{
					Error("[syncinv] HandleInputData remote input (cmd=HAND_EVENT) dropped, item not in bubble");
					break; // not in bubble
				}

				if (false == e.CheckRequestSrc())
				{
					return false; // stale packet
				}

				if (false == e.CheckRequest())
				{
					Error("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " STS=" + GetDayZPlayerOwner().GetSimulationTimeStamp() + " is cheating with cmd=" + typename.EnumToString(InventoryCommandType, type) + " event=" + e.DumpToString());
					return false; // cheater
				}

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

				e.m_Player.GetHumanInventory().PostHandEvent(e);
				break;
			}

			case InventoryCommandType.SWAP:
			{
				InventoryLocation src1 = new InventoryLocation;
				InventoryLocation src2 = new InventoryLocation;
				InventoryLocation dst1 = new InventoryLocation;
				InventoryLocation dst2 = new InventoryLocation;
				src1.ReadFromContext(ctx);
				src2.ReadFromContext(ctx);
				dst1.ReadFromContext(ctx);
				dst2.ReadFromContext(ctx);
				
				if (remote && (!src1.GetItem() || !src2.GetItem()))
				{
					Error("[syncinv] HandleInputData remote input (cmd=SWAP) dropped, item not in bubble");
					break; // not in bubble
				}
				
				if (false == GameInventory.CheckRequestSrc(GetManOwner(), src1, GameInventory.c_MaxItemDistanceRadius))
				{
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " failed src1 check with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src1=" + InventoryLocation.DumpToStringNullSafe(src1));
					return false; // stale packet
				}
				if (false == GameInventory.CheckRequestSrc(GetManOwner(), src2, GameInventory.c_MaxItemDistanceRadius))
				{
					syncDebugPrint("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " failed src2 check with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2));
					return false; // stale packet
				}

				if (false == GameInventory.CheckSwapItemsRequest(GetManOwner(), src1, src2, dst1, dst2, GameInventory.c_MaxItemDistanceRadius))
				{
					Error("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " is cheating with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2) +  " dst1=" + InventoryLocation.DumpToStringNullSafe(dst1) + " dst2=" + InventoryLocation.DumpToStringNullSafe(dst2));
					return false; // cheater
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

					LocationSwap(src1, src2, dst1, dst2);
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

				if (false == GameInventory.CheckDropRequest(GetManOwner(), src, GameInventory.c_MaxItemDistanceRadius))
				{
					Error("[cheat] HandleInputData man=" + Object.GetDebugName(GetManOwner()) + " is cheating with cmd=" + typename.EnumToString(InventoryCommandType, type) + " src=" + InventoryLocation.DumpToStringNullSafe(src));
					return false; // cheater
				}

				GetGame().ObjectDelete(src.GetItem());
				break;
			}
		}

		StoreInputForRemotes(handling_juncture, remote, ctx);

		return true;
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
		switch (mode)
		{
			case InventoryMode.SERVER:
			{				
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
			}
		}
		return super.TakeToDst(mode, src, dst);
	}

	override void HandEvent (InventoryMode mode, HandEventBase e)
	{
		switch (mode)
		{
			case InventoryMode.SERVER:
			{
				hndDebugPrint("[inv] DZPI::HandEvent(" + typename.EnumToString(InventoryMode, mode) + ")");
				if (!e.IsServerSideOnly())
                	SendServerHandEventViaJuncture(GetDayZPlayerOwner(), e);
                PostHandEvent(e);
                return;
			}
		}

		super.HandEvent(mode, e);
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

	/**@fn			OnEventFromRemoteWeapon
	 * @brief		reaction of remote weapon to (common user/anim/...) event sent from server
	 **/
	bool OnEventFromRemoteWeapon (ParamsReadContext ctx)
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
		
					fsmDebugSpam("[wpnfsm] recv event from remote: created event=" + e);
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
				Error("OnEventFromRemoteWeapon - entity in hands, but not weapon. item=" + GetEntityInHands());
		}
		else
			Error("OnEventFromRemoteWeapon - no entity in hands");
		return true;
	}


	/**@fn			OnHandEventFromRemote
	 * @brief		reaction of remote weapon to (common user/anim/...) event sent from server
	 **/
	bool OnHandEventFromRemote (ParamsReadContext ctx)
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
	
	override void OnHandsStateChanged (HandStateBase src, HandStateBase dst)
	{
#ifdef BOT
		PlayerBase p = PlayerBase.Cast(GetDayZPlayerOwner());
		if (p)
		{
			botDebugPrint("[bot] hand fsm changed state src=" + src + " ---> dst=" + dst);
			p.m_Bot.ProcessEvent(new BotEventOnItemInHandsChanged(p));
		}
#endif
	}
	
	bool IsProcessing()
	{
		return !m_FSM.GetCurrentState().IsIdle();
	}
};

