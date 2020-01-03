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

void MyDialog::Upgrade_Library()
{

	const int li_count_items = 1000;
	m_ctrl_progress.SetRange(0, li_count_items);
	m_ctrl_progress.SetStep(1);

	for (int li_i = 0; li_i < li_count_items; ++li_i)
	{
		m_ctrl_progress.StepIt();
		Sleep(5);
		ProcessMessages();
	}


	OnOK();// it crashes here
	//not if runs from the main thread

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
	Upgrade_Library();
}

void MyDialog::ProcessMessages()
{
	MSG msg;
	CWinApp* pApp = AfxGetApp();
	while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
	{
		pApp->PumpMessage();
	}
}
