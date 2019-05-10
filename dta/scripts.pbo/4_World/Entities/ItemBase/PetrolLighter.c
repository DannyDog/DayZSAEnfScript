class PetrolLighter extends ItemBase
{
	override bool CanIgniteItem( EntityAI ignite_target = NULL )
	{
		return true;
	}
	
	/*
	override void OnIgnitedTarget( EntityAI ignited_item )
	{
	}
	*/
	
	/*
	override void OnIgnitedTargetFailed( EntityAI target_item )
	{
	}
	*/
	
	/*
	override bool IsTargetIgnitionSuccessful( EntityAI item_target = NULL )
	{
	}
	*/
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionLightItemOnFire);
	}
}