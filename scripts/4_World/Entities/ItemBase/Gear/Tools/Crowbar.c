class Crowbar: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDismantlePart);
		AddAction(ActionSkinning);
	}
};
