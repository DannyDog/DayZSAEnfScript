class ActionMineTreeCB : ActionContinuousBaseCB
{
	private const float TIME_BETWEEN_MATERIAL_DROPS_DEFAULT = 4;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousMineWood(TIME_BETWEEN_MATERIAL_DROPS_DEFAULT);
	} 
};

class ActionMineTree: ActionContinuousBase
{
	void ActionMineTree()
	{
		m_CallbackClass = ActionMineTreeCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_HACKTREE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTTree(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}
	
	override string GetText()
	{
		return "#cut_down_tree";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsServer() )
			return true;
		
		Object targetObject = target.GetObject();
		return targetObject.IsTree() && targetObject.IsCuttable();
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		// TODO switch WoodenPlank item for logs, once those are ready
		//ItemBase wooden_logs = ItemBase.Cast(GetGame().CreateObject("WoodenPlank",action_data.m_Player.GetPosition(), false));
		//wooden_logs.SetQuantity(1);
		
		// "hiding" of map item
		//action_data.m_Target.GetObject().SetOrigin("0 0 0");
	}
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		/*if (action_data && action_data.m_Target)
		{
		}*/
	}
};