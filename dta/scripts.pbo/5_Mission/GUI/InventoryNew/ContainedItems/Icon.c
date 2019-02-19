class Icon: LayoutHolder
{
	protected int					m_SizeX;
	protected int					m_SizeY;
	protected int					m_PosX;
	protected int					m_PosY;
	
	protected bool					m_IsWeapon			= false;
	protected bool					m_IsMagazine		= false;
	protected bool					m_HasTemperature	= false;
	protected bool					m_HasQuantity		= false;
	protected float					m_CurrQuantity		= -1;
	
	protected EntityAI				m_Obj;
	protected ItemBase				m_Item;
	protected bool					m_HandsIcon;
	protected int					m_CargoPos;
	protected bool					m_IsDragged;
	
	protected EntityAI				m_am_entity1, m_am_entity2;

	const int NUMBER_OF_TIMERS = 2;

	void Icon( LayoutHolder parent, bool hands_icon = false )
	{
		m_HandsIcon = hands_icon;
		ItemManager.GetInstance().SetSelectedItem( NULL, NULL, NULL );
		
		SetActive( false );
	}

	bool IsDragged()
	{
		return m_IsDragged;
	}

	override void SetActive( bool active )
	{
		if( active && GetObject() )
		{
			float x, y;
			GetMainWidget().GetScreenPos( x, y );
			ItemManager.GetInstance().PrepareTooltip( EntityAI.Cast( GetObject() ), x, y );
		}
		
		if( GetMainWidget() )
		{
			GetMainWidget().FindAnyWidget("Selected").Show( active );
		}
	}
	
	override void SetParentWidget()
	{
		#ifndef PLATFORM_CONSOLE
		if( m_Parent.IsInherited( HandsPreview ) )
		{ 
			super.SetParentWidget();
		}
		else
		{
			if( m_Parent != NULL )
			{
				CargoContainer grid_container = CargoContainer.Cast( m_Parent );
				if( grid_container )
				{
					m_ParentWidget = grid_container.GetMainWidget();
				}
			}
		}
		#else
		super.SetParentWidget();
		#endif
	}

	void RefreshQuickbar()
	{
		InventoryMenu menu = InventoryMenu.Cast( GetGame().GetUIManager().FindMenu( MENU_INVENTORY ) );
		ItemManager.GetInstance().HideTooltip();
		if( menu )
		{
			menu.RefreshQuickbar();
		}
	}

	void DoubleClick(Widget w, int x, int y, int button)
	{
		if( button == MouseState.LEFT )
		{
			PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
			if( player.GetInventory().HasInventoryReservation( m_Obj, NULL ) || player.GetInventory().IsInventoryLocked() )
			{
				return;
			}
			
			InventoryMenu menu = InventoryMenu.Cast( GetGame().GetUIManager().FindMenu( MENU_INVENTORY ) );
			if( w == NULL )
			{
				return;
			}
			ItemPreviewWidget iw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
			if( !iw )
			{
			  string name = w.GetName();
			  name.Replace( "PanelWidget", "Render" );
			  iw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
			}
			
			if( !iw )
			{
			  iw = ItemPreviewWidget.Cast( w );
			}
			
			if( !iw.GetItem() )
			{
				return;
			}
	
			EntityAI item = iw.GetItem();
			
			if( !item.GetInventory().CanRemoveEntity() )
				return;
			
			if( m_HandsIcon )
			{
				if( player.GetHumanInventory().CanRemoveEntityInHands() )
				{
					player.PredictiveMoveItemFromHandsToInventory();
				}
				ItemManager.GetInstance().HideTooltip();
				if( menu )
				{
					menu.RefreshQuickbar();
				}
				return;
			}
	
			InventoryLocation i1 = new InventoryLocation;
			EntityAI hands_item = player.GetHumanInventory().GetEntityInHands();
			EntityAI item_root_owner = item.GetHierarchyRoot();
			
			
			if( player.GetInventory().HasEntityInInventory( item ) && player.GetHumanInventory().CanAddEntityInHands( item ) )
			{
				player.PredictiveTakeEntityToHands( item );
			}
			else if( hands_item && item_root_owner == GetGame().GetPlayer() )
			{
				/*if( hands_item.GetInventory().CanAddAttachment( item ) )
				{
					CombineItems( hands_item, item ); //INVTODO Check if wanted.
				}
				else */if( player.GetInventory().CanSwapEntities( item, hands_item ) )
				{
					player.PredictiveTakeEntityToHands( item );
				}
				else if( player.GetInventory().CanForceSwapEntities( item, hands_item, i1 ) )
				{
					player.PredictiveForceSwapEntities( item, hands_item, i1);
				}
			}
			else
			{
				bool found = false;
				if( item.GetInventory().CanRemoveEntity())
				{
					InventoryLocation i2 = new InventoryLocation;
					found = player.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.ANY, i2 );
					if( found )
					{
						if( i2.GetType() == FindInventoryLocationType.ATTACHMENT )
						{
							if( i2.GetParent() != player )
								found = false;
						}
					}
				}
				if( found )
				{
					if(player.GetHumanInventory().CanAddEntityToInventory(item))
						player.PredictiveTakeEntityToInventory(FindInventoryLocationType.ANY, item);
				}
				else
				{
					if( player.GetHumanInventory().CanAddEntityInHands( item ) )
					{
						player.PredictiveTakeEntityToHands( item );
					}
				}
			}
	
			ItemManager.GetInstance().HideTooltip();
			if( menu )
			{
				menu.RefreshQuickbar();
			}
		}
	}

	void DraggingOverSwap( Widget w, int x, int y, Widget receiver )
	{
		if( w == NULL )
		{
			return;
		}
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );

		ItemPreviewWidget receiver_ipw = ItemPreviewWidget.Cast( receiver.FindAnyWidget( "Render" ) );
		if( m_HandsIcon )
		{
			receiver_ipw = ItemPreviewWidget.Cast( receiver.GetParent().FindAnyWidget( "Render" ) );
		}

		ItemPreviewWidget w_ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		if( w_ipw == NULL )
		{
			w_ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
		}
		if( w_ipw == NULL )
		{
			return;
		}

		InventoryItem receiver_entity = InventoryItem.Cast( receiver_ipw.GetItem() );
		InventoryItem w_entity = InventoryItem.Cast( w_ipw.GetItem() );
		if( !w_entity )
		{
			return;
		}

		if( GameInventory.CanSwapEntities( receiver_entity, w_entity ) )
		{
			ColorManager.GetInstance().SetColor( w, ColorManager.SWAP_COLOR );
			ItemManager.GetInstance().HideDropzones();
			ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "HandsPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
		}
		else
		{
			if( m_HandsIcon )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.SWAP_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "HandsPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
			else
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
				ItemManager.GetInstance().ShowSourceDropzone( w_entity );
			}
		}
	}

	void DraggingOverCombine( Widget w, int x, int y, Widget receiver )
	{
		if( w == NULL )
		{
			return;
		}
		ItemPreviewWidget iw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
		if( !iw )
		{
		  string name = w.GetName();
		  name.Replace( "PanelWidget", "Render" );
		  iw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		}
		if( !iw )
		{
		  iw = ItemPreviewWidget.Cast( w );
		}
		if( !iw.GetItem() )
		{
			return;
		}

		int flags = GetCombinationFlags( GetGame().GetPlayer().GetHumanInventory().GetEntityInHands(), iw.GetItem() );
		ShowActionMenuCombine( GetGame().GetPlayer().GetHumanInventory().GetEntityInHands(), iw.GetItem(), flags , w , true);
	}

	bool MouseEnter(Widget w, int x, int y)
	{
		ItemManager.GetInstance().PrepareTooltip( EntityAI.Cast( m_Obj ) );
		return true;
	}

	bool MouseLeave( Widget w, Widget s, int x, int y	)
	{
		ItemManager.GetInstance().HideTooltip();
		return true;
	}

	void DraggingOver( Widget w, int x, int y, Widget receiver )
	{
		ItemManager.GetInstance().HideDropzones();
		EntityAI entity = EntityAI.Cast( m_Obj );

		if( w == NULL )
		{
			return;
		}
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );

		ItemPreviewWidget receiver_ipw = ItemPreviewWidget.Cast( receiver.FindAnyWidget( "Render" ) );
		if( m_HandsIcon )
		{
			receiver_ipw = ItemPreviewWidget.Cast( receiver.GetParent().FindAnyWidget( "Render" ) );
		}

		ItemPreviewWidget w_ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		if( w_ipw == NULL )
		{
			w_ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
		}
		if( w_ipw == NULL )
		{
			return;
		}

		InventoryItem receiver_entity = InventoryItem.Cast( receiver_ipw.GetItem() );
		InventoryItem w_entity = InventoryItem.Cast( w_ipw.GetItem() );
		if( !receiver_entity || !w_entity )
		{
			return;
		}

		if( ( ItemBase.Cast( receiver_entity ) ).CanBeCombined( ItemBase.Cast( w_entity ) ) )
		{
			ColorManager.GetInstance().SetColor( w, ColorManager.COMBINE_COLOR );
			if( entity.GetHierarchyParent().GetHierarchyParent() == GetGame().GetPlayer() )
			{
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
			else if( !m_HandsIcon )
			{
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "LeftPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
		}
		else if( GameInventory.CanSwapEntities( receiver_entity, w_entity ) )
		{
			ColorManager.GetInstance().SetColor( w, ColorManager.SWAP_COLOR );
			if( entity.GetHierarchyParent().GetHierarchyParent() == GetGame().GetPlayer() )
			{
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
			else if( !m_HandsIcon )
			{
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "LeftPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
		}
		else
		{
			ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
			ItemManager.GetInstance().ShowSourceDropzone( w_entity );
		}
	}

	int GetCombinationFlags( EntityAI entity1, EntityAI entity2 )
	{
		int flags = 0;
		PlayerBase m_player = PlayerBase.Cast( GetGame().GetPlayer() );
		EntityAI entity_in_hands = m_player.GetHumanInventory().GetEntityInHands();

		if( !entity1 || !entity2 ) return flags;

		//Magazine swapmag1;
		//Magazine swapmag2;
		//bool skipSwap = false;
/*
		if( Class.CastTo(swapmag1, entity1) && Class.CastTo(swapmag2, entity2) )
		{
			Weapon_Base parentWpn;

			if(	Class.CastTo(parentWpn, swapmag1.GetOwner())	)
			{
				skipSwap = true;
				if( m_player.GetWeaponManager().CanSwapMagazine(parentWpn,swapmag2) )
					flags = flags | InventoryCombinationFlags.SWAP_MAGAZINE;
			}

			if(	Class.CastTo(parentWpn, swapmag2.GetOwner())	)
			{
				skipSwap = true;
				if( m_player.GetWeaponManager().CanSwapMagazine(parentWpn,swapmag1) )
					flags = flags | InventoryCombinationFlags.SWAP_MAGAZINE;

			}
		}
*/
		if( entity1.IsInherited( ItemBase ) && entity2.IsInherited( ItemBase ) )
		{
			ItemBase ent1 = ItemBase.Cast( entity1 );
			if( ent1.CanBeCombined( ItemBase.Cast( entity2 ) ) ) flags = flags | InventoryCombinationFlags.COMBINE_QUANTITY2;
		}

		Weapon_Base wpn;
		Magazine mag;
		if( Class.CastTo(wpn,  entity1 ) && Class.CastTo(mag,  entity2 ) )
		{
			/*int muzzleIndex = wpn.GetCurrentMuzzle();
			if( m_player.GetWeaponManager().CanLoadBullet(wpn, mag) )
			{
				flags = flags | InventoryCombinationFlags.LOAD_CHAMBER;
			}
			else if( m_player.GetWeaponManager().CanAttachMagazine(wpn, mag) )
			{
				flags = flags | InventoryCombinationFlags.ATTACH_MAGAZINE;
			}
			else if( m_player.GetWeaponManager().CanSwapMagazine(wpn, mag))
			{
				flags = flags | InventoryCombinationFlags.SWAP_MAGAZINE;
			}*/
		}
		else if( entity1.GetInventory().CanAddAttachment( entity2 ) )
		{
			if( !entity1.IsInherited( ZombieBase ) && !entity1.IsInherited( Car ) && !entity2.IsInherited( ZombieBase ) && !entity2.IsInherited( Car ) )
			{
				flags = flags | InventoryCombinationFlags.ADD_AS_ATTACHMENT;
			}
		}
		if( entity1.GetInventory().CanAddEntityInCargo( entity2 ) ) flags = flags | InventoryCombinationFlags.ADD_AS_CARGO;

		if( entity1 == m_player.GetHumanInventory().GetEntityInHands() || entity2 == m_player.GetHumanInventory().GetEntityInHands())
		{
		//Debug.Log("GetCombinationFlags called, setting comb. flag","recipes");
			if( GetRecipeCount( false, entity1, entity2 ) > 0 )
			{
				flags = flags | InventoryCombinationFlags.RECIPE_HANDS;
			}

			ActionManagerClient amc;
			Class.CastTo(amc, m_player.GetActionManager());
			if( entity1 == m_player.GetHumanInventory().GetEntityInHands() )
			{
				if( amc.CanPerformActionFromInventory( ItemBase.Cast( entity1 ), ItemBase.Cast( entity2 ) ) )
				{
					flags = flags | InventoryCombinationFlags.PERFORM_ACTION;
				}
				else if( amc.CanSetActionFromInventory( ItemBase.Cast( entity1 ), ItemBase.Cast( entity2 ) ) )
				{
					flags = flags | InventoryCombinationFlags.SET_ACTION;
				}
			}
			else
			{
				if( amc.CanPerformActionFromInventory( ItemBase.Cast( entity2 ), ItemBase.Cast( entity1 ) ) )
				{
					flags = flags | InventoryCombinationFlags.PERFORM_ACTION;
				}
				else if( amc.CanSetActionFromInventory( ItemBase.Cast( entity2 ), ItemBase.Cast( entity1 ) ) )
				{
					flags = flags | InventoryCombinationFlags.SET_ACTION;
				}
			}
		}

		if( GetRecipeCount( true, entity1, entity2 ) > 0 )
		{
			flags = flags | InventoryCombinationFlags.RECIPE_ANYWHERE;
		}
		return flags;
	}

	int GetRecipeCount( bool recipe_anywhere, EntityAI entity1, EntityAI entity2 )
	{
		PluginRecipesManager plugin_recipes_manager = PluginRecipesManager.Cast( GetPlugin( PluginRecipesManager ) );
		return plugin_recipes_manager.GetValidRecipes( ItemBase.Cast( entity1 ), ItemBase.Cast( entity2 ), NULL, PlayerBase.Cast( GetGame().GetPlayer() ) );
	}

	void RefreshDraggedQuant()
	{
		Icon dragged_icon = ItemManager.GetInstance().GetDraggedIcon();
		if( dragged_icon )
		{
			dragged_icon.SetQuantity( dragged_icon.GetMainWidget() );
		}
	}

	void OnPerformCombination( int combinationFlags )
	{
		PlayerBase m_player = PlayerBase.Cast( GetGame().GetPlayer() );
		if( m_am_entity1 == NULL || m_am_entity2 == NULL ) return;

		if( combinationFlags == InventoryCombinationFlags.NONE ) return;

		Weapon_Base wpn;
		Magazine mag;

		if( combinationFlags & InventoryCombinationFlags.LOAD_CHAMBER )
		{
			if( Class.CastTo(wpn,  m_am_entity1 ) && Class.CastTo(mag,  m_am_entity2 ) )
			{
				if( m_player.GetWeaponManager().CanLoadBullet(wpn, mag) )
				{
					m_player.GetWeaponManager().LoadBullet(mag);
					RefreshDraggedQuant();
					return;
				}
			}
		}
		if( combinationFlags & InventoryCombinationFlags.ADD_AS_ATTACHMENT )
		{
			m_player.PredictiveTakeEntityToTargetAttachment(m_am_entity1, m_am_entity2);
		}
		if( combinationFlags & InventoryCombinationFlags.ADD_AS_CARGO )
		{
			m_player.PredictiveTakeEntityToTargetCargo(m_am_entity1, m_am_entity2);
		}
		if( combinationFlags & InventoryCombinationFlags.SWAP )
		{
			if( !m_player.PredictiveSwapEntities( m_am_entity1, m_am_entity2 ) && m_player.GetHumanInventory().CanAddEntityInHands( m_am_entity2 ) )
			{
				m_player.PredictiveTakeEntityToHands( m_am_entity2 );
			}
		}
		if( combinationFlags & InventoryCombinationFlags.TAKE_TO_HANDS )
		{
			if( m_player.GetHumanInventory().CanAddEntityInHands( m_am_entity2 ) )
			{
				m_player.PredictiveTakeEntityToHands( m_am_entity2 );
			}
		}
		if( combinationFlags & InventoryCombinationFlags.PERFORM_ACTION )
		{
			ActionManagerClient amc;
			Class.CastTo(amc, m_player.GetActionManager());

			if( m_am_entity1 == m_player.GetHumanInventory().GetEntityInHands() )
			{
				amc.PerformActionFromInventory(ItemBase.Cast( m_am_entity1 ),ItemBase.Cast( m_am_entity2 ));
			}
			else
			{
				amc.PerformActionFromInventory(ItemBase.Cast( m_am_entity2 ),ItemBase.Cast( m_am_entity1 ));
			}
		}
		if( combinationFlags & InventoryCombinationFlags.SET_ACTION )
		{
			ActionManagerClient amc2;
			Class.CastTo(amc2, m_player.GetActionManager());

			if( m_am_entity1 == m_player.GetHumanInventory().GetEntityInHands() )
			{
				amc2.SetActionFromInventory(ItemBase.Cast( m_am_entity1 ),ItemBase.Cast( m_am_entity2 ));
			}
			else
			{
				amc2.SetActionFromInventory(ItemBase.Cast( m_am_entity2 ),ItemBase.Cast( m_am_entity1 ));
			}
		}
	}

	void ShowActionMenu(InventoryItem item)
	{
		PlayerBase m_player = PlayerBase.Cast( GetGame().GetPlayer() );
		ItemManager.GetInstance().HideTooltip();
		m_am_entity1 = item;
		m_am_entity2 = NULL;
		ContextMenu cmenu = GetGame().GetUIManager().GetMenu().GetContextMenu();

		cmenu.Hide();
		cmenu.Clear();

		if(m_am_entity1 == NULL)
			return;

		ref TSelectableActionInfoArray customActions = new TSelectableActionInfoArray;
		ItemBase itemBase = ItemBase.Cast( item );
		itemBase.GetRecipesActions(m_player, customActions);

		if( ItemBase.GetDebugActionsMask() & DebugActionType.GENERIC_ACTIONS )
		{
			itemBase.GetDebugActions(customActions);
		}
		if( ItemBase.GetDebugActionsMask() & DebugActionType.PLAYER_AGENTS )
		{
			m_player.GetDebugActions(customActions);
		}

		int actionsCount = customActions.Count();
		for ( int i = 0; i < customActions.Count(); i++ )
		{
			TSelectableActionInfo actionInfo = customActions.Get(i);
			if( actionInfo )
			{
				int actionId = actionInfo.param2;
				string actionText = actionInfo.param3;

				cmenu.Add(actionText, this, "OnSelectAction", new Param2<ItemBase, int>(itemBase, actionId));
			}
		}

		int m_am_Pos_x,  m_am_Pos_y;
		GetMousePos( m_am_Pos_x, m_am_Pos_y );
				m_am_Pos_x -= 5;
		m_am_Pos_y -= 5;
		cmenu.Show(m_am_Pos_x, m_am_Pos_y);
	}

	void OnSelectAction(ItemBase item, int actionId)
	{
		PlayerBase m_player = PlayerBase.Cast( GetGame().GetPlayer() );
		m_player.GetActionManager().OnInstantAction(AT_DEBUG,new Param2<ItemBase,int>(item,actionId));
	}

	void ShowActionMenuCombine( EntityAI entity1, EntityAI entity2, int combinationFlags, Widget w , bool color_test )
	{
		int current_flag;
		ContextMenu cmenu = GetGame().GetUIManager().GetMenu().GetContextMenu();
		m_am_entity1 = entity1;
		m_am_entity2 = entity2;
		cmenu.Hide();
		cmenu.Clear();
		int id = -1;

		if( combinationFlags & InventoryCombinationFlags.COMBINE_QUANTITY2 )
		{
			if( color_test )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.COMBINE_COLOR );
				ItemManager.GetInstance().HideDropzones();
				ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "HandsPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			}
			else
			{
				ItemBase entity = ItemBase.Cast( entity1 );
				entity.CombineItemsClient( ItemBase.Cast( entity2 ) );
				RefreshDraggedQuant();
			}
			return;
		}

		if( entity1 == NULL || entity2 == NULL ) return;

		if( combinationFlags == InventoryCombinationFlags.NONE )
		{
			if( color_test )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
				ItemManager.GetInstance().ShowSourceDropzone( entity2 );
			}
			return;
		}

		if( combinationFlags & InventoryCombinationFlags.ADD_AS_ATTACHMENT )
		{
			current_flag = InventoryCombinationFlags.ADD_AS_ATTACHMENT;
			cmenu.Add( "#inv_context_add_as_attachment", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}
		if( combinationFlags & InventoryCombinationFlags.LOAD_CHAMBER )
		{
			current_flag = InventoryCombinationFlags.LOAD_CHAMBER;
			cmenu.Add( "#inv_context_load_chamber", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}
		if(combinationFlags & InventoryCombinationFlags.ATTACH_MAGAZINE)
		{
			current_flag = InventoryCombinationFlags.ATTACH_MAGAZINE;
			cmenu.Add("#inv_context_attach_magazine", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}

		if( combinationFlags & InventoryCombinationFlags.ADD_AS_CARGO )
		{
			current_flag = InventoryCombinationFlags.ADD_AS_CARGO;
			cmenu.Add( "#inv_context_add_as_cargo", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}

		if( combinationFlags & InventoryCombinationFlags.SWAP )
		{
			current_flag = InventoryCombinationFlags.SWAP;
			cmenu.Add( "#inv_context_swap", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}

		if( combinationFlags & InventoryCombinationFlags.COMBINE_QUANTITY )
		{
			current_flag = InventoryCombinationFlags.COMBINE_QUANTITY;
			cmenu.Add( "#inv_context_combine", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}

		if(combinationFlags & InventoryCombinationFlags.SET_ACTION)
		{
			current_flag = InventoryCombinationFlags.SET_ACTION;
			cmenu.Add("#inv_context_attach_magazine", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}
		
		if(combinationFlags & InventoryCombinationFlags.PERFORM_ACTION)
		{
			current_flag = InventoryCombinationFlags.PERFORM_ACTION;
			cmenu.Add("Perform action", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}

		int m_am_Pos_x,  m_am_Pos_y;
		GetMousePos( m_am_Pos_x, m_am_Pos_y );
		m_am_Pos_x -= 5;
		m_am_Pos_y -= 5;

		if( color_test )
		{
			ItemManager.GetInstance().HideDropzones();
			ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "HandsPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
			ColorManager.GetInstance().SetColor( w, ColorManager.COMBINE_COLOR );
		}
		if( combinationFlags & InventoryCombinationFlags.RECIPE_HANDS ||  combinationFlags & InventoryCombinationFlags.RECIPE_ANYWHERE )
		{
			if( !color_test )
			{
				OnPerformRecipe( id );
			}
		}
		else if( cmenu.Count() == 1 )
		{
			if( !color_test )
			{
				OnPerformCombination( current_flag );
			}
		}
		else
		{
			if( color_test )
			{
				ColorManager.GetInstance().SetColor( w, ColorManager.RED_COLOR );
				ItemManager.GetInstance().ShowSourceDropzone( entity2 );
			}
			else
			{
				cmenu.Show( m_am_Pos_x, m_am_Pos_y );
			}
		}
	}

	void OnPerformRecipe(int id)
	{
		if( m_am_entity1 == NULL || m_am_entity2 == NULL ) return;

		Debug.Log("OnPerformRecipe called for id:"+id.ToString(),"recipes");
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		player.GetCraftingManager().SetInventoryCraft( id, ItemBase.Cast( m_am_entity1 ), ItemBase.Cast( m_am_entity2 ) );
	}

	void Combine( Widget w, int x, int y, Widget receiver )
	{
		ItemPreviewWidget iw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
		if( !iw )
		{
		  string name = w.GetName();
		  name.Replace( "PanelWidget", "Render" );
		  iw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		}
		if( !iw )
		{
		  iw = ItemPreviewWidget.Cast( w );
		}
		if( !iw.GetItem() )
		{
			return;
		}

		int flags = GetCombinationFlags( GetGame().GetPlayer().GetHumanInventory().GetEntityInHands(), iw.GetItem() );
		ShowActionMenuCombine( GetGame().GetPlayer().GetHumanInventory().GetEntityInHands(), iw.GetItem(), flags , w, false );
	}
	
	void CombineItems( EntityAI entity1, EntityAI entity2 )
	{
		int flags = GetCombinationFlags( entity1, entity2 );
		FlagAction( entity1, entity2, flags );
	}
	
	void FlagAction( EntityAI entity1, EntityAI entity2, int combinationFlags )
	{
		int current_flag;
		ContextMenu cmenu = GetGame().GetUIManager().GetMenu().GetContextMenu();
		m_am_entity1 = entity1;
		m_am_entity2 = entity2;
		cmenu.Hide();
		cmenu.Clear();
		int id = -1;

		if( combinationFlags & InventoryCombinationFlags.COMBINE_QUANTITY2 )
		{
				ItemBase entity = ItemBase.Cast( entity1 );
				entity.CombineItemsClient( ItemBase.Cast( entity2 ) );
				RefreshDraggedQuant();
			return;
		}

		if( entity1 == NULL || entity2 == NULL ) return;

		if( combinationFlags == InventoryCombinationFlags.NONE )
		{
			return;
		}

		if( combinationFlags & InventoryCombinationFlags.ADD_AS_ATTACHMENT )
		{
			current_flag = InventoryCombinationFlags.ADD_AS_ATTACHMENT;
			cmenu.Add( "#inv_context_add_as_attachment", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}
		if( combinationFlags & InventoryCombinationFlags.LOAD_CHAMBER )
		{
			current_flag = InventoryCombinationFlags.LOAD_CHAMBER;
			cmenu.Add( "#inv_context_load_chamber", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}
		if(combinationFlags & InventoryCombinationFlags.ATTACH_MAGAZINE)
		{
			current_flag = InventoryCombinationFlags.ATTACH_MAGAZINE;
			cmenu.Add("#inv_context_attach_magazine", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}

		if( combinationFlags & InventoryCombinationFlags.ADD_AS_CARGO )
		{
			current_flag = InventoryCombinationFlags.ADD_AS_CARGO;
			cmenu.Add( "#inv_context_add_as_cargo", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}

		if( combinationFlags & InventoryCombinationFlags.SWAP )
		{
			current_flag = InventoryCombinationFlags.SWAP;
			cmenu.Add( "#inv_context_swap", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}

		if( combinationFlags & InventoryCombinationFlags.COMBINE_QUANTITY )
		{
			current_flag = InventoryCombinationFlags.COMBINE_QUANTITY;
			cmenu.Add( "#inv_context_combine", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}

		if(combinationFlags & InventoryCombinationFlags.SET_ACTION)
		{
			current_flag = InventoryCombinationFlags.SET_ACTION;
			cmenu.Add("#inv_context_attach_magazine", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}
		
		if(combinationFlags & InventoryCombinationFlags.PERFORM_ACTION)
		{
			current_flag = InventoryCombinationFlags.PERFORM_ACTION;
			cmenu.Add("Perform Action2", this, "OnPerformCombination", new Param1<int>( current_flag ) );
		}

		int m_am_Pos_x,  m_am_Pos_y;
		GetMousePos( m_am_Pos_x, m_am_Pos_y );
		m_am_Pos_x -= 5;
		m_am_Pos_y -= 5;

		if( combinationFlags & InventoryCombinationFlags.RECIPE_HANDS ||  combinationFlags & InventoryCombinationFlags.RECIPE_ANYWHERE )
		{
				OnPerformRecipe( id );
		}
		else 
		if( cmenu.Count() == 1 )
		{
				OnPerformCombination( current_flag );
		}
		else
		{
				cmenu.Show( m_am_Pos_x, m_am_Pos_y );
		}
	}

	void MouseClick( Widget w, int x, int y, int button )
	{
		InventoryItem itemAtPos = InventoryItem.Cast( m_Obj );
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		InventoryLocation il = new InventoryLocation;
		m_Obj.GetInventory().GetCurrentInventoryLocation( il );
		bool draggable = !player.GetInventory().HasInventoryReservation( m_Obj, null ) && !player.GetInventory().IsInventoryLocked();
		draggable = draggable && ( m_Obj.GetHierarchyRoot() && m_Obj.GetInventory().CanRemoveEntity() || !m_Obj.GetHierarchyRoot() && AttachmentsOutOfReach.IsAttachmentReachable( m_Obj, "", il.GetSlot() ) );
				
		ItemManager.GetInstance().SetWidgetDraggable( w, draggable );
		
		if( button == MouseState.RIGHT )
		{
			if( itemAtPos && itemAtPos.IsItemBase() )
			{
				ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( GetMainWidget().FindAnyWidget( "Render" ) );
				itemAtPos.OnRightClick();
				
				if( m_HasQuantity )
					SetQuantity( item_preview.GetParent() );
				if( GetDayZGame().IsLeftCtrlDown() )
					ShowActionMenu( itemAtPos );
			}
		}
		else if( button == MouseState.MIDDLE )
		{
			InspectItem( itemAtPos );
		}
		else if ( button == MouseState.LEFT && g_Game.IsLeftCtrlDown() )
		{
			if( itemAtPos.GetInventory().CanRemoveEntity() )
			{
				GetGame().GetPlayer().PredictiveDropEntity( itemAtPos );
			}
		}
	}

	void DropReceivedFromMain( Widget w, int x, int y, Widget receiver )
	{
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		ItemPreviewWidget receiver_ipw = ItemPreviewWidget.Cast( receiver.FindAnyWidget( "Render" ) );
		if( m_HandsIcon )
		{
			receiver_ipw = ItemPreviewWidget.Cast( receiver.GetParent().FindAnyWidget( "Render" ) );
		}

		ItemPreviewWidget w_ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		if( w_ipw == NULL )
		{
			w_ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
		}
		if( w_ipw == NULL )
		{
			return;
		}

		InventoryItem receiver_entity = InventoryItem.Cast( receiver_ipw.GetItem() );
		InventoryItem w_entity = InventoryItem.Cast( w_ipw.GetItem() );
		if( !w_entity )
		{
			return;
		}

		if( ( ItemBase.Cast( receiver_entity ) ).CanBeCombined( ItemBase.Cast( w_entity ) ) )
		{
			( ItemBase.Cast( receiver_entity ) ).CombineItemsClient( ItemBase.Cast( w_entity ) );
			Refresh();
		}
		else if( GameInventory.CanSwapEntities( receiver_entity, w_entity ) )
		{
			Magazine mag = Magazine.Cast(w_entity);
			if( mag )
			{
				Weapon_Base wpn = Weapon_Base.Cast(mag.GetHierarchyParent());
				if( wpn )
				{
					if( player.GetWeaponManager().CanSwapMagazine( wpn,  Magazine.Cast(receiver_entity) ) )
						player.GetWeaponManager().SwapMagazine( Magazine.Cast(receiver_entity) );
					return;
				}
			}
			
			player.PredictiveSwapEntities( w_entity, receiver_entity );

			Icon icon = ItemManager.GetInstance().GetDraggedIcon();
			if( m_Parent.IsInherited( IconsContainer ) )
			{
				ToRefresh( this, icon );
			}
		}
		else
		{
			if( m_HandsIcon && player.GetHumanInventory().CanAddEntityInHands( w_entity ) )
			{
				player.PredictiveTakeEntityToHands( w_entity );
			}
		}
	}

	void Swap( Widget w, int x, int y, Widget receiver )
	{
		string name = w.GetName();
		name.Replace( "PanelWidget", "Render" );

		ItemPreviewWidget receiver_ipw = ItemPreviewWidget.Cast( receiver.FindAnyWidget( "Render" ) );
		if( m_HandsIcon )
		{
			receiver_ipw = ItemPreviewWidget.Cast( receiver.GetParent().FindAnyWidget( "Render" ) );
		}

		ItemPreviewWidget w_ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( name ) );
		if( w_ipw == NULL )
		{
			w_ipw = ItemPreviewWidget.Cast( w.FindAnyWidget( "Render" ) );
		}
		if( w_ipw == NULL )
		{
			return;
		}

		InventoryItem receiver_entity = InventoryItem.Cast( receiver_ipw.GetItem() );
		InventoryItem w_entity = InventoryItem.Cast( w_ipw.GetItem() );
		if( !w_entity )
		{
			return;
		}

		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		EntityAI item_in_hands = player.GetHumanInventory().GetEntityInHands();
		Weapon_Base wpn;
		Magazine mag;

		if( Class.CastTo(wpn,  item_in_hands ) && Class.CastTo(mag,  w_entity ) && Class.CastTo(wpn,  mag.GetHierarchyParent() ) )
		{
			return;
		}

		InventoryLocation il_fswap = new InventoryLocation;
		
		if( GameInventory.CanSwapEntities( receiver_entity, w_entity ) )
		{
			if( !player.GetInventory().HasInventoryReservation( item_in_hands, NULL ) )
			{
				GetGame().GetPlayer().PredictiveSwapEntities( w_entity, receiver_entity );
				
				Icon icon = ItemManager.GetInstance().GetDraggedIcon();
				if( m_Parent.IsInherited( IconsContainer ) )
				{
					ToRefresh( this, icon );
				}
			}
		}
		else if( player.GetInventory().CanForceSwapEntities( w_entity, receiver_entity, il_fswap ) )
		{
			if( m_HandsIcon && !player.GetInventory().HasInventoryReservation( item_in_hands, NULL ) )
			{
				GetGame().GetPlayer().PredictiveForceSwapEntities( w_entity, receiver_entity, il_fswap );
			}
		}
	}

	void RefreshQuantity( )
	{
		SetQuantity( GetMainWidget() );
	}

	void ToRefresh( Icon icon, Icon icon2 )
	{
		( IconsContainer.Cast( m_Parent ) ).RemoveItem( icon );
		( IconsContainer.Cast( m_Parent ) ).RemoveItem( icon2 );
	}

	override void SetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
			m_LayoutName = WidgetLayoutName.IconXbox;
		#else
			switch( InventoryMenu.GetWidthType() )
			{
				case ScreenWidthType.NARROW:
				{
					m_LayoutName = WidgetLayoutName.IconNarrow;
					break;
				}
				case ScreenWidthType.MEDIUM:
				{
					m_LayoutName = WidgetLayoutName.IconMedium;
					break;
				}
				case ScreenWidthType.WIDE:
				{
					m_LayoutName = WidgetLayoutName.IconWide;
					break;
				}
			}
		#endif
			
	}

	void SetSize( int x, int y )
	{
		m_SizeX = x;
		m_SizeY = y;
	}

	int GetCargoPos()
	{
		return m_CargoPos;
	}

	void SetCargoPos( int x )
	{
		GetMainWidget().SetSort( x );
		m_CargoPos = x;
	}

	void DestroyWhiteBackground()
	{
		ItemManager.GetInstance().HideDropzones();

		ItemManager.GetInstance().SetIsDragging( false );
		m_IsDragged = false;
		
		if( m_HandsIcon )
		{
			Refresh();
			FullScreen();
			GetMainWidget().FindAnyWidget( "Color" ).SetColor( ColorManager.BASE_COLOR );
		}
		
		GetMainWidget().FindAnyWidget( "Selected" ).Show( false );

		InventoryMenu menu = InventoryMenu.Cast( GetGame().GetUIManager().FindMenu( MENU_INVENTORY ) );
		if( menu )
		{
			menu.RefreshQuickbar();
		}
	}

	void CreateWhiteBackground()
	{
		ItemManager.GetInstance().SetDraggedIcon(this);
		m_IsDragged = true;
		ItemManager.GetInstance().SetIsDragging( true );
		int ww, hh;
		GetGame().GetInventoryItemSize( InventoryItem.Cast( GetObject() ), ww, hh );
		SetSize( ww, hh );
		
		SetPos( 0,0 );

		if( !m_HandsIcon )
		{
			Refresh();
		}
		else
		{
			GetMainWidget().FindAnyWidget( "Color" ).SetColor( ColorManager.BASE_COLOR );
			GetMainWidget().FindAnyWidget( "Color" ).SetAlpha( 0.1 );
		}
		
		GetMainWidget().FindAnyWidget( "Selected" ).Show( true );
	}

	void OnDraggingOverBackground( Widget w, int x, int y, Widget reciever  )
	{
		ItemManager.GetInstance().HideDropzones();
		EntityAI entity = EntityAI.Cast( m_Obj );
		EntityAI owner = entity.GetHierarchyParent();
		if( owner && owner.GetHierarchyParent() == GetGame().GetPlayer() )
		{
			ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "RightPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
		}
		else if( !m_HandsIcon )
		{
			ItemManager.GetInstance().GetRootWidget().FindAnyWidget( "LeftPanel" ).FindAnyWidget( "DropzoneX" ).SetAlpha( 1 );
		}

		if( w == NULL || reciever == NULL )
		{
			return;
		}
		Pos pa;
		reciever.GetUserData( pa );
		if( m_Parent )
		{
			ContainerWithCargo item = ContainerWithCargo.Cast( m_Parent.m_Parent );
			if( item )
			{
				item.DraggingOverGrid( w, m_PosY + pa.y, m_PosX + pa.x, reciever );
			}
			HandsContainer hands_item = HandsContainer.Cast( m_Parent.m_Parent );
			if( hands_item )
			{
				hands_item.DraggingOverGrid( w, m_PosY + pa.y, m_PosX + pa.x, reciever, null );
			}
		}
	}

	void DropReceivedFromBackground( Widget w, int x, int y, Widget reciever  )
	{
		Pos pa;
		if( reciever )
		{
			reciever.GetUserData( pa );
			if( m_Parent )
			{
				ContainerWithCargo item = ContainerWithCargo.Cast( m_Parent.m_Parent );
				if( item )
				{
					item.DropReceived(w, m_PosY + pa.y, m_PosX + pa.x );
				}
			}
		}
	}

	override void Refresh()
	{
		super.Refresh();

		if( !m_HandsIcon )
			SetPos( m_PosX, m_PosY );
		
		if( m_HasTemperature )
			SetTemperature();
		if( m_IsWeapon )
			RefreshMuzzleIcon();
		if( m_HasQuantity )
			SetQuantity( GetMainWidget() );
	}

	void SetTemperature()
	{
		ItemManager.GetInstance().SetIconTemperature( EntityAI.Cast( m_Obj ), GetMainWidget().FindAnyWidget( "Render" ).GetParent() );
	}

	void RefreshIconPos()
	{
		Refresh();
		GetMainWidget().Update();
	}

	void FullScreen()
	{
		if( m_IsDragged )
		{
			return;
		}
		GetRootWidget().ClearFlags( WidgetFlags.HEXACTSIZE + WidgetFlags.VEXACTSIZE );
		GetRootWidget().SetSize( 1, 1 );
		GetRootWidget().FindAnyWidget( "Color" ).SetColor( ARGB( 0, 0, 0, 0 ) );
	}

	void RefreshPos( int row, int column )
	{
		if( row != m_PosY || column != m_PosX )
		{
			m_PosX = column;
			m_PosY = row;
			SetPos( m_PosX, m_PosY );
			RefreshIconPos();
		}
	}

	Object GetObject()
	{
		return m_Obj;
	}
	
	void RefreshMuzzleIcon()
	{
		Weapon_Base wpn = Weapon_Base.Cast( GetObject() );
		if( wpn )
		{
			int mi = wpn.GetCurrentMuzzle();
			GetMainWidget().FindAnyWidget( "AmmoIcon" ).Show( wpn.IsChamberFull( mi ) );
		}
	}
	
	float GetQuantity()
	{
		if( m_Item )
		{
			if( m_IsMagazine )
			{
				return Magazine.Cast( m_Item ).GetAmmoCount();
			}
			else
			{
				return m_Item.GetQuantity();
			}
		}
		return -1;
	}

	void SetQuantity( Widget item_w )
	{
		if( m_Item && m_CurrQuantity != GetQuantity() )
		{
			m_CurrQuantity = GetQuantity();
			int has_quantity = QuantityConversions.HasItemQuantity( m_Item );
			Widget quantity_panel = item_w.FindAnyWidget( "QuantityPanel" );
			
			TextWidget item_quantity = TextWidget.Cast( item_w.FindAnyWidget( "Quantity" ) );
			ProgressBarWidget quantity_progress = ProgressBarWidget.Cast( item_w.FindAnyWidget( "QuantityBar" ) );
			Widget quantity_stack = item_w.FindAnyWidget( "QuantityStackPanel" );
			if( has_quantity == QUANTITY_COUNT )
			{
				item_quantity.SetText( QuantityConversions.GetItemQuantityText( m_Item ) );
				quantity_stack.Show( true );
				quantity_progress.Show( false );
			}
			else if( has_quantity == QUANTITY_PROGRESS )
			{

				float progress_max = quantity_progress.GetMax();
				int max = m_Item.ConfigGetInt( "varQuantityMax" );
				int count = m_Item.ConfigGetInt( "count" );
				float quantity = QuantityConversions.GetItemQuantity( InventoryItem.Cast( m_Item ) );

				if( count > 0 )
				{
					max = count;
				}
				if( max > 0 )
				{

					float value = Math.Round( ( quantity / max ) * 100 );
					quantity_progress.SetCurrent( value );
				}
				quantity_stack.Show( false );
				quantity_progress.Show( true );
			}
		}
	}
	
	void SetSort( int index )
	{
		GetMainWidget().SetSort( index );
		GetMainWidget().Update();
	}
	
	int GetSort()
	{
		return GetMainWidget().GetSort( );
	}
	
	void SetItemPreview()
	{
		ItemPreviewWidget item_preview = ItemPreviewWidget.Cast( GetMainWidget().FindAnyWidget( "Render" ) );
		item_preview.Show( true );
		item_preview.SetItem( EntityAI.Cast( m_Obj ) );
		item_preview.SetModelOrientation( "0 0 0" );
		item_preview.SetView( m_Obj.GetViewIndex() );
	}
	
	void SetItemSize()
	{
		#ifdef PLATFORM_CONSOLE
		Widget tw_p		= GetMainWidget().FindAnyWidget( "ItemSizePanel" );
		TextWidget tw	= TextWidget.Cast( GetMainWidget().FindAnyWidget( "ItemSize" ) );
		
		if( !m_HandsIcon )
			tw_p.Show( true );
		tw.Show( true );
		
		int size_x, size_y;
		GetGame().GetInventoryItemSize( InventoryItem.Cast( m_Obj ) , size_x, size_y );
		int capacity = size_x * size_y;
		tw.SetText( capacity.ToString() );
		#endif
	}

	void Init( EntityAI obj )
	{
		m_Obj	= obj;
		m_Item	= ItemBase.Cast( m_Obj );
		
		SetItemPreview();

		WidgetEventHandler.GetInstance().RegisterOnDrag( GetMainWidget(),  this, "CreateWhiteBackground" );
		WidgetEventHandler.GetInstance().RegisterOnDrop( GetMainWidget(),  this, "DestroyWhiteBackground" );
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget(),  this, "DropReceivedFromMain" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( GetMainWidget(),  this, "MouseClick" );
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget().FindAnyWidget( "Swap" ),  this, "Swap" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget().FindAnyWidget( "Swap" ),  this, "DraggingOverSwap" );
		WidgetEventHandler.GetInstance().RegisterOnDropReceived( GetMainWidget().FindAnyWidget( "Combine" ),  this, "Combine" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget().FindAnyWidget( "Combine" ),  this, "DraggingOverCombine" );
		WidgetEventHandler.GetInstance().RegisterOnDraggingOver( GetMainWidget(),  this, "DraggingOver" );
		WidgetEventHandler.GetInstance().RegisterOnMouseEnter( GetMainWidget(),  this, "MouseEnter" );
		WidgetEventHandler.GetInstance().RegisterOnMouseLeave( GetMainWidget(),  this, "MouseLeave" );
		WidgetEventHandler.GetInstance().RegisterOnDoubleClick( GetMainWidget(),  this, "DoubleClick" );
		
		SetItemSize();
		CheckIsWeapon();
		CheckIsMagazine();
		CheckHasTemperature();
		CheckHasQuantity();
		
		Refresh();
	}
	
	void CheckIsWeapon()
	{
		m_IsWeapon = ( Weapon_Base.Cast( m_Obj ) != null );
	}
	
	void CheckIsMagazine()
	{
		m_IsMagazine = ( Magazine.Cast( m_Obj ) != null );
	}
	
	void CheckHasTemperature()
	{
		if( m_Item )
		{
			m_HasTemperature = ( m_Item.GetTemperatureMax() != 0 && m_Item.GetTemperatureMin() != 0 );
		}
	}
	
	void CheckHasQuantity()
	{
		if( m_Item )
		{
			m_HasQuantity = ( QuantityConversions.HasItemQuantity( m_Item ) != QUANTITY_HIDDEN );
			if( m_HasQuantity )
			{
				GetMainWidget().FindAnyWidget( "QuantityPanel" ).Show( true );
			}
		}
	}
	
	void SetPosX( int x )
	{
		m_PosX = x;
	}
	
	void SetPosY( int y )
	{
		m_PosY = y;
	}
	
	void SetSizeX( int x )
	{
		m_SizeX = x;
	}
	
	void SetSizeY( int y )
	{
		m_SizeY = y;
	}
	
	int GetPosX()
	{
		return m_PosX;
	}
	
	int GetPosY()
	{
		return m_PosY;
	}
	
	int GetSizeX()
	{
		return m_SizeX;
	}
	
	int GetSizeY()
	{
		return m_SizeY;
	}

	void SetPos( int column, int row )
	{
		CargoContainer c_parent = CargoContainer.Cast( m_Parent );
		HandsPreview h_parent = HandsPreview.Cast( m_Parent );
		float icon_size, space_size;
		if( c_parent )
		{
			icon_size = c_parent.GetIconSize();
			space_size = c_parent.GetSpaceSize();
		}
		else if( h_parent )
		{
			icon_size = h_parent.GetIconSize();
			GetRootWidget().SetFlags( WidgetFlags.EXACTSIZE );
		}
		
		#ifndef PLATFORM_CONSOLE
			GetRootWidget().SetPos( icon_size * column + ( column + 1 ) * space_size, icon_size * row + ( row + 1 ) * space_size );
			GetRootWidget().SetSize( icon_size * m_SizeX + ( m_SizeX ) * space_size, icon_size * m_SizeY + ( m_SizeY ) * space_size );
		#else
			row = m_CargoPos / 5;
			column = m_CargoPos % 5;
			GetRootWidget().SetPos( icon_size * column, icon_size * row );
			GetRootWidget().SetSize( icon_size, icon_size );
		#endif
	}
	
	override void UpdateInterval()
	{
		if( m_Item )
		{
			if( m_HasTemperature )
				SetTemperature();
			if( m_IsWeapon )
				RefreshMuzzleIcon();
			if( m_HasQuantity )
				SetQuantity( GetMainWidget() );
		}
	}
}

class Pos
{
	int x, y;

	void Pos( int _x, int _y )
	{
		x = _x;
		y = _y;
	}
}
