class VomitSymptom extends SymptomBase
{
	//just for the Symptom parameters set-up and gets called even if the Symptom doesn't execute, don't put any gameplay code in here
	override void OnInit()
	{
		m_SymptomType = SymptomTypes.PRIMARY;
		m_Priority = 100;
		m_ID = SymptomIDs.SYMPTOM_VOMIT;
		m_DestroyOnAnimFinish = true;
		m_SyncToClient = false;
		m_Duration = 5;
	}
	
	//!gets called every frame
	override void OnUpdateServer(PlayerBase player, float deltatime)
	{

	}

	override void OnUpdateClient(PlayerBase player, float deltatime)
	{

	}
	
	override void OnAnimationStart()
	{
		m_Player.GetStatStomachVolume().Set(0);
		m_Player.GetStatStomachWater().Set(0);
		m_Player.GetStatStomachEnergy().Set(0);
		m_Player.GetStatToxicity().Set(0);
		
		Print("------------ vomit start -------------");
	}
	
	override void OnAnimationFinish()
	{
		
	}
	
	override bool CanActivate()
	{
		return ( m_Manager.GetCurrentCommandID() == DayZPlayerConstants.COMMANDID_MOVE || m_Manager.GetCurrentCommandID() == DayZPlayerConstants.COMMANDID_ACTION );
	}	
	
	//!gets called once on an Symptom which is being activated
	override void OnGetActivatedServer(PlayerBase player)
	{
		PlayAnimationFB(DayZPlayerConstants.CMD_ACTIONFB_VOMIT,DayZPlayerConstants.STANCEMASK_CROUCH, GetDuration() );
		//timer.Run(10, this, "Destroy");
		Debug.Log("OnGetActivated VomitSymptom called", "PlayerSymptom");
		
	}

	//!only gets called once on an active Symptom that is being deactivated
	override void OnGetDeactivatedServer(PlayerBase player)
	{
		Debug.Log("OnGetDeactivated VomitSymptom called", "PlayerSymptom");
	}

	override void OnGetDeactivatedClient(PlayerBase player)
	{
		Debug.Log("OnGetDeactivated VomitSymptom called", "PlayerSymptom");
	}
	
	override SmptAnimMetaBase SpawnAnimMetaObject()
	{
		return new SmptAnimMetaFB();
	}
}