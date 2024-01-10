
// MFCApplication3Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include "CDataModify.h"
#include "list_control.h"
#include "ADD_CLIENT_dlg.h"
#include "ADD_RECORD_dlg.h"
#include "MOD_CLIENT_dlg.h"
#include "MOD_RECORD_dlg.h"
#include "FIND_CLIENT_dlg.h"
#include "FIND_RECORD_dlg.h"
#include "LOGIN_dlg.h"
#include "IDD_MOD_USER_dlg.h"
#include "user.h"
#include <windows.h>

#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CDataModify dataModify;
record_o record_o_a;
user user_a;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 对话框



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list_record);
	DDX_Control(pDX, IDC_LIST3, list_client);
	DDX_Control(pDX, IDC_LIST2, list_find);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMFCApplication3Dlg::OnLvnItemchangedList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST3, &CMFCApplication3Dlg::OnLvnItemchangedList3)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication3Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication3Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication3Dlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 消息处理程序

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	dataModify.open_client();
	dataModify.open_record();
	record_o_a.open_file();
	user_a.open_file();
	LoginIn();

	

	// TODO: 在此添加额外的初始化代码
	// 包括编号、日期、类别、存取数目、经办人
	DWORD   dwStyle_record = list_record.GetExtendedStyle();
	dwStyle_record |= LVS_EX_FULLROWSELECT;
	dwStyle_record |= LVS_EX_GRIDLINES;     //网格线
	list_record.SetExtendedStyle(dwStyle_record);    //设置扩展风格
	CString record_label_text[] = { TEXT("操作编号"), TEXT("客户编号"), TEXT("日期"), TEXT("类别"), TEXT("存取数目"), TEXT("经办人"), TEXT("操作后金额") };
	int record_label_width[] = {100, 100, 100, 100, 100, 100, 100};
	for (int i = 0; i != sizeof(record_label_width) / sizeof(int); ++i)
	{
		list_record.InsertColumn(i, record_label_text[i], 0, record_label_width[i]);
	}
	// 包括编号、客户姓名、支取密码、客户地址、客户电话、账户总金额
	DWORD   dwStyle_list = list_client.GetExtendedStyle();
	dwStyle_list |= LVS_EX_FULLROWSELECT;
	dwStyle_list |= LVS_EX_GRIDLINES;     //网格线
	list_client.SetExtendedStyle(dwStyle_list);    //设置扩展风格
	CString client_label_text[] = { TEXT("客户编号"), TEXT("客户姓名"), TEXT("支取密码"), TEXT("客户地址"), TEXT("客户电话"), TEXT("账户总金额")};
	int client_label_width[] = {100, 100, 100, 100, 100, 200};
	for (int i = 0; i != sizeof(client_label_width) / sizeof(int); ++i)
	{
		list_client.InsertColumn(i, client_label_text[i], 0, client_label_width[i]);
	}

	update_list_client(dataModify.info_client_list);
	update_list_record(dataModify.info_record_list);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCApplication3Dlg::OnLvnItemchangedList3(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void CMFCApplication3Dlg::LoginIn()
{
	LOGIN_dlg dlg;
	dlg.DoModal();
	std::string user_id = CW2A(dlg.user_id);
	std::string passwords = CW2A(dlg.passwords);
	std::vector<int> find_list = user_a.find_user(user_id, passwords);
	if (!user_a.login_user(user_id, passwords))
	{
		MessageBox(TEXT("登陆失败"), TEXT("错误"), MB_ICONERROR);
		exit(0);
	}
}

void CMFCApplication3Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD_CLIENT_dlg dlg;
	if (IDOK == dlg.DoModal())
	{
		int id = std::atoi(CW2A(dlg.client_id));
		std::string name = CW2A(dlg.name);
		std::string passwords = CW2A(dlg.passwords);
		std::string address = CW2A(dlg.address);
		std::string phone_number = CW2A(dlg.phone_number);
		float total_balance = std::atof(CW2A(dlg.total_balance));
		client_structure A(id, name, passwords, address, phone_number, total_balance);
		dataModify.add_client(A);
		record_o_a.add_record_o(5, std::stoi(user_a.user_id_c), id, NULL);
	}
	update_list_client(dataModify.info_client_list);
	dataModify.save_client();
}


void CMFCApplication3Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD_RECORD_dlg dlg;
	if (IDOK == dlg.DoModal())
	{
		int operation_id = std::atoi(CW2A(dlg.operator_id));
		int client_id = std::atoi(CW2A(dlg.client_id));
		int year = std::atoi(CW2A(dlg.year));
		int month = std::atoi(CW2A(dlg.month));
		int day = std::atoi(CW2A(dlg.day));
		int category= std::atoi(CW2A(dlg.category));
		float amount = std::atof(CW2A(dlg.amount));
		std::string operator_name = user_a.user_id_c;
		std::vector<int> find_list = dataModify.find_client(std::to_string(client_id), 0);
		float current_amount = dataModify.info_client_list[find_list[0]].total_balance + (category ? amount : (-amount));
		dataModify.info_client_list[find_list[0]].total_balance = current_amount;
		record_structure A(operation_id, client_id, year, month, day, category, amount, operator_name, current_amount);
		dataModify.add_record(A);
		record_o_a.add_record_o(4, std::stoi(user_a.user_id_c), NULL, operation_id);
	}
	update_list_record(dataModify.info_record_list);
	dataModify.save_record();
	update_list_client(dataModify.info_client_list);
	dataModify.save_client();
}


void CMFCApplication3Dlg::OnBnClickedButton1()
{
	MOD_RECORD_dlg dlg;
	CDataModify dataModify_b;
	dataModify_b = dataModify;
	dataModify.info_client_list;
	if (IDOK == dlg.DoModal())
	{
		int operation_id = std::atoi(CW2A(dlg.opertation_id));
		std::vector<int> opertation_index_list = dataModify_b.find_record(std::to_string(operation_id), 0);
		if (opertation_index_list.size() != 1)
		{
			MessageBox(TEXT("不存在此操作编号"), TEXT("错误"), MB_ICONERROR);
			return;
		}
		int opertation_index = opertation_index_list[0];
		std::string operator_name = dataModify.info_record_list[opertation_index].operator_name;
		if (operator_name != user_a.user_id_c)
		{
			MessageBox(TEXT("无法修改非此账号操作的记录"), TEXT("错误"), MB_ICONERROR);
			return;
		}
		record_o_a.add_record_o(24, std::stoi(user_a.user_id_c), NULL, operation_id);
		int client_id = dataModify.info_record_list[opertation_index].client_id;
		int year = std::atoi(CW2A(dlg.year));
		int month = std::atoi(CW2A(dlg.month));
		int day = std::atoi(CW2A(dlg.day));
		int category = std::atoi(CW2A(dlg.category));
		float amount = std::atof(CW2A(dlg.amount));
		std::vector<int> find_list = dataModify.find_client(std::to_string(client_id), 0);
		record_structure record_b = dataModify_b.info_record_list[opertation_index];
		float current_amount_b = record_b.current_amount;
		float money_ope_b = -(record_b.category ? record_b.amount : (-record_b.amount));
		float money_ope = (category ? amount : (-amount));
		float current_amount = current_amount_b + money_ope_b + money_ope;
		dataModify.info_client_list[find_list[0]].total_balance = current_amount;

		std::vector<int> find_list_2 = dataModify.find_record(std::to_string(operation_id), 0);
		record_structure A(operation_id, client_id, year, month, day, category, amount, operator_name, current_amount);
		int index = find_list_2[0];
		dataModify.mod_record(index, A);

	}
	update_list_record(dataModify.info_record_list);
	dataModify.save_record();
	update_list_client(dataModify.info_client_list);
	dataModify.save_client();
}

void CMFCApplication3Dlg::OnBnClickedButton6()
{
	MOD_CLIENT_dlg dlg;
	if (IDOK == dlg.DoModal())
	{
		int id = std::atoi(CW2A(dlg.client_id));
		std::string name = CW2A(dlg.name);
		std::string passwords = CW2A(dlg.passwords);
		std::string address = CW2A(dlg.address);
		std::string phone_number = CW2A(dlg.phone_number);
		float total_balance = std::atof(CW2A(dlg.total_balance));
		client_structure A(id, name, passwords, address, phone_number, total_balance);
		std::vector<int> find_list = dataModify.find_client(std::to_string(id), 0);
		int index = find_list[0];
		dataModify.mod_client(index, A);
		record_o_a.add_record_o(15, std::stoi(user_a.user_id_c), id, NULL);
	}
	update_list_client(dataModify.info_client_list);
	dataModify.save_client();
}


void CMFCApplication3Dlg::OnBnClickedButton8()
{
	FIND_RECORD_dlg dlg;
	if (IDOK == dlg.DoModal())
	{
		int index_number = 0;
		int* index_number_p = &index_number;
		std::string opertation_id = CW2A(dlg.opertation_id);
		std::string client_id = CW2A(dlg.client_id);
		std::string operator_name = CW2A(dlg.operator_name);
		find_info_record(opertation_id, client_id, operator_name);
		while (list_find.DeleteColumn(0));
		initcolumn_record();
		update_find_list_record(dataModify.info_record_list, find_list_index);
	}
}



void CMFCApplication3Dlg::OnBnClickedButton7()
{
	FIND_CLIENT_dlg dlg;
	if (IDOK == dlg.DoModal())
	{
		int index_number = 0;
		int* index_number_p = &index_number;
		std::string id = CW2A(dlg.client_id);
		std::string name = CW2A(dlg.name);
		std::string phone_number = CW2A(dlg.phone_number);
		find_info_client(id, name, phone_number);
		while (list_find.DeleteColumn(0));
		initcolumn_client();
		update_find_list_client(dataModify.info_client_list, find_list_index);
	}
}

void CMFCApplication3Dlg::find_info_client(std::string id, std::string name, std::string phone_number)
{
	int input1 = (id != "" ? 100 : 0);
	int input2 = (name != "" ? 101 : 0);
	int input3 = (phone_number != "" ? 102 : 0);
	int sum = input1 + input2 + input3;
	if (sum == 100)
	{
		find_list_index = dataModify.find_client(id, 0);
	}
	else if (sum == 101)
	{
		find_list_index = dataModify.find_client(name, 1);
	}
	else
	{
		find_list_index = dataModify.find_client(phone_number, 2);
	}
}

void CMFCApplication3Dlg::find_info_record(std::string opertation_id, std::string client_id, std::string operator_name)
{
	int input1 = (opertation_id != "" ? 100 : 0);
	int input2 = (client_id != "" ? 101 : 0);
	int input3 = (operator_name != "" ? 102 : 0);
	int sum = input1 + input2 + input3;
	if (sum == 100)
	{
		find_list_index = dataModify.find_record(opertation_id, 0);
	}
	else if (sum == 101)
	{
		find_list_index = dataModify.find_record(client_id, 1);
	}
	else
	{
		find_list_index = dataModify.find_record(operator_name, 2);
	}
}



void CMFCApplication3Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = list_client.GetSelectionMark();
	if (index > -1)
	{
		record_o_a.add_record_o(15, std::stoi(user_a.user_id_c), dataModify.info_client_list[index].id, NULL);
		dataModify.del_client(index);
		update_list_client(dataModify.info_client_list);
		dataModify.save_client();
	}
}

void CMFCApplication3Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = list_record.GetSelectionMark();
	if (index > -1)
	{
		record_o_a.add_record_o(14, std::stoi(user_a.user_id_c), NULL, dataModify.info_record_list[index].opertation_id);
		dataModify.del_record(index);
		update_list_record(dataModify.info_record_list);
		dataModify.save_record();
	}
}

void CMFCApplication3Dlg::OnBnClickedButton9()
{
	while (list_find.DeleteColumn(0));
	initcolumn_record_o();
	update_find_list_record_o(record_o_a.record_o_list);
}


void CMFCApplication3Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	IDD_MOD_USER_dlg dlg;
	if (IDOK == dlg.DoModal())
	{
		int index_number = 0;
		int* index_number_p = &index_number;
		std::string user_id = CW2A(dlg.user_id);
		std::string passwords = CW2A(dlg.passwords);
		std::string passwords_c = CW2A(dlg.passwords_c);
		if (passwords_c == "")
		{
			if (user_a.find_user_1(user_id))
			{
				std::vector<int> find_list = user_a.find_user(user_id, passwords);
				if (find_list.size() == 1)
				{
					user_a.del_user(user_id, passwords);
					MessageBox(TEXT("删除成功"), TEXT("成功"), MB_ICONINFORMATION);
				}
				else
				{
					MessageBox(TEXT("删除失败"), TEXT("错误"), MB_ICONERROR);
				}
			}
			else
			{
				user_a.add_user(user_id, passwords);
				MessageBox(TEXT("增加成功"), TEXT("成功"), MB_ICONINFORMATION);
			}
		}
		else
		{
			if (user_a.find_user_1(user_id))
			{
				std::vector<int> find_list = user_a.find_user(user_id, passwords);
				if (find_list.size() == 1)
				{
					user_a.mod_user(user_id, passwords, passwords_c);
					MessageBox(TEXT("修改成功"), TEXT("成功"), MB_ICONINFORMATION);
				}
				else
				{
					MessageBox(TEXT("修改失败"), TEXT("错误"), MB_ICONERROR);
				}
			}
		}
	}
}
