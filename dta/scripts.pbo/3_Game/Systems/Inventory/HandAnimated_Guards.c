int SlotToAnimType (notnull Man player, notnull InventoryLocation src)
{
	if (src.GetType() == InventoryLocationType.ATTACHMENT)
	{
		//return WeaponHideShowTypes.HIDESHOW_SLOT_KNIFEBACK;
		switch (src.GetSlot())
		{
			case InventorySlots.SHOULDER:
			{
				if (src.GetItem() && src.GetItem().IsWeapon())
				{
					return WeaponHideShowTypes.HIDESHOW_SLOT_RFLLEFTBACK;
				}
				else if (src.GetItem() && src.GetItem().IsOneHandedBehaviour())
				{
					return WeaponHideShowTypes.HIDESHOW_SLOT_1HDLEFTBACK;
				}
				return WeaponHideShowTypes.HIDESHOW_SLOT_2HDLEFTBACK;
			}
			case InventorySlots.MELEE:
			{
				if (src.GetItem() && src.GetItem().IsWeapon())
				{
					return WeaponHideShowTypes.HIDESHOW_SLOT_RFLRIGHTBACK;
				}
				else if (src.GetItem() && src.GetItem().IsOneHandedBehaviour())
				{
					return WeaponHideShowTypes.HIDESHOW_SLOT_1HDRIGHTBACK;
				}
				return WeaponHideShowTypes.HIDESHOW_SLOT_2HDRIGHTBACK;
			}
			case InventorySlots.PISTOL:
			{
				EntityAI parent_item = src.GetParent(); 		// belt
				Man owner;
				if (parent_item)
					owner = parent_item.GetHierarchyRootPlayer(); 		// player
				EntityAI item1 = owner.GetInventory().FindAttachment(InventorySlots.HIPS);
				EntityAI item2 = parent_item.GetHierarchyParent();
				if (owner && owner.GetInventory().FindAttachment(InventorySlots.HIPS) == parent_item.GetHierarchyParent()) // is the pistol in a belt holster?
				{
					return WeaponHideShowTypes.HIDESHOW_SLOT_PISTOLBELT;
				}
				return WeaponHideShowTypes.HIDESHOW_SLOT_PISTOLCHEST;
			}
			case InventorySlots.KNIFE:
				return WeaponHideShowTypes.HIDESHOW_SLOT_KNIFEBACK;
			
			case InventorySlots.VEST:
			case InventorySlots.FEET:
			case InventorySlots.BODY:
			case InventorySlots.LEGS:
			case InventorySlots.BACK:
				return WeaponHideShowTypes.HIDESHOW_SLOT_INVENTORY;
			
			default:
				Print("[hndfsm] SlotToAnimType -  not animated slot in src_loc=" + InventoryLocation.DumpToStringNullSafe(src));
		};
		//
		//if (InventorySlots.GetSlotIdFromString("Pistol"))
	}
	else if (src.GetType() == InventoryLocationType.CARGO)
	{
		return WeaponHideShowTypes.HIDESHOW_SLOT_INVENTORY;
	}
	return -1;
}

bool SelectAnimationOfTakeToHands (notnull Man player, notnull InventoryLocation src, notnull InventoryLocation dst, out int animType)
{
	if (player.IsInTransport())
		return false;
	if (src.GetType() == InventoryLocationType.GROUND)
		return false;

	if (src.GetItem().GetHierarchyRootPlayer() == player)
	{	
		animType = SlotToAnimType(player, src);
		if (animType != -1)
		{
			hndDebugPrint("[hndfsm] SelectAnimationOfTakeToHands - selected animType=" + animType + " for item=" + src.GetItem());
			return true;
		}
	}
	hndDebugPrint("[hndfsm] SelectAnimationOfTakeToHands - no animation");
	return false;
}

bool SelectAnimationOfMoveFromHands (notnull Man player, notnull InventoryLocation src, notnull InventoryLocation dst, out int animType)
{
	if (player.IsInTransport())
		return false;

	if (src.GetItem().GetHierarchyRootPlayer() == player)
	{	
		animType = SlotToAnimType(player, dst);
		if (animType != -1)
		{
			hndDebugPrint("[hndfsm] SelectAnimationOfMoveFromHands guard - selected animType=" + animType + " for item=" + src.GetItem());
			return true;
		}
	}
	hndDebugPrint("[hndfsm] SelectAnimationOfMoveFromHands - no animation");
	return false;
}

bool SelectAnimationOfForceSwapInHands (notnull Man player, notnull InventoryLocation old_src, notnull InventoryLocation old_dst, notnull InventoryLocation new_src, notnull InventoryLocation new_dst, out int animType1, out int animType2)
{
	if (player.IsInTransport())
		return false;

	if (old_src.GetItem().GetHierarchyRootPlayer() == player && new_src.GetItem().GetHierarchyRootPlayer() == player)
	{
		animType1 = SlotToAnimType(player, old_dst);
		animType2 = SlotToAnimType(player, new_src);
		if (animType1 != -1 || animType2 != -1)
		{
			hndDebugPrint("[hndfsm] SelectAnimationOfForceSwapInHands guard - selected animType1=" + animType1 + " animType2=" + animType2 + " for old_item=" + old_src.GetItem() + " for new_item=" + new_src.GetItem());
			return true;
		}
	}
	hndDebugPrint("[hndfsm] SelectAnimationOfForceSwapInHands - no animation");
	return false;
}


class HandSelectAnimationOfTakeToHandsEvent extends HandGuardBase
{
	void HandSelectAnimationOfTakeToHandsEvent (Man p = NULL) { }

	override bool GuardCondition (HandEventBase e)
	{
		int animType = -1;
		if (SelectAnimationOfTakeToHands(e.m_Player, e.GetSrc(), e.GetDst(), animType))
		{
			e.m_AnimationID = animType;
			return true;
		}
		return false;
	}
};

class HandSelectAnimationOfMoveFromHandsEvent extends HandGuardBase
{
	protected Man m_Player;
	ref HandGuardHasRoomForItem m_HasRoomGuard = new HandGuardHasRoomForItem;

	void HandSelectAnimationOfMoveFromHandsEvent (Man p = NULL) { m_Player = p; }

	override bool GuardCondition (HandEventBase e)
	{
		if (m_HasRoomGuard.GuardCondition(e))
		{
			EntityAI eai = m_Player.GetHumanInventory().GetEntityInHands();
			if (eai)
			{
				InventoryLocation src = new InventoryLocation;
				if (eai.GetInventory().GetCurrentInventoryLocation(src))
				{
					int animType = -1;
					if (SelectAnimationOfMoveFromHands(e.m_Player, src, e.GetDst(), animType))
					{
						e.m_AnimationID = animType;
						return true;
					}
					return false;
				}
			}
		}
		return false;
	}
};

class HandSelectAnimationOfForceSwapInHandsEvent extends HandGuardBase
{
	protected Man m_Player;

	void HandSelectAnimationOfForceSwapInHandsEvent (Man p = NULL) { m_Player = p; }

	bool ProcessSwapEvent (notnull HandEventBase e, notnull InventoryLocation old_dst, out int animType1, out int animType2)
	{
		EntityAI old_e = e.m_Player.GetHumanInventory().GetEntityInHands();
		EntityAI new_e = e.GetSrcEntity();

		if (!old_e)
		{
			Error("[hndfsm] HandSelectAnimationOfForceSwapInHandsEvent - old_e (in hands) is null!");
			return false;
		}
		
		if (!new_e)
		{
			Error("[hndfsm] HandSelectAnimationOfForceSwapInHandsEvent - new_e (in hands) is null!");
			return false;
		}

		if (!old_dst || !old_dst.IsValid())
		{
			Error("[hndfsm] HandSelectAnimationOfForceSwapInHandsEvent - old_dst (dst of item in hands) is null (or invalid)!");
			return false;
		}

		InventoryLocation old_src = new InventoryLocation;
		if (!old_e.GetInventory().GetCurrentInventoryLocation(old_src))
		{
			Error("[hndfsm] HandSelectAnimationOfForceSwapInHandsEvent - old_e has no inv location");
			return false;
		}

		InventoryLocation new_src = new InventoryLocation;
		if (!new_e.GetInventory().GetCurrentInventoryLocation(new_src))
		{
			Error("[hndfsm] HandSelectAnimationOfForceSwapInHandsEvent - new_e has no inv location");
			return false;
		}

		InventoryLocation new_dst = new InventoryLocation;
		new_dst.SetHands(e.m_Player, new_src.GetItem());

		return SelectAnimationOfForceSwapInHands(e.m_Player, old_src, old_dst, new_src, new_dst, animType1, animType2);
	}

	override bool GuardCondition (HandEventBase e)
	{
		HandEventForceSwap es = HandEventForceSwap.Cast(e);
		if (es)
		{
			hndDebugPrint("[hndfsm] HandGuardHasRoomForItem FSwap e=" + e.DumpToString());
			
			bool allow = false;
			if (GameInventory.CanSwapEntities(es.GetSrc().GetItem(), es.m_Src2.GetItem()))
				allow = true; // allow if ordinary swap
			else if (es.m_Dst2)
			{
				if (!GameInventory.LocationTestAddEntity(es.m_Dst2, false, true, true, true, true))
					Error("[hndfsm] HandGuardHasRoomForItem - no room at dst=" + InventoryLocation.DumpToStringNullSafe(e.GetDst()));
				allow = true;
			}
			
			if (allow)
			{
				int animType1 = -1;
				int animType2 = -1;
				if (ProcessSwapEvent(e, es.m_Dst2, animType1, animType2))
				{
					e.m_AnimationID = animType1;
					es.m_Animation2ID = animType2;
					return true;
				}
			}
			else
				Error("[hndfsm] HandSelectAnimationOfForceSwapInHandsEvent - m_HasRoomGuard.GuardCondition failed");
		}
		else
			Error("[hndfsm] HandSelectAnimationOfForceSwapInHandsEvent - not a swap event");
		return false;
	}
};

class HandSelectAnimationOfSwapInHandsEvent extends HandSelectAnimationOfForceSwapInHandsEvent
{
	override bool GuardCondition (HandEventBase e)
	{
		HandEventSwap es = HandEventSwap.Cast(e);
		if (es)
		{
			int animType1 = -1;
			int animType2 = -1;
			if (ProcessSwapEvent(e, es.m_Dst2, animType1, animType2))
			{
				e.m_AnimationID = animType1;
				es.m_Animation2ID = animType2;
				return true;
			}
		}
		else
			Error("[hndfsm] HandSelectAnimationOfSwapInHandsEvent - not a swap event");
		return false;
	}
};

