class PlaceObjectActionReciveData : ActionReciveData
{
	vector m_Position;
	vector m_Orientation;
}

class PlaceObjectActionData : ActionData
{
	vector m_Position;
	vector m_Orientation;
	bool m_AlreadyPlaced;
}

class ActiondeployObjectCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_DEPLOY);
	}

	override void OnAnimationEvent(int pEventID)	
	{
		super.OnAnimationEvent( pEventID );
		
		switch (pEventID)
		{
			case UA_ANIM_EVENT:						
				if ( GetGame().IsServer() )
				{		
					m_ActionData.m_MainItem.SoundSynchRemote();
				}
			
				if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
				{			
					if ( m_ActionData.m_Player.GetItemInHands() )
					{
						DropDuringPlacing();
					}
				}

			break;
		}
	}

	void DropDuringPlacing()
	{
		EntityAI entity_for_placing = m_ActionData.m_MainItem;
		if ( entity_for_placing.IsBasebuildingKit() )
			return;
		
		vector orientation = m_ActionData.m_Player.GetOrientation();
		vector 	position = m_ActionData.m_Player.GetPosition() + m_ActionData.m_Player.GetDirection();
		vector rotation_matrix[3];
		float direction[4];
		InventoryLocation source = new InventoryLocation;
		InventoryLocation destination = new InventoryLocation;
		
		Math3D.YawPitchRollMatrix( orientation, rotation_matrix );
		Math3D.MatrixToQuat( rotation_matrix, direction );
			
		vector ground_position = position;
		ground_position[1] = GetGame().SurfaceY(ground_position[0],ground_position[2]);
		
		if ( vector.DistanceSq( m_ActionData.m_Player.GetPosition(), ground_position ) > UAMaxDistances.DEFAULT * UAMaxDistances.DEFAULT)
		{
			if ( entity_for_placing.GetInventory().GetCurrentInventoryLocation( source ) )
			{
				destination.SetGroundEx( entity_for_placing, position, direction );
				m_ActionData.m_Player.PredictiveTakeToDst(source, destination);
			}
		}
		else
		{
			if ( entity_for_placing.GetInventory().GetCurrentInventoryLocation( source ) )
			{
				destination.SetGroundEx( entity_for_placing, ground_position, direction );
				m_ActionData.m_Player.PredictiveTakeToDst(source, destination);
			}
		}
	}
};

class ActionDeployObject: ActionContinuousBase
{			 
	void ActionDeployObject()
	{
		m_CallbackClass		= ActiondeployObjectCB;
		m_SpecialtyWeight 	= UASoftSkillsWeight.PRECISE_LOW;
		m_CommandUID		= 0;
		m_FullBody			= true;
		m_StanceMask		= DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool HasProgress()
	{
		return true;
	}
	
	override bool HasAlternativeInterrupt()
	{
		return true;
	}
	
	override string GetText()
	{
		return "#deploy_object";
	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{
		return true;
	}
	
	override ActionData CreateActionData()
	{
		PlaceObjectActionData action_data = new PlaceObjectActionData;
		return action_data;
	}
	
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{	
		if ( super.SetupAction(player, target, item, action_data, extra_data ))
		{
			PlaceObjectActionData poActionData;
			poActionData = PlaceObjectActionData.Cast(action_data);
			poActionData.m_AlreadyPlaced = false;
			if (!GetGame().IsMultiplayer() || GetGame().IsClient() )
			{
				Hologram hologram = player.GetHologramLocal();
				if (hologram)
				{
					poActionData.m_Position = player.GetHologramLocal().GetProjectionPosition();
					poActionData.m_Orientation = player.GetHologramLocal().GetProjectionOrientation();
			
					poActionData.m_Player.SetLocalProjectionPosition( poActionData.m_Position );
					poActionData.m_Player.SetLocalProjectionOrientation( poActionData.m_Orientation );
				}
				else
				{
					return false;
				}
			}
			
			if ( !action_data.m_MainItem )
				return false;
			
			SetupAnimation( action_data.m_MainItem );
			return true;
		}
		return false;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//Print("XXXXXX");
		//Client
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( player.IsPlacingLocal() )
			{
				//Print("------");
				if ( !player.GetHologramLocal().IsColliding() )
				{
					if ( item.CanBePlaced(player, player.GetHologramLocal().GetProjectionEntity().GetPosition()) )
					{
						return true;
					}
				}
			}
			return false;
		}
		//Server
		return true; 
	}
	
	/*override bool ActionConditionContinue( ActionData action_data )
	{
		//Client
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( player.IsPlacingLocal() )
			{
				if ( !player.GetHologramLocal().IsColliding() )
				{
					if ( item.CanBePlaced(player, player.GetHologramLocal().GetProjectionEntity().GetPosition()) )
					{
						return true;
					}
				}
			}
			return false;
		}
		//Server
		return true; 
	}*/
	
	override void OnStartClient( ActionData action_data )
	{		
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		
		if ( !poActionData ) { return; }
		
		if (GetGame().IsMultiplayer())
			action_data.m_Player.PlacingCompleteLocal();
	}
	
	override void OnStartServer( ActionData action_data )
	{
		if ( GetGame().IsMultiplayer() )
		{
			PlaceObjectActionData poActionData;
			poActionData = PlaceObjectActionData.Cast(action_data);
			
			if ( !poActionData ) { return; }
			
			EntityAI entity_for_placing = action_data.m_MainItem;
			poActionData.m_Player.SetLocalProjectionPosition( poActionData.m_Position );
			poActionData.m_Player.SetLocalProjectionOrientation( poActionData.m_Orientation );
			
			if ( action_data.m_MainItem )
			{
				poActionData.m_Player.PlacingStartServer(action_data.m_MainItem);
			
				GetGame().AddActionJuncture( action_data.m_Player, entity_for_placing, 10000 );
				action_data.m_MainItem.SetIsBeingPlaced( true );
			}
		}
		else
		{
			//local singleplayer			
			action_data.m_Player.PlacingStartServer(action_data.m_MainItem);
			action_data.m_Player.GetHologramLocal().SetUpdatePosition( false );
			action_data.m_MainItem.SetIsBeingPlaced( true );
		}
	}
			
	override void OnFinishProgressClient( ActionData action_data )
	{
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		
		if ( !poActionData ) { return; }
		
		EntityAI entity_for_placing = action_data.m_MainItem;
		vector position = action_data.m_Player.GetLocalProjectionPosition();
		vector orientation = action_data.m_Player.GetLocalProjectionOrientation();

		poActionData.m_AlreadyPlaced = true;
		
		entity_for_placing.OnPlacementComplete( action_data.m_Player, position, orientation);
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		
		if ( !poActionData ) { return; }
		if( !action_data.m_MainItem ) { return; }
		
		EntityAI entity_for_placing = action_data.m_MainItem;
		vector position = action_data.m_Player.GetLocalProjectionPosition();
		vector orientation = action_data.m_Player.GetLocalProjectionOrientation();
		
		action_data.m_Player.GetHologramServer().EvaluateCollision(action_data.m_MainItem);
		//action_data.m_Player.GetHologramServer().SetIsColliding(true); //REMOVE
		if (action_data.m_Player.GetHologramServer().IsColliding())
		{
			//Print("!!!IsColliding");
			//return;
		}
		
		action_data.m_Player.GetHologramServer().PlaceEntity( entity_for_placing );
		
		if ( GetGame().IsMultiplayer() )
			action_data.m_Player.GetHologramServer().CheckPowerSource();
		
		action_data.m_Player.PlacingCompleteServer();
		entity_for_placing.OnPlacementComplete( action_data.m_Player, position, orientation );		
		
		MoveEntityToFinalPosition( action_data, position, orientation );		
		GetGame().ClearJuncture( action_data.m_Player, entity_for_placing );
		action_data.m_MainItem.SetIsBeingPlaced( false );
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		poActionData.m_AlreadyPlaced = true;	
		action_data.m_MainItem.SoundSynchRemoteReset();
	}
	
	override void OnEndClient( ActionData action_data  )
	{
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		if ( !poActionData.m_AlreadyPlaced )
		{
			EntityAI entity_for_placing = action_data.m_MainItem;
			action_data.m_Player.PlacingCancelLocal();
			action_data.m_Player.PredictiveTakeEntityToHands( entity_for_placing );
			action_data.m_Player.LockHandsUntilItemHeld();
		}
	}
	
	override void OnEndServer( ActionData action_data  )
	{
		if( !action_data || !action_data.m_MainItem )
			return;
		
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		if ( !poActionData.m_AlreadyPlaced )
		{
			EntityAI entity_for_placing = action_data.m_MainItem;
			GetGame().ClearJuncture( action_data.m_Player, entity_for_placing );
			action_data.m_MainItem.SetIsBeingPlaced( false );
		
			if ( GetGame().IsMultiplayer() )
			{	
				action_data.m_Player.PlacingCancelServer();
				//action_data.m_Player.ServerTakeEntityToHands( entity_for_placing );
				action_data.m_MainItem.SoundSynchRemoteReset();
			}
			else
			{
				//local singleplayer
				action_data.m_Player.PlacingCancelLocal();
				action_data.m_Player.PlacingCancelServer();
				
				InventoryLocation source = new InventoryLocation;
				InventoryLocation destination = new InventoryLocation;
		
				if ( action_data.m_MainItem.GetInventory().GetCurrentInventoryLocation( source ) )
				{
					destination.SetHands( action_data.m_Player, action_data.m_MainItem );
					action_data.m_Player.GetDayZPlayerInventory().RedirectToHandEvent(InventoryMode.LOCAL, source, destination);
				}
			}
			
			GetGame().ClearJuncture( action_data.m_Player, action_data.m_MainItem );
		}
		else
		{
			//TODO: make OnEND placement event and move there
			
			action_data.m_MainItem.SetIsDeploySound( false );
			action_data.m_MainItem.SetIsPlaceSound( false );
			action_data.m_MainItem.SoundSynchRemoteReset();
			
			if ( action_data.m_MainItem.IsBasebuildingKit() )
			{
				action_data.m_MainItem.Delete();
			}
			else
			{
				GetGame().ClearJuncture( action_data.m_Player, action_data.m_MainItem );
			}
		}
	}

	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);

		ctx.Write( poActionData.m_Position );
		ctx.Write( poActionData.m_Orientation );
	}
	
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		if(!action_recive_data)
		{
			action_recive_data = new PlaceObjectActionReciveData;
		}
		super.ReadFromContext(ctx, action_recive_data );
		PlaceObjectActionReciveData action_data_po = PlaceObjectActionReciveData.Cast(action_recive_data);
		
		vector entity_position = "0 0 0";
		vector entity_orientation = "0 0 0";
		if (!ctx.Read(entity_position))
			return false;
		if (!ctx.Read(entity_orientation))
			return false;
		
		action_data_po.m_Position = entity_position;
		action_data_po.m_Orientation = entity_orientation;
		
		return true;
	}
	
	override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data)
	{
		super.HandleReciveData(action_recive_data, action_data);
		
		PlaceObjectActionReciveData recive_data_po = PlaceObjectActionReciveData.Cast(action_recive_data);
		PlaceObjectActionData action_data_po = PlaceObjectActionData.Cast(action_data);
		
		action_data_po.m_Position = recive_data_po.m_Position;
		action_data_po.m_Orientation = recive_data_po.m_Orientation;
	}
			
	void MoveEntityToFinalPosition( ActionData action_data, vector position, vector orientation )
	{
		if ( action_data.m_MainItem.IsBasebuildingKit() ) return;
		
		EntityAI entity_for_placing = action_data.m_MainItem;
		vector rotation_matrix[3];
		float direction[4];
		InventoryLocation source = new InventoryLocation;
		InventoryLocation destination = new InventoryLocation;
		
		Math3D.YawPitchRollMatrix( orientation, rotation_matrix );
		Math3D.MatrixToQuat( rotation_matrix, direction );
		
		if ( entity_for_placing.GetInventory().GetCurrentInventoryLocation( source ) )
		{
			destination.SetGroundEx( entity_for_placing, position, direction );
			
			if ( GetGame().IsMultiplayer() )
			{
				action_data.m_Player.ServerTakeToDst(source, destination);
			}		
			//local singleplayer
			else
			{
				MoveEntityToFinalPositionSinglePlayer(action_data, source, destination);
			}			
		}
	}
	
	void MoveEntityToFinalPositionSinglePlayer(ActionData action_data, InventoryLocation source, InventoryLocation destination)
	{
		action_data.m_Player.GetInventory().TakeToDst(InventoryMode.LOCAL, source, destination);
	}
	
	void SetupAnimation( ItemBase item )
	{
		if ( item.IsDeployable() )
		{
			if ( item.IsHeavyBehaviour() )
			{
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_HEAVY;
			}
			else if ( item.IsOneHandedBehaviour() )
			{
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_1HD; 
			}
			else if ( item.IsTwoHandedBehaviour() )
			{
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
			}
			else
			{
				Print("Error: check " + item + " behaviour");
			}
		}
		else
		{
			if ( item.IsHeavyBehaviour() )
			{
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_PLACING_HEAVY;
			}
			else if ( item.IsOneHandedBehaviour() )
			{
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_PLACING_1HD; 
			}
			else if ( item.IsTwoHandedBehaviour() )
			{
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_PLACING_2HD;
			}
			else
			{
				Print("Error: check " + item + " behaviour");
			}
		}
	}
};
