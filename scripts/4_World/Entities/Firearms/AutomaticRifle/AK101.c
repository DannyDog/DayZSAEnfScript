class AK101_Base : AKM_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Ak101Recoil(this);
	}
			
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "AK_Bayonet" );
			entity.GetInventory().CreateInInventory( "AK_PlasticBttstck" );	
			entity.GetInventory().CreateInInventory( "AK_RailHndgrd" );
			entity.GetInventory().CreateInInventory( "PSO1Optic" );		
			entity.GetInventory().CreateInInventory( "UniversalLight" );	
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.GetInventory().CreateInInventory( "Battery9V" );	
			entity.SpawnEntityOnGroundPos("Mag_AK101_30Rnd", entity.GetPosition());
		}
	}
};

class AK101 : AK101_Base {};