class FlareSimulation : Entity
{
	protected Particle 			m_ParMainFire;
	protected EffectSound 		m_BurningSound;
	protected FlareLight		m_FlareLight;
	const static float			MAX_FARLIGHT_DIST = 40;
	const static float			MIN_FARLIGHT_DIST = 5; 
	
	ref NoiseParams 			m_NoisePar; // Contains the noise data ( template and strength )
	private float 				m_NoiseTimer;
	private int 				m_NoiseCounter = 0;
	protected const float 		NOISE_DELAY = 2; // How much time between two consecutive noise pings
	private const int 			NOISE_COUNT = 3; // How many noise pings flare will send during lifetime ( excluding first one )
	
	void OnActivation(Entity flare)
	{
		m_FlareLight = FlareLight.Cast(ScriptedLightBase.CreateLight( FlareLight, Vector(0,0,0) ));
		if ( m_FlareLight )
			m_FlareLight.AttachOnObject(flare);
		
		if (m_ParMainFire)
		{
			m_ParMainFire.Stop();
		}
		
		m_ParMainFire = Particle.PlayOnObject( ParticleList.FLAREPROJ_ACTIVATE, flare);
		m_ParMainFire.SetWiggle( 7, 0.3 );
		
		flare.PlaySoundSetLoop( m_BurningSound, "roadflareLoop_SoundSet", 0, 0 );
		
		if ( GetGame().IsServer() )
		{
			// Create and load noise parameters
			m_NoisePar = new NoiseParams();
			m_NoisePar.LoadFromPath("cfgWeapons Flaregun_Base NoiseFlare");
			NoiseSystem noise = GetGame().GetNoiseSystem();
			/*if ( noise )
			{
				// Create a noise ping with dummy target
				noise.AddNoiseTarget( flare.GetPosition(), NOISE_DELAY, m_NoisePar );
			}*/
			CastFlareAINoise( flare.GetPosition() );
		}
	}
	
	void OnFire( Entity flare)
	{
		//m_ParMainFire = Particle.PlayOnObject( ParticleList.FLAREPROJ_FIRE, flare);
		//m_ParMainFire.SetWiggle( 7, 0.3);
	}
	
	void Simulate( Entity flare )
	{
		vector curPos = flare.GetPosition();
		DayZPlayer player = GetGame().GetPlayer();
		if ( player )
			vector playerPos = player.GetPosition();
		
		if ( GetGame().IsClient() )
		{
			float dist = vector.DistanceSq(curPos, playerPos);
			
			if ( ( dist <= MAX_FARLIGHT_DIST * MAX_FARLIGHT_DIST ) && ( dist > MIN_FARLIGHT_DIST * MIN_FARLIGHT_DIST ) )
				m_ParMainFire.SetParameter( 0, EmitorParam.SIZE, MiscGameplayFunctions.Normalize(dist, MAX_FARLIGHT_DIST * MAX_FARLIGHT_DIST) );
			
			if ( dist <= MIN_FARLIGHT_DIST * MIN_FARLIGHT_DIST )
				TurnOffDistantLight();
		}
		
		CastFlareAINoise( curPos );
	}
	
	void CastFlareAINoise( vector position )
	{
		if ( GetGame().IsServer() )
		{
			NoiseSystem noise = GetGame().GetNoiseSystem();
			if ( noise )
			{
				m_NoiseTimer += GetGame().GetFps();
				if ( m_NoiseTimer >= NOISE_DELAY && m_NoiseCounter <= NOISE_COUNT )
				{
					noise.AddNoiseTarget( position, NOISE_DELAY, m_NoisePar);
					
					m_NoiseTimer = 0;
					m_NoiseCounter++;
				}
			}
		}
	}
	
	void TurnOffDistantLight()
	{
		if (m_ParMainFire)
		{
			m_ParMainFire.SetParameter(0, EmitorParam.LIFETIME, 0);
			m_ParMainFire.SetParameter(0, EmitorParam.LIFETIME_RND, 0);
			m_ParMainFire.SetParameter(0, EmitorParam.REPEAT, 0);
			m_ParMainFire.SetParameter(0, EmitorParam.SIZE, 0);
		}
	}
	
	void ~FlareSimulation()
	{
		if (m_ParMainFire)
			m_ParMainFire.Stop();
		
		if (m_BurningSound)
			m_BurningSound.SoundStop();
		
		if (m_FlareLight)
			m_FlareLight.FadeOut();
	}
}

class FlareSimulation_Red : FlareSimulation
{
	override void OnActivation( Entity flare)
	{
		m_FlareLight = FlareLight.Cast( ScriptedLightBase.CreateLight( FlareLightRed, Vector(0,0,0) ) );
		if ( m_FlareLight )
			m_FlareLight.AttachOnObject( flare );
		
		if (m_ParMainFire)
		{
			m_ParMainFire.Stop();
		}
		m_ParMainFire = Particle.PlayOnObject( ParticleList.FLAREPROJ_ACTIVATE_RED, flare );
		m_ParMainFire.SetWiggle( 7, 0.3 );
		
		flare.PlaySoundSetLoop( m_BurningSound, "roadflareLoop_SoundSet", 0, 0 );
		
		if ( GetGame().IsServer() )
		{
			m_NoisePar = new NoiseParams();
			m_NoisePar.LoadFromPath("cfgWeapons Flaregun_Base NoiseFlare");
			NoiseSystem noise = GetGame().GetNoiseSystem();
			/*if ( noise )
			{
				// Create a noise ping with dummy target
				noise.AddNoiseTarget( flare.GetPosition(), NOISE_DELAY, m_NoisePar );
			}*/
			CastFlareAINoise( flare.GetPosition() );
		}
	}
	

}

class FlareSimulation_Green : FlareSimulation
{
	override void OnActivation(Entity flare)
	{
		m_FlareLight = FlareLight.Cast( ScriptedLightBase.CreateLight( FlareLightGreen, Vector(0,0,0) ) );
		if ( m_FlareLight )
			m_FlareLight.AttachOnObject( flare );
		
		if ( m_ParMainFire )
		{
			m_ParMainFire.Stop();
		}
		m_ParMainFire = Particle.PlayOnObject( ParticleList.FLAREPROJ_ACTIVATE_GREEN, flare );
		m_ParMainFire.SetWiggle( 7, 0.3 );
		
		flare.PlaySoundSetLoop( m_BurningSound, "roadflareLoop_SoundSet", 0, 0 );
		
		if ( GetGame().IsServer() )
		{
			m_NoisePar = new NoiseParams();
			m_NoisePar.LoadFromPath("cfgWeapons Flaregun_Base NoiseFlare");
			NoiseSystem noise = GetGame().GetNoiseSystem();
			/*if ( noise )
			{
				// Create a noise ping with dummy target
				noise.AddNoiseTarget( flare.GetPosition(), NOISE_DELAY, m_NoisePar );
			}*/
			CastFlareAINoise( flare.GetPosition() );
		}
	}
}

class FlareSimulation_Blue : FlareSimulation
{
	override void OnActivation(Entity flare)
	{
		m_FlareLight = FlareLight.Cast( ScriptedLightBase.CreateLight( FlareLightBlue, Vector(0,0,0) ) );
		if ( m_FlareLight )
			m_FlareLight.AttachOnObject( flare );
		
		if (m_ParMainFire)
		{
			m_ParMainFire.Stop();
		}
		m_ParMainFire = Particle.PlayOnObject( ParticleList.FLAREPROJ_ACTIVATE_BLUE, flare);
		m_ParMainFire.SetWiggle( 7, 0.3 );
		
		flare.PlaySoundSetLoop( m_BurningSound, "roadflareLoop_SoundSet", 0, 0 );
		
		if ( GetGame().IsServer() )
		{
			m_NoisePar = new NoiseParams();
			m_NoisePar.LoadFromPath("cfgWeapons Flaregun_Base NoiseFlare");
			NoiseSystem noise = GetGame().GetNoiseSystem();
			/*if ( noise )
			{
				// Create a noise ping with dummy target
				noise.AddNoiseTarget( flare.GetPosition(), NOISE_DELAY, m_NoisePar );
			}*/
			CastFlareAINoise( flare.GetPosition() );
		}
	}
}