enum LZH43AnimState
{
	DEFAULT 			= 0, 	///< default weapon state, closed and discharged
};

enum DoubleBarrelShotgunStableStateID
{
	UNKNOWN				=  0,
	LoadedLoaded		=  1,
	LoadedEmpty			=  2,
	FireoutLoaded		=  3,
	FireoutFireout		=  4,
	FireoutEmpty		=  5,
	EmptyEmpty			=  6,
}


class DoubleBarrelShotgunLoadedLoaded extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] { LoadedLoaded L_L"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] } LoadedLoaded L_L"); }
	override int GetCurrentStateID () { return DoubleBarrelShotgunStableStateID.LoadedLoaded; }
	override bool HasBullet () { return false; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return false; }
};
class DoubleBarrelShotgunLoadedEmpty extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] { LoadedEmpty L_E"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] } LoadedEmpty L_E"); }
	override int GetCurrentStateID () { return DoubleBarrelShotgunStableStateID.LoadedEmpty; }
	override bool HasBullet () { return false; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return false; }
};
class DoubleBarrelShotgunFireoutLoaded extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] { FireoutLoaded F_L"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] } FireoutLoaded F_L"); }
	override int GetCurrentStateID () { return DoubleBarrelShotgunStableStateID.FireoutLoaded; }
	override bool HasBullet () { return true; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return false; }
};
class DoubleBarrelShotgunFireoutFireout extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] { FireoutFireout F_F"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] } FireoutFireout F_F"); }
	override int GetCurrentStateID () { return DoubleBarrelShotgunStableStateID.FireoutFireout; }
	override bool HasBullet () { return true; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return true; }
};

class DoubleBarrelShotgunFireoutEmpty extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] { FireoutEmpty F_E"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] } FireoutEmpty F_E"); }
	override int GetCurrentStateID () { return DoubleBarrelShotgunStableStateID.FireoutEmpty; }
	override bool HasBullet () { return true; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return true; }
};

class DoubleBarrelShotgunEmptyEmpty extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] { EmptyEmpty E_E"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] } EmptyEmpty E_E"); }
	override int GetCurrentStateID () { return DoubleBarrelShotgunStableStateID.EmptyEmpty; }
	override bool HasBullet () { return true; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return true; }
};



class Izh43Shotgun_Base : Rifle_Base
{
	ref WeaponStateBase L_L;
	ref WeaponStateBase L_E;
	ref WeaponStateBase F_L;
	ref WeaponStateBase F_F;
	ref WeaponStateBase F_E;
	ref WeaponStateBase E_E;
	
	
	override void InitStateMachine ()
	{
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_DOUBLE_1));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_DOUBLE_2));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_DOUBLE_3));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_DOUBLE_4));
		// setup abilities
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_START));
		m_abilities.Insert(new AbilityRecord(WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_END));
	
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_DRY));
		

	
		// basic weapon states
		L_L = new DoubleBarrelShotgunLoadedLoaded(this, NULL, LZH43AnimState.DEFAULT);
		L_E = new DoubleBarrelShotgunLoadedEmpty(this, NULL, LZH43AnimState.DEFAULT);
		F_L = new DoubleBarrelShotgunFireoutLoaded(this, NULL, LZH43AnimState.DEFAULT);
		F_F = new DoubleBarrelShotgunFireoutFireout(this, NULL, LZH43AnimState.DEFAULT);
		F_E = new DoubleBarrelShotgunFireoutEmpty(this, NULL, LZH43AnimState.DEFAULT);
		E_E = new DoubleBarrelShotgunEmptyEmpty(this, NULL, LZH43AnimState.DEFAULT);
	
		
		WeaponStateBase		Mech = new WeaponCharging(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED);
		/*WeaponStateBase		Mech_F = new WeaponCharging(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED);
		WeaponStateBase		Mech_L = new WeaponCharging(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED);*/

		LoopedChambering 	Chamber_E = new LoopedChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		LoopedChambering 	Chamber_F = new LoopedChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED_KEEP, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		LoopedChambering 	Chamber_L = new LoopedChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		
		WeaponStateBase		Unjam_J = new WeaponUnjamming(this, NULL, WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_START);
		
		WeaponStateBase		Trigger_E = new WeaponDryFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_DRY);
		WeaponStateBase		Trigger_F = new WeaponDryFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_DRY);
		WeaponStateBase		Trigger_L = new WeaponFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL);
		WeaponStateBase		Trigger_J = new WeaponDryFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_DRY);
		// extend Rifle_Base fsm
		/*LoopedChambering lch = new LoopedChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		LoopedChambering psh = new LoopedChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED_KEEP	, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		LoopedChambering lch2 = new LoopedChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE,true);
		LoopedChambering psh2 = new LoopedChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED_KEEP	, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE,true);
		*/
		
		WeaponEventBase _fin_ = new WeaponEventHumanCommandActionFinished;
		WeaponEventBase __L__ = new WeaponEventLoad1Bullet;
		WeaponEventBase __T__ = new WeaponEventTrigger;
		WeaponEventBase __U__ = new WeaponEventUnjam;
		WeaponEventBase	__M__ = new WeaponEventMechanism;
		WeaponEventBase _abt_ = new WeaponEventHumanCommandActionAborted;
		WeaponEventBase _rto_ = new WeaponEventReloadTimeout;
		WeaponEventBase _dto_ = new WeaponEventDryFireTimeout;

		m_fsm = new WeaponFSM();
		
		m_fsm.AddTransition(new WeaponTransition( E_E,		__M__,  Mech));
		m_fsm.AddTransition(new WeaponTransition( L_L,		__M__,  Mech));
		m_fsm.AddTransition(new WeaponTransition( L_E,		__M__,  Mech));
		m_fsm.AddTransition(new WeaponTransition( F_L,		__M__,  Mech));
		m_fsm.AddTransition(new WeaponTransition( F_F,		__M__,  Mech));
		m_fsm.AddTransition(new WeaponTransition( F_E,		__M__,  Mech));
		m_fsm.AddTransition(new WeaponTransition( Mech,		_fin_,  E_E));
		
		m_fsm.AddTransition(new WeaponTransition( Mech,		_abt_,  L_L, NULL, new GuardAnd( new WeaponGuardRightChamberLoaded(this), new WeaponGuardLeftChamberLoaded(this))));
		m_fsm.AddTransition(new WeaponTransition( Mech,		_abt_,  L_E, NULL, new GuardAnd( new WeaponGuardRightChamberLoaded(this), new WeaponGuardLeftChamberEmpty(this))));
		m_fsm.AddTransition(new WeaponTransition( Mech,		_abt_,  F_L, NULL, new GuardAnd( new WeaponGuardRightChamberFireout(this), new WeaponGuardLeftChamberLoaded(this))));
		m_fsm.AddTransition(new WeaponTransition( Mech,		_abt_,  F_F, NULL, new GuardAnd( new WeaponGuardRightChamberFireout(this), new WeaponGuardLeftChamberFireout(this))));
		m_fsm.AddTransition(new WeaponTransition( Mech,		_abt_,  F_E, NULL, new GuardAnd( new WeaponGuardRightChamberFireout(this), new WeaponGuardLeftChamberEmpty(this))));
		m_fsm.AddTransition(new WeaponTransition( Mech,		_abt_,  E_E));
		
		
		m_fsm.SetInitialState(E_E);

		SelectionBulletHide();
		//SelectionMagazineHide();

		m_fsm.Start();
	
	}
	//Weapon
	//L_L
	//L_E	
	//F_E
	//F_L
	//F_F
	//E_E
};

enum LZH43MuzzlesIndex
{
	LEFT 			= 0,
	RIGHT			= 1,
};

class WeaponGuardLeftChamberEmpty extends WeaponGuardBase
{
	protected Weapon_Base m_weapon;
	void WeaponGuardLeftChamberEmpty (Weapon_Base w = NULL) { m_weapon = w; }

	override bool GuardCondition (WeaponEventBase e)
	{
		if (m_weapon.IsChamberEmpty(LZH43MuzzlesIndex.LEFT))
		{
			wpnDebugPrint("[wpnfsm] guard - left chamber empty");
			return true;
		}
		wpnDebugPrint("[wpnfsm] guard - left chamber not empty");
		return false;
	}
};

class WeaponGuardRightChamberEmpty extends WeaponGuardBase
{
	protected Weapon_Base m_weapon;
	void WeaponGuardRightChamberEmpty (Weapon_Base w = NULL) { m_weapon = w; }

	override bool GuardCondition (WeaponEventBase e)
	{
		if (m_weapon.IsChamberEmpty(LZH43MuzzlesIndex.RIGHT))
		{
			wpnDebugPrint("[wpnfsm] guard - right chamber empty");
			return true;
		}
		wpnDebugPrint("[wpnfsm] guard - right chamber not empty");
		return false;
	}
};

class WeaponGuardLeftChamberFireout extends WeaponGuardBase
{
	protected Weapon_Base m_weapon;
	void WeaponGuardLeftChamberFireout (Weapon_Base w = NULL) { m_weapon = w; }

	override bool GuardCondition (WeaponEventBase e)
	{
		if (m_weapon.IsChamberFiredOut(LZH43MuzzlesIndex.LEFT))
		{
			wpnDebugPrint("[wpnfsm] guard - left chamber fireout");
			return true;
		}
		wpnDebugPrint("[wpnfsm] guard - left chamber not fireout");
		return false;
	}
};

class WeaponGuardRightChamberFireout extends WeaponGuardBase
{
	protected Weapon_Base m_weapon;
	void WeaponGuardRightChamberFireout (Weapon_Base w = NULL) { m_weapon = w; }

	override bool GuardCondition (WeaponEventBase e)
	{
		if (m_weapon.IsChamberFiredOut(LZH43MuzzlesIndex.RIGHT))
		{
			wpnDebugPrint("[wpnfsm] guard - right chamber fireout");
			return true;
		}
		wpnDebugPrint("[wpnfsm] guard - right chamber not fireout");
		return false;
	}
};

class WeaponGuardLeftChamberLoaded extends WeaponGuardBase
{
	protected Weapon_Base m_weapon;
	void WeaponGuardLeftChamberLoaded (Weapon_Base w = NULL) { m_weapon = w; }

	override bool GuardCondition (WeaponEventBase e)
	{
		if (m_weapon.IsChamberEjectable(LZH43MuzzlesIndex.LEFT))
		{
			wpnDebugPrint("[wpnfsm] guard - left chamber loaded");
			return true;
		}
		wpnDebugPrint("[wpnfsm] guard - left chamber not loaded");
		return false;
	}
};

class WeaponGuardRightChamberLoaded extends WeaponGuardBase
{
	protected Weapon_Base m_weapon;
	void WeaponGuardRightChamberLoaded (Weapon_Base w = NULL) { m_weapon = w; }

	override bool GuardCondition (WeaponEventBase e)
	{
		if (m_weapon.IsChamberEjectable(LZH43MuzzlesIndex.RIGHT))
		{
			wpnDebugPrint("[wpnfsm] guard - right chamber loaded");
			return true;
		}
		wpnDebugPrint("[wpnfsm] guard - right chamber not loaded");
		return false;
	}
};
//--------------------------------------
//--------------------------------------
//--------------------------------------
/*
class WeaponEjectRightCasing extends WeaponStateBase
{
	void WeaponEjectRightCasing (Weapon_Base w = NULL, WeaponStateBase parent = NULL) { }

	override void OnEntry (WeaponEventBase e)
	{
		super.OnEntry(e);

		wpnDebugPrint("[wpnfsm] ejected fired out casing");
		int mi = m_weapon.GetCurrentMuzzle();
		m_weapon.EjectCasing(LZH43MuzzlesIndex.RIGHT);
		m_weapon.SelectionBulletHide();
	}
};

class WeaponEjectRightBullet_Cartridge extends WeaponStateBase
{
	Magazine m_dstMagazine; /// destination of the cartridge

	override void OnEntry (WeaponEventBase e)
	{
		super.OnEntry(e);

		DayZPlayer p = e.m_player;
		int mi = m_weapon.GetCurrentMuzzle();

		ejectBulletAndStoreInMagazine(m_weapon, mi, m_dstMagazine, p); // MP-safe
	}

	override void OnAbort (WeaponEventBase e)
	{
		m_dstMagazine = NULL;
		super.OnAbort(e);
	}

	override void OnExit (WeaponEventBase e)
	{
		m_dstMagazine = NULL;
		super.OnExit(e);
	}

	override bool SaveCurrentFSMState (ParamsWriteContext ctx)
	{
		if (!super.SaveCurrentFSMState(ctx))
			return false;

		if (!ctx.Write(m_dstMagazine))
		{
			Error("[wpnfsm] WeaponEjectBullet_Cartridge.SaveCurrentFSMState: cannot write m_dstMagazine for weapon=" + m_weapon);
			return false;
		}
		return true;
	}

	override bool LoadCurrentFSMState (ParamsReadContext ctx)
	{
		if (!super.LoadCurrentFSMState(ctx))
			return false;

		if (!ctx.Read(m_dstMagazine))
		{
			Error("[wpnfsm] WeaponEjectBullet_Cartridge.LoadCurrentFSMState: cannot read m_dstMagazine for weapon=" + m_weapon);
			return false;
		}
		return true;
	}

};
*/