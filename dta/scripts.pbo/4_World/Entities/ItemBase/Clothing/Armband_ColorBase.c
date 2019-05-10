class Armband_ColorBase extends Clothing
{
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}
		if ( GetNumberOfItems() == 0 || !parent || parent.IsMan() )
		{
			return true;
		}
		return false;
	}
	
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}
		if ( GetQuantity() <= 1 )
		{
			return true;
		}
		return false;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionWringClothes);
	}
};

class Armband_Dyed extends Armband_ColorBase {};
class Armband_White extends Armband_ColorBase {};
class Armband_Yellow extends Armband_ColorBase {};
class Armband_Orange extends Armband_ColorBase {};
class Armband_Red extends Armband_ColorBase {};
class Armband_Green extends Armband_ColorBase {};
class Armband_Pink extends Armband_ColorBase {};
class Armband_Blue extends Armband_ColorBase {};
class Armband_Black extends Armband_ColorBase {};