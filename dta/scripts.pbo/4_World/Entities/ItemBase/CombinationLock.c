class CombinationLock extends ItemBase
{
	int m_LockDigits;					//how many digits will the combination contain
	int m_Combination;					//actual combination that is dialed on lock
	int m_CombinationLocked;			//combination that was dialed on lock before the shuffle
	
	bool m_IsLockAttached;				//for storing to db
	
	//client only
	int m_CombinationClient;
	bool m_IsLockAttachedClient;
	
	//Sounds
	//build
	const string SOUND_LOCK_OPEN 			= "combinationlock_open_SoundSet";
	const string SOUND_LOCK_CLOSE 			= "combinationlock_close_SoundSet";
	const string SOUND_LOCK_CHANGE_NUMBER	= "combinationlock_changenumber_SoundSet";
	const string SOUND_LOCK_CHANGE_DIAL		= "combinationlock_changedial_SoundSet";

	protected EffectSound m_Sound;
		
	void CombinationLock()
	{
		SetBaseLockValues();
		
		//synchronized variables
		int combination_length = Math.Pow( 10, m_LockDigits );
		
		RegisterNetSyncVariableInt( "m_Combination", 		0, combination_length - 1 );
		RegisterNetSyncVariableInt( "m_CombinationLocked", 	0, combination_length - 1 );
		RegisterNetSyncVariableBool( "m_IsLockAttached" );	
	}
	
	protected void SetBaseLockValues()
	{
		//set lock init values
		m_LockDigits 			= 3;
		m_Combination		 	= 111;
		m_CombinationLocked 	= 999;		
	}

	override void EEInit()
	{
		super.EEInit();
		
		//set visual on init
		UpdateVisuals();
	}	

	void SetLockAttachedState( bool state )
	{
		m_IsLockAttached = state;
		
		Synchronize();
	}
	
	bool IsLockAttached()
	{
		return m_IsLockAttached;
	}	
	
	// --- VISUALS
	void UpdateVisuals()
	{
		//Client (only)
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() )
		{
			//was unlocked
			if ( m_IsLockAttachedClient && !m_IsLockAttached )
			{
				Fence fence = Fence.Cast( GetHierarchyParent() );
				if ( fence )
				{
					//drop entity
					fence.GetInventory().DropEntity( InventoryMode.LOCAL, fence, this );
				}
			}
		}
		
		//Client/Server
		if ( IsLockedOnGate() )
		{
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( HideItem, 		0, false );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ShowAttached, 	0, false );
		}
		else
		{
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( ShowItem, 		0, false );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( HideAttached, 	0, false );
		}
	}
	
	void UpdateSound()
	{
		//dialed new number
		if ( m_CombinationClient != m_Combination )
		{
			SoundLockChangeNumber();
		}
		
		//was locked
		if ( !m_IsLockAttachedClient && m_IsLockAttached )
		{
			SoundLockClose();
		}
		//was unlocked
		else if ( m_IsLockAttachedClient && !m_IsLockAttached )
		{
			SoundLockOpen();
		}
	}
	
	//TODO
	protected void ShowItem()
	{
		SetAnimationPhase( "Combination_Lock_Item", 0 );
		SetAnimationPhase( "Lock_Item_1", 			0 );
		SetAnimationPhase( "Lock_Item_2", 			0 );
	}
	
	protected void HideItem()
	{
		SetAnimationPhase( "Combination_Lock_Item", 1 );
		SetAnimationPhase( "Lock_Item_1", 			1 );
		SetAnimationPhase( "Lock_Item_2", 			1 );
	}
	
	protected void ShowAttached()
	{
		SetAnimationPhase( "Combination_Lock_Attached", 0 );
		SetAnimationPhase( "Lock_Attached_1", 			0 );
		SetAnimationPhase( "Lock_Attached_2", 			0 );
	}
	
	protected void HideAttached()
	{
		SetAnimationPhase( "Combination_Lock_Attached", 1 );
		SetAnimationPhase( "Lock_Attached_1", 			1 );
		SetAnimationPhase( "Lock_Attached_2", 			1 );
	}	
	// ---
	
	// --- EVENTS
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );
		
		//write data
		ctx.Write( m_Combination );
		ctx.Write( m_CombinationLocked );
		ctx.Write( m_IsLockAttached );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		//--- Combination Lock data ---
		//combination
		if ( !ctx.Read( m_Combination ) )
		{
			m_Combination = 0;
			return false;
		}
		
		//combination locked
		if ( !ctx.Read( m_CombinationLocked ) )
		{
			m_CombinationLocked = 0;
			return false;
		}
		
		//is lock attached
		if ( !ctx.Read( m_IsLockAttached ) )
		{
			m_IsLockAttached = false;
			return false;
		}
		
		return true;
	}
	
	override void AfterStoreLoad()
	{	
		super.AfterStoreLoad();		
		
		//is lock attached
		m_IsLockAttached = false;
		
		Fence fence = Fence.Cast( GetHierarchyParent() );
		if ( fence )
		{
			//check for gate part
			m_IsLockAttached = fence.HasGate();
			
			//do check for lock 'not attached but locked' state
			if ( m_IsLockAttached )
			{
				InventoryLocation inventory_location = new InventoryLocation;
				GetInventory().GetCurrentInventoryLocation( inventory_location );		
				fence.GetInventory().SetSlotLock( inventory_location.GetSlot(), m_IsLockAttached );
			}
		}
		//---
		
		//synchronize
		Synchronize();
	}
	
	// --- SYNCHRONIZATION
	void Synchronize()
	{
		if ( GetGame().IsServer() )
		{
			SetSynchDirty();
			
			UpdateVisuals();
		}
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		//update visuals (client)
		UpdateVisuals();
		
		//update sound (client)
		UpdateSound();
		
		//update client state
		m_CombinationClient = m_Combination;
		m_IsLockAttachedClient = m_IsLockAttached;
	}
	
	void SetCombination( int combination )
	{
		m_Combination = combination;
		
		Synchronize();
	}
	
	void SetCombinationLocked( int combination )
	{
		m_CombinationLocked = combination;
		
		Synchronize();
	}
	
	// --- ACTIONS
	int GetCombination()
	{
		return m_Combination;
	}
	
	void DialNextNumber( int dial_index )
	{
		string combination_text = m_Combination.ToString();
		string dialed_text;
		
		//insert zeros to dials with 0 value
		int length_diff = m_LockDigits - combination_text.Length();
		for ( int i = 0; i < length_diff; ++i )
		{
			combination_text = "0" + combination_text;
		}
		
		//assemble the whole combination with increased part
		for ( int j = 0; j < combination_text.Length(); ++j )
		{
			if ( j == dial_index )
			{
				int next_dialed_number = combination_text.Get( j ).ToInt() + 1;
				if ( next_dialed_number > 9 )
				{
					next_dialed_number = 0;
				}
				
				dialed_text += next_dialed_number.ToString();
			}
			else
			{
				dialed_text += combination_text.Get( j );
			}
		}
		
		SetCombination( dialed_text.ToInt() );
	}
	
	void SetNextDial( out int dial_index )
	{
		if ( m_LockDigits > 1 )
		{
			if ( dial_index <= m_LockDigits - 2 )
			{
				dial_index++;
			}
			else if ( dial_index >= m_LockDigits >  - 1 )
			{
				dial_index = 0;
			}
		}
		else
		{
			dial_index = 0;
		}
	}	
	
	//Lock lock
	void Lock( EntityAI parent )
	{
		if ( !IsLockAttached() )
		{
			SetCombinationLocked( m_Combination );
			ShuffleLock();
			
			//set slot lock
			InventoryLocation inventory_location = new InventoryLocation;
			GetInventory().GetCurrentInventoryLocation( inventory_location );		
			parent.GetInventory().SetSlotLock( inventory_location.GetSlot(), true );
			
			//set lock attached
			SetLockAttachedState( true );
		}
	}
	
	void Unlock( EntityAI parent )
	{
		//set slot unlock
		InventoryLocation inventory_location = new InventoryLocation;
		GetInventory().GetCurrentInventoryLocation( inventory_location );			
		parent.GetInventory().SetSlotLock( inventory_location.GetSlot(), false );			
		
		//drop entity from attachment slot
		parent.GetInventory().DropEntity( InventoryMode.PREDICTIVE, parent, this );
		
		//set lock attached
		SetLockAttachedState( false );
	}
		
	//Shuffle lock
	void ShuffleLock()
	{
		string combination_text = m_Combination.ToString();
		string shuffled_text;
		
		//insert zeros to dials with 0 value
		int length_diff = m_LockDigits - combination_text.Length();
		for ( int i = 0; i < length_diff; ++i )
		{
			combination_text = "0" + combination_text;
		}
		
		//assemble the whole combination with increased part
		for ( int j = 0; j < combination_text.Length(); ++j )
		{
			int dial_number = combination_text.Get( j ).ToInt();
			dial_number = ( dial_number + Math.RandomInt( 1, 9 ) ) % 10;
			shuffled_text = shuffled_text + dial_number.ToString();
		}
		
		SetCombination( shuffled_text.ToInt() );
	}
	
	bool IsLockedOnGate()
	{
		Fence fence = Fence.Cast( GetHierarchyParent() );
		if ( fence )
		{
			if ( m_Combination != m_CombinationLocked )
			{
				return true;
			}
		}
		
		return false;
	}
	
	//================================================================
	// SOUNDS
	//================================================================
	protected void SoundLockOpen()
	{
		PlaySoundSet( m_Sound, SOUND_LOCK_OPEN, 0, 0 );
	}

	protected void SoundLockClose()
	{
		PlaySoundSet( m_Sound, SOUND_LOCK_CLOSE, 0, 0 );
	}
	
	void SoundLockChangeNumber()
	{
		PlaySoundSet( m_Sound, SOUND_LOCK_CHANGE_NUMBER, 0, 0 );
	}

	void SoundLockChangeDial()
	{
		PlaySoundSet( m_Sound, SOUND_LOCK_CHANGE_DIAL, 0, 0 );
	}	
	
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionAttachToConstruction);		
		AddAction(ActionNextCombinationLockDial);
		AddAction(ActionDialCombinationLock);
	}
}
