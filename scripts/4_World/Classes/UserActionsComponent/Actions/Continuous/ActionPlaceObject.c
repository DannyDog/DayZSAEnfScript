class ActionPlaceObjectCB : ActiondeployObjectCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_PLACE);
	}
	
	override void DropDuringPlacing()
	{
		EntityAI entity_for_placing = m_ActionData.m_MainItem;	
		vector orientation = m_ActionData.m_Player.GetLocalProjectionOrientation();
		vector position = m_ActionData.m_Player.GetLocalProjectionPosition();
		vector rotation_matrix[3];
		float direction[4];
		InventoryLocation source = new InventoryLocation;
		InventoryLocation destination = new InventoryLocation;
		
		Math3D.YawPitchRollMatrix( orientation, rotation_matrix );
		Math3D.MatrixToQuat( rotation_matrix, direction );
	
		if ( entity_for_placing.GetInventory().GetCurrentInventoryLocation( source ) )
		{
			destination.SetGroundEx( entity_for_placing, position, direction );
			m_ActionData.m_Player.PredictiveTakeToDst(source, destination);
		}
	}
};

class ActionPlaceObject: ActionDeployObject
{		
	void ActionPlaceObject()
	{
		m_CallbackClass	= ActionPlaceObjectCB;
	}

	override bool HasProgress()
	{
		return false;
	}
	
	override string GetText()
	{
		return "#place_object";
	}
};
