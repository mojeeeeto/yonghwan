#include "vehicle.h"

vehicle::vehicle()
{
	this->wheel_number = 0;
	this->max_speed = 0;
	this->has_name = false;
}
vehicle::vehicle(int wheel,int max)
{
	this->wheel_number = wheel;
	this->max_speed = max;
	this->has_name = true;
}
vehicle::vehicle(int wheel,int max, bool has)
{
	this->wheel_number = wheel;
	this->max_speed = max;
	this->has_name = has;
}
int vehicle::get_wheel_number()
{
	return this->wheel_number;
}
int vehicle::get_max_speed()
{
	return this->max_speed;
}
bool vehicle::get_has_name()
{
	return this->has_name;
}
const char* vehicle::get_class_name()
{
	return "vehicle";
}
void vehicle::set_wheel_number(int wheel)
{
	this->wheel_number = wheel;
}
void vehicle::set_max_speed(int max)
{
	this->max_speed = max;
}
void vehicle::set_has_name(bool has)
{
	this->has_name = has;
}









