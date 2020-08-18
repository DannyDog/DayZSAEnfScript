class AmmoBox : Container_Base 
{
	override int GetDamageSystemVersionChange()
	{
		return 110;
	}
};
class FirstAidKit : Container_Base 
{
	override int GetDamageSystemVersionChange()
	{
		return 110;
	}
};
class PlateCarrierPouches : Container_Base
{
	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		if (!super.CanReceiveItemIntoCargo(item))
			return false;
		
		return !item.GetInventory().HasInventorySlot(InventorySlots.GetSlotIdFromString("Vest"));
	}
	
	override bool CanLoadItemIntoCargo( EntityAI item )
	{
		if (!super.CanLoadItemIntoCargo(item))
			return false;
		
		return !item.GetInventory().HasInventorySlot(InventorySlots.GetSlotIdFromString("Vest"));
	}
};
class Refrigerator: WorldContainer_Base {};
class RefrigeratorMinsk : WorldContainer_Base {};
class SmallProtectorCase : Container_Base 
{
	override int GetDamageSystemVersionChange()
	{
		return 110;
	}
};
class TrashCan : WorldContainer_Base {};
