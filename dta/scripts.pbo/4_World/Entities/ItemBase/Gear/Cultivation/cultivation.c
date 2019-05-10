class AntiPestsSpray: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDisinfectPlantBit);
		AddAction(ActionDisinfectPlant);
		AddAction(ActionForceDrink);
		AddAction(ActionDrink);
	}
};
class CannabisSeeds : SeedBase{};
class PepperSeeds : SeedBase{};
class Plant_Cannabis : PlantBase {};
class Plant_Pepper : PlantBase {};
class Plant_Potato : PlantBase {};
class Plant_Pumpkin : PlantBase {};
class Plant_Tomato : PlantBase {};
class Plant_Zucchini : PlantBase {};
class PumpkinSeeds : SeedBase{};
class SeedBase : Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionPlantSeed);
		AddAction(ActionEmptySeedsPack);
	}
};
class TomatoSeeds : SeedBase{};
class ZucchiniSeeds : SeedBase{};
