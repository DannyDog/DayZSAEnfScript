class ActionDismantlePartCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.DEFAULT_DECONSTRUCT );
	}
};

class ActionDismantlePart: ActionContinuousBase
{
	void ActionDismantlePart()
	{
		m_CallbackClass = ActionDismantlePartCB;
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
		return AT_DISMANTLE_PART;
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
				return "#dismantle" + " " + constrution_part.GetName();
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
				string part_name = targetObject.GetActionComponentName( target.GetComponentIndex() );
				
				BaseBuildingBase base_building = BaseBuildingBase.Cast( targetObject );
				Construction construction = base_building.GetConstruction();		
				ConstructionPart construction_part = construction.GetConstructionPartToDismantle( part_name, item );
				
				if ( construction_part && base_building.IsFacingBack( player, construction_part.GetPartName() ) )
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
		
		if ( construction.CanDismantlePart( construction_part.GetPartName(), action_data.m_MainItem ) )
		{
			//build
			construction.DismantlePart( construction_part.GetPartName(), GetType() );
			
			//add damage to tool
			action_data.m_MainItem.DecreaseHealth( UADamageApplied.DISMANTLE, false );
		}

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
		
	//setup
	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{	
		if( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			SetBuildingAnimation( item );
			
			return true;
		}
		
		return false;
	}
	
	void SetBuildingAnimation( ItemBase item )
	{
		switch( item.Type() )
		{
			case Shovel:
			case FieldShovel:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
				break;
			case Pliers:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
				break;				
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
				break;
		}
	}		
}