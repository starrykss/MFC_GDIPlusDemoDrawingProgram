#pragma once
#include "afxcmn.h"


// CEraserSizeDlg 대화 상자입니다.

class CEraserSizeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEraserSizeDlg)

public:
	CEraserSizeDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEraserSizeDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ERASER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	UINT m_nEraserSize;
	CSpinButtonCtrl m_spinEraser;
	virtual BOOL OnInitDialog();
};
