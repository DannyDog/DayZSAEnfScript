class CharcoalTablets extends Edible_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
		//AddAction(ActionForceFeed);
		//AddAction(ActionEat);
	}
	
	override void OnConsume(float amount, PlayerBase consumer)
	{
		//consumer.GetModifiersManager().ActivateModifier( eModifiers.MDF_POISONING );
	}
}