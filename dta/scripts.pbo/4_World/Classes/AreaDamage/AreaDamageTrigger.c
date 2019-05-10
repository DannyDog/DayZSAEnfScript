class AreaDamageTrigger extends Trigger
{
	protected EntityAI	  		m_AreaTriggerParent;
	protected AreaDamageType	m_AreaDamageType;

	protected bool				m_Looping;
	protected bool				m_Raycasted;
	
	protected int				m_TriggerUpdateMs;
	protected float				m_LoopingInterval;
	protected float 			m_DeferredInterval;
	
	protected vector			m_ExtentMin;
	protected vector			m_ExtentMax;

	protected ref array<string>	m_HitZones;
	protected ref array<string> m_RaycastSources;
	protected string			m_AmmoName;
	protected int				m_DamageType			//!< DT_CUSTOM (Damage Type)
	
	protected ref Timer			m_LoopTimer;
	protected ref Timer			m_DeferTimer;

	void AreaDamageTrigger()
	{
		m_Looping 			= false;
		m_Raycasted			= false;
		m_LoopingInterval 	= 0.1;
		m_DeferredInterval 	= 0.1;
		m_TriggerUpdateMs   = 100; 
		m_AreaDamageType 	= AreaDamageType.REGULAR;
		m_HitZones			= new array<string>;
		m_HitZones.Insert("Head");
		m_RaycastSources	= new array<string>;
		m_RaycastSources 	= {"0.0 0.1 0.0", "0.2 0.1 0.2", "-.2 0.1 0.2", "0.2 0.1 -.2", "-.2 0.1 -.2"};

		m_AmmoName 			= "MeleeDamage";
		m_DamageType		= 3;

		// start main timer
		m_LoopTimer 		= new Timer(CALL_CATEGORY_SYSTEM);
		m_DeferTimer 		= new Timer(CALL_CATEGORY_SYSTEM);
	}

	void ~AreaDamageTrigger() {}
	
	// Sets parent object for this trigger
	void SetParentObject(EntityAI parent)
	{
		if ( GetGame().IsServer() )
		{
			m_AreaTriggerParent = parent;
		}
	}
	
	EntityAI GetParentObject()
	{
		return m_AreaTriggerParent;
	}
	
	void SetAreaDamageType(int area_dmg_type )
	{
		AreaDamageSelector(area_dmg_type);
	}
	
	void SetLoopTime(float time)
	{
		m_LoopingInterval = time;
	}
	
	void SetDeferTime(float time)
	{
		m_DeferredInterval = time;
	}
	
	void SetRaycastSources(array<string> raycast_sources)
	{
		m_RaycastSources = raycast_sources;
	}
	
	void SetHitZones(array<string> hitzones)
	{
		m_HitZones = hitzones;
	}

	void SetAmmoName(string ammo_name)
	{
		m_AmmoName = ammo_name;
	}
	
	void SetDamageType(int pDamageType)
	{
		m_DamageType = pDamageType;
	}
	
	protected void PreDamageActions()
	{
		if ( m_AreaTriggerParent )
		{
			m_AreaTriggerParent.PreAreaDamageActions();
		}
	}

	protected void PostDamageActions()
	{
		if ( m_AreaTriggerParent )
		{
			m_AreaTriggerParent.PostAreaDamageActions();
		}
	}

	override protected void UpdateInsiders(int timeout)
	{
		vector max = GetPosition() + m_ExtentMax;
		vector min = GetPosition() + m_ExtentMin;
		
		for(int n = 0; n < m_insiders.Count(); )
		{
			TriggerInsider ins = m_insiders.Get(n);
			if(ins.insider == null)
			{
				//object has been deleted. Remove it
				m_insiders.Remove(n);
				continue;
			}

			Object insObj = ins.GetObject();
			if(insObj && vector.Distance(insObj.GetPosition(), GetPosition()) > GetRadius(m_ExtentMin, m_ExtentMax)/2)
			{
				//object left. Remove it
				OnLeave(ins.insider.Ptr());
				m_insiders.Remove(n);
				continue;
			}
			 
			n++;			
		}
	}
	
	override void SetExtents(vector mins, vector maxs)
	{
		m_ExtentMax = maxs;
		m_ExtentMin = mins;

		super.SetExtents(mins, maxs);
	}
	
	override void OnEnter( Object obj )
	{
		super.OnEnter( obj );

		if ( GetGame().IsServer() )
		{
			EntityAI victim;
			Class.CastTo(victim, obj);

			// Run timer for non-deferred AreaDamageTypes only
			if ( m_AreaDamageType == AreaDamageType.REGULAR || m_AreaDamageType == AreaDamageType.REGULAR_RAYCASTED || m_AreaDamageType == AreaDamageType.ONETIME || m_AreaDamageType == AreaDamageType.ONETIME_RAYCASTED)
			{
				PreDamageActions();
				m_LoopTimer.Run( m_LoopingInterval, this, "SnapOnObject", new Param1<EntityAI>(victim), m_Looping );
			}

			// Run timer for deferred AreaDamageTypes only
			if ( m_AreaDamageType == AreaDamageType.REGULAR_DEFERRED || m_AreaDamageType == AreaDamageType.REGULAR_RAYCASTED_DEFERRED || m_AreaDamageType == AreaDamageType.ONETIME_DEFERRED || m_AreaDamageType == AreaDamageType.ONETIME_RAYCASTED_DEFERRED )
			{
				PreDamageActions();
				m_DeferTimer.Run( m_DeferredInterval, this, "LoopTimer", new Param1<EntityAI>(victim), false );
			}
		}
	}
	
	override void OnLeave(Object obj)
	{
		super.OnLeave( obj );

		//! stop all running timers
		if ( m_DeferTimer && m_DeferTimer.IsRunning() )
		{
			m_DeferTimer.Stop();
		}
		if ( m_LoopTimer && m_LoopTimer.IsRunning() )
		{
			m_LoopTimer.Stop();
		}
	}
	
	protected string GetRandomHitZone(array<string> hitzones)
	{
		string hitzone;
		Math.Randomize(-1);
		int idx = Math.RandomInt( 0, 100 ) % hitzones.Count();
		hitzone = hitzones[idx];

		return hitzone;
	}
	
	protected string GetRaycastedHitZone(EntityAI victim, array<string> raycast_sources_str)
	{
		
		// Vertical raycast start positions:    Center,      North East,    North West,    South East,  South West
		//vector raycast_sources[5] = {"0.0 0.1 0.0", "0.2 0.1 0.2", "-.2 0.1 0.2", "0.2 0.1 -.2", "-.2 0.1 -.2"};
		
		string hitzone;
		vector contact_pos;
		vector contact_dir;
		int contactComponent;
		bool isSteppedOn = false;
		
		ref set<Object> victims = new set<Object>;
		
		array<vector> raycast_sources = new TVectorArray;

		// convert Array of string to array of Vectors
		for ( int v = 0; v < raycast_sources_str.Count(); ++v)
		{
			raycast_sources.Insert(raycast_sources_str[v].ToVector());
		}
		
		for ( int i = 0; i < raycast_sources.Count(); ++i )
		{
			vector raycast_start_pos = ModelToWorld( raycast_sources.Get(i) );
			vector raycast_end_pos = "0 0.5 0" + raycast_start_pos;
			
			//#ifdef DEVELOPER
			//Debug.DrawArrow( raycast_start_pos, raycast_end_pos );
			//#endif
			DayZPhysics.RaycastRV( raycast_start_pos, raycast_end_pos, contact_pos, contact_dir, contactComponent, victims , null, this, true, false, ObjIntersectIFire);
			
			for ( int j = 0; j < victims.Count(); ++j )
			{
				Object contact_obj = victims.Get(j);
				
				if ( contact_obj.IsInherited(Man) )
				{
					isSteppedOn = true;
					break;
				}
			}
			
			if (isSteppedOn)
			{
				hitzone = victim.GetDamageZoneNameByComponentIndex(contactComponent);
				break;
			}
		}
		
		if(isSteppedOn)
		{
			return hitzone;
		}
		else
		{
			// Damage random leg since we don't know what part of player's body was caught in the trap.
			string dmg_zone_rnd = "LeftFoot";
			if ( Math.RandomIntInclusive(0, 1) == 1 )
				dmg_zone_rnd = "RightFoot";
			return dmg_zone_rnd;
		}
	}

	//! just for running Loop timer throught Defer timer
	protected void LoopTimer(EntityAI victim)
	{
		m_LoopTimer.Run( m_LoopingInterval, this, "SnapOnObject", new Param1<EntityAI>(victim), m_Looping );
	}
	
	protected void SnapOnObject( EntityAI victim )
	{
		if (victim && victim.IsAlive())
		{
			string hitzone;

			if ( !m_Raycasted )
			{
				hitzone = GetRandomHitZone(m_HitZones);
			}
			else
			{
				hitzone = GetRaycastedHitZone( victim, m_RaycastSources );
			}
			
			//! TODO: should be configurable while creating area damage - array of types
			if ( victim.IsInherited(Man) )
			{
				victim.ProcessDirectDamage(m_DamageType, EntityAI.Cast(this), hitzone, m_AmmoName, "0.5 0.5 0.5", 1);
				PostDamageActions();
			}
		}
	}
	
	protected void AreaDamageSelector(int area_dmg_type)
	{
		m_AreaDamageType = area_dmg_type;
		switch(area_dmg_type)
		{
		case AreaDamageType.REGULAR:
			m_Looping = true;
			m_Raycasted = false;
		break;
		case AreaDamageType.REGULAR_DEFERRED:
			m_Looping = true;
			m_Raycasted = false;
		break;
		case AreaDamageType.REGULAR_RAYCASTED:
			m_Looping = true;
			m_Raycasted = true;
		break;
		case AreaDamageType.REGULAR_RAYCASTED_DEFERRED:
			m_Looping = true;
			m_Raycasted = true;
		break;
		case AreaDamageType.ONETIME:
			m_Looping = false;
			m_Raycasted = false;
		break;
		case AreaDamageType.ONETIME_DEFERRED:
			m_Looping = false;
			m_Raycasted = false;
		break;
		case AreaDamageType.ONETIME_RAYCASTED:
			m_Looping = false;
			m_Raycasted = true;
		break;
		case AreaDamageType.ONETIME_RAYCASTED_DEFERRED:
			m_Looping = false;
			m_Raycasted = true;
		break;
		}
	}
}