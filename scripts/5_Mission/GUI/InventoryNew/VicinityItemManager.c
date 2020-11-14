class VicinityItemManager
{
	private const float UPDATE_FREQUENCY 			= 0.25;
	private const float VICINITY_DISTANCE			= 0.5;
	private const float VICINITY_ACTOR_DISTANCE		= 3.0;
	private const float VICINITY_CONE_DISTANCE		= 3;
	private const float VICINITY_CONE_REACH_DISTANCE	= 2.0;
	private const float VICINITY_CONE_ANGLE 			= 30;
	private const float VICINITY_CONE_RADIANS 		= 0.5;
	private const string CE_CENTER 					= "ce_center";
	private const float HEIGHT_OFFSET 				= 0.2;
	private const int OBJECT_OBSTRUCTION_WEIGHT		= 10000; //in grams
	private const float CONE_HEIGHT_MIN 				= -0.5;
	private const float CONE_HEIGHT_MAX 				= 3.0;
	
	private ref 	array<EntityAI> m_VicinityItems = new ref array<EntityAI>;
	private ref 	array<ref CargoBase> m_VicinityCargos = new ref array<ref CargoBase>;
	private 		float m_RefreshCounter;
	private static ref VicinityItemManager s_Instance;
	
	static VicinityItemManager GetInstance ()
	{
		if (!s_Instance)
			s_Instance = new VicinityItemManager;
		return s_Instance;
	}
	
	void Init()
	{
		//Print("VicinityItemManager Init");
	}
	
	array<EntityAI> GetVicinityItems()
	{
		return m_VicinityItems;
	}
	
	void AddVicinityItems( Object object )
	{
		EntityAI inventory_item = EntityAI.Cast( object );
				
		if ( inventory_item )
		{
			if ( m_VicinityItems.Find( inventory_item ) == INDEX_NOT_FOUND && GameInventory.CheckManipulatedObjectsDistances( inventory_item, GetGame().GetPlayer(), VICINITY_CONE_REACH_DISTANCE + 1.0 ) )
			{
				m_VicinityItems.Insert( inventory_item );
			}
		}
	}

	array<ref CargoBase> GetVicinityCargos()
	{
		return m_VicinityCargos;
	}
	
	void AddVicinityCargos( CargoBase object )
	{
		if ( m_VicinityCargos.Find( object ) == INDEX_NOT_FOUND /*&& GameInventory.CheckManipulatedObjectsDistances( inventory_item, GetGame().GetPlayer(), VICINITY_CONE_REACH_DISTANCE ) */ )
		{
			m_VicinityCargos.Insert( object );
		}
	}
	
	void ResetRefreshCounter()
	{
		m_RefreshCounter = 0;
	}
	
	//per frame call
	void Update( float delta_time )
	{		
		m_RefreshCounter += delta_time;
		
		//Call RefreshVicinityItems() every UPDATE_FREQUENCY seconds
		if ( m_RefreshCounter >= UPDATE_FREQUENCY )
		{
			RefreshVicinityItems();
			//Print("*---------------------*Refreshing vicinity*---------------------*");
			m_RefreshCounter = 0;
		}
	}
	
	bool ExcludeFromContainer_Phase1 (Object actor_in_radius)
	{
		EntityAI entity_ai;
		if ( !Class.CastTo( entity_ai, actor_in_radius) )
			return true;
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		if ( entity_ai == player )
			return true;
		if ( entity_ai.IsParticle() )
			return true;
		if ( entity_ai.IsScriptedLight() )
			return true;
		if ( entity_ai.IsBeingPlaced() )
			return true;
		if ( entity_ai.IsHologram() )
			return true;
		if ( entity_ai.IsMan() || entity_ai.IsZombie() || entity_ai.IsZombieMilitary() )
		{
			//visibility cone check
			vector object_center_pos = entity_ai.GetPosition();
			
			if ( entity_ai && entity_ai.IsMan() )
			{
				PlayerBase vicinity_player = PlayerBase.Cast( entity_ai );
				if ( vicinity_player )
				{
					int bone_index_player = vicinity_player.GetBoneIndexByName( "spine3" );
					object_center_pos = vicinity_player.GetBonePositionWS( bone_index_player );
				}
			}
			else if ( entity_ai && (entity_ai.IsZombie() || entity_ai.IsZombieMilitary()) )
			{
				ZombieBase vicinity_zombie = ZombieBase.Cast( entity_ai );
				if ( vicinity_zombie )
				{
					int bone_index_zombie = vicinity_zombie.GetBoneIndexByName( "spine3" );
					object_center_pos = vicinity_zombie.GetBonePositionWS( bone_index_zombie );
				}
			}
			
			vector entity_direction = player.GetPosition() - object_center_pos;
			entity_direction.Normalize();
			entity_direction[1] = 0; //ignore height
			
			vector player_direction =  MiscGameplayFunctions.GetHeadingVector( player );
			player_direction.Normalize();
			player_direction[1] = 0; //ignore height
			
			float dot_rad = vector.Dot( player_direction, entity_direction );
			
			if ( dot_rad > -0.5 )
			{
				//Print("~~~actor_in_radius out of VICINITY_CONE_RADIANS~~~");
				//Print("~~~dot_rad: ~~~: " + dot_rad);
				return true;
			}
		}
		return false;
	}
	
	bool ExcludeFromContainer_Phase2 (Object object_in_radius)
	{
		EntityAI entity_ai;
		ItemBase item;

		if ( !Class.CastTo( entity_ai, object_in_radius) )
			return true;
		if ( entity_ai == PlayerBase.Cast(GetGame().GetPlayer()) )
			return true;
		if ( entity_ai.IsParticle() )
			return true;
		if ( entity_ai.IsScriptedLight() )
			return true;
		if ( entity_ai.IsBeingPlaced() )
			return true;
		if ( entity_ai.IsHologram() )
			return true;
		if ( !Class.CastTo( item, object_in_radius) )
			return true;
		if ( !item.IsTakeable() )
			return true;
		
		return false;
	}
	
	bool ExcludeFromContainer_Phase3 (Object object_in_cone)
	{
		EntityAI entity_ai;
		ItemBase item;
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		//Print("---object in cone: " + object_in_cone);
		if ( !Class.CastTo( entity_ai, object_in_cone) )
			return true;
		if ( entity_ai == player )
			return true;
		if ( entity_ai.IsParticle() )
			return true;
		if ( entity_ai.IsScriptedLight() )
			return true;
		if ( entity_ai.IsBeingPlaced() )
			return true;
		if ( entity_ai.IsHologram() )
			return true;
		if ( !Class.CastTo( item, object_in_cone) && !object_in_cone.IsTransport() && !PASBroadcaster.Cast( object_in_cone ) )
			return true;
		if ( item && !item.IsTakeable() )
			return true;

		return false;
	}
	
	bool CanIgnoreDistanceCheck (EntityAI entity_ai)
	{
	    return entity_ai.IsTransport() || entity_ai.CanUseConstruction();
	}
	
	//per frame call
	void RefreshVicinityItems()
	{
		array<Object> objects_in_vicinity = new array<Object>;
		array<CargoBase> proxyCargos = new array<CargoBase>;
		array<Object> filtered_objects = new array<Object>;
		EntityAI entity_ai;
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if ( m_VicinityItems ) 
		{
			m_VicinityItems.Clear();
		}
		
		if (m_VicinityCargos)
			m_VicinityCargos.Clear();

		//1. GetAll actors in VICINITY_ACTOR_DISTANCE
//		DebugActorsSphereDraw( VICINITY_ACTOR_DISTANCE );
		GetGame().GetObjectsAtPosition3D( player.GetPosition(), VICINITY_ACTOR_DISTANCE, objects_in_vicinity, proxyCargos );		
		
		// no filtering for cargo (initial implementation)		
		for ( int ic = 0; ic < proxyCargos.Count(); ic++ )
			AddVicinityCargos( proxyCargos[ic] );

		//filter unnecessary objects beforehand
		for ( int i = 0; i < objects_in_vicinity.Count(); i++ )
		{
			Object actor_in_radius = objects_in_vicinity.Get(i);
			//Print("---actor in radius: " + actor_in_radius);
			if (ExcludeFromContainer_Phase1(actor_in_radius))
				continue;
				
			if ( filtered_objects.Find( actor_in_radius ) == INDEX_NOT_FOUND )
			{
				//Print("+0+filtered_objects in radius inserting: " + actor_in_radius);
				filtered_objects.Insert( actor_in_radius );
			}
		}
		
		if ( objects_in_vicinity ) 
		{
			objects_in_vicinity.Clear();
		}
		
		//2. GetAll Objects in VICINITY_DISTANCE
		GetGame().GetObjectsAtPosition3D( player.GetPosition(), VICINITY_DISTANCE, objects_in_vicinity, proxyCargos );		
//		DebugObjectsSphereDraw( VICINITY_DISTANCE );
		
		//filter unnecessary objects beforehand
		for ( int j = 0; j < objects_in_vicinity.Count(); j++ )
		{
			Object object_in_radius = objects_in_vicinity.Get(j);
			//Print("---object in radius: " + object_in_radius);
			if (ExcludeFromContainer_Phase2(object_in_radius))
				continue;

			if ( filtered_objects.Find( object_in_radius ) == INDEX_NOT_FOUND )
			{
				//Print("+1+filtered_objects in radius inserting: " + object_in_radius);
				filtered_objects.Insert( object_in_radius );
			}
		}
		
		if ( objects_in_vicinity ) 
		{
			objects_in_vicinity.Clear();
		}
		
		//3. Add objects from GetEntitiesInCone
		vector headingDirection = MiscGameplayFunctions.GetHeadingVector( player );
		DayZPlayerUtils.GetEntitiesInCone( player.GetPosition(), headingDirection, VICINITY_CONE_ANGLE, VICINITY_CONE_REACH_DISTANCE, CONE_HEIGHT_MIN, CONE_HEIGHT_MAX, objects_in_vicinity);

//		DebugConeDraw( player.GetPosition(), VICINITY_CONE_ANGLE );

		//filter unnecessary objects beforehand
		for ( int k = 0; k < objects_in_vicinity.Count(); k++ )
		{
			Object object_in_cone = objects_in_vicinity.Get(k);
			if (ExcludeFromContainer_Phase3(object_in_cone))
				continue;

			if ( filtered_objects.Find( object_in_cone ) == INDEX_NOT_FOUND )
			{
				//Print("+2+filtered_objects in cone inserting: " + object_in_cone);
				filtered_objects.Insert( object_in_cone );
			}
		}

		//4. Filter filtered objects with RayCast from the player ( head bone )
		for ( int l = 0; l < filtered_objects.Count(); l++ )
		{
			Object filtered_object = filtered_objects.Get(l);
			bool is_obstructed = false;
			Class.CastTo( entity_ai, filtered_object );
			
			//distance check
			if ( vector.DistanceSq( player.GetPosition(), entity_ai.GetPosition() ) > VICINITY_CONE_REACH_DISTANCE * VICINITY_CONE_REACH_DISTANCE )
			{
			    if ( !CanIgnoreDistanceCheck( entity_ai ) )
			    {
			        //Print("Distance ckeck pre: " + entity_ai + " failed" );
			        continue;
			    }
			}
			
			is_obstructed = IsObstructed(filtered_object);

			
			//Print("is_obstructed: " + is_obstructed);
			
			if ( !is_obstructed )
			{
				//Print("AddvicinityItem: " + filtered_object);
				AddVicinityItems( filtered_object );
			}
		}	
	}
	
	bool IsObstructed(Object filtered_object)
	{
		return MiscGameplayFunctions.IsObjectObstructed(filtered_object);
	}
	
	//Debug functions
	
	ref array<Shape> rayShapes = new array<Shape>();
	
	private void DebugActorsSphereDraw( float radius )
	{
		CleanupDebugShapes(rayShapes);
		
		rayShapes.Insert( Debug.DrawSphere( GetGame().GetPlayer().GetPosition(), radius, COLOR_GREEN, ShapeFlags.TRANSP|ShapeFlags.WIREFRAME ) );
	}
	
	private void DebugObjectsSphereDraw( float radius )
	{		
		rayShapes.Insert( Debug.DrawSphere( GetGame().GetPlayer().GetPosition(), radius, COLOR_GREEN, ShapeFlags.TRANSP|ShapeFlags.WIREFRAME ) );
	}
	
	private void DebugRaycastDraw( vector start, vector end )
	{
		rayShapes.Insert( Debug.DrawArrow( start, end, 0.5, COLOR_YELLOW ) );
	}
	
	private void DebugConeDraw( vector start, float cone_angle )
	{
		vector endL, endR;
		float playerAngle;
		float xL,xR,zL,zR;
		
		playerAngle = MiscGameplayFunctions.GetHeadingAngle( PlayerBase.Cast( GetGame().GetPlayer() ) );

		endL = start;
		endR = start;
		xL = VICINITY_CONE_REACH_DISTANCE * Math.Cos( playerAngle + Math.PI_HALF + cone_angle * Math.DEG2RAD ); // x
		zL = VICINITY_CONE_REACH_DISTANCE * Math.Sin( playerAngle + Math.PI_HALF + cone_angle * Math.DEG2RAD ); // z
		xR = VICINITY_CONE_REACH_DISTANCE * Math.Cos( playerAngle + Math.PI_HALF - cone_angle * Math.DEG2RAD ); // x
		zR = VICINITY_CONE_REACH_DISTANCE * Math.Sin( playerAngle + Math.PI_HALF - cone_angle * Math.DEG2RAD ); // z
		endL[0] = endL[0] + xL;
		endL[2] = endL[2] + zL;
		endR[0] = endR[0] + xR;
		endR[2] = endR[2] + zR;

		rayShapes.Insert( Debug.DrawLine( start, endL, COLOR_GREEN ) );
		rayShapes.Insert( Debug.DrawLine( start, endR, COLOR_GREEN ) ) ;
		rayShapes.Insert( Debug.DrawLine( endL, endR, COLOR_GREEN ) );
	}
	
	private void CleanupDebugShapes(array<Shape> shapesArr)
	{
		for ( int it = 0; it < shapesArr.Count(); ++it )
		{
			Debug.RemoveShape( shapesArr[it] );
		}
		
		shapesArr.Clear();
	}
}