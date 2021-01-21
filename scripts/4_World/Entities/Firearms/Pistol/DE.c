class Deagle_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new DEagleRecoil(this);
	}
	
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "PistolSuppressor" );
			entity.GetInventory().CreateInInventory( "PistolOptic" );
			entity.SpawnEntityOnGroundPos("Mag_Deagle_9rnd", entity.GetPosition());
		}
	}
	
};

class Deagle : Deagle_Base {};
class Deagle_Gold : Deagle_Base {};

