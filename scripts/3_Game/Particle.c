class Particle extends ScriptedEntity
{
	protected 	int		m_ParticleID;
	protected 	float	m_Lifetime;
	protected 	int		m_PreviousFrame;
	protected 	bool 	m_IsPlaying;
	protected 	bool 	m_IsRepeat;
	private 	bool 	m_MarkedForDeletion;
	bool 				m_ForceOrientationRelativeToWorld = false;
	vector 				m_DefaultOri;
	vector 				m_DefaultPos;
	float 				m_MaxOriWiggle;
	float 				m_MaxOriInterval;
	ref Timer 			m_RandomizeOri;
	
	private Object 		m_ParentObject; // TO DO: Remove m_ParentObject parameter and use GetObject instead!
	private Object 		m_ParticleEffect;
	
	private vector 		m_GlobalPosPreviousFrame;
	
	static private const int MAX_EMITORS = 30; // Limits the amount of emitors this API works with. Increase in case of need.
	
	
	//====================================
	// Client: Constructor
	//====================================
	void Particle()
	{
		SetFlags(EntityFlags.VISIBLE, true);
		SetEventMask(EntityEvent.INIT);
		SetEventMask(EntityEvent.FRAME);
	}	
	
	//====================================
	// Client: UpdateState
	//====================================
	protected void UpdateState()
	{
		if ( m_IsPlaying == false && m_ParticleEffect)
		{
			DestroyParticleEffect();
		}
		else if ( m_IsPlaying == true && m_ParticleEffect == NULL )
		{
			CreateParticleEffect();
		}
	}
	
	Object GetParticleParent()
	{
		return m_ParentObject;
	}
	
	override bool IsParticle()
	{
		return true;
	}
	
	//====================================
	// Client: CreateParticleEffect
	//====================================
	private void CreateParticleEffect()
	{
		if (!GetGame().IsServer()  ||  !GetGame().IsMultiplayer())
		{
			if ( m_ParticleEffect == NULL )
			{
				m_ParticleEffect = GetGame().CreateObject("#particlesourceenf", Vector(0,0,0), true); // particle source must be lowercase!
			}
			
			this.AddChild(m_ParticleEffect, -1, m_ForceOrientationRelativeToWorld);
			vobject vobj = NULL;
			
			vobj = GetObject( ParticleList.GetParticleFullPath(m_ParticleID) );
			
			m_ParticleEffect.SetObject(vobj, "");
			ReleaseObject(vobj);
			
			m_IsRepeat = IsRepeat();
			m_Lifetime = GetMaxLifetime();
		}
	}
	
	float GetMaxLifetime()
	{
		if (m_ParticleEffect)
		{
			float lifetime_min = 0;
			float lifetime_random = 0;
			float lifetime_return = 0;
			float effect_time = 0;
			string emitors_array[MAX_EMITORS];
			
			int emitors = GetParticleEmitors(m_ParticleEffect, emitors_array, MAX_EMITORS);
			
			for (int i = 0; i < emitors; i++)
			{
				GetParticleParm(m_ParticleEffect, i, EmitorParam.LIFETIME, lifetime_min);
				GetParticleParm(m_ParticleEffect, i, EmitorParam.LIFETIME_RND, lifetime_random);
				GetParticleParm(m_ParticleEffect, i, EmitorParam.EFFECT_TIME, effect_time);
				
				if ( lifetime_min + lifetime_random + effect_time > lifetime_return )
				{
					lifetime_return = lifetime_min + lifetime_random + effect_time;
				}
			}
		}
		
		return lifetime_return;
	}
	
	//! Returns direct particle effect entity which is usually handled by this class 'Particle'
	Object GetDirectParticleEffect()
	{
		return m_ParticleEffect;
	}
	
	//====================================
	// Client: DestroyParticleEffect
	//====================================	
	private void DestroyParticleEffect()
	{
		if ( m_ParticleEffect && GetGame() )
		{
			SetParameter(-1, EmitorParam.LIFETIME, 0);
			SetParameter(-1, EmitorParam.LIFETIME_RND, 0);
			SetParameter(-1, EmitorParam.REPEAT, 0);
			
			m_IsRepeat = false;
			
			// Particle is now disabled. The EOnFrame event will delete it from the world when all of its particles are despawned.
		}
	}
	
	//====================================
	// Client: SetParameter
	//====================================
	void SetParameter(int emitter, int parameter, float value)
	{
		// m_ParticleEffect -> owner of Particle, as set in Particle CreateParticleEffect()

		SetParticleParm(m_ParticleEffect, emitter, parameter, value);
	}
	
	//====================================
	// Client: GetParameter
	//====================================
	void GetParameter(int emitter, int parameter, out float value)
	{
		// m_ParticleEffect -> owner of Particle, as set in Particle CreateParticleEffect()

		GetParticleParm(m_ParticleEffect, emitter, parameter, value);
	}
	
	//====================================
	// Client: GetParticleCount
	// Warning! CPU expensive!
	//====================================
	int GetParticleCount()
	{
		if (m_ParticleEffect)
		{
			return m_ParticleEffect.GetParticleCount(m_ParticleEffect);
		}
		
		return 0;
	}
	
	//====================================
	// Client: IsRepeat()
	// Warning! CPU expensive!
	//====================================
	bool IsRepeat()
	{
		if (m_ParticleEffect)
		{
			int repeat = false;
			string emitors_array[MAX_EMITORS];
			
			int emitors = GetParticleEmitors(m_ParticleEffect, emitors_array, MAX_EMITORS);
			
			for (int i = 0; i < emitors; i++)
			{
				GetParticleParm(m_ParticleEffect, i, EmitorParam.REPEAT, repeat);
				
				if (repeat)
				{
					return true;
				}
			}
		}
		
		return false;
	}
	
	// !Scales the given parameter on all emitors relatively to their ORIGINAL value. If you want to change a specific emitor, then use function SetParticleParm().
	void ScaleParticleParamFromOriginal(int parameter_id, float coef )
	{
		if (m_ParticleEffect)
		{
			string emitors_array[MAX_EMITORS];
			
			int emitors = GetParticleEmitors(m_ParticleEffect, emitors_array, MAX_EMITORS);
			
			for (int i = 0; i < emitors; i++)
			{
				float value
				GetParticleParmOriginal	(m_ParticleEffect, i, parameter_id, value);
				SetParticleParm			(m_ParticleEffect, i, parameter_id, value * coef);
			}
		}
	}
	
	// !Scales the given parameter on all emitors relatively to their CURRENT value. If you want to change a specific emitor, then use function SetParticleParm().
	void ScaleParticleParam(int parameter_id, float coef )
	{
		if (m_ParticleEffect)
		{
			string emitors_array[MAX_EMITORS];
			
			int emitors = GetParticleEmitors(m_ParticleEffect, emitors_array, MAX_EMITORS);
			
			for (int i = 0; i < emitors; i++)
			{
				float value
				GetParticleParm(m_ParticleEffect, i, parameter_id, value);
				SetParticleParm(m_ParticleEffect, i, parameter_id, value * coef);
			}
		}
	}
	
	// !Increments the value of the given parameter relatively from the ORIGINAL value. Use negative number to decrement value.
	void IncrementParticleParamFromOriginal(int parameter_id, float value )
	{
		if (m_ParticleEffect)
		{
			string emitors_array[MAX_EMITORS];
			
			int emitors = GetParticleEmitors(m_ParticleEffect, emitors_array, MAX_EMITORS);
			
			for (int i = 0; i < emitors; i++)
			{
				float param
				GetParticleParm(m_ParticleEffect, i, parameter_id, param);
				SetParticleParm(m_ParticleEffect, i, parameter_id, param + value);
			}
		}
	}
	
	// !Increments the value of the given parameter relatively from the CURRENT value. Use negative number to decrement value.
	void IncrementParticleParam(int parameter_id, float value )
	{
		if (m_ParticleEffect)
		{
			string emitors_array[MAX_EMITORS];
			
			int emitors = GetParticleEmitors(m_ParticleEffect, emitors_array, MAX_EMITORS);
			
			for (int i = 0; i < emitors; i++)
			{
				float param
				GetParticleParm(m_ParticleEffect, i, parameter_id, param);
				SetParticleParm(m_ParticleEffect, i, parameter_id, param + value);
			}
		}
	}
	
	// !Scale some parameter for all emitors in this particle effect. If you want to change a specific emitor, then use function SetParticleParm().
	void SetParticleParam(int parameter_id, float value )
	{
		SetParticleParm(m_ParticleEffect, -1, parameter_id, value);
	}
	
	
	//====================================
	// Client: OnCheckAutoDelete
	//====================================	
	void OnCheckAutoDelete()
	{
		if (m_Lifetime <= 0)
		{
			if (!m_MarkedForDeletion)
			{
				m_IsRepeat = IsRepeat(); // It is possible that the REPEAT flag was changed during lifetime, so it needs to be checked again.
				
				if ( m_IsRepeat )
				{
					m_Lifetime = GetMaxLifetime();
				}
				else
				{
					m_IsPlaying = false;
					
					if ( GetParticleCount() == 0 )
					{
						m_MarkedForDeletion = true;
						OnToDelete();
					}
				}
			}
			else
			{
				if ( m_MarkedForDeletion )
				{
					GetGame().ObjectDelete( m_ParticleEffect );
					m_ParticleEffect = NULL;
					GetGame().ObjectDelete( this );
				}
			}
		}
	}
	
	override void EOnFrame(IEntity other, float timeSlice)
	{
		super.EOnFrame(other, timeSlice);
		
		m_Lifetime -= timeSlice;
		
		// WIP experiment with measurements of particle's speed.
		/*EntityAI parent = EntityAI.Cast( GetParent() ); // THIS SHOULD BE IEntity kind! Do not cast here if not necesarry!
		
		if (parent)
		{
			if ( m_GlobalPosPreviousFrame == Vector(0,0,0) )
			{
				m_GlobalPosPreviousFrame = GetPosition();
				return;
			}
			
			if ( m_PreviousFrame == 0 )
			{
				m_PreviousFrame = GetGame().GetTime();
				return;
			}
			
			vector global_pos_now = GetPosition();
			
			float distance_per_frame = vector.Distance(global_pos_now, m_GlobalPosPreviousFrame);
			int lag = GetGame().GetTime() - m_PreviousFrame;
			float stretch = distance_per_frame * lag;
			
			if ( parent.GetType() == "Torch" )
				Print(stretch);
			
			m_GlobalPosPreviousFrame = GetPosition();
		}*/
		
		OnCheckAutoDelete();
	}
	
	// Called before deletion
	private void OnToDelete()
	{
		
		
		
		/* TODO Call Back To Effect
		if (m_MyEffectHolder)
		{
			if ( m_MyEffectHolder.GetParticle() == this )
			{
				m_MyEffectHolder.SetParticle(NULL);
				m_MyEffectHolder.CheckLifeSpan();
			}
		}
		*/
	}
	
	//! Makes the particle change direction by random_angle every random_interval seconds.
	void SetWiggle(float random_angle, float random_interval)
	{
		if ( !random_angle == 0  ||  !random_interval == 0)
		{
			m_MaxOriWiggle = random_angle;
			m_MaxOriInterval = random_interval;
			
			if (!m_RandomizeOri)
				m_RandomizeOri = new Timer( CALL_CATEGORY_GAMEPLAY );
			
			if ( !m_RandomizeOri.IsRunning() ) // Makes sure the timer is NOT running already
			{
				m_RandomizeOri.Run( Math.RandomFloat(0, m_MaxOriInterval) , this, "RandomizeOrientation", NULL, false);
			}
		}
		else if (m_RandomizeOri)
		{
			m_RandomizeOri.Stop();
			delete m_RandomizeOri;
		}
	}
	
	//! Stops randomized wiggle
	void StopWiggle()
	{
		SetWiggle(0,0);
	}
	
	// Randomizes orientation within m_MaxOriWiggle
	void RandomizeOrientation()
	{
		if (m_ParentObject)
		{
			if ( !m_RandomizeOri.IsRunning() )
			{
				m_RandomizeOri.Run( Math.RandomFloat(0, m_MaxOriInterval) , this, "RandomizeOrientation", NULL, false);
			}
			
			Object old_parent = m_ParentObject;
			AddAsChild( NULL );
			
			float r1 = Math.RandomFloat(0, m_MaxOriWiggle*2) - m_MaxOriWiggle;
			float r2 = Math.RandomFloat(0, m_MaxOriWiggle*2) - m_MaxOriWiggle;
			float r3 = Math.RandomFloat(0, m_MaxOriWiggle*2) - m_MaxOriWiggle;
			
			vector new_ori = m_DefaultOri + Vector( r1, r2, r3 );
			AddAsChild( old_parent, m_DefaultPos, new_ori );
		}
	}
	
	/** \name Create a particle
		You can create a particle either at some position, or create it as an attachment on some object.
	*/
	
	/**
	\brief Creates a particle emitter and attaches it on the given object
		\param particle_id \p int Particle ID registered in ParticleList.c
		\param parent_obj \p Object Instance on which this particle will be attached
		\param local_pos \p vector Attachment position local to the parent (optional)
		\param local_ori \p vector Orientation local to the parent (Pitch, Yawn, Roll in degrees) (Optional)
		\return \p Particle Created particle instance
	*/
	static Particle CreateOnObject( int particle_id, Object parent_obj, vector local_pos = "0 0 0", vector local_ori = "0 0 0", bool force_world_rotation = false )
	{
		if (!parent_obj)
			Error("ERROR when creating a particle! Parameter parent_obj is NULL!");
		
		vector global_pos = parent_obj.GetPosition();
		Particle p = CreateInWorld(particle_id, global_pos, Vector(0,0,0), force_world_rotation);
		p.AddAsChild(parent_obj, local_pos, local_ori, force_world_rotation);
		p.m_DefaultOri = local_ori;
		
		return p;
	}
	
	//! LEGACY FUNCTION!
	static Particle Create( int particle_id, Object parent_obj, vector local_pos = "0 0 0", vector local_ori = "0 0 0" )
	{
		return CreateOnObject( particle_id, parent_obj, local_pos, local_ori);
	}
	
	/**
	\brief Creates a particle emitter on the given position
		\param particle_id \p int Particle ID registered in ParticleList.c
		\param global_pos \p Vector Position where the particel will be created
		\param global_ori \p vector Orientation (Pitch, Yawn, Roll in degrees) (Optional)
		\return \p Particle Created particle instance
	*/
	static Particle CreateInWorld( int particle_id, vector global_pos, vector global_ori = "0 0 0", bool force_world_rotation = false )
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
			Particle p = Particle.Cast( GetGame().CreateObject("Particle", global_pos, true) );
			p.SetSource(particle_id);
			p.SetOrientation(global_ori);
			p.m_ForceOrientationRelativeToWorld = force_world_rotation;
			return p;
		}
		else
		{
			Error("A particle was spawned on server-side! Particles can be spawned on client-side only!");
		}
		
		return null;
	}
	
	//! Legacy function for modding support from 1.01 and below.
	static Particle Create( int particle_id, vector global_pos, vector global_ori = "0 0 0" )
	{
		return CreateInWorld( particle_id, global_pos, global_ori );
	}
	
	
	
	/** \name Play/Stop particle
		You can use the following Play(...) functions to (create and) activate a particle in 1 line of your script.
	*/
	
	
	/**
	\brief Creates a particle emitter, attaches it on the given object and activates it
		\param particle_id \p int Particle ID registered in ParticleList.c
		\param parent_obj \p Object Instance on which this particle will be attached
		\param local_pos \p vector Attachment position local to the parent (optional)
		\param local_ori \p vector Orientation local to the parent (Pitch, Yaw, Roll in degrees) (Optional)
		\param force_world_rotation \p bool Forces particle's orientation to rotate relative to the world and not with the object (Optional)
		\return \p Particle Created particle instance
	*/
	static Particle PlayOnObject( int particle_id, Object parent_obj, vector local_pos = "0 0 0", vector local_ori = "0 0 0", bool force_world_rotation = false )
	{
		Particle p = CreateOnObject(particle_id, parent_obj, local_pos, local_ori, force_world_rotation);
		p.PlayParticle();
		
		return p;
	}
	
	//! Legacy function for modding support from 1.01 and below.
	static Particle Play( int particle_id, Object parent_obj, vector local_pos = "0 0 0", vector local_ori = "0 0 0" )
	{
		return PlayOnObject( particle_id, parent_obj, local_pos, local_ori);
	}
	
	/**
	\brief Creates a particle emitter on the given position and activates it
		\param particle_id \p int Particle ID registered in ParticleList.c
		\param global_pos \p Vector Position where the particel will be created
		\return \p Particle Created particle instance
	*/
	static Particle PlayInWorld( int particle_id, vector global_pos)
	{
		Particle p = CreateInWorld(particle_id, global_pos);
		p.PlayParticle();
		
		return p;
	}
	
	//! Legacy function for modding support from 1.01 and below.
	static Particle Play( int particle_id, vector global_pos)
	{
		return PlayInWorld( particle_id, global_pos);
	}
	
	//! Plays the current particle. The optional parameter changes this particle for the new one.
	void PlayParticle(int particle_id = -1)
	{
		if ( particle_id > -1 )
		{
			SetSource(particle_id);
		}
		
		m_IsPlaying = true;

		UpdateState();
	}
	
	//! Legacy function for modding support from 1.01 and below. Please use PlayParticle(...) instead of this one.
	void Play(int particle_id = -1)
	{
		PlayParticle(particle_id);
	}
	
	//! Stops generating particles. Emitter is later automatically removed from memory on clients when its particle count is 0.
	void Stop()
	{
		m_IsPlaying = false;
		
		
		// Without the following we might get an error when a particle parent is despawned client-side.
		Object parent = Object.Cast( GetParent() );
		if( parent )
		{
			vector world_pos = GetPosition();
			parent.RemoveChild(this);
			SetPosition(world_pos);
		}
		
		UpdateState();
	}
	
	/**
	\brief Attaches this particle onto some object. If NULL value is provided then the particle will be detached from the current parent.
		\param parent \p Object Parent onto which this particle will be attached
		\param local_pos \p vector Attachment position local to the parent (optional)
		\param local_ori \p vector Orientation local to the parent (Pitch, Yawn, Roll in degrees) (Optional)
	*/
	void AddAsChild(Object parent, vector local_pos = "0 0 0", vector local_ori = "0 0 0", bool force_rotation_to_world = false)
	{
		if (parent  &&  !parent.ToDelete()) // AddAsChild method is sometimes called from a timer. Due to that it is necesarry to use ToDelete() here to check if the parent object is flagged for deletion or not on client, because sometimes this code is executed before the parent's destructor from where this would normally be handled.
		{
			SetPosition(local_pos);
			SetOrientation(local_ori);
			m_ParentObject = parent;
			m_DefaultPos = local_pos;
			m_ForceOrientationRelativeToWorld = force_rotation_to_world;
			
			if (m_ParticleEffect)
				AddChild(m_ParticleEffect, -1, m_ForceOrientationRelativeToWorld);
			
			parent.AddChild(this, -1, false); // Pivot does not work in DayZ so we use -1.
		}
		else
		{
			if (m_ParentObject  &&  !m_ParentObject.ToDelete())
			{
				m_ParentObject.RemoveChild(this);
				SetPosition( m_ParentObject.ModelToWorld( GetPosition() ) ); // Move the detached particle to its last position on the parent. Otherwise it will be around [0,0,0].
				m_ParentObject = NULL;
			}
		}
	}
	
	//! Sets particle id
	void SetSource(int particle_id)
	{
		m_ParticleID = particle_id;
	}
	
	//! Returns particle id
	int GetParticleID()
	{
		return m_ParticleID;
	}
}