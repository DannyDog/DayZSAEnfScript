class ActionDigInStashCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DIG_STASH);
	}
};

class ActionDigInStash: ActionContinuousBase
{	
	static float m_DigStashSlopeTolerance = 0.6;
	
	void ActionDigInStash()
	{
		m_CallbackClass = ActionDigInStashCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
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
		return "#bury";
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
			if ( target_IB.IsInherited(UndergroundStash) )
			{
				return false;
			}
			
			// Check surface
			string surface_type;
			vector position = target_IB.GetPosition();
			GetGame().SurfaceGetType ( position[0], position[2], surface_type );
			
			if ( target_IB.ConfigGetBool("canBeDigged") )
			{
				if ( GetGame().IsSurfaceDigable(surface_type) )
				{
					// Check slope angle
					vector posA = position + "0.5 0 0.5";
					vector posB = position + "-0.5 0 0.5";
					vector posC = position + "0.5 0 -0.5";
					vector posD = position + "-0.5 0 -0.5";
					
					array<vector> positions = new array<vector>;
					positions.Insert( posA );
					positions.Insert( posB );
					positions.Insert( posC );
					positions.Insert( posD );
					
					float difference = GetGame().GetHighestSurfaceYDifference(positions);
					
					if ( difference < m_DigStashSlopeTolerance )
					{
						return true;
					}
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
		
		ItemBase stashed_item;
		UndergroundStash stash;
		vector pos = targetEntity.GetPosition();
					
		Class.CastTo(stashed_item,  targetEntity );
		Class.CastTo(stash,  GetGame().CreateObjectEx("UndergroundStash", pos, ECE_PLACE_ON_SURFACE) );
		  
		if ( stash )
		{
			stash.PlaceOnGround();
			
			if (GameInventory.LocationCanRemoveEntity(target_IL))
			{
				action_data.m_Player.ServerTakeEntityToTargetCargo(stash, stashed_item);
			}
			else
				Print("ActionDigStash: Cannot remove targetObject=" + targetObject + " obj from current location=" + InventoryLocation.DumpToStringNullSafe(target_IL));
		}
		else
		{
			Error("ERROR! ActionDigStash: Stash not spawned!");
		}
		
		//Apply tool damage
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 17);				
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};