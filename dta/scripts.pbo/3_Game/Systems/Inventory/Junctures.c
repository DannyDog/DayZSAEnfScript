
bool TryAcquireInventoryJunctureFromServer (notnull Man player, notnull InventoryLocation src, notnull InventoryLocation dst)
{
	if (player.NeedInventoryJunctureFromServer(src.GetItem(), src.GetParent(), dst.GetParent()))
	{
		bool test_dst_occupancy = true;
		if (GetGame().AddInventoryJuncture(player, src.GetItem(), dst, test_dst_occupancy, GameInventory.c_InventoryReservationTimeoutMS))
		{
			syncDebugPrint("[syncinv] juncture needed and acquired, player=" + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
			return JunctureRequestResult.JUNCTURE_ACQUIRED; // ok
		}
		else
		{
			syncDebugPrint("[syncinv] juncture request DENIED, player=" + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
			return JunctureRequestResult.JUNCTURE_DENIED; // permission to perform juncture denied
		}
	}
	else
	{
		syncDebugPrint("[syncinv] juncture not required, player=" + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " src=" + InventoryLocation.DumpToStringNullSafe(src) + " dst=" + InventoryLocation.DumpToStringNullSafe(dst));
		return JunctureRequestResult.JUNCTURE_NOT_REQUIRED; // juncture not necessary
	}
}

bool TryAcquireTwoInventoryJuncturesFromServer (notnull Man player, notnull InventoryLocation src1, notnull InventoryLocation src2, notnull InventoryLocation dst1, notnull InventoryLocation dst2)
{
	//syncDebugPrint("[syncinv] t=" + GetGame().GetTime() + "ms TryAcquireTwoInventoryJuncturesFromServer src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2) +  " dst1=" + InventoryLocation.DumpToStringNullSafe(dst1) + " dst2=" + InventoryLocation.DumpToStringNullSafe(dst2));

	bool need_j1 = player.NeedInventoryJunctureFromServer(src1.GetItem(), src1.GetParent(), dst1.GetParent());
	bool need_j2 = player.NeedInventoryJunctureFromServer(src2.GetItem(), src2.GetParent(), dst2.GetParent());
	if (need_j1 || need_j2)
	{
		if (need_j1)
		{
			if (!GetGame().AddInventoryJuncture(player, src1.GetItem(), dst1, false, GameInventory.c_InventoryReservationTimeoutMS))
			{
				syncDebugPrint("[syncinv] item1 juncture request DENIED, player=" + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2) +  " dst1=" + InventoryLocation.DumpToStringNullSafe(dst1) + " dst2=" + InventoryLocation.DumpToStringNullSafe(dst2));
				return JunctureRequestResult.JUNCTURE_DENIED; // permission to perform juncture denied
			}
		}

		if (need_j2)
		{
			if (!GetGame().AddInventoryJuncture(player, src2.GetItem(), dst2, false, GameInventory.c_InventoryReservationTimeoutMS))
			{
				syncDebugPrint("[syncinv] item2 juncture request DENIED, player=" + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2) +  " dst1=" + InventoryLocation.DumpToStringNullSafe(dst1) + " dst2=" + InventoryLocation.DumpToStringNullSafe(dst2));
				if (need_j1)
				{
					GetGame().ClearJuncture(player, src1.GetItem()); // release already acquired juncture for item1
					syncDebugPrint("[syncinv] item2 juncture request DENIED, cleaning acquired juncture for item1, , player=" + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2) +  " dst1=" + InventoryLocation.DumpToStringNullSafe(dst1) + " dst2=" + InventoryLocation.DumpToStringNullSafe(dst2));
				}
				return JunctureRequestResult.JUNCTURE_DENIED; // permission to perform juncture denied
			}
		}

		return JunctureRequestResult.JUNCTURE_ACQUIRED; // ok, both junctures acquired
	}
	else
	{
		syncDebugPrint("[syncinv] junctures not required, player=" + Object.GetDebugName(player) + " STS=" + player.GetSimulationTimeStamp() + " src1=" + InventoryLocation.DumpToStringNullSafe(src1) + " src2=" + InventoryLocation.DumpToStringNullSafe(src2) +  " dst1=" + InventoryLocation.DumpToStringNullSafe(dst1) + " dst2=" + InventoryLocation.DumpToStringNullSafe(dst2));
		return JunctureRequestResult.JUNCTURE_NOT_REQUIRED; // juncture not necessary
	}
}

