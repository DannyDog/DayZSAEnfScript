/*!
	All classes related to game weather
*/


//-----------------------------------------------------------------------------
/*!
	Weather phenomenon type
*/
enum EWeatherPhenomenon
{
	OVERCAST,
	FOG,
	RAIN
};


//-----------------------------------------------------------------------------
/*!
	Weather phenomenon
*/
class WeatherPhenomenon
{
	//! Returns type of this phenomenon.
	proto native EWeatherPhenomenon GetType();

	//! Returns actual value of phenomenon in range <0, 1>.
	proto native float GetActual();

	//! Returns a forecast value the phenomenon is heading towards.
	proto native float GetForecast();

	/*!
		\brief Sets the forecast.
		\param forecast     Desired forecast value that should be met in given time.
		\param time         A time of the next change (how long it takes in seconds to interpolate to given value).
		\param minDuration  A minimal time in seconds the change will last.
	*/
	proto native void Set( float forecast, float time = 0, float minDuration = 0 );

	//! Reads the time in seconds when the next forecast will be computed.
	proto native float GetNextChange();
	//! Sets the time in seconds when the next forecast will be computed.
	proto native void SetNextChange( float time );

	/*!
		\brief Reads limits of this phenomenon.
		\param fnMin Function minimum (in range <0, 1>).
		\param fnMax Function maximum (in range <0, 1>).
	*/
	proto void GetLimits( out float fnMin, out float fnMax );
	/*!
		\brief Sets limits of this phenomenon.

		Actual value of this phenomenon will be always held in range <fnMin, fnMax>.

		Default values are:
			fnMin  = 0
			fnMax  = 1

		\param fnMin Function minimum (in range <0, 1>).
		\param fnMax Function maximum (in range <0, 1>).
	*/
	proto native void SetLimits( float fnMin, float fnMax );

	/*!
		\brief Reads limits of change when forecast is computed.
		\param fcMin Forecast change minimum (in range <0, 1>).
		\param fcMax Forecast change maximum (in range <0, 1>).
	*/
	proto void GetForecastChangeLimits( out float fcMin, out float fcMax );
	/*!
		\brief Sets limits of change when forecast is computed.

		These limits govern how much the forecast value can change
		when it is computed by weather controller.

		Default values are:
			fcMin  = 0
			fcMax  = 1

		\param fcMin Forecast change minimum (in range <0, 1>).
		\param fcMax Forecast change maximum (in range <0, 1>).
	*/
	proto native void SetForecastChangeLimits( float fcMin, float fcMax );

	/*!
		\brief Reads time range in which next forecast can be computed.
		\param ftMin Minimal number of seconds.
		\param ftMax Maximal number of seconds.
	*/
	proto void GetForecastTimeLimits( out float ftMin, out float ftMax );
	/*!
		\brief Sets time range in which next forecast can be computed.

		Default values are:
			ftMin  = 300  (5 minutes)
			ftMax  = 3600 (1 hour)

		\param ftMin Minimal number of seconds.
		\param ftMax Maximal number of seconds.
	*/
	proto native void SetForecastTimeLimits( float ftMin, float ftMax );

	/*!
		\brief Is called every time the Phenomenon computes new forecast.

		\note Called on server only.

		\param change Computed change of forecast value.
		\param time   Seconds when the next forecast will be computed.
		\return True when script modifies state of this phenomenon false otherwise.
	*/

	bool OnBeforeChange( float change, float time )
	{
		Weather weather = g_Game.GetWeather();
		
		if ( weather.GetMissionWeather() )
			return false;
		
		float rainMin;
		float rainMax;
		float rainTime;
		float rainTimeDur;

		float rainActual = weather.GetRain().GetActual();
		
		float overcastActual = weather.GetOvercast().GetActual();
		float overcastForecast = weather.GetOvercast().GetForecast();
		float overcastNextChange = weather.GetOvercast().GetNextChange();
		
		float overcastInverted = 1.0 - overcastActual;

		weather.SetRainThresholds( 0.75, 1.0, 30 );
		weather.SetWindMaximumSpeed( 30 );

		switch( GetType() )
		{
			case EWeatherPhenomenon.OVERCAST:
				Print( "COMPUTING NEW OVERCAST" );

				float rangeMin = 0.15;
				float rangeHigh = 0.85;
			
				float timeChangeLow = 1800.0;
				float timeChangeMid = 1.5 * timeChangeLow;
				float timeChangeHigh = 2 * timeChangeLow;

				float timeRange = timeChangeLow;
			
				float overcastMid = 0.5;
				float overcastRange = 0.1;

				float rand = Math.RandomFloatInclusive( 0.0, 1.0 );

				if ( rand > rangeMin && rand < rangeHigh )
				{
					overcastMid = 0.5;
					overcastRange = 0.2;
				
					weather.SetWindFunctionParams( 0.1, 0.4, 30 );

					//m_clrCounter += 0.1;
					//m_badCounter -= 0.1;
				}
				else if ( rand <= rangeMin )
				{
					overcastMid = 0.25;
					overcastRange = 0.12;
				
					weather.SetWindFunctionParams( 0.02, 0.2, 30 );

					if ( GetActual() > rangeHigh )
					{
						timeRange = timeChangeHigh;
						weather.SetWindFunctionParams( 0.2, 0.6, 40 );
					}
					else if ( GetActual() > rangeMin )
					{
						timeRange = timeChangeMid;
						weather.SetWindFunctionParams( 0.1, 0.4, 30 );
					}
					else
					{
						timeRange = timeChangeLow;
						weather.SetWindFunctionParams( 0.02, 0.1, 20 );
					}

					//m_clrCounter -= 0.1;
					//m_badCounter -= 0.1;
				}
				else
				{
					overcastMid = 0.8;
					overcastRange = 0.2;

					if ( GetActual() < rangeMin )
					{
						timeRange = timeChangeHigh;
						weather.SetWindFunctionParams( 0.2, 0.8, 50 );
					}
					else if ( GetActual() > rangeHigh )
					{
						timeRange = timeChangeLow;
						float maxWind = Math.RandomFloatInclusive( 0.7, 1.0 );
						weather.SetWindFunctionParams( 0.7, maxWind, 50 );
					}
					else
					{
						timeRange = timeChangeMid;
						weather.SetWindFunctionParams( 0.4, 0.8, 50 );
					}

					//m_clrCounter += 0.1;
					//m_badCounter += 0.1;
				}
			
				float nextOvercast = Math.RandomFloatInclusive( overcastMid - overcastRange, overcastMid + overcastRange );
				Set( nextOvercast, timeRange, 0 );
				//SetNextChange( timeRange );

				Print( "Actual " + "( " + g_Game.GetDayTime() + " )" + " overcast: " + GetActual() );
				Print( "Actual " + "( " + g_Game.GetDayTime() + " )" + " rain: " + rainActual );
				Print( "-----------------------------------------------------------" );	

				return true;

			case EWeatherPhenomenon.FOG:
				Print( "COMPUTING NEW FOG" );
				Print( "Actual " + "( " + g_Game.GetDayTime() + " )" + " fog: " + GetActual() );
				Print( "-----------------------------------------------------------" );
				
				float fogMin = 0.0;
				float fogMax = 0.15;
				float fogTime = 1800.0;

				float fogyMorning = Math.RandomFloatInclusive( 0.0, 1.0 );

				if (  fogyMorning > 0.85 )
				{
					if ( (g_Game.GetDayTime() > 4 && g_Game.GetDayTime() < 7 ) )
					{
						fogMin = 0.10;
						fogMax = 0.35;
						fogTime = 300;
					}
				}

				if ( overcastActual < 0.3 )
				{
					fogMin = 0.0;
					fogMax = 0.08;
					fogTime = 900.0;
				}

				Set( Math.RandomFloatInclusive( fogMin, fogMax ), fogTime, 0);
				return true;
			
			case EWeatherPhenomenon.RAIN:
				Print( "COMPUTING NEW RAIN" );

				if ( GetActual() > 0.1 && overcastActual <= 0.95 )
				{
					rainMin = 0.0;
					rainMax	= 0.05;
					rainTime = Math.RandomFloatInclusive( overcastActual*20, overcastActual*60 );	// *10 converting to seconds *2-12 muting rain 
					rainTimeDur = Math.RandomFloatInclusive( overcastInverted*1200, overcastInverted*1800 );
				}
				else if ( overcastActual > 0.8 )
				{
					rainMin = 0.1;
					rainMax	= 0.4;
					rainTime = Math.RandomFloatInclusive( 120, 240 );
					rainTimeDur = Math.RandomFloatInclusive( 30, 60 );
				}
				else if ( overcastActual > 0.9 )
				{
					rainMin = 0.4;
					rainMax	= 0.7;
					rainTime = Math.RandomFloatInclusive( 60, 120 );
					rainTimeDur = Math.RandomFloatInclusive( 60, 120 );
				}
				else if ( overcastActual > 0.95 )
				{
					rainMin = 0.5;
					rainMax	= 0.8;
					rainTime = Math.RandomFloatInclusive( 10, 60 );
					rainTimeDur = Math.RandomFloatInclusive( 120, 240 );
				}
				else
				{
					rainMin = 0.0;
					rainMax	= 0.3;
					rainTime = Math.RandomFloatInclusive( 240, 300 );
					rainTimeDur = Math.RandomFloatInclusive( 90, 120 );
				}
				
				Set( Math.RandomFloatInclusive(rainMin, rainMax), rainTime, rainTimeDur );
/*
				if ( overcastNextChange < rainTime + rainTimeDur )
					SetNextChange( overcastNextChange );
				else
*/
				//SetNextChange(rainTime + rainTimeDur);

				
				Print( "Actual " + "( " + g_Game.GetDayTime() + " )" + " rain: " + GetActual() );
				Print( "-----------------------------------------------------------" );
				
				return true;
		}

		return false;
	}
};


typedef WeatherPhenomenon Overcast;
typedef WeatherPhenomenon Fog;
typedef WeatherPhenomenon Rain;




//-----------------------------------------------------------------------------
/*!
	Weather controller
*/
class Weather
{
	protected bool m_missionWeather;
	
	void Weather()
	{
		m_missionWeather = false;
	}
	
	//! Returns actual time from start of a server (how many seconds elapsed from server start).
	proto native float GetTime();

	//! Returns an overcast phenomenon object.
	proto native Overcast GetOvercast();

	//! Returns a fog phenomenon object.
	proto native Fog GetFog();

	//! Returns a rain phenomenon object.
	proto native Rain GetRain();

	/*!
		\brief Sets the thunderstorm properties.
		\param  density   A value in <0, 1> range where 0 means no thunderstorms at all
		                  and 1 means thunderstorm every time it gets cloudy.
		\param  threshold The overcast value that must be exceeded so that lightning can appear.
		\param  timeOut   A minimal time in seconds between lightning during thunderstorm.
	*/
	proto native void SetStorm( float density, float threshold, float timeOut );

	//! Returns wind vector (direction and speed as length of the vector).
	proto native vector GetWind();
	//! Sets the wind vector (direction and speed as length of the vector).
	proto native void SetWind( vector wind );
	/*!
		\brief Returns actual wind speed in metre per second.
		\note Wind is changing continuously in time, so the returned value may not stand for too long.
	*/
	proto native float GetWindSpeed();
	/*!
		\brief Sets the actual wind speed in metre per second.
		\note Wind is changing continuously in time, so the returned value may not stand for too long.
		      Minimum speed for wind is 0.1 m/s.
	*/
	proto native void SetWindSpeed( float speed );
	/*!
		\brief Returns maximal wind speed in metre per second.
		\note By default this value is 10 m/s but it can be overridden in script on mission initialization.
	*/
	proto native float GetWindMaximumSpeed();
	//! Sets the maximal wind speed in metre per second.
	proto native void SetWindMaximumSpeed( float maxSpeed );
	/*!
		\brief Reads function parameters that controls the wind behaviour (change in time).
		\param fnMin   Function relative minimum (in range <0, 1>).
		\param fnMax   Function relative maximum (in range <0, 1>).
		\param fnSpeed Controls speed of change of function value.
	*/
	proto void GetWindFunctionParams( out float fnMin, out float fnMax, out float fnSpeed );
	/*!
		\brief Sets function parameters that controls the wind behaviour (change in time).
		\param fnMin   Function relative minimum (in range <0, 1>).
		\param fnMax   Function relative maximum (in range <0, 1>).
		\param fnSpeed Controls speed of change of function value.
	*/
	proto native void SetWindFunctionParams( float fnMin, float fnMax, float fnSpeed );

	/*!
		\brief Sets overcast threshold values for rain phenomena.

		Rain can start only if actual overcast value is in given range of <tMin, tMax>.
		If it's already raining and actual overcast value gets out of given range
		then rain will stop in given tTime seconds.

		Default values are:
			tMin  = 0.6
			tMax  = 1
			tTime = 30

		\param tMin  Minimal overcast value (in range <0, 1>).
		\param tMax  Maximal overcast value (in range <0, 1>).
		\param tTime Time in seconds when it stops raining.
	*/
	proto native void SetRainThresholds( float tMin, float tMax, float tTime );

	void MissionWeather( bool use )
	{
		m_missionWeather = use;
	}
	
	bool GetMissionWeather()
	{
		return m_missionWeather;
	}

};
