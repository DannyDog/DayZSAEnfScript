class ActionGagTarget: ActionContinuousBase
{	
	void ActionGagTarget()
	{
		m_CallbackClass = ActionCoverHeadTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_COVERHEAD_TARGET;
		//m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);		
	}
		
	override string GetText()
	{
		return "#gag_person";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (item.GetQuantity() > 1)
			return false;
		
		PlayerBase targetPlayer;
		Class.CastTo(targetPlayer, target.GetObject());
		if ( !IsWearingMask(targetPlayer) ) 
		{
			ItemBase headgear = ItemBase.Cast(targetPlayer.FindAttachmentBySlotName( "Headgear" ));
			if ( headgear )
			{
				bool headgear_restricted;
				bool exists = headgear.ConfigIsExisting("noMask");
				headgear_restricted = headgear.ConfigGetBool( "noMask" );
				if (headgear_restricted)
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
		PlayerBase ntarget;
		Class.CastTo(ntarget, action_data.m_Target.GetObject());
		ntarget.GetInventory().CreateInInventory("MouthRag");
		
		MouthRag m_Gag = MouthRag.Cast(ntarget.GetItemOnSlot("Mask"));
		if (m_Gag)
		{
			m_Gag.SetHealth01("", "", action_data.m_MainItem.GetHealth01("", ""));
		}
		
		action_data.m_MainItem.TransferModifiers(ntarget);
		action_data.m_MainItem.Delete();

		//action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
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