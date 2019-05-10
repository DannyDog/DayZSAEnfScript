class Spotlight extends ItemBase
{
	private bool	m_IsFolded;
	SpotlightLight 	m_Light;
	
	static vector 	m_LightLocalPosition 	= "0 1.50668 0.134863";
	static vector 	m_LightLocalOrientation = "0 0 0";
	
	// Spotlight can be extended and compressed
	static const string SEL_REFLECTOR_COMP_U 		= "reflector";
	static const string SEL_CORD_FOLDED_U 			= "cord_folded";
	static const string SEL_CORD_PLUGGED_U 			= "cord_plugged";
	static const string SEL_CORD_PLUGGED_F 			= "spotlight_folded_cord_plugged";
	static const string SEL_CORD_FOLDED_F 			= "spotlight_folded_cord_folded";
	
	static const string SEL_INVENTORY 				= "inventory";
	static const string SEL_PLACING 				= "placing";
	static const string SEL_GLASS_F 				= "glass_folded";
	static const string SEL_GLASS_U 				= "glass_unfolded";
	static const string SEL_REFLECTOR_F				= "reflector_folded";
	static const string SEL_REFLECTOR_U				= "reflector_unfolded";
	
	static const int 	ID_GLASS					= 3;
	static const int 	ID_REFLECTOR				= 4;
	
	static string 		LIGHT_OFF_GLASS 			= "dz\\gear\\camping\\Data\\spotlight_glass.rvmat";
	static string 		LIGHT_OFF_REFLECTOR 		= "dz\\gear\\camping\\Data\\spotlight.rvmat";
	static string 		LIGHT_ON_GLASS 				= "dz\\gear\\camping\\Data\\spotlight_glass_on.rvmat";
	static string 		LIGHT_ON_REFLECTOR 			= "dz\\gear\\camping\\Data\\spotlight_glass_on.rvmat";
	
	//sound
	const string 				SOUND_TURN_ON		= "spotlight_turn_on_SoundSet";
	const string 				SOUND_TURN_OFF		= "spotlight_turn_off_SoundSet";
	
	protected EffectSound 		m_SoundTurnOn;
	protected EffectSound 		m_SoundTurnOff;	
	
	ref protected EffectSound 	m_DeployLoopSound;

	/*
		Spotlight, folded and unfolded.
	*/
	
	void Spotlight()
	{
		m_DeployLoopSound = new EffectSound;
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsDeploySound");
	}
	
	void ~Spotlight()
	{
		if ( m_DeployLoopSound )
		{
			SEffectManager.DestroySound( m_DeployLoopSound );
		}
	}
	
	override void OnInitEnergy()
	{
		if ( GetCompEM().IsPlugged() )
			Unfold();
		else
			Fold();
		
		UpdateAllSelections();
	}
	
	override void EOnInit(IEntity other, int extra)
	{
		super.EOnInit(other, extra);
		
		if ( !IsHologram() )
		{
			UpdateAllSelections();
			HideSelection(SEL_CORD_FOLDED_F);
		}
	}
	
	//--- POWER EVENTS
	override void OnSwitchOn()
	{
		super.OnSwitchOn();
		
		//sound (client only)
		SoundTurnOn();
	}

	override void OnSwitchOff()
	{
		super.OnSwitchOff();
		
		//sound (client only)
		SoundTurnOff();
		
		if (m_Light)
		{
			m_Light.FadeOut(0.05);
			m_Light = null;
		}
	}
	
	override void OnWorkStart()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // client side
		{
			m_Light = SpotlightLight.Cast( ScriptedLightBase.CreateLight( SpotlightLight, "0 0 0") );
			m_Light.AttachOnObject(this, m_LightLocalPosition, m_LightLocalOrientation);
			
			
		}
		
		SetObjectMaterial(ID_GLASS, LIGHT_ON_GLASS);
		SetObjectMaterial(ID_REFLECTOR, LIGHT_ON_REFLECTOR);
	}
	
	/*override void OnWork(float consumed_energy)
	{
			
		}*/

	override void OnWorkStop()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() ) // client side
		{
			if (m_Light)
				m_Light.FadeOut();
			
		}
		
		SetObjectMaterial(ID_GLASS, LIGHT_OFF_GLASS);
		SetObjectMaterial(ID_REFLECTOR, LIGHT_OFF_REFLECTOR);
	}
	
	// Called when this device is picked up
	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged(old_owner, new_owner);
		
		// When the item is picked up by a player
		if (new_owner)
		{
			Fold();
		}
	}

	override void OnIsPlugged(EntityAI source_device)
	{
		Unfold();
		UpdateAllSelections();
	}
	
	void UpdateAllSelections()
	{
		bool is_plugged = GetCompEM().IsPlugged();
		HideAllSelections();
		
		if ( IsFolded() )
		{
			HideSelection( SEL_REFLECTOR_COMP_U );
			
			ShowSelection( SEL_INVENTORY );
			ShowSelection( SEL_GLASS_F );
			ShowSelection( SEL_REFLECTOR_F );
			
			if (is_plugged)
			{
				ShowSelection( SEL_CORD_PLUGGED_F );
			}
			else
			{
				ShowSelection( SEL_CORD_FOLDED_F );
			}
		}
		else
		{
			ShowSelection( SEL_PLACING );
			ShowSelection( SEL_REFLECTOR_U );
			ShowSelection( SEL_GLASS_U );
			ShowSelection( SEL_REFLECTOR_COMP_U );
			
			if (is_plugged)
			{
				ShowSelection( SEL_CORD_PLUGGED_U );
			}
			else
			{
				ShowSelection( SEL_CORD_FOLDED_U );
			}
		}
	}
	
	override void OnIsUnplugged( EntityAI last_energy_source )
	{
		UpdateAllSelections();
	}

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

	void Fold()
	{
		m_IsFolded = true;
		GetCompEM().SwitchOff();
		GetCompEM().UnplugThis();
		
		UpdateAllSelections();
	}

	void Unfold()
	{
		m_IsFolded = false;
		
		UpdateAllSelections();
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{   
		super.OnStoreSave(ctx);
		
		// Save folded/unfolded state
		ctx.Write( m_IsFolded );
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{   
		if ( !super.OnStoreLoad(ctx, version) )
			return false;
		
		// Load folded/unfolded state
		bool b_is_folded = false;
		if (!ctx.Read(b_is_folded))
			b_is_folded = true;
		
		if (b_is_folded)
		{
			Fold();
		}
		else
		{
			Unfold();
		}

		return true;
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}
		// Commented out so Reposition action is possible to execute
		return true; //GetCompEM().IsCordFolded(); 
	}

	override bool CanPutIntoHands ( EntityAI player ) 
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		// Commented out so Reposition action is possible to execute
		return true; //GetCompEM().IsCordFolded();
	}

	bool IsFolded()
	{
		return m_IsFolded;
	}
	
	//================================================================
	// SOUNDS
	//================================================================
	protected void SoundTurnOn()
	{
		PlaySoundSet( m_SoundTurnOn, SOUND_TURN_ON, 0, 0 );
	}
	
	protected void SoundTurnOff()
	{
		PlaySoundSet( m_SoundTurnOff, SOUND_TURN_OFF, 0, 0 );
	}		
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
		
	override void OnPlacementStarted( Man player )
	{
		super.OnPlacementStarted( player );
		
		ref array<string> array_of_selections = {SEL_CORD_PLUGGED_U, SEL_CORD_FOLDED_U};
		PlayerBase player_PB = PlayerBase.Cast( player );
				
		if( GetGame().IsMultiplayer() && GetGame().IsServer() )
		{
			player_PB.GetHologramServer().SetSelectionToRefresh( array_of_selections );		
		}
		else
		{
			player_PB.GetHologramLocal().SetSelectionToRefresh( array_of_selections );
		}
	}
		
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
		return "placeSpotlight_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "spotlight_deploy_SoundSet";
	}
	
	void PlayDeployLoopSound()
	{		
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{		
			m_DeployLoopSound = SEffectManager.PlaySound( GetLoopDeploySoundset(), GetPosition());
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
		
		AddAction(ActionClapBearTrapWithThisItem);
		AddAction(ActionPlugIn);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionUnplugThisByCord);
		AddAction(ActionTurnOnSpotlight);
		AddAction(ActionTurnOffSpotlight);
		AddAction(ActionRepositionPluggedItem);
		AddAction(ActionDeployObject);
	}
}