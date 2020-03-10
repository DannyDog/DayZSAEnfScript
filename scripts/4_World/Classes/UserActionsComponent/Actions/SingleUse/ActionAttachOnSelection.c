class ActionAttachOnSelection: ActionSingleUseBase
{
	void ActionAttachOnSelection()
	{
	}

	override void CreateConditionComponents() 
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}
		
	override string GetText()
	{
		//return "attach on Selection";
		return "#attach";
	}
	
	override ActionData CreateActionData()
	{
		AttachActionData action_data = new AttachActionData;
		return action_data;
	}
	
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if ( super.SetupAction( player, target, item, action_data, extra_data))
		{
			if (!GetGame().IsMultiplayer() || GetGame().IsClient())
			{
				AttachActionData action_data_a = AttachActionData.Cast(action_data);
			
				EntityAI target_entity = EntityAI.Cast( target.GetObject() );
				EntityAI item_entity = item;
			
				array<string> selections = new array<string>;
				target_entity.GetActionComponentNameList(target.GetComponentIndex(), selections);

				//if ( IsInReach(player, target, UAMaxDistances.DEFAULT )) return false;	

				for (int s = 0; s < selections.Count(); s++)
				{

					int carId = InventorySlots.GetSlotIdFromString( selections[s] );
					int slotsCnt = item_entity.GetInventory().GetSlotIdCount();

					for (int i=0; i < slotsCnt; i++ )
					{
						int itmSlotId = item_entity.GetInventory().GetSlotId(i);

						if ( carId == itmSlotId )
						{
							action_data_a.m_AttSlot = itmSlotId;
							return true;
						}
					}
				}
				return false;
			}
			return true;
		}
		return false;
	}
	
	/*override void WriteToContext (ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		AttachActionData action_data_a = AttachActionData.Cast(action_data);
		ctx.Write(action_data_a.m_AttSlot);
	}
	
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		if(!action_recive_data)
		{
			action_recive_data = new AttachActionReciveData;
		}
		if (super.ReadFromContext(ctx, action_recive_data ))
		{
			AttachActionReciveData recive_data_a = Class.Cast(action_recive_data);
			if (ctx.Read(recive_data_a.m_AttSlot))
				return true;
		} 
		return false;
	}
	
	override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data)
	{
		super.HandleReciveData(action_recive_data, action_data);
		
		AttachActionReciveData recive_data_a = Class.Cast(action_recive_data);
		AttachActionData action_data_a = Class.Cast(action_data);
		
		action_data_a.m_AttSlot = recive_data_a.m_AttSlot;
	}*/
	
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		EntityAI item_entity = item;
		
		if ( target_entity && item_entity )
		{
			if ( !target_entity.GetInventory() ) return false;
			if ( !target_entity.GetInventory().CanAddAttachment( item_entity ) ) return false;

			if (GetGame().IsMultiplayer() && GetGame().IsServer() ) return true;
			
			array<string> selections = new array<string>;
			target_entity.GetActionComponentNameList(target.GetComponentIndex(), selections);

			//if ( IsInReach(player, target, UAMaxDistances.DEFAULT )) return false;

			for (int s = 0; s < selections.Count(); s++)
			{

				int carId = InventorySlots.GetSlotIdFromString( selections[s] );
				int slotsCnt = item_entity.GetInventory().GetSlotIdCount();
				EntityAI currentAttachment = target_entity.GetInventory().FindAttachment( carId );
				if (currentAttachment) 
					continue;

				for (int i=0; i < slotsCnt; i++ )
				{
					int itmSlotId = item_entity.GetInventory().GetSlotId(i);
					
					if ( carId == itmSlotId )
					{
						return true;
					}
				}
			}

		}	
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		if (GetGame().IsMultiplayer())
			return;
		
		EntityAI target_entity = EntityAI.Cast( action_data.m_Target.GetObject() );
		EntityAI item_entity = action_data.m_MainItem;
		
		AttachActionData action_data_a = AttachActionData.Cast(action_data);
		
		action_data.m_Player.PredictiveTakeEntityToTargetAttachmentEx(target_entity, item_entity, action_data_a.m_AttSlot );
		//target_entity.PredictiveTakeEntityAsAttachmentEx( item_entity, m_AttSlot );

	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		EntityAI target_entity = EntityAI.Cast( action_data.m_Target.GetObject() );
		EntityAI item_entity = action_data.m_MainItem;
		
		AttachActionData action_data_a = AttachActionData.Cast(action_data);
		
		action_data.m_Player.PredictiveTakeEntityToTargetAttachmentEx(target_entity, item_entity, action_data_a.m_AttSlot );
		//target_entity.PredictiveTakeEntityAsAttachmentEx( item_entity, m_AttSlot );

	}
}