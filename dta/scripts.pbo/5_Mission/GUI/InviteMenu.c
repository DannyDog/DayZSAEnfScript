class InviteMenu extends UIScriptedMenu
{	
	private TextWidget		m_LogoutTimetext;
	private TextWidget		m_Info;
	private ButtonWidget	m_bCancel;
	private int m_iTime;

	void InviteMenu()
	{
		m_iTime = 15;
	}
	
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("gui/layouts/day_z_invite_dialog.layout");
		
		m_LogoutTimetext = TextWidget.Cast( layoutRoot.FindAnyWidget("logoutTimeText") );
		m_Info = TextWidget.Cast( layoutRoot.FindAnyWidget("txtInfo") );
		m_bCancel = ButtonWidget.Cast( layoutRoot.FindAnyWidget("bCancel") );
		m_LogoutTimetext.SetText(m_iTime.ToString());
		
		// player should sit down if possible
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player && player.GetEmoteManager() && !player.IsRestrained() && !player.IsUnconscious()) 
		{
			player.GetEmoteManager().CreateEmoteCBFromMenu(ID_EMOTE_SITA);
		}
		
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( UpdateTime, 1000, true );
		return layoutRoot;
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		
		if (w == m_bCancel)
		{
			Cancel();
			return true;
		}

		return false;
	}
	
	override void OnShow()
	{
		super.OnShow();
		SetFocus( m_bCancel );
	}

	override void Update( float timeslice )
	{
		if( GetGame().GetInput().LocalPress( "UAUIBack", false ) )
		{
			Cancel();
			Close();
		}		
	}
		
	void UpdateTime()
	{
		if (m_iTime > 0)
		{
			m_iTime -= 1;
			m_LogoutTimetext.SetText(m_iTime.ToString());	
		}
		else
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.UpdateTime);
			string ip;
			int port;
			OnlineServices.GetInviteServerInfo( ip, port );
			g_Game.ConnectFromJoin( ip, port );
			//Close();
		}
	}

	void Cancel()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.UpdateTime);
		
		g_Game.SetGameState( DayZGameState.IN_GAME );
		g_Game.SetLoadState( DayZLoadState.CONNECT_CONTROLLER_SELECT );
		Close();
	}
}