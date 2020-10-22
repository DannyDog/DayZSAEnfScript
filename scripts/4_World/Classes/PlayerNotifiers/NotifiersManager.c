enum eNotifiers
{
	NTF_HEALTHY,
	NTF_BLEEDISH,
	NTF_HUNGRY,
	NTF_THIRSTY,
	NTF_STUFFED,
	NTF_SICK,
	NTF_WETNESS,
	NTF_WARMTH,
	NTF_FEVERISH,
	NTF_BLOOD,
	NTF_LIVES,
	NTF_STAMINA,
	//NTF_AGENT_INFECTION,
	NTF_PILLS,
	NTF_HEARTBEAT,
	NTF_FRACTURE,
	//----------------------------
	NTF_COUNT,// !!! LAST ITEM !!!

}


class NotifiersManager
{

	ref array<ref NotifierBase> 	m_Notifiers;
	PlayerBase						m_Player;
	ref VirtualHud					m_VirtualHud;
	int								m_MinTickTime;
	string 							m_System = "Notifiers";
	void NotifiersManager(PlayerBase player)
	{
		m_Player = player;

		m_Notifiers = new array<ref NotifierBase>;
		
		m_Notifiers.Insert(new HungerNotfr(this));
		m_Notifiers.Insert(new ThirstNotfr(this));
		m_Notifiers.Insert(new WarmthNotfr(this));
		m_Notifiers.Insert(new WetnessNotfr(this));
		m_Notifiers.Insert(new HealthNotfr(this));
		m_Notifiers.Insert(new FeverNotfr(this));
		m_Notifiers.Insert(new SickNotfr(this));
		//m_Notifiers.Insert(new BleedingNotfr(this));
		m_Notifiers.Insert(new StuffedNotfr(this));
		m_Notifiers.Insert(new BloodNotfr(this));
		//m_Notifiers.Insert(new AgentsNotfr(this));
		m_Notifiers.Insert(new PillsNotfr(this));
		m_Notifiers.Insert(new HeartbeatNotfr(this));
		m_Notifiers.Insert(new FracturedLegNotfr(this)); //New addition
		
		m_MinTickTime = MIN_TICK_NOTIFIERS;
	}

	PlayerBase GetPlayer()
	{
		return m_Player;
	}

	VirtualHud GetVirtualHud()
	{
		return m_VirtualHud;
	}


	NotifierBase FindNotifier( int type )
	{
		for(int i = 0;i < m_Notifiers.Count(); i++)
		{
			if ( m_Notifiers.Get(i).GetNotifierType() == type )
			{
				return m_Notifiers.Get(i);
			}
		}
		return null;
	}

	void ActivateByType(int notifier, bool triggerEvent = true)
	{
		FindNotifier(notifier).SetActive(true);
	}

	void DeactivateByType(int notifier, bool triggerEvent = true)
	{
		FindNotifier(notifier).SetActive(false);
	}

	void OnScheduledTick()
	{
		if( !GetPlayer().IsPlayerSelected() ) return;
		
		TickNotifiers();
	}

	void TickNotifiers()
	{
		int current_time = GetGame().GetTime();

		for(int i = 0;i < m_Notifiers.Count(); i++)
		{
			if ( m_Notifiers.Get(i).IsActive() && m_Notifiers.Get(i).IsTimeToTick(current_time) )
			{
				m_Notifiers.Get(i).OnTick(current_time);
			}
		}
	}

}