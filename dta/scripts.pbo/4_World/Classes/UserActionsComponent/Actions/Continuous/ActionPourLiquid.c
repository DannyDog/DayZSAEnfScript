class ActionPourLiquidCB : ActionContinuousBaseCB
{
	private const float TIME_TO_REPEAT = 0.25;

	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityLiquidTransfer(UAQuantityConsumed.POUR_LIQUID, TIME_TO_REPEAT);
	}
	
	override void OnAnimationEvent(int pEventID)	
	{
		super.OnAnimationEvent( pEventID );
		
		switch (pEventID)
		{
			case UA_ANIM_EVENT:			
				if ( !GetGame().IsMultiplayer() || GetGame().IsServer() )
				{
					Bottle_Base vessel_in_hands = Bottle_Base.Cast( m_ActionData.m_Target.GetObject() );
					Param1<bool> play = new Param1<bool>( true );
					GetGame().RPCSingleParam( vessel_in_hands, SoundTypeBottle.POURING, play, true );
				}

			break;
		}
	}
	
	override void EndActionComponent()
	{
		super.EndActionComponent();
				
		if ( !GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			Bottle_Base target_vessel = Bottle_Base.Cast( m_ActionData.m_Target.GetObject());
			Param1<bool> play = new Param1<bool>( false );
			GetGame().RPCSingleParam( target_vessel, SoundTypeBottle.POURING, play, true );
		}
	}
};

class ActionPourLiquid: ActionContinuousBase
{
	void ActionPourLiquid()
	{
		m_CallbackClass = ActionPourLiquidCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		
		m_MessageStartFail = "It's ruined.";
		m_MessageStart = "I have started filling the bottle.";
		m_MessageSuccess = "I have finished filling the bottle..";
		m_MessageFail = "Player moved and filling the bottle was canceled.";
		m_MessageCancel = "I stopped filling the bottle.";
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}
	
	override bool HasProneException()
	{
		return true;
	}
	
	override int GetType()
	{
		return AT_POUR_LIQUID;
	}
	
	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		ItemBase item = player.GetItemInHands();
		
		return "#pour_liquid";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		ItemBase target_item = ItemBase.Cast(target.GetObject());
		if ( target_item && item && GetGame().IsServer() && GetGame().IsMultiplayer() )
			return true;
		
		if ( GetGame().IsInventoryOpen() && !player.GetLiquidTendencyDrain() )
		{
			player.SetLiquidTendencyDrain(true);
			return false;
		}
		
		if ( target_item && item && item.GetQuantity() > item.GetQuantityMin() && target_item.GetQuantity() < target_item.GetQuantityMax() && !player.GetLiquidTendencyDrain() && Liquid.CanFillContainer( target_item, item.GetLiquidType() ) && target_item.IsOpen() )
		{
			return true;
		}
		return false;
	}
		
	override void OnStartServer( ActionData action_data )
	{
		action_data.m_Player.SetLiquidTendencyDrain(false);
	}
	
	override void OnEndServer( ActionData action_data )
	{		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};