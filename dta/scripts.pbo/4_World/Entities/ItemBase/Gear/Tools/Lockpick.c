class Lockpick: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionLockDoors);
		AddAction(ActionUnlockDoors);
	}
};
