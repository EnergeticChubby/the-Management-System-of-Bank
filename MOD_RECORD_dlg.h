#pragma once
#include "afxdialogex.h"


// MOD_RECORD_dlg 对话框

class MOD_RECORD_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(MOD_RECORD_dlg)

public:
	MOD_RECORD_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MOD_RECORD_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOD_RECORD_dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString opertation_id;
//	CString client_id;
	CString year;
	CString month;
	CString day;
	CString category;
	CString amount;
//	CString operator_name;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit3();
};
