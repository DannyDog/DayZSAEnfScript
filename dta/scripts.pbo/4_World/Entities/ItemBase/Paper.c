typedef Param2<string, EntityAI> WritePaperParamsOld;

//-----------------------
typedef Param3<string, string, int> 			WritePaperParams; //message, pen, font
typedef Param1<array<ref WritePaperParams>> 	PaperParams;
//-----------------------

class Paper extends ItemBase
{
	ref array<ref WritePaperParams> m_AdvancedText = new array<ref WritePaperParams>; //TODO
	
	void Paper()
	{
		//m_AdvancedText = NULL;
	}
	
	void ~Paper()
	{
		m_AdvancedText.Clear();
		m_AdvancedText = NULL;
	}
	
	// EntityAI override
	override void OnRPC( PlayerIdentity sender, int rpc_type, ParamsReadContext  ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		
		if (rpc_type == ERPCs.RPC_WRITE_NOTE)
		{
			ref WritePaperParams param = new WritePaperParams("", "",0); // message, penColor, handwriting
			
			if (ctx.Read(param))
			{
				m_AdvancedText.Insert(param);
				/* //SYNCFAIL
				string message = GetItemVariableString("message");
				
				// remove any html tags added by user
				param.param1.Replace("\n", "<br>");
				
				if (message != "") message += "<br>";
				message +=  "<font color=\"" + param.param2.ConfigGetString("writingColor") + "\">" + param.param1 + "</font>";
				
				if (message.Length() < 1000) 
				{
					SetItemVariableString("message", message);
				}
				*/
			}
		}
		if (rpc_type == ERPCs.RPC_READ_NOTE)
		{
			//Print("reading");
			array<ref WritePaperParams> new_AdvancedText = new array<ref WritePaperParams>;
			PaperParams paramsRead = new PaperParams(null);
			if (ctx.Read(paramsRead))
			{
				new_AdvancedText = paramsRead.param1;
				m_AdvancedText = new_AdvancedText;
			}
			if (!GetGame().IsServer() && GetGame().IsMultiplayer())
			{
				PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
				//PlayerBase player = PlayerBase.Cast(GetParent());
				if ( player && player.GetInventory().HasEntityInInventory(this) ) 	player.enterNoteMenuRead = true;
			}
		}
	}
	
	//================================================================
	// IGNITION ACTION
	//================================================================
	override bool HasFlammableMaterial()
	{
		return true;
	}
	
	override bool CanBeIgnitedBy( EntityAI igniter = NULL )
	{
		if ( GetHierarchyParent() ) return false;
		
		return true;
	}
	
	override bool CanIgniteItem( EntityAI ignite_target = NULL )
	{
		return false;
	}
	
	override void OnIgnitedTarget( EntityAI ignited_item )
	{
	}
	
	override void OnIgnitedThis( EntityAI fire_source )
	{
		Fireplace.IgniteEntityAsFireplace( this, fire_source );
	}

	override bool IsThisIgnitionSuccessful( EntityAI item_source = NULL )
	{
		return Fireplace.CanIgniteEntityAsFireplace( this );
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionReadPaper);
		AddAction(ActionWritePaper);
	}
}
