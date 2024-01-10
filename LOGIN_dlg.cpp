// LOGIN_dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "afxdialogex.h"
#include "LOGIN_dlg.h"


// LOGIN_dlg 对话框

IMPLEMENT_DYNAMIC(LOGIN_dlg, CDialogEx)

LOGIN_dlg::LOGIN_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN_dlg, pParent)
	, user_id(_T(""))
	, passwords(_T(""))
{

}

LOGIN_dlg::~LOGIN_dlg()
{
}

void LOGIN_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user_id);
	DDX_Text(pDX, IDC_EDIT2, passwords);
}


BEGIN_MESSAGE_MAP(LOGIN_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LOGIN_dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON9, &LOGIN_dlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// LOGIN_dlg 消息处理程序


void LOGIN_dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void LOGIN_dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (user_id == L"" || passwords == L"")
	{
		MessageBox(TEXT("有输入内容为空！请重新填写"), TEXT("错误"), MB_ICONERROR);
	}
	else
	{
		OnOK();
		return;
	}
}
