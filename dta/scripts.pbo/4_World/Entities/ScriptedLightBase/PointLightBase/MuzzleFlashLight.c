class MuzzleFlashLight extends PointLightBase
{
	static float m_Lifetime = 0.04;
	
	void MuzzleFlashLight()
	{
		SetLifetime(m_Lifetime);
		FadeIn(m_Lifetime * 0.5);
		SetFadeOutTime(m_Lifetime * 0.5);
		SetVisibleDuringDaylight(true);
		SetRadiusTo( 15 );
		SetBrightnessTo(1);
		SetCastShadow(false);
		SetAmbientColor(0.76, 0.68, 0.31);
		SetDiffuseColor(0.76, 0.68, 0.31);
		SetFlareVisible(false);
	}
}