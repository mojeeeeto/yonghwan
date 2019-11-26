
#include "json_dict.h"

void json_dict::put(json_object* key, json_object* val)
{
	if (find(key) == -1)
	{
		v.push_back(std::make_pair(key, val));
		
	}
	else
	{
		v[find(key)].second = val;
	}
}
int json_dict::find(json_object* key)
{
	for (int i = 0; i < this->v.size(); i++)
	{
		if (key->to_string() == this->v[i].first->to_string())
			return i;
	}
	return -1;
}
json_dict::json_dict()
{

}
json_object* json_dict::parse(const char* str, int length)
{
	_index++;
	json_dict* add = new json_dict();

	while (str[_index] != '}')
	{
		json_object* key = json_object::parse(str, length);
		_index++;
		json_object* value = json_object::parse(str, length);
		
		add->put(key, value);
		_index++;
	}
	return add;
}
json_object* json_dict::operator[](json_object* key) const
{
	for (int i = 0; i < this->v.size(); i++)
	{
		if (this->v[i].first->to_string() == key->to_string())
		{
			return this->v[i].second;
		}
	}
	return nullptr;
}

json_object* json_dict::operator[](const std::string& key) const
{
	for (int i = 0; i < this->v.size(); i++)
	{
		if (this->v[i].first->to_string() == key)
		{
			return this->v[i].second;
		}
	}
	return nullptr;
}
json_object* json_dict::operator[](int key) const
{
	std::string tmp = std::to_string(key);
	for (int i = 0; i < this->v.size(); i++)
	{
		if (this->v[i].first->to_string() == tmp)
		{
			return this->v[i].second;
		}
	}
	return nullptr;
}
json_object::_type json_dict::type()
{
	return this->DICT;
}
std::string json_dict::to_string()
{
	std::string str = "{";
	for (int i = 0; i < this->v.size(); i++)
	{
		str += (this->v[i].first->to_string()+ ": " + this->v[i].second->to_string());
		if (i < this->v.size()-1)
		{
			str  += ", ";
		}
	}
	str += "}";
	return str;
}