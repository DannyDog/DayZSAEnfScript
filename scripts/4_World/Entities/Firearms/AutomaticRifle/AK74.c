class AK74_Base : AKM_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Ak74Recoil(this);
	}
	
		
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "AK74_WoodBttstck" );
			entity.GetInventory().CreateInInventory( "AK74_Hndgrd" );
			entity.GetInventory().CreateInInventory( "PSO1Optic" );
			entity.GetInventory().CreateInInventory( "AK_Bayonet" );
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.SpawnEntityOnGroundPos("Mag_AK74_30Rnd", entity.GetPosition());
		}
	}
};

class AK74 : AK74_Base
{
	override bool CanEnterIronsights()
	{
		ItemOptics optic = GetAttachedOptics();
		if (optic && PSO1Optic.Cast(optic) || PSO11Optic.Cast(optic) || KazuarOptic.Cast(optic))
			return true;
		return super.CanEnterIronsights();
	}
};