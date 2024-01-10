#pragma once
#include "afxdialogex.h"


// ADD_CLIENT_dlg 对话框

class ADD_CLIENT_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_CLIENT_dlg)

public:
	ADD_CLIENT_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ADD_CLIENT_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_CLIENT_dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString client_id;
	CString name;
	CString passwords;
	CString address;
	CString phone_number;
	CString total_balance;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
