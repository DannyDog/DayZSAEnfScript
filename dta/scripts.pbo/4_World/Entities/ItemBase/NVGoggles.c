class NVGoggles extends PoweredOptic_Base
{
	bool 		m_IsLowered;
	bool 		m_InitOnSpawn;
	ItemBase 	m_Strap;
	
	void NVGoggles()
	{
		if (!m_InitOnSpawn)
		{
			m_InitOnSpawn = true;
			//RotateGoggles(false);
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		RemoveAction(ActionViewOptics);
		AddAction(ActionViewBinoculars);
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached( item, slot_name );
		
		/*if ( IsWorking() )
		{
			PlayerBase player;
			if ( PlayerBase.CastTo(player, GetHierarchyRootPlayer()) && m_Strap )
				player.SetNVGWorking(true);
		}*/
		/*bool switchon = GetCompEM().CanSwitchOn();
		bool switchoff = GetCompEM().CanSwitchOff();
		float energy = item.GetCompEM().GetEnergy();
		bool canwork = GetCompEM().CanWork();*/
		if ( GetCompEM().CanWork() && m_IsLowered )
			GetCompEM().SwitchOn();
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached( item, slot_name );
		
		/*PlayerBase player;
		if ( PlayerBase.CastTo(player, GetHierarchyRootPlayer()) && m_Strap )
			player.SetNVGWorking(false);*/
		GetCompEM().SwitchOff();
	}
	
	override void OnWasAttached ( EntityAI parent, int slot_id )
	{
		super.OnWasAttached(parent, slot_id);
		RotateGoggles(true);
		
		m_Strap = ItemBase.Cast(parent);
		
		/*PlayerBase player;
		if ( PlayerBase.CastTo(player, GetHierarchyRootPlayer()) )
		{
			if ( parent && Clothing.Cast(parent) )
			{
				Clothing.Cast(parent).UpdateNVGStatus(player);
			}
		}*/
	}
	
	override void OnWasDetached ( EntityAI parent, int slot_id )
	{
		super.OnWasDetached(parent, slot_id);
		RotateGoggles(true);
		
		m_Strap = null;
		
		PlayerBase player;
		if ( PlayerBase.CastTo(player, parent.GetHierarchyRootPlayer()) )
		{
			if ( parent && Clothing.Cast(parent) )
			{
				Clothing.Cast(parent).UpdateNVGStatus(player,false);
			}
		}
	}
	
	override void OnWorkStart()
	{
		PlayerBase player;
		if ( PlayerBase.CastTo(player, GetHierarchyRootPlayer()) && m_Strap )
			player.SetNVGWorking(true);
	}
	
	override void OnWorkStop()
	{
		PlayerBase player;
		if ( PlayerBase.CastTo(player, GetHierarchyRootPlayer()) )
			player.SetNVGWorking(false);
	}
	
	/*override void OnIsPlugged(EntityAI source_device)
	{
	}*/
	
	override bool IsWorking()
	{
		/*Print("GetCompEM() " + GetCompEM());
		Print("GetCompEM().CanWork() " + GetCompEM().CanWork());*/
		if ( GetCompEM() && GetCompEM().CanWork() )
		{
			if ( m_Strap && m_IsLowered ) //on strap
			{
				return true;
			}
			else if ( !m_Strap ) //handheld
			{
				return true;
			}
		}
		return false;
	}
	
	void LoweredCheck() //check for animation state, if another player lowered them first (or solve by synced variable)
	{
		if ( GetAnimationPhase("rotate") != m_IsLowered )
		{
			m_IsLowered = GetAnimationPhase("rotate");
		}
	}
	
	void RotateGoggles(bool state)
	{
		//if ( GetAnimationPhase("rotate") != state ) //useless?
			SetAnimationPhase("rotate",!state);
		m_IsLowered = !state;
		
		if ( GetCompEM() )
		{
			if ( !state && GetCompEM().CanWork() )
				GetCompEM().SwitchOn();
			else
				GetCompEM().SwitchOff();
		}
	}
}
