class ActionBuildShelter: ActionBuildPart
{
	string 						m_SoundsetBuildStart;
	string 						m_SoundsetBuildLoop;
	string 						m_SoundsetBuildFinish;
	ref protected EffectSound 	m_BuildLoopSound;
	
	void ActionBuildShelter()
	{
		m_CallbackClass = ActionBuildPartCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTCursor;
	}
	
	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			ConstructionPart constrution_part = construction_action_data.GetCurrentBuildPart();
			
			if ( constrution_part )
			{
				string ret = "";
				switch (constrution_part.GetName())
				{
					case "leather":
						ret = "#build_shelter_leather";
					break;
					
					case "fabric":
						ret = "#build_shelter_fabric";
					break;
					
					case "stick":
						ret = "#build_shelter_stick";
					break;
				}
			}
		}
		
		return ret;
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override bool UseMainItem()
	{
		return false;
	}
	
	override bool HasProgress()
	{
		return true;
	}
	
	override bool HasAlternativeInterrupt()
	{
		return false;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//Action not allowed if player has broken legs
		if (player.m_BrokenLegState == eBrokenLegs.BROKEN_LEGS)
			return false;
		
		if(target.GetObject() && !target.GetObject().CanUseConstructionBuild())
			return false;
		if( player.IsPlacingLocal() || player.IsPlacingServer() )
			return false;
		
		if( (!GetGame().IsMultiplayer() || GetGame().IsClient()) )
		{
			ConstructionActionData construction_action_data = player.GetConstructionActionData();
			int start_index = construction_action_data.m_PartIndex;
			if( construction_action_data.GetConstructionPartsCount() > 0 )
			{
				for(int i = 0; i < construction_action_data.GetConstructionPartsCount(); i++)
				{
					if( MiscGameplayFunctions.ComplexBuildCollideCheckClient(player, target, item ) )
					{
						return true;
					}
					else
					{
						construction_action_data.SetNextIndex();
					}
				}
				construction_action_data.m_PartIndex = start_index;
			}
			return false;
		}
		return true;
	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{
		return MiscGameplayFunctions.BuildCondition( action_data.m_Player, action_data.m_Target, action_data.m_MainItem , false );
	}
	
	override void OnStart( ActionData action_data )
	{
		super.OnStart(action_data);
		action_data.m_Player.TryHideItemInHands(true);
	}
	
	override void OnStartClient( ActionData action_data )
	{
		super.OnStartClient(action_data);
		
		DetermineConstructionSounds(action_data);
		PlayActionStartSound(action_data);
	}
	
	override void OnStartAnimationLoopClient( ActionData action_data )
	{
		super.OnStartAnimationLoopClient(action_data);
		
		PlayActionLoopSound(action_data);
	}
	
	override void OnEnd( ActionData action_data )
	{
		super.OnEnd(action_data);
		action_data.m_Player.TryHideItemInHands(false);
	}
	
	override void OnEndClient( ActionData action_data )
	{
		super.OnEndClient(action_data);
		
		StopActionLoopSound();
		//DestroyActionLoopSound();
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		Construction construction = base_building.GetConstruction();
		
		string part_name = BuildPartActionData.Cast(action_data).m_PartType;
		
		if ( !construction.IsColliding( part_name ) && construction.CanBuildPart( part_name, action_data.m_MainItem, false ) )
		{
			//build
			construction.BuildPartServer( action_data.m_Player, part_name, AT_BUILD_PART );
		}
		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	
	override void OnFinishProgressClient( ActionData action_data )
	{
		super.OnFinishProgressClient(action_data);
		
		PlayActionFinishSound(action_data);
	}
	
	override protected void SetBuildingAnimation( ItemBase item )
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_2HD;
	}
	
	void DetermineConstructionSounds( ActionData action_data )
	{
		ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
		ConstructionPart constrution_part = construction_action_data.GetCurrentBuildPart();
		if (constrution_part)
		{
			switch (constrution_part.GetName())
			{
				case "leather":
					m_SoundsetBuildStart = "Shelter_Leather_Build_Start_SoundSet";
					m_SoundsetBuildLoop = "Shelter_Leather_Build_Loop_SoundSet";
					m_SoundsetBuildFinish = "Shelter_Leather_Build_Finish_SoundSet";
				break;
				
				case "fabric":
					m_SoundsetBuildStart = "Shelter_Fabric_Build_Start_SoundSet";
					m_SoundsetBuildLoop = "Shelter_Fabric_Build_Loop_SoundSet";
					m_SoundsetBuildFinish = "Shelter_Fabric_Build_Finish_SoundSet";
				break;
				
				case "stick":
					m_SoundsetBuildStart = "Shelter_Wooden_Stick_Build_Start_SoundSet";
					m_SoundsetBuildLoop = "Shelter_Wooden_Stick_Build_Loop_SoundSet";
					m_SoundsetBuildFinish = "Shelter_Wooden_Stick_Build_Finish_SoundSet";
				break;
				
				default:
					m_SoundsetBuildStart = "";
					m_SoundsetBuildLoop = "";
					m_SoundsetBuildFinish = "";
				break;
			}
		}
	}
	
	void PlayActionStartSound( ActionData action_data )
	{
		EffectSound sound =	SEffectManager.PlaySound(m_SoundsetBuildStart, action_data.m_Target.GetObject().GetPosition());
		sound.SetSoundAutodestroy( true );
	}
	
	void PlayActionLoopSound( ActionData action_data )
	{
		if (!m_BuildLoopSound)
		{
			m_BuildLoopSound = new EffectSound;
			//m_BuildLoopSound = SEffectManager.CreateSound(m_SoundsetBuildLoop,action_data.m_Target.GetObject().GetPosition(),0,0,true);
		}
		if ( !m_BuildLoopSound.IsSoundPlaying() )
		{
			m_BuildLoopSound = SEffectManager.PlaySound( m_SoundsetBuildLoop, action_data.m_Target.GetObject().GetPosition(),0,0,true );
		}
		//Print("loop playing: " + m_BuildLoopSound.IsSoundPlaying());
	}
	
	void StopActionLoopSound()
	{
		if (m_BuildLoopSound)
		{
			m_BuildLoopSound.SetSoundFadeOut(0.5);
			m_BuildLoopSound.SoundStop();
		}
	}
	
	void DestroyActionLoopSound()
	{
		if (m_BuildLoopSound)
		{
			//Print("m_BuildLoopSound destroying: " + m_BuildLoopSound);
			SEffectManager.DestroySound( m_BuildLoopSound );
			//Print("m_BuildLoopSound destroyed");
			//Print(m_BuildLoopSound);
			//Print("---------");
		}
	}
	
	void PlayActionFinishSound( ActionData action_data )
	{
		EffectSound sound =	SEffectManager.PlaySound(m_SoundsetBuildFinish, action_data.m_Target.GetObject().GetPosition());
		sound.SetSoundAutodestroy( true );
	}
}