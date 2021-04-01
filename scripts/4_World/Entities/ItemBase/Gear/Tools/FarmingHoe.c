class FarmingHoe: ItemBase
{
	override bool CanMakeGardenplot()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionClapBearTrapWithThisItem);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDigGardenPlot);
		AddAction(ActionDismantleGardenPlot);
		AddAction(ActionDismantlePart);
		AddAction(ActionBuildPart);
		AddAction(ActionBuryBody);
		AddAction(ActionBuryAshes);
		AddAction(ActionDigOutStash);
		AddAction(ActionDigInStash);
		AddAction(ActionFillObject);
		AddAction(ActionDigWorms);
		AddAction(ActionCreateGreenhouseGardenPlot);
	}
};
