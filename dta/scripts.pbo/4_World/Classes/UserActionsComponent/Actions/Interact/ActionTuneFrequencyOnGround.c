class ActionTuneFrequencyOnGround : ActionInteractBase
{
	string m_RadioFreq;

	void ActionTuneFrequencyOnGround()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_MessageSuccess 	= "I have tuned the frequency.";
		m_MessageFail 		= "Cannot tune the frequency on the device without power.";
		m_RadioFreq 		= string.Empty;
	}

	override int GetType()
	{
		return AT_TUNE_FREQUENCY_ON_GROUND;
	}

	override string GetText()
	{
		string text = "#tune_frequency | " + m_RadioFreq + " MHz";
		return text;
	}

#ifndef OLD_ACTIONS	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
#endif

	override bool HasProgress()
	{
		return false;
	}
		
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		Land_Radio_PanelBig transmitter = Land_Radio_PanelBig.Cast( target_object );
		string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		
		if ( transmitter.GetCompEM().IsWorking() && selection == "control_panel" )
		{
			//transmitter.DisplayRadioInfo( transmitter.GetTunedFrequency().ToString(), player );
			m_RadioFreq = transmitter.GetTunedFrequency().ToString();
			
			return true;
		}
		
		return false;
	}
		
	override void OnExecuteServer( ActionData action_data )
	{
		Land_Radio_PanelBig transmitter = Land_Radio_PanelBig.Cast( action_data.m_Target.GetObject() );
		transmitter.SetNextFrequency( action_data.m_Player );
	}
}