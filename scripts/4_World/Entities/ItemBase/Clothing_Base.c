// I know the filename is stupid, but it's what the other files in this structure use..
// And I can't really make it "class Clothing_Base extends Clothing"
// since that will conflict with config and other parts of script and break mods :c
class Clothing extends Clothing_Base
{
	override bool IsClothing()
	{
		return true;
	}

	// Conditions	
	override bool CanPutInCargo( EntityAI parent )
	{
		if ( !super.CanPutInCargo( parent ) )
			return false;
		
		bool is_hidden_stash_exception = false;
		
		if ( parent.IsInherited( UndergroundStash ) )
			is_hidden_stash_exception = true;
		
		if ( GetNumberOfItems() == 0 || !parent || parent.IsMan() || is_hidden_stash_exception )
		{
			EntityAI cargoParent = parent.GetHierarchyParent();
			ClothingBase parentClothing = ClothingBase.Cast(parent);
			if (cargoParent)
				return !(parent.IsClothing() && cargoParent.IsClothing()) || ( parentClothing && parentClothing.SmershException(cargoParent) );
			
			return true;
		}
		
		return false;
	}
	
	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		if (!super.CanReceiveItemIntoCargo(item))
			return false;
		
		EntityAI hierarchyParent = GetHierarchyParent();
		return !hierarchyParent || hierarchyParent.IsMan() || SmershException(hierarchyParent);
	}
	
	//Kind of a hack but I don't have enough time left to do larger scale reworks, sorry
	bool SmershException(EntityAI hierarchyParent)
	{
		EntityAI hp = hierarchyParent.GetHierarchyParent();
		if (hp)
		{
			if (!hp.IsMan())
				return false;
		}
		
		return IsInherited(SmershBag) && hierarchyParent.IsInherited(SmershVest);
	}
	
	override bool CanLoadItemIntoCargo(EntityAI item)
	{
		if (!super.CanLoadItemIntoCargo(item))
			return false;
		
		EntityAI parent = GetHierarchyParent();
		
		if ( parent && parent.IsInherited( UndergroundStash ) )
			return true;
				
		return !parent || parent.IsMan() || SmershException(parent);
	}
};

typedef Clothing ClothingBase;