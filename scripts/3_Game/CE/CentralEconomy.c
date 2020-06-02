
/** @file */

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

const int ECE_EQUIP_ATTACHMENTS				= 8192;		// equip with configured ATTACHMENTS
const int ECE_EQUIP_CARGO					= 16384;	// equip with configured CARGO
const int ECE_EQUIP							= 24576;	// equip with configured (ATTACHMENTS + CARGO)
const int ECE_EQUIP_CONTAINER				= 2097152;	// populate DE/ group CONTAINER during spawn
const int ECE_LOCAL							= 1073741824; // create object locally

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


class CEApi
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

	//! Process lifetime increase withing radius by value (sec)
	proto native void OnRadiusLifetimeIncrease( vector vCenter, float fRadius, float fValue );
	//! Process lifetime decrease withing radius by value (sec)
	proto native void OnRadiusLifetimeDecrease( vector vCenter, float fRadius, float fValue );
	//! Process lifetime reset withing radius to default value from DB
	proto native void OnRadiusLifetimeReset( vector vCenter, float fRadius );

};

proto native CEApi GetCEApi();

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
