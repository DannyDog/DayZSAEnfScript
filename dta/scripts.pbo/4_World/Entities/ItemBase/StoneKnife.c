class StoneKnife extends ToolBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionSkinning);
		AddAction(ActionMineBush);
		AddAction(ActionMineTreeBark);
	}
}