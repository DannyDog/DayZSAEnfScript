class CrudeMachete extends ToolBase
{
	void Machete()
	{
	}

	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionBurnSewTarget);
		AddAction(ActionSkinning);
		AddAction(ActionMineBush);
		AddAction(ActionMineTreeBark);
		AddAction(ActionBurnSewSelf);
		AddAction(ActionDigWorms);
	}
}