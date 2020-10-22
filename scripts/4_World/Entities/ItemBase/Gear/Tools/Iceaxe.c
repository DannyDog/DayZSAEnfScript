class Iceaxe: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionBuryAshes);
		AddAction(ActionDigGardenPlot);
		//AddAction(ActionMineRock1H);
		AddAction(ActionDigWorms);
		AddAction(ActionDismantlePart);
		AddAction(ActionBuildPart);
		AddAction(ActionSkinning);
	}
};
