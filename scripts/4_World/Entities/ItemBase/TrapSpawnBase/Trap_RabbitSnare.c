class Trap_RabbitSnare extends TrapSpawnBase
{
	void Trap_RabbitSnare()
	{
		//m_InitWaitTime = 120 + Math.RandomInt( 0, 300 );
		m_InitWaitTime = 2;
		//m_UpdateWaitTime = 15;
		m_UpdateWaitTime = 1;
		m_BaitNeeded = false;
		m_IsFoldable = true;
		m_IsUsable = true;
		m_MinimalDistanceFromPlayersToCatch = 1;

		m_AnimationPhaseSet = "inventory";
		m_AnimationPhaseTriggered = "placing";
		m_AnimationPhaseUsed = "rabbit_snare_used";

		m_WaterSurfaceForSetup = false;
		
		m_CatchesPond = new multiMap<string, float>;
		
		m_CatchesSea = new multiMap<string, float>;
		
		m_CatchesGroundAnimal = new multiMap<string, float>;
		m_CatchesGroundAnimal.Insert("Animal_GallusGallusDomesticusF_Brown",1);
		//m_CatchesGroundAnimal.Insert("Animal_GallusGallusDomesticusF_Spotted",1);
		//m_CatchesGroundAnimal.Insert("Animal_GallusGallusDomesticusF_White",1);
		//m_CatchesGroundAnimal.Insert("Animal_LepusEuropaeus",1); Temporarily removed because rabbits don't sppawn now. Used Gallus Gallus as a placeholder.
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
	
	override void SetupTrap()
	{
		if ( g_Game.IsServer() )
		{
			if ( this.GetHierarchyRootPlayer().CanDropEntity( this) )
			{
				if ( this.IsRuined() ) 
				{
					PlayerBase player = PlayerBase.Cast( this.GetHierarchyRootPlayer() );
					player.MessageImportant( "The trap is ruined." );
				}
				else
				{
					PlayerBase owner_player = PlayerBase.Cast( this.GetHierarchyRootPlayer() );
					Error("Mojmir: TODO");
					owner_player.LocalDropEntity( this );

					//GetDirection
					vector trapPos = ( owner_player.GetDirection() ); // * 0.5;
					trapPos[1] = 0;
					this.SetPosition( owner_player.GetPosition() + trapPos );
					
					owner_player.MessageStatus( m_InfoSetup );

					SetActive();
					
					this.SetOrientation( owner_player.GetOrientation() );
				}
			}
		}
	}
	
	override void AlignCatch( ItemBase obj, string catch_name )
	{
		if ( catch_name == "Animal_LepusEuropaeus" )
		{
			obj.SetOrientation( this.GetOrientation() );
			
			vector forward_vec = this.GetDirection();
			vector side_vec = forward_vec.Perpend(  ) * -0.22;
			forward_vec = forward_vec * -0.3;
			
			vector chatch_pos = obj.GetPosition() + forward_vec + side_vec;
			obj.SetPosition( chatch_pos );
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
		return "placeRabbitSnareTrap_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "rabbitsnare_deploy_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
}

class RabbitSnareTrap extends Trap_RabbitSnare 
{	

}