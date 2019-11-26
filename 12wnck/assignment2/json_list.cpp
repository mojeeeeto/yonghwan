#include "json_list.h"

json_list::json_list()
{
}
json_object* json_list::parse(const char* str, int length)
{
	json_list* add = new json_list();
	_index++;
	while (str[_index] != ']')
	{
		json_object* key = json_object::parse(str, length);
		add->v.push_back(key);
		_index++;
	}
	return add;
}
json_object* json_list::operator[](int key)const
{
	return v[key];

}
json_object::_type json_list::type()
{
	return LIST;
}
std::string json_list::to_string()
{
	std::string str = "[";
	for (int i=0;i<v.size();i++)
	{
		str += v[i]->to_string();
		if (i < v.size() - 1)
		{
			str += ", ";
		}
	}
	str += "]";
	return str;
}