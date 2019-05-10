class DisinfectantAlcohol: Edible_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDisinfectTarget);
		AddAction(ActionDisinfectSelf);
		AddAction(ActionFillGeneratorTank);
		AddAction(ActionForceDrinkAlcohol);
		AddAction(ActionDrinkAlcohol);
	}
};
