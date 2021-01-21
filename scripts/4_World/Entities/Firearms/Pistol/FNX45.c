class FNX45_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Fnx45Recoil(this);
	}
		
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "PistolSuppressor" );
			entity.GetInventory().CreateInInventory( "FNP45_MRDSOptic" );
			entity.GetInventory().CreateInInventory( "TLRLight" );
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.SpawnEntityOnGroundPos("Mag_FNX45_15Rnd", entity.GetPosition());
		}
	}
	
};