class ActionCPRCB : ActionContinuousBaseCB
{
	private const float REPEAT_AFTER_SEC = 1;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(REPEAT_AFTER_SEC);
	}
};

class ActionCPR: ActionContinuousBase
{	
	void ActionCPR()
	{
		m_CallbackClass = ActionCPRCB;
		m_MessageStartFail = "Target moved and canceled action.";
		m_MessageStart = "Player started reusiscitating you.";
		m_MessageSuccess = "Player revived you.";
		m_MessageFail = "Player moved and CPR was canceled.";
		m_MessageCancel = "You stopped CPR";
		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CPR;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	#endif
	
	override void OnStartClient(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(true);
	}
	
	override void OnStartServer(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(true);
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}

	override int GetType()
	{
		return AT_CPR_T;
	}
		
	override string GetText()
	{
		return "#cpr";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		PlayerBase other_player = PlayerBase.Cast(target.GetObject());
		bool holds_heavy_item = item && item.IsHeavyBehaviour();
		return other_player.IsUnconscious() && !holds_heavy_item;
	}
	
	override void OnFinishProgressClient(ActionData action_data)
	{
		action_data.m_Player.GetItemAccessor().HideItemInHands(false);
	}
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		PlayerBase other_player = PlayerBase.Cast(action_data.m_Target.GetObject());
		other_player.GiveShock(5);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		action_data.m_Player.GetItemAccessor().HideItemInHands(false);
	}
	
	override void OnExecuteServer(ActionData action_data)
	{

	}

};
