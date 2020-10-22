/**@class		WeaponFSM
 * @brief		weapon finite state machine
 **/
class WeaponFSM extends HFSMBase<WeaponStateBase, WeaponEventBase, WeaponActionBase, WeaponGuardBase>
{
	protected int m_NextStateId = 0; /// counter for InternalID: each state in a fsm is assigned an unique number
	protected ref array<WeaponStateBase> m_UniqueStates = new array<WeaponStateBase>; /// unique list of states in this machine (automation of save/load)

	protected void SetInternalID(WeaponStateBase state)
	{
		if (state && state.GetInternalStateID() == -1)
		{
			state.SetInternalStateID(m_NextStateId);

			//wpnDebugSpam("[wpnfsm] " + Object.GetDebugName(m_weapon) + " unique state=" + state + " has id=" + m_NextStateId);
			m_UniqueStates.Insert(state);
			++m_NextStateId;
		}
	}

	/**@fn		AddTransition
	 * @brief	adds transition into transition table
	 * As a side effect registers the state(s) into m_UniqueStates
	 **/
	override void AddTransition(FSMTransition<WeaponStateBase, WeaponEventBase, WeaponActionBase, WeaponGuardBase> t)
	{
		super.AddTransition(t);

		SetInternalID(t.m_srcState);
		SetInternalID(t.m_dstState);
	}
	
	override protected ProcessEventResult ProcessLocalTransition(FSMTransition<WeaponStateBase, WeaponEventBase, WeaponActionBase, WeaponGuardBase> t, WeaponEventBase e)
	{
		ProcessEventResult res = super.ProcessLocalTransition(t, e);
		ValidateAndRepair();
		return res;
	}
	
	override WeaponStateBase ProcessAbortEvent(WeaponEventBase e, out ProcessEventResult result)
	{
		WeaponStateBase res = super.ProcessAbortEvent(e, result);
		ValidateAndRepair();
		return res;
	}
	
	override protected ProcessEventResult ProcessAbortTransition(FSMTransition<WeaponStateBase, WeaponEventBase, WeaponActionBase, WeaponGuardBase> t, WeaponEventBase e)
	{
		ProcessEventResult res = super.ProcessAbortTransition(t, e);
		ValidateAndRepair();
		return res;
	}

	/**@fn		FindStateForInternalID
	 * @brief	retrieve base state that matches given internal id
	 * @param[in]	id	the id stored in database during save
	 **/
	WeaponStateBase FindStateForInternalID(int id)
	{
		int state_count = m_UniqueStates.Count();
		for (int idx = 0; idx < state_count; ++idx)
		{
			int state_id = m_UniqueStates.Get(idx).GetInternalStateID();
			if (state_id == id)
				return m_UniqueStates.Get(idx);
		}
		return null;
	}

	/**@fn		FindStableStateForID
	 * @brief	load from database - reverse lookup for state from saved id
	 * @param[in]	id	the id stored in database during save
	 **/
	WeaponStableState FindStableStateForID(int id)
	{
		if (id == 0)
			return null;

		int count = m_Transitions.Count();
		for (int i = 0; i < count; ++i)
		{
			WeaponTransition trans = m_Transitions.Get(i);
			WeaponStableState state = WeaponStableState.Cast(trans.m_srcState);
			if (state && id == state.GetCurrentStateID())
				return state;
		}
		return null;
	}

	protected bool LoadAndSetCurrentFSMState(ParamsReadContext ctx, int version)
	{
		int curr_state_id = -1;
		if (!ctx.Read(curr_state_id))
		{
			Error("[wpnfsm] LoadCurrentFSMState - cannot read current state");
			return false;
		}

		WeaponStateBase state = FindStateForInternalID(curr_state_id);
		if (state)
		{
			Terminate();
			wpnDebugPrint("[wpnfsm] synced current state=" + state + " id=" + curr_state_id);	
			m_State = state;	
			Start(null, true);
			return true;
		}
		else
			Error("[wpnfsm] LoadCurrentFSMState - cannot find state for id=" + curr_state_id);
		return false;

	}

	/**@fn		LoadCurrentFSMState
	 * @brief	load current state of fsm
	 **/
	bool LoadCurrentFSMState(ParamsReadContext ctx, int version)
	{
		if (LoadAndSetCurrentFSMState(ctx, version))
		{
			bool res = m_State.LoadCurrentFSMState(ctx, version);
			wpnDebugSpam("[wpnfsm] LoadCurrentFSMState - loaded current state=" + GetCurrentState());
			return res;
		}
		return false;
	}
	
	bool LoadCurrentUnstableFSMState(ParamsWriteContext ctx, int version)
	{
		if (LoadAndSetCurrentFSMState(ctx, version))
		{
			// read all substates
			int state_count = m_UniqueStates.Count();
			for (int idx = 0; idx < state_count; ++idx)
			{
				wpnDebugSpam("[wpnfsm] LoadCurrentUnstableFSMState " + idx + "/" + state_count + " id=" + m_UniqueStates.Get(idx).GetInternalStateID() + " state=" + m_UniqueStates.Get(idx));
				if (!m_UniqueStates.Get(idx).LoadCurrentFSMState(ctx, version))
					Error("[wpnfsm] LoadCurrentUnstableFSMState - cannot load unique state " + idx + "/" + state_count + " with id=" + m_UniqueStates.Get(idx).GetInternalStateID() + " state=" + m_UniqueStates.Get(idx));
			}
			return true;
		}
		return false;
	}

	/**@fn		SaveCurrentFSMState
	 * @brief	save current state of fsm
	 **/
	bool SaveCurrentFSMState(ParamsWriteContext ctx)
	{
		WeaponStateBase state = GetCurrentState();
		int curr_state_id = state.GetInternalStateID();
		wpnDebugPrint("[wpnfsm] SaveCurrentFSMState - saving current state=" + GetCurrentState() + " id=" + curr_state_id);

		if (!ctx.Write(curr_state_id))
		{
			Error("[wpnfsm] SaveCurrentFSMState - cannot save curr_state_id=" + curr_state_id);
			return false;
		}

		// write only current state
		if (!state.SaveCurrentFSMState(ctx))
		{
			Error("[wpnfsm] SaveCurrentFSMState - cannot save currrent state=" +state);
			return false;
		}
		return true;
	}
	
	bool SaveCurrentUnstableFSMState(ParamsWriteContext ctx)
	{
		WeaponStateBase state = GetCurrentState();
		int curr_state_id = state.GetInternalStateID();
		wpnDebugPrint("[wpnfsm] SaveCurrentUnstableFSMState - saving current state=" + GetCurrentState() + " id=" + curr_state_id);
		
		if (!ctx.Write(curr_state_id))
		{
			Error("[wpnfsm] SaveCurrentFSMState - cannot save curr_state_id=" + curr_state_id);
			return false;
		}

		// write all substates
		int state_count = m_UniqueStates.Count();
		for (int idx = 0; idx < state_count; ++idx)
		{
			int state_id = m_UniqueStates.Get(idx).GetInternalStateID();
			if (state_id != -1)
			{
				wpnDebugSpam("[wpnfsm] SaveCurrentUnstableFSMState " + idx + "/" + state_count + " id=" + state_id + " name=" + m_UniqueStates.Get(idx));
				if (!m_UniqueStates.Get(idx).SaveCurrentFSMState(ctx))
					Error("SaveCurrentUnstableFSMState - cannot save unique state=" + m_UniqueStates.Get(idx) + " idx=" + idx + "/" + state_count + " with id=" + state_id);
			}
			else
				Error("[wpnfsm] SaveCurrentUnstableFSMState state=" + m_UniqueStates.Get(idx) + " with unassigned ID!");
		}
		return true;
	}
	
    /**@fn		ValidateAndRepair
	 * @brief	validate the state of the gun and repair if mismatch
	 **/
	void ValidateAndRepair()
	{
		Internal_ValidateAndRepair();
	}
	
	/**@fn		Internal_ValidateAndRepair
	 * @brief	validate the state of the gun and repair if mismatch
	 * @return	bool whether it performed reparing or not
	 **/
	protected bool Internal_ValidateAndRepair()
	{
		bool repaired = false;
		
		// Only repair stable states
		WeaponStableState state = WeaponStableState.Cast(m_State);				
		if (state && state.IsRepairEnabled())
		{		
			Weapon_Base weapon = state.m_weapon;
			if (weapon)
			{
				repaired |= ValidateAndRepairHelper(weapon,
						"MagazineRepair",
						state.HasMagazine(), ( weapon.GetMagazine(weapon.GetCurrentMuzzle()) != null ),
						new WeaponEventAttachMagazine, new WeaponEventDetachMagazine,
						state);
				
				repaired |= ValidateAndRepairHelper(weapon,
						"JammedRepair",
						state.IsJammed(), weapon.IsJammed(),
						new WeaponEventTriggerToJam, new WeaponEventUnjam,
						state);
				
				if (weapon.IsJammed())
					return repaired;
				
				// Sadly, multi muzzle and fired out bullets are a bit too tricky
				if (weapon.GetMuzzleCount() == 1)
				{
					repaired |= ValidateAndRepairHelper(weapon,
						"ChamberRepair",
						state.HasBullet(), weapon.IsChamberFull(weapon.GetCurrentMuzzle()),
						new WeaponEventLoad1Bullet, new WeaponEventMechanism,
						state);
				}
			}
		}

		return repaired;
	}
	
	protected bool ValidateAndRepairHelper(Weapon_Base weapon, string name, bool stateCondition, bool gunCondition, WeaponEventBase e1, WeaponEventBase e2, out WeaponStableState state)
	{	
		wpnDebugPrint("[wpnfsm] " + weapon.GetDebugName(weapon) + " ValidateAndRepair - " + name + " - " + m_State + " - state: " + stateCondition + " & weapon: " + gunCondition);
		
		if (stateCondition != gunCondition)
		{
			Error("[wpnfsm] ValidateAndRepair Attempting to repair: " + weapon.GetDebugName(weapon) + " - " + name + " - " + m_State + " - state: " + stateCondition + " != weapon: " + gunCondition);
			
			WeaponStableState repairedState = ValidateAndRepairStateFinder(gunCondition, e1, e2, state);
			
			if (repairedState)
			{
				Terminate();
				m_State = repairedState;
				Start(null, true);
				state = repairedState;
				weapon.SyncSelectionState(state.HasBullet(), state.HasMagazine());
				repairedState.SyncAnimState();
				wpnDebugPrint("[wpnfsm] " + weapon.GetDebugName(weapon) + " ValidateAndRepair - " + name + " - Result - " + m_State);
				return true;
			}
			else
				Error("[wpnfsm] " + weapon.GetDebugName(weapon) + " ValidateAndRepair FAILED - " + name + " - " + m_State + " - state: " + stateCondition + " != weapon: " + gunCondition);
		}
		
		return false;
	}
	
	protected WeaponStableState ValidateAndRepairStateFinder(bool condition, WeaponEventBase e1, WeaponEventBase e2, WeaponStableState state)
	{
		WeaponStateBase interState;
		if (condition)
			interState = FindTransitionState(state, e1);
		else
			interState = FindTransitionState(state, e2);
			
		return WeaponStableState.Cast(FindGuardedTransitionState(interState, new WeaponEventHumanCommandActionFinished));
	}
	
	/**@fn		OnStoreLoad
	 * @brief	load state of fsm
	 **/
	bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		int id = 0;
		ctx.Read(id);
		WeaponStableState state = FindStableStateForID(id);
		if (state)
		{
			Terminate();
			wpnDebugPrint("[wpnfsm] OnStoreLoad - loading current state=" + state + " id=" + id);	
			m_State = state;
			Start(null, true);
		}
		else
		{
			Print("[wpnfsm] Warning! OnStoreLoad - cannot load curent weapon state, id=" + id);
		}

		return true;
	}

	/**@fn		GetCurrentStateID
	 * @brief	tries to return identifier of current stable state
	 *
	 * if the weapon is in stable state, i.e. not reloading, firing, detaching, ... than
	 * the identifier of the stable state is used directly.
	 * otherwise if the weapon is in unstable state, than the function uses abort information
	 * to determine the closest stable state that is coherent with weapon's state.
	 *
	 * @return	integer id that will be stored to database
	 **/
	int GetCurrentStableStateID()
	{
		// 1) if current state is stable state then return ID directly
		WeaponStableState state = WeaponStableState.Cast(GetCurrentState());
		if (state)
			return state.GetCurrentStateID();

		// 2) otherwise find closest stable state (by looking on abort event)
		WeaponStateBase abort_dst = FindAbortDestinationState(new WeaponEventHumanCommandActionAborted(null));
		WeaponStableState closest_stable_state = WeaponStableState.Cast(abort_dst);
		
		if (closest_stable_state)
		{
			Print("[wpnfsm] Save occured in fsm transition! current state=" + GetCurrentState() + " closes stable state=" + closest_stable_state + " id=" + closest_stable_state.GetCurrentStateID());
			return closest_stable_state.GetCurrentStateID();
		}		

		Print("[wpnfsm] Warning! Save occured in fsm transition! GetCurrentStateID - cannot find closest weapon stable state.");
		return 0;
	}

	/**@fn		GetCurrentStateID
	 * @brief	return internal identifier of current state
	 **/
	int GetInternalStateID()
	{
		WeaponStateBase curr = GetCurrentState();
		int id = 0;
		if (curr)
			id = curr.GetInternalStateID();
		return id;
	}

	/**@fn		OnStoreSave
	 * @brief	save state of fsm
	 **/
	void OnStoreSave(ParamsWriteContext ctx)
	{
		int id = GetCurrentStableStateID();
		wpnDebugSpamALot("[wpnfsm] OnStoreSave - saving current state=" + GetCurrentState() + " id=" + id);
		ctx.Write(id);
	}

	/**@fn		RandomizeFSMState
	 * @brief	Engine callback - loot randomization of FSM's state. not intended to direct use.
	 **/
	void RandomizeFSMState(bool hasBullet, bool hasMagazine, bool isJammed)
	{
		array<WeaponStableState> candidates = new array<WeaponStableState>;
		int tc = m_Transitions.Count();
		for (int i = 0; i < tc; ++i)
		{
			WeaponTransition trans = m_Transitions.Get(i);
			WeaponStableState state = WeaponStableState.Cast(trans.m_srcState);
			if (state && state.HasBullet() == hasBullet && state.HasMagazine() == hasMagazine && state.IsJammed() == isJammed)
				candidates.Insert(state);
		}

		int cc = candidates.Count();
		if (cc)
		{
			int randomIndex = Math.RandomInt(0, cc);
			WeaponStableState selected = candidates.Get(randomIndex);
			Terminate();
			m_State = selected;
			if (!Internal_ValidateAndRepair())
				Start(null, true);
			wpnDebugPrint("[wpnfsm] RandomizeFSMState - randomized current state=" + m_State + " id=" + selected.GetCurrentStateID());
			selected.SyncAnimState();
		}
		else
		{
			wpnDebugPrint("[wpnfsm] RandomizeFSMState - warning - cannot randomize, no states available");
		}
	}
};

