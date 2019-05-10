class ActionNextCombinationLockDial: ActionSingleUseBase
{
	void ActionNextCombinationLockDial()
	{
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem		= new CCINonRuined;
		m_ConditionTarget 	= new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}
	
	override bool IsInstant()
	{
		return true;
	}
	
	override bool RemoveForceTargetAfterUse()
	{
		return false;
	}
	
	override int GetType()
	{
		return AT_NEXT_COMBINATION_LOCK_DIAL;
	}
	
	override string GetText()
	{
		return "#next_combination_lock_dial";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( item.IsInherited( CombinationLock ) )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			construction_action_data.SetCombinationLock( CombinationLock.Cast( item ) );

			return true;
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
		//single player
		CombinationLock combination_lock = CombinationLock.Cast( action_data.m_MainItem );
		combination_lock.SoundLockChangeDial();
	}	
	
	override void OnStartClient( ActionData action_data )
	{
		CombinationLock combination_lock = CombinationLock.Cast( action_data.m_MainItem );
		combination_lock.SoundLockChangeDial();
	}
}