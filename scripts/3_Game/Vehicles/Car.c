
//!	Car's sound controller list. (native, do not change or extend)
enum CarSoundCtrl
{
	// simulation
	ENGINE, //!< indicates if engine is ON
	RPM,    //!< engine's RPM
	SPEED,  //!< speed of the car in km/h

	// miscellaneous
	DOORS, //!< indicates if doors are open
	PLAYER //!< indicates if driver is controlled by player
};



//!	Type of vehicle's fluid. (native, do not change or extend)
enum CarFluid
{
	FUEL,
	OIL,
	BRAKE,
	COOLANT,

	USER1, //!< reserved for user / modding support
	USER2, //!< reserved for user / modding support
	USER3, //!< reserved for user / modding support
	USER4  //!< reserved for user / modding support
};



//!	Enumerated vehicle's gears. (native, do not change or extend)
enum CarGear
{
	REVERSE,
	NEUTRAL,
	FIRST,
	SECOND,
	THIRD,
	FOURTH,
	FIFTH,
	SIXTH,
	SEVENTH,
	EIGTH,
	NINTH,
	TENTH,
	ELEVENTH,
	TWELFTH,
	THIRTEENTH,
	FOURTEENTH,
	FIFTEENTH,
	SIXTEENTH
};



//!	Base native class for all motorized wheeled vehicles.
class Car extends Transport
{
	//!	Returns the instance of vehicle's controller.
	proto native CarController GetController();

	//!	Returns the current speed of the vehicle in km/h.
	proto native float GetSpeedometer();
	
	override bool IsAreaAtDoorFree( int currentSeat, float maxAllowedObjHeight = 0.5, float horizontalExtents = 0.5, float playerHeight = 1.7 )
	{
		float speed = GetSpeedometer();
		vector direction = GetDirection();
		vector crewPos;
		vector crewDir;
		CrewEntryWS( currentSeat, crewPos, crewDir );
		crewPos[1] = crewPos[1] + maxAllowedObjHeight + playerHeight * 0.5;
		float vExtents = horizontalExtents;
		if (speed > 8)
			vExtents *= 6;
		if (speed > 8)
			horizontalExtents = 2;
		array<Object> excluded = new array<Object>;
		array<Object> collided = new array<Object>;
		excluded.Insert(this);
		excluded.Insert(GetGame().GetPlayer());
		GetGame().IsBoxColliding(crewPos, crewDir, Vector(horizontalExtents, playerHeight, vExtents), excluded, collided); 
		foreach (Object o : collided)
		{
			EntityAI e = EntityAI.Cast(o);
			vector minmax[2];
			if ( e && e.IsZombie() && e.IsDamageDestroyed() )
				continue;
			
			if ( o.GetCollisionBox(minmax) && !o.CanBeSkinned() ) // CanBeSkinned means it is a dead entity which should not block the door
				return false;
		}
		return true;
	}
	
	override Shape DebugFreeAreaAtDoor( int currentSeat, float maxAllowedObjHeight = 0.5, float horizontalExtents = 0.5, float playerHeight = 1.7 )
	{
		float speed = GetSpeedometer();
		vector direction = GetDirection();
		vector crewPos;
		vector crewDir;
		CrewEntryWS( currentSeat, crewPos, crewDir );
		crewPos[1] = crewPos[1] + maxAllowedObjHeight + playerHeight * 0.5;
		float vExtents = horizontalExtents;
		if (speed > 8)
			vExtents *= 6;
		if (speed > 8)
			horizontalExtents = 2;
		array<Object> excluded = new array<Object>;
		array<Object> collided = new array<Object>;
		excluded.Insert(this);
		excluded.Insert(GetGame().GetPlayer());
		GetGame().IsBoxColliding(crewPos, crewDir, Vector(horizontalExtents, playerHeight, vExtents), excluded, collided); 
		int color = ARGB(20, 0, 255, 0);
		foreach (Object o : collided)
		{
			vector minmax[2];
			if (o.GetCollisionBox(minmax))
			{
				color = ARGB(20, 255, 0, 0);
			}
		}

		return Debug.DrawCylinder(crewPos, horizontalExtents, playerHeight, color);
	}


//-----------------------------------------------------------------------------
// fluids

	/*!
		Returns tank capacity for the specified vehicle's fluid.

		\param fluid the specified fluid type
	*/
	proto native float GetFluidCapacity( CarFluid fluid );

	/*!
		Returns fraction value (in range <0, 1>)
		of the current state of the specified vehicle's fluid.

		\param[in] fluid the specified fluid type
	*/
	proto native float GetFluidFraction( CarFluid fluid );

	//! Removes from the specified fluid the specified amount.
	proto native void Leak( CarFluid fluid, float amount );

	//! Removes all the specified fluid from vehicle.
	proto native void LeakAll( CarFluid fluid );

	//! Adds to the specified fluid the specified amount.
	proto native void Fill( CarFluid fluid, float amount );

	/*!
		Is called every time when the specified vehicle's fluid level
		changes eg. when car is consuming fuel.

		\param[in] fluid fluid identifier, \see CarFluid
		\param[in] newValue new fluid level
		\param[in] oldValue previous fluid level before change
	*/
	void OnFluidChanged( CarFluid fluid, float newValue, float oldValue ) {}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// engine

	//! Returns engine's max rpm before engine blows up.
	proto native float EngineGetRPMMax();

	//! Returns engine's maximal working rpm without damaging the engine.
	proto native float EngineGetRPMRedline();

	//! Returns engine's rpm value.
	proto native float EngineGetRPM();

	//! Returns true when engine is running, false otherwise.
	proto native bool EngineIsOn();

	//! Starts the engine.
	proto native void EngineStart();

	/*!
		Is called every time the game wants to start the engine.

		\return true if the engine can start, false otherwise.
	*/
	bool OnBeforeEngineStart()
	{
		// engine can start by default
		return true;
	}

	//! Is called every time the engine starts.
	void OnEngineStart() {}

	//! Stops the engine.
	proto native void EngineStop();

	//! Is called every time the engine stops.
	void OnEngineStop() {}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// gearbox

	//! Returns total number of gears.
	proto native int GetGearsCount();

	/*!
		Is called every time when the simulation changed gear.

		\param[in] newGear new gear level
		\param[in] oldGear previous gear level before gear shift
	*/
	void OnGearChanged( int newGear, int oldGear )
	{
	}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// events

	/*!
		Is called every time when vehicle collides with other object.

		\param[in] zoneName configured vehicle's zone that was hit
		\param[in] localPos position where the vehicle was hit in vehicle's space
		\param[in] other object with which the vehicle is colliding
		\param[in] data contact properties
	*/
	void OnContact( string zoneName, vector localPos, IEntity other, Contact data ) {}

	/*!
		Is called every sound simulation step.
		In this callback, user can modify behaviour of sound controllers.

		\param[in] ctrl sound controller identifier, \see CarSoundCtrl
		\param[in] oldValue already computed value by the game code
		\return new value of the specified sound controller.
	*/
	float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		// just use the computed value by the game code
		return oldValue;
	}

    /*!
        Is called every game frame.

        \param[in] dt frame time in seconds
    */
    void OnUpdate( float dt ) {}
//-----------------------------------------------------------------------------


	// implemented only in internal configuration
	proto native void ForcePosition( vector pos );
	// implemented only in internal configuration
	proto native void ForceDirection( vector dir );
};



//! Native class for controlling a wheeled vehicle (Car class).
class CarController
{
	//!	Returns the current steering value in range <-1, 1>.
	proto native float GetSteering();
	/*!
		Sets the steering value.

		\param in     should be in range <-1, 1>
		\param analog indicates if the input value was taken from analog controller
	*/
	proto native void SetSteering( float in, bool analog = false );

	//!	Returns the current thrust turbo modifier value in range <0, 1>.
	proto native float GetThrustTurbo();
	//!	Returns the current thrust gentle modifier value in range <0, 1>.
	proto native float GetThrustGentle();
	//!	Returns the current thrust value in range <0, 1>.
	proto native float GetThrust();
	/*!
		Sets the thrust value.

		\param in     should be in range <0, 1>
		\param gentle should be in range <0, 1>, thrust modifier
		\param turbo  should be in range <0, 1>, thrust modifier
	*/
	proto native void SetThrust( float in, float gentle = 0, float turbo = 0 );

	//! Returns the current brake value in range <0, 1>.
	proto native float GetBrake();
	/*!
		Sets the brake value.

		\param in should be in range <0, 1>
	*/
	proto native void SetBrake( float in );

	//!	Returns index of the current gear.
	proto native int GetGear();

	proto native void ShiftUp();
	proto native void ShiftTo( CarGear gear );
	proto native void ShiftDown();
};
