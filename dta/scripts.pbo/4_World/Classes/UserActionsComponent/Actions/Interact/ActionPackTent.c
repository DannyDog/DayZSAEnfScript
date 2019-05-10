class ActionPackTent: ActionInteractBase
{
	void ActionPackTent()
	{
		m_MessageSuccess = "I've packed tent.";
		m_MessageFail = "I cannot pack tent.";
		//m_Animation = "open";
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTParent(10);
	}
	
	override int GetType()
	{
		return AT_PACK_TENT;
	}

	override string GetText()
	{
		return "#pack_tent";
	}

#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
#endif

	override bool IsUsingProxies()
	{
		return true;
	}

	override bool HasProgress()
	{
		return false;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		Object targetParent = target.GetParent();
		
		if ( player && targetObject && targetParent )
		{
			float max_action_distance = 1; //m_MaximalActionDistance;
			if ( targetParent.IsInherited(CarTent) ) 
			{
				max_action_distance = 5.0;
			}
			else if ( targetParent.IsInherited(LargeTent) ) 
			{
				max_action_distance = 4.0;
			}
			else if ( targetParent.IsInherited(MediumTent) )
			{
				max_action_distance = 3.0;
			}
			float distance = Math.AbsInt(vector.Distance(targetParent.GetPosition(),player.GetPosition()));
			if (  distance <= max_action_distance )	
			{
				TentBase tent = TentBase.Cast( targetParent );
				if ( tent.CanBePacked() )
				{
					array<string> selections = new array<string>;
					targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);
					
					for ( int s = 0; s < selections.Count(); s++ )
					{					
						if ( selections[s] == "pack" )
						{
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
		vector target_object_pos = targetObject.GetPosition();
		
		if ( targetParent && targetParent.IsInherited(TentBase) ) 
		{
			array<string> selections = new array<string>;
			targetObject.GetActionComponentNameList(action_data.m_Target.GetComponentIndex(), selections);
			
			TentBase tent = TentBase.Cast( targetParent );
			tent.Pack( true );
			tent.SetPosition( targetParent.CoordToParent( target_object_pos ) );
			tent.SetOrientation( action_data.m_Player.GetOrientation() );
			tent.PlaceOnSurface();
		}
	}
};