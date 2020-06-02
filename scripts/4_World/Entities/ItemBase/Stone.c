class Stone extends ItemBase
{
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		//update visuals if stone quantity changed
		FireplaceBase fireplace_base = FireplaceBase.Cast( GetHierarchyParent() );
		if ( fireplace_base )
		{
			fireplace_base.RefreshFireplaceVisuals();
		}
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionAttach);
		AddAction(ActionDetach);
	}
}