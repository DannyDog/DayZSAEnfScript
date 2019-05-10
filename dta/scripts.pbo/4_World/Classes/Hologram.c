class Hologram
{
	protected EntityAI 			m_Parent; 		
	protected EntityAI 			m_Projection; 	
	protected ItemBase 			m_ProjectionIB; 	
	protected PlayerBase 		m_Player;
	protected ProjectionTrigger m_ProjectionTrigger;

	protected bool 				m_IsColliding;
	protected bool 				m_IsCollidingGPlot;
	protected bool 				m_IsSlope;
	protected bool 				m_IsCollidingPlayer;
	protected bool 				m_IsFloating;
	protected bool 				m_UpdatePosition;
	protected bool 				m_IsHidden;

	protected vector 			m_DefaultOrientation;
	protected vector			m_Rotation;
	protected vector			m_y_p_r_previous;
	protected vector 			m_ContactDir;
	protected const string 		ANIMATION_PLACING 				= "Placing";
	protected const string 		ANIMATION_INVENTORY 			= "Inventory";
	protected const string 		SELECTION_PLACING 				= "placing";
	protected const string 		SELECTION_INVENTORY 			= "inventory";

	protected const float 		SMALL_PROJECTION_RADIUS 		= 1;
	protected const float 		SMALL_PROJECTION_GROUND 		= 2;
	protected const float		DISTANCE_SMALL_PROJECTION		= 1;
	protected const float		LARGE_PROJECTION_DISTANCE_LIMIT	= 6;
	protected const float 		PROJECTION_TRANSITION			= 0.25;
	protected const float 		LOOKING_TO_SKY					= 0.75;
	
	protected float 			m_SlopeTolerance;
	protected bool				m_AlignToTerrain;
	protected vector 			m_YawPitchRollLimit;
	
	protected ref set<string> 	m_SelectionsToRefresh 			= new set<string>;

	/*
	Shape m_DebugPlugArrowLeftClose;
	Shape m_DebugPlugArrowRightClose;
	Shape m_DebugPlugArrowLeftFar;
	Shape m_DebugPlugArrowRightFar;
	*/
		
	void Hologram( PlayerBase player, vector pos)
	{	
		m_Player = player;
		m_Parent = m_Player.GetHumanInventory().GetEntityInHands();
		m_Projection = NULL;
		m_ProjectionIB = NULL;
		m_ProjectionTrigger = NULL;
		m_UpdatePosition = true;
		m_Rotation = "0 0 0";
		
		EntityAI projection_entity;
		
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
		{	
			projection_entity = EntityAI.Cast( GetGame().CreateObject( ProjectionBasedOnParent(), pos ) );
			SetProjectionEntity( projection_entity );
			SetProjectionIB( projection_entity );
			SetAnimations();
		}
		else
		{
			projection_entity = EntityAI.Cast( GetGame().CreateObject( ProjectionBasedOnParent(), pos, true, false, false ) );
			SetProjectionEntity( projection_entity );	
			SetProjectionIB( projection_entity );	
			SetAnimations();
			CreateTrigger();
		}
		
		if ( !projection_entity.IsInherited(GardenBase)) // Garden plot is a special case
		{
			GetProjectionIB().SetIsHologram( true );
		}
		
		string config_path_slope = "CfgVehicles" + " " + GetProjectionEntity().GetType() + " " + "slopeTolerance";
		if ( GetGame().ConfigIsExisting( config_path_slope ) )
		{
			m_SlopeTolerance = GetGame().ConfigGetFloat( config_path_slope );
		}
		
		string config_path_align = "CfgVehicles" + " " + GetProjectionEntity().GetType() + " " + "alignHologramToTerain";
		if ( GetGame().ConfigIsExisting( config_path_align ) )
		{
			m_AlignToTerrain = GetGame().ConfigGetInt( config_path_align );
		}
		
		string config_path_w_p_r = "CfgVehicles" + " " + GetProjectionEntity().GetType() + " " + "yawPitchRollLimit";
		if ( GetGame().ConfigIsExisting( config_path_w_p_r ) )
		{
			m_YawPitchRollLimit = GetGame().ConfigGetVector( config_path_w_p_r );
		}
	}
	
	void ~Hologram()
	{
		if ( GetGame() )
		{
			if ( m_Projection )
			{
				GetGame().ObjectDelete( m_Projection );
			}
	
			if ( m_ProjectionTrigger )
			{
				GetGame().ObjectDelete( m_ProjectionTrigger );
			}
		}
	}
	
	void SetAnimations()
	{
		if ( m_Projection.HasAnimation( ANIMATION_PLACING ) )
		{
			m_Projection.SetAnimationPhase( ANIMATION_PLACING, 0 );
			SetSelectionToRefresh( SELECTION_PLACING );

			if ( m_Projection.HasAnimation( ANIMATION_INVENTORY ) )
			{
				m_Projection.SetAnimationPhase( ANIMATION_INVENTORY, 1 );
			}
		}
		else
		{
			UpdateSelections();
			SetSelectionToRefresh( SELECTION_INVENTORY );
		}
	}
	
	// Updates selections on hologram object so they reflect the state of the parent object's selections.
	void UpdateSelections()
	{
		string cfg_access = "CfgVehicles " + m_Projection.GetType() + " AnimationSources ";
		
		if ( GetGame().ConfigIsExisting(cfg_access) )
		{
			int cfg_access_count = g_Game.ConfigGetChildrenCount(cfg_access);

			for ( int i = 0; i < cfg_access_count; ++i )
			{
				string found_anim;
				GetGame().ConfigGetChildName(cfg_access, i, found_anim);
				
				float anim_phase = m_Parent.GetAnimationPhase(found_anim);
				m_Projection.SetAnimationPhase(found_anim, anim_phase);
			}
		}
	}

	string ProjectionBasedOnParent()
	{
		ItemBase item_in_hands = ItemBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );

		if ( item_in_hands && item_in_hands.CanMakeGardenplot() )
		{
			return "GardenPlot";
		}
		
		//Camping & Base building
		if ( item_in_hands.IsInherited( TentBase ) || item_in_hands.IsInherited( FenceKit ) || item_in_hands.IsInherited( WatchtowerKit ) )
		{
			return item_in_hands.GetType() + "Placing";
		}
		
		return item_in_hands.GetType();
	}
		
	// update loop for visuals and collisions of the hologram
	void UpdateHologram( float timeslice )
	{		
		if ( !m_Parent )
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(m_Player.TogglePlacingLocal);
			
			return
		}
		
		if ( m_Player.IsSwimming() || m_Player.IsClimbingLadder() || m_Player.IsRaised() )
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(m_Player.TogglePlacingLocal);
			
			return
		}
		
		EvaluateCollision();
		RefreshTrigger();
		CheckPowerSource();	
		RefreshVisual();

		if ( !GetUpdatePosition() )
		{
			return;
		} 

		// update hologram position	
		SetProjectionPosition( GetProjectionEntityPosition( m_Player ) );
		SetProjectionOrientation( AlignProjectionOnTerrain( timeslice ) );		
		m_Projection.OnHologramBeingPlaced( m_Player );
	}
	
	vector AlignProjectionOnTerrain( float timeslice )
	{
		vector y_p_r;
		
		if ( m_AlignToTerrain )
		{
			vector projection_orientation_angles = GetDefaultOrientation() + GetProjectionRotation();	
			vector mat0[3];
			vector mat1[3];
			vector mat2[3];
			vector projection_position = m_Projection.GetPosition();
			vector normal;
			
			if ( m_ContactDir.Length() > 0 )
			{
				normal = m_ContactDir;
			} 
			else
			{
				normal = GetGame().SurfaceGetNormal( projection_position[0], projection_position[2] );
			}
			
			vector angles = normal.VectorToAngles();
			angles[1] = angles[1] + 270;
					
			angles[0] = Math.Clamp( angles[0], 0, 360 ); 
			angles[1] = Math.Clamp( angles[1], 0, 360 );
			angles[2] = Math.Clamp( angles[2], 0, 360 );
				
			projection_orientation_angles[0] = projection_orientation_angles[0] + ( 360 - angles[0] );
			
			Math3D.YawPitchRollMatrix( projection_orientation_angles, mat0 );
			Math3D.YawPitchRollMatrix( angles, mat1 );
			Math3D.MatrixMultiply3( mat1, mat0, mat2 );	
			
			y_p_r = Math3D.MatrixToAngles( mat2 );
		}
		else
		{
			y_p_r = GetDefaultOrientation() + GetProjectionRotation();
			
			if ( y_p_r[0] > 180 )
			{
				y_p_r[0] = y_p_r[0] - 360;
			}
			
			if ( y_p_r[0] < -180 )
			{
				y_p_r[0] = y_p_r[0] + 360;
			}
		}	
		
		return SmoothProjectionMovement( y_p_r, timeslice );
	}
	
	vector SmoothProjectionMovement( vector y_p_r, float timeslice )
	{	
		if ( m_y_p_r_previous )
		{					
			if ( Math.AbsFloat( y_p_r[0] - m_y_p_r_previous[0] ) > 100 )
			{												
				if ( y_p_r[0] > 0 )
				{		
					m_y_p_r_previous[0] = m_y_p_r_previous[0] + 360; 
				}
				
				if ( y_p_r[0] < 0 )
				{		
					m_y_p_r_previous[0] = m_y_p_r_previous[0] - 360;
				}
			}
			
			y_p_r[0] = Math.Lerp( m_y_p_r_previous[0], y_p_r[0], 15 * timeslice );
			y_p_r[1] = Math.Lerp( m_y_p_r_previous[1], y_p_r[1], 15 * timeslice );
			y_p_r[2] = Math.Lerp( m_y_p_r_previous[2], y_p_r[2], 15 * timeslice );
		}
		
		m_y_p_r_previous = y_p_r;
		
		return y_p_r;
	}
	
	void CreateTrigger()
	{
		Class.CastTo(m_ProjectionTrigger,  g_Game.CreateObject( "ProjectionTrigger", GetProjectionPosition(), true ) );

		m_ProjectionTrigger.SetOrientation( GetProjectionOrientation() );
		m_ProjectionTrigger.SetParentObject( this );
		m_ProjectionTrigger.SetParentOwner( m_Player );
	}

	void RefreshTrigger()
	{
		vector min_max[2];
		m_Projection.GetCollisionBox( min_max );

		m_ProjectionTrigger.SetPosition( GetProjectionPosition() );
		m_ProjectionTrigger.SetOrientation( GetProjectionOrientation() );
		m_ProjectionTrigger.SetExtents(min_max[0], min_max[1]);	
	}

	void EvaluateCollision()
	{	
		bool is_surface_water = IsSurfaceWater( m_Projection.GetPosition() );		
		
		if ( IsHidden() || IsCollidingBBox() || IsCollidingPlayer() || IsCollidingBase() || IsCollidingGPlot() || IsCollidingZeroPos() || IsBehindObstacle() || IsCollidingAngle() )
		{
			SetIsColliding( true );							
		}	
		else
		{
			if( IsProjectionTrap() )
			{
				if( m_Projection.IsInherited( TrapSpawnBase ) )
				{
					TrapSpawnBase trap_spawn_base;
					Class.CastTo(trap_spawn_base,  m_Projection );
					SetIsColliding( !trap_spawn_base.IsPlaceableAtPosition( m_Projection.GetPosition() ) );
				}
				else
				{
					TrapBase trap_base;
					Class.CastTo(trap_base,  m_Projection );
					SetIsColliding( !trap_base.IsPlaceableAtPosition( m_Projection.GetPosition() ) );
				}
			}
			else
			{
				if( is_surface_water )
				{
					SetIsColliding( true );
				}
				else
				{
					SetIsColliding( false );
				}				
			}
		}
	}
	
	bool IsCollidingAngle()
	{
		vector projection_orientation = m_Projection.GetOrientation();
		
		if ( Math.AbsFloat( projection_orientation[1] ) > m_YawPitchRollLimit[1] || Math.AbsFloat(  projection_orientation[2] ) > m_YawPitchRollLimit[2] )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool IsCollidingBBox()
	{
		vector center;
		vector relative_ofset; //we need to lift BBox, because it is calculated from the bottom of projection, and not from the middle
		vector absolute_ofset = "0 0.01 0"; //we need to lift BBox even more, because it colliddes with house floors due to various reasons (probably geometry or float imperfections)
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		ref array<Object> excluded_objects = new array<Object>;
		ref array<Object> collided_objects = new array<Object>;
		
		m_Projection.GetCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );

		if ( GetGame().IsBoxColliding( center, orientation, edge_length, excluded_objects, collided_objects ) )
		{	
			/*
			for( int i = 0; i < collided_objects.Count(); i++ )
			{
				Object obj_collided = collided_objects[i];
				Print("obj_collided with: " + obj_collided );
			}
			*/
			
			return true;	
		}
		else
		{
			return false;			
		}
	}

	bool IsCollidingBase()
	{
		/*
		if(m_DebugPlugArrowLeftClose)
		{
			m_DebugPlugArrowLeftClose.Destroy();
			m_DebugPlugArrowLeftClose = NULL; 

			m_DebugPlugArrowRightClose.Destroy();
			m_DebugPlugArrowRightClose = NULL; 

			m_DebugPlugArrowLeftFar.Destroy();
			m_DebugPlugArrowLeftFar = NULL; 

			m_DebugPlugArrowRightFar.Destroy();
			m_DebugPlugArrowRightFar = NULL; 
		}
		*/
		
		vector from_left_close = m_Projection.CoordToParent( GetLeftCloseProjectionVector() );
		vector to_left_close_down = from_left_close + "0 -1 0";

		vector from_right_close = m_Projection.CoordToParent( GetRightCloseProjectionVector() );
		vector to_right_close_down = from_right_close + "0 -1 0";

		vector from_left_far = m_Projection.CoordToParent( GetLeftFarProjectionVector() );
		vector to_left_far_down = from_left_far + "0 -1 0";

		vector from_right_far = m_Projection.CoordToParent( GetRightFarProjectionVector() );
		vector to_right_far_down = from_right_far + "0 -1 0";
		
		/*
		m_DebugPlugArrowLeftClose = DrawArrow( from_left_close, to_left_close_down );
		m_DebugPlugArrowRightClose = DrawArrow( from_right_close, to_right_close_down );
		m_DebugPlugArrowLeftFar = DrawArrow( from_left_far, to_left_far_down );
		m_DebugPlugArrowRightFar = DrawArrow( from_right_far, to_right_far_down );
		*/

		vector contact_pos_left_close;
		vector contact_pos_right_close;
		vector contact_pos_left_far;
		vector contact_pos_right_far;
		vector contact_dir_left_close;
		vector contact_dir_right_close;
		vector contact_dir_left_far;
		vector contact_dir_right_far;
		int contact_component_left_close;
		int contact_component_right_close;
		int contact_component_left_far;
		int contact_component_right_far;
		set<Object> results_left_close = new set<Object>;
		set<Object> results_right_close = new set<Object>;
		set<Object> results_left_far = new set<Object>;
		set<Object> results_right_far = new set<Object>;
		Object obj_left_close;
		Object obj_right_close;
		Object obj_left_far;
		Object obj_right_far;

		DayZPhysics.RaycastRV( from_left_close, to_left_close_down, contact_pos_left_close, contact_dir_left_close, contact_component_left_close, results_left_close, m_Projection, m_Projection, false, false );
		DayZPhysics.RaycastRV( from_right_close, to_right_close_down, contact_pos_right_close, contact_dir_right_close, contact_component_right_close, results_right_close,m_Projection, m_Projection, false, false );
		DayZPhysics.RaycastRV( from_left_far, to_left_far_down, contact_pos_left_far, contact_dir_left_far, contact_component_left_far, results_left_far, m_Projection, m_Projection, false, false );
		DayZPhysics.RaycastRV( from_right_far, to_right_far_down, contact_pos_right_far, contact_dir_right_far, contact_component_right_far, results_right_far, m_Projection, m_Projection, false, false );

		//Print("results_left_close.Count(): " + results_left_close.Count() );
		for( int j = 0; j < results_left_close.Count(); j++ )
		{
			obj_left_close = results_left_close[j];
			//Print("obj_left_close hit: " + obj_left_close );
		}

		//Print("results_right_close.Count(): " + results_right_close.Count() );
		for( int k = 0; k < results_right_close.Count(); k++ )
		{
			obj_right_close = results_right_close[k];
			//Print("obj_right_close hit: " + obj_right_close );
		}
	
		//Print("results_left_far.Count(): " + results_left_far.Count() );
		for( int l = 0; l < results_left_far.Count(); l++ )
		{
			obj_left_far = results_left_far[l];
			//Print("obj_left_far hit: " + obj_left_far );
		}

		//Print("results_right_far.Count(): " + results_right_far.Count() );
		for( int m = 0; m < results_right_far.Count(); m++ )
		{
			obj_right_far = results_right_far[m];
			//Print("obj_right_far hit: " + obj_right_far );
		}
			
		if ( IsBaseStatic( obj_left_close, obj_right_close, obj_left_far, obj_right_far ) )
		{
			if ( IsBaseIntact( obj_left_close, obj_right_close, obj_left_far, obj_right_far ) )
			{
				if ( IsBaseFlat( contact_pos_left_close, contact_pos_right_close, contact_pos_left_far, contact_pos_right_far ) )
				{ 	
					//Print("The base is static object and the base is intact and the base is flat");	
					return false;	
				}
			}
		}
		
		//Print("The base is either not static object or the base is not intact or the base is not flat");
		return true;
	}

	bool IsCollidingGPlot()
	{
		if ( m_IsCollidingGPlot )
		{
			//Print("NOT suitable terrain for garden plot");
			return true; 
		}
		else
		{
			//Print("Suitable terrain for garden plot");
			return false;
		}
	}

	bool IsCollidingZeroPos()
	{
		vector origin = Vector(0, 0, 0,);

		if ( GetProjectionPosition() == origin )
		{
			//Print("NOT able to place, projection in origin");
			return true; 
		}
		else
		{
			//Print("Projection not in origin");
			return false;
		}
	}
	
	bool IsBehindObstacle()
	{			
		vector starting_pos = GetParentEntity().GetPosition();
		vector headingDirection = MiscGameplayFunctions.GetHeadingVector(m_Player);
		array<Object> coneObjects = new array<Object>;
		vector c_MaxTargetDistance = GetProjectionPosition() - m_Player.GetPosition();
		float c_ConeAngle = c_MaxTargetDistance.Length() * 5;
	 	float c_ConeHeightMin = 0.25;
	 	float c_ConeHeightMax = 1;
		Building building;
		
		//DrawDebugCone( true, starting_pos, c_MaxTargetDistance.Length(), c_ConeAngle );
		
		DayZPlayerUtils.GetEntitiesInCone( starting_pos, headingDirection, c_ConeAngle, c_MaxTargetDistance.Length(), c_ConeHeightMin, c_ConeHeightMax, coneObjects );
		
		for ( int i = 0; i < coneObjects.Count(); i++ )
		{
			Object object = coneObjects.Get(i);
			//Print("coneObjects.Count(): " + coneObjects.Count());
			//Print("object: " + object.GetName());
			//Print("index: " + i);
					
			//Tere is always 1 object in the cone and i am not able to find out what it is, so skip the object.
			if ( coneObjects.Count() > 1 && i > 0 )
			{
				if ( object == m_Player )
				{
					//Print( "Mame playera" );
					continue;
				}
				
				if ( object == GetParentEntity() )
				{
					//Print( "Mame GetParentEntity" );
					continue;
				}
				
				if ( object == GetProjectionEntity() )
				{
					//Print( "Mame GetProjectionEntity" );
					continue;
				}
				
				if ( object.IsTree() )
				{
					//Print( "Mame strom" );
					continue;
				}
				
				if ( Class.CastTo( building, object ) )
				{
					//Print( "Mame budovu" );
					continue;
				}
				
				if ( object.IsInherited( CarTent ) )
				{
					//Print( "Mame Cartent" );
					continue;
				}
				
				//Print( "Mame obstacle" );
				return true;
			}
		}
		
		//Print("No obstacle in cone");
		return false;
	}
	/*	
	ref array<Shape> dbgConeShapes = new array<Shape>();
	
	private void DrawDebugCone(bool enabled, vector starting_pos, float MaxTargetDistance, float cone_angle )
	{
		// "cone" settings
		vector start, endL, endR;
		float playerAngle;
		float xL,xR,zL,zR;
		
		float c_MaxTargetDistance = MaxTargetDistance;
		float c_ConeAngle = cone_angle;
		
		if (enabled)
		{
			CleanupDebugShapes(dbgConeShapes);
			
			start = starting_pos;
			playerAngle = MiscGameplayFunctions.GetHeadingAngle(m_Player);
			
			// offset position of the shape in height
			start[1] = start[1] + 0.2;

			endL = start;
			endR = start;
			xL = c_MaxTargetDistance * Math.Cos(playerAngle + Math.PI_HALF + c_ConeAngle * Math.DEG2RAD); // x
			zL = c_MaxTargetDistance * Math.Sin(playerAngle + Math.PI_HALF + c_ConeAngle * Math.DEG2RAD); // z
			xR = c_MaxTargetDistance * Math.Cos(playerAngle + Math.PI_HALF - c_ConeAngle * Math.DEG2RAD); // x
			zR = c_MaxTargetDistance * Math.Sin(playerAngle + Math.PI_HALF - c_ConeAngle * Math.DEG2RAD); // z
			endL[0] = endL[0] + xL;
			endL[2] = endL[2] + zL;
			endR[0] = endR[0] + xR;
			endR[2] = endR[2] + zR;

			dbgConeShapes.Insert( Debug.DrawLine(start, endL, COLOR_BLUE) );
			dbgConeShapes.Insert( Debug.DrawLine(start, endR, COLOR_BLUE) ) ;
			dbgConeShapes.Insert( Debug.DrawLine(endL, endR, COLOR_BLUE) );
		}
	}
	
	private void CleanupDebugShapes(array<Shape> shapesArr)
	{
		for ( int it = 0; it < shapesArr.Count(); ++it )
		{
			Debug.RemoveShape( shapesArr[it] );
			shapesArr.Remove(it);
		}
	}
	*/
	bool IsBaseStatic( Object under_left_close, Object under_right_close, Object under_left_far, Object under_right_far )
	{	
		//check if the object below hologram is dynamic object. Dynamic objects like barrels can be taken to hands 
		//and item which had been placed on top of them, would stay floating in the air	
		if( under_left_close != NULL )
		{
			if( !under_left_close.IsBuilding() && !under_left_close.IsPlainObject() )
			{
				//Print("base is NOT static under_left_close");
				return false;
			}
		}
		else if( under_right_close != NULL )
		{
			if( !under_right_close.IsBuilding() && !under_right_close.IsPlainObject() )
			{
				//Print("base is NOT static under_right_close");
				return false;
			}
		}
		else if( under_left_far != NULL )
		{
			if( !under_left_far.IsBuilding() && !under_left_far.IsPlainObject() )
			{
				//Print("base is NOT static under_left_far");
				return false;
			}
		}
		else if( under_right_far != NULL )
		{
			if( !under_right_far.IsBuilding() && !under_right_far.IsPlainObject() )
			{
				//Print("base is NOT static under_right_far");
				return false;
			}
		}

		//Print("base is static");
		return true;
	}

	bool IsBaseIntact( Object under_left_close, Object under_right_close, Object under_left_far, Object under_right_far )
	{
		if( under_left_close == under_right_close && under_right_close == under_left_far && under_left_far == under_right_far )
		{
			//Print("base is intact");
			return true;			
		}
		else
		{
			//Print("base is NOT intact");
			return false;			
		}
	}

	bool IsBaseFlat( vector contact_pos_left_close, vector contact_pos_right_close, vector contact_pos_left_far, vector contact_pos_right_far )
	{
		vector projection_pos = GetProjectionPosition();
		float slope_pos_left_close = projection_pos[1] - contact_pos_left_close[1];
		float slope_pos_right_close = projection_pos[1] - contact_pos_right_close[1];
		float slope_pos_left_far = projection_pos[1] - contact_pos_left_far[1];
		float slope_pos_right_far = projection_pos[1] - contact_pos_right_far[1];
		
		/*
		Print(slope_pos_left_close);
		Print(slope_pos_right_close);
		Print(slope_pos_left_far);
		Print(slope_pos_right_far);
		*/
		
		if( slope_pos_left_close < m_SlopeTolerance )
		{
			if( slope_pos_right_close < m_SlopeTolerance )
			{
				if( slope_pos_left_far < m_SlopeTolerance )
				{
					if(  slope_pos_right_far < m_SlopeTolerance )
					{
						//Print("base is flat");
						return true;	
					}					
				}				
			}			
		}

		//Print("base is NOT flat");
		return false;			
	}
	
	/*
	Shape DrawArrow(vector from, vector to, float size = 0.5, int color = 0xFFFFFFFF, float flags = 0)
	{
		vector dir = to - from;
		dir.Normalize();
		vector dir1 = dir * size;
		size = size * 0.5;
	
		vector dir2 = dir.Perpend() * size;
	
		vector pts[5];
		pts[0] = from;
		pts[1] = to;
		pts[2] = to - dir1 - dir2;
		pts[3] = to - dir1 + dir2;
		pts[4] = to;
		
		return Shape.CreateLines(color, flags, pts, 5);
	}
	*/
	
	void CheckPowerSource()
	{
		//in range of its power source.
		if ( m_Player && m_Parent && m_Parent.HasEnergyManager() && m_Parent.GetCompEM().IsPlugged() )
		{
			// Now we know we are working with an electric device which is plugged into a power source.
			EntityAI placed_entity = m_Parent;
					
			// Unplug the device when the player is too far from the power source.
			placed_entity.GetCompEM().UpdatePlugState();
			
			// Delete local hologram when plug is rippled out and advanced placement is active
			if( GetGame().IsMultiplayer() && GetGame().IsClient() )
			{
				if ( !placed_entity.GetCompEM().IsPlugged() )
				{
					m_Player.MessageImportant("The plug was ripped out!");
					
					// Cancel placement mode
					GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(m_Player.TogglePlacingLocal);
				}
			}
		}				
	}
		
	EntityAI PlaceEntity( EntityAI entity_for_placing )
	{	
		if( !GetProjectionEntity().IsKindOf( m_Parent.GetType() ))
		{
			Class.CastTo(entity_for_placing, GetGame().CreateObject( m_Projection.GetType(), m_Projection.GetPosition() ));
		}
					
		return entity_for_placing;
	}		
		
	protected vector GetCollisionBoxSize( vector min_max[2] )
	{
		vector box_size = Vector(1,1,1);
		
		box_size[0] = min_max[1][0] - min_max[0][0];
		box_size[2] = min_max[1][2] - min_max[0][2];
		box_size[1] = min_max[1][1] - min_max[0][1];
		
		return box_size;
	}

	vector GetLeftCloseProjectionVector()
	{
		vector min_max[2];
		m_Projection.GetCollisionBox( min_max );

		return min_max[0];
	}

	vector GetRightCloseProjectionVector()
	{
		vector min_max[2];
		m_Projection.GetCollisionBox( min_max );
		min_max[1][1] = min_max[0][1];
		min_max[1][2] = min_max[0][2];

		return min_max[1];
	}

	vector GetLeftFarProjectionVector()
	{
		vector min_max[2];
		m_Projection.GetCollisionBox( min_max );
		min_max[0][2] = min_max[1][2];

		return min_max[0];
	}

	vector GetRightFarProjectionVector()
	{
		vector min_max[2];
		m_Projection.GetCollisionBox( min_max );
		min_max[1][1] = min_max[0][1]; 

		return min_max[1];
	}

	bool IsSurfaceWater( vector position )
	{
		if( GetGame().SurfaceIsSea( position[0], position[2] ) )
		{
			return true;
		}
		else if( GetGame().SurfaceIsPond( position[0], position[2] ) )
		{
			return true;
		}
		
		return false;
	}

	protected vector GetProjectionEntityPosition( PlayerBase player )
	{
		float min_projection_dist;
		float max_projection_dist; 
		m_ContactDir = vector.Zero;
		vector min_max[2];
		float projection_radius = GetProjectionRadius();
		float camera_to_player_distance = vector.Distance( GetGame().GetCurrentCameraPosition(), player.GetPosition() );

		if( projection_radius < SMALL_PROJECTION_RADIUS )	// objects with radius smaller than 1m
		{
			min_projection_dist = DISTANCE_SMALL_PROJECTION;
			max_projection_dist = DISTANCE_SMALL_PROJECTION * 2;
		}
		else
		{
			min_projection_dist = projection_radius;
			max_projection_dist = projection_radius * 2;
			max_projection_dist = Math.Clamp( max_projection_dist, 0, LARGE_PROJECTION_DISTANCE_LIMIT );
		}
		
		vector from = GetGame().GetCurrentCameraPosition();
		vector to = from + ( GetGame().GetCurrentCameraDirection() * ( max_projection_dist + camera_to_player_distance ) );
		vector contact_pos;
		int contact_component;
		set<Object> hit_object = new set<Object>;

		DayZPhysics.RaycastRV( from, to, contact_pos, m_ContactDir, contact_component, hit_object, player, m_Projection, false, false );

		float player_to_projection_distance = vector.Distance( player.GetPosition(), contact_pos );
		vector player_to_projection_vector;

		//hologram is at min distance from player
		if( player_to_projection_distance <= min_projection_dist )
		{
			player_to_projection_vector = contact_pos - player.GetPosition();		  
			player_to_projection_vector.Normalize();
			contact_pos = player.GetPosition() + (player_to_projection_vector * min_projection_dist);
		}
		//hologram is at max distance from player
		else if( player_to_projection_distance >= max_projection_dist )
		{
			player_to_projection_vector = contact_pos - player.GetPosition();	
			player_to_projection_vector.Normalize();
			//prevents the hologram to go underground/floor while hologram exceeds max_projection_dist
			player_to_projection_vector[1] = player_to_projection_vector[1] + PROJECTION_TRANSITION;		
			
			contact_pos = player.GetPosition() + (player_to_projection_vector * max_projection_dist);
			SetIsFloating( true );
		}
		//hologram is between min and max distance from player
		else
		{
			SetIsFloating( false );
		}			
			
		return contact_pos;
	}

	bool IsProjectionTrap()
	{
		if( m_Projection.IsInherited( TrapBase ) || m_Projection.IsInherited( TrapSpawnBase ) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	float GetProjectionDiameter()
	{		
		float diameter;
		float radius;
		vector diagonal;
		vector min_max[2];

		m_Projection.GetCollisionBox( min_max );
		diagonal = GetCollisionBoxSize( min_max );
		diameter = diagonal.Length();

		return diameter;	
	}

	float GetProjectionRadius()
	{		
		float diameter;
		float radius;
		vector diagonal;
		vector min_max[2];

		m_Projection.GetCollisionBox( min_max );
		diagonal = GetCollisionBoxSize( min_max );
		diameter = diagonal.Length();
		radius = diameter / 2;

		return radius;	
	}
		
	void SetUpdatePosition( bool state )
	{
		m_UpdatePosition = state;
	}

	bool GetUpdatePosition()
	{
		return m_UpdatePosition;
	}

	EntityAI GetParentEntity()
	{
		return m_Parent;
	}
	
	void SetProjectionEntity( EntityAI projection )
	{
		m_Projection = projection;
	}

	EntityAI GetProjectionEntity()
	{
		return m_Projection;
	}
	
	void SetProjectionIB( EntityAI projection )
	{
		m_ProjectionIB = ItemBase.Cast( projection );
	}

	ItemBase GetProjectionIB()
	{
		return m_ProjectionIB;
	}
	
	void SetIsFloating( bool is_floating )
	{
		m_IsFloating = is_floating;
	}
		
	void SetIsColliding( bool is_colliding )
	{
		m_IsColliding = is_colliding;
	}

	void SetIsHidden( bool is_hidden )
	{
		m_IsHidden = is_hidden;
	}
	
	void SetIsCollidingPlayer( bool is_colliding )
	{
		m_IsCollidingPlayer = is_colliding;
	}

	void SetIsCollidingGPlot( bool is_colliding_gplot )
	{
		m_IsCollidingGPlot = is_colliding_gplot;
	}

	bool IsFloating()
	{
		return m_IsFloating;
	}

	bool IsColliding()
	{
		return m_IsColliding;
	}
	
	bool IsHidden()
	{
		return m_IsHidden;
	}

	bool IsCollidingPlayer()
	{
		return m_IsCollidingPlayer;
	}

	void SetProjectionPosition( vector position )
	{	
		m_Projection.SetPosition( position );			
		
		if ( IsFloating() )
		{
			m_Projection.SetPosition( SetOnGround( position ) );
		}
	}

	void SetProjectionOrientation( vector orientation )
	{	
		m_Projection.SetOrientation( orientation );
	}
	
	vector GetProjectionRotation()
	{
		return m_Rotation;
	}
	
	void AddProjectionRotation( float addition )
	{	
		m_Rotation[0] = m_Rotation[0] + addition;
	}
	
	void SubtractProjectionRotation( float subtraction )
	{	
		m_Rotation[0] = m_Rotation[0] - subtraction;
	}
	
	vector SetOnGround( vector position )
	{
		vector from = position;
		vector ground;
		vector player_to_projection_vector;
		float projection_diameter = GetProjectionDiameter();
				
		if( projection_diameter < SMALL_PROJECTION_GROUND )
		{
			ground = Vector(0, - SMALL_PROJECTION_GROUND, 0);
		}
		else
		{
			ground = Vector(0, - projection_diameter, 0);
		}

		vector to = from + ground;
		vector contact_pos;
		//vector contact_dir;
		int contact_component;
		
		DayZPhysics.RaycastRV( from, to, contact_pos, m_ContactDir, contact_component, NULL, NULL, m_Projection, false, false );

		HideWhenClose( contact_pos );

		return contact_pos;
	}

	vector HideWhenClose( vector pos )
	{
		//if the hologram is too close to player when he looks to the sky, send the projection to away
		vector cam_dir = GetGame().GetCurrentCameraDirection();

		if( cam_dir[1] > LOOKING_TO_SKY )
		{
			pos = "0 0 0";
		}

		return pos;
	}

	vector GetProjectionPosition()
	{
		return m_Projection.GetPosition();
	}
	
	vector GetProjectionOrientation()
	{
		return m_Projection.GetOrientation();
	}
	
	vector GetDefaultOrientation()
	{
		m_DefaultOrientation = GetGame().GetCurrentCameraDirection().VectorToAngles();
		m_DefaultOrientation[1] = 0;

		return m_DefaultOrientation;
	}

	int GetHiddenSelection( string selection )
	{
		string config_path = "CfgVehicles" + " " + m_Projection.GetType() + " " + "hiddenSelections";
		ref array<string> hidden_selection_array = new array<string>;

		GetGame().ConfigGetTextArray( config_path, hidden_selection_array );	

		for (int i = 0; i < hidden_selection_array.Count(); i++)
		{
			if ( hidden_selection_array.Get(i) == selection )
			{
				return i;
			}			
		}	

		return 0;
	}

	// the function accepts string
	void SetSelectionToRefresh( string selection )
	{
		m_SelectionsToRefresh.Insert( selection );
	}

	//overloaded function to accept array of strings
	void SetSelectionToRefresh( array<string> selection )
	{
		for( int i = 0; i < selection.Count(); i++ )
		{
			m_SelectionsToRefresh.Insert( selection.Get(i) );
		}
	}
		
	void RefreshVisual()
	{
		if ( m_Projection )
		{
			string config_material = "CfgVehicles" + " " + m_Projection.GetType() + " " + "hologramMaterial";
			string hologram_material = GetGame().ConfigGetTextOut( config_material );
			string config_model = "CfgVehicles" + " " + m_Projection.GetType() + " " + "hologramMaterialPath";
			string hologram_material_path = GetGame().ConfigGetTextOut( config_model );
			string SEL_CORD_PLUGGED = m_Parent.GetCompEM().SEL_CORD_PLUGGED;
			string SEL_CORD_FOLDED = m_Parent.GetCompEM().SEL_CORD_FOLDED;
			string selection_to_refresh;

			if ( !IsColliding() )
			{
				if ( m_Parent.HasEnergyManager() )
				{
					if ( m_Parent.GetCompEM().IsPlugged() )
					{
						if ( m_Parent.GetCompEM().IsEnergySourceAtReach( GetProjectionPosition() ) )
						{
							for( int i = 0; i < m_SelectionsToRefresh.Count(); i++ )
							{
								selection_to_refresh = m_SelectionsToRefresh.Get(i);
								m_Projection.SetObjectTexture( GetHiddenSelection( selection_to_refresh ), "#(argb,8,8,3)color(0.5,0.5,0.5,0.75,ca)" );
								m_Projection.SetObjectMaterial( GetHiddenSelection( selection_to_refresh ), hologram_material_path + "\\" + hologram_material + "_powered.rvmat" );
								//Print("s komponentom, zapojeny, nekoliduje, v dosahu");
							}
							
							m_Projection.SetAnimationPhase( SEL_CORD_PLUGGED, 0);
							m_Projection.SetAnimationPhase( SEL_CORD_FOLDED, 1);	
						}							
						else
						{
							for( int j = 0; j < m_SelectionsToRefresh.Count(); j++ )
							{
								selection_to_refresh = m_SelectionsToRefresh.Get(j);
								m_Projection.SetObjectTexture( GetHiddenSelection( selection_to_refresh ), "#(argb,8,8,3)color(0.5,0.5,0.5,0.75,ca)" );
								m_Projection.SetObjectMaterial( GetHiddenSelection( selection_to_refresh ), hologram_material_path + "\\" + hologram_material + "_deployable.rvmat" );
								//Print("s komponentom, zapojeny, nekoliduje, nie v dosahu");
							}
							
							m_Projection.SetAnimationPhase( SEL_CORD_PLUGGED, 1);
							m_Projection.SetAnimationPhase( SEL_CORD_FOLDED, 0);
						}
					}
					else
					{
						for( int k = 0; k < m_SelectionsToRefresh.Count(); k++ )
						{
							selection_to_refresh = m_SelectionsToRefresh.Get(k);
							m_Projection.SetObjectTexture( GetHiddenSelection( selection_to_refresh ), "#(argb,8,8,3)color(0.5,0.5,0.5,0.75,ca)" );
							m_Projection.SetObjectMaterial( GetHiddenSelection( selection_to_refresh ), hologram_material_path + "\\" + hologram_material + "_deployable.rvmat" );
							//Print("s komponentom, nekoliduje");
						}
							m_Projection.SetAnimationPhase( SEL_CORD_PLUGGED, 1);
							m_Projection.SetAnimationPhase( SEL_CORD_FOLDED, 0);
					}			
				}
				else
				{
					for( int l = 0; l < m_SelectionsToRefresh.Count(); l++ )
					{
						selection_to_refresh = m_SelectionsToRefresh.Get(l);
						m_Projection.SetObjectTexture( GetHiddenSelection( selection_to_refresh ), "#(argb,8,8,3)color(0.5,0.5,0.5,0.75,ca)" );
						m_Projection.SetObjectMaterial( GetHiddenSelection( selection_to_refresh ), hologram_material_path + "\\" + hologram_material + "_deployable.rvmat" );
						//Print("bez komponentu, nekoliduje");
					}
				}
			}
			else
			{
				for( int m = 0; m < m_SelectionsToRefresh.Count(); m++ )
				{
					selection_to_refresh = m_SelectionsToRefresh.Get(m);
					m_Projection.SetObjectTexture( GetHiddenSelection( selection_to_refresh ), "#(argb,8,8,3)color(0.5,0.5,0.5,0.75,ca)" );
					m_Projection.SetObjectMaterial( GetHiddenSelection( selection_to_refresh ), hologram_material_path + "\\" + hologram_material + "_undeployable.rvmat" );
					//Print("koliduje");
				}
			}
		}
	}
};

class ProjectionTrigger extends Trigger
{
	protected int m_TriggerUpdateMs;
	protected Hologram m_ParentObj;
	protected PlayerBase m_Player;

	override void OnEnter( Object obj )
	{
		//Print("OnEnter");
		if ( m_ParentObj )
		{
			m_ParentObj.SetIsCollidingPlayer( true );
			m_TriggerUpdateMs = 50;
		}
	}

	override void OnLeave( Object obj )
	{
		//Print("OnLeave");
		if ( m_ParentObj )
		{
			m_ParentObj.SetIsCollidingPlayer( false );
		}
	}

	override protected void UpdateInsiders(int timeout )
	{
		super.UpdateInsiders(m_TriggerUpdateMs);
	}
	
	void SetParentObject( Hologram projection )
	{
		m_ParentObj = projection;
	}

	void SetParentOwner( PlayerBase player )
	{
		m_Player = player;
	}
}

