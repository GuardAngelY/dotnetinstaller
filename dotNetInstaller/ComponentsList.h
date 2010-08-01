#pragma once

class CdotNetInstallerDlg;

class CComponentsList :
	public CCheckListBox
{
	DECLARE_DYNAMIC(CComponentsList);
private:
	CdotNetInstallerDlg * m_pExecuteCallback;
	InstallConfiguration * m_pConfiguration;
	DVLib::LcidType m_lcidtype;
	void Exec(const ComponentPtr& component);
protected:
	void PreDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct); 
	void OnCheckChange();
	void OnLButtonDblClk(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP();
public:
	void SetExecuteCallback(CdotNetInstallerDlg *);
	void Load(DVLib::LcidType lcidtype, InstallConfiguration * pConfiguration);
	void AddComponent(const ComponentPtr& component, const std::wstring& description, bool checked, bool disabled);
	CComponentsList();
};
