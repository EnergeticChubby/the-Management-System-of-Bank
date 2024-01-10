#pragma once
#include "afxdialogex.h"


// LOGIN_dlg 对话框

class LOGIN_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN_dlg)

public:
	LOGIN_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LOGIN_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN_dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString user_id;
	CString passwords;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnEnChangeEdit2();
};
