class Watchtower extends BaseBuildingBase
{	
	typename ATTACHMENT_BARBED_WIRE			= BarbedWire;
	typename ATTACHMENT_CAMONET 			= CamoNet;
	
	const float MAX_FLOOR_VERTICAL_DISTANCE 		= 0.5;
	
	const float MIN_ACTION_DETECTION_ANGLE_RAD 		= 0.35;		//0.35 RAD = 20 DEG
	
	void Watchtower()
	{
	}
	
	override string GetConstructionKitType()
	{
		return "WatchtowerKit";
	}		
	
	//--- ATTACHMENT & CONDITIONS
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		if ( !super.CanReceiveAttachment( attachment, slotId ) )
			return false;

		//because CanReceiveAttachment() method can be called on all clients in the vicinity, vertical distance check needs to be skipped on clients that don't
		//interact with the object through attach action (AT_ATTACH_TO_CONSTRUCTION)
		PlayerBase player;
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//check action initiator (AT_ATTACH_TO_CONSTRUCTION)
			player = PlayerBase.Cast( GetGame().GetPlayer() );
			if ( player )
			{
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				PlayerBase action_initiator = construction_action_data.GetActionInitiator();
				
				if ( action_initiator == player )			
				{
					construction_action_data.SetActionInitiator( NULL );				//reset action initiator
				}
				else
				{
					player = null;					//do not do vertical check (next)
				}
			}
		}
		//
			
		return CheckSlotVerticalDistance( slotId, player );
	}
	
	//can put into hands
	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}
	
	// --- INVENTORY
	override bool CanDisplayAttachmentSlot( string slot_name )
	{
		//super
		if ( !super.CanDisplayAttachmentSlot( slot_name ) )
		return false;
		//

		slot_name.ToLower();
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		//base attachments
		if ( slot_name.Contains( "material_l1" ) || slot_name.Contains( "level_1_" ) )
		{
			if ( slot_name.Contains( "woodenlogs" ) )
			{
				return CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_1", player );
			}
			else
			{
				return GetConstruction().IsPartConstructed( "level_1_base" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_1", player );
			}
		}
		else if ( slot_name.Contains( "material_l2" ) || slot_name.Contains( "level_2_" ) )
		{
			if ( slot_name.Contains( "woodenlogs" ) )
			{
				return CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_2", player );
			}
			else
			{
				return GetConstruction().IsPartConstructed( "level_2_base" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_2", player );
			}
		}
		else if ( slot_name.Contains( "material_l3" ) || slot_name.Contains( "level_3_" ) )
		{
			if ( slot_name.Contains( "woodenlogs" ) )
			{
				return CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_3", player );
			}
			else
			{
				return GetConstruction().IsPartConstructed( "level_3_base" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_3", player );
			}
		}
				
		return true;
	}

	override bool CanDisplayAttachmentCategory( string category_name )
	{
		//super
		if ( !super.CanDisplayAttachmentCategory( category_name ) )
		return false;
		//
	
		category_name.ToLower();
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		//level 1
		if ( category_name.Contains( "level_1" ) )
		{
			if ( category_name.Contains( "level_1_" ) )
			{
				return GetConstruction().IsPartConstructed( "level_1_base" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_1", player );
			}
			else
			{
				return CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_1", player );
			}
		}
		//level 2
		if ( category_name.Contains( "level_2" ) )
		{
			if ( category_name.Contains( "level_2_" ) )
			{
				return GetConstruction().IsPartConstructed( "level_2_base" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_2", player );
			}
			else
			{
				return GetConstruction().IsPartConstructed( "level_1_roof" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_2", player );
			}
		}
		//level 3
		if ( category_name.Contains( "level_3" ) )
		{
			if ( category_name.Contains( "level_3_" ) )
			{
				return GetConstruction().IsPartConstructed( "level_3_base" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_3", player );
			}
			else
			{
				return GetConstruction().IsPartConstructed( "level_2_roof" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_3", player );
			}
		}
		
		return true;
	}	
	
	//returns true if attachment slot position is within given range
	override bool CheckSlotVerticalDistance( int slot_id, PlayerBase player )
	{
		string slot_name;
		InventorySlots.GetSelectionForSlotId( slot_id , slot_name );		
		slot_name.ToLower();
		
		//wall attachments
		//level 1
		if ( slot_name.Contains( "material_l1" ) || slot_name.Contains( "level_1_" ) )
		{
			if ( slot_name.Contains( "woodenlogs" ) )
			{
				return CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_1", player );
			}
			else
			{
				return GetConstruction().IsPartConstructed( "level_1_base" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_1", player );
			}
		}
		//level 2
		if ( slot_name.Contains( "material_l2" ) || slot_name.Contains( "level_2_" ) )
		{
			if ( slot_name.Contains( "material_l2w" ) || slot_name.Contains( "level_2_wall" ) )
			{
				return GetConstruction().IsPartConstructed( "level_2_base" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_2", player );
			}
			else
			{
				if ( slot_name.Contains( "woodenlogs" ) )
				{
					return CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_2", player );
				}
				else
				{
					return GetConstruction().IsPartConstructed( "level_1_roof" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_2", player );
				}
			}
		}
		//level 3
		if ( slot_name.Contains( "material_l3" ) || slot_name.Contains( "level_3_" ) )
		{
			if ( slot_name.Contains( "material_l3w" ) || slot_name.Contains( "level_3_wall" ) )
			{
				return GetConstruction().IsPartConstructed( "level_3_base" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_3", player );
			}
			else
			{
				if ( slot_name.Contains( "woodenlogs" ) )
				{
					return CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_3", player );
				}
				else
				{
					return GetConstruction().IsPartConstructed( "level_2_roof" ) && CheckMemoryPointVerticalDistance( MAX_FLOOR_VERTICAL_DISTANCE, "level_3", player );
				}
			}
		}		
	
		return true;		
	}
	
	//returns true if player->mem_point position is within given range
	override bool CheckMemoryPointVerticalDistance( float max_dist, string selection, PlayerBase player )
	{
		if ( player )
		{
			//check vertical distance
			vector player_pos = player.GetPosition();
			vector pos;
			
			if ( MemoryPointExists( selection ) )
			{
				pos = ModelToWorld( GetMemoryPointPos( selection ) );
			}
			
			if ( Math.AbsFloat( player_pos[1] - pos[1] ) <= max_dist )
			{
				return true;
			}
			else
			{
				return false;
			}
		}			

		return true;
	}	
	// ---	
	
	//--- ACTION CONDITIONS
	//returns dot product of player->construction direction based on existing/non-existing reference point
	override bool IsFacingPlayer( PlayerBase player, string selection )
	{
		vector ref_pos;
		vector ref_dir;
		vector player_dir;
		float dot;
		bool has_memory_point = MemoryPointExists( selection );
		
		if ( has_memory_point )
		{
			ref_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			ref_dir = ref_pos - GetPosition();
		}
		else
		{
			ref_pos = GetPosition();
			ref_dir = ref_pos - player.GetPosition();
		}
		
		ref_dir.Normalize();
		ref_dir[1] = 0;				//ignore height
		
		player_dir = player.GetDirection();
		player_dir.Normalize();
		player_dir[1] = 0;			//ignore height
		
		if ( ref_dir.Length() != 0 )
		{
			dot = vector.Dot( player_dir, ref_dir );
		}
		
		if ( has_memory_point )
		{
			if ( dot < 0 && Math.AbsFloat( dot ) > MIN_ACTION_DETECTION_ANGLE_RAD )
			{
				return true;
			}
		}
		else
		{
			if ( dot > 0 && Math.AbsFloat( dot ) > MIN_ACTION_DETECTION_ANGLE_RAD )
			{
				return true;
			}
		}
		
		return false;
	}
		
	override bool IsFacingCamera( string selection )
	{
		vector ref_pos;
		vector ref_dir;
		vector cam_dir = GetGame().GetCurrentCameraDirection();
		
		if ( MemoryPointExists( selection ) )
		{
			ref_pos = ModelToWorld( GetMemoryPointPos( selection ) );
			ref_dir = ref_pos - GetPosition();
			
			ref_dir.Normalize();
			ref_dir[1] = 0;		//ignore height
			
			cam_dir[1] = 0;		//ignore height
			
			if ( ref_dir.Length() > 0.5 )		//if the distance (m) is too low, ignore this check
			{
				float dot = vector.Dot( cam_dir, ref_dir );
			
				if ( dot < 0 )	
				{
					return true;
				}
			}
		}

		return false;
	}	
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionFoldBaseBuildingObject);
	}	
}