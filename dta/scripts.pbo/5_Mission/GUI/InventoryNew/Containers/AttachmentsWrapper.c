class AttachmentsWrapper: Container
{
	ref Attachments m_Attachments;
	
	void SetParent( Attachments atts )
	{
		m_Attachments = atts;
	}
	
	override void SetLayoutName()
	{
		m_LayoutName = WidgetLayoutName.AttachmentsWrapper;
	}
	
	override bool Select()
	{
		return m_Attachments.Select();
	}
	
	override bool Combine()
	{
		return false;
	}
	
	override bool TransferItemToVicinity()
	{
		return m_Attachments.TransferItemToVicinity();
	}
	
	override bool TransferItem()
	{
		return m_Attachments.TransferItem();
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
	
	override EntityAI GetFocusedEntity()
	{
		return m_Attachments.GetFocusedEntity();
	}
}
