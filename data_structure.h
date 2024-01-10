#pragma once
#include <iostream>

class client_structure
{
public:
	//	每个客户是一条记录，包括编号、客户姓名、支取密码、客户地址、客户电话、账户总金额；
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
	// 每次存取款是一条记录，包括编号、日期、类别、存取数目、经办人、当前金额（操作后的金额）。
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
		category = category_i; // 取款 0 和 存款 1
		amount = amount_i;
		operator_name = operator_name_i;
		current_amount = current_amount_i;
	}
};