class InjuryHandlerThresholds
{
	const float WORN = 0.8;
	const float DAMAGED = 0.6;
	const float BADLY_DAMAGED = 0.4;
	const float RUINED = 0.2;
};

class InjuryAnimValues
{
	const float LVL0 = 0;
	const float LVL1 = 0.3;
	const float LVL2 = 0.6;
	const float LVL3 = 0.8;
	const float LVL4 = 1;
};

enum eInjuryHandlerLevels
{
	PRISTINE,
	WORN,
	DAMAGED,
	BADLY_DAMAGED,
	RUINED,
}

class InjuryAnimationHandler
{

	const float VALUE_CHECK_INTERVAL	 	= 5;
	const float SENSITIVTY_PERCENTAGE 		= 1;//how much the value needs to change up/down from previous update to trigger a new update(in percent)

	ref ScriptInvoker m_ChangedStateInvoker	= new ScriptInvoker();
	
	float m_TimeSinceLastTick = VALUE_CHECK_INTERVAL + 1;
	float m_LastUpdate;
	eInjuryHandlerLevels m_LastHealthUpdate;
	float m_HealthMaxValue;
	
	
	private PlayerBase m_Player; //! owner
	private bool m_AnimationChange = false;
	private bool m_InjuryAnimEnabled = false;
	private float m_InjuryAnimDamageValue = 0;
	
	
	void InjuryAnimationHandler(PlayerBase player)
	{
		m_Player = player;
		m_HealthMaxValue 	= m_Player.GetMaxHealth("", "Health");
	}
	
	bool IsInjuryAnimEnabled()
	{
		return m_InjuryAnimEnabled;
	}
	
	float GetInjuryAnimValue()
	{
		return m_InjuryAnimDamageValue;
	}
	
	ScriptInvoker GetInvoker()
	{
		return m_ChangedStateInvoker;
	}
	
	void Update(float deltaT)
	{
		if( m_AnimationChange )
		{
			m_Player.GetCommandModifier_Additives().SetInjured(m_InjuryAnimDamageValue, m_InjuryAnimEnabled);
			m_AnimationChange = false;
		}

		if( GetGame().IsClient() ) return;
		m_TimeSinceLastTick += deltaT;

		if( m_TimeSinceLastTick > VALUE_CHECK_INTERVAL )
		{
			CheckValue();
			m_TimeSinceLastTick = 0;
		}
		
	}

	void CheckValue(bool forceUpdate = false)
	{
		float health_current_normalized = m_Player.GetHealth("","Health") / m_HealthMaxValue;
		eInjuryHandlerLevels injury_level = GetInjuryLevel(health_current_normalized);
		
		if( m_LastHealthUpdate != injury_level || forceUpdate )
		{
			SendValue(injury_level);
			m_ChangedStateInvoker.Invoke(injury_level);
			m_LastHealthUpdate = injury_level;
			Synchronize(injury_level);
		}
	}
	
	void Synchronize(eInjuryHandlerLevels level)
	{
		m_Player.m_HealthLevel = level;
		Print("m_Player.m_HealthLevel:" + m_Player.m_HealthLevel);
		m_Player.SetSynchDirty();
	}

	void SendValue(eInjuryHandlerLevels level)
	{
		DayZPlayerSyncJunctures.SendInjury(m_Player, true, level);
	}
	
	void SetInjuryCommandParams(bool enable, eInjuryHandlerLevels level)
	{
		m_AnimationChange = true;
		m_InjuryAnimEnabled = enable;
		m_InjuryAnimDamageValue = GetInjuryValue(level);
	}
	
	eInjuryHandlerLevels GetInjuryLevel(float health)
	{
		if ( health  < InjuryHandlerThresholds.RUINED ) 
		{
			return eInjuryHandlerLevels.RUINED;
		}
		
		if ( health  < InjuryHandlerThresholds.BADLY_DAMAGED ) 
		{
			return eInjuryHandlerLevels.BADLY_DAMAGED;
		}
		
		if ( health  < InjuryHandlerThresholds.DAMAGED ) 			
		{
			return eInjuryHandlerLevels.DAMAGED;
		}
		
		if ( health  < InjuryHandlerThresholds.WORN ) 		
		{
			return eInjuryHandlerLevels.WORN;
		}
		
		return eInjuryHandlerLevels.PRISTINE;
	}
	
	
	float GetInjuryValue(eInjuryHandlerLevels level)
	{
		switch(level)
		{
			case eInjuryHandlerLevels.RUINED:
			{
				return InjuryAnimValues.LVL4;
			}
			case eInjuryHandlerLevels.BADLY_DAMAGED:
			{
				return InjuryAnimValues.LVL3;
			}
			case eInjuryHandlerLevels.DAMAGED:
			{
				return InjuryAnimValues.LVL2;
			}
			case eInjuryHandlerLevels.WORN:
			{
				return InjuryAnimValues.LVL1;
			}
			case eInjuryHandlerLevels.PRISTINE:
			{
				return InjuryAnimValues.LVL0;
			}
			default:
				Error("Undefined Injury level");
		}
		return 0;
	}

}