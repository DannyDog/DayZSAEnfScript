//! Trigger used by traps
class TrapTrigger : Trigger
{
	TrapBase m_ParentObj;
	
	void SetParentObject( TrapBase obj )
	{
		if ( GetGame().IsServer() )
			m_ParentObj = obj;
	}
	
	override protected bool CanAddObjectAsInsider(Object object)
	{
		return object.IsInherited(EntityAI) && m_ParentObj && m_ParentObj.IsActive();
	}

	override protected void OnEnterServerEvent(TriggerInsider insider)
	{
		if ( m_ParentObj && m_ParentObj.IsActive() )
			m_ParentObj.SnapOnObject(EntityAI.Cast( insider.GetObject() ));
	}
}