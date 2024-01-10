// IDD_MOD_USER_dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "afxdialogex.h"
#include "IDD_MOD_USER_dlg.h"
#include <string>


// IDD_MOD_USER_dlg 对话框

IMPLEMENT_DYNAMIC(IDD_MOD_USER_dlg, CDialogEx)

IDD_MOD_USER_dlg::IDD_MOD_USER_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, user_id(_T(""))
	, passwords(_T(""))
	, passwords_c(_T(""))
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

IDD_MOD_USER_dlg::~IDD_MOD_USER_dlg()
{
}

void IDD_MOD_USER_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user_id);
	DDX_Text(pDX, IDC_EDIT2, passwords);
	DDX_Text(pDX, IDC_EDIT6, passwords_c);
}


BEGIN_MESSAGE_MAP(IDD_MOD_USER_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &IDD_MOD_USER_dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON9, &IDD_MOD_USER_dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON11, &IDD_MOD_USER_dlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// IDD_MOD_USER_dlg 消息处理程序

bool IDD_MOD_USER_dlg::string_number()
{
	std::string user_id_s = CW2A(user_id);
	for (int i = 0; i < user_id_s.size(); i++)
	{
		int tmp = (int)user_id_s[i];
		if (tmp >= 48 && tmp <= 57)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

void IDD_MOD_USER_dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (user_id == L"" || passwords == L"")
	{
		MessageBox(TEXT("输入有误"), TEXT("错误"), MB_ICONERROR);
	}
	else if(passwords_c != L"")
	{
		MessageBox(TEXT("请勿输入新密码"), TEXT("错误"), MB_ICONERROR);
	}
	else if (!string_number())
	{
		MessageBox(TEXT("操作者编号仅为数字组成"), TEXT("错误"), MB_ICONERROR);
	}
	else
	{
		OnOK();
		return;
	}
}


void IDD_MOD_USER_dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (user_id == L"" || passwords == L"" || passwords_c == L"")
	{
		MessageBox(TEXT("输入有误"), TEXT("错误"), MB_ICONERROR);
	}
	else if (!string_number())
	{
		MessageBox(TEXT("操作者编号仅为数字组成"), TEXT("错误"), MB_ICONERROR);
	}
	else
	{
		OnOK();
		return;
	}
}


void IDD_MOD_USER_dlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
	return;
}
