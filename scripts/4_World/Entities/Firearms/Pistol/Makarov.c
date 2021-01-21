class MakarovIJ70_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MakarovRecoil(this);
	}
	
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "PistolSuppressor" );
			entity.SpawnEntityOnGroundPos("Mag_IJ70_8Rnd", entity.GetPosition());
		}
	}
};