class Hammer extends Inventory_Base
{
	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildPartSwitch);
		//AddAction(ActionMineRock);
		AddAction(ActionBuildPart);
	}
}