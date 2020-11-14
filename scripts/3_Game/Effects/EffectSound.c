class EffectSound : Effect
{
	ref ScriptInvoker Event_OnSoundWaveStarted		= new ScriptInvoker();
	ref ScriptInvoker Event_OnSoundWaveEnded		= new ScriptInvoker();
	ref ScriptInvoker Event_OnSoundFadeInStopped	= new ScriptInvoker();
	ref ScriptInvoker Event_OnSoundFadeOutStarted	= new ScriptInvoker();
	
	// Sounds
	protected string					m_SoundSetName;
	protected ref SoundParams			m_SoundParams;
	protected ref SoundObjectBuilder	m_SoundObjectBuilder;
	protected ref SoundObject			m_SoundObject;
	protected ref AbstractWave			m_SoundWaveObject;
	protected Object					m_SoundParent;
	protected WaveKind					m_SoundWaveKind;
	protected bool						m_SoundLoop;
	protected bool						m_SetEnvVariables;
	protected bool						m_SoundAutodestroy;
	protected bool						m_SoundWaveIsPlaying;
	protected bool						m_SoundWaveStarting;
	protected bool						m_SoundWaveStopping;
	protected float						m_SoundWaveLenght;
	protected float						m_SoundWaveVolume;
	protected float						m_SoundWaveVolumeMax;
	protected float						m_SoundWaveTime;
	
	protected float						m_SoundFadeOutStartTime;
	protected float						m_SoundFadeOutDuration;
	protected float						m_SoundFadeOutInitVolume;
	
	protected float						m_SoundFadeInDuration;
	
	//=====================================
	// Constructor
	//=====================================
	void EffectSound()
	{
		m_SoundWaveKind = WaveKind.WAVEEFFECTEX;
		m_SoundWaveVolume = 0;
		m_SoundWaveVolumeMax = 1;
		m_SoundAutodestroy = false;
	}
	
	//=====================================
	// Destructor
	//=====================================
	void ~EffectSound()
	{
		SEffectManager.Event_OnFrameUpdate.Remove(Event_OnFrameUpdate);
	}
	
	//=====================================
	// IsSound
	//=====================================
	override bool IsSound()
	{
		return true;
	}
	
	//=====================================
	// GetSoundWaveLenght
	//=====================================
	float GetSoundWaveLenght()
	{
		return m_SoundWaveLenght;
	}
	
	//=====================================
	// GetSoundWaveTime
	//=====================================
	float GetSoundWaveTime()
	{
		return m_SoundWaveTime;
	}
	
	//=====================================
	// SetSoundVolume
	//=====================================
	void SetSoundVolume(float volume)
	{
		m_SoundWaveVolume = volume;
		if ( m_SoundWaveObject )
			m_SoundWaveObject.SetVolumeRelative( volume );
	}
	
	//=====================================
	// SetSoundMaxVolume
	//=====================================
	void SetSoundMaxVolume(float volume)
	{
		m_SoundWaveVolumeMax = volume;
		if ( m_SoundWaveObject )
			m_SoundWaveObject.SetVolumeRelative( m_SoundWaveVolume );
	}
		
	//=====================================
	// SetSoundLoop
	//=====================================
	void SetSoundLoop(bool loop)
	{
		m_SoundLoop = loop;
		
		if ( m_SoundWaveObject )
			m_SoundWaveObject.Loop( loop );
	}
	
	//=====================================
	// GetSoundVolume
	//=====================================
	float GetSoundVolume()
	{
		return m_SoundWaveVolume;
	}
	
	//=====================================
	// SoundSetWaveKind
	//=====================================
	void SetSoundWaveKind(WaveKind wave_kind)
	{
		m_SoundWaveKind = wave_kind;
	}
	
	//=====================================
	// SetParent
	//=====================================
	void SetParent(Object parent_obj)
	{
		m_SoundParent = parent_obj;
	}
	
	//=====================================
	// SetSoundFadeIn
	//=====================================
	void SetSoundFadeIn(float fade_in)
	{
		m_SoundFadeInDuration = fade_in;
	}
	
	//=====================================
	// SetSoundFadeOut
	//=====================================
	void SetSoundFadeOut(float fade_out)
	{
		m_SoundFadeOutDuration = fade_out;
	}
	
	//=====================================
	// SetSoundName
	//=====================================
	void SetSoundSet(string snd)
	{
		m_SoundSetName = snd;
	}
	
	//=====================================
	// SetEnviromentVariables
	//=====================================
	void SetEnviromentVariables(bool setEnvVariables)
	{
		m_SetEnvVariables = setEnvVariables;
	}
	
	//=====================================
	// IsSoundPlaying
	//=====================================
	bool IsSoundPlaying()
	{
		return m_SoundWaveIsPlaying;
	}
	
	//=====================================
	// IsSoundAutodestroy
	//=====================================
	void SetSoundAutodestroy(bool auto_destroy)
	{
		m_SoundAutodestroy = auto_destroy;
	}
	
	//=====================================
	// IsSoundAutodestroy
	//=====================================
	bool IsSoundAutodestroy()
	{
		return m_SoundAutodestroy;
	}
	
	//=====================================
	// SoundLoad
	//=====================================
	bool SoundLoad()
	{
		if ( !m_SoundParams )
		{
			//Print("SoundLoad is loading..");
			m_SoundParams = new SoundParams( m_SoundSetName );
			if ( !m_SoundParams.IsValid() )
			{
				//SoundError("Invalid sound set.");
				return false;
			}
			
			m_SoundObjectBuilder = new SoundObjectBuilder( m_SoundParams );
			if(m_SetEnvVariables)
			{
				m_SoundObjectBuilder.UpdateEnvSoundControllers(GetPosition());
			}
			
			m_SoundObject = m_SoundObjectBuilder.BuildSoundObject();
			
			if ( m_SoundObject )
			{
				m_SoundObject.SetKind( m_SoundWaveKind );
			}
			else
			{
				Error("[Error][Sound]: SoundLoad() -> m_SoundObject is null -> m_SoundSetName: "+ m_SoundSetName);
			}
		}
		else
		{
			//Print("SoundLoad is loaded.");
		}
		
		return true;
	}
	
	//=====================================
	// IsSoundValid
	//=====================================
	bool IsSoundValid()
	{
		return m_SoundParams.IsValid();
	}
	
	// !Plays all elements this effects consists of
	//=====================================
	// Play
	//=====================================
	bool SoundPlay()
	{
		//SoundReset();
		
		if (m_SoundSetName != "")
		{
			bool was_loaded = (m_SoundParams != NULL);
			bool is_sound_valid = SoundLoad();
			if ( is_sound_valid )
			{
				if(m_SetEnvVariables && was_loaded)
				{
					m_SoundObjectBuilder.UpdateEnvSoundControllers(GetPosition());
					m_SoundObject = m_SoundObjectBuilder.BuildSoundObject();
					m_SoundObject.SetKind( m_SoundWaveKind );
				}
				
				if ( m_SoundObject )
				{
					m_SoundObject.SetPosition( GetPosition() );
					m_SoundWaveObject = GetGame().GetSoundScene().Play3D( m_SoundObject, m_SoundObjectBuilder );
					m_SoundWaveLenght = m_SoundWaveObject.GetLength();
					
					if ( SoundWaveValidation() )
					{
						if ( m_SoundFadeInDuration > 0 )
						{
							m_SoundWaveObject.SetVolumeRelative( 0 );
							m_SoundFadeOutStartTime = m_SoundWaveLenght - m_SoundFadeInDuration;
						}
						
						SetSoundLoop( m_SoundLoop );
						
						m_SoundWaveStarting = true;
						
						AbstractWaveEvents events = AbstractWaveEvents.Cast(m_SoundWaveObject.GetUserData());
						events.Event_OnSoundWaveStarted.Insert( Event_OnSoundWaveStarted );
						events.Event_OnSoundWaveEnded.Insert( Event_OnSoundWaveEnded );
						
						UpdateEvents();
						
						return true;
					}
					else
					{
						m_SoundWaveObject.Stop();
					}
				}
				else
				{
					Error("[Error][Sound]: SoundPlay() -> m_SoundObject is null -> m_SoundSetName: "+ m_SoundSetName);
				}
			}
		}
		
		return false;
	}
	
	//=====================================
	// SoundStop
	//=====================================
	void SoundStop()
	{
		if ( IsSoundPlaying() )
		{
			if ( m_SoundFadeOutDuration > 0 )
			{
				m_SoundWaveStopping = true;
				m_SoundFadeOutStartTime = m_SoundWaveTime;
			}
			else
			{
				m_SoundWaveObject.Stop();
			}
		}
		else
		{
			SoundReset();
		}
	}
	
	//=====================================
	// SoundWaveValidation
	//=====================================
	protected bool SoundWaveValidation()
	{
		bool valid = true;
		
		if ( m_SoundFadeInDuration > GetSoundWaveLenght() )
		{
			SoundError("FadeIn is longer than sound wave lengt.");
			valid = false;
		}
		
		if ( m_SoundFadeOutDuration > GetSoundWaveLenght() )
		{
			SoundError("FadeOut is longer than sound wave lengt.");
			valid = false;
		}
		
		if ( m_SoundFadeOutDuration + m_SoundFadeInDuration > GetSoundWaveLenght() )
		{
			SoundError("FadeIn & FadeOut are longer than sound wave lengt.");
			valid = false;
		}
		
		return valid;
	}
	
	//=====================================
	// UpdateEvents
	//=====================================
	protected void UpdateEvents()
	{
		if ( m_SoundWaveObject )
		{
			SetEnableEventFrame(true);
		}
		else
		{
			SetEnableEventFrame(false);
		}
	}
	
	//=====================================
	// Event_OnFrameUpdate
	//=====================================
	override void Event_OnFrameUpdate(float time_delta)
	{
		// Override this method for own use
		if ( IsSoundPlaying() )
		{			
			//Print("SoundTime: "+ m_SoundWaveTime +"/"+ GetSoundWaveLenght() +" Volume: "+ GetSoundVolume());
			
			if ( m_SoundParent )
			{
				m_SoundWaveObject.SetPosition( m_SoundParent.GetPosition() );
			}
			
			// FadeIn
			if ( m_SoundWaveStarting )
			{
				if ( m_SoundFadeInDuration > 0 )
				{
					SetSoundVolume( GetSoundVolume() + (time_delta / m_SoundFadeInDuration) );
					
					if ( GetSoundVolume() >= m_SoundWaveVolumeMax )
					{
						Event_OnSoundFadeInStopped();
						SetSoundVolume( m_SoundWaveVolumeMax );
						m_SoundWaveStarting = false;
					}
				}
				else
				{
					SetSoundVolume( m_SoundWaveVolumeMax );
					m_SoundWaveStarting = false;
				}
			}
			
			// FadeOut
			if ( m_SoundWaveStopping )
			{
				if ( m_SoundFadeOutDuration > 0 )
				{
					if ( m_SoundFadeOutInitVolume == 0 )
					{
						m_SoundFadeOutInitVolume = GetSoundVolume();
						Event_OnSoundFadeOutStarted();
					}
					
					SetSoundVolume( GetSoundVolume() - (m_SoundFadeOutInitVolume / m_SoundFadeOutDuration * time_delta) );
				}
				else
				{
					SetSoundVolume( 0 );
				}
				
				if ( GetSoundVolume() <= 0 )
				{		
					if ( m_SoundWaveObject )
					{
						m_SoundWaveObject.Stop();
					}
				}
			}
			
			// Counting timer here becouse loop play
			m_SoundWaveTime += time_delta;
		}
	}
	
	//=====================================
	// SoundReset
	//=====================================
	protected void SoundReset()
	{
		m_SoundWaveIsPlaying		= false;
		m_SoundWaveVolume			= m_SoundWaveVolumeMax;
		m_SoundWaveTime				= 0;
		m_SoundFadeOutInitVolume	= 0;
		m_SoundFadeOutStartTime		= 0;
		
		if ( m_SoundWaveObject )
		{
			m_SoundWaveObject.Stop();
			m_SoundWaveObject.SetVolumeRelative( m_SoundWaveVolumeMax );
		}
	}
	
	//=====================================
	// Event_OnSoundWaveStarted
	//=====================================
	void Event_OnSoundWaveStarted()
	{
		// Override this method for own use
		//Print("Event_OnSoundWaveStarted");
		m_SoundWaveIsPlaying = true;
		
		Event_OnSoundWaveStarted.Invoke(this);
	}
	
	//=====================================
	// Event_OnSoundWaveEnded
	//=====================================
	void Event_OnSoundWaveEnded()
	{
		// Override this method wfor own use
		//Print("Event_OnSoundWaveEnded");
		m_SoundWaveIsPlaying = false;
		
		Event_OnSoundWaveEnded.Invoke(this);
		
		if ( IsSoundAutodestroy() )
		{
			//SEffectManager.DestroySound( this );
			if ( GetGame() )
			{
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( SEffectManager.DestroySound, this );			
			}
		}		
	}
	
	//=====================================
	// Event_OnSoundFadeInStopped
	//=====================================
	void Event_OnSoundFadeInStopped()
	{
		// Override this method for own use
		//Print("Event_OnSoundFadeInStopped");
		
		Event_OnSoundFadeInStopped.Invoke(this);
	}
	
	//=====================================
	// Event_OnSoundFadeInStopped
	//=====================================
	void Event_OnSoundFadeOutStarted()
	{
		// Override this method for own use
		//Print("Event_OnSoundFadeOutStarted");
		
		Event_OnSoundFadeOutStarted.Invoke(this);
	}
	
	//=====================================
	// SoundError
	//=====================================
	protected void SoundError(string err_msg)
	{
		Error("EffectSound<"+this+">: SoundSetName: \"" + m_SoundSetName + "\" => "+ err_msg);
	}
}