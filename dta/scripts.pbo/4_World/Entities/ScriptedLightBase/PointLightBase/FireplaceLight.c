class FireplaceLight extends PointLightBase
{
	static float m_TorchRadius = 25;
	static float m_TorchBrightness = 4.75;
	
	void FireplaceLight()
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo( m_TorchRadius );
		SetBrightnessTo(m_TorchBrightness);
		SetCastShadow(true);
		SetFadeOutTime(5);
		SetDiffuseColor(1.0, 0.5, 0.3);
		SetAmbientColor(1.0, 0.5, 0.3);
		SetFlareVisible(false);
	}
	
	override void OnFrameLightSource(IEntity other, float timeSlice)
	{
		
	}
}