class SEffectManager
{
	protected static ref array<int> m_FreeEffectIDs = new array<int>;
	protected static ref map<int, ref Effect> m_EffectsMap = new map<int, ref Effect>;
	protected static int m_HighestFreeEffectID = 1;
	
	static ref ScriptInvoker Event_OnFrameUpdate = new ScriptInvoker();
	
	//===============================
	// EffectRegister
	//===============================
	static int EffectRegister(Effect effect)
	{
		int id = GetFreeEffectID();
		m_EffectsMap.Insert(id, effect);
		effect.SetID(id);
		
		if ( effect.IsSound() )
		{
			EffectSound sound = EffectSound.Cast( effect );
			sound.Event_OnSoundWaveEnded.Insert( SEffectManager.Event_OnSoundWaveEnded );
		}
		
		return id;
	}
	
	//===============================
	// EffectUnregister
	//===============================
	static void EffectUnregister(int id)
    {
		m_EffectsMap.Remove(id);
		
		if ( m_FreeEffectIDs.Find(id) == -1 )
		{
			m_FreeEffectIDs.Insert(id);
		}
    }
	
	//===============================
	// CreateSound
	//===============================
	static EffectSound CreateSound(string sound_set, vector position, float play_fade_in = 0, float stop_fade_out = 0, bool loop = false)
	{
		ref EffectSound effect_sound = new EffectSound();
		effect_sound.SetSoundSet(sound_set);
		effect_sound.SetPosition(position);
		effect_sound.SetSoundFadeIn(play_fade_in);
		effect_sound.SetSoundFadeOut(stop_fade_out);
		effect_sound.SetSoundLoop(loop);
		
		EffectRegister( effect_sound );
		
		return effect_sound;
	}
	
	//===============================
	// PlaySound
	//===============================
	static EffectSound PlaySound(string sound_set, vector position, float play_fade_in = 0, float stop_fade_out = 0, bool loop = false)
	{
		ref EffectSound effect_sound = CreateSound(sound_set, position, play_fade_in, stop_fade_out, loop);
				
		effect_sound.SoundPlay();
		
		return effect_sound;
	}
	
	//===============================
	// PlaySoundOnObject
	//===============================
	static EffectSound PlaySoundOnObject(string sound_set, Object parent_object, float play_fade_in = 0, float stop_fade_out = 0, bool loop = false)
	{
		ref EffectSound effect_sound = CreateSound(sound_set, parent_object.GetPosition(), play_fade_in, stop_fade_out, loop);
		
		effect_sound.SetParent( parent_object );
		effect_sound.SoundPlay();
		
		return effect_sound;
	}
	
	//===============================
	// Event_OnSoundWaveEnded
	//===============================
	static void Event_OnSoundWaveEnded(EffectSound effect_sound)
	{		
		if ( effect_sound.IsSoundAutodestroy() )
		{			
			effect_sound.Event_OnSoundWaveEnded.Remove( SEffectManager.Event_OnSoundWaveEnded );
			
			//if ( DestroySound( effect_sound ) )
			{
				//Print("Sound Deleted");
			}
		}
	}
	
	//===============================
	// DestroySound
	//===============================
	static bool DestroySound(EffectSound sound_effect)
	{
		EffectUnregister( sound_effect.GetID() );
		sound_effect.SoundStop();
		delete sound_effect;
		
		return true;
	}
	
	//===============================
	// IsEffectExist
	//===============================
	static bool IsEffectExist( int effect_id )
	{
		if ( m_EffectsMap[effect_id] )
		{
			return true;
		}
		
		return false;
	}
	
	//===============================
	// PlayInWorld
	//===============================
	static int PlayInWorld(Effect eff, vector pos)
	{
		eff.SetPosition( pos );
		eff.Start();
		int id = EffectRegister(eff);
		
		return id;
	}
	
	//===============================
	// PlayOnObject
	//===============================
	static int PlayOnObject(Effect eff, Object obj, vector local_pos = "0 0 0", vector local_ori = "0 0 0", bool force_rotation_relative_to_world = false)
	{
		eff.SetAttachmentParent(obj);
		eff.SetAttachedLocalPos(local_pos);
		eff.SetAttachedLocalOri(local_ori);
		
		if (force_rotation_relative_to_world)
		{
			EffectParticle eff_particle = EffectParticle.Cast(eff);
			
			if (eff_particle)
			{
				eff_particle.ForceParticleRotationRelativeToWorld(force_rotation_relative_to_world);
			}
		}
		
		eff.Start();
		int id = EffectRegister(eff);
		
		return id;
	}
	
	//===============================
	// Stop
	//===============================
	static void Stop(int effect_id)
	{
		Effect eff = m_EffectsMap.Get(effect_id);
		
		if (eff)
		{
			eff.Stop();
		}
		else
		{
			string str = "SEffectManager> Stopping an effect with ID " + effect_id + " has failed! Such ID is not registered in m_EffectsMap!";
			Error(str);
		}
	}
	
	//===============================
	// GetEffectByID
	//===============================
	static Effect GetEffectByID(int effect_id)
	{
		return m_EffectsMap.Get(effect_id);
	}
	
	//===============================
	// Event_OnFrameUpdate
	//===============================
	static void Event_OnFrameUpdate(float time_delta)
	{
		Event_OnFrameUpdate.Invoke(time_delta);
	}
	
	//===============================
	// GetFreeEffectID
	//===============================
	protected static int GetFreeEffectID()
	{
		int return_id;
		
		if (m_FreeEffectIDs.Count() > 0)
		{
			return_id = m_FreeEffectIDs.Get(0);
			m_FreeEffectIDs.Remove(0);
		}
		else
		{
			return_id = m_HighestFreeEffectID;
			m_HighestFreeEffectID += 1;
		}
		
		return return_id;		
	}
}