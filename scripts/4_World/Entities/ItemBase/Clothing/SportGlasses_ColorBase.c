class SportGlasses_ColorBase extends Clothing 
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}
		bool is_mask_only = false;
		
		if ( parent.FindAttachmentBySlotName( "Mask" ) )
		{
			is_mask_only = parent.FindAttachmentBySlotName( "Mask" ).ConfigGetBool( "noEyewear" );
			DebugPrint.Log("" + is_mask_only);
		}
		
		if ( ( GetNumberOfItems() == 0 || !parent || parent.IsMan() ) && !is_mask_only )
		{
			return true;
		}
		return false;
	}
};
class SportGlasses_Black extends SportGlasses_ColorBase {};
class SportGlasses_Blue extends SportGlasses_ColorBase {};
class SportGlasses_Green extends SportGlasses_ColorBase {};
class SportGlasses_Orange extends SportGlasses_ColorBase {};