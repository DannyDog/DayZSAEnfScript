class ActionDisinfectPlantCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousDisinfectPlant(UAQuantityConsumed.GARDEN_DISINFECT_PLANT);
	}
};

class ActionDisinfectPlant: ActionContinuousBase
{
	void ActionDisinfectPlant()
	{
		m_CallbackClass = ActionDisinfectPlantCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_SPRAYPLANT;
		//m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINotRuinedAndEmpty;
	}
		
	override string GetText()
	{
		return "#apply";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		PlantBase plant;
		if ( Class.CastTo(plant,  target.GetObject() ) && !item.IsDamageDestroyed() )
		{			
			if ( plant.IsGrowing()  &&  plant.NeedsSpraying() )
			{	
				if ( item.GetQuantity() > 0 )
				{
					return true;
				}
			}
		}
		
		return false;
	}

	/*override void OnEndServer( ActionData action_data )
	{
		PlantBase plant;
		if ( Class.CastTo(plant, action_data.m_Target.GetObject()) )
		{
			Param1<float> nacdata = Param1<float>.Cast( action_data.m_ActionComponent.GetACData() );
			if(nacdata)
			{
				float spray = nacdata.param1;
				plant.SprayPlant(spray);
				//SendMessageToClient(action_data.m_Player,plant.StopInfestation( nacdata.param1 ));
				action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
			}
		}
	}*/
	
	override void OnFinishProgressServer( ActionData action_data)
	{
		Object targetObject = action_data.m_Target.GetObject();
		Param1<float> nacdata = Param1<float>.Cast( action_data.m_ActionComponent.GetACData() );
		if (nacdata)
		{
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
	}
	
	override void OnFinishProgressClient( ActionData action_data)
	{
		Object targetObject = action_data.m_Target.GetObject();
		Param1<float> nacdata = Param1<float>.Cast( action_data.m_ActionComponent.GetACData() );
		if (nacdata)
		{
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		}
	}
};