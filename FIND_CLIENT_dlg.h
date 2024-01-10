#pragma once
#include "afxdialogex.h"


// FIND_CLIENT_dlg 对话框

class FIND_CLIENT_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(FIND_CLIENT_dlg)

public:
	FIND_CLIENT_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~FIND_CLIENT_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIND_CLIENT_dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString client_id;
	CString name;
	afx_msg void OnEnChangeEdit2();
	CString phone_number;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton1();
};
