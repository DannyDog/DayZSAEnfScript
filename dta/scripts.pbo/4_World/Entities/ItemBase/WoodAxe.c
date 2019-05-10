class WoodAxe extends ToolBase
{
	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionMineTree);
		AddAction(ActionMineBush);
		AddAction(ActionDestroyPart);
		AddAction(ActionSawPlanks);
		AddAction(ActionUnrestrainTarget);
	}
}