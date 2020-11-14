
/** @file */

/// tree traversal type, for more see http://en.wikipedia.org/wiki/Tree_traversal
enum InventoryTraversalType
{
	PREORDER,
	INORDER,
	POSTORDER,
	LEVELORDER
};

const int INDEX_NOT_FOUND = -1;
//-----------------------------------------------------------------------------
typedef Serializer ParamsReadContext;
typedef Serializer ParamsWriteContext;

/**
\brief Class for sending RPC over network
	@code
		// example sending
		void Send()
		{
			ScriptRPC rpc = new ScriptRPC();
	
			rpc.Write(645);
			rpc.Write("hello");
			
			array<float> farray = {1.2, 5.6, 8.1};
			rpc.Write(farray);
	
			rpc.Send(m_Player, ERPCs.RPC_TEST, true, m_Player.GetIdentity());
		}

		// example receive
		void OnRPC(ParamsReadContext ctx)
		{
			int num;
			string text;
			array<float> farray;

			ctx.Read(num);
			ctx.Read(text);
			ctx.Read(farray);
		}
	@endcode
*/

class JsonSerializer: Serializer
{
	void JsonSerializer() {}
	void ~JsonSerializer() {}
	
	/**
	\brief Script variable serialization to json string
	@param variable_out script variable to be serialized to string
	@param nice if the string should be formated for human readability
	@param result from the serialization, output or error depending on the return value 
	\return if the serialization was successful
	@code
		Data data;
		string textOut; 
		bool nice = false;
		JsonSerializer js = new JsonSerializer();
		bool ok = js.WriteToString(data, false, textOut);	
	@endcode	
	*/
	proto bool WriteToString(void variable_out, bool nice, out string result);
	
	/**
	\brief Json string deserialization to script variable
	@param variable_in script variable to be deserialized from string
	@param jsonString the input string
	@param error from the deserialization. Is used only if the return value of the function is false
	\return if the deserialization was successful
	@code
		// Example json
		//  {
		//    "i": 6,                                 // Int
		//    "f": 3.5,                               // Float
		//    "v": [1.1,2.2,3.3]                      // Vector3 is static array of size 3
		//    "s": "string",                          // String
		//    "subData": {                            // Object
		//      "staticIArr": [9,8],                  // Static array (of ints)
		//      "dynamicSArr": ["string1","string2"]  // Dynamic array (of strings)
		//    },                                      //
		//    "fSet": [12.3,14.7],                    // Set (of floats)
		//    "ifMap": {                              // Map (of int, float), only valid key type is int, enum, string
		//      "3": 4.5,							  // Map key has to be as string
		//      "4": 5.5
		//    }
		//  }
	
		Data data = new Data;
		string input = // valid json string;
		string error;
	    bool ok = js.ReadFromString(data, input, error);
	@endcode	
	*/
	proto bool ReadFromString(void variable_in, string jsonString, out string error);
};


class ScriptRPC: ParamsWriteContext
{
	void ScriptRPC();
	void ~ScriptRPC();
	//! Reset internal buffer which stores written data. After Reset is callded, ScriptRPC can be used again as "new" ScriptRPC
	proto native void Reset();
	/**
  \brief Initiate remote procedure call. When called on client, RPC is evaluated on server; When called on server, RPC is executed on all clients. 
	Do not reset ScriptRPC internal state, so if is Send called multiple times in a row, it sends same (previously written) data again and again, until is Reset() called.
	@param target object on which remote procedure is called, when NULL, RPC is evaluated by CGame as global
	@param rpc_type user defined identification of RPC
	@param recipient specified client to send RPC to. If NULL, RPC will be send to all clients (specifying recipient increase security and decrease network traffic)
	*/
	proto native void Send(Object target, int rpc_type, bool guaranteed,PlayerIdentity recipient = NULL);
};

class ScriptInputUserData : ParamsWriteContext
{
	void ScriptInputUserData ();
	void ~ScriptInputUserData ();

	proto native void Reset ();
	proto native void Send ();
	proto native static bool CanStoreInputUserData ();
};

class ScriptReadWriteContext
{
	void ScriptReadWriteContext ();
	void ~ScriptReadWriteContext ();

	proto native ParamsWriteContext GetWriteContext ();
	proto native ParamsReadContext GetReadContext ();
};

class ScriptRemoteInputUserData : ParamsWriteContext
{
	void ScriptRemoteInputUserData ();
	void ~ScriptRemoteInputUserData ();

	proto native void Reset ();
};

class ScriptJunctureData : ParamsWriteContext
{
	void ScriptJunctureData ();
	void ~ScriptJunctureData ();

	proto native void Reset ();
};

//-----------------------------------------------------------------------------
class MeleeCombatData
{
	proto native int GetModesCount();

	proto native owned string GetModeName(int index);

	proto native owned string GetAmmoTypeName(int index);

	proto native float GetModeRange(int index);
	
	private void MeleeCombatData();
	private void ~MeleeCombatData();
}

//-----------------------------------------------------------------------------
const string NullStringArray[1] = { "" };

//-----------------------------------------------------------------------------
//! Selection class
class Selection
{
	proto native owned string GetName();
	proto native int GetVertexCount();
	proto native int GetLODVertexIndex(int sel_vertex_index);

	vector GetVertexPosition(LOD lod, int index)
	{
		int lodIndex = GetLODVertexIndex(index);
		if(lodIndex == -1)
		{
			Error("Vertex doesn't exist");
			return vector.Zero;
		}
		
		return lod.GetVertexPosition(lodIndex);
	}
};

//-----------------------------------------------------------------------------
//! LOD class
class LOD
{
	proto native int GetSelectionCount();
	proto native bool GetSelections(notnull out array<Selection> selections);

	proto native vector GetVertexPosition(int vertex_index);
	
	proto native owned string GetName(Object myObject);
	
	Selection GetSelectionByName( string name )
	{
		array<Selection> selections = new array<Selection>;
		GetSelections( selections );
		
		for ( int i = 0; i < selections.Count(); ++i )
		{
			string selection_name = selections.Get( i ).GetName();
			selection_name.ToLower();
			name.ToLower();
			if (selection_name == name)
			{
				return selections.Get( i );
			}
		}
		
		return NULL;
	}
	
	proto native int GetPropertyCount();
	proto native owned string GetPropertyName(int index);
	proto native owned string GetPropertyValue(int index);
}

class Plant extends Object
{
};

/*
class ParamEntry
{
	proto string GetString(string entryName);
	proto int GetInt(string entryName);
	proto float GetFloat(string entryName);
	proto ref ParamEntry GetEntry(string entryName); 
	proto int GetNumChildren();
	proto ref ParamEntry GetNumChildren(int n);	
};
*/
//-----------------------------------------------------------------------------
	
//-----------------------------------------------------------------------------
class ProxyInventory extends ObjectTyped
{
};

//-----------------------------------------------------------------------------
class ProxySubpart extends Entity
{
};

//-----------------------------------------------------------------------------
// custom widgets
//-----------------------------------------------------------------------------
class ItemPreviewWidget: Widget
{
	proto native void SetItem(EntityAI object);
	proto native EntityAI GetItem();
	
	proto native int GetView();
	/**
	* 0 - default boundingbox_min + boundingbox_max + invView
	* 1 - boundingbox_min2 + boundingbox_max2 + invView2
	* 2 - boundingbox_min3 + boundingbox_max3 + invView3
	* ...	
	*/
	proto native void SetView(int viewIndex);

	proto native void		SetModelOrientation(vector vOrientation);
	proto native vector GetModelOrientation();
	proto native void		SetModelPosition(vector vPos);
	proto native vector GetModelPosition();
	
	proto native void SetForceFlipEnable(bool enable);
	proto native void SetForceFlip(bool value);
};

//-----------------------------------------------------------------------------
class PlayerPreviewWidget: Widget
{
	proto native void		UpdateItemInHands(EntityAI object);
	proto native void		SetPlayer(DayZPlayer player);
	proto native DayZPlayer	GetDummyPlayer();

	proto native void		SetModelOrientation(vector vOrientation);
	proto native vector		GetModelOrientation();
	proto native void		SetModelPosition(vector vPos);
	proto native vector		GetModelPosition();
};

//-----------------------------------------------------------------------------
class HtmlWidget extends RichTextWidget
{
	proto native void LoadFile(string path);
};

//-----------------------------------------------------------------------------
class MapWidget: Widget
{
	proto native void ClearUserMarks();
	proto native void AddUserMark(vector pos, string text, int color /*ARGB*/, string texturePath);
	proto native vector GetMapPos();
	proto native void SetMapPos(vector worldPos);
	proto native float GetScale();
	proto native void SetScale(float scale);
	proto native vector MapToScreen(vector worldPos);
	proto native vector ScreenToMap(vector screenPos);
};

//-----------------------------------------------------------------------------
//! Player description
class PlayerIdentity: Managed
{
	//! ping range estimation
	proto native int GetPingMin();
	//! ping range estimation
	proto native int GetPingMax();
	//! ping range estimation
	proto native int GetPingAvg();

	//! bandwidth estimation (in kbps)
	proto native int GetBandwidthMin();
	//! bandwidth estimation (in kbps)
	proto native int GetBandwidthMax();
	//! bandwidth estimation (in kbps)
	proto native int GetBandwidthAvg();
	
	//! nick (short) name of player
	proto native owned string GetName();
	//! full name of player
	proto native owned string GetFullName();
	//! unique id of player (hashed steamID, database Xbox id...) can be used in database or logs
	proto native owned string GetId();
	//! plaintext unique id of player (cannot be used in database or logs)
	proto native owned string GetPlainId();
	//!  id of player in one session (is reused after player disconnects)
	proto native owned int GetPlayerId();

	private void ~PlayerIdentity()
	{
	}
};

//-----------------------------------------------------------------------------
const int PROGRESS_START = 0;
const int PROGRESS_FINISH = 1;
const int PROGRESS_PROGRESS = 2;
const int PROGRESS_UPDATE = 3;

//-----------------------------------------------------------------------------
typedef int ChatChannel;

//-----------------------------------------------------------------------------
//! state, progress, title
typedef Param3<int, float, string> ProgressEventParams;
typedef Param1<string> ScriptLogEventParams;
//! channel, from, text, color config class
typedef Param4<int, string, string, string> ChatMessageEventParams;
typedef Param1<int> ChatChannelEventParams;
typedef Param1<int> SQFConsoleEventParams;
//! PlayerIdentity, useDB, pos, yaw, preloadTimeout (= additional time in seconds to how long server waits for loginData)
typedef Param5<PlayerIdentity, bool, vector, float, int> ClientPrepareEventParams;
//! PlayerIdentity, PlayerPos, Top, Bottom, Shoe, Skin
typedef Param3<PlayerIdentity, vector, Serializer> ClientNewEventParams; 
//! PlayerIdentity, Man
typedef Param2<PlayerIdentity, Man> ClientRespawnEventParams; 
//! PlayerIdentity, Man
typedef Param2<PlayerIdentity, Man> ClientReadyEventParams;
//! PlayerIdentity, Man
typedef Param2<PlayerIdentity, Man> ClientReconnectEventParams; 
//! PlayerIdentity, Man, LogoutTime, AuthFailed
typedef Param4<PlayerIdentity, Man, int, bool> ClientDisconnectedEventParams; 
//! LoginTime
typedef Param1<int> LoginTimeEventParams; 
//! RespawnTime
typedef Param1<int> RespawnEventParams; 

typedef Param1<vector> PreloadEventParams; 
//! Player
typedef Param1<Man> LogoutCancelEventParams; 
//! text message for line 1, text message for line 2 
typedef Param2<string, string> LoginStatusEventParams; 
//! logoutTime
typedef Param1<int> LogoutEventParams; 
//! Width, Height, Windowed
typedef Param3<int, int, bool> WindowsResizeEventParams;
//! Enabled
typedef Param1<bool> VONStateEventParams;
//! player name, player id
typedef Param2<string, string> VONStartSpeakingEventParams;
//! player name, player id
typedef Param2<string, string> VONStopSpeakingEventParams;
//! world name
typedef Param1<string> DLCOwnerShipFailedParams;
//! Camera
typedef Param1<FreeDebugCamera> SetFreeCameraEventParams;
//! Duration
typedef Param1<int>MPConnectionLostEventParams;


//-----------------------------------------------------------------------------
#ifdef DOXYGEN
// just because of doc



enum EventType
{
	//! no params
	StartupEventTypeID,
	//! no params
	WorldCleaupEventTypeID,

	//-----------------------------------------------------------------------------
	//! no params
	MPSessionStartEventTypeID,
	//! no params
	MPSessionEndEventTypeID,
	//! no params
	MPSessionFailEventTypeID,
	//! no params
	MPSessionPlayerReadyEventTypeID,

	//-----------------------------------------------------------------------------
	//! params: \ref ProgressEventParams
	ProgressEventTypeID,
	//! no params
	NetworkManagerClientEventTypeID,
	//! no params
	NetworkManagerServerEventTypeID,
	//! no params
	DialogQueuedEventTypeID,
	//! params: \ref ChatMessageEventParams
	ChatMessageEventTypeID,
	//! params: \ref ChatChannelEventParams
	ChatChannelEventTypeID,
	//! params: \ref ClientPrepareEventParams
	ClientPrepareEventTypeID,
	//! params: \ref ClientNewEventParams
	ClientNewEventTypeID,	
	//! params: \ref ClientRespawnEventParams
	ClientRespawnEventTypeID,
	//! params: \ref ClientReconnectEventParams
	ClientReconnectEventTypeID,
	//! params: \ref ClientReadyEventParams
	ClientReadyEventTypeID,
	//! params: \ref ClientDisconnectedEventParams
	ClientDisconnectedEventTypeID,
	//! params: \ref LogoutCancelEventParams
	LogoutCancelEventTypeID,
	//! params: \ref LoginTimeEventParams
	LoginTimeEventTypeID,
	//! params: \ref RespawnEventParams
	RespawnEventTypeID,
	//! params: \ref PreloadEventParams
	PreloadEventTypeID,
	//! params: \ref LogoutEventParams
	LogoutEventTypeID,	
	//! params: \ref LoginStatusEventParams
	LoginStatusEventTypeID,	
	//! params: \ref ScriptLogEventParams
	ScriptLogEventTypeID,
	//! params: \ref VONStateEventParams
	VONStateEventTypeID,
	//! params: \ref VONStartSpeakingEventParams
	VONStartSpeakingEventTypeID,
	//! params: \ref VONStopSpeakingEventParams
	VONStopSpeakingEventTypeID,
	//! params: \ref SetFreeCameraEventParams
	DLCOwnerShipFailedEventTypeID,
	//! params: \ref DLCOwnerShipFailedParams
	SetFreeCameraEventTypeID,
	//! params: \ref MPConnectionLostEventParams
	MPConnectionLostEventTypeID,
	//! no params
	ConnectingAbortEventTypeID
	
	//possible in engine events not accessable from script
	//ReloadShadersEvent
	//LoadWorldProgressEvent
	
	//SignStatusEvent
	//SetPausedEvent
	//TerminationEvent
	//UserSettingsChangedEvent
	//StorageChangedEvent
	//BeforeResetEvent
	//AfterRenderEvent
	//AfterResetEvent
	//CrashLogEvent
	//ConsoleEvent
};

#endif

class CursorIcons
{
	const string None 			= "";
	const string Cursor			= "set:dayz_gui image:cursor";
	const string CloseDoors 	= "set:dayz_gui image:close";
	const string OpenDoors 		= "set:dayz_gui image:open";
	const string OpenCarDoors 	= "set:dayz_gui image:open_car";
	const string CloseCarDoors 	= "set:dayz_gui image:close_car";
	const string EngineOff 		= "set:dayz_gui image:engine_off";
	const string EngineOn 		= "set:dayz_gui image:engine_on";
	const string LadderDown 	= "set:dayz_gui image:ladderdown";
	const string LadderOff 		= "set:dayz_gui image:ladderoff";
	const string LadderUp 		= "set:dayz_gui image:ladderup";
	const string LootCorpse 	= "set:dayz_gui image:gear";
	const string CloseHood 		= "set:dayz_gui image:close_hood";
	const string OpenHood 		= "set:dayz_gui image:open_hood";
	const string GetOut 		= "set:dayz_gui image:getout";
	const string GetInCargo 	= "set:dayz_gui image:get_in_cargo";
	const string Reload 		= "set:dayz_gui image:reload";
	const string GetInDriver 	= "set:dayz_gui image:get_in_driver";
	const string GetInCommander = "set:dayz_gui image:get_in_commander";
	const string GetInPilot 	= "set:dayz_gui image:get_in_pilot";
	const string GetInGunner 	= "set:dayz_gui image:get_in_gunner";
};

	

// some defs for CGame::ShowDialog()
/*
const int DBB_NONE = 0;
const int DBB_OK = 1;
const int DBB_YES = 2;
const int DBB_NO = 3;
const int DBB_CANCEL = 4;

const int DBT_OK = 0;		//just OK button
const int DBT_YESNO = 1;	//Yes and No buttons
const int DBT_YESNOCANCEL = 2; //Yes, No, Cancel buttons

const int DMT_NONE = 0;
const int DMT_INFO = 1;
const int DMT_WARNING = 2;
const int DMT_QUESTION = 3;
const int DMT_EXCLAMATION = 4;
*/

proto native CGame GetGame();

class Hud: Managed
{
	ref Timer m_Timer;
	void Init( Widget hud_panel_widget ) {}
	void DisplayNotifier( int key, int tendency, int status ) {}
	void DisplayBadge( int key, int value ) {}
	void SetStamina( int value, int range ) {}
	void DisplayStance( int stance ) {}
	void DisplayPresence() {}
	void ShowCursor() { }
	void HideCursor() { }
	void SetCursorIcon( string icon ) { }
	void SetCursorIconScale( string type, float percentage ) { }
	void SetCursorIconOffset( string type, float x, float y ) { }
	void SetCursorIconSize( string type, float x, float y ) {	}
	void ShowWalkieTalkie( bool show ) { }
	void ShowWalkieTalkie( int fadeOutSeconds ) { }
	void SetWalkieTalkieText( string text ) { }
	void RefreshQuickbar( bool itemChanged = false ) {}
	void Show(bool show) {}
	void UpdateBloodName() {}
	void SetTemperature( string temp );
	void SetStaminaBarVisibility( bool show );
	void Update( float timeslice ){}
	bool IsXboxDebugCursorEnabled();
	void ShowVehicleInfo();
	void HideVehicleInfo();
	void ToggleHeatBufferPlusSign( bool show );
	
	void ShowQuickbarUI( bool show );
	void ShowQuickbarPlayer( bool show );
	void ShowHudPlayer( bool show );
	void ShowHudUI( bool show );
	void ShowHudInventory( bool show );
	void ShowQuickBar( bool show );
	void ShowHud( bool show );
	
	void OnResizeScreen();

	void SetPermanentCrossHair( bool show ) {}

};

//-----------------------------------------------------------------------------
//! Mission class
class Mission
{
	ScriptModule MissionScript;

	ref array<vector> m_ActiveRefresherLocations;
	private void ~Mission();
	
	void OnInit()	{}
	void OnMissionStart() {}
	void OnMissionFinish()	{}
	void OnUpdate(float timeslice) {}
	void OnKeyPress(int key) {}
	void OnKeyRelease(int key) {}
	void OnMouseButtonPress(int button){}
	void OnMouseButtonRelease(int button){}
	void OnEvent(EventType eventTypeId, Param params) {}
	void OnItemUsed(InventoryItem item, Man owner) {}	
	void AddDummyPlayerToScheduler(Man player){}
	void Reset(){}
	void ResetGUI(){}
	
	Hud GetHud()
	{ 
		return NULL;
	}
	
	bool IsPlayerDisconnecting(Man player);
	
	UIScriptedMenu	CreateScriptedMenu( int id ) 
	{ 
		return NULL;
	}
	
	UIScriptedWindow	CreateScriptedWindow( int id ) 
	{ 
		return NULL;
	}
	
	WorldData GetWorldData()
	{
		return NULL;
	}
	
	WorldLighting GetWorldLighting()
	{
		return NULL;
	}
	
	bool IsPaused() 
	{ 
		return false; 
	}
	
	bool IsGame()
	{
		return false;
	}
	
	bool IsServer()
	{
		return false;
	}

	void Pause() {}
	void Continue() {}
	
	void AbortMission() {}

	void CreateLogoutMenu(UIMenuPanel parent) {}
	void StartLogoutMenu(int time) {}

	void CreateDebugMonitor() {}
	
	void RefreshCrosshairVisibility() {}

	void HideCrosshairVisibility() {}
	
	bool IsMissionGameplay()
	{
		return false;
	}
	
	bool IsControlDisabled() {}
	
	void PlayerControlEnable( bool bForceSupress ) {}
	void PlayerControlDisable(int mode) {}

	void ShowInventory() {}
	void HideInventory() {}
	
	void ShowChat() {}
	void HideChat() {}
	void UpdateVoiceLevelWidgets(int level) {}
	void HideVoiceLevelWidgets() {}
	bool IsVoNActive() {}
	
	bool InsertCorpse(Man player)
	{
		return false;
	}
	
	UIScriptedMenu GetNoteMenu() {};
	void SetNoteMenu(UIScriptedMenu menu) {};
	void SetPlayerRespawning(bool state);
	bool IsPlayerRespawning();
	array<vector> GetActiveRefresherLocations();
	
	//! for client-side usage
	void SetRespawnModeClient(int mode);
	int GetRespawnModeClient()
	{
		return -1;
	}
	//! server-side
	void SyncRespawnModeInfo(PlayerIdentity identity) {};
};

// -------------------------------------------------------------------------

class MenuData: Managed
{
	proto native int	GetCharactersCount();
	proto native int 	GetLastPlayedCharacter();
	//! Return Character person or null if character initialization failed (inventory load, or corrupted data)
	proto native Man 	CreateCharacterPerson(int index);
	
	proto void 			GetLastServerAddress(int index, out string address);
	proto native int 	GetLastServerPort(int index);
	proto void 			GetLastServerName(int index, out string address);
	
	proto void 			RequestSetDefaultCharacterData();
	proto bool			RequestGetDefaultCharacterData();
	
	//! Actual DefaultCharacter saving
	void OnSetDefaultCharacter(ParamsWriteContext ctx)
	{
		//Print("OnSetDefaultCharacter");
		
		if (!GetMenuDefaultCharacterDataInstance()/* || GetGame().IsServer()*/)
		{
			Error("MenuData | OnSetDefaultCharacter - failed to get data class!");
			return;
		}
		
		GetMenuDefaultCharacterDataInstance().SerializeCharacterData(ctx);
		SaveCharactersLocal();
	}
	
	//! Actual DefaultCharacter loading
	bool OnGetDefaultCharacter(ParamsReadContext ctx)
	{
		//Print("OnGetDefaultCharacter");
		
		if (!GetMenuDefaultCharacterDataInstance())
		{
			Error("MenuData | OnGetDefaultCharacter - failed to get data class!");
			return false;
		}
		
		if (GetMenuDefaultCharacterDataInstance().DeserializeCharacterData(ctx))
		{
			return true;
		}
		return false;
	}
	
	proto void 			GetCharacterName(int index, out string name);
	proto native void 	SetCharacterName(int index, string newName);
	// save character is set as last played character 
	proto native void 	SaveCharacter(bool localPlayer, bool verified);
	proto native void 	SaveDefaultCharacter(Man character);
	
	//! Saves characters menu data to file
	proto native void 	SaveCharactersLocal();
	//! Loads characters menu data from file
	proto native void 	LoadCharactersLocal();
	proto native void 	ClearCharacters();
	
	MenuDefaultCharacterData GetMenuDefaultCharacterDataInstance()
	{
		return GetGame().GetMenuDefaultCharacterData();
	}
	
	//proto native void	GetCharacterStringList(int characterID, string name, out TStringArray values);
	//proto bool			GetCharacterString(int characterID,string name, out string value);
};

//used to hold 'default character' data
class MenuDefaultCharacterData
{
	//const int MODE_SERVER = 0;
	//const int MODE_CLIENT = 1;
	
	string 					m_CharacterName;
	string 					m_CharacterType;
	ref map<int,string> 	m_AttachmentsMap;
	bool 					m_ForceRandomCharacter;
	
	void MenuDefaultCharacterData()
	{
		Init();
	}
	
	void Init()
	{
		//Print("MenuDefaultCharacterData | Init");
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			//Print("MenuDefaultCharacterData | m_MenuData: " + GetGame().GetMenuData());
			GetGame().GetMenuData().LoadCharactersLocal();
		}
		m_AttachmentsMap = new map<int,string>;
	}
	
	void ClearAttachmentsMap()
	{
		m_AttachmentsMap.Clear();
	}
	
	void SetDefaultAttachment(int slotID, string type)
	{
		m_AttachmentsMap.Set(slotID,type); //using 'Set' instead of 'Insert' for convenience
	}
	
	void GenerateRandomEquip()
	{
		ClearAttachmentsMap();
		
		int slot_ID;
		string attachment_type;
		for (int i = 0; i < DefaultCharacterCreationMethods.GetAttachmentSlotsArray().Count(); i++)
		{
			slot_ID = DefaultCharacterCreationMethods.GetAttachmentSlotsArray().Get(i);
			if (DefaultCharacterCreationMethods.GetConfigArrayCountFromSlotID(slot_ID) > 0)
			{
				attachment_type = DefaultCharacterCreationMethods.GetConfigAttachmentTypes(slot_ID).GetRandomElement();
				//if (attachment_type != "")
					SetDefaultAttachment(slot_ID,attachment_type);
			}
		}
	}
	
	void EquipDefaultCharacter(Man player)
	{
		if (!player)
		{
			Print("WARNING - trying to equip non-existent object! | MenuDefaultCharacterData::EquipDefaultCharacter");
			return;
		}
		
		int slot_ID;
		string attachment_type;
		string current_attachment_type;
		EntityAI current_attachment_object;
		
		for (int i = 0; i < m_AttachmentsMap.Count(); i++)
		{
			attachment_type = "";
			current_attachment_type = "";
			slot_ID = m_AttachmentsMap.GetKey(i);
			attachment_type = m_AttachmentsMap.GetElement(i); //Get(i)
			current_attachment_object = player.GetInventory().FindAttachment(slot_ID);
			
			if (current_attachment_object)
			{
				current_attachment_type = current_attachment_object.GetType();
			}
			if (current_attachment_type != attachment_type)
			{
				if (current_attachment_object)
					g_Game.ObjectDelete(current_attachment_object);
				if (attachment_type != "")
					player.GetInventory().CreateAttachmentEx(attachment_type,slot_ID);
			}
		}
	}
	
	//!serializes data into a param array to be used by "StoreLoginData(notnull array<ref Param> params);" 
	void SerializeCharacterData(ParamsWriteContext ctx)
	{
		//Print("SerializeCharacterData");
		ctx.Write(m_CharacterType);
		ctx.Write(m_AttachmentsMap);
		ctx.Write(m_ForceRandomCharacter);
		ctx.Write(m_CharacterName);
		//Print(m_CharacterType);
		//DumpAttMapContents();
	}
	
	bool DeserializeCharacterData(ParamsReadContext ctx)
	{
		//Print("DeserializeCharacterData");
		if (!ctx.Read(m_CharacterType))
			return false;
		if (!ctx.Read(m_AttachmentsMap))
			return false;
		if (!ctx.Read(m_ForceRandomCharacter))
			return false;
		if (!ctx.Read(m_CharacterName))
			return false;
		
		//Print(m_CharacterType);
		//DumpAttMapContents();
		return true;
	}
	
	void SetCharacterName(string name)
	{
		m_CharacterName = name;
	}
	
	string GetCharacterName()
	{
		return m_CharacterName;
	}
	
	void SetCharacterType(string character_type)
	{
		m_CharacterType = character_type;
	}
	
	string GetCharacterType()
	{
		return m_CharacterType;
	}
	
	void SetRandomCharacterForced(bool state)
	{
		m_ForceRandomCharacter = state;
	}
	
	bool IsRandomCharacterForced()
	{
		return m_ForceRandomCharacter;
	}
	
	ref map<int,string> GetAttachmentMap()
	{
		return m_AttachmentsMap;
	}
	
	//DEBUG
	void DumpAttMapContents()
	{
		int debugID;
		string debugType;
		Print("-----------");
		Print("m_AttachmentsMap contents:");
		for (int j = 0; j < m_AttachmentsMap.Count(); j++)
		{
			debugID = m_AttachmentsMap.GetKey(j);
			debugType = m_AttachmentsMap.GetElement(j);
			Print("index " + j);
			Print("debugID: " + debugID);
			Print("debugType: " + debugType);
		}
		Print("-----------");
	}
}

class DefaultCharacterCreationMethods
{
	static ref array<int> m_AttachmentSlots = {
		InventorySlots.SHOULDER,
		InventorySlots.MELEE,
		InventorySlots.HEADGEAR,
		InventorySlots.MASK,
		InventorySlots.EYEWEAR,
		InventorySlots.GLOVES,
		InventorySlots.ARMBAND,
		InventorySlots.BODY,
		InventorySlots.VEST,
		InventorySlots.BACK,
		InventorySlots.HIPS,
		InventorySlots.LEGS,
		InventorySlots.FEET
	};
	//conversion nescesssary for legacy reasons...
	static ref array<string> m_ConfigArrayNames = {
		"shoulder",
		"melee",
		"headgear",
		"mask",
		"eyewear",
		"gloves",
		"armband",
		"top",
		"vests",
		"backpacks",
		"hips",
		"bottom",
		"shoe"
	};
	
	const static string m_Path = "cfgCharacterCreation";
	
	//! Returns config path of att. slot category, empty if undefined
	static string GetPathFromSlotID(int slot_ID)
	{
		int idx = m_AttachmentSlots.Find(slot_ID);
		string path = "" + m_Path + " " + m_ConfigArrayNames.Get(idx);
		return path;
	}
	
	//! How many 'default equip' types are listed in the corresponding array
	static int GetConfigArrayCountFromSlotID(int slot_ID)
	{
		TStringArray types = new TStringArray;
		GetGame().ConfigGetTextArray(GetPathFromSlotID(slot_ID),types);
		return types.Count();
	}
	
	//! Lists all configured types (if any) for the appropriate attachment
	static ref array<string> GetConfigAttachmentTypes(int slot_ID)
	{
		TStringArray types = new TStringArray;
		GetGame().ConfigGetTextArray(GetPathFromSlotID(slot_ID),types);
		return types;
	}
	
	//! Lists all customizable InventorySlots
	static ref array<int> GetAttachmentSlotsArray()
	{
		return m_AttachmentSlots;
	}
	
	//! for conversion of slot ID to config array's string
	static ref array<string> GetConfigArrayNames()
	{
		return m_ConfigArrayNames;
	}
}

// -------------------------------------------------------------------------
/*
// Option Access Type
const int AT_UNKNOWN = 0;
const int AT_OBJECTS_DETAIL = 1;
const int AT_TEXTURE_DETAIL = 2;
const int AT_HDR_DETAIL = 4;
const int AT_FSAA_DETAIL = 5;
const int AT_VSYNC_VALUE = 6;
const int AT_ANISO_DETAIL = 7;
const int AT_OPTIONS_FXAA_VALUE = 8;
const int AT_OPTIONS_SW_VALUE = 10;
const int AT_POSTPROCESS_EFFECTS = 11;
const int AT_QUALITY_PREFERENCE = 12;
const int AT_ATOC_DETAIL = 13;
const int AT_AMBIENT_OCCLUSION = 14;
const int AT_BLOOM = 15;
const int AT_ROTATION_BLUR = 16;
const int AT_SHADOW_DETAIL = 18;
const int AT_OPTIONS_TERRAIN = 19;
const int AT_OPTIONS_RESOLUTION = 20;
const int AT_OPTIONS_GAMMA_SLIDER = 23;
const int AT_OPTIONS_BRIGHT_SLIDER = 24;
const int AT_OPTIONS_VISIBILITY_SLIDER = 25;
const int AT_OPTIONS_OBJECT_VISIBILITY_SLIDER = 26;
const int AT_OPTIONS_SHADOW_VISIBILITY_SLIDER = 28;
const int AT_OPTIONS_DRAWDISTANCE_SLIDER = 29;
const int AT_ASPECT_RATIO = 34;
const int AT_CONFIG_YREVERSED = 36;
const int AT_OPTIONS_FIELD_OF_VIEW = 38;
const int AT_OPTIONS_MUSIC_SLIDER = 39;
const int AT_OPTIONS_EFFECTS_SLIDER = 40;
const int AT_OPTIONS_VON_SLIDER = 41;
const int AT_OPTIONS_MASTER_VOLUME = 42;
const int AT_OPTIONS_HWACC = 46;
const int AT_OPTIONS_EAX = 47;
const int AT_OPTIONS_LANGUAGE = 49;
const int AT_OPTIONS_RADIO = 51;
const int AT_CONFIG_XAXIS = 52;
const int AT_CONFIG_YAXIS = 53;
const int AT_CONFIG_MOUSE_FILTERING = 55;
const int AT_CONFIG_HEAD_BOB = 56;
const int AT_CONFIG_CONTROLLER_XAXIS = 58,
const int AT_CONFIG_CONTROLLER_YAXIS = 59,
const int AT_CONFIG_CONTROLLER_REVERSED_LOOK = 60,
const int AT_OPTIONS_DISPLAY_MODE = 61,
const int AT_OPTIONS_TERRAIN_SHADER = 62,
const int AT_OPTIONS_AIM_HELPER = 63,
const int AT_OPTIONS_MOUSE_AND_KEYBOARD = 64,

// Option Access Control Type
const int OA_CT_NUMERIC = 0;
const int OA_CT_SWITCH = 1;
const int OA_CT_LIST = 2;

// Option Field of view constants
const float OPTIONS_FIELD_OF_VIEW_MIN = 0.75242724772f;
const float OPTIONS_FIELD_OF_VIEW_MAX = 1.30322025726f;
*/

class OptionsAccess: Managed
{
	//proto private void ~OptionsAccess();
	//proto private void OptionsAccess();

	/**
	\brief AccessType of current option
 	\return AccessType
	*/
	proto native  int	GetAccessType();
	
	/**
	\brief Current option controller type. OA_CT_NUMERIC = 0, OA_CT_SWITCH = 1, OA_CT_LIST = 2
	\return ControlType
	*/
	proto native  int	GetControlType();
	
	/**
	\brief Applies the option value if the value has changed and forgets the old value. This function has no effect on internal options, see OptionsAccess::Test
	*/
	proto native  void	Apply();
	
	/**
	\brief Sets the option value internaly if the value has changed and wasnt set immediately upon change
	*/
	proto native  void	Test();
	
	/**
	\brief Reverts the option value to old value if the value has changed and wasnt applied. This function has effect on internal options
	*/	
	proto native  void	Revert();
	
	/**
	\brief If the option value is changed and not applied or reverted. Value can already be set internally if the value was changed immediately
	\return 1 if the value is changed, 0 othewise
	*/
	proto native  int	IsChanged();
	
	/**
	\brief If the option value will take effect only after the game is restarted
	\return 1 if the value is changed, 0 othewise
	*/
	proto native  int	NeedRestart();
	
	/**
	\brief If the value is changed internally immediately upon change.
	\return 1 if the value is changed immediately, 0 othewise
	*/
	proto native  int	SetChangeImmediately();
};

// -------------------------------------------------------------------------
class NumericOptionsAccess extends OptionsAccess
{
	proto native  float	ReadValue();
	proto native  void	WriteValue(float value);
	proto native	float	GetMin();
	proto native	float	GetMax();
};

// -------------------------------------------------------------------------
class ListOptionsAccess extends OptionsAccess
{
	proto native int		GetIndex();
	proto native void		SetIndex(int index);
	proto native int		GetItemsCount();
	proto	void					GetItemText(int index, out string value);
};

// -------------------------------------------------------------------------
class SwitchOptionsAccess extends OptionsAccess
{
	proto native void		Switch();
	proto	void					GetItemText(out string value);
	proto native int		GetIndex();
};

// -------------------------------------------------------------------------
class GameOptions: Managed
{	
	/**
	\brief Tests, Applies every option and save config with options to file, see OptionsAccess::Test, OptionsAccess::Apply
	*/
	proto native void	Apply();

	/**
	\brief Load config with options and Revert every option, see OptionsAccess::Revert
	*/
	proto native void	Revert();

	/**
	\brief Tests every option, see OptionsAccess::Test
	*/
	proto native void	Test();

	/**
 	\brief Get option by index
	@param index	
 	\return OptionsAccess
 	*/
	proto native OptionsAccess GetOption(int index);
	
	/**
 	\brief Get option by AccessType
	@param AccessType	
 	\return OptionsAccess
 	*/
	proto native OptionsAccess GetOptionByType(int accessType);
	
	/**
 	\brief Registered options count
 	\return number of options
 	*/
	proto native int GetOptionsCount();

	/**
	\brief Checks if any option is changed and needs restart, see OptionsAccess::IsChanged, OptionsAccess::NeedRestart
	\return 1 if such option was found, 0 othewise
	*/
	proto native int NeedRestart();
	
	/**
	\brief Checks if any option is changed, see OptionsAccess::IsChanged
	\return 1 if such option was found, 0 othewise
	*/
	proto native int IsChanged();
	
	/**
	\brief Initializes option values with the current users settings
	*/
	proto native void Initialize();
};


typedef Link<Object> OLinkT;

/**
 * @fn	SpawnEntity
 * @brief	Spawns entity in known inventory location
 *
 * @param[in]	object_name \p string Name of item class
 * @param[in] inv_loc \p Inventory Location of the spawned item
 * @return		created entity in case of success, null otherwise
 **/
EntityAI SpawnEntity (string object_name, notnull InventoryLocation inv_loc, int iSetupFlags, int iRotation)
{
	return GameInventory.LocationCreateEntity(inv_loc, object_name,iSetupFlags,iRotation);
}

class Static : Object
{
};


class PrtTest // Temporal class for toggling particles on guns
{
	static bool m_GunParticlesState = true;
}

// #include "Scripts/Classes/Component/_include.c"
