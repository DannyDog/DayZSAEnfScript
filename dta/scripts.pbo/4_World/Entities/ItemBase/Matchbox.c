class Matchbox extends ItemBase
{
	override bool CanIgniteItem( EntityAI ignite_target = NULL )
	{
		return true;
	}
	
	override void OnIgnitedTarget( EntityAI ignited_item )
	{
		if ( GetGame().IsServer() )
		{
			AddQuantity( -1 );
		}
	}
	
	override void OnIgnitedTargetFailed( EntityAI target_item )
	{
		if ( GetGame().IsServer() )
		{
			AddQuantity( -1 );
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionLightItemOnFire);
	}
	
	/*
	override bool IsTargetIgnitionSuccessful( EntityAI item_target = NULL )
	{
	}
	*/
}