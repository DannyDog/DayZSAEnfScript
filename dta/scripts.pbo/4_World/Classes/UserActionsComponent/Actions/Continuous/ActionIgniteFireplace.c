// BORIS V: TO BE REMOVED!

class ActionIgniteFireplaceCB : ActionContinuousBaseCB
{
	private const float TIME_TO_REPEAT_CHECK = 1;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTimeIgnite( UATimeSpent.FIREPLACE_IGNITE, TIME_TO_REPEAT_CHECK );
	}
}

class IgniteFireplaceActionData : ActionData
{
	string 	m_ReasonToCancel;
}

class ActionIgniteFireplace: ActionContinuousBase
{
	const float 	m_HandDrillDamagePerUse = 20;
	const float 	m_MatchSpentPerUse = 1;
	
	protected ref Timer m_ClutterCutterDestroyTimer;
	protected Object clutter_cutter;
	
	override ActionData CreateActionData()
	{
		ActionData action_data = new IgniteFireplaceActionData;
		return action_data;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINonRuined;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		return false;
		
		Object target_object = target.GetObject();
		EntityAI target_entity = EntityAI.Cast( target_object ); 
		
		if ( target_object && target_object.IsFireplace() && !target_entity.GetHierarchyParent() )
		{	
			FireplaceBase fireplace_target = FireplaceBase.Cast( target_object );
			
			if ( !fireplace_target.IsBurning() ) 
			{
				if ( fireplace_target.IsBarrelWithHoles() ) 		//if barrel with holes
				{
					BarrelHoles_ColorBase barrel = BarrelHoles_ColorBase.Cast( fireplace_target );
					if ( !barrel.IsOpen() )
					{
						return false;
					}
				}
				
				return true;
			}
		}
		
		return false;
	}
	
	override void OnEndServer( ActionData action_data  )
	{
		IgniteFireplaceActionData if_action_data = IgniteFireplaceActionData.Cast(action_data);
		if ( if_action_data.m_ReasonToCancel != "" )
			SendMessageToClient( if_action_data.m_Player, if_action_data.m_ReasonToCancel );
	}	

	void DestroyClutterCutterAfterTime()
	{
		m_ClutterCutterDestroyTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_ClutterCutterDestroyTimer.Run( 0.3, this, "DestroyClutterCutter", NULL, false );
	}
	
	void DestroyClutterCutter()
	{
		GetGame().ObjectDelete( clutter_cutter );
	}	
	
	bool SkipKindlingCheck()
	{
		return false;
	}
}