class HescoBox extends Inventory_Base
{
	static const int FOLDED 		= 0;
	static const int UNFOLDED 		= 1;
	static const int FILLED 		= 2;
	
	static ref array<string> 		m_SurfaceForSetup;
	ref Timer 						m_Timer;
	ref protected EffectSound 		m_DeployLoopSound;

	protected int m_State;
	
	void HescoBox()
	{
		m_State = FOLDED;
		m_DeployLoopSound = new EffectSound;
		
		if (!m_SurfaceForSetup)
		{
			m_SurfaceForSetup = new array<string>;
			InsertMaterialForSetup();
		}
		
		//synchronized variables
		RegisterNetSyncVariableInt( "m_State", FOLDED, FILLED );
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsDeploySound");
	}
	
	void ~HescoBox()
	{
		if ( m_DeployLoopSound )
		{
			SEffectManager.DestroySound( m_DeployLoopSound );
		}
	}

	override bool CanPutIntoHands( EntityAI parent )
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		return CanBeManipulated();
	}
		
	void Synchronize()
	{
		SetSynchDirty();
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		//refresh visuals
		RefreshVisuals();
				
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
	
	void RefreshVisuals()
	{
		if( GetState() == UNFOLDED )
		{
			InsertMaterialForSetup();
		}
	}

	int GetState()
	{
		return m_State;
	}
	
	void SetState( int state )
	{
		m_State = state;
	}

	bool CanBeFilledAtPosition( vector position )
	{
		string surface_type;
		GetGame().SurfaceGetType( position[0], position[2], surface_type );

		if ( m_SurfaceForSetup.Find(surface_type) > -1 )
		{
			return true;
		}
		
		return false;
	}

	bool CanBeManipulated()
	{
		if ( GetState() == FOLDED )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void Fold()
	{
		this.ShowSelection( "inventory" );
		this.HideSelection( "placing" );
		this.HideSelection( "filled" );
		
		SetState( FOLDED );
		RefreshPhysics();
		
		if ( GetGame().IsServer() )
		{
			SetAllowDamage(true);
			Synchronize();
			DecreaseHealth( "", "", 5 ); //TODO Daniel implement soft skill bonus via useraction
		}
	}

	void Unfold()
	{
		this.HideSelection( "inventory" );
		this.ShowSelection( "placing" );
		this.HideSelection( "filled" );
		
		InsertMaterialForSetup();
		SetState( UNFOLDED );
		RefreshPhysics();
		
		if ( GetGame().IsServer() )
		{
			SetAllowDamage(true);
			Synchronize();
			DecreaseHealth( "", "", 5 ); //TODO Daniel implement soft skill bonus via useraction
		}
	}

	override void EEItemLocationChanged (notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged (oldLoc, newLoc);
		
		RefreshPhysics();
	}
	
	void RefreshPhysicsDelayed()
	{
		if ( this  &&  !ToDelete() )
		{
			RemoveProxyPhysics( "inventory" );
			RemoveProxyPhysics( "placing" );
			RemoveProxyPhysics( "filled" );
			
			int state = GetState();
			
			switch (state)
			{
				case UNFOLDED:
					//ShowSelection( "placing" );
					AddProxyPhysics( "placing" ); 
					
				return;
				
				case FOLDED:
					AddProxyPhysics( "inventory" ); 
				return;
				
				case FILLED:
					AddProxyPhysics( "filled" ); 
				return;
			}
		}
	}
	
	void RefreshPhysics()
	{
		if (!m_Timer)
			m_Timer = new Timer( CALL_CATEGORY_SYSTEM );
		
		m_Timer.Run(0.1, this, "RefreshPhysicsDelayed");
	}
	
	void InsertMaterialForSetup()
	{	
		m_SurfaceForSetup.Insert("cp_dirt");
		m_SurfaceForSetup.Insert("cp_broadleaf_dense1");
		m_SurfaceForSetup.Insert("cp_broadleaf_dense2");
		m_SurfaceForSetup.Insert("cp_broadleaf_sparse1");
		m_SurfaceForSetup.Insert("cp_broadleaf_sparse2");
		m_SurfaceForSetup.Insert("cp_conifer_common1");
		m_SurfaceForSetup.Insert("cp_conifer_common2");
		m_SurfaceForSetup.Insert("cp_conifer_moss1");
		m_SurfaceForSetup.Insert("cp_conifer_moss2");
		m_SurfaceForSetup.Insert("cp_grass");
		m_SurfaceForSetup.Insert("cp_grass_tall");
		m_SurfaceForSetup.Insert("cp_gravel");
	}

	void Fill()
	{
		this.HideSelection( "inventory" );
		this.HideSelection( "placing" );
		this.ShowSelection( "filled" );
		
		SetState( FILLED );
		RefreshPhysics();
		
		if ( GetGame().IsServer() )
		{
			Synchronize();
			DecreaseHealth( "", "", 5 ); //TODO Daniel implement soft skill bonus via useraction
			SetAllowDamage(false);
		}
	}
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{   
		super.OnStoreSave(ctx);
		
		// Save state
		ctx.Write( m_State );
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{   
		if ( !super.OnStoreLoad(ctx, version) )
			return false;
		
		// Load folded/unfolded state
		int state = FOLDED;
		if ( !ctx.Read(state) )
			state = FOLDED;
		
		switch (state)
		{
			case FOLDED:
			{
				Fold();
				break;
			}
			case UNFOLDED:
			{
				Unfold();
				break;
			}
			case FILLED:
			{
				Fill();
				break;
			}
		}
		return true;
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementComplete( Man player )
	{
		super.OnPlacementComplete( player );
		
		if ( GetGame().IsServer() )
		{
			Unfold();
			
			SetIsDeploySound( true );
		}
	}
		
	override bool IsDeployable()
	{
		return true;
	}

	override string GetDeploySoundset()
	{
		return "placeHescoBox_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "hescobox_deploy_SoundSet";
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
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionFoldObject);
		AddAction(ActionDeployObject);
	}
}
