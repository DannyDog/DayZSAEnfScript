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
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDigGardenPlot);
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionMineRock);
		AddAction(ActionDismantlePart);
		AddAction(ActionBuildPart);
		//AddAction(ActionDestroyPart);
		AddAction(ActionDigWorms);
		AddAction(ActionSkinning);
		AddAction(ActionDigOutStash);
		AddAction(ActionDigInStash);
	}
}	