#pragma once
#include "MFCApplication3Dlg.h"
#include "data_structure.h"
#include "record_o.h"
// #include "CDataModify.h"
#include <vector>
#include <string>
#include <atlstr.h>


//int id;
//std::string name;
//std::string passwords;
//std::string address;
//std::string phone_number;
//float total_balance;
void CMFCApplication3Dlg::update_list_client(std::vector<client_structure> list)
{
	list_client.DeleteAllItems();
	CString str;
	for (int i = 0; i < list.size(); i++)
	{
		str.Format(TEXT("%d"), list[i].id);
		list_client.InsertItem(i, str);
		list_client.SetItemText(i, 1, CA2T(list[i].name.c_str()));
		list_client.SetItemText(i, 2, CA2T(list[i].passwords.c_str()));
		list_client.SetItemText(i, 3, CA2T(list[i].address.c_str()));
		list_client.SetItemText(i, 4, CA2T(list[i].phone_number.c_str()));
		list_client.SetItemText(i, 5, CA2T(std::to_string(list[i].total_balance).c_str()));
	}
}

void CMFCApplication3Dlg::update_list_record(std::vector<record_structure> list)
{
	list_record.DeleteAllItems();
	CString str;
	for (int i = 0; i < list.size(); i++)
	{
		str.Format(TEXT("%d"), list[i].opertation_id);
		list_record.InsertItem(i, str);
		list_record.SetItemText(i, 1, CA2T(std::to_string(list[i].client_id).c_str()));
		std::string data = std::to_string(list[i].year) + "/" + std::to_string(list[i].month) + "/" + std::to_string(list[i].day);
		list_record.SetItemText(i, 2, CA2T(data.c_str()));
		data = list[i].category ? "存款" : "取款";
		list_record.SetItemText(i, 3, CA2T(data.c_str()));
		list_record.SetItemText(i, 4, CA2T(std::to_string(list[i].amount).c_str()));
		list_record.SetItemText(i, 5, CA2T(list[i].operator_name.c_str()));
		list_record.SetItemText(i, 6, CA2T(std::to_string(list[i].current_amount).c_str()));
	}
}

void CMFCApplication3Dlg::initcolumn_client()
{
	// 包括编号、客户姓名、支取密码、客户地址、客户电话、账户总金额
	DWORD   dwStyle_list = list_find.GetExtendedStyle();
	dwStyle_list |= LVS_EX_GRIDLINES;     //网格线
	list_find.SetExtendedStyle(dwStyle_list);    //设置扩展风格
	CString client_label_text[] = { TEXT("客户编号"), TEXT("客户姓名"), TEXT("支取密码"), TEXT("客户地址"), TEXT("客户电话"), TEXT("账户总金额") };
	int client_label_width[] = { 100, 100, 100, 100, 100, 200 };
	for (int i = 0; i != sizeof(client_label_width) / sizeof(int); ++i)
	{
		list_find.InsertColumn(i, client_label_text[i], 0, client_label_width[i]);
	}
}

void CMFCApplication3Dlg::initcolumn_record()
{
	// 包括编号、日期、类别、存取数目、经办人
	DWORD   dwStyle_record = list_find.GetExtendedStyle();
	dwStyle_record |= LVS_EX_GRIDLINES;     //网格线
	list_find.SetExtendedStyle(dwStyle_record);    //设置扩展风格
	CString record_label_text[] = { TEXT("操作编号"), TEXT("客户编号"), TEXT("日期"), TEXT("类别"), TEXT("存取数目"), TEXT("经办人"), TEXT("操作后金额") };
	int record_label_width[] = { 100, 100, 100, 100, 100, 100, 100 };
	for (int i = 0; i != sizeof(record_label_width) / sizeof(int); ++i)
	{
		list_find.InsertColumn(i, record_label_text[i], 0, record_label_width[i]);
	}
}

void CMFCApplication3Dlg::update_find_list_client(std::vector<client_structure> list, std::vector<int> index_list)
{
	list_find.DeleteAllItems();
	CString str;
	for (int i = 0; i < index_list.size(); i++)
	{
		int index = index_list[i];
		str.Format(TEXT("%d"), list[index].id);
		list_find.InsertItem(i, str);
		list_find.SetItemText(i, 1, CA2T(list[index].name.c_str()));
		list_find.SetItemText(i, 2, CA2T(list[index].passwords.c_str()));
		list_find.SetItemText(i, 3, CA2T(list[index].address.c_str()));
		list_find.SetItemText(i, 4, CA2T(list[index].phone_number.c_str()));
		list_find.SetItemText(i, 5, CA2T(std::to_string(list[index].total_balance).c_str()));
	}
}

void CMFCApplication3Dlg::update_find_list_record(std::vector<record_structure> list, std::vector<int> index_list)
{
	list_find.DeleteAllItems();
	CString str;
	for (int i = 0; i < index_list.size(); i++)
	{
		int index = index_list[i];
		str.Format(TEXT("%d"), list[index].opertation_id);
		list_find.InsertItem(i, str);
		list_find.SetItemText(i, 1, CA2T(std::to_string(list[index].client_id).c_str()));
		std::string data = std::to_string(list[index].year) + "/" + std::to_string(list[i].month) + "/" + std::to_string(list[i].day);
		list_find.SetItemText(i, 2, CA2T(data.c_str()));
		data = list[i].category ? "存款" : "取款";
		list_find.SetItemText(i, 3, CA2T(data.c_str()));
		list_find.SetItemText(i, 4, CA2T(std::to_string(list[index].amount).c_str()));
		list_find.SetItemText(i, 5, CA2T(list[index].operator_name.c_str()));
		list_find.SetItemText(i, 6, CA2T(std::to_string(list[index].current_amount).c_str()));
	}
}

void CMFCApplication3Dlg::initcolumn_record_o()
{
	list_find.DeleteAllItems();
	// 包括编号、日期、类别、存取数目、经办人
	DWORD   dwStyle_record = list_find.GetExtendedStyle();
	dwStyle_record |= LVS_EX_GRIDLINES;     //网格线
	list_find.SetExtendedStyle(dwStyle_record);    //设置扩展风格
	CString record_label_text[] = { TEXT("操作时间"), TEXT("行为"), TEXT("操作者编号"), TEXT("客户编号"), TEXT("操作编号") };
	int record_label_width[] = { 220, 100, 100, 100, 100 };
	for (int i = 0; i != sizeof(record_label_width) / sizeof(int); ++i)
	{
		list_find.InsertColumn(i, record_label_text[i], 0, record_label_width[i]);
	}
}

void CMFCApplication3Dlg::update_find_list_record_o(std::vector<record_o_struc> list)
{
	list_find.DeleteAllItems();
	CString str;
	for (int i = 0; i < list.size(); i++)
	{
		str = CA2T(list[i].time.c_str());
		list_find.InsertItem(i, str);
		std::string operator_code_trans;
		switch (list[i].operator_code)
		{
		case 4:
			operator_code_trans = "增加记录";
			break;
		case 14:
			operator_code_trans = "删除记录";
			break;
		case 24:
			operator_code_trans = "修改记录";
			break;
		case 5:
			operator_code_trans = "增加用户";
			break;
		case 15:
			operator_code_trans = "删除用户";
			break;
		case 25:
			operator_code_trans = "修改用户";
			break;
		}
		list_find.SetItemText(i, 1, CA2T(operator_code_trans.c_str()));
		operator_code_trans = "No Record";
		list_find.SetItemText(i, 2, CA2T(std::to_string(list[i].operator_id).c_str()));
		if (list[i].client_id != 0)
			list_find.SetItemText(i, 3, CA2T(std::to_string(list[i].client_id).c_str()));
		else
			list_find.SetItemText(i, 3, CA2T(operator_code_trans.c_str()));
		if (list[i].record_id != 0)
			list_find.SetItemText(i, 4, CA2T(std::to_string(list[i].record_id).c_str()));
		else
			list_find.SetItemText(i, 4, CA2T(operator_code_trans.c_str()));
	}
}