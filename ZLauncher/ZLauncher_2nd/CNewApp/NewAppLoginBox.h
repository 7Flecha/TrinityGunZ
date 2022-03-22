#include "resource.h"
#include "CDDBDialog.h"

/////////////////////////////////////////////////////////////////////////////
// Dialog
class CNewAppLoginBox : public CDDBDialog
{
private:
	CStatic			m_cMessage;
	CDDBButton		m_cOK;
	CDDBButton		m_cCancel;
	CEdit			m_cID;
	CEdit			m_cPassword;

	// Variables
	CString			m_strCaption;
	CString			m_strMessage;
	UINT			m_nButtonType;
	CDialog*		m_pParentDialog;


public:
	CNewAppLoginBox(CWnd* pParent = NULL);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

protected:
	afx_msg void OnBnLoginRequest();

	DECLARE_MESSAGE_MAP()
};
