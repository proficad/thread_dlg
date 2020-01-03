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

UINT MyDialog::Upgrade_Library(LPVOID pParam)
{
	MyDialog* pDlg = static_cast<MyDialog*>(pParam);

	const int li_count_items = 1000;
	pDlg->m_ctrl_progress.SetRange(0, li_count_items);
	pDlg->m_ctrl_progress.SetStep(1);

	for (int li_i = 0; li_i < li_count_items; ++li_i)
	{
		pDlg->m_ctrl_progress.StepIt();
	}

	pDlg->OnOK();// it crashes here

	return 0;
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrl_progress);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDialog message handlers


void MyDialog::OnBnClickedButton1()
{
	AfxBeginThread(&MyDialog::Upgrade_Library, this);
}
