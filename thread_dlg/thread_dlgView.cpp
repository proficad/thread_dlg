
// thread_dlgView.cpp : implementation of the CthreaddlgView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "thread_dlg.h"
#endif

#include "thread_dlgDoc.h"
#include "thread_dlgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CthreaddlgView

IMPLEMENT_DYNCREATE(CthreaddlgView, CView)

BEGIN_MESSAGE_MAP(CthreaddlgView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CthreaddlgView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CthreaddlgView construction/destruction

CthreaddlgView::CthreaddlgView() noexcept
{
	// TODO: add construction code here

}

CthreaddlgView::~CthreaddlgView()
{
}

BOOL CthreaddlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CthreaddlgView drawing

void CthreaddlgView::OnDraw(CDC* pDC)
{
	CthreaddlgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect l_rect;
	GetClientRect(l_rect);
	pDC->DrawText(_T("click here"), l_rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
}


// CthreaddlgView printing


void CthreaddlgView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CthreaddlgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CthreaddlgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CthreaddlgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CthreaddlgView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CthreaddlgView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CthreaddlgView diagnostics

#ifdef _DEBUG
void CthreaddlgView::AssertValid() const
{
	CView::AssertValid();
}

void CthreaddlgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CthreaddlgDoc* CthreaddlgView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CthreaddlgDoc)));
	return (CthreaddlgDoc*)m_pDocument;
}
#endif //_DEBUG


// CthreaddlgView message handlers
