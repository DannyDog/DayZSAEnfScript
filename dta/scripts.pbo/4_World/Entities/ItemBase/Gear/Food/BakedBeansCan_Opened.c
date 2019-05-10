class BakedBeansCan_Opened: Edible_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeedCan);
		AddAction(ActionEatCan);
	}
};
