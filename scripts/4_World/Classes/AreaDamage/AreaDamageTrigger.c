class AreaDamageTrigger extends Trigger
{
	protected int				m_TriggerUpdateMs;
	protected vector			m_ExtentMin;
	protected vector			m_ExtentMax;
	
	protected AreaDamageBase	m_AreaDamageType;
	
	void AreaDamageTrigger()
	{
		m_TriggerUpdateMs = 100;
		m_AreaDamageType = null;
	}

	void ~AreaDamageTrigger()
	{
		//! call OnLeave for all insiders when removing trigger
		for (int n = 0; n < m_insiders.Count(); )
		{
			TriggerInsider ins = m_insiders.Get(n);
			Object insObj = ins.GetObject();
			if ( insObj )
			{
				//object left. Remove it
				OnLeave(insObj);
				m_insiders.Remove(n);
				continue;
			}
			 
			n++;
		}
	}
	
	override protected void UpdateInsiders(int timeout)
	{
		if (!GetGame().IsServer())
		{
			return;
		}
		
		vector max = GetPosition() + m_ExtentMax;
		vector min = GetPosition() + m_ExtentMin;
		
		//!DEBUG
		#ifdef DEVELOPER
		this.Debug(min, max);
		#endif
		
		for (int n = 0; n < m_insiders.Count(); )
		{
			TriggerInsider ins = m_insiders.Get(n);
			if ( ins.GetObject() == null )
			{
				//object has been deleted. Remove it
				m_insiders.Remove(n);
				continue;
			}

			Object insObj = ins.GetObject();
			float innerDist = (GetRadius(m_ExtentMin, m_ExtentMax) * 0.5) + 0.2;
			if ( insObj && vector.DistanceSq(insObj.GetPosition(), GetPosition()) > (innerDist * innerDist) )
			{
				if (g_Game.GetTime() - ins.timeStamp > 500)
				{
					//object left. Remove it
					OnLeave(ins.GetObject());
					m_insiders.Remove(n);
					continue;
				}
			}
			 
			n++;
		}
	}

	override void AddInsider(Object obj)
	{
		if (!GetGame().IsServer())
		{
			return;
		}
		
		TriggerInsider ins;
		if ( obj )
		{
			for (int n = 0; n < m_insiders.Count(); n++)
			{
				ins = m_insiders.Get(n);
				//already in?
				if ( obj && ins.GetObject() == obj )
				{
					//just update timestamp
					//Print("Already in");
					ins.timeStamp = g_Game.GetTime();
					return;
				}
			}
	
			ins = new TriggerInsider(obj);
			ins.timeStamp = g_Game.GetTime();
			m_insiders.Insert(ins);
			OnEnter(obj);
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
			//obj.OnAreaDamageEnter();

			if ( m_AreaDamageType )
			{
			 	m_AreaDamageType.OnEnter(obj);
				//Print("On Enter called!");
			}
		}
	}
	
	override void OnLeave(Object obj)
	{
		super.OnLeave( obj );

		if ( GetGame().IsServer() )
		{
			//obj.OnAreaDamageLeave();

			if ( m_AreaDamageType )
			{
				
				PrintToRPT("[DAMAGE TRIGGER LEAVE] " + this + " The following Object left : " + obj); 
		 		m_AreaDamageType.OnLeave(obj);
				//Print("On Leave called!");
			}
		}
	}
	
	void SetAreaDamageType(AreaDamageBase adType)
	{
		m_AreaDamageType = adType;
	}
	
#ifdef DEVELOPER
	
	protected ref array<Shape> dbgTargets = new array<Shape>();
	
	void Debug(vector pos1, vector pos2)
	{
		bool showSpheres = DiagMenu.GetBool(DiagMenuIDs.DM_SHOW_AREADMG_TRIGGER);
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
				
				dbgTargets.Insert( Debug.DrawBox(pos1, pos2, COLOR_GREEN_A));
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