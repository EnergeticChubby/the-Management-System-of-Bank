// ADD_RECORD_dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "afxdialogex.h"
#include "ADD_RECORD_dlg.h"


// ADD_RECORD_dlg 对话框

IMPLEMENT_DYNAMIC(ADD_RECORD_dlg, CDialogEx)

ADD_RECORD_dlg::ADD_RECORD_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_RECORD_dlg, pParent)
	, operator_id(_T(""))
	, client_id(_T(""))
	, year(_T(""))
	, month(_T(""))
	, day(_T(""))
	, category(_T(""))
	, amount(_T(""))
{

}

ADD_RECORD_dlg::~ADD_RECORD_dlg()
{
}

void ADD_RECORD_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, operator_id);
	DDX_Text(pDX, IDC_EDIT2, client_id);
	DDX_Text(pDX, IDC_EDIT3, year);
	DDX_Text(pDX, IDC_EDIT4, month);
	DDX_Text(pDX, IDC_EDIT5, day);
	DDX_Text(pDX, IDC_EDIT6, category);
	DDX_Text(pDX, IDC_EDIT8, amount);
}


BEGIN_MESSAGE_MAP(ADD_RECORD_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ADD_RECORD_dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ADD_RECORD_dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// ADD_RECORD_dlg 消息处理程序


void ADD_RECORD_dlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	if (operator_id == L"" ||  client_id== L"" || year == L"" || month == L"" || day == L"" || category == L"" || amount==L"")
	{
		MessageBox(TEXT("有输入内容为空！请重新填写"), TEXT("错误"), MB_ICONERROR);
	}
	else if (client_id == TEXT("0") || operator_id == TEXT("0"))
	{
		MessageBox(TEXT("客户id和操作id不能为0"), TEXT("错误"), MB_ICONERROR);
	}
	else
	{
		OnOK();
		return;
	}
}


void ADD_RECORD_dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
	return;
}
