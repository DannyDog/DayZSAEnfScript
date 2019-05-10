class FarmingHoe: Inventory_Base
{
	override bool CanMakeGardenplot()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionClapBearTrapWithThisItem);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDigGardenPlot);
		AddAction(ActionBuryAshes);
		AddAction(ActionDigWorms);
	}
};
