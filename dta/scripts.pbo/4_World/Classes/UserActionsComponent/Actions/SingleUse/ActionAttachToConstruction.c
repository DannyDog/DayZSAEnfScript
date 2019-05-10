class ActionAttachToConstruction: ActionSingleUseBase
{
	void ActionAttachToConstruction()
	{
		m_MessageSuccess = "I've attached the object.";
	}

	override void CreateConditionComponents() 
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
	
	override int GetType()
	{
		return AT_ATTACH_TO_CONSTRUCTION;
	}
		
	override string GetText()
	{
		return "#attach";
	}
	
	override ActionData CreateActionData()
	{
		AttachActionData action_data = new AttachActionData;
		return action_data;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		
		if ( target_entity && target_entity.CanUseConstruction() )
		{
			string selection = target_entity.GetActionComponentName( target.GetComponentIndex() );
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			int slot_id  = construction_action_data.GetAttachmentSlotFromSelection( player, target_entity, item, selection );
			
			if ( slot_id != -1 )
			{
				BaseBuildingBase base_building = BaseBuildingBase.Cast( target_entity );
				if (  base_building.CheckSlotVerticalDistance( slot_id, player ) )
				{
					construction_action_data.SetSlotId( slot_id );
					
					return true;
				}
			}
		}
		
		return false;
	}
	
	override void OnStartClient( ActionData action_data )
	{
		//set action initiator
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		construction_action_data.SetActionInitiator( action_data.m_Player );
	}
	
	protected void OnExecuteImpl( ActionData action_data )
	{
		EntityAI target_entity = EntityAI.Cast( action_data.m_Target.GetObject() );
		ItemBase item = ItemBase.Cast( action_data.m_MainItem );
		
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		int slot_id = construction_action_data.GetSlotId();
		
		if ( slot_id != -1 )
		{
			ItemBase attachment = ItemBase.Cast( target_entity.GetInventory().FindAttachment( slot_id ) );
			
			if ( attachment )
			{
				//combine
				attachment.CombineItemsClient( item );
			}
			else
			{
				action_data.m_Player.PredictiveTakeEntityToTargetAttachmentEx( target_entity, item, slot_id );
			}
		}
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		OnExecuteImpl(action_data);
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		if ( !GetGame().IsMultiplayer() )
		{
			ClearInventoryReservation(action_data);
			
			OnExecuteImpl(action_data); // single player
		}
	}
}