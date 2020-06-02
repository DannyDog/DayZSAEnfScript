class HandSaw: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionMineBush);
		AddAction(ActionSawPlanks);
		//AddAction(ActionDestroyCombinationLock);
		//AddAction(ActionDestroyPart);
	}
};
