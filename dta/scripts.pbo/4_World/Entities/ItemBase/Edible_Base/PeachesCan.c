class PeachesCan : Edible_Base
{
	override void Open()
	{
		//super.Open();
		ReplaceEdibleWithNew("PeachesCan_Opened");
	}
}
