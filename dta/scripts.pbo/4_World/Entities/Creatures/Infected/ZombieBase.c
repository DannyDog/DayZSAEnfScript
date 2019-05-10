class ZombieBase extends DayZInfected
{
	//! server / singleplayer properties
	protected int m_StanceVariation = 0;
	protected int m_LastMindState = -1;
	protected float m_LastMovementSpeed = -1;
	
	protected bool m_KnuckleLand = false;
	protected float m_KnuckleOutTimer = 0;

	protected int m_MindState = -1;
	protected float m_MovementSpeed = -1;
	
	protected vector m_DefaultHitPosition;
	
	protected ref AbstractWave				m_LastSoundVoiceAW;
	protected ref InfectedSoundEventHandler	m_InfectedSoundEventHandler;

	//-------------------------------------------------------------
	void ZombieBase()
	{
		Init();
	}
	
	void Init()
	{
		SetEventMask(EntityEvent.INIT);
		
		RegisterNetSyncVariableInt("m_MindState", -1, 4);
		RegisterNetSyncVariableFloat("m_MovementSpeed", -1, 3);
		
		//! sets default hit position and cache it here (mainly for impact particles)
		m_DefaultHitPosition = SetDefaultHitPosition(GetDayZInfectedType().GetDefaultHitPositionComponent());

		//! client only
		if( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			m_LastSoundVoiceAW 			= null;
			m_InfectedSoundEventHandler = new InfectedSoundEventHandler(this);
		}
	}
	
	//! synced variable(s) handler
	override void OnVariablesSynchronized()
	{
		DebugSound("[Infected @ " + this + "][OnVariablesSynchronized]");
		HandleSoundEvents();
	}

	//-------------------------------------------------------------
	override void EOnInit(IEntity other, int extra)
	{
		if( !GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			m_StanceVariation = Math.RandomInt(0, 4);
	
			DayZInfectedCommandMove moveCommand = GetCommand_Move();
			moveCommand.SetStanceVariation(m_StanceVariation);
		}
	}
	
	override bool IsZombie()
	{
		return true;
	}
	
	override bool IsZombieMilitary()
	{
		if ( IsKindOf( "ZmbM_SoldierNormal_Base" ) )
		{
			return true;
		}		
		
		return false;
	}
	
	bool IsMale()
	{
		return true;
	}
	
	//-------------------------------------------------------------
	override AnimBootsType GetBootsType()
	{
		return AnimBootsType.Boots;
	}
	
	override bool CanBeSkinned()
	{
		return false;
	}
	//-------------------------------------------------------------
	override bool IsHealthVisible()
	{
		return false;
	}
	//-------------------------------------------------------------

	//! returns hit component for attacking AI
	override string GetHitComponentForAI()
	{
		return GetDayZInfectedType().GetHitComponentForAI();
	}

	//! returns default hit component (fallback)
	override string GetDefaultHitComponent()
	{
		return GetDayZInfectedType().GetDefaultHitComponent();
	}

	override vector GetDefaultHitPosition()
	{
		return m_DefaultHitPosition;
	}
	
	protected vector SetDefaultHitPosition(string pSelection)
	{
		return GetSelectionPositionMS(pSelection);
	}

	//! returns suitable hit components for finisher attacks
	override array<string> GetSuitableFinisherHitComponents()
	{
		return GetDayZInfectedType().GetSuitableFinisherHitComponents();
	}

	//-------------------------------------------------------------
	//!
	//! CommandHandler
	//! 

	void CommandHandler(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		//! handle death
		if( HandleDeath(pCurrentCommandID) )
		{
			return;
		}

		//! movement handler (just for sync now)
		HandleMove(pCurrentCommandID);
		
		//! handle finished commands
		if (pCurrentCommandFinished)
		{			
			//! default behaviour after finish is to start move
			DayZInfectedCommandMove moveCommand = StartCommand_Move();
			moveCommand.SetStanceVariation(m_StanceVariation);
			
			return;
		}
		
		//! crawl transition
		if( HandleCrawlTransition(pCurrentCommandID) )
		{
			return;
		}
		
		//! damage hits
		if( HandleDamageHit(pCurrentCommandID) )
		{
			return;
		}
		
		DayZInfectedInputController inputController = GetInputController();
		if( inputController )
		{
			if( HandleVault(pCurrentCommandID, inputController, pDt) )
			{
				return;
			}
			
			if( HandleMindStateChange(pCurrentCommandID, inputController, pDt) )
			{
				return;
			}
			
			if( FightLogic(pCurrentCommandID, inputController, pDt) )
			{
				return;
			}
		}		
	}

	//-------------------------------------------------------------
	//!
	//! CommandHandlerDebug
	//! 

	void  CommandHandlerDebug(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		if( GetPluginManager() )
		{
			PluginDayZInfectedDebug infectedDebug = PluginDayZInfectedDebug.Cast(GetPluginManager().GetPluginByType(PluginDayZInfectedDebug));
			if( infectedDebug )
				infectedDebug.CommandHandler(this);
		}	
	}
	//-------------------------------------------------------------
	//!
	//! HandleMove
	//!
	
	void HandleMove(int pCurrentCommandID)
	{
		DayZInfectedInputController ic = GetInputController();
		m_MovementSpeed = ic.GetMovementSpeed();
		if (Math.AbsFloat(m_LastMovementSpeed - m_MovementSpeed) >= 0.9 && m_LastMovementSpeed != m_MovementSpeed)
		{
			SetSynchDirty();
		}
		m_LastMovementSpeed = m_MovementSpeed;
	}
	
	//-------------------------------------------------------------
	//!
	//! HandleDeath
	//! 

	float m_DamageHitDirection = 0;
	int   m_DeathType = 0;

	bool HandleDeath(int pCurrentCommandID)
	{
		if( pCurrentCommandID == DayZInfectedConstants.COMMANDID_DEATH )
		{
			return true;
		}

		if( !IsAlive() )
		{
			StartCommand_Death(m_DeathType, m_DamageHitDirection);
			m_MovementSpeed = -1;
			m_MindState = -1;
			SetSynchDirty();
			return true;
		}

		return false;
	}	
	
	bool EvaluateDeathAnimation(EntityAI pSource, string pComponent, string pAmmoType, out int pAnimType, out float pAnimHitDir)
	{
		//! 
		bool doPhxImpulse = GetGame().ConfigGetInt("cfgAmmo " + pAmmoType + " doPhxImpulse") > 0;
		
		//! anim type
		pAnimType = doPhxImpulse;
				
		//! direction
		pAnimHitDir = ComputeHitDirectionAngle(pSource);
		
		//! add some impulse if needed
		if( doPhxImpulse )
		{
			vector impulse = 80 * m_TransportHitVelocity;
			impulse[1] = 80 * 1.5;
			//Print("Impulse: " + impulse.ToString());
			
			dBodyApplyImpulse(this, impulse);
		}
				
		return true;
	}

	//-------------------------------------------------------------
	//!
	//! HandleVault
	//! 
	
	int m_ActiveVaultType = -1;
	
	int GetVaultType(float height)
	{
		if( height <= 0.6 )
			return 0;
		else if( height <= 1.1 )
			return 1;
		else if( height <= 1.6 )
			return 2;
		else 
			return 3;
	}
	
	bool HandleVault(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		if( pCurrentCommandID == DayZInfectedConstants.COMMANDID_VAULT )
		{
			DayZInfectedCommandVault vaultCmd = GetCommand_Vault();
			if( vaultCmd && vaultCmd.WasLand() )
			{
				m_KnuckleOutTimer = 0;
				m_KnuckleLand = true;
			}
			if( m_KnuckleLand )
			{
				m_KnuckleOutTimer += pDt;
				if( m_KnuckleOutTimer > 2.0 )
					StartCommand_Vault(-1);
			}
			
			return true;
		}
		
		if( pInputController.IsVault() )
		{
			float vaultHeight = pInputController.GetVaultHeight();
			int vaultType = GetVaultType(vaultHeight);
			m_KnuckleLand = false;
			StartCommand_Vault(vaultType);
			return true; 
		}
		
		return false;
	}
	
	//-------------------------------------------------------------
	//!
	//! Mind state change
	//! 

	bool HandleMindStateChange(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		DayZInfectedCommandMove moveCommand = GetCommand_Move();
		if( moveCommand && moveCommand.IsTurning() )
			return false;
		
		m_MindState = pInputController.GetMindState();
		if( m_LastMindState != m_MindState )
		{
			switch( m_MindState )
			{
			case DayZInfectedConstants.MINDSTATE_CALM:
				if( moveCommand )
					moveCommand.SetIdleState(0);
				break;

			case DayZInfectedConstants.MINDSTATE_DISTURBED:
				if( moveCommand )
					moveCommand.SetIdleState(1);
				break;
			
			case DayZInfectedConstants.MINDSTATE_CHASE:
				if( moveCommand && (m_LastMindState < DayZInfectedConstants.MINDSTATE_CHASE) )
					moveCommand.SetIdleState(2);
				break;
			}
			
			m_LastMindState = m_MindState;
			m_AttackCooldownTime = 0.0;
			SetSynchDirty();
		}
		return false;
	}

	//-------------------------------------------------------------
	//!
	//! Sound (client only)
	//!
	
	protected void HandleSoundEvents()
	{
		//! no sound handler - bail out
		if( !m_InfectedSoundEventHandler )
		{
			return;
		}

		//! infected is dead
		if( !IsAlive() )
		{
			//! stop all sounds
			m_InfectedSoundEventHandler.Stop();
			return;
		}

		switch( m_MindState )
		{
		case DayZInfectedConstants.MINDSTATE_CALM:
			m_InfectedSoundEventHandler.PlayRequest(EInfectedSoundEventID.MINDSTATE_CALM_MOVE);
			break;
		case DayZInfectedConstants.MINDSTATE_ALERTED:
			m_InfectedSoundEventHandler.PlayRequest(EInfectedSoundEventID.MINDSTATE_ALERTED_MOVE);
			break;
		case DayZInfectedConstants.MINDSTATE_DISTURBED:
			m_InfectedSoundEventHandler.PlayRequest(EInfectedSoundEventID.MINDSTATE_DISTURBED_IDLE);
			break
		case DayZInfectedConstants.MINDSTATE_CHASE:
			m_InfectedSoundEventHandler.PlayRequest(EInfectedSoundEventID.MINDSTATE_CHASE_MOVE);
			break;
		default:
			m_InfectedSoundEventHandler.Stop();
			break;
		}
		
		DebugSound("[Infected @ " + this + "][MindState]" + typename.EnumToString(DayZInfectedConstants, m_MindState));
		DebugSound("[Infected @ " + this + "][SoundEventID]" + typename.EnumToString(EInfectedSoundEventID, m_InfectedSoundEventHandler.GetCurrentStateEventID()));
	}

	AbstractWave ProcessVoiceFX(string pSoundSetName)
	{
		ref SoundParams			soundParams;
		ref SoundObjectBuilder	soundObjectBuilder;
		ref SoundObject			soundObject;
		if(GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			soundParams = new SoundParams( pSoundSetName );
			if ( !soundParams.IsValid() )
			{
				//SoundError("Invalid sound set.");
				return null;
			}
			
			soundObjectBuilder = new SoundObjectBuilder( soundParams );
			soundObject = soundObjectBuilder.BuildSoundObject();
			AttenuateSoundIfNecessary(soundObject);

			return PlaySound(soundObject, soundObjectBuilder);
		}

		return null;
	}

	override void OnSoundVoiceEvent(int event_id, string event_user_string)
	{
		//super.OnSoundVoiceEvent(event_id, event_user_string);
		AnimSoundVoiceEvent voice_event = GetCreatureAIType().GetSoundVoiceEvent(event_id);
		if(voice_event != null)
		{
			//! stop state sound when playing anim SoundVoice
			if (m_InfectedSoundEventHandler) // && m_InfectedSoundEventHandler.IsPlaying())
			{
				m_InfectedSoundEventHandler.Stop();
				DebugSound("[Infected @ " + this + "][SoundEvent] InfectedSoundEventHandler - stop all");
			}

			//! stop playing of old SoundVoice from anim (if any)
			if (m_LastSoundVoiceAW != null)
			{
				DebugSound("[Infected @ " + this + "][AnimVoiceEvent] Stopping LastAW");
				m_LastSoundVoiceAW.Stop();
			}
			
			//! play new SoundVoice from anim
			ProcessSoundVoiceEvent(voice_event, m_LastSoundVoiceAW);
			
			HandleSoundEvents();
		}
	}
	
	protected void ProcessSoundVoiceEvent(AnimSoundVoiceEvent sound_event, out AbstractWave aw)
	{
		if(GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			SoundObjectBuilder objectBuilder = sound_event.GetSoundBuilder();
			if(NULL != objectBuilder)
			{
				objectBuilder.UpdateEnvSoundControllers(GetPosition());
				SoundObject soundObject = objectBuilder.BuildSoundObject();
				AttenuateSoundIfNecessary(soundObject);
				aw = PlaySound(soundObject, objectBuilder);
			}
		}
		
		if(GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			if(sound_event.m_NoiseParams != NULL)
				GetGame().GetNoiseSystem().AddNoise(this, sound_event.m_NoiseParams);
		}
	}
	
	//-------------------------------------------------------------
	//!
	//! Combat
	//! 
	
	EntityAI m_ActualTarget = NULL;
	float m_AttackCooldownTime = 0;	
	DayZInfectedAttackType m_ActualAttackType = NULL;
	
	bool FightLogic(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		if( pCurrentCommandID == DayZInfectedConstants.COMMANDID_MOVE )
		{
			// we attack only in chase & fight state
			int mindState = pInputController.GetMindState();
			if( mindState == DayZInfectedConstants.MINDSTATE_CHASE )
			{
				return ChaseAttackLogic(pCurrentCommandID, pInputController, pDt);
			}
			else if( mindState == DayZInfectedConstants.MINDSTATE_FIGHT )
			{
				return FightAttackLogic(pCurrentCommandID, pInputController, pDt);
			}
		}
		else if( pCurrentCommandID == DayZInfectedConstants.COMMANDID_ATTACK )
		{
			DayZInfectedCommandAttack attackCommand = GetCommand_Attack();
			if( attackCommand && attackCommand.WasHit() )
			{
				if( m_ActualTarget != NULL )
				{
					bool playerInBlockStance = false;
					vector targetPos = m_ActualTarget.GetPosition();
					vector hitPosWS = targetPos;

					PlayerBase playerTarget = PlayerBase.Cast(m_ActualTarget);
					if( playerTarget )
					{
						playerInBlockStance = playerTarget.GetMeleeFightLogic() && playerTarget.GetMeleeFightLogic().IsInBlock();
					}

					if( vector.DistanceSq(targetPos, this.GetPosition()) <= m_ActualAttackType.m_Distance * m_ActualAttackType.m_Distance )
					{
						//! player is in block stance
						if( playerInBlockStance )
						{
							//! infected is playing heavy attack - decrease the dmg to light
							if( m_ActualAttackType.m_IsHeavy != 0 )
							{
								hitPosWS = m_ActualTarget.ModelToWorld(m_ActualTarget.GetDefaultHitPosition()); //! override hit pos by pos defined in type
								DamageSystem.CloseCombatDamageName(this, m_ActualTarget, m_ActualTarget.GetHitComponentForAI(), "MeleeZombie", hitPosWS);
							}
							else
							{
								//! infected is playing light attack - do not send damage, play animation instead
								if( GetGame().IsServer() )
								{
									hitPosWS = m_ActualTarget.GetDefaultHitPosition(); //! override hit pos by pos defined in type
									m_ActualTarget.EEHitBy(null, 0, EntityAI.Cast(this), -1, m_ActualTarget.GetDefaultHitComponent(), "Dummy_Light", hitPosWS);
								}
							}
						}
						else
						{
							hitPosWS = m_ActualTarget.ModelToWorld(m_ActualTarget.GetDefaultHitPosition()); //! override hit pos by pos defined in type
							DamageSystem.CloseCombatDamageName(this, m_ActualTarget, m_ActualTarget.GetHitComponentForAI(), m_ActualAttackType.m_AmmoType, hitPosWS);
						}
					}
				}
			}
			
			return true;
		}
				
		return false;
	}
	
	bool ChaseAttackLogic(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		// always update target - it can be destroyed		
		m_ActualTarget = pInputController.GetTargetEntity();
		if( m_ActualTarget == NULL )
			return false;
	
		vector targetPos = m_ActualTarget.GetPosition();
		if( !CanAttackToPosition(targetPos) )
			return false;
		
		float targetDist = vector.Distance(targetPos, this.GetPosition());
		int pitch = GetAttackPitch(m_ActualTarget);
		
		m_ActualAttackType = GetDayZInfectedType().ChooseAttack(DayZInfectedAttackGroupType.CHASE, targetDist, pitch);
		if( m_ActualAttackType )
		{
			StartCommand_Attack(m_ActualTarget, m_ActualAttackType.m_Type, m_ActualAttackType.m_Subtype);
			m_AttackCooldownTime = m_ActualAttackType.m_Cooldown;
			return true;
		}
		
		return false;
	}
	
	bool FightAttackLogic(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		// always update target - it can be destroyed		
		m_ActualTarget = pInputController.GetTargetEntity();

		if( m_AttackCooldownTime > 0 )
		{
			m_AttackCooldownTime -= pDt;
			return false;
		}
					
		if( m_ActualTarget == NULL )
			return false;

		vector targetPos = m_ActualTarget.GetPosition();
		float targetDist = vector.Distance(targetPos, this.GetPosition());
		float diffY = Math.AbsFloat(GetPosition()[1] - targetPos[1]);
		int pitch = GetAttackPitch(m_ActualTarget);

		if( !CanAttackToPosition(targetPos) )
			return false;

		m_ActualAttackType = GetDayZInfectedType().ChooseAttack(DayZInfectedAttackGroupType.FIGHT, targetDist, pitch);
		if( m_ActualAttackType )
		{
			StartCommand_Attack(m_ActualTarget, m_ActualAttackType.m_Type, m_ActualAttackType.m_Subtype);
			m_AttackCooldownTime = m_ActualAttackType.m_Cooldown;
			return true;
		}

		return false;
	}

	int GetAttackPitch(EntityAI target)
	{
		float attackRefPosY;
		
		// TODO: move it to some virtual method
		if( target.IsMan() )
		{
			DayZPlayer targetPlayer = NULL;
			Class.CastTo(targetPlayer, target);
			
			// bone index should be cached in Type
			int boneIndex = targetPlayer.GetBoneIndexByName("Head");
			attackRefPosY = targetPlayer.GetBonePositionWS(boneIndex)[1];
		}
		else
		{
			attackRefPosY = target.GetPosition()[1];
		}

		// Now we have only erect stance, we need to get head position later too
		float headPosY = GetPosition()[1];
		headPosY += 1.8;
				
		float diff = Math.AbsFloat(attackRefPosY - headPosY);
		
		if( diff < 0.3 )
			return 0;
		
		if( headPosY > attackRefPosY )
			return -1;
		else
			return 1;
	}
		
	//-------------------------------------------------------------
	//!
	//! Crawl transition
	//! 
	
	int m_CrawlTransition = -1;
	
	bool HandleCrawlTransition(int pCurrentCommandID)
	{
		if( m_CrawlTransition != -1 )
		{
			StartCommand_Crawl(m_CrawlTransition);
			
			m_CrawlTransition = -1;
			return true;
		}

		return pCurrentCommandID == DayZInfectedConstants.COMMANDID_CRAWL;
	}
	
	bool EvaluateCrawlTransitionAnimation(EntityAI pSource, string pComponent, string pAmmoType, out int pAnimType)
	{
		pAnimType = -1;
		if( pComponent == "LeftLeg" && GetHealth(pComponent, "Health") == 0 )
			pAnimType = 0;
		else if( pComponent == "RightLeg" && GetHealth(pComponent, "Health") == 0 )
			pAnimType = 2;
		
		if( pAnimType != -1 )
		{
			vector targetDirection = GetDirection();
			vector toSourceDirection = (pSource.GetPosition() - GetPosition());

			targetDirection[1] = 0;
			toSourceDirection[1] = 0;

			targetDirection.Normalize();
			toSourceDirection.Normalize();

			float cosFi = vector.Dot(targetDirection, toSourceDirection);
			if( cosFi >= 0 ) // front
				pAnimType++;
		}
		
		return pAnimType != -1;
	}
	
	//-------------------------------------------------------------
	//!
	//! Damage hits
	//! 
	
	bool m_DamageHitToProcess = false;
	
	bool m_DamageHitHeavy = false;
	int m_DamageHitType = 0;
		
	bool HandleDamageHit(int pCurrentCommandID)
	{
		if( pCurrentCommandID == DayZInfectedConstants.COMMANDID_HIT )
		{
			m_DamageHitToProcess = false;
			return true;
		}
		
		if( m_DamageHitToProcess )
		{
			StartCommand_Hit(m_DamageHitHeavy, m_DamageHitType, m_DamageHitDirection);
			
			m_DamageHitToProcess = false;
			return true;
		}

		return false;
	}

	//! selects animation type and direction based on damage system data
	bool EvaluateDamageHitAnimation(EntityAI pSource, string pComponent, string pAmmoType, out bool pHeavyHit, out int pAnimType, out float pAnimHitDir)
	{
		//! heavy hit
		pHeavyHit = GetGame().ConfigGetInt("cfgAmmo " + pAmmoType + " hitAnimation") > 0;
				
		//! anim type
		pAnimType = 0; // belly
		
		if( !pHeavyHit )
		{
			if( pComponent == "Torso" ) // body
				pAnimType = 1;
			else if( pComponent == "Head" ) // head		
				pAnimType = 2;
		}
				
		//! direction
		pAnimHitDir = ComputeHitDirectionAngle(pSource);

		return true;
	}
	
	float ComputeHitDirectionAngle(EntityAI pSource)
	{
		vector targetDirection = GetDirection();
		vector toSourceDirection = (pSource.GetPosition() - GetPosition());

		targetDirection[1] = 0;
		toSourceDirection[1] = 0;

		targetDirection.Normalize();
		toSourceDirection.Normalize();

		float cosFi = vector.Dot(targetDirection, toSourceDirection);
		vector cross = targetDirection * toSourceDirection;

		float dirAngle = Math.Acos(cosFi) * Math.RAD2DEG;
		if( cross[1] < 0 )
			dirAngle = -dirAngle;
		
		return dirAngle;
	}
	
	//-------------------------------------------------------------
	//!
	//! Events from damage system
	//! 

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos);
		
		m_TransportHitRegistered = false;
		
		if( !IsAlive() )
		{
			dBodySetInteractionLayer(this, PhxInteractionLayers.AI_NO_COLLISION);
			EvaluateDeathAnimation(source, dmgZone, ammo, m_DeathType, m_DamageHitDirection);
		}
		else
		{
			int crawlTransitionType = -1;
			if( EvaluateCrawlTransitionAnimation(source, dmgZone, ammo, crawlTransitionType) )
			{
				m_CrawlTransition = crawlTransitionType;
				return;
			}
			
			if( EvaluateDamageHitAnimation(source, dmgZone, ammo, m_DamageHitHeavy, m_DamageHitType, m_DamageHitDirection) )
			{
				m_DamageHitToProcess = true;
				return;
			}
		}		
	}
	
	override void EEHitByRemote(int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos)
	{
		super.EEHitByRemote(damageType, source, component, dmgZone, ammo, modelPos);
	}

	//! sound debug messages
	protected void DebugSound(string s)
	{
		//Print(s);
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
	
	bool m_TransportHitRegistered = false;
	vector m_TransportHitVelocity;
	
	void RegisterTransportHit(Transport transport)
	{
		if( !m_TransportHitRegistered )
		{	
			m_TransportHitRegistered = true; 
			m_TransportHitVelocity = GetVelocity(transport);
			
			// compute impulse
			if (m_TransportHitVelocity.Length() > 0.3)
			{
				vector impulse = 40 * m_TransportHitVelocity;
				impulse[1] = 40 * 1.5;
				//Print("Impulse: " + impulse.ToString());
				dBodyApplyImpulse(this, impulse);
			}
			
			// avoid damage because of small movements
			if (m_TransportHitVelocity.Length() > 1.5)
			{
				float damage = 10 * m_TransportHitVelocity.Length();
				//Print("Transport damage: " + damage.ToString() + " velocity: " +  m_TransportHitVelocity.Length().ToString());
				ProcessDirectDamage( 3, transport, "", "TransportHit", "0 0 0", damage );
			}
			else
				m_TransportHitRegistered = false; // EEHitBy is not called if no damage
		}
	}
}