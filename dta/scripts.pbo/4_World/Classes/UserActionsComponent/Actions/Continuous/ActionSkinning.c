/*
Example of skinning config which should be inside animal's base class:
class Skinning
{
	// All classes in this scope are parsed, so they can have any name.
	class ObtainedSteaks 
	{
		item = "DeerSteakMeat"; // item to spawn
		count = 10; // How many items to spawn
		transferToolDamageCoef = 1; // Optional: How much tool's damage is transfered to item's damage.
		
		// Make sure to have only 1 of the following quantity paramenter
		quantity = 100; // Optional: Set item's quantity
		quantityCoef = 1; // Optional: Set item's quantity (in coefficient)
		quantityMinMax[] = {100, 200}; // Optional: Set item's quantity within min/max values
		quantityMinMaxCoef[] = {0, 1}; // Optional: Set item's quantity (in coefficient) within min/max values
	};
};
*/

class ActionSkinningCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.SKIN );
	}
};

class ActionSkinning: ActionContinuousBase
{	
	void ActionSkinning()
	{
		m_CallbackClass = ActionSkinningCB;
		m_MessageStartFail = "The blade is not sharp enough";
		m_MessageStart = "I have started skinning the target.";
		m_MessageSuccess = "I have skinned the target.";
		m_MessageFail = "I have moved and skinning was canceled.";
		m_MessageCancel = "I stopped skinning the target.";
		//m_Animation = "EAT";
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ANIMALSKINNING;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTDummy( );	
	}

	override int GetType()
	{
		return AT_SKINNING;
	}
		
	override string GetText()
	{
		return "#skin";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject != NULL )
		{
			if ( targetObject.CanBeSkinned() && !targetObject.IsAlive() )
			{
				EntityAI target_EAI;
				Class.CastTo(target_EAI,  targetObject );
				
				if (!GetGame().IsServer()) // Temporal hackfix for skinning not working in multiplayer. Waiting for DAYZ-28269 to be resolved.
					return true;
				
				if ( target_EAI.CanBeSkinnedWith(item) ) 
				{
					return true;
				}
			}
		}
		
		return false;
	}

	// Spawns the loot according to the Skinning class in the dead agent's config
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		
		// Prepare to read config variables
		string item_to_spawn;
		string cfg_skinning_organ_class;
		
		// Mark the body as skinned to forbid another skinning action on it
		EntityAI body;
		Class.CastTo(body,  targetObject );
		vector body_pos = body.GetPosition();
		body.SetAsSkinned();
		
		if (body.IsInherited(PlayerBase))
		{
			// This section drops all clothes (and attachments) from the dead player before deleting their body
			PlayerBase body_PB = PlayerBase.Cast(body);
			
			if (body_PB.IsRestrained())
			{
				MiscGameplayFunctions.TransformRestrainItem(body_PB.GetHumanInventory().GetEntityInHands(), null, action_data.m_Player, body_PB);
				/*
				EntityAI item_in_hands = action_data.m_MainItem;
				body_PB.SetRestrained(false);
				string new_item_name = MiscGameplayFunctions.ObtainRestrainItemTargetClassname(item_in_hands);			
				MiscGameplayFunctions.TurnItemInHandsIntoItemEx(body_PB, new UnrestrainSelfPlayer(item_in_hands, new_item_name));
				*/
			}
				
			
			DropEquipAndDestroyRootLambda lambda(body_PB, "", action_data.m_Player);
			action_data.m_Player.ServerReplaceItemWithNew(lambda);
		}
		else
		{
			GetGame().ObjectDelete(body); // Temporal deletion of the body
		}
		
		// clutter cutter removed due to issues with audio it causes when players steps on it.
		//Object cutter = GetGame().CreateObject( "ClutterCutter2x2", body_pos, false ); // clutter cutter to free space on ground for organs.
		
		// Get config path to the animal
		string cfg_animal_class_path = "cfgVehicles " + body.GetType() + " " + "Skinning ";
		
		// Getting item type from the config
		int child_count = g_Game.ConfigGetChildrenCount( cfg_animal_class_path );
		
		// Parsing of the 'Skinning' class in the config of the dead body
		for ( int i1 = 0; i1 < child_count; i1++ )
		{
			// To make configuration as convenient as possible, all classes are parsed and parameters are read
			g_Game.ConfigGetChildName(cfg_animal_class_path, i1, cfg_skinning_organ_class); // out cfg_skinning_organ_class
			cfg_skinning_organ_class = cfg_animal_class_path + cfg_skinning_organ_class + " ";
			g_Game.ConfigGetText(cfg_skinning_organ_class + "item", item_to_spawn); // out item_to_spawn
			
			if ( item_to_spawn != "" ) // Makes sure to ignore incompatible parameters in the Skinning class of the agent
			{
				// Spawning items in action_data.m_Player's inventory
				int item_count = g_Game.ConfigGetInt( cfg_skinning_organ_class + "count" );
				
				for ( int i2 = 0; i2 < item_count; i2++ )
				{
					ItemBase spawn_result = CreateOrgan( action_data.m_Player, body_pos, item_to_spawn, cfg_skinning_organ_class, action_data.m_MainItem );
					action_data.m_MainItem.DecreaseHealth(0.1); // wear out
				}
			}
		}	
		
		PluginLifespan module_lifespan = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
		module_lifespan.UpdateBloodyHandsVisibility( action_data.m_Player, true );
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}

	// Spawns an organ defined in the given config
	ItemBase CreateOrgan( PlayerBase player, vector body_pos, string item_to_spawn, string cfg_skinning_organ_class, ItemBase tool)
	{
		// Create item from config
		ItemBase added_item;
		vector pos_rnd = body_pos + Vector(Math.RandomFloat01() - 0.5, 0, Math.RandomFloat01() - 0.5);
		Class.CastTo(added_item,  GetGame().CreateObject( item_to_spawn, pos_rnd, false ) );
		
		// Check if skinning is configured for this body
		if (!added_item)
			return NULL;
		
		// Set randomized position
		added_item.PlaceOnSurface();
		
		// Set item's quantity from config, if it's defined there.
		float item_quantity = 0;
		array<float> quant_min_max = new array<float>;
		array<float> quant_min_max_coef = new array<float>;
		
		GetGame().ConfigGetFloatArray( cfg_skinning_organ_class + "quantityMinMax", quant_min_max);
		GetGame().ConfigGetFloatArray( cfg_skinning_organ_class + "quantityMinMaxCoef", quant_min_max_coef);
		
		
		// Read config for quantity value
		if (quant_min_max.Count() > 0)
		{
			float soft_skill_manipulated_value = ( quant_min_max.Get(0)+ quant_min_max.Get(1) ) / 2;
			float min_quantity = player.GetSoftSkillsManager().AddSpecialtyBonus( soft_skill_manipulated_value, this.GetSpecialtyWeight() );
			item_quantity = Math.RandomFloat(min_quantity, quant_min_max.Get(1));
		}
		
		if (quant_min_max_coef.Count() > 0)
		{
			float coef = Math.RandomFloat(quant_min_max_coef.Get(0), quant_min_max_coef.Get(1));
			item_quantity = added_item.GetQuantityMax() * coef;
		}
		
		if ( GetGame().ConfigGetFloat( cfg_skinning_organ_class + "quantity" ) > 0 )
			item_quantity = g_Game.ConfigGetFloat( cfg_skinning_organ_class + "quantity" );
		
		if ( GetGame().ConfigGetFloat( cfg_skinning_organ_class + "quantityCoef" ) > 0 )
		{
			float coef2 = g_Game.ConfigGetFloat( cfg_skinning_organ_class + "quantityCoef" );
			item_quantity = added_item.GetQuantityMax() * coef2;
		}
		
		if ( item_quantity > 0 )
		{
			item_quantity = Math.Round(item_quantity);
			added_item.SetQuantity( item_quantity, false );
		}
		
		// Transfer tool's damage to the item's condition
		float item_apply_tool_damage_coef = GetGame().ConfigGetFloat( cfg_skinning_organ_class + "transferToolDamageCoef" );
		
		if ( item_apply_tool_damage_coef > 0 )
		{
			float tool_dmg_coef = 1 - tool.GetHealth01();
			float organ_dmg_coef = tool_dmg_coef * item_apply_tool_damage_coef;
			added_item.DecreaseHealthCoef( organ_dmg_coef );
		}
		
		added_item.InsertAgent(eAgents.SALMONELLA, 1);
		return added_item;
	}
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		super.OnFinishProgressClient( action_data );
		
		if ( action_data.m_Target ) 
		{
			Object target_obj = action_data.m_Target.GetObject();
			
			if ( target_obj.IsKindOf( "Animal_CapreolusCapreolus" ) || target_obj.IsKindOf( "Animal_CapreolusCapreolusF" ) || target_obj.IsKindOf( "Animal_CervusElaphus" ) || target_obj.IsKindOf( "Animal_CervusElaphusF" ) )
			{
				GetGame().GetAnalyticsClient().OnActionFinishedGutDeer();
			}
		}
	}
};