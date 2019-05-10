class BearTrap extends TrapBase
{
	// Vertical raycast start positions:    Center,      North East,    North West,    South East,  South West
	static vector m_RaycastSources[5] = {"0.0 0.1 0.0", "0.2 0.1 0.2", "-.2 0.1 0.2", "0.2 0.1 -.2", "-.2 0.1 -.2"}; // Positions are local to model. Vertical offset prevents ground collision.
	
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
		vector 	contact_pos;
		vector 	contact_dir;
		int 	contactComponent;
		bool 	IsSteppedOn = false;
		ManBase	victim_MB = ManBase.Cast( victim );
		Print(victim_MB);
		ref set<Object> victims = new set<Object>;
		
		if (victim_MB)
		{
			if ( GetGame().IsServer() )
			{
				for ( int i = 0; i < 5; ++i )
				{
					vector raycast_start_pos = ModelToWorld ( m_RaycastSources[i] );
					vector raycast_end_pos = "0 0.5 0" + raycast_start_pos;
					
					//Debug.DrawArrow( raycast_start_pos, raycast_end_pos ); // Uncomment for debugging of raycast positions
					DayZPhysics.RaycastRV( raycast_start_pos, raycast_end_pos, contact_pos, contact_dir, contactComponent, victims , NULL, this, true, false, ObjIntersectIFire);
					
					Print("Checking Raycast hit...");
					Print(contactComponent);
					Print(victim_MB.GetDamageZoneNameByComponentIndex(contactComponent));
					
					for ( int i2 = 0; i2 < victims.Count(); ++i2 )
					{
						Object contact_obj = victims.Get(i2);
						
						if ( contact_obj.IsMan() )
						{
							IsSteppedOn = true;
							break;
						}
					}
					
					if (IsSteppedOn)
					{
						break;
					}
				}
			}
			
			if ( GetGame().IsServer() )
			{
				if (IsSteppedOn)
				{
					if ( victim_MB.IsControlledPlayer())
					{
						if ( victim_MB.IsInherited(Man) ) // Do not damage OLD player through new damage system! Otherwise the game might crash!
						{
							string dmg_zone_hit = victim_MB.GetDamageZoneNameByComponentIndex(contactComponent);
							//Print(dmg_zone_hit);
							victim_MB.ProcessDirectDamage(DT_CLOSE_COMBAT, this, dmg_zone_hit, "BearTrapHit", "0 0 0", 1);
							
							CauseVictimToStartLimping( victim_MB );

							//debug
							/* 
							PlayerBase player = PlayerBase.Cast( victim );
							if (player)
							{
								player.MessageStatus( dmg_zone_hit );
							}
							*/
						}
					}
				}
				else
				{
					// Damage random leg since we don't know what part of player's body was caught in the trap.
					
					string dmg_zone_rnd = "LeftFoot";
					if ( Math.RandomIntInclusive(0, 1) == 1 )
						dmg_zone_rnd = "RightFoot";
					
					//Print(dmg_zone_rnd);
					victim_MB.ProcessDirectDamage(DT_CLOSE_COMBAT, this, dmg_zone_rnd, "BearTrapHit", "0 0 0", 1);

					CauseVictimToStartLimping( victim_MB );
					
					//debug
					/* 
					PlayerBase player2 = PlayerBase.Cast( victim );
					if (player2)
					{
						player2.MessageStatus( dmg_zone_rnd );
					}
					*/
				}
			}
			
			if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
			{
				PlayerBase player_victim = PlayerBase.Cast( victim );
			
				player_victim.SpawnDamageDealtEffect();
			}
			
			PlaySoundBiteLeg();
		}
		else
		{
			PlaySoundBiteEmpty();
		}
	}
	
	// Causes the player to start limping. Temporal solution until broken limbs are properly simulated.
	void CauseVictimToStartLimping( ManBase player_MB )
	{
		PlayerBase player_PB = PlayerBase.Cast(player_MB);
		
		if (player_PB)
		{
			float target_health = player_PB.GetHealth() * 0.2;
			player_PB.SetHealth(target_health);
		}
	}
		
	void PlaySoundBiteLeg()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			SEffectManager.PlaySound("beartrapCloseDamage_SoundSet", this.GetPosition(), 0, 0, false);
		}
	}
	
	void PlaySoundBiteEmpty()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			SEffectManager.PlaySound("beartrapClose_SoundSet", this.GetPosition(), 0, 0, false);
		}
	}
	
	void PlaySoundOpen()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			SEffectManager.PlaySound("beartrapOpen_SoundSet", this.GetPosition(), 0, 0, false);
		}
	}
	
	override void OnActivate()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if ( GetGame().GetPlayer() )
			{
				PlaySoundOpen();
			}
		}
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementComplete( Man player ) 
	{		
		if ( GetGame().IsServer() )
		{
			PlayerBase player_PB = PlayerBase.Cast( player );
			StartActivate( player_PB );
			
			m_TrapTrigger.SetPosition( player_PB.GetLocalProjectionPosition() );
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