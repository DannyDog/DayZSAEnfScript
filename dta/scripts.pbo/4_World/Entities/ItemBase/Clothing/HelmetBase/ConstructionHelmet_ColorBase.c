class ConstructionHelmet_ColorBase extends HelmetBase
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
};


class ConstructionHelmet_Blue extends ConstructionHelmet_ColorBase {};
class ConstructionHelmet_Lime extends ConstructionHelmet_ColorBase {};
class ConstructionHelmet_Orange extends ConstructionHelmet_ColorBase {};
class ConstructionHelmet_Red extends ConstructionHelmet_ColorBase {};
class ConstructionHelmet_White extends ConstructionHelmet_ColorBase {};
class ConstructionHelmet_Yellow extends ConstructionHelmet_ColorBase {};