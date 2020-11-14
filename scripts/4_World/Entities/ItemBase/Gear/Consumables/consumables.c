class Bait: ItemBase {};
class Bandana_ColorBase: Clothing
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBandageTarget);
		AddAction(ActionBandageSelf);
		AddAction(ActionWringClothes);
	}
	
	void Bandana_ColorBase()
	{

	}
	
	override float GetBandagingEffectivity()
	{
		return 1.0;
	};
};
class Bandana_RedPattern: Bandana_ColorBase {};
class Bandana_BlackPattern: Bandana_ColorBase {};
class Bandana_PolkaPattern: Bandana_ColorBase {};
class Bandana_Greenpattern: Bandana_ColorBase {};
class Bandana_CamoPattern: Bandana_ColorBase {};
class Bandana_Blue: Bandana_ColorBase {};
class Bandana_Pink: Bandana_ColorBase {};
class Bandana_Yellow: Bandana_ColorBase {};

class BatteryD: ItemBase {};
class Bone:  ItemBase {};
class BoneBait: ItemBase {};
class BoneHook:  ItemBase {};
class BurlapStrip: ItemBase {};
class ButaneCanister: ItemBase {};
class DuctTape: ItemBase 
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionRepairTent);
		AddAction(ActionRepairShelter);
		//AddAction(ActionRepairPart);
		AddAction(ActionRestrainTarget);
		AddAction(ActionRestrainSelf);
	}
};
class Flashbang: ItemBase {};
class Hook:  ItemBase {};
class LargeGasCanister: ItemBase {};
class MediumGasCanister: ItemBase {};
class NailBox: Box_Base {};
class Netting: ItemBase {};
class SmallGasCanister: ItemBase {};
class SmallStone: ItemBase {};
class Spraycan_ColorBase: ItemBase {};
class Spraycan_Black: Spraycan_ColorBase {};
class Spraycan_Green: Spraycan_ColorBase {};
class TannedLeather: ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttachToConstruction);
	}
};
