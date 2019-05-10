class ActionDialCombinationLockOnTargetCB : ActionContinuousBaseCB
{
	private const float REPEAT_AFTER_SEC = 0.5;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(REPEAT_AFTER_SEC);
	}
}

class ActionDialCombinationLockOnTarget: ActionContinuousBase
{
	void ActionDialCombinationLockOnTarget()
	{
		m_CallbackClass = ActionDialCombinationLockOnTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;		
		m_MessageStartFail = "I have failed the tunning.";
		m_MessageStart = "I have started the tunning.";
		m_MessageFail = "I have failed the tunning.";
		m_MessageCancel = "I have stopped the tunning.";
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINotPresent;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
	}
	
	override bool HasProneException()
	{
		return true;
	}
	
	override int GetType()
	{
		return AT_DIAL_COMBINATION_LOCK_ON_TARGET;
	}

	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		string combination_lock_text;
		
		if ( player )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			combination_lock_text = construction_action_data.GetDialNumberText();
		}		

		return "#dial_combination_lock" + " " + combination_lock_text;	
	}

#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
#endif

	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			Fence fence = Fence.Cast( targetObject );
			
			if ( fence && fence.IsLocked() )
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

	override void OnFinishProgressServer( ActionData action_data )
	{	
		//set dialed number
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		CombinationLock combination_lock =  construction_action_data.GetCombinationLock();
		combination_lock.DialNextNumber( construction_action_data.GetDialIndex() );		

		//check for unlock state
		if ( !combination_lock.IsLockedOnGate() )
		{
			EntityAI target_entity = EntityAI.Cast( action_data.m_Target.GetObject() );
			combination_lock.Unlock( target_entity );
		}
	}
}