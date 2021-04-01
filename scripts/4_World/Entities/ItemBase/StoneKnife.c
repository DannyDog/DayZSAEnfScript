class StoneKnife extends ToolBase
{
	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionSkinning);
		AddAction(ActionMineBush);
		AddAction(ActionMineTreeBark);
		AddAction(ActionDigWorms);
	}
}