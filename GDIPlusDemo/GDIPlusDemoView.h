
// GDIPlusDemoView.h : CGDIPlusDemoView 클래스의 인터페이스
//

#pragma once
#include "atltypes.h"

enum DRAW_MODE { FREEDRAW_MODE, LINE_MODE, RECTANGLE_MODE, ELLIPSE_MODE };

class CGDIPlusDemoView : public CView
{
protected: // serialization에서만 만들어집니다.
	CGDIPlusDemoView();
	DECLARE_DYNCREATE(CGDIPlusDemoView)

// 특성입니다.
public:
	CGDIPlusDemoDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CGDIPlusDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int m_nPenSize;
	int m_nEraserSize;
	COLORREF m_colorPen;
	CPoint m_ptPrev;
	afx_msg void OnPenColor();
	afx_msg void OnPenSize();
	afx_msg void OnEraserSize();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int m_nDrawMode;
	afx_msg void OnFreedraw();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnEllipse();
	afx_msg void OnUpdateFreedraw(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEllipse(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRectangle(CCmdUI *pCmdUI);
	bool m_bSecond;
	afx_msg void OnFileOpen();
	Image* m_pImage;
};

#ifndef _DEBUG  // GDIPlusDemoView.cpp의 디버그 버전
inline CGDIPlusDemoDoc* CGDIPlusDemoView::GetDocument() const
   { return reinterpret_cast<CGDIPlusDemoDoc*>(m_pDocument); }
#endif

