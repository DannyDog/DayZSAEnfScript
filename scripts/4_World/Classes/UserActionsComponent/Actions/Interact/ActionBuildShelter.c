class ActionBuildShelter: ActionBuildPart
{
	void ActionBuildShelter()
	{
		m_CallbackClass = ActionBuildPartCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}
	
	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			ConstructionPart constrution_part = construction_action_data.GetCurrentBuildPart();
			
			if ( constrution_part )
			{
				string ret = "";
				switch (constrution_part.GetName())
				{
					case "leather":
						ret = "#build_shelter_leather";
					break;
					
					case "fabric":
						ret = "#build_shelter_fabric";
					break;
					
					case "stick":
						ret = "#build_shelter_stick";
					break;
				}
			}
		}
		
		return ret;
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override bool UseMainItem()
	{
		return false;
	}
	
	override bool HasProgress()
	{
		return true;
	}
	
	override bool HasAlternativeInterrupt()
	{
		return false;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if(target.GetObject() && !target.GetObject().CanUseConstructionBuild())
			return false;
		if( player.IsPlacingLocal() || player.IsPlacingServer() )
			return false;
		
		if( (!GetGame().IsMultiplayer() || GetGame().IsClient()) )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			int start_index = construction_action_data.m_PartIndex;
			if( construction_action_data.GetConstructionPartsCount() > 0 )
			{
				for(int i = 0; i < construction_action_data.GetConstructionPartsCount(); i++)
				{
					if( MiscGameplayFunctions.ComplexBuildCollideCheckClient(player, target, item ) )
					{
						return true;
					}
					else
					{
						construction_action_data.SetNextIndex();
					}
				}
				construction_action_data.m_PartIndex = start_index;
			}
			return false;
		}
		return true;
	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{
		return MiscGameplayFunctions.BuildCondition( action_data.m_Player, action_data.m_Target, action_data.m_MainItem , false );
	}
	
	override void OnStart( ActionData action_data )
	{
		super.OnStart(action_data);
		action_data.m_Player.TryHideItemInHands(true);
	}
	
	override void OnEnd( ActionData action_data )
	{
		super.OnEnd(action_data);
		action_data.m_Player.TryHideItemInHands(false);
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		Construction construction = base_building.GetConstruction();
		
		string part_name = BuildPartActionData.Cast(action_data).m_PartType;
		
		if ( !construction.IsColliding( part_name ) && construction.CanBuildPart( part_name, action_data.m_MainItem, false ) )
		{
			//build
			construction.BuildPartServer( action_data.m_Player, part_name, AT_BUILD_PART );
		}
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	
	override protected void SetBuildingAnimation( ItemBase item )
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
	}
}