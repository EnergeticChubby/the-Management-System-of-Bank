// FIND_RECORD_dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication3.h"
#include "afxdialogex.h"
#include "FIND_RECORD_dlg.h"


// FIND_RECORD_dlg 对话框

IMPLEMENT_DYNAMIC(FIND_RECORD_dlg, CDialogEx)

FIND_RECORD_dlg::FIND_RECORD_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIND_RECORD_dlg, pParent)
	, opertation_id(_T(""))
	, client_id(_T(""))
	, operator_name(_T(""))
{

}

FIND_RECORD_dlg::~FIND_RECORD_dlg()
{
}

void FIND_RECORD_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, opertation_id);
	DDX_Text(pDX, IDC_EDIT2, client_id);
	DDX_Text(pDX, IDC_EDIT3, operator_name);
}


BEGIN_MESSAGE_MAP(FIND_RECORD_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &FIND_RECORD_dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &FIND_RECORD_dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// FIND_RECORD_dlg 消息处理程序


void FIND_RECORD_dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码	
	UpdateData(TRUE);
	int input1 = (opertation_id != L"" ? 100 : 0);
	int input2 = (client_id != L"" ? 101 : 0);
	int input3 = (operator_name != L"" ? 102 : 0);
	int sum = input1 + input2 + input3;
	if ((sum > 120) || (sum == 0))
	{
		MessageBox(TEXT("输入内容有误！请重新填写"), TEXT("错误"), MB_ICONERROR);
	}
	else
	{
		OnOK();
		return;
	}
}



void FIND_RECORD_dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
	return;
}
