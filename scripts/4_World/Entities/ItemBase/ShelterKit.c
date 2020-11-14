class ShelterKit extends KitBase
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if ( !super.CanReceiveAttachment(attachment, slotId) )
			return false;
		
		ItemBase att = ItemBase.Cast(GetInventory().FindAttachment(slotId));
		if (att)
			return false;
		
		return true;
	}

	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );
		
		if ( GetGame().IsServer() )
		{
			//Create shelter site
			ShelterSite site = ShelterSite.Cast( GetGame().CreateObjectEx( "ShelterSite", GetPosition(), ECE_PLACE_ON_SURFACE ) );
			site.SetPosition( position );
			site.SetOrientation( orientation );
			
			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();
			
			SetIsDeploySound( true );
		}
	}

	override bool DoPlacingHeightCheck()
	{
		return true;
	}

	override float HeightCheckOverride()
	{
		return 1.6;
	}

	override void DisassembleKit(ItemBase item)
	{
		if (!IsHologram())
		{
			ItemBase stick = ItemBase.Cast(GetGame().CreateObjectEx("WoodenStick",GetPosition(),ECE_PLACE_ON_SURFACE));
			MiscGameplayFunctions.TransferItemProperties(this, stick);
			stick.SetQuantity(4);
			Rope rope = Rope.Cast(item);
			CreateRope(rope);
		}
	}
}