
// MFCApplication3Dlg.h: 头文件
//

#pragma once
#include <vector>
#include "data_structure.h"
#include "record_o_structure.h"
#include "user_structure.h"


// CMFCApplication3Dlg 对话框
class CMFCApplication3Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication3Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl list_record;
	CListCtrl list_client;
	std::vector<int> find_list_index;
	void update_list_client(std::vector<client_structure>);
	void update_list_record(std::vector<record_structure>);
	void find_info_client(std::string id, std::string name, std::string phone_number);
	void find_info_record(std::string opertatoion_id, std::string client_id, std::string operation_name);
	void initcolumn_client();
	void initcolumn_record();
	void initcolumn_record_o();
	void update_find_list_client(std::vector<client_structure>, std::vector<int>);
	void update_find_list_record(std::vector<record_structure>, std::vector<int>);
	void update_find_list_record_o(std::vector<record_o_struc>);
	void LoginIn();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton7();
	CListCtrl list_find;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
};
