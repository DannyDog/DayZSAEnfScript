class FirearmActionBase : ActionBase
{	
	void FirearmActionBase() 
	{
	}
	
	override int GetStanceMask(PlayerBase player)
	{
		return DayZPlayerConstants.STANCEMASK_ALL;
	}
	
	override int GetActionCategory()
	{
		return AC_SINGLE_USE;
	}
#ifndef OLD_ACTIONS
	override typename GetInputType()
	{
		return DefaultActionInput;
	}
#endif
	override bool ActionConditionContinue( ActionData action_data ) //condition for action
	{
		Weapon_Base wpn = Weapon_Base.Cast(action_data.m_MainItem);
		return !wpn.IsIdle();
	}
	
	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		action_data.m_State = UA_PROCESSING;
		bool in_iron_sights = action_data.m_Player.IsInIronsights();
		if(in_iron_sights)
		{
			action_data.m_Player.ExitSights();
		}
	}
	
	override bool CanBePerformedFromInventory()
	{
		return true;
	}
	
	override bool CanBeUsedOnBack()
	{
		return true;
	}
	
#ifndef OLD_ACTIONS
	override bool CanBeUsedRaised()
	{
		return true;
	}
#endif
	
	override void OnUpdate( ActionData action_data )
	{
		super.OnUpdate( action_data );
		Weapon_Base wpn = Weapon_Base.Cast(action_data.m_MainItem);
		
		if ( !wpn || action_data.m_Player.GetItemInHands()!=wpn || !action_data.m_Player.GetWeaponManager().IsRunning() )
		{
			End( action_data );
		}
	}
	
	override float GetProgress( ActionData action_data )
	{
		return -1;
	}
};