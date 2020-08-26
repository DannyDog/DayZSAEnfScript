#define _ARMA_

//(8 Enums)
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	destructno = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgPatches
{
	class DZ_Rocks_Bliss
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgNonAIVehicles
{
	class StaticObject;
	class Static_rock_wallh4: StaticObject{};
	class Static_rock_wallh5: StaticObject{};
	class Static_rock_wallh6: StaticObject{};
	class Static_stone10: StaticObject{};
	class Static_stone10_moss: StaticObject{};
	class Static_stone6: StaticObject{};
	class Static_stone6_moss: StaticObject{};
	class Static_stone7: StaticObject{};
	class Static_stone7_moss: StaticObject{};
	class Static_stone8: StaticObject{};
	class Static_stone8_moss: StaticObject{};
	class Static_stone9: StaticObject{};
	class Static_stone9_moss: StaticObject{};
};
