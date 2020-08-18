class CCTCursor : CCTBase
{
	protected float m_MaximalActionDistanceSq;
	
	void CCTCursor ( float maximal_target_distance = UAMaxDistances.DEFAULT )
	{
		m_MaximalActionDistanceSq = maximal_target_distance * maximal_target_distance;
	}
	
	override bool Can( PlayerBase player, ActionTarget target )
	{	
		if( !target )
			return false;
		
		Object targetObject = target.GetObject();
		if ( !player || !targetObject || targetObject.IsDamageDestroyed() )
			return false;
			
		if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
			return true;
		
		vector playerHeadPos;
		MiscGameplayFunctions.GetHeadBonePos(player, playerHeadPos);
		
		float distanceRoot = vector.DistanceSq(target.GetCursorHitPos(), player.GetPosition());
		float distanceHead = vector.DistanceSq(target.GetCursorHitPos(), playerHeadPos);
		
		return ( distanceRoot <= m_MaximalActionDistanceSq || distanceHead <= m_MaximalActionDistanceSq );
	}
};