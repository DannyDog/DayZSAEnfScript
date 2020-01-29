class ActionBreakLongWoodenStickCB : ActionContinuousBaseCB
{
	private const float TIME_TO_BREAK_STICKS = 5.0;
	
	override void CreateActionComponent()
	{
		//float adjusted_time = m_ActionData.m_Player.GetSoftSkillsManager().AdjustCraftingTime(TIME_TO_BREAK_STICKS,UASoftSkillsWeight.ROUGH_HIGH);	
		m_ActionData.m_ActionComponent = new CAContinuousTime(TIME_TO_BREAK_STICKS);
	}
};

class ActionBreakLongWoodenStick: ActionContinuousBase
{
	void ActionBreakLongWoodenStick()
	{
		m_CallbackClass = ActionBreakLongWoodenStickCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( item.IsEmpty() )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "#STR_split0";
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		BreakLongWoodenStick lambda = new BreakLongWoodenStick(action_data.m_MainItem, "WoodenStick", action_data.m_Player, 3);
		action_data.m_Player.ServerReplaceItemInHandsWithNew(lambda);
	}
};

class BreakLongWoodenStick : ReplaceItemWithNewLambdaBase
{
	int m_ItemCount;
	
	void BreakLongWoodenStick (EntityAI old_item, string new_item_type, PlayerBase player, int count) 
	{
		m_ItemCount = count; 
	}

	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		ItemBase sticks;
		Class.CastTo(sticks, new_item);
		sticks.SetQuantity(m_ItemCount);
	}
};