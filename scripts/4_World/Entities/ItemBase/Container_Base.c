class Container_Base extends ItemBase
{
	override bool IsContainer()
	{
		return true;
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}	
		if ( parent != this && ( this.GetType() != parent.GetType() ) )
		{
			return true;
		}
		
		return false;
	}
}

class DeployableContainer_Base extends Container_Base
{
	protected vector m_HalfExtents; // The Y value contains a heightoffset and not the halfextent !!!
	
	void DeployableContainer_Base()
	{
		m_HalfExtents = vector.Zero;
		
		ProcessInvulnerabilityCheck("disableContainerDamage");
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
	

	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;
		
		return super.CanReceiveAttachment(attachment, slotId);
	}

	override bool CanReceiveItemIntoCargo( EntityAI cargo )
	{
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;

		return super.CanReceiveItemIntoCargo( cargo );
	}
	
	/*
	override bool CanReceiveItemIntoCargo (EntityAI cargo)
	{
		super.CanReceiveItemIntoCargo( cargo );
		
		if ( GetHealthLevel() == GameConstants.STATE_RUINED )
			return false;
		
		return true;
	}
	*/
	
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		
		if ( newLevel == GameConstants.STATE_RUINED )
			MiscGameplayFunctions.DropAllItemsInInventoryInBounds(this, m_HalfExtents);
	}
}