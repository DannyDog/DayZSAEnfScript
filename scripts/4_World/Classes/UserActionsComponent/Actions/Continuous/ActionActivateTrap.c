class ActionActivateTrapCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_DEPLOY);
	}
	
	override void InitActionComponent()
	{
		super.InitActionComponent();
		
		RegisterAnimationEvent("CraftingAction", UA_IN_CRAFTING);
	}
};

class ActionActivateTrap: ActionContinuousBase
{	
	void ActionActivateTrap()
	{
		m_CallbackClass = ActionActivateTrapCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_Sound = "craft_universal_0";
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINotPresent;
	}

	override string GetText()
	{
		return "#activate";
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
		ItemBase tgt_item = ItemBase.Cast( target.GetObject() );
		if ( tgt_item && tgt_item.IsBeingPlaced() ) return false;
		
		Object targetObject = target.GetObject();
		if ( targetObject != NULL && targetObject.IsInherited(TrapBase) ) 
		{
			TrapBase trap = TrapBase.Cast( targetObject );
			
			if ( trap.IsActivable() )
			{
				return true;
			}
		}
		
		return false;
	}
	
	override void OnStartAnimationLoop( ActionData action_data )
	{
		super.OnStartAnimationLoop( action_data );

		if ( !GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			TrapBase trap = TrapBase.Cast( action_data.m_Target.GetObject() );
			Param1<bool> play = new Param1<bool>( true );
			GetGame().RPCSingleParam( trap, SoundTypeTrap.ACTIVATING, play, true );
		}
	}
	
	override void OnEndAnimationLoop( ActionData action_data )
	{
		super.OnEndAnimationLoop( action_data );

		if ( !GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			TrapBase trap = TrapBase.Cast( action_data.m_Target.GetObject());
			Param1<bool> play = new Param1<bool>( false );
			GetGame().RPCSingleParam( trap, SoundTypeTrap.ACTIVATING, play, true );
		}
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		if ( targetObject != NULL && targetObject.IsInherited(TrapBase) ) 
		{
			TrapBase trap = TrapBase.Cast( targetObject );
			trap.StartActivate( action_data.m_Player );
		}
	}
};