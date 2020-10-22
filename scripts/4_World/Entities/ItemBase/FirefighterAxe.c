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
		//AddAction(ActionRepairPart);
		AddAction(ActionDismantlePart);
		//AddAction(ActionBuildPart);
		//AddAction(ActionDestroyPart);
		//AddAction(ActionSawPlanks);
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionSkinning);
	}
}