class MeatTenderizer: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionBuildPart);

	}
};
