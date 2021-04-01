class ActionFertilizeSlotCB : ActionContinuousBaseCB
{
	private const float QUANTITY_USED_PER_SEC = 10;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousFertilizeGardenSlot(QUANTITY_USED_PER_SEC);
	}
};

class ActionFertilizeSlot: ActionContinuousBase
{
	void ActionFertilizeSlot()
	{
		m_CallbackClass = ActionFertilizeSlotCB;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionTarget = new CCTDummy;
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		return "#fertilize_slot";
	}


	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		GardenBase garden_base;
		if ( Class.CastTo(garden_base, target.GetObject()))
		{
			//string selection = garden_base.GetActionComponentName(target.GetComponentIndex());
			
			//string selection = targetObject.GetActionComponentName(target.GetComponentIndex());
			
			Slot slot;// = garden_base.GetSlotBySelection( selection );
			
			array<string> selections = new array<string>;
			garden_base.GetActionComponentNameList(target.GetComponentIndex(), selections);
			string selection;

			for (int s = 0; s < selections.Count(); s++)
			{
				//string selection = targetObject.GetActionComponentName(target.GetComponentIndex());
				selection = selections[s];
				slot = garden_base.GetSlotBySelection( selection );
				if (slot)
					break;
			}
			
			if ( garden_base.NeedsFertilization( selection ) )
			{
				if ( item.GetQuantity() > 0 )
				{
					return true;
				}
			}
		}
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		// The functionality is in the Execute event of this user action's component.
	}
};