#pragma once
#include <iostream>

class user_structure
{
public:
	std::string id;
	std::string passwords;

	user_structure(std::string id_i, std::string passwords_i)
	{
		id = id_i;
		passwords = passwords_i;
	}
};