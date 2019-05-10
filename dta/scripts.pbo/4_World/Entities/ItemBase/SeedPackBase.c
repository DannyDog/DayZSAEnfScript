class SeedPackBase extends Inventory_Base
{
	private static const float PACK_DAMAGE_TOLERANCE = 0.5;
	
	void SeedPackBase()
	{	
	}

	void EmptySeedPack( PlayerBase player )
	{
		float damage = 100 - this.GetHealth("", "");
		
		if ( damage < 1 )
		{
			string pack_type = this.GetType();
			string seeds_type = "";
			
			GetGame().ConfigGetText( "cfgVehicles " + pack_type + " Horticulture ContainsSeedsType", seeds_type );
			
			int seeds_quantity_max = GetGame().ConfigGetInt( "cfgVehicles " + pack_type + " Horticulture ContainsSeedsQuantity" );
			int seeds_quantity = seeds_quantity_max;
			
			if ( damage >= PACK_DAMAGE_TOLERANCE ) 
			{
				seeds_quantity = Math.Round( seeds_quantity_max * (1 - ((damage - PACK_DAMAGE_TOLERANCE) / PACK_DAMAGE_TOLERANCE)) );
			}
		
			if ( seeds_quantity < 1 )
			{ 
				seeds_quantity = 1;
			}
			
			if (player)
			{
				EmptySeedsPackLambda lambda = new EmptySeedsPackLambda(this, seeds_type, player, seeds_quantity);
				player.ServerReplaceItemInHandsWithNew(lambda);
			}
			else
			{
				vector pos = GetPosition();
				GetGame().CreateObject(seeds_type, pos);
				GetGame().ObjectDelete( this );
			}
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionEmptySeedsPack);
	}
}

class EmptySeedsPackLambda : ReplaceItemWithNewLambdaBase
{
	int m_ItemCount;
	
	void EmptySeedsPackLambda (EntityAI old_item, string new_item_type, PlayerBase player, int count) 
	{
		m_ItemCount = count; 
	}

	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		ItemBase unboxed;
		Class.CastTo(unboxed, new_item);
		unboxed.SetQuantity(m_ItemCount);
	}
};