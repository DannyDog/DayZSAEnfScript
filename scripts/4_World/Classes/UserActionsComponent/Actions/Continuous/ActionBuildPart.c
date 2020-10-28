class BuildPartActionReciveData : ActionReciveData
{
	string m_PartType;
}

class BuildPartActionData : ActionData
{
	string m_PartType;
};

class ActionBuildPartCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time = SetCallbackDuration(m_ActionData.m_MainItem);
		m_ActionData.m_ActionComponent = new CAContinuousTime( time );
	}
	
	float SetCallbackDuration( ItemBase item )
	{
		/*switch( item.Type() )
		{
			case Pickaxe:
			case Shovel:
			case FieldShovel:
				return UATimeSpent.BASEBUILDING_CONSTRUCT_MEDIUM;
			default:
				return UATimeSpent.BASEBUILDING_CONSTRUCT_FAST;
		}*/
		return UATimeSpent.BASEBUILDING_CONSTRUCT_MEDIUM;
	}
};

class ActionBuildPart: ActionContinuousBase
{
	void ActionBuildPart()
	{
		m_CallbackClass = ActionBuildPartCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
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
				return "#build" + " " + constrution_part.GetName();
			}
		}
		
		return "";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//hack - gate
		if(target.GetObject() && (!target.GetObject().CanUseConstructionBuild() || target.GetObject().CanUseHandConstruction()))
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
						//Print("i: " + i + " | name: " + construction_action_data.GetCurrentBuildPart().GetPartName());
						return true;
					}
					else
					{
						construction_action_data.SetNextIndex();
					}
				}
				construction_action_data.m_PartIndex = start_index;
				//Print("fail | name: " + construction_action_data.GetCurrentBuildPart().GetPartName());
			}
			return false;
		}
		return true;
	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{
		return MiscGameplayFunctions.BuildCondition( action_data.m_Player, action_data.m_Target, action_data.m_MainItem , false );
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		Construction construction = base_building.GetConstruction();
		
		string part_name = BuildPartActionData.Cast(action_data).m_PartType;
		
		if ( !construction.IsColliding( part_name ) && construction.CanBuildPart( part_name, action_data.m_MainItem, true ) )
		{
			//build
			construction.BuildPartServer( action_data.m_Player, part_name, AT_BUILD_PART );
			
			//add damage to tool
			action_data.m_MainItem.DecreaseHealth( UADamageApplied.BUILD, false );
		}
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	
	override ActionData CreateActionData()
	{
		BuildPartActionData action_data = new BuildPartActionData;
		return action_data;
	}
	
	//setup
	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{	
		if( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			SetBuildingAnimation( item );
			
			if( !GetGame().IsMultiplayer() || GetGame().IsClient() )
			{
				ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
				BuildPartActionData.Cast(action_data).m_PartType = construction_action_data.GetCurrentBuildPart().GetPartName();
			}
			return true;
		}
		
		return false;
	}
	
	protected void SetBuildingAnimation( ItemBase item )
	{
		switch( item.Type() )
		{
			case Pickaxe:
			case Shovel:
			case FieldShovel:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIG;
				break;
			case Pliers:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
				break;
			case SledgeHammer:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_MINEROCK;
				break;
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
				break;
		}
	}
	
	override void WriteToContext(ParamsWriteContext ctx, ActionData action_data)
	{
		super.WriteToContext(ctx, action_data);
		
		ctx.Write(BuildPartActionData.Cast(action_data).m_PartType);
	}
	
	override bool ReadFromContext(ParamsReadContext ctx, out ActionReciveData action_recive_data )
	{
		action_recive_data = new BuildPartActionReciveData;
		super.ReadFromContext(ctx, action_recive_data);
		
		string part_type;
		if ( ctx.Read(part_type) )
		{
			BuildPartActionReciveData.Cast( action_recive_data ).m_PartType = part_type;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	override void HandleReciveData(ActionReciveData action_recive_data, ActionData action_data)
	{
		super.HandleReciveData(action_recive_data, action_data);
		
		BuildPartActionData.Cast(action_data).m_PartType = BuildPartActionReciveData.Cast( action_recive_data ).m_PartType;
	}
	
	override string GetAdminLogMessage(ActionData action_data)
	{
		return " built " + action_data.m_Target.GetObject().GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName();
	}
	
	void SetNextIndex(ActionData action_data)
	{
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		construction_action_data.SetNextIndex();
	}
}