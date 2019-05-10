class Iceaxe: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionBuryAshes);
		AddAction(ActionDigGardenPlot);
		AddAction(ActionMineRock);
		AddAction(ActionDigWorms);
		AddAction(ActionBuildPart);
		AddAction(ActionDismantlePart);
	}
};
