class HungerMdfr: ModifierBase
{
	protected float	m_EnergyDelta;
	protected float	m_LastEnergyLevel;
	ref HumanMovementState		m_MovementState	= new HumanMovementState();
		
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 					= eModifiers.MDF_HUNGER;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override bool ActivateCondition(PlayerBase player)
	{
		return true;
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		return false;
	}
	
	override void OnReconnect(PlayerBase player)
	{

	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		player.GetMovementState(m_MovementState);
		float energy = player.GetStatEnergy().Get();
		float metabolic_speed = MiscGameplayFunctions.GetEnergyMetabolicSpeed(m_MovementState.m_iMovement);
		//PrintString(metabolic_speed.ToString());
		
		float energy_delta  = Math.AbsInt(player.GetStatEnergy().Get() - m_LastEnergyLevel);
		if (energy <  m_LastEnergyLevel) energy_delta = -energy_delta;
		m_LastEnergyLevel = player.GetStatEnergy().Get();
		
		player.GetStatEnergy().Add( -metabolic_speed * deltaT );
		if ( energy <= PlayerConstants.LOW_ENERGY_THRESHOLD )
		{
			player.SetMixedSoundState( eMixedSoundStates.HUNGRY );
			if( !player.GetStomach().IsDigesting() )
				player.AddHealth("GlobalHealth", "Health", -PlayerConstants.LOW_ENERGY_DAMAGE_PER_SEC * deltaT );
		}
		else
		{
			player.UnsetMixedSoundState( eMixedSoundStates.HUNGRY );
		}
	}
};