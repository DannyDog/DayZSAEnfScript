class ShockDealtEffect
{
	const float INTENSITY_COEF_OVERALL = 0.8; //intensity percentage multiplier
	const float INTENSITY_COEF_BLUR = 1;
	const float INTENSITY_COEF_COLOR = 0.2;
	const float INTENSITY_COEF_VIGNETTE = 0.7;
	const float DURATION_MIN = 0.6;
	
	float m_HitDuration;
	float m_BreakPoint;
	float m_TimeActive;
	float m_ShockIntensityMax;
	
	void ShockDealtEffect(float intensity_max)
	{
		float duration_coef = Math.Clamp(intensity_max,DURATION_MIN,1);
		m_HitDuration = 1 * duration_coef;
		m_BreakPoint = 0.2 * duration_coef;
		m_ShockIntensityMax = Math.Clamp(intensity_max,0,1);
		//Print(intensity_max);
	}
	
	void ~ShockDealtEffect()
	{
		PPEffects.SetBlurShock(0);
		PPEffects.SetShockEffectColor(0);
		//PPEffects.ResetPPMask();
	}
	
	void Update(float deltatime)
	{
		float value;
		
		if( m_TimeActive <= m_BreakPoint )
		{
			value = Math.InverseLerp(0, m_BreakPoint, m_TimeActive);
		}
		else
		{
			float tmp_value = Math.InverseLerp(m_BreakPoint, m_HitDuration, m_TimeActive);
			value = 1 - tmp_value;
		}
		//Print(value);
		m_TimeActive += deltatime;
		value = Math.Clamp(value,0,1);
		
		//value calculations
		float val = Math.Clamp(Math.Lerp(0, m_ShockIntensityMax, value),0,m_ShockIntensityMax);
		float val_color = Math.Clamp(val * INTENSITY_COEF_COLOR,0,m_ShockIntensityMax);
		//Print(val);
		//Print(val_color);
		
		//Postprocess application
		PPEffects.SetBlurShock(val * INTENSITY_COEF_OVERALL * INTENSITY_COEF_BLUR);
		PPEffects.SetShockEffectColor(val_color * INTENSITY_COEF_OVERALL);
		PPEffects.SetShockVignette(val * INTENSITY_COEF_OVERALL * INTENSITY_COEF_VIGNETTE);
		
		if(m_TimeActive >= m_HitDuration)
		{
			delete this;
		}
	}
}