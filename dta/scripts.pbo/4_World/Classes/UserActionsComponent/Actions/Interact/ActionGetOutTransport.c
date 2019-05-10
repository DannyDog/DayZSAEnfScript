class ActionGetOutTransport: ActionInteractBase
{
	private Transport m_transport;
	private int       m_crewIdx;


	void ActionGetOutTransport()
	{
		m_MessageSuccess = "";
		//m_CommandUID = DayZPlayerConstants.;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		m_HUDCursorIcon = "GetInDriver";
	}


	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override int GetType()
	{
		return AT_GETOUT_TRANSPORT;
	}

	override string GetText()
	{
		return "#leave_vehicle";
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

		HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
		if ( vehCommand )
		{
			m_transport = vehCommand.GetTransport();
			if ( m_transport )
			{
				m_crewIdx = m_transport.CrewMemberIndex( player );
				if ( m_crewIdx >= 0 && m_transport.CrewCanGetThrough( m_crewIdx ) )
					return true;
			}
		}

		return false;
	}

	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
		if( vehCommand )
		{
			Transport trans = vehCommand.GetTransport();
			
			if ( trans )
			{
				Car car;
				if ( Class.CastTo(car, trans) )
				{
					float speed = car.GetSpeedometer();
					if ( speed <= 8 )
					{
						vehCommand.GetOutVehicle();
					}
					else
					{
						vehCommand.JumpOutVehicle();
					}
					//action_data.m_Player.GetItemAccessor().HideItemInHands(false);
					//action_data.m_Player.GetItemAccessor().OnItemInHandsChanged();
					
					GetDayZGame().GetBacklit().OnLeaveCar();									
				}
			}
		}
	}
	
	//TODO: quick'n'dirt hotfix, refactor!
	override void End( ActionData action_data )
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(Unhide,500,false,(action_data.m_Player));
		super.End( action_data );
	}
	
	void Unhide(PlayerBase player)
	{
		player.GetItemAccessor().HideItemInHands(false);
	}

	override void OnUpdate(ActionData action_data)
	{

		if(action_data.m_State == UA_START)
		{
			if( !action_data.m_Player.GetCommand_Vehicle().IsGettingOut() )
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
	
	override bool CanBeUsedInRestrain()
	{
		return true;
	}
	
	override bool CanBeUsedInVehicle()
	{
		return true;
	}
};
