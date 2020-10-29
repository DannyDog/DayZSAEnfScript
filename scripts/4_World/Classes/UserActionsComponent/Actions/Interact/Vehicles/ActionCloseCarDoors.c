class ActionCloseCarDoors: ActionCarDoors
{
	void ActionCloseCarDoors()
	{	
		m_HUDCursorIcon = CursorIcons.CloseDoors;
		//m_CarDoorSound = "offroad_door_close_SoundSet";
		m_IsOpening = false;
		
		FillCommandUIDPerCrewIdx(DayZPlayerConstants.CMD_ACTIONMOD_DRIVER_DOOR_CLOSE, DayZPlayerConstants.CMD_ACTIONMOD_CODRIVER_DOORCLOSE);
	}

	override string GetText()
	{
		return "#close";
	}
};