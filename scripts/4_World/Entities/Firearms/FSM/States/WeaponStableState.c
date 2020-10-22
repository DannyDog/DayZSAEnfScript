/**@class		WeaponStableState
 * @brief	  represents weapon's stable state (i.e. the basic states that the weapon will spend the most time in)
 *
 * Stable states have associated animation states that they supposed to be in.
 * If they are not, the SetWeaponAnimState is called on the weapon in order to
 * set to required (configured) state
 *
 * @NOTE: OnExit from stable state, the weapon's animation state (@see
 * Weapon_Base::m_weaponAnimState) is set to -1 (unknown) In case of action
 * abort the final stable state is forced to set proper animation state
 * according to configuration (@see m_animState)
 **/

enum MuzzleState
{
	E	=  0,
	F	=  1,
	L	=  2
}

class WeaponStableState extends WeaponStateBase
{
	int m_animState;
	
	ref array<MuzzleState> m_muzzleHasBullet = new array<MuzzleState>();

	void WeaponStableState(Weapon_Base w = NULL, WeaponStateBase parent = NULL, int anim_state = -1) { m_animState = anim_state; InitMuzzleArray(); }

	void SyncAnimState()
	{
		int curr = m_weapon.GetWeaponAnimState();
		if (curr != m_animState)
		{			
			//fsmDebugSpam("[wpnfsm] " + Object.GetDebugName(m_weapon) + " synchronizing anim state: " + curr + " --> " + m_animState);
			DayZPlayer p;
			if (Class.CastTo(p, m_weapon.GetHierarchyParent()))
			{
				HumanCommandWeapons hcw = p.GetCommandModifier_Weapons();
				if (hcw)
				{
					hcw.SetInitState(m_animState);
					m_weapon.SetWeaponAnimState(m_animState);
					fsmDebugSpam("[wpnfsm] " + Object.GetDebugName(m_weapon) + " state=" + m_weapon.GetCurrentState().Type() + " synchronized anim state: " + typename.EnumToString(PistolAnimState, curr) + " --> " + typename.EnumToString(PistolAnimState, m_animState));
				}
				else
				{
					Human wpnOwner = Human.Cast(m_weapon.GetHierarchyRootPlayer());
					HumanCommandWeapons.StaticSetInitState(wpnOwner, m_animState);
					m_weapon.SetWeaponAnimState(m_animState);
					fsmDebugSpam("[wpnfsm] " + Object.GetDebugName(m_weapon) + " state=" + m_weapon.GetCurrentState().Type() + " synchronized remote anim state: " + typename.EnumToString(PistolAnimState, curr) + " --> " + typename.EnumToString(PistolAnimState, m_animState));
				}
			}		
		}
	}

	override void OnEntry(WeaponEventBase e)
	{
		super.OnEntry(e);
		m_weapon.SetJammed(false);
		if (e)
			SyncAnimState();
	}
	override void OnUpdate(float dt)
	{
		super.OnUpdate(dt);
		SyncAnimState();
	}
	override void OnExit(WeaponEventBase e)
	{
		m_weapon.ResetWeaponAnimState();
		super.OnExit(e);
	}
	
	void InitMuzzleArray() {}

	override bool IsIdle() { return true; }

	int GetCurrentStateID() { return 0; }
	/// let's not break anything that is not configured for the system
	bool IsRepairEnabled() { return false; }
	/// query for bullet
    bool HasBullet() { return false; }
	/// query for magazine
	bool HasMagazine() { return false; }
	/// query for jammed state
	bool IsJammed() { return false; }
	/// query for bullet in chamber
	MuzzleState GetMuzzleState(int idx) { return m_muzzleHasBullet[idx]; }
};


