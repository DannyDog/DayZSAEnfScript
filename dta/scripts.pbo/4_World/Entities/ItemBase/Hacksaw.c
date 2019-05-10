class Hacksaw extends ToolBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionMineBush);
		AddAction(ActionSawPlanks);
		AddAction(ActionDestroyCombinationLock);
		AddAction(ActionDestroyPart);
	}
}