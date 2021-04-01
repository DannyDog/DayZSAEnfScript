class ActionUncoverHeadSelfCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.COVER_HEAD);
	}
};

class ActionUncoverHeadSelf: ActionContinuousBase
{
	void ActionUncoverHeadSelf()
	{
		m_CallbackClass = ActionUncoverHeadSelfCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_COVERHEAD_SELF;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}
		
	override string GetText()
	{
		return "#uncover_head";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		if ( IsWearingBurlap(player) ) 
			return true;

		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		EntityAI entity = action_data.m_Player.GetInventory().CreateInInventory("BurlapSack");
		if( !entity )
		{
			vector m4[4];
			action_data.m_Player.GetTransformWS(m4);
			InventoryLocation target_gnd = new InventoryLocation;
			target_gnd.SetGround(null, m4);
			entity = GameInventory.LocationCreateEntity(target_gnd, "BurlapSack",ECE_IN_INVENTORY,RF_DEFAULT);
		}
		
		EntityAI attachment;
		ItemBase new_item = ItemBase.Cast(entity);
		Class.CastTo(attachment, action_data.m_Player.GetInventory().FindAttachment(InventorySlots.HEADGEAR));
		if ( attachment && attachment.GetType() == "BurlapSackCover" )
		{
			if (new_item)
				MiscGameplayFunctions.TransferItemProperties(attachment,new_item,true,false,true);
			
			attachment.Delete();
		}
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}


	bool IsWearingBurlap( PlayerBase player )
	{
		EntityAI attachment;
		Class.CastTo(attachment, player.GetInventory().FindAttachment(InventorySlots.HEADGEAR));
		if ( attachment && attachment.IsInherited(BurlapSackCover) )
		{
			return true;
		}
		return false;		
	}
};