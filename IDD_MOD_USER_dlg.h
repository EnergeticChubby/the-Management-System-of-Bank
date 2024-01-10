#pragma once
#include "afxdialogex.h"


// IDD_MOD_USER_dlg 对话框

class IDD_MOD_USER_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(IDD_MOD_USER_dlg)

public:
	IDD_MOD_USER_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~IDD_MOD_USER_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString user_id;
	CString passwords;
	CString passwords_c;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton11();
	bool string_number();
};
