/*
	Author: Boris Vacula
	For documentation go to: DayZ Confluence -> How-to articles -> Weapon muzzle flash particle system configuration
	This system plays effect(s) on any weapon that is fired/jammed/ruined/...
*/

class WeaponParticlesBase // This class represents every particle effect you see in config within OnFire or OnOverheating events
{
	bool			m_IlluminateWorld;
	bool			m_IgnoreIfSuppressed;
	bool			m_OnlyIfBoltIsOpen;
	int 			m_MuzzleIndex;
	int 			m_OverrideParticle;
	int 			m_OnlyWithinHealthLabelMin;
	int 			m_OnlyWithinHealthLabelMax;
	float 			m_OnlyWithinOverheatLimitsMin;
	float			m_OnlyWithinOverheatLimitsMax;
	float 			m_OnlyWithinRainLimitsMin;
	float			m_OnlyWithinRainLimitsMax;
	string 			m_OverrideDirectionPoint;
	string 			m_OnlyIfBulletIs;
	string 			m_OnlyIfWeaponIs;
	string 			m_OverridePoint;
	vector 			m_OverrideDirectionVector;
	vector 			m_PositionOffset;
	
	//======================================
	//  		PRELOAD EVERYTHING
	//======================================
	
	void WeaponParticlesBase(ItemBase muzzle_owner, string config_OnFire_entry)
	{
		// ignoreIfSuppressed
		m_IgnoreIfSuppressed = GetGame().ConfigGetFloat(config_OnFire_entry + " " + "ignoreIfSuppressed");
		
		// onlyIfBoltIsOpen
		m_OnlyIfBoltIsOpen = GetGame().ConfigGetFloat(config_OnFire_entry + " " + "onlyIfBoltIsOpen");
		
		// illuminateWorld
		m_IlluminateWorld = GetGame().ConfigGetFloat(config_OnFire_entry + " " + "illuminateWorld");
		
		m_MuzzleIndex = -1;
		if(GetGame().ConfigIsExisting(config_OnFire_entry + " " + "muzzleIndex"))
		{
			m_MuzzleIndex = GetGame().ConfigGetInt(config_OnFire_entry + " " + "muzzleIndex");
		}
		
		// onlyIfWeaponIs
		m_OnlyIfWeaponIs = "";
		GetGame().ConfigGetText( config_OnFire_entry + " onlyIfWeaponIs", m_OnlyIfWeaponIs);
		
		// onlyIfBulletIs
		m_OnlyIfBulletIs = "";
		GetGame().ConfigGetText( config_OnFire_entry + " onlyIfBulletIs", m_OnlyIfBulletIs);
		
		// onlyWithinHealthLabel[]
		array<float> health_limit = new array<float>;
		GetGame().ConfigGetFloatArray( config_OnFire_entry + " onlyWithinHealthLabel", health_limit);
		
		if (health_limit.Count() == 2)
		{
			m_OnlyWithinHealthLabelMin = health_limit.Get(0);
			m_OnlyWithinHealthLabelMax = health_limit.Get(1);
		}
		else
		{
			// Disable this filter
			m_OnlyWithinHealthLabelMin = -1;
			m_OnlyWithinHealthLabelMax = 99;
		}
		
		health_limit.Clear();
		delete health_limit;
		
		// onlyWithinOverheatLimits[]
		array<float> overheat_limit = new array<float>;
		GetGame().ConfigGetFloatArray( config_OnFire_entry + " onlyWithinOverheatLimits", overheat_limit);
		
		if (overheat_limit.Count() == 2)
		{
			m_OnlyWithinOverheatLimitsMin = overheat_limit.Get(0);
			m_OnlyWithinOverheatLimitsMax = overheat_limit.Get(1);
		}
		else
		{
			// Disable this filter
			m_OnlyWithinOverheatLimitsMin = -1;
			m_OnlyWithinOverheatLimitsMax = 2;
		}
		
		overheat_limit.Clear();
		delete overheat_limit;
		
		// onlyWithinRainLimits[]
		array<float> rain_limit = new array<float>;
		GetGame().ConfigGetFloatArray( config_OnFire_entry + " onlyWithinRainLimits", rain_limit);
		
		if (rain_limit.Count() == 2)
		{
			m_OnlyWithinRainLimitsMin = rain_limit.Get(0);
			m_OnlyWithinRainLimitsMax = rain_limit.Get(1);
		}
		else
		{
			// Disable this filter
			m_OnlyWithinRainLimitsMin = -1;
			m_OnlyWithinRainLimitsMax = 2;
		}
		
		rain_limit.Clear();
		delete rain_limit;
		
		// overridePoint
		m_OverridePoint = "";
		GetGame().ConfigGetText(config_OnFire_entry + " " + "overridePoint", m_OverridePoint);
		
		if (m_OverridePoint == "")
			m_OverridePoint = "Usti hlavne"; // default memory point name
		
		// overrideParticle
		string particle_name = "";
		GetGame().ConfigGetText( config_OnFire_entry + " overrideParticle" , particle_name);
		
		if (particle_name != "")
		{
			string path = ParticleList.GetPathToParticles();
			m_OverrideParticle = ParticleList.GetParticleID(path + particle_name);
		}
		else
		{
			m_OverrideParticle = -1;
		}
		
		// overrideDirectionPoint
		m_OverrideDirectionPoint = "";
		GetGame().ConfigGetText( config_OnFire_entry + " overrideDirectionPoint" , m_OverrideDirectionPoint);
		
		if (m_OverrideDirectionPoint == "")
		{
			// overrideDirectionVector
			vector test_ori = GetGame().ConfigGetVector( config_OnFire_entry + " overrideDirectionVector");
			
			if (test_ori != Vector(0, 0, 0))
			{
				m_OverrideDirectionVector = test_ori;
			}
		}
		
		// positionOffset[]
		array<float> v = new array<float>;
		GetGame().ConfigGetFloatArray( config_OnFire_entry + " positionOffset" , v);
		
		if (v.Count() == 3)
		{
			float v1 = v.Get(0);
			float v2 = v.Get(1);
			float v3 = v.Get(2);
			m_PositionOffset = Vector(v1, v2, v3);
		}
	}
	
	
	
	//======================================
	//			  PLAY PARTICLES
	//======================================
	// It is important to know that this block of script is called for weapons and muzzle attachments alike.
	// Thus weapon == muzzle_owner when this is called for a weapon, and weapon != muzzle_owner when this is called for a suppressor.
	void OnActivate(ItemBase weapon, int muzzle_index, string ammoType, ItemBase muzzle_owner, ItemBase suppressor, string config_to_search)
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
			// Handle effect's parameters
			if ( PrtTest.m_GunParticlesState ) // Check if particles are enabled by debug
			{
				if ( m_MuzzleIndex == -1 || m_MuzzleIndex == muzzle_index )
				{
					if ( CheckBoltStateCondition(weapon) ) // onlyIfBoltIsOpen
					{
						if ( !suppressor  ||  !(m_IgnoreIfSuppressed) ) // ignoreIfSuppressed
						{
							if ( CheckHealthCondition( muzzle_owner.GetHealthLevel() ) ) // onlyWithinHealthLabel
							{
								if (CheckOverheatingCondition( muzzle_owner.GetOverheatingCoef() ) ) // onlyWithinOverheatLimits
								{
									if (CheckRainCondition( GetGame().GetWeather().GetRain().GetActual() ) ) // onlyWithinRainLimits
									{
										if ( m_OnlyIfBulletIs == ""  ||  m_OnlyIfBulletIs == ammoType ) // onlyIfBulletIs
										{
											if ( m_OnlyIfWeaponIs == ""  ||  m_OnlyIfWeaponIs == weapon.GetType() ) // onlyIfWeaponIs
											{
												// Get particle ID
												int particle_id = CheckParticleOverride(ammoType);
											
												// Get position of the particle
												vector local_pos = muzzle_owner.GetSelectionPositionLS(m_OverridePoint);
												local_pos += m_PositionOffset;
											
												// Set orientation of the particle
												vector particle_ori = CheckOrientationOverride(local_pos, muzzle_owner);
											
												Particle p = Particle.PlayOnObject( particle_id, muzzle_owner, local_pos, particle_ori );
											
												OnParticleCreated(weapon, ammoType, muzzle_owner, suppressor, config_to_search, p);
											
												if (m_IlluminateWorld)
												{
													vector global_pos = muzzle_owner.ModelToWorld(local_pos + Vector(-0.2, 0, 0));
													ScriptedLightBase.CreateLight(MuzzleFlashLight, global_pos);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	void OnParticleCreated(ItemBase weapon, string ammoType, ItemBase muzzle_owner, ItemBase suppressor, string config_to_search, Particle p)
	{
		
	}
	
	void OnDeactivate(ItemBase weapon, string ammoType, ItemBase muzzle_owner, ItemBase suppressor, string config_to_search)
	{
		
	}
	
	void OnUpdate(ItemBase weapon, string ammoType, ItemBase muzzle_owner, ItemBase suppressor, string config_to_search)
	{
		
	}
	
	
	//==============================================
	//  		 HANDLE CONFIG PARAMETERS          
	//==============================================
	
	
	// OnlyWithinHealthLabelMin & OnlyWithinHealthLabelMax
	bool CheckBoltStateCondition(ItemBase weapon)
	{
		if ( m_OnlyIfBoltIsOpen )
		{
			Weapon_Base wb = Weapon_Base.Cast( weapon );
			WeaponStateBase current_state =  wb.GetCurrentState();
			return current_state.IsBoltOpen();
		}
		
		return true;
	}
	
	// OnlyWithinHealthLabelMin & OnlyWithinHealthLabelMax
	bool CheckHealthCondition(int health_label)
	{
		if ( (health_label >= m_OnlyWithinHealthLabelMin)  &&  (health_label <= m_OnlyWithinHealthLabelMax) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	// OnlyWithinOverheatLimitsMin & OnlyWithinOverheatLimitsMax
	bool CheckOverheatingCondition(float overheating_coef)
	{
		if ( (overheating_coef >= m_OnlyWithinOverheatLimitsMin)  &&  (overheating_coef <= m_OnlyWithinOverheatLimitsMax) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	// OnlyWithinRainLimitsMin & OnlyWithinRainLimitsMax
	bool CheckRainCondition(float rain_coef)
	{
		if ( (rain_coef >= m_OnlyWithinRainLimitsMin)  &&  (rain_coef <= m_OnlyWithinRainLimitsMax) )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	// muzzleFlashParticle
	int CheckParticleOverride(string ammoType)
	{
		int particle_id = -1;
		
		string particle_file = "";
		string cfg_path = "CfgAmmo " + ammoType + " muzzleFlashParticle";
		if (GetGame().ConfigGetText( cfg_path, particle_file))
			particle_id = ParticleList.GetParticleID( ParticleList.GetPathToParticles() + particle_file);
		
		// Config is accessed only once because the data is saved into a map for repeated access.
		
		if ( particle_id > 0 || m_OverrideParticle == -1)
		{
			if (particle_file == "")
			{
				string ammo_particle_error = "ERROR! Cannot spawn particle effect because item " + ammoType + " is missing config parameter muzzleFlashParticle!";
				DPrint(ammo_particle_error);
			}
			else
			{
				particle_id = ParticleList.GetParticleID( ParticleList.GetPathToParticles() + particle_file);
				
				if (particle_id == 0)
				{
					string err = "Error! Cannot play particle effect with name " + particle_file + " because no such file is registered in ParticleList.c! Make sure it's registered there and then rebuild Scripts and Graphics PBOs.";
					Error(err);
					m_OverrideParticle = particle_id; // Prevents another appearence of the above error.
				}
			}
		}
		else
		{
			particle_id = m_OverrideParticle;
		}
		
		return particle_id;
	}
	
	// OverrideDirectionPoint & OverrideDirectionVector
	vector CheckOrientationOverride(vector local_pos, ItemBase muzzle_owner)
	{
		vector particle_ori = "0 0 0";
		if (m_OverrideDirectionPoint != "")
		{
			vector target_pos = muzzle_owner.GetSelectionPositionLS(m_OverrideDirectionPoint);
			target_pos = vector.Direction(local_pos, target_pos);
			particle_ori = target_pos.VectorToAngles();
		}
		else
		{
			if (m_OverrideDirectionVector != Vector(0, 0, 0))
			{
				particle_ori = m_OverrideDirectionVector;
			}
			
			if (muzzle_owner.IsInherited(ItemSuppressor))
			{
				particle_ori = particle_ori + Vector(0,0,270); // This rotation is necesarry due to suppressors being rotated into ground in their p3d files
			}
		}
		
		return particle_ori;
	}
}

// FIRE particles
class WeaponParticlesOnFire : WeaponParticlesBase {}

// BULLET EJECT particles
class WeaponParticlesOnBulletCasingEject : WeaponParticlesBase {}

// OVERHEATING particles
class WeaponParticlesOnOverheating: WeaponParticlesBase
{
	override void OnParticleCreated(ItemBase weapon, string ammoType, ItemBase muzzle_owner, ItemBase suppressor, string config_to_search, Particle p)
	{
		muzzle_owner.RegisterOverheatingParticle(p, m_OnlyWithinOverheatLimitsMin, m_OnlyWithinOverheatLimitsMax, p.GetParticleID(), muzzle_owner, p.m_DefaultPos, p.m_DefaultOri );
	}
	
	override void OnDeactivate(ItemBase weapon, string ammoType, ItemBase muzzle_owner, ItemBase suppressor, string config_to_search)
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
			weapon.KillAllOverheatingParticles();
		}
	}
	
	override void OnUpdate(ItemBase weapon, string ammoType, ItemBase muzzle_owner, ItemBase suppressor, string config_to_search)
	{
		OnActivate(weapon, 0, ammoType, muzzle_owner, suppressor, config_to_search);
	}
}

class OverheatingParticle
{
	Particle 	m_Particle;
	int 		m_ParticleID;
	Object 		m_Parent;
	vector		m_LocalPos;
	vector		m_LocalOri;
	
	float m_OverheatingLimitMin;
	float m_OverheatingLimitMax;
	
	void RegisterParticle( Particle p)
	{
		m_Particle = p;
	}
	
	Particle GetParticle()
	{
		return m_Particle;
	}
	
	void SetOverheatingLimitMin(float min)
	{
		m_OverheatingLimitMin = min;
	}
	
	void SetOverheatingLimitMax(float max)
	{
		m_OverheatingLimitMax = max;
	}
	
	float GetOverheatingLimitMin()
	{
		return m_OverheatingLimitMin;
	}
	
	float GetOverheatingLimitMax()
	{
		return m_OverheatingLimitMax;
	}
	
	void SetParticleParams(int particle_id, Object parent, vector local_pos, vector local_ori)
	{
		m_ParticleID = particle_id;
		m_Parent = parent;
		m_LocalPos = local_pos;
		m_LocalOri = local_ori;
	}
	
	int GetParticleID()
	{
		return m_ParticleID;
	}
	
	Object GetParticleParent()
	{
		return m_Parent;
	}
	
	vector GetParticlePos()
	{
		return m_LocalPos;
	}
	
	vector GetParticleOri()
	{
		return m_LocalOri;
	}
}