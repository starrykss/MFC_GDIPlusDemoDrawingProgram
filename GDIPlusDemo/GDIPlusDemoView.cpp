
// GDIPlusDemoView.cpp : CGDIPlusDemoView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "GDIPlusDemo.h"
#endif

#include "GDIPlusDemoDoc.h"
#include "GDIPlusDemoView.h"

// 추가
#include "PenSizeDlg.h"
#include "EraserSizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDIPlusDemoView

IMPLEMENT_DYNCREATE(CGDIPlusDemoView, CView)

BEGIN_MESSAGE_MAP(CGDIPlusDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGDIPlusDemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_PEN_COLOR, &CGDIPlusDemoView::OnPenColor)
	ON_COMMAND(ID_PEN_SIZE, &CGDIPlusDemoView::OnPenSize)
	ON_COMMAND(ID_ERASER_SIZE, &CGDIPlusDemoView::OnEraserSize)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FREEDRAW, &CGDIPlusDemoView::OnFreedraw)
	ON_COMMAND(ID_LINE, &CGDIPlusDemoView::OnLine)
	ON_COMMAND(ID_RECTANGLE, &CGDIPlusDemoView::OnRectangle)
	ON_COMMAND(ID_ELLIPSE, &CGDIPlusDemoView::OnEllipse)
	ON_UPDATE_COMMAND_UI(ID_FREEDRAW, &CGDIPlusDemoView::OnUpdateFreedraw)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CGDIPlusDemoView::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_ELLIPSE, &CGDIPlusDemoView::OnUpdateEllipse)
	ON_UPDATE_COMMAND_UI(ID_RECTANGLE, &CGDIPlusDemoView::OnUpdateRectangle)
	ON_COMMAND(ID_FILE_OPEN, &CGDIPlusDemoView::OnFileOpen)
END_MESSAGE_MAP()

// CGDIPlusDemoView 생성/소멸

CGDIPlusDemoView::CGDIPlusDemoView()
	: m_nPenSize(0)
	, m_nEraserSize(0)
	, m_ptPrev(0)
	, m_nDrawMode(0)
	, m_bSecond(false)
	, m_pImage(NULL)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_nPenSize = 2;
	m_nEraserSize = 4;
	m_ptPrev = 0;
	m_colorPen = RGB(0, 0, 0);

}

CGDIPlusDemoView::~CGDIPlusDemoView()
{
}

BOOL CGDIPlusDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGDIPlusDemoView 그리기

void CGDIPlusDemoView::OnDraw(CDC* pDC)
{
	CGDIPlusDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	Graphics graphics(pDC->m_hDC);
	if (m_pImage)
	{
		graphics.DrawImage(m_pImage, 0, 0, m_pImage->GetWidth(), m_pImage->GetHeight());
	}
}
		

// CGDIPlusDemoView 인쇄


void CGDIPlusDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGDIPlusDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGDIPlusDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGDIPlusDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CGDIPlusDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGDIPlusDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	// theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGDIPlusDemoView 진단

#ifdef _DEBUG
void CGDIPlusDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIPlusDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIPlusDemoDoc* CGDIPlusDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIPlusDemoDoc)));
	return (CGDIPlusDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDIPlusDemoView 메시지 처리기


void CGDIPlusDemoView::OnPenSize()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CPenSizeDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		m_nPenSize = dlg.m_nPenSize;
	}
}


void CGDIPlusDemoView::OnEraserSize()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CEraserSizeDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		m_nEraserSize = dlg.m_nEraserSize;
	}
}


void CGDIPlusDemoView::OnPenColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_colorPen = dlg.GetColor();
	}
}

void CGDIPlusDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_nDrawMode == FREEDRAW_MODE)
	{
		m_ptPrev = point;
		HCURSOR hCursor = AfxGetApp()->LoadCursorW(IDC_CURSOR_PEN);
		SetCursor(hCursor);
	}
	else
	{
		if (m_bSecond)
		{
			CClientDC dc(this);
			Graphics graphics(dc);
			Gdiplus::Color clr;
			clr.SetFromCOLORREF(m_colorPen);
			Pen pen(Color(clr), m_nPenSize);
			int w = point.x - m_ptPrev.x + 1;
			int h = point.y - m_ptPrev.y + 1;

			if (m_nDrawMode == LINE_MODE)   // 직선 그리기
			{
				graphics.DrawLine(&pen, m_ptPrev.x, m_ptPrev.y, point.x, point.y);
				m_bSecond = false;
			}
			else if (m_nDrawMode == RECTANGLE_MODE)  // 사각형 그리기
			{
				graphics.DrawRectangle(&pen, m_ptPrev.x, m_ptPrev.y, w, h);
			}
			else if (m_nDrawMode == ELLIPSE_MODE)  // 원 그리기
			{
				graphics.DrawEllipse(&pen, m_ptPrev.x, m_ptPrev.y, w, h);
			}
			m_bSecond = false;
		}
		else   // b_bSecond == false
		{
			m_ptPrev = point;
			m_bSecond = true;
		}
	}

	CView::OnLButtonDown(nFlags, point);
}


void CGDIPlusDemoView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_ptPrev = point;
	HCURSOR hCursor = AfxGetApp()->LoadCursorW(IDC_CURSOR_ERASER);
	SetCursor(hCursor);

	CView::OnRButtonDown(nFlags, point);
}


void CGDIPlusDemoView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_nDrawMode == FREEDRAW_MODE)   // 자유 곡선 모드에서만 작동
	{
		CClientDC dc(this);
		Graphics graphics(dc);

		Gdiplus::Color clr;
		clr.SetFromCOLORREF(m_colorPen);

		if (nFlags == MK_LBUTTON)
		{
			// todo: 그리기
			HCURSOR hCursor = AfxGetApp()->LoadCursorW(IDC_CURSOR_PEN);
			SetCursor(hCursor);
			Pen pen(Color(clr), m_nPenSize);
			graphics.DrawLine(&pen, m_ptPrev.x, m_ptPrev.y, point.x, point.y);
			m_ptPrev = point;
		}
		if (nFlags == MK_RBUTTON)
		{
			// todo: 지우기
			// todo: 그리기
			HCURSOR hCursor = AfxGetApp()->LoadCursorW(IDC_CURSOR_ERASER);
			SetCursor(hCursor);
			Pen pen(Color(255, 255, 255), m_nEraserSize);
			graphics.DrawLine(&pen, m_ptPrev.x, m_ptPrev.y, point.x, point.y);
			m_ptPrev = point;
		}
	}
	CView::OnMouseMove(nFlags, point);
}


void CGDIPlusDemoView::OnFreedraw()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = FREEDRAW_MODE;
}


void CGDIPlusDemoView::OnLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = LINE_MODE;
}


void CGDIPlusDemoView::OnRectangle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = RECTANGLE_MODE;
}


void CGDIPlusDemoView::OnEllipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nDrawMode = ELLIPSE_MODE;
}


void CGDIPlusDemoView::OnUpdateFreedraw(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck((m_nDrawMode == FREEDRAW_MODE) ? 1 : 0);
}


void CGDIPlusDemoView::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck((m_nDrawMode == LINE_MODE) ? 1 : 0);
}


void CGDIPlusDemoView::OnUpdateEllipse(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck((m_nDrawMode == ELLIPSE_MODE) ? 1 : 0);
}


void CGDIPlusDemoView::OnUpdateRectangle(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck((m_nDrawMode == RECTANGLE_MODE) ? 1 : 0);
}

void CGDIPlusDemoView::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	static TCHAR BASED_CODE szFilter[] = _T("이미지 파일(*.BMP, *.GIF, *.JPG, *.PNG | *.BMP; *.GIF; *.JPG; *.PNG; *.bmp; *.jpg; *.gif; *.png |모든 파일(*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);   // FALSE : 저장
	if (IDOK == dlg.DoModal())
	{
		CString pathName = dlg.GetPathName();
		m_pImage = Image::FromFile(pathName);
		Invalidate();  // 화면 갱신
	}
}