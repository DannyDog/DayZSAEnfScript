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
	class DZ_Weapons_Melee_Powered
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Melee"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Powered_Base;
	class Switchable_Base;
	class Chainsaw: Switchable_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Chainsaw0";
		descriptionShort = "$STR_CfgVehicles_Chainsaw1";
		model = "\dz\weapons\melee\powered\chainsaw.p3d";
		animClass = "Chainsaw";
		weight = 5800;
		itemSize[] = {10,5};
		absorbency = 0.0;
		openItemSpillRange[] = {40,60};
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
		hiddenSelections[] = {"flame"};
		hiddenSelectionsTextures[] = {""};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\powered\Data\chainsaw.rvmat"}},{0.7,{"DZ\weapons\melee\powered\Data\chainsaw.rvmat"}},{0.5,{"DZ\weapons\melee\powered\Data\chainsaw_damage.rvmat"}},{0.3,{"DZ\weapons\melee\powered\Data\chainsaw_damage.rvmat"}},{0.0,{"DZ\weapons\melee\powered\Data\chainsaw_destruct.rvmat"}}};
				};
			};
		};
		class EnergyManager
		{
			hasIcon = 1;
			energyAtSpawn = 0;
			energyUsagePerSecond = 1;
			energyStorageMax = 600;
		};
		class flame
		{
			sound = "Sound_FlareFlame";
			texture = "dz\gear\consumables\data\flame_red_ca.paa";
		};
	};
	class CattleProd: Powered_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CattleProd0";
		descriptionShort = "$STR_CfgVehicles_CattleProd1";
		model = "\dz\gear\tools\Catle_Prod.p3d";
		inventorySlot[] = {"Shoulder","Melee"};
		rotationFlags = 1;
		weight = 2700;
		itemSize[] = {1,6};
		itemBehaviour = 1;
		fragility = 0.008;
		lootTag[] = {"Farm"};
		lootCategory = "Tools";
		energyResources[] = {{"power",0.1}};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\powered\Data\chainsaw.rvmat"}},{0.7,{"DZ\weapons\melee\powered\Data\chainsaw.rvmat"}},{0.5,{"DZ\weapons\melee\powered\Data\chainsaw_damage.rvmat"}},{0.3,{"DZ\weapons\melee\powered\Data\chainsaw_damage.rvmat"}},{0.0,{"DZ\weapons\melee\powered\Data\chainsaw_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
		class EnergyManager
		{
			hasIcon = 1;
			plugType = 1;
			energyUsagePerSecond = 1.5;
			attachmentAction = 1;
			wetnessExposure = 0.1;
		};
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.6;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.6;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.2;
			};
			class Default_SwitchedOn
			{
				ammo = "MeleeLightBluntShock";
				range = 1.6;
			};
			class Heavy_SwitchedOn
			{
				ammo = "MeleeLightBluntShock_Heavy";
				range = 1.6;
			};
			class Sprint_SwitchedOn
			{
				ammo = "MeleeLightBluntShock_Heavy";
				range = 2.2;
			};
		};
	};
	class StunBaton: Powered_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_StunBaton0";
		descriptionShort = "$STR_CfgVehicles_StunBaton1";
		model = "\dz\weapons\melee\powered\Stun_Baton.p3d";
		inventorySlot[] = {"Shoulder","Melee"};
		rotationFlags = 1;
		weight = 800;
		itemSize[] = {1,4};
		itemBehaviour = 1;
		fragility = 0.008;
		lootTag[] = {"Police"};
		lootCategory = "Tools";
		energyResources[] = {{"power",0.1}};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\powered\Data\Stun_Baton.rvmat"}},{0.7,{"DZ\weapons\melee\powered\Data\Stun_Baton.rvmat"}},{0.5,{"DZ\weapons\melee\powered\Data\Stun_Baton_damage.rvmat"}},{0.3,{"DZ\weapons\melee\powered\Data\Stun_Baton_damage.rvmat"}},{0.0,{"DZ\weapons\melee\powered\Data\Stun_Baton_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {7};
		repairCosts[] = {25.0};
		class EnergyManager
		{
			hasIcon = 1;
			plugType = 1;
			energyUsagePerSecond = 3;
			attachmentAction = 1;
			wetnessExposure = 0.1;
		};
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.5;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.5;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.0;
			};
			class Default_SwitchedOn
			{
				ammo = "MeleeLightBluntShock";
				range = 1.5;
			};
			class Heavy_SwitchedOn
			{
				ammo = "MeleeLightBluntShock_Heavy";
				range = 1.5;
			};
			class Sprint_SwitchedOn
			{
				ammo = "MeleeLightBluntShock_Heavy";
				range = 2.0;
			};
		};
	};
};
