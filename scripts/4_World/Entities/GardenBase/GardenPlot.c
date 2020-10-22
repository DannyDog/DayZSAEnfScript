class GardenPlot extends GardenBase
{
	Object 	m_ClutterCutter;
	
	void GardenPlot()
	{
		SetBaseFertility(0.75);
	}
	
	override void EEInit()
	{	
		super.EEInit();
	}	
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{				
		if ( !super.OnStoreLoad(ctx, version) )
			return false;

		if ( !m_ClutterCutter )
		{		
			m_ClutterCutter = GetGame().CreateObjectEx( "ClutterCutter6x6", GetPosition(), ECE_PLACE_ON_SURFACE );
			m_ClutterCutter.SetOrientation( GetOrientation() );
		}

		return true;
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		if (m_ClutterCutter  &&  GetGame())
		{
			GetGame().ObjectDelete(m_ClutterCutter);
			m_ClutterCutter = NULL;
		}
	}
	
	override bool IsInventoryVisible()
	{
		return true;
	}

	override int GetGardenSlotsCount()
	{
		return 9;
	}

	void RefreshSlots()
	{
		HideSelection("SeedBase_1");
		HideSelection("SeedBase_2");
		HideSelection("SeedBase_3");
		HideSelection("SeedBase_4");
		HideSelection("SeedBase_5");
		HideSelection("SeedBase_6");
		HideSelection("SeedBase_7");
		HideSelection("SeedBase_8");
		HideSelection("SeedBase_9");
	}
	
	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementStarted( Man player )
	{
		RefreshSlots();
	}
	
	override void OnHologramBeingPlaced( Man player )
	{
		RefreshSlots();
	}
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
				
		PlayerBase player_base = PlayerBase.Cast( player );
		//vector pos = player_base.GetLocalProjectionPosition();
		//vector ori = player_base.GetLocalProjectionOrientation();
			
		if ( GetGame().IsMultiplayer()  &&  GetGame().IsServer() || !GetGame().IsMultiplayer() )
		{
			// To properly move the clutter cutter from spawn position, it must be deleted and created again.
			if (m_ClutterCutter)
			{
				GetGame().ObjectDelete(m_ClutterCutter);
				m_ClutterCutter = NULL;
			}
			
			if (!m_ClutterCutter)
			{		
				m_ClutterCutter = GetGame().CreateObjectEx( "ClutterCutter6x6", GetPosition(), ECE_PLACE_ON_SURFACE );
				m_ClutterCutter.SetOrientation( orientation );
			}
		}
	}
	
	override bool CanBePlaced( Man player, vector position )
	{
		string surface_type;
		GetGame().SurfaceGetType( position[0], position[2], surface_type );
		
		return GetGame().IsSurfaceFertile(surface_type);
	}
}