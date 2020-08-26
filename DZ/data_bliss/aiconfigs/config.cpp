#define _ARMA_

class CfgPatches
{
	class DZ_data_aiconfigs_bliss{};
};
class GroupBehaviourTemplates
{
	class BlissBearGroupBeh
	{
		type = "Bear";
		agentPathLength = 20.0;
		simpleLodGroupSpeed = 1.0;
		singleAgentSafeKeeperDelayMin = 30.0;
		singleAgentSafeKeeperDelayMax = 50.0;
		safeKeeperIntervalMin = 30.0;
		safeKeeperIntervalMax = 50.0;
		class LifeCycleDayTime
		{
			class Activity1
			{
				endTimeMin = 8.0;
				endTimeMax = 9.0;
				zoneType = "Graze";
			};
			class Activity2
			{
				endTimeMin = 10.0;
				endTimeMax = 11.0;
				zoneType = "Graze";
			};
			class Activity3
			{
				endTimeMin = 13.0;
				endTimeMax = 14.0;
				zoneType = "Graze";
			};
			class Activity4
			{
				endTimeMin = 17.0;
				endTimeMax = 18.0;
				zoneType = "Graze";
			};
			class Activity5
			{
				endTimeMin = 20.0;
				endTimeMax = 21.0;
				zoneType = "Graze";
			};
		};
	};
};
