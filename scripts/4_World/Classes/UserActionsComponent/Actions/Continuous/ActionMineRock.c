class ActionMineRockCB : ActionContinuousBaseCB
{
	private const float TIME_BETWEEN_MATERIAL_DROPS = 8;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousMineRock(TIME_BETWEEN_MATERIAL_DROPS);
	}
};

class ActionMineRock: ActionContinuousBase
{
	void ActionMineRock()
	{
		m_CallbackClass = ActionMineRockCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_MINEROCK;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{		
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject.IsRock() )
		{
			return true;
		}
		return false;
	}
		
	override string GetText()
	{
		return "#mine";
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};

class ActionMineRock1H : ActionMineRock
{
	void ActionMineRock1H()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_HACKTREE;
	}
}