class NVGHeadstrap extends Clothing
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}
		bool headgear_present = false;
		bool another_NVG_holder = false;
		
		if ( parent.FindAttachmentBySlotName( "Headgear" ) )
		{
			headgear_present = parent.FindAttachmentBySlotName( "Headgear" ).ConfigGetBool( "noMask" );
			
			if ( Mich2001Helmet.Cast(parent.FindAttachmentBySlotName( "Headgear" )) )
			{
				another_NVG_holder = true;
			}
		}
		
		if ( ( GetNumberOfItems() == 0 || !parent || parent.IsMan() ) && !headgear_present && !another_NVG_holder )
		{
			return true;
		}
		return false;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionToggleNVG);
	}
};