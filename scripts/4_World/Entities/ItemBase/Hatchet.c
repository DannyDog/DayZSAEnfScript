class Hatchet extends ToolBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionMineTree);
		AddAction(ActionMineBush);
		AddAction(ActionDismantlePart);
		AddAction(ActionBuildPart);
		//AddAction(ActionDestroyPart);
		//AddAction(ActionSawPlanks);
		AddAction(ActionUnrestrainTarget);
	}
}