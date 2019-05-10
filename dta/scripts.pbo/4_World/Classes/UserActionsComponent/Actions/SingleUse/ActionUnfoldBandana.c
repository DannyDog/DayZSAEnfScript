class ActionUnfoldBandana : ActionUnfoldEntity
{
	void ActionUnfoldBandana ()
	{
		m_MessageSuccess = "It's folded.";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
	}

	override int GetType () { return AT_BANDANA_UNFOLD; }
	override string GetText() { return "#bandana_unfold"; }
};

class UnfoldBandanaLambda : TurnItemIntoItemLambda
{
	void UnfoldBandanaLambda (EntityAI old_item, string new_item_type, PlayerBase player)
	{
	}
};

