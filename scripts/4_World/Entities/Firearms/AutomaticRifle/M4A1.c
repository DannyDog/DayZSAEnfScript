class M4A1_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new M4a1Recoil(this);
	}		
		
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "M9A1_Bayonet" );
			entity.GetInventory().CreateInInventory( "M4_OEBttstck" );	
			entity.GetInventory().CreateInInventory( "M4_RISHndgrd" );
			entity.GetInventory().CreateInInventory( "UniversalLight" );		
			entity.GetInventory().CreateInInventory( "M4_T3NRDSOptic" );	
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.GetInventory().CreateInInventory( "Battery9V" );	
			entity.SpawnEntityOnGroundPos("Mag_STANAGCoupled_30Rnd", entity.GetPosition());
		}
	}
};