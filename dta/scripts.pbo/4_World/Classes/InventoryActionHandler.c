//! Client only - manage set up crafting on client 
class InventoryActionHandler
{
#ifdef OLD_ACTIONS
	int m_actionID;
	ItemBase m_itemTarget;
	ItemBase m_itemInHand;
#else
	ActionBase m_action;
	ActionTarget m_target;
	ItemBase m_mainItem;
	bool 	m_useItemInHands;
#endif
	PlayerBase m_player;
	
	bool m_isActive;
	vector m_actionStartPos;
	
	const float MIN_DISTANCE_TO_INTERRUPT = 1.0;	
	const int IAH_SINGLE_USE = 1;
	const int IAH_CONTINUOUS = 2;


	void InventoryActionHandler(PlayerBase player)
	{
		m_player = player;
		m_isActive = false;
#ifdef OLD_ACTIONS
		m_itemTarget = NULL;
		m_itemInHand = NULL;
		m_actionID = -1;
#else
		m_action = null;
		m_target = null;
		m_mainItem = null;
		m_useItemInHands = false;
#endif
	}
#ifdef OLD_ACTIONS
	void SetAction(int type, int ActionID, ItemBase actionTargetItem )
	{
		m_actionID = ActionID;
		m_itemTarget = actionTargetItem;
		m_itemInHand = m_player.GetItemInHands();
		m_actionStartPos = m_player.GetPosition();
		m_isActive = true;
		
		ActionManagerClient mngr;
		Class.CastTo(mngr, m_player.GetActionManager());
		
		ActionTarget at;
		at = new ActionTarget(actionTargetItem, null, -1, vector.Zero, -1);
		switch( type )
		{
			case IAH_SINGLE_USE:
				mngr.InjectSingleUseAction(ActionID, at, m_itemInHand);
				break;
			case IAH_CONTINUOUS:
				mngr.InjectContinuousAction(ActionID, at, m_itemInHand);
				break;
		}
		mngr.ForceTarget(actionTargetItem);
		
		GetGame().GetMission().HideInventory();
	}
#else
	void SetAction(ActionBase action, ItemBase target_item, ItemBase main_item )
	{
		Object target_parent = null;
		if(target_item)
		{
			target_parent = target_item.GetHierarchyParent();
		}
		ActionTarget at = new ActionTarget(target_item, target_parent, -1, vector.Zero, -1);
		
		SetAction(action, at, main_item );
	}
	
	void SetAction(ActionBase action, ActionTarget target, ItemBase main_item )
	{
		ActionManagerClient mngr;
		Class.CastTo(mngr, m_player.GetActionManager());
		
		m_action = action;
		m_target = target;
		m_mainItem = main_item;
		
		ItemBase itemInHand = m_player.GetItemInHands();
		m_useItemInHands = main_item == itemInHand;
		
		m_actionStartPos = m_player.GetPosition();
		m_isActive = true;
		
		mngr.InjectAction( action, target, main_item );
		mngr.ForceTarget(m_target.GetObject());
		
		GetGame().GetMission().HideInventory();
	}	
#endif	
	
#ifdef OLD_ACTIONS
	int GetActionID()
	{
		return m_actionID;
	}
#endif
	
	bool IsActiveAction()
	{
		return m_isActive;
	}
	
	void OnUpdate()
	{
		
		if( !m_isActive ) return;
		
		if( m_player.IsRaised() || m_player.GetCommand_Melee() )
		{
			DeactiveAction();
			return;			
		}
		
		if( GetGame().IsInventoryOpen() )
		{
			DeactiveAction();
			return;				
		}
#ifdef OLD_ACTIONS		
		ItemBase handItem = m_player.GetItemInHands();
		
		if( handItem != m_itemInHand )
		{
			DeactiveAction();
			return;
		}
#else
		if (m_useItemInHands)
		{
			ItemBase handItem = m_player.GetItemInHands();
		
			if( handItem != m_mainItem )
			{
				DeactiveAction();
				return;
			}
		}
#endif			
		if( Math.AbsFloat( vector.Distance(m_actionStartPos, m_player.GetPosition())) > MIN_DISTANCE_TO_INTERRUPT )
		{
			DeactiveAction();
			return;
		}
		
		
	}

	void DeactiveAction()
	{
		if( !m_isActive ) return;
		
		m_isActive = false;
#ifdef OLD_ACTIONS
		m_itemTarget = NULL;
		m_itemInHand = NULL;
		m_actionID = -1;
		
		
		ActionManagerClient mngr;
		Class.CastTo(mngr, m_player.GetActionManager());
		mngr.EjectActions();
		mngr.ClearForceTarget();
#else
		ActionManagerClient mngr;
		Class.CastTo(mngr, m_player.GetActionManager());
	
		mngr.EjectAction(m_action);
		mngr.ClearForceTarget();
		
		m_player.GetCraftingManager().ResetInventoryCraft();
		
		m_action = null;
		m_target = null;
		m_mainItem = null;
		m_useItemInHands = false;
#endif	
		
	}
}
