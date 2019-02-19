class MouthRag extends Clothing
{
	void ~MouthRag()
	{
		PlayerBase player;
		Class.CastTo(player, GetHierarchyRootPlayer());
		if( GetGame() && GetGame().IsServer() && player )
		{
			MutePlayerByGag(player,false);
		}
		
	}
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		
		PlayerBase player;
		Class.CastTo(player, parent.GetHierarchyRootPlayer());

		if ( (GetGame().IsServer() || !GetGame().IsMultiplayer()) && player && slot_id == InventorySlots.MASK )
		{
			//GetGame().GetSoundScene().SetSpeechExVolume(0,1);
			//GetGame().GetSoundScene().SetVOIPVolume(0,1);
			//GetGame().GetSoundScene().SetRadioVolume(0,1);
			
			MutePlayerByGag(player,true);
		}
	}

	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		
		PlayerBase player = PlayerBase.Cast(parent);
		
		if ( GetGame().IsServer() && player )
		{
			MutePlayerByGag(player,false);
		}
	}
	
	void MutePlayerByGag(PlayerBase player, bool state)
	{
		//GetGame().GetSoundScene().SetSpeechExVolume(g_Game.m_volume_speechEX,1);
		//GetGame().GetSoundScene().SetVOIPVolume(g_Game.m_volume_VOIP,1);
		//GetGame().GetSoundScene().SetRadioVolume(g_Game.m_volume_radio,1);
		
		GetGame().SetVoiceEffect(player, VoiceEffectMumbling, state);
	}
};