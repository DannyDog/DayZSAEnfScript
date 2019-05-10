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
	}
};
class Rope: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionRestrainTarget);
		AddAction(ActionRestrainSelf);
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