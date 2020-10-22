class Zucchini : Edible_Base
{
	override bool CanBeCookedOnStick()
	{
		return true;
	}

	override bool CanBeCooked()
	{
		return true;
	}	

	override bool IsFruit()
	{
		return true;
	}
	
	override bool CanDecay()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatFruit);
	}
}
