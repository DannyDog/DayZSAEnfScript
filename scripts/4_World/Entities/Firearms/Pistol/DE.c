class Deagle_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new DEagleRecoil(this);
	}
};

class Deagle : Deagle_Base {};
class Deagle_Gold : Deagle_Base {};

