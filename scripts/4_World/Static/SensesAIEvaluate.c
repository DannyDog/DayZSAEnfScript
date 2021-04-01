class NoiseAIEvaluate 
{
	static float SURFACE_NOISE_WEIGHT = 0.25;
	
	static float GetNoiseMultiplier(DayZPlayerImplement playerImplement)
	{
		float speedNoise =  GetNoiseMultiplierByPlayerSpeed(playerImplement);
		float shoesNoise =  GetNoiseMultiplierByShoes(playerImplement);
		float surfaceNoise = GetNoiseMultiplierBySurface(playerImplement);
		
		surfaceNoise *= SURFACE_NOISE_WEIGHT;
		float avgNoise = (shoesNoise + surfaceNoise)/(1 + SURFACE_NOISE_WEIGHT);
		avgNoise *= speedNoise;
		
		return avgNoise;
	}
	
	//Noise multiplier based on player speed
	protected static float GetNoiseMultiplierByPlayerSpeed(DayZPlayerImplement playerImplement)
	{
		ref HumanMovementState hms = new HumanMovementState();
		
		playerImplement.GetMovementState(hms);
		
		switch(AITargetCallbacksPlayer.StanceToMovementIdxTranslation(hms))
		{			
			case DayZPlayerConstants.MOVEMENTIDX_IDLE:
				return PlayerConstants.AI_NOISE_IDLE;
			
			case DayZPlayerConstants.MOVEMENTIDX_WALK:
				return PlayerConstants.AI_NOISE_WALK;
			
			case DayZPlayerConstants.MOVEMENTIDX_RUN:
				return PlayerConstants.AI_NOISE_RUN;
			
			case DayZPlayerConstants.MOVEMENTIDX_SPRINT:
				return PlayerConstants.AI_NOISE_SPRINT;
		}
		
		//Default return
		return PlayerConstants.AI_NOISE_SPRINT;
	}
	
	
	//Noise multiplier based on type of boots
	protected static float GetNoiseMultiplierByShoes(DayZPlayerImplement playerImplement)
	{
		switch(playerImplement.GetBootsType())
		{
			case AnimBootsType.None:
				return PlayerConstants.AI_NOISE_SHOES_NONE;
			
			case AnimBootsType.Sneakers:
				return PlayerConstants.AI_NOISE_SHOES_SNEAKERS;
			
			case AnimBootsType.Boots:
				return PlayerConstants.AI_NOISE_SHOES_BOOTS;	
		}
		
		//Default return
		return PlayerConstants.AI_NOISE_SHOES_BOOTS;
	}
	
	//Gets noise multiplayer base on surface player walks on
	protected static float GetNoiseMultiplierBySurface(DayZPlayerImplement playerImplement)
	{
		return playerImplement.GetSurfaceNoise(); 
	}
}