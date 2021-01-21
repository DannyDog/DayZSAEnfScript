class MKII_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MkiiRecoil(this);
	}
	
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.SpawnEntityOnGroundPos("Mag_MKII_10Rnd", entity.GetPosition());
		}
	}
};
