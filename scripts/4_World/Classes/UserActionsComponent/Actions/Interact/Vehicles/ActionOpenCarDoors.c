class ActionOpenCarDoors: ActionCarDoors
{
	void ActionOpenCarDoors()
	{
		m_HUDCursorIcon = CursorIcons.OpenDoors;
		//m_CarDoorSound = "offroad_door_open_SoundSet";
		m_IsOpening = true;
		
		FillCommandUIDPerCrewIdx(DayZPlayerConstants.CMD_ACTIONMOD_DRIVER_DOOR_OPEN, DayZPlayerConstants.CMD_ACTIONMOD_CODRIVER_DOOROPEN);
	}

	override string GetText()
	{
		return "#open";
	}
};