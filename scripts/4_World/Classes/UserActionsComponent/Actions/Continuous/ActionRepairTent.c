class ActionRepairTentCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(3); //TODO add proper constant
	}
};

class ActionRepairTent: ActionContinuousBase
{
	void ActionRepairTent()
	{
		m_CallbackClass = ActionRepairTentCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined; //?
		m_ConditionTarget = new CCTParent(10);
	}

	override string GetText()
	{
		return "#repair";
	}
	
	override bool IsUsingProxies()
	{
		return true;
	}
	
	override bool HasTarget()
	{
		return true;
	}
	
	/*override bool UseMainItem()
	{
		return true;
	}
	
	override bool MainItemAlwaysInHands()
	{
		return true;
	}*/

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		Object targetParent = target.GetParent();
		string damageZone;

		if ( player && targetObject && targetParent )
		{
			float max_action_distance = 1; //m_MaximalActionDistance;
			
			if ( targetParent.IsInherited(CarTent) ) max_action_distance = 10.0;
			else if ( targetParent.IsInherited(LargeTent) ) max_action_distance = 10.0;
			else if ( targetParent.IsInherited(MediumTent) ) max_action_distance = 6.0;
			
			float distance = Math.AbsFloat(vector.Distance(targetParent.GetPosition(),player.GetPosition()));
			
			if (  distance <= max_action_distance )	
			{
				if ( targetParent.IsInherited(TentBase) ) 
				{
					array<string> selections = new array<string>;
					targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
					TentBase tent = TentBase.Cast( targetParent );
					
					for (int s = 0; s < selections.Count(); s++)
					{
						if (DamageSystem.GetDamageZoneFromComponentName(tent, selections[s], damageZone)); //NOTE: relevant fire geometry and view geometry selection names MUST match in order to get a valid damage zone
						{
							//Print("#" + s + " damageZone: " + damageZone);
							break;
						}
					}
					
					PluginRepairing module_repairing;
					Class.CastTo(module_repairing, GetPlugin(PluginRepairing));
					
					return module_repairing.CanRepair(item,tent,damageZone);
				}
			}
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		Object targetParent = action_data.m_Target.GetParent();

		if ( targetParent && targetParent.IsInherited(TentBase) ) 
		{
			string damageZone;
			array<string> selections = new array<string>;
			targetObject.GetActionComponentNameList(action_data.m_Target.GetComponentIndex(), selections);
			
			TentBase tent = TentBase.Cast( targetParent );
			for ( int s = 0; s < selections.Count(); s++)
			{
				if (DamageSystem.GetDamageZoneFromComponentName(tent, selections[s], damageZone)); //NOTE: relevant fire geometry and view geometry selection names MUST match in order to get a valid damage zone
				{
					break;
				}
			}
			
			PluginRepairing module_repairing;
			Class.CastTo(module_repairing, GetPlugin(PluginRepairing));
			
			module_repairing.Repair(action_data.m_Player,action_data.m_MainItem,tent,m_SpecialtyWeight,damageZone);
		}
	}
	
	override void OnEndServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		TentBase ntarget = TentBase.Cast( target_object );
		if( ntarget )
		{
			ntarget.SoundSynchRemoteReset();
		}
	}
};