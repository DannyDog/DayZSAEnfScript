class ActionGetInTransport: ActionInteractBase
{
	private Transport m_transport;
	private int       m_crewIdx;


	void ActionGetInTransport()
	{
		m_MessageSuccess = "";
		//m_CommandUID = DayZPlayerConstants.;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = "GetInDriver";
	}


	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override int GetType()
	{
		return AT_GETIN_TRANSPORT;
	}

	override string GetText()
	{
		return "#get_in_vehicle";
	}

#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
#endif
	
	override bool HasProgress()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_transport = null;
		m_crewIdx   = -1;

		if ( !target )
			return false;

		if ( !Class.CastTo(m_transport, target.GetObject()) )
			return false;

		if ( player.GetCommand_Vehicle() )
			return false;

		int componentIndex = target.GetComponentIndex();
		
		m_crewIdx = m_transport.CrewPositionIndex(componentIndex);
		if ( m_crewIdx < 0 )
			return false;

		Human crew = m_transport.CrewMember( m_crewIdx );
		if ( crew )
			return false;
		
		if ( !m_transport.CrewCanGetThrough( m_crewIdx ) )
			return false;

		array<string> selections = new array<string>();

		m_transport.GetActionComponentNameList( componentIndex, selections );
		
		for ( int i = 0; i < selections.Count(); i++ )
		{
			if ( m_transport.CanReachSeatFromDoors(selections[i], player.GetPosition(), 1.0) )
				return true;
		}

		return false;
	}

	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		int seat = m_transport.GetSeatAnimationType(m_crewIdx);
		HumanCommandVehicle vehCommand = action_data.m_Player.StartCommand_Vehicle(m_transport, m_crewIdx, seat);
		if( vehCommand )
		{
			vehCommand.SetVehicleType(m_transport.GetAnimInstance());
			action_data.m_Player.GetItemAccessor().HideItemInHands(true);
			
			GetDayZGame().GetBacklit().OnEnterCar();
		}
	}

	override bool CanBeUsedInRestrain()
	{
		return true;
	}
	
	override void OnUpdate(ActionData action_data)
	{

		if(action_data.m_State == UA_START)
		{
			if( !action_data.m_Player.GetCommand_Vehicle().IsGettingIn() )
			{
				End(action_data);
			}
			//TODO add some timed check for stuck possibility
			/*else
			{
				End(action_data);
			}*/
		}
	}
};
