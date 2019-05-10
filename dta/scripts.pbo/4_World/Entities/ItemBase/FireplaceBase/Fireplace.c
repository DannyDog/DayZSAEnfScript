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
		ItemBase item = ItemBase.Cast( attachment );
		
		//kindling items
		if ( IsKindling ( item ) )
		{
			return true;
		}
		
		//fuel items
		if ( IsFuel ( item ) )
		{
			return true;
		}
		
		//cookware
		if ( item.Type() == ATTACHMENT_COOKING_POT )
		{
			if ( IsItemTypeAttached( ATTACHMENT_TRIPOD ) || IsOven() ) 
			{
				return true;
			}
		}
		
		//tripod
		if ( item.Type() == ATTACHMENT_TRIPOD )
		{
			if ( !IsOven() && GetHierarchyParent() == NULL )
			{
				return true;
			}
		}
		
		//stones
		if ( item.Type() == ATTACHMENT_STONES )
		{
			if ( GetHierarchyParent() || IsBurning() )
			{
				return false;
			}
			
			return true;
		}
		
		return false;
	}

	override bool CanReleaseAttachment( EntityAI attachment )
	{
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
		
		//tripod
		if ( item.Type() == ATTACHMENT_TRIPOD && !GetCookingEquipment() )
		{
			return true;
		}
		
		//stones
		if ( item.Type() == ATTACHMENT_STONES )
		{
			if ( IsOven() || IsBurning() )
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
		
		if ( HasAshes() || IsBurning() || IsOven() || IsInAnimPhase( ANIMATION_TRIPOD ) || IsInAnimPhase( ANIMATION_STONES ) || !IsCargoEmpty() )
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
	override bool CanReceiveItemIntoCargo( EntityAI cargo )
	{
		if ( GetHierarchyParent() )
		{
			return false;
		}
		
		return true;
	}

	override bool CanReleaseCargo( EntityAI cargo )
	{
		if ( IsBurning() )
		{
			return false;
		}
		
		return true;
	}
	
	//hands
	override bool CanPutIntoHands( EntityAI parent )
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		
		if ( HasAshes() || IsBurning() || IsOven() || IsInAnimPhase( ANIMATION_TRIPOD ) || IsInAnimPhase( ANIMATION_STONES ) || !IsCargoEmpty() )
		{
			return false;
		}
		
		return true;
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
		Object cc_object = GetGame().CreateObject ( OBJECT_CLUTTER_CUTTER , GetPosition() );
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
		if ( !HasEnoughRoomForFireAbove() )
		{
			return false;
		}
		
		//check surface
		if ( IsOnWaterSurface() )
		{
			return false;
		}

		//check wetness/rain/wind
		if ( IsWet() || IsRainingAbove() || IsWindy() )
		{
			return false;
		}
		
		return true;	
	}
	
	//================================================================
	// FIREPLACE ENTITY
	//================================================================	
	static Fireplace IgniteEntityAsFireplace( notnull EntityAI entity,notnull EntityAI fire_source )
	{
		//get player
		PlayerBase player = PlayerBase.Cast( fire_source.GetHierarchyRootPlayer() );
		
		//create fireplace
		Fireplace fireplace = Fireplace.Cast( GetGame().CreateObject ( "Fireplace" , player.GetPosition() ) );
		
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
		//check roof
		if ( !FireplaceBase.HasEntityEnoughRoomForFireAbove( entity ) )
		{
			return false;
		}
		
		//check surface
		if ( FireplaceBase.IsEntityOnWaterSurface( entity ) )
		{
			return false;
		}

		//check wetness/rain/wind
		if ( FireplaceBase.IsEntityWet( entity ) || FireplaceBase.IsRainingAboveEntity( entity ) || FireplaceBase.IsWindy() )
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
		return "placeFireplace_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionPlaceFireplaceIntoBarrel);
		AddAction(ActionPlaceFireplaceIndoor);
		//AddAction(ActionLightItemOnFire);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionBuildOven);
		AddAction(ActionDismantleOven);
	}
}
