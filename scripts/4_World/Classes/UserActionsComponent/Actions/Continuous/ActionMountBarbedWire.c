class ActionMountBarbedWireCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_CONSTRUCT);
	}
};

class ActionMountBarbedWire: ActionContinuousBase
{
	float m_DamageAmount;
	string m_SlotName;
	
	void ActionMountBarbedWire()
	{
		m_CallbackClass = ActionMountBarbedWireCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		
		m_DamageAmount = 2;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}
		
	override string GetText()
	{
		return "#mount";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		
		if ( targetObject && targetObject.CanUseConstruction() && targetObject.CanUseConstructionBuild() )
		{
			BaseBuildingBase base_building = BaseBuildingBase.Cast( targetObject );
			
			string selection = targetObject.GetActionComponentName( target.GetComponentIndex() );
			
			if ( selection.Length() > 0 )
			{
				BarbedWire barbed_wire = BarbedWire.Cast( base_building.FindAttachmentBySlotName( selection ) );
				if ( barbed_wire && !barbed_wire.IsMounted() && !barbed_wire.IsRuined() )
				{
					m_SlotName = selection;
					
					return true;
				}
			}			
		}
		
		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data )
	{	
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		BarbedWire barbed_wire = BarbedWire.Cast( base_building.FindAttachmentBySlotName( m_SlotName ) );
		
		//mount and refresh parent
		barbed_wire.SetMountedState( true );
		base_building.SetHealth(m_SlotName,"Health",barbed_wire.GetHealth("","Health")); //attachment slot names and damagezone names must match
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
}