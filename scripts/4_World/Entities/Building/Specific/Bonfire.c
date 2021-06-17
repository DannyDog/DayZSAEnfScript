class Bonfire extends BuildingSuper
{
	protected BonfireLight		m_Light;
	protected Particle 			m_ParticleFire;
	protected Particle 			m_ParticleSmoke;
	protected EffectSound 		m_SoundFireLoop;
	
	//Heating related variables
	protected ref Timer 		m_BonfireHeatingTimer;
	private const float 		TIMER_HEATING_UPDATE_INTERVAL	= 2;
	private const float 		PARAM_HEAT_RADIUS				= 15;
	private const float 		PARAM_FULL_HEAT_RADIUS			= 5;
	private const float 		PARAM_HEAT_THROUGH_AIR_COEF		= 0.030;
	private const float 		CONST_FIRE_TEMP					= 1000;
	
	override void EEInit()
	{
		super.EEInit();
		
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			// object creation - create effects (light, particles, sound)
			
			// light
			if ( !m_Light )
			{
				m_Light = BonfireLight.Cast( ScriptedLightBase.CreateLight( BonfireLight, Vector(0,0,0), 1 ) );
				m_Light.AttachOnMemoryPoint( this, m_Light.m_MemoryPoint );
				m_Light.FadeBrightnessTo( m_Light.m_FireBrightness, 0 );
				m_Light.FadeRadiusTo( m_Light.m_FireRadius, 0 );
			}
			
			// particles
			if ( !m_ParticleSmoke )
				m_ParticleSmoke = Particle.PlayOnObject( ParticleList.BONFIRE_SMOKE, this, GetMemoryPointPos( "bonfire_smoke" ), Vector(0,0,0), true );
			if ( !m_ParticleFire )
				m_ParticleFire = Particle.PlayOnObject( ParticleList.BONFIRE_FIRE, this, GetMemoryPointPos( "bonfire_fire" ), Vector(0,0,0), true );
			
			// sounds
			if ( !m_SoundFireLoop )
				PlaySoundSetLoop( m_SoundFireLoop, "HeavyFire_SoundSet", 1.0, 2.0 );
		}
		
		if ( GetGame().IsServer() )
		{
			m_BonfireHeatingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
			m_BonfireHeatingTimer.Run( TIMER_HEATING_UPDATE_INTERVAL, this, "BonfireHeating", NULL, true );	
		}
	}
	
	override void EEDelete( EntityAI parent )
	{
		super.EEDelete( parent );

		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			// outside of bubble - do effects cleanup (light, particles, sound)
			
			// light
			if ( m_Light )
				m_Light.FadeOut();
			
			// particles 
			if ( m_ParticleSmoke )
				m_ParticleSmoke.Stop();
			if ( m_ParticleFire )
				m_ParticleFire.Stop();
			
			// sounds 
			if ( m_SoundFireLoop )
				m_SoundFireLoop.SoundStop();
		}
		
		if ( GetGame().IsServer() )
		{
			if ( m_BonfireHeatingTimer && m_BonfireHeatingTimer.IsRunning() )
			{
				m_BonfireHeatingTimer.Stop();
			}
		}
	}	
	
	protected void BonfireHeating()
	{
		#ifdef DEVELOPER
		DebugBonfire();
		#endif
		
		//transfer heat to near players
		BonfireTransferHeatToNearPlayers();
	}
	
	//transfer heat to all nearby players
	protected void BonfireTransferHeatToNearPlayers()
	{
		float distance;

		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;

		GetGame().GetObjectsAtPosition( GetPosition(), PARAM_HEAT_RADIUS, nearest_objects, proxy_cargos ); 

		for ( int i = 0; i < nearest_objects.Count(); i++ )
		{
			Object nearest_object = nearest_objects.Get(i);
			
			//! heat transfer to player
			if ( nearest_object.IsInherited( PlayerBase ) )
			{
				PlayerBase player = PlayerBase.Cast( nearest_object );
				distance = vector.Distance( player.GetPosition(), GetPosition() );
				//distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
				float temperature = 0;
				
				//! heat transfer through air to player ( anv temperature )
				if ( distance > PARAM_FULL_HEAT_RADIUS )
				{
					float distFactor = 1 - ( distance / PARAM_HEAT_RADIUS );
					temperature = CONST_FIRE_TEMP * ( PARAM_HEAT_THROUGH_AIR_COEF * distFactor);
				}
				else
					temperature = CONST_FIRE_TEMP * ( PARAM_HEAT_THROUGH_AIR_COEF );
				
				player.AddToEnvironmentTemperature( temperature );
			}
			//! heat transfer to items (no in player possession)
			else if ( nearest_object != this && nearest_object.IsInherited( ItemBase ) && nearest_object.GetParent() == null )
			{
				ItemBase item = ItemBase.Cast( nearest_object );
				float wetness = item.GetWet();

				//! drying of items around the fireplace (based on distance)
				if ( wetness > 0 )
				{
					distance = vector.Distance( item.GetPosition(), GetPosition() );
					distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
					
					wetness = wetness * ( PARAM_HEAT_THROUGH_AIR_COEF / distance );
					wetness = Math.Clamp( wetness, item.GetWetMin(), item.GetWetMax() );
					item.AddWet( -wetness );
				}
			}
		}
	}
	
#ifdef DEVELOPER
	
	protected ref array<Shape> dbgTargets = new array<Shape>();
	
	void DebugBonfire()
	{
		bool showSpheres = DiagMenu.GetBool(DiagMenuIDs.DM_SHOW_FIREHEAT_RADIUS);
		if (showSpheres)
		{
			if ( !GetGame().IsMultiplayer() || !GetGame().IsServer() )
			{
				//Print("Debug");
				vector w_pos, w_pos_sphr, w_pos_lend;
				Object obj;
		
				CleanupDebugShapes(dbgTargets);
		
				w_pos = this.GetPosition();
				// sphere pos tweaks
				w_pos_sphr = w_pos;
				// line pos tweaks
				w_pos_lend = w_pos;
				
				dbgTargets.Insert( Debug.DrawSphere(w_pos_sphr, PARAM_FULL_HEAT_RADIUS, COLOR_RED_A, ShapeFlags.TRANSP));
				dbgTargets.Insert( Debug.DrawSphere(w_pos_sphr, PARAM_HEAT_RADIUS, COLOR_YELLOW_A, ShapeFlags.TRANSP));
			}
		}
		else
			CleanupDebugShapes(dbgTargets);
	}
	
	protected void CleanupDebugShapes(array<Shape> shapes)
	{
		for ( int it = 0; it < shapes.Count(); ++it )
		{
			Debug.RemoveShape( shapes[it] );
		}

		shapes.Clear();
	}
	
#endif
}