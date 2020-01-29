#define _ARMA_

class CfgPatches
{
	class DZ_AI
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgAIBehaviours
{
	class Herbivores
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "BigGame";
		defaultGroupTemplateName = "DZDeerGroupBeh";
		class PathAgent
		{
			radius = 0.25;
			height = 1.8;
		};
		class BehaviourHLDeer
		{
			instantAlertRangeMin = 20.0;
			instantAlertRangeMax = 50.0;
			instantAlertStrength = 7.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 5;
					grazeWalkingWeight = 5;
					restWeight = 20;
					travelWeight = 0;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 40;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 30;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 10;
					safetyDurationMax = 15;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.2;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 1.36;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.0;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
				};
			};
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 10;
					travelWeight = 0;
					grazeOnSpotDurationMin = 50;
					grazeOnSpotDurationMax = 100;
					grazeWalkingDurationMin = 50;
					grazeWalkingDurationMax = 100;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 20;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.2;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 1.36;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class CatchUpMovement
					{
						maxSpeed = 1.36;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
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
					travelWeight = 50;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 30;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 30;
					restingDurationMin = 0;
					restingDurationMax = 0;
					travelingDurationMin = 20;
					travelingDurationMax = 30;
					safetyDurationMin = 15;
					safetyDurationMax = 25;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 0.4;
					safetyLookAngleChangeInterval = 5;
					class GrazeMovement
					{
						maxSpeed = 0.2;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 1.36;
						minSpeed = 0.8;
						acceleration = 1.0;
						maxAngleSpeed = 10.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 0.81;
					};
					class CatchUpMovement
					{
						maxSpeed = 5.8;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 10;
					travelWeight = 0;
					drinkingWeight = 20;
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
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class DrinkingMovement
					{
						maxSpeed = 1.359;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class GrazeMovement
					{
						maxSpeed = 0.2;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 1.359;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.0;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourNonSpecificThreat
				{
					lookWeight = 30;
					sniffWeight = 0;
					sniffDuration = 0.5;
					lookDuration = 6.0;
				};
			};
			class SlotSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					class WalkingMovement
					{
						maxSpeed = 1.359;
						minSpeed = 0.0;
						acceleration = 5.0;
						maxAngleSpeed = 180.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					lookWeight = 10;
					walkWeight = 0;
					walkSpeed = 0.4;
					rotateAtStartAngleTolerance = 0.5;
					maxRotateAngle = 2.5;
					walkDuration = 15.0;
					lookDuration = 6.0;
				};
			};
			class SlotAlerted
			{
				class BehaviourFleeFromTargets
				{
					minDistanceToTargetRatio = 0.5;
					class RunMovement
					{
						maxSpeed = 17.0;
						optimalSpeed = 12.0;
						minSpeed = 1.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 15.0;
						acceleration = 4.0;
						maxAngleSpeed = 70.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 1.4;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 7;
				noiseToAlertMultiplier = 1.0;
				damageToAlertMultiplier = 1.0;
				class Calm
				{
					dropSpeed = 5;
					dropDelay = 1;
					maxAlertValue = 25;
				};
				class NonSpecificThreat
				{
					dropSpeed = 5;
					dropDelay = 10;
					maxAlertValue = 50;
				};
				class SpecificThreat
				{
					dropSpeed = 2;
					dropDelay = 10;
					maxAlertValue = 75;
				};
				class Alerted
				{
					dropSpeed = 10;
					dropDelay = 10;
					maxAlertValue = 100;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 50.0;
			rangeMax = 120.0;
			rangeShotMin = 0.0;
			rangeShotMax = 10.0;
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
				Predator = 10.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.5;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.5;
			visionRangeMin = 20;
			visionRangeMax = 100;
			visionFov = 2.0;
			visionPeripheralRangeMin = 1;
			visionPeripheralRangeMax = 30;
			visionPeripheralFov = 3.2;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.5;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 0.8;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 0.4;
		};
	};
	class Herbivores_BosTaurus
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "BigGame";
		defaultGroupTemplateName = "DZdomesticGroupBeh";
		class PathAgent
		{
			radius = 0.4;
			height = 1.8;
		};
		class BehaviourHLDomestic
		{
			instantAlertRangeMin = 10.0;
			instantAlertRangeMax = 40.0;
			instantAlertStrength = 9.0;
			agentPathLength = 30.0;
			agentPathUpdateDelta = 1.0;
			agentPathMinLength = 2.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 50;
					grazeWalkingWeight = 20;
					restWeight = 50;
					travelWeight = 0;
					grazeOnSpotDurationMin = 40;
					grazeOnSpotDurationMax = 120;
					grazeWalkingDurationMin = 40;
					grazeWalkingDurationMax = 120;
					restingDurationMin = 60;
					restingDurationMax = 180;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 0.85;
						minSpeed = 0.6;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.5;
					};
					class CatchUpMovement
					{
						maxSpeed = 1.2;
						minSpeed = 0.6;
						acceleration = 0.2;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.5;
					};
				};
			};
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 10;
					travelWeight = 0;
					grazeOnSpotDurationMin = 40;
					grazeOnSpotDurationMax = 120;
					grazeWalkingDurationMin = 40;
					grazeWalkingDurationMax = 120;
					restingDurationMin = 60;
					restingDurationMax = 180;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 3;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 0.85;
						minSpeed = 0.6;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.5;
					};
					class CatchUpMovement
					{
						maxSpeed = 1.2;
						minSpeed = 0.6;
						acceleration = 0.2;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.5;
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 25;
					grazeWalkingWeight = 25;
					restWeight = 0;
					travelWeight = 50;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 50;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 50;
					restingDurationMin = 20;
					restingDurationMax = 25;
					travelingDurationMin = 20;
					travelingDurationMax = 40;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 10.0;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 0.85;
						minSpeed = 0.6;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.5;
					};
					class CatchUpMovement
					{
						maxSpeed = 1.2;
						minSpeed = 0.6;
						acceleration = 0.2;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.5;
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 10;
					travelWeight = 0;
					drinkingWeight = 20;
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
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 3;
					class DrinkingMovement
					{
						maxSpeed = 0.85;
						minSpeed = 0.6;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.5;
					};
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 0.85;
						minSpeed = 0.6;
						acceleration = 0.1;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.5;
					};
					class CatchUpMovement
					{
						maxSpeed = 1.2;
						minSpeed = 0.6;
						acceleration = 0.2;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "CowOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.5;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 0;
					walkToWeight = 20;
					stayLookAtWeight = 10;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 1.0;
					walkAwayDurationMin = 6;
					walkAwayDurationMax = 15;
					walkToDurationMin = 6;
					walkToDurationMax = 15;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 20;
					stayDurationMin = 20;
					stayDurationMax = 30;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.85;
						minSpeed = 0.85;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "CowOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.61;
					};
				};
			};
			class SlotSpecificThreat
			{
				class SlotEvents
				{
					class EventsDuring
					{
						class PeriodicEventRepeatAlert_BosTaurusSlotSpec
						{
							repeatTimeMin = 1.0;
							repeatTimeMax = 6.0;
							class AlertImpulseActionRepeatAlert_BosTaurusSlotSpec
							{
								value = 9.0;
								range = 10.0;
							};
						};
					};
				};
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 10;
					walkToWeight = 0;
					stayLookAtWeight = 0;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 15;
					walkAwayDurationMax = 25;
					walkToDurationMin = 20;
					walkToDurationMax = 30;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 20;
					stayDurationMin = 5;
					stayDurationMax = 10;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.85;
						minSpeed = 0.85;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.61;
					};
				};
			};
			class SlotAlerted
			{
				class SlotEvents
				{
					class EventsEntering
					{
						class OneTimeEventSendAlert_BosTaurusSlotAlert
						{
							class AlertImpulseActionSendAlert_BosTaurusSlotAlert
							{
								value = 50.0;
								range = 15.0;
							};
						};
					};
					class EventsDuring
					{
						class PeriodicEventRepeatAlert_BosTaurusSlotAlert
						{
							repeatTimeMin = 1.0;
							repeatTimeMax = 3.0;
							class AlertImpulseActionRepeatAlert_BosTaurusSlotAlert
							{
								value = 8.0;
								range = 15.0;
							};
						};
					};
				};
				class BehaviourGoToTarget
				{
					class Movement
					{
						maxSpeed = 11.0;
						optimalSpeed = 3.0;
						minSpeed = 0.6;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 20.0;
						acceleration = 5.0;
						maxAngleSpeed = 60.0;
						slowRadius = 4.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.61;
					};
					class RunMovementInjured1
					{
						maxSpeed = 1.0;
						optimalSpeed = 1.0;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 5.0;
						maxAngleSpeed = 30.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.5;
					};
					class RunMovementInjured2
					{
						maxSpeed = 0.1;
						optimalSpeed = 0.0;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 5.0;
						maxAngleSpeed = 30.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "CowOnRun";
						startAnimationMaxSpeed = 0.5;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 30;
				noiseToAlertMultiplier = 0.4;
				noiseShotToAlertMultiplier = 1.2;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 8;
					dropDelay = 1;
					maxAlertValue = 5;
				};
				class NonSpecificThreat
				{
					dropSpeed = 8;
					dropDelay = 2;
					maxAlertValue = 70;
				};
				class SpecificThreat
				{
					dropSpeed = 7;
					dropDelay = 2;
					maxAlertValue = 110;
				};
				class Alerted
				{
					dropSpeed = 6;
					dropDelay = 1.0;
					maxAlertValue = 130;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 10.0;
			rangeMax = 30.0;
			rangeShotMin = 5.0;
			rangeShotMax = 300.0;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 1.0;
				Zombies = 1.0;
				Player = 1.0;
			};
		};
		class TargetSystemDZBase
		{
			class VisionTeamMultipliers
			{
				BigGame = 0.8;
				Zombies = 1.0;
				Player = 1.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.5;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 5.0;
			visionRangeMin = 8;
			visionRangeMax = 20;
			visionFov = 1.6;
			visionPeripheralRangeMin = 5;
			visionPeripheralRangeMax = 8;
			visionPeripheralFov = 6.28;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 1.0;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 1.0;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 1.0;
		};
	};
	class AmbientLife
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "AmbientLife";
		class PathAgent
		{
			radius = 0.3;
			height = 0.5;
		};
		class BehaviourHLAmbientLife
		{
			agentPathLength = 20.0;
			agentPathUpdateDelta = 2.0;
			agentPathMinLength = 2.5;
			class SlotCalm
			{
				class BehaviourAmbientLifeCalm
				{
					walkWeight = 25;
					idle1Weight = 25;
					idle2Weight = 0;
					idle3Weight = 25;
					walkingDurationMin = 5.0;
					walkingDurationMax = 20.0;
					idle1DurationMin = 5.0;
					idle1DurationMax = 20.0;
					idle2DurationMin = 5.0;
					idle2DurationMax = 20.0;
					idle3DurationMin = 5.0;
					idle3DurationMax = 20.0;
					class WalkingMovement
					{
						maxSpeed = 0.14;
						minSpeed = 0.1;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourNonSpecificThreat
				{
					lookWeight = 30;
					sniffWeight = 0;
					sniffDuration = 0.5;
					lookDuration = 6.0;
				};
			};
			class SlotAlerted
			{
				class BehaviourGoToTarget
				{
					class Movement
					{
						maxSpeed = 3.0;
						minSpeed = 1.0;
						acceleration = 5.0;
						maxAngleSpeed = 180.0;
						slowRadius = 1.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "ChickenOnRun";
					};
					class SoundsDuring
					{
						class Sound1
						{
							sounds[] = {"HenCluck_X_SoundSet"};
						};
						probability = 0.9;
						RepeatTimeMin = 1.0;
						RepeatTimeMax = 3.0;
						RepeatEnabled = "true";
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 10;
				noiseToAlertMultiplier = 1.5;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 6;
					dropDelay = 3;
					maxAlertValue = 20;
				};
				class NonSpecificThreat
				{
					dropSpeed = 6;
					dropDelay = 3;
					maxAlertValue = 40;
				};
				class Alerted
				{
					dropSpeed = 10;
					dropDelay = 4;
					maxAlertValue = 100;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 2.0;
			rangeMax = 15.0;
			rangeShotMin = 100.0;
			rangeShotMax = 300.0;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 0.8;
				Zombies = 1.0;
				Player = 1.0;
			};
		};
		class TargetSystemAmbientLife
		{
			visionManSizeStand = 1.5;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.45;
			visionRangeMin = 2.0;
			visionRangeMax = 10.0;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.5;
		};
	};
	class Herbivores_CapreolusCapreolus
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "BigGame";
		defaultGroupTemplateName = "DZDeerGroupBeh";
		class PathAgent
		{
			radius = 0.2;
			height = 1.0;
		};
		class BehaviourHLDeer
		{
			instantAlertRangeMin = 20.0;
			instantAlertRangeMax = 50.0;
			instantAlertStrength = 6.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 50;
					travelWeight = 0;
					grazeOnSpotDurationMin = 40;
					grazeOnSpotDurationMax = 80;
					grazeWalkingDurationMin = 40;
					grazeWalkingDurationMax = 80;
					restingDurationMin = 40;
					restingDurationMax = 60;
					travelingDurationMin = 20;
					travelingDurationMax = 20;
					safetyDurationMin = 14;
					safetyDurationMax = 24;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.135;
						minSpeed = 0.135;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
				};
			};
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					class SoundsDuring
					{
						sounds[] = {"dz\sounds\effects\animals\deer\bark_roe\bark_0","dz\sounds\effects\animals\deer\bark_roe\bark_1","dz\sounds\effects\animals\deer\bark_roe\bark_2","dz\sounds\effects\animals\deer\bark_roe\bark_3","dz\sounds\effects\animals\deer\bark_roe\bark_4","dz\sounds\effects\animals\deer\bark_roe\bark_5","dz\sounds\effects\animals\deer\bark_roe\bark_6","dz\sounds\effects\animals\deer\bark_roe\bark_7"};
						volume = 0.8;
						distance = 100;
						probability = 0.5;
						RepeatTimeMin = 10.0;
						RepeatTimeMax = 50.0;
						RepeatEnabled = "true";
					};
					travelingMode = "false";
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 20;
					travelWeight = 0;
					grazeOnSpotDurationMin = 10;
					grazeOnSpotDurationMax = 50;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 40;
					restingDurationMin = 20;
					restingDurationMax = 20;
					travelingDurationMin = 20;
					travelingDurationMax = 20;
					safetyDurationMin = 14;
					safetyDurationMax = 24;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.135;
						minSpeed = 0.135;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					class SoundsDuring
					{
						sounds[] = {"dz\sounds\effects\animals\deer\bark_roe\bark_0","dz\sounds\effects\animals\deer\bark_roe\bark_1","dz\sounds\effects\animals\deer\bark_roe\bark_2","dz\sounds\effects\animals\deer\bark_roe\bark_3","dz\sounds\effects\animals\deer\bark_roe\bark_4","dz\sounds\effects\animals\deer\bark_roe\bark_5","dz\sounds\effects\animals\deer\bark_roe\bark_6","dz\sounds\effects\animals\deer\bark_roe\bark_7"};
						volume = 0.8;
						distance = 100;
						probability = 0.5;
						RepeatTimeMin = 10.0;
						RepeatTimeMax = 50.0;
						RepeatEnabled = "true";
					};
					travelingMode = "true";
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 50;
					grazeOnSpotDurationMin = 15;
					grazeOnSpotDurationMax = 20;
					grazeWalkingDurationMin = 15;
					grazeWalkingDurationMax = 20;
					restingDurationMin = 5;
					restingDurationMax = 10;
					travelingDurationMin = 40;
					travelingDurationMax = 60;
					safetyDurationMin = 14;
					safetyDurationMax = 24;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.135;
						minSpeed = 0.135;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					class SoundsDuring
					{
						sounds[] = {"dz\sounds\effects\animals\deer\bark_roe\bark_0","dz\sounds\effects\animals\deer\bark_roe\bark_1","dz\sounds\effects\animals\deer\bark_roe\bark_2","dz\sounds\effects\animals\deer\bark_roe\bark_3","dz\sounds\effects\animals\deer\bark_roe\bark_4","dz\sounds\effects\animals\deer\bark_roe\bark_5","dz\sounds\effects\animals\deer\bark_roe\bark_6","dz\sounds\effects\animals\deer\bark_roe\bark_7"};
						volume = 0.8;
						distance = 100;
						probability = 0.5;
						RepeatTimeMin = 10.0;
						RepeatTimeMax = 50.0;
						RepeatEnabled = "true";
					};
					travelingMode = "true";
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 10;
					travelWeight = 0;
					drinkingWeight = 20;
					grazeOnSpotDurationMin = 10;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 10;
					restingDurationMin = 0;
					restingDurationMax = 0;
					travelingDurationMin = 20;
					travelingDurationMax = 20;
					drinkingDurationMin = 15;
					drinkingDurationMax = 20;
					grazeWalkingSpeed = 0.179;
					travelingWalkingSpeed = 1.196;
					safetyDurationMin = 14;
					safetyDurationMax = 24;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class DrinkingMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
					class GrazeMovement
					{
						maxSpeed = 0.135;
						minSpeed = 0.135;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					class SoundsEntering
					{
						sounds[] = {"dz\sounds\effects\animals\deer\bark_roe\bark_0","dz\sounds\effects\animals\deer\bark_roe\bark_1","dz\sounds\effects\animals\deer\bark_roe\bark_2","dz\sounds\effects\animals\deer\bark_roe\bark_3","dz\sounds\effects\animals\deer\bark_roe\bark_4","dz\sounds\effects\animals\deer\bark_roe\bark_5","dz\sounds\effects\animals\deer\bark_roe\bark_6","dz\sounds\effects\animals\deer\bark_roe\bark_7"};
						volume = 0.8;
						distance = 100;
						probability = 0.8;
					};
					class SoundsDuring
					{
						sounds[] = {"dz\sounds\effects\animals\deer\bark_roe\bark_0","dz\sounds\effects\animals\deer\bark_roe\bark_1","dz\sounds\effects\animals\deer\bark_roe\bark_2","dz\sounds\effects\animals\deer\bark_roe\bark_3","dz\sounds\effects\animals\deer\bark_roe\bark_4","dz\sounds\effects\animals\deer\bark_roe\bark_5","dz\sounds\effects\animals\deer\bark_roe\bark_6","dz\sounds\effects\animals\deer\bark_roe\bark_7"};
						volume = 0.8;
						distance = 100;
						probability = 0.3;
						RepeatTimeMin = 10.0;
						RepeatTimeMax = 30.0;
						RepeatEnabled = "true";
					};
					walkAwayWeight = 0;
					walkToWeight = 10;
					stayLookAtWeight = 20;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 10;
					walkToDurationMin = 7;
					walkToDurationMax = 14;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 25;
					stayDurationMin = 5;
					stayDurationMax = 10;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
				};
			};
			class SlotSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					class SoundsEntering
					{
						sounds[] = {"dz\sounds\effects\animals\deer\bark_roe\bark_0","dz\sounds\effects\animals\deer\bark_roe\bark_1","dz\sounds\effects\animals\deer\bark_roe\bark_2","dz\sounds\effects\animals\deer\bark_roe\bark_3","dz\sounds\effects\animals\deer\bark_roe\bark_4","dz\sounds\effects\animals\deer\bark_roe\bark_5","dz\sounds\effects\animals\deer\bark_roe\bark_6","dz\sounds\effects\animals\deer\bark_roe\bark_7"};
						volume = 0.8;
						distance = 100;
						probability = 0.8;
					};
					class SoundsDuring
					{
						sounds[] = {"dz\sounds\effects\animals\deer\bark_roe\bark_0","dz\sounds\effects\animals\deer\bark_roe\bark_1","dz\sounds\effects\animals\deer\bark_roe\bark_2","dz\sounds\effects\animals\deer\bark_roe\bark_3","dz\sounds\effects\animals\deer\bark_roe\bark_4","dz\sounds\effects\animals\deer\bark_roe\bark_5","dz\sounds\effects\animals\deer\bark_roe\bark_6","dz\sounds\effects\animals\deer\bark_roe\bark_7"};
						volume = 0.8;
						distance = 150;
						probability = 0.3;
						RepeatTimeMin = 10.0;
						RepeatTimeMax = 30.0;
						RepeatEnabled = "true";
					};
					walkAwayWeight = 10;
					walkToWeight = 10;
					stayLookAtWeight = 20;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 10;
					walkAwayDurationMax = 20;
					walkToDurationMin = 7;
					walkToDurationMax = 15;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 25;
					stayDurationMin = 5;
					stayDurationMax = 10;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.53;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "RoeDeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.54;
					};
				};
			};
			class SlotAlerted
			{
				class BehaviourFleeFromTargets
				{
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = {"DeerAmbush1_SoundSet","DeerAmbush1_tailForest_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"DeerAmbush2_SoundSet","DeerAmbush2_tailForest_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"DeerAmbush3_SoundSet","DeerAmbush3_tailForest_SoundSet"};
						};
						class Sound4
						{
							sounds[] = {"DeerAmbush4_SoundSet","DeerAmbush4_tailForest_SoundSet"};
						};
						class Sound5
						{
							sounds[] = {"DeerAmbush5_SoundSet","DeerAmbush5_tailForest_SoundSet"};
						};
						class Sound6
						{
							sounds[] = {"DeerAmbush6_SoundSet","DeerAmbush6_tailForest_SoundSet"};
						};
						probability = 1.0;
					};
					minDistanceToTargetRatio = 0.5;
					class SoundsDuring
					{
						sounds[] = {"dz\sounds\effects\animals\deer\bark_roe\bark_0","dz\sounds\effects\animals\deer\bark_roe\bark_1","dz\sounds\effects\animals\deer\bark_roe\bark_2","dz\sounds\effects\animals\deer\bark_roe\bark_3","dz\sounds\effects\animals\deer\bark_roe\bark_4","dz\sounds\effects\animals\deer\bark_roe\bark_5","dz\sounds\effects\animals\deer\bark_roe\bark_6","dz\sounds\effects\animals\deer\bark_roe\bark_7"};
						volume = 0.8;
						distance = 200;
						probability = 0.3;
						RepeatTimeMin = 10.0;
						RepeatTimeMax = 30.0;
						RepeatEnabled = "true";
					};
					class RunMovement
					{
						maxSpeed = 11.76;
						optimalSpeed = 9.6;
						minSpeed = 0.9;
						maxSpeedRange = 50.0;
						optimalSpeedRange = 25.0;
						acceleration = 7.0;
						maxAngleSpeed = 70.0;
						slowRadius = 4.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "RoeDeerOnRun";
						startAnimationMaxSpeed = 0.91;
					};
					class RunMovementInjured1
					{
						maxSpeed = 1.35;
						optimalSpeed = 1.35;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 2.0;
						maxAngleSpeed = 1.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 0.91;
					};
					class RunMovementInjured2
					{
						maxSpeed = 0.1;
						optimalSpeed = 0.0;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 2.0;
						maxAngleSpeed = 1.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 0.91;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 7.0;
				noiseToAlertMultiplier = 1.0;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 5;
					dropDelay = 1;
					maxAlertValue = 25;
				};
				class NonSpecificThreat
				{
					dropSpeed = 5;
					dropDelay = 10;
					maxAlertValue = 50;
				};
				class SpecificThreat
				{
					dropSpeed = 2;
					dropDelay = 10;
					maxAlertValue = 75;
				};
				class Alerted
				{
					dropSpeed = 10;
					dropDelay = 10;
					maxAlertValue = 100;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 20.0;
			rangeMax = 70.0;
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
				Predator = 10.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.5;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.5;
			visionRangeMin = 5;
			visionRangeMax = 50;
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
	class Herbivores_CapraHircus
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "BigGame";
		defaultGroupTemplateName = "DZSheepGroupBeh";
		class PathAgent
		{
			radius = 0.2;
			height = 1.0;
		};
		class BehaviourHLDomestic
		{
			instantAlertRangeMin = 10.0;
			instantAlertRangeMax = 40.0;
			instantAlertStrength = 9.0;
			agentPathLength = 30.0;
			agentPathUpdateDelta = 1.0;
			agentPathMinLength = 2.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 10;
					restWeight = 20;
					travelWeight = 0;
					grazeOnSpotDurationMin = 40;
					grazeOnSpotDurationMax = 120;
					grazeWalkingDurationMin = 40;
					grazeWalkingDurationMax = 120;
					restingDurationMin = 60;
					restingDurationMax = 180;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.11;
						minSpeed = 0.11;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						pathFilter = "NoJumping";
					};
					class TravelingMovement
					{
						maxSpeed = 0.84;
						minSpeed = 0.41;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.42;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.84;
						minSpeed = 0.41;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.42;
					};
				};
			};
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 10;
					travelWeight = 0;
					grazeOnSpotDurationMin = 40;
					grazeOnSpotDurationMax = 120;
					grazeWalkingDurationMin = 40;
					grazeWalkingDurationMax = 120;
					restingDurationMin = 60;
					restingDurationMax = 180;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.11;
						minSpeed = 0.11;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						pathFilter = "NoJumping";
					};
					class TravelingMovement
					{
						maxSpeed = 0.84;
						minSpeed = 0.41;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.42;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.84;
						minSpeed = 0.41;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.42;
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 10;
					travelWeight = 0;
					drinkingWeight = 20;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 30;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 30;
					restingDurationMin = 20;
					restingDurationMax = 30;
					travelingDurationMin = 0;
					travelingDurationMax = 20;
					drinkingDurationMin = 40;
					drinkingDurationMax = 60;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class DrinkingMovement
					{
						maxSpeed = 0.84;
						minSpeed = 0.41;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.42;
					};
					class GrazeMovement
					{
						maxSpeed = 0.11;
						minSpeed = 0.11;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						pathFilter = "NoJumping";
					};
					class TravelingMovement
					{
						maxSpeed = 0.84;
						minSpeed = 0.41;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.42;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.84;
						minSpeed = 0.41;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.42;
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 50;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 50;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 50;
					restingDurationMin = 20;
					restingDurationMax = 25;
					travelingDurationMin = 20;
					travelingDurationMax = 40;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.11;
						minSpeed = 0.11;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						pathFilter = "NoJumping";
					};
					class TravelingMovement
					{
						maxSpeed = 0.84;
						minSpeed = 0.41;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.42;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.84;
						minSpeed = 0.41;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.42;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 0;
					walkToWeight = 10;
					stayLookAtWeight = 10;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 1.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 15;
					walkToDurationMin = 5;
					walkToDurationMax = 15;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 20;
					stayDurationMin = 20;
					stayDurationMax = 30;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.84;
						minSpeed = 0.41;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.42;
					};
				};
			};
			class SlotSpecificThreat
			{
				class SlotEvents
				{
					class EventsEntering{};
					class EventsDuring
					{
						class PeriodicEventRepeatAlert_OvisAriesSlotSpec
						{
							repeatTimeMin = 1.0;
							repeatTimeMax = 4.0;
							class AlertImpulseActionRepeatAlert_OvisAriesSlotSpec
							{
								value = 0.0;
								range = 10.0;
							};
						};
					};
				};
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 10;
					walkToWeight = 0;
					stayLookAtWeight = 0;
					stayWeight = 0;
					walkAwaySpreadAngle = 0.5;
					walkAwayInitialAngle = 1.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 1.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 15;
					walkToDurationMin = 5;
					walkToDurationMax = 15;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 20;
					stayDurationMin = 20;
					stayDurationMax = 30;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 6.0;
						optimalSpeed = 2.8;
						minSpeed = 2.12;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 20.0;
						acceleration = 4.0;
						maxAngleSpeed = 90.0;
						slowRadius = 4.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 2.13;
					};
				};
			};
			class SlotAlerted
			{
				class SlotEvents
				{
					class EventsEntering
					{
						class OneTimeEventSendAlert_OvisAriesSlotAlert
						{
							class AlertImpulseActionSendAlert_OvisAriesSlotAlert
							{
								value = 50.0;
								range = 10.0;
							};
						};
					};
					class EventsDuring
					{
						class PeriodicEventRepeatAlert_OvisAriesSlotAlert
						{
							repeatTimeMin = 1.0;
							repeatTimeMax = 4.0;
							class AlertImpulseActionRepeatAlert_OvisAriesSlotAlert
							{
								value = 0.0;
								range = 10.0;
							};
						};
					};
				};
				class BehaviourGoToTarget
				{
					class Movement
					{
						maxSpeed = 10.44;
						optimalSpeed = 6.0;
						minSpeed = 0.41;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 2.0;
						maxAngleSpeed = 60.0;
						slowRadius = 6.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 0.42;
					};
					class RunMovementInjured1
					{
						maxSpeed = 1.2;
						optimalSpeed = 0.41;
						minSpeed = 0.41;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 1.0;
						maxAngleSpeed = 30.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 0.42;
					};
					class RunMovementInjured2
					{
						maxSpeed = 0.0;
						optimalSpeed = 0.0;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 1.0;
						maxAngleSpeed = 30.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 1.4;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 60;
				noiseToAlertMultiplier = 0.3;
				noiseShotToAlertMultiplier = 1.2;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 8;
					dropDelay = 1;
					maxAlertValue = 5;
				};
				class NonSpecificThreat
				{
					dropSpeed = 8;
					dropDelay = 2;
					maxAlertValue = 70;
				};
				class SpecificThreat
				{
					dropSpeed = 7;
					dropDelay = 2;
					maxAlertValue = 110;
				};
				class Alerted
				{
					dropSpeed = 6;
					dropDelay = 0.1;
					maxAlertValue = 120;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 10.0;
			rangeMax = 30.0;
			rangeShotMin = 5.0;
			rangeShotMax = 300.0;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 1.0;
				Zombies = 1.0;
				Player = 1.0;
			};
		};
		class TargetSystemDZBase
		{
			class VisionTeamMultipliers
			{
				BigGame = 0.8;
				Zombies = 1.0;
				Player = 1.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.5;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 5.0;
			visionRangeMin = 6;
			visionRangeMax = 10;
			visionFov = 1.6;
			visionPeripheralRangeMin = 5;
			visionPeripheralRangeMax = 8;
			visionPeripheralFov = 6.28;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 1.0;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 1.0;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 1.0;
		};
	};
	class Herbivores_SusDomesticus
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "BigGame";
		defaultGroupTemplateName = "DZSheepGroupBeh";
		class PathAgent
		{
			radius = 0.2;
			height = 1.0;
		};
		class BehaviourHLDomestic
		{
			instantAlertRangeMin = 5.0;
			instantAlertRangeMax = 15.0;
			instantAlertStrength = 7.0;
			agentPathLength = 30.0;
			agentPathUpdateDelta = 1.0;
			agentPathMinLength = 2.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					travelingMode = "false";
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 20;
					travelWeight = 0;
					grazeOnSpotDurationMin = 10;
					grazeOnSpotDurationMax = 15;
					grazeWalkingDurationMin = 3;
					grazeWalkingDurationMax = 8;
					restingDurationMin = 15;
					restingDurationMax = 20;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					grazeWalkingSpeed = 0.25;
					travelingWalkingSpeed = 0.96;
					safetyIntervalMin = 13;
					safetyIntervalMax = 27;
					safetyDurationMin = 8;
					safetyDurationMax = 12;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.23;
						minSpeed = 0.23;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 0.7;
						optimalSpeed = 0.7;
						minSpeed = 0.49;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.5;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.0;
						optimalSpeed = 3.0;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
				};
			};
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					travelingMode = "false";
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 20;
					travelWeight = 0;
					grazeOnSpotDurationMin = 5;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 5;
					grazeWalkingDurationMax = 10;
					restingDurationMin = 5;
					restingDurationMax = 10;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					grazeWalkingSpeed = 0.25;
					travelingWalkingSpeed = 0.96;
					safetyIntervalMin = 30;
					safetyIntervalMax = 40;
					safetyDurationMin = 5;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class GrazeMovement
					{
						maxSpeed = 0.23;
						minSpeed = 0.23;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 0.7;
						optimalSpeed = 0.7;
						minSpeed = 0.49;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.5;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.0;
						optimalSpeed = 3.0;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					travelingMode = "true";
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 20;
					travelWeight = 20;
					grazeOnSpotDurationMin = 100;
					grazeOnSpotDurationMax = 100;
					grazeWalkingDurationMin = 100;
					grazeWalkingDurationMax = 100;
					restingDurationMin = 100;
					restingDurationMax = 100;
					travelingDurationMin = 100;
					travelingDurationMax = 100;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 3;
					class GrazeMovement
					{
						maxSpeed = 0.23;
						minSpeed = 0.23;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 0.7;
						optimalSpeed = 0.7;
						minSpeed = 0.49;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.5;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.0;
						optimalSpeed = 3.0;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					travelingMode = "true";
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 10;
					travelWeight = 0;
					drinkingWeight = 20;
					grazeOnSpotDurationMin = 10;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 10;
					restingDurationMin = 0;
					restingDurationMax = 0;
					travelingDurationMin = 20;
					travelingDurationMax = 20;
					drinkingDurationMin = 15;
					drinkingDurationMax = 20;
					grazeWalkingSpeed = 0.179;
					travelingWalkingSpeed = 1.196;
					safetyIntervalMin = 15;
					safetyIntervalMax = 20;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class DrinkingMovement
					{
						maxSpeed = 0.7;
						optimalSpeed = 0.7;
						minSpeed = 0.49;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.5;
					};
					class GrazeMovement
					{
						maxSpeed = 0.23;
						minSpeed = 0.23;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 0.7;
						optimalSpeed = 0.7;
						minSpeed = 0.49;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.5;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.0;
						optimalSpeed = 3.0;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 0;
					walkToWeight = 10;
					stayLookAtWeight = 10;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 10;
					walkToDurationMin = 3;
					walkToDurationMax = 5;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 15;
					stayDurationMin = 10;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.7;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.5;
					};
				};
			};
			class SlotSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 10;
					walkToWeight = 0;
					stayLookAtWeight = 0;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 0.1;
					walkToInitialAngle = 0.1;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 10;
					walkToDurationMin = 2;
					walkToDurationMax = 6;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 15;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.7;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.5;
					};
				};
			};
			class SlotAlerted
			{
				class SlotEvents
				{
					class EventsEntering
					{
						class OneTimeEventSendAlert_BosTaurusSlotAlert
						{
							class AlertImpulseActionSendAlert_BosTaurusSlotAlert
							{
								value = 50.0;
								range = 15.0;
							};
						};
					};
				};
				class BehaviourGoToTarget
				{
					class Movement
					{
						maxSpeed = 7.2;
						optimalSpeed = 5.0;
						minSpeed = 0.7;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 15.0;
						acceleration = 4.0;
						maxAngleSpeed = 70.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 0.8;
					};
					class RunMovementInjured1
					{
						maxSpeed = 7.2;
						optimalSpeed = 5.0;
						minSpeed = 0.7;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 15.0;
						acceleration = 4.0;
						maxAngleSpeed = 70.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 0.8;
					};
					class RunMovementInjured2
					{
						maxSpeed = 7.2;
						optimalSpeed = 5.0;
						minSpeed = 0.7;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 15.0;
						acceleration = 4.0;
						maxAngleSpeed = 70.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 0.8;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 25;
				noiseToAlertMultiplier = 0.7;
				noiseShotToAlertMultiplier = 2.0;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 5;
					dropDelay = 1;
					maxAlertValue = 10;
				};
				class NonSpecificThreat
				{
					dropSpeed = 5;
					dropDelay = 5;
					maxAlertValue = 70;
				};
				class SpecificThreat
				{
					dropSpeed = 5;
					dropDelay = 3;
					maxAlertValue = 100;
				};
				class Alerted
				{
					dropSpeed = 5;
					dropDelay = 1;
					maxAlertValue = 115;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 10.0;
			rangeMax = 25.0;
			rangeShotMin = 5.0;
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
				BigGame = 0.8;
				Zombies = 1.0;
				Player = 1.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.45;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 5.0;
			visionRangeMin = 15;
			visionRangeMax = 20;
			visionFov = 1.2;
			visionPeripheralRangeMin = 5;
			visionPeripheralRangeMax = 10;
			visionPeripheralFov = 6.28;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.75;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 0.9;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 0.7;
		};
	};
	class Herbivores_SusScrofa
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "BigGame";
		defaultGroupTemplateName = "DZDeerGroupBeh";
		class PathAgent
		{
			radius = 0.2;
			height = 1.0;
		};
		class BehaviourHLDeer
		{
			instantAlertRangeMin = 20.0;
			instantAlertRangeMax = 50.0;
			instantAlertStrength = 7.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 20;
					travelWeight = 0;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 30;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 30;
					restingDurationMin = 20;
					restingDurationMax = 30;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 8;
					safetyDurationMax = 12;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.12;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class CatchUpMovement
					{
						maxSpeed = 4.2;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
				};
			};
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 5;
					travelWeight = 0;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 30;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 30;
					restingDurationMin = 20;
					restingDurationMax = 30;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 8;
					safetyDurationMax = 12;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 3;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.12;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class CatchUpMovement
					{
						maxSpeed = 4.2;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 50;
					grazeOnSpotDurationMin = 15;
					grazeOnSpotDurationMax = 25;
					grazeWalkingDurationMin = 15;
					grazeWalkingDurationMax = 25;
					restingDurationMin = 0;
					restingDurationMax = 0;
					travelingDurationMin = 20;
					travelingDurationMax = 40;
					safetyDurationMin = 8;
					safetyDurationMax = 12;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.12;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class CatchUpMovement
					{
						maxSpeed = 4.2;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					travelingMode = "true";
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 10;
					travelWeight = 0;
					drinkingWeight = 20;
					grazeOnSpotDurationMin = 10;
					grazeOnSpotDurationMax = 20;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 20;
					restingDurationMin = 15;
					restingDurationMax = 25;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					drinkingDurationMin = 50;
					drinkingDurationMax = 70;
					safetyDurationMin = 8;
					safetyDurationMax = 12;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class DrinkingMovement
					{
						maxSpeed = 1.12;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.12;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class CatchUpMovement
					{
						maxSpeed = 4.2;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 0;
					walkToWeight = 10;
					stayLookAtWeight = 10;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 10;
					walkToDurationMin = 4;
					walkToDurationMax = 8;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 15;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 1.12;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
				};
			};
			class SlotSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 0;
					walkToWeight = 10;
					stayLookAtWeight = 10;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 10;
					walkToDurationMin = 4;
					walkToDurationMax = 8;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 15;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 1.12;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
				};
			};
			class SlotAlerted
			{
				class BehaviourFleeFromTargets
				{
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = {"DeerAmbush1_SoundSet","DeerAmbush1_tailForest_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"DeerAmbush2_SoundSet","DeerAmbush2_tailForest_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"DeerAmbush3_SoundSet","DeerAmbush3_tailForest_SoundSet"};
						};
						class Sound4
						{
							sounds[] = {"DeerAmbush4_SoundSet","DeerAmbush4_tailForest_SoundSet"};
						};
						class Sound5
						{
							sounds[] = {"DeerAmbush5_SoundSet","DeerAmbush5_tailForest_SoundSet"};
						};
						class Sound6
						{
							sounds[] = {"DeerAmbush6_SoundSet","DeerAmbush6_tailForest_SoundSet"};
						};
						probability = 1.0;
					};
					minDistanceToTargetRatio = 0.5;
					class RunMovement
					{
						maxSpeed = 17.0;
						optimalSpeed = 12.0;
						minSpeed = 1.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 15.0;
						acceleration = 4.0;
						maxAngleSpeed = 70.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 1.4;
					};
					class RunMovementInjured1
					{
						maxSpeed = 1.35;
						optimalSpeed = 1.35;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 2.0;
						maxAngleSpeed = 1.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 1.4;
					};
					class RunMovementInjured2
					{
						maxSpeed = 0.1;
						optimalSpeed = 0.0;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 2.0;
						maxAngleSpeed = 1.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 1.4;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 7;
				noiseToAlertMultiplier = 1.0;
				noiseShotToAlertMultiplier = 2.0;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 5;
					dropDelay = 1;
					maxAlertValue = 15;
				};
				class NonSpecificThreat
				{
					dropSpeed = 5;
					dropDelay = 5;
					maxAlertValue = 70;
				};
				class SpecificThreat
				{
					dropSpeed = 2;
					dropDelay = 8;
					maxAlertValue = 100;
				};
				class Alerted
				{
					dropSpeed = 3;
					dropDelay = 10;
					maxAlertValue = 105;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 10.0;
			rangeMax = 60.0;
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
				BigGame = 0.8;
				Zombies = 1.0;
				Player = 1.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.45;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.5;
			visionRangeMin = 5;
			visionRangeMax = 60;
			visionFov = 1.2;
			visionPeripheralRangeMin = 5;
			visionPeripheralRangeMax = 25;
			visionPeripheralFov = 3.15;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.75;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 0.9;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 0.7;
		};
	};
	class Herbivores_CervusElaphusFem
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "BigGame";
		defaultGroupTemplateName = "DZDeerGroupBeh";
		class PathAgent
		{
			radius = 0.2;
			height = 1.4;
		};
		class BehaviourHLDeer
		{
			instantAlertRangeMin = 20.0;
			instantAlertRangeMax = 50.0;
			instantAlertStrength = 7.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 5;
					grazeWalkingWeight = 5;
					restWeight = 5;
					travelWeight = 0;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 60;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 60;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyIntervalMin = 15;
					safetyIntervalMax = 15;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.179;
						minSpeed = 0.179;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.225;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.4;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
				};
			};
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 10;
					travelWeight = 0;
					grazeOnSpotDurationMin = 50;
					grazeOnSpotDurationMax = 100;
					grazeWalkingDurationMin = 50;
					grazeWalkingDurationMax = 100;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyIntervalMin = 15;
					safetyIntervalMax = 15;
					safetyDurationMin = 20;
					safetyDurationMax = 20;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.179;
						minSpeed = 0.179;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.225;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.4;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					travelingMode = "true";
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 0;
					travelWeight = 50;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 30;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 20;
					restingDurationMin = 0;
					restingDurationMax = 0;
					travelingDurationMin = 20;
					travelingDurationMax = 50;
					safetyIntervalMin = 15;
					safetyIntervalMax = 20;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class GrazeMovement
					{
						maxSpeed = 0.179;
						minSpeed = 0.179;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.225;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.4;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 10;
					travelWeight = 0;
					drinkingWeight = 20;
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
					safetyIntervalMin = 15;
					safetyIntervalMax = 20;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class DrinkingMovement
					{
						maxSpeed = 1.225;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
					class GrazeMovement
					{
						maxSpeed = 0.179;
						minSpeed = 0.179;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.225;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
					class CatchUpMovement
					{
						maxSpeed = 3.4;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 0;
					walkToWeight = 10;
					stayLookAtWeight = 10;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 10;
					walkToDurationMin = 4;
					walkToDurationMax = 8;
					stayLookAtDurationMin = 15;
					stayLookAtDurationMax = 25;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.9;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
				};
			};
			class SlotSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 10;
					walkToWeight = 0;
					stayLookAtWeight = 20;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 10;
					walkToDurationMin = 20;
					walkToDurationMax = 30;
					stayLookAtDurationMin = 15;
					stayLookAtDurationMax = 25;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 1.225;
						minSpeed = 0.7;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.71;
					};
				};
			};
			class SlotAlerted
			{
				class BehaviourFleeFromTargets
				{
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = {"DeerAmbush1_SoundSet","DeerAmbush1_tailForest_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"DeerAmbush2_SoundSet","DeerAmbush2_tailForest_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"DeerAmbush3_SoundSet","DeerAmbush3_tailForest_SoundSet"};
						};
						class Sound4
						{
							sounds[] = {"DeerAmbush4_SoundSet","DeerAmbush4_tailForest_SoundSet"};
						};
						class Sound5
						{
							sounds[] = {"DeerAmbush5_SoundSet","DeerAmbush5_tailForest_SoundSet"};
						};
						class Sound6
						{
							sounds[] = {"DeerAmbush6_SoundSet","DeerAmbush6_tailForest_SoundSet"};
						};
						probability = 1.0;
					};
					minDistanceToTargetRatio = 0.5;
					class RunMovement
					{
						maxSpeed = 15.0;
						optimalSpeed = 8.0;
						minSpeed = 1.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 5.0;
						maxAngleSpeed = 70.0;
						slowRadius = 4.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 1.4;
					};
					class RunMovementInjured1
					{
						maxSpeed = 1.196;
						optimalSpeed = 1.196;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 2.0;
						maxAngleSpeed = 1.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 1.4;
					};
					class RunMovementInjured2
					{
						maxSpeed = 0.1;
						optimalSpeed = 0.0;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 2.0;
						maxAngleSpeed = 1.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 1.4;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 7.0;
				noiseToAlertMultiplier = 1.0;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 5;
					dropDelay = 1;
					maxAlertValue = 25;
				};
				class NonSpecificThreat
				{
					dropSpeed = 5;
					dropDelay = 10;
					maxAlertValue = 50;
				};
				class SpecificThreat
				{
					dropSpeed = 2;
					dropDelay = 8;
					maxAlertValue = 75;
				};
				class Alerted
				{
					dropSpeed = 10;
					dropDelay = 10;
					maxAlertValue = 100;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 20.0;
			rangeMax = 80.0;
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
				Predator = 10.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.5;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.5;
			visionRangeMin = 5;
			visionRangeMax = 80;
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
	class Herbivores_OvisAries
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "BigGame";
		defaultGroupTemplateName = "DZSheepGroupBeh";
		class PathAgent
		{
			radius = 0.2;
			height = 1.0;
		};
		class BehaviourHLDomestic
		{
			instantAlertRangeMin = 20.0;
			instantAlertRangeMax = 40.0;
			instantAlertStrength = 9.0;
			agentPathLength = 30.0;
			agentPathUpdateDelta = 1.0;
			agentPathMinLength = 2.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 10;
					restWeight = 20;
					travelWeight = 0;
					grazeOnSpotDurationMin = 40;
					grazeOnSpotDurationMax = 120;
					grazeWalkingDurationMin = 40;
					grazeWalkingDurationMax = 120;
					restingDurationMin = 60;
					restingDurationMax = 180;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.09;
						minSpeed = 0.09;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						pathFilter = "NoJumping";
					};
					class TravelingMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.3;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.31;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.3;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.31;
					};
				};
			};
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 10;
					travelWeight = 0;
					grazeOnSpotDurationMin = 40;
					grazeOnSpotDurationMax = 120;
					grazeWalkingDurationMin = 40;
					grazeWalkingDurationMax = 120;
					restingDurationMin = 60;
					restingDurationMax = 180;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.09;
						minSpeed = 0.09;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						pathFilter = "NoJumping";
					};
					class TravelingMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.3;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.31;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.3;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.31;
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 10;
					travelWeight = 0;
					drinkingWeight = 20;
					grazeOnSpotDurationMin = 10;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 10;
					restingDurationMin = 0;
					restingDurationMax = 0;
					travelingDurationMin = 20;
					travelingDurationMax = 20;
					drinkingDurationMin = 15;
					drinkingDurationMax = 20;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class DrinkingUpMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.3;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.31;
					};
					class GrazeMovement
					{
						maxSpeed = 0.09;
						minSpeed = 0.09;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						pathFilter = "NoJumping";
					};
					class TravelingMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.3;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.31;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.3;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.31;
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 50;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 50;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 50;
					restingDurationMin = 20;
					restingDurationMax = 25;
					travelingDurationMin = 20;
					travelingDurationMax = 40;
					safetyDurationMin = 15;
					safetyDurationMax = 35;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.091;
						minSpeed = 0.091;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						pathFilter = "NoJumping";
					};
					class TravelingMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.3;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.31;
					};
					class CatchUpMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.3;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.31;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class SlotEvents
				{
					class EventsDuring{};
				};
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 0;
					walkToWeight = 10;
					stayLookAtWeight = 10;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 1.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 15;
					walkToDurationMin = 5;
					walkToDurationMax = 15;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 20;
					stayDurationMin = 20;
					stayDurationMax = 30;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.55;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "NoJumping";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.31;
					};
				};
			};
			class SlotSpecificThreat
			{
				class SlotEvents
				{
					class EventsEntering{};
					class EventsDuring
					{
						class PeriodicEventRepeatAlert_OvisAriesSlotSpec
						{
							repeatTimeMin = 1.0;
							repeatTimeMax = 4.0;
							class AlertImpulseActionRepeatAlert_OvisAriesSlotSpec
							{
								value = 0.0;
								range = 10.0;
							};
						};
					};
				};
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 10;
					walkToWeight = 0;
					stayLookAtWeight = 0;
					stayWeight = 0;
					walkAwaySpreadAngle = 0.5;
					walkAwayInitialAngle = 1.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 1.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 15;
					walkToDurationMin = 5;
					walkToDurationMax = 15;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 20;
					stayDurationMin = 20;
					stayDurationMax = 30;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.55;
						minSpeed = 0.55;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 20.0;
						acceleration = 4.0;
						maxAngleSpeed = 10.0;
						slowRadius = 8.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 0.31;
					};
				};
			};
			class SlotAlerted
			{
				class SlotEvents
				{
					class EventsEntering
					{
						class OneTimeEventSendAlert_OvisAriesSlotAlert
						{
							class AlertImpulseActionSendAlert_OvisAriesSlotAlert
							{
								value = 50.0;
								range = 10.0;
							};
						};
					};
					class EventsDuring
					{
						class PeriodicEventRepeatAlert_OvisAriesSlotAlert
						{
							repeatTimeMin = 1.0;
							repeatTimeMax = 4.0;
							class AlertImpulseActionRepeatAlert_OvisAriesSlotAlert
							{
								value = 0.0;
								range = 10.0;
							};
						};
					};
				};
				class BehaviourGoToTarget
				{
					class Movement
					{
						maxSpeed = 8.63;
						optimalSpeed = 6.0;
						minSpeed = 0.3;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 2.0;
						maxAngleSpeed = 60.0;
						slowRadius = 6.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 0.3;
					};
					class RunMovementInjured1
					{
						maxSpeed = 0.9;
						optimalSpeed = 0.4;
						minSpeed = 0.3;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 1.0;
						maxAngleSpeed = 30.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 0.3;
					};
					class RunMovementInjured2
					{
						maxSpeed = 0.0;
						optimalSpeed = 0.0;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 1.0;
						maxAngleSpeed = 30.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "NoJumping";
						startAnimationMaxSpeed = 1.4;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 60;
				noiseToAlertMultiplier = 0.3;
				noiseShotToAlertMultiplier = 1.2;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 8;
					dropDelay = 1;
					maxAlertValue = 5;
				};
				class NonSpecificThreat
				{
					dropSpeed = 8;
					dropDelay = 2;
					maxAlertValue = 70;
				};
				class SpecificThreat
				{
					dropSpeed = 7;
					dropDelay = 2;
					maxAlertValue = 110;
				};
				class Alerted
				{
					dropSpeed = 6;
					dropDelay = 0.1;
					maxAlertValue = 120;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 10.0;
			rangeMax = 30.0;
			rangeShotMin = 5.0;
			rangeShotMax = 300.0;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 1.0;
				Zombies = 1.0;
				Player = 1.0;
			};
		};
		class TargetSystemDZBase
		{
			class VisionTeamMultipliers
			{
				BigGame = 0.8;
				Zombies = 1.0;
				Player = 1.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.5;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 5.0;
			visionRangeMin = 3;
			visionRangeMax = 9;
			visionFov = 1.6;
			visionPeripheralRangeMin = 4;
			visionPeripheralRangeMax = 6;
			visionPeripheralFov = 6.28;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 1.0;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 1.0;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 1.0;
		};
	};
	class Predators_Wolf
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "Predator";
		defaultGroupTemplateName = "DZWolfGroupBeh";
		class PathAgent
		{
			radius = 0.3;
			height = 1.0;
			lengthRadius = 0.7;
		};
		class BehaviourHLPredator
		{
			instantAlertRangeMin = 0.0;
			instantAlertRangeMax = 0.0;
			instantAlertStrength = 0.0;
			proximityAttackRange = 2.5;
			attackCooldown = 3.0;
			class SlotCalmGrazing
			{
				class BehaviourCalm
				{
					travelingMode = "true";
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 0;
					grazeOnSpotDurationMin = 5;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 500;
					grazeWalkingDurationMax = 500;
					restingDurationMin = 5;
					restingDurationMax = 10;
					travelingDurationMin = 15;
					travelingDurationMax = 30;
					grazeWalkingSpeed = 0.2;
					travelingWalkingSpeed = 1.36;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
					};
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.38;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
				};
			};
			class SlotSiege
			{
				class BehaviourSiege
				{
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = {"WolfPant0_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"WolfPant1_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"WolfPant2_SoundSet"};
						};
						probability = 1.0;
					};
					class SoundsDuring
					{
						class Sound1
						{
							sounds[] = {"WolfPant3_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"WolfPant4_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"WolfPant5_SoundSet"};
						};
						class Sound4
						{
							sounds[] = {"WolfPant6_SoundSet"};
						};
						class Sound5
						{
							sounds[] = {"WolfPant7_SoundSet"};
						};
						class Sound6
						{
							sounds[] = {"WolfGrowl0_SoundSet"};
						};
						class Sound7
						{
							sounds[] = {"WolfGrowl1_SoundSet"};
						};
						class Sound8
						{
							sounds[] = {"WolfGrowl2_SoundSet"};
						};
						probability = 0.4;
						RepeatTimeMin = 5.0;
						RepeatTimeMax = 15.0;
						RepeatEnabled = "true";
					};
					innerRadius = 7;
					innerRadiusMin = 4.5;
					innerRadiusMax = 10;
					outerRadius = 16;
					directionChangeTimeMin = 7;
					directionChangeTimeMax = 25;
					PlayerFOV = 1.4;
					preferPlayerFOVCooldown = 1.0;
					attackDistance = 3.5;
					class InnerCircleMovement
					{
						maxSpeed = 6.3;
						optimalSpeed = 6.3;
						optimalSpeedRange = 1;
						minSpeed = 1.0;
						acceleration = 7.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						maxSpeedRange = 2;
						pathFilter = "WolfOnHunt";
						startAnimationMaxSpeed = 0.54;
					};
					class Movement
					{
						maxSpeed = 9.0;
						optimalSpeed = 6.3;
						optimalSpeedRange = 15;
						minSpeed = 1.0;
						acceleration = 10.0;
						maxAngleSpeed = 180.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						maxSpeedRange = 20;
						pathFilter = "WolfOnOuterCircle";
						startAnimationMaxSpeed = 0.54;
					};
					class AttackMovement
					{
						maxSpeed = 12.175;
						optimalSpeed = 12.0;
						optimalSpeedRange = 6;
						minSpeed = 0.8;
						acceleration = 10.0;
						maxAngleSpeed = 180.0;
						slowRadius = 2.0;
						stopRadius = 3.0;
						maxSpeedRange = 30;
						pathFilter = "WolfOnHunt";
					};
				};
			};
			class SlotEating
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 20;
					eatingWeight = 20;
					grazeOnSpotDurationMin = 5;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 10;
					grazeWalkingDurationMax = 15;
					restingDurationMin = 15;
					restingDurationMax = 25;
					travelingDurationMin = 15;
					travelingDurationMax = 30;
					eatingDurationMin = 15;
					eatingDurationMax = 25;
					safetyDurationMin = 10;
					safetyDurationMax = 20;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
					};
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.38;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
				};
			};
			class SlotHunting
			{
				class BehaviourHunt
				{
					attackRange = 3.5;
					followingRadius = 15.0;
					followingRadiusReqroupCooldownMin = 5.0;
					followingRadiusReqroupCooldownMax = 15.0;
					followingRadiusRegroupMinSpeed = 1.5;
					predictFollowingMinDistance = 10.0;
					minDistanceToTargetRatio = 0.3;
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = {"WolfBark3_0_SoundSet"};
						};
						probability = 0.3;
					};
					class SoundsDuring
					{
						class Sound1
						{
							sounds[] = {"WolfBark2_0_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"WolfBark2_1_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"WolfBark2_2_SoundSet"};
						};
						class Sound4
						{
							sounds[] = {"WolfBark2_3_SoundSet"};
						};
						class Sound5
						{
							sounds[] = {"WolfBark2_4_SoundSet"};
						};
						probability = 1.0;
						RepeatTimeMin = 10.0;
						RepeatTimeMax = 30.0;
						RepeatEnabled = "true";
					};
					class Movement
					{
						maxSpeed = 10.0;
						optimalSpeed = 9.5;
						minSpeed = 1.0;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						maxSpeedRange = 15.0;
						optimalSpeedRange = 5.0;
						pathFilter = "WolfOnHunt";
					};
					class MovementAttack
					{
						maxSpeed = 12.175;
						optimalSpeed = 12.175;
						minSpeed = 6.0;
						acceleration = 20.0;
						maxAngleSpeed = 360.0;
						slowRadius = 0.0;
						stopRadius = 0.0;
						maxSpeedRange = 3;
						optimalSpeedRange = 1;
						pathFilter = "WolfOnHunt";
					};
				};
			};
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					travelingMode = "true";
					grazeOnSpotWeight = 50;
					grazeWalkingWeight = 50;
					restWeight = 50;
					travelWeight = 0;
					grazeOnSpotDurationMin = 5;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 15;
					grazeWalkingDurationMax = 25;
					restingDurationMin = 25;
					restingDurationMax = 35;
					travelingDurationMin = 15;
					travelingDurationMax = 30;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
					};
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.38;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
				};
			};
			class SlotCalmTravelling
			{
				class BehaviourCalm
				{
					travelingMode = "true";
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 50;
					grazeOnSpotDurationMin = 10;
					grazeOnSpotDurationMax = 20;
					grazeWalkingDurationMin = 25;
					grazeWalkingDurationMax = 35;
					restingDurationMin = 5;
					restingDurationMax = 10;
					travelingDurationMin = 10;
					travelingDurationMax = 50;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 4.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.38;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 2.0;
						stopRadius = 1.0;
						pathFilter = "WolfOnHunt";
					};
				};
			};
			class SlotAttracted
			{
				class BehaviourCalm
				{
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = {"WolfHowls1_SoundSet","WolfHowls1_tailDistant_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"WolfHowls2_SoundSet","WolfHowls2_tailDistant_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"WolfHowls3_SoundSet","WolfHowls3_tailDistant_SoundSet"};
						};
						class Sound4
						{
							sounds[] = {"WolfHowls4_SoundSet","WolfHowls4_tailDistant_SoundSet"};
						};
						class Sound5
						{
							sounds[] = {"WolfHowls5_SoundSet","WolfHowls5_tailDistant_SoundSet"};
						};
						class Sound6
						{
							sounds[] = {"WolfHowls6_SoundSet","WolfHowls6_tailDistant_SoundSet"};
						};
						class Sound7
						{
							sounds[] = {"WolfHowls5_SoundSet","WolfHowls7_tailDistant_SoundSet"};
						};
						class Sound8
						{
							sounds[] = {"WolfHowls6_SoundSet","WolfHowls8_tailDistant_SoundSet"};
						};
						probability = 0.9;
					};
					class SoundsDuring
					{
						class Sound1
						{
							sounds[] = {"WolfHowl1_SoundSet","WolfHowl1_tailDistant_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"WolfHowl2_SoundSet","WolfHowl2_tailDistant_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"WolfHowl3_SoundSet","WolfHowl3_tailDistant_SoundSet"};
						};
						class Sound4
						{
							sounds[] = {"WolfHowl4_SoundSet","WolfHowl4_tailDistant_SoundSet"};
						};
						class Sound5
						{
							sounds[] = {"WolfHowl5_SoundSet","WolfHowl5_tailDistant_SoundSet"};
						};
						class Sound6
						{
							sounds[] = {"WolfHowl6_SoundSet","WolfHowl6_tailDistant_SoundSet"};
						};
						class Sound7
						{
							sounds[] = {"WolfHowl5_SoundSet","WolfHowl7_tailDistant_SoundSet"};
						};
						class Sound8
						{
							sounds[] = {"WolfHowl6_SoundSet","WolfHowl8_tailDistant_SoundSet"};
						};
						probability = 0.5;
						RepeatTimeMin = 5.0;
						RepeatTimeMax = 25.0;
						RepeatEnabled = "true";
					};
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 0;
					travelWeight = 50;
					grazeOnSpotDurationMin = 5;
					grazeOnSpotDurationMax = 10;
					grazeWalkingDurationMin = 5;
					grazeWalkingDurationMax = 10;
					restingDurationMin = 5;
					restingDurationMax = 10;
					travelingDurationMin = 50;
					travelingDurationMax = 100;
					grazeWalkingSpeed = 0.544;
					travelingWalkingSpeed = 0.782;
					safetyDurationMin = 10;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "WolfOnHunt";
					};
					class CatchUpMovement
					{
						maxSpeed = 6.38;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "WolfOnHunt";
					};
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
				};
			};
			class SlotFireplace
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 20;
					grazeWalkingWeight = 20;
					restWeight = 20;
					travelWeight = 0;
					grazeOnSpotDurationMin = 50;
					grazeOnSpotDurationMax = 100;
					grazeWalkingDurationMin = 50;
					grazeWalkingDurationMax = 100;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					grazeWalkingSpeed = 0.2;
					travelingWalkingSpeed = 1.36;
					safetyIntervalMin = 30;
					safetyIntervalMax = 40;
					safetyDurationMin = 5;
					safetyDurationMax = 10;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
					};
					class TravelingMovement
					{
						maxSpeed = 2.85;
						minSpeed = 0.78;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 0.0;
						stopRadius = 0.5;
						slowToTurn = "true";
						smoothAcceleration = "true";
					};
				};
			};
			class SlotScared
			{
				class BehaviourFleeFromTargets
				{
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = {"WolfGroans1_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"WolfGroans2_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"WolfGroans3_SoundSet"};
						};
						probability = 1.0;
					};
					class SoundsDuring
					{
						class Sound1
						{
							sounds[] = {"WolfGroan1_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"WolfGroan2_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"WolfGroan3_SoundSet"};
						};
						probability = 0.3;
						RepeatTimeMin = 5.0;
						RepeatTimeMax = 25.0;
						RepeatEnabled = "true";
					};
					class RunMovement
					{
						maxSpeed = 12.175;
						optimalSpeed = 6.39;
						minSpeed = 1.0;
						acceleration = 2.0;
						maxAngleSpeed = 360.0;
						slowRadius = 4.0;
						stopRadius = 0.0;
						maxSpeedRange = 15;
						optimalSpeedRange = 10;
						pathFilter = "DeerOnRun";
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 10;
				noiseToAlertMultiplier = 1.0;
				damageToAlertMultiplier = 200.0;
				class Calm
				{
					dropSpeed = 3;
					dropDelay = 2;
					maxAlertValue = 30;
				};
				class Alerted
				{
					dropSpeed = 11;
					dropDelay = 0;
					maxAlertValue = 100;
				};
				class AlertedExtra
				{
					dropSpeed = 25;
					dropDelay = 10;
					maxAlertValue = 500;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 25.0;
			rangeMax = 100.0;
			rangeShotMin = 0.0;
			rangeShotMax = 50.0;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 0.4;
				Zombies = 0.6;
				Player = 1.0;
			};
		};
		class TargetSystemDZBase
		{
			class VisionTeamMultipliers
			{
				BigGame = 0.6;
				Zombies = 1.0;
				Player = 1.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.6;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.5;
			visionRangeMin = 100;
			visionRangeMax = 200;
			visionFov = 1.8;
			visionPeripheralRangeMin = 1;
			visionPeripheralRangeMax = 16;
			visionPeripheralFov = 6.2;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.75;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 0.9;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 0.7;
		};
	};
	class Herbivores_CervusElaphus
	{
		HeadLookBoneName = "pin_lookat";
		teamName = "BigGame";
		defaultGroupTemplateName = "DZDeerGroupBeh";
		class PathAgent
		{
			radius = 0.25;
			height = 1.8;
		};
		class BehaviourHLDeer
		{
			instantAlertRangeMin = 20.0;
			instantAlertRangeMax = 50.0;
			instantAlertStrength = 7.0;
			class SlotCalmResting
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 5;
					grazeWalkingWeight = 5;
					restWeight = 5;
					travelWeight = 0;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 60;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 60;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 25;
					safetyDurationMax = 40;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.36;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class CatchUpMovement
					{
						maxSpeed = 5.0;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
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
					grazeOnSpotDurationMin = 50;
					grazeOnSpotDurationMax = 100;
					grazeWalkingDurationMin = 50;
					grazeWalkingDurationMax = 100;
					restingDurationMin = 50;
					restingDurationMax = 150;
					travelingDurationMin = 0;
					travelingDurationMax = 0;
					safetyDurationMin = 25;
					safetyDurationMax = 40;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 1.5;
					safetyLookAngleChangeInterval = 7;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.36;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class CatchUpMovement
					{
						maxSpeed = 5.0;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
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
					travelWeight = 50;
					grazeOnSpotDurationMin = 20;
					grazeOnSpotDurationMax = 30;
					grazeWalkingDurationMin = 20;
					grazeWalkingDurationMax = 30;
					restingDurationMin = 0;
					restingDurationMax = 0;
					travelingDurationMin = 20;
					travelingDurationMax = 30;
					safetyDurationMin = 25;
					safetyDurationMax = 40;
					safetyLookAngleMin = 0.1;
					safetyLookAngleMax = 0.4;
					safetyLookAngleChangeInterval = 5;
					class GrazeMovement
					{
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.36;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class CatchUpMovement
					{
						maxSpeed = 5.0;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
				};
			};
			class SlotDrinking
			{
				class BehaviourCalm
				{
					grazeOnSpotWeight = 10;
					grazeWalkingWeight = 10;
					restWeight = 10;
					travelWeight = 0;
					drinkingWeight = 20;
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
					safetyDurationMin = 25;
					safetyDurationMax = 40;
					safetyLookAngleMin = 0.3;
					safetyLookAngleMax = 0.7;
					safetyLookAngleChangeInterval = 3;
					class DrinkingMovement
					{
						maxSpeed = 1.36;
						minSpeed = 0.8;
						acceleration = 5.0;
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
						maxSpeed = 0.25;
						minSpeed = 0.25;
						acceleration = 5.0;
						maxAngleSpeed = 5.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
					};
					class TravelingMovement
					{
						maxSpeed = 1.36;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 0.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
					class CatchUpMovement
					{
						maxSpeed = 5.0;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 90.0;
						slowRadius = 5.0;
						stopRadius = 3.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
				};
			};
			class SlotNonSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 0;
					walkToWeight = 10;
					stayLookAtWeight = 10;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 10;
					walkToDurationMin = 4;
					walkToDurationMax = 8;
					stayLookAtDurationMin = 10;
					stayLookAtDurationMax = 25;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 0.85;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
				};
			};
			class SlotSpecificThreat
			{
				class BehaviourSpecificThreat
				{
					walkAwayWeight = 10;
					walkToWeight = 0;
					stayLookAtWeight = 20;
					stayWeight = 0;
					walkAwaySpreadAngle = 1.5;
					walkAwayInitialAngle = 2.0;
					walkToSpreadAngle = 1.5;
					walkToInitialAngle = 2.0;
					walkAwayDurationMin = 5;
					walkAwayDurationMax = 10;
					walkToDurationMin = 20;
					walkToDurationMax = 30;
					stayLookAtDurationMin = 15;
					stayLookAtDurationMax = 25;
					stayDurationMin = 5;
					stayDurationMax = 15;
					pathLength = 10.0;
					class WalkingMovement
					{
						maxSpeed = 1.359;
						minSpeed = 0.8;
						acceleration = 5.0;
						maxAngleSpeed = 10.0;
						slowRadius = 1.9;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						pathFilter = "DeerOnRun";
						useStartAnimation = "true";
						startAnimationMaxSpeed = 0.81;
					};
				};
			};
			class SlotAlerted
			{
				class BehaviourFleeFromTargets
				{
					class SoundsEntering
					{
						class Sound1
						{
							sounds[] = {"DeerAmbush1_SoundSet","DeerAmbush1_tailForest_SoundSet"};
						};
						class Sound2
						{
							sounds[] = {"DeerAmbush2_SoundSet","DeerAmbush2_tailForest_SoundSet"};
						};
						class Sound3
						{
							sounds[] = {"DeerAmbush3_SoundSet","DeerAmbush3_tailForest_SoundSet"};
						};
						class Sound4
						{
							sounds[] = {"DeerAmbush4_SoundSet","DeerAmbush4_tailForest_SoundSet"};
						};
						class Sound5
						{
							sounds[] = {"DeerAmbush5_SoundSet","DeerAmbush5_tailForest_SoundSet"};
						};
						class Sound6
						{
							sounds[] = {"DeerAmbush6_SoundSet","DeerAmbush6_tailForest_SoundSet"};
						};
						probability = 1.0;
					};
					minDistanceToTargetRatio = 0.5;
					class RunMovement
					{
						maxSpeed = 15.0;
						optimalSpeed = 8.0;
						minSpeed = 1.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 5.0;
						maxAngleSpeed = 70.0;
						slowRadius = 4.0;
						stopRadius = 2.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 1.4;
					};
					class RunMovementInjured1
					{
						maxSpeed = 1.35;
						optimalSpeed = 1.35;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 2.0;
						maxAngleSpeed = 1.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 1.4;
					};
					class RunMovementInjured2
					{
						maxSpeed = 0.1;
						optimalSpeed = 0.0;
						minSpeed = 0.0;
						maxSpeedRange = 30.0;
						optimalSpeedRange = 25.0;
						acceleration = 2.0;
						maxAngleSpeed = 1.0;
						slowRadius = 10.0;
						stopRadius = 4.0;
						slowToTurn = "true";
						smoothAcceleration = "true";
						useStartAnimation = "true";
						pathFilter = "DeerOnRun";
						startAnimationMaxSpeed = 1.4;
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 7.0;
				noiseToAlertMultiplier = 1.0;
				noiseShotToAlertMultiplier = 2.0;
				damageToAlertMultiplier = 1e+06;
				class Calm
				{
					dropSpeed = 5;
					dropDelay = 1;
					maxAlertValue = 25;
				};
				class NonSpecificThreat
				{
					dropSpeed = 5;
					dropDelay = 10;
					maxAlertValue = 50;
				};
				class SpecificThreat
				{
					dropSpeed = 2;
					dropDelay = 10;
					maxAlertValue = 75;
				};
				class Alerted
				{
					dropSpeed = 10;
					dropDelay = 10;
					maxAlertValue = 100;
				};
			};
		};
		class NoiseSystemParams
		{
			rangeMin = 20.0;
			rangeMax = 80.0;
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
				Predator = 10.0;
			};
			visionManSizeStand = 1.0;
			visionManSizeCrouch = 0.8;
			visionManSizeProne = 0.5;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.5;
			visionRangeMin = 5;
			visionRangeMax = 80;
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
	class Infected
	{
		name = "zombie";
		HeadLookBoneName = "lookat";
		teamName = "Zombies";
		class BehaviourHLZombie
		{
			class MovementWalk
			{
				maxSpeed = 1.5;
				minSpeed = 0.0;
				acceleration = 5.0;
				maxAngleSpeed = 180.0;
				slowRadius = 0.0;
				stopRadius = 0.5;
				pathFilter = "ZombieCalm";
			};
			class MovementRun
			{
				maxSpeed = 3.0;
				minSpeed = 0.0;
				acceleration = 15.0;
				maxAngleSpeed = 120.0;
				slowRadius = 0.0;
				goalRadius = 1.5;
				stopRadius = 1.7;
				useStartAnimation = "false";
				pathFilter = "ZombieAlerted";
			};
			class MovementSprint
			{
				maxSpeed = 9.0;
				minSpeed = 0.0;
				acceleration = 27.0;
				maxAngleSpeed = 180.0;
				maxSpeedRange = 9.0;
				slowRadius = 3.2;
				goalRadius = 1.5;
				goalSpeed = 7.2;
				stopRadius = 1.7;
				waypointRadius = 1.5;
				useStartAnimation = "false";
				startAnimationMaxSpeed = 0.0;
				slowToTurn = "false";
				smoothAcceleration = "true";
				pathFilter = "ZombieAlerted";
			};
			class SlotCalm
			{
				class BehaviourZombieCalm
				{
					StandingDurationMin = 4;
					StandingDurationMax = 8;
					WalkingDurationMin = 4;
					WalkingDurationMax = 12;
					MinLookTime = 1;
					MaxLookTime = 2;
					IsAttractMode = "false";
					class SoundsDuring
					{
						class Sound1
						{
							moveWithEntity = "true";
						};
						probability = 0.8;
						RepeatTimeMin = 9.0;
						RepeatTimeMax = 15.0;
						RepeatEnabled = "true";
					};
				};
			};
			class SlotAlerted
			{
				class BehaviourZombieAlerted
				{
					maxTimeInDisturbedState = 5.0;
					alertToAttract = 0.75;
					fightStateEnterDistance = 2.0;
					fightStateExitDistance = 3.0;
					fightStateEnterOrientAngleDiff = 160.0;
					fightStateExitOrientAngleDiff = 160.0;
					disturbedTargetHistoryLength = 20.0;
					disturbedVisionUtilityWeight = 1.0;
					disturbedNoiseUtilityWeight = 1.0;
					disturbedDamageUtilityWeight = 0.0;
					attractedTargetHistoryLength = 20.0;
					attractedVisionUtilityWeight = 1.0;
					attractedNoiseUtilityWeight = 1.0;
					attractedDamageUtilityWeight = 1.0;
					chaseTargetHistoryLength = 20.0;
					chaseVisionUtilityWeight = 1.0;
					chaseNoiseUtilityWeight = 1.0;
					chaseDamageUtilityWeight = 1.0;
					class SoundsEntering
					{
						class Sound1{};
						probability = 1.0;
					};
					class SoundsDuring
					{
						class Sound1{};
						probability = 1.0;
						RepeatTimeMin = 3.9;
						RepeatTimeMax = 4.1;
						RepeatEnabled = "true";
					};
					noiseMakeAlertPeriod = 3.0;
					class NoiseMakeAlert
					{
						strength = 60.0;
						type = "sound";
					};
				};
			};
			class AlertSystem
			{
				visionToAlertMultiplier = 20.0;
				noiseToAlertMultiplier = 0.8;
				damageToAlertMultiplier = 10000.0;
				noiseShotToAlertMultiplier = 1.7;
				class Calm
				{
					DropSpeed = 3;
					DropDelay = 2;
					MaxAlertValue = 20;
				};
				class Alerted
				{
					DropSpeed = 1;
					DropDelay = 10;
					MaxAlertValue = 100;
				};
			};
			staminaDepletionSpeed = 5;
			staminaRechargeSpeed = 10;
		};
		class TargetSystemDZBase
		{
			visionProximityRange = 2.5;
			visionProximityStrengthMult = 3;
			visionCloseRange = 8.0;
			visionCloseHeight = 1.8;
			visionCloseStrengthMult = 3.0;
			visionRangeMin = 20;
			visionRangeMax = 40;
			visionFov = 1.0;
			visionPeripheralRangeMin = 5;
			visionPeripheralRangeMax = 20;
			visionPeripheralFov = 2.3;
			visionAngularSpeedMin = 0.1;
			visionAngularSpeedMax = 0.5;
			visionAngularSpeedMaxMult = 1.0;
			visionNightMinMult = 1.0;
			visionNightMaxMult = 0.4;
			visionRainMinMult = 1.0;
			visionRainMaxMult = 0.5;
			visionFogMinMult = 1.0;
			visionFogMaxMult = 0.5;
		};
		class NoiseSystemParams
		{
			rangeMin = 3.0;
			rangeMax = 35.0;
			rangeShotMin = 25.0;
			rangeShotMax = 200.0;
			radiusMin = 5.0;
			radiusMax = 20.0;
			radiusShotMin = 10.0;
			radiusShotMax = 50.0;
			class NoiseStrengthTeamMultipliers
			{
				BigGame = 1.0;
				Zombies = 1.0;
				Player = 1.0;
			};
		};
	};
	class InfectedFemale: Infected
	{
		class BehaviourHLZombie: BehaviourHLZombie
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourZombieCalm: BehaviourZombieCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = "true";
						};
					};
				};
			};
			class SlotAlerted: SlotAlerted
			{
				class BehaviourZombieAlerted: BehaviourZombieAlerted
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1{};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1{};
					};
				};
			};
		};
	};
	class InfectedMale: Infected
	{
		class BehaviourHLZombie: BehaviourHLZombie
		{
			class SlotCalm: SlotCalm
			{
				class BehaviourZombieCalm: BehaviourZombieCalm
				{
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1
						{
							moveWithEntity = "true";
						};
					};
				};
			};
			class SlotAlerted: SlotAlerted
			{
				class BehaviourZombieAlerted: BehaviourZombieAlerted
				{
					class SoundsEntering: SoundsEntering
					{
						class Sound1: Sound1{};
					};
					class SoundsDuring: SoundsDuring
					{
						class Sound1: Sound1{};
					};
				};
			};
		};
	};
};
class CfgNoises
{
	class DeerStepNoise
	{
		type = "sound";
		continuousRange = 100;
		strength = 10;
	};
	class DeerRoarNoise
	{
		type = "sound";
		continuousRange = 100;
		strength = 10;
	};
	class WolfStepNoise
	{
		type = "sound";
		continuousRange = 100;
		strength = 10;
	};
	class WolfRoarNoise
	{
		type = "sound";
		continuousRange = 100;
		strength = 10;
	};
	class ZombieStepNoise
	{
		type = "sound";
		continuousRange = 100;
		strength = 10;
	};
	class ZombieRoarNoise
	{
		type = "sound";
		continuousRange = 100;
		strength = 10;
	};
};
class CfgDamages
{
	class DeerBiteDamage{};
	class WolfBiteDamage
	{
		bone = "tongue3";
		ammo = "MeleeWolf";
		radius = 0.4;
		duration = 0.2;
	};
	class WolfLowBiteDamage
	{
		bone = "chest";
		ammo = "MeleeWolf";
		radius = 0.7;
		duration = 0.5;
	};
};
