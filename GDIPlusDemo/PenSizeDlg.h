#pragma once
#include "afxcmn.h"


// CPenSizeDlg ��ȭ �����Դϴ�.

class CPenSizeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPenSizeDlg)

public:
	CPenSizeDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPenSizeDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PEN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	UINT m_nPenSize;
	CSpinButtonCtrl m_spinPen;
	virtual BOOL OnInitDialog();
};
