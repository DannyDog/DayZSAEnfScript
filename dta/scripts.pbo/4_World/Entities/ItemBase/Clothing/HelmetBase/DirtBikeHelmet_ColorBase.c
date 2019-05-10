class DirtBikeHelmet_ColorBase extends HelmetBase
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

class DirtBikeHelmet_Green extends DirtBikeHelmet_ColorBase {};
class DirtBikeHelmet_Chernarus extends DirtBikeHelmet_ColorBase {};
class DirtBikeHelmet_Khaki extends DirtBikeHelmet_ColorBase {};
class DirtBikeHelmet_Police extends DirtBikeHelmet_ColorBase {};
class DirtBikeHelmet_Red extends DirtBikeHelmet_ColorBase {};
class DirtBikeHelmet_Black extends DirtBikeHelmet_ColorBase {};
class DirtBikeHelmet_Blue extends DirtBikeHelmet_ColorBase {};