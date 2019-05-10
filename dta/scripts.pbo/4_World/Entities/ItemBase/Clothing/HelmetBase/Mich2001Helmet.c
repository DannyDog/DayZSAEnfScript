class Mich2001Helmet extends HelmetBase
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}
		bool is_mask_only = false;
		bool another_NVG_holder = false;
		
		if ( parent.FindAttachmentBySlotName( "Mask" ) )
		{
			is_mask_only = parent.FindAttachmentBySlotName( "Mask" ).ConfigGetBool( "noHelmet" );
		}
		
		if ( NVGHeadstrap.Cast(parent.FindAttachmentBySlotName( "Eyewear" )) )
		{
			another_NVG_holder = true;
		}
		
		if ( ( GetNumberOfItems() == 0 || !parent || parent.IsMan() ) && !is_mask_only && !another_NVG_holder )
		{
			return true;
		}
		return false;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnOnHelmetFlashlight); //use default light actions instead?
		AddAction(ActionTurnOffHelmetFlashlight);
		AddAction(ActionToggleNVG);
	}
};