class ActionToggleTentOpen: ActionInteractBase
{
	void ActionToggleTentOpen()
	{
		m_MessageSuccess = "I've performed action.";
		m_MessageFail = "I cannot perform action.";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTParent(10);
	}

	override int GetType()
	{
		return AT_TOGGLE_TENT_OPEN;
	}

	override string GetText()
	{
		return "#toggle_opening";
	}
	
	override bool IsUsingProxies()
	{
		return true;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		Object targetParent = target.GetParent();

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
						if ( tent.CanToggleAnimations(selections[s]) )
						{
							//Print("nazov selekcie: " + selections[s]);
							return true;
						}
					}
				}
			}
		}
		
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		Object targetParent = action_data.m_Target.GetParent();

		if ( targetParent && targetParent.IsInherited(TentBase) ) 
		{
			array<string> selections = new array<string>;
			targetObject.GetActionComponentNameList(action_data.m_Target.GetComponentIndex(), selections);
			
			TentBase tent = TentBase.Cast( targetParent );
			for ( int s = 0; s < selections.Count(); s++)
			{
				if ( tent.CanToggleAnimations(selections[s]) )
				{
					tent.ToggleAnimation( selections[s] );
				}
			}
								
			//regenerate pathgraph
			tent.SetAffectPathgraph( true, false );
			
			if ( tent.CanAffectPathgraph() )
			{
				//Start update
				tent.RegenerateNavmesh();

			}
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