class ShelterBase extends TentBase
{
	static const string SITE_OBJECT_TYPE = "ShelterSite";
	void ShelterBase()
	{
		m_ShowAnimationsWhenPitched.Insert( "Body" );
		m_ShowAnimationsWhenPacked.Insert( "Body" ); //redundant?
		
		m_HalfExtents = Vector(0.8, 0.15, 1.3);
	}

	override void SetActions()
	{
		super.SetActions();
		
		RemoveAction(ActionTogglePlaceObject);
		RemoveAction(ActionToggleTentOpen);
		RemoveAction(ActionPackTent);
		RemoveAction(ActionDeployObject);
		
		AddAction(ActionDeconstructShelter);
	}
	
	override void EEInit()
	{		
		super.EEInit();
		
		Pitch(true,true);
	}
	
	void Deconstruct()
	{
		StaticConstructionMethods.SpawnConstructionMaterialPiles(this,null,GetMaterialPath(),GetShelterVariant());
		SpawnKit();
		Delete();
	}
	
	string GetMaterialPath()
	{
		return "" + CFG_VEHICLESPATH + " " + SITE_OBJECT_TYPE + " Construction site " + GetShelterVariant() + " Materials";
	}
	
	string GetShelterVariant()
	{
		return "";
	}
	
	void SpawnKit()
	{
		ItemBase construction_kit = ItemBase.Cast( GetGame().CreateObjectEx( "ShelterKit", GetPosition(), ECE_PLACE_ON_SURFACE ) );
		construction_kit.SetHealth01( "","",GetHealth01() );
	}
	
	/*override static bool KeepRotationOnLambda()
	{
		return true;
	}*/
};

class ShelterFabric extends ShelterBase
{
	override string GetShelterVariant()
	{
		return "fabric";
	}
};

class ShelterLeather extends ShelterBase
{
	override string GetShelterVariant()
	{
		return "leather";
	}
};

class ShelterStick extends ShelterBase
{
	override string GetShelterVariant()
	{
		return "stick";
	}
};