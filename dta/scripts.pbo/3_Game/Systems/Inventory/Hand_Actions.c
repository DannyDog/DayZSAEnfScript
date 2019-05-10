///@{ actions

/**@class	HandActionBase
 * @brief	represents action executed on transition just between OnExit from old state and OnEntry to new state
 **/
class HandActionBase
{
	/**@fn			Action
	 * @brief		executed when transition occurs
	 **/
	void Action (HandEventBase e) { }
};


class HandActionCreated extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] action=created");

		e.m_Player.OnItemInHandsChanged();
	}
};

class HandActionTake extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] action=take");

		GameInventory.LocationSyncMoveEntity(e.GetSrc(), e.GetDst());
		e.m_Player.OnItemInHandsChanged();
	}
};

class HandActionDrop extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] action=drop");

		GameInventory.LocationSyncMoveEntity(e.GetSrc(), e.GetDst());
		e.m_Player.OnItemInHandsChanged();
	}
};

class HandActionThrow extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] action=throw");
		HandActionThrow action = HandActionThrow.Cast(e);

		GameInventory.LocationSyncMoveEntity(e.GetSrc(), e.GetDst());

		e.GetSrcEntity().CreateDynamicPhysics(PhxInteractionLayers.DYNAMICITEM);
		dBodyApplyImpulse(e.GetSrcEntity(), vector.Up * 20);

		e.m_Player.OnItemInHandsChanged();
	}
};

class HandActionMoveTo extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] action=moveTo");

		HandEventMoveTo es = HandEventMoveTo.Cast(e);
		if (es)
		{
			GameInventory.LocationSyncMoveEntity(e.GetSrc(), es.m_Dst);
			e.m_Player.OnItemInHandsChanged();
		}
		else
			Error("[hndfsm] HandActionMoveTo - this is no HandEventMoveTo");
	}
};

class HandActionDestroy extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] action=destroy");

		GetGame().ObjectDelete(e.GetSrcEntity());
		e.m_Player.OnItemInHandsChanged();
	}
};

class HandActionDestroyed extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] action=destroyed");

		e.m_Player.OnItemInHandsChanged();
	}
};

class HandActionDestroyAndReplaceWithNew extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		Man player = e.m_Player;
		EntityAI itemInHands = player.GetHumanInventory().GetEntityInHands();

		InventoryLocation src = new InventoryLocation;
		if (itemInHands.GetInventory().GetCurrentInventoryLocation(src))
		{
			HandEventDestroyAndReplaceWithNew edr = HandEventDestroyAndReplaceWithNew.Cast(e);
			if (edr)
			{
				hndDebugPrint("[hndfsm] action=replace with new");

				edr.m_Lambda.Execute();
				return;
			}
			else
				Error("[hndfsm] HandActionDestroyAndReplaceWithNew - not a HandEventDestroyAndReplaceWithNew event");
		}
		else
			Error("[hndfsm] HandActionDestroyAndReplaceWithNew - itemInHands has no InventoryLocation");
	}
};

class HandActionDestroyAndReplaceWithNewElsewhere extends HandActionDestroyAndReplaceWithNew
{
	override void Action (HandEventBase e)
	{
		super.Action(e);
	}
};

class HandActionReplaced extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] action=replaced");
		Man player = e.m_Player;

		player.OnItemInHandsChanged();
	}
};

class HandActionSwap extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		HandEventSwap es = HandEventSwap.Cast(e);
		if (es)
		{
			hndDebugPrint("[hndfsm] Swap src1=" + InventoryLocation.DumpToStringNullSafe(es.GetSrc()) + " src2=" + InventoryLocation.DumpToStringNullSafe(es.m_Src2) + " dst1=" + InventoryLocation.DumpToStringNullSafe(es.GetDst()) +  "dst2=" + InventoryLocation.DumpToStringNullSafe(es.m_Dst2));

			GameInventory.LocationSwap(es.GetSrc(), es.m_Src2, es.GetDst(), es.m_Dst2);
			e.m_Player.OnItemInHandsChanged();
		}
		else
			Error("[hndfsm] HandActionSwap - this is no HandEventSwap");
	}
};

class HandActionForceSwap extends HandActionBase
{
};

///@} actions

