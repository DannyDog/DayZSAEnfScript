class XmasLights extends Inventory_Base
{
	private ItemBase m_AttachedTo = NULL;
	
	void XmasLights()
	{
		TurnOffItem( this );
	}

	override void OnWorkStart()
	{
		TurnOnItem( m_AttachedTo );
		TurnOnItem( this );
	}

	override void OnWorkStop()
	{
		TurnOffItem( m_AttachedTo );
		TurnOffItem( this );
	}

	void AttachToObject(ItemBase parent)
	{
		SetPilotLight( false );	
		
		m_AttachedTo = parent;
		TurnOnItem( parent );

		if( GetCompEM().IsPlugged() )
		{
			parent.SetAnimationPhase( "Cord_plugged", 0);
			parent.SetAnimationPhase( "Cord_folded", 1);
		}
		else
		{
			parent.SetAnimationPhase( "Cord_plugged", 1);
			parent.SetAnimationPhase( "Cord_folded", 0);
		}
	}

	void DetachFromObject(ItemBase parent)
	{
		m_AttachedTo = NULL;
		HideOnItem( parent );
		TurnOnItem( this );
		
		GetCompEM().UnplugThis();
	}

	void TurnOnItem(ItemBase item)
	{
		if ( item != NULL )
		{
			if ( GetCompEM().IsWorking() )
			{
				item.SetObjectMaterial( 0, "dz\\gear\\camping\\data\\christmas_lights_red_on.rvmat" );
				item.SetObjectMaterial( 1, "dz\\gear\\camping\\data\\christmas_lights_green_on.rvmat" );
				item.SetObjectMaterial( 2, "dz\\gear\\camping\\data\\christmas_lights_blue_on.rvmat" );
				item.SetObjectMaterial( 3, "dz\\gear\\camping\\data\\christmas_lights_yellow_on.rvmat" );
				item.SetObjectTexture( 0, "dz\\gear\\camping\\data\\christmas_lights_string_ca.paa" );
				item.SetObjectTexture( 1, "dz\\gear\\camping\\data\\christmas_lights_string_ca.paa" );
				item.SetObjectTexture( 2, "dz\\gear\\camping\\data\\christmas_lights_string_ca.paa" );
				item.SetObjectTexture( 3, "dz\\gear\\camping\\data\\christmas_lights_string_ca.paa" );
				item.SetPilotLight(true);	
			}
			else
			{
				TurnOffItem( item );
			}
		}
	}

	void TurnOffItem(ItemBase item)
	{
		if ( item != NULL )
		{
			item.SetObjectMaterial( 0, "dz\\gear\\camping\\data\\christmass_ligths_string.rvmat" );
			item.SetObjectMaterial( 1, "dz\\gear\\camping\\data\\christmass_ligths_string.rvmat" );
			item.SetObjectMaterial( 2, "dz\\gear\\camping\\data\\christmass_ligths_string.rvmat" );
			item.SetObjectMaterial( 3, "dz\\gear\\camping\\data\\christmass_ligths_string.rvmat" );
			item.SetObjectTexture( 0, "dz\\gear\\camping\\data\\christmas_lights_string_ca.paa" );
			item.SetObjectTexture( 1, "dz\\gear\\camping\\data\\christmas_lights_string_ca.paa" );
			item.SetObjectTexture( 2, "dz\\gear\\camping\\data\\christmas_lights_string_ca.paa" );
			item.SetObjectTexture( 3, "dz\\gear\\camping\\data\\christmas_lights_string_ca.paa" );
			item.SetPilotLight(false);
		}
	}

	void HideOnItem(ItemBase item)
	{
		item.SetObjectMaterial( 0, "" );
		item.SetObjectMaterial( 1, "" );
		item.SetObjectMaterial( 2, "" );
		item.SetObjectMaterial( 3, "" );
		item.SetObjectTexture( 0, "" );
		item.SetObjectTexture( 1, "" );
		item.SetObjectTexture( 2, "" );
		item.SetObjectTexture( 3, "" );
		item.SetPilotLight(false);
		item.SetAnimationPhase( "Cord_plugged", 1);
		item.SetAnimationPhase( "Cord_folded", 1);
	}
	
	// --------------------------------------------------
	// Advanced placement
	//---------------------------------------------------
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionPlugIn);
		AddAction(ActionUnplugThisByCord);
	}
	
}
