class WoodAxe extends ToolBase
{
	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		//AddAction(ActionBuildPartSwitch);
		AddAction(ActionMineTree);
		AddAction(ActionMineBush);
		//AddAction(ActionRepairPart);
		AddAction(ActionDismantlePart);
		//AddAction(ActionBuildPart);
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionSkinning);
	}
}