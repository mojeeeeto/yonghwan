#include "String.h"

String::String(const std::string& str)
{
	this->_val = str;
}
std::string String::val()
{
	return _val;
}
void String::set_val(const std::string& str)
{
	this->_val = str;
}
json_object* String::parse(const char*str, int length, char base)
{
	_index++;
	std::string tmp = "\'";
	while (str[_index] != base)
	{
		tmp += str[_index];
		_index++;
	}
	tmp += "\'";
	json_object* result = new String(tmp);
	return result;
}
json_object::_type String::type()
{
	return STRING;
}
std::string String::to_string()
{
	return val();
}