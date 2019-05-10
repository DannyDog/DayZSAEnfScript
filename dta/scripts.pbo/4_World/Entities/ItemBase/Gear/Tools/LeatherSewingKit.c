class LeatherSewingKit: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionSewTarget);
		AddAction(ActionSewSelf);
	}
};
