class CivilianBelt: Clothing
{
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo( parent ) )
		{
			return false;
		}
		
		return IsEmpty();
	}
		
			
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "NylonKnifeSheath" );
			entity.GetInventory().CreateInInventory( "PlateCarrierHolster" );
			entity.GetInventory().CreateInInventory( "Canteen" );
		}
	}
};
