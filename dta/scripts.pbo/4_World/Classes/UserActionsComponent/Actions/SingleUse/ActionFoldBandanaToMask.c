class ActionFoldBandanaToMask : ActionFoldEntityToSlot
{
	void ActionFoldBandanaToMask ()
	{
		m_MessageSuccess = "It's on my face.";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_SlotID = InventorySlots.MASK;
	}

	override int GetType () { return AT_BANDANA_TO_MASK; }
	override string GetText () { return "#bandana_to_mask"; }
};
