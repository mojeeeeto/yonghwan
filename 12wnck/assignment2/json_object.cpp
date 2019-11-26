#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;

json_object* json_object::parse(const char* str, int length)
{ 
	while (str[_index] != '\0'&& _index < length)
	{
		if (str[_index] == '{')
		{
			return json_dict::parse(str, length);
		}
		else if(str[_index] == '[')
		{
			return json_list::parse(str, length);
		}
		else if (str[_index] == '"')
		{
			return String::parse(str,length, '"');
		}
		else if (str[_index] == '\'')
		{
			return String::parse(str, length, '\'');
		}
		else if (str[_index] <= '9' && str[_index] >= '0')
		{
			return Integer::parse(str, length);
		}
		_index++;
	}
}
json_object* json_object::parse(const std::string& str)
{
	_index = 0;
	int length = str.length();
	const char* string = str.c_str();
	
	return parse(string, length);
}
