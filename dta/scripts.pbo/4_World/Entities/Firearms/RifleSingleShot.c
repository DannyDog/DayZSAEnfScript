enum RSSAnimState
{
	DEFAULT 			= 0, 	///< default weapon state, closed and discharged
};

enum RSSStableStateID
{
	UNKNOWN				=  0,
	Empty				=  1,
	Fireout				=  2,
	Loaded				=  3,
	Jammed				=  4,
}

class RSSEmpty extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] { Empty E"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] } Empty E"); }
	override int GetCurrentStateID () { return RSSStableStateID.Empty; }
	override bool HasBullet () { return false; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return false; }
};
class RSSFireout extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] { Fireout F"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] } Fireout F"); }
	override int GetCurrentStateID () { return RSSStableStateID.Fireout; }
	override bool HasBullet () { return false; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return false; }
};
class RSSLoaded extends WeaponStableState
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] { Loaded C"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] } Loaded C"); }
	override int GetCurrentStateID () { return RSSStableStateID.Loaded; }
	override bool HasBullet () { return true; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return false; }
};
class RSSJammed extends WeaponStateJammed
{
	override void OnEntry (WeaponEventBase e) { wpnPrint("[wpnfsm] { Jammed J"); super.OnEntry(e); }
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnfsm] } Jammed J"); }
	override int GetCurrentStateID () { return RSSStableStateID.Jammed; }
	override bool HasBullet () { return true; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return true; }
	override bool IsBoltOpen () { return true; }
};

/**@class		Izh18_Base
 * @brief		base for Izh18
 * @NOTE		name copies config base class
 **/
class RifleSingleShot_Base extends Rifle_Base
{
	void RifleSingleShot_Base ()
	{
	}
	
	override void InitStateMachine()
	{
		// setup abilities
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_ONEBULLET_CLOSED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_START));
		m_abilities.Insert(new AbilityRecord(WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_END));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_COCKED));

		// setup state machine
		// basic weapon states
		WeaponStateBase E = new RSSEmpty(this, NULL, RSSAnimState.DEFAULT);
		WeaponStateBase F = new RSSFireout(this, NULL, RSSAnimState.DEFAULT);
		WeaponStateBase J = new RSSJammed(this, NULL, RSSAnimState.DEFAULT);
		WeaponStateBase L = new RSSLoaded(this, NULL, RSSAnimState.DEFAULT);
		// unstable (intermediate) states
		WeaponStateBase Mech_F = new WeaponCharging(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED);
		WeaponStateBase Mech_L = new WeaponEjectBullet(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED);
		
		WeaponStateBase Chamber_E = new WeaponChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_ONEBULLET_CLOSED);
		WeaponStateBase Chamber_F = new RifleChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_ONEBULLET_CLOSED);
		WeaponStateBase Chamber_L = new RifleReChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_ONEBULLET_CLOSED);
		
		WeaponStateBase Trigger_E = new WeaponDryFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_COCKED);
		WeaponStateBase Trigger_L = new WeaponFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL);
		WeaponStateBase Trigger_F = new WeaponDryFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_COCKED);

		WeaponStateBase Trigger_LJ = new WeaponFireToJam(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_JAM);
		
		WeaponStateBase Unjam_J = new WeaponUnjamming(this, NULL, WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_START);

		// events
		WeaponEventBase __M__ = new WeaponEventMechanism;
		WeaponEventBase __T__ = new WeaponEventTrigger;
		WeaponEventBase __TJ_ = new WeaponEventTriggerToJam;
		WeaponEventBase __L__ = new WeaponEventLoad1Bullet;
		WeaponEventBase __U__ = new WeaponEventUnjam;
		WeaponEventBase _fin_ = new WeaponEventHumanCommandActionFinished;
		WeaponEventBase _abt_ = new WeaponEventHumanCommandActionAborted;
		WeaponEventBase _dto_ = new WeaponEventDryFireTimeout;

		m_fsm = new WeaponFSM();
		// charging
		m_fsm.AddTransition(new WeaponTransition(E		, __M__,	Mech_F));
		m_fsm.AddTransition(new WeaponTransition(F		, __M__,	Mech_F));
		m_fsm.AddTransition(new WeaponTransition(Mech_F	, _fin_,	E));
		m_fsm.AddTransition(new WeaponTransition(Mech_F	, _abt_,	F, NULL, new WeaponGuardChamberFiredOut(this)));
		m_fsm.AddTransition(new WeaponTransition(Mech_F	, _abt_,	E));
		
		// eject good cartridge
		m_fsm.AddTransition(new WeaponTransition(L		, __M__,	Mech_L));
		m_fsm.AddTransition(new WeaponTransition(Mech_L	, _fin_,	E));
		m_fsm.AddTransition(new WeaponTransition(Mech_L	, _abt_,	E, NULL, new WeaponGuardChamberEmpty(this)));
		m_fsm.AddTransition(new WeaponTransition(Mech_L	, _abt_,	L));

		// load cartridge
		// option 1: talking to submachine
		/*m_fsm.AddTransition(new WeaponTransition(E  , __L__,   Chamber_E));
		m_fsm.AddTransition(new WeaponTransition(Chamber_E  , _fin_,   L));
		m_fsm.AddTransition(new WeaponTransition(Chamber_E  , _abt_,   E, NULL, new WeaponGuardChamberEmpty(this)));
		m_fsm.AddTransition(new WeaponTransition(Chamber_E  , _abt_,   L));*/

		m_fsm.AddTransition(new WeaponTransition(E			, __L__,	Chamber_F));
		m_fsm.AddTransition(new WeaponTransition(F			, __L__,	Chamber_F));
		m_fsm.AddTransition(new WeaponTransition(Chamber_F	, _fin_,	L));
		m_fsm.AddTransition(new WeaponTransition(Chamber_F	, _abt_,	F, NULL, new WeaponGuardChamberFiredOut(this)));
		m_fsm.AddTransition(new WeaponTransition(Chamber_F	, _abt_,	E, NULL, new WeaponGuardChamberEmpty(this)));
		m_fsm.AddTransition(new WeaponTransition(Chamber_F	, _abt_,	L));

		// fire
		m_fsm.AddTransition(new WeaponTransition(E  		, __T__,	Trigger_E)); // fire cocked
		m_fsm.AddTransition(new WeaponTransition(Trigger_E 	, _fin_,	E));
		m_fsm.AddTransition(new WeaponTransition(Trigger_E 	, _dto_,	E));
		m_fsm.AddTransition(new WeaponTransition(Trigger_E 	, _abt_,	E));
		
		m_fsm.AddTransition(new WeaponTransition(F  		, __T__,	Trigger_F)); // fire uncocked
		m_fsm.AddTransition(new WeaponTransition(Trigger_F	, _fin_,	F));
		m_fsm.AddTransition(new WeaponTransition(Trigger_F	, _dto_,	F));
		m_fsm.AddTransition(new WeaponTransition(Trigger_F	, _abt_,	F));
		
		m_fsm.AddTransition(new WeaponTransition(L			, __T__,	Trigger_L)); // a) fire if not jammed
		m_fsm.AddTransition(new WeaponTransition(Trigger_L	, _fin_,	F));
		m_fsm.AddTransition(new WeaponTransition(Trigger_L	, _abt_,	F));
		
		m_fsm.AddTransition(new WeaponTransition(L			, __TJ_,	Trigger_LJ)); // a) fire if not jammed
		m_fsm.AddTransition(new WeaponTransition(Trigger_LJ	, _fin_,	J));
		m_fsm.AddTransition(new WeaponTransition(Trigger_LJ	, _abt_,	J));
		
		
		

		// unjam
		m_fsm.AddTransition(new WeaponTransition(J			, __U__,	Unjam_J));
		m_fsm.AddTransition(new WeaponTransition(Unjam_J	, _fin_,	J, NULL, new WeaponGuardJammed(this)));
		m_fsm.AddTransition(new WeaponTransition(Unjam_J	, _fin_,	E));

		// initial state setup
		bool empty = true;
		bool discharged = false; // @TODO:
		WeaponStateBase init_state = E;
		if (empty)
		{
			if (!discharged)
				init_state = E;
		}
		else
		{
			init_state = L; // can init state == load/jammed?
		}
		m_fsm.SetInitialState(init_state);

		SelectionBulletHide();

		m_fsm.Start();
	}
	
	override bool CanChamberBullet (int muzzleIndex, Magazine mag)
	{
		return CanChamberFromMag(muzzleIndex, mag);
	}

};
