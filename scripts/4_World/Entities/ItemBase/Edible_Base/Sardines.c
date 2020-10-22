class Sardines extends Edible_Base
{
	override bool CanBeCookedOnStick()
	{
		return false;
	}	

	override bool CanBeCooked()
	{
		return false;
	}	
	
	override bool IsMeat()
	{
		return true;
	}

	override bool CanDecay()
	{
		return true;
	}
}
