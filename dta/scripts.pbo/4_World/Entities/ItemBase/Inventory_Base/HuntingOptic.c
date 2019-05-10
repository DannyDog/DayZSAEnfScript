class HuntingOptic extends ItemOptics
{
	EntityAI m_parent;
	
	void HuntingOptic()
	{
		HideSelection("rings_ris");
		HideSelection("rings_ris_pilot");
	}
	
	override void OnWasAttached( EntityAI parent, int slot_id )
	{
		super.OnWasAttached(parent, slot_id);
		m_parent = parent;
		if (!m_parent.IsKindOf("Winchester70"))
		{
			HideSelection("rings_winchester");
			HideSelection("rings_winchester_pilot");
			ShowSelection("rings_ris");
			ShowSelection("rings_ris_pilot");
		}
	}
	
	override void OnWasDetached( EntityAI parent, int slot_id )
	{
		super.OnWasDetached(parent, slot_id);
		m_parent = null;
		HideSelection("rings_ris");
		HideSelection("rings_ris_pilot");
		ShowSelection("rings_winchester");
		ShowSelection("rings_winchester_pilot");
	}
	
	override void HideSelection( string selection_name )
	{
		super.HideSelection( selection_name );
		if (selection_name == "hide") //hides pilotview selections in order not to obstruct view
		{
			HideSelection("rings_ris_pilot");
			HideSelection("rings_winchester_pilot");
		}
	}
	
	override void ShowSelection( string selection_name )
	{
		super.ShowSelection( selection_name );
		if (selection_name == "hide")
		{
			if (m_parent && !m_parent.IsKindOf("Winchester70"))
			{
				HideSelection("rings_winchester");
				HideSelection("rings_winchester_pilot");
				ShowSelection("rings_ris");
				ShowSelection("rings_ris_pilot");
			}
			else
			{
				HideSelection("rings_ris");
				HideSelection("rings_ris_pilot");
				ShowSelection("rings_winchester");
				ShowSelection("rings_winchester_pilot");
			}
		}
	}
}