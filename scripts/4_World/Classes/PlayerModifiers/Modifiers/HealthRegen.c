class HealthRegenMdfr: ModifierBase
{
	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID 					= eModifiers.MDF_HEALTH_REGEN;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}
	override bool ActivateCondition(PlayerBase player)
	{
		return true;
	}

	override void OnActivate(PlayerBase player)
	{
	}

	override void OnReconnect(PlayerBase player)
	{

	}
	
	override bool DeactivateCondition(PlayerBase player)
	{
		return false;
	}

	override void OnTick(PlayerBase player, float deltaT)
	{	
		if(player.IsAlive())//this needs to be here, some of the other modifiers can kill the character during the same modifier tick, and not checking here can partially revive him(resulting in a broken char)
		{
			float blood =  player.GetHealth("GlobalHealth", "Blood");
	
			float blood_scale_normalized = Math.InverseLerp(PlayerConstants.BLOOD_THRESHOLD_FATAL, player.GetMaxHealth("", "Blood"), blood);
			blood_scale_normalized = Math.Clamp(blood_scale_normalized,0,1);
			float regen_speed = Math.Lerp(PlayerConstants.HEALTH_REGEN_MIN, PlayerConstants.HEALTH_REGEN_MAX, blood_scale_normalized);
			regen_speed = regen_speed * deltaT;
			player.AddHealth("GlobalHealth", "Health" ,  regen_speed );
			
			player.AddHealth("RightArm","Health",regen_speed * PlayerConstants.DAMAGE_ZONE_BLOOD_REGEN_MODIFIER );
			player.AddHealth("RightHand","Health",regen_speed * PlayerConstants.DAMAGE_ZONE_BLOOD_REGEN_MODIFIER);
			player.AddHealth("LeftArm","Health",regen_speed * PlayerConstants.DAMAGE_ZONE_BLOOD_REGEN_MODIFIER);
			player.AddHealth("LeftHand","Health",regen_speed * PlayerConstants.DAMAGE_ZONE_BLOOD_REGEN_MODIFIER);
			
			//Leg regen when legs are NOT BROKEN
			if ( player.m_BrokenLegState == eBrokenLegs.NO_BROKEN_LEGS )
			{
				player.AddHealth("RightLeg","Health", PlayerConstants.LEG_HEALTH_REGEN);
				player.AddHealth("RightFoot","Health", PlayerConstants.LEG_HEALTH_REGEN);
				player.AddHealth("LeftLeg","Health", PlayerConstants.LEG_HEALTH_REGEN);
				player.AddHealth("LeftFoot","Health", PlayerConstants.LEG_HEALTH_REGEN);
			}
			else
			{
				//Leg regen when legs are BROKEN or SPLINTED
				player.AddHealth("RightLeg","Health", PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
				player.AddHealth("RightFoot","Health",PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
				player.AddHealth("LeftLeg","Health", PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
				player.AddHealth("LeftFoot","Health", PlayerConstants.LEG_HEALTH_REGEN_BROKEN);
			}
			
			player.AddHealth("Torso","Health",regen_speed * PlayerConstants.DAMAGE_ZONE_BLOOD_REGEN_MODIFIER);
			player.AddHealth("Head","Health",regen_speed * PlayerConstants.DAMAGE_ZONE_BLOOD_REGEN_MODIFIER);
		}
	}
};
