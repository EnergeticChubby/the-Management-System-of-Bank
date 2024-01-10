#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "data_structure.h"
#include "pch.h"

class CDataModify
{
private:
	std::string File_path_client = "client.txt";
	std::string File_path_record = "record.txt";
public:
	std::vector<client_structure> info_client_list;
	std::vector<record_structure> info_record_list;
	bool open_client();
	void add_client(client_structure info_client);
	void del_client(int index_client);
	void mod_client(int index_clent, client_structure info_client);
	bool save_client();
	std::vector<int> find_client(std::string data, int a);

	bool open_record();
	void add_record(record_structure info_record);
	void del_record(int index_record);
	void mod_record(int index_record, record_structure info_record);
	bool save_record();
	std::vector<int> find_record(std::string data, int a);

	std::vector<client_structure> info_client;
	std::vector<record_structure> info_record;
};

bool CDataModify::open_client()
{
	std::ifstream in(File_path_client, std::ios::in);

	if (!in.is_open())
	{
		return false;
	}
	std::string str1;
	int number = 0; // 用户总数 * 6
	while (getline(in, str1))
	{
		++number;
	};
	in.close();
	std::ifstream in_2(File_path_client, std::ios::in);
	for (int i = 0; i * 6 != number; ++i)
	{
		getline(in_2, str1);
		int id = std::stoi(str1.c_str());
		getline(in_2, str1);
		std::string name = str1.c_str();
		getline(in_2, str1);
		std::string passwords = str1.c_str();
		getline(in_2, str1);
		std::string address = str1.c_str();
		getline(in_2, str1);
		std::string phone_number = str1.c_str();
		getline(in_2, str1);
		float total_balance = std::stof(str1.c_str());
		client_structure A(id, name, passwords, address, phone_number, total_balance);
		info_client_list.push_back(A);
	}
	return true;
}

bool CDataModify::open_record()
{
	std::ifstream in(File_path_record, std::ios::in);

	if (!in.is_open())
	{
		return false;
	}
	std::string str1;
	int number = 0; 
	while (getline(in, str1))
	{
		++number;
	};
	in.close();
	std::ifstream in_2(File_path_record, std::ios::in);
	for (int i = 0; i * 9 != number; ++i)
	{
		getline(in_2, str1);
		int operation_id = std::stoi(str1.c_str());
		getline(in_2, str1);
		int client_id = std::stoi(str1.c_str());
		getline(in_2, str1);
		int year = std::stoi(str1.c_str());
		getline(in_2, str1);
		int month = std::stoi(str1);
		getline(in_2, str1);
		int day =std::stoi(str1);
		getline(in_2,str1);
		int category = std::stoi(str1);
		getline(in_2, str1);
		float amount = std::stof(str1.c_str());
		getline(in_2, str1);
		std::string operator_name = str1.c_str();
		getline(in_2, str1);
		float current_amount = std::stof(str1.c_str());
		record_structure B(operation_id, client_id, year, month, day, category,amount, operator_name, current_amount);
		info_record_list.push_back(B);
	}
	return true;
}
void CDataModify::mod_client(int index_client, client_structure info_client)
{
	info_client_list[index_client].id = info_client.id;
    info_client_list[index_client].name = info_client.name;
    info_client_list[index_client].passwords = info_client.passwords;
	info_client_list[index_client].address = info_client.address;
	info_client_list[index_client].phone_number = info_client.phone_number;
	info_client_list[index_client].total_balance = info_client.total_balance;
}

void CDataModify::mod_record(int index_record, record_structure info_record)
{
	info_record_list[index_record].opertation_id = info_record.opertation_id;
    info_record_list[index_record].client_id = info_record.client_id;
    info_record_list[index_record].year = info_record.year;
	info_record_list[index_record].month = info_record.month;
	info_record_list[index_record].day = info_record.day;
	info_record_list[index_record].amount = info_record.amount;
    info_record_list[index_record].operator_name = info_record.operator_name;
	info_record_list[index_record].current_amount = info_record.current_amount;
}

bool  CDataModify::save_client()
{
	std::vector<client_structure>list;
	std::ofstream out(File_path_client, std::ios::out);
	if (!out.is_open())
		return false;
	for (int m = 0; m != info_client_list.size(); ++m)
	{
		out << info_client_list[m].id << std::endl;
		out << info_client_list[m].name << std::endl;
		out << info_client_list[m].passwords << std::endl;
		out << info_client_list[m].address << std::endl;
		out << info_client_list[m].phone_number << std::endl;
		out << info_client_list[m].total_balance << std::endl;
	}
	out.close();
	return true;
}

bool  CDataModify::save_record()
{
	std::vector<record_structure>list;
	std::ofstream out(File_path_record, std::ios::out);
	if (!out.is_open())
		return false;
	for (int m = 0; m != info_record_list.size(); ++m)
	{
		out << info_record_list[m].opertation_id << std::endl;
		out << info_record_list[m].client_id << std::endl;
		out << info_record_list[m].year << std::endl;
		out << info_record_list[m].month << std::endl;
		out << info_record_list[m].day << std::endl;
		out << info_record_list[m].category << std::endl;
		out << info_record_list[m].amount << std::endl;
		out << info_record_list[m].operator_name << std::endl;
		out << info_record_list[m].current_amount << std::endl;
	}
	out.close();
	return true;
}

void CDataModify::add_client(client_structure info_client)
{
	/*输入info_client的信息*/
	info_client_list.push_back(info_client);
}

void CDataModify::del_client(int index_client)
{
	/*删除的信息*/
	info_client_list.erase(info_client_list.begin() + index_client);
}

void CDataModify::add_record(record_structure info_record)
{
	/*输入info_record的信息*/
	info_record_list.push_back(info_record);
}

void CDataModify::del_record(int index_record)
{
	/*删除的信息*/
	info_record_list.erase(info_record_list.begin() + index_record);
}

std::vector<int> CDataModify::find_client(std::string data, int a) // a = 0 编号 a = 1 姓名 a = 2 客户电话
{
	int index = 0;
	std::vector<int> find_list;
	for (auto i : info_client_list)
	{
		switch (a)
		{
		case 0:
		{
			if (std::to_string(i.id) == data)
				find_list.push_back(index);
			break;
		}
		case 1:
		{
			if (i.name == data)
				find_list.push_back(index);
			break;
		}
		case 2:
		{
			if (i.phone_number == data)
				find_list.push_back(index);
			break;
		}
		}
		++index;
	}
	return find_list;
}

std::vector<int> CDataModify::find_record(std::string data, int a) // a = 0 操作编号 a = 1 客户编号 a = 2 操作者编号
{
	int index = 0;
	std::vector<int> find_list;
	for (auto i : info_record_list)
	{
		switch (a)
		{
		case 0:
		{
			if (std::to_string(i.opertation_id) == data)
				find_list.push_back(index);
			break;
		}
		case 1:
		{
			if (std::to_string(i.client_id) == data)
				find_list.push_back(index);
			break;
		}
		case 2:
		{
			if (i.operator_name == data)
				find_list.push_back(index);
			break;
		}
		}
		++index;
	}
	return find_list;
}