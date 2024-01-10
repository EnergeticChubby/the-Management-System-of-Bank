// FIND_CLIENT_dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "afxdialogex.h"
#include "FIND_CLIENT_dlg.h"


// FIND_CLIENT_dlg 对话框

IMPLEMENT_DYNAMIC(FIND_CLIENT_dlg, CDialogEx)

FIND_CLIENT_dlg::FIND_CLIENT_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIND_CLIENT_dlg, pParent)
	, client_id(_T(""))
	, name(_T(""))
	, phone_number(_T(""))
{

}

FIND_CLIENT_dlg::~FIND_CLIENT_dlg()
{
}

void FIND_CLIENT_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, client_id);
	DDX_Text(pDX, IDC_EDIT5, name);
	DDX_Text(pDX, IDC_EDIT2, phone_number);
}


BEGIN_MESSAGE_MAP(FIND_CLIENT_dlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &FIND_CLIENT_dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON9, &FIND_CLIENT_dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON1, &FIND_CLIENT_dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// FIND_CLIENT_dlg 消息处理程序


void FIND_CLIENT_dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void FIND_CLIENT_dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码	
	UpdateData(TRUE);
	int input1 = (client_id != L"" ? 100 : 0);
	int input2 = (name != L"" ? 101 : 0);
	int input3 = (phone_number != L"" ? 102 : 0);
	int sum = input1 + input2 + input3;
	if ((sum > 120) || (sum == 0))
	{
		MessageBox(TEXT("有输入内容有误！请重新填写"), TEXT("错误"), MB_ICONERROR);
	}
	else
	{
		OnOK();
		return;
	}
}


void FIND_CLIENT_dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
	return;
}
