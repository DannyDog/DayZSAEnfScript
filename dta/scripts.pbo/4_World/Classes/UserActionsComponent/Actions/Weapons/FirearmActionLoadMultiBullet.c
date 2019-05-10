class FirearmActionLoadMultiBullet : FirearmActionBase
{	
	//-----------------------------------------------------
	// 	Action events and methods
	//-----------------------------------------------------
	void FirearmActionLoadMultiBullet() 
	{
	}	
	
	override int GetActionCategory()
	{
		return AC_CONTINUOUS;
	}
	
	override int GetType()  //returns action uid
	{
		return AT_LOAD_MULTI_BULLET_TO_WEAPON;
	}

	override string GetText() //text game displays in HUD hint 
	{
		return "#load_bullets";
	}
	
	/*string GetTargetDescription()
	{
		return "default target description";
	}*/
	
	/*protected bool ActionConditionContinue( ActionData action_data ) //condition for action
	{
		return true;
	}*/
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		Weapon_Base wpn = Weapon_Base.Cast(item);
		Magazine mag = Magazine.Cast(target.GetObject());
		
		if (wpn && mag )
			if ( player.GetWeaponManager().CanLoadBullet(wpn,mag) )
				return true;

		return false;
	}
	
	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		Magazine mag = Magazine.Cast(action_data.m_Target.GetObject());	

		action_data.m_Player.GetWeaponManager().LoadMultiBullet(mag, this);

	}
	
	override bool CanBePerformedFromInventory()
	{
		return false;
	}
	
	override bool CanBeSetFromInventory()
	{
		return false;
	}
#ifdef OLD_ACTIONS	
	override void OnContinuousCancel( ActionData action_data )
#else
	override void OnEndInput( ActionData action_data )
#endif
	{
		action_data.m_Player.GetWeaponManager().LoadMultiBulletStop();
	}

	override bool CanBePerformedFromQuickbar()
	{
		return true;
	}
	
	override bool HasProgress()
	{
		return false;
	} 
	
	// action need first have permission from server before can start
	/*bool UseAcknowledgment()
	{
		return true;
	}*/

	
	/*override int GetState( ActionData action_data )
	{
		return UA_PROCESSING;
	}*/
	
	/*override float GetProgress( ActionData action_data )
	{
		return -1;
	}*/
	
#ifndef OLD_ACTIONS
	override typename GetInputType()
	{
		return ContinuousDefaultActionInput;
	}
#endif
};