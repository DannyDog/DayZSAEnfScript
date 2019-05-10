class AIWorld : Managed
{
	private void AIWorld();
	private void ~AIWorld();

	/*!
	Creates group with group behaviour specified by templateName param.
	AIGroups lifetime is managed by AIWorld, e.g. empty groups are deleted automatically.
	*/
	proto native AIGroup CreateGroup(string templateName);
	/*!
	Creates group with no group behaviour
	*/
	proto native AIGroup CreateDefaultGroup();
	/*!
	Destroys group and all AIAgents attached
	*/
	proto native void DeleteGroup(notnull AIGroup group);
	
	/*!
	Finds closest point on navmesh within maxDistance radius using default navmesh filter. 
	Default navmesh filter excludes polygons that are marked UNREACHABLE, DISABLED, SPECIAL, SWIM, SWIM_SEA.
	/param 	[in]	position 			position wanted
	/param 	[in] 	maxDistance 		search radius
	/param 	[out] 	sampledPosition		closest position on navmesh to position
	/returns	true - function succeedes and found position is written to output paramter "sampledPosition"
	/returns	false - function failed to find position on navmesh within given radius, output paramter is left intact
	*/
	proto native bool SampleNavmeshPosition(vector position, float maxDistance, out vector sampledPosition);
}