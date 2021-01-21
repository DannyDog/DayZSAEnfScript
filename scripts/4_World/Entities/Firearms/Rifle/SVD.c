class SVD_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
	}
	
	override bool CanEnterIronsights()
	{
		ItemOptics optic = GetAttachedOptics();
		if (optic && PSO1Optic.Cast(optic) || PSO11Optic.Cast(optic) || KashtanOptic.Cast(optic))
			return true;
		return super.CanEnterIronsights();
	}
			
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "PSO1Optic" );	
			entity.GetInventory().CreateInInventory( "AK_Suppressor" );	
			entity.GetInventory().CreateInInventory( "Battery9V" );	
			entity.SpawnEntityOnGroundPos("Mag_SVD_10Rnd", entity.GetPosition());
		}
	}
};