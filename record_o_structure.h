#pragma once
#include <string>

class record_o_struc // record_operation
{
public:
	std::string time;
	int operator_code;
	int operator_id;
	int client_id;
	int record_id;
	record_o_struc(std::string time_i, int operator_code_i, int operator_id_i, int client_id_i, int record_id_i)
	{
		time = time_i;
		operator_code = operator_code_i;
		operator_id = operator_id_i;
		client_id = client_id_i;
		record_id = record_id_i;
	};
};