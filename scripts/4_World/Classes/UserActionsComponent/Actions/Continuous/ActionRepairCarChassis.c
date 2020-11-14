class RepairCarChassisActionReciveData : ActionReciveData
{
	string m_DamageZoneRecived;
}

class RepairCarChassisActionData : ActionData
{
	string m_DamageZone;
}

class ActionRepairCarChassisCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.BASEBUILDING_REPAIR_FAST );
	}
};

class ActionRepairCarChassis: ActionContinuousBase
{
	typename m_LastValidType;
	string m_CurrentDamageZone = "";
	int m_LastValidComponentIndex = -1;
	const float MAX_ACTION_DIST = 3.0;
	
	void ActionRepairCarChassis()
	{
		m_CallbackClass = ActionRepairTentPartCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		
		//m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;// | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
		m_LockTargetOnUse = false;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined; //To change?
		m_ConditionTarget = new CCTNone; //CCTNonRuined( UAMaxDistances.BASEBUILDING ); ??
	}

	override string GetText()
	{
		return "#repair";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//m_CurrentDamageZone = "";
		Object targetObject = target.GetObject();
		Object targetParent = target.GetParent();
		CarScript car = CarScript.Cast( targetObject );
		EntityAI carEntity = EntityAI.Cast( targetObject );
		
		if ( !car || !player )
			return false;

		 //m_MaximalActionDistance;
		//float distance = Math.AbsFloat( vector.Distance( car.GetPosition(),player.GetPosition() ));

		//if ( distance <= MAX_ACTION_DIST )	
		//{
			if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
				return true;
			
			array<string> selections = new array<string>;
			PluginRepairing module_repairing;
			Class.CastTo( module_repairing, GetPlugin(PluginRepairing) );

			targetObject.GetActionComponentNameList( target.GetComponentIndex(), selections, "view");

			if (m_LastValidType != target.Type() || m_LastValidComponentIndex != target.GetComponentIndex() || m_CurrentDamageZone == "" )
			{
				string damageZone = "";
				string compName = "";

				for ( int s = 0; s < selections.Count(); s++ )
				{
					compName = selections[s];
					
					//NOTE: relevant fire geometry and view geometry selection names MUST match in order to get a valid damage zone
					if ( carEntity && DamageSystem.GetDamageZoneFromComponentName( carEntity, compName, damageZone ))
					{
						int zoneHP = car.GetHealthLevel( damageZone );
						//Print( "damageZone: " + damageZone + " hp: " + zoneHP );
						if ( zoneHP < GameConstants.STATE_RUINED && zoneHP > GameConstants.STATE_PRISTINE )
						{
							m_CurrentDamageZone = damageZone;
							m_LastValidComponentIndex = target.GetComponentIndex();
							
							vector repairPos = carEntity.GetPosition();
						
							Truck_01_Covered truck = Truck_01_Covered.Cast(car);
							//Determine if using a "Special" item for repairing
							WoodenPlank plank = WoodenPlank.Cast(item);
							Fabric tarp = Fabric.Cast(item);
						
							switch( damageZone )
							{
								case "dmgZone_front":
								{
									repairPos = car.GetFrontPointPosWS();
									break;
								}
								case "dmgZone_back":
								{
									repairPos = car.GetBackPointPosWS();
									break;
								}
								case "Fender_1_1":
								{
									repairPos = car.Get_1_1PointPosWS();
									break;
								}
								case "Fender_1_2":
								{
									repairPos = car.Get_1_2PointPosWS();
									break;
								}
								case "Fender_2_1":
								{
									repairPos = car.Get_2_1PointPosWS();
									break;
								}
								case "Fender_2_2":
								{
									repairPos = car.Get_2_2PointPosWS();
									break;
								}
								case "dmgZone_doors":	
								{
									repairPos = car.GetFrontPointPosWS();
									break;
								}
								case "BackWood":
								{
									if (!plank)
										return false;
									repairPos = truck.GetBackPointPosWS();
									break;
								}
								case "BackTarp":
								{
									if (!tarp)
										return false;
									repairPos = truck.GetBackPointPosWS();
									break;
								}
								default:
									return false;
								break;
							}
							
							//Prevent planks and tarp from repairing non related areas
							if ((tarp || plank) && (damageZone != "BackWood" && damageZone != "BackTarp"))
								return false;

							float dist = vector.Distance( repairPos, player.GetPosition() );
							if ( dist < MAX_ACTION_DIST)
								return true;
						}
					}
				}
			//}
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Object tgObject = action_data.m_Target.GetObject();
		ItemBase usedItem = action_data.m_MainItem;
		
		Fabric usedTarp = Fabric.Cast(usedItem);
		WoodenPlank usedPlank = WoodenPlank.Cast(usedItem);
		
		string damageZone = RepairCarPartActionData.Cast(action_data).m_DamageZone;
		if ( !GetGame().IsMultiplayer() )
			damageZone = m_CurrentDamageZone;

		if ( tgObject && damageZone != "" ) 
		{
			CarScript car = CarScript.Cast( tgObject );
			if ( car )
			{
/*
				PluginRepairing module_repairing;
				Class.CastTo(module_repairing, GetPlugin(PluginRepairing));
				
				PlayerBase playerPB;
				Class.CastTo(playerPB, action_data.m_Player);
				
				ItemBase item;
				Class.CastTo(item, action_data.m_MainItem );
				
				//CarScript car;
				//Class.CastTo(car, action_data.m_Target.GetObject() );
				
				module_repairing.Repair(playerPB, item, car, 0);
*/

				int newDmgLevel = car.GetHealthLevel( damageZone ) - 1;
				
				if ( newDmgLevel < 0 )
					newDmgLevel = 0;
				
				float zoneMax = car.GetMaxHealth(damageZone,"");
				
				float dmgStateValue = zoneMax * GameConstants.DAMAGE_WORN_VALUE;
				float randomValue = Math.RandomFloatInclusive( zoneMax * 0.05, zoneMax * 0.15);
				
				//TODO:: CHECK
				//GetHealthLevelValue
				switch( newDmgLevel )
				{
					case GameConstants.STATE_BADLY_DAMAGED:
						Print( zoneMax * GameConstants.DAMAGE_RUINED_VALUE );
						car.SetHealth( damageZone, "", (zoneMax * GameConstants.DAMAGE_RUINED_VALUE) + randomValue );
						break;

					case GameConstants.STATE_DAMAGED:
						Print(zoneMax * GameConstants.DAMAGE_BADLY_DAMAGED_VALUE );
						car.SetHealth( damageZone, "", (zoneMax * GameConstants.DAMAGE_BADLY_DAMAGED_VALUE) + randomValue );
						break;

					case GameConstants.STATE_WORN:
						Print(zoneMax * GameConstants.DAMAGE_DAMAGED_VALUE );
						car.SetHealth( damageZone, "", (zoneMax * GameConstants.DAMAGE_DAMAGED_VALUE) + randomValue );
						break;
					
					case GameConstants.STATE_PRISTINE:
						Print(zoneMax * GameConstants.DAMAGE_WORN_VALUE );
						car.SetHealth( damageZone, "", (zoneMax * GameConstants.DAMAGE_WORN_VALUE) + randomValue );
						break;
					
					default:
						break;
				}

				if ( usedItem.HasQuantity() )
				{
					if ( usedItem.GetQuantity() > 1 )
					{
						int qnt = usedItem.GetQuantity();
						if (usedTarp || usedPlank)
							qnt -= 1;
						else
							qnt -= usedItem.GetQuantityMax() * 0.25;
						usedItem.SetQuantity( qnt );
					}
					else
						usedItem.Delete();
				}
			}
		}
	}

	override ActionData CreateActionData()
	{
		RepairCarPartActionData action_data = new RepairCarPartActionData;
		return action_data;
	}
	
	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext( ctx, action_data );
		RepairCarPartActionData repair_action_data;

		if( HasTarget() && Class.CastTo( repair_action_data,action_data ) )
		{
			repair_action_data.m_DamageZone = m_CurrentDamageZone;
			ctx.Write(repair_action_data.m_DamageZone);
		}
	}
	
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		if( !action_recive_data )
			action_recive_data = new RepairCarPartActionReciveData;

		super.ReadFromContext( ctx, action_recive_data );
		RepairCarPartActionReciveData recive_data_repair = RepairCarPartActionReciveData.Cast( action_recive_data );

		if( HasTarget() )
		{
			string zone;
			if ( !ctx.Read( zone ) )
				return false;

			recive_data_repair.m_DamageZoneRecived = zone;
		}

		return true;
	}
	
	override void HandleReciveData( ActionReciveData action_recive_data, ActionData action_data )
	{
		super.HandleReciveData( action_recive_data, action_data );

		RepairCarPartActionReciveData recive_data_repair = RepairCarPartActionReciveData.Cast( action_recive_data );
		RepairCarPartActionData.Cast( action_data ).m_DamageZone = recive_data_repair.m_DamageZoneRecived;
	}
};