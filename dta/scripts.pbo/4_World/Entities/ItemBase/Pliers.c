class Pliers extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionBuildPart);
		AddAction(ActionDismantlePart);
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionMountBarbedWire);
		AddAction(ActionUnmountBarbedWire);
	}
}