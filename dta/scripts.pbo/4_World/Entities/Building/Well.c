class Well extends BuildingSuper
{
	override bool IsBuilding()
	{
		return false;
	}
	
	override bool IsWell()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		//AddAction(ActionDrinkWell);
		AddAction(ActionWashHandsWellOne);
		AddAction(ActionDrinkWellContinuous);
	}
	

}