class Headtorch_Black : Headtorch_ColorBase 
{
	override void OnLightCreated()
	{
		m_Light.SetColorToRed();
	}
}