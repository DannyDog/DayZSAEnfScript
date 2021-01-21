class FlareSimulation : Entity
{
	protected Particle 			m_ParMainFire;
	protected EffectSound 		m_BurningSound;
	protected FlareLight		m_FlareLight;
	const static float			MAX_FARLIGHT_DIST = 40;
	const static float			MIN_FARLIGHT_DIST = 5; 
	
	void OnActivation(Entity flare)
	{
		m_FlareLight = FlareLight.Cast(ScriptedLightBase.CreateLight( FlareLight, Vector(0,0,0) ));
		if ( m_FlareLight )
			m_FlareLight.AttachOnObject(flare);
		
		if(m_ParMainFire)
		{
			m_ParMainFire.Stop();
		}
		
		m_ParMainFire = Particle.PlayOnObject( ParticleList.FLAREPROJ_ACTIVATE, flare);
		m_ParMainFire.SetWiggle( 7, 0.3);
		
		flare.PlaySoundSetLoop( m_BurningSound, "roadflareLoop_SoundSet", 0, 0 );
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
		if (player)
			vector playerPos = player.GetPosition();
		float dist = Math.Sqrt(vector.DistanceSq(curPos, playerPos));
		
		if (dist <= MAX_FARLIGHT_DIST && dist > MIN_FARLIGHT_DIST)
			m_ParMainFire.SetParameter(0, EmitorParam.SIZE, MiscGameplayFunctions.Normalize(dist, MAX_FARLIGHT_DIST));
		
		if (dist <= MIN_FARLIGHT_DIST)
			TurnOffDistantLight();
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
		if(m_ParMainFire)
			m_ParMainFire.Stop();
		
		if(m_BurningSound)
			m_BurningSound.SoundStop();
		
		if(m_FlareLight)
			m_FlareLight.FadeOut();
	}
	
	
}

class FlareSimulation_Red : FlareSimulation
{
	override void OnActivation( Entity flare)
	{
		m_FlareLight = FlareLight.Cast(ScriptedLightBase.CreateLight( FlareLightRed, Vector(0,0,0) ));
		if ( m_FlareLight )
			m_FlareLight.AttachOnObject(flare);
		
		if(m_ParMainFire)
		{
			m_ParMainFire.Stop();
		}
		m_ParMainFire = Particle.PlayOnObject( ParticleList.FLAREPROJ_ACTIVATE_RED, flare);
		m_ParMainFire.SetWiggle( 7, 0.3);
		
		flare.PlaySoundSetLoop( m_BurningSound, "roadflareLoop_SoundSet", 0, 0 );
	}
	

}

class FlareSimulation_Green : FlareSimulation
{
	override void OnActivation(Entity flare)
	{
		m_FlareLight = FlareLight.Cast(ScriptedLightBase.CreateLight( FlareLightGreen, Vector(0,0,0) ));
		if ( m_FlareLight )
			m_FlareLight.AttachOnObject(flare);
		
		if(m_ParMainFire)
		{
			m_ParMainFire.Stop();
		}
		m_ParMainFire = Particle.PlayOnObject( ParticleList.FLAREPROJ_ACTIVATE_GREEN, flare);
		m_ParMainFire.SetWiggle( 7, 0.3);
		
		flare.PlaySoundSetLoop( m_BurningSound, "roadflareLoop_SoundSet", 0, 0 );
	}
}

class FlareSimulation_Blue : FlareSimulation
{
	override void OnActivation(Entity flare)
	{
		m_FlareLight = FlareLight.Cast(ScriptedLightBase.CreateLight( FlareLightBlue, Vector(0,0,0) ));
		if ( m_FlareLight )
			m_FlareLight.AttachOnObject(flare);
		
		if(m_ParMainFire)
		{
			m_ParMainFire.Stop();
		}
		m_ParMainFire = Particle.PlayOnObject( ParticleList.FLAREPROJ_ACTIVATE_BLUE, flare);
		m_ParMainFire.SetWiggle( 7, 0.3);
		
		flare.PlaySoundSetLoop( m_BurningSound, "roadflareLoop_SoundSet", 0, 0 );
	}
}