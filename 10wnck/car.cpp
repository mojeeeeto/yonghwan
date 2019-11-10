#include "vehicle.h"
#include "car.h"
car::car() :vehicle()
{
	this->car_name = nullptr;
	this->max_speed = 0;
	this->has_name = false;
	this->wheel_number = 0;
}
car::car(int wheel,int max) : vehicle(wheel,max)
{
	this->wheel_number = wheel;
	this->max_speed = max;
	this->car_name = nullptr;
}
car::car(int wheel,int max,const char* name) : vehicle(wheel, max)
{
	this->wheel_number = wheel;
	this->max_speed = max;
	this->car_name = name;
}
car::car(int wheel,int max,const char* name,bool hasname) : vehicle(wheel,max,hasname)
{
	this->wheel_number = wheel;
	this->max_speed = max;
	this->car_name = name;
	this->has_name = hasname;
}
const char* car::get_car_name()
{
	return this->car_name;
}
const char* car::get_class_name()
{
	return "car";
}
void car::set_car_name(const char* name)
{
	this->car_name = name;
}

