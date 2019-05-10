class FreezeSymptom extends SymptomBase
{
	//this is just for the Symptom parameters set-up and is called even if the Symptom doesn't execute, don't put any gameplay code in here
	override void OnInit()
	{
		m_SymptomType = SymptomTypes.PRIMARY;
		m_Priority = 1;
		m_ID = SymptomIDs.SYMPTOM_FREEZE;
		m_DestroyOnAnimFinish = true;
		m_SyncToClient = false;
	}
	
	//!gets called every frame
	override void OnUpdateServer(PlayerBase player, float deltatime)
	{

	}

	override void OnUpdateClient(PlayerBase player, float deltatime)
	{
	}
	
	override void OnAnimationPlayFailed()
	{
		
	}
	
	override bool CanActivate()
	{
		return true;
	}
	
	//!gets called once on an Symptom which is being activated
	override void OnGetActivatedServer(PlayerBase player)
	{	
		HumanMovementState hms = new HumanMovementState();
		player.GetMovementState(hms);
		ItemBase item = m_Player.GetItemInHands();
		//PlaySound(EPlayerSoundEventID.FREEZING);
		//return;//crash fix
		if(!(item && item.IsHeavyBehaviour()) && m_Manager.GetCurrentCommandID() == DayZPlayerConstants.COMMANDID_MOVE && hms.m_iMovement == DayZPlayerConstants.MOVEMENTIDX_IDLE && !player.IsRestrained() )
		{
			PlayAnimationADD(2);
		}
		else
		{
			PlaySound(EPlayerSoundEventID.FREEZING);
		}
	}

	//!gets called once on a Symptom which is being activated
	override void OnGetActivatedClient(PlayerBase player)
	{
	}

	//!only gets called once on an active Symptom that is being deactivated
	override void OnGetDeactivatedServer(PlayerBase player)
	{
		Debug.Log("OnGetDeactivated CoughSymptom called", "PlayerSymptom");
	}

	//!only gets called once on an active Symptom that is being deactivated
	override void OnGetDeactivatedClient(PlayerBase player)
	{
		Debug.Log("OnGetDeactivated CoughSymptom called", "PlayerSymptom");
	}
	
	override SmptAnimMetaBase SpawnAnimMetaObject()
	{
		return new HeatComfortmMetaADD();
	}
}
