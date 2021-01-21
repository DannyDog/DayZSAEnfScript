class PlateCarrierVest: Clothing
{
			
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "PlateCarrierPouches" );
			entity.GetInventory().CreateInInventory( "PlateCarrierHolster" );
		}
	}
};