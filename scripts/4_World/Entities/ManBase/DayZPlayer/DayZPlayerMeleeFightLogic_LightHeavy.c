//! Light / Heavy punches

enum EFightLogicCooldownCategory
{
	EVADE = 0
}

class DayZPlayerMeleeFightLogic_LightHeavy
{
	//! cooldown timers settings
	const float EVADE_COOLDOWN			= 0.5;
	
	//
	const float CLOSE_TARGET_DISTANCE	= 1.2;
	
	//! dummy ammo types 
	const string DUMMY_LIGHT_AMMO		= "Dummy_Light";
	const string DUMMY_HEAVY_AMMO		= "Dummy_Heavy";


	protected DayZPlayerImplement					m_DZPlayer;
	protected ref DayZPlayerImplementMeleeCombat	m_MeleeCombat;
	protected EMeleeHitType							m_HitType;
	protected ref map <int, ref Timer>				m_CooldownTimers;
	protected Mission 								m_Mission;

	protected bool									m_IsInBlock;
	protected bool									m_IsEvading;

	void DayZPlayerMeleeFightLogic_LightHeavy(DayZPlayerImplement player)
	{
		Init(player);
	}
	
	void Init(DayZPlayerImplement player)
	{
		m_DZPlayer 			= player;
		m_MeleeCombat		= m_DZPlayer.GetMeleeCombat();
		m_Mission			= GetGame().GetMission();

		m_IsInBlock 		= false;
		m_IsEvading	 		= false;
		m_HitType			= EMeleeHitType.NONE;
		
		RegisterCooldowns();
	}

	void ~DayZPlayerMeleeFightLogic_LightHeavy() {}

	bool IsInBlock()
	{
		return m_IsInBlock;
	}
	
	bool IsEvading()
	{
		return m_IsEvading;
	}

	protected void RegisterCooldowns()
	{
		m_CooldownTimers	= new map<int, ref Timer>;
		m_CooldownTimers.Insert(EFightLogicCooldownCategory.EVADE, new Timer(CALL_CATEGORY_SYSTEM)); // evades
	}

	protected EMeleeHitType GetAttackTypeFromInputs(HumanInputController pInputs)
	{
		if (pInputs.IsMeleeFastAttackModifier() && m_DZPlayer.CanConsumeStamina(EStaminaConsumers.MELEE_HEAVY))
		{
			return EMeleeHitType.HEAVY;
		}
		else
		{
			return EMeleeHitType.LIGHT;
		}
	}
	
	protected EMeleeHitType GetAttackTypeByWeaponAttachments(EntityAI pEntity)
	{
		if( !m_DZPlayer.CanConsumeStamina(EStaminaConsumers.MELEE_HEAVY) )
		{
			return EMeleeHitType.NONE;
		}

		//! use stabbing if the bayonet/knife is attached to firearm
		if( pEntity.HasBayonetAttached() )
		{
			return EMeleeHitType.WPN_STAB;
		}
		else if( pEntity.HasButtstockAttached() )
		{
			return EMeleeHitType.WPN_HIT_BUTTSTOCK;
		}
		else
		{
			return EMeleeHitType.WPN_HIT;
		}
	}

	protected float GetAttackTypeByDistanceToTarget(EntityAI pTarget, EMeleeTargetType pTargetType = EMeleeTargetType.ALIGNABLE)
	{
		if( pTargetType == EMeleeTargetType.NONALIGNABLE )
			return 1.0;

		if( pTarget )
		{
			//! target in short distance - in place attack
			if( vector.Distance(m_DZPlayer.GetPosition(), pTarget.GetPosition()) <= CLOSE_TARGET_DISTANCE )
			{
				return 1.0;
			}
		}
		
		//! target is far from the player - forward movement attack
		return 0.0;
	}

	bool HandleFightLogic(int pCurrentCommandID, HumanInputController pInputs, EntityAI pEntityInHands, HumanMovementState pMovementState, out bool pContinueAttack)
	{		
		InventoryItem itemInHands = InventoryItem.Cast(pEntityInHands);
		HumanCommandMove hcm = m_DZPlayer.GetCommand_Move();
		
		//Get worn gloves
		ClothingBase gloves = ClothingBase.Cast(PlayerBase.Cast(m_DZPlayer).GetItemOnSlot("GLOVES"));
		PlayerBase player = PlayerBase.Cast(m_DZPlayer);
				
		bool isFireWeapon = itemInHands && itemInHands.IsWeapon();
		bool isNotMeleeWeapon = itemInHands && !itemInHands.IsMeleeWeapon(); // TODO: allowed for everything that is not disabled in config (primarily for anim testing)

		if ((pInputs.IsUseButtonDown() && !isFireWeapon) || (pInputs.IsMeleeWeaponAttack() && isFireWeapon) || (pContinueAttack && isFireWeapon))
		{
			float attackByDistance;
			EntityAI target;
			EMeleeTargetType targetType;
			
			//! do not perform attacks when blocking
			if (m_IsInBlock || m_IsEvading)
			{
				return true;
			}

			//! if the item in hands cannot be used as melee weapon
			if (isNotMeleeWeapon && !isFireWeapon)
			{
				return false;
			}
			
			//If player has BrokenLegs she cannot use melee weapons
			/*PlayerBase m_PlayerBase = PlayerBase.Cast(m_DZPlayer);
			if (m_PlayerBase.m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
				return false;*/

			if (pCurrentCommandID == DayZPlayerConstants.COMMANDID_MOVE)
			{
				//! melee with firearm
				if (isFireWeapon)
				{
					//! don't allow bash to interfere with actions like chambering or ejecting bullets
					Weapon_Base weapon = Weapon_Base.Cast(itemInHands);
					//PlayerBase player = PlayerBase.Cast(m_DZPlayer);
					if (weapon.IsWaitingForActionFinish() || player.GetActionManager().GetRunningAction())
						return false;
					
					//! perform firearm melee from raised erect or continue with attack after character stand up from crouch
					else if (hcm.GetCurrentMovementSpeed() <= 2.05 && (pMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDERECT || pContinueAttack) && !m_DZPlayer.IsFighting())
					{
						m_HitType = GetAttackTypeByWeaponAttachments(pEntityInHands);
						if( m_HitType == EMeleeHitType.NONE )
							return false; //! exit if there is no suitable attack

						m_MeleeCombat.Update(itemInHands, m_HitType);

						GetTargetData(target, targetType);
						attackByDistance = GetAttackTypeByDistanceToTarget(target, targetType);

						m_DZPlayer.StartCommand_Melee2(target, m_HitType == EMeleeHitType.WPN_STAB, attackByDistance);
						m_DZPlayer.DepleteStamina(EStaminaModifiers.MELEE_HEAVY);
						DisableControls();

						pContinueAttack = false; // reset continueAttack flag

						return true;
					}				
					//! char stand up when performing firearm melee from crouch
					else if( pMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDCROUCH )
					{
						if (hcm)
						{
							hcm.ForceStance(DayZPlayerConstants.STANCEIDX_RAISEDERECT);
							pContinueAttack = true;
							return false;
						}
					}
				}
				else
				{
					//! first attack in raised erc (light or heavy if modifier is used)
					if (pMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDERECT)
					{
						m_HitType = GetAttackTypeFromInputs(pInputs);
						m_MeleeCombat.Update(itemInHands, m_HitType);

						GetTargetData(target, targetType);
						attackByDistance = GetAttackTypeByDistanceToTarget(target, targetType);

						m_DZPlayer.StartCommand_Melee2(target, m_HitType == EMeleeHitType.HEAVY, attackByDistance);
						//PlayerBase m_PlayerBase = PlayerBase.Cast(m_DZPlayer);
						if (m_HitType == EMeleeHitType.HEAVY)
						{
							m_DZPlayer.DepleteStamina(EStaminaModifiers.MELEE_HEAVY);
							if (player.m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
							{	
								player.m_ShockHandler.SetShock(PlayerConstants.BROKEN_LEGS_HEAVY_MELEE_SHOCK);
								player.m_ShockHandler.CheckValue(true);
								//m_PlayerBase.DealShock(PlayerConstants.BROKEN_LEGS_HEAVY_MELEE_SHOCK);
							}
						}
						else
						{
							m_DZPlayer.DepleteStamina(EStaminaModifiers.MELEE_LIGHT);
							if (player.m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
							{
								player.m_ShockHandler.SetShock(PlayerConstants.BROKEN_LEGS_LIGHT_MELEE_SHOCK);
								player.m_ShockHandler.CheckValue(true);
								//m_PlayerBase.DealShock(PlayerConstants.BROKEN_LEGS_LIGHT_MELEE_SHOCK);
							}
						}	
						DisableControls();
						return true;
					}
					//! kick from raised pne
					else if (pMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDPRONE)
					{
						HumanCommandWeapons hcw = m_DZPlayer.GetCommandModifier_Weapons();
						
						PlayerBase m_Player = PlayerBase.Cast(m_DZPlayer);
						//Print("Broken leg state : " + m_Player.m_BrokenLegState);
						
						float hcw_angle = hcw.GetBaseAimingAngleLR();
						//! check if player is on back
						//! (situation where the player is raised in prone and on back is not in anim graph)
						if( ( hcw_angle < -90 || hcw_angle > 90 ) && m_Player.m_BrokenLegState != eBrokenLegs.BROKEN_LEGS )
						{
							m_HitType = EMeleeHitType.KICK;
							m_MeleeCombat.Update(itemInHands, m_HitType);
	
							GetTargetData(target, targetType);
							attackByDistance = GetAttackTypeByDistanceToTarget(target, targetType);
	
							m_DZPlayer.StartCommand_Melee2(target, false, attackByDistance);
							m_DZPlayer.DepleteStamina(EStaminaModifiers.MELEE_HEAVY);
							DisableControls();
							return true;
						}
						
						return false;
					}
					//! sprint attack in erc stance
					else if (pMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_ERECT && m_DZPlayer.IsSprintFull())
					{
						m_HitType = EMeleeHitType.SPRINT;
						m_MeleeCombat.Update(itemInHands, m_HitType);

						GetTargetData(target, targetType);
						attackByDistance = GetAttackTypeByDistanceToTarget(target, targetType);

						m_DZPlayer.StartCommand_Melee2(target, false, attackByDistance);
						m_DZPlayer.DepleteStamina(EStaminaModifiers.MELEE_HEAVY);
						DisableControls();
						return true;
					}
				}
			}
			//! combo hits - when we are already in Melee command and clicking UseButton
			else if (pCurrentCommandID == DayZPlayerConstants.COMMANDID_MELEE2)
			{
				//! no suitable attack - skip that
				if( m_HitType == EMeleeHitType.NONE )
					return false;

				HumanCommandMelee2 hmc2 = m_DZPlayer.GetCommand_Melee2();

				if (hmc2 && hmc2.IsInComboRange())
				{
					//! select if the next attack will light or heavy (based on input/attachment modifier)
					if( !isFireWeapon )
					{
						m_HitType = GetAttackTypeFromInputs(pInputs);
					}
					else
					{
						m_HitType = GetAttackTypeByWeaponAttachments(pEntityInHands);
					}

					//! continue 'combo' - left hand attacks
					if (m_HitType == EMeleeHitType.HEAVY || m_HitType == EMeleeHitType.WPN_STAB)
					{
						//m_MeleeCombat.Update(itemInHands, m_HitType);
						GetTargetData(target, targetType);						
						attackByDistance = GetAttackTypeByDistanceToTarget(target, targetType);
						
						//!Testing
						player = PlayerBase.Cast(m_DZPlayer);
						if (player.m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
						{
							player.m_ShockHandler.SetShock(PlayerConstants.BROKEN_LEGS_HEAVY_MELEE_SHOCK);
							player.m_ShockHandler.CheckValue(true);
						}
						hmc2.ContinueCombo(true, attackByDistance);

						DisableControls();
					}
					else
					{
						//m_MeleeCombat.Update(itemInHands, m_HitType);
						GetTargetData(target, targetType);
						attackByDistance = GetAttackTypeByDistanceToTarget(target, targetType);

						player = PlayerBase.Cast(m_DZPlayer);
						if (player.m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
						{
							player.m_ShockHandler.SetShock(PlayerConstants.BROKEN_LEGS_LIGHT_MELEE_SHOCK);
							player.m_ShockHandler.CheckValue(true);
						}
						hmc2.ContinueCombo(false, attackByDistance);

						DisableControls();
					}

					//! stamina depletion per attack
					switch( m_HitType )
					{
						case EMeleeHitType.HEAVY:
						case EMeleeHitType.SPRINT:
						case EMeleeHitType.WPN_STAB:
						case EMeleeHitType.WPN_HIT_BUTTSTOCK:
						case EMeleeHitType.WPN_HIT:
							m_DZPlayer.DepleteStamina(EStaminaModifiers.MELEE_HEAVY);
						break;
						default:
							m_DZPlayer.DepleteStamina(EStaminaModifiers.MELEE_LIGHT);
						break;
					}

					return true;
				}
				else
				{
					return true;
				}
			}
		}
		else if (pCurrentCommandID == DayZPlayerConstants.COMMANDID_MELEE2)
		{
			HumanCommandMelee2 hmc2a = m_DZPlayer.GetCommand_Melee2();
			if (hmc2a)
			{
				//! on anim event Hit received
				if (hmc2a.WasHit())
				{
					//! re-target (enemy can be already away)
					m_MeleeCombat.Update(itemInHands, m_HitType, true);
					//! evaluate hit - selection of cfg 'ammo' type
					EvaluateHit(itemInHands);
					
					//If we hit something, inflict damage
					DamageHands(m_DZPlayer, gloves, itemInHands);
					//! reset - prepared for next hit
					m_MeleeCombat.SetTargetObject(null);
					m_MeleeCombat.SetHitPos(vector.Zero);
					m_MeleeCombat.SetHitZoneIdx(-1);
					
					//m_MeleeCombat.CheckMeleeItem();
					
					EnableControls();
				}
			}
		}
		else if (!isFireWeapon && pCurrentCommandID == DayZPlayerConstants.COMMANDID_MOVE)
		{			
			HumanCommandMove cm = m_DZPlayer.GetCommand_Move();

			int 	roll = pInputs.IsMeleeLREvade();

			//! evades in raised erc stance while moving
			if (pMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDERECT && roll != 0)
			{
				//! not enough stamina to do evades
				if (!m_DZPlayer.CanConsumeStamina(EStaminaConsumers.MELEE_EVADE)) return false;

				float angle;
				if (roll == 1)
				{
					angle = -90;	// left
				}
				else
				{
					angle = 90;		// right
				}

				// start melee evade
				m_IsEvading = true;
				SetCooldown(EVADE_COOLDOWN, EFightLogicCooldownCategory.EVADE);
				cm.StartMeleeEvadeA(angle);
				m_DZPlayer.DepleteStamina(EStaminaModifiers.MELEE_EVADE);
				
				//Inflict shock when sidestepping with broken legs
				if (player.m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
				{
					player.m_ShockHandler.SetShock(PlayerConstants.BROKEN_LEGS_LIGHT_MELEE_SHOCK);
					player.m_ShockHandler.CheckValue(true);
				}
			}

			//! stand up when crouching and raised pressed
			if (pInputs.IsWeaponRaised() && pMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_CROUCH)
			{
				cm.ForceStance(DayZPlayerConstants.STANCEIDX_RAISEDERECT);
			}

			//! blocks in raised erc/pro stance
			//! (bare hand or with melee weapon only)
			if (!isFireWeapon && (pMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDERECT || pMovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDPRONE))
			{
				float angle2;

				if (cm.GetCurrentInputAngle(angle2) && (angle2 < -130.0 || angle2 > 130))
				{
					cm.SetMeleeBlock(true);
					m_IsInBlock = true;
				}
				else
				{
					cm.SetMeleeBlock(false);
					m_IsInBlock = false;
				}
			}
			else
			{
				cm.SetMeleeBlock(false);
				m_IsInBlock = false;
			}
		}

		return false;
	}

	protected void EvaluateHit(InventoryItem weapon)
	{
		EntityAI target = m_MeleeCombat.GetTargetEntity();

		if( target )
		{
			if( target.IsInherited(DayZPlayer) )
			{
				EvaluateHit_Player(weapon, target);
			}
			else if( target.IsInherited(DayZInfected) )
			{
				EvaluateHit_Infected(weapon, target);
			}
			else if( target.GetMeleeTargetType() == EMeleeTargetType.NONALIGNABLE )
			{
				EvaluateHit_NonAlignableObjects(weapon, target);
			}
			else
			{
				EvaluateHit_Common(weapon, target);
			}
			
			m_MeleeCombat.CheckMeleeItem();
		}
	}

	protected void EvaluateHit_Player(InventoryItem weapon, Object target)
	{
		int hitZoneIdx = m_MeleeCombat.GetHitZoneIdx();
		int weaponMode = m_MeleeCombat.GetWeaponMode();
		vector hitPosWS;
		bool forcedDummy = false;

		PlayerBase targetPlayer = PlayerBase.Cast(target);

		//! Melee Hit/Impact modifiers
		if( targetPlayer )
		{
			//! if the oponnent is in Melee Block shift the damage down
			if( targetPlayer.GetMeleeFightLogic() && targetPlayer.GetMeleeFightLogic().IsInBlock())
			{
				if( weaponMode > 0 )
				{
					weaponMode--; // Heavy -> Light shift
				}
				else
				{
					forcedDummy = true; // dummy hits, cannot shift lower than 0
				}
			}
		}

		EvaluateHit_Common(weapon, target, forcedDummy);
	}
	
	protected void EvaluateHit_Infected(InventoryItem weapon, Object target)
	{
		int hitZoneIdx = m_MeleeCombat.GetHitZoneIdx();
		int weaponMode = m_MeleeCombat.GetWeaponMode();
		vector hitPosWS;

		DayZInfected targetInfected = DayZInfected.Cast(target);

		//! check and evaluate stealth kill
		if( targetInfected && weapon )
		{
			//! perform only for finisher suitable weapons in combination with heavy melee attack OR stabbing with firearm melee
			if((m_HitType == EMeleeHitType.HEAVY && weapon.IsMeleeFinisher()) || m_HitType == EMeleeHitType.WPN_STAB)
			{
				//! check if attacker is in right pos and angle against victim
				if( IsBehindEntity(45, m_DZPlayer, target) )
				{
					EntityAI targetEntity = EntityAI.Cast(target);

					//! translate idx to name
					string compName = targetEntity.GetDamageZoneNameByComponentIndex(hitZoneIdx);
	
					//check if name is in suitable components list
					if( targetEntity.GetSuitableFinisherHitComponents().Find(compName) > -1 )
					{
						// execute attack (dmg part)
						hitPosWS = targetEntity.ModelToWorld(targetEntity.GetDefaultHitPosition());
						DamageSystem.CloseCombatDamage(m_DZPlayer, target, hitZoneIdx, "FinisherHit", hitPosWS);
						return; //! early exit
					}
				}
			}
		}
		
		EvaluateHit_Common(weapon, target);
	}
	
	protected void EvaluateHit_Common(InventoryItem weapon, Object target, bool forcedDummy=false)
	{
		int hitZoneIdx = m_MeleeCombat.GetHitZoneIdx();
		int weaponMode = m_MeleeCombat.GetWeaponMode();
		vector hitPosWS;
		string ammo;

		EntityAI targetEntity = EntityAI.Cast(target);

		//! check if we need to use dummy hit
		if(!DummyHitSelector(m_HitType, ammo) && !forcedDummy)
		{
			//! normal hit with applied damage to targeted component
			if (hitZoneIdx >= 0)
			{
				hitPosWS = targetEntity.ModelToWorld(targetEntity.GetDefaultHitPosition());
				m_DZPlayer.ProcessMeleeHit(weapon, weaponMode, target, hitZoneIdx, hitPosWS);
			}
		}
		else
		{
			//! play hit animation for dummy hits
			if( GetGame().IsServer() && targetEntity )
			{
				hitPosWS = targetEntity.ModelToWorld(targetEntity.GetDefaultHitPosition()); //! override hit pos by pos defined in type
				targetEntity.EEHitBy(null, 0, m_DZPlayer, hitZoneIdx, "", ammo, hitPosWS, 1.0);
			}
		}
	}

	protected void EvaluateHit_NonAlignableObjects(InventoryItem weapon, Object target)
	{
		int hitZoneIdx = m_MeleeCombat.GetHitZoneIdx();

		if (hitZoneIdx >= 0)
		{
			m_DZPlayer.ProcessMeleeHit(weapon, m_MeleeCombat.GetWeaponMode(), target, hitZoneIdx, m_MeleeCombat.GetHitPos());
		}

		return;
	}

	protected void GetTargetData(out EntityAI target, out EMeleeTargetType targetType)
	{
		target = m_MeleeCombat.GetTargetEntity();
		targetType = EMeleeTargetType.ALIGNABLE; //! default
		
		if( target )
		{
			targetType = target.GetMeleeTargetType();
		}

		//! nullify target for nonalignable objects (big objects)
		if( targetType == EMeleeTargetType.NONALIGNABLE )
		{
			target = null;
		}
	}

	//! evaluation of hit player vs. player
	protected bool DummyHitSelector(EMeleeHitType hitType, out string ammoType)
	{
		switch(hitType)
		{
		//! in case of kick (on back or push from erc) change the ammo type to dummy
		case EMeleeHitType.KICK:
			ammoType = DUMMY_HEAVY_AMMO;
			return true;
		break;
		}
		
		ammoType = DUMMY_LIGHT_AMMO;
		
		return false;
	}
	
	protected bool IsBehindEntity(int angle, DayZPlayer source, Object target)
	{
		//! behind entity check			
		vector targetDirection = target.GetDirection();
		vector toSourceDirection = (source.GetPosition() - target.GetPosition());

		targetDirection[1] = 0;
		toSourceDirection[1] = 0;

		targetDirection.Normalize();
		toSourceDirection.Normalize();

		float cosFi = vector.Dot(targetDirection, toSourceDirection);
		vector cross = targetDirection * toSourceDirection;

		int hitDir = Math.Acos(cosFi) * Math.RAD2DEG;
		
		if( cross[1] < 0 )
			hitDir = -hitDir;
		
		if( hitDir <= (-180 + angle) || hitDir >= (180 - angle) )
		{
			//Print("HitDir: " + hitDir + " angle passed");
			return true;
		}
		
		return false;
	}

	protected void SetCooldown(float time, EFightLogicCooldownCategory cooldownCategory)
	{
		//! stops currently running cooldown timer (for specific category)
		if( m_CooldownTimers.Get(cooldownCategory).IsRunning() )
		{
			m_CooldownTimers.Get(cooldownCategory).Stop();
		}
		
		//! param for ResetCooldown
		Param1<int> param = new Param1<int>(cooldownCategory);
		m_CooldownTimers.Get(cooldownCategory).Run(time, this, "ResetCooldown", param);
	}
	
	protected void ResetCooldown(EFightLogicCooldownCategory cooldownCategory)
	{
		switch(cooldownCategory)
		{
		case EFightLogicCooldownCategory.EVADE:
			m_IsEvading = false;
		break;
		}
	}

	protected void EnableControls()
	{
		/*
		if(m_Mission)
		{
			m_Mission.PlayerControlEnable(true);
		}
		*/
	}

	protected void DisableControls()
	{
		/*
		if(m_Mission)
		{
			m_Mission.PlayerControlDisable(INPUT_EXCLUDE_MOUSE_ALL);
		}
		*/
	}
	
	protected void DamageHands(DayZPlayer DZPlayer, ClothingBase gloves, InventoryItem itemInHands)
	{
		EntityAI target = m_MeleeCombat.GetTargetEntity();
		
		//We did not hit anything
		if ( !target )
			return;
		
		//Check if server side
		if ( DZPlayer.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER && !itemInHands )
		{
			//If gloves, damage gloves
			if ( gloves && gloves.GetHealthLevel() < GameConstants.STATE_RUINED )
			{
				gloves.DecreaseHealth("", "", 1);
			}
			else
			{
				//If no gloves, inflict hand damage and bleeding
				//DZPlayer.DecreaseHealth("hands", "", 10); IN CASE WE WANT TO DO STUFF WITH HAND HEALTH
				
				//Do not add bleeding if hitting player, zombie or animal
				if ( PlayerBase.Cast(target) || DayZInfected.Cast(target) || AnimalBase.Cast(target) )
					return;
				
				//Random bleeding source
				int m_RandNum = Math.RandomIntInclusive(1, 15);
				switch (m_RandNum)
				{
					case 1:
						PlayerBase.Cast(DZPlayer).m_BleedingManagerServer.AttemptAddBleedingSourceBySelection("RightForeArmRoll");
					break;
					
					case 2:
						PlayerBase.Cast(DZPlayer).m_BleedingManagerServer.AttemptAddBleedingSourceBySelection("LeftForeArmRoll");
					break;
					
					default:
						//Do nothing here
					break;
				}
			}
		}
	}
}