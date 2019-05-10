class Fence extends BaseBuildingBase
{	
	protected bool m_HasGate		= false;
	protected bool m_IsOpened 		= false;
	protected bool m_IsOpenedClient	= false;
	
	typename ATTACHMENT_WOODEN_LOG			= WoodenLog;
	typename ATTACHMENT_COMBINATION_LOCK	= CombinationLock;
	
	const string ATTACHMENT_SLOT_COMBINATION_LOCK = "Att_CombinationLock";
	
	const string SOUND_GATE_OPEN_START			= "DoorWoodTowerOpen_SoundSet";
	const string SOUND_GATE_CLOSE_START			= "DoorWoodTowerClose_start_SoundSet";
	const string SOUND_GATE_CLOSE_END			= "DoorWoodTowerClose_end_SoundSet";

	//gate openining
	const float GATE_ROTATION_ANGLE_DEG 			= 100;
	const float GATE_ROTATION_TIME_APPROX			= 2000;		//ms
	
	const float MAX_ACTION_DETECTION_ANGLE_RAD 		= 1.5;		//1.5 RAD = ~85 DEG
	
	protected EffectSound m_SoundGate_Start;
	protected EffectSound m_SoundGate_End;
	
	void Fence()
	{
		//synchronized variables
		RegisterNetSyncVariableBool( "m_HasGate" );
		RegisterNetSyncVariableBool( "m_IsOpened" );
	}
	
	override string GetConstructionKitType()
	{
		return "FenceKit";
	}
	
	//Gate
	bool HasGate()
	{
		return m_HasGate;
	}
	
	void SetGateState( bool has_gate )
	{
		m_HasGate = has_gate;
	}	
	
	void SetOpenedState( bool state )
	{
		m_IsOpened = state;
	}
	
	bool IsOpened()
	{
		return m_IsOpened;
	}
	
	bool IsLocked()
	{
		CombinationLock combination_lock = GetCombinationLock();
		if ( combination_lock && combination_lock.IsLockedOnGate() )
		{
			return true;
		}
		
		return false;
	}
		
	CombinationLock GetCombinationLock()
	{
		CombinationLock combination_lock = CombinationLock.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_COMBINATION_LOCK ) );
		return combination_lock;
	}
	
	//--- CONSTRUCTION KIT
	override vector GetKitSpawnPosition()
	{
		if ( MemoryPointExists( "kit_spawn_position" ) )
		{
			vector position;
			position = GetMemoryPointPos( "kit_spawn_position" );
			
			return ModelToWorld( position );
		}		
		
		return GetPosition();
	}	
	
	// --- INVENTORY
	override bool CanDisplayAttachmentSlot( string slot_name )
	{
		if ( slot_name == "Att_CombinationLock" )
		{
			if ( !HasGate() )
			{
				return false;
			}
		}
		
		return true;
	}

	override bool CanDisplayAttachmentCategory( string category_name )
	{
		if ( category_name == "Attachments" || category_name == "Material" )
		{
			if ( !HasBase() )
			{
				return false;
			}			
		}
		
		return true;
	}	
	// ---
	
	// --- EVENTS
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
		
		//write
		ctx.Write( m_HasGate );
		ctx.Write( m_IsOpened );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;

		//--- Fence data ---
		//has gate
		if ( !ctx.Read( m_HasGate ) )
		{
			m_HasGate = false;
			return false;
		}
		
		//is opened
		if ( !ctx.Read( m_IsOpened ) )
		{
			m_IsOpened = false;
			return false;
		}
		//---
		
		return true;
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();
		
		//set gate state
		ConstructionPart gate_part = GetConstruction().GetGateConstructionPart();
		SetGateState( gate_part.IsBuilt() );
		
		//update gate state visual
		if ( IsOpened() )
		{
			OpenFence();
		}
	}	
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if ( m_IsOpenedClient != m_IsOpened )
		{
			m_IsOpenedClient = m_IsOpened;
			
			if ( m_IsOpenedClient )
			{
				OpenFence();
			}
			else
			{
				CloseFence();
			}
		}
	}	

	
	//--- BUILD EVENTS
	//CONSTRUCTION EVENTS
	override void OnPartBuiltServer( string part_name, int action_id )
	{
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );
		
		//check gate state
		if ( constrution_part.IsGate() )
		{
			SetGateState( true );
		}
		
		super.OnPartBuiltServer( part_name, action_id );
	}
	
	override void OnPartDismantledServer( string part_name, int action_id )
	{
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );

		//check gate state
		if ( constrution_part.IsGate() )
		{
			SetGateState( false );
		}
		
		//check gate state
		if ( constrution_part.IsGate() )
		{
			if ( IsLocked() )
			{
				CombinationLock combination_lock = CombinationLock.Cast( FindAttachmentBySlotName( ATTACHMENT_SLOT_COMBINATION_LOCK ) );
				combination_lock.Unlock( this );
			}
		}
		
		super.OnPartDismantledServer( part_name, action_id );
	}
	
	override void OnPartDestroyedServer( string part_name, int action_id )
	{
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart( part_name );

		//check gate state
		if ( constrution_part.IsGate() )
		{
			SetGateState( false );
		}


		super.OnPartDestroyedServer( part_name, action_id );
	}	

	//--- ATTACHMENT & CONDITIONS
	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		//manage action initiator (AT_ATTACH_TO_CONSTRUCTION)
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			if ( player )
			{
				ConstructionActionData construction_action_data = player.GetConstructionActionData();
				
				//reset action initiator
				construction_action_data.SetActionInitiator( NULL );				
			}
		}
		//			
		
		//conditions
		if ( attachment.Type() != ATTACHMENT_WOODEN_LOG )
		{
			if ( !HasBase() )
			{
				return false;
			}
		}
		
		if ( attachment.Type() == ATTACHMENT_COMBINATION_LOCK )
		{
			if ( !HasGate() || IsOpened() )
			{
				return false;
			}
		}
			
		return true;
	}
	
	override void EEItemAttached( EntityAI item, string slot_name )
	{
		super.EEItemAttached( item, slot_name );
		
		//Check combination lock
		if ( item.IsInherited( CombinationLock ) )
		{
			CombinationLock combination_lock = CombinationLock.Cast( item );
			combination_lock.Lock( this );
		}
	}
	
	//hands
	override bool CanPutIntoHands( EntityAI parent )
	{
		if( !super.CanPutIntoHands( parent ) )
		{
			return false;
		}
		
		if ( HasBase() )
		{
			return false;
		}
		
		return true;
	}	
	
	//--- OPEN/CLOSE ACTIONS
	bool CanOpenFence()
	{
		if ( HasGate() && !IsOpened() && !IsLocked() )
		{
			return true;
		}
		
		return false;
	}
	
	bool CanCloseFence()
	{
		if ( HasGate() && IsOpened() )
		{
			return true;
		}
		
		return false;
	}
	
	void OpenFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{
			float value = GATE_ROTATION_ANGLE_DEG;
			SetAnimationPhase( "Wall_Interact_Rotate", 				value );
			SetAnimationPhase( "Wall_Barbedwire_1_Mounted_Rotate", 	value );
			SetAnimationPhase( "Wall_Barbedwire_2_Mounted_Rotate", 	value );
			SetAnimationPhase( "Wall_Camonet_Rotate", 				value );
			SetAnimationPhase( "Wall_Gate_Rotate", 					value );
			SetAnimationPhase( "Wall_Base_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Base_Up_Rotate", 				value );
			SetAnimationPhase( "Wall_Wood_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Wood_Up_Rotate", 				value );
			SetAnimationPhase( "Wall_Metal_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Metal_Up_Rotate", 				value );
			
			SetOpenedState( true );
			
			//regenerate navmesh
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
			
			//synchronize
			SynchronizeBaseState();
		}
		
		//client or single player
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//play sound
			SoundGateOpenStart();
		}
	}
	
	void CloseFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{		
			float value = 0;
			SetAnimationPhase( "Wall_Interact_Rotate", 				value );
			SetAnimationPhase( "Wall_Barbedwire_1_Mounted_Rotate", 	value );
			SetAnimationPhase( "Wall_Barbedwire_2_Mounted_Rotate", 	value );
			SetAnimationPhase( "Wall_Camonet_Rotate", 				value );
			SetAnimationPhase( "Wall_Gate_Rotate", 					value );
			SetAnimationPhase( "Wall_Base_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Base_Up_Rotate", 				value );
			SetAnimationPhase( "Wall_Wood_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Wood_Up_Rotate", 				value );
			SetAnimationPhase( "Wall_Metal_Down_Rotate", 			value );
			SetAnimationPhase( "Wall_Metal_Up_Rotate", 				value );
			
			SetOpenedState( false );
			
			//regenerate navmesh
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );
			
			//synchronize
			SynchronizeBaseState();
		}
		
		//client or single player
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//play sound
			SoundGateCloseStart();
			
			//add check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( CheckFenceClosed, 0, true );
		}
	}
	
	protected void CheckFenceClosed()
	{
		if ( GetAnimationPhase( "Wall_Gate_Rotate" ) == 0 )			//animation closed
		{
			//play sound
			if ( this ) SoundGateCloseEnd();
			
			//remove check
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Remove( CheckFenceClosed );
		}
	}
	
	//Damage triggers
	override void CreateAreaDamage( string slot_name, float rotation_angle = 0 )
	{
		if ( IsOpened() )
		{
			rotation_angle = 100;
		}
		
		super.CreateAreaDamage( slot_name, rotation_angle );
	}	
	
	//--- ACTION CONDITIONS
	override bool IsFacingPlayer( PlayerBase player, string selection )
	{
		vector fence_pos = GetPosition();
		vector player_pos = player.GetPosition();
		vector ref_dir = GetDirection();
		
		//vector fence_player_dir = player_pos - fence_pos;
		vector fence_player_dir = player.GetDirection();
		fence_player_dir.Normalize();
		fence_player_dir[1] = 0; 	//ignore height
		
		ref_dir.Normalize();
		ref_dir[1] = 0;			//ignore height
		
		if ( ref_dir.Length() != 0 )
		{
			float angle = Math.Acos( fence_player_dir * ref_dir );
			
			if ( angle >= MAX_ACTION_DETECTION_ANGLE_RAD )
			{
				return true;
			}
		}
		
		return false;
	}
	
	override bool IsFacingCamera( string selection )
	{
		vector ref_dir = GetDirection();
		vector cam_dir = GetGame().GetCurrentCameraDirection();
		
		//ref_dir = GetGame().GetCurrentCameraPosition() - GetPosition();
		ref_dir.Normalize();
		ref_dir[1] = 0;		//ignore height
		
		cam_dir.Normalize();
		cam_dir[1] = 0;		//ignore height
		
		if ( ref_dir.Length() != 0 )
		{
			float angle = Math.Acos( cam_dir * ref_dir );
			
			if ( angle >= MAX_ACTION_DETECTION_ANGLE_RAD )
			{
				return true;
			}
		}

		return false;
	}	
	
	//================================================================
	// SOUNDS
	//================================================================
	protected void SoundGateOpenStart()
	{
		PlaySoundSet( m_SoundGate_Start, SOUND_GATE_OPEN_START, 0.1, 0.1 );
	}

	protected void SoundGateCloseStart()
	{
		PlaySoundSet( m_SoundGate_Start, SOUND_GATE_CLOSE_START, 0.1, 0.1 );
	}

	protected void SoundGateCloseEnd()
	{
		PlaySoundSet( m_SoundGate_End, SOUND_GATE_CLOSE_END, 0.1, 0.1 );
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionFoldBaseBuildingObject);
		AddAction(ActionDialCombinationLockOnTarget);
		AddAction(ActionNextCombinationLockDialOnTarget);
		AddAction(ActionOpenFence);
		AddAction(ActionCloseFence);
	}
}
