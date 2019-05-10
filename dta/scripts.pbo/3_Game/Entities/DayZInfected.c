enum DayZInfectedConstants
{
	//! anim commands
	COMMANDID_MOVE,
	COMMANDID_VAULT,
	COMMANDID_DEATH,
	COMMANDID_HIT,
	COMMANDID_ATTACK,
	COMMANDID_CRAWL,
	
	//! mind states
	MINDSTATE_CALM,
	MINDSTATE_DISTURBED,
	MINDSTATE_ALERTED,
	MINDSTATE_CHASE,
	MINDSTATE_FIGHT,
};

enum DayZInfectedConstantsMovement
{
	MOVEMENTSTATE_IDLE = 0,
	MOVEMENTSTATE_WALK,
	MOVEMENTSTATE_RUN,
	MOVEMENTSTATE_SPRINT
}

class DayZInfectedCommandMove
{
	proto native void SetStanceVariation(int pStanceVariation);
	proto native void SetIdleState(int pIdleState);
	proto native void StartTurn(float pDirection, int pSpeedType);
	proto native bool IsTurning();
}

class DayZInfectedCommandVault
{
	proto native bool WasLand();
}

class DayZInfectedCommandAttack
{
	proto native bool WasHit();
}

class DayZInfected extends DayZCreatureAI
{	
	proto native DayZInfectedType GetDayZInfectedType();
	proto native DayZInfectedInputController GetInputController();	
	proto native DayZInfectedCommandMove StartCommand_Move();	
	proto native DayZInfectedCommandVault StartCommand_Vault(int pType);	
	proto native void StartCommand_Death(int pType, float pDirection);
	proto native void StartCommand_Hit(bool pHeavy, int pType, float pDirection);
	proto native DayZInfectedCommandAttack StartCommand_Attack(EntityAI pTarget, int pType, float pSubtype);
	proto native void StartCommand_Crawl(int pType);
	
	proto native bool CanAttackToPosition(vector pTargetPosition);
	
	proto native DayZInfectedCommandMove GetCommand_Move();
	proto native DayZInfectedCommandVault GetCommand_Vault();
	proto native DayZInfectedCommandAttack GetCommand_Attack();
		
	//-------------------------------------------------------------
	void DayZInfected()
	{
	}
	
	//-------------------------------------------------------------
	void ~DayZInfected()
	{
	}
	
	//-------------------------------------------------------------
	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos);
		
		if( !IsAlive() )
		{
			if ( !m_DeathSyncSent ) //to be sent only once on hit/death
			{
				Man killer = source.GetHierarchyRootPlayer();
				
				if ( !m_KillerData ) //only one player is considered killer in the event of crossfire
				{
					m_KillerData = new KillerData;
					m_KillerData.m_Killer = killer;
					m_KillerData.m_MurderWeapon = source;
				}
				
				if ( killer && killer.IsPlayer() )
				{
					// was infected killed by headshot?
					if ( dmgZone == "Head" ) //no "Brain" damage zone defined (nor can it be caught like on player, due to missing command handler), "Head" is sufficient
					{
						m_KilledByHeadshot = true;
						if (m_KillerData.m_Killer == killer)
							m_KillerData.m_KillerHiTheBrain = true;
					}
				}
				SyncEvents.SendEntityKilled(this, m_KillerData.m_Killer, m_KillerData.m_MurderWeapon, m_KillerData.m_KillerHiTheBrain);
				m_DeathSyncSent = true;
			}
		}
	}
}