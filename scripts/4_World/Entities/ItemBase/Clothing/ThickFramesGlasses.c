class ThickFramesGlasses extends Clothing 
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}
		return CanWearUnderMask( parent );
	}
};