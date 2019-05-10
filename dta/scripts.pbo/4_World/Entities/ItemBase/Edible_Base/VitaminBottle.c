class VitaminBottle : Edible_Base
{
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if( consumer.GetModifiersManager().IsModifierActive(eModifiers.MDF_IMMUNITYBOOST ) )//effectively resets the timer
		{
			consumer.GetModifiersManager().DeactivateModifier( eModifiers.MDF_IMMUNITYBOOST );
		}
		consumer.GetModifiersManager().ActivateModifier( eModifiers.MDF_IMMUNITYBOOST );
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
		//AddAction(ActionForceFeed);
		//AddAction(ActionEat);
	}
}