class Colt1911_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Colt1911Recoil(this);
	}
	
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "PistolSuppressor" );
			entity.GetInventory().CreateInInventory( "TLRLight" );
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.SpawnEntityOnGroundPos("Mag_1911_7Rnd", entity.GetPosition());
		}
	}
};

class Colt1911 : Colt1911_Base {};
class Engraved1911 : Colt1911_Base {};