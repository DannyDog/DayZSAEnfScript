class FlashGrenade extends Grenade_Base
{
	override void OnExplosionEffects(Object source, Object directHit, int componentIndex, string surface, vector pos, vector surfNormal, float energyFactor, float explosionFactor, bool isWater, string ammoType)
	{
		super.OnExplosionEffects(source, directHit, componentIndex, surface, pos, surfNormal, energyFactor, explosionFactor, isWater, ammoType);

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		if ( player )
		{
			bool visual = false;
			vector headPos = player.GetDamageZonePos("Head"); // animated position in the middle of the zone
			
			// get grenade range
			string grenadePath = "cfgAmmo " + ammoType + " indirectHitRange";
			float maxRange = GetGame().ConfigGetFloat(grenadePath);

			if ( vector.DistanceSq(headPos, pos) <= (maxRange * maxRange) ) 
			{
				// check visibility
				vector contactPos;
				vector contactDir;
				int contactComponent;
				
				// ignore collisions with parent if fireplace
				InventoryItem invItem = InventoryItem.Cast( source );
				EntityAI parent = invItem.GetHierarchyParent();
				array<Object> excluded = new array<Object>;
				
				if (!parent || !parent.IsFireplace())
					parent = null;
				else if (parent)
					excluded.Insert(parent);
				
				array<ref RaycastRVResult> results = new array<ref RaycastRVResult>;
				excluded.Insert(this); //Ignore self for visibility check
				
				//There shouldn't be cases justifying we go further than first entry (if in fireplace, self does not impact)
				RaycastRVParams rayParams = new RaycastRVParams(pos, headPos, excluded[0]);
				DayZPhysics.RaycastRVProxy(rayParams, results, excluded);
				
				//If player is not first index, object is between player and grenade
				if (PlayerBase.Cast(results[0].obj))
				{
					if ( MiscGameplayFunctions.IsPlayerOrientedTowardPos(player, pos, 60) )
					{
						visual = true;
					}
					player.OnPlayerReceiveFlashbangHitStart(visual);
				}
			}
		}
	}
	

	void FlashGrenade()
	{
		SetAmmoType("FlashGrenade_Ammo");
		SetFuseDelay(2);
		SetGrenadeType(EGrenadeType.ILLUMINATING);
		SetParticleExplosion(ParticleList.GRENADE_M84);
	}

	void ~FlashGrenade() {}
}