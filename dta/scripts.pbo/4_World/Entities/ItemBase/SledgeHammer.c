class SledgeHammer extends Inventory_Base
{
	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionClapBearTrapWithThisItem);
		AddAction(ActionMineRock);
		AddAction(ActionDestroyPart);
	}
}