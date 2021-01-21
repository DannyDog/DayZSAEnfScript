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
	
	/*override void UpdateNVGStatus(PlayerBase player, bool attaching = false)
	{
		NVGoggles NVGAttachment;
		NVGAttachment = NVGoggles.Cast(FindAttachmentBySlotName("NVG"));
		
		if ( player )
		{
			if ( NVGAttachment )
			{
				NVGAttachment.LoweredCheck();
				
				if ( attaching && NVGAttachment.IsWorking() && NVGAttachment.m_Strap && NVGAttachment.m_IsLowered && !player.IsNVGWorking() )
				{
					NVGAttachment.SetPlayer(player);
					player.SetNVGWorking(true);
				}
				else if ( player.IsNVGWorking() )
				{
					NVGAttachment.SetPlayer(null);
					player.SetNVGWorking(false);
				}
			}
			else if ( player.IsNVGWorking() )
			{
				player.SetNVGWorking(false);
			}
		}
	}*/
	
			
	//Debug menu Spawn Ground Special
	override void OnDebugSpawn()
	{
		EntityAI entity;
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "NVGoggles" );
			entity.GetInventory().CreateInInventory( "UniversalLight" );
			entity.GetInventory().CreateInInventory( "Battery9V" );
			entity.GetInventory().CreateInInventory( "Battery9V" );
		}
	}
};