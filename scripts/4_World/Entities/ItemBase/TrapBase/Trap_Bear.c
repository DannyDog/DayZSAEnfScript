class BearTrap extends TrapBase
{
	// Vertical raycast start positions:    		Center,      North East,    North West,    South East,  South West
	static const vector m_RaycastSources[5] = {"0.0 0.1 0.0", "0.2 0.1 0.2", "-.2 0.1 0.2", "0.2 0.1 -.2", "-.2 0.1 -.2"}; // Positions are local to model. Vertical offset prevents ground collision.
	
	void BearTrap()
	{
		m_DamagePlayers = 5; 		//How much damage player gets when caught
		m_DefectRate = 0;
		m_InitWaitTime = 0; 			//After this time after deployment, the trap is activated
		m_AnimationPhaseGrounded = "placing";
		m_AnimationPhaseSet = "BearTrap_Set";
		m_AnimationPhaseTriggered = "placing";
	}
	
	override void OnSteppedOn(EntityAI victim)
	{		
		PlayerBase victimPB = PlayerBase.Cast(victim);
		if (GetGame().IsServer() && victimPB)
		{
			vector 	contact_pos;
			vector 	contact_dir;
			int 	contactComponent;
			ref set<Object> victims = new set<Object>;
				
			for ( int i = 0; i < 5; ++i )
			{
				vector raycast_start_pos = ModelToWorld ( m_RaycastSources[i] );
				vector raycast_end_pos = "0 0.5 0" + raycast_start_pos;
				DayZPhysics.RaycastRV( raycast_start_pos, raycast_end_pos, contact_pos, contact_dir, contactComponent, victims , NULL, this, true, false, ObjIntersectIFire);
					
				/*
				Print("Checking Raycast hit...");
				Print(contactComponent);
				Print(victimPB.GetDamageZoneNameByComponentIndex(contactComponent));
				*/
				
				for ( int j = 0; j < victims.Count(); ++j )
				{
					Object contact_obj = victims.Get(j);
					if ( contact_obj.IsMan() )
					{
						OnServerSteppedOn(victimPB, victimPB.GetDamageZoneNameByComponentIndex(contactComponent));
						return;
					}
				}
			}
				
			// Damage random leg since we don't know what part of player's body was caught in the trap.
			string damageZoneRand = "LeftLeg";
			if ( Math.RandomIntInclusive(0, 1) == 1 )
				damageZoneRand = "RightLeg";
				
			OnServerSteppedOn(victimPB, damageZoneRand);
		}
		else if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			if (victimPB)
			{
				victimPB.SpawnDamageDealtEffect();
				PlaySoundBiteLeg();
			}
			else if (victim.IsInherited(DayZCreatureAI))
				PlaySoundBiteLeg();
			else
				PlaySoundBiteEmpty();
		}
	}
	
	void OnServerSteppedOn(PlayerBase victim, string damageZone)
	{
		CauseVictimToStartLimping( victim, damageZone );
		victim.ProcessDirectDamage(DT_CLOSE_COMBAT, this, damageZone, "BearTrapHit", "0 0 0", 1);
	}
	
	// Causes the player to start limping. This is temporary and should at some point be replaced by broken legs
	void CauseVictimToStartLimping( PlayerBase victim, string damagedZone )
	{
		float damage = victim.GetMaxHealth(); //deal 100% damage to break legs
		victim.DamageAllLegs(damage); 
	}
		
	void PlaySoundBiteLeg()
	{
		SEffectManager.PlaySound("beartrapCloseDamage_SoundSet", this.GetPosition(), 0, 0, false);
	}
	
	void PlaySoundBiteEmpty()
	{
		SEffectManager.PlaySound("beartrapClose_SoundSet", this.GetPosition(), 0, 0, false);
	}
	
	void PlaySoundOpen()
	{
		SEffectManager.PlaySound("beartrapOpen_SoundSet", this.GetPosition(), 0, 0, false);
	}

	override void OnActivate()
	{
		if ( (GetGame().IsClient() || !GetGame().IsMultiplayer()) && GetGame().GetPlayer() )
		{
			PlaySoundOpen();
		}
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		if ( GetGame().IsServer() )
		{
			PlayerBase player_PB = PlayerBase.Cast( player );
			StartActivate( player_PB );
			
			m_TrapTrigger.SetPosition( position );
		}	
	}
	
	override bool IsDeployable()
	{
		return true;
	}
	
	override string GetLoopDeploySoundset()
	{
		return "beartrap_deploy_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionClapBearTrapWithThisItem);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
}