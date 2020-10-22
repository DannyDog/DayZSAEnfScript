class LandMineTrap extends TrapBase
{
	protected ref EffectSound m_TimerLoopSound;
	protected ref Timer m_DeleteTimer;
	
	void LandMineTrap()
	{
		m_DefectRate = 15;
		m_DamagePlayers = 0; 			//How much damage player gets when caught
		m_InitWaitTime = 10; 			//After this time after deployment, the trap is activated
		m_InfoActivationTime = "#STR_LandMineTrap0" + m_InitWaitTime.ToString() + "#STR_LandMineTrap1"; 
		
		m_AddDeactivationDefect = true;
	}
		
	override void StartActivate( PlayerBase player )
	{
		super.StartActivate( player );
		
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			SEffectManager.PlaySound("landmine_safetyPin_SoundSet", this.GetPosition(), 0, 0, false);
			m_TimerLoopSound = SEffectManager.PlaySound("landmine_timer2_SoundSet", this.GetPosition(), 0, 0, true);
		}
	}
	
	override void OnActivate()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if ( m_TimerLoopSound )
			{
				m_TimerLoopSound.SoundStop();
				m_TimerLoopSound.SetSoundAutodestroy( true );
			}
			
			if ( GetGame().GetPlayer() )
			{
				PlaySoundActivate();
			}
		}
	}
	
	override bool CanExplodeInFire()
	{
		return true;
	}
	
	override void OnSteppedOn(EntityAI victim)
	{
		if ( GetGame().IsServer() )
		{
			Explode(DT_EXPLOSION);
			
			m_DeleteTimer = new Timer( CALL_CATEGORY_SYSTEM );
			m_DeleteTimer.Run( 2, this, "DeleteThis" );
		}
	}
	
	void DeleteThis()
	{
		GetGame().ObjectDelete(this);
	}
	
	override void OnItemLocationChanged  ( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged(old_owner, new_owner);
		
		if ( g_Game.IsServer() )
		{
			
		}
	}
	
	override void EEKilled( Object killer )
	{
		super.EEKilled( killer );
		
		OnSteppedOn(NULL);
	}
	
	void PlaySoundActivate()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			SEffectManager.PlaySound("landmineActivate_SoundSet", this.GetPosition(), 0, 0, false);
		}
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
		
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		if ( GetGame().IsServer() )
		{
			PlayerBase player_PB = PlayerBase.Cast( player );
			StartActivate( player_PB );
		}
	}
	
	override bool IsDeployable()
	{
		return true;
	}
	
	override string GetLoopDeploySoundset()
	{
		return "landmine_deploy_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionActivateTrap);
		AddAction(ActionDeployObject);
	}
}
