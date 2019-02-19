class Thermometer extends ItemBase
{
	string GetTemperatureMessage(PlayerBase player)
	{
		string temp;
		float value;
		if( player.GetModifiersManager() && player.GetModifiersManager().IsModifierActive(eModifiers.MDF_FEVER) )
		{
			value = Math.RandomFloatInclusive(PlayerConstants.HIGH_TEMPERATURE_L, PlayerConstants.HIGH_TEMPERATURE_H);
		}
		else
		{
			
			value = Math.RandomFloatInclusive(PlayerConstants.NORMAL_TEMPERATURE_L, PlayerConstants.NORMAL_TEMPERATURE_H);
		}
		temp = value.ToString();
		return "Thermometer displays "+temp+" °C";
	}
}