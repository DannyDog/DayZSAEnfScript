enum EMeleeHitType
{
	NONE = -1,

	LIGHT,
	HEAVY,
	SPRINT,
	KICK,

	WPN_HIT,
	WPN_HIT_BUTTSTOCK,
	WPN_STAB,
}

class DayZPlayerImplementMeleeCombat
{
	// target selection settings
	protected const float				TARGETING_ANGLE_NORMAL	= 30.0;
	protected const float				TARGETING_ANGLE_SPRINT	= 15.0;
	protected const float				TARGETING_MIN_HEIGHT	= -2.0;
	protected const float				TARGETING_MAX_HEIGHT	= 2.0;
	protected const float				TARGETING_RAY_RADIUS	= 0.25;
	protected const float				TARGETING_RAY_DIST		= 5.0;
	protected const float				TARGETING_RAY_DIST_SHORT= 2.0;

	protected const float 				RANGE_EXTENDER_NORMAL	= 0.65;
	protected const float 				RANGE_EXTENDER_SPRINT	= 1.35;
	
	protected const string				DEFAULT_HIT_ZONE 		= "Torso";
	
	// members
	protected DayZPlayerImplement		m_DZPlayer;
	
	//! targets - types
	protected Object					m_TargetObject;
	protected EMeleeTargetType			m_TargetType;
	protected ref array<Object> 		m_AllTargetObjects;
	protected ref array<typename>		m_TargetableObjects;
	protected ref array<typename>		m_NonAlignableObjects;

	//! weapons
	protected InventoryItem				m_Weapon;
	protected int						m_WeaponMode;
	protected float						m_WeaponRange;
	
	protected bool 						m_SprintAttack;
	
	protected vector 					m_RayStart;
	protected vector	 				m_RayEnd;
	protected vector	 				m_RayEndShort;

	protected int 						m_HitZoneIdx;
	protected string					m_HitZoneName;
	protected vector					m_HitPositionWS;
	
	protected EMeleeHitType				m_HitType;

	// ------------------------------------------------------------
	// CONSTRUCTOR
	// ------------------------------------------------------------

	void DayZPlayerImplementMeleeCombat(DayZPlayerImplement player)
	{
		Init(player);
	}
	
	void Init(DayZPlayerImplement player)
	{
		m_DZPlayer 		= player;
		
		m_HitZoneName	= "";
		m_HitZoneIdx 	= -1;
		m_HitPositionWS = "-1 -1 -1";
		
		m_TargetObject      = null;
		m_TargetType		= EMeleeTargetType.ALIGNABLE;
		m_AllTargetObjects 	= new array<Object>;

		m_TargetableObjects = new array<typename>; //checks against CONFIG hierarchy
		m_TargetableObjects.Insert(DayZPlayer);
		m_TargetableObjects.Insert(DayZInfected);
		m_TargetableObjects.Insert(DayZAnimal);

		m_NonAlignableObjects = new array<typename>;
		m_NonAlignableObjects.Insert(Building);
		m_NonAlignableObjects.Insert(Car);
		m_NonAlignableObjects.Insert(CarWheel);
		m_NonAlignableObjects.Insert(CarDoor);
		m_NonAlignableObjects.Insert(TentBase);
		m_NonAlignableObjects.Insert(BaseBuildingBase);
	}

	void ~DayZPlayerImplementMeleeCombat() {}

	// ------------------------------------------------------------
	// PUBLIC
	// ------------------------------------------------------------

	EMeleeHitType GetHitType()
	{
		return m_HitType;
	}

	void SetHitZoneIdx(int pHitZone)
	{
		m_HitZoneIdx = pHitZone;
	}
	
	EntityAI GetTargetEntity()
	{
		return EntityAI.Cast(m_TargetObject);
	}

	void SetTargetObject(Object pTarget)
	{
		m_TargetObject = pTarget;
	}
	
	int GetHitZoneIdx()
	{
		return m_HitZoneIdx;
	}
	
	vector GetHitPos()
	{
		return m_HitPositionWS;
	}

	void SetHitPos(vector pHitPos)
	{
		m_HitPositionWS = pHitPos;
	}
	
	int GetWeaponMode()
	{
		return m_WeaponMode;
	}

	void Update(InventoryItem weapon, EMeleeHitType hitMask, bool wasHitEvent = false)
	{
		m_Weapon = weapon;
		m_HitType = hitMask;
		m_TargetType = EMeleeTargetType.ALIGNABLE;
		m_SprintAttack = hitMask == EMeleeHitType.SPRINT;
		m_WeaponMode = SelectWeaponMode(weapon);
		m_WeaponRange = GetWeaponRange(weapon, m_WeaponMode);
		m_AllTargetObjects.Clear();

		if( !GetGame().IsMultiplayer() || !GetGame().IsServer() )
		{
			if( !ScriptInputUserData.CanStoreInputUserData() )
			{
				//Error("DayZPlayerImplementMeleeCombat - ScriptInputUserData already posted");
				return;
			}

			//! target in cone
			TargetSelection();

			//! skips Hit zone selection when called in hit part of anim (WasHit event)
			if( !wasHitEvent || m_TargetType != EMeleeTargetType.NONALIGNABLE )
			{
				HitZoneSelection();
			}

			//! store target into input packet
			if( GetGame().IsMultiplayer() )
			{
				ScriptInputUserData ctx = new ScriptInputUserData;
				ctx.Write(INPUT_UDT_MELEE_TARGET);
				ctx.Write(m_TargetObject);
				ctx.Write(m_HitPositionWS);
				ctx.Write(m_HitZoneIdx);
				ctx.Send();
			}
		}
	}
	
	void CheckMeleeItem()
	{
		if (m_Weapon)
		{
			ItemBase item;
			item = ItemBase.Cast(m_Weapon.ProcessMeleeItemDamage(GetWeaponMode()));
			
			if (item && item.GetHierarchyRootPlayer())
			{
				PlayerBase.Cast(item.GetHierarchyRootPlayer()).SetCheckMeleeItem(item);
			}
			else if (m_Weapon && m_Weapon.GetHierarchyRootPlayer())
			{
				PlayerBase.Cast(m_Weapon.GetHierarchyRootPlayer()).SetCheckMeleeItem(ItemBase.Cast(m_Weapon));
			}
		}
	}
	
	// ------------------------------------------------------------
	// protected
	// ------------------------------------------------------------

	protected int SelectWeaponMode(InventoryItem weapon)
	{
		if( weapon )
		{
			//! melee with firearm (TBD)
			if (weapon.IsInherited(Weapon))
			{
				switch(m_HitType)
				{
					case EMeleeHitType.WPN_HIT:
						return 0;
					break;
					case EMeleeHitType.WPN_HIT_BUTTSTOCK:
						return 1;
					break;
					case EMeleeHitType.WPN_STAB:
						return 2;
					break;
				}
			}
			else
			{
				//! melee weapon attacks - gets mode from the item
				switch(m_HitType)
				{
					case EMeleeHitType.LIGHT:
						return weapon.GetMeleeMode();
					break;
					case EMeleeHitType.HEAVY:
						return weapon.GetMeleeHeavyMode();
					break;
					case EMeleeHitType.SPRINT:
						return weapon.GetMeleeSprintMode();
					break;
				}
			}
		}

		//! bare hand melee mode selection
		switch(m_HitType)
		{
			case EMeleeHitType.HEAVY:
				return 1;
			break;
			case EMeleeHitType.SPRINT:
				return 2;
			break;
		}
		return 0; //! default bare-hand light attack
	}
	
	protected float GetWeaponRange(InventoryItem weapon, int weaponMode)
	{
		if( weapon )
		{
			return weapon.GetMeleeCombatData().GetModeRange(weaponMode);
		}
		else
		{
			return m_DZPlayer.GetMeleeCombatData().GetModeRange(weaponMode);
		}
	}

	protected void TargetSelection()
	{
		PlayerBase player = PlayerBase.Cast(m_DZPlayer);
		vector pos = m_DZPlayer.GetPosition();
		vector dir = MiscGameplayFunctions.GetHeadingVector(player);

		float dist = m_WeaponRange + RANGE_EXTENDER_NORMAL;
		float tgtAngle = TARGETING_ANGLE_NORMAL;
		if (m_SprintAttack)
		{
			dist = m_WeaponRange + RANGE_EXTENDER_SPRINT;
			tgtAngle = TARGETING_ANGLE_SPRINT;
		}

		m_TargetObject = DayZPlayerUtils.GetMeleeTarget(pos, dir, tgtAngle, dist, TARGETING_MIN_HEIGHT, TARGETING_MAX_HEIGHT, m_DZPlayer, m_TargetableObjects, m_AllTargetObjects);

		if(IsObstructed(m_TargetObject))
			m_TargetObject = null;
	}

	protected void HitZoneSelection()
	{
		Object cursorTarget = null;
		PlayerBase player = PlayerBase.Cast(m_DZPlayer);

		// ray properties 
		vector pos;
		vector cameraDirection = GetGame().GetCurrentCameraDirection();

		MiscGameplayFunctions.GetHeadBonePos(player, pos);
		m_RayStart = pos;
		m_RayEnd = pos + cameraDirection * TARGETING_RAY_DIST;
		m_RayEndShort = pos + cameraDirection * TARGETING_RAY_DIST_SHORT;

		// raycast
		ref set<Object> hitObjects = new set<Object>;
		int hitComponentIndex;
		float hitFraction;
		vector start, end, hitNormal, hitPosObstructed;
		PhxInteractionLayers collisionLayerMask = PhxInteractionLayers.DEFAULT;
		
		if ( !DayZPhysics.RaycastRV(m_RayStart, m_RayEndShort, m_HitPositionWS, hitNormal, m_HitZoneIdx, hitObjects, null, player, false, false, ObjIntersectIFire) && !DayZPhysics.RaycastRV(m_RayStart, m_RayEnd, m_HitPositionWS, hitNormal, m_HitZoneIdx, hitObjects, null, player, false, false, ObjIntersectIFire, TARGETING_RAY_RADIUS) )
		{
			m_HitZoneIdx = -1;
			//Print("HitZoneSelection failed");
		}
		else if ( hitObjects.Count() > 0 )
		{
			cursorTarget = hitObjects.Get(0);

			//! make sure we are in range of the current weapon;				
			vector playerPos = m_DZPlayer.GetPosition();
			vector hitPos = m_HitPositionWS;
			//! 2d only
			playerPos[1] = 0;
			hitPos[1] = 0;

			//! just for building and transports (big objects)				
			if( cursorTarget.IsAnyInherited(m_NonAlignableObjects) && vector.Distance(playerPos, hitPos) <= GetWeaponRange(m_Weapon, GetWeaponMode()))
			{
				//! if no object in cone, set this object from raycast for these special cases
				if (m_TargetObject == null)
				{
					m_TargetObject = cursorTarget;
				}
			}

			if ( cursorTarget == m_TargetObject )
			{
				m_HitZoneName = cursorTarget.GetDamageZoneNameByComponentIndex(m_HitZoneIdx);
				//Print("hit object: " + m_TargetObject + " | component idx: " + m_HitZoneIdx + " | hitzone name: " + m_HitZoneName);
			}
			else
			{
				if (m_TargetObject == DayZInfected.Cast(m_TargetObject) || m_TargetObject == PlayerBase.Cast(m_TargetObject))
					m_HitZoneName = DEFAULT_HIT_ZONE; //Default to torso if no zone is targeted 
			}
		}
		else
		{
			m_HitZoneIdx = -1;
			//Print("HitZoneSelection failed");
		}
	}

	protected bool IsObstructed(Object object)
	{
		// check direct visibility of object (obstruction check)
		PhxInteractionLayers collisionLayerMask = PhxInteractionLayers.BUILDING|PhxInteractionLayers.DOOR|PhxInteractionLayers.VEHICLE|PhxInteractionLayers.ROADWAY|PhxInteractionLayers.TERRAIN|PhxInteractionLayers.ITEM_SMALL|PhxInteractionLayers.ITEM_LARGE|PhxInteractionLayers.FENCE;
		int hitComponentIndex;
		float hitFraction;
		vector start, end, hitNormal, hitPosObstructed;
		Object hitObject = null;
		PlayerBase player = PlayerBase.Cast(m_DZPlayer);

		if(object)
		{
			MiscGameplayFunctions.GetHeadBonePos(player, start);
			end = start + MiscGameplayFunctions.GetHeadingVector(player) * vector.Distance(player.GetPosition(), object.GetPosition());
			
			if( end == start )
				return true; //! not possible to trace when this happens (zero length raycast)

			return DayZPhysics.RayCastBullet( start, end, collisionLayerMask, null, hitObject, hitPosObstructed, hitNormal, hitFraction);
		}

		return false;
	}
	
#ifdef DEVELOPER
	// ------------------------------------------------------------
	// DEBUG
	// ------------------------------------------------------------
	protected ref array<Shape> dbgConeShapes = new array<Shape>();
	protected ref array<Shape> dbgTargets = new array<Shape>();
	protected ref array<Shape> hitPosShapes = new array<Shape>();
	
	void Debug(InventoryItem weapon, EMeleeHitType hitType)
	{
		bool show_targets = DiagMenu.GetBool(DiagMenuIDs.DM_MELEE_SHOW_TARGETS) && DiagMenu.GetBool(DiagMenuIDs.DM_MELEE_DEBUG_ENABLE);
		bool draw_targets = DiagMenu.GetBool(DiagMenuIDs.DM_MELEE_DRAW_TARGETS) && DiagMenu.GetBool(DiagMenuIDs.DM_MELEE_DEBUG_ENABLE);
		bool draw_range = DiagMenu.GetBool(DiagMenuIDs.DM_MELEE_DRAW_RANGE) && DiagMenu.GetBool(DiagMenuIDs.DM_MELEE_DEBUG_ENABLE);

		if( show_targets || draw_targets || draw_range )
		{
			if( !GetGame().IsMultiplayer() || !GetGame().IsServer() )
			{
				m_Weapon = weapon;
				m_HitType = hitType;
				m_SprintAttack = (hitType & EMeleeHitType.SPRINT) == EMeleeHitType.SPRINT;
				m_WeaponMode = SelectWeaponMode(weapon);
				m_WeaponRange = GetWeaponRange(weapon, m_WeaponMode);
				m_AllTargetObjects.Clear();
				m_HitPositionWS = "0.5 0.5 0.5";
				
				TargetSelection();
				HitZoneSelection();
			}
		}

		ShowDebugMeleeTarget(show_targets);
		DrawDebugTargets(show_targets);
		DrawDebugMeleeHitPosition(draw_targets);
		DrawDebugMeleeCone(draw_range);
	}

	//! shows target in DbgUI 'window'
	protected void ShowDebugMeleeTarget(bool enabled)
	{
		int windowPosX = 0;
		int windowPosY = 500;

		//DbgUI.BeginCleanupScope();
		DbgUI.Begin("Melee Target", windowPosX, windowPosY);
		if (enabled )
		{
			if ( m_TargetObject )
			{
				DbgUI.Text("Character: " + m_TargetObject.GetDisplayName());
				DbgUI.Text("HitZone: " + m_HitZoneName + "(" + m_HitZoneIdx + ")");
				DbgUI.Text("HitPosWS:" + m_HitPositionWS);
				DbgUI.Text("Distance:" + vector.Distance(m_HitPositionWS,m_RayStart));
			}
		}
		DbgUI.End();
		//DbgUI.EndCleanupScope();
	}

	//! shows debug sphere above the target
	protected void DrawDebugTargets(bool enabled)
	{
		vector w_pos, w_pos_sphr, w_pos_lend;
		Object obj;

		if ( enabled )
		{
			CleanupDebugShapes(dbgTargets);

			for (int i = 0; i < m_AllTargetObjects.Count(); i++ )
			{
				if ( m_TargetObject && m_AllTargetObjects.Count() )
				{
					obj = m_AllTargetObjects.Get(i);
					w_pos = obj.GetPosition();
					// sphere pos tweaks
					w_pos_sphr = w_pos;
					w_pos_sphr[1] = w_pos_sphr[1] + 1.8;
					// line pos tweaks
					w_pos_lend = w_pos;
					w_pos_lend[1] = w_pos_lend[1] + 1.8;
					
					if ( m_AllTargetObjects.Get(i) == m_TargetObject )
					{
						dbgTargets.Insert( Debug.DrawSphere(w_pos_sphr, 0.05, COLOR_RED, ShapeFlags.NOOUTLINE) );
						dbgTargets.Insert( Debug.DrawLine(w_pos, w_pos_lend, COLOR_RED) );
					}
					else
					{
						dbgTargets.Insert( Debug.DrawSphere(w_pos_sphr, 0.05, COLOR_YELLOW, ShapeFlags.NOOUTLINE) );
						dbgTargets.Insert( Debug.DrawLine(w_pos, w_pos_lend, COLOR_YELLOW) );
					}
				}
			}
		}
		else
			CleanupDebugShapes(dbgTargets);
	}
		
	protected void DrawDebugMeleeCone(bool enabled)
	{
		// "cone" settings
		vector start, end, endL, endR;
		float playerAngle;
		float xL,xR,zL,zR;
		float dist = m_WeaponRange + RANGE_EXTENDER_NORMAL;
		float tgtAngle = TARGETING_ANGLE_NORMAL;
		
		PlayerBase player = PlayerBase.Cast(m_DZPlayer);
		if (m_SprintAttack)
		{
			dist = m_WeaponRange + RANGE_EXTENDER_SPRINT;
			tgtAngle = TARGETING_ANGLE_SPRINT;
		}

		if (enabled)
		{
			CleanupDebugShapes(dbgConeShapes);

			start = m_DZPlayer.GetPosition();
			playerAngle = MiscGameplayFunctions.GetHeadingAngle(player);
			
			endL = start;
			endR = start;
			xL = dist * Math.Cos(playerAngle + Math.PI_HALF + tgtAngle * Math.DEG2RAD); // x
			zL = dist * Math.Sin(playerAngle + Math.PI_HALF + tgtAngle * Math.DEG2RAD); // z
			xR = dist * Math.Cos(playerAngle + Math.PI_HALF - tgtAngle * Math.DEG2RAD); // x
			zR = dist * Math.Sin(playerAngle + Math.PI_HALF - tgtAngle * Math.DEG2RAD); // z
			endL[0] = endL[0] + xL;
			endL[2] = endL[2] + zL;
			endR[0] = endR[0] + xR;
			endR[2] = endR[2] + zR;

			dbgConeShapes.Insert( Debug.DrawLine(start, endL, COLOR_BLUE ) );
			dbgConeShapes.Insert( Debug.DrawLine(start, endR, COLOR_BLUE) ) ;
			dbgConeShapes.Insert( Debug.DrawLine(endL, endR, COLOR_BLUE  ) );
		}
		else
			CleanupDebugShapes(dbgConeShapes);		
	}

	protected void DrawDebugMeleeHitPosition(bool enabled)
	{
		if (enabled && m_TargetObject)
		{
			CleanupDebugShapes(hitPosShapes);
			hitPosShapes.Insert( Debug.DrawSphere(m_HitPositionWS, TARGETING_RAY_RADIUS, COLOR_YELLOW, ShapeFlags.NOOUTLINE|ShapeFlags.TRANSP) );
		}
		else
			CleanupDebugShapes(hitPosShapes);
	}

	protected void CleanupDebugShapes(array<Shape> shapes)
	{
		for ( int it = 0; it < shapes.Count(); ++it )
		{
			Debug.RemoveShape( shapes[it] );
		}

		shapes.Clear();
	}
#endif
}