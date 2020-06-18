class Hammer extends Inventory_Base
{
	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionRepairPart);
		AddAction(ActionBuildPartSwitch);
		//AddAction(ActionMineRock1H);
		AddAction(ActionBuildPart);
	}
}