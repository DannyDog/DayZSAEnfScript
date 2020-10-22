class TrapSpawnBase extends ItemBase
{
	int   m_InitWaitTime; 			//After this time after deployment, the trap is activated
	int   m_UpdateWaitTime; 		//Time when timer will be called again until success or not succes catch is done
	float m_DefectRate; 			//Added damage after trap activation
	bool m_NeedInstalation;			//If installation of trap is needed
	bool m_BaitNeeded;				//if bait is needed for sucessfull catch
	bool m_IsFoldable;
	bool m_IsUsable;
	float m_MinimalDistanceFromPlayersToCatch;

	private bool m_IsActive;
	private bool m_IsInProgress;
	
	ref Timer m_Timer;
	ref Timer m_PrevTimer;
	private ItemBase m_Catch;
	
	ref Timer m_AlignCatchTimer;

	string m_AnimationPhaseSet;
	string m_AnimationPhaseTriggered;
	string m_AnimationPhaseUsed;

	bool m_WaterSurfaceForSetup;	//if trap can be installed on water surface (cannot be detected via getsurfacetype)
	ref multiMap<string, float>	m_CatchesPond;	//array of catches that can be catched in trap - string key, float catch_chance, float minCatch, float maxCatch
	ref multiMap<string, float>	m_CatchesSea;	//array of catches that can be catched in trap - string key, float catch_chance, float minCatch, float maxCatch
	ref multiMap<string, float>	m_CatchesGroundAnimal;	//array of catches that can be catched in trap - string key, float catch_chance, float minCatch, float maxCatch
	string m_InfoSetup;

	ref protected EffectSound 	m_DeployLoopSound;
	
	void TrapSpawnBase()
	{
		m_DefectRate = 10; 			//Added damage after trap activation
		m_UpdateWaitTime = 0;
		m_IsInProgress = false;
		m_InitWaitTime = 99;
		m_NeedInstalation = true;
		m_BaitNeeded = false;
		m_InfoSetup = 				"#STR_TrapSpawnBase0";
		m_IsFoldable = false;
		m_IsUsable = false;
		m_MinimalDistanceFromPlayersToCatch = 0;

		m_AnimationPhaseSet = "";
		m_AnimationPhaseTriggered = "";
		m_AnimationPhaseUsed = "";
		
		m_CatchesPond = NULL;
		m_CatchesSea = NULL;
		m_CatchesGroundAnimal = NULL;
		
		m_PrevTimer = NULL;
		m_DeployLoopSound = new EffectSound;
		
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsDeploySound");
	}

	void ~TrapSpawnBase()
	{
		if ( m_DeployLoopSound )
		{
			SEffectManager.DestroySound( m_DeployLoopSound );
		}
	}

	//! this event is called all variables are synchronized on client
    override void OnVariablesSynchronized()
    {
        super.OnVariablesSynchronized();
		
		if ( IsDeploySound() )
		{
			PlayDeploySound();
		}
		
		if ( CanPlayDeployLoopSound() )
		{
			PlayDeployLoopSound();
		}
					
		if ( m_DeployLoopSound && !CanPlayDeployLoopSound() )
		{
			StopDeployLoopSound();
		}
	}
	
	bool IsActive()
	{
		if ( m_IsActive && m_IsInProgress == false )
		{
			return true;
		}
		return false;
	}

	override bool IsTakeable()
	{
		if ( g_Game.IsServer() )
		{
			CargoBase itemcargo = this.GetInventory().GetCargo();
			
			if (itemcargo)
			{
				int cargo_count = itemcargo.GetItemCount();
				if ( cargo_count > 0 )
				{
					return false;
				}
			}
		}
		return true;
	}

	bool IsPlaceable()
	{
		if ( g_Game.IsServer() )
		{
			if ( this.GetHierarchyRootPlayer() != NULL && this.GetHierarchyRootPlayer().GetHumanInventory().GetEntityInHands() == this )
			{
				PlayerBase player = PlayerBase.Cast( this.GetHierarchyRootPlayer() );
				
				vector player_pos = player.GetPosition();
				vector aim_pos = player.GetAimPosition();
				
				if ( vector.Distance(player_pos, aim_pos) <= 1.5 )
				{
					return IsPlaceableAtPosition( aim_pos );
				}
			}
		}
		
		return false;
	}

	bool IsPlaceableAtPosition( vector position )
	{
		string surface_type;
		GetGame().SurfaceGetType(position[0], position[2], surface_type);

		// check water (sea) surface
		if ( m_WaterSurfaceForSetup && GetGame().SurfaceIsSea( position[0], position[2] ) )
		{
			return true;
		}

		// check water (pond) surface
		if ( m_WaterSurfaceForSetup && GetGame().SurfaceIsPond( position[0], position[2] ) )
		{
			return true;
		}
		// SmallFishTrap is amphibious, on water serves as a fish trap, on surface serves as rain procurement vesel
		if ( IsKindOf("SmallFishTrap") )
		{
			if ( !GetGame().SurfaceIsPond( position[0], position[2] ) &&  !GetGame().SurfaceIsSea( position[0], position[2] ) )
			{
				return true;
			} 
		}
		
		// check surface
		return GetGame().IsSurfaceDigable(surface_type);
	}

	void SetupTrap()
	{ 
		if ( GetGame().IsServer() )
		{
			if ( this.GetHierarchyRootPlayer() && this.GetHierarchyRootPlayer().CanDropEntity( this) )  // kvoli desyncu
			{
				SetupTrapPlayer( PlayerBase.Cast( this.GetHierarchyRootPlayer() ) );
			}
		}
	}

	void SetupTrapPlayer( PlayerBase player, bool set_position = true )
	{ 
		if ( GetGame().IsServer() )
		{
			if ( this.IsRuined() ) 
			{
				player.MessageImportant( "The trap is ruined." );
			}
			else
			{
				if ( set_position )
				{
					Error("Mojmir: TODO");
					player.LocalDropEntity( this );

					vector trapPos = ( player.GetDirection() * 1.5 );
					trapPos[1] = 0;
					this.SetPosition( player.GetPosition() + trapPos );
				}
				
				player.MessageStatus( m_InfoSetup );

				SetActive();
			}
		}
	}
	
	void Fold()
	{
		if ( g_Game.IsServer() && m_IsFoldable == true )
		{
			SetInactive();
		}
	}

	void AddDefect()
	{
		if ( g_Game.IsServer() )
		{
			this.DecreaseHealth( "", "", m_DefectRate);
		}
	}
	
	void StartActivate( PlayerBase player )
	{
	}
	
	void SetActive()
	{
		if ( g_Game.IsServer() && m_IsActive == false )
		{
			m_IsInProgress = false;
			m_IsActive = true;

			this.AddDefect();
			if ( m_AnimationPhaseSet != "" && m_AnimationPhaseTriggered != "" )
			{
				this.SetAnimationPhase( m_AnimationPhaseSet, 1 );
				this.SetAnimationPhase( m_AnimationPhaseTriggered, 0 );
				this.SetAnimationPhase( m_AnimationPhaseUsed, 1 );
			}

			m_Timer = new Timer( CALL_CATEGORY_GAMEPLAY );
			m_Timer.Run( m_InitWaitTime, this, "SpawnCatch" );
		}
	}

	void SetInactive()
	{
		if ( g_Game.IsServer() )
		{
			if ( this.IsActive() )
			{
				this.AddDefect();
			}
			m_IsActive = false;
			if ( m_Timer )
			{
				m_Timer.Stop();
			}
			if ( m_AnimationPhaseSet != "" && m_AnimationPhaseTriggered != "" && !m_IsUsable )
			{
				this.SetAnimationPhase( m_AnimationPhaseSet, 0 );
				this.SetAnimationPhase( m_AnimationPhaseTriggered, 1 );
				this.SetAnimationPhase( m_AnimationPhaseUsed, 1 );
			}
		}
	}

	void SetUsed()
	{
		if ( g_Game.IsServer() )
		{
			if ( this.IsActive() )
			{
				this.AddDefect();
			}
			m_IsActive = false;
			if ( m_Timer )
			{
				m_Timer.Stop();
			}
			if ( m_AnimationPhaseSet != "" && m_AnimationPhaseTriggered != "" )
			{
				this.SetAnimationPhase( m_AnimationPhaseSet, 1 );
				this.SetAnimationPhase( m_AnimationPhaseTriggered, 1 );
				this.SetAnimationPhase( m_AnimationPhaseUsed, 0 );
			}
		}
	}
	
	void SpawnCatch()
	{
		if ( g_Game.IsServer() )
		{
			if ( m_MinimalDistanceFromPlayersToCatch > 0 && m_UpdateWaitTime > 0 )
			{
				m_PrevTimer = m_Timer;
				m_Timer = new Timer( CALL_CATEGORY_GAMEPLAY );
				m_Timer.Run( m_UpdateWaitTime, this, "SpawnCatch" );
			}

			int i;
			bool canCatch = false;

			if ( m_BaitNeeded )
			{
				CargoBase itemcargo = this.GetInventory().GetCargo();
				int cargo_count = itemcargo.GetItemCount();

				if ( itemcargo && cargo_count > 0 )
				{
					for ( i = 0; i < cargo_count; i++ )
					{
						InventoryItem ii = InventoryItem.Cast( itemcargo.GetItem(i) );
						string tmp;
						GetGame().ObjectGetType (ii, tmp);

						// if bait is needed and correct bait is used, spawn catch
						if ( tmp == "Food_Worm" ||  tmp == "Consumable_Bait" )	//todo: set food in table params
						{
							// delete bait
							g_Game.ObjectDelete( ii );
							if ( ii.GetHealth("", "") > 60 )
							{
								canCatch = true;
							}
						}
					}
				}
			}
			else
			{
				canCatch = true;
			}
			
			if ( m_MinimalDistanceFromPlayersToCatch > 0 )
			{
				ref array<Man> players = new array<Man>;
				g_Game.GetWorld().GetPlayerList( players );
					
				bool minimal_distance_ok = true;	
					
				for ( i = 0; i < players.Count(); i++ )
				{
					if ( vector.Distance(players.Get(i).GetPosition(), this.GetPosition()) < m_MinimalDistanceFromPlayersToCatch )
					{
						minimal_distance_ok = false;
						break;
					}
				}
				
				if ( !minimal_distance_ok && canCatch )
				{
					canCatch = false;
				}
			}
			
			if ( canCatch )
			{
				float surface_chance_for_catch = 1.0;
				
				multiMap<string, float>	catches;
				vector pos = GetPosition();
				if ( m_WaterSurfaceForSetup )
				{
					if ( g_Game.SurfaceIsSea( pos[0], pos[2] ) ) 
					{
						catches = m_CatchesSea;
					}
					else if ( g_Game.SurfaceIsPond( pos[0], pos[2] ) ) 
					{
						catches = m_CatchesPond;
					}
				}
				else
				{
					string surface_type;
					GetGame().SurfaceGetType(pos[0], pos[2], surface_type);
					
					surface_chance_for_catch = GetGame().ConfigGetFloat("CfgSurfaces " + surface_type + " chanceForCatch");
					
					catches = m_CatchesGroundAnimal;
				}

				if ( catches && catches.Count() > 0 )
				{
					// create catch in move to cargo
					// select random object from catches
					int count = catches.Count() - 1;
					int randomCatchIndex = Math.RandomInt( 0, count );
				
					float chance_for_catch = surface_chance_for_catch * catches.GetByIndex ( randomCatchIndex ).Get(0);
				
					if ( chance_for_catch > Math.RandomFloat(0, 1) )
					{
						// how many catches random(min,max)
						int minQuantity = catches.GetByIndex ( randomCatchIndex ).Get(1);
						int maxQuantity = catches.GetByIndex ( randomCatchIndex ).Get(2);
						int quantityCatch =  Math.RandomInt( minQuantity, maxQuantity );

						if ( quantityCatch > 0 )
						{
							for (int iii = 0; iii < quantityCatch; iii++)
							{			
								if ( catches != m_CatchesGroundAnimal )
								{
									m_Catch = ItemBase.Cast( g_Game.CreateObjectEx( catches.GetKeyByIndex(randomCatchIndex), this.GetPosition(), ECE_PLACE_ON_SURFACE ) );
									m_Catch.SetQuantity( m_Catch.GetQuantityMax() );
									Error("Mojmir - TODO");
									//this.SynchronizedTakeEntityToCargo( true, m_Catch );
								}
								else 
								{
									m_Catch = ItemBase.Cast( g_Game.CreateObject( catches.GetKeyByIndex(randomCatchIndex), this.GetPosition(), false, true ) );
									m_Catch.SetHealth( "", "", 0 );
									
									m_AlignCatchTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
									m_AlignCatchTimer.Run( 2, this, "AlignCatch", new Param2<ItemBase, string>(m_Catch, catches.GetKeyByIndex(randomCatchIndex)), false );
									
									SetInactive();
								}
							}
						}
					}
					else if ( m_IsUsable )
					{
						SetUsed();
					}
				}
				
				if ( !m_IsUsable )
				{
					SetInactive();
				}
			}
		}
	}

	void AlignCatch( ItemBase obj, string catch_name )
	{

	}

	override void OnItemLocationChanged  ( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged(old_owner, new_owner);
		
		if ( g_Game.IsServer() )
		{
			// throw trap from vicinity
			if ( new_owner == NULL && m_NeedInstalation == false )
			{
				SetActive();
			}
			else if ( old_owner == NULL && new_owner != NULL )
			{
				if ( m_IsFoldable )
				{
					Fold();
				}
				else
				{
					SetInactive();
				}
			}

		}
	}

	override bool CanBePlaced( Man player, vector position )
	{
		return IsPlaceableAtPosition( position );
	}

	override string CanBePlacedFailMessage( Man player, vector position )
	{
		return "Trap can't be placed on this surface type.";
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		if ( GetGame().IsServer() )
		{
			SetupTrapPlayer( PlayerBase.Cast( player ), false );
			
			SetIsDeploySound( true );
		}	
	}
	
	void PlayDeployLoopSound()
	{		
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{		
			if ( !m_DeployLoopSound.IsSoundPlaying() )
			{
				m_DeployLoopSound = SEffectManager.PlaySound( GetLoopDeploySoundset(), GetPosition() );
			}
		}
	}
	
	void StopDeployLoopSound()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{	
			m_DeployLoopSound.SetSoundFadeOut(0.5);
			m_DeployLoopSound.SoundStop();
		}
	}
}
