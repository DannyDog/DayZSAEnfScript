class FlashlightLight extends SpotLightBase
{
	private static float m_DefaultBrightness = 6;
	private static float m_DefaultRadius = 30;
	
	void FlashlightLight()
	{
		SetVisibleDuringDaylight(true);
		SetRadiusTo(m_DefaultRadius);
		SetSpotLightAngle(120);
		SetCastShadow(true);
		EnableSpecular(true);
		SetBrightnessTo(m_DefaultBrightness);
		SetFadeOutTime(0.15);
		SetAmbientColor(1.0, 0.85, 0.75);
		SetDiffuseColor(1.0, 0.85, 0.75);
	}
	
	void SetIntensity( float coef, float time )
	{
		FadeBrightnessTo(m_DefaultBrightness * coef, time);
	}
}