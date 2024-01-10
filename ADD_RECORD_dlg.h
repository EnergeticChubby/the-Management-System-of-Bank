#pragma once
#include "afxdialogex.h"


// ADD_RECORD_dlg 对话框

class ADD_RECORD_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_RECORD_dlg)

public:
	ADD_RECORD_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ADD_RECORD_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_RECORD_dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString operator_id;
	CString client_id;
	CString year;
	CString month;
	CString day;
	CString category;
	afx_msg void OnBnClickedButton2();
	CString amount;
	afx_msg void OnBnClickedButton3();
};
