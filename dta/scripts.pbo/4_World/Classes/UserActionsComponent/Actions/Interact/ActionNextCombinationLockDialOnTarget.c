class ActionNextCombinationLockDialOnTarget: ActionInteractBase
{
	void ActionNextCombinationLockDialOnTarget()
	{
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
	}

	override int GetType()
	{
		return AT_NEXT_COMBINATION_LOCK_DIAL_ON_TARGET;
	}

	override string GetText()
	{
		return "#next_combination_lock_dial";
	}

	override bool IsInstant()
	{
		return true;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			Fence fence = Fence.Cast( targetObject );
			
			if ( fence && fence.IsLocked() && !player.GetItemInHands() )
			{
				string selection = fence.GetActionComponentName( target.GetComponentIndex() );
				
				if ( selection == "wall_interact" )
				{
					ConstructionActionData construction_action_data = player.GetConstructionActionData();
					construction_action_data.SetCombinationLock( fence.GetCombinationLock() );
					
					return true;
				}
			}
		}
		
		return false;
	}
	
	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		
		//set next dial
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		construction_action_data.SetNextCombinationLockDial();
	}
	
	override void OnStartServer( ActionData action_data )
	{
		Fence fence = Fence.Cast( action_data.m_Target.GetObject() );
		if ( fence )
		{
			CombinationLock combination_lock = fence.GetCombinationLock();
			combination_lock.SoundLockChangeDial();			
		}
	}	
	
	override void OnStartClient( ActionData action_data )
	{
		Fence fence = Fence.Cast( action_data.m_Target.GetObject() );
		if ( fence )
		{
			CombinationLock combination_lock = fence.GetCombinationLock();
			combination_lock.SoundLockChangeDial();			
		}
	}	
}