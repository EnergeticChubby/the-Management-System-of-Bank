#pragma once
#include "afxdialogex.h"


// FIND_RECORD_dlg 对话框

class FIND_RECORD_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(FIND_RECORD_dlg)

public:
	FIND_RECORD_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~FIND_RECORD_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIND_RECORD_dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString opertation_id;
	CString client_id;
	CString operator_name;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
