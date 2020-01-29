class ChemicalAgent extends AgentBase
{
	override void Init()
	{
		m_Type 					= eAgents.CHEMICAL_POISON;
		m_Invasibility 			= 1;
		m_TransferabilityIn		= 1;
		m_TransferabilityOut	= 0;
		m_AntibioticsResistance = 1;
		m_MaxCount 				= 1000;
		m_Potency 				= EStatLevels.HIGH;
		m_DieOffSpeed 			= 1;
	}
}