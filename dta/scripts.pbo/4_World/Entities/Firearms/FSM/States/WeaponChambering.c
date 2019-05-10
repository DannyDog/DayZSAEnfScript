// load 1 bullet
class WeaponChambering_Start extends WeaponStartAction
{ 
	override void OnEntry (WeaponEventBase e)
	{
		super.OnEntry(e);

		m_weapon.SelectionBulletHide();
	}
};

class WeaponChambering_Base extends WeaponStateBase
{
	float m_damage;
	string m_type;
	Magazine m_srcMagazine; /// source of the cartridge
	
	override bool SaveCurrentFSMState (ParamsWriteContext ctx)
	{
		if (!super.SaveCurrentFSMState(ctx))
			return false;

		if (!ctx.Write(m_damage))
		{
			Error("[wpnfsm] WeaponChambering.SaveCurrentFSMState: cannot write m_damage for weapon=" + m_weapon);
			return false;
		}
		if (!ctx.Write(m_type))
		{
			Error("[wpnfsm] WeaponChambering.SaveCurrentFSMState: cannot write m_type for weapon=" + m_weapon);
			return false;
		}
		if (!ctx.Write(m_srcMagazine))
		{
			Error("[wpnfsm] WeaponChambering.SaveCurrentFSMState: cannot write m_srcMagazine for weapon=" + m_weapon);
			return false;
		}
		return true;
	}

	override bool LoadCurrentFSMState (ParamsReadContext ctx, int version)
	{
		if (!super.LoadCurrentFSMState(ctx, version))
			return false;

		if (!ctx.Read(m_damage))
		{
			Error("[wpnfsm] WeaponChambering.LoadCurrentFSMState: cannot read m_damage for weapon=" + m_weapon);
			return false;
		}
		if (!ctx.Read(m_type))
		{
			Error("[wpnfsm] WeaponChambering.LoadCurrentFSMState: cannot read m_type for weapon=" + m_weapon);
			return false;
		}
		if (!ctx.Read(m_srcMagazine))
		{
			Error("[wpnfsm] WeaponChambering.LoadCurrentFSMState: cannot read m_srcMagazine for weapon=" + m_weapon);
			return false;
		}
		return true;
	}
};


class WeaponChambering_Cartridge extends WeaponChambering_Base
{
	override void OnEntry (WeaponEventBase e)
	{
		super.OnEntry(e);

		if (m_srcMagazine)
		{
			if (m_srcMagazine.LocalAcquireCartridge(m_damage, m_type))
			{
				wpnDebugPrint("[wpnfsm] WeaponChambering_Cartridge, ok - cartridge acquired: dmg=" + m_damage + " type=" + m_type);
				m_weapon.SelectionBulletShow();
			}
			else
				Error("[wpnfsm] WeaponChambering_Cartridge, error - cannot take cartridge from magazine");
		}
		else
		{
			Error("[wpnfsm] WeaponChambering_Cartridge, error - no magazine to load from (m_srcMagazine=NULL)");
		}
	}

	override void OnAbort (WeaponEventBase e)
	{
		if (m_srcMagazine)
		{
			//bool is_single_or_server = !GetGame().IsMultiplayer() || GetGame().IsServer();
			int mi = m_weapon.GetCurrentMuzzle();
			string magazineTypeName = m_weapon.GetChamberAmmoTypeName(mi);
			if( !GetGame().IsMultiplayer() || GetGame().IsServer() )
			{
				if (DayZPlayerUtils.HandleDropCartridge(e.m_player, m_damage, m_type, magazineTypeName))
					wpnDebugPrint("[wpnfsm] WeaponChambering_Cartridge, ok - aborting, chambering cartridge dropped to ground");
				else
					Error("[wpnfsm] WeaponChambering_Cartridge, error - cannot abort removal from wpn (of old mag)");
			}

			m_weapon.SelectionBulletHide(); // force hide on abort
		}
		m_type = string.Empty;
		super.OnAbort(e);
	}

	override void OnExit (WeaponEventBase e)
	{
		int mi = m_weapon.GetCurrentMuzzle();
		//if ( m_weapon.IsChamberFiredOut(mi) )
		//	m_weapon.EjectCasing(mi);
		if (m_weapon.PushCartridgeToChamber(mi, m_damage, m_type))
		{
			wpnDebugPrint("[wpnfsm] WeaponChambering_Cartridge, ok - loaded chamber");
		}
		else
			wpnDebugPrint("[wpnfsm] WeaponChambering_Cartridge, error - cannot load chamber chamber!");

		m_type = string.Empty;
		super.OnExit(e);
	}

};

class WeaponChambering_Cartridge_ChambToMag extends WeaponChambering_Cartridge
{
	override void OnExit (WeaponEventBase e)
	{
		float ammoDamage;
 		string ammoTypeName;
		int mi = m_weapon.GetCurrentMuzzle();
		if (m_weapon.IsChamberFull(mi))
		{
			m_weapon.PopCartridgeFromChamber(mi, ammoDamage, ammoTypeName);
			if (m_weapon.PushCartridgeToInternalMagazine(mi, ammoDamage, ammoTypeName))
			{
				wpnDebugPrint("[wpnfsm] WeaponChambering_Cartridge, ok - loaded chamber");
			}
			else
				wpnDebugPrint("[wpnfsm] WeaponChambering_Cartridge, error - cannot load chamber chamber!");
		}
		super.OnExit(e);
	}
}


class WeaponChambering_Cartridge_InnerMag extends WeaponChambering_Base
{
	override void OnEntry (WeaponEventBase e)
	{
		super.OnEntry(e);

		if (m_srcMagazine)
		{
			if (m_srcMagazine.LocalAcquireCartridge(m_damage, m_type))
			{
				wpnDebugPrint("[wpnfsm] WeaponChambering_Cartridge_InnerMag, ok - cartridge acquired: dmg=" + m_damage + " type=" + m_type);
				m_weapon.SelectionBulletShow();
			}
			else
				Error("[wpnfsm] WeaponChambering_Cartridge_InnerMag, error - cannot take cartridge from magazine");
		}
		else
		{
			Error("[wpnfsm] WeaponChambering_Cartridge_InnerMag, error - no magazine to load from (m_srcMagazine=NULL)");
		}
	}

	override void OnAbort (WeaponEventBase e)
	{
		if (m_srcMagazine)
		{
			//bool is_single_or_server = !GetGame().IsMultiplayer() || GetGame().IsServer();
			int mi = m_weapon.GetCurrentMuzzle();
			string magazineTypeName = m_weapon.GetChamberAmmoTypeName(mi);
			if( !GetGame().IsMultiplayer() || GetGame().IsServer() )
			{
				if (DayZPlayerUtils.HandleDropCartridge(e.m_player, m_damage, m_type, magazineTypeName))
					wpnDebugPrint("[wpnfsm] WeaponChambering_Cartridge_InnerMag, ok - aborting, chambering cartridge dropped to ground");
				else
					Error("[wpnfsm] WeaponChambering_Cartridge_InnerMag, error - cannot abort removal from wpn (of old mag)");
			}

			m_weapon.SelectionBulletHide(); // force hide on abort
		}
		m_type = string.Empty;
		super.OnAbort(e);
	}

	override void OnExit (WeaponEventBase e)
	{
		float ammoDamage;
 		string ammoTypeName;
		int mi = m_weapon.GetCurrentMuzzle();
		if (!m_weapon.IsInternalMagazineFull(mi))
		{
			if (m_weapon.PushCartridgeToInternalMagazine(mi, m_damage, m_type))
			{
				wpnDebugPrint("[wpnfsm] WeaponChambering_Cartridge_InnerMag, ok - loaded chamber");
			}
			else
				wpnDebugPrint("[wpnfsm] WeaponChambering_Cartridge_InnerMag, error - cannot load chamber chamber!");
		}
		super.OnExit(e);
	}
};

class WeaponChambering_W4T extends WeaponStateBase
{
	override bool IsWaitingForActionFinish () { return true; }
};

class WeaponChambering extends WeaponStateBase
{
	WeaponActions m_action;
	int m_actionType;
	Magazine m_srcMagazine; /// source of the cartridge

	ref WeaponStateBase m_start;
	ref WeaponEjectCasing m_eject;
	ref WeaponChambering_Cartridge m_chamber;
	ref WeaponChambering_W4T m_w4t;

	void WeaponChambering (Weapon_Base w = NULL, WeaponStateBase parent = NULL, WeaponActions action = WeaponActions.NONE, int actionType = -1)
	{
		m_action = action;
		m_actionType = actionType;

		// setup nested state machine
		m_start = new WeaponChambering_Start(m_weapon, this, m_action, m_actionType);
		m_chamber = new WeaponChambering_Cartridge(m_weapon, this);
		m_w4t = new WeaponChambering_W4T(m_weapon, this);
		m_eject = new WeaponEjectCasing(m_weapon, this);
		// events
		WeaponEventBase _fin_ = new WeaponEventHumanCommandActionFinished;
		WeaponEventAnimBulletInChamber __bc_ = new WeaponEventAnimBulletInChamber;
		WeaponEventAnimBulletShow  __bs_ = new WeaponEventAnimBulletShow;
		WeaponEventAnimBulletEject	__be_ = new WeaponEventAnimBulletEject;

		m_fsm = new WeaponFSM(this); // @NOTE: set owner of the submachine fsm
		m_fsm.AddTransition(new WeaponTransition(m_start  , __be_, m_eject));
		m_fsm.AddTransition(new WeaponTransition(m_start  , __bs_, m_chamber));
		m_fsm.AddTransition(new WeaponTransition(m_eject  , __bs_, m_chamber));
		m_fsm.AddTransition(new WeaponTransition(m_chamber, __bc_, m_w4t));
		m_fsm.AddTransition(new WeaponTransition(m_w4t    , _fin_, NULL));

		m_fsm.SetInitialState(m_start);
	}

	override void OnEntry (WeaponEventBase e)
	{
		if (e != NULL)
		{
			if (e.m_magazine != NULL)
			{
				wpnDebugPrint("[wpnfsm] WeaponChambering, taking mag from event e.mag=" + e.m_magazine.ToString());
				m_srcMagazine = e.m_magazine;
			}
		}
		else
		{
			wpnDebugPrint("[wpnfsm] WeaponChambering (e=NULL), m_srcMagazine=" + m_srcMagazine.ToString());
		}
		wpnDebugPrint("[wpnfsm] m_srcMagazine=" + m_srcMagazine.ToString());

		m_chamber.m_srcMagazine = m_srcMagazine;

		super.OnEntry(e); // @NOTE: super at the end (prevent override from submachine start)
	}

	override void OnAbort (WeaponEventBase e)
	{
		m_srcMagazine = NULL;
		m_chamber.m_srcMagazine = NULL;
		super.OnAbort(e);
	}

	override void OnExit (WeaponEventBase e)
	{
		m_srcMagazine = NULL;
		m_chamber.m_srcMagazine = NULL;
		super.OnExit(e);
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

