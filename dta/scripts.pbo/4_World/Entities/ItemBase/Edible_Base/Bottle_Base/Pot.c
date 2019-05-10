class Pot extends Bottle_Base
{
	void Pot()
	{

	}
	
	void ~Pot()
	{

	}
	
	override bool IsContainer()
	{
		return true;
	}
	
	override string GetPouringSoundset()
	{
		return "emptyVessle_Pot_SoundSet";
	}
	
		override string GetEmptyingLoopSoundsetHard()
	{
		return "pour_HardGround_Pot_SoundSet";
	}
	
	override string GetEmptyingLoopSoundsetSoft()
	{
		return "pour_SoftGround_Pot_SoundSet";
	}
	
	override string GetEmptyingLoopSoundsetWater()
	{
		return "pour_Water_Pot_SoundSet";
	}
	
	override string GetEmptyingEndSoundsetHard()
	{
		return "pour_End_HardGround_Pot_SoundSet";
	}
	
	override string GetEmptyingEndSoundsetSoft()
	{
		return "pour_End_SoftGround_Pot_SoundSet";
	}
	
	override string GetEmptyingEndSoundsetWater()
	{
		return "pour_End_Water_Pot_SoundSet";
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}	
		if ( !(parent.IsKindOf("Pot"))/* && !(parent.IsKindOf("Container_Base"))*/)
		{
			return true;
		}
		
		return false;
	}
	
	override void EECargoIn(EntityAI item)
	{
		super.EECargoIn(item);

		if (GetGame().IsServer())
		{
			//! when the pot contains some liquid set the wetness of item to max
			if (GetQuantity() > 0 && GetLiquidType() >= LIQUID_WATER)
			{
				SoakItem(item);
			}
		}
	}
	
	//! sets wetness of item too its max
	protected void SoakItem(EntityAI item)
	{
		ItemBase itemIB;
		if (Class.CastTo(itemIB, item))
		{
			if (itemIB.GetAbsorbency() > 0)
			{
				itemIB.SetWet(itemIB.GetWetMax());
			}
		}
	}
	
	override bool IsOpen()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionWorldLiquidActionSwitch);
		AddAction(ActionFillGeneratorTank);
		AddAction(ActionExtinguishFireplaceByLiquid);
		AddAction(ActionFillBottleBase);
		AddAction(ActionWaterGardenSlot);
		AddAction(ActionWaterPlant);
		AddAction(ActionForceDrink);
		AddAction(ActionPourLiquid);
		AddAction(ActionDrainLiquid);
		AddAction(ActionEmptyCookingPot);
		AddAction(ActionDrinkCookingPot);
	}
}