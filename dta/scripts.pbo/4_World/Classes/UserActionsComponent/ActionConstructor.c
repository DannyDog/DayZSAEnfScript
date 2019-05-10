class ActionConstructor
{
#ifndef OLD_ACTIONS
	bool ConstructActions( out array<ref ActionBase> actionsArray, out map<typename, ActionBase> actionNameActionMap )
	{
		TTypenameArray action_array_names = new TTypenameArray;
		RegisterActions(action_array_names);
		Sort(action_array_names,action_array_names.Count());
		
		actionsArray = new array<ref ActionBase>;
		actionNameActionMap = new map<typename, ActionBase>;
		ActionBase new_action;
		
		for(int i = 0; i < action_array_names.Count(); i++)
		{
			new_action = ActionBase.Cast(action_array_names[i].Spawn());
			if(new_action)
			{
				new_action.CreateConditionComponents();
				new_action.SetID(actionsArray.Count());
				actionsArray.Insert(new_action);
				actionNameActionMap.Insert(action_array_names[i], new_action);
			}
		}
		return true;
	}
	
	void RegisterActions(TTypenameArray actions)
	{
		// SingleUse Actions	
		actions.Insert(ActionOpen);
		actions.Insert(ActionClose);
		actions.Insert(ActionConsumeSingle);
		actions.Insert(ActionForceConsumeSingle);
		actions.Insert(ActionTurnOnChemlight);
		actions.Insert(ActionMeasureTemperatureSelf);
		actions.Insert(ActionMeasureTemperatureTarget);
		actions.Insert(ActionDisinfectSelf);
		actions.Insert(ActionDisinfectTarget);
		actions.Insert(ActionPlugIn);
		actions.Insert(ActionPlugIntoFence);
		actions.Insert(ActionTogglePlaceObject);
		actions.Insert(ActionTurnOnWhileInHands);
		actions.Insert(ActionTurnOffWhileInHands);
		actions.Insert(ActionPlantSeed);
		actions.Insert(ActionDisinfectPlantBit);
		actions.Insert(ActionTurnOnHeatpack);
		actions.Insert(ActionToggleFishing);
//		actions.Insert(ActionAttachToCharger);
		actions.Insert(ActionTurnOnTransmitter);	
		actions.Insert(ActionTurnOffTransmitter);
		actions.Insert(ActionWashHandsItem);
		actions.Insert(ActionTakeABiteCan);
		actions.Insert(ActionForceABiteCan);
		actions.Insert(ActionPlaceFireplaceIndoor);
		actions.Insert(ActionAttach);
		actions.Insert(ActionAttachOnProxy);
		actions.Insert(ActionAttachWheels);
		actions.Insert(ActionPlugTargetIntoThis);
		actions.Insert(ActionInsertSparkplug);
		actions.Insert(ActionEmptySeedsPack);
		actions.Insert(ActionWorldCraftSwitch);
		actions.Insert(ActionWorldLiquidActionSwitch);
		actions.Insert(ActionAttachPowerSourceToPanel);
//		actions.Insert(ActionAttachMetalWire);
		actions.Insert(ActionInjectSelf);
		actions.Insert(ActionInjectTarget);
		actions.Insert(ActionInjectEpinephrineSelf);
		actions.Insert(ActionInjectEpinephrineTarget);
		actions.Insert(ActionInjectMorphineSelf);
		actions.Insert(ActionInjectMorphineTarget);
		actions.Insert(ActionHandcuffTarget);
		actions.Insert(ActionBuildPartSwitch);
		actions.Insert(ActionAttachOnSelection);
		actions.Insert(ActionTurnOnWeaponFlashlight);
		actions.Insert(ActionTurnOffWeaponFlashlight);
		actions.Insert(ActionNextCombinationLockDial);
		actions.Insert(ActionAttachToConstruction);
		actions.Insert(ActionTakeMaterialToHandsSwitch);
		actions.Insert(ActionFoldBandanaToMask);
		actions.Insert(ActionFoldBandanaToHead);
		actions.Insert(ActionUnfoldBandana);
		actions.Insert(ActionClapBearTrapWithThisItem);
		actions.Insert(ActionZoomIn);
		actions.Insert(ActionZoomOut);
		actions.Insert(ActionPlaceFireplaceIntoBarrel);
		actions.Insert(ActionStopEngine);
		actions.Insert(ActionUnfoldMap);
		actions.Insert(ActionDropItem);
		actions.Insert(ActionSwitchSeats);
		actions.Insert(ActionTurnOnHeadtorch);
		actions.Insert(ActionTurnOffHeadtorch);
		actions.Insert(ActionTurnOnHelmetFlashlight);
		actions.Insert(ActionTurnOffHelmetFlashlight);
		actions.Insert(ActionToggleNVG);

		// Continuous use actions
		actions.Insert(ActionWorldCraft);
//		actions.Insert(ActionDigStash);
		actions.Insert(ActionSkinning);
		actions.Insert(ActionPlaceObject);
		actions.Insert(ActionDeployObject);
		actions.Insert(ActionMineTree);
		actions.Insert(ActionMineBush);
		actions.Insert(ActionMineRock);
		actions.Insert(ActionDrinkDisinfectant);
		actions.Insert(ActionForceDrinkDisinfectant);	
		actions.Insert(ActionDrinkDisinfectant2);
		actions.Insert(ActionDigGardenPlot);
		actions.Insert(ActionWaterPlant);
		actions.Insert(ActionFertilizeSlot);
		actions.Insert(ActionDisinfectPlant);
		actions.Insert(ActionFillObject);
		actions.Insert(ActionDefibrilateSelf);
		actions.Insert(ActionDefibrilateTarget);
		actions.Insert(ActionTestBloodSelf);
		actions.Insert(ActionTestBloodTarget);
		actions.Insert(ActionGiveBloodSelf);
		actions.Insert(ActionGiveBloodTarget);
		actions.Insert(ActionGiveSalineSelf);
		actions.Insert(ActionGiveSalineTarget);
		actions.Insert(ActionCollectBloodSelf);
		actions.Insert(ActionCollectBloodTarget);
		actions.Insert(ActionCollectSampleSelf);
		actions.Insert(ActionCollectSampleTarget);
		actions.Insert(ActionCoverHeadSelf);
		actions.Insert(ActionUncoverHeadSelf);
		actions.Insert(ActionCoverHeadTarget);
		actions.Insert(ActionShave);
		actions.Insert(ActionSplintSelf);
		actions.Insert(ActionSplintTarget);
		actions.Insert(ActionConsume);
		actions.Insert(ActionForceConsume);
		actions.Insert(ActionForceDrink);
		actions.Insert(ActionForceFeed);
		actions.Insert(ActionEat);
		actions.Insert(ActionEatMeat);
		actions.Insert(ActionEatFruit);
		actions.Insert(ActionDrink);
		actions.Insert(ActionDrinkCookingPot);
		actions.Insert(ActionBandageSelf);
		actions.Insert(ActionBandageTarget);
		actions.Insert(ActionRestrainTarget);
		actions.Insert(ActionRestrainSelf);
		actions.Insert(ActionUnrestrainTarget);
		actions.Insert(ActionUnrestrainSelf);
		actions.Insert(ActionPlaceOnGround);
		actions.Insert(ActionForceDrinkAlcohol);
		actions.Insert(ActionDrinkAlcohol);
		actions.Insert(ActionFishing);
		actions.Insert(ActionFillBottleBase);
		actions.Insert(ActionTuneFrequency);
		actions.Insert(ActionTuneRadioStation);
		actions.Insert(ActionIgniteFireplaceByAir);
		actions.Insert(ActionLightItemOnFire);
		actions.Insert(ActionExtinguishFireplaceByLiquid);
		actions.Insert(ActionExtinguishFireplaceByExtinguisher);
		actions.Insert(ActionBurnSewSelf);
		actions.Insert(ActionBurnSewTarget);
		actions.Insert(ActionSewSelf);
		actions.Insert(ActionSewTarget);
		actions.Insert(ActionBuryAshes);
		actions.Insert(ActionCookOnStick);
		actions.Insert(ActionFillGeneratorTank);
		actions.Insert(ActionSawPlanks);
		actions.Insert(ActionBuryBody);
		actions.Insert(ActionEatCan);
		actions.Insert(ActionForceFeedCan);
		actions.Insert(ActionForceFeedMeat);
		actions.Insert(ActionWaterGardenSlot);
		actions.Insert(ActionWringClothes);
		actions.Insert(ActionLoadMagazine);
		actions.Insert(ActionEmptyMagazine);
		actions.Insert(ActionBuildPart);
		actions.Insert(ActionDismantlePart);
		actions.Insert(ActionDestroyPart);
		actions.Insert(ActionCPR);
		actions.Insert(ActionDrinkPondContinuous);
		actions.Insert(ActionEatSmall);
		actions.Insert(ActionMineTreeBark);
		actions.Insert(ActionDigWorms);
		actions.Insert(ActionShaveTarget);
		actions.Insert(ActionDrinkWellContinuous);
		actions.Insert(ActionUncoverHeadTarget);
		actions.Insert(ActionLockDoors);
		actions.Insert(ActionUnlockDoors);
		actions.Insert(ActionUnpackBox);
		//actions.Insert(ActionWashHandsWater);
		//actions.Insert(ActionWashHandsWell);
		actions.Insert(ActionDrinkCan);
		actions.Insert(ActionStripCarrierVest);
		actions.Insert(ActionBuildOven);
		actions.Insert(ActionDismantleOven);
		actions.Insert(ActionWritePaper);
		actions.Insert(ActionFillFuel);
		actions.Insert(ActionPourLiquid);
		actions.Insert(ActionDrainLiquid);
		actions.Insert(ActionStartEngine);
		actions.Insert(ActionRaiseMegaphone);
		actions.Insert(ActionActivateTrap);
		actions.Insert(ActionEmptyBottleBase);
		actions.Insert(ActionEmptyCookingPot);
		actions.Insert(ActionViewOptics);
		actions.Insert(ActionViewBinoculars);
		actions.Insert(ActionFoldBaseBuildingObject);
		//actions.Insert(ActionUseRangefinder);
		//actions.Insert(ActionAttached);
		actions.Insert(ActionMountBarbedWire);
		actions.Insert(ActionUnmountBarbedWire);
		actions.Insert(ActionDialCombinationLock);
		actions.Insert(ActionDialCombinationLockOnTarget);
		actions.Insert(ActionFillCoolant);
		actions.Insert(ActionFillOil);
		actions.Insert(ActionDestroyCombinationLock);
		actions.Insert(ActionGagSelf);
		actions.Insert(ActionGagTarget);
		actions.Insert(ActionUngagSelf);
		actions.Insert(ActionUngagTarget);
		actions.Insert(ActionDigInStash);
		//actions.Insert(ActionEmptyBarrel);
		
		// Interact actions
		actions.Insert(ActionPullOutPlug);
		actions.Insert(ActionUnplugThisByCord);
		actions.Insert(ActionTurnOnWhileOnGround);
		actions.Insert(ActionTurnOffWhileOnGround);
		actions.Insert(ActionTurnOnPowerGenerator);
		actions.Insert(ActionTurnOffPowerGenerator);
		actions.Insert(ActionTurnOnSpotlight);
		actions.Insert(ActionTurnOffSpotlight);
		actions.Insert(ActionITest);
		actions.Insert(ActionRemovePlant);
		actions.Insert(ActionHarvestCrops);
		actions.Insert(ActionFoldObject);
		//actions.Insert(ActionDrinkPond); //! old take a sip action
		//actions.Insert(ActionDrinkWell); //! old take a sip action
		actions.Insert(ActionRepositionPluggedItem);
		//actions.Insert(ActionPickBerry);
		actions.Insert(ActionTurnOnTransmitterOnGround);
		actions.Insert(ActionTurnOffTransmitterOnGround);
		actions.Insert(ActionTuneFrequencyOnGround);
		actions.Insert(ActionToggleTentOpen);
		actions.Insert(ActionPackTent);
		actions.Insert(ActionOpenBarrel);
		actions.Insert(ActionCloseBarrel);
		actions.Insert(ActionOpenBarrelHoles);
		actions.Insert(ActionCloseBarrelHoles);
		actions.Insert(ActionTakeFireplaceIndoor);
		actions.Insert(ActionOpenDoors);
		actions.Insert(ActionCloseDoors);
		actions.Insert(ActionEnterLadder);
		actions.Insert(ActionExitLadder);
		actions.Insert(ActionGetInTransport);
		actions.Insert(ActionTakeItem);
		actions.Insert(ActionDetachPowerSourceFromPanel);
		actions.Insert(ActionSortAmmoPile);
		actions.Insert(ActionSwapItemToHands);
		actions.Insert(ActionTakeItemToHands);
		actions.Insert(ActionLockedDoors);
		actions.Insert(ActionTakeFireplaceFromBarrel);
		actions.Insert(ActionOpenCarDoors);
		actions.Insert(ActionCloseCarDoors);
		actions.Insert(ActionWashHandsWellOne);
		actions.Insert(ActionWashHandsWaterOne);
		actions.Insert(ActionGetOutTransport);
		actions.Insert(ActionAnimateSeats); //<- action doesn't work well, add it later
		actions.Insert(ActionAnimateCarSelection); //<- action doesn't work well, add it later
		actions.Insert(ActionDetach);
		actions.Insert(ActionOpenFence);
		actions.Insert(ActionCloseFence);
		actions.Insert(ActionNextCombinationLockDialOnTarget);
		actions.Insert(ActionTakeMaterialToHands);
		
		//vehicle actions
		actions.Insert(ActionSwitchLights);
		
		//Instant action - debug
		actions.Insert(ActionDebug);
			
		//Weapon
		actions.Insert(FirearmActionAttachMagazine);
		actions.Insert(FirearmActionLoadMultiBullet);
		actions.Insert(FirearmActionLoadBullet);
		
		actions.Insert(ActionTakeItem);
	
	}
	
#else	
	void ConstructActions(out array<ref ActionBase> actions)
	{
		// SingleUse Actions	
		actions.Insert(new ActionOpen);
		actions.Insert(new ActionClose);
		actions.Insert(new ActionConsumeSingle);
		actions.Insert(new ActionForceConsumeSingle);
		//actions.Insert(new ActionTakeABite);
		//actions.Insert(new ActionTakeASip);
		//actions.Insert(new ActionForceABite);
		//actions.Insert(new ActionForceASip);
		//actions.Insert(new ActionMeasureBattery);
		actions.Insert(new ActionTurnOnChemlight);
		actions.Insert(new ActionMeasureTemperatureSelf);
		actions.Insert(new ActionMeasureTemperatureTarget);
		actions.Insert(new ActionDisinfectSelf);
		actions.Insert(new ActionDisinfectTarget);
		actions.Insert(new ActionPlugIn);
		actions.Insert(new ActionPlugIntoFence);
		actions.Insert(new ActionTogglePlaceObject);
		actions.Insert(new ActionTurnOnWhileInHands);
		actions.Insert(new ActionTurnOffWhileInHands);
		actions.Insert(new ActionPlantSeed);
		actions.Insert(new ActionDisinfectPlantBit);
		actions.Insert(new ActionReadPaper);
		actions.Insert(new ActionTurnOnHeatpack);
		actions.Insert(new ActionToggleFishing);
		actions.Insert(new ActionTurnOnTransmitter);	
		actions.Insert(new ActionTurnOffTransmitter);
		actions.Insert(new ActionWashHandsItem);
		actions.Insert(new ActionTakeABiteCan);
		actions.Insert(new ActionForceABiteCan);
		actions.Insert(new ActionPlaceFireplaceIndoor);
		actions.Insert(new ActionAttach);
		actions.Insert(new ActionAttachOnProxy);
		actions.Insert(new ActionAttachWheels);
		actions.Insert(new ActionPlugTargetIntoThis);
		actions.Insert(new ActionInsertSparkplug);
		actions.Insert(new ActionEmptySeedsPack);
		actions.Insert(new ActionWorldCraftSwitch);
		actions.Insert(new ActionWorldLiquidActionSwitch);
		//actions.Insert(new ActionWorldCraftCancel);
		actions.Insert(new ActionAttachPowerSourceToPanel);
		actions.Insert(new ActionInjectSelf);
		actions.Insert(new ActionInjectTarget);
		actions.Insert(new ActionInjectEpinephrineSelf);
		actions.Insert(new ActionInjectEpinephrineTarget);
		actions.Insert(new ActionInjectMorphineSelf);
		actions.Insert(new ActionInjectMorphineTarget);
		actions.Insert(new ActionHandcuffTarget);
		actions.Insert(new ActionBuildPartSwitch);
		actions.Insert(new ActionAttachOnSelection);
		actions.Insert(new ActionTurnOnWeaponFlashlight);
		actions.Insert(new ActionTurnOffWeaponFlashlight);
		actions.Insert(new ActionNextCombinationLockDial);
		actions.Insert(new ActionAttachToConstruction);
		actions.Insert(new ActionTakeMaterialToHandsSwitch);
		actions.Insert(new ActionFoldBandanaToMask);
		actions.Insert(new ActionFoldBandanaToHead);
		actions.Insert(new ActionUnfoldBandana);
		
		//actions.Insert(new ActionLoadMagazineToWeapon);
		//actions.Insert(new ActionLoadBulletToWeapon);
		actions.Insert(new ActionClapBearTrapWithThisItem);
		actions.Insert(new ActionZoomIn);
		actions.Insert(new ActionZoomOut);
		actions.Insert(new ActionPlaceFireplaceIntoBarrel);
		actions.Insert(new ActionStopEngine);
		actions.Insert(new ActionUnfoldMap);
		actions.Insert(new ActionDropItem);
		actions.Insert(new ActionSwitchSeats);
		actions.Insert(new ActionTurnOnHeadtorch);
		actions.Insert(new ActionTurnOffHeadtorch);
		actions.Insert(new ActionTurnOnHelmetFlashlight);
		actions.Insert(new ActionTurnOffHelmetFlashlight);
		actions.Insert(new ActionToggleNVG);

		// Continuous use actions
		//actions.Insert(new ActionCraft);
		actions.Insert(new ActionWorldCraft);
		actions.Insert(new ActionDigInStash);
		actions.Insert(new ActionDigOutStash);
		actions.Insert(new ActionSkinning);
		actions.Insert(new ActionPlaceObject);
		actions.Insert(new ActionDeployObject);
		actions.Insert(new ActionMineTree);
		actions.Insert(new ActionMineBush);
		actions.Insert(new ActionMineRock);
		actions.Insert(new ActionDrinkDisinfectant);
		actions.Insert(new ActionForceDrinkDisinfectant);	
		actions.Insert(new ActionDrinkDisinfectant2);
		actions.Insert(new ActionDigGardenPlot);
		actions.Insert(new ActionWaterPlant);
		actions.Insert(new ActionFertilizeSlot);
		actions.Insert(new ActionDisinfectPlant);
		actions.Insert(new ActionFillObject);
		actions.Insert(new ActionDefibrilateSelf);
		actions.Insert(new ActionDefibrilateTarget);
		actions.Insert(new ActionTestBloodSelf);
		actions.Insert(new ActionTestBloodTarget);
		actions.Insert(new ActionGiveBloodSelf);
		actions.Insert(new ActionGiveBloodTarget);
		actions.Insert(new ActionGiveSalineSelf);
		actions.Insert(new ActionGiveSalineTarget);
		actions.Insert(new ActionCollectBloodSelf);
		actions.Insert(new ActionCollectBloodTarget);
		actions.Insert(new ActionCollectSampleSelf);
		actions.Insert(new ActionCollectSampleTarget);
		actions.Insert(new ActionCoverHeadSelf);
		actions.Insert(new ActionUncoverHeadSelf);
		actions.Insert(new ActionCoverHeadTarget);
		actions.Insert(new ActionShave);
		actions.Insert(new ActionSplintSelf);
		actions.Insert(new ActionSplintTarget);
		actions.Insert(new ActionConsume);
		actions.Insert(new ActionForceConsume);
		actions.Insert(new ActionForceDrink);
		actions.Insert(new ActionForceFeed);
		actions.Insert(new ActionEat);
		actions.Insert(new ActionEatMeat);
		actions.Insert(new ActionEatFruit);
		actions.Insert(new ActionDrink);
		actions.Insert(new ActionDrinkCookingPot);
		actions.Insert(new ActionBandageSelf);
		actions.Insert(new ActionBandageTarget);
		actions.Insert(new ActionRestrainTarget);
		actions.Insert(new ActionRestrainSelf);
		actions.Insert(new ActionUnrestrainTarget);
		actions.Insert(new ActionUnrestrainSelf);
		actions.Insert(new ActionPlaceOnGround);
		actions.Insert(new ActionForceDrinkAlcohol);
		actions.Insert(new ActionDrinkAlcohol);
		actions.Insert(new ActionFishing);
		actions.Insert(new ActionFillBottleBase);
		actions.Insert(new ActionTuneFrequency);
		actions.Insert(new ActionTuneRadioStation);
		actions.Insert(new ActionIgniteFireplaceByAir);
		actions.Insert(new ActionLightItemOnFire);
		actions.Insert(new ActionExtinguishFireplaceByLiquid);
		actions.Insert(new ActionExtinguishFireplaceByExtinguisher);
		actions.Insert(new ActionBurnSewSelf);
		actions.Insert(new ActionBurnSewTarget);
		actions.Insert(new ActionSewSelf);
		actions.Insert(new ActionSewTarget);
		actions.Insert(new ActionBuryAshes);
		actions.Insert(new ActionCookOnStick);
		actions.Insert(new ActionFillGeneratorTank);
		actions.Insert(new ActionSawPlanks);
		actions.Insert(new ActionBuryBody);
		actions.Insert(new ActionEatCan);
		actions.Insert(new ActionForceFeedCan);
		actions.Insert(new ActionForceFeedMeat);
		actions.Insert(new ActionWaterGardenSlot);
		actions.Insert(new ActionWringClothes);
		actions.Insert(new ActionLoadMagazine);
		actions.Insert(new ActionEmptyMagazine);
		actions.Insert(new ActionBuildPart);
		actions.Insert(new ActionDismantlePart);
		actions.Insert(new ActionDestroyPart);
		actions.Insert(new ActionCPR);
		actions.Insert(new ActionDrinkPondContinuous);
		actions.Insert(new ActionEatSmall);
		actions.Insert(new ActionMineTreeBark);
		actions.Insert(new ActionDigWorms);
		actions.Insert(new ActionShaveTarget);
		actions.Insert(new ActionDrinkWellContinuous);
		actions.Insert(new ActionUncoverHeadTarget);
		actions.Insert(new ActionLockDoors);
		actions.Insert(new ActionUnlockDoors);
		actions.Insert(new ActionUnpackBox);
		actions.Insert(new ActionWashHandsWater);
		actions.Insert(new ActionWashHandsWell);
		actions.Insert(new ActionDrinkCan);
		actions.Insert(new ActionStripCarrierVest);
		actions.Insert(new ActionBuildOven);
		actions.Insert(new ActionDismantleOven);
		actions.Insert(new ActionWritePaper);
		actions.Insert(new ActionFillFuel);
		actions.Insert(new ActionPourLiquid);
		actions.Insert(new ActionDrainLiquid);
		actions.Insert(new ActionStartEngine);
		//actions.Insert(new ActionViewCompass);
		actions.Insert(new ActionRaiseMegaphone);
		actions.Insert(new ActionActivateTrap);
		actions.Insert(new ActionEmptyBottleBase);
		actions.Insert(new ActionEmptyCookingPot);
		actions.Insert(new ActionViewOptics);
		actions.Insert(new ActionViewBinoculars);
		actions.Insert(new ActionFoldBaseBuildingObject);
		//actions.Insert(new ActionUseRangefinder);
		//actions.Insert(new ActionAttached);
		actions.Insert(new ActionMountBarbedWire);
		actions.Insert(new ActionUnmountBarbedWire);
		actions.Insert(new ActionDialCombinationLock);
		actions.Insert(new ActionDialCombinationLockOnTarget);
		actions.Insert(new ActionFillCoolant);
		actions.Insert(new ActionFillOil);
		actions.Insert(new ActionFillBrakes);
		actions.Insert(new ActionDestroyCombinationLock);
		actions.Insert(new ActionGagSelf);
		actions.Insert(new ActionGagTarget);
		actions.Insert(new ActionUngagSelf);
		actions.Insert(new ActionUngagTarget);
		//actions.Insert(new ActionEmptyBarrel);
		
		// Interact actions
		actions.Insert(new ActionPullOutPlug);
		actions.Insert(new ActionUnplugThisByCord);
		actions.Insert(new ActionTurnOnWhileOnGround);
		actions.Insert(new ActionTurnOffWhileOnGround);
		actions.Insert(new ActionTurnOnPowerGenerator);
		actions.Insert(new ActionTurnOffPowerGenerator);
		actions.Insert(new ActionTurnOnSpotlight);
		actions.Insert(new ActionTurnOffSpotlight);
		actions.Insert(new ActionITest);
		actions.Insert(new ActionRemovePlant);
		actions.Insert(new ActionHarvestCrops);
		actions.Insert(new ActionFoldObject);
		actions.Insert(new ActionDrinkPond);
		actions.Insert(new ActionDrinkWell);
		actions.Insert(new ActionRepositionPluggedItem);
		//actions.Insert(new ActionPickBerry);
		actions.Insert(new ActionTurnOnTransmitterOnGround);
		actions.Insert(new ActionTurnOffTransmitterOnGround);
		actions.Insert(new ActionTuneFrequencyOnGround);
		actions.Insert(new ActionToggleTentOpen);
		actions.Insert(new ActionPackTent);
		actions.Insert(new ActionOpenBarrel);
		actions.Insert(new ActionCloseBarrel);
		actions.Insert(new ActionOpenBarrelHoles);
		actions.Insert(new ActionCloseBarrelHoles);
		actions.Insert(new ActionTakeFireplaceIndoor);
		actions.Insert(new ActionOpenDoors);
		actions.Insert(new ActionCloseDoors);
		actions.Insert(new ActionEnterLadder);
		actions.Insert(new ActionExitLadder);
		actions.Insert(new ActionGetInTransport);
		actions.Insert(new ActionTakeItem);
		actions.Insert(new ActionDetachPowerSourceFromPanel);
		actions.Insert(new ActionSortAmmoPile);
		actions.Insert(new ActionSwapItemToHands);
		actions.Insert(new ActionTakeItemToHands);
		actions.Insert(new ActionLockedDoors);
		actions.Insert(new ActionTakeFireplaceFromBarrel);
		actions.Insert(new ActionOpenCarDoors);
		actions.Insert(new ActionCloseCarDoors);
		actions.Insert(new ActionWashHandsWellOne);
		actions.Insert(new ActionWashHandsWaterOne);
		actions.Insert(new ActionGetOutTransport);
		actions.Insert(new ActionAnimateSeats); //<- action doesn't work well, add it later
		actions.Insert(new ActionAnimateCarSelection); //<- action doesn't work well, add it later
		actions.Insert(new ActionDetach);
		actions.Insert(new ActionOpenFence);
		actions.Insert(new ActionCloseFence);
		actions.Insert(new ActionNextCombinationLockDialOnTarget);
		actions.Insert(new ActionTakeMaterialToHands);
		
		//vehicle actions
		actions.Insert(new ActionSwitchLights);
		
		//Instant action - debug
		actions.Insert(new ActionDebug);
		
		
		//Weapon
		actions.Insert(new FirearmActionAttachMagazine);
		actions.Insert(new FirearmActionLoadMultiBullet);
		actions.Insert(new FirearmActionLoadBullet);
	}
#endif
};