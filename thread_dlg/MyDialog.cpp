// MyDialog.cpp : implementation file
//

#include "stdafx.h"
#include "thread_dlg.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog dialog

IMPLEMENT_DYNAMIC(MyDialog, CDialog)

MyDialog::MyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MyDialog, pParent)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrl_progress);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
END_MESSAGE_MAP()


// MyDialog message handlers
