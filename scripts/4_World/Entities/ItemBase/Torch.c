class Torch : ItemBase
{
	private SoundOnVehicle	m_LoopSoundEntity;
	Particle 				m_FireParticle;
	bool					m_CanReceiveUpgrade; // Synchronized variable
	bool					m_IsBeingDestructed = false;
	
	static float 			m_BurnTimePerRag;
	static float 			m_BurnTimePerFullLard;
	static float 			m_BurnTimePerFullFuelDose;
	static float 			m_MaxConsumableLardQuantity;
	static float 			m_MaxConsumableFuelQuantity;
	static float 			m_WaterEvaporationByFireIntensity = 0.001;
	static int 				m_StartFadeOutOfLightAtQuantity = 3;
	vector 					m_ParticleLocalPos = Vector(0, 0.50, 0);
	
	string					m_DecraftResult = "WoodenStick";
	TorchLight				m_Light;
	
	void Torch()
	{
		if ( m_BurnTimePerRag == 0 || m_BurnTimePerFullLard == 0 || m_MaxConsumableLardQuantity == 0 || m_MaxConsumableFuelQuantity == 0 )
		{
			string cfg_path = "CfgVehicles " + GetType();
			m_BurnTimePerRag = GetGame().ConfigGetFloat( cfg_path + " burnTimePerRag" );
			m_BurnTimePerFullLard = GetGame().ConfigGetFloat( cfg_path + " burnTimePerFullLardDose" );
			m_BurnTimePerFullFuelDose = GetGame().ConfigGetFloat( cfg_path + " burnTimePerFullFuelDose" );
			m_MaxConsumableLardQuantity = GetGame().ConfigGetFloat( cfg_path + " maxConsumableLardDose" );
			m_MaxConsumableFuelQuantity = GetGame().ConfigGetFloat( cfg_path + " maxConsumableFuelDose" );
		}
		
		RegisterNetSyncVariableBool("m_CanReceiveUpgrade");
	}
	
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		if ( m_LoopSoundEntity != NULL && GetGame() != NULL )
		{
			GetGame().ObjectDelete( m_LoopSoundEntity );
		}
		
		StopAllParticles();
	}
	
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		ItemBase att = ItemBase.Cast(GetInventory().FindAttachment(slotId));
		if (att && att.IsFullQuantity())
			return false;
		
		return super.CanReceiveAttachment(attachment, slotId);
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}
		return CanBeTakenAsCargo();
	}
	
	override bool CanReleaseAttachment(EntityAI attachment)
	{
		if( !super.CanReleaseAttachment( attachment ) )
			return false;
		return !GetCompEM().IsWorking();
	}
	
	override bool CanRemoveFromCargo(EntityAI parent)
	{
		return CanBeTakenAsCargo();
	}
	
	bool CanBeTakenAsCargo()
	{
		// Don't let players burn their pockets!
		return !GetCompEM().IsWorking();
	}
	
	override bool IsIgnited()
	{
		return GetCompEM().IsWorking();
	}
	
	override bool CanIgniteItem(EntityAI ignite_target = NULL)
	{
		return GetCompEM().IsWorking();
	}
	
	override bool HasFlammableMaterial()
	{
		return true;
	}
	
	// Checkes if Torch can be ignited
	override bool CanBeIgnitedBy(EntityAI igniter = NULL)
	{
		if ( !GetCompEM().CheckWetness() )
			return false;
		
		ItemBase rag = GetRag();
		
		if (rag  &&  GetCompEM().GetEnergy() < GetCompEM().GetEnergyUsage() * GetCompEM().GetUpdateInterval() )
		{
			float wetness = rag.GetWet();
			bool is_dry_enough = wetness <= 1-GetCompEM().GetWetnessExposure();
			return is_dry_enough;
		}
		
		if ( !GetCompEM().CanWork() )
			return false;
		
		if ( GetCompEM().GetEnergy() >= 3 )
			return true;
		
		return false;
	}
	
	void UpdateCheckForReceivingUpgrade()
	{
		if ( GetGame().IsServer() )
		{
			float energy_limit = GetCompEM().GetEnergyMax() - GetCompEM().GetEnergy();
			
			if ( m_BurnTimePerRag < energy_limit )
			{
				m_CanReceiveUpgrade = true;
			}
			else
			{
				m_CanReceiveUpgrade = false;
			}
			
			SetSynchDirty();
		}
	}
	
	override void OnIgnitedThis(EntityAI fire_source)
	{
		if ( !GetCompEM().HasEnoughStoredEnergy() )
		{
			ConsumeRag();
		}
		
		GetCompEM().SwitchOn();
	}
	
	override void OnSwitchOn()
	{
		if ( !GetCompEM().HasEnoughStoredEnergy() )
			GetCompEM().SwitchOff();
		;
	}
	
	void SetTorchDecraftResult(string type)
	{
		m_DecraftResult = type; //not persistent for the moment
	}
	
	bool ConsumeRag()
	{
		ItemBase rag = GetRag();
		
		if (rag)
		{
			if (rag.GetQuantity() <= 1)
			{
				LockRags(false); // Unlock attachment slot before deletion. Otherwise it will get stuck locked and unusable.
			}
			
			rag.AddQuantity(-1);
			rag.SetHealth(0);
			GetCompEM().AddEnergy( m_BurnTimePerRag );
			return true;
		}
		
		return false;
	}
	
	void ConsumeLard(Lard lard)
	{
		if (lard)
		{
			float lard_quant = lard.GetQuantity();
			
			float available_lard_quant = lard_quant;
			
			if ( available_lard_quant > m_MaxConsumableLardQuantity )
				available_lard_quant = m_MaxConsumableLardQuantity;
			
			float available_lard_coef = available_lard_quant / m_MaxConsumableLardQuantity;
			
			float add_energy = m_BurnTimePerFullLard * available_lard_coef;
			float add_energy_coef = 1;
			
			float energy_limit = GetCompEM().GetEnergyMax() - GetCompEM().GetEnergy();
			
			if (add_energy > energy_limit )
			{
				add_energy_coef = energy_limit / add_energy;
				add_energy = energy_limit;
				available_lard_quant = available_lard_quant * add_energy_coef;
			}
			
			GetCompEM().AddEnergy( add_energy );
			lard.AddQuantity(-available_lard_quant);
			
			CalculateQuantity();
			
			UpdateCheckForReceivingUpgrade();
		}
	}
	
	void ConsumeFuelFromBottle(ItemBase vessel)
	{
		if (vessel)
		{
			float vessel_quant = vessel.GetQuantity();
			
			float available_vessel_quant = vessel_quant;
			
			if ( available_vessel_quant > m_MaxConsumableFuelQuantity )
				available_vessel_quant = m_MaxConsumableFuelQuantity;
			
			float available_vessel_coef = available_vessel_quant / m_MaxConsumableFuelQuantity;
			
			float add_energy = m_BurnTimePerFullFuelDose * available_vessel_coef;
			float add_energy_coef = 1;
			
			float energy_limit = GetCompEM().GetEnergyMax() - GetCompEM().GetEnergy();
			
			if (add_energy > energy_limit )
			{
				add_energy_coef = energy_limit / add_energy;
				add_energy = energy_limit;
				available_vessel_quant = available_vessel_quant * add_energy_coef;
			}
			
			GetCompEM().AddEnergy( add_energy );
			vessel.AddQuantity(-available_vessel_quant);
			
			CalculateQuantity();
			
			UpdateCheckForReceivingUpgrade();
		}
	}
	
	void ConsumeFuelFromGasStation()
	{
		float add_energy = m_BurnTimePerFullFuelDose;
		float add_energy_coef = 1;
		
		float energy_limit = GetCompEM().GetEnergyMax() - GetCompEM().GetEnergy();
		
		if (add_energy > energy_limit )
		{
			add_energy_coef = energy_limit / add_energy;
			add_energy = energy_limit;
		}
		
		GetCompEM().AddEnergy( add_energy );
		CalculateQuantity();
		UpdateCheckForReceivingUpgrade();
	}
	
	void RuinRags()
	{
		ItemBase rag = GetRag();
		
		if (rag)
		{
			rag.SetHealth(1); //does not actually ruin rags, combining would be impossible
		}
	}
	
	// Inventory manipulation
	override void OnInventoryExit(Man player)
	{
		super.OnInventoryExit(player);
		
		StandUp();
	}
	
	// Stands up the torch, if possible. Returns true on success.
	bool StandUp()
	{
		string surface_type;
		vector position = GetPosition();
		GetGame().SurfaceGetType ( position[0], position[2], surface_type );
		bool is_surface_soft = GetGame().IsSurfaceDigable(surface_type);
		
		if ( is_surface_soft && !IsRuined() )
		{
			vector ori_rotate = "0 0 0";
			ori_rotate[0] = Math.RandomFloat(0, 360);
			ori_rotate[1] = Math.RandomFloat(0, 10);
			SetOrientation(ori_rotate);
			
			return true; // I am standing up
		}
		
		return false; // I am NOT standing up
	}
	
	// Calculates torch's quantity, which represents the amount of fuel left
	void CalculateQuantity()
	{
		if (GetGame().IsServer())
		{
			int stack_max = InventorySlots.GetStackMaxForSlotId(InventorySlots.GetSlotIdFromString("Rags"));
			float q_max = GetCompEM().GetEnergyMax() + m_BurnTimePerRag * stack_max;
			float q_min = GetCompEM().GetEnergy();
			
			ItemBase rag = GetRag();
			if (rag)
			{
				q_min += m_BurnTimePerRag * rag.GetQuantity();
			}
			
			int quant = Math.Round( (q_min / q_max) * 100 );
			
			float wetness = GetWet();
			float wetness_exposure = GetCompEM().GetWetnessExposure();
			
			if (wetness > 0  &&  wetness_exposure > 0)
			{
				quant = quant * ( 1- (wetness / wetness_exposure ) );
			}
			
			SetQuantity(quant);
		}
	}
	
	bool CanReceiveUpgrade()
	{
		if ( GetGame().IsServer() )
		{
			float energy_limit = GetCompEM().GetEnergyMax() - GetCompEM().GetEnergy();
			
			if ( Torch.m_BurnTimePerRag < energy_limit )
			{
				return m_CanReceiveUpgrade;
			}
		}
		else
		{
			return m_CanReceiveUpgrade;
		}
		
		return false;
	}
	
	override void EEItemAttached( EntityAI item, string slot_name ) 
	{
		super.EEItemAttached( item, slot_name );
		CalculateQuantity();
		UpdateCheckForReceivingUpgrade();
	}
	
	bool CanTransformIntoStick()
	{
		if ( GetGame().IsServer()  &&  !IsIgnited()  &&  !GetRag() )
			return true;
		else
			return false;
		;
	}
	
	void TryTransformIntoStick()
	{
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if ( m_IsBeingDestructed || (player && player.IsPlayerDisconnected()) )
			return;
				
		if ( CanTransformIntoStick() )
		{
			m_IsBeingDestructed = true;
			if (player)
			{
				// Transform object into wooden stick
				StopAllParticles();
				
				TorchLambda lambda = new TorchLambda(this, m_DecraftResult);
				player.ServerReplaceItemInHandsWithNew(lambda);
			}
			else
			{
				// Create wooden stick and delete Torch
				vector pos = GetPosition();
				vector ori = GetOrientation();
				
				if ( GetType() == "WoodenStick" )
					ori = ori + Vector(0,90,0);
				
				ItemBase stick = ItemBase.Cast( GetGame().CreateObjectEx(m_DecraftResult, pos, ECE_PLACE_ON_SURFACE) );
				stick.SetPosition(pos);
				stick.PlaceOnSurface();
				
				if ( stick.GetType() == "LongWoodenStick" )
				{
					pos = stick.GetPosition() + Vector(0,-0.3,0);
					stick.SetPosition(pos);
				}
				
				stick.SetOrientation(ori);
				GetGame().ObjectDelete(this);
			}
		}
	}
	
	override void EEItemDetached( EntityAI item, string slot_name ) 
	{
		super.EEItemDetached( item, slot_name );
		
		if (m_IsBeingDestructed)
		{
			if (GetGame().IsServer())
			{
				EntityAI rags = EntityAI.Cast(GetGame().CreateObjectEx(item.GetType(), GetPosition(), ECE_PLACE_ON_SURFACE));
				if( rags )
					MiscGameplayFunctions.TransferItemProperties(item, rags);
			}
			return;
		}
		
		CalculateQuantity();
		UpdateCheckForReceivingUpgrade();
		
		TryTransformIntoStick();
	}
	
	override void OnWorkStart()
	{
		LockRags(true);
	}
	
	void StopAllParticles()
	{
		if (m_FireParticle)
		{
			m_FireParticle.Stop();
		}
	}
	
	Rag GetRag()
	{
		return Rag.Cast( GetAttachmentByType(Rag) );
	}
	
	void LockRags(bool do_lock)
	{
		ItemBase rag = GetRag();
		
		if (rag)
		{
			if (do_lock)
			{
				rag.LockToParent();
			}
			else
			{
				rag.UnlockFromParent();
			}
		}
	}
	
	void UpdateLight()
	{
		if (!m_Light)
		{
			m_Light = TorchLight.Cast( ScriptedLightBase.CreateLight( TorchLight, Vector(0,0,0), 1 ) );
			m_Light.AttachOnObject(this, m_ParticleLocalPos + Vector (0,0.2,0));
		}
		
		if (m_FireParticle)
		{
			Object direct_particle = m_FireParticle.GetDirectParticleEffect();
			
			if (direct_particle  &&  direct_particle != m_Light.GetAttachmentParent())
			{
				m_Light.AttachOnObject(direct_particle, Vector(0,0.2,0));
			}	
		}
		
		float update_interval = GetCompEM().GetUpdateInterval();
		
		if (GetQuantity() <= m_StartFadeOutOfLightAtQuantity)
		{
			float brightness_coef = GetQuantity() / m_StartFadeOutOfLightAtQuantity;
			float radius_coef = GetQuantity() / m_StartFadeOutOfLightAtQuantity;
			
			if (radius_coef < m_StartFadeOutOfLightAtQuantity/10)
				radius_coef = m_StartFadeOutOfLightAtQuantity/10;
			
			if (brightness_coef < m_StartFadeOutOfLightAtQuantity/10)
				brightness_coef = m_StartFadeOutOfLightAtQuantity/10;
			
			m_Light.FadeBrightnessTo(m_Light.m_TorchBrightness * brightness_coef, update_interval);
			m_Light.FadeRadiusTo(m_Light.m_TorchRadius * radius_coef, update_interval);
		}
		else
		{
			m_Light.FadeBrightnessTo(m_Light.m_TorchBrightness, update_interval);
			m_Light.FadeRadiusTo(m_Light.m_TorchRadius, update_interval);
		}
	}
	
	override void OnWork( float consumed_energy )
	{
		if ( GetGame().IsServer() )
		{
			if ( GetCompEM().GetEnergy()  <=  ( GetCompEM().GetEnergyUsage() * GetCompEM().GetUpdateInterval() ) )
			{
				ConsumeRag();
			}
			
			RuinRags();
			
			CalculateQuantity();
			
			UpdateCheckForReceivingUpgrade();
			
			AddWet( -m_WaterEvaporationByFireIntensity * GetCompEM().GetUpdateInterval() );
			
			Rag rag = GetRag();
			
			if ( rag )
			{
				rag.AddWet( -m_WaterEvaporationByFireIntensity * GetCompEM().GetUpdateInterval() );
			}
		}
		
		if ( !m_LoopSoundEntity && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			m_LoopSoundEntity = PlaySoundLoop("torchLoop", 50);
		}
		
		// Particle scaling by fuel
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			UpdateLight();
			
			if ( GetQuantity() < 40 )
			{
				if (!m_FireParticle)
					m_FireParticle = Particle.PlayOnObject(ParticleList.TORCH_T1, this, m_ParticleLocalPos, Vector(0,0,0), true);
				
				float scale = GetQuantity() / 40;
				
				if (scale > 1)
					scale = 1;
				
				if (scale < 0.25)
					scale = 0.25;
				
				m_FireParticle.ScaleParticleParamFromOriginal(EmitorParam.SIZE, scale);
				m_FireParticle.ScaleParticleParamFromOriginal(EmitorParam.VELOCITY, scale);
				m_FireParticle.ScaleParticleParamFromOriginal(EmitorParam.VELOCITY_RND, scale);
			}
			else
			{
				if ( !m_FireParticle  ||  m_FireParticle.GetParticleID() != ParticleList.TORCH_T2 )
				{
					// Executes once when fire particle starts or changes
					
					if (m_FireParticle)
						m_FireParticle.Stop();
					
					m_FireParticle = Particle.PlayOnObject(ParticleList.TORCH_T2, this, m_ParticleLocalPos, Vector(0,0,0), true);
				}
			}
		}
	}
	
	override void OnWorkStop()
	{
		if (m_Light)
			m_Light.FadeOut();
		
		if ( m_LoopSoundEntity && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			GetGame().ObjectDelete( m_LoopSoundEntity );
			m_LoopSoundEntity = NULL;
		}
		
		if ( m_FireParticle)
		{
			m_FireParticle.Stop();
			m_FireParticle = NULL;
		}
		
		CalculateQuantity();
		UpdateCheckForReceivingUpgrade();
		
		LockRags(false);
		
		TryTransformIntoStick();
	}
	
	// COMBAT
	// This needs refactor!
	override int GetMeleeMode()
	{
		if ( GetCompEM().IsWorking() )
			return 3; // ???
		else
			return 0; // ???
	}

	override int GetMeleeHeavyMode()
	{
		if ( GetCompEM().IsWorking() )
			return 4; // ???
		else
			return 1; // ???
	}
	
	override int GetMeleeSprintMode()
	{
		if ( GetCompEM().IsWorking() )
			return 5; // ???
		else
			return 2; // ???
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionLightItemOnFire);
		AddAction(ActionUpgradeTorchFromGasPump);
	}
	
	override void OnAttachmentQuantityChanged(ItemBase item)
	{
		super.OnAttachmentQuantityChanged(item);
		CalculateQuantity();
	}
};

class TorchLambda : ReplaceItemWithNewLambdaBase
{
	override void CopyOldPropertiesToNew (notnull EntityAI old_item, EntityAI new_item)
	{
		super.CopyOldPropertiesToNew(old_item, new_item);

		ItemBase stick;
		Class.CastTo(stick, new_item);
		stick.SetQuantity(1);
	}
};