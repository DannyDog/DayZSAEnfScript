class ActionLockedDoors: ActionInteractBase
{
	void ActionLockedDoors()
	{
		m_MessageSuccess = "";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		//m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override int GetType()
	{
		return AT_LOCKED_DOORS;
	}

	override string GetText()
	{
		return "#locked_door";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		//if( IsDamageDestroyed(action_data.m_Target) ) return false;
		if( !IsBuilding(target) ) return false;
		if( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;

		Building building;
		if( Class.CastTo(building, target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
			if ( doorIndex != -1 )
			{
				return building.IsDoorLocked(doorIndex);
			}
		}
		return false;
	}

	void OnExecute( ActionData action_data )
	{
		Building building;
		if( Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if( doorIndex != -1 )
			{
				building.OpenDoor(doorIndex);
			}
		}
	}

	override void OnExecuteClient( ActionData action_data )
	{
		OnExecute(action_data);
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		OnExecute(action_data);
	}
};