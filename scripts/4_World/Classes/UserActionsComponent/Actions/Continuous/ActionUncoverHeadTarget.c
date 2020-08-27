class ActionUncoverHeadTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.COVER_HEAD);
	}
};

class ActionUncoverHeadTarget: ActionContinuousBase
{
	void ActionUncoverHeadTarget()
	{
		m_CallbackClass = ActionUncoverHeadTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT,false);
	}
	
	override string GetText()
	{
		return "#uncover_players_head";
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		PlayerBase targetPlayer;
		if( Class.CastTo(targetPlayer, target.GetObject()) )
		{
			if ( IsWearingBurlap(targetPlayer) )
			{
				return true;
			}
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		//setaperture will be called from here, or from statemachine
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		
		EntityAI attachment;
		Class.CastTo(attachment, ntarget.GetInventory().FindAttachment(InventorySlots.HEADGEAR));
		
		if ( attachment && attachment.GetType() == "BurlapSackCover" )
		{
			attachment.Delete();
			EntityAI item = action_data.m_Player.GetInventory().CreateInInventory("BurlapSack");
			if(!item)
			{
				vector m4[4];
				action_data.m_Player.GetTransformWS(m4);
				InventoryLocation target_gnd = new InventoryLocation;
				target_gnd.SetGround(null, m4);
				item = GameInventory.LocationCreateEntity(target_gnd, "BurlapSack",ECE_IN_INVENTORY,RF_DEFAULT);
			}
			
			if ( item )
				MiscGameplayFunctions.TransferItemProperties(attachment,item);
			
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
	}

	bool IsWearingBurlap( PlayerBase player )
	{
		EntityAI attachment;
		Class.CastTo(attachment, player.GetInventory().FindAttachment(InventorySlots.HEADGEAR));
		if ( attachment && attachment.GetType() == "BurlapSackCover" )
		{
			return true;
		}
		return false;
	}
};