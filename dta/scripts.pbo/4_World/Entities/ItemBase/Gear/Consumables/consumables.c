class Bait: ItemBase {};
class Bandana_ColorBase: ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionBandageTarget);
		AddAction(ActionBandageSelf);
	}
};
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
class TannedLeather: ItemBase {};
