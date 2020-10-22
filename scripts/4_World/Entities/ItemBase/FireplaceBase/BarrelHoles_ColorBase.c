class BarrelHoles_ColorBase extends FireplaceBase
{
	//Visual animations
	const string ANIMATION_OPENED 			= "LidOff";
	const string ANIMATION_CLOSED			= "LidOn";
	
	protected bool m_IsOpenedClient			= false;

	protected ref OpenableBehaviour m_Openable;
	
	void BarrelHoles_ColorBase()
	{
		//Particles - default for FireplaceBase
		PARTICLE_FIRE_START 	= ParticleList.BARREL_FIRE_START;
		PARTICLE_SMALL_FIRE 	= ParticleList.BARREL_SMALL_FIRE;
		PARTICLE_NORMAL_FIRE	= ParticleList.BARREL_NORMAL_FIRE;
		PARTICLE_SMALL_SMOKE 	= ParticleList.BARREL_SMALL_SMOKE;
		PARTICLE_NORMAL_SMOKE	= ParticleList.BARREL_NORMAL_SMOKE;
		PARTICLE_FIRE_END 		= ParticleList.BARREL_FIRE_END;
		PARTICLE_STEAM_END		= ParticleList.BARREL_FIRE_STEAM_2END;

		m_Openable = new OpenableBehaviour(false);
		
		//synchronized variables
		RegisterNetSyncVariableBool("m_Openable.m_IsOpened");
		
		ProcessInvulnerabilityCheck("disableContainerDamage");
		
		m_LightDistance = 50;
	}
	
	override int GetDamageSystemVersionChange()
	{
		return 110;
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		//hide in inventory
		//GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}
	
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
		
		ctx.Write( m_Openable.IsOpened() );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		bool opened;
		if ( version >= 110 && !ctx.Read( opened ) )
		{
			return false;
		}
		
		if ( opened )
		{
			Open();
		}
		else
		{
			Close();
		}
		
		return true;
	}
	
	override bool IsBarrelWithHoles()
	{
		return true;
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( !IsBeingPlaced() )
		{
			//Refresh particles and sounds
			RefreshFireParticlesAndSounds( false );
						
			//sound sync
			if ( IsOpen() && IsSoundSynchRemote() )
			{
				SoundBarrelOpenPlay();
			}
			
			if ( !IsOpen() && IsSoundSynchRemote() )
			{
				SoundBarrelClosePlay();
			}
		}

		UpdateVisualState();
	}
	
	//ATTACHMENTS
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		ItemBase item = ItemBase.Cast( attachment );
		
		if ( GetHealthLevel() == GameConstants.STATE_RUINED || GetHierarchyRootPlayer() != null )
			return false;

		//direct cooking slots
		if ( !IsOpen() )
		{
			if ( ( item.Type() == ATTACHMENT_COOKING_POT ) || ( item.Type() == ATTACHMENT_FRYING_PAN ) || ( item.IsKindOf( "Edible_Base" ) ) )
			{
				return super.CanReceiveAttachment(attachment, slotId);
			}
		}
		else
		{
			if ( IsKindling( item ) || IsFuel( item ) )
			{
				return super.CanReceiveAttachment(attachment, slotId);
			}
		}

		return false;
	}
	
	override bool CanLoadAttachment( EntityAI attachment )
	{
		ItemBase item = ItemBase.Cast( attachment );
		
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;

		if ( ( item.Type() == ATTACHMENT_COOKING_POT ) || ( item.Type() == ATTACHMENT_FRYING_PAN ) || ( item.IsKindOf( "Edible_Base" ) ) || IsKindling( item ) || IsFuel( item ) )
			return super.CanLoadAttachment(attachment);

		return false;
	}

	override bool CanReleaseAttachment( EntityAI attachment )
	{
		if( !super.CanReleaseAttachment( attachment ) )
			return false;
		
		ItemBase item = ItemBase.Cast( attachment );
		//kindling items
		if ( IsKindling ( item ) && !IsBurning() && IsOpen() )
		{
			if ( HasLastFuelKindlingAttached() )
			{
				if ( HasLastAttachment() )
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return true;
			}
		}
		
		//fuel items
		if ( IsFuel ( item ) && !IsBurning() && IsOpen() )
		{
			if ( HasLastFuelKindlingAttached() )
			{	
				if ( HasLastAttachment() )
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return true;
			}
		}
		
		//direct cooking slots
		if ( ( item.Type() == ATTACHMENT_COOKING_POT ) || ( item.Type() == ATTACHMENT_FRYING_PAN ) || ( item.IsKindOf( "Edible_Base" ) ) )
		{
			return true;
		}
		
		return false;
	}

	override void EEItemAttached ( EntityAI item, string slot_name ) 
	{
		super.EEItemAttached( item, slot_name );
		
		ItemBase item_base = ItemBase.Cast( item );
		
		//kindling / fuel
		if ( IsKindling ( item_base ) || IsFuel ( item_base ) )
		{
			//add to consumables
			AddToFireConsumables ( item_base );
		}
		
		// direct cooking slots
		switch ( slot_name )
		{
			case "DirectCookingA":
				m_DirectCookingSlots[0] = item_base;
				break;

			case "DirectCookingB":
				m_DirectCookingSlots[1] = item_base;
				break;

			case "DirectCookingC":
				m_DirectCookingSlots[2] = item_base;
				break;
		}

		// smoking slots
		switch ( slot_name )
		{
			case "SmokingA":
				m_SmokingSlots[0] = item_base;
				break;

			case "SmokingB":
				m_SmokingSlots[1] = item_base;
				break;

			case "SmokingC":
				m_SmokingSlots[2] = item_base;
				break;

			case "SmokingD":
				m_SmokingSlots[3] = item_base;
				break;
		}

		//refresh fireplace visuals
		RefreshFireplaceVisuals();
	}

	override void EEItemDetached ( EntityAI item, string slot_name ) 
	{
		super.EEItemDetached ( item, slot_name );
		
		ItemBase item_base = ItemBase.Cast( item );
		
		//kindling / fuel
		if ( IsKindling ( item_base ) || IsFuel ( item_base ) )
		{
			//remove from consumables
			RemoveFromFireConsumables ( GetFireConsumableByItem( item_base ) );
		}
		
		// direct cooking slots
		switch ( slot_name )
		{
			case "DirectCookingA":
				m_DirectCookingSlots[0] = NULL;
				break;

			case "DirectCookingB":
				m_DirectCookingSlots[1] = NULL;
				break;

			case "DirectCookingC":
				m_DirectCookingSlots[2] = NULL;
				break;
		}

		// smoking slots
		switch ( slot_name )
		{
			case "SmokingA":
				m_SmokingSlots[0] = NULL;
				break;

			case "SmokingB":
				m_SmokingSlots[1] = NULL;
				break;

			case "SmokingC":
				m_SmokingSlots[2] = NULL;
				break;

			case "SmokingD":
				m_SmokingSlots[3] = NULL;
				break;
		}

		// food on direct cooking slots (removal of sound effects)
		if ( item_base.IsKindOf( "Edible_Base" ) )
		{
			Edible_Base food_on_dcs = Edible_Base.Cast( item_base );
			food_on_dcs.MakeSoundsOnClient( false );
		}

		// cookware-specifics (remove audio visuals)
		if ( item_base.Type() == ATTACHMENT_COOKING_POT )
		{	
			Bottle_Base cooking_pot = Bottle_Base.Cast( item );
			cooking_pot.RemoveAudioVisualsOnClient();	
		}
		if ( item_base.Type() == ATTACHMENT_FRYING_PAN )
		{	
			FryingPan frying_pan = FryingPan.Cast( item );
			frying_pan.RemoveAudioVisualsOnClient();
		}

		//refresh fireplace visuals
		RefreshFireplaceVisuals();
	}
	
	//CONDITIONS
	//this into/outo parent.Cargo
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo( parent ) )
		{
			return false;
		}
		return false;
	}

	override bool CanRemoveFromCargo( EntityAI parent )
	{
		return true;
	}

	//cargo item into/outo this.Cargo
	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;

		if ( !IsOpen() || GetHierarchyParent() )
			return false;

		return super.CanReceiveItemIntoCargo( item );
	}
	
	override bool CanLoadItemIntoCargo( EntityAI item )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;

		if ( GetHierarchyParent() )
			return false;

		return super.CanLoadItemIntoCargo( item );
	}

	override bool CanReleaseCargo( EntityAI cargo )
	{
		return IsOpen();
	}
	
	//hands
	override bool CanPutIntoHands( EntityAI parent )
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		if ( IsBurning() || !IsCargoEmpty() || DirectCookingSlotsInUse() || IsOpen() )
		{
			return false;
		}
		
		return true;
	}
	
	//INVENTORY DISPLAY CONDITIONS
	override bool CanDisplayCargo()
	{
		//super
		if( !super.CanDisplayCargo() )
		{
			return false;
		}
		//
		
		return IsOpen();
	}

	override bool CanDisplayAttachmentCategory( string category_name )
	{
		//super
		if( !super.CanDisplayAttachmentCategory( category_name ) )
		{
			return false;
		}
		//
		
		if ( ( category_name == "CookingEquipment" ) || ( category_name == "Smoking" ) )
		{
			return !IsOpen();
		}			
		else
		{
			return IsOpen();
		}
		
		return true;
	}	
	// ---	

	//ACTIONS
	override void Open()
	{
		m_Openable.Open();
		//GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		
		m_RoofAbove = false;
		
		SoundSynchRemote();
		//SetSynchDirty(); //! called also in SoundSynchRemote - TODO
		UpdateVisualState();
	}
	
	override void Close()
	{
		m_Openable.Close();
		//GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
		
		m_RoofAbove = true;
		
		SoundSynchRemote();
		//SetSynchDirty(); //! called also in SoundSynchRemote - TODO
		UpdateVisualState();
	}
	
	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}
	
	protected void UpdateVisualState()
	{
		if ( IsOpen() )
		{
			SetAnimationPhase( ANIMATION_OPENED, 0 );
			SetAnimationPhase( ANIMATION_CLOSED, 1 );
		}
		else
		{
			SetAnimationPhase( ANIMATION_OPENED, 1 );
			SetAnimationPhase( ANIMATION_CLOSED, 0 );
		}
	}
	
	//Can extinguish fire
	override bool CanExtinguishFire()
	{
		if ( IsOpen() && IsBurning() )
		{
			return true;
		}
		
		return false;
	}	
	
	//particles
	override bool CanShowSmoke()
	{
		return IsOpen();
	}
	
	// Item-to-item fire distribution
	override bool HasFlammableMaterial()
	{
		return true;
	}
	
	override bool CanBeIgnitedBy( EntityAI igniter = NULL )
	{
		if ( HasAnyKindling() && !IsBurning() && IsOpen() && !GetHierarchyParent() )
		{
			return true;
		}
			
		return false;
	}
	
	override bool CanIgniteItem( EntityAI ignite_target = NULL )
	{
		if ( IsBurning() && IsOpen() )
		{
			return true;
		}
		
		return false;
	}
	
	override bool IsIgnited()
	{
		return IsBurning();
	}
	
	override void OnIgnitedTarget( EntityAI ignited_item )
	{
	}
	
	override void OnIgnitedThis( EntityAI fire_source )
	{	
		//remove grass
		Object cc_object = GetGame().CreateObjectEx( OBJECT_CLUTTER_CUTTER , GetPosition(), ECE_PLACE_ON_SURFACE );
		cc_object.SetOrientation ( GetOrientation() );
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( DestroyClutterCutter, 0.2, false, cc_object );
		
		//start fire
		StartFire(); 
	}

	void SoundBarrelOpenPlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "barrel_open_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
	
	void SoundBarrelClosePlay()
	{
		EffectSound sound =	SEffectManager.PlaySound( "barrel_close_SoundSet", GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
	
	void DestroyClutterCutter( Object clutter_cutter )
	{
		GetGame().ObjectDelete( clutter_cutter );
	}	
	
	override bool IsThisIgnitionSuccessful( EntityAI item_source = NULL )
	{
		//check kindling
		if ( !HasAnyKindling() && IsOpen() )
		{
			return false;
		}
		
		//check roof
		/*if ( !IsCeilingHighEnoughForSmoke() && IsOnInteriorSurface() )
		{
			return false;
		}*/
		
		//check surface
		if ( IsOnWaterSurface() )
		{
			return false;
		}

		return true;	
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override string GetPlaceSoundset()
	{
		return "placeBarrel_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionOpenBarrelHoles);
		AddAction(ActionCloseBarrelHoles);
		AddAction(ActionTakeFireplaceFromBarrel);
		//AddAction(ActionLightItemOnFire);
		AddAction(ActionPlaceObject);
	}
}
