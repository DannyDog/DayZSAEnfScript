class RDG2SmokeGrenade_ColorBase : Grenade_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
	}
};