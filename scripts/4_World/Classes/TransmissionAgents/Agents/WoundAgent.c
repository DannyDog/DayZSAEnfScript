class WoundAgent extends AgentBase
{
	override void Init()
	{
		m_Type 					= eAgents.WOUND_AGENT;
		m_Invasibility 			= 0.5;
		m_TransferabilityIn		= 1;
		m_TransferabilityOut	= 0.1;
		m_AntibioticsResistance = 0.5;
		m_MaxCount 				= 1000;
		m_Potency 				= EStatLevels.HIGH;
		m_DieOffSpeed 			= 1;
	}
}