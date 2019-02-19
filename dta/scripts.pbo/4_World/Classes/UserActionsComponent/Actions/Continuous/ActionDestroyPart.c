class ActionDestroyPartCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.DEFAULT_DESTROY );
	}
};

class ActionDestroyPart: ActionContinuousBase
{
	void ActionDestroyPart()
	{
		m_CallbackClass = ActionDestroyPartCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;		
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}

	override int GetType()
	{
		return AT_DESTROY_PART;
	}
		
	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			ConstructionPart constrution_part = construction_action_data.GetTargetPart();
			
			if ( constrution_part )
			{
				return "#destroy" + " " + constrution_part.GetName();
			}
		}
		
		return "";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		if ( player && !player.IsLeaning() )
		{
			Object targetObject = target.GetObject();
			if ( targetObject && targetObject.CanUseConstruction() )
			{
				string part_name = targetObject.GetActionComponentName(target.GetComponentIndex());
				
				BaseBuildingBase base_building = BaseBuildingBase.Cast( targetObject );
				Construction construction = base_building.GetConstruction();		
				ConstructionPart construction_part = construction.GetConstructionPartToDestroy( part_name );
				
				if ( construction_part && base_building.IsFacingFront( player, construction_part.GetPartName() ) )
				{
					ConstructionActionData construction_action_data = player.GetConstructionActionData();
					construction_action_data.SetTargetPart( construction_part );
					
					return true;
				}
			}
		}
		
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		Construction construction = base_building.GetConstruction();
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		ConstructionPart construction_part = construction_action_data.GetTargetPart();
		
		if ( construction.CanDestroyPart( construction_part.GetPartName() ) )
		{
			//build
			construction.DestroyPart( construction_part.GetPartName(), GetType() );
			
			//add damage to tool
			action_data.m_MainItem.DecreaseHealth( UADamageApplied.DESTROY, false );
		}

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
}