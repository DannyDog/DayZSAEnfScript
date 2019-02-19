class ActionUngagSelf: ActionContinuousBase
{
	void ActionUngagSelf()
	{
		m_CallbackClass = ActionUncoverHeadSelfCB;
		m_MessageStartFail = "";
		m_MessageStart = "I have started removing the sack";
		m_MessageSuccess = "I have removed the sack.";
		m_MessageFail = "I have moved and removing sack was canceled.";
		m_MessageCancel = "I stopped removing the sack.";
	}

	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override int GetType()
	{
		return AT_UNGAG_SELF;
	}

	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "#ungag";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		if ( IsWearingGag(player) ) 
			return true;

		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{		
		EntityAI attachment;
		Class.CastTo(attachment, action_data.m_Player.GetInventory().FindAttachment(InventorySlots.MASK));
		if ( attachment && attachment.GetType() == "MouthRag" )
		{
			/*TurnItemIntoItemLambda lamb = new TurnItemIntoItemLambda(attachment, "Rag", action_data.m_Player);
			lamb.SetTransferParams(true, true, true, false,1);
			MiscGameplayFunctions.TurnItemIntoItemEx(action_data.m_Player, lamb);*/
			action_data.m_Player.DropItem(ItemBase.Cast(attachment));
		}
		//action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	
	bool IsWearingGag( PlayerBase player )
	{
		EntityAI attachment;
		Class.CastTo(attachment, player.GetInventory().FindAttachment(InventorySlots.MASK));
		if ( attachment && attachment.GetType() == "MouthRag" )
		{
			return true;
		}
		return false;
	}
};