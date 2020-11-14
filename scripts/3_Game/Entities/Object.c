class Object extends IEntity
{
	private void ~Object();
	private void Object();
	
	bool CanBeSkinned()
	{
		return false;
	}
	
	proto native void AddProxyPhysics(string proxySelectionName);	
	
	proto native void RemoveProxyPhysics(string proxySelectionName);	

	//! Retrieve all LODS	
	proto native bool GetLODS(notnull out array<LOD> lods);
	
	//! Retrieve LOD name
	proto native owned string GetLODName(LOD lod);
	
	//! Retrieve LOD by given name
	LOD GetLODByName( string name )
	{
		array<LOD> lods = new array<LOD>;
		GetLODS( lods );
		
		for ( int i = 0; i < lods.Count(); ++i )
		{
			string lod_name = GetLODName( lods.Get( i ) );
			lod_name.ToLower();
			name.ToLower();
			if ( lod_name == name ) 
			{
				return lods.Get( i );
			}
		}
		
		return NULL;
	}
	
	//! Returns the hiddenSelectionsTextures array from the object's config
	TStringArray GetHiddenSelectionsTextures()
	{
		string garden_type = this.GetType();
		TStringArray textures = new TStringArray;
		GetGame().ConfigGetTextArray( "CfgVehicles " + garden_type + " hiddenSelectionsTextures", textures );
		return textures;
	}
	
	//! Returns the hiddenSelectionsMaterials array from the object's config
	TStringArray GetHiddenSelectionsMaterials()
	{
		string garden_type = this.GetType();
		TStringArray materials = new TStringArray;
		GetGame().ConfigGetTextArray( "CfgVehicles " + garden_type + " hiddenSelectionsMaterials", materials );
		return materials;
	}
	
	//! Creates an explosion on this object by its ammoType in config.
	void Explode(int damageType, string ammoType = "")
	{
		if (ammoType == "")
			ammoType = this.ConfigGetString("ammoType");
		
		if (ammoType == "")
			ammoType = "Dummy_Heavy";
		
		if ( GetGame().IsServer() )
		{
			SynchExplosion();
			DamageSystem.ExplosionDamage(EntityAI.Cast(this), NULL, ammoType, GetPosition(), damageType);
		}
	}
	
	void SynchExplosion()
	{
		if ( GetGame().IsServer()  &&  GetGame().IsMultiplayer() ) // Multiplayer server
		{
			Param1<EntityAI> p = new Param1<EntityAI>(NULL);
			
			GetGame().RPCSingleParam( this, ERPCs.RPC_EXPLODE_EVENT, p, true);
		}
		
		if ( GetGame().IsServer()  &&  !GetGame().IsMultiplayer() ) // Singleplayer
		{
			OnExplodeClient();
		}
	}
	
	//! Called on clients when this object explodes
	void OnExplodeClient()
	{
		string ammoType = this.ConfigGetString("ammoType");
		
		if (ammoType == "")
			ammoType = "Dummy_Heavy";
		
		// Handle spawn of particle
		string particle_path = "cfgAmmo " + ammoType + " particle";
		string particle_name;
		GetGame().ConfigGetText(particle_path, particle_name);
		
		int particle_ID = ParticleList.GetParticleID(ParticleList.GetPathToParticles() + particle_name);
		
		if (particle_ID > 0)
		{
			Particle.PlayInWorld(particle_ID, GetPosition());
		}
		
		// Handle spawn of Effect, which allows more complex behavior
		string effect_path = "cfgAmmo " + ammoType + " effect";
		string effect_name;
		
		GetGame().ConfigGetText(effect_path, effect_name);
		
		typename effect_type_name = effect_name.ToType();
		
		if ( effect_type_name )
		{
			Effect eff; 
			Class.CastTo(eff, effect_type_name.Spawn());
			
			SEffectManager.PlayInWorld(eff, GetPosition() );
		}
	}
	
	void OnExplosionEffects (Object source, Object directHit, int componentIndex, string surface, vector pos, vector surfNormal, float energyFactor, float explosionFactor, bool isWater, string ammoType) { }
	
	//! returns action component name by given component index, 'geometry' can be "fire" or "view" (default "" for mixed/legacy mode)
	proto native owned string GetActionComponentName(int componentIndex, string geometry = "");
	
	//! returns action component position by given component index, 'geometry' can be "fire" or "view" (default "" for mixed/legacy mode)
	proto native owned vector GetActionComponentPosition(int componentIndex, string geometry = "");

	//! returns action component name list by given component index, 'geometry' can be "fire" or "view" (default "" for mixed/legacy mode)
	proto native owned void GetActionComponentNameList(int componentIndex, TStringArray nameList, string geometry = "");
	
	//! return true if selection containts action component, 'geometry' can be "fire" or "view" (default "" for mixed/legacy mode)
	proto native bool IsActionComponentPartOfSelection(int componentIndex, string selectionName, string geometry = "");
	
	//! Flag to determine this object is marked to be deleted soon
	proto native bool ToDelete();
	
	//! Determine whether this object is in the deletion ProcessDirectDamage
	//! Is useful in the case where a parent is being deleted, since the children will be deleted first
	//! So to know if something was removed or detached from it's parent, use this check to see if it is because the parent is being deleted
	proto native bool IsPendingDeletion();
	
	//! Retrieve position
	proto native vector GetPosition();

	//! Returns world position.
	//! This function takes proxy transformation into account.
	proto native vector GetWorldPosition();
	
	//! Set position
	proto native void SetPosition(vector vPos);
	
	/**
	\brief Place object on surface
	*/
	proto native void PlaceOnSurface();

	/**
	\brief Retrieve orientation (yaw, pitch, roll) in <b>degrees</b>
	\return vector of yaw, pitch and roll angles (x = yaw, y = pitch, z = roll)
	*/
	proto native vector GetOrientation();

	/**
	\brief Set orientation (yaw, pitch, roll) in <b>degrees</b>
	@param vOrientation, vector of yaw, pitch and roll angles (x = yaw, y = pitch, z = roll)
	*/
	proto native void SetOrientation(vector vOrientation);
	
	//! Retrieve direction vector
	proto native vector GetDirection();
	
	/**
	\brief Set direction of object
	@param vDirection, direction vector
	\note object up vector is always y-axis
	*/
	proto native void SetDirection(vector vPos);
	
	//! Calculate local position of other entity to this entity
	proto native vector GetLocalPos(vector vPos);
	//! Calculate global position to this entity from local position
	proto native vector GetGlobalPos(vector vPos);
	
	//! Retrieve object's speed in global space
	proto native vector GetSpeed();
	
	//! Retrieve object's speed in local space
	proto native vector GetModelSpeed();
	
	//! Returns true if object's geometry can affect pathgraph generation
	proto native bool CanAffectPathgraph();
	
	//! Sets if object's geometry affects pathgraph generation. If first parameter is true, it ignores second parameter and sets affecting pathgraph by parameter set in object's config
	proto native void SetAffectPathgraph(bool fromConfig, bool affect);
	

	/**
	\brief Get Clipping info
	@param minMax array[2] of vectors, into minMax[0] is returned min, into minMax[1] is returned max
	\return radius of bounding box
	@code
	vector minMax[2];
	float radius = GetGame().GetPlayer().ClippingInfo(minMax);
	Print(minMax);
	Print(radius);
	@endcode
	*/
	proto float ClippingInfo(out vector minMax[2]);
	
	/** 
	\brief Gets collision bounding box
	@param minMax array[2] of vectors, into minMax[0] is returned min, into minMax[1] is returned max
	\return true if collision box exists, false otherwise
	@code
	vector minMax[2];
	if(GetGame().GetPlayer().GetCollisionBox(minMax))
		Print("has box");
	@endcode
	*/
	proto native bool GetCollisionBox(out vector minMax[2]);
	
	//! Get total damage (clipped to range 0..1)
	proto native float GetDamage();

	
	proto native void GetSelectionList(out TStringArray selectionList);
	
	//! Returns noise multiplier of surface under object
	float GetSurfaceNoise()
	{
		vector position = GetPosition();
		return GetGame().SurfaceGetNoiseMultiplier(NULL, position, -1);
	}
	
	//! Returns type of surface under object
	string GetSurfaceType()
	{
		string surface_type;
		int liquid_type;
		
		GetGame().SurfaceUnderObject(this, surface_type,liquid_type);
//		Print(surface_type);
//		Print(liquid_type);
		
		return surface_type;
	}

	//! Returns true if the given selection was found in the p3d file. False if otherwise.
	bool HasSelection( string selection )
	{
		TStringArray selections = new TStringArray;
		GetSelectionList( selections );
		
		for ( int i = 0; i < selections.Count(); ++i )
		{
			if ( selections.Get( i ) == selection )
			{
				return true;
			}
		}
		
		return false;
	}
	
	//! Searches object's config for the given animation name. Returns true if it was found, or false if not.
	bool HasAnimation( string anim_name )
	{
		string cfg_path_vehicles = "CfgVehicles " + GetType() + " ";
		if ( GetGame().ConfigIsExisting (cfg_path_vehicles)  &&  GetGame().ConfigIsExisting (cfg_path_vehicles + "AnimationSources " + anim_name) )
		{
			return true;
		}
		
		string cfg_path_weapons = "CfgWeapons " + GetType() + " ";
		if ( GetGame().ConfigIsExisting (cfg_path_weapons)  &&  GetGame().ConfigIsExisting (cfg_path_weapons + "AnimationSources " + anim_name) )
		{
			return true;
		}
		
		string cfg_path_magazines = "CfgMagazines " + GetType() + " ";
		if ( GetGame().ConfigIsExisting (cfg_path_magazines)  &&  GetGame().ConfigIsExisting (cfg_path_magazines + "AnimationSources " + anim_name) )
		{
			return true;
		}
		
		return false;
	}
	
	//! If Returns true if this item has EnergyManager in its config. Otherwise returns false.
	/*bool HasEnergyManager()
	{
		return false;
	}*/
	
	proto native int GetMemoryPointIndex(string memoryPointName);
	proto native vector GetMemoryPointPos(string memoryPointName);
	proto native vector GetMemoryPointPosByIndex(int pointIndex);
	proto native bool MemoryPointExists(string memoryPoint);
	
	proto native void CreateDynamicPhysics(PhxInteractionLayers layer);
	proto native void EnableDynamicCCD(bool state);
	proto native void SetDynamicPhysicsLifeTime(float lifeTime);

	//! Called when tree is chopped down. 'cutting_entity' can be tool, or player, if cutting bush with bare hands
	void OnTreeCutDown( EntityAI cutting_entity )
	{
		
	}
	
	//! Get config class of object
	string GetType()
	{
		string ret;
		GetGame().ObjectGetType(this, ret);
	
		return ret;
	}
	
	//! Get display name of entity
	string GetDisplayName()
//	string GetName()
	{
		string tmp;
		if (NameOverride(tmp))
		{
			tmp = Widget.TranslateString(tmp);
			//tmp.ToUpper();
		}
		else
		{
			GetGame().ObjectGetDisplayName(this, tmp);
		}
		return tmp;
	}
	
	//! Returns name of the model of this object without the '.p3d' suffix
	string GetModelName()
	{
		return GetGame().GetModelName(GetType());
	}


	int Release()
	{
		return GetGame().ObjectRelease(this);
	}
	
	//! Check config class name of the object
	bool IsKindOf(string type)
	{
		return GetGame().ObjectIsKindOf(this, type);
	}
		
	// Check alive state
	bool IsAlive()
	{
		if ( IsDamageDestroyed() ) 
		{
			return false; // Is dead
		}
		
		return true; // Is alive
	}

		
	//! Returns if this entity is Man
	bool IsMan()
	{
		return false;
	}
	
	//! Returns if this entity is EntityAI
	bool IsEntityAI()
	{
		return false;
	}
	
	//! Returns if this entity is Static Transmitter
	bool IsStaticTransmitter()
	{
		return false;
	}
	
	//! Returns if this entity is a non-static Transmitter
	bool IsTransmitter()
	{
		return false;
	}
	
	//! Returns if this entity is ItemBase
	bool IsItemBase()
	{
		return false;
	}
	
	bool IsContainer()
	{
		return false;
	}
	
	//! Returns if this entity is Magazine
	bool IsMagazine()
	{
		return false;
	}
	
	//! Returns if this entity is Ammo Pile
	bool IsAmmoPile()
	{
		return false;
	}
	
	//! Returns if this entity is InventoryItem
	bool IsInventoryItem()
	{
		return false;
	}

	//! Returns if this entity is Clothing
	bool IsClothing()
	{
		return false;
	}

	//! Returns if this entity is fireplacebase
	bool IsFireplace()
	{	
		return false;
	}
	
	//! Returns if this entity is tree
	bool IsTree()
	{	
		return false;
	}
	
	//! Returns if this entity is rock
	bool IsRock()
	{	
		return false;
	}
	
	//! Returns whether object is PlanBase
	bool IsWoodBase()
	{
		return false;
	}

	//! Returns if this entity is bush
	bool IsBush()
	{
		return false;
	}
	
	bool IsCuttable()
	{
		return false;
	}
	
	//! Returns if this entity is Pelt_Base
	bool IsPeltBase()
	{
		return false;
	}

	//! Returns if this entity is Weapon
	bool IsWeapon()
	{
		return false;
	}
	
	//! returns if this entity is Melee Weapon
	bool IsMeleeWeapon()
	{
		return false;
	}
	
	//! Returns if this entity is Building
	bool IsBuilding()
	{
		return false;
	}
	
	//! Returns if this entity is Well (extends Building)
	bool IsWell()
	{
		return false;
	}
	
	//! Returns if this entity is Fuel Station (extends Building)
	bool IsFuelStation()
	{
		return false;
	}
	
	//! Returns if this entity is transport
	bool IsTransport()
	{
		return false;
	}
	
	//! Returns if this is an appliance, that can be plugged into electric circuit (== not energy source)
	bool IsElectricAppliance()
	{
		return false;
	}
	
	//! Returns if this entity can be constucted,deconstructed (e.g. fence,watchtower)
	bool CanUseConstruction()
	{
		return false;
	}
	
	//! Returns if this entity can be built, specifically.
	bool CanUseConstructionBuild()
	{
		return false;
	}
	
	//! Returns if this entity can be constructed without tools
	bool CanUseHandConstruction()
	{
		return false;
	}
	
	//! Returns if this entity if a food item
	bool IsFood()
	{
		return ( IsFruit() || IsMeat() || IsMushroom() );
	}
	
	bool IsFruit()
	{
		return false;
	}
	
	bool IsMeat()
	{
		return false;
	}
	
	bool IsMushroom()
	{
		return false;
	}	

	//! Returns if the health of this entity should be displayed (widgets, inventory)
	bool IsHealthVisible()
	{
		return true;
	}
	
	//! Returns true if the health of damage zones should be displayed (instead of global HP of the entity) ( action widgets)
	bool ShowZonesHealth()
	{
		return false;
	}

	bool IsParticle()
	{
		return false;
	}
	
	bool IsItemTent()
	{
		return false;
	}
	
	bool IsScriptedLight()
	{
		return false;
	}
		
	bool HasProxyParts()
	{
		return false;
	}
	
	//! Disables icon in the vicinity, useful for large, immovable items, that are not buildings
	bool DisableVicinityIcon()
	{
		return false;
	}

	//! Returns low and high bits of networkID.
	//! This id is shared between client and server for whole server-client session.
	proto void GetNetworkID( out int lowBits, out int highBits );
	
	string GetNetworkIDString()
	{
		int low, high;
		GetNetworkID( low, high );
		return high.ToString() + low.ToString();
	}
	
	static string GetDebugName(Object o)
	{
		if (o)
			return o.GetType() + ":" + o.GetNetworkIDString();
		return "null";
	}
	
	//! Remote procedure call shortcut, see CGame.RPC / CGame.RPCSingleParam
	void RPC(int rpc_type, array<ref Param> params, bool guaranteed, PlayerIdentity recipient = NULL)
	{
		GetGame().RPC(this, rpc_type, params, guaranteed, recipient);
	}
	
	//! Remote procedure call shortcut, see CGame.RPCSingleParam / CGame.RPC
	void RPCSingleParam(int rpc_type, Param param, bool guaranteed, PlayerIdentity recipient = NULL)
	{
		GetGame().RPCSingleParam(this, rpc_type, param, guaranteed, recipient);
	}
	
	/**
  \brief Called after remote procedure call is recieved for this object
		@param rpc_type user defined identification of RPC
		@param ctx read context for params
	*/
	void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx);

	vector GetSelectionPositionOld(string name)
	{
		return GetGame().ObjectGetSelectionPosition(this, name);
	}
	
	vector GetSelectionPositionLS(string name)
	{
		return GetGame().ObjectGetSelectionPositionLS(this, name);
	}
	
	vector GetSelectionPositionMS(string name)
	{
		return GetGame().ObjectGetSelectionPositionMS(this, name);
	}
	
	vector GetSelectionPositionWS(string name)
	{
		return GetGame().ObjectGetSelectionPositionWS(this, name);
	}

	
	vector ModelToWorld(vector modelPos)
	{
		return GetGame().ObjectModelToWorld(this, modelPos);
	}
	
	vector WorldToModel(vector worldPos)
	{
		return GetGame().ObjectWorldToModel(this, worldPos);
	}

	// config class API	
	
	proto string ConfigGetString(string entryName);
	proto int ConfigGetInt(string entryName);
	bool ConfigGetBool(string entryName)
	{
		if ( ConfigGetInt(entryName) == 1 )
		{
			return true;
		}
		
		return false;
	}

	proto float ConfigGetFloat(string entryName);
	proto vector ConfigGetVector(string entryName);
	//proto ParamEntry ConfigGetEntry(string entryName);

	/**
  \brief Get array of strings from config entry.
	@param entryName 
	@param value output
	*/
	proto native void		ConfigGetTextArray(string entryName, out TStringArray values);

	/**
  \brief Get array of floats from config entry.
	@param entryName 
	@param value output
	*/
	proto native void		ConfigGetFloatArray(string entryName, out TFloatArray values);
	
	/**
  \brief Get array of integers from config entry.
	@param entryName 
	@param value output
	*/
	proto native void		ConfigGetIntArray(string entryName, out TIntArray values);

	/**
  \brief Checks if given entry exists.
	@param entryName 
	*/
	proto native bool		ConfigIsExisting(string entryName);
	
	//! Compares config class name to given string
	bool KindOf( string tag )
	{
		bool found = false;
		string item_name = this.GetType();	
		TStringArray item_tag_array = new TStringArray;
		ConfigGetTextArray("cfgVehicles " + item_name + " itemInfo", item_tag_array);	
		
		int array_size = item_tag_array.Count();
		for (int i = 0; i < array_size; i++)
		{
			if ( item_tag_array.Get(i) == tag )
			{
				found = true;
				break;
			}
		}
		return found;
	}
	
	bool IsAnyInherited( array<typename> typenames )
	{
		bool ret;
		for( int i = 0; i < typenames.Count(); i++ )
		{
			ret = ret || this.IsInherited( typenames.Get(i) );
		}
		return ret;
	}
	
	// Damage system
	/**
  \brief Checks if object is destroyed.
	*/
	proto native bool   IsDamageDestroyed();
	
	/**
	\brief Sets the time over which to perform DestructTent/DestructTree
	@param time time over which to perform DestructTent/DestructTree
	*/
	proto native void  SetDestructTime(float time);
	
	/**
	\brief Returns current state of health.
	@param zoneName if empty string, returns state of global health
	@param healthType if empty string, returns state of main health
	*/
	proto native float  GetHealth(string zoneName, string healthType);
	
	/**
	\brief Returns current state of health in range <0, 1>.
	@param zoneName if empty string, returns state of global health
	@param healthType if empty string, returns state of main health
	*/
	proto native float  GetHealth01(string zoneName, string healthType);
	
	/**
  \brief Returns maximum value of health.
	@param zoneName if empty string, returns state of global health
	@param healthType if empty string, returns state of main health
	*/
	proto native float  GetMaxHealth(string zoneName, string healthType);
	
	/**
  \brief Sets current state of health.
	@param zoneName if empty string, sets state of global health
	@param healthType if empty string, sets state of main health
	*/
	proto native void   SetHealth(string zoneName, string healthType, float value);
	
	/**
  \brief Adds health.
	@param zoneName if empty string, sets state of global health
	@param healthType if empty string, sets state of main health
	*/
	proto native void   AddHealth(string zoneName, string healthType, float value);

	/**
  \brief Decreases health.
	@param zoneName if empty string, sets state of global health
	@param healthType if empty string, sets state of main health
	*/
	proto native void   DecreaseHealth(string zoneName, string healthType, float value);
	
	/**
  \brief Decreases health with the option of auto-deleting the object if its ruined.
	@param zoneName if empty string, sets state of global health
	@param healthType if empty string, sets state of main health
	*/
	void   DecreaseHealth(string zoneName, string healthType, float value, bool auto_delete)
	{
		DecreaseHealth( zoneName, healthType, value);
		
		float result_health = GetHealth(zoneName, healthType);
		
		if ( auto_delete  &&  result_health <= 0 )
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(GetGame().ObjectDelete, this); 
		}
	}
	
	//! Equivalent of GetHealth("", "");
	float GetHealth()
	{
		return GetHealth("", "");
	}
	//! Equivalent of GetHealth01("", "");
	float GetHealth01()
	{
		return GetHealth01("", "");
	}
	//! Equivalent of GetMaxHealth("", "");
	float GetMaxHealth()
	{
		return GetMaxHealth("", "");
	}
	//! Equivalent of SetHealth("", "", float value);
	void SetHealth(float health)
	{
		SetHealth("", "", health);
	}
	//! Sets health relative to its maximum
	void SetHealth01(string zoneName, string healthType, float coef)
	{
		SetHealth(zoneName,healthType,(GetMaxHealth(zoneName,healthType)*coef));
	}
	//! Sets health to its maximum (zone or global)
	void SetHealthMax(string zoneName = "", string healthType = "")
	{
		SetHealth(zoneName,healthType,GetMaxHealth(zoneName,healthType));
	}
	//! Equivalent of AddHealth("", "", float value);
	void AddHealth( float add_health)
	{
		AddHealth("", "", add_health);
	}
	//! Equivalent of DecreaseHealth("", "", float value, bool auto_delete);
	void DecreaseHealth(float dec_health, bool auto_delete = true)
	{
		DecreaseHealth("", "", dec_health, auto_delete);
	}
	//! Decreases health by the given coeficient.
	void DecreaseHealthCoef(float dec_health_coef, bool auto_delete = true)
	{
		float current_health = GetHealth();
		float final_health_coef = GetHealth01() - dec_health_coef;
		float final_health = GetMaxHealth() * final_health_coef;		
		DecreaseHealth("", "", current_health - final_health);
	}

	/**
  \brief Applies damage on object.
	@param damageType DT_CLOSE_COMBAT/DT_FIRE_ARM/DT_EXPLOSION/DT_CUSTOM
	@param source source of damage
	@param compomentName which component was hit
	@param ammoName ammoType, which defines how much damage should be applied
	@param directHitModelPos local position of hit
	@param damageCoef multiplier of applied damage
	*/
	proto native void ProcessDirectDamage(int damageType, EntityAI source, string componentName, string ammoName, vector modelPos, float damageCoef = 1.0);
	
	/**
  \brief Obtains a list of nammes of all object's damage zones
	@param list of names
	*/
	proto native void GetDamageZones(out TStringArray dmgZones);
	
	/**
  \brief Obtains middle position of damage zone based on it's name
	@param name of the damage zone
	*/
	proto native vector GetDamageZonePos(string zoneName);
	/**
  \brief Obtains name of damage zone based on index of specific component
	@param index of the component
	*/
	proto native owned string GetDamageZoneNameByComponentIndex(int componentIndex);
	
	/**
  \brief Is this just static object without config? So we can avoid calling unnecessary methods
	*/
	proto native bool IsPlainObject();
	
	/**
  	\brief Returns global health level specified in object's config class parameter healthLevels
	     (range is usually 0..4, 0 = pristine, 1 = worn, 2 = damaged, 3 = badly damaged, 4 = ruined but can be changed).
	@param zoneName if empty string, returns state of global health level
	*/
	proto native int GetHealthLevel(string zone = "");
	
	/**
  	\brief Returns global number of health levels specified in object's config class parameter healthLevels
	     (range is usually 0..4, 0 = pristine, 1 = worn, 2 = damaged, 3 = badly damaged, 4 = ruined but can be changed).
	@param zoneName if empty string, returns number of global health levels
	*/
	proto native int GetNumberOfHealthLevels(string zone = "");
	
	/**
  	\brief Returns cutoff value for health level specified in object's config class parameter healthLevels
	@param zoneName if empty string, returns number of global health levels
	@param healthLevel the health level to get the value from
	*/
	proto native float GetHealthLevelValue(int healthLevel, string zone = "");
	
	/**
  \brief Enable or disable object to receive damage
	@param enable or disable
	*/
	proto native void SetAllowDamage(bool val);
	
	/**
	\brief Returns if object is destroyable
	*/
	proto native bool GetCanBeDestroyed();
	
	/**
	\brief Enable or disable destruction of object (after health is depleated)
	@param enable or disable
	*/
	proto native void SetCanBeDestroyed(bool val);
	
	/**
	\brief Returns whether the object is ruined (0 Health).
	\return \p bool true = item has 0 Health or less
	@code
		if ( item.IsRuined() )
		{
			Print("Object is ruined!");
		}
	@endcode
	*/
	bool IsRuined()
	{
		if ( IsDamageDestroyed() )
		{
			return true;
		}
		
		return false;
	}

	void GetActions(typename action_input_type, out array<ActionBase_Basic> actions)
	{
	}

	//! Plays the given sound once on this object's instance. Range is in meters. Created sound is only local, unless create_local is set to false. Returns the sound itself.
	SoundOnVehicle PlaySound(string sound_name, float range, bool create_local = true)
	{
		return GetGame().CreateSoundOnObject(this, sound_name, range, false, create_local);
	}
	
	//! Plays the given sound in loop on this object's instance. Range is in meters. Created sound is only local, unless create_local is set to false. Returns the sound itself.
	SoundOnVehicle PlaySoundLoop(string sound_name, float range, bool create_local = true)
	{
		return GetGame().CreateSoundOnObject(this, sound_name, range, true, create_local);
	}
	
	//! EffectSound - plays soundset on this object and returns state of the sound (true - played, false - not played)
	bool PlaySoundSet( out EffectSound sound, string sound_set, float fade_in, float fade_out, bool loop = false )
	{
		if ( GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			if ( sound )
			{
				if ( loop )
				{
					return true;
				}
				else
				{
					StopSoundSet( sound );		//auto stop for non-looped sounds
				}
			}
			
			sound = SEffectManager.PlaySoundOnObject( sound_set, this, fade_in, fade_out, loop );
			sound.SetSoundAutodestroy( true );
			
			return true;
		}
		
		return false;
	}	

	//! EffectSound - plays soundset on this object in loop and returns state of the sound (true - played, false - not played)
	bool PlaySoundSetLoop( out EffectSound sound, string sound_set, float fade_in, float fade_out )
	{
		return PlaySoundSet( sound, sound_set, fade_in, fade_out, true );
	}
	
	//! EffectSound - stops soundset and returns state of the sound (true - stopped, false - not playing)
	bool StopSoundSet( out EffectSound sound )
	{
		if ( sound && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			sound.SoundStop();
			sound = NULL;
			
			return true;
		}
		
		return false;
	}
	
	void PostAreaDamageActions() {}
	void PreAreaDamageActions() {}
	
	
	void SpawnDamageDealtEffect() { }
	void OnPlayerRecievedHit(){}
	
	bool HasNetworkID()
	{
		int lo = 0;
		int hi = 0;
		GetNetworkID(lo, hi);
		return lo | hi;
	}
	
	bool NameOverride(out string output)
	{
		return false;
	}
	
	bool DescriptionOverride(out string output)
	{
		return false;
	}
	
	EntityAI ProcessMeleeItemDamage(int mode = 0) {}
	
	bool CanBeRepairedToPristine()
	{
		return false;
	}
	
	//Debug
	//----------------------------------------------
	/*void DbgAddPxyPhy(string slot)
	{
		Print("AddProxyPhysics slot: " + slot);
		AddProxyPhysics(slot);
	}*/
};