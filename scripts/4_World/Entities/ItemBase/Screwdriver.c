class Screwdriver extends ToolBase
{
	void Screwdriver()
	{
		m_MineDisarmRate = 80;
	}
	
	override bool IsMeleeFinisher()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBurnSewTarget);
		AddAction(ActionUnrestrainTarget);
		AddAction(ActionBurnSewSelf);
		AddAction(ActionSkinning);
		AddAction(ActionLockAttachment);
		AddAction(ActionDisarmMine);
	}
}