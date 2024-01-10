// MOD_CLIENT_dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "afxdialogex.h"
#include "MOD_CLIENT_dlg.h"


// MOD_CLIENT_dlg 对话框

IMPLEMENT_DYNAMIC(MOD_CLIENT_dlg, CDialogEx)

MOD_CLIENT_dlg::MOD_CLIENT_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MOD_CLIENT_dlg, pParent)
{

}

MOD_CLIENT_dlg::~MOD_CLIENT_dlg()
{
}

void MOD_CLIENT_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT2, client_id);
	//  DDX_Text(pDX, IDC_EDIT1, name);
	//  DDX_Text(pDX, IDC_EDIT3, phone_number);
	DDX_Text(pDX, IDC_EDIT1, client_id);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, passwords);
	DDX_Text(pDX, IDC_EDIT4, address);
	DDX_Text(pDX, IDC_EDIT5, phone_number);
	DDX_Text(pDX, IDC_EDIT6, total_balance);
}


BEGIN_MESSAGE_MAP(MOD_CLIENT_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &MOD_CLIENT_dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &MOD_CLIENT_dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// MOD_CLIENT_dlg 消息处理程序


void MOD_CLIENT_dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
	return;
}


void MOD_CLIENT_dlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	if (client_id == L"" || name == L"" || passwords == L"" || address == L"" || phone_number == L"" || total_balance == L"")
	{
		MessageBox(TEXT("有输入内容为空！请重新填写"), TEXT("错误"), MB_ICONERROR);
	}
	else if (client_id == TEXT("0"))
	{
		MessageBox(TEXT("客户id不能为0"), TEXT("错误"), MB_ICONERROR);
	}
	else
	{
		OnOK();
		return;
	}
}
