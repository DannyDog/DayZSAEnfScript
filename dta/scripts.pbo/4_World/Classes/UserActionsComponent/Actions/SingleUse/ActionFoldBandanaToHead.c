class ActionFoldBandanaToHead : ActionFoldEntityToSlot
{
	void ActionFoldBandanaToHead ()
	{
		m_MessageSuccess = "It's on my head.";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_SlotID = InventorySlots.HEADGEAR;
	}

	override int GetType () { return AT_BANDANA_TO_HEAD; }
	override string GetText () { return "#bandana_to_head"; }
};
