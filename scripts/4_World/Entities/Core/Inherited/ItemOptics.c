class ItemOptics extends InventoryItemSuper
{
	bool 				m_data_set;
	bool 				m_allowsDOF; //true if optics DOES NOT have magnification (FOV >= DZPLAYER_CAMERA_FOV_IRONSIGHTS)
	bool 				m_reddot_displayed
	bool 				m_isNVOptic = false;
	int 				m_reddot_index;
	float 				m_blur_float;
	float 				m_nearplane_override; //override value for DayZPlayerCameraOptics only!
	string 				m_optic_sight_texture;
	string 				m_optic_sight_material;
	string 				m_2D_preload_type;
	ref array<float> 	m_mask_array;
	ref array<float> 	m_lens_array;
	ref array<float> 	m_OpticsDOFProperties = new array<float>;
		
	void ItemOptics()
	{
		m_mask_array = new array<float>;
		m_lens_array = new array<float>;
		InitReddotData();
		InitOpticsPPInfo();
		InitCameraOverrideProperties();
		InitOpticsDOFProperties(m_OpticsDOFProperties);
		Init2DPreloadType();
	}
	
	/**@fn		EnterOptics
	 * @brief	switches to optics mode if possible
	 * @return true if success, false otherwise
	 **/
	proto native bool EnterOptics ();
	
	/**@fn		IsInOptics
	 * @brief	is weapon in optics mode or not
	 * @return true if in optics mode, false otherwise
	 **/
	proto native bool IsInOptics ();
	
	/**@fn		ExitOptics
	 * @brief	switches out of optics mode (if possible)
	 * @return true if success, false otherwise
	 **/
	proto native bool ExitOptics ();

	/**@fn		HasWeaponIronsightsOverride
	 * @brief	is weapon in optics mode or not
	 * @return true if optics has defined override optics info for weapon
	 **/
	proto native bool HasWeaponIronsightsOverride ();
	
	/**@fn		UseWeaponIronsightsOverride
	 * @brief	switches into ironsights override settings
	 * @return  true if switching was successful
	 **/
	proto native bool UseWeaponIronsightsOverride(bool state);

	/**@fn		IsUsingWeaponIronsightsOverride
	 * @brief	is optics using ironsights override settings or not
	 * @return  true if optics is using ironsights override settings
	 **/
	proto native bool IsUsingWeaponIronsightsOverride();

		/**@fn		GetStepFOVCount
	 * @brief	returns number of configured steps
	 **/
	proto native int GetStepFOVCount ();
	
	/**@fn		GetStepZoom
	 * @brief	returns position of currently used value in discreteFov config array
	 * @return	position of currently used value in discreteFov config array
	 **/
	proto native int GetStepFOVIndex ();
	
	/**@fn		SetStepZoom
	 * @brief sets zoom to fov value defined at given position in discreteFov config array
	 * @param[in] index of configured step, range [0..cfg_max]
	 * @return	true if zoom set
	 **/
	proto native bool SetStepFOVIndex (int step);
	
	/**@fn		StepZoomIn
	 * @brief sets zoom to next defined (respective to current) value in zoom fov config array
	 * @return	true if zoom set
	 **/
	proto native bool StepFOVUp ();
	
	/**@fn		StepZoomOut
	 * @brief	sets zoom to previous (respective to current) defined value in zoom fov config array
	 * @return	true if zoom set
	 **/
	proto native bool StepFOVDown ();

	/**@fn		GetCurrentStepFOV
	 * @brief	returns fov at current index, or _opticInfo._opticsZoomInit
	 **/
	proto native float GetCurrentStepFOV ();

	/**@fn		GetStepZeroing
	 * @brief	returns position of currently used value in zeroing config array
	 * @return	 position of currently used value in zeroing config array
	 **/
	proto native int GetStepZeroing ();
	
	/**@fn		SetZeroing
	 * @brief sets zeroing to value defined at given position in zeroing config array
	 * @param[in] index of zeroing to set [0..cfg_max]
	 * @return	true if zeroing set
	 **/
	proto native bool SetStepZeroing (int step);
	
	/**
	 * @fn		StepZeroingUp
	 * @brief sets zeroing to next defined (respective to current) value in zeroing config array
	 * @return true if zeroing set
	 **/
	proto native bool StepZeroingUp ();
	
	/**
	 * @fn		StepZeroingDown
	 * @brief	sets zeroing to previous (respective to current) defined value in zeroing config array
	 * @return true if zeroing set
	 **/
	proto native bool StepZeroingDown ();
	
	/**
	 * @fn		GetCameraPoint
	 * @brief	gets camera position & direction in model space of optics entity
	 **/
	proto native void GetCameraPoint (out vector pos, out vector dir);
	
	/**
	 * @fn		GetZoomInit
	 * @brief	gets FOV value, when entering optics
	 **/
	proto native float GetZoomInit();

	/**
	 * @fn		GetZoomMin
	 * @brief	gets FOV minimum
	 **/
	proto native float GetZoomMin();

	/**
	 * @fn		GetZoomMax
	 * @brief	gets FOV maximum
	 **/
	proto native float GetZoomMax();

	/**
	 * @fn		GetZeroingDistanceZoomMin
	 * @brief	Gets Zeroing distance at opticsZoomMin
	 **/
	proto native float GetZeroingDistanceZoomMin();
	
	/**
	 * @fn		GetZeroingDistanceZoomMax
	 * @brief	Gets Zeroing distance at opticsZoomMax
	 **/
	proto native float GetZeroingDistanceZoomMax();


	
	/*override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		
		// could maybe just ask for energy component on item?
		if (slot_name == "BatteryD")
		{
			item.GetCompEM().SwitchOn();
		}
	}*/
	
	/*override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if (slot_name == "BatteryD")
		{
			item.GetCompEM().SwitchOff();
		}
	}*/
	
	override void OnWorkStart()
	{
		ShowReddot(true);
	}
	
	override void OnWorkStop()
	{
		ShowReddot(false);
	}
	
	bool IsWorking()
	{
		if (GetCompEM() && GetCompEM().CanWork())
			return true;
		return false;
	}
	
	void UpdateOpticsReddotVisibility()
	{
		if (IsWorking() && !m_reddot_displayed)
		{
			ShowReddot(true);
		}
		else if (!IsWorking() && m_reddot_displayed)
		{
			ShowReddot(false);
		}
	}
	
	override void OnWasAttached( EntityAI parent, int slot_id )
	{
		super.OnWasAttached(parent, slot_id);
		
		SetTakeable(false);
	}

	override void OnWasDetached( EntityAI parent, int slot_id )
	{
		super.OnWasDetached(parent, slot_id);
		
		PlayerBase player;
		if (PlayerBase.CastTo(player, GetHierarchyRootPlayer()))
		{
			player.SetReturnToOptics(false);
		}
		
		SetTakeable(true);
	}
	
	override void OnInventoryExit(Man player)
	{
		super.OnInventoryExit(player);
		
		PlayerBase playerPB;
		if (PlayerBase.CastTo(playerPB, player))
		{
			playerPB.SetReturnToOptics(false);
		}
		
		SetTakeable(true);
	}
	
	void InitReddotData()
	{
		string path = "cfgVehicles " + GetType() + " OpticsInfo";
		string temp;
		
		if (GetGame().ConfigIsExisting(path))
		{
			m_reddot_index = GetHiddenSelectionIndex("reddot");
			if (GetGame().ConfigIsExisting(path + " opticSightTexture"))
			{
				GetGame().ConfigGetText(path + " opticSightTexture", temp);
				m_optic_sight_texture = temp;
				temp = "";
			}
			if (GetGame().ConfigIsExisting(path + " opticSightMaterial"))
			{
				GetGame().ConfigGetText(path + " opticSightMaterial", temp);
				m_optic_sight_material = temp;
				temp = "";
			}
		}
		m_data_set = true;
	}
	
	void ShowReddot(bool state)
	{
		if (!m_data_set)
			InitReddotData();
		
		// does not have reddot
		if (m_reddot_index == -1)
			return;
		
		if (state)
		{
			if (m_optic_sight_texture != "")
				SetObjectTexture(m_reddot_index, m_optic_sight_texture);
			if (m_optic_sight_material != "")
				SetObjectMaterial(m_reddot_index, m_optic_sight_material);
		}
		else
		{
			SetObjectTexture(m_reddot_index, "");
			SetObjectMaterial(m_reddot_index, "");
		}
		m_reddot_displayed = state;
	}
	
	void InitOpticsPPInfo()
	{
		m_allowsDOF = InitDOFAvailability();
		InitOpticsPP(m_mask_array, m_lens_array, m_blur_float);
		
		m_isNVOptic = ConfigGetBool("NVOptic");
	}
	
	//! optics with more than 1x zoom do not allow DOF changes
	bool InitDOFAvailability()
	{
		float fov_max;
		string path = "cfgVehicles " + GetType() + " OpticsInfo";
		
		/*
		Weapon_Base weapon = Weapon_Base.Cast(GetHierarchyParent());
		if (!weapon)
			return false; // no DOF for handheld optics
		*/
		fov_max = GetGame().ConfigGetFloat(path + " opticsZoomMax");
		if (fov_max >= GameConstants.DZPLAYER_CAMERA_FOV_IRONSIGHTS)
		{
			return true;
		}
		return false;
	}
	
	//! initializes values for optics' post-processes
	void InitOpticsPP(out array<float> mask_array, out array<float> lens_array, out float blur_float)
	{
		string path = "cfgVehicles " + GetType() + " OpticsInfo";
		GetGame().ConfigGetFloatArray(path + " PPMaskProperties", mask_array);
		GetGame().ConfigGetFloatArray(path + " PPLensProperties", lens_array);
		blur_float = GetGame().ConfigGetFloat(path + " PPBlurProperties");
	}
	
	void InitCameraOverrideProperties()
	{
		string path = "cfgVehicles " + GetType() + " OpticsInfo";
		if ( GetGame().ConfigIsExisting(path + " nearPlaneDistanceOverride") )
		{
			m_nearplane_override = GetGame().ConfigGetFloat(path + " nearPlaneDistanceOverride");
		}
		else
		{
			m_nearplane_override = DayZPlayerCameraOptics.CONST_NEARPLANE_OPTICS;
		}
	}
	
	//! Initializes DOF properties for optic's alternate ironsights (ACOG etc.)
	bool InitOpticsDOFProperties (out array<float> temp_array)
	{
		if (GetGame().ConfigIsExisting("cfgVehicles " + GetType() + " OpticsInfo PPDOFProperties"))
		{
			GetGame().ConfigGetFloatArray("cfgVehicles " + GetType() + " OpticsInfo PPDOFProperties", temp_array);
			return true;
		}
		else if (GetGame().ConfigIsExisting("cfgVehicles " + GetType() + " OpticsInfoWeaponOverride PPDOFProperties"))
		{
			GetGame().ConfigGetFloatArray("cfgVehicles " + GetType() + " OpticsInfoWeaponOverride PPDOFProperties", temp_array);
			return true;
		}
		return false;
	}
	
	//! returns 'true' for non-magnifying optics
	bool AllowsDOF()
	{
		return m_allowsDOF;
	}
	
	bool IsNVOptic()
	{
		return m_isNVOptic;
	}
	
	ref array<float> GetOpticsDOF ()
	{
		return m_OpticsDOFProperties;
	}
	ref array<float> GetOpticsPPMask()
	{
		return m_mask_array;
	}
	ref array<float> GetOpticsPPLens()
	{
		return m_lens_array;
	}
	float GetOpticsPPBlur()
	{
		return m_blur_float;
	}
	
	float GetNearPlaneValue()
	{
		return m_nearplane_override;
	}
	
	void Init2DPreloadType()
	{
		string path = "cfgVehicles " + GetType() + " OpticsInfo preloadOpticType";
		string type_2d;
		
		if ( GetGame().ConfigIsExisting(path) )
		{
			GetGame().ConfigGetText(path, type_2d);
			m_2D_preload_type = type_2d;
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionViewOptics);
	}
};	

typedef ItemOptics OpticBase;


