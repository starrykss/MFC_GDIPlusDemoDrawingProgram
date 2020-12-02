
// GDIPlusDemoView.cpp : CGDIPlusDemoView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "GDIPlusDemo.h"
#endif

#include "GDIPlusDemoDoc.h"
#include "GDIPlusDemoView.h"

// �߰�
#include "PenSizeDlg.h"
#include "EraserSizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDIPlusDemoView

IMPLEMENT_DYNCREATE(CGDIPlusDemoView, CView)

BEGIN_MESSAGE_MAP(CGDIPlusDemoView, CView)
	// ǥ�� �μ� ����Դϴ�.
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

// CGDIPlusDemoView ����/�Ҹ�

CGDIPlusDemoView::CGDIPlusDemoView()
	: m_nPenSize(0)
	, m_nEraserSize(0)
	, m_ptPrev(0)
	, m_nDrawMode(0)
	, m_bSecond(false)
	, m_pImage(NULL)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CGDIPlusDemoView �׸���

void CGDIPlusDemoView::OnDraw(CDC* pDC)
{
	CGDIPlusDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	Graphics graphics(pDC->m_hDC);
	if (m_pImage)
	{
		graphics.DrawImage(m_pImage, 0, 0, m_pImage->GetWidth(), m_pImage->GetHeight());
	}
}
		

// CGDIPlusDemoView �μ�


void CGDIPlusDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGDIPlusDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CGDIPlusDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CGDIPlusDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CGDIPlusDemoView ����

#ifdef _DEBUG
void CGDIPlusDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIPlusDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIPlusDemoDoc* CGDIPlusDemoView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIPlusDemoDoc)));
	return (CGDIPlusDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDIPlusDemoView �޽��� ó����


void CGDIPlusDemoView::OnPenSize()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CPenSizeDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		m_nPenSize = dlg.m_nPenSize;
	}
}


void CGDIPlusDemoView::OnEraserSize()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CEraserSizeDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		m_nEraserSize = dlg.m_nEraserSize;
	}
}


void CGDIPlusDemoView::OnPenColor()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_colorPen = dlg.GetColor();
	}
}

void CGDIPlusDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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

			if (m_nDrawMode == LINE_MODE)   // ���� �׸���
			{
				graphics.DrawLine(&pen, m_ptPrev.x, m_ptPrev.y, point.x, point.y);
				m_bSecond = false;
			}
			else if (m_nDrawMode == RECTANGLE_MODE)  // �簢�� �׸���
			{
				graphics.DrawRectangle(&pen, m_ptPrev.x, m_ptPrev.y, w, h);
			}
			else if (m_nDrawMode == ELLIPSE_MODE)  // �� �׸���
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_ptPrev = point;
	HCURSOR hCursor = AfxGetApp()->LoadCursorW(IDC_CURSOR_ERASER);
	SetCursor(hCursor);

	CView::OnRButtonDown(nFlags, point);
}


void CGDIPlusDemoView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_nDrawMode == FREEDRAW_MODE)   // ���� � ��忡���� �۵�
	{
		CClientDC dc(this);
		Graphics graphics(dc);

		Gdiplus::Color clr;
		clr.SetFromCOLORREF(m_colorPen);

		if (nFlags == MK_LBUTTON)
		{
			// todo: �׸���
			HCURSOR hCursor = AfxGetApp()->LoadCursorW(IDC_CURSOR_PEN);
			SetCursor(hCursor);
			Pen pen(Color(clr), m_nPenSize);
			graphics.DrawLine(&pen, m_ptPrev.x, m_ptPrev.y, point.x, point.y);
			m_ptPrev = point;
		}
		if (nFlags == MK_RBUTTON)
		{
			// todo: �����
			// todo: �׸���
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nDrawMode = FREEDRAW_MODE;
}


void CGDIPlusDemoView::OnLine()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nDrawMode = LINE_MODE;
}


void CGDIPlusDemoView::OnRectangle()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nDrawMode = RECTANGLE_MODE;
}


void CGDIPlusDemoView::OnEllipse()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nDrawMode = ELLIPSE_MODE;
}


void CGDIPlusDemoView::OnUpdateFreedraw(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck((m_nDrawMode == FREEDRAW_MODE) ? 1 : 0);
}


void CGDIPlusDemoView::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck((m_nDrawMode == LINE_MODE) ? 1 : 0);
}


void CGDIPlusDemoView::OnUpdateEllipse(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck((m_nDrawMode == ELLIPSE_MODE) ? 1 : 0);
}


void CGDIPlusDemoView::OnUpdateRectangle(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck((m_nDrawMode == RECTANGLE_MODE) ? 1 : 0);
}

void CGDIPlusDemoView::OnFileOpen()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	static TCHAR BASED_CODE szFilter[] = _T("�̹��� ����(*.BMP, *.GIF, *.JPG, *.PNG | *.BMP; *.GIF; *.JPG; *.PNG; *.bmp; *.jpg; *.gif; *.png |��� ����(*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);   // FALSE : ����
	if (IDOK == dlg.DoModal())
	{
		CString pathName = dlg.GetPathName();
		m_pImage = Image::FromFile(pathName);
		Invalidate();  // ȭ�� ����
	}
}