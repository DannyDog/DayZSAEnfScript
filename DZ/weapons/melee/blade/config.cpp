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
	class DZ_Weapons_Melee_Blade
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
	class WoodAxe: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_WoodAxe0";
		descriptionShort = "$STR_CfgVehicles_WoodAxe1";
		model = "\dz\weapons\melee\blade\woodaxe.p3d";
		repairableWithKits[] = {4};
		repairCosts[] = {20.0};
		rotationFlags = 12;
		weight = 1360;
		itemSize[] = {2,6};
		itemBehaviour = 2;
		fragility = 0.01;
		inventorySlot[] = {"Shoulder","Melee"};
		lootCategory = "Tools";
		lootTag[] = {"Work","Forester","Camping"};
		dismantle_action_type = 74;
		openItemSpillRange[] = {20,40};
		itemInfo[] = {"Axe"};
		isMeleeWeapon = 1;
		suicideAnim = "woodaxe";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeAxe";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeAxe_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeAxe_Heavy";
				range = 3.7;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\axe.rvmat","DZ\weapons\melee\blade\data\axe_view_metal.rvmat","DZ\weapons\melee\blade\data\axe_view_wood.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\axe.rvmat","DZ\weapons\melee\blade\data\axe_view_metal.rvmat","DZ\weapons\melee\blade\data\axe_view_wood.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\axe_damage.rvmat","DZ\weapons\melee\blade\data\axe_view_metal_damage.rvmat","DZ\weapons\melee\blade\data\axe_view_wood_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\axe_damage.rvmat","DZ\weapons\melee\blade\data\axe_view_metal_damage.rvmat","DZ\weapons\melee\blade\data\axe_view_wood_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\axe_destruct.rvmat","DZ\weapons\melee\blade\data\axe_view_metal_destruct.rvmat","DZ\weapons\melee\blade\data\axe_view_wood_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
				class ShoulderR_Hide
				{
					soundset = "ShoulderR_Hide_SoundSet";
					id = 1210;
				};
				class ShoulderR_Show
				{
					soundset = "ShoulderR_Show_SoundSet";
					id = 1211;
				};
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
			};
		};
	};
	class Hatchet: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Hatchet0";
		descriptionShort = "$STR_CfgVehicles_Hatchet1";
		model = "\dz\weapons\melee\blade\hatchet.p3d";
		build_action_type = 10;
		dismantle_action_type = 74;
		repairableWithKits[] = {4};
		repairCosts[] = {18.0};
		rotationFlags = 17;
		weight = 1133;
		itemSize[] = {2,4};
		fragility = 0.01;
		inventorySlot[] = {""};
		lootCategory = "Tools";
		lootTag[] = {"Work","Forester","Camping"};
		itemInfo[] = {"Axe"};
		openItemSpillRange[] = {20,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\hatchet.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\hatchet.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\hatchet_destruct.rvmat"}}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeHatchet";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeHatchet_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeHatchet_Heavy";
				range = 3.3;
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "woodaxe";
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
				class ShoulderR_Hide
				{
					soundset = "ShoulderR_Hide_SoundSet";
					id = 1210;
				};
				class ShoulderR_Show
				{
					soundset = "ShoulderR_Show_SoundSet";
					id = 1211;
				};
				class WoodHammer_SoundSet
				{
					soundSet = "WoodHammer_SoundSet";
					id = 11161;
				};
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
			};
		};
	};
	class FirefighterAxe: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FirefighterAxe0";
		descriptionShort = "$STR_CfgVehicles_FirefighterAxe1";
		model = "\dz\weapons\melee\blade\FirefighterAxe.p3d";
		repairableWithKits[] = {4};
		repairCosts[] = {20.0};
		rotationFlags = 12;
		weight = 1360;
		itemSize[] = {2,7};
		itemBehaviour = 2;
		fragility = 0.01;
		inventorySlot[] = {"Shoulder","Melee"};
		lootCategory = "Tools";
		lootTag[] = {"Work","Forester","Camping"};
		dismantle_action_type = 74;
		openItemSpillRange[] = {20,40};
		itemInfo[] = {"Axe"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\melee\blade\data\ffax_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\ffax.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\ffax.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\ffax_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\ffax_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\ffax_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "fireaxe";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeFireAxe";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeFireAxe_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeFireAxe_Heavy";
				range = 3.7;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
				class ShoulderR_Hide
				{
					soundset = "ShoulderR_Hide_SoundSet";
					id = 1210;
				};
				class ShoulderR_Show
				{
					soundset = "ShoulderR_Show_SoundSet";
					id = 1211;
				};
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
			};
		};
	};
	class FirefighterAxe_Black: FirefighterAxe
	{
		scope = 2;
		color = "Black";
		lootCategory = "Crafted";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.15,0.15,0.15,1.0,CO)"};
	};
	class FirefighterAxe_Green: FirefighterAxe
	{
		scope = 2;
		color = "Green";
		lootCategory = "Crafted";
		hiddenSelectionsTextures[] = {"#(argb,8,8,3)color(0.35,0.37,0.28,1.0,CO)"};
	};
	class Cleaver: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Cleaver0";
		descriptionShort = "$STR_CfgVehicles_Cleaver1";
		model = "\dz\weapons\melee\blade\meat_cleaver.p3d";
		inventorySlot[] = {""};
		repairableWithKits[] = {4};
		repairCosts[] = {15.0};
		rotationFlags = 17;
		canSkinBodies = 1;
		weight = 500;
		itemSize[] = {2,3};
		lootTag[] = {"Kitchen","Civilian"};
		lootCategory = "Tools";
		openItemSpillRange[] = {10,35};
		itemInfo[] = {"Knife"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 120;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\meat_cleaver.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\meat_cleaver.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\meat_cleaver_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\meat_cleaver_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\meat_cleaver_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeKnife";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeKnife_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeKnife_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
				class CutTies_end
				{
					soundSet = "CutTies_end_SoundSet";
					id = 519;
				};
				class CutTies_loop
				{
					soundSet = "CutTies_loop_SoundSet";
					id = 520;
				};
				class shaving_knife_clean
				{
					soundSet = "shaving_knife_clean_SoundSet";
					id = 600;
				};
				class shaving_knife1
				{
					soundSet = "shaving_knife1_SoundSet";
					id = 601;
				};
				class shaving_knife2
				{
					soundSet = "shaving_knife2_SoundSet";
					id = 602;
				};
				class shaving_knife3
				{
					soundSet = "shaving_knife3_SoundSet";
					id = 603;
				};
				class shaving_knife4
				{
					soundSet = "shaving_knife4_SoundSet";
					id = 604;
				};
				class shaving_knife5
				{
					soundSet = "shaving_knife5_SoundSet";
					id = 605;
				};
				class shaving_knife6
				{
					soundSet = "shaving_knife6_SoundSet";
					id = 606;
				};
				class shaving_knife7
				{
					soundSet = "shaving_knife7_SoundSet";
					id = 607;
				};
				class shaving_knife8
				{
					soundSet = "shaving_knife8_SoundSet";
					id = 608;
				};
				class shaving_knife9
				{
					soundSet = "shaving_knife9_SoundSet";
					id = 609;
				};
				class shaving_knife10
				{
					soundSet = "shaving_knife10_SoundSet";
					id = 610;
				};
				class shaving_knife11
				{
					soundSet = "shaving_knife11_SoundSet";
					id = 611;
				};
				class shaving_knife12
				{
					soundSet = "shaving_knife12_SoundSet";
					id = 612;
				};
				class shaving_knife13
				{
					soundSet = "shaving_knife13_SoundSet";
					id = 613;
				};
				class shaving_knife14
				{
					soundSet = "shaving_knife14_SoundSet";
					id = 614;
				};
				class shaving_knife15
				{
					soundSet = "shaving_knife15_SoundSet";
					id = 615;
				};
				class shaving_knife16
				{
					soundSet = "shaving_knife16_SoundSet";
					id = 616;
				};
				class shaving_knife17
				{
					soundSet = "shaving_knife17_SoundSet";
					id = 617;
				};
				class shaving_knife18
				{
					soundSet = "shaving_knife18_SoundSet";
					id = 618;
				};
				class shaving_knife19
				{
					soundSet = "shaving_knife19_SoundSet";
					id = 619;
				};
				class shaving_knife20
				{
					soundSet = "shaving_knife20_SoundSet";
					id = 620;
				};
				class shaving_knife21
				{
					soundSet = "shaving_knife21_SoundSet";
					id = 621;
				};
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
			};
		};
	};
	class CombatKnife: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_CombatKnife0";
		descriptionShort = "$STR_CfgVehicles_CombatKnife1";
		model = "\dz\weapons\melee\blade\combatknife.p3d";
		animClass = "Knife";
		repairableWithKits[] = {4};
		repairCosts[] = {10.0};
		inventorySlot[] = {"Knife"};
		rotationFlags = 17;
		canSkinBodies = 1;
		RestrainUnlockType = 1;
		weight = 312;
		itemSize[] = {1,3};
		lootTag[] = {"Military_east","Military_west"};
		lootCategory = "Tools";
		itemInfo[] = {"Knife"};
		openItemSpillRange[] = {10,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\combat_knife.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\combat_knife.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\combat_knife_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\combat_knife_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\combat_knife_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeMachete";
				range = 1.2;
			};
			class Heavy
			{
				ammo = "MeleeMachete_Heavy";
				range = 1.2;
			};
			class Sprint
			{
				ammo = "MeleeMachete_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
				class CutTies_end
				{
					soundSet = "CutTies_end_SoundSet";
					id = 519;
				};
				class CutTies_loop
				{
					soundSet = "CutTies_loop_SoundSet";
					id = 520;
				};
				class shaving_knife_clean
				{
					soundSet = "shaving_knife_clean_SoundSet";
					id = 600;
				};
				class shaving_knife1
				{
					soundSet = "shaving_knife1_SoundSet";
					id = 601;
				};
				class shaving_knife2
				{
					soundSet = "shaving_knife2_SoundSet";
					id = 602;
				};
				class shaving_knife3
				{
					soundSet = "shaving_knife3_SoundSet";
					id = 603;
				};
				class shaving_knife4
				{
					soundSet = "shaving_knife4_SoundSet";
					id = 604;
				};
				class shaving_knife5
				{
					soundSet = "shaving_knife5_SoundSet";
					id = 605;
				};
				class shaving_knife6
				{
					soundSet = "shaving_knife6_SoundSet";
					id = 606;
				};
				class shaving_knife7
				{
					soundSet = "shaving_knife7_SoundSet";
					id = 607;
				};
				class shaving_knife8
				{
					soundSet = "shaving_knife8_SoundSet";
					id = 608;
				};
				class shaving_knife9
				{
					soundSet = "shaving_knife9_SoundSet";
					id = 609;
				};
				class shaving_knife10
				{
					soundSet = "shaving_knife10_SoundSet";
					id = 610;
				};
				class shaving_knife11
				{
					soundSet = "shaving_knife11_SoundSet";
					id = 611;
				};
				class shaving_knife12
				{
					soundSet = "shaving_knife12_SoundSet";
					id = 612;
				};
				class shaving_knife13
				{
					soundSet = "shaving_knife13_SoundSet";
					id = 613;
				};
				class shaving_knife14
				{
					soundSet = "shaving_knife14_SoundSet";
					id = 614;
				};
				class shaving_knife15
				{
					soundSet = "shaving_knife15_SoundSet";
					id = 615;
				};
				class shaving_knife16
				{
					soundSet = "shaving_knife16_SoundSet";
					id = 616;
				};
				class shaving_knife17
				{
					soundSet = "shaving_knife17_SoundSet";
					id = 617;
				};
				class shaving_knife18
				{
					soundSet = "shaving_knife18_SoundSet";
					id = 618;
				};
				class shaving_knife19
				{
					soundSet = "shaving_knife19_SoundSet";
					id = 619;
				};
				class shaving_knife20
				{
					soundSet = "shaving_knife20_SoundSet";
					id = 620;
				};
				class shaving_knife21
				{
					soundSet = "shaving_knife21_SoundSet";
					id = 621;
				};
				class drop
				{
					soundset = "combatknife_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class HuntingKnife: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_HuntingKnife0";
		descriptionShort = "$STR_CfgVehicles_HuntingKnife1";
		model = "\dz\weapons\melee\blade\Hunting_knife.p3d";
		inventorySlot[] = {"Knife"};
		repairableWithKits[] = {4};
		repairCosts[] = {10.0};
		rotationFlags = 17;
		RestrainUnlockType = 1;
		canSkinBodies = 1;
		weight = 200;
		itemSize[] = {1,3};
		lootTag[] = {"Hunting","Camping"};
		lootCategory = "Tools";
		itemInfo[] = {"Knife"};
		openItemSpillRange[] = {10,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 130;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeKnife";
				range = 1.2;
			};
			class Heavy
			{
				ammo = "MeleeKnife_Heavy";
				range = 1.2;
			};
			class Sprint
			{
				ammo = "MeleeKnife_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
				class CutTies_end
				{
					soundSet = "CutTies_end_SoundSet";
					id = 519;
				};
				class CutTies_loop
				{
					soundSet = "CutTies_loop_SoundSet";
					id = 520;
				};
				class shaving_knife_clean
				{
					soundSet = "shaving_knife_clean_SoundSet";
					id = 600;
				};
				class shaving_knife1
				{
					soundSet = "shaving_knife1_SoundSet";
					id = 601;
				};
				class shaving_knife2
				{
					soundSet = "shaving_knife2_SoundSet";
					id = 602;
				};
				class shaving_knife3
				{
					soundSet = "shaving_knife3_SoundSet";
					id = 603;
				};
				class shaving_knife4
				{
					soundSet = "shaving_knife4_SoundSet";
					id = 604;
				};
				class shaving_knife5
				{
					soundSet = "shaving_knife5_SoundSet";
					id = 605;
				};
				class shaving_knife6
				{
					soundSet = "shaving_knife6_SoundSet";
					id = 606;
				};
				class shaving_knife7
				{
					soundSet = "shaving_knife7_SoundSet";
					id = 607;
				};
				class shaving_knife8
				{
					soundSet = "shaving_knife8_SoundSet";
					id = 608;
				};
				class shaving_knife9
				{
					soundSet = "shaving_knife9_SoundSet";
					id = 609;
				};
				class shaving_knife10
				{
					soundSet = "shaving_knife10_SoundSet";
					id = 610;
				};
				class shaving_knife11
				{
					soundSet = "shaving_knife11_SoundSet";
					id = 611;
				};
				class shaving_knife12
				{
					soundSet = "shaving_knife12_SoundSet";
					id = 612;
				};
				class shaving_knife13
				{
					soundSet = "shaving_knife13_SoundSet";
					id = 613;
				};
				class shaving_knife14
				{
					soundSet = "shaving_knife14_SoundSet";
					id = 614;
				};
				class shaving_knife15
				{
					soundSet = "shaving_knife15_SoundSet";
					id = 615;
				};
				class shaving_knife16
				{
					soundSet = "shaving_knife16_SoundSet";
					id = 616;
				};
				class shaving_knife17
				{
					soundSet = "shaving_knife17_SoundSet";
					id = 617;
				};
				class shaving_knife18
				{
					soundSet = "shaving_knife18_SoundSet";
					id = 618;
				};
				class shaving_knife19
				{
					soundSet = "shaving_knife19_SoundSet";
					id = 619;
				};
				class shaving_knife20
				{
					soundSet = "shaving_knife20_SoundSet";
					id = 620;
				};
				class shaving_knife21
				{
					soundSet = "shaving_knife21_SoundSet";
					id = 621;
				};
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
			};
		};
	};
	class Machete: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Machete0";
		descriptionShort = "$STR_CfgVehicles_Machete1";
		model = "\dz\weapons\melee\blade\machete.p3d";
		animClass = "Knife";
		RestrainUnlockType = 1;
		repairableWithKits[] = {4};
		repairCosts[] = {12.0};
		inventorySlot[] = {""};
		rotationFlags = 17;
		canSkinBodies = 1;
		weight = 500;
		itemSize[] = {1,4};
		lootTag[] = {"Work","Forester","Hunting","Farm"};
		lootCategory = "Tools";
		itemInfo[] = {"Knife"};
		openItemSpillRange[] = {10,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\machete.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\machete.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\machete_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\machete_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\machete_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeMachete";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeMachete_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeMachete_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
				class CutTies_end
				{
					soundSet = "CutTies_end_SoundSet";
					id = 519;
				};
				class CutTies_loop
				{
					soundSet = "CutTies_loop_SoundSet";
					id = 520;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class Pitchfork: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Pitchfork0";
		descriptionShort = "$STR_CfgVehicles_Pitchfork1";
		model = "\dz\weapons\melee\blade\Hay_Fork.p3d";
		inventorySlot[] = {"Shoulder","Melee"};
		rotationFlags = 17;
		itemSize[] = {2,10};
		weight = 1300;
		itemBehaviour = 2;
		lootTag[] = {"Farm"};
		lootCategory = "Tools";
		openItemSpillRange[] = {30,60};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\Hay_Fork.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\Hay_Fork.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\Hay_Fork_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\Hay_Fork_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\Hay_Fork_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "pitchfork";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleePitchfork";
				range = 2;
			};
			class Heavy
			{
				ammo = "MeleePitchfork_Heavy";
				range = 2;
			};
			class Sprint
			{
				ammo = "MeleePitchfork_Heavy";
				range = 4.1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
				class CutTies_end
				{
					soundSet = "CutTies_end_SoundSet";
					id = 519;
				};
				class CutTies_loop
				{
					soundSet = "CutTies_loop_SoundSet";
					id = 520;
				};
				class shaving_knife_clean
				{
					soundSet = "shaving_knife_clean_SoundSet";
					id = 600;
				};
				class shaving_knife1
				{
					soundSet = "shaving_knife1_SoundSet";
					id = 601;
				};
				class shaving_knife2
				{
					soundSet = "shaving_knife2_SoundSet";
					id = 602;
				};
				class shaving_knife3
				{
					soundSet = "shaving_knife3_SoundSet";
					id = 603;
				};
				class shaving_knife4
				{
					soundSet = "shaving_knife4_SoundSet";
					id = 604;
				};
				class shaving_knife5
				{
					soundSet = "shaving_knife5_SoundSet";
					id = 605;
				};
				class shaving_knife6
				{
					soundSet = "shaving_knife6_SoundSet";
					id = 606;
				};
				class shaving_knife7
				{
					soundSet = "shaving_knife7_SoundSet";
					id = 607;
				};
				class shaving_knife8
				{
					soundSet = "shaving_knife8_SoundSet";
					id = 608;
				};
				class shaving_knife9
				{
					soundSet = "shaving_knife9_SoundSet";
					id = 609;
				};
				class shaving_knife10
				{
					soundSet = "shaving_knife10_SoundSet";
					id = 610;
				};
				class shaving_knife11
				{
					soundSet = "shaving_knife11_SoundSet";
					id = 611;
				};
				class shaving_knife12
				{
					soundSet = "shaving_knife12_SoundSet";
					id = 612;
				};
				class shaving_knife13
				{
					soundSet = "shaving_knife13_SoundSet";
					id = 613;
				};
				class shaving_knife14
				{
					soundSet = "shaving_knife14_SoundSet";
					id = 614;
				};
				class shaving_knife15
				{
					soundSet = "shaving_knife15_SoundSet";
					id = 615;
				};
				class shaving_knife16
				{
					soundSet = "shaving_knife16_SoundSet";
					id = 616;
				};
				class shaving_knife17
				{
					soundSet = "shaving_knife17_SoundSet";
					id = 617;
				};
				class shaving_knife18
				{
					soundSet = "shaving_knife18_SoundSet";
					id = 618;
				};
				class shaving_knife19
				{
					soundSet = "shaving_knife19_SoundSet";
					id = 619;
				};
				class shaving_knife20
				{
					soundSet = "shaving_knife20_SoundSet";
					id = 620;
				};
				class shaving_knife21
				{
					soundSet = "shaving_knife21_SoundSet";
					id = 621;
				};
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
			};
		};
	};
	class Pickaxe: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Pickaxe0";
		descriptionShort = "$STR_CfgVehicles_Pickaxe1";
		model = "\dz\weapons\melee\blade\Pickaxe.p3d";
		inventorySlot[] = {"Shoulder","Melee"};
		rotationFlags = 12;
		repairableWithKits[] = {4};
		repairCosts[] = {25.0};
		build_action_type = 36;
		dismantle_action_type = 46;
		itemInfo[] = {"Pickaxe"};
		RestrainUnlockType = 1;
		itemSize[] = {3,6};
		weight = 1300;
		itemBehaviour = 2;
		lootTag[] = {"Work"};
		lootCategory = "Tools";
		openItemSpillRange[] = {40,70};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"dz\weapons\melee\blade\data\Pickaxe_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\Pickaxe.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\Pickaxe.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\Pickaxe_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\Pickaxe_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\Pickaxe_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "fireaxe";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleePickaxe";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleePickaxe_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleePickaxe_Heavy";
				range = 3.7;
			};
		};
		class Horticulture
		{
			ToolAnim = "CHOPPINGWOOD";
			DiggingTimeToComplete = 4.5;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup_light
				{
					soundSet = "pickUpShovelLight_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "pickUpShovel_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
				class ShoulderR_Hide
				{
					soundset = "ShoulderR_Hide_SoundSet";
					id = 1210;
				};
				class ShoulderR_Show
				{
					soundset = "ShoulderR_Show_SoundSet";
					id = 1211;
				};
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
			};
		};
	};
	class Sword: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Sword0";
		descriptionShort = "$STR_CfgVehicles_Sword1";
		model = "\dz\weapons\melee\blade\medieval_sword.p3d";
		repairableWithKits[] = {4};
		repairCosts[] = {25.0};
		inventorySlot[] = {"Shoulder","Melee"};
		RestrainUnlockType = 1;
		rotationFlags = 12;
		itemSize[] = {2,8};
		weight = 1800;
		itemBehaviour = 2;
		lootTag[] = {"Historical"};
		lootCategory = "Tools";
		itemInfo[] = {"Axe"};
		openItemSpillRange[] = {20,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\medieval_sword.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\medieval_sword.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\medieval_sword_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\medieval_sword_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\medieval_sword_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "sword";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeSword";
				range = 1.8;
			};
			class Heavy
			{
				ammo = "MeleeSword_Heavy";
				range = 1.8;
			};
			class Sprint
			{
				ammo = "MeleeSword_Heavy";
				range = 3.7;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
				class CutTies_end
				{
					soundSet = "CutTies_end_SoundSet";
					id = 519;
				};
				class CutTies_loop
				{
					soundSet = "CutTies_loop_SoundSet";
					id = 520;
				};
				class shaving_knife_clean
				{
					soundSet = "shaving_knife_clean_SoundSet";
					id = 600;
				};
				class shaving_knife1
				{
					soundSet = "shaving_knife1_SoundSet";
					id = 601;
				};
				class shaving_knife2
				{
					soundSet = "shaving_knife2_SoundSet";
					id = 602;
				};
				class shaving_knife3
				{
					soundSet = "shaving_knife3_SoundSet";
					id = 603;
				};
				class shaving_knife4
				{
					soundSet = "shaving_knife4_SoundSet";
					id = 604;
				};
				class shaving_knife5
				{
					soundSet = "shaving_knife5_SoundSet";
					id = 605;
				};
				class shaving_knife6
				{
					soundSet = "shaving_knife6_SoundSet";
					id = 606;
				};
				class shaving_knife7
				{
					soundSet = "shaving_knife7_SoundSet";
					id = 607;
				};
				class shaving_knife8
				{
					soundSet = "shaving_knife8_SoundSet";
					id = 608;
				};
				class shaving_knife9
				{
					soundSet = "shaving_knife9_SoundSet";
					id = 609;
				};
				class shaving_knife10
				{
					soundSet = "shaving_knife10_SoundSet";
					id = 610;
				};
				class shaving_knife11
				{
					soundSet = "shaving_knife11_SoundSet";
					id = 611;
				};
				class shaving_knife12
				{
					soundSet = "shaving_knife12_SoundSet";
					id = 612;
				};
				class shaving_knife13
				{
					soundSet = "shaving_knife13_SoundSet";
					id = 613;
				};
				class shaving_knife14
				{
					soundSet = "shaving_knife14_SoundSet";
					id = 614;
				};
				class shaving_knife15
				{
					soundSet = "shaving_knife15_SoundSet";
					id = 615;
				};
				class shaving_knife16
				{
					soundSet = "shaving_knife16_SoundSet";
					id = 616;
				};
				class shaving_knife17
				{
					soundSet = "shaving_knife17_SoundSet";
					id = 617;
				};
				class shaving_knife18
				{
					soundSet = "shaving_knife18_SoundSet";
					id = 618;
				};
				class shaving_knife19
				{
					soundSet = "shaving_knife19_SoundSet";
					id = 619;
				};
				class shaving_knife20
				{
					soundSet = "shaving_knife20_SoundSet";
					id = 620;
				};
				class shaving_knife21
				{
					soundSet = "shaving_knife21_SoundSet";
					id = 621;
				};
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
			};
		};
	};
	class KukriKnife: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_KukriKnife0";
		descriptionShort = "$STR_CfgVehicles_KukriKnife1";
		model = "\dz\weapons\melee\blade\kukri_knife.p3d";
		repairableWithKits[] = {4};
		repairCosts[] = {10.0};
		rotationFlags = 17;
		RestrainUnlockType = 1;
		canSkinBodies = 1;
		weight = 250;
		itemSize[] = {1,4};
		openItemSpillRange[] = {10,20};
		itemInfo[] = {"Knife"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 150;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\kukri_knife.rvmat","DZ\weapons\melee\blade\data\kukri_knife_wood.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\kukri_knife.rvmat","DZ\weapons\melee\blade\data\kukri_knife_wood.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\kukri_knife_damage.rvmat","DZ\weapons\melee\blade\data\kukri_knife_wood_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\kukri_knife_damage.rvmat","DZ\weapons\melee\blade\data\kukri_knife_wood_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\kukri_knife_destruct.rvmat","DZ\weapons\melee\blade\data\kukri_knife_wood_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeMachete";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeMachete_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeMachete_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
				class CutTies_end
				{
					soundSet = "CutTies_end_SoundSet";
					id = 519;
				};
				class CutTies_loop
				{
					soundSet = "CutTies_loop_SoundSet";
					id = 520;
				};
				class shaving_knife_clean
				{
					soundSet = "shaving_knife_clean_SoundSet";
					id = 600;
				};
				class shaving_knife1
				{
					soundSet = "shaving_knife1_SoundSet";
					id = 601;
				};
				class shaving_knife2
				{
					soundSet = "shaving_knife2_SoundSet";
					id = 602;
				};
				class shaving_knife3
				{
					soundSet = "shaving_knife3_SoundSet";
					id = 603;
				};
				class shaving_knife4
				{
					soundSet = "shaving_knife4_SoundSet";
					id = 604;
				};
				class shaving_knife5
				{
					soundSet = "shaving_knife5_SoundSet";
					id = 605;
				};
				class shaving_knife6
				{
					soundSet = "shaving_knife6_SoundSet";
					id = 606;
				};
				class shaving_knife7
				{
					soundSet = "shaving_knife7_SoundSet";
					id = 607;
				};
				class shaving_knife8
				{
					soundSet = "shaving_knife8_SoundSet";
					id = 608;
				};
				class shaving_knife9
				{
					soundSet = "shaving_knife9_SoundSet";
					id = 609;
				};
				class shaving_knife10
				{
					soundSet = "shaving_knife10_SoundSet";
					id = 610;
				};
				class shaving_knife11
				{
					soundSet = "shaving_knife11_SoundSet";
					id = 611;
				};
				class shaving_knife12
				{
					soundSet = "shaving_knife12_SoundSet";
					id = 612;
				};
				class shaving_knife13
				{
					soundSet = "shaving_knife13_SoundSet";
					id = 613;
				};
				class shaving_knife14
				{
					soundSet = "shaving_knife14_SoundSet";
					id = 614;
				};
				class shaving_knife15
				{
					soundSet = "shaving_knife15_SoundSet";
					id = 615;
				};
				class shaving_knife16
				{
					soundSet = "shaving_knife16_SoundSet";
					id = 616;
				};
				class shaving_knife17
				{
					soundSet = "shaving_knife17_SoundSet";
					id = 617;
				};
				class shaving_knife18
				{
					soundSet = "shaving_knife18_SoundSet";
					id = 618;
				};
				class shaving_knife19
				{
					soundSet = "shaving_knife19_SoundSet";
					id = 619;
				};
				class shaving_knife20
				{
					soundSet = "shaving_knife20_SoundSet";
					id = 620;
				};
				class shaving_knife21
				{
					soundSet = "shaving_knife21_SoundSet";
					id = 621;
				};
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
			};
		};
	};
	class FangeKnife: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_FangeKnife0";
		descriptionShort = "$STR_CfgVehicles_FangeKnife1";
		model = "\dz\weapons\melee\blade\fange_knife.p3d";
		inventorySlot[] = {"Knife"};
		repairableWithKits[] = {4};
		repairCosts[] = {10.0};
		rotationFlags = 17;
		RestrainUnlockType = 1;
		canSkinBodies = 1;
		weight = 200;
		itemSize[] = {1,4};
		openItemSpillRange[] = {10,20};
		itemInfo[] = {"Knife"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 130;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\fange_knife_blade.rvmat","DZ\weapons\melee\blade\data\fange_knife_handle.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\fange_knife_blade.rvmat","DZ\weapons\melee\blade\data\fange_knife_handle.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\fange_knife_blade_damage.rvmat","DZ\weapons\melee\blade\data\fange_knife_handle_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\fange_knife_blade_damage.rvmat","DZ\weapons\melee\blade\data\fange_knife_handle_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\fange_knife_blade_destruct.rvmat","DZ\weapons\melee\blade\data\fange_knife_handle_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeMachete";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeMachete_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeMachete_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
				class CutTies_end
				{
					soundSet = "CutTies_end_SoundSet";
					id = 519;
				};
				class CutTies_loop
				{
					soundSet = "CutTies_loop_SoundSet";
					id = 520;
				};
				class shaving_knife_clean
				{
					soundSet = "shaving_knife_clean_SoundSet";
					id = 600;
				};
				class shaving_knife1
				{
					soundSet = "shaving_knife1_SoundSet";
					id = 601;
				};
				class shaving_knife2
				{
					soundSet = "shaving_knife2_SoundSet";
					id = 602;
				};
				class shaving_knife3
				{
					soundSet = "shaving_knife3_SoundSet";
					id = 603;
				};
				class shaving_knife4
				{
					soundSet = "shaving_knife4_SoundSet";
					id = 604;
				};
				class shaving_knife5
				{
					soundSet = "shaving_knife5_SoundSet";
					id = 605;
				};
				class shaving_knife6
				{
					soundSet = "shaving_knife6_SoundSet";
					id = 606;
				};
				class shaving_knife7
				{
					soundSet = "shaving_knife7_SoundSet";
					id = 607;
				};
				class shaving_knife8
				{
					soundSet = "shaving_knife8_SoundSet";
					id = 608;
				};
				class shaving_knife9
				{
					soundSet = "shaving_knife9_SoundSet";
					id = 609;
				};
				class shaving_knife10
				{
					soundSet = "shaving_knife10_SoundSet";
					id = 610;
				};
				class shaving_knife11
				{
					soundSet = "shaving_knife11_SoundSet";
					id = 611;
				};
				class shaving_knife12
				{
					soundSet = "shaving_knife12_SoundSet";
					id = 612;
				};
				class shaving_knife13
				{
					soundSet = "shaving_knife13_SoundSet";
					id = 613;
				};
				class shaving_knife14
				{
					soundSet = "shaving_knife14_SoundSet";
					id = 614;
				};
				class shaving_knife15
				{
					soundSet = "shaving_knife15_SoundSet";
					id = 615;
				};
				class shaving_knife16
				{
					soundSet = "shaving_knife16_SoundSet";
					id = 616;
				};
				class shaving_knife17
				{
					soundSet = "shaving_knife17_SoundSet";
					id = 617;
				};
				class shaving_knife18
				{
					soundSet = "shaving_knife18_SoundSet";
					id = 618;
				};
				class shaving_knife19
				{
					soundSet = "shaving_knife19_SoundSet";
					id = 619;
				};
				class shaving_knife20
				{
					soundSet = "shaving_knife20_SoundSet";
					id = 620;
				};
				class shaving_knife21
				{
					soundSet = "shaving_knife21_SoundSet";
					id = 621;
				};
				class pickup_light
				{
					soundSet = "hatchet_pickup_light_SoundSet";
					id = 796;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
				class FirefighterAxe_loop_SoundSet
				{
					soundSet = "FirefighterAxe_loop_SoundSet";
					id = 1121;
				};
				class FirefighterAxe_end_SoundSet
				{
					soundSet = "FirefighterAxe_end_SoundSet";
					id = 1122;
				};
			};
		};
	};
	class CrudeMachete: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_CrudeMachete0";
		descriptionShort = "$STR_CrudeMachete1";
		model = "\dz\weapons\melee\blade\machete_tactical.p3d";
		animClass = "Knife";
		RestrainUnlockType = 1;
		repairableWithKits[] = {4};
		repairCosts[] = {12.0};
		inventorySlot[] = {""};
		rotationFlags = 17;
		canSkinBodies = 1;
		weight = 500;
		itemSize[] = {1,4};
		itemInfo[] = {"Knife"};
		openItemSpillRange[] = {10,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\machete_tactical.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\machete_tactical.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\machete_tactical_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\machete_tactical_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\machete_tactical_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeMachete";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeMachete_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeMachete_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
				class CutTies_end
				{
					soundSet = "CutTies_end_SoundSet";
					id = 519;
				};
				class CutTies_loop
				{
					soundSet = "CutTies_loop_SoundSet";
					id = 520;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class OrientalMachete: Inventory_Base
	{
		scope = 2;
		displayName = "$STR_OrientalMachete0";
		descriptionShort = "$STR_OrientalMachete1";
		model = "\dz\weapons\melee\blade\machete_oriental.p3d";
		animClass = "Knife";
		RestrainUnlockType = 1;
		repairableWithKits[] = {4};
		repairCosts[] = {12.0};
		inventorySlot[] = {""};
		rotationFlags = 17;
		canSkinBodies = 1;
		weight = 500;
		itemSize[] = {1,4};
		itemInfo[] = {"Knife"};
		openItemSpillRange[] = {10,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 200;
					healthLevels[] = {{1.0,{"DZ\weapons\melee\blade\data\machete_oriental.rvmat"}},{0.7,{"DZ\weapons\melee\blade\data\machete_oriental.rvmat"}},{0.5,{"DZ\weapons\melee\blade\data\machete_oriental_damage.rvmat"}},{0.3,{"DZ\weapons\melee\blade\data\machete_oriental_damage.rvmat"}},{0.0,{"DZ\weapons\melee\blade\data\machete_oriental_destruct.rvmat"}}};
				};
			};
		};
		isMeleeWeapon = 1;
		suicideAnim = "onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeMachete";
				range = 1.4;
			};
			class Heavy
			{
				ammo = "MeleeMachete_Heavy";
				range = 1.4;
			};
			class Sprint
			{
				ammo = "MeleeMachete_Heavy";
				range = 3.3;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class animalSkinning_in
				{
					soundSet = "animalSkinning_in_SoundSet";
					id = 516;
				};
				class animalSkinning
				{
					soundSet = "animalSkinning_SoundSet";
					id = 517;
				};
				class animalSkinning_out
				{
					soundSet = "animalSkinning_out_SoundSet";
					id = 518;
				};
				class CutTies_end
				{
					soundSet = "CutTies_end_SoundSet";
					id = 519;
				};
				class CutTies_loop
				{
					soundSet = "CutTies_loop_SoundSet";
					id = 520;
				};
				class pickup
				{
					soundSet = "hatchet_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "woodaxe_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxycombatknife: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Knife";
		model = "\DZ\weapons\melee\blade\combatknife.p3d";
	};
};
