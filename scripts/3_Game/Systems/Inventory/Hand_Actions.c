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
		hndDebugPrint("[hndfsm] " + Object.GetDebugName(e.m_Player) + " STS=" + e.m_Player.GetSimulationTimeStamp() + " action=created");

		e.m_Player.OnItemInHandsChanged();
	}
};

class HandActionTake extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] " + Object.GetDebugName(e.m_Player) + " STS=" + e.m_Player.GetSimulationTimeStamp() + " action=take");

		GameInventory.LocationSyncMoveEntity(e.GetSrc(), e.GetDst());
		e.m_Player.OnItemInHandsChanged();
	}
};

class HandActionDrop extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] " + Object.GetDebugName(e.m_Player) + " STS=" + e.m_Player.GetSimulationTimeStamp() + " action=" + e.DumpToString());

		GameInventory.LocationSyncMoveEntity(e.GetSrc(), e.GetDst());
 		e.m_Player.OnItemInHandsChanged();
	}
};

class HandActionThrow extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] " + Object.GetDebugName(e.m_Player) + " STS=" + e.m_Player.GetSimulationTimeStamp() + " action=throw");
		HandEventThrow throwEvent = HandEventThrow.Cast(e);

		GameInventory.LocationSyncMoveEntity(e.GetSrc(), e.GetDst());

		DayZPlayer player = DayZPlayer.Cast(e.m_Player);
		if ( player.GetInstanceType() != DayZPlayerInstanceType.INSTANCETYPE_REMOTE )
		{
			InventoryItem item = InventoryItem.Cast(e.GetSrcEntity());
			if( item )
				item.ThrowPhysically(player, throwEvent.GetForce());
			else
				Error("[hndfsm] HandActionThrow - src entity null!");
		}

		player.OnItemInHandsChanged();
	}
};

class HandActionMoveTo extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		hndDebugPrint("[hndfsm] " + Object.GetDebugName(e.m_Player) + " STS=" + e.m_Player.GetSimulationTimeStamp() + " action=moveTo");

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
			hndDebugPrint("[hndfsm] " + Object.GetDebugName(e.m_Player) + " STS=" + e.m_Player.GetSimulationTimeStamp() + " Swap src1=" + InventoryLocation.DumpToStringNullSafe(es.GetSrc()) + " src2=" + InventoryLocation.DumpToStringNullSafe(es.m_Src2) + " dst1=" + InventoryLocation.DumpToStringNullSafe(es.GetDst()) +  "dst2=" + InventoryLocation.DumpToStringNullSafe(es.m_Dst2));

			GameInventory.LocationSwap(es.GetSrc(), es.m_Src2, es.GetDst(), es.m_Dst2);
			e.m_Player.OnItemInHandsChanged();
		}
		else
			Error("[hndfsm] HandActionSwap - this is no HandEventSwap");
	}
};

class HandActionForceSwap extends HandActionBase
{
	override void Action (HandEventBase e)
	{
		HandEventForceSwap es = HandEventForceSwap.Cast(e);
		if (es)
		{
			hndDebugPrint("[hndfsm] " + Object.GetDebugName(e.m_Player) + " STS=" + e.m_Player.GetSimulationTimeStamp() + " FSwap src1=" + InventoryLocation.DumpToStringNullSafe(es.GetSrc()) + " src2=" + InventoryLocation.DumpToStringNullSafe(es.m_Src2) + " dst1=" + InventoryLocation.DumpToStringNullSafe(es.GetDst()) +  "dst2=" + InventoryLocation.DumpToStringNullSafe(es.m_Dst2));

			GameInventory.LocationSwap(es.GetSrc(), es.m_Src2, es.GetDst(), es.m_Dst2);
			e.m_Player.OnItemInHandsChanged();
		}
		else
			Error("[hndfsm] HandActionForceSwap - this is no HandEventForceSwap");
	}
};

///@} actions

