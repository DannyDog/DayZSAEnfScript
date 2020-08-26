#define _ARMA_

class CfgPatches
{
	class DZ_AI_Bliss
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data_Bliss"};
	};
};
class CfgAIBehaviours
{
	class Predator_UrsusArctos
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "Predator";
		defaultGroupTemplateName = "BlissBearGroupBeh";
		class PathAgent
		{
			radius = 0.25;
			height = 1.8;
		};
		class BehaviourHLBear
		{
			instantAlertRangeMin = 15.0;
			instantAlertRangeMax = 50.0;
			instantAlertStrength = 10.0;
			enragedReachDistanceMax = 6.0;
			enragedReachDistanceMin = 2.5;
			predictReachFollowingMaxDistance = 10.0;
			predictReachFollowingTime = 0.5;
			annoyanceDistance = 30.0;
			annoyanceTimerMin = 8.0;
			annoyanceTimerMax = 12.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 5;
					grazeWalkingWeight = 5;
					restWeight = 0;
					travelWeight = 0;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 60;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 60;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 20;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 2.6;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.24;
						minSpeed = 0.24;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.5;
						minSpeed = 0.55;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
				};
			};
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 0;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 40;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 15;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 25;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 2.6;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.24;
						minSpeed = 0.24;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.5;
						minSpeed = 0.55;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 0;
					travelWeight = 20;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 30;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 15;
					restingDurationMin = 0;
					restingDurationMax = 0;
					travelingDurationMin = 30;
					travelingDurationMax = 50;
					safetyDurationMin = 15;
					safetyDurationMax = 25;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 2.6;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.24;
						minSpeed = 0.24;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.5;
						minSpeed = 0.55;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 0;
					travelWeight = 10;
					drinkingWeight = 0;
					grazeOnSpotDurationMin = 100;
					grazeOnSpotDurationMax = 100;
					grazeWalkingDurationMin = 100;
					grazeWalkingDurationMax = 100;
					restingDurationMin = 200;
					restingDurationMax = 200;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					drinkingDurationMin = 150;
					drinkingDurationMax = 150;
					safetyDurationMin = 15;
					safetyDurationMax = 20;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 2.6;
					safetyLookAngleChangeInterval = 7;
					class DrinkingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class GrazeMovement
					{
						maxSpeed = 0.24;
						minSpeed = 0.24;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.5;
						minSpeed = 0.55;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 10;
					walkToWeight = 0;
					stayLookAtWeight = 15;
					stayWeight = 0;
					walkAwaySpreadAngle = 3.5;
					walkAwayInitialAngle = 3.5;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 12;
					walkAwayDurationMax = 18;
					walkToDurationMin = 4;
					walkToDurationMax = 8;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 15;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.55;
					};
				};
			};
			class SlotSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 10;
					walkToWeight = 10;
					stayLookAtWeight = 20;
					stayWeight = 0;
					walkAwaySpreadAngle = 3.5;
					walkAwayInitialAngle = 3.5;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 12;
					walkAwayDurationMax = 18;
					walkToDurationMin = 10;
					walkToDurationMax = 15;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 15;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 1.0;
						minSpeed = 0.55;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 3.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.56;
					};
				};
			};
			class SlotIntimidate
			{
				class BehaviourInfectedPackEnraged
				{
					class Movement
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						acceleration = 4.0;
						maxAngleSpeed = 120.0;
						slowRadius = 1.5;
						stopRadius = 0.8;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class MovementApproaching
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						optimalSpeed = 0.6;
						acceleration = 1.5;
						maxAngleSpeed = 40.0;
						slowRadius = 1.0;
						stopRadius = 0.2;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class MovementReach
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						acceleration = 4.0;
						maxAngleSpeed = 120.0;
						slowRadius = 5.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
				};
			};
			class SlotEnraged
			{
				class BehaviourInfectedPackEnraged
				{
					class Movement
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						acceleration = 4.0;
						maxAngleSpeed = 120.0;
						slowRadius = 1.5;
						stopRadius = 0.8;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class MovementApproaching
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						acceleration = 1.5;
						maxAngleSpeed = 40.0;
						slowRadius = 1.0;
						stopRadius = 0.2;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class MovementReach
					{
						maxSpeed = 8.0;
						minSpeed = 0.55;
						acceleration = 4.0;
						maxAngleSpeed = 120.0;
						slowRadius = 5.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
				};
			};
			class SlotScared
			{
				class BehaviourGoToTarget
				{
					class Movement
					{
						maxSpeed = 3.3;
						optimalSpeed = 1.0;
						minSpeed = 0.55;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 20.0;
						acceleration = 5.0;
						maxAngleSpeed = 60.0;
						slowRadius = 4.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 0.61;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 6.0;
				noiseToAlertMultiplier = 1.2;
				noiseShotToAlertMultiplier = 0.5;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 9;
					dropDelay = 1;
					maxAlertValue = 25;
				};
				class NonSpecificThreat
				{
					dropSpeed = 9;
					dropDelay = 25;
					maxAlertValue = 50;
				};
				class SpecificThreat
				{
					dropSpeed = 5;
					dropDelay = 15;
					maxAlertValue = 75;
				};
				class Alerted
				{
					dropSpeed = 5;
					dropDelay = 5;
					maxAlertValue = 200;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 20.0;
			rangeMax = 110.0;
			rangeShotMin = 100.0;
			rangeShotMax = 300.0;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 0.8;
				Zombies = 1.0;
				Player = 1.0;
			};
		};
		class TargetSystemDZBase
		{
			class VisionTeamMultipliers
			{
				BigGame = 1.0;
				Zombies = 1.0;
				Player = 1.0;
				Predator = 1.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.5;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.5;
			visionRangeMin = 20;
			visionRangeMax = 60;
			visionFov = 2.0;
			visionPeripheralRangeMin = 1;
			visionPeripheralRangeMax = 30;
			visionPeripheralFov = 3.2;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.75;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 0.9;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 0.7;
		};
	};
};
class CfgNoises
{
	class WolfStepNoise
	{
		type = "sound";
		continuousRange = 100;
		strength = 0;
	};
	class WolfRoarNoise
	{
		type = "sound";
		continuousRange = 100;
		strength = 0;
	};
};
class CfgDamages
{
	class BearBiteDamage
	{
		bone = "tongue4";
		ammo = "MeleeBear";
		radius = 0.7;
		duration = 0.2;
	};
	class BearLeftPawDamage
	{
		bone = "lflegdigit11";
		ammo = "MeleeBear";
		radius = 0.7;
		duration = 0.2;
	};
	class BearRightPawDamage
	{
		bone = "rflegdigit11";
		ammo = "MeleeBear";
		radius = 0.7;
		duration = 0.2;
	};
	class BearBiteDamageIntimidate
	{
		bone = "tongue4";
		ammo = "MeleeBearShock";
		radius = 0.7;
		duration = 0.2;
	};
	class BearLeftPawDamageIntimidate
	{
		bone = "lflegdigit11";
		ammo = "MeleeBearShock";
		radius = 0.7;
		duration = 0.2;
	};
	class BearRightPawDamageIntimidate
	{
		bone = "rflegdigit11";
		ammo = "MeleeBearShock";
		radius = 0.7;
		duration = 0.2;
	};
};
