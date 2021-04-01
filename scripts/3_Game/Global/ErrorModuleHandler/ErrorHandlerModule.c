//-----------------------------------------------------------------------------
// Definition
//-----------------------------------------------------------------------------
//! Definition and API of an ErrorHandlerModule - Do not insert any logic here! (as this class is not moddable)
class ErrorHandlerModule
{
	//! Returns the category the module handles.
	proto native ErrorCategory GetCategory();
	
	//! Set the category the module handles.
	proto native void SetCategory(ErrorCategory category);
	
	//! Event that gets triggered when an error of the owned category is thrown.
	protected void OnErrorThrown(int errorCode, string additionalInfo = "")
	{
		#ifdef DEVELOPER
		Print(ErrorModuleHandler.GetErrorHex(errorCode));
		#endif
	}
	
	//! Retrieve the message shown on Client
	string GetClientMessage(int errorCode, string additionalInfo = "")
	{
		return additionalInfo;
	}
	
	//! Retrieve the message shown on Server
	string GetServerMessage(int errorCode, string additionalInfo = "")
	{
		return additionalInfo;
	}
	
	//! Event called by ErrorModuleHandler
	void OnEvent(EventType eventTypeId, Param params)
	{
	}
}

//-----------------------------------------------------------------------------
// Script override
//-----------------------------------------------------------------------------
/**
  \brief This is where to input logic and extend functionality of ErrorHandlerModule
*/
class ErrorHandlerModuleScript : ErrorHandlerModule
{
	
	protected string m_Header = ""; //!< \p Optional: Header (e.g. The header of a Dialogue box)
	protected string m_Prefix = ""; //!< \p Optional: Prefix (e.g. Fixed text at the start of the messages in the module)
	protected int m_MenuId = -1; //!< \p Optional: The ID for the menus belonging to this module	
	protected ref UIScriptedMenu m_UIHandler = null; //!< \p Optional: The UI the handler might generally use	
	
	/**
		\brief \p Map containing the codes that exist for the ErrorHandlerModule
		* The code links to ErrorProperties
		* This contains at the very least the Message for the error
		* Additionally, it can contain the way to handle the error (e.g. Throw a Dialogue with the message)
	*/
	protected ref map<int, ref ErrorProperties> m_ErrorDataMap = new map<int, ref ErrorProperties>();
	
	//! Constructor, by default calls the function that will fill the ErrorDataMap
	void ErrorHandlerModuleScript()
	{
		InitOptionalVariables();
		FillErrorDataMap();
	}
	
	//! Function which gets called before FillErrorDataMap, designed to set Optional Variales before ErrorProperties are created
	void InitOptionalVariables()
	{
	}
	
	//! Function to fill up m_ErrorDataMap, gets called in the Constructor
	void FillErrorDataMap()
	{
		//! Already insert the default "UNKNOWN ERROR" message for code "-1"
		InsertDialogueErrorProperties(-1, "#server_browser_error_unknown");
	}
	
	/**
	\brief Fetches the ErrorProperties for the error code.
		\param errorCode \p int The full error code
		\return \p ErrorProperties The data and handling for the error
	*/
	ErrorProperties GetProperties(int errorCode)
	{
		int error = ErrorModuleHandler.GetCodeFromError(errorCode);
		ErrorProperties properties = null;
			
		if (!m_ErrorDataMap.Find(error, properties))
			Error(string.Format("[EHM] Could not find any properties for error %1(%2) in %3", errorCode, ErrorModuleHandler.GetErrorHex(errorCode), this));
		
		return properties;
	}
	
	/**
	\brief Fetches the Client message for the error code.
		\param errorCode \p int The full error code
		\return \p string The Client message for the error
	*/
	override string GetClientMessage(int errorCode, string additionalInfo = "")
	{
		ErrorProperties properties = GetProperties(errorCode);
			
		if ( properties )
			return properties.GetClientMessage(additionalInfo);
		else
			return additionalInfo;
	}
	
	/**
	\brief Fetches the Server message for the error code.
		\param errorCode \p int The full error code
		\return \p string The Server message for the error
	*/	
	override string GetServerMessage(int errorCode, string additionalInfo = "")
	{
		ErrorProperties properties = GetProperties(errorCode);
			
		if ( properties )
			return properties.GetServerMessage(additionalInfo);
		else
			return additionalInfo;
	}
	
	/**
	\brief Event that gets triggered when an error of the owned category is thrown.
	  * Do not call directly!
	  * Call ErrorModuleHandler.ThrowError instead
		\param errorCode \p int The full error code
		\param additionalInfo \p string Any additional info regarding the error, usually data
	*/
	protected override void OnErrorThrown(int errorCode, string additionalInfo = "")
	{
		super.OnErrorThrown(errorCode, additionalInfo);
		
		ErrorProperties properties = GetProperties(errorCode);
			
		if ( properties )
			properties.HandleError(errorCode, additionalInfo);
		else
		{
			Error(string.Format("[EHM] Error code %1(%2) was thrown but no ErrorProperties was found for it in category %3.", errorCode, ErrorModuleHandler.GetErrorHex(errorCode), GetCategory().ToString()));
			if (m_ErrorDataMap.Find(-1, properties))
				properties.HandleError(errorCode, additionalInfo);
		}
	}
	
	//-----------------------------------------------------------------------------
	// Insert helpers
	//-----------------------------------------------------------------------------
	//! Insert an error with Dialogue as handling, using the Optional Variables
	void InsertDialogueErrorProperties(int code, string message, int dialogButtonType = DBT_OK, int defaultButton = DBB_OK, int dialogMeaningType = DMT_EXCLAMATION, bool displayAdditionalInfo = true)
	{
		m_ErrorDataMap.Insert(code, DialogueErrorProperties(string.Format("%1%2", m_Prefix, message), message, m_Header, m_MenuId, m_UIHandler, dialogButtonType, defaultButton, dialogMeaningType, displayAdditionalInfo));
	}
	
	//! Insert an error with Dialogue as handling with custom header
	void InsertHeaderDialogueErrorProperties(int code, string message, string header, int dialogButtonType = DBT_OK, int defaultButton = DBB_OK, int dialogMeaningType = DMT_EXCLAMATION, bool displayAdditionalInfo = true)
	{
		m_ErrorDataMap.Insert(code, DialogueErrorProperties(string.Format("%1%2", m_Prefix, message), message, header, m_MenuId, m_UIHandler, dialogButtonType, defaultButton, dialogMeaningType, displayAdditionalInfo));
	}
	
	//! Insert an error with Dialogue as handling with custom prefix
	void InsertPrefixDialogueErrorProperties(int code, string message, string prefix, int dialogButtonType = DBT_OK, int defaultButton = DBB_OK, int dialogMeaningType = DMT_EXCLAMATION, bool displayAdditionalInfo = true)
	{
		m_ErrorDataMap.Insert(code, DialogueErrorProperties(string.Format("%1%2", prefix, message), message, m_Header, m_MenuId, m_UIHandler, dialogButtonType, defaultButton, dialogMeaningType, displayAdditionalInfo));
	}
	
	//! Insert an error with Dialogue as handling with extended prefix
	void InsertExtendedPrefixDialogueErrorProperties(int code, string message, string prefix, int dialogButtonType = DBT_OK, int defaultButton = DBB_OK, int dialogMeaningType = DMT_EXCLAMATION, bool displayAdditionalInfo = true)
	{
		m_ErrorDataMap.Insert(code, DialogueErrorProperties(string.Format("%1%2%3", m_Prefix, prefix, message), message, m_Header, m_MenuId, m_UIHandler, dialogButtonType, defaultButton, dialogMeaningType, displayAdditionalInfo));
	}
	
	//! Insert an error with Dialogue as handling with separate server message
	void InsertSplitDialogueErrorProperties(int code, string message, string serverMessage, int dialogButtonType = DBT_OK, int defaultButton = DBB_OK, int dialogMeaningType = DMT_EXCLAMATION, bool displayAdditionalInfo = true)
	{
		m_ErrorDataMap.Insert(code, DialogueErrorProperties(string.Format("%1%2", m_Prefix, message), serverMessage, m_Header, m_MenuId, m_UIHandler, dialogButtonType, defaultButton, dialogMeaningType, displayAdditionalInfo));
	}
	
	//! Insert an error with no handling
	void InsertErrorProperties(int code)
	{
		m_ErrorDataMap.Insert(code, ErrorProperties("", ""));
	}
}