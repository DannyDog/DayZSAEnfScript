class ActionDismantleGardenPlotCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DIG_GARDEN);
	}
};

class ActionDismantleGardenPlot: ActionContinuousBase
{	
	//GardenPlot m_GardenPlot;
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;//new CCINone;
		m_ConditionTarget = new CCTCursor;
	}
	
	void ActionDismantleGardenPlot()
	{
		m_CallbackClass	= ActionDismantleGardenPlotCB;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
	}
		
	override string GetText()
	{
		return "#remove_garden_plot";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//Action not allowed if player has broken legs
		if (player.m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
			return false;
		
		GardenPlot targetPlot = GardenPlot.Cast(target.GetObject());
		
		//Keep here until sure we don't want to interract with Slots
		//9 entries to coresspond to gardenplot slot count
		/*array<bool> isPlotFree = {0, 0, 0, 0, 0, 0, 0, 0, 0}; //default all entries to false
		
		if (targetPlot)
		{
			Slot slot;
			for (int i = 0; i < targetPlot.GetSlots().Count(); i++)
			{
				slot = targetPlot.GetSlots()[i];
				if (slot)
				{
					if (!slot.GetSeed() && !slot.GetPlant())
						isPlotFree[i] = true;
				}
			}
			if (isPlotFree.Find(false) != -1)
				return false;
			return true;
		}*/
		//return false;
		//player.IsPlacingLocal
		if (targetPlot && !player.IsPlacingLocal())
			return true;
		else
			return false;
	}

	void SetupAnimation( ItemBase item )
	{
		if ( item )
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIG;
		}
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		GardenPlot targetPlot = GardenPlot.Cast(action_data.m_Target.GetObject());
		targetPlot.Delete();
		
		if (GetGame().IsServer())
			MiscGameplayFunctions.DealAbsoluteDmg(action_data.m_MainItem, 10);
	}
};
