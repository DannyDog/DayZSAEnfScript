class Wreck_UH1Y extends House
{
	Particle m_ParticleEfx;
	
	void Wreck_UH1Y()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.SMOKING_HELI_WRECK, this, Vector(-0.5, 0, -1.0));
		}
	}
	
	override void EEDelete(EntityAI parent)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( m_ParticleEfx )
				m_ParticleEfx.Stop();
		}
	}
	
}

class Wreck_Mi8 extends House
{

	void Wreck_Mi8()
	{
		//I'll leave this here if we want to add particles to MI-8
	}
}