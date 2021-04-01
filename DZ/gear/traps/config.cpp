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
	class DZ_Gear_Traps
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgAmmo
{
	class DefaultAmmo;
	class LandMineExplosion: DefaultAmmo
	{
		hit = 0.0;
		indirectHit = 0.5;
		indirectHitRange = 1;
		particle = "explosion_landmine_01";
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		fuseDistance = 1;
		simulation = "shotShell";
		simulationStep = 0.05;
		soundSetExplosion[] = {"Landmine_Explosion_SoundSet","Landmine_Explosion_Tail_SoundSet"};
		soundHit[] = {"DZ\sounds\weapons\grenades\hand_grenade_1",10.0,1};
		soundFly[] = {"dz\sounds\Weapons\explosions\noise",3.162277e-05,1};
		soundEngine[] = {"",9.999998e-05,4};
		class DamageApplied
		{
			type = "FragGrenade";
			bleedThreshold = 1.0;
			class Health
			{
				damage = 17;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 100;
			};
		};
		class NoiseExplosion
		{
			strength = 100;
			type = "sound";
		};
	};
};
class CfgVehicles
{
	class Trap_Base;
	class BearTrap: Trap_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_BearTrap0";
		descriptionShort = "$STR_CfgVehicles_BearTrap1";
		model = "\DZ\gear\traps\beartrap.p3d";
		itemSize[] = {7,3};
		weight = 12000;
		itemBehaviour = 2;
		lootTag[] = {"Hunting","Forester","Work"};
		slopeTolerance = 0.2;
		yawPitchRollLimit[] = {60,60,60};
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\traps\data\beartrap_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\traps\data\beartrap.rvmat"};
		hologramMaterial = "beartrap";
		hologramMaterialPath = "dz\gear\traps\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\gear\traps\data\beartrap.rvmat"}},{0.7,{"DZ\gear\traps\data\beartrap.rvmat"}},{0.5,{"DZ\gear\traps\data\beartrap_damage.rvmat"}},{0.3,{"DZ\gear\traps\data\beartrap_damage.rvmat"}},{0.0,{"DZ\gear\traps\data\beartrap_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class BearTrap_Set
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class movement_walk
				{
					soundSet = "beartrap_movement_walk_SoundSet";
					id = 1;
				};
				class movement_run
				{
					soundSet = "beartrap_movement_run_SoundSet";
					id = 3;
				};
				class movement_sprint
				{
					soundSet = "beartrap_movement_sprint_SoundSet";
					id = 5;
				};
				class pickUpItem_Light
				{
					soundSet = "pickUpBearTrapLight_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpBearTrap_SoundSet";
					id = 797;
				};
			};
		};
	};
	class LandMineTrap: Trap_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_LandMineTrap0";
		descriptionShort = "$STR_CfgVehicles_LandMineTrap1";
		model = "\DZ\gear\traps\landmine.p3d";
		weight = 1670;
		itemSize[] = {2,2};
		itemBehaviour = 1;
		slopeTolerance = 0.15;
		yawPitchRollLimit[] = {60,60,60};
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\traps\data\landmine_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\traps\data\landmine.rvmat"};
		hologramMaterial = "landmine";
		hologramMaterialPath = "dz\gear\traps\data";
		ammoType = "LandMineExplosion";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\traps\data\landmine.rvmat"}},{0.7,{"DZ\gear\traps\data\landmine.rvmat"}},{0.5,{"DZ\gear\traps\data\landmine_damage.rvmat"}},{0.3,{"DZ\gear\traps\data\landmine_damage.rvmat"}},{0.0,{"DZ\gear\traps\data\landmine_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class safety_pin
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class landmine_start
				{
					soundSet = "landmine_start_SoundSet";
					id = 1;
				};
				class landmine_loop
				{
					soundSet = "landmine_loop_SoundSet";
					id = 2;
				};
				class landmine_end
				{
					soundSet = "landmine_end_SoundSet";
					id = 3;
				};
			};
		};
	};
	class SmallFishTrap: Trap_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_SmallFishTrap0";
		descriptionShort = "$STR_CfgVehicles_SmallFishTrap1";
		model = "\dz\gear\tools\improvised_fish_trap.p3d";
		lootCategory = "Crafted";
		rotationFlags = 17;
		slopeTolerance = 0.2;
		yawPitchRollLimit[] = {20,20,20};
		weight = 60;
		itemSize[] = {2,3};
		itemsCargoSize[] = {1,2};
		allowOwnedCargoManipulation = 1;
		itemBehaviour = 1;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\drinks\Data\Loot_WaterBottle_CA.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\drinks\Data\Loot_WaterBottle.rvmat"};
		hologramMaterial = "Loot_WaterBottle";
		hologramMaterialPath = "dz\gear\drinks\data";
		stackedUnit = "ml";
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		quantityBar = 1;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit = 0.0;
		varQuantityMin = 0.0;
		varQuantityMax = 500.0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"}},{0.7,{"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"}},{0.5,{"DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"}},{0.3,{"DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"}},{0.0,{"DZ\gear\drinks\data\Loot_WaterBottle_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class FishNetTrap: Trap_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FishNetTrap0";
		descriptionShort = "$STR_CfgVehicles_FishNetTrap1";
		model = "\dz\gear\traps\fishnettrap.p3d";
		lootCategory = "Crafted";
		slopeTolerance = 0.2;
		yawPitchRollLimit[] = {20,20,20};
		weight = 60;
		itemSize[] = {2,3};
		itemsCargoSize[] = {2,3};
		allowOwnedCargoManipulation = 1;
		itemBehaviour = 1;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\traps\data\fishnettrap_CO.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\traps\data\fishnettrap.rvmat"};
		hologramMaterial = "fishnettrap";
		hologramMaterialPath = "dz\gear\traps\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"}},{0.7,{"DZ\gear\drinks\data\Loot_WaterBottle.rvmat"}},{0.5,{"DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"}},{0.3,{"DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"}},{0.0,{"DZ\gear\drinks\data\Loot_WaterBottle_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
		};
	};
	class TripwireTrap: Trap_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_TripwireTrap0";
		descriptionShort = "$STR_CfgVehicles_TripwireTrap1";
		model = "\dz\gear\traps\tripwire.p3d";
		rotationFlags = 16;
		lootCategory = "Crafted";
		attachments[] = {"tripWireAttachment"};
		slopeTolerance = 0.3;
		yawPitchRollLimit[] = {60,60,60};
		weight = 60;
		itemSize[] = {2,3};
		itemBehaviour = 1;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\crafting\data\rabbit_snare_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\crafting\data\rabbit_snare.rvmat"};
		hologramMaterial = "rabbit_snare";
		hologramMaterialPath = "dz\gear\crafting\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\rabbit_snare.rvmat"}},{0.7,{"DZ\gear\crafting\data\rabbit_snare.rvmat"}},{0.5,{"DZ\gear\crafting\data\rabbit_snare_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\rabbit_snare_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\rabbit_snare_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class HiddenByDefault
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class ShownByDefault
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class inventory: ShownByDefault{};
			class placing: HiddenByDefault{};
			class TripWire_set_can: HiddenByDefault{};
			class TripWire_set_grenade: HiddenByDefault{};
			class TripWire_triggered: HiddenByDefault{};
			class s1_flashbang: HiddenByDefault{};
			class s1_frag_RGD5: HiddenByDefault{};
			class s1_grenade: HiddenByDefault{};
			class s1_Road_flare: HiddenByDefault{};
			class s1_smokegrenade: HiddenByDefault{};
			class s1_smokegrenade_rdg2: HiddenByDefault{};
			class s1_SodaCan_Used: HiddenByDefault{};
			class s2_flashbang: HiddenByDefault{};
			class s2_frag_RGD5: HiddenByDefault{};
			class s2_grenade: HiddenByDefault{};
			class s2_Road_flare: HiddenByDefault{};
			class s2_smokegrenade: HiddenByDefault{};
			class s2_smokegrenade_rdg2: HiddenByDefault{};
			class s2_SodaCan_Used: HiddenByDefault{};
			class s3_flashbang: HiddenByDefault{};
			class s3_frag_RGD5: HiddenByDefault{};
			class s3_grenade: HiddenByDefault{};
			class s3_Road_flare: HiddenByDefault{};
			class s3_smokegrenade: HiddenByDefault{};
			class s3_smokegrenade_rdg2: HiddenByDefault{};
			class s3_SodaCan_Used: HiddenByDefault{};
		};
	};
	class RabbitSnareTrap: Trap_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_RabbitSnareTrap0";
		descriptionShort = "$STR_CfgVehicles_RabbitSnareTrap1";
		model = "\dz\gear\crafting\rabbit_snare.p3d";
		rotationFlags = 16;
		lootCategory = "Crafted";
		slopeTolerance = 0.2;
		yawPitchRollLimit[] = {45,45,45};
		weight = 240;
		itemSize[] = {2,2};
		itemBehaviour = 1;
		hiddenSelections[] = {"placing"};
		hiddenSelectionsTextures[] = {"dz\gear\crafting\data\rabbit_snare_co.paa"};
		hiddenSelectionsMaterials[] = {"dz\gear\crafting\data\rabbit_snare.rvmat"};
		hologramMaterial = "rabbit_snare";
		hologramMaterialPath = "dz\gear\crafting\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 70;
					healthLevels[] = {{1.0,{"DZ\gear\crafting\data\rabbit_snare.rvmat"}},{0.7,{"DZ\gear\crafting\data\rabbit_snare.rvmat"}},{0.5,{"DZ\gear\crafting\data\rabbit_snare_damage.rvmat"}},{0.3,{"DZ\gear\crafting\data\rabbit_snare_damage.rvmat"}},{0.0,{"DZ\gear\crafting\data\rabbit_snare_destruct.rvmat"}}};
				};
			};
		};
		class AnimationSources
		{
			class inventory
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class placing
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class rabbit_snare_used
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
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
	};
};
