class SportGlasses_ColorBase extends Clothing 
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}
		return CanWearUnderMask( parent );
	}
};
class SportGlasses_Black extends SportGlasses_ColorBase {};
class SportGlasses_Blue extends SportGlasses_ColorBase {};
class SportGlasses_Green extends SportGlasses_ColorBase {};
class SportGlasses_Orange extends SportGlasses_ColorBase {};