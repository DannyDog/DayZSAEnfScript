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
		
		if ( Class.CastTo(target_IB, target.GetObject()) && target_IB.CanBeDigged() )
		{
			if ( player.IsPlacingLocal() )
				return false;
			
			if (target_IB.GetInventory().IsAttachment())
				return false;
			
			// here we check if a stash is nearby and block digging a new one in close proximity
			array<Object> excluded_objects = new array<Object>;
			excluded_objects.Insert(target_IB);
			array<Object> nearby_objects = new array<Object>;
			// For now we exclude an area of 2 X 2 X 2 meters
			if ( GetGame().IsBoxColliding( target_IB.GetPosition(), target_IB.GetOrientation(), "2 2 2", excluded_objects, nearby_objects) )
			{
				for (int i = 0; i < nearby_objects.Count(); i++)
				{
					if ( nearby_objects[i].IsInherited(UndergroundStash) )
						return false;
				}
			}
			
			// Check surface
			string surface_type;
			string surface_type2; //introduced to improve behaviour on problematic building floors
			vector position = target_IB.GetPosition();
			
			vector minmax[2];
			target_IB.GetCollisionBox(minmax);
			vector from = position + Vector(0,minmax[1][1],0);
			float height = Math.Max(minmax[1][1] + minmax[0][1],1.0) + 0.2;
			vector to = from - Vector(0,height,0);
			
			vector contact_pos;
			vector contact_dir;
			int contact_component;
			
			RaycastRVParams rayInput = new RaycastRVParams(from, to, target_IB);
			rayInput.type = ObjIntersectIFire;
			array<ref RaycastRVResult> results = new array<ref RaycastRVResult>;
			
			if ( DayZPhysics.RaycastRVProxy(rayInput, results) )
			{
				contact_pos = results[0].pos;
			}
			
			GetGame().SurfaceGetType3D( position[0], position[1], position[2], surface_type );
			GetGame().SurfaceGetType3D( contact_pos[0], contact_pos[1], contact_pos[2], surface_type2 );
			/*Print("position: " + position);
			Print("contact_pos: " + contact_pos);
			Print("surface_type: " + surface_type);
			Print("surface_type2: " + surface_type2);*/
			
			if ( !GetGame().IsSurfaceDigable(surface_type) || !GetGame().IsSurfaceDigable(surface_type2) )
			{
				return false;
			}
			else
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
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 10);				
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	
	override string GetAdminLogMessage( ActionData action_data )
	{
		string message = string.Format("Player %1 Dug in %2 at position %3", action_data.m_Player, action_data.m_Target.GetObject(), action_data.m_Target.GetObject().GetPosition() );
		return message;
	}
};