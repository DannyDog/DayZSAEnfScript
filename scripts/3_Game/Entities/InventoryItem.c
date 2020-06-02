class InventoryItem extends EntityAI
{	
	private string m_SoundImpactType;
	static private const float SOUND_CONTACT_SKIP = 0.33;//second
	private float m_SoundContactTickTime;

	proto native InventoryItemType GetInventoryItemType();

	//! Some inventoryItem devices can be switched on/off (radios, transmitters)
	proto native void SwitchOn(bool onOff);
	//! Some inventoryItem devices can be switched on/off (radios, transmitters)
	proto native bool IsOn();
	
	//! collisions with character
	proto native void EnableCollisionsWithCharacter(bool state);
	proto native bool HasCollisionsWithCharacter();

	proto native MeleeCombatData GetMeleeCombatData();	
	
	proto native void ThrowPhysically(DayZPlayer player, vector force);
	
	
	void InventoryItem()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			PreLoadSoundImpactType();
		}
	}
	
	
	void OnRightClick()
	{
	
	}

	event bool OnUseFromInventory(Man owner)
	{
		return false;
	}

	//! Get tooltip text
	string GetTooltip()
	{
		string temp;
		if (!DescriptionOverride(temp))
			temp = ConfigGetString("descriptionShort");
		return temp;
	}

	override bool IsInventoryItem()
	{
		return true;
	}
	
	int GetMeleeMode()
	{
		return 0;
	}

	int GetMeleeHeavyMode()
	{
		return 1;
	}	
	
	int GetMeleeSprintMode()
	{
		return 2;
	}
	
	override bool IsMeleeWeapon()
	{
		if (ConfigIsExisting("isMeleeWeapon"))
			return ConfigGetBool("isMeleeWeapon");
		else
			return false; // TODO: allowed for everything that is not disabled in config (primarily for anim testing)
	}
	
	bool IsMeleeFinisher()
	{
		return false;
	}
	
	// -------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------
	protected void PreLoadSoundImpactType()
	{
		string impactType = "default";

		if( ConfigIsExisting("soundImpactType") )
		{
			impactType = ConfigGetString("soundImpactType");
		}
		
		m_SoundImpactType = impactType;
	}
	
	string GetSoundImpactType()
	{	
		return m_SoundImpactType;
	}
	
	// -------------------------------------------------------------------------------
	AbstractWave PlaySound(SoundObject so, SoundObjectBuilder sob)
	{
		if (so == NULL)
		{
			//Print("PlaySound: NULL argument");
			return NULL;
		}

		so.SetPosition(GetPosition());
		AbstractWave wave = GetGame().GetSoundScene().Play3D(so, sob);
		return wave;
	}
	
	string GetImpactSurfaceType(IEntity other, Contact impact)
	{
		string surface;
		if(DayZPhysics.GetHitSurface(
			Object.Cast(other),
			impact.Position + impact.RelativeVelocityBefore * 5,
			impact.Position - impact.RelativeVelocityBefore * 5,
			surface))
		{
			return surface;
		}
		else
		{
			int liquid;
			GetGame().SurfaceUnderObject(this, surface, liquid);
			return surface;
		}
	}

	// -------------------------------------------------------------------------------
/*	override void EOnContact(IEntity other, Contact extra)
	{
		if( GetGame().IsMultiplayer() && GetGame().IsServer() )
			return;
		
		float tickTime = GetGame().GetTickTime();
		if(m_SoundContactTickTime + SOUND_CONTACT_SKIP > tickTime)
			return;
		
		float impactVelocity = extra.RelativeVelocityBefore.Length();
		if(impactVelocity < 0.3)
            return;
		
        if(impactVelocity > 1.0)
            impactVelocity = 1;
		else if(impactVelocity < 0.5)
			impactVelocity = 0.5;

		string tableName = GetSoundImpactType() + "_Impact_LookupTable";
		SoundLookupTable table = AnimSoundLookupTableBank.GetInstance().GetImpactTable(tableName);
		if(table != NULL)
		{
			string surfaceName = GetImpactSurfaceType(other, extra);
			float weight = ConfigGetFloat("weight");
			//Print("[lukasikjak] surface: " + surfaceName + " speed: " + impactVelocity + " weight: " + weight);
			if(surfaceName != "")
			{
				SoundObjectBuilder soundBuilder = table.GetSoundBuilder(surfaceName.Hash());
				if (soundBuilder != NULL)
				{
					soundBuilder.SetVariable("weight", weight);
					soundBuilder.SetVariable("speed", extra.RelativeVelocityBefore.Length());
					soundBuilder.UpdateEnvSoundControllers(GetPosition());
					
					SoundObject soundObject = soundBuilder.BuildSoundObject();
					if (soundObject != NULL)
					{
						soundObject.SetKind(WaveKind.WAVEEFFECTEX);
						PlaySound(soundObject, soundBuilder);
					}
				}
			}
		}

		m_SoundContactTickTime = tickTime;
	}*/
};