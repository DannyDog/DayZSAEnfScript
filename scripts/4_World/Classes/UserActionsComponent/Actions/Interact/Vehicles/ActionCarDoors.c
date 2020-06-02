class ActionCarDoors: ActionInteractBase
{
	protected int m_CommandUIDPerCrewIdx[4];
	CarScript m_Car;
	string m_AnimSource = "";
	protected string m_CarDoorSound = "";
	protected bool m_IsOpening = true;
	
	void ActionCarDoors()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		//m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		m_Car = null;
		
		//! player inside vehicle
		if ( player && player.GetCommand_Vehicle() )
		{
			if ( Class.CastTo(m_Car, player.GetCommand_Vehicle().GetTransport()) )
			{
				int crewIdx = m_Car.CrewMemberIndex( player );
				
				//! crewIdx sanity checks and see if there is a door
				if ( crewIdx < 0 || crewIdx > 3 || m_Car.GetCarDoorsState(m_Car.GetDoorInvSlotNameFromSeatPos(crewIdx)) == CarDoorState.DOORS_MISSING )
					return false;

				m_AnimSource = m_Car.GetAnimSourceFromSelection(m_Car.GetDoorSelectionNameFromSeatPos(crewIdx));
				
				//! see if door is in reach
				if ( !m_Car.CanReachDoorsFromSeat(m_AnimSource, crewIdx) || !m_Car.IsAreaAtDoorFree( crewIdx ) )
					return false;
				
				m_CommandUID = m_CommandUIDPerCrewIdx[crewIdx];
				
				float animationPhaseInside = m_Car.GetAnimationPhase(m_AnimSource);				
				return ( m_IsOpening && animationPhaseInside <= 0.5 ) || ( !m_IsOpening && animationPhaseInside > 0.5 );
			}
		}
		else
		{
			//! reach check from outside of m_Car
			if ( !IsInReach(player, target, UAMaxDistances.DEFAULT) )
				return false;

			//! player is outside of vehicle
			if ( Class.CastTo(m_Car, target.GetParent()) )
			{
				array<string> selections = new array<string>();
				
				CarDoor m_CarDoor = CarDoor.Cast(target.GetObject());
				if (m_CarDoor)
				{
					m_CarDoor.GetActionComponentNameList(target.GetComponentIndex(), selections);
					
					for (int i = 0; i < selections.Count(); i++)
					{
						m_AnimSource = m_Car.GetAnimSourceFromSelection( selections[i]);
						if ( m_AnimSource != "" )
						{
							int idx = m_Car.GetSeatIndexFromDoor(m_AnimSource);
							if (idx != -1 && !m_Car.IsAreaAtDoorFree( idx ))
								return false;	//! player is looking at one of the doors, can't open if obstructed
							
							//! if player is in m_Car and cannot reach doors
							m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
							
							float animationPhase = m_Car.GetAnimationPhase(m_AnimSource);	
							//! is in reach, should open the door
							return ( m_IsOpening && animationPhase <= 0.5 ) || ( !m_IsOpening && animationPhase > 0.5 );
						}
						/*
						if ( m_AnimSource != "" && m_Car.IsAreaAtDoorFree( m_Car.GetSeatIndexFromDoor(m_AnimSource) ) )
						{
							//! if player is in m_Car and cannot reach doors
							m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
							
							float animationPhase = m_Car.GetAnimationPhase(m_AnimSource);	
							//! is in reach, should open the door
							return ( m_IsOpening && animationPhase <= 0.5 ) || ( !m_IsOpening && animationPhase > 0.5 );
						}
						*/
					}
				}
			}
		}
		
		return false;
	}

	override void OnStart( ActionData action_data )
	{
		if ( m_Car )
		{
			float phase;
			
			if (m_IsOpening)
				phase = 1.0;
			else
				phase = 0.0;
			
			m_Car.SetAnimationPhase( m_AnimSource, phase);
			
			if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
				SEffectManager.PlaySound(m_CarDoorSound, m_Car.GetPosition());
		}
	}
	
	override bool CanBeUsedInVehicle()
	{
		return true;
	}
	
	protected void FillCommandUIDPerCrewIdx( int crewIdx0, int crewIdx1, int crewIdx2, int crewIdx3 )
	{
		m_CommandUIDPerCrewIdx[0] = crewIdx0;
		m_CommandUIDPerCrewIdx[1] = crewIdx1;
		m_CommandUIDPerCrewIdx[2] = crewIdx2;
		m_CommandUIDPerCrewIdx[3] = crewIdx3;
	}
	
	protected void FillCommandUIDPerCrewIdx( int evenCrewIdx0, int unevenCrewIdx1 )
	{
		FillCommandUIDPerCrewIdx(evenCrewIdx0, unevenCrewIdx1, evenCrewIdx0, unevenCrewIdx1);
	}
};