class MotoHelmet_ColorBase extends HelmetBase
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

class MotoHelmet_Black extends MotoHelmet_ColorBase {};
class MotoHelmet_Grey extends MotoHelmet_ColorBase {};
class MotoHelmet_Green extends MotoHelmet_ColorBase {};
class MotoHelmet_Lime extends MotoHelmet_ColorBase {};
class MotoHelmet_Blue extends MotoHelmet_ColorBase {};
class MotoHelmet_Red extends MotoHelmet_ColorBase {};
class MotoHelmet_White extends MotoHelmet_ColorBase {};