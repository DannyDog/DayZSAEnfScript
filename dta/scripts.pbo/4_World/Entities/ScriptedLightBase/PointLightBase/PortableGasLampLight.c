class PortableGasLampLight extends PointLightBase
{
	static float m_TorchRadius = 15;
	static float m_TorchBrightness = 5.0;
	
	void PortableGasLampLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo( m_TorchRadius );
		SetBrightnessTo(m_TorchBrightness);
		SetCastShadow(true);
		FadeIn(0.5);
		SetFadeOutTime(0.1);
		SetDiffuseColor(1.0, 0.7, 0.5);
		SetAmbientColor(1.0, 0.7, 0.5);
	}
	
	/*override void OnFrameLightSource(IEntity other, float timeSlice)
	{
		
	}*/
}