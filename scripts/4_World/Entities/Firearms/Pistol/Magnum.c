const float MAGNUM_ROTATION_POSITION_M1 = -0.167;
const float MAGNUM_ROTATION_POSITION_0 = 0.0;
const float MAGNUM_ROTATION_POSITION_1 = 0.167;
const float MAGNUM_ROTATION_POSITION_2 = 0.334;
const float MAGNUM_ROTATION_POSITION_3 = 0.500;
const float MAGNUM_ROTATION_POSITION_4 = 0.668;
const float MAGNUM_ROTATION_POSITION_5 = 0.835;
const float MAGNUM_ROTATION_POSITION_6 = 1.0;


enum MagnumAnimState
{
	DEFAULT 			= 0, 	///< default weapon state
};

enum MagnumStableStateID
{
	DEFAULT				=  0,
}

class Magnum_Static_State extends WeaponStableState
{
	bool init = false;
	override void OnEntry (WeaponEventBase e) 
	{ 
		
		wpnPrint("[wpnstate] { Magnum stable state"); 
		super.OnEntry(e);
		if(init)
		{
			Magnum_Cylinder cylinder = Magnum_Cylinder.Cast(m_weapon.GetAttachmentByType(Magnum_Cylinder));
			Magnum_Ejector ejector = Magnum_Ejector.Cast(m_weapon.GetAttachmentByType(Magnum_Ejector));
			
			if(cylinder && ejector)
			{
				float rot;
				int mi = m_weapon.GetCurrentMuzzle();
				switch(mi)
				{
	
					case 0:
						rot = MAGNUM_ROTATION_POSITION_0;
						break;
					case 1:
						rot = MAGNUM_ROTATION_POSITION_5;
						break;
					case 2:
						rot = MAGNUM_ROTATION_POSITION_4;
						break;
					case 3:
						rot = MAGNUM_ROTATION_POSITION_3;
						break;
					case 4:
						rot = MAGNUM_ROTATION_POSITION_2;
						break;	
					case 5:
						rot = MAGNUM_ROTATION_POSITION_1;
						break;	
				}
				float anim_phase = cylinder.GetAnimationPhase("Rotate_Cylinder");
				if(anim_phase + 0.1 < rot || anim_phase - 0.1 > rot)
				{
					cylinder.ResetAnimationPhase("Rotate_Cylinder", rot );
					cylinder.SetAnimationPhase("Rotate_Cylinder", rot );
					ejector.ResetAnimationPhase("Rotate_Ejector", rot );
					ejector.SetAnimationPhase("Rotate_Ejector", rot );
				}
			}
		}
		init = true;
	}
	override void OnExit (WeaponEventBase e) { super.OnExit(e); wpnPrint("[wpnstate] }  Magnum stable state"); }
	override int GetCurrentStateID () { return MagnumStableStateID.DEFAULT; }
	override bool HasBullet () { return false; }
	override bool HasMagazine () { return false; }
	override bool IsJammed () { return false; }
};



class Magnum_Base extends Weapon_Base
{
	ref WeaponStateBase C;
	int m_LastMuzzleloaded;
	int m_ActiveMuzzle;
	const string ATT_SLOT_CYLINDER = "RevolverCylinder";
	const string ATT_SLOT_EJECTOR = "RevolverEjector";
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(FirearmActionLoadMultiBullet);

		RemoveAction(FirearmActionLoadBulletQuick); // Easy reload
		AddAction(FirearmActionLoadMultiBulletQuick); // Easy reload

	}
	
	override RecoilBase SpawnRecoilObject()
	{
		return new MagnumRecoil(this);
	}
	
	void Magnum_Base ()
	{
		m_LastMuzzleloaded = 0;
		m_ActiveMuzzle = 0;
		
		/*m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionTypes.CHAMBERING_STARTLOOPABLE_CLOSED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionTypes.CHAMBERING_ENDLOOPABLE));
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionTypes.MECHANISM_CLOSED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionTypes.MECHANISM_SPECIAL));
		m_abilities.Insert(new AbilityRecord(WeaponActions.UNJAMMING, WeaponActionTypes.UNJAMMING_START));
		m_abilities.Insert(new AbilityRecord(WeaponActions.UNJAMMING, WeaponActionTypes.UNJAMMING_END));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionTypes.FIRE_NORMAL));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionTypes.FIRE_COCKED));*/
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).Call( AssembleGun );
	}
	
	override void InitStateMachine ()
	{
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED_KEEP));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE));
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_SPECIAL));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_COCKED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_UNCOCKED));


		// setup state machine
		// basic weapon state
		C = new Magnum_Static_State(this, NULL, MagnumAnimState.DEFAULT);


		WeaponMagnumChambering Chamber = new WeaponMagnumChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED_KEEP,WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		WeaponMagnumChambering Chamber_E = new WeaponMagnumChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED,WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		//WeaponMagnumChambering Chamber_CC00 = new WeaponMagnumChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_END);

		WeaponCharging Mech = new WeaponCharging(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED);
		
		WeaponStateBase	Trigger_normal = new WeaponFireMagnum(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL);
		WeaponStateBase	Trigger_dry = new WeaponFireMagnum(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_COCKED);
		
		// events

		WeaponEventBase __L__ = new WeaponEventLoad1Bullet;
		WeaponEventBase _fin_ = new WeaponEventHumanCommandActionFinished;
		WeaponEventBase _abt_ = new WeaponEventHumanCommandActionAborted;
		WeaponEventBase __M__ = new WeaponEventMechanism;
		WeaponEventBase __T__ = new WeaponEventTrigger;
		

		WeaponEventBase _rto_ = new WeaponEventReloadTimeout;
		WeaponEventBase _dto_ = new WeaponEventDryFireTimeout;

	
		m_fsm = new WeaponFSM();



		m_fsm.AddTransition(new WeaponTransition( C,				__L__,	Chamber, null, new WeaponGuardAnyChamberFiredOut(this))); // chamber from closed charged
		m_fsm.AddTransition(new WeaponTransition(  Chamber,	_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Chamber,	_abt_,	C));

		
		m_fsm.AddTransition(new WeaponTransition( C,				__L__,	Chamber_E)); // chamber from closed charged
		m_fsm.AddTransition(new WeaponTransition(  Chamber_E,	_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Chamber_E,	_abt_,	C));

		
		m_fsm.AddTransition(new WeaponTransition( C,				__M__,	Mech)); // charge from closed
		m_fsm.AddTransition(new WeaponTransition(  Mech,		_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Mech,		_abt_,	C));

		
		
		m_fsm.AddTransition(new WeaponTransition( C,				__T__,	Trigger_normal, null, new GuardAnd (new WeaponGuardCurrentChamberFull(this), new GuardNot(new WeaponGuardCurrentChamberFiredOut(this))) )); // fire.cocked
		m_fsm.AddTransition(new WeaponTransition(  Trigger_normal,	_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_normal, 	_dto_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_normal, 	_abt_,	C));
		
		m_fsm.AddTransition(new WeaponTransition( C,				__T__,	Trigger_dry)); // fire.cocked
		m_fsm.AddTransition(new WeaponTransition(  Trigger_dry,	_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_dry, 	_dto_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_dry, 	_abt_,	C));


		m_fsm.SetInitialState(C);
		SelectionBulletHide();
		SetCurrentMuzzle(0);
		//HideMagazine();
		m_fsm.Start();
	}
	
	override bool CanChamberBullet (int muzzleIndex, Magazine mag)
	{
		for(int i = 0; i < GetMuzzleCount(); i++)
		{
			if( CanChamberFromMag(i, mag) )
			{
				if(IsChamberEmpty(i))
					return true;
				
				if(IsChamberFiredOut(i))
					return true;
			} 
		}
		return false;
	}
	
	void AssembleGun()
	{
		if ( !FindAttachmentBySlotName(ATT_SLOT_EJECTOR) && !FindAttachmentBySlotName(ATT_SLOT_CYLINDER) )
		{
			GetInventory().CreateAttachment("Magnum_Ejector");
			GetInventory().CreateAttachment("Magnum_Cylinder");
		}
		else
		{
			Magnum_Cylinder cylinder = Magnum_Cylinder.Cast(GetAttachmentByType(Magnum_Cylinder));
			Magnum_Ejector ejector = Magnum_Ejector.Cast(GetAttachmentByType(Magnum_Ejector));

			if(cylinder && ejector)
			{			
				for (int i = 0; i < GetMuzzleCount(); i++ )
				{
					if (IsChamberFull(i))
					{
						string bullet = "bullet";
						if (i > 0)
							bullet = string.Format("bullet_" + (i + 1));
						cylinder.ShowSelection(bullet);
						
						if (!IsChamberFiredOut(i))
						{
							string bullet_nose = "bullet_nose";
							if (i > 0)
								bullet_nose = string.Format("bullet_nose_" + (i + 1));
							cylinder.ShowSelection(bullet_nose);
						}
					}
				}
				
				float rot;
				int mi = GetCurrentMuzzle();
				switch(mi)
				{
	
					case 0:
						rot = MAGNUM_ROTATION_POSITION_0;
						break;
					case 1:
						rot = MAGNUM_ROTATION_POSITION_5;
						break;
					case 2:
						rot = MAGNUM_ROTATION_POSITION_4;
						break;
					case 3:
						rot = MAGNUM_ROTATION_POSITION_3;
						break;
					case 4:
						rot = MAGNUM_ROTATION_POSITION_2;
						break;	
					case 5:
						rot = MAGNUM_ROTATION_POSITION_1;
						break;	
				}
				float anim_phase = cylinder.GetAnimationPhase("Rotate_Cylinder");
				if(anim_phase + 0.1 < rot || anim_phase - 0.1 > rot)
				{
					cylinder.ResetAnimationPhase("Rotate_Cylinder", rot );
					cylinder.SetAnimationPhase("Rotate_Cylinder", rot );
					ejector.ResetAnimationPhase("Rotate_Ejector", rot );
					ejector.SetAnimationPhase("Rotate_Ejector", rot );
				}
			}
		}
	}
	
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		
		if(GetGame().IsMultiplayer() && !GetGame().IsServer())
			return;
		
		SetAttachmentsHealth();
	}
	
	//sets health of cylinder and ejector objects
	void SetAttachmentsHealth()
	{
		EntityAI entity;
		ItemBase attachment;
		for (int i = 0; i < GetInventory().AttachmentCount(); i++)
		{
			entity = GetInventory().GetAttachmentFromIndex(i);
			if ( Class.CastTo(attachment,entity) )
			{
				attachment.SetHealth01("","Health",GetHealth01());
			}
		}
	}
	
	override void OnFire(int muzzle_index)
	{
		Magnum_Cylinder cylinder = Magnum_Cylinder.Cast(GetAttachmentByType(Magnum_Cylinder));
		if (cylinder)
		{
			string bullet_nose = "bullet_nose";
			if (muzzle_index > 0)
				bullet_nose = string.Format("bullet_nose_" + (muzzle_index + 1));
			cylinder.HideSelection(bullet_nose);
		}
	}
	
	override bool IsShowingChamberedBullet()
	{
		return false;
	}
	
	override bool CanEjectBullet() 
	{
		for(int i = 0; i < GetMuzzleCount(); i++)
		{
			if(IsChamberFull(i))
				return true;
		}
		return false;
	}
};

class Magnum extends Magnum_Base {};
class Magnum_Cylinder extends DummyItem {};
class Magnum_Ejector extends DummyItem {};