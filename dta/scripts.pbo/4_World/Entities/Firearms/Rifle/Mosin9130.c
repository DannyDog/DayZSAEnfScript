/**@class		Mosin9130
 * @brief		base for Mosin
 * @NOTE		name copies config base class
 **/
class Mosin9130_Base extends BoltActionRifle_InnerMagazine_Base
{
	void Mosin9130_Base ()
	{
	}
	
	override bool CanEnterIronsights()
	{
		ItemOptics optic = GetAttachedOptics();
		if (optic && PUScopeOptic.Cast(optic))
			return true;
		return super.CanEnterIronsights();
	}
};


class Mosin9130 extends Mosin9130_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MosinRecoil(this);
	}
};

class SawedoffMosin9130_Base extends Mosin9130_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MosinSawedOffRecoil(this);
	}
};
