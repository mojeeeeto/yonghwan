#include "vehicle.h"
#include "bike.h"

bike::bike() : vehicle()
{
	this->bike_name = nullptr;
	this->bike_number = 0;
}
bike::bike(int wheel,int max) : vehicle(wheel,max)
{
	this->wheel_number = wheel;
	this->max_speed = max;
	this->bike_name = nullptr;
	this->bike_number = 0;
}
bike::bike(int wheel,int max,const char* name) : vehicle(wheel,max)
{
	this->wheel_number = wheel;
	this->max_speed = max;
	this->bike_name = name;
	this->bike_number = 0;
}
bike::bike(int wheel,int max,const char* name,int number) : vehicle(wheel,max)
{
	this->wheel_number = wheel;
	this->max_speed = max;
	this->bike_name = name;
	this->bike_number = number;
}
bike::bike(int wheel,int max,const char* name,int number,bool has) : vehicle(wheel,max,has)
{
	this->wheel_number = wheel;
	this->max_speed = max;
	this->bike_name = name;
	this->bike_number = number;
	this->has_name = has;
}
const char* bike::get_bike_name()
{
	return this->bike_name;
}
const char* bike::get_class_name()
{
	return "bike";
}
int bike::get_bike_number()
{
	return this->bike_number;
}
void bike::set_bike_number(int number)
{
	this->bike_number = number;
}
void bike::set_bike_name(const char* name)
{
	this->bike_name = name;
}


