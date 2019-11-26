#include "Integer.h"

Integer::Integer(int value)
{
	_val = value;
}
int Integer::val()
{
	return this->_val;
}
void Integer::set_val(const int& value)
{
	_val = value;
}
json_object* Integer::parse(const char* str, int length)
{
	int index = _index;
	std::string tmp = "";
	while ( '0' <= str[index] && str[index]<='9')
	{
		tmp = tmp+ str[index];
		index++;
	}
	_index = index-1;
	json_object* result = new Integer(std::stoi(tmp));
	return result;
}
json_object::_type Integer::type()
{
	return INT;
}
std::string Integer::to_string()
{
	return std::to_string(val());
}