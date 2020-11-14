class DarkMotoHelmet_ColorBase extends HelmetBase
{	
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if (!super.CanPutAsAttachment(parent)) {return false;}
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
	
	override bool IsObstructingVoice()
	{
		return true;
	}
	
	override int GetVoiceEffect()
	{
		return VoiceEffectObstruction;
	}
}

class DarkMotoHelmet_Black extends DarkMotoHelmet_ColorBase {};
class DarkMotoHelmet_Grey extends DarkMotoHelmet_ColorBase {};
class DarkMotoHelmet_Green extends DarkMotoHelmet_ColorBase {};
class DarkMotoHelmet_Lime extends DarkMotoHelmet_ColorBase {};
class DarkMotoHelmet_Blue extends DarkMotoHelmet_ColorBase {};
class DarkMotoHelmet_Red extends DarkMotoHelmet_ColorBase {};
class DarkMotoHelmet_White extends DarkMotoHelmet_ColorBase {};