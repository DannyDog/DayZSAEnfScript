
//! this is main camera class 
class DayZPlayerCameraIronsights extends DayZPlayerCameraBase
{
	static const float 	CONST_UD_MIN	= -85.0;		//!< down limit
	static const float 	CONST_UD_MAX	= 85.0;			//!< up limit
	static const float 	CONST_UD_MIN_BACK = -25.0;		//!< down limit on back

	static const float 	CONST_LR_MIN	= -160.0;		//!< down limit
	static const float 	CONST_LR_MAX	= 160.0;			//!< up limit
	
	protected 	bool 			m_isEntering 	= false;
	protected	bool			m_opticsHasWeaponOverride = false;
	protected ref array<float> 	temp_array;

	//! camera dynamics
	float m_velocityYaw[1];
	float m_velocityPitch[1];
	float m_dynamicsStrength;
	float m_dynamicsSmoothTime;
	vector m_SightMisalignmentModifier;
	
	float m_movementTimeAcc;
	float m_movementAmplitudeX;
	float m_movementAmplitudeY;
	float m_movementFrequencyX;
	float m_movementFrequencyY;
	

	void 	DayZPlayerCameraIronsights(DayZPlayer pPlayer, HumanInputController pInput)
	{
		
		if (!temp_array)
			temp_array = new array<float>;
		m_iBoneIndex = pPlayer.GetBoneIndexByName("RightHand_Dummy");
		
		if (m_iBoneIndex == -1)
		{
			Print("DayZPlayerCamera1stPerson: main bone not found");
		}

		m_dynamicsStrength = 2;
		m_dynamicsSmoothTime = 0.3;
		
		SetupSightEntities();
		GetCurrentSightInfo(m_OpticsCamPos, m_OpticsCamDir);
		m_isEntering = true;
		m_WeaponSwayModifier = 0.5;
		
		m_movementTimeAcc = 0;
		m_movementAmplitudeX = 1;
		m_movementAmplitudeY = 1;
		m_movementFrequencyX = 1;
		m_movementFrequencyY = 2;
	}
	
	void SetupSightEntities()
	{		
		EntityAI inHands = m_pPlayer.GetHumanInventory().GetEntityInHands();
		if (inHands)
		{
			m_weaponUsed = Weapon_Base.Cast(inHands);
			if( m_weaponUsed )
			{
				m_SightMisalignmentModifier = m_weaponUsed.GetPropertyModifierObject().m_SightMisalignment;
				m_dynamicsStrength = m_dynamicsStrength * m_SightMisalignmentModifier[0];
				m_dynamicsSmoothTime = m_dynamicsSmoothTime * m_SightMisalignmentModifier[1];
				m_opticsUsed = m_weaponUsed.GetAttachedOptics();
				if( m_opticsUsed )
				{
					m_opticsHasWeaponOverride = m_opticsUsed.HasWeaponIronsightsOverride();
				}
			}
			else
			{
				m_opticsUsed = ItemOptics.Cast(inHands);
			}
		}
	}
	
	//
	override void OnActivate (DayZPlayerCamera pPrevCamera, DayZPlayerCameraResult pPrevCameraResult)
	{
		super.OnActivate(pPrevCamera,pPrevCameraResult);
		vector 	f = pPrevCamera.GetBaseAngles();
		m_fUpDownAngle		= f[0]; 
		m_fLeftRightAngle	= f[1]; 
		m_fUpDownAngleAdd	= f[2];
	}

	EntityAI GetCurrentSightEntity ()
	{
		if( m_opticsHasWeaponOverride )
			return m_opticsUsed;
		
		return m_weaponUsed;
	}

	bool GetCurrentSightInfo (out vector camPos, out vector camDir)
	{
		EntityAI e = GetCurrentSightEntity();
		if( e == m_weaponUsed )
		{
			m_weaponUsed.GetCameraPoint(m_weaponUsed.GetCurrentMuzzle(), camPos, camDir);
			return true;
		}
		else if( e == m_opticsUsed )
		{
			m_opticsUsed.UseWeaponIronsightsOverride(m_opticsHasWeaponOverride);
			m_opticsUsed.GetCameraPoint(camPos, camDir);
			return true;
		}
		return false;
	}
	
	//	
	override void 		OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		//! update angles from input 
		float min;
		DayZPlayerImplement player = DayZPlayerImplement.Cast(GetGame().GetPlayer());
		if (player && player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_RAISEDPRONE))
			min = CONST_UD_MIN_BACK;
		else
			min = CONST_UD_MIN;
		
		float 	udAngle 	= UpdateUDAngle(m_fUpDownAngle, m_fUpDownAngleAdd, min, CONST_UD_MAX, pDt);
		m_CurrentCameraPitch = udAngle;
		m_fLeftRightAngle	= UpdateLRAngle(m_fLeftRightAngle, CONST_LR_MIN, CONST_LR_MAX, pDt);

		// get model space transform matrix of the gun's eye vector 
		vector matTM[4];
		HumanItemAccessor hia = m_pPlayer.GetItemAccessor();
		if(GetCurrentSightEntity())
			hia.WeaponGetCameraPointBoneRelative(GetCurrentSightEntity(), m_OpticsCamPos, m_OpticsCamDir, m_iBoneIndex, matTM);
		
		// aim change based on character movement
		vector aimChangeYPR;
		float aimChangeX = m_pInput.GetAimChange()[0] * Math.RAD2DEG;
		float aimChangeY = m_pInput.GetAimChange()[1] * Math.RAD2DEG;

		HumanCommandMove hcm = m_pPlayer.GetCommand_Move();
		if( hcm )
		{
			float speed = hcm.GetCurrentMovementSpeed();
			
			if( speed > 0 )
				m_movementTimeAcc += pDt;
			else
				m_movementTimeAcc = 0;
			
			aimChangeX += m_movementAmplitudeX * speed * Math.Sin(Math.PI2 * m_movementFrequencyX * m_movementTimeAcc);
			aimChangeY += m_movementAmplitudeY * speed * Math.Sin(Math.PI2 * m_movementFrequencyY * m_movementTimeAcc);
		}

		aimChangeYPR[0] = Math.SmoothCD(aimChangeYPR[0], -(m_dynamicsStrength * aimChangeY), m_velocityYaw, m_dynamicsSmoothTime, 1000, pDt);
		aimChangeYPR[1] = Math.SmoothCD(aimChangeYPR[1], -(m_dynamicsStrength * aimChangeX), m_velocityPitch, m_dynamicsSmoothTime, 1000, pDt);
		aimChangeYPR[2] = 0;

		vector dynamics[4];
		Math3D.YawPitchRollMatrix(aimChangeYPR, dynamics);
		dynamics[3] = vector.Zero;
		
		// aiming model offsets
		vector aimingMatTM[4];
		hia.WeaponGetAimingModelDirTm(aimingMatTM);
		
		// final offset matrix
		Math3D.MatrixMultiply4(dynamics, aimingMatTM, dynamics);
		Math3D.MatrixMultiply4(dynamics, matTM, pOutResult.m_CameraTM);
		AdjustCameraParameters(pDt, pOutResult);
		UpdateBatteryOptics(GetCurrentSightEntity());
		UpdateCameraNV(PlayerBase.Cast(m_pPlayer));
		
		if(m_CameraShake)
		{
			float x,y;
			m_CameraShake.Update(pDt, x, y);
			DayZPlayerImplement.Cast(m_pPlayer).GetAimingModel().SetCamShakeValues(x, y);
		}
	}

	//
	override vector GetBaseAngles()
	{
		vector a;
		a[0] = m_fUpDownAngle;
		a[1] = m_fLeftRightAngle;
		a[2] = m_fUpDownAngleAdd;
		return a;
	}
	
	void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult)
	{
		pOutResult.m_iDirectBone 			= m_iBoneIndex;
		pOutResult.m_iDirectBoneMode 		= 4;
	
		pOutResult.m_fFovAbsolute = HoldBreathFOVEffect(pDt);
		
		pOutResult.m_bUpdateWhenBlendOut	= false;
		pOutResult.m_fDistance 				= 0;
		pOutResult.m_fUseHeading 			= 0;
		pOutResult.m_fInsideCamera 			= 1.0;
		pOutResult.m_fShootFromCamera		= m_fShootFromCamera;
		
		pOutResult.m_fNearPlane = 0.04; //0.07 default
	}
	
	float HoldBreathFOVEffect(float pDt)
	{
		if (m_pPlayer.IsHoldingBreath())
		{
			m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, GameConstants.DZPLAYER_CAMERA_FOV_EYEZOOM, m_fFovAbsVel, 0.1, 1000, pDt);
		}
		else if (m_isEntering) //sets FOV immediatelly to avoid "floating camera" effect
		{
			m_fFovAbsolute = GameConstants.DZPLAYER_CAMERA_FOV_IRONSIGHTS;
			m_isEntering = false;
		}
		else
		{
			m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, GameConstants.DZPLAYER_CAMERA_FOV_IRONSIGHTS, m_fFovAbsVel, 0.1, 1000, pDt);
		}

		return m_fFovAbsolute;
	}
	
	// sets PP for ironsights and optics (override) cameras
	override void SetCameraPP(bool state, DayZPlayerCamera launchedFrom)
	{
		//Print("SetCameraPP - ADS");
		if (!state || !m_weaponUsed || (PlayerBase.Cast(m_pPlayer) && launchedFrom != PlayerBase.Cast(m_pPlayer).GetCurrentPlayerCamera()))
		{
			PPEffects.ResetPPMask();
			PPEffects.SetLensEffect(0, 0, 0, 0);
			PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
			PPEffects.SetBlurOptics(0);
			
			if (IsCameraNV())
			{
				SetNVPostprocess(NVTypes.NV_GOGGLES);
			}
			else
			{
				SetNVPostprocess(NVTypes.NONE);
			}
		}
		else
		{
			PPEffects.ResetPPMask();
			//PPEffects.AddPPMask(0.5, 0.5, 0.3, 0.05);
			PPEffects.SetLensEffect(0, 0, 0, 0);
			if (m_weaponUsed.GetWeaponDOF() || (m_opticsUsed && m_opticsUsed.GetOpticsDOF()))
			{
				if (m_opticsUsed && m_opticsUsed.GetOpticsDOF().Count() == 6)
				{
					temp_array = m_opticsUsed.GetOpticsDOF();
				}
				else
				{
					temp_array = m_weaponUsed.GetWeaponDOF();
				}
				if (temp_array.Count() == 6)
					PPEffects.OverrideDOF(temp_array[0],temp_array[1],temp_array[2],temp_array[3],temp_array[4],temp_array[5]);
			}
			else
				PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
			PPEffects.SetBlurOptics(0);
			
			if (IsCameraNV())
			{
				SetNVPostprocess(NVTypes.NV_GOGGLES);
			}
			else
			{
				SetNVPostprocess(NVTypes.NONE);
			}
		}
		
		if (m_weaponUsed)
		{
			m_weaponUsed.HideWeaponBarrel(false);
		}
	}
	
	override string GetCameraName()
	{
		return "DayZPlayerCameraIronsights";
	}
	
	override void SetCameraPPDelay(DayZPlayerCamera pPrevCamera)
	{
		if (pPrevCamera.GetCameraName() == "DayZPlayerCamera1stPerson")
		{
			//Print("---ironsights---DayZPlayerCamera1stPerson");
			m_CameraPPDelay = DayZPlayerCameras.TIME_CAMERACHANGE_01;
		}
		else if (pPrevCamera.GetCameraName() == "DayZPlayerCameraOptics")
		{
			m_CameraPPDelay = 0;
		}
		else
		{
			//Print("---ironsights---else");
			m_CameraPPDelay = DayZPlayerCameras.TIME_CAMERACHANGE_02;
		}
	}
	
	void UpdateBatteryOptics(EntityAI entity)
	{
		ItemOptics optics = ItemOptics.Cast(entity);
		if (optics)
			optics.UpdateOpticsReddotVisibility();
	}

	//! settings
	protected	float	m_fShootFromCamera = 0.0;
	
	//! runtime values 
	protected	int 	m_iBoneIndex;				//!< right hand dummy bone index
	protected	vector	m_OpticsCamPos;
	protected	vector	m_OpticsCamDir;
	protected 	float 	m_fUpDownAngle;				//!< up down angle in rad
	protected 	float 	m_fUpDownAngleAdd;			//!< up down angle in rad
	protected 	float 	m_fLeftRightAngle;			//!< left right angle in rad (in freelook only)

}

class DayZPlayerCameraOptics : DayZPlayerCameraIronsights
{
	void DayZPlayerCameraOptics(DayZPlayer pPlayer, HumanInputController pInput)
	{
		if (!temp_array)
			temp_array = new array<float>;
		m_fShootFromCamera = 0;
	}
	
	override EntityAI GetCurrentSightEntity ()
	{
		return m_opticsUsed;
	}

	override bool GetCurrentSightInfo (out vector camPos, out vector camDir)
	{
		if (m_opticsUsed)
		{
			m_opticsUsed.UseWeaponIronsightsOverride(false);
			m_opticsUsed.GetCameraPoint(camPos, camDir);
			return true;
		}
		return false;
	}

	override void OnActivate (DayZPlayerCamera pPrevCamera, DayZPlayerCameraResult pPrevCameraResult)
	{
		super.OnActivate(pPrevCamera,pPrevCameraResult);
		
		if (DayZPlayerCameraBase.Cast(pPrevCamera) && DayZPlayerCameraBase.Cast(pPrevCamera).IsCameraNV())
		{
			PPEffects.SetEVValuePP(0); //sets EV value immediately to avoid bright flashes at night
			//PPEffects.SetColorizationNV(0.0, 0.0, 0.0);
		}
		PlayerBase player = PlayerBase.Cast(m_pPlayer);
		if (player)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(player.HideClothing,m_CameraPPDelay*1000,false,m_opticsUsed,true);
		}
	}
	
	override void AdjustCameraParameters(float pDt, inout DayZPlayerCameraResult pOutResult)
	{
		pOutResult.m_iDirectBone 			= m_iBoneIndex;
		pOutResult.m_iDirectBoneMode 		= 4;
	
		pOutResult.m_fFovAbsolute = HoldBreathFOVEffect(pDt);
		
		pOutResult.m_bUpdateWhenBlendOut	= false;
		pOutResult.m_fDistance 				= 0;
		pOutResult.m_fUseHeading 			= 0;
		pOutResult.m_fInsideCamera 			= 1.0;
		pOutResult.m_fShootFromCamera		= m_fShootFromCamera;
		
		pOutResult.m_fNearPlane = 0.06; //0.07 default
	}
	
	override float HoldBreathFOVEffect(float pDt)
	{
		//hotfix; two cameras exist and update simultaneously during transition, even if optics/weapons is no longer present!
		/*PlayerBase player = PlayerBase.Cast(m_pPlayer);
		if (player && player.GetCurrentCamera() != this)
			return 0.6;*/
		
		ItemOptics optics = ItemOptics.Cast( GetCurrentSightEntity() );
		if (optics)
		{
			if (optics.GetCurrentStepFOV() >= GameConstants.DZPLAYER_CAMERA_FOV_EYEZOOM && (m_pPlayer.IsHoldingBreath() || m_pPlayer.IsEyeZoom()))
			{
				m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, GameConstants.DZPLAYER_CAMERA_FOV_EYEZOOM, m_fFovAbsVel, 0.1, 1000, pDt);
			}
			else if (m_isEntering) //sets FOV immediatelly to avoid "floating camera" effect
			{
				m_fFovAbsolute = optics.GetCurrentStepFOV();
				m_isEntering = false;
			}
			else
			{
				m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, optics.GetCurrentStepFOV(), m_fFovAbsVel, 0.1, 1000, pDt);
				//m_fFovAbsolute = optics.GetCurrentStepFOV();
			}
			return m_fFovAbsolute;
		}
		else
		{
			//Error("optic camera, but there is no optic item or optic on weapon"); //camera update ticks on transitions as well, caused problems
			return 0.6;  //TODO figure some other way to get original FOV here!
		}
	}
	
	override void SetCameraPP(bool state,DayZPlayerCamera launchedFrom)
	{
		//Print("SetCameraPP - optics");
		if (!state || !m_opticsUsed || (PlayerBase.Cast(m_pPlayer) && launchedFrom != PlayerBase.Cast(m_pPlayer).GetCurrentPlayerCamera()))
		{
			PPEffects.ResetPPMask();
			PPEffects.SetLensEffect(0, 0, 0, 0);
			PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
			PPEffects.SetBlurOptics(0);
			
			if (IsCameraNV())
			{
				SetNVPostprocess(NVTypes.NV_GOGGLES);
			}
			else
			{
				SetNVPostprocess(NVTypes.NONE);
			}
			
			if (m_weaponUsed)
			{
				m_weaponUsed.HideWeaponBarrel(false);
			}
		}
		else
		{
			PPEffects.ResetPPMask();
			
			// 1x scopes only
			if (m_opticsUsed.AllowsDOF() && !NVGoggles.Cast(m_opticsUsed))
			{
				PPEffects.SetLensEffect(0, 0, 0, 0);
				if (m_weaponUsed)
				{
					if (m_opticsUsed.GetOpticsDOF().Count() == 6)
					{
						temp_array = m_opticsUsed.GetOpticsDOF();
					}
					else
					{
						temp_array = m_weaponUsed.GetWeaponDOF(); //TODO should some optics have own DOF settings (different eye point)?
					}
					
					if (temp_array.Count() == 6)
					{
						PPEffects.OverrideDOF(temp_array[0],temp_array[1],temp_array[2],temp_array[3],temp_array[4],temp_array[5]);
					}
				}
				else
					PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
				
				// optics NV mode
				if (m_opticsUsed.IsNVOptic())
				{
					if (m_opticsUsed.IsWorking())
					{
						SetCameraNV(true);
						SetNVPostprocess(NVTypes.NV_OPTICS_ON);
					}
					else
					{
						SetCameraNV(false);
						SetNVPostprocess(NVTypes.NV_OPTICS_OFF);
					}
				}
				else
				{
					if (IsCameraNV())
					{
						SetNVPostprocess(NVTypes.NV_GOGGLES);
					}
					else
					{
						SetNVPostprocess(NVTypes.NONE);
					}
				}
			}
			else //magnifying scopes
			{
				// optics mask
				if (m_opticsUsed.GetOpticsPPMask() && m_opticsUsed.GetOpticsPPMask().Count() == 4)
				{
					temp_array = m_opticsUsed.GetOpticsPPMask();
					
					PPEffects.AddPPMask(temp_array[0], temp_array[1], temp_array[2], temp_array[3]);
					//PPEffects.AddPPMask(0.5, 0.5, 0.4, 0.05);
				}
				
				//optics lens
				if (m_opticsUsed.GetOpticsPPLens() && m_opticsUsed.GetOpticsPPLens().Count() == 4)
				{
					temp_array = m_opticsUsed.GetOpticsPPLens();
					
					PPEffects.SetLensEffect(temp_array[0], temp_array[1], temp_array[2], temp_array[3]);
					//PPEffects.SetLensEffect(1, 0.15, 0, 0 );
				}
				else
				{
					PPEffects.SetLensEffect(0, 0, 0, 0);
				}
				
				//optics blur
				if (m_opticsUsed.GetOpticsPPBlur() != 0)
				{
					PPEffects.SetBlurOptics(m_opticsUsed.GetOpticsPPBlur());
				}
				else
					PPEffects.SetBlurOptics(0);
				
				// optics NV mode
				if (m_opticsUsed.IsNVOptic())
				{
					if (m_opticsUsed.IsWorking())
					{
						SetCameraNV(true);
						SetNVPostprocess(NVTypes.NV_OPTICS_ON);
					}
					else
					{
						SetCameraNV(false);
						SetNVPostprocess(NVTypes.NV_OPTICS_OFF);
					}
				}
				else
				{
					SetNVPostprocess(NVTypes.NONE);
				}
			}
			
			if (m_weaponUsed)
			{
				m_weaponUsed.HideWeaponBarrel(true);
			}
		}
	}
	
	override string GetCameraName()
	{
		return "DayZPlayerCameraOptics";
	}
	
	override void SetCameraPPDelay(DayZPlayerCamera pPrevCamera)
	{
		if (pPrevCamera.GetCameraName() == "DayZPlayerCameraIronsights")
		{
			m_CameraPPDelay = DayZPlayerCameras.TIME_CAMERACHANGE_02 - 0.05;
		}
		else if (pPrevCamera.GetCameraName() == "DayZPlayerCamera1stPerson")
		{
			m_CameraPPDelay = DayZPlayerCameras.TIME_CAMERACHANGE_02 - 0.05; //changed to accomodate handheld optics, had to be changed here also
		}
		else if (!pPrevCamera.IsCamera3rdRaised())
		{
			m_CameraPPDelay = DayZPlayerCameras.TIME_CAMERACHANGE_03 - 0.05;
		}
		else
		{
			m_CameraPPDelay = DayZPlayerCameras.TIME_CAMERACHANGE_02 - 0.05;
		}
	}
	
	//different handling in optics; no NV outside designated NV scopes
	override void UpdateCameraNV(PlayerBase player)
	{
		if ( !m_opticsUsed || (m_opticsUsed && !m_opticsUsed.IsNVOptic()) )
		{
			if (m_opticsUsed && m_opticsUsed.AllowsDOF()) //1x scopes
			{
				super.UpdateCameraNV(player);
			}
			else if ( IsCameraNV() )
			{
				//super.UpdateCameraNV(player);
				SetCameraNV(false);
			}
		}
	}
};

