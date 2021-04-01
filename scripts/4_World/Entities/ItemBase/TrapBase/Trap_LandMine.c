enum SoundTypeMine
{
	DISARMING = 0
}

class LandMineTrap extends TrapBase
{
	protected ref EffectSound m_TimerLoopSound;
	protected ref EffectSound m_DisarmingLoopSound;
	protected ref Timer m_DeleteTimer;
	
	private const int BROKEN_LEG_PROB = 90;
	private const int BLEED_SOURCE_PROB = 50;
	private const int MAX_BLEED_SOURCE = 1;
	
	private ref array<int> m_ClothingDmg;
	
	void LandMineTrap()
	{
		m_DefectRate = 15;
		m_DamagePlayers = 0; 			//How much damage player gets when caught
		m_InitWaitTime = 10; 			//After this time after deployment, the trap is activated
		//m_InfoActivationTime = "#STR_LandMineTrap0" + m_InitWaitTime.ToString() + "#STR_LandMineTrap1"; 
		m_InfoActivationTime = string.Format("#STR_LandMineTrap0%1#STR_LandMineTrap1", m_InitWaitTime.ToString());
		
		m_AddDeactivationDefect = true;
		
		//Order is important and must match clothing array in DamageClothing method
		m_ClothingDmg = new array<int>;
		m_ClothingDmg.Insert(60); 	//Trousers
		m_ClothingDmg.Insert(100);	//BackPack
		m_ClothingDmg.Insert(40);	//Vest
		m_ClothingDmg.Insert(10);	//HeadGear
		m_ClothingDmg.Insert(10);	//Mask
		m_ClothingDmg.Insert(40);	//Body
		m_ClothingDmg.Insert(50);	//Feet
		m_ClothingDmg.Insert(5);	//Gloves
	}
	
	void ~LandMineTrap()
	{
		if ( m_TimerLoopSound )
			SEffectManager.DestroySound(m_TimerLoopSound);
	}
		
	override void StartActivate( PlayerBase player )
	{
		super.StartActivate( player );
		
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			EffectSound sound = SEffectManager.PlaySound("landmine_safetyPin_SoundSet", GetPosition(), 0, 0, false);
			sound.SetSoundAutodestroy( true );
			m_TimerLoopSound = SEffectManager.PlaySound("landmine_timer2_SoundSet", GetPosition(), 0, 0, true);
		}
	}
	
	override void OnActivate()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if ( m_TimerLoopSound )
			{
				m_TimerLoopSound.SetSoundAutodestroy( true );
				m_TimerLoopSound.SoundStop();
			}
			
			if ( GetGame().GetPlayer() )
			{
				PlaySoundActivate();
			}
		}
	}
	
	override bool CanExplodeInFire()
	{
		return true;
	}
	
	override void OnSteppedOn( EntityAI victim )
	{
		if ( GetGame().IsServer() )
		{
			if ( !GetDisarmed() )
			{
				if ( victim )
				{
					//Check if we have a player
					PlayerBase victim_PB = PlayerBase.Cast( victim );
					if ( victim_PB && victim_PB.IsAlive() )
					{
						int randNum; //value used for probability evaluation
						randNum = Math.RandomInt(0, 100);
						if ( randNum <= BROKEN_LEG_PROB )
						{
							float damage = victim_PB.GetMaxHealth( "RightLeg", "" ); //deal 100% damage to break legs
							victim_PB.DamageAllLegs( damage ); 
						}
						
						randNum = Math.RandomInt(0, 100);
						if ( randNum < BLEED_SOURCE_PROB )
						{
							for ( int i = 0; i < MAX_BLEED_SOURCE; i++ )
							{
								//We add two bleeding sources max to lower half
								randNum = Math.RandomIntInclusive(0, PlayerBase.m_BleedingSourcesLow.Count() - 1);
						
								victim_PB.m_BleedingManagerServer.AttemptAddBleedingSourceBySelection(PlayerBase.m_BleedingSourcesLow[randNum]);
							}
						}
						
						DamageClothing( victim_PB );
					}
				}
				Explode( DT_EXPLOSION );
			}
			m_DeleteTimer = new Timer( CALL_CATEGORY_SYSTEM );
			m_DeleteTimer.Run( 2, this, "DeleteThis" );
		}
	}
	
	void DeleteThis()
	{
		GetGame().ObjectDelete( this );
	}
	
	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged( old_owner, new_owner );
		
		/*if ( g_Game.IsServer() )
		{
			
		}*/
	}
	
	override void EEKilled( Object killer )
	{
		super.EEKilled( killer );
		
		OnSteppedOn( NULL );
	}
	
	void PlaySoundActivate()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			EffectSound sound = SEffectManager.PlaySound("landmineActivate_SoundSet", GetPosition(), 0, 0, false);
			sound.SetSoundAutodestroy( true );
		}
	}
	
	override void Explode( int damageType, string ammoType = "" )
	{
		if (ammoType == "")
			ammoType = ConfigGetString("ammoType");
		
		if (ammoType == "")
			ammoType = "Dummy_Heavy";
		
		if ( GetGame().IsServer() )
		{
			SynchExplosion();
			vector offset = Vector(0, 0.1, 0); //Vertical offset applied to landmine explosion (in meters)
			DamageSystem.ExplosionDamage(this, NULL, ammoType, GetPosition() + offset, damageType); //Offset explosion on Y axis
		}
	}
	
	override bool CanBeClapped()
	{
		return true;
	}
	
	override bool CanBeDisarmed()
	{
		return true;
	}
	
	void DamageClothing( PlayerBase player )
	{
		//Get all currently equipped clothing
		// ---------------------------------------------

		ClothingBase trousers = 	ClothingBase.Cast(player.GetItemOnSlot("LEGS"));
		ClothingBase bag = 			ClothingBase.Cast(player.GetItemOnSlot("BACK"));
		ClothingBase vest = 		ClothingBase.Cast(player.GetItemOnSlot("VEST"));
		ClothingBase headGear =  	ClothingBase.Cast(player.GetItemOnSlot("HeadGear"));
		ClothingBase mask =  		ClothingBase.Cast(player.GetItemOnSlot("Mask"));
		ClothingBase shirt = 		ClothingBase.Cast(player.GetItemOnSlot("BODY"));
		ClothingBase shoes =  		ClothingBase.Cast(player.GetItemOnSlot("FEET"));
		ClothingBase gloves = 		ClothingBase.Cast(player.GetItemOnSlot("GLOVES"));

		//Array used to find all relevant information about currently equipped clothes
		array<ClothingBase> equippedClothes = new array<ClothingBase>;

		equippedClothes.Insert(trousers);
		equippedClothes.Insert(bag);
		equippedClothes.Insert(vest);
		equippedClothes.Insert(headGear);
		equippedClothes.Insert(mask);
		equippedClothes.Insert(shirt);
		equippedClothes.Insert(shoes);
		equippedClothes.Insert(gloves);

		// -----------------------------------------------
		
		int nbClothes = 0;

		//Damage all currently equipped clothes
		for ( int i = 0; i < equippedClothes.Count(); i++ )
		{
			//If no item is equipped on slot, slot is ignored
			if (equippedClothes[i] == null)
				continue;

			equippedClothes[i].DecreaseHealth(m_ClothingDmg[i], false);
			nbClothes++;
		}
	}
	
	override void OnRPC( PlayerIdentity sender, int rpc_type, ParamsReadContext ctx )
	{
		super.OnRPC(sender, rpc_type, ctx);
		
		ref Param1<bool> p = new Param1<bool>(false);
				
		if (ctx.Read(p))
		{
			bool play = p.param1;
		}
		
		switch (rpc_type)
		{
			case SoundTypeMine.DISARMING:
			
				if ( play )
				{
					PlayDisarmingLoopSound();
				}
				
				if ( !play )
				{
					StopDisarmingLoopSound();
				}
			
			break;
		}
	}
	
	void PlayDisarmingLoopSound()
	{
		if ( !m_DisarmingLoopSound || !m_DisarmingLoopSound.IsSoundPlaying() )
		{
			m_DisarmingLoopSound = SEffectManager.PlaySound( "landmine_deploy_SoundSet", GetPosition() );
		}
	}
	
	void StopDisarmingLoopSound()
	{
		m_DisarmingLoopSound.SoundStop();
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
		}
	}
	
	override bool IsDeployable()
	{
		return true;
	}
	
	override string GetLoopDeploySoundset()
	{
		return "landmine_deploy_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionActivateTrap);
		AddAction(ActionDeployObject);
	}
}
