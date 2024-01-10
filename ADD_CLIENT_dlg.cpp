// ADD_CLIENT_dlg.cpp: 实现文件
//
#pragma once
#include "pch.h"
#include "MFCApplication3.h"
#include "afxdialogex.h"
#include "ADD_CLIENT_dlg.h"


// ADD_CLIENT_dlg 对话框

IMPLEMENT_DYNAMIC(ADD_CLIENT_dlg, CDialogEx)

ADD_CLIENT_dlg::ADD_CLIENT_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_CLIENT_dlg, pParent)
	, client_id(_T(""))
	, name(_T(""))
	, passwords(_T(""))
	, address(_T(""))
	, phone_number(_T(""))
	, total_balance(_T(""))
{

}

ADD_CLIENT_dlg::~ADD_CLIENT_dlg()
{
}

void ADD_CLIENT_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, client_id);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, passwords);
	DDX_Text(pDX, IDC_EDIT4, address);
	DDX_Text(pDX, IDC_EDIT5, phone_number);
	DDX_Text(pDX, IDC_EDIT6, total_balance);
}


BEGIN_MESSAGE_MAP(ADD_CLIENT_dlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &ADD_CLIENT_dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &ADD_CLIENT_dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ADD_CLIENT_dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// ADD_CLIENT_dlg 消息处理程序


void ADD_CLIENT_dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ADD_CLIENT_dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
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


void ADD_CLIENT_dlg::OnBnClickedButton3()
{
	OnCancel();
	return;
}
