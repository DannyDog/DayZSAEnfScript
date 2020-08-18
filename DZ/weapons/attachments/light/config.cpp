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
	class DZ_Weapons_Lights
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class Switchable_Base;
	class UniversalLight: Switchable_Base
	{
		scope = 2;
		displayName = "$STR_cfgVehicles_UniversalLight0";
		descriptionShort = "$STR_cfgVehicles_UniversalLight1";
		model = "\DZ\weapons\attachments\light\weaponlight_universal.p3d";
		rotationFlags = 17;
		reversed = 1;
		weight = 80;
		itemSize[] = {2,1};
		inventorySlot[] = {"weaponFlashlight","helmetFlashlight"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\m4_flashlight.rvmat","dz\gear\tools\data\flashlight_glass.rvmat"}},{0.7,{}},{0.5,{"DZ\weapons\attachments\data\m4_flashlight_damage.rvmat","dz\gear\tools\data\flashlight_glass_damage.rvmat"}},{0.3,{}},{0.0,{"DZ\weapons\attachments\data\m4_flashlight_destruct.rvmat","dz\gear\tools\data\flashlight_glass_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {7};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"zbytek","reflector","glass","reflector_far"};
		hiddenSelectionsTextures[] = {"dz\weapons\attachments\data\m4_flashlight_co.paa","dz\weapons\attachments\data\m4_flashlight_co.paa","dz\gear\tools\data\flashlight_glass.paa","dz\weapons\attachments\data\m4_flashlight_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\weapons\attachments\data\m4_flashlight.rvmat","dz\weapons\attachments\data\m4_flashlight.rvmat","dz\gear\tools\data\flashlight_glass.rvmat","dz\weapons\attachments\data\m4_flashlight.rvmat"};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOffWhenInCargo = 1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 30;
		};
	};
	class TLRLight: Switchable_Base
	{
		scope = 2;
		displayName = "$STR_cfgVehicles_TLRLight0";
		descriptionShort = "$STR_cfgVehicles_TLRLight1";
		model = "\DZ\weapons\attachments\light\weaponlight_TLR.p3d";
		rotationFlags = 17;
		reversed = 1;
		weight = 118;
		itemSize[] = {1,1};
		inventorySlot[] = {"pistolFlashlight"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\weapons\attachments\data\tls3.rvmat"}},{0.7,{"DZ\weapons\attachments\data\tls3.rvmat"}},{0.5,{"DZ\weapons\attachments\data\tls3_damage.rvmat"}},{0.3,{"DZ\weapons\attachments\data\tls3_damage.rvmat"}},{0.0,{"DZ\weapons\attachments\data\tls3_destruct.rvmat"}}};
				};
			};
		};
		repairableWithKits[] = {7};
		repairCosts[] = {30.0,25.0};
		hiddenSelections[] = {"glass","reflector"};
		hiddenSelectionsTextures[] = {"dz\gear\tools\data\flashlight_glass.paa","dz\gear\tools\data\flashlight_old_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\tools\data\flashlight_glass.rvmat"};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOffWhenInCargo = 1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 30;
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyWeaponlight_universal: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "weaponFlashlight";
		model = "\dz\weapons\attachments\light\weaponlight_universal.p3d";
	};
	class ProxyWeaponlight_TLR: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "pistolFlashlight";
		model = "\dz\weapons\attachments\light\weaponlight_TLR.p3d";
	};
};
