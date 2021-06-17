class ActionDisarmMineCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DISARM_MINE);
	}
}

class ActionDisarmMine: ActionContinuousBase
{
	void ActionDisarmMine()
	{
		m_CallbackClass = ActionDisarmMineCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTCursor;
	}

	override string GetText()
	{
		return "#disarm";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target )
			return false;

		TrapBase target_TB;

		if ( Class.CastTo(target_TB,  target.GetObject() ) &&  item && IsInReach(player, target, UAMaxDistances.DEFAULT) )
		{		
			if (target_TB.IsActive() && target_TB.CanBeDisarmed())
			{
				return true;
			}
		}
		return false;
	}
	
	override void OnStartAnimationLoop( ActionData action_data )
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			LandMineTrap targetMine = LandMineTrap.Cast( action_data.m_Target.GetObject() );
			Param1<bool> play = new Param1<bool>( true );
			GetGame().RPCSingleParam( targetMine, SoundTypeMine.DISARMING, play, true );
		}
	}
	
	override void OnAnimationEvent( ActionData action_data )
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			LandMineTrap targetMine = LandMineTrap.Cast( action_data.m_Target.GetObject() );
			Param1<bool> play = new Param1<bool>( true );
			GetGame().RPCSingleParam( targetMine, SoundTypeMine.DISARMING, play, true );
		}
	}
	
	override void OnEndAnimationLoop( ActionData action_data )
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			LandMineTrap targetMine = LandMineTrap.Cast( action_data.m_Target.GetObject() );
			Param1<bool> play = new Param1<bool>( false );
			GetGame().RPCSingleParam( targetMine, SoundTypeMine.DISARMING, play, true );
		}
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		TrapBase target_TB;
		Class.CastTo( target_TB, action_data.m_Target.GetObject() );
		
		ToolBase item_TB;
		Class.CastTo( item_TB, action_data.m_MainItem );
		
		int randNum;
		randNum = Math.RandomIntInclusive(0, 100);
		if ( randNum < item_TB.GetDisarmRate() )
		{
			target_TB.SetDisarmed(true); 	//Prevent detonation of explosive
			target_TB.SetHealth("", "", 0); //Effectively destroy mine
		}
		else
		{
			target_TB.OnSteppedOn( action_data.m_Player );
		}
		
		MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 2);
	}
};