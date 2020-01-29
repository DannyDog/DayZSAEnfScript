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
	class DZ_Radio
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class HouseNoDestruct;
	class Transmitter_Base: Inventory_Base
	{
		scope = 0;
	};
	class PersonalRadio: Transmitter_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_PersonalRadio0";
		descriptionShort = "$STR_CfgVehicles_PersonalRadio1";
		lootTag[] = {"Police","Hunting","Camping","Military_east"};
		model = "\dz\gear\radio\WalkieTalkie.p3d";
		weight = 2400;
		absorbency = 0.5;
		itemSize[] = {1,3};
		inventorySlot[] = {"WalkieTalkie"};
		rotationFlags = 1;
		oldpower = 0;
		isMeleeWeapon = 1;
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
		simulation = "itemTransmitter";
		inputRange[] = {2.0,5.0,10.0};
		range = 5000;
		attachments[] = {"BatteryD"};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.1;
		};
		class ClothingTypes{};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\radio\data\WalkieTalkie.rvmat"}},{0.7,{"DZ\gear\radio\data\WalkieTalkie.rvmat"}},{0.5,{"DZ\gear\radio\data\WalkieTalkie_damage.rvmat"}},{0.3,{"DZ\gear\radio\data\WalkieTalkie_damage.rvmat"}},{0.0,{"DZ\gear\radio\data\WalkieTalkie_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class turnOnRadio
				{
					soundSet = "turnOnRadio_SoundSet";
					id = 1006;
				};
				class turnOffRadio
				{
					soundSet = "turnOffRadioNoise_SoundSet";
					id = 1007;
				};
			};
		};
	};
	class BaseRadio: Transmitter_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BaseRadio0";
		descriptionShort = "$STR_CfgVehicles_BaseRadio1";
		model = "\dz\gear\radio\Base_radio_station_g.p3d";
		weight = 14500;
		absorbency = 0.5;
		itemSize[] = {5,5};
		inventorySlot[] = {"Back"};
		class ClothingTypes
		{
			male = "\dz\gear\radio\Base_radio_station_m.p3d";
			female = "\dz\gear\radio\Base_radio_station_f.p3d";
		};
		oldpower = 0;
		simulation = "itemTransmitter";
		inputRange = 8;
		range = 50000;
		attachments[] = {"CarBattery"};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.05;
			plugType = 5;
			attachmentAction = 1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\radio\data\Base_radio_station.rvmat"}},{0.7,{"DZ\gear\radio\data\Base_radio_station.rvmat"}},{0.5,{"DZ\gear\radio\data\Base_radio_station_damage.rvmat"}},{0.3,{"DZ\gear\radio\data\Base_radio_station_damage.rvmat"}},{0.0,{"DZ\gear\radio\data\Base_radio_station_destruct.rvmat"}}};
				};
			};
		};
		soundAttType = "Small";
	};
	class Megaphone: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Megaphone0";
		descriptionShort = "$STR_CfgVehicles_Megaphone1";
		lootTag[] = {"Police","Military_east"};
		model = "\dz\gear\radio\megaphone.p3d";
		weight = 2400;
		absorbency = 0.5;
		itemSize[] = {3,4};
		rotationFlags = 17;
		oldpower = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\radio\data\megaphone.rvmat"}},{0.7,{"DZ\gear\radio\data\megaphone.rvmat"}},{0.5,{"DZ\gear\radio\data\megaphone_damage.rvmat"}},{0.3,{"DZ\gear\radio\data\megaphone_damage.rvmat"}},{0.0,{"DZ\gear\radio\data\megaphone_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
		simulation = "itemMegaphone";
		range = 200;
		gain = 3.0;
		attachments[] = {"BatteryD"};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.02;
			attachmentAction = 1;
		};
	};
	class Radio: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Radio0";
		descriptionShort = "$STR_CfgVehicles_Radio1";
		model = "\dz\gear\radio\unitra_wilga.p3d";
		animClass = "Knife";
		weight = 1700;
		itemSize[] = {2,3};
		fragility = 0.01;
		absorbency = 0.5;
		simulation = "ItemRadio";
		attachments[] = {"BatteryD"};
		oldpower = 0;
		repairableWithKits[] = {5,7};
		repairCosts[] = {30.0,25.0};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.02;
			attachmentAction = 1;
			wetnessExposure = 0.1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\radio\data\unitra_wilga.rvmat"}},{0.7,{"DZ\gear\radio\data\unitra_wilga.rvmat"}},{0.5,{"DZ\gear\radio\data\unitra_wilga_damage.rvmat"}},{0.3,{"DZ\gear\radio\data\unitra_wilga_damage.rvmat"}},{0.0,{"DZ\gear\radio\data\unitra_wilga_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
		class Channels
		{
			class Absolute80s
			{
				name = "Absolute 80s";
				url = "http://icecast.timlradio.co.uk/a832.ogg";
			};
			class Absolute90s
			{
				name = "Absolute 90s";
				url = "http://icecast.timlradio.co.uk/a932.ogg";
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyWalkieTalkie: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"WalkieTalkie"};
		model = "\dz\gear\radio\WalkieTalkie.p3d";
	};
};
