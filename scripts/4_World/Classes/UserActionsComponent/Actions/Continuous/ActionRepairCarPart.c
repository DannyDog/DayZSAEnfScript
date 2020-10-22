class RepairCarPartActionReciveData : ActionReciveData
{
	string m_DamageZoneRecived;
}

class RepairCarPartActionData : ActionData
{
	string m_DamageZone;
}

class ActionRepairCarPartCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.BASEBUILDING_REPAIR_FAST );
	}
};

class ActionRepairCarPart: ActionContinuousBase
{
	typename m_LastValidType;
	string m_CurrentDamageZone = "";
	int m_LastValidComponentIndex = -1;
	const float MAX_ACTION_DIST = 3;
	
	void ActionRepairCarPart()
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
		Object targetObject = target.GetObject();
		Object targetParent = target.GetParent();
		CarDoor carDoor = CarDoor.Cast( targetObject );
		EntityAI carPartEntity = EntityAI.Cast( targetObject );
		
		if ( !carDoor || !player )
			return false;
		
		float distance = Math.AbsFloat( vector.Distance( carDoor.GetPosition(),player.GetPosition() ));
		if ( distance > MAX_ACTION_DIST)
			return false;
		
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
			return true;
			
		//Check if item is attached to car -> If so, block repair
		if (targetParent != null)
			return false;
		
		if ( carDoor )
		{
			//Check health level of door
			int zoneHP = carDoor.GetHealthLevel( "" );
			if ( zoneHP < GameConstants.STATE_RUINED && zoneHP > GameConstants.STATE_PRISTINE )
				return true;
			
			return false;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Object tgObject = action_data.m_Target.GetObject();
		ItemBase usedItem = action_data.m_MainItem;
		
		string damageZone = RepairCarPartActionData.Cast(action_data).m_DamageZone;
		if ( !GetGame().IsMultiplayer() )
			damageZone = m_CurrentDamageZone;
		
		if ( tgObject ) 
		{
			CarDoor carDoor = CarDoor.Cast( tgObject );
			if ( carDoor )
			{
				int newDmgLevel = carDoor.GetHealthLevel( "" ) - 1;
				
				if ( newDmgLevel < 0 )
					newDmgLevel = 0;
				
				float zoneMax = carDoor.GetMaxHealth("","");
				
				float dmgStateValue = zoneMax * GameConstants.DAMAGE_WORN_VALUE;
				float randomValue = Math.RandomFloatInclusive( zoneMax * 0.05, zoneMax * 0.15);
				
				//TODO:: CHECK
				//GetHealthLevelValue
				switch( newDmgLevel )
				{
					case GameConstants.STATE_BADLY_DAMAGED:
						//Print("" + zoneMax * GameConstants.DAMAGE_RUINED_VALUE );
						carDoor.SetHealth( "", "", (zoneMax * GameConstants.DAMAGE_RUINED_VALUE) + randomValue );
						break;

					case GameConstants.STATE_DAMAGED:
						//Print("" + zoneMax * GameConstants.DAMAGE_BADLY_DAMAGED_VALUE );
						carDoor.SetHealth( "", "", (zoneMax * GameConstants.DAMAGE_BADLY_DAMAGED_VALUE) + randomValue );
						break;

					case GameConstants.STATE_WORN:
						//Print("" + zoneMax * GameConstants.DAMAGE_DAMAGED_VALUE );
						carDoor.SetHealth( "", "", (zoneMax * GameConstants.DAMAGE_DAMAGED_VALUE) + randomValue );
						break;
					
					case GameConstants.STATE_PRISTINE:
						//Print("" + zoneMax * GameConstants.DAMAGE_WORN_VALUE );
						carDoor.SetHealth( "", "", (zoneMax * GameConstants.DAMAGE_WORN_VALUE) + randomValue );
						break;
					
					default:
						break;
				}

				if ( usedItem.HasQuantity() )
				{
					if ( usedItem.GetQuantity() > 1 )
					{
						int qnt = usedItem.GetQuantity();
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