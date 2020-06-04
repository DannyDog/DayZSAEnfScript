class BurlapSack: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionCoverHeadTarget);
		AddAction(ActionCoverHeadSelf);
	}
};
class GorkaHelmetVisor: Inventory_Base {};
class ChickenFeather: Inventory_Base {};
class LongWoodenStick: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionClapBearTrapWithThisItem);
		AddAction(ActionCookOnStick);
		AddAction(ActionBreakLongWoodenStick);
	}
};
class Rope: Inventory_Base
{
	InventoryLocation m_TargetLocation = null;
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionRestrainTarget);
		AddAction(ActionRestrainSelf);
	}
	
	InventoryLocation GetTargetLocation()
	{
		return m_TargetLocation;
	}
	
	void SetTargetLocation(InventoryLocation targetLocation)
	{
		m_TargetLocation = targetLocation;
	}
};
class Spear : Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionClapBearTrapWithThisItem);
	}
};