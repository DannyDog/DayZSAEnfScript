class EffEngineSmoke : EffVehicleSmoke
{
	private float m_Time;
	static private float m_UpdateInterval = 2;
	
	override void SetParticleStateLight()
	{
		SetParticleState( ParticleList.HATCHBACK_ENGINE_OVERHEATING );
	}
	
	override void SetParticleStateHeavy()
	{
		SetParticleState( ParticleList.HATCHBACK_ENGINE_OVERHEATED );
	}
	
	override void Event_OnFrameUpdate(float time_delta)
	{
		m_Time += time_delta;
		
		if (m_Time >= m_UpdateInterval)
		{
			m_Time = 0;
			
			Car parent = Car.Cast( GetAttachmentParent() );
				
			if (parent)
			{
				Particle p = GetParticle();
				if (p)
					p.Stop();
				
				if (p) // quick fix
				{
					SetParticleState( p.GetParticleID() );
					p = GetParticle();
					if (p)
					{
						float speed = parent.GetSpeedometer();
						float lifetime_scale;
						
						if (speed < 100)
							lifetime_scale = (100 - speed) / 100;
						else
							lifetime_scale = 0.1;
						
						float birthrate_scale = 1 + (speed * 0.02 );
						
						p.ScaleParticleParamFromOriginal( EmitorParam.LIFETIME, lifetime_scale );
						p.ScaleParticleParamFromOriginal( EmitorParam.LIFETIME_RND, lifetime_scale );
						p.ScaleParticleParamFromOriginal( EmitorParam.BIRTH_RATE, birthrate_scale );
						p.ScaleParticleParamFromOriginal( EmitorParam.BIRTH_RATE_RND, birthrate_scale );
					}
				}
			}
		}
	}
}