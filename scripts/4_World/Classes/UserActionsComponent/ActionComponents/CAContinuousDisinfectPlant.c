class CAContinuousDisinfectPlant : CAContinuousQuantity
{
	protected float m_PlantNeededSpraying;
	protected float	m_TimeToComplete;
	protected float m_SpentQuantityTotal;
	protected float m_StartQuantity;

	void CAContinuousDisinfectPlant( float quantity_used_per_second )
	{
		m_QuantityUsedPerSecond = quantity_used_per_second;
	}
	
	override void Setup( ActionData action_data )
	{
		PlantBase target_PB;
		if (Class.CastTo(target_PB, action_data.m_Target.GetObject()))
		{
			m_SpentQuantity = 0;
			m_StartQuantity = action_data.m_MainItem.GetQuantity();
			if ( !m_SpentUnits )
			{ 
				m_SpentUnits = new Param1<float>(0);
			}
			else
			{	
				m_SpentUnits.param1 = 0;
			}
			if ( action_data.m_MainItem )
			{
				m_ItemQuantity = action_data.m_MainItem.GetQuantity();
			}
			if ( target_PB ) 
			{
				m_PlantNeededSpraying = target_PB.GetSprayUsage() - target_PB.GetSprayQuantity();
			}

			m_TimeToComplete = (Math.Min(m_PlantNeededSpraying,m_ItemQuantity))/m_QuantityUsedPerSecond;
		}
	}
	
	override int Execute( ActionData action_data  )
	{
		Object targetObject = action_data.m_Target.GetObject();
		
		if ( !action_data.m_Player )
		{
			return UA_ERROR;
		}
		
		if ( m_ItemQuantity <= 0 )
		{
			return UA_FINISHED;
		}
		else
		{
			if ( m_SpentQuantity < m_ItemQuantity  &&  m_SpentQuantity < m_PlantNeededSpraying )
			{
				m_SpentQuantity += m_QuantityUsedPerSecond * action_data.m_Player.GetDeltaT();
				float transfered_spray = action_data.m_Player.GetSoftSkillsManager().AddSpecialtyBonus( m_SpentQuantity, m_Action.GetSpecialtyWeight(), true );
				
				m_SpentQuantityTotal += m_SpentQuantity;
				
				if ( m_Action ) 
				{
					PlantBase plant;
					Class.CastTo(plant,  targetObject );
					plant.SprayPlant(transfered_spray);
					//m_Action.SendMessageToClient(action_data.m_Player, plant.StopInfestation( transfered_spray ));
				}
				
				CalcAndSetQuantity( action_data );
				
				return UA_PROCESSING;
			}
			else
			{
				CalcAndSetQuantity( action_data );
				OnCompletePogress(action_data);
				return UA_FINISHED;
			}
		}
	}
	
	override float GetProgress()
	{	
		//return (m_SpentQuantity*m_QuantityUsedPerSecond)/m_TimeToComplete;
		return -(m_SpentQuantityTotal / m_StartQuantity);
	}
};