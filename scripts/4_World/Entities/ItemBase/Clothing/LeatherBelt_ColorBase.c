class LeatherBelt_ColorBase extends Clothing
{
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo( parent ) )
		{
			return false;
		}
		
		return IsEmpty();
	}
}
class LeatherBelt_Beige extends LeatherBelt_ColorBase {};
class LeatherBelt_Natural extends LeatherBelt_ColorBase {};
class LeatherBelt_Brown extends LeatherBelt_ColorBase {};
class LeatherBelt_Black extends LeatherBelt_ColorBase {};