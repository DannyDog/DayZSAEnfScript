class SewingKit: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionRepairTent);
		AddAction(ActionRepairShelter);
		AddAction(ActionSewTarget);
		AddAction(ActionSewSelf);
	}
};
