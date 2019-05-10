
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
//! PlayerIdentity, useDB, pos, yaw, queueTime
typedef Param5<PlayerIdentity, bool, vector, float, int> PreloadEventParams;
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
//! PlayerIdentity, QueueTime, NewChar
typedef Param2<int, bool> ClientSpawningEventParams; 
//! Player
typedef Param1<Man> LogoutCancelEventParams; 
//! Error 
typedef Param1<string> DatabaseErrorEventParams; 
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
	//! params: \ref PreloadEventParams
	PreloadEventTypeID,
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
	//! params: \ref ClientSpawningEventParams
	ClientSpawningEventTypeID,
	//! params: \ref LogoutEventParams
	LogoutEventTypeID,	
	//! params: \ref DatabaseErrorEventParams
	DatabaseErrorEventTypeID,	
	//! params: \ref ScriptLogEventParams
	ScriptLogEventTypeID,
	//! params: \ref VONStateEventParams
	VONStateEventTypeID,
	//! params: \ref VONStartSpeakingEventParams
	VONStartSpeakingEventTypeID,
	//! params: \ref VONStopSpeakingEventParams
	VONStopSpeakingEventTypeID,
	//! params: \ref SetFreeCameraEventParams
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
	void Update( float timeslice ){}
	bool IsXboxDebugCursorEnabled();
	void ShowVehicleInfo();
	void HideVehicleInfo();
	void OnResizeScreen();

	void SetPermanentCrossHair( bool show ) {}

};

//-----------------------------------------------------------------------------
//! Mission class
class Mission
{
	ScriptModule MissionScript;

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
	
	void PlayerControlEnable() {}
	void PlayerControlDisable(int mode) {}

	void ShowInventory() {}
	void HideInventory() {}
	
	void ShowChat() {}
	void HideChat() {}

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
	
	proto void 			GetCharacterName(int index, out string name);
	proto native void 	SetCharacterName(int index, string newName);
	// save character is set as last played character 
	proto native void 	SaveCharacter(bool localPlayer, bool verified);
	proto native void 	SaveDefaultCharacter(Man character);
	
	proto native void 	SaveCharactersLocal();
	proto native void 	LoadCharactersLocal();
	proto native void 	ClearCharacters();
	
	//proto native void	GetCharacterStringList(int characterID, string name, out TStringArray values);
	//proto bool			GetCharacterString(int characterID,string name, out string value);
};


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

// -------------------------------------------------------------------------
class Hive
{
	proto native void InitOnline( string host = "" );
	proto native void InitOffline();
	proto native void InitSandbox();

	proto native void SetShardID( string shard );
	proto native void SetEnviroment( string env );

	proto native void CharacterSave( Man player );
	proto native void CharacterKill( Man player );
	proto native void CharacterExit( Man player );

	proto native void CallUpdater( string content );
	
};

proto native Hive CreateHive();
proto native void DestroyHive();
proto native Hive GetHive();



// constants for device (binding device) type determine:
//
//	EUAINPUT_DEVICE_KEYBOARD
//	EUAINPUT_DEVICE_MOUSE
//	EUAINPUT_DEVICE_KEYBOARDMOUSE
//	EUAINPUT_DEVICE_CONTROLLER
//	EUAINPUT_DEVICE_IR

// -------------------------------------------------------------------------
class UAIDWrapper
{
	proto native UAInput InputP();			// get input pointer
};

// -------------------------------------------------------------------------
class UAInput
{
	proto native int ID();			// return input index
	proto native int NameHash();	// return input hash

	proto native int BindingCount();	// return binding count
	proto native int Binding( int iIndex );	// return binding at index

	proto native void ClearBinding();	// remove all bindings

	proto native void BindCombo( string sButtonName );		// bind combo to this input by name (single/ or append to existing button)
	proto native void BindComboByHash( int iHash );			// bind combo to this input by hash (single/ or append to existing button)

	proto native void AddAlternative();						// add new alternative keybind
	proto native void ClearAlternative( int iIndex );		// clear binding alternative by index
	proto native void SelectAlternative( int iIndex );		// select binding alternative by index
	proto native int AlternativeCount();					// get currently assigned alternative count
	proto native int AlternativeIndex();					// get currently selected alternative index
	proto native void ClearDeviceBind( int iDeviceFlags );	// clear binding for specific device(s)

	proto native int BindKeyCount(); // binded key count (for selected alternative)
	proto native int GetBindKey( int iIndex ); // binded "control" at index (for selected alternative)
	proto native int GetBindDevice( int iIndex ); // binded "control" device type at index (for selected alternative)
	proto native bool CheckBindDevice( int iIndex, int iDeviceFlags ); // compare binded device "control" type :: EUAINPUT_DEVICE_KEYBOARD for example

	proto native float LocalValue();

	proto native bool LocalPress();
	proto native bool LocalRelease();
	proto native bool LocalHold();
	proto native bool LocalHoldBegin();
	proto native bool LocalDoubleClick();
	proto native bool LocalClick();

	proto native bool IsCombo();	// return true if there is currently combo bind - use Binding() result !!!

	// normal state is there are no limits, input generates all the events
	// but if there is an limiter, 
	proto native bool IsLimited();	// return true if there is an event limit
	
	proto native bool IsPressLimit();		// if limited to PRESS
	proto native bool IsReleaseLimit();		// if limited to RELEASE
	proto native bool IsHoldLimit();		// if limited to HOLD
	proto native bool IsClickLimit();		// if limited to SINGLE CLICK
	proto native bool IsDoubleClickLimit();	// if limited to DOUBLE CLICK

	proto native bool HasSorting( int iIndex );		// has sorting group index?

	proto native void Supress();			// supress press event for next frame (while not pressed ATM - otherwise until release)

	proto native bool IsLocked();			// determine if locked (not active ATM)
	proto native void Lock();				// lock (until unlock called or exclusion is selected)
	proto native void Unlock();				// unlock exclusively

	proto native int ConflictCount();		// get number of conflicts with other inputs

	proto native void ForceEnable( bool bEnable );	// force enable on/ off
	proto native void ForceDisable( bool bEnable );	// force disable on/ off

	proto native void Backlit_Override( int eType, int iColor ); // enable/ disable backlit of associated controls (EUABACKLIT_*)
	proto native bool Backlit_Enabled(); // check whether associated controls are backlit

	proto native UAIDWrapper GetPersistentWrapper(); // create persistent object for input access

	private void UAInput();
	private void ~UAInput();
};

// -------------------------------------------------------------------------
class UAInterface
{
	// getting action state
	/**
	\brief Get action state
	@param action id of action, defined in \ref 4_World/Classes/UserActionsComponent/_constants.c
	@param check_focus if true and game is unfocused, returns 0; otherwise returns actual value
	@return actual action state as float, for regular two state buttons returns 0 or 1, for analog buttons/axes returns value in interval <0, 1> with consideration of defined deadzones
	@see SyncedValue()
	*/
	proto native float	SyncedValue_ID(int action, bool check_focus = true);
	proto native float	SyncedValue(string action, bool check_focus = true);
		
	/**  
	\brief Returns true just in frame, when action was invoked (button was pressed)
	@param action id of action, defined in \ref 4_World/Classes/UserActionsComponent/_constants.c
	@param check_focus if true and game is unfocused, returns 0; otherwise returns actual value
	@return true if action was invoked in that frame, false otherwise
	@see SyncedPress()
	*/
	proto native bool	SyncedPress_ID(int action, bool check_focus = true);
	proto native bool	SyncedPress(string action, bool check_focus = true);
	
	/**  
	\brief Returns true just in frame, when release action happened (button was released)
	@param action id of action, defined in \ref 4_World/Classes/UserActionsComponent/_constants.c
	@param check_focus if true and game is unfocused, returns 0; otherwise returns actual value
	@return true if action was released in that frame, false otherwise
	@see SyncedRelease()
	*/
	proto native bool	SyncedRelease_ID(int action, bool check_focus = true);
	proto native bool	SyncedRelease(string action, bool check_focus = true);

	/**  
	\brief Returns true just in frame, when hold action invoked (button is hold)
	@param action id of action, defined in \ref 4_World/Classes/UserActionsComponent/_constants.c
	@param check_focus if true and game is unfocused, returns 0; otherwise returns actual value
	@return true if action was released in that frame, false otherwise
	@see SyncedHold()
	*/
	proto native bool	SyncedHold_ID(int action, bool check_focus = true);
	proto native bool	SyncedHold(string action, bool check_focus = true);

	/**  
	\brief Returns true just in frame, when double click action invoked (button double clicked)
	@param action id of action, defined in \ref 4_World/Classes/UserActionsComponent/_constants.c
	@param check_focus if true and game is unfocused, returns 0; otherwise returns actual value
	@return true if action was released in that frame, false otherwise
	@see SyncedDbl()
	*/
	proto native bool	SyncedDbl_ID(int action, bool check_focus = true);
	proto native bool	SyncedDbl(string action, bool check_focus = true);
	
	/**  
	\brief Returns true just in frame, when single click action invoked (button pressed and released before hold timer)
	@param action id of action, defined in \ref 4_World/Classes/UserActionsComponent/_constants.c
	@param check_focus if true and game is unfocused, returns 0; otherwise returns actual value
	@return true if action was released in that frame, false otherwise
	@see SyncedClick()
	*/
	proto native bool	SyncedClick_ID(int action, bool check_focus = true);
	proto native bool	SyncedClick(string action, bool check_focus = true);
	
};

// -------------------------------------------------------------------------
class UAInputAPI
{
	proto native void ListCurrentProfile();
	proto native void ListCurrentPreset();
	proto native void ListAvailableButtons();
	proto native void ListActiveGroup();

	proto native void GetActiveInputs( out TIntArray items ); // return list of all bindable inputs

	proto native UAInput GetInputByID( int iID );
	proto native UAInput GetInputByName( string sInputName );

	proto native owned string GetButtonName( int iHash );	// get localized name for any button hash

	proto native int ModificatorCount();	// modificator count
	proto native owned string GetModificatorName( int index );	// modificator name
	
	// for options only mapping, do not call normally as it is not performance wise!
	proto native int DeterminePressedButton();	// recently pressed key, mouse button or pad button (returns zero if nothing pressed)
	proto native int DeterminedCount(); // all buttons (keys, etc.) pressed during determination test (call only when DeterminePressedButton() returned something !)
	proto native int GetDetermined( int iIndex ); // total count of pressed buttons (call only when DeterminePressedButton() returned something !)

	proto native UAInput RegisterInput( string sInputName, string sLoc, string sGroupName );
	proto native void DeRegisterInput( string sInputName );

	proto native void RegisterGroup( string sGroupName, string sLoc );
	proto native void DeRegisterGroup( string sGroupName );

	proto native void UpdateControls(); // call this on each change of exclusion
	proto native void ActivateGroup( string sGroupName );
	proto native void ActivateExclude( string sExcludeName );
	proto native void ActivateContext( string sContextName );
	proto native void ActivateModificator( string sModName );

	proto native void DeactivateContext();

	proto native bool PresetCreateNew(); // create new preset from the selected one - (false == cannot create new == too many presets!)
	proto native bool PresetDelete( int index ); // delete specific preset - (false == not deletable!)
	proto native int PresetCurrent(); // determine index of current preset - (-1 == not selected)
	proto native void PresetSelect( int index ); // select specific preset
	proto native int PresetCount(); // count of presets
	proto native owned string PresetName( int index ); // name of selected preset

	proto native int SortingCount();				// sorting group count
	proto native owned string SortingName( int index );	// sorting group name

	proto native void Export();	// export XML (user) configuration
	
	proto native void Backlit_None(); // turn off backlit
	proto native void Backlit_Background( int eType, int iColor1, int iColor2 ); // start backlit
	proto native void Backlit_Animation( string strName, float fLifeTime, int iColor1, int iColor2 ); // start backlit animation and after time limit -> continue with another one
	proto native bool Backlit_Enabled(); // check whether backlit active
	proto native void Backlit_KeyByHash( int uHash, int eLayer, int eType, int iColor ); // key directly (during keybinding process) (EUABACKLIT_*)
	proto native void Backlit_KeyByName( string strName, int eLayer, int eType, int iColor ); // key directly (by name) (EUABACKLIT_*)
	proto native void Backlit_Remove( int eLayer ); // turn off layer of backlit
	proto native void Backlit_ForceUpdate(); // this forces update immediately - USE ONLY IN LOADING SEQUENCE !!!
	proto native void Backlit_EmptyQueue(); // empty queue of animations - use if you want to play something immediately

};

proto native UAInputAPI GetUApi();

// -------------------------------------------------------------------------
// object (SF) Spawn Flags (use to setup behavior and/ or trigger functionality)
//
const int ECE_NONE							= 0;
	
const int ECE_SETUP							= 2;	// process full entity setup (when creating NEW entity)
const int ECE_TRACE							= 4;	// trace under entity when being placed (from the point of creation)
const int ECE_CENTER						= 8;	// use center from shape (model) for placement

const int ECE_UPDATEPATHGRAPH				= 32;	// update navmesh when object placed upon it

const int ECE_ROTATIONFLAGS					= 512;	// enable rotation flags for object placement
const int ECE_CREATEPHYSICS					= 1024;	// create collision envelope and related physics data (if object has them)
const int ECE_AIRBORNE						= 4096;	// create flying unit in the air

const int ECE_EQUIP_ATTACHMENTS				= 8192;		// equip with configured attachments
const int ECE_EQUIP_CARGO					= 16384;	// equip with configured cargo
const int ECE_EQUIP							= 24576;	// equip with configured attachments + cargo

const int ECE_NOSURFACEALIGN				= 262144;	// do not align object on surface/ terrain
const int ECE_KEEPHEIGHT					= 524288;	// keep height when creating object (do not use trace or placement on surface)

// note: use predefined combination when not solving something specific
//
const int ECE_IN_INVENTORY					= 787456;	// ECE_CREATEPHYSICS|ECE_KEEPHEIGHT|ECE_NOSURFACEALIGN
const int ECE_PLACE_ON_SURFACE				= 1060;		// ECE_CREATEPHYSICS|ECE_UPDATEPATHGRAPH|ECE_TRACE
const int ECE_OBJECT_SWAP					= 787488;	// ECE_CREATEPHYSICS|ECE_UPDATEPATHGRAPH|ECE_KEEPHEIGHT|ECE_NOSURFACEALIGN


// -------------------------------------------------------------------------
// object (RF) Rotation Flags (use to force and/ or invoke placement rotation)
//
const int	RF_NONE					= 0;

const int	RF_FRONT				= 1;	// front side placement
const int	RF_TOP					= 2;	// top side placement
const int	RF_LEFT					= 4;	// left side placement
const int	RF_RIGHT				= 8;	// right side placement
const int	RF_BACK					= 16;	// back side placement
const int	RF_BOTTOM				= 32;	// bottom side placement

const int	RF_ALL					= 63;	// RF_FRONT|RF_TOP|RF_LEFT|RF_RIGHT|RF_BACK|RF_BOTTOM

const int	RF_IGNORE				= 64;	// ignore placement RF flags - object will spawn as model was created

const int	RF_TOPBOTTOM			= 34;	// RF_TOP|RF_BOTTOM
const int	RF_LEFTRIGHT			= 12;	// RF_LEFT|RF_RIGHT
const int	RF_FRONTBACK			= 17;	// RF_FRONT|RF_BACK

const int	RF_RANDOMROT			= 64;	// allow random rotation around axis when placing
const int	RF_ORIGINAL				= 128;	// use default placement setuped on object in config
const int	RF_DECORRECTION			= 256;	// angle correction when spawning InventoryItem at Building angle
const int	RF_DEFAULT				= 512;	// use default placement setuped on object in config


class CETesting
{
	proto native void ExportSpawnData();
	proto native void ExportProxyData( vector vCenter, float fRadius );
	proto native void ExportClusterData();
	proto native void ExportProxyProto();
	proto native void MarkCloseProxy( float fRadius, bool bAllSelections );
	proto native void RemoveCloseProxy();
	proto native void ListCloseProxy( float fRadius );

	proto native void SpawnAnalyze( string sClassName );

	proto native void TimeShift( float fShift );
	proto native void OverrideLifeTime( float fLifeTime );

	proto native void NewRestock( bool bEnable );

	proto native void SpawnGroup( string sEvName, vector vPos );
	proto native void SpawnDE( string sEvName, vector vPos, float fAngle ); /* THIS WILL BE OBSOLETE OR PREFERABLY DEFAULT? */
	proto native void SpawnDE_WIP( string sEvName, vector vPos, float fAngle, int uFlags );
	proto native void SpawnLoot( string sEvName, vector vPos, float fAngle, int iCount, float fRange );

	proto native void SpawnDynamic( vector vPos, bool bShowCylinders );
	proto native void SpawnVehicles( vector vPos, bool bShowCylinders );
	proto native void SpawnBuilding( vector vPos, bool bShowCylinders );

	proto native void SpawnEntity( string sClassName, vector vPos, float fRange, int iCount );
	proto native void SpawnRotation( string sClassName, vector vPos, float fRange, int iCount, int iFlags );
	proto native void SpawnPerfTest( string sClassName, int iCount );
	proto native void CleanMap();

	proto native void PlatformStatTest();

	proto native void EconomyLog( string sLogType );
	proto native void EconomyMap( string sMapType );
	proto native void EconomyOutput( string sOutputType, float fRange );

};

proto native CETesting GetTesting();

// -------------------------------------------------------------------------
class CEItemProfile
{
	proto native int GetNominal(); // nominal - how many items should be aproximately in map
	proto native int GetMin(); // min - minimal count should be available in map

	proto native float GetQuantityMin(); // min quantity (0.0 - 1.0) (like ammobox - this determine how many bullets are there, or water bottle)
	proto native float GetQuantityMax(); // max quantity (0.0 - 1.0) (like ammobox - this determine how many bullets are there, or water bottle)

	proto native float GetQuantity(); // random quantity (0.0 - 1.0)

	proto native float GetLifetime(); // lifetime in (seconds) - what is the idle before item abandoned at ground gets deleted
	proto native float GetRestock(); // restock is oposite of lifetime - idle before item is allowed to respawn when required

	proto native int GetCost(); // cost of item determines its 'value' for players (this serve as priority during respawn and cleanup operation)

	proto native int GetUsageFlags(); // area usage flags (each bit has assigned group - which as part of map overlay effectively affects spawning)
	proto native int GetValueFlags(); // area value flags (each bit has assigned group - which as part of map overlay effectively affects spawning)
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
