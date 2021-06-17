class M16A2_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new M16A2Recoil(this);
	}		
		
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.SpawnEntityOnGroundPos("Mag_STANAGCoupled_30Rnd", entity.GetPosition());
		}
	}
};