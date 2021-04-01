class ActionCreateGreenhouseGardenPlotCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DIG_GARDEN);
	}
};

class ActionCreateGreenhouseGardenPlot: ActionContinuousBase
{
	GardenPlot m_GardenPlot;
	private const float CAMERA_PITCH_THRESHOLD = -30;
	
	void ActionCreateGreenhouseGardenPlot()
	{
		m_CallbackClass		= ActionCreateGreenhouseGardenPlotCB;
		m_FullBody			= true;
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight 	= UASoftSkillsWeight.ROUGH_LOW;
	}

	override string GetText()
	{
		return "#make_garden_plot";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTCursor;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !target ) 
			return false;
		
		if ( player.IsPlacingLocal() )
			return false;

		Object target_object = target.GetObject();
		
		Land_Misc_Greenhouse greenHouse = Land_Misc_Greenhouse.Cast( target_object );
		Land_Misc_Polytunnel polytunnel = Land_Misc_Polytunnel.Cast( target_object) ;
		
		if ( target_object && ( greenHouse || polytunnel ) )
		{
			if ( !IsInReach(player, target, UAMaxDistances.DEFAULT) )
				return false;
			
			string action_selection = target_object.GetActionComponentName( target.GetComponentIndex() );
			string damage_zone;
			if ( DamageSystem.GetDamageZoneFromComponentName(EntityAI.Cast(target_object), action_selection, damage_zone) )
				return false;
			
			//Check if looking upwards
			if ( player.GetCurrentCamera() )
			{
				DayZPlayerCamera camera = player.GetCurrentCamera();
				if ( camera.GetCurrentPitch() > CAMERA_PITCH_THRESHOLD )
					return false;
			}
			
			//check if there is any gardenplot objects in the current building
			ref array<Object> nearest_objects = new array<Object>;
			ref array<CargoBase> proxy_cargos = new array<CargoBase>;
			vector pos = target_object.GetPosition();
			pos[1] = pos[1] - 1; //Lower by one meter for check if plot already present
			GetGame().GetObjectsAtPosition3D( pos, 2, nearest_objects, proxy_cargos );
	
			for ( int i = 0; i < nearest_objects.Count(); ++i )
			{
				Object object = nearest_objects.Get( i );
				
				if ( object.IsInherited( GardenPlot ) )
				{
					return false;
				}
			}
			
			return true;
		}
		
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlaceObjectActionData poActionData;
		poActionData = PlaceObjectActionData.Cast(action_data);
		EntityAI entity_for_placing = action_data.m_MainItem;
		Object targetObject = action_data.m_Target.GetObject();
		
		vector position = targetObject.GetPosition();
		
		//Depending on where we dig the required height offset is not the same
		Land_Misc_Greenhouse greenHouse = Land_Misc_Greenhouse.Cast( targetObject );
		Land_Misc_Polytunnel polytunnel = Land_Misc_Polytunnel.Cast( targetObject) ;
		
		if ( polytunnel )
			position[1] = position[1] - 1.15; //Lower Y position by roughly 1 meter to compensate for spawning location offset
		else
			position[1] = position[1] - 1.05;
		
		vector orientation = targetObject.GetOrientation();
		
		if ( GetGame().IsMultiplayer() )
		{		
			Land_Misc_Polytunnel tunnel = Land_Misc_Polytunnel.Cast(action_data.m_Target.GetObject());
			if (tunnel)
			{
				m_GardenPlot = GardenPlot.Cast( GetGame().CreateObjectEx( "GardenPlotPolytunnel", position, ECE_KEEPHEIGHT ) );
			}
			else
			{
				m_GardenPlot = GardenPlot.Cast( GetGame().CreateObjectEx( "GardenPlotGreenhouse", position, ECE_KEEPHEIGHT ) );
			}
			
			m_GardenPlot.SetOrientation( orientation );
		}
	}
}