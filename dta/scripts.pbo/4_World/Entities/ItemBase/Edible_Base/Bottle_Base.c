enum SoundTypeBottle
{
	POURING			= 1,
	EMPTYING		= 0,	
}

class Bottle_Base extends Edible_Base
{
	//Particles
	protected Particle 	m_ParticleCooking;
	protected int 		m_ParticlePlaying 	= ParticleList.INVALID;
	//Boiling
	//waiting for proper particle effects
	protected int PARTICLE_BOILING_EMPTY 	= ParticleList.COOKING_BOILING_EMPTY;
	protected int PARTICLE_BOILING_START 	= ParticleList.COOKING_BOILING_START;
	protected int PARTICLE_BOILING_DONE 	= ParticleList.COOKING_BOILING_DONE;
	//Baking
	protected int PARTICLE_BAKING_START 	= ParticleList.COOKING_BAKING_START;
	protected int PARTICLE_BAKING_DONE 		= ParticleList.COOKING_BAKING_DONE;
	//Drying
	protected int PARTICLE_DRYING_START 	= ParticleList.COOKING_DRYING_START;
	protected int PARTICLE_DRYING_DONE 		= ParticleList.COOKING_DRYING_DONE;
	//Burning
	protected int PARTICLE_BURNING_DONE		= ParticleList.COOKING_BURNING_DONE;
	
	//Sounds
	protected SoundOnVehicle	m_SoundCooking;
	protected string			m_SoundPlaying = "";
	ref protected EffectSound 	m_PouringLoopSound;
	ref protected EffectSound 	m_EmptyingLoopSound;
	
	//cooking data
	protected CookingMethodType 	m_CookingMethod;
	protected bool 					m_CookingIsDone;
	protected bool 					m_CookingIsEmpty;
	protected bool 					m_CookingIsBurned;	
	
	//Boiling
	const string SOUND_BOILING_EMPTY 		= "boilingWater";
	const string SOUND_BOILING_START 		= "boilingWater";
	const string SOUND_BOILING_DONE 		= "boilingWaterDone";
	//Baking
	const string SOUND_BAKING_START 		= "bake";
	const string SOUND_BAKING_DONE 			= "bakeDone";
	//Drying
	const string SOUND_DRYING_START 		= "dry";
	const string SOUND_DRYING_DONE 			= "dryDone";	
	//Burning
	const string SOUND_BURNING_DONE 		= "burned";
	
	float m_LiquidEmptyRate;
	private const float QUANTITY_EMPTIED_PER_SEC_DEFAULT = 200; //default
		
	void Bottle_Base()
	{
		m_PouringLoopSound  	= new EffectSound;
		m_EmptyingLoopSound = new EffectSound;
		
		RegisterNetSyncVariableInt( "m_CookingMethod", CookingMethodType.NONE, CookingMethodType.COUNT );
		RegisterNetSyncVariableBool("m_CookingIsDone");
		RegisterNetSyncVariableBool("m_CookingIsEmpty");
		RegisterNetSyncVariableBool("m_CookingIsBurned");
		
		m_LiquidEmptyRate = QUANTITY_EMPTIED_PER_SEC_DEFAULT;
	}
	
	void ~Bottle_Base()
	{
		SEffectManager.DestroySound( m_PouringLoopSound );
		SEffectManager.DestroySound( m_EmptyingLoopSound );
	}
	
	override void EEDelete( EntityAI parent )
	{
		super.EEDelete( parent );
		
		//remove audio visuals
		RemoveAudioVisuals();
	}	
	
	//================================================================
	// PARTICLES & SOUNDS
	//================================================================
	//Refreshes the audio and partcile effects on cooking pot
	//is_done - is the food baked, boiled, dried?
	//is_empty - is cooking quipment (cargo) empty?
	//is_burned - is any of the food items in the cargo in burned food stage?
	override void Synchronize()
	{
		if ( GetGame() && GetGame().IsServer() )
		{
			SetSynchDirty();
		}
	}
	
	override void OnRPC(PlayerIdentity sender, int rpc_type,ParamsReadContext  ctx) 
	{
		super.OnRPC(sender, rpc_type, ctx);
		
		ref Param1<bool> p = new Param1<bool>(false);
				
		if (ctx.Read(p))
		{
			bool play = p.param1;
		}
		
		switch(rpc_type)
		{
			case SoundTypeBottle.POURING:
			
				if ( play )
				{
					PlayPouringLoopSound();
				}
				
				if ( !play )
				{
					StopPouringLoopSound();
				}
			
			break;
			
			case SoundTypeBottle.EMPTYING:
				
				if ( play )
				{
					PlayEmptyingLoopSound();
				}
				
				if ( !play )
				{
					StopEmptyingLoopSound();
				}
			
			break;
		}
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		//refresh audio visuals
		if ( m_CookingMethod != CookingMethodType.NONE )
		{
			RefreshAudioVisuals( m_CookingMethod, m_CookingIsDone, m_CookingIsEmpty, m_CookingIsBurned );
		}
		else
		{
			RemoveAudioVisuals();
		}
	}
	
	void RemoveAudioVisualsOnClient()
	{
		m_CookingMethod		= CookingMethodType.NONE;
		
		//synchronize
		Synchronize();
	}
	
	void RefreshAudioVisualsOnClient( CookingMethodType cooking_method, bool is_done, bool is_empty, bool is_burned )
	{
		m_CookingMethod		= cooking_method;
		m_CookingIsDone 	= is_done;
		m_CookingIsEmpty	= is_empty;
		m_CookingIsBurned	= is_burned;
		
		//synchronize
		Synchronize();
	}
	
	void RefreshAudioVisuals( CookingMethodType cooking_method, bool is_done, bool is_empty, bool is_burned )
	{
		string sound_name;
		int particle_id;
		
		//if at least one of the food items is burned
		if ( is_burned )		
		{
			sound_name 		= SOUND_BURNING_DONE;
			particle_id 	= PARTICLE_BURNING_DONE;
		}
		//proper cooking methods
		else
		{
			if ( cooking_method == CookingMethodType.BOILING )
			{
				if ( is_empty )											//EMPTY
				{
					sound_name 		= SOUND_BOILING_EMPTY;
					particle_id 	= PARTICLE_BOILING_EMPTY;
				}
				else
				{
					if ( is_done )										//DONE
					{
						sound_name 		= SOUND_BOILING_DONE;
						particle_id 	= PARTICLE_BOILING_DONE;
					}
					else												//START
					{
						sound_name 		= SOUND_BOILING_START;
						particle_id 	= PARTICLE_BOILING_START;
					}
				}
			}
			else if ( cooking_method == CookingMethodType.BAKING )
			{
				if ( is_done )											//DONE
				{
					sound_name 		= SOUND_BAKING_DONE;
					particle_id 	= PARTICLE_BAKING_DONE;
				}
				else													//START
				{
					sound_name 		= SOUND_BAKING_START;
					particle_id 	= PARTICLE_BAKING_START;
				}
			}
			else if ( cooking_method == CookingMethodType.DRYING )
			{
				if ( is_done )											//DONE
				{
					sound_name 		= SOUND_DRYING_DONE;
					particle_id 	= PARTICLE_DRYING_DONE;
				}
				else													//START
				{
					sound_name 		= SOUND_DRYING_START;
					particle_id 	= PARTICLE_DRYING_START;
				}
			}			
		}
		
		//play effects
		ParticleCookingStart( particle_id );
		SoundCookingStart( sound_name );
	}
	
	void RemoveAudioVisuals()
	{
		ParticleCookingStop();
		SoundCookingStop();
	}
	
	//particles
	void ParticleCookingStart( int particle_id )
	{
		if ( m_ParticlePlaying != particle_id )
		{
			//stop previous particles
			ParticleCookingStop();
			
			//create new
			if ( GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
			{
				vector local_pos = GetSteamPosition();
				//TODO set steam position to pot (proxy) memory point (new hierarchy needed)
				//m_ParticleCooking = Particle.Create( particle_id, this, local_pos );
				m_ParticleCooking = Particle.PlayInWorld( particle_id, local_pos );
				m_ParticlePlaying = particle_id;
			}
		}
	}
	
	void ParticleCookingStop()
	{
		if ( m_ParticleCooking && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			m_ParticleCooking.Stop();
			m_ParticleCooking = NULL;
			m_ParticlePlaying = ParticleList.INVALID;
		}
	}
	
	//get position for steam particle
	protected vector GetSteamPosition()
	{
		EntityAI parent = GetHierarchyParent();
		vector particle_pos = parent.GetPosition();
		float steam_offset = 0;
		
		if ( parent )
		{
			if ( parent.IsInherited( PortableGasStove ) )
			{
				steam_offset = 0.2;
			}
			else if ( parent.IsInherited( FireplaceBase ) )
			{
				FireplaceBase fireplace = FireplaceBase.Cast( parent );
				
				if ( fireplace.IsBaseFireplace() )
				{
					steam_offset = 0.8;
				}
				else if ( fireplace.IsBarrelWithHoles() )
				{
					steam_offset = 1.1;
				}
				else if ( fireplace.IsFireplaceIndoor() )
				{
					steam_offset = 0.45;
				}		
			}
		}
		
		particle_pos[1] = particle_pos[1] + steam_offset;
		
		return particle_pos;
	}

	//sounds
	protected void SoundCookingStart( string sound_name )
	{
		if ( GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{	
			if ( m_SoundPlaying != sound_name )
			{
				//stop previous sound
				SoundCookingStop();
				
				//create new
				m_SoundCooking = PlaySoundLoop( sound_name, 50 );
				m_SoundPlaying = sound_name;
			}
		}
	}
	
	protected void SoundCookingStop()
	{
		if ( m_SoundCooking )
		{
			GetGame().ObjectDelete( m_SoundCooking );
			m_SoundCooking = NULL;
			m_SoundPlaying = "";
		}
	}	
		
	void PlayPouringLoopSound()
	{
		if ( !m_PouringLoopSound.IsSoundPlaying() )
		{
			m_PouringLoopSound = SEffectManager.PlaySound( GetPouringSoundset(), GetPosition() );
		}
	}
	
	void StopPouringLoopSound()
	{
		m_PouringLoopSound.SoundStop();
	}
		
	void PlayEmptyingLoopSound()
	{
		if ( !m_EmptyingLoopSound.IsSoundPlaying() )
		{
			m_EmptyingLoopSound = SEffectManager.PlaySound( GetEmptyingLoopSoundset(), GetPosition() );
		}
	}
	
	void StopEmptyingLoopSound()
	{
		m_EmptyingLoopSound.SoundStop();
				
		EffectSound sound =	SEffectManager.PlaySound( GetEmptyingEndSoundset(), GetPosition() );
		sound.SetSoundAutodestroy( true );
	}
		
	string GetEmptyingLoopSoundset()
	{		
		vector pos = GetPosition();
		string surface_type = GetGame().GetPlayer().GetSurfaceType();
		string sound_set = "";
		
		if ( GetGame().IsSurfaceHardGround( surface_type ) )
		{
			sound_set = GetEmptyingLoopSoundsetHard();
		}
		else if ( GetGame().IsSurfaceSoftGround( surface_type ) )
		{
			sound_set = GetEmptyingLoopSoundsetSoft();
		}
		else if ( GetGame().SurfaceIsPond( pos[0], pos[2] ) || GetGame().SurfaceIsSea( pos[0], pos[2] ) )
		{
			sound_set = GetEmptyingLoopSoundsetWater();
		}
		
		return sound_set;
	}
	
	string GetEmptyingEndSoundset()
	{		
		vector pos = GetPosition();
		string surface_type = GetGame().GetPlayer().GetSurfaceType();
		string sound_set = "";
		
		if ( GetGame().IsSurfaceHardGround( surface_type ) )
		{
			sound_set = GetEmptyingEndSoundsetHard();
		}
		else if ( GetGame().IsSurfaceSoftGround( surface_type ) )
		{
			sound_set = GetEmptyingEndSoundsetSoft();
		}
		else if ( GetGame().SurfaceIsPond( pos[0], pos[2] ) || GetGame().SurfaceIsSea( pos[0], pos[2] ) )
		{
			sound_set = GetEmptyingEndSoundsetWater();
		}
		
		return sound_set;
	}

	string GetPouringSoundset() {}
	
	string GetEmptyingLoopSoundsetHard() {};
	
	string GetEmptyingLoopSoundsetSoft() {};
	
	string GetEmptyingLoopSoundsetWater() {};
	
	string GetEmptyingEndSoundsetHard() {};
	
	string GetEmptyingEndSoundsetSoft() {};
	
	string GetEmptyingEndSoundsetWater() {};
	
	float GetLiquidEmptyRate()
	{
		return m_LiquidEmptyRate;
	}
	
	
		
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionWorldLiquidActionSwitch);
		AddAction(ActionFillFuel);
		AddAction(ActionFillCoolant);
		AddAction(ActionFillGeneratorTank);
		AddAction(ActionExtinguishFireplaceByLiquid);
		AddAction(ActionFillBottleBase);
		AddAction(ActionWaterGardenSlot);
		AddAction(ActionWaterPlant);
		AddAction(ActionForceDrink);
		AddAction(ActionPourLiquid);
		AddAction(ActionDrainLiquid);
		AddAction(ActionEmptyBottleBase);
		AddAction(ActionWashHandsItem);
		AddAction(ActionDrink);
	}
}
