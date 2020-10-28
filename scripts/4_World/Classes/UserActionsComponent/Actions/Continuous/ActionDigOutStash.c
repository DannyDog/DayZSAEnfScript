class ActionDigOutStashCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DIG_STASH);
	}
};

class ActionDigOutStash: ActionContinuousBase
{	
	void ActionDigOutStash()
	{
		m_CallbackClass = ActionDigOutStashCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGUPCACHE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}

	override string GetText()
	{
		return "#dig_stash";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemBase target_IB;
		
		// Check if player is standing on terrain
		vector plr_pos = player.GetPosition();
		float height = GetGame().SurfaceY(plr_pos[0], plr_pos[2]);
		height = plr_pos[1] - height;
		
		if ( height > 0.2 )
			return false; // Player is not standing on ground
		
		if ( Class.CastTo(target_IB, target.GetObject()) )
		{			
			if ( target_IB.ConfigGetBool("canBeDigged") )
			{
				if ( target_IB.IsInherited(UndergroundStash) )
				{
					return true;
				}
			}
		}
		
		return false;
	}

	override void OnExecuteClient( ActionData action_data )
	{
		super.OnExecuteClient( action_data );
		
		SpawnParticleShovelRaise( action_data );
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		super.OnExecuteServer( action_data );
		
		if ( !GetGame().IsMultiplayer() ) // Only in singleplayer
		{
			SpawnParticleShovelRaise( action_data );
		}
	}
	
	void SpawnParticleShovelRaise( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;
		Particle.PlayOnObject( ParticleList.DIGGING_STASH, player );
	}
	
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		EntityAI targetEntity = EntityAI.Cast(targetObject);
		UndergroundStash target_stash;
		if (!targetEntity)
		{
			Error("ActionDigStash - Cannot get inventory of targetObject=" + targetObject);
			return;
		}
		
		InventoryLocation target_IL = new InventoryLocation;
		if (!targetEntity.GetInventory().GetCurrentInventoryLocation(target_IL))
		{
			Error("ActionDigStash: Cannot get inventory location of targetObject=" + targetObject);
			return;
		}
		
		// Dig out of stash
		if ( Class.CastTo(target_stash, targetEntity) )
		{
			ItemBase chest = target_stash.GetStashedItem();
			
			if (chest)
			{
				DigOutStashLambda lambda(target_stash, "", action_data.m_Player);
				action_data.m_Player.ServerReplaceItemWithNew(lambda);
			}
			else
				g_Game.ObjectDelete( target_stash );
		}

		//Apply tool damage
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 17);		
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};

class DigOutStashLambda : DropEquipAndDestroyRootLambda
{
	void DigOutStashLambda (EntityAI old_item, string new_item_type, PlayerBase player)
	{ }

	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);
	}
};