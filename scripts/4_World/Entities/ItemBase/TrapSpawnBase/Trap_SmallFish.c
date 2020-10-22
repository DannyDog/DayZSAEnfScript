class Trap_SmallFish extends TrapSpawnBase
{
	void Trap_SmallFish()
	{
		m_InitWaitTime = 200;
		m_BaitNeeded = true;

		m_AnimationPhaseSet = "inventory";
		m_AnimationPhaseTriggered = "placing";

		m_WaterSurfaceForSetup = true;

		m_CatchesPond = new multiMap<string, float>;
		
		m_CatchesSea = new multiMap<string, float>;
		m_CatchesSea.Insert("Sardines",1);
		m_CatchesSea.Insert("Sardines",1);
		m_CatchesSea.Insert("Sardines",1);
		
		m_CatchesGroundAnimal = new multiMap<string, float>;
	}
	
	/*override bool IsOneHandedBehaviour()
	{
		return true;
	}*/
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
				
		if ( IsPlaceSound() )
		{
			PlayPlaceSound();
		}
	}
	
	// ITEM CANNOT BE TAKEN WHEN CONTAINS CARGO
	/*override*/ bool CanPutInInventory ( EntityAI  player ) 
	{
		return IsTakeable();
	}

	override bool CanPutIntoHands ( EntityAI player ) 
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		return IsTakeable();
	}

	override bool CanRemoveFromHands ( EntityAI player ) 
	{
		return IsTakeable();
	}

	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		if ( GetHierarchyRootPlayer() != NULL )
			return false;

		return super.CanReceiveItemIntoCargo( item );
	}

	override bool CanReleaseCargo( EntityAI child )
	{
		if ( GetHierarchyRootPlayer() == NULL )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionWorldLiquidActionSwitch);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
		AddAction(ActionFillGeneratorTank);
		AddAction(ActionExtinguishFireplaceByLiquid);
		AddAction(ActionFillBottleBase);
		AddAction(ActionWaterGardenSlot);
		AddAction(ActionWaterPlant);
		AddAction(ActionForceDrink);
		AddAction(ActionTransferLiquid);
		AddAction(ActionEmptyBottleBase);
		AddAction(ActionDrink);
	}
}

class SmallFishTrap extends Trap_SmallFish 
{
	ref RainProcurementManager m_RainProcurement;
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		// fill the bottle when placed in water

		if ( GetGame().SurfaceIsSea( position[0], position[2] ) || GetGame().SurfaceIsPond( position[0], position[2] ) )
		{
			// TODO: fill with different kinds of liquid, once nescessary surface getters are available and working
			Liquid.FillContainerEnviro( this, LIQUID_WATER, this.GetQuantityMax() );
			SetupTrapPlayer( PlayerBase.Cast( player ), false );
		}	
		else
		{
			m_RainProcurement = new RainProcurementManager( this );
			m_RainProcurement.InitRainProcurement();
		}
		
		SetIsPlaceSound( true );
	}
	
	override bool IsDeployable()
	{
		return true;
	}
	
	override string GetDeploySoundset()
	{
		return "placeSmallFishTrap_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "fishtrap_deploy_SoundSet";
	}
	
	override bool DoPlacingHeightCheck()
	{
		return true; //has to be able to catch rain, default distance raycast
	}
	
	// ----------------------------------------------------------------------------------------
	// When the item is picked up by a player, stop the rain procurement
	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged(old_owner, new_owner);
		
		if (m_RainProcurement != NULL) 
		{
			if (new_owner)
			{
				m_RainProcurement.StopRainProcurement();
				m_RainProcurement = NULL;
			}
		}
	}
	
	override bool IsOpen()
	{
		return true;
	}
}