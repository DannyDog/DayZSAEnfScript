class ActionViewBinoculars : ActionViewOptics
{
	bool m_workingRangefinder;
	override int GetType()
	{
		return AT_VIEW_BINOCULARS;
	}
		
	override string GetText()
	{
		if (!m_workingRangefinder)
			return "#Look_Through";
		return "#use_range_finder";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemOptics optic;
		if( Class.CastTo(optic, item) && !optic.IsInOptics() )
		{
			Rangefinder rangefinder = Rangefinder.Cast(item);
			if ( rangefinder && rangefinder.GetCompEM().CanWork() )
			{
				m_workingRangefinder = true;
			}
			else
			{
				m_workingRangefinder = false;
			}
			return true;
		}
		return false;
	}
	
	override void EnterOptics(ItemOptics optic, PlayerBase player)
	{
		player.SetHandheldOpticsInUse(true);
		optic.EnterOptics();
		optic.HideSelection("hide");
		if ( NVGoggles.Cast(optic) && optic.ConfigIsExisting("simpleHiddenSelections") ) //HACK
		{
			optic.SetSimpleHiddenSelectionState(0,false);
		}
		
		if ( optic.HasEnergyManager() )
		{
			PoweredOptic_Base rf = PoweredOptic_Base.Cast(optic);
			if (!rf)
				return;
			
			rf.SetPlayer( player );
			if ( GetGame().IsServer() )
				rf.GetCompEM().SwitchOn();
		}
	}
	
	override void ExitOptics(ItemOptics optic, PlayerBase player)
	{
		optic.ShowSelection("hide");
		if ( NVGoggles.Cast(optic) && optic.ConfigIsExisting("simpleHiddenSelections") ) //HACK
		{
			optic.SetSimpleHiddenSelectionState(0,true);
		}
		optic.ExitOptics();
		player.SetHandheldOpticsInUse(false);
		if ( optic.HasEnergyManager() )
		{
			PoweredOptic_Base rf = PoweredOptic_Base.Cast(optic);
			if (!rf)
				return;
			
			rf.SetPlayer( null );
			if ( GetGame().IsServer() )
				rf.GetCompEM().SwitchOff();
		}
	}
}