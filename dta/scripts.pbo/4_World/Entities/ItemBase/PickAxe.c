class Pickaxe extends ItemBase
{
	override bool CanMakeGardenplot()
	{
		return true;
	}

	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDigGardenPlot);
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionMineRock);
		AddAction(ActionBuildPart);
		AddAction(ActionDismantlePart);
		AddAction(ActionDestroyPart);
		AddAction(ActionDigWorms);
	}
}	