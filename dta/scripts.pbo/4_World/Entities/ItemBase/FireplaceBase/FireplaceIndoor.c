class FireplaceIndoor extends FireplaceBase
{
	protected float 				m_SmokePosX;
	protected float 				m_SmokePosY;
	protected float 				m_SmokePosZ;
	protected int					m_FirePointIndex = 1;	//limited to 1 decimal place (1-9)
	
	static const string FIREPOINT_ACTION_SELECTION	= "fireplace_action";
	static const string FIREPOINT_FIRE_POSITION 	= "fireplace_point";
	static const string FIREPOINT_SMOKE_POSITION 	= "fireplace_smoke";
	
	void FireplaceIndoor()
	{
		//Particles - default for FireplaceBase
		PARTICLE_FIRE_START 	= ParticleList.HOUSE_FIRE_START;
		PARTICLE_SMALL_FIRE 	= ParticleList.HOUSE_SMALL_FIRE;
		PARTICLE_NORMAL_FIRE	= ParticleList.HOUSE_NORMAL_FIRE;
		PARTICLE_SMALL_SMOKE 	= ParticleList.HOUSE_SMALL_SMOKE;
		PARTICLE_NORMAL_SMOKE	= ParticleList.HOUSE_NORMAL_SMOKE;
		PARTICLE_FIRE_END 		= ParticleList.HOUSE_FIRE_END;
		PARTICLE_STEAM_END		= ParticleList.HOUSE_FIRE_STEAM_2END;		
		
		//register sync variables
		RegisterNetSyncVariableFloat( "m_SmokePosX", 0, 0, 2 );
		RegisterNetSyncVariableFloat( "m_SmokePosY", 0, 0, 2 );
		RegisterNetSyncVariableFloat( "m_SmokePosZ", 0, 0, 2 );
		RegisterNetSyncVariableInt( "m_FirePointIndex", 1, 9 );
	}
	
	//================================================================
	// ONSTORESAVE/LOAD/AFTERLOAD
	//================================================================
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );

		//fire point name
		ctx.Write( m_FirePointIndex );
		
		//smoke position
		ctx.Write( m_SmokePosX );
		ctx.Write( m_SmokePosY );
		ctx.Write( m_SmokePosZ );
	}

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;

		//--- Fireplace Indoor data ---
		//fire point name
		if( !ctx.Read( m_FirePointIndex ) )
		{
			m_FirePointIndex = 1;		//set default
			return false;
		}
		
		//smoke position
		if ( !ctx.Read( m_SmokePosX ) )
		{
			m_SmokePosX = 0;		//set default
			return false;
		}
		if ( !ctx.Read( m_SmokePosY ) )
		{
			m_SmokePosY = 0;		//set default
			return false;
		}
		if ( !ctx.Read( m_SmokePosZ ) )
		{
			m_SmokePosZ = 0;		//set default
			return false;
		}
		//---

		return true;
	}
		
	//================================================================
	// FIRE POINT (HOUSE)
	// LIMITED TO 1 DECIMAL PLACE (0-9)
	//================================================================
	static int GetFirePointIndex( string action_selection )
	{
		int index_location = action_selection.Length() - 1;
		return action_selection.Substring( index_location, 1 ).ToInt();
	}
	
	void SetFirePointIndex( int fire_point_index )
	{
		m_FirePointIndex = fire_point_index;
	}
	
	static bool CanPlaceFireplaceInSelectedSpot( Object building, int fire_point_index, out vector fire_point_pos_world )
	{
		//Get fire point index position
		vector fire_point_pos = building.GetSelectionPositionMS( FIREPOINT_FIRE_POSITION + fire_point_index.ToString() );
		fire_point_pos_world = building.ModelToWorld( fire_point_pos );
		
		//check if there is any FireplaceIndoor objects near selected fire point
		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;
		GetGame().GetObjectsAtPosition3D( fire_point_pos_world, 1, nearest_objects, proxy_cargos );

		for ( int i = 0; i < nearest_objects.Count(); ++i )
		{
			Object object = nearest_objects.Get( i );
			
			if ( object.IsInherited( FireplaceIndoor ) )
			{
				return false;
			}
		}
		
		return true;
	}
	
	void SetSmokePointPosition( vector smoke_point_pos )
	{
		m_SmokePosX = smoke_point_pos[0];
		m_SmokePosY = smoke_point_pos[1];
		m_SmokePosZ = smoke_point_pos[2];
	}
	
	//================================================================
	// PARTICLES
	//================================================================
	override protected vector GetSmokeEffectPosition()
	{
		return Vector( m_SmokePosX, m_SmokePosY, m_SmokePosZ );
	}
	
	protected vector GetSmokeRelativePosition()
	{
		vector fire_position = GetPosition();
		vector smoke_position = GetSmokeEffectPosition();
		
		return Vector( smoke_position[0] - fire_position[0], smoke_position[1] - fire_position[1], smoke_position[2] - fire_position[2] );
	}
	
	//small smoke
	override void ParticleSmallSmokeStart()
	{
		PlayParticle( m_ParticleSmallSmoke, PARTICLE_SMALL_SMOKE, GetSmokeRelativePosition() );
	}
	
	//normal smoke
	override void ParticleNormalSmokeStart()
	{
		PlayParticle( m_ParticleNormalSmoke, PARTICLE_NORMAL_SMOKE, GetSmokeRelativePosition() );
	}	

	//================================================================
	// STATE
	//================================================================
	override bool IsFireplaceIndoor()
	{
		return true;
	}

	//================================================================
	// ATTACHMENTS
	//================================================================	
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
		if ( item.Type() == ATTACHMENT_COOKING_POT || item.Type() == ATTACHMENT_FRYING_PAN )
		{
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
		if ( IsKindling ( item ) && !IsBurning() )
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
		if ( item.Type() == ATTACHMENT_COOKING_POT || item.Type() == ATTACHMENT_FRYING_PAN )
		{
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
			AddToFireConsumables ( item_base );
		}
		
		//cookware
		if ( item_base.Type() == ATTACHMENT_COOKING_POT )
		{
			SetCookingEquipment( item_base );
			
			//rotate handle
			item_base.SetAnimationPhase( ANIMATION_COOKWARE_HANDLE, 1 );
		}
		//TODO
		//frying pan 
		if ( item_base.Type() == ATTACHMENT_FRYING_PAN )
		{
			SetCookingEquipment( item_base );
		}
		
		
		//refresh fireplace visuals
		RefreshFireplaceVisuals();
	}

	override void EEItemDetached( EntityAI item, string slot_name ) 
	{
		super.EEItemDetached ( item, slot_name );
		
		ItemBase item_base = ItemBase.Cast( item );
		
		//kindling / fuel
		if ( IsKindling( item_base ) || IsFuel( item_base ) )
		{
			//remove from consumables
			RemoveFromFireConsumables( GetFireConsumableByItem( item_base ) );
			
			//no attachments left & no ashes are present
			if ( GetInventory().AttachmentCount() == 0 && !HasAshes() )
			{
				//TODO
				//Clear point
				/*
				if ( GetGame().IsServer() )
				{
					if ( GetFireplacePoint() )
					{
						GetFireplacePoint().ClearObject();
						ClearFireplacePoint();						
					}
				}
				*/

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
		//frying pan		
		if ( item_base.Type() == ATTACHMENT_FRYING_PAN )
		{
			ClearCookingEquipment();
		}
		
		//refresh fireplace visuals
		RefreshFireplaceVisuals();
	}
		
	//================================================================
	// CONDITIONS
	//================================================================
	//this into/outo parent.Cargo
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}
		return false;
	}

	override bool CanRemoveFromCargo( EntityAI parent )
	{
		return true;
	}
	
	//cargo item into/outo this.Cargo
	override bool CanReceiveItemIntoCargo( EntityAI cargo )
	{
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
		return false;
	}
	
	override bool CanRemoveFromHands ( EntityAI player ) 
	{
		return false;
	}

	// Item-to-item fire distribution
	override bool HasFlammableMaterial()
	{
		return true;
	}
	
	override bool CanBeIgnitedBy( EntityAI igniter = NULL )
	{
		if ( HasAnyKindling() && !GetHierarchyParent() )
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
		//start fire
		StartFire(); 
	}
	
	override bool IsThisIgnitionSuccessful( EntityAI item_source = NULL )
	{
		//check kindling
		if ( !HasAnyKindling() )
		{
			return false;
		}
		
		//check wetness
		if ( IsWet() )
		{
			return false;
		}
		
		return true;	
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTakeFireplaceIndoor);
		//AddAction(ActionLightItemOnFire);
	}
}
