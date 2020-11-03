class HandForceSwappingAnimated_Show extends HandStartAction
{
	ref InventoryLocation m_Src1 = null;
	ref InventoryLocation m_Src2 = null;
	ref InventoryLocation m_Dst1 = null;
	ref InventoryLocation m_Dst2 = null;

	void HandForceSwapingAnimated_Show (Man player = NULL, HandStateBase parent = NULL, WeaponActions action = WeaponActions.NONE, int actionType = -1) { }

	override void OnEntry (HandEventBase e)
	{
		if (m_Src1 && m_Src2 && m_Dst1 && m_Dst2)
		{
			GameInventory.LocationSwap(m_Src1, m_Src2, m_Dst1, m_Dst2);
			e.m_Player.OnItemInHandsChanged();
		}
		else
			Error("[hndfsm] HandForceSwappingAnimated_Show is not properly configured!");

		super.OnEntry(e);
	}

	override void OnAbort (HandEventBase e)
	{
		m_Src1 = null;
		m_Src2 = null;
		m_Dst1 = null;
		m_Dst2 = null;
		super.OnAbort(e);
	}

	override void OnExit (HandEventBase e)
	{
		m_Src1 = null;
		m_Src2 = null;
		m_Dst1 = null;
		m_Dst2 = null;
		super.OnExit(e);
	}

	override bool IsWaitingForActionFinish () { return true; }
};


class HandAnimatedForceSwapping extends HandStateBase
{
	ref InventoryLocation m_Src1 = null;
	ref InventoryLocation m_Src2 = null;
	ref InventoryLocation m_Dst1 = null;
	ref InventoryLocation m_Dst2 = null;

	ref HandStartHidingAnimated m_Hide;
	ref HandForceSwappingAnimated_Show m_Show;

	void HandAnimatedForceSwapping (Man player = NULL, HandStateBase parent = NULL)
	{
		// setup nested state machine
		m_Hide = new HandStartHidingAnimated(player, this, WeaponActions.HIDE, -1);
		m_Show = new HandForceSwappingAnimated_Show(player, this, WeaponActions.SHOW, -1);

		// events:
		HandEventBase _fin_ = new HandEventHumanCommandActionFinished;
		HandEventBase _AEh_ = new HandAnimEventChanged;
		HandEventBase __Xd_ = new HandEventDestroyed;

		m_FSM = new HandFSM(this); // @NOTE: set owner of the submachine fsm

		m_FSM.AddTransition(new HandTransition(   m_Hide, _AEh_,   m_Show ));
		m_FSM.AddTransition(new HandTransition(   m_Hide, _fin_,   m_Show )); // no animation in Hide step
		m_FSM.AddTransition(new HandTransition(   m_Show, _fin_,     NULL ));
		m_FSM.AddTransition(new HandTransition(   m_Show, __Xd_,     null ));

		m_FSM.SetInitialState(m_Hide);
	}

	override void OnEntry (HandEventBase e)
	{		
		HandEventForceSwap efs = HandEventForceSwap.Cast(e);
		if (efs)
		{
			m_Hide.m_ActionType = efs.m_AnimationID;
			
			m_Src1 = efs.GetSrc();
			m_Src2 = efs.m_Src2;
			m_Dst1 = efs.GetDst();
			m_Dst2 = efs.m_Dst2;

			m_Show.m_Src1 = m_Src1;
			m_Show.m_Src2 = m_Src2;
			m_Show.m_Dst1 = m_Dst1;
			m_Show.m_Dst2 = m_Dst2;
			
			m_Show.m_ActionType = efs.m_Animation2ID;
			
			if (GetGame().IsClient() || !GetGame().IsMultiplayer())
			{
				e.m_Player.GetHumanInventory().AddInventoryReservation(m_Src2.GetItem(), m_Src2, GameInventory.c_InventoryReservationTimeoutShortMS);
				e.m_Player.GetHumanInventory().AddInventoryReservation(m_Src1.GetItem(), m_Src1, GameInventory.c_InventoryReservationTimeoutShortMS);
			}
		}

		super.OnEntry(e); // @NOTE: super at the end (prevent override from submachine start)
	}

	override void OnAbort (HandEventBase e)
	{
		if( GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			e.m_Player.GetHumanInventory().ClearInventoryReservation(m_Src2.GetItem(), m_Src2);
			e.m_Player.GetHumanInventory().ClearInventoryReservation(m_Src1.GetItem(), m_Src1);
		}
		else
		{
			GetGame().ClearJuncture(e.m_Player, m_Src2.GetItem());
			GetGame().ClearJuncture(e.m_Player, m_Src1.GetItem());
		}
		
		m_Src1 = null;
		m_Src2 = null;
		m_Dst1 = null;
		m_Dst2 = null;
		
		super.OnAbort(e);
	}

	override void OnExit (HandEventBase e)
	{
		if( GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			e.m_Player.GetHumanInventory().ClearInventoryReservation(m_Src2.GetItem(), m_Src2);
			e.m_Player.GetHumanInventory().ClearInventoryReservation(m_Src1.GetItem(), m_Src1);
		}
		
		m_Src1 = null;
		m_Src2 = null;
		m_Dst1 = null;
		m_Dst2 = null;

		super.OnExit(e);
	}
};

