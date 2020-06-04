class FenceKit extends ItemBase
{	
	ref protected EffectSound 		m_DeployLoopSound;
	protected bool 					m_DeployedRegularly;
	
	void FenceKit()
	{
		m_DeployLoopSound = new EffectSound;
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsDeploySound");
	}
	
	void ~FenceKit()
	{
		if ( m_DeployLoopSound )
		{
			SEffectManager.DestroySound( m_DeployLoopSound );
		}
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		//set visual on init
		UpdateVisuals();
		UpdatePhysics();
		
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( AssembleKit );
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached( item, slot_name );
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if( player && player.IsPlayerDisconnected() )
		{
			return;
		}
		if (item && slot_name == "Rope")
		{
			if ((GetGame().IsServer() || !GetGame().IsMultiplayer()) && !m_DeployedRegularly)
			{					
				DisassembleKit(ItemBase.Cast(item));
				item.Delete();
				Delete();
			}
		}
	}
	
	override void OnEndPlacement()
	{
		m_DeployedRegularly = true;
	}
	
	override void OnPlacementCancelled( Man player )
	{
		super.OnPlacementCancelled(player);
		m_DeployedRegularly = false;
	}
	
	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged( old_owner, new_owner );
		
		//update visuals after location change
		UpdatePhysics();
	}
		
	override bool HasProxyParts()
	{
		return true;
	}
	
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if ( !super.CanReceiveAttachment(attachment, slotId) )
			return false;
		
		ItemBase att = ItemBase.Cast(GetInventory().FindAttachment(slotId));
		if (att)
			return false;
		
		return true;
	}
	
	//Update visuals and physics
	void UpdateVisuals()
	{
		SetAnimationPhase( "Inventory", 0 );
		SetAnimationPhase( "Placing", 1 );
	}
	
	void UpdatePhysics()
	{
		AddProxyPhysics( "Inventory" );
		RemoveProxyPhysics( "Placing" );		
	}	
	
	/*override bool IsOneHandedBehaviour()
	{
		return true;
	}*/
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( IsDeploySound() )
		{
			PlayDeploySound();
		}
				
		if ( CanPlayDeployLoopSound() )
		{
			PlayDeployLoopSound();
		}
					
		if ( m_DeployLoopSound && !CanPlayDeployLoopSound() )
		{
			StopDeployLoopSound();
		}
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			
		
	override void OnPlacementComplete( Man player )
	{
		if ( GetGame().IsServer() )
		{
			//Create fence
			PlayerBase player_base = PlayerBase.Cast( player );
			vector position = player_base.GetLocalProjectionPosition();
			vector orientation = player_base.GetLocalProjectionOrientation();
			
			Fence fence = Fence.Cast( GetGame().CreateObjectEx( "Fence", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			fence.SetPosition( position );
			fence.SetOrientation( orientation );
			
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			
			SetIsDeploySound( true );
		}	
	}
	
	override bool IsDeployable()
	{
		return true;
	}	
	
	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "BarbedWire_Deploy_loop_SoundSet";
	}
	
	void PlayDeployLoopSound()
	{		
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{		
			if ( !m_DeployLoopSound.IsSoundPlaying() )
			{
				m_DeployLoopSound = SEffectManager.PlaySound( GetLoopDeploySoundset(), GetPosition() );
			}
		}
	}
	
	void StopDeployLoopSound()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{	
			m_DeployLoopSound.SetSoundFadeOut(0.5);
			m_DeployLoopSound.SoundStop();
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
	
	void AssembleKit()
	{
		if (!IsHologram())
		{
			Rope rope = Rope.Cast(GetInventory().CreateAttachment("Rope"));
		}
	}
	
	void DisassembleKit(ItemBase item)
	{
		if (!IsHologram())
		{
			ItemBase stick = ItemBase.Cast(GetGame().CreateObjectEx("WoodenStick",GetPosition(),ECE_PLACE_ON_SURFACE));
			stick.SetQuantity(2);
			Rope rope = Rope.Cast(item);
			CreateRope(rope);
		}
	}
	
	void CreateRope(Rope rope)
	{
		if (!rope)
			return;
		
		InventoryLocation targetLoc = rope.GetTargetLocation();
		if (targetLoc && targetLoc.GetType() == InventoryLocationType.ATTACHMENT)
			return;

				GetGame().CreateObjectEx("Rope",GetPosition(),ECE_PLACE_ON_SURFACE);
	}
}
