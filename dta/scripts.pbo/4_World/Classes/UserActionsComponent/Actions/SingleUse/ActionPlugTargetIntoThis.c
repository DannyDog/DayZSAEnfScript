class ActionPlugTargetIntoThis: ActionSingleUseBase
{
	bool m_Retoggle;
	
	void ActionPlugTargetIntoThis()
	{
		m_MessageStartFail = "m_MessageStartFail";
		m_MessageStart = "m_MessageStart";
		m_MessageSuccess = "m_MessageSuccess";
		m_MessageFail = "m_MessageFail";
		m_MessageCancel = "m_MessageCancel";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_Retoggle = false;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}

	override int GetType()
	{
		return AT_PLUG_TARGET_INTO_THIS;
	}
	
	override string GetText()
	{
		return "#connect_together";
	}
	
	override bool Can( PlayerBase player, ActionTarget target, ItemBase item )
	{				
		if ( super.Can( player, target, item ) )
		{		
			if ( player.IsPlacingLocal() )
			{				
				m_Retoggle = true;
				
				player.GetHologramLocal().SetIsHidden( true );
				player.GetHologramLocal().GetProjectionEntity().HideAllSelections();	
			}
		}
		
		if ( !super.Can( player, target, item ) )
		{		
			if ( m_Retoggle )
			{				
				m_Retoggle = false;
				
				player.GetHologramLocal().SetIsHidden( false );
				player.GetHologramLocal().GetProjectionEntity().ShowAllSelections();	
			}
		}
		
		return super.Can( player, target, item );
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{		
		EntityAI target_EAI = EntityAI.Cast( target.GetObject() );
		
		if ( target_EAI  &&  item  &&  target_EAI.HasEnergyManager()  &&  item.HasEnergyManager() )
		{
			if ( !target_EAI.GetCompEM().IsPlugged()  &&  item.GetCompEM().CanReceivePlugFrom(target_EAI) )
			{
				// Check if the target_EAI is a device which is supposed to be plugged into something
				ref TIntArray cfg_actions = new TIntArray;
				g_Game.ConfigGetIntArray("cfgVehicles " +target_EAI.GetType() + " SingleUseActions", cfg_actions);	
				
				if ( cfg_actions )
				{
					for ( int i = 0;  i < cfg_actions.Count();  i++ )
					{
						int action = cfg_actions.Get(i);
						
						if ( action == AT_PLUG_THIS_INTO_TARGET )
						{
							return true;
						}
					}
				}
			}
			
			// Special case for vehicle batteries
			if ( item.IsInherited(VehicleBattery))
			{
				MetalWire metal_wire = MetalWire.Cast( item.GetCompEM().GetPluggedDevice() );
				
				if ( metal_wire  &&  metal_wire.GetCompEM().CanReceivePlugFrom(target_EAI) )
				{
					return true; // We can power the action_data.m_Target from vehicle battery because it has metal wire attached.
				}
			}
		}
		
		return false;
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		Process(action_data);
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		action_data.m_Player.PlacingCancelLocal(); // Cance advanced placement without unplugging main object from power source
		m_Retoggle = false;
	}

	void Process( ActionData action_data )
	{
		ItemBase target_IB = ItemBase.Cast( action_data.m_Target.GetObject() );
		
		if ( action_data.m_MainItem.IsInherited(VehicleBattery) )
		{
			// Car/truck batteries can have a metal wire attached through which they can power common electric appliances
			
			MetalWire metal_wire = MetalWire.Cast( action_data.m_MainItem.GetCompEM().GetPluggedDevice() );
			
			if (metal_wire)
			{
				target_IB.GetCompEM().PlugThisInto(metal_wire);
			}
		}
		else
		{
			// Everything else in general
			target_IB.GetCompEM().PlugThisInto(action_data.m_MainItem);
		}
		
		// Special case for spotlights
		if ( target_IB.IsInherited(Spotlight) )
		{
			Spotlight spotlight = Spotlight.Cast( target_IB );
			spotlight.Unfold();
		}
		
		target_IB.GetInventory().TakeEntityAsAttachment( InventoryMode.LOCAL, action_data.m_MainItem );
		action_data.m_Player.ServerDropEntity( action_data.m_MainItem );
	}
};