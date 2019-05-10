class Epinephrine: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionInjectEpinephrineTarget);
		AddAction(ActionInjectEpinephrineSelf);
	}
};
