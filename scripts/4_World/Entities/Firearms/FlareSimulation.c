class FlareSimulation : Entity
{
	protected Particle 			m_ParMainFire;
	protected EffectSound 		m_BurningSound;
	protected FlareLight		m_FlareLight;
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