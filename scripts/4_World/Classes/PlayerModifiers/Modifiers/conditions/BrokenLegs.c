class BrokenLegsMdfr: ModifierBase
{
	private const 	float	HEALTHY_LEG = 100; //Health at which legs are no longer considered broken
	private 		int 	currentState = -1; //Current broken leg state used upon reconnect
	private const 	float	TIME_TO_UPDATE = 0.5;
	private			float	elapsedTime = TIME_TO_UPDATE + 1;
	//int counter = 0; //fall down counter
	

	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 					= eModifiers.MDF_BROKEN_LEGS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
		m_ActivationType 		= EActivationType.TRIGGER_EVENT_ON_ACTIVATION;
		m_IsPersistent			= true;
	}

	override bool  ActivateCondition(PlayerBase player)
	{
		//Verify intial conditions for broken legs
		if (  player.m_BrokenLegState != eBrokenLegs.BROKEN_LEGS || m_ShouldBeActive )
		{
			return true;
		}
		return false;
	}

	override void OnActivate(PlayerBase player)
	{
		if (!ActivateCondition(player))
		{
			return;
		}
		
		if ( player.m_BrokenLegState != eBrokenLegs.BROKEN_LEGS )
		{
			currentState = eBrokenLegs.BROKEN_LEGS;
			player.SetBrokenLegs(currentState);	
			
		}
		else
		{
			currentState = eBrokenLegs.BROKEN_LEGS;
			player.SetBrokenLegs(currentState);
		}
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		player.SetBrokenLegs(eBrokenLegs.NO_BROKEN_LEGS);
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		if ( player.GetHealth("RightLeg", "Health") >= HEALTHY_LEG && player.GetHealth("LeftLeg", "Health") >= HEALTHY_LEG )
		{
			player.UpdateBrokenLegs(eBrokenLegs.NO_BROKEN_LEGS);
			if ( player.IsWearingSplint() )
			{
				MiscGameplayFunctions.RemoveSplint(player); //Remove splint when leg is healed
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	override void Activate()
	{
		super.Activate();
	}
	
	override void Deactivate(bool trigger = true)
	{
		super.Deactivate(trigger);
	}
	
	override void ActivateRequest(EActivationType trigger)
	{
		super.ActivateRequest( trigger );
	}
	
	override void Tick(float delta_time)
	{
		if ( !m_IsActive && m_ShouldBeActive )
		{
			Activate();
		}
		
		if ( m_IsActive )
		{
			if ( DeactivateCondition(m_Player) )
			{
				if ( !IsLocked() ) 
				{
					Deactivate();
				}
			}
			else
			{
				m_ActivatedTime += m_AccumulatedTimeActive;
				OnTick(m_Player, delta_time);
			}
			m_AccumulatedTimeActive = 0;
		}
	}
	
	override void OnTick(PlayerBase player, float deltaT)
	{
		elapsedTime += deltaT;
		if ( player.m_BrokenLegState == eBrokenLegs.BROKEN_LEGS_SPLINT || player.IsWearingSplint() )
		{
			currentState = eBrokenLegs.BROKEN_LEGS_SPLINT;
			if (elapsedTime > TIME_TO_UPDATE)
			{
				player.UpdateBrokenLegs(currentState); //Update in the player Base
					
				elapsedTime = 0;
			}

		}
		else
		{
			currentState = eBrokenLegs.BROKEN_LEGS;
			
			if (elapsedTime > TIME_TO_UPDATE)
			{
				player.UpdateBrokenLegs(currentState); //Update in the player base
				
				elapsedTime = 0;
			}
		}
	}
};
