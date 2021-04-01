class KitchenKnife extends ToolBase
{
	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBurnSewTarget);
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionSkinning);
		AddAction(ActionMineBush);
		AddAction(ActionMineTreeBark);
		AddAction(ActionBurnSewSelf);
		AddAction(ActionDigWorms);
		AddAction(ActionShaveTarget);
		AddAction(ActionDisarmMine);
		AddAction(ActionShave);
	}
}