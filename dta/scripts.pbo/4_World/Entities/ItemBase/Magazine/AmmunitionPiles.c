//!ammo pile base
class Ammunition_Base: Magazine_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionSortAmmoPile);
	}
};

class Ammo_45ACP: Ammunition_Base {};
class Ammo_308Win: Ammunition_Base {};
class Ammo_9x19: Ammunition_Base {};
class Ammo_380: Ammunition_Base {};
class Ammo_556x45: Ammunition_Base {};
class Ammo_556x45Tracer: Ammunition_Base {};
class Ammo_762x54: Ammunition_Base {};
class Ammo_762x54Tracer: Ammunition_Base {};
class Ammo_762x39: Ammunition_Base {};
class Ammo_762x39Tracer: Ammunition_Base {};
class Ammo_9x39: Ammunition_Base {};
class Ammo_22: Ammunition_Base {};
class Ammo_12gaPellets: Ammunition_Base {};
class Ammo_12gaSlug: Ammunition_Base {};
class Ammo_357: Ammunition_Base {};
class Ammo_545x39: Ammunition_Base {};
class Ammo_ArrowComposite: Ammunition_Base {};
class Ammo_SharpStick: Ammunition_Base {};
class Ammo_ArrowPrimitive: Ammunition_Base {};
class Ammo_ArrowBoned: Ammunition_Base {};
class Ammo_ArrowBolt: Ammunition_Base {};
class Ammo_DartSyringe: Ammunition_Base {};
class Ammo_Flare: Ammunition_Base {};
class Ammo_RPG7_HE: Ammunition_Base {};
class Ammo_RPG7_AP: Ammunition_Base {};
class Ammo_LAW_HE: Ammunition_Base {};
class Ammo_GrenadeM4 : Ammunition_Base {};