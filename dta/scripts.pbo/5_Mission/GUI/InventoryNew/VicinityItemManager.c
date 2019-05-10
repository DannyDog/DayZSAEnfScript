class VicinityItemManager
{
	static private const float UPDATE_FREQUENCY 			= 10;
	static private const float VICINITY_DISTANCE			= 0.5;
	static private const float VICINITY_CONE_DISTANCE		= 3;
	static private const float VICINITY_CONE_REACH_DISTANCE	= 2.0;
	static private const float VICINITY_CONE_ANGLE 			= 30;
	static private const string CE_CENTER 					= "ce_center";
	static private const float HEIGHT_OFFSET 				= 0.2;
	static private const int OBJECT_OBSTRUCTION_WEIGHT		= 10000; //in grams
	static private const float CONE_HEIGHT_MIN 				= -0.5;
	static private const float CONE_HEIGHT_MAX 				= 3.0;
	
	static private ref 	array<ref EntityAI> m_VicinityItems = new ref array<ref EntityAI>;
	static private 		int m_RefreshCounter;
	
	static void Init()
	{
		//Print("VicinityItemManager Init");
	}
	
	static array<ref EntityAI> GetVicinityItems()
	{
		return m_VicinityItems;
	}
	
	static void AddVicinityItems( Object object )
	{
		EntityAI inventory_item = EntityAI.Cast( object );
				
		if ( inventory_item )
		{
			if ( m_VicinityItems.Find( inventory_item ) == INDEX_NOT_FOUND && GameInventory.CheckManipulatedObjectsDistances( inventory_item, GetGame().GetPlayer(), VICINITY_CONE_REACH_DISTANCE ) )
			{
				m_VicinityItems.Insert( inventory_item );
			}
		}
	}
	
	static void ResetRefreshCounter()
	{
		m_RefreshCounter = 10;
	}
	
	//per frame call
	static void Update()
	{		
		//Call RefreshVicinityItems() every UPDATE_FREQUENCY seconds
		if ( m_RefreshCounter >= UPDATE_FREQUENCY )
		{
			RefreshVicinityItems();
			//Print("*---------------------*Refreshing vicinity*---------------------*");
			m_RefreshCounter = 0;
		}
		
		m_RefreshCounter++;
	}
	
	//per frame call
	static void RefreshVicinityItems()
	{
		array<Object> objects_in_vicinity = new array<Object>;
		array<CargoBase> proxyCargos = new array<CargoBase>;
		array<Object> filtered_objects = new array<Object>;
		array<ref RaycastRVResult> hit_proxy_objects = new array<ref RaycastRVResult>;	
		set<Object> hit_objects = new set<Object>;
		vector object_center_pos;
		vector object_contact_pos;
		vector object_contact_dir;
		vector raycast_start;
		int contact_component;
		EntityAI entity_ai;
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if ( m_VicinityItems ) 
		{
			m_VicinityItems.Clear();
		}

		//1. GetAll Objects in VICINITY_DISTANCE
		GetGame().GetObjectsAtPosition3D( player.GetPosition(), VICINITY_DISTANCE, objects_in_vicinity, proxyCargos );		
//		DebugShpeheresDraw();
		
		//filter unnecessary objects beforehand
		for ( int i = 0; i < objects_in_vicinity.Count(); i++ )
		{
			Object object_in_radius = objects_in_vicinity.Get(i);
			//Print("---object in radius: " + object_in_radius);
			if ( object_in_radius == GetGame().GetPlayer() ){continue;}
			if ( !object_in_radius.CastTo( entity_ai, object_in_radius) ){continue;}
			if ( entity_ai && entity_ai.IsParticle() ){continue;}			
			if ( entity_ai && entity_ai.IsScriptedLight() ){continue;}
			
			
			if ( filtered_objects.Find( object_in_radius ) == INDEX_NOT_FOUND )
			{
				//Print("+++filtered_objects in radius inserting: " + object_in_radius);
				filtered_objects.Insert( object_in_radius );
			}
		}
		
		if ( objects_in_vicinity ) 
		{
			objects_in_vicinity.Clear();
		}
		
		//2. Add objects from GetEntitiesInCone
		vector headingDirection = MiscGameplayFunctions.GetHeadingVector( player );
		DayZPlayerUtils.GetEntitiesInCone( player.GetPosition(), headingDirection, VICINITY_CONE_ANGLE, VICINITY_CONE_REACH_DISTANCE, CONE_HEIGHT_MIN, CONE_HEIGHT_MAX, objects_in_vicinity);

//		DebugConeDraw( player.GetPosition(), VICINITY_CONE_ANGLE );

		//filter unnecessary objects beforehand
		for ( int j = 0; j < objects_in_vicinity.Count(); j++ )
		{
			Object object_in_cone = objects_in_vicinity.Get(j);
			//Print("---object in cone: " + object_in_cone);
			
			//quick distance check
			
			if ( vector.DistanceSq( player.GetPosition(), object_in_cone.GetPosition() ) > VICINITY_CONE_REACH_DISTANCE * VICINITY_CONE_REACH_DISTANCE )
			{
				if ( !object_in_cone.IsTransport() && !object_in_cone.CanUseConstruction() )
				{
					//Print("Distance ckeck pre: " + object_in_cone + " failed" );
					continue;
				}	
			}
			
			if ( object_in_cone == GetGame().GetPlayer() ){continue;}
			if ( !object_in_cone.CastTo( entity_ai, object_in_cone) ){continue;}
			if ( entity_ai && entity_ai.IsParticle() ){continue;}			
			if ( entity_ai && entity_ai.IsScriptedLight() ){continue;}
			
			if ( filtered_objects.Find( object_in_cone ) == INDEX_NOT_FOUND )
			{
				//Print("+++filtered_objects in cone inserting: " + object_in_cone);
				filtered_objects.Insert( object_in_cone );
			}
		}

		//3. Filter filtered objects with RayCast from the player ( head bone )
		for ( int ii = 0; ii < filtered_objects.Count(); ii++ )
		{
			Object filtered_object = filtered_objects.Get(ii);
			bool is_obstructed = false;
			
			if ( filtered_object.MemoryPointExists(CE_CENTER) )
			{
				//Print("CE_CENTER found");
				vector modelPos = filtered_object.GetMemoryPointPos(CE_CENTER);
				object_center_pos = filtered_object.ModelToWorld(modelPos);
			}
			else
			{
				//Print("CE_CENTER DOING A BAMBOOZLE => not found");
				object_center_pos = filtered_object.GetPosition();
				object_center_pos[1] = object_center_pos[1] + HEIGHT_OFFSET;
			}
			
			//Print("-->raycast from player to: " + filtered_object);
			MiscGameplayFunctions.GetHeadBonePos( PlayerBase.Cast( GetGame().GetPlayer() ), raycast_start);
//			DebugRaycastDraw( raycast_start, object_center_pos );
				
			if ( hit_objects ) 
			{
				hit_objects.Clear();
			}
			
			if ( filtered_object.HasProxyParts() || filtered_object.CanUseConstruction() )
			{
				//Print(" :) (: pouzij proxy raycast koli proxy itemom :) (: ");
				RaycastRVParams ray_input = new RaycastRVParams( raycast_start, object_center_pos, player );
				DayZPhysics.RaycastRVProxy( ray_input, hit_proxy_objects );
				
				if ( hit_proxy_objects )
				{
					//Print(" /*- hit_proxy_objects -*/ ");
					if ( hit_proxy_objects.Count() > 0 )
					{
						if ( hit_proxy_objects[0].hierLevel > 0 )
						{
							// ignores attachments on player
							if ( !hit_proxy_objects[0].parent.IsMan() )
							{
								//Print( "hit_proxy_objects[0].obj " + hit_proxy_objects[0].obj );
								//Print( "hit_proxy_objects[0].parent" + hit_proxy_objects[0].parent );
								
								if ( hit_proxy_objects[0].parent )
								{
									EntityAI parent_entity = EntityAI.Cast( hit_proxy_objects[0].parent );
									if ( parent_entity.GetInventory().GetCargo() )
									{	
										is_obstructed = true;
									}
									else
									{
										is_obstructed = false;
									}
								}
							}	
						}
					}
				}
			}
			else
			{
				//Print(" ===>>> pouzij standardny raycast s fire geometriou koli domom a basebuildingu <<<=== ");
				DayZPhysics.RaycastRV( raycast_start, object_center_pos, object_contact_pos, object_contact_dir, contact_component, hit_objects, null, GetGame().GetPlayer(), false, false, ObjIntersectFire, 0.0, CollisionFlags.ALLOBJECTS );
			}
			//1. ignore items from list if is in ray object out of current list
			// TODO: not necessary for the first iterrationaa
			
			for ( int iii = 0; iii < hit_objects.Count(); iii++ )
			{
				Object hit_object = hit_objects.Get(iii);
				
				//Print("-->>pocas raycastu hitujem: " + hit_object);
				
				if ( hit_object.IsBuilding() )
				{
					//Print("!!!!!obstacle building: " + hit_object);
					is_obstructed = true;
				}

				if ( hit_object.IsPlainObject() )
				{
					//Print("!!!!!obstacle plaing object: " + hit_object);
					is_obstructed = true;
				}
				
				//2. ignore item from list if is in ray item with weight bigger than OBJECT_OBSTRUCTION_WEIGHT 
				EntityAI eai;
				if ( Class.CastTo( eai, hit_object ) )
				{
					if ( eai.GetItemWeight() >= 10000 )
					{
						if ( eai != filtered_object )
						{
							//Print("!!!!!obstacle vaha: " + hit_object);
							is_obstructed = true;
						}
					}
				}
			}
			
			//Print("is_obstructed: " + is_obstructed);
			
			if ( !is_obstructed )
			{
				//Print("AddvicinityItem: " + filtered_object);
				AddVicinityItems( filtered_object );
			}
		}	
	}
	
	//Debug funciions
	
	static ref array<Shape> rayShapes = new array<Shape>();
	
	static private void DebugShpeheresDraw()
	{
		CleanupDebugShapes(rayShapes);
		
		rayShapes.Insert( Debug.DrawSphere( GetGame().GetPlayer().GetPosition(), VICINITY_DISTANCE, COLOR_GREEN, ShapeFlags.TRANSP|ShapeFlags.WIREFRAME ) );
	}
	
	static private void DebugRaycastDraw( vector start, vector end )
	{
		rayShapes.Insert( Debug.DrawArrow( start, end, 0.5, COLOR_YELLOW ) );
	}
	
	static private void DebugConeDraw( vector start, float cone_angle )
	{
		vector endL, endR;
		float playerAngle;
		float xL,xR,zL,zR;
		
		playerAngle = MiscGameplayFunctions.GetHeadingAngle(GetGame().GetPlayer());

		endL = start;
		endR = start;
		xL = VICINITY_CONE_REACH_DISTANCE * Math.Cos(playerAngle + Math.PI_HALF + cone_angle * Math.DEG2RAD); // x
		zL = VICINITY_CONE_REACH_DISTANCE * Math.Sin(playerAngle + Math.PI_HALF + cone_angle * Math.DEG2RAD); // z
		xR = VICINITY_CONE_REACH_DISTANCE * Math.Cos(playerAngle + Math.PI_HALF - cone_angle * Math.DEG2RAD); // x
		zR = VICINITY_CONE_REACH_DISTANCE * Math.Sin(playerAngle + Math.PI_HALF - cone_angle * Math.DEG2RAD); // z
		endL[0] = endL[0] + xL;
		endL[2] = endL[2] + zL;
		endR[0] = endR[0] + xR;
		endR[2] = endR[2] + zR;

		rayShapes.Insert( Debug.DrawLine(start, endL, COLOR_GREEN) );
		rayShapes.Insert( Debug.DrawLine(start, endR, COLOR_GREEN) ) ;
		rayShapes.Insert( Debug.DrawLine(endL, endR, COLOR_GREEN) );
	}
	
	static private void CleanupDebugShapes(array<Shape> shapesArr)
	{
		for ( int it = 0; it < shapesArr.Count(); ++it )
		{
			Debug.RemoveShape( shapesArr[it] );
		}
		
		shapesArr.Clear();
	}
}