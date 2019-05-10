// load x bullets
class LoopedChambering_EndLoop extends WeaponStartAction
{
};

class LoopedChambering_Wait4ShowBullet2 extends WeaponStateBase
{ 
};

class LoopedChambering extends WeaponStateBase
{
	WeaponActions m_action;
	int m_startActionType;
	int m_endActionType;
	Magazine m_srcMagazine; /// source of the cartridge

	ref WeaponStateBase m_start;
	ref WeaponEjectCasing m_eject;
	ref WeaponChambering_Base m_chamber;
	ref LoopedChambering_Wait4ShowBullet2 m_w4sb2;
	ref WeaponStartAction m_endLoop;
	ref BulletHide_W4T m_hideB;

	void LoopedChambering (Weapon_Base w = NULL, WeaponStateBase parent = NULL, WeaponActions action = WeaponActions.NONE, int startActionType = -1, int endActionType = -1)
	{
		m_action = action;
		m_startActionType = startActionType;
		m_endActionType = endActionType;

		// setup nested state machine
		m_start = new WeaponChambering_Start(m_weapon, this, m_action, m_startActionType);
		m_eject = new WeaponEjectCasing(m_weapon, this);
		m_chamber = new WeaponChambering_Cartridge_ChambToMag(m_weapon, this);
		m_w4sb2 = LoopedChambering_Wait4ShowBullet2(m_weapon, this);
		m_hideB = new BulletHide_W4T(m_weapon, this);
		m_endLoop = new WeaponStartAction(m_weapon, this, m_action, m_endActionType); // @NOTE: termination playing action - dummy?
		// events
		WeaponEventBase							_fin_ = new WeaponEventHumanCommandActionFinished;
		WeaponEventContinuousLoadBulletStart	__lS_ = new WeaponEventContinuousLoadBulletStart;
		WeaponEventContinuousLoadBulletEnd		__lE_ = new WeaponEventContinuousLoadBulletEnd;
		WeaponEventAnimBulletShow				__bs_ = new WeaponEventAnimBulletShow;
		WeaponEventAnimBulletHide				__bh_ = new WeaponEventAnimBulletHide;
		WeaponEventAnimBulletEject				__be_ = new WeaponEventAnimBulletEject;
		WeaponEventAnimBulletInMagazine			__bM_ = new WeaponEventAnimBulletInMagazine;
		WeaponEventAnimBulletShow2				_bs2_ = new WeaponEventAnimBulletShow2;

		m_fsm = new WeaponFSM(this); // @NOTE: set owner of the submachine fsm
		m_fsm.AddTransition(new WeaponTransition(m_start  , __be_, m_eject));
		m_fsm.AddTransition(new WeaponTransition(m_start  , __bs_, m_chamber));
		m_fsm.AddTransition(new WeaponTransition(m_eject  , __bs_, m_chamber));
		

		m_fsm.AddTransition(new WeaponTransition(m_chamber, __bM_, m_w4sb2, NULL, new GuardAnd(new GuardAnd(new WeaponGuardHasAmmoInLoopedState(m_chamber), new WeaponGuardChamberHasRoomForMoreThanOne(m_weapon)),new WeaponGuardWeaponManagerWantContinue())));
		m_fsm.AddTransition(new WeaponTransition(m_chamber, __bM_, m_endLoop));
		m_fsm.AddTransition(new WeaponTransition(m_w4sb2, 	__bh_, m_hideB));
		m_fsm.AddTransition(new WeaponTransition(m_hideB, 	__bs_, m_chamber));

		m_fsm.AddTransition(new WeaponTransition(m_endLoop, _fin_, NULL));
		

		m_fsm.SetInitialState(m_start);
	}

	override void OnEntry (WeaponEventBase e)
	{
		if (e != NULL)
		{
			if (e.m_magazine != NULL)
			{
				Print("[wpnfsm] LoopedChamberingEjectFirst, taking mag from event e.mag=" + e.m_magazine.ToString());
				m_srcMagazine = e.m_magazine;
			}
		}
		else
		{
			Print("[wpnfsm] LoopedChamberingEjectFirst (e=NULL), m_srcMagazine=" + m_srcMagazine.ToString());
		}
		Print("[wpnfsm] m_srcMagazine=" + m_srcMagazine.ToString());

		m_chamber.m_srcMagazine = m_srcMagazine;
		


		super.OnEntry(e); // @NOTE: super at the end (prevent override from submachine start)
	}
	override void OnExit (WeaponEventBase e)
	{
		m_srcMagazine = NULL;
		m_chamber.m_srcMagazine = NULL;
		super.OnExit(e);
		
	}
	override void OnAbort (WeaponEventBase e)
	{
		m_srcMagazine = NULL;
		m_chamber.m_srcMagazine = NULL;
		super.OnAbort(e);
	}
	
	override bool SaveCurrentFSMState (ParamsWriteContext ctx)
	{
		if (!super.SaveCurrentFSMState(ctx))
			return false;

		if (!ctx.Write(m_srcMagazine))
		{
			Error("[wpnfsm] WeaponChambering.SaveCurrentFSMState: cannot save m_srcMagazine for weapon=" + m_weapon);
			return false;
		}
		return true;
	}

	override bool LoadCurrentFSMState (ParamsReadContext ctx, int version)
	{
		if (!super.LoadCurrentFSMState(ctx, version))
			return false;

		if (!ctx.Read(m_srcMagazine))
		{
			Error("[wpnfsm] WeaponChambering.LoadCurrentFSMState: cannot read m_srcMagazine for weapon=" + m_weapon);
			return false;
		}
		return true;
	}
};

class LoopedChamberingEjectLast extends WeaponStateBase
{
	WeaponActions m_action;
	int m_startActionType;
	int m_endActionType;
	Magazine m_srcMagazine; /// source of the cartridge

	ref WeaponStateBase m_start;
	ref WeaponEjectCasing m_eject;
	ref WeaponChambering_Base m_chamber;
	ref LoopedChambering_Wait4ShowBullet2 m_w4sb2;
	ref WeaponStartAction m_endLoop;
	ref BulletHide_W4T m_hideB;
	ref WeaponChamberFromInnerMag_W4T m_chamberFromInnerMag;

	void LoopedChamberingEjectLast (Weapon_Base w = NULL, WeaponStateBase parent = NULL, WeaponActions action = WeaponActions.NONE, int startActionType = -1, int endActionType = -1)
	{
		m_action = action;
		m_startActionType = startActionType;
		m_endActionType = endActionType;

		// setup nested state machine
		m_start = new WeaponChambering_Start(m_weapon, this, m_action, m_startActionType);
		m_eject = new WeaponEjectCasing(m_weapon, this);
		m_chamber = new WeaponChambering_Cartridge_InnerMag(m_weapon, this);
		m_w4sb2 = new LoopedChambering_Wait4ShowBullet2(m_weapon, this);
		m_hideB = new BulletHide_W4T(m_weapon, this);
		m_chamberFromInnerMag = new WeaponChamberFromInnerMag_W4T(m_weapon, this);
		m_endLoop = new WeaponStartAction(m_weapon, this, m_action, m_endActionType); // @NOTE: termination playing action - dummy?
		// events
		WeaponEventBase							_fin_ = new WeaponEventHumanCommandActionFinished;
		WeaponEventContinuousLoadBulletStart	__lS_ = new WeaponEventContinuousLoadBulletStart;
		WeaponEventContinuousLoadBulletEnd		__lE_ = new WeaponEventContinuousLoadBulletEnd;
		WeaponEventAnimCocked					__wc_ = new WeaponEventAnimCocked;
		WeaponEventAnimBulletShow				__bs_ = new WeaponEventAnimBulletShow;
		WeaponEventAnimBulletHide				__bh_ = new WeaponEventAnimBulletHide;
		WeaponEventAnimBulletEject				__be_ = new WeaponEventAnimBulletEject;
		WeaponEventAnimBulletInMagazine			__bM_ = new WeaponEventAnimBulletInMagazine;
		WeaponEventAnimBulletShow2				_bs2_ = new WeaponEventAnimBulletShow2;

		m_fsm = new WeaponFSM(this); // @NOTE: set owner of the submachine fsm
		m_fsm.AddTransition(new WeaponTransition(m_start  , __bs_, m_chamber));
		

		m_fsm.AddTransition(new WeaponTransition(m_chamber, __bM_, m_w4sb2, NULL, new GuardAnd(new GuardAnd(new WeaponGuardHasAmmoInLoopedState(m_chamber), new WeaponGuardChamberHasRoomForMoreThanOne(m_weapon)),new WeaponGuardWeaponManagerWantContinue())));
		m_fsm.AddTransition(new WeaponTransition(m_chamber, __bM_, m_endLoop));
		m_fsm.AddTransition(new WeaponTransition(m_w4sb2,	__bh_, m_hideB));
		m_fsm.AddTransition(new WeaponTransition(m_hideB,	__bs_, m_chamber));

		m_fsm.AddTransition(new WeaponTransition(m_endLoop, _fin_, NULL));
		
		m_fsm.AddTransition(new WeaponTransition(m_endLoop,				__be_, m_eject));
		m_fsm.AddTransition(new WeaponTransition(m_eject,				__wc_, m_chamberFromInnerMag));
		m_fsm.AddTransition(new WeaponTransition(m_chamberFromInnerMag,	_fin_, NULL));
		

		m_fsm.SetInitialState(m_start);
	}

	override void OnEntry (WeaponEventBase e)
	{
		if (e != NULL)
		{
			if (e.m_magazine != NULL)
			{
				Print("[wpnfsm] LoopedChamberingEjectLast, taking mag from event e.mag=" + e.m_magazine.ToString());
				m_srcMagazine = e.m_magazine;
			}
		}
		else
		{
			Print("[wpnfsm] LoopedChamberingEjectLast (e=NULL), m_srcMagazine=" + m_srcMagazine.ToString());
		}
		Print("[wpnfsm] m_srcMagazine=" + m_srcMagazine.ToString());

		m_chamber.m_srcMagazine = m_srcMagazine;
		


		super.OnEntry(e); // @NOTE: super at the end (prevent override from submachine start)
	}
	override void OnExit (WeaponEventBase e)
	{
		m_srcMagazine = NULL;
		m_chamber.m_srcMagazine = NULL;
		super.OnExit(e);
		
	}
	override void OnAbort (WeaponEventBase e)
	{
		m_srcMagazine = NULL;
		m_chamber.m_srcMagazine = NULL;
		super.OnAbort(e);
		
	}
	
	override bool SaveCurrentFSMState (ParamsWriteContext ctx)
	{
		if (!super.SaveCurrentFSMState(ctx))
			return false;

		if (!ctx.Write(m_srcMagazine))
		{
			Error("[wpnfsm] WeaponChambering.SaveCurrentFSMState: cannot save m_srcMagazine for weapon=" + m_weapon);
			return false;
		}
		return true;
	}

	override bool LoadCurrentFSMState (ParamsReadContext ctx, int version)
	{
		if (!super.LoadCurrentFSMState(ctx, version))
			return false;

		if (!ctx.Read(m_srcMagazine))
		{
			Error("[wpnfsm] WeaponChambering.LoadCurrentFSMState: cannot read m_srcMagazine for weapon=" + m_weapon);
			return false;
		}
		return true;
	}
};