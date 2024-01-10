// MOD_RECORD_dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "afxdialogex.h"
#include "MOD_RECORD_dlg.h"


// MOD_RECORD_dlg 对话框

IMPLEMENT_DYNAMIC(MOD_RECORD_dlg, CDialogEx)

MOD_RECORD_dlg::MOD_RECORD_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MOD_RECORD_dlg, pParent)
	, opertation_id(_T(""))
	, year(_T(""))
	, month(_T(""))
	, day(_T(""))
	, category(_T(""))
	, amount(_T(""))
{

}

MOD_RECORD_dlg::~MOD_RECORD_dlg()
{
}

void MOD_RECORD_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, opertation_id);
	DDX_Text(pDX, IDC_EDIT3, year);
	DDX_Text(pDX, IDC_EDIT4, month);
	DDX_Text(pDX, IDC_EDIT5, day);
	DDX_Text(pDX, IDC_EDIT6, category);
	DDX_Text(pDX, IDC_EDIT8, amount);
	//  DDX_Text(pDX, IDC_EDIT7, operator_name);
}


BEGIN_MESSAGE_MAP(MOD_RECORD_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &MOD_RECORD_dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &MOD_RECORD_dlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT3, &MOD_RECORD_dlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


// MOD_RECORD_dlg 消息处理程序


void MOD_RECORD_dlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	if (opertation_id == L"" || year == L"" || month == L"" || day == L"" || category == L"" || amount == L"")
	{
		MessageBox(TEXT("有输入内容为空！请重新填写"), TEXT("错误"), MB_ICONERROR);
	}
	else if (opertation_id == TEXT("0"))
	{
		MessageBox(TEXT("操作id不能为0"), TEXT("错误"), MB_ICONERROR);
	}
	else
	{
		OnOK();
		return;
	}
}


void MOD_RECORD_dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
	return;
}


void MOD_RECORD_dlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
