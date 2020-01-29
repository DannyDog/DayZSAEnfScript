class Hammer extends Inventory_Base
{
	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionMineRock1H);
		AddAction(ActionBuildPart);
	}
	
	override bool GetSpecialUserActionDamage(out float damage, int action_type = -1)
	{
		damage = 3.0;
		return true;
	};
}