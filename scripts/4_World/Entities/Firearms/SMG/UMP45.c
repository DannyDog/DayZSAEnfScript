class UMP45_Base : RifleBoltLock_Base
{ 
	void UMP_Base()
	{	
	}
	
	override RecoilBase SpawnRecoilObject()
	{
		return new Ump45Recoil(this);
	}
	
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "PistolSuppressor" );
			entity.GetInventory().CreateInInventory( "ReflexOptic" );
			entity.GetInventory().CreateInInventory( "UniversalLight" );
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.SpawnEntityOnGroundPos("Mag_UMP_25Rnd", entity.GetPosition());
		}
	}
	
};