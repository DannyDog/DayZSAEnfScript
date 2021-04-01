class AttachmentsWrapper: Container
{
	Attachments m_Attachments;
	
	void SetParent( Attachments atts )
	{
		m_Attachments = atts;
	}
	
	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.AttachmentsWrapper;
	}
	
	override void SetLastActive()
	{
		m_Attachments.SetLastActive();
	}
	
	override bool Select()
	{
		return m_Attachments.Select();
	}
	
	override bool SelectItem()
	{
		return m_Attachments.SelectItem();
	}
	
	override bool Combine()
	{
		return m_Attachments.Combine();
	}
	
	override bool TransferItemToVicinity()
	{
		return m_Attachments.TransferItemToVicinity();
	}
	
	override bool TransferItem()
	{
		return m_Attachments.TransferItem();
	}
	
	override bool InspectItem()
	{
		return m_Attachments.InspectItem();
	}
	
	override bool EquipItem()
	{
		return m_Attachments.EquipItem();
	}
	
	override bool CanEquip()
	{
		return m_Attachments.CanEquip();
	}
	
	override bool CanCombine()
	{
		return m_Attachments.CanCombine();
	}
	
	override bool CanCombineAmmo()
	{
		return false;
	}
	
	override bool IsEmpty()
	{
		return m_Attachments.IsEmpty();
	}
	
	override bool IsItemActive()
	{
		return m_Attachments.IsItemActive();
	}

	override bool IsItemWithQuantityActive()
	{
		return m_Attachments.IsItemWithQuantityActive();
	}
	
	override EntityAI GetFocusedItem()
	{
		return m_Attachments.GetFocusedItem();
	}
}
