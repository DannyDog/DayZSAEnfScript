class FirearmActionAttachMagazine : FirearmActionBase
{	
	//-----------------------------------------------------
	// 	Action events and methods
	//-----------------------------------------------------
	void FirearmActionAttachMagazine() 
	{
	}	
	
	override int GetActionCategory()
	{
		return AC_SINGLE_USE;
	}

	override string GetText() //text game displays in HUD hint 
	{
		return "#attach";
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
		if (!super.ActionCondition( player, target, item ))
			return false;
		
		HumanCommandWeapons hcw = player.GetCommandModifier_Weapons();
		Magazine mag = Magazine.Cast(target.GetObject());	
		Weapon_Base wpn = Weapon_Base.Cast(item);	
		return mag && (player.GetWeaponManager().CanAttachMagazine(wpn,mag) || player.GetWeaponManager().CanSwapMagazine(wpn,mag)) && (!hcw || hcw.GetRunningAction() != WeaponActions.RELOAD);
	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{
		return true;
	}
	
	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		Weapon_Base wpn = Weapon_Base.Cast(action_data.m_MainItem);
		Magazine mag = Magazine.Cast(action_data.m_Target.GetObject());	
		if ( action_data.m_Player.GetWeaponManager().CanAttachMagazine(wpn,mag,false) )
			action_data.m_Player.GetWeaponManager().AttachMagazine(mag, this);
		else
			action_data.m_Player.GetWeaponManager().SwapMagazine(mag, this);
	}
	
	override bool CanBePerformedFromInventory()
	{
		return true;
	}
	
	override bool CanBePerformedFromQuickbar()
	{
		return true;
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
};


class FirearmActionAttachMagazineQuick : FirearmActionBase
{	
	void FirearmActionAttachMagazineQuick() 
	{
	}	
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		if (!super.ActionCondition( player, target, item ))
			return false;
		
		HumanCommandWeapons hcw = player.GetCommandModifier_Weapons();
		if (hcw && hcw.GetRunningAction() == WeaponActions.RELOAD)
			return false;
		
		MagazineStorage mag = MagazineStorage.Cast(player.GetWeaponManager().GetPreparedMagazine());
		
		if (!mag)
			return false;
		
		Weapon weapon = Weapon.Cast(item);
		bool isLoadedMag = false;
		
		for (int i = 0, count = weapon.GetMuzzleCount(); i < count; ++i)
			isLoadedMag |= ( mag == weapon.GetMagazine( i ) );
		
		return !isLoadedMag;
	}
	
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if( super.SetupAction( player, target, item, action_data, extra_data))
		{
			if( !GetGame().IsMultiplayer() || GetGame().IsClient() )
			{
				ActionTarget newTarget = new ActionTarget(player.GetWeaponManager().GetPreparedMagazine(), null, -1, vector.Zero, -1);
				action_data.m_Target = newTarget;
			}
			return true;
		}
		return false;
	}
	
	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		Weapon_Base wpn = Weapon_Base.Cast(action_data.m_MainItem);
		Magazine mag = Magazine.Cast(action_data.m_Target.GetObject());	
		if ( action_data.m_Player.GetWeaponManager().CanAttachMagazine(wpn,mag,false) )
			action_data.m_Player.GetWeaponManager().AttachMagazine(mag, this);
		else
			action_data.m_Player.GetWeaponManager().SwapMagazine(mag, this);
	}
	
	override bool HasTarget()
	{
		return true;
	}
	
	override bool HasProgress()
	{
		return false;
	}
	
	override typename GetInputType()
	{
		return ContinuousWeaponManipulationActionInput;
	} 
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined();
		m_ConditionTarget = new CCTSelf;
	}
};