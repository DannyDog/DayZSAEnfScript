class HeadtorchLight extends SpotLightBase
{
	private static float m_DefaultBrightness = 6;
	private static float m_DefaultRadius = 25;
	
	void HeadtorchLight()
	{
		SetVisibleDuringDaylight(true);
		SetRadiusTo(m_DefaultRadius);
		SetSpotLightAngle(130);
		SetCastShadow(true);
		FadeIn(0.06);
		SetFadeOutTime(0.1);
		SetBrightnessTo(m_DefaultBrightness);
		SetAmbientColor(0.8, 0.9, 1.0);
		SetDiffuseColor(0.8, 0.9, 1.0);
		//SetDisableShadowsWithinRadius(0.25); // Idea for optimization: Uncomment this to disable shadows from Headtorch while it's on player's head during 1P view.
	}
	
	void SetColorToWhite()
	{
		SetAmbientColor(0.8, 0.9, 1.0);
		SetDiffuseColor(0.8, 0.9, 1.0);
	}
	
	void SetColorToRed()
	{
		SetAmbientColor(0.8, 0.1, 0.1);
		SetDiffuseColor(0.8, 0.1, 0.1);
	}
	
	void SetIntensity( float coef, float time )
	{
		FadeBrightnessTo(m_DefaultBrightness * coef, time);
		FadeRadiusTo(m_DefaultRadius * coef, time);
	}
}