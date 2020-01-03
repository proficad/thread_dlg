#pragma once


// MyDialog dialog

class MyDialog : public CDialog
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MyDialog();


	static UINT Upgrade_Library(LPVOID pParam);


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MyDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_ctrl_progress;
	afx_msg void OnBnClickedButton1();
};
