//! Extended TriggerInsider for AreaDamageTriggerBase
class AreaDamageTriggerInsider : TriggerInsider
{
	//! Last time the object was damaged in seconds
	float lastDamaged;
	
	void AreaDamageTriggerInsider(Object obj)
	{
	}
}

//! Managed by AreaDamageManager and its derivatives
class AreaDamageTriggerBase : Trigger
{
	//! AreaDamageManager managing this instance
	protected ref AreaDamageManager		m_AreaDamageManager;
	
	#ifdef DEVELOPER
	private string 						m_DebugAreaType;
	#endif
	
	//! ctor
	void AreaDamageTriggerBase()
	{
		m_AreaDamageManager = null;
	}

	//! dtor
	void ~AreaDamageTriggerBase()
	{
		//! call Leave for all insiders when removing trigger
		int nr = m_insiders.Count();
		for (int n = 0; n < nr; ++n)
		{
			Object insObj = m_insiders[n].GetObject();
			if ( insObj )
				Leave(m_insiders[n]);
		}
		
		#ifdef DEVELOPER
		CleanupDebugShapes(dbgTargets);
		#endif
	}
	
	//! AreaDamageTriggerBase configuration
	//@{
	//! Set the manager instance
	void SetAreaDamageManager( AreaDamageManager adType )
	{
		m_AreaDamageManager = adType;
		
		#ifdef DEVELOPER
		m_DebugAreaType = m_AreaDamageManager.GetAmmoName();
		#endif
	}
	//@}
	
	
	//! TriggerEvents, pass them on to manager
	//@{
	//! OnEnter
	override protected void OnEnterBeginEvent(TriggerInsider insider)
	{
		super.OnEnterBeginEvent(insider);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnEnterBeginEvent(insider);
	}
	override protected void OnEnterServerEvent(TriggerInsider insider)
	{
		super.OnEnterServerEvent(insider);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnEnterServerEvent(insider);
	}
	override protected void OnEnterClientEvent(TriggerInsider insider)
	{
		super.OnEnterClientEvent(insider);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnEnterClientEvent(insider);
	}
	override protected void OnEnterEndEvent(TriggerInsider insider)
	{
		super.OnEnterEndEvent(insider);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnEnterEndEvent(insider);
	}

	//! OnStayStart
	override protected void OnStayStartBeginEvent(int nrOfInsiders)
	{
		super.OnStayStartBeginEvent(nrOfInsiders);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayStartBeginEvent(nrOfInsiders);
	}
	override protected void OnStayStartServerEvent(int nrOfInsiders)
	{
		super.OnStayStartServerEvent(nrOfInsiders);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayStartServerEvent(nrOfInsiders);
	}
	override protected void OnStayStartClientEvent(int nrOfInsiders)
	{
		super.OnStayStartClientEvent(nrOfInsiders);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayStartClientEvent(nrOfInsiders);
	}
	override protected void OnStayStartEndEvent(int nrOfInsiders)
	{
		super.OnStayStartEndEvent(nrOfInsiders);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayStartEndEvent(nrOfInsiders);
	}

	//!OnStay
	override protected void OnStayBeginEvent(TriggerInsider insider, float deltaTime)
	{
		super.OnStayBeginEvent(insider, deltaTime);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayBeginEvent(insider, deltaTime);
	}
	override protected void OnStayServerEvent(TriggerInsider insider, float deltaTime)
	{
		super.OnStayServerEvent(insider, deltaTime);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayServerEvent(insider, deltaTime);
	}
	override protected void OnStayClientEvent(TriggerInsider insider, float deltaTime)
	{
		super.OnStayClientEvent(insider, deltaTime);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayClientEvent(insider, deltaTime);
	}
	override protected void OnStayEndEvent(TriggerInsider insider, float deltaTime)
	{
		super.OnStayEndEvent(insider, deltaTime);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayEndEvent(insider, deltaTime);
	}

	//! OnStayFinish
	override protected void OnStayFinishBeginEvent()
	{
		super.OnStayFinishBeginEvent();
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayFinishBeginEvent();
	}
	override protected void OnStayFinishServerEvent()
	{
		super.OnStayFinishServerEvent();
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayFinishServerEvent();
	}
	override protected void OnStayFinishClientEvent()
	{
		super.OnStayFinishClientEvent();
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayFinishClientEvent();
	}
	override protected void OnStayFinishEndEvent()
	{
		super.OnStayFinishEndEvent();
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnStayFinishEndEvent();
	}
	
	//! OnLeave
	override protected void OnLeaveBeginEvent(TriggerInsider insider)
	{
		super.OnLeaveBeginEvent(insider);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnLeaveBeginEvent(insider);
	}
	override protected void OnLeaveServerEvent(TriggerInsider insider)
	{
		super.OnLeaveServerEvent(insider);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnLeaveServerEvent(insider);
	}
	override protected void OnLeaveClientEvent(TriggerInsider insider)
	{
		super.OnLeaveClientEvent(insider);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnLeaveClientEvent(insider);
	}
	override protected void OnLeaveEndEvent(TriggerInsider insider)
	{
		super.OnLeaveEndEvent(insider);
		
		if ( m_AreaDamageManager )
			m_AreaDamageManager.OnLeaveEndEvent(insider);
	}
	//@}
	
	
	//! TriggerInsider conditions
	//@{
	//! Condition whether a TriggerInsider should still be updated or not (checked in update loop and before adding)
	override protected bool ShouldRemoveInsider(TriggerInsider insider)
	{
		return !insider.GetObject().IsAlive();
	}
	//@}
	
	
	//! TriggerInsider processing
	//@{
	//! Override the TriggerInsider type to be AreaDamageTriggerInsider
	override protected TriggerInsider CreateInsider(Object obj)
	{
		return new AreaDamageTriggerInsider(obj);		
	}
	
	//! Adding of new TriggerInsider
	override protected void AddInsider(Object obj)
	{
		if ( !GetGame().IsServer() )
			return;
		
		super.AddInsider(obj);
		
		//!DEBUG
		#ifdef DEVELOPER
		DebugSendDmgTrigger();
		#endif
	}
	
	//! Removing of TriggerInsider
	override protected void RemoveInsider(TriggerInsider insider, int index = -1)
	{
		if ( !GetGame().IsServer() )
			return;
		
		super.RemoveInsider(insider, index);
		
		//!DEBUG
		#ifdef DEVELOPER
		DebugSendDmgTrigger();
		#endif
	}
	
	//! Update the current TriggerInsider inside the Trigger
	override protected void UpdateInsiders(int timeout)
	{
		if ( !GetGame().IsServer() )
			return;
	
		super.UpdateInsiders(timeout);

		//!DEBUG
		#ifdef DEVELOPER
		DebugSendDmgTrigger();
		#endif
	}
	//@}
	
	//! DEBUGGING
	//@{
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
	
#ifdef DEVELOPER
	
	void DebugSendDmgTrigger()
	{		
		vector minmax[2];
		GetCollisionBox(minmax);
		
		Param5<vector, vector, vector, string, array<ref TriggerInsider>> pos = new Param5<vector, vector, vector, string, array<ref TriggerInsider>>(vector.Zero, vector.Zero, vector.Zero, "", null);
		pos.param1 = minmax[0] + GetPosition();
		pos.param2 = minmax[1] + GetPosition();
		pos.param3 = m_AreaDamageManager.GetOrientation();
		pos.param4 = m_DebugAreaType;
		pos.param5 = m_insiders;
		
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
			GetGame().RPCSingleParam(this, ERPCs.RPC_AREADAMAGE_DEBUGAREA, pos, true);
		else
			DebugDmgTrigger( pos.param1, pos.param2, pos.param3, pos.param4, pos.param5 );
	}
	
	protected ref array<Shape> dbgTargets = new array<Shape>();
	
	void DebugDmgTrigger( vector pos1, vector pos2, vector orientation, string dmgType, array<ref TriggerInsider> insiders)
	{
		bool enableDebug = DiagMenu.GetBool(DiagMenuIDs.DM_SHOW_AREADMG_TRIGGER);
		if ( enableDebug )
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
			
			if ( GetGame().IsMultiplayer() )
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
	//@}
}