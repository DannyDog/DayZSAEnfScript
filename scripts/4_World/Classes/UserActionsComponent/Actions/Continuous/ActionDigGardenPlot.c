class ActionDigGardenPlotCB : ActiondeployObjectCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DIG_GARDEN);
	}
	
	override void DropDuringPlacing()
	{
		if ( m_ActionData.m_MainItem.CanMakeGardenplot() )
		{
			return;
		} 
	}
};

class ActionDigGardenPlot: ActionDeployObject
{	
	GardenPlot m_GardenPlot;
	
	void ActionDigGardenPlot()
	{
		m_CallbackClass	= ActionDigGardenPlotCB;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
	}
		
	override string GetText()
	{
		return "#make_garden_plot";
	}
	
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//Client
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( player.IsPlacingLocal() )
			{
				Hologram hologram = player.GetHologramLocal();
				GardenPlot item_GP;
				Class.CastTo(item_GP,  hologram.GetProjectionEntity() );	
				CheckSurfaceBelowGardenPlot(player, item_GP, hologram);
	
				if ( !hologram.IsColliding() )
				{
					return true;
				}
			}
			return false;
		}
		//Server
		return true;
	}

	override void SetupAnimation( ItemBase item )
	{
		if ( item )
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIG;
		}
	}
	
	void CheckSurfaceBelowGardenPlot(PlayerBase player, GardenPlot item_GP, Hologram hologram)
	{
		if (item_GP) // TO DO: When GardenPlot is renamed back to GardenPlot then remove this check.
		{
			if ( item_GP.CanBePlaced(player, item_GP.GetPosition() )  )
			{
				if( item_GP.CanBePlaced(NULL, item_GP.CoordToParent(hologram.GetLeftCloseProjectionVector())) )
				{
					if( item_GP.CanBePlaced(NULL, item_GP.CoordToParent(hologram.GetRightCloseProjectionVector())) )
					{
						if( item_GP.CanBePlaced(NULL, item_GP.CoordToParent(hologram.GetLeftFarProjectionVector())) )
						{
							if( item_GP.CanBePlaced(NULL, item_GP.CoordToParent(hologram.GetRightFarProjectionVector())) )
							{
								hologram.SetIsCollidingGPlot( false );
	
								return;
							}
						}
					}
				}
			}
			
			hologram.SetIsCollidingGPlot( true );
		}
	}
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		EntityAI entity_for_placing = action_data.m_MainItem;
		vector position = action_data.m_Player.GetLocalProjectionPosition();
		vector orientation = action_data.m_Player.GetLocalProjectionOrientation();
				
		if ( GetGame().IsMultiplayer() )
		{		
			m_GardenPlot = GardenPlot.Cast( action_data.m_Player.GetHologramServer().PlaceEntity( entity_for_placing ));
			m_GardenPlot.SetOrientation( orientation );
			action_data.m_Player.GetHologramServer().CheckPowerSource();
			action_data.m_Player.PlacingCompleteServer();	
			
			m_GardenPlot.OnPlacementComplete( action_data.m_Player );
		}
			
		//local singleplayer
		if ( !GetGame().IsMultiplayer())
		{						
			m_GardenPlot = GardenPlot.Cast( action_data.m_Player.GetHologramLocal().PlaceEntity( entity_for_placing ));
			m_GardenPlot.SetOrientation( orientation );
			action_data.m_Player.PlacingCompleteLocal();
			
			m_GardenPlot.OnPlacementComplete( action_data.m_Player );
		}
		
		GetGame().ClearJuncture( action_data.m_Player, entity_for_placing );
		action_data.m_MainItem.SetIsBeingPlaced( false );
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		poActionData.m_AlreadyPlaced = true;	
		action_data.m_MainItem.SoundSynchRemoteReset();
		
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 17);
		
	}
};
