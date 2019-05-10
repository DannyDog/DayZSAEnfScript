class SkateHelmet_ColorBase extends HelmetBase
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}
		bool is_mask_only = false;
		
		if ( parent.FindAttachmentBySlotName( "Mask" ) )
		{
			is_mask_only = parent.FindAttachmentBySlotName( "Mask" ).ConfigGetBool( "noHelmet" );
		}
		
		if ( ( GetNumberOfItems() == 0 || !parent || parent.IsMan() ) && !is_mask_only )
		{
			return true;
		}
		return false;
	}
}

class SkateHelmet_Black extends SkateHelmet_ColorBase {};
class SkateHelmet_Blue extends SkateHelmet_ColorBase {};
class SkateHelmet_Gray extends SkateHelmet_ColorBase {};
class SkateHelmet_Green extends SkateHelmet_ColorBase {};
class SkateHelmet_Red extends SkateHelmet_ColorBase {};