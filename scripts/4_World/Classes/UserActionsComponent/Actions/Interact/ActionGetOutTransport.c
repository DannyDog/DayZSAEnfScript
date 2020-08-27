class GetOutTransportActionData : ActionData
{
	Car m_Car;
	vector m_StartLocation;
	float m_CarSpeed;
	bool m_WasJumpingOut = false;
}

class ActionGetOutTransport: ActionBase
{

	
	void ActionGetOutTransport()
	{
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		//m_HUDCursorIcon = "GetInDriver";
	}
	
	override ActionData CreateActionData()
	{
		ActionData action_data = new GetOutTransportActionData;
		return action_data;
	}


	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "#leave_vehicle";
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override bool HasProgress()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
 		Transport trans = null;
		int crew_index = -1;

		HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
		if ( vehCommand )
		{
			trans = vehCommand.GetTransport();
			if ( trans )
			{
				crew_index = trans.CrewMemberIndex( player );
				
/*According today testing (12.06.2020) this hack is no longer needed
				//Hack for NIVA - disabling jumpng out from the back seats
				Car car;
				if ( Class.CastTo(car, trans) )
				{
					if ( car.GetSpeedometer() > 8 && crew_index >= 2 && trans.GetType() == "OffroadHatchback" )
						return false;
				}
*/
				
				if ( crew_index >= 0 && trans.CrewCanGetThrough( crew_index ) && trans.IsAreaAtDoorFree( crew_index ) )
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
				GetOutTransportActionData got_action_data = GetOutTransportActionData.Cast(action_data);
				Car car;
				if ( Class.CastTo(car, trans) )
				{
					got_action_data.m_StartLocation = got_action_data.m_Player.GetPosition();
					got_action_data.m_Car = car;
					float speed = car.GetSpeedometer();
					got_action_data.m_CarSpeed = speed;
					if ( speed <= 8 )
					{
						vehCommand.GetOutVehicle();
					}
					else
					{
						got_action_data.m_WasJumpingOut = true;
						vehCommand.JumpOutVehicle();
					}
					//action_data.m_Player.GetItemAccessor().HideItemInHands(false);
					//action_data.m_Player.GetItemAccessor().OnItemInHandsChanged();
					
					GetDayZGame().GetBacklit().OnLeaveCar();		
					if ( action_data.m_Player.GetInventory() ) 
						action_data.m_Player.GetInventory().LockInventory(LOCK_FROM_SCRIPT);							
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
		if (action_data.m_State == UA_START)
		{
			if ( !action_data.m_Player.GetCommand_Vehicle() )
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
	
	override int GetActionCategory()
	{
		return AC_INTERACT;
	}
	
	override void OnEnd( ActionData action_data )
	{
		if ( action_data.m_Player.GetInventory() ) 
				action_data.m_Player.GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);
	}
	
	override void OnEndServer( ActionData action_data )
	{
		GetOutTransportActionData got_action_data = GetOutTransportActionData.Cast(action_data);
		vector endLocation = action_data.m_Player.GetPosition();
		
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		
		set<Object> result = new set<Object>;
		
		vector offset = Vector(0, 2, 0);
		
		if (DayZPhysics.RaycastRV(got_action_data.m_StartLocation, endLocation, contact_pos, contact_dir, contact_component, result, got_action_data.m_Car, action_data.m_Player, false, false, ObjIntersectView, 0.3))
			got_action_data.m_Player.SetPosition(contact_pos);

		if (got_action_data.m_WasJumpingOut)
			got_action_data.m_Player.OnJumpOutVehicleFinish(got_action_data.m_CarSpeed);
	}
};
