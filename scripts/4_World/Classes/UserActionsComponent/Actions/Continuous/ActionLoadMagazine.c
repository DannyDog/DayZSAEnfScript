class ActionLoadMagazineCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(UATimeSpent.MAG_LOAD);
	}
	
	int time;
	override void OnAnimationEvent(int pEventID)	
	{
		super.OnAnimationEvent( pEventID );
		
		if ( GetGame().IsClient() )
			return;
		
		switch (pEventID)
		{
			case UA_ANIM_EVENT:			
				{
					
					Print(GetGame().GetTime()-time);
					time = GetGame().GetTime();
					//Param1<float> timeSpendParam;
					//if( !Class.CastTo(timeSpendParam, action_data.m_ActionComponent.GetACData()) ) return;
		
					Magazine trg;
					Magazine itm;
					if ( Class.CastTo(trg,  m_ActionData.m_Target.GetObject()) && Class.CastTo(itm, m_ActionData.m_MainItem) )
					{
						float dmg;
						string ammoType;
						
						if ( trg.ServerAcquireCartridge(dmg,ammoType) )
						{
							if ( !itm.ServerStoreCartridge(dmg,ammoType) )		
							{	
								trg.ServerStoreCartridge(dmg,ammoType);
							}
							else
							{
								itm.ApplyManipulationDamage(); //damages magazine
							}
						}
					}
					
					trg.SetSynchDirty();
					itm.SetSynchDirty();
					//manipulationDamage
					//if(trg.GetAmmoCount() > 0 )
						//trg.SetSynchDirty();
					//itm.SetSynchDirty();
				}
				break;
			
			default:
				break;
		}
	}
};

class ActionLoadMagazine: ActionContinuousBase
{
	void ActionLoadMagazine()
	{
		m_CallbackClass = ActionLoadMagazineCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_FILLMAG;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_FILLMAG;
	}
	
	override bool HasProneException()
	{
		return true;
	}

	override string GetText()
	{
		return "#load_magazine";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined();
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Magazine trg;
		Magazine itm;
		return ( Class.CastTo(trg, target.GetObject()) && Class.CastTo(itm, item) && itm.GetAmmoCount() < itm.GetAmmoMax() && trg.GetAmmoCount() != 0 && itm.IsCompatiableAmmo( trg ) );
	}
	
	override bool CanBePerformedFromQuickbar()
	{
		return true;
	}
};

class ActionLoadMagazineQuickCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(UATimeSpent.MAG_LOAD);
	}
	
	override void OnAnimationEvent(int pEventID)	
	{
		super.OnAnimationEvent( pEventID );
		
		if ( GetGame().IsClient() )
			return;
		
		switch (pEventID)
		{
			case UA_ANIM_EVENT:			
				{
					//Param1<float> timeSpendParam;
					//if( !Class.CastTo(timeSpendParam, action_data.m_ActionComponent.GetACData()) ) return;
					
					Magazine itm = Magazine.Cast(m_ActionData.m_MainItem);
					Magazine trg = m_ActionData.m_Player.GetWeaponManager().GetPreparedMagazine();
					
					if ( itm && trg )
					{
						float dmg;
						string ammoType;
						
						if ( trg.ServerAcquireCartridge(dmg,ammoType) )
						{
							if ( !itm.ServerStoreCartridge(dmg,ammoType) )		
							{	
								trg.ServerStoreCartridge(dmg,ammoType);
							}
							else
							{
								itm.ApplyManipulationDamage(); //damages magazine
							}
						}
					}
					
					trg.SetSynchDirty();
					itm.SetSynchDirty();
					//manipulationDamage
					//if(trg.GetAmmoCount() > 0 )
						//trg.SetSynchDirty();
					//itm.SetSynchDirty();
				}
				break;
			
			default:
				break;
		}
	}
};

class ActionLoadMagazineQuick: ActionContinuousBase
{
	void ActionLoadMagazineQuick()
	{
		m_CallbackClass = ActionLoadMagazineQuickCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_FILLMAG;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_FILLMAG;
	}
	
	override bool HasProneException()
	{
		return true;
	}
	
	override typename GetInputType()
	{
		return ContinuousWeaponManipulationActionInput;
	} 
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined();
		m_ConditionTarget = new CCTSelf;
	}
	
	override bool HasTarget()
	{
		return false;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Magazine mag = Magazine.Cast( item );

		return mag && player.GetWeaponManager().GetPreparedMagazine() != null && mag.GetAmmoCount() < mag.GetAmmoMax();
	}
};