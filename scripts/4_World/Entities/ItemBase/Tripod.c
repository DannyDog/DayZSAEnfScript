class Tripod extends ItemBase
{
	override bool HasProxyParts()
	{
		return true;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
}