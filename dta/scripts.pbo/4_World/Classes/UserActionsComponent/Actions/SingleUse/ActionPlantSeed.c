class ActionPlantSeed: ActionSingleUseBase
{
	void ActionPlantSeed()
	{
		m_MessageSuccess = "";
		m_MessageStartFail = "";
		m_MessageStart = "";
		m_MessageSuccess = "";
		m_MessageFail = "";
		m_MessageCancel = "";
		//m_Animation = "open";
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_DROPITEM_HANDS;
		m_FullBody = false;
	}
	
	override void CreateConditionComponents()  
	{		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTDummy;
	}

	override int GetType()
	{
		return AT_PLANT_SEED;
	}

	override bool HasTarget()
	{
		return true;
	}

	override string GetText()
	{
		return "#plant_seed";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		GardenBase targetObject = GardenBase.Cast( target.GetObject() );
		
		if( targetObject )
		{
			string selection = targetObject.GetActionComponentName(target.GetComponentIndex());
			
			if ( item != NULL && item.GetQuantity() > 0 && targetObject.CanPlantSeed( selection ) )
			{
				return true;
			}
		}
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Process(action_data);
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		//Process(action_data);
	}

	void Process( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		
		if ( targetObject != NULL && targetObject.IsInherited(GardenBase) )
		{
			GardenBase garden_base = GardenBase.Cast( targetObject );
			string selection = targetObject.GetActionComponentName(action_data.m_Target.GetComponentIndex());
			Slot slot = garden_base.GetSlotBySelection( selection );
			int slot_ID = slot.GetSlotId();
			
			ItemBase seed_IB = ItemBase.Cast( action_data.m_MainItem );
			
			seed_IB.SplitIntoStackMax( garden_base, slot_ID, action_data.m_Player );
		}

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};