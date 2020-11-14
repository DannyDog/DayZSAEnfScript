///@{ guards

/**@class	HandGuardBase
 * @brief	represents guard on a transition from state to state
 **/
class HandGuardBase
{
	/**@fn			GuardCondition
	 * @brief		enable or disable transition based on condition
	 * the guard is a boolean operation executed first and which can prevent the transition from firing by returning false
	 * @return		true if transition is allowed
	 **/
	bool GuardCondition (HandEventBase e) { return true; }
};


class HandGuardAnd extends HandGuardBase
{
	ref HandGuardBase m_arg0;
	ref HandGuardBase m_arg1;

	void HandGuardAnd (HandGuardBase arg0 = NULL, HandGuardBase arg1 = NULL) { m_arg0 = arg0; m_arg1 = arg1; }

	override bool GuardCondition (HandEventBase e)
	{
		bool result = m_arg0.GuardCondition(e) && m_arg1.GuardCondition(e);
		hndDebugPrint("[hndfsm] HandGuardAnd guard - " + m_arg0.Type() + " && " + m_arg1.Type() + " = " + result);
		return result;
	}
};

class HandGuardNot extends HandGuardBase
{
	ref HandGuardBase m_arg0;

	void HandGuardNot (HandGuardBase arg0 = NULL) { m_arg0 = arg0; }

	override bool GuardCondition (HandEventBase e)
	{
		bool result = !m_arg0.GuardCondition(e);
		hndDebugPrint("[hndfsm] HandGuardNot guard - ! " + m_arg0.Type() + " = " + result);
		return result;
	}
};

class HandGuardOr extends HandGuardBase
{
	ref HandGuardBase m_arg0;
	ref HandGuardBase m_arg1;

	void HandGuardOr (HandGuardBase arg0 = NULL, HandGuardBase arg1 = NULL) { m_arg0 = arg0; m_arg1 = arg1; }

	override bool GuardCondition (HandEventBase e)
	{
		bool result = m_arg0.GuardCondition(e) || m_arg1.GuardCondition(e);
		hndDebugPrint("[hndfsm] HandGuardOr guard - " + m_arg0.Type() + " || " + m_arg1.Type() + " = " + result);
		return result;
	}
};

class HandGuardHasItemInEvent extends HandGuardBase
{
	protected Man m_Player;
	void HandGuardHasItemInEvent (Man p = NULL) { m_Player = p; }

	override bool GuardCondition (HandEventBase e)
	{
		EntityAI eai = e.GetSrcEntity();
		if (eai != NULL /* && CanTakeInHands*/)
		{
			hndDebugPrint("[hndfsm] HandGuardHasItemInEvent guard - has valid entity in event");
			return true;
		}
		hndDebugPrint("[hndfsm] HandGuardHasItemInEvent guard - no entity in event");
		return false;
	}
};

class HandGuardHasWeaponInEvent extends HandGuardHasItemInEvent
{
	void HandGuardHasWeapoonInEvent (Man p = NULL) { }

	override bool GuardCondition (HandEventBase e)
	{
		EntityAI eai = e.GetSrcEntity();
		if (eai != NULL)
		{
			if (eai.IsWeapon())
			{
				hndDebugPrint("[hndfsm] HandGuardHasWeaponInEvent guard - has valid weapon in event");
				return true;
			}
			else
			{
				hndDebugPrint("[hndfsm] HandGuardHasWeaponInEvent guard - entity, but not weapon in event");
				return false;
			}
		}
		hndDebugPrint("[hndfsm] HandGuardHasWeaponInEvent guard - no entity in event");
		return false;
	}
};

class HandGuardIsSameItemInHands extends HandGuardBase
{
	protected Man m_Player;
	void HandGuardIsSameItemInHands (Man p = NULL) { m_Player = p; }

	override bool GuardCondition (HandEventBase e)
	{
		if (e.GetSrcEntity() == m_Player.GetHumanInventory().GetEntityInHands())
		{
			hndDebugPrint("[hndfsm] HandGuardIsSameItemInHands guard - has same entity in hands");
			return true;
		}

		hndDebugPrint("[hndfsm] HandGuardIsSameItemInHands guard - different entity in hands");
		return false;
	}
};

class HandGuardHasDestroyedItemInHands extends HandGuardBase
{
	protected Man m_Player;
	void HandGuardHasDestroyedItemInHands (Man p = NULL) { m_Player = p; }

	override bool GuardCondition (HandEventBase e)
	{
		hndDebugSpam("[hndfsm] HandGuardHasDestroyedItemInHands guard - has same entity in hands ev=" + e.GetSrcEntity() + " hnd=" + m_Player.GetHumanInventory().GetEntityInHands());
		EntityAI hnd = m_Player.GetHumanInventory().GetEntityInHands();
		if (e.GetSrcEntity())
		{
			if (e.GetSrcEntity() == hnd)
			{
				hndDebugPrint("[hndfsm] HandGuardHasDestroyedItemInHands guard - has same entity in hands");
				return true;
			}

			if (hnd == null)
			{
				hndDebugPrint("[hndfsm] HandGuardHasDestroyedItemInHands guard - hands already empty");
				return true;
			}
		}
		else
		{
			hndDebugPrint("[hndfsm] HandGuardHasDestroyedItemInHands guard - hands already empty and item destroyed");
			return true;
		}

		hndDebugPrint("[hndfsm] HandGuardHasDestroyedItemInHands guard - destroyed entity not in hands");
		return false;
	}
};

class HandGuardHasItemInHands extends HandGuardBase
{
	protected Man m_Player;
	void HandGuardHasItemInHands (Man p = NULL) { m_Player = p; }

	override bool GuardCondition (HandEventBase e)
	{
		if (m_Player.GetHumanInventory().GetEntityInHands())
		{
			hndDebugPrint("[hndfsm] HandGuardHasItemInHands guard - has valid entity in hands");
			return true;
		}

		hndDebugPrint("[hndfsm] HandGuardHasItemInHands guard - no entity in hands");
		return false;
	}
};

class HandGuardHasRoomForItem extends HandGuardBase
{
	protected Man m_Player;
	void HandGuardHasRoomForItem (Man p = NULL) { m_Player = p; }

	override bool GuardCondition(HandEventBase e)
	{
		if (e.GetDst() && e.GetDst().IsValid())
		{
			if( GetGame().IsClient() || !GetGame().IsMultiplayer())
			{
				if(m_Player)
					m_Player.GetHumanInventory().ClearInventoryReservation(e.GetDst().GetItem(),e.GetDst());
			}

			if (!GameInventory.LocationTestAddEntity(e.GetDst(), false, true, true, true, true))
			{
				hndDebugPrint("[hndfsm] HandGuardHasRoomForItem - no room at dst=" + InventoryLocation.DumpToStringNullSafe(e.GetDst()));
				//Error("[hndfsm] HandGuardHasRoomForItem - no room at dst=" + InventoryLocation.DumpToStringNullSafe(e.GetDst()));
				return false;
			}
				
			
			if( GetGame().IsClient() || !GetGame().IsMultiplayer())
			{
				if(m_Player)
					m_Player.GetHumanInventory().AddInventoryReservation(e.GetDst().GetItem(), e.GetDst(), GameInventory.c_InventoryReservationTimeoutShortMS);
			}
			return true;
		}

		hndDebugPrint("[hndfsm] HandGuardHasRoomForItem guard - e.m_Dst is null");
		return false;
	}
};

class HandGuardCanSwap extends HandGuardBase
{
	protected Man m_Player;
	void HandGuardCanSwap(Man p = NULL) { m_Player = p; }

	override bool GuardCondition(HandEventBase e)
	{
		HandEventSwap es = HandEventSwap.Cast(e);
		
		if (GameInventory.CanSwapEntitiesEx(es.GetSrc().GetItem(), es.m_Src2.GetItem()))
			return true;

		hndDebugPrint("[hndfsm] HandGuardCanSwap guard - cannot swap");
		return false;
	}
};

class HandGuardCanForceSwap extends HandGuardBase
{
	protected Man m_Player;
	void HandGuardCanForceSwap(Man p = NULL) { m_Player = p; }

	override bool GuardCondition(HandEventBase e)
	{
		HandEventForceSwap es = HandEventForceSwap.Cast(e);
		
		if (GameInventory.CanSwapEntitiesEx(es.GetSrc().GetItem(), es.m_Src2.GetItem()))
			return true; // allow if ordinary swap
		else if (es.m_Dst2 && GameInventory.CanForceSwapEntitiesEx(es.GetSrc().GetItem(), null, es.m_Src2.GetItem(), es.m_Dst2))
			return true;

		hndDebugPrint("[hndfsm] HandGuardCanForceSwap guard - cannot forceswap");
		return false;
	}
};

///@} guards

