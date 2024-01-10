#pragma once
#include <iostream>

class client_structure
{
public:
	//	ÿ���ͻ���һ����¼��������š��ͻ�������֧ȡ���롢�ͻ���ַ���ͻ��绰���˻��ܽ�
	int id;
	std::string name;
	std::string passwords;
	std::string address;
	std::string phone_number;
	float total_balance;

	client_structure(int id_i, std::string name_i, std::string passwords_i, std::string address_i, std::string phone_number_i, float total_balance_i)
	{
		id = id_i;
		name = name_i;
		passwords = passwords_i;
		address = address_i;
		phone_number = phone_number_i;
		total_balance = total_balance_i;
	}

};

class record_structure
{
public:
	// ÿ�δ�ȡ����һ����¼��������š����ڡ���𡢴�ȡ��Ŀ�������ˡ���ǰ��������Ľ���
	int opertation_id;
	int client_id;
	int year;
	int month;
	int day;
	int category;
	float amount;
	std::string operator_name;
	float current_amount;
	record_structure(int opertation_id_i, int client_id_i, int year_i, int month_i, int day_i, int category_i, float amount_i, std::string operator_name_i, float current_amount_i)
	{
		opertation_id = opertation_id_i;
		client_id = client_id_i;
		year = year_i;
		month = month_i;
		day = day_i;
		category = category_i; // ȡ�� 0 �� ��� 1
		amount = amount_i;
		operator_name = operator_name_i;
		current_amount = current_amount_i;
	}
};