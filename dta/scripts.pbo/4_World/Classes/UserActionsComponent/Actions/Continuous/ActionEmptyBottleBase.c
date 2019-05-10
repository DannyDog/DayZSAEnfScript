class ActionEmptyBottleBaseCB : ActionContinuousBaseCB
{	
	override void CreateActionComponent()
	{
		float EmptiedQuantity;// = QUANTITY_EMPTIED_PER_SEC;
		Bottle_Base bottle = Bottle_Base.Cast(m_ActionData.m_MainItem);
		if (bottle)
			EmptiedQuantity = bottle.GetLiquidEmptyRate();
		m_ActionData.m_ActionComponent = new CAContinuousEmpty(EmptiedQuantity);
	}
	
	override void OnAnimationEvent(int pEventID)	
	{
		super.OnAnimationEvent( pEventID );
				
		switch (pEventID)
		{
			case UA_ANIM_EVENT:			
				if ( !GetGame().IsMultiplayer() || GetGame().IsServer() )
				{
					Bottle_Base vessel_in_hands = Bottle_Base.Cast( m_ActionData.m_MainItem );
					Param1<bool> play = new Param1<bool>( true );
					GetGame().RPCSingleParam( vessel_in_hands, SoundTypeBottle.EMPTYING, play, true );
				}

			break;
		}
	}
	
	override void EndActionComponent()
	{
		super.EndActionComponent();
		
		if ( !GetGame().IsMultiplayer() || GetGame().IsServer() )
		{
			Bottle_Base target_vessel = Bottle_Base.Cast( m_ActionData.m_MainItem );
			Param1<bool> play = new Param1<bool>( false );
			GetGame().RPCSingleParam( target_vessel, SoundTypeBottle.EMPTYING, play, true );
		}
	}
};

class ActionEmptyBottleBase: ActionContinuousBase
{
	void ActionEmptyBottleBase()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_MessageStartFail = "It's ruined.";
		m_MessageStart = "I have started filling the bottle.";
		m_MessageSuccess = "I have finished filling the bottle..";
		m_MessageFail = "Player moved and filling the bottle was canceled.";
		m_MessageCancel = "I stopped filling the bottle.";
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		
		m_CallbackClass = ActionEmptyBottleBaseCB;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINotRuinedAndEmpty;
		m_ConditionTarget = new CCTNone;
	}

	override int GetType()
	{
		return AT_EMPTY_BOTTLE;
	}

	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "#empty";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//TODO: implement proper solution, ideally something to do with camera angle
		vector 	pos_cursor = target.GetCursorHitPos();
		vector 	pos_head;
		MiscGameplayFunctions.GetHeadBonePos( player, pos_head );
		float distance = vector.Distance(pos_cursor, pos_head);
				
		if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
			return true;
		/*if ( item.IsLiquidPresent() && distance < 1.7 && !target.GetObject() )
			return true;*/
		DayZPlayerCameraBase camera;
		if ( item.IsLiquidPresent() && !target.GetObject() && DayZPlayerCameraBase.CastTo(camera, player.GetCurrentCamera()) && camera.GetCurrentPitch() < -70 )
		{
			//Print(camera.GetCurrentPitch());
			return true;
		}
		return false;
	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{
		if (action_data.m_MainItem.GetQuantity() > action_data.m_MainItem.GetQuantityMin())
		{
			return true;
		}
		return false;
	}
	
	/*override void OnCompleteLoopServer( ActionData action_data )
	{
		//item.TransferModifiers(player);
		Param1<float> nacdata;
		Class.CastTo(nacdata,  action_data.m_ActionComponent.GetACData() );
		float delta = nacdata.param1;
		action_data.m_MainItem.AddQuantity( -delta );

		action_data.m_Player.GetSoftSkillManager().AddSpecialty( m_SpecialtyWeight );
	}
	
	override void OnCancelServer( ActionData action_data )
	{
		OnCompleteLoopServer(action_data);
	}*/
};