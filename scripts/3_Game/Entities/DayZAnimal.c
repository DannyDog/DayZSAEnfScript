class DayZCreatureAnimInterface
{	
	//-----------------------------------------------------
	// Binds, returns -1 when error, otherwise if ok

	//! returns command index - 	
	proto native TAnimGraphCommand		BindCommand(string pCommandName);

	//!
	proto native TAnimGraphVariable 	BindVariableFloat(string pVariable);
	proto native TAnimGraphVariable 	BindVariableInt(string pVariable);
	proto native TAnimGraphVariable 	BindVariableBool(string pVariable);

	//!
	proto native TAnimGraphTag 			BindTag(string pTagName);

	//!
	proto native TAnimGraphEvent		BindEvent(string pEventName);
}

class DayZCreature extends EntityAI 
{
	#ifdef _DAYZ_CREATURE_DEBUG_SHADOW
	proto native void DebugSetShadow(DayZCreature creature);
	#endif
	
	proto native bool RegisterAnimationEvent(string event_name, string function_name);
	
	proto native void SetAnimationInstanceByName(string animation_instance_name, int instance_uuid, float duration);
	proto native int GetCurrentAnimationInstanceUUID();
	
	proto native DayZCreatureAnimInterface GetAnimInterface();

	
	proto native void UpdateSimulationPrecision(int simLOD);
	
	override bool IsDayZCreature()
	{
		return true;
	}
	
	override bool CanBeSkinned()
	{
		return true;
	}
	
	override bool IsIgnoredByConstruction()
	{
		return true;
	}
}

class DayZCreatureAI extends DayZCreature 
{
	proto native AIAgent GetAIAgent();

	proto native bool IsSoundInsideBuilding();
#ifdef DEVELOPER
	proto native void DebugDisableAIControl();
	proto native void DebugRestoreAIControl();
#endif
	proto native void AddDamageSphere(string bone_name, string ammo_name, float radius, float duration, bool invertTeams);
	
	proto native DayZCreatureAIType GetCreatureAIType();
	/*!
	AIAgent initialization.
	Manual ai initialization for creatures created with CreateObject(... init_ai = false...).
	*/
	proto native void InitAIAgent(AIGroup group);
	proto native void DestroyAIAgent();
	
	void DayZCreatureAI()
	{
		RegisterAnimEvents();
		SetFlags(EntityFlags.TOUCHTRIGGERS, false);
	}
	
	void AddDamageSphere(AnimDamageParams damage_params)
	{ 
		AddDamageSphere(damage_params.m_sBoneName, damage_params.m_sAmmoName, damage_params.m_fRadius, damage_params.m_fDuration, damage_params.m_bInvertTeams); 
	}
	
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		CreateComponent(COMP_TYPE_BODY_STAGING); // TO DO: This is never called on clients in multiplayer! That's why skinning doesn't work properly in MP. DAYZ-28269
	}
	
	AnimBootsType GetBootsType()
	{
		return AnimBootsType.None;
	}
	
	AbstractWave PlaySound(SoundObject so, SoundObjectBuilder sob)
	{
		if(so == NULL)
		{
			return NULL;
		}
		
		so.SetPosition(GetPosition());
		AbstractWave wave = GetGame().GetSoundScene().Play3D(so, sob);
		return wave;
	}
	
	void OnSoundEvent(int event_id, string event_user_string) 
	{
		AnimSoundEvent sound_event = GetCreatureAIType().GetSoundEvent(event_id);
		if(sound_event != NULL)
		{
			ProcessSoundEvent(sound_event);
		}
	}

	void OnSoundVoiceEvent(int event_id, string event_user_string)
	{
		AnimSoundVoiceEvent voice_event = GetCreatureAIType().GetSoundVoiceEvent(event_id);
		if(voice_event != NULL)
		{
			ProcessSoundVoiceEvent(voice_event);
		}
	}
	
	void OnStepEvent(int event_id, string event_user_string) 
	{
		AnimStepEvent step_event = GetCreatureAIType().GetStepEvent(event_id);
		if(step_event != NULL)
		{
			ProcessStepEvent(step_event);
		}
	}
	
	void OnDamageEvent(int event_id, string event_user_string)
	{
		AnimDamageEvent damage_event = GetCreatureAIType().GetDamageEvent(event_id);
		if(damage_event != NULL)
		{
			ProcessDamageEvent(damage_event);
		}
	}
	
	protected void RegisterAnimEvents()
	{
		if(!RegisterAnimationEvent("Sound", "OnSoundEvent"))
		{
			Print("Error registering anim. event (Sound)");
		}

		if(!RegisterAnimationEvent("SoundVoice", "OnSoundVoiceEvent"))
		{
			Print("Error registering anim. event (SoundVoice)");
		}

		if(GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if(!RegisterAnimationEvent("Step", "OnStepEvent"))
			{
				Print("Error registering anim. event (Step)");
			}
		}
		
		if(!RegisterAnimationEvent("Damage", "OnDamageEvent"))
		{
			Print("Error registering anim. event (Damage)");
		}
	}
	
	private void ProcessSoundEvent(AnimSoundEvent sound_event)
	{
		if(GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			SoundObjectBuilder objectBuilder = sound_event.GetSoundBuilder();
			if(NULL != objectBuilder)
			{
				objectBuilder.UpdateEnvSoundControllers(GetPosition());
				SoundObject soundObject = objectBuilder.BuildSoundObject();
				PlaySound(soundObject, objectBuilder);
			}
		}
		
		if(GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			if(sound_event.m_NoiseParams != NULL)
				GetGame().GetNoiseSystem().AddNoise(this, sound_event.m_NoiseParams);
		}
	}

	private void ProcessSoundVoiceEvent(AnimSoundVoiceEvent sound_event)
	{
		if(GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			SoundObjectBuilder objectBuilder = sound_event.GetSoundBuilder();
			if(NULL != objectBuilder)
			{
				objectBuilder.UpdateEnvSoundControllers(GetPosition());
				SoundObject soundObject = objectBuilder.BuildSoundObject();
				AttenuateSoundIfNecessary(soundObject);
				PlaySound(soundObject, objectBuilder);
			}
		}
		
		if(GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			if(sound_event.m_NoiseParams != NULL)
				GetGame().GetNoiseSystem().AddNoise(this, sound_event.m_NoiseParams);
		}
	}

	private void ProcessStepEvent(AnimStepEvent step_event)
	{
		SoundObjectBuilder soundBuilder = step_event.GetSoundBuilder(GetSurfaceType().Hash());
		if(soundBuilder == NULL)
			return;
		
		soundBuilder.UpdateEnvSoundControllers(GetPosition());
		SoundObject soundObject = soundBuilder.BuildSoundObject();
		AttenuateSoundIfNecessary(soundObject);
		PlaySound(soundObject, soundBuilder);
		
		//TODO effects
	}
	
	private void ProcessDamageEvent(AnimDamageEvent damage_event)
	{
		AddDamageSphere(damage_event.m_DamageParams);
	}
	
	protected void AttenuateSoundIfNecessary(SoundObject soundObject)
	{
		if (GetGame().GetPlayer() != NULL && (IsSoundInsideBuilding() != GetGame().GetPlayer().IsSoundInsideBuilding() || GetGame().GetPlayer().IsCameraInsideVehicle()))
		{
			soundObject.SetKind(WaveKind.WAVEATTALWAYS);
		}
		else
		{
			soundObject.SetKind(WaveKind.WAVEEFFECTEX);
		}
	}
}

enum DayZAnimalConstants
{
	COMMANDID_MOVE,
	COMMANDID_JUMP,
	COMMANDID_DEATH,
	COMMANDID_HIT,
	COMMANDID_ATTACK,
	COMMANDID_SCRIPT,
};

class DayZAnimalInputController
{
	proto native bool IsDead();
	proto native bool IsJump();
	proto native bool IsAttack();
	
	//--------------------------------------------------------------

	//! never created by script
	private void DayZAnimalInputController()
	{
	}

	//! never destroyed by script
	private void ~DayZAnimalInputController()
	{
	}	
};

class DayZAnimalCommandScript
{
	//! constructor must have 1st parameter to be DayZAnimal
	// DayZAnimalCommandScript(DayZAnimal pInfected);

	//! virtual to be overridden
	//! called when command starts
	void 	OnActivate()	{ };

	//! called when command ends
	void 	OnDeactivate()	{ };


	//---------------------------------------------------------------
	// usable everywhere

	//! this terminates command script and shows CommandHandler(  ... pCurrentCommandFinished == true );
	proto native void 	SetFlagFinished(bool pFinished);


	//---------------------------------------------------------------
	// PreAnim Update 

	//! override this !
	//! called before any animation is processed
	//! here change animation values, add animation commands	
	void 	PreAnimUpdate(float pDt);

	//! function usable in PreAnimUpdate or in !!! OnActivate !!!
	proto native 	void	PreAnim_CallCommand(int pCommand, int pParamInt, float pParamFloat);
	proto native 	void	PreAnim_SetFloat(int pVar, float pFlt);
	proto native 	void	PreAnim_SetInt(int pVar, int pInt);
	proto native 	void	PreAnim_SetBool(int pVar, bool pBool);

	//---------------------------------------------------------------
	// PrePhys Update 

	//! override this !
	//! after animation is processed, before physics is processed
	void 	PrePhysUpdate(float pDt);

	//! script function usable in PrePhysUpdate
	proto native 	bool	PrePhys_IsEvent(int pEvent);
	proto native 	bool	PrePhys_IsTag(int pTag);
	proto native 	bool	PrePhys_GetTranslation(out vector pOutTransl);		// vec3 in local space !
	proto native 	bool	PrePhys_GetRotation(out float pOutRot[4]);         	// quaternion in local space !
	proto native 	void	PrePhys_SetTranslation(vector pInTransl); 			// vec3 in local space !
	proto native 	void	PrePhys_SetRotation(float pInRot[4]);				// quaternion in local space !

	//---------------------------------------------------------------
	// PostPhys Update 

	//! override this !
	//! final adjustment of physics state (after physics was applied)
	//! returns true if command continues running / false if command should end (or you can use SetFlagFinished(true))
	bool	PostPhysUpdate(float pDt);

	//! script function usable in PostPhysUpdate
	proto native 	void	PostPhys_GetPosition(out vector pOutTransl);		//! vec3 in world space
	proto native 	void	PostPhys_GetRotation(out float pOutRot[4]);        	//! quaternion in world space
	proto native 	void	PostPhys_SetPosition(vector pInTransl);				//! vec3 in world space
	proto native 	void	PostPhys_SetRotation(float pInRot[4]);				//! quaternion in world space
	proto native 	void	PostPhys_LockRotation();							//! do not process rotations !
}

class DayZAnimal extends DayZCreatureAI
{

	//! Melee hit components (AI targeting)	
	protected ref array<ref DayZAIHitComponent> m_HitComponentsForAI;
	protected string m_DefaultHitComponent;
	protected string m_DefaultHitPositionComponent;
	protected vector m_DefaultHitPosition;

	proto native DayZAnimalInputController GetInputController();

	proto native void StartCommand_Death(int pType, int pDirection);
	proto native void StartCommand_Move();
	proto native void StartCommand_Jump();
	proto native void StartCommand_Attack();
	proto native void StartCommand_Hit(int pType, int pDirection);
	
	//! scripted commands
	proto native DayZAnimalCommandScript StartCommand_Script(DayZAnimalCommandScript pInfectedCommand);
	proto native DayZAnimalCommandScript StartCommand_ScriptInst(typename pCallbackClass);
	proto native DayZAnimalCommandScript GetCommand_Script();
	
	proto native void SignalAIAttackStarted();
	proto native void SignalAIAttackEnded();
	
	void DayZAnimal()
	{
		// testing: animals have no inventory by default
		//GetInventory().LockInventory(LOCK_FROM_SCRIPT); // Hides animals from vicinity in inventory. Remove this if wanted otherwise.
		
		m_HitComponentsForAI = new array<ref DayZAIHitComponent>;

		RegisterHitComponentsForAI();
		
		//! sets default hit position and cache it here (mainly for impact particles)
		m_DefaultHitPosition = SetDefaultHitPosition(GetDefaultHitPositionComponent());
	}
	
	override bool IsHealthVisible()
	{
		return false;
	}	
	
	override bool IsAnimal()
	{
		return true;
	}
	
	override bool IsInventoryVisible()
	{
		return false;
	}
	
	void CommandHandler(float dt, int currentCommandID, bool currentCommandFinished)
	{
		DayZAnimalInputController inputController = GetInputController();
		
		//! for mods
		if( ModCommandHandlerBefore(dt, currentCommandID, currentCommandFinished) )
		{
			return;
		}

		if (HandleDeath(currentCommandID, inputController))
		{
			return;
		}
		
		if (currentCommandFinished)
		{
			if (currentCommandID == DayZAnimalConstants.COMMANDID_ATTACK)
			{
				SignalAIAttackEnded();
			}
	
			StartCommand_Move();
	
			return;
		}
		
		//! for mods
		if( ModCommandHandlerInside(dt, currentCommandID, currentCommandFinished) )
		{
			return;
		}
	
		if (HandleDamageHit(currentCommandID))
		{
			if (currentCommandID  == DayZAnimalConstants.COMMANDID_ATTACK)
			{
				SignalAIAttackEnded();
			}
			return;
		}
	
		if (currentCommandID == DayZAnimalConstants.COMMANDID_MOVE)
		{
			if (inputController.IsJump())
			{
				StartCommand_Jump();
				return;
			}
	
			if (inputController.IsAttack())
			{
				StartCommand_Attack();
				SignalAIAttackStarted();
				return;
			}
		}
		
		//!
		if( ModCommandHandlerAfter(dt, currentCommandID, currentCommandFinished) )
		{
			return;
		}
	}
	
	//-------------------------------------------------------------
	//!
	//! ModOverrides
	//! 
	// these functions are for modded overide in script command mods 

	bool ModCommandHandlerBefore(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		return false;
	}

	bool ModCommandHandlerInside(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		return false;
	}
	
	bool ModCommandHandlerAfter(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		return false;
	}
	
	bool m_DamageHitToProcess = false;
	int m_DamageHitType = 0;
	int m_DamageHitDirection = 0;
	
	bool HandleDeath(int currentCommandID, DayZAnimalInputController inputController)
	{
		if (inputController.IsDead())
		{
			if (currentCommandID == DayZAnimalConstants.COMMANDID_DEATH)
			{
				return true;
			}
	
			if (m_DamageHitToProcess)
			{
				m_DamageHitToProcess = false;
				
				StartCommand_Death(m_DamageHitType, m_DamageHitDirection);
			}
			else
			{
				StartCommand_Death(0, 0);
			}
			
			dBodySetInteractionLayer(this, PhxInteractionLayers.RAGDOLL);
	
			return true;
		}
		
		return false;
	}
	
	bool HandleDamageHit(int currentCommandID)
	{
		if (m_DamageHitToProcess)
		{
			m_DamageHitToProcess = false;
			
			if (currentCommandID != DayZAnimalConstants.COMMANDID_HIT)
			{
				StartCommand_Hit(m_DamageHitType, m_DamageHitDirection);
			}
			return true;
		}
		return false;
	}
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		m_TransportHitRegistered = false;
		
		if( ammo.ToType().IsInherited(Nonlethal_Base) )
		{
			//Print("DayZAnimal | EEHitBy | nonlethal hit");
			AddHealth("","Health",-ConvertNonlethalDamage(damageResult.GetDamage(dmgZone,"Shock")));
		}
		else
		{
			ComponentAnimalBleeding animal_bleeding = ComponentAnimalBleeding.Cast( GetComponent( COMP_TYPE_ANIMAL_BLEEDING ) );
			animal_bleeding.CreateWound( damageResult, dmgZone, ammo );
		}
		
		int type = 0;
		int direction = 0;
		if (ComputeDamageHitParams(source, dmgZone, ammo, type, direction) == true)
		{
			QueueDamageHit(type, direction);
		}
		
	}
	
	void QueueDamageHit(int type, int direction)
	{
		m_DamageHitToProcess = true;
		m_DamageHitType = type;
		m_DamageHitDirection = direction;
	}
	
	bool ComputeDamageHitParams(EntityAI source, string dmgZone, string ammo, out int type, out int direction)
	{
		type = 0; // not used right now
		
		float angleDeg = ComputeHitDirectionAngleDeg(source);
		direction = TranslateHitAngleDegToDirectionIndex(angleDeg);
		
		direction += FindComponentDirectionOffset(dmgZone);
		
		return true;	
	}
	
	float ComputeHitDirectionAngleDeg(EntityAI source)
	{
		vector targetDirection = GetDirection();
		vector toSourceDirection = (source.GetPosition() - GetPosition());

		targetDirection[1] = 0;
		toSourceDirection[1] = 0;

		targetDirection.Normalize();
		toSourceDirection.Normalize();

		float cosFi = vector.Dot(targetDirection, toSourceDirection);
		vector cross = targetDirection * toSourceDirection;

		float dirAngleDeg = Math.Acos(cosFi) * Math.RAD2DEG;
		if( cross[1] < 0 )
			dirAngleDeg = -dirAngleDeg;
		
		return dirAngleDeg;
	}
	
	int TranslateHitAngleDegToDirectionIndex(float angleDeg)
	{
		if (angleDeg >= -20 && angleDeg <= 20) // front
		{
			return 1; 
		}
		else if (angleDeg < 0) // left
		{
			return 2;
		}
		
		return 3; // right
	}
	
	int FindComponentDirectionOffset(string component)
	{
		const int directionCount = 4;
		
		int offset = 0;
		if (component.Length() == 0)
		{
			offset = 0;
		}
		else if (component == "Zone_Head")
		{
			offset = directionCount;
		}
		else if (component == "Zone_Chest" || component == "Zone_Legs_Front" || component == "Zone_Spine_Front" || component == "Zone_Neck")
		{
			offset = 2 * directionCount;
		}
		else
		{
			offset = 3 * directionCount;
		}
		
		return offset;
	}
	
	//-------------------------------------------------------------
	//!
	//! Phx contact event
	//! 
	
	override private void EOnContact(IEntity other, Contact extra)
	{
		if( !IsAlive() )
			return;
		
		Transport transport = Transport.Cast(other);
		if( transport )
		{
			if ( GetGame().IsServer() || !GetGame().IsMultiplayer() )
			{
				RegisterTransportHit(transport);
			}			
		}
	}

	//! register hit components for AI melee (used by attacking AI)
	void RegisterHitComponentsForAI()
	{
		//! registers default hit compoent for the entity
		m_DefaultHitComponent = "Zone_Chest";
		//! registers default hit position component for entity
		m_DefaultHitPositionComponent = "Pelvis";

		//! register hit components that are selected by probability
		DayZAIHitComponentHelpers.RegisterHitComponent(m_HitComponentsForAI, "Zone_Chest", 50);
	}
	
	override string GetHitComponentForAI()
	{
		string hitComp;
		
		if (DayZAIHitComponentHelpers.SelectMostProbableHitComponent(m_HitComponentsForAI, hitComp))
		{
			return hitComp;
		}	
		
		return GetDefaultHitComponent();
	}
	
	override string GetDefaultHitComponent()
	{
		return m_DefaultHitComponent;
	}
	
	override string GetDefaultHitPositionComponent()
	{
		return m_DefaultHitPositionComponent;
	}

	override vector GetDefaultHitPosition()
	{
		return m_DefaultHitPosition;
	}

	protected vector SetDefaultHitPosition(string pSelection)
	{
		return GetSelectionPositionMS(pSelection);
	}
	
	float ConvertNonlethalDamage(float damage)
	{
		float converted_dmg = damage * GameConstants.PROJECTILE_CONVERSION_ANIMALS;
		return converted_dmg;
	} 
}