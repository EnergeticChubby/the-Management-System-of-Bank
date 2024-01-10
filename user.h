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
#include "user_structure.h"
#include "sha256.h"


class user
{
private:
	std::string File_path_user = "user.txt";

public:
	std::vector<user_structure> user_list;
	std::string user_id_c;
	bool open_file();
	bool save_file();
	void add_user(std::string id, std::string passwords);
	bool login_user(std::string id, std::string passwords);
	std::vector<int> find_user(std::string id, std::string passwords);
	bool user::find_user_1(std::string id);
	void mod_user(std::string id, std::string passwords, std::string passwords_c);
	void del_user(std::string id, std::string passwords);
};

bool user::open_file()
{
	std::ifstream in(File_path_user, std::ios::in);

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
	std::ifstream in_2(File_path_user, std::ios::in);
	for (int i = 0; i * 2 != number; ++i)
	{
		getline(in_2, str1);
		std::string id = str1.c_str();
		getline(in_2, str1);
		std::string passwords = str1.c_str();
		user_structure A(id, passwords);
		user_list.push_back(A);
	}
	return true;
}

bool user::save_file()
{
	std::ofstream out(File_path_user, std::ios::out);
	if (!out.is_open())
		return false;
	for (int m = 0; m != user_list.size(); ++m)
	{
		out << user_list[m].id << std::endl;
		out << user_list[m].passwords << std::endl;
	}
	out.close();
	return true;
}

void user::add_user(std::string id, std::string passwords)
{
	std::string id_digest = Ly::Sha256::getInstance().getHexMessageDigest(id);
	std::string passwords_digest = Ly::Sha256::getInstance().getHexMessageDigest(passwords);
	user_structure A(id_digest, passwords_digest);
	user_list.push_back(A);
	save_file();
}

bool user::login_user(std::string id, std::string passwords)
{
	//std::string id_digest = Ly::Sha256::getInstance().getHexMessageDigest(id);
	//std::string passwords_digest = Ly::Sha256::getInstance().getHexMessageDigest(passwords);
	std::vector<int> find_list = find_user(id, passwords);
	user_id_c = id;
	if (find_list.size() == 1)
		return true;
	else
		return false;
}

std::vector<int> user::find_user(std::string id, std::string passwords)
{
	std::string id_digest = Ly::Sha256::getInstance().getHexMessageDigest(id);
	std::string passwords_digest = Ly::Sha256::getInstance().getHexMessageDigest(passwords);
	int index = 0;
	std::vector<int> find_list;
	for (auto i : user_list)
	{
		if (i.id == id_digest && i.passwords == passwords_digest)
			find_list.push_back(index);
		++index;
	}
	return find_list;
}

bool user::find_user_1(std::string id)
{
	std::string id_digest = Ly::Sha256::getInstance().getHexMessageDigest(id);
	int index = 0;
	std::vector<int> find_list;
	for (auto i : user_list)
	{
		if (i.id == id_digest)
			return true;
	}
	return false;
}

void user::mod_user(std::string id, std::string passwords, std::string passwords_c)
{
	std::vector<int> find_list = find_user(id, passwords);
	std::string passwords_c_digest = Ly::Sha256::getInstance().getHexMessageDigest(passwords_c);
	user_list[find_list[0]].passwords = passwords_c_digest;
	save_file();
}

void user::del_user(std::string id, std::string passwords)
{
	std::vector<int> find_list = find_user(id, passwords);
	user_list.erase(user_list.begin() + find_list[0]);
	save_file();
}
