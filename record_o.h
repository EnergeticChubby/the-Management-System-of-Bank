#pragma once
#pragma warning(disable:4996)
/*
* 0、添加
* 1、删除
* 2、修改
* 4、记录
* 5、用户
* 
* time:
* YYYY-MM-DD
* operation code:
* 0
* operator id:
* 1083 暂时没有用户登陆系统，默认为1083
* detials:
* client id:
* record id:
*/
#include<ctime>
#include<stdio.h>
#include<string>
#include<vector>
#include <fstream>
#include <ctime>
#include "record_o_structure.h"

class record_o
{
private:
	std::string File_path_record_o = "record_o.txt";

public:
	std::vector<record_o_struc> record_o_list;
	bool open_file();
	bool save_file();
	void add_record_o(int operator_code, int operator_id, int client_id, int record_id);
};

bool record_o::open_file()
{
	std::ifstream in(File_path_record_o, std::ios::in);

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
	std::ifstream in_2(File_path_record_o, std::ios::in);
	for (int i = 0; i * 5 != number; ++i)
	{
		getline(in_2, str1);
		std::string time = str1.c_str();
		getline(in_2, str1);
		int operator_code = std::stoi(str1.c_str());
		getline(in_2, str1);
		int operator_id = std::stoi(str1.c_str());
		getline(in_2, str1);
		int client_id = std::stoi(str1.c_str());
		getline(in_2, str1);
		int record_id = std::stoi(str1.c_str());
		record_o_struc A(time, operator_code, operator_id, client_id, record_id);
		record_o_list.push_back(A);
	}
	return true;
}

bool record_o::save_file()
{
	std::ofstream out(File_path_record_o, std::ios::out);
	if (!out.is_open())
		return false;
	for (int m = 0; m != record_o_list.size(); ++m)
	{
		out << record_o_list[m].time << std::endl;
		out << record_o_list[m].operator_code << std::endl;
		out << record_o_list[m].operator_id << std::endl;
		out << record_o_list[m].client_id << std::endl;
		out << record_o_list[m].record_id << std::endl;
	}
	out.close();
	return true;
}

void record_o::add_record_o(int operator_code, int operator_id, int client_id, int record_id)
{
	// 获取当前时间
	std::time_t currentTime = std::time(nullptr);

	// 将时间转换为字符串
	std::tm* localTime = std::localtime(&currentTime);
	char timeString[100]; // 数组足够大以容纳时间字符串
	std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
	std::string time = timeString;
	record_o_struc A(time, operator_code, operator_id, client_id, record_id);
	record_o_list.push_back(A);
	save_file();
}
