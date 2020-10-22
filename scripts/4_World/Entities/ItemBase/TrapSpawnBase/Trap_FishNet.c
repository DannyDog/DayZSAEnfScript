class Trap_FishNet extends TrapSpawnBase
{
	void Trap_FishNet()
	{
		m_InitWaitTime = Math.RandomFloat(45,90);
		m_BaitNeeded = false;
		m_IsFoldable = true;

		m_AnimationPhaseSet = "inventory";
		m_AnimationPhaseTriggered = "placing";
		
		m_WaterSurfaceForSetup = true;

		m_CatchesPond = new multiMap<string, float>;
		m_CatchesPond.Insert("Carp",1);
		m_CatchesPond.Insert("Carp",1);
		m_CatchesPond.Insert("Carp",2);
		
		m_CatchesSea = new multiMap<string, float>;
		m_CatchesSea.Insert("Sardines",1);
		m_CatchesSea.Insert("Sardines",1);
		m_CatchesSea.Insert("Sardines",2);

		m_CatchesSea.Insert("Sardines",1);
		m_CatchesSea.Insert("Sardines",1);
		m_CatchesSea.Insert("Sardines",2);

		m_CatchesSea.Insert("Mackerel",1);
		m_CatchesSea.Insert("Mackerel",1);
		m_CatchesSea.Insert("Mackerel",2);
		
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
		if ( GetHierarchyRootPlayer() == NULL )
		{
			return true;
		}
		else
		{
			return false;
		}
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
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
			
		SetIsPlaceSound( true );
	}
	
	override bool IsDeployable()
	{
		return true;
	}
	
	override string GetDeploySoundset()
	{
		return "placeFishNetTrap_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "fishnet_deploy_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
}

class FishNetTrap extends Trap_FishNet 
{

}