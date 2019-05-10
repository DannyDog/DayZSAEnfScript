class FirefighterAxe extends ToolBase
{
	void FirefighterAxe()
	{
	}
	
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