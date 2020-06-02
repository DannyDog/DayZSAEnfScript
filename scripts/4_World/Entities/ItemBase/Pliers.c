class Pliers extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionDismantlePart);
		AddAction(ActionBuildPart);
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionMountBarbedWire);
		AddAction(ActionUnmountBarbedWire);
	}
}