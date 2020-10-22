class PipeWrench extends Inventory_Base
{
	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		//AddAction(ActionDismantlePart);
		AddAction(ActionRepairCarEngine);
	}
}