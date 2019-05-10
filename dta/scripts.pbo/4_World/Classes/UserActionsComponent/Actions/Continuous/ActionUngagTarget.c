class ActionUngagTarget: ActionContinuousBase
{
	void ActionUngagTarget()
	{
		m_CallbackClass = ActionUncoverHeadTargetCB;
		m_MessageStartFail = "There's nothing left.";
		m_MessageStart = "Player started removing sack from your head.";
		m_MessageSuccess = "Player finished removing sack from your head.";
		m_MessageFail = "Player moved and removing sack from was canceled.";
		m_MessageCancel = "You stopped removing sack.";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override void CreateConditionComponents()  
	{
	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}

	override int GetType()
	{
		return AT_UNGAG_TARGET;
	}
	
	override string GetText()
	{
		return "#ungag_person";
	}

#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
#endif

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		PlayerBase targetPlayer;
		if( Class.CastTo(targetPlayer, target.GetObject()) )
		{
			if ( IsWearingGag(targetPlayer) && null == player.GetHumanInventory().GetEntityInHands()) 
			{
				return true;
			}
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		
		EntityAI attachment;
		Class.CastTo(attachment, ntarget.GetInventory().FindAttachment(InventorySlots.MASK));
		
		if ( attachment && attachment.GetType() == "MouthRag" )
		{
			UngagSelfLambda lamb = new UngagSelfLambda(attachment, "Rag", action_data.m_Player);
			lamb.SetTransferParams(true, true, true, false, 1);
			action_data.m_Player.ServerReplaceItemElsewhereWithNewInHands(lamb);
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
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