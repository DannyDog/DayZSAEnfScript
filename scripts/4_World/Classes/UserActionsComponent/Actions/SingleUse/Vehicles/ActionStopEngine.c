class ActionStopEngine: ActionSingleUseBase
{
	void ActionStopEngine()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_STOPENGINE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		//m_HUDCursorIcon     = CursorIcons.LootCorpse;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText()
	{
		return "#stop_engine";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		HumanCommandVehicle vehCmd = player.GetCommand_Vehicle();
		Car car;
		
		if ( vehCmd && vehCmd.GetVehicleSeat() == DayZPlayerConstants.VEHICLESEAT_DRIVER )
		{
			Transport trans = vehCmd.GetTransport();
			if ( trans )
			{
				if ( Class.CastTo(car, trans) && car.EngineIsOn() )
				{
					//if ( car.CrewMemberIndex( player ) == DayZPlayerConstants.VEHICLESEAT_DRIVER )
					if ( car.GetSpeedometer() <= 8 )
						return true;
				}
			}
		}
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		HumanCommandVehicle vehCmd = action_data.m_Player.GetCommand_Vehicle();
		CarScript car;

		if ( vehCmd )
		{
			Transport trans = vehCmd.GetTransport();
			if ( trans )
			{
				if ( Class.CastTo(car, trans) )
				{
					car.EngineStop();
					if ( !GetGame().IsMultiplayer() )
						SEffectManager.PlaySound( car.m_EngineStopFuel, car.GetPosition() );
				}
			}
		}	
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		HumanCommandVehicle vehCmd = action_data.m_Player.GetCommand_Vehicle();
		CarScript car;

		if ( vehCmd )
		{
			Transport trans = vehCmd.GetTransport();
			if ( trans )
			{
				if ( Class.CastTo(car, trans) )
				{
					car.EngineStop();
					SEffectManager.PlaySound( car.m_EngineStopFuel, car.GetPosition() );
				}
			}
		}
	}
	
	override bool CanBeUsedInVehicle()
	{
		return true;
	}
};