class ActionSplintTargetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.APPLY_SPLINT);
	}
};

class ActionSplintTarget: ActionContinuousBase
{
	void ActionSplintTarget()
	{
		m_CallbackClass = ActionSplintTargetCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_BANDAGETARGET;
		m_FullBody = true;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}
		
	override string GetText()
	{
		return "#fix_persons_fracture";
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		action_data.m_MainItem.TransferModifiers(ntarget);
		ntarget.ApplySplint();
		
		ItemBase new_item = ItemBase.Cast(ntarget.GetInventory().CreateInInventory("Splint_Applied"));
		if ( new_item )
		{
			MiscGameplayFunctions.TransferItemProperties(action_data.m_MainItem,new_item,true,false,true);
			action_data.m_MainItem.Delete();
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
		
		ntarget.m_BrokenLegState = eBrokenLegs.BROKEN_LEGS_SPLINT;
		//action_data.m_MainItem.Delete();

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		PlayerBase ntarget = PlayerBase.Cast( target.GetObject() );
		if (ntarget.m_BrokenLegState != eBrokenLegs.BROKEN_LEGS || IsWearingSplint(ntarget))
		{
			return false;
		}
		return super.ActionCondition(player, target, item);
	
	}
	
	bool IsWearingSplint( PlayerBase player )
	{
		if ( player.GetItemOnSlot("Splint_Right") )
		{
			return true;
		}
		return false;		
	}
};