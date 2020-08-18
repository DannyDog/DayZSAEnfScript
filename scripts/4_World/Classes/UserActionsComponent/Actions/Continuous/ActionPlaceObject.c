class ActionPlaceObjectCB : ActiondeployObjectCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_PLACE);
	}
	
	override void DropDuringPlacing()
	{
		// Does not need this, so empty the function
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
	
	override void MoveEntityToFinalPositionSinglePlayer(ActionData action_data, InventoryLocation source, InventoryLocation destination)
	{
		action_data.m_Player.GetDayZPlayerInventory().RedirectToHandEvent(InventoryMode.LOCAL, source, destination);
	}
};
