class SplitItemUtils
{
	static void TakeOrSplitToInventory ( notnull PlayerBase player, notnull EntityAI target, notnull EntityAI item)
	{
		ItemBase item_base = ItemBase.Cast( item );
		float stack_max = item_base.ConfigGetFloat("varStackMax");
		if(stack_max < 1)
			stack_max = item_base.GetQuantityMax();
		
		if( !item.GetInventory().CanRemoveEntity() || !player.CanManipulateInventory() )
			return;
		
		if( stack_max >= item_base.GetQuantity() )
		{
			player.PredictiveTakeEntityToTargetAttachment(target, item);
		}
		else
		{
			item_base.SplitIntoStackMaxCargoClient( target, -1, 0, 0 );
		}
	}
	
	static void TakeOrSplitToInventoryLocation ( notnull PlayerBase player, notnull InventoryLocation dst)
	{
		ItemBase item_base = ItemBase.Cast( dst.GetItem() );
		float stack_max = item_base.ConfigGetFloat("varStackMax");
		
		if(stack_max < 1)
			stack_max = item_base.GetQuantityMax();
		
		int slot = dst.GetSlot();

		if( !dst.GetItem().GetInventory().CanRemoveEntity() || !player.CanManipulateInventory() )
			return;
		
		if( slot != -1 )
		{
			int slot_stack_max = InventorySlots.GetStackMaxForSlotId( slot );
			if (slot_stack_max > 0)
				stack_max = slot_stack_max;
		}
		
		if( stack_max >= item_base.GetQuantity() )
		{
			InventoryLocation src = new InventoryLocation;
			if (dst.GetItem().GetInventory().GetCurrentInventoryLocation(src))
			{
				player.PredictiveTakeToDst(src, dst);
			}
			else
				Error("TakeIntoCargoEx cannot get src for dst=" + dst.DumpToString());
		}
		else
		{
			item_base.SplitIntoStackMaxToInventoryLocationClient( dst );
		}
	}
}