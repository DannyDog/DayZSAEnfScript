class B95_base : DoubleBarrel_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new B95Recoil(this);
	}
	
		
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "HuntingOptic" );
			entity.SpawnEntityOnGroundPos("Ammo_308Win", entity.GetPosition());
		}
	}
	
};

class B95 : B95_base
{};