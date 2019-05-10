class ActionAnimateSeats: ActionAnimateCarSelection
{
	override int GetType()
	{
		return AT_ANIMATE_SEATS;
	}

	override string GetText()
	{
		return "#move_seat";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		//if( !IsInReach(player, target, UAMaxDistances.DEFAULT) ) return false;

		Object targetObject = target.GetObject();
		Entity targetEnt = Entity.Cast(targetObject);
		Transport transport;
		CarScript car;
		int crewIdx;

		//string selection = targetObject.GetActionComponentName(target.GetComponentIndex());
		array<string> selections = new array<string>();
		targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);

		
		if ( !Class.CastTo(transport, targetObject) )
			return false;

		if ( Class.CastTo(car, targetEnt) )
		{
			for (int i = 0; i < selections.Count(); i++)
			{
				m_AnimSource = car.GetAnimSourceFromSelection( selections[i]) ;
				if ( m_AnimSource != "" )
				{
					//return true; //TODO:: NEED A LINK BETWEEN SeatBack and seat with crew after that we can REMOVE the return
					
					if ( m_AnimSource == "SeatDriver" )
					{
						if ( car.GetCarDoorsState( "NivaDriverDoors" ) == CarDoorState.DOORS_CLOSED || transport.CrewMember( DayZPlayerConstants.VEHICLESEAT_DRIVER ) )
							return false;

					}
					
					if ( m_AnimSource == "SeatCoDriver" )
					{
						if ( car.GetCarDoorsState( "NivaCoDriverDoors" ) == CarDoorState.DOORS_CLOSED || transport.CrewMember( DayZPlayerConstants.VEHICLESEAT_CODRIVER )  )
							return false;
					}
					
					if ( !transport.CanReachSeatFromDoors(selections[i], player.GetPosition(), 1.0) )
						return false;

					return true;
				}
			}
		}

		return false;
	}
	
	override bool CanBeUsedInVehicle()
	{
		return true;
	}
};