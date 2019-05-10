class ChernarusMap extends ItemMap
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionUnfoldMap);
	}
}
class ChernarusMap_Open extends ItemMap {}