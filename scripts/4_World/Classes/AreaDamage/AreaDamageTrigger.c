class AreaDamageTrigger extends Trigger
{
	protected int				m_TriggerUpdateMs;
	protected vector			m_ExtentMin;
	protected vector			m_ExtentMax;
	
	protected AreaDamageBase	m_AreaDamageType;
	
	#ifdef DEVELOPER
	private string 				m_DebugAreaType;
	#endif
	
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
		if ( GetGame().IsServer() )
		{
			vector max = GetPosition() + m_ExtentMax;
			vector min = GetPosition() + m_ExtentMin;
			
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
				if ( insObj && ( !insObj.IsAlive() || vector.DistanceSq(insObj.GetPosition(), GetPosition()) > (innerDist * innerDist) ) )
				{
					int timeDiff = g_Game.GetTime() - ins.timeStamp;
					if (timeDiff > 500)
					{
						//object left. Remove it
						OnLeave(ins.GetObject());
						m_insiders.Remove(n);
						
						continue;
					}
					else
					{
						//Print("" + this + " :: " + insObj + " :: " + timeDiff);
					}
				}
				n++;
			}
			
			//!DEBUG
			#ifdef DEVELOPER
			Param5<vector, vector, vector, string, array<ref TriggerInsider>> pos = new Param5<vector, vector, vector, string, array<ref TriggerInsider>>(vector.Zero, vector.Zero, vector.Zero, "", null);
			pos.param1 = min;
			pos.param2 = max;
			pos.param3 = m_AreaDamageType.GetOrientation();
			pos.param4 = m_DebugAreaType;
			pos.param5 = m_insiders;
			GetGame().RPCSingleParam(this, ERPCs.RPC_AREADAMAGE_DEBUGAREA, pos, true);
			#endif
		}
	}
	
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{	
		super.OnRPC(sender, rpc_type, ctx);
		#ifdef DEVELOPER
		switch ( rpc_type )
		{
			case ERPCs.RPC_AREADAMAGE_DEBUGAREA:
				Param5<vector, vector, vector, string, array<ref TriggerInsider>> pos = new Param5<vector, vector, vector, string, array<ref TriggerInsider>>(vector.Zero, vector.Zero, vector.Zero, "", null);
				if ( ctx.Read( pos ) )
				{
					DebugDmgTrigger( pos.param1, pos.param2, pos.param3, pos.param4, pos.param5 );
				}
			break;
		}
		#endif
	}

	override void AddInsider(Object obj)
	{
		if ( !GetGame().IsServer() )
		{
			return;
		}
		
		TriggerInsider ins;
		if ( obj )
		{
			for ( int n = 0; n < m_insiders.Count(); n++ )
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

	override void SetExtents( vector mins, vector maxs )
	{
		m_ExtentMax = maxs;
		m_ExtentMin = mins;

		super.SetExtents(mins, maxs);
	}
	
	override void OnEnter( Object obj )
	{
		super.OnEnter( obj );
		
		//Print(this);
		if ( GetGame().IsServer() )
		{
			//obj.OnAreaDamageEnter();

			if ( m_AreaDamageType )
			{
			 	m_AreaDamageType.OnEnter( obj );
				//Print("On Enter called!");
			}
		}
	}
	
	override void OnLeave( Object obj )
	{
		super.OnLeave( obj );
		//Print(this);

		if ( GetGame().IsServer() )
		{
			//obj.OnAreaDamageLeave();

			if ( m_AreaDamageType )
			{
				m_AreaDamageType.OnLeave( obj );
			}
		}
	}
	
	void SetAreaDamageType( AreaDamageBase adType )
	{
		m_AreaDamageType = adType;
		
		#ifdef DEVELOPER
		m_DebugAreaType = m_AreaDamageType.GetAmmoName();
		#endif
	}
	
#ifdef DEVELOPER
	
	protected ref array<Shape> dbgTargets = new array<Shape>();
	
	void DebugDmgTrigger( vector pos1, vector pos2, vector orientation, string dmgType, array<ref TriggerInsider> insiders)
	{
		bool showSpheres = DiagMenu.GetBool(DiagMenuIDs.DM_SHOW_AREADMG_TRIGGER);
		if ( showSpheres )
		{
			if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
			{
				return;
			}
			
			vector w_pos, w_pos_sphr, w_pos_lend;
	
			CleanupDebugShapes( dbgTargets );
	
			w_pos = this.GetPosition();
			// sphere pos tweaks
			w_pos_sphr = w_pos;
			// line pos tweaks
			w_pos_lend = w_pos;
			
			//Find way to change colour of box depending on ammoType in a more elegant fashion
			m_DebugAreaType = dmgType;
			Shape dbgShape;
			vector pos = GetWorldPosition();
			vector mat[4];
			
			switch ( m_DebugAreaType )
			{
				case "FireDamage":
					dbgShape = Debug.DrawBox(pos1 - pos, pos2 - pos, COLOR_RED_A);
				
					GetTransform( mat );
					dbgShape.CreateMatrix( mat );
					dbgShape.SetMatrix(mat);
				
					dbgTargets.Insert( dbgShape );
				break;
				
				case "BarbedWireHit":
					dbgShape = Debug.DrawBox(pos1 - pos, pos2 - pos, COLOR_BLUE_A);
					
					GetTransform( mat );
					dbgShape.CreateMatrix( mat );
					dbgShape.SetMatrix(mat);
				
					dbgTargets.Insert( dbgShape );
				break;
				
				default:
					dbgShape = Debug.DrawBox(pos1 - pos, pos2 - pos, COLOR_GREEN_A);
					
					GetTransform( mat );
					dbgShape.CreateMatrix( mat );
					dbgShape.SetMatrix(mat);
				
					dbgTargets.Insert( dbgShape );
				break;
			}
			
			m_insiders = insiders;
		
			if ( m_insiders.Count() > 0 )
			{
				//Change colour to make state clearer
				dbgShape.SetColor( COLOR_YELLOW_A );
				
				for ( int i = 0; i < m_insiders.Count(); i++ )
				{
					EntityAI insider_EAI = EntityAI.Cast( m_insiders[i].GetObject() );
					if ( insider_EAI )
					{
						vector insiderPos = insider_EAI.GetPosition() + "0 0.1 0";
						
						dbgTargets.Insert( Debug.DrawArrow( w_pos, insiderPos ) );
					}
				}
			}
		}
		else
			CleanupDebugShapes( dbgTargets );
	}
	
	protected void CleanupDebugShapes( array<Shape> shapes )
	{
		for ( int it = 0; it < shapes.Count(); ++it )
		{
			Debug.RemoveShape( shapes[it] );
		}

		shapes.Clear();
	}
	
#endif
}