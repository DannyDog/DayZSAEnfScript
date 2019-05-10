class NotificationUI
{
	protected ref Widget	m_Root;
	protected ref Widget	m_Spacer;
	protected ref Widget	m_VoiceContent;
	protected ref Widget	m_NotificationContent;
	
	protected ref map<NotificationRuntimeData, Widget>	m_Notifications;
	protected ref map<string, Widget>					m_VoiceNotifications;
	
	protected float										m_Width;
	protected float										m_CurrentHeight;
	protected float										m_TargetHeight;
	protected ref map<string, Widget>					m_WidgetTimers;
	
	void NotificationUI()
	{
		m_Root					= GetGame().GetWorkspace().CreateWidgets("gui/layouts/new_ui/notifications/notifications.layout");
		m_Spacer				= m_Root.FindAnyWidget( "NotificationSpacer" );
		m_VoiceContent			= m_Root.FindAnyWidget( "VoiceContent" );
		m_NotificationContent	= m_Root.FindAnyWidget( "NotificationContent" );
		m_Notifications			= new map<NotificationRuntimeData, Widget>;
		m_VoiceNotifications	= new map<string, Widget>;
		m_WidgetTimers			= new map<string, Widget>;
		
		NotificationSystem.BindOnAdd( AddNotification );
		NotificationSystem.BindOnRemove( RemoveNotification );
	}
	
	void ~NotificationUI()
	{
		NotificationSystem.UnbindOnAdd( AddNotification );
		NotificationSystem.UnbindOnRemove( RemoveNotification );
	}
	
	void AddNotification( NotificationRuntimeData data )
	{
		Widget notification			= GetGame().GetWorkspace().CreateWidgets("gui/layouts/new_ui/notifications/notification_element.layout", m_NotificationContent);
		
		ImageWidget icon			= ImageWidget.Cast( notification.FindAnyWidget( "Image" ) );
		RichTextWidget title		= RichTextWidget.Cast( notification.FindAnyWidget( "Title" ) );
		
		if( data.GetIcon() != "" )
			icon.LoadImageFile( 0, data.GetIcon() );
		title.SetText( data.GetTitleText() );
		
		if( data.GetDetailText() != "" )
		{
			Widget bottom_spacer	= notification.FindAnyWidget( "BottomSpacer" );
			RichTextWidget detail	= RichTextWidget.Cast( notification.FindAnyWidget( "Detail" ) );
			bottom_spacer.Show(true);
			detail.SetText( data.GetDetailText() );
			notification.Update();
		}
		
		m_Notifications.Insert( data, notification );
		UpdateTargetHeight();
	}
	
	void RemoveNotification( NotificationRuntimeData data )
	{
		if( m_Notifications.Contains( data ) )
		{
			Widget notification = m_Notifications.Get( data );
			m_WidgetTimers.Insert( m_WidgetTimers.Count().ToString() + data.GetTime().ToString(), notification );
			m_Notifications.Remove( data );
			UpdateTargetHeight();
		}
	}
	
	void AddVoiceNotification(string player, string name)
	{
		Print("Trying to add voice notification");
		if (!m_VoiceNotifications.Contains(player))
		{
			Widget notification;
			if (!m_WidgetTimers.Contains(player))
			{
				notification = GetGame().GetWorkspace().CreateWidgets("gui/layouts/new_ui/notifications/notification_voice_element.layout", m_VoiceContent);
			}
			else
			{
				Print("Replacing old widget");
				notification = m_WidgetTimers.Get(player);
				m_WidgetTimers.Remove(player);
			}

			RichTextWidget title = RichTextWidget.Cast(notification.FindAnyWidget("Name"));
			m_VoiceNotifications.Insert(player, notification);
			Print("Added voice notification");
			title.SetText(name);
			UpdateTargetHeight();
		}
	}
	
	void RemoveVoiceNotification( string player )
	{
		if( m_VoiceNotifications.Contains( player ) )
		{
			Widget notification = m_VoiceNotifications.Get( player );
			m_WidgetTimers.Insert( player, notification );
			m_VoiceNotifications.Remove( player );
			UpdateTargetHeight();
		}
	}
	
	void ClearVoiceNotifications()
	{
		for( int i = 0; i < m_VoiceNotifications.Count(); )
		{
			Widget w = m_VoiceNotifications.GetElement( i );
			delete w;
		}
		m_VoiceNotifications.Clear();
		UpdateTargetHeight();
	}
	
	void UpdateTargetHeight()
	{
		m_VoiceContent.Update();
		m_NotificationContent.Update();
		m_Spacer.Update();
		
		float x;
		m_Spacer.GetScreenSize( x, m_TargetHeight );
		m_Root.GetScreenSize( m_Width, m_CurrentHeight );
	}
	
	static float m_VelArr[1];
	void Update( float timeslice )
	{
		bool is_near = ( m_CurrentHeight + 0.01 < m_TargetHeight || m_CurrentHeight - 0.01 > m_TargetHeight );
		if( is_near )
		{
			m_CurrentHeight = Math.SmoothCD(m_CurrentHeight, m_TargetHeight, m_VelArr, 0.2, 10000, timeslice);
			m_Root.SetSize( m_Width, m_CurrentHeight );
		}
		else if( m_TargetHeight != m_CurrentHeight )
		{
			m_CurrentHeight = m_TargetHeight;
			m_Root.SetSize( m_Width, m_CurrentHeight );
			m_VelArr[0] = 0;
		}
		
		for( int i = 0; i < m_WidgetTimers.Count(); )
		{
			Widget w = m_WidgetTimers.GetElement( i );
			float new_alpha			= Math.Clamp( w.GetAlpha() - timeslice / NOTIFICATION_FADE_TIME, 0, 1 );
			if( new_alpha > 0 )
			{
				w.SetAlpha( new_alpha );
				Widget w_c = w.FindAnyWidget( "TopSpacer" );
				Widget w_c2 = w.FindAnyWidget( "BottomSpacer" );
				if( w_c && w_c2 )
				{
					float new_alpha_cont	= Math.Clamp( w_c.GetAlpha() - timeslice / NOTIFICATION_FADE_TIME, 0, 1 );
					w_c.SetAlpha( new_alpha_cont );
					w_c2.SetAlpha( new_alpha_cont );
				}
				i++;
			}
			else
			{
				delete w;
				m_WidgetTimers.RemoveElement( i );
				UpdateTargetHeight();
			}
		}
	}
}