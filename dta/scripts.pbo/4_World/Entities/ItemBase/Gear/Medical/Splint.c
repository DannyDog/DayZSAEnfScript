class Splint: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionSplintTarget);
		AddAction(ActionSplintSelf);
	}
};
