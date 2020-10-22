class TotalDamageResult: Managed
{
	proto native float GetDamage(string zoneName, string healthType);
	proto native float GetHighestDamage(string healthType);
};

//-----------------------------------------------------------------------------
class DamageSystem
{
	static proto native void CloseCombatDamage(EntityAI source, Object targetObject, int targetComponentIndex, string ammoTypeName, vector worldPos);
	static proto native void CloseCombatDamageName(EntityAI source, Object targetObject, string targetComponentName, string ammoTypeName, vector worldPos);

	static proto native void ExplosionDamage(EntityAI source, Object directHitObject, string ammoTypeName, vector worldPos, int damageType);
	
	static bool GetDamageZoneMap(EntityAI entity, out DamageZoneMap zoneMap)
	{
		string path_base;
		string path;
		
		if(entity.IsWeapon())
		{
			path_base = CFG_WEAPONSPATH;
		}
		else if(entity.IsMagazine())
		{
			path_base = CFG_MAGAZINESPATH;
		}
		else
		{
			path_base = CFG_VEHICLESPATH;
		}
		path_base = "" + path_base + " " + entity.GetType() + " DamageSystem DamageZones";
		
		if (!GetGame().ConfigIsExisting(path_base))
		{
			return false;
		}
		else
		{
			string zone;
			ref array<string> zone_names = new array<string>;
			ref array<string> component_names;
			
			entity.GetDamageZones(zone_names);
			for(int i = 0; i < zone_names.Count(); i++)
			{
				component_names = new array<string>;
				zone = zone_names.Get(i);
				path = "" + path_base + " " + zone + " componentNames";
				if(GetGame().ConfigIsExisting(path))
				{
					GetGame().ConfigGetTextArray(path,component_names);
				}
				zoneMap.Insert(zone,component_names);
			}
			
			return true;
		}
	}
	
	//! Returns damage zone to which the named component belongs
	static bool  GetDamageZoneFromComponentName(notnull EntityAI entity, string component, out string damageZone)
	{
		DamageZoneMap zoneMap = entity.GetEntityDamageZoneMap();
		array<array<string>> components;
		components = zoneMap.GetValueArray();
		for(int i = 0; i < components.Count(); i++)
		{
			array<string> inner = components.Get(i);
			for(int j = 0; j < inner.Count(); j++)
			{
				string innerComponentName = inner.Get(j);
				innerComponentName.ToLower();

				if (innerComponentName == component)
				{
					damageZone = zoneMap.GetKey(i);
					return true;
				}
			}
		}
		damageZone = "";
		return false;
	}
	
	static bool GetComponentNamesFromDamageZone(notnull EntityAI entity, string damageZone, out array<string> componentNames)
	{
		string path;
		
		if(entity.IsWeapon())
		{
			path = CFG_WEAPONSPATH;
		}
		else if(entity.IsMagazine())
		{
			path = CFG_MAGAZINESPATH;
		}
		else
		{
			path = CFG_VEHICLESPATH;
		}
		
		path = "" + path + " " + entity.GetType() + " DamageSystem DamageZones " + damageZone + " componentNames";
		if(GetGame().ConfigIsExisting(path))
		{
			GetGame().ConfigGetTextArray(path,componentNames);
			return true;
		}
		
		return false;
	}
}

typedef map<string,ref array<string>> DamageZoneMap;