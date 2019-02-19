class ActionGagSelf: ActionContinuousBase
{	
	void ActionGagSelf()
	{
		m_CallbackClass = ActionCoverHeadSelfCB;
		m_MessageStartFail = "It's too torn.";
		m_MessageStart = "I have started putting sack on";
		m_MessageSuccess = "I have put sack on.";
		m_MessageFail = "I have moved and putting sack on was canceled.";
		m_MessageCancel = "I stopped putting sack on.";
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}

	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSelf;
	}

	override int GetType()
	{
		return AT_GAG_SELF;
	}

	override bool HasTarget()
	{
		return false;
	}
		
	override string GetText()
	{
		return "#gag_self";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (item.GetQuantity() > 1)
			return false;
		
		if ( !IsWearingMask(player) ) 
		{
			if ( player.FindAttachmentBySlotName( "Headgear" ) )
			{
				bool headgear_allows;
				headgear_allows = player.FindAttachmentBySlotName( "Headgear" ).ConfigGetBool( "noMask" );
				if (!headgear_allows)
				{
					return false;
				}
			}
			return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		action_data.m_Player.GetInventory().CreateInInventory("MouthRag");
		action_data.m_MainItem.TransferModifiers(action_data.m_Player);
		action_data.m_MainItem.Delete();
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}

	bool IsWearingMask( PlayerBase player)
	{
		if ( player.GetInventory().FindAttachment(InventorySlots.MASK) )
		{
			return true;
		}
		return false;
	}
};