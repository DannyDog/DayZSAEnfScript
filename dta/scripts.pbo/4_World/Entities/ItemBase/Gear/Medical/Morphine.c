class Morphine: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionInjectMorphineTarget);
		AddAction(ActionInjectMorphineSelf);
	}
};
