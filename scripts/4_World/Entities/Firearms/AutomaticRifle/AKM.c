class AKM_Base : RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new AkmRecoil(this);
	}
	
	override int GetWeaponSpecificCommand(int weaponAction ,int subCommand)
	{
		if ( weaponAction == WeaponActions.RELOAD)
		{
			switch (subCommand)
			{
				case WeaponActionReloadTypes.RELOADSRIFLE_MAGAZINE_BULLET:
					return WeaponActionReloadTypes.RELOADRIFLE_MAGAZINE_BULLET;
				
				case WeaponActionReloadTypes.RELOADSRIFLE_NOMAGAZINE_BULLET:
					return WeaponActionReloadTypes.RELOADRIFLE_NOMAGAZINE_BULLET;
				
				case WeaponActionReloadTypes.RELOADSRIFLE_MAGAZINE_NOBULLET:
					return WeaponActionReloadTypes.RELOADRIFLE_MAGAZINE_NOBULLET;
				
				case WeaponActionReloadTypes.RELOADSRIFLE_NOMAGAZINE_NOBULLET:
					return WeaponActionReloadTypes.RELOADRIFLE_NOMAGAZINE_NOBULLET;
				
				default:
					return subCommand;
			}
		
		}
		return subCommand;
	}
	
	override bool CanEnterIronsights()
	{
		ItemOptics optic = GetAttachedOptics();
		if (optic && PSO1Optic.Cast(optic) || PSO11Optic.Cast(optic) || KazuarOptic.Cast(optic))
			return true;
		return super.CanEnterIronsights();
	}
			
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "AK_WoodBttstck" );
			entity.GetInventory().CreateInInventory( "AK_RailHndgrd" );
			entity.GetInventory().CreateInInventory( "AK_Bayonet" );
			entity.GetInventory().CreateInInventory( "UniversalLight" );
			entity.GetInventory().CreateInInventory( "KobraOptic" );
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.SpawnEntityOnGroundPos("Mag_AKM_Drum75Rnd", entity.GetPosition());
		}
	}	
};