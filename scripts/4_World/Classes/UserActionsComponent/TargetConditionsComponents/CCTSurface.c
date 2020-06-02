class CCTSurface : CCTBase
{
	protected float m_MaximalActionDistanceSq;
	
	void CCTSurface ( float maximal_target_distance ) //distance measured from the center of the object!
	{
		m_MaximalActionDistanceSq = maximal_target_distance * maximal_target_distance;
	}
	
	override bool Can( PlayerBase player, ActionTarget target )
	{	
		if( !target || (target && target.GetObject()) )
			return false;
		
		if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
			return true;
		
		vector hit_pos = target.GetCursorHitPos();
		if (hit_pos == vector.Zero)
			return false;
			
		//string surface_type;
		//GetGame().SurfaceGetType( hit_pos[0], hit_pos[2], surface_type );
		
		return ( vector.DistanceSq(hit_pos, player.GetPosition()) <= m_MaximalActionDistanceSq );
	}
};
