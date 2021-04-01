enum EConnectErrorScript
{
	UNKNOWN = -1,				// -1 must always be UNKNOWN
	OK = 0,						// 0 must always be OK
	
	ALREADY_CONNECTING,			// Already joining a server
	ALREADY_CONNECTING_THIS, 	// Already joining this exact server
}

class ConnectErrorScriptModule : ErrorHandlerModuleScript
{
	void ConnectErrorScriptModule()
	{
		SetCategory(ErrorCategory.ConnectErrorScript);		
	}
	
	override void InitOptionalVariables()
	{
		super.InitOptionalVariables();
		
		m_Header = "#server_browser_connecting_failed";
		m_MenuId = MENU_CONNECT_ERROR_SCRIPT;
		m_UIHandler = new ConnectErrorScriptModuleUI;
	}
	
	override void FillErrorDataMap()
	{
		super.FillErrorDataMap();
		
		InsertDialogueErrorProperties(EConnectErrorScript.ALREADY_CONNECTING, 		"#STR_script_already_connecting", DBT_YESNO, DBB_NO);
		InsertDialogueErrorProperties(EConnectErrorScript.ALREADY_CONNECTING_THIS, 	"#STR_script_already_connecting_this");
	}
	
	override void OnEvent(EventType eventTypeId, Param params)
	{
		switch (eventTypeId)
		{
			case MPSessionPlayerReadyEventTypeID:
				g_Game.GetUIManager().CloseSpecificDialog(m_MenuId);
				break;
			
			default:
				break;
		}
	}
}

class ConnectErrorScriptModuleUI : UIScriptedMenu
{
	override bool OnModalResult(Widget w, int x, int y, int code, int result)
	{
		super.OnModalResult(w, x, y, code, result);
		
		int error = ErrorModuleHandler.GetCodeFromError(code);		
		switch ( error )
		{
			case EConnectErrorScript.ALREADY_CONNECTING:
				if (result == DBB_YES)
				{
					g_Game.DisconnectSessionForce();
					g_Game.DisconnectSessionScript();
					OnlineServices.LoadMPPrivilege();
				}
				break;
			
			default:
				break;
		}
		
		return true;
	}
}