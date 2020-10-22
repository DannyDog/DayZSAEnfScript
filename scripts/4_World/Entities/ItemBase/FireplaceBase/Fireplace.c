class Fireplace extends FireplaceBase
{
	void Fireplace()
	{
		//Particles - default for FireplaceBase
		PARTICLE_FIRE_START 	= ParticleList.CAMP_FIRE_START;
		PARTICLE_SMALL_FIRE 	= ParticleList.CAMP_SMALL_FIRE;
		PARTICLE_NORMAL_FIRE	= ParticleList.CAMP_NORMAL_FIRE;
		PARTICLE_SMALL_SMOKE 	= ParticleList.CAMP_SMALL_SMOKE;
		PARTICLE_NORMAL_SMOKE	= ParticleList.CAMP_NORMAL_SMOKE;
		PARTICLE_FIRE_END 		= ParticleList.CAMP_FIRE_END;
		PARTICLE_STEAM_END		= ParticleList.CAMP_STEAM_2END;
	}
	
	override bool IsBaseFireplace()
	{
		return true;
	}
	
	//attachments
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		if ( !super.CanReceiveAttachment(attachment, slotId) )
			return false;

		ItemBase item = ItemBase.Cast( attachment );

		//kindling items
		if ( IsKindling ( item ) )
			return true;
		
		//fuel items
		if ( IsFuel ( item ) )
			return true;
		
		//cookware
		if ( item.Type() == ATTACHMENT_COOKING_POT )
		{
			if ( IsItemTypeAttached( ATTACHMENT_TRIPOD ) || IsOven() ) 
				return true;
		}
		if ( item.Type() == ATTACHMENT_FRYING_PAN )
		{
			if ( IsOven() ) 
				return true;
		}

		// food on direct cooking slots
		if ( IsOven() )
		{
			if ( item.IsKindOf( "Edible_Base" ) )
				return true;
		}
		//tripod
		if ( item.Type() == ATTACHMENT_TRIPOD )
		{
			if ( !IsOven() && GetHierarchyParent() == NULL )
				return true;
		}
		
		//stones
		if ( item.Type() == ATTACHMENT_STONES )
		{
			if ( GetHierarchyParent() || IsBurning() )
				return false;
			
			return true;
		}
		
		return false;
	}
	
	override bool CanLoadAttachment( EntityAI attachment )
	{
		if ( !super.CanLoadAttachment(attachment) )
			return false;

		ItemBase item = ItemBase.Cast( attachment );

		//kindling items
		if ( IsKindling ( item ) )
			return true;
		
		//fuel items
		if ( IsFuel ( item ) )
			return true;
		
		//cookware
		if ( item.Type() == ATTACHMENT_COOKING_POT )
		{
			if ( IsItemTypeAttached( ATTACHMENT_TRIPOD ) || IsOven() ) 
				return true;
		}
		if ( item.Type() == ATTACHMENT_FRYING_PAN )
		{
			if ( IsOven() ) 
				return true;
		}

		// food on direct cooking slots
		if ( IsOven() )
		{
			if ( item.IsKindOf( "Edible_Base" ) )
				return true;
		}
		//tripod
		if ( item.Type() == ATTACHMENT_TRIPOD )
		{
			if ( !IsOven() && GetHierarchyParent() == NULL )
				return true;
		}
		
		//stones
		if ( item.Type() == ATTACHMENT_STONES )
		{
			if ( GetHierarchyParent() || IsBurning() )
				return false;
			
			return true;
		}
		
		return false;
	}

	override bool CanReleaseAttachment( EntityAI attachment )
	{
		if( !super.CanReleaseAttachment( attachment ) )
			return false;
		
		ItemBase item = ItemBase.Cast( attachment );
		
		//has last attachment and there are still items in cargo
		if ( GetInventory().AttachmentCount() == 1 && GetInventory().GetCargo().GetItemCount() != 0 )
		{
			return false;
		}
		
		//kindling items
		if ( IsKindling( item ) && !IsBurning() )
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
		if ( IsFuel( item ) && !IsBurning() )
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
		
		//cookware
		if ( item.Type() == ATTACHMENT_COOKING_POT )
		{
			return true;
		}
		if ( item.Type() == ATTACHMENT_FRYING_PAN )
		{
			return true;
		}

		// food on direct cooking slots
		if ( item.IsKindOf("Edible_Base") )
			return true;

		//tripod
		if ( item.Type() == ATTACHMENT_TRIPOD && !GetCookingEquipment() )
		{
			return true;
		}
		
		//stones
		if ( item.Type() == ATTACHMENT_STONES )
		{
			if ( IsBurning() )
				return false;

			int stone_quantity = item.GetQuantity();
			if ( HasStoneCircle() && ( stone_quantity <= 8 ) )
			{
				return false;
			}
			if ( IsOven() )
			{
				return false;
			}
			
			return true;
		}
		
		return false;
	}

	override void EEItemAttached( EntityAI item, string slot_name ) 
	{
		super.EEItemAttached( item, slot_name );
		
		ItemBase item_base = ItemBase.Cast( item );
		
		//kindling / fuel
		if ( IsKindling( item_base ) || IsFuel( item_base ) )
		{
			//add to consumables
			AddToFireConsumables( item_base );
		}
		
		//cookware
		if ( item_base.Type() == ATTACHMENT_COOKING_POT )
		{
			SetCookingEquipment( item_base );
			
			//rotate handle (if not in 'Oven' stage)
			if ( !IsOven() )
			{
				item_base.SetAnimationPhase( ANIMATION_COOKWARE_HANDLE, 0 );
			}
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
		
		//TODO
		//add SetViewIndex when attaching various attachments
		
		//refresh fireplace visuals
		RefreshFireplaceVisuals();
	}

	override void EEItemDetached( EntityAI item, string slot_name ) 
	{
		super.EEItemDetached( item, slot_name );
		
		ItemBase item_base = ItemBase.Cast( item );
		
		//kindling / fuel
		if ( IsKindling( item_base ) || IsFuel( item_base ) )
		{
			//remove from consumables
			RemoveFromFireConsumables( GetFireConsumableByItem( item_base ) );
			
			//no attachments left, no cargo items & no ashes are present
			if ( GetInventory().AttachmentCount() == 0 && !HasAshes() )
			{
				//destroy fireplace
				DestroyFireplace();
			}
		}

		//cookware
		if ( item_base.Type() == ATTACHMENT_COOKING_POT )
		{
			ClearCookingEquipment();
			
			//rotate handle
			item_base.SetAnimationPhase( ANIMATION_COOKWARE_HANDLE, 1 );
			
			//remove audio visuals
			Bottle_Base cooking_pot = Bottle_Base.Cast( item );
			cooking_pot.RemoveAudioVisualsOnClient();
		}
		if ( item_base.Type() == ATTACHMENT_FRYING_PAN )
		{
			//remove audio visuals
			FryingPan frying_pan = FryingPan.Cast( item );
			frying_pan.RemoveAudioVisualsOnClient();
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

		//TODO
		//add SetViewIndex when detaching various attachments
		
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
		
		if ( HasAshes() || IsBurning() || HasStones() || HasStoneCircle() || IsOven() || IsInAnimPhase( ANIMATION_TRIPOD ) || !IsCargoEmpty() )
		{
			return false;
		}
		
		return true;
	}

	override bool CanRemoveFromCargo( EntityAI parent )
	{
		return true;
	}
	
	//cargo item into/outo this.Cargo
	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		if ( GetHierarchyParent() )
		{
			return false;
		}
		
		return super.CanReceiveItemIntoCargo( item );
	}
	
	override bool CanLoadItemIntoCargo( EntityAI item )
	{
		if ( GetHierarchyParent() )
			return false;
		
		return super.CanLoadItemIntoCargo( item );
	}
/*
	override bool CanReleaseCargo( EntityAI cargo )
	{

		if ( IsBurning() )
		{
			return false;
		}

		return true;
	}
*/
	
	//hands
	override bool CanPutIntoHands( EntityAI parent )
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		
		if ( HasAshes() || IsBurning() || HasStones() || HasStoneCircle() || IsOven() || IsInAnimPhase( ANIMATION_TRIPOD ) || !IsCargoEmpty() )
		{
			return false;
		}
		
		return true;
	}
	
	override bool CanDisplayAttachmentCategory( string category_name )
	{
		if( !super.CanDisplayAttachmentCategory( category_name ) )
		{
			return false;
		}
		
		if ( IsOven() )
		{
			if ( category_name == "CookingEquipment" )
				return false;
			if ( ( category_name == "DirectCooking" ) || ( category_name == "Smoking" ) )
				return true;
		}
		else
		{
			if ( category_name == "CookingEquipment" )
				return true;
			if ( ( category_name == "DirectCooking" ) || ( category_name == "Smoking" ) )
				return false;
		}
		return true;
	}
	
	override bool CanAssignAttachmentsToQuickbar()
	{
		return false;
	}
	
	//particles
	override bool CanShowSmoke()
	{
		return !IsOven();
	}
	
	
	void DestroyClutterCutter( Object clutter_cutter )
	{
		GetGame().ObjectDelete( clutter_cutter );
	}	
	
	override void RefreshFireplacePhysics()
	{
		//Oven
		if ( IsOven() )
		{
			RemoveProxyPhysics( ANIMATION_OVEN );
			AddProxyPhysics( ANIMATION_OVEN );
		}
		else
		{
			RemoveProxyPhysics( ANIMATION_OVEN );
		}
		
		//Tripod
		if ( IsItemTypeAttached( ATTACHMENT_TRIPOD ) )
		{
			RemoveProxyPhysics( ANIMATION_TRIPOD );
			AddProxyPhysics( ANIMATION_TRIPOD );
		}
		else
		{
			RemoveProxyPhysics( ANIMATION_TRIPOD );
		}	
	}

	//on store save/load
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave(ctx);
		
		if( GetGame().SaveVersion() >= 110 )
		{
			// save stone circle state
			ctx.Write( m_HasStoneCircle );
			
			// save stone oven state
			ctx.Write( m_IsOven );
		}
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad(ctx, version) )
			return false;

		if( version >= 110 )
		{
			// read stone circle state
			if( !ctx.Read( m_HasStoneCircle ) )
			{
				m_HasStoneCircle = false;
				return false;
			}
			// read stone oven state
			if( !ctx.Read( m_IsOven ) )
			{
				m_IsOven = false;
				return false;
			}
		}		
		return true;
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
		
		if ( IsBurning() )
		{
			if ( !m_ClutterCutter )
			{
				m_ClutterCutter = GetGame().CreateObjectEx( OBJECT_CLUTTER_CUTTER, GetPosition(), ECE_PLACE_ON_SURFACE );
				m_ClutterCutter.SetOrientation( GetOrientation() );
			}
		}
	}
	
	//================================================================
	// IGNITION ACTION
	//================================================================	
	
	// Item-to-item fire distribution
	override bool HasFlammableMaterial()
	{
		return true;
	}
	
	override bool CanBeIgnitedBy( EntityAI igniter = NULL )
	{
		if ( HasAnyKindling() && !IsBurning() && !GetHierarchyParent() )
		{
			return true;
		}
			
		return false;
	}
	
	override bool CanIgniteItem( EntityAI ignite_target = NULL )
	{
		if ( IsBurning() )
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
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( DestroyClutterCutter, 200, false, cc_object );
		
		//start fire
		StartFire();
		
		if ( fire_source )
		{
			Man player = fire_source.GetHierarchyRootPlayer();
			
			if ( player )
			{
				EFireIgniteType ignate_type = EFireIgniteType.Unknow;
				
				if ( fire_source.ClassName() == "Matchbox"  )
				{
					ignate_type = EFireIgniteType.Matchbox;
				}
				else if ( fire_source.ClassName() == "Roadflare"  )
				{
					ignate_type = EFireIgniteType.Roadflare;
				}
				else if ( fire_source.ClassName() == "HandDrillKit"  )
				{
					ignate_type = EFireIgniteType.HandDrill;
				}
				
				
				SyncEvents.SendPlayerIgnatedFireplace( player, ignate_type );
			}
		}
	}

	override bool IsThisIgnitionSuccessful( EntityAI item_source = NULL )
	{
		//check kindling
		if ( !HasAnyKindling() )
		{
			return false;
		}
		
		//check roof
		if ( !IsOven() )
		{
			if ( !IsCeilingHighEnoughForSmoke() && IsOnInteriorSurface() )
			{
				return false;
			}
		}
		
		//check surface
		if ( IsOnWaterSurface() )
		{
			return false;
		}

		//check wetness
		if ( IsWet() )
		{
			return false;
		}

		// check if the fireplace isnt below a roof
		//  excluding this check whein oven stage
		if ( !MiscGameplayFunctions.IsUnderRoof( this ) && !IsOven() )
		{
			// if not, check if there is strong rain or wind
			if ( IsRainingAbove() || IsWindy() )
			{
				return false;
			}
		}
		
		return true;	
	}
	
	//================================================================
	// FIREPLACE ENTITY
	//================================================================	
	static Fireplace IgniteEntityAsFireplace( notnull EntityAI entity, notnull EntityAI fire_source )
	{
		//get player
		PlayerBase player = PlayerBase.Cast( fire_source.GetHierarchyRootPlayer() );
		
		//create fireplace
		Fireplace fireplace = Fireplace.Cast( GetGame().CreateObjectEx( "Fireplace" , entity.GetPosition(), ECE_PLACE_ON_SURFACE ) );
		
		//attach
		if ( !GetGame().IsMultiplayer() )		//clear inventory reservation (single player)
		{
			InventoryLocation loc = new InventoryLocation;
			entity.GetInventory().GetCurrentInventoryLocation( loc );
			player.GetInventory().ClearInventoryReservation( entity, loc );
		}
		
		if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
		{
			player.ServerTakeEntityToTargetAttachment( fireplace, entity ); // multiplayer server side
		}
		else
		{
			player.LocalTakeEntityToTargetAttachment( fireplace, entity ); // single player or multiplayer client side
		}
		
		//start fire
		fireplace.StartFire();
		
		//call event
		fireplace.OnIgnitedThis( fire_source );
		
		return fireplace;
	}
	
	static bool CanIgniteEntityAsFireplace( notnull EntityAI entity )
	{
		//check ceiling (enough space for smoke)
		if ( MiscGameplayFunctions.IsUnderRoof( entity, FireplaceBase.MIN_CEILING_HEIGHT ) && IsEntityOnInteriorSurface( entity ) )
		{
			return false;
		}
		
		//check surface
		if ( FireplaceBase.IsEntityOnWaterSurface( entity ) )
		{
			return false;
		}

		//check wetness/rain/wind
		if ( FireplaceBase.IsEntityWet( entity ) )
		{
			return false;
		}

		// check if the fireplace isnt below a roof
		if ( !MiscGameplayFunctions.IsUnderRoof( entity ) )
		{
			// if not, check if there is strong rain or wind
			if ( FireplaceBase.IsRainingAboveEntity( entity ) || FireplaceBase.IsWindy() )
			{
				return false;
			}
		}

		return true;	
	}	

	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override string GetPlaceSoundset()
	{
		return "placeFireplace_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionPlaceFireplaceIntoBarrel);
		AddAction(ActionPlaceFireplaceIndoor);
		AddAction(ActionPlaceOvenIndoor);
		//AddAction(ActionLightItemOnFire);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionBuildOven);
		AddAction(ActionDismantleOven);
		AddAction(ActionBuildStoneCircle);
		AddAction(ActionDismantleStoneCircle);
	}
}
